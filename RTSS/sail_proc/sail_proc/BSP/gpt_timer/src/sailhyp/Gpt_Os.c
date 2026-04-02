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
#include "interrupts.h"
#include "debug_log.h"
#include "err.h"

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
    Std_ReturnType Ret = E_OK;
    status_t status = mask_interrupt(nVectorId);
    if(NO_ERROR != status)
    {
        Ret = E_NOT_OK;
    }
    status = register_int_handler(nVectorId, (int_handler )pISR, args);
    if(NO_ERROR != status)
    {
        Ret = E_NOT_OK;
    }
    status = configure_interrupt(nVectorId, (enum intr_config)eTrigger, args);
    if(NO_ERROR != status)
    {
        Ret = E_NOT_OK;
    }
    status = unmask_interrupt(nVectorId);
    if(NO_ERROR != status)
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
    status_t status = mask_interrupt(nVectorId);
    if(NO_ERROR != status)
    {
        Ret = E_NOT_OK;
    }
    else
    {
        status = unregister_int_handler(nVectorId, nFlags);
        if(NO_ERROR != status)
        {
            Ret = E_NOT_OK;
        }
    }
    return Ret;
}