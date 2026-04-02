/*
===========================================================================
*/
/**
    @file  sailupdater_tests.c
    @brief Implementation of SAIL Updater Unit test and Functional test

*/
/*
    ===========================================================================

    Copyright (c) 2023 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/asuthar.bsp.sail.1.0.TestFolderReStructure/tests/sailsw1/sailupdater_el2_tests_sw1.c#1 $
    $DateTime: 2024/01/25 22:37:00 $
    $Author: asuthar $
=========================================================================================================*/

/*=========================================================================================================
**                                        Include files                                                  **
=========================================================================================================*/
#include "common_functions.h"
#include "debug_log.h"
#include "cache_ops.h"
#include "common_functions.h"
#include "tests.h"
#include "sail_updater_core.h"
#include "mailboxExt_api.h"
#include "autosar_crc.h"
#include "syscall_pub.h"
#include "syscall_hvc.h"

#ifdef SAILUPDATER_TEST_SRC_ENABLED
/*========================================================================================================
**  Function :  xTestSailUpdater_FastBootTest_Wrapper
**  sailupdater test
** ========================================================================================================
*/
TESTerrorType_e xTestSailUpdater_FastBootTest_Wrapper(void)
{
    uint8 *find;
    uint32_t hvcId = 0;
    uint32_t paramId = 0;
    uint32_t arg1 = 0;
    uint32_t arg2 = 0;
    uint32_t arg3 = 0;
    uint32_t arg4 = 0;

    find = APPL_SAIL_Shell_gettoken(NULL);

    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;

    /*Add hvc calls to execute EL2 Fastboot unit tests for below commands*/
    if(APPL_SAIL_Shell_stricmp("ut",(char*)find))
    {
    	find = APPL_SAIL_Shell_gettoken(NULL);
    	if (APPL_SAIL_Shell_stricmp("init",(char*)find))
        {
            hvcId = FASTBOOT_INIT_HVC_ID;
	    paramId = FASTBOOT_INIT_PARAM_ID;
            if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    	    {
	        DEBUG_LOG(SAIL_INFO, " xTestSailUpdater_FastBootTest_Wrapper: hvc_call to FASTBOOT_INIT_HVC_ID Failed\n\r");
	        return xRetStatus;
    	    }
    	    xRetStatus = MODULE_TEST_PASSED;
        }
        else if (APPL_SAIL_Shell_stricmp("hello",(char*)find))
        {
            hvcId = FASTBOOT_HELLO_HVC_ID;
	    paramId = FASTBOOT_HELLO_PARAM_ID;	
            if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    	    {
	        DEBUG_LOG(SAIL_INFO, " xTestSailUpdater_FastBootTest_Wrapper: hvc_call to FASTBOOT_HELLO_HVC_ID Failed\n\r");
	        return xRetStatus;
    	    }
    	    xRetStatus = MODULE_TEST_PASSED;
        }
        else if (APPL_SAIL_Shell_stricmp("flashimg",(char*)find))
        { 
            hvcId = FASTBOOT_FLASHIMG_HVC_ID;
	    paramId = FASTBOOT_FLASHIMG_PARAM_ID;	
            if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    	    {
	        DEBUG_LOG(SAIL_INFO, " xTestSailUpdater_FastBootTest_Wrapper: hvc_call to FASTBOOT_FLASHIMG_HVC_ID Failed\n\r");
       	        return xRetStatus;
    	    }
    	    xRetStatus = MODULE_TEST_PASSED;
        }
        else if (APPL_SAIL_Shell_stricmp("readimg",(char*)find))
        {
            hvcId = FASTBOOT_READIMG_HVC_ID;
	    paramId = FASTBOOT_READIMG_PARAM_ID;	
            if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    	    {
	        DEBUG_LOG(SAIL_INFO, " xTestSailUpdater_FastBootTest_Wrapper: hvc_call to FASTBOOT_READIMG_HVC_ID Failed\n\r");
        	return xRetStatus;
    	    }
    	    xRetStatus = MODULE_TEST_PASSED;
        }
        else if (APPL_SAIL_Shell_stricmp("queryimg",(char*)find))
        {
            hvcId = FASTBOOT_QUERYIMG_HVC_ID;
	    paramId = FASTBOOT_QUERYIMG_PARAM_ID;
            if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    	    {
	        DEBUG_LOG(SAIL_INFO, " xTestSailUpdater_FastBootTest_Wrapper: hvc_call to FASTBOOT_QUERYIMG_HVC_ID Failed\n\r");
        	return xRetStatus;
    	    }
	    xRetStatus = MODULE_TEST_PASSED;
        }
        else if (APPL_SAIL_Shell_stricmp("blinfo",(char*)find))
        {
            hvcId = FASTBOOT_BLINFO_HVC_ID;
	    paramId = FASTBOOT_BLINFO_PARAM_ID;	
            if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    	    {
	        DEBUG_LOG(SAIL_INFO, " xTestSailUpdater_FastBootTest_Wrapper: hvc_call to FASTBOOT_BLINFO_HVC_ID Failed\n\r");
        	return xRetStatus;
    	    }
    	    xRetStatus = MODULE_TEST_PASSED;
        }
        else if (APPL_SAIL_Shell_stricmp("bootimage",(char*)find))
        {
            hvcId = FASTBOOT_BOOTIMG_HVC_ID;
	    paramId = FASTBOOT_BOOTIMG_PARAM_ID;
            if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    	    {
	        DEBUG_LOG(SAIL_INFO, " xTestSailUpdater_FastBootTest_Wrapper: hvc_call to FASTBOOT_BOOTIMG_HVC_ID Failed\n\r");
        	return xRetStatus;
    	    }
    	    xRetStatus = MODULE_TEST_PASSED;
        }     
        else if (APPL_SAIL_Shell_stricmp("bootcontinue",(char*)find))
        {
            hvcId = FASTBOOT_BOOTCONTINUE_HVC_ID;
	    paramId = FASTBOOT_BOOTCONTINUE_PARAM_ID; 	
            if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    	    {
	        DEBUG_LOG(SAIL_INFO, " xTestSailUpdater_FastBootTest_Wrapper: hvc_call to FASTBOOT_BOOTCONTINUE_HVC_ID Failed\n\r");
        	return xRetStatus;
    	    }
	    xRetStatus = MODULE_TEST_PASSED;
        }
        else
        {
            /* Invalid cmd */
            DEBUG_LOG( SAIL_INFO,"sail_updater EL2 fboot ut syntax invalid  \n\r" );
            return xRetStatus;
        }
    }
    else
    {
        /* Invalid cmd */
        DEBUG_LOG( SAIL_INFO,"sail_updater EL2 fboot syntax invalid  \n\r" );
        return xRetStatus;
    }
    return xRetStatus;
}

#endif //SAILUPDATER_TEST_SRC_ENABLED
/**********************************************************************************************************
**                                  End of file sailupdater_test.c                                              **
**********************************************************************************************************/
