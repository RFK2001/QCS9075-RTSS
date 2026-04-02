
/*
===========================================================================
*/
/**
    @file  sail_updater_otabookkeeping.c
    @brief Implementation of SAIL Updater Ota Book keep

*/
/*
    ===========================================================================

    Copyright (c) 2023-2025 Qualcomm Technologies, Inc.
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

#include "sail_updater_core.h"
#include "sail_updater_cmn.h"
#include "autosar_crc.h"
#include "cache_ops.h"
#include "debug_log.h"
#include "common_functions.h"
#include "spinor_el2_api.h"
#include "sail_updater_otabookkeep.h"
#include "err_fatal.h"
#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
#include "tests.h"
#endif

SAILUpdaterOTAStateValType currentOTAState = OTA_DISABLED;

/**********************************************************
 * Check for partition information corruption and collect info
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Result of the operation
 *
 **********************************************************/
static SAILUpdaterStatusType_e ePrvCheckBookkeepingInfo(SAILUpdaterOTARebootCtrlType* bookInfo, uint32_t* numEntries, uint32_t* numValidEntries, boolean *isFreshPart, boolean *isCorrputed)
{
    uint8_t otaStateTypeReadBuf[2];

    if ((NULL == numEntries) || (NULL == numValidEntries))
    {
         DEBUG_LOG(SAIL_ERROR,"%s: numEntries or numValidEntries is NULL \n\r",__func__);
         return SAIL_UPDATER_STATUS_FAIL;
    }
    *numEntries = 0;
    *numValidEntries = 0;

    /* Run through all the state entries */
    for (int i = (sizeof(bookInfo->OTAState) / sizeof(bookInfo->OTAState[0])) - 1; i >= 0; i -= 1)
    {
        DEBUG_LOG(SAIL_INFO,"%s: Partition Status-> otaState[%d].rawstate: 0x%x otaState[%d].crc: 0x%x\n\r",__func__, i,bookInfo->OTAState[i].rawState,
                  i,bookInfo->OTAState[i].crc);

        /* If Ota status Buffer has a non 0xFF value */
        if (bookInfo->OTAState[i].rawState != OTA_INVALID)
        {
            *numEntries = *numEntries + 1;
            *isFreshPart = FALSE;
            memset(otaStateTypeReadBuf, 0, 2);
            otaStateTypeReadBuf[0] = bookInfo->OTAState[i].rawState;

            /*CRC Validation for the state */
            otaStateTypeReadBuf[1] = ulAutosarCrc(AUTOSAR_CRC_32BIT_ETHERNET, otaStateTypeReadBuf, sizeof(otaStateTypeReadBuf));
            if(otaStateTypeReadBuf[1] != bookInfo->OTAState[i].crc)
            {
                *isCorrputed = TRUE;
                DEBUG_LOG(SAIL_WARNING, "%s:CRC not matching for item %d, OTA state value 0x%x\n\r", __func__, i, bookInfo->OTAState[i].rawStateExt.OTAState);
                continue;
            }
            /*Got Valid OTA state*/
            else
            {
                *numValidEntries = *numValidEntries + 1;
                DEBUG_LOG(SAIL_INFO,"%s:valid raw state[%d] 0x%x\n\r",__func__, i,bookInfo->OTAState[i].rawState);
                continue;
            }
        }
        else
        {
            continue;
        }
    }

    return SAIL_UPDATER_STATUS_SUCCESS;
}

/**********************************************************
 * Constructs the GUID Mapping of the GPT table based on the 2 GPTs
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Result of the Operation
 *
 **********************************************************/
static SAILUpdaterStatusType_e ePrvConstructOTAStateGUIDMap(uint8_t* update_guidMap)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;
    uint32_t PartitionCrcA=0, PartitionHdrCrcStatusA=0, PartitionEntryCrcStatusA=0;
    uint32_t PartitionCrcB=0, PartitionHdrCrcStatusB=0, PartitionEntryCrcStatusB=0;

    if (NULL == update_guidMap)
    {
        DEBUG_LOG(SAIL_ERROR,"%s:update_guidMap is NULL \n\r", __func__);
        return SAIL_UPDATER_STATUS_FAIL;
    }

    eStatus = xSAILUpdaterCoreVerifyGPTWrap(SAIL_UPD_GPT_ID_PRIMARY, &PartitionCrcA, &PartitionHdrCrcStatusA, &PartitionEntryCrcStatusA);
    if (SAIL_UPDATER_STATUS_SUCCESS != eStatus)
    {
        DEBUG_LOG(SAIL_ERROR,"%s:Verifying Primary GPT Header Failed \n\r", __func__);
        return eStatus;
    }

    eStatus = xSAILUpdaterCoreVerifyGPTWrap(SAIL_UPD_GPT_ID_SECONDARY, &PartitionCrcB, &PartitionHdrCrcStatusB, &PartitionEntryCrcStatusB);
    if (SAIL_UPDATER_STATUS_SUCCESS != eStatus)
    {
        DEBUG_LOG(SAIL_ERROR,"%s:Verifying Secondary GPT Header Failed \n\r", __func__);
        return eStatus;
    }

    DEBUG_LOG(SAIL_WARNING,"%s: GPT params PartitionHdrCrcStatusA:0x%x PartitionEntryCrcStatusA:0x%x PartitionCrcA:0x%x PartitionHdrCrcStatusB:0x%x PartitionEntryCrcStatusB:0x%x PartitionCrcB:0x%x) \n\r", __func__,
              PartitionHdrCrcStatusA, PartitionEntryCrcStatusA, PartitionCrcA, PartitionHdrCrcStatusB, PartitionEntryCrcStatusB, PartitionCrcB);

    /* If both GPTs are valid, and Partition Entry CRCs match, then logicalA -> PhysicalA  else logicalA -> PhysicalB */
    if ((1 == PartitionHdrCrcStatusA) && (1 == PartitionEntryCrcStatusA) && (1 == PartitionHdrCrcStatusB) && (1 == PartitionEntryCrcStatusB))
    {
        if (PartitionCrcA == PartitionCrcB)
        {
            *update_guidMap = 0;
        }
        else
        {
            *update_guidMap = 1;
        }
    }
    else
    {
        /* If Primary GPT is not valid */
        if ((0 == PartitionHdrCrcStatusA) || (0 == PartitionEntryCrcStatusA))
        {
            /* It is highly unlikely that the Primary GPT is corrupted and the book keeping partitions are also corrupted.
               But if the Secondary GPT is good (which should be since we booted till HYP) we should be able to boot with the images in Primary Partition.
               So set the guid Map to logicalA -> PhysicalA since we are relying on Secondary GPT and secondary GPT logicalA -> PhysicalA always.
               Fix GPT should fix erors in the Primary GPT based on the OTA state and corrupted OTA state should be handled
               later to update to a stable state (depending on the redundancy of images, OTA state and GPT state) */

            /* Check to ensure Secondary GPT is intact else error */
            if ((1 == PartitionHdrCrcStatusB) && (1 == PartitionEntryCrcStatusB))
            {
                *update_guidMap = 0;
            }
            else
            {
                *update_guidMap = 0;
                DEBUG_LOG(SAIL_ERROR,"%s:Both GPTs are bad. \n\r", __func__);
                return SAIL_UPDATER_STATUS_FAIL;
            }
        }
        else
        {
            /* Secondary GPT is not valid. This case should ideally not happen since the Secondary GPT should never be touched.
               We cannot construct the GUID mapping in this case since there is no reference to compare.
               Action needs to be taken by the OTA cloud to fix this error or vechicle should be taken to the service.
               Since Primary GPT is valid, proceeding with the assumption that current map is logicalA -> physicalA*/
            *update_guidMap = 0;
            DEBUG_LOG(SAIL_WARNING,"%s:Secondary GPT is bad. \n\r", __func__);
        }
    }
    return eStatus;
}

/**********************************************************
 * Updates the book keeping information to establish establish redundancy
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Result of the Operation
 *
 **********************************************************/
static SAILUpdaterStatusType_e ePrvUpdateBookRedundancy(void* norHandle, SAILUpdaterOTARebootCtrlType* rebootPart, boolean isEraseNeeded,
                                                            uint32_t PartitionOffset, uint32_t PartitionSize, uint32_t update_idx, uint32_t blockSize)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;
    SAILUpdaterOTARebootCtrlType temprebootPart = {0};

    if(update_idx >= (sizeof(rebootPart->OTAState) / sizeof(rebootPart->OTAState[0])))
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Invalid update_idx:%d \n\r", __func__,update_idx);
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        return eStatus;
    }

    if (TRUE == isEraseNeeded)
    {
        /* Erase and set both partitions to OTA_REBOOT_CORRUPTED */
        if ( SPINOR_DEVICE_DONE != spinorEl2Erase ((spinor_handle_t)norHandle, PartitionOffset / blockSize, PartitionSize / blockSize))
        {
            DEBUG_LOG(SAIL_ERROR,"%s:SPINOR Erase Failed \n\r", __func__);
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
            return eStatus;
        }
    }

    if( SPINOR_DEVICE_DONE != spinorEl2Write((spinor_handle_t)norHandle, PartitionOffset, sizeof(SAILUpdaterOTARebootCtrlType), (void *)rebootPart))
    {
        DEBUG_LOG(SAIL_ERROR,"%s: SPINOR Write  failed \n\r", __func__);
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        return eStatus;
    }
    /* Read from the partition again to verify the content */
    if( SPINOR_DEVICE_DONE != spinorEl2Read ( (spinor_handle_t)norHandle, PartitionOffset, sizeof(temprebootPart), (void *)&temprebootPart))
    {
        DEBUG_LOG(SAIL_ERROR,"%s: SPINOR Read back after write failed \n\r", __func__);
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        return eStatus;
    }

    /* Error if the Read values dont match */
    if ( (temprebootPart.OTAState[update_idx].crc != rebootPart->OTAState[update_idx].crc) ||
         (temprebootPart.OTAState[update_idx].rawState != rebootPart->OTAState[update_idx].rawState) )
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Verify failed for OTA State Readback state = 0x%x and readback CRC =0x%x \n\r", __func__,
                  temprebootPart.OTAState[update_idx].rawState, temprebootPart.OTAState[update_idx].crc);
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        return eStatus;
    }
    return eStatus;
}

/**********************************************************
 * Checks if the contents of the 2 partition's OTA states and CRCs match
 *
 * @return boolean [OUT]
 *   Status of the Operation
 *
 **********************************************************/
static boolean IsPartitionContentsMatching(SAILUpdaterOTARebootCtrlType *rebootPartA, SAILUpdaterOTARebootCtrlType *rebootPartB)
{
    for (int i =0; i < (sizeof(rebootPartA->OTAState)/sizeof(rebootPartA->OTAState[0]));i++)
    {
        if ( (rebootPartA->OTAState[i].rawState != rebootPartB->OTAState[i].rawState) ||
            (rebootPartA->OTAState[i].crc != rebootPartB->OTAState[i].crc)
            )
        {
            return FALSE;
        }
    }
    return TRUE;
}

/**********************************************************
 * Checks and Updates the book keeping information to establish redundancy
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Result of the Operation
 *
 **********************************************************/
