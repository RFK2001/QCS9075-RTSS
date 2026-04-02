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
  File Name.............. : CanTrcv_184_Tcan1146.h
  Description............ : Can Transceiver TCAN1146 Driver header file
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
#ifndef CANTRCV_184_TCAN1146_H
#define CANTRCV_184_TCAN1146_H

/*=============================================================================
  |                       INCLUDE FILES                                         |
  =============================================================================*/
#include "Spi.h"
#include "ComStack_Types.h"
#include "Can_GeneralTypes.h"
#include "CanTrcv_184_Tcan1146_Cfg.h"
#include "EcuM.h"
#ifndef CAN_PLT_SAFERTOS_ENABLE
#if(CANTRCV_184_TCAN1146_ICU_CHANNEL_SUPPORT == STD_ON)
#include "Icu.h"
#endif
#if(CANTRCV_184_TCAN1146_BUSERR_FLAG_SUPPORT == STD_ON)
#include "Rte_Dem_Type.h"
#endif

#endif /* End of CAN_PLT_SAFERTOS_ENABLE */

/*=============================================================================
  |                       VERSION INFORMATION                                   |
  =============================================================================*/
/* AUTOSAR Specification Version Information */
#define CANTRCV_184_TCAN1146_AR_RELEASE_MAJOR_VERSION      4
#define CANTRCV_184_TCAN1146_AR_RELEASE_MINOR_VERSION      8
#define CANTRCV_184_TCAN1146_AR_RELEASE_REVISION_VERSION   0

/* Software Version Information */
#define CANTRCV_184_TCAN1146_SW_MAJOR_VERSION   1
#define CANTRCV_184_TCAN1146_SW_MINOR_VERSION   1
#define CANTRCV_184_TCAN1146_SW_PATCH_VERSION   0

#define CANTRCV_184_TCAN1146_VENDOR_ID   0x00B8u
#define CANTRCV_184_TCAN1146_MODULE_ID   0x0046u

/*=============================================================================
|                       VERSION CHECK                                         |
=============================================================================*/
/* [SWS_BSW_00036] Inter module version check. */
#ifndef CAN_PLT_SAFERTOS_ENABLE
#if ((CANTRCV_184_TCAN1146_AR_RELEASE_MAJOR_VERSION != SPI_AR_RELEASE_MAJOR_VERSION) || \
     (CANTRCV_184_TCAN1146_AR_RELEASE_MINOR_VERSION != SPI_AR_RELEASE_MINOR_VERSION))
#error "Autosar version numbers of CanTrcv_184_Tcan1146.h and Spi.h are different."
#endif

#if ((CANTRCV_184_TCAN1146_AR_RELEASE_MAJOR_VERSION != ECUM_AR_RELEASE_MAJOR_VERSION) || \
     (CANTRCV_184_TCAN1146_AR_RELEASE_MINOR_VERSION != ECUM_AR_RELEASE_MINOR_VERSION))
#error "Autosar version numbers of CanTrcv_184_Tcan1146.h and EcuM.h are different."
#endif

#if(CANTRCV_184_TCAN1146_ICU_CHANNEL_SUPPORT == STD_ON)
#if ((CANTRCV_184_TCAN1146_AR_RELEASE_MAJOR_VERSION != ICU_AR_RELEASE_MAJOR_VERSION) || \
     (CANTRCV_184_TCAN1146_AR_RELEASE_MINOR_VERSION != ICU_AR_RELEASE_MINOR_VERSION))
#error "Autosar version numbers of CanTrcv_184_Tcan1146.h and Icu.h are different."
#endif
#endif
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */
/*=============================================================================
  |                       API Service ID                                        |
  =============================================================================*/
