/*
===========================================================================
*/
/**
    @file  psailSafeRtos.c
    @brief This file contains PSAIL safeRtos API implementation for MD PMIC monitoring 

*/
/*
    ===========================================================================

    Copyright (c) 2021-2022 Qualcomm Technologies, Inc.
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

    $Header:   $
    $DateTime:  $
    $Author:   $

    ===========================================================================
*/

/*=================================================================================================
**                                        Include files                                          **
=================================================================================================*/
#include "debug_log.h"
#include "types.h"
#include "gpio_summary_intr.h"
#include "gpio.h"
#include "HALhwio.h"
#include "hw_io.h"
#include "gpio.h"
#include "isd.h"
#include "psailInternal.h"
#include "timetick.h"
#include "spinor_el1_api.h"
#include "psail.h"
#include "sleepEl1.h"
#include "msmhwiobase.h"
//#include "fusa.h"
#include "common_functions.h"
//#include "fusa_serv.h"
#include "chipinfo.h"
#include "chipinfodefs.h"
#include "platforminfodefs.h"
#include "pmicapi.h"
#include "Crashdbg_api.h"

/*=================================================================================================
**                                   Local macros, variables and constants                       **
==================================================================================================*/

extern QueueHandle_t xPsailQueueHandle;

extern  TaskHandle_t xPsailTaskHandle;

extern psailDebugType_e ucPsailDebugMode;
/* Number of PSAIL Tasks */
/* The size of the periodic test task stack - must be a multiple of 64. */
#define PSAIL_TASK_STACK_SIZE                   ( 4096u )
/* Declare task TCB. */
static StaticTask_t xPsailTaskTCB = { 0 };

#define PSAIL_QUEUE_LENGTH                ( 1U )
#define PSAIL_QUEUE_ITEM_SIZE             ( sizeof(Psail_QueueMsgType) )
#define PSAIL_QUEUE_BUFFER_SIZE           ( PSAIL_QUEUE_LENGTH * PSAIL_QUEUE_ITEM_SIZE )
#define PSAIL_PINBIST_FAILED              ( 0xFFu )

/* Declare task stack:
 * The check task stack is protected by an MPU region, so the alignment must
 * follow MPU alignment rules and aligned to a 64-byte boundary. */
static StackType_t xPsailTaskStack[PSAIL_TASK_STACK_SIZE] __attribute__( ( aligned( MEM_ALIGNMENT_64 ) ) ) = { 0 };
static uint8_t xPsailQueueBuffer[PSAIL_QUEUE_BUFFER_SIZE] __attribute__( ( aligned( MEM_ALIGNMENT_4 ) ) ) = { 0 };
StaticQueue_t xStaticPsailQueueBuffer;

PSAIL_DATA psailDebugType_e ucPsailDebugMode = PSAIL_DEBUG_OFF; 

PSAIL_DATA QueueHandle_t xPsailQueueHandle = NULL;

PSAIL_DATA TaskHandle_t xPsailTaskHandle = NULL;

PSAIL_DATA static uint32 ulPSAILSleepHandle = 0;

/*=================================================================================================
**                                   Local function prototypes                                   **
==================================================================================================*/

static void prvPSAILIntrHandler(void *args);
static PSAILStatusType_e prvPSAILIntrReg(void);
static PSAILStatusType_e xDumpDataInSpiNOR(PsailSPINORDataType *xDataSPINOR);
static void prvPsailTask(void *pvParameters);
static void prvPSAILDeInit_Sleep( const sleepModeType_e eState );

/*=================================================================================================
**                                   Global function definitions                                 **
==================================================================================================*/

