/*
  ==============================================================================
*/
/*==============================================================================
  File Name          : Gpt_Os.c
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
/*==============================================================================
**                         Include files                                      **
==============================================================================*/
#include "Gpt.h"
#include "Gpt_Os.h"
#include <stdlib.h>
#include "debug_log.h"
#include "interrupts.h"

/**
 *  @brief eGptOs_RegisterInterrupt: Register interrupt handler
 *  
 *  @param [in] nVectorId vector number
 *  @param [in] eTrigger  interrupt trigger type
 *  @param [in] pISR      ISR Handler
 *  @param [in] args      Handler args
 *  @return method status
 *  
 *  @details None
 */
GPT_TIMER_FUNC Std_ReturnType eGptOs_RegisterInterrupt
(
    uint32 nVectorId,
    GptOs_TriggerType eTrigger,
    Gpt_EventPtrType pISR,
    void *args
)
{
  /*Configue interrupt at interrupt controller*/
  Std_ReturnType Ret = E_OK;
  intEl1Status_t status = xGicSetIntEnable(nVectorId, (boolean)FALSE);
  if(INT_EL1_SUCCESS != status)
  {
    Ret = E_NOT_OK;
  }
  status = xGicRegisterIntHandler(nVectorId, (InterruptHandle_t)pISR, args);
  if(INT_EL1_SUCCESS != status)
  {
    Ret = E_NOT_OK;
  }
  status = xGicConfigureInt(nVectorId, (enum InterruptConfig_t)eTrigger, args);
  if(INT_EL1_SUCCESS != status)
  {
    Ret = E_NOT_OK;
  }
  status = xGicSetIntEnable(nVectorId, (boolean)TRUE);
  if(INT_EL1_SUCCESS != status)
  {
    Ret = E_NOT_OK;
  }
  return Ret;
}

/**
 *  @brief eGptOs_DeRegisterInterrupt: Deregister Interrupt
 *  
 *  @param [in] nVectorId vector number
 *  @param [in] nFlags unused 
 *  @return Return method status
 *  
 *  @details None
 */
GPT_TIMER_FUNC Std_ReturnType eGptOs_DeRegisterInterrupt
(
    uint32 nVectorId,
    uint32 nFlags
)
{
  Std_ReturnType Ret = E_OK;
  intEl1Status_t status = xGicSetIntEnable(nVectorId, (boolean)FALSE);
  if(INT_EL1_SUCCESS != status)
  {
    Ret = E_NOT_OK;
  }
  else
  {
    status = xGicUnRegisterIntHandler(nVectorId, nFlags);
    if(INT_EL1_SUCCESS != status)
    {
      Ret = E_NOT_OK;
    }
  }
  return Ret;
}
/*==============================================================================
**                                  EOF                                       **
==============================================================================*/
