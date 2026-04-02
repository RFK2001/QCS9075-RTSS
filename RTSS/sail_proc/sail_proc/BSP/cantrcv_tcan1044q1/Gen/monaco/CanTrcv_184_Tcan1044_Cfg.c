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

/* CanTrcv TCAN1044 Pre-compile Configuration Source File */
#ifdef __cplusplus
extern "C"{
#endif

/******************************************************************************
**                          Includes                                         **
******************************************************************************/
#include "CanTrcv_184_Tcan1044_Cfg.h"
#include "CanTrcv_184_Tcan1044.h"
#ifndef CAN_PLT_SAFERTOS_ENABLE
#include "Dio_Cfg.h"
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */

/******************************************************************************
**                  Constants, Macros and Structures                         **
******************************************************************************/

#define CANTRCV_184_TCAN1044_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_184_Tcan1044_MemMap.h"
static const CanTrcv_Tcan1044ChConfigType CanTrcv_184_Tcan1044_ChConfig[]=
{
    {
        /* Init State */
        CANTRCV_TRCVMODE_STANDBY,

        /* Standby Pin */
        DIO_CHANNEL_PIN_41,

        /* Rxd Pin */
        DIO_CHANNEL_PIN_28,

        /* Maximum Baudrate */
        8000000u,

        /* Channel Used */
        TRUE,

        /* WakeUp by Bus Support */
        TRUE,

        /* Wakeup Source Id */
        32,

#if(CANTRCV_184_TCAN1044_ICU_CHANNEL_SUPPORT == STD_ON)
        /* ICU Channel support */
        TRUE,

        /* ICU Channel Id */
        10
#endif
    },
    {
        /* Init State */
        CANTRCV_TRCVMODE_STANDBY,

        /* Standby Pin */
        DIO_CHANNEL_PIN_42,

        /* Rxd Pin */
        DIO_CHANNEL_PIN_30,

        /* Maximum Baudrate */
        8000000u,

        /* Channel Used */
        TRUE,

        /* WakeUp by Bus Support */
        TRUE,

        /* Wakeup Source Id */
        32,

 #if(CANTRCV_184_TCAN1044_ICU_CHANNEL_SUPPORT == STD_ON)
        /* ICU Channel support */
        TRUE,

        /* ICU Channel Id */
        10
#endif
    },
    {
        /* Init State */
        CANTRCV_TRCVMODE_STANDBY,

        /* Standby Pin */
        DIO_CHANNEL_PIN_43,

        /* Rxd Pin */
        DIO_CHANNEL_PIN_32,

        /* Maximum Baudrate */
        8000000u,

        /* Channel Used */
        TRUE,

        /* WakeUp by Bus Support */
        TRUE,

        /* Wakeup Source Id */
        32,

#if(CANTRCV_184_TCAN1044_ICU_CHANNEL_SUPPORT == STD_ON)
        /* ICU Channel support */
        TRUE,

        /* ICU Channel Id */
        10
#endif
    }
};
#define CANTRCV_184_TCAN1044_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_184_Tcan1044_MemMap.h"

#define CANTRCV_184_TCAN1044_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_184_Tcan1044_MemMap.h"
const CanTrcv_Tcan1044ConfigType CanTrcv_184_Tcan1044_Config =
{
    /* Number of CAN Transceiver Channels */
    3u,
    
    /* Pointer to CAN Transceiver configurations */
    &CanTrcv_184_Tcan1044_ChConfig[0]
};
#define CANTRCV_184_TCAN1044_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanTrcv_184_Tcan1044_MemMap.h"

#ifdef __cplusplus
}
#endif
