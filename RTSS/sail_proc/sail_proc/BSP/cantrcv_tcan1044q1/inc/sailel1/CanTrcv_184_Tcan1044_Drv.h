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
    File Name.............. : CanTrcv_184_Tcan1044_Drv.h
    Description............ : Header file of CanTrcv_184_Tcan1044_Drv.c
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
#ifndef CANTRCV_184_TCAN1044_DRV_H
#define CANTRCV_184_TCAN1044_DRV_H

/*=============================================================================
|                       INCLUDE FILES                                         |
=============================================================================*/
#include "CanTrcv_184_Tcan1044.h"    /* CAN Transceiver TCAN1044 header file */

/*=============================================================================
|                       Function Declarations                                 |
=============================================================================*/
#define CANTRCV_184_TCAN1044_START_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"
void Tcan1044DrvSetNormalMode(const CanTrcv_Tcan1044ChConfigType *channelPtr);
#define CANTRCV_184_TCAN1044_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"

#define CANTRCV_184_TCAN1044_START_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"
void Tcan1044DrvSetStandbyMode(const CanTrcv_Tcan1044ChConfigType *channelPtr);
#define CANTRCV_184_TCAN1044_STOP_SEC_CODE
#include "CanTrcv_184_Tcan1044_MemMap.h"

#endif /* CANTRCV_184_TCAN1044_DRV_H */

/*=============================================================================
|                       END OF FILE                                           |
=============================================================================*/
