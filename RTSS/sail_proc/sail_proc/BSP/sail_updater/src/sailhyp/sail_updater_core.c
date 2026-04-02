
/*
===========================================================================
*/
/**
    @file  sail_updater_core.c
    @brief Implementation of SAIL Updater core functions

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
#include "sailhyp_xbl_api.h"
#include "cache_ops.h"
#include "debug_log.h"
#include "common_functions.h"

#include "spinor_el2_api.h"
#include "gpt_partition1.h"
#include "libfdt.h"
#include "fdt_utils.h"
#include "err_fatal.h"

/*----------------------------------------------------------------------------
 * Preprocessor Definitions and Constants
 * -------------------------------------------------------------------------*/
#define ARRAY_LENGTH(a) (sizeof(a) / sizeof((a)[0]))

/* SAIL updater GPT work buffer size */
#define SAILUPDATER_GPT_WORK_BUF_SIZE     4096


/* SAIL updater Address ranges to be accessed in the DDR */
#define SAIL_UPDATER_DDR_START_ADDR 0x30E00000
#define SAIL_UPDATER_DDR_END_ADDR   0x31000000
#define SAIL_MD_DDR_ADDR_OFFSET     0x60000000


/* Type of Operation */
typedef enum
{
    UPDATER_FLASH_OPERATION,     /** Updater Flash operation */
    UPDATER_BOOT_OPERATION,      /** Updater Boot operation */
    UPDATER_MAX_OPERATION        /** Max value for Operation */
}xSAILUpdaterCoreOperType;

/* SAIL Updater Core Context */
typedef struct
{
    spinor_handle_t norHandle;      /** SPINOR device handle */
    spinorMemInfoType memInfo;      /** SPINOR device Info */
    uint8_t* pGPTWorkBuf;           /** Pointer to the workbuffer */
    gptHeader_t PrimaryGPTHdr;      /** Primary GPT Header */
    gptHeader_t SecondaryGPTHdr;    /** Secondary GPT Header */
    gptEntryRead gptReadCb;         /** Callback for the GPT read */
    boolean  bookKeepEnable;        /** Device tree value for book keep enable/disable */
    uint32_t maxRetry;              /** Max retry count */
    boolean rollbackEnable;         /** Device tree value for Rollback enable/disable */
    boolean fixGptRebootEn;         /** Device tree value for Reboot after Fix GPT enable/disable */
    boolean eraseBookBeforeWrite;   /** Device tree value for Erase bookkeeping before Write enable/disable */
    uint32_t testcmdID;             /** Test cmd ID */
}sailUpdaterCoreCtx_t;

/* Strcuture to store the boot partition offset and index information */
typedef struct
{
    uint32_t idx;
    uint32_t startAddr;
    uint32_t size;
}__attribute__((packed)) SAILUpdaterBootPartitionoffsetTblType;

/* SAIL Updater List of Flashable Images */
static const char* cSAILUpdaterEL2FlashImglist[]=
{
    "SAIL_HYP",
    "SAIL_SW1",
    "SAIL_SW2",
    "SAIL_SW3",
    "SAIL_SW4"
};

/* SAIL Updater List of Bootable Images */
static const char* cSAILUpdaterEL2BootImglist[]=
{
    "SAIL_SW1",
};

/* SAIL Updater Workbuffer */
static uint8_t gSAILUpdaterEL2gptWorkBuf[SAILUPDATER_GPT_WORK_BUF_SIZE] __attribute__ ((aligned(EL_SHARED_CACHELINE_SIZE))); /* align to cache line in case doing cache invalidation only */

/* SAIL Updater Core Context */
sailUpdaterCoreCtx_t g_SAILUpdaterEL2CoreCtx = {0};

/* SAIL Updater Flags for debug */
static volatile boolean bSAILUpdaterCoreSkipInCRCCheck = FALSE;
static volatile boolean bSAILUpdaterCoreSkipAddrCheck = FALSE;

static SAILUpdaterCoreStatusType_e ePrvSAILUpdaterGetGPTHdr(uint32_t gpt_id,gptHeader_t *pGPTHdr);
static SAILUpdaterCoreStatusType_e ePrvSAILUpdaterVerifyGPT(uint32_t gpt_id, gptHeader_t* pGPTHdr, sailUpdaterCoreVerifyGPTtype *chkGPTparam);

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
void vSailUpdaterSetSkipAddrCheck(boolean skipVal)
{
#ifdef SAILUPDATER_TEST_SRC_ENABLED
    bSAILUpdaterCoreSkipAddrCheck = skipVal;
#endif
}

/**********************************************************
 * Gets GPT Partition Info using the GPT header provided
 *
 *
 * @param pGptHdr [IN]
 *   Pointer to the GPT Header Info
 *
 * @param pGuid [IN]
 *   GUID information for the partition
 *
 * @param pulStartAddr [IN/OUT]
 *   Start address of the Partition
 *
 * @param pulSize [IN/OUT]
 *   Size of the partition
 *
 * @param pulIndex [IN/OUT]
 *   Index of the partition entry in the GPT
 *
 * @return boolean [OUT]
 *   Result of operation.
 *     TRUE - Success
 *     FALSE - Failure
 *
 **********************************************************/
static boolean bPrvSAILUpdaterGPTGetPartitionInfo ( gptHeader_t *pGptHdr, guid_t* pGuid, uint32_t *pulStartAddr, uint32_t *pulSize , uint32_t *pulIndex)
{
    uint32_t i;
    uint32_t ulBase;
    uint32_t ulEntrySz;
    uint32_t sz;
    gptEntry_t *pEntry;

    if ( !pGptHdr  || !pGuid || !pulStartAddr || !pulSize || !pulIndex)
    {
        return FALSE;
    }
    ulBase     = ((uint32_t)(pGptHdr->partition_entry_lba & 0xFFFFFFFF)) * NOR_LBA_SZ;
    ulEntrySz  = pGptHdr->size_of_partition_entry;

    pEntry  = (gptEntry_t *)g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf;

    for ( i = 0; i < pGptHdr->number_of_partition_entries; i++ )
    {
        if (ulEntrySz != g_SAILUpdaterEL2CoreCtx.gptReadCb(g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf, (ulBase + i * ulEntrySz), ulEntrySz))
        {
            return FALSE;
        }
        if ( !gptVerifyPartitionGuid(pEntry, pGuid) )
        {
            continue;
        }
        *pulStartAddr = (uint32_t)gptGetPartitionBase ( pEntry, NOR_LBA_SZ );
        *pulSize      = (uint32_t)gptGetPartitionSize ( pEntry, NOR_LBA_SZ );
        *pulIndex = i;
        return TRUE;
    }
    return FALSE;
}

/**********************************************************
 * Swaps Partition Offset for index in the Partition Entries
 *
 *
 * @param pEntriesBuf [IN/OUT]
 *   Pointer to the Partition Entries
 *
 * @param idxA [IN]
 *   Index of 1st entry
 *
 * @param idxB [IN]
 *   Index of 2nd Entry
 *
 *
 * @return void [OUT]
 *   None
 **********************************************************/
static void vPrvSAILUpdaterSwapPartitionOffset(uint8_t *pEntriesBuf, uint32_t idxA, uint32_t idxB)
{
    uint32_t tempAddrStart, tempAddrEnd;
    gptEntry_t* pEntryA;
    gptEntry_t* pEntryB;

    if (NULL == pEntriesBuf)
    {
        return;
    }

    pEntryA  = pEntryB = (gptEntry_t *)pEntriesBuf;
    pEntryA += idxA;
    pEntryB += idxB;

    tempAddrEnd = pEntryA->ending_lba;
    tempAddrStart = pEntryA->starting_lba;

    pEntryA->ending_lba = pEntryB->ending_lba;
    pEntryA->starting_lba = pEntryB->starting_lba;

    pEntryB->ending_lba = tempAddrEnd;
    pEntryB->starting_lba = tempAddrStart;

    return;
}

/**********************************************************
 * Return the Partition Entry index for the Partition from Header and Entries
 *
 *
 * @param pGptHdr [IN]
 *   Pointer to the GPT Header
 *
 * @param pGuid [IN]
 *   GUID for the partition
 *
 * @param pEntriesBuf [IN]
 *   Pointer to the Partition Entries
 *
 *
 * @return uint32_t [OUT]
 *   Partition Entry Index
 **********************************************************/
static uint32_t ulPrvSAILUpdaterGPTGetPartitionEntryIdx ( gptHeader_t *pGptHdr, guid_t* pGuid, uint8_t *pEntriesBuf)
{
    uint32_t i;
    uint32_t sz;
    gptEntry_t *pEntry;

    if ( !pGptHdr  || !pGuid || !pEntriesBuf)
    {
        return 0xFFFFFFFF;
    }

    pEntry  = (gptEntry_t *)pEntriesBuf;

    for ( i = 0; i < pGptHdr->number_of_partition_entries; i++ )
    {
        if ( !gptVerifyPartitionGuid(pEntry, pGuid) )
        {
            pEntry++;
            continue;
        }
        return i;
    }
    return i;
}

/**********************************************************
 * Reads GPT Partition Entries into the buffer using GPT Header
 *
 *
 * @param pGptHdr [IN]
 *   Pointer to the GPT Header
 *
 * @param bufAddr [IN/OUT]
 *  Address of the buffer
 *
 * @return SAILUpdaterCoreStatusType_e [OUT]
 *   Status of the operation
 **********************************************************/
static SAILUpdaterCoreStatusType_e bPrvSAILUpdaterGPTGetPartitionEntries ( gptHeader_t *pGptHdr, uint8_t *bufAddr )
{
    uint32_t i;
    uint32_t ulBase;
    uint32_t ulEntrySz, ulReadSz;
    size_t result;

    if ( !pGptHdr  || !bufAddr)
    {
        return SAIL_UPDATER_FAIL;
    }

    ulBase     = ((uint32_t)(pGptHdr->partition_entry_lba & 0xFFFFFFFF)) * NOR_LBA_SZ;
    ulEntrySz  = pGptHdr->size_of_partition_entry;
    ulReadSz = (ulEntrySz % SPINOR_BYTES_ALIGNMENT) ? ulEntrySz + SPINOR_BYTES_ALIGNMENT - (ulEntrySz % SPINOR_BYTES_ALIGNMENT) : ulEntrySz;

    /* Read each entry start in the work buffer with aligned bytes and copy only the entries into the actual buffer */
    for ( i = 0; i < pGptHdr->number_of_partition_entries; i++ )
    {
        if (ulEntrySz != g_SAILUpdaterEL2CoreCtx.gptReadCb(g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf, (ulBase + i * ulEntrySz), ulReadSz))
        {
            return SAIL_UPDATER_FAIL;
        }

        result = sailbsp_memscpy(bufAddr, ulEntrySz, g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf, ulEntrySz);
        if(result == 0)
        {
            return SAIL_UPDATER_FAIL;
        }

        bufAddr += ulEntrySz;
    }

    return SAIL_UPDATER_SUCCESS;
}

/**********************************************************
 * Calculates the cumulative Partition CRC using the GPT header
 *
 * @param pGptHdr [IN]
 *   Pointer to the GPT header
 *
 * @param crc [IN]
 *   Pointer to the CRC value calculated
 *
 * @return boolean [OUT]
 *   Status of the operation
 **********************************************************/
boolean bPrvSAILUpdaterCalcCumPartitionCRC(gptHeader_t* pGptHdr, uint32_t *crc)
{
    uint32_t i;
    uint32_t ulBase;
    uint32_t ulEntrySz, ulReadSz;
    uint32_t initial_seed=0;

    if ( !pGptHdr  || !crc)
    {
        return FALSE;
    }

    ulBase     = ((uint32_t)(pGptHdr->partition_entry_lba & 0xFFFFFFFF)) * NOR_LBA_SZ;
    ulEntrySz  = pGptHdr->size_of_partition_entry;
    ulReadSz = (ulEntrySz % SPINOR_BYTES_ALIGNMENT) ? ulEntrySz + SPINOR_BYTES_ALIGNMENT - (ulEntrySz % SPINOR_BYTES_ALIGNMENT) : ulEntrySz;

    /* Read each entry start in the work buffer with aligned bytes and copy only the entries into the actual buffer */
    for ( i = 0; i < pGptHdr->number_of_partition_entries; i++ )
    {
        if (ulEntrySz != g_SAILUpdaterEL2CoreCtx.gptReadCb(g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf, (ulBase + i * ulEntrySz), ulReadSz))
        {
            *crc=0;
            return FALSE;
        }
        initial_seed = gptCalcCRC32 ((const uint8_t *) g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf, ulEntrySz, initial_seed);
    }

    *crc = initial_seed;
    return TRUE;

}

/**********************************************************
 * Reconstruct Alternate GPT using Source GPT Header
 *
 * @param norHandle [IN]
 *   Handle for the NOR flash
 *
 * @param pGptHdr [IN]
 *   Pointer to the Source GPT Header
 *
 * @param isSwapNeeded [IN]
 *    Is Swapping of the offsets of boot partitions from GPT needed
 *
 * @return SAILUpdaterCoreStatusType_e [OUT]
 *   Status of the operation
 **********************************************************/
