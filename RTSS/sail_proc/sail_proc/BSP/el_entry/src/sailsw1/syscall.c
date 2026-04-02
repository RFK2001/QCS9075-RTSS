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
#include "target_linker_map.h"

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
    SVC Parser Service Functions
============================================================================*/
SYSCALL_FUNC static uint32 loadIndirectParam(svcSyscallParamType *ctx_p)
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

SYSCALL_FUNC sail_syscall_entry_t* sailbsp_syscall_lookup(uint32 svc_id)
{
   sail_syscall_entry_t *cur   = NULL;
   sail_syscall_entry_t *start = NULL;
   sail_syscall_entry_t *end   = NULL;
   uint32 i = 0;
   uint32 owner_id_mask = SAIL_MASK_BITS(29, 24);
   uint32 func_id_mask  = SAIL_MASK_BITS(15, 0);
   uint32 app_id_mask   = SAIL_MASK_BITS(15, 8);

   /* We only want Owner ID and Function ID */
   svc_id &= owner_id_mask | func_id_mask;

   start = (sail_syscall_entry_t *)SYSCALL_TABLE_START;
   cur   = start;
   end   = (sail_syscall_entry_t *)SYSCALL_TABLE_END;


   while ( ( uint32 )cur < ( uint32 )end )
   {
      if (svc_id == cur->svc_id)
      {
         /* Some syscall registered for more args then they can handle */
         if (SAIL_SYSCALL_NUM_ARGS(cur->param_id) > SAILBSP_SYSCALL_MAX_ARG )
         {
             return NULL;
         }
         return cur;
      }
      cur++;
   }

   return NULL;
}

SYSCALL_FUNC static uint32 svc_do_syscall(svcSyscallParamType             *ctx_p,
                                          sail_syscall_func_t             func,
                                          uint32                          args,
                                          sailbsp_svc_rsp_t               *rsp)
{
    uint32 ret = 0;
    uint32 (*func_param0)(sailbsp_svc_rsp_t*) = func;
    uint32 (*func_param1)(register_t, sailbsp_svc_rsp_t*) = func;
    uint32 (*func_param2)(register_t, register_t,sailbsp_svc_rsp_t*) = func;
    uint32 (*func_param3)(register_t, register_t, register_t,sailbsp_svc_rsp_t*) = func;
    uint32 (*func_param4)(register_t, register_t, register_t, register_t,sailbsp_svc_rsp_t*) = func;
    uint32 (*func_param5)(register_t, register_t, register_t, register_t, register_t,sailbsp_svc_rsp_t*) = func;
    uint32 (*func_param6)(register_t, register_t, register_t, register_t, register_t, register_t,sailbsp_svc_rsp_t*) = func;
    uint32 (*func_param7)(register_t, register_t, register_t, register_t, register_t, register_t, register_t, sailbsp_svc_rsp_t*) = func;

    /* SAIL SVC SYSCALL supports up to 7 arguments (optional: ptr to +3 rsp parameters) */
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
        break;
    }

    return ret;
}


SYSCALL_FUNC void svc_handler( svcSyscallParamType *pxSvcParam)
{
    uint32                svc_id    = 0;
    uint32                param_id  = 0;
    sail_syscall_entry_t *sc_entry  = NULL;
    uint32                nargs     = 0;
    uint32                retval    = 0;

    svc_id   = (uint32)(pxSvcParam->func_id & 0xFFFFFFFFULL);       /* SVC function ID */

    param_id = (uint32)(pxSvcParam->param_list_id & 0xFFFFFFFFULL); /* Param ID*/

    pxSvcParam->param0 &= 0xFFFFFFFFULL;
    pxSvcParam->param1 &= 0xFFFFFFFFULL;
    pxSvcParam->param2 &= 0xFFFFFFFFULL;
    pxSvcParam->param3 &= 0xFFFFFFFFULL;

    sc_entry = sailbsp_syscall_lookup(svc_id);

    if (sc_entry == NULL)
    {
        pxSvcParam->res_p.ret = SVC_ERR_UNKNOWN_SVC_ID;
    }

    nargs = SAIL_SYSCALL_NUM_ARGS(sc_entry->param_id);
    /* Some syscall registered for more args then they can handle */
    if (nargs > SAILBSP_SYSCALL_MAX_ARG)
    {
        pxSvcParam->res_p.ret = SVC_ERR_SYSCALL_NOT_AVAILABLE;
    }

    if (SAIL_SYSCALL_NUM_ARGS(param_id) != nargs)
    {
        pxSvcParam->res_p.ret = SVC_ERR_NUM_ARGS_MISMATCH;
    }

    if (param_id != sc_entry->param_id)
    {
        pxSvcParam->res_p.ret = SVC_ERR_PARAM_ID_MISMATCH;
    }

    /* Check for indirect parameter list when there are more than 4 function args
    * (we only have 4 regs for parameters in ARMv8 smc interface) */
    if (nargs > 4)
    {
       retval = loadIndirectParam(pxSvcParam);

       if(retval != E_SUCCESS)
       {
           pxSvcParam->res_p.ret = retval;
       }
    }

    /* Now we have what we need */
    retval = svc_do_syscall(pxSvcParam, (sail_syscall_func_t)sc_entry->func, nargs, &pxSvcParam->res_p.rsp);

    pxSvcParam->res_p.ret = retval;
}
