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

#include "CanTrcv_184_Tcan1146.h"
#include "CanTrcv_184_Tcan1146_Irq.h"
#include "CanTrcv_184_Tcan1146_Plt_Cfg.h"
#include "CanTrcv_184_Tcan1146_SafeRTOS.h"
#include "CanTrcv_184_Tcan1146_If.h"
#include "types.h"
#include "interrupts.h"
void CANTRCV1146_COMMON_ISR_CB(void * arg)
{
    uint8 channel_id = ((CanTcrv1146_Gpio_IRQ_Config_Type *)arg)->channel_id;
    uint8 controller_id = ((CanTcrv1146_Gpio_IRQ_Config_Type *)arg)->controller_id;
    CanTrcv_184_Tcan1146_Wakeup_IRQ_Disable(channel_id);
    CanTrcv_184_Tcan1146_SetOpModeToStandby(channel_id);
    CanIf_184_Tcan1146_WakeupIndication(channel_id, controller_id);
}

void CANTRCV1146_COMMON_ISR(void * arg)
{

	CANTRCV1146_COMMON_ISR_CB( arg );

}



