/*
===========================================================================
*/
/**
    @file  FreeRTOSOsal.c
    @brief OS Application layer for FreeRTOS kernel Functions

*/
/*
    ===========================================================================

    FreeRTOS Kernel V11.0.1
    Copyright (C) 2021 Amazon.com, Inc. or its affiliates.  All Rights Reserved.

    SPDX-License-Identifier: MIT

    Permission is hereby granted, free of charge, to any person obtaining a copy of
    this software and associated documentation files (the "Software"), to deal in
    the Software without restriction, including without limitation the rights to
    use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
    the Software, and to permit persons to whom the Software is furnished to do so,
    subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
    FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
    COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
    IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
    CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

    https://www.FreeRTOS.org
    https://github.com/FreeRTOS
    
    ===========================================================================

    Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
    All rights reserved.
    Confidential and Proprietary - Qualcomm Technologies, Inc.

    ===========================================================================

    $Header:   $
    $DateTime:  $
    $Author:   $

    ===========================================================================
*/

/*=================================================================================================
**                                        Include files                                          **
=================================================================================================*/
#include "FreeRTOSOsal.h"

/*=================================================================================================
**                                          Functions                                            **
=================================================================================================*/

/*==============================================================
** Scheduler
==============================================================*/
void vFreeRTOSTaskSuspendAll( void )
{
    ( void ) vTaskSuspendAll();
}
/*-----------------------------------------------------------*/

BaseType_t xFreeRTOSTaskResumeAll( void )
{
    return ( BaseType_t ) xTaskResumeAll();
}
/*-----------------------------------------------------------*/

BaseType_t xFreeRTOSTaskGetSchedulerState( void )
{
    /* return Scheduler State: 
     *    taskSCHEDULER_NOT_STARTED/taskSCHEDULER_RUNNING/taskSCHEDULER_SUSPENDED
     */
    return ( BaseType_t ) xTaskGetSchedulerState();
}

/*==============================================================
** Tasks
==============================================================*/

BaseType_t xFreeRTOSTaskCreate( const TaskParams_t * const pxTaskDefinition,
                                              TaskHandle_t *pxTaskHandle )
{
    *pxTaskHandle = xTaskCreateStatic(  pxTaskDefinition->pvTaskCode,
                                        pxTaskDefinition->pcName,
                                        pxTaskDefinition->usStackDepth,
                                        pxTaskDefinition->pvParameters,
                                        pxTaskDefinition->uxPriority,
                                        pxTaskDefinition->puxStackBuffer,
                                        pxTaskDefinition->pxTaskBuffer
                                    );

    if( *pxTaskHandle == NULL )
    {
        return pdFAIL;
    }

    return pdPASS;
}
/*-----------------------------------------------------------*/

BaseType_t xFreeRTOSTaskCreateAffinitySet( const TaskParams_t * const pxTaskDefinition,
                                                        UBaseType_t uxCoreAffinityMask,
                                                        TaskHandle_t *pxTaskHandle )
{
    *pxTaskHandle = xTaskCreateStaticAffinitySet(   pxTaskDefinition->pvTaskCode,
                                                    pxTaskDefinition->pcName,
                                                    pxTaskDefinition->usStackDepth,
                                                    pxTaskDefinition->pvParameters,
                                                    pxTaskDefinition->uxPriority,
                                                    pxTaskDefinition->puxStackBuffer,
                                                    pxTaskDefinition->pxTaskBuffer, 
                                                    uxCoreAffinityMask
                                                );

    if( *pxTaskHandle == NULL )
    {
        return pdFAIL;
    }

    return pdPASS;
}
/*-----------------------------------------------------------*/

TickType_t xFreeRTOSTaskGetTickCount( void )
{
    return ( TickType_t ) xTaskGetTickCount();
}
/*-----------------------------------------------------------*/

BaseType_t xFreeRTOSTaskDelayUntil( TickType_t *pxPreviousWakeTime,
                                           TickType_t xTimeIncrement )
{
    return ( BaseType_t ) xTaskDelayUntil( pxPreviousWakeTime, xTimeIncrement );
}
/*-----------------------------------------------------------*/

void vFreeRTOSTaskDelay( TickType_t xTicksToDelay )
{
    ( void ) vTaskDelay( xTicksToDelay );
}
/*-----------------------------------------------------------*/

void vFreeRTOSTaskDelete(TaskHandle_t xTaskHandle)
{
    /* If TaskHandle is NULL, then the current Task is Deleted. */
    ( void ) vTaskDelete( xTaskHandle );
}
/*-----------------------------------------------------------*/

void vFreeRTOSTaskSuspend(TaskHandle_t xTaskHandle)
{
    /* If TaskHandle is NULL, then the current Task is Supended. */
    ( void ) vTaskSuspend( xTaskHandle );
}