static SAILUpdaterStatusType_e xPrvSAILUpdaterReconstructAltGPT ( void *norHandle, gptHeader_t *pGptHdr, boolean isSwapNeeded)
{
    uint32_t i;
    uint32_t ulBase;
    uint32_t ulEntrySz, ulReadSz;
    uint32_t byte_offset=0;
    uint32_t result;
    uint32_t ulEntrySzErase=0, ulEraseLBA;
    uint32_t block_size=0;
    gptHeader_t xGptHdr = {0}, tempGptHdr={0};
    uint32_t srcGPTId, altGPTId;
    sailUpdaterCoreVerifyGPTtype xGPTparam= {0};
    spinorMemInfoType memInfo = {0};
    uint64_t temp_lba, destHdrLba;
    uint32_t tempCrc,ulWriteSz;
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;

    char imgGuid[GUID_STRING_SIZE+1] = "";
    guid_t tmpGuid={0};
    uint32_t partitionId, tblIdx=0, tempidx;
    uint32_t partitionAddr, partitionSize,pulIndex;
    SAILUpdaterBootPartitionoffsetTblType imgoffsetTbl[2*ARRAY_LENGTH(cSAILUpdaterEL2FlashImglist)]={0};
    gptEntry_t *pEntry  = NULL;
    int j=0;

    if ( NULL == pGptHdr)
    {
        DEBUG_LOG(SAIL_ERROR,"%s:  pGptHdr is NULL\n\r", __func__);
        return SAIL_UPDATER_STATUS_FAIL;
    }

    if (NULL == norHandle)
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Spinor handle passed is NULL \n\r", __func__);
        return SAIL_UPDATER_STATUS_FAIL;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl2GetMemInfo((spinor_handle_t)norHandle, &memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Spinor Get Mem Info failed \n\r", __func__);
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto updaterGPTEnd;
    }

    if (TRUE == isSwapNeeded)
    {
        tblIdx= 0;
        /* Validate the Image and then compare the CRC for the primary and Backup partitions for each image */
        for(int imageId = 0; imageId < ARRAY_LENGTH(cSAILUpdaterEL2FlashImglist) ; imageId++)
        {
            for(partitionId = XBL_PARTITION_A; partitionId <= XBL_PARTITION_B; partitionId++)
            {
                /* Get the GUID for the Image */
                if(sailhyp_xbl_getImgGUID(cSAILUpdaterEL2FlashImglist[imageId], partitionId, SAIL_UPD_GPT_ID_PRIMARY, imgGuid))
                {
                    DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCheckbootPartition: Get Image GUID failed \n\r");
                    eStatus = SAIL_UPDATER_STATUS_FAIL;
                    goto updaterGPTEnd;
                }

                if(FALSE == gptDecodeGUIDString ( imgGuid, &tmpGuid))
                {
                    DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Converting GUID String to GUID for Image GUID_A failed \n\r");
                    eStatus = SAIL_UPDATER_STATUS_FAIL;
                    goto updaterGPTEnd;
                }

                /* Get the Partition Info A and B partitions for Image from Primary Header */
                if(FALSE == bPrvSAILUpdaterGPTGetPartitionInfo (pGptHdr, &tmpGuid, &partitionAddr, &partitionSize, &pulIndex ))
                {
                    DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Get Partition Info from Primary GPT for Image GUID_A failed \n\r");
                    eStatus = SAIL_UPDATER_STATUS_FAIL;
                    goto updaterGPTEnd;
                }

                imgoffsetTbl[tblIdx].idx = pulIndex;
                imgoffsetTbl[tblIdx].startAddr = partitionAddr;
                imgoffsetTbl[tblIdx].size = partitionSize;
                tblIdx++;
            }
            /* swap A and B offset's index in the table  for every image so when we are out of the loop, the index and partition offset size values is already swapped locally */
            tempidx = imgoffsetTbl[tblIdx - 2].idx;
            imgoffsetTbl[tblIdx - 2].idx = imgoffsetTbl[tblIdx - 1].idx;
            imgoffsetTbl[tblIdx-1].idx = tempidx;
        }
    }

    /* If the source GPT header is Primary */
    if (TRUE == gptIsPrimaryHeader(pGptHdr))

    {
        srcGPTId = SAIL_UPD_GPT_ID_PRIMARY;
        altGPTId = SAIL_UPD_GPT_ID_SECONDARY;
        ulBase     = ((uint32_t)(pGptHdr->partition_entry_lba & 0xFFFFFFFF)) * NOR_LBA_SZ; // to read the partition entries
        ulEntrySz  = pGptHdr->size_of_partition_entry;
        ulReadSz = (ulEntrySz % SPINOR_BYTES_ALIGNMENT) ? ulEntrySz + SPINOR_BYTES_ALIGNMENT - (ulEntrySz % SPINOR_BYTES_ALIGNMENT) : ulEntrySz;

        /* Source GPT is Primary. Calculate Secondary GPT offsets */
        byte_offset = pGptHdr->alternate_lba - (pGptHdr->first_usable_lba - pGptHdr->partition_entry_lba);  // to write the partition entries
        ulEraseLBA = pGptHdr->alternate_lba - (pGptHdr->first_usable_lba - pGptHdr->partition_entry_lba);  // erase LBA
        ulEntrySzErase = (pGptHdr->first_usable_lba - pGptHdr->partition_entry_lba) + (memInfo.block_count - pGptHdr->alternate_lba);
    }
    else
    {
        srcGPTId = SAIL_UPD_GPT_ID_SECONDARY;
        altGPTId = SAIL_UPD_GPT_ID_PRIMARY;
        ulBase     = ((uint32_t)(pGptHdr->partition_entry_lba & 0xFFFFFFFF)) * NOR_LBA_SZ; // to read the partition entries
        ulEntrySz  = pGptHdr->size_of_partition_entry;
        ulReadSz = (ulEntrySz % SPINOR_BYTES_ALIGNMENT) ? ulEntrySz + SPINOR_BYTES_ALIGNMENT - (ulEntrySz % SPINOR_BYTES_ALIGNMENT) : ulEntrySz;

        /* Source GPT is Secondary. Calculate Primary GPT  offsets */
        byte_offset = pGptHdr->alternate_lba + 1;  // to write the partition entries
        ulEraseLBA = pGptHdr->alternate_lba;  // erase LBA
        ulEntrySzErase =  pGptHdr->first_usable_lba - pGptHdr->alternate_lba; // erase size
    }

    DEBUG_LOG(SAIL_WARNING,"%s: Erasing GPT Header and Partition entries for GPT ID = %d  \n\r", __func__, altGPTId);

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if ( (SAIL_OTA_TRIG_ERROR_ER_FIXGPTCCORRUPTION_XBL == g_SAILUpdaterEL2CoreCtx.testcmdID)
        || (SAIL_OTA_TRIG_ERROR_ER_GPT_ROLLBACK_XBL == g_SAILUpdaterEL2CoreCtx.testcmdID)
        )
    {
        /* Erasing 1 4K block */
        ulEntrySzErase = 1;
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    /* Erase the Destination GPT Header and partition entries  */
    if(SPINOR_DEVICE_DONE != spinorEl2Erase ((spinor_handle_t)norHandle, ulEraseLBA, ulEntrySzErase))
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Erase GPT Header and Partition entries for GPT ID = %d failed \n\r", __func__, altGPTId);
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto updaterGPTEnd;
    }
#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if ( (SAIL_OTA_TRIG_ERROR_ER_FIXGPTCCORRUPTION_XBL == g_SAILUpdaterEL2CoreCtx.testcmdID)
         || (SAIL_OTA_TRIG_ERROR_ER_GPT_ROLLBACK_XBL == g_SAILUpdaterEL2CoreCtx.testcmdID)
         )
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Forced crash due to trigger testcmdID=%d \n\r", __func__, g_SAILUpdaterEL2CoreCtx.testcmdID);
        err_fatal(SAIL_UPDATER,ERR_FATAL_FORCED_REBOOT);
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    block_size = memInfo.pages_per_block * memInfo.page_size_bytes;

    /* Read each entry start in the work buffer with aligned bytes and copy only the entries into the actual buffer */
    for ( i = 0; i < pGptHdr->number_of_partition_entries; i++ )
    {
        if (ulEntrySz != g_SAILUpdaterEL2CoreCtx.gptReadCb(g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf, (ulBase + i * ulEntrySz), ulReadSz))
        {
            DEBUG_LOG(SAIL_ERROR,"%s: Read partition entry %d failed \n\r", __func__, i);
            return SAIL_UPDATER_STATUS_FAIL;
        }

        if (TRUE == isSwapNeeded)
        {
            /* Check if the index is in the imgoffsetTbl. if yes then we have to use the values from the able in the work buffer */
            for (j=0;j < ARRAY_LENGTH(imgoffsetTbl);j++)
            {
                /* If offset found in table then update in work buffer */
                if (imgoffsetTbl[j].idx == i)
                {
                    pEntry = (gptEntry_t *)g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf;
                    pEntry->starting_lba = (imgoffsetTbl[j].startAddr/NOR_LBA_SZ);
                    pEntry->ending_lba = pEntry->starting_lba+(imgoffsetTbl[j].size/NOR_LBA_SZ)-1;
                    break;
                }
            }
        }

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
        if ( (SAIL_OTA_TRIG_ERROR_WR_ENTRY_FIXGPTCCORRUPTION_XBL == g_SAILUpdaterEL2CoreCtx.testcmdID)
            || (SAIL_OTA_TRIG_ERROR_WR_ENTRY_GPT_ROLLBACK_XBL == g_SAILUpdaterEL2CoreCtx.testcmdID)
            )

        {
            /* set the write transfer size to SPINOR_BYTES_ALIGNMENT*5 bytes so that it is less than 1 partition entry and aligned*/
            ulEntrySz = SPINOR_BYTES_ALIGNMENT*5;
        }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

        /* Write to the partition */
        if( SPINOR_DEVICE_DONE != spinorEl2Write ( (spinor_handle_t)norHandle, (byte_offset*block_size)+(i*ulEntrySz), ulEntrySz, (void *)g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf) )
        {
            DEBUG_LOG(SAIL_ERROR,"%s: Write Partition entry %d failed \n\r", __func__, i);
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
            goto updaterGPTEnd;
        }
#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
        if( (SAIL_OTA_TRIG_ERROR_WR_ENTRY_FIXGPTCCORRUPTION_XBL == g_SAILUpdaterEL2CoreCtx.testcmdID)
            || (SAIL_OTA_TRIG_ERROR_WR_ENTRY_GPT_ROLLBACK_XBL == g_SAILUpdaterEL2CoreCtx.testcmdID)
            )
        {
            DEBUG_LOG(SAIL_ERROR,"%s: Forced crash due to trigger testcmdID=%d \n\r", __func__, g_SAILUpdaterEL2CoreCtx.testcmdID);
            err_fatal(SAIL_UPDATER,ERR_FATAL_FORCED_REBOOT);
        }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED
    }

    /* Copy the source GPT header to a temporary location */
    result = sailbsp_memscpy(&xGptHdr, sizeof(gptHeader_t), pGptHdr, sizeof(gptHeader_t));
    if(result == 0)
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Copy GPT header from Source to temp location failed \n\r", __func__);
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto updaterGPTEnd;
    }

    /* Modify the contents of the destination GPT Header to make it valid */
    xGptHdr.header_crc32 = 0;
    temp_lba = xGptHdr.my_lba;
    xGptHdr.my_lba = xGptHdr.alternate_lba;
    xGptHdr.alternate_lba = temp_lba;

    if (TRUE == gptIsPrimaryHeader(pGptHdr))
    {
        /* For Secondary GPT */
        xGptHdr.partition_entry_lba = pGptHdr->alternate_lba - (pGptHdr->first_usable_lba - pGptHdr->partition_entry_lba);
    }
    else
    {
        /* For Primary GPT */
        xGptHdr.partition_entry_lba = pGptHdr->alternate_lba + 1;
    }

    /* If partition offsets are swapped, then the partition CRC needs to be calculated */
    if (TRUE == isSwapNeeded)
    {
        if(FALSE == bPrvSAILUpdaterCalcCumPartitionCRC(&xGptHdr, &tempCrc))
        {
            DEBUG_LOG(SAIL_ERROR,"%s: Calculating Cumulative partition CRC failed \n\r", __func__);
            eStatus = SAIL_UPDATER_STATUS_FAIL;
            goto updaterGPTEnd;

        }
        xGptHdr.partition_entries_crc32 = tempCrc;
    }

    /* Calculate new Header CRC */
    tempCrc = gptCalcCRC32 ((const uint8_t *) &xGptHdr, xGptHdr.header_size, GPT_CRC32_SEED_DEFAULT);
    xGptHdr.header_crc32 = tempCrc;

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if ( (SAIL_OTA_TRIG_ERROR_WR_HDR_FIXGPTCCORRUPTION_XBL == g_SAILUpdaterEL2CoreCtx.testcmdID)
         || (SAIL_OTA_TRIG_ERROR_WR_HDR_GPT_ROLLBACK_XBL == g_SAILUpdaterEL2CoreCtx.testcmdID)
        )
    {
        /* swap bits the CRC*/
        xGptHdr.header_crc32 = ~xGptHdr.header_crc32;
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    /* Copy the GPT header from temp location to Destination buffer */
    result = sailbsp_memscpy( (void *)g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf, sizeof(gptHeader_t), &xGptHdr, sizeof(gptHeader_t));
    if(result == 0)
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Copy GPT header from Source to destination buffer failed \n\r", __func__);
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto updaterGPTEnd;
    }

    ulWriteSz = (sizeof(gptHeader_t) % SPINOR_BYTES_ALIGNMENT) ? sizeof(gptHeader_t) + SPINOR_BYTES_ALIGNMENT - (sizeof(gptHeader_t) % SPINOR_BYTES_ALIGNMENT) : sizeof(gptHeader_t);

    /* If the Write size is not aligned, then pad FFs to the data and write */
    if( (ulWriteSz != sizeof(gptHeader_t)) && (ulWriteSz > sizeof(gptHeader_t)))
    {
        memset((void *)(g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf + sizeof(gptHeader_t)), 0xFF, (ulWriteSz - sizeof(gptHeader_t)));
    }

    /* Calcuate the buffer offsets for the destination from the Alt GPT header */
    destHdrLba = xGptHdr.my_lba;

    /* Flush and Invalidate the cache for the address containing the destination content */
    clean_invalidate_cache_by_range((uint32) g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf, (uint32)g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf + ulWriteSz);

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if ( (SAIL_OTA_TRIG_ERROR_WR_HDR_FIXGPTCCORRUPTION_XBL == g_SAILUpdaterEL2CoreCtx.testcmdID)
         || (SAIL_OTA_TRIG_ERROR_WR_HDR_GPT_ROLLBACK_XBL == g_SAILUpdaterEL2CoreCtx.testcmdID)
        )
    {
        /* set the write transfer size to SPINOR_BYTES_ALIGNMENT*5 bytes so that it is less than 1 gpt header size and aligned*/
        ulWriteSz = SPINOR_BYTES_ALIGNMENT*5;
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    /* Write the Destination GPT header */
    if( SPINOR_DEVICE_DONE != spinorEl2Write ( (spinor_handle_t)norHandle, destHdrLba * block_size, ulWriteSz, (void *)g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf))
    {
        DEBUG_LOG(SAIL_ERROR,"%s: GPT Header Write Failed \n\r", __func__);
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto updaterGPTEnd;
    }

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if ( (SAIL_OTA_TRIG_ERROR_WR_HDR_FIXGPTCCORRUPTION_XBL == g_SAILUpdaterEL2CoreCtx.testcmdID)
         || (SAIL_OTA_TRIG_ERROR_WR_HDR_GPT_ROLLBACK_XBL == g_SAILUpdaterEL2CoreCtx.testcmdID)
         )
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Forced crash due to trigger testcmdID=%d \n\r", __func__,g_SAILUpdaterEL2CoreCtx.testcmdID);
        err_fatal(SAIL_UPDATER,ERR_FATAL_FORCED_REBOOT);
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    /* Check the GPT health of Destination GPT */
    if (SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(altGPTId, &tempGptHdr, &xGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Getting GPT health for verifying update failed for GPT ID =%d\n\r", __func__, altGPTId);
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto updaterGPTEnd;
    }

    if ((0 == xGPTparam.EntryCrcStatus) || (0 == xGPTparam.HeaderCrcStatus))
    {
        DEBUG_LOG(SAIL_ERROR,"%s: GPT ID=%d  header Invalid EntryCrcStatus = %d, HeaderCrcStatus = %d headerCRC = 0x%x partitionCRC = 0x%x num_partitions=0x%x \n\r", __func__, altGPTId,
                  xGPTparam.EntryCrcStatus, xGPTparam.HeaderCrcStatus, tempGptHdr.header_crc32, tempGptHdr.partition_entries_crc32, tempGptHdr.number_of_partition_entries);
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto updaterGPTEnd;
    }

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if ( (SAIL_OTA_TRIG_ERROR_POST_FIXGPTCORRUPTION_XBL == g_SAILUpdaterEL2CoreCtx.testcmdID)
         || (SAIL_OTA_TRIG_ERROR_POST_GPT_ROLLBACK == g_SAILUpdaterEL2CoreCtx.testcmdID)
         )
    {
        DEBUG_LOG(SAIL_ERROR, "%s: Forced crash due to trigger testcmdID=%d \n\r", __func__, g_SAILUpdaterEL2CoreCtx.testcmdID);
        err_fatal(SAIL_UPDATER,ERR_FATAL_FORCED_REBOOT);
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    DEBUG_LOG(SAIL_WARNING, "%s: GPT ID=%d GPT header valid EntryCrc=0x%x HeaderCrc=0x%x number_of_partition_entries=0x%x\n\r", __func__,altGPTId,
              tempGptHdr.partition_entries_crc32, tempGptHdr.header_crc32, tempGptHdr.number_of_partition_entries);

updaterGPTEnd:
    return eStatus;
}

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
SAILUpdaterStatusType_e xSAILUpdaterCoreGetTrueSwap ( void *norHandle, boolean *pTrueSwap)
{
    spinorMemInfoType memInfo = {0};
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;

    char imgGuid[GUID_STRING_SIZE+1] = "";
    guid_t tmpGuid={0};
    uint32_t partitionId, tblIdx=0;
    uint32_t partitionAddr, partitionSize,pulIndex;
    SAILUpdaterBootPartitionoffsetTblType imgoffsetTbl[2*ARRAY_LENGTH(cSAILUpdaterEL2FlashImglist)]={0};
	gptHeader_t xPrimGptHdr;
	gptHeader_t xSecGptHdr;

    if ( NULL == pTrueSwap)
    {
        DEBUG_LOG(SAIL_ERROR,"%s:  pTrueSwap is NULL\n\r", __func__);
        return SAIL_UPDATER_STATUS_FAIL;
    }

    if (NULL == norHandle)
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Spinor handle passed is NULL \n\r", __func__);
        return SAIL_UPDATER_STATUS_FAIL;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl2GetMemInfo((spinor_handle_t)norHandle, &memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Spinor Get Mem Info failed \n\r", __func__);
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto trueSwapGPTEnd;
    }

	/* If the 2 CRCs are not matching, then get the true swap value based on the SAILHYP partition of the 2 GPTs  */
	if( SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterGetGPTHdr(SAIL_UPD_GPT_ID_PRIMARY, &xPrimGptHdr))
	{
		DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreGetTrueSwap: Read Primary GPT header failed \n\r");
		eStatus = SAIL_UPDATER_STATUS_FAIL;
		goto trueSwapGPTEnd;
	}

	if( SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterGetGPTHdr(SAIL_UPD_GPT_ID_SECONDARY, &xSecGptHdr))
	{
		DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreGetTrueSwap: Read Secondary GPT header failed \n\r");
		eStatus = SAIL_UPDATER_STATUS_FAIL;
		goto trueSwapGPTEnd;
	}

	tblIdx= 0;
	/*primary partition: xbl partition A and B*/
	for(partitionId = XBL_PARTITION_A; partitionId <= XBL_PARTITION_B; partitionId++)
	{
		/* Get the GUID for the sailhyp */
		if(sailhyp_xbl_getImgGUID(cSAILUpdaterEL2FlashImglist[0], partitionId, SAIL_UPD_GPT_ID_PRIMARY, imgGuid))
		{
			DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreGetTrueSwap: Get Image GUID failed \n\r");
			eStatus = SAIL_UPDATER_STATUS_FAIL;
			goto trueSwapGPTEnd;
		}

		if(FALSE == gptDecodeGUIDString ( imgGuid, &tmpGuid))
		{
			DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreGetTrueSwap: Converting GUID String to GUID for Image GUID_A failed \n\r");
			eStatus = SAIL_UPDATER_STATUS_FAIL;
			goto trueSwapGPTEnd;
		}

		/* Get the Partition Info A and B partitions for Image from Primary Header */
		if(FALSE == bPrvSAILUpdaterGPTGetPartitionInfo (&xPrimGptHdr, &tmpGuid, &partitionAddr, &partitionSize, &pulIndex ))
		{
			DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreGetTrueSwap: Get Partition Info from Primary GPT for Image GUID_A failed \n\r");
			eStatus = SAIL_UPDATER_STATUS_FAIL;
			goto trueSwapGPTEnd;
		}

        /*Saving the address of the partition in the index of the table*/
		imgoffsetTbl[tblIdx].idx = partitionAddr;
		tblIdx++;
	}

	/*secondary partition: xbl partition A and B for sailhyp image*/
	for(partitionId = XBL_PARTITION_A; partitionId <= XBL_PARTITION_B; partitionId++)
	{
		/* Get the GUID for the sailhyp */
		if(sailhyp_xbl_getImgGUID(cSAILUpdaterEL2FlashImglist[0], partitionId, SAIL_UPD_GPT_ID_PRIMARY, imgGuid))
		{
			DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreGetTrueSwap: Get Image GUID failed \n\r");
			eStatus = SAIL_UPDATER_STATUS_FAIL;
			goto trueSwapGPTEnd;
		}

		if(FALSE == gptDecodeGUIDString ( imgGuid, &tmpGuid))
		{
			DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreGetTrueSwap: Converting GUID String to GUID for Image GUID_A failed \n\r");
			eStatus = SAIL_UPDATER_STATUS_FAIL;
			goto trueSwapGPTEnd;
		}

		/* Get the Partition Info A and B partitions for Image from secondary Header */
		if(FALSE == bPrvSAILUpdaterGPTGetPartitionInfo (&xSecGptHdr, &tmpGuid, &partitionAddr, &partitionSize, &pulIndex ))
		{
			DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreGetTrueSwap: Get Partition Info from Primary GPT for Image GUID_A failed \n\r");
			eStatus = SAIL_UPDATER_STATUS_FAIL;
			goto trueSwapGPTEnd;
		}
		imgoffsetTbl[tblIdx].idx = partitionAddr;
		tblIdx++;
	}

	if( (imgoffsetTbl[0].idx == imgoffsetTbl[2].idx) && (imgoffsetTbl[1].idx == imgoffsetTbl[3].idx) )
	{
		*pTrueSwap = FALSE;
	}
	else
	{
		*pTrueSwap = TRUE;
	}

trueSwapGPTEnd:
    return eStatus;
}

/**********************************************************
 * Reads GPT Header into the buffer
 *
 *
 * @param gpt_id [IN]
 *   GPT Header ID
 *
 * @param pGPTHdr [IN/OUT]
 *  Address of the buffer
 *
 * @return SAILUpdaterCoreStatusType_e [OUT]
 *   Status of the operation
 **********************************************************/
static SAILUpdaterCoreStatusType_e ePrvSAILUpdaterGetGPTHdr(uint32_t gpt_id, gptHeader_t *pGPTHdr)
{
    uint32_t startAddr,sz;
    size_t result;

    startAddr = (SAIL_UPD_GPT_ID_PRIMARY == gpt_id) ? NOR_LBA_SZ : (SAIL_UPD_GPT_ID_SECONDARY == gpt_id) ? (g_SAILUpdaterEL2CoreCtx.memInfo.block_count - 1) * NOR_LBA_SZ : 0;

    if (0 == startAddr)
    {
        return SAIL_UPDATER_FAIL;
    }

    sz = (sizeof(gptHeader_t) % SPINOR_BYTES_ALIGNMENT) ? sizeof(gptHeader_t) + SPINOR_BYTES_ALIGNMENT - (sizeof(gptHeader_t) % SPINOR_BYTES_ALIGNMENT) : sizeof(gptHeader_t);

    if (sz != g_SAILUpdaterEL2CoreCtx.gptReadCb(g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf, startAddr, sz))
    {
        return SAIL_UPDATER_FAIL;
    }

    result = sailbsp_memscpy(pGPTHdr, sizeof(gptHeader_t), g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf, sizeof(gptHeader_t));
    if(result == 0)
    {
        return SAIL_UPDATER_FAIL;
    }

    return SAIL_UPDATER_SUCCESS;
}

/**********************************************************
 * Updates the status of the GPT validity
 *
 *
 * @param gpt_id [IN]
 *   GPT Header ID
 *
 * @param pGPTHdr [IN/OUT]
 *  Address of the buffer for GPT Header
 *
 * @param chkGPTparam [IN/OUT]
 *  Address of the buffer to update validity info
 *
 * @return SAILUpdaterCoreStatusType_e [OUT]
 *   Status of the operation
 **********************************************************/
static SAILUpdaterCoreStatusType_e ePrvSAILUpdaterVerifyGPT(uint32_t gpt_id, gptHeader_t* pGPTHdr, sailUpdaterCoreVerifyGPTtype *chkGPTparam)
{
    uint32_t hdrSz = 0, partEntriesSz = 0;

    if( SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterGetGPTHdr(gpt_id,pGPTHdr))
    {
        return SAIL_UPDATER_FAIL;;
    }

    /* verify GPT header CRC */
    if (FALSE == gptVerifyHeaderCRC32(pGPTHdr, GPT_CRC32_SEED_DEFAULT))
    {
        chkGPTparam->HeaderCrcStatus = 0;
        chkGPTparam->EntryCrcStatus = 0;
        chkGPTparam->GptSize = 0;
        return SAIL_UPDATER_SUCCESS;
    }
    else
    {
        chkGPTparam->HeaderCrcStatus = 1;
    }

    /* verify Partition Entry CRC */
    if (FALSE == gptVerifyPartitionEntryCRC32(pGPTHdr, g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf, g_SAILUpdaterEL2CoreCtx.gptReadCb, NOR_LBA_SZ, GPT_CRC32_SEED_DEFAULT))
    {
        chkGPTparam->EntryCrcStatus = 0;
        chkGPTparam->GptSize=0;
        return SAIL_UPDATER_SUCCESS;
    }
    else
    {
        chkGPTparam->EntryCrcStatus = 1;
    }

    hdrSz = sizeof(gptHeader_t);
    partEntriesSz = gptGetPartitionEntrySize(pGPTHdr) * gptGetNumOfPartitionEntrys(pGPTHdr);

    chkGPTparam->GptSize = hdrSz + partEntriesSz;

    return SAIL_UPDATER_SUCCESS;
}

/**********************************************************
 * Checks for Image valid for the operation
 *
 *
 * @param oper [IN]
 *   Type of operation for the image
 *
 * @param imgName [IN]
 *  Image Name
 *
 * @return boolean [OUT]
 *   Status of the operation
 *      TRUE - Image Valid for the operation
 *      FALSE - Image invalid for the operation
 **********************************************************/
static boolean bPrvSAILUpdaterCoreIsValidImg(xSAILUpdaterCoreOperType oper, const char *imgName)
{
    if (UPDATER_MAX_OPERATION <= oper)
    {
        return FALSE;
    }

    if (UPDATER_FLASH_OPERATION == oper)
    {
        for (int i = 0; i < ARRAY_LENGTH(cSAILUpdaterEL2FlashImglist); i++)
        {
            if (strlen(imgName) != strlen(cSAILUpdaterEL2FlashImglist[i]) )
            {
                continue;
            }
            if (0 == strncmp(cSAILUpdaterEL2FlashImglist[i], imgName,strlen(cSAILUpdaterEL2FlashImglist[i])))
            {
                return TRUE;
            }
        }
        return FALSE;
    }
    else if (UPDATER_BOOT_OPERATION == oper)
    {
        for (int i = 0; i < ARRAY_LENGTH(cSAILUpdaterEL2BootImglist); i++)
        {
            if (strlen(imgName) != strlen(cSAILUpdaterEL2BootImglist[i]) )
            {
                continue;
            }
            if (0 == strncmp(cSAILUpdaterEL2BootImglist[i], imgName,strlen(cSAILUpdaterEL2BootImglist[i])))
            {
                return TRUE;
            }
        }
        return FALSE;
    }
    else
    {
        return FALSE;
    }
}

/**********************************************************
 * Checks for Address range is in range
 *
 *
 * @param ulStartAddr [IN]
 *   Start Address
 *
 * @param ulSize [IN]
 *  Size
 *
 * @return boolean [OUT]
 *   Status of the operation
 *      TRUE - Address in valid range
 *      FALSE - Address not in valid range
 **********************************************************/
static boolean bPrvSAILUpdaterCoreIsAddrInRange(uint32_t ulStartAddr, uint32_t ulSize)
{
    if (TRUE == bSAILUpdaterCoreSkipAddrCheck)
    {
        return TRUE;
    }
    else
    {
        uint32_t ulEndAddr = ulStartAddr + ulSize;

        /* If there is an overflow return error */
        if ( (ulEndAddr < ulStartAddr))
        {
            return FALSE;
        }

        /* Return Error if size of region is more than Address range for SAIL Updater */
        if ((SAIL_UPDATER_DDR_END_ADDR - SAIL_UPDATER_DDR_START_ADDR) < ulSize)
        {
            return FALSE;
        }

        /* [start,x,end] => valid range */
        /* Return Error If Start/end address is outside of the Address range for SAIL Updater */
        if ( (ulStartAddr < SAIL_UPDATER_DDR_START_ADDR) ||
             (ulStartAddr > SAIL_UPDATER_DDR_END_ADDR) ||
             (ulEndAddr > SAIL_UPDATER_DDR_END_ADDR)
           )
        {
            return FALSE;
        }

        return TRUE;
    }
}

/**********************************************************
 * Checks for CRC value matches
 *
 *
 * @param valA [IN]
 *   Value 1
 *
 * @param valB [IN]
 *   Value 2
 *
 * @return boolean [OUT]
 *   Status of the operation
 *      TRUE - CRC values mismatch
 *      FALSE - CRC values match
 **********************************************************/
static boolean bPrvSAILUpdaterCoreIsCRCNotMatch(uint32_t valA, uint32_t valB)
{
    if (TRUE == bSAILUpdaterCoreSkipInCRCCheck)
    {
        return FALSE;
    }
    return (valA != valB);
}

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
SAILUpdaterStatusType_e xSAILUpdaterCoreReconstructAltGPT(void *norHandle, uint32_t sourceGptId, boolean isSwapNeeded)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;
    sailUpdaterCoreVerifyGPTtype xGPTparam ={0};
    gptHeader_t xGPTHdr={0};

    if(NULL == norHandle)
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Spinor Handle is NULL \n\r", __func__);
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ReconstructAltGPTEnd;
    }

    /* Check the GPT health of GPT */
    if (SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(sourceGptId, &xGPTHdr, &xGPTparam))
    {
         DEBUG_LOG(SAIL_ERROR,"%s: Getting GPT health for Source GPT ID=%d failed \n\r", __func__, sourceGptId);
         eStatus = SAIL_UPDATER_STATUS_FAIL;
         goto ReconstructAltGPTEnd;
    }

    if ((0 == xGPTparam.EntryCrcStatus) || (0 == xGPTparam.HeaderCrcStatus))
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Source GPT header Invalid headerID = %d EntryCrcStatus = %d HeaderCrcStatus = %d \n\r", __func__, sourceGptId, xGPTparam.EntryCrcStatus, xGPTparam.HeaderCrcStatus);
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ReconstructAltGPTEnd;
    }

    DEBUG_LOG(SAIL_WARNING, "%s: Source GPT header valid headerID = %d EntryCrc=0x%x HeaderCrc=0x%x number_of_partition_entries=0x%x\n\r", __func__,
              sourceGptId, xGPTHdr.partition_entries_crc32, xGPTHdr.header_crc32, xGPTHdr.number_of_partition_entries);

    DEBUG_LOG(SAIL_WARNING, "%s: Reconstructing from source GPT ID = %d SwapNeeded=0x%x\n\r", __func__,
              sourceGptId, isSwapNeeded);

    /* Construct and update the Alternate GPT using Source GPT */
    if(SAIL_UPDATER_SUCCESS != xPrvSAILUpdaterReconstructAltGPT(norHandle, &xGPTHdr, isSwapNeeded))
    {
          DEBUG_LOG(SAIL_ERROR,"%s: Updating GPT ID=%d to Alternate GPT Failed\n\r", __func__, sourceGptId);
          eStatus = SAIL_UPDATER_STATUS_FAIL;
          goto ReconstructAltGPTEnd;
    }