/* Service ID for CanTrcv_184_Tcan1146_init */
#define CANTRCV_184_TCAN1146_INIT_SID                       (uint8)0x00
/* Service ID for CanTrcv_184_Tcan1146_SetOpMode */
#define CANTRCV_184_TCAN1146_SETOPMODE_SID                  (uint8)0x01
/* Service ID for CanTrcv_184_Tcan1146_GetOpMode */
#define CANTRCV_184_TCAN1146_GETOPMODE_SID                  (uint8)0x02
/* Service ID for CanTrcv_184_Tcan1146_GetBusWuReason */
#define CANTRCV_184_TCAN1146_GETBUSWUREASON_SID             (uint8)0x03
/* Service ID for CanTrcv_184_Tcan1146_GetVersionInfo */
#define CANTRCV_184_TCAN1146_GETVERSIONINFO_SID             (uint8)0x04
/* Service ID for CanTrcv_184_Tcan1146_SetWakeupMode */
#define CANTRCV_184_TCAN1146_SETWAKEUPMODE_SID              (uint8)0x05
/* Service ID for CanTrcv_184_Tcan1146_GetTrcvSystemData */
#define CANTRCV_184_TCAN1146_GETTRCVSYSTEMDATA_SID          (uint8)0x09
/* Service ID for CanTrcv_184_Tcan1146_ClearTrcvWufFlag */
#define CANTRCV_184_TCAN1146_CLEARTRCVWUFFLAG_SID           (uint8)0x0A
/* Service ID for CanTrcv_184_Tcan1146_ReadTrcvTimeoutFlag */
#define CANTRCV_184_TCAN1146_READTRCVTIMEOUTFLAG_SID        (uint8)0x0B
/* Service ID for CanTrcv_184_Tcan1146_ClearTrcvTimeoutFlag */
#define CANTRCV_184_TCAN1146_CLEARTRCVTIMEOUTFLAG_SID       (uint8)0x0C
/* Service ID for CanTrcv_184_Tcan1146_ReadTrcvSilenceFlag */
#define CANTRCV_184_TCAN1146_READTRCVSILENCEFLAG_SID        (uint8)0x0D
/* Service ID for CanTrcv_184_Tcan1146_CheckWakeup */
#define CANTRCV_184_TCAN1146_CHECKWAKEUP_SID                (uint8)0x07
/* Service ID for CanTrcv_184_Tcan1146_SetPNActivationState */
#define CANTRCV_184_TCAN1146_SETPNACTIVATIONSTATE_SID       (uint8)0x0F
/* Service ID for CanTrcv_184_Tcan1146_CheckWakeFlag */
#define CANTRCV_184_TCAN1146_CHECKWAKEFLAG_SID              (uint8)0x0E
/* Service ID for CanTrcv_184_Tcan1146_Deinit */
#define CANTRCV_184_TCAN1146_DEINIT_SID                     (uint8)0x10
/* Service ID for CanTrcv_184_Tcan1146_MainFunction */
#define CANTRCV_184_TCAN1146_MAINFUNCTION_SID               (uint8)0x06
/* Service ID for CanTrcv_184_Tcan1146_MainFunctionDiagnostics */
#define CANTRCV_184_TCAN1146_MAINFUNCTIONDIAGNOSTICS_SID    (uint8)0x08

/*=============================================================================
  |                       Macros                                                |
  =============================================================================*/
/* Macro to check whether CAN Trcv is un-initialized */
#define CANTRCV_184_TCAN1146_STATE_NOT_ACTIVE           (uint8)0x00
/* Macro to check whether CAN Trcv is initialized */
#define CANTRCV_184_TCAN1146_STATE_ACTIVE               (uint8)0x01
/* Macro for wakeupreason if reason not found */
#define CANTRCV_184_TCAN1146_WU_NOT_FOUND               (uint8)0xFF

/*=============================================================================
  |                       DET ERROR CODES                                       |
  =============================================================================*/
/*DET errors*/
#define CANTRCV_184_TCAN1146_E_INVALID_TRANSCEIVER      1u
#define CANTRCV_184_TCAN1146_E_PARAM_POINTER            2u
#define CANTRCV_184_TCAN1146_E_UNINIT                  11u
#define CANTRCV_184_TCAN1146_E_TRCV_NOT_STANDBY        21u
#define CANTRCV_184_TCAN1146_E_TRCV_NOT_NORMAL         22u
#define CANTRCV_184_TCAN1146_E_PARAM_TRCV_WAKEUP_MODE  23u
#define CANTRCV_184_TCAN1146_E_PARAM_TRCV_OPMODE       24u
#define CANTRCV_184_TCAN1146_E_BAUDRATE_NOT_SUPPORTED  25u
#define CANTRCV_184_TCAN1146_E_INIT_FAILED             27u
/*Run time errors*/
#define CANTRCV_184_TCAN1146_E_NO_TRCV_CONTROL         26u

