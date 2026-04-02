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

#ifndef GPT_H__
#define GPT_H__

/*==============================================================================
**                            Include files                                   **
==============================================================================*/

/*@Requirements : [SWS_Gpt_00278] */
#include "Std_Types.h" /* Std_ReturnType and Std_VersionInfoType      */
#include "Gpt_Cfg.h"
/* EcuM_WakeupSource: from EcuM.h and EcuM_Cbk.h not required for BSP RTD */
/*==============================================================================
**                      defines and macros                                    **
==============================================================================*/
/*------------------< Component Identification >------------------*/
/*@Requirements : [SRS_BSW_00374]
 *@brief : All Basic Software Modules shall provide a 
 *         readable module vendor identification
 */
#define GPT_VENDOR_ID                  0x00B8U
/*@Requirements : [SRS_BSW_00379]
 *@brief : All software modules shall provide a module identifier
 *         in the header file and in the module XML description file.
 */
#define GPT_MODULE_ID                  30U

/*
* @brief :  Runtime Errors. 
* @implements :
* @Requirements : [SWS_Gpt_91001]
*/

/* API service called when timer channel is still busy (running) */
#define GPT_E_BUSY                            ((uint8)0x0B) 

/* API service called when driver is in wrong mode */
#define GPT_E_MODE                            ((uint8)0x0C)

#if(GPT_DEV_ERROR_DETECT == STD_ON)
/*
* @brief : Development Errors. 
* @implements :
* @Requirements : [SWS_Gpt_91000]
*/
/*API service called without module initialization*/
#define GPT_E_UNINIT                            ((uint8)0x0A) 
/*API service for initialization called when already initialized*/
#define GPT_E_ALREADY_INITIALIZED               ((uint8)0x0D)
/*API error return code: Init function failed*/
#define GPT_E_INIT_FAILED                       ((uint8)0x0E)
/*API parameter checking: invalid channel */
#define GPT_E_PARAM_CHANNEL                     ((uint8)0x14)
/*API parameter checking: invalid value*/
#define GPT_E_PARAM_VALUE                       ((uint8)0x15)
/*API parameter checking: invalid pointer*/
#define GPT_E_PARAM_POINTER                     ((uint8)0x16)
/*API parameter checking: invalid Predef Timer*/
#define GPT_E_PARAM_PREDEF_TIMER                ((uint8)0x17)
/*API parameter checking: invalid mode */
#define GPT_E_PARAM_MODE                        ((uint8)0x1F)


/* GPT Service ID Numbers */

/* Gpt_Init Service Id */
#define GPT_SERVICE_ID_INIT                         ((uint8)1U)

/* Gpt_GetTimeElapsed Service Id */
#define GPT_SERVICE_ID_GET_TIME_ELAPSED             ((uint8)3U)
/* Gpt_GetTimeRemaining Service Id */
#define GPT_SERVICE_ID_GET_TIME_REMAINING           ((uint8)4U)

/* Gpt_StopTimer Service Id */
#define GPT_SERVICE_ID_STOP_TIMER                   ((uint8)6U)
/* Gpt_EnableNotification Service Id */
#define GPT_SERVICE_ID_ENABLE_NOTIFICATION          ((uint8)7U)
/* Gpt_DisableNotification Service Id */
#define GPT_SERVICE_ID_DISABLE_NOTIFICATION         ((uint8)8U)
/* Gpt_SetMode Service Id */
#define GPT_SERVICE_ID_SET_MODE                     ((uint8)9U)
/* Gpt_DisableWakeup Service Id */
#define GPT_SERVICE_ID_DISABLE_WAKEUP               ((uint8)0x0AU)
/* Gpt_EnableWakeup Service Id */
#define GPT_SERVICE_ID_ENABLE_WAKEUP                ((uint8)0x0BU)
/* Gpt_CheckWakeup Service Id */
#define GPT_SERVICE_ID_CHECK_WAKEUP                 ((uint8)0x0CU)
/* Gpt_GetPredefTimerValue Service Id */
#define GPT_SERVICE_ID_GET_PREDEF_TIME_VALUE        ((uint8)0x0DU)
/* GPT Module BSP RTD General Service Id */
#define GPT_SERVICE_ID_IRQ_EVENT                    ((uint8)0x0EU)

