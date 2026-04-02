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

#include "Clock.h"
#include "ClockDefs.h"
#include "types.h"
#include "chipinfo.h"
#include "CanTrcv_184_Tcan1044_Plt_Cfg.h"
#include "CanTrcv_184_Tcan1044_SafeRTOS.h"
#include "CanTrcv_184_Tcan1044_Irq.h"

CAN_DATA static CanTcrv1044_Gpio_Pin_Type CanTcrv1044_Stb_Gpio_Cfg[CAN_TCAN1044_MAX_CNT] = {0};
CAN_DATA static CanTcrv1044_Gpio_Pin_Type CanTcrv1044_Wup_Gpio_Cfg[CAN_TCAN1044_MAX_CNT] = {0};
CAN_DATA CanTcrv1044_Gpio_IRQ_Config_Type CanTcrv1044_Wup_Irq_Cfg[CAN_TCAN1044_MAX_CNT] = {0};

/*===========================================================================
**  Function :  CanTcrv1044_Cfg_Standby_Gpio_Init
**  This function is to fill the config table of standby pin
** ==========================================================================
*/
static void CanTcrv1044_Cfg_Standby_Gpio_Init(ChipInfoFamilyType chip_family)
{
    uint8_t tcan1044_max_inst = 0u;
	
	if (chip_family == CHIPINFO_FAMILY_LEMANSAU)
	{
	    tcan1044_max_inst = LEMANS_TCAN1044_CHAN_NUM;
	    CanTcrv1044_Stb_Gpio_Cfg[0].gpio_num = (uint32_t)LEMANS_TCAN1044_CHAN_0_STB_PIN;
	    CanTcrv1044_Stb_Gpio_Cfg[1].gpio_num = (uint32_t)LEMANS_TCAN1044_CHAN_1_STB_PIN;
	    CanTcrv1044_Stb_Gpio_Cfg[2].gpio_num = (uint32_t)LEMANS_TCAN1044_CHAN_2_STB_PIN;
	}
	else if (chip_family == CHIPINFO_FAMILY_MONACOAU)
	{
		tcan1044_max_inst = MONACO_TCAN1044_CHAN_NUM;
	    CanTcrv1044_Stb_Gpio_Cfg[0].gpio_num = (uint32_t)MONACO_TCAN1044_CHAN_0_STB_PIN;
	}
	else
	{
	    tcan1044_max_inst = NORD_TCAN1044_CHAN_NUM;
	    CanTcrv1044_Stb_Gpio_Cfg[0].gpio_num = (uint32_t)NORD_TCAN1044_CHAN_0_STB_PIN;
	    CanTcrv1044_Stb_Gpio_Cfg[1].gpio_num = (uint32_t)NORD_TCAN1044_CHAN_1_STB_PIN;
	    CanTcrv1044_Stb_Gpio_Cfg[2].gpio_num = (uint32_t)NORD_TCAN1044_CHAN_2_STB_PIN;
	}

    for (uint8_t i = 0; i < tcan1044_max_inst; i++)
    {
        CanTcrv1044_Stb_Gpio_Cfg[i].gpio_cfg.func    = 0;
        CanTcrv1044_Stb_Gpio_Cfg[i].gpio_cfg.dir     = GPIO_OUT;
        CanTcrv1044_Stb_Gpio_Cfg[i].gpio_cfg.pull    = GPIO_PU;
        CanTcrv1044_Stb_Gpio_Cfg[i].gpio_cfg.drive   = GPIO_8MA;
    }
}

/*===========================================================================
**  Function :  CanTcrv1044_Cfg_WakeUp_Gpio_Init
**  This function is to fill the config table of wake up pin
** ==========================================================================
*/
static void CanTcrv1044_Cfg_WakeUp_Gpio_Init(ChipInfoFamilyType chip_family)
{
    uint8_t tcan1044_max_inst = 0u;
	
	if (chip_family == CHIPINFO_FAMILY_LEMANSAU)
	{
	    tcan1044_max_inst = LEMANS_TCAN1044_CHAN_NUM;
	    CanTcrv1044_Wup_Gpio_Cfg[0].gpio_num = (uint32_t)LEMANS_TCAN1044_CHAN_0_WUP_PIN;
	    CanTcrv1044_Wup_Gpio_Cfg[1].gpio_num = (uint32_t)LEMANS_TCAN1044_CHAN_1_WUP_PIN;
	    CanTcrv1044_Wup_Gpio_Cfg[2].gpio_num = (uint32_t)LEMANS_TCAN1044_CHAN_2_WUP_PIN;
	}
	else if(chip_family == CHIPINFO_FAMILY_MONACOAU)
	{
		CanTcrv1044_Wup_Gpio_Cfg[0].gpio_num = (uint32_t)MONACO_TCAN1044_CHAN_0_WUP_PIN;
	}
	else
	{
	    tcan1044_max_inst = NORD_TCAN1044_CHAN_NUM;
	    CanTcrv1044_Wup_Gpio_Cfg[0].gpio_num = (uint32_t)NORD_TCAN1044_CHAN_0_WUP_PIN;
	    CanTcrv1044_Wup_Gpio_Cfg[1].gpio_num = (uint32_t)NORD_TCAN1044_CHAN_1_WUP_PIN;
	    CanTcrv1044_Wup_Gpio_Cfg[2].gpio_num = (uint32_t)NORD_TCAN1044_CHAN_2_WUP_PIN;
	}

    for (uint8_t i = 0; i < tcan1044_max_inst; i++)
    {
        CanTcrv1044_Wup_Gpio_Cfg[i].gpio_cfg.func   = 0;
        CanTcrv1044_Wup_Gpio_Cfg[i].gpio_cfg.dir    = GPIO_IN;
        CanTcrv1044_Wup_Gpio_Cfg[i].gpio_cfg.pull   = GPIO_PU;
        CanTcrv1044_Wup_Gpio_Cfg[i].gpio_cfg.drive  = GPIO_2MA;
    }
}

