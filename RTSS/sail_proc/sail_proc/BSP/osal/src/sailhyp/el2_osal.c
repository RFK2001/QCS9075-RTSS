/*
===========================================================================
*/
/**
    @file  el2_osal.c
    @brief EL2 OSAL implementation.

*/
/*
    ===========================================================================

    Copyright (c) 2022 Qualcomm Technologies, Inc.
    All Rights Reserved.
    Confidential and Proprietary - Qualcomm Technologies, Inc.

    Export of this technology or software is regulated by the U.S. Government.
    Diversion contrary to U.S. law prohibited.

    All ideas, data and information contained in or disclosed by
    this document are confidential and proprietary information of
    Qualcomm Technologies, Inc. and all rights therein are expressly reserved.
    By accepting this material the recipient agrees that this material
    and the information contained therein are held in confidence and in
    trust and will not be used, copied, reproduced in whole or in part,
    nor its contents revealed in any manner to others without the express
    written permission of Qualcomm Technologies, Inc.

    ===========================================================================

    $Header: $
    $DateTime: $
    $Author: $

    ===========================================================================
*/


/*=========================================================================
      Include Files
==========================================================================*/
#include "osal.h"
#include "sailbsp_mutex.h"
#include "interrupts.h"
#include "debug_log.h"

/*=========================================================================
      Static definitions
==========================================================================*/

static mutex_t osal_critical_section;

#define OSAL_LOCK_MAX_NUM    10
static mutex_t acLockBuffer[OSAL_LOCK_MAX_NUM];
static uint32_t ulOsalLockIdx;
/*=========================================================================
      Functions
==========================================================================*/

void vOsalInit(void)
{
    uint64 ulRet;
    ulRet = mutex_init(&osal_critical_section); /* Non-zero ulRet means it is running multiple thread mode */
    memset(acLockBuffer, 0, sizeof(acLockBuffer));
    ulOsalLockIdx = 0;
}

/* =========================================================================
**  Function : OsOsalMutexInit
** =========================================================================*/

slOsalStatus xOsalMutexInit 
( 
  OsalMutex* pMutex 
)
{
  slOsalStatus slStatus = OSAL_ERR;
  if (pMutex != NULL)
  {
	  *pMutex = NULL;
    mutex_lock(&osal_critical_section);
	  if ( ulOsalLockIdx < OSAL_LOCK_MAX_NUM )
	  {
	    
      OsalMutex tmp = &acLockBuffer[ulOsalLockIdx];
	    *pMutex = tmp;
	    mutex_init(tmp);
		  ulOsalLockIdx++;
	  }
	  mutex_unlock(&osal_critical_section);
   }
 return (pMutex != NULL && *pMutex != NULL) ? OSAL_OK : OSAL_ERR;
}


/* =========================================================================
**  Function : OsOsalMutexDeinit
** =========================================================================*/

void vOsalMutexDeinit 
( 
  OsalMutex* pMutex 
)
{
  /* no deinit needed */
}


/* =========================================================================
**  Function : OsOsalMutexLock
** =========================================================================*/

void vOsalMutexLock 
( 
  OsalMutex* pMutex 
)
{
  if( pMutex != NULL && *pMutex != NULL )
  {
    mutex_lock(*pMutex);
  }
}

/* =========================================================================
**  Function : OsOsalMutexUnlock
** =========================================================================*/

void vOsalMutexUnlock 
( 
  OsalMutex* pMutex 
)

{
  if( pMutex != NULL && *pMutex != NULL )
  {
    mutex_unlock(*pMutex);

  }
}

/* =========================================================================
**  Function : OsOsalRegisterInterrupt
** =========================================================================*/

slOsalStatus xOsalRegisterInterrupt
(
  uint32_t             nInterrupt,
  eOsalTriggerType     eTrigger,
  pvOsalIsrCb          *pIsrCallback,
  uint32*              nArg
)
{
  int ret = 0;
    uint32_t nTriggerFlag = INT_CONFIG_LEVEL_TRIGGER ;
  
    switch( eTrigger )
    {
      case OSAL_TRIGGER_HIGH:
      case OSAL_TRIGGER_LOW:
        nTriggerFlag = INT_CONFIG_LEVEL_TRIGGER;
        break;
      case OSAL_TRIGGER_RISING:
      case OSAL_TRIGGER_FALLING:
        nTriggerFlag = INT_CONFIG_EDGE_TRIGGER;
        break;
    }
    ret = (int)configure_interrupt(nInterrupt,   nTriggerFlag , 0U);
    if ( 0 != ret )
    {
      return ret;
    }
    ret = (int)register_int_handler( nInterrupt,
                                (int_handler)pIsrCallback,
                                (void*)nArg ) ;
      if ( 0 != ret )
    {
      return ret;
    }
    unmask_interrupt (nInterrupt);
      
    return (ret == 0) ? OSAL_OK : OSAL_ERR;
}

/* =========================================================================
**  Function : OsOsalDeregisterInterrupt
** =========================================================================*/

slOsalStatus xOsalDeregisterInterrupt
(
  uint32_t nInterrupt
)
{
  int ret;
  mask_interrupt (nInterrupt);
  ret = (int)unregister_int_handler( nInterrupt, 0 );

  return (ret == 0) ? OSAL_OK : OSAL_ERR;
}

/* =========================================================================
**  Function : OsOsalMaskInterrupt
** =========================================================================*/

slOsalStatus vOsalMaskInterrupt
(
  uint32_t nInterrupt
)
{
  mask_interrupt (nInterrupt);
  return OSAL_OK;
}


/* =========================================================================
**  Function : OsOsalUnmaskInterrupt
** =========================================================================*/

slOsalStatus vOsalUnmaskInterrupt
(
  uint32_t nInterrupt
)
{
  unmask_interrupt (nInterrupt);
  return OSAL_OK;
}

/* =========================================================================
**  Function : vTsOsalQueueInterrupt
** =========================================================================*/
slOsalStatus slOsalQueueInterrupt
(
   uint32_t nInterrupt,
   void *arg,
   slOsalQueueInterruptCallback callback
)
{
    return (callback) (nInterrupt, arg);
}

