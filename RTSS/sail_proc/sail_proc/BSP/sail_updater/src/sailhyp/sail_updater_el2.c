
/*
===========================================================================
*/
/**
    @file  sail_updater_el2.c
    @brief Implementation of SAIL Updater in EL2

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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/sail_updater/src/sailhyp/sail_updater_el2.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/
#include "sail_updater_core.h"
#include "sail_updater_msgtypes.h"
#include "sail_updater_msg_handler.h"
#include "mailboxExt_api.h"
#include "debug_log.h"
#include "sailbsp_mutex.h"
#include "common_functions.h"
#include "boot.h"
#include "err_fatal.h"
#include "sail_updater_otabookkeep.h"

/* Queue Init Macros */
#define SAIL_UPDATER_Q_LENGTH           ( 1 )
#define SAIL_UPDATER_Q_ITEM_SIZE        ( sizeof(sailUpdaterMsgHeaderType) )
#define SAIL_UPDATER_Q_BUFFER_SIZE      ( ( SAIL_UPDATER_Q_LENGTH * SAIL_UPDATER_Q_ITEM_SIZE ) )
#define SAIL_UPDATER_Q_MAGIC_NUMBER     0xFADECAFE
#define SAIL_UPDATERTEST_TXQ_LENGTH           ( 1 )
#define SAIL_UPDATERTEST_TXQ_ITEM_SIZE        ( sizeof(sailUpdaterMsgHeaderType) )
#define SAIL_UPDATERTEST_TXQ_BUFFER_SIZE      ( ( SAIL_UPDATERTEST_TXQ_LENGTH * SAIL_UPDATERTEST_TXQ_ITEM_SIZE ) )

/* Updater Message Context type */
typedef struct
{
    sailUpdaterMsgHeaderType ReqMsg;
    sailUpdaterMsgHeaderType RspMsg;
}SAILUpdaterMsg_t;

/* Queue Parameter type */
typedef struct
{
    uint32_t magic_number;            /* Magic number for the Queue param */
    uint8_t* pQueueBuffer;            /* Pointer to hold the Queue Buffer */
    uint32_t QueueLength;             /* Max number of items Queue can hold */
    uint32_t QueueItemSize;           /* Size of each item in the Queue */
    uint32_t QueueBufSize;            /* Size of the Queue Buffer */
    uint32_t QueueWrIndex;            /* Index where the queue item will next be inserted */
    uint32_t QueueRdIndex;            /* Index where the queue will read the next item */
    uint32_t QueueNumValidItems;      /* Number of valid items available in the Queue to be processed */
//  uint32_t QueueNumFreeItems;       /* Number of free items in the Queue */
    mutex_t QueueLock;                /* Lock for the queue */
}SAILUpdaterQueueParamType;

typedef void* SAILUpdaterQueueHandleType;

/* Buffer for the Queue to share data between the Mailbox and the Updater thread */
static uint8_t xSAILUpdaterQueueBuffer[SAIL_UPDATER_Q_BUFFER_SIZE]__attribute__( ( aligned( sizeof(uint32_t) ) ) )= {0};
/* Handle to the Queue */
SAILUpdaterQueueHandleType xSAILUpdaterQueueHandle = NULL;

/* Queue parameters */
static SAILUpdaterQueueParamType g_SAILUpdaterQueueParam={0};

/* Updater Message Context */
SAILUpdaterMsg_t g_SAILUPdaterCtx = {0};

