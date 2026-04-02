/*
 * FreeRTOS Kernel V11.0.1
 * Copyright (C) 2021 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * SPDX-License-Identifier: MIT
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

/* Standard includes. */
#include <stdlib.h>
#include <string.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "IPCC.h"
#include "common_functions.h"
#include "sail_bootcfg.h"

#ifndef configINTERRUPT_CONTROLLER_BASE_ADDRESS
    #error configINTERRUPT_CONTROLLER_BASE_ADDRESS must be defined.  Refer to Cortex-A equivalent: http: /*www.FreeRTOS.org/Using-FreeRTOS-on-Cortex-A-Embedded-Processors.html */
#endif

#ifndef configINTERRUPT_CONTROLLER_CPU_INTERFACE_OFFSET
    #error configINTERRUPT_CONTROLLER_CPU_INTERFACE_OFFSET must be defined.  Refer to Cortex-A equivalent: http: /*www.FreeRTOS.org/Using-FreeRTOS-on-Cortex-A-Embedded-Processors.html */
#endif

#ifndef configUNIQUE_INTERRUPT_PRIORITIES
    #error configUNIQUE_INTERRUPT_PRIORITIES must be defined.  Refer to Cortex-A equivalent: http: /*www.FreeRTOS.org/Using-FreeRTOS-on-Cortex-A-Embedded-Processors.html */
#endif

#ifndef configSETUP_TICK_INTERRUPT
    #error configSETUP_TICK_INTERRUPT() must be defined.  Refer to Cortex-A equivalent: http: /*www.FreeRTOS.org/Using-FreeRTOS-on-Cortex-A-Embedded-Processors.html */
#endif /* configSETUP_TICK_INTERRUPT */

#ifndef configMAX_API_CALL_INTERRUPT_PRIORITY
    #error configMAX_API_CALL_INTERRUPT_PRIORITY must be defined.  Refer to Cortex-A equivalent: http: /*www.FreeRTOS.org/Using-FreeRTOS-on-Cortex-A-Embedded-Processors.html */
#endif

#if configMAX_API_CALL_INTERRUPT_PRIORITY > configUNIQUE_INTERRUPT_PRIORITIES
    #error configMAX_API_CALL_INTERRUPT_PRIORITY must be less than or equal to configUNIQUE_INTERRUPT_PRIORITIES as the lower the numeric priority value the higher the logical interrupt priority
#endif

#if configUSE_PORT_OPTIMISED_TASK_SELECTION == 1
    /* Check the configuration. */
    #if ( configMAX_PRIORITIES > 32 )
        #error configUSE_PORT_OPTIMISED_TASK_SELECTION can only be set to 1 when configMAX_PRIORITIES is less than or equal to 32.  It is very rare that a system requires more than 10 to 15 difference priorities as tasks that share a priority will time slice.
    #endif
#endif /* configUSE_PORT_OPTIMISED_TASK_SELECTION */

//TODO: check if API/Drivers interrupt priority can be changed to lower priority. 
#if 0
#if configMAX_API_CALL_INTERRUPT_PRIORITY == 0
    #error configMAX_API_CALL_INTERRUPT_PRIORITY must not be set to 0
#endif

/* In case security extensions are implemented. */
#if configMAX_API_CALL_INTERRUPT_PRIORITY <= ( configUNIQUE_INTERRUPT_PRIORITIES / 2 )
    #error configMAX_API_CALL_INTERRUPT_PRIORITY must be greater than ( configUNIQUE_INTERRUPT_PRIORITIES / 2 )
#endif
#endif 

/*
 * __ARM_FP is defined by the c preprocessor when FPU support is enabled,
 * usually with the -mfpu= argument and -mfloat-abi=.
 *
 * Note: Some implementations of the c standard library may use FPU registers
 *       for generic memory operations (memcpy, etc).
 *       When setting configUSE_TASK_FPU_SUPPORT == 1, care must be taken to
 *       ensure that the FPU registers are not used without an FPU context.
 */
#if ( configUSE_TASK_FPU_SUPPORT == 0 )
    #ifdef __ARM_FP
        #error __ARM_FP is defined, so configUSE_TASK_FPU_SUPPORT must be set to either to 1 or 2.
    #endif /* __ARM_FP */
#elif ( configUSE_TASK_FPU_SUPPORT == 1 ) || ( configUSE_TASK_FPU_SUPPORT == 2 )
    #ifndef __ARM_FP
        #error __ARM_FP is not defined, so configUSE_TASK_FPU_SUPPORT must be set to 0.
    #endif /* __ARM_FP */
#endif /* configUSE_TASK_FPU_SUPPORT */

/*
 * Some vendor specific files default configCLEAR_TICK_INTERRUPT() in
 * portmacro.h.
 */
#ifndef configCLEAR_TICK_INTERRUPT
    #define configCLEAR_TICK_INTERRUPT()
#endif

/*
 * A critical section is exited when the critical section nesting count reaches
 * this value.
 */
#define portNO_CRITICAL_NESTING          ( ( uint32_t ) 0 )

/*
 * In all GICs 255 can be written to the priority mask register to unmask all
 * (but the lowest) interrupt priority.
 */
#define portUNMASK_VALUE                 ( 0xFFUL )

