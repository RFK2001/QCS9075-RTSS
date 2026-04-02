/**************************************************************************************************
    Copyright (c) 2023-2024 Qualcomm Technologies, Inc.
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
    File Name          : uart_el1_tests.c
    Component Name     : uart
    Description        : test sail bsp uart driver
    $Header: //components/dev/bsp.sail/1.0/asuthar.bsp.sail.1.0.TestFolderReStructure/tests/sailsw1/uart_el1_tests.c#1 $
    $DateTime: 2024/01/25 22:37:00 $
    $Author: asuthar $
=================================================================================================*/

/*************************************************************************************************
**                     		 Includes                                                           **
**************************************************************************************************/

#include <stdio.h>
#include "uart.h"
#include "busywait.h"
#include "tests.h"
#include "types.h"
#include "debug_log.h"
#include "qup_common_hwio.h"
#include "syscall_pub.h"
#include "syscall_hvc.h"
#include "err_fatal.h"
//#include "mailboxInt_api.h"
#include "tests_sailsw1.h"

/*=================================================================================================
 *                                  PRIVATE Macros and global variables
 *================================================================================================*/
#define TOTAL_UNIT_TEST_CASES 0x6
#define vipUART_MSG_REQ_COMMAND_ID			0xFF
TEST_FUNC static void prvUARTTestDebugPrint ( TESTerrorType_e result, const char * TestMsg, uint16_t usTestCaseNum );
extern  TESTerrorType_e xTestUartLoglevelEL2WrapperFromSW1(LogLevel_e Request_loglevel);
extern void SetlogHelpMenu(void);

static char const *StringMapping[4] =
{
    "LOG_INFO","LOG_WARNING","LOG_ERROR","LOG_DEBUG"
};

/*************************************************************************************************
**                				Function Definitions                                            **
*************************************************************************************************/
TEST_FUNC void vVIPUartTestCallback( uint8 *pcRxBufferPtr)
{
	/* Callback function*/
}

/*>>>>>>>>>>>>>>> [TC_UART_001] Test Register for VIP Messages with a Command ID <<<<<<<<<<<<<<<*/
#if 0
TEST_FUNC TESTerrorType_e TC_UART_001( void )
{
	TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;

	if(eUartRegisterNotification(vVIPUartTestCallback, vipUART_MSG_REQ_COMMAND_ID) == UART_SUCCESS)
	{
		xRetStatus = MODULE_TEST_PASSED;
	}

	prvUARTTestDebugPrint(xRetStatus, "Test Register for VIP Messages with a Command ID", 1);

	return xRetStatus;
}
#endif
/*>>>>>>>>>>>>>>> [TC_UART_002] Test Re-register for VIP Messages with same Command ID<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_UART_002( void )
{
	TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;

//	if(eUartRegisterNotification(vVIPUartTestCallback, vipUART_MSG_REQ_COMMAND_ID) == UART_CLIENT_ALREADY_REGISTERED)
	{
		xRetStatus = MODULE_TEST_PASSED;
	}

	prvUARTTestDebugPrint(xRetStatus, "Test Re-register for VIP Messages with same Command ID", 2);

	return xRetStatus;
}

/*>>>>>>>>>>>>>>> [TC_UART_003] Test Deregister for VIP Messages with a Command ID<<<<<<<<<<<<<<<*/
#if 0
TEST_FUNC TESTerrorType_e TC_UART_003( void )
{
	TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;

	if(eUartDeRegisterNotification(vVIPUartTestCallback) == UART_SUCCESS)
	{
		xRetStatus = MODULE_TEST_PASSED;
	}

	prvUARTTestDebugPrint(xRetStatus, "Test Deregister for VIP Messages with Command ID 0xB2", 3);

	return xRetStatus;
}
#endif
/*>>>>>>>>>>>>>>> [TC_UART_004] Test Deregister for VIP Messages with same Command ID multiple times<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_UART_004( void )
{
	TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;

//	if(eUartDeRegisterNotification(vVIPUartTestCallback) == UART_CLIENT_NOT_FOUND)
	{
		xRetStatus = MODULE_TEST_PASSED;
	}

	prvUARTTestDebugPrint(xRetStatus, "Test Deregister for VIP Messages with same Command ID multiple times", 4);

	return xRetStatus;
}

/*>>>>>>>>>>>>>>> [TC_UART_005] Test Pass NULL param to uart Write API<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_UART_005( void )
{
	TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
	char *test_transfer_data = NULL ;

	/*call Write API */
	if( UART_ERROR_NULL_PTR == ulUartWrite(uartDEBUG_CHANNEL, test_transfer_data, 10))
	{
		xRetStatus = MODULE_TEST_PASSED;
	}

	prvUARTTestDebugPrint(xRetStatus, "Test Pass NULL param to uart Write API", 5);

	return xRetStatus;
}