/*=================================================================================================
 @Service name        xPsailTaskInit
 @Description         Init Function to take schedule PSAIL task
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

BaseType_t xPsailTaskInit( CPUIdType_e           xSchdCore,
                                     UBaseType_t  xTaskPrior )
{
    BaseType_t xResult = pdFAIL;
	UBaseType_t uxCoreAffinityMask;
    /* The structure passed to xSAILTaskCreate() to create the check task. */
    TaskParams_t xInitTaskParameters =
    {
        .pvTaskCode =prvPsailTask,                 /* The function that implements the task being created. */
        .pcName = "PsailTask",                 /* The name of the task being created. The kernel does not use this itself, it's just to assist debugging. */
        .pxTaskBuffer =&xPsailTaskTCB,              /* The buffer allocated for use as the task TCB. */
        .puxStackBuffer =xPsailTaskStack,             /* The buffer allocated for use as the task stack. */
        .usStackDepth =PSAIL_TASK_STACK_SIZE,      /* The size of the buffer allocated for use as the task stack - note this is in BYTES! */
        .pvParameters =NULL,                               /* The task parameter, not used in this case. */
        .uxPriority =xTaskPrior,                         /* The priority assigned to the task being created. */
		.xRegions = {				   /* The MPU task parameters. */
			{NULL, 0UL, 0UL}, /* No additional region definitions are required. */
			{NULL, 0UL, 0UL},
			{NULL, 0UL, 0UL},
			{NULL, 0UL, 0UL},
			{NULL, 0UL, 0UL},
			{NULL, 0UL, 0UL}},

    };

    /* Create the check task. */
	uxCoreAffinityMask = (1 << xSchdCore);  //Mapped to core 2 from core 0 for testing
	xResult = xFreeRTOSTaskCreateAffinitySet( &xInitTaskParameters,uxCoreAffinityMask, /* The structure containing the task parameters created at the start of this function. */
			&xPsailTaskHandle );

    return xResult;
}

/*=================================================================================================
 @Service name        xPsail_Task_Resources_Init
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

BaseType_t xPsail_Task_Resources_Init(CPUIdType_e xSchdCore)
{
    BaseType_t xResult = pdPASS ;
        /* Create Queue */
    xResult = xFreeRTOSQueueCreate(xPsailQueueBuffer, PSAIL_QUEUE_LENGTH, PSAIL_QUEUE_ITEM_SIZE, &xPsailQueueHandle,&xStaticPsailQueueBuffer);

    return xResult;
}


/*=================================================================================================
**                                        Local function definitions                             **
=================================================================================================*/

