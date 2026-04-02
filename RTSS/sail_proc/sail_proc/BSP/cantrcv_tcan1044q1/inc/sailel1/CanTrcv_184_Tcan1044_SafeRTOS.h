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

#ifndef CANTRCV_184_TCAN1044_SAFERTOS_H
#define CANTRCV_184_TCAN1044_SAFERTOS_H

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
|                       Function Declarations                                 |
=============================================================================*/
void CanTrcv_184_Tcan1044_Config_Standby_Gpio(uint8 channel_id);
void CanTrcv_184_Tcan1044_Config_Wakeup_Gpio(uint8 channel_id);
void CanTrcv_184_Tcan1044_Register_WakeUp_IRQ(uint8 channel_id);
void CanTrcv_184_Tcan1044_Deregister_WakeUp_IRQ(uint8 channel_id);
void CanTrcv_184_Tcan1044_WakeUp_IRQ_Enable(uint8 channel_id);
void CanTrcv_184_Tcan1044_Wakeup_IRQ_Disable(uint8 channel_id);

/*=============================================================================
|                       EXPORTED FUNCTIONS                                    |
=============================================================================*/
/* MISRA RULE 5.02/5.04 VIOLATION: JUSTIFICATION_2 */

extern Std_ReturnType Det_ReportError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);
extern Std_ReturnType Can_Safertos_Config_Gpio(uint8 ControllerId);


/*=============================================================================
|                       EXPORTED VARIABLES                                    |
=============================================================================*/



/*=============================================================================
|                       VERSION CHECK                                         |
=============================================================================*/




#ifdef __cplusplus
}
#endif

#endif /* CANTRCV_184_TCAN1044_SAFERTOS_H */

