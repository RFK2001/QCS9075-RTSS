/*
    ===========================================================================

    Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
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

/*=============================================================================
    File Name.............. : CanTrcv_184_Tcan1044.h
    Description............ : Can Transceiver Driver header file
    Autosar Release Version : R22-11
    Platform............... :
    SW Release Version..... :

=============================================================================*/

/*=============================================================================
|                       REVISION HISTORY                                      |
===============================================================================
| Revision  Date            Changed By        Description                     |
===============================================================================

=============================================================================*/
#ifndef CANTRCV_184_TCAN1044_H
#define CANTRCV_184_TCAN1044_H

/*=============================================================================
|                       INCLUDE FILES                                         |
=============================================================================*/
#include "ComStack_Types.h"
#include "Can_GeneralTypes.h"
#include "CanTrcv_184_Tcan1044_Cfg.h"

#ifndef CAN_PLT_SAFERTOS_ENABLE
#include "Dio.h"
#else
#include "Std_Types.h"
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
#include "EcuM.h"
#if(CANTRCV_184_TCAN1044_ICU_CHANNEL_SUPPORT == STD_ON)
#include "Icu.h"
#endif

/*=============================================================================
|                       VERSION INFORMATION                                   |
=============================================================================*/
/* AUTOSAR Specification Version Information */
#define CANTRCV_184_TCAN1044_AR_RELEASE_MAJOR_VERSION      4
#define CANTRCV_184_TCAN1044_AR_RELEASE_MINOR_VERSION      8
#define CANTRCV_184_TCAN1044_AR_RELEASE_REVISION_VERSION   0

/* Software Version Information */
#define CANTRCV_184_TCAN1044_SW_MAJOR_VERSION   1
#define CANTRCV_184_TCAN1044_SW_MINOR_VERSION   2
#define CANTRCV_184_TCAN1044_SW_PATCH_VERSION   0

#define CANTRCV_184_TCAN1044_VENDOR_ID   0x00B8u
#define CANTRCV_184_TCAN1044_MODULE_ID   0x0046u

/*=============================================================================
|                       VERSION CHECK                                         |
=============================================================================*/
/* [SWS_BSW_00036] Inter module version check. */
#ifndef CAN_PLT_SAFERTOS_ENABLE
#if ((CANTRCV_184_TCAN1044_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION) || \
     (CANTRCV_184_TCAN1044_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION))
// #error "Autosar version numbers of CanTrcv_184_Tcan1044.h and Dio.h are different."
#endif

#if ((CANTRCV_184_TCAN1044_AR_RELEASE_MAJOR_VERSION != ECUM_AR_RELEASE_MAJOR_VERSION) || \
     (CANTRCV_184_TCAN1044_AR_RELEASE_MINOR_VERSION != ECUM_AR_RELEASE_MINOR_VERSION))
// #error "Autosar version numbers of CanTrcv_184_Tcan1044.h and EcuM.h are different."
#endif

#if(CANTRCV_184_TCAN1044_ICU_CHANNEL_SUPPORT == STD_ON)
#if ((CANTRCV_184_TCAN1044_AR_RELEASE_MAJOR_VERSION != ICU_AR_RELEASE_MAJOR_VERSION) || \
     (CANTRCV_184_TCAN1044_AR_RELEASE_MINOR_VERSION != ICU_AR_RELEASE_MINOR_VERSION))
// #error "Autosar version numbers of CanTrcv_184_Tcan1044.h and Icu.h are different."
#endif
#endif
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */

