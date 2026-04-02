/**************************************************************************************************
** Copyright (c) 2022-2025 Qualcomm Technologies, Inc.                                           **
** All Rights Reserved.                                                                          **
** Confidential and Proprietary - Qualcomm Technologies, Inc.                                    **
**************************************************************************************************/

/*=================================================================================================
    File Name          : sailfreertos_init.c
    Component Name     : sailfreertos
    Description        : FreeRTOS initialization file
    $Header:  $
    $DateTime: 2022/03/11 01:34:19 $
    $Author:  $
=================================================================================================*/

/*=================================================================================================
**                                        Include files                                          **
=================================================================================================*/
#include <stdio.h>
#include <stdint.h>
#include "types.h"
#include "HALhwio.h"
#include "common_functions.h"
#include "isd.h"
#include "tests.h"
#include "busywait.h"
#include "debug_log.h"
#include "syscall.h"
#include "syscall_svc.h"
#include "sail_updater_el1.h"
#include "psail.h"

//#include "pmicSafeRtos.h"
#include "sleepSafeRtos.h"

#include "boot_logger.h"

#include "ddrmilestone.h"

#include "Clock.h"
#include "arm64.h"
#include "err_fatal.h"
#include "sailbsp_mutex.h"

#include "spinor_el1_api.h"
#include "boot.h"
#include "icb_error.h"


#include "freertos_init.h"

#include "isd.h"
#include "syscall_svc.h"
#include "Spi_Task.h"
#include "Can_Task.h"
#include "tests.h"
#include "Can_Mailbox_Task.h"
#include "FreeRTOSOsal.h"

#include "Crashdbg_api.h"
#include "arch_ops.h"
#include "interrupts.h"


/*=================================================================================================
**                                        Local defines and macros                               **
=================================================================================================*/

/* Scheduler initialisation definitions. */
#define configSTACK_CHECK_MARGIN            ( 0U )

/* User configuration for the idle task. */
#define configIDLE_TASK_STACK_SIZE          ( 1024U )

/* User configuration for the timer task. */
#define configTIMER_TASK_STACK_SIZE         ( 1024U )

/* Virtual Timer Interrupt */
#define VIRTAUL_TIMER_PPI_ID                ( 27U )
/*=================================================================================================
**                                        Global variables and constants                         **
=================================================================================================*/
 static volatile BaseType_t ulTickHookCallCount;

 static uint32_t xIdleTaskCounter      = 0U;
 static uint32_t xPassiveIdleTaskCounter      = 0U;

SemaphoreHandle_t  pxMutexHandleSVCParmAdd   = NULL ;
static StaticSemaphore_t pxMutexHandleSVCParmAddBuffer;

typedef BaseType_t ( * pSAILTaskInitType ) ( CPUIdType_e           xSchdCore,
                                               UBaseType_t  xTaskPrior );

typedef BaseType_t ( * pSAILCommResourcesInitType ) (CPUIdType_e xSchdCore);

typedef struct
{
    CPUIdType_e                xSchdCore;
    TaskPriorityType_e         xTaskPrior;
    pSAILTaskInitType          pTaskInitFunc;
    pSAILCommResourcesInitType pTaskResourcesInitFunc;
}FreertosTaskSchedulingTableType;

/* Mutex lock address for task and isr locking */
mutex_t     *pxFreeRTOSLock[]          = { (mutex_t*)FREERTOS_TASK_LOCK_MEM_ADD, (mutex_t*)FREERTOS_ISR_LOCK_MEM_ADD };

//Heap Initialization 
//SAIL_FREERTOS_HEAP static uint8_t ucHeap[ configTOTAL_HEAP_SIZE ];

#define CPU0_TASKS_DISABLED
#define CPU1_TASKS_DISABLED
#define CPU2_TASKS_DISABLED
#define CPU3_TASKS_DISABLED

#define DUMMY_TASK_STACK_SIZE    ( 2048 )
TaskHandle_t xDummy1TaskHandle = NULL;
static StackType_t xDummy1TaskStack[DUMMY_TASK_STACK_SIZE]  __attribute__((aligned(MEM_ALIGNMENT_64))) = { 0 };
static StaticTask_t xDummy1TaskTCB = { 0 };

TaskHandle_t xDummy2TaskHandle = NULL;
static StackType_t xDummy2TaskStack[DUMMY_TASK_STACK_SIZE]  __attribute__((aligned(MEM_ALIGNMENT_64))) = { 0 };
static StaticTask_t xDummy2TaskTCB = { 0 };

