/*
===========================================================================
*/
/**
  @file IPCCImage.c

  IPC Controller common image driver code.
*/
/*
  ====================================================================

  Copyright (c) 2018-2025 Qualcomm Technologies Incorporated.
  All Rights Reserved.
  QUALCOMM Proprietary and Confidential.

  ====================================================================

  $Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/ipcc/src/IPCCImage.c#1 $
  $DateTime: 2025/02/01 11:39:23 $
  $Author: smarru $

  ====================================================================
*/


/*=========================================================================
      Include Files
==========================================================================*/
#include "IPCC.h"
#include "IPCC_Internal.h"
#include "IPCC_Image.h"
#include "common_functions.h"
#include "IPCC_Log.h"
/*=========================================================================
      External data
==========================================================================*/


/* =========================================================================
**  Function : IPCC_InitImageEx
** =========================================================================*/
/**
  Initialize the IPCC image specific portion of the driver.

  This function links up the BSP data to the driver.

  @param
  None.

  @return
  None.

  @dependencies
  None.
*/

IPCC_FUNC void
IPCC_InitImageEx
(
  IPCCDrvCtxt* pDrv,
  IPCC_Protocol eProtocol,
  uint32_t   sail_client_idx
)
{
  /* We should never hit this, but do it just incase */
  if ( pDrv != NULL ) 
  {
    IPCCLog_Out(1, "IPCC_InitImageEx  (arg) Protocol %d client %d driver %x\r\n", eProtocol,sail_client_idx,pDrv);
    /* Init subsystem */
    IPCC_InitSubsysImageEx(pDrv, eProtocol, sail_client_idx);
  }


}