/*=============================================================================
|                       API Service ID                                        |
=============================================================================*/
/* Service ID for CanTrcv_184_Tcan1044_Init */
#define CANTRCV_184_TCAN1044_INIT_SID                  (uint8)0x00
/* Service ID for CanTrcv_184_Tcan1044_SetOpMode */
#define CANTRCV_184_TCAN1044_SETOPMODE_SID             (uint8)0x01
/* Service ID for CanTrcv_184_Tcan1044_GetOpMode */
#define CANTRCV_184_TCAN1044_GETOPMODE_SID             (uint8)0x02
/* Service ID for CanTrcv_184_Tcan1044_GetBusWuReason */
#define CANTRCV_184_TCAN1044_GETBUSWUREASON_SID        (uint8)0x03
/* Service ID for CanTrcv_184_Tcan1044_GetVersionInfo */
#define CANTRCV_184_TCAN1044_GETVERSIONINFO_SID        (uint8)0x04
/* Service ID for CanTrcv_184_Tcan1044_SetWakeupMode */
#define CANTRCV_184_TCAN1044_SETWAKEUPMODE_SID         (uint8)0x05
/* Service ID for CanTrcv_184_Tcan1044_CheckWakeup */
#define CANTRCV_184_TCAN1044_CHECKWAKEUP_SID           (uint8)0x07
/* Service ID for CanTrcv_184_Tcan1044_Deinit */
#define CANTRCV_184_TCAN1044_DEINIT_SID                (uint8)0x10
/* Service ID for CanTrcv_184_Tcan1044_MainFunction */
#define CANTRCV_184_TCAN1044_MAINFUNCTION_SID          (uint8)0x06

/*=============================================================================
|                       Macros                                                |
=============================================================================*/
/* Macro to check whether CAN Trcv is un-initialized */
#define CANTRCV_184_TCAN1044_STATE_NOT_ACTIVE          (uint8)0x00
/* Macro to check whether CAN Trcv is initialized */
#define CANTRCV_184_TCAN1044_STATE_ACTIVE              (uint8)0x01
/* Macro for wakeupreason if reason not found */
#define CANTRCV_184_TCAN1044_WU_NOT_FOUND              (uint8)0xFF

/*=============================================================================
|                       DET ERROR CODES                                       |
=============================================================================*/
/*DET errors*/
#define CANTRCV_184_TCAN1044_E_INVALID_TRANSCEIVER      1u
#define CANTRCV_184_TCAN1044_E_PARAM_POINTER            2u
#define CANTRCV_184_TCAN1044_E_UNINIT                  11u
#define CANTRCV_184_TCAN1044_E_TRCV_NOT_STANDBY        21u
#define CANTRCV_184_TCAN1044_E_TRCV_NOT_NORMAL         22u
#define CANTRCV_184_TCAN1044_E_PARAM_TRCV_WAKEUP_MODE  23u
#define CANTRCV_184_TCAN1044_E_PARAM_TRCV_OPMODE       24u
#define CANTRCV_184_TCAN1044_E_BAUDRATE_NOT_SUPPORTED  25u
#define CANTRCV_184_TCAN1044_E_INIT_FAILED             27u
/*Run time errors*/
#define CANTRCV_184_TCAN1044_E_NO_TRCV_CONTROL         26u

/*=============================================================================
|                       Structures and Enums                                  |
=============================================================================*/
#ifdef CAN_PLT_SAFERTOS_ENABLE
/* DIO */
typedef uint16 Dio_ChannelType;
typedef uint8 Dio_LevelType;
#endif 

typedef struct
{
    /* Pointer to the Operational Mode of the CAN Transceiver */
    CanTrcv_TrcvModeType OperMode;

#if (CANTRCV_184_TCAN1044_WAKEUP_SUPPORT == STD_ON)
    /* Pointer to the wakeup reason of the CAN Transceiver */
    uint8 WakeupReason;

    /* Pointer to the BusWakeUp Notification */
    CanTrcv_TrcvWakeupModeType WakeupNotiforEvent;

    /* Pointer to the BusWakeUp State */
    boolean WakeupPending;
#endif
} CanTrcv_Tcan1044ChStateType;

