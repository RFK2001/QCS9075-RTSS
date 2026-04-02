/*
===========================================================================
*/
/**
  @file IPCCOS_tz.c

  IPC Controller driver Operating system abstraction for TZ.
*/
/*
  ====================================================================

  Copyright (c) 2021 Qualcomm Technologies,Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies,Inc.

  ====================================================================

  $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/ipcc/src/sail/sailhyp/IPCC_OSSAIL.c#1 $
  $DateTime: 2025/07/09 22:36:30 $
  $Author: rmunibyr $

  ====================================================================
*/


/*=========================================================================
      Include Files
==========================================================================*/
#include "IPCC_Internal.h"
#include "IPCC_OS.h"
#include <stdlib.h>
#include "sailbsp_mutex.h"
#include "interrupts.h"
#include "debug_log.h"
#include "sailheap.h"

/*=========================================================================
      Static definitions
==========================================================================*/



/*=========================================================================
      Functions
==========================================================================*/

/* =========================================================================
**  Function : IPCCOS_MutexInit
** =========================================================================*/

void 
IPCCOS_MutexInit 
( 
  IPCCOSMutex* pMutex 
)
{
  if( pMutex == NULL ) 
  {
    return;
  }

  *pMutex = ( void* ) IPCCOS_Malloc ( sizeof( mutex_t ) );
  if( *pMutex != NULL )
  {
    (void)mutex_init((mutex_t*)*pMutex);
  }
}


/* =========================================================================
**  Function : IPCCOS_MutexDeinit
** =========================================================================*/

void 
IPCCOS_MutexDeinit 
( 
  IPCCOSMutex* pMutex 
)
{
  if( pMutex == NULL ) 
  {
    return;
  }

  if( *pMutex != NULL )
  {
    IPCCOS_Free(*pMutex);
    *pMutex = NULL;
  }
}

/* =========================================================================
**  Function : IPCCOS_MutexLock
** =========================================================================*/

void 
IPCCOS_MutexLock 
( 
  IPCCOSMutex* pMutex 
)
{
  if( pMutex != NULL && *pMutex != NULL )
  {
    mutex_lock((mutex_t*)*pMutex);
  }
}


/* =========================================================================
**  Function : IPCCOS_MutexUnlock
** =========================================================================*/

void 
IPCCOS_MutexUnlock 
( 
  IPCCOSMutex* pMutex 
)
{
  if( pMutex != NULL && *pMutex != NULL )
  {
    mutex_unlock((mutex_t*)*pMutex);
  }
}

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
  uint32_t               clientId
)
{
  enum intr_config nTriggerFlag = INT_CONFIG_EDGE_TRIGGER;// = TZBSP_INTF_TRIGGER_EDGE; 

  switch( eTrigger )
  {
    case IPCCOS_TRIGGER_HIGH:
    case IPCCOS_TRIGGER_LOW:
      nTriggerFlag = INT_CONFIG_LEVEL_TRIGGER;
      break;
    case IPCCOS_TRIGGER_RISING:
    case IPCCOS_TRIGGER_FALLING:
      nTriggerFlag = INT_CONFIG_EDGE_TRIGGER;
      break;

      default:
      // do nothing
      break;
  }

  ;
  /* Register for Interrupt through DALInterruptController */
  if ( 0 != configure_interrupt(nInterrupt,   nTriggerFlag , NULL) )
  {
    return IPCC_EINUSE;//ToDO change to right error return code.
  }
  (void)register_int_handler( nInterrupt,
                                (int_handler)pCB,
                                (void*)nArg ) ;
  arm_gic_update_routing(nInterrupt, clientId);
  (void)unmask_interrupt (nInterrupt);
  return IPCC_EOK;
}


/* =========================================================================
**  Function : IPCCOS_DeregisterInterrupt
** =========================================================================*/

IPCC_Status_t
IPCCOS_DeregisterInterrupt
(
  IPCCOSInterruptHandle* phInterrupt,
  uint32_t               nInterrupt
)
{
  /* Unregister for Rx Interrupt */
  (void)mask_interrupt (nInterrupt);
  (void)unregister_int_handler( nInterrupt, 0 );

  return IPCC_EOK;
}

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
)
{
  LOG_ERROR("TZBSP_ERR_FATAL_IPCC");
}

/* =========================================================================
**  Function : IPCCOS_Malloc
** =========================================================================*/

void*
IPCCOS_Malloc
(
   uintptr_t nSize
)
{
  return sailheap_malloc(nSize);
}


/* =========================================================================
**  Function : IPCCOS_Free
** =========================================================================*/

void
IPCCOS_Free
(
   void* p
)
{
  sailheap_free(p);
}

