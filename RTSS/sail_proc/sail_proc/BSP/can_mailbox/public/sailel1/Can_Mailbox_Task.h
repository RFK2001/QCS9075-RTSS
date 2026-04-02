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
/*==============================================================================
	File Name.............. : Can_Mailbox.h
	Description............ : This file contains functionality of CAN Mailbox
	Autosar Release Version :
	Platform............... :
	SW Release Version..... :
==============================================================================*/

#ifndef CAN_MAILBOX_TASK_H
#define CAN_MAILBOX_TASK_H
#ifdef __cplusplus
extern "C"
{
#endif
/*==============================================================================
|                       INCLUDE FILES                                          |
==============================================================================*/
/* Includes all types and constants that are shared among the
   AUTOSAR CAN modules Can and CanIf */
#include "freertos_init.h"
/*=================================================================================================
**                                       Global variables                                         **
=================================================================================================*/

/*=================================================================================================
**                                    Global function prototypes                                 **
===================================================================================================*/
BaseType_t xCanMailboxTaskInit(CPUIdType_e xSchdCore, UBaseType_t xTaskPrior);
BaseType_t xCanMailboxTaskResourceInit(CPUIdType_e xSchdCore);

#ifdef __cplusplus
}
#endif
#endif /* CAN_MAILBOX_TASK_H */
/*==============================================================================
==============================================================================*/