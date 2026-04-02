
/*
===========================================================================
*/
/**
    @file  sail_updater_msg_handler.c
    @brief Implementation of SAIL Updater Message handling

*/
/*
    ===========================================================================

    Copyright (c) 2023-2024 Qualcomm Technologies, Inc.
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

#include "sail_updater_msg_handler.h"
#include "sail_updater_core.h"
#include "autosar_crc.h"
#include "cache_ops.h"
#include "mailboxExt_api.h"
#include "debug_log.h"
#include "common_functions.h"
#include "err_fatal.h"

#ifdef SAILUPDATER_TEST_SRC_ENABLED
#define SAIL_UPDATERTEST_RXQ_LENGTH           ( 1 )
#define SAIL_UPDATERTEST_RXQ_ITEM_SIZE        ( sizeof(sailUpdaterMsgHeaderType) )
#define SAIL_UPDATERTEST_RXQ_BUFFER_SIZE      ( ( SAIL_UPDATERTEST_RXQ_LENGTH * SAIL_UPDATERTEST_RXQ_ITEM_SIZE ) )
//extern uint8_t xSAILUpdaterTestRxQueueBuffer[SAIL_UPDATERTEST_RXQ_BUFFER_SIZE];
uint8_t xSAILUpdaterTestRxQueueBuffer[SAIL_UPDATERTEST_RXQ_BUFFER_SIZE]__attribute__( ( aligned( sizeof(uint32_t) ) ) )= {0};
extern volatile boolean gSAILUpdaterTestSkipMailbox;
#endif

/**********************************************************
 * Checks the Validity of the Header Message
 *
 *
 * @param pReqMsg [IN]
 *   Pointer to the Request Message
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterMsgCheckHeaderValidity(sailUpdaterMsgHeaderType* pReqMsg)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;
    uint32_t tempCRC32=0;

    /* Verify Header CRC */
    tempCRC32 = pReqMsg->headerCrc;

    pReqMsg->headerCrc = 0;
    pReqMsg->headerCrc = ulSAILUpdaterCoreCalcCRC((uint32_t)pReqMsg, sizeof(sailUpdaterMsgHeaderType));

    if (pReqMsg->headerCrc != tempCRC32)
    {
        eStatus = SAIL_UPDATER_INVALID_HDR_CRC;
        goto CheckHeaderValidityEnd;
    }

    /* Validate Header Params */
    if ( (SAIL_UPD_MD2SAIL != pReqMsg->direction) || (0 != pReqMsg->status) || (sizeof(sailUpdaterMsgHeaderType) != pReqMsg->headerSize))
    {
        eStatus = SAIL_UPDATER_INVALID_HDR_PARAM;
        goto CheckHeaderValidityEnd;
    }

    /* Data Integrity of the buffers will be checked in the individual Messages as needed */
CheckHeaderValidityEnd:
    return eStatus;
}

/**********************************************************
 * Process the Request Message
 *
 *
 * @param pReqMsg [IN]
 *   Pointer to the Request Message
 *
 * @param pRspMsg [IN/OUT]
 *   Pointer to the Response Message
 *
 * @return void [OUT]
 *   None
 *
 **********************************************************/
