/*
===========================================================================
*/
/**
    @file  sleepSafeRTOS.c
    @brief Sleep Task Implementation in SafeRTOS

*/
/*
    ===========================================================================

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

    ===========================================================================
    File Name          : sleepSafeRTOS.c
    Component Name     : sleep
    Description        : Sleep Task Implementation in SafeRTOS
    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/sleep/src/sailsw1/sleepSafeRtos.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

/*=================================================================================================
**                                        Include files                                          **
=================================================================================================*/
#include "debug_log.h"
#include "types.h"
#include "sleepSafeRtos.h"
#include "errno.h"
#include "sleepEl1.h"
#include "IPCC.h"
#include "common_functions.h"
//#include "mailboxInt_api.h"
//#include "wdt_safertos.h"
#include "uart.h"
#include "md_sail_pm_defs.h"
#include "mailboxExt_api.h"
#include "pwr_controller_el1.h"
#include "sleep_internal.h"
#include "sleep_core.h"
#include "uart.h"
#include "mailboxLib.h"
//#include "mailboxInt_api.h"
#include "osal.h"
#include "isd_drv.h"
#include "isd_resets.h"
#include "isd_os.h"
#include "isd.h"
#include "pwr_controller_cmn.h"
#include "pmicapi.h"
#include "HALhwio.h"
#include "err_fatal.h"
#include "syscall_pub.h"
#include "syscall_hvc.h"
#include "target.h"
#include "commonClient.h"
#include "sailbsp_mutex.h"
#include "i2c.h"
#include "busywait.h"
#include "psailhwio.h"

/*=================================================================================================
**                                   Local macros, variables and constants                       **
==================================================================================================*/

#define SAIL_SLEEP_ACK_TO_TZ   0xAA030000u

#define CORE_3_SLEEP_COMPLETE  0x8u

#define CORE_2_SLEEP_COMPLETE  0x4u

#define CORE_1_SLEEP_COMPLETE  0x2u

/* Number of sleep Tasks */
/* The size of the periodic test task stack - must be a multiple of 64. */
#ifdef SAILSW4
    #define SLEEP_INFO                              __attribute__ ( ( section ("sleep_data" ) ) )
    #define SLEEP_TASK_STACK_SIZE                   ( 1024u )
#else
    #define SLEEP_INFO 
    #define SLEEP_TASK_STACK_SIZE                   ( 4*1024u )
#endif
/* Declare task TCB. */
static StaticTask_t xSleepTaskTCB_core0 = { 0 };
static StaticTask_t xSleepTaskTCB_core1 = { 0 };
static StaticTask_t xSleepTaskTCB_core2 = { 0 };
static StaticTask_t xSleepTaskTCB_core3 = { 0 };

#define SLEEP_QUEUE_LENGTH                ( 2U )
#define SLEEP_QUEUE_ITEM_SIZE             ( 8u )
#define SLEEP_QUEUE_BUFFER_SIZE           ( SLEEP_QUEUE_LENGTH * SLEEP_QUEUE_ITEM_SIZE )

#define DEEP_SLEEP_CORE_LOCK                     (mutex_t *)  (SHR_DEEP_SLEEP)
#define SLEEP_CRITICAL_SECTION_START()           mutex_lock(DEEP_SLEEP_CORE_LOCK)
#define SLEEP_CRITICAL_SECTION_END()             mutex_unlock(DEEP_SLEEP_CORE_LOCK)

#define AOS_SDAM01_MEM_119_ACK_VALUE       (0xAAu)
#define AOS_SDAM01_MEM_119_WRITE_VALUE     (0xBCu)
/* one i2c read takes 60uSec, 1 Sec = 60 * 16666 is the timeout value*/
#define AOS_HANDSHAKE_TIMEOUT_MAX          (0xB71B0) 
/* Declare task stack:
 * The check task stack is protected by an MPU region, so the alignment must
 * follow MPU alignment rules and aligned to a 64-byte boundary. */
SLEEP_INFO static StackType_t xSleepTaskStack_core0[SLEEP_TASK_STACK_SIZE] __attribute__( ( aligned( MEM_ALIGNMENT_64 ) ) ) = { 0 };
SLEEP_INFO static StackType_t xSleepTaskStack_core1[SLEEP_TASK_STACK_SIZE] __attribute__( ( aligned( MEM_ALIGNMENT_64 ) ) ) = { 0 };
SLEEP_INFO static StackType_t xSleepTaskStack_core2[SLEEP_TASK_STACK_SIZE] __attribute__( ( aligned( MEM_ALIGNMENT_64 ) ) ) = { 0 };
SLEEP_INFO static StackType_t xSleepTaskStack_core3[SLEEP_TASK_STACK_SIZE] __attribute__( ( aligned( MEM_ALIGNMENT_64 ) ) ) = { 0 };

