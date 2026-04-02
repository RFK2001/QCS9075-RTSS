/**
 * @file gpio.c
 * @brief
 * Source file for gpio driver of SAIL
 *
 *        Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*==========================================================================*/
#include "gpio.h"
#include <stdio.h>
#include "gpio_summary_intr.h"
#include "gpio_direct_intr.h"
#include "types.h"
#include "HALhwio.h"
#include "sail_tlmm_hwio.h"
#include "boot_logger.h"
#include "err_fatal.h"


GPIO_GLOBAL_DATA uint32_t sail_gpio_base = 0u;

/*Updated to GPIO_E_OK in eGpio_DirectIntrInit API*/
GPIO_GLOBAL_DATA  eSailGPIOStatus_t eGpioDirectIntrInitStatus = GPIO_E_NOT_OK;

/*===========================================================================
**  Function :  sail_gpio_WritePin
** ==========================================================================
*/
/*!
*
* @brief
*   Programs the output value of a GPIO pin.
*
* @param
*	@param[in] ngpio - gpio number
*	@param[in] nvalue - The value (HIGH/LOW) to write
* @par Dependencies
*   None
* @retval
*   The pin signal value read, high or low
* @par Side Effects
*   None
*/
static eSailGPIOStatus_t eSailGPIOWakeUpConfig(void)
{

#ifndef monaco
  eSailGPIOStatus_t eGpioStatus = GPIO_E_NOT_OK;
  uint32_t uiRegValue = 0;
  uint32_t uiReadBackRegValue = 0;

  uiRegValue = HWIO_SAILSS_TLMM_SAILSS_TLMM_WEST_MPM_WAKEUP_INT_EN_1_IN;
  
  /* Enable input of GPIO 63 and 65 for the wakeup path */
  uiRegValue = uiRegValue | HWIO_SAILSS_TLMM_SAILSS_TLMM_WEST_MPM_WAKEUP_INT_EN_1_GPIO_65_BMSK;

  HWIO_SAILSS_TLMM_SAILSS_TLMM_WEST_MPM_WAKEUP_INT_EN_1_OUT(uiRegValue);
  uiReadBackRegValue = HWIO_SAILSS_TLMM_SAILSS_TLMM_WEST_MPM_WAKEUP_INT_EN_1_IN;
  if(uiReadBackRegValue == uiRegValue)
  {
    eGpioStatus =  GPIO_E_OK;
  }

#else
  eSailGPIOStatus_t eGpioStatus =  GPIO_E_OK;
#endif

  return eGpioStatus;
}
/*===========================================================================
**  Function :  sail_gpio_WritePin
** ==========================================================================
*/
/*!
*
* @brief
*   Programs the output value of a GPIO pin.
*
* @param
*	@param[in] ngpio - gpio number
*	@param[in] nvalue - The value (HIGH/LOW) to write
* @par Dependencies
*   None
* @retval
*   The pin signal value read, high or low
* @par Side Effects
*   None
*
*/
eSailGPIOStatus_t sail_gpio_WritePin(uint32_t uiGPIOn, uint32_t uiValue)
{
	uint32_t nVal = 0u;
	GPIOValueType Gpio_LevelStatus = GPIO_VALUE_FORCE32;
	eSailGPIOStatus_t eGpioStatus = GPIO_E_NOT_OK;

	/*Checking whether input parameters are within range or not*/
	if(uiGPIOn <= SAIL_GPIO_MAX_NUM_PINS)
	{
		if ( uiValue == (uint32_t)GPIO_HIGH )
		{
			nVal = 0x1u;
		}
		out_dword(((sail_gpio_base + (PIN_WIDTH * uiGPIOn)) + SAIL_GPIO_IN_OUT_REG_OFFS_BMSK), ((nVal & 0x1u) << 1u));
		if((in_dword((sail_gpio_base + (PIN_WIDTH * uiGPIOn)) + SAIL_GPIO_IN_OUT_REG_OFFS_BMSK) & 0x1u) != 0u)
		{
			Gpio_LevelStatus = GPIO_HIGH;
		}
		else
		{
			Gpio_LevelStatus = GPIO_LOW;
		}
		if(uiValue == (uint32_t)Gpio_LevelStatus)
		{
			eGpioStatus = GPIO_E_OK;
		}
	}

	return eGpioStatus;
}

