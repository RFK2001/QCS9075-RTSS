

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
#ifndef SCHM_CAN_H
#define SCHM_CAN_H

#ifdef __cplusplus
extern "C"{
#endif
/*=============================================================================
|                       INCLUDE FILES                                         |
=============================================================================*/
#include "Std_Types.h"


/*=============================================================================
|                       EXPORTED CONSTANTS and MACROS                         |
=============================================================================*/



/*=============================================================================
|                       EXPORTED STRUCTURES, ENUMS, TYPEDEFS                  |
=============================================================================*/



/*=============================================================================
|                       EXPORTED FUNCTIONS                                    |
=============================================================================*/
/* MISRA RULE 5.02/5.04 VIOLATION: JUSTIFICATION_2 */

extern void SchM_Enter_Can_Exclusive_Area_00(void);
extern void SchM_Enter_Can_Exclusive_Area_01(void);
extern void SchM_Enter_Can_Exclusive_Area_02(void);
extern void SchM_Enter_Can_Exclusive_Area_03(void);
extern void SchM_Enter_Can_Exclusive_Area_04(void);


extern void SchM_Exit_Can_Exclusive_Area_00(void);
extern void SchM_Exit_Can_Exclusive_Area_01(void);
extern void SchM_Exit_Can_Exclusive_Area_02(void);
extern void SchM_Exit_Can_Exclusive_Area_03(void);
extern void SchM_Exit_Can_Exclusive_Area_04(void);


#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_MainFunction_Write(void);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_MainFunction_Read(void);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_MainFunction_Mode(void);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_MainFunction_BusOff(void);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void Can_MainFunction_Wakeup(void);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void CanFusa_MainFunction_CfgCheck(void);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
#define CAN_START_SEC_CODE_ASIL_B
#include "Can_MemMap.h"
extern void CanFusa_MainFunction_HM(void);
#define CAN_STOP_SEC_CODE_ASIL_B
#include "Can_MemMap.h"

/*=============================================================================
|                       EXPORTED VARIABLES                                    |
=============================================================================*/



/*=============================================================================
|                       VERSION CHECK                                         |
=============================================================================*/




#ifdef __cplusplus
}
#endif

#endif /* SCHM_CAN_H */