ReconstructAltGPTEnd:
    return eStatus;
}

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
SAILUpdaterStatusType_e xSAILUpdaterCoreVerifyGPTWrap(uint32_t gptId, uint32_t *crc32, uint32_t *hdrCrcStatus, uint32_t *entryCrcStatus)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;
    sailUpdaterCoreVerifyGPTtype xPrimaryGPTparam={0}, xSecondaryGPTparam ={0};
    gptHeader_t PrimaryGPTHdr = {0}, SecondaryGPTHdr = {0};

    if (gptId == SAIL_UPD_GPT_ID_PRIMARY)
    {
        /* Check the GPT health of Primary GPT */
        if (SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(SAIL_UPD_GPT_ID_PRIMARY, &PrimaryGPTHdr, &xPrimaryGPTparam))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreVerifyGPTWrap: Getting Primary GPT health failed \n\r");
            eStatus = SAIL_UPDATER_STATUS_FAIL;
            *crc32 = 0U;
            *hdrCrcStatus = 0U;
            *entryCrcStatus = 0U;
            goto verifyGPTWrapEnd;
        }
        *crc32 = PrimaryGPTHdr.partition_entries_crc32;
        *hdrCrcStatus = xPrimaryGPTparam.HeaderCrcStatus;
        *entryCrcStatus = xPrimaryGPTparam.EntryCrcStatus;
    }
    else if (gptId == SAIL_UPD_GPT_ID_SECONDARY)
    {
        /* Check the GPT health of Secondary GPT */
        if (SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(SAIL_UPD_GPT_ID_SECONDARY, &SecondaryGPTHdr, &xSecondaryGPTparam))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreVerifyGPTWrap: Getting Secondary GPT health failed \n\r");
            eStatus = SAIL_UPDATER_STATUS_FAIL;
            *crc32 = 0U;
            *hdrCrcStatus = 0U;
            *entryCrcStatus = 0U;
            goto verifyGPTWrapEnd;
        }
        *crc32 = SecondaryGPTHdr.partition_entries_crc32;
        *hdrCrcStatus = xSecondaryGPTparam.HeaderCrcStatus;
        *entryCrcStatus = xSecondaryGPTparam.EntryCrcStatus;
    }
    else
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreVerifyGPTWrap: gpt id Invalid\n\r");
        *crc32 = 0U;
        *hdrCrcStatus = 0U;
        *entryCrcStatus = 0U;
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto verifyGPTWrapEnd;
    }

verifyGPTWrapEnd:
    return eStatus;
}

/**********************************************************
 * Read SAIl hyp devicetree
 *
 *
 * @return SAILUpdaterStatusType_e [OUT]
 *   Status of the Initalization
 *
 **********************************************************/
static SAILUpdaterCoreStatusType_e xSAILUpdaterReadDtbUpdateBookkeep (void)
{
    SAILUpdaterCoreStatusType_e eStatus = SAIL_UPDATER_SUCCESS;
    int retval;
    void *pDTB = NULL;
    int32_t root_offset = 0;
    uint32_t bookKeepEnable=0;
    uint32_t maxRetry = 0;
    uint32_t rollbackEnable = 0;
    uint32_t fixGptReboot = 0, testcmdID = 0;
    uint32_t eraseBookBeforeWrite = 0;

    /* Get the DTB entries for fastboot/devprgm GPIO configuration */
    pDTB = fdt_get_dtb();
    if (NULL != pDTB)
    {
        root_offset = fdt_path_offset(pDTB, "/sailUpdater");
        if(root_offset > 0)
        {
             /* if any of the DTB entries are missing, skip entering book keep OTA flow */
             retval = fdt_getprop_u32(pDTB, root_offset, "bookkeeping_enable", &bookKeepEnable);
             retval |= fdt_getprop_u32(pDTB, root_offset, "max_retry", &maxRetry);
             retval |= fdt_getprop_u32(pDTB, root_offset, "rollback_enable", &rollbackEnable);
             retval |= fdt_getprop_u32(pDTB, root_offset, "reboot_after_fixgpt", &fixGptReboot);
#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
             retval |= fdt_getprop_u32(pDTB, root_offset, "sailupdatertestCMDID", &testcmdID);
#else
             testcmdID = 0;
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

             retval |= fdt_getprop_u32(pDTB, root_offset, "eraseBookBeforeWrite", &eraseBookBeforeWrite);

             /* If no errors in the DTB configuration, configure and check for the GPIO value */
             if(0 != retval)
             {
                 DEBUG_LOG(SAIL_ERROR,"sailhyp_readdtb_update_bookkeep: fdt read failed\n\r");
                 eStatus = SAIL_UPDATER_FAIL;
                 goto readDtbEnd;
             }

             g_SAILUpdaterEL2CoreCtx.bookKeepEnable = (bookKeepEnable==0)?FALSE:TRUE;
             g_SAILUpdaterEL2CoreCtx.maxRetry = maxRetry;
             g_SAILUpdaterEL2CoreCtx.rollbackEnable = (rollbackEnable==0)?FALSE:TRUE;
             g_SAILUpdaterEL2CoreCtx.fixGptRebootEn = (fixGptReboot==0)?FALSE:TRUE;
             g_SAILUpdaterEL2CoreCtx.eraseBookBeforeWrite = (eraseBookBeforeWrite==0)?FALSE:TRUE;

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
             g_SAILUpdaterEL2CoreCtx.testcmdID = testcmdID;
#else
             g_SAILUpdaterEL2CoreCtx.testcmdID = 0;
#endif // SAILUPDATER_INJTEST_SRC_ENABLED
        }
        else
        {
             eStatus = SAIL_UPDATER_FAIL;
             goto readDtbEnd;
        }
    }
    else
    {
        eStatus = SAIL_UPDATER_FAIL;
        goto readDtbEnd;
    }

readDtbEnd:
    return eStatus;
}

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
boolean bSAILUpdaterCoreIsBookkeepingEnabled(uint32_t *maxRetryCount)
{
    *maxRetryCount = g_SAILUpdaterEL2CoreCtx.maxRetry;

     return g_SAILUpdaterEL2CoreCtx.bookKeepEnable;

}

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
boolean bSAILUpdaterCoreIsBookkeepEraseWriteSet(void)
{
    return g_SAILUpdaterEL2CoreCtx.eraseBookBeforeWrite;
}

/**********************************************************
 * Gets the test Command ID
 *
 *
 * @param  None
 *
 * @return uint32_t test Command ID
 *
 **********************************************************/
uint32_t ulSAILUpdaterCoregetTestCmdID(void)
{
    return g_SAILUpdaterEL2CoreCtx.testcmdID;
}

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
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
void ulSAILUpdaterCoreSetTestCmdID(uint32_t testCmdId)
{
    g_SAILUpdaterEL2CoreCtx.testcmdID = testCmdId;
}
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

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
boolean bSAILUpdaterCoreIsRollbackEnabled(void)
{
    return g_SAILUpdaterEL2CoreCtx.rollbackEnable;
}

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
SAILUpdaterCoreStatusType_e xSAILUpdaterCoreInit(void)
{
    SAILUpdaterCoreStatusType_e eStatus = SAIL_UPDATER_SUCCESS;

   /*Device Tree Read*/
   if(SAIL_UPDATER_SUCCESS !=xSAILUpdaterReadDtbUpdateBookkeep())
   {
       DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreInit: Read DTB failed \n\r");
       eStatus = SAIL_UPDATER_FAIL;
       goto updaterCoreInitEnd;
   }

   /* Initalize SPINOR handle */
   g_SAILUpdaterEL2CoreCtx.norHandle = NULL;
   if(SPINOR_DEVICE_DONE != spinorEl2Open ( &g_SAILUpdaterEL2CoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
   {
       DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreInit: Spinor Open failed \n\r");
       eStatus = SAIL_UPDATER_FAIL;
       goto updaterCoreInitEnd;
   }

   /* Get SPINOR memory Info */
   if (SPINOR_DEVICE_DONE != spinorEl2GetMemInfo(g_SAILUpdaterEL2CoreCtx.norHandle, &g_SAILUpdaterEL2CoreCtx.memInfo))
   {
       DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreInit: Spinor Get Mem Info failed \n\r");
       eStatus = SAIL_UPDATER_FAIL;
       goto updaterCoreInitEnd;
   }

   DEBUG_LOG(SAIL_INFO,"xSAILUpdaterCoreInit: SAILUpdater Core Init done\n\r");

   g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf = gSAILUpdaterEL2gptWorkBuf;
   g_SAILUpdaterEL2CoreCtx.gptReadCb = gptPartitionGetReadCb();

   if( SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterGetGPTHdr(SAIL_UPD_GPT_ID_PRIMARY, &g_SAILUpdaterEL2CoreCtx.PrimaryGPTHdr))
   {
       DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreInit: Read Primary GPT header failed \n\r");
       eStatus = SAIL_UPDATER_FAIL;
       goto updaterCoreInitEnd;
   }

   if( SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterGetGPTHdr(SAIL_UPD_GPT_ID_SECONDARY, &g_SAILUpdaterEL2CoreCtx.SecondaryGPTHdr))
   {
       DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreInit: Read GPT Secondary GPT header failed \n\r");
       eStatus = SAIL_UPDATER_FAIL;
       goto updaterCoreInitEnd;
   }


   DEBUG_LOG(SAIL_WARNING, "xSAILUpdaterCoreInit: Primary GPT headerCRC = 0x%x partitionCRC = 0x%x num_partitions=0x%x \n\r", g_SAILUpdaterEL2CoreCtx.PrimaryGPTHdr.header_crc32, g_SAILUpdaterEL2CoreCtx.PrimaryGPTHdr.partition_entries_crc32, g_SAILUpdaterEL2CoreCtx.PrimaryGPTHdr.number_of_partition_entries);
   DEBUG_LOG(SAIL_WARNING, "xSAILUpdaterCoreInit: Secondary GPT headerCRC = 0x%x partitionCRC = 0x%x  num_partitions=0x%x \n\r", g_SAILUpdaterEL2CoreCtx.SecondaryGPTHdr.header_crc32, g_SAILUpdaterEL2CoreCtx.SecondaryGPTHdr.partition_entries_crc32, g_SAILUpdaterEL2CoreCtx.SecondaryGPTHdr.number_of_partition_entries);

updaterCoreInitEnd:
   if (g_SAILUpdaterEL2CoreCtx.norHandle != NULL)
   {
       /* Close SPINOR handle */
       if(SPINOR_DEVICE_DONE != spinorEl2Close ( g_SAILUpdaterEL2CoreCtx.norHandle ))
       {
           DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreInit: Spinor Close failed \n\r");
           eStatus = SAIL_UPDATER_FAIL;
       }
       g_SAILUpdaterEL2CoreCtx.norHandle = NULL;
   }
   return eStatus;
}

/**********************************************************
 * Caculates the CRC for the contents provided
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
uint32_t ulSAILUpdaterCoreCalcCRC(uint32_t addr, uint32_t len)
{
    uint32_t testBufAddr=0;
    uint32_t testBufLen = 0;
    uint32_t sz=1, crc=0;

    testBufAddr = addr;
    testBufLen = len;
    sz = 1;

    crc = ulAutosarCrcBufList(AUTOSAR_CRC_32BIT_ETHERNET, &testBufAddr, &testBufLen, sz);
    return crc;
}

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
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessHello(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;

    pRspMsg->msgId = SAIL_UPD_MSG_ID_HELLO;

    if ( (pReqMsg->hello.hello[0] != 'H') ||  (pReqMsg->hello.hello[1] != 'E') ||  (pReqMsg->hello.hello[2] != 'L') ||  (pReqMsg->hello.hello[3] != 'L')
          || (pReqMsg->hello.hello[4] != 'O') ||  (pReqMsg->hello.hello[5] != '\0')
       )
    {
        eStatus = SAIL_UPDATER_INVALID_HELLO_MSG;
        goto ProcessHelloEnd;
    }
    else if ( (pReqMsg->hello.mailboxVersionMajor != 1) || (pReqMsg->hello.mailboxVersionMinor!=0) )
    {
        eStatus = SAIL_UPDATER_INVALID_VERSION;
        goto ProcessHelloEnd;
    }

    pRspMsg->hello.hello[0] = 'H';
    pRspMsg->hello.hello[1] = 'E';
    pRspMsg->hello.hello[2] = 'L';
    pRspMsg->hello.hello[3] = 'L';
    pRspMsg->hello.hello[4] = 'O';
    pRspMsg->hello.hello[5] = '\0';

    pRspMsg->hello.mailboxVersionMajor = 1;
    pRspMsg->hello.mailboxVersionMinor = 0;

    pRspMsg->status = SAIL_UPDATER_STATUS_SUCCESS;

ProcessHelloEnd:
    return eStatus;
}

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
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessFlashImg(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg)
{
    SPINOR_STATUS result;
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;
    uint32_t byte_offset,byte_count,block_size;
    uint32_t FlashPartition, FlashGptId;
    uint32_t temp_crc=0;
    uint32_t pulIndex=0;
    size_t sizeret;
    char imgGuid[GUID_STRING_SIZE+1] = "";      // dummy GUID
    guid_t tmpGuid = {0};
    gptHeader_t xGPTHdr = {0};
    sailUpdaterCoreVerifyGPTtype chkGPTparam = {0};
    uint32_t bufAddrToUse = pReqMsg->flashImg.bufAddr - SAIL_MD_DDR_ADDR_OFFSET;

    pRspMsg->msgId = SAIL_UPD_MSG_ID_FLASH_IMAGE;

    /* Initalize SPINOR handle */
    g_SAILUpdaterEL2CoreCtx.norHandle = NULL;
    if(SPINOR_DEVICE_DONE != spinorEl2Open ( &g_SAILUpdaterEL2CoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: Spinor Open failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessFlashImgEnd;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl2GetMemInfo(g_SAILUpdaterEL2CoreCtx.norHandle, &g_SAILUpdaterEL2CoreCtx.memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: Spinor Get Mem Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessFlashImgEnd;
    }

    sizeret = sailbsp_memscpy((void *)pRspMsg->flashImg.imgName, SAIL_UPD_IMG_NAME_LEN, (void *) pReqMsg->flashImg.imgName, SAIL_UPD_IMG_NAME_LEN);
    if(sizeret == 0)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: Failed to copy image name from request to response msg \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessFlashImgEnd;
    }

    pRspMsg->flashImg.FlashPartition = pReqMsg->flashImg.FlashPartition;
    pRspMsg->flashImg.FlashGptId = pReqMsg->flashImg.FlashGptId;

    /* Validate the Image */
    if (FALSE == bPrvSAILUpdaterCoreIsValidImg(UPDATER_FLASH_OPERATION, (const char*)&pReqMsg->flashImg.imgName))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: Invalid Image name \n\r");
        eStatus = SAIL_UPDATER_INVALID_IMG_NAME;
        goto ProcessFlashImgEnd;
    }

    /* Invalid Partition ID */
    if (pReqMsg->flashImg.ext_id.FlashPartition >= SAIL_UPD_PARTITION_ID_MAX)
    {
        eStatus = SAIL_UPDATER_INVALID_PARTITION_ID;
        goto ProcessFlashImgEnd;
    }

    if ((pReqMsg->flashImg.ext_id.flashtype > 2) || (0 != pReqMsg->flashImg.ext_id.reserved[0]) || (0 != pReqMsg->flashImg.ext_id.reserved[1]))
    {
        DEBUG_LOG(SAIL_ERROR, "xSAILUpdaterCoreProcessFlashImg: Invalid Flash Image extended ID 0x%x\n\r", pReqMsg->flashImg.FlashPartition);
        eStatus = SAIL_UPDATER_INVALID_PARTITION_ID;
        goto ProcessFlashImgEnd;
    }

    /* Invalid GPT ID */
    if (pReqMsg->flashImg.FlashGptId >= SAIL_UPD_GPT_ID_MAX)
    {
        eStatus = SAIL_UPDATER_INVALID_GPT_ID;
        goto ProcessFlashImgEnd;
    }

    /* UnAligned Buffer size */
    if (pReqMsg->flashImg.bufLen % SPINOR_BYTES_ALIGNMENT)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: Invalid Buffer Size 0x%x\n\r",pReqMsg->flashImg.bufLen);
        eStatus = SAIL_UPDATER_UNALIGNED_BUF_SIZE;
        goto ProcessFlashImgEnd;
    }

    if (0 == pReqMsg->flashImg.bufLen)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: Invalid Buffer Size 0x%x\n\r",pReqMsg->flashImg.bufLen);
        eStatus = SAIL_UPDATER_INVALID_BUF_SIZE;
        goto ProcessFlashImgEnd;
    }

    /* Invalid Buffer Address */
    if ((0U == pReqMsg->flashImg.bufAddr) || (0U == bufAddrToUse) ||
        (FALSE == bPrvSAILUpdaterCoreIsAddrInRange(bufAddrToUse, pReqMsg->flashImg.bufLen))
       )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: Invalid Buffer Address \n\r");
        eStatus = SAIL_UPDATER_INVALID_BUF_ADDR;
        goto ProcessFlashImgEnd;
    }

    if( SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(pReqMsg->flashImg.FlashGptId, &xGPTHdr, &chkGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: GPT header read Failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessFlashImgEnd;
    }

    if( (0 == chkGPTparam.HeaderCrcStatus) || (0 == chkGPTparam.EntryCrcStatus) )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: GPT header Invalid \n\r");
        eStatus = SAIL_UPDATER_GPT_INVALID;
        goto ProcessFlashImgEnd;
    }

    FlashPartition = (pReqMsg->flashImg.ext_id.FlashPartition == SAIL_UPD_PARTITION_ID_PRIMARY) ? XBL_PARTITION_A : XBL_PARTITION_B;
    FlashGptId = (pReqMsg->flashImg.FlashGptId == SAIL_UPD_GPT_ID_PRIMARY)?XBL_GPT_TABLE_PRIMARY:XBL_GPT_TABLE_SECONDARY;

    /* Get the GUID for the Image */
    if(sailhyp_xbl_getImgGUID((const char *)&pReqMsg->flashImg.imgName, FlashPartition, FlashGptId, imgGuid))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: Get Image GUID failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessFlashImgEnd;
    }

    if(FALSE == gptDecodeGUIDString ( imgGuid, &tmpGuid))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: Converting GUID String to GUID for Image GUID failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessFlashImgEnd;
    }

    if(FALSE == bPrvSAILUpdaterGPTGetPartitionInfo (&xGPTHdr, &tmpGuid, &byte_offset, &byte_count , &pulIndex))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: Get Partition Info failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessFlashImgEnd;
    }

    /* Invalid Buffer Size if Size of image is more than partition size */
    if (byte_count < pReqMsg->flashImg.bufLen)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: Invalid Buffer Size \n\r");
        eStatus = SAIL_UPDATER_INVALID_BUF_SIZE;
        goto ProcessFlashImgEnd;
    }

    /* Copy the current CRC and Calculate Buffer CRC */
    temp_crc = pReqMsg->flashImg.bufCrc;
    pReqMsg->flashImg.bufCrc = 0;
    pReqMsg->flashImg.bufCrc = ulSAILUpdaterCoreCalcCRC(bufAddrToUse, pReqMsg->flashImg.bufLen);

    /* Verify Buffer CRC */
    if (TRUE == bPrvSAILUpdaterCoreIsCRCNotMatch(temp_crc, pReqMsg->flashImg.bufCrc))
    {
        eStatus = SAIL_UPDATER_INVALID_BUF_CRC;
        goto ProcessFlashImgEnd;
    }

    block_size = g_SAILUpdaterEL2CoreCtx.memInfo.pages_per_block * g_SAILUpdaterEL2CoreCtx.memInfo.page_size_bytes;

    /* Erase the Partition */
    result = spinorEl2Erase (g_SAILUpdaterEL2CoreCtx.norHandle, byte_offset/block_size, byte_count/block_size);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: Erase Partition failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessFlashImgEnd;
    }

    /* Write to the partition */
    result = spinorEl2Write ( g_SAILUpdaterEL2CoreCtx.norHandle, byte_offset, pReqMsg->flashImg.bufLen, (void *)bufAddrToUse);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: Write Partition failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessFlashImgEnd;
    }

    /* Copy Buffer Address and Length from the request into the response header */
    pRspMsg->flashImg.bufAddr = pReqMsg->flashImg.bufAddr;
    pRspMsg->flashImg.bufLen = pReqMsg->flashImg.bufLen;

    /* Read from the partition again to verify the CRC */
    result = spinorEl2Read ( g_SAILUpdaterEL2CoreCtx.norHandle, byte_offset, pRspMsg->flashImg.bufLen, (void *)bufAddrToUse);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: Read Partition failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessFlashImgEnd;
    }

    /* Calculate Buffer CRC */
    pRspMsg->flashImg.bufCrc = 0;
    pRspMsg->flashImg.bufCrc = ulSAILUpdaterCoreCalcCRC(bufAddrToUse, pRspMsg->flashImg.bufLen);

    if (pRspMsg->flashImg.bufCrc != pReqMsg->flashImg.bufCrc)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: CRC after read not matching the Request data CRC \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessFlashImgEnd;
    }

    pRspMsg->status = SAIL_UPDATER_STATUS_SUCCESS;

