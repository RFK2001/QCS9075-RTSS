/*
===========================================================================
*/
/**
    @file  sailupdater_tests.c
    @brief Implementation of SAIL Updater Unit test and Functional test

*/
/*
    ===========================================================================

    Copyright (c) 2023-24 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/asuthar.bsp.sail.1.0.TestFolderReStructure/tests/sailsw1/sailupdater_tests.c#1 $
    $DateTime: 2024/01/25 22:37:00 $
    $Author: asuthar $
=========================================================================================================*/

/*=========================================================================================================
**                                        Include files                                                  **
=========================================================================================================*/
#include "common_functions.h"
#include "debug_log.h"
#include "cache_ops.h"
#include "common_functions.h"
#include "tests.h"
#include "sail_updater_core.h"
#include "mailboxExt_api.h"
#include "autosar_crc.h"
#include "syscall_pub.h"
#include "syscall_hvc.h"
#include "chipinfo.h"

#ifdef SAILUPDATER_TEST_SRC_ENABLED
extern void vSAILupdMailboxcb(xMailboxExtclienttype MBclient_ID);
/*=========================================================================================================
**                                        Local defines and macros                                       **
=========================================================================================================*/
/* Task Init Macros */
#define SAIL_UPD_VER_MAJ 1
#define SAIL_UPD_VER_MIN 0
#define SAIL_VA_ADDR 0x2D000000
#define SAIL_VA_ADDR_SRV1 0x2E000000
#define MD_VA_ADDR 0x8D000000
#define SAIL_ADDR_DIFF 0x60000000
#define MAX_IMAGES 5
#define SAIL_UPD_IMG_NAME_INV             "SAIL_INV"
#define MAX_INV_LEN 2097153

/* Queue Init Macros */
#define SAIL_UPDATERTEST_TXQ_LENGTH           ( 2 )
#define SAIL_UPDATERTEST_RXQ_LENGTH           ( 1 )
#define SAIL_UPDATERTEST_Q_ITEM_SIZE        ( sizeof(sailUpdaterMsgHeaderType) )
#define SAIL_UPDATERTEST_TXQ_BUFFER_SIZE      ( SAIL_UPDATERTEST_TXQ_LENGTH * SAIL_UPDATERTEST_Q_ITEM_SIZE )
#define SAIL_UPDATERTEST_RXQ_BUFFER_SIZE      ( SAIL_UPDATERTEST_RXQ_LENGTH * SAIL_UPDATERTEST_Q_ITEM_SIZE )

/*Enum defines all TEST ID's for SAIL Updater*/
typedef enum
{
    TEST_INVHELLO_VER=0,
    TEST_INVHELLO,
    TEST_HELLO,
    TEST_GETOTAMETADATA_UNALGNBUFSZ,
    TEST_GETOTAMETADATA_INVADDR,
    TEST_GETOTAMETADATA_INVBUFSZ,
    TEST_GETOTAMETADATA,
    TEST_GETBOOTINFO_INVBUFSZ,
    TEST_GETBOOTINFO_INVBUFCRC,
    TEST_GETBOOTINFO_INVBUFADDR,
    TEST_GETBOOTINFO_INVNUMIMG,
    TEST_GETBOOTINFO_INVIMGNAME,
    TEST_GETBOOTINFO,
    TEST_FLASHIMG_INVIMGNAME,
    TEST_FLASHIMG_INVPARTID,
    TEST_FLASHIMG_INVGPTID,
    TEST_FLASHIMG_INVBUFADDR,
    TEST_FLASHIMG_INVBUFSZ,
    TEST_FLASHIMG_INVBUFCRC,
    TEST_FLASHIMG_UNALGNBUFSZ,
    TEST_FLASHIMG,
    TEST_READIMG_INVIMGNAME,
    TEST_READIMG_INVPARTID,
    TEST_READIMG_INVGPTID,
    TEST_READIMG_INVBUFADDR,
    TEST_READIMG_INVBUFSZ,
    TEST_READIMG_UNALGNBUFSZ,
    TEST_READIMG,
    TEST_SETOTAMETADATA_UNALGNBUFSZ,
    TEST_SETOTAMETADATA_INVADDR,
    TEST_SETOTAMETADATA_INVBUFSZ,
    TEST_SETOTAMETADATA_INVBUFCRC,
    TEST_SETOTAMETADATA,
    TEST_FIXGPT_INVBUFSZ,
    TEST_FIXGPT_INVBUFADDR,
    TEST_FIXGPT_UNALGNBUFSZ,
    TEST_FIXGPT_INVGPTID,
    TEST_FIXGPT,
    TEST_UPDGPT_INVBUFSZ,
    TEST_UPDGPT_INVBUFCRC,
    TEST_UPDGPT_INVBUFADDR,
    TEST_UPDGPT_INVNUMIMG,
    TEST_UPDGPT,
    TEST_READGPT_INVBUFSZ,
    TEST_READGPT_INVBUFADDR,
    TEST_READGPT_UNALGNBUFSZ,
    TEST_READGPT_INVGPTID,
    TEST_READGPT,
    TEST_WRITEGPT_INVBUFSZ,
    TEST_WRITEGPT_INVBUFADDR,
    TEST_WRITEGPT_UNALGNBUFSZ,
    TEST_WRITEGPT_INVGPTID,
    TEST_WRITEGPT,
    TEST_QUERYIMG_INVNUMIMG,
    TEST_QUERYIMG_INVBUFSZ,
    TEST_QUERYIMG_INVBUFCRC,
    TEST_QUERYIMG_INVBUFADDR,
    TEST_QUERYIMG_INVIMGNAME,
    TEST_QUERYIMG,
    TEST_CHECKGPT,
    TEST_GETOTAMETADATAINFO,
    TEST_ARB,
    TEST_MRC,
    TEST_REDUNDANCY,
    TEST_OTA_DONE,
    TEST_ID_MAX,
}sailUpdTestCaseIDType;

/* Updater Message Context type */
typedef struct
{
    sailUpdaterMsgHeaderType TxMsg;
    sailUpdaterMsgHeaderType RxMsg;
}SAILUpdaterTestMsg_t;

/* Updater Global Rx Messages */
typedef struct
{
    uint32_t primaryGptSize;
    uint32_t secondaryGptSize;
    uint32_t blInfoNumImagesBoot;
    uint32_t blInfoSailAddr;
    uint32_t rdImgBufAddr;
    uint32_t rdImgBufLen;
    uint32_t rdImgBufCrc;
    uint32_t readGptId;
    uint32_t readGptBufLen;
    sailUpdaterImageEntryType updImgEntryType[MAX_IMAGES];
    uint32_t metadataSize_KB;
    OTAMetaDataSectorMapInfoType sectorMap[3];
}SAILUpdaterTestRxMsgCtx_t;

/*=========================================================================================================
**                                        Static variables and constants                                 **
=========================================================================================================*/
/*This variable makes sure Queue creation happens only once*/
TEST_DATA static boolean bSAILUpdaterTestStart = FALSE;
/*This variable takes care of image name for Functional test*/
TEST_DATA static boolean bSAILUpdaterFuncTestReadImg = FALSE;

#ifdef SAILUPDATER_TEST_SRC_ENABLED
/* Queue Buffers and Handles definitions */
TEST_DATA uint8_t xSAILUpdaterTestRxQueueBuffer[ SAIL_UPDATERTEST_RXQ_BUFFER_SIZE ] __attribute__( ( aligned( MEM_ALIGNMENT_4 ) ) ) = { 0 };
TEST_DATA QueueHandle_t xSAILUpdaterTestRxQueueHandle = NULL;
TEST_DATA  StaticQueue_t xSAILUpdaterTestRxQueueBufferStatic;
TEST_DATA uint8_t xSAILUpdaterTestTxQueueBuffer[ SAIL_UPDATERTEST_TXQ_BUFFER_SIZE ] __attribute__( ( aligned( MEM_ALIGNMENT_4 ) ) ) = { 0 };
TEST_DATA QueueHandle_t xSAILUpdaterTestTxQueueHandle = NULL;
TEST_DATA  StaticQueue_t xSAILUpdaterTestTxQueueBufferStatic;
/* Updater Message Context */
TEST_DATA SAILUpdaterTestMsg_t g_SAILUPdaterTestCtx = {0};
TEST_DATA SAILUpdaterTestRxMsgCtx_t gRxMsgCtx = {0};
#endif

/**********************************************************
 * Initalize the Queue
 *
 *
 * @return portBaseType [OUT]
 *   Status of the Operation
 *
 **********************************************************/
TEST_FUNC BaseType_t xSAILUpdaterTestQueueInit( void )
{
    BaseType_t xCreateResult = pdPASS;
    xCreateResult = xFreeRTOSQueueCreate( xSAILUpdaterTestRxQueueBuffer,
                                  SAIL_UPDATERTEST_RXQ_LENGTH,
                                  SAIL_UPDATERTEST_Q_ITEM_SIZE,
                                  &xSAILUpdaterTestRxQueueHandle,& xSAILUpdaterTestRxQueueBufferStatic);
    if( xCreateResult != pdPASS )
    {
        return pdFAIL;
    }
    xCreateResult = xFreeRTOSQueueCreate( xSAILUpdaterTestTxQueueBuffer,
                                  SAIL_UPDATERTEST_TXQ_LENGTH,
                                  SAIL_UPDATERTEST_Q_ITEM_SIZE,
                                  &xSAILUpdaterTestTxQueueHandle,& xSAILUpdaterTestTxQueueBufferStatic);
    if( xCreateResult != pdPASS )
    {
        return pdFAIL;
    }
    return xCreateResult;
}

/**********************************************************
 * Receives the Sail Image Updater Test Response from SAIL
 *
 *
 * @param pRxMsg [IN/OUT]
 *   Pointer to the Response Message
 *
 * @return TESTerrorType_e [OUT]
 *   None
 *
 **********************************************************/
TEST_FUNC TESTerrorType_e vSAILUpdaterTestRespMessage(sailUpdaterMsgHeaderType* pRxMsg)
{
    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    BaseType_t xStatus            = pdFALSE;
    UBaseType_t uxNumberOfItems = 0U;
    uint32_t headerCrcBkup = 0,headerCrc = 0;
    uint32_t testBufLen = 0;
    uint32_t testBufAddr = 0;

    if(NULL == pRxMsg)
    {
        DEBUG_LOG(SAIL_ERROR,"vSAILUpdaterTestRespMessage: pRxMsg NULL\n\r");
        return MODULE_TEST_FAILED;
    }

    xStatus = xFreeRTOSQueueReceive( xSAILUpdaterTestRxQueueHandle, pRxMsg, pdMS_TO_TICKS( freertosMAX_DELAY ));
    if( xStatus == pdPASS )
    {
        xRetStatus = MODULE_TEST_PASSED;
    }
   /* Validate the Header CRC */
    testBufLen = pRxMsg->headerSize;
    testBufAddr = (uint32_t)pRxMsg;
    headerCrcBkup = pRxMsg->headerCrc;
    pRxMsg->headerCrc = 0;
    headerCrc = ulAutosarCrcBufList(AUTOSAR_CRC_32BIT_ETHERNET, &testBufAddr, &testBufLen, 1);
    if (headerCrc != headerCrcBkup)
    {
        DEBUG_LOG(SAIL_ERROR,"vSAILUpdaterTestRespMessage: Header CRC check failed for Rx Message \n\r");
        xRetStatus = MODULE_TEST_FAILED;
    }
    return xRetStatus;
}

/**********************************************************
 * Sends the Sail Image Updater Test Message to SAIL and waits on receive
 *
 *
 * @param pTxMsg [IN/OUT]
 *   Pointer to the Request Message
 *
 * @return TESTerrorType_e [OUT]
 *   None
 *
 **********************************************************/
TEST_FUNC TESTerrorType_e vSAILUpdaterTestSendReceiveMessage(sailUpdaterMsgHeaderType* pTxMsg)
{
    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    uint32_t testBufLen = 0;
    uint32_t testBufAddr = 0;
    uint32_t testHeaderCrc = 0;

    if(NULL == pTxMsg)
    {
        DEBUG_LOG(SAIL_ERROR,"vSAILUpdaterTestSendReceiveMessage: pTxMsg NULL\n\r");
        return MODULE_TEST_FAILED;
    }

    /* Set the Header Size */
    pTxMsg->headerSize = sizeof(sailUpdaterMsgHeaderType);
    testBufLen = pTxMsg->headerSize;
    testBufAddr = (uint32_t)pTxMsg;

    //Skip Addr check
    vSailUpdaterSetSkipAddrCheck(TRUE);

    //Skip Mail box
    vSailUpdaterSetSkipMB(TRUE);

    /* Set the Header Direction */
    pTxMsg->direction = SAIL_UPD_MD2SAIL;

    /* Calculate the Header CRC */
    pTxMsg->headerCrc = 0;
    pTxMsg->headerCrc = ulAutosarCrcBufList(AUTOSAR_CRC_32BIT_ETHERNET, &testBufAddr, &testBufLen, 1);

    /* Flush and Invalidate the cache */
    clean_invalidate_cache_by_range((uint32) pTxMsg,(uint32)pTxMsg + sizeof(sailUpdaterMsgHeaderType));

    /* Queue Send */
    if( pdPASS !=xFreeRTOSQueueSend( xSAILUpdaterTestTxQueueHandle, pTxMsg, pdMS_TO_TICKS( freertosMAX_DELAY ) ) )
    {
        DEBUG_LOG(SAIL_INFO, " vSAILUpdaterTestSendReceiveMessage: xQueueSend Failed\n\r");
        return MODULE_TEST_FAILED;
    }
    else
    {
        DEBUG_LOG(SAIL_INFO, " vSAILUpdaterTestSendReceiveMessage: xQueueSend Pass\n\r");
    }

    /* Send the Message over Mailbox */
    vSAILupdMailboxcb(MAILBOX_OTA);

    /* Receive the Message*/
    xRetStatus = vSAILUpdaterTestRespMessage(&g_SAILUPdaterTestCtx.RxMsg);
    if(MODULE_TEST_PASSED == xRetStatus)
    {
        DEBUG_LOG(SAIL_INFO, "vSAILUpdaterTestSendReceiveMessage: Receive Done\r\n");
    }
    else
    {
        DEBUG_LOG(SAIL_INFO, "vSAILUpdaterTestSendReceiveMessage: Receive Failed\r\n");
        xRetStatus = MODULE_TEST_FAILED;
    }

    /* Enable Addr check */
    vSailUpdaterSetSkipAddrCheck(FALSE);

    /* Enable Mail box */
    vSailUpdaterSetSkipMB(FALSE);

    return xRetStatus;
}

