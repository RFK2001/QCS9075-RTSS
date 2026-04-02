/*
===========================================================================
*/
/**
    @file  FreeRTOSOsal.h
    @brief OS Application Layer which contains declaration of FreeRTOS kernel/port functions exposed to SAIL BSP

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

#ifndef FREERTOS_OSAL_H
#define FREERTOS_OSAL_H

#ifdef __cplusplus
extern "C" {
#endif

/*=================================================================================================
**                                        Include files                                          **
=================================================================================================*/
/* FreeRTOS includes. */
#include "FreeRTOSConfig.h"
#include "projdefs.h"
#include "FreeRTOS.h"

#include "task.h"
#include "list.h"
#include "queue.h"
#include "timers.h"
#include "atomic.h"
#include "message_buffer.h"
#include "event_groups.h"
#include "croutine.h"
#include "atomic.h"
#include "semphr.h"
#include "stack_macros.h"
#include "stream_buffer.h"
//#include "mpu_wrappers.h"

/*=================================================================================================
**                              macros, variables and constants                                  **
=================================================================================================*/

#define freertosMAX_DELAY                    ( ( TickType_t ) portMAX_DELAY )

/*=================================================================================================
**                 typedefs : Enums, Structures Union and other typedefs                         **
=================================================================================================*/
enum
{
    MEM_ALIGNMENT_4     = 4U,
    MEM_ALIGNMENT_8     = 8U,
    MEM_ALIGNMENT_16    = 16U,
    MEM_ALIGNMENT_32    = 32U,
    MEM_ALIGNMENT_64    = 64U,
};

typedef struct{
    TaskFunction_t pvTaskCode;
    const char * pcName;
    configSTACK_DEPTH_TYPE usStackDepth;
    void * pvParameters;
    UBaseType_t uxPriority;
    StackType_t * puxStackBuffer;
    StaticTask_t * const pxTaskBuffer;
    MemoryRegion_t xRegions[ portNUM_CONFIGURABLE_REGIONS ];
}TaskParams_t;


/*=================================================================================================
**                                 Global function prototypes                                    **
=================================================================================================*/

/*==============================================================
** OSAL: Critical sections
==============================================================*/

#define freertosENTER_CRITICAL()                   vTaskEnterCritical()

#define freertosEXIT_CRITICAL()                    vTaskExitCritical()

/*==============================================================
** OSAL: Task YIELD
==============================================================*/

/* Force the task to yield. */
#define freertosYIELD()                             portYIELD()

/* yield the task from an ISR */
#define freertosYIELD_FROM_ISR()                    portYIELD_FROM_ISR( pdTRUE )

/*==============================================================
** Application functions/hooks
==============================================================*/
void vApplicationSetupTickInterrupt( void );

void vApplicationClearTickInterrupt( void );

void vApplicationTickHook( void );

void vApplicationIdleHook( void );

void vApplicationPassiveIdleHook( void );

void vApplicationFPUSafeIRQHandler( uint32_t ulICCIAR );

/*==============================================================
** OSAL: Scheduler
==============================================================*/
void vFreeRTOSTaskSuspendAll( void );

BaseType_t xFreeRTOSTaskResumeAll( void );

BaseType_t xFreeRTOSTaskGetSchedulerState( void );

/*==============================================================
** OSAL: Task
==============================================================*/

void vFreeRTOSTaskDelay( TickType_t xTicksToDelay );

BaseType_t xFreeRTOSTaskCreate( const TaskParams_t * const pxTaskDefinition,
                                                            TaskHandle_t *pxTaskHandle );

BaseType_t xFreeRTOSTaskCreateAffinitySet( const TaskParams_t * const pxTaskDefinition,
                                                                UBaseType_t uxCoreAffinityMask,
                                                                TaskHandle_t *pxTaskHandle );

TickType_t xFreeRTOSTaskGetTickCount( void );