/*=============================================================================
  |                       Structures and Enums                                  |
  =============================================================================*/
/*porting from Rte_Dem_Type.h*/
typedef uint16 Dem_EventIdType;

typedef enum
{
    CANTRCV_184_TCAN1146_PN_ENABLED,
    CANTRCV_184_TCAN1146_PN_DISABLED
}
CanTrcv_184_Tcan1146_PNActivationType;

typedef enum
{
    CANTRCV_184_TCAN1146_FLAG_SET,
    CANTRCV_184_TCAN1146_FLAG_CLEARED
}
CanTrcv_184_Tcan1146_TrcvFlagStateType;

typedef enum
{
    TCAN1146_NO_STATUS_SET = 0,
    TCAN1146_WU_BY_BUS = 1,
    TCAN1146_POWER_ON = 2,
    TCAN1146_PN_CFG_FAIL = 4,
    TCAN1146_FRAME_OVF = 8,
    TCAN1146_WKERR = 16,
    TCAN1146_BUSERR = 32
}
Tcan1146StatusType;

typedef struct
{
    /* Pointer to the Operational Mode of the CAN Transceiver */
    CanTrcv_TrcvModeType OperMode;

#if (CANTRCV_184_TCAN1146_WAKEUP_SUPPORT == STD_ON)
    /* Pointer to the wakeup reason of the CAN Transceiver */
    uint8 WakeupReason;

    /* Pointer to the BusWakeUp Notification */
    CanTrcv_TrcvWakeupModeType WakeupNotiforEvent;

    /* Pointer to the BusWakeUp State */
    boolean WakeupPending;

    /* Contains all TCAN1146 Status info */
    uint8 StatusBits;
#endif
} CanTrcv_Tcan1146ChStateType;

typedef struct
{
    /* Can Id of Wakeup Frame */
    uint32 PnFrameCanId;

    /* Can Id Mask of Wakeup Frame */
    uint32 PnFrameCanIdMask;

    /* Can BaudRate in kbps */
    uint32 BaudRate;

    /* Data Length Code of Wakeup Frame */
    uint8 PnFrameDlc;

    /* Bus Error Flag Checked */
    boolean BusErrFlag;

    /* Pn Frame is Extended Frame */
    boolean PnCanIdIsExtended;

    /* Pn is enabled */
    boolean PnEnabled;

    /* Power On Reset Flag Checked */
    boolean PowerOnFlag;

    /* Pointer to Data Mask Spec */
    const uint8 *DataMask;

} CanTrcv_Tcan1146ChPnConfigType;

typedef struct
{
    /*Init State*/
    CanTrcv_TrcvModeType InitState;

    /* SPI Sequence Id */
    Spi_SequenceType SpiSequenceId;

    /* SPI Channel Id */
    Spi_ChannelType SpiChannelId;

    /* Maximum Baudrate */
    uint32 MaxBaudrate;

    /* Channel Used*/
    boolean ChannelUsed;

#if(CANTRCV_184_TCAN1146_WAKEUP_SUPPORT == STD_ON)
    /* WakeUp by Bus Support */
    boolean WakeupbyBus;

    /* Wakeup Source Id */
    EcuM_WakeupSourceType WakeupSourceId;
#if(CANTRCV_184_TCAN1146_ICU_CHANNEL_SUPPORT == STD_ON)
    /* ICU Channel support*/
    boolean IcuSupport;

    /* ICU Channel Id */
    Icu_ChannelType IcuChannelId;
#endif
    /* HW pn support*/
    boolean HwPnSupport;

    /* Power On Reset Wakeup Source Id*/
    uint32 PorWakeupSourceId;

    /* Syserr Wakeup Source Id*/
    uint32 SyserrWakeupSourceId;

    /*Partial Networking Cfg */
    const CanTrcv_Tcan1146ChPnConfigType *PnCfg;
#endif
#if(CANTRCV_184_TCAN1146_BUSERR_FLAG_SUPPORT == STD_ON)
    /* Event ID for Dem Reporting */
    Dem_EventIdType DemEventId;
#endif
}CanTrcv_Tcan1146ChConfigType;

