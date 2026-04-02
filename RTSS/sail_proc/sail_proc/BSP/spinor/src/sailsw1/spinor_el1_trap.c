/*
===========================================================================
*/
/**
    @file  spinor_el1_trap.c
    @brief Implementation of spinor EL1 Trap services

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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/src/sailsw1/spinor_el1_trap.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "spinor_el1_trap.h"
#include "syscall.h"
#include "spinor_trap_defs.h"
#include "syscall_hvc.h"
#include "syscall_svc.h"
#include "syscall_pub.h"
#include "FreeRTOSOsal.h"
#include "common_functions.h"
#include "err_fatal.h"


uint32 spinorEl1TrapInterface(spinorTrapEventID_t eventID, spinorTrapParams_t* trapParam, sailbsp_svc_rsp_t *rsp)
{
    rsp->data[0] = ((uint32_t)spinor_trap_syscall_wrap(eventID, trapParam));

    return SVC_SUCCESS;
}

/**********************************************************
 * Syscall wrapper for spinor Trap interface
 *
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_trap_syscall_wrap(spinorTrapEventID_t eventID, spinorTrapParams_t* trapParam)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;

    /* Construct the HVC call parameters */
    uint32_t hvc_id=SAIL_SPINOR_FUNC_TRAP;
    uint32_t param_id=SAIL_SPINOR_FUNC_TRAP_PARAM_ID;
    uint32_t arg1 = (uint32)eventID;
    uint32_t arg2 = (uint32)trapParam;
    uint32_t arg3 = 0U;
    uint32_t arg4 = 0U;

    /* Make HVC/SVC call */
    if(TRUE == xSyscallIsPrivilegedMode())
    {
        if(HVC_SUCCESS != hvc_call(&hvc_id, &param_id, &arg1, &arg2, &arg3, &arg4))
        {
            err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if(SVC_SUCCESS != svc_call(&hvc_id, &param_id, &arg1, &arg2, &arg3, &arg4))
        {
            err_fatal(EL_ENTRY, ERR_FATAL_SVC_CALL_FAILED);
        }
    }

    status = (SPINOR_STATUS)param_id;

    return status;
}

/**********************************************************
 *
 *
 * SPINOR service trap systemcall interface primitives
 *
 *
 **********************************************************/

/* SYS CALL DECLARATIONS */

SAIL_DEFINE_SYSCALL(  SAIL_SPINOR_FUNC_TRAP,
                      SAIL_SPINOR_FUNC_TRAP_PARAM_ID,
                      0,
                      spinorEl1TrapInterface
                    );

