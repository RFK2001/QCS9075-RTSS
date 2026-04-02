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

#ifndef TCAN1044_PLATFROM_CFG_H
#define TCAN1044_PLATFROM_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

#include "gpio.h"
#include "gpio_direct_intr.h"
#include "gpio_summary_intr.h"

#define CAN_TCAN1044_MAX_CNT                    3u
#define CAN_TCAN1044_INVALID_PIN                0xFF
    
#define LEMANS_TCAN1044_CHAN_NUM                3u
#define LEMANS_TCAN1044_CHAN_0_STB_PIN          55
#define LEMANS_TCAN1044_CHAN_1_STB_PIN          56
#define LEMANS_TCAN1044_CHAN_2_STB_PIN          57
#define LEMANS_TCAN1044_CHAN_0_WUP_PIN          42
#define LEMANS_TCAN1044_CHAN_1_WUP_PIN          44
#define LEMANS_TCAN1044_CHAN_2_WUP_PIN          46

#define MONACO_TCAN1044_CHAN_NUM                1u
#define MONACO_TCAN1044_CHAN_0_STB_PIN   		46
#define MONACO_TCAN1044_CHAN_0_WUP_PIN          44

#define NORD_TCAN1044_CHAN_NUM                  3u
#define NORD_TCAN1044_CHAN_0_STB_PIN            41
#define NORD_TCAN1044_CHAN_1_STB_PIN            42
#define NORD_TCAN1044_CHAN_2_STB_PIN            43
#define NORD_TCAN1044_CHAN_0_WUP_PIN            28
#define NORD_TCAN1044_CHAN_1_WUP_PIN            30
#define NORD_TCAN1044_CHAN_2_WUP_PIN            32

typedef struct
{
    uint32_t        gpio_num;
    GPIOConfigType  gpio_cfg;
}CanTcrv1044_Gpio_Pin_Type;

typedef struct{
    uint8  channel_id;
    uint8  controller_id;
    uint32_t gpio_num;
    eGpioDirectIntrPolarityEdgeSel_t int_cfg;
    uGPIOINTISR int_handler;
} CanTcrv1044_Gpio_IRQ_Config_Type;

void CanTcrv1044_Plt_Cfg_Get_WakeUp_IRQ(uint8 channel_id,  CanTcrv1044_Gpio_IRQ_Config_Type* irq_out);
void CanTcrv1044_Plt_Cfg_Get_Standby_Gpio(uint8 channel_id,  CanTcrv1044_Gpio_Pin_Type* gpio_cfg);
void CanTcrv1044_Plt_Cfg_Get_WakeUp_Gpio(uint8 channel_id,  CanTcrv1044_Gpio_Pin_Type* gpio_cfg);
void CanTcrv1044_Plt_Cfg_Init(void);


extern CanTcrv1044_Gpio_IRQ_Config_Type CanTcrv1044_Wup_Irq_Cfg[CAN_TCAN1044_MAX_CNT];;

#ifdef __cplusplus
}
#endif

#endif /* TCAN1044_PLATFROM_CFG_H */