/*
 * Tasks are not created with a floating point context, but can be given a
 * floating point context after they have been created.  A variable is stored as
 * part of the tasks context that holds portNO_FLOATING_POINT_CONTEXT if the task
 * does not have an FPU context, or any other value if the task does have an FPU
 * context.
 */
#define portNO_FLOATING_POINT_CONTEXT    ( ( StackType_t ) 0 )

/* Constants required to setup the initial task context. */
#define portINITIAL_SPSR                 ( ( StackType_t ) 0x1f ) /* System mode, ARM mode, IRQ enabled FIQ enabled. */
#define portTHUMB_MODE_BIT               ( ( StackType_t ) 0x20 )
#define portINTERRUPT_ENABLE_BIT         ( 0x80UL )
#define portTHUMB_MODE_ADDRESS           ( 0x01UL )

/*
 * Used by portASSERT_IF_INTERRUPT_PRIORITY_INVALID() when ensuring the binary
 * point is zero.
 */
#define portBINARY_POINT_BITS            ( ( uint8_t ) 0x03 )

/* Masks all bits in the APSR other than the mode bits. */
#define portAPSR_MODE_BITS_MASK          ( 0x1F )

/* The value of the mode bits in the APSR when the CPU is executing in user
 * mode. */
#define portAPSR_USER_MODE               ( 0x10 )

/* The critical section macros only mask interrupts up to an application
 * determined priority level.  Sometimes it is necessary to turn interrupt off in
 * the CPU itself before modifying certain hardware registers. */
#define portCPU_IRQ_DISABLE()                  \
    __asm volatile ( "CPSID i" ::: "memory" ); \
    __asm volatile ( "DSB" );                  \
    __asm volatile ( "ISB" );

#define portCPU_IRQ_ENABLE()                   \
    __asm volatile ( "CPSIE i" ::: "memory" ); \
    __asm volatile ( "DSB" );                  \
    __asm volatile ( "ISB" );


/* Macro to unmask all interrupt priorities. */
#define portCLEAR_INTERRUPT_MASK_GENERIC()                                                  \
    {                                                                                       \
        portCPU_IRQ_DISABLE();                                                              \
        __asm volatile ( "mcr p15, 0, %0, c4, c6, 0":  :"r" ( (uint32_t)portUNMASK_VALUE) );\
        __asm volatile ( "DSB       \n"                                                     \
                         "ISB       \n" );                                                  \
        portCPU_IRQ_ENABLE();                                                               \
    }

#define portINTERRUPT_PRIORITY_REGISTER_OFFSET    0x420UL
#define portMAX_8_BIT_VALUE                       ( ( uint8_t ) 0xff )
#define portBIT_0_SET                             ( ( uint8_t ) 0x01 )
#define portCPSR_IRQ_MASK                         ( ( uint32_t ) 0x80 )

/*
 * Let the user override the pre-loading of the initial LR with the address of
 * prvTaskExitError() in case is messes up unwinding of the stack in the
 * debugger.
 */
#ifdef configTASK_RETURN_ADDRESS
    #define portTASK_RETURN_ADDRESS    configTASK_RETURN_ADDRESS
#else
    #define portTASK_RETURN_ADDRESS    prvTaskExitError
#endif

#if ( configUSE_TASK_FPU_SUPPORT != 0 )

/*
 * The space on the stack required to hold the FPU registers.
 *
 * The ARM Cortex R52 processor implements the VFPv4-D32 FPU
 * architecture. This includes only 32 double-precision registers,
 * instead of 32 as is in VFPv4. The register bank can be viewed
 * either as thirty-two 64-bit double-word registers (D0-D31) or
 * Sixty-four 32-bit single-word registers (S0-S63), in both cases
 * the size of the bank remains the same. The FPU has also a 32-bit
 * status register.
 */
    #define portFPU_REGISTER_WORDS    ( ( 32 * 2 ) + 1 )
#endif /* configUSE_TASK_FPU_SUPPORT != 0 */

/*Schedular Synchronization*/
#define portCLUSTER_1_ID                ( (uint32_t) 1U)
#define portCLUSTER_2_ID                ( (uint32_t) 2U)
#define portSTART_SCHEDULAR_BITS        ( (uint32_t) ( ( (uint32_t)0xFUL & ~(ulCluster1LockStep << 1UL) ) & ~(ulCluster2LockStep << 3UL) ) ) 

/*-----------------------------------------------------------*/

/*
 * Starts the first task executing.  This function is necessarily written in
 * assembly code so is implemented in portASM.s.
 */
extern void vPortRestoreTaskContext( void );

/*
 * Used to catch tasks that attempt to return from their implementing function.
 */
static void prvTaskExitError( void );

#if ( configUSE_TASK_FPU_SUPPORT != 0 )

/*
 * If the application provides an implementation of vApplicationIRQHandler(),
 * then it will get called directly without saving the FPU registers on
 * interrupt entry, and this weak implementation of
 * vApplicationFPUSafeIRQHandler() is just provided to remove linkage errors -
 * it should never actually get called so its implementation contains a
 * call to configASSERT() that will always fail.
 *
 * If the application provides its own implementation of
 * vApplicationFPUSafeIRQHandler() then the implementation of
 * vApplicationIRQHandler() provided in portASM.S will save the FPU registers
 * before calling it.
 *
 * Therefore, if the application writer wants FPU registers to be saved on
 * interrupt entry their IRQ handler must be called
 * vApplicationFPUSafeIRQHandler(), and if the application writer does not want
 * FPU registers to be saved on interrupt entry their IRQ handler must be
 * called vApplicationIRQHandler().
 */
    void vApplicationFPUSafeIRQHandler( uint32_t ulICCIAR ) __attribute__( ( weak ) );