/*===========================================================================
**  Function :  sail_gpio_ReadPin
** ==========================================================================
*/
/*!
*
* @brief
*   Returns the value of the GPIO signal (HIGH or LOW) in boolean format.
*
* @param
*	@param[in] ngpio - gpio number
*
* @par Dependencies
*   None
* @retval
*   The pin signal value read, high or low
* @par Side Effects
*   None
*
*/
GPIOValueType sail_gpio_ReadPin(uint32_t uiGPIOn)
{
	GPIOValueType Gpio_LevelStatus = GPIO_VALUE_FORCE32;

	GPIOValueType eReadValue = GPIO_VALUE_FORCE32;
	/*Checking whether input parameters are within range or not*/
	if(uiGPIOn <= SAIL_GPIO_MAX_NUM_PINS)
	{
		if((in_dword((sail_gpio_base + (PIN_WIDTH * uiGPIOn)) + SAIL_GPIO_IN_OUT_REG_OFFS_BMSK) & 0x1u) != 0u)
		{
			eReadValue = GPIO_HIGH;
	}
	else
	{
			eReadValue = GPIO_LOW;
		}
		if(GPIO_HIGH == eReadValue)
		{
			Gpio_LevelStatus = GPIO_HIGH;
		}
		else
		{
			Gpio_LevelStatus = GPIO_LOW;
		}
	}

	return Gpio_LevelStatus;
}

/*===========================================================================
**  Function :  sail_gpio_ReadPinOutput
** ==========================================================================
*/
/*!
*
* @brief
*    Reads the programmed output value of a GPIO pin.
*
* @param
*	@param[in] ngpio - gpio number
*
* @par Dependencies
*   None
* @retval
*   The pin signal value read, high or low
* @par Side Effects
*   None
*
*/
GPIOValueType sail_gpio_ReadPinOutput(uint32_t uiGPIOn)
{
	GPIOValueType Gpio_LevelStatus = GPIO_VALUE_FORCE32;
	uint32_t uiReadBackValue = 0u;
	
	/*Checking whether input parameters are within range or not*/
	if(uiGPIOn <= SAIL_GPIO_MAX_NUM_PINS)
	{
		uiReadBackValue = ((in_dword(((sail_gpio_base + (PIN_WIDTH * uiGPIOn)) + SAIL_GPIO_IN_OUT_REG_OFFS_BMSK)) & 0x2u) >> 1u) & 0x1u;
		if (1u == uiReadBackValue)
		{
			Gpio_LevelStatus =  GPIO_HIGH;
		}
		else
		{
			Gpio_LevelStatus = GPIO_LOW;
		}
	}

	return Gpio_LevelStatus;

}

/*===========================================================================
**  Function :  sail_gpio_get_pin_config
** ==========================================================================
*/
/*!
*
* @brief
*   Reads a gpio configuration
*
* @param
*	@param[in] ngpio - gpio number
*	@param[out] cfg   - gpio configuration to be read
* @par Dependencies
*   None
* @retval
*   None
* @par Side Effects
*   None
*
*/
void sail_gpio_get_pin_config(uint32 uiGPIOn, GPIOConfigType *pcfg)
{

	if(uiGPIOn <= SAIL_GPIO_MAX_NUM_PINS)
	{
		uint32 nregval = in_dword((sail_gpio_base + (PIN_WIDTH * uiGPIOn)));

		pcfg->func   = (uint8_t)SAIL_GPIO_GET_FUNC(nregval);
		pcfg->dir    = (uint8_t)SAIL_GPIO_GET_DIR(nregval);
		pcfg->pull   = (uint8_t)SAIL_GPIO_GET_PULL(nregval);
		pcfg->drive  = (uint8_t)SAIL_GPIO_GET_DRIVE(nregval);
	}


}