SLEEP_INFO static uint8_t xSleepQueueBuffer_core0[SLEEP_QUEUE_BUFFER_SIZE] __attribute__( ( aligned( MEM_ALIGNMENT_4 ) ) ) = { 0 };
SLEEP_INFO static uint8_t xSleepQueueBuffer_core1[SLEEP_QUEUE_BUFFER_SIZE] __attribute__( ( aligned( MEM_ALIGNMENT_4 ) ) ) = { 0 };
SLEEP_INFO static uint8_t xSleepQueueBuffer_core2[SLEEP_QUEUE_BUFFER_SIZE] __attribute__( ( aligned( MEM_ALIGNMENT_4 ) ) ) = { 0 };
SLEEP_INFO static uint8_t xSleepQueueBuffer_core3[SLEEP_QUEUE_BUFFER_SIZE] __attribute__( ( aligned( MEM_ALIGNMENT_4 ) ) ) = { 0 };

SLEEP_INFO QueueHandle_t xSleepQueueHandle = NULL;   
SLEEP_INFO QueueHandle_t xSleepQueueHandle_core0 = NULL;
SLEEP_INFO QueueHandle_t xSleepQueueHandle_core1 = NULL;   
SLEEP_INFO QueueHandle_t xSleepQueueHandle_core2 = NULL;   
SLEEP_INFO QueueHandle_t xSleepQueueHandle_core3 = NULL;   

SLEEP_INFO StaticQueue_t xS_QueueBuffer_core0;
SLEEP_INFO StaticQueue_t xS_QueueBuffer_core1;
SLEEP_INFO StaticQueue_t xS_QueueBuffer_core2;
SLEEP_INFO StaticQueue_t xS_QueueBuffer_core3;

SLEEP_INFO TaskHandle_t xSleepTaskHandle = NULL;

SLEEP_INFO sleepDebugMarker_e xSleepDebugMarker = SLEEP_INVALID_MARKER;
SLEEP_INFO TaskHandle_t xsleep_TaskHandle_core0 = NULL;
SLEEP_INFO TaskHandle_t xsleep_TaskHandle_core1 = NULL;
SLEEP_INFO TaskHandle_t xsleep_TaskHandle_core2 = NULL;
SLEEP_INFO TaskHandle_t xsleep_TaskHandle_core3 = NULL;

SLEEP_INFO uint64 ulCoreStatusMask = 0x0ul;
volatile static uint8 ack_from_core_2 = 0x0;
volatile static uint8 ack_from_core_1 = 0x0;
/*=================================================================================================
**                                   Local function prototypes                                   **
==================================================================================================*/



/*=================================================================================================
**                                   Global function definitions                                 **
==================================================================================================*/



