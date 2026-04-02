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
#include "debug_log.h"

/* =========================================================================
**  Function : GPIOOS_MutexInit
** =========================================================================*/

void GPIOOS_MutexInit ( mutex_t* pMutex )
{
    if (pMutex != NULL) 
    {
      (void)mutex_init(pMutex);
    }

}

/* =========================================================================
**  Function : GPIOOS_MutexLock
** =========================================================================*/

void GPIOOS_MutexLock ( mutex_t* pMutex )
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
  enum intr_config nTrigger;
  int32_t siMaskStatus;
  int32_t siIntrHandleStatus;
  int32_t siConfgIntr;
  int32_t siUnmaskIntr;
  GPIOOS_Error eReturnStatus = GPIOOS_ERR;

  nTrigger = (enum intr_config)eTrigger;
  siMaskStatus = mask_interrupt(nVectorId);
  siIntrHandleStatus = register_int_handler(nVectorId, (int_handler )pISR, args);
  siConfgIntr = configure_interrupt(nVectorId, nTrigger, args);
  if ((0 == siConfgIntr) && (0 == siMaskStatus) && (0 == siIntrHandleStatus))
  {
    siUnmaskIntr = unmask_interrupt(nVectorId);
    if((0 == siUnmaskIntr))
    {
      eReturnStatus = GPIOOS_OK;
    }
  }
    return eReturnStatus;
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
  GPIOOS_Error eReturnStatus = GPIOOS_ERR;
  siMaskIntr = mask_interrupt(nVectorId);
  siUnRegIntr = unregister_int_handler(nVectorId, nFlags);

  if((0 == siMaskIntr) && (0 ==siUnRegIntr))
  {
    eReturnStatus = GPIOOS_OK;
  }
    return eReturnStatus;
}
