/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * All rights reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *
 * Export of this technology or software is regulated by the U.S. Government.
 * Diversion contrary to U.S. law prohibited.
 *
 * All ideas, data and information contained in or disclosed by
 * this document are confidential and proprietary information of
 * Qualcomm Technologies, Inc. and all rights therein are expressly reserved.
 * By accepting this material the recipient agrees that this material
 * and the information contained therein are held in confidence and in
 * trust and will not be used, copied, reproduced in whole or in part,
 * nor its contents revealed in any manner to others without the express
 * written permission of Qualcomm Technologies, Inc.
 */

/*=================================================================================================
**                                        Include files                                          **
=================================================================================================*/
#include <stdint.h>
#include <errno.h>
#include "common_functions.h"
#include "ddrmilestone.h"
#include "isd.h"
#include "debug_log.h"
#include "mailboxExt_api.h"
#include "commonClient.h"
#include "osal.h"
#include "mailboxLib.h"
#include "syscall.h"
#include "syscall_pub.h"
#include "syscall_hvc.h"
#include "syscall_svc.h"
#include "IPCC.h"

/*=================================================================================================
**                                       Local macros, variables and constants                   **
==================================================================================================*/
#define DDRMilestone_TASK_STACK_SIZE		( 1024 )
#define DDRMilestone_TASK_DELAY             ( 4U )
#define DDRMilestone_SECTASK_DELAY  		( 4U )
#define DDRMilestone_EBDEINIT_TASK_DELAY	( 2U )
#define DDRMilestone_EBDEINIT_MAXCORE		( 3U )
#define DDRMilestone_ELPM_MB_COOKIES		( 0x454C504DU )
#define DDRMilestone_SECINIT_MAXCORE		( 4U )
#define DDRMilestone_EBMSTR_CORE			( 0U )
#define DDRMilestone_Q_LEN			( 2U )
#define DDRMilestone_Q_ITEM_SZ		( sizeof(uint32_t) )
#define DDRMilestone_Q_BUFF_SZ		( DDRMilestone_Q_LEN * DDRMilestone_Q_ITEM_SZ )
#define DDRMilestone_TASK_INSTANCES			( 3U )			

static StaticTask_t xDDRMilestoneTaskTCB[DDRMilestone_TASK_INSTANCES] = { 0 };
TaskHandle_t xDDRMilestoneTaskHandle[DDRMilestone_TASK_INSTANCES] = { NULL, NULL, NULL };
static StackType_t xDDRMilestoneTaskStack[DDRMilestone_TASK_INSTANCES][DDRMilestone_TASK_STACK_SIZE] __attribute__( ( aligned( MEM_ALIGNMENT_64 ) ) ) = { 0 };
static uint8_t xDDRMilestoneQBuf[DDRMilestone_Q_BUFF_SZ] __attribute__( ( aligned( MEM_ALIGNMENT_4 ) ) ) = { 0 };
QueueHandle_t xDDRMilestoneQHandle = NULL;   
StaticQueue_t xDDRQueueBuffer;

static void prvTaskUnMskIrq(void);
static void prvTaskMskIrq(void);
static void vDDRMilestoneUpdateEL2MPU(void);
/*=================================================================================================
**                                   Global function definitions                                 **
==================================================================================================*/