#endif /* configUSE_TASK_FPU_SUPPORT != 0 */

/*-----------------------------------------------------------*/

/*
 * A variable is used to keep track of the critical section nesting.  This
 * variable has to be stored as part of the task context and must be initialised to
 * a non zero value to ensure interrupts don't inadvertently become unmasked before
 * the scheduler starts.  As it is stored as part of the task context it will
 * automatically be set to 0 when the first task is started.
 */
/* For SMP if portCRITICAL_NESTING_IN_TCB == 1, Ctitical nesting is part of Task TCB
 * ulCriticalNesting is not used in this senario.    
 * TODO: use uxCriticalNesting from TCB from save/restore (context switching.)
 */
volatile uint32_t ulCriticalNesting = 9999UL;

#if ( configUSE_TASK_FPU_SUPPORT != 0 )

/*
 * Saved as part of the task context.  If ulPortTaskHasFPUContext is non-zero then
 * a floating point context must be saved and restored for the task.
 */
    uint32_t ulPortTaskHasFPUContext = pdFALSE;
#endif /* configUSE_TASK_FPU_SUPPORT != 0 */

/* Set to 1 to pend a context switch from an ISR. */
#if ( configNUMBER_OF_CORES > 1 )
    uint32_t ulPortYieldRequired[ configNUMBER_OF_CORES ]= { pdFALSE };
#else
    uint32_t ulPortYieldRequired = pdFALSE;
#endif /* #if ( configNUMBER_OF_CORES > 1 ) */

/*
 * Counts the interrupt nesting depth.  A context switch is only performed if
 * if the nesting depth is 0.
 */
#if ( configNUMBER_OF_CORES > 1 )
    uint32_t ulPortInterruptNesting[ configNUMBER_OF_CORES ] = { 0UL };
#else
    uint32_t ulPortInterruptNesting = 0UL;
#endif /* #if ( configNUMBER_OF_CORES > 1 ) */

#if ( configNUMBER_OF_CORES > 1 )
    IPCC_Handle xFreertosSmp_IpccHandle[configNUMBER_OF_CORES] = { NULL };

    volatile uint32_t ulPortStartSchedulerSync = 0UL;

    volatile uint32_t ulCluster1LockStep = 0UL;

    volatile uint32_t ulCluster2LockStep = 0UL;
#endif /* #if ( configNUMBER_OF_CORES > 1 ) */

/* Used in asm code. */
__attribute__( ( used ) ) const uint32_t ulMaxAPIPriorityMask = ( configMAX_API_CALL_INTERRUPT_PRIORITY << portPRIORITY_SHIFT );

/*-----------------------------------------------------------*/

/* Weak Declarations */

void vApplicationTickHook( void ) __attribute__((weak));
void vApplicationSetupTickInterrupt( void ) __attribute__((weak));
void vApplicationClearTickInterrupt( void ) __attribute__((weak));
void vApplicationStackOverflowHook( TaskHandle_t xTask, char *pcTaskName ) __attribute__((weak));
void vApplicationIdleHook( void ) __attribute__((weak));
void vApplicationMallocFailedHook( void ) __attribute__((weak));

#if ( configUSE_PASSIVE_IDLE_HOOK == 1 )
void vApplicationPassiveIdleHook( void ) __attribute__((weak));
#endif /* #if ( configUSE_PASSIVE_IDLE_HOOK == 1 ) */

#if (configSUPPORT_STATIC_ALLOCATION == 1)
void vApplicationGetTimerTaskMemory( StaticTask_t **ppxTimerTaskTCBBuffer,
                                     StackType_t **ppxTimerTaskStackBuffer,
                                     configSTACK_DEPTH_TYPE * puxTimerTaskStackSize )
								__attribute__((weak));

void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer,
                                    StackType_t **ppxIdleTaskStackBuffer,
                                    configSTACK_DEPTH_TYPE * puxIdleTaskStackSize )
								__attribute__((weak));
void vApplicationGetPassiveIdleTaskMemory( StaticTask_t ** ppxIdleTaskTCBBuffer,
                                                   StackType_t ** ppxIdleTaskStackBuffer,
                                                   configSTACK_DEPTH_TYPE * puxIdleTaskStackSize,
                                                   BaseType_t xPassiveIdleTaskIndex )
                                __attribute__((weak));
#endif

/*-----------------------------------------------------------*/

/* SMP supporting functions */

BaseType_t xPortGetCoreId( void )
{
    BaseType_t xCurrentCoreId = get_curr_phys_cpu_num();

    return xCurrentCoreId;
}
/*-----------------------------------------------------------*/

BaseType_t xPortGetCusterId( void )
{
    BaseType_t xCurrentCluserId = get_curr_cluster_num();

    return xCurrentCluserId;
}
/*-----------------------------------------------------------*/