static SAILUpdaterStatusType_e ePrvCheckBookRedundancy(void* norHandle)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;

    spinorMemInfoType memInfo = {0};
    uint32_t partitionAOffset= 0, partitionASize=0;
    uint32_t partitionBOffset= 0, partitionBSize=0;
    uint32_t blockSize=0;
    SAILUpdaterOTARebootCtrlType rebootPartA={0}, rebootPartB={0};

    uint8_t update_idx,idx,update_guidMap=0;
    uint32_t numEntriesA = 0, numValidEntriesA = 0, numEntriesB = 0, numValidEntriesB = 0, max_entries_possible=0;
    boolean isFreshPartA = TRUE, isFreshPartB = TRUE;
    boolean isCorrputedA = FALSE, isCorrputedB = FALSE;

    uint8_t otaStateTypeWriteBuf[2];
    size_t result;

    if (NULL == norHandle)
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Spinor handle passed is NULL \n\r", __func__);
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto CheckBookRedundancyEnd;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl2GetMemInfo((spinor_handle_t)norHandle, &memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Spinor Get Mem Info failed \n\r", __func__);
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto CheckBookRedundancyEnd;
    }

    /* Get reboot ctrl Primary partition Info */
    if( SPINOR_DEVICE_DONE != spinorEl2GetGptPartitionInfo((spinor_handle_t)norHandle, "bb7f4519-795e-471d-ac09-2d84c56cd253", &partitionAOffset, &partitionASize))
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Get Reboot Ctrl Primary Partition Info failed \n\r", __func__);
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto CheckBookRedundancyEnd;
    }

    /* Get reboot ctrl Secondary partition Info */
    if( SPINOR_DEVICE_DONE != spinorEl2GetGptPartitionInfo((spinor_handle_t)norHandle, "b5b5a557-ea43-461e-9be2-a028c9b841f4", &partitionBOffset, &partitionBSize))
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Get Reboot Ctrl Secondary Partition Info failed \n\r", __func__);
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto CheckBookRedundancyEnd;
    }

    /* Read from the Primary partition */
    if( SPINOR_DEVICE_DONE != spinorEl2Read ( (spinor_handle_t)norHandle, partitionAOffset, sizeof(rebootPartA), (void*)&rebootPartA))
    {
        DEBUG_LOG(SAIL_ERROR,"%s: SPINOR Read from Primary Partition failed \n\r", __func__);
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto CheckBookRedundancyEnd;
    }

    /* Read from the Secondary partition */
    if( SPINOR_DEVICE_DONE != spinorEl2Read ( (spinor_handle_t)norHandle, partitionBOffset, sizeof(rebootPartB), (void*)&rebootPartB))
    {
        DEBUG_LOG(SAIL_ERROR,"%s: SPINOR Read from Secondary partition failed \n\r", __func__);
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto CheckBookRedundancyEnd;
    }

    /* Check Primary partition corruption and collect info */
    if(SAIL_UPDATER_STATUS_SUCCESS != ePrvCheckBookkeepingInfo(&rebootPartA, &numEntriesA, &numValidEntriesA, &isFreshPartA, &isCorrputedA))
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Checking bookkeepingInfo from Primary partition failed \n\r", __func__);
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto CheckBookRedundancyEnd;
    }

    /* Check Secondary partition corruption and collect info */
    if(SAIL_UPDATER_STATUS_SUCCESS != ePrvCheckBookkeepingInfo(&rebootPartB, &numEntriesB, &numValidEntriesB, &isFreshPartB, &isCorrputedB))
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Checking bookkeepingInfo from Secondary partition failed \n\r", __func__);
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto CheckBookRedundancyEnd;
    }

    DEBUG_LOG(SAIL_WARNING,"%s: numEntriesA:0x%x, numValidEntriesA:0x%x, isFreshPartA:0x%x, isCorrputedA:0x%x \n\r",
              __func__, numEntriesA, numValidEntriesA, isFreshPartA, isCorrputedA);

    DEBUG_LOG(SAIL_WARNING,"%s: numEntriesB:0x%x, numValidEntriesB:0x%x, isFreshPartB:0x%x, isCorrputedB:0x%x \n\r",
              __func__, numEntriesB, numValidEntriesB, isFreshPartB, isCorrputedB);

    max_entries_possible = (sizeof(rebootPartA.OTAState) / sizeof(rebootPartA.OTAState[0]));

    if( (numEntriesA > max_entries_possible) || (numValidEntriesA > max_entries_possible) ||
        (numEntriesB > max_entries_possible) || (numValidEntriesB > max_entries_possible)
      )
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Number of entries or valid entries in A or B is exceeding max possible value \n\r", __func__);
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto CheckBookRedundancyEnd;
    }


    /* If both partitions are corrupted, Erase and set state to OTA_REBOOT_CORRUPTED */
    if ((TRUE == isCorrputedA) && (TRUE == isCorrputedB) )
    {
        if(SAIL_UPDATER_STATUS_SUCCESS != ePrvConstructOTAStateGUIDMap(&update_guidMap))
        {
            DEBUG_LOG(SAIL_ERROR,"%s: Constructing the OTA State GUID Map failed \n\r", __func__);
            eStatus = SAIL_UPDATER_STATUS_FAIL;
            goto CheckBookRedundancyEnd;
        }

        blockSize  = memInfo.pages_per_block * memInfo.page_size_bytes;
        update_idx = 0;

       /* Prepare the contents to write to the partitions */
        memset(&rebootPartA, 0xFF, sizeof(rebootPartA));
        /* Update Magic number */
        rebootPartA.xMagic.ulMagicNumber = 0x1;
        rebootPartA.xMagic.ulMagicNumCRC = ulAutosarCrc(AUTOSAR_CRC_32BIT_ETHERNET, (uint8_t *)(&rebootPartA.xMagic), sizeof(rebootPartA.xMagic.ulMagicNumber));


        rebootPartA.OTAState[update_idx].rawState = (update_guidMap<<7)|(OTA_REBOOT_CORRUPTED);
        memset(otaStateTypeWriteBuf, 0, 2);
        otaStateTypeWriteBuf[0] = rebootPartA.OTAState[update_idx].rawState;

        /* Calculate CRC */
        otaStateTypeWriteBuf[1] = ulAutosarCrc(AUTOSAR_CRC_32BIT_ETHERNET, otaStateTypeWriteBuf, sizeof(otaStateTypeWriteBuf));
        rebootPartA.OTAState[update_idx].crc = otaStateTypeWriteBuf[1];

        /* Update the contents in Primary partition */
        DEBUG_LOG(SAIL_WARNING,"%s: Setting state = 0x%x and CRC =0x%x at index %d in Primary partition \n\r", __func__, rebootPartA.OTAState[update_idx].rawState, rebootPartA.OTAState[update_idx].crc, update_idx);

        eStatus = ePrvUpdateBookRedundancy(norHandle, &rebootPartA, TRUE, partitionAOffset, partitionASize, update_idx, blockSize);
        if(SAIL_UPDATER_STATUS_SUCCESS != eStatus)
        {
            DEBUG_LOG(SAIL_ERROR,"%s:Updating OTA_REBOOT_CORRUPTED for Bookkeeping redundnancy for Primary partition Failed \n\r", __func__);
            goto CheckBookRedundancyEnd;
        }

        /* Update the contents in Secondary partition */
        DEBUG_LOG(SAIL_WARNING,"%s: Setting state = 0x%x and CRC = 0x%x at index %d in Secondary partition \n\r", __func__, rebootPartA.OTAState[update_idx].rawState, rebootPartA.OTAState[update_idx].crc, update_idx);
        eStatus = ePrvUpdateBookRedundancy(norHandle, &rebootPartA, TRUE, partitionBOffset, partitionBSize, update_idx, blockSize);
        if(SAIL_UPDATER_STATUS_SUCCESS != eStatus)
        {
            DEBUG_LOG(SAIL_ERROR,"%s:Updating OTA_REBOOT_CORRUPTED for Bookkeeping redundnancy for Secondary partition Failed \n\r", __func__);
            goto CheckBookRedundancyEnd;
        }
    }
    else
    {
        /* If both are fresh parts, Erase and set state to OTA_DISABLED */
        if ((TRUE == isFreshPartA) && (TRUE == isFreshPartB))
        {
            /* Erase and set both partitions to OTA_DISABLED */
            blockSize  = memInfo.pages_per_block * memInfo.page_size_bytes;
            update_guidMap = 0;
            update_idx = 0;

           /* Prepare the contents to write to the partitions */
            memset(&rebootPartA, 0xFF, sizeof(rebootPartA));

            /* Update Magic number */
            rebootPartA.xMagic.ulMagicNumber = 0x1;
            rebootPartA.xMagic.ulMagicNumCRC = ulAutosarCrc(AUTOSAR_CRC_32BIT_ETHERNET, (uint8_t *)&rebootPartA.xMagic, sizeof(rebootPartA.xMagic.ulMagicNumber));

            rebootPartA.OTAState[update_idx].rawState = (update_guidMap<<7)|OTA_DISABLED;
            memset(otaStateTypeWriteBuf, 0, 2);
            otaStateTypeWriteBuf[0] = rebootPartA.OTAState[update_idx].rawState;

            /* Calculate CRC */
            otaStateTypeWriteBuf[1] = ulAutosarCrc(AUTOSAR_CRC_32BIT_ETHERNET, otaStateTypeWriteBuf, sizeof(otaStateTypeWriteBuf));
            rebootPartA.OTAState[update_idx].crc = otaStateTypeWriteBuf[1];

            /* Update the contents in Primary partition */
            DEBUG_LOG(SAIL_WARNING,"%s: Setting state = 0x%x and CRC = 0x%x at index %d in Primary partition \n\r", __func__, rebootPartA.OTAState[update_idx].rawState, rebootPartA.OTAState[update_idx].crc, update_idx);

            eStatus = ePrvUpdateBookRedundancy(norHandle, &rebootPartA, TRUE, partitionAOffset, partitionASize, update_idx, blockSize);
            if(SAIL_UPDATER_STATUS_SUCCESS != eStatus)
            {
                DEBUG_LOG(SAIL_ERROR,"%s:Updating OTA_DISABLED for Bookkeeping redundnancy for Primary partition Failed \n\r", __func__);
                goto CheckBookRedundancyEnd;
            }

            /* Update the contents in Secondary partition */
            DEBUG_LOG(SAIL_WARNING,"%s: Setting state = 0x%x and CRC = 0x%x at index %d in Secondary partition \n\r", __func__, rebootPartA.OTAState[update_idx].rawState, rebootPartA.OTAState[update_idx].crc, update_idx);
            eStatus = ePrvUpdateBookRedundancy(norHandle, &rebootPartA, TRUE, partitionBOffset, partitionBSize, update_idx, blockSize);
            if(SAIL_UPDATER_STATUS_SUCCESS != eStatus)
            {
                DEBUG_LOG(SAIL_ERROR,"%s:Updating OTA_DISABLED for Bookkeeping redundnancy for Secondary partition Failed \n\r", __func__);
                goto CheckBookRedundancyEnd;
            }
        }
        else if (TRUE == isCorrputedA)
        {
            /* If Primary partition is corrupted, Erase Primary partition and copy contents from Secondary to Primary*/
            blockSize  = memInfo.pages_per_block * memInfo.page_size_bytes;
            update_idx = numValidEntriesB-1;

           /* Prepare the contents to write to the partition */
            memset(&rebootPartA, 0xFF, sizeof(rebootPartA));

            /* Update Magic number */
            rebootPartA.xMagic.ulMagicNumber = 0x1;
            rebootPartA.xMagic.ulMagicNumCRC = ulAutosarCrc(AUTOSAR_CRC_32BIT_ETHERNET, (uint8_t *)&rebootPartA.xMagic, sizeof(rebootPartA.xMagic.ulMagicNumber));

            result = sailbsp_memscpy(&rebootPartA, sizeof(rebootPartA), &rebootPartB, sizeof(rebootPartB));
            if(result == 0)
            {
                DEBUG_LOG(SAIL_ERROR,"%s: Copying contents from rebootB buffer to rebootA buffer failed \n\r", __func__);
                eStatus = SAIL_UPDATER_STATUS_FAIL;
                goto CheckBookRedundancyEnd;
            }

            /* Update the contents in Primary partition */
            DEBUG_LOG(SAIL_WARNING,"%s: Copying Secondary partition contents to Primary partition to fix Primary's corruption \n\r", __func__);

            eStatus = ePrvUpdateBookRedundancy(norHandle, &rebootPartA, TRUE, partitionAOffset, partitionASize, update_idx, blockSize);
            if(SAIL_UPDATER_STATUS_SUCCESS != eStatus)
            {
                DEBUG_LOG(SAIL_ERROR,"%s:Copying Secondary partition contents to Primary partition to fix Primary's corruption Failed \n\r", __func__);
                goto CheckBookRedundancyEnd;
            }
        }
        else if (TRUE == isCorrputedB)
        {
            /* If Secondary partition is corrupted, Erase Secondary partition and copy contents from Primary to Secondary*/
            blockSize  = memInfo.pages_per_block * memInfo.page_size_bytes;
            update_idx = numValidEntriesA-1;

           /* Prepare the contents to write to the partition */
            memset(&rebootPartB, 0xFF, sizeof(rebootPartB));

            /* Update Magic number */
            rebootPartB.xMagic.ulMagicNumber = 0x1;
            rebootPartB.xMagic.ulMagicNumCRC = ulAutosarCrc(AUTOSAR_CRC_32BIT_ETHERNET, (uint8_t *)&rebootPartB.xMagic, sizeof(rebootPartB.xMagic.ulMagicNumber));

            result = sailbsp_memscpy(&rebootPartB, sizeof(rebootPartB), &rebootPartA, sizeof(rebootPartA));
            if(result == 0)
            {
                DEBUG_LOG(SAIL_ERROR,"%s: Copying contents from rebootA buffer to rebootB buffer failed \n\r", __func__);
                eStatus = SAIL_UPDATER_STATUS_FAIL;
                goto CheckBookRedundancyEnd;
            }

            /* Update the contents in Secondary partition */
            DEBUG_LOG(SAIL_WARNING,"%s: Copying Primary partition contents to Secondary partition to fix Secondary's corruption \n\r", __func__);

            eStatus = ePrvUpdateBookRedundancy(norHandle, &rebootPartB, TRUE, partitionBOffset, partitionBSize, update_idx, blockSize);
            if(SAIL_UPDATER_STATUS_SUCCESS != eStatus)
            {
                DEBUG_LOG(SAIL_ERROR,"%s:Copying Primary partition contents to Secondary partition to fix Secondary's corruption Failed \n\r", __func__);
                goto CheckBookRedundancyEnd;
            }
        }
        else
        {
            /* Both partitions are valid. Safety check to see if the valid entries match the number of actual entries in each partition */
            if ((numEntriesA!=numValidEntriesA) || (numEntriesB!=numValidEntriesB))
            {
                DEBUG_LOG(SAIL_ERROR,"%s: NumValidEntries not match NumEntries. numEntriesA:0x%x numValidEntriesA:0x%x numEntriesB:0x%x numValidEntriesB:0x%x \n\r",
                          __func__, numEntriesA, numValidEntriesA, numEntriesB, numValidEntriesB);
                eStatus = SAIL_UPDATER_STATUS_FAIL;
                goto CheckBookRedundancyEnd;
            }

            /* Check if the contents in both partitions are matching */
            if (FALSE == IsPartitionContentsMatching(&rebootPartA, &rebootPartB))
            {
                if (1 == numEntriesA)
                {
                    /* If number of entries in Primary partition  is just 1, Secondary partition is not yet updated.Erase Secondary partition
                       and copy Primary contents to Secondary */
                    blockSize  = memInfo.pages_per_block * memInfo.page_size_bytes;
                    update_idx = numValidEntriesA-1;

                   /* Prepare the contents to write to the partition */
                    memset(&rebootPartB, 0xFF, sizeof(rebootPartB));
                    /* Update Magic number */
                    rebootPartB.xMagic.ulMagicNumber = 0x1;
                    rebootPartB.xMagic.ulMagicNumCRC = ulAutosarCrc(AUTOSAR_CRC_32BIT_ETHERNET, (uint8_t *)&rebootPartB.xMagic, sizeof(rebootPartB.xMagic.ulMagicNumber));

                    result = sailbsp_memscpy(&rebootPartB, sizeof(rebootPartB), &rebootPartA, sizeof(rebootPartA));
                    if(result == 0)
                    {
                        DEBUG_LOG(SAIL_ERROR,"%s: Copying contents from rebootA buffer to rebootB buffer failed \n\r", __func__);
                        eStatus = SAIL_UPDATER_STATUS_FAIL;
                        goto CheckBookRedundancyEnd;
                    }

                    /* Update the contents in Secondary partition */
                    DEBUG_LOG(SAIL_WARNING,"%s: Copying Primary partition contents to Secondary partition to match the contents after erase \n\r", __func__);

                    eStatus = ePrvUpdateBookRedundancy(norHandle, &rebootPartB, TRUE, partitionBOffset, partitionBSize, update_idx, blockSize);
                    if(SAIL_UPDATER_STATUS_SUCCESS != eStatus)
                    {
                        DEBUG_LOG(SAIL_ERROR,"%s:Copying Primary partition contents to Secondary partition to match the contents after erase Failed \n\r", __func__);
                        goto CheckBookRedundancyEnd;
                    }
                }
                else
                {
                    if (numEntriesA == numEntriesB)
                    {
                        DEBUG_LOG(SAIL_ERROR,"%s:Number of entries in both partition are same. But contents not matching is an error\n\r", __func__);
                        eStatus = SAIL_UPDATER_STATUS_FAIL;
                        goto CheckBookRedundancyEnd;
                    }
                    /* If number of entries in A is more than B, update B */
                    if (numEntriesA > numEntriesB)
                    {

                        blockSize  = memInfo.pages_per_block * memInfo.page_size_bytes;
                        update_idx = numValidEntriesA-1;

                       /* Prepare the contents to write to the partition */
                        memset(&rebootPartB, 0xFF, sizeof(rebootPartB));
                        /* Update Magic number */
                        rebootPartB.xMagic.ulMagicNumber = 0x1;
                        rebootPartB.xMagic.ulMagicNumCRC = ulAutosarCrc(AUTOSAR_CRC_32BIT_ETHERNET, (uint8_t *)&rebootPartB.xMagic, sizeof(rebootPartB.xMagic.ulMagicNumber));

                        result = sailbsp_memscpy(&rebootPartB, sizeof(rebootPartB), &rebootPartA, sizeof(rebootPartA));
                        if(result == 0)
                        {
                            DEBUG_LOG(SAIL_ERROR,"%s: Copying contents from rebootA buffer to rebootB buffer failed\n\r", __func__);
                            eStatus = SAIL_UPDATER_STATUS_FAIL;
                            goto CheckBookRedundancyEnd;
                        }

                        /* Update the contents in Secondary partition */
                        DEBUG_LOG(SAIL_WARNING,"%s: Copying Primary partition contents to Secondary partition to match the contents\n\r", __func__);

                        eStatus = ePrvUpdateBookRedundancy(norHandle, &rebootPartB, TRUE, partitionBOffset, partitionBSize, update_idx, blockSize);
                        if(SAIL_UPDATER_STATUS_SUCCESS != eStatus)
                        {
                            DEBUG_LOG(SAIL_ERROR,"%s:Copying Primary partition contents to Secondary partition to match the contents Failed\n\r", __func__);
                            goto CheckBookRedundancyEnd;
                        }
                    }
                    else
                    {
                        /* If number of entries in A is less than B, update A. This can happen if there is a power loss while fixing A  */
                        blockSize  = memInfo.pages_per_block * memInfo.page_size_bytes;
                        update_idx = numValidEntriesB-1;

                       /* Prepare the contents to write to the partition */
                        memset(&rebootPartA, 0xFF, sizeof(rebootPartA));

                        /* Update Magic number */
                        rebootPartA.xMagic.ulMagicNumber = 0x1;
                        rebootPartA.xMagic.ulMagicNumCRC = ulAutosarCrc(AUTOSAR_CRC_32BIT_ETHERNET, (uint8_t *)&rebootPartA.xMagic, sizeof(rebootPartA.xMagic.ulMagicNumber));

                        result = sailbsp_memscpy(&rebootPartA, sizeof(rebootPartA), &rebootPartB, sizeof(rebootPartB));
                        if(result == 0)
                        {
                            DEBUG_LOG(SAIL_ERROR,"%s: Copying contents from rebootB buffer to rebootA buffer failed \n\r", __func__);
                            eStatus = SAIL_UPDATER_STATUS_FAIL;
                            goto CheckBookRedundancyEnd;
                        }

                        /* Update the contents in Primary partition */
                        DEBUG_LOG(SAIL_WARNING,"%s: Copying Secondary partition contents to Primary partition to match the contents\n\r", __func__);

                        eStatus = ePrvUpdateBookRedundancy(norHandle, &rebootPartA, TRUE, partitionAOffset, partitionASize, update_idx, blockSize);
                        if(SAIL_UPDATER_STATUS_SUCCESS != eStatus)
                        {
                            DEBUG_LOG(SAIL_ERROR,"%s:Copying Secondary partition contents to Primary partition to match the contents Failed\n\r", __func__);
                            goto CheckBookRedundancyEnd;
                        }
                    }
                }
            }
            else
            {
                /* Do nothing. Contents matching */
            }
        }
    }

