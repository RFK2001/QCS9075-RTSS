/*
===========================================================================
*/
/**
    @file  isd_resets.c
    @brief This file implements the resets handling from ISD

*/
/*
    ===========================================================================

    Copyright (c) 2021-2022 Qualcomm Technologies, Inc.
    All Rights Reserved.
    Confidential and Proprietary - Qualcomm Technologies, Inc.

    Export of this technology or software is regulated by the U.S. Government.
    Diversion contrary to U.S. law prohibited.

    All ideas, data and information contained in or disclosed by
    this document are confidential and proprietary information of
    Qualcomm Technologies, Inc. and all rights therein are expressly reserved.
    By accepting this material the recipient agrees that this material
    and the information contained therein are held in confidence and in
    trust and will not be used, copied, reproduced in whole or in part,
    nor its contents revealed in any manner to others without the express
    written permission of Qualcomm Technologies, Inc.

    ===========================================================================

    $Header:   $
    $DateTime:  $
    $Author:   $

    ===========================================================================
*/

#include "isd_drv.h"
#include "isd_resets.h"
#include "pmicapi.h"
#include "chipinfo.h"
#include "HALhwio.h"
#include "sail_csr_hwio.h"
#include "debug_log.h"
#include "Crashdbg_api.h"
#include "mailboxExt_api.h"
#include "logcode.h"
#include "freertos_init.h"
#include "isd.h"
#include "sleepSafeRtos.h"
#include "busywait.h"
#include "isd_cfg.h"
#include "commonClient.h"
#include "FreeRTOSOsal.h"
#include "interrupts.h"
#include <timetick.h>

extern QueueHandle_t xSleepQueueHandle;

/* ToDo - MD Interrupt reason from shadow register to be passed from ISD Interrupt context to Task Context */

  #define WR_SAIL_ISLAND           0xCD050000UL
  #define AUTH_FAIL_SWITCH_LUN_HR  0xCC020000UL
  #define FAILURE_FORCE_PASS2      0xCC040000UL
  #define RESET_READY              0xCC050000UL
  #define FORCE_EDL                0xCC030000UL 
  #define SW_MD_CR                 0xCD010000UL


/* Shadow register value reserved for HLOS boot success, though not used in HLOS Image and stISDSailMDStatus table below.
This is needed to detect any non-zero lower half word value as HLOS failures */
#define HLOS_BOOT_SUCCESS             0xD0010000UL 

/* Task delay to update MD boot error code from Log code memory to VIP via UART(based on periodic ping). 
   ACK to MD will be delayed for 50ms for applicable MD boot failures */
#define DELAY_ACK2MDBOOTFAIL   50U

static const ISD_IntrConfigType stISDSailMDStatus[] = {
                                                            { MD_SEC_FUSE_HR              , 0xCD000000u },
                                                            { MD_SW_CR                    , 0xCD010000u },
                                                            { MD_VSENSE_STATUS            , 0xCD020001u },
                                                            { MD_SOC_WR                   , 0xCD030000u },
                                                            { MD_WR_SAIL_ISLAND           , 0xCD050000u },
                                                            { MD_DDR_READY                , 0xCC010000u },
                                                            { MD_AUTH_FAIL_SWITCH_LUN_HR  , 0xCC020000u },
                                                            { MD_FORCE_EDL                , 0xCC030000u },
                                                            { MD_FAILURE_FORCE_PASS2      , 0xCC040000u },
                                                            { MD_RESET_READY              , 0xCC050000u },
                                                            { MD_GRACEFUL_SHUTDOWN        , 0xCD060000u },
                                                            { XBLSEC_BOOT_SUCCESS         , 0xCB000001u },
                                                            { XBLLDR_BOOT_SUCCESS         , 0xCB000003u },
                                                            { TZ_BOOT_SUCCESS             , 0xCB000007u },
                                                            { QHEE_BOOT_SUCCESS           , 0xCB00000Fu },
                                                            { UEFI_BOOT_SUCCESS           , 0xCB00001Fu },
                                                            { ABL_BOOT_SUCCESS            , 0xCB00003Fu },
                                                            { MD_SOC_HR                   , 0xCD070000u },
                                                            { MD_SAIL_LPM_DDR_SUSPEND 	  , 0xD0030000u },
                                                            { MD_S1_READY           	  , 0xD0000000u },
                                                            { MD_MB_READY           	  , 0xD0020000u },
                                                            { SAIL_SEC_FUSE_HR            , 0xAA010000u },
                                                            { SAIL_VSENSE_READY           , 0xAA020000u },
                                                            { SAIL_RESET_READY            , 0xAA030000u },
                                                            { SAIL_RGMII_VOL_SEL          , 0xAA040000u },
                                                            { SAIL_SW_CR                  , 0xAA050000u },
                                                            { SAIL_TEST_MANAGER_MODE      , 0xAA060000u },
                                                            { SAIL_ISLAND_READY           , 0xAA070000u },
                                                            { SAIL_OSPI_MD_CTRL           , 0xAA080000u },
                                                            { SAIL_SDI_DISABLED           , 0xAA0C0000u },
                                                            { MD_SOC_SDI_DISABLE          , 0xCD0A0000u },
                                                            { SAIL_QAMV4_DETECTION        , 0xCC070000u },
                                                            /*
                                                             * Note : Add Any entry above this
                                                             * Issue Description :- On warm/ cold boot path ISD driver will populated missed
                                                             * Shadow register config from MD. On warm boot path shadow register config will
                                                             * be populated to STR and ISD API will fill up Sleep queue with STR information
                                                             * as last shadow register config was STR and SAIL will enter into sleep again.
                                                             * To avoid such cases STR/Deep Sleep ENUM is expected to have highest value in
                                                             * ISD_SailMDStatusType
                                                             */
                                                            { STR_COMM_TO_SAIL            , 0xCD080000u },
                                                            { MD_SOC_DEEP_SLEEP           , 0xCD090000u },
                                                        };

