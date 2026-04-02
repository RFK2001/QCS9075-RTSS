
/*
===========================================================================
*/
/**
    @file  sail_updater_el1.c
    @brief Implementation of SAIL Updater driver in EL1

*/
/*
    ===========================================================================

    Copyright (c) 2022-2024 Qualcomm Technologies, Inc.
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

    $Header: $
    $DateTime: $
    $Author: $

    ===========================================================================
*/

#include "sail_updater_el1.h"
#include "sail_updater_msgtypes.h"
#include "sail_updater_msg_handler.h"
#include "sail_updater_core.h"
#include "sail_updater_cmn.h"
#include "sail_updater_otabookkeep.h"
#include "spinor_el1_api.h"
#include "mailboxExt_api.h"
#include "debug_log.h"
#include "err_fatal.h"
#include "sleepEl1.h"
#include "common_functions.h"

/* Task Init Macros */
#define SAIL_UPDATER_TASK_STACK_SIZE                   ( 4096 )

/* Queue Init Macros */
#define SAIL_UPDATER_Q_LENGTH           ( 1 )
#define SAIL_UPDATER_Q_ITEM_SIZE        ( sizeof(sailUpdaterMsgHeaderType) )
#define SAIL_UPDATER_Q_BUFFER_SIZE      ( SAIL_UPDATER_Q_LENGTH * SAIL_UPDATER_Q_ITEM_SIZE )

/* Task Init Definitions */
static StaticTask_t xSAILUpdaterTaskTCB = { 0 };
static StackType_t xSAILUpdaterTaskStack[ SAIL_UPDATER_TASK_STACK_SIZE ] __attribute__( ( aligned( MEM_ALIGNMENT_64 ) ) ) = { 0 };

/* Queue Buffers and Handles definitions */
uint8_t xSAILUpdaterQueueBuffer[ SAIL_UPDATER_Q_BUFFER_SIZE ] __attribute__( ( aligned( MEM_ALIGNMENT_4 ) ) ) = { 0 };
QueueHandle_t xSAILUpdaterQueueHandle = NULL;
StaticQueue_t xSAILUpdaterQueueBufferStatic;
TaskHandle_t xSAILUpdaterTaskHandle = NULL;

#ifdef SAILUPDATER_TEST_SRC_ENABLED
extern QueueHandle_t xSAILUpdaterTestTxQueueHandle;
#endif

uint32 ulSAILUpdaterSleepHandle = 0;

/* Updater Message Context type */
typedef struct
{
    sailUpdaterMsgHeaderType ReqMsg;
    sailUpdaterMsgHeaderType RspMsg;
}SAILUpdaterMsg_t;

/* Updater Message Context */
SAILUpdaterMsg_t g_SAILUPdaterCtx = {0};

static boolean g_OtaStateCorrupted = FALSE;

#ifdef SAILUPDATER_TEST_SRC_ENABLED
/*This variable is global and used in sail__updater_msg_handler.c also*/
volatile boolean gSAILUpdaterTestSkipMailbox = FALSE;
#endif

static void prvSAILUpdaterDeInit_Sleep( const sleepModeType_e eState );

/**********************************************************
 * set the Skip MB value
 *
 *
 * @param skipVal [IN]
 *   None
 *
 * @return void [OUT]
 *
 **********************************************************/
void vSailUpdaterSetSkipMB(boolean skipVal)
{
#ifdef SAILUPDATER_TEST_SRC_ENABLED
    gSAILUpdaterTestSkipMailbox = skipVal;
    DEBUG_LOG(SAIL_INFO,"vSailUpdaterSetSkipMB: skip value: %d \n\r",gSAILUpdaterTestSkipMailbox);
#endif
}

/**********************************************************
 * Initalize the Queue
 *
 *
 * @param xSchdCore [IN]
 *   Core number
 *
 * @return portBaseType [OUT]
 *   Status of the Operation
 *
 **********************************************************/
BaseType_t xSAILUpdaterQueueInit( CPUIdType_e xSchdCore )
{
    BaseType_t xCreateResult = pdPASS;
    xCreateResult = xFreeRTOSQueueCreate( xSAILUpdaterQueueBuffer,
                                  SAIL_UPDATER_Q_LENGTH,
                                  SAIL_UPDATER_Q_ITEM_SIZE,
                                  &xSAILUpdaterQueueHandle,&xSAILUpdaterQueueBufferStatic );
    if( xCreateResult != pdPASS )
    {
        xCreateResult = pdFAIL;
    }

    return xCreateResult;
}