/*==============================================================
** Queues
==============================================================*/

BaseType_t xFreeRTOSQueueCreate( uint8_t *pucQueueStorage,
                                    UBaseType_t uxQueueLength,
                                    UBaseType_t uxItemSize,
                                    QueueHandle_t *pxQueueHandle,
                                    StaticQueue_t *pxStaticQueue)
{
    *pxQueueHandle = xQueueCreateStatic( uxQueueLength, uxItemSize, (uint8_t *) pucQueueStorage, pxStaticQueue );

    if( *pxQueueHandle != NULL )
    {
        return pdPASS;
    }else
    {
        return pdFALSE;
    }
}
/*-----------------------------------------------------------*/

BaseType_t xFreeRTOSQueueSend( QueueHandle_t xQueueHandle,
                                      const void *const pvSendMsg,
                                      TickType_t xTicksToWait )
{
    return ( BaseType_t ) xQueueSend( xQueueHandle, pvSendMsg, xTicksToWait );
}
/*-----------------------------------------------------------*/

BaseType_t xFreeRTOSQueueReceive( QueueHandle_t xQueueHandle, void *const pvReceiveMsgBuff,
                                         TickType_t xTicksToWait )
{
    return ( BaseType_t ) xQueueReceive( xQueueHandle, pvReceiveMsgBuff, xTicksToWait );
}
/*-----------------------------------------------------------*/

BaseType_t xFreeRTOSQueueSendFromISR( QueueHandle_t xQueueHandle, const void *const pvSendMsg )
{
    BaseType_t xReturn;
    BaseType_t xHigherPriorityTaskWoken;
    xHigherPriorityTaskWoken = pdFALSE;

    xReturn = xQueueSendFromISR( xQueueHandle, pvSendMsg, &xHigherPriorityTaskWoken );

    if( xHigherPriorityTaskWoken )
    {
        xHigherPriorityTaskWoken = pdFALSE;
        portYIELD_FROM_ISR( pdTRUE );
    }

    return xReturn; 
}
/*-----------------------------------------------------------*/

UBaseType_t uxFreeRTOSQueueMessagesWaiting( QueueHandle_t xQueueHandle )
{
    /* Returns number of messages/ number of items in Queue */
    UBaseType_t uxNumMessagesWaiting = 0x0UL;

    uxNumMessagesWaiting = uxQueueMessagesWaiting( xQueueHandle );

    return uxNumMessagesWaiting; 
}
/*-----------------------------------------------------------*/

BaseType_t xFreeRTOSQueuePeek( QueueHandle_t xQueueHandle, void *const pvReceiveMsgBuff, TickType_t xTicksToWait )
{
    return ( BaseType_t ) xQueuePeek( xQueueHandle, pvReceiveMsgBuff, xTicksToWait );
}

/*==============================================================
** Mutex
==============================================================*/

BaseType_t xFreeRTOSMutexCreate( StaticSemaphore_t *pxMutexBuffer,
                                               SemaphoreHandle_t *pxMutexHandle )
{
    BaseType_t xReturn;
    
    *pxMutexHandle = xSemaphoreCreateMutexStatic( ( StaticSemaphore_t *)pxMutexBuffer );

    if ( *pxMutexHandle != NULL )
    {
        xReturn = pdPASS;
    }else
    {
        xReturn = pdFAIL;
    }

    return xReturn;
}
/*-----------------------------------------------------------*/

BaseType_t xFreeRTOSMutexTake (SemaphoreHandle_t xMutexHandle, TickType_t xTicksToWait)
{
    return ( BaseType_t ) xSemaphoreTake( xMutexHandle, xTicksToWait );
}
/*-----------------------------------------------------------*/

BaseType_t xFreeRTOSMutexGive (SemaphoreHandle_t xMutexHandle)
{    
    return ( BaseType_t ) xSemaphoreGive( xMutexHandle );
}

/*==============================================================
** Semephore
==============================================================*/

BaseType_t xFreeRTOSSemaphoreCreateBinary(StaticSemaphore_t *pxSemaphoreBuffer, SemaphoreHandle_t *pxSemaphoreHandle)
{
	BaseType_t xReturn = pdFAIL;

	*pxSemaphoreHandle = xSemaphoreCreateBinaryStatic( (StaticSemaphore_t*)pxSemaphoreBuffer );

	if( *pxSemaphoreHandle == NULL )
    { 
		xReturn = pdFAIL;
	}else
    {
		xReturn = pdPASS;
	}

    return xReturn;
}
/*-----------------------------------------------------------*/

BaseType_t xFreeRTOSSemaphoreTake (SemaphoreHandle_t xSemaphoreHandle, TickType_t xTicksToWait)
{
    return ( BaseType_t ) xSemaphoreTake( (QueueHandle_t)xSemaphoreHandle, xTicksToWait );
}
/*-----------------------------------------------------------*/

