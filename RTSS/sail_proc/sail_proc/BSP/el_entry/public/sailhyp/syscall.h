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
                           DEFINES
===========================================================================*/
#define ELF_EI_CLASS_32   1
#define ELF_EI_CLASS_64   2

/** Maximum number of system call arguments. */
#define SAILBSP_SYSCALL_MAX_ARG                     7

#define SAILBSP_SYSCALL_INDIRECT_PARAMS_MAX         4
#define SAILBSP_SYSCALL_DIRECT_PARAMS_MAX           4

#define SAILBSP_SYSCALL_PARAM_TYPE_VAL              0x0
#define SAILBSP_SYSCALL_PARAM_TYPE_BUF_RO           0x1
#define SAILBSP_SYSCALL_PARAM_TYPE_BUF_RW           0x2
#define SAILBSP_SYSCALL_PARAM_TYPE_BUF_VALIDATION   0x3

#define SAILBSP_SYSCALL_AARCH32                     0x0
#define SAILBSP_SYSCALL_AARCH64                     0x1

#define SAILBSP_SYSCALL_IRQS_ENABLED                0x0
#define SAILBSP_SYSCALL_IRQS_DISABLED               0x1

#define IS_INVALID_RSP_PTR(rsp_ptr) (NULL == rsp_ptr)


#define SAILBSP_SET_RSP(rsp_ptr, rsp0, rsp1, rsp2) \
  do { \
    if (!rsp_ptr) break; \
    ((sailbsp_hvc_rsp_t *)rsp_ptr)->data[0] = (uintnt) rsp0; \
    ((sailbsp_hvc_rsp_t *)rsp_ptr)->data[1] = (uintnt) rsp1; \
    ((sailbsp_hvc_rsp_t *)rsp_ptr)->data[2] = (uintnt) rsp2; \
  } while (0)

/*
 * Helper macros for setting sailbsp_smc_rsp_t*
 */
#define SAILBSP_SET_RSP1(rsp_ptr, rsp0) \
  SAILBSP_SET_RSP(rsp_ptr, rsp0, 0, 0)
#define SAILBSP_SET_RSP2(rsp_ptr, rsp0, rsp1) \
  SAILBSP_SET_RSP(rsp_ptr, rsp0, rsp1, 0)
#define SAILBSP_SET_RSP3(rsp_ptr, rsp0, rsp1, rsp2) \
  SAILBSP_SET_RSP(rsp_ptr, rsp0, rsp1, rsp2)

#define SAILBSP_SET_RSPI(rsp_ptr, idx, rspval) \
  do { \
    if (!rsp_ptr || idx>=3 || idx<0) break; \
    rsp_ptr->rsp[idx] = (uint32)rspval; \
  } while (0)

/** Syscall definition flags */
#define SAIL_SC_FLAG_RSP                0x00000001 /* Syscall populates rsp          */
#define SAIL_SC_FLAG_ENABLE_INT         0x00000002 /* Enable IRQs during syscall     */
#define SAIL_SC_FLAG_NON_COPY_RETURN    0x00000004 /* Appsbl mode switch flag        */
#define SAIL_SC_FLAG_LEGACY_API         0x00000008 /* Legacy API bypasses validation */
#define SAIL_SC_FLAG_O_RSP_ON_ERR       0x00000010 /* Overwrite Response on error    */
#define SAIL_SC_FLAG_USE_CRYPTO         0x00000020
#define SAIL_SC_FLAG_FLUSH_RW_BUF       0x00000040
#define SAIL_SC_FLAG_TEE_API            0x00000080 /* TEE API bypasses params id use */
//#define SAIL_SC_FLAG_HYP_SMC_CALL     0x00000100 /* Do not use anymore             */
#define SAIL_SC_FLAG_MC_CALL            0x00000200 /* Syscall can be handled in idle
                                                    thread by multiple cores
													concurrently                   */

/* Make no distinction between Register Class and Control Class
   syscalls */
#define SAIL_SC_FLAG_SHARED_SYSCALL     SAIL_SC_FLAG_O_RSP_ON_ERR

/** Sycall Client ID */
#define ARM_NS_AVMID_HYP     			0    // defined in ARM SMC Spec for W7-client guest  tracking

#define ARM_ARCH_SERVICE_START_32       0x80000000
#define ARM_ARCH_SERVICE_END_32         0x8000FFFF

#define ARM_ARCH_SERVICE_START_64       0xC0000000
#define ARM_ARCH_SERVICE_END_64         0xC000FFFF

#define SMCCC_ARCH_WORKAROUND_REQ 		0x0          //ToDo Do we need this

#define SMCCC_ARCH_WORKAROUND_NOT_REQ 	0x1			 //ToDo Do we need this

/* Put all system calls in a specific memory section */
#define SAIL_DEFINE_SYSCALL(hvc_id, param_id, flags, func) \
  extern uint32 func (); \
  static sail_syscall_entry_t sail_syscall_entry_ ##func \
  __attribute__((section("_sail_syscall"),used)) = \
  { 0, hvc_id, param_id, flags, func }


/*===========================================================================
                           TYPES and TYPEDEFS
===========================================================================*/
typedef enum smc_processing_status_e {
  E_HVC_DONE_PROCESSING = 0,
  E_HVC_CONT_PROCESSING = 1
} hvc_processing_status_enum;

/* Size: 0x30 */
typedef struct ctx_gpregs_t_s {
      register_t func_id;
      register_t param_list_id;
      register_t param0;
      register_t param1;
      register_t param2;
      register_t param3;
      register_t session_id;   //Do we need this if we dont support irq in hvc
      register_t hyp_client_id;
      register_t param4;
      register_t param5;
      register_t param6;
      register_t param7;
} ctx_gpregs_t;


/* Size: 0x20 */
typedef struct ctx_x8_x14_s
{
	  register_t x8, x9, x10, x11;
	  register_t x12, x13, x14, reserved;
} ctx_x8_x14_t;

/* Size: 0x10 */
typedef struct ctx_x4_x7_s
{
  register_t x4, x5, x6, x7;
} ctx_x4_x7_t;

/* Size: 0x60 */
typedef struct ctx_reg_s
{
   /* Size: 0x20 */
	ctx_x8_x14_t   unchanged_callee_saved;

   /* Size: 0x10 */
   ctx_x4_x7_t    param_callee_saved;

   /* Size: 0x30 */
   ctx_gpregs_t    in;
} ctx_reg_t;

typedef struct sailbsp_hvc_result_s {
  uint32 data[3];
} sailbsp_hvc_rsp_t;

typedef struct hvc_result_t_s {
  register_t     ret;
  sailbsp_hvc_rsp_t rsp;
  register_t     sp;
  register_t     reserved;
} hvc_result_t;


#ifndef SAILBSP_SYSCALL_FUNC_T
#define SAILBSP_SYSCALL_FUNC_T
typedef uint32 (*sail_syscall_func_t)();
#endif


typedef struct sail_syscall_entry_s
{
  uint32 reserved;             ///< service_id in sail_syscall_entry_t
  uint32 hvc_id;               ///< owner id and command id of the function to be called
  uint32 param_id;             ///< # of args and their types defined by function definition
  uint32 flags;                ///< flags for special syscall handling
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




#endif  