/**********************************************************
 * SAIL Updater Queue Read Wrapper
 * Handles TEST and OTA
 *
 * @param MBclient_ID [IN]
 *   Mailbox Client ID
 *
 * @param num_item [IN]
 *
 *
 * @param rbuff [IN]
 *   Read Buffer
 *
 * @return retVal [OUT]
 *   Queue receive status
 *
 **********************************************************/
int32 slMailboxReadWrap(xMailboxExtclienttype MBclient_ID,uint32 num_item,uint8 *rbuff );
int32 slMailboxReadWrap(xMailboxExtclienttype MBclient_ID,uint32 num_item,uint8 *rbuff )
{
    int32 retVal = 0;
    BaseType_t xStatus = pdFALSE;
#ifdef SAILUPDATER_TEST_SRC_ENABLED
    if(TRUE == gSAILUpdaterTestSkipMailbox)
    {
        if(NULL != xSAILUpdaterTestTxQueueHandle)
        {
            xStatus = xFreeRTOSQueueReceive( xSAILUpdaterTestTxQueueHandle, rbuff, pdMS_TO_TICKS( freertosMAX_DELAY ));
            DEBUG_LOG(SAIL_INFO,"slMailboxReadWrap: xQueueReceive returns %d \n\r",xStatus);
            retVal = (int32)xStatus;
        }
    }
    else
#endif
    {
        retVal = slMailboxRead(MBclient_ID,num_item,rbuff);
    }
    return retVal;
}

/**********************************************************
 * SAIL Updater Queue send Wrapper
 * Handles TEST and OTA
 *
 * @param xQueue [IN]
 *   Queue to be send
 *
 * @param pMsg [IN]
 *   Message to be send
 *
 * @return xQSendStatus [OUT]
 *   Queue send status
 *
 **********************************************************/
BaseType_t xQueueSendWrap(QueueHandle_t xQueue, void *pMsg );
BaseType_t xQueueSendWrap(QueueHandle_t xQueue, void *pMsg )
{
    BaseType_t xQSendStatus = pdFALSE;
#ifdef SAILUPDATER_TEST_SRC_ENABLED
    if(TRUE == gSAILUpdaterTestSkipMailbox)
    {
        if(NULL != xQueue)
        {
            xQSendStatus = xFreeRTOSQueueSend( xQueue, pMsg, pdMS_TO_TICKS( freertosMAX_DELAY ));
        }
    }
    else
#endif
    {
        xQSendStatus = xFreeRTOSQueueSendFromISR( xQueue, pMsg);
    }
    return xQSendStatus;
}

/**********************************************************
 * SAIL Updater Get Valid Item Num Wrapper
 * Handles TEST and OTA
 *
 * @param MBclient_ID [IN]
 *   Mailbox Client ID
 *
 * @return uxNumberOfItems [OUT]
 *   None
 *
 **********************************************************/
int32 slMailbox_Get_ValidItemNumWrap(xMailboxExtclienttype MBclient_ID);
int32 slMailbox_Get_ValidItemNumWrap(xMailboxExtclienttype MBclient_ID)
{
    UBaseType_t uxNumberOfItems = 0U;
#ifdef SAILUPDATER_TEST_SRC_ENABLED
    if(TRUE == gSAILUpdaterTestSkipMailbox)
    {
        if(NULL != xSAILUpdaterTestTxQueueHandle)
        {
            uxNumberOfItems = uxFreeRTOSQueueMessagesWaiting( xSAILUpdaterTestTxQueueHandle );
        }
    }
    else
#endif
    {
        uxNumberOfItems = slMailbox_Get_ValidItemNum(MBclient_ID);
    }
    return uxNumberOfItems;
}

/**********************************************************
 * SAIL Updater Mailbox Callback
 *
 *
 * @param MBclient_ID [IN]
 *   Mailbox Client ID
 *
 * @return void [OUT]
 *   None
 *
 **********************************************************/
