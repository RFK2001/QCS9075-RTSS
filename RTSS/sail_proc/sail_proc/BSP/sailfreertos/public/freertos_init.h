/**************************************************************************************************
** Copyright (c) 2022-2025 Qualcomm Technologies, Inc.                                           **
** All Rights Reserved.                                                                          **
** Confidential and Proprietary - Qualcomm Technologies, Inc.                                    **
**************************************************************************************************/

/*=================================================================================================
    File Name          : sailfreertos_init.h
    Component Name     : sailfreertos
    Description        : FreeRTOS initialization Interface file
    $Header:  $
    $DateTime: 2022/03/11 01:34:19 $
    $Author:  $
=================================================================================================*/

/* Include header file guard */

#ifndef SAILFREERTOS_INIT_H_
#define SAILFREERTOS_INIT_H_

#include "FreeRTOSOsal.h"
#include "IPCC.h"
#include "arch_defs.h"

#define CPSR_MODE_MASK             0x1FU

#define CPSR_MODE_USR              0x10U
#define CPSR_MODE_FIQ              0x11U
#define CPSR_MODE_IRQ              0x12U
#define CPSR_MODE_SVC              0x13U
#define CPSR_MODE_ABT              0x17U
#define CPSR_MODE_HYP              0x1AU
#define CPSR_MODE_UND              0x1BU
#define CPSR_MODE_SYS              0x1FU


#define SCTLR_DCACHE_MASK                ( (uint32_t)1U << 2U )
#define SCTLR_ICACHE_MASK                ( (uint32_t)1U << 12U )


#define PSTATE_ABORT_INTR_MASK         ( 1U << 8U )
#define PSTATE_IRQ_INTR_MASK           ( 1U << 7U )
#define PSTATE_FIQ_INTR_MASK           ( 1U << 6U )

typedef enum
{
    CPU0 = 0,
    CPU1,
    CPU2,
    CPU3,
    MAXM_CPU,
}CPUIdType_e;

typedef enum
{
    TASK_PRIOR_0 = 0,
    TASK_PRIOR_1,
    TASK_PRIOR_2,
    TASK_PRIOR_3,
    TASK_PRIOR_4,
    TASK_PRIOR_5,
    TASK_PRIOR_6,
    TASK_PRIOR_7,
    TASK_PRIOR_MAX
}TaskPriorityType_e;

/* Structure for accessing list of all Tasks*/
typedef struct 
{
    TaskHandle_t TaskHandle;
    const char *TaskName;
    int8_t        Taskcount;
} xTaskInfo;

// Keep this number the same as cpurtsNUMBER_OF_TASK in cpuruntimestats.h

extern SemaphoreHandle_t  pxMutexHandleSVCParmAdd;
extern BaseType_t xFreertosInitializeScheduler ( CPUIdType_e xCurrCPU );
extern BaseType_t xFreertosTasksAndResourcesInit();
extern void xFreertosTaskStartScheduler ( CPUIdType_e xCurrCPU );
extern void vYieldCoreCB( IPCC_CBData nData, IPCC_Client eSenderID, IPCC_Signal nSignal );
extern portCHAR xFreertosIsIRQMode(void);
extern void vFreeRTOSSleepDeInit(void);
extern IPCC_Handle xFreertosSmp_IpccHandle;
BaseType_t xFreertosChecker( CPUIdType_e xCurrCPU );
/* TODO: To be moved to crashdbg EL1 public header */ 
extern BaseType_t xCrashdbgSPINORDCTaskInit(CPUIdType_e xSchdCore, UBaseType_t xTaskPrior);

#endif /* SAILFREERTOS_INIT_H_ */
