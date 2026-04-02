#ifndef ISD_OS_H
#define ISD_OS_H

/*
===========================================================================
*/
/**
  @file isd_os.h
  @brief Private interface include file for isd internal os abstraction layer.
*/
/*
  ===========================================================================

  Copyright (c) 2022 Qualcomm Technologies Incorporated.  
  All Rights Reserved.
  Qualcomm Proprietary and Confidential.

  ===========================================================================
*/

#include "types.h"

/*=========================================================================
      Type Definitions
==========================================================================*/
/**
 * Deifinition of Mutex 
 */
typedef void* ISDOSMutex;

/**
 * Definition of an Interrupt Driver handle
 */
typedef void ISDOS_InterruptHandle(void * arg);

/**
 * Definition of trigger types for interrupt registration
 */
typedef enum
{
  ISDOS_TRIGGER_LEVEL=0,
  ISDOS_TRIGGER_EDGE,
  ISDOS_MAX
}
ISDOS_TriggerType;

/*=========================================================================
      Function Definitions
==========================================================================*/

/* =========================================================================
**  Function : vISDOS_MutexInit
** =========================================================================*/

void 
vISDOS_MutexInit 
( 
  ISDOSMutex* pMutex 
);

/* =========================================================================
**  Function : vISDOS_MutexLock
** =========================================================================*/

void 
vISDOS_MutexLock 
( 
  ISDOSMutex* pMutex 
);


/* =========================================================================
**  Function : vISDOS_MutexUnlock
** =========================================================================*/

void 
vISDOS_MutexUnlock 
( 
  ISDOSMutex* pMutex 
);

/* =========================================================================
**  Function : eISDOS_RegisterInterrupt
** =========================================================================*/

isdResultsType_e 
eISDOS_RegisterInterrupt
(
    uint32_t nVectorId,
    ISDOS_TriggerType eTrigger,
    ISDOS_InterruptHandle *pISR,
    void *args
);

/* =========================================================================
**  Function : eISDOS_DeRegisterInterrupt
** =========================================================================*/

isdResultsType_e 
eISDOS_DeRegisterInterrupt
(
    uint32_t nVectorId,
    uint32_t nFlags
);

#endif