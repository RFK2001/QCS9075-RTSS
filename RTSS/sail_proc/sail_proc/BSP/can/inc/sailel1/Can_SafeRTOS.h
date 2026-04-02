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
/* Can Driver Configuration Header file */
/******************************************************************************/
/**
* AUTOMATICALLY GENERATED FILE. DO NOT EDIT.   
* GENERATED ON : Fri May 24 15:21:00 IST 2024           
* 
* file: Can_Drv_Cfg.c
*
* Description: This is a CAN driver configuration Header file for Lemans sprcific
*
* <pre>
*
* MODIFICATION HISTORY:
*
* Ver   Who     Date       Changes
* ----- ----    --------   ----------------------------------------------------
* 1.0.0 Yingjie 12/6/2024  First release.

* </pre>
*
*******************************************************************************/
#ifndef CAN_DRV_CFG_H
#define CAN_DRV_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*==============================================================================
|                       INCLUDE FILES                                          |
==============================================================================*/

#include "FreeRTOSOsal.h"
#include "freertos_init.h"
#include "gpio.h"
#include "Clock.h"
#include "ClockDefs.h"
#include "debug_log.h"
#include "types.h"
//#include "fusa.h"
#include "Std_Types.h"
/*==============================================================================
|                       EXPORTED CONSTANTS and MACROS                          |
==============================================================================*/

#define NUM_CLOCKS_PER_CAN_CONTROLLER		2u
#define NUM_GPIO_PER_CAN_CONTROLLER 		2u
#define NUM_IRQ_PER_CAN_CONTROLLER		    9u

/*==============================================================================
|                       EXPORTED STRUCTURES, ENUMS, TYPEDEFS                   |
==============================================================================*/

typedef enum
{
  CAN_TCAN1146_MAPPED,
  CAN_TCAN1044_MAPPED,
  CAN_NO_TRCV
} CAN_TRCV_MAP_Type;

/*==============================================================================
|                       EXPORTED FUNCTIONS                                     |
==============================================================================*/
Std_ReturnType Can_Safertos_Interrupt_Register(uint8 ControllerId);
Std_ReturnType Can_Safertos_Interrupt_Deregister(uint8 ControllerId);
Std_ReturnType Can_Safertos_Enable_Clock(uint8 ControllerId);
Std_ReturnType Can_Safertos_Disable_Clock(uint8 ControllerId);
Std_ReturnType Can_Safertos_Config_Gpio(uint8 ControllerId);
void Can_Safertos_Get_TransceiverId_For_Can(uint8 ControllerId, CAN_TRCV_MAP_Type* trcv_type, uint8* trcv_channel_id);

Std_ReturnType Det_ReportError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);
Std_ReturnType Det_ReportRuntimeError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);


/*==============================================================================
|                       EXPORTED VARIABLES                                     |
==============================================================================*/


#ifdef __cplusplus
}
#endif

#endif
/*******************************************************************************
**                         End of File                                        **
*******************************************************************************/

