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

/* CanTrcv TCAN1044 Pre-compile Configuration Header File */
#ifndef CANTRCV_184_TCAN1044_CFG_H
#define CANTRCV_184_TCAN1044_CFG_H

/******************************************************************************
**                          Include Files                                    **
******************************************************************************/

/******************************************************************************
**                          Version Information                              **
******************************************************************************/
/* AUTOSAR Specification Version Information */
#define CANTRCV_184_TCAN1044_AR_RELEASE_MAJOR_VERSION_CFG_H      4
#define CANTRCV_184_TCAN1044_AR_RELEASE_MINOR_VERSION_CFG_H      8
#define CANTRCV_184_TCAN1044_AR_RELEASE_REVISION_VERSION_CFG_H   0

/* Software Version Information */
#define CANTRCV_184_TCAN1044_SW_MAJOR_VERSION_CFG_H    1
#define CANTRCV_184_TCAN1044_SW_MINOR_VERSION_CFG_H    1
#define CANTRCV_184_TCAN1044_SW_PATCH_VERSION_CFG_H    0

/******************************************************************************
**                              Macros                                       **
******************************************************************************/

#define CAN_PLT_SAFERTOS_ENABLE

#define CANTRCV_184_TCAN1044_DEV_ERROR_DETECT          STD_ON

#define CANTRCV_184_TCAN1044_CFG_PRE_COMPILE           STD_ON

#define CANTRCV_184_TCAN1044_CFG_POST_BUILD            STD_OFF

#define CANTRCV_184_TCAN1044_WAKEUP_SUPPORT            STD_ON

#define CANTRCV_184_TCAN1044_HW_PN_SUPPORT             STD_OFF

#ifndef CAN_PLT_SAFERTOS_ENABLE
#define CANTRCV_184_TCAN1044_ICU_CHANNEL_SUPPORT       STD_ON
#else
#define CANTRCV_184_TCAN1044_ICU_CHANNEL_SUPPORT       STD_OFF
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */

#define CANTRCV_184_TCAN1044_INSTANCE_ID               1u

#define CANTRCV_184_TCAN1044_NUM_OF_CHANNELS           3u

#define CANTRCV_184_TCAN1044_VERSION_INFO_API          STD_ON

#ifndef CAN_PLT_SAFERTOS_ENABLE
#define CANTRCV_184_TCAN1044_WAITTIME_IN_US            20u
#else
#define CANTRCV_184_TCAN1044_DELAY_IN_MS               1u           
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */

#define CANTRCV_184_TCAN1044_1US16BIT_TIMER_SUPPORT    STD_ON

#ifdef CAN_PLT_SAFERTOS_ENABLE
#define DIO_CHANNEL_PIN_28   28u
#define DIO_CHANNEL_PIN_30   30u
#define DIO_CHANNEL_PIN_32   32u
#define DIO_CHANNEL_PIN_41   41u
#define DIO_CHANNEL_PIN_42   42u
#define DIO_CHANNEL_PIN_43   43u
#define DIO_CHANNEL_PIN_44   44u
#define DIO_CHANNEL_PIN_46   46u
#define DIO_CHANNEL_PIN_55   55u
#define DIO_CHANNEL_PIN_56   56u
#define DIO_CHANNEL_PIN_57   57u
#endif

#endif