ProcessFlashImgEnd:
    if (g_SAILUpdaterEL2CoreCtx.norHandle != NULL)
    {
       /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl2Close ( g_SAILUpdaterEL2CoreCtx.norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: Spinor Close failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        }
        g_SAILUpdaterEL2CoreCtx.norHandle = NULL;
    }
    return eStatus;
}

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
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessReadImg(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg)
{
    SPINOR_STATUS result;
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;
    uint32_t byte_offset,byte_count;
    uint32_t readPartition,readGptId;
    uint32_t pulIndex=0;
    size_t sizeret;
    char imgGuid[GUID_STRING_SIZE+1] = "";      // dummy GUID
    guid_t tmpGuid = {0};
    gptHeader_t xGPTHdr = {0};
    sailUpdaterCoreVerifyGPTtype chkGPTparam = {0};
    uint32_t bufAddrToUse = pReqMsg->readImg.bufAddr - SAIL_MD_DDR_ADDR_OFFSET;

    pRspMsg->msgId = SAIL_UPD_MSG_ID_READ_IMAGE;

    /* Initalize SPINOR handle */
    g_SAILUpdaterEL2CoreCtx.norHandle = NULL;
    if(SPINOR_DEVICE_DONE != spinorEl2Open ( &g_SAILUpdaterEL2CoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadImg: Spinor Open failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessReadImgEnd;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl2GetMemInfo(g_SAILUpdaterEL2CoreCtx.norHandle, &g_SAILUpdaterEL2CoreCtx.memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadImg: Spinor Get Mem Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessReadImgEnd;
    }

    sizeret = sailbsp_memscpy((void *)pRspMsg->readImg.imgName, SAIL_UPD_IMG_NAME_LEN, (void *) pReqMsg->readImg.imgName, SAIL_UPD_IMG_NAME_LEN);
    if(sizeret == 0)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadImg: Failed to copy image name from request to response msg \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessReadImgEnd;
    }

    pRspMsg->readImg.readPartition = pReqMsg->readImg.readPartition;
    pRspMsg->readImg.readGptId = pReqMsg->readImg.readGptId;

    /* Validate the Image */
    if (FALSE == bPrvSAILUpdaterCoreIsValidImg(UPDATER_FLASH_OPERATION, (const char*)&pReqMsg->readImg.imgName))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadImg: Invalid Image name \n\r");
        eStatus = SAIL_UPDATER_INVALID_IMG_NAME;
        goto ProcessReadImgEnd;
    }

    /* Invalid Partition ID */
    if (pReqMsg->readImg.readPartition >= SAIL_UPD_PARTITION_ID_MAX)
    {
        eStatus = SAIL_UPDATER_INVALID_PARTITION_ID;
        goto ProcessReadImgEnd;
    }

    /* Invalid GPT ID */
    if (pReqMsg->readImg.readGptId >= SAIL_UPD_GPT_ID_MAX)
    {
        eStatus = SAIL_UPDATER_INVALID_GPT_ID;
        goto ProcessReadImgEnd;
    }

    /* UnAligned Buffer size */
    if (pReqMsg->readImg.bufLen % SPINOR_BYTES_ALIGNMENT)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadImg: Invalid Buffer Size 0x%x\n\r", pReqMsg->readImg.bufLen);
        eStatus = SAIL_UPDATER_UNALIGNED_BUF_SIZE;
        goto ProcessReadImgEnd;
    }

    if (0 == pReqMsg->readImg.bufLen)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadImg: Invalid Buffer Size 0x%x\n\r", pReqMsg->readImg.bufLen);
        eStatus = SAIL_UPDATER_INVALID_BUF_SIZE;
        goto ProcessReadImgEnd;
    }

    /* Invalid Buffer Address */
    if ((0U == pReqMsg->readImg.bufAddr) || (0U == bufAddrToUse) ||
        (FALSE == bPrvSAILUpdaterCoreIsAddrInRange(bufAddrToUse, pReqMsg->readImg.bufLen))
       )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadImg: Invalid Buffer Address \n\r");
        eStatus = SAIL_UPDATER_INVALID_BUF_ADDR;
        goto ProcessReadImgEnd;
    }

    if( SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(pReqMsg->readImg.readGptId, &xGPTHdr, &chkGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadImg: GPT header read Failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessReadImgEnd;
    }

    if( (0 == chkGPTparam.HeaderCrcStatus) || (0 == chkGPTparam.EntryCrcStatus) )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadImg: GPT header Invalid \n\r");
        eStatus = SAIL_UPDATER_GPT_INVALID;
        goto ProcessReadImgEnd;
    }

    readPartition = (pReqMsg->readImg.readPartition == SAIL_UPD_PARTITION_ID_PRIMARY)?XBL_PARTITION_A:XBL_PARTITION_B;
    readGptId = (pReqMsg->readImg.readGptId == SAIL_UPD_GPT_ID_PRIMARY)?XBL_GPT_TABLE_PRIMARY:XBL_GPT_TABLE_SECONDARY;

    /* Get the GUID for the Image */
    if(XBL_SUCCESS != sailhyp_xbl_getImgGUID((const char *)&pReqMsg->readImg.imgName, readPartition, readGptId, imgGuid))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadImg: Error Getting Image GUID \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessReadImgEnd;
    }

    if(FALSE == gptDecodeGUIDString ( imgGuid, &tmpGuid))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadImg: Converting GUID String to GUID for Image GUID failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessReadImgEnd;
    }

    if(FALSE == bPrvSAILUpdaterGPTGetPartitionInfo (&xGPTHdr, &tmpGuid, &byte_offset, &byte_count, &pulIndex))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadImg: Get Partition Info failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessReadImgEnd;
    }

    /* Invalid Buffer Size if the size of image to read is more than the partition size */
    if (byte_count < pReqMsg->readImg.bufLen)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadImg: Invalid Buffer Size \n\r");
        eStatus = SAIL_UPDATER_INVALID_BUF_SIZE;
        goto ProcessReadImgEnd;
    }

    /* Read the partition */
    result = spinorEl2Read ( g_SAILUpdaterEL2CoreCtx.norHandle, byte_offset, pReqMsg->readImg.bufLen, (void *)bufAddrToUse);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadImg: Read from Partition failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessReadImgEnd;
    }

    /* Calculate Buffer CRC */
    pRspMsg->readImg.bufCrc = 0;
    pRspMsg->readImg.bufCrc = ulSAILUpdaterCoreCalcCRC(bufAddrToUse, pReqMsg->readImg.bufLen);

    /* Copy Buffer Address and Length from the request into the response header */
    pRspMsg->readImg.bufAddr = pReqMsg->readImg.bufAddr;
    pRspMsg->readImg.bufLen = pReqMsg->readImg.bufLen;

    pRspMsg->status = SAIL_UPDATER_STATUS_SUCCESS;

ProcessReadImgEnd:
    if (g_SAILUpdaterEL2CoreCtx.norHandle != NULL)
    {
        /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl2Close ( g_SAILUpdaterEL2CoreCtx.norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadImg: Spinor Close failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        }
        g_SAILUpdaterEL2CoreCtx.norHandle = NULL;
    }
    return eStatus;
}

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
#if 0
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessGetOTAMeta(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg)
{
    SPINOR_STATUS result;
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;
    uint32_t byte_offset,byte_count;

    uint32_t bufAddrToUse = pReqMsg->getMetaData.bufAddr - SAIL_MD_DDR_ADDR_OFFSET;

    pRspMsg->msgId = SAIL_UPD_MSG_ID_GET_OTA_METADATA;

    /* Initalize SPINOR handle */
    g_SAILUpdaterEL2CoreCtx.norHandle = NULL;
    if(SPINOR_DEVICE_DONE != spinorEl2Open ( &g_SAILUpdaterEL2CoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetOTAMeta: Spinor Open failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessGetOTAMetaEnd;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl2GetMemInfo(g_SAILUpdaterEL2CoreCtx.norHandle, &g_SAILUpdaterEL2CoreCtx.memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetOTAMeta: Spinor Get Mem Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessGetOTAMetaEnd;
    }

    /* Get SAIL_OTA_METADATA partition ("e60b7926-9899-45b1-9758-c95af5657199") */
    result = spinorEl2GetGptPartitionInfo(g_SAILUpdaterEL2CoreCtx.norHandle, "e60b7926-9899-45b1-9758-c95af5657199", &byte_offset, &byte_count);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetOTAMeta: Get Partition Info failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessGetOTAMetaEnd;
    }

    /* Invalid Buffer Size if the size to read is more than partition size */
    if (byte_count < pReqMsg->getMetaData.bufLen)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetOTAMeta: Invalid buffer size 0x%x \n\r", pReqMsg->getMetaData.bufLen);
        eStatus = SAIL_UPDATER_INVALID_BUF_SIZE;
        goto ProcessGetOTAMetaEnd;
    }

    if (0 == pReqMsg->getMetaData.bufLen)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetOTAMeta: Invalid buffer size 0x%x \n\r", pReqMsg->getMetaData.bufLen);
        eStatus = SAIL_UPDATER_INVALID_BUF_SIZE;
        goto ProcessGetOTAMetaEnd;
    }

    /* UnAligned Buffer size */
    if (pReqMsg->getMetaData.bufLen % SPINOR_BYTES_ALIGNMENT)
    {
        eStatus = SAIL_UPDATER_UNALIGNED_BUF_SIZE;
        goto ProcessGetOTAMetaEnd;
    }

    /* Invalid Buffer Address */
    if ((0U == pReqMsg->getMetaData.bufAddr) || (0U == bufAddrToUse) ||
        (FALSE == bPrvSAILUpdaterCoreIsAddrInRange(bufAddrToUse, pReqMsg->getMetaData.bufLen))
       )
    {
        eStatus = SAIL_UPDATER_INVALID_BUF_ADDR;
        goto ProcessGetOTAMetaEnd;
    }

    /* Check buffer Alignment */

    /* Read the partition */
    result = spinorEl2Read ( g_SAILUpdaterEL2CoreCtx.norHandle, byte_offset, pReqMsg->getMetaData.bufLen, (void *)bufAddrToUse);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetOTAMeta: Read from OTA Meta Partition failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessGetOTAMetaEnd;
    }

    /* Calculate Buffer CRC */
    pRspMsg->getMetaData.bufCrc = 0;
    pRspMsg->getMetaData.bufCrc = ulSAILUpdaterCoreCalcCRC(bufAddrToUse, pReqMsg->getMetaData.bufLen);

    /* Copy Buffer Address and Length from the request into the response header */
    pRspMsg->getMetaData.bufAddr = pReqMsg->getMetaData.bufAddr;
    pRspMsg->getMetaData.bufLen = pReqMsg->getMetaData.bufLen;

    pRspMsg->status = SAIL_UPDATER_STATUS_SUCCESS;

ProcessGetOTAMetaEnd:
    if (g_SAILUpdaterEL2CoreCtx.norHandle != NULL)
    {
        /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl2Close ( g_SAILUpdaterEL2CoreCtx.norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetOTAMeta: Spinor Close failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        }
        g_SAILUpdaterEL2CoreCtx.norHandle = NULL;
    }
    return eStatus;
}
#endif

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
#if 0
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessSetOTAMeta(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;

    SPINOR_STATUS result;
    uint32_t byte_offset,byte_count,block_size;
    uint32_t temp_crc=0;
    uint32_t bufAddrToUse = pReqMsg->setMetaData.bufAddr - SAIL_MD_DDR_ADDR_OFFSET;

    pRspMsg->msgId = SAIL_UPD_MSG_ID_SET_OTA_METADATA;

    /* Initalize SPINOR handle */
    g_SAILUpdaterEL2CoreCtx.norHandle = NULL;
    if(SPINOR_DEVICE_DONE != spinorEl2Open ( &g_SAILUpdaterEL2CoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessSetOTAMeta: Spinor Open failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessSetOTAMetaEnd;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl2GetMemInfo(g_SAILUpdaterEL2CoreCtx.norHandle, &g_SAILUpdaterEL2CoreCtx.memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessSetOTAMeta: Spinor Get Mem Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessSetOTAMetaEnd;
    }

    /* Get SAIL_OTA_METADATA partition ("e60b7926-9899-45b1-9758-c95af5657199") */
    result = spinorEl2GetGptPartitionInfo(g_SAILUpdaterEL2CoreCtx.norHandle, "e60b7926-9899-45b1-9758-c95af5657199", &byte_offset, &byte_count);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessSetOTAMeta: Get Partition Info failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessSetOTAMetaEnd;
    }

    /* Invalid Buffer Size if the size to write is more than partition size */
    if (byte_count < pReqMsg->setMetaData.bufLen)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessSetOTAMeta: Invalid buffer size 0x%x \n\r", pReqMsg->setMetaData.bufLen);
        eStatus = SAIL_UPDATER_INVALID_BUF_SIZE;
        goto ProcessSetOTAMetaEnd;
    }

    if (0 == pReqMsg->setMetaData.bufLen)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessSetOTAMeta: Invalid buffer size 0x%x \n\r", pReqMsg->setMetaData.bufLen);
        eStatus = SAIL_UPDATER_INVALID_BUF_SIZE;
        goto ProcessSetOTAMetaEnd;
    }

    /* UnAligned Buffer size */
    if (pReqMsg->setMetaData.bufLen % SPINOR_BYTES_ALIGNMENT)
    {
        eStatus = SAIL_UPDATER_UNALIGNED_BUF_SIZE;
        goto ProcessSetOTAMetaEnd;
    }

    /* Invalid Buffer Address */
    if ((0U == pReqMsg->setMetaData.bufAddr) || (0U == bufAddrToUse) ||
        (FALSE == bPrvSAILUpdaterCoreIsAddrInRange(bufAddrToUse, pReqMsg->setMetaData.bufLen))
       )
    {
        eStatus = SAIL_UPDATER_INVALID_BUF_ADDR;
        goto ProcessSetOTAMetaEnd;
    }

    /* Copy the current CRC and Calculate Buffer CRC */
    temp_crc = pReqMsg->setMetaData.bufCrc;
    pReqMsg->setMetaData.bufCrc = 0;
    pReqMsg->setMetaData.bufCrc = ulSAILUpdaterCoreCalcCRC(bufAddrToUse, pReqMsg->setMetaData.bufLen);

    /* Verify Buffer CRC */
    if(TRUE == bPrvSAILUpdaterCoreIsCRCNotMatch(temp_crc, pReqMsg->setMetaData.bufCrc))
    {
        eStatus = SAIL_UPDATER_INVALID_BUF_CRC;
        goto ProcessSetOTAMetaEnd;
    }

    block_size = g_SAILUpdaterEL2CoreCtx.memInfo.pages_per_block * g_SAILUpdaterEL2CoreCtx.memInfo.page_size_bytes;

    /* Erase the Partition */
    result = spinorEl2Erase (g_SAILUpdaterEL2CoreCtx.norHandle, byte_offset/block_size, byte_count/block_size);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessSetOTAMeta: Erase OTA Meta Partition failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessSetOTAMetaEnd;
    }

    /* Write to the partition */
    result = spinorEl2Write ( g_SAILUpdaterEL2CoreCtx.norHandle, byte_offset, pReqMsg->setMetaData.bufLen, (void *)bufAddrToUse);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessSetOTAMeta: Write OTA Meta Partition failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessSetOTAMetaEnd;
    }

    /* Copy Buffer Address and Length from the request into the response header */
    pRspMsg->setMetaData.bufAddr = pReqMsg->setMetaData.bufAddr;
    pRspMsg->setMetaData.bufLen = pReqMsg->setMetaData.bufLen;


    /* Read from the partition again to verify the CRC */
    result = spinorEl2Read ( g_SAILUpdaterEL2CoreCtx.norHandle, byte_offset, pRspMsg->setMetaData.bufLen, (void *)bufAddrToUse);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessSetOTAMeta: Read OTA Meta Partition failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessSetOTAMetaEnd;
    }

    /* Calculate Buffer CRC */
    pRspMsg->setMetaData.bufCrc = 0;
    pRspMsg->setMetaData.bufCrc = ulSAILUpdaterCoreCalcCRC(bufAddrToUse, pRspMsg->setMetaData.bufLen);

    if (pRspMsg->setMetaData.bufCrc != pReqMsg->setMetaData.bufCrc)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessSetOTAMeta: CRC after read not matching the Request data CRC \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessSetOTAMetaEnd;
    }

    pRspMsg->status = SAIL_UPDATER_STATUS_SUCCESS;

ProcessSetOTAMetaEnd:
    if (g_SAILUpdaterEL2CoreCtx.norHandle != NULL)
    {
        /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl2Close ( g_SAILUpdaterEL2CoreCtx.norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessSetOTAMeta: Spinor Close failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        }
        g_SAILUpdaterEL2CoreCtx.norHandle = NULL;
    }
    return eStatus;
}
#endif

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
#if 0
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessChkGPT(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;
    sailUpdaterCoreVerifyGPTtype xPrimaryGPTparam={0}, xSecondaryGPTparam ={0};


    pRspMsg->msgId = SAIL_UPD_MSG_ID_CHECK_GPT;

    /* Initalize SPINOR handle */
    g_SAILUpdaterEL2CoreCtx.norHandle = NULL;
    if(SPINOR_DEVICE_DONE != spinorEl2Open ( &g_SAILUpdaterEL2CoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessChkGPT: Spinor Open failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ChkGPTEnd;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl2GetMemInfo(g_SAILUpdaterEL2CoreCtx.norHandle, &g_SAILUpdaterEL2CoreCtx.memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessChkGPT: Spinor Get Mem Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ChkGPTEnd;
    }

    /* Check the GPT health of Primary GPT */
    if (SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(SAIL_UPD_GPT_ID_PRIMARY, &g_SAILUpdaterEL2CoreCtx.PrimaryGPTHdr, &xPrimaryGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessChkGPT: Getting Primary GPT health failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ChkGPTEnd;
    }

    /* Check the GPT health of Secondary GPT */
    if (SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(SAIL_UPD_GPT_ID_SECONDARY, &g_SAILUpdaterEL2CoreCtx.SecondaryGPTHdr, &xSecondaryGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessChkGPT: Getting Secondary GPT health failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ChkGPTEnd;
    }

    pRspMsg->checkGpt.primaryGptEntryCrcStatus = xPrimaryGPTparam.EntryCrcStatus;
    pRspMsg->checkGpt.primaryGptHeaderCrcStatus = xPrimaryGPTparam.HeaderCrcStatus;
    pRspMsg->checkGpt.primaryGptSize = xPrimaryGPTparam.GptSize;

    pRspMsg->checkGpt.secondaryGptEntryCrcStatus = xSecondaryGPTparam.EntryCrcStatus;
    pRspMsg->checkGpt.secondaryGptHeaderCrcStatus = xSecondaryGPTparam.HeaderCrcStatus;
    pRspMsg->checkGpt.secondaryGptSize = xSecondaryGPTparam.GptSize;

    pRspMsg->status = SAIL_UPDATER_STATUS_SUCCESS;

ChkGPTEnd:
    if (g_SAILUpdaterEL2CoreCtx.norHandle != NULL)
    {
        /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl2Close ( g_SAILUpdaterEL2CoreCtx.norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessChkGPT: Spinor Close failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        }
        g_SAILUpdaterEL2CoreCtx.norHandle = NULL;
    }
    return eStatus;
}
#endif

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
#if 0
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessReadGPT(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;
    size_t result;
    gptHeader_t xGPTHdr = {0};
    sailUpdaterCoreVerifyGPTtype chkGPTparam = {0};
    uint32_t bufAddrToUse = pReqMsg->readGpt.bufAddr - SAIL_MD_DDR_ADDR_OFFSET;

    pRspMsg->msgId = SAIL_UPD_MSG_ID_READ_GPT;

    pRspMsg->readGpt.id = pReqMsg->readGpt.id;

    /* Initalize SPINOR handle */
    g_SAILUpdaterEL2CoreCtx.norHandle = NULL;
    if(SPINOR_DEVICE_DONE != spinorEl2Open ( &g_SAILUpdaterEL2CoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadGPT: Spinor Open failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ReadGPTEnd;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl2GetMemInfo(g_SAILUpdaterEL2CoreCtx.norHandle, &g_SAILUpdaterEL2CoreCtx.memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadGPT: Spinor Get Mem Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ReadGPTEnd;
    }

    /* Validate GPT ID */
    if (pReqMsg->readGpt.id >= SAIL_UPD_GPT_ID_MAX)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadGPT: Invalid GPT ID \n\r");
        eStatus = SAIL_UPDATER_INVALID_GPT_ID;
        goto ReadGPTEnd;
    }

    if( SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(pReqMsg->readGpt.id, &xGPTHdr, &chkGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadGPT: GPT header read Failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ReadGPTEnd;
    }

    if( (0 == chkGPTparam.HeaderCrcStatus) || (0 == chkGPTparam.EntryCrcStatus) )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadGPT: GPT header Invalid \n\r");
        eStatus = SAIL_UPDATER_GPT_INVALID;
        goto ReadGPTEnd;
    }

    /* Validate Buffer Size */
    if (chkGPTparam.GptSize > pReqMsg->readGpt.bufLen)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadGPT: Invalid Buffer Size 0x%x \n\r", pReqMsg->readGpt.bufLen);
        eStatus = SAIL_UPDATER_INVALID_BUF_SIZE;
        goto ReadGPTEnd;
    }

    if (0 == pReqMsg->readGpt.bufLen)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadGPT: Invalid Buffer Size 0x%x \n\r", pReqMsg->readGpt.bufLen);
        eStatus = SAIL_UPDATER_INVALID_BUF_SIZE;
        goto ReadGPTEnd;
    }

    /* UnAligned Buffer size */
    if (pReqMsg->readGpt.bufLen % SPINOR_BYTES_ALIGNMENT)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadGPT: Unaligned Buffer Size \n\r");
        eStatus = SAIL_UPDATER_UNALIGNED_BUF_SIZE;
        goto ReadGPTEnd;
    }

    /* Validate Buffer Address */
    if ((0U == pReqMsg->readGpt.bufAddr) || (0U == bufAddrToUse) ||
        (FALSE == bPrvSAILUpdaterCoreIsAddrInRange(bufAddrToUse, pReqMsg->readGpt.bufLen))
       )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadGPT: Invalid Buffer Address \n\r");
        eStatus = SAIL_UPDATER_INVALID_BUF_ADDR;
        goto ReadGPTEnd;
    }

    /* Invalidate the cache */
    invalidate_dcache_by_range(bufAddrToUse, (bufAddrToUse + pReqMsg->readGpt.bufLen) );

    /* Copy the partition entries first to the start of the buffer and then move it by offset of header size.
       Then read the header into the buffer at the start of the buffer.
       This is needed only because of alignment of the buffers passed to SPINOR.
     */
    if(SAIL_UPDATER_SUCCESS != bPrvSAILUpdaterGPTGetPartitionEntries(&xGPTHdr, (uint8_t *)(bufAddrToUse+sizeof(gptHeader_t))) )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadGPT: Parition Entries read Failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ReadGPTEnd;
    }

    /* GPT header is already read . Copy it into the destination buffer */
    result = sailbsp_memscpy((void *)bufAddrToUse, sizeof(gptHeader_t), &xGPTHdr, sizeof(gptHeader_t));
    if(result == 0)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadGPT: Copy GPT header from local location to buffer address failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ReadGPTEnd;
    }

    /* Flush and Invalidate the cache */
    clean_invalidate_cache_by_range((uint32) bufAddrToUse,(uint32)bufAddrToUse + chkGPTparam.GptSize);

    /* Copy Buffer Address and Length from the request into the response header */
    pRspMsg->readGpt.bufAddr = pReqMsg->readGpt.bufAddr;
    pRspMsg->readGpt.bufLen = pReqMsg->readGpt.bufLen;

    /* Calculate Buffer CRC */
    pRspMsg->readGpt.bufCrc = 0;
    pRspMsg->readGpt.bufCrc = ulSAILUpdaterCoreCalcCRC(bufAddrToUse, pRspMsg->readGpt.bufLen);

    pRspMsg->status = SAIL_UPDATER_STATUS_SUCCESS;