#define ARRAY_SIZE(x)      (sizeof((x))/sizeof((x)[0]))

/*===========================================================================
**  Function :  prvISDGetMDStatus
** ==========================================================================
*/
/*!
*
* @brief
*   This functions reads the shadow registers and returns the value as a uint32
*
* @param
*   void
* @par Dependencies
*   None
* @retval
*   uint32          : MD shadow register value
*
*/
ISD_FUNC static uint32 prvISDGetMDStatus(void)
{
    uint32 nReturnValue = 0u;

    nReturnValue = ( HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS4_REG_IN & 0xFFu );
    nReturnValue |= (( HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS5_REG_IN & 0xFFu ) << 8u );
    nReturnValue |= (( HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS6_REG_IN & 0xFFu ) << 16u );
    nReturnValue |= (( HWIO_SAILSS_CSR_MAIN2SAIL_GP_NONSEC_STATUS7_REG_IN & 0xFFu ) << 24u );

    return nReturnValue;
}

/*===========================================================================
**  Function :  vISDSetSAILMDAck
** ==========================================================================
*/
/*!
*
* @brief
*   This functions updates the shadow registers with value from a uint32
*
* @param
*   nStatus         : Value to be written to the 4 shadow registers
* @par Dependencies
*   None
* @retval
*   None
*
*/
ISD_FUNC void vISDSetSAILMDAck(uint32 nStatus)
{
    HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS4_REG_OUT( nStatus & 0x000000FFu );
    HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS5_REG_OUT((( nStatus & 0x0000FF00u ) >> 8u ));
    HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS6_REG_OUT((( nStatus & 0x00FF0000u ) >> 16u ));
    HWIO_SAILSS_CSR_SAIL2MAIN_GP_NONSEC_SHADOW_STATUS7_REG_OUT((( nStatus & 0xFF000000u ) >> 24u ));
    DEBUG_LOG(SAIL_WARNING, "Ack to MD : 0x%X\r\n", nStatus);
}

/*!
*
* @brief vISDUpdatePendingISDStatus
*   This functions updates lastest ISD status captured in sail bootup path 
*   by SAIL Master core 0
*
* @param None
* @par  API should be called before RTOS shcedular init to capture pending
        event status.
*   None
* @retval
*   None
*
*/
ISD_FUNC void vISDUpdatePendingEventStatus( void )
{
	ISD_DriverContext_t *pISDDriverContext = ISD_CONTEXT_BASE_ADDRESS_COPY;
	uint32 nReturnValue = prvISDGetMDStatus();
	ISD_SailMDStatusType nIntrReason = ISD_TaskStatesMAX;
	 /* Find pending event */
    for( uint32 ulEvCnt = (uint32)MD_SEC_FUSE_HR; ulEvCnt < ARRAY_SIZE(stISDSailMDStatus); ulEvCnt++)
    {
        if( stISDSailMDStatus[ulEvCnt].value == nReturnValue)
        {
            /* event reason is found */
            nIntrReason = stISDSailMDStatus[ulEvCnt].eIntrReason;
            break;
        }
    }

    if ( nIntrReason >= STR_COMM_TO_SAIL )
    {
        /*
         * In Case shadow register is update to STR (Suspend to RAM) or
         * Deep sleep then don't call INTR handler otherwise ISD will 
         * initiate another sleep/deep request
         */

    }else
    {
        DEBUG_LOG(SAIL_WARNING, "Rx MD ISD event capture : 0x%X\r\n", nReturnValue);
        prvISD_MDIntrHandler(&pISDDriverContext, nIntrReason);
    }
	return;
}



