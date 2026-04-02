/*
@file debug_err_fatal.c
@brief Misc. error handling routines

*/
 /*        Copyright (c) 2022-2025 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 */
 
/*===========================================================================
                              Include files
=============================================================================*/

#include "types.h"
#include "cache_ops.h"
#include "err_fatal.h"

/*===========================================================================
                              Extern
=============================================================================*/
extern void err_fatal(MODULE_ID mid,int32_t Error_ID);
extern void err_warning(sailbsp_err_fatal_e err);


/**
 * @  sailbsp_err_fatal :Api to invoke 
 */
void __attribute__((noreturn)) sailbsp_err_fatal(MODULE_ID mid,uint32_t Error_ID)
{
  err_fatal(mid,Error_ID); //function should never return.
  while(1);
}

void  sailbsp_err_warning(sailbsp_err_fatal_e err)
{
  err_warning(err);
}