TaskHandle_t xDummy3TaskHandle = NULL;
static StackType_t xDummy3TaskStack[DUMMY_TASK_STACK_SIZE]  __attribute__((aligned(MEM_ALIGNMENT_64))) = { 0 };
static StaticTask_t xDummy3TaskTCB = { 0 };

/*=================================================================================================
**                                 Local Functions Declarations                                  **
=================================================================================================*/
BaseType_t xDummy1TaskInit( CPUIdType_e           xSchdCore,
		UBaseType_t  xTaskPrior );

BaseType_t xDummy2TaskInit( CPUIdType_e           xSchdCore,
		UBaseType_t  xTaskPrior );

BaseType_t xDummy3TaskInit( CPUIdType_e           xSchdCore,
		UBaseType_t  xTaskPrior );
BaseType_t xSAILshellTaskInit_core0( CPUIdType_e           xSchdCore,
		UBaseType_t  xTaskPrior );
BaseType_t xSAILshellTaskInit_core1( CPUIdType_e           xSchdCore,
		UBaseType_t  xTaskPrior );
BaseType_t xSAILshellTaskInit_core2( CPUIdType_e           xSchdCore,
		UBaseType_t  xTaskPrior );
BaseType_t xSleepTaskInit_core0( CPUIdType_e           xSchdCore,
                 UBaseType_t  xTaskPrior );
BaseType_t xSleepTaskInit_core1( CPUIdType_e           xSchdCore,
                 UBaseType_t  xTaskPrior );
BaseType_t xSleepTaskInit_core2( CPUIdType_e           xSchdCore,
                 UBaseType_t  xTaskPrior );

/*=================================================================================================
**                                 Extern Declarations                                          **
=================================================================================================*/
extern BaseType_t xSAILConsoleUartTaskRTOSFeatureInit( CPUIdType_e           xSchdCore);
extern BaseType_t xSAILConsoleUartTaskInit( CPUIdType_e           xSchdCore,
                                        UBaseType_t  xTaskPrior  );

/*=================================================================================================
**                                 Tasks Creation Table                                         **
=================================================================================================*/

static const FreertosTaskSchedulingTableType xTaskInitTable[] =
{
    /*** CPU0 ***/
    { CPU0, TASK_PRIOR_5, xISDTaskInit,                     NULL                                },
    { CPU0, TASK_PRIOR_2, xSAILshellTaskInit_core0,         xAPPLShellTaskRTOSFeatureInit       },
    { CPU0, TASK_PRIOR_3, xSAILConsoleUartTaskInit,         xSAILConsoleUartTaskRTOSFeatureInit },
    { CPU0, TASK_PRIOR_5, xSleepTaskInit_core0,             xSleep_Task_Resources_Init          },
    { CPU0, TASK_PRIOR_3, xSpinorEL1TaskInit,               xSpinorEl1TaskResourceInit          }, // SPINOR task needs to run at the same priority
                                                                                                   // as WDG task which does the pet (TODO: enable WDG)
    { CPU0, TASK_PRIOR_1, xCrashdbgSPINORDCTaskInit,        NULL                                },
    { CPU0, TASK_PRIOR_3, xSAILUpdaterTaskInit,             NULL                                },
    { CPU0, TASK_PRIOR_7, xDDRMilestoneTaskInit,            NULL                                }, // Do not use prio 7 for any other task
    { CPU0, TASK_PRIOR_5, xSAILMBTestTaskInit,              xMBTestTaskRTOSFeatureInit          },
    #ifndef CPU0_TASKS_DISABLED
    { CPU0, TASK_PRIOR_4, xDummy1TaskInit,                  NULL                                },
    { CPU0, TASK_PRIOR_7, xDDRMilestoneTaskInit,            NULL                                }, // Do not use prio 7 for any other task
    { CPU0, TASK_PRIOR_5, xSAILMBTestTaskInit,              xMBTestTaskRTOSFeatureInit          },
    { CPU0, TASK_PRIOR_1, xCoreHandshakeTaskInit,           xCoreHSTaskFeatureInit              },
    { CPU0, TASK_PRIOR_3, xMDLCTaskInit,                    NULL                                },
    #endif

    /*** CPU1 ***/
    { CPU1, TASK_PRIOR_2, xSAILshellTaskInit_core1,         NULL                                },
    { CPU1, TASK_PRIOR_5, xSleepTaskInit_core1,             NULL                                },
    { CPU1, TASK_PRIOR_5, xCanTrcvTaskInit,                 xCanTrcvTaskQueueInit               },
    { CPU1, TASK_PRIOR_5, xCanTaskInit,                     xCanTaskQueueInit                   },
    { CPU1, TASK_PRIOR_5, xCanSrvTaskInit,                  xCanSrvTaskQueueInit                },
    { CPU1, TASK_PRIOR_5, xCanMailboxTaskInit,              xCanMailboxTaskResourceInit         },
    { CPU1, TASK_PRIOR_5, xSPIXferHandlerTaskInit,          xSPISEQMsgQueueInit                 },
    { CPU1, TASK_PRIOR_5, xISDTaskInit,                     NULL                                },
    { CPU1, TASK_PRIOR_7, xDDRMilestoneTaskInit,            NULL                                }, // Do not use prio 7 for any other task
    #ifndef CPU1_TASKS_DISABLED
    { CPU1, TASK_PRIOR_4, xDummy2TaskInit,                  NULL                                },
    { CPU1, TASK_PRIOR_7, xDDRMilestoneTaskInit,            NULL                                }, // Do not use prio 7 for any other task
    { CPU1, TASK_PRIOR_5, xCanMailboxTaskInit,              xCanMailboxTaskResourceInit         },
    { CPU1, TASK_PRIOR_1, xCoreHandshakeTaskInit,           xCoreHSTaskFeatureInit              },
    #endif

    /*** CPU2 ***/
    { CPU2, TASK_PRIOR_2, xSAILshellTaskInit_core2,         NULL                                },
    { CPU2, TASK_PRIOR_5, xSleepTaskInit_core2,             NULL                                },
    { CPU2, TASK_PRIOR_5, xIcbTaskInit,                     xIcb_LogResourcesInit               }, 
    { CPU2, TASK_PRIOR_5, xPsailTaskInit ,                  xPsail_Task_Resources_Init          }, 
    { CPU2, TASK_PRIOR_5, xISDTaskInit,                     NULL                                },
    { CPU2, TASK_PRIOR_7, xDDRMilestoneTaskInit,            NULL                                }, // Do not use prio 7 for any other task
    #ifndef CPU2_TASKS_DISABLED
    { CPU2, TASK_PRIOR_4, xDummy3TaskInit,                  NULL                                },
    { CPU2, TASK_PRIOR_7, xDDRMilestoneTaskInit,            NULL                                }, // Do not use prio 7 for any other task
    { CPU2, TASK_PRIOR_1, xCoreHandshakeTaskInit,           xCoreHSTaskFeatureInit              },
    { CPU2, TASK_PRIOR_2, xPmicNINTTaskInit,                xPmicNINT_Task_Resources_Init       },
    #endif

    /*** CPU3 ***/
    #ifndef CPU3_TASKS_DISABLED
    #endif 
};


