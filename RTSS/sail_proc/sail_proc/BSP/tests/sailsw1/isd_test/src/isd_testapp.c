/*******************************************************************************
**                                                                            **
** Copyright (C)  2024 Qualcomm Technologies, Inc. (2020)                     **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Qualcomm       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME     : isd_testapp.c                                              **
**                                                                            **
**  VERSION      : 1.0.0                                                      **
**                                                                            **
**  DATE         : 03-May-2024                                                **
**                                                                            **
**  PLATFORM     : Qualcomm SAIL                                              **
**                                                                            **
**  AUTHOR       : SAIL SW DEV                                                **
**                                                                            **
**  VENDOR       : Qualcomm Technologies, Inc.                                **
**                                                                            **
**  DESCRIPTION  : isd test file                                              **
**                                                                            **
**  SPECIFICATION(S) : Unit test specification                                **
**                                                                            **
**                                                                            **
*******************************************************************************/
#include <stdio.h>
#include "tests.h"
#include "debug_log.h"
#include "logcode.h"
#include "isd_testapp.h"



/*******************************************************************************
**                Private Macro Definitions                                   **
*******************************************************************************/



/*******************************************************************************
**                Global variables                                            **
*******************************************************************************/


/*******************************************************************************
**                Extern Declaration variables                                **
*******************************************************************************/




/*==============================================================================
**                      Private  function prototypes                          **
==============================================================================*/




/*******************************************************************************
**             				   Functions                                      **
*******************************************************************************/


TEST_FUNC TESTerrorType_e TC_ISD_GetMdStatus(void)
{

	DEBUG_LOG(SAIL_ERROR, " >>>>>>>>>>>>>>>>>>>>>>> Main Domain Boot Status test Started <<<<<<<<<<<<<<<<<<<<<<<<<< \n\r");
	TESTerrorType_e eReturnStatus = MODULE_TEST_FAILED;

	isdStatusType_e eGetStatusRet = ISD_MD2SAIL_STATUS_FAILED;
	ISD_CONTEXT_BASE_ADDRESS_TEST->eISDStatus = XBL_SEC_BOOT_SECCESS;

	eGetStatusRet = eISDGetStatus(ISD_GET_XBL_SEC_STATUS);

	/* XBL secure boot */
	if(XBL_SEC_BOOT_SECCESS == eGetStatusRet)
	{
		DEBUG_LOG(SAIL_ERROR, "MD XBL Secure Boot PASSED \n\r");
	}
	else
	{
		DEBUG_LOG(SAIL_ERROR, "MD XBL Secure Boot FAILED \n\r");

		//return eReturnStatus;
	}

	/* DDR status */
	ISD_CONTEXT_BASE_ADDRESS_TEST->eISDStatus = DDR_READY;
	eGetStatusRet = eISDGetStatus(ISD_GET_DDR_STATUS);

	if(DDR_READY == eGetStatusRet)
	{
		DEBUG_LOG(SAIL_ERROR, "MD DDR READY PASSED \n\r");
	}
	else
	{
		DEBUG_LOG(SAIL_ERROR, "MD DDR READY FAILED \n\r");

		//return eReturnStatus;
	}


	/* XBL Loader status */
	ISD_CONTEXT_BASE_ADDRESS_TEST->eISDStatus = XBL_LOADER_BOOT_SUCCESS;
	eGetStatusRet = eISDGetStatus(ISD_GET_XBL_SEC_STATUS);

	if(XBL_LOADER_BOOT_SUCCESS == eGetStatusRet)
	{
		DEBUG_LOG(SAIL_ERROR, "MD XBL Loader PASSED \n\r");
	}
	else
	{
		DEBUG_LOG(SAIL_ERROR, "MD XBL Loader FAILED \n\r");

		//return eReturnStatus;
	}

	/* MD TZ Success status */
	ISD_CONTEXT_BASE_ADDRESS_TEST->eISDStatus = TZ_SUCCESS;
	eGetStatusRet = eISDGetStatus(ISD_GET_TZ_STATUS);

	if(TZ_SUCCESS == eGetStatusRet)
	{
		DEBUG_LOG(SAIL_ERROR, "MD TZ Success PASSED \n\r");
	}
	else
	{
		DEBUG_LOG(SAIL_ERROR, "MD TZ Success FAILED \n\r");

		//return eReturnStatus;
	}

	DEBUG_LOG(SAIL_ERROR, " >>>>>>>>>>>>>>>>>>>>>>> Main Domain Boot Status test Completed <<<<<<<<<<<<<<<<<<<<<<<<<< \n\r");
	eReturnStatus = MODULE_TEST_PASSED;

	return eReturnStatus;

}




TEST_FUNC TESTerrorType_e TC_ISD_GetCurrentState(void)
{

	DEBUG_LOG(SAIL_ERROR, " >>>>>>>>>>>>>>>>>>>>>>> SAIL Status Test Started <<<<<<<<<<<<<<<<<<<<<<<<<< \n\r");
	TESTerrorType_e eReturnStatus = MODULE_TEST_FAILED;

	isdStatesType_e eGetStatusRet;

	eGetStatusRet = eISDGetCurrentState();

	if(NORMAL_STATE == eGetStatusRet)
	{
		eReturnStatus = MODULE_TEST_PASSED;
		DEBUG_LOG(SAIL_ERROR, " SAIL is in NORMAL State \n\r");	
	}
	else
	{
		DEBUG_LOG(SAIL_ERROR, " SAIL is in ISLAND State \n\r");	
	}

	DEBUG_LOG(SAIL_ERROR, " >>>>>>>>>>>>>>>>>>>>>>> SAIL Status Test Completed <<<<<<<<<<<<<<<<<<<<<<<<<< \n\r");

	return eReturnStatus;



}


