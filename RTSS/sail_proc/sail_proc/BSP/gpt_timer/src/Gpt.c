/*
  ==============================================================================
*/
/*==============================================================================
  File Name          : Gpt.h
  Component Name     : MCAL Gpt module as gpt_timer RTD Module 
  Description        : AutoSAR R 24-11
  $Header: 
  $DateTime: 
  $Author: 
  ============================================================================*/
/*
  ==============================================================================
  
  Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
  All rights reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
   
  ==============================================================================

  $Header: 
  $DateTime:
  $Author:

  ==============================================================================
*/
/*
  ==============================================================================

  EDIT HISTORY FOR MODULE

  when       who      what, where, why
  --------   -------  ----------------------------------------------------------

  ==============================================================================
*/
/*==============================================================================
**                         Include files                                      **
==============================================================================*/
/* @[SWS_Gpt_00375]: Gpt.c shall include Det.h in any case to be able to raise runtime error: for BSP RTD refer API guide */
#include "Gpt.h"
#include "HALhwio.h"
#include "hw_io.h"
#include "msmhwiobase.h"
#include "g_SAIL_QTMR.h"
#include "Gpt_Prv.h"
#include "Gpt_Os.h"
#include "Gpt_Irq.h"
#include "debug_log.h"
/*==============================================================================
**                         defines and macros                                 **
==============================================================================*/
#define GPT_EN_PREDEF_TIMER( var, pos, flag) \
    do { \
        if ((flag) != 0U) { \
            (var) |= (1U << (pos)); \
        } else { \
        (var) &= ~(1U << (pos)); } \
    } while (0)
         
#define GPT_CHAN_CFG_MASK   0xFFU
#define GPT_CHAN_CFG_SHFT   0x08U
/*==============================================================================
**      Private typedefs : Enums, Structures Union and other typedefs         **
==============================================================================*/
/* PredefTimer Grade Info*/
typedef struct {
	uint32 Gpt_BitsValMax;
	uint32 Gpt_ResScaler;
}Gpt_GradeMapType;

GPT_TIMER_CONST static const Gpt_GradeMapType Gpt_GradeMap[GPT_PREDEF_TIMER_XUS_DISABLED] = {
        {.Gpt_BitsValMax = GPT_PREDEF_TIMER_1US_16BIT_VAL_MAX,   .Gpt_ResScaler= GPT_PREDEF_TIMER_1US_16BIT_RES},
        {.Gpt_BitsValMax = GPT_PREDEF_TIMER_1US_24BIT_VAL_MAX,   .Gpt_ResScaler= GPT_PREDEF_TIMER_1US_16BIT_RES},
        {.Gpt_BitsValMax = GPT_PREDEF_TIMER_1US_32BIT_VAL_MAX,   .Gpt_ResScaler= GPT_PREDEF_TIMER_1US_16BIT_RES},
        {.Gpt_BitsValMax = GPT_PREDEF_TIMER_100US_32BIT_VAL_MAX, .Gpt_ResScaler= GPT_PREDEF_TIMER_100US_32BIT_RES},
        {.Gpt_BitsValMax = GPT_PREDEF_TIMER_2US_32BIT_VAL_MAX,   .Gpt_ResScaler= GPT_PREDEF_TIMER_2US_32BIT_RES},
};

GPT_TIMER_DATA static Gpt_ModuleCoreDataType  Gpt_ModuleRTData = { 0U };
/*=========================================================================================================
**                                        Private Function Protos                                        **
=========================================================================================================*/
#if (GPT_DEV_ERROR_DETECT == STD_ON)
GPT_TIMER_FUNC void Gpt_ReportError(const uint8 Gpt_Serviceid, const uint8 Gpt_ErrorId);
#endif
GPT_TIMER_FUNC void Gpt_ReportRuntimeError(const uint8 Gpt_Serviceid, const uint8 Gpt_ErrorId);
/*=========================================================================================================
**                                        Private Function Definitions                                   **
=========================================================================================================*/
#if (GPT_DEV_ERROR_DETECT == STD_ON)
/*========================================================================================================
 @Service name        Gpt_ReportError
 @Description         Error report to Det and Dem : Helper service for Error report
 @param[in]           Gpt_Serviceid and Gpt_ErrorId
 @param[out]          None
 @param[in, out]      None
 @return              None
 @Pre                 None
 @Post                None
 @Requirements IDs    None
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous function
 @Reentrancy          Non Reentrant
 @Note                None.
========================================================================================================*/
GPT_TIMER_FUNC void Gpt_ReportError(const uint8 Gpt_Serviceid, const uint8 Gpt_ErrorId)
{
    Gpt_ModuleCoreDataType *pGpt_ModuleCoreData = &Gpt_ModuleRTData;
    pGpt_ModuleCoreData->GptDetErrCnt++;
    Std_ReturnType ReturnType = Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, Gpt_Serviceid, Gpt_ErrorId);
    if(ReturnType == E_NOT_OK)
    {
        /* Integrator did not configured and handled the Det Errors */
        while(1) {
            ; /* do nothing */
        }
    }
    (void)Gpt_Serviceid;
    (void)Gpt_ErrorId;
    return ;
}
#endif
/*========================================================================================================
 @Service name        Gpt_ReportRuntimeError
 @Description         Helper service for Error report : Error report to Det and Dem.
 @param[in]           Gpt_Serviceid and Gpt_ErrorId
 @param[out]          None
 @param[in, out]      None
 @return              None
 @Pre                 None
 @Post                None
 @Requirements IDs    None
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous function
 @Reentrancy          Non Reentrant
 @Note                None.
========================================================================================================*/
GPT_TIMER_FUNC void Gpt_ReportRuntimeError(const uint8 Gpt_Serviceid, const uint8 Gpt_ErrorId)
{   
    Gpt_ModuleCoreDataType *pGpt_ModuleCoreData = &Gpt_ModuleRTData;
    pGpt_ModuleCoreData->GptRunErrCnt++;
	Std_ReturnType ReturnType = Det_ReportRuntimeError(GPT_MODULE_ID, GPT_INSTANCE_ID, Gpt_Serviceid, Gpt_ErrorId);
    if(ReturnType == E_NOT_OK)
    {
        /* Integrator did not configured and handled the Run Errors */
        while(1) {
            ; /* do nothing */
        }
    }
    (void)Gpt_Serviceid;
    (void)Gpt_ErrorId;
    return ;
}
/*=========================================================================================================
**                                        Global Function Definitions                                   **
=========================================================================================================*/
/*========================================================================================================
 @Service name        Gpt_Init
 @Description         Initializes the GPT driver.
 @param[in]           const Gpt_ConfigType* ConfigPtr
 @param[out]          None
 @param[in, out]      None
 @return              None
 @Pre                 None
 @Post                None
 @Requirements IDs    SWS_Gpt_00280
 @Design IDs          NA
 @service ID          0x01
 @Sync/Async          Synchronous function
 @Reentrancy          Non Reentrant
 @Note                All the other services used after Gpt_Init services is executed.
========================================================================================================*/
/* @[SWS_Gpt_00006] : The function Gpt_Init shall initialize the hardware timer
    module according to a configuration set referenced by ConfigPtr.
    (SRS_BSW_00101, SRS_SPAL_12057 */

/* TODO Needs check below requirement use case
 * @[SWS_Gpt_00309] : A re-initialization of the GPT driver by executing the Gpt_Init
   function requires a de-initialization before by executing a Gpt_DeInit.  ( )*/

