/*
 * FreeRTOS Kernel v11.0.1
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
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

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#define configUSE_PREEMPTION                    ( 1U )
#define configUSE_PORT_OPTIMISED_TASK_SELECTION ( 0U )
#define configUSE_TICKLESS_IDLE                 ( 0U )
#define configCPU_CLOCK_HZ                      ( 19200000UL )
//#define configSYSTICK_CLOCK_HZ                  1000000
#define configTICK_RATE_HZ                      ( 1000U )
#define configMAX_PRIORITIES                    ( 11U )
#define configMINIMAL_STACK_SIZE                ( 1024U )
#define configMAX_TASK_NAME_LEN                 ( 16U )
#define configUSE_16_BIT_TICKS                  ( 0U )
#define configIDLE_SHOULD_YIELD                 ( 1U )
#define configUSE_TASK_NOTIFICATIONS            ( 1U )
#define configTASK_NOTIFICATION_ARRAY_ENTRIES   ( 3U )
#define configUSE_MUTEXES                       ( 1U )
#define configUSE_RECURSIVE_MUTEXES             ( 1U )
#define configUSE_COUNTING_SEMAPHORES           ( 1U )
#define configUSE_ALTERNATIVE_API               ( 0U ) /* Deprecated! */
#define configQUEUE_REGISTRY_SIZE               ( 0U )
#define configUSE_QUEUE_SETS                    ( 0U )
#define configUSE_TIME_SLICING                  ( 1U )
#define configUSE_NEWLIB_REENTRANT              ( 0U )
#define configENABLE_BACKWARD_COMPATIBILITY     ( 0U )
#define configNUM_THREAD_LOCAL_STORAGE_POINTERS ( 5U )
#define configUSE_MINI_LIST_ITEM                ( 1U )
#define configSTACK_DEPTH_TYPE                  uint32_t /* configSTACK_DEPTH_TYPE V11.0.1 : uint32_t, TODO: check v11.1.0+ : default - StackType_t, and if it can be reduced to uint16_t */
//#define configMESSAGE_BUFFER_LENGTH_TYPE        ( size_t )
#define configHEAP_CLEAR_MEMORY_ON_FREE         ( 1U )

/* SMP specific */
#define configNUM_SMP_SUPPORTED_CORES           ( 4U )
#define configNUM_CORES                         ( configNUM_SMP_SUPPORTED_CORES ) // deprecated actually..
#define configNUMBER_OF_CORES                   ( configNUM_SMP_SUPPORTED_CORES )
#define configNUMBER_OF_CORES_PER_CLUSTER       ( 2U ) // Number of Cores per GIC Cluster.
#define configNUMBER_OF_CLUSTERS                ( 2U ) // Number of GIC Cluster Instances.
#define configUSE_CORE_AFFINITY                 ( 1U )
#define configRUN_MULTIPLE_PRIORITIES           ( 1U )
#define configUSE_MINIMAL_IDLE_HOOK             ( 0U )
#define configUSE_TASK_PREEMPTION_DISABLE       ( 1U )
#define configUSE_PASSIVE_IDLE_HOOK             ( 1U )
#define configTICK_CORE                         ( 0U )
#define portCRITICAL_NESTING_IN_TCB             ( 1U )

/* Memory allocation related definitions. */
#define configSUPPORT_STATIC_ALLOCATION             ( 1U )
#define configSUPPORT_DYNAMIC_ALLOCATION            ( 0U ) //For TCP/IP Stack use it for Sockets. //Remove for SMP build
#define configTOTAL_HEAP_SIZE                       ( 0x10000U )
#define configAPPLICATION_ALLOCATED_HEAP            ( 1U )
#define configSTACK_ALLOCATION_FROM_SEPARATE_HEAP   ( 0U )

/* Hook function related definitions. */
#define configUSE_IDLE_HOOK                     ( 1U )
#define configUSE_TICK_HOOK                     ( 1U )
#define configCHECK_FOR_STACK_OVERFLOW          ( 2U )
#define configUSE_MALLOC_FAILED_HOOK            ( 1U )
#define configUSE_DAEMON_TASK_STARTUP_HOOK      ( 0U )
#define configUSE_SB_COMPLETED_CALLBACK         ( 1U )

/* Run time and task stats gathering related definitions. */
#define configGENERATE_RUN_TIME_STATS           ( 0U )
#define configUSE_TRACE_FACILITY                ( 1U )
#define configUSE_STATS_FORMATTING_FUNCTIONS    ( 0U )
// #define portCONFIGURE_TIMER_FOR_RUN_TIME_STATS ()
// #define portGET_RUN_TIME_COUNTER_VALUE()
#define configUSE_TASK_FPU_SUPPORT ( 2U )
#define configENABLE_FPU ( 1U )