/*----------------------------------------------------------------------------
* sail_updater: send Hello
*
* @param sailUpdTestCaseIDType testID[IN]
*
* @return TESTerrorType_e [OUT]
*   Status of the operation MODULE_TEST_FAILED/MODULE_TEST_SUCCESS.
*
*--------------------------------------------------------------------------*/
TEST_FUNC TESTerrorType_e TC_SailUpdater_Hello(sailUpdTestCaseIDType testID)
{
    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    uint32_t sz = (uint32_t)sizeof(sailUpdaterMsgHeaderType);
    /* reset msg */
    (void)memset((void*)&(g_SAILUPdaterTestCtx.TxMsg), 0, sz);
    (void)memset((void*)&(g_SAILUPdaterTestCtx.RxMsg), 0, sz);

    /* parse & pack msg */
    g_SAILUPdaterTestCtx.TxMsg.msgId      = SAIL_UPD_MSG_ID_HELLO;
    g_SAILUPdaterTestCtx.TxMsg.status     = SAIL_UPD_STATUS_SUCCESS;
    g_SAILUPdaterTestCtx.TxMsg.hello.hello[0]    = (uint8_t)'H';
    g_SAILUPdaterTestCtx.TxMsg.hello.hello[1]    = (uint8_t)'E';
    g_SAILUPdaterTestCtx.TxMsg.hello.hello[2]    = (uint8_t)'L';
    g_SAILUPdaterTestCtx.TxMsg.hello.hello[3]    = (uint8_t)'L';
    g_SAILUPdaterTestCtx.TxMsg.hello.hello[4]    = (uint8_t)'O';
    g_SAILUPdaterTestCtx.TxMsg.hello.hello[5]    = (uint8_t)'\0';
    g_SAILUPdaterTestCtx.TxMsg.hello.mailboxVersionMajor  = SAIL_UPD_VER_MAJ;
    g_SAILUPdaterTestCtx.TxMsg.hello.mailboxVersionMinor  = SAIL_UPD_VER_MIN;

    switch (testID)
    {
        case TEST_HELLO:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_Hello: TEST_HELLO\r\n");
            break;
        case TEST_INVHELLO:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_Hello: TEST_INVHELLO\r\n");
            g_SAILUPdaterTestCtx.TxMsg.hello.hello[2]    = (uint8_t)'E';
            break;
        case TEST_INVHELLO_VER:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_Hello: TEST_INVHELLO_VER\r\n");
            g_SAILUPdaterTestCtx.TxMsg.hello.mailboxVersionMajor  = SAIL_UPD_VER_MIN;
            g_SAILUPdaterTestCtx.TxMsg.hello.mailboxVersionMinor  = SAIL_UPD_VER_MAJ;
            break;
        default:
            xRetStatus = MODULE_TEST_FAILED;
            goto InvTestID;
    }

    /* Send Message and Receive response*/
    xRetStatus = vSAILUpdaterTestSendReceiveMessage(&g_SAILUPdaterTestCtx.TxMsg);
    if(MODULE_TEST_PASSED == xRetStatus)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_Hello: Sent-Receive Done\r\n");
    }
    else
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_Hello: Sent/Receive Failed\r\n");
        return xRetStatus;
    }

    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.msgId != SAIL_UPD_MSG_ID_HELLO)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_Hello: Response Failure with Invalid MsgID\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        goto InvTestID;
    }
    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.direction != SAIL_UPD_SAIL2MD)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_Hello: Response Failure with Invalid direction\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        goto InvTestID;
    }

    switch (testID)
    {
        case TEST_HELLO:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_STATUS_SUCCESS)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_Hello: Response Success\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_Hello: Response Failure\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_INVHELLO:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_HELLO_MSG)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_Hello: Response Success SAIL_UPDATER_INVALID_HELLO_MSG %d\r\n\n", g_SAILUPdaterTestCtx.RxMsg.status);
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_Hello: Response Fail %d Expected SAIL_UPDATER_INVALID_HELLO_MSG\r\n\n", g_SAILUPdaterTestCtx.RxMsg.status);
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_INVHELLO_VER:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_VERSION)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_Hello: Response Success SAIL_UPDATER_INVALID_VERSION %d\r\n\n", g_SAILUPdaterTestCtx.RxMsg.status);
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_Hello: Response Fail %d Expected SAIL_UPDATER_INVALID_VERSION\r\n\n", g_SAILUPdaterTestCtx.RxMsg.status);
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        default:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_Hello: Invalid Test ID\r\n\n");
            xRetStatus = MODULE_TEST_FAILED;
            break;
    }

InvTestID:
    return xRetStatus;

}

/*----------------------------------------------------------------------------
* sail_updater: check GPT
*
* @param sailUpdTestCaseIDType testID[IN]
*
* @return TESTerrorType_e [OUT]
*   Status of the operation MODULE_TEST_FAILED/MODULE_TEST_SUCCESS.
*
*--------------------------------------------------------------------------*/
TEST_FUNC TESTerrorType_e TC_SailUpdater_checkGPT(sailUpdTestCaseIDType testID)
{
    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    uint32_t sz = (uint32_t)sizeof(sailUpdaterMsgHeaderType);
    /* reset msg */
    (void)memset((void*)&(g_SAILUPdaterTestCtx.TxMsg), 0, sz);
    (void)memset((void*)&(g_SAILUPdaterTestCtx.RxMsg), 0, sz);

    if(testID != TEST_CHECKGPT)
    {
        return xRetStatus;
    }

    /* parse & pack msg */
    g_SAILUPdaterTestCtx.TxMsg.msgId      = SAIL_UPD_MSG_ID_CHECK_GPT;
    g_SAILUPdaterTestCtx.TxMsg.status     = SAIL_UPD_STATUS_SUCCESS;
    g_SAILUPdaterTestCtx.TxMsg.checkGpt.primaryGptHeaderCrcStatus = 0;
    g_SAILUPdaterTestCtx.TxMsg.checkGpt.primaryGptEntryCrcStatus = 0;
    g_SAILUPdaterTestCtx.TxMsg.checkGpt.primaryGptSize = 0;
    g_SAILUPdaterTestCtx.TxMsg.checkGpt.secondaryGptHeaderCrcStatus = 0;
    g_SAILUPdaterTestCtx.TxMsg.checkGpt.secondaryGptEntryCrcStatus  = 0;
    g_SAILUPdaterTestCtx.TxMsg.checkGpt.secondaryGptSize = 0;

    /* Send Message and Receive response*/
    xRetStatus = vSAILUpdaterTestSendReceiveMessage(&g_SAILUPdaterTestCtx.TxMsg);
    if(MODULE_TEST_PASSED == xRetStatus)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_checkGPT: Sent-Receive Done\r\n");
    }
    else
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_checkGPT: Sent/Receive Failed\r\n");
        return xRetStatus;
    }

    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.msgId != SAIL_UPD_MSG_ID_CHECK_GPT)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_checkGPT: Response Failure with Invalid MsgID\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.direction != SAIL_UPD_SAIL2MD)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_checkGPT: Response Failure with Invalid direction\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_STATUS_SUCCESS)
    {
        if (g_SAILUPdaterTestCtx.RxMsg.checkGpt.primaryGptHeaderCrcStatus == 1 &&
            g_SAILUPdaterTestCtx.RxMsg.checkGpt.primaryGptEntryCrcStatus == 1 &&
            g_SAILUPdaterTestCtx.RxMsg.checkGpt.secondaryGptHeaderCrcStatus == 1 &&
            g_SAILUPdaterTestCtx.RxMsg.checkGpt.secondaryGptEntryCrcStatus == 1)
        {
            gRxMsgCtx.primaryGptSize = g_SAILUPdaterTestCtx.RxMsg.checkGpt.primaryGptSize;
            gRxMsgCtx.secondaryGptSize = g_SAILUPdaterTestCtx.RxMsg.checkGpt.secondaryGptSize;
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_checkGPT: Response Success\r\n\n");
            xRetStatus = MODULE_TEST_PASSED;
        }
    }
    else
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_checkGPT: Response Failure\r\n\n");
        xRetStatus = MODULE_TEST_FAILED;
    }
    return xRetStatus;
}

/*----------------------------------------------------------------------------
* sail_updater: fix GPT
*
* @param sailUpdTestCaseIDType testID[IN]
*
* @return TESTerrorType_e [OUT]
*   Status of the operation MODULE_TEST_FAILED/MODULE_TEST_SUCCESS.
*
*--------------------------------------------------------------------------*/
TEST_FUNC TESTerrorType_e TC_SailUpdater_fixGPT(sailUpdTestCaseIDType testID, boolean ext_support)
{
    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    uint32_t sz = (uint32_t)sizeof(sailUpdaterMsgHeaderType);
    /* reset msg */
    (void)memset((void*)&(g_SAILUPdaterTestCtx.TxMsg), 0, sz);
    (void)memset((void*)&(g_SAILUPdaterTestCtx.RxMsg), 0, sz);

    xRetStatus = TC_SailUpdater_checkGPT(TEST_CHECKGPT);
    if (MODULE_TEST_FAILED == xRetStatus)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_fixGPT:checkGpt FAILED before FixGPT \n\r");
        return xRetStatus;
    }

    if (TRUE == ext_support)
    {
        g_SAILUPdaterTestCtx.TxMsg.fixGpt.ext_id.id = 0;
        g_SAILUPdaterTestCtx.TxMsg.fixGpt.ext_id.fixtype = 1;
    }
    else
    {
       g_SAILUPdaterTestCtx.TxMsg.fixGpt.id = 0;
    }

    /* parse & pack msg */
    g_SAILUPdaterTestCtx.TxMsg.msgId      = SAIL_UPD_MSG_ID_FIX_GPT;
    g_SAILUPdaterTestCtx.TxMsg.status     = SAIL_UPD_STATUS_SUCCESS;
    g_SAILUPdaterTestCtx.TxMsg.fixGpt.bufAddr = MD_VA_ADDR;
    g_SAILUPdaterTestCtx.TxMsg.fixGpt.bufLen = 2*24*1024;

   switch (testID)
    {
        case TEST_FIXGPT:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_fixGPT: TEST_FIXGPT\r\n");
            break;
        case TEST_FIXGPT_INVBUFADDR:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_fixGPT: TEST_FIXGPT_INVBUFADDR\r\n");
            g_SAILUPdaterTestCtx.TxMsg.fixGpt.bufAddr = 0U;
            break;
        case TEST_FIXGPT_INVBUFSZ:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_fixGPT: TEST_FIXGPT_INVBUFSZ\r\n");
            g_SAILUPdaterTestCtx.TxMsg.fixGpt.bufLen = (2*gRxMsgCtx.primaryGptSize)-16;
            break;
        case TEST_FIXGPT_UNALGNBUFSZ:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_fixGPT: TEST_FIXGPT_UNALGNBUFSZ\r\n");
            g_SAILUPdaterTestCtx.TxMsg.fixGpt.bufLen = (2*gRxMsgCtx.primaryGptSize)+3;
            break;
        case TEST_FIXGPT_INVGPTID:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_fixGPT: TEST_FIXGPT_INVGPTID\r\n");
            g_SAILUPdaterTestCtx.TxMsg.fixGpt.id = SAIL_UPD_GPT_ID_MAX;
            break;
        default:
            xRetStatus = MODULE_TEST_FAILED;
            return xRetStatus;
    }

    /* Send Message and Receive response*/
    xRetStatus = vSAILUpdaterTestSendReceiveMessage(&g_SAILUPdaterTestCtx.TxMsg);
    if(MODULE_TEST_PASSED == xRetStatus)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_fixGPT: Sent-Receive Done\r\n");
    }
    else
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_fixGPT: Sent/Receive Failed\r\n");
        return xRetStatus;
    }

    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.msgId != SAIL_UPD_MSG_ID_FIX_GPT)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_fixGPT: Response Failure with Invalid MsgID\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.direction != SAIL_UPD_SAIL2MD)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_fixGPT: Response Failure with Invalid direction\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    switch (testID)
    {
        case TEST_FIXGPT:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_STATUS_SUCCESS)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_fixGPT: Response Success\r\n\n");
             xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_fixGPT: Response Failure\r\n\n");
               xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_FIXGPT_INVBUFADDR:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_BUF_ADDR)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_fixGPT: Response Success SAIL_UPDATER_INVALID_BUF_ADDR\r\n\n");
             xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_fixGPT: Response Failure expected SAIL_UPDATER_INVALID_BUF_ADDR\r\n\n");
               xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_FIXGPT_INVBUFSZ:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_BUF_SIZE)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_fixGPT: Response Success SAIL_UPDATER_INVALID_BUF_SIZE\r\n\n");
             xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_fixGPT: Response Failure expected SAIL_UPDATER_INVALID_BUF_SIZE\r\n\n");
               xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_FIXGPT_UNALGNBUFSZ:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_UNALIGNED_BUF_SIZE)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_fixGPT: Response Success SAIL_UPDATER_UNALIGNED_BUF_SIZE\r\n\n");
             xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_fixGPT: Response Failure expected SAIL_UPDATER_UNALIGNED_BUF_SIZE\r\n\n");
               xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_FIXGPT_INVGPTID:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_GPT_ID)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_fixGPT: Response Success SAIL_UPDATER_INVALID_GPT_ID\r\n\n");
             xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_fixGPT: Response Failure expected SAIL_UPDATER_INVALID_GPT_ID\r\n\n");
               xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        default:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_fixGPT: Invalid Test ID\r\n\n");
            xRetStatus = MODULE_TEST_FAILED;
            break;
        }
    return xRetStatus;
}

/*----------------------------------------------------------------------------
* sail_updater: read GPT
*
* @param sailUpdTestCaseIDType testID[IN]
*
* @return TESTerrorType_e [OUT]
*   Status of the operation MODULE_TEST_FAILED/MODULE_TEST_SUCCESS.
*
*--------------------------------------------------------------------------*/
TEST_FUNC TESTerrorType_e TC_SailUpdater_readGPT(sailUpdTestCaseIDType testID)
{
    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    uint32_t sz = (uint32_t)sizeof(sailUpdaterMsgHeaderType);
    /* reset msg */
    (void)memset((void*)&(g_SAILUPdaterTestCtx.TxMsg), 0, sz);
    (void)memset((void*)&(g_SAILUPdaterTestCtx.RxMsg), 0, sz);

    xRetStatus = TC_SailUpdater_checkGPT(TEST_CHECKGPT);
    if (MODULE_TEST_FAILED == xRetStatus)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readGPT:checkGpt FAILED before ReadGPT \n\r");
        return xRetStatus;
    }

    /* parse & pack msg */
    g_SAILUPdaterTestCtx.TxMsg.msgId      = SAIL_UPD_MSG_ID_READ_GPT;
    g_SAILUPdaterTestCtx.TxMsg.status     = SAIL_UPD_STATUS_SUCCESS;
    g_SAILUPdaterTestCtx.TxMsg.readGpt.id = 1;
    g_SAILUPdaterTestCtx.TxMsg.readGpt.bufAddr = MD_VA_ADDR;
    g_SAILUPdaterTestCtx.TxMsg.readGpt.bufLen = 2*24*1024;

   switch (testID)
    {
        case TEST_READGPT:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readGPT: TEST_READGPT\r\n");
            break;
        case TEST_READGPT_INVBUFADDR:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readGPT: TEST_READGPT_INVBUFADDR\r\n");
            g_SAILUPdaterTestCtx.TxMsg.readGpt.bufAddr = 0U;
            break;
        case TEST_READGPT_INVBUFSZ:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readGPT: TEST_READGPT_INVBUFSZ\r\n");
            g_SAILUPdaterTestCtx.TxMsg.readGpt.bufLen = gRxMsgCtx.primaryGptSize-16;
            break;
        case TEST_READGPT_UNALGNBUFSZ:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readGPT: TEST_READGPT_UNALGNBUFSZ\r\n");
            g_SAILUPdaterTestCtx.TxMsg.readGpt.bufLen = gRxMsgCtx.primaryGptSize+3;
            break;
        case TEST_READGPT_INVGPTID:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readGPT: TEST_READGPT_INVGPTID\r\n");
            g_SAILUPdaterTestCtx.TxMsg.readGpt.id = SAIL_UPD_GPT_ID_MAX;
            break;
        default:
            xRetStatus = MODULE_TEST_FAILED;
            return xRetStatus;
    }

    /* Send Message and Receive response*/
    xRetStatus = vSAILUpdaterTestSendReceiveMessage(&g_SAILUPdaterTestCtx.TxMsg);
    if(MODULE_TEST_PASSED == xRetStatus)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readGPT: Sent-Receive Done\r\n");
    }
    else
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readGPT: Sent/Receive Failed\r\n");
        return xRetStatus;
    }

    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.msgId != SAIL_UPD_MSG_ID_READ_GPT)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readGPT: Response Failure with Invalid MsgID\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.direction != SAIL_UPD_SAIL2MD)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readGPT: Response Failure with Invalid direction\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readGPT: Status %d\r\n", g_SAILUPdaterTestCtx.RxMsg.status);
    switch (testID)
    {
        case TEST_READGPT:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_STATUS_SUCCESS)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readGPT: Response Success\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
                gRxMsgCtx.readGptBufLen  = g_SAILUPdaterTestCtx.RxMsg.readGpt.bufLen;
                gRxMsgCtx.readGptId =g_SAILUPdaterTestCtx.RxMsg.readGpt.id;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readGPT: Response Failure\r\n\n");
               xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_READGPT_INVBUFADDR:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_BUF_ADDR)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readGPT: Response Success SAIL_UPDATER_INVALID_BUF_ADDR\r\n\n");
             xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readGPT: Response Failure expected SAIL_UPDATER_INVALID_BUF_ADDR\r\n\n");
               xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_READGPT_INVBUFSZ:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_BUF_SIZE)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readGPT: Response Success SAIL_UPDATER_INVALID_BUF_SIZE\r\n\n");
             xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readGPT: Response Failure expected SAIL_UPDATER_INVALID_BUF_SIZE\r\n\n");
               xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_READGPT_UNALGNBUFSZ:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_UNALIGNED_BUF_SIZE)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readGPT: Response Success SAIL_UPDATER_UNALIGNED_BUF_SIZE\r\n\n");
             xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readGPT: Response Failure expected SAIL_UPDATER_UNALIGNED_BUF_SIZE\r\n\n");
               xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_READGPT_INVGPTID:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_GPT_ID)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readGPT: Response Success SAIL_UPDATER_INVALID_GPT_ID\r\n\n");
             xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readGPT: Response Failure expected SAIL_UPDATER_INVALID_GPT_ID\r\n\n");
               xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        default:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readGPT: Invalid Test ID\r\n\n");
            xRetStatus = MODULE_TEST_FAILED;
            break;
        }
    return xRetStatus;
}

