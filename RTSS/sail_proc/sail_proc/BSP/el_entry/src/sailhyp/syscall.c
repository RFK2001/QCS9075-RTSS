/**
 * @file syscall.c
 * @brief
 * Source file for Sail sysacalls
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


/*===========================================================================
                               INCLUDE FILES
===========================================================================*/
#include <stdlib.h>
#include <stdio.h>
#include "syscall.h"
#include "syscall_pub.h"
#include "errno.h"
#include "debug_log.h"
#include "types.h"
#include "target_linker_map.h"
/*===========================================================================
                               VARIABLES
============================================================================*/

/*===========================================================================
								SYS CALL DECLARATION
============================================================================*/
SAIL_DEFINE_SYSCALL(1,
                   1,
                   0,
                   sail_syscall_1);

SAIL_DEFINE_SYSCALL(2,
                   1,
                   0,
                   sail_syscall_2);
/*
 *===========================================================================
 *								FUNCTIONS
 *===========================================================================*/


uint32 syscall_handler(uint32 hvc_id) {
     
	return hvc_id * 2;
}

uint32 sail_syscall_1(uint32 arg) {
    return arg* 3;
}
uint32 sail_syscall_2(uint32 arg) {
    return arg * 4;
}


/*===========================================================================
    HVC Parser Service Functions
============================================================================*/
static uint32 loadIndirectParam(ctx_gpregs_t *ctx_p)
{

   if (SAILBSP_SYSCALL_DIRECT_PARAMS_MAX >=
          SAIL_SYSCALL_NUM_ARGS(ctx_p->param_list_id))
   {
      // no need to load indirect parameters
      return E_SUCCESS;
   }

   uint32_t *p_indirect_param = (uint32_t *)ctx_p->param3;
   ctx_p->param3 = p_indirect_param[0];
   ctx_p->param4 = p_indirect_param[1];
   ctx_p->param5 = p_indirect_param[2];
   ctx_p->param6 = p_indirect_param[3];
   ctx_p->param7 = p_indirect_param[4];

   return E_SUCCESS;
}

static uint32 hyp_do_syscall(ctx_gpregs_t                  *ctx_p,
                             sail_syscall_func_t             func,
                             uint32                         args,
                             sailbsp_hvc_rsp_t                 *rsp)
{
   uint32 ret = 0;

   SAILBSP_SET_RSP3(rsp, 0, 0, 0);

   uint32 (*func_param0)(sailbsp_hvc_rsp_t*) = func;
   uint32 (*func_param1)(register_t, sailbsp_hvc_rsp_t*) = func;
   uint32 (*func_param2)(register_t, register_t,sailbsp_hvc_rsp_t*) = func;
   uint32 (*func_param3)(register_t, register_t, register_t,sailbsp_hvc_rsp_t*) = func;
   uint32 (*func_param4)(register_t, register_t, register_t, register_t,sailbsp_hvc_rsp_t*) = func;
   uint32 (*func_param5)(register_t, register_t, register_t, register_t, register_t,sailbsp_hvc_rsp_t*) = func;
   uint32 (*func_param6)(register_t, register_t, register_t, register_t, register_t, register_t,sailbsp_hvc_rsp_t*) = func;
   uint32 (*func_param7)(register_t, register_t, register_t, register_t, register_t, register_t, register_t, sailbsp_hvc_rsp_t*) = func;

   /* SAIL HVC SYSCALL supports up to 7 arguments (optional: ptr to +3 rsp parameters) */
   switch (args)
   {
   case 0:
      ret = func_param0(rsp);
      break;

   case 1:
      ret = func_param1(ctx_p->param0, rsp);
      break;

   case 2:
      ret = func_param2(ctx_p->param0, ctx_p->param1, rsp);
      break;

   case 3:
      ret = func_param3(ctx_p->param0, ctx_p->param1, ctx_p->param2, rsp);
      break;

   case 4:
      ret = func_param4(ctx_p->param0, ctx_p->param1, ctx_p->param2, ctx_p->param3, rsp);
      break;

   case 5:
      ret = func_param5(ctx_p->param0, ctx_p->param1, ctx_p->param2,
                 ctx_p->param3, ctx_p->param4, rsp);
      break;

   case 6:
      ret = func_param6(ctx_p->param0, ctx_p->param1, ctx_p->param2,
                 ctx_p->param3, ctx_p->param4, ctx_p->param5,
                 rsp);
      break;

   case 7:
      ret = func_param7(ctx_p->param0, ctx_p->param1, ctx_p->param2,
                 ctx_p->param3, ctx_p->param4, ctx_p->param5,
                 ctx_p->param6, rsp);
      break;


   default:
      ret = -1;
   }

   return ret;
}