/*=================================================================================================
**                                        Hook function definitions                             **
=================================================================================================*/
void vApplicationTickHook( void )
{
    /* Increment a counter so the check task can see that the tick hook is
     * being called. */
    ulTickHookCallCount++;
}
/*-----------------------------------------------------------*/

void vApplicationSetupTickInterrupt( void )
{
    BaseType_t xResult = pdFAIL;

    /* Disable Virtual Timer */
    arch_write_cntvctl( (uint32_t) FALSE );

    uint32_t temp = arch_read_cntvtval();

    ( void )xGicSetIntEnable(VIRTAUL_TIMER_PPI_ID, (bool)FALSE);
    ( void )xGicRegisterIntHandler(VIRTAUL_TIMER_PPI_ID, (InterruptHandle_t)&FreeRTOS_Tick_Handler, NULL);
    if ( 0x0U == xGicConfigureInt(VIRTAUL_TIMER_PPI_ID, (enum InterruptConfig_t)EL1_INT_CONFIG_EDGE_TRIGGER, NULL) )
    {
        ( void )xGicSetIntPriority(VIRTAUL_TIMER_PPI_ID, (uint32_t)0xF0U);
        ( void )xGicSetIntEnable(VIRTAUL_TIMER_PPI_ID, (bool)TRUE);

        /* Write Timer Val */
        arch_write_cntvtval( (uint32_t)((configCPU_CLOCK_HZ/configTICK_RATE_HZ) - 1U) );   

        /* Enable Virtual Timer */
        arch_write_cntvctl( (uint32_t) TRUE );
    }else
    {
        //Tick Configuration Failed.
    }
}
/*-----------------------------------------------------------*/

void vApplicationClearTickInterrupt( void )
{
    /* Read Timer CompareValue */
    uint64_t timerCompareVal = arch_read_cntvcval();

    /* Schedule Next Tick */
    timerCompareVal += (uint64_t)((configCPU_CLOCK_HZ/configTICK_RATE_HZ) - 1U);
    arch_write_cntvcval(timerCompareVal);
}
/*-----------------------------------------------------------*/