BaseType_t xFreeRTOSTaskDelayUntil( TickType_t *pxPreviousWakeTime,
                                                        TickType_t xTimeIncrement );

void vFreeRTOSTaskDelete(TaskHandle_t xTaskHandle);

void vFreeRTOSTaskSuspend(TaskHandle_t xTaskHandle);

/*==============================================================
** OSAL: Queue
==============================================================*/

BaseType_t xFreeRTOSQueueCreate( uint8_t *pucQueueStorage,
                                               UBaseType_t uxQueueLength,
                                               UBaseType_t uxItemSize,
                                               QueueHandle_t *pxQueueHandle,
											   StaticQueue_t *pxStaticQueue );

BaseType_t xFreeRTOSQueueSend( QueueHandle_t xQueueHandle,
                                      const void *const pvSendMsg,
                                      TickType_t xTicksToWait );

BaseType_t xFreeRTOSQueueSendFromISR( QueueHandle_t xQueueHandle, const void *const pvSendMsg );

BaseType_t xFreeRTOSQueueReceive( QueueHandle_t xQueueHandle, void *const pvReceiveMsgBuff,
                                         TickType_t xTicksToWait );

UBaseType_t uxFreeRTOSQueueMessagesWaiting( QueueHandle_t xQueueHandle );

BaseType_t xFreeRTOSQueuePeek( QueueHandle_t xQueueHandle, void *const pvReceiveMsgBuff, TickType_t xTicksToWait );

/*==============================================================
** OSAL: Mutex
==============================================================*/

BaseType_t xFreeRTOSMutexCreate( StaticSemaphore_t *pxMutexBuffer,
                                                        SemaphoreHandle_t *pxMutexHandle );

BaseType_t xFreeRTOSMutexTake(SemaphoreHandle_t xMutexHandle, TickType_t xTicksToWait);

BaseType_t xFreeRTOSMutexGive(SemaphoreHandle_t xMutexHandle);

/*==============================================================
** OSAL: Semephore
==============================================================*/

BaseType_t xFreeRTOSSemaphoreCreateBinary(StaticSemaphore_t *pxSemaphoreBuffer, SemaphoreHandle_t *pxSemaphoreHandle);

BaseType_t xFreeRTOSSemaphoreGive(SemaphoreHandle_t xSemaphoreHandle);

BaseType_t xFreeRTOSSemaphoreGiveFromISR(SemaphoreHandle_t xSemaphoreHandle, BaseType_t * const pxHigherPriorityTaskWoken);

BaseType_t xFreeRTOSSemaphoreTake(SemaphoreHandle_t xSemaphoreHandle, TickType_t xTicksToWait);

/*==============================================================
** OSAL: Event Groups
==============================================================*/

BaseType_t xFreeRTOSEventGroupCreate( StaticEventGroup_t *pxEventGroup,
                                                    EventGroupHandle_t *pxEventGroupHandle );

BaseType_t xFreeRTOSEventGroupSetBits( EventGroupHandle_t xEventGroupHandle,
                                                             const EventBits_t xBitsToSet );
                                                             
BaseType_t xFreeRTOSEventGroupSetBitsFromISR( EventGroupHandle_t xEventGroupHandle,
                                                            const EventBits_t xBitsToSet );

BaseType_t xFreeRTOSEventGroupClearBits( EventGroupHandle_t xEventGroupHandle,
                                                             const EventBits_t xBitsToClear );

BaseType_t xFreeRTOSEventGroupWaitBits( EventGroupHandle_t xEventGroupHandle,
                                                      const EventBits_t xBitsToWaitFor,
                                                      const BaseType_t xClearOnExit,
                                                      const BaseType_t xWaitForAllBits,
                                                      EventBits_t *pxEventBitsSet,
                                                      TickType_t xTicksToWait );

#ifdef __cplusplus
}
#endif

#endif /* FREERTOS_OSAL_H */