/*===========================================================================
**  Function :  prvIPCNonSecISR_CB
** ==========================================================================
*/
/*!
*
* @brief
*   ISR for non secure interrupt from MD boot stages
*
* @param
*   void
* @par Dependencies
*   None
* @retval
*   None
*
*/
ISD_FUNC void prvIPCNonSecISR_CB(void *args)
{
    ISD_DriverContext_t *pContxt = (ISD_DriverContext_t *) args;
    uint32_t ui32LoopCounter = 0;
    ISD_SailMDStatusType nIntrReason = ISD_TaskStatesMAX;
    uint32 nStatus = 0;

    /* Get MD boot stages status via shadow register */
    nStatus = prvISDGetMDStatus();
    /* Find interrupt reason*/
    for(ui32LoopCounter = (uint32)MD_SEC_FUSE_HR; ui32LoopCounter < ARRAY_SIZE(stISDSailMDStatus); ui32LoopCounter++)
    {
        if( stISDSailMDStatus[ui32LoopCounter].value == nStatus)
        {
            /* Interrupt reason is found */
            nIntrReason = stISDSailMDStatus[ui32LoopCounter].eIntrReason;
            break;
        }
    }
    DEBUG_LOG(SAIL_WARNING, "Rx MD Interrupt : 0x%X\r\n", nStatus);

    /* Call the error handler API*/
    prvISD_MDIntrHandler(&pContxt, nIntrReason);
}

ISD_FUNC void prvIPCNonSecISR(void *args)
{


    prvIPCNonSecISR_CB(args);


}

/*===========================================================================
**  Function :  prvTZIPCSecISR_CB
** ==========================================================================
*/
/*!
*
* @brief
*   ISR for TZ secure interrupt
*
* @param
*   void
* @par Dependencies
*   None
* @retval
*   None
*
*/
ISD_FUNC void prvTZIPCSecISR_CB(void *args)
{
    ISD_DriverContext_t *pContxt = (ISD_DriverContext_t *) args;
    uint32_t i = 0;
    ISD_SailMDStatusType nResetReason = ISD_TaskStatesMAX;
    uint32 nStatus = 0;

    nStatus = prvISDGetMDStatus();
    /* Find interrupt reason*/
    for(i = (uint32)MD_SEC_FUSE_HR; i < ARRAY_SIZE(stISDSailMDStatus); i++)
    {
        if( stISDSailMDStatus[i].value == nStatus)
        {
            /* Interrupt reason is found */
            nResetReason = stISDSailMDStatus[i].eIntrReason;
            break;
        }
    }

    DEBUG_LOG(SAIL_WARNING, " Rx MD TZ Interrupt: 0x%X\r\n", nStatus);
    prvISD_MDIntrHandler(&pContxt, nResetReason);
}

ISD_FUNC void prvTZIPCSecISR(void *args)
{


    prvTZIPCSecISR_CB(args);


}

/*===========================================================================
**  Function :  eISDGetMDIntrReason
** ==========================================================================
*/
/*!
*
* @brief
*   This function returns the MD Interrupt reset reason.
* @param
*   None
* @par Dependencies
*   None
* @retval
*   ISD_SailMDStatusType
*
*/
ISD_FUNC uint32_t eISDGetMDIntrReason(void)
{
    ISD_DriverContext_t *pISDDriverContext = ISD_CONTEXT_BASE_ADDRESS_COPY;
    return pISDDriverContext->MD_IntrReason;
}

