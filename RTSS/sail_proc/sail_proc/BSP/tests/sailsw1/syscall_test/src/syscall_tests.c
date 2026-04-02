/**************************************************************************************************
    Copyright (c) 2024 Qualcomm Technologies, Inc.
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
    File Name          : syscall_tests.c
    Component Name     : Syscall
    Description        : Syscall driver interface test file
    $Header: $
    $DateTime: $
    $Author: $
=================================================================================================*/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include <stdio.h>
#include "tests.h"
#include <stdlib.h>
#include "debug_log.h"
#include "busywait.h"
#include "timetick.h"
#include "syscall_hvc.h"
#include "syscall_svc.h"
#include "syscall_pub.h"
#include "syscall.h"
#include "err_fatal.h"

/*******************************************************************************
**                Private Macro Definitions                                   **
*******************************************************************************/

#define syscallTOTALTESTCASES 2U


/*******************************************************************************
**                Global variables                                            **
*******************************************************************************/

/*******************************************************************************
**                  Private Function declaration                              **
*******************************************************************************/

/*******************************************************************************
**                  Private Function definition                               **
*******************************************************************************/

TEST_FUNC static void prvSyscallTestDebugPrint ( TESTerrorType_e result, const char * TestMsg, uint16_t usTestCaseNum )
{
    if ( MODULE_TEST_PASSED == result ) /* Error injection Test pass */
    {
        DEBUG_LOG( SAIL_INFO,"[TC_SYSCALL_%03d] Passed: %s\n\r", usTestCaseNum, TestMsg );
    }
    else
    {
        DEBUG_LOG( SAIL_INFO,"[TC_SYSCALL_%03d] Failed: %s\n\r", usTestCaseNum, TestMsg);
    }
}

TEST_FUNC static boolean slSyscallTestSyscall (uint32_t ulSyscallParam)
{
    uint32_t hvcId     = SYSCALL_TEST_HVC_ID;
    uint32_t paramId   = SYSCALL_TEST_HVC_PARAM_ID;
    uint32_t arg1      = (uint32_t)ulSyscallParam;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    boolean  ret       = FALSE;

    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
            err_fatal(EL_ENTRY, ERR_FATAL_SVC_CALL_FAILED);
        }
    }
    
	ret = (boolean)paramId;
	
    return ret;
}

TEST_FUNC static uint32_t ulSyscallTestSvcTrap ( uint32_t ulSyscallParam, sailbsp_svc_rsp_t *rsp)
{
    /* rsp->data[0] return clock result */
    rsp->data[0] = slSyscallTestSyscall ( ulSyscallParam);

    return (uint32_t)SVC_SUCCESS;
}

SAIL_DEFINE_SYSCALL(SYSCALL_TEST_HVC_ID,
                    SYSCALL_TEST_HVC_PARAM_ID,
                    0,
                    ulSyscallTestSvcTrap);


TEST_FUNC TESTerrorType_e TC_SYSCALL_001( void )
{
    TESTerrorType_e eSyscallTestResultType = MODULE_TEST_PASSED;	
	
	for(int i = 0; i < 100; i++)
	{
	    if( slSyscallTestSyscall (0xDEADBEEFU) != TRUE )
	    {
	    	eSyscallTestResultType = MODULE_TEST_FAILED;
	    	break;
	    }
	}

end:
	prvSyscallTestDebugPrint ( eSyscallTestResultType, "Regressive Syscall test", 1 );
	return eSyscallTestResultType;
}

