#ifndef IPCCRX_H__
#define IPCCRX_H__
/*
===========================================================================
*/
/**
  @file IPCCRx.h
  @brief Private interface include file for accessing the IPCC Rx
  device driver definitions.

  The IPCCRx.h file is the private API interface to the Inter-Processor 
  Communication Controller driver.
*/
/*
  ===========================================================================

  Copyright (c) 2018-2025 Qualcomm Technologies Incorporated.  
  All Rights Reserved.
  Qualcomm Proprietary and Confidential.

  ===========================================================================

  $Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/ipcc/inc/IPCC_Rx.h#1 $
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
#include "IPCC_OS.h"
#include <stdint.h>

/*=========================================================================
      Macro Declarations
==========================================================================*/

#define IPCC_NO_DATA  (0xffffffffu)

/*=========================================================================
      Interface Declarations
==========================================================================*/

/* =========================================================================
**  Function : IPCCRx_InitEx
** =========================================================================*/

void
IPCCRx_InitEx
(
   IPCCDrvCtxt* pDrv,
   IPCC_Protocol eProtocol,
   uint32_t   sail_client_idx
);

/* =========================================================================
**  Function : IPCCRx_AttachEx
** =========================================================================*/

void
IPCCRx_AttachEx
(
  IPCCClientCtxt*   pClientCtxt,
  uint32_t sail_client_id
);

/* =========================================================================
**  Function : IPCCRx_DetachEx
** =========================================================================*/

void
IPCCRx_DetachEx
(
  IPCCClientCtxt*   pClientCtxt,
  uint32_t sail_client_id
);


/* =========================================================================
**  Function : IPCCRx_RegisterInterrupt
** =========================================================================*/

IPCC_Status_t 
IPCCRx_RegisterInterrupt
(
  IPCCClientCtxt*   pClientCtxt,
  IPCC_Client       eCID, 
  IPCC_Signal       nSignalLow,
  IPCC_Signal       nSignalHigh,
  IPCC_CB           pfnCB,
  IPCC_CBData       nData
);


/* =========================================================================
**  Function : IPCCRx_DeregisterInterrupt
** =========================================================================*/

IPCC_Status_t 
IPCCRx_DeregisterInterrupt
(
  IPCCClientCtxt*   pClientCtxt,
  IPCC_Client       eCID, 
  IPCC_Signal       nSignalLow,
  IPCC_Signal       nSignalHigh
);

#endif /*__IPCCRX_H__*/
