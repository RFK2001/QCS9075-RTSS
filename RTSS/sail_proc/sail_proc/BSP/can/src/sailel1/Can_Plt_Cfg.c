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
#include "Can_Plt_Cfg.h"
#include "Can_SafeRTOS.h"
#include "chipinfo.h"
#include "Can_Drv.h"
#include "Can_Irq.h"

/* CAN configurations */
CAN_DATA static Can_Gpio_Pin_Type CAN_WUP_Gpio_Cfg[CAN_MTTCAN_MAX_CNT] = {0};
CAN_DATA static Can_IRQ_Config_Type Can_Irq_Cfg[CAN_MTTCAN_MAX_CNT*NUM_IRQ_PER_CAN_CONTROLLER] = {0};
CAN_DATA static Can_Gpio_Pin_Type Can_Gpio_Cfg[CAN_MTTCAN_MAX_CNT*NUM_GPIO_PER_CAN_CONTROLLER] = {0};
CAN_DATA static CAN_MTTCAN_ClockType Can_Clk_Cfg[CAN_MTTCAN_MAX_CNT*NUM_CLOCKS_PER_CAN_CONTROLLER] = {0};

/* CAN TRCV Mapping */ 
CAN_DATA static uint8_t Can_Tcan1146_Map[CAN_MTTCAN_MAX_CNT] = {0};
CAN_DATA static uint8_t Can_Tcan1044_Map[CAN_MTTCAN_MAX_CNT] = {0};


static uint32_t Can_Plt_Cfg_Max_Supported_Instance(ChipInfoFamilyType chip_family)
{
    uint32_t MAX_CAN_CNT = 0;

	if (chip_family == CHIPINFO_FAMILY_LEMANSAU)
	{
        MAX_CAN_CNT = NUMBER_OF_ACTIVE_CAN_CTRL;
	}
    else if (chip_family == CHIPINFO_FAMILY_MONACOAU)
	{
        MAX_CAN_CNT = NUMBER_OF_ACTIVE_CAN_CTRL;
	}
    else if (chip_family == CHIPINFO_FAMILY_NORDAU)
	{
        MAX_CAN_CNT = NUMBER_OF_ACTIVE_CAN_CTRL;
	}
    else
    {

    }

    return MAX_CAN_CNT;
}

/*===========================================================================
**  Function :  Can_WakeUp_GPIOTable_Init
**  This function is to initialize wakeup GPIO configuration
** ==========================================================================
*/
static void Can_Plt_Cfg_Trcv_Map_Init(ChipInfoFamilyType chip_family)
{
    uint32 i = 0;
	uint32_t can_max_inst = Can_Plt_Cfg_Max_Supported_Instance(chip_family);

	if (chip_family == CHIPINFO_FAMILY_LEMANSAU)
	{
	    Can_Tcan1146_Map[0] = CAN_TCAN1146_CHAN_0;
        Can_Tcan1146_Map[1] = CAN_TCAN1146_CHAN_1;
        Can_Tcan1146_Map[2] = CAN_TCAN_INVALID;
        Can_Tcan1146_Map[3] = CAN_TCAN_INVALID;
        Can_Tcan1146_Map[4] = CAN_TCAN_INVALID;
        Can_Tcan1146_Map[5] = CAN_TCAN_INVALID;
        Can_Tcan1146_Map[6] = CAN_TCAN_INVALID;
        Can_Tcan1146_Map[7] = CAN_TCAN_INVALID;
        
        Can_Tcan1044_Map[0] = CAN_TCAN_INVALID;
        Can_Tcan1044_Map[1] = CAN_TCAN_INVALID;
        Can_Tcan1044_Map[2] = CAN_TCAN1044_CHAN_0;
        Can_Tcan1044_Map[3] = CAN_TCAN1044_CHAN_1;
        Can_Tcan1044_Map[4] = CAN_TCAN1044_CHAN_2;
        Can_Tcan1044_Map[5] = CAN_TCAN_INVALID;
        Can_Tcan1044_Map[6] = CAN_TCAN_INVALID;
        Can_Tcan1044_Map[7] = CAN_TCAN_INVALID;
	}
	else if (chip_family == CHIPINFO_FAMILY_MONACOAU)
	{
	    Can_Tcan1146_Map[0] = CAN_TCAN1146_CHAN_0;
        Can_Tcan1146_Map[1] = CAN_TCAN_INVALID;
        Can_Tcan1146_Map[2] = CAN_TCAN_INVALID;
        Can_Tcan1146_Map[3] = CAN_TCAN_INVALID;
        Can_Tcan1146_Map[4] = CAN_TCAN_INVALID;
        Can_Tcan1146_Map[5] = CAN_TCAN_INVALID;
        Can_Tcan1146_Map[6] = CAN_TCAN_INVALID;
        Can_Tcan1146_Map[7] = CAN_TCAN_INVALID;
        
        Can_Tcan1044_Map[0] = CAN_TCAN_INVALID;
        Can_Tcan1044_Map[1] = CAN_TCAN_INVALID;
        Can_Tcan1044_Map[2] = CAN_TCAN_INVALID;
        Can_Tcan1044_Map[3] = CAN_TCAN1044_CHAN_0;
        Can_Tcan1044_Map[4] = CAN_TCAN_INVALID;
        Can_Tcan1044_Map[5] = CAN_TCAN_INVALID;
        Can_Tcan1044_Map[6] = CAN_TCAN_INVALID;
        Can_Tcan1044_Map[7] = CAN_TCAN_INVALID;
	}
    else if	(chip_family == CHIPINFO_FAMILY_NORDAU)
	{
	    Can_Tcan1146_Map[0] = CAN_TCAN1146_CHAN_0;
        Can_Tcan1146_Map[1] = CAN_TCAN1146_CHAN_1;
        Can_Tcan1146_Map[2] = CAN_TCAN_INVALID;
        Can_Tcan1146_Map[3] = CAN_TCAN_INVALID;
        Can_Tcan1146_Map[4] = CAN_TCAN_INVALID;
        Can_Tcan1146_Map[5] = CAN_TCAN_INVALID;
        Can_Tcan1146_Map[6] = CAN_TCAN_INVALID;
        Can_Tcan1146_Map[7] = CAN_TCAN_INVALID;
        
        Can_Tcan1044_Map[0] = CAN_TCAN_INVALID;
        Can_Tcan1044_Map[1] = CAN_TCAN_INVALID;
        Can_Tcan1044_Map[2] = CAN_TCAN1044_CHAN_0;
        Can_Tcan1044_Map[3] = CAN_TCAN1044_CHAN_1;
        Can_Tcan1044_Map[4] = CAN_TCAN1044_CHAN_2;
        Can_Tcan1044_Map[5] = CAN_TCAN_INVALID;
        Can_Tcan1044_Map[6] = CAN_TCAN_INVALID;
        Can_Tcan1044_Map[7] = CAN_TCAN_INVALID;
	}
    else
    {
    
    }

    for (i=0; i < can_max_inst; i++)
    {
    	CAN_WUP_Gpio_Cfg[i].cfg.func = 0;
    	CAN_WUP_Gpio_Cfg[i].cfg.dir = (uint8_t)GPIO_IN;
    	CAN_WUP_Gpio_Cfg[i].cfg.pull = (uint8_t)GPIO_PU;
    	CAN_WUP_Gpio_Cfg[i].cfg.drive = (uint8_t)GPIO_2MA;
    }
}