typedef struct 
{
    /*Init State*/
    CanTrcv_TrcvModeType InitState;

    /* Input Pin - Standby Pin*/
    Dio_ChannelType StandBypin;

    /* Output Pin - Rxd Pin */
    Dio_ChannelType RxdPin;

    /* Maximum Baudrate */
    uint32 MaxBaudrate;

    /* Channel Used*/
    boolean ChannelUsed;

#if (CANTRCV_184_TCAN1044_WAKEUP_SUPPORT == STD_ON)
    /* WakeUp by Bus Support */
    boolean WakeupbyBus;

    /* Wakeup Source Id */
    EcuM_WakeupSourceType WakeupSourceId;

#if(CANTRCV_184_TCAN1044_ICU_CHANNEL_SUPPORT == STD_ON)
    /* ICU Channel support*/
    boolean IcuSupport;

    /* ICU Channel Id */
    Icu_ChannelType IcuChannelId;
#endif
#endif
} CanTrcv_Tcan1044ChConfigType;

typedef struct {
    /* Number of CAN Transceiver Channels */
    uint8 NumOfChannels;

    /* Pointer to CAN Transceiver configurations */
    const CanTrcv_Tcan1044ChConfigType *ChannelConfig;
} CanTrcv_Tcan1044ConfigType;

extern const CanTrcv_Tcan1044ConfigType CanTrcv_184_Tcan1044_Config;

/*=============================================================================
|                       Function Declarations                                 |
=============================================================================*/
#define CANTRCV_184_TCAN1044_START_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"
void CanTrcv_184_Tcan1044_Init(const CanTrcv_Tcan1044ConfigType *ConfigPtr);
#define CANTRCV_184_TCAN1044_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"

#define CANTRCV_184_TCAN1044_START_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"
Std_ReturnType CanTrcv_184_Tcan1044_SetOpMode(
     uint8 Transceiver,
     CanTrcv_TrcvModeType OpMode);
#define CANTRCV_184_TCAN1044_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"

#define CANTRCV_184_TCAN1044_START_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"
Std_ReturnType CanTrcv_184_Tcan1044_GetOpMode(
     uint8 Transceiver,
     CanTrcv_TrcvModeType *OpMode);
#define CANTRCV_184_TCAN1044_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"

#define CANTRCV_184_TCAN1044_START_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"
Std_ReturnType CanTrcv_184_Tcan1044_GetBusWuReason(
     uint8 Transceiver,
     CanTrcv_TrcvWakeupReasonType *reason);
#define CANTRCV_184_TCAN1044_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"

#if (CANTRCV_184_TCAN1044_VERSION_INFO_API == STD_ON)
#define CANTRCV_184_TCAN1044_START_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"
void CanTrcv_184_Tcan1044_GetVersionInfo(Std_VersionInfoType *versioninfo);
#define CANTRCV_184_TCAN1044_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"
#endif

#define CANTRCV_184_TCAN1044_START_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"
Std_ReturnType CanTrcv_184_Tcan1044_SetWakeupMode(
     uint8 Transceiver,
     CanTrcv_TrcvWakeupModeType TrcvWakeupMode);
#define CANTRCV_184_TCAN1044_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"

#define CANTRCV_184_TCAN1044_START_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"
Std_ReturnType CanTrcv_184_Tcan1044_CheckWakeup(uint8 Transceiver);
#define CANTRCV_184_TCAN1044_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"

#define CANTRCV_184_TCAN1044_START_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"
void CanTrcv_184_Tcan1044_DeInit(void);
#define CANTRCV_184_TCAN1044_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"

#ifdef CAN_PLT_SAFERTOS_ENABLE
#define CANTRCV_184_TCAN1044_START_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"
void CanTrcv_184_Tcan1044_SetOpModeToStandby(uint8 Transceiver);
#define CANTRCV_184_TCAN1044_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"

#endif /* End of CAN_PLT_SAFERTOS_ENABLE */

#endif /* CANTRCV_184_TCAN1044_H */

/*=============================================================================
|                       END OF FILE                                           |
=============================================================================*/