CheckBookRedundancyEnd:
    return eStatus;
}

/**********************************************************
 * Update Retry Count
 *
 * @param handle [IN]
 *   Handle for the NOR flash
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the Operation
 *
 **********************************************************/
static SAILUpdaterStatusType_e ePrvUpdateRetryCount(void *norHandle)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;
    uint8_t *otaRetryBuffPtr = NULL ;

    uint32_t partitionAOffset= 0, partitionASize=0;
    uint32_t partitionBOffset= 0, partitionBSize=0;
    SAILUpdaterOTARebootCtrlType rebootPartA={0};
    spinorMemInfoType memInfo = {0};
    uint32_t blockSizeBytes=0;

    boolean sail_updater_book_erase_write = FALSE;

    if (NULL == norHandle)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterUpdateRetryCount: Spinor handle passed is NULL \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto UpdateRetryCountEnd;
    }

    sail_updater_book_erase_write = bSAILUpdaterCoreIsBookkeepEraseWriteSet();

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl2GetMemInfo((spinor_handle_t)norHandle, &memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterUpdateRetryCount: Spinor Get Mem Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto UpdateRetryCountEnd;
    }

    /* Get reboot ctrl Primary partition Info */
    if( SPINOR_DEVICE_DONE != spinorEl2GetGptPartitionInfo((spinor_handle_t)norHandle, "bb7f4519-795e-471d-ac09-2d84c56cd253", &partitionAOffset, &partitionASize) )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterUpdateRetryCount: Get Reboot Ctrl Primary Partition Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto UpdateRetryCountEnd;
    }

    /* Get reboot ctrl Secondary partition Info */
    if( SPINOR_DEVICE_DONE != spinorEl2GetGptPartitionInfo((spinor_handle_t)norHandle, "b5b5a557-ea43-461e-9be2-a028c9b841f4", &partitionBOffset, &partitionBSize))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterUpdateRetryCount: Get Reboot Ctrl Secondary Partition Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto UpdateRetryCountEnd;
    }

    /* Read from the partition */
    if( SPINOR_DEVICE_DONE !=  spinorEl2Read ( (spinor_handle_t)norHandle, partitionAOffset, sizeof(rebootPartA), (void *)&rebootPartA))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterUpdateRetryCount: SPINOR Read failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto UpdateRetryCountEnd;
    }

    otaRetryBuffPtr = (uint8_t *)&rebootPartA.RetryCnt[0];

    /* check for FF and update the entry there */
    for (uint32_t i=0;i<sizeof(rebootPartA.RetryCnt);i++)
    {
        DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterUpdateRetryCount: otaRetryBuff[%d]: %d\n\r", i,otaRetryBuffPtr[i]);
        if (otaRetryBuffPtr[i]==0xFF)
        {
            DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterUpdateRetryCount: retry count position %d\n\r", i);
            otaRetryBuffPtr[i] = 0x0;
            break;
        }
    }

    if (TRUE == sail_updater_book_erase_write)
    {
        /* Always erase the bookkeeping partition */
        blockSizeBytes  = memInfo.pages_per_block * memInfo.page_size_bytes;
        DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterUpdateRetryCount: Erasing Primary Partition \n\r");
        if ( SPINOR_DEVICE_DONE != spinorEl2Erase ((spinor_handle_t)norHandle, partitionAOffset / blockSizeBytes, partitionASize/blockSizeBytes))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterUpdateRetryCount:spinorEl1Erase Failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
            goto UpdateRetryCountEnd;
        }
        /*Write retry count to the Primary Partition */
        if( SPINOR_DEVICE_DONE != spinorEl2Write((spinor_handle_t)norHandle, partitionAOffset, sizeof(SAILUpdaterOTARebootCtrlType), (void *)&rebootPartA) )
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterUpdateRetryCount: Write retry count to Primary partition failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
            goto UpdateRetryCountEnd;
        }
    }
    else
    {
        /*Write retry count to the Primary Partition */
        if( SPINOR_DEVICE_DONE != spinorEl2Write((spinor_handle_t)norHandle, partitionAOffset+((uint32_t)&rebootPartA.RetryCnt[0]-(uint32_t)&rebootPartA), sizeof(rebootPartA.RetryCnt), (void *)otaRetryBuffPtr))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterUpdateRetryCount: Write retry count to Primary partition failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
            goto UpdateRetryCountEnd;
        }
    }

    if (TRUE == sail_updater_book_erase_write)
    {
        DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterUpdateRetryCount: Erasing Secondary Partition \n\r");
        blockSizeBytes  = memInfo.pages_per_block * memInfo.page_size_bytes;
        if ( SPINOR_DEVICE_DONE != spinorEl2Erase ((spinor_handle_t)norHandle, partitionBOffset / blockSizeBytes, partitionBSize/blockSizeBytes))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterUpdateRetryCount:Erasing Secondary Partition Failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
            goto UpdateRetryCountEnd;
        }

        /*Write retry count to the Secondary Partition */
        if( SPINOR_DEVICE_DONE != spinorEl2Write((spinor_handle_t)norHandle, partitionBOffset, sizeof(SAILUpdaterOTARebootCtrlType), (void *)&rebootPartA) )
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterUpdateRetryCount: Write retry count to Secondary partition failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
            goto UpdateRetryCountEnd;
        }
    }
    else
    {
        /*Write retry count to the Secondary Partition */
        if( SPINOR_DEVICE_DONE != spinorEl2Write((spinor_handle_t)norHandle, partitionBOffset+((uint32_t)&rebootPartA.RetryCnt[0]-(uint32_t)&rebootPartA), sizeof(rebootPartA.RetryCnt), (void *)otaRetryBuffPtr) )
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterUpdateRetryCount: Write retry count to Secondary partition failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
            goto UpdateRetryCountEnd;
        }
    }

UpdateRetryCountEnd:
    return eStatus;
}

/**********************************************************
 * Get Retry Count
 *
 * @param handle [IN]
 *   Handle for the NOR flash
 *
 * @param pRetryCount [IN/OUT]
 *   Pointer to the Retry Count
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the Operation
 **********************************************************/
