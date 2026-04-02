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

#ifdef __cplusplus
extern "C"{
#endif

#include "CanTrcv_184_Tcan1044_SafeRTOS.h"
#include "CanTrcv_184_Tcan1044_Plt_Cfg.h"
#include "debug_log.h"

/*===========================================================================
**  Function :  CanTrcv_184_Tcan1044_Safertos_Config_Gpio
** ==========================================================================
*/
void CanTrcv_184_Tcan1044_Config_Standby_Gpio(uint8 channel_id)
{
    CanTcrv1044_Gpio_Pin_Type standby_cfg = {0};
    eSailGPIOStatus_t status = GPIO_E_NOT_OK;

    if (channel_id >= CAN_TCAN1044_MAX_CNT)
    {
        return;
    }

    CanTcrv1044_Plt_Cfg_Get_Standby_Gpio(channel_id, &standby_cfg);

    status = sail_gpio_config_pin((uint32_t)(standby_cfg.gpio_num), standby_cfg.gpio_cfg);
	if(status == GPIO_E_NOT_OK)
	{
		DEBUG_LOG(LOG_ERROR, "%s failed, gpio = %d, status = %d \r\n",
                                     __func__, standby_cfg.gpio_num, status);
	}
}


/*===========================================================================
**  Function :  CanTrcv_184_Tcan1044_Config_Wakeup_Gpio
**  Note: Rx reused as wake up interrupt, gpio configuration are different
** ==========================================================================
*/
void CanTrcv_184_Tcan1044_Config_Wakeup_Gpio(uint8 channel_id)
{
    CanTcrv1044_Gpio_Pin_Type wakeup_cfg = {0};
    eSailGPIOStatus_t status = GPIO_E_NOT_OK;

    if (channel_id >= CAN_TCAN1044_MAX_CNT)
    {
        return;
    }
    CanTcrv1044_Plt_Cfg_Get_WakeUp_Gpio(channel_id, &wakeup_cfg);
    
    status = sail_gpio_config_pin((uint32_t)(wakeup_cfg.gpio_num), wakeup_cfg.gpio_cfg);
    if(status == GPIO_E_NOT_OK)
	{
		DEBUG_LOG(LOG_ERROR, "%s failed, gpio = %d, status = %d \r\n",
											__func__, wakeup_cfg.gpio_num, status);
	}
}


/* =========================================================================
**  Function : CanTrcv_184_Tcan1044_Register_WakeUp_IRQ
** =========================================================================*/

void CanTrcv_184_Tcan1044_Register_WakeUp_IRQ(uint8 channel_id)
{
    CanTcrv1044_Gpio_IRQ_Config_Type irq_cfg = {0};
    int32 status = UGPIOINT_ERROR;
        uint32 ulcpu_Id = get_curr_phys_cpu_num();

    if (channel_id >= CAN_TCAN1044_MAX_CNT)
    {
        return;
    }

    CanTcrv1044_Plt_Cfg_Get_WakeUp_IRQ(channel_id, &irq_cfg);

    if(irq_cfg.int_handler != NULL)
    {
            status = eGpio_RegisterDirectIntr(
                                       irq_cfg.gpio_num,  
                                       irq_cfg.int_cfg,
                                       (uGPIOINTISR)irq_cfg.int_handler, 
                                       (uGPIOINTISR)&CanTcrv1044_Wup_Irq_Cfg[channel_id]);
        if(status == UGPIOINT_ERROR )
		{
			DEBUG_LOG(LOG_ERROR, "%s failed, gpio = %d, int_cfg = %d, status = %d \r\n",
												__func__, irq_cfg.gpio_num, irq_cfg.int_cfg, status);
		}
    }
}

/* =========================================================================
**  Function : CanTrcv_184_Tcan1044_Deregister_WakeUp_IRQ
** =========================================================================*/
void CanTrcv_184_Tcan1044_Deregister_WakeUp_IRQ(uint8 channel_id)
{
    CanTcrv1044_Gpio_IRQ_Config_Type irq_cfg = {0};
    int32 status = UGPIOINT_ERROR;

    if (channel_id >= CAN_TCAN1044_MAX_CNT)
    {
        return;
    }

    CanTcrv1044_Plt_Cfg_Get_WakeUp_IRQ(channel_id, &irq_cfg);

    if(irq_cfg.int_handler != NULL)
    {
            status = eGpio_DeregisterDirectIntr(irq_cfg.gpio_num);
		if( status == UGPIOINT_ERROR )
		{
			DEBUG_LOG(LOG_ERROR, "%s, gpio = %d, status = %d \r\n",
                                        __func__, irq_cfg.gpio_num, status);
		}
    }
}


/* =========================================================================
**  Function : CanTrcv_184_Tcan1044_WakeUp_IRQ_Enable
** =========================================================================*/
/**
  Wrapper Function to enable wake up capable interrupts
  @param
  CAN_Instance_ID.

  @return
  None.

  @dependencies
  Interrupts.h.
 */

void CanTrcv_184_Tcan1044_WakeUp_IRQ_Enable(uint8 channel_id)
{
    CanTcrv1044_Gpio_IRQ_Config_Type irq_cfg = {0};
    int32 status = UGPIOINT_ERROR;

    if (channel_id >= CAN_TCAN1044_MAX_CNT)
    {
        return;
    }

    CanTcrv1044_Plt_Cfg_Get_WakeUp_IRQ(channel_id, &irq_cfg);

    if(irq_cfg.int_handler != NULL)
    {
            status = eGpio_EnableDirectIntr(irq_cfg.gpio_num);
		if( status == UGPIOINT_ERROR )
		{
			DEBUG_LOG(LOG_ERROR, "%s failed, gpio = %d, status = %d \r\n",
													__func__, irq_cfg.gpio_num, status);
		}
    }
}

/* =========================================================================
**  Function : CanTrcv_184_Tcan1044_Wakeup_IRQ_Disable
** =========================================================================*/
/**
  Wrapper Function to disable wake up capable interrupts
  @param
  CAN_Instance_ID.

  @return
  None.

  @dependencies
  Interrupts.h.
 */

void CanTrcv_184_Tcan1044_Wakeup_IRQ_Disable(uint8 channel_id)
{
    CanTcrv1044_Gpio_IRQ_Config_Type irq_cfg = {0};
    int32 status = UGPIOINT_ERROR;

    if (channel_id >= CAN_TCAN1044_MAX_CNT)
    {
        return;
    }

    CanTcrv1044_Plt_Cfg_Get_WakeUp_IRQ(channel_id, &irq_cfg);

    if(irq_cfg.int_handler != NULL)
    {

            status = eGpio_DisableDirectIntr(irq_cfg.gpio_num);
		if( status == UGPIOINT_ERROR )
		{
			DEBUG_LOG(LOG_ERROR, "%s failed, gpio = %d, status = %d \r\n",
													__func__, irq_cfg.gpio_num, status);
		}
    }
}



#ifdef __cplusplus
}
#endif
