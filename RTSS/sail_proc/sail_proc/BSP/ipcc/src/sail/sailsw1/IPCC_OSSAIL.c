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

  $Header: //components/rel/bsp.sail/1.0/ipcc/src/sail/IPCC_OSSAIL.c#2 $
  $DateTime: 2021/11/17 10:35:58 $
  $Author: pwbldsvc $

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
#include "common_functions.h"
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

IPCC_FUNC  void
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

IPCC_FUNC  void
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

IPCC_FUNC  void
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

IPCC_FUNC  void
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
IPCC_FUNC  IPCC_Status_t
IPCCOS_RegisterInterruptEx
(
  IPCCOSInterruptHandle* phInterrupt,
  uint32_t               nInterrupt,
  uint32_t               buImage,
  IPCCOS_TriggerType     eTrigger,
  IPCCOSCB               pCB,
  void*                  nArg,
  uint32_t                  clientId
)
{

  IPCC_Status_t status1 = IPCC_EOK;
  IPCC_Status_t status2 = IPCC_EOK;
  IPCC_Status_t status = IPCC_EGENERR;

  {
    enum InterruptConfig_t nTriggerFlag = EL1_INT_CONFIG_EDGE_TRIGGER;// = TZBSP_INTF_TRIGGER_EDGE; 

     switch( eTrigger )
    {
      case IPCCOS_TRIGGER_HIGH:
      case IPCCOS_TRIGGER_LOW:
        nTriggerFlag = EL1_INT_CONFIG_LEVEL_TRIGGER;
        break;
      case IPCCOS_TRIGGER_RISING:
      case IPCCOS_TRIGGER_FALLING:
        nTriggerFlag = EL1_INT_CONFIG_EDGE_TRIGGER;
        break;

        default:
        // do nothing
        break;
    }

    ;
    /* Register for Interrupt through DALInterruptController */
    (void)xGicSetIntEnable(nInterrupt, (boolean)FALSE);
    if ( 0 != xGicConfigureInt(nInterrupt,   nTriggerFlag , NULL) )
    {
      return IPCC_EINUSE;//ToDO change to right error return code.
    }
    (void)xGicRegisterIntHandler( nInterrupt,
                                  (InterruptHandle_t)pCB,
                                  (void*)nArg ) ;
    (void)xGicSetIntEnable(nInterrupt, (boolean)TRUE);
    status = IPCC_EOK;
  }
 
  return status;
}

/* =========================================================================
**  Function : IPCCOS_DeregisterInterrupt
** =========================================================================*/

IPCC_FUNC  IPCC_Status_t
IPCCOS_DeregisterInterrupt
(
  IPCCOSInterruptHandle* phInterrupt,
  uint32_t               nInterrupt
)
{
  IPCC_Status_t status1 = IPCC_EOK;
  IPCC_Status_t status2 = IPCC_EOK;
  IPCC_Status_t status = IPCC_EGENERR;


  /* Unregister for Rx Interrupt */
  {
    /* Unregister for Rx Interrupt */
    (void)xGicSetIntEnable(nInterrupt, (boolean)FALSE);
    (void)xGicUnRegisterIntHandler( nInterrupt, (uint32_t)0U );
    status = IPCC_EOK;
  }

  return status;
}

/* =========================================================================
**  Function : IPCCOS_ErrFatal
** =========================================================================*/

IPCC_FUNC  void
IPCCOS_ErrFatal
(
  const char* pszMsg,
  uintptr_t   arg0,
  uintptr_t   arg1,
  uintptr_t   arg2
)
{
  //LOG_ERROR("TZBSP_ERR_FATAL_IPCC");
}

/* =========================================================================
**  Function : IPCCOS_Malloc
** =========================================================================*/

IPCC_FUNC  void*
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

IPCC_FUNC  void
IPCCOS_Free
(
   void* p
)
{
  sailheap_free(p);
}

