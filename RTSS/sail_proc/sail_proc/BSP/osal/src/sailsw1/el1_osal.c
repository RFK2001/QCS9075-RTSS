/*
===========================================================================
*/
/**
    @file  el1_osal.c
    @brief EL1 OSAL implementation.

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
#include <stdlib.h>
#include "sailbsp_mutex.h"
#include "FreeRTOSOsal.h"
#include "freertos_init.h"
#include "debug_log.h"
#include "interrupts.h"
/*=========================================================================
      Static definitions
==========================================================================*/


static mutex_t osal_critical_section;

#define OSAL_LOCK_MAX_NUM    20
static StaticSemaphore_t acLockBuffer[OSAL_LOCK_MAX_NUM];
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
  BaseType_t ret = pdPASS;
  SemaphoreHandle_t xMutexHandle = NULL;

  if (pMutex != NULL)
  {
    *pMutex = NULL;
     mutex_lock(&osal_critical_section);
    if ( ulOsalLockIdx < OSAL_LOCK_MAX_NUM )
    {
      OsalMutex tmp = &acLockBuffer[ulOsalLockIdx];
      if ( pdPASS == ( ret = xFreeRTOSMutexCreate (tmp, &xMutexHandle) ) )
      {
        *pMutex = (OsalMutex)xMutexHandle;
        ulOsalLockIdx++;
        slStatus = OSAL_OK;
      }
    }
    mutex_unlock(&osal_critical_section);
  }

  return slStatus;
}


/* =========================================================================
**  Function : OsOsalMutexDeinit
** =========================================================================*/

void vOsalMutexDeinit 
( 
  OsalMutex* pMutex 
)
{
  //TODO
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
    SemaphoreHandle_t xMutexHandle = ( SemaphoreHandle_t )*pMutex;
    xFreeRTOSMutexTake ( xMutexHandle, pdMS_TO_TICKS( freertosMAX_DELAY ) );
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
    SemaphoreHandle_t xMutexHandle = ( SemaphoreHandle_t )*pMutex;
    xFreeRTOSMutexGive ( xMutexHandle );
  }
}

/* =========================================================================
**  Function : OsOsalRegisterInterrupt
** =========================================================================*/

slOsalStatus xOsalRegisterInterrupt
(
  uint32_t             nInterrupt,
  eOsalTriggerType     eTrigger,
  pvOsalIsrCb          *pCB,
  uint32*              nArg
)
{
  intEl1Status_t ret = INT_EL1_SUCCESS;
  enum InterruptConfig_t nTriggerFlag = EL1_INT_CONFIG_EDGE_TRIGGER;
  
  switch( eTrigger )
  {
    case OSAL_TRIGGER_HIGH:
    case OSAL_TRIGGER_LOW:
    nTriggerFlag = EL1_INT_CONFIG_LEVEL_TRIGGER;
    break;
    case OSAL_TRIGGER_RISING:
    case OSAL_TRIGGER_FALLING:
    nTriggerFlag = EL1_INT_CONFIG_EDGE_TRIGGER;
    break;
  }

  ret = xGicSetIntEnable(nInterrupt, (boolean)FALSE);
  if ( INT_EL1_SUCCESS != ret )
  {
    return OSAL_ERR;
  }
  ret = xGicRegisterIntHandler( nInterrupt,
                              (InterruptHandle_t)pCB,
                              (void*)nArg );
  if ( INT_EL1_SUCCESS != ret )
  {
    return OSAL_ERR;
  }
  ret = xGicConfigureInt(nInterrupt, nTriggerFlag, NULL);
  if ( INT_EL1_SUCCESS != ret )
  {
    return OSAL_ERR;
  }

  ret = xGicSetIntEnable(nInterrupt, (boolean)TRUE);
    
  return (ret == INT_EL1_SUCCESS) ? OSAL_OK : OSAL_ERR;
}

/* =========================================================================
**  Function : OsOsalDeregisterInterrupt
** =========================================================================*/

slOsalStatus xOsalDeregisterInterrupt
(
  uint32_t               nInterrupt
)
{
  intEl1Status_t ret = INT_EL1_SUCCESS;

  ret = xGicSetIntEnable(nInterrupt, (boolean)FALSE);
  if ( INT_EL1_SUCCESS != ret )
  {
    return OSAL_ERR;
  }
  ret = xGicUnRegisterIntHandler(nInterrupt,(uint32_t)0U);
  if ( INT_EL1_SUCCESS != ret )
  {
    return OSAL_ERR;
  }
  
  return (ret == INT_EL1_SUCCESS) ? OSAL_OK : OSAL_ERR;
}

/* =========================================================================
**  Function : OsOsalMaskInterrupt
** =========================================================================*/

slOsalStatus vOsalMaskInterrupt
(
  uint32_t               nInterrupt
)
{
    if( pdPASS != xGicSetIntEnable(nInterrupt, (boolean)FALSE))
    {
		return OSAL_ERR;
    }
	return OSAL_OK;
}


/* =========================================================================
**  Function : OsOsalUnmaskInterrupt
** =========================================================================*/

slOsalStatus vOsalUnmaskInterrupt
(
  uint32_t               nInterrupt
)
{
	if( pdPASS != xGicSetIntEnable(nInterrupt,  (boolean)TRUE))
    {			
		return OSAL_ERR;
    }
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