static SAILUpdaterStatusType_e ePrvGetRetryCount(void *norHandle, uint32_t *pRetryCount)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;
    uint8_t *otaRetryBuffPtr = NULL ;
    uint32_t partitionAOffset= 0, partitionASize=0;
    SAILUpdaterOTARebootCtrlType rebootPartA={0};

    if (pRetryCount == NULL)
    {
       DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetRetryCount: pRetryCount is NULL\n\r");
       eStatus =  SAIL_UPDATER_STATUS_FAIL;
       goto GetRetryCountEnd;
    }

    if (NULL == norHandle)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetRetryCount: Spinor handle passed is NULL \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto GetRetryCountEnd;
    }

    /* Get reboot ctrl Primary partition Info */
    if( SPINOR_DEVICE_DONE != spinorEl2GetGptPartitionInfo((spinor_handle_t)norHandle, "bb7f4519-795e-471d-ac09-2d84c56cd253",  &partitionAOffset, &partitionASize))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetRetryCount: Get Reboot Ctrl Primary Partition Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto GetRetryCountEnd;
    }
    /* Read from the partition */
    if( SPINOR_DEVICE_DONE != spinorEl2Read ( (spinor_handle_t)norHandle, partitionAOffset, sizeof(rebootPartA), (void *)&rebootPartA))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetRetryCount: SPINOR Read failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto GetRetryCountEnd;
    }

    otaRetryBuffPtr = (uint8_t *)&rebootPartA.RetryCnt[0];

    /* check for FF */
    for (uint32_t i=0;i<sizeof(rebootPartA.RetryCnt);i++)
    {
        DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetRetryCount: otaRetryBuff[%d]: %d\n\r", i,otaRetryBuffPtr[i]);
        if (otaRetryBuffPtr[i]==0xFF)
        {
            DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetRetryCount: retry count: %d\n\r", i);
            *pRetryCount = i;
            break;
        }
    }

GetRetryCountEnd:
    return eStatus;
}

/**********************************************************
 * Gets the index of the empty slot for the state in the partition
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Result of the operation
 *
 **********************************************************/
static SAILUpdaterStatusType_e ePrvGetEmptySlotIdx(SAILUpdaterOTAStateType* OTAState, uint32_t maxSize, uint8_t *idx)
{
    uint32_t i;

    for (i =0; i<maxSize;i++)
    {
        if (0xFF == OTAState[i].rawState)
        {
            break;
        }
    }
    *idx = i;
    return SAIL_UPDATER_STATUS_SUCCESS;
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
boolean bSAILUpdaterOtaBookIsBootOTA(void)
{
    if (currentOTAState == OTA_BOOTING)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
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
SAILUpdaterOTAStateValType xSAILUpdaterOtaBookGetCurrentOTAState(void)
{
    return currentOTAState;
}

static SAILUpdaterStatusType_e ePrvCheckBookB(void* norHandle, boolean *isFresh)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;

    spinorMemInfoType memInfo = {0};
    uint32_t partitionBOffset= 0, partitionBSize=0;
    SAILUpdaterOTARebootCtrlType rebootPartB={0};

    uint32_t numEntriesB = 0, numValidEntriesB = 0;
    boolean isFreshPartB = TRUE;
    boolean isCorrputedB = FALSE;

    uint8_t otaStateTypeWriteBuf[2];
    size_t result;

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl2GetMemInfo((spinor_handle_t)norHandle, &memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Spinor Get Mem Info failed \n\r", __func__);
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        isFreshPartB = FALSE;
        goto CheckBookEnd;
    }

    /* Get reboot ctrl Secondary partition Info */
    if( SPINOR_DEVICE_DONE != spinorEl2GetGptPartitionInfo((spinor_handle_t)norHandle, "b5b5a557-ea43-461e-9be2-a028c9b841f4", &partitionBOffset, &partitionBSize))
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Get Reboot Ctrl Secondary Partition Info failed \n\r", __func__);
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        isFreshPartB = FALSE;
        goto CheckBookEnd;
    }

    /* Read from the Secondary partition */
    if( SPINOR_DEVICE_DONE != spinorEl2Read ( (spinor_handle_t)norHandle, partitionBOffset, sizeof(rebootPartB), (void*)&rebootPartB))
    {
        DEBUG_LOG(SAIL_ERROR,"%s: SPINOR Read from Secondary partition failed \n\r", __func__);
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        isFreshPartB = FALSE;
        goto CheckBookEnd;
    }

    /* Check Secondary partition corruption and collect info */
    if(SAIL_UPDATER_STATUS_SUCCESS != ePrvCheckBookkeepingInfo(&rebootPartB, &numEntriesB, &numValidEntriesB, &isFreshPartB, &isCorrputedB))
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Checking bookkeepingInfo from Secondary partition failed \n\r", __func__);
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        isFreshPartB = FALSE;
        goto CheckBookEnd;
    }

CheckBookEnd:
    *isFresh = isFreshPartB;
     return eStatus;
}

SAILUpdaterStatusType_e xSAILUpdaterForceOtaStatus (void *norHandle, SAILUpdaterOTAStateValType state)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;
    spinorMemInfoType memInfo = {0};
    boolean is_erase_needed = FALSE;
    uint32_t partitionAOffset= 0, partitionASize=0;
    uint32_t partitionBOffset= 0, partitionBSize=0;
    uint32_t blockSizeBytes=0;
    SAILUpdaterOTARebootCtrlType rebootPartA={0}, rebootPartB={0}, temprebootPart = {0};
    uint8_t update_idx,idx,update_guidMap;
    uint8_t last_raw_state,last_state, last_guidMap, last_CRC ;

    uint8_t otaStateTypeWriteBuf[2];
    uint8_t otaStateValidateBuf[2];
    boolean sail_updater_book_erase_write = FALSE;

    if (NULL == norHandle)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterForceOtaStatus: Spinor handle passed is NULL \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ForceOtaStatusEnd;
    }

    sail_updater_book_erase_write = bSAILUpdaterCoreIsBookkeepEraseWriteSet();

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl2GetMemInfo((spinor_handle_t)norHandle, &memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterForceOtaStatus: Spinor Get Mem Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ForceOtaStatusEnd;
    }

    /* Get reboot ctrl Primary partition Info */
    if( SPINOR_DEVICE_DONE != spinorEl2GetGptPartitionInfo((spinor_handle_t)norHandle, "bb7f4519-795e-471d-ac09-2d84c56cd253", &partitionAOffset, &partitionASize))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterForceOtaStatus: Get Reboot Ctrl Primary Partition Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ForceOtaStatusEnd;
    }

    /* Get reboot ctrl Secondary partition Info */
    if( SPINOR_DEVICE_DONE != spinorEl2GetGptPartitionInfo((spinor_handle_t)norHandle, "b5b5a557-ea43-461e-9be2-a028c9b841f4", &partitionBOffset, &partitionBSize))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterForceOtaStatus: Get Reboot Ctrl Secondary Partition Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ForceOtaStatusEnd;
    }

    /* Read from the Primary partition */
    if( SPINOR_DEVICE_DONE != spinorEl2Read ( (spinor_handle_t)norHandle, partitionAOffset, sizeof(rebootPartA), (void *)&rebootPartA))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterForceOtaStatus: SPINOR Read failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ForceOtaStatusEnd;
    }

    if(SAIL_UPDATER_STATUS_SUCCESS != ePrvGetEmptySlotIdx(&rebootPartA.OTAState[0], (sizeof(rebootPartA.OTAState)/sizeof(rebootPartA.OTAState[0])) , &idx))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterForceOtaStatus:Getting last index failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ForceOtaStatusEnd;
    }

    DEBUG_LOG(SAIL_INFO,"xSAILUpdaterForceOtaStatus:Empty slot at index %d \n\r", idx);

    /* error. index cannot be 0. proper values should have been fixed during bootup itself */
    if (0 == idx)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterForceOtaStatus:Reboot partition cannot empty, index is 0 \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ForceOtaStatusEnd;
    }

    /* Get the values at the last index */
    last_raw_state = rebootPartA.OTAState[idx - 1].rawState;
    last_state = last_raw_state & 0x7F;
    last_guidMap = (last_raw_state&0x80)>>0x7;
    last_CRC = rebootPartA.OTAState[idx - 1].crc;

    DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterForceOtaStatus:Values at last index[%d] -> last_raw_state=0x%x last_state=0x%x last_guidMap=0x%x last_CRC=0x%x \n\r",
              (idx-1),last_raw_state, last_state, last_guidMap, last_CRC);

    /* validate values at the last index */
    memset(otaStateValidateBuf, 0, 2);
    otaStateValidateBuf[0] = last_raw_state;
    /* Calculate CRC */
    otaStateValidateBuf[1] = ulAutosarCrc(AUTOSAR_CRC_32BIT_ETHERNET, otaStateValidateBuf, sizeof(otaStateValidateBuf));

    /* Check for CRC match, if not Matching  error out */
    if(otaStateValidateBuf[1] != last_CRC)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterForceOtaStatus:last state value 0x%x and CRC 0x%x does not match at index %d \n\r", last_raw_state, last_CRC,(idx - 1));
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ForceOtaStatusEnd;
    }

    update_guidMap = last_guidMap;
    is_erase_needed = FALSE;
    update_idx = idx;

    /* If index reached end of buffer, get the last state and erase and write */
    if (idx >= (sizeof(rebootPartA.OTAState)/sizeof(rebootPartA.OTAState[0])))
    {
        DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterForceOtaStatus:Erasing partition due to end of buffer reached \n\r");
        is_erase_needed = TRUE;
        update_idx = 0;
    }

    /* Erase the bookkeeping partition if erasebookkeping before write it set or if erase is needed */
    if ((TRUE == sail_updater_book_erase_write) || (TRUE == is_erase_needed))
    {
        blockSizeBytes  = memInfo.pages_per_block * memInfo.page_size_bytes;
        if (SPINOR_DEVICE_DONE != spinorEl2Erase((spinor_handle_t)norHandle, partitionAOffset / blockSizeBytes, partitionASize / blockSizeBytes)) {
            DEBUG_LOG(SAIL_ERROR, "xSAILUpdaterForceOtaStatus:spinorEl1Erase Failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
            goto ForceOtaStatusEnd;
        }
    }

    /* Reset the contents for the partitions only if erase is needed. Should not be set to FFs if erase before write case */
    if (TRUE == is_erase_needed)
    {
        /*Set the contents to 0xFF */
        memset(&rebootPartA, 0xFF, sizeof(rebootPartA));
    }

    /* Update Magic number */
    rebootPartA.xMagic.ulMagicNumber = 0x1;
    rebootPartA.xMagic.ulMagicNumCRC = ulAutosarCrc(AUTOSAR_CRC_32BIT_ETHERNET, (uint8_t *)&rebootPartA.xMagic, sizeof(rebootPartA.xMagic.ulMagicNumber));

    rebootPartA.OTAState[update_idx].rawState = (update_guidMap<<7)|(state);

    /*Write Status Offset*/
    memset(otaStateTypeWriteBuf, 0, 2);
    otaStateTypeWriteBuf[0] = rebootPartA.OTAState[update_idx].rawState;

    /* Calculate CRC */
    otaStateTypeWriteBuf[1] = ulAutosarCrc(AUTOSAR_CRC_32BIT_ETHERNET, otaStateTypeWriteBuf, sizeof(otaStateTypeWriteBuf));
    rebootPartA.OTAState[update_idx].crc = otaStateTypeWriteBuf[1];

    DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterForceOtaStatus: Setting state = 0x%x and CRC = 0x%x at index %d\n\r", rebootPartA.OTAState[update_idx].rawState, rebootPartA.OTAState[update_idx].crc, update_idx);

    if( SPINOR_DEVICE_DONE != spinorEl2Write((spinor_handle_t)norHandle, partitionAOffset, sizeof(rebootPartA), (void *) &rebootPartA))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterForceOtaStatus: Write OTA status failure for Primary partition \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ForceOtaStatusEnd;
    }

    /* Read from the partition again to verify the content */
    if( SPINOR_DEVICE_DONE != spinorEl2Read ( (spinor_handle_t)norHandle, partitionAOffset, sizeof(temprebootPart), (void *) &temprebootPart))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterForceOtaStatus: SPINOR Read back after write to Primary partition failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ForceOtaStatusEnd;
    }

    /* Error if the Read values dont match */
    if ( (temprebootPart.OTAState[update_idx].crc != rebootPartA.OTAState[update_idx].crc) ||
         (temprebootPart.OTAState[update_idx].rawState != rebootPartA.OTAState[update_idx].rawState) )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterForceOtaStatus: Verify failed for OTA State in Primary partition Readback state = 0x%x and readback CRC = 0x%x \n\r",
                  temprebootPart.OTAState[update_idx].rawState, temprebootPart.OTAState[update_idx].crc);
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ForceOtaStatusEnd;
    }

    currentOTAState = state;

    /* Re-do the same for the Secondary Reboot Ctrl Partition */
    /* Erase the bookkeeping partition if erasebookkeping before write it set or if erase is needed */
    if ((TRUE == sail_updater_book_erase_write) || (TRUE == is_erase_needed))
    {
        DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterForceOtaStatus: Erasing Secondary Partition \n\r");
        blockSizeBytes  = memInfo.pages_per_block * memInfo.page_size_bytes;
        if ( SPINOR_DEVICE_DONE != spinorEl2Erase ((spinor_handle_t)norHandle, partitionBOffset / blockSizeBytes, partitionBSize/blockSizeBytes))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterForceOtaStatus:Erasing Secondary Partition Failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
            goto ForceOtaStatusEnd;
        }
    }

    /* Update the Secondary Reboot Ctrl Partition */
    DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterForceOtaStatus: Updating Secondary Partition state = 0x%x and CRC = 0x%x at index %d\n\r", temprebootPart.OTAState[update_idx].rawState, temprebootPart.OTAState[update_idx].crc, update_idx);
    if( SPINOR_DEVICE_DONE != spinorEl2Write((spinor_handle_t)norHandle, partitionBOffset, sizeof(temprebootPart), (void *) &temprebootPart))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterForceOtaStatus: Write OTA status failure for Secondary partition\n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ForceOtaStatusEnd;
    }

    /* Read from the partition again to verify the content */
    if( SPINOR_DEVICE_DONE != spinorEl2Read ( (spinor_handle_t)norHandle, partitionBOffset, sizeof(rebootPartB), (void *) &rebootPartB))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterForceOtaStatus: SPINOR Read back after write to Secondary partition failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ForceOtaStatusEnd;
    }

    /* Error if the Read values dont match */
    if ( (temprebootPart.OTAState[update_idx].crc != rebootPartB.OTAState[update_idx].crc) ||
         (temprebootPart.OTAState[update_idx].rawState != rebootPartB.OTAState[update_idx].rawState) )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterForceOtaStatus: Verify failed for OTA State in Secondary partition Readback state = 0x%x and readback CRC = 0x%x \n\r",
                  rebootPartB.OTAState[update_idx].rawState, rebootPartB.OTAState[update_idx].crc);
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ForceOtaStatusEnd;
    }

    currentOTAState = state;

