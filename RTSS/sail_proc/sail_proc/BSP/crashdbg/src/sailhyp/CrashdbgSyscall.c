/**************************************************************************************************
** Copyright (c) 2022 Qualcomm Technologies, Inc.                                                **
** All Rights Reserved.                                                                          **
** Confidential and Proprietary - Qualcomm Technologies, Inc.                                    **
**************************************************************************************************/

/*=================================================================================================
    File Name          : Crachdbg_syscall.c
    Component Name     : Crashdbg
    Description        : Crashdbg HVC Syscall table and wrapper define in this module
    $Header:  $
    $DateTime:  $
    $Author:  $
=================================================================================================*/

/*=================================================================================================
**                                        Include files                                          **
=================================================================================================*/

#include <stdlib.h>
#include <stdio.h>
#include "syscall_pub.h"
#include "syscall.h"
#include "types.h"
#include "Crashdbg_api.h"

/* =========================================================================
**  Function : CrashdbgSyscall_disable_debug
** =========================================================================*/
/**
  This function disables debug by clearing SAIL_CC RESET_DEBUG_EN and mask or unmask SAIL_CC MD_PS_HOLD_MASK register, based on request.

  @param rsp [out], Crashdbg_Result( rsp->data[0])

  @return
  HVC_SUCCESS

  @dependencies
  None.
*/
uint32 CrashdbgSyscall_disable_debug(Crashdbg_CtrlType_e ctrl_type, sailbsp_hvc_rsp_t *rsp )
{
    /* rsp->data[0] return Crashdbg result */
    rsp->data[0] =  Crashdbg_disable(ctrl_type);

    return HVC_SUCCESS;
}

/*
 * uint32 CrashdbgSyscall_disable_debug ( int reset_type, sailbsp_hvc_rsp_t *rsp )
 */
SAIL_DEFINE_SYSCALL( CRASHDBG_DISDBG_HVC_ID,
                     CRASHDBG_DISDBG_PARAM_ID,
                     0,
                     CrashdbgSyscall_disable_debug );