/*===========================================================================
**  Function :  sail_gpio_config_pin
** ==========================================================================
*/
/*!
*
* @brief
*   Configures a gpio's pull, direction, drive strength and function
*
* @param
*	@param[in] ngpio - gpio number
*	@param[in] cfg   - gpio configuration
* @par Dependencies
*   None
* @retval
*   None
* @par Side Effects
*   None
*
*/
eSailGPIOStatus_t sail_gpio_config_pin(uint32_t uiGPIOn, GPIOConfigType cfg)
{
	uint16_t nRegVal = 0u;
	eSailGPIOStatus_t eGpioStatus = GPIO_E_NOT_OK;
	GPIOConfigType CfgCheck;

	/*Checking whether input parameters are within range or not*/
	if(uiGPIOn <= SAIL_GPIO_MAX_NUM_PINS)
	{
		nRegVal = SAIL_GPIO_CFG_TO_REG(cfg.func,
								  cfg.dir,
	                              cfg.pull,
	                              cfg.drive);
		out_dword(sail_gpio_base + (PIN_WIDTH * uiGPIOn), nRegVal);
		sail_gpio_get_pin_config(uiGPIOn,&CfgCheck);
		if((CfgCheck.func == cfg.func) && (CfgCheck.dir == cfg.dir) && (CfgCheck.pull == cfg.pull) && (CfgCheck.drive == cfg.drive))
		{
			eGpioStatus = GPIO_E_OK;
	}
	}

	return eGpioStatus;
}

/*===========================================================================
**  Function :  sail_gpio_config_group
** ==========================================================================
*/
/*!
*
* @brief
*   Configures a group of gpio's pull, direction, drive strength and function
*
* @param
*	@param[in] ngpio - array of gpio numbers
*	@param[in] cfg   - array of gpio configurations
*	@param[in] nSize - size of the arrays ngpio and cfg
* @par Dependencies
*   None
* @retval
*   None
* @par Side Effects
*   None
*
*/
eSailGPIOStatus_t sail_gpio_config_group( const uint32_t * uiGPIOn,  const GPIOConfigType *cfg, uint32_t nSize)
{
	uint32_t nIdx = 0u;
	eSailGPIOStatus_t eGpioStatus = GPIO_E_NOT_OK;
	
	if((NULL != uiGPIOn) && (NULL != cfg) && (nSize <= SAIL_GPIO_MAX_NUM_PINS))
	{
		for(nIdx = 0u; nIdx < nSize; nIdx++)
	{
			eGpioStatus = sail_gpio_config_pin(uiGPIOn[nIdx], cfg[nIdx]);
			if(GPIO_E_OK != eGpioStatus)
			{
				break;
			}
		}
	}
	return eGpioStatus;
}

/*===========================================================================
**  Function :  sail_gpio_init
** ==========================================================================
*/
/*!
*
* @brief
*   Gpio init function
*
* @param
*
* @par Dependencies
*   None
* @retval
*   None
* @par Side Effects
*   None
*
*/
void sail_gpio_init(void)
{
	uint64 uiGpioTime = 0u;
	eSailGPIOStatus_t eGpioStatus = GPIO_E_NOT_OK;
	int32_t siSummaryIntr;
	uint32_t nCurrCPU = 0u;

	nCurrCPU = GPIO_GET_CURRENT_CORE();
	uiGpioTime = uBootLogger_LogStartTime("GPIO Init Started on core", (int32_t)nCurrCPU);
	sail_gpio_base = SAILSS_TLMM_SAILSS_TLMM_BASE;

	if((SAIL_R52_CLUSTER_0_CORE_0 == nCurrCPU) || (SAIL_R52_CLUSTER_1_CORE_0 == nCurrCPU))
	{
		siSummaryIntr = uGPIOSummaryInt_Init();
	}
	else
	{
		siSummaryIntr = UGPIOINT_SUCCESS;
	}

	/* enabling mx path from psail_err_n pad to isd */
	eGpioStatus = eSailGPIOWakeUpConfig();

	eGpioDirectIntrInitStatus = GPIO_E_OK;
	if((UGPIOINT_SUCCESS == siSummaryIntr) && (GPIO_E_OK == eGpioStatus))
	{
		(void)vBootLogger_LogDeltaTime(uiGpioTime, "GPIO Init Done on core", (int32_t)nCurrCPU);
	}
	else
	{
		(void)vBootLogger_LogDeltaTime(uiGpioTime, "GPIO Init Failed on core", (int32_t)nCurrCPU);
		err_fatal(GPIO_INIT ,(int32_t)GPIO_INIT_FAILED);
	}
	
}