/*----------------------------------------------------------------------------
* sail_updater: write GPT
*
* @param sailUpdTestCaseIDType testID[IN]
*
* @return TESTerrorType_e [OUT]
*   Status of the operation MODULE_TEST_FAILED/MODULE_TEST_SUCCESS.
*
*--------------------------------------------------------------------------*/
TEST_FUNC TESTerrorType_e TC_SailUpdater_writeGPT(sailUpdTestCaseIDType testID)
{
    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    uint32_t sz = (uint32_t)sizeof(sailUpdaterMsgHeaderType);
    uint32_t size = 0;
    uint32_t bufAddr = 0;
    /* reset msg */
    (void)memset((void*)&(g_SAILUPdaterTestCtx.TxMsg), 0, sz);
    (void)memset((void*)&(g_SAILUPdaterTestCtx.RxMsg), 0, sz);

    xRetStatus = TC_SailUpdater_checkGPT(TEST_CHECKGPT);
    if (MODULE_TEST_FAILED == xRetStatus)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_writeGPT:checkGpt FAILED before WriteGPT \n\r");
        return xRetStatus;
    }

    /* parse & pack msg */
    g_SAILUPdaterTestCtx.TxMsg.msgId      = SAIL_UPD_MSG_ID_WRITE_GPT;
    g_SAILUPdaterTestCtx.TxMsg.status     = SAIL_UPD_STATUS_SUCCESS;
    g_SAILUPdaterTestCtx.TxMsg.writeGpt.id = gRxMsgCtx.readGptId;
    g_SAILUPdaterTestCtx.TxMsg.writeGpt.bufAddr = MD_VA_ADDR;
    g_SAILUPdaterTestCtx.TxMsg.writeGpt.bufLen = gRxMsgCtx.readGptBufLen;
    bufAddr = g_SAILUPdaterTestCtx.TxMsg.writeGpt.bufAddr-SAIL_ADDR_DIFF;
    size = g_SAILUPdaterTestCtx.TxMsg.writeGpt.bufLen;
    g_SAILUPdaterTestCtx.TxMsg.writeGpt.bufCrc = ulAutosarCrcBufList(AUTOSAR_CRC_32BIT_ETHERNET, &bufAddr, &size, 1);

   switch (testID)
    {
        case TEST_WRITEGPT:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_writeGPT: TEST_WRITEGPT\r\n");
            break;
        case TEST_WRITEGPT_INVBUFADDR:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_writeGPT: TEST_WRITEGPT_INVBUFADDR\r\n");
            g_SAILUPdaterTestCtx.TxMsg.readGpt.bufAddr = 0U;
            break;
        case TEST_WRITEGPT_INVBUFSZ:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_writeGPT: TEST_WRITEGPT_INVBUFSZ\r\n");
            g_SAILUPdaterTestCtx.TxMsg.readGpt.bufLen = gRxMsgCtx.primaryGptSize-16;
            break;
        case TEST_WRITEGPT_UNALGNBUFSZ:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_writeGPT: TEST_WRITEGPT_UNALGNBUFSZ\r\n");
            g_SAILUPdaterTestCtx.TxMsg.readGpt.bufLen = gRxMsgCtx.primaryGptSize+3;
            break;
        case TEST_WRITEGPT_INVGPTID:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_writeGPT: TEST_WRITEGPT_INVGPTID\r\n");
            g_SAILUPdaterTestCtx.TxMsg.readGpt.id = SAIL_UPD_GPT_ID_MAX;
            break;
        default:
            xRetStatus = MODULE_TEST_FAILED;
            return xRetStatus;
    }

    /* Send Message and Receive response*/
    xRetStatus = vSAILUpdaterTestSendReceiveMessage(&g_SAILUPdaterTestCtx.TxMsg);
    if(MODULE_TEST_PASSED == xRetStatus)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_writeGPT: Sent-Receive Done\r\n");
    }
    else
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_writeGPT: Sent/Receive Failed\r\n");
        return xRetStatus;
    }

    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.msgId != SAIL_UPD_MSG_ID_WRITE_GPT)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_writeGPT: Response Failure with Invalid MsgID\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.direction != SAIL_UPD_SAIL2MD)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_writeGPT: Response Failure with Invalid direction\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_writeGPT: Status %d\r\n",g_SAILUPdaterTestCtx.RxMsg.status);
    switch (testID)
    {
        case TEST_WRITEGPT:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_STATUS_SUCCESS)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_writeGPT: Response Success\r\n\n");
             xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_writeGPT: Response Failure\r\n\n");
               xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_WRITEGPT_INVBUFADDR:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_BUF_ADDR)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_writeGPT: Response Success SAIL_UPDATER_INVALID_BUF_ADDR\r\n\n");
             xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_writeGPT: Response Failure expected SAIL_UPDATER_INVALID_BUF_ADDR\r\n\n");
               xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_WRITEGPT_INVBUFSZ:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_BUF_SIZE)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_writeGPT: Response Success SAIL_UPDATER_INVALID_BUF_SIZE\r\n\n");
             xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_writeGPT: Response Failure expected SAIL_UPDATER_INVALID_BUF_SIZE\r\n\n");
               xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_WRITEGPT_UNALGNBUFSZ:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_UNALIGNED_BUF_SIZE)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_writeGPT: Response Success SAIL_UPDATER_UNALIGNED_BUF_SIZE\r\n\n");
             xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_writeGPT: Response Failure expected SAIL_UPDATER_UNALIGNED_BUF_SIZE\r\n\n");
               xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_WRITEGPT_INVGPTID:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_GPT_ID)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_writeGPT: Response Success SAIL_UPDATER_INVALID_GPT_ID\r\n\n");
             xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_writeGPT: Response Failure expected SAIL_UPDATER_INVALID_GPT_ID\r\n\n");
               xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        default:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_writeGPT: Invalid Test ID\r\n\n");
            xRetStatus = MODULE_TEST_FAILED;
            break;
        }
    return xRetStatus;
}


/*----------------------------------------------------------------------------
* sail_updater: update GPT
*
* @param sailUpdTestCaseIDType testID[IN]
*
* @return TESTerrorType_e [OUT]
*   Status of the operation MODULE_TEST_FAILED/MODULE_TEST_SUCCESS.
*
*--------------------------------------------------------------------------*/
TEST_FUNC TESTerrorType_e TC_SailUpdater_updateGPT(sailUpdTestCaseIDType testID)
{
    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    uint32_t sz = (uint32_t)sizeof(sailUpdaterMsgHeaderType);
    uint32_t size=0, bufLen=0,memscpyRet =0,bufAddr=0;
    size = 1*sizeof(sailUpdaterMsgUpdateGptEntryType);
    bufLen = ((1*sizeof(sailUpdaterMsgUpdateGptEntryType))+(24*1024));
    sailUpdaterMsgUpdateGptEntryType *pGptEntryType = NULL;
    ChipInfoIdType chipid;

    chipid = ChipInfo_GetChipId();
    if((CHIPINFO_ID_SA_MONACOAU_SRV1L == chipid) || (CHIPINFO_ID_SA_MONACOAU_SRV1L_FFC == chipid) || (CHIPINFO_ID_SA_LEMANSAU_ADAS == chipid))
    {
        pGptEntryType = (sailUpdaterMsgUpdateGptEntryType *)SAIL_VA_ADDR_SRV1;
    }
    else
    {
        pGptEntryType = (sailUpdaterMsgUpdateGptEntryType *)SAIL_VA_ADDR;
    }


    if(NULL == pGptEntryType)
    {
         DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_updateGPT pGptEntryType NULL\n\r");
         return MODULE_TEST_FAILED;
    }

    memscpyRet = sailbsp_memscpy(&pGptEntryType->imgName[0], SAIL_UPD_IMG_NAME_LEN,SAIL_UPD_IMG_NAME_SW1,strlen(SAIL_UPD_IMG_NAME_SW1)+1);
    if(memscpyRet == 0)
    {
         xRetStatus = MODULE_TEST_FAILED;
         DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_updateGPT: Image name copy failed\r\n");
         return xRetStatus;
    }
    /* Image partition swapping type: 0 - A and B offset swapping, other value are reserved */
    pGptEntryType->partitionSwapType = 0;

    /* reset msg */
    (void)memset((void*)&(g_SAILUPdaterTestCtx.TxMsg), 0, sz);
    (void)memset((void*)&(g_SAILUPdaterTestCtx.RxMsg), 0, sz);


    /* parse & pack msg */
    g_SAILUPdaterTestCtx.TxMsg.msgId      = SAIL_UPD_MSG_ID_UPDATE_GPT;
    g_SAILUPdaterTestCtx.TxMsg.status     = SAIL_UPD_STATUS_SUCCESS;
    g_SAILUPdaterTestCtx.TxMsg.updateGpt.id     = 0;
    g_SAILUPdaterTestCtx.TxMsg.updateGpt.num    = 1;//numPartition;
    g_SAILUPdaterTestCtx.TxMsg.updateGpt.bufAddr= MD_VA_ADDR;
    g_SAILUPdaterTestCtx.TxMsg.updateGpt.bufLen = bufLen;
    bufAddr = g_SAILUPdaterTestCtx.TxMsg.updateGpt.bufAddr-SAIL_ADDR_DIFF;

    g_SAILUPdaterTestCtx.TxMsg.updateGpt.bufCrc = ulAutosarCrcBufList(AUTOSAR_CRC_32BIT_ETHERNET, &bufAddr, &size, 1);

   switch (testID)
    {
        case TEST_UPDGPT:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_updateGPT: TEST_UPDGPT\r\n");
            break;
        case TEST_UPDGPT_INVBUFADDR:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_updateGPT: TEST_UPDGPT_INVBUFADDR\r\n");
            g_SAILUPdaterTestCtx.TxMsg.updateGpt.bufAddr = 0U;
            break;
        case TEST_UPDGPT_INVBUFSZ:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_updateGPT: TEST_UPDGPT_INVBUFSZ\r\n");
            g_SAILUPdaterTestCtx.TxMsg.updateGpt.bufLen = size-1;
            break;
        case TEST_UPDGPT_INVBUFCRC:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_updateGPT: TEST_UPDGPT_INVBUFCRC\r\n");
            g_SAILUPdaterTestCtx.TxMsg.updateGpt.bufCrc = 0;
            break;
        case TEST_UPDGPT_INVNUMIMG:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_updateGPT: TEST_UPDGPT_INVNUMIMG\r\n");
            g_SAILUPdaterTestCtx.TxMsg.updateGpt.num   = 6;
            break;
        default:
            xRetStatus = MODULE_TEST_FAILED;
            return xRetStatus;
    }

    /* Send Message and Receive response*/
    xRetStatus = vSAILUpdaterTestSendReceiveMessage(&g_SAILUPdaterTestCtx.TxMsg);
    if(MODULE_TEST_PASSED == xRetStatus)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_updateGPT: Sent-Receive Done\r\n");
    }
    else
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_updateGPT: Sent/Receive Failed\r\n");
        return xRetStatus;
    }
    DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_updateGPT: Rx Status %d\r\n", g_SAILUPdaterTestCtx.RxMsg.status);
    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.msgId != SAIL_UPD_MSG_ID_UPDATE_GPT)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_updateGPT: Response Failure with Invalid MsgID\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.direction != SAIL_UPD_SAIL2MD)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_updateGPT: Response Failure with Invalid direction\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    switch (testID)
    {
        case TEST_UPDGPT:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_STATUS_SUCCESS)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_updateGPT: Response Success\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_updateGPT: Response Failure\r\n\n");
               xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_UPDGPT_INVBUFADDR:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_BUF_ADDR)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_updateGPT: Response Success SAIL_UPDATER_INVALID_BUF_ADDR\r\n\n");
             xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_updateGPT: Response Failure expected SAIL_UPDATER_INVALID_BUF_ADDR\r\n\n");
               xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_UPDGPT_INVBUFSZ:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_BUF_SIZE)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_updateGPT: Response Success SAIL_UPDATER_INVALID_BUF_SIZE\r\n\n");
             xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_updateGPT: Response Failure expected SAIL_UPDATER_INVALID_BUF_SIZE\r\n\n");
               xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_UPDGPT_INVNUMIMG:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_NUM_OF_IMAGES)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_updateGPT: Response Success SAIL_UPDATER_INVALID_NUM_OF_IMAGES\r\n\n");
             xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_updateGPT: Response Failure expected SAIL_UPDATER_INVALID_NUM_OF_IMAGES\r\n\n");
               xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_UPDGPT_INVBUFCRC:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_BUF_CRC)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_updateGPT: Response Success SAIL_UPDATER_INVALID_BUF_CRC\r\n\n");
             xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_updateGPT: Response Failure expected SAIL_UPDATER_INVALID_BUF_CRC\r\n\n");
               xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        default:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_updateGPT: Invalid Test ID\r\n\n");
            xRetStatus = MODULE_TEST_FAILED;
            break;
        }
    return xRetStatus;
}

