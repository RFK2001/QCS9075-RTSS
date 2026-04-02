/**
 * @file syscall_svc.c
 * @brief
 * Source file for Sail SVC calls
 *
 *        Copyright (c) 2023 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*===========================================================================

=============================================================================*/


/*===========================================================================
                               INCLUDE FILES
===========================================================================*/
#include"types.h"
#include <stdlib.h>
#include <stdio.h>
#include "syscall_svc.h"
#include "syscall_pub.h"
#include "syscall.h"
#include "debug_log.h"
#include "common_functions.h"
#include "freertos_init.h"
#include "err_fatal.h"

#define SVC_SAIL_GLOBAL_ID (uint8_t)25


/*===========================================================================
                               VARIABLES
============================================================================*/
static BSP_GLOBAL_DATA  void              *pvSVCParmAdd             = NULL;
static BSP_GLOBAL_DATA svcSyscallParamType     xSvcParm             = {0};
/*
 *===========================================================================
 *                              FUNCTIONS
 *===========================================================================*/
/*===========================================================================
**  Function :  xSyscallIsPrivilegedMode
** ==========================================================================
*/
/*!
*
* @brief
*   This function will check the priv or user mode.
*
* @param
*  None
* @par Dependencies
*   None
* @retval
*   boolean- TRUE/FALSE
* @par Side Effects
*   None
*
*/

SYSCALL_FUNC boolean xSyscallIsPrivilegedMode( void )
{
    boolean  bPrivMode   = TRUE;
    uint32_t ulCPSR_reg  = 0;

    __asm__ ( "mrs %0, CPSR\n" : "=r"(ulCPSR_reg) :);
    if( CPSR_MODE_USR == ( ulCPSR_reg & CPSR_MODE_MASK ) ) /* Is the task running privileged? */
    {
        bPrivMode = FALSE;
    }
    return bPrivMode;
}
/*===========================================================================
**  Function :  svc_call
** ==========================================================================
*/
/*!
*
* @brief
*   Incoke SVC from EL1 mode.
*
* @param
    uint32_t *cmd_id       -- SVC ID
    uint32_t *param_id     -- PARAM ID
    uint32_t *arg1         -- Arg1
    uint32_t *arg2         -- Arg2
    uint32_t *arg3         -- Arg3
    uint32_t *arg4         -- Arg4
* @par Dependencies
*   None
* @retval
*   Success or Error code
* @par Side Effects
*   None
*
*/

SYSCALL_FUNC int svc_call(uint32_t *svc_id, uint32_t *param_id, uint32_t *arg1, uint32_t *arg2, uint32_t *arg3, uint32_t *arg4)
{
    int svcResult = (int)SVC_ERR_FAILURE ;

    if( pdPASS != xFreeRTOSMutexTake ( pxMutexHandleSVCParmAdd, freertosMAX_DELAY ) )
    {
        err_fatal(EL_ENTRY, ERR_FATAL_SVC_CALL_FAILED);
    }

    if( (svc_id == NULL ) || ( param_id == NULL ) || ( arg1 == NULL ) || ( arg2 == NULL ) || ( arg3 == NULL )
             || ( arg4 == NULL ) )
    {
        svcResult = (int)SVC_ERR_FAILURE;
		goto end;
    }

    xSvcParm.func_id       = *svc_id;
    xSvcParm.param_list_id = *param_id;
    xSvcParm.param0        = *arg1;
    xSvcParm.param1        = *arg2;
    xSvcParm.param2        = *arg3;
    xSvcParm.param3        = *arg4;

    pvSVCParmAdd    = (void *)&xSvcParm;

    //TODO: uncomment once SVC_Handler supports platform syscall framework.
    // __asm volatile( " SVC  25 " );

    /* SVC return status, success or failure */
    svcResult = xSvcParm.res_p.ret;

    /* API Syscall return status, success or failure */
    *param_id = xSvcParm.res_p.rsp.data[0];

end:
	/* Need to release the mutex for next SVC call */
	if( pdPASS != xFreeRTOSMutexGive ( pxMutexHandleSVCParmAdd ) )
    {
        err_fatal(EL_ENTRY, ERR_FATAL_SVC_CALL_FAILED);
    }
    return svcResult;
}

/*===========================================================================
**  Function :  vSafertosSvcHookWrapper
** ==========================================================================
*/
/*!
*
* @brief
*   This is the SVC hook wrapper, will be called from SafeRTOS SVC hook
*
* @param
    uint32_t uxSvcNumber       -- SVC number
* @par Dependencies
*   None
* @retval
*   None
* @par Side Effects
*   None
*
*/
SYSCALL_FUNC void vFreertosSvcHookWrapper( uint32_t uxSvcNumber )
{
    if( SVC_SAIL_GLOBAL_ID == uxSvcNumber )
    {
        if( NULL != pvSVCParmAdd )
        {
            svc_handler( ( svcSyscallParamType * )pvSVCParmAdd );
        }
    }
}