BaseType_t xFreeRTOSSemaphoreGive (SemaphoreHandle_t xSemaphoreHandle)
{
    return ( BaseType_t ) xSemaphoreGive( xSemaphoreHandle );
}
/*-----------------------------------------------------------*/

BaseType_t xFreeRTOSSemaphoreGiveFromISR (SemaphoreHandle_t xSemaphoreHandle, BaseType_t * const pxHigherPriorityTaskWoken)
{
    BaseType_t xReturn = pdFALSE;

    xReturn = xSemaphoreGiveFromISR( xSemaphoreHandle, pxHigherPriorityTaskWoken );

    if( *pxHigherPriorityTaskWoken )
    {
        *pxHigherPriorityTaskWoken = pdFALSE;
        portYIELD_FROM_ISR( pdTRUE );
    }

    return xReturn;
}

/*==============================================================
** Event Groups
==============================================================*/

BaseType_t xFreeRTOSEventGroupCreate( StaticEventGroup_t *pxEventGroupBuffer,
                                                    EventGroupHandle_t *pxEventGroupHandle )
{
    BaseType_t xReturn;

    *pxEventGroupHandle = xEventGroupCreateStatic( pxEventGroupBuffer );

    if ( *pxEventGroupHandle != NULL )
    {
        xReturn =  pdPASS;
    }
    else
    {
        xReturn = pdFAIL;
    }
    return xReturn;
}
/*-----------------------------------------------------------*/

BaseType_t xFreeRTOSEventGroupSetBits( EventGroupHandle_t xEventGroupHandle,
                                                            const EventBits_t uxBitsToSet )
{
    EventBits_t uxBits;

    if ( xEventGroupHandle == NULL )
    {
        return pdFAIL;
    }

    if ( ( uxBitsToSet & eventEVENT_BITS_CONTROL_BYTES ) != 0U )
    {
        return pdFAIL;
    }

    uxBits = xEventGroupSetBits( xEventGroupHandle, uxBitsToSet );

    return pdPASS; 
}
/*-----------------------------------------------------------*/

BaseType_t xFreeRTOSEventGroupSetBitsFromISR( EventGroupHandle_t xEventGroupHandle,
                                                            const EventBits_t uxBitsToSet )
{
    BaseType_t xReturn;
    BaseType_t xHigherPriorityTaskWoken;
    xHigherPriorityTaskWoken = pdFALSE;

    if ( xEventGroupHandle == NULL )
    {
        return pdFAIL;
    }

    xReturn = xEventGroupSetBitsFromISR( xEventGroupHandle, uxBitsToSet, &xHigherPriorityTaskWoken );

    if( xHigherPriorityTaskWoken )
    {
        xHigherPriorityTaskWoken = pdFALSE;
        portYIELD_FROM_ISR( pdTRUE );
    }

    return xReturn; 
}
/*-----------------------------------------------------------*/

BaseType_t xFreeRTOSEventGroupClearBits( EventGroupHandle_t xEventGroupHandle,
                                                            const EventBits_t uxBitsToClear )
{
    EventBits_t uxBits;

    if ( xEventGroupHandle == NULL )
    {
        return pdFAIL;
    }

    if ( ( uxBitsToClear & eventEVENT_BITS_CONTROL_BYTES ) != 0U )
    {
        return pdFAIL;
    }

    uxBits = xEventGroupClearBits( xEventGroupHandle, uxBitsToClear );

    return pdPASS; 
}
/*-----------------------------------------------------------*/

BaseType_t xFreeRTOSEventGroupWaitBits( EventGroupHandle_t xEventGroupHandle,
                                               const EventBits_t uxBitsToWaitFor,
                                               const BaseType_t xClearOnExit,
                                               const BaseType_t xWaitForAllBits,
                                               EventBits_t *pxEventBitsSet,
                                               TickType_t xTicksToWait )
{
    BaseType_t xReturn = pdPASS;

    if ( xEventGroupHandle == NULL )
    {
        return pdFAIL;
    }

    if ( ( uxBitsToWaitFor & eventEVENT_BITS_CONTROL_BYTES ) != 0U )
    {
        return pdFAIL;
    }

    *pxEventBitsSet = xEventGroupWaitBits( xEventGroupHandle, uxBitsToWaitFor,
                                       xClearOnExit, xWaitForAllBits, xTicksToWait );

    if( ( *pxEventBitsSet | (uxBitsToWaitFor) ) == uxBitsToWaitFor )
    {
        //All bits were set 
        xReturn = pdPASS;
    }
    else 
    {
        //Not all bits were set or return because xTicksToWait ticks passed without the bits becoming set. 
        xReturn = pdFAIL;
    }
    return xReturn;
}
/*-----------------------------------------------------------*/


