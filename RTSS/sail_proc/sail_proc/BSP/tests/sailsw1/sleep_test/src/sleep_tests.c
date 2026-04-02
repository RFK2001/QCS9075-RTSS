/*******************************************************************************
**                                                                            **
** Copyright (C)  2020 Qualcomm Technologies, Inc. (2020)                     **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Qualcomm       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME     : sleep_test.c                                               **
**                                                                            **
**  VERSION      : 1.0.0                                                      **
**                                                                            **
**  DATE         : 2020-6-01                                                  **
**                                                                            **
**  PLATFORM     : Qualcomm SMSS                                              **
**                                                                            **
**  AUTHOR       : SMSS SW DEV                                                **
**                                                                            **
**  VENDOR       : Qualcomm Technologies, Inc.                                **
**                                                                            **
**  DESCRIPTION  : i2c test file                                              **
**                                                                            **
**  SPECIFICATION(S) : Unit test specification                                **
**                                                                            **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include <stdio.h>
#include "tests.h"
#include "sleepEl1.h"
#include "sail_pwr_cntrl_hwio.h"
#include "syscall_pub.h"
#include "sleep_cmm.h"
#include "syscall_hvc.h"
//#include "sleepFreeRtos.h"
#include "sleepSafeRtos.h"
#include "sleep_internal.h"
#include "debug_log.h"
#include "HALhwio.h"
#include "pwr_controller_el1.h"
#include "pwr_controller_cmn.h"

uint32 ulTestSleepHandle;
#define SLEEP_INFO                              __attribute__ ( ( section ("sleep_data" ) ) )
#define SLEEP_TASK_STACK_SIZE                   ( 1024u )

extern QueueHandle_t xSleepQueueHandle ;   
extern QueueHandle_t xSleepQueueHandle_core1;   
extern QueueHandle_t xSleepQueueHandle_core2;   
extern QueueHandle_t xSleepQueueHandle_core3; 

/*******************************************************************************
**                Private Macro Definitions                                   **
*******************************************************************************/

/*******************************************************************************
**                Global variables                                            **
*******************************************************************************/


/*========================================================================================================
 @Service name        prvSemaphoreCallBackFunc
 @Description         DeInit Call Back to register to sleep driver
 @param[in]           eState -> SLEEP_ENTRY = arg from sleep driver to Deinit Test Driver
                                SLEEP_ABORT = arg from sleep driver in case sleep Driver want to abort sleep
 @param[out]          NA
 @param[in, out]      NA
 @return              void
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 =========================================================================================================*/

static void prvSemaphoreCallBackFunc( const sleepModeType_e eState )
{
    DEBUG_LOG(SAIL_ERROR,"###### prvSemaphoreCallBackFunc\n\r");
    BaseType_t    xQReturn = pdFAIL;
 //   if(( STR_SLEEP_MODE == eState ) || (DEEP_SLEEP_MODE == eState))
    {
	uint8 cpu_id = get_curr_phys_cpu_num();
        if (SLEEP_ERR_FLAG_SUCCESS == xSleepDriverAckEl1(ulTestSleepHandle,DRIVER_SLEEP,cpu_id))
        {

        }
    } 
}



void vsleepGetData(sleepDebugInformation *pSleepdata)
{
    uint32_t hvcId     = SLEEP_GET_DATA;
    uint32_t paramId   = SLEEP_GET_DATA_PARM_ID;
    uint32_t arg1      = (uint32_t)pSleepdata;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    int32_t check = 0;
DEBUG_LOG(SAIL_WARNING,"HVC ID-:%d   0x%x\r\n",hvcId,hvcId);
DEBUG_LOG(SAIL_WARNING,"Param ID-:%d   0x%x\r\n",paramId,paramId);
    //if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    check = hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4);
DEBUG_LOG(SAIL_WARNING,"check-:%d\r\n",check);
    if ( HVC_SUCCESS != check )
    {
        /* TODO: Implement error handler or log */
        while(1);
    }
}


/*
*
*
	<<<<<<<<<<<< xTestSleepWrapper >>>>>>>>>>>>>>>
*
*
 */