/*===========================================================================
**  Function :  prvISD_ISDStateHandler
** ==========================================================================
*/
/*!
*
* @brief
*   This functions handles the IPC interrupt by doing one/more of following:
*               1. Sending ACK to MD
*               2. Enabling Isoaltions
*               3. Configuring to PMIC to Warm Reset
*               4. De-assert SAIL_PS_HOLD
*
* @param
*   state       : new state of SAIL 
* @par Dependencies
*   None
* @retval
*   None
*
*/
ISD_FUNC void prvISD_ISDStateHandler(ISD_DriverContext_t *pContxt, isdStatesType_e state)
{
    ISD_UNUSED_PARAMETER(pContxt);
    uint32_t MD_IntrReason = 0u;
     /*
    *   TODO with EL1
    *   Move this handling to the task context with SafeRTOS.
    *   It is placed here for el2 beacuse Isolations shall be
    *   after notifying the client. The client notifications 
    *   are sent in IPCC interrupt handler. Since nested interrupts
    *   are not enabled now, notifications will be sent after
    *   enabling isolations, same in case of SAIL_PS_HOLD de-assertion
    *   as well
    */
    MD_IntrReason = prvISDGetMDStatus();

    switch(state)
    {
        case ISLAND_STATE:
#ifdef ISLAND_ENABLE
            /* TODO: call SAIL de-init API */
            /* ACK to MD only when MD triggers direct interrupt to SAIL about any MD error/crash */
            /* In case of SAIL isolation via FUSA, ACK to MD must be skipped. */
            if ( (MD_IntrReason == AUTH_FAIL_SWITCH_LUN_HR) ||
                     (MD_IntrReason == FAILURE_FORCE_PASS2) ||
                     (MD_IntrReason == WR_SAIL_ISLAND) ||
                     (MD_IntrReason == RESET_READY)
                   )
            {
                if(CHIPINFO_ID_SA_LEMANSAU_IVI == ChipInfo_GetChipId())
                {
                    /* Indicate sail is RESET_READY to MD*/
                    vISDSetSAILMDAck(stISDSailMDStatus[SAIL_RESET_READY].value);
                } else
                {
                    /* Indicate sail is ISLAND_READY to MD*/
                    vISDSetSAILMDAck(stISDSailMDStatus[SAIL_ISLAND_READY].value);
                }
            }
            eISDEnableIsolations();
            DEBUG_LOG(SAIL_WARNING, "SAIL in island mode \r\n");
#else
            /* PMIC configuration will be the default one, set for mission/production mode. */
            /* ACK to MD only when MD triggers direct interrupt to SAIL about any MD error/crash */
            /* In case of SAIL isolation via FUSA, ACK to MD must be skipped. */
            if (MD_IntrReason == SW_MD_CR)
            {
                vISDSetSAILMDAck(stISDSailMDStatus[SAIL_RESET_READY].value);
            }
#endif
            break;

        case SOC_SHUTDOWN:
        {
            pmicErrFlagType_e eReturnValue;
            /* 
                MD has requested for SOC Shutdown. Indicate SAIL reset ready and program PMIC for shutdown 
                and pull SAIL_PS_HOLD low. For dependent PMIC also de-init all the drivers 
            */
            /* TODO: call SAIL de-init API */
            /* Configure PMIC for shutdown and then ack MD. Platform(IVI or ADAS) check is done within PMIC API */
            eReturnValue = xPmicSetResetState(PMIC_POFF);
            if(PMIC_ERR_FLAG_SUCCESS == eReturnValue )
            {
                vISDSetSAILMDAck(stISDSailMDStatus[SAIL_RESET_READY].value);
            }
        }
            break;
        
        case SOC_WARM_RESET:
        {
            pmicErrFlagType_e eReturnValue;
            /* 
                MD has requested for SOC Warm Reset. Indicate SAIL reset ready and program PMIC for warm reset 
                and pull SAIL_PS_HOLD low. For dependent PMIC also de-init all the drivers 
            */
            /* Configure PMIC for shutdown and then ack MD. Platform(IVI or ADAS) check is done within PMIC API */
             eReturnValue = xPmicSetResetState(PMIC_WARM_RESET);
             if(PMIC_ERR_FLAG_SUCCESS == eReturnValue )
             {
                if(MD_IntrReason == FORCE_EDL)
                {
                    /* 50ms Task delay to update MD boot error code from Log code memory to VIP via UART(periodic ping)*/                    
                    (void)vFreeRTOSTaskDelay(pdMS_TO_TICKS(DELAY_ACK2MDBOOTFAIL));
                    vISDSetSAILMDAck(stISDSailMDStatus[SAIL_RESET_READY].value);
                }
                /* SAIL shall reset with MD during a)MD XBL direct ramdump, and
                b)MD warm reset island request
                To support island enable/disable requirement within SAIL Image, SAIL must ACK with Island ready to avoid ACK timeout on MD. */
                else if (MD_IntrReason == FAILURE_FORCE_PASS2)
                {
                    /* 50ms Task delay to update MD boot error code from Log code memory to VIP via UART(periodic ping)*/                    
                    (void)vFreeRTOSTaskDelay(pdMS_TO_TICKS(DELAY_ACK2MDBOOTFAIL));
                    vISDSetSAILMDAck(stISDSailMDStatus[SAIL_ISLAND_READY].value);
                }
                else if (MD_IntrReason == WR_SAIL_ISLAND)
                {
                    vISDSetSAILMDAck(stISDSailMDStatus[SAIL_ISLAND_READY].value);
                }
                else
                {
                    vISDSetSAILMDAck(stISDSailMDStatus[SAIL_RESET_READY].value);
                }
             }  
        }
            break;


        case SOC_CRASH_RESET:
            /* 
                MD known crash. Indicate SAIL reset ready to enter concurrent crash reset.
            */
            /* TODO: call SAIL de-init API */

            vISDSetSAILMDAck(stISDSailMDStatus[SAIL_RESET_READY].value);
            break;

        case SOC_HARD_RESET:
        {
            pmicErrFlagType_e eReturnValue;
            /* 
                MD has requested for SOC Hard Reset. Indicate SAIL reset ready and program PMIC for hard reset
                and pull SAIL_PS_HOLD low. For dependent PMIC, de-init all the drivers.
            */          
            eReturnValue = xPmicSetResetState(PMIC_POFF_PON);
        
            if(PMIC_ERR_FLAG_SUCCESS == eReturnValue )
            {
            #ifdef ISLAND_ENABLE
                vISDSetSAILMDAck(stISDSailMDStatus[SAIL_RESET_READY].value);
                /* The below code is to overwrite SAIL ACK for below use cases */
            #else
                /* SAIL shall reset with MD during a) MD LUN switch hard reset,
                b) MD XBL direct ramdump - hard reset after dump collection and c)MD HLOS - hard reset request from MD log console.
                To support island enable/disable requirement within SAIL, SAIL must ACK with Island ready to avoid ACK timeout on MD. */
                if (MD_IntrReason == AUTH_FAIL_SWITCH_LUN_HR)
                {
                    /* 50ms Task delay to update MD boot error code from Log code memory to VIP via UART(periodic ping)*/                    
                    (void)vFreeRTOSTaskDelay(pdMS_TO_TICKS(DELAY_ACK2MDBOOTFAIL));
                    vISDSetSAILMDAck(stISDSailMDStatus[SAIL_ISLAND_READY].value);
                }
                else if (MD_IntrReason == RESET_READY)
                {
                    vISDSetSAILMDAck(stISDSailMDStatus[SAIL_ISLAND_READY].value);
                }
                else
                {
                    /* 50ms Task delay to update MD boot error code from Log code memory to VIP via UART(periodic ping), if applicable */                    
                    /* Within this delay time, all SAIL ISD clients will abort any transactions with MD(DDR,MB,MD register space).
                    NOTE - IPCC to SAIL secondary cores will be sent first and finally to self-core0 to wait for this 50ms delay */
                    (void)vFreeRTOSTaskDelay(pdMS_TO_TICKS(DELAY_ACK2MDBOOTFAIL));
                    vISDSetSAILMDAck(stISDSailMDStatus[SAIL_RESET_READY].value);
                }
            #endif	
            }
            
	   
            /* MD_PS_HOLD will be de-asserted after this ACK. MD_PS_HOLD Neg edge ISR will be executed
               where we will check for this SOC_HARD_RESET case and then de-assert SAIL_PS_HOLD,
               so that both MD and SAIL will go through hard reset */
            break;
        }
        default:
        // default switch case
        break;
    }
}

