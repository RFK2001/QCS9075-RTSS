/**
 * @file sail_bootcfg_el1.c
 * @brief Sail boot configs functions
 * Source file for the definition of Sail diagnostics util functions
 *
 *        Copyright (c) 2021 - 2025 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
*/


/*===========================================================================

                            EDIT HISTORY FOR FILE

when       who      what, where, why
--------   ---     ------------------------------------------------------------
08.04.22   pmdonthi       Created
=============================================================================*/
#include "syscall.h"
#include "syscall_hvc.h"
#include "syscall_svc.h"
#include "syscall_pub.h"
#include "common_functions.h"
#include "err_fatal.h"
#include "types.h"

BSP_GLOBAL_DATA static uint8 capt_sec_gpio_val = 0, cap_sec_gpio_init = 0;

/**********************************************************
 * Syscall wrapper for sail diagnostics utils Trap interface
 *
 * @return uint8 [OUT]
 *   value of the Capt sec GPIO register.
 **********************************************************/
uint8 getCaptSecGpioVal_trap_syscall_wrap(void)
{
    uint8 capt_sec_val_local = 0;
    
    uint32_t hvcId     = (uint32_t)SAIL_GET_CAPT_SEC_GPIO;
    uint32_t paramId   = (uint32_t)SAIL_GET_CAPT_SEC_GPIO_PARAM_ID;
    uint32_t arg1      = 0;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;

    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        if((int)HVC_SUCCESS != hvc_call(&hvcId, &paramId, &arg1, &arg2, &arg3, &arg4))
        {
            err_fatal(EL_ENTRY, ERR_FATAL_HVC_CALL_FAILED);
        }
    }
    else
    {
        if((int)SVC_SUCCESS != svc_call(&hvcId, &paramId, &arg1, &arg2, &arg3, &arg4))
        {
            err_fatal(EL_ENTRY, ERR_FATAL_SVC_CALL_FAILED);
        }
    }
    
    capt_sec_val_local = (uint8)paramId;
    
    return capt_sec_val_local;
}

/**********************************************************
 * EL1 trap function for the sail diagnostics utils get capt sec GPIO
 *
 * @return uint32 [OUT]
 *   Result of the operation.
 **********************************************************/
uint32 sailbsp_El1trap_get_capt_sec_gpio_val(sailbsp_svc_rsp_t *rsp)
{
    rsp->data[0] = ((uint32_t)getCaptSecGpioVal_trap_syscall_wrap());

    return SVC_SUCCESS;
}

/**********************************************************
 * Function to get the sail diagnostics utils capt sec GPIO value
 *
 * @return uint32 [OUT]
 *   Result of the operation.
 **********************************************************/
uint8 sailbsp_get_capt_sec_gpio_val(void)
{
    if(cap_sec_gpio_init == 0)
    {
        capt_sec_gpio_val = getCaptSecGpioVal_trap_syscall_wrap();
        cap_sec_gpio_init = 1;
    }
    
    return capt_sec_gpio_val;
}

/* SYS CALL DECLARATIONS */
SAIL_DEFINE_SYSCALL(  SAIL_GET_CAPT_SEC_GPIO,
                      SAIL_GET_CAPT_SEC_GPIO_PARAM_ID,
                      0,
                      sailbsp_El1trap_get_capt_sec_gpio_val
                    );