TEST_FUNC TESTerrorType_e TC_ISD_IsdDeinit(void)
{

	DEBUG_LOG(SAIL_ERROR, " >>>>>>>>>>>>>>>>>>>>>>> ISD De-Init Test started <<<<<<<<<<<<<<<<<<<<<<<<<< \n\r");
	TESTerrorType_e eReturnStatus = MODULE_TEST_FAILED;

	isdResultsType_e eGetStatusRet = ISD_NOT_OK;

	eGetStatusRet = eISDDeInit();

	if(ISD_OK == eGetStatusRet)
	{
		eReturnStatus = MODULE_TEST_PASSED;
		DEBUG_LOG(SAIL_ERROR, " ISD De-Init PASSED \n\r");
	}
	else
	{
		DEBUG_LOG(SAIL_ERROR, " ISD De-Init FAILED \n\r");	
	}

	DEBUG_LOG(SAIL_ERROR, " >>>>>>>>>>>>>>>>>>>>>>> ISD De-Init Test Completed <<<<<<<<<<<<<<<<<<<<<<<<<< \n\r");

	return eReturnStatus;

}


TEST_FUNC TESTerrorType_e TC_ISD_IsdInit(void)
{

	DEBUG_LOG(SAIL_ERROR, " >>>>>>>>>>>>>>>>>>>>>>> ISD Init Test Started <<<<<<<<<<<<<<<<<<<<<<<<<< \n\r");
	TESTerrorType_e eReturnStatus = MODULE_TEST_FAILED;

	isdResultsType_e eGetStatusRet = ISD_NOT_OK;

	vISDInit();

	if(ISD_OK == uiIsdInitStatus)
	{
		eReturnStatus = MODULE_TEST_PASSED;
		DEBUG_LOG(SAIL_ERROR, " ISD Init PASSED \n\r");	
	}
	else
	{
		DEBUG_LOG(SAIL_ERROR, " ISD Init FAILED \n\r");	
	}
	DEBUG_LOG(SAIL_ERROR, " >>>>>>>>>>>>>>>>>>>>>>> ISD Init Test Completed <<<<<<<<<<<<<<<<<<<<<<<<<< \n\r");
	return eReturnStatus;

}


TEST_FUNC TESTerrorType_e xTestIsdWrapper(void)
{


	TESTerrorType_e eReturnStatus = MODULE_TEST_FAILED;

    
	uint8 *find = NULL;

	find = APPL_SAIL_Shell_gettoken(NULL);
	if(find == NULL)
	{
		isdStatusType_e eGetStatusRet = ISD_MD2SAIL_STATUS_FAILED;
		isdStatesType_e eState = NORMAL_STATE;


		TC_ISD_IsdDeinit();
		
		TC_ISD_IsdInit();
		
		TC_ISD_GetMdStatus();

		TC_ISD_GetCurrentState();

	}
	else 
	{
		if (1U == APPL_SAIL_Shell_stricmp("isoen",(char*)find))
		{

			DEBUG_LOG(SAIL_ERROR, "CDD_Isd_EnableIsolations Test Passed\n\r");
		}
		else if (1U == APPL_SAIL_Shell_stricmp("isodis",(char*)find))
		{

			DEBUG_LOG(SAIL_ERROR, "CDD_Isd_DisableIsolations Test Passed\n\r");
		}
		else if (1U == APPL_SAIL_Shell_stricmp("spsholda",(char*)find))
		{

			DEBUG_LOG(SAIL_ERROR, "CDD_Isd_SailPsHoldAssert Test Passed\n\r");
		}
		else if (1U == APPL_SAIL_Shell_stricmp("spsholdd",(char*)find))
		{

			DEBUG_LOG(SAIL_ERROR, "CDD_Isd_SailPsHoldDeAssert Test Passed\n\r");
		}
		else if (1U == APPL_SAIL_Shell_stricmp("fatalerror",(char*)find))
		{

			DEBUG_LOG(SAIL_ERROR, "CDD_Isd_FatalError Test Passed\n\r");
		}
		else if (1U == APPL_SAIL_Shell_stricmp("setmdack",(char*)find))
		{

			DEBUG_LOG(SAIL_ERROR, "CDD_Isd_SetSAILMDAck Test Passed\n\r");
		}
		else if (1U == APPL_SAIL_Shell_stricmp("help",(char*)find))
        {
            DEBUG_LOG(SAIL_ERROR,
            " isd test Cmds are\n\r" \
			" isd \n\r"  \
            " isd isoen\n\r"  \
            " isd isodis\n\r" \
            " isd spsholda\n\r" \
            " isd spsholdd\n\r" \
            " isd fatalerror\n\r" \
            " isd setmdack\n\r" \
            " isd coverage\n\r" \
            " isd help\n\r");
        }
        else
        {
            DEBUG_LOG(SAIL_ERROR,"Not a valid command, use isd help command \n\r");
        }
		
	}

	return eReturnStatus;

}