/**********************************************************************************************************
    Copyright (c) 2023 Qualcomm Technologies, Inc.
    All Rights Reserved.
    Confidential and Proprietary - Qualcomm Technologies, Inc.

    Export of this technology or software is regulated by the U.S. Government.
    Diversion contrary to U.S. law prohibited.

    All ideas, data and information contained in or disclosed by
    this document are confidential and proprietary information of
    Qualcomm Technologies, Inc. and all rights therein are expressly reserved.
    By accepting this material the recipient agrees that this material
    and the information contained therein are held in confidence and in
    trust and will not be used, copied, reproduced in whole or in part,
    nor its contents revealed in any manner to others without the express
    written permission of Qualcomm Technologies, Inc.
**********************************************************************************************************/

/*=========================================================================================================
    File Name          : Os.h
    Component Name     : 
    Description        : Stub functions and typedefs to support Baremetal Autosar Code. Donot use in EVB
    $Header: $
    $DateTime: 
    $Author: 
=========================================================================================================*/

/*=========================================================================================================
**                                        Include files                                                  **
=========================================================================================================*/
#ifndef OS_H
#define OS_H

#include "Std_Types.h"

typedef uint64 EventMaskType;
typedef void (*TaskType)(void);

//#define ISR(x) void x(void)
#define TASK(TaskFuncName)	void TaskFuncName(void)

# define CDD_BootLoggerEvent     ((EventMaskType)255uLL)
#define BrsEvCyclicAlarm_1ms                ((EventMaskType)1uLL)
#define Ssm_ClientFaultMessageEvent         ((EventMaskType)7uLL)
#define Ssm_ClientHealthProcessAlarmEv_25ms ((EventMaskType)1uLL)
#define Ssm_ClientMainMsgEv                 ((EventMaskType)3uLL)
#define Ssm_ClientSubsFaultRcvEvent         ((EventMaskType)1uLL)
#define Ssm_FaultEvent                      ((EventMaskType)55uLL)
#define Ssm_HealthMonitorEvent              ((EventMaskType)1uLL)
#define Ssm_MailboxHandlerEvent             ((EventMaskType)3uLL)
#define Ssm_SoCFatalEvent                   ((EventMaskType) 0x6000000000000000uLL) /* Bits 62 and 61 */
#define Ssm_SoCFatalTimeoutEvent            ((EventMaskType) 0x9000000000000000uLL) /* Bits 63 and 60 */
#define Ssm_SailToAPSSEvent                 ((EventMaskType)1uLL)
/*#define Ssm_TestClient1Events               ((EventMaskType)0x0EULL)
#define Ssm_TestClient1AlarmEvent           ((EventMaskType)0x01ULL)
#define Ssm_TestSub1AlarmEvent             ((EventMaskType)1uLL)
#define Ssm_TestSub1NotifyEvent            ((EventMaskType)2uLL)*/
#define Ssm_TestTaskDelayEvent              ((EventMaskType)1ULL)
#define Ssm_TestOnlyUartTaskKillEvent       ((EventMaskType) 0x0800000000000000ULL) /* Bit 59 */
#define Ssm_UartEvent                       ((EventMaskType)1uLL)
#define Ssm_PeriodicMonitorEvent            ((EventMaskType)1uLL)
#define Ssm_FusaIntrEvent                   ((EventMaskType)1uLL)
#define Ssm_TestTaskEvent                   ((EventMaskType)10uLL)
#define Ssm_ConfigMailboxEvent             ((EventMaskType)1uLL)
#define Mbtf_event                          ((EventMaskType)2uLL)

#define OS_MS2TICKS_SystemTimer(taskPeriod)                 (((uint32) (taskPeriod)) * 1000U)

#define  INVALID_TASK                        NULL_PTR
//temporary decleration for OS counter
#define OsCounter 0
typedef enum
{
    BAREMETAL_ISR0_STUB = 0,
    BAREMETAL_ISR1_STUB = 1,
    BAREMETAL_ISR2_STUB = 2,
    OS_ISRID_COUNT = 3,
    IPCC_P_COMPUTEL1_Sail_Core0 = 4,
    IPCC_P_MPROC_ISR=5,
    ISD_IPC_NON_SEC_INTR,
    ISD_TZ_IPC_SEC_INTR,
    INVALID_ISR = OS_ISRID_COUNT
}ISRType;
typedef uint32    Os_TickType;
/*! This data type represents count values in ticks. */
typedef Os_TickType TickType;
/*! This data type points to the data type TickType. */
typedef TickType* TickRefType;

typedef  uint32 CounterType;

/*! Resource identifiers. Defined in Appl\GenData\Os_Types_Lcfg.h */
typedef enum
{
  Ssm_ClientHealthMutex = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Ssm_ClientRegMutex = 1,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Ssm_SubsMutex = 2,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  OS_RESOURCEID_COUNT = 3
} ResourceType;

/*! Alarm identifiers. Defined in Appl\GenData\Os_Types_Lcfg.h */
typedef enum
{
  BrsCyclicAlarm_1ms = 0,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Ssm_ClientHealthProcessAlarm_25ms = 1,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Ssm_HealthMonitorAlarm = 2,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Ssm_MailboxHandlerAlarm = 3,  /* PRQA S 0784 */ /* MD_Os_Rule5.5_0784 */
  Ssm_PeriodicMonitorAlarm,
  Ssm_SoCFatalTimeoutAlarm, /* Used by the Ssm SoC Fatal Task to wait for 40ms */
  Ssm_TestClient1Alarm,
  Ssm_TestTaskDelayAlarm,
  /* Add new Alarms above this comment */
  OS_ALARMID_COUNT
} AlarmType;

void Os_EnableInterruptSource(ISRType ISDID, boolean val);


/* OS Functions prototypes */
Std_ReturnType GetResource(ResourceType mutexName);
Std_ReturnType ReleaseResource(ResourceType mutexName);
Std_ReturnType SetRelAlarm(AlarmType AlarmID, uint32 Increment, uint32 Cycle);
Std_ReturnType CancelAlarm(AlarmType AlarmID);
Std_ReturnType SetEvent(TaskType TaskID, EventMaskType event);
Std_ReturnType WaitEvent(EventMaskType Mask);
Std_ReturnType GetEvent(TaskType TaskID, EventMaskType *Mask);
Std_ReturnType ClearEvent(EventMaskType Mask);
Std_ReturnType TerminateTask(void);
Std_ReturnType GetTaskID(TaskType *TaskIDRef);


extern void Os_EnableInterruptSource(ISRType ISDID, boolean val);
extern void Os_DisableInterruptSource(ISRType ISDID);
extern StatusType GetCounterValue(
					CounterType CounterID,
					TickRefType Value);

#endif 

/**********************************************************************************************************
**                                  End of file Os.h                                             **
**********************************************************************************************************/