/*=================================================================================================
 @Service name        xSleepSailRTCUSecondaryToWFI
 @Description         HVC call to do RTCU Config for sleep in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              NA
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/


sleepErrType_e xSleepSailRTCUSecondaryToWFI(void)
{
    uint32_t hvcId     = SLEEP_RTCU_SETTING;
    uint32_t paramId   = SLEEP_RTCU_SETTING_PARM_ID;
    uint32_t arg1      = 0;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;
    if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    {
        err_fatal(SLEEP, ERR_FATAL_HVC_CALL_FAILED);
    }

    return (sleepErrType_e) paramId;
}

/*=================================================================================================
 @Service name        xSleepClockDisable
 @Description         HVC call to disable required sailss clock for sleep in EL2
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              NA
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/


sleepErrType_e xSleepClockDisable(void)
{
    uint32_t hvcId     = SLEEP_CLOCK_DISABLE;
    uint32_t paramId   = SLEEP_CLOCK_DISABLE_PARM_ID;
    uint32_t arg1      = 0;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;

    if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
    {
        err_fatal(SLEEP, ERR_FATAL_HVC_CALL_FAILED);
    }

    return (sleepErrType_e) paramId;
}

void vEl2SleepNotify1(sleepModeType_e xSleepState)
{
	uint32_t hvcId     = SLEEP_NOTIFY_EL2;
	uint32_t paramId   = SLEEP_NOTIFY_EL2_PARM_ID;
	uint32_t arg1      = (uint32_t)xSleepState;
	uint32_t arg2      = 0;
	uint32_t arg3      = 0;
	uint32_t arg4      = 0;
	if ( HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4) )
	{   
		err_fatal(SLEEP, ERR_FATAL_HVC_CALL_FAILED);
	}   
}


/*=================================================================================================
 @Service name        vSleepTask
 @Description         Task to take action for sleep
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              NA
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

void vSleepTask(void *pvParameters)
{
    (void)pvParameters;
    BaseType_t xReturn = pdFAIL;
    uint8 xMsg[8];
    uint8 Data[2];
    uint32 ulcpu_ID;
    uartStatusType_e xUartStatus = UART_SUCCESS;
    uint8 IRQ[3] = {39,40,41};
    PCSleepModeType_e xPcMode = PC_MODE_MAX;
    sleepModeType_e xSleepMode = INVALID_SLEEP_MODE;
    uint64 ulSleepCoreStatus = 0x0u;
    volatile uint8  xSDAMvalue = 0x0u;
    volatile uint32 timeout;
	QueueHandle_t *pxSleepQueueHandle=NULL;

    *(volatile uint32*) SLEEP_CORE_STATUS = 0x0u; // Reset Core Status

    ulcpu_ID = get_curr_phys_cpu_num();


    xSleepDebugMarker = SLEEP_TASK_STARTED;
    if(get_curr_phys_cpu_num() ==0){
    	pxSleepQueueHandle=&xSleepQueueHandle;
	}else if(get_curr_phys_cpu_num() ==1){
	    	pxSleepQueueHandle=&xSleepQueueHandle_core1;
	}else if(get_curr_phys_cpu_num() ==2){
	    	pxSleepQueueHandle=&xSleepQueueHandle_core2;
	}else if(get_curr_phys_cpu_num() ==3){
	    	pxSleepQueueHandle=&xSleepQueueHandle_core3;
	}
    for(;;)
    {

        /* Receive msg on queue and parse message */
        xReturn = xFreeRTOSQueueReceive(*pxSleepQueueHandle, &xMsg, freertosMAX_DELAY);
        if ( pdPASS == xReturn )
        {

            if(get_curr_phys_cpu_num() ==0){

                if ( SLEEP_PREP_REQUEST_INTERNAL == xMsg[0])
                {

                    ulcpu_ID = get_curr_phys_cpu_num();

                    xSleepDebugMarker = SLEEP_ENTRY_STARTED;

                    DEBUG_LOG(SAIL_INFO,"[SLEEP]:Prepare Request Received in core %d\r\n",ulcpu_ID);

                    if ( STR_SLEEP_REQ == xMsg[1] )
                    {   
                        xPcMode = PC_MODE_SLEEP;
                        xSleepMode = STR_SLEEP_MODE;
                        DEBUG_LOG(SAIL_INFO,"[SLEEP]:STR_SLEEP_REQ \r\n");
                    }else if ( DEEP_SLEEP_REQ == xMsg[1] )
                    {
                        xPcMode = PC_MODE_DEEPSLEEP;
                        xSleepMode = DEEP_SLEEP_MODE;
                        DEBUG_LOG(SAIL_INFO,"[SLEEP]:DEEP_SLEEP_MODE \r\n");
                    }else
                    {
                        /* added for misra */
                    }

                    if (FALSE == ( DEEP_SLEEP_MODE == xSleepMode &&  TRUE == bSailPmicPresent() ))
                    {
                        /*
                         * In case of STR Disable Dependent/Independent PMIC Disable SEC and NON SEC IRQ 
                         * In case of Deep Sleep Dependent PMIC Disable SEC and NON SEC IRQ 
                         */
                        
                        eISDOS_DeRegisterInterrupt(ISD_TZ_IPC_SEC_INTR, FALSE);
                        eISDOS_DeRegisterInterrupt(ISD_TZ_IPC_NON_SEC_INTR, FALSE);
                    }

                    xSleepDebugMarker = SLEEP_IRQ_CONFIG_DONE;

                    
                    Data[0] = SLEEP_CORE_0_1_COMM;
                    Data[1] = xSleepMode;
					if( pdPASS != xFreeRTOSQueueSend (xSleepQueueHandle_core1, (void*)&Data, 0))
                    {
                        DEBUG_LOG(SAIL_INFO,"[SLEEP]:QueueSend Core0_1 Msg Send\r\n");
                    }else
                    {
                        DEBUG_LOG(SAIL_ERROR,"[SLEEP]:QueueSend Core0_1 Msg Failed\r\n");
                        err_fatal(SLEEP,ERR_FATAL_FAULT_DETECTED);
                    }

                    Data[0] = SLEEP_CORE_0_2_COMM;
					if( pdPASS != xFreeRTOSQueueSend (xSleepQueueHandle_core2, (void*)&Data, 0))
                    {
                        DEBUG_LOG(SAIL_INFO,"[SLEEP]:QueueSend Core0_2 Msg Send\r\n");
                    }else
                    {
                        DEBUG_LOG(SAIL_ERROR,"[SLEEP]:QueueSend Core0_2 Msg Failed\r\n");
                        err_fatal(SLEEP,ERR_FATAL_FAULT_DETECTED);
                    }

                    Data[0] = SLEEP_CORE_0_3_COMM;
                    if (  pdPASS != xFreeRTOSQueueSend (xSleepQueueHandle_core3, (void*)&Data, 0) )
                    {
                        DEBUG_LOG(SAIL_INFO,"[SLEEP]:QueueSend Core0_3 Msg Send\r\n");
                    }else
                    {
                        DEBUG_LOG(SAIL_ERROR,"[SLEEP]:QueueSend Core0_3 Msg Failed\r\n");
                        err_fatal(SLEEP,ERR_FATAL_FAULT_DETECTED);
                    }                    

                    xSleepDebugMarker = SLEEP_CORE_1_2_NOTIFICATION_SENT;

                    vNotifySleepEnterEl1(xSleepMode,get_curr_phys_cpu_num());

                    xSleepDebugMarker = SLEEP_CORE0_EL1_DEINIT_DONE;

                    if ( SLEEP_ERR_FLAG_SUCCESS != xSleepEnter(xSleepMode) ) 
                    {
                        DEBUG_LOG(SAIL_ERROR,"[SLEEP]:xSleepEnter Fail\r\n");
                        err_fatal(SLEEP,ERR_FATAL_FAULT_DETECTED);
                    }

                    xSleepDebugMarker = SLEEP_CORE1_2_ACK_RECEIVED;

                    vFreeRTOSTaskSuspendAll();


                    vFreeRTOSSleepDeInit(); // SafeRTOS Deinit function where Shared Mem register are getting reset
                    

                    vEl2SleepNotify(xSleepMode); // HVC call to notify driver registered to Sleep Driver in EL2

                    xSleepDebugMarker = SLEEP_CORE0_EL2_DEINIT_DONE;
                    
                    if(UART_CONNECTED == bUartConnectionStatus(uartDEBUG_CHANNEL))
                    {
                        xUartStatus = xUartDeInit(uartDEBUG_HW);
                        if( UART_SUCCESS != xUartStatus)
                        {
                            DEBUG_LOG(SAIL_ERROR,"[SLEEP]:xUartDeInit UART_DEBUG_PORT Fail\r\n");
                            err_fatal(SLEEP,ERR_FATAL_FAULT_DETECTED);
                        }
                    }
                    
                    xSleepDebugMarker = SLEEP_CORE0_UART_DEINIT_DONE;

                    /* 8.  RTCU Low Power Programming
                        a.  Please follow Section 2.3 - "R52 Warm Boot Sequence" in RTCU HPG – 
                            https://qualcomm.sharepoint.com/:w:/r/teams/IPCatalog/HPG/Processor/SAILSS_RTCU_HPG.docm?d=w1929fc1739064cb2990d240f6208f85d&csf=1&web=1&e=M7Fv98
                        b.  Please implement only upto Disabling 3 Core WDOGs, 3 cores to Push 
                            to WFI and GIC related programming. Keep the Primary core ON for the further Low Power settings.
                    */

                    xSleepSailRTCUSecondaryToWFI();

                    /* 
                    required  ec-ec  
                    safertosapiENTER_CRITICAL();
                    
                    slMailBox_DeInit();

                    safertosapiEXIT_CRITICAL();*/
                   
                    if(ulcpu_ID < 3)
                    {
						vOsalMaskInterrupt(IRQ[ulcpu_ID]); // TODO:Right now masking the IRQ
														   //can be removed later, once IPCC DEinit is available
                    }

                    vsleepDataUpdateEl1(SLEEP_ENTRY_MAKER);

                    if (STR_SLEEP_MODE == xSleepMode )
                    { 
                        xSleepClockDisable();
                    }
                    // With debug uart removal, in sleep entry all_clock_off signal needs time to get effect. 
                    busywait(80);
                    if ( PC_STATUS_SUCCESS != xPCSleepEnterEL1(xPcMode) )
                    {
                        DEBUG_LOG(SAIL_ERROR,"[SLEEP]:xPCSleepEnterEL1 Error\r\n");
                        err_fatal(SLEEP,ERR_FATAL_FAULT_DETECTED);
                    }

                    xSleepDebugMarker = SLEEP_ENTRY_SEQ_TRIGGERED;

                    vISDSetSAILMDAck(SAIL_SLEEP_ACK_TO_TZ); // Sending Ack Back to TZ

                    if ( DEEP_SLEEP_MODE == xSleepMode && TRUE == bSailPmicPresent() )
                    {
                        timeout = 0u;
                        /* wait for Acknoledge from AOS through SDAM register */
                        while ((AOS_SDAM01_MEM_119_ACK_VALUE != xSDAMvalue) && (timeout < AOS_HANDSHAKE_TIMEOUT_MAX))
                        {  
                            busywait(1u);
                            // i2c read for SDAM (0X000070B7U IS SDAM01_MEM_119 ADDRESS )
                            xI2cRead((uint8) I2C_CHANNEL_ID_3, HWIO_SDAM01_MEM_119_ADDR,1,(uint8*)&xSDAMvalue);
                            timeout++;    
                        }
                        /* Acknoledge back to AOS*/
                        if(AOS_SDAM01_MEM_119_ACK_VALUE == xSDAMvalue)
                        {
                            
                                /*
                                * In case of Deep sleep and independent PMIC, SAIL_PMIC need to be configured
                                * for POFF mode after acknoledgement from AOS.
                                */ 
                                if (PMIC_ERR_FLAG_SUCCESS == xPmicSetResetState(PMIC_POFF))//
                                {
                                    DEBUG_LOG(SAIL_DEBUG,"[Sleep]: PMIC POFF Config Success\r\n");
                                }else
                                {
                                    DEBUG_LOG(SAIL_ERROR,"[Sleep]: PMIC POFF Config Fail\r\n");
                                    err_fatal(SLEEP,ERR_FATAL_FAULT_DETECTED);
                                }
                            xSDAMvalue = AOS_SDAM01_MEM_119_WRITE_VALUE;
                            xI2cWrite((uint8) I2C_CHANNEL_ID_3, HWIO_SDAM01_MEM_119_ADDR,1,(uint8*)&xSDAMvalue);
                            DEBUG_LOG(SAIL_INFO,"[Sleep]:SDAM reg ack success\r\n");
                        }
                        else
                        {
                            /*
                            * In case notifcation from AOSS is not recieved then don't take any action . If you are getting
                            * below print then AOSS is supposed to take action for failure
                            */
                            DEBUG_LOG(SAIL_ERROR,"[Sleep]:SDAM reg ack Fail\r\n");
                        }
                    }
                    low_power_El1();

                }
           }else if(get_curr_phys_cpu_num() ==1){



                if (  SLEEP_CORE_0_1_COMM == xMsg[0] )
                {
                    ulcpu_ID = get_curr_phys_cpu_num();

			ack_from_core_1 = 1; 

                    xSleepMode = xMsg[1];
                   while( ack_from_core_2 == 0){
			if(ack_from_core_2 != 0)
			break;

		   }
                    /*if ( 0x0 != slMailBoxIB_DeInit())
                    {
                         DEBUG_LOG(SAIL_INFO,"[SLEEP]:slMailBoxIB_DeInit Failed \r\n");
                    }*/

                    xSleepDebugMarker = SLEEP_CORE1_REQ_RECEIVED;


                    vNotifySleepEnterEl1(xSleepMode,get_curr_phys_cpu_num()); //notifying all the task and driver register
                                                       // device is going into sleep state

                    xSleepDebugMarker = SLEEP_CORE1_EL1_DEINT_DONE;

                    vFreeRTOSTaskSuspendAll();

                    vFreeRTOSSleepDeInit(); // SafeRTOS Deinit function where Shared Mem register are getting reset

                    vEl2SleepNotify(xSleepMode);

                    xSleepDebugMarker = SLEEP_CORE1_EL2_DEINT_DONE;

                    if ( SLEEP_ERR_FLAG_SUCCESS == xSleepDriverStatusEl1(get_curr_phys_cpu_num()) ) // wait function to check if all register tasks
                                                                      // went to sleep state
                    {
                        /* 
                        required  ec-ec
                        safertosapiENTER_CRITICAL();
                        
                        slMailBox_DeInit();

                        safertosapiEXIT_CRITICAL();*/
                      
                    	if(ulcpu_ID < 3)
                    	{
							vOsalMaskInterrupt(IRQ[ulcpu_ID]);// TODO:Right now masking the IRQ
														   //can be removed later, once IPCC DEinit is available
                    	}

                        xSleepDebugMarker = SLEEP_CORE1_COMPLETE;

                        SLEEP_CRITICAL_SECTION_START();

                        ulSleepCoreStatus = in_dword(SLEEP_CORE_STATUS);

                        *(volatile uint32*) SLEEP_CORE_STATUS = ulSleepCoreStatus|CORE_1_SLEEP_COMPLETE; 

                        SLEEP_CRITICAL_SECTION_END();

			ack_from_core_1 = 1; 
                       low_power_El1();
                    }

                }

            } else if(get_curr_phys_cpu_num() ==2){



                if ( SLEEP_CORE_0_2_COMM == xMsg[0])
                {
                    ulcpu_ID = get_curr_phys_cpu_num();

                    DEBUG_LOG(SAIL_INFO,"[SLEEP]:vSleepTask in core %d\r\n",ulcpu_ID); // Placeholder for core2

                    xSleepMode = xMsg[1];
			ack_from_core_2 = 1;
                    /*if ( 0x0 != slMailBoxIB_DeInit())
                    {
                         DEBUG_LOG(SAIL_INFO,"[SLEEP]:slMailBoxIB_DeInit Failed \r\n");
                    }*/

                    xSleepDebugMarker = SLEEP_CORE2_REQ_RECEIVED;

                    vNotifySleepEnterEl1(xSleepMode,ulcpu_ID); //notifying all the task and driver register
                                                    // device is going into sleep state

                    vFreeRTOSTaskSuspendAll();

                    vFreeRTOSSleepDeInit(); // SafeRTOS Deinit function where Shared Mem register are getting reset

                    xSleepDebugMarker = SLEEP_CORE2_EL1_DEINT_DONE;

                    vEl2SleepNotify(xSleepMode);

                    xSleepDebugMarker = SLEEP_CORE2_EL2_DEINT_DONE;

                    if ( SLEEP_ERR_FLAG_SUCCESS == xSleepDriverStatusEl1(get_curr_phys_cpu_num()) ) // wait function to check if all register tasks
                                                                          // went to sleep state
                    {

                        /* 
                        required  ec-ec 
                        safertosapiENTER_CRITICAL();
                        
                        slMailBox_DeInit();

                        safertosapiEXIT_CRITICAL();*/
                        
                        if(ulcpu_ID < 3)
                        {
							vOsalMaskInterrupt(IRQ[ulcpu_ID]);// TODO:Right now masking the IRQ
															 //can be removed later, once IPCC DEinit is available
                        }

                        xSleepDebugMarker = SLEEP_CORE2_COMPLETE;

                        SLEEP_CRITICAL_SECTION_START();

                        ulSleepCoreStatus = in_dword(SLEEP_CORE_STATUS);

                        *(volatile uint32*) SLEEP_CORE_STATUS = ulSleepCoreStatus|CORE_2_SLEEP_COMPLETE;

                        SLEEP_CRITICAL_SECTION_END();
			ack_from_core_2 = 1;
                        
                        low_power_El1();
                    }
                }

            }else if(get_curr_phys_cpu_num() ==3){




                if (  SLEEP_CORE_0_3_COMM == xMsg[0] )
                {

                    xSleepMode = xMsg[1];
                                        
                    vNotifySleepEnterEl1(xSleepMode,get_curr_phys_cpu_num()); //notifying all the task and driver register
                                                    // device is going into sleep state

                    vFreeRTOSTaskSuspendAll();

                    vFreeRTOSSleepDeInit(); // SafeRTOS Deinit function where Shared Mem register are getting reset

                    if ( SLEEP_ERR_FLAG_SUCCESS == xSleepDriverStatusEl1(get_curr_phys_cpu_num()) ) // wait function to check if all register tasks
                                                                          // went to sleep state
                    {

                        xSleepDebugMarker = SLEEP_CORE3_COMPLETE;

                        SLEEP_CRITICAL_SECTION_START();

                        ulSleepCoreStatus = in_dword(SLEEP_CORE_STATUS);

                        *(volatile uint32*) SLEEP_CORE_STATUS = ulSleepCoreStatus|CORE_3_SLEEP_COMPLETE;

                        SLEEP_CRITICAL_SECTION_END();

                        low_power_El1();
                    }
                }

            }
        }
    }
}


