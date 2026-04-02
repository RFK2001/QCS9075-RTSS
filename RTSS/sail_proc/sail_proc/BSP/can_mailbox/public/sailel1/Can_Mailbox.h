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

#ifndef CAN_MAILBOX_H
#define CAN_MAILBOX_H
#ifdef __cplusplus
extern "C"
{
#endif
/*==============================================================================
|                       INCLUDE FILES                                          |
==============================================================================*/
/* Includes all types and constants that are shared among the
   AUTOSAR CAN modules Can and CanIf */
#include "xCanSrv.h"
/*=================================================================================================
**                                       Global variables                                         **
=================================================================================================*/

/*=================================================================================================
**                                    Global function prototypes                                 **
===================================================================================================*/
/*******************************************************************************
Function Name...... : Can_Mb_Init
Parameters (IN)... : None
Parameters (INOUT) : None
Parameters (OUT).. : None
Return Value...... : E_OK, E_NOT_OK
Description....... : This function initializes can mailbox module, registers for  
					 callback event and sends sail ready status to MD
*******************************************************************************/
Std_ReturnType Can_Mb_Init(void);

#ifdef __cplusplus
}
#endif
#endif /* CAN_MAILBOX_H */
/*==============================================================================
==============================================================================*/