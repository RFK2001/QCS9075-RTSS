
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
#ifndef ECUM_CBK_H
#define ECUM_CBK_H

#ifdef __cplusplus
extern "C"{
#endif
/*=============================================================================
|                       INCLUDE FILES                                         |
=============================================================================*/

#include "EcuM.h"


/*=============================================================================
|                       EXPORTED STRUCTURES, ENUMS, TYPEDEFS                  |
=============================================================================*/



/*=============================================================================
|                       EXPORTED FUNCTIONS                                    |
=============================================================================*/

extern void EcuM_CheckWakeup(
                        EcuM_WakeupSourceType wakeupSource);
extern void EcuM_SetWakeupEvent(
                            EcuM_WakeupSourceType sources);
extern void EcuM_ClearWakeupEvent(
                            EcuM_WakeupSourceType sources);


/*=============================================================================
|                       EXPORTED VARIABLES                                    |
=============================================================================*/

extern EcuM_WakeupSourceType EcuM_WakeupSource;



#ifdef __cplusplus
}
#endif

#endif /* ECUM_CBK_H */