#ifdef SAILUPDATER_TEST_SRC_ENABLED
uint8_t xSAILUpdaterTestTxQueueBuffer[SAIL_UPDATERTEST_TXQ_BUFFER_SIZE]__attribute__( ( aligned( sizeof(uint32_t) ) ) )= {0};
/*This variable is global and used in sail_updater_msg_handler.c also*/
volatile boolean gSAILUpdaterTestSkipMailbox = FALSE;
#endif

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
 * @param pQueueMemory [IN]
 *   Pointer to the Queue Message
 *
 * @param uxBufferLength [IN]
 *   Total size of the Buffer for the Queue
 *
 * @param uxQueueLength [IN]
 *   Number of items in the Queue
 *
 * @param uxItemSize [IN]
 *   Size of each item in the Queue
 *
 * @param pxQueue [IN/OUT]
 *   Pointer to the Queue Handle
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the Operation
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterQueueInit(uint8_t* pQueueMemory,
                                               uint32_t uxBufferLength,
                                               uint32_t uxQueueLength,
                                               uint32_t uxItemSize,
                                               SAILUpdaterQueueHandleType* pxQueue  )
{
    SAILUpdaterStatusType_e xCreateResult = SAIL_UPDATER_STATUS_SUCCESS;

    if ( (NULL == pQueueMemory) || (NULL == pxQueue) )
    {
        return SAIL_UPDATER_INVALID_BUF_ADDR;
    }

    if (uxBufferLength !=  uxQueueLength*uxItemSize)
    {
        return SAIL_UPDATER_INVALID_BUF_SIZE;
    }

    mutex_init(&g_SAILUpdaterQueueParam.QueueLock);

    g_SAILUpdaterQueueParam.pQueueBuffer = pQueueMemory;
    g_SAILUpdaterQueueParam.QueueBufSize = uxBufferLength;
    g_SAILUpdaterQueueParam.QueueItemSize = uxItemSize;
    g_SAILUpdaterQueueParam.QueueLength = uxQueueLength;
//  g_SAILUpdaterQueueParam.QueueNumFreeItems = uxQueueLength;
    g_SAILUpdaterQueueParam.QueueNumValidItems = 0;
    g_SAILUpdaterQueueParam.QueueWrIndex = 0;
    g_SAILUpdaterQueueParam.QueueRdIndex = uxQueueLength-1;
    g_SAILUpdaterQueueParam.magic_number = SAIL_UPDATER_Q_MAGIC_NUMBER;

    *pxQueue = (SAILUpdaterQueueHandleType *)&g_SAILUpdaterQueueParam;

    return SAIL_UPDATER_STATUS_SUCCESS;
}

/**********************************************************
 * Insert Item to the Queue
 *
 *
 * @param xQueueHandle [IN]
 *   Queue Handle
 *
 * @param pvItemToQueue [IN]
 *   Pointer to the Item to queue
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the Operation
 *
 **********************************************************/
SAILUpdaterStatusType_e xPrvSAILUpdaterQueueSend(void* xQueueHandle, void* pvItemToQueue)
{
    size_t result;
    uint32_t val;
    SAILUpdaterQueueParamType* Qparam = (SAILUpdaterQueueParamType* )xQueueHandle;

    if ((NULL == xQueueHandle) || (NULL == pvItemToQueue) || (SAIL_UPDATER_Q_MAGIC_NUMBER != Qparam->magic_number))
    {
        return SAIL_UPDATER_INVALID_BUF_ADDR;
    }

//  mutex_lock(&Qparam->QueueLock);
    val = mutex_try_lock(&Qparam->QueueLock);

    if (val)
    {
    //  if ((Qparam->QueueNumFreeItems) && (Qparam->QueueNumValidItems < Qparam->QueueLength))
        if (Qparam->QueueNumValidItems < Qparam->QueueLength)
        {
            if (Qparam->QueueItemSize > 0)
            {
                result = sailbsp_memscpy((void *)((uint32)Qparam->pQueueBuffer + (Qparam->QueueWrIndex * Qparam->QueueItemSize)), Qparam->QueueItemSize,
                                         (const void *)pvItemToQueue, Qparam->QueueItemSize
                                         );
                if(result == 0)
                {
                     mutex_unlock(&Qparam->QueueLock);
                     return SAIL_UPDATER_STATUS_FAIL;
                }
            }
    //      Qparam->QueueNumFreeItems--;
            Qparam->QueueNumValidItems++;
            Qparam->QueueWrIndex = (Qparam->QueueWrIndex + 1) % Qparam->QueueLength;

            mutex_unlock(&Qparam->QueueLock);
            return SAIL_UPDATER_STATUS_SUCCESS;
        }
        else
        {
            mutex_unlock(&Qparam->QueueLock);
            return SAIL_UPDATER_Q_BUF_FULL;
        }
    }
    else
    {
        return SAIL_UPDATER_Q_BUF_FULL;
    }

    return SAIL_UPDATER_STATUS_SUCCESS;
}

