#ifndef IPCC_IMAGE_H__
#define IPCC_IMAGE_H__
/*
===========================================================================
*/
/**
  @file IPCCImage.h
  @brief Private interface include file for accessing the IPCC image specific
  device driver.

  The IPCCImage.h file is the private API interface to the Inter-Processor 
  Communication Controller driver.
*/
/*
  ===========================================================================

  Copyright (c) 2018-2025 Qualcomm Technologies Incorporated.  
  All Rights Reserved.
  Qualcomm Proprietary and Confidential.

  ===========================================================================

  $Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/ipcc/inc/IPCC_Image.h#1 $
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

#include "IPCC_Internal.h"
#include <stdint.h>




/*=========================================================================
      Interface Declarations
==========================================================================*/


/* =========================================================================
**  Function : IPCC_InitImageEx
** =========================================================================*/
/**
  Initialize the IPCC image specific portion of the driver.

  This function links up the BSP data to the driver.

  @param
  pDrv   - Pointer to driver context.
  cpu_id - client id

  @return
  None.

  @dependencies
  None.
*/

void
IPCC_InitImageEx
(
   IPCCDrvCtxt* pDrv,
   IPCC_Protocol eProtocol,
   uint32_t   sail_client_idx
);

/*=========================================================================
      Interface Declarations
==========================================================================*/

/* =========================================================================
**  Function : IPCC_InitSubsysImageEx
** =========================================================================*/
/**
  Initialize the IPCC image specific portion of the driver based on the
  subsystem.

  This function will gather subsystem specific information and/or initialize
  IPCC based on the subsystem in use.

  @param
  pDrv - Pointer to driver context.

  @return
  None.

  @dependencies
  None.
*/

void
IPCC_InitSubsysImageEx
(
   IPCCDrvCtxt* pDrv,
   IPCC_Protocol eProtocol,
   uint32_t   sail_client_idx
);

#endif /*__IPCC_IMAGE_H__*/
