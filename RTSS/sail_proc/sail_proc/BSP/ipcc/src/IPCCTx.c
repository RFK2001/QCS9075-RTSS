/*
===========================================================================
*/
/**
  @file IPCCTx.c

  IPC Controller driver Tx portion of the driver.
*/
/*
  ====================================================================

  Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.

  ====================================================================

  $Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/ipcc/src/IPCCTx.c#1 $
  $DateTime: 2025/02/01 11:39:23 $
  $Author: smarru $

  ====================================================================
*/


/*=========================================================================
      Include Files
==========================================================================*/
#include "IPCC.h"
#include "IPCC_Internal.h"
#include "IPCC_Tx.h"
#include "IPCC_Log.h"
#include "IPCCHWIO.h"
#include "common_functions.h"

/*=========================================================================
      Static defiintions
==========================================================================*/

static SM_APP_DATA IPCCTxDrvType TxDrv;

/*=========================================================================
      Functions
==========================================================================*/


/* =========================================================================
**  Function : IPCCTx_Init
** =========================================================================*/

IPCC_FUNC  void
IPCCTx_Init
(
   IPCCDrvCtxt* pDrv
)
{

  /*-------------------------------------------------------------------------*/

  /* Apply Tx Drv to Master Drv */
  if ( pDrv != NULL )
  {
    pDrv->pTxDrv = &TxDrv;
    //IPCCLog_Out(0, "IPCCTx Initialized Drv: %x\r\n",&TxDrv);
  }

  IPCCLog_Out(0, "IPCCTx Initialized\r\n");
}


/* =========================================================================
**  Function : IPCCTx_Trigger
** =========================================================================*/

IPCC_FUNC  IPCC_Status_t
IPCCTx_Trigger
(
  IPCCClientCtxt*   pClientCtxt,
  IPCC_Client       eCID, 
  IPCC_Signal       nSignalLow,
  IPCC_Signal       nSignalHigh
)
{
  IPCC_Protocol eProtocol;
  uint32_t nIdx, nSigEn;

  /*-------------------------------------------------------------------------*/

  if( pClientCtxt == NULL ||
      pClientCtxt->pProtocol == NULL ||
      (uint8_t)eCID >= pClientCtxt->pProtocol->nNumClients ||
      nSignalLow > nSignalHigh ||
      nSignalHigh >= pClientCtxt->pProtocol->nNumSigs )
  {
    IPCCLog_Out(3, "IPCCTx_Trigger failed (arg) for eCID %d, nSignalLow %d, nSignalHigh %d\r\n", eCID, nSignalLow, nSignalHigh);
    return IPCC_EARG;
  }

  IPCCLog_Out(3, "IPCCTx_Trigger called for eCID %d, SignalLow: %d, SignalHigh: %d\r\n", eCID, nSignalLow, nSignalHigh);

  /* Trigger outgoing interrupt */
  /* For now, trigger one-by-one, but ideally we can use Global trigger mask */
  for( nIdx = nSignalLow; nIdx <= nSignalHigh; nIdx++ )
  {
    if(HWIO_SHFT(IPC_SEND, CLIENT_ID) <= 31)
    {
      nSigEn = ( (uint32_t)eCID << HWIO_SHFT(IPC_SEND, CLIENT_ID) ) | nIdx;
      HWIO_OUTXI2(pClientCtxt->pProtocol->nVirtBaseAddress, IPC_SEND, 0, 0, nSigEn);
    }

  }

  return IPCC_EOK;
}