GPT_TIMER_FUNC Std_ReturnType Gpt_Init(const Gpt_ConfigType *const ConfigPtr)
{
    Gpt_ModuleCoreDataType *pGpt_ModuleCoreData = &Gpt_ModuleRTData;
    Std_ReturnType Ret = E_NOT_OK;
#if (GPT_DEV_ERROR_DETECT == STD_ON )
	uint8   DevErrStatus = (uint8)E_OK;
#endif
    /*  Fix for KW P1 issue */
    if((NULL_PTR == ConfigPtr) || (NULL_PTR == ConfigPtr->Gpt_ChannelConfig) || (NULL_PTR == ConfigPtr->Gpt_ModuleConfig))
    {
#if (GPT_DEV_ERROR_DETECT == STD_ON )
        Gpt_ReportError(GPT_SERVICE_ID_INIT, GPT_E_PARAM_POINTER);
        DevErrStatus = (uint8)E_NOT_OK;
#endif
    }
    else
#if (GPT_DEV_ERROR_DETECT == STD_ON )
    {
        if(GPT_DRIVER_INITIALIZED == pGpt_ModuleCoreData->GptDrvState)
        {
            /*[SWS_Gpt_00307] If development error detection is enabled for the GPT module:
            If the GPT driver is not in operation mode "uninitialized", the function Gpt_Init shall
            raise the error GPT_E_ALREADY_INITIALIZED.*/
            //Gpt_ReportError(GPT_SERVICE_ID_INIT, GPT_E_ALREADY_INITIALIZED);
	    DEBUG_LOG(SAIL_WARNING,">>>>> GPT timer already Initialized , deinit first using stop cmd\n\r");
            DevErrStatus = (uint8)E_NOT_OK;
	    return DevErrStatus;
        }
        if(DevErrStatus == (uint8)E_NOT_OK)
        {
            Gpt_ReportError(GPT_SERVICE_ID_INIT, GPT_E_INIT_FAILED);
            DevErrStatus = (uint8)E_NOT_OK;
        }
    }
    if(DevErrStatus == (uint8)E_OK)
#endif /* (GPT_DEV_ERROR_DETECT == STD_ON ) */
    {
        /* populate module core handle */
        pGpt_ModuleCoreData->pGpt_ChannelConfig = ConfigPtr->Gpt_ChannelConfig;
        pGpt_ModuleCoreData->pGpt_ModuleConfig = ConfigPtr->Gpt_ModuleConfig;
        
        /*@[SWS_Gpt_00339] :The function Gpt_Init shall set the operation mode of the
        GPT driver to "normal mode". This leads to a behavior like Gpt_SetMode is called
        with parameter GPT_MODE_NORMAL.*/

        pGpt_ModuleCoreData->GptDrvMode = GPT_MODE_NORMAL;

          /* The Counter Secure Register contains a bit for Secure access to each timer frame,
           including both views of the timer frame and the access to the associated CNTACR and CNTVOFF
           registers in the Access Control region. SAILSS_QTMR_QTMR_AC_CNTNSAR_FG0 */
         /* Non-secure access to frame N. N lies from 0 to $NUM_FRAME-1 (Max. Limit is 7).
            0x0: SECURE_ONLY - Secure access only - non-secure access is RAZ/WI
            0x1: SECURE_OR_NONSECURE - Secure or Non-secure access*/

        REG_OUT(SAILSS_QTMR_SAILSS_QTMR_BASE, SAILSS_QTMR_QTMR_AC_CNTNSAR_FG0,  (uint16)0xFF);
        REG_OUT(SAILSS_QTMR_SAILSS_QTMR_BASE, SAILSS_QTMR_QTMR_AC_CNTNSAR_FG1,  (uint16)0xFF);

        for (uint8 ConfigIdx = 0U; ConfigIdx < ConfigPtr->Gpt_ModuleConfig->GptDrvChannelMaxConfig ; ConfigIdx++)
        {
            if(ConfigPtr->Gpt_ChannelConfig[ConfigIdx].GptChanHW == GPT_CHAN_HWTIMER_PL0_QTMR )
            {
                /* The Second View Counter Access Control Register (CNTPL0ACR) provide second view access control
                to the individual elements of timer frame n, except CNTVOFF and CNTPL0ACR registers
                SAILSS_QTMR_QTMR_V1_CNTPL0ACR_0 */
                outpdw(Gpt_CNTPLO_ACR_OFFSET(ConfigPtr->Gpt_ChannelConfig[ConfigIdx].GptChannelID), (uint32)0x303U);
                /* The Counter Access Control Register (CNTACR) provide access control to the individual
                elements of timer frame n, including the second view of that timer frame n. FG0 provides
                access to Frame Group0(upto 8 frames) **/
                outpdw(Gpt_AC_CNTACR_FG0_BASE_ADDR_OFFSET((ConfigPtr->Gpt_ChannelConfig[ConfigIdx].GptChannelID) & ( 0x3U) ), (uint32)0x3FU);
                outpdw(Gpt_AC_CNTACR_FG1_BASE_ADDR_OFFSET((ConfigPtr->Gpt_ChannelConfig[ConfigIdx].GptChannelID) & ( 0x3U) ), (uint32)0x3FU);
            }
            /* init chan data */
            pGpt_ModuleCoreData->Gpt_ChannelCoreData[ConfigIdx].GptChanHW               = ConfigPtr->Gpt_ChannelConfig[ConfigIdx].GptChanHW;
            pGpt_ModuleCoreData->Gpt_ChannelCoreData[ConfigIdx].GptTargetTime           = 0UL;
        	pGpt_ModuleCoreData->Gpt_ChannelCoreData[ConfigIdx].GptTargetTimeInHwTicks  = 0UL;
        	pGpt_ModuleCoreData->Gpt_ChannelCoreData[ConfigIdx].GptStopValueInHwTicks   = 0UL;
        	pGpt_ModuleCoreData->Gpt_ChannelCoreData[ConfigIdx].GptStopReqTimeInHwTicks = 0UL;
        	pGpt_ModuleCoreData->Gpt_ChannelCoreData[ConfigIdx].GptStartValueInHWTicks  = 0UL;
        	pGpt_ModuleCoreData->Gpt_ChannelCoreData[ConfigIdx].GptChannelState = GPT_CHANNEL_INITIALIZED;
            /* @[SWS_Gpt_00258] :The function Gpt_Init shall disable all wakeup interrupts,
             controlled by the GPT driver. */
            #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
            pGpt_ModuleCoreData->Gpt_ChannelCoreData[ConfigIdx].GptEnableWakeup = STD_OFF;
            #endif
            /* @[SWS_Gpt_00107] : The function Gpt_Init shall disable all interrupt notifications,
             controlled by the GPT driver. */
            #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)             
            pGpt_ModuleCoreData->Gpt_ChannelCoreData[ConfigIdx].GptChannelCbkEn = STD_OFF;
            pGpt_ModuleCoreData->Gpt_ChannelCoreData[ConfigIdx].GptChannelCbkBckEn = STD_OFF;
            #endif
            /* ctl disable and mask */
            GptPrv_DisableTimer( (const Gpt_ChannelType)  pGpt_ModuleCoreData->pGpt_ChannelConfig[ConfigIdx].GptChannelID, \
                                 (const Gpt_ChanHWType) pGpt_ModuleCoreData->pGpt_ChannelConfig[ConfigIdx].GptChanHW );
            /* @[SWS_Gpt_00068] :The function Gpt_Init shall only initialize the configured
             resources. Resources that are not configured in the configuration file shall not be
             touched. (SRS_SPAL_12125) */
            /* install private channel event handler */
            if(ConfigPtr->Gpt_ChannelConfig[ConfigIdx].GptChanHW == GPT_CHAN_HWTIMER_PL0_QTMR )
            {
                Ret = eGptOs_RegisterInterrupt( (uint32)(Gpt_PHYIRQ_0 + (uint32)ConfigPtr->Gpt_ChannelConfig[ConfigIdx].GptChannelID), \
                                            GptOs_TRIGGER_EDGE, \
                                            prvQTimerGetISR( ConfigPtr->Gpt_ChannelConfig[ConfigIdx].GptChannelID ), \
                                            (void*)&Gpt_ModuleRTData );
            }
            else
            {
                Ret = eGptOs_RegisterInterrupt( (uint32)(Gpt_PHYIRQ_PROC + (uint32)ConfigPtr->Gpt_ChannelConfig[ConfigIdx].GptChanHW), \
                                            GptOs_TRIGGER_EDGE, \
                                            prvQTimerGetISR( ConfigPtr->Gpt_ChannelConfig[ConfigIdx].GptChannelID ), \
                                                (void*)&Gpt_ModuleRTData );
            }
            #if(GPT_DEV_ERROR_DETECT == STD_ON)
            if(Ret != (uint8)E_OK)
            {
                Gpt_ReportError(GPT_SERVICE_ID_INIT, GPT_E_INIT_FAILED);
            }
            #endif
        }
        /* @[SWS_Gpt_00390] :The function Gpt_Init shall start all enabled GPT Predef
            Timers at value “0”*/ 
        /* in this HW Not possible so timer emulate using safe ticker */
        pGpt_ModuleCoreData->GptPredefTimerEn = 0x0U;
        GPT_EN_PREDEF_TIMER( pGpt_ModuleCoreData->GptPredefTimerEn, \
                             (uint8)GPT_PREDEF_TIMER_100US_32BIT, \
                                (uint8)pGpt_ModuleCoreData->pGpt_ModuleConfig->GptPredefTimer100us32bitEnable  );
        
        GPT_EN_PREDEF_TIMER( pGpt_ModuleCoreData->GptPredefTimerEn, \
                             (uint8)GPT_PREDEF_TIMER_2US_32BIT, \
                                (uint8)pGpt_ModuleCoreData->pGpt_ModuleConfig->GptPredefTimer2us32bitEnable  );

        if( pGpt_ModuleCoreData->pGpt_ModuleConfig->GptPredefTimer1usEnablingGrade == GPT_PREDEF_TIMER_1US_16_24_32BIT_ENABLED )
        {
            GPT_EN_PREDEF_TIMER( pGpt_ModuleCoreData->GptPredefTimerEn,(uint8)GPT_PREDEF_TIMER_1US_16BIT, (uint8)1U );
            GPT_EN_PREDEF_TIMER( pGpt_ModuleCoreData->GptPredefTimerEn,(uint8)GPT_PREDEF_TIMER_1US_24BIT, (uint8)1U );
            GPT_EN_PREDEF_TIMER( pGpt_ModuleCoreData->GptPredefTimerEn,(uint8)GPT_PREDEF_TIMER_1US_32BIT, (uint8)1U );
        }
        else if( pGpt_ModuleCoreData->pGpt_ModuleConfig->GptPredefTimer1usEnablingGrade == GPT_PREDEF_TIMER_1US_16_24BIT_ENABLED  )
        {
            GPT_EN_PREDEF_TIMER( pGpt_ModuleCoreData->GptPredefTimerEn,(uint8)GPT_PREDEF_TIMER_1US_16BIT, (uint8)1U );
            GPT_EN_PREDEF_TIMER( pGpt_ModuleCoreData->GptPredefTimerEn,(uint8)GPT_PREDEF_TIMER_1US_24BIT, (uint8)1U );
        }
        else if( pGpt_ModuleCoreData->pGpt_ModuleConfig->GptPredefTimer1usEnablingGrade == GPT_PREDEF_TIMER_1US_16BIT_ENABLED  )
        {
            GPT_EN_PREDEF_TIMER( pGpt_ModuleCoreData->GptPredefTimerEn,(uint8)GPT_PREDEF_TIMER_1US_16BIT, (uint8)1U );
        }
        else
        {
            ; /* do nothing */
        }
        /* init the predef timer info */
        pGpt_ModuleCoreData->GptPredefTimerTickMax = GptPrv_GetHWChanTickMax(pGpt_ModuleCoreData->pGpt_ModuleConfig->GptPredefTimerHWType);
        pGpt_ModuleCoreData->GptPredefTimerTickvOffs = GptPrv_GetCounterValue( 0U, pGpt_ModuleCoreData->pGpt_ModuleConfig->GptPredefTimerHWType);
        pGpt_ModuleCoreData->GptDrvState = GPT_DRIVER_INITIALIZED;
        (void)Ret;
    }
    return Ret;
}
    /* @[SWS_Gpt_00194] : The function Gpt_DeInit shall be pre compile time
    configurable On/Off by the configuration parameter: GptDeInitApi.
    (SRS_BSW_00171) */

#if (GPT_DEINIT_API == STD_ON)
/*========================================================================================================
 @Service name        Gpt_DeInit
 @Description         De-initializes the GPT driver.
 @param[in]           None
 @param[out]          None
 @param[in, out]      None
 @return              None
 @Pre                 None
 @Post                None
 @Requirements IDs    SWS_Gpt_00281
 @Design IDs          NA
 @service ID          0x02
 @Sync/Async          Synchronous function
 @Reentrancy          Non Reentrant
 @Note                All the other services used after Gpt_Init services is executed.
========================================================================================================*/
    /* @[SWS_Gpt_00008] : The function Gpt_DeInit shall deinitialize the hardware used
    by the GPT driver (depending on configuration) to the power on reset state. Values of
    registers which are not writeable are excluded. It’s the responsibility of the hardware
    design that the state does not lead to undefined activities in the µC.
    (SRS_BSW_00336, SRS_SPAL_12163, SRS_Gpt_12116) */

    /* @[SWS_Gpt_00162] : The function Gpt_DeInit shall influence only the peripherals,
    which are allocated by the static configuration. (SRS_Gpt_12116) */

    /* @[SWS_Gpt_00308] : If a postbuild multiple selectable configuration variant was used,
    the function Gpt_DeInit shall further influence only the peripherals, which are
    allocated by the runtime configuration set passed by the previous call of the function
    Gpt_Init.  (SRS_Gpt_12116)*/

