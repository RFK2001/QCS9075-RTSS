/*
 * FreeRTOS Kernel V11.0.1
 * Copyright (C) 2021 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 * Copyright (c) 2021 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: MIT AND BSD-3-Clause
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 */
 
/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * All rights reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

#ifndef PORTMACRO_H
#define PORTMACRO_H

/* *INDENT-OFF* */
#ifdef __cplusplus
    extern "C" {
#endif
/* *INDENT-ON* */
/*-----------------------------------------------------------------------------
 * Include Files
 *---------------------------------------------------------------------------*/
#include "sailbsp_mutex.h"

/*-----------------------------------------------------------
 * Port specific definitions.
 *
 * The settings in this file configure FreeRTOS correctly for the given hardware
 * and compiler.
 *
 * These settings should not be altered.
 *-----------------------------------------------------------
 */

/* Type definitions. */
#define portCHAR          char
#define portFLOAT         float
#define portDOUBLE        double
#define portLONG          long
#define portSHORT         short
#define portSTACK_TYPE    uint32_t
#define portBASE_TYPE     long

typedef portSTACK_TYPE   StackType_t;
typedef long             BaseType_t;
typedef unsigned long    UBaseType_t;

typedef uint32_t         TickType_t;

#define portMAX_DELAY    ( TickType_t ) 0xffffffffUL

#define portUNUSED_PARAMETER( x )     ( ( void )(x) )

/*-----------------------------------------------------------*/

/* Hardware specifics. */
#define portSTACK_GROWTH      ( -1 )
#define portTICK_PERIOD_MS    ( ( TickType_t ) 1000 / configTICK_RATE_HZ )
#define portBYTE_ALIGNMENT    8

/*-----------------------------------------------------------*/
/* Arch Utilities. */
BaseType_t xPortGetCoreId( void );
#define portGET_CORE_ID()                xPortGetCoreId()
#define portGET_CLUSTER_ID()             xPortGetCusterId()

/*-----------------------------------------------------------*/

/* Task utilities. */

/* Called at the end of an ISR that can cause a context switch. */
#if ( configNUMBER_OF_CORES > 1 )
#define portEND_SWITCHING_ISR( xSwitchRequired )                        \
    {                                                                   \
        extern uint32_t ulPortYieldRequired[ configNUMBER_OF_CORES ];   \
                                                                        \
        if( xSwitchRequired != pdFALSE )                                \
        {                                                               \
            ulPortYieldRequired[ portGET_CORE_ID() ] = pdTRUE;          \
        }                                                               \
    }
#else
#define portEND_SWITCHING_ISR( xSwitchRequired )                        \
    {                                                                   \
        extern uint32_t ulPortYieldRequired;                            \
                                                                        \
        if( xSwitchRequired != pdFALSE )                                \
        {                                                               \
            ulPortYieldRequired = pdTRUE;                               \
        }                                                               \
    }
#endif /* #if ( configNUMBER_OF_CORES > 1 ) */

#define portYIELD_FROM_ISR( x )    portEND_SWITCHING_ISR( x )
#define portYIELD()                __asm volatile ( "SVC 0" ::: "memory" );


/*-----------------------------------------------------------
* Critical section control
*----------------------------------------------------------*/

#if ( configNUMBER_OF_CORES == 1 )
    extern void vPortEnterCritical( void );
    extern void vPortExitCritical( void );
#endif /* #if ( configNUMBER_OF_CORES == 1 ) */

//TODO : Need to use common logic between GNU and FUSA for INTR masking

#if defined(__ARM_GNU__)
    extern void vPortClearInterruptMask( uint32_t ulSavedCpsrState );
    extern void vPortDisableInterrupts( void );
    extern void vPortEnableInterrupts( void );
    extern uint32_t ulPortSetInterruptMask( void );
#define portDISABLE_INTERRUPTS()                  vPortDisableInterrupts()
#define portENABLE_INTERRUPTS()                   vPortEnableInterrupts()
#define portSET_INTERRUPT_MASK()                  ulPortSetInterruptMask()
#define portCLEAR_INTERRUPT_MASK( x )             vPortClearInterruptMask( x )
#define portSET_INTERRUPT_MASK_FROM_ISR()         ulPortSetInterruptMask()
#define portCLEAR_INTERRUPT_MASK_FROM_ISR( x )    vPortClearInterruptMask( x )


#elif defined(__ARM_FUSA__)
    extern uint32_t ulPortSetInterruptMask( void );
    extern void vPortClearInterruptMask( uint32_t ulNewMaskValue );
    extern void vPortInstallFreeRTOSVectorTable( void );

#define portDISABLE_INTERRUPTS()                  ulPortSetInterruptMask()
#define portENABLE_INTERRUPTS()                   vPortClearInterruptMask( 0 )

#define portDISABLE_INTERRUPTS()                  ulPortSetInterruptMask()
#define portENABLE_INTERRUPTS()                   vPortClearInterruptMask( 0 )
#define portSET_INTERRUPT_MASK()                  ulPortSetInterruptMask()
#define portCLEAR_INTERRUPT_MASK( x )             vPortClearInterruptMask( x )
#define portSET_INTERRUPT_MASK_FROM_ISR()         ulPortSetInterruptMask()
#define portCLEAR_INTERRUPT_MASK_FROM_ISR( x )    vPortClearInterruptMask( x )

#endif

/*
 * These macros do not globally disable/enable interrupts. They do mask off
 * interrupts that have a priority below configMAX_API_CALL_INTERRUPT_PRIORITY.
 */
#if ( configNUMBER_OF_CORES == 1 )
    #define portENTER_CRITICAL()                      vPortEnterCritical();
    #define portEXIT_CRITICAL()                       vPortExitCritical();
#endif /* #if ( configNUMBER_OF_CORES == 1 ) */

/*-----------------------------------------------------------
* SMP Support
*----------------------------------------------------------*/
#if ( configNUMBER_OF_CORES > 1 )

#define portRTOS_SPINLOCK_COUNT    2
extern mutex_t     *pxFreeRTOSLock[];		

static inline void vPortRecursiveLock( uint32_t ulLockType,
                                       mutex_t * pxLock,
                                       BaseType_t uxAcquire )
{
    static uint8_t ucOwnedByCore[ configNUMBER_OF_CORES ];
    static uint8_t ucRecursionCountByLock[ portRTOS_SPINLOCK_COUNT ];
    uint32_t ulCoreNum = portGET_CORE_ID();
    uint32_t ulLockBit = 1u << ulLockType;

    if( uxAcquire )
    {
        if( pxLock != NULL )
        {
			// If specific core has specific lock (task or isr) already locked
            if( ucOwnedByCore[ ulCoreNum ] & ulLockBit )
            {
				// Increment lock count
                ucRecursionCountByLock[ ulLockType ]++;
                return;
            }
			// Spin until lock is free
            while( pxLock[ulLockType].lock == 1 )
            {
            }
        }
		// Take lock
		mutex_lock(&pxLock[ulLockType]);
        ucRecursionCountByLock[ ulLockType ] = 1;
        ucOwnedByCore[ ulCoreNum ] |= ulLockBit;
    }
    else
    {
		// Decrement count
        if( !--ucRecursionCountByLock[ ulLockType ] )
        {
            ucOwnedByCore[ ulCoreNum ] &= ~ulLockBit;
			mutex_unlock(&pxLock[ulLockType]);
        }
    }
}

    /* Request the Core(X) to yield. */
    void vPortYieldCore( BaseType_t xYieldCoreId );
    #define portYIELD_CORE( x )              vPortYieldCore( x )

	/* Acquire the TASK lock. TASK lock is a recursive lock.
	 * It should be able to be locked by the same core multiple times. */
    #define portGET_TASK_LOCK()              vPortRecursiveLock( 1, *pxFreeRTOSLock, pdTRUE )

	/* Release the TASK lock. If a TASK lock is locked by the same core multiple times,
	 * it should be released as many times as it is locked. */
    #define portRELEASE_TASK_LOCK()          vPortRecursiveLock( 1, *pxFreeRTOSLock, pdFALSE )

	/* Acquire the ISR lock. ISR lock is a recursive lock.
	 * It should be able to be locked by the same core multiple times. */
    #define portGET_ISR_LOCK()                vPortRecursiveLock( 0, *pxFreeRTOSLock, pdTRUE )

	/* Release the ISR lock. If a ISR lock is locked by the same core multiple times, \
	 * it should be released as many times as it is locked. */
    #define portRELEASE_ISR_LOCK()           vPortRecursiveLock( 0, *pxFreeRTOSLock, pdFALSE )

    #define portENTER_CRITICAL()             vTaskEnterCritical()
    #define portEXIT_CRITICAL()              vTaskExitCritical()

	/* vTaskEnterCriticalFromISR and vTaskExitCriticalFromISR should be used in the
	 * implementation of portENTER/EXIT_CRITICAL_FROM_ISR if the number of cores is
	 * more than 1 in the system. */
    #define portENTER_CRITICAL_FROM_ISR()    vTaskEnterCriticalFromISR()
    #define portEXIT_CRITICAL_FROM_ISR( x )  vTaskExitCriticalFromISR( x )

#endif /* if ( configNUMBER_OF_CORES > 1 ) */

/*-----------------------------------------------------------*/

/*
 * Task function macros as described on the FreeRTOS.org WEB site.  These are
 * not required for this port but included in case common demo code that uses these
 * macros is used.
 */
#define portTASK_FUNCTION_PROTO( vFunction, pvParameters )    void vFunction( void * pvParameters )
#define portTASK_FUNCTION( vFunction, pvParameters )          void vFunction( void * pvParameters )

/*
 * Prototype of the FreeRTOS tick handler.  This must be installed as the
 * handler for whichever peripheral is used to generate the RTOS tick.
 */
void FreeRTOS_Tick_Handler( void );

/*
 * If configUSE_TASK_FPU_SUPPORT is set to 1, then tasks are created without an
 * FPU context and must call vPortTaskUsesFPU() to allocate an FPU context
 * prior to any FPU instructions. If configUSE_TASK_FPU_SUPPORT is set to 2,
 * then all tasks have an FPU context allocated by default.
 */
#if ( configUSE_TASK_FPU_SUPPORT == 1 )
    void vPortTaskUsesFPU( void );
    #define portTASK_USES_FLOATING_POINT()    vPortTaskUsesFPU()
#elif ( configUSE_TASK_FPU_SUPPORT == 2 )

/*
 * Each task has an FPU context already, so define this function away to
 * prevent it being called accidentally.
 */
    #define vPortTaskUsesFPU()
    #define portTASK_USES_FLOATING_POINT()
#endif /* configUSE_TASK_FPU_SUPPORT */

#define portLOWEST_INTERRUPT_PRIORITY           ( ( ( uint32_t ) configUNIQUE_INTERRUPT_PRIORITIES ) - 1UL )
#define portLOWEST_USABLE_INTERRUPT_PRIORITY    ( portLOWEST_INTERRUPT_PRIORITY - 1UL )

/* Architecture specific optimisations. */
#ifndef configUSE_PORT_OPTIMISED_TASK_SELECTION
    #define configUSE_PORT_OPTIMISED_TASK_SELECTION    1
#endif

#if configUSE_PORT_OPTIMISED_TASK_SELECTION == 1

/* Store/clear the ready priorities in a bit map. */
    #define portRECORD_READY_PRIORITY( uxPriority, uxReadyPriorities )    ( uxReadyPriorities ) |= ( 1UL << ( uxPriority ) )
    #define portRESET_READY_PRIORITY( uxPriority, uxReadyPriorities )     ( uxReadyPriorities ) &= ~( 1UL << ( uxPriority ) )

/*-----------------------------------------------------------*/

    #define portGET_HIGHEST_PRIORITY( uxTopPriority, uxReadyPriorities )    uxTopPriority = ( 31 - __builtin_clz( uxReadyPriorities ) )

#endif /* configUSE_PORT_OPTIMISED_TASK_SELECTION */

#if ( configASSERT_DEFINED == 1 )
    void vPortValidateInterruptPriority( void );
    #define portASSERT_IF_INTERRUPT_PRIORITY_INVALID()    vPortValidateInterruptPriority()
#endif /* configASSERT */

#define portNOP()                                         __asm volatile ( "NOP" )


/*
 * The number of bits to shift for an interrupt priority is dependent on the
 * number of bits implemented by the interrupt controller.
 */
#if configUNIQUE_INTERRUPT_PRIORITIES == 16
    #define portPRIORITY_SHIFT            4
    #define portMAX_BINARY_POINT_VALUE    3
#elif configUNIQUE_INTERRUPT_PRIORITIES == 32
    #define portPRIORITY_SHIFT            3
    #define portMAX_BINARY_POINT_VALUE    2
#elif configUNIQUE_INTERRUPT_PRIORITIES == 64
    #define portPRIORITY_SHIFT            2
    #define portMAX_BINARY_POINT_VALUE    1
#elif configUNIQUE_INTERRUPT_PRIORITIES == 128
    #define portPRIORITY_SHIFT            1
    #define portMAX_BINARY_POINT_VALUE    0
#elif configUNIQUE_INTERRUPT_PRIORITIES == 256
    #define portPRIORITY_SHIFT            0
    #define portMAX_BINARY_POINT_VALUE    0
#else /* if configUNIQUE_INTERRUPT_PRIORITIES == 16 */
    #error Invalid configUNIQUE_INTERRUPT_PRIORITIES setting.  configUNIQUE_INTERRUPT_PRIORITIES must be set to the number of unique priorities implemented by the target hardware
#endif /* if configUNIQUE_INTERRUPT_PRIORITIES == 16 */

/* Interrupt controller direct addresses access not available for GICv3 */

#define portMEMORY_BARRIER()    __asm volatile ( "" ::: "memory" )

/* *INDENT-OFF* */
#ifdef __cplusplus
    } /* extern C */
#endif
/* *INDENT-ON* */

#endif /* PORTMACRO_H */
