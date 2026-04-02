
#ifndef __SAIL_UPDATER_CORE_H__
#define __SAIL_UPDATER_CORE_H__

/*
===========================================================================
*/
/**
    @file  sail_updater_core.h
    @brief This file provides definitions for the SAIL Updater core support functions.

*/
/*
    ===========================================================================

    Copyright (c) 2022-2025 Qualcomm Technologies, Inc.
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

#include "types.h"
#include "sail_updater_cmn.h"
#include "sail_updater_msgtypes.h"

/*Enable Sail updater tests*/
#define SAILUPDATER_TEST_SRC_ENABLED

/* Return Types for the Core operations */
typedef enum
{
   SAIL_UPDATER_SUCCESS,                   /* Success */
   SAIL_UPDATER_FAIL                       /* Failure */
}SAILUpdaterCoreStatusType_e;

/* SAIL Updater Core GPT verify type */
typedef struct
{
    uint32_t HeaderCrcStatus;    /* 0 - error, 1 - pass */
    uint32_t EntryCrcStatus;     /* 0 - error, 1 - pass */
    uint32_t GptSize;            /* in bytes            */
} sailUpdaterCoreVerifyGPTtype;

/**********************************************************
 * set the Skip Addr check value
 *
 *
 * @param skipVal [IN]
 *   None
 *
 * @return void [OUT]
 *
 **********************************************************/
void vSailUpdaterSetSkipAddrCheck(boolean skipVal);

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
void vSailUpdaterSetSkipMB(boolean skipVal);

/**********************************************************
 * Initalizes the resources and contexts used by the SAIL Updater
 *
 *
 * @param void [IN]
 *   None
 *
 * @return SAILUpdaterCoreStatusType_e [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SAILUpdaterCoreStatusType_e xSAILUpdaterCoreInit(void);

/**********************************************************
 * De-Initalizes the resources and contexts used by the SAIL Updater
 *
 *
 * @param void [IN]
 *   None
 *
 * @return SAILUpdaterCoreStatusType_e [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SAILUpdaterCoreStatusType_e xSAILUpdaterCoreDeInit(void);

/**********************************************************
 * Calculates the CRC for the contents provided
 *
 *
 * @param addr [IN]
 *   Start address of the contents
 *
 * @param len [IN]
 *   Length of the data of the contents
 *
 * @return uint32_t [OUT]
 *   Resulting CRC value.
 *
 **********************************************************/
uint32_t ulSAILUpdaterCoreCalcCRC(uint32_t addr, uint32_t len);

/**********************************************************
 * Calculates the cumulative CRC for the contents provided
 *
 *
 * @param addr [IN]
 *   Start address of the contents
 *
 * @param len [IN]
 *   Length of the data of the contents
 *
 * @param lastIteration [IN]
 *   lastIteration in the cumulative CRC loop
 *
 * @param calcCrc [IN]
 *   calc CRC in the loop
 *
 * @return uint32_t [OUT]
 *   Resulting CRC value.
 *
 **********************************************************/
uint32_t ulSAILUpdaterCoreCalcCumulativeCRC(uint32_t addr, uint32_t len, bool lastIteration, uint32_t calcCrc);