void vApplicationIdleHook( void )
{
    xIdleTaskCounter++;
}
/*-----------------------------------------------------------*/

void vApplicationPassiveIdleHook( void )
{
    xPassiveIdleTaskCounter++;
}
/*-----------------------------------------------------------*/

static void vFreertosSvcHook( UBaseType_t uxSvcNumber )
{

    vFreertosSvcHookWrapper( (uint32_t)uxSvcNumber );

}
/*-----------------------------------------------------------*/

/*=========================================================================
**  Function : xFreertosTasksAndResourcesInit
** =========================================================================*/
/**
  It will initialize the tasks and respective resources

  @param
  [in]xCurrCPU - CPU0/CPU1/CPU2/CPU3

  @return
  xResult - pdPASS or pdFAIL

  @dependencies
  None.
*/
BaseType_t xFreertosTasksAndResourcesInit()
{
    uint32_t ulCpuCore = get_curr_phys_cpu_num();
    BaseType_t xResult = pdPASS;

    if (ulCpuCore == 0)
    {
        for( uint8_t i = 0; i < SIZEOF_ARRAY(xTaskInitTable); i++ )
        {
            if ( pdPASS != xTaskInitTable[i].pTaskInitFunc( xTaskInitTable[i].xSchdCore,
                        xTaskInitTable[i].xTaskPrior ) )
            {
                xResult = pdFAIL;
            }

            if ( xTaskInitTable[i].pTaskResourcesInitFunc != NULL )
            {
                if ( pdPASS != xTaskInitTable[i].pTaskResourcesInitFunc( xTaskInitTable[i].xSchdCore ) )
                {
                    xResult = pdFAIL;
                }
            }
        }
    }
#if 0
    if( pdPASS != xResult )
    {
        err_fatal(FREERTOS ,(int32_t)xResult);
    }
#endif	
    return xResult;
}

/*=========================================================================
**  Function : sailbsp_imageLoadToDDR_wait 
** =========================================================================*/
#if 0
static void sailbsp_imageLoadToDDR_wait ( void ) {
    while ( 1 ) {
        if (S1_READY_SUCCESS != eISDGetStatus(ISD_GET_S1_READY_STATUS)){
            ;
        }
        else {
            DEBUG_LOG(SAIL_INFO,"DDR READY BEFORE INITIALIZING FREERTOS SCHEDULER, S1_READY_SUCCESS");
            break;
        }
    }
}
#endif

/*=========================================================================
**  Function : xFreertosInitializeScheduler
** =========================================================================*/
/**
  Initialize the FreeRTOS Scheduler

  @param
  [in]xCurrCPU - CPU0/CPU1/CPU2/CPU3

  @return
  xResult - pdPASS or pdFAIL

  @dependencies
  None.
*/
BaseType_t xFreertosInitializeScheduler ( CPUIdType_e xCurrCPU )
{
    ( void )xCurrCPU; /*future use */
    BaseType_t xResult = pdPASS;

    //wait for MD DDR to be ready before initializing the scheduler
    //sailbsp_imageLoadToDDR_wait();
	
	/* Init GIC and initialize EL1 vector table for IRQs */
    if (0x0U != xGicInitEl1())
    {
        xResult = pdFAIL;
    }

    if (xCurrCPU == 0)
    {
    /* Initialize the SVC call Mutex lock for atomic  operation */
    if (pdPASS != xFreeRTOSMutexCreate (&pxMutexHandleSVCParmAddBuffer, &pxMutexHandleSVCParmAdd) )
    {
        xResult = pdFAIL;
    }
    }
    return xResult;
}

/*=========================================================================
**  Function : Dummy Tasks
** =========================================================================*/

void xDummy1TaskCore0( void * pvParameters )
{
    static volatile uint32_t xDummy1TaskCounter = 0U;
    for ( ;; ) 
    {
        xDummy1TaskCounter++; 
        // DEBUG_LOG(SAIL_WARNING, "Dummy Task Core 0 - Counter Value: %d \n\r", xDummy1TaskCounter);
        vFreeRTOSTaskDelay(pdMS_TO_TICKS(5000)); 
    }
}

void xDummy2TaskCore1( void * pvParameters )
{
    static volatile uint32_t xDummy2TaskCounter = 0U;
    for ( ;; ) 
    {
        xDummy2TaskCounter++; 
        // DEBUG_LOG(SAIL_WARNING, "Dummy Task Core 1 - Counter Value: %d \n\r", xDummy2TaskCounter);
        vFreeRTOSTaskDelay(pdMS_TO_TICKS(10000)); 
    }
}