/*----------------------------------------------------------------------------
* sail_updater: GetMetaDataInfo
*
* @param sailUpdTestCaseIDType testID[IN]
*
* @return TESTerrorType_e [OUT]
*   Status of the operation MODULE_TEST_FAILED/MODULE_TEST_SUCCESS.
*
*--------------------------------------------------------------------------*/
TEST_FUNC TESTerrorType_e TC_SailUpdater_getMetaDataInfo(sailUpdTestCaseIDType testID)
{
    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    uint32_t sz = (uint32_t)sizeof(sailUpdaterMsgHeaderType);
    /* reset msg */
    (void)memset((void*)&(g_SAILUPdaterTestCtx.TxMsg), 0, sz);
    (void)memset((void*)&(g_SAILUPdaterTestCtx.RxMsg), 0, sz);

    if(testID != TEST_GETOTAMETADATAINFO)
    {
        return xRetStatus;
    }

    /* parse & pack msg */
    g_SAILUPdaterTestCtx.TxMsg.msgId      = SAIL_UPD_MSG_GET_OTA_METADATAINFO;
    g_SAILUPdaterTestCtx.TxMsg.status     = SAIL_UPD_STATUS_SUCCESS;

    /* Send Message and Receive response*/
    xRetStatus = vSAILUpdaterTestSendReceiveMessage(&g_SAILUPdaterTestCtx.TxMsg);
    if(MODULE_TEST_PASSED == xRetStatus)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getMetaDataInfo: Sent-Receive Done\r\n");
    }
    else
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getMetaDataInfo: Sent/Receive Failed\r\n");
        return xRetStatus;
    }

    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.msgId != SAIL_UPD_MSG_GET_OTA_METADATAINFO)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getMetaDataInfo: Response Failure with Invalid MsgID\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.direction != SAIL_UPD_SAIL2MD)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getMetaDataInfo: Response Failure with Invalid direction\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_STATUS_SUCCESS)
    {
        gRxMsgCtx.metadataSize_KB = g_SAILUPdaterTestCtx.RxMsg.getMetaDataInfo.partition_size;
        sailbsp_memscpy(gRxMsgCtx.sectorMap, sizeof(gRxMsgCtx.sectorMap), g_SAILUPdaterTestCtx.RxMsg.getMetaDataInfo.sectorMap, sizeof(gRxMsgCtx.sectorMap));
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getMetaDataInfo: Response Success\r\n\n");
        xRetStatus = MODULE_TEST_PASSED;
    }
    else
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getMetaDataInfo: Response Failure\r\n\n");
        xRetStatus = MODULE_TEST_FAILED;
    }
    return xRetStatus;
}

/*----------------------------------------------------------------------------
* sail_updater: get OTA MetaData
*
* @param sailUpdTestCaseIDType testID[IN]
*
* @return TESTerrorType_e [OUT]
*   Status of the operation MODULE_TEST_FAILED/MODULE_TEST_SUCCESS.
*
*--------------------------------------------------------------------------*/
TEST_FUNC TESTerrorType_e TC_SailUpdater_getOtaMetaData(sailUpdTestCaseIDType testID)
{
    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    uint32_t sz = (uint32_t)sizeof(sailUpdaterMsgHeaderType);
    /* reset msg */
    (void)memset((void*)&(g_SAILUPdaterTestCtx.TxMsg), 0, sz);
    (void)memset((void*)&(g_SAILUPdaterTestCtx.RxMsg), 0, sz);

    /* parse & pack msg */
    g_SAILUPdaterTestCtx.TxMsg.msgId      = SAIL_UPD_MSG_ID_GET_OTA_METADATA;
    g_SAILUPdaterTestCtx.TxMsg.status     = SAIL_UPD_STATUS_SUCCESS;
    g_SAILUPdaterTestCtx.TxMsg.getMetaData.bufAddr = MD_VA_ADDR;
    g_SAILUPdaterTestCtx.TxMsg.getMetaData.bufLen = gRxMsgCtx.metadataSize_KB*1024;
    g_SAILUPdaterTestCtx.TxMsg.getMetaData.bufCrc = 0;

    switch (testID)
    {
        case TEST_GETOTAMETADATA:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getOtaMetaData: TEST_GETOTAMETADATA\r\n");
            break;
        case TEST_GETOTAMETADATA_INVADDR:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getOtaMetaData: TEST_GETOTAMETADATA_INVADDR\r\n");
            g_SAILUPdaterTestCtx.TxMsg.getMetaData.bufAddr = 0U;
            break;
        case TEST_GETOTAMETADATA_INVBUFSZ:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getOtaMetaData: TEST_GETOTAMETADATA_INVBUFSZ\r\n");
            g_SAILUPdaterTestCtx.TxMsg.getMetaData.bufLen = MAX_INV_LEN;
            break;
        case TEST_GETOTAMETADATA_UNALGNBUFSZ:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getOtaMetaData: TEST_GETOTAMETADATA_UNALGNBUFSZ\r\n");
            g_SAILUPdaterTestCtx.TxMsg.getMetaData.bufLen = gRxMsgCtx.metadataSize_KB*1024-3;
            break;
        default:
            xRetStatus = MODULE_TEST_FAILED;
            return xRetStatus;
    }

    /* Send Message and Receive response*/
    xRetStatus = vSAILUpdaterTestSendReceiveMessage(&g_SAILUPdaterTestCtx.TxMsg);
    if(MODULE_TEST_PASSED == xRetStatus)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getOtaMetaData: Sent-Receive Done\r\n");
    }
    else
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getOtaMetaData: Sent/Receive Failed\r\n");
        return xRetStatus;
    }

    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.msgId != SAIL_UPD_MSG_ID_GET_OTA_METADATA)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getOtaMetaData: Response Failure with Invalid MsgID\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.direction != SAIL_UPD_SAIL2MD)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getOtaMetaData: Response Failure with Invalid direction\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getOtaMetaData: Response Value %d\r\n",g_SAILUPdaterTestCtx.RxMsg.status);
    switch (testID)
    {
        case TEST_GETOTAMETADATA:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_STATUS_SUCCESS)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getOtaMetaData: Response Success\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getOtaMetaData: Response Failure\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_GETOTAMETADATA_INVADDR:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_BUF_ADDR)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getOtaMetaData: Response Success Invalid Buffer Address\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getOtaMetaData: Response Failure, expected Invalid Buffer Address response\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_GETOTAMETADATA_INVBUFSZ:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_BUF_SIZE)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getOtaMetaData: Response Success Invalid Buffer Size\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getOtaMetaData: Response Failure, expected Invalid Buffer Size response\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_GETOTAMETADATA_UNALGNBUFSZ:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_UNALIGNED_BUF_SIZE)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getOtaMetaData: Response Success Unalligned Buffer Size\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getOtaMetaData: Response Failure, expected Unalligned Buffer Size response\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        default:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getOtaMetaData: Invalid Test ID\r\n\n");
            xRetStatus = MODULE_TEST_FAILED;
            break;
    }
    return xRetStatus;
}

/*----------------------------------------------------------------------------
* sail_updater: set OTA MetaData
*
* @param sailUpdTestCaseIDType testID[IN]
*
* @return TESTerrorType_e [OUT]
*   Status of the operation MODULE_TEST_FAILED/MODULE_TEST_SUCCESS.
*
*--------------------------------------------------------------------------*/
TEST_FUNC TESTerrorType_e TC_SailUpdater_setOtaMetaData(sailUpdTestCaseIDType testID)
{
    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    uint32_t sz = (uint32_t)sizeof(sailUpdaterMsgHeaderType);
    uint32_t bufAddr = 0, bufLen =0;
    /* reset msg */
    (void)memset((void*)&(g_SAILUPdaterTestCtx.TxMsg), 0, sz);
    (void)memset((void*)&(g_SAILUPdaterTestCtx.RxMsg), 0, sz);

    /* parse & pack msg */
    g_SAILUPdaterTestCtx.TxMsg.msgId      = SAIL_UPD_MSG_ID_SET_OTA_METADATA;
    g_SAILUPdaterTestCtx.TxMsg.status     = SAIL_UPD_STATUS_SUCCESS;
    g_SAILUPdaterTestCtx.TxMsg.setMetaData.bufAddr = MD_VA_ADDR;
    g_SAILUPdaterTestCtx.TxMsg.setMetaData.bufLen = gRxMsgCtx.metadataSize_KB*1024;
    g_SAILUPdaterTestCtx.TxMsg.setMetaData.bufCrc = 0;
    bufAddr = g_SAILUPdaterTestCtx.TxMsg.setMetaData.bufAddr -SAIL_ADDR_DIFF;
    bufLen = g_SAILUPdaterTestCtx.TxMsg.setMetaData.bufLen;
    g_SAILUPdaterTestCtx.TxMsg.setMetaData.bufCrc = ulAutosarCrcBufList(AUTOSAR_CRC_32BIT_ETHERNET, &bufAddr, &bufLen, 1);

    switch (testID)
    {
        case TEST_SETOTAMETADATA:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_setOtaMetaData: TEST_SETOTAMETADATA\r\n");
            break;
        case TEST_SETOTAMETADATA_INVADDR:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_setOtaMetaData: TEST_SETOTAMETADATA_INVADDR\r\n");
            g_SAILUPdaterTestCtx.TxMsg.setMetaData.bufAddr = 0U;
            break;
        case TEST_SETOTAMETADATA_INVBUFSZ:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_setOtaMetaData: TEST_SETOTAMETADATA_INVBUFSZ\r\n");
            g_SAILUPdaterTestCtx.TxMsg.setMetaData.bufLen = MAX_INV_LEN;
            break;
        case TEST_SETOTAMETADATA_UNALGNBUFSZ:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_setOtaMetaData: TEST_SETOTAMETADATA_UNALGNBUFSZ\r\n");
            g_SAILUPdaterTestCtx.TxMsg.setMetaData.bufLen = gRxMsgCtx.primaryGptSize+3;
            break;
        case TEST_SETOTAMETADATA_INVBUFCRC:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_setOtaMetaData: TEST_SETOTAMETADATA_INVBUFCRC\r\n");
            g_SAILUPdaterTestCtx.TxMsg.setMetaData.bufCrc = 0;
            break;
        default:
            xRetStatus = MODULE_TEST_FAILED;
            return xRetStatus;
    }

    /* Send Message and Receive response*/
    xRetStatus = vSAILUpdaterTestSendReceiveMessage(&g_SAILUPdaterTestCtx.TxMsg);
    if(MODULE_TEST_PASSED == xRetStatus)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_setOtaMetaData: Sent-Receive Done\r\n");
    }
    else
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_setOtaMetaData: Sent/Receive Failed\r\n");
        return xRetStatus;
    }

    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.msgId != SAIL_UPD_MSG_ID_SET_OTA_METADATA)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_setOtaMetaData: Response Failure with Invalid MsgID\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.direction != SAIL_UPD_SAIL2MD)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_setOtaMetaData: Response Failure with Invalid direction\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_setOtaMetaData: Response Value %d\r\n",g_SAILUPdaterTestCtx.RxMsg.status);
    switch (testID)
    {
        case TEST_SETOTAMETADATA:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_STATUS_SUCCESS)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_setOtaMetaData: Response Success\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_setOtaMetaData: Response Failure\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_SETOTAMETADATA_INVADDR:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_BUF_ADDR)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_setOtaMetaData: Response Success Invalid Buffer Address\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_setOtaMetaData: Response Failure, expected Invalid Buffer Address response\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_SETOTAMETADATA_INVBUFSZ:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_BUF_SIZE)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_setOtaMetaData: Response Success Invalid Buffer Size\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_setOtaMetaData: Response Failure, expected Invalid Buffer Size response\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_SETOTAMETADATA_UNALGNBUFSZ:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_UNALIGNED_BUF_SIZE)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_setOtaMetaData: Response Success Unalligned Buffer Size\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_setOtaMetaData: Response Failure, expected Unalligned Buffer Size response\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_SETOTAMETADATA_INVBUFCRC:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_BUF_CRC)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_setOtaMetaData: Response Success invalid Buffer CRC\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_setOtaMetaData: Response Failure, expected invalid Buffer CRC response\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        default:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_setOtaMetaData: Invalid Test ID\r\n\n");
            xRetStatus = MODULE_TEST_FAILED;
            break;
    }
    return xRetStatus;
}