ReadGPTEnd:
    if (g_SAILUpdaterEL2CoreCtx.norHandle != NULL)
    {
        /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl2Close ( g_SAILUpdaterEL2CoreCtx.norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadGPT: Spinor Close failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        }
        g_SAILUpdaterEL2CoreCtx.norHandle = NULL;
    }
    return eStatus;
}
#endif

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
#if 0
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessWriteGPT(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;
    uint32_t sz=0, offset = 0, temp_crc, ulAltGptId, ulWriteSz, ulEntrySz;
    uint32_t num_bytes, srcAddr, partitionOffsetAddr, block_size, max_transfersize;
    uint32_t partition_entry_offset=0, partition_entry_size=0, destHdrLba, ulEraseSz=0, ulEraseLBA=0;
    gptHeader_t xGPTHdr = {0}, xAltGPTHdr = {0};
    sailUpdaterCoreVerifyGPTtype chkGPTparam = {0}, chkDestGPTparam = {0};
    size_t result;

    uint32_t bufAddrToUse = pReqMsg->writeGpt.bufAddr - SAIL_MD_DDR_ADDR_OFFSET;

    pRspMsg->msgId = SAIL_UPD_MSG_ID_WRITE_GPT;

    pRspMsg->writeGpt.id = pReqMsg->writeGpt.id;

    /* Initalize SPINOR handle */
    g_SAILUpdaterEL2CoreCtx.norHandle = NULL;
    if(SPINOR_DEVICE_DONE != spinorEl2Open ( &g_SAILUpdaterEL2CoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: Spinor Open failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto WriteGPTEnd;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl2GetMemInfo(g_SAILUpdaterEL2CoreCtx.norHandle, &g_SAILUpdaterEL2CoreCtx.memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: Spinor Get Mem Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto WriteGPTEnd;
    }

    /* Validate GPT ID */
    if (pReqMsg->writeGpt.id >= SAIL_UPD_GPT_ID_MAX)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: Invalid GPT ID \n\r");
        eStatus = SAIL_UPDATER_INVALID_GPT_ID;
        goto WriteGPTEnd;
    }

    //todo: Dilip check if this check is needed?
    /* Get the GPT params of primary and secondary and check if they are valid */
    if (SAIL_UPD_GPT_ID_PRIMARY == pReqMsg->writeGpt.id)
    {
        ulAltGptId = SAIL_UPD_GPT_ID_SECONDARY;
    }
    else
    {
        ulAltGptId = SAIL_UPD_GPT_ID_PRIMARY;
    }

    if( SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(ulAltGptId, &xAltGPTHdr, &chkGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: Alt GPT header read Failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto WriteGPTEnd;
    }

    if ((0 == chkGPTparam.EntryCrcStatus) || (0 == chkGPTparam.HeaderCrcStatus))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: Alt GPT header Invalid \n\r");
        eStatus = SAIL_UPDATER_ALT_GPT_INVALID;
        goto WriteGPTEnd;
    }

    /* Validate Buffer Size */
    if (chkGPTparam.GptSize > pReqMsg->writeGpt.bufLen)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: Invalid Buffer Size 0x%x\n\r", pReqMsg->writeGpt.bufLen);
        eStatus = SAIL_UPDATER_INVALID_BUF_SIZE;
        goto WriteGPTEnd;
    }

    if (0 == pReqMsg->writeGpt.bufLen)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: Invalid Buffer Size 0x%x\n\r", pReqMsg->writeGpt.bufLen);
        eStatus = SAIL_UPDATER_INVALID_BUF_SIZE;
        goto WriteGPTEnd;
    }

    /* UnAligned Buffer size */
    if (pReqMsg->writeGpt.bufLen % SPINOR_BYTES_ALIGNMENT)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: Unaligned Buffer Size \n\r");
        eStatus = SAIL_UPDATER_UNALIGNED_BUF_SIZE;
        goto WriteGPTEnd;
    }

    /* Validate Buffer Address */
    if ((0U == pReqMsg->writeGpt.bufAddr) || (0U == bufAddrToUse) ||
        (FALSE == bPrvSAILUpdaterCoreIsAddrInRange(bufAddrToUse, pReqMsg->writeGpt.bufLen))
       )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: Invalid Buffer Address \n\r");
        eStatus = SAIL_UPDATER_INVALID_BUF_ADDR;
        goto WriteGPTEnd;
    }


    /* Copy the current CRC and Calculate Buffer CRC */
    temp_crc = pReqMsg->writeGpt.bufCrc;
    pReqMsg->writeGpt.bufCrc = 0;
    pReqMsg->writeGpt.bufCrc = ulSAILUpdaterCoreCalcCRC(bufAddrToUse, pReqMsg->writeGpt.bufLen);

    /* Verify Buffer CRC */
    if(TRUE == bPrvSAILUpdaterCoreIsCRCNotMatch(temp_crc, pReqMsg->writeGpt.bufCrc))
    {
        eStatus = SAIL_UPDATER_INVALID_BUF_CRC;
        goto WriteGPTEnd;
    }

    // Read the header from buffer and validate the CRC
    result = sailbsp_memscpy((void *)&xGPTHdr, sizeof(gptHeader_t), (const void *)bufAddrToUse , sizeof(gptHeader_t));
    if(result == 0)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: Move GPT Header from buffer to temp location failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto WriteGPTEnd;
    }

    if (FALSE == gptVerifyHeaderCRC32(&xGPTHdr, GPT_CRC32_SEED_DEFAULT))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: GPT header CRC invalid \n\r");
        eStatus = SAIL_UPDATER_GPT_HEADERCRC_INVALID;
        goto WriteGPTEnd;
    }

    /* Calculate partition entries CRC */
    ulEntrySz  = xGPTHdr.size_of_partition_entry * xGPTHdr.number_of_partition_entries;
    temp_crc = gptCalcCRC32((const uint8_t *)(bufAddrToUse+sizeof(gptHeader_t)), ulEntrySz, GPT_CRC32_SEED_DEFAULT);

    if (temp_crc != xGPTHdr.partition_entries_crc32)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: Partition entries CRC invalid \n\r");
        eStatus = SAIL_UPDATER_GPT_PARTITIONCRC_INVALID;
        goto WriteGPTEnd;
    }

    /* Calcuate the buffer offsets for the destination from the GPT header */
    if (SAIL_UPD_GPT_ID_PRIMARY == pReqMsg->writeGpt.id)
    {
        if (TRUE != gptIsPrimaryHeader(&xGPTHdr))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: GPT id and header do not match \n\r");
            eStatus = SAIL_UPDATER_GPT_INVALID;
            goto WriteGPTEnd;
        }
        partition_entry_offset = xGPTHdr.partition_entry_lba;
        partition_entry_size = xGPTHdr.first_usable_lba - xGPTHdr.partition_entry_lba;
        ulEraseLBA = xGPTHdr.my_lba;
        ulEraseSz = xGPTHdr.first_usable_lba - xGPTHdr.my_lba;
    }
    else if (SAIL_UPD_GPT_ID_SECONDARY == pReqMsg->writeGpt.id)
    {
        if (TRUE == gptIsPrimaryHeader(&xGPTHdr))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: GPT id and header do not match \n\r");
            eStatus = SAIL_UPDATER_GPT_INVALID;
            goto WriteGPTEnd;
        }
        partition_entry_offset = xGPTHdr.partition_entry_lba;
        partition_entry_size =  xGPTHdr.my_lba - xGPTHdr.partition_entry_lba;
        ulEraseLBA = xGPTHdr.partition_entry_lba;
        ulEraseSz = xGPTHdr.partition_entry_lba - xGPTHdr.my_lba+(g_SAILUpdaterEL2CoreCtx.memInfo.block_count - xGPTHdr.my_lba);
    }

    /* Erase the Destination GPT Header and partition entries */
    result = spinorEl2Erase (g_SAILUpdaterEL2CoreCtx.norHandle, ulEraseLBA, ulEraseSz);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: Erase GPT Header and Partition entries failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto WriteGPTEnd;
    }

    ulEntrySz  = xGPTHdr.size_of_partition_entry * xGPTHdr.number_of_partition_entries;

    block_size = g_SAILUpdaterEL2CoreCtx.memInfo.pages_per_block * g_SAILUpdaterEL2CoreCtx.memInfo.page_size_bytes;

    /* copy into max 4k chunks in to local work buffer and then write so that the buffer address is aligned */
    num_bytes = ulEntrySz;

    srcAddr = bufAddrToUse + sizeof(gptHeader_t);
    partitionOffsetAddr = partition_entry_offset * block_size;

    while (num_bytes)
    {
        max_transfersize = (num_bytes <= ARRAY_LENGTH(gSAILUpdaterEL2gptWorkBuf))?num_bytes:ARRAY_LENGTH(gSAILUpdaterEL2gptWorkBuf);

        /* Copy the entries from workbuffer to local buffers */
        result = sailbsp_memscpy(g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf, max_transfersize, (const void *)srcAddr, max_transfersize);
        if(result == 0)
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: Copy entries workbuffer to local buffer failed \n\r");
            eStatus = SAIL_UPDATER_STATUS_FAIL;
            goto WriteGPTEnd;
        }

        srcAddr += max_transfersize;

        if (max_transfersize == num_bytes)
        {
            max_transfersize = (num_bytes % SPINOR_BYTES_ALIGNMENT)? num_bytes + SPINOR_BYTES_ALIGNMENT - (num_bytes % SPINOR_BYTES_ALIGNMENT) : num_bytes;

            if ((max_transfersize != num_bytes ) && (max_transfersize > num_bytes))
            {
                memset(g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf + num_bytes, 0xFF, (max_transfersize - num_bytes));
            }
            num_bytes -= num_bytes;
        }
        else
        {
            num_bytes -= max_transfersize;
        }

        /* Flush and Invalidate the cache for the local buffer containing the destination content */
        clean_invalidate_cache_by_range((uint32)g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf, (uint32)g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf + max_transfersize);

        /* Write the Destination GPT partition entries */
        result = spinorEl2Write ( g_SAILUpdaterEL2CoreCtx.norHandle, partitionOffsetAddr, max_transfersize, (void *)g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf );
        if( result != SPINOR_DEVICE_DONE )
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: Write partition entries failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
            goto WriteGPTEnd;
        }
        partitionOffsetAddr += max_transfersize;
    }

    /* Copy the GPT header to Destination buffer that can accommodate extra bytes for taking care of padding for alignment */
    result = sailbsp_memscpy(g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf, sizeof(gptHeader_t), (const void *)bufAddrToUse , sizeof(gptHeader_t));
    if(result == 0)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: Copy GPT header from Source to local work buffer failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto WriteGPTEnd;
    }

    ulWriteSz = (sizeof(gptHeader_t) % SPINOR_BYTES_ALIGNMENT) ? sizeof(gptHeader_t) + SPINOR_BYTES_ALIGNMENT - (sizeof(gptHeader_t) % SPINOR_BYTES_ALIGNMENT) : sizeof(gptHeader_t);

    /* If the Write size is not aligned, then pad FFs to the data and write */
    if( (ulWriteSz != sizeof(gptHeader_t)) && (ulWriteSz > sizeof(gptHeader_t)))
    {
        memset(g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf + sizeof(gptHeader_t), 0xFF, (ulWriteSz - sizeof(gptHeader_t)));
    }

    /* Calcuate the buffer offsets for the destination from the GPT header */
    destHdrLba = xGPTHdr.my_lba;

    /* Flush and Invalidate the cache for the address containing the destination content */
    clean_invalidate_cache_by_range((uint32)g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf, (uint32)g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf + ulWriteSz);

    /* Write the Destination GPT header */
    result = spinorEl2Write ( g_SAILUpdaterEL2CoreCtx.norHandle, destHdrLba * block_size, ulWriteSz, (void *)g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: Write partition entries failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto WriteGPTEnd;
    }

    /* Verify the new destination GPT */
    if (SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(pReqMsg->writeGpt.id, &xGPTHdr, &chkDestGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: Verify destination header read failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto WriteGPTEnd;
    }

    if ((0 == chkDestGPTparam.EntryCrcStatus) || (0 == chkDestGPTparam.HeaderCrcStatus) )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: Destination GPT header Invalid \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto WriteGPTEnd;
    }

    pRspMsg->status = SAIL_UPDATER_STATUS_SUCCESS;

WriteGPTEnd:
    if (g_SAILUpdaterEL2CoreCtx.norHandle != NULL)
    {
        /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl2Close ( g_SAILUpdaterEL2CoreCtx.norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: Spinor Close failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        }
        g_SAILUpdaterEL2CoreCtx.norHandle = NULL;
    }
    return eStatus;
}
#endif

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
#if 0
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessFixGPT(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg)
{
    SAILUpdaterStatusType_e eStatus  = SAIL_UPDATER_STATUS_SUCCESS;
    SPINOR_STATUS result;
    uint32_t block_size;
    uint32_t num_bytes, srcAddr, partitionOffsetAddr;
    uint64_t temp_lba, destHdrLba;
    uint32_t max_transfersize, partition_entry_offset, partition_entry_size;
    uint32_t tempCrc;
    uint32_t ulAltGptId, ulEntrySz, ulWriteSz;
    gptHeader_t xAltGPTHdr = {0}, xGptHdr = {0};
    sailUpdaterCoreVerifyGPTtype chkGPTparam = {0}, chkDestGPTparam={0};
    uint32_t bufAddrToUse = pReqMsg->fixGpt.bufAddr - SAIL_MD_DDR_ADDR_OFFSET;

    pRspMsg->msgId = SAIL_UPD_MSG_ID_FIX_GPT;

    pRspMsg->fixGpt.id = pReqMsg->fixGpt.id;

    /* Initalize SPINOR handle */
    g_SAILUpdaterEL2CoreCtx.norHandle = NULL;
    if(SPINOR_DEVICE_DONE != spinorEl2Open ( &g_SAILUpdaterEL2CoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Spinor Open failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto FixGPTEnd;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl2GetMemInfo(g_SAILUpdaterEL2CoreCtx.norHandle, &g_SAILUpdaterEL2CoreCtx.memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Spinor Get Mem Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto FixGPTEnd;
    }

    /* Invalid GPT ID */
    if (pReqMsg->fixGpt.ext_id.id >= SAIL_UPD_GPT_ID_MAX)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Invalid GPT ID \n\r");
        eStatus = SAIL_UPDATER_INVALID_GPT_ID;
        goto FixGPTEnd;
    }

    if ((pReqMsg->fixGpt.ext_id.fixtype > 1) || (0 != pReqMsg->fixGpt.ext_id.reserved[0]) || (0 != pReqMsg->fixGpt.ext_id.reserved[1]))
    {
        DEBUG_LOG(SAIL_ERROR, "xSAILUpdaterCoreProcessFixGPT: Invalid Fix GPT extended ID 0x%x\n\r", pReqMsg->fixGpt.id);
        eStatus = SAIL_UPDATER_INVALID_GPT_ID;
        goto FixGPTEnd;
    }

    if (SAIL_UPD_GPT_ID_PRIMARY == pReqMsg->fixGpt.ext_id.id)
    {
        ulAltGptId = SAIL_UPD_GPT_ID_SECONDARY;
    }
    else
    {
        ulAltGptId = SAIL_UPD_GPT_ID_PRIMARY;
    }

    if( SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(ulAltGptId, &xAltGPTHdr, &chkGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Alt GPT header read Failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto FixGPTEnd;
    }

    if ((0 == chkGPTparam.EntryCrcStatus) || (0 == chkGPTparam.HeaderCrcStatus))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Alt GPT header Invalid \n\r");
        eStatus = SAIL_UPDATER_ALT_GPT_INVALID;
        goto FixGPTEnd;
    }

    /* Validate Buffer Size */
    if (2* chkGPTparam.GptSize > pReqMsg->fixGpt.bufLen)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Invalid Buffer size 0x%x\n\r", pReqMsg->fixGpt.bufLen );
        eStatus = SAIL_UPDATER_INVALID_BUF_SIZE;
        goto FixGPTEnd;
    }

    if (0 == pReqMsg->fixGpt.bufLen)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Invalid Buffer size 0x%x\n\r", pReqMsg->fixGpt.bufLen );
        eStatus = SAIL_UPDATER_INVALID_BUF_SIZE;
        goto FixGPTEnd;
    }

    /* UnAligned Buffer size */
    if (pReqMsg->fixGpt.bufLen % SPINOR_BYTES_ALIGNMENT)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Unaligned Buffer Size \n\r");
        eStatus = SAIL_UPDATER_UNALIGNED_BUF_SIZE;
        goto FixGPTEnd;
    }

    /* Validate Buffer Address */
    if ((0U == pReqMsg->fixGpt.bufAddr) || (0U == bufAddrToUse) ||
        (FALSE == bPrvSAILUpdaterCoreIsAddrInRange(bufAddrToUse, pReqMsg->fixGpt.bufLen))
       )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Invalid Buffer Address \n\r");
        eStatus = SAIL_UPDATER_INVALID_BUF_ADDR;
        goto FixGPTEnd;
    }

    /* Read the source Partition Entries */
    if(SAIL_UPDATER_SUCCESS != bPrvSAILUpdaterGPTGetPartitionEntries ( &xAltGPTHdr, (uint8_t *)bufAddrToUse))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Source Partition entries read Failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto FixGPTEnd;
    }

    /* Copy the partition entries from Source to Destination buffer for the partition entries since they should be the same as source.
       Lower addresses of the buffer will be used for the Source and higher address for the destination */
    ulEntrySz  = xAltGPTHdr.size_of_partition_entry * xAltGPTHdr.number_of_partition_entries;

    result = sailbsp_memscpy((void *)(bufAddrToUse + chkGPTparam.GptSize), ulEntrySz, (const void *)bufAddrToUse, ulEntrySz);
    if(result == 0)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Copy partition entries from Source to destination buffer failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto FixGPTEnd;
    }

    /* Flush and Invalidate the cache for the higher address containing the destination content */
    clean_invalidate_cache_by_range((uint32) bufAddrToUse + chkGPTparam.GptSize, (uint32)bufAddrToUse + chkGPTparam.GptSize + ulEntrySz);

    /* Calcuate the buffer offsets for the destination from the Alt GPT header */
    if (SAIL_UPD_GPT_ID_PRIMARY == ulAltGptId)
    {
        partition_entry_offset = xAltGPTHdr.last_usable_lba + 1;
        partition_entry_size = xAltGPTHdr.first_usable_lba - xAltGPTHdr.partition_entry_lba;
    }
    else if (SAIL_UPD_GPT_ID_SECONDARY == ulAltGptId)
    {
        partition_entry_offset = xAltGPTHdr.alternate_lba + 1;
        partition_entry_size =  xAltGPTHdr.my_lba - xAltGPTHdr.partition_entry_lba;
    }

    /* Read the source GPT header. Already available in xAltGPTHdr. no need to read again */
    /* Copy the source GPT header to a temporary location */
    result = sailbsp_memscpy(&xGptHdr, sizeof(gptHeader_t), &xAltGPTHdr, sizeof(gptHeader_t));
    if(result == 0)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Copy GPT header from Source to temp location failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto FixGPTEnd;
    }

    /* Modify the contents of the destination GPT Header to make it valid */
    xGptHdr.header_crc32 = 0;
    temp_lba = xGptHdr.my_lba;
    xGptHdr.my_lba = xGptHdr.alternate_lba;
    xGptHdr.alternate_lba = temp_lba;
    xGptHdr.partition_entry_lba = partition_entry_offset;

    /* Calculate new Header CRC */
    tempCrc = gptCalcCRC32 ((const uint8_t *) &xGptHdr, xGptHdr.header_size, GPT_CRC32_SEED_DEFAULT);
    xGptHdr.header_crc32 = tempCrc;

    /* Calcuate the buffer offsets for the destination from the Alt GPT header */
    destHdrLba = xGptHdr.my_lba;

    /* Erase the Destination GPT header */
    result = spinorEl2Erase (g_SAILUpdaterEL2CoreCtx.norHandle, destHdrLba, 1);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Erase Destination GPT Header failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto FixGPTEnd;
    }

    /* Erase the Destination GPT partition entries */
    result = spinorEl2Erase (g_SAILUpdaterEL2CoreCtx.norHandle, partition_entry_offset, partition_entry_size);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Erase GPT Partition entries failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto FixGPTEnd;
    }

    block_size = g_SAILUpdaterEL2CoreCtx.memInfo.pages_per_block * g_SAILUpdaterEL2CoreCtx.memInfo.page_size_bytes;

    /* copy into max 4k chunks in to local work buffer and then write so that the buffer address is aligned */
    num_bytes = ulEntrySz;

    srcAddr = bufAddrToUse + chkGPTparam.GptSize;
    partitionOffsetAddr = partition_entry_offset * block_size;

    while (num_bytes)
    {
        max_transfersize = (num_bytes <= ARRAY_LENGTH(gSAILUpdaterEL2gptWorkBuf))?num_bytes:ARRAY_LENGTH(gSAILUpdaterEL2gptWorkBuf);

        /* Copy the entries from workbuffer to local buffers */
        result = sailbsp_memscpy(g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf, max_transfersize, (const void *)srcAddr, max_transfersize);
        if(result == 0)
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Copy entries workbuffer to local buffer failed \n\r");
            eStatus = SAIL_UPDATER_STATUS_FAIL;
            goto FixGPTEnd;
        }

        srcAddr += max_transfersize;

        if (max_transfersize == num_bytes)
        {
            max_transfersize = (num_bytes % SPINOR_BYTES_ALIGNMENT)? num_bytes + SPINOR_BYTES_ALIGNMENT - (num_bytes % SPINOR_BYTES_ALIGNMENT) : num_bytes;

            if ((max_transfersize != num_bytes ) && (max_transfersize > num_bytes))
            {
                memset(g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf + num_bytes, 0xFF, (max_transfersize - num_bytes));
            }
            num_bytes -= num_bytes;
        }
        else
        {
            num_bytes -= max_transfersize;
        }

        /* Flush and Invalidate the cache for the local buffer containing the destination content */
        clean_invalidate_cache_by_range((uint32)g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf, (uint32)g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf + max_transfersize);

        /* Write the Destination GPT partition entries */
        result = spinorEl2Write ( g_SAILUpdaterEL2CoreCtx.norHandle, partitionOffsetAddr, max_transfersize, (void *)g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf );
        if( result != SPINOR_DEVICE_DONE )
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Write partition entries failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
            goto FixGPTEnd;
        }
        partitionOffsetAddr += max_transfersize;
    }

    /* clear the buffers */
    memset( (void *)bufAddrToUse, 0, pReqMsg->fixGpt.bufLen);

    /* Flush and invalidate the cache */
    clean_invalidate_cache_by_range((uint32)bufAddrToUse, (uint32)bufAddrToUse + pReqMsg->fixGpt.bufLen);

    /* Copy the GPT header from temp location to Destination buffer */
    result = sailbsp_memscpy( (void *)g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf, sizeof(gptHeader_t), &xGptHdr, sizeof(gptHeader_t));
    if(result == 0)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Copy GPT header from Source to destination buffer failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto FixGPTEnd;
    }

    ulWriteSz = (sizeof(gptHeader_t) % SPINOR_BYTES_ALIGNMENT) ? sizeof(gptHeader_t) + SPINOR_BYTES_ALIGNMENT - (sizeof(gptHeader_t) % SPINOR_BYTES_ALIGNMENT) : sizeof(gptHeader_t);

    /* If the Write size is not aligned, then pad FFs to the data and write */
    if( (ulWriteSz != sizeof(gptHeader_t)) && (ulWriteSz > sizeof(gptHeader_t)))
    {
        memset((void *)(g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf + sizeof(gptHeader_t)), 0xFF, (ulWriteSz - sizeof(gptHeader_t)));
    }

    /* Flush and Invalidate the cache for the address containing the destination content */
    clean_invalidate_cache_by_range((uint32) g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf, (uint32)g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf + ulWriteSz);

    /* Write the Destination GPT header */
    result = spinorEl2Write ( g_SAILUpdaterEL2CoreCtx.norHandle, destHdrLba * block_size, ulWriteSz, (void *)g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Write partition entries failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto FixGPTEnd;
    }

    /* Verify the new destination GPT */
    if (SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(pReqMsg->fixGpt.ext_id.id, &xGptHdr, &chkDestGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Verify destination header read failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto FixGPTEnd;
    }

    if ((0 == chkDestGPTparam.EntryCrcStatus) || (0 == chkDestGPTparam.HeaderCrcStatus) || (chkDestGPTparam.GptSize != chkGPTparam.GptSize))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Destination GPT header Invalid \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto FixGPTEnd;
    }

    pRspMsg->status = SAIL_UPDATER_STATUS_SUCCESS;

