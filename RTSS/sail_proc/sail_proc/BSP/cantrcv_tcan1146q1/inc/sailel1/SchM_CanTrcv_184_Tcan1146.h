
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
#ifndef SCHM_CANTRCV_184_TCAN1146_H
#define SCHM_CANTRCV_184_TCAN1146_H

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

extern void SchM_Enter_CanTrcv_184_Tcan1146_Exclusive_Area(void);
extern void SchM_Exit_CanTrcv_184_Tcan1146_Exclusive_Area(void);

#define CANTRCV_184_TCAN1146_START_SEC_CODE_FAST
#include "CanTrcv_184_Tcan1146_MemMap.h"
extern void CanTrcv_184_Tcan1146_MainFunction(void);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE_FAST
#include "CanTrcv_184_Tcan1146_MemMap.h"

#define CANTRCV_184_TCAN1146_START_SEC_CODE_FAST
#include "CanTrcv_184_Tcan1146_MemMap.h"
extern void CanTrcv_184_Tcan1146_MainFunctionDiagnostics(void);
#define CANTRCV_184_TCAN1146_STOP_SEC_CODE_FAST
#include "CanTrcv_184_Tcan1146_MemMap.h"

/*=============================================================================
|                       EXPORTED VARIABLES                                    |
=============================================================================*/



/*=============================================================================
|                       VERSION CHECK                                         |
=============================================================================*/




#ifdef __cplusplus
}
#endif

#endif /* SCHM_CANTRCV_184_TCAN1146_H */

