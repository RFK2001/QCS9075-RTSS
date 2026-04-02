/*
  ==============================================================================
*/
/*==============================================================================
  File Name          : Gpt_Os.h
  Component Name     : MCAL Gpt module as gpt_timer RTD Module 
  Description        : This file implements the os abstraction APIs for GPT
  $Header: 
  $DateTime: 
  $Author: 
  ============================================================================*/
/*
  ==============================================================================
  
  Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
  All rights reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
   
  ==============================================================================

  $Header: 
  $DateTime:
  $Author:

  ==============================================================================
*/
/*
  ==============================================================================

  EDIT HISTORY FOR MODULE

  when       who      what, where, why
  --------   -------  ----------------------------------------------------------

  ==============================================================================
*/

#ifndef GPT_OS_H__
#define GPT_OS_H__
/*==============================================================================
**                         Include files                                      **
==============================================================================*/
#include "types.h"
#include "interrupts.h"
/*==============================================================================
**                         Type Definitions and prots.                        **
==============================================================================*/
/**
 * Definition of trigger types for interrupt registration
 */
typedef uint32 GptOs_TriggerType;

#define GptOs_TRIGGER_LEVEL (uint32)EL1_INT_CONFIG_LEVEL_TRIGGER
#define GptOs_TRIGGER_EDGE  (uint32)EL1_INT_CONFIG_EDGE_TRIGGER

/**
 *  @brief eGptOs_RegisterInterrupt: Register interrupt handler
 *  
 *  @param [in] nVectorId vector number
 *  @param [in] eTrigger  interrupt trigger type
 *  @param [in] pISR      ISR Handler
 *  @param [in] args      Handler args
 *  @return None
 *  
 *  @details None
 */
GPT_TIMER_FUNC Std_ReturnType eGptOs_RegisterInterrupt
(
    uint32 nVectorId,
    GptOs_TriggerType eTrigger,
    Gpt_EventPtrType pISR,
    void *args
);

/**
 *  @brief eGptOs_DeRegisterInterrupt: Deregister Interrupt
 *  
 *  @param [in] nVectorId vector number
 *  @param [in] nFlags unused 
 *  @return Return description
 *  
 *  @details None
 */
GPT_TIMER_FUNC Std_ReturnType eGptOs_DeRegisterInterrupt
(
    uint32 nVectorId,
    uint32 nFlags
);
#endif
/*==============================================================================
**                                      EOF                                   **
==============================================================================*/