static void Can_Plt_Cfg_Irq_Init(ChipInfoFamilyType chip_family)
{
    uint32 i = 0;
	uint32_t can_max_inst = Can_Plt_Cfg_Max_Supported_Instance(chip_family);
	
    for (i = 0; i < (uint32)NUM_IRQ_PER_CAN_CONTROLLER*can_max_inst; i++)
    {
		Can_Irq_Cfg[i].int_cfg = (uint32_t)CAN_INTR_TRIGGER_LEVEL;
	}
	
	if (chip_family == CHIPINFO_FAMILY_LEMANSAU)
    {
        Can_Irq_Cfg[0].Can_Controller_id = 0;
		Can_Irq_Cfg[0].int_num = 241;
		Can_Irq_Cfg[0].can_int_handler = &CANSS0_FUSA_WARNING_ISR;
		
        Can_Irq_Cfg[1].Can_Controller_id = 0;
		Can_Irq_Cfg[1].int_num = 432;
		Can_Irq_Cfg[1].can_int_handler = &CANSS0_INT0_ISR;
		
        Can_Irq_Cfg[2].Can_Controller_id = 0;
		Can_Irq_Cfg[2].int_num = 433;
		Can_Irq_Cfg[2].can_int_handler = &CANSS0_INT1_ISR;
		
        Can_Irq_Cfg[3].Can_Controller_id = 0;
		Can_Irq_Cfg[3].int_num = 434;
		Can_Irq_Cfg[3].can_int_handler = CANSS0_DMU_ISR;
		
        Can_Irq_Cfg[4].Can_Controller_id = 0;
		Can_Irq_Cfg[4].int_num = 435;
		Can_Irq_Cfg[4].can_int_handler = CANSS0_DMA_ISR;
		
        Can_Irq_Cfg[5].Can_Controller_id = 0;
		Can_Irq_Cfg[5].int_num = 436;
		Can_Irq_Cfg[5].can_int_handler = CANSS0_FUSA_ERROR_ISR;
		
        Can_Irq_Cfg[6].Can_Controller_id = 0;
		Can_Irq_Cfg[6].int_num = 472;
		Can_Irq_Cfg[6].can_int_handler = CANSS0_FE0_ISR;
		
        Can_Irq_Cfg[7].Can_Controller_id = 0;
		Can_Irq_Cfg[7].int_num = 473;
		Can_Irq_Cfg[7].can_int_handler = CANSS0_FE1_ISR;
		
        Can_Irq_Cfg[8].Can_Controller_id = 0;
		Can_Irq_Cfg[8].int_num = 474;
		Can_Irq_Cfg[8].can_int_handler = CANSS0_FE2_ISR;
		
        Can_Irq_Cfg[9].Can_Controller_id = 1;
		Can_Irq_Cfg[9].int_num = 242;
		Can_Irq_Cfg[9].can_int_handler = CANSS1_FUSA_WARNING_ISR;
		
        Can_Irq_Cfg[10].Can_Controller_id = 1;
		Can_Irq_Cfg[10].int_num = 437;
		Can_Irq_Cfg[10].can_int_handler = CANSS1_INT0_ISR;
		
        Can_Irq_Cfg[11].Can_Controller_id = 1;
		Can_Irq_Cfg[11].int_num = 438;
		Can_Irq_Cfg[11].can_int_handler = CANSS1_INT1_ISR;
		
        Can_Irq_Cfg[12].Can_Controller_id = 1;
		Can_Irq_Cfg[12].int_num = 439;
		Can_Irq_Cfg[12].can_int_handler = CANSS1_DMU_ISR;
		
        Can_Irq_Cfg[13].Can_Controller_id = 1;
		Can_Irq_Cfg[13].int_num = 440;
		Can_Irq_Cfg[13].can_int_handler = CANSS1_DMA_ISR;
		
        Can_Irq_Cfg[14].Can_Controller_id = 1;
		Can_Irq_Cfg[14].int_num = 441;
		Can_Irq_Cfg[14].can_int_handler = CANSS1_FUSA_ERROR_ISR;
		
        Can_Irq_Cfg[15].Can_Controller_id = 1;
		Can_Irq_Cfg[15].int_num = 475;
		Can_Irq_Cfg[15].can_int_handler = CANSS1_FE0_ISR;
		
        Can_Irq_Cfg[16].Can_Controller_id = 1;
		Can_Irq_Cfg[16].int_num = 476;
		Can_Irq_Cfg[16].can_int_handler = CANSS1_FE1_ISR;
		
        Can_Irq_Cfg[17].Can_Controller_id = 1;
		Can_Irq_Cfg[17].int_num = 477;
		Can_Irq_Cfg[17].can_int_handler = CANSS1_FE2_ISR;
		
        Can_Irq_Cfg[18].Can_Controller_id = 2;
		Can_Irq_Cfg[18].int_num = 243;
		Can_Irq_Cfg[18].can_int_handler = CANSS2_FUSA_WARNING_ISR;
		
        Can_Irq_Cfg[19].Can_Controller_id = 2;
		Can_Irq_Cfg[19].int_num = 442;
		Can_Irq_Cfg[19].can_int_handler = CANSS2_INT0_ISR;
		
        Can_Irq_Cfg[20].Can_Controller_id = 2;
		Can_Irq_Cfg[20].int_num = 443;
		Can_Irq_Cfg[20].can_int_handler = CANSS2_INT1_ISR;
		
        Can_Irq_Cfg[21].Can_Controller_id = 2;
		Can_Irq_Cfg[21].int_num = 444;
		Can_Irq_Cfg[21].can_int_handler = CANSS2_DMU_ISR;
		
        Can_Irq_Cfg[22].Can_Controller_id = 2;
		Can_Irq_Cfg[22].int_num = 445;
		Can_Irq_Cfg[22].can_int_handler = CANSS2_DMA_ISR;
		
        Can_Irq_Cfg[23].Can_Controller_id = 2;
		Can_Irq_Cfg[23].int_num = 446;
		Can_Irq_Cfg[23].can_int_handler = CANSS2_FUSA_ERROR_ISR;
		
        Can_Irq_Cfg[24].Can_Controller_id = 2;
		Can_Irq_Cfg[24].int_num = 478;
		Can_Irq_Cfg[24].can_int_handler = CANSS2_FE0_ISR;
		
        Can_Irq_Cfg[25].Can_Controller_id = 2;
		Can_Irq_Cfg[25].int_num = 479;
		Can_Irq_Cfg[25].can_int_handler = CANSS2_FE1_ISR;
		
        Can_Irq_Cfg[26].Can_Controller_id = 2;
		Can_Irq_Cfg[26].int_num = 480;
		Can_Irq_Cfg[26].can_int_handler = CANSS2_FE2_ISR;
		
        Can_Irq_Cfg[27].Can_Controller_id = 3;
		Can_Irq_Cfg[27].int_num = 244;
		Can_Irq_Cfg[27].can_int_handler = CANSS3_FUSA_WARNING_ISR;
		
        Can_Irq_Cfg[28].Can_Controller_id = 3;
		Can_Irq_Cfg[28].int_num = 447;
		Can_Irq_Cfg[28].can_int_handler = CANSS3_INT0_ISR;
		
        Can_Irq_Cfg[29].Can_Controller_id = 3;
		Can_Irq_Cfg[29].int_num = 448;
		Can_Irq_Cfg[29].can_int_handler = CANSS3_INT1_ISR;
		
        Can_Irq_Cfg[30].Can_Controller_id = 3;
		Can_Irq_Cfg[30].int_num = 449;
		Can_Irq_Cfg[30].can_int_handler = CANSS3_DMU_ISR;
		
        Can_Irq_Cfg[31].Can_Controller_id = 3;
		Can_Irq_Cfg[31].int_num = 450;
		Can_Irq_Cfg[31].can_int_handler = CANSS3_DMA_ISR;
		
        Can_Irq_Cfg[32].Can_Controller_id = 3;
		Can_Irq_Cfg[32].int_num = 451;
		Can_Irq_Cfg[32].can_int_handler = CANSS3_FUSA_ERROR_ISR;
		
        Can_Irq_Cfg[33].Can_Controller_id = 3;
		Can_Irq_Cfg[33].int_num = 481;
		Can_Irq_Cfg[33].can_int_handler = CANSS3_FE0_ISR;
		
        Can_Irq_Cfg[34].Can_Controller_id = 3;
		Can_Irq_Cfg[34].int_num = 482;
		Can_Irq_Cfg[34].can_int_handler = CANSS3_FE1_ISR;
		
        Can_Irq_Cfg[35].Can_Controller_id = 3;
		Can_Irq_Cfg[35].int_num = 483;
		Can_Irq_Cfg[35].can_int_handler = CANSS3_FE2_ISR;
		
        Can_Irq_Cfg[36].Can_Controller_id = 4;
		Can_Irq_Cfg[36].int_num = 245;
		Can_Irq_Cfg[36].can_int_handler = CANSS4_FUSA_WARNING_ISR;
		
        Can_Irq_Cfg[37].Can_Controller_id = 4;
		Can_Irq_Cfg[37].int_num = 452;
		Can_Irq_Cfg[37].can_int_handler = CANSS4_INT0_ISR;
		
        Can_Irq_Cfg[38].Can_Controller_id = 4;
		Can_Irq_Cfg[38].int_num = 453;
		Can_Irq_Cfg[38].can_int_handler = CANSS4_INT1_ISR;
		
        Can_Irq_Cfg[39].Can_Controller_id = 4;
		Can_Irq_Cfg[39].int_num = 454;
		Can_Irq_Cfg[39].can_int_handler = CANSS4_DMU_ISR;
		
        Can_Irq_Cfg[40].Can_Controller_id = 4;
		Can_Irq_Cfg[40].int_num = 455;
		Can_Irq_Cfg[40].can_int_handler = CANSS4_DMA_ISR;
		
        Can_Irq_Cfg[41].Can_Controller_id = 4;
		Can_Irq_Cfg[41].int_num = 456;
		Can_Irq_Cfg[41].can_int_handler = CANSS4_FUSA_ERROR_ISR;
		
        Can_Irq_Cfg[42].Can_Controller_id = 4;
		Can_Irq_Cfg[42].int_num = 484;
		Can_Irq_Cfg[42].can_int_handler = CANSS4_FE0_ISR;
		
        Can_Irq_Cfg[43].Can_Controller_id = 4;
		Can_Irq_Cfg[43].int_num = 485;
		Can_Irq_Cfg[43].can_int_handler = CANSS4_FE1_ISR;
		
        Can_Irq_Cfg[44].Can_Controller_id = 4;
		Can_Irq_Cfg[44].int_num = 486;
		Can_Irq_Cfg[44].can_int_handler = CANSS4_FE2_ISR;
		
        Can_Irq_Cfg[45].Can_Controller_id = 5;
		Can_Irq_Cfg[45].int_num = 246;
		Can_Irq_Cfg[45].can_int_handler = CANSS5_FUSA_WARNING_ISR;
		
        Can_Irq_Cfg[46].Can_Controller_id = 5;
		Can_Irq_Cfg[46].int_num = 457;
		Can_Irq_Cfg[46].can_int_handler = CANSS5_INT0_ISR;
		
        Can_Irq_Cfg[47].Can_Controller_id = 5;
		Can_Irq_Cfg[47].int_num = 458;
		Can_Irq_Cfg[47].can_int_handler = CANSS5_INT1_ISR;
		
        Can_Irq_Cfg[48].Can_Controller_id = 5;
		Can_Irq_Cfg[48].int_num = 459;
		Can_Irq_Cfg[48].can_int_handler = CANSS5_DMU_ISR;
		
        Can_Irq_Cfg[49].Can_Controller_id = 5;
		Can_Irq_Cfg[49].int_num = 460;
		Can_Irq_Cfg[49].can_int_handler = CANSS5_DMA_ISR;
		
        Can_Irq_Cfg[50].Can_Controller_id = 5;
		Can_Irq_Cfg[50].int_num = 461;
		Can_Irq_Cfg[50].can_int_handler = CANSS5_FUSA_ERROR_ISR;
		
        Can_Irq_Cfg[51].Can_Controller_id = 5;
		Can_Irq_Cfg[51].int_num = 487;
		Can_Irq_Cfg[51].can_int_handler = CANSS5_FE0_ISR;
		
        Can_Irq_Cfg[52].Can_Controller_id = 5;
		Can_Irq_Cfg[52].int_num = 488;
		Can_Irq_Cfg[52].can_int_handler = CANSS5_FE1_ISR;
		
        Can_Irq_Cfg[53].Can_Controller_id = 5;
		Can_Irq_Cfg[53].int_num = 489;
		Can_Irq_Cfg[53].can_int_handler = CANSS5_FE2_ISR;
		
        Can_Irq_Cfg[54].Can_Controller_id = 6;
		Can_Irq_Cfg[54].int_num = 247;
		Can_Irq_Cfg[54].can_int_handler = CANSS6_FUSA_WARNING_ISR;
		
        Can_Irq_Cfg[55].Can_Controller_id = 6;
		Can_Irq_Cfg[55].int_num = 462;
		Can_Irq_Cfg[55].can_int_handler = CANSS6_INT0_ISR;
		
        Can_Irq_Cfg[56].Can_Controller_id = 6;
		Can_Irq_Cfg[56].int_num = 463;
		Can_Irq_Cfg[56].can_int_handler = CANSS6_INT1_ISR;
		
        Can_Irq_Cfg[57].Can_Controller_id = 6;
		Can_Irq_Cfg[57].int_num = 464;
		Can_Irq_Cfg[57].can_int_handler = CANSS6_DMU_ISR;
		
        Can_Irq_Cfg[58].Can_Controller_id = 6;
		Can_Irq_Cfg[58].int_num = 465;
		Can_Irq_Cfg[58].can_int_handler = CANSS6_DMA_ISR;
		
        Can_Irq_Cfg[59].Can_Controller_id = 6;
		Can_Irq_Cfg[59].int_num = 466;
		Can_Irq_Cfg[59].can_int_handler = CANSS6_FUSA_ERROR_ISR;
		
        Can_Irq_Cfg[60].Can_Controller_id = 6;
		Can_Irq_Cfg[60].int_num = 490;
		Can_Irq_Cfg[60].can_int_handler = CANSS6_FE0_ISR;
		
        Can_Irq_Cfg[61].Can_Controller_id = 6;
		Can_Irq_Cfg[61].int_num = 491;
		Can_Irq_Cfg[61].can_int_handler = CANSS6_FE1_ISR;
		
        Can_Irq_Cfg[62].Can_Controller_id = 6;
		Can_Irq_Cfg[62].int_num = 492;
		Can_Irq_Cfg[62].can_int_handler = CANSS6_FE2_ISR;
		
        Can_Irq_Cfg[63].Can_Controller_id = 7;
		Can_Irq_Cfg[63].int_num = 248;
		Can_Irq_Cfg[63].can_int_handler = CANSS7_FUSA_WARNING_ISR;
		
        Can_Irq_Cfg[64].Can_Controller_id = 7;
		Can_Irq_Cfg[64].int_num = 467;
		Can_Irq_Cfg[64].can_int_handler = CANSS7_INT0_ISR;
		
        Can_Irq_Cfg[65].Can_Controller_id = 7;
		Can_Irq_Cfg[65].int_num = 468;
		Can_Irq_Cfg[65].can_int_handler = CANSS7_INT1_ISR;
		
        Can_Irq_Cfg[66].Can_Controller_id = 7;
		Can_Irq_Cfg[66].int_num = 469;
		Can_Irq_Cfg[66].can_int_handler = CANSS7_DMU_ISR;
		
        Can_Irq_Cfg[67].Can_Controller_id = 7;
		Can_Irq_Cfg[67].int_num = 470;
		Can_Irq_Cfg[67].can_int_handler = CANSS7_DMA_ISR;
		
        Can_Irq_Cfg[68].Can_Controller_id = 7;
		Can_Irq_Cfg[68].int_num = 471;
		Can_Irq_Cfg[68].can_int_handler = CANSS7_FUSA_ERROR_ISR;
		
        Can_Irq_Cfg[69].Can_Controller_id = 7;
		Can_Irq_Cfg[69].int_num = 493;
		Can_Irq_Cfg[69].can_int_handler = CANSS7_FE0_ISR;
		
        Can_Irq_Cfg[70].Can_Controller_id = 7;
		Can_Irq_Cfg[70].int_num = 494;
		Can_Irq_Cfg[70].can_int_handler = CANSS7_FE1_ISR;
		
        Can_Irq_Cfg[71].Can_Controller_id = 7;
		Can_Irq_Cfg[71].int_num = 495;
		Can_Irq_Cfg[71].can_int_handler = CANSS7_FE2_ISR;
    }
    else if (chip_family == CHIPINFO_FAMILY_MONACOAU)
    {
        Can_Irq_Cfg[0].Can_Controller_id = 0;
		Can_Irq_Cfg[0].int_num = 241;
		Can_Irq_Cfg[0].can_int_handler = &CANSS0_FUSA_WARNING_ISR;
		
        Can_Irq_Cfg[1].Can_Controller_id = 0;
		Can_Irq_Cfg[1].int_num = 432;
		Can_Irq_Cfg[1].can_int_handler = &CANSS0_INT0_ISR;
		
        Can_Irq_Cfg[2].Can_Controller_id = 0;
		Can_Irq_Cfg[2].int_num = 433;
		Can_Irq_Cfg[2].can_int_handler = &CANSS0_INT1_ISR;
		
        Can_Irq_Cfg[3].Can_Controller_id = 0;
		Can_Irq_Cfg[3].int_num = 434;
		Can_Irq_Cfg[3].can_int_handler = CANSS0_DMU_ISR;
		
        Can_Irq_Cfg[4].Can_Controller_id = 0;
		Can_Irq_Cfg[4].int_num = 435;
		Can_Irq_Cfg[4].can_int_handler = CANSS0_DMA_ISR;
		
        Can_Irq_Cfg[5].Can_Controller_id = 0;
		Can_Irq_Cfg[5].int_num = 436;
		Can_Irq_Cfg[5].can_int_handler = CANSS0_FUSA_ERROR_ISR;
		
        Can_Irq_Cfg[6].Can_Controller_id = 0;
		Can_Irq_Cfg[6].int_num = 472;
		Can_Irq_Cfg[6].can_int_handler = CANSS0_FE0_ISR;
		
        Can_Irq_Cfg[7].Can_Controller_id = 0;
		Can_Irq_Cfg[7].int_num = 473;
		Can_Irq_Cfg[7].can_int_handler = CANSS0_FE1_ISR;
		
        Can_Irq_Cfg[8].Can_Controller_id = 0;
		Can_Irq_Cfg[8].int_num = 474;
		Can_Irq_Cfg[8].can_int_handler = CANSS0_FE2_ISR;
		
        Can_Irq_Cfg[9].Can_Controller_id = 1;
		Can_Irq_Cfg[9].int_num = 242;
		Can_Irq_Cfg[9].can_int_handler = CANSS1_FUSA_WARNING_ISR;
		
        Can_Irq_Cfg[10].Can_Controller_id = 1;
		Can_Irq_Cfg[10].int_num = 437;
		Can_Irq_Cfg[10].can_int_handler = CANSS1_INT0_ISR;
		
        Can_Irq_Cfg[11].Can_Controller_id = 1;
		Can_Irq_Cfg[11].int_num = 438;
		Can_Irq_Cfg[11].can_int_handler = CANSS1_INT1_ISR;
		
        Can_Irq_Cfg[12].Can_Controller_id = 1;
		Can_Irq_Cfg[12].int_num = 439;
		Can_Irq_Cfg[12].can_int_handler = CANSS1_DMU_ISR;
		
        Can_Irq_Cfg[13].Can_Controller_id = 1;
		Can_Irq_Cfg[13].int_num = 440;
		Can_Irq_Cfg[13].can_int_handler = CANSS1_DMA_ISR;
		
        Can_Irq_Cfg[14].Can_Controller_id = 1;
		Can_Irq_Cfg[14].int_num = 441;
		Can_Irq_Cfg[14].can_int_handler = CANSS1_FUSA_ERROR_ISR;
		
        Can_Irq_Cfg[15].Can_Controller_id = 1;
		Can_Irq_Cfg[15].int_num = 475;
		Can_Irq_Cfg[15].can_int_handler = CANSS1_FE0_ISR;
		
        Can_Irq_Cfg[16].Can_Controller_id = 1;
		Can_Irq_Cfg[16].int_num = 476;
		Can_Irq_Cfg[16].can_int_handler = CANSS1_FE1_ISR;
		
        Can_Irq_Cfg[17].Can_Controller_id = 1;
		Can_Irq_Cfg[17].int_num = 477;
		Can_Irq_Cfg[17].can_int_handler = CANSS1_FE2_ISR;
		
        Can_Irq_Cfg[18].Can_Controller_id = 2;
		Can_Irq_Cfg[18].int_num = 243;
		Can_Irq_Cfg[18].can_int_handler = CANSS2_FUSA_WARNING_ISR;
		
        Can_Irq_Cfg[19].Can_Controller_id = 2;
		Can_Irq_Cfg[19].int_num = 442;
		Can_Irq_Cfg[19].can_int_handler = CANSS2_INT0_ISR;
		
        Can_Irq_Cfg[20].Can_Controller_id = 2;
		Can_Irq_Cfg[20].int_num = 443;
		Can_Irq_Cfg[20].can_int_handler = CANSS2_INT1_ISR;
		
        Can_Irq_Cfg[21].Can_Controller_id = 2;
		Can_Irq_Cfg[21].int_num = 444;
		Can_Irq_Cfg[21].can_int_handler = CANSS2_DMU_ISR;
		
        Can_Irq_Cfg[22].Can_Controller_id = 2;
		Can_Irq_Cfg[22].int_num = 445;
		Can_Irq_Cfg[22].can_int_handler = CANSS2_DMA_ISR;
		
        Can_Irq_Cfg[23].Can_Controller_id = 2;
		Can_Irq_Cfg[23].int_num = 446;
		Can_Irq_Cfg[23].can_int_handler = CANSS2_FUSA_ERROR_ISR;
		
        Can_Irq_Cfg[24].Can_Controller_id = 2;
		Can_Irq_Cfg[24].int_num = 478;
		Can_Irq_Cfg[24].can_int_handler = CANSS2_FE0_ISR;
		
        Can_Irq_Cfg[25].Can_Controller_id = 2;
		Can_Irq_Cfg[25].int_num = 479;
		Can_Irq_Cfg[25].can_int_handler = CANSS2_FE1_ISR;
		
        Can_Irq_Cfg[26].Can_Controller_id = 2;
		Can_Irq_Cfg[26].int_num = 480;
		Can_Irq_Cfg[26].can_int_handler = CANSS2_FE2_ISR;
		
        Can_Irq_Cfg[27].Can_Controller_id = 3;
		Can_Irq_Cfg[27].int_num = 244;
		Can_Irq_Cfg[27].can_int_handler = CANSS3_FUSA_WARNING_ISR;
		
        Can_Irq_Cfg[28].Can_Controller_id = 3;
		Can_Irq_Cfg[28].int_num = 447;
		Can_Irq_Cfg[28].can_int_handler = CANSS3_INT0_ISR;
		
        Can_Irq_Cfg[29].Can_Controller_id = 3;
		Can_Irq_Cfg[29].int_num = 448;
		Can_Irq_Cfg[29].can_int_handler = CANSS3_INT1_ISR;
		
        Can_Irq_Cfg[30].Can_Controller_id = 3;
		Can_Irq_Cfg[30].int_num = 449;
		Can_Irq_Cfg[30].can_int_handler = CANSS3_DMU_ISR;
		
        Can_Irq_Cfg[31].Can_Controller_id = 3;
		Can_Irq_Cfg[31].int_num = 450;
		Can_Irq_Cfg[31].can_int_handler = CANSS3_DMA_ISR;
		
        Can_Irq_Cfg[32].Can_Controller_id = 3;
		Can_Irq_Cfg[32].int_num = 451;
		Can_Irq_Cfg[32].can_int_handler = CANSS3_FUSA_ERROR_ISR;
		
        Can_Irq_Cfg[33].Can_Controller_id = 3;
		Can_Irq_Cfg[33].int_num = 481;
		Can_Irq_Cfg[33].can_int_handler = CANSS3_FE0_ISR;
		
        Can_Irq_Cfg[34].Can_Controller_id = 3;
		Can_Irq_Cfg[34].int_num = 482;
		Can_Irq_Cfg[34].can_int_handler = CANSS3_FE1_ISR;
		
        Can_Irq_Cfg[35].Can_Controller_id = 3;
		Can_Irq_Cfg[35].int_num = 483;
		Can_Irq_Cfg[35].can_int_handler = CANSS3_FE2_ISR;
    }
    else if (chip_family == CHIPINFO_FAMILY_NORDAU)
	{
        Can_Irq_Cfg[0].Can_Controller_id = 0;
        Can_Irq_Cfg[0].int_num = 423;
        Can_Irq_Cfg[0].can_int_handler = &CANSS0_FUSA_WARNING_ISR;
        
        Can_Irq_Cfg[1].Can_Controller_id = 0;
        Can_Irq_Cfg[1].int_num = 432;
        Can_Irq_Cfg[1].can_int_handler = &CANSS0_INT0_ISR;
        
        Can_Irq_Cfg[2].Can_Controller_id = 0;
        Can_Irq_Cfg[2].int_num = 433;
        Can_Irq_Cfg[2].can_int_handler = &CANSS0_INT1_ISR;
        
        Can_Irq_Cfg[3].Can_Controller_id = 0;
        Can_Irq_Cfg[3].int_num = 434;
        Can_Irq_Cfg[3].can_int_handler = CANSS0_DMU_ISR;
        
        Can_Irq_Cfg[4].Can_Controller_id = 0;
        Can_Irq_Cfg[4].int_num = 435;
        Can_Irq_Cfg[4].can_int_handler = CANSS0_DMA_ISR;
        
        Can_Irq_Cfg[5].Can_Controller_id = 0;
        Can_Irq_Cfg[5].int_num = 211;
        Can_Irq_Cfg[5].can_int_handler = CANSS0_FUSA_ERROR_ISR;
        
        Can_Irq_Cfg[6].Can_Controller_id = 0;
        Can_Irq_Cfg[6].int_num = 472;
        Can_Irq_Cfg[6].can_int_handler = CANSS0_FE0_ISR;
        
        Can_Irq_Cfg[7].Can_Controller_id = 0;
        Can_Irq_Cfg[7].int_num = 473;
        Can_Irq_Cfg[7].can_int_handler = CANSS0_FE1_ISR;
        
        Can_Irq_Cfg[8].Can_Controller_id = 0;
        Can_Irq_Cfg[8].int_num = 474;
        Can_Irq_Cfg[8].can_int_handler = CANSS0_FE2_ISR;
        
        Can_Irq_Cfg[9].Can_Controller_id = 1;
        Can_Irq_Cfg[9].int_num = 424;
        Can_Irq_Cfg[9].can_int_handler = CANSS1_FUSA_WARNING_ISR;
        
        Can_Irq_Cfg[10].Can_Controller_id = 1;
        Can_Irq_Cfg[10].int_num = 437;
        Can_Irq_Cfg[10].can_int_handler = CANSS1_INT0_ISR;
        
        Can_Irq_Cfg[11].Can_Controller_id = 1;
        Can_Irq_Cfg[11].int_num = 438;
        Can_Irq_Cfg[11].can_int_handler = CANSS1_INT1_ISR;
        
        Can_Irq_Cfg[12].Can_Controller_id = 1;
        Can_Irq_Cfg[12].int_num = 439;
        Can_Irq_Cfg[12].can_int_handler = CANSS1_DMU_ISR;
        
        Can_Irq_Cfg[13].Can_Controller_id = 1;
        Can_Irq_Cfg[13].int_num = 440;
        Can_Irq_Cfg[13].can_int_handler = CANSS1_DMA_ISR;
        
        Can_Irq_Cfg[14].Can_Controller_id = 1;
        Can_Irq_Cfg[14].int_num = 212;
        Can_Irq_Cfg[14].can_int_handler = CANSS1_FUSA_ERROR_ISR;
        
        Can_Irq_Cfg[15].Can_Controller_id = 1;
        Can_Irq_Cfg[15].int_num = 475;
        Can_Irq_Cfg[15].can_int_handler = CANSS1_FE0_ISR;
        
        Can_Irq_Cfg[16].Can_Controller_id = 1;
        Can_Irq_Cfg[16].int_num = 476;
        Can_Irq_Cfg[16].can_int_handler = CANSS1_FE1_ISR;
        
        Can_Irq_Cfg[17].Can_Controller_id = 1;
        Can_Irq_Cfg[17].int_num = 477;
        Can_Irq_Cfg[17].can_int_handler = CANSS1_FE2_ISR;
        
        Can_Irq_Cfg[18].Can_Controller_id = 2;
        Can_Irq_Cfg[18].int_num = 425;
        Can_Irq_Cfg[18].can_int_handler = CANSS2_FUSA_WARNING_ISR;
        
        Can_Irq_Cfg[19].Can_Controller_id = 2;
        Can_Irq_Cfg[19].int_num = 442;
        Can_Irq_Cfg[19].can_int_handler = CANSS2_INT0_ISR;
        
        Can_Irq_Cfg[20].Can_Controller_id = 2;
        Can_Irq_Cfg[20].int_num = 443;
        Can_Irq_Cfg[20].can_int_handler = CANSS2_INT1_ISR;
        
        Can_Irq_Cfg[21].Can_Controller_id = 2;
        Can_Irq_Cfg[21].int_num = 444;
        Can_Irq_Cfg[21].can_int_handler = CANSS2_DMU_ISR;
        
        Can_Irq_Cfg[22].Can_Controller_id = 2;
        Can_Irq_Cfg[22].int_num = 445;
        Can_Irq_Cfg[22].can_int_handler = CANSS2_DMA_ISR;
        
        Can_Irq_Cfg[23].Can_Controller_id = 2;
        Can_Irq_Cfg[23].int_num = 213;
        Can_Irq_Cfg[23].can_int_handler = CANSS2_FUSA_ERROR_ISR;
        
        Can_Irq_Cfg[24].Can_Controller_id = 2;
        Can_Irq_Cfg[24].int_num = 478;
        Can_Irq_Cfg[24].can_int_handler = CANSS2_FE0_ISR;
        
        Can_Irq_Cfg[25].Can_Controller_id = 2;
        Can_Irq_Cfg[25].int_num = 479;
        Can_Irq_Cfg[25].can_int_handler = CANSS2_FE1_ISR;
        
        Can_Irq_Cfg[26].Can_Controller_id = 2;
        Can_Irq_Cfg[26].int_num = 480;
        Can_Irq_Cfg[26].can_int_handler = CANSS2_FE2_ISR;
        
        Can_Irq_Cfg[27].Can_Controller_id = 3;
        Can_Irq_Cfg[27].int_num = 426;
        Can_Irq_Cfg[27].can_int_handler = CANSS3_FUSA_WARNING_ISR;
        
        Can_Irq_Cfg[28].Can_Controller_id = 3;
        Can_Irq_Cfg[28].int_num = 447;
        Can_Irq_Cfg[28].can_int_handler = CANSS3_INT0_ISR;
        
        Can_Irq_Cfg[29].Can_Controller_id = 3;
        Can_Irq_Cfg[29].int_num = 448;
        Can_Irq_Cfg[29].can_int_handler = CANSS3_INT1_ISR;
        
        Can_Irq_Cfg[30].Can_Controller_id = 3;
        Can_Irq_Cfg[30].int_num = 449;
        Can_Irq_Cfg[30].can_int_handler = CANSS3_DMU_ISR;
        
        Can_Irq_Cfg[31].Can_Controller_id = 3;
        Can_Irq_Cfg[31].int_num = 450;
        Can_Irq_Cfg[31].can_int_handler = CANSS3_DMA_ISR;
        
        Can_Irq_Cfg[32].Can_Controller_id = 3;
        Can_Irq_Cfg[32].int_num = 214;
        Can_Irq_Cfg[32].can_int_handler = CANSS3_FUSA_ERROR_ISR;
        
        Can_Irq_Cfg[33].Can_Controller_id = 3;
        Can_Irq_Cfg[33].int_num = 481;
        Can_Irq_Cfg[33].can_int_handler = CANSS3_FE0_ISR;
        
        Can_Irq_Cfg[34].Can_Controller_id = 3;
        Can_Irq_Cfg[34].int_num = 482;
        Can_Irq_Cfg[34].can_int_handler = CANSS3_FE1_ISR;
        
        Can_Irq_Cfg[35].Can_Controller_id = 3;
        Can_Irq_Cfg[35].int_num = 483;
        Can_Irq_Cfg[35].can_int_handler = CANSS3_FE2_ISR;
        
        Can_Irq_Cfg[36].Can_Controller_id = 4;
        Can_Irq_Cfg[36].int_num = 427;
        Can_Irq_Cfg[36].can_int_handler = CANSS4_FUSA_WARNING_ISR;
        
        Can_Irq_Cfg[37].Can_Controller_id = 4;
        Can_Irq_Cfg[37].int_num = 452;
        Can_Irq_Cfg[37].can_int_handler = CANSS4_INT0_ISR;
        
        Can_Irq_Cfg[38].Can_Controller_id = 4;
        Can_Irq_Cfg[38].int_num = 453;
        Can_Irq_Cfg[38].can_int_handler = CANSS4_INT1_ISR;
        
        Can_Irq_Cfg[39].Can_Controller_id = 4;
        Can_Irq_Cfg[39].int_num = 454;
        Can_Irq_Cfg[39].can_int_handler = CANSS4_DMU_ISR;
        
        Can_Irq_Cfg[40].Can_Controller_id = 4;
        Can_Irq_Cfg[40].int_num = 455;
        Can_Irq_Cfg[40].can_int_handler = CANSS4_DMA_ISR;
        
        Can_Irq_Cfg[41].Can_Controller_id = 4;
        Can_Irq_Cfg[41].int_num = 215;
        Can_Irq_Cfg[41].can_int_handler = CANSS4_FUSA_ERROR_ISR;
        
        Can_Irq_Cfg[42].Can_Controller_id = 4;
        Can_Irq_Cfg[42].int_num = 484;
        Can_Irq_Cfg[42].can_int_handler = CANSS4_FE0_ISR;
        
        Can_Irq_Cfg[43].Can_Controller_id = 4;
        Can_Irq_Cfg[43].int_num = 485;
        Can_Irq_Cfg[43].can_int_handler = CANSS4_FE1_ISR;
        
        Can_Irq_Cfg[44].Can_Controller_id = 4;
        Can_Irq_Cfg[44].int_num = 486;
        Can_Irq_Cfg[44].can_int_handler = CANSS4_FE2_ISR;
        
        Can_Irq_Cfg[45].Can_Controller_id = 5;
        Can_Irq_Cfg[45].int_num = 428;
        Can_Irq_Cfg[45].can_int_handler = CANSS5_FUSA_WARNING_ISR;
        
        Can_Irq_Cfg[46].Can_Controller_id = 5;
        Can_Irq_Cfg[46].int_num = 457;
        Can_Irq_Cfg[46].can_int_handler = CANSS5_INT0_ISR;
        
        Can_Irq_Cfg[47].Can_Controller_id = 5;
        Can_Irq_Cfg[47].int_num = 458;
        Can_Irq_Cfg[47].can_int_handler = CANSS5_INT1_ISR;
        
        Can_Irq_Cfg[48].Can_Controller_id = 5;
        Can_Irq_Cfg[48].int_num = 459;
        Can_Irq_Cfg[48].can_int_handler = CANSS5_DMU_ISR;
        
        Can_Irq_Cfg[49].Can_Controller_id = 5;
        Can_Irq_Cfg[49].int_num = 460;
        Can_Irq_Cfg[49].can_int_handler = CANSS5_DMA_ISR;
        
        Can_Irq_Cfg[50].Can_Controller_id = 5;
        Can_Irq_Cfg[50].int_num = 216;
        Can_Irq_Cfg[50].can_int_handler = CANSS5_FUSA_ERROR_ISR;
        
        Can_Irq_Cfg[51].Can_Controller_id = 5;
        Can_Irq_Cfg[51].int_num = 487;
        Can_Irq_Cfg[51].can_int_handler = CANSS5_FE0_ISR;
        
        Can_Irq_Cfg[52].Can_Controller_id = 5;
        Can_Irq_Cfg[52].int_num = 488;
        Can_Irq_Cfg[52].can_int_handler = CANSS5_FE1_ISR;
        
        Can_Irq_Cfg[53].Can_Controller_id = 5;
        Can_Irq_Cfg[53].int_num = 489;
        Can_Irq_Cfg[53].can_int_handler = CANSS5_FE2_ISR;
        
        Can_Irq_Cfg[54].Can_Controller_id = 6;
        Can_Irq_Cfg[54].int_num = 429;
        Can_Irq_Cfg[54].can_int_handler = CANSS6_FUSA_WARNING_ISR;
        
        Can_Irq_Cfg[55].Can_Controller_id = 6;
        Can_Irq_Cfg[55].int_num = 462;
        Can_Irq_Cfg[55].can_int_handler = CANSS6_INT0_ISR;
        
        Can_Irq_Cfg[56].Can_Controller_id = 6;
        Can_Irq_Cfg[56].int_num = 463;
        Can_Irq_Cfg[56].can_int_handler = CANSS6_INT1_ISR;
        
        Can_Irq_Cfg[57].Can_Controller_id = 6;
        Can_Irq_Cfg[57].int_num = 464;
        Can_Irq_Cfg[57].can_int_handler = CANSS6_DMU_ISR;
        
        Can_Irq_Cfg[58].Can_Controller_id = 6;
        Can_Irq_Cfg[58].int_num = 465;
        Can_Irq_Cfg[58].can_int_handler = CANSS6_DMA_ISR;
        
        Can_Irq_Cfg[59].Can_Controller_id = 6;
        Can_Irq_Cfg[59].int_num = 217;
        Can_Irq_Cfg[59].can_int_handler = CANSS6_FUSA_ERROR_ISR;
        
        Can_Irq_Cfg[60].Can_Controller_id = 6;
        Can_Irq_Cfg[60].int_num = 490;
        Can_Irq_Cfg[60].can_int_handler = CANSS6_FE0_ISR;
        
        Can_Irq_Cfg[61].Can_Controller_id = 6;
        Can_Irq_Cfg[61].int_num = 491;
        Can_Irq_Cfg[61].can_int_handler = CANSS6_FE1_ISR;
        
        Can_Irq_Cfg[62].Can_Controller_id = 6;
        Can_Irq_Cfg[62].int_num = 492;
        Can_Irq_Cfg[62].can_int_handler = CANSS6_FE2_ISR;
        
        Can_Irq_Cfg[63].Can_Controller_id = 7;
        Can_Irq_Cfg[63].int_num = 430;
        Can_Irq_Cfg[63].can_int_handler = CANSS7_FUSA_WARNING_ISR;
        
        Can_Irq_Cfg[64].Can_Controller_id = 7;
        Can_Irq_Cfg[64].int_num = 467;
        Can_Irq_Cfg[64].can_int_handler = CANSS7_INT0_ISR;
        
        Can_Irq_Cfg[65].Can_Controller_id = 7;
        Can_Irq_Cfg[65].int_num = 468;
        Can_Irq_Cfg[65].can_int_handler = CANSS7_INT1_ISR;
        
        Can_Irq_Cfg[66].Can_Controller_id = 7;
        Can_Irq_Cfg[66].int_num = 469;
        Can_Irq_Cfg[66].can_int_handler = CANSS7_DMU_ISR;
        
        Can_Irq_Cfg[67].Can_Controller_id = 7;
        Can_Irq_Cfg[67].int_num = 470;
        Can_Irq_Cfg[67].can_int_handler = CANSS7_DMA_ISR;
        
        Can_Irq_Cfg[68].Can_Controller_id = 7;
        Can_Irq_Cfg[68].int_num = 218;
        Can_Irq_Cfg[68].can_int_handler = CANSS7_FUSA_ERROR_ISR;
        
        Can_Irq_Cfg[69].Can_Controller_id = 7;
        Can_Irq_Cfg[69].int_num = 493;
        Can_Irq_Cfg[69].can_int_handler = CANSS7_FE0_ISR;
        
        Can_Irq_Cfg[70].Can_Controller_id = 7;
        Can_Irq_Cfg[70].int_num = 494;
        Can_Irq_Cfg[70].can_int_handler = CANSS7_FE1_ISR;
        
        Can_Irq_Cfg[71].Can_Controller_id = 7;
        Can_Irq_Cfg[71].int_num = 495;
        Can_Irq_Cfg[71].can_int_handler = CANSS7_FE2_ISR;
	}
	else
	{

	}

}

