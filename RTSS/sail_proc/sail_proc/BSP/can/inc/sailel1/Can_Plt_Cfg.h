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
#ifndef CAN_PLATFROM_CFG_H
#define CAN_PLATFROM_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

#include "gpio.h"
#include "Clock.h"
#include "ClockDefs.h"
#include "types.h"
#include "Can_SafeRTOS.h"

#define MAX_CLOCK_NAME_LEN            32U
#define MTTCAN_AHB_CLOCK_FREQ         100u
#define MTTCAN_CORE_CLOCK_FREQ        80u

#define CAN_TCAN1146_CHAN_0           0
#define CAN_TCAN1146_CHAN_1           1

#define CAN_TCAN1044_CHAN_0           0
#define CAN_TCAN1044_CHAN_1           1
#define CAN_TCAN1044_CHAN_2           2

#define CAN_TCAN_INVALID              0xFF

#define INVALID_PIN                   0xFF

/* Lemans configuration */

#define CANSS0_TX_LEMANS_PIN          37
#define CANSS0_RX_LEMANS_PIN          38
#define CANSS1_TX_LEMANS_PIN          39
#define CANSS1_RX_LEMANS_PIN          40
#define CANSS2_TX_LEMANS_PIN          41
#define CANSS2_RX_LEMANS_PIN          42
#define CANSS3_TX_LEMANS_PIN          43
#define CANSS3_RX_LEMANS_PIN          44
#define CANSS4_TX_LEMANS_PIN          45
#define CANSS4_RX_LEMANS_PIN          46
#define CANSS5_TX_LEMANS_PIN          47
#define CANSS5_RX_LEMANS_PIN          48
#define CANSS6_TX_LEMANS_PIN          49
#define CANSS6_RX_LEMANS_PIN          50
#define CANSS7_TX_LEMANS_PIN          51
#define CANSS7_RX_LEMANS_PIN          52

#define CANSS0_WUP_LEMANS_PIN         53   /* Wake-Up Capable TRCV  */
#define CANSS1_WUP_LEMANS_PIN         54   /* Wake-Up Capable TRCV  */
#define CANSS2_WUP_LEMANS_PIN         42   /* Wake-Up Capable TRCV  */
#define CANSS3_WUP_LEMANS_PIN         44   /* Wake-Up Capable TRCV  */
#define CANSS4_WUP_LEMANS_PIN         46   /* Wake-Up Capable TRCV  */
#define CANSS5_WUP_LEMANS_PIN         INVALID_PIN   /* Wake-up Not Supported */
#define CANSS6_WUP_LEMANS_PIN         INVALID_PIN   /* Wake-up Not Supported */
#define CANSS7_WUP_LEMANS_PIN         INVALID_PIN   /* Wake-up Not Supported */

/* Monaco configuration */
#define CANSS0_TX_MONACO_PIN          37
#define CANSS0_RX_MONACO_PIN          38
#define CANSS1_TX_MONACO_PIN          39
#define CANSS1_RX_MONACO_PIN          40
#define CANSS2_TX_MONACO_PIN          41
#define CANSS2_RX_MONACO_PIN          42
#define CANSS3_TX_MONACO_PIN          43
#define CANSS3_RX_MONACO_PIN          44
#define CANSS4_TX_MONACO_PIN          INVALID_PIN
#define CANSS4_RX_MONACO_PIN          INVALID_PIN
#define CANSS5_TX_MONACO_PIN          INVALID_PIN
#define CANSS5_RX_MONACO_PIN          INVALID_PIN
#define CANSS6_TX_MONACO_PIN          INVALID_PIN
#define CANSS6_RX_MONACO_PIN          INVALID_PIN
#define CANSS7_TX_MONACO_PIN          INVALID_PIN
#define CANSS7_RX_MONACO_PIN          INVALID_PIN

/* Nord configuration */

#define NORD_MAX_CAN_CNT              8u

#define CANSS0_TX_NORD_PIN            23
#define CANSS0_RX_NORD_PIN            24
#define CANSS1_TX_NORD_PIN            25
#define CANSS1_RX_NORD_PIN            26
#define CANSS2_TX_NORD_PIN            27
#define CANSS2_RX_NORD_PIN            28
#define CANSS3_TX_NORD_PIN            29
#define CANSS3_RX_NORD_PIN            30
#define CANSS4_TX_NORD_PIN            31
#define CANSS4_RX_NORD_PIN            32
#define CANSS5_TX_NORD_PIN            33
#define CANSS5_RX_NORD_PIN            34
#define CANSS6_TX_NORD_PIN            35
#define CANSS6_RX_NORD_PIN            36
#define CANSS7_TX_NORD_PIN            37
#define CANSS7_RX_NORD_PIN            38

#define CANSS0_WUP_NORD_PIN           39   /* Wake-Up Capable TRCV  */
#define CANSS1_WUP_NORD_PIN           40   /* Wake-Up Capable TRCV  */
#define CANSS2_WUP_NORD_PIN           28   /* Wake-Up Capable TRCV  */
#define CANSS3_WUP_NORD_PIN           30   /* Wake-Up Capable TRCV  */
#define CANSS4_WUP_NORD_PIN           32   /* Wake-Up Capable TRCV  */
#define CANSS5_WUP_NORD_PIN           INVALID_PIN   /* Wake-up Not Supported */
#define CANSS6_WUP_NORD_PIN           INVALID_PIN   /* Wake-up Not Supported */
#define CANSS7_WUP_NORD_PIN           INVALID_PIN   /* Wake-up Not Supported */


typedef enum
{
  CAN_INTR_TRIGGER_LEVEL,
  CAN_INTR_TRIGGER_EDGE,
  CAN_INTR_MAX
} CAN_INTR_TriggerType;

typedef struct{
    uint8 Can_Controller_id;
    uint32_t int_num;
    uint32_t int_cfg;
    void (*can_int_handler)(void *arg);
} Can_IRQ_Config_Type;

typedef struct
{
	int32_t        num;
	GPIOConfigType  cfg;
}Can_Gpio_Pin_Type;

typedef struct
{
    char     clkName[MAX_CLOCK_NAME_LEN];
    uint32_t freq;
}CAN_MTTCAN_ClockType;

void Can_Plt_Cfg_Get_IRQ(uint8 ControllerId, uint8 int_num, Can_IRQ_Config_Type* irq_out);
void Can_Plt_Cfg_Get_Gpio(uint8 ControllerId, uint8 gpio_num, Can_Gpio_Pin_Type* gpio_out);
void Can_Plt_Cfg_Get_Clock(uint8 ControllerId,  uint8 clock_num, CAN_MTTCAN_ClockType* clock_out);
void Can_Plt_Get_TransceiverId_For_Can(uint8 ControllerId, CAN_TRCV_MAP_Type* trcv_type, uint8* trcv_channel_id);

void Can_Plt_Cfg_Init(void);

#ifdef __cplusplus
}
#endif

#endif /* CAN_PLATFROM_CFG_H */