void vSAILUpdaterMsgProcessReqMsg(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;

    /* Clear the Response message */
    memset(pRspMsg,0, sizeof(sailUpdaterMsgHeaderType));

    /* Set the MsgId for the RspMsg from ReqMsg so that the error can be prepared directly at the end */
    pRspMsg->msgId = pReqMsg->msgId;

    /* Check for Request Message Header Validity */
    eStatus = xSAILUpdaterMsgCheckHeaderValidity(pReqMsg);
    if (SAIL_UPDATER_STATUS_SUCCESS != eStatus)
    {
        goto processReqMsgEnd;
    }

    switch (pReqMsg->msgId)
    {
        case SAIL_UPD_MSG_ID_HELLO:
            DEBUG_LOG(SAIL_WARNING,"vSAILUpdaterMsgProcessReqMsg: Processing MSG ID Hello \n\r");
            eStatus = xSAILUpdaterCoreProcessHello(pReqMsg, pRspMsg);
            break;
        case SAIL_UPD_MSG_ID_QUERY_IMAGES:
            DEBUG_LOG(SAIL_WARNING,"vSAILUpdaterMsgProcessReqMsg: Processing MSG ID Query Images \n\r");
            eStatus = xSAILUpdaterCoreProcessQueryImg(pReqMsg, pRspMsg);
            break;
        case SAIL_UPD_MSG_ID_READ_IMAGE:
            DEBUG_LOG(SAIL_WARNING,"vSAILUpdaterMsgProcessReqMsg: Processing MSG ID Read Image \n\r");
            eStatus = xSAILUpdaterCoreProcessReadImg(pReqMsg, pRspMsg);
            break;
        case SAIL_UPD_MSG_ID_FLASH_IMAGE:
            DEBUG_LOG(SAIL_WARNING,"vSAILUpdaterMsgProcessReqMsg: Processing MSG ID Flash Image \n\r");
            eStatus = xSAILUpdaterCoreProcessFlashImg(pReqMsg, pRspMsg);
            break;
        case SAIL_UPD_MSG_ID_BOOT_IMAGE:
            DEBUG_LOG(SAIL_WARNING,"vSAILUpdaterMsgProcessReqMsg: Processing MSG ID Boot Image \n\r");
            eStatus = xSAILUpdaterCoreProcessBootImg(pReqMsg, pRspMsg);
            break;
        case SAIL_UPD_MSG_ID_BOOT_CONTINUE:
            DEBUG_LOG(SAIL_WARNING,"vSAILUpdaterMsgProcessReqMsg: Processing MSG ID Boot Continue \n\r");
            eStatus = xSAILUpdaterCoreProcessBootContinue(pReqMsg, pRspMsg);
            break;

        case SAIL_UPD_MSG_ID_CHECK_GPT:
        case SAIL_UPD_MSG_ID_READ_GPT:
        case SAIL_UPD_MSG_ID_WRITE_GPT:
        case SAIL_UPD_MSG_ID_FIX_GPT:
        case SAIL_UPD_MSG_ID_UPDATE_GPT:
        case SAIL_UPD_MSG_ID_GET_OTA_METADATA:
        case SAIL_UPD_MSG_ID_SET_OTA_METADATA:
        case SAIL_UPD_MSG_READ_OTA_METADATA:
        case SAIL_UPD_MSG_WRITE_OTA_METADATA:
        case SAIL_UPD_MSG_ERASE_OTA_METADATA:
        case SAIL_UPD_MSG_GET_OTA_METADATAINFO:
        case SAIL_UPD_MSG_ID_UPDATE_ARB:
        case SAIL_UPD_MSG_ID_UPDATE_MRC:
        case SAIL_UPD_MSG_OTA_DONE:
        case SAIL_UPD_MSG_REDUNDANCY_ESTABLISHED:
        case SAIL_UPD_MSG_TEST_ERROR_INJECTION:
        case SAIL_UPD_MSG_ID_GET_BOOTINFO:
#if 1
            DEBUG_LOG(SAIL_WARNING,"vSAILUpdaterMsgProcessReqMsg: Processing MSG ID Get Boot Info \n\r");
            eStatus = xSAILUpdaterCoreProcessGetBootInfo(pReqMsg, pRspMsg);
          break;
#endif
        default:
            DEBUG_LOG(SAIL_ERROR,"vSAILUpdaterMsgProcessReqMsg: Invalid Message ID received \n\r");
            eStatus = SAIL_UPDATER_INVALID_MSG_ID;
            break;
    }

processReqMsgEnd:
    if (SAIL_UPDATER_STATUS_SUCCESS != eStatus)
    {
        DEBUG_LOG(SAIL_INFO,"vSAILUpdaterMsgProcessReqMsg: Error in processed message, estatus: %d\n\r",eStatus);
        vSAILUpdaterMsgPrepareErrRsp(pRspMsg, eStatus);
    }
    else
    {
        DEBUG_LOG(SAIL_INFO,"vSAILUpdaterMsgProcessReqMsg: Message processed successfully \n\r");
    }
    return;
}