static void Can_Plt_Cfg_Gpio_Init(ChipInfoFamilyType chip_family)
{
    uint32 i = 0;
	uint32_t can_max_inst = Can_Plt_Cfg_Max_Supported_Instance(chip_family);

	if (chip_family == CHIPINFO_FAMILY_LEMANSAU)
    {
    	Can_Gpio_Cfg[0].num = CANSS0_TX_LEMANS_PIN;
    	Can_Gpio_Cfg[1].num = CANSS0_RX_LEMANS_PIN;
    	Can_Gpio_Cfg[2].num = CANSS1_TX_LEMANS_PIN;
    	Can_Gpio_Cfg[3].num = CANSS1_RX_LEMANS_PIN;
    	Can_Gpio_Cfg[4].num = CANSS2_TX_LEMANS_PIN;
    	Can_Gpio_Cfg[5].num = CANSS2_RX_LEMANS_PIN;
    	Can_Gpio_Cfg[6].num = CANSS3_TX_LEMANS_PIN;
    	Can_Gpio_Cfg[7].num = CANSS3_RX_LEMANS_PIN;
    	Can_Gpio_Cfg[8].num = CANSS4_TX_LEMANS_PIN;
    	Can_Gpio_Cfg[9].num = CANSS4_RX_LEMANS_PIN;
    	Can_Gpio_Cfg[10].num = CANSS5_TX_LEMANS_PIN;
    	Can_Gpio_Cfg[11].num = CANSS5_RX_LEMANS_PIN;
    	Can_Gpio_Cfg[12].num = CANSS6_TX_LEMANS_PIN;
    	Can_Gpio_Cfg[13].num = CANSS6_RX_LEMANS_PIN;
    	Can_Gpio_Cfg[14].num = CANSS7_TX_LEMANS_PIN;
    	Can_Gpio_Cfg[15].num = CANSS7_RX_LEMANS_PIN;
    }
    else if (chip_family == CHIPINFO_FAMILY_MONACOAU)
    {
    	Can_Gpio_Cfg[0].num = CANSS0_TX_MONACO_PIN;
    	Can_Gpio_Cfg[1].num = CANSS0_RX_MONACO_PIN;
    	Can_Gpio_Cfg[2].num = CANSS1_TX_MONACO_PIN;
    	Can_Gpio_Cfg[3].num = CANSS1_RX_MONACO_PIN;
    	Can_Gpio_Cfg[4].num = CANSS2_TX_MONACO_PIN;
    	Can_Gpio_Cfg[5].num = CANSS2_RX_MONACO_PIN;
    	Can_Gpio_Cfg[6].num = CANSS3_TX_MONACO_PIN;
    	Can_Gpio_Cfg[7].num = CANSS3_RX_MONACO_PIN;
    	Can_Gpio_Cfg[8].num = CANSS4_TX_MONACO_PIN;
    	Can_Gpio_Cfg[9].num = CANSS4_RX_MONACO_PIN;
    	Can_Gpio_Cfg[10].num = CANSS5_TX_MONACO_PIN;
    	Can_Gpio_Cfg[11].num = CANSS5_RX_MONACO_PIN;
    	Can_Gpio_Cfg[12].num = CANSS6_TX_MONACO_PIN;
    	Can_Gpio_Cfg[13].num = CANSS6_RX_MONACO_PIN;
    	Can_Gpio_Cfg[14].num = CANSS7_TX_MONACO_PIN;
    	Can_Gpio_Cfg[15].num = CANSS7_RX_MONACO_PIN;
    }
    else if (chip_family == CHIPINFO_FAMILY_NORDAU)
    {
        Can_Gpio_Cfg[0].num = CANSS0_TX_NORD_PIN;
        Can_Gpio_Cfg[1].num = CANSS0_RX_NORD_PIN;
        Can_Gpio_Cfg[2].num = CANSS1_TX_NORD_PIN;
        Can_Gpio_Cfg[3].num = CANSS1_RX_NORD_PIN;
        Can_Gpio_Cfg[4].num = CANSS2_TX_NORD_PIN;
        Can_Gpio_Cfg[5].num = CANSS2_RX_NORD_PIN;
        Can_Gpio_Cfg[6].num = CANSS3_TX_NORD_PIN;
        Can_Gpio_Cfg[7].num = CANSS3_RX_NORD_PIN;
        Can_Gpio_Cfg[8].num = CANSS4_TX_NORD_PIN;
        Can_Gpio_Cfg[9].num = CANSS4_RX_NORD_PIN;
        Can_Gpio_Cfg[10].num = CANSS5_TX_NORD_PIN;
        Can_Gpio_Cfg[11].num = CANSS5_RX_NORD_PIN;
        Can_Gpio_Cfg[12].num = CANSS6_TX_NORD_PIN;
        Can_Gpio_Cfg[13].num = CANSS6_RX_NORD_PIN;
        Can_Gpio_Cfg[14].num = CANSS7_TX_NORD_PIN;
        Can_Gpio_Cfg[15].num = CANSS7_RX_NORD_PIN;
    }
    else
    {

    }
	
	do{
		Can_Gpio_Cfg[i].cfg.dir = (uint8_t)GPIO_OUT;
		i++;
		Can_Gpio_Cfg[i].cfg.dir = (uint8_t)GPIO_IN;
        i++;
	}while(i < (can_max_inst*(uint32_t)NUM_GPIO_PER_CAN_CONTROLLER));

    for (i=0; i < (can_max_inst*(uint32_t)NUM_GPIO_PER_CAN_CONTROLLER); i++)
    {
		Can_Gpio_Cfg[i].cfg.func = 1;
		Can_Gpio_Cfg[i].cfg.pull = (uint8_t)GPIO_NP;
		Can_Gpio_Cfg[i].cfg.drive = (uint8_t)GPIO_8MA;
	}
}