/**
  It will initialize the DDRMilestone platform service task and resources

  @param [in] - None

  @return - None

  @dependencies - None.
*/
void vDDRMilestoneTask(void* pvParameters)
{
	BaseType_t xReturn = pdFAIL;
	uint32_t usMsgDmSts = 0U;
	uint32_t usIdx = 0U;
	mailboxEBStatusType_e EBxStatus = MB_UNINITIALIZED;
    uint32_t cpu_num = get_curr_phys_cpu_num();

	/* Init MD IPCC only after MD XBL_SEC boot */
	while (XBL_SEC_BOOT_SECCESS != eISDGetStatus(ISD_GET_XBL_SEC_STATUS))
	{
		(void)vFreeRTOSTaskDelay(DDRMilestone_TASK_DELAY);

	}
	IPCC_InitEx(IPCC_P_MPROC, cpu_num);
	IPCC_InitEx(IPCC_P_COMPUTEL0, cpu_num);
	IPCC_InitEx(IPCC_P_COMPUTEL1, cpu_num);
	for(;;)
	{
		/* Once TZ_SUCCESS is revived, EL2 DDR MPU region will be enabled. */
		while (TZ_SUCCESS != eISDGetStatus(ISD_GET_TZ_STATUS))
		{
			(void)vFreeRTOSTaskDelay(DDRMilestone_TASK_DELAY);
		
		}

		vDDRMilestoneUpdateEL2MPU();

		while (S1_READY_SUCCESS != eISDGetStatus(ISD_GET_S1_READY_STATUS))
		{
			(void)vFreeRTOSTaskDelay(DDRMilestone_TASK_DELAY);
		
		}

		/* required  ec-ec */
		freertosENTER_CRITICAL();
		(void)slMailBox_Enable();
		freertosEXIT_CRITICAL();

		if ( cpu_num == 0U )
		{
			/* this task only on high prio otherwise add KPI on MD side bootup , once
				init complete remove from ready list */
			/* MD_S1_READY expected */
		while (S1_READY_SUCCESS != eISDGetStatus(ISD_GET_S1_READY_STATUS))
			{
				(void)vFreeRTOSTaskDelay(DDRMilestone_TASK_DELAY);
			}
			vMailbox_S1_Handler();
			/* MD_MB_READY only received if MD_S1_READY captured by either HYP or ELx */
		while (MB_READY_SUCCESS != eISDGetStatus(ISD_GET_MB_READY_STATUS))
			{
				(void)vFreeRTOSTaskDelay(DDRMilestone_TASK_DELAY);
			}
			vMailbox_S1_Handler();
		}
		else
		{ 
			/* check for config and init state trasition */
			usIdx  = get_curr_phys_cpu_num();
			EBxStatus = eMailbox_Get_CoreStatus( usIdx );
			if( EBxStatus >= MB_ABORT )
			{
				DEBUG_LOG( SAIL_ERROR, "mailboxEB: error ! ready core %d failed to boot due to mb abort state\n\r", usIdx );
			}
			else if( EBxStatus >= MB_E2EREADY )
			{
				; /* skip for already init done */		
			}
			else 
			{
				/* check for config and init state trasition */
				usIdx  = get_curr_phys_cpu_num();
				/* wait for config and init state transition */
				while((MB_INITIIALIZED > eMailbox_Get_CoreStatus( DDRMilestone_EBMSTR_CORE )) || (MB_CONFIGURED > eMailbox_Get_CoreStatus( usIdx )))
				{
					(void)vFreeRTOSTaskDelay(DDRMilestone_SECTASK_DELAY);
				}
				/* update state */
				if( usIdx < DDRMilestone_SECINIT_MAXCORE )
				{
					EBxStatus = eMailbox_Set_Status( MB_INITIIALIZED, usIdx );
					if( MB_INITIIALIZED != eMailbox_SetBCK_Status( EBxStatus, usIdx ) )
					{
						DEBUG_LOG( SAIL_ERROR, "mailboxEB: warning ! ready core %d failed to update init state\n\r", usIdx );
					}
				}
				else
				{
					DEBUG_LOG( SAIL_ERROR, "mailboxEB: error ! ready core %d failed to update init state, unsupported core\n\r", usIdx );
				}
				/* wait for next state transition */
				while((MB_E2EREADY > eMailbox_Get_CoreStatus( DDRMilestone_EBMSTR_CORE )) || (MB_INITIIALIZED > eMailbox_Get_CoreStatus( usIdx )))
				{
					(void)vFreeRTOSTaskDelay(DDRMilestone_SECTASK_DELAY);
				}
				/* update state */
				if( usIdx < DDRMilestone_SECINIT_MAXCORE )
				{
					EBxStatus = eMailbox_Set_Status( MB_E2EREADY, usIdx );
					if( MB_E2EREADY != eMailbox_SetBCK_Status( EBxStatus, usIdx ) )
					{
						DEBUG_LOG( SAIL_ERROR, "mailboxEB: warning ! ready core %d failed to update ready state\n\r", usIdx );
					}
					else
					{
						DEBUG_LOG( SAIL_ERROR, "mailboxEB: ready core %d in sync\n\r", usIdx );
					}
				}
				else
				{
					DEBUG_LOG( SAIL_ERROR, "mailboxEB: error ! ready core %d failed to ready, unsupported core\n\r", usIdx );
				}
			}
		}

		//TODO: Enable LPM DDR Suspend Path.
		/* handle LPM and EBUSY abrupt wakeup - do not merge with above init logical handling */
		xReturn = xFreeRTOSQueueReceive( xDDRMilestoneQHandle, &usMsgDmSts, freertosMAX_DELAY);
		if( ( pdPASS == xReturn ) && ( DDRMilestone_DDR_SUSPEND == usMsgDmSts ) )
		{
			/* ec to ec case */
			prvTaskMskIrq();
			(void)slMailBox_DeInit();
			prvTaskUnMskIrq();
			/* poll for de-init status */
			if ( cpu_num == 0U )
			{
				for( usIdx = 0U; usIdx < DDRMilestone_EBDEINIT_MAXCORE; usIdx++ )
				{
					if ( (1u == usIdx%2u) && ( TRUE == IsClusterInLockStepMode(usIdx/2u)) )
					{
						DEBUG_LOG(SAIL_INFO,"vDDRMilestoneTask: eMailbox_Get_CoreStatus LPM Skipped Core:%d\n\r", usIdx);
					}
					else
					{
						/* wait until core change status , any cause will result in LPM resume back */
						while( (MB_CONFIGURED < eMailbox_Get_CoreStatus( usIdx )) && (MB_ABORT != eMailbox_Get_CoreStatus( usIdx )) )
						{
							(void)vFreeRTOSTaskDelay(DDRMilestone_EBDEINIT_TASK_DELAY);
						}
						/* expected for S2disc support */
						(void)eMailbox_SetBCK_Status(MB_UNINITIALIZED, usIdx);
					}
				}
				/* mark mailbox entry as ELPM */
				(void)eLogToMBSAILConsoleOff();
				mb_desc_t *Lpmbdesc = (void*)mailboxEB_QCMI_ADDR;
				Lpmbdesc->magic = DDRMilestone_ELPM_MB_COOKIES;
		    	vISDSetSAILMDAck(DDRMilestone_DDR_SUSPEND);
			}
		}
		else
		{
			DEBUG_LOG(SAIL_INFO,"vDDRMilestoneTask: ELPM %d, 0x%X\n\r", xReturn, usMsgDmSts);
		}
	}
	//TODO: Enable Task suspend in FreeRTOS port.
	vFreeRTOSTaskSuspend( NULL );
}