#define GPT_SERVICE_ID_GET_CNT_FREERUN              ((uint8)0x0FU)


#if(GPT_VERSION_INFO_API == STD_ON)
/* Gpt_GetVersionInfo Service Id */
#define GPT_SERVICE_ID_GETVERSIONINFO               ((uint8)0x00U)
#endif

#endif /*(GPT_DEV_ERROR_DETECT == STD_ON)*/

/* This is used in Runtime Errors API Call, so defined outside the DEV ERROR*/
/* Gpt_DeInit Service Id */
#define GPT_SERVICE_ID_DE_INIT                      ((uint8)2U)
/* Gpt_StartTimer Service Id */
#define GPT_SERVICE_ID_START_TIME                   ((uint8)5U)

/* DIO MODULE INSTANCE ID */
#define GPT_INSTANCE_ID                             ((uint8)0U)

/* Gpt Channel States defined in SWS */
#define GPT_CHANNEL_UNINITIALIZED    	            ((uint8)0x00U)
#define GPT_CHANNEL_INITIALIZED      	            ((uint8)0x01U)
#define GPT_CHANNEL_RUNNING          	            ((uint8)0x02U)
#define GPT_CHANNEL_STOPPED          	            ((uint8)0x03U)
#define GPT_CHANNEL_EXPIRED          	            ((uint8)0x04U)

/* Driver States */
#define GPT_DRIVER_UNINITIALIZED                    ((uint8)0x00U)
#define GPT_DRIVER_INITIALIZED                      ((uint8)0x01U)


/* Channel modes */
#define GPT_CH_MODE_CONTINUOUS          	        ((uint8)0x00U)
#define GPT_CH_MODE_ONESHOT             	        ((uint8)0x01U)

/* Bool */
#define GPT_FALSE          				            ((uint8)0x00U)
#define GPT_TRUE             			            ((uint8)0x01U)

/* custom */
#define GPT_STATUS_FAILED              ((uint8_t)0x00U)
#define GPT_STATUS_PASSED              ((uint8_t)0x01U)

/* Predef Timers values scaling according to @[SWS_Gpt_00383] */
/* @[SWS_Gpt_00383] ====> @[SWS_Gpt_00389] ====> @[SWS_Gpt_00334] */
#define GPT_PREDEF_TIMER_1US_16BIT_RES              ((uint8)1U)
#define GPT_PREDEF_TIMER_1US_24BIT_RES              ((uint8)1U)
#define GPT_PREDEF_TIMER_1US_32BIT_RES              ((uint8)1U)
#define GPT_PREDEF_TIMER_100US_32BIT_RES            ((uint8)100U)
#define GPT_PREDEF_TIMER_2US_32BIT_RES  	        ((uint8)2U)

/* Time MAX specific spare predef timers */
#define GPT_PREDEF_TIMER_1US_16BIT_VAL_MAX          ((uint32)0x0000FFFFU)
#define GPT_PREDEF_TIMER_1US_24BIT_VAL_MAX          ((uint32)0x00FFFFFFU)
#define GPT_PREDEF_TIMER_1US_32BIT_VAL_MAX          ((uint32)0xFFFFFFFFU)
#define GPT_PREDEF_TIMER_2US_32BIT_VAL_MAX          ((uint32)0xFFFFFFFFU)
#define GPT_PREDEF_TIMER_100US_32BIT_VAL_MAX        ((uint32)0xFFFFFFFFU)

/*==============================================================================
**       map section as rgn fixed for BSP RTD                                 **
==============================================================================*/
#define GPT_TIMER_FUNC __attribute__ ( ( section ( "gpttimer_api" ) ) )
#define GPT_TIMER_DATA __attribute__ ( ( section ( "gpttimer_rw" ) ) )
#define GPT_TIMER_CONST __attribute__ ( ( section ( "gpttimer_ro" ) ) )


extern unsigned int Image$$lnkGPTTIMERStartAddr$$ZI$$Base;
extern unsigned int Image$$lnkGPTTIMEREndAddr$$ZI$$Base;