GPT_TIMER_FUNC void Gpt_DeInit(void)
{
    Gpt_ModuleCoreDataType *pGpt_ModuleCoreData = &Gpt_ModuleRTData;
    Std_ReturnType Ret = E_NOT_OK;
#if (GPT_DEV_ERROR_DETECT == STD_ON )
    uint8   DevErrStatus = (uint8)E_OK;

     /* @[SWS_Gpt_00220] : If development error detection is enabled for the GPT module:
        If the driver is not initialized, the function Gpt_DeInit shall raise the error
        GPT_E_UNINIT. : (SRS_BSW_00406) */
    if(GPT_DRIVER_UNINITIALIZED == pGpt_ModuleCoreData->GptDrvState)
    {
        Gpt_ReportError(GPT_SERVICE_ID_DE_INIT, GPT_E_UNINIT);
        DevErrStatus = (uint8)E_NOT_OK;
    }

    if(DevErrStatus == (uint8)E_OK)
#endif /* (GPT_DEV_ERROR_DETECT == STD_ON ) */
    {
        for (uint8 ConfigIdx =0U; ConfigIdx < pGpt_ModuleCoreData->pGpt_ModuleConfig->GptDrvChannelMaxConfig; ConfigIdx++)
        {
            if ( pGpt_ModuleCoreData->Gpt_ChannelCoreData[ConfigIdx].GptChannelState == GPT_CHANNEL_RUNNING )
            {
                /* @[SWS_Gpt_00234] : If any timer channel is in state "running", the function
                    Gpt_DeInit shall raise the runtime error GPT_E_BUSY.  ( ) */
                Gpt_ReportRuntimeError(GPT_SERVICE_ID_DE_INIT, GPT_E_BUSY);
                return ;
            }
        }

        for (uint8 ConfigIdx =0U; ConfigIdx< pGpt_ModuleCoreData->pGpt_ModuleConfig->GptDrvChannelMaxConfig ; ConfigIdx++)
        {
            #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
            pGpt_ModuleCoreData->Gpt_ChannelCoreData[ConfigIdx].GptEnableWakeup = STD_OFF;
            #endif
            #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)             
            pGpt_ModuleCoreData->Gpt_ChannelCoreData[ConfigIdx].GptChannelCbkEn = STD_OFF;
            pGpt_ModuleCoreData->Gpt_ChannelCoreData[ConfigIdx].GptChannelCbkBckEn = STD_OFF;
            #endif
            pGpt_ModuleCoreData->Gpt_ChannelCoreData[ConfigIdx].GptChannelState = GPT_CHANNEL_UNINITIALIZED;
            /* ctl disable and mask */
            GptPrv_DisableTimer( (const Gpt_ChannelType) pGpt_ModuleCoreData->pGpt_ChannelConfig[ConfigIdx].GptChannelID, \
                                 (const Gpt_ChanHWType) pGpt_ModuleCoreData->pGpt_ChannelConfig[ConfigIdx].GptChanHW );
            /* unmap ISR if driver uninit. */
            if(pGpt_ModuleCoreData->pGpt_ChannelConfig[ConfigIdx].GptChanHW == GPT_CHAN_HWTIMER_PL0_QTMR )
            {
                Ret = eGptOs_DeRegisterInterrupt((uint32)(Gpt_PHYIRQ_0 + (uint32)pGpt_ModuleCoreData->pGpt_ChannelConfig[ConfigIdx].GptChannelID), (uint32_t)0U);
            }
            else
            {
                Ret = eGptOs_DeRegisterInterrupt((uint32)(Gpt_PHYIRQ_PROC + (uint32)pGpt_ModuleCoreData->pGpt_ChannelConfig[ConfigIdx].GptChanHW), (uint32_t)0U);
            }
            #if(GPT_DEV_ERROR_DETECT == STD_ON)
            if(Ret != (uint8)E_OK)
            {
                Gpt_ReportError(GPT_SERVICE_ID_DE_INIT, GPT_E_UNINIT);
            }
            #endif
        }
        /*@[SWS_Gpt_00363] :The function Gpt_DeInit shall set the operation mode of the
         GPT driver to "uninitialized". ( )*/
        /* @[SWS_Gpt_00391] : The function Gpt_DeInit shall stop all enabled GPT Predef
                Timers. : (SRS_Gpt_13607)*/
        pGpt_ModuleCoreData->GptPredefTimerTickMax = 0UL;
        pGpt_ModuleCoreData->GptPredefTimerTickvOffs = 0UL;
        pGpt_ModuleCoreData->GptDrvMode = GPT_MODE_NORMAL; 
        pGpt_ModuleCoreData->GptDrvState = GPT_DRIVER_UNINITIALIZED;
        (void)Ret;
    }
    return ;
}
#endif /* (GPT_DEINIT_API == STD_ON) */

/* @[SWS_Gpt_00195] : The function Gpt_GetTimeElapsed shall be pre compile time
configurable On/Off by the configuration parameter: GptTimeElapsedApi.
(SRS_BSW_00171)*/
#if (GPT_TIME_ELAPSED_API == STD_ON)
/*========================================================================================================
@Service name        Gpt_GetTimeElapsed
@Description         Returns the time already elapsed.
@param[in]           Channel : Numeric identifier of the GPT channel.
@param[out]          None
@param[in, out]      None
@return              Gpt_ValueType :Elapsed timer value (in number of ticks)
@Pre                 None
@Post                None
@Requirements IDs    SWS_Gpt_00282
@Design IDs          NA
@service ID          0x03
@Sync/Async          Synchronous function
@Reentrancy          Reentrant
@Note                All the other services used after Gpt_Init services is executed.
========================================================================================================*/
/* @[SWS_Gpt_00113] : The function Gpt_GetTimeElapsed shall be fully reentrant,
    this means even for the same timer channel.  ( )*/
GPT_TIMER_FUNC Gpt_ValueType Gpt_GetTimeElapsed (Gpt_ChannelType Channel)
{
    Gpt_ModuleCoreDataType *pGpt_ModuleCoreData = &Gpt_ModuleRTData;
    Gpt_ValueType Gpt_u64ElapsedTime = 0U;
    Gpt_ValueType Gpt_u64CurrentTicks = 0U;
    Gpt_ValueType Gpt_u64ElapsedTicks = 0U;
    Gpt_ChannelType Gpt_ChannelNum = 0U;
    Gpt_ChannelType Gpt_ChannelConfigIndex = 0U;
#if (GPT_DEV_ERROR_DETECT == STD_ON )
uint8   DevErrStatus = (uint8)E_OK;
#endif

    Gpt_ChannelConfigIndex = (Gpt_ChannelType)((Channel >> GPT_CHAN_CFG_SHFT) & GPT_CHAN_CFG_MASK );
    Gpt_ChannelNum = (Gpt_ChannelType)(Channel & GPT_CHAN_CFG_MASK);

#if (GPT_DEV_ERROR_DETECT == STD_ON )

    if (pGpt_ModuleCoreData->GptDrvState == GPT_DRIVER_UNINITIALIZED )
    {
        /*@[SWS_Gpt_00222] : If development error detection is enabled for GPT module:
          If the driver is not initialized, the function Gpt_GetTimeElapsed shall raise the error
          GPT_E_UNINIT.*/
        Gpt_ReportError( GPT_SERVICE_ID_GET_TIME_ELAPSED, GPT_E_UNINIT);
        DevErrStatus = (uint8)E_NOT_OK;
    }

    if( Gpt_ChannelConfigIndex >=  (Gpt_ChannelType)GptChannel_MAX_ID )
    {
        /*@[SWS_Gpt_00210] : If development error detection is enabled for GPT module:
        If the parameter Channel is invalid (not within the range specified by configuration),
        the function Gpt_GetTimeElapsed shall raise the error GPT_E_PARAM_CHANNEL.*/
        Gpt_ReportError( GPT_SERVICE_ID_GET_TIME_ELAPSED, GPT_E_PARAM_CHANNEL);
        DevErrStatus = (uint8)E_NOT_OK;
    }

    if(DevErrStatus == E_OK)
    {
        if( pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChannelID != Gpt_ChannelNum )
        {
            /*@[SWS_Gpt_00210] : If development error detection is enabled for GPT module:
            If the parameter Channel is invalid (not within the range specified by configuration),
            the function Gpt_GetTimeElapsed shall raise the error GPT_E_PARAM_CHANNEL.*/
            Gpt_ReportError( GPT_SERVICE_ID_GET_TIME_ELAPSED, GPT_E_PARAM_CHANNEL);
            DevErrStatus = (uint8)E_NOT_OK;
        }
    }
    if (DevErrStatus == E_OK)
#endif
    {
        if ( pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptChannelState == GPT_CHANNEL_INITIALIZED )
        {
            /*@[SWS_Gpt_00295] : If the function Gpt_GetTimeElapsed is called on a timer
               channel in state "initialized" (channel started never before), the function shall return
               the value "0".*/
            return 0U;
        }

        if( pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptChannelState == GPT_CHANNEL_STOPPED )
        {
            /*@[SWS_Gpt_00297] : If the function Gpt_GetTimeElapsed is called on a timer
               channel in state "stopped", the function shall return the time value at the moment of
               stopping.  ( )*/

        	/* timer was stopped by the stop API requesting for the Elapsed time, So it will provide the
        	 * previously stopped value and stopped value is equal to elapsed value because of timer stopped
        	 * Running timer else time is different and stopped timer elapsed time is different*/
            Gpt_u64ElapsedTime =  \
            GptPrv_GetSWChanTicks( pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptStopReqTimeInHwTicks, \
                                    pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChannelTickFrequency );
            return Gpt_u64ElapsedTime ;
        }

        if( ( pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptChannelState == GPT_CHANNEL_EXPIRED ) &&
        		( pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChannelMode == GPT_CH_MODE_ONESHOT ) )
        {
            /*@[SWS_Gpt_00299] : If the function Gpt_GetTimeElapsed is called on a channel
               configured for "one-shot mode" in state "expired" (timer has reached the target time),
               the function shall return the target time. : ( )*/
            return pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptTargetTime;
        }
        /* in run mode */
        Gpt_u64CurrentTicks = GptPrv_GetCounterValue((const Gpt_ChannelType) Gpt_ChannelNum, \
                (const Gpt_ChanHWType) pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChanHW );
        /* @[SWS_Gpt_00010] : The function Gpt_GetTimeElapsed shall return the time
        already elapsed. When the channel is in mode “one-shot mode”, this is the value
        relative to the point in time, the channel has been started. : (SRS_Gpt_12117)*/
        
        /* @[SWS_Gpt_00361] : When the channel is in mode "continuous mode", the return
            value of Gpt_GetTimeElapsed is the value relative to the last recurrence (target
            time reached) or to the start of the channel before the first recurrence occurs.*/

        Gpt_u64ElapsedTicks = GptPrv_GetTimeDifference( Gpt_u64CurrentTicks, \
                                pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptStartValueInHWTicks);
        Gpt_u64ElapsedTime = \
            GptPrv_GetSWChanTicks( Gpt_u64ElapsedTicks, \
                                    pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChannelTickFrequency );
        /* mask max value */
        Gpt_u64ElapsedTime &= pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChannelTickValueMax;

    }
   return Gpt_u64ElapsedTime;
}
#endif /* (GPT_TIME_ELAPSED_API == STD_ON) */

    /* @[SWS_Gpt_00196] : The function Gpt_GetTimeRemaining shall be pre compile time
        configurable On/Off by the configuration parameter: GptTimeRemainingApi.
        (SRS_BSW_00171) */
#if (GPT_TIME_REMAINING_API == STD_ON)
/*========================================================================================================
 @Service name        Gpt_GetTimeRemaining
 @Description         Returns the time remaining until the target time is reached.
 @param[in]           Channel : Numeric identifier of the GPT channel.
 @param[out]          None
 @param[in, out]      None
 @return              Gpt_ValueType :Remaining timer value (in number of ticks)
 @Pre                 None
 @Post                None
 @Requirements IDs    SWS_Gpt_00283
 @Design IDs          NA
 @service ID          0x04
 @Sync/Async          Synchronous function
 @Reentrancy          Reentrant
 @Note                All the other services used after Gpt_Init services is executed.
========================================================================================================*/
    /* @[SWS_Gpt_00114] : The function Gpt_GetTimeRemaining shall be fully reentrant,
   this means even for the same timer channel.  ( )*/