sail_syscall_entry_t* sailbsp_syscall_lookup(uint32 hvc_id)
{
   sail_syscall_entry_t *cur = NULL;
   sail_syscall_entry_t *start = NULL;
   sail_syscall_entry_t *end = NULL;
   uint32 i = 0;
   uint32 owner_id_mask = SAIL_MASK_BITS(29, 24);
   uint32 func_id_mask  = SAIL_MASK_BITS(15, 0);
   uint32 app_id_mask   = SAIL_MASK_BITS(15, 8);

   /* We only want Owner ID and Function ID */
   hvc_id &= owner_id_mask | func_id_mask;

   start = (sail_syscall_entry_t *)SYSCALL_TABLE_START;
   cur = start;
   end = (sail_syscall_entry_t *)SYSCALL_TABLE_END;
   
   
   while ((uint32)cur < (uint32)end)
   {
      if (hvc_id == cur->hvc_id)
      {
         /* Some syscall registered for more args then they can handle */
         if (SAIL_SYSCALL_NUM_ARGS(cur->param_id) > SAILBSP_SYSCALL_MAX_ARG ) return NULL;
   
         return cur;
      }
      cur++;
   }
  
   return NULL;
}

uint32 sailhyp_hvc_handler(ctx_reg_t *ctx_p, uint32 caller_mode, hvc_result_t *res_p)
{
   uint32 nargs = 0, int_flags = 0;
   uint32 hvc_id = 0, param_id = 0;
   uint32 i = 0;
   uint32 retval = 0;
   sail_syscall_entry_t *sc_entry = NULL;
   ctx_gpregs_t *in;
   ctx_gpregs_t local_in = {0};


   if (NULL == ctx_p)
   {
      return E_HVC_DONE_PROCESSING;
   }

   if ((ELF_EI_CLASS_32 != caller_mode))
   {
      LOG_ERROR("HVC caller_mode unknowon\n");
   }

   in = &ctx_p->in;

   //memscpy(&local_in, sizeof(ctx_gpregs_t), in, sizeof(ctx_gpregs_t));
   memcpy(&local_in,in, sizeof(ctx_gpregs_t));

   /* HVC function ID is in r0 */
   hvc_id = (uint32)(in->func_id & 0xFFFFFFFFULL);
   /* Param ID is in r1 */
   param_id = (uint32)(in->param_list_id & 0xFFFFFFFFULL);

   /*
   retval = sailbsp_validate_hvc_id(hvc_id);
   if (HVC_SUCCESS != retval)
   {
      res_p->ret = retval;
      return E_HVC_DONE_PROCESSING;
   }
   */

   /* Check for the correct function */
   if (SAILBSP_SYSCALL_AARCH32 == SAIL_SYSCALL_AARCH(hvc_id))
   {
      in->param0 &= 0xFFFFFFFFULL;
      in->param1 &= 0xFFFFFFFFULL;
      in->param2 &= 0xFFFFFFFFULL;
      in->param3 &= 0xFFFFFFFFULL;
   }

   sc_entry = sailbsp_syscall_lookup(hvc_id);

   if (sc_entry == NULL)
   {
      res_p->ret = HVC_ERR_UNKNOWN_HVC_ID;
      return E_HVC_DONE_PROCESSING;
   }

   nargs = SAIL_SYSCALL_NUM_ARGS(sc_entry->param_id);
   /* Some syscall registered for more args then they can handle */
   if (nargs > SAILBSP_SYSCALL_MAX_ARG)
   {
      res_p->ret = HVC_ERR_SYSCALL_NOT_AVAILABLE;
      return E_HVC_DONE_PROCESSING;
   }

   if (SAIL_SYSCALL_NUM_ARGS(param_id) != nargs)
   {
      res_p->ret = HVC_ERR_NUM_ARGS_MISMATCH;
      return E_HVC_DONE_PROCESSING;
   }

   if (param_id != sc_entry->param_id)
   {
      res_p->ret = HVC_ERR_PARAM_ID_MISMATCH;
      return E_HVC_DONE_PROCESSING;
   }

   /* Check for indirect parameter list when there are more than 4 function args
   * (we only have 4 regs for parameters in ARMv8 smc interface) */
   if (nargs > 4)
   {
      retval = loadIndirectParam(&local_in);

      if(retval != E_SUCCESS)
      {
        res_p->ret = retval;
        return E_HVC_DONE_PROCESSING;
      }
   }

   /* Now we have what we need */
   retval = hyp_do_syscall(&local_in, (sail_syscall_func_t)sc_entry->func, nargs, &res_p->rsp);

   res_p->ret = retval;

   return E_HVC_DONE_PROCESSING;
}