#if ( configNUMBER_OF_CORES > 1 )
void vPortYieldCore( BaseType_t xYieldCoreId )
{
    ( void )IPCC_Trigger( xFreertosSmp_IpccHandle[(uint32_t)portGET_CORE_ID()], (IPCC_Client)IPCC_C_SAIL0 + (uint32_t)xYieldCoreId, 31U, 31U );
}
#endif /* #if ( configNUMBER_OF_CORES > 1 ) */
/*-----------------------------------------------------------*/

#if ( configNUMBER_OF_CORES > 1 )
void vPortYieldCoreCB( IPCC_CBData nData, IPCC_Client eSenderID, IPCC_Signal nSignal )
{
    portYIELD_FROM_ISR( pdTRUE );
}
#endif /* #if ( configNUMBER_OF_CORES > 1 ) */
/*-----------------------------------------------------------*/

#if ( configNUMBER_OF_CORES > 1 )
static void vPortSmpIpccRegister(uint32_t ulCoreId)
{
    uint32_t ulRegCoreId;
    
    IPCC_AttachEx( &xFreertosSmp_IpccHandle[ulCoreId], IPCC_P_SAIL_MPROC, (IPCC_Client)(IPCC_C_SAIL0 + ulCoreId), ulCoreId );

    for(ulRegCoreId = 0; ulRegCoreId < configNUMBER_OF_CORES; ulRegCoreId++)
    {
        IPCC_RegisterInterrupt( xFreertosSmp_IpccHandle[ulCoreId], (IPCC_Client)IPCC_C_SAIL0 + ulRegCoreId, 31U, 31U, (IPCC_CB)vPortYieldCoreCB, (IPCC_CBData)&ulCoreId);
    }

}
#endif /* #if ( configNUMBER_OF_CORES > 1 ) */
/*-----------------------------------------------------------*/

/*
 * See header file for description.
 */
StackType_t * pxPortInitialiseStack( StackType_t * pxTopOfStack,
                                     TaskFunction_t pxCode,
                                     void * pvParameters )
{
    /*
     * Setup the initial stack of the task.  The stack is set exactly as
     * expected by the portRESTORE_CONTEXT() macro.
     *
     * The fist real value on the stack is the status register, which is set for
     * system mode, with interrupts enabled.  A few NULLs are added first to ensure
     * GDB does not try decoding a non-existent return address.
     */
    *pxTopOfStack = ( StackType_t ) NULL;
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t ) NULL;
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t ) NULL;
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t ) portINITIAL_SPSR;

    if( ( ( uint32_t ) pxCode & portTHUMB_MODE_ADDRESS ) != 0x00UL )
    {
        /* The task will start in THUMB mode. */
        *pxTopOfStack |= portTHUMB_MODE_BIT;
    }

    pxTopOfStack--;

    /* Next the return address, which in this case is the start of the task. */
    *pxTopOfStack = ( StackType_t ) pxCode;
    pxTopOfStack--;

    /* Next all the registers other than the stack pointer. */
    *pxTopOfStack = ( StackType_t ) portTASK_RETURN_ADDRESS; /* R14 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t ) 0x12121212;              /* R12 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t ) 0x11111111;              /* R11 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t ) 0x10101010;              /* R10 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t ) 0x09090909;              /* R9 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t ) 0x08080808;              /* R8 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t ) 0x07070707;              /* R7 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t ) 0x06060606;              /* R6 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t ) 0x05050505;              /* R5 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t ) 0x04040404;              /* R4 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t ) 0x03030303;              /* R3 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t ) 0x02020202;              /* R2 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t ) 0x01010101;              /* R1 */
    pxTopOfStack--;
    *pxTopOfStack = ( StackType_t ) pvParameters;            /* R0 */

    /*
     * The task will start with a critical nesting count of 0 as interrupts are
     * enabled.
     */
    pxTopOfStack--;
    *pxTopOfStack = portNO_CRITICAL_NESTING;

    #if ( configUSE_TASK_FPU_SUPPORT == 1 )
    {
        /*
         * The task will start without a floating point context.
         * A task that uses the floating point hardware must call
         * vPortTaskUsesFPU() before executing any floating point
         * instructions.
         */
        pxTopOfStack--;
        *pxTopOfStack = portNO_FLOATING_POINT_CONTEXT;
    }
    #elif ( configUSE_TASK_FPU_SUPPORT == 2 )
    {
        /*
         * The task will start with a floating point context. Leave enough
         * space for the registers and ensure they are initialized to 0.
         */
        pxTopOfStack -= portFPU_REGISTER_WORDS;
        memset( pxTopOfStack, 0x00, portFPU_REGISTER_WORDS * sizeof( StackType_t ) );

        pxTopOfStack--;
        *pxTopOfStack = pdTRUE;
        ulPortTaskHasFPUContext = pdTRUE;
    }
    #elif ( configUSE_TASK_FPU_SUPPORT != 0 )
    {
        #error Invalid configUSE_TASK_FPU_SUPPORT setting - configUSE_TASK_FPU_SUPPORT must be set to 0, 1, or 2.
    }
    #endif /* configUSE_TASK_FPU_SUPPORT */

    return pxTopOfStack;
}
/*-----------------------------------------------------------*/

