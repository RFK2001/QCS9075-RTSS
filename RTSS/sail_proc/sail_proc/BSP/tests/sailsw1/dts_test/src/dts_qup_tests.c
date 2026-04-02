/**************************************************************************************************
    Copyright (c) 2021,2023 Qualcomm Technologies, Inc.
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
**************************************************************************************************/
/*=================================================================================================
    File Name          : dts_qup_tests.c
    Component Name     : scripts/.dts
    Description        : read dts file and configure qup driver
    $Header:  $
    $DateTime:  $
    $Author: txavier $
=================================================================================================*/

/*************************************************************************************************
**                     		 Includes                                                           **
**************************************************************************************************/
#include "debug_log.h"
#include "tests.h"
#include "qup_common_hwio.h"
#include <libfdt.h>
#include "fdt_utils.h"
#include "HALhwio.h"
#include "hw_io.h"
#include "common_functions.h"
#include "uart.h"

/*=================================================================================================
 *                                  PRIVATE Macros
 *================================================================================================*/
TEST_FUNC static void prvDTSQUPTestDebugPrint ( TESTerrorType_e result, const char * TestMsg, uint16_t usTestCaseNum );
#define TOTAL_FUNC_TEST_CASES 0x5
#define SPIM_SERIALPROTOCOL             0x1U
#define I2C_FWPROTOCOL                  0x3U
TEST_DATA uint8 currentCoreNun = 0;
#define VIP_UART_BAUDRATE 921600

extern uint32 getUartClkRegValue(uint32 baudrate);
/*************************************************************************************************
**                				Function Definitions                                            **
*************************************************************************************************/
/*>>>>>>>>>>>>>>> [TC_DTS_001] ER09838: Test Firmware loading from DTS for SPI protocol <<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_DTS_001( void )
{
	TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
	uint32 protocol = 0x0;
	int32_t offset = 0, root_offset = 0;
	const char *path;
	int32_t valSize_st = 5;
	uint32 ulspi_base = 0x0;
	char prot_name[6] = {'s', 'p', 'i', '0','\0'};
	void *pDTB = NULL;

	pDTB = fdt_get_dtb();
	if (NULL != pDTB)
	{
		root_offset = fdt_path_offset(pDTB, "/qup");
		root_offset = fdt_path_offset(pDTB, "/aliases");
		path = (const char*)fdt_getprop(pDTB, root_offset, prot_name , NULL);
		if (path != NULL) {
			offset = fdt_path_offset(pDTB, path);
			(void)fdt_getprop_u32(pDTB, offset, "reg-base", &ulspi_base);
		}
		protocol = REG_INF(ulspi_base, GENI_S_FW_REVISION, PROTOCOL);
		if(protocol == SPIM_SERIALPROTOCOL)
		{
			 xRetStatus = MODULE_TEST_PASSED;
		}
	}

	prvDTSQUPTestDebugPrint(xRetStatus, "Test - Firmware loading from DTS for SPI protocol", 1);

	return xRetStatus;
}

/*>>>>>>>>>>>>>>> [TC_DTS_002] ER09838: Test - UART0 baudrate configuration from DTS  <<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_DTS_002( void )
{
	TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
	int32_t offset = 0, root_offset = 0;
	const char *path;
	uint32 uluart_base = 0x0, baudrate = 0x0;
	char uart_name[6] = {'u', 'a', 'r', 't','0','\0'};
	void *pDTB = NULL;
	uint32 usclkRegValue = 0x0;
	uint32 configclkRegValue = 0x0;

	pDTB = fdt_get_dtb();
	if (NULL != pDTB)
	{
		root_offset = fdt_path_offset(pDTB, "/qup");
		root_offset = fdt_path_offset(pDTB, "/aliases");
		path = (const char*)fdt_getprop(pDTB, root_offset, uart_name , NULL);
		if (path != NULL) {
			offset = fdt_path_offset(pDTB, path);
			(void)fdt_getprop_u32(pDTB, offset, "reg-base", &uluart_base);
			(void)fdt_getprop_u32(pDTB, offset, "baudrate", &baudrate);
		}
	}

    usclkRegValue = getUartClkRegValue(baudrate);
    configclkRegValue = REG_IN(uluart_base, GENI_SER_M_CLK_CFG);
    if(configclkRegValue == usclkRegValue)
    {
    	 xRetStatus = MODULE_TEST_PASSED;
    }

	prvDTSQUPTestDebugPrint(xRetStatus, "Test - UART0 baudrate configuration from DTS", 2);

    return xRetStatus;
}

/*>>>>>>>>>>>>>>> [TC_DTS_003] ER09838: Test I2C mode selection from DTS <<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_DTS_003( void )
{
	TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
	uint32 clk_div = 0, set_clkdiv = 0x1;
	uint32 se0_i2c_base = 0xF1900000;


    clk_div = REG_INF(se0_i2c_base, GENI_SER_M_CLK_CFG, CLK_DIV_VALUE);
    if(set_clkdiv == clk_div)
    {
      	 xRetStatus = MODULE_TEST_PASSED;
    }

	prvDTSQUPTestDebugPrint(xRetStatus, "Test - I2C mode selection from DTS", 3);

	return xRetStatus;
}

/*>>>>>>>>>>>>>>> [TC_DTS_004] ER09838: Test UART1 Parity configuration from DTS  <<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_DTS_004( void )
{
	TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
	int32_t offset = 0, root_offset = 0;
	const char *path;
	uint32 uluart_base = 0x0, parity = 0x0, set_parity = 0x0;
	char uart_name[6] = {'u', 'a', 'r', 't','1','\0'};
	void *pDTB = NULL;

	pDTB = fdt_get_dtb();
	if (NULL != pDTB)
	{
		root_offset = fdt_path_offset(pDTB, "/qup");
		root_offset = fdt_path_offset(pDTB, "/aliases");
		path = (const char*)fdt_getprop(pDTB, root_offset, uart_name , NULL);
		if (path != NULL) {
			offset = fdt_path_offset(pDTB, path);
			(void)fdt_getprop_u32(pDTB, offset, "reg-base", &uluart_base);
			(void)fdt_getprop_u32(pDTB, offset, "parity", &parity);
		}
	}
	if( parity == UART_NO_PARITY)
	{
		parity = UART_EVEN_PARITY;
	}
	set_parity = REG_INF(uluart_base, UART_TX_PARITY_CFG, TX_PAR_MODE);
	if(set_parity == parity)
	{
		xRetStatus = MODULE_TEST_PASSED;
	}

	prvDTSQUPTestDebugPrint(xRetStatus, "Test - UART1 Parity configuration from DTS ", 4);

    return xRetStatus;
}

/*>>>>>>>>>>>>>>> [TC_DTS_005] FR91273: Test - Firmware loading from DTS for I2C1 protocol  <<<<<<<<<<<<<<<*/
TESTerrorType_e TC_DTS_005( void )
{
	TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
	uint32 protocol = 0x0;
	int32_t offset = 0, root_offset = 0;
	const char *path;
	int32_t valSize_st = 5;
	uint32 uli2c_base = 0x0;
	char prot_name[6] = {'i', '2', 'c', '1','\0'};
	void *pDTB = NULL;

	pDTB = fdt_get_dtb();
	if (NULL != pDTB)
	{
		root_offset = fdt_path_offset(pDTB, "/qup");
		root_offset = fdt_path_offset(pDTB, "/aliases");
		path = (const char*)fdt_getprop(pDTB, root_offset, prot_name , NULL);
		if (path != NULL) {
			offset = fdt_path_offset(pDTB, path);
			(void)fdt_getprop_u32(pDTB, offset, "reg-base", &uli2c_base);
		}
		protocol = REG_INF(uli2c_base, GENI_S_FW_REVISION, PROTOCOL);
		if(protocol == I2C_FWPROTOCOL)
		{
			 xRetStatus = MODULE_TEST_PASSED;
		}
	}

	prvDTSQUPTestDebugPrint(xRetStatus, "Test - Firmware loading from DTS for I2C1 protocol", 5);

	return xRetStatus;
}

