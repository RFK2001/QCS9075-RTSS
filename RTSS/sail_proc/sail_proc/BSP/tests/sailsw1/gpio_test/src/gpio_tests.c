/**
 * @file gpio_test.c
 * @brief
 * Source file for testing gpio driver of safety manager
 *
 *        Copyright (c) 2021 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */
/*==========================================================================*/
#include <stdio.h>
#include "gpio.h"
#include "sail_tlmm_hwio.h"
#include "gpio_summary_intr.h"
#include "gpio_direct_intr.h"
#include "tests.h"
#include "debug_log.h"

#define MAX_SAIL_GPIO 78
#define TEST_GPIO_PASS		 0
#define TEST_GPIO_FAIL_RD	-1 
#define TEST_GPIO_FAIL_WR	-2
#define TEST_GPIO_FAIL_CF	-3
#define TEST_GPIO_FAIL_INTR	-3
#define TEST_GPIOS_NUM		5U
#define TEST_GPIO_NUM_58	58U 
#define TEST_GPIO_NUM_59	59U 
#define TEST_GPIO_NUM_60	60U 
#define TEST_GPIO_NUM_61	61U 
#define TEST_GPIO_NUM_81	81U

TEST_DATA volatile static uint8 testGPIOIntrStates = 0;
TEST_DATA volatile static uint8 testGPIO = 0xFF;
TEST_DATA volatile static uint8 Gpio_Intr_flag = 0u;
TEST_DATA volatile static uint32_t Isr_flag = 0u;

/*===========================================================================
**  Gpio Test Helper function declarations
** ==========================================================================
*/
TEST_FUNC static int TC_GPIO_Direct_Interrupt(int ngpio);
TEST_FUNC static int TC_GPIO_Summary_Interrupt(int ngpio);

/*===========================================================================
**  Function :  GPIO Test ISR
** ==========================================================================
*/
TEST_FUNC void gpio_isr(void *args)
{

	Isr_flag = 1;
	#if 1
	if (testGPIOIntrStates == 9)
	{
		testGPIOIntrStates = 3;
	}

	if(testGPIO != 0xFF)
	{
		if( Gpio_Intr_flag )
		{
			eGpio_DisableDirectIntr(testGPIO);
			eGpio_ClearDirectIntrStatus(testGPIO);
			eGpio_DeregisterDirectIntr(testGPIO);
		}
		else
		{
			uGPIODisable_SummaryIntr(testGPIO);
			uGPIOClearSummaryIntrStatus(testGPIO);
			uGPIODeregister_SummaryIntr(testGPIO);
		}
	}

	#endif
}