typedef struct {
    /* Number of CAN Transceiver Channels */
    uint8 NumOfChannels;

    /* Pointer to CAN Transceiver configurations */
    const CanTrcv_Tcan1146ChConfigType *ChannelConfig;

    /* Number of SPI Retries */
    uint8 SpiCommRetries;
} CanTrcv_Tcan1146ConfigType;

extern const CanTrcv_Tcan1146ConfigType CanTrcv_184_Tcan1146_Config;

extern CanTrcv_Tcan1146ChStateType CanTrcv_184_Tcan1146_ChannelState[CANTRCV_184_TCAN1146_NUM_OF_CHANNELS];

/*=============================================================================
  |                       Function Declarations                                 |
  =============================================================================*/
#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
void CanTrcv_184_Tcan1146_Init(const CanTrcv_Tcan1146ConfigType* ConfigPtr);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
Std_ReturnType CanTrcv_184_Tcan1146_SetOpMode(uint8 Transceiver,
        CanTrcv_TrcvModeType OpMode);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
Std_ReturnType CanTrcv_184_Tcan1146_GetOpMode(uint8 Transceiver,
        CanTrcv_TrcvModeType* OpMode);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
Std_ReturnType CanTrcv_184_Tcan1146_GetBusWuReason(uint8 Transceiver,
        CanTrcv_TrcvWakeupReasonType* reason);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#if (CANTRCV_184_TCAN1146_VERSION_INFO_API == STD_ON)
#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
void CanTrcv_184_Tcan1146_GetVersionInfo(Std_VersionInfoType* versioninfo);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
#endif

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
Std_ReturnType CanTrcv_184_Tcan1146_SetWakeupMode(uint8 Transceiver,
        CanTrcv_TrcvWakeupModeType TrcvWakeupMode);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#if (CANTRCV_184_TCAN1146_HW_PN_SUPPORT == STD_ON)
#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
Std_ReturnType CanTrcv_184_Tcan1146_GetTrcvSystemData(uint8 Transceiver,
        uint32* TrcvSysData);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
Std_ReturnType CanTrcv_184_Tcan1146_ClearTrcvWufFlag(uint8 Transceiver);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
Std_ReturnType CanTrcv_184_Tcan1146_ReadTrcvTimeoutFlag(uint8 Transceiver,
        CanTrcv_184_Tcan1146_TrcvFlagStateType* FlagState);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
Std_ReturnType CanTrcv_184_Tcan1146_ClearTrcvTimeoutFlag(uint8 Transceiver);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
Std_ReturnType CanTrcv_184_Tcan1146_ReadTrcvSilenceFlag(uint8 Transceiver,
        CanTrcv_184_Tcan1146_TrcvFlagStateType* FlagState);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
#endif

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
Std_ReturnType CanTrcv_184_Tcan1146_CheckWakeup(uint8 Transceiver);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
Std_ReturnType CanTrcv_184_Tcan1146_SetPNActivationState (
        CanTrcv_184_Tcan1146_PNActivationType ActivationState);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
Std_ReturnType CanTrcv_184_Tcan1146_CheckWakeFlag(uint8 Transceiver);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
void CanTrcv_184_Tcan1146_DeInit(void);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"

#ifdef CAN_PLT_SAFERTOS_ENABLE
#define CANTRCV_184_TCAN1146_START_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
void CanTrcv_184_Tcan1146_SetOpModeToStandby(uint8 Transceiver);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1146_MemMap.h"
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */

#endif /* CANTRCV_184_TCAN1146_H */

/*=============================================================================
  |                       END OF FILE                                           |
  =============================================================================*/
