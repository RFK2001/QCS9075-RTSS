#ifndef IPCCDRV_H__
#define IPCCDRV_H__
/*
===========================================================================
*/
/**
  @file IPCCDrv.h
  @brief Private interface include file for accessing the IPCC device driver.

  The IPCCDrv.h file is the private API interface to the Inter-Processor 
  Communication Controller driver.
*/
/*
  ===========================================================================

  Copyright (c) 2018-2025 Qualcomm Technologies Incorporated.  
  All Rights Reserved.
  Qualcomm Proprietary and Confidential.

  ===========================================================================

  $Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/ipcc/inc/IPCC_Drv.h#1 $
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
#include <stdint.h>


/*=========================================================================
      Interface Declarations
==========================================================================*/


/* =========================================================================
**  Function : IPCCDrv_AttachEx
** =========================================================================*/

IPCC_Status_t
IPCCDrv_AttachEx
(
  IPCC_Handle   *pH,
  IPCC_Protocol eProtocol,
  IPCC_Client   eClient,
  uint32_t      sail_client_idx
);

/* =========================================================================
**  Function : IPCCDrv_Detach
** =========================================================================*/

IPCC_Status_t
IPCCDrv_Detach
(
  IPCC_Handle *pH
);


/* =========================================================================
**  Function : IPCCDrv_RegisterInterrupt
** =========================================================================*/

IPCC_FUNC IPCC_Status_t
IPCCDrv_RegisterInterrupt
(
  IPCC_Handle       h,
  IPCC_Client       eSenderCID, 
  IPCC_Signal       nSignalLow,
  IPCC_Signal       nSignalHigh,
  IPCC_CB           pfnCB,
  IPCC_CBData       nData
);


/* =========================================================================
**  Function : IPCCDrv_DeregisterInterrupt
** =========================================================================*/

IPCC_FUNC IPCC_Status_t
IPCCDrv_DeregisterInterrupt
(
  IPCC_Handle       h,
  IPCC_Client       eSenderCID, 
  IPCC_Signal       nSignalLow,
  IPCC_Signal       nSignalHigh
);


/* =========================================================================
**  Function : IPCCDrv_Trigger
** =========================================================================*/

IPCC_FUNC IPCC_Status_t
IPCCDrv_Trigger
(
  IPCC_Handle       h,
  IPCC_Client       eTargetCID,
  IPCC_Signal       nSignalLow,
  IPCC_Signal       nSignalHigh
);

#endif /*__IPCCDRV_H__*/