static void prvTaskMskIrq(void)
{
    if(get_curr_phys_cpu_num()==0){
	 vOsalMaskInterrupt(39U);
	 vOsalMaskInterrupt(43U);
	 vOsalMaskInterrupt(47U);
	 vOsalMaskInterrupt(32U);
	}else if(get_curr_phys_cpu_num()==1){
	 vOsalMaskInterrupt(40U);
	 vOsalMaskInterrupt(44U);
	 vOsalMaskInterrupt(48U);
	 vOsalMaskInterrupt(33U);
	}else if(get_curr_phys_cpu_num()==2){
	 vOsalMaskInterrupt(41U);
	 vOsalMaskInterrupt(45U);
	 vOsalMaskInterrupt(49U);
	 vOsalMaskInterrupt(34U);
	}else if(get_curr_phys_cpu_num()==3){
	 vOsalMaskInterrupt(42U);
	 vOsalMaskInterrupt(46U);
	 vOsalMaskInterrupt(50U);
	 vOsalMaskInterrupt(35U);
	}

	return;
}

static void prvTaskUnMskIrq(void)
{
	if(get_curr_phys_cpu_num()==0){
	 vOsalUnmaskInterrupt(32U);
	}else if(get_curr_phys_cpu_num()==1){
	 vOsalUnmaskInterrupt(33U);
	}else if(get_curr_phys_cpu_num()==2){
	 vOsalUnmaskInterrupt(34U);
	}else if(get_curr_phys_cpu_num()==3){
	 vOsalUnmaskInterrupt(35U);
    }
	return;
}

