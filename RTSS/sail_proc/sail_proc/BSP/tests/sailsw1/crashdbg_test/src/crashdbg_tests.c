/**********************************************************************************************************
    Copyright (c) 2022 Qualcomm Technologies, Inc.
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
**********************************************************************************************************/

/*=========================================================================================================
    File Name          : crashdbg_tests.c
    Component Name     : SAIL Crash debug Unit Test
    Description        : SAIL Crash debug Unit Test features are implemented in this file.
    $Header: $
    $DateTime: 2 $
    $Author: pwbldsvc $
=========================================================================================================*/

/*=========================================================================================================
**                                        Include files                                                  **
=========================================================================================================*/
#include "common_functions.h"
#include "debug_log.h"
#include "Crashdbg_api.h"
#include "tests.h"
#include "pmicapi.h"

/*=========================================================================================================
**                                        Local defines and macros                                       **
=========================================================================================================*/
typedef enum
{
    DBG_TEST_FAIL = 0,
    DBG_TEST_PASS = 1
}CrashdbgTest_StatusType_e;
/*=========================================================================================================
**                                        Static variables and constants                                 **
=========================================================================================================*/

/*=========================================================================================================
**                                        Local function definitions                                     **
=========================================================================================================*/

/*========================================================================================================
**  Function :  xTestCrashdbg_El1_Wrapper
**  Wdt test
** ========================================================================================================
*/


TEST_FUNC TESTerrorType_e xTestCrashdbg_El1_Wrapper(void)
{
    uint8 *find;
    uint8 currentCoreNum = 0;
	Crashdbg_Result result;
	CrashdbgTest_StatusType_e DbgTest_Status = DBG_TEST_FAIL;
	pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
	
    find = APPL_SAIL_Shell_gettoken(NULL);

	TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
	currentCoreNum = get_curr_phys_cpu_num();

     if(APPL_SAIL_Shell_stricmp("core0",(char*)find))
     {
    	if (0 == currentCoreNum)
       {
            find = APPL_SAIL_Shell_gettoken(NULL);

            if (APPL_SAIL_Shell_stricmp("depcrashdisable",(char*)find))
            {
				//Disable only SAIL dependent crash flow upon MD fatal error. 
				//SAIL crash dump collection upon SAIL fatal error is still supported.
            	result = Crashdbg_disable(DEP_CRASH_DISABLED);
                if(result == DBG_DISABLED)
                {
                    DbgTest_Status = DBG_TEST_PASS;
                    DEBUG_LOG( SAIL_INFO,"SAIL depcrash disabled for MD fatal err\n\r" );
                }
            }
            else if (APPL_SAIL_Shell_stricmp("crashdbgdisable",(char*)find))
            {
				//Disable SAIL crash debug completely.
            	result = Crashdbg_disable(CRASHDBG_DISABLED);
				//Reconfigure SAIL PMIC for hard reset
				xErrFlag = xPmicSetResetState(PMIC_POFF_PON);
                if( (result == DBG_DISABLED) && (xErrFlag == PMIC_ERR_FLAG_SUCCESS) )
                {
                    DbgTest_Status = DBG_TEST_PASS;
                    DEBUG_LOG( SAIL_INFO,"SAIL crash dbg disabled \n\r" );
                }
            }
			else
            {
            	/* Invalid cmd */
            	 DEBUG_LOG( SAIL_INFO,"Core0 Crashdbg cmd invalid or syntax invalid \n\r" );
            	 return xRetStatus;
            }
       }
       else
       {
    	   /* if current is not core0 */
       }
     }
     else
     {
    	 /* Invalid cmd */
    	 DEBUG_LOG( SAIL_INFO, "Crashdbg cmd invalid or syntax invalid \n\r" );
     }

return xRetStatus;

}

TEST_FUNC TESTerrorType_e x_TestCrashdbg_El1_Wrapper(void)
{
	CrashdbgTest_StatusType_e DbgTest_Status = DBG_TEST_FAIL;
	pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;
	TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
	
	uint8 TestCnt = 2; 
	if ( DBG_DISABLED == Crashdbg_disable(DEP_CRASH_DISABLED)) 
	{
		DbgTest_Status = DBG_TEST_PASS;
        DEBUG_LOG( SAIL_INFO,"SAIL depcrash disabled for MD fatal err\n\r" );
		TestCnt--;
	}
	if( DBG_DISABLED == Crashdbg_disable(DEP_CRASH_DISABLED) )
	{
		if ( PMIC_ERR_FLAG_SUCCESS == xPmicSetResetState(PMIC_POFF_PON) )
		{
			DbgTest_Status = DBG_TEST_PASS;
            DEBUG_LOG( SAIL_INFO,"SAIL crash dbg disabled \n\r" );
			TestCnt--;
		}
	}
	
	if ( TestCnt == 0 )
	{
		DEBUG_LOG( SAIL_INFO,"CrashDebug All Test Case Passed. \n\r" );
		xRetStatus = MODULE_TEST_PASSED;
	}
	else
	{
		DEBUG_LOG( SAIL_INFO,"CrashDebug Test case Failed. \n\r" );
	}
	
	return xRetStatus;
}

/**********************************************************************************************************
**                                  End of file wdt_tests.c                                              **
**********************************************************************************************************/