ForceOtaStatusEnd:
    return eStatus;
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
SAILUpdaterStatusType_e xSAILUpdaterOtaBookGetLdrFlow(boolean *bootType)
{
    SAILUpdaterOTAStateValType xOtaStatus;
    SAILUpdaterStatusType_e xCreateResult = SAIL_UPDATER_STATUS_SUCCESS;
    uint32_t primCrc=0, secCrc=0;
    uint32_t xRetryCount=0;
    uint32_t maxRetryCount=0;
    uint32_t primHdrCrcStatus =0, primEntryCrcStatus=0, secHdrCrcStatus=0, secEntryCrcStatus=0;
    uint8_t guidMap = 0;
    boolean rollbackEn=FALSE;
    boolean isBookBFresh = FALSE;
    boolean bValid = FALSE;
    uint32_t ulMagicNum = 0xFF;
    boolean bTrueSwap = FALSE;

    spinor_handle_t norHandle = NULL;

    /* Initialize the SAIL Updater Core layer */
    if(SAIL_UPDATER_SUCCESS != xSAILUpdaterCoreInit())
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: Updater Core Initialization Failed \n\r");
        xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
        goto GetLoaderFlowEnd;
    }

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    extern uint32_t sailUpdaterInjEL2testTriggerId;

    /** ==========================================================================================================

        Use either Option 1 or Option 2 for testing. This cannot be enabled for production

       ========================================================================================================== */

    /** ========================= Option 1 ====================================================================== */

    /**  Test code to send testID commands using UART. But this has timing issues to boot the system.
        This cannot be enabled for mainline or production. Only purpose is for developer testing
        to save recompilation of different testIDs in DTB and flashing image.
        To use this feature, reading the entry from device tree using the line
               sailUpdaterInjEL2testTriggerId = ulSAILUpdaterCoregetTestCmdID();
        needs to be commented out
     */

//  DEBUG_LOG(SAIL_WARNING,"Enter SAILUpdater Injection testID command \n\r");
//  DEBUG_LOG(SAIL_WARNING,"sailupdaterinj testID \n\r");
//
//  vTestModuleInit();
//
//  vSailUpdaterInjTestLoop();

