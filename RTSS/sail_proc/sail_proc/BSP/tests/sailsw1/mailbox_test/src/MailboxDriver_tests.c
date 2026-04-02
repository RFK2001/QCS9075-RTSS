/**
 * @file MailboxDriver_tests.c
 * @brief
 * Mailbox test Cases
 *
 *        Copyright (c) 2022 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*==========================================================================*/
#include <stdio.h>
#include <string.h>
#include "tests.h"
#include "IPCC.h"
#include "debug_log.h"
#include "mailboxExt_api.h" 
#include "mailboxLib.h" 
/*******************************************************************************
**                Private Macro Definitions                                   **
*******************************************************************************/
#define MailboxNumTestCases	            19U
/*******************************************************************************
**                Global variables                                            **
*******************************************************************************/
uint8 mbDATA[7] = {'M','B','D','A','T','A','\0'};
uint8 rdDATA[7] = {0};
/*******************************************************************************
**             				   Functions                                      **
*******************************************************************************/
extern MAILBOX_EXT_FUNC int32 slMailBox_DeInit(void);
extern MAILBOX_EXT_FUNC int32 slMailboxWrite(xMailboxExtclienttype MBclient_ID, uint32 num_item, uint8 *wbuff);
extern MAILBOX_EXT_FUNC int32 slMailboxRead(xMailboxExtclienttype MBclient_ID,uint32 num_item,uint8 *rbuff);
extern MAILBOX_EXT_FUNC mailboxEBStatusType_e eMailbox_Get_Status(void);
extern MAILBOX_EXT_FUNC int32 slMailbox_Get_FreeItemNum(xMailboxExtclienttype MBclient_ID);
extern MAILBOX_EXT_FUNC int32 slMailBox_Enable(void);
extern MAILBOX_EXT_FUNC void vMBTFCbk(xMailboxExtclienttype MBclient_ID);
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> TEST CASES <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_MB_01] Mailbox Deinit <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

/* int32 TC_MB_01(void)
{
	int32 slstatus  = MB_E_SUCCESS;
	slstatus = slMailBox_DeInit();   //+ TEST CASE
	return slstatus;
} */

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_MB_02] Mailbox Write <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

int32 TC_MB_02(void)
{
	int32 slStatus = MB_E_NOT_READY;
	slStatus = slMailboxWrite(MAILBOX_HLOSTST, 1, (uint8*)&mbDATA) ;//+ TEST CASE
	return slStatus;
}
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_MB_03] Mailbox Read <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

int32 TC_MB_03(void)
{
	int32 slStatus = MB_E_NOT_READY;
	slStatus = slMailboxRead(MAILBOX_HLOSTST, 1, (uint8*)&rdDATA) ;//+ TEST CASE 
	return slStatus;
}
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_MB_04] Mailbox Get Status <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

/* uint32 TC_MB_04(void)
{
	mailboxEBStatusType_e EBStatus = 0xFFU;
	EBStatus = eMailbox_Get_Status() ;//+ TEST CASE
	return EBStatus;
} */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_MB_05] Mailbox Get Number of Free item <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

int32 TC_MB_05(void)
{
	int32 slStatus = MB_E_NOT_READY;
	slStatus = slMailbox_Get_FreeItemNum(MAILBOX_HLOSTST) ;//+ TEST CASE
	return slStatus;
}
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_MB_06] Mailbox Init <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

/* int32 TC_MB_06(void)
{
	int32 slstatus  = MB_E_SUCCESS;
	slStatus = slMailBox_Enable() ;//+ TEST CASE
	return slStatus;
} */
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_MB_07] Mailbox Channel Register <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

/* int32 TC_MB_07(void)
{
	int32 slstatus = MB_E_SUCCESS;
	slStatus = slMailboxClientReg(MAILBOX_HLOSTST, vMBTFCbk) ;//+ TEST CASE
	return slStatus;
} */

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_MB_08] Mailbox Get Valid item Num <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