/**
  It will initialize the DDRMilestone platform service task and resources

  @param [in] - None

  @return - None

  @dependencies - None.
*/
BaseType_t xDDRMilestoneTaskInit( CPUIdType_e           xSchdCore,
                                     UBaseType_t  xTaskPrior )
{
    BaseType_t xResult = pdPASS;
	UBaseType_t uxCoreAffinityMask;
	
    /* The structure passed to xSAILTaskCreate() to create the check task. */
	TaskParams_t xInitTaskParameters =
	{
        .pvTaskCode     = vDDRMilestoneTask,                 /* The function that implements the task being created. */
        .pcName         = "DDRMilestoneTask",              /* The name of the task being created. The kernel does not use this itself, it's just to assist debugging. */
        .pxTaskBuffer   = &(xDDRMilestoneTaskTCB[xSchdCore]),              /* The buffer allocated for use as the task TCB. */
        .puxStackBuffer = (xDDRMilestoneTaskStack[xSchdCore]),             /* The buffer allocated for use as the task stack. */
		.usStackDepth   = DDRMilestone_TASK_STACK_SIZE,      /* The size of the buffer allocated for use as the task stack - note this is in BYTES! */
        .pvParameters   = NULL,                               /* The task parameter, not used in this case. */
        .uxPriority     = ( xTaskPrior ),                         /* The priority assigned to the task being created. */
        .xRegions       = {                                   /* The MPU task parameters. */
                                    { NULL, 0UL, 0UL},    /* No additional region definitions are required. */
                                    { NULL, 0UL, 0UL},
                                    { NULL, 0UL, 0UL},
                                    { NULL, 0UL, 0UL},
                                    { NULL, 0UL, 0UL},
                                    { NULL, 0UL, 0UL}
                        }
	};
    uxCoreAffinityMask = ( 1 << xSchdCore );

	/* Get the Current CPU Id.*/
	uint32_t ulcpu_ID = get_curr_phys_cpu_num();

    /* Create the check task. */
	if ( ulcpu_ID == 0U )
	{
		xResult = xFreeRTOSQueueCreate(&xDDRMilestoneQBuf[0U], DDRMilestone_Q_LEN, DDRMilestone_Q_ITEM_SZ, &xDDRMilestoneQHandle,&xDDRQueueBuffer);
	}
    if((xResult == pdPASS) && (NULL != xDDRMilestoneQHandle))
	{
		xResult = xFreeRTOSTaskCreateAffinitySet( &xInitTaskParameters, /* The structure containing the task parameters created at the start of this function. */
                                        uxCoreAffinityMask, &xDDRMilestoneTaskHandle[xSchdCore]);
	}
    return xResult;
}

/**
  vDDRMilestoneUpdateEL2MPU enables EL2 DDR MPU region.

  @param [in] - None

  @return - None

  @dependencies - None.
*/
static void vDDRMilestoneUpdateEL2MPU(void)
{
    uint32_t hvcId = 0;
    uint32_t paramId = 0;
    uint32_t arg1 = 0;
    uint32_t arg2 = 0;
    uint32_t arg3 = 0;
    uint32_t arg4 = 0;
    hvcId = SAIL_BOOT_EL2_MPU_UPDATE_HVC_ID;
    paramId = SAIL_BOOT_EL2_MPU_UPDATE_PARAM_ID;

    if( TRUE == xSyscallIsPrivilegedMode() )
    {
        if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4))
        {
           DEBUG_LOG(SAIL_ERROR, "EL2 MPU UPDATE HVC failed\n\r");
        }
    }
    else
    {
        if ( SVC_SUCCESS != svc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
        {
        	DEBUG_LOG(SAIL_ERROR, "EL2 MPU UPDATE SVC failed\n\r");
        }
    }
    return;
}
uint32 el1_mpu_syscall_enable_ddr_region_mpu(sailbsp_svc_rsp_t *rsp)
{
    vDDRMilestoneUpdateEL2MPU();
    return SVC_SUCCESS;
}

SAIL_DEFINE_SYSCALL( (uint32_t)SAIL_BOOT_EL2_MPU_UPDATE_HVC_ID,
                     (uint32_t)SAIL_BOOT_EL2_MPU_UPDATE_PARAM_ID,
                     0x0U,
                     el1_mpu_syscall_enable_ddr_region_mpu
                    );