FixGPTEnd:
    if (g_SAILUpdaterEL2CoreCtx.norHandle != NULL)
    {
        /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl2Close ( g_SAILUpdaterEL2CoreCtx.norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Spinor Close failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        }
        g_SAILUpdaterEL2CoreCtx.norHandle = NULL;
    }
    return eStatus;
}
#endif

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
#if 0
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessUpdateGPT(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;

    SPINOR_STATUS result;
    uint32_t byte_offset,byte_count,block_size,ulWriteSz;
    uint32_t destHdrLba;
    uint32_t crc;
    uint32_t i,j=0, idxA, idxB;
    sailUpdaterMsgUpdateGptEntryType *pImgEntry=NULL;
    uint32_t temp_crc, workBufAddr, ulEntrySz, num_bytes, srcAddr;
    uint32_t partitionOffsetAddr, max_transfersize;
    uint32_t bufAddrToUse = pReqMsg->updateGpt.bufAddr - SAIL_MD_DDR_ADDR_OFFSET;

    gptHeader_t xGPTHdr = {0}, xAltGPTHdr = {0};
    sailUpdaterCoreVerifyGPTtype xPrimaryGPTparam={0}, chkDestGPTparam={0}, chkGPTparam={0};

    guid_t tmpGuidA={0}, tmpGuidB={0};

    char imgGuid_A[GUID_STRING_SIZE+1] = "";      // dummy GUID
    char imgGuid_B[GUID_STRING_SIZE+1] = "";      // dummy GUID

    pRspMsg->msgId = SAIL_UPD_MSG_ID_UPDATE_GPT;

    pRspMsg->updateGpt.id = pReqMsg->updateGpt.id;
    pRspMsg->updateGpt.num = pReqMsg->updateGpt.num;

    /* Initalize SPINOR handle */
    g_SAILUpdaterEL2CoreCtx.norHandle = NULL;
    if(SPINOR_DEVICE_DONE != spinorEl2Open ( &g_SAILUpdaterEL2CoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Spinor Open failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto UpdateGPTEnd;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl2GetMemInfo(g_SAILUpdaterEL2CoreCtx.norHandle, &g_SAILUpdaterEL2CoreCtx.memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Spinor Get Mem Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto UpdateGPTEnd;
    }

    if (pReqMsg->updateGpt.id != SAIL_UPD_GPT_ID_PRIMARY)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Invalid GPT ID \n\r");
        eStatus = SAIL_UPDATER_INVALID_GPT_ID;
        goto UpdateGPTEnd;
    }

    if (SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(SAIL_UPD_GPT_ID_SECONDARY, &xAltGPTHdr, &chkGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Alt GPT header read Failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto UpdateGPTEnd;
    }

    if ((0 == chkGPTparam.EntryCrcStatus) || (0 == chkGPTparam.HeaderCrcStatus))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Alt GPT header Invalid HeaderCRC=0x%x EntryCRC=0x%x HeaderCrcStatus=0x%x EntryCrcStatus=0x%x\n\r",
                  xAltGPTHdr.header_crc32, xAltGPTHdr.partition_entries_crc32,chkGPTparam.HeaderCrcStatus, chkGPTparam.EntryCrcStatus);
        eStatus = SAIL_UPDATER_ALT_GPT_INVALID;
        goto UpdateGPTEnd;
    }

    if (pReqMsg->updateGpt.num > ARRAY_LENGTH(cSAILUpdaterEL2FlashImglist))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Invalid number of Images \n\r");
        eStatus = SAIL_UPDATER_INVALID_NUM_OF_IMAGES;
        goto UpdateGPTEnd;
    }

    /* Invalid Buffer Address */
    if ((0U == pReqMsg->updateGpt.bufAddr) || (0U == bufAddrToUse) ||
        (FALSE == bPrvSAILUpdaterCoreIsAddrInRange(bufAddrToUse, pReqMsg->updateGpt.bufLen))
       )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Invalid Buffer Address \n\r");
        eStatus = SAIL_UPDATER_INVALID_BUF_ADDR;
        goto UpdateGPTEnd;
    }

    /* Invalid Buffer Size */
    if (pReqMsg->updateGpt.bufLen <  (pReqMsg->updateGpt.num * sizeof(sailUpdaterMsgUpdateGptEntryType)) )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Invalid Buffer Size 0x%x\n\r", pReqMsg->updateGpt.bufLen);
        eStatus = SAIL_UPDATER_INVALID_BUF_SIZE;
        goto UpdateGPTEnd;
    }

    if (0 == pReqMsg->updateGpt.bufLen)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Invalid Buffer Size 0x%x\n\r", pReqMsg->updateGpt.bufLen);
        eStatus = SAIL_UPDATER_INVALID_BUF_SIZE;
        goto UpdateGPTEnd;
    }

    /* Copy the current CRC and Calculate Buffer CRC */
    temp_crc = pReqMsg->updateGpt.bufCrc;
    pReqMsg->updateGpt.bufCrc = 0;
    pReqMsg->updateGpt.bufCrc = ulSAILUpdaterCoreCalcCRC(bufAddrToUse, (pReqMsg->updateGpt.num * sizeof(sailUpdaterMsgUpdateGptEntryType)));

    /* Verify Buffer CRC */
    if (TRUE == bPrvSAILUpdaterCoreIsCRCNotMatch(temp_crc, pReqMsg->updateGpt.bufCrc))
    {
        eStatus = SAIL_UPDATER_INVALID_BUF_CRC;
        goto UpdateGPTEnd;
    }

    pImgEntry =  (sailUpdaterMsgUpdateGptEntryType *)bufAddrToUse;
    for ( i = 0; i < pReqMsg->updateGpt.num; i++)
    {
        /* Validate the Image */
        if (FALSE == bPrvSAILUpdaterCoreIsValidImg(UPDATER_FLASH_OPERATION, (const char *)pImgEntry->imgName))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Invalid Image name \n\r");
            eStatus = SAIL_UPDATER_INVALID_IMG_NAME;
            goto UpdateGPTEnd;
        }
        pImgEntry++;
    }

    /* Check the GPT health of Primary GPT */
    if (SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(SAIL_UPD_GPT_ID_PRIMARY, &xGPTHdr, &xPrimaryGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Getting Primary GPT health failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto UpdateGPTEnd;
    }

    if( (0 == xPrimaryGPTparam.HeaderCrcStatus) || (0 == xPrimaryGPTparam.EntryCrcStatus) )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Primary GPT Invalid \n\r");
        eStatus = SAIL_UPDATER_GPT_INVALID;
        goto UpdateGPTEnd;
    }

    /* Get reboot ctrl partition Info */
    result = spinorEl2GetGptPartitionInfo(g_SAILUpdaterEL2CoreCtx.norHandle, "bb7f4519-795e-471d-ac09-2d84c56cd253", &byte_offset, &byte_count);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Get Reboot Ctrl Partition Info failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto UpdateGPTEnd;
    }

    block_size = g_SAILUpdaterEL2CoreCtx.memInfo.pages_per_block * g_SAILUpdaterEL2CoreCtx.memInfo.page_size_bytes;

    /* Erase reboot ctrl Partition */
    result = spinorEl2Erase (g_SAILUpdaterEL2CoreCtx.norHandle, byte_offset/block_size, byte_count/block_size);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Erase Reboot Ctrl Partition failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto UpdateGPTEnd;
    }

    /* Write to reboot ctrl partition*/
    //todo: Dilip Update the writes with reboot ctrl data
    result = spinorEl2Write(g_SAILUpdaterEL2CoreCtx.norHandle, byte_offset, SPINOR_BYTES_ALIGNMENT, (void *)bufAddrToUse);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Write Reboot Ctrl Partition failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto UpdateGPTEnd;
    }

    /* Read the partition Entries to work buffer */
    workBufAddr = bufAddrToUse + (pReqMsg->updateGpt.num * sizeof(sailUpdaterMsgUpdateGptEntryType));
    if(SAIL_UPDATER_SUCCESS != bPrvSAILUpdaterGPTGetPartitionEntries(&xGPTHdr, (uint8_t *) workBufAddr) )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Parition Entries read Failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto UpdateGPTEnd;
    }

    /* For every image in the list get the IMG GUID A and B swap partition info */
    pImgEntry =  (sailUpdaterMsgUpdateGptEntryType *)bufAddrToUse;

    for (i=0;i < pReqMsg->updateGpt.num;i++)
    {
        /* Get the GUID A for the Image */
        if (XBL_SUCCESS != sailhyp_xbl_getImgGUID((const char *)&pImgEntry->imgName, XBL_PARTITION_A, pReqMsg->updateGpt.id, imgGuid_A))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Error Getting Image GUID A \n\r");
            eStatus = SAIL_UPDATER_STATUS_FAIL;
            goto UpdateGPTEnd;
        }

        if (XBL_SUCCESS != sailhyp_xbl_getImgGUID((const char *)&pImgEntry->imgName, XBL_PARTITION_B, pReqMsg->updateGpt.id, imgGuid_B))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Error Getting Image GUID B \n\r");
            eStatus = SAIL_UPDATER_STATUS_FAIL;
            goto UpdateGPTEnd;
        }

        if(FALSE == gptDecodeGUIDString ( imgGuid_A, &tmpGuidA))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Converting GUID String to GUID for Image GUID_A failed \n\r");
            eStatus = SAIL_UPDATER_STATUS_FAIL;
            goto UpdateGPTEnd;
        }

        if(FALSE == gptDecodeGUIDString ( imgGuid_B, &tmpGuidB))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Converting GUID String to GUID for Image GUID_B failed \n\r");
            eStatus = SAIL_UPDATER_STATUS_FAIL;
            goto UpdateGPTEnd;
        }

        idxA = ulPrvSAILUpdaterGPTGetPartitionEntryIdx(&xGPTHdr, &tmpGuidA, (uint8_t *)workBufAddr);
        idxB = ulPrvSAILUpdaterGPTGetPartitionEntryIdx(&xGPTHdr, &tmpGuidB, (uint8_t *)workBufAddr);

        if ( (xGPTHdr.number_of_partition_entries <= idxA) || (xGPTHdr.number_of_partition_entries <= idxB))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Could not locate Index for the Partition entry in buffer \n\r");
            eStatus = SAIL_UPDATER_STATUS_FAIL;
            goto UpdateGPTEnd;
        }

        vPrvSAILUpdaterSwapPartitionOffset((uint8_t *)workBufAddr, idxA, idxB);

        pImgEntry++;
    }

    ulEntrySz  = xGPTHdr.size_of_partition_entry * xGPTHdr.number_of_partition_entries;

    /* Flush and Invalidate the cache for the address containing the destination content */
    clean_invalidate_cache_by_range((uint32) workBufAddr, (uint32)workBufAddr + ulEntrySz);

    /* Calcuate the buffer offsets for the destination from the GPT header */
    destHdrLba = xGPTHdr.my_lba;

    /* Erase the Destination GPT header */
    result = spinorEl2Erase (g_SAILUpdaterEL2CoreCtx.norHandle, destHdrLba, 1);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Erase Destination GPT Header failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto UpdateGPTEnd;
    }

    /* Erase the Destination GPT partition entries */
    result = spinorEl2Erase(g_SAILUpdaterEL2CoreCtx.norHandle, xGPTHdr.partition_entry_lba, xGPTHdr.first_usable_lba - xGPTHdr.partition_entry_lba);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Erase GPT Partition entries failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto UpdateGPTEnd;
    }

    block_size = g_SAILUpdaterEL2CoreCtx.memInfo.pages_per_block * g_SAILUpdaterEL2CoreCtx.memInfo.page_size_bytes;

    /* copy into max 4k chunks in to local work buffer and then write so that the buffer address is aligned */
    num_bytes = ulEntrySz;

    srcAddr = workBufAddr;
    partitionOffsetAddr = xGPTHdr.partition_entry_lba * block_size;

    while (num_bytes)
    {
        max_transfersize = (num_bytes <= ARRAY_LENGTH(gSAILUpdaterEL2gptWorkBuf))?num_bytes:ARRAY_LENGTH(gSAILUpdaterEL2gptWorkBuf);

        /* Copy the entries from workbuffer to local buffers */
        result = sailbsp_memscpy(g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf, max_transfersize, (const void *) srcAddr, max_transfersize);
        if(result == 0)
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Copy entries workbuffer to local buffer failed \n\r");
            eStatus = SAIL_UPDATER_STATUS_FAIL;
            goto UpdateGPTEnd;
        }

        srcAddr += max_transfersize;

        /* Add padding bytes to make it aligned if needed and memset it to 1 */
        if (max_transfersize == num_bytes)
        {
            max_transfersize = (num_bytes % SPINOR_BYTES_ALIGNMENT)? num_bytes + SPINOR_BYTES_ALIGNMENT - (num_bytes % SPINOR_BYTES_ALIGNMENT) : num_bytes;

            if ((max_transfersize != num_bytes ) && (max_transfersize > num_bytes))
            {
                memset(g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf + num_bytes, 0xFF, (max_transfersize - num_bytes));
            }
            num_bytes -= num_bytes;
        }
        else
        {
            num_bytes -= max_transfersize;
        }

        /* Flush and Invalidate the cache for the local buffer containing the destination content */
        clean_invalidate_cache_by_range((uint32)g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf, (uint32)g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf + max_transfersize);

        /* Write the Destination GPT partition entries */
        result = spinorEl2Write ( g_SAILUpdaterEL2CoreCtx.norHandle, partitionOffsetAddr, max_transfersize, (void *)g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf );
        if( result != SPINOR_DEVICE_DONE )
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Write partition entries failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
            goto UpdateGPTEnd;
        }
        partitionOffsetAddr += max_transfersize;
    }

    /* Calculate partition entries CRC */
    crc = gptCalcCRC32 ((const uint8_t *)workBufAddr, ulEntrySz, GPT_CRC32_SEED_DEFAULT);

    /* Update the partition CRC in the GPT header */
    xGPTHdr.partition_entries_crc32 = crc;

    /* Calculate the new Header CRC */
    xGPTHdr.header_crc32 = 0;

    crc = gptCalcCRC32((const uint8_t *)&xGPTHdr, xGPTHdr.header_size, GPT_CRC32_SEED_DEFAULT);

    xGPTHdr.header_crc32 = crc;

    /* Copy the GPT header to Destination buffer that can accommodate extra bytes for taking care of padding for alignment */
    result = sailbsp_memscpy(g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf, sizeof(gptHeader_t), &xGPTHdr, sizeof(gptHeader_t));
    if(result == 0)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Copy GPT header from Source to destination buffer failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto UpdateGPTEnd;
    }

    ulWriteSz = (sizeof(gptHeader_t) % SPINOR_BYTES_ALIGNMENT) ? sizeof(gptHeader_t) + SPINOR_BYTES_ALIGNMENT - (sizeof(gptHeader_t) % SPINOR_BYTES_ALIGNMENT) : sizeof(gptHeader_t);

    /* If the Write size is not aligned, then pad FFs to the data and write */
    if( (ulWriteSz != sizeof(gptHeader_t)) && (ulWriteSz > sizeof(gptHeader_t)))
    {
        memset(g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf + sizeof(gptHeader_t), 0xFF, (ulWriteSz - sizeof(gptHeader_t)));
    }

    /* Flush and Invalidate the cache for the address containing the destination content */
    clean_invalidate_cache_by_range((uint32)g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf, (uint32)g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf + ulWriteSz);

    block_size = g_SAILUpdaterEL2CoreCtx.memInfo.pages_per_block * g_SAILUpdaterEL2CoreCtx.memInfo.page_size_bytes;

    /* Write the Destination GPT header */
    result = spinorEl2Write ( g_SAILUpdaterEL2CoreCtx.norHandle, destHdrLba * block_size, ulWriteSz, (void *)g_SAILUpdaterEL2CoreCtx.pGPTWorkBuf);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Write partition entries failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto UpdateGPTEnd;
    }

    /* Verify the new destination GPT */
    if (SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(pReqMsg->updateGpt.id, &xGPTHdr, &chkDestGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Verify destination header read failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto UpdateGPTEnd;
    }

    if ((0 == chkDestGPTparam.EntryCrcStatus) || (0 == chkDestGPTparam.HeaderCrcStatus) || (chkDestGPTparam.GptSize != xPrimaryGPTparam.GptSize))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Destination GPT header Invalid \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto UpdateGPTEnd;
    }

    pRspMsg->status = SAIL_UPDATER_STATUS_SUCCESS;