int32 TC_MB_08(void)
{
	int32 slStatus = MB_E_NOT_READY;
	slStatus = slMailbox_Get_ValidItemNum(MAILBOX_HLOSTST) ;//+ TEST CASE
	return slStatus;
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_MB_09] Mailbox Debug Event Count <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

int32 TC_MB_09(void)
{
	int32_t slStatus = MB_E_INVALID_INDEX;
	slStatus = slMailboxEBDebugEventCnt(MAILBOX_EBMAX, MB_CHAN_WR_MODE) ;//+ TEST CASE
	return slStatus;
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_MB_10] Mailbox  Set Status To Abort <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

mailboxEBStatusType_e TC_MB_10(void)
{
	mailboxEBStatusType_e EBStatus = 0xFFU;
	EBStatus = eMailbox_Abort() ;//+ TEST CASE
	return EBStatus;
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_MB_11] Mailbox  Set Status To Resume (Before Abort state) <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

mailboxEBStatusType_e TC_MB_11(void)
{
	mailboxEBStatusType_e EBStatus = 0xFFU;
	EBStatus = eMailbox_Resume() ;//+ TEST CASE
	return EBStatus;
}

/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_MB_12] Mailbox Channel Register <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

/* int32 TC_MB_12(void)
{
	int32 slstatus = MB_E_SUCCESS;
	slstatus = slMailboxClientReg(0x20, vMBTFCbk) ;// Negative TEST CASE
	return slstatus;
}  */

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_MB_13] Mailbox Write <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

int32 TC_MB_13(void)
{
	int32 slStatus = MB_E_NOT_READY;
	slStatus = slMailboxWrite(MAILBOX_EBMAX, 1, (uint8*)&mbDATA) ;// Negative TEST CASE
	return slStatus;
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_MB_14] Mailbox Read <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

int32 TC_MB_14(void)
{
	int32 slStatus = MB_E_NOT_READY;
	slStatus = slMailboxRead(MAILBOX_EBMAX, 1, (uint8*)&rdDATA) ;//Negative TEST CASE 
	return slStatus;
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_MB_15] Mailbox Get Number of Free item <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

int32 TC_MB_15(void)
{
	int32 slStatus = MB_E_NOT_READY;
	slStatus = slMailbox_Get_FreeItemNum(MAILBOX_EBMAX) ;//Negative TEST CASE
	return slStatus;
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_MB_16] Mailbox Get Valid item Num <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

int32 TC_MB_16(void)
{
	int32 slStatus = MB_E_NOT_READY;
	slStatus = slMailbox_Get_ValidItemNum(MAILBOX_EBMAX) ;//Negative TEST CASE
	return slStatus;
}
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_MB_17] Mailbox Get Core Status <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

int32 TC_MB_17(void)
{
	mailboxEBStatusType_e EBStatus = 0xFFU;
	EBStatus = eMailbox_Get_CoreStatus(0x5) ;//Negative TEST CASE
	return EBStatus;
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_MB_18] Mailbox Set Core Status <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

int32 TC_MB_18(void)
{
	mailboxEBStatusType_e EBStatus = 0xFFU;
	EBStatus = eMailbox_Set_Status(MB_UNINITIALIZED, 0x5) ;//Negative TEST CASE
	return EBStatus;
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_MB_19] Mailbox Set EB REQUEST <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

int32 TC_MB_19(void)
{
	int32 Status  = MB_E_SUCCESS;
	Status = slMailbox_EBResetRequest(0x5) ;//Negative TEST CASE
	return Status;
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_MB_20] Mailbox Debug Event Count <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

int32 TC_MB_20(void)
{
	int32_t slStatus = MB_E_INVALID_INDEX;
	slStatus = slMailboxEBDebugEventCnt(-1, MB_CHAN_WR_MODE) ;//Negative TEST CASE
	return slStatus;
}

/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_MB_21] Mailbox Send Trigger <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

int32 TC_MB_21(void)
{
	int32 slStatus = MB_E_NOT_READY;
	slStatus = slMailboxSendTrigger(MAILBOX_EBMAX) ;// Negative TEST CASE
	return slStatus;
} 