static void Can_Plt_Cfg_Clk_Init(ChipInfoFamilyType chip_family)
{
    uint32 i = 0;
	uint8_t can_index = 0;
	uint32_t can_max_inst = Can_Plt_Cfg_Max_Supported_Instance(chip_family);

	(void)memset(Can_Clk_Cfg, 0, sizeof(Can_Clk_Cfg));
	
	do{
		can_index = (uint8_t)(i/2u);
        (void)snprintf(Can_Clk_Cfg[i].clkName, sizeof(Can_Clk_Cfg[i].clkName), "sailss_cc_can%d_ahb_clk", can_index); 
		Can_Clk_Cfg[i].freq = MTTCAN_AHB_CLOCK_FREQ;
		i++;
		(void)snprintf(Can_Clk_Cfg[i].clkName, sizeof(Can_Clk_Cfg[i].clkName), "sailss_cc_can%d_core_clk", can_index);
		Can_Clk_Cfg[i].freq = MTTCAN_CORE_CLOCK_FREQ;
		i++;	
	}while(i < (can_max_inst*(uint32_t)NUM_CLOCKS_PER_CAN_CONTROLLER));
}

void Can_Plt_Cfg_Get_IRQ(uint8 ControllerId, uint8 int_num, Can_IRQ_Config_Type* irq_out)
{
    *irq_out = Can_Irq_Cfg[ControllerId * NUM_IRQ_PER_CAN_CONTROLLER + int_num];
}

