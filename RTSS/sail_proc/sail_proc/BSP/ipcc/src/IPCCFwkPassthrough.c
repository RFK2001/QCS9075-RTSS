/*
===========================================================================
*/
/**
  @file IPCCFwkPassthrough.c

  Framework passthrough for the IPC Controller driver.
*/
/*
  ====================================================================

  Copyright (c) 2018-2025 Qualcomm Technologies Incorporated.
  All Rights Reserved.
  QUALCOMM Proprietary and Confidential.

  ====================================================================

  $Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/ipcc/src/IPCCFwkPassthrough.c#1 $
  $DateTime: 2025/02/01 11:39:23 $
  $Author: smarru $

  ====================================================================
*/


/*=========================================================================
      Include Files
==========================================================================*/
#include "IPCC.h"
#include "IPCC_Drv.h"


/*=========================================================================
      Functions
==========================================================================*/

/* =========================================================================
**  Function : IPCC_AttachEx
** =========================================================================*/

IPCC_FUNC IPCC_Status_t
IPCC_AttachEx
(
  IPCC_Handle   *pH,
  IPCC_Protocol eProtocol,
  IPCC_Client   eClient,
  uint32_t      sail_client_idx
)
{
  return IPCCDrv_AttachEx(pH,eProtocol,eClient,sail_client_idx);
}


/* =========================================================================
**  Function : IPCC_Detach
** =========================================================================*/

IPCC_FUNC IPCC_Status_t IPCC_Detach(IPCC_Handle *pH)
{
  return IPCCDrv_Detach(pH);
}


/* =========================================================================
**  Function : IPCC_RegisterInterrupt
** =========================================================================*/

IPCC_FUNC IPCC_Status_t
IPCC_RegisterInterrupt
(
  IPCC_Handle       h,
  IPCC_Client       eCID, 
  IPCC_Signal       nSignalLow,
  IPCC_Signal       nSignalHigh,
  IPCC_CB           pfnCB,
  IPCC_CBData       nData
)
{
  return IPCCDrv_RegisterInterrupt(h,eCID,nSignalLow,nSignalHigh,pfnCB,nData);
}


/* =========================================================================
**  Function : IPCC_DeregisterInterrupt
** =========================================================================*/

IPCC_FUNC IPCC_Status_t
IPCC_DeregisterInterrupt
(
  IPCC_Handle       h,
  IPCC_Client       eCID, 
  IPCC_Signal       nSignalLow,
  IPCC_Signal       nSignalHigh
)
{
  return IPCCDrv_DeregisterInterrupt(h,eCID,nSignalLow,nSignalHigh);
}


/* =========================================================================
**  Function : IPCC_Trigger
** =========================================================================*/

IPCC_FUNC IPCC_Status_t
IPCC_Trigger
(
  IPCC_Handle       h,
  IPCC_Client       eClient,
  IPCC_Signal       nSignalLow,
  IPCC_Signal       nSignalHigh
)
{
  return IPCCDrv_Trigger(h,eClient,nSignalLow,nSignalHigh);
}


