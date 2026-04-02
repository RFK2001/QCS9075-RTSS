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

#ifndef TCAN1044_IF_H
#define TCAN1044_IF_H

#ifdef __cplusplus
extern "C"{
#endif

//#include "Can_SafeRTOS.h"
#include "Std_Types.h"
#include "Can_GeneralTypes.h"

Std_ReturnType CanIf_184_Tcan1044_TrcvModeIndication(uint8 CanIfTrcvid, CanTrcv_TrcvModeType OperMode);
void CanIf_184_Tcan1044_WakeupIndication(uint8 CanIfTrcvid, uint8 controller_id);



#ifdef __cplusplus
}
#endif

#endif /* CANTRCV_184_TCAN1044_SAFERTOS_H */