/*----------------------------------------------------------------------------
* sail_updater: get Boot Info
*
* @param sailUpdTestCaseIDType testID[IN]
*
* @return TESTerrorType_e [OUT]
*   Status of the operation MODULE_TEST_FAILED/MODULE_TEST_SUCCESS.
*
*--------------------------------------------------------------------------*/
TEST_FUNC TESTerrorType_e TC_SailUpdater_getBootInfo(sailUpdTestCaseIDType testID)
{
    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    uint32_t memscpyRet = 0, bufAddr =0, bufLen =0, bootPartStatus = 0;;
    uint32_t sz = (uint32_t)sizeof(sailUpdaterMsgHeaderType);

    /* reset msg */
    (void)memset((void*)&(g_SAILUPdaterTestCtx.TxMsg), 0, sz);
    (void)memset((void*)&(g_SAILUPdaterTestCtx.RxMsg), 0, sz);

    sailUpdaterImageEntryType *pUpdImgEntryType = NULL;
    ChipInfoIdType chipid;

    chipid = ChipInfo_GetChipId();
    if((CHIPINFO_ID_SA_MONACOAU_SRV1L == chipid) || (CHIPINFO_ID_SA_MONACOAU_SRV1L_FFC == chipid) || (CHIPINFO_ID_SA_LEMANSAU_ADAS == chipid))
    {
        pUpdImgEntryType = (sailUpdaterImageEntryType *)SAIL_VA_ADDR_SRV1;
    }
    else
    {
        pUpdImgEntryType = (sailUpdaterImageEntryType *)SAIL_VA_ADDR;
    }


    if(NULL == pUpdImgEntryType)
    {
         DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo pUpdImgEntryType NULL\n\r");
         return MODULE_TEST_FAILED;
    }

    for(uint32_t k =0; k<MAX_IMAGES; k++)
    {
        switch(k)
        {
            case 0:
                memscpyRet = sailbsp_memscpy(&pUpdImgEntryType->imgName[0], SAIL_UPD_IMG_NAME_LEN,SAIL_UPD_IMG_NAME_HYP,strlen(SAIL_UPD_IMG_NAME_HYP)+1);
                break;
            case 1:
                memscpyRet = sailbsp_memscpy(&pUpdImgEntryType->imgName[0], SAIL_UPD_IMG_NAME_LEN,SAIL_UPD_IMG_NAME_SW1,strlen(SAIL_UPD_IMG_NAME_SW1)+1);
                break;
            case 2:
                memscpyRet = sailbsp_memscpy(&pUpdImgEntryType->imgName[0], SAIL_UPD_IMG_NAME_LEN,SAIL_UPD_IMG_NAME_SW2,strlen(SAIL_UPD_IMG_NAME_SW2)+1);
                break;
            case 3:
                memscpyRet = sailbsp_memscpy(&pUpdImgEntryType->imgName[0], SAIL_UPD_IMG_NAME_LEN,SAIL_UPD_IMG_NAME_SW3,strlen(SAIL_UPD_IMG_NAME_SW3)+1);
                break;
            case 4:
                memscpyRet = sailbsp_memscpy(&pUpdImgEntryType->imgName[0], SAIL_UPD_IMG_NAME_LEN,SAIL_UPD_IMG_NAME_SW4,strlen(SAIL_UPD_IMG_NAME_SW4)+1);
                break;
        }
        if(memscpyRet == 0)
        {
            xRetStatus = MODULE_TEST_FAILED;
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo: Image name copy failed\r\n");
            return xRetStatus;
        }
        pUpdImgEntryType++;
    }

    /* parse & pack msg */
    g_SAILUPdaterTestCtx.TxMsg.msgId      = SAIL_UPD_MSG_ID_GET_BOOTINFO;
    g_SAILUPdaterTestCtx.TxMsg.status     = SAIL_UPD_STATUS_SUCCESS;
    g_SAILUPdaterTestCtx.TxMsg.bootInfo.imgInfo.num_images = 5;
    g_SAILUPdaterTestCtx.TxMsg.bootInfo.imgInfo.bufAddr = MD_VA_ADDR;
    g_SAILUPdaterTestCtx.TxMsg.bootInfo.imgInfo.bufLen = g_SAILUPdaterTestCtx.TxMsg.bootInfo.imgInfo.num_images*sizeof(sailUpdaterImageEntryType);
    bufAddr = g_SAILUPdaterTestCtx.TxMsg.bootInfo.imgInfo.bufAddr-SAIL_ADDR_DIFF;
    bufLen = g_SAILUPdaterTestCtx.TxMsg.bootInfo.imgInfo.bufLen;
    g_SAILUPdaterTestCtx.TxMsg.bootInfo.imgInfo.bufCrc = ulAutosarCrcBufList(AUTOSAR_CRC_32BIT_ETHERNET, &bufAddr, &bufLen, 1);

    switch (testID)
    {
        case TEST_GETBOOTINFO:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo: TEST_GETBOOTINFO\r\n");
            break;
        case TEST_GETBOOTINFO_INVNUMIMG:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo: TEST_GETBOOTINFO_INVNUMIMG\r\n");
            g_SAILUPdaterTestCtx.TxMsg.bootInfo.imgInfo.num_images = 6;
            break;
        case TEST_GETBOOTINFO_INVBUFADDR:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo: TEST_GETBOOTINFO_INVBUFADDR\r\n");
            g_SAILUPdaterTestCtx.TxMsg.bootInfo.imgInfo.bufAddr = 0U;
            break;
        case TEST_GETBOOTINFO_INVBUFSZ:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo: TEST_GETBOOTINFO_INVBUFSZ\r\n");
            g_SAILUPdaterTestCtx.TxMsg.bootInfo.imgInfo.bufLen = (g_SAILUPdaterTestCtx.TxMsg.bootInfo.imgInfo.num_images*sizeof(sailUpdaterImageEntryType))-16;
            break;
        case TEST_GETBOOTINFO_INVBUFCRC:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo: TEST_GETBOOTINFO_INVBUFCRC\r\n");
            g_SAILUPdaterTestCtx.TxMsg.bootInfo.imgInfo.bufCrc = 0;
            break;
        case TEST_GETBOOTINFO_INVIMGNAME:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo: TEST_GETBOOTINFO_INVIMGNAME\r\n");
            if((CHIPINFO_ID_SA_MONACOAU_SRV1L == chipid) || (CHIPINFO_ID_SA_MONACOAU_SRV1L_FFC == chipid) || (CHIPINFO_ID_SA_LEMANSAU_ADAS == chipid))
            {
                pUpdImgEntryType = (sailUpdaterImageEntryType *)SAIL_VA_ADDR_SRV1;
            }
            else
            {
                pUpdImgEntryType = (sailUpdaterImageEntryType *)SAIL_VA_ADDR;
            }

            memscpyRet = sailbsp_memscpy(&pUpdImgEntryType->imgName[0], SAIL_UPD_IMG_NAME_LEN,SAIL_UPD_IMG_NAME_INV,strlen(SAIL_UPD_IMG_NAME_INV)+1);
            if(memscpyRet == 0)
            {
                xRetStatus = MODULE_TEST_FAILED;
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo: Invalid Image name copy failed\r\n");
                return xRetStatus;
            }
            g_SAILUPdaterTestCtx.TxMsg.bootInfo.imgInfo.bufCrc = ulAutosarCrcBufList(AUTOSAR_CRC_32BIT_ETHERNET, &bufAddr, &bufLen, 1);
            break;
        default:
            xRetStatus = MODULE_TEST_FAILED;
            return xRetStatus;
    }

    /* Send Message and Receive response*/
    xRetStatus = vSAILUpdaterTestSendReceiveMessage(&g_SAILUPdaterTestCtx.TxMsg);
    if(MODULE_TEST_PASSED == xRetStatus)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo: Sent-Receive Done\r\n");
    }
    else
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo: Sent/Receive Failed\r\n");
        return xRetStatus;
    }

    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.msgId != SAIL_UPD_MSG_ID_GET_BOOTINFO)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo: Response Failure with Invalid MsgID\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.direction != SAIL_UPD_SAIL2MD)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo: Response Failure with Invalid direction\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo: Response Value %d\r\n",g_SAILUPdaterTestCtx.RxMsg.status);
    switch (testID)
    {
        case TEST_GETBOOTINFO:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_STATUS_SUCCESS)
            {
                gRxMsgCtx.blInfoNumImagesBoot = g_SAILUPdaterTestCtx.RxMsg.bootInfo.imgInfo.num_images;
                gRxMsgCtx.blInfoSailAddr = g_SAILUPdaterTestCtx.RxMsg.bootInfo.imgInfo.bufAddr- SAIL_ADDR_DIFF;
                pUpdImgEntryType = (sailUpdaterImageEntryType  *)gRxMsgCtx.blInfoSailAddr;
                if(NULL == pUpdImgEntryType)
                {
                    DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo Resp pUpdImgEntryType NULL\n\r");
                    return MODULE_TEST_FAILED;
                }
                for(int k = 0; k < g_SAILUPdaterTestCtx.RxMsg.bootInfo.imgInfo.num_images; k++)
                {
                    memscpyRet = sailbsp_memscpy(&gRxMsgCtx.updImgEntryType[k].imgName[0],SAIL_UPD_IMG_NAME_LEN,pUpdImgEntryType->imgName,SAIL_UPD_IMG_NAME_LEN);
                    if(memscpyRet == 0)
                    {
                        xRetStatus = MODULE_TEST_FAILED;
                        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo: Response Image name copy failed\r\n");
                        return xRetStatus;
                    }
                    gRxMsgCtx.updImgEntryType[k].bootGptId = pUpdImgEntryType->bootGptId;
                    gRxMsgCtx.updImgEntryType[k].bootPartition = pUpdImgEntryType->bootPartition;
                    gRxMsgCtx.updImgEntryType[k].partitionSizeA = pUpdImgEntryType->partitionSizeA;
                    gRxMsgCtx.updImgEntryType[k].partitionSizeB = pUpdImgEntryType->partitionSizeB;
                    gRxMsgCtx.updImgEntryType[k].isTwoGptTableEntriesMatching = pUpdImgEntryType->isTwoGptTableEntriesMatching;
                    DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo: Img Name: %s bufAddr: 0x%x bootGPT %d bootPartition %d partSizeA 0x%x partSizeB 0x%x isTwoGptTableEntriesMatching %d\n\r",
                        pUpdImgEntryType->imgName,g_SAILUPdaterTestCtx.RxMsg.bootInfo.imgInfo.bufAddr,pUpdImgEntryType->bootGptId,pUpdImgEntryType->bootPartition,pUpdImgEntryType->partitionSizeA,pUpdImgEntryType->partitionSizeB, pUpdImgEntryType->isTwoGptTableEntriesMatching);
                    if(strncmp((void *)&gRxMsgCtx.updImgEntryType[k].imgName[0],SAIL_UPD_IMG_NAME_SW4, strlen(SAIL_UPD_IMG_NAME_SW4)) == 0)
                    {
                         DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo: SAILSW4 boot partition check not needed\r\n");
                    }
                    else
                    {
                        if(pUpdImgEntryType->bootPartition != 0)
                        {
                            bootPartStatus++;
                        }
                    }
                    pUpdImgEntryType++;
                }
                if (g_SAILUPdaterTestCtx.RxMsg.bootInfo.primaryGptHeaderCrcStatus == 1 &&
                g_SAILUPdaterTestCtx.RxMsg.bootInfo.primaryGptEntryCrcStatus == 1 &&
                g_SAILUPdaterTestCtx.RxMsg.bootInfo.secondaryGptHeaderCrcStatus == 1 &&
                g_SAILUPdaterTestCtx.RxMsg.bootInfo.secondaryGptEntryCrcStatus == 1)
                {
                    if(bootPartStatus == 0)
                    {
                        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo: Response Success\r\n\n");
                        xRetStatus = MODULE_TEST_PASSED;
                    }
                    else
                    {
                        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo: Response Success BUT Boot Partition is Wrong!!\r\n\n");
                        xRetStatus = MODULE_TEST_FAILED;
                    }
                }
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo: Response Failure\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_GETBOOTINFO_INVNUMIMG:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_NUM_OF_IMAGES)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo: Response Success Invalid Number of images\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo: Response Failure, expected Invalid Num Images response\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_GETBOOTINFO_INVBUFADDR:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_BUF_ADDR)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo: Response Success Invalid Buffer Address\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo: Response Failure, expected Invalid Buffer Address response\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_GETBOOTINFO_INVBUFSZ:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_BUF_SIZE)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo: Response Success Invalid Buffer Size\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo: Response Failure, expected Invalid Buffer Size response\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_GETBOOTINFO_INVBUFCRC:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_BUF_CRC)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo: Response Success Invalid Buffer CRC\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo: Response Failure, expected Invalid Buffer CRC response\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_GETBOOTINFO_INVIMGNAME:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_IMG_NAME)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo: Response Success SAIL_UPDATER_INVALID_IMG_NAME\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo: Response Failure, expected SAIL_UPDATER_INVALID_IMG_NAME\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;

        default:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_getBootInfo: Invalid Test ID\r\n\n");
            xRetStatus = MODULE_TEST_FAILED;
            break;
    }
    return xRetStatus;
}

/*----------------------------------------------------------------------------
* sail_updater: query image
*
* @param sailUpdTestCaseIDType testID[IN]
*
* @return TESTerrorType_e [OUT]
*   Status of the operation MODULE_TEST_FAILED/MODULE_TEST_SUCCESS.
*
*--------------------------------------------------------------------------*/
TEST_FUNC TESTerrorType_e TC_SailUpdater_queryImg(sailUpdTestCaseIDType testID)
{
    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    uint32_t memscpyRet = 0, bufAddr =0, bufLen =0, bootPartStatus = 0;;
    uint32_t sz = (uint32_t)sizeof(sailUpdaterMsgHeaderType);

    /* reset msg */
    (void)memset((void*)&(g_SAILUPdaterTestCtx.TxMsg), 0, sz);
    (void)memset((void*)&(g_SAILUPdaterTestCtx.RxMsg), 0, sz);

    sailUpdaterImageEntryType *pUpdImgEntryType = NULL;
    ChipInfoIdType chipid;

    chipid = ChipInfo_GetChipId();
    if((CHIPINFO_ID_SA_MONACOAU_SRV1L == chipid) || (CHIPINFO_ID_SA_MONACOAU_SRV1L_FFC == chipid) || (CHIPINFO_ID_SA_LEMANSAU_ADAS == chipid))
    {
        pUpdImgEntryType = (sailUpdaterImageEntryType *)SAIL_VA_ADDR_SRV1;
    }
    else
    {
        pUpdImgEntryType = (sailUpdaterImageEntryType *)SAIL_VA_ADDR;
    }


    if(NULL == pUpdImgEntryType)
    {
         DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_queryImg pUpdImgEntryType NULL\n\r");
         return MODULE_TEST_FAILED;
    }

    memscpyRet = sailbsp_memscpy(&pUpdImgEntryType->imgName[0], SAIL_UPD_IMG_NAME_LEN,SAIL_UPD_IMG_NAME_SW1,strlen(SAIL_UPD_IMG_NAME_SW1)+1);
    if(memscpyRet == 0)
    {
         xRetStatus = MODULE_TEST_FAILED;
         DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_queryImg: Image name copy failed\r\n");
         return xRetStatus;
    }

    /* parse & pack msg */
    g_SAILUPdaterTestCtx.TxMsg.msgId      = SAIL_UPD_MSG_ID_QUERY_IMAGES;
    g_SAILUPdaterTestCtx.TxMsg.status     = SAIL_UPD_STATUS_SUCCESS;
    g_SAILUPdaterTestCtx.TxMsg.queryImg.num_images = 1;
    g_SAILUPdaterTestCtx.TxMsg.queryImg.bufAddr = MD_VA_ADDR;
    g_SAILUPdaterTestCtx.TxMsg.queryImg.bufLen = g_SAILUPdaterTestCtx.TxMsg.queryImg.num_images*sizeof(sailUpdaterImageEntryType);
    bufAddr = g_SAILUPdaterTestCtx.TxMsg.queryImg.bufAddr-SAIL_ADDR_DIFF;
    bufLen = g_SAILUPdaterTestCtx.TxMsg.queryImg.bufLen;
    g_SAILUPdaterTestCtx.TxMsg.queryImg.bufCrc = ulAutosarCrcBufList(AUTOSAR_CRC_32BIT_ETHERNET, &bufAddr, &bufLen, 1);

    switch (testID)
    {
        case TEST_QUERYIMG:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_queryImg: TEST_QUERYIMG\r\n");
            break;
        case TEST_QUERYIMG_INVNUMIMG:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_queryImg: TEST_QUERYIMG_INVNUMIMG\r\n");
            g_SAILUPdaterTestCtx.TxMsg.queryImg.num_images = 6;
            break;
        case TEST_QUERYIMG_INVBUFADDR:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_queryImg: TEST_QUERYIMG_INVBUFADDR\r\n");
            g_SAILUPdaterTestCtx.TxMsg.queryImg.bufAddr = 0U;
            break;
        case TEST_QUERYIMG_INVBUFSZ:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_queryImg: TEST_QUERYIMG_INVBUFSZ\r\n");
            g_SAILUPdaterTestCtx.TxMsg.queryImg.bufLen = (g_SAILUPdaterTestCtx.TxMsg.queryImg.num_images*sizeof(sailUpdaterImageEntryType))-16;
            break;
        case TEST_QUERYIMG_INVBUFCRC:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_queryImg: TEST_GETBOOTINFO_INVBUFCRC\r\n");
            g_SAILUPdaterTestCtx.TxMsg.queryImg.bufCrc = 0;
            break;
        case TEST_QUERYIMG_INVIMGNAME:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_queryImg: TEST_GETBOOTINFO_INVIMGNAME\r\n");
            memscpyRet = sailbsp_memscpy(&pUpdImgEntryType->imgName[0], SAIL_UPD_IMG_NAME_LEN,SAIL_UPD_IMG_NAME_INV,strlen(SAIL_UPD_IMG_NAME_INV)+1);
            if(memscpyRet == 0)
            {
               xRetStatus = MODULE_TEST_FAILED;
               DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_queryImg: Image name copy failed\r\n");
               return xRetStatus;
            }
            g_SAILUPdaterTestCtx.TxMsg.queryImg.bufCrc = ulAutosarCrcBufList(AUTOSAR_CRC_32BIT_ETHERNET, &bufAddr, &bufLen, 1);
            break;
        default:
            xRetStatus = MODULE_TEST_FAILED;
            return xRetStatus;
    }

    /* Send Message and Receive response*/
    xRetStatus = vSAILUpdaterTestSendReceiveMessage(&g_SAILUPdaterTestCtx.TxMsg);
    if(MODULE_TEST_PASSED == xRetStatus)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_queryImg: Sent-Receive Done\r\n");
    }
    else
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_queryImg: Sent/Receive Failed\r\n");
        return xRetStatus;
    }

    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.msgId != SAIL_UPD_MSG_ID_QUERY_IMAGES)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_queryImg: Response Failure with Invalid MsgID\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.direction != SAIL_UPD_SAIL2MD)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_queryImg: Response Failure with Invalid direction\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_queryImg: Response Value %d\r\n",g_SAILUPdaterTestCtx.RxMsg.status);
    switch (testID)
    {
        case TEST_QUERYIMG:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_STATUS_SUCCESS)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_queryImg: Response Success\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_queryImg: Response Failure\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_QUERYIMG_INVNUMIMG:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_NUM_OF_IMAGES)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_queryImg: Response Success Invalid Number of images\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_queryImg: Response Failure, expected Invalid Num Images response\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_QUERYIMG_INVBUFADDR:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_BUF_ADDR)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_queryImg: Response Success Invalid Buffer Address\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_queryImg: Response Failure, expected Invalid Buffer Address response\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_QUERYIMG_INVBUFSZ:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_BUF_SIZE)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_queryImg: Response Success Invalid Buffer Size\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_queryImg: Response Failure, expected Invalid Buffer Size response\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_QUERYIMG_INVBUFCRC:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_BUF_CRC)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_queryImg: Response Success Invalid Buffer CRC\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_queryImg: Response Failure, expected Invalid Buffer CRC response\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_QUERYIMG_INVIMGNAME:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_IMG_NAME)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_queryImg: Response Success SAIL_UPDATER_INVALID_IMG_NAME\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_queryImg: Response Failure, expected SAIL_UPDATER_INVALID_IMG_NAME\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        default:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_queryImg: Invalid Test ID\r\n\n");
            xRetStatus = MODULE_TEST_FAILED;
            break;
    }
    return xRetStatus;
}