void xDummy3TaskCore2( void * pvParameters )
{
    static volatile uint32_t xDummy3TaskCounter = 0U;
    for ( ;; ) 
    {
        xDummy3TaskCounter++; 
        // DEBUG_LOG(SAIL_WARNING, "Dummy Task Core DCLS - Counter Value: %d \n\r", xDummy3TaskCounter);
        vFreeRTOSTaskDelay(pdMS_TO_TICKS(20000)); 
    }
}

BaseType_t xDummy1TaskInit( CPUIdType_e  xSchdCore,
                            UBaseType_t  xTaskPrior )
{
    static BaseType_t xDummy1TaskCreated = pdPASS;
    BaseType_t xResult = pdPASS;
    UBaseType_t uxCoreAffinityMask;

    TaskParams_t xInitTaskParameters = {
        .pvTaskCode     = xDummy1TaskCore0,                
        .pcName         = "DUMMY_1_TASK_CORE0",            
        .usStackDepth   = DUMMY_TASK_STACK_SIZE, 
        .pvParameters   = NULL, 
        .uxPriority     = (xTaskPrior),   
        .puxStackBuffer = xDummy1TaskStack,           
        .xRegions		=	{
                                { NULL, 0UL, 0UL },
                                { NULL, 0UL, 0UL },
                                { NULL, 0UL, 0UL },
                                { NULL, 0UL, 0UL },
                                { NULL, 0UL, 0UL },
                                { NULL, 0UL, 0UL }
                            },
        .pxTaskBuffer   = &xDummy1TaskTCB
    };
    uxCoreAffinityMask = ( 1 << xSchdCore );

    xResult = xFreeRTOSTaskCreateAffinitySet(&xInitTaskParameters, uxCoreAffinityMask, &xDummy1TaskHandle);

    if ( xResult != pdPASS){
        xDummy1TaskCreated = pdFALSE;
    }
    
    return xResult;
}

BaseType_t xDummy2TaskInit( CPUIdType_e  xSchdCore,
                            UBaseType_t  xTaskPrior )
{
    static BaseType_t xDummy2TaskCreated = pdPASS;
    BaseType_t xResult = pdPASS;
    UBaseType_t uxCoreAffinityMask;

    TaskParams_t xInitTaskParameters = {
        .pvTaskCode     = xDummy2TaskCore1,                
        .pcName         = "DUMMY_2_TASK_CORE1",            
        .usStackDepth   = DUMMY_TASK_STACK_SIZE, 
        .pvParameters   = NULL, 
        .uxPriority     = (xTaskPrior),   
        .puxStackBuffer = xDummy2TaskStack,           
        .xRegions		=	{
                                { NULL, 0UL, 0UL },
                                { NULL, 0UL, 0UL },
                                { NULL, 0UL, 0UL },
                                { NULL, 0UL, 0UL },
                                { NULL, 0UL, 0UL },
                                { NULL, 0UL, 0UL }
                            },
        .pxTaskBuffer   = &xDummy2TaskTCB
    };
    uxCoreAffinityMask = ( 1 << xSchdCore );

    xResult = xFreeRTOSTaskCreateAffinitySet(&xInitTaskParameters, uxCoreAffinityMask, &xDummy2TaskHandle);

    if ( xResult != pdPASS){
        xDummy2TaskCreated = pdFALSE;
    }

    return xResult;
}

BaseType_t xDummy3TaskInit( CPUIdType_e  xSchdCore,
                            UBaseType_t  xTaskPrior )
{
    static BaseType_t xDummy3TaskCreated = pdPASS;
    BaseType_t xResult = pdPASS;
    UBaseType_t uxCoreAffinityMask;

    TaskParams_t xInitTaskParameters = {
        .pvTaskCode     = xDummy3TaskCore2,                
        .pcName         = "DUMMY_3_TASK_CORE2",            
        .usStackDepth   = DUMMY_TASK_STACK_SIZE, 
        .pvParameters   = NULL, 
        .uxPriority     = (xTaskPrior),   
        .puxStackBuffer = xDummy3TaskStack,           
        .xRegions		=	{
                                { NULL, 0UL, 0UL },
                                { NULL, 0UL, 0UL },
                                { NULL, 0UL, 0UL },
                                { NULL, 0UL, 0UL },
                                { NULL, 0UL, 0UL },
                                { NULL, 0UL, 0UL }
                            },
        .pxTaskBuffer   = &xDummy3TaskTCB
    };
    uxCoreAffinityMask = ( 1 << xSchdCore );

    xResult = xFreeRTOSTaskCreateAffinitySet(&xInitTaskParameters, uxCoreAffinityMask, &xDummy3TaskHandle);

    if ( xResult != pdPASS){
        xDummy3TaskCreated = pdFALSE;
    }

    return xResult;
}

