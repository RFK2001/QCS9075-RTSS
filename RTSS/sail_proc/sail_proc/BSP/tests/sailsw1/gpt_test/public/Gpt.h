#ifndef QTIMER_H_
#define QTIMER_H_
/**************************************************************************************************
    Copyright (c) 2022 Qualcomm Technologies, Inc.
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
**************************************************************************************************/

/*=================================================================================================
    File Name          : Gpt.h
    Component Name     : Time
    Description        : Public Header file for GPT Autosar Module
    $Header:
    $DateTime:
    $Author:
=================================================================================================*/
#include "types.h"
#include "Gpt_Cfg.h"
#include "sailbsp_mutex.h"
#include "Std_Types.h"
/*==============================================================================
**                      Global Macro                                          **
==============================================================================*/
#define GPT_VENDOR_ID                
#define GPT_MODULE_ID

#if( GPT_DEV_ERROR_DETECT == STD_ON )
#define GPT_E_UNINIT                 	((uint8_t)0x0AU)
#define GPT_E_BUSY                   	((uint8_t)0x0BU)
#define GPT_E_MODE                   	((uint8_t)0x0CU)
#define GPT_E_ALREADY_INITIALIZED    	((uint8_t)0x0DU)
#define GPT_E_INIT_FAILED            	((uint8_t)0x0EU)
#define GPT_E_PARAM_CHANNEL          	((uint8_t)0x14U)
#define GPT_E_PARAM_VALUE            	((uint8_t)0x15U)
#define GPT_E_PARAM_POINTER          	((uint8_t)0x16U)
#define GPT_E_PARAM_PREDEF_TIMER     	((uint8_t)0x17U)
#define GPT_E_PARAM_MODE             	((uint8_t)0x1FU)
#endif

/* Channel Status */
#define GPT_CHANNEL_UNINITIALIZED    	        ((uint8_t)0x00U)
#define GPT_CHANNEL_INITIALIZED      	        ((uint8_t)0x01U)
#define GPT_CHANNEL_RUNNING          	        ((uint8_t)0x02U)
#define GPT_CHANNEL_STOPPED          	        ((uint8_t)0x03U)
#define GPT_CHANNEL_EXPIRED          	        ((uint8_t)0x04U)
#define GPT_CHANNEL_UNINITIALIZED_FAILED      ((uint8_t)0x05U)


#define GPT_STATUS_FAILED              ((uint8_t)0x00U)
#define GPT_STATUS_PASSED              ((uint8_t)0x01U)

/* Channel modes */
#define GPT_CH_MODE_CONTINUOUS          	((Gpt_ChannelModeType)0x00U)
#define GPT_CH_MODE_ONESHOT             	((Gpt_ChannelModeType)0x01U)

/* Bool */
#define GPT_FALSE          				((uint8_t)0x00U)
#define GPT_TRUE             			((uint8_t)0x01U)


#define GPT_NUMBEROF_CHANNELS         (12u)


#define GPT_PREDEF_TIMER_1US_16BIT_RES  	((uint8_t)1U)
#define GPT_PREDEF_TIMER_1US_24BIT_RES  	((uint8_t)1U)
#define GPT_PREDEF_TIMER_1US_32BIT_RES  	((uint8_t)1U)
#define GPT_PREDEF_TIMER_2US_32BIT_RES  	((uint8_t)2U)
#define GPT_PREDEF_TIMER_100US_32BIT_RES	((uint8_t)100U)

/* Tim MAX Temporary  */
#define GPT_PREDEF_TIMER_1US_16BIT_VAL_MAX  	((uint32_t)0x0000FFFFU)
#define GPT_PREDEF_TIMER_1US_24BIT_VAL_MAX  	((uint32_t)0x00FFFFFFU)
#define GPT_PREDEF_TIMER_1US_32BIT_VAL_MAX  	((uint32_t)0xFFFFFFFFU)
#define GPT_PREDEF_TIMER_2US_32BIT_VAL_MAX  	((uint32_t)0xFFFFFFFFU)
#define GPT_PREDEF_TIMER_100US_32BIT_VAL_MAX	((uint32_t)0xFFFFFFFFU)