static void prvTaskExitError( void )
{
    /*
     * A function that implements a task must not exit or attempt to return to
     * its caller as there is nothing to return to.  If a task wants to exit it
     * should instead call vTaskDelete( NULL ).
     *
     * Artificially force an assert() to be triggered if configASSERT() is
     * defined, then stop here so application writers can catch the error.
     */
    #if ( configNUMBER_OF_CORES > 1 )
        configASSERT( ulPortInterruptNesting[ portGET_CORE_ID() ] == ~0UL );
    #else
        configASSERT( ulPortInterruptNesting == ~0UL );
    #endif
    
    portDISABLE_INTERRUPTS();

    for( ; ; )
    {
    }
}
/*-----------------------------------------------------------*/

#if ( configUSE_TASK_FPU_SUPPORT != 0 )

    void vApplicationFPUSafeIRQHandler( uint32_t ulICCIAR ) /* __attribute__( ( weak ) ) */
    {
        ( void ) ulICCIAR;
        configASSERT( ( volatile void * ) NULL );
    }

#endif /* configUSE_TASK_FPU_SUPPORT != 0 */
/*-----------------------------------------------------------*/

BaseType_t xPortStartScheduler( void )
{
    uint32_t ulAPSR = 8; /* 8 bits per byte. */
    uint32_t currentCoreID = portGET_CORE_ID();

    /*
     * Only continue if the CPU is not in User mode.  The CPU must be in a
     * Privileged mode for the scheduler to start.
     */
    __asm volatile ( "MRS %0, APSR" : "=r" ( ulAPSR )::"memory" );
    ulAPSR &= portAPSR_MODE_BITS_MASK;
    configASSERT( ulAPSR != portAPSR_USER_MODE );

    if( ulAPSR != portAPSR_USER_MODE )
    {
        //TODO: add bitpoint and priority stuck-at check.

        /*
        * Interrupts are turned off in the CPU itself to ensure tick does
        * not execute  while the scheduler is being started.  Interrupts are
        * automatically turned back on in the CPU when the first task starts
        * executing.
        */
        portCPU_IRQ_DISABLE();

        #if ( configNUMBER_OF_CORES > 1 )
            if ( currentCoreID == configTICK_CORE )
            {
                /* Start the timer that generates the tick ISR. Only on Primary core for SMP
                 * Interrupts are disabled here already.*/
                configSETUP_TICK_INTERRUPT();
            }
        #else
            /* Start the timer that generates the tick ISR. */
            configSETUP_TICK_INTERRUPT();
        #endif /* #if ( configNUMBER_OF_CORES > 1 ) */

        #if ( configNUMBER_OF_CORES > 1 )

            /*Register the IPCC interrupts to yeild secondary cores*/
            vPortSmpIpccRegister( currentCoreID );

        #endif /* #if ( configNUMBER_OF_CORES > 1 ) */

        #if ( configNUMBER_OF_CORES > 1 )

        if ( currentCoreID % (uint32_t)configNUMBER_OF_CORES_PER_CLUSTER == 0U )
        {
            uint32_t clusterConfig = sailbsp_get_capt_sec_gpio_val();
            uint32_t currentCluster = (uint32_t) currentCoreID/configNUMBER_OF_CORES_PER_CLUSTER;
            if ( (portCLUSTER_1_ID == (clusterConfig & portCLUSTER_1_ID)) && (currentCluster == (portCLUSTER_1_ID - 1U)) )
            {
                ulCluster1LockStep = 1U;
            }
            else if ( (portCLUSTER_2_ID == (clusterConfig & portCLUSTER_2_ID)) && (currentCluster == (portCLUSTER_2_ID - 1U)) )
            {
                ulCluster2LockStep = 1U;
            }
        } 
        
        ulPortStartSchedulerSync = ( ulPortStartSchedulerSync | ( pdPASS << portGET_CORE_ID() ) ); 
                
        while( ulPortStartSchedulerSync != portSTART_SCHEDULAR_BITS ){};

        #endif /* #if ( configNUMBER_OF_CORES > 1 ) */

        /* Start the first task executing. */
        vPortRestoreTaskContext();
    }

    /*
     * Will only get here if vTaskStartScheduler() was called with the CPU in
     * a non-privileged mode or the binary point register was not set to its lowest
     * possible value.  prvTaskExitError() is referenced to prevent a compiler
     * warning about it being defined but not referenced in the case that the user
     * defines their own exit address.
     */
    ( void ) prvTaskExitError;

    return 0;
}
/*-----------------------------------------------------------*/

void vPortEndScheduler( void )
{
    /*
     * Not implemented in ports where there is nothing to return to.
     * Artificially force an assert.
     */
    configASSERT( ulCriticalNesting == 1000UL );
}
/*-----------------------------------------------------------*/

#if ( configNUMBER_OF_CORES == 1 )
void vPortEnterCritical( void )
{
    /* Mask interrupts up to the max syscall interrupt priority. */
    ulPortSetInterruptMask();

    /*
     * Now that interrupts are disabled, ulCriticalNesting can be accessed
     * directly.  Increment ulCriticalNesting to keep a count of how many times
     * portENTER_CRITICAL() has been called.
     */
    ulCriticalNesting++;

    /*
     * This is not the interrupt safe version of the enter critical function so
     * assert() if it is being called from an interrupt context.  Only API
     * functions that end in "FromISR" can be used in an interrupt.  Only assert if
     * the critical nesting count is 1 to protect against recursive calls if the
     * assert function also uses a critical section.
     */
    if( ulCriticalNesting == 1 )
    {
        configASSERT( ulPortInterruptNesting == 0 );
    }
}
#endif /* #if ( configNUMBER_OF_CORES == 1 ) */
/*-----------------------------------------------------------*/

