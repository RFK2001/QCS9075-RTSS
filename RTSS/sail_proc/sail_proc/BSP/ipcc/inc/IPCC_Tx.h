#ifndef IPCCTX_H__
#define IPCCTX_H__
/*
===========================================================================
*/
/**
  @file IPCCTx.h
  @brief Private interface include file for accessing the IPCC Tx
  device driver definitions.

  The IPCCTx.h file is the private API interface to the Inter-Processor 
  Communication Controller driver.
*/
/*
  ===========================================================================

  Copyright (c) 2018-2025 Qualcomm Technologies Incorporated.  
  All Rights Reserved.
  Qualcomm Proprietary and Confidential.

  ===========================================================================

  $Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/ipcc/inc/IPCC_Tx.h#1 $
  $DateTime: 2025/02/01 11:39:23 $
  $Author: smarru $

  when       who     what, where, why
  --------   ---     ---------------------------------------------------------- 
  05/18/18   cp      Initial revision.

  ===========================================================================
*/


/*=========================================================================
      Include Files
==========================================================================*/

#include "IPCC.h"
#include "IPCC_Internal.h"
#include <stdint.h>

/*=========================================================================
      Interface Declarations
==========================================================================*/


/* =========================================================================
**  Function : IPCCTx_Init
** =========================================================================*/

void IPCCTx_Init(IPCCDrvCtxt* pDrv);


/* =========================================================================
**  Function : IPCCTx_Attach
** =========================================================================*/

void
IPCCTx_Attach
(
  IPCCTxDrvInfoType**  ppTxDrv
);

/* =========================================================================
**  Function : IPCCTx_Detach
** =========================================================================*/

void
IPCCTx_Detach
(
  IPCCTxDrvInfoType**  ppTxDrv
);

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
);

#endif /*__IPCCTX_H__*/