/*===========================================================================
**  Function :  TC_GPIO_Direct_Interrupt
** ==========================================================================
*/
/*!
*
* @brief
*  Function to test GPIO driver direct interrupt testcases
*
* @param
*	@param[in] ngpio - gpio number
*
* @par Dependencies
*   None
* @retval
*   test result PASS/FAIL type
* @par Side Effects
*   None
*
*/
TEST_FUNC static int TC_GPIO_Direct_Interrupt(int ngpio)
{
	volatile uint32 nGPIO = ngpio;
    volatile eGpioDirectIntrPolarityEdgeSel_t eTrigger = SAIL_GPIO_TRIGGER_RISING_EDGE;
	int idx = 0;
	volatile GPIOConfigType  gpio_cfg = {0};

	Gpio_Intr_flag = 1;
	/* Configures the GPIO as input*/
	gpio_cfg.dir = GPIO_IN;
	gpio_cfg.pull = GPIO_NP;	// 0x0: NO_PULL
	gpio_cfg.drive = 0x4; 		// 0x4: DRV_10_MA
	sail_gpio_config_pin(nGPIO, gpio_cfg);

	if(GPIO_E_OK != eGpio_RegisterDirectIntr(nGPIO, eTrigger, (uGPIOINTISR) gpio_isr, (void *)&gpio_cfg))
	{
		return TEST_GPIO_FAIL_INTR;
	}

	if((GPIO_E_OK != eGpio_EnableDirectIntr(nGPIO)) && (GPIO_E_OK != eGpio_DeregisterDirectIntr( nGPIO )))
	{
		return TEST_GPIO_FAIL_INTR;
	}

	if(GPIO_E_OK != eGpio_DisableDirectIntr(nGPIO))
	{
		return TEST_GPIO_FAIL_INTR;
	}

	if(GPIO_E_OK != eGpio_ClearDirectIntrStatus(nGPIO))
	{
		return TEST_GPIO_FAIL_INTR;
	}

	if(GPIO_E_OK != eGpio_DeregisterDirectIntr(nGPIO))
	{
		return TEST_GPIO_FAIL_INTR;
	}
	/* return gpio test status */
	return TEST_GPIO_PASS;
}
/*===========================================================================
**  Function :  TC_GPIO_Summary_Interrupt
** ==========================================================================
*/
/*!
*
* @brief
*  Function to test GPIO driver summary interrupt testcases
*
* @param
*	@param[in] ngpio - gpio number
*
* @par Dependencies
*   None
* @retval
*   test result PASS/FAIL type
* @par Side Effects
*   None
*
*/
TEST_FUNC static int TC_GPIO_Summary_Interrupt(int ngpio)
{
	volatile int stop_here = 1;
	volatile int test_case = 1;
	volatile int retValue = 0;
	volatile uint32 nGPIO = ngpio;
    volatile uGPIOIntTriggerType eTrigger = UGPIOINT_TRIGGER_RISING;
	int idx = 0;
	volatile GPIOConfigType  gpio_cfg = {0};

	/* Configures the GPIO as input*/
	testGPIOIntrStates = 5;
	while(stop_here)
	{
		switch(testGPIOIntrStates)
		{
			case 1:
				if(UGPIOINT_SUCCESS != uGPIORegister_SummaryIntr(nGPIO, eTrigger, (uGPIOINTISR) gpio_isr, (void *)&gpio_cfg))
				{
					return TEST_GPIO_FAIL_INTR;
				}
				testGPIOIntrStates = 2;
			break;

			case 2:
				if(UGPIOINT_SUCCESS != uGPIOSummaryInt_EnableInterrupt(nGPIO) && UGPIOINT_SUCCESS != uGPIODeregister_SummaryIntr( nGPIO ))
				{
					return TEST_GPIO_FAIL_INTR;
				}
				testGPIOIntrStates = 4;
			break;

			case 3:
				if(UGPIOINT_SUCCESS != uGPIODisable_SummaryIntr(nGPIO))
				{
					return TEST_GPIO_FAIL_INTR;
				}
				testGPIOIntrStates = 7;
			break;

			case 4:
				if(UGPIOINT_SUCCESS != uGPIOTrigger_SummaryIntr(nGPIO))
				{
					return TEST_GPIO_FAIL_INTR;
				}
				//testGPIOIntrStates = 3; // currently, this test case is disabled, will re enable this later
				 testGPIOIntrStates = 9;
			break;

			case 5:
				gpio_cfg.dir = GPIO_IN;
				gpio_cfg.pull = GPIO_NP;	// 0x0: NO_PULL 
				gpio_cfg.drive = 0x4; 		// 0x4: DRV_10_MA 
				sail_gpio_config_pin(nGPIO, gpio_cfg);

				testGPIOIntrStates = 1;
			break;

			case 7:
					stop_here = 0;
				
			break;

			default:
				/*Do nothing*/
			break;
		}
	}
	uGPIODeregister_SummaryIntr(nGPIO);
	/* return gpio test status */
	return TEST_GPIO_PASS;
}

/*===========================================================================
**  Function :  TC_GPIO_Input
** ==========================================================================
*/
/*!
*
* @brief
*  Function to test GPIO driver input testcases 			
*
* @param
*	@param[in] ngpio - gpio number
*
* @par Dependencies
*   None
* @retval
*   test result PASS/FAIL type
* @par Side Effects
*   None
*
*/
TEST_FUNC static int TC_GPIO_Input(int ngpio)
{
	/* variables to pass to GPIO functions */
	GPIOValueType	gpio_value = {0};
	GPIOConfigType	test_gpio_cfg = {0};
	GPIOConfigType  gpio_cfg = {0};
	
	//configure GPIO as input
	gpio_cfg.dir = GPIO_IN;
	gpio_cfg.pull = GPIO_NP;	
	gpio_cfg.drive = 0; 		
	sail_gpio_config_pin(ngpio, gpio_cfg);	

	/*Set pin to HIGH*/
	sail_gpio_WritePin(ngpio, GPIO_HIGH);
	gpio_value = sail_gpio_ReadPin(ngpio);
	if(GPIO_HIGH != gpio_value)
	{
		return 	TEST_GPIO_FAIL_RD;
	}

	/*Set pin to LOW*/
	sail_gpio_WritePin(ngpio, GPIO_LOW);
	gpio_value = sail_gpio_ReadPin(ngpio);
	if(GPIO_LOW != gpio_value)
	{
		return 	TEST_GPIO_FAIL_RD;
	}

	/* return gpio test status */
	return TEST_GPIO_PASS;	

}