/*=================================================================================================
 @Service name        xSleepTaskInit
 @Description         Init Function to schedule sleep task
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              portBaseType <pdFail , pdPass> Based on status of task creation
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

BaseType_t xSleepTaskInit_core0( CPUIdType_e           xSchdCore,
                                     UBaseType_t  xTaskPrior )
{
    BaseType_t xResult = pdFAIL;
    uint64 ullWakeIRQMask = 0x0u;
    xSleepDebugMarker = SLEEP_INVALID_MARKER;
	UBaseType_t uxCoreAffinityMask;
	uxCoreAffinityMask = ( 1 << xSchdCore);
	TaskParams_t xInitTaskParameters2 = {  
		.pvTaskCode     = vSleepTask,
		.pcName         = "sleep_task",
		.usStackDepth   = SLEEP_TASK_STACK_SIZE,
		.pvParameters   = NULL,
		.uxPriority     = (xTaskPrior),
		.puxStackBuffer = xSleepTaskStack_core0,
		.xRegions               =       {
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL }
		},
		.pxTaskBuffer   = &xSleepTaskTCB_core0
	};
	xResult = xFreeRTOSTaskCreateAffinitySet(&xInitTaskParameters2, uxCoreAffinityMask, &xsleep_TaskHandle_core0);
	if ( xResult != pdPASS){
		DEBUG_LOG(SAIL_WARNING, " [core 0] sleepInit task failed\r\n");
	}else{
		DEBUG_LOG(SAIL_WARNING, " [core 0] sleepInit task created\r\n");
	}
	
	    mutex_init(DEEP_SLEEP_CORE_LOCK);

    /* Configure Wakeup Source */

        //ullWakeIRQMask = 0x2;  sailtimer wake
        //ullWakeIRQMask = 0x1000002; sailtimer wake and gpio 53
        //ullWakeIRQMask = 0x31C0002; sailtimer wake and CAN GPIOs
        //ullWakeIRQMask = 0x1; sailpwr ready
        //ullWakeIRQMask = 0x210; external wake

        for ( uint8 ucCoreNum = 1u ; ucCoreNum < SAILBSP_CPU_COUNT  ; ucCoreNum++ )
        {
            if( ucCoreNum%SAILBSP_CPUS_PER_CLUSTER && IsClusterInLockStepMode(ucCoreNum/SAILBSP_CPUS_PER_CLUSTER))
            {
                continue;
            }
            ulCoreStatusMask = ulCoreStatusMask|(1<<ucCoreNum);
        }

        ullWakeIRQMask = 0x10; // Config md_sleep_tmr_expiry as wake up source

        if(PC_STATUS_SUCCESS !=  xPCConfigureWakeIRQEL1(~ullWakeIRQMask))
        {
            return pdFAIL;
        }
	return xResult;
} 
BaseType_t xSleepTaskInit_core1( CPUIdType_e           xSchdCore,
		UBaseType_t  xTaskPrior )
{
	BaseType_t xResult = pdFAIL;
	UBaseType_t uxCoreAffinityMask;
	uxCoreAffinityMask = ( 1 << xSchdCore);
	TaskParams_t xInitTaskParameters2 = {  
		.pvTaskCode     = vSleepTask,
		.pcName         = "sleep_task",
		.usStackDepth   = SLEEP_TASK_STACK_SIZE,
		.pvParameters   = NULL,
		.uxPriority     = (xTaskPrior),
		.puxStackBuffer = xSleepTaskStack_core1,
		.xRegions               =       {
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL }
		},
		.pxTaskBuffer   = &xSleepTaskTCB_core1
	};
	xResult = xFreeRTOSTaskCreateAffinitySet(&xInitTaskParameters2, uxCoreAffinityMask, &xsleep_TaskHandle_core1);
	if ( xResult != pdPASS){
		DEBUG_LOG(SAIL_WARNING, " [core 1] sleepInit task failed\r\n");
	}else{
		DEBUG_LOG(SAIL_WARNING, " [core 1] sleepInit task created\r\n");
	}
	return xResult;
} 
BaseType_t xSleepTaskInit_core2( CPUIdType_e           xSchdCore,
		UBaseType_t  xTaskPrior )
{
	BaseType_t xResult = pdFAIL;
	UBaseType_t uxCoreAffinityMask;
	uxCoreAffinityMask = ( 1 << xSchdCore);
	TaskParams_t xInitTaskParameters2 = {  
		.pvTaskCode     = vSleepTask,
		.pcName         = "sleep_task",
		.usStackDepth   = SLEEP_TASK_STACK_SIZE,
		.pvParameters   = NULL,
		.uxPriority     = (xTaskPrior),
		.puxStackBuffer = xSleepTaskStack_core2,
		.xRegions               =       {
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL }
		},
		.pxTaskBuffer   = &xSleepTaskTCB_core2
	};
	xResult = xFreeRTOSTaskCreateAffinitySet(&xInitTaskParameters2, uxCoreAffinityMask, &xsleep_TaskHandle_core2);
	if ( xResult != pdPASS){
		DEBUG_LOG(SAIL_WARNING, " [core 2] sleepInit task failed\r\n");
	}else{
		DEBUG_LOG(SAIL_WARNING, " [core 2] sleepInit task created\r\n");
	}
	return xResult;
}