GPT_TIMER_FUNC Gpt_ValueType Gpt_GetTimeRemaining (Gpt_ChannelType Channel)
{
    Gpt_ModuleCoreDataType *pGpt_ModuleCoreData = &Gpt_ModuleRTData;
    Gpt_ValueType Gpt_u64RemainingTime = 0U;
    Gpt_ValueType Gpt_u64CurrentTicks = 0U;
    Gpt_ValueType Gpt_u64RemainingTicks = 0U;
    Gpt_ChannelType Gpt_ChannelNum = 0U;
    Gpt_ChannelType Gpt_ChannelConfigIndex = 0U;
#if (GPT_DEV_ERROR_DETECT == STD_ON )
    uint8   DevErrStatus = (uint8)E_OK;
#endif

    Gpt_ChannelConfigIndex = (Gpt_ChannelType)((Channel >> GPT_CHAN_CFG_SHFT ) & GPT_CHAN_CFG_MASK);
    Gpt_ChannelNum = (Gpt_ChannelType)(Channel & GPT_CHAN_CFG_MASK);

#if (GPT_DEV_ERROR_DETECT == STD_ON )

    if (pGpt_ModuleCoreData->GptDrvState == GPT_DRIVER_UNINITIALIZED )
    {
        /* @[SWS_Gpt_00223] : If development error detection is enabled for GPT module:
        If the driver is not initialized, the function Gpt_GetTimeRemaining shall raise the
        error GPT_E_UNINIT. (SRS_BSW_00406)*/
        Gpt_ReportError( GPT_SERVICE_ID_GET_TIME_REMAINING, GPT_E_UNINIT);
        DevErrStatus = (uint8)E_NOT_OK;
    }
    
    if( Gpt_ChannelConfigIndex >=  (Gpt_ChannelType)GptChannel_MAX_ID )
    {
        /* @[SWS_Gpt_00211] : If development error detection is enabled for GPT module:
        If the parameter Channel is invalid (not within the range specified by configuration),
        the function Gpt_GetTimeRemaining shall raise the error
        GPT_E_PARAM_CHANNEL.*/
        Gpt_ReportError( GPT_SERVICE_ID_GET_TIME_REMAINING, GPT_E_PARAM_CHANNEL);
        DevErrStatus = (uint8)E_NOT_OK;
    }
    
    if(DevErrStatus == E_OK)
    {
        if( pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChannelID != Gpt_ChannelNum )
        {
            /* @[SWS_Gpt_00211] : If development error detection is enabled for GPT module:
            If the parameter Channel is invalid (not within the range specified by configuration),
            the function Gpt_GetTimeRemaining shall raise the error
            GPT_E_PARAM_CHANNEL.*/
               Gpt_ReportError( GPT_SERVICE_ID_GET_TIME_REMAINING, GPT_E_PARAM_CHANNEL);
               DevErrStatus = (uint8)E_NOT_OK;
        }
    }
    if (DevErrStatus == E_OK)
#endif
    {
        if ( pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptChannelState == GPT_CHANNEL_INITIALIZED )
        {
            /*@[SWS_Gpt_00301] : If the function Gpt_GetTimeRemaining is called on a timer
               channel in state "initialized" (channel started never before), the function shall return
               the value "0".  ( ) */
            return 0U;
        }

        if( pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptChannelState == GPT_CHANNEL_STOPPED )
        {   
            /*@[SWS_Gpt_00303] : If the function Gpt_GetTimeRemaining is called on a timer
              channel in state "stopped", the function shall return the remaining time value at the
              moment of stopping.  ( )*/
        	Gpt_u64RemainingTicks = \
                GptPrv_GetTimeDifference( pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptStopValueInHwTicks, \
                                            pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptStopReqTimeInHwTicks );
            /* time remain */                                             
            Gpt_u64RemainingTime =  GptPrv_GetSWChanTicks( Gpt_u64RemainingTicks, \
                                    pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChannelTickFrequency );                                                 
                                                              
        	Gpt_u64RemainingTime &= pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChannelTickValueMax;
        	return Gpt_u64RemainingTime;
        }

        if( (pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptChannelState == GPT_CHANNEL_EXPIRED ) && \
        		(pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChannelMode == GPT_CH_MODE_ONESHOT) )
        {
            /*@[SWS_Gpt_00305] : If the function Gpt_GetTimeRemaining is called on a channel
              configured for "one-shot mode" in state "expired" (timer has reached the target time),
              the function shall return the value “0”.  ( )*/
            return 0U;
        }
        /* in run mode */
        Gpt_u64CurrentTicks = GptPrv_GetCounterValue((const Gpt_ChannelType) Gpt_ChannelNum, \
                (const Gpt_ChanHWType) pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChanHW );
        /* @[SWS_Gpt_00083] :The function Gpt_GetTimeRemaining shall return the timer
           value remaining until the target time will be reached next time. The remaining time is
           the "target time" minus the time already elapsed.  (SRS_Gpt_12117)*/
        Gpt_u64RemainingTicks = \
                GptPrv_GetTimeDifference( pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptStopValueInHwTicks, \
                                            Gpt_u64CurrentTicks );
        /* time remain */                                             
        Gpt_u64RemainingTime =  GptPrv_GetSWChanTicks( Gpt_u64RemainingTicks, \
                                    pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChannelTickFrequency );       
        
        Gpt_u64RemainingTime &= pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChannelTickValueMax;
    }
    return Gpt_u64RemainingTime;
}
#endif /*(GPT_TIME_REMAINING_API == STD_ON)*/

/*========================================================================================================
 @Service name        Gpt_StartTimer
 @Description         Starts a timer channel.
 @param[in]           Channel : Numeric identifier of the GPT channel.
                      Value : Target time in number of ticks.
 @param[out]          None
 @param[in, out]      None
 @return              None
 @Pre                 None
 @Post                None
 @Requirements IDs    SWS_Gpt_00284
 @Design IDs          NA
 @service ID          0x05
 @Sync/Async          Synchronous function
 @Reentrancy          Reentrant (but not for the same timer channel)
 @Note                All the other services used after Gpt_Init services is executed.
========================================================================================================*/
    /* @[SWS_Gpt_00115] : The function Gpt_StartTimer shall be reentrant, if the timer
    channels used in concurrent calls are different.  ( )*/

GPT_TIMER_FUNC void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value)
{
    Gpt_ModuleCoreDataType *pGpt_ModuleCoreData = &Gpt_ModuleRTData;
    Gpt_ChannelType Gpt_ChannelNum = 0U;
    Gpt_ChannelType Gpt_ChannelConfigIndex = 0U;
    Gpt_ChannelType Gpt_ChannelConfigIndex1 = 0U;
#if (GPT_DEV_ERROR_DETECT == STD_ON )
    uint8   DevErrStatus = (uint8)E_OK;
#endif
    Gpt_ChannelConfigIndex = (Gpt_ChannelType)((Channel >> GPT_CHAN_CFG_SHFT) & GPT_CHAN_CFG_MASK);
    Gpt_ChannelNum = (Gpt_ChannelType)(Channel & GPT_CHAN_CFG_MASK);

#if (GPT_DEV_ERROR_DETECT == STD_ON )
    /* @[SWS_Gpt_00224] : If development error detection is enabled for GPT module:
    If the driver is not initialized, the function Gpt_StartTimer shall raise the error
    GPT_E_UNINIT.*/
    if (pGpt_ModuleCoreData->GptDrvState == GPT_DRIVER_UNINITIALIZED )
    {
        Gpt_ReportError( GPT_SERVICE_ID_START_TIME, GPT_E_UNINIT);
        DevErrStatus = (uint8)E_NOT_OK;
    }
    
    if( Gpt_ChannelConfigIndex >=  (Gpt_ChannelType)GptChannel_MAX_ID )
    {
        /* @[SWS_Gpt_00212] : If development error detection is enabled for GPT module:
        If the parameter Channel is invalid (not within the range specified by configuration),
        the function Gpt_StartTimer shall raise the error GPT_E_PARAM_CHANNEL.*/
        Gpt_ReportError( GPT_SERVICE_ID_START_TIME, GPT_E_PARAM_CHANNEL);
        DevErrStatus = (uint8)E_NOT_OK;
    }
    
    if(DevErrStatus == E_OK)
    {
        /* @[SWS_Gpt_00212] : If development error detection is enabled for GPT module:
        If the parameter Channel is invalid (not within the range specified by configuration),
        the function Gpt_StartTimer shall raise the error GPT_E_PARAM_CHANNEL.*/
        if( pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChannelID != Gpt_ChannelNum )
        {
            Gpt_ReportError( GPT_SERVICE_ID_START_TIME, GPT_E_PARAM_CHANNEL);
            DevErrStatus = (uint8)E_NOT_OK;
        }
        if (DevErrStatus == E_OK)
        {
            /* @[SWS_Gpt_00218] If development error detection is enabled for GPT module:
            The function Gpt_StartTimer shall raise the error GPT_E_PARAM_VALUE if the
            parameter Value is "0" or not within the allowed range (exceeding the maximum
            timer resolution).*/
        	if( (Value <= 0x0U) || \
                (pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChannelTickValueMax <= Value) )
            {
                Gpt_ReportError( GPT_SERVICE_ID_START_TIME, GPT_E_PARAM_VALUE);
                DevErrStatus = (uint8)E_NOT_OK;
            }
        }
    }
    if (DevErrStatus == E_OK)
#endif
    {
        /*@[SWS_Gpt_00084] : If the function Gpt_StartTimer is called on a channel in state
          "running", the function shall raise the runtime error GPT_E_BUSY.*/
        if( pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptChannelState == GPT_CHANNEL_RUNNING )
        {
        	Gpt_ReportRuntimeError( GPT_SERVICE_ID_START_TIME, GPT_E_BUSY);
            return;
        }
        /* @[SWS_Gpt_00274] ⌈The function Gpt_StartTimer shall start the selected timer
        channel with a defined target time. ⌋ (SRS_Gpt_12128)
        Note : Not required to start separately timer, Just writing to Cval or Tval is required to start count */

    	 /* The "target time" is passed as a parameter to Gpt_StartTimer. So, for each start
         of a timer channel, the target time can be set individually */
    	pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptTargetTime = Value;
        /* Target Time */
        pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptTargetTimeInHwTicks = GptPrv_GetHWChanTicks(Value, \
                                                    pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChannelTickFrequency);
        /* load compare counter */
        pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptStopValueInHwTicks =   \
        GptPrv_SetCounterValue( Gpt_ChannelNum, \
                                (const Gpt_ChanHWType) pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChanHW, \
                                pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptTargetTimeInHwTicks,   \
                                &(pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptStartValueInHWTicks));
                                
        /*[SWS_Gpt_00364] The state of the selected timer channel shall be changed to
           "running" if Gpt_StartTimer is called.*/
         pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptChannelState = GPT_CHANNEL_RUNNING;

         /*[SWS_Gpt_00275] : If configured and enabled, an interrupt notification or a wakeup
           interrupt occurs, when the target time is reached.*/
        /* ISR is enabled, When the target time is reached
         * Wake-up is not supported */
         /* ctl enablr and unmask */
         GptPrv_EnableTimer( (const Gpt_ChannelType) Gpt_ChannelNum, \
                                 (const Gpt_ChanHWType) pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChanHW );
    }
    return ;
}

/*========================================================================================================
 @Service name        Gpt_StopTimer
 @Description         Starts a timer channel.
 @param[in]           Channel : Numeric identifier of the GPT channel.
 @param[out]          None
 @param[in, out]      None
 @return              None
 @Pre                 None
 @Post                None
 @Requirements IDs    SWS_Gpt_00285
 @Design IDs          NA
 @service ID          0x06
 @Sync/Async          Synchronous function
 @Reentrancy          Reentrant (but not for the same timer channel)
 @Note                All the other services used after Gpt_Init services is executed.
========================================================================================================*/
    /* @[SWS_Gpt_00116] : The function Gpt_StopTimer shall be reentrant, if the timer
    channels used in concurrent calls are different. ⌋ ( )*/

    /* Note : Actually timer is not stopping because stop feature of Hw is not available
     * Here just stopping ISR trigger and get the current value and difference with start value
     * and store difference value, it will become same has elapsed time value with respect start value
     * Stop API : stored elapse time at the time of stop request
     * Elapsed API : provide elapse time at run time without stopping
     * if Elapse API called for already stopped timer than stopped value by stop API,
     * stopped value  become return value for elapse API   */