void Can_Plt_Cfg_Get_Gpio(uint8 ControllerId, uint8 gpio_num, Can_Gpio_Pin_Type* gpio_out)
{
    *gpio_out = Can_Gpio_Cfg[ControllerId * NUM_GPIO_PER_CAN_CONTROLLER + gpio_num];
}

void Can_Plt_Cfg_Get_Clock(uint8 ControllerId,  uint8 clock_num, CAN_MTTCAN_ClockType* clock_out)
{
    *clock_out = Can_Clk_Cfg[ControllerId * NUM_CLOCKS_PER_CAN_CONTROLLER + clock_num];
}

void Can_Plt_Get_TransceiverId_For_Can(uint8 ControllerId, CAN_TRCV_MAP_Type*            trcv_type, uint8* trcv_channel_id)
{
    if (Can_Tcan1146_Map[ControllerId] != CAN_TCAN_INVALID)
    {
        *trcv_type = CAN_TCAN1146_MAPPED;
        *trcv_channel_id = Can_Tcan1146_Map[ControllerId];
    }
    else if (Can_Tcan1044_Map[ControllerId] != CAN_TCAN_INVALID)
    {
        *trcv_type = CAN_TCAN1044_MAPPED;
        *trcv_channel_id = Can_Tcan1044_Map[ControllerId];
    }
    else
    {
        *trcv_type = CAN_NO_TRCV;
        *trcv_channel_id = CAN_TCAN_INVALID;
    }
}

void Can_Plt_Cfg_Init(void)
{
	ChipInfoFamilyType chip_family = CHIPINFO_FAMILY_32BITS;
    #if defined(CHIPINFO_FAMILY_LEMANS)
    chip_family = CHIPINFO_FAMILY_LEMANSAU;
    #elif defined(CHIPINFO_FAMILY_MONACO)
    chip_family = CHIPINFO_FAMILY_MONACOAU;
    #endif
    Can_Plt_Cfg_Trcv_Map_Init(chip_family);
    Can_Plt_Cfg_Irq_Init(chip_family);
    Can_Plt_Cfg_Gpio_Init(chip_family);
    Can_Plt_Cfg_Clk_Init(chip_family);
}