BaseType_t xSleepTaskInit_core3( CPUIdType_e           xSchdCore,
		UBaseType_t  xTaskPrior )
{
	BaseType_t xResult = pdFAIL;
	UBaseType_t uxCoreAffinityMask;
	uxCoreAffinityMask = ( 1 << xSchdCore);
	TaskParams_t xInitTaskParameters2 = {   
		.pvTaskCode     = vSleepTask,
		.pcName         = "sleep_task",
		.usStackDepth   = SLEEP_TASK_STACK_SIZE,
		.pvParameters   = NULL,
		.uxPriority     = (xTaskPrior ),
		.puxStackBuffer = xSleepTaskStack_core3,
		.xRegions               =       {
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL },
			{ NULL, 0UL, 0UL }
		},
		.pxTaskBuffer   = &xSleepTaskTCB_core3
	};
	xResult = xFreeRTOSTaskCreateAffinitySet(&xInitTaskParameters2, uxCoreAffinityMask, &xsleep_TaskHandle_core3);
	if ( xResult != pdPASS){
		DEBUG_LOG(SAIL_WARNING, " [core 2] sleepInit task failed\r\n");
	}else{
		DEBUG_LOG(SAIL_WARNING, " [core 2] sleepInit task created\r\n");
	}
	return xResult;
}