/**********************************************************
 * Retrieve Item from the Queue
 *
 *
 * @param xQueueHandle [IN]
 *   Queue Handle
 *
 * @param pvItemFromQueue [IN/OUT]
 *   Pointer to buffer to retrieve Item from queue
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the Operation
 *
 **********************************************************/
SAILUpdaterStatusType_e xPrvSAILUpdaterQueueReceive( void* xQueueHandle, void* pvItemFromQueue)
{
    uint32_t tempRdIdx=0;
    size_t result;
    SAILUpdaterQueueParamType* Qparam = (SAILUpdaterQueueParamType* )xQueueHandle;

    if ((NULL == xQueueHandle) || (NULL == pvItemFromQueue) || (SAIL_UPDATER_Q_MAGIC_NUMBER != Qparam->magic_number))
    {
        return SAIL_UPDATER_INVALID_BUF_ADDR;
    }

    mutex_lock(&Qparam->QueueLock);

    tempRdIdx = (Qparam->QueueRdIndex + 1) % Qparam->QueueLength;

//  if ((Qparam->QueueNumFreeItems != Qparam->QueueLength) && (Qparam->QueueNumValidItems > 0))
    if (Qparam->QueueNumValidItems > 0)
    {
        if (Qparam->QueueItemSize > 0)
        {
            result = sailbsp_memscpy((void *)pvItemFromQueue, Qparam->QueueItemSize,
                                      (const void *)((uint32)Qparam->pQueueBuffer + (tempRdIdx * Qparam->QueueItemSize)), Qparam->QueueItemSize
                                     );
            if(result == 0)
            {
                 mutex_unlock(&Qparam->QueueLock);
                 return SAIL_UPDATER_STATUS_FAIL;
            }
        }

        Qparam->QueueRdIndex = tempRdIdx;
//      Qparam->QueueNumFreeItems++;
        Qparam->QueueNumValidItems--;
    }
    else
    {
        /* Queue is empty */
        mutex_unlock(&Qparam->QueueLock);
        return SAIL_UPDATER_STATUS_FAIL;
    }

    mutex_unlock(&Qparam->QueueLock);
    return SAIL_UPDATER_STATUS_SUCCESS;
}

/**********************************************************
 * Checks if the Queue is Empty
 *
 *
 * @param xQueueHandle [IN]
 *   Queue Handle
 *
 * @param bQueueStatus [IN/OUT]
 *   Pointer to update the status of Queue
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the Operation
 *
 **********************************************************/
SAILUpdaterStatusType_e xPrvSAILUpdaterQueueIsEmpty( void* xQueueHandle, boolean *bQueueStatus)
{
    SAILUpdaterQueueParamType* Qparam = (SAILUpdaterQueueParamType* )xQueueHandle;

    if ((NULL == xQueueHandle) || (NULL == bQueueStatus) || (SAIL_UPDATER_Q_MAGIC_NUMBER != Qparam->magic_number))
    {
        return SAIL_UPDATER_INVALID_BUF_ADDR;
    }

    //mutex_lock(&Qparam->QueueLock);

//  if ((Qparam->QueueNumFreeItems < Qparam->QueueLength) && (Qparam->QueueNumValidItems > 0))
    if (Qparam->QueueNumValidItems > 0)
    {
        *bQueueStatus = FALSE;
    }
    else
    {
        *bQueueStatus = TRUE;
    }
    //mutex_unlock(&Qparam->QueueLock);
    return SAIL_UPDATER_STATUS_SUCCESS;
}