/*=================================================================================================
 @Service name        prvPsailTask
 @Description         Task to take action from sail side to collect PSAIL logs
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

static void prvPsailTask(void *pvParameters)
{
    (void)pvParameters;
    PSAILStatusType_e xRetStatus = PSAIL_SUCCESS;
    BaseType_t xReturn = pdFAIL;
    Psail_QueueMsgType xMsgUnblock = {PSAIL_ERROR_OCCURED};
    Psail_QueueMsgType xMsg = {0};
    uint8 ucCountIndex = 0x0u;
    uint8 ucCountFaultPerPsail = 0x0u;
    PsailSPINORDataType xDataSPINOR = {0};
    uint64 warm_boot_status = in_dword(WARM_BOOT_STATUS);
#if 0	
    FUSAQueueMsgType xPsailErrorData = {.eEventId = FUSA_ERROR_518,
                                        .eEventType = FUSA_FATAL,
                                        .eEventDomain = MD,
                                        .eEventSource = PMIC_FAULT,
                                        };
#endif
    ChipInfoFamilyType eFamilyId = ChipInfo_GetChipFamily();
    ChipInfoVersionType nVersion = ChipInfo_GetChipVersion();
    pmicErrFlagType_e xErrFlag = PMIC_ERR_FLAG_SUCCESS;

    /*
      Since PSAIL FastPlus mode setting in present in PSI loading for K1 Kobras
      and since K1 kobras are only present in Lemans V1 Boards
      wait for DDR Ready state on MD side. DDR Ready state
      comes after PMICInit is done on MD side - i.e. PSI is loaded.
    */
    if( (eFamilyId == CHIPINFO_FAMILY_LEMANSAU) && (nVersion == CHIPINFO_VERSION(1u,0u)) )
    {
        while ( S1_READY_SUCCESS != eISDGetStatus(ISD_GET_S1_READY_STATUS))
        {
            vFreeRTOSTaskDelay(10u);
        }

        if ( S1_READY_SUCCESS == eISDGetStatus(ISD_GET_S1_READY_STATUS) )
        {   
            // Added for Misra 
        }
        else
        {
            DEBUG_LOG(SAIL_INFO,"PSAIL:DDR_NOT_READY MD side!!\r\n");
        }
    }
    else
    {
        // Added for Misra
    }
    xRetStatus = xPsailDriverInit();
    if ( xRetStatus == PSAIL_SUCCESS )
    {
        DEBUG_LOG(SAIL_DEBUG,"[PSAIL] PSAIL Driver Initialized\r\n");
        // Added for Misra 
    }
    else if ( xRetStatus == PSAIL_IVI_PFLR_Mode )
    {
        xReturn = xFreeRTOSQueueSend(xPsailQueueHandle,&xMsgUnblock, freertosMAX_DELAY);
        //AssertSMErr(true, SMErr_BSP_TRIG_REQ, fusa_DEFAULT_ERR_ID);
    }
    else
    {
        //AssertSMErr(true, SMErr_BSP_TRIG_REQ, fusa_DEFAULT_ERR_ID);
        DEBUG_LOG(SAIL_INFO,"[PSAIL] Could not Initiate Psail Information. SM Error asserted\r\n");
    }

    if ( DEVICE_IS_IN_WARM_BOOT != warm_boot_status )
    {
        
        xRetStatus = xPinBIST(); // Call to Psail Driver to do Pin BIST
        if ( xRetStatus == PSAIL_SUCCESS )
        {
            // Added for Misra 
        }else
        {
           // xPsailErrorData.ucErrData[0] = PSAIL_PINBIST_FAILED;
            // TODO: Send Message to SSM that PinBIST Failed.
            DEBUG_LOG(SAIL_INFO,"PSAIL:xPinBISTEL1 Failed. SM Error asserted\r\n");
            // Collect Logs if PinBIST fails.
            ucPsailDebugMode = PSAIL_DEBUG_ON; 
            xReturn = xFreeRTOSQueueSend(xPsailQueueHandle,&xMsgUnblock, freertosMAX_DELAY);
        }
    }
    else{
        DEBUG_LOG(SAIL_INFO,"PSAIL PIN BIST Skipped : Device in WARM BOOT!!!\r\n");
    }


    xRetStatus = prvPSAILIntrReg(); // API to configure PSAIL ERROR for falling edge INTR

    if (  PSAIL_SUCCESS == xRetStatus)
    {
        // Added for Misra
    }else
    {
        DEBUG_LOG(SAIL_INFO,"PSAIL:prvPSAILIntrReg Failed\r\n");
        DEBUG_LOG(SAIL_INFO,"PSAIL:prvPsailTask deleted\r\n");

        vFreeRTOSTaskDelete(xPsailTaskHandle);
    }

    if ( ulPSAILSleepHandle == 0u )
    {
        if ( SLEEP_ERR_FLAG_SUCCESS != xSleepRegisterCallBackEl1(&prvPSAILDeInit_Sleep,&ulPSAILSleepHandle,get_curr_phys_cpu_num()))
        {
            DEBUG_LOG(SAIL_INFO,"prvPSAILDeInit_Sleep Sleep Reg Failed\n\r");
        }
        else
        {
            DEBUG_LOG(SAIL_INFO,"prvPSAILDeInit_Sleep Sleep Reg Success\n\r");
        }
    }



    DEBUG_LOG(SAIL_INFO,"PsailTask started\r\n");

    for(;;)
    {
        /* Receive msg on queue and parse message */
        xReturn = xFreeRTOSQueueReceive(xPsailQueueHandle, &xMsg, freertosMAX_DELAY);
        if ( pdPASS == xReturn )
        {
            if ( PSAIL_ERROR_OCCURED == xMsg.PsailStatus )
            {
                if (PSAIL_SUCCESS == xPsailBPingTillReady())
                {
                    // Do nothing if successful
                }
                else
                {

                }

                /* Program PMIC for POFF. We dont want to warm reset after Psail fault. */
                xErrFlag = xPmicSetResetState(PMIC_POFF);

                DEBUG_LOG(SAIL_DEBUG,"PSAIL COOKIE AT 0x%x = 0x%x\r\n",PSAIL_ERROR_STATUS, in_dword(PSAIL_ERROR_STATUS));

                //xRetStatus = xPSAILCollectFirstFaultLog(xPsailErrorData.ucErrData);
                //AssertSMErr(true, SMErr_BSP_TRIG_REQ, fusa_DEFAULT_ERR_ID);

                //vFUSAMsgSendToSM(xPsailErrorData);
                
                /* code to read out SDAM01_MEM041-SDAM_MEM056 of Each Kobra PSAIL PMIC */
                xRetStatus = xPSAILDumpSDAMMemory();

                // UART Command to enable Debug Mode - psail debug
                if(ucPsailDebugMode == PSAIL_DEBUG_ON)
                {
                    xRetStatus = xPSAILDumpFaultLog(&(xDataSPINOR.ucPsailFaultLog[0]));  //Call to collect logs from Fault FIFO from each PSAIL
                    /*
                     * TODO : Below Logs print part can be removed whenever EFS Driver is ready in EL1
                     *
                     *
                     */

                    for (ucCountIndex = 0 ; ucCountIndex < psailMAX_CHIP_ON_SOC ; ucCountIndex++)
                    {
                        if( 0x0u != xDataSPINOR.ucPsailFaultLog[ucCountIndex].ucLvl2FaultCount )
                        {
                            DEBUG_LOG(SAIL_INFO,"PsailID :%d\r\n",xDataSPINOR.ucPsailFaultLog[ucCountIndex].PsailId);
                        }
                        else
                        {
                            DEBUG_LOG(SAIL_DEBUG,"PsailID :%d\r\n",xDataSPINOR.ucPsailFaultLog[ucCountIndex].PsailId); //Added for CC
                        }

                        for(ucCountFaultPerPsail = 0 ; ucCountFaultPerPsail < xDataSPINOR.ucPsailFaultLog[ucCountIndex].ucLvl2FaultCount ; ucCountFaultPerPsail++)
                        {
                            DEBUG_LOG(SAIL_INFO,"=== Entry:%d ===\r\n",ucCountFaultPerPsail+1u);
                            DEBUG_LOG(SAIL_INFO,"TimeStamp:0x%x\r\n",xDataSPINOR.ucPsailFaultLog[ucCountIndex].Lvl2ErrorInfo[ucCountFaultPerPsail].ucTimeStamp);
                            DEBUG_LOG(SAIL_INFO,"ucMonitorPID:0x%x\r\n",xDataSPINOR.ucPsailFaultLog[ucCountIndex].Lvl2ErrorInfo[ucCountFaultPerPsail].ucMonitorPID);
                            DEBUG_LOG(SAIL_INFO,"ucMonitorIndex:0x%x\r\n",xDataSPINOR.ucPsailFaultLog[ucCountIndex].Lvl2ErrorInfo[ucCountFaultPerPsail].ucMonitorIndex);
                            DEBUG_LOG(SAIL_INFO,"ucOldError:0x%x\r\n",xDataSPINOR.ucPsailFaultLog[ucCountIndex].Lvl2ErrorInfo[ucCountFaultPerPsail].ucOldError);
                            DEBUG_LOG(SAIL_INFO,"ucNewError:0x%x\r\n",xDataSPINOR.ucPsailFaultLog[ucCountIndex].Lvl2ErrorInfo[ucCountFaultPerPsail].ucNewError);
                            DEBUG_LOG(SAIL_INFO,"Threshold Violated:0x%x\r\n",xDataSPINOR.ucPsailFaultLog[ucCountIndex].Lvl2ErrorInfo[ucCountFaultPerPsail].ucThresholdViolation);
                        }
                    }

                    if ( PSAIL_SUCCESS == xDumpDataInSpiNOR(&xDataSPINOR) )
                    {
                        DEBUG_LOG(SAIL_INFO,"Psail log collection success\r\n");
                    }else
                    {
                        DEBUG_LOG(SAIL_ERROR,"Psail log collection failed\r\n");
                    }
                }
                else
                {
                    DEBUG_LOG(SAIL_DEBUG,"Psail Not in Debug mode\r\n");
                }
                vPSAILClearError();
            }
            else
            {
                DEBUG_LOG(SAIL_DEBUG,"Unknown Message Recieved in Queue. \r\n");
            }
        }
        else
        {
            DEBUG_LOG(SAIL_DEBUG,"Queue Message Not Recieved in safertosapiMAX_DELAY time. \r\n");
        }
    }
}


