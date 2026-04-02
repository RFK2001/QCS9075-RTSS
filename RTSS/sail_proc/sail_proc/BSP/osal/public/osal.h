
/*
===========================================================================
*/
/**
    @file  osal.h
    @brief OS abstraction layer's defines and function prototypes

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

#ifndef OSAL_H
#define OSAL_H

/*=========================================================================
      Include Files
==========================================================================*/

#include "types.h"


/*=========================================================================
      Type Definitions
==========================================================================*/

/**
 * return value
 */
typedef int32_t slOsalStatus;

#define OSAL_OK            0
#define OSAL_OK_NOT_DONE   1
#define OSAL_ERR          -1

/**
 * Opaque definition of a mutex
 */
typedef void* OsalMutex;


/**
 * Definition of Callback handler
 */
typedef void pvOsalIsrCb (void* args);

/**
 * Definition of trigger types for interrupt registration
 */
typedef enum
{
  OSAL_TRIGGER_HIGH,             // Level
  OSAL_TRIGGER_LOW,              // Level
  OSAL_TRIGGER_RISING,           // Edge
  OSAL_TRIGGER_FALLING           // Edge
} eOsalTriggerType;

typedef enum
{
  OSAL_IRQ_LEVEL_TRIGGER = 0,             // Level
  OSAL_IRQ_EDGE_TRIGGER = 1,             // edge
} eOsalIRQType;

/*=========================================================================
      Function Definitions
==========================================================================*/

/* =========================================================================
**  Function : vTsOsalInit
** =========================================================================*/
void vOsalInit(void);

/* =========================================================================
**  Function : OsOsalMutexInit
** =========================================================================*/

slOsalStatus xOsalMutexInit 
( 
  OsalMutex* pMutex 
);


/* =========================================================================
**  Function : OsOsalMutexDeinit
** =========================================================================*/

void vOsalMutexDeinit 
( 
  OsalMutex* pMutex 
);


/* =========================================================================
**  Function : OsOsalMutexLock
** =========================================================================*/

void vOsalMutexLock 
( 
  OsalMutex* pMutex 
);


/* =========================================================================
**  Function : OsOsalMutexUnlock
** =========================================================================*/

void vOsalMutexUnlock 
( 
  OsalMutex* pMutex 
);

/* =========================================================================
**  Function : OsOsalRegisterInterrupt
** =========================================================================*/

slOsalStatus xOsalRegisterInterrupt
(
  uint32_t             nInterrupt,
  eOsalTriggerType     eTrigger,
  pvOsalIsrCb          *pIsrCallback,
  uint32*              nArg
);


/* =========================================================================
**  Function : OsOsalDeregisterInterrupt
** =========================================================================*/

slOsalStatus xOsalDeregisterInterrupt
(
  uint32_t               nInterrupt
);


/* =========================================================================
**  Function : OsOsalMaskInterrupt
** =========================================================================*/

slOsalStatus vOsalMaskInterrupt
(
  uint32_t               nInterrupt
);


/* =========================================================================
**  Function : OsOsalUnmaskInterrupt
** =========================================================================*/

slOsalStatus vOsalUnmaskInterrupt
(
  uint32_t               nInterrupt
);

typedef slOsalStatus slOsalQueueInterruptCallback (uint32_t nInterrupt, void *arg);

slOsalStatus slOsalQueueInterrupt
(
   uint32_t nInterrupt,
   void *arg,
   slOsalQueueInterruptCallback * callback
);

#endif /* __OSAL_H__ */