/*----------------------------------------------------------------------------
* sail_updater: flash Image
*
* @param sailUpdTestCaseIDType testID[IN]
*
* @return TESTerrorType_e [OUT]
*   Status of the operation MODULE_TEST_FAILED/MODULE_TEST_SUCCESS.
*
*--------------------------------------------------------------------------*/
TEST_FUNC TESTerrorType_e TC_SailUpdater_flashImage(sailUpdTestCaseIDType testID, uint32_t restart, boolean ext_support)
{
    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    uint32_t memscpyRet = 0, bufAddr =0, bufLen =0;
    uint32_t sz = (uint32_t)sizeof(sailUpdaterMsgHeaderType);

    /* reset msg */
    (void)memset((void*)&(g_SAILUPdaterTestCtx.TxMsg), 0, sz);
    (void)memset((void*)&(g_SAILUPdaterTestCtx.RxMsg), 0, sz);

    memscpyRet = sailbsp_memscpy(&g_SAILUPdaterTestCtx.TxMsg.flashImg.imgName[0], SAIL_UPD_IMG_NAME_LEN,SAIL_UPD_IMG_NAME_SW1,strlen(SAIL_UPD_IMG_NAME_SW1)+1);
    if(memscpyRet == 0)
    {
         xRetStatus = MODULE_TEST_FAILED;
         DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_flashImage: Image name copy failed\r\n");
         return xRetStatus;
    }

    if (TRUE == ext_support)
    {
        if (0 == restart)
        {
            g_SAILUPdaterTestCtx.TxMsg.flashImg.ext_id.FlashPartition = 1;
            g_SAILUPdaterTestCtx.TxMsg.flashImg.ext_id.flashtype = 2;
        }
        else
        {
            g_SAILUPdaterTestCtx.TxMsg.flashImg.ext_id.FlashPartition = 1;
            g_SAILUPdaterTestCtx.TxMsg.flashImg.ext_id.flashtype = 1;
        }
    }
    else
    {
        g_SAILUPdaterTestCtx.TxMsg.flashImg.FlashPartition = 1;
    }

    /* parse & pack msg */
    g_SAILUPdaterTestCtx.TxMsg.msgId      = SAIL_UPD_MSG_ID_FLASH_IMAGE;
    g_SAILUPdaterTestCtx.TxMsg.status     = SAIL_UPD_STATUS_SUCCESS;
    g_SAILUPdaterTestCtx.TxMsg.flashImg.FlashGptId     = 0;
    g_SAILUPdaterTestCtx.TxMsg.flashImg.bufAddr        = gRxMsgCtx.rdImgBufAddr;
    g_SAILUPdaterTestCtx.TxMsg.flashImg.bufLen         = gRxMsgCtx.rdImgBufLen;
    bufAddr = g_SAILUPdaterTestCtx.TxMsg.flashImg.bufAddr-SAIL_ADDR_DIFF;
    bufLen = g_SAILUPdaterTestCtx.TxMsg.flashImg.bufLen;
    g_SAILUPdaterTestCtx.TxMsg.flashImg.bufCrc = ulAutosarCrcBufList(AUTOSAR_CRC_32BIT_ETHERNET, &bufAddr, &bufLen, 1);

    switch (testID)
    {
        case TEST_FLASHIMG:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_flashImage: TEST_FLSHIMG\r\n");
            break;
        case TEST_FLASHIMG_INVIMGNAME:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_flashImage: TEST_FLSHIMG_INVIMGNAME\r\n");
            memscpyRet = sailbsp_memscpy(&g_SAILUPdaterTestCtx.TxMsg.flashImg.imgName[0], SAIL_UPD_IMG_NAME_LEN,SAIL_UPD_IMG_NAME_INV,strlen(SAIL_UPD_IMG_NAME_INV)+1);
            if(memscpyRet == 0)
            {
               xRetStatus = MODULE_TEST_FAILED;
               DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_flashImage: Image name copy failed\r\n");
               return xRetStatus;
            }
            break;
        case TEST_FLASHIMG_INVPARTID:
            g_SAILUPdaterTestCtx.TxMsg.flashImg.FlashPartition = SAIL_UPD_PARTITION_ID_MAX;
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_flashImage: TEST_FLSHIMG_INVPARTID\r\n");
            break;
        case TEST_FLASHIMG_INVGPTID:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_flashImage: TEST_FLSHIMG_INVGPTID\r\n");
            g_SAILUPdaterTestCtx.TxMsg.flashImg.FlashGptId     = SAIL_UPD_GPT_ID_MAX;
            break;
        case TEST_FLASHIMG_INVBUFADDR:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_flashImage: TEST_FLASHIMG_INVBUFADDR\r\n");
            g_SAILUPdaterTestCtx.TxMsg.flashImg.bufAddr = 0U;
            break;
        case TEST_FLASHIMG_INVBUFSZ:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_flashImage: TEST_FLASHIMG_INVBUFSZ\r\n");
            g_SAILUPdaterTestCtx.TxMsg.flashImg.bufLen = 3*1024*1024;
            break;
        case TEST_FLASHIMG_INVBUFCRC:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_flashImage: TEST_FLASHIMG_INVBUFCRC\r\n");
            g_SAILUPdaterTestCtx.TxMsg.flashImg.bufCrc = 0;
            break;
        case TEST_FLASHIMG_UNALGNBUFSZ:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_flashImage: TEST_FLASHIMG_UNALGNBUFSZ\r\n");
            g_SAILUPdaterTestCtx.TxMsg.flashImg.bufLen = g_SAILUPdaterTestCtx.TxMsg.readImg.bufLen+3;
            break;
        default:
            xRetStatus = MODULE_TEST_FAILED;
            return xRetStatus;
    }

    /* Send Message and Receive response*/
    xRetStatus = vSAILUpdaterTestSendReceiveMessage(&g_SAILUPdaterTestCtx.TxMsg);
    if(MODULE_TEST_PASSED == xRetStatus)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_flashImage: Sent-Receive Done\r\n");
    }
    else
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_flashImage: Sent/Receive Failed\r\n");
        return xRetStatus;
    }

    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.msgId != SAIL_UPD_MSG_ID_FLASH_IMAGE)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_flashImage: Response Failure with Invalid MsgID\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.direction != SAIL_UPD_SAIL2MD)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_flashImage: Response Failure with Invalid direction\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    switch (testID)
    {
        case TEST_FLASHIMG:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_STATUS_SUCCESS)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_flashImage: Response Success\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_flashImage: Response Failure\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_FLASHIMG_INVIMGNAME:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_IMG_NAME)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_flashImage: Response Success SAIL_UPDATER_INVALID_IMG_NAME\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_flashImage: Response Failure, expected SAIL_UPDATER_INVALID_IMG_NAME\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_FLASHIMG_INVPARTID:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_PARTITION_ID)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_flashImage: Response Success SAIL_UPDATER_INVALID_PARTITION_ID\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_flashImage: Response Failure, expected SAIL_UPDATER_INVALID_PARTITION_ID\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_FLASHIMG_INVGPTID:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_GPT_ID)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_flashImage: Response Success SAIL_UPDATER_INVALID_GPT_ID\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_flashImage: Response Failure, expected SAIL_UPDATER_INVALID_GPT_ID\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_FLASHIMG_INVBUFADDR:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_BUF_ADDR)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_flashImage: Response Success SAIL_UPDATER_INVALID_BUF_ADDR\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_flashImage: Response Failure, expected SAIL_UPDATER_INVALID_BUF_ADDR\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_FLASHIMG_INVBUFSZ:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_BUF_SIZE)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_flashImage: Response Success SAIL_UPDATER_INVALID_BUF_SIZE\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_flashImage: Response Failure, expected SAIL_UPDATER_INVALID_BUF_SIZE\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_FLASHIMG_INVBUFCRC:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_BUF_CRC)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_flashImage: Response Success SAIL_UPDATER_INVALID_BUF_CRC\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_flashImage: Response Failure, expected SAIL_UPDATER_INVALID_BUF_CRC\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_FLASHIMG_UNALGNBUFSZ:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_UNALIGNED_BUF_SIZE)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_flashImage: Response Success SAIL_UPDATER_UNALIGNED_BUF_SIZE\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_flashImage: Response Failure, expected SAIL_UPDATER_UNALIGNED_BUF_SIZE\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        default:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_flashImage: Invalid Test ID\r\n\n");
            xRetStatus = MODULE_TEST_FAILED;
            break;
    }
    return xRetStatus;
}

/*----------------------------------------------------------------------------
* sail_updater: read Image
*
* @param sailUpdTestCaseIDType testID[IN]
*
* @return TESTerrorType_e [OUT]
*   Status of the operation MODULE_TEST_FAILED/MODULE_TEST_SUCCESS.
*
*--------------------------------------------------------------------------*/
TEST_FUNC TESTerrorType_e TC_SailUpdater_readImage(sailUpdTestCaseIDType testID)
{
    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    uint32_t memscpyRet = 0;
    uint32_t sz = (uint32_t)sizeof(sailUpdaterMsgHeaderType);

    xRetStatus = TC_SailUpdater_getBootInfo(TEST_GETBOOTINFO);
    if (MODULE_TEST_FAILED == xRetStatus)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: getBootInfo FAILED before ReadImg \n\r");
        return xRetStatus;
    }

    /* reset msg */
    (void)memset((void*)&(g_SAILUPdaterTestCtx.TxMsg), 0, sz);
    (void)memset((void*)&(g_SAILUPdaterTestCtx.RxMsg), 0, sz);

    if(bSAILUpdaterFuncTestReadImg == TRUE)
    {
        memscpyRet = sailbsp_memscpy(&g_SAILUPdaterTestCtx.TxMsg.readImg.imgName[0], SAIL_UPD_IMG_NAME_LEN,SAIL_UPD_IMG_NAME_SW4,strlen(SAIL_UPD_IMG_NAME_SW4)+1);
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: SW4 read\r\n");
    }
    else
    {
        memscpyRet = sailbsp_memscpy(&g_SAILUPdaterTestCtx.TxMsg.readImg.imgName[0], SAIL_UPD_IMG_NAME_LEN,SAIL_UPD_IMG_NAME_SW1,strlen(SAIL_UPD_IMG_NAME_SW1)+1);
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: SW1 read\r\n");
    }
    if(memscpyRet == 0)
    {
         xRetStatus = MODULE_TEST_FAILED;
         DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: Image name copy failed\r\n");
         return xRetStatus;
    }

    for(int k = 0; k < gRxMsgCtx.blInfoNumImagesBoot; k++)
    {
        if(strncmp((void *)&gRxMsgCtx.updImgEntryType[k].imgName[0],(void*)&g_SAILUPdaterTestCtx.TxMsg.readImg.imgName[0], SAIL_UPD_IMG_NAME_LEN) == 0)
        {
            g_SAILUPdaterTestCtx.TxMsg.readImg.bufLen = gRxMsgCtx.updImgEntryType[k].partitionSizeA;
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: buf len %d\n\r",g_SAILUPdaterTestCtx.TxMsg.readImg.bufLen);
        }
    }

    /* parse & pack msg */
    g_SAILUPdaterTestCtx.TxMsg.msgId      = SAIL_UPD_MSG_ID_READ_IMAGE;
    g_SAILUPdaterTestCtx.TxMsg.status     = SAIL_UPD_STATUS_SUCCESS;
    g_SAILUPdaterTestCtx.TxMsg.readImg.readPartition = 0;
    g_SAILUPdaterTestCtx.TxMsg.readImg.readGptId     = 0;
    g_SAILUPdaterTestCtx.TxMsg.readImg.bufAddr       = MD_VA_ADDR;

    switch (testID)
    {
        case TEST_READIMG:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: TEST_READIMG\r\n");
            break;
        case TEST_READIMG_INVIMGNAME:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: TEST_READIMG_INVIMGNAME\r\n");
            memscpyRet = sailbsp_memscpy(&g_SAILUPdaterTestCtx.TxMsg.readImg.imgName[0], SAIL_UPD_IMG_NAME_LEN,SAIL_UPD_IMG_NAME_INV,strlen(SAIL_UPD_IMG_NAME_INV)+1);
            if(memscpyRet == 0)
            {
               xRetStatus = MODULE_TEST_FAILED;
               DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: Image name copy failed\r\n");
               return xRetStatus;
            }
            break;
        case TEST_READIMG_INVPARTID:
            g_SAILUPdaterTestCtx.TxMsg.readImg.readPartition = SAIL_UPD_PARTITION_ID_MAX;
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: TEST_READIMG_INVPARTID\r\n");
            break;
        case TEST_READIMG_INVGPTID:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: TEST_READIMG_INVGPTID\r\n");
            g_SAILUPdaterTestCtx.TxMsg.readImg.readGptId     = SAIL_UPD_GPT_ID_MAX;
            break;
        case TEST_READIMG_INVBUFADDR:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: TEST_READIMG_INVBUFADDR\r\n");
            g_SAILUPdaterTestCtx.TxMsg.readImg.bufAddr = 0U;
            break;
        case TEST_READIMG_INVBUFSZ:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: TEST_READIMG_INVBUFSZ\r\n");
            g_SAILUPdaterTestCtx.TxMsg.readImg.bufLen = 3*1024*1024;
            break;
        case TEST_READIMG_UNALGNBUFSZ:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: TEST_READIMG_UNALGNBUFSZ\r\n");
            g_SAILUPdaterTestCtx.TxMsg.readImg.bufLen = g_SAILUPdaterTestCtx.TxMsg.readImg.bufLen+3;
            break;
        default:
            xRetStatus = MODULE_TEST_FAILED;
            return xRetStatus;
    }

    /* Send Message and Receive response*/
    xRetStatus = vSAILUpdaterTestSendReceiveMessage(&g_SAILUPdaterTestCtx.TxMsg);
    if(MODULE_TEST_PASSED == xRetStatus)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: Sent-Receive Done\r\n");
    }
    else
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: Sent/Receive Failed\r\n");
        return xRetStatus;
    }

    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.msgId != SAIL_UPD_MSG_ID_READ_IMAGE)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: Response Failure with Invalid MsgID\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.direction != SAIL_UPD_SAIL2MD)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: Response Failure with Invalid direction\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: Rx Status %d\r\n", g_SAILUPdaterTestCtx.RxMsg.status);
    switch (testID)
    {
        case TEST_READIMG:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_STATUS_SUCCESS)
            {
                gRxMsgCtx.rdImgBufAddr = g_SAILUPdaterTestCtx.RxMsg.readImg.bufAddr;
                gRxMsgCtx.rdImgBufLen  = g_SAILUPdaterTestCtx.RxMsg.readImg.bufLen;
                gRxMsgCtx.rdImgBufCrc  = g_SAILUPdaterTestCtx.RxMsg.readImg.bufCrc;
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: Response Success\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: Response Failure\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_READIMG_INVIMGNAME:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_IMG_NAME)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: Response Success SAIL_UPDATER_INVALID_IMG_NAME\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: Response Failure, expected SAIL_UPDATER_INVALID_IMG_NAME\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_READIMG_INVPARTID:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_PARTITION_ID)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: Response Success SAIL_UPDATER_INVALID_PARTITION_ID\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: Response Failure, expected SAIL_UPDATER_INVALID_PARTITION_ID\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_READIMG_INVGPTID:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_GPT_ID)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: Response Success SAIL_UPDATER_INVALID_GPT_ID\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: Response Failure, expected SAIL_UPDATER_INVALID_GPT_ID\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_READIMG_INVBUFADDR:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_BUF_ADDR)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: Response Success SAIL_UPDATER_INVALID_BUF_ADDR\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: Response Failure, expected SAIL_UPDATER_INVALID_BUF_ADDR\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_READIMG_INVBUFSZ:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_INVALID_BUF_SIZE)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: Response Success SAIL_UPDATER_INVALID_BUF_SIZE\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: Response Failure, expected SAIL_UPDATER_INVALID_BUF_SIZE\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        case TEST_READIMG_UNALGNBUFSZ:
            if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_UNALIGNED_BUF_SIZE)
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: Response Success SAIL_UPDATER_UNALIGNED_BUF_SIZE\r\n\n");
                xRetStatus = MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: Response Failure, expected SAIL_UPDATER_UNALIGNED_BUF_SIZE\r\n\n");
                xRetStatus = MODULE_TEST_FAILED;
            }
            break;
        default:
            DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_readImage: Invalid Test ID\r\n\n");
            xRetStatus = MODULE_TEST_FAILED;
            break;
    }
    return xRetStatus;
}