TEST_FUNC TESTerrorType_e TC_SYSCALL_002( void )
{
    TESTerrorType_e eSyscallTestResultType = MODULE_TEST_PASSED;	
	uint32_t svc_id=0; uint32_t param_id=0; uint32_t arg1=0; uint32_t arg2=0; uint32_t arg3=0; uint32_t arg4=0;
	
	for(int i=0; i<50; i++)
	{
	    if( svc_call(NULL, &param_id, &arg1, &arg2, &arg3, &arg4) == SVC_SUCCESS )
	    {
	    	eSyscallTestResultType = MODULE_TEST_FAILED;
	    	goto end;
	    }
	    
	    if( svc_call(&svc_id, NULL, &arg1, &arg2, &arg3, &arg4) == SVC_SUCCESS )
	    {
	    	eSyscallTestResultType = MODULE_TEST_FAILED;
	    	goto end;
	    }
	    
	    if( svc_call(&svc_id, &param_id, NULL, &arg2, &arg3, &arg4) == SVC_SUCCESS )
	    {
	    	eSyscallTestResultType = MODULE_TEST_FAILED;
	    	goto end;
	    }
	    
	    if( svc_call(&svc_id, &param_id, &arg1,NULL, &arg3, &arg4) == SVC_SUCCESS )
	    {
	    	eSyscallTestResultType = MODULE_TEST_FAILED;
	    	goto end;
	    }
	    
	    if( svc_call(&svc_id, &param_id, &arg1, &arg2, NULL, &arg4) == SVC_SUCCESS )
	    {
	    	eSyscallTestResultType = MODULE_TEST_FAILED;
	    	goto end;
	    }
	    
	    if( svc_call(&svc_id, &param_id, &arg1, &arg2, &arg3, NULL) == SVC_SUCCESS )
	    {
	    	eSyscallTestResultType = MODULE_TEST_FAILED;
	    	goto end;
	    }
	}

end:
	prvSyscallTestDebugPrint ( eSyscallTestResultType, "SVC Call Negative tests", 2 );
	return eSyscallTestResultType;
}

TEST_FUNC TESTerrorType_e TC_SYSCALL_003( void )
{
    TESTerrorType_e eSyscallTestResultType = MODULE_TEST_PASSED;	
	uint32_t hvc_id=0; uint32_t param_id=0; uint32_t arg1=0; uint32_t arg2=0; uint32_t arg3=0; uint32_t arg4=0;
	
	for(int i=0; i<50; i++)
	{
	    if( hvc_call(NULL, &param_id, &arg1, &arg2, &arg3, &arg4) == HVC_SUCCESS )
	    {
	    	eSyscallTestResultType = MODULE_TEST_FAILED;
	    	goto end;
	    }
	    
	    if( hvc_call(&hvc_id, NULL, &arg1, &arg2, &arg3, &arg4) == HVC_SUCCESS )
	    {
	    	eSyscallTestResultType = MODULE_TEST_FAILED;
	    	goto end;
	    }
	    
	    if( hvc_call(&hvc_id, &param_id, NULL, &arg2, &arg3, &arg4) == HVC_SUCCESS )
	    {
	    	eSyscallTestResultType = MODULE_TEST_FAILED;
	    	goto end;
	    }
	    
	    if( hvc_call(&hvc_id, &param_id, &arg1,NULL, &arg3, &arg4) == HVC_SUCCESS )
	    {
	    	eSyscallTestResultType = MODULE_TEST_FAILED;
	    	goto end;
	    }
	    
	    if( hvc_call(&hvc_id, &param_id, &arg1, &arg2, NULL, &arg4) == HVC_SUCCESS )
	    {
	    	eSyscallTestResultType = MODULE_TEST_FAILED;
	    	goto end;
	    }
	    
	    if( hvc_call(&hvc_id, &param_id, &arg1, &arg2, &arg3, NULL) == HVC_SUCCESS )
	    {
	    	eSyscallTestResultType = MODULE_TEST_FAILED;
	    	goto end;
	    }
	}

end:
	prvSyscallTestDebugPrint ( eSyscallTestResultType, "HVC Call Negative tests", 3 );
	return eSyscallTestResultType;
}

SM_APP_DATA uint8 uSyscallTestCaseCnt =  syscallTOTALTESTCASES; 

TEST_FUNC void vTestSyscallWrappper1( void )
{
    if ( MODULE_TEST_PASSED != TC_SYSCALL_001( ) )
    {
        uSyscallTestCaseCnt--;
    }
    if ( MODULE_TEST_PASSED != TC_SYSCALL_002( ) )
    {
        uSyscallTestCaseCnt--;
    }
}

TEST_FUNC TESTerrorType_e xTestSyscallWrappper2( void )
{
    if ( MODULE_TEST_PASSED != TC_SYSCALL_003( ) )
    {
        uSyscallTestCaseCnt--;
    }
	
    if ( syscallTOTALTESTCASES == uSyscallTestCaseCnt )
    {
        DEBUG_LOG( SAIL_INFO, ">>>>> Syscall all test cases passed <<<<<\n\r" );
		return MODULE_TEST_PASSED;
    }
    else
    {
        DEBUG_LOG( SAIL_INFO, ">>>>> Syscall all test cases not passed <<<<<\n\r" );
		return MODULE_TEST_FAILED;
    }
}