//  ulSAILUpdaterCoreSetTestCmdID(sailUpdaterInjEL2testTriggerId);

    /** ============================ Option 2 =================================================================== */

    /** Read from Device tree */
    sailUpdaterInjEL2testTriggerId = ulSAILUpdaterCoregetTestCmdID();

    /** ========================================================================================================= */

    DEBUG_LOG(SAIL_WARNING, "xSAILUpdaterGetLoaderFlow: vSailUpdaterInjTestLoop returned test id %d \n\r", sailUpdaterInjEL2testTriggerId);
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    if (FALSE == bSAILUpdaterCoreIsBookkeepingEnabled(&maxRetryCount))
    {
        DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetLoaderFlow: Book Keeping Disabled\n\r");
        /*Boot Type is regular*/
        *bootType = TRUE;
        xCreateResult =  SAIL_UPDATER_STATUS_SUCCESS;
        goto GetLoaderFlowEnd;
    }

    rollbackEn = bSAILUpdaterCoreIsRollbackEnabled();
    DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetLoaderFlow: OTA Bookkeeping is Enabled max retry count: %d rollbackEn=%d \n\r",maxRetryCount, rollbackEn);

   if(SPINOR_DEVICE_DONE != spinorEl2Open ( &norHandle, SPINOR_USER_TYPE_OTA ))
   {
       DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterOtaBookGetLdrFlow: Spinor Open failed \n\r");
       xCreateResult = SAIL_UPDATER_STATUS_FAIL;
       goto GetLoaderFlowEnd;
   }

    if(SAIL_UPDATER_STATUS_SUCCESS != ePrvCheckBookB(norHandle, &isBookBFresh))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: Checking Bookkeeping PartitionB failed \n\r");
        xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
        goto GetLoaderFlowEnd;
    }
    DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetLoaderFlow: ePrvCheckBookB isBookBFresh %d\n\r", isBookBFresh);

    if(SAIL_UPDATER_STATUS_SUCCESS != ePrvCheckBookRedundancy(norHandle))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: Checking Bookkeeping Redundancy failed \n\r");
        xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
        goto GetLoaderFlowEnd;
    }

    /*Get Ota Status*/
    if(SAIL_UPDATER_STATUS_SUCCESS != xSAILUpdaterGetOtaStatus(norHandle, &xOtaStatus, &guidMap))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterGetOtaStatus Failed \n\r");
        xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
        goto GetLoaderFlowEnd;
    }
    currentOTAState = xOtaStatus;

    DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetLoaderFlow: xOtaStatus=%d guidMap=%d \n\r",xOtaStatus, guidMap);

    /*validate the magic number, crc check*/
    if(SAIL_UPDATER_STATUS_SUCCESS != xSAILUpdaterGetMagicNum(norHandle, &ulMagicNum, &bValid))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterGetMagicNum Failed \n\r");
        xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
        goto GetLoaderFlowEnd;
    }

    if(bValid == FALSE)
    {
        ulMagicNum = 0xDEADBEEF;
    }

    DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterGetMagicNum bValid %d,  ulMagicNum = 0x%x\n\r", bValid ,ulMagicNum);

    /* Check if the Primary GPT is healthy */
    if(SAIL_UPDATER_SUCCESS != xSAILUpdaterCoreVerifyGPTWrap(SAIL_UPD_GPT_ID_PRIMARY, &primCrc, &primHdrCrcStatus, &primEntryCrcStatus))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterCoreVerifyGPTWrap Primary Failed \n\r");
        xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
        goto GetLoaderFlowEnd;
    }

    DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetLoaderFlow: prim partition_entries_crc32 0x%x primHdrCrcStatus = %d primEntryCrcStatus = %d\n\r",primCrc, primHdrCrcStatus, primEntryCrcStatus);

    /* If Primary GPT not healthy, fix the Primary GPT based on the OTA State Information */
    if (!((primHdrCrcStatus==1) && (primEntryCrcStatus==1)))
    {
        DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetLoaderFlow: Fixing Primary GPT \n\r");
        if(SAIL_UPDATER_SUCCESS != xSAILUpdaterCoreFixCorruptPrimaryGPT(norHandle, xOtaStatus, guidMap))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: Fix Primary GPT Failed \n\r");
            xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
            goto GetLoaderFlowEnd;
        }
    }

    /*If Update GPT is done the Write OTA status as booting with OTA Images*/
    if(xOtaStatus ==  OTA_UPDATE_START )
    {
        DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetLoaderFlow: OTA_UPDATE_START\n\r");
        /*BOOT Type is not regular*/
        *bootType = FALSE;
        /*Check for Secondary GPT CRC*/
        if(SAIL_UPDATER_SUCCESS != xSAILUpdaterCoreVerifyGPTWrap(SAIL_UPD_GPT_ID_SECONDARY, &secCrc, &secHdrCrcStatus, &secEntryCrcStatus))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterCoreVerifyGPTWrap Secondary Failed \n\r");
            xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
            goto GetLoaderFlowEnd;
        }
        DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetLoaderFlow: sec partition_entries_crc32=0x%x secHdrCrcStatus = %d secEntryCrcStatus = %d \n\r",secCrc, secHdrCrcStatus, secEntryCrcStatus);

        /*Check for Primary GPT CRC*/
        if(SAIL_UPDATER_SUCCESS != xSAILUpdaterCoreVerifyGPTWrap(SAIL_UPD_GPT_ID_PRIMARY, &primCrc, &primHdrCrcStatus, &primEntryCrcStatus))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterCoreVerifyGPTWrap Primary Failed \n\r");
            xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
            goto GetLoaderFlowEnd;
        }
        DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetLoaderFlow: prim partition_entries_crc32 0x%x primHdrCrcStatus = %d primEntryCrcStatus = %d\n\r",primCrc, primHdrCrcStatus, primEntryCrcStatus);

        /* Primary GPT should be healthy and if previous map is 0 then partition entries should mismatch or
           if previous map is 1 then partition entries should be equal */
        if ( (1 == primHdrCrcStatus) && (1 == primEntryCrcStatus) )
        {
            /* patch 1 entry condition */
            if ((isBookBFresh==TRUE) && (ulMagicNum == 0xffffffff) && (guidMap == 0) && (primCrc == secCrc))
            {
                //patch 1
                    /*Do nothing */
                    DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetLoaderFlow: OTA Migration from old statemachine to new statemachine.\n\r");
                    if(SAIL_UPDATER_STATUS_SUCCESS != xSAILUpdaterForceOtaStatus(norHandle, OTA_BOOTING))
                    {
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterForceOtaStatus OTA_BOOTING Failed \n\r");
                        xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
                        goto GetLoaderFlowEnd;
                    }
                    DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterForceOtaStatus OTA_BOOTING\n\r");
                    /*Retry count Increase Update*/
                    if(SAIL_UPDATER_STATUS_SUCCESS != ePrvUpdateRetryCount(norHandle))
                    {
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterUpdateRetryCount Failed \n\r");
                        xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
                        goto GetLoaderFlowEnd;
                    }
                    /*Get Retry Count*/
                    if(SAIL_UPDATER_STATUS_SUCCESS != ePrvGetRetryCount(norHandle, &xRetryCount))
                    {
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterGetRetryCount Failed \n\r");
                        xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
                        goto GetLoaderFlowEnd;
                    }
                    DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterGetRetryCount: %d\n\r", xRetryCount);


            }
            else if ( (isBookBFresh==TRUE) && (ulMagicNum == 0xffffffff) && (guidMap == 0) && (primCrc != secCrc))
            {
                //add patch 2

                /* If guidMap is 0 and prim CRC not equal to sec CRC and bookkeeping B is fresh then
                   its an OTA Migration from old statemachine and we need to explicitly swap the additional entries in Primary GPT so that
                   the next update from to newer statemachine OTA will work correctly.
                */
                /* Patch 2:*/

                /* swap the correct number of entries here during migration */
                if(SAIL_UPDATER_SUCCESS != xSAILUpdaterCoreReconstructAltGPT(norHandle, SAIL_UPD_GPT_ID_SECONDARY, TRUE))
                {
                    DEBUG_LOG(SAIL_ERROR,"%s: Force Swapping to fix the difference in migration failed \n\r", __func__);
                    xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
                    goto GetLoaderFlowEnd;
                }

                if(SAIL_UPDATER_STATUS_SUCCESS != xSAILUpdaterSetOtaStatus(norHandle, OTA_BOOTING))
                {
                    DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterSetOtaStatus OTA_BOOTING Failed \n\r");
                    xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
                    goto GetLoaderFlowEnd;
                }
                DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterSetOtaStatus OTA_BOOTING\n\r");
                /*Retry count Increase Update*/
                if(SAIL_UPDATER_STATUS_SUCCESS != ePrvUpdateRetryCount(norHandle))
                {
                    DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterUpdateRetryCount Failed \n\r");
                    xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
                    goto GetLoaderFlowEnd;
                }
                /*Get Retry Count*/
                if(SAIL_UPDATER_STATUS_SUCCESS != ePrvGetRetryCount(norHandle, &xRetryCount))
                {
                    DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterGetRetryCount Failed \n\r");
                    xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
                    goto GetLoaderFlowEnd;
                }
                DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterGetRetryCount: %d\n\r", xRetryCount);
            }
            else if ( (isBookBFresh==FALSE) && (ulMagicNum == 0xffffffff))
            {
                //patch 3.

                // Fixed the condition where after migration to new statemachine with Guidmap state is not in sync with the GPT entry state
                if (primCrc != secCrc)
                {
                    if(SAIL_UPDATER_SUCCESS != xSAILUpdaterCoreGetTrueSwap( norHandle, &bTrueSwap))
                    {
                        DEBUG_LOG(SAIL_ERROR,"%s: xSAILUpdaterCoreGetTrueSwap returned failure\n\r", __func__);
                        xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
                        goto GetLoaderFlowEnd;
                    }

                    DEBUG_LOG(SAIL_WARNING,"%s: xSAILUpdaterCoreGetTrueSwap bTrueSwap=%d\n\r", __func__, bTrueSwap);

                    if (bTrueSwap == TRUE)
                    {
                        /* Swap happened. So Swap all the entries from Seondary to Primary */
                        if(SAIL_UPDATER_SUCCESS != xSAILUpdaterCoreReconstructAltGPT(norHandle, SAIL_UPD_GPT_ID_SECONDARY, TRUE))
                        {
                            DEBUG_LOG(SAIL_ERROR,"%s: Force Swapping to fix the difference in migration failed \n\r", __func__);
                            xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
                            goto GetLoaderFlowEnd;
                        }
                        if(guidMap == 1)
                        {
                            // force state to booting. guidMap still be 1
                            if(SAIL_UPDATER_STATUS_SUCCESS != xSAILUpdaterForceOtaStatus(norHandle, OTA_BOOTING))
                            {
                                DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterForceOtaStatus OTA_BOOTING Failed \n\r");
                                xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
                                goto GetLoaderFlowEnd;
                            }
                            DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterForceOtaStatus OTA_BOOTING\n\r");
                        }
                        else
                        {
                            // Set state to Booting. the function will set the GuidMap to 1
                            if(SAIL_UPDATER_STATUS_SUCCESS != xSAILUpdaterSetOtaStatus(norHandle, OTA_BOOTING))
                            {
                                DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterSetOtaStatus OTA_BOOTING Failed \n\r");
                                xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
                                goto GetLoaderFlowEnd;
                            }
                            DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterSetOtaStatus OTA_BOOTING\n\r");
                        }
                    }
                    else
                    {
                        /* No Swap here. So copy Secondary to Primary GPT as it is */
                        if(SAIL_UPDATER_SUCCESS != xSAILUpdaterCoreReconstructAltGPT(norHandle, SAIL_UPD_GPT_ID_SECONDARY, FALSE))
                        {
                            DEBUG_LOG(SAIL_ERROR,"%s: Force Swapping to fix the difference in migration failed \n\r", __func__);
                            xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
                            goto GetLoaderFlowEnd;
                        }

                        if(guidMap == 1)
                        {
                            // setOtaSate to booting. the function will set guidMap = 0
                            if(SAIL_UPDATER_STATUS_SUCCESS != xSAILUpdaterSetOtaStatus(norHandle, OTA_BOOTING))
                            {
                                DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterSetOtaStatus OTA_BOOTING Failed \n\r");
                                xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
                                goto GetLoaderFlowEnd;
                            }
                            DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterSetOtaStatus OTA_BOOTING\n\r");
                        }
                        else
                        {
                            // Force state to booting. the Guid Map remains as 0
                            if(SAIL_UPDATER_STATUS_SUCCESS != xSAILUpdaterForceOtaStatus(norHandle, OTA_BOOTING))
                            {
                                DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterForceOtaStatus OTA_BOOTING Failed \n\r");
                                xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
                                goto GetLoaderFlowEnd;
                            }
                            DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterForceOtaStatus OTA_BOOTING\n\r");
                        }
                    }
                }
                else
                {
                    if (guidMap == 0)
                    {
                        // force state to booting. guidMap still be 0
                        if(SAIL_UPDATER_STATUS_SUCCESS != xSAILUpdaterForceOtaStatus(norHandle, OTA_BOOTING))
                        {
                            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterForceOtaStatus OTA_BOOTING Failed \n\r");
                            xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
                            goto GetLoaderFlowEnd;
                        }
                        DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterForceOtaStatus OTA_BOOTING\n\r");
                    }
                    else
                    {
                        // setOtaSate to booting.the function will set guidMap = 0
                        if(SAIL_UPDATER_STATUS_SUCCESS != xSAILUpdaterSetOtaStatus(norHandle, OTA_BOOTING))
                        {
                            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterSetOtaStatus OTA_BOOTING Failed \n\r");
                            xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
                            goto GetLoaderFlowEnd;
                        }
                        DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterSetOtaStatus OTA_BOOTING\n\r");
                    }
                }

                /*Retry count Increase Update*/
                if(SAIL_UPDATER_STATUS_SUCCESS != ePrvUpdateRetryCount(norHandle))
                {
                    DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterUpdateRetryCount Failed \n\r");
                    xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
                    goto GetLoaderFlowEnd;
                }
                /*Get Retry Count*/
                if(SAIL_UPDATER_STATUS_SUCCESS != ePrvGetRetryCount(norHandle, &xRetryCount))
                {
                    DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterGetRetryCount Failed \n\r");
                    xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
                    goto GetLoaderFlowEnd;
                }
                DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterGetRetryCount: %d\n\r", xRetryCount);
            }
            else
            {
                // ES15 release code copys here
                if ( ((0 == guidMap)&&(primCrc != secCrc)) || ((1 == guidMap)&&(primCrc == secCrc)) )
                {
                    DEBUG_LOG(SAIL_WARNING, "xSAILUpdaterGetLoaderFlow: logicGuidASwapped map changed and Primary CRC status is good. Change state to OTA_BOOTING\n\r");

                    if(SAIL_UPDATER_STATUS_SUCCESS != xSAILUpdaterSetOtaStatus(norHandle, OTA_BOOTING))
                    {
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterSetOtaStatus OTA_BOOTING Failed \n\r");
                        xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
                        goto GetLoaderFlowEnd;
                    }
                    DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterSetOtaStatus OTA_BOOTING\n\r");
                    /*Retry count Increase Update*/
                    if(SAIL_UPDATER_STATUS_SUCCESS != ePrvUpdateRetryCount(norHandle))
                    {
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterUpdateRetryCount Failed \n\r");
                        xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
                        goto GetLoaderFlowEnd;
                    }
                    /*Get Retry Count*/
                    if(SAIL_UPDATER_STATUS_SUCCESS != ePrvGetRetryCount(norHandle, &xRetryCount))
                    {
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterGetRetryCount Failed \n\r");
                        xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
                        goto GetLoaderFlowEnd;
                    }
                    DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterGetRetryCount: %d\n\r", xRetryCount);
                }
                else
                {
                    /* Swap the GPT. power loss could have happened after recording state to OTA START but before the GPT was modified.
                    switch  partitions now */

                    DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetLoaderFlow: logicGuidASwapped map not changed.Switch partition in previous boot did not happen.Switching partitions in Primary GPT now \n\r");
                    if(SAIL_UPDATER_SUCCESS != xSAILUpdaterCoreFixCorruptPrimaryGPT(norHandle, xOtaStatus, guidMap))
                    {
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: Switch partitions in Primary GPT \n\r");
                        xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
                        goto GetLoaderFlowEnd;
                    }
                }
            }
        }
        /*If Primary GPT status invalid at this point, its an error */
        else
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: update GPT started. Fixing Primary GPT or guid map swap has issues \n\r");
            xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
            goto GetLoaderFlowEnd;
        }
    }
    /*Update OTA Boot Flow*/
    else if(xOtaStatus ==  OTA_BOOTING)
    {
        /*Boot type Not regular*/
        *bootType = FALSE;
        /*Retry count Increase Update*/
        if(SAIL_UPDATER_STATUS_SUCCESS != ePrvUpdateRetryCount(norHandle))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterUpdateRetryCount Failed \n\r");
            xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
            goto GetLoaderFlowEnd;
        }
        /*Get Retry Count*/
        if(SAIL_UPDATER_STATUS_SUCCESS != ePrvGetRetryCount(norHandle, &xRetryCount))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterGetRetryCount Failed \n\r");
            xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
            goto GetLoaderFlowEnd;
        }
        DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetLoaderFlow: OTA Status OTA_BOOTING, xSAILUpdaterGetRetryCount: %d\n\r", xRetryCount);
        /*Check for Max Value*/
        if(xRetryCount >= maxRetryCount)
        {
            if (TRUE == rollbackEn)
            {
                boolean rebootNeeded =  TRUE;
                DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetLoaderFlow: Max Retry count %d exceeded threshold %d. Performing Rollback of Primary GPT\n\r", xRetryCount, maxRetryCount);
                /*Check for Secondary GPT CRC*/
                if(SAIL_UPDATER_SUCCESS != xSAILUpdaterCoreVerifyGPTWrap(SAIL_UPD_GPT_ID_SECONDARY, &secCrc, &secHdrCrcStatus, &secEntryCrcStatus))
                {
                    DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterCoreVerifyGPTWrap Secondary Failed \n\r");
                    xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
                    goto GetLoaderFlowEnd;
                }
                DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetLoaderFlow: sec partition_entries_crc32=0x%x secHdrCrcStatus = %d secEntryCrcStatus = %d \n\r",secCrc, secHdrCrcStatus, secEntryCrcStatus);

                /*Check for Primary GPT CRC*/
                if(SAIL_UPDATER_SUCCESS != xSAILUpdaterCoreVerifyGPTWrap(SAIL_UPD_GPT_ID_PRIMARY, &primCrc, &primHdrCrcStatus, &primEntryCrcStatus))
                {
                    DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterCoreVerifyGPTWrap Primary Failed \n\r");
                    xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
                    goto GetLoaderFlowEnd;
                }
                DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetLoaderFlow: prim partition_entries_crc32 0x%x primHdrCrcStatus = %d primEntryCrcStatus = %d\n\r",primCrc, primHdrCrcStatus, primEntryCrcStatus);

                /* Primary GPT should be healthy and if previous map is 0 in booting state then partition entries should match or
                   if previous map is 1 in booting state then partition entries should mismatch for Rolling back GPT.
                   If not rollback happened already but we got a power loss before updating the state to Rollback */
                if ((1 == primHdrCrcStatus) && (1 == primEntryCrcStatus))
                {
                    /* If Rollback happened already, do not rollback again
                       power loss could have happened Rolling back GPT */
                    if ( ((0 == guidMap)&&(primCrc != secCrc)) || ((1 == guidMap)&&(primCrc == secCrc)) )
                    {
                        DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetLoaderFlow: Rollback already happened. Not changing the GPT again \n\r");
                        rebootNeeded = FALSE;
                    }
                    else
                    {
                        DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetLoaderFlow: Rollingback Primary GPT \n\r");
                        /* Rollback the Primary GPT to the previous version */
                        if(SAIL_UPDATER_SUCCESS != xSAILUpdaterCoreRollbackPrimaryGPT(norHandle, xOtaStatus, guidMap))
                        {
                            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: Rollingback Primary GPT Failed\n\r");
                            xCreateResult = SAIL_UPDATER_STATUS_FAIL;
                            goto GetLoaderFlowEnd;
                        }
                        rebootNeeded = TRUE;
                    }
                }
                /*If Primary GPT status invalid at this point, its an error */
                else
                {
                    DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: Rollback started. Fixing Primary GPT due to corruption up has issues \n\r");
                    xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
                    goto GetLoaderFlowEnd;
                }

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
                if (SAIL_OTA_TRIG_ERROR_PRE_ROLLBACK == ulSAILUpdaterCoregetTestCmdID())
                {
                    DEBUG_LOG(SAIL_ERROR,"%s: Forced crash due to trigger SAIL_OTA_TRIG_ERROR_PRE_ROLLBACK \n\r", __func__);
                    err_fatal(SAIL_UPDATER,ERR_FATAL_FORCED_REBOOT);
                }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

                /*Update OTA State to OTA_Rollback*/
                if(SAIL_UPDATER_STATUS_SUCCESS != xSAILUpdaterSetOtaStatus(norHandle, OTA_ROLLBACK))
                {
                    DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: xSAILUpdaterSetOtaStatus OTA_ROLLBACK Failed \n\r");
                    xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
                    goto GetLoaderFlowEnd;
                }
                DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: xRetryCount > MAX_RETRY, xSAILUpdaterSetOtaStatus OTA_ROLLBACK\n\r");

                /* Reboot only if the Rollback was actually performed in this boot*/
                if (TRUE == rebootNeeded)
                {
                    /* Issue reboot for SAIL after GPT rollback so the old image can be booted */
                    DEBUG_LOG(SAIL_ERROR, "%s Forced reboot after GPT Rollback \n\r", __func__);
                    err_fatal(SAIL_UPDATER, ERR_FATAL_FORCED_REBOOT);
                }

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
                if (SAIL_OTA_TRIG_ERROR_POST_ROLLBACK == ulSAILUpdaterCoregetTestCmdID())
                {
                    DEBUG_LOG(SAIL_ERROR,"%s: Forced crash due to trigger SAIL_OTA_TRIG_ERROR_POST_ROLLBACK \n\r", __func__);
                    err_fatal(SAIL_UPDATER,ERR_FATAL_FORCED_REBOOT);
                }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

            }
        }
    }
    /*If OTA DONE */
    else if(xOtaStatus ==  OTA_DONE)
    {
        /*Boot type Not regular*/
        *bootType = FALSE;
    }
    /* Update OTA Rollback Flow */
    else if(xOtaStatus ==  OTA_ROLLBACK)
    {
        /*Boot type Not regular*/
        *bootType = FALSE;
    }
    /*If Flash Partition is in progress*/
    else if(xOtaStatus ==  OTA_IN_PROGRESS)
    {
        /*Boot type Not regular*/
        *bootType = FALSE;
    }
    /*If Corrupted State*/
    else if(xOtaStatus ==  OTA_REBOOT_CORRUPTED)
    {
        /*Boot type Not regular*/
        *bootType = FALSE;
    }
    else if (xOtaStatus ==  OTA_INVALID)
    {
        /*Boot type Not regular*/
        *bootType = FALSE;
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: OTA Status INVALID \n\r");
        xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
        goto GetLoaderFlowEnd;
    }
    /*Update OTA State to Regular*/
    else
    {
        /*Boot type is regular*/
        *bootType = TRUE;
        /*Update OTA state*/
        if(SAIL_UPDATER_STATUS_SUCCESS !=  xSAILUpdaterSetOtaStatus(norHandle, OTA_DISABLED))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: ulSAILUpdaterCoreOtaStatusWrite OTA_DISABLED failed \n\r");
            xCreateResult =  SAIL_UPDATER_STATUS_FAIL;
            goto GetLoaderFlowEnd;
        }
    }

