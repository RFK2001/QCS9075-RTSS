/**
 * @file uart_tests.c
 * @brief
 * uart test functions
 *
 *        Copyright (c) 2021 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*==========================================================================*/


#include <stdio.h>
#include "uart.h"
#include "busywait.h"
#include "tests.h"
#include "types.h"
#include "debug_log.h"
#include "syscall.h"
#include "syscall_pub.h"

static char const *StringMapping[4] =
{
    "LOG_INFO","LOG_WARNING","LOG_ERROR","LOG_DEBUG"
};


#if 0
#define TEST_UART_FAIL       0
#define TEST_UART_PASS		 1


TEST_DATA char test_DMA_Transfer[] = {'H','e','l','l','o',' ','U','A','R','T',' ','D','M','A',
                                                                             'H','e','l','l','o',' ','U','A','R','T',' ','D','M','A',
																			 'H','e','l','l','o',' ','U','A','R','T',' ','D','M','A',
																			 'H','e','l','l','o',' ','U','A','R','T',' ','D','M','A',
																			 'H','e','l','l','o',' ','U','A','R','T',' ','D','M','A',
																			 'H','e','l','l','o',' ','U','A','R','T',' ','D','M','A',
																			 'H','e','l','l','o',' ','U','A','R','T',' ','D','M','A',
																			 'H','e','l','l','o',' ','U','A','R','T',' ','D','M','A',
																			 'H','e','l','l','o',' ','U','A','R','T',' ','D','M','A',
																			 'H','e','l','l','o',' ','U','A','R','T',' ','D','M','A',
																			 'H','e','l','l','o',' ','U','A','R','T',' ','D','M','A',
																			 'H','e','l','l','o',' ','U','A','R','T',' ','D','M','A',
																			 'H','e','l','l','o',' ','U','A','R','T',' ','D','M','A',
																			 'H','e','l','l','o',' ','U','A','R','T',' ','D','M','A',
																			 'H','e','l','l','o',' ','U','A','R','T',' ','D','M','A',
																			 'H','e','l','l','o',' ','U','A','R','T',' ','D','M','A',
																			 'H','e','l','l','o',' ','U','A','R','T',' ','D','M','A',
																			 'H','e','l','l','o',' ','U','A','R','T',' ','D','M','A',
																			 'H','e','l'};