/**********************************************************
 * Prepares the Error Response Message
 *
 *
 * @param pRspMsg [IN/OUT]
 *   Pointer to the Request Message
 *
 * @param eStatus [IN]
 *   Error Message
 *
 * @return void [OUT]
 *   None
 *
 **********************************************************/
void vSAILUpdaterMsgPrepareErrRsp(sailUpdaterMsgHeaderType* pRspMsg, SAILUpdaterStatusType_e eStatus)
{
    if (pRspMsg)
    {
        pRspMsg->status = eStatus;
    }

    return;
}

/**********************************************************
 * SAIL Updater Write Response back Wrapper
 * Write Wrapper for Fasboot and Unit tests
 *
 * @param MBclient_ID [IN]
 *   Mailbox Client ID
 * @param num_item [IN]
 *   item number
 * @param rbuff [IN]
 *   response message
 *
 * @return xStatus [OUT]
 *   success/failure
 *
 **********************************************************/
int32 slMailboxWriteWrap(xMailboxExtclienttype MBclient_ID,uint32 num_item,uint8 *rbuff );
int32 slMailboxWriteWrap(xMailboxExtclienttype MBclient_ID,uint32 num_item,uint8 *rbuff )
{
    int32 retVal = 0;
#ifdef SAILUPDATER_TEST_SRC_ENABLED
    uint32_t uRxBufSize = sizeof(sailUpdaterMsgHeaderType) * num_item;
    if(TRUE == gSAILUpdaterTestSkipMailbox)
    {
        /* copy the Rx response Buffer to be sent to El2 Test */
        retVal = sailbsp_memscpy(xSAILUpdaterTestRxQueueBuffer, uRxBufSize,
                                         rbuff, uRxBufSize
                                         );
        if(retVal == 0)
        {
            return SAIL_UPDATER_STATUS_FAIL;
        }
        DEBUG_LOG(SAIL_INFO,"slMailboxWriteWrap: Rx Response Buffer copied \n\r");
    }
    else
#endif
    {
        DEBUG_LOG(SAIL_INFO,"slMailboxWriteWrap: slMailboxWrite\n\r");
        retVal = slMailboxWrite(MBclient_ID,num_item,rbuff);
        DEBUG_LOG(SAIL_INFO,"slMailboxWriteWrap: slMailboxWrite retval %d\n\r", retVal);
    }
    return retVal;
}

/**********************************************************
 * Sends the Response Message
 *
 *
 * @param pRspMsg [IN/OUT]
 *   Pointer to the Request Message
 *
 * @return void [OUT]
 *   None
 *
 **********************************************************/
void vSAILUpdaterMsgSendResponse(sailUpdaterMsgHeaderType* pRspMsg)
{
    uint32_t errorId = 0U;
    /* Set the Header Size */
    pRspMsg->headerSize = sizeof(sailUpdaterMsgHeaderType);

    /* Set the Header Direction */
    pRspMsg->direction = SAIL_UPD_SAIL2MD;

    /* Calculate the Header CRC */
    pRspMsg->headerCrc = 0;
    pRspMsg->headerCrc = ulSAILUpdaterCoreCalcCRC((uint32_t)pRspMsg, sizeof(sailUpdaterMsgHeaderType));

    /* Flush and Invalidate the cache */
    clean_invalidate_cache_by_range((uint32) pRspMsg,(uint32)pRspMsg + sizeof(sailUpdaterMsgHeaderType));

    /* Send the Response over Mailbox */
    if(slMailboxWriteWrap(MAILBOX_OTA,1,(uint8 *)pRspMsg) > 0)
    {
        /* Log Message sent */
        DEBUG_LOG(SAIL_WARNING,"vSAILUpdaterMsgSendResponse: Sent Response to Mailbox \n\r");
    }
    else
    {
        /* error in reading from mailbox. log and loop */
        DEBUG_LOG(SAIL_ERROR,"vSAILUpdaterMsgSendResponse: Error Writing to Mailbox \n\r");
        errorId = SAIL_UPDATER_STATUS_FAIL;
        err_fatal(MAILBOX, errorId);
    }
}