/*===========================================================================
**  Function :  prvISD_MDIntrHandler
** ==========================================================================
*/
/*!
*
* @brief
*   This functions handles the MD interrupt by doing one/more of following:
*               1. Updates SAIL context var with the new state
*               2. Sends IPCC Interrupts to all core to notify the registered 
*                  clients
*
* @param
*   pISDContext       : ISD Context variable
*   nResetReason      : Status of MD as read from Shadow registers
* @par Dependencies
*   None
* @retval
*   None
*
*/
ISD_FUNC void prvISD_MDIntrHandler(ISD_DriverContext_t **pISDContext, ISD_SailMDStatusType nResetReason)
{
    int32_t idx = 0;
    uint8 xMsg[8u];
    ISD_DriverContext_t *pContext = *pISDContext;
    BaseType_t    xQSendStatus = pdFAIL;
    uint32 err_code = 0u;
    pContext->MD_IntrReason = (uint32_t)nResetReason;
    uint32 uACStatus = 0U;

    switch(nResetReason)
    {
        case MD_GRACEFUL_SHUTDOWN:
        {
            pmicErrFlagType_e eReturnValue;
            eReturnValue = xPmicConfigureEnableDrvPin((boolean)PMIC_DISABLE);
            if(PMIC_ERR_FLAG_SUCCESS == eReturnValue)
            {
                /* Set Current State and also notify the registered drivers */
                pContext->isdState = SOC_SHUTDOWN;
                /* Disable SAIL SDI or crash reset flow by,
                   a) clearing SAIL crash reset debug enablement register and
                   b) set "MD_PS_HOLD_MASK" as 0xFFFF */
                if(Crashdbg_disable(CRASHDBG_DISABLED) != DBG_DISABLED)
                {
                  DEBUG_LOG(SAIL_ERROR, "Crash debug disable failed \r\n");
                }
                (void)prvISDSendIPCCInterrupt(); 
            }

        }
        break;

        case MD_AUTH_FAIL_SWITCH_LUN_HR:
        case MD_FAILURE_FORCE_PASS2:
        case MD_WR_SAIL_ISLAND:
        case MD_RESET_READY: //To isolate SAIL during MD PASS2 hard reset(actual MD crash or direct PASS2 entry from MD XBL_LDR)
            if ( (nResetReason == MD_AUTH_FAIL_SWITCH_LUN_HR) ||
                 (nResetReason == MD_FAILURE_FORCE_PASS2) )
            {
              //Update "MD XBL boot failures due to LUN switch and direct PASS2",into Logcode memory
              err_code = eISD_GetMDBootErrorCode();
              DEBUG_LOG(SAIL_WARNING, "MD ErrCode:0x%x \r\n",err_code);            
              (void)vLcWriteLogCode(MD_BOOT_MILESTONES,FAIL,&err_code,1u);	
            }
#ifdef ISLAND_ENABLE
            /* Set Current State and also notify the registered drivers */
            pContext->isdState = ISLAND_STATE;
            pContext->eISDStatus = ISD_MD2SAIL_STATUS_FAILED;//DDR_NOT_READY;
            /* In these use cases, MD will go through reset when SAIL is isolated.
            Hence, mask SAIL to follow MD_PS_HOLD enabled by crash debug feature,
            to avoid SAIL reset */
            if(Crashdbg_disable(DEP_CRASH_DISABLED) != DBG_DISABLED)
            {

                DEBUG_LOG(SAIL_ERROR, "Mask SAIL follow MD_PS_HOLD failed \r\n");
            }
            (void)prvISDSendIPCCInterrupt();
#else
            /* Set Current State and also notify the registered drivers 
            that it's not a fatal error               */
            if ( (nResetReason == MD_FAILURE_FORCE_PASS2) ||
                 (nResetReason == MD_WR_SAIL_ISLAND) )
            {
              pContext->isdState = SOC_WARM_RESET;
            }
            else
            {
              pContext->isdState = SOC_HARD_RESET;
            }
            /* When MD hard resets via fastboot reboot/qnx reset commands or post MD secure fuse blown,
            allow SAIL to go through hard reset but not crash reset flow.
            Hence, crash debug feature must be disabled to avoid entering crash reset flow upon md_ps_hold low */
            if(Crashdbg_disable(CRASHDBG_DISABLED) != DBG_DISABLED)
            {

                DEBUG_LOG(SAIL_ERROR, "Crash debug disable failed \r\n");
            }
            (void)prvISDSendIPCCInterrupt();	
#endif
        break;

        case MD_FORCE_EDL:
        case MD_SOC_WR:
            if(nResetReason == MD_FORCE_EDL)
            {
              //Update "MD FORCE EDL" due to Recovery LUN failure,into Logcode memory
              err_code = eISD_GetMDBootErrorCode();
              DEBUG_LOG(SAIL_WARNING, "MD ErrCode:0x%x \r\n",err_code);
              (void)vLcWriteLogCode(MD_BOOT_MILESTONES,FAIL,&err_code,1u);	
            }
            /* Set Current State and also notify the registered drivers */
            pContext->isdState = SOC_WARM_RESET;
            /* When MD warm resets via adb commands or to enter EDL mode,
            allow SAIL to go through warm reset but not crash reset flow.
            Hence, crash debug feature must be disabled to avoid entering crash reset flow upon md_ps_hold low */
            if(Crashdbg_disable(CRASHDBG_DISABLED) != DBG_DISABLED)
            {

                DEBUG_LOG(SAIL_ERROR, "Crash debug disable failed \r\n");
            }
            (void)prvISDSendIPCCInterrupt();

        break;

        case MD_DDR_READY:
        {
            uint32_t log_data = (uint32_t)LC_MD_DDR_READY;

            pContext->eISDStatus = DDR_READY;
            DEBUG_LOG(SAIL_WARNING, "DDR READY \r\n");
            (void)vLcWriteLogCode(MD_BOOT_MILESTONES,PASS,&log_data,1u);
        }

        break;

        case XBLSEC_BOOT_SUCCESS:
        {
            uint32_t log_data = (uint32_t)LC_MD_XBLSEC_BOOT;

            pContext->eISDStatus = XBL_SEC_BOOT_SECCESS;
            DEBUG_LOG(SAIL_WARNING, "XBL_SEC BOOT SUCCESS \r\n");
            (void)vLcWriteLogCode(MD_BOOT_MILESTONES,PASS,&log_data,1u);
        }
        break;
        case STR_COMM_TO_SAIL:
        {
            DEBUG_LOG(SAIL_WARNING, "STR_COMM_TO_SAIL SUCCESS \r\n");
            xMsg[0] = SLEEP_PREP_REQUEST_INTERNAL;
            xMsg[1] = STR_SLEEP_REQ;
            if ( xSleepQueueHandle != NULL )
            {
                xQSendStatus = xFreeRTOSQueueSendFromISR( xSleepQueueHandle, &xMsg[0]);
                if (pdPASS == xQSendStatus )
                {
                    freertosYIELD_FROM_ISR();
                }
            }
        }

        break;

        case MD_SOC_DEEP_SLEEP:
        {
            DEBUG_LOG(SAIL_WARNING, "MD_SOC_DEEP_SLEEP SUCCESS \r\n");
            xMsg[0] = SLEEP_PREP_REQUEST_INTERNAL;
            xMsg[1] = DEEP_SLEEP_REQ;
            pContext->isdState = SOC_DEEP_SLEEP;
            if ( xSleepQueueHandle != NULL )
            {
                xQSendStatus = xFreeRTOSQueueSendFromISR( xSleepQueueHandle, &xMsg[0]);
                if (pdPASS == xQSendStatus )
                {
                    freertosYIELD_FROM_ISR();
                }
            }
        }

        break;

        case XBLLDR_BOOT_SUCCESS:
        {
            uint32_t log_data = (uint32_t)LC_MD_XBLLDR_BOOT;

            pContext->eISDStatus = XBL_LOADER_BOOT_SUCCESS;
            DEBUG_LOG(SAIL_WARNING, "XBL_LDR BOOT SUCCESS \r\n");
            (void)vLcWriteLogCode(MD_BOOT_MILESTONES,PASS,&log_data,1u);
        }

        break;

        case TZ_BOOT_SUCCESS:
        {
            uint32_t log_data = (uint32_t)LC_MD_TZ_BOOT;

            pContext->eISDStatus  = TZ_SUCCESS;
            DEBUG_LOG(SAIL_WARNING, "TZ BOOT SUCCESS \r\n");
            vLCWriteTimeStamp( SAIL_TZ_READY ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );
            (void)vLcWriteLogCode(MD_BOOT_MILESTONES,PASS,&log_data,1u);
        }

        break;

        case QHEE_BOOT_SUCCESS:
        {
            uint32_t log_data = (uint32_t)LC_MD_QHEE_BOOT;
            pContext->eISDStatus  = QHEE_SUCCESS;
            DEBUG_LOG(SAIL_WARNING, "QHEE BOOT SUCCESS \r\n");
            (void)vLcWriteLogCode(MD_BOOT_MILESTONES,PASS,&log_data,1u);
			/* for ES4 , later need to remove */
			//vMailboxEBAppPowerOnInit( 2U );
        }

        break;

        case UEFI_BOOT_SUCCESS:
        {
            uint32_t log_data = (uint32_t)LC_MD_UEFI_BOOT;

            pContext->eISDStatus  = UEFI_SUCCESS; 
            DEBUG_LOG(SAIL_WARNING, "UEFI BOOT SUCCESS \r\n");
            (void)vLcWriteLogCode(MD_BOOT_MILESTONES,PASS,&log_data,1u);
        }

        break;

        case ABL_BOOT_SUCCESS:
        {
            uint32_t log_data = (uint32_t)LC_MD_ABL_BOOT;

            pContext->eISDStatus  = ABL_SUCCESS; 
            DEBUG_LOG(SAIL_WARNING, "ABL BOOT SUCCESS \r\n");
            (void)vLcWriteLogCode(MD_BOOT_MILESTONES,PASS,&log_data,1u);
        }
        break;

        case MD_SW_CR:
            /* When SAIL dependent crash for MD fatal error is enabled,
               SAIL will go through crash reset flow, concurrently with MD.
               Otherwise, Isolate SAIL (ISLAND mode) */
            if(Crashdbg_disable(DEP_CRASH_ENABLED) == DBG_SUCCESS)
            {
              /* Set Current State and also notify the registered drivers 
              that it's a known crash               */
              pContext->isdState = SOC_CRASH_RESET;
            }
            else
            {
              /* Switch SAIL to Island mode */				
              pContext->isdState = ISLAND_STATE;
              pContext->eISDStatus = ISD_MD2SAIL_STATUS_FAILED;			  
            }
            (void)prvISDSendIPCCInterrupt();

	    break;

        case MD_SEC_FUSE_HR:
        case MD_SOC_HR:

            /* Set Current State and also notify the registered drivers 
            that it's not a fatal error               */
            pContext->isdState = SOC_HARD_RESET;
            /* When MD hard resets via fastboot reboot/qnx reset commands or post MD secure fuse blown,
            allow SAIL to go through hard reset but not crash reset flow.
            Hence, crash debug feature must be disabled to avoid entering crash reset flow upon md_ps_hold low */
            if(Crashdbg_disable(CRASHDBG_DISABLED) != DBG_DISABLED)
            {

                DEBUG_LOG(SAIL_ERROR, "Crash debug disable failed \r\n");
            }
            (void)prvISDSendIPCCInterrupt();
        break;
		
		case MD_SAIL_LPM_DDR_SUSPEND:
			pContext->eISDStatus  = LPM_DDR_SUSPEND_SUCCESS;
			DEBUG_LOG(SAIL_WARNING,"LPM DDR SUSPEND\n\r");
			(void)prvISDSendIPCCInterrupt();
			break;

        case MD_S1_READY:
			pContext->eISDStatus  = S1_READY_SUCCESS;
			DEBUG_LOG(SAIL_WARNING,"MD_S1_READY\n\r");
			vLCWriteTimeStamp( SAIL_S1_READY ,timetick_CvtTimetick64ToTime( timetick_get64() ,T_USEC ) );
			break;
			
		case MD_MB_READY:
			pContext->eISDStatus  = MB_READY_SUCCESS; 
			DEBUG_LOG(SAIL_WARNING,"MD_MB_READY\n\r");
			break;

        case MD_SOC_SDI_DISABLE:
            /* Disable SAIL SDI, Re-configure PMIC and ACK back, upon SoC SDI disable request from MD-TZ */
            if(Crashdbg_disable(CRASHDBG_DISABLE_PMIC_RECFG) != DBG_DISABLED)
            {
              DEBUG_LOG(SAIL_ERROR, "Crash debug disable and PMIC recfg failed \r\n");
            } 
            DEBUG_LOG(SAIL_WARNING,"SAIL SDI Disabled\n\r");
            vISDSetSAILMDAck(stISDSailMDStatus[SAIL_SDI_DISABLED].value);
            break;			
        case SAIL_QAMV4_DETECTION:
            pContext-> QAMV4_Present = QAMV4_PRESENT;
            DEBUG_LOG(SAIL_WARNING,"SAIL_QAMV4_DETECTION\r\n");
        break;		

        default:
        {
            uint32_t  ShdwRegVal = prvISDGetMDStatus();
            if( ((ShdwRegVal & 0xFFFF0000u) == HLOS_BOOT_SUCCESS) &&
                ((ShdwRegVal & 0x0000FFFFu) != 0x0u) )
            {
              /* HLOS boot failures
               For example- a)startup checker failure before HLOS kernel is up, 
                            b)startmgr failure  after HLOS kernel is up
              */
              /* Write HLOS error code into UART buffer to inform external MCU/VIP, based on periodic ping
                from MCU. HLOS doesn't wait for any ACK from SAIL and proceed with MD non-sec wdog immediately.
                Eventually MD-TZ will inform SAIL about "MD_SW_CR", before MD-secure wdog bites.
                Within this time, SAIL shall inform MCU about HLOS error code via UART */
              (void)vLcWriteLogCode(MD_BOOT_MILESTONES,FAIL,&ShdwRegVal,1u);			
            }
            else
            {
              DEBUG_LOG(SAIL_ERROR,"Invalid msg received at SAIL 0x%x\n\r",ShdwRegVal);
            }
        }
        break;
    }
    if(TZ_BOOT_SUCCESS <= nResetReason)
    {
        uACStatus = in_dword(SAILAC_INIT_STATUS);

        if(0UL == uACStatus)
        {
            SAILbspACGVSysCallHandler();
        }
    }
}