GetLoaderFlowEnd:
    if (norHandle != NULL)
    {
        /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl2Close ( norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetLoaderFlow: Spinor Close failed \n\r");
            xCreateResult = SAIL_UPDATER_STATUS_FAIL;
        }
        norHandle = NULL;
    }
    return xCreateResult;
}

/**********************************************************
 * SAIL_UPDATER Set OTA Status
 *
 * @param norHandle [IN]
 *   Handle for the NOR flash
 *
 * @param SAILUpdaterOTAStateValType [IN]
 *   state to be set
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the Operation
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterSetOtaStatus (void *norHandle, SAILUpdaterOTAStateValType state)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;
    spinorMemInfoType memInfo = {0};
    boolean is_erase_needed = FALSE;
    uint32_t partitionAOffset= 0, partitionASize=0;
    uint32_t partitionBOffset= 0, partitionBSize=0;
    uint32_t blockSizeBytes=0;
    SAILUpdaterOTARebootCtrlType rebootPartA={0}, rebootPartB={0}, temprebootPart = {0};
    uint8_t update_idx,idx,update_guidMap;
    uint8_t last_raw_state,last_state, last_guidMap, last_CRC ;

    uint8_t otaStateTypeWriteBuf[2];
    uint8_t otaStateValidateBuf[2];

    boolean sail_updater_book_erase_write = FALSE;

    if (NULL == norHandle)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterSetOtaStatus: Spinor handle passed is NULL \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto SetOtaStatusEnd;
    }

    sail_updater_book_erase_write = bSAILUpdaterCoreIsBookkeepEraseWriteSet();

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl2GetMemInfo((spinor_handle_t)norHandle, &memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterSetOtaStatus: Spinor Get Mem Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto SetOtaStatusEnd;
    }

    /* Get reboot ctrl Primary partition Info */
    if( SPINOR_DEVICE_DONE != spinorEl2GetGptPartitionInfo((spinor_handle_t)norHandle, "bb7f4519-795e-471d-ac09-2d84c56cd253", &partitionAOffset, &partitionASize))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterSetOtaStatus: Get Reboot Ctrl Primary Partition Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto SetOtaStatusEnd;
    }

    /* Get reboot ctrl Secondary partition Info */
    if( SPINOR_DEVICE_DONE != spinorEl2GetGptPartitionInfo((spinor_handle_t)norHandle, "b5b5a557-ea43-461e-9be2-a028c9b841f4", &partitionBOffset, &partitionBSize))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterSetOtaStatus: Get Reboot Ctrl Secondary Partition Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto SetOtaStatusEnd;
    }

    /* Read from the Primary partition */
    if( SPINOR_DEVICE_DONE != spinorEl2Read ( (spinor_handle_t)norHandle, partitionAOffset, sizeof(rebootPartA), (void *)&rebootPartA))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterSetOtaStatus: SPINOR Read failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto SetOtaStatusEnd;
    }

    if(SAIL_UPDATER_STATUS_SUCCESS != ePrvGetEmptySlotIdx(&rebootPartA.OTAState[0], (sizeof(rebootPartA.OTAState)/sizeof(rebootPartA.OTAState[0])) , &idx))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterSetOtaStatus:Getting last index failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto SetOtaStatusEnd;
    }

    DEBUG_LOG(SAIL_INFO,"xSAILUpdaterSetOtaStatus:Empty slot at index %d \n\r", idx);

    /* error. index cannot be 0. proper values should have been fixed during bootup itself */
    if (0 == idx)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterSetOtaStatus:Reboot partition cannot empty, index is 0 \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto SetOtaStatusEnd;
    }

    /* Get the values at the last index */
    last_raw_state = rebootPartA.OTAState[idx - 1].rawState;
    last_state = last_raw_state & 0x7F;
    last_guidMap = (last_raw_state&0x80)>>0x7;
    last_CRC = rebootPartA.OTAState[idx - 1].crc;

    DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterSetOtaStatus:Values at last index[%d] -> last_raw_state=0x%x last_state=0x%x last_guidMap=0x%x last_CRC=0x%x \n\r",
              (idx-1),last_raw_state, last_state, last_guidMap, last_CRC);

    /* validate values at the last index */
    memset(otaStateValidateBuf, 0, 2);
    otaStateValidateBuf[0] = last_raw_state;
    /* Calculate CRC */
    otaStateValidateBuf[1] = ulAutosarCrc(AUTOSAR_CRC_32BIT_ETHERNET, otaStateValidateBuf, sizeof(otaStateValidateBuf));

    /* Check for CRC match, if not Matching  error out */
    if(otaStateValidateBuf[1] != last_CRC)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterSetOtaStatus:last state value 0x%x and CRC 0x%x does not match at index %d \n\r", last_raw_state, last_CRC,(idx - 1));
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto SetOtaStatusEnd;
    }

    /* If the new state is same as the last state, no write needed */
    if (last_state == state)
    {
        currentOTAState = state;
        DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterSetOtaStatus:last state is the same as new state No need to Write \n\r");
        goto SetOtaStatusEnd;
    }

    if(OTA_DISABLED == state)
    {
        DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterSetOtaStatus:Erasing partition due to state OTA_DISABLED \n\r");
        is_erase_needed = TRUE;
        update_idx = 0;
        update_guidMap = 0;
    }
    else if(OTA_DONE == state)
    {
        DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterSetOtaStatus:Erasing partition due to state OTA_DONE \n\r");
        is_erase_needed = TRUE;
        update_idx = 0;
        update_guidMap = last_guidMap;
    }
    else if((OTA_BOOTING == state) || (OTA_ROLLBACK == state))
    {
        update_guidMap = ~last_guidMap;
        is_erase_needed = FALSE;
        update_idx = idx;
    }
    else
    {
        update_guidMap = last_guidMap;
        is_erase_needed = FALSE;
        update_idx = idx;
    }

    /* If index reached end of buffer, get the last state and erase and write */
    if (idx >= (sizeof(rebootPartA.OTAState)/sizeof(rebootPartA.OTAState[0])))
    {
        DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterSetOtaStatus:Erasing partition due to end of buffer reached \n\r");
        is_erase_needed = TRUE;
        update_idx = 0;
    }

    /* Erase the bookkeeping partition if erasebookkeping before write it set or if erase is needed */
    if ((TRUE == sail_updater_book_erase_write) || (TRUE == is_erase_needed))
    {
        blockSizeBytes  = memInfo.pages_per_block * memInfo.page_size_bytes;
        if ( SPINOR_DEVICE_DONE != spinorEl2Erase ((spinor_handle_t)norHandle, partitionAOffset / blockSizeBytes, partitionASize/blockSizeBytes))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterSetOtaStatus:spinorEl1Erase Failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
            goto SetOtaStatusEnd;
        }
    }

    /* Reset the contents for the partitions only if erase is needed. Should not be set to FFs if erase before write case */
    if (TRUE == is_erase_needed)
    {
        /*Set the contents to 0xFF */
        memset(&rebootPartA, 0xFF, sizeof(rebootPartA));
    }

    memset(&rebootPartA.xMagic, 0xFF, sizeof(SAILUpdaterOTAMagicType));
    /* Update Magic number */
    rebootPartA.xMagic.ulMagicNumber = 0x1;
    rebootPartA.xMagic.ulMagicNumCRC = ulAutosarCrc(AUTOSAR_CRC_32BIT_ETHERNET, (uint8_t *)&rebootPartA.xMagic, sizeof(rebootPartA.xMagic.ulMagicNumber));

    rebootPartA.OTAState[update_idx].rawState = (update_guidMap<<7)|(state);

    /*Write Status Offset*/
    memset(otaStateTypeWriteBuf, 0, 2);
    otaStateTypeWriteBuf[0] = rebootPartA.OTAState[update_idx].rawState;

    /* Calculate CRC */
    otaStateTypeWriteBuf[1] = ulAutosarCrc(AUTOSAR_CRC_32BIT_ETHERNET, otaStateTypeWriteBuf, sizeof(otaStateTypeWriteBuf));
    rebootPartA.OTAState[update_idx].crc = otaStateTypeWriteBuf[1];

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    uint32 testCmdID = ulSAILUpdaterCoregetTestCmdID();
    if ( (SAIL_OTA_TRIG_ERROR_WR_ROLLBACK_A == testCmdID) )
    {
        /* Corrupt the state and CRC */
        rebootPartA.OTAState[update_idx].rawState = rebootPartA.OTAState[update_idx].rawState | 0x58;
        rebootPartA.OTAState[update_idx].crc = ~rebootPartA.OTAState[update_idx].crc;
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterSetOtaStatus: Setting state = 0x%x and CRC = 0x%x at index %d\n\r", rebootPartA.OTAState[update_idx].rawState, rebootPartA.OTAState[update_idx].crc, update_idx);

    if( SPINOR_DEVICE_DONE != spinorEl2Write((spinor_handle_t)norHandle, partitionAOffset, sizeof(rebootPartA), (void *) &rebootPartA))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterSetOtaStatus: Write OTA status failure for Primary partition \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto SetOtaStatusEnd;
    }

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if ( (SAIL_OTA_TRIG_ERROR_WR_ROLLBACK_A == testCmdID) )
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Forced crash due to trigger SAIL_OTA_TRIG_ERROR_WR_ROLLBACK_A\n\r", __func__);
        err_fatal(SAIL_UPDATER,ERR_FATAL_FORCED_REBOOT);
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    /* Read from the partition again to verify the content */
    if( SPINOR_DEVICE_DONE != spinorEl2Read ( (spinor_handle_t)norHandle, partitionAOffset, sizeof(temprebootPart), (void *) &temprebootPart))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterSetOtaStatus: SPINOR Read back after write to Primary partition failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto SetOtaStatusEnd;
    }

    /* Error if the Read values dont match */
    if ( (temprebootPart.OTAState[update_idx].crc != rebootPartA.OTAState[update_idx].crc) ||
         (temprebootPart.OTAState[update_idx].rawState != rebootPartA.OTAState[update_idx].rawState) )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterSetOtaStatus: Verify failed for OTA State in Primary partition Readback state = 0x%x and readback CRC = 0x%x \n\r",
                  temprebootPart.OTAState[update_idx].rawState, temprebootPart.OTAState[update_idx].crc);
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto SetOtaStatusEnd;
    }

    currentOTAState = state;

    /* Re-do the same for the Secondary Reboot Ctrl Partition */
    /* Erase the bookkeeping partition if erasebookkeping before write it set or if erase is needed */
    if ((TRUE == sail_updater_book_erase_write) || (TRUE == is_erase_needed))
    {
        DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterSetOtaStatus: Erasing Secondary Partition \n\r");
        blockSizeBytes  = memInfo.pages_per_block * memInfo.page_size_bytes;
        if ( SPINOR_DEVICE_DONE != spinorEl2Erase ((spinor_handle_t)norHandle, partitionBOffset / blockSizeBytes, partitionBSize/blockSizeBytes))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterSetOtaStatus:Erasing Secondary Partition Failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
            goto SetOtaStatusEnd;
        }
    }

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if ( (SAIL_OTA_TRIG_ERROR_WR_ROLLBACK_B == testCmdID) )
    {
        /* Corrupt the state and CRC */
        temprebootPart.OTAState[update_idx].rawState = temprebootPart.OTAState[update_idx].rawState | 0x58;
        temprebootPart.OTAState[update_idx].crc = ~temprebootPart.OTAState[update_idx].crc;
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    /* Update the Secondary Reboot Ctrl Partition */
    DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterSetOtaStatus: Updating Secondary Partition state = 0x%x and CRC = 0x%x at index %d\n\r", temprebootPart.OTAState[update_idx].rawState, temprebootPart.OTAState[update_idx].crc, update_idx);
    if( SPINOR_DEVICE_DONE != spinorEl2Write((spinor_handle_t)norHandle, partitionBOffset, sizeof(temprebootPart), (void *) &temprebootPart))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterSetOtaStatus: Write OTA status failure for Secondary partition\n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto SetOtaStatusEnd;
    }

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if ( (SAIL_OTA_TRIG_ERROR_WR_ROLLBACK_B == testCmdID) )
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Forced crash due to trigger SAIL_OTA_TRIG_ERROR_WR_ROLLBACK_B\n\r", __func__);
        err_fatal(SAIL_UPDATER,ERR_FATAL_FORCED_REBOOT);
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    /* Read from the partition again to verify the content */
    if( SPINOR_DEVICE_DONE != spinorEl2Read ( (spinor_handle_t)norHandle, partitionBOffset, sizeof(rebootPartB), (void *) &rebootPartB))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterSetOtaStatus: SPINOR Read back after write to Secondary partition failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto SetOtaStatusEnd;
    }

    /* Error if the Read values dont match */
    if ( (temprebootPart.OTAState[update_idx].crc != rebootPartB.OTAState[update_idx].crc) ||
         (temprebootPart.OTAState[update_idx].rawState != rebootPartB.OTAState[update_idx].rawState) )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterSetOtaStatus: Verify failed for OTA State in Secondary partition Readback state = 0x%x and readback CRC = 0x%x \n\r",
                  rebootPartB.OTAState[update_idx].rawState, rebootPartB.OTAState[update_idx].crc);
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto SetOtaStatusEnd;
    }

    currentOTAState = state;