#if ( configNUMBER_OF_CORES == 1 )
void vPortExitCritical( void )
{
    if( ulCriticalNesting > portNO_CRITICAL_NESTING )
    {
        /* Decrement the nesting count as the critical section is being exited. */
        ulCriticalNesting--;

        /*
         * If the nesting level has reached zero then all interrupt
         * priorities must be re-enabled.
         */
        if( ulCriticalNesting == portNO_CRITICAL_NESTING )
        {
            /*
             * Critical nesting has reached zero so all interrupt priorities
             * should be unmasked.
             */
            portCLEAR_INTERRUPT_MASK_GENERIC();
        }
    }
}
#endif /* #if ( configNUMBER_OF_CORES == 1 ) */
/*-----------------------------------------------------------*/

#if ( configNUMBER_OF_CORES > 1 )
void FreeRTOS_Tick_Handler( void )
{
    uint32_t currentCoreID = portGET_CORE_ID();
    /*
     * Set interrupt mask before altering scheduler structures.   The tick
     * handler runs at the lowest priority, so interrupts cannot already be masked,
     * so there is no need to save and restore the current mask value.  It is
     * necessary to turn off interrupts in the CPU itself while the ICCPMR is being
     * updated.
     */
    portCPU_IRQ_DISABLE();
    uint32_t ulIccPmrVal = ( uint32_t ) ( configMAX_API_CALL_INTERRUPT_PRIORITY << portPRIORITY_SHIFT );
    __asm volatile ( "mcr p15, 0, %0, c4, c6, 0":  :"r" (ulIccPmrVal));
    __asm volatile ( "dsb       \n"
                     "isb       \n" ::: "memory" );
    portCPU_IRQ_ENABLE();

    /* Yield other cores (not tick core which is core0) */
    for(uint32_t yieldcore_num = 0; yieldcore_num < (uint32_t)configNUMBER_OF_CORES; yieldcore_num++)
    {
        if ( yieldcore_num != currentCoreID )
        {
            portYIELD_CORE(yieldcore_num);
        }
    }

    /* Increment the RTOS tick. */
    if( xTaskIncrementTick() != pdFALSE )
    {
        ulPortYieldRequired[ currentCoreID ] = pdTRUE;
    }

    /* Ensure all interrupt priorities are active again. */
    portCLEAR_INTERRUPT_MASK_GENERIC();
    configCLEAR_TICK_INTERRUPT();
}

#else
void FreeRTOS_Tick_Handler( void )
{
    /*
     * Set interrupt mask before altering scheduler structures.   The tick
     * handler runs at the lowest priority, so interrupts cannot already be masked,
     * so there is no need to save and restore the current mask value.  It is
     * necessary to turn off interrupts in the CPU itself while the ICCPMR is being
     * updated.
     */
    portCPU_IRQ_DISABLE();
    uint32_t ulIccPmrVal = ( uint32_t ) ( configMAX_API_CALL_INTERRUPT_PRIORITY << portPRIORITY_SHIFT );
    __asm volatile ( "mcr p15, 0, %0, c4, c6, 0":  :"r" (ulIccPmrVal));
    __asm volatile ( "dsb       \n"
                     "isb       \n" ::: "memory" );
    portCPU_IRQ_ENABLE();

    /* Increment the RTOS tick. */
    if( xTaskIncrementTick() != pdFALSE )
    {
        ulPortYieldRequired = pdTRUE;
    }

    /* Ensure all interrupt priorities are active again. */
    portCLEAR_INTERRUPT_MASK_GENERIC();
    configCLEAR_TICK_INTERRUPT();
}
#endif

/*-----------------------------------------------------------*/

#if ( configUSE_TASK_FPU_SUPPORT == 1 )

    void vPortTaskUsesFPU( void )
    {
        uint32_t ulInitialFPSCR = 0;

        /*
         * A task is registering the fact that it needs an FPU context. Set the
         * FPU flag (which is saved as part of the task context).
         */
        ulPortTaskHasFPUContext = pdTRUE;

        /* Initialise the floating point status register. */
        __asm volatile ( "FMXR  FPSCR, %0" ::"r" ( ulInitialFPSCR ) : "memory" );
    }

#endif /* configUSE_TASK_FPU_SUPPORT == 1 */
/*-----------------------------------------------------------*/


//TODO : Need to use common logic between GNU and FUSA for INTR masking

#if defined(__ARM_GNU__)



void vPortClearInterruptMask( uint32_t ulSavedCpsrState )
{
    /* Interrupts must be masked while ICCPMR is updated. */
    portCPU_IRQ_DISABLE();
    __asm volatile ( "mcr p15, 0, %0, c4, c6, 0":  :"r" ( (uint32_t)portUNMASK_VALUE) );
    __asm volatile ( "dsb       \n"
                     "isb       \n" ::: "memory" );

    /* If Interrupts are masked prior to unmasking do not re-enable Interrupts. */
    /* After clearing the interrupt priority mask. Restore the CPSR, to make sure interrupt mask for CPU IRQ is set to the original state. */
    __asm volatile ( "msr cpsr, %0" :  :"r" ( ulSavedCpsrState ) :);
    __asm volatile ( "dsb       \n"
                     "isb       \n" ::: "memory" );
}
/*-----------------------------------------------------------*/