/**********************************************************
 * Checks if the Queue is Full
 *
 *
 * @param xQueueHandle [IN]
 *   Queue Handle
 *
 * @param bQueueStatus [IN/OUT]
 *   Pointer to update the status of Queue
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the Operation
 *
 **********************************************************/
SAILUpdaterStatusType_e xPrvSAILUpdaterQueueIsFull( void* xQueueHandle, boolean *bQueueStatus)
{
    SAILUpdaterQueueParamType* Qparam = (SAILUpdaterQueueParamType* )xQueueHandle;

    if ((NULL == xQueueHandle) || (NULL == bQueueStatus) || (SAIL_UPDATER_Q_MAGIC_NUMBER != Qparam->magic_number))
    {
        return SAIL_UPDATER_INVALID_BUF_ADDR;
    }

//  mutex_lock(&Qparam->QueueLock);

//  if ((Qparam->QueueNumFreeItems == 0) && (Qparam->QueueNumValidItems == Qparam->QueueLength))
    if (Qparam->QueueNumValidItems >= Qparam->QueueLength)
    {
        *bQueueStatus = TRUE;
    }
    else
    {
        *bQueueStatus = FALSE;
    }
//  mutex_unlock(&Qparam->QueueLock);
    return SAIL_UPDATER_STATUS_SUCCESS;
}



/**********************************************************
 * SAIL Updater Queue Read Wrapper
 * Read Wrapper for Unit Test and Fastboot usecases
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
int32 slMailboxReadWrap(xMailboxExtclienttype MBclient_ID,uint32 num_item,uint8 *rbuff);
int32 slMailboxReadWrap(xMailboxExtclienttype MBclient_ID,uint32 num_item,uint8 *rbuff)
{
    int32 retVal = 0;
#ifdef SAILUPDATER_TEST_SRC_ENABLED
    uint32_t uTxBufSize = sizeof(sailUpdaterMsgHeaderType) * num_item;
    if(TRUE == gSAILUpdaterTestSkipMailbox) 
    {
    	/* copy the Tx Buffer send from El2 Test */  
    	retVal = sailbsp_memscpy(rbuff, uTxBufSize,
                                         xSAILUpdaterTestTxQueueBuffer, uTxBufSize
                                         );
    	if(retVal == 0)
    	{
            return SAIL_UPDATER_STATUS_FAIL;
    	}
    	DEBUG_LOG(SAIL_INFO,"slMailboxReadWrap: Tx Buffer copied \n\r");
    }
    else
#endif
    {
        retVal = slMailboxRead(MBclient_ID,num_item,rbuff);
    }
    return retVal;
}

/**********************************************************
 * SAIL Updater Get Valid Item Num Wrapper
 * Wrapper for Unit Test and Fastboot usecases
 *
 * @param MBclient_ID [IN]
 *   Mailbox Client ID
 *
 * @return uxNumberOfItems [OUT]
 *   Number of Items
 *
 **********************************************************/