GPT_TIMER_FUNC void Gpt_StopTimer(Gpt_ChannelType Channel)
{
    Gpt_ModuleCoreDataType *pGpt_ModuleCoreData = &Gpt_ModuleRTData;
    Gpt_ChannelType Gpt_ChannelNum = 0U;
    Gpt_ChannelType Gpt_ChannelConfigIndex = 0U;
    uint64 Gpt_u64CurrentTicks = 0U;
    uint64 Gpt_u64ElapsedTicks = 0U;
#if (GPT_DEV_ERROR_DETECT == STD_ON )
    uint8   DevErrStatus = (uint8)E_OK;
#endif

    Gpt_ChannelConfigIndex = (Gpt_ChannelType)((Channel >> GPT_CHAN_CFG_SHFT) & GPT_CHAN_CFG_MASK);
    Gpt_ChannelNum = (Gpt_ChannelType)(Channel & GPT_CHAN_CFG_MASK);

#if (GPT_DEV_ERROR_DETECT == STD_ON )
    if (pGpt_ModuleCoreData->GptDrvState == GPT_DRIVER_UNINITIALIZED )
    {
        /* [SWS_Gpt_00225] ⌈If development error detection is enabled for GPT module:
        If the driver is not initialized, the function Gpt_StopTimer shall raise the error
        GPT_E_UNINIT. ⌋ (SRS_BSW_00406)*/

        Gpt_ReportError( GPT_SERVICE_ID_STOP_TIMER, GPT_E_UNINIT);
        DevErrStatus = (uint8)E_NOT_OK;
    }
    
    if( Gpt_ChannelConfigIndex >=  (Gpt_ChannelType)GptChannel_MAX_ID )
    {
        /* @[SWS_Gpt_00213] ⌈If development error detection is enabled for GPT module:
          If the parameter Channel is invalid (not within the range specified by configuration),
          the function Gpt_StopTimer shall raise the error GPT_E_PARAM_CHANNEL. ⌋ ( )*/
        Gpt_ReportError( GPT_SERVICE_ID_STOP_TIMER, GPT_E_PARAM_CHANNEL);
        DevErrStatus = (uint8)E_NOT_OK;
    }
     
    if(DevErrStatus == E_OK)
    {
        if( pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChannelID != Gpt_ChannelNum )
        {
            /* @[SWS_Gpt_00213] ⌈If development error detection is enabled for GPT module:
              If the parameter Channel is invalid (not within the range specified by configuration),
              the function Gpt_StopTimer shall raise the error GPT_E_PARAM_CHANNEL. ⌋ ( )*/
            Gpt_ReportError( GPT_SERVICE_ID_STOP_TIMER, GPT_E_PARAM_CHANNEL);
            DevErrStatus = (uint8)E_NOT_OK;
        }
    }
    if (DevErrStatus == E_OK)
#endif
    {
        if( pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptChannelState != GPT_CHANNEL_RUNNING )
        {
             /*@[SWS_Gpt_00099] : If development error detection is enabled for GPT module:
             If the function Gpt_StopTimer is called on a channel in state "initialized", "stopped"
             or "expired", the function shall not raise a development error. ( ) */

            /*@[SWS_Gpt_00344] : If the function Gpt_StopTimer is called on a channel in state
            "initialized", "stopped" or "expired", the function shall leave without any action (no
             change of the channel state).  ( )*/

            return ;
        }

        Gpt_u64CurrentTicks = GptPrv_GetCounterValue((const Gpt_ChannelType) Gpt_ChannelNum, \
            (const Gpt_ChanHWType) pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChanHW );
        
        Gpt_u64ElapsedTicks = GptPrv_GetTimeDifference( Gpt_u64CurrentTicks, \
                       pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptStartValueInHWTicks );

        pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptStopReqTimeInHwTicks = Gpt_u64ElapsedTicks;

        /* @[SWS_Gpt_00013] : The function Gpt_StopTimer shall stop the selected timer
           channel. : (SRS_Gpt_12119)*/
        /* ctl disable and mask */
        GptPrv_DisableTimer( (const Gpt_ChannelType) Gpt_ChannelNum, \
              (const Gpt_ChanHWType) pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChanHW );
        /* @[SWS_Gpt_00343] : The state of the selected timer channel shall be changed to
           "stopped" if Gpt_StopTimer is called.  ( )*/
        pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptChannelState = GPT_CHANNEL_STOPPED;
    }
    return ;
}

    /* @[SWS_Gpt_00199] : The function Gpt_EnableNotification shall be pre compile
    time configurable On/Off by the configuration parameter:
    GptEnableDisableNotificationApi.  (SRS_BSW_00171*/

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
/*========================================================================================================
 @Service name        Gpt_EnableNotification
 @Description         Enables the interrupt notification for a channel (relevant in normal mode)
 @param[in]           Channel : Numeric identifier of the GPT channel.
 @param[out]          None
 @param[in, out]      None
 @return              Void
 @Pre                 None
 @Post                None
 @Requirements IDs    SWS_Gpt_00286
 @Design IDs          NA
 @service ID          0x07
 @Sync/Async          Synchronous function
 @Reentrancy          Reentrant (but not for the same timer channel)
 @Note                All the other services used after Gpt_Init services is executed.
========================================================================================================*/
/* @[SWS_Gpt_00117] ⌈The function Gpt_EnableNotification shall be reentrant, if
   the timer channels used in concurrent calls are different. ⌋ ( )*/

GPT_TIMER_FUNC void Gpt_EnableNotification (Gpt_ChannelType Channel)
{
    Gpt_ModuleCoreDataType *pGpt_ModuleCoreData = &Gpt_ModuleRTData;
    Gpt_ChannelType Gpt_ChannelNum = 0U;
    Gpt_ChannelType Gpt_ChannelConfigIndex = 0U;
#if (GPT_DEV_ERROR_DETECT == STD_ON )
    uint8   DevErrStatus = (uint8)E_OK;
#endif

    Gpt_ChannelConfigIndex = (Gpt_ChannelType)((Channel >> GPT_CHAN_CFG_SHFT) & GPT_CHAN_CFG_MASK);
    Gpt_ChannelNum = (Gpt_ChannelType)(Channel & GPT_CHAN_CFG_MASK);

#if (GPT_DEV_ERROR_DETECT == STD_ON )
    if (pGpt_ModuleCoreData->GptDrvState == GPT_DRIVER_UNINITIALIZED )
    {
        /* @[SWS_Gpt_00226] : If development error detection is enabled for GPT module:
        If the driver is not initialized, the function Gpt_EnableNotification shall raise the
        error GPT_E_UNINIT.  (SRS_BSW_00406) */
        Gpt_ReportError( GPT_SERVICE_ID_ENABLE_NOTIFICATION, GPT_E_UNINIT);
        DevErrStatus = (uint8)E_NOT_OK;
    }
    
    if( Gpt_ChannelConfigIndex >=  (Gpt_ChannelType)GptChannel_MAX_ID )
    {
        /*@[SWS_Gpt_00214] : If development error detection is enabled for GPT module:
        If the parameter Channel is invalid (not within the range specified by
        configuration), the function Gpt_EnableNotification shall raise the error
        GPT_E_PARAM_CHANNEL. ( )*/
        Gpt_ReportError( GPT_SERVICE_ID_ENABLE_NOTIFICATION, GPT_E_PARAM_CHANNEL);
        DevErrStatus = (uint8)E_NOT_OK;
    }
     
    if(DevErrStatus == E_OK)
    {
        if( pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChannelID != Gpt_ChannelNum )
       {
           /*@[SWS_Gpt_00214] : If development error detection is enabled for GPT module:
           If the parameter Channel is invalid (not within the range specified by
           configuration), the function Gpt_EnableNotification shall raise the error
           GPT_E_PARAM_CHANNEL. ( )*/
           Gpt_ReportError( GPT_SERVICE_ID_ENABLE_NOTIFICATION, GPT_E_PARAM_CHANNEL);
           DevErrStatus = (uint8)E_NOT_OK;
       }
       if( pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptNotification == NULL_PTR )
       {
           /* @[SWS_Gpt_00377] : If development error detection is enabled for GPT module:
           If no valid notification function is configured (GptNotification), the function
           Gpt_EnableNotification shall raise the error GPT_E_PARAM_CHANNEL. ( )*/
           Gpt_ReportError( GPT_SERVICE_ID_ENABLE_NOTIFICATION, GPT_E_PARAM_CHANNEL);
           DevErrStatus = (uint8)E_NOT_OK;
       }
    }
    if (DevErrStatus == E_OK)
#endif
    {
        /* @[SWS_Gpt_00014] ⌈The function Gpt_EnableNotification shall enable the
         interrupt notification of the referenced channel configured for notification (see also
         SWS_Gpt_00233). The function shall save an attribute like "notification enabled" of
         the channel. ⌋ (SRS_SPAL_00157, SRS_SPAL_12067, SRS_Gpt_12121)
         Comment: This attribute affects the interrupt notification always when the driver is in
         "normal mode". In "sleep mode" the attribute has no influence. */
         pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptChannelCbkEn = STD_ON;
         pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptChannelCbkBckEn = STD_ON;
    }

	return ;
}
#endif /* (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON) */

    /* @[SWS_Gpt_00200] : The function Gpt_DisableNotification shall be pre
    compile time configurable On/Off by the configuration parameter:
    GptEnableDisableNotificationApi.: (SRS_BSW_00171) */

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
/*========================================================================================================
 @Service name        Gpt_DisableNotification
 @Description         Disables the interrupt notification for a channel (relevant in normal mode).
 @param[in]           Channel : Numeric identifier of the GPT channel.
 @param[out]          None
 @param[in, out]      None
 @return              Void
 @Pre                 None
 @Post                None
 @Requirements IDs    SWS_Gpt_00287
 @Design IDs          NA
 @service ID          0x08
 @Sync/Async          Synchronous function
 @Reentrancy          Reentrant (but not for the same timer channel)
 @Note                All the other services used after Gpt_Init services is executed.
========================================================================================================*/
    /* @[SWS_Gpt_00118] : The function Gpt_DisableNotification shall be reentrant,
    if the timer channels used in concurrent calls are different.( )*/