uint32_t ulPortSetInterruptMask( void )
{
    uint32_t ulIccPmrVal;
    uint32_t ulSavedCpsrState;

    /* Read CPSR to check the interrupt mask status. */
    __asm volatile ( "mrs %0, cpsr" : "=r" ( ulSavedCpsrState )::);

    /* Interrupts must be masked while ICCPMR is updated. */
    portCPU_IRQ_DISABLE();

    __asm volatile ( "mrc p15, 0, %0, c4, c6, 0": "=r" (ulIccPmrVal) : );

    if( ulIccPmrVal != ( uint32_t ) ( configMAX_API_CALL_INTERRUPT_PRIORITY << portPRIORITY_SHIFT ) )
    {
        /* Set interrupt priority mask (ICCPMR). */
        ulIccPmrVal = ( uint32_t ) ( configMAX_API_CALL_INTERRUPT_PRIORITY << portPRIORITY_SHIFT );
        __asm volatile ( "mcr p15, 0, %0, c4, c6, 0":  :"r" (ulIccPmrVal));
        __asm volatile ( "dsb       \n"
                         "isb       \n" ::: "memory" );
    }

    /* If Interrupts are masked prior to setting interrupt mask do not re-enable Interrupts. */
    /* After setting the interrupt priority mask. Restore the CPSR, to make sure interrupt mask for CPU IRQ is set to the original state. */
    __asm volatile ( "msr cpsr, %0" :  :"r" ( ulSavedCpsrState ) :);
    __asm volatile ( "dsb       \n"
                     "isb       \n" ::: "memory" );

    return ulSavedCpsrState;
}
/*-----------------------------------------------------------*/

void vPortDisableInterrupts( void )
{
    portCPU_IRQ_DISABLE();
}
/*-----------------------------------------------------------*/

void vPortEnableInterrupts( void )
{
    portCPU_IRQ_ENABLE();
}




#elif defined(__ARM_FUSA__)
void vPortClearInterruptMask( uint32_t ulNewMaskValue )
{   
    uint32_t ulCpsrState;

    /* Read CPSR to check the interrupt mask status. */
    __asm volatile ( "mrs %0, cpsr" : "=r" ( ulCpsrState )::);

    if( ulNewMaskValue == pdFALSE )
    {
        portCPU_IRQ_DISABLE();
        __asm volatile ( "mcr p15, 0, %0, c4, c6, 0":  :"r" ( (uint32_t)portUNMASK_VALUE) );
        __asm volatile ( "dsb       \n"
                         "isb       \n" ::: "memory" );
    }

    /* If Interrupts are masked prior to unmasking do not re-enable Interrupts. */
    ulCpsrState &= portCPSR_IRQ_MASK;
    if (ulCpsrState != portCPSR_IRQ_MASK)
    {
        portCPU_IRQ_ENABLE();
    }
}
/*-----------------------------------------------------------*/

uint32_t ulPortSetInterruptMask( void )
{
    uint32_t ulReturn;
    uint32_t ulIccPmrVal;
    uint32_t ulCpsrState;

    /* Read CPSR to check the interrupt mask status. */
    __asm volatile ( "mrs %0, cpsr" : "=r" ( ulCpsrState )::);

    /* Interrupts must be masked while ICCPMR is updated. */
    portCPU_IRQ_DISABLE();

    __asm volatile ( "mrc p15, 0, %0, c4, c6, 0": "=r" (ulIccPmrVal) : );

    if( ulIccPmrVal == ( uint32_t ) ( configMAX_API_CALL_INTERRUPT_PRIORITY << portPRIORITY_SHIFT ) )
    {
        /* Interrupts were already masked. */
        ulReturn = pdTRUE;
    }
    else
    {
        ulReturn = pdFALSE;
        ulIccPmrVal = ( uint32_t ) ( configMAX_API_CALL_INTERRUPT_PRIORITY << portPRIORITY_SHIFT );
        __asm volatile ( "mcr p15, 0, %0, c4, c6, 0":  :"r" (ulIccPmrVal));
        __asm volatile ( "dsb       \n"
                         "isb       \n" ::: "memory" );
    }

    /* If Interrupts are masked prior to setting interrupt mask do not re-enable Interrupts. */
    ulCpsrState &= portCPSR_IRQ_MASK;
    if (ulCpsrState != portCPSR_IRQ_MASK)
    {
        portCPU_IRQ_ENABLE();
    }

    return ulReturn;
}
#endif
/*-----------------------------------------------------------*/

