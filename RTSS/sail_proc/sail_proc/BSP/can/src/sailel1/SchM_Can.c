
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
#ifdef __cplusplus
extern "C"{
#endif
/*=============================================================================
|                       INCLUDE FILES                                         |
=============================================================================*/
#include "SchM_Can.h"
#ifdef CAN_PLT_SAFERTOS_ENABLE
#include "Can_SafeRTOS.h"
#endif /* End of CAN_PLT_SAFERTOS_ENABLE */

#define RTE_VENDOR_ID_C   39u
#define RTE_MODULE_ID_C   02u

#define RTE_AR_RELEASE_MAJOR_VERSION_C     4u
#define RTE_AR_RELEASE_MINOR_VERSION_C     8u
#define RTE_AR_RELEASE_REVISION_VERSION_C  0u

#define RTE_SW_MAJOR_VERSION_C     1u
#define RTE_SW_MINOR_VERSION_C     0u
#define RTE_SW_PATCH_VERSION_C     0u

#define SCHM_CAN_NUMBER_OF_AREAS   8u
/*=============================================================================
|                       LOCAL FUNCTION PROTOTYPES                             |
=============================================================================*/



/*=============================================================================
|                       LOCAL VARIABLES                                       |
=============================================================================*/

CAN_DATA static volatile uint8 SchM_Can_Entry_Counter[SCHM_CAN_NUMBER_OF_AREAS];


/*=============================================================================
|                       FUNCTION DEFINITIONS                                  |
=============================================================================*/


void SchM_Enter_Can_Exclusive_Area_00(void)
{
    SchM_Can_Entry_Counter[0]++;
}

void SchM_Exit_Can_Exclusive_Area_00(void)
{
    SchM_Can_Entry_Counter[0]--;
}


void SchM_Enter_Can_Exclusive_Area_01(void)
{
    SchM_Can_Entry_Counter[1]++;
}

void SchM_Exit_Can_Exclusive_Area_01(void)
{
    SchM_Can_Entry_Counter[1]--;
}

void SchM_Enter_Can_Exclusive_Area_02(void)
{
    SchM_Can_Entry_Counter[2]++;
}

void SchM_Exit_Can_Exclusive_Area_02(void)
{
    SchM_Can_Entry_Counter[2]--;

}

void SchM_Enter_Can_Exclusive_Area_03(void)
{
    SchM_Can_Entry_Counter[3]++;
}

void SchM_Exit_Can_Exclusive_Area_03(void)
{
    SchM_Can_Entry_Counter[3]--;

}

void SchM_Enter_Can_Exclusive_Area_04(void)
{
    SchM_Can_Entry_Counter[4]++;
}

void SchM_Exit_Can_Exclusive_Area_04(void)
{
    SchM_Can_Entry_Counter[4]--;

}
#ifdef __cplusplus
}
#endif