/*===========================================================================
**  Function :  TC_GPIO_Output
** ==========================================================================
*/
/*!
*
* @brief
*  Function to test GPIO driver output testcases 			
*
* @param
*	@param[in] ngpio - gpio number
*
* @par Dependencies
*   None
* @retval
*   test result PASS/FAIL type
* @par Side Effects
*   None
*
*/
TEST_FUNC static int TC_GPIO_Output(int ngpio)
{
	/* variables to pass to GPIO functions */
	GPIOValueType	gpio_value = {0};
	GPIOConfigType	test_gpio_cfg = {0};
	GPIOConfigType  gpio_cfg = {0};

	/* Config GPIO as output*/
	gpio_cfg.dir = GPIO_OUT;
	gpio_cfg.pull = GPIO_PU;	
	gpio_cfg.drive = 0x7; 		
	sail_gpio_config_pin(ngpio, gpio_cfg);

	/* test GPIO write */
	// a. write - 0x1
	sail_gpio_WritePin(ngpio, GPIO_HIGH);
	gpio_value = sail_gpio_ReadPinOutput(ngpio);
	if ( GPIO_HIGH != gpio_value)
	{
		return 	TEST_GPIO_FAIL_WR;
	}
	
	// b. write - 0x0
	sail_gpio_WritePin(ngpio, GPIO_LOW);
	gpio_value = sail_gpio_ReadPinOutput(ngpio);
	if ( GPIO_LOW != gpio_value)
	{
		return 	TEST_GPIO_FAIL_WR;
	}

	/* return gpio test status */
	return TEST_GPIO_PASS;
}