GPT_TIMER_FUNC void Gpt_DisableNotification (Gpt_ChannelType Channel)
{
    Gpt_ModuleCoreDataType *pGpt_ModuleCoreData = &Gpt_ModuleRTData;
    Gpt_ChannelType Gpt_ChannelNum = 0U;
    Gpt_ChannelType Gpt_ChannelConfigIndex = 0U;
#if (GPT_DEV_ERROR_DETECT == STD_ON )
    uint8   DevErrStatus = (uint8)E_OK;
#endif

    Gpt_ChannelConfigIndex = (Gpt_ChannelType)((Channel >> GPT_CHAN_CFG_SHFT) & GPT_CHAN_CFG_MASK);
    Gpt_ChannelNum = (Gpt_ChannelType)(Channel & GPT_CHAN_CFG_MASK);

#if (GPT_DEV_ERROR_DETECT == STD_ON )
    if (pGpt_ModuleCoreData->GptDrvState == GPT_DRIVER_UNINITIALIZED )
    {
        /*  @[SWS_Gpt_00226] : If development error detection is enabled for GPT module:
        If the driver is not initialized, the function Gpt_DisableNotification shall raise the
        error GPT_E_UNINIT.  (SRS_BSW_00406)*/
        Gpt_ReportError( GPT_SERVICE_ID_DISABLE_NOTIFICATION, GPT_E_UNINIT);
        DevErrStatus = (uint8)E_NOT_OK;
    }
         
    if( Gpt_ChannelConfigIndex >=  (Gpt_ChannelType)GptChannel_MAX_ID )
    {
        /*@[SWS_Gpt_00214] : If development error detection is enabled for GPT module:
        If the parameter Channel is invalid (not within the range specified by configuration),
        the function Gpt_DisableNotification shall raise the error GPT_E_PARAM_CHANNEL.*/
        Gpt_ReportError( GPT_SERVICE_ID_DISABLE_NOTIFICATION, GPT_E_PARAM_CHANNEL);
        DevErrStatus = (uint8)E_NOT_OK;
    }
    
    if(DevErrStatus == E_OK)
    {
        if( pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChannelID != Gpt_ChannelNum )
        {

            /* @[SWS_Gpt_00214] ⌈If development error detection is enabled for GPT module:
               If the parameter Channel is invalid (not within the range specified by
               configuration), the function Gpt_DisableNotification shall raise the error
               GPT_E_PARAM_CHANNEL.  ( )*/
            Gpt_ReportError( GPT_SERVICE_ID_DISABLE_NOTIFICATION, GPT_E_PARAM_CHANNEL);
            DevErrStatus = (uint8)E_NOT_OK;
        }
    }
    if( pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptNotification == NULL_PTR )
    {

        /* @[SWS_Gpt_00379] ⌈If development error detection is enabled for GPT module:
           If no valid notification function is configured (GptNotification), the function
           Gpt_DisableNotification shall raise the error GPT_E_PARAM_CHANNEL. ⌋ ( )*/
        Gpt_ReportError( GPT_SERVICE_ID_DISABLE_NOTIFICATION, GPT_E_PARAM_CHANNEL);
        DevErrStatus = (uint8)E_NOT_OK;
    }

    if (DevErrStatus == E_OK)
#endif
    {
        /*[SWS_Gpt_00015] ⌈The function Gpt_DisableNotification shall disable the
        interrupt notification of the referenced channel configured for notification (see also
        SWS_Gpt_00233). The function shall save an attribute like "notification disabled" of
        the channel. ⌋ (SRS_SPAL_00157, SRS_Gpt_12122, SRS_SPAL_12067)
        Comment: This attribute affects the interrupt notification always when the driver is in
        "normal mode". In "sleep mode" the attribute has no influence. */
        pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptChannelCbkEn = STD_OFF;
        pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptChannelCbkBckEn = STD_OFF; 
    }
    return ;
}
#endif /*(GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)*/


/* @[SWS_Gpt_00255] : The function Gpt_SetMode is only available if the configuration
   parameter GptReportWakeupSource is enabled.
    @[SWS_Gpt_00157] : The function Gpt_DisableWakeup is only feasible, if
   GptReportWakeupSource is statically configured available.
   @[SWS_Gpt_00158] ⌈The function Gpt_EnableWakeup is only feasible, if
   GptReportWakeupSource is statically configured available.    */

#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/* @[SWS_Gpt_00201] : The function Gpt_SetMode shall be pre compile time configurable On/Off by the
configuration parameter: GptWakeupFunctionalityApi (SRS_BSW_00171) */
/* @[SWS_Gpt_00203] : The function Gpt_EnableWakeup shall be pre compile time configurable On/Off by
the configuration parameter: GptWakeupFunctionalityApi (SRS_BSW_00171) */
/* @[SWS_Gpt_00202] : The function Gpt_DisableWakeup shall be pre compile time configurable On/Off by
the configuration parameter: GptWakeupFunctionalityApi (SRS_BSW_00171) */

/*========================================================================================================
 @Service name        Gpt_SetMode
 @Description         Sets the operation mode of the GPT.
 @param[in]           GPT_MODE_NORMAL: Normal operation mode of the GPT driver.
                      GPT_MODE_SLEEP: Sleep mode of the GPT driver (wakeup capable).
                      See also Gpt_ModeType
 @param[out]          None
 @param[in, out]      None
 @return              Void
 @Pre                 None
 @Post                None
 @Requirements IDs    SWS_Gpt_00288
 @Design IDs          NA
 @service ID          0x09
 @Sync/Async          Synchronous function
 @Reentrancy          Non - Reentrant
 @Note                All the other services used after Gpt_Init services is executed.
========================================================================================================*/
/* @[SWS_Gpt_00151] : The function Gpt_SetMode shall set the operation mode of the
GPT driver to the given mode parameter. (SRS_SPAL_12169, SRS_Gpt_13603)*/
GPT_TIMER_FUNC void Gpt_SetMode (Gpt_ModeType Mode)
{
    Gpt_ModuleCoreDataType *pGpt_ModuleCoreData = &Gpt_ModuleRTData;
    Gpt_ChannelType Gpt_ChannelNum = 0U;
    Gpt_ChannelType Gpt_ChannelConfigIndex = 0U;
    #if (GPT_DEV_ERROR_DETECT == STD_ON )
    uint8   DevErrStatus = (uint8)E_OK;
#endif

#if (GPT_DEV_ERROR_DETECT == STD_ON )
    if (pGpt_ModuleCoreData->GptDrvState == GPT_DRIVER_UNINITIALIZED )
    {
        /*  @[SWS_Gpt_00228] : dIf development error detection is enabled for GPT module:
            If the driver is not initialized, the function Gpt_SetMode shall raise the error GPT_E_-
            UNINIT (SRS_BSW_00406)*/
        Gpt_ReportError( GPT_SERVICE_ID_SET_MODE, GPT_E_UNINIT);
        DevErrStatus = (uint8)E_NOT_OK;
    }
    if(DevErrStatus == E_OK)
    {
        if((Mode != GPT_MODE_NORMAL) && ( Mode != GPT_MODE_SLEEP))
        {

            /* @[SWS_Gpt_00231] If development error detection is enabled for GPT module:
                The function Gpt_SetMode shall raise the error GPT_E_PARAM_MODE if the parameter
                Mode is invalid.  (SRS_BSW_00406)*/
            Gpt_ReportError( GPT_SERVICE_ID_SET_MODE, GPT_E_PARAM_MODE);
            DevErrStatus = (uint8)E_NOT_OK;
        }
    }

    if (DevErrStatus == E_OK)
#endif
    {
       for( Gpt_ChannelConfigIndex = 0U; \
            Gpt_ChannelConfigIndex < pGpt_ModuleCoreData->pGpt_ModuleConfig->GptDrvChannelMaxConfig; \
            Gpt_ChannelConfigIndex ++ )
            {
                /* @[SWS_Gpt_00152] : If the parameter Mode has the value GPT_MODE_NORMAL: The function Gpt_SetMode
                shall enable the interrupt notification for all channels which are configured for notification
                and the notification is enabled (stored attribute) via the function Gpt_EnableNotification prior.
                All other interrupt notifications shall be disabled ( SRS_Gpt_13603 ) */
                
                /* @[SWS_Gpt_00165] : If the parameter Mode has the value GPT_MODE_NORMAL, the
                    function Gpt_SetMode shall not restart automatically the timer channels which have
                    been stopped by entering the sleep Mode (SRS_Gpt_13603 ) */
                if( GPT_MODE_NORMAL == Mode )
                {
                    pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptChannelCbkEn = \
                    pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptChannelCbkBckEn;  
                }  
                /* @[SWS_Gpt_00164] : If the function Gpt_SetMode is called with parameter Mode has
                    the value GPT_MODE_SLEEP: All timer channels in state "running" which are not
                    configured for wakeup or not enabled for wakeup interruption (stored attribute) via
                    Gpt_EnableWakeup shall be stopped and their state shall be changed to "stopped" (SRS_Gpt_13603) */                    

                if(( pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptChannelState == GPT_CHANNEL_RUNNING ) && \
                        ( pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptEnableWakeup != STD_ON ) && \
                        ( GPT_MODE_SLEEP == Mode ))
                {
                    Gpt_ChannelNum = (Gpt_ChannelType)(Gpt_ChannelConfigIndex << GPT_CHAN_CFG_SHFT ) | ( pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChannelID & GPT_CHAN_CFG_MASK );      
                    Gpt_StopTimer( Gpt_ChannelNum );
                }
                /* @[SWS_Gpt_00341] : If the parameter has the value GPT_MODE_SLEEP the function
                    Gpt_SetMode shall not start a wakeup timer automatically. First, the user shall call
                    Gpt_StartTimer to start a wakeup timer, after this the user shall call Gpt_SetMode
                    with parameter GPT_MODE_SLEEP  (SRS_Gpt_13603) */ 
                /* @[SWS_Gpt_00153] : the parameter Mode has the value GPT_MODE_SLEEP:
                    The function Gpt_SetMode shall enable the wakeup interrupts for all channels which
                    are configured for wakeup and the wakeup is enabled (stored attribute) via the function
                    Gpt_EnableWakeup prior. All other wakeup interrupts shall be disabled (SRS_Gpt_13603) */ 
                if( ( pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptEnableWakeup != STD_ON ) && \
                    ( GPT_MODE_SLEEP == Mode ) )
                {
                    /* ctl disable and mask */
                    pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptChannelCbkEn = STD_OFF; 
                    GptPrv_DisableTimer( (const Gpt_ChannelType)  pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChannelID, \
                                 (const Gpt_ChanHWType) pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChanHW );    
                }
            }
            /* @[SWS_Gpt_00392] : If the parameter Mode has the value GPT_MODE_NORMAL: If the driver is in "sleep mode",
                the function Gpt_SetMode shall restart all enabled GPT Predef Timers at value "0". (SRS_Gpt_13607) */
            if( GPT_MODE_NORMAL == Mode )
            {
                pGpt_ModuleCoreData->GptPredefTimerTickvOffs = GptPrv_GetCounterValue( 0U, pGpt_ModuleCoreData->pGpt_ModuleConfig->GptPredefTimerHWType);
                pGpt_ModuleCoreData->GptDrvMode = GPT_MODE_NORMAL;
            } 
            /* @[SWS_Gpt_00393] : If the parameter Mode has the value GPT_MODE_SLEEP: The function Gpt_SetMode shall 
            stop all enabled GPT Predef Timers (SRS_Gpt_13607) */
            if( GPT_MODE_SLEEP == Mode )
            {
                pGpt_ModuleCoreData->GptDrvMode = GPT_MODE_SLEEP;
            } 
    }
    return;
}

