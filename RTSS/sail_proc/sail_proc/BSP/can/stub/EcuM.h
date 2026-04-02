
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
#ifndef ECUM_H
#define ECUM_H

#include "EcuM_Types.h"
#include "EcuM_Cbk.h"

#ifdef __cplusplus
extern "C"{
#endif
/*=============================================================================
|                       INCLUDE FILES                                         |
=============================================================================*/


/*=============================================================================
|                       EXPORTED CONSTANTS and MACROS                         |
=============================================================================*/
/* [SWS_BSW_00059] Published information elements. */
#define ECUM_VENDOR_ID   39u
#define ECUM_MODULE_ID   10u

#define ECUM_AR_RELEASE_MAJOR_VERSION     4u
#define ECUM_AR_RELEASE_MINOR_VERSION     8u
#define ECUM_AR_RELEASE_REVISION_VERSION  0u

#define ECUM_SW_MAJOR_VERSION     1u
#define ECUM_SW_MINOR_VERSION     0u
#define ECUM_SW_PATCH_VERSION     0u

void EcuM_SetWakeupEvent(
                            EcuM_WakeupSourceType sources);

void EcuM_ClearWakeupEvent(
                            EcuM_WakeupSourceType sources);
#ifdef __cplusplus
}
#endif

#endif /* ECUM_H */