/*===========================================================================
**  Function :  CanTcrv1044_Cfg_WakeUp_IRQ_Init
**  This function is to initialize wake up IRQ configuration
** ==========================================================================
*/
static void CanTcrv1044_Cfg_WakeUp_IRQ_Init(ChipInfoFamilyType chip_family)
{
    uint8_t tcan1044_max_inst = 0u;
	
	if (chip_family == CHIPINFO_FAMILY_LEMANSAU)
	{
	    tcan1044_max_inst = LEMANS_TCAN1044_CHAN_NUM;
	    CanTcrv1044_Wup_Irq_Cfg[0].gpio_num = (uint32_t)LEMANS_TCAN1044_CHAN_0_WUP_PIN;
	    CanTcrv1044_Wup_Irq_Cfg[1].gpio_num = (uint32_t)LEMANS_TCAN1044_CHAN_1_WUP_PIN;
	    CanTcrv1044_Wup_Irq_Cfg[2].gpio_num = (uint32_t)LEMANS_TCAN1044_CHAN_2_WUP_PIN;

		CanTcrv1044_Wup_Irq_Cfg[0].controller_id = 2;
		CanTcrv1044_Wup_Irq_Cfg[1].controller_id = 3;
		CanTcrv1044_Wup_Irq_Cfg[2].controller_id = 4;

        CanTcrv1044_Wup_Irq_Cfg[0].int_handler = CANTRCV1044_CHANNEL_ISR;
        CanTcrv1044_Wup_Irq_Cfg[1].int_handler = CANTRCV1044_CHANNEL_ISR;
        CanTcrv1044_Wup_Irq_Cfg[2].int_handler = CANTRCV1044_CHANNEL_ISR;
	}
	else if (chip_family == CHIPINFO_FAMILY_MONACOAU)
	{
		 tcan1044_max_inst = MONACO_TCAN1044_CHAN_NUM;
		 CanTcrv1044_Wup_Irq_Cfg[0].gpio_num = (uint32_t)MONACO_TCAN1044_CHAN_0_WUP_PIN;
		 CanTcrv1044_Wup_Irq_Cfg[0].controller_id = 3;
		 CanTcrv1044_Wup_Irq_Cfg[0].int_handler = CANTRCV1044_CHANNEL_ISR;
	}
	else
	{
	    tcan1044_max_inst = NORD_TCAN1044_CHAN_NUM;
	    CanTcrv1044_Wup_Irq_Cfg[0].gpio_num = (uint32_t)NORD_TCAN1044_CHAN_0_WUP_PIN;
	    CanTcrv1044_Wup_Irq_Cfg[1].gpio_num = (uint32_t)NORD_TCAN1044_CHAN_1_WUP_PIN;
	    CanTcrv1044_Wup_Irq_Cfg[2].gpio_num = (uint32_t)NORD_TCAN1044_CHAN_2_WUP_PIN;

		CanTcrv1044_Wup_Irq_Cfg[0].controller_id = 2;
		CanTcrv1044_Wup_Irq_Cfg[1].controller_id = 3;
		CanTcrv1044_Wup_Irq_Cfg[2].controller_id = 4;

        CanTcrv1044_Wup_Irq_Cfg[0].int_handler = CANTRCV1044_CHANNEL_ISR;
        CanTcrv1044_Wup_Irq_Cfg[1].int_handler = CANTRCV1044_CHANNEL_ISR;
        CanTcrv1044_Wup_Irq_Cfg[2].int_handler = CANTRCV1044_CHANNEL_ISR;
	}
	
    for (uint8_t i = 0; i < tcan1044_max_inst; i++)
    {
        CanTcrv1044_Wup_Irq_Cfg[i].channel_id = (uint8)i;
		CanTcrv1044_Wup_Irq_Cfg[i].int_cfg = SAIL_GPIO_TRIGGER_FALLING_EDGE;
    }
}

void CanTcrv1044_Plt_Cfg_Get_Standby_Gpio(uint8 channel_id,  CanTcrv1044_Gpio_Pin_Type* gpio_cfg)
{
    *gpio_cfg = CanTcrv1044_Stb_Gpio_Cfg[channel_id];
}
void CanTcrv1044_Plt_Cfg_Get_WakeUp_Gpio(uint8 channel_id,  CanTcrv1044_Gpio_Pin_Type* gpio_cfg)
{
    *gpio_cfg = CanTcrv1044_Wup_Gpio_Cfg[channel_id];
}

void CanTcrv1044_Plt_Cfg_Get_WakeUp_IRQ(uint8 channel_id,  CanTcrv1044_Gpio_IRQ_Config_Type* irq_out)
{
    *irq_out = CanTcrv1044_Wup_Irq_Cfg[channel_id];
}

void CanTcrv1044_Plt_Cfg_Init(void)
{
	ChipInfoFamilyType chip_family = CHIPINFO_FAMILY_32BITS;
    #if defined(CHIPINFO_FAMILY_LEMANS)
    chip_family = CHIPINFO_FAMILY_LEMANSAU;
    #elif defined(CHIPINFO_FAMILY_MONACO)
    chip_family = CHIPINFO_FAMILY_MONACOAU;
    #endif

    CanTcrv1044_Cfg_Standby_Gpio_Init(chip_family);
    CanTcrv1044_Cfg_WakeUp_Gpio_Init(chip_family);
    CanTcrv1044_Cfg_WakeUp_IRQ_Init(chip_family);
}