TESTerrorType_e xTestSleepWrapper(void)
{
	uint8* find;
	BaseType_t xQSendStatus = pdFAIL;
	uint8 xMsg[8];
	uint8 ucSleepRequest = 0x0u;
	xMsg[0] = SLEEP_PREP_REQUEST_INTERNAL;
	sleepDebugInformation xSleepdata = {0};
	xMsg[1] = STR_SLEEP_REQ;
	find = APPL_SAIL_Shell_gettoken(NULL);
	uint64 ullWakeIRQMask = 0x200;
	BaseType_t xWasPrivileged;

	uint32 ulPCBaseAddress = SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE;

	if ( APPL_SAIL_Shell_stricmp("info",(char*)find) )
	{
		BaseType_t xReturn = pdTRUE;
		//xWasPrivileged = portRAISE_PRIVILEGE();
		vsleepGetData(&xSleepdata);
		//portRESTORE_PRIVILEGE( xWasPrivileged );
		DEBUG_LOG(SAIL_INFO,"xSleepdata.entryTimeStamp %lld microSecond \r\n",xSleepdata.entryTimeStamp);
		DEBUG_LOG(SAIL_INFO,"xSleepdata.exitTimeStamp %lld microSecond\r\n",xSleepdata.exitTimeStamp);
		DEBUG_LOG(SAIL_INFO,"xSleepdata.sleepCount %d \r\n",xSleepdata.sleepCount);
		DEBUG_LOG(SAIL_INFO,"xSleepdata.TimeElapseInSleep %lld microSecond\r\n",xSleepdata.TimeElapseInSleep);
	}
	else if ( APPL_SAIL_Shell_stricmp("deep",(char*)find) )
	{
		xMsg[1] = DEEP_SLEEP_REQ;
		ucSleepRequest = 0x1u;
	}else if ( APPL_SAIL_Shell_stricmp("tmr",(char*)find) )
	{
		ullWakeIRQMask = 0x2; // Config pc_sleep_tmr_wake_irq
//		   HWIO_SAILSS_PC_SEQ_MEM_m_OUTI(ulPCBaseAddress,24,0x50115005);
//                HWIO_SAILSS_PC_SEQ_MEM_m_OUTI(ulPCBaseAddress,26,0x40120005);
  // /             HWIO_SAILSS_PC_SEQ_MEM_m_OUTI(ulPCBaseAddress,28,0x50150005);
   //             HWIO_SAILSS_PC_SEQ_MEM_m_OUTI(ulPCBaseAddress,36,0x40130005);
     //           HWIO_SAILSS_PC_SEQ_MEM_m_OUTI(ulPCBaseAddress,42,0x40110005);
       //         HWIO_SAILSS_PC_SEQ_MEM_m_OUTI(ulPCBaseAddress,44,0x40140005);
         //       HWIO_SAILSS_PC_SEQ_MEM_m_OUTI(ulPCBaseAddress,51,0x00055005);
		if(PC_STATUS_SUCCESS !=  xPCConfigureWakeIRQEL1(~ullWakeIRQMask))
		{
			DEBUG_LOG(SAIL_ERROR,"[Sleep_Test]:SAIL Uart Failed\n\r");
		}else
		{
			DEBUG_LOG(SAIL_WARNING,"[Sleep_Test]:SAIL Uart Success\n\r");
		}
		xQSendStatus = xFreeRTOSQueueSend(xSleepQueueHandle, &xMsg, 0);

		if ( xQSendStatus == pdPASS)
		{
			DEBUG_LOG(SAIL_INFO,"[Sleep_Test]:Sleep Request Sent SuccessFull\n\r");
		}else
		{
			DEBUG_LOG(SAIL_INFO,"[Sleep_Test]:Sleep Request Sent Failed\n\r");
		}
	}
	else if ( APPL_SAIL_Shell_stricmp("uart",(char*)find) )
	{
		ullWakeIRQMask = 0x200; // GPIO7 as wake up source
		   HWIO_SAILSS_PC_SEQ_MEM_m_OUTI(ulPCBaseAddress,24,0x50115005);
                HWIO_SAILSS_PC_SEQ_MEM_m_OUTI(ulPCBaseAddress,26,0x40120005);
                HWIO_SAILSS_PC_SEQ_MEM_m_OUTI(ulPCBaseAddress,28,0x50150005);
                HWIO_SAILSS_PC_SEQ_MEM_m_OUTI(ulPCBaseAddress,36,0x40130005);
                HWIO_SAILSS_PC_SEQ_MEM_m_OUTI(ulPCBaseAddress,42,0x40110005);
                HWIO_SAILSS_PC_SEQ_MEM_m_OUTI(ulPCBaseAddress,44,0x40140005);
                HWIO_SAILSS_PC_SEQ_MEM_m_OUTI(ulPCBaseAddress,51,0x00055005);

		if(PC_STATUS_SUCCESS !=  xPCConfigureWakeIRQEL1(~ullWakeIRQMask))
		{
			DEBUG_LOG(SAIL_ERROR,"[Sleep_Test]:SAIL Uart Failed\n\r");
		}else
		{
			DEBUG_LOG(SAIL_WARNING,"[Sleep_Test]:SAIL Uart Success\n\r");
		}
		xQSendStatus = xFreeRTOSQueueSend(xSleepQueueHandle, &xMsg, 0);

		if ( xQSendStatus == pdPASS)
		{
			DEBUG_LOG(SAIL_INFO,"[Sleep_Test]:Sleep Request Sent SuccessFull\n\r");
		}else
		{
			DEBUG_LOG(SAIL_INFO,"[Sleep_Test]:Sleep Request Sent Failed\n\r");
		}
	}
	else if ( APPL_SAIL_Shell_stricmp("sail",(char*)find) )
	{
		ullWakeIRQMask = 0x200; // GPIO7 as wake up source
		DEBUG_LOG(SAIL_INFO,"[Sleep_Test]:SAIL StandAlone PC_SEQ Setting Applied\n\r");
		/* 
		 * Below code is to update Sequencer code of SAIL PC for SAIL
		 * StandAlone Configuration needed.
		 */
		HWIO_SAILSS_PC_SEQ_MEM_m_OUTI(ulPCBaseAddress,24,0x50115005);
		HWIO_SAILSS_PC_SEQ_MEM_m_OUTI(ulPCBaseAddress,26,0x40120005);
		HWIO_SAILSS_PC_SEQ_MEM_m_OUTI(ulPCBaseAddress,28,0x50150005);
		HWIO_SAILSS_PC_SEQ_MEM_m_OUTI(ulPCBaseAddress,36,0x40130005);
		HWIO_SAILSS_PC_SEQ_MEM_m_OUTI(ulPCBaseAddress,42,0x40110005);
		HWIO_SAILSS_PC_SEQ_MEM_m_OUTI(ulPCBaseAddress,44,0x40140005);
		HWIO_SAILSS_PC_SEQ_MEM_m_OUTI(ulPCBaseAddress,51,0x00055005);
		ucSleepRequest = 0x1u;

	}else if ( APPL_SAIL_Shell_stricmp("md",(char*)find) )
	{
		ullWakeIRQMask = 0x10;  // Config md_sleep_tmr_expiry as wake up source
		DEBUG_LOG(SAIL_INFO,"[Sleep_Test]:MD_SAIL PC_SEQ Setting Applied\n\r");
		ucSleepRequest = 0x1u;
	}else
	{
		DEBUG_LOG(SAIL_INFO,"[Sleep_Test]:Invalid Sleep Cmd\n\r");
	}

	if ( 0x1 == ucSleepRequest )
	{
		//xWasPrivileged = portRAISE_PRIVILEGE();

		if(PC_STATUS_SUCCESS !=  xPCConfigureWakeIRQEL1(~ullWakeIRQMask))
		{
			DEBUG_LOG(SAIL_INFO,"[Sleep_Test]:xPCConfigureWakeIRQEL1 Failed\n\r");
		}

		if ( ulTestSleepHandle == 0u )
		{
			uint8 cpu_id = get_curr_phys_cpu_num();
			if ( SLEEP_ERR_FLAG_SUCCESS != xSleepRegisterCallBackEl1(&prvSemaphoreCallBackFunc,&ulTestSleepHandle,get_curr_phys_cpu_num()))
			{
				DEBUG_LOG(SAIL_INFO,"[Sleep_Test]:prvSemaphoreCallBackFunc Sleep Reg Failed\n\r");
			}else{
				DEBUG_LOG(SAIL_WARNING,"....[SLEEP] Sleep test on Core %d \n\r",cpu_id);

			}

		}
		//portRESTORE_PRIVILEGE( xWasPrivileged );
		xQSendStatus = xFreeRTOSQueueSend(xSleepQueueHandle, &xMsg, 0);

		if ( xQSendStatus == pdPASS)
		{
			DEBUG_LOG(SAIL_INFO,"[Sleep_Test]:Sleep Request Sent SuccessFull\n\r");
		}else
		{
			DEBUG_LOG(SAIL_INFO,"[Sleep_Test]:Sleep Request Sent Failed\n\r");
		}
	}

	return MODULE_TEST_PASSED;
}
