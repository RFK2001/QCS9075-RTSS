
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
#include "spinor_el1_api.h"
#include "sail_updater_otabookkeep.h"
#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
#include "err_fatal.h"
#endif

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
    boolean sail_updater_book_erase_write = FALSE;

    uint8_t otaStateTypeWriteBuf[2];
    uint8_t otaStateValidateBuf[2];

    sail_updater_book_erase_write = bSAILUpdaterCoreIsBookkeepEraseWriteSet();

    if (NULL == norHandle)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterSetOtaStatus: Spinor handle passed is NULL \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto SetOtaStatusEnd;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl1GetMemInfo((spinor_handle_t)norHandle, &memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterSetOtaStatus: Spinor Get Mem Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto SetOtaStatusEnd;
    }

    /* Get reboot ctrl Primary partition Info */
    if( SPINOR_DEVICE_DONE != spinorEl1GetGptPartitionInfo((spinor_handle_t)norHandle, "bb7f4519-795e-471d-ac09-2d84c56cd253", &partitionAOffset, &partitionASize))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterSetOtaStatus: Get Reboot Ctrl Primary Partition Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto SetOtaStatusEnd;
    }

    /* Get reboot ctrl Secondary partition Info */
    if( SPINOR_DEVICE_DONE != spinorEl1GetGptPartitionInfo((spinor_handle_t)norHandle, "b5b5a557-ea43-461e-9be2-a028c9b841f4", &partitionBOffset, &partitionBSize))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterSetOtaStatus: Get Reboot Ctrl Secondary Partition Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto SetOtaStatusEnd;
    }

    /* Read from the Primary partition */
    if( SPINOR_DEVICE_DONE != spinorEl1Read ( (spinor_handle_t)norHandle, partitionAOffset, sizeof(rebootPartA), (void *)&rebootPartA))
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

    DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterSetOtaStatus:Empty slot at index %d \n\r", idx);

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
        if ( SPINOR_DEVICE_DONE != spinorEl1Erase ((spinor_handle_t)norHandle, partitionAOffset / blockSizeBytes, partitionASize/blockSizeBytes))
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
    if ( (SAIL_OTA_TRIG_ERROR_WR_INPROGRESS_A == testCmdID) || (SAIL_OTA_TRIG_ERROR_WR_UPDATESTART_A == testCmdID)
         || (SAIL_OTA_TRIG_ERROR_WR_OTADONE_A == testCmdID) || (SAIL_OTA_TRIG_ERROR_WR_OTADDISABLED_A_FIXGPT == testCmdID)
         || (SAIL_OTA_TRIG_ERROR_WR_OTADDISABLED_A_REDUNDANCY == testCmdID)
        )
    {
        /* Corrupt the state and CRC */
        rebootPartA.OTAState[update_idx].rawState = rebootPartA.OTAState[update_idx].rawState | 0x58;
        rebootPartA.OTAState[update_idx].crc = ~rebootPartA.OTAState[update_idx].crc;
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterSetOtaStatus: Setting state = 0x%x and CRC = 0x%x at index %d\n\r", rebootPartA.OTAState[update_idx].rawState, rebootPartA.OTAState[update_idx].crc, update_idx);

    if( SPINOR_DEVICE_DONE != spinorEl1Write((spinor_handle_t)norHandle, partitionAOffset, sizeof(rebootPartA), (void *)&rebootPartA))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterSetOtaStatus: Write OTA status failure for Primary partition \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto SetOtaStatusEnd;
    }

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if ( (SAIL_OTA_TRIG_ERROR_WR_INPROGRESS_A == testCmdID) || (SAIL_OTA_TRIG_ERROR_WR_UPDATESTART_A == testCmdID)
         || (SAIL_OTA_TRIG_ERROR_WR_OTADONE_A == testCmdID) || (SAIL_OTA_TRIG_ERROR_WR_OTADDISABLED_A_FIXGPT == testCmdID)
         || (SAIL_OTA_TRIG_ERROR_WR_OTADDISABLED_A_REDUNDANCY == testCmdID)
        )
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Forced crash due to trigger testCmdID=%d\n\r", __func__, testCmdID);
        err_fatal(SAIL_UPDATER,ERR_FATAL_FORCED_REBOOT);
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    /* Read from the partition again to verify the content */
    if( SPINOR_DEVICE_DONE != spinorEl1Read ( (spinor_handle_t)norHandle, partitionAOffset, sizeof(temprebootPart), (void *)&temprebootPart))
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

    /* Re-do the same for the Secondary Reboot Ctrl Partition */
    /* Erase the bookkeeping partition if erasebookkeping before write it set or if erase is needed */
    if ((TRUE == sail_updater_book_erase_write) || (TRUE == is_erase_needed))
    {
        DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterSetOtaStatus: Erasing Secondary Partition \n\r");
        blockSizeBytes  = memInfo.pages_per_block * memInfo.page_size_bytes;
        if ( SPINOR_DEVICE_DONE != spinorEl1Erase ((spinor_handle_t)norHandle, partitionBOffset / blockSizeBytes, partitionBSize/blockSizeBytes))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterSetOtaStatus:Erasing Secondary Partition Failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
            goto SetOtaStatusEnd;
        }
    }

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if ( (SAIL_OTA_TRIG_ERROR_WR_INPROGRESS_B == testCmdID) || (SAIL_OTA_TRIG_ERROR_WR_UPDATESTART_B == testCmdID)
         || (SAIL_OTA_TRIG_ERROR_WR_OTADONE_B == testCmdID) || (SAIL_OTA_TRIG_ERROR_WR_OTADDISABLED_B_FIXGPT == testCmdID)
         || (SAIL_OTA_TRIG_ERROR_WR_OTADDISABLED_B_REDUNDANCY == testCmdID)
        )
    {
        /* Corrupt the state and CRC */
        temprebootPart.OTAState[update_idx].rawState = temprebootPart.OTAState[update_idx].rawState | 0x58;
        temprebootPart.OTAState[update_idx].crc = ~temprebootPart.OTAState[update_idx].crc;
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    /* Update the Secondary Reboot Ctrl Partition */
    DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterSetOtaStatus: Updating Secondary Partition state = 0x%x and CRC = 0x%x at index %d\n\r", temprebootPart.OTAState[update_idx].rawState, temprebootPart.OTAState[update_idx].crc, update_idx);

    if( SPINOR_DEVICE_DONE != spinorEl1Write((spinor_handle_t)norHandle, partitionBOffset, sizeof(temprebootPart), (void *)&temprebootPart))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterSetOtaStatus: Write OTA status failure for Secondary partition\n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto SetOtaStatusEnd;
    }

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if ( (SAIL_OTA_TRIG_ERROR_WR_INPROGRESS_B == testCmdID) || (SAIL_OTA_TRIG_ERROR_WR_UPDATESTART_B == testCmdID)
         || (SAIL_OTA_TRIG_ERROR_WR_OTADONE_B == testCmdID) || (SAIL_OTA_TRIG_ERROR_WR_OTADDISABLED_B_FIXGPT == testCmdID)
         || (SAIL_OTA_TRIG_ERROR_WR_OTADDISABLED_B_REDUNDANCY == testCmdID)
        )
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Forced crash due to trigger testCmdID=%d\n\r", __func__, testCmdID);
        err_fatal(SAIL_UPDATER,ERR_FATAL_FORCED_REBOOT);
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    /* Read from the partition again to verify the content */
    if( SPINOR_DEVICE_DONE != spinorEl1Read ( (spinor_handle_t)norHandle, partitionBOffset, sizeof(rebootPartB), (void *)&rebootPartB))
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
    if (SPINOR_DEVICE_DONE != spinorEl1GetMemInfo((spinor_handle_t)norHandle, &memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetOtaStatus: Spinor Get Mem Info failed \n\r");
        *otaStatus = OTA_INVALID;
        *guidMap = 0;
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto GetOtaStatusEnd;
    }

    /* Get reboot ctrl Primary partition Info */
    if( SPINOR_DEVICE_DONE !=  spinorEl1GetGptPartitionInfo((spinor_handle_t)norHandle, "bb7f4519-795e-471d-ac09-2d84c56cd253", &otaStatusByteOffset, &otaStatusByteCountPart)  )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetOtaStatus: Get Reboot Ctrl Primary Partition Info failed \n\r");
        *otaStatus = OTA_INVALID;
        *guidMap = 0;
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto GetOtaStatusEnd;
    }

    /* Read from the partition */
    if( SPINOR_DEVICE_DONE != spinorEl1Read ( (spinor_handle_t)norHandle, otaStatusByteOffset, sizeof(rebootPartA), (void *)&rebootPartA))
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
        DEBUG_LOG(SAIL_WARNING, "xSAILUpdaterGetOtaStatus: Primary Partition Status -> otaState[%d].logicGuidASwapped: 0x%x otaState[%d].state: 0x%x CRC -> otaState[%d].crc: 0x%x\n\r",
                  i, rebootPartA.OTAState[i].rawStateExt.logicGuidASwapped, i, rebootPartA.OTAState[i].rawStateExt.OTAState, i, rebootPartA.OTAState[i].crc);

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
    if( SPINOR_DEVICE_DONE !=  spinorEl1GetGptPartitionInfo((spinor_handle_t)norHandle, "b5b5a557-ea43-461e-9be2-a028c9b841f4", &otaStatusByteOffset, &otaStatusByteCountPart))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterGetOtaStatus: Get Reboot Ctrl Secondary Partition Info failed \n\r");
        *otaStatus = OTA_INVALID;
        *guidMap = 0;
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto GetOtaStatusEnd;
    }

    /* Read from the partition */
    if( SPINOR_DEVICE_DONE != spinorEl1Read ( (spinor_handle_t)norHandle, otaStatusByteOffset, sizeof(rebootPartB), (void *)&rebootPartB))
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
        DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterGetOtaStatus: Secondary Partition Status -> otaState[%d].state: 0x%x  CRC -> otaState[%d].crc: 0x%x\n\r", i,rebootPartB.OTAState[i].rawStateExt.OTAState,
                  i,rebootPartB.OTAState[i].crc);

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

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED

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
        DEBUG_LOG(SAIL_WARNING,"%s: Partition Status-> otaState[%d].rawstate:0x%x otaState[%d].crc:0x%x\n\r",__func__, i,bookInfo->OTAState[i].rawState,
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
                DEBUG_LOG(SAIL_WARNING,"%s:valid raw state[%d] 0x%x\n\r",__func__, i,bookInfo->OTAState[i].rawState);
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
 * SAIL_UPDATER Set OTA Status
 *
 * @param norHandle [IN]
 *   Handle for the NOR flash
 *
 * @param testCmdID [IN]
 *   Test Trigger ID
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the Operation
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterTestCorruptOtaStatus (void *norHandle, uint32_t testCmdID)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;

    spinorMemInfoType memInfo = {0};
    uint32_t partitionAOffset= 0, partitionASize=0;
    uint32_t partitionBOffset= 0, partitionBSize=0;
    uint32_t blockSize=0;
    SAILUpdaterOTARebootCtrlType rebootPartA={0}, rebootPartB={0};

    uint32_t numEntriesA = 0, numValidEntriesA = 0, numEntriesB = 0, numValidEntriesB = 0;
    boolean isFreshPartA = TRUE, isFreshPartB = TRUE;
    boolean isCorrputedA = FALSE, isCorrputedB = FALSE;

    if (NULL == norHandle)
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Spinor handle passed is NULL \n\r", __func__);
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto TestCorruptOtaStatusEnd;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl1GetMemInfo((spinor_handle_t)norHandle, &memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Spinor Get Mem Info failed \n\r", __func__);
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto TestCorruptOtaStatusEnd;
    }

    blockSize  = memInfo.pages_per_block * memInfo.page_size_bytes;

    if ( (SAIL_OTA_TRIG_CORRUPT_LAST_BOOKKEEPING_A == testCmdID) || (SAIL_OTA_TRIG_CORRUPT_MIDENTRY_BOOKKEEPING_A == testCmdID)
         || (SAIL_OTA_TRIG_CORRUPT_LAST_BOOKKEEPING_AB == testCmdID) || (SAIL_OTA_TRIG_CORRUPT_MIDENTRY_BOOKKEEPING_AB == testCmdID)
         )
    {
        /* Get reboot ctrl Primary partition Info */
        if( SPINOR_DEVICE_DONE != spinorEl1GetGptPartitionInfo((spinor_handle_t)norHandle, "bb7f4519-795e-471d-ac09-2d84c56cd253", &partitionAOffset, &partitionASize))
        {
            DEBUG_LOG(SAIL_ERROR,"%s: Get Reboot Ctrl Primary Partition Info failed \n\r", __func__);
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
            goto TestCorruptOtaStatusEnd;
        }

        /* Read from the Primary partition */
        if( SPINOR_DEVICE_DONE != spinorEl1Read ( (spinor_handle_t)norHandle, partitionAOffset, sizeof(rebootPartA), (void*)&rebootPartA))
        {
            DEBUG_LOG(SAIL_ERROR,"%s: SPINOR Read from Primary Partition failed \n\r", __func__);
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
            goto TestCorruptOtaStatusEnd;
        }

        /* Check Primary partition corruption and collect info */
        if(SAIL_UPDATER_STATUS_SUCCESS != ePrvCheckBookkeepingInfo(&rebootPartA, &numEntriesA, &numValidEntriesA, &isFreshPartA, &isCorrputedA))
        {
            DEBUG_LOG(SAIL_ERROR,"%s: Checking bookkeepingInfo from Primary partition failed \n\r", __func__);
            eStatus = SAIL_UPDATER_STATUS_FAIL;
            goto TestCorruptOtaStatusEnd;
        }

        if ((SAIL_OTA_TRIG_CORRUPT_MIDENTRY_BOOKKEEPING_A == testCmdID) || (SAIL_OTA_TRIG_CORRUPT_MIDENTRY_BOOKKEEPING_AB == testCmdID))
        {
            if (numValidEntriesA <= 2)
            {
                DEBUG_LOG(SAIL_ERROR,"%s: numValidEntries in A Less than= 2. Try again after updating few states  \n\r", __func__);
                eStatus = SAIL_UPDATER_STATUS_FAIL;
                goto TestCorruptOtaStatusEnd;
            }
            else
            {
                /* Corrupt the mid entry state and CRC */
                rebootPartA.OTAState[numValidEntriesA / 2].rawState |= 0x58;
                rebootPartA.OTAState[numValidEntriesA / 2].crc = ~rebootPartA.OTAState[numValidEntriesA / 2].crc;
            }
        }
        else if ((SAIL_OTA_TRIG_CORRUPT_LAST_BOOKKEEPING_A == testCmdID) ||
                  (SAIL_OTA_TRIG_CORRUPT_LAST_BOOKKEEPING_AB == testCmdID)
                 )
        {
            if (numValidEntriesA < 2)
            {
                DEBUG_LOG(SAIL_ERROR,"%s: numValidEntries in A Less than 2. Try again after updating few states  \n\r", __func__);
                eStatus = SAIL_UPDATER_STATUS_FAIL;
                goto TestCorruptOtaStatusEnd;
            }
            else
            {
                /* Corrupt the last entry state and CRC */
                rebootPartA.OTAState[numValidEntriesA-1].rawState |= 0x58;
                rebootPartA.OTAState[numValidEntriesA-1].crc = ~rebootPartA.OTAState[numValidEntriesA-1].crc;
            }
        }
        else
        {
            DEBUG_LOG(SAIL_ERROR,"%s: Unsupported TestCmd ID =%d \n\r", __func__,testCmdID );
            eStatus = SAIL_UPDATER_STATUS_FAIL;
            goto TestCorruptOtaStatusEnd;
        }

        /* Erase the partitions */
        if ( SPINOR_DEVICE_DONE != spinorEl1Erase ((spinor_handle_t)norHandle, partitionAOffset / blockSize, partitionASize / blockSize))
        {
            DEBUG_LOG(SAIL_ERROR,"%s:SPINOR Erase Failed for Partition A \n\r", __func__);
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
            goto TestCorruptOtaStatusEnd;
        }

        /* Write the values to the partitions */
        if( SPINOR_DEVICE_DONE != spinorEl1Write((spinor_handle_t)norHandle, partitionAOffset, sizeof(SAILUpdaterOTARebootCtrlType), (void *)&rebootPartA))
        {
            DEBUG_LOG(SAIL_ERROR,"%s: SPINOR Write  failed for Partition A \n\r", __func__);
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
            goto TestCorruptOtaStatusEnd;
        }
    }

    if ((SAIL_OTA_TRIG_CORRUPT_LAST_BOOKKEEPING_B == testCmdID) || (SAIL_OTA_TRIG_CORRUPT_MIDENTRY_BOOKKEEPING_B == testCmdID)
         || (SAIL_OTA_TRIG_CORRUPT_LAST_BOOKKEEPING_AB == testCmdID) || (SAIL_OTA_TRIG_CORRUPT_MIDENTRY_BOOKKEEPING_AB == testCmdID)
        )
    {
        /* Get reboot ctrl Secondary partition Info */
        if( SPINOR_DEVICE_DONE != spinorEl1GetGptPartitionInfo((spinor_handle_t)norHandle, "b5b5a557-ea43-461e-9be2-a028c9b841f4", &partitionBOffset, &partitionBSize))
        {
            DEBUG_LOG(SAIL_ERROR,"%s: Get Reboot Ctrl Secondary Partition Info failed \n\r", __func__);
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
            goto TestCorruptOtaStatusEnd;
        }

        /* Read from the Secondary partition */
        if( SPINOR_DEVICE_DONE != spinorEl1Read ( (spinor_handle_t)norHandle, partitionBOffset, sizeof(rebootPartB), (void*)&rebootPartB))
        {
            DEBUG_LOG(SAIL_ERROR,"%s: SPINOR Read from Secondary partition failed \n\r", __func__);
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
            goto TestCorruptOtaStatusEnd;
        }

        /* Check Secondary partition corruption and collect info */
        if(SAIL_UPDATER_STATUS_SUCCESS != ePrvCheckBookkeepingInfo(&rebootPartB, &numEntriesB, &numValidEntriesB, &isFreshPartB, &isCorrputedB))
        {
            DEBUG_LOG(SAIL_ERROR,"%s: Checking bookkeepingInfo from Secondary partition failed \n\r", __func__);
            eStatus = SAIL_UPDATER_STATUS_FAIL;
            goto TestCorruptOtaStatusEnd;
        }

        if ((SAIL_OTA_TRIG_CORRUPT_MIDENTRY_BOOKKEEPING_B == testCmdID) || (SAIL_OTA_TRIG_CORRUPT_MIDENTRY_BOOKKEEPING_AB == testCmdID))
        {
            if (numValidEntriesB <= 2)
            {
                DEBUG_LOG(SAIL_ERROR,"%s: numValidEntries in B Less than= 2. Try again after updating few states  \n\r", __func__);
                eStatus = SAIL_UPDATER_STATUS_FAIL;
                goto TestCorruptOtaStatusEnd;

            }
            else
            {
                /* Corrupt the mid entry state and CRC */
                rebootPartB.OTAState[numValidEntriesB/2].rawState |= 0x58;
                rebootPartB.OTAState[numValidEntriesB/2].crc = ~rebootPartB.OTAState[numValidEntriesB / 2].crc;
            }
        }
        else if ((SAIL_OTA_TRIG_CORRUPT_LAST_BOOKKEEPING_B == testCmdID) ||
                  (SAIL_OTA_TRIG_CORRUPT_LAST_BOOKKEEPING_AB == testCmdID)
                 )
        {
            if (numValidEntriesB < 2)
            {
                DEBUG_LOG(SAIL_ERROR,"%s: numValidEntries in B Less than 2. Try again after updating few states  \n\r", __func__);
                eStatus = SAIL_UPDATER_STATUS_FAIL;
                goto TestCorruptOtaStatusEnd;

            }
            else
            {
                /* Corrupt the last entry state and CRC */
                rebootPartB.OTAState[numValidEntriesB-1].rawState |= 0x58;
                rebootPartB.OTAState[numValidEntriesB-1].crc = ~rebootPartB.OTAState[numValidEntriesB-1].crc;
            }
        }
        else
        {
            DEBUG_LOG(SAIL_ERROR,"%s: Unsupported TestCmd ID =%d \n\r", __func__,testCmdID );
            eStatus = SAIL_UPDATER_STATUS_FAIL;
            goto TestCorruptOtaStatusEnd;
        }

        /* Erase the partition */
        if ( SPINOR_DEVICE_DONE != spinorEl1Erase ((spinor_handle_t)norHandle, partitionBOffset / blockSize, partitionBSize / blockSize))
        {
            DEBUG_LOG(SAIL_ERROR,"%s:SPINOR Erase Failed for Partition B \n\r", __func__);
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
            goto TestCorruptOtaStatusEnd;
        }

        /* Write the values to the partitions */
        if( SPINOR_DEVICE_DONE != spinorEl1Write((spinor_handle_t)norHandle, partitionBOffset, sizeof(SAILUpdaterOTARebootCtrlType), (void *)&rebootPartB))
        {
            DEBUG_LOG(SAIL_ERROR,"%s: SPINOR Write  failed for Partition B \n\r", __func__);
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
            goto TestCorruptOtaStatusEnd;
        }
    }

    DEBUG_LOG(SAIL_WARNING,"%s: Corrupted Book keeping partition Successfully \n\r", __func__);

TestCorruptOtaStatusEnd:
    return eStatus;
}
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

/* EOF */
