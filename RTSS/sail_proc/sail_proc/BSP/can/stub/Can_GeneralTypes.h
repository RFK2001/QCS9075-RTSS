/*
===========================================================================
*/
/**
    @file  pmic.c
    @brief Contain All top level function of PMIC driver

*/
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
|                       MISRA-C VIOLATIONS                                    |
=============================================================================*/
/* 
JUSTIFICATION_1: <.........>
*/

#ifndef CAN_GENERAL_TYPES_H
#define CAN_GENERAL_TYPES_H

#ifdef __cplusplus
extern "C"{
#endif
/*=============================================================================
|                       INCLUDE FILES                                         |
=============================================================================*/
#include "ComStack_Types.h"


/*=============================================================================
|                       EXPORTED CONSTANTS and MACROS                         |
=============================================================================*/
/* [SWS_BSW_00059] Published information elements. */
#ifndef CAN_AR_RELEASE_MAJOR_VERSION
#define CAN_VENDOR_ID   184u
#define CAN_MODULE_ID   80u

#define CAN_AR_RELEASE_MAJOR_VERSION     4u
#define CAN_AR_RELEASE_MINOR_VERSION     8u
#define CAN_AR_RELEASE_REVISION_VERSION  0u
#endif

#define CAN_SW_MAJOR_VERSION_GT     1u
#define CAN_SW_MINOR_VERSION_GT     0u
#define CAN_SW_PATCH_VERSION_GT     0u



/*=============================================================================
|                       EXPORTED STRUCTURES, ENUMS, TYPEDEFS                  |
=============================================================================*/
/* [SWS_Can_00429] */
typedef uint16 Can_HwHandleType;

/* [SWS_Can_00416] */
typedef uint32 Can_IdType;

/* [SWS_CAN_00496] */
typedef struct
{
    Can_IdType CanId;
    Can_HwHandleType Hoh;
    uint8 ControllerId;
}Can_HwType;

/* [SWS_Can_00415] */
typedef struct
{
    PduIdType swPduHandle;
    uint8 length;
    Can_IdType id;
    uint8* sdu;
}Can_PduType;

/* [SWS_CAN_91029]{DRAFT} */
typedef struct
{
    uint32 nanoseconds;
    uint32 seconds;
}Can_TimeStampType;

/* [SWS_Can_00039] */
typedef enum
{
    CAN_OK,
    CAN_NOT_OK,
    CAN_BUSY
}Can_ReturnType;

/* [SWS_Can_91003] */
typedef enum
{
    CAN_ERRORSTATE_ACTIVE = 0u,
    CAN_ERRORSTATE_PASSIVE,
    CAN_ERRORSTATE_BUSOFF
}Can_ErrorStateType;

/* [SWS_Can_91013] */
typedef enum
{
    CAN_CS_UNINIT = 0u,
    CAN_CS_STARTED,
    CAN_CS_STOPPED,
    CAN_CS_SLEEP
}Can_ControllerStateType;

/* [SWS_Can_91021] */
typedef enum
{
    CAN_ERROR_BIT_MONITORING1 = 1u,
    CAN_ERROR_BIT_MONITORING0,
    CAN_ERROR_BIT,
    CAN_ERROR_CHECK_ACK_FAILED,
    CAN_ERROR_ACK_DELIMITER,
    CAN_ERROR_ARBITRATION_LOST,
    CAN_ERROR_OVERLOAD,
    CAN_ERROR_CHECK_FORM_FAILED,
    CAN_ERROR_CHECK_STUFFING_FAILED,
    CAN_ERROR_CHECK_CRC_FAILED,
    CAN_ERROR_BUS_LOCK
}Can_ErrorType;

/* [SWS_CanTrcv_00163] */
typedef enum
{
    CANTRCV_TRCVMODE_NORMAL = 0u,
    CANTRCV_TRCVMODE_STANDBY,
    CANTRCV_TRCVMODE_SLEEP
}CanTrcv_TrcvModeType;

/* [SWS_CanTrcv_00164] */
typedef enum
{
    CANTRCV_WUMODE_ENABLE = 0u,
    CANTRCV_WUMODE_DISABLE,
    CANTRCV_WUMODE_CLEAR
}CanTrcv_TrcvWakeupModeType;

/* [SWS_CanTrcv_00165] */
typedef enum
{
    CANTRCV_WU_ERROR = 0u,
    CANTRCV_WU_NOT_SUPPORTED,
    CANTRCV_WU_BY_BUS,
    CANTRCV_WU_INTERNALLY,
    CANTRCV_WU_RESET,
    CANTRCV_WU_POWER_ON,
    CANTRCV_WU_BY_PIN,
    CANTRCV_WU_BY_SYSERR
}CanTrcv_TrcvWakeupReasonType;

/*=============================================================================
|                       EXPORTED FUNCTIONS                                    |
=============================================================================*/



/*=============================================================================
|                       EXPORTED VARIABLES                                    |
=============================================================================*/



/*=============================================================================
|                       VERSION CHECK                                         |
=============================================================================*/
/* [SWS_BSW_00036] Inter module version check. */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
#if ((CAN_AR_RELEASE_MAJOR_VERSION != COMSTACKTYPE_AR_MAJOR_VERSION)     || \
     (CAN_AR_RELEASE_MINOR_VERSION != COMSTACKTYPE_AR_MINOR_VERSION))
    //#error "Autosar version numbers of Can_GeneralTypes.h and ComStack_Types.h \
are different."
#endif
#endif


#ifdef __cplusplus
}
#endif

#endif /* CAN_GENERAL_TYPES_H */