/**********************************************************
 * SAIL Updater Check Boot Partition
 *
 *  If Boot partitions are matching, Then update OTA state as DISABLED else write IN_PROGRESS
 *
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterCheckbootPartition(void);

/**********************************************************
 * Process the Hello Message
 *
 *
 * @param pReqMsg [IN]
 *   Pointer to the Request Message
 *
 * @param pRspMsg [IN/OUT]
 *   Pointer to the Response Message
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessHello(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg);

/**********************************************************
 * Process the Flash Image Message
 *
 *
 * @param pReqMsg [IN]
 *   Pointer to the Request Message
 *
 * @param pRspMsg [IN/OUT]
 *   Pointer to the Response Message
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessFlashImg(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg);

/**********************************************************
 * Process the Read Image Message
 *
 *
 * @param pReqMsg [IN]
 *   Pointer to the Request Message
 *
 * @param pRspMsg [IN/OUT]
 *   Pointer to the Response Message
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessReadImg(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg);

/**********************************************************
 * Process the Get OTA Meta data Message
 *
 *
 * @param pReqMsg [IN]
 *   Pointer to the Request Message
 *
 * @param pRspMsg [IN/OUT]
 *   Pointer to the Response Message
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessGetOTAMeta(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg);

/**********************************************************
 * Process the Set OTA Meta data Message
 *
 *
 * @param pReqMsg [IN]
 *   Pointer to the Request Message
 *
 * @param pRspMsg [IN/OUT]
 *   Pointer to the Response Message
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessSetOTAMeta(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg);

/**********************************************************
 * Process the Read OTA Meta data Message
 *
 *
 * @param pReqMsg [IN]
 *   Pointer to the Request Message
 *
 * @param pRspMsg [IN/OUT]
 *   Pointer to the Response Message
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessReadOTAMeta(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg);

/**********************************************************
 * Process the Write OTA Meta data Message
 *
 *
 * @param pReqMsg [IN]
 *   Pointer to the Request Message
 *
 * @param pRspMsg [IN/OUT]
 *   Pointer to the Response Message
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessWriteOTAMeta(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg);

/**********************************************************
 * Process the Erase OTA Meta data Message
 *
 *
 * @param pReqMsg [IN]
 *   Pointer to the Request Message
 *
 * @param pRspMsg [IN/OUT]
 *   Pointer to the Response Message
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessEraseOTAMeta(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg);

/**********************************************************
 * Process the Get OTA Meta data Info Message
 *
 *
 * @param pReqMsg [IN]
 *   Pointer to the Request Message
 *
 * @param pRspMsg [IN/OUT]
 *   Pointer to the Response Message
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessGetOTAMetaInfo(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg);

/**********************************************************
 * Process the Check GPT Message
 *
 *
 * @param pReqMsg [IN]
 *   Pointer to the Request Message
 *
 * @param pRspMsg [IN/OUT]
 *   Pointer to the Response Message
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessChkGPT(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg);

/**********************************************************
 * Process the Read GPT Message
 *
 *
 * @param pReqMsg [IN]
 *   Pointer to the Request Message
 *
 * @param pRspMsg [IN/OUT]
 *   Pointer to the Response Message
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessReadGPT(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg);

/**********************************************************
 * Process the Write GPT Message
 *
 *
 * @param pReqMsg [IN]
 *   Pointer to the Request Message
 *
 * @param pRspMsg [IN/OUT]
 *   Pointer to the Response Message
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessWriteGPT(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg);

/**********************************************************
 * Process the Fix GPT Message
 *
 *
 * @param pReqMsg [IN]
 *   Pointer to the Request Message
 *
 * @param pRspMsg [IN/OUT]
 *   Pointer to the Response Message
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessFixGPT(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg);

/**********************************************************
 * Process the Update GPT Message
 *
 *
 * @param pReqMsg [IN]
 *   Pointer to the Request Message
 *
 * @param pRspMsg [IN/OUT]
 *   Pointer to the Response Message
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessUpdateGPT(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg);

/**********************************************************
 * Process the Query Image Message
 *
 *
 * @param pReqMsg [IN]
 *   Pointer to the Request Message
 *
 * @param pRspMsg [IN/OUT]
 *   Pointer to the Response Message
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessQueryImg(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg);

/**********************************************************
 * Process the Get Boot Info Message
 *
 *
 * @param pReqMsg [IN]
 *   Pointer to the Request Message
 *
 * @param pRspMsg [IN/OUT]
 *   Pointer to the Response Message
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessGetBootInfo(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg);

/**********************************************************
 * Process the Boot Image Message
 *
 *
 * @param pReqMsg [IN]
 *   Pointer to the Request Message
 *
 * @param pRspMsg [IN/OUT]
 *   Pointer to the Response Message
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessBootImg(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg);

/**********************************************************
 * Process the Boot Continue Message
 *
 *
 * @param pReqMsg [IN]
 *   Pointer to the Request Message
 *
 * @param pRspMsg [IN/OUT]
 *   Pointer to the Response Message
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessBootContinue(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg);

/**********************************************************
 * Process the OTA Done Message
 *
 *
 * @param pReqMsg [IN]
 *   Pointer to the Request Message
 *
 * @param pRspMsg [IN/OUT]
 *   Pointer to the Response Message
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessOTADone(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg);

/**********************************************************
 * Process the Redundancy Established Message
 *
 *
 * @param pReqMsg [IN]
 *   Pointer to the Request Message
 *
 * @param pRspMsg [IN/OUT]
 *   Pointer to the Response Message
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessRedundancy(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg);

/**********************************************************
 * Process the Update ARB Message
 *
 *
 * @param pReqMsg [IN]
 *   Pointer to the Request Message
 *
 * @param pRspMsg [IN/OUT]
 *   Pointer to the Response Message
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessUpdateARB(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg);

/**********************************************************
 * Process the Update MRC Message
 *
 *
 * @param pReqMsg [IN]
 *   Pointer to the Request Message
 *
 * @param pRspMsg [IN/OUT]
 *   Pointer to the Response Message
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessUpdateMRC(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg);

/**********************************************************
 * Updates the status of the GPT validity
 *
 * @param gptId [IN]
 *   GPT Header ID
 *
 * @param crc32 [OUT]
 *  crc value of the GPT ID
 *
 * @param hdrCrcStatus [OUT]
 *  header crc status of the GPT ID
 *
 * @param entryCrcStatus [OUT]
 *  entry crc status of the GPT ID
 *
 * @return SAILUpdaterCoreStatusType_e [OUT]
 *   Status of the operation
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterCoreVerifyGPTWrap(uint32_t gptId, uint32_t *crc32, uint32_t *hdrCrcStatus, uint32_t *entryCrcStatus);

/**********************************************************
 * Wrapper to Reconstruct Alternate GPT using Source GPT
 *
 * @param norHandle [IN]
 *   Handle for the NOR flash
 *
 * @param sourceGptId [IN]
 *   GPT ID of Source GPT
 *
 * @param isSwapNeeded [IN]
 *   Is Swapping of the offsets of boot partitions from GPT needed
 *
 * @return SAILUpdaterCoreStatusType_e [OUT]
 *   Status of the operation
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterCoreReconstructAltGPT (void *norHandle, uint32_t sourceGptId, boolean isSwapNeeded);

/**********************************************************
 * Check for Book keep Enabled
 *
 *
 * @param uint32_t *maxRetryCount [OUT]
 *   None
 *
 * @return boolean TRUE/FALSE[OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean bSAILUpdaterCoreIsBookkeepingEnabled(uint32_t *maxRetryCount);

/**********************************************************
 * Check if Book keep Erase needed before Write
 *
 *
 * @param
 *   None
 *
 * @return boolean TRUE/FALSE[OUT]
 *   Status of the Setting.
 *
 **********************************************************/