void vSAILupdMailboxcb(xMailboxExtclienttype MBclient_ID);
void vSAILupdMailboxcb(xMailboxExtclienttype MBclient_ID)
{

    BaseType_t    xQSendStatus = pdFAIL;
    uint8 ullNumValidItemLoc;
    uint8 numofitemcount;
    uint32_t errorId = 0U;

    sailUpdaterMsgHeaderType xRecvdMsg={0};
    sailUpdaterMsgHeaderType xErrResp={0};

    if(MAILBOX_OTA != MBclient_ID)
    {
        /* Unexpected Mailbox Callback */
        DEBUG_LOG(SAIL_ERROR,"vSAILupdMailboxcb: Unexpected Mailbox Callback \n\r");
        errorId = SAIL_UPDATER_STATUS_FAIL;
        err_fatal(MAILBOX, errorId);
    }

    /* Get the number of valid item for the requested region*/
    ullNumValidItemLoc = (uint32) slMailbox_Get_ValidItemNumWrap(MBclient_ID);
    if(ullNumValidItemLoc>0)
    {
        for(numofitemcount = 0; numofitemcount<ullNumValidItemLoc;numofitemcount++)
        {
            if( slMailboxReadWrap(MBclient_ID,1,(uint8 *)&xRecvdMsg) > 0 )
            {
                xQSendStatus = xQueueSendWrap( xSAILUpdaterQueueHandle, &xRecvdMsg);
                if (errQUEUE_FULL ==  xQSendStatus)
                {
                    /* Queue Full. Send Error response with queue full */
                    //Copy the msgId from the Message received
                    xErrResp.msgId = xRecvdMsg.msgId;
                    DEBUG_LOG(SAIL_INFO,"vSAILupdMailboxcb: Sail updater Queue Full \n\r");
                    vSAILUpdaterMsgPrepareErrRsp(&xErrResp,SAIL_UPDATER_Q_BUF_FULL);
                    vSAILUpdaterMsgSendResponse(&xErrResp);
                }
                else if (pdPASS != xQSendStatus)
                {
                    /* Error in queuing */
                    DEBUG_LOG(SAIL_ERROR,"vSAILupdMailboxcb: Queue from ISR failed \n\r");
                    errorId = xQSendStatus;
                    err_fatal(SAFERTOS, errorId);
                }
                else
                {
                    /* Queued request. Log and proceed */
                    DEBUG_LOG(SAIL_INFO,"vSAILupdMailboxcb: Sail updater Message Queued \n\r");
                }
            }
            else
            {
                /* error in reading from mailbox. log and loop */
                DEBUG_LOG(SAIL_ERROR,"vSAILupdMailboxcb: Error reading from Mailbox \n\r");
                errorId = SAIL_UPDATER_STATUS_FAIL;
                err_fatal(MAILBOX, errorId);
            }
        }
        freertosYIELD_FROM_ISR();
    }
}

/**********************************************************
 * SAIL Updater Initalization
 *
 *
 * @param xSchdCore [IN]
 *   CPU number
 *
 * @return portBaseType [OUT]
 *   Status of the Initalization
 *
 **********************************************************/
BaseType_t xSAILUpdaterInit(CPUIdType_e xSchdCore)
{

    BaseType_t xCreateResult = pdPASS;
    spinor_handle_t norHandle = NULL;
    SAILUpdaterOTAStateValType xOtaStatus =  OTA_INVALID ;
    uint8_t guidMap = 0;

    if( pdPASS != xSAILUpdaterQueueInit(xSchdCore) )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterInit: Queue Initialization Failed \n\r");
        xCreateResult =  pdFAIL;
        goto UpdaterInitEnd;
    }

    /* Register callback with the Mailbox */
    (void)slMailboxClientReg(MAILBOX_OTA,vSAILupdMailboxcb);
#if 1
    /* Initialize the SAIL Updater Core layer */
    if(SAIL_UPDATER_SUCCESS != xSAILUpdaterCoreInit())
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterInit: Updater Core Initialization Failed \n\r");
        xCreateResult = pdFAIL;
        goto UpdaterInitEnd;
    }

    /* Initalize SPINOR handle */
    if(SPINOR_DEVICE_DONE != spinorEl1Open ( &norHandle, SPINOR_USER_TYPE_OTA ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterInit: Spinor Open failed \n\r");
        xCreateResult = SAIL_UPDATER_FAIL;
        goto UpdaterInitEnd;
    }

    /*Get Ota Status*/
    if(SAIL_UPDATER_STATUS_SUCCESS != xSAILUpdaterGetOtaStatus(norHandle, &xOtaStatus, &guidMap))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterInit: xSAILUpdaterGetOtaStatus Failed \n\r");
        xCreateResult =  pdFAIL;
        goto UpdaterInitEnd;
    }

    /*Set the Global flag in case of OTA CORRUPTED state*/
    if (xOtaStatus == OTA_REBOOT_CORRUPTED)
    {
        g_OtaStateCorrupted = TRUE;
        DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterInit: OTA state is OTA_REBOOT_CORRUPTED \n\r");
    }