SetOtaStatusEnd:
    return eStatus;
}

/**********************************************************
 * SAIL_UPDATER Get OTA Status
 *
 * @param norHandle [IN]
 *   Handle for the NOR flash
 *
 * @param SAILUpdaterOTAStateValType [OUT]
 *   state to be Read
 *
 * @param guidMap [OUT]
 *   GUID Mapping Information for GUIDA
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the Operation
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterGetOtaStatus (void *norHandle, SAILUpdaterOTAStateValType *otaStatus, uint8_t* guidMap)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;
    spinorMemInfoType memInfo = {0};
    uint32_t otaStatusByteOffset = 0, otaStatusByteCountPart = 0;
    uint8_t otaStateTypeReadBuf[2];
    SAILUpdaterOTARebootCtrlType rebootPartA={0}, rebootPartB={0};

    if ((NULL == otaStatus) || (NULL == guidMap))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetOtaStatus: otaStatus or guidMap pointer passed is NULL \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto GetOtaStatusEnd;
    }

    if (NULL == norHandle)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetOtaStatus: Spinor handle passed is NULL \n\r");
        *otaStatus = OTA_INVALID;
        *guidMap = 0;
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto GetOtaStatusEnd;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl2GetMemInfo((spinor_handle_t)norHandle, &memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetOtaStatus: Spinor Get Mem Info failed \n\r");
        *otaStatus = OTA_INVALID;
        *guidMap = 0;
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto GetOtaStatusEnd;
    }

    /* Get reboot ctrl Primary partition Info */
    if( SPINOR_DEVICE_DONE !=  spinorEl2GetGptPartitionInfo((spinor_handle_t)norHandle, "bb7f4519-795e-471d-ac09-2d84c56cd253", &otaStatusByteOffset, &otaStatusByteCountPart)  )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetOtaStatus: Get Reboot Ctrl Primary Partition Info failed \n\r");
        *otaStatus = OTA_INVALID;
        *guidMap = 0;
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto GetOtaStatusEnd;
    }

    /* Read from the partition */
    if( SPINOR_DEVICE_DONE != spinorEl2Read ( (spinor_handle_t)norHandle, otaStatusByteOffset, sizeof(rebootPartA), (void *) &rebootPartA))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetOtaStatus: Get Reboot Ctrl Primary Partition Info failed \n\r");
        *otaStatus = OTA_INVALID;
        *guidMap = 0;
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto GetOtaStatusEnd;
    }

    /* Check for the Last Valid OTA state */
    for (int i=(sizeof(rebootPartA.OTAState)/sizeof(rebootPartA.OTAState[0]))-1;i>=0;i-=1)
    {
        DEBUG_LOG(SAIL_WARNING, "UpdOtaSts:PPartSts[%d] Swap:0x%x state:0x%x CRC:0x%x\n\r",
                    i, rebootPartA.OTAState[i].rawStateExt.logicGuidASwapped, rebootPartA.OTAState[i].rawStateExt.OTAState, rebootPartA.OTAState[i].crc);
        /*if Ota status Buffer has a valid value*/
        if (rebootPartA.OTAState[i].rawState != OTA_INVALID)
        {
            memset(otaStateTypeReadBuf, 0, 2);
            otaStateTypeReadBuf[0] = rebootPartA.OTAState[i].rawState;

            /*CRC Validation failure scenario handling. Fail on first invalid value to check the Secondary partition */
            otaStateTypeReadBuf[1] = ulAutosarCrc(AUTOSAR_CRC_32BIT_ETHERNET, otaStateTypeReadBuf, sizeof(otaStateTypeReadBuf));
            if(otaStateTypeReadBuf[1] != rebootPartA.OTAState[i].crc)
            {
                DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetOtaStatus:CRC not matching for item %d in Primary partition, OTA state value 0x%x\n\r",i,rebootPartA.OTAState[i].rawStateExt.OTAState);
                goto checkAltPartition;
            }
            /*Got Valid OTA state*/
            else
            {
                DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetOtaStatus:return the state 0x%x\n\r",rebootPartA.OTAState[i].rawStateExt.OTAState);
                *otaStatus = rebootPartA.OTAState[i].rawStateExt.OTAState;
                *guidMap = rebootPartA.OTAState[i].rawStateExt.logicGuidASwapped;
                goto GetOtaStatusEnd;
            }
        }
        else
        {
            continue;
        }
    }

checkAltPartition:
    /* Get reboot ctrl Secondary partition Info */
    if( SPINOR_DEVICE_DONE !=  spinorEl2GetGptPartitionInfo((spinor_handle_t)norHandle, "b5b5a557-ea43-461e-9be2-a028c9b841f4", &otaStatusByteOffset, &otaStatusByteCountPart))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetOtaStatus: Get Reboot Ctrl Secondary Partition Info failed \n\r");
        *otaStatus = OTA_INVALID;
        *guidMap = 0;
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto GetOtaStatusEnd;
    }

    /* Read from the partition */
    if( SPINOR_DEVICE_DONE != spinorEl2Read ( (spinor_handle_t)norHandle, otaStatusByteOffset, sizeof(rebootPartB), (void *) &rebootPartB))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetOtaStatus: Get Reboot Ctrl Secondary Partition Info failed \n\r");
        *otaStatus = OTA_INVALID;
        *guidMap = 0;
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto GetOtaStatusEnd;
    }

    /* Check for the Last Valid OTA state */
    for (int i=(sizeof(rebootPartB.OTAState)/sizeof(rebootPartB.OTAState[0]))-1;i>=0;i-=1)
    {
        DEBUG_LOG(SAIL_WARNING, "UpdOtaSts:SPartSts[%d] Swap:0x%x state:0x%x CRC:0x%x\n\r",
            i, rebootPartB.OTAState[i].rawStateExt.logicGuidASwapped, rebootPartB.OTAState[i].rawStateExt.OTAState, rebootPartB.OTAState[i].crc);

        /*if Ota status Buffer has a valid value*/
        if (rebootPartB.OTAState[i].rawState != OTA_INVALID)
        {
            memset(otaStateTypeReadBuf, 0, 2);
            otaStateTypeReadBuf[0] = rebootPartB.OTAState[i].rawState;

            /*CRC Validation failure scenario handling. Fail on the first invalid value */
            otaStateTypeReadBuf[1] = ulAutosarCrc(AUTOSAR_CRC_32BIT_ETHERNET, otaStateTypeReadBuf, sizeof(otaStateTypeReadBuf));
            if(otaStateTypeReadBuf[1] != rebootPartB.OTAState[i].crc)
            {
                DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetOtaStatus:CRC not matching for item %d in Secondary partition, OTA state value 0x%x\n\r",i,rebootPartB.OTAState[i].rawStateExt.OTAState);
                *otaStatus =  OTA_INVALID;
                *guidMap = 0;
                eStatus =  SAIL_UPDATER_STATUS_FAIL;
                goto GetOtaStatusEnd;
            }
            /*Got Valid OTA state*/
            else
            {
                DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetOtaStatus:return the state 0x%x\n\r",rebootPartB.OTAState[i].rawStateExt.OTAState);
                *otaStatus = rebootPartB.OTAState[i].rawStateExt.OTAState;
                *guidMap = rebootPartB.OTAState[i].rawStateExt.logicGuidASwapped;
                goto GetOtaStatusEnd;
            }
        }
        else
        {
            continue;
        }
    }

    /* Corruption should not happen in both partitions. Redundancy Check should restore both partitions in XBL. Valid value should be written in XBL */
    DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetOtaStatus: Unexpected error. Control should not reach here \n\r");
    *otaStatus =  OTA_INVALID;
    *guidMap = 0;
    eStatus =  SAIL_UPDATER_STATUS_FAIL;

GetOtaStatusEnd:
    return eStatus;
}

/**********************************************************
 * SAIL_UPDATER Get Magic Number
 *
 * @param norHandle [IN]
 *   Handle for the NOR flash
 *
 * @param pMagicNum [IN/OUT]
 *   magic num to be read
 *
 * @param pValid [IN/OUT]
 *   whether magic num is valid
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the Operation
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterGetMagicNum (void *norHandle, uint32_t *pMagicNum, boolean *pValid)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;
    spinorMemInfoType memInfo = {0};
    uint32_t otaStatusByteOffset = 0, otaStatusByteCountPart = 0;
    SAILUpdaterOTARebootCtrlType rebootPartA={0};
    uint32_t ultempCRC = 0;

    if ((NULL == pMagicNum) || (NULL == pValid))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetMagicNum: pValid or pMagicNum pointer passed is NULL \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto GetMagicNumEnd;
    }

    if (NULL == norHandle)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetMagicNum: Spinor handle passed is NULL \n\r");
        *pMagicNum = 0xDEADBEEF;
        *pValid = FALSE;
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto GetMagicNumEnd;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl2GetMemInfo((spinor_handle_t)norHandle, &memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetOtaStatus: Spinor Get Mem Info failed \n\r");
        *pMagicNum = 0xDEADBEEF;
        *pValid = FALSE;
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto GetMagicNumEnd;
    }

    /* Get reboot ctrl Primary partition Info */
    if( SPINOR_DEVICE_DONE !=  spinorEl2GetGptPartitionInfo((spinor_handle_t)norHandle, "bb7f4519-795e-471d-ac09-2d84c56cd253", &otaStatusByteOffset, &otaStatusByteCountPart)  )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetMagicNum: Get Reboot Ctrl Primary Partition Info failed \n\r");
        *pMagicNum = 0xDEADBEEF;
        *pValid = FALSE;
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto GetMagicNumEnd;
    }

    /* Read from the partition */
    if( SPINOR_DEVICE_DONE != spinorEl2Read ( (spinor_handle_t)norHandle, otaStatusByteOffset, sizeof(rebootPartA), (void *) &rebootPartA))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetMagicNum: Get Reboot Ctrl Primary Partition Info failed \n\r");
        *pMagicNum = 0xDEADBEEF;
        *pValid = FALSE;
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto GetMagicNumEnd;
    }

    ultempCRC = ulAutosarCrc(AUTOSAR_CRC_32BIT_ETHERNET, (uint8_t *)&rebootPartA.xMagic, sizeof(rebootPartA.xMagic.ulMagicNumber));
    if(ultempCRC == rebootPartA.xMagic.ulMagicNumCRC)
    {
        *pValid = TRUE;
        *pMagicNum = rebootPartA.xMagic.ulMagicNumber;
    }
    else
    {
        *pValid = FALSE;
        *pMagicNum = 0xDEADBEEF;
    }

GetMagicNumEnd:
    return eStatus;
}


/* EOF */