/*==============================================================================
**                      Global Type Defs                                      **
==============================================================================*/

typedef uint8_t Gpt_IDType;

typedef void ( * Gpt_NotificationPtrType )( void );
typedef void ( * Gpt_EventPtrType )( void *args );

typedef uint8_t Gpt_ChannelType;
typedef uint8_t Gpt_StateType;
typedef uint64_t Gpt_ValueType;

typedef enum
{
  GPT_MODE_NORMAL = (uint32_t)0U,
  GPT_MODE_SLEEP  = (uint32_t)1U,
} Gpt_ModeType;

typedef uint8_t Gpt_EnWakeupType;
typedef uint8_t Gpt_ChannelCbkEnType;
typedef uint8_t Gpt_ChannelModeType;
typedef uint8_t Gpt_ChannelStateType;


typedef enum
{
  GPT_PREDEF_TIMER_1US_16BIT   = (uint32_t)0U,
  GPT_PREDEF_TIMER_1US_24BIT   = (uint32_t)1U,
  GPT_PREDEF_TIMER_1US_32BIT   = (uint32_t)2U,
  GPT_PREDEF_TIMER_100US_32BIT = (uint32_t)3U,
  GPT_PREDEF_TIMER_2US_32BIT = (uint32_t)4U
} Gpt_PredefTimerType;


/* Channel specific configuration type of GPT driver */
typedef struct
{
  #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
  Gpt_NotificationPtrType GptNotificationPtr;
  uint32_t Gpt_EvLink;
  Gpt_EventPtrType EventPtr;
  Gpt_ChannelCbkEnType Gpt_ChannelCbkEn;
  #endif

  Gpt_PredefTimerType GptPredefTimer;
  Gpt_PredefTimerType GptPredefTimerRes;
  Gpt_PredefTimerType GptPredefTimerMax;
  Gpt_ValueType Gpt_TargetTime;
  /* GPT_MODE_CONTINUOUS/GPT_MODE_ONESHOT */
  Gpt_ChannelModeType GptChannelMode;  
  /* Channel Status */
  Gpt_ChannelStateType GptChannelState;
  /* channel info.*/
  Gpt_ChannelType GptChannelID;
  Gpt_IDType Gpt_TimerID;
  Gpt_IDType Gpt_ClkID;
  uint64_t Gpt_StopValueInTicks;
  uint64_t Gpt_TrStopValueInResolution;
  uint64_t Gpt_TrStartValue;
  mutex_t lock;
} Gpt_ChannelConfigType;

/* Channel specific configuration type of GPT driver */
typedef struct
{
	Gpt_StateType 	Gpt_State;
	Gpt_ModeType 	Gpt_Mode;
	Gpt_ChannelType Gpt_ChannelMax;
}Gpt_ModuleConfigType;

/* Module Cfg type of GPT Driver  */
typedef struct
{
	Gpt_ModuleConfigType *Gpt_ModuleConfig;
	Gpt_ChannelConfigType *ChannelConfig[GPT_MAX_CHANNELS];
} Gpt_ConfigType;

void Gpt_GetVersionInfo( Std_VersionInfoType* const VersionInfoPtr );

Std_ReturnType Gpt_Init(const Gpt_ConfigType *const ConfigPtr);
void Gpt_DeInit(void);

Gpt_ValueType Gpt_GetTimeElapsed(const Gpt_ChannelType Channel);
Gpt_ValueType Gpt_GetTimeRemaining(const Gpt_ChannelType Channel);

void Gpt_StartTimer(const Gpt_ChannelType Channel, const Gpt_ValueType Value);
void Gpt_StopTimer(const Gpt_ChannelType Channel);

void Gpt_EnableNotification(const Gpt_ChannelType Channel);
void Gpt_DisableNotification(const Gpt_ChannelType Channel);

void Gpt_SetMode(const Gpt_ModeType Mode);

Std_ReturnType Gpt_GetPredefTimerValue
( 
	const Gpt_PredefTimerType PredefTimer, uint32_t *const TimeValuePtr
);

Gpt_ValueType Gpt_GetCntFreeRunning( const Gpt_ChannelType Channel );

#include "Gpt_PBcfg.h"
#endif