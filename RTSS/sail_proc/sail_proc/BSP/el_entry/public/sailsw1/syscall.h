/**
 * @file syscall.h
 * @brief Sail definitions
 * Header file for the definition of Sail HVC calls
 *
 *        Copyright (c) 2021 Qualcomm Technologies, Inc.
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

#ifndef SYSCALL_H
#define SYSCALL_H

/*===========================================================================
                           INCLUDE FILES
===========================================================================*/
#include<stdio.h>
#include<stdlib.h>
#include "types.h"

/*===========================================================================
                           TYPES and TYPEDEFS
===========================================================================*/


#define SAILBSP_SYSCALL_MAX_ARG                     7

#define SAILBSP_SYSCALL_INDIRECT_PARAMS_MAX         4
#define SAILBSP_SYSCALL_DIRECT_PARAMS_MAX           4

#define SAILBSP_SET_RSP(rsp_ptr, rsp0, rsp1, rsp2) \
  do { \
    if (!rsp_ptr) break; \
    ((sailbsp_hvc_rsp_t *)rsp_ptr)->data[0] = (uintnt) rsp0; \
    ((sailbsp_hvc_rsp_t *)rsp_ptr)->data[1] = (uintnt) rsp1; \
    ((sailbsp_hvc_rsp_t *)rsp_ptr)->data[2] = (uintnt) rsp2; \
  } while (0)

#define SAILBSP_SET_RSP3(rsp_ptr, rsp0, rsp1, rsp2) \
  SAILBSP_SET_RSP(rsp_ptr, rsp0, rsp1, rsp2)



typedef struct sailbsp_hvc_result_s {
  uint32 data[3];
} sailbsp_svc_rsp_t;

typedef struct hvc_result_t_s {
  register_t        ret;
  sailbsp_svc_rsp_t rsp;
} svc_result_t;

typedef struct
{
    register_t func_id;
    register_t param_list_id;
    register_t param0;
    register_t param1;
    register_t param2;
    register_t param3;
    register_t param4;
    register_t param5;
    register_t param6;
    register_t param7;
    svc_result_t res_p;
}svcSyscallParamType;

typedef uint32 (*sail_syscall_func_t)();

typedef struct sail_syscall_entry_s
{
  uint32 reserved;            ///< service_id in sail_syscall_entry_t
  uint32 svc_id;              ///< owner id and command id of the function to be called
  uint32 param_id;            ///< # of args and their types defined by function definition
  uint32 flags;               ///< flags for special syscall handling
  sail_syscall_func_t func;    ///< Syscall function
} sail_syscall_entry_t;

/*===========================================================================
                           EXTERNS
===========================================================================*/
extern uint32 Image$$syscall_table$$Base;
extern uint32 Image$$syscall_table$$Length;

/*===========================================================================
                           MACROS
===========================================================================*/
/* Put all system calls in a specific memory section */
#define SAIL_DEFINE_SYSCALL(svc_id, param_id, flags, func) \
  extern uint32 func (); \
  static sail_syscall_entry_t sail_syscall_entry_ ##func \
  __attribute__((section("_sail_syscall"),used)) = \
  { 0, svc_id, param_id, flags, func }


extern int svc_call(uint32_t *svc_id, uint32_t *param_id, uint32_t *arg1, uint32_t *arg2, uint32_t *arg3, uint32_t *arg4);
void svc_handler( svcSyscallParamType *pxSvcParam);

#endif  
