#ifndef GPIO_OS_H
#define GPIO_OS_H

/*
===========================================================================
*/
/**
  @file gpio_os.h
  @brief Private interface include file for gpio internal os abstraction layer.
*/
/*
  ===========================================================================

  Copyright (c) 2022 Qualcomm Technologies Incorporated.  
  All Rights Reserved.
  Qualcomm Proprietary and Confidential.

  ===========================================================================
*/

#include "types.h"
#include "sailbsp_mutex.h"
/*=========================================================================
      Type Definitions
==========================================================================*/

/**
 * Deifinition of Mutex 
 */
typedef void* GPIOOSMutex;

/**
 * Definition of an Interrupt Driver handle
 */
typedef void GPIOOSInterruptHandle(void *callback_func );

/**
 * Definition of trigger types for interrupt registration
 */
typedef enum
{
  GPIOOS_TRIGGER_LEVEL,
  GPIOOS_TRIGGER_EDGE,
  GPIOOS_MAX
}
GPIOOS_TriggerType;

/**
 * Definition of error types
 * 
 */
typedef enum
{
    GPIOOS_ERR,
    GPIOOS_OK
}GPIOOS_Error;
/*=========================================================================
      Function Definitions
==========================================================================*/

/* =========================================================================
**  Function : GPIOOS_MutexInit
** =========================================================================*/

extern void GPIOOS_MutexInit ( mutex_t* pMutex );


/* =========================================================================
**  Function : GPIOOS_MutexDeinit
** =========================================================================*/

extern void GPIOOS_MutexDeinit ( mutex_t* pMutex );


/* =========================================================================
**  Function : GPIOOS_MutexLock
** =========================================================================*/

extern void GPIOOS_MutexLock ( mutex_t* pMutex );


/* =========================================================================
**  Function : GPIOOS_MutexUnlock
** =========================================================================*/

extern void GPIOOS_MutexUnlock ( mutex_t* pMutex );

/* =========================================================================
**  Function : GPIOOS_RegisterInterrupt
** =========================================================================*/

extern GPIOOS_Error GPIOOS_RegisterInterrupt
(
    uint32_t nVectorId,
    GPIOOS_TriggerType eTrigger,
    GPIOOSInterruptHandle *pISR,
    void *args
);

/* =========================================================================
**  Function : GPIOOS_DeRegisterInterrupt
** =========================================================================*/

extern GPIOOS_Error GPIOOS_DeRegisterInterrupt
(
    uint32_t nVectorId,
    uint32_t nFlags
);

#endif
