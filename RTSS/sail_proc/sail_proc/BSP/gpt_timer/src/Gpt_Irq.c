/*
  ==============================================================================
*/
/*==============================================================================
  File Name          : Gpt_Irq.c
  Component Name     : MCAL Gpt module as gpt_timer RTD Module 
  Description        : AutoSAR R 24-11
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
**                              Include files                                 **
==============================================================================*/
#include "HALhwio.h"
    /*@[SWS_Gpt_00261] : Gpt_Irq.c shall include Gpt.h for the prototype declaration
        of the notification functions. (SRS_BSW_00164)*/
#include "Gpt.h"
#include "Gpt_Prv.h"
#include "Gpt_Irq.h"
#include "Gpt_PBcfg.h"
#include "debug_log.h"

/*==============================================================================
**                              Private ISR Notifications Prots.              **
==============================================================================*/
#if (GPT_DEV_ERROR_DETECT == STD_ON)
GPT_TIMER_FUNC void Gpt_ReportError(const uint8 Gpt_Serviceid, const uint8 Gpt_ErrorId);
#endif
GPT_TIMER_FUNC static void Gpt_ISRHandler_CB(const Gpt_ChannelType Channel, Gpt_ModuleCoreDataType *pGpt_ModuleCoreData);
/*==============================================================================
**                              Private ISR Notifications                     **
==============================================================================*/
GPT_TIMER_FUNC static void Gpt_ISRHandler_CB(const Gpt_ChannelType Channel, Gpt_ModuleCoreDataType *pGpt_ModuleCoreData)
{
    Gpt_ChannelType Gpt_ChannelConfigIndex = 0U;
    if( NULL == pGpt_ModuleCoreData ) { 
        #if(GPT_DEV_ERROR_DETECT == STD_ON)
        Gpt_ReportError(GPT_SERVICE_ID_IRQ_EVENT, GPT_E_PARAM_POINTER);
        #endif
        while(1) {
            ; /* trap if not handled by integrator */
        }
    }
    /* channels is valid */
    for (Gpt_ChannelConfigIndex = 0U; Gpt_ChannelConfigIndex< pGpt_ModuleCoreData->pGpt_ModuleConfig->GptDrvChannelMaxConfig ; Gpt_ChannelConfigIndex++)
	{
		if (pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChannelID == Channel)
		{
            break;
		}
	}
    /* invalid channel */
    if( Gpt_ChannelConfigIndex >= pGpt_ModuleCoreData->pGpt_ModuleConfig->GptDrvChannelMaxConfig )
    {   
        #if(GPT_DEV_ERROR_DETECT == STD_ON)
        Gpt_ReportError(GPT_SERVICE_ID_IRQ_EVENT, GPT_E_PARAM_POINTER);
        #endif
        while(1) {
            ; /* trap if not handled by integrator */
        }
    }
    /* channel expired */
    if(pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChannelMode == GPT_CH_MODE_ONESHOT)
    {
        /* mask timer */
        GptPrv_DisableTimer(Channel, pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChanHW);
        pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptChannelState = GPT_CHANNEL_EXPIRED;
    }
    else /* continueous */
    {
        /* mask timer */
        GptPrv_DisableTimer(Channel, pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChanHW);
        /* load compare counter */
        pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptStopValueInHwTicks =   \
        GptPrv_SetCounterValue( Channel, \
                                (const Gpt_ChanHWType) pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChanHW, \
                                pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptTargetTimeInHwTicks,   \
                                &(pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptStartValueInHWTicks));
        /* unmask timer */
        GptPrv_EnableTimer(Channel, pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChanHW); 
    }
    #if (GPT_ENABLE_DISABLE_NOTIFICATION_API == STD_ON)
    if( (STD_ON == pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptChannelCbkEn) \
    		&& ( NULL_PTR != pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptNotification))
    {
    	pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptNotification();
    }
    #endif
    /* ECU State manager Wakeup notfiy */
    #if (GPT_WAKEUP_FUNCTIONALITY_API == STD_ON)
    #if (GPT_REPORT_WAKEUP_SOURCE == STD_ON)   
    if( ( pGpt_ModuleCoreData->GptDrvMode == GPT_MODE_SLEEP ) && \
        ( pGpt_ModuleCoreData->Gpt_ChannelCoreData[Gpt_ChannelConfigIndex].GptEnableWakeup == STD_ON ) )
    {
        /* ECM Wakeup handle through cfg stub in *cfg.h for BSP RTD and wakeup source value configured by 
            configurator tool b0-b5 reserved for standard RESETS/Wakeups other bx assigned to each wakeup sources 
        later on activation call to Gpt_CheckWakeup()=> void EcuM_SetWakeupEvent(EcuM_WakeupSourceType sources) */  
        EcuM_CheckWakeup( pGpt_ModuleCoreData->pGpt_ChannelConfig[Gpt_ChannelConfigIndex].GptChannelWakeupInfo );
    }
    #endif
    #endif
    return;  
}
/*==============================================================================
**                      Private ISR Notification Wrapper API                  **
==============================================================================*/
GPT_TIMER_FUNC static void Gpt_ISRHandler( const Gpt_ChannelType Channel, Gpt_ModuleCoreDataType *LpGpt_ModuleCoreData )
{
    /* EL2/Freertos ISR handles FPU registers save/restore. */
	/* Calls the ISR_CB function */
    Gpt_ISRHandler_CB(Channel, LpGpt_ModuleCoreData);
    return;
}
/*==============================================================================
**                              Private ISR Notifications                    **
==============================================================================*/
GPT_TIMER_FUNC void Gpt_Notification_Default(void)
{
    /* default */
   // __asm__ volatile( "nop\n\t");
   DEBUG_LOG(SAIL_WARNING," Gpt_Notification_Default called\n\r");
    return;
}

