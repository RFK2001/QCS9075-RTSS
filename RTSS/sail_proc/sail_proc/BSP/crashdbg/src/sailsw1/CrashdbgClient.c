/*
==============================================================================

FILE: CrashdbgClient.c

DESCRIPTION:
  Crashdbg driver System Call ( SW1/EL1 ) module interface.

==============================================================================

$Header: $

==============================================================================
Copyright (c) 2022 QUALCOMM Technologies Incorporated.
All Rights Reserved.
QUALCOMM Proprietary/GTDR
==============================================================================

*/

/*=========================================================================
      Include Files
==========================================================================*/

#include "stdbool.h"
#include "stdint.h"
#include "types.h"
#include "syscall_hvc.h"
#include "syscall_pub.h"
#include "Crashdbg_api.h"
#include "Crashdbg.h"
#include "err_fatal.h"

/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
==========================================================================================================*/
#define CRASHDBG_FUNC  __attribute__ ( ( section ( "crashdbg_func" ) ) )

/*=========================================================================
      Top-Level Functions
==========================================================================*/

/* =========================================================================
**  Function : Crashdbg_disable
** =========================================================================*/
/**
  This function disables crash debug feature and mask/unmask SAIL_CC MD_PS_HOLD_MASK, based on request.

  @return
  DBG_FAILED -- Crashdbg disable or mask/unmask SAIL_CC MD_PS_HOLD_MASK failure
  DBG_DISABLED -- Crashdbg disable and/or mask SAIL_CC MD_PS_HOLD_MASK success
  DBG_SUCCESS -- Unmask SAIL_CC MD_PS_HOLD_MASK success

  @dependencies
  None.
*/
CRASHDBG_FUNC Crashdbg_Result Crashdbg_disable
(
  Crashdbg_CtrlType_e ctrl_type
)
{
  uint32 ulResult = DBG_SUCCESS;
  uint32_t hvcId     = CRASHDBG_DISDBG_HVC_ID;
  uint32_t paramId   = CRASHDBG_DISDBG_PARAM_ID;
  uint32_t arg1      = ctrl_type;
  uint32_t arg2      = 0;
  uint32_t arg3      = 0;
  uint32_t arg4      = 0;

  if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
  {
	  err_fatal(CRASHDBG, ERR_FATAL_HVC_CALL_FAILED);
  }

  /*NOTE: parameter id will return with rsp->data[0], Crashdbg result */
  ulResult = paramId;

  return ulResult;
}

