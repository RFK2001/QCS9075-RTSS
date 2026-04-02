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
#ifndef TCAN1146_PLATFROM_CFG_H
#define TCAN1146_PLATFROM_CFG_H

#ifdef __cplusplus
extern "C"{
#endif


#include "gpio.h"
#include "gpio_direct_intr.h"
#include "gpio_summary_intr.h"


typedef struct{
    uint8  channel_id;
    uint8 controller_id;
    uint8 gpio_num;
    GPIOConfigType gpio_cfg;
    eGpioDirectIntrPolarityEdgeSel_t int_cfg;
    uGPIOINTISR int_handler;
} CanTcrv1146_Gpio_IRQ_Config_Type;


#define CAN_TCAN1146_MAX_CNT                    2u
#define CAN_TCAN1146_INVALID_PIN                0xFF

#define LEMANS_TCAN1146_CHAN_NUM                2u
#define LEMANS_TCAN1146_CHAN_0_WUP_PIN          53
#define LEMANS_TCAN1146_CHAN_1_WUP_PIN          54

#define MONACO_TCAN1146_CHAN_NUM                1u
#define MONACO_TCAN1146_CHAN_0_WUP_PIN          45

#define NORD_TCAN1146_CHAN_NUM                  2u
#define NORD_TCAN1146_CHAN_0_WUP_PIN            39
#define NORD_TCAN1146_CHAN_1_WUP_PIN            40

void CanTcrv1146_Plt_Cfg_Get_WakeUp_IRQ(uint8 channel_id,  CanTcrv1146_Gpio_IRQ_Config_Type* irq_out);
void CanTcrv1146_Plt_Cfg_Init(void);
extern CanTcrv1146_Gpio_IRQ_Config_Type CanTcrv1146_Wup_Irq_Cfg[CAN_TCAN1146_MAX_CNT];

#ifdef __cplusplus
}
#endif

#endif /* TCAN1146_PLATFROM_CFG_H */

