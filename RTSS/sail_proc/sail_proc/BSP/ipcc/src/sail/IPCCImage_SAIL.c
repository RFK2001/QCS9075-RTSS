/*
===========================================================================
*/
/**
  @file IPCCImage_TZ.c

  Image specific file for the IPC Controller driver.
*/
/*
  ====================================================================

  Copyright (c) 2021-2025 Qualcomm Technologies,Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies,Inc.

  ====================================================================

  $Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/ipcc/src/sail/IPCCImage_SAIL.c#1 $
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
#include "IPCCHWIO.h"
#include "HALhwio.h"
#include "arm_acle.h"
#include "target.h"
#include "common_functions.h" 
#include "IPCC_Log.h"

/*=========================================================================
      External data
==========================================================================*/


/*=========================================================================
      Function Definitions
==========================================================================*/

IPCC_FUNC  void
IPCC_InitSubsysImageEx
(
  IPCCDrvCtxt* pDrv,
  IPCC_Protocol eProtocol,
  uint32_t   sail_client_idx
)
{
  
  uint8_t nMode;
  IPCCProtocolType* pProtocol;
  
  if ( pDrv == NULL ) 
  {
    IPCCLog_Out(1, "IPCC_InitSubsysImageEx  NULL\r\n");
    return;
  }
  
  /* Link up BSP data */
  pDrv->pBSP = &IPCCBSPData[sail_client_idx];// ToDo rrahul : update the IPCCBSP : IPCCBSPData[cpu_idx];
  
  nMode = pDrv->pBSP->bIPCCMode;

  //IPCCLog_Out(1, "IPCC_InitSubsysImageEx  (arg) NoProtocol %d mode %d BSPptr %x\r\n", pDrv->pBSP->nNumProtocols,nMode,pDrv->pBSP);

  for ( uint32_t nIdx = 0; nIdx < pDrv->pBSP->nNumProtocols; nIdx++ )
  {
    pProtocol = &pDrv->pBSP->pProtocols[nIdx];
    if ( (pProtocol->nPhysBaseAddress != 0x0u) && (pProtocol->nProtocolId == eProtocol)) 
    {
      /*
       * This one time config is done for all targets pre-wildcat for all instances of IPCC. 
       * For now, since we share a warehouse, we should set this flag in our BSP to indicate. 
       */
      if ( !(pProtocol->bSkipOneTimeConfig == 1u) )
      {
		  /* Write the mode value we expect */
        HWIO_OUTXF(pProtocol->nPhysBaseAddress, IPC_TOP_MODE, MODE, nMode);

        /* Enable Trace */
        HWIO_OUTXF(pProtocol->nPhysBaseAddress, IPC_TRACE_ENABLE, ENABLE, 1);
      }

      /* Add client offset */
      pProtocol->nVirtBaseAddress = ((uint8_t)pDrv->pBSP->eClient * ( HWIO_ADDRXI2(0, IPC_ID, 0, 1) - HWIO_ADDRXI2(0, IPC_ID, 0, 0) ) );
      /* Add protocol offset and base */
      pProtocol->nVirtBaseAddress += pProtocol->nPhysBaseAddress + pProtocol->nOffset;
      //IPCCLog_Out(1, "IPCC_InitSubsysImageEx  break\r\n");
      break;
    }
  }
}