/* Co-routine related definitions. */
#define configUSE_CO_ROUTINES                   ( 0U )
#define configMAX_CO_ROUTINE_PRIORITIES         ( 0U )

/* Software timer related definitions. */
#define configUSE_TIMERS                        ( 1U )
#define configTIMER_TASK_PRIORITY               ( 5U )
#define configTIMER_QUEUE_LENGTH                ( 25U )
#define configTIMER_TASK_STACK_DEPTH            ( 1024U )

/* Interrupt nesting behaviour configuration. */
#define configKERNEL_INTERRUPT_PRIORITY         ( 0x00U )
#define configMAX_SYSCALL_INTERRUPT_PRIORITY    ( 0x00U )
#define configMAX_API_CALL_INTERRUPT_PRIORITY   ( 0x00U )

/* FreeRTOS MPU specific definitions. */
#define configENABLE_MPU                                       ( 0U )
#define portUSING_MPU_WRAPPERS                                 ( 0U )
#define MPU_WRAPPERS_INCLUDED_FROM_API_FILE
#define portNUM_CONFIGURABLE_REGIONS                           ( 6U )
#define portPRIVILEGE_BIT                                      ( 0U )
#define configINCLUDE_APPLICATION_DEFINED_PRIVILEGED_FUNCTIONS ( 0U )
#define configTOTAL_MPU_REGIONS                                ( 16U )
//#define configTEX_S_C_B_FLASH                                  0x07UL /* Default value. */
//#define configTEX_S_C_B_SRAM                                   0x07UL /* Default value. */
#define configENFORCE_SYSTEM_CALLS_FROM_KERNEL_ONLY            ( 1U )
#define configALLOW_UNPRIVILEGED_CRITICAL_SECTIONS             ( 1U )
#define configENABLE_ERRATA_837070_WORKAROUND   ( 1U )

/* Secure side port related definitions. */
#define secureconfigMAX_SECURE_CONTEXTS         ( 0U )

/* If configTASK_RETURN_ADDRESS is not defined then a task that attempts to
return from its implementing function will end up in a "task exit error"
function - which contains a call to configASSERT().  However this can give GCC
some problems when it tries to unwind the stack, as the exit error function has
nothing to return to.  To avoid this define configTASK_RETURN_ADDRESS to 0.  */
#undef configTASK_RETURN_ADDRESS

/* Optional functions - most linkers will remove unused functions anyway. */
#define INCLUDE_vTaskPrioritySet                1
#define INCLUDE_uxTaskPriorityGet               1
#define INCLUDE_vTaskDelete                     1
#define INCLUDE_vTaskSuspend                    1
#define INCLUDE_xResumeFromISR                  1
#define INCLUDE_vTaskDelayUntil                 1
#define INCLUDE_vTaskDelay                      1
#define INCLUDE_xTaskGetSchedulerState          1
#define INCLUDE_xTaskGetCurrentTaskHandle       1
#define INCLUDE_uxTaskGetStackHighWaterMark     0
#define INCLUDE_uxTaskGetStackHighWaterMark2    1
#define INCLUDE_xTaskGetIdleTaskHandle          1
#define INCLUDE_eTaskGetState                   1
#define INCLUDE_xEventGroupSetBitFromISR        1
#define INCLUDE_xTimerPendFunctionCall          1
#define INCLUDE_xTaskAbortDelay                 1
#define INCLUDE_xTaskGetHandle                  1
#define INCLUDE_xTaskResumeFromISR              1

/*
 * The application must provide a function that configures a peripheral to
 * create the FreeRTOS tick interrupt, then define configSETUP_TICK_INTERRUPT()
 * in FreeRTOSConfig.h to call the function. FreeRTOS_Tick_Handler() must
 * be installed as the peripheral's interrupt handler.
 */
//void vConfigureTickInterrupt( void );
#define configSETUP_TICK_INTERRUPT()        vApplicationSetupTickInterrupt()

//void vClearTickInterrupt( void );
#define configCLEAR_TICK_INTERRUPT()        vApplicationClearTickInterrupt()

/* The following constant describe the hardware GIC */
#define configUNIQUE_INTERRUPT_PRIORITIES				32
#define configINTERRUPT_CONTROLLER_BASE_ADDRESS ( 0 )
#define configINTERRUPT_CONTROLLER_CPU_INTERFACE_OFFSET ( 0 )


//TODO: Add Linker Tags, once MPU support is available.

#endif /* FREERTOS_CONFIG_H */