/*******************************************************************************
** Syntax           : TESTerrorType_e xTestUARTWrapper                                  **
**                    (                                                       **
**                    )                                                       **
**                                                                            **
** Description      : This API will test the UART driver for loopback and     **
**                    without loopback configuration.                         **
**                                                                            **
** Parameters(in)   : None                                                    **
**                                                                            **
** Parameters (out) : None                                                    **
**                                                                            **
** Parameters (in-out):                                                       **
**                                                                            **
** Return value     : Uart test result                                        **
**
**                                                                            **
*******************************************************************************/
TEST_FUNC TESTerrorType_e xTestUARTWrapper()
{
  char test_transfer_data[] = {'H','e','l','l','o',' ','U','A','R','T'};
  char test_receive_data[100];
  uint8 lCompareCount =0;
  int32 lStatus = MODULE_TEST_PASSED;
  uint32 ulret = 0U;
#if 0
  if(   (xUartCoreConfig.ChCfgPtr->ucLoopback_mode == 0) 
	 && (xUartCoreConfig.ChCfgPtr->eUartOpMode == UART_FIFO_MODE))
  {
    /* Debug Log - Print*/
	ulret = ulUartWrite(UART_DEBUG_PORT, "[UART] SAIL_INFO Print Test \n\r",30); 
	if (ulret == 30)
	{
		ulUartWrite(UART_DEBUG_PORT, "All data transmitted \n\r",23);
	}
	else
	{
		ulUartWrite(UART_DEBUG_PORT, "All data not transmitted \n\r",27);
	}
	ulret = ulUartRead(UART_DEBUG_PORT, &test_receive_data[0], sizeof("[UART] SAIL_ERROR Print"));
	if (ulret == 23)
	{
		ulUartWrite(UART_DEBUG_PORT, "All data received \n\r",20);
	}
	else
	{
		ulUartWrite(UART_DEBUG_PORT, "All data not received \n\r",24);
	}
	ulret = ulUartWrite(UART_DEBUG_PORT, "[UART] SAIL_ERROR Print Test\n\r",30);
	if (ulret == 30)
	{
		ulUartWrite(UART_DEBUG_PORT, "All data transmitted \n\r",23);
	}
	else
	{
		ulUartWrite(UART_DEBUG_PORT, "All data not transmitted \n\r",27);
	}
	ulret = ulUartWrite(UART_DEBUG_PORT, "[UART] SAIL_WARNING Print Test\n\r",32);
	if (ulret == 32)
	{
		ulUartWrite(UART_DEBUG_PORT, "All data transmitted \n\r",23);
	}
	else
	{
		ulUartWrite(UART_DEBUG_PORT, "All data not transmitted \n\r",27);
	}
	ulret = ulUartWrite(UART_DEBUG_PORT, "[UART] SAIL_DEBUG Print Test\n\r",30);
	if (ulret == 30)
	{
		ulUartWrite(UART_DEBUG_PORT, "All data transmitted \n\r",23);
	}
	else
	{
		ulUartWrite(UART_DEBUG_PORT, "All data not transmitted \n\r",27);
	}
	ulret = ulUartWrite(UART_DEBUG_PORT, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890!@#$%%^&*()_+ -> PRINTING_SUCCESS\n\rABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890!@#$%%^&*()_+ -> PRINTING_SUCCESS\n\rABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%%^&*()_+ ->\n\r",264);
	if (ulret == 264)
	{
		ulUartWrite(UART_DEBUG_PORT, "All data transmitted \n\r",23);
	}
	else
	{
		ulUartWrite(UART_DEBUG_PORT, "All data not transmitted \n\r",27);
	}
	ulret = ulUartWrite(UART_DEBUG_PORT, "Transmitting more than 300 bytes 123455ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890!@#$%%^&*()_+ -> PRINTING_SUCCESS\n\rABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890!@#$%%^&*()_+ -> PRINTING_SUCCESS\n\rABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%%^&*()_+ ->\n\r",264);
	if (ulret == 303)
	{
		ulUartWrite(UART_DEBUG_PORT, "All data transmitted \n\r",23);
	}
	else
	{
		ulUartWrite(UART_DEBUG_PORT, "All data not transmitted \n\r",27);
	}
		
  }
  else if(   (xUartCoreConfig.ChCfgPtr->ucLoopback_mode == 0) 
	 && (xUartCoreConfig.ChCfgPtr->eUartOpMode == UART_DMA_MODE))
	 {
		ulret = ulUartWrite(UART_DEBUG_PORT, &test_DMA_Transfer[0],255);
		ulret = ulUartWrite(UART_DEBUG_PORT, &test_DMA_Transfer[0],25);
		while(1);
	 }
  else
  {
	//receive data from Receive API to receive data.
	ulUartWrite(UART_DEBUG_PORT, &test_transfer_data[0], sizeof(test_transfer_data));
	//receive data from Receive API to receive data.
	ulUartRead(UART_DEBUG_PORT, &test_receive_data[0], sizeof(test_transfer_data));
	//Compare data sent with receive data
	for (lCompareCount=0; lCompareCount<sizeof(test_transfer_data); lCompareCount++)
	{
		if (test_transfer_data[lCompareCount]!=test_receive_data[lCompareCount])
			break;
	}	

	//If both are equal then Test is Success.
	if( lCompareCount == sizeof(test_transfer_data))
	{
		lStatus = MODULE_TEST_PASSED;
		ulUartWrite(UART_DEBUG_PORT, "\n\rSAIL UART Loopback test is success\r\n",38);
	}
	else
	{
		lStatus = MODULE_TEST_FAILED;
		ulUartWrite(UART_DEBUG_PORT, "\n\rSAIL UART Loopback test is fail\r\n",35);
	}
  }
#endif
  return lStatus;
}	
#endif


TESTerrorType_e UARTLoglevel_EL2_WrapInterface(LogLevel_e Request_loglevel)
{
	TESTerrorType_e status = MODULE_TEST_FAILED;
	LogLevel_e CurrLogLevel;
	uint8 ucIndex = 0;
		DEBUG_LOG(SAIL_WARNING, ">>>>> SETTING LOG LEVEL FOR EL2 <<<<<<\n\r",StringMapping[ucIndex]);
	if( Request_loglevel ==  LOG_INFO)
	{
		ucIndex = 0;
	}else if( Request_loglevel ==  LOG_WARNING)
	{
		ucIndex = 1;
	}else if( Request_loglevel ==  LOG_ERROR) 
	{
		ucIndex = 2;
	}else{
		ucIndex = 3;
	}

	vLogSetLevel(Request_loglevel);
	CurrLogLevel = vLogGetLevel();
	if ( CurrLogLevel == Request_loglevel ){
		status = MODULE_TEST_PASSED;
		DEBUG_LOG(Request_loglevel, ">>>>> EL2 Loglevel set to %s <<<<<\n\r",StringMapping[ucIndex]);
	}
	else 
		DEBUG_LOG(SAIL_ERROR, ">>>>> EL2 Loglevel set to %s fail<<<<<\n\r",StringMapping[ucIndex]);
	return status;
}
/*


        <<<<<<<<<<<< UartLogLevelEL2SysCallWrapper >>>>>>>>>>>>>>>
        Sys Call to call UART log level EL2 wrapper function

*/

uint32 UartLoglevelEl2TestTrapInterface( uint32 verbosity_lvl, sailbsp_hvc_rsp_t *rsp)
{
    rsp->data[0] = (uint32_t)UARTLoglevel_EL2_WrapInterface((LogLevel_e)verbosity_lvl);
    return HVC_SUCCESS;
}

/* SYS CALL DECLARATIONS */

SAIL_DEFINE_SYSCALL(  SAIL_LOGLEVEL_FUNC_TEST_TRAP,
                      SAIL_LOGLEVEL_FUNC_TEST_TRAP_PARAM_ID,
                      0,
                      UartLoglevelEl2TestTrapInterface
                    );

/************** SAIL UART TEST ************/