#define GPT_DATA_RGN_START      ( void * )( &Image$$lnkGPTTIMERStartAddr$$ZI$$Base )
#define GPT_DATA_RGN_SIZE       ( uint32 )( (uint32) &Image$$lnkGPTTIMEREndAddr$$ZI$$Base - \
                                                    (uint32) &Image$$lnkGPTTIMERStartAddr$$ZI$$Base )

/*==============================================================================
**   Global typedefs : Enums, Structures Union and other typedefs             **
==============================================================================*/

typedef void ( * Gpt_NotificationPtrType )( void );
typedef void ( * Gpt_EventPtrType )( void *args );
/* 
 * @brief :  Numeric ID of a GPT channel.. 
 * @implements :   0 - <Implementation specific.:>
 * @Requirements : [SWS_Gpt_00358]
 */
typedef uint16 Gpt_ChannelType;

/*
 * @brief :  Type for reading and setting the timer values (in number of ticks). 
 * @implements :The range of this type is µC dependent (width of the timer 
 *              register) and has to be described by the supplier.
 * @Requirements : [SWS_Gpt_00359]
 */
typedef uint64 Gpt_ValueType;

/*
 * @brief :   Modes of the GPT driver.
 * @implements :The range of this type is µC dependent (width of the timer register) and has to 
 *                be described by the supplier.
 * @Requirements : [SWS_Gpt_00360]
 */
typedef enum
{
	GPT_MODE_NORMAL = 0x00U,          /* Normal operation mode of the GPT*/
	GPT_MODE_SLEEP  = 0x01U,          /* Operation for reduced power operation mode.
	                                     In sleep mode only wakeup capable channels
	                                     are available.*/
} Gpt_ModeType;

/*
 * @brief :    Type for GPT Predef Timers.
 * @implements :
 * @Requirements : [SWS_Gpt_00389]
 */
/* @[SWS_Gpt_00383] ====> @[SWS_Gpt_00389] ====> @[SWS_Gpt_00334] */
typedef enum
{
	GPT_PREDEF_TIMER_1US_16BIT   = 0x00U,   /* GPT Predef Timer with tick duration 1µs and range 16bit   */
	GPT_PREDEF_TIMER_1US_24BIT   = 0x01U,   /* GPT Predef Timer with tick duration 1µs and range 24bit   */
	GPT_PREDEF_TIMER_1US_32BIT   = 0x02U,   /* GPT Predef Timer with tick duration 1µs and range 32bit   */
	GPT_PREDEF_TIMER_100US_32BIT = 0x03U,   /* GPT Predef Timer with tick duration 100µs and range 32bit */
	GPT_PREDEF_TIMER_2US_32BIT   = 0x04U,   /* QC spec: GPT Predef Timer with tick duration 2us and range 32bit */
	GPT_PREDEF_TIMER_XUS_DISABLED = 0x05U,  /* QC spec: GPT Predef Timer with tick duration 2us and range 32bit */
} Gpt_PredefTimerType;

typedef enum
{
    GPT_PREDEF_TIMER_1US_16BIT_ENABLED         =  (0x00U),
    GPT_PREDEF_TIMER_1US_16_24BIT_ENABLED      =  (0x01U),
    GPT_PREDEF_TIMER_1US_16_24_32BIT_ENABLED   =  (0x02U),
    GPT_PREDEF_TIMER_1US_DISABLED              =  (0x03U),
}Gpt_PredefTimerGradeType;


typedef enum
{
    GPT_CHAN_HWTIMER_PL2_PHY      =  (0x00U), 
    GPT_CHAN_HWTIMER_PL1_VRT      =  (0x01U),
    GPT_CHAN_HWTIMER_PL1_PHY      =  (0x04U), /* set 4 as per HW mapping */
    GPT_CHAN_HWTIMER_PL0_QTMR     =  (0x05U), /* chan 0 to chan 11*/
}Gpt_ChanHWType;

typedef uint8     Gpt_EnableWakeupType;
typedef uint8     Gpt_ChannelCbkEnType;
typedef uint8     Gpt_ChannelModeType;
typedef uint8     Gpt_ChannelStateType;
typedef uint8     Gpt_StateType;
/* BSP RTD */
typedef uint32 EcuM_WakeupSourceType;

