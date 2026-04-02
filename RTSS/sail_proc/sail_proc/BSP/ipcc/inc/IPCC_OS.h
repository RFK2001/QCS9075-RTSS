#ifndef IPCC_OS_H__
#define IPCC_OS_H__
/*
===========================================================================
*/
/**
  @file IPCC_OS.h
  @brief Private interface include file for accessing the IPCC internal
  Operating system abstraction layer.
*/
/*
  ===========================================================================

  Copyright (c) 2018-2025 Qualcomm Technologies Incorporated.  
  All Rights Reserved.
  Qualcomm Proprietary and Confidential.

  ===========================================================================

  $Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/ipcc/inc/IPCC_OS.h#1 $
  $DateTime: 2025/02/01 11:39:23 $
  $Author: smarru $

  when       who     what, where, why
  --------   ---     ---------------------------------------------------------- 
  07/28/18   cp      Initial revision.

  ===========================================================================
*/


/*=========================================================================
      Include Files
==========================================================================*/

#include "IPCC.h"
#include "types.h"
#include <stdint.h>


/*=========================================================================
      Type Definitions
==========================================================================*/

/**
 * Opaque definition of a mutex
 */
typedef void* IPCCOSMutex;


/**
 * Opaque definition of an Interrupt Driver handle
 */
typedef void* IPCCOSInterruptHandle;

/**
 * Definition of Callback handler
 */
typedef void (*IPCCOSCB) (void* arg);

/**
 * Definition of trigger types for interrupt registration
 */
typedef enum
{
  IPCCOS_TRIGGER_HIGH,
  IPCCOS_TRIGGER_LOW,
  IPCCOS_TRIGGER_RISING,
  IPCCOS_TRIGGER_FALLING
}
IPCCOS_TriggerType;

/*=========================================================================
      Function Definitions
==========================================================================*/

/* =========================================================================
**  Function : IPCCOS_MutexInit
** =========================================================================*/

void 
IPCCOS_MutexInit 
( 
  IPCCOSMutex* pMutex 
);


/* =========================================================================
**  Function : IPCCOS_MutexDeinit
** =========================================================================*/

void 
IPCCOS_MutexDeinit 
( 
  IPCCOSMutex* pMutex 
);


/* =========================================================================
**  Function : IPCCOS_MutexLock
** =========================================================================*/

void 
IPCCOS_MutexLock 
( 
  IPCCOSMutex* pMutex 
);


/* =========================================================================
**  Function : IPCCOS_MutexUnlock
** =========================================================================*/

void 
IPCCOS_MutexUnlock 
( 
  IPCCOSMutex* pMutex 
);

/* =========================================================================
**  Function : IPCCOS_RegisterInterruptEx
** =========================================================================*/

IPCC_Status_t
IPCCOS_RegisterInterruptEx
(
  IPCCOSInterruptHandle* phInterrupt,
  uint32_t               nInterrupt,
  uint32_t               buImage,
  IPCCOS_TriggerType     eTrigger,
  IPCCOSCB               pCB,
  void*                  nArg,
  uint32_t                  clientId
);

/* =========================================================================
**  Function : IPCCOS_DeregisterInterrupt
** =========================================================================*/

IPCC_Status_t
IPCCOS_DeregisterInterrupt
(
  IPCCOSInterruptHandle* phInterrupt,
  uint32_t               nInterrupt
);


/* =========================================================================
**  Function : IPCCOS_ErrFatal
** =========================================================================*/

void
IPCCOS_ErrFatal
(
  const char* pszMsg,
  uintptr_t   arg0,
  uintptr_t   arg1,
  uintptr_t   arg2
);


/* =========================================================================
**  Function : IPCCOS_Malloc
** =========================================================================*/

void*
IPCCOS_Malloc
(
   uintptr_t nSize
);


/* =========================================================================
**  Function : IPCCOS_Free
** =========================================================================*/

void
IPCCOS_Free
(
   void* p
);

#endif /*__IPCC_OS_H__*/