boolean bSAILUpdaterCoreIsBookkeepEraseWriteSet(void);

/**********************************************************
 * Gets the test Command ID
 *
 *
 * @param  None
 *
 * @return uint32_t test Command ID
 *
 **********************************************************/
uint32_t ulSAILUpdaterCoregetTestCmdID(void);

/**********************************************************
 * Check for Rollback Enabled
 *
 *
 * @param void
 *   None
 *
 * @return boolean TRUE/FALSE[OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean bSAILUpdaterCoreIsRollbackEnabled(void);

/**********************************************************
 * Fix Primary GPT Corruption based on OTA State Info
 *
 * @param norHandle [IN]
 *   Handle for the NOR flash
 *
 * @param xOtaStatus [IN]
 *   OTA State
 *
 * @param guidMap [IN]
 *   GUID Mapping
 *
 * @return SAILUpdaterCoreStatusType_e [OUT]
 *   Status of the operation
 **********************************************************/

SAILUpdaterStatusType_e xSAILUpdaterCoreFixCorruptPrimaryGPT(void *norHandle, SAILUpdaterOTAStateValType xOtaStatus, uint8_t guidMap);

/**********************************************************
 * Rollback the Primary GPT previous version
 *
 * @param norHandle [IN]
 *   Handle for the NOR flash
 *
 * @param xOtaStatus [IN]
 *   OTA State
 *
 * @param guidMap [IN]
 *   GUID Mapping
 *
 * @return SAILUpdaterCoreStatusType_e [OUT]
 *   Status of the operation
 **********************************************************/

SAILUpdaterStatusType_e xSAILUpdaterCoreRollbackPrimaryGPT(void *norHandle, SAILUpdaterOTAStateValType xOtaStatus, uint8_t guidMap);

/**********************************************************
 * Function to find true swap status
 *
 * @param norHandle [IN]
 *   Handle for the NOR flash
 *
 * @param pTrueSwap [IN]
 *    Is Swapping of the offsets of boot partitions is true
 *
 * @return SAILUpdaterCoreStatusType_e [OUT]
 *   Status of the operation
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterCoreGetTrueSwap ( void *norHandle, boolean *pTrueSwap);

/**********************************************************
 * Process the Get Image Digest
 *
 *
 * @param pReqMsg [IN]
 *   Pointer to the Request Message
 *
 * @param pRspMsg [IN/OUT]
 *   Pointer to the Response Message
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessGetImgDigest(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg);

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
/**********************************************************
 * Process the Test Injection Message
 *
 *
 * @param pReqMsg [IN]
 *   Pointer to the Request Message
 *
 * @param pRspMsg [IN/OUT]
 *   Pointer to the Response Message
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the operation.
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessTestInjection(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg);

/**********************************************************
 * Sets the test Command ID
 *
 *
 * @param  testCmdId
 *    Test Trigger ID
 *
 * @return void
 *    None
 *
 **********************************************************/
void ulSAILUpdaterCoreSetTestCmdID(uint32_t testCmdId);

#endif /* SAILUPDATER_INJTEST_SRC_ENABLED */

#endif /* __SAIL_UPDATER_CORE_H__ */