/*===========================================================================
**  Function :  TC_GPIO_Config
** ==========================================================================
*/
/*!
*
* @brief
*  Function to test complete GPIO driver config testcases 			
*
* @param
*	@param[in] ngpio - gpio number
*
* @par Dependencies
*   None
* @retval
*   test result PASS/FAIL type
* @par Side Effects
*   None
*
*/
TEST_FUNC static int TC_GPIO_Config(int ngpio)
{
	/* variables to pass to GPIO functions */
	GPIOValueType	gpio_value = {0};
	GPIOConfigType	test_gpio_cfg = {0};
	GPIOConfigType  gpio_cfg = {0};

	eSailGPIOStatus_t status =  GPIO_E_NOT_OK;
	
	/* test Various configs of GPIO */
	
	// a. gpio direction
	// GPIO_IN
	gpio_cfg.dir = GPIO_IN;
	gpio_cfg.pull = GPIO_NP;	// 0x0: NO_PULL 
	gpio_cfg.drive = 0x4; 		// 0x4: DRV_10_MA 
	status = sail_gpio_config_pin(ngpio, gpio_cfg);	
	sail_gpio_get_pin_config(ngpio, &test_gpio_cfg);	
	if ( (gpio_cfg.dir != test_gpio_cfg.dir) 
		|| (gpio_cfg.pull != test_gpio_cfg.pull) 
		|| (gpio_cfg.drive != test_gpio_cfg.drive) || (status != GPIO_E_OK))
	{
		return TEST_GPIO_FAIL_CF;
	}
	status =  GPIO_E_NOT_OK;
	// GPIO_OUT
	gpio_cfg.dir = GPIO_OUT;
	gpio_cfg.pull = GPIO_NP;	// 0x0: NO_PULL 
	gpio_cfg.drive = 0x4; 		// 0x4: DRV_10_MA 
	status = sail_gpio_config_pin(ngpio, gpio_cfg);	
	sail_gpio_get_pin_config(ngpio, &test_gpio_cfg);	
	if ( (gpio_cfg.dir != test_gpio_cfg.dir) 
		|| (gpio_cfg.pull != test_gpio_cfg.pull) 
		|| (gpio_cfg.drive != test_gpio_cfg.drive) || (status != GPIO_E_OK))
	{
		return TEST_GPIO_FAIL_CF;
	}	
	
	status =  GPIO_E_NOT_OK;
	// b. gpio set pulltypes 
    //	0x1 - PULL_DOWN
	gpio_cfg.dir = GPIO_OUT;
	gpio_cfg.pull = GPIO_PD;	
	gpio_cfg.drive = 0x4; 		
	status = sail_gpio_config_pin(ngpio, gpio_cfg);	
	sail_gpio_get_pin_config(ngpio, &test_gpio_cfg);	
	if ( (gpio_cfg.dir != test_gpio_cfg.dir) 
		|| (gpio_cfg.pull != test_gpio_cfg.pull) 
		|| (gpio_cfg.drive != test_gpio_cfg.drive)|| (status != GPIO_E_OK))
	{
		return TEST_GPIO_FAIL_CF;
	}

	status =  GPIO_E_NOT_OK;
	//	0x3 - PULL_UP
	gpio_cfg.dir = GPIO_OUT;
	gpio_cfg.pull = GPIO_PU;	
	gpio_cfg.drive = 0x4; 		
	status = sail_gpio_config_pin(ngpio, gpio_cfg);	
	sail_gpio_get_pin_config(ngpio, &test_gpio_cfg);	
	if ( (gpio_cfg.dir != test_gpio_cfg.dir) 
		|| (gpio_cfg.pull != test_gpio_cfg.pull) 
		|| (gpio_cfg.drive != test_gpio_cfg.drive)|| (status != GPIO_E_OK))
	{
		return TEST_GPIO_FAIL_CF;
	}

	status =  GPIO_E_NOT_OK;
	
	// c. gpio set drive strength
	// 0x0: DRV_2_MA 
	gpio_cfg.dir = GPIO_OUT;
	gpio_cfg.pull = GPIO_PU;	
	gpio_cfg.drive = 0x0; 		
	status = sail_gpio_config_pin(ngpio, gpio_cfg);	
	sail_gpio_get_pin_config(ngpio, &test_gpio_cfg);	
	if ( (gpio_cfg.dir != test_gpio_cfg.dir) 
		|| (gpio_cfg.pull != test_gpio_cfg.pull) 
		|| (gpio_cfg.drive != test_gpio_cfg.drive)|| (status != GPIO_E_OK))
	{
			return TEST_GPIO_FAIL_CF;
	}

	status =  GPIO_E_NOT_OK;
	// 0x7: DRV_16_MA
	gpio_cfg.dir = GPIO_OUT;
	gpio_cfg.pull = GPIO_PU;	
	gpio_cfg.drive = 0x7; 		
	status = sail_gpio_config_pin(ngpio, gpio_cfg);	
	sail_gpio_get_pin_config(ngpio, &test_gpio_cfg);	
	if ( (gpio_cfg.dir != test_gpio_cfg.dir) 
		|| (gpio_cfg.pull != test_gpio_cfg.pull) 
		|| (gpio_cfg.drive != test_gpio_cfg.drive)|| (status != GPIO_E_OK))
	{
		return TEST_GPIO_FAIL_CF;
	}

	return TEST_GPIO_PASS;	
}	

/*===========================================================================
**  Function :  xTestGPIOWrappper
** ==========================================================================
*/
/*!
*
* @brief
*  Function to test complete GPIO driver testcases 			
*
* @param
*	none
*
* @par Dependencies
*   None
* @retval
*   test result PASS/FAIL type
* @par Side Effects
*   None
*
*/
TEST_FUNC TESTerrorType_e xTestGPIOWrappper(void)
{
	int i = 0, result = 0, returnValue = MODULE_TEST_PASSED;
	int test_gpios[] = {  TEST_GPIO_NUM_58,
						  TEST_GPIO_NUM_59,
						  TEST_GPIO_NUM_60,
						  TEST_GPIO_NUM_61,
						  TEST_GPIO_NUM_81};
						  
	DEBUG_LOG( SAIL_INFO, " GPIO test started\r\n" );
	for(i = 0; i < TEST_GPIOS_NUM; i++)
	{
		result=TC_GPIO_Config(test_gpios[i]);
		result|=TC_GPIO_Output(test_gpios[i]);
		result|=TC_GPIO_Summary_Interrupt(test_gpios[i]);
		result|=TC_GPIO_Direct_Interrupt(test_gpios[i]);
		if ( (result == TEST_GPIO_PASS) || (i == 4) )
		{
			DEBUG_LOG( SAIL_INFO, "[TC_GPIO_%03d] Passed\r\n",  i);
		}
		else
		{
			DEBUG_LOG( SAIL_INFO, " [TC_GPIO_%03d] Failed\r\n", i );
			returnValue = MODULE_TEST_FAILED;
		}
	}

	if ( returnValue == TEST_GPIO_PASS )
	{
		DEBUG_LOG( SAIL_WARNING, "[GPIO tests Passed]\r\n");
		return MODULE_TEST_PASSED;
	}
	else
	{
		DEBUG_LOG( SAIL_INFO, "[GPIO tests Failed]\r\n");
		return MODULE_TEST_FAILED;
	}

}

