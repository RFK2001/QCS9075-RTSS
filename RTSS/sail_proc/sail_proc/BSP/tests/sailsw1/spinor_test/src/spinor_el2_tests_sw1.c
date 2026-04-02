/*
===========================================================================
*/
/**
    @file  spinor_el2_tests_sw1.c
    @brief Testing the spinor EL2 tests in SW1 via HVC calls

*/
/*
    ===========================================================================

    Copyright (c) 2021-24 Qualcomm Technologies, Inc.
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

    $Header: //components/rel/bsp.sail/1.0/tests/spinor_el2_tests.c#5 $
    $DateTime: 2022/07/20 12:27:51 $
    $Author: pwbldsvc $

    ===========================================================================
*/

#include <stdio.h>
#include "tests.h"
#include "syscall_pub.h"
#include "syscall_hvc.h"
#include "spinor_tests.h"
#include "err_fatal.h"

/*
*
*
<<<<<<<<<<<< xTestSpinorEL2Wrapper >>>>>>>>>>>>>>>
*
*
*/
TEST_FUNC TESTerrorType_e xTestSpinorEL2WrapperFromSW1(void)
{
    TESTerrorType_e status = MODULE_TEST_FAILED;
    spinorTrapTestEventID_t testeventID = 0;
    uint32_t hvcId = 0U, paramId = 0U, arg1 = 0U, arg2 = 0U, arg3 = 0U, arg4 = 0U;
    
    for(testeventID = SPINOR_TEST_TRAP_FUNC_ERASERD; testeventID <= SPINOR_TEST_TRAP_FUNC_MAX; testeventID++)
    {
        hvcId = SAIL_SPINOR_FUNC_TEST_TRAP;
        paramId = SAIL_SPINOR_FUNC_TEST_TRAP_PARAM_ID;
        arg1 = (uint32_t)testeventID;
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
        vFreeRTOSTaskDelay(50u);
    }
    
    return status;
}