/*========================================================================================================
 @Service name        Gpt_EnableWakeup
 @Description         Enables the wakeup interrupt of a channel (relevant in sleep mode).
 @param[in]           Channel Numeric identifier of the GPT channel.
 @param[out]          None
 @param[in, out]      None
 @return              Void
 @Pre                 None
 @Post                None
 @Requirements IDs    SWS_Gpt_00290
 @Design IDs          NA
 @service ID          0x0b
 @Sync/Async          Synchronous function
 @Reentrancy          Reentrant (but not for the same timer channel).
 @Note                All the other services used after Gpt_Init services is executed.
========================================================================================================*/
/* @[SWS_Gpt_00159] ⌈The function Gpt_DisableWakeup shall disable the wakeup
interrupt of the referenced channel configured for wakeup. The function shall save an
attribute like "wakeup disabled" of the channel.
Comment: This attribute affects the wakeup interrupt always when the driver is in
"sleep mode". In "normal mode" the attribute has no influence. (SRS_Gpt_13602)*/
GPT_TIMER_FUNC void Gpt_EnableWakeup (Gpt_ChannelType Channel )
{
    Gpt_ModuleCoreDataType *pGpt_ModuleCoreData = &Gpt_ModuleRTData;
    Gpt_ChannelType Gpt_ChannelNum = 0U;
    Gpt_ChannelType Gpt_ChannelConfigIndex = 0U;
#if (GPT_DEV_ERROR_DETECT == STD_ON )
    uint8   DevErrStatus = (uint8)E_OK;
#endif

    Gpt_ChannelConfigIndex = (Gpt_ChannelType)((Channel >> GPT_CHAN_CFG_SHFT) & GPT_CHAN_CFG_MASK);
    Gpt_ChannelNum = (Gpt_ChannelType)(Channel & GPT_CHAN_CFG_MASK);

#if (GPT_DEV_ERROR_DETECT == STD_ON )
    if (pGpt_ModuleCoreData->GptDrvState == GPT_DRIVER_UNINITIALIZED )
    {
        /*  @[SWS_Gpt_00230] : If development error detection is enabled for GPT module:
        If the driver is not initialized, the function Gpt_EnableWakeup shall raise the
        error GPT_E_UNINIT.  (SRS_BSW_00406)*/
        Gpt_ReportError( GPT_SERVICE_ID_ENABLE_WAKEUP, GPT_E_UNINIT);
        DevErrStatus = (uint8)E_NOT_OK;
    }
    
    if( Gpt_ChannelConfigIndex >=  (Gpt_ChannelType)GptChannel_MAX_ID )
    {
        /* @[SWS_Gpt_00216] If development error detection is enabled for GPT module:
            If the parameter Channel is invalid (not within the range specified by configuration)
            or channel wakeup is not enabled by configuration (GptEnableWakeup), the function
            Gpt_EnableWakeup shall raise the error GPT_E_PARAM_CHANNEL.  ( SRS_BSW_00406 )*/
        Gpt_ReportError( GPT_SERVICE_ID_ENABLE_WAKEUP, GPT_E_PARAM_CHANNEL);
        DevErrStatus = (uint8)E_NOT_OK;
    }
    
    if(DevErrStatus == E_OK)
    {
        if( ( pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChannelID != Gpt_ChannelNum ) || \
            ( pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptEnableWakeup != STD_ON ) )
        {
            /* @[SWS_Gpt_00216] If development error detection is enabled for GPT module:
                If the parameter Channel is invalid (not within the range specified by configuration)
                or channel wakeup is not enabled by configuration (GptEnableWakeup), the function
                Gpt_EnableWakeup shall raise the error GPT_E_PARAM_CHANNEL.  ( SRS_BSW_00406 )*/
            Gpt_ReportError( GPT_SERVICE_ID_ENABLE_WAKEUP, GPT_E_PARAM_CHANNEL);
            DevErrStatus = (uint8)E_NOT_OK;
        }
    }
    if (DevErrStatus == E_OK)
#endif
    {
        /* @[SWS_Gpt_00160] : The function Gpt_EnableWakeup shall enable the wakeup interrupt of the referenced 
            Channel configured for wakeup. The function shall save an attribute like "wakeup enabled" of the
            channel (SRS_Gpt_13602) */
            
        /* @[SWS_Gpt_00156] : The function Gpt_EnableWakeup shall be reentrant, if the timer Channels used in
            concurrent calls are different (SRS_Gpt_13602) */
        pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptEnableWakeup = STD_ON;
    }
    return;
}

/*========================================================================================================
 @Service name        Gpt_DisableWakeup
 @Description         Disables the wakeup interrupt of a channel (relevant in sleep mode).
 @param[in]           Channel Numeric identifier of the GPT channel.
 @param[out]          None
 @param[in, out]      None
 @return              Void
 @Pre                 None
 @Post                None
 @Requirements IDs    SWS_Gpt_00289
 @Design IDs          NA
 @service ID          0x0a
 @Sync/Async          Synchronous function
 @Reentrancy          Reentrant (but not for the same timer channel)
 @Note                All the other services used after Gpt_Init services is executed.
========================================================================================================*/
/* @[SWS_Gpt_00159] The function Gpt_DisableWakeup shall disable the wakeup
interrupt of the referenced channel configured for wakeup. The function shall save an
attribute like "wakeup disabled" of the channel.
Comment: This attribute affects the wakeup interrupt always when the driver is in
"sleep mode". In "normal mode" the attribute has no influence. (SRS_Gpt_13602)*/
GPT_TIMER_FUNC void Gpt_DisableWakeup ( Gpt_ChannelType Channel)
{
    Gpt_ModuleCoreDataType *pGpt_ModuleCoreData = &Gpt_ModuleRTData;
    Gpt_ChannelType Gpt_ChannelNum = 0U;
    Gpt_ChannelType Gpt_ChannelConfigIndex = 0U;
#if (GPT_DEV_ERROR_DETECT == STD_ON )
    uint8   DevErrStatus = (uint8)E_OK;
#endif

    Gpt_ChannelConfigIndex = (Gpt_ChannelType)((Channel >> GPT_CHAN_CFG_SHFT) & GPT_CHAN_CFG_MASK);
    Gpt_ChannelNum = (Gpt_ChannelType)(Channel & GPT_CHAN_CFG_MASK);

#if (GPT_DEV_ERROR_DETECT == STD_ON )
    if (pGpt_ModuleCoreData->GptDrvState == GPT_DRIVER_UNINITIALIZED )
    {
        /*  @[SWS_Gpt_00230] : If development error detection is enabled for GPT module:
        If the driver is not initialized, the function Gpt_DisableWakeup shall raise the
        error GPT_E_UNINIT.  (SRS_BSW_00406)*/
        Gpt_ReportError( GPT_SERVICE_ID_DISABLE_WAKEUP, GPT_E_UNINIT);
        DevErrStatus = (uint8)E_NOT_OK;
    }
    
    if( Gpt_ChannelConfigIndex >=  (Gpt_ChannelType)GptChannel_MAX_ID )
    {
         /* @[SWS_Gpt_00216] If development error detection is enabled for GPT module:
            If the parameter Channel is invalid (not within the range specified by configuration)
            or channel wakeup is not enabled by configuration (GptEnableWakeup), the function
            Gpt_DisableWakeup shall raise the error GPT_E_PARAM_CHANNEL.  ( SRS_BSW_00406 )*/
        Gpt_ReportError( GPT_SERVICE_ID_DISABLE_WAKEUP, GPT_E_PARAM_CHANNEL);
        DevErrStatus = (uint8)E_NOT_OK;
    }
    
    if(DevErrStatus == E_OK)
    {
        if( ( pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChannelID != Gpt_ChannelNum ) || \
            ( pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptEnableWakeup != STD_ON ) )
        {
            /* @[SWS_Gpt_00216] If development error detection is enabled for GPT module:
                If the parameter Channel is invalid (not within the range specified by configuration)
                or channel wakeup is not enabled by configuration (GptEnableWakeup), the function
                Gpt_DisableWakeup shall raise the error GPT_E_PARAM_CHANNEL.  ( SRS_BSW_00406 )*/
            Gpt_ReportError( GPT_SERVICE_ID_DISABLE_WAKEUP, GPT_E_PARAM_CHANNEL);
            DevErrStatus = (uint8)E_NOT_OK;
        }
    }
    if (DevErrStatus == E_OK)
#endif
    {
        /* @[SWS_Gpt_00160] : The function Gpt_DisableWakeup shall enable the wakeup interrupt of the referenced 
            Channel configured for wakeup. The function shall save an attribute like "wakeup enabled" of the
            channel (SRS_Gpt_13602) */
        /* @[SWS_Gpt_00155] : The function Gpt_DisableWakeup shall be reentrant, if the
            timer channels used in concurrent calls are different. (SRS_Gpt_13602) */
        pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptEnableWakeup = STD_OFF;
    }
    return;
}

/*========================================================================================================
 @Service name        Gpt_CheckWakeup
 @Description         Checks if a wakeup capable GPT channel is the source for a wakeup event and calls
                        the ECU state manager service EcuM_SetWakeupEvent in case of a valid GPT channel
                        wakeup event.
 @param[in]           WakeupSource : wakeup source to be checked.
 @param[out]          None
 @param[in, out]      None
 @return              void
 @Pre                 None
 @Post                None
 @Requirements IDs    SWS_Gpt_00328
 @Design IDs          NA
 @service ID          0x0c
 @Sync/Async          Synchronous function
 @Reentrancy          Reentrant (but not for the same timer channel).
 @Note                All the other services used after Gpt_Init services is executed.
========================================================================================================*/
GPT_TIMER_FUNC void Gpt_CheckWakeup( EcuM_WakeupSourceType WakeupSource )
{
    Gpt_ModuleCoreDataType *pGpt_ModuleCoreData = &Gpt_ModuleRTData;
    Gpt_ChannelType Gpt_ChannelConfigIndex = 0U;
#if (GPT_DEV_ERROR_DETECT == STD_ON )
    uint8   DevErrStatus = (uint8)E_OK;
    if (pGpt_ModuleCoreData->GptDrvState == GPT_DRIVER_UNINITIALIZED )
    {
        /*  @[SWS_Gpt_00325] : If development error detection is enabled for GPT module:
        If the driver is not initialized, the function Gpt_CheckWakeup shall raise the
        error GPT_E_UNINIT.  (SRS_BSW_00406)*/
        Gpt_ReportError( GPT_SERVICE_ID_CHECK_WAKEUP, GPT_E_UNINIT);
        DevErrStatus = (uint8)E_NOT_OK;
    }
    if (DevErrStatus == E_OK)
#endif
    { 
        /* @[SWS_Gpt_00321] : The function Gpt_CheckWakeup shall check if a wakeup capable
            GPT channel is th   e source for a wakeup event and call EcuM_SetWakeupEvent to
            indicate a valid timer wakeup event to the ECU State Manager [5] */       
        /* @[SWS_Gpt_00323] : The function Gpt_CheckWakeup shall be reentrant, if the timer Channels used in
            concurrent calls are different */
        for( Gpt_ChannelConfigIndex = 0U; \
            Gpt_ChannelConfigIndex < pGpt_ModuleCoreData->pGpt_ModuleConfig->GptDrvChannelMaxConfig; \
            Gpt_ChannelConfigIndex ++ )
        {
            if( pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChannelWakeupInfo == WakeupSource)
            {
               EcuM_SetWakeupEvent( WakeupSource ); 
            }
        }
    }
    return;
}
#endif /* GPT_WAKEUP_FUNCTIONALITY_API */
#endif /* GPT_REPORT_WAKEUP_SOURCE */
/*========================================================================================================
 @Service name        Gpt_GetPredefTimerValue
 @Description         Delivers the current value of the desired GPT Predef Timer.
 @param[in]           PredefTimer GPT Predef Timer
 @param[out]          TimeValuePtr Pointer to time value destination data in RAM
 @param[in, out]      None
 @return              Std_ReturnType E_OK: no error has been detected
                      E_NOT_OK: aborted due to errors
 @Pre                 None
 @Post                None
 @Requirements IDs    SWS_Gpt_00286
 @Design IDs          NA
 @service ID          0x0d
 @Sync/Async          Synchronous function
 @Reentrancy          Reentrant.
 @Note                All the other services used after Gpt_Init services is executed.
========================================================================================================*/
    /* @[SWS_Gpt_00397] : The function Gpt_GetPredefTimerValue shall be fully
    reentrant, this means even for the same GPT Predef Timer.  (SRS_Gpt_13608) */