/*=================================================================================================
 @Service name        xDumpDataInSpiNOR
 @Description         xDumpDataInSpiNOR is used to dump PSAIL ERROR in SPINOR EFS data
 @param[in]           PsailSPINORDataType -> Pointer to the fault data.
 @param[out]          NA
 @param[in, out]      NA
 @return              PSAILStatusType_e
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

static PSAILStatusType_e xDumpDataInSpiNOR(PsailSPINORDataType *xDataSPINOR)
{
    PSAILStatusType_e xRetStatus = PSAIL_SUCCESS;
    xDataSPINOR->magicNumber = 0xcafe; // Magic number
    spinor_handle_t handle = NULL;
    uint32 ulbyteCount = 0x0;
    uint32 ulstartBlock = 0x0;
    SPINOR_STATUS xspinorReturn = SPINOR_DEVICE_OK_NOT_DONE;
    spinorMemInfoType xspinorInfo ={0};
    uint32 ulbyteoffset = 0x0;
    uint32 partsize_count = 0x0u;



    xspinorReturn = spinorEl1Open(&handle,SPINOR_USER_TYPE_EL1);

    if( xspinorReturn != SPINOR_DEVICE_DONE || handle == NULL)
    {
        DEBUG_LOG(SAIL_ERROR,"[PSAIL]: Open handle failed\n\r");
        return PSAIL_LOG_DUMP_ERROR;
    }
    else
    {
        DEBUG_LOG(SAIL_DEBUG,"[Psail] Open handle Success\r\n");
    }

    xspinorReturn = spinorEl1GetMemInfo ( handle, &xspinorInfo );
    if( xspinorReturn != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"[PSAIL]:GetMemInfo failed \n\r");
        xRetStatus = PSAIL_LOG_DUMP_ERROR;
        goto ErrSPINOR;
    }
    else
    {
        DEBUG_LOG(SAIL_DEBUG,"[Psail] GetMemInfo Success\r\n");
    }

    xspinorReturn = spinorEl1GetGptPartitionInfo( handle, "66768379-5905-40d3-96bc-56222766ec6f", &ulbyteoffset, &ulbyteCount);
    if( xspinorReturn != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"[PSAIL]:GetGptPartitionInfo failed \n\r");
        xRetStatus = PSAIL_LOG_DUMP_ERROR;
        goto ErrSPINOR;
    }
    else
    {
        DEBUG_LOG(SAIL_DEBUG,"[Psail] GetGptPartitionInfo Success\r\n");
    }
    
    partsize_count = ulbyteCount;

    ulbyteCount = xspinorInfo.pages_per_block * xspinorInfo.page_size_bytes;

    xspinorReturn = spinorEl1Erase (handle, ulbyteoffset/ulbyteCount, 1);
    if( xspinorReturn != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"[PSAIL]:Erase failed \n\r");
        xRetStatus = PSAIL_LOG_DUMP_ERROR;
        goto ErrSPINOR;
    }
    else
    {
        DEBUG_LOG(SAIL_DEBUG,"[Psail] Erase Success\r\n");
    }

    xspinorReturn = spinorEl1Write ( handle, ulbyteoffset, sizeof(PsailSPINORDataType), xDataSPINOR );
    if(xspinorReturn != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"[PSAIL]:Write failed\r\n");
        xRetStatus = PSAIL_LOG_DUMP_ERROR;
        goto ErrSPINOR;
    }
    else
    {
        DEBUG_LOG(SAIL_DEBUG,"[Psail] Write to SPINOR Success\r\n");
    }

    ErrSPINOR:
    xspinorReturn = spinorEl1Close(handle);
    if(xspinorReturn != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"[PSAIL]:Close failed\r\n");
        xRetStatus = PSAIL_LOG_DUMP_ERROR;
    }
    else
    {
        DEBUG_LOG(SAIL_DEBUG,"[Psail] Close SPINOR Success\r\n");
    }

    return xRetStatus;

}


/*=================================================================================================
 @Service name        prvPSAILIntrHandler
 @Description         Interrupt handler for the gpio interrupt
 @param[in]           *args - arguments passed during interrupt registration
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
 ==================================================================================================*/