GPT_TIMER_FUNC static void Gpt_TimerIrq0ISR(void *args)
{
    Gpt_ISRHandler(0U, args);
    return;
}

GPT_TIMER_FUNC static void Gpt_TimerIrq1ISR(void *args)
{
    Gpt_ISRHandler(1U, args);
    return;
}

GPT_TIMER_FUNC static void Gpt_TimerIrq2ISR(void *args)
{
    Gpt_ISRHandler(2U, args);
    return;
}

GPT_TIMER_FUNC static void Gpt_TimerIrq3ISR(void *args)
{
    Gpt_ISRHandler(3U, args);
    return;
}

GPT_TIMER_FUNC static void Gpt_TimerIrq4ISR(void *args)
{
    Gpt_ISRHandler(4U, args);
    return;
}

GPT_TIMER_FUNC static void Gpt_TimerIrq5ISR(void *args)
{
    Gpt_ISRHandler(5U, args);
    return;
}

GPT_TIMER_FUNC static void Gpt_TimerIrq6ISR(void *args)
{
    Gpt_ISRHandler(6U, args);
    return;
}

GPT_TIMER_FUNC static void Gpt_TimerIrq7ISR(void *args)
{
    Gpt_ISRHandler(7U, args);
    return;
}

GPT_TIMER_FUNC static void Gpt_TimerIrq8ISR(void *args)
{
    Gpt_ISRHandler(8U, args);
    return;
}

GPT_TIMER_FUNC static void Gpt_TimerIrq9ISR(void *args)
{
    Gpt_ISRHandler(9U, args);
    return;
}

GPT_TIMER_FUNC static void Gpt_TimerIrq10ISR(void *args)
{
    Gpt_ISRHandler(10U, args);
    return;
}

GPT_TIMER_FUNC static void Gpt_TimerIrq11ISR(void *args)
{
    Gpt_ISRHandler(11U, args);
    return;
}


GPT_TIMER_FUNC static void Gpt_TimerIrq12ISR(void *args)
{
    Gpt_ISRHandler(12, args);
    return;
}

GPT_TIMER_FUNC static void Gpt_TimerIrq13ISR(void *args)
{
    Gpt_ISRHandler(13, args);
    return;
}

GPT_TIMER_FUNC static void Gpt_TimerIrq14ISR(void *args)
{
    Gpt_ISRHandler(14, args);
    return;
}

/**
 *  @brief prvQTimerGetISR - provides ISR handle
 *  
 *  @param [in] timerId timer HW channel Interface IDn
 *  @return Returns ISR Handle

 *  
 *  @details None
 */
GPT_TIMER_FUNC Gpt_EventPtrType prvQTimerGetISR(const Gpt_ChannelType timerId)
{
    Gpt_EventPtrType lIntrHandle = NULL;
    switch(timerId)
    {
        case 0U:
            lIntrHandle = Gpt_TimerIrq0ISR;
        break;
        case 1U:
            lIntrHandle = Gpt_TimerIrq1ISR;
        break;
        case 2U:
            lIntrHandle = Gpt_TimerIrq2ISR;
        break;
        case 3U:
            lIntrHandle = Gpt_TimerIrq3ISR;
        break;
        case 4U:
            lIntrHandle = Gpt_TimerIrq4ISR;
        break;
        case 5U:
            lIntrHandle = Gpt_TimerIrq5ISR;
        break;
        case 6U:
            lIntrHandle = Gpt_TimerIrq6ISR;
        break;
        case 7U:
            lIntrHandle = Gpt_TimerIrq7ISR;
        break;
        case 8U:
            lIntrHandle = Gpt_TimerIrq8ISR;
        break;
        case 9U:
            lIntrHandle = Gpt_TimerIrq9ISR;
        break;
        case 10U:
            lIntrHandle = Gpt_TimerIrq10ISR;
        break;
        case 11U:
            lIntrHandle = Gpt_TimerIrq11ISR;
        break;
        case 12U:
            lIntrHandle = Gpt_TimerIrq12ISR;
        break;
        case 13U:
            lIntrHandle = Gpt_TimerIrq13ISR;
        break;
        case 14U:
            lIntrHandle = Gpt_TimerIrq14ISR;
        break;
        default:
            ; /* do nothing */
        break;
    }
    return lIntrHandle;
}
/*==============================================================================
**                    End of file Gpt_Irq.c                                   **
==============================================================================*/