/* Channel specific configuration type of GPT driver */
typedef struct
{
    #if ((GPT_WAKEUP_FUNCTIONALITY_API == STD_ON) \
            && (GPT_REPORT_WAKEUP_SOURCE == STD_ON))
     /* Wakeup information to EcuM_SetWakeupEvent bitfeild other than default ECUM remaining set by Integrator */
    EcuM_WakeupSourceType GptChannelWakeupInfo;
    #endif
    #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
    /* Channel wakeup capability TRUE/FALSE */
    Gpt_EnableWakeupType GptEnableWakeup;
    #endif
    #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    Gpt_NotificationPtrType   GptNotification;
    #endif
    Gpt_ChanHWType            GptChanHW;
    Gpt_ChannelType           GptChannelID;                   /*  Channel Id of the GPT channel  */
    Gpt_ChannelModeType       GptChannelMode;                 /*  GPT_Autosar MODE_CONTINUOUS/GPT_MODE_ONESHOT  */
    uint64                    GptChannelTickFrequency;        /*  Specifies the tick frequency of the timer channel in Hz*/
    uint64                    GptChannelTickValueMax;         /*  Maximum value in ticks, next rolls over to zero.*/                                                                
    uint8                     GptChannelClkRef;               /* optional , deafult clock is on */
    uint8                     GptChannelEcucPartitionRef;     /* optional , deafult amp image */
} Gpt_ChannelConfigType;

/* Channel specific configuration type of GPT driver */
typedef struct
{
    Gpt_PredefTimerGradeType GptPredefTimer1usEnablingGrade;
    uint8 GptPredefTimer100us32bitEnable;
    uint8 GptPredefTimer2us32bitEnable;
    Gpt_ChanHWType GptPredefTimerHWType;
	Gpt_ChannelType GptDrvChannelMaxConfig;           /*  Max channels are configured*/
}Gpt_ModuleConfigType;

/*
* @brief :        This is the type of the data structure including the configuration set required for
                  initializing the GPT timer unit.
* @implements :   Implementation specific configuration data structure, see chapter 10 for
                  configurable parameters.
* @Requirements : [SWS_Gpt_00357]
*/

typedef struct
{
   const Gpt_ChannelConfigType *Gpt_ChannelConfig;   /* Hw and driver Config*/
   const Gpt_ModuleConfigType  *Gpt_ModuleConfig;    /* Driver Config*/
}Gpt_ConfigType;

/*==============================================================================
**                        Global Function Declarations                        **
==============================================================================*/
/*==============================================================================
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
 @Note                All the other services used after Gpt_Init services is
                        executed.
==============================================================================*/
GPT_TIMER_FUNC extern Std_ReturnType Gpt_Init ( const Gpt_ConfigType* const ConfigPtr);
#if (GPT_DEINIT_API == STD_ON)
/*==============================================================================
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
 @Note                All the other services used after Gpt_Init services is
                        executed.
==============================================================================*/
GPT_TIMER_FUNC extern void Gpt_DeInit (void);
#endif

GPT_TIMER_FUNC Gpt_ValueType Gpt_GetCntFreeRunning( const Gpt_ChannelType Channel );

#if (GPT_TIME_ELAPSED_API == STD_ON)
/*==============================================================================
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
@Note                All the other services used after Gpt_Init services is
                     executed.
==============================================================================*/
GPT_TIMER_FUNC extern Gpt_ValueType Gpt_GetTimeElapsed (Gpt_ChannelType Channel);
#endif

#if (GPT_TIME_REMAINING_API == STD_ON)
/*==============================================================================
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
 @Note                All the other services used after Gpt_Init services is 
                        executed.
==============================================================================*/
GPT_TIMER_FUNC extern Gpt_ValueType Gpt_GetTimeRemaining (Gpt_ChannelType Channel);
#endif
/*==============================================================================
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
 @Note                All the other services used after Gpt_Init services is
                      executed.
==============================================================================*/
GPT_TIMER_FUNC extern void Gpt_StartTimer (Gpt_ChannelType Channel,Gpt_ValueType Value);
/*==============================================================================
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
 @Note                All the other services used after Gpt_Init services is
                        executed.
==============================================================================*/
GPT_TIMER_FUNC extern void Gpt_StopTimer (Gpt_ChannelType Channel);

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
/*==============================================================================
 @Service name        Gpt_EnableNotification
 @Description         Enables the interrupt notification for a channel
                        (relevant in normal mode)
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
 @Note                All the other services used after Gpt_Init services is
                        executed.
==============================================================================*/
GPT_TIMER_FUNC extern void Gpt_EnableNotification (Gpt_ChannelType Channel);
#endif