UpdateGPTEnd:
    if (g_SAILUpdaterEL2CoreCtx.norHandle != NULL)
    {
        /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl2Close ( g_SAILUpdaterEL2CoreCtx.norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Spinor Close failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        }
        g_SAILUpdaterEL2CoreCtx.norHandle = NULL;
    }
    return eStatus;
}
#endif

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
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessQueryImg(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;
    uint32_t i,j=0;
    uint32_t temp_crc;
    uint32_t pulIndex=0;
    sailUpdaterImageEntryType *pImgEntry=NULL;
    XBLBootInfoType xBootInfo[XBL_IMAGE_ID_MAX]={0};
    sailUpdaterCoreVerifyGPTtype xPrimaryGPTparam={0}, xSecondaryGPTparam ={0};

    uint32_t bufAddrToUse = pReqMsg->queryImg.bufAddr - SAIL_MD_DDR_ADDR_OFFSET;
    uint32_t bootPartitionID, bootGPTID;

    char imgGuid_A[GUID_STRING_SIZE+1] = "";      // dummy GUID
    char imgGuid_B[GUID_STRING_SIZE+1] = "";      // dummy GUID
    guid_t tmpGuidA={0}, tmpGuidB={0};

    uint32_t partitionSizeA_1;                  /* the maximum size of partition A in Primary table */
    uint32_t partitionSizeB_1;                  /* the maximum size of partition B in Primary table */
    uint32_t partitionSizeA_2;                  /* the maximum size of partition A in Secondary table */
    uint32_t partitionSizeB_2;                  /* the maximum size of partition B in Secondary table */

    uint32_t partitionAddrA_1;                  /* Partition A start address in Primary table */
    uint32_t partitionAddrB_1;                  /* Partition B start address in Primary table */
    uint32_t partitionAddrA_2;                  /* Partition A start address in Secondary table */
    uint32_t partitionAddrB_2;                  /* Partition B start address in Secondary table */

    pRspMsg->msgId = SAIL_UPD_MSG_ID_QUERY_IMAGES;

    /* Initalize SPINOR handle */
    g_SAILUpdaterEL2CoreCtx.norHandle = NULL;
    if(SPINOR_DEVICE_DONE != spinorEl2Open ( &g_SAILUpdaterEL2CoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Spinor Open failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessQueryImgEnd;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl2GetMemInfo(g_SAILUpdaterEL2CoreCtx.norHandle, &g_SAILUpdaterEL2CoreCtx.memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Spinor Get Mem Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessQueryImgEnd;
    }

    if (pReqMsg->queryImg.num_images > ARRAY_LENGTH(cSAILUpdaterEL2FlashImglist))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Invalid number of Images \n\r");
        eStatus = SAIL_UPDATER_INVALID_NUM_OF_IMAGES;
        goto ProcessQueryImgEnd;
    }

    /* Invalid Buffer Address */
    if ((0U == pReqMsg->queryImg.bufAddr) || (0U == bufAddrToUse) ||
        (FALSE == bPrvSAILUpdaterCoreIsAddrInRange(bufAddrToUse, pReqMsg->queryImg.bufLen))
       )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Invalid Buffer Address \n\r");
        eStatus = SAIL_UPDATER_INVALID_BUF_ADDR;
        goto ProcessQueryImgEnd;
    }

    /* Invalid Buffer Size */
    if (pReqMsg->queryImg.bufLen <  (pReqMsg->queryImg.num_images * sizeof(sailUpdaterImageEntryType)) )
    {
         DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Invalid Buffer Size 0x%x\n\r", pReqMsg->queryImg.bufLen);
        eStatus = SAIL_UPDATER_INVALID_BUF_SIZE;
        goto ProcessQueryImgEnd;
    }

    if (0 == pReqMsg->queryImg.bufLen)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Invalid Buffer Size 0x%x\n\r", pReqMsg->queryImg.bufLen);
        eStatus = SAIL_UPDATER_INVALID_BUF_SIZE;
        goto ProcessQueryImgEnd;
    }

    /* Copy the current CRC and Calculate Buffer CRC */
    temp_crc = pReqMsg->queryImg.bufCrc;
    pReqMsg->queryImg.bufCrc = 0;
    pReqMsg->queryImg.bufCrc = ulSAILUpdaterCoreCalcCRC(bufAddrToUse, pReqMsg->queryImg.bufLen);

    /* Verify Buffer CRC */
    if (TRUE == bPrvSAILUpdaterCoreIsCRCNotMatch(temp_crc, pReqMsg->queryImg.bufCrc))
    {
        eStatus = SAIL_UPDATER_INVALID_BUF_CRC;
        goto ProcessQueryImgEnd;
    }

    pImgEntry =  (sailUpdaterImageEntryType *)bufAddrToUse;
    for ( i = 0; i < pReqMsg->queryImg.num_images; i++)
    {
        /* Validate the Image */
        if (FALSE == bPrvSAILUpdaterCoreIsValidImg(UPDATER_FLASH_OPERATION, (const char *)pImgEntry->imgName))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Invalid Image name \n\r");
            eStatus = SAIL_UPDATER_INVALID_IMG_NAME;
            goto ProcessQueryImgEnd;
        }
        pImgEntry++;
    }

    /* Check the GPT health of Primary GPT */
    if (SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(SAIL_UPD_GPT_ID_PRIMARY, &g_SAILUpdaterEL2CoreCtx.PrimaryGPTHdr, &xPrimaryGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Getting Primary GPT health failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessQueryImgEnd;
    }

    /* Check the GPT health of Secondary GPT */
    if (SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(SAIL_UPD_GPT_ID_SECONDARY, &g_SAILUpdaterEL2CoreCtx.SecondaryGPTHdr, &xSecondaryGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Getting Secondary GPT health failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessQueryImgEnd;
    }

    /* Get the boot info from XBL */
    if (sailhyp_xbl_queryBootInfo(xBootInfo, XBL_IMAGE_ID_MAX))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Getting Image info from XBL failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessQueryImgEnd;
    }

    /* check the boot info and populate the response */
    pImgEntry =  (sailUpdaterImageEntryType *)bufAddrToUse;

    for ( i = 0; i < pReqMsg->queryImg.num_images; i++)
    {
        /* find the image */
        for ( j = 0; j < ARRAY_LENGTH(xBootInfo); j++)
        {
            if (strlen((const char *)pImgEntry->imgName) != strlen(xBootInfo[j].img_name))
            {
                continue;
            }

            if (0 == strncmp(xBootInfo[j].img_name, (const char *) pImgEntry->imgName,strlen(xBootInfo[j].img_name)))
            {
                bootGPTID = (XBL_GPT_TABLE_PRIMARY == xBootInfo[j].gpt_id)?SAIL_UPD_GPT_ID_PRIMARY:(XBL_GPT_TABLE_SECONDARY == xBootInfo[j].gpt_id)?SAIL_UPD_GPT_ID_SECONDARY:SAIL_UPD_GPT_ID_MAX;
                bootPartitionID = (XBL_PARTITION_A == xBootInfo[j].partition_id)?SAIL_UPD_PARTITION_ID_PRIMARY:(XBL_PARTITION_B == xBootInfo[j].partition_id)?SAIL_UPD_PARTITION_ID_SECONDARY:SAIL_UPD_PARTITION_ID_MAX;

                if (SAIL_UPD_GPT_ID_MAX == bootGPTID)
                {
                    /* If the bootGPTID is not updated, update the information based on one of the valid GPT. Primary first and then secondary */
                    if( (1 == xPrimaryGPTparam.HeaderCrcStatus) && (1 == xPrimaryGPTparam.EntryCrcStatus) )
                    {
                        bootGPTID = SAIL_UPD_GPT_ID_PRIMARY;
                    }
                    else if( (1 == xSecondaryGPTparam.HeaderCrcStatus) && (1 == xSecondaryGPTparam.EntryCrcStatus) )
                    {
                        bootGPTID = SAIL_UPD_GPT_ID_SECONDARY;
                    }
                    else
                    {
                        bootGPTID = SAIL_UPD_GPT_ID_MAX;
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Boot GPT ID not available \n\r");
                        eStatus = SAIL_UPDATER_BOOT_INFO_UNAVAILABLE;
                        goto ProcessQueryImgEnd;
                    }
                }

                if (SAIL_UPD_PARTITION_ID_MAX == bootPartitionID)
                {
                    /* If boot Partition ID is not set, image is probably not loaded. No Need to error out. Set the partition ID as MAX as an error.
                       Info can be requested again later with retry. */
                    DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Boot Partition ID not available \n\r");
                }

                pImgEntry->bootGptId = bootGPTID;
                pImgEntry->bootPartition = bootPartitionID;

                /* Get the GUID for the Image */
                if(sailhyp_xbl_getImgGUID((const char *)pImgEntry->imgName, XBL_PARTITION_A, bootGPTID, imgGuid_A))
                {
                    DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Get Image GUID_A failed \n\r");
                    eStatus = SAIL_UPDATER_STATUS_FAIL;
                    goto ProcessQueryImgEnd;
                }

                if(sailhyp_xbl_getImgGUID((const char *)pImgEntry->imgName, XBL_PARTITION_B, bootGPTID, imgGuid_B))
                {
                    DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Get Image GUID_B failed \n\r");
                    eStatus = SAIL_UPDATER_STATUS_FAIL;
                    goto ProcessQueryImgEnd;
                }

                /* Read both the GPT headers */
                /* If the Primary GPT is valid, get the Primary GPT header and read the partition info from it */
                if( (1 == xPrimaryGPTparam.HeaderCrcStatus) && (1 == xPrimaryGPTparam.EntryCrcStatus) )
                {
                    if( SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterGetGPTHdr(SAIL_UPD_GPT_ID_PRIMARY, &g_SAILUpdaterEL2CoreCtx.PrimaryGPTHdr) )
                    {
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Reading Primary GPT header failed \n\r");
                        eStatus = SAIL_UPDATER_STATUS_FAIL;
                        goto ProcessQueryImgEnd;
                    }

                    if(FALSE == gptDecodeGUIDString ( imgGuid_A, &tmpGuidA))
                    {
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Converting GUID String to GUID for Image GUID_A failed \n\r");
                        eStatus = SAIL_UPDATER_STATUS_FAIL;
                        goto ProcessQueryImgEnd;
                    }

                    if(FALSE == gptDecodeGUIDString ( imgGuid_B, &tmpGuidB))
                    {
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Converting GUID String to GUID for Image GUID_B failed \n\r");
                        eStatus = SAIL_UPDATER_STATUS_FAIL;
                        goto ProcessQueryImgEnd;
                    }

                    /* Get the Partition Info A and B partitions for Image from Primary Header */
                    if(FALSE == bPrvSAILUpdaterGPTGetPartitionInfo (&g_SAILUpdaterEL2CoreCtx.PrimaryGPTHdr, &tmpGuidA, &partitionAddrA_1, &partitionSizeA_1, &pulIndex ))
                    {
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Get Partition Info from Primary GPT for Image GUID_A failed \n\r");
                        eStatus = SAIL_UPDATER_STATUS_FAIL;
                        goto ProcessQueryImgEnd;
                    }

                    if(FALSE == bPrvSAILUpdaterGPTGetPartitionInfo (&g_SAILUpdaterEL2CoreCtx.PrimaryGPTHdr, &tmpGuidB, &partitionAddrB_1, &partitionSizeB_1, &pulIndex ))
                    {
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Get Partition Info from Primary GPT for Image GUID_B failed \n\r");
                        eStatus = SAIL_UPDATER_STATUS_FAIL;
                        goto ProcessQueryImgEnd;
                    }

                }
                else
                {
                    partitionAddrA_1 = partitionSizeA_1 = partitionAddrB_1 = partitionSizeB_1 = 0;

                }

                /* If the secondary GPT is valid, get the secondary GPT header and read the partition info from it */
                if ( (1 == xSecondaryGPTparam.HeaderCrcStatus) && (1 == xSecondaryGPTparam.EntryCrcStatus) )
                {
                    if (SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterGetGPTHdr(SAIL_UPD_GPT_ID_SECONDARY, &g_SAILUpdaterEL2CoreCtx.SecondaryGPTHdr))
                    {
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Reading Secondary GPT header failed \n\r");
                        eStatus = SAIL_UPDATER_STATUS_FAIL;
                        goto ProcessQueryImgEnd;
                    }

                    if(FALSE == gptDecodeGUIDString ( imgGuid_A, &tmpGuidA))
                    {
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Converting GUID String to GUID for Image GUID_A failed \n\r");
                        eStatus = SAIL_UPDATER_STATUS_FAIL;
                        goto ProcessQueryImgEnd;
                    }

                    if(FALSE == gptDecodeGUIDString ( imgGuid_B, &tmpGuidB))
                    {
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Converting GUID String to GUID for Image GUID_B failed \n\r");
                        eStatus = SAIL_UPDATER_STATUS_FAIL;
                        goto ProcessQueryImgEnd;
                    }

                    /* Get the Partition Info A and B partitions for Image from Secondary Header */
                    if (FALSE == bPrvSAILUpdaterGPTGetPartitionInfo(&g_SAILUpdaterEL2CoreCtx.SecondaryGPTHdr, &tmpGuidA, &partitionAddrA_2, &partitionSizeA_2, &pulIndex))
                    {
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Get Partition Info from Secondary GPT for Image GUID_A failed \n\r");
                        eStatus = SAIL_UPDATER_STATUS_FAIL;
                        goto ProcessQueryImgEnd;
                    }

                    if(FALSE == bPrvSAILUpdaterGPTGetPartitionInfo (&g_SAILUpdaterEL2CoreCtx.SecondaryGPTHdr, &tmpGuidB, &partitionAddrB_2, &partitionSizeB_2 , &pulIndex))
                    {
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Get Partition Info from Secondary GPT for Image GUID_B failed \n\r");
                        eStatus = SAIL_UPDATER_STATUS_FAIL;
                        goto ProcessQueryImgEnd;
                    }
                }
                else
                {
                    partitionAddrA_2 = partitionSizeA_2 = partitionAddrB_2 = partitionSizeB_2 = 0;

                }

                /* Get partition size of A and B from boot GPT ID and Check if the entries are matching from other GPT ID */
                if (SAIL_UPD_GPT_ID_PRIMARY == bootGPTID)
                {
                    pImgEntry->partitionSizeA = partitionSizeA_1;
                    pImgEntry->partitionSizeB = partitionSizeB_1;
                }
                else if (SAIL_UPD_GPT_ID_SECONDARY == bootGPTID)
                {
                    pImgEntry->partitionSizeA = partitionSizeA_2;
                    pImgEntry->partitionSizeB = partitionSizeB_2;

                }
                else
                {
                    // already handled. nothing to do here
                }

                if( (partitionAddrA_1 != partitionAddrA_2) || (partitionAddrB_1 != partitionAddrB_2)
                     || (partitionSizeA_1 != partitionSizeA_2) || (partitionSizeB_1 != partitionSizeB_2) )
                {
                    pImgEntry->isTwoGptTableEntriesMatching = 0; // 0 is not matching

                }
                else
                {
                    pImgEntry->isTwoGptTableEntriesMatching = 1; // 1 is matching
                }

                break;
            }
        }

        /* If the Image is not found in the boot Info list, then flag an error */
        if (j == ARRAY_LENGTH(xBootInfo))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Image not found in the boot info list \n\r");
            eStatus = SAIL_UPDATER_STATUS_FAIL;
            goto ProcessQueryImgEnd;
        }

        pImgEntry++;
    }

    pRspMsg->queryImg.num_images = pReqMsg->queryImg.num_images;

    /* Copy Buffer Address and Length from the request into the response header */
    pRspMsg->queryImg.bufAddr = pReqMsg->queryImg.bufAddr;
    pRspMsg->queryImg.bufLen = (pRspMsg->queryImg.num_images * sizeof(sailUpdaterImageEntryType));

    /* Calculate Buffer CRC */
    pRspMsg->queryImg.bufCrc = 0;
    pRspMsg->queryImg.bufCrc = ulSAILUpdaterCoreCalcCRC(bufAddrToUse, pRspMsg->queryImg.bufLen);

    /* Flush and Invalidate the cache */
    clean_invalidate_cache_by_range((uint32) bufAddrToUse,(uint32)bufAddrToUse +  pRspMsg->queryImg.bufLen);

    pRspMsg->status = SAIL_UPDATER_STATUS_SUCCESS;