int32 slMailbox_Get_ValidItemNumWrap(xMailboxExtclienttype MBclient_ID);
int32 slMailbox_Get_ValidItemNumWrap(xMailboxExtclienttype MBclient_ID)
{
    int32 uxNumberOfItems = 0U;
#ifdef SAILUPDATER_TEST_SRC_ENABLED    
    if(TRUE == gSAILUpdaterTestSkipMailbox) 
    {
        uxNumberOfItems = 1U;
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

    SAILUpdaterStatusType_e    xQSendStatus = SAIL_UPDATER_STATUS_SUCCESS;
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
                xQSendStatus = xPrvSAILUpdaterQueueSend( xSAILUpdaterQueueHandle, &xRecvdMsg);
                if (SAIL_UPDATER_Q_BUF_FULL ==  xQSendStatus)
                {
                    /* Queue Full. Send Error response with queue full */
                    //Copy the msgId from the Message received
                    xErrResp.msgId = xRecvdMsg.msgId;
                    DEBUG_LOG(SAIL_INFO,"vSAILupdMailboxcb: Sail updater Queue Full \n\r");
                    vSAILUpdaterMsgPrepareErrRsp(&xErrResp,SAIL_UPDATER_Q_BUF_FULL);
                    vSAILUpdaterMsgSendResponse(&xErrResp);
                }
                else if (SAIL_UPDATER_STATUS_SUCCESS != xQSendStatus)
                {
                    /* Error in queuing */
                    DEBUG_LOG(SAIL_ERROR,"vSAILupdMailboxcb: Queue from ISR failed \n\r");
                    errorId = xQSendStatus;
                    err_fatal(SAIL_UPDATER, errorId);
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
    }
}

/**********************************************************
 * SAIL Updater Initalization
 *
 *
 * @param void [IN]
 *   None
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the Initalization
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterEl2Init(void)
{
    SAILUpdaterStatusType_e xCreateResult = SAIL_UPDATER_STATUS_SUCCESS;
    if( SAIL_UPDATER_STATUS_SUCCESS != xSAILUpdaterQueueInit(xSAILUpdaterQueueBuffer,
                                                             SAIL_UPDATER_Q_BUFFER_SIZE,
                                                             SAIL_UPDATER_Q_LENGTH,
                                                             SAIL_UPDATER_Q_ITEM_SIZE,
                                                             &xSAILUpdaterQueueHandle) )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterInit: Queue Initialization Failed \n\r");
        xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
        goto UpdaterInitEnd;
    }
    
    /*For Unit Tests gSAILUpdaterTestSkipMailbox is set to TRUE before calling xSAILUpdaterEl2Init
      So enable mailbox only for regular Fatboot use case and Not for test*/
    if(FALSE == gSAILUpdaterTestSkipMailbox)
    {
        if(0 != slMailBox_Enable())
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterEl2Init: slMailBox_Enable() failed\n\r");
            xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
            goto UpdaterInitEnd;
    	}

        /* Register callback with the Mailbox */
        (void)slMailboxClientReg(MAILBOX_OTA,vSAILupdMailboxcb);
    }

    /* Initialize the SAIL Updater Core layer */
    if(SAIL_UPDATER_SUCCESS != xSAILUpdaterCoreInit())
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterInit: Updater Core Initialization Failed \n\r");
        xCreateResult = SAIL_UPDATER_STATUS_FAIL;
        goto UpdaterInitEnd;
    }


UpdaterInitEnd:
    return xCreateResult;

}

/**********************************************************
 * SAIL Updater De-Initalization
 *
 *
 * @param void [IN]
 *   None
 *
 * @return void [OUT]
 *   None
 *
 **********************************************************/