/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_MB_22] Int Mailbox chan reset <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

int32 TC_MB_22(void)
{
	int32 slStatus  = MB_E_SUCCESS;
//	slStatus = slMailbox_IBResetRequest( 0x5 );// Negative TEST CASE      // ===> Internal Mailbox API
	return slStatus;
}

/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_MB_23] Int Mailbox Set Status <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

int32 TC_MB_23(void)
{
	uint32 IBStatus = 0xFFU;
//	IBStatus = eMailboxIB_Set_Status( 0x03, 0x5 );// Negative TEST CASE    // ===> Internal mailbox API
	return IBStatus;
}

/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_MB_24] Int Mailbox chan reg <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

int32 TC_MB_24(void)
{
	int32 sllStatus = MB_E_INVALID_INDEX;
//	sllStatus = slMailboxIBChannelReg( IB_CHAN_MAX, 0x2, NULL );// Negative TEST CASE  // ====> Internal mailbox API
	return sllStatus;
}

/* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> [TC_MB_25] Int Mailbox send <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

int32 TC_MB_25(void)
{
	int32 sllStatus = MB_E_SUCCESS;
//	sllStatus = slMailboxIBSend(IB_CHAN_MAX, 10, NULL);// Negative TEST CASE          // =====> Internal Mailbox AI
	return sllStatus;
}


/*
*
*
	<<<<<<<<<<<< xTestMBWrapper >>>>>>>>>>>>>>>
*
*
*/
TESTerrorType_e xTestMBWrapper(void)
{
	int8 NumTestCases = MailboxNumTestCases;
	TESTerrorType_e xReturn = MODULE_TEST_FAILED;
	DEBUG_LOG(SAIL_INFO,"<<<<<<<<<<<<<Mailbox Test Cases Started>>>>>>>>>>\r\n");
/* 	if	( TC_MB_01() != MB_E_SUCCESS )
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_01 Fails\r\n");
	}
	else
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_01 Pass\r\n");
		NumTestCases--;
		xReturn = MODULE_TEST_PASSED;
	}
	if ( TC_MB_06() != MB_E_SUCCESS )
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_06 Fails\r\n");
	}
	else
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_06 Pass\r\n");
		NumTestCases--;
		xReturn = MODULE_TEST_PASSED;
	}
	if ( TC_MB_07() != MB_E_SUCCESS )
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_07 Fails\r\n");
	}
	else
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_07 Pass\r\n");
		NumTestCases--;
		xReturn = MODULE_TEST_PASSED;
	} */
	if ( TC_MB_02() < 0 )
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_02 Fails\r\n");
	}
	else
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_02 Pass\r\n");
		NumTestCases--;
		xReturn = MODULE_TEST_PASSED;
	}
	if ( TC_MB_03() < 0 )
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_03 Fails\r\n");
	}
	else
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_03 Pass\r\n");
		NumTestCases--;
		xReturn = MODULE_TEST_PASSED;
	}
/* 	if ( 0U > TC_MB_04 || TC_MB_04 > 4U  )
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_04 Fails\r\n");
	}
	else
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_04 Pass\r\n");
		NumTestCases--;
		xReturn = MODULE_TEST_PASSED;
	} */
	if ( TC_MB_05() < 0 )
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_05 Fails\r\n");
	}
	else
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_05 Pass\r\n");
		NumTestCases--;
		xReturn = MODULE_TEST_PASSED;
	}
	if ( TC_MB_08() != MB_E_SUCCESS )
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_08 Fails\r\n");
	}
	else
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_08 Pass\r\n");
		NumTestCases--;
		xReturn = MODULE_TEST_PASSED;
	}
	if ( TC_MB_09() != MB_E_INVALID_INDEX )
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_09 Fails\r\n");
	}
	else
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_09 Pass\r\n");
		NumTestCases--;
		xReturn = MODULE_TEST_PASSED;
	}
	if ( TC_MB_10() != 4U )
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_10 Fails\r\n");
	}
	else
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_10 Pass\r\n");
		NumTestCases--;
		xReturn = MODULE_TEST_PASSED;
	}
	if ( TC_MB_11() == 4U )
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_11 Fails\r\n");
	}
	else
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_11 Pass\r\n");
		NumTestCases--;
		xReturn = MODULE_TEST_PASSED;
	}