/*=========================================================================
**  Function : xFreertosTaskStartScheduler
** =========================================================================*/

void xFreertosTaskStartScheduler (CPUIdType_e xCurrCPU) {
    if ( xCurrCPU == 0 )
    {
        vTaskStartScheduler();
    }
    else
    {
        xPortStartScheduler();
    }
    for( ;; );
}
/*=========================================================================
**  Function : xFreertosChecker
** =========================================================================*/
/**
  It will validate the Stacks, cache config,

  @param
  None

  @info
   ++++++++ SAILBSP_STACK_END = Image$$ARM_LIB_STACK$$ZI$$Limit
   +      +
   +      +  2K SYS Mode Stack
   +      +
   ++++++++ ( SAILBSP_STACK_END  - SYS_MODE_STACK_SIZE
   +      +
   +      +  1K FIQ and IRQ Mode Stack
   +      +
   ++++++++ ( SAILBSP_STACK_END  - SYS_MODE_STACK_SIZE - IRQ_MODE_STACK_SIZE );
   +      +
   +      +  4K SVC Mode Stack
   +      +
   ++++++++ ( SAILBSP_STACK_END  - SYS_MODE_STACK_SIZE - IRQ_MODE_STACK_SIZE - SVC_MODE_STACK_SIZE);
   +      +
   +      +  1K ABT and UND Mode Stack
   +      +
   ++++++++ ( SAILBSP_STACK_END  - SYS_MODE_STACK_SIZE - IRQ_MODE_STACK_SIZE - SVC_MODE_STACK_SIZE - ABT_MODE_STACK_SIZE);
  @return
  xResult - pdPASS or pdFAIL

  @dependencies
  None.
*/
BaseType_t xFreertosChecker( CPUIdType_e xCurrCPU )
{
    ( void )xCurrCPU;

    uint32_t ulIntrMask          = 0;
    uint32_t ulModeMask          = 0;
    uint32_t ulSCTLRVal          = 0;
    uint32_t ulStackPointer      = 0;
    uint32_t ulStackPointerStart = 0;
    uint32_t ulStackPointerEnd   = 0;
    bool pbIsOn                  = FALSE;
    ClockIdType nClockId         = 0;
    ClockHandle hClientHandle    = (ClockHandle)NULL;
    BaseType_t xResult         = pdPASS;
    uint32_t     ulPMRVal        = 0;
    uint32_t ulPSTATE_RegStore    =0;

    __asm__ volatile( "mrs %0, CPSR\n" : "=r"(ulPSTATE_RegStore) :);   /* Save PSTATE register */

    /*
     * FreeRTOS Checker 1: Validate Interrupt Masking
     */
    ulModeMask = ulPSTATE_RegStore;
    ulIntrMask = ulModeMask & PSTATE_IRQ_INTR_MASK;

    if( ulIntrMask == PSTATE_IRQ_INTR_MASK )  /* PSTATE_IRQ_INTR Enable Check */
    {
        xResult = pdFAIL;
		 DEBUG_LOG(SAIL_WARNING, "FreeRTOS Checker 1: Validate Interrupt Masking  ulIntrMask Value: %d\n\r",ulIntrMask);
    }
    __asm__ volatile( "cpsid  aif"::: "memory");                            /* disable interrupts a,i,f */


    /* Validate the priority masking register as per the SafeRTOS Configuration */
    __asm volatile( "mrc p15, #0, %0, c4, c6, #0" :"=r"(ulPMRVal) : );

    if(configMAX_SYSCALL_INTERRUPT_PRIORITY != ulPMRVal) 
    {
		 DEBUG_LOG(SAIL_WARNING, "Validate the priority masking register as per the FreeRTOS Configuration  ulPMRVal Value: %d\n\r",ulPMRVal);	
        xResult = pdFAIL;
    }

    /*
     * FreeRTOS Checker 2: Validate the Processor MODE
     */
    ulModeMask = ( ulModeMask & CPSR_MODE_SYS );

    if(CPSR_MODE_SYS != ulModeMask)
    {
    	 DEBUG_LOG(SAIL_WARNING, "FreeRTOS Checker 2: Validate the Processor MODE  ulModeMask Value: %d\n\r",ulModeMask);		
        xResult = pdFAIL;
    }
    if(xCurrCPU  == 0){
    /*
     * FreeRTOS Checker 3: Validate the Stack Pointer of SYS_MODE
     * stack start with sys mode and all other modes follow after sys mode stack
     */
    __asm__ volatile( "mov %0, sp\n" : "=r" (ulStackPointer) :);

    ulStackPointerStart  =   ( SAILBSP_STACK_END );
    ulStackPointerEnd    =   ( SAILBSP_STACK_END  - SYS_MODE_STACK_SIZE );

    if( ( ulStackPointer  >  ulStackPointerStart ) ||  ( ulStackPointer  <  ulStackPointerEnd ) )
    {
    	 DEBUG_LOG(SAIL_WARNING, "FreeRTOS Checker 3: Validate the Stack Pointer of SYS_MODE  ulStackPointer Value: %x ulStackPointerStart:%x and ulStackPointerEnd: %x\n\r",ulStackPointer,ulStackPointerStart,ulStackPointerEnd);			
        xResult = pdFAIL;
    }

    /*
     * FreeRTOS Checker 4: Validate Stack Pointer of IRQ_MODE
     */
    __asm__ volatile( "mrs %0, CPSR\n" : "=r"(ulModeMask) :);               /* read CPSR */

    ulModeMask = ( ulModeMask & ( ~ CPSR_MODE_MASK ) ) | CPSR_MODE_IRQ;

    __asm__ volatile( "msr CPSR,  %0" :  :"r"(ulModeMask) );

    __asm__ volatile( "mov %0, sp\n" : "=r" (ulStackPointer) :);

    ulStackPointerStart  =   ( SAILBSP_STACK_END  - SYS_MODE_STACK_SIZE );
    ulStackPointerEnd    =   ( SAILBSP_STACK_END  - SYS_MODE_STACK_SIZE - IRQ_MODE_STACK_SIZE );

    if( ( ulStackPointer  >  ulStackPointerStart ) ||  ( ulStackPointer  <  ulStackPointerEnd ) )
    {
        DEBUG_LOG(SAIL_WARNING, "FreeRTOS Checker 3: Validate the Stack Pointer of IRQ_MODE  ulStackPointer Value: %x ulStackPointerStart:%x and ulStackPointerEnd: %x\n\r",ulStackPointer,ulStackPointerStart,ulStackPointerEnd);			
        xResult = pdFAIL;
    }

    /*
     * FreeRTOS Checker 5: Validate Stack Pointer of SVC_MODE
     */
    __asm__ volatile( "mrs %0, CPSR\n" : "=r"(ulModeMask) :);               /* read CPSR */

    ulModeMask = ( ulModeMask & ( ~ CPSR_MODE_MASK ) ) | CPSR_MODE_SVC;

    __asm__ volatile( "msr CPSR,  %0" :  :"r"(ulModeMask) );

    __asm__ volatile( "mov %0, sp\n" : "=r" (ulStackPointer) :);

    ulStackPointerStart =  ( SAILBSP_STACK_END  - SYS_MODE_STACK_SIZE - IRQ_MODE_STACK_SIZE );
    ulStackPointerEnd   =  ( SAILBSP_STACK_END  - SYS_MODE_STACK_SIZE - IRQ_MODE_STACK_SIZE - SVC_MODE_STACK_SIZE);

    if( ( ulStackPointer  >  ulStackPointerStart ) ||  ( ulStackPointer  <  ulStackPointerEnd ) )
    {
        DEBUG_LOG(SAIL_WARNING, "FreeRTOS Checker 3: Validate the Stack Pointer of SVC_MODE  ulStackPointer Value: %x ulStackPointerStart:%x and ulStackPointerEnd: %x\n\r",ulStackPointer,ulStackPointerStart,ulStackPointerEnd);			
        xResult = pdFAIL;
    }

    /*
     * FreeRTOS Checker 6: Validate Stack Pointer of ABT_MODE
     */

    __asm__ volatile( "mrs %0, CPSR\n" : "=r"(ulModeMask) :);               /* read CPSR */

    ulModeMask = ( ulModeMask & ( ~ CPSR_MODE_MASK ) ) | CPSR_MODE_ABT;

    __asm__ volatile( "msr CPSR,  %0" :  :"r"(ulModeMask) );

    __asm__ volatile( "mov %0, sp\n" : "=r" (ulStackPointer) :);

    ulStackPointerStart =  ( SAILBSP_STACK_END - SYS_MODE_STACK_SIZE - IRQ_MODE_STACK_SIZE - SVC_MODE_STACK_SIZE);
    ulStackPointerEnd   =  ( SAILBSP_STACK_END - SYS_MODE_STACK_SIZE - IRQ_MODE_STACK_SIZE - SVC_MODE_STACK_SIZE - ABT_MODE_STACK_SIZE);

    if( ( ulStackPointer  >  ulStackPointerStart ) ||  ( ulStackPointer  <  ulStackPointerEnd ) )
    {
        DEBUG_LOG(SAIL_WARNING, "FreeRTOS Checker 3: Validate the Stack Pointer of ABT_MODE  ulStackPointer Value: %x ulStackPointerStart:%x and ulStackPointerEnd: %x\n\r",ulStackPointer,ulStackPointerStart,ulStackPointerEnd);			        
        xResult = pdFAIL;
    }
  }
    __asm__ volatile( "msr CPSR,  %0" :  :"r"(ulPSTATE_RegStore) ); /* restore the PSTATE */

    /*
     * FreeRTOS Checker 7: Validate Cache Configuration
     */
    __asm__ volatile( "mrc p15,  #0, %0, c1, c0, #0" :"=r"(ulSCTLRVal) :); /* read SCTLR */

    if( ( ulSCTLRVal & SCTLR_DCACHE_MASK ) != SCTLR_DCACHE_MASK ) /* DCACHE Enable Check */
    {
        DEBUG_LOG(SAIL_WARNING, "FreeRTOS Checker 7: Validate D Cache Configuration  ulSCTLRVal Value: %d\n\r",ulSCTLRVal);
        xResult = pdFAIL;
    }

    if( ( ulSCTLRVal & SCTLR_ICACHE_MASK ) != SCTLR_ICACHE_MASK ) /* ICACHE Enable Check */
    {
        DEBUG_LOG(SAIL_WARNING, "FreeRTOS Checker 7: Validate I Cache Configuration  ulSCTLRVal Value: %d\n\r",ulSCTLRVal);
        xResult = pdFAIL;
    }

    /*
     * FreeRTOS Checker 8: Validate Systick Timer Clock Enable
     */

    (void)Clock_GetHandle(&hClientHandle);

    /* sailss_cc_tscss_1_global_cntr_clk is the input for Cortex R52 Timer Module */
    if ( CLOCK_SUCCESS == Clock_GetClockId( hClientHandle,"sailss_cc_tscss_1_global_cntr_clk", &nClockId ) )
    {
        if ( CLOCK_SUCCESS ==  Clock_IsClockOn(hClientHandle, nClockId, &pbIsOn) )
        {
            if(pbIsOn != TRUE)
            {
                DEBUG_LOG(SAIL_WARNING, " FreeRTOS Checker 8: Validate Systick Timer Clock Enable  pbIsOn Value: %d\n\r",pbIsOn);
                xResult = pdFAIL;
            }
        }
    }
    else
    {
        DEBUG_LOG(SAIL_WARNING, " FreeRTOS Checker 8: Validate Systick Timer Clock Enable  Clock_GetClockId Failed \n\r");
        xResult = pdFAIL;
    }

    if( pdPASS != xResult )
    {
        //err_fatal(FREERTOS ,(int32_t)xResult);
        err_fatal(FREERTOS ,(int32_t)5);
    }
	
    return xResult;
}
/*=========================================================================
**  Function : xFreertosIsIRQMode
** =========================================================================*/
/**
  This function will check if current task mode is CPSR_MODE_USR or CPSR_MODE_SYS.
  If yes, current mode is not IRQ mode.

  @param
  [in]None

  @return
   TRUE or FALSE

  @dependencies
  None.
*/
portCHAR xFreertosIsIRQMode(void)
{
    portCHAR  bPrivMode   = TRUE;
    uint32_t      ulCPSR_reg   = 0;

    __asm__ volatile( "mrs %0, CPSR\n" : "=r"(ulCPSR_reg) : );

    if( ( CPSR_MODE_USR == ( ulCPSR_reg & CPSR_MODE_MASK ) )  || ( CPSR_MODE_SYS == ( ulCPSR_reg & CPSR_MODE_MASK ) ) ) /* Is the task running privileged? */
    {
        bPrivMode = FALSE;
    }
    else
    {
        bPrivMode = TRUE;
    }
    return bPrivMode ;
}
/*=========================================================================
** Function : vFreeRTOSSleepDeInit
** =========================================================================*/
/**
This function will be called before going to sleep to clear the shared memory
and disable tick interrupt

@param
[in]None

@return
? None

@dependencies
None.
*/
 void vFreeRTOSSleepDeInit(void)
{
    /* Disable Virtual Timer */
    arch_write_cntvctl( (uint32_t) FALSE );

    /* Cleared FreeRTOS Shared Memory Region */
    out_dword(FreeRTOS_0_GIC_FLAG_MEM_ADD,0x0);
    out_dword(FreeRTOS_1_GIC_FLAG_MEM_ADD,0x0);
}