#endif 
UpdaterInitEnd:
    if (NULL != norHandle)
    {
        /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl1Close ( norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterInit: Spinor Close failed \n\r");
            xCreateResult =  pdFAIL;
        }
    }
       
    return xCreateResult;
}

/**********************************************************
 * SAIL Updater De-Initalization
 *
 *  De-Register Mailbox Callback, De-init Queue Handles and core
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterDeInit(void)
{
    BaseType_t xCreateResult = pdPASS;

    /*De-Init the Queue handles*/
    memset(xSAILUpdaterQueueBuffer,0,SAIL_UPDATER_Q_BUFFER_SIZE);
    xSAILUpdaterQueueHandle = NULL;

    /* De-Register callback with the Mailbox */
    (void)slMailboxClientReg(MAILBOX_OTA,NULL);

    /* De-Initialize the SAIL Updater Core layer */
    if(SAIL_UPDATER_SUCCESS != xSAILUpdaterCoreDeInit())
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterDeInit: Updater Core De-Initialization Failed \n\r");
        xCreateResult = pdFAIL;
        goto UpdaterDeInitEnd;
    }

UpdaterDeInitEnd:
    return xCreateResult;
}

/**********************************************************
 * SAIL Updater Task
 *
 *
 * @param pvParameters [IN/OUT]
 *   Pointer for Input Params
 *
 * @return void [OUT]
 *   None
 *
 **********************************************************/
void vSailUpdaterTask(void * pvParameters)
{
    uint32_t errorId = 0U;
    uint32_t ulcpu_ID = get_curr_phys_cpu_num();

    xSAILUpdaterInit(ulcpu_ID);

    /*If OTA State is Corrupted, then Check Boot Partition*/
    if (g_OtaStateCorrupted == TRUE)
    {
        if(SAIL_UPDATER_STATUS_SUCCESS != xSAILUpdaterCheckbootPartition())
        {
            DEBUG_LOG(SAIL_ERROR,"vSailUpdaterTask: xSAILUpdaterCheckbootPartition returned Failure \n\r");
            errorId = SAIL_UPDATER_STATUS_FAIL;
            err_fatal(SAIL_UPDATER, errorId);
        }
        g_OtaStateCorrupted = FALSE;
    }

    /* First time check if the Mailbox is ready for receiving events */
    for(;;)
    {
        if (MB_E2EREADY == eMailbox_Get_Status())
        {
            DEBUG_LOG(SAIL_INFO,"vSailUpdaterTask: SAILUpdater MB ready \n\r");
            break;
        }

        /* Poll Periodically */
        vFreeRTOSTaskDelay( 2 );
    }

    for(;;)
    {
        DEBUG_LOG(SAIL_WARNING,"vSailUpdaterTask: Waiting on receive Queue \n\r");
        /* Wait on Receive Queue Event */
        if(pdPASS != xFreeRTOSQueueReceive( xSAILUpdaterQueueHandle, &g_SAILUPdaterCtx.ReqMsg, freertosMAX_DELAY ))
        {
            DEBUG_LOG(SAIL_ERROR,"vSailUpdaterTask: Receive from Queue failed \n\r");
            errorId = SAIL_UPDATER_STATUS_FAIL;
            err_fatal(SAFERTOS, errorId);
        }

        DEBUG_LOG(SAIL_WARNING,"vSailUpdaterTask: Queue Item received \n\r");

        /* Process the Request Message */
        vSAILUpdaterMsgProcessReqMsg(&g_SAILUPdaterCtx.ReqMsg,&g_SAILUPdaterCtx.RspMsg);

        /* Send the response for the Message */
        vSAILUpdaterMsgSendResponse(&g_SAILUPdaterCtx.RspMsg);

        /* Clear the Request Message for the next message */
        memset( &g_SAILUPdaterCtx.ReqMsg, 0, sizeof(sailUpdaterMsgHeaderType));
    }
}