#if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
/*==============================================================================
 @Service name        Gpt_DisableNotification
 @Description         Disables the interrupt notification for a channel 
                        (relevant in normal mode).
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
 @Note                All the other services used after Gpt_Init services is
                        executed.
==============================================================================*/
GPT_TIMER_FUNC extern void Gpt_DisableNotification (Gpt_ChannelType Channel);
#endif

#if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)
#if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
/*==============================================================================
 @Service name        Gpt_SetMode
 @Description         Sets the operation mode of the GPT.
 @param[in]           GPT_MODE_NORMAL: Normal operation mode of the GPT driver.
                      GPT_MODE_SLEEP: Sleep mode of the GPT driver
                      (wakeup capable).  See also Gpt_ModeType
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
 @Note                All the other services used after Gpt_Init services is
                        executed.
==============================================================================*/
GPT_TIMER_FUNC extern void Gpt_SetMode (Gpt_ModeType Mode);
/*==============================================================================
 @Service name        Gpt_EnableWakeup
 @Description         Enables the wakeup interrupt of a channel (relevant in
                        sleep mode).
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
 @Note                All the other services used after Gpt_Init services is
                        executed.
==============================================================================*/
GPT_TIMER_FUNC extern void Gpt_EnableWakeup (Gpt_ChannelType Channel);
/*==============================================================================
 @Service name        Gpt_DisableWakeup
 @Description         Disables the wakeup interrupt of a channel (relevant in 
                        sleep mode).
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
 @Note                All the other services used after Gpt_Init services is
                        executed.
==============================================================================*/
GPT_TIMER_FUNC extern void Gpt_DisableWakeup (Gpt_ChannelType Channel);
/*==============================================================================
 @Service name        Gpt_CheckWakeup
 @Description         Checks if a wakeup capable GPT channel is the source for a
                        wakeup event and calls the ECU state manager service 
                        EcuM_SetWakeupEvent in case of a valid GPT channel
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
 @Note                All the other services used after Gpt_Init services is
                        executed.
==============================================================================*/
GPT_TIMER_FUNC extern void Gpt_CheckWakeup (EcuM_WakeupSourceType WakeupSource);
#endif /* GPT_WAKEUP_FUNCTIONALITY_API */
#endif /* GPT_REPORT_WAKEUP_SOURCE */
/*==============================================================================
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
 @Note                All the other services used after Gpt_Init services is
                        executed.
==============================================================================*/
GPT_TIMER_FUNC extern Std_ReturnType Gpt_GetPredefTimerValue (Gpt_PredefTimerType PredefTimer,uint32* TimeValuePtr);

#if (GPT_VERSION_INFO_API == STD_ON)
/*==============================================================================
 @Service name        Gpt_GetVersionInfo
 @Description         Returns the version information of this module.
 @param[in]           None
 @param[out]          VersionInfoPtrPointer : to where to store the version
                        information of this module.
 @param[in, out]      None
 @return              Void
 @Pre                 None
 @Post                None
 @Requirements IDs    SWS_Gpt_00279
 @Design IDs          NA
 @service ID          0x00
 @Sync/Async          Synchronous function
 @Reentrancy          Reentrant
 @Note                All the other services used after Port_init services is
                        executed.
==============================================================================*/    
GPT_TIMER_FUNC extern void Gpt_GetVersionInfo (Std_VersionInfoType* VersionInfoPtr);
#endif
/*The file is included to get extern declaration of all the Gpt  configuration
    root structure. The extern declaration of configuration root structure is
    needed by application software */
#include "Gpt_PBcfg.h"
/*==============================================================================
**                                                                            **
==============================================================================*/
#endif /*GPT_H*/
/*==============================================================================
**                              End of file Gpt.h                             **
==============================================================================*/