void xSAILUpdaterDeinit(void)
{
   mailboxEBStatusType_e status = eMailbox_Set_Status( MB_UNINITIALIZED,  0 );
   (void)eMailbox_SetBCK_Status(MB_UNINITIALIZED, 0 );
   DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterDeinit: SAIL MB De-enit EBStatus %d\n\r",status);
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
    boolean isQEmpty=TRUE;
	boot_mode_type* bootmode = (boot_mode_type*)pvParameters;
    uint32_t errorId = 0U;

    /* First time check if the Mailbox is ready for receiving events */
    for(;;)
    {
        /*Mailbox Status check incase of Fast boot*/
        if(FALSE == gSAILUpdaterTestSkipMailbox)
        {
            if (MB_E2EREADY == eMailbox_Get_Status())
            {
                DEBUG_LOG(SAIL_ERROR,"vSailUpdaterTask: SAILUpdater MB ready \n\r");
                break;
            }
        }
        /*No need for Mailbox Status check incase of Unit test*/
        else
        {
        	break;
        }
    }

    for(;;)
    {

        DEBUG_LOG(SAIL_WARNING,"vSailUpdaterTask: Waiting on receive Queue \n\r");
        do {

            if(SAIL_UPDATER_STATUS_SUCCESS != xPrvSAILUpdaterQueueIsEmpty(xSAILUpdaterQueueHandle, &isQEmpty))
            {
                 DEBUG_LOG(SAIL_ERROR,"vSailUpdaterTask: xPrvSAILQueueIsEmpty returned error \n\r");
                 break;
            }
        }
        while (TRUE == isQEmpty);

        /* Wait on Receive Queue Event */
        if(SAIL_UPDATER_STATUS_SUCCESS != xPrvSAILUpdaterQueueReceive( xSAILUpdaterQueueHandle, &g_SAILUPdaterCtx.ReqMsg ))
        {
            DEBUG_LOG(SAIL_ERROR,"vSailUpdaterTask: Receive from Queue failed \n\r");
            errorId = SAIL_UPDATER_STATUS_FAIL;
            err_fatal(SAIL_UPDATER, errorId);
        }

        DEBUG_LOG(SAIL_WARNING,"vSailUpdaterTask: Queue Item received \n\r");

        /* Process the Request Message */
        vSAILUpdaterMsgProcessReqMsg(&g_SAILUPdaterCtx.ReqMsg,&g_SAILUPdaterCtx.RspMsg);

        /* Send the response for the Message */
        vSAILUpdaterMsgSendResponse(&g_SAILUPdaterCtx.RspMsg);

        /* Clear the Request Message for the next message */
        memset( &g_SAILUPdaterCtx.ReqMsg, 0, sizeof(sailUpdaterMsgHeaderType));

        if((SAIL_UPD_MSG_ID_BOOT_IMAGE == g_SAILUPdaterCtx.RspMsg.msgId) && (SAIL_UPDATER_STATUS_SUCCESS == g_SAILUPdaterCtx.RspMsg.status))
        {
            DEBUG_LOG(SAIL_WARNING,"vSailUpdaterTask: Mode fastboot boot \n\r");
            *bootmode = BOOT_MODE_FASTBOOT_BOOT;
			break;
        }
        else if ((SAIL_UPD_MSG_ID_BOOT_CONTINUE == g_SAILUPdaterCtx.RspMsg.msgId) && (SAIL_UPDATER_STATUS_SUCCESS == g_SAILUPdaterCtx.RspMsg.status))
        {
            DEBUG_LOG(SAIL_WARNING,"vSailUpdaterTask: Mode fastboot Continue \n\r");
            *bootmode = BOOT_MODE_FASTBOOT_CONT;
			break;
        }
#ifdef SAILUPDATER_TEST_SRC_ENABLED
        /*In test scenario, vSailUpdaterTask API needs to exit after posting the response buffer
        so that control goes back to the test*/
	if(TRUE == gSAILUpdaterTestSkipMailbox) 
    	{
    	    break;
    	}
#endif   
    }
}

/**********************************************************
 * SAIL OTA Updater Is Boot Type OTA Boot
 *
 *
 * @param void [IN]
 *   None
 *
 * @return boolean TRUE/FALSE [OUT]
 *   retun values
 *
 **********************************************************/
boolean xSAILUpdaterIsBootTypeOTA(void)
{
    return (bSAILUpdaterOtaBookIsBootOTA());
}

/**********************************************************
 * SAIL OTA Updater get Current OTA state
 *
 *
 * @param void [IN]
 *   None
 *
 * @return SAILUpdaterOTAStateValType currentOTAState [OUT]
 *   return current OTA State
 *
 **********************************************************/
SAILUpdaterOTAStateValType xSAILUpdaterGetCurrentOTAState(void)
{   
    return (xSAILUpdaterOtaBookGetCurrentOTAState());
}

/**********************************************************
 * SAIL OTA Updater Get Loader Flow
 *
 *
 * @param bootType [IN/OUT]
 *   pointer to return the boot mode
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the Initalization
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterGetLoaderFlow(boolean *bootType)
{
    if (NULL == bootType)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: NULL bootType param passed \n\r");
        return SAIL_UPDATER_STATUS_FAIL;
    }
    
    return (xSAILUpdaterOtaBookGetLdrFlow(bootType));
}