TEST_FUNC static void prvDTSQUPTestDebugPrint ( TESTerrorType_e result, const char * TestMsg, uint16_t usTestCaseNum )
{
    if( MODULE_TEST_PASSED == result )
    {
        DEBUG_LOG( SAIL_INFO,"[TC_DTS_%03d] Passed: %s\r\n", usTestCaseNum, TestMsg );
    }
    else
    {
        DEBUG_LOG( SAIL_INFO,"[TC_DTS_%03d] Failed: %s\r\n", usTestCaseNum, TestMsg);
    }
}

TEST_FUNC TESTerrorType_e xTestDTS_QUP_Wrapper(void)
{
	TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
	uint8 ucTestCaseCnt = TOTAL_FUNC_TEST_CASES;

	currentCoreNun = get_curr_phys_cpu_num();

	if (1 == currentCoreNun)
   {
		if ( MODULE_TEST_FAILED == TC_DTS_001() )
		{
			ucTestCaseCnt--;
		}
   }
	if (2 == currentCoreNun)
   {
		if ( MODULE_TEST_FAILED == TC_DTS_002() )
		{
			ucTestCaseCnt--;
		}
   }
	if (1 == currentCoreNun)
   {
		if ( MODULE_TEST_FAILED == TC_DTS_003() )
		{
			ucTestCaseCnt--;
		}
   }
	if (2 == currentCoreNun)
   {
		if ( MODULE_TEST_FAILED == TC_DTS_004() )
		{
			ucTestCaseCnt--;
		}
   }
   if (0 == currentCoreNun)
   {
		if ( MODULE_TEST_FAILED == TC_DTS_005() )
		{
			ucTestCaseCnt--;
		}
   }
	if( TOTAL_FUNC_TEST_CASES == ucTestCaseCnt )
	{
	    DEBUG_LOG( SAIL_INFO, "[DTS tests Passed]\r\n" );
	    xRetStatus =  MODULE_TEST_PASSED;
	}
	else
	{
	    DEBUG_LOG( SAIL_INFO, "[DTS tests Failed]\r\n" );
	    xRetStatus =  MODULE_TEST_FAILED;
	}

    return xRetStatus;
}
