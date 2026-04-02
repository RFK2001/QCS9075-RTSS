/**
 * @file syscall.c
 * @brief
 * Source file for Sail HVC calls
 *
 *        Copyright (c) 2023 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*===========================================================================

                            EDIT HISTORY FOR FILE

when       who      what, where, why
--------   ---     ------------------------------------------------------------
06.02.21   rrahul       Created
=============================================================================*/


/*===========================================================================
                               INCLUDE FILES
===========================================================================*/
#include <stdlib.h>
#include <stdio.h>
#include "syscall_hvc.h"
#include "debug_log.h"
#include "syscall_pub.h"
#include "interrupts.h"
/*===========================================================================
                               VARIABLES
============================================================================*/

/*===========================================================================
								SYS CALL DECLARATION
============================================================================*/

/*
 *===========================================================================
 *								FUNCTIONS
 *===========================================================================*/

/*===========================================================================
**  Function :  hvc_call
** ==========================================================================
*/
/*!
*
* @brief
*   Incoke HVC from EL1 mode.
*
* @param
    uint32_t *cmd_id       -- HVC ID
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

SYSCALL_FUNC int hvc_call_cb(uint32_t *hvc_id, uint32_t *param_id, uint32_t *arg1, uint32_t *arg2, uint32_t *arg3, uint32_t *arg4)
{
      uint32_t d0 = 0, d1, d2, d3, d4, d5, sid;

      if( (hvc_id == NULL ) || ( param_id == NULL ) || ( arg1 == NULL ) || ( arg2 == NULL ) || ( arg3 == NULL )
               || ( arg4 == NULL ) )
      {
           return HVC_ERR_FAILURE;
      }

      /* HVC call disable the interrupt, at a time only one HVC call possible */
      d0 = *hvc_id;
      d1 = *param_id;
      d2 = *arg1;
      d3 = *arg2;
      d4 = *arg3;
      d5 = *arg4;
      //sid = 0;

      __asm__ volatile(
                        ".arch_extension sec\n"
                        "ldr r0, %4\n"
                        "ldr r1, %5\n"
                        "ldr r2, %6\n"
                        "ldr r3, %7\n"
                        "ldr r4, %8\n"
                        "ldr r5, %9\n"
                        "hvc 0x0\n"
                        "str r0, %0\n"
                        "str r1, %1\n"
                        "str r2, %2\n"
                        "str r3, %3\n"
                        : "=m"(d0), "=m"(d1), "=m"(d2), "=m"(d3)
                        : "m"(d0), "m"(d1), "m"(d2), "m"(d3), "m"(d4), "m"(d5)
                        : "r0", "r1", "r2", "r3", "r4", "r5"
                      );
  
      //LOG_INFO("smc out: 0x%x:%x:%x:%x:%x\n", d0, d1, d2, d3, sid);
  
      *param_id = d1;
      *arg1 = d2;
      *arg2 = d3;

      return d0;
}

SYSCALL_FUNC int hvc_call(uint32_t *hvc_id, uint32_t *param_id, uint32_t *arg1, uint32_t *arg2, uint32_t *arg3, uint32_t *arg4)
{
      /* Save ARM Neon Registers before implementing any C-code in SVC handler */
	SAVE_FPU_REGISTERS();

      /* Call the hvc_call_cb */
      int ret = hvc_call_cb(hvc_id, param_id, arg1, arg2, arg3, arg4);

      /* Restore ARM Neon Registers after implementing SVC handler */
	RESTORE_FPU_REGISTERS();
      
      return ret;
}