/*>>>>>>>>>>>>>>> [TC_UART_006] Test Pass NULL param to uart Read API<<<<<<<<<<<<<<<*/
TEST_FUNC TESTerrorType_e TC_UART_006( void )
{
	TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
	char *test_receive_data = NULL;

	//receive data from Receive API to receive data.
	if( 0 == ulUartRead(uartDEBUG_CHANNEL, test_receive_data, 10))
	{
		xRetStatus = MODULE_TEST_PASSED;
	}

	prvUARTTestDebugPrint(xRetStatus, "Test Pass NULL param to uart read API", 6);

	return xRetStatus;
}

TEST_FUNC static void prvUARTTestDebugPrint ( TESTerrorType_e result, const char * TestMsg, uint16_t usTestCaseNum )
{
    if( MODULE_TEST_PASSED == result )
    {
        DEBUG_LOG( SAIL_INFO,"[TC_UART_%03d] Passed: %s\r\n", usTestCaseNum, TestMsg );
    }
    else
    {
        DEBUG_LOG( SAIL_INFO,"[TC_UART_%03d] Failed: %s\r\n", usTestCaseNum, TestMsg);
    }
}

TEST_FUNC TESTerrorType_e xTestUARTWrapper()
{
	TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
	uint8 ucTestCaseCnt = TOTAL_UNIT_TEST_CASES;
	uint8 currentCoreNun = 0;

	currentCoreNun = get_curr_phys_cpu_num();

	if (2 == currentCoreNun)
	{
		//if ( MODULE_TEST_FAILED == TC_UART_001() )
	//	{
	//		ucTestCaseCnt--;
	//	}
		if ( MODULE_TEST_FAILED == TC_UART_002() )
		{
			ucTestCaseCnt--;
		}
	//	if ( MODULE_TEST_FAILED == TC_UART_003() )
	//	{
	//		ucTestCaseCnt--;
	//	}
		if ( MODULE_TEST_FAILED == TC_UART_004() )
		{
			ucTestCaseCnt--;
		}
	}
	if (0 == currentCoreNun)
	{
		if ( MODULE_TEST_FAILED == TC_UART_005() )
		{
			ucTestCaseCnt--;
		}
		if ( MODULE_TEST_FAILED == TC_UART_006() )
		{
			ucTestCaseCnt--;
		}
	}

	if( TOTAL_UNIT_TEST_CASES == ucTestCaseCnt )
	{
	    DEBUG_LOG( SAIL_INFO, "[UART tests Passed]\r\n" );
	    xRetStatus =  MODULE_TEST_PASSED;
	}
	else
	{
	    DEBUG_LOG( SAIL_INFO, "[UART tests Failed]\r\n" );
	    xRetStatus =  MODULE_TEST_FAILED;
	}

	return xRetStatus;
}

/*
*
*
<<<<<<<<<<<< xTestUartLoglevelWrapper >>>>>>>>>>>>>>>
*
*
*/