ProcessQueryImgEnd:
    if (g_SAILUpdaterEL2CoreCtx.norHandle != NULL)
    {
        /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl2Close ( g_SAILUpdaterEL2CoreCtx.norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Spinor Close failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        }
        g_SAILUpdaterEL2CoreCtx.norHandle = NULL;
    }
    pImgEntry = NULL;
    return eStatus;
}

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
#if 1
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessGetBootInfo(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;
    uint32_t i,j=0;
    sailUpdaterImageEntryType *pImgEntry=NULL;
    uint32_t temp_crc;
    uint32_t pulIndex=0;
    XBLBootInfoType xBootInfo[XBL_IMAGE_ID_MAX]={0};
    sailUpdaterCoreVerifyGPTtype xPrimaryGPTparam={0}, xSecondaryGPTparam ={0};

    uint32_t bufAddrToUse = pReqMsg->bootInfo.imgInfo.bufAddr - SAIL_MD_DDR_ADDR_OFFSET;
    uint32_t bootPartitionID, bootGPTID;

    char imgGuid_A[GUID_STRING_SIZE+1] = "";      // dummy GUID
    char imgGuid_B[GUID_STRING_SIZE+1] = "";      // dummy GUID
    guid_t tmpGuidA={0}, tmpGuidB={0};

    uint32_t partitionSizeA_1;                  /* the maximum size of partition A in Primary table */
    uint32_t partitionSizeB_1;                  /* the maximum size of partition B in Primary table */
    uint32_t partitionSizeA_2;                  /* the maximum size of partition A in Secondary table */
    uint32_t partitionSizeB_2;                  /* the maximum size of partition B in Secondary table */

    uint32_t partitionAddrA_1;                  /* Partition A start address in Primary table */
    uint32_t partitionAddrB_1;                  /* Partition B start address in Primary table */
    uint32_t partitionAddrA_2;                  /* Partition A start address in Secondary table */
    uint32_t partitionAddrB_2;                  /* Partition B start address in Secondary table */


    pRspMsg->msgId = SAIL_UPD_MSG_ID_GET_BOOTINFO;

    /* Initalize SPINOR handle */
    g_SAILUpdaterEL2CoreCtx.norHandle = NULL;
    if(SPINOR_DEVICE_DONE != spinorEl2Open ( &g_SAILUpdaterEL2CoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Spinor Open failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessBootInfoEnd;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl2GetMemInfo(g_SAILUpdaterEL2CoreCtx.norHandle, &g_SAILUpdaterEL2CoreCtx.memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Spinor Get Mem Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessBootInfoEnd;
    }

    if (pReqMsg->bootInfo.imgInfo.num_images > ARRAY_LENGTH(cSAILUpdaterEL2FlashImglist))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Invalid number of Images \n\r");
        eStatus = SAIL_UPDATER_INVALID_NUM_OF_IMAGES;
        goto ProcessBootInfoEnd;
    }

    /* Invalid Buffer Address */
    if ((0U == pReqMsg->bootInfo.imgInfo.bufAddr) || (0U == bufAddrToUse) ||
        (FALSE == bPrvSAILUpdaterCoreIsAddrInRange(bufAddrToUse, pReqMsg->bootInfo.imgInfo.bufLen))
       )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Invalid Buffer Address \n\r");
        eStatus = SAIL_UPDATER_INVALID_BUF_ADDR;
        goto ProcessBootInfoEnd;
    }

    /* Invalid Buffer Size */
    if (pReqMsg->bootInfo.imgInfo.bufLen <  (pReqMsg->bootInfo.imgInfo.num_images * sizeof(sailUpdaterImageEntryType)) )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Invalid Buffer Size \n\r");
        eStatus = SAIL_UPDATER_INVALID_BUF_SIZE;
        goto ProcessBootInfoEnd;
    }

    if (0 == pReqMsg->bootInfo.imgInfo.bufLen )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Invalid Buffer Size 0x%x \n\r", pReqMsg->bootInfo.imgInfo.bufLen );
        eStatus = SAIL_UPDATER_INVALID_BUF_SIZE;
        goto ProcessBootInfoEnd;
    }

    /* Copy the current CRC and Calculate Buffer CRC */
    temp_crc = pReqMsg->bootInfo.imgInfo.bufCrc;
    pReqMsg->bootInfo.imgInfo.bufCrc = 0;
    pReqMsg->bootInfo.imgInfo.bufCrc = ulSAILUpdaterCoreCalcCRC(bufAddrToUse, pReqMsg->bootInfo.imgInfo.bufLen);

    /* Verify Buffer CRC */
    if (TRUE == bPrvSAILUpdaterCoreIsCRCNotMatch(temp_crc, pReqMsg->bootInfo.imgInfo.bufCrc))
    {
        eStatus = SAIL_UPDATER_INVALID_BUF_CRC;
        goto ProcessBootInfoEnd;
    }

    pImgEntry =  (sailUpdaterImageEntryType *)bufAddrToUse;
    for ( i = 0; i < pReqMsg->bootInfo.imgInfo.num_images; i++)
    {
        /* Validate the Image */
        if (FALSE == bPrvSAILUpdaterCoreIsValidImg(UPDATER_FLASH_OPERATION, (const char *)pImgEntry->imgName))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Invalid Image name \n\r");
            eStatus = SAIL_UPDATER_INVALID_IMG_NAME;
            goto ProcessBootInfoEnd;
        }
        pImgEntry++;
    }

    /* Check the GPT health of Primary GPT */
    if (SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(SAIL_UPD_GPT_ID_PRIMARY, &g_SAILUpdaterEL2CoreCtx.PrimaryGPTHdr, &xPrimaryGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Getting Primary GPT health failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessBootInfoEnd;
    }

    /* Check the GPT health of Secondary GPT */
    if (SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(SAIL_UPD_GPT_ID_SECONDARY, &g_SAILUpdaterEL2CoreCtx.SecondaryGPTHdr, &xSecondaryGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Getting Secondary GPT health failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessBootInfoEnd;
    }

    /* Get the boot info from XBL. Need to pass in array size */
    if (sailhyp_xbl_queryBootInfo(xBootInfo,XBL_IMAGE_ID_MAX))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Getting Image info from XBL failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessBootInfoEnd;
    }

    /* check the boot info and populate the response */
    pImgEntry =  (sailUpdaterImageEntryType *)bufAddrToUse;

    for ( i = 0; i < pReqMsg->bootInfo.imgInfo.num_images; i++)
    {
        /* find the image */
        for ( j = 0; j < ARRAY_LENGTH(xBootInfo); j++)
        {
            if (strlen((const char *)pImgEntry->imgName) != strlen(xBootInfo[j].img_name))
            {
                continue;
            }
            if (0 == strncmp(xBootInfo[j].img_name, (const char *) pImgEntry->imgName,strlen(xBootInfo[j].img_name)))
            {
                bootGPTID = (XBL_GPT_TABLE_PRIMARY == xBootInfo[j].gpt_id)?SAIL_UPD_GPT_ID_PRIMARY:(XBL_GPT_TABLE_SECONDARY == xBootInfo[j].gpt_id)?SAIL_UPD_GPT_ID_SECONDARY:SAIL_UPD_GPT_ID_MAX;
                bootPartitionID = (XBL_PARTITION_A == xBootInfo[j].partition_id)?SAIL_UPD_PARTITION_ID_PRIMARY:(XBL_PARTITION_B == xBootInfo[j].partition_id)?SAIL_UPD_PARTITION_ID_SECONDARY:SAIL_UPD_PARTITION_ID_MAX;

                if (SAIL_UPD_GPT_ID_MAX == bootGPTID)
                {
                    //handle error?? //todo: dilip Do not error out.
//                  DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Boot GPT ID not available \n\r");
//                  eStatus = SAIL_UPDATER_BOOT_INFO_UNAVAILABLE;
//                  goto ProcessBootInfoEnd;

                    /* If the bootGPTID is not updated, update the information based on one of the valid GPT. Primary first and then secondary */
                    if( (1 == xPrimaryGPTparam.HeaderCrcStatus) && (1 == xPrimaryGPTparam.EntryCrcStatus) )
                    {
                        bootGPTID = SAIL_UPD_GPT_ID_PRIMARY;
                    }
                    else if( (1 == xSecondaryGPTparam.HeaderCrcStatus) && (1 == xSecondaryGPTparam.EntryCrcStatus) )
                    {
                        bootGPTID = SAIL_UPD_GPT_ID_SECONDARY;
                    }
                    else
                    {
                        bootGPTID = SAIL_UPD_GPT_ID_MAX;
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Boot GPT ID not available \n\r");
                        eStatus = SAIL_UPDATER_BOOT_INFO_UNAVAILABLE;
                        goto ProcessBootInfoEnd;
                    }
                }

                if (SAIL_UPD_PARTITION_ID_MAX == bootPartitionID)
                {
                    /* If boot Partition ID is not set, image is probably not loaded. No Need to error out. Set the partition ID as MAX as an error.
                       Info can be requested again later with retry. */
                    DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Boot Partition ID not available \n\r");
                }

                pImgEntry->bootGptId = bootGPTID;
                pImgEntry->bootPartition = bootPartitionID;

                /* Get the GUID for the Image */
                if(sailhyp_xbl_getImgGUID((const char *)pImgEntry->imgName, XBL_PARTITION_A, bootGPTID, imgGuid_A))
                {
                    DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Get Image GUID_A failed \n\r");
                    eStatus = SAIL_UPDATER_STATUS_FAIL;
                    goto ProcessBootInfoEnd;
                }

                if(sailhyp_xbl_getImgGUID((const char *)pImgEntry->imgName, XBL_PARTITION_B, bootGPTID, imgGuid_B))
                {
                    DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Get Image GUID_B failed \n\r");
                    eStatus = SAIL_UPDATER_STATUS_FAIL;
                    goto ProcessBootInfoEnd;
                }

                /* Read both the GPT headers */

                /* If the Primary GPT is valid, get the Primary GPT header and read the partition info from it */
                if( (1 == xPrimaryGPTparam.HeaderCrcStatus) && (1 == xPrimaryGPTparam.EntryCrcStatus) )
                {
                    if( SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterGetGPTHdr(SAIL_UPD_GPT_ID_PRIMARY, &g_SAILUpdaterEL2CoreCtx.PrimaryGPTHdr) )
                    {
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Reading Primary GPT header failed \n\r");
                        eStatus = SAIL_UPDATER_STATUS_FAIL;
                        goto ProcessBootInfoEnd;
                    }

                    if(FALSE == gptDecodeGUIDString ( imgGuid_A, &tmpGuidA))
                    {
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Converting GUID String to GUID for Image GUID_A failed \n\r");
                        eStatus = SAIL_UPDATER_STATUS_FAIL;
                        goto ProcessBootInfoEnd;
                    }

                    if(FALSE == gptDecodeGUIDString ( imgGuid_B, &tmpGuidB))
                    {
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Converting GUID String to GUID for Image GUID_B failed \n\r");
                        eStatus = SAIL_UPDATER_STATUS_FAIL;
                        goto ProcessBootInfoEnd;
                    }

                    /* Get the Partition Info A and B partitions for Image from Primary Header */
                    if(FALSE == bPrvSAILUpdaterGPTGetPartitionInfo (&g_SAILUpdaterEL2CoreCtx.PrimaryGPTHdr, &tmpGuidA, &partitionAddrA_1, &partitionSizeA_1, &pulIndex ))
                    {
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Get Partition Info from Primary GPT for Image GUID_A failed \n\r");
                        eStatus = SAIL_UPDATER_STATUS_FAIL;
                        goto ProcessBootInfoEnd;
                    }

                    if(FALSE == bPrvSAILUpdaterGPTGetPartitionInfo (&g_SAILUpdaterEL2CoreCtx.PrimaryGPTHdr, &tmpGuidB, &partitionAddrB_1, &partitionSizeB_1, &pulIndex))
                    {
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Get Partition Info from Primary GPT for Image GUID_B failed \n\r");
                        eStatus = SAIL_UPDATER_STATUS_FAIL;
                        goto ProcessBootInfoEnd;
                    }

                }
                else
                {
                    partitionAddrA_1 = partitionSizeA_1 = partitionAddrB_1 = partitionSizeB_1 = 0;

                }

                /* If the secondary GPT is valid, get the secondary GPT header and read the partition info from it */
                if ( (1 == xSecondaryGPTparam.HeaderCrcStatus) && (1 == xSecondaryGPTparam.EntryCrcStatus) )
                {
                    if (SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterGetGPTHdr(SAIL_UPD_GPT_ID_SECONDARY, &g_SAILUpdaterEL2CoreCtx.SecondaryGPTHdr))
                    {
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Reading Secondary GPT header failed \n\r");
                        eStatus = SAIL_UPDATER_STATUS_FAIL;
                        goto ProcessBootInfoEnd;
                    }

                    if(FALSE == gptDecodeGUIDString ( imgGuid_A, &tmpGuidA))
                    {
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Converting GUID String to GUID for Image GUID_A failed \n\r");
                        eStatus = SAIL_UPDATER_STATUS_FAIL;
                        goto ProcessBootInfoEnd;
                    }

                    if(FALSE == gptDecodeGUIDString ( imgGuid_B, &tmpGuidB))
                    {
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Converting GUID String to GUID for Image GUID_B failed \n\r");
                        eStatus = SAIL_UPDATER_STATUS_FAIL;
                        goto ProcessBootInfoEnd;
                    }

                    /* Get the Partition Info A and B partitions for Image from Secondary Header */
                    if (FALSE == bPrvSAILUpdaterGPTGetPartitionInfo(&g_SAILUpdaterEL2CoreCtx.SecondaryGPTHdr, &tmpGuidA, &partitionAddrA_2, &partitionSizeA_2, &pulIndex))
                    {
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Get Partition Info from Secondary GPT for Image GUID_A failed \n\r");
                        eStatus = SAIL_UPDATER_STATUS_FAIL;
                        goto ProcessBootInfoEnd;
                    }

                    if(FALSE == bPrvSAILUpdaterGPTGetPartitionInfo (&g_SAILUpdaterEL2CoreCtx.SecondaryGPTHdr, &tmpGuidB, &partitionAddrB_2, &partitionSizeB_2, &pulIndex ))
                    {
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Get Partition Info from Secondary GPT for Image GUID_B failed \n\r");
                        eStatus = SAIL_UPDATER_STATUS_FAIL;
                        goto ProcessBootInfoEnd;
                    }
                }
                else
                {
                    partitionAddrA_2 = partitionSizeA_2 = partitionAddrB_2 = partitionSizeB_2 = 0;

                }

                /* Get partition size of A and B from boot GPT ID and Check if the entries are matching from other GPT ID */
                if (SAIL_UPD_GPT_ID_PRIMARY == bootGPTID)
                {
                    pImgEntry->partitionSizeA = partitionSizeA_1;
                    pImgEntry->partitionSizeB = partitionSizeB_1;
                }
                else if (SAIL_UPD_GPT_ID_SECONDARY == bootGPTID)
                {
                    pImgEntry->partitionSizeA = partitionSizeA_2;
                    pImgEntry->partitionSizeB = partitionSizeB_2;

                }
                else
                {
                    // already handled. nothing to do here
                }

                if( (partitionAddrA_1 != partitionAddrA_2) || (partitionAddrB_1 != partitionAddrB_2)
                     || (partitionSizeA_1 != partitionSizeA_2) || (partitionSizeB_1 != partitionSizeB_2) )
                {
                    pImgEntry->isTwoGptTableEntriesMatching = 0; // 0 is not matching

                }
                else
                {
                    pImgEntry->isTwoGptTableEntriesMatching = 1; // 1 is matching
                }

                break;
            }
        }

        /* If the Image is not found in the boot Info list, then flag an error */
        if (j == ARRAY_LENGTH(xBootInfo))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Image not found in the boot info list \n\r");
            eStatus = SAIL_UPDATER_STATUS_FAIL;
            goto ProcessBootInfoEnd;
        }

        pImgEntry++;
    }

    /* Populate the Response for the GPT Health of both headers */

    /* Primary GPT */
    pRspMsg->bootInfo.primaryGptEntryCrcStatus = xPrimaryGPTparam.EntryCrcStatus;
    pRspMsg->bootInfo.primaryGptHeaderCrcStatus = xPrimaryGPTparam.HeaderCrcStatus;
    pRspMsg->bootInfo.primaryGptSize = xPrimaryGPTparam.GptSize;

    /* Secondary GPT */
    pRspMsg->bootInfo.secondaryGptEntryCrcStatus = xSecondaryGPTparam.EntryCrcStatus;
    pRspMsg->bootInfo.secondaryGptHeaderCrcStatus = xSecondaryGPTparam.HeaderCrcStatus;
    pRspMsg->bootInfo.secondaryGptSize = xSecondaryGPTparam.GptSize;

    /* Copy the number of images from Req to Resp Msg */
    pRspMsg->bootInfo.imgInfo.num_images = pReqMsg->bootInfo.imgInfo.num_images;

    /* Copy Buffer Address and Length from the request into the response header */
    pRspMsg->bootInfo.imgInfo.bufAddr = pReqMsg->bootInfo.imgInfo.bufAddr;
    pRspMsg->bootInfo.imgInfo.bufLen = (pRspMsg->bootInfo.imgInfo.num_images * sizeof(sailUpdaterImageEntryType));

    /* Calculate Buffer CRC */
    pRspMsg->bootInfo.imgInfo.bufCrc = 0;
    pRspMsg->bootInfo.imgInfo.bufCrc = ulSAILUpdaterCoreCalcCRC(bufAddrToUse, pRspMsg->bootInfo.imgInfo.bufLen);

    /* Flush and Invalidate the cache */
    clean_invalidate_cache_by_range((uint32) bufAddrToUse,(uint32)bufAddrToUse +  pRspMsg->bootInfo.imgInfo.bufLen);

    pRspMsg->status = SAIL_UPDATER_STATUS_SUCCESS;

ProcessBootInfoEnd:
    if (g_SAILUpdaterEL2CoreCtx.norHandle != NULL)
    {
        /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl2Close ( g_SAILUpdaterEL2CoreCtx.norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Spinor Close failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        }
        g_SAILUpdaterEL2CoreCtx.norHandle = NULL;
    }
    pImgEntry = NULL;
    return eStatus;
}
#endif

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
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessBootImg(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;
    uint32_t byte_offset,byte_count;
    uint32_t bootPartition, bootGptId;
    uint32_t temp_crc=0;
    uint32_t pulIndex=0;
    size_t sizeret;
    char imgGuid[GUID_STRING_SIZE+1] = "";      // dummy GUID
    guid_t tmpGuid = {0};
    gptHeader_t xGPTHdr = {0};
    sailUpdaterCoreVerifyGPTtype chkGPTparam = {0};
    uint32_t bufAddrToUse = pReqMsg->bootImg.bufAddr - SAIL_MD_DDR_ADDR_OFFSET;

    pRspMsg->msgId = SAIL_UPD_MSG_ID_BOOT_IMAGE;

    /* Initalize SPINOR handle */
    g_SAILUpdaterEL2CoreCtx.norHandle = NULL;
    if(SPINOR_DEVICE_DONE != spinorEl2Open ( &g_SAILUpdaterEL2CoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessBootImg: Spinor Open failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessBootImgEnd;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl2GetMemInfo(g_SAILUpdaterEL2CoreCtx.norHandle, &g_SAILUpdaterEL2CoreCtx.memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessBootImg: Spinor Get Mem Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessBootImgEnd;
    }

    sizeret = sailbsp_memscpy((void *)pRspMsg->bootImg.imgName, SAIL_UPD_IMG_NAME_LEN, (void *) pReqMsg->bootImg.imgName, SAIL_UPD_IMG_NAME_LEN);
    if(sizeret == 0)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessBootImg: Failed to copy image name from request to response msg \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessBootImgEnd;
    }

    pRspMsg->bootImg.bootPartition = pReqMsg->bootImg.bootPartition;
    pRspMsg->bootImg.bootGptId = pReqMsg->bootImg.bootGptId;

    /* Validate the Image */
    if (FALSE == bPrvSAILUpdaterCoreIsValidImg(UPDATER_BOOT_OPERATION, (const char*)&pReqMsg->bootImg.imgName))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessBootImg: Invalid Image name \n\r");
        eStatus = SAIL_UPDATER_INVALID_IMG_NAME;
        goto ProcessBootImgEnd;
    }

    /* Invalid Partition ID */
    if (pReqMsg->bootImg.bootPartition >= SAIL_UPD_PARTITION_ID_MAX)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessBootImg: Invalid Partition ID \n\r");
        eStatus = SAIL_UPDATER_INVALID_PARTITION_ID;
        goto ProcessBootImgEnd;
    }

    /* Invalid GPT ID */
    if (pReqMsg->bootImg.bootGptId >= SAIL_UPD_GPT_ID_MAX)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessBootImg: Invalid GPT ID \n\r");
        eStatus = SAIL_UPDATER_INVALID_GPT_ID;
        goto ProcessBootImgEnd;
    }

    /* UnAligned Buffer size */
    if (pReqMsg->bootImg.bufLen % SPINOR_BYTES_ALIGNMENT)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessBootImg: Invalid Buffer Size \n\r");
        eStatus = SAIL_UPDATER_UNALIGNED_BUF_SIZE;
        goto ProcessBootImgEnd;
    }

    /* Invalid Buffer Address */
    if ((0U == pReqMsg->bootImg.bufAddr) || (0U == bufAddrToUse) ||
        (FALSE == bPrvSAILUpdaterCoreIsAddrInRange(bufAddrToUse, pReqMsg->bootImg.bufLen))
       )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessBootImg: Invalid Buffer Address \n\r");
        eStatus = SAIL_UPDATER_INVALID_BUF_ADDR;
        goto ProcessBootImgEnd;
    }

    if( SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(pReqMsg->bootImg.bootGptId, &xGPTHdr, &chkGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessBootImg: GPT header read Failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessBootImgEnd;
    }

    if( (0 == chkGPTparam.HeaderCrcStatus) || (0 == chkGPTparam.EntryCrcStatus) )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessBootImg: GPT header Invalid \n\r");
        eStatus = SAIL_UPDATER_GPT_INVALID;
        goto ProcessBootImgEnd;
    }

    bootPartition = (pReqMsg->bootImg.bootPartition == SAIL_UPD_PARTITION_ID_PRIMARY)?XBL_PARTITION_A:XBL_PARTITION_B;
    bootGptId = (pReqMsg->bootImg.bootGptId == SAIL_UPD_GPT_ID_PRIMARY)?XBL_GPT_TABLE_PRIMARY:XBL_GPT_TABLE_SECONDARY;

    /* Get the GUID for the Image */
    if(sailhyp_xbl_getImgGUID((const char *)&pReqMsg->bootImg.imgName, bootPartition, bootGptId, imgGuid))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessBootImg: Get Image GUID failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessBootImgEnd;
    }

    if(FALSE == gptDecodeGUIDString ( imgGuid, &tmpGuid))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessBootImg: Converting GUID String to GUID for Image GUID failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessBootImgEnd;
    }

    if(FALSE == bPrvSAILUpdaterGPTGetPartitionInfo (&xGPTHdr, &tmpGuid, &byte_offset, &byte_count, &pulIndex ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessBootImg: Get Partition Info failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessBootImgEnd;
    }

    /* Invalid Buffer Size if Size of image is more than partition size */
    if (byte_count < pReqMsg->bootImg.bufLen)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessBootImg: Invalid Buffer Size 0x%x\n\r",pReqMsg->bootImg.bufLen);
        eStatus = SAIL_UPDATER_INVALID_BUF_SIZE;
        goto ProcessBootImgEnd;
    }

    if (0 == pReqMsg->bootImg.bufLen)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessBootImg: Invalid Buffer Size 0x%x\n\r",pReqMsg->bootImg.bufLen);
        eStatus = SAIL_UPDATER_INVALID_BUF_SIZE;
        goto ProcessBootImgEnd;
    }

    /* Copy the current CRC and Calculate Buffer CRC */
    temp_crc = pReqMsg->bootImg.bufCrc;
    pReqMsg->bootImg.bufCrc = 0;
    pReqMsg->bootImg.bufCrc = ulSAILUpdaterCoreCalcCRC(bufAddrToUse, pReqMsg->bootImg.bufLen);

    /* Verify Buffer CRC */
    if (TRUE == bPrvSAILUpdaterCoreIsCRCNotMatch(temp_crc, pReqMsg->bootImg.bufCrc))
    {
        eStatus = SAIL_UPDATER_INVALID_BUF_CRC;
        goto ProcessBootImgEnd;
    }

    if (XBL_SUCCESS != sailhyp_xbl_update_storage( XBL_STORAGE_DDR, bufAddrToUse, pReqMsg->bootImg.bufLen))
    {
		DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessBootImg: Error in sailhyp_xbl_update_storage \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessBootImgEnd;
    }

    /* Copy Buffer Address and Length from the request into the response header */
    pRspMsg->bootImg.bufAddr = pReqMsg->bootImg.bufAddr;
    pRspMsg->bootImg.bufLen = pReqMsg->bootImg.bufLen;
    pRspMsg->bootImg.bufCrc =  pReqMsg->bootImg.bufCrc;

    pRspMsg->status = SAIL_UPDATER_STATUS_SUCCESS;

ProcessBootImgEnd:
    if (g_SAILUpdaterEL2CoreCtx.norHandle != NULL)
    {
        /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl2Close ( g_SAILUpdaterEL2CoreCtx.norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessBootImg: Spinor Close failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        }
        g_SAILUpdaterEL2CoreCtx.norHandle = NULL;
    }
    return eStatus;
}

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
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessBootContinue(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;

    pRspMsg->msgId = SAIL_UPD_MSG_ID_BOOT_CONTINUE;

    pRspMsg->status = SAIL_UPDATER_STATUS_SUCCESS;

ProcessBootContEnd:
    return eStatus;
}

/**********************************************************
 * Determines if the swap of the partition offsets from Secondary GPT is needed
 * for the primary GPT fixing based on last OTA state and GuidMap
 *
 * @param xOtaStatus [IN]
 *   OTA State
 *
 * @param guidMap [IN]
 *   GUID Mapping
 *
 * @return boolean [OUT]
 *   Status of the operation
 **********************************************************/
static boolean bPrvIsFixPrimGptPartitionSwapNeeded(SAILUpdaterOTAStateValType xOtaStatus, uint8_t guidMap)
{
    boolean swapNeeded = FALSE;

    switch (xOtaStatus)
    {
        case OTA_UPDATE_START:
            swapNeeded = (guidMap == 0)?TRUE:FALSE;
            break;
        case OTA_DISABLED:
        case OTA_IN_PROGRESS:
        case OTA_BOOTING:
        case OTA_ROLLBACK:
        case OTA_DONE:
        case OTA_REBOOT_CORRUPTED:
            swapNeeded = (guidMap == 0)?FALSE:TRUE;
            break;
        case OTA_INVALID:
        default:
            swapNeeded = FALSE;
            break;
    }
    return swapNeeded;
}

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
SAILUpdaterStatusType_e xSAILUpdaterCoreFixCorruptPrimaryGPT(void *norHandle, SAILUpdaterOTAStateValType xOtaStatus, uint8_t guidMap)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;
    boolean isPartitionOffsetSwapNeeded = FALSE;

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if (SAIL_OTA_TRIG_ERROR_PRE_FIXGPTCORRUPTION_XBL == g_SAILUpdaterEL2CoreCtx.testcmdID)
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Forced crash due to trigger SAIL_OTA_TRIG_ERROR_PRE_FIXGPTCORRUPTION_XBL \n\r", __func__);
        err_fatal(SAIL_UPDATER,ERR_FATAL_FORCED_REBOOT);
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    isPartitionOffsetSwapNeeded = bPrvIsFixPrimGptPartitionSwapNeeded(xOtaStatus,guidMap);

    if(SAIL_UPDATER_SUCCESS != xSAILUpdaterCoreReconstructAltGPT(norHandle, SAIL_UPD_GPT_ID_SECONDARY, isPartitionOffsetSwapNeeded))
    {
          DEBUG_LOG(SAIL_ERROR,"%s: Fixing Primary GPT Corruption failed \n\r", __func__);
          eStatus = SAIL_UPDATER_STATUS_FAIL;
          goto FixCorruptPrimaryGPTEnd;
    }

    if (TRUE == g_SAILUpdaterEL2CoreCtx.fixGptRebootEn)
    {
        /*Force crash anytime the primary GPT is fixed */
        DEBUG_LOG(SAIL_ERROR, "%s Forced reboot after Fixing GPT \n\r", __func__);
        err_fatal(SAIL_UPDATER, ERR_FATAL_FORCED_REBOOT);
    }

FixCorruptPrimaryGPTEnd:
    return eStatus;
}

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

SAILUpdaterStatusType_e xSAILUpdaterCoreRollbackPrimaryGPT(void *norHandle, SAILUpdaterOTAStateValType xOtaStatus, uint8_t guidMap)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;
    sailUpdaterCoreVerifyGPTtype xGPTparam ={0};
    gptHeader_t xGPTHdr={0};
    boolean isPartitionOffsetSwapNeeded = FALSE;

    /* If the logicalA->PhysicalA currently, then swap is needed while copying the GPT entries from Secondary Partition */
    if (guidMap == 0)
    {
        isPartitionOffsetSwapNeeded = TRUE;
    }
    else
    {
        isPartitionOffsetSwapNeeded = FALSE;
    }

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if (SAIL_OTA_TRIG_ERROR_PRE_GPT_ROLLBACK == g_SAILUpdaterEL2CoreCtx.testcmdID)
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Forced crash due to trigger SAIL_OTA_TRIG_ERROR_PRE_GPT_ROLLBACK \n\r", __func__);
        err_fatal(SAIL_UPDATER,ERR_FATAL_FORCED_REBOOT);
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    if(SAIL_UPDATER_SUCCESS != xSAILUpdaterCoreReconstructAltGPT(norHandle, SAIL_UPD_GPT_ID_SECONDARY, isPartitionOffsetSwapNeeded))
    {
          DEBUG_LOG(SAIL_ERROR,"%s: Rollingback Primary GPT failed \n\r", __func__);
          eStatus = SAIL_UPDATER_STATUS_FAIL;
          goto FixCorruptPrimaryGPTEnd;
    }

FixCorruptPrimaryGPTEnd:
    return eStatus;
}