/*----------------------------------------------------------------------------
* sail_updater: ARB
*
* @param sailUpdTestCaseIDType testID[IN]
*
* @return TESTerrorType_e [OUT]
*   Status of the operation MODULE_TEST_FAILED/MODULE_TEST_SUCCESS.
*
*--------------------------------------------------------------------------*/
TEST_FUNC TESTerrorType_e TC_SailUpdater_ARB(sailUpdTestCaseIDType testID)
{
    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    uint32_t sz = (uint32_t)sizeof(sailUpdaterMsgHeaderType);
    /* reset msg */
    (void)memset((void*)&(g_SAILUPdaterTestCtx.TxMsg), 0, sz);
    (void)memset((void*)&(g_SAILUPdaterTestCtx.RxMsg), 0, sz);

    if(testID != TEST_ARB)
    {
        return xRetStatus;
    }

    /* parse & pack msg */
    g_SAILUPdaterTestCtx.TxMsg.msgId      = SAIL_UPD_MSG_ID_UPDATE_ARB;
    g_SAILUPdaterTestCtx.TxMsg.status     = SAIL_UPD_STATUS_SUCCESS;

    /* Send Message and Receive response*/
    xRetStatus = vSAILUpdaterTestSendReceiveMessage(&g_SAILUPdaterTestCtx.TxMsg);
    if(MODULE_TEST_PASSED == xRetStatus)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_ARB: Sent-Receive Done\r\n");
    }
    else
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_ARB: Sent/Receive Failed\r\n");
        return xRetStatus;
    }

    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.msgId != SAIL_UPD_MSG_ID_UPDATE_ARB)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_ARB: Response Failure with Invalid MsgID\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.direction != SAIL_UPD_SAIL2MD)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_ARB: Response Failure with Invalid direction\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_STATUS_SUCCESS)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_ARB: Response Success\r\n\n");
        xRetStatus = MODULE_TEST_PASSED;
    }
    else
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_ARB: Response Failure\r\n\n");
        xRetStatus = MODULE_TEST_FAILED;
    }
    return xRetStatus;
}

/*----------------------------------------------------------------------------
* sail_updater: MRC
*
* @param sailUpdTestCaseIDType testID[IN]
*
* @return TESTerrorType_e [OUT]
*   Status of the operation MODULE_TEST_FAILED/MODULE_TEST_SUCCESS.
*
*--------------------------------------------------------------------------*/
TEST_FUNC TESTerrorType_e TC_SailUpdater_MRC(sailUpdTestCaseIDType testID)
{
    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    uint32_t sz = (uint32_t)sizeof(sailUpdaterMsgHeaderType);
    /* reset msg */
    (void)memset((void*)&(g_SAILUPdaterTestCtx.TxMsg), 0, sz);
    (void)memset((void*)&(g_SAILUPdaterTestCtx.RxMsg), 0, sz);

    if(testID != TEST_MRC)
    {
        return xRetStatus;
    }

    /* parse & pack msg */
    g_SAILUPdaterTestCtx.TxMsg.msgId      = SAIL_UPD_MSG_ID_UPDATE_MRC;
    g_SAILUPdaterTestCtx.TxMsg.status     = SAIL_UPD_STATUS_SUCCESS;

    /* Send Message and Receive response*/
    xRetStatus = vSAILUpdaterTestSendReceiveMessage(&g_SAILUPdaterTestCtx.TxMsg);
    if(MODULE_TEST_PASSED == xRetStatus)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_MRC: Sent-Receive Done\r\n");
    }
    else
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_MRC: Sent/Receive Failed\r\n");
        return xRetStatus;
    }

    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.msgId != SAIL_UPD_MSG_ID_UPDATE_MRC)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_MRC: Response Failure with Invalid MsgID\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.direction != SAIL_UPD_SAIL2MD)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_MRC: Response Failure with Invalid direction\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_STATUS_SUCCESS)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_MRC: Response Success\r\n\n");
        xRetStatus = MODULE_TEST_PASSED;
    }
    else
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_MRC: Response Failure\r\n\n");
        xRetStatus = MODULE_TEST_FAILED;
    }
    return xRetStatus;
}

/*----------------------------------------------------------------------------
* sail_updater: Redundancy
*
* @param sailUpdTestCaseIDType testID[IN]
*
* @return TESTerrorType_e [OUT]
*   Status of the operation MODULE_TEST_FAILED/MODULE_TEST_SUCCESS.
*
*--------------------------------------------------------------------------*/
TEST_FUNC TESTerrorType_e TC_SailUpdater_Redundancy(sailUpdTestCaseIDType testID)
{
    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    uint32_t sz = (uint32_t)sizeof(sailUpdaterMsgHeaderType);
    /* reset msg */
    (void)memset((void*)&(g_SAILUPdaterTestCtx.TxMsg), 0, sz);
    (void)memset((void*)&(g_SAILUPdaterTestCtx.RxMsg), 0, sz);

    if(testID != TEST_REDUNDANCY)
    {
        return xRetStatus;
    }

    /* parse & pack msg */
    g_SAILUPdaterTestCtx.TxMsg.msgId      = SAIL_UPD_MSG_REDUNDANCY_ESTABLISHED;
    g_SAILUPdaterTestCtx.TxMsg.status     = SAIL_UPD_STATUS_SUCCESS;

    /* Send Message and Receive response*/
    xRetStatus = vSAILUpdaterTestSendReceiveMessage(&g_SAILUPdaterTestCtx.TxMsg);
    if(MODULE_TEST_PASSED == xRetStatus)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_Redundancy: Sent-Receive Done\r\n");
    }
    else
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_Redundancy: Sent/Receive Failed\r\n");
        return xRetStatus;
    }

    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.msgId != SAIL_UPD_MSG_REDUNDANCY_ESTABLISHED)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_Redundancy: Response Failure with Invalid MsgID\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.direction != SAIL_UPD_SAIL2MD)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_Redundancy: Response Failure with Invalid direction\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_STATUS_SUCCESS)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_Redundancy: Response Success\r\n\n");
        xRetStatus = MODULE_TEST_PASSED;
    }
    else
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_Redundancy: Response Failure\r\n\n");
        xRetStatus = MODULE_TEST_FAILED;
    }
    return xRetStatus;
}

/*----------------------------------------------------------------------------
* sail_updater: OTA Done
*
* @param sailUpdTestCaseIDType testID[IN]
*
* @return TESTerrorType_e [OUT]
*   Status of the operation MODULE_TEST_FAILED/MODULE_TEST_SUCCESS.
*
*--------------------------------------------------------------------------*/
TEST_FUNC TESTerrorType_e TC_SailUpdater_OTA_Done(sailUpdTestCaseIDType testID)
{
    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;
    uint32_t sz = (uint32_t)sizeof(sailUpdaterMsgHeaderType);
    /* reset msg */
    (void)memset((void*)&(g_SAILUPdaterTestCtx.TxMsg), 0, sz);
    (void)memset((void*)&(g_SAILUPdaterTestCtx.RxMsg), 0, sz);

    if(testID != TEST_OTA_DONE)
    {
        return xRetStatus;
    }

    /* parse & pack msg */
    g_SAILUPdaterTestCtx.TxMsg.msgId      = SAIL_UPD_MSG_OTA_DONE;
    g_SAILUPdaterTestCtx.TxMsg.status     = SAIL_UPD_STATUS_SUCCESS;

    /* Send Message and Receive response*/
    xRetStatus = vSAILUpdaterTestSendReceiveMessage(&g_SAILUPdaterTestCtx.TxMsg);
    if(MODULE_TEST_PASSED == xRetStatus)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_OTA_Done: Sent-Receive Done\r\n");
    }
    else
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_OTA_Done: Sent/Receive Failed\r\n");
        return xRetStatus;
    }

    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.msgId != SAIL_UPD_MSG_OTA_DONE)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_OTA_Done: Response Failure with Invalid MsgID\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    /*Validate responses*/
    if(g_SAILUPdaterTestCtx.RxMsg.direction != SAIL_UPD_SAIL2MD)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_OTA_Done: Response Failure with Invalid direction\r\n");
        xRetStatus = MODULE_TEST_FAILED;
        return xRetStatus;
    }
    if(g_SAILUPdaterTestCtx.RxMsg.status == SAIL_UPDATER_STATUS_SUCCESS)
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_OTA_Done: Response Success\r\n\n");
        xRetStatus = MODULE_TEST_PASSED;
    }
    else
    {
        DEBUG_LOG(SAIL_INFO, "TC_SailUpdater_OTA_Done: Response Failure\r\n\n");
        xRetStatus = MODULE_TEST_FAILED;
    }
    return xRetStatus;
}

/*========================================================================================================
**  Function :  xTestSailUpdater_functionalTest
**  sailupdater test
** ========================================================================================================
*/
TEST_FUNC TESTerrorType_e TC_functionalTest_OTAFlow(uint32_t restart, boolean ext_support)
{
    TESTerrorType_e xRetStatus = MODULE_TEST_PASSED;

    xRetStatus = TC_SailUpdater_Hello(TEST_HELLO);
    if (MODULE_TEST_FAILED == xRetStatus)
    {
        DEBUG_LOG(SAIL_INFO, "SAILUPDATER Functional Hello FAILED \n\r");
        return xRetStatus;
    }
    xRetStatus = TC_SailUpdater_checkGPT(TEST_CHECKGPT);
    if (MODULE_TEST_FAILED == xRetStatus)
    {
        DEBUG_LOG(SAIL_INFO, "SAILUPDATER Functional checkGpt FAILED \n\r");
        return xRetStatus;
    }
    xRetStatus = TC_SailUpdater_getMetaDataInfo(TEST_GETOTAMETADATAINFO);
    if (MODULE_TEST_FAILED == xRetStatus)
    {
        DEBUG_LOG(SAIL_INFO, "SAILUPDATER Functional getMetaDataInfo FAILED \n\r");
        return xRetStatus;
    }
    xRetStatus = TC_SailUpdater_getOtaMetaData(TEST_GETOTAMETADATA);
    if (MODULE_TEST_FAILED == xRetStatus)
    {
        DEBUG_LOG(SAIL_INFO, "SAILUPDATER Functional getMetaData FAILED \n\r");
        return xRetStatus;
    }
    xRetStatus = TC_SailUpdater_getBootInfo(TEST_GETBOOTINFO);
    if (MODULE_TEST_FAILED == xRetStatus)
    {
        DEBUG_LOG(SAIL_INFO, "SAILUPDATER Functional getBootInfo FAILED \n\r");
        return xRetStatus;
    }
    if(restart == 0)
    {
        xRetStatus = TC_SailUpdater_readImage(TEST_READIMG);
        if (MODULE_TEST_FAILED == xRetStatus)
        {
            DEBUG_LOG(SAIL_INFO, "SAILUPDATER Functional readImg FAILED \n\r");
            return xRetStatus;
        }
        xRetStatus = TC_SailUpdater_flashImage(TEST_FLASHIMG, restart, ext_support);
        if (MODULE_TEST_FAILED == xRetStatus)
        {
            DEBUG_LOG(SAIL_INFO, "SAILUPDATER Functional flashImg FAILED \n\r");
            return xRetStatus;
        }
        xRetStatus = TC_SailUpdater_updateGPT(TEST_UPDGPT);
        if (MODULE_TEST_FAILED == xRetStatus)
        {
            DEBUG_LOG(SAIL_INFO, "SAILUPDATER Functional updateGpt FAILED \n\r");
            return xRetStatus;
        }
    }
    else if (restart == 1)
    {
        if (TRUE == ext_support)
        {
            xRetStatus = TC_SailUpdater_OTA_Done(TEST_OTA_DONE);
            if (MODULE_TEST_FAILED == xRetStatus)
            {
                DEBUG_LOG(SAIL_INFO, "SAILUPDATER Functional OTADONE FAILED \n\r");
                return xRetStatus;
            }
        }
        bSAILUpdaterFuncTestReadImg = FALSE;
        xRetStatus = TC_SailUpdater_readImage(TEST_READIMG);
        if (MODULE_TEST_FAILED == xRetStatus)
        {
            DEBUG_LOG(SAIL_INFO, "SAILUPDATER Functional readImg FAILED \n\r");
            return xRetStatus;
        }
        xRetStatus = TC_SailUpdater_flashImage(TEST_FLASHIMG, restart, ext_support);
        if (MODULE_TEST_FAILED == xRetStatus)
        {
            DEBUG_LOG(SAIL_INFO, "SAILUPDATER Functional flashImg FAILED \n\r");
            return xRetStatus;
        }

        xRetStatus = TC_SailUpdater_fixGPT(TEST_FIXGPT, ext_support);
        if (MODULE_TEST_FAILED == xRetStatus)
        {
            DEBUG_LOG(SAIL_INFO, "SAILUPDATER Functional fixGPT FAILED \n\r");
            return xRetStatus;
        }

        if (TRUE == ext_support)
        {
            xRetStatus = TC_SailUpdater_Redundancy(TEST_REDUNDANCY);
            if (MODULE_TEST_FAILED == xRetStatus)
            {
                DEBUG_LOG(SAIL_INFO, "SAILUPDATER Functional Redundancy FAILED \n\r");
                return xRetStatus;
            }
        }

        xRetStatus = TC_SailUpdater_setOtaMetaData(TEST_SETOTAMETADATA);
        if (MODULE_TEST_FAILED == xRetStatus)
        {
            DEBUG_LOG(SAIL_INFO, "SAILUPDATER Functional setOtaMetaData FAILED \n\r");
            return xRetStatus;
        }

        xRetStatus = TC_SailUpdater_ARB(TEST_ARB);
        if (MODULE_TEST_FAILED == xRetStatus)
        {
            DEBUG_LOG(SAIL_INFO, "SAILUPDATER Functional ARB FAILED \n\r");
            return xRetStatus;
        }

        xRetStatus = TC_SailUpdater_MRC(TEST_MRC);
        if (MODULE_TEST_FAILED == xRetStatus)
        {
            DEBUG_LOG(SAIL_INFO, "SAILUPDATER Functional MRC FAILED \n\r");
            return xRetStatus;
        }
    }
    else
    {
        DEBUG_LOG(SAIL_INFO, "TC_functionalTest_OTAFlow: Invalid restart option\r\n\n");
        xRetStatus = MODULE_TEST_FAILED;
    }
    return xRetStatus;
}