/*=================================================================================================
 @Service name        xSleep_Task_Resources_Init
 @Description         Resource Init Function to create task Queue
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              portBaseType <pdFail , pdPass> Based on status of task creation
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

BaseType_t xSleep_Task_Resources_Init(CPUIdType_e xSchdCore)
{
    BaseType_t xResult = pdPASS ;
	/* Create Queue */
	xResult = xFreeRTOSQueueCreate(xSleepQueueBuffer_core0,SLEEP_QUEUE_LENGTH,SLEEP_QUEUE_ITEM_SIZE,&xSleepQueueHandle,&xS_QueueBuffer_core0);
	if( xResult != pdPASS ){
		    DEBUG_LOG(SAIL_WARNING, " ######### [SLEEP] create Queue on core 0 Failed\n\r");
	}
	xResult = xFreeRTOSQueueCreate(xSleepQueueBuffer_core1,SLEEP_QUEUE_LENGTH,SLEEP_QUEUE_ITEM_SIZE,&xSleepQueueHandle_core1,&xS_QueueBuffer_core1);
	if( xResult != pdPASS ){
		    DEBUG_LOG(SAIL_WARNING, " ######## [SLEEP] create Queue on core 1 Failed\n\r");
	}
	xResult = xFreeRTOSQueueCreate(xSleepQueueBuffer_core2,SLEEP_QUEUE_LENGTH,SLEEP_QUEUE_ITEM_SIZE,&xSleepQueueHandle_core2,&xS_QueueBuffer_core2);
	if( xResult != pdPASS ){
		    DEBUG_LOG(SAIL_WARNING, " ######## [SLEEP] create Queue on core 2 Failed\n\r");
	}

    return xResult;
}


/*=================================================================================================
**                                        Local function definitions                             **
=================================================================================================*/

/**********************************************************************************************************
**                                  End of file sleepSafeRtos.c                                          **
**********************************************************************************************************/