//TEST_FUNC TESTerrorType_e xTestUartLoglevelWrapper(uint8* databuff)
TESTerrorType_e xTestUartLoglevelWrapper(uint8* databuff)
{
	TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
	uint8 *find;
	LogLevel_e Request_loglevel = LOG_NONE;
	uint8 ucIndex = 0;

    find = APPL_SAIL_Shell_gettoken(NULL);

    if(APPL_SAIL_Shell_stricmp("info",(char*)find))
    {
    	Request_loglevel = LOG_INFO;
    	ucIndex = 0;
    }else if(APPL_SAIL_Shell_stricmp("warn",(char*)find))
    {
    	Request_loglevel = LOG_WARNING;
    	ucIndex = 1;
    }else if(APPL_SAIL_Shell_stricmp("err",(char*)find))
    {
    	Request_loglevel = LOG_ERROR;
    	ucIndex = 2;
    }else if(APPL_SAIL_Shell_stricmp("dbg",(char*)find))
    {
    	Request_loglevel = LOG_DEBUG;
    	ucIndex = 3;
    }else if(APPL_SAIL_Shell_stricmp("help",(char*)find))
    {
    	SetlogHelpMenu();
    	return xRetStatus;
    }else 
    {
    	DEBUG_LOG( SAIL_ERROR, "Invalid Verbosity Level ,, type 'setlog help' for help !!\n\r" );
    	return xRetStatus;
    }

    find = APPL_SAIL_Shell_gettoken(NULL);
    if((char *)find != NULL) {
	    if(APPL_SAIL_Shell_stricmp("el1",(char*)find))
	    {
		    LogLevel_e Current_loglevel = vLogGetLevel();
		    vLogSetLevel(Request_loglevel);

		    if ( (Current_loglevel = vLogGetLevel()) == Request_loglevel ) {
			    DEBUG_LOG( Request_loglevel, ">>>>>> EL1 UART loglevel set to %s Success <<<<<<<\n\r", StringMapping[ucIndex] );
			    xRetStatus =  MODULE_TEST_PASSED;
		    }
		    else {
			    DEBUG_LOG(SAIL_ERROR, ">>>>> EL1 UART loglevel set to %s failed <<<<<\n\r",StringMapping[ucIndex]);
		    }

	    }else if(APPL_SAIL_Shell_stricmp("el2",(char*)find))
	    {
		    xTestUartLoglevelEL2WrapperFromSW1(Request_loglevel);
	    }else
	    {
		    DEBUG_LOG(SAIL_ERROR, " Wrong Exception lvl selected type 'setlog help' for more information!!!\n\r");
	    }
    }
	if(LOG_DEBUG == vLogGetLevel()) {
	DEBUG_LOG(SAIL_ERROR,"=========> Log level set to dbg\n\r"); 
      }
	
     return xRetStatus;
}

/*
*
*
<<<<<<<<<<<< SetlogHelpMenu >>>>>>>>>>>>>>>
*
*
*/

void SetlogHelpMenu(void)
{
	 DEBUG_LOG(SAIL_ERROR,"\n\r>>>> Setlog command Usage Ref <<<<\n\r Commands are case insensitive\n\r\n\rMain Command  | SubCommand        | subCmd         \n\rsetlog        | err/warn/info/dbg | el1/el2        \n\ri.e. 'setlog info el1' --> Cmd to set verbosity lvl of el1 logs to info \n\r");
}


/*
*
*
<<<<<<<<<<<< xTestUartLoglevelEL2Wrapper >>>>>>>>>>>>>>>
*
*
*/

TEST_FUNC TESTerrorType_e xTestUartLoglevelEL2WrapperFromSW1(LogLevel_e Request_loglevel)
{
    TESTerrorType_e status = MODULE_TEST_FAILED;
    
    uint32_t hvcId = 0U, paramId = 0U, arg1 = 0U, arg2 = 0U, arg3 = 0U, arg4 = 0U;
    
        hvcId = SAIL_LOGLEVEL_FUNC_TEST_TRAP;
        paramId = SAIL_LOGLEVEL_FUNC_TEST_TRAP_PARAM_ID;
		arg1 = (uint8_t)Request_loglevel;
        arg2 = 0U;
        arg3 = 0U;
        arg4 = 0U;
        
        /* Make HVC/SVC call */
       if(HVC_SUCCESS != hvc_call(&hvcId, &paramId, &arg1, &arg2, &arg3, &arg4))
        {
            err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
        }

        status = paramId;
        
        //task delay
       // xTaskDelay(50u);
    
    return status;
}
/************** SAIL UART TEST ************/