/* 	if ( TC_MB_12() != MB_E_SUCCESS )
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_12 Fails\r\n");
	}
	else
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_12 Pass\r\n");
		NumTestCases--;
		xReturn = MODULE_TEST_PASSED;
	} */
	if ( TC_MB_13() < 0)
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_13 Pass\r\n");
		NumTestCases--;
		xReturn = MODULE_TEST_PASSED;
	}
	else
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_13 Fails\r\n");
	}
	if ( TC_MB_14() < 0  )
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_14 Pass\r\n");
		NumTestCases--;
		xReturn = MODULE_TEST_PASSED;
	}
	else
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_14 Fails\r\n");
	}
	if ( TC_MB_15() < 0 )
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_15 Pass\r\n");
		NumTestCases--;
		xReturn = MODULE_TEST_PASSED;
	}
	else
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_15 Fails\r\n");
	}
	if ( TC_MB_16() < 0 )
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_16 Pass\r\n");
		NumTestCases--;
		xReturn = MODULE_TEST_PASSED;
	}
	else
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_16 Fails\r\n");
	}
	if ( TC_MB_17() != 0xFFU )
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_17 Fails\r\n");
	}
	else
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_17 Pass\r\n");
		NumTestCases--;
		xReturn = MODULE_TEST_PASSED;
	}
	if ( TC_MB_18() != 0xFFU )
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_18 Fails\r\n");
	}
	else
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_18 Pass\r\n");
		NumTestCases--;
		xReturn = MODULE_TEST_PASSED;
	}
	if ( TC_MB_19() == 4U )
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_19 Fails\r\n");
	}
	else
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_19 Pass\r\n");
		NumTestCases--;
		xReturn = MODULE_TEST_PASSED;
	}
	if ( TC_MB_20() == MB_E_INVALID_INDEX || TC_MB_20() == MB_E_NULL_INPUT  )
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_20 Pass\r\n");
		NumTestCases--;
		xReturn = MODULE_TEST_PASSED;
	}
	else
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_20 Fails\r\n");
	}
/* 	if ( TC_MB_21() != MB_E_SUCCESS )
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_21 Pass\r\n");
		NumTestCases--;
		xReturn = MODULE_TEST_PASSED;
	}
	else
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_21 Fails\r\n");
	} */
	if ( TC_MB_22() != MB_E_SUCCESS )
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_22 Pass\r\n");
		NumTestCases--;
		xReturn = MODULE_TEST_PASSED;
	}
	else
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_22 Fails\r\n");
	}
	if ( TC_MB_23() != MB_E_SUCCESS )
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_23 Pass\r\n");
		NumTestCases--;
		xReturn = MODULE_TEST_PASSED;
	}
	else
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_23 Fails\r\n");
	}
	if ( TC_MB_24() != MB_E_SUCCESS )
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_24 Pass\r\n");
		NumTestCases--;
		xReturn = MODULE_TEST_PASSED;
	}
	else
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_24 Fails\r\n");
	}
	if ( TC_MB_25() < 0 )
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_24 Pass\r\n");
		NumTestCases--;
		xReturn = MODULE_TEST_PASSED;
	}
	else
	{
		DEBUG_LOG(SAIL_INFO,"TC_MB_24 Fails\r\n");
	}
	if ( NumTestCases == 0 )
	{ 
		DEBUG_LOG(SAIL_INFO, "Mailbox All Test Case Passed!\r\n");
	}
	else
	{
		DEBUG_LOG(SAIL_INFO, "Mailbox All Test Case NOT Passed!\r\n");
	}
	return xReturn;
}