/*
===========================================================================
*/
/**
  @file gpio_os.c

  gpio driver implementation for os abstraction layer.
*/
/*
  ====================================================================

  Copyright (c) 2022 Qualcomm Technologies,Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies,Inc.

  ====================================================================
*/

/*=========================================================================
      Include Files
==========================================================================*/
#include "gpio_os.h"
#include <stdlib.h>
#include "sailbsp_mutex.h"
#include "interrupts.h"
/* =========================================================================
**  Function : GPIOOS_MutexInit
** =========================================================================*/

void GPIOOS_MutexInit 
( 
  mutex_t* pMutex 
)
{
    if (pMutex != NULL) 
    {
      (void)mutex_init(pMutex);
    }

    
}

/* =========================================================================
**  Function : GPIOOS_MutexLock
** =========================================================================*/

void GPIOOS_MutexLock 
( 
  mutex_t* pMutex 
)
{
    if (pMutex != NULL) 
    {
      mutex_lock(pMutex);
    }
    
}


/* =========================================================================
**  Function : GPIOOS_MutexUnlock
** =========================================================================*/

void GPIOOS_MutexUnlock 
( 
  mutex_t* pMutex 
)
{
    if (pMutex != NULL) 
    {
      mutex_unlock(pMutex);
    }
    
}

/* =========================================================================
**  Function : GPIOOS_RegisterInterrupt
** =========================================================================*/
GPIOOS_Error GPIOOS_RegisterInterrupt
(
    uint32_t nVectorId,
    GPIOOS_TriggerType eTrigger,
    GPIOOSInterruptHandle *pISR,
    void *args
)
{
  int32_t siMaskStatus;
  int32_t siIntrHandleStatus;
  int32_t siConfgIntr;
  int32_t siUnmaskIntr;
  GPIOOS_Error eStatus = GPIOOS_ERR;

  /*Configue interrupt at interrupt controller*/
  enum InterruptConfig_t nTrigger = (enum InterruptConfig_t)eTrigger;
  siMaskStatus = xGicSetIntEnable(nVectorId, (boolean)FALSE);
  siIntrHandleStatus = xGicRegisterIntHandler(nVectorId, (InterruptHandle_t )pISR, args);
  siConfgIntr = xGicConfigureInt(nVectorId, nTrigger, NULL);
  if ((0 == siConfgIntr) && (0 == siMaskStatus) && (0 == siIntrHandleStatus))
  {
    siUnmaskIntr = xGicSetIntEnable(nVectorId, (boolean)TRUE);
    if((0 == siUnmaskIntr))
    {
      eStatus = GPIOOS_OK;
    }
  }

  return eStatus;
}

/* =========================================================================
**  Function : GPIOOS_DeRegisterInterrupt
** =========================================================================*/

GPIOOS_Error GPIOOS_DeRegisterInterrupt
(
    uint32_t nVectorId,
    uint32_t nFlags
)
{
  int32_t siMaskIntr;
  int32_t siUnRegIntr;
  GPIOOS_Error eStatus = GPIOOS_ERR;
  
  siMaskIntr = xGicSetIntEnable(nVectorId, (boolean)FALSE);
  siUnRegIntr = xGicUnRegisterIntHandler(nVectorId, nFlags);

  if((0 == siMaskIntr) && (0 == siUnRegIntr))
  {
    eStatus = GPIOOS_OK;
  }

  return eStatus;
}