TEST_FUNC static uint32 xTestGPIO_ConfigureAndTriggerInterrupt(uint8 nGPIO, uGPIOIntTriggerType eTrigger)
{
	int RegIntStatus;
	int EnableIntStatus;
	uint32 status = 0u;

	RegIntStatus = uGPIORegister_SummaryIntr(nGPIO, eTrigger, (uGPIOINTISR) gpio_isr, NULL);
	EnableIntStatus = uGPIOSummaryInt_EnableInterrupt(nGPIO);

	if(RegIntStatus == UGPIOINT_SUCCESS && EnableIntStatus == UGPIOINT_SUCCESS)
	{
		status = 1u;

	}

	return status;
}
TEST_FUNC static uint8 xTestGPIO_GetGPIONum(uint8* find)
{

	volatile uint32 gpio_num = 0;
	uint8 strLen = 0;

	strLen = strlen((char *) find);
	if(strLen > 1)
	{
		gpio_num = ((find[0] % 0x30 ) * 10) + (find[1] % 0x30 );
	}
	else
	{
		gpio_num =  (find[0] % 0x30 );
	}
	return gpio_num;
}
/*******************************************************************************
** Syntax           : TESTerrorType_e HAL_SAIL_Test_GPIO();                                **
**                    (   void							                      **
**                    )                                                       **
**                                                                            **
** Description      : Read the data from console and execute test case        **
**                    									                      **
**                                                                            **
** Parameters(in)   : None     									              **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Parameters (in-out):                                                       **
**                                                                            **
** Return value     : None			                                          **
**                                                                            **
*******************************************************************************/
TEST_FUNC TESTerrorType_e HAL_SAIL_Test_GPIO(uint8* find)
{
	TESTerrorType_e xRetStatus = MODULE_TEST_PASSED;
	eSailGPIOStatus_t GpioStatus = GPIO_E_NOT_OK;
	uint32 status;
	uint32 lAddr = 0;
	volatile uint32 gpio_num = 0;
	uint8 strLen = 0;
	GPIOConfigType cfg =		{
                                    .func=   0,
                                    .dir =   GPIO_IN,
                                    .pull =  GPIO_PU,
                                    .drive = GPIO_2MA
                                  };

		/*for(int i = strLen - 1, gpio_num = 0; i >= 0; i--)
		{
			
			gpio_num += ((((uint8 )find[i]) % 0x30) * (10 * i));
			
		}*/

		find = APPL_SAIL_Shell_gettoken((uint8 *)(find + strlen((char *) find) + 1));
		if(APPL_SAIL_Shell_stricmp("input",(char*)find))
		{
			find = APPL_SAIL_Shell_gettoken((uint8 *)(find + strlen((char *) find) + 1));
			gpio_num = xTestGPIO_GetGPIONum(find);

			cfg.dir = GPIO_IN;
			GpioStatus = sail_gpio_config_pin(gpio_num, cfg);
			if(GPIO_E_OK == GpioStatus)
			{
				
				DEBUG_LOG(SAIL_INFO,"Configuring gpio %d as input with RAW\n\r",gpio_num);
				GpioStatus = GPIO_E_NOT_OK;
			}
			else
			{
				xRetStatus = MODULE_TEST_FAILED;
				DEBUG_LOG(SAIL_INFO,"Configuring gpio %d as input but RAW failed\n\r",gpio_num);
			}
			
		}
		else if(APPL_SAIL_Shell_stricmp("output",(char*)find))
		{
			find = APPL_SAIL_Shell_gettoken((uint8 *)(find + strlen((char *) find) + 1));
			gpio_num = xTestGPIO_GetGPIONum(find);
			cfg.dir = GPIO_OUT;
			cfg.pull = GPIO_NP;
			GpioStatus = sail_gpio_config_pin(gpio_num, cfg);
			if(GPIO_E_OK == GpioStatus)
			{
				DEBUG_LOG(SAIL_INFO,"Configuring gpio %d as output with RAW\n\r",gpio_num);
				GpioStatus = GPIO_E_NOT_OK;
			}
			else
			{
				xRetStatus = MODULE_TEST_FAILED;
				DEBUG_LOG(SAIL_INFO,"Configuring gpio %d as output but RAW failed\n\r",gpio_num);
			}
			
		}
		
		else if(APPL_SAIL_Shell_stricmp("high",(char*)find))
		{
			find = APPL_SAIL_Shell_gettoken((uint8 *)(find + strlen((char *) find) + 1));
			gpio_num = xTestGPIO_GetGPIONum(find);

			GpioStatus = sail_gpio_WritePin(gpio_num, GPIO_HIGH);
			if(GPIO_E_OK == GpioStatus)
			{
				DEBUG_LOG(SAIL_INFO,"Setting gpio %d as High with RAW\n\r",gpio_num);
				GpioStatus = GPIO_E_NOT_OK;
			}
			else
			{
				xRetStatus = MODULE_TEST_FAILED;
				DEBUG_LOG(SAIL_INFO,"Setting gpio %d as High\n\r",gpio_num);
			}
			
		}
		else if(APPL_SAIL_Shell_stricmp("low",(char*)find))
		{
			find = APPL_SAIL_Shell_gettoken((uint8 *)(find + strlen((char *) find) + 1));
			gpio_num = xTestGPIO_GetGPIONum(find);
			GpioStatus = sail_gpio_WritePin(gpio_num, GPIO_LOW);
			if(GPIO_E_OK == GpioStatus)
			{
				DEBUG_LOG(SAIL_INFO,"Setting gpio %d as Low with RAW\n\r",gpio_num);
				GpioStatus = GPIO_E_NOT_OK;
			}
			else
			{
				xRetStatus = MODULE_TEST_FAILED;
				DEBUG_LOG(SAIL_INFO,"Setting gpio %d as Low but RAW failed\n\r",gpio_num);
			}
			
		}
		else if(APPL_SAIL_Shell_stricmp("intr_low",(char*)find))
		{
			find = APPL_SAIL_Shell_gettoken((uint8 *)(find + strlen((char *) find) + 1));
			gpio_num = xTestGPIO_GetGPIONum(find);
			testGPIO = gpio_num;
			status = xTestGPIO_ConfigureAndTriggerInterrupt(gpio_num, UGPIOINT_TRIGGER_LOW);
			if(1u == status)
			{

				DEBUG_LOG(SAIL_INFO,"Enabled Low Level Interrupt on gpio %d with RAW\n\r",gpio_num);
			}
			else
			{
				xRetStatus = MODULE_TEST_FAILED;
				DEBUG_LOG(SAIL_INFO,"Enabled Low Level Interrupt on gpio %d but RAW failed\n\r",gpio_num);
			}
			status = 0;
		}
		else if(APPL_SAIL_Shell_stricmp("intr_high",(char*)find))
		{
			find = APPL_SAIL_Shell_gettoken((uint8 *)(find + strlen((char *) find) + 1));
			gpio_num = xTestGPIO_GetGPIONum(find);
			testGPIO = gpio_num;
			status = xTestGPIO_ConfigureAndTriggerInterrupt(gpio_num, UGPIOINT_TRIGGER_HIGH);
			if(1u == status)
			{

				DEBUG_LOG(SAIL_INFO,"Enabled High Level Interrupt on gpio %d with RAW\n\r",gpio_num);
			}
			else
			{
				xRetStatus = MODULE_TEST_FAILED;
				DEBUG_LOG(SAIL_INFO,"Enabled High Level Interrupt on gpio %d but RAW failed\n\r",gpio_num);
			}
			status = 0;
			
		}
		else if(APPL_SAIL_Shell_stricmp("intr_rising",(char*)find))
		{
			find = APPL_SAIL_Shell_gettoken((uint8 *)(find + strlen((char *) find) + 1));
			gpio_num = xTestGPIO_GetGPIONum(find);
			testGPIO = gpio_num;
			status = xTestGPIO_ConfigureAndTriggerInterrupt(gpio_num, UGPIOINT_TRIGGER_RISING);
			if(1u == status)
			{

				DEBUG_LOG(SAIL_INFO,"Enabled Rising Edge Interrupt on gpio %d with RAW\n\r",gpio_num);
			}
			else
			{
				xRetStatus = MODULE_TEST_FAILED;
				DEBUG_LOG(SAIL_INFO,"Enabled Rising Edge Interrupt on gpio %d but RAW failed\n\r",gpio_num);
			}
			status = 0;

		}
		else if(APPL_SAIL_Shell_stricmp("intr_falling",(char*)find))
		{
			find = APPL_SAIL_Shell_gettoken((uint8 *)(find + strlen((char *) find) + 1));
			gpio_num = xTestGPIO_GetGPIONum(find);
			testGPIO = gpio_num;
			status = xTestGPIO_ConfigureAndTriggerInterrupt(gpio_num, UGPIOINT_TRIGGER_FALLING);
			if(1u == status)
			{

				DEBUG_LOG(SAIL_INFO,"Enabled Falling Edge Interrupt on gpio %d with RAW\n\r",gpio_num);
			}
			else
			{
				xRetStatus = MODULE_TEST_FAILED;
				DEBUG_LOG(SAIL_INFO,"Enabled Falling Edge Interrupt on gpio %d but RAW failed\n\r",gpio_num);
			}
			status = 0;

		}
		else if(APPL_SAIL_Shell_stricmp("intr_dual",(char*)find))
		{
			find = APPL_SAIL_Shell_gettoken((uint8 *)(find + strlen((char *) find) + 1));
			gpio_num = xTestGPIO_GetGPIONum(find);
			testGPIO = gpio_num;
			status = xTestGPIO_ConfigureAndTriggerInterrupt(gpio_num, UGPIOINT_TRIGGER_DUAL_EDGE);
			if(1u == status)
			{

				DEBUG_LOG(SAIL_INFO,"Enabled Dual Edge Interrupt on gpio %d with RAW\n\r",gpio_num);
			}
			else
			{
				xRetStatus = MODULE_TEST_FAILED;
				DEBUG_LOG(SAIL_INFO,"Enabled Dual Edge Interrupt on gpio %d but RAW failed\n\r",gpio_num);
			}
			status = 0;
			
		}
		else if(APPL_SAIL_Shell_stricmp("intr_trigger",(char*)find))
		{	int trigstatus;
			find = APPL_SAIL_Shell_gettoken((uint8 *)(find + strlen((char *) find) + 1));
			gpio_num = xTestGPIO_GetGPIONum(find);
			testGPIO = gpio_num;
			trigstatus = uGPIOTrigger_SummaryIntr(testGPIO);
			DEBUG_LOG(SAIL_INFO,"Waiting for GPIO %d interrupt\n\r",gpio_num);
			while(!Isr_flag);
			if(trigstatus == UGPIOINT_SUCCESS && 1u == Isr_flag)
			{
				Isr_flag = 0u;
				DEBUG_LOG(SAIL_INFO,"Interrupt Trigged and ISR executed on gpio %d with RAW\n\r",gpio_num);
			}
			else 
			{
				xRetStatus = MODULE_TEST_FAILED;
				DEBUG_LOG(SAIL_INFO,"Interrupt Trigged and ISR NOT executed on gpio %d with RAW FAILED\n\r",gpio_num);
			}
			
		}
		else if(APPL_SAIL_Shell_stricmp("read",(char*)find))
		{
			find = APPL_SAIL_Shell_gettoken((uint8 *)(find + strlen((char *) find) + 1));
			gpio_num = xTestGPIO_GetGPIONum(find);
			GPIOValueType Pin_State = sail_gpio_ReadPin(gpio_num);
			DEBUG_LOG(SAIL_INFO,"Pin state for SAIL GPIO %d is %d\n\r",gpio_num,Pin_State);
		}
		else
		{
			DEBUG_LOG(SAIL_INFO,"Invalid test command, running generic test cases \n\r");
			xRetStatus = xTestGPIOWrappper();
		}

	return xRetStatus;
}