#if ( configASSERT_DEFINED == 1 )

    void vPortValidateInterruptPriority( void )
    {
        /*
         * The following assertion will fail if a service routine (ISR) for
         * an interrupt that has been assigned a priority above
         * configMAX_SYSCALL_INTERRUPT_PRIORITY calls an ISR safe FreeRTOS API
         * function.  ISR safe FreeRTOS API functions must *only* be called
         * from interrupts that have been assigned a priority at or below
         * configMAX_SYSCALL_INTERRUPT_PRIORITY.
         *
         * Numerically low interrupt priority numbers represent logically high
         * interrupt priorities, therefore the priority of the interrupt must
         * be set to a value equal to or numerically *higher* than
         * configMAX_SYSCALL_INTERRUPT_PRIORITY.
         *
         * FreeRTOS maintains separate thread and ISR API functions to ensure
         * interrupt entry is as fast and simple as possible.
         */

        configASSERT( portICCRPR_RUNNING_PRIORITY_REGISTER >= ( uint32_t ) ( configMAX_API_CALL_INTERRUPT_PRIORITY << portPRIORITY_SHIFT ) );

        /*
         * Priority grouping:  The interrupt controller (GIC) allows the bits
         * that define each interrupt's priority to be split between bits that
         * define the interrupt's pre-emption priority bits and bits that define
         * the interrupt's sub-priority.  For simplicity all bits must be defined
         * to be pre-emption priority bits.  The following assertion will fail if
         * this is not the case (if some bits represent a sub-priority).
         *
         * The priority grouping is configured by the GIC's binary point register
         * (ICCBPR).  Writing 0 to ICCBPR will ensure it is set to its lowest
         * possible value (which may be above 0).
         */
        configASSERT( ( portICCBPR_BINARY_POINT_REGISTER & portBINARY_POINT_BITS ) <= portMAX_BINARY_POINT_VALUE );
    }

#endif /* configASSERT_DEFINED */
/*-----------------------------------------------------------*/

#if (configSUPPORT_STATIC_ALLOCATION == 1)
/* vApplicationGetIdleTaskMemory() Hook.
 * configKERNEL_PROVIDED_STATIC_MEMORY is set to 0.
 * configSUPPORT_STATIC_ALLOCATION is set to 1, so application need
 * to provide the memory that is used by the Idle task,
 */
static StaticTask_t xIdleTaskTCB;
static StackType_t  uxIdleTaskStack[ configMINIMAL_STACK_SIZE ];
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer,
                                    StackType_t **ppxIdleTaskStackBuffer,
                                    configSTACK_DEPTH_TYPE * puxIdleTaskStackSize )
{
    *ppxIdleTaskTCBBuffer = &( xIdleTaskTCB );
    *ppxIdleTaskStackBuffer = &( uxIdleTaskStack[ 0 ] );
    *puxIdleTaskStackSize = configMINIMAL_STACK_SIZE; //Stack size is expressed in terms of Words, not bytes.
}

static StaticTask_t xIdleTaskTCBs[ configNUMBER_OF_CORES ];
static StackType_t uxIdleTaskStacks[ configNUMBER_OF_CORES ][ configMINIMAL_STACK_SIZE ];
void vApplicationGetPassiveIdleTaskMemory( StaticTask_t ** ppxIdleTaskTCBBuffer,
                                           StackType_t ** ppxIdleTaskStackBuffer,
                                           configSTACK_DEPTH_TYPE * puxIdleTaskStackSize,
                                           BaseType_t xPassiveIdleTaskIndex )
{


    *ppxIdleTaskTCBBuffer = &( xIdleTaskTCBs[ xPassiveIdleTaskIndex ] );
    *ppxIdleTaskStackBuffer = &( uxIdleTaskStacks[ xPassiveIdleTaskIndex ][ 0 ] );
    *puxIdleTaskStackSize = configMINIMAL_STACK_SIZE; //Stack size is expressed in terms of Words, not bytes.
}

/*-----------------------------------------------*/
/* vApplicationGetTimerTaskMemory() Hook.
 * configKERNEL_PROVIDED_STATIC_MEMORY is set to 0.
 * configSUPPORT_STATIC_ALLOCATION and configUSE_TIMERS are set to 1, so the
 * application need to provide the memory that is used by the Timer service task. 
 */
static StaticTask_t xTimerTaskTCB;
static StackType_t  uxTimerTaskStack[ configTIMER_TASK_STACK_DEPTH ];
void vApplicationGetTimerTaskMemory( StaticTask_t **ppxTimerTaskTCBBuffer,
                                     StackType_t **ppxTimerTaskStackBuffer,
                                     configSTACK_DEPTH_TYPE * puxTimerTaskStackSize )
{
    *ppxTimerTaskTCBBuffer = &( xTimerTaskTCB );
    *ppxTimerTaskStackBuffer = &( uxTimerTaskStack[ 0 ] );
    *puxTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH; //Stack size is expressed in terms of Words, not bytes.
}
#endif
/*-----------------------------------------------------------*/

/* Application Hook Funcations */

void vApplicationTickHook( void )
{
}
/*-----------------------------------------------------------*/

void vApplicationSetupTickInterrupt( void )
{
}
/*-----------------------------------------------------------*/

void vApplicationClearTickInterrupt( void )
{
}
/*-----------------------------------------------------------*/

void vApplicationStackOverflowHook( TaskHandle_t xTask, char *pcTaskName )
{
    portUNUSED_PARAMETER( xTask );
    portUNUSED_PARAMETER( pcTaskName );
    
    /* Disable interrupts to avoid further context switch */
    portDISABLE_INTERRUPTS();

    for( ;; );
}
/*-----------------------------------------------------------*/

void vApplicationIdleHook( void )
{
}
/*-----------------------------------------------------------*/

void vApplicationMallocFailedHook( void )
{
    for( ;; );
}
/*-----------------------------------------------------------*/

/* End of File */