static void prvPSAILIntrHandler(void *args)
{
    Psail_QueueMsgType xMsg = {PSAIL_ERROR_OCCURED};
    BaseType_t    xQReturn = pdFAIL;

    /* Sail SM needs a cookie to be set. This is done in order to ensure that Psail Fault data reaches VIP. */
    out_dword(PSAIL_ERROR_STATUS, PSAIL_ERROR_COOKIE);
    
    /* Disable Crash Debug as we dont want SAIL_pshold to follow MD_pshold */ 
	(void) Crashdbg_disable(CRASHDBG_DISABLED);

    xQReturn = xFreeRTOSQueueSendFromISR(xPsailQueueHandle, &xMsg);

    if( pdPASS == xQReturn)
    {
        DEBUG_LOG(SAIL_INFO,"PSAIL : prvPSAILIntrHandler\r\n");
    }
    else
    {
        DEBUG_LOG(SAIL_INFO,"PSAIL : Unable to Send Message on Queue\r\n");  
    }

    freertosYIELD_FROM_ISR();
}


/*=================================================================================================
 @Service name        prvPSAILIntrReg
 @Description         Registers the psail gpio falling edge interrupt
 @param[in]           NA
 @param[out]          NA
 @param[in, out]      NA
 @return              <PSAILStatusType_e> <Return err type based on status of initialization>
 @Pre                 Nil
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          Synchronous
 @Reentrancy          <NO>
 @Note                <None>
 ==================================================================================================*/