GPT_TIMER_FUNC Std_ReturnType Gpt_GetPredefTimerValue ( Gpt_PredefTimerType PredefTimer, uint32* TimeValuePtr )
{
    Gpt_ModuleCoreDataType *pGpt_ModuleCoreData = &Gpt_ModuleRTData;
    uint64 Gpt_u64CurrentTicks = 0U;
    uint64 Gpt_u64Currentoffs = 0U;
    uint32 Gpt_u32PredefTimer = 0U;
#if(GPT_DEV_ERROR_DETECT == STD_ON )
    uint8   DevErrStatus = (uint8)E_OK;
    if (pGpt_ModuleCoreData->GptDrvState == GPT_DRIVER_UNINITIALIZED )
    {
        /*  @[SWS_Gpt_00398] ⌈If development error detection is enabled for GPT module: If the
            driver is not initialized, the function Gpt_GetPredefTimerValue shall raise the
            error GPT_E_UNINIT. ⌋ (SRS_BSW_00406)  */

        Gpt_ReportError( GPT_SERVICE_ID_GET_PREDEF_TIME_VALUE, GPT_E_UNINIT);
        DevErrStatus = (uint8)E_NOT_OK;
    }
    if ((PredefTimer < GPT_PREDEF_TIMER_1US_16BIT ) || (PredefTimer > GPT_PREDEF_TIMER_XUS_DISABLED))
    {
        /*  @[SWS_Gpt_00399] : If development error detection is enabled for GPT module: If the
            parameter PredefTimer is invalid, the function Gpt_GetPredefTimerValue
            shall raise the development error GPT_E_PARAM_PREDEF_TIMER. (SRS_BSW_00323)  */
        Gpt_ReportError( GPT_SERVICE_ID_GET_PREDEF_TIME_VALUE, GPT_E_PARAM_PREDEF_TIMER);
        DevErrStatus = (uint8)E_NOT_OK;
    }
    /* cfg check */ 
    Gpt_u32PredefTimer = (( (uint32)1 << (uint32)PredefTimer ) & pGpt_ModuleCoreData->GptPredefTimerEn );
    if ( Gpt_u32PredefTimer == STD_OFF )
    {
        /*  @[SWS_Gpt_00400] : If development error detection is enabled for GPT module: If the
            GPT Predef Timer passed by the parameter PredefTimer is not enabled, the
            function Gpt_GetPredefTimerValue shall raise the development error
            GPT_E_PARAM_PREDEF_TIMER.  ( )  */
        Gpt_ReportError( GPT_SERVICE_ID_GET_PREDEF_TIME_VALUE, GPT_E_PARAM_PREDEF_TIMER);
        DevErrStatus = (uint8)E_NOT_OK;
    }
    if(DevErrStatus == E_OK)
    {
        if( pGpt_ModuleCoreData->GptDrvMode == GPT_MODE_SLEEP )
        {

            /* @[SWS_Gpt_00401] : If the driver is in "sleep mode", the function
            Gpt_GetPredefTimerValue shall raise the runtime error GPT_E_MODE. ( )*/
            Gpt_ReportError( GPT_SERVICE_ID_GET_PREDEF_TIME_VALUE, GPT_E_MODE);
            DevErrStatus = (uint8)E_NOT_OK;
        }
    }
    /*input parameter is NULL check */
    if ((TimeValuePtr) == NULL_PTR)
    {

        /* @[SWS_Gpt_00403] : If development error detection is enabled for GPT module: If the
          parameter TimeValuePtr is a null pointer, the function
         Gpt_GetPredefTimerValue shall raise the error GPT_E_PARAM_POINTER.⌋
         (SRS_BSW_00369, SRS_BSW_00323)*/
        Gpt_ReportError( GPT_SERVICE_ID_GET_PREDEF_TIME_VALUE,GPT_E_PARAM_POINTER );
        DevErrStatus = (uint8)E_NOT_OK;
        /* Note:
        It is strongly recommended to check the return value of the function
        Gpt_GetPredefTimerValue on user software level. When E_NOT_OK is
        returned the time value - pointed by TimeValuePtr - may be invalid and must not
        be used. */
        return (uint8)E_NOT_OK;
    }

    if (DevErrStatus == E_OK)
#endif
    {	
        Gpt_u64CurrentTicks = GptPrv_GetCounterValue((const Gpt_ChannelType)PredefTimer, pGpt_ModuleCoreData->pGpt_ModuleConfig->GptPredefTimerHWType);
        Gpt_u64Currentoffs = GptPrv_GetTimeDifference( Gpt_u64CurrentTicks, pGpt_ModuleCoreData->GptPredefTimerTickvOffs );
        if(Gpt_u64CurrentTicks < pGpt_ModuleCoreData->GptPredefTimerTickvOffs)
        {
            Gpt_u64CurrentTicks = GptPrv_GetTimeDifference( pGpt_ModuleCoreData->GptPredefTimerTickMax, pGpt_ModuleCoreData->GptPredefTimerTickvOffs ); 
            Gpt_u64Currentoffs += Gpt_u64CurrentTicks; 
        }
        Gpt_u64Currentoffs = GptPrv_ConvertHwTicksToUSTicks( Gpt_u64Currentoffs, Gpt_GradeMap[PredefTimer].Gpt_ResScaler );
        *TimeValuePtr = (uint32)((uint64)Gpt_u64Currentoffs & Gpt_GradeMap[PredefTimer].Gpt_BitsValMax);
    }
    return E_OK;
}
#if(GPT_VERSION_INFO_API == STD_ON)
/*========================================================================================================
 @Service name        Gpt_GetVersionInfo
 @Description         Returns the version information of this module.
 @param[in]           None
 @param[out]          VersionInfoPtr : to where to store the version information of this module.
 @param[in, out]      None
 @return              Void
 @Pre                 None
 @Post                None
 @Requirements IDs    SWS_Gpt_00279
 @Design IDs          NA
 @service ID          0x00
 @Sync/Async          Synchronous function
 @Reentrancy          Reentrant
 @Note                All the other services used after Port_init services is executed.
========================================================================================================*/
GPT_TIMER_FUNC void Gpt_GetVersionInfo (Std_VersionInfoType* VersionInfoPtr )
{
    #if (GPT_DEV_ERROR_DETECT == STD_ON )
    uint8    u8PortDevErrStatus = E_OK;
    /*input parameter is NULL check */
    if (VersionInfoPtr == NULL_PTR)
    {
        /* @[SWS_Gpt_00338] : If development error detection is enabled for the GPT module:
        If the parameter VersionInfoPtr is a null pointer, the function
        Gpt_GetVersionInfo shall raise the error GPT_E_PARAM_POINTER. (SRS_BSW_00323)*/
        Gpt_ReportError( GPT_SERVICE_ID_GETVERSIONINFO, GPT_E_PARAM_POINTER);
        u8PortDevErrStatus = (uint8)E_NOT_OK;
    }
    else
    #endif /* (GPT_DEV_ERROR_DETECT == STD_ON ) */
    {
        VersionInfoPtr->vendorID         =  GPT_VENDOR_ID;
        VersionInfoPtr->moduleID         =  GPT_MODULE_ID;
        VersionInfoPtr->sw_major_version =  GPT_SW_MAJOR_VERSION;
        VersionInfoPtr->sw_minor_version =  GPT_SW_MINOR_VERSION;
        VersionInfoPtr->sw_patch_version =  GPT_SW_PATCH_VERSION;
    }
}
#endif /* (GPT_VERSION_INFO_API == STD_ON) */

/*========================================================================================================
 @Service name        Gpt_GetCntFreeRunning
 @Description         Returns free running counter value of selected timer channel.
 @param[in]           Channel - Timer logical Symbolic Identifier 
 @param[out]          None
 @param[in, out]      None
 @return              free running counter value of selected timer channel 
 @Pre                 None
 @Post                None
 @Requirements IDs    None, custom API to maintain legacy interface
 @Design IDs          NA
 @service ID          0x0F
 @Sync/Async          Synchronous function
 @Reentrancy          Reentrant
 @Note                -
========================================================================================================*/
GPT_TIMER_FUNC Gpt_ValueType Gpt_GetCntFreeRunning( const Gpt_ChannelType Channel )
{
	Gpt_ModuleCoreDataType *pGpt_ModuleCoreData = &Gpt_ModuleRTData;
    Gpt_ValueType Gpt_u64ResultTime = 0U;
    Gpt_ValueType Gpt_u64CurrentTicks = 0U;
    Gpt_ChannelType Gpt_ChannelNum = 0U;
    Gpt_ChannelType Gpt_ChannelConfigIndex = 0U;
#if (GPT_DEV_ERROR_DETECT == STD_ON )
    uint8   DevErrStatus = (uint8)E_OK;
#endif

    Gpt_ChannelConfigIndex = (Gpt_ChannelType)((Channel >> GPT_CHAN_CFG_SHFT ) & GPT_CHAN_CFG_MASK);
    Gpt_ChannelNum = (Gpt_ChannelType)(Channel & GPT_CHAN_CFG_MASK);

#if (GPT_DEV_ERROR_DETECT == STD_ON )

    if (pGpt_ModuleCoreData->GptDrvState == GPT_DRIVER_UNINITIALIZED )
    {
        /* @[SWS_Gpt_00223] : If development error detection is enabled for GPT module:
        If the driver is not initialized, the function Gpt_GetCntFreeRunning shall raise the
        error GPT_E_UNINIT. (SRS_BSW_00406)*/
        Gpt_ReportError( GPT_SERVICE_ID_GET_CNT_FREERUN, GPT_E_UNINIT);
        DevErrStatus = (uint8)E_NOT_OK;
    }
    
    if( Gpt_ChannelConfigIndex >=  (Gpt_ChannelType)GptChannel_MAX_ID )
    {
        /* @[SWS_Gpt_00211] : If development error detection is enabled for GPT module:
        If the parameter Channel is invalid (not within the range specified by configuration),
        the function Gpt_GetCntFreeRunning shall raise the error
        GPT_E_PARAM_CHANNEL.*/
        Gpt_ReportError( GPT_SERVICE_ID_GET_CNT_FREERUN, GPT_E_PARAM_CHANNEL);
        DevErrStatus = (uint8)E_NOT_OK;
    }
    
    if(DevErrStatus == E_OK)
    {
        if( pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChannelID != Gpt_ChannelNum )
        {
            /* @[SWS_Gpt_00211] : If development error detection is enabled for GPT module:
            If the parameter Channel is invalid (not within the range specified by configuration),
            the function Gpt_GetCntFreeRunning shall raise the error
            GPT_E_PARAM_CHANNEL.*/
               Gpt_ReportError( GPT_SERVICE_ID_GET_CNT_FREERUN, GPT_E_PARAM_CHANNEL);
               DevErrStatus = (uint8)E_NOT_OK;
        }
    }
    if (DevErrStatus == E_OK)
#endif
    {
        /* The Free Run counter read shall be available immediately after GPT initialization,
			as per custom requirements, regardless of when GPT_Init is invoked.
			It is important to note that Gpt_GetPredefTimerValue() calculates the timer
			value based on the offset since Power-On Reset (POR). However,
			this API does not support starting the count from zero, which
			is necessary for compatibility with legacy interfaces. Instead,
			it performs a direct read of the counter and applies the configured
			channel resolution */
        Gpt_u64CurrentTicks = GptPrv_GetCounterValue((const Gpt_ChannelType) Gpt_ChannelNum, \
                (const Gpt_ChanHWType) pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChanHW );
        /* to support legacy compatibility only apply resolution of channel, no masking with chan max rolloff setting */                                             
        Gpt_u64ResultTime =  GptPrv_GetSWChanTicks( Gpt_u64CurrentTicks, \
                                    pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChannelTickFrequency );
    }
    return Gpt_u64ResultTime;
}
/*==============================================================================
**                                  EOF                                       **
==============================================================================*/