/**********************************************************
 * SAIL Updater Task Init
 *
 *
 * @param xSchdCore [IN]
 *   CPU number
 *
 * @param xTaskPrior [IN]
 *   Task Priority
 *
 * @return portBaseType [OUT]
 *   Status of the operation
 *
 **********************************************************/
BaseType_t xSAILUpdaterTaskInit( CPUIdType_e  xSchdCore, UBaseType_t  xTaskPrior )
{
    BaseType_t xResult;
    UBaseType_t uxCoreAffinityMask;
    /* The structure passed to xSAILTaskCreate() to create the check task. */
    TaskParams_t xInitTaskParameters =
    {
        .pvTaskCode = vSailUpdaterTask,                   /* The function that implements the task being created. */
        .pcName ="SAIL Updater",                     /* The name of the task being created. The kernel does not use this itself, it's just to assist debugging. */
        .pxTaskBuffer = &xSAILUpdaterTaskTCB,               /* The buffer allocated for use as the task TCB. */
        .puxStackBuffer =xSAILUpdaterTaskStack,              /* The buffer allocated for use as the task stack. */
        .usStackDepth =SAIL_UPDATER_TASK_STACK_SIZE,       /* The size of the buffer allocated for use as the task stack - note this is in BYTES! */
        .pvParameters =NULL,                               /* The task parameter, not used in this case. */
       .uxPriority = (xTaskPrior),                         /* The priority assigned to the task being created. */
        .xRegions = {				   /* The MPU task parameters. */
						 {NULL, 0UL, 0UL}, /* No additional region definitions are required. */
						 {NULL, 0UL, 0UL},
						 {NULL, 0UL, 0UL},
						 {NULL, 0UL, 0UL},
						 {NULL, 0UL, 0UL},
						 {NULL, 0UL, 0UL}}};

    if ( ulSAILUpdaterSleepHandle == 0u )
    {
        if ( SLEEP_ERR_FLAG_SUCCESS != xSleepRegisterCallBackEl1(&prvSAILUpdaterDeInit_Sleep,&ulSAILUpdaterSleepHandle,get_curr_phys_cpu_num()))
        {
            DEBUG_LOG(SAIL_INFO,"prvSAILUpdaterDeInit_Sleep Sleep Reg Failed\n\r");
        }
        else
        {
            DEBUG_LOG(SAIL_INFO,"prvSAILUpdaterDeInit_Sleep Sleep Reg Success\n\r");
        }
    }



    uxCoreAffinityMask = (1 << xSchdCore);
    /* Create the check task. */
    xResult = xFreeRTOSTaskCreateAffinitySet( &xInitTaskParameters,uxCoreAffinityMask, /* The structure containing the task parameters created at the start of this function. */
                           &xSAILUpdaterTaskHandle );

    return xResult;
}


/*========================================================================================================
 @Service name        prvSAILUpdaterDeInit_Sleep
 @Description         DeInit Call Back to register to sleep driver
 @param[in]           eState -> SLEEP_ENTRY = arg from sleep driver to Deinit Sail Updater Driver
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

static void prvSAILUpdaterDeInit_Sleep( const sleepModeType_e eState )
{
    if(( STR_SLEEP_MODE == eState ) || (DEEP_SLEEP_MODE == eState))
    {
        if ( pdPASS == xSAILUpdaterDeInit() )
        {
            if (SLEEP_ERR_FLAG_SUCCESS == xSleepDriverAckEl1(ulSAILUpdaterSleepHandle,DRIVER_SLEEP,get_curr_phys_cpu_num()))
            {
                vFreeRTOSTaskSuspend(xSAILUpdaterTaskHandle);
                DEBUG_LOG(SAIL_ERROR,"[sleep]  prvSAILUpdaterDeInit_Sleep xSleepDriverAck Success\n\r");
            }
            else
            {
                DEBUG_LOG(SAIL_ERROR,"[SAILUpdater] prvSAILUpdaterDeInit_Sleep xSleepDriverAck Failed\r\n");
            }
        }
        else
        {
            DEBUG_LOG(SAIL_ERROR,"[SAILUpdater] xSAILUpdaterDeInit Failed\r\n");
        }
    }
    else
    {
        DEBUG_LOG(SAIL_ERROR,"[SAILUpdater] Abort Request Recieved\r\n");
    }
}