/*========================================================================================================
**  Function :  xTestSailUpdater_El1_Wrapper
**  sailupdater test
** ========================================================================================================
*/

TEST_FUNC TESTerrorType_e xTestSailUpdater_El1_Wrapper(void)
{
    uint8 *find;
    uint16_t testLoop;
    uint64_t testcasefailed = 0;
    find = APPL_SAIL_Shell_gettoken(NULL);

    if (FALSE == bSAILUpdaterTestStart)
    {
        /* Queue Create */
        if( pdPASS !=xSAILUpdaterTestQueueInit())
        {
            DEBUG_LOG(SAIL_INFO, " vSAILUpdaterTestSendMessage: xSAILUpdaterTestQueueInit Failed\n\r");
            return MODULE_TEST_FAILED;
        }
        else
        {
            DEBUG_LOG(SAIL_INFO, " vSAILUpdaterTestSendMessage: xSAILUpdaterTestQueueInit Pass\n\r");
            bSAILUpdaterTestStart = TRUE;
        }
    }

    TESTerrorType_e xRetStatus = MODULE_TEST_FAILED;

    if(APPL_SAIL_Shell_stricmp("ft",(char*)find))
    {
        boolean ext_support =  FALSE;
        bSAILUpdaterFuncTestReadImg = FALSE;//changing to fix reboot fail after preboot sequence
        find = APPL_SAIL_Shell_gettoken(NULL);

        if(APPL_SAIL_Shell_stricmp("r0",(char*)find))
        {
            find = APPL_SAIL_Shell_gettoken(NULL);
            if(APPL_SAIL_Shell_stricmp("extsupport",(char*)find))
            {
                ext_support =  TRUE;
            }
            else
            {
                ext_support =  FALSE;
            }
            xRetStatus = TC_functionalTest_OTAFlow(0, ext_support);
            if (MODULE_TEST_FAILED == xRetStatus)
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER Functional Test OTA Pre Reboot Flow FAILED <<<<<\n\r");
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER Functional Test OTA Pre Reboot Flow PASSED. initiate system Reboot <<<<<\n\r");
            }
        }
        else if (APPL_SAIL_Shell_stricmp("r1",(char*)find))
        {
            find = APPL_SAIL_Shell_gettoken(NULL);
            if(APPL_SAIL_Shell_stricmp("extsupport",(char*)find))
            {
                ext_support =  TRUE;
            }
            else
            {
                ext_support =  FALSE;
            }

            xRetStatus = TC_functionalTest_OTAFlow(1, ext_support);
            if (MODULE_TEST_FAILED == xRetStatus)
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER Functional Test OTA Post Reboot Flow FAILED <<<<<\n\r");
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER Functional Test OTA Post Reboot Flow PASSED <<<<<\n\r");
            }
        }
        else
        {
            /* Invalid cmd */
            DEBUG_LOG( SAIL_INFO,"sail_updater ft syntax invalid  \n\r" );
            return xRetStatus;
        }
    }
    else if(APPL_SAIL_Shell_stricmp("ut",(char*)find))
    {
        bSAILUpdaterFuncTestReadImg = FALSE;
        find = APPL_SAIL_Shell_gettoken(NULL);

        if (APPL_SAIL_Shell_stricmp("hello",(char*)find))
        {
            for(testLoop = TEST_INVHELLO_VER; testLoop <= TEST_HELLO; testLoop++)
            {
                xRetStatus = TC_SailUpdater_Hello(testLoop);
                if(MODULE_TEST_PASSED != xRetStatus)
                {
                    testcasefailed |= (uint64_t)1<<testLoop;
                }
            }
            if (0 == testcasefailed)
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER HELLO Test all test cases passed <<<<<\n\r");
                return MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER TEST all HELLO test cases NOT passed 0x%x <<<<<\n\r",testcasefailed);
                return MODULE_TEST_FAILED;
            }
        }
        else if (APPL_SAIL_Shell_stricmp("flashimg",(char*)find))
        {
            boolean ext_support = FALSE;
            find = APPL_SAIL_Shell_gettoken(NULL);
            if(APPL_SAIL_Shell_stricmp("extsupport",(char*)find))
            {
                ext_support = TRUE;
            }
            else
            {
                ext_support = FALSE;
            }
            xRetStatus = TC_SailUpdater_readImage(TEST_READIMG);
            if (MODULE_TEST_FAILED == xRetStatus)
            {
                DEBUG_LOG(SAIL_INFO, "SAILUPDATER readImg FAILED before running flashimg test \n\r");
                return xRetStatus;
            }

            for(testLoop = TEST_FLASHIMG_INVIMGNAME; testLoop <= TEST_FLASHIMG; testLoop++)
            {
                xRetStatus = TC_SailUpdater_flashImage(testLoop, 0, ext_support);
                if(MODULE_TEST_PASSED != xRetStatus)
                {
                    testcasefailed |= (uint64_t)1<<testLoop;
                }
            }
            if (0 == testcasefailed)
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER TEST_FLASHIMG Test all test cases passed <<<<<\n\r");
                return MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER TEST all TEST_FLASHIMG test cases NOT passed 0x%x <<<<<\n\r",testcasefailed);
                return MODULE_TEST_FAILED;
            }
        }
        else if (APPL_SAIL_Shell_stricmp("readimg",(char*)find))
        {
            for(testLoop = TEST_READIMG_INVIMGNAME; testLoop <= TEST_READIMG; testLoop++)
            {
                xRetStatus = TC_SailUpdater_readImage(testLoop);
                if(MODULE_TEST_PASSED != xRetStatus)
                {
                    testcasefailed |= (uint64_t)1<<testLoop;
                }
            }
            if (0 == testcasefailed)
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER TEST_READIMG Test all test cases passed <<<<<\n\r");
                return MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER TEST all TEST_READIMG test cases NOT passed 0x%x <<<<<\n\r",testcasefailed);
                return MODULE_TEST_FAILED;
            }
        }
        else if (APPL_SAIL_Shell_stricmp("getota",(char*)find))
        {
            xRetStatus = TC_SailUpdater_getMetaDataInfo(TEST_GETOTAMETADATAINFO);
            if (MODULE_TEST_FAILED == xRetStatus)
            {
                DEBUG_LOG(SAIL_INFO, "SAILUPDATER GETOTAMETADATA test getMetaDataInfo FAILED \n\r");
                return xRetStatus;
            }

            for(testLoop = TEST_GETOTAMETADATA_UNALGNBUFSZ; testLoop <= TEST_GETOTAMETADATA; testLoop++)
            {
                xRetStatus = TC_SailUpdater_getOtaMetaData(testLoop);
                if(MODULE_TEST_PASSED != xRetStatus)
                {
                    testcasefailed |= (uint64_t)1<<testLoop;
                }
            }
            if (0 == testcasefailed)
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER GETOTAMETADATA Test all test cases passed <<<<<\n\r");
                return MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER TEST all GETOTAMETADATA test cases NOT passed 0x%x <<<<<\n\r",testcasefailed);
                return MODULE_TEST_FAILED;
            }
        }
        else if (APPL_SAIL_Shell_stricmp("setota",(char*)find))
        {
            xRetStatus = TC_SailUpdater_getMetaDataInfo(TEST_GETOTAMETADATAINFO);
            if (MODULE_TEST_FAILED == xRetStatus)
            {
                DEBUG_LOG(SAIL_INFO, "SAILUPDATER SETOTAMETADATA test getMetaDataInfo FAILED \n\r");
                return xRetStatus;
            }

            for(testLoop = TEST_SETOTAMETADATA_UNALGNBUFSZ; testLoop <= TEST_SETOTAMETADATA; testLoop++)
            {
                xRetStatus = TC_SailUpdater_setOtaMetaData(testLoop);
                if(MODULE_TEST_PASSED != xRetStatus)
                {
                    testcasefailed |= (uint64_t)1<<testLoop;
                }
            }
            if (0 == testcasefailed)
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER SETOTAMETADATA Test all test cases passed <<<<<\n\r");
                return MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER TEST all SETOTAMETADATA test cases NOT passed 0x%x <<<<<\n\r",testcasefailed);
                return MODULE_TEST_FAILED;
            }
        }
        else if (APPL_SAIL_Shell_stricmp("chkgpt",(char*)find))
        {
            xRetStatus = TC_SailUpdater_checkGPT(TEST_CHECKGPT);
            if (MODULE_TEST_FAILED == xRetStatus)
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER CHECK GPT Test FAILED <<<<<\n\r");
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER CHECK GPT Test PASSED <<<<<\n\r");
            }
        }
        else if (APPL_SAIL_Shell_stricmp("blinfo",(char*)find))
        {
            for(testLoop = TEST_GETBOOTINFO_INVBUFSZ; testLoop <= TEST_GETBOOTINFO; testLoop++)
            {
                xRetStatus = TC_SailUpdater_getBootInfo(testLoop);
                if(MODULE_TEST_PASSED != xRetStatus)
                {
                    testcasefailed |= (uint64_t)1<<testLoop;
                }
            }
            if (0 == testcasefailed)
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER TEST_GETBOOTINFO Test all test cases passed <<<<<\n\r");
                return MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER TEST all TEST_GETBOOTINFO test cases NOT passed 0x%x <<<<<\n\r",testcasefailed);
                return MODULE_TEST_FAILED;
            }
        }
        else if (APPL_SAIL_Shell_stricmp("readgpt",(char*)find))
        {
            for(testLoop = TEST_READGPT_INVBUFSZ; testLoop <= TEST_READGPT; testLoop++)
            {
                xRetStatus = TC_SailUpdater_readGPT(testLoop);
                if(MODULE_TEST_PASSED != xRetStatus)
                {
                    testcasefailed |= (uint64_t)1<<testLoop;
                }
            }
            if (0 == testcasefailed)
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER TEST_READGPT Test all test cases passed <<<<<\n\r");
                return MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER TEST all TEST_READGPT test cases NOT passed 0x%x <<<<<\n\r",testcasefailed);
                return MODULE_TEST_FAILED;
            }
        }
        else if (APPL_SAIL_Shell_stricmp("writegpt",(char*)find))
        {
            for(testLoop = TEST_WRITEGPT_INVBUFSZ; testLoop <= TEST_WRITEGPT; testLoop++)
            {
                xRetStatus = TC_SailUpdater_writeGPT(testLoop);
                if(MODULE_TEST_PASSED != xRetStatus)
                {
                    testcasefailed |= (uint64_t)1<<testLoop;
                }
            }
            if (0 == testcasefailed)
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER TEST_WRITEGPT Test all test cases passed <<<<<\n\r");
                return MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER TEST all TEST_WRITEGPT test cases NOT passed 0x%x <<<<<\n\r",testcasefailed);
                return MODULE_TEST_FAILED;
            }
        }
        else if (APPL_SAIL_Shell_stricmp("fixgpt",(char*)find))
        {
            boolean ext_support = FALSE;
            find = APPL_SAIL_Shell_gettoken(NULL);
            if(APPL_SAIL_Shell_stricmp("extsupport",(char*)find))
            {
                ext_support = TRUE;
            }
            else
            {
                ext_support = FALSE;
            }
            for(testLoop = TEST_FIXGPT_INVBUFSZ; testLoop <= TEST_FIXGPT; testLoop++)
            {
                xRetStatus = TC_SailUpdater_fixGPT(testLoop, ext_support);
                if(MODULE_TEST_PASSED != xRetStatus)
                {
                    testcasefailed |= (uint64_t)1<<testLoop;
                }
            }
            if (0 == testcasefailed)
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER TEST_FIXGPT Test all test cases passed <<<<<\n\r");
                return MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER TEST all TEST_FIXGPT test cases NOT passed 0x%x <<<<<\n\r",testcasefailed);
                return MODULE_TEST_FAILED;
            }
        }
        else if (APPL_SAIL_Shell_stricmp("updgpt",(char*)find))
        {
            for(testLoop = TEST_UPDGPT_INVBUFSZ; testLoop <= TEST_UPDGPT; testLoop++)
            {
                xRetStatus = TC_SailUpdater_updateGPT(testLoop);
                if(MODULE_TEST_PASSED != xRetStatus)
                {
                    testcasefailed |= (uint64_t)1<<testLoop;
                }
            }
            if (0 == testcasefailed)
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER TEST_UPDGPT Test all test cases passed <<<<<\n\r");
                return MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER TEST all TEST_UPDGPT test cases NOT passed 0x%x <<<<<\n\r",testcasefailed);
                return MODULE_TEST_FAILED;
            }
        }
        else if (APPL_SAIL_Shell_stricmp("queryimg",(char*)find))
        {
            for(testLoop = TEST_QUERYIMG_INVNUMIMG; testLoop <= TEST_QUERYIMG; testLoop++)
            {
                xRetStatus = TC_SailUpdater_queryImg(testLoop);
                if(MODULE_TEST_PASSED != xRetStatus)
                {
                    testcasefailed |= (uint64_t)1<<testLoop;
                }
            }
            if (0 == testcasefailed)
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER TEST_QUERYIMG Test all test cases passed <<<<<\n\r");
                return MODULE_TEST_PASSED;
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER TEST all TEST_QUERYIMG test cases NOT passed 0x%x <<<<<\n\r",testcasefailed);
                return MODULE_TEST_FAILED;
            }
        }
        else if (APPL_SAIL_Shell_stricmp("arb",(char*)find))
        {
            xRetStatus = TC_SailUpdater_ARB(TEST_ARB);
            if (MODULE_TEST_FAILED == xRetStatus)
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER ARB Test FAILED <<<<<\n\r");
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER ARB Test PASSED <<<<<\n\r");
            }
        }
        else if (APPL_SAIL_Shell_stricmp("mrc",(char*)find))
        {
            xRetStatus = TC_SailUpdater_MRC(TEST_MRC);
            if (MODULE_TEST_FAILED == xRetStatus)
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER MRC Test FAILED <<<<<\n\r");
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER MRC Test PASSED <<<<<\n\r");
            }
        }
        else if (APPL_SAIL_Shell_stricmp("redundancy",(char*)find))
        {
            xRetStatus = TC_SailUpdater_Redundancy(TEST_REDUNDANCY);
            if (MODULE_TEST_FAILED == xRetStatus)
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER REDUNDANCY Test FAILED <<<<<\n\r");
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER REDUNDANCY Test PASSED <<<<<\n\r");
            }
        }
        else if (APPL_SAIL_Shell_stricmp("otadone",(char*)find))
        {
            xRetStatus = TC_SailUpdater_OTA_Done(TEST_OTA_DONE);
            if (MODULE_TEST_FAILED == xRetStatus)
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER OTADONE Test FAILED <<<<<\n\r");
            }
            else
            {
                DEBUG_LOG(SAIL_INFO, ">>>>> SAILUPDATER OTADONE Test PASSED <<<<<\n\r");
            }
        }
        else
        {
            /* Invalid cmd */
            DEBUG_LOG( SAIL_INFO,"sail_updater ut syntax invalid  \n\r" );
            return xRetStatus;
        }
    }
    else
    {
        /* Invalid cmd */
        DEBUG_LOG( SAIL_INFO,"sail_updater syntax invalid  \n\r" );
        return xRetStatus;
    }
    return xRetStatus;
}

#endif //SAILUPDATER_TEST_SRC_ENABLED
/**********************************************************************************************************
**                                  End of file sailupdater_test.c                                              **
**********************************************************************************************************/