static PSAILStatusType_e prvPSAILIntrReg(void)
{
    PSAILStatusType_e eRetStatus = PSAIL_SUCCESS; 
        /* Register and enable psail gpio interrupt*/
        if( UGPIOINT_SUCCESS == uGPIORegister_SummaryIntr( psailPinGPIONumber, UGPIOINT_TRIGGER_FALLING,
                                                                (uGPIOINTISR) prvPSAILIntrHandler, NULL ))
        {
            if ( UGPIOINT_SUCCESS == uGPIOSummaryInt_EnableInterrupt( psailPinGPIONumber))
            {
                // Added for Misra
            }else
            {
                eRetStatus = PSAIL_INIT_ERROR;
                DEBUG_LOG(SAIL_ERROR,"PsailErr GPIO Reg Enable failed\r\n");
            }
        }else
        {
            eRetStatus = PSAIL_INIT_ERROR;
            DEBUG_LOG(SAIL_ERROR,"PsailErr GPIO Reg failed\r\n");
        }

    return eRetStatus;
}

/*========================================================================================================
 @Service name        prvPSAILDeInit_Sleep
 @Description         DeInit Call Back to register to sleep driver
 @param[in]           eState -> SLEEP_ENTRY = arg from sleep driver to Deinit PSAIL Driver
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

static void prvPSAILDeInit_Sleep( const sleepModeType_e eState )
{
    if(( STR_SLEEP_MODE == eState ) || (DEEP_SLEEP_MODE == eState))
    {
        if ( UGPIOINT_SUCCESS == uGPIODeregister_SummaryIntr(psailPinGPIONumber) )
        { 
            if (SLEEP_ERR_FLAG_SUCCESS == xSleepDriverAckEl1(ulPSAILSleepHandle,DRIVER_SLEEP,get_curr_phys_cpu_num()))
            {
                vFreeRTOSTaskSuspend(xPsailTaskHandle);
                DEBUG_LOG(SAIL_INFO,"prvPSAILDeInit_Sleep xSleepDriverAck Success\n\r");
            }
            else
            {
                DEBUG_LOG(SAIL_ERROR,"[Psail] prvPSAILDeInit_Sleep xSleepDriverAck Failed\r\n");
            }
        }
        else
        {
            DEBUG_LOG(SAIL_ERROR,"[Psail] uGPIODeregister_SummaryIntr Failed\r\n");
        }
    }
    else
    {
        DEBUG_LOG(SAIL_ERROR,"Abort Request Recieved\r\n");
    }
}

/**********************************************************************************************************
**                                  End of file psail.c                                                  **
**********************************************************************************************************/
