
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
#include "sail_updater_otabookkeep.h"
#include "autosar_crc.h"
#include "sailel1_xbl_api.h"
#include "cache_ops.h"
#include "debug_log.h"
#include "common_functions.h"

#include "spinor_el1_api.h"
#include "gpt_partition1.h"
#include "syscall_pub.h"
#include "syscall_hvc.h"
#include "libfdt.h"
#include "fdt_utils.h"
#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
#include "err_fatal.h"
#endif

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
    boolean eraseBookBeforeWrite;   /** Device tree value for Erase bookkeeping before Write enable/disable */
    uint32_t testcmdID;             /** Test cmd ID */
}sailUpdaterCoreCtx_t;

/* SAIL Updater List of Flashable Images */
static const char* cSAILUpdaterFlashImglist[]=
{
    "SAIL_HYP",
    "SAIL_SW1",
    "SAIL_SW2",
    "SAIL_SW3",
    "SAIL_SW4"
};

/* SAIL Updater List of Bootable Images */
static const char* cSAILUpdaterBootImglist[]=
{
    "SAIL_SW1",
};

/* SAIL Updater Workbuffer */
static uint8_t gSAILUpdatergptWorkBuf[SAILUPDATER_GPT_WORK_BUF_SIZE] __attribute__ ((aligned(EL_SHARED_CACHELINE_SIZE))); /* align to cache line in case doing cache invalidation only */

/* SAIL Updater Core Context */
sailUpdaterCoreCtx_t g_SAILUpdaterCoreCtx = {0};

/* SAIL Updater Flags for debug */
static volatile boolean bSAILUpdaterCoreSkipInCRCCheck = FALSE;
static volatile boolean bSAILUpdaterCoreSkipAddrCheck = FALSE;

/* Read Image to work buffer in Loop and calculate Cumulative CRC */
static SAILUpdaterStatusType_e ulSAILUpdaterCoreImgBufCumCrc(uint32_t bufLen,uint32_t primbyte_offset, uint32_t *cumCrc);

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

static uint32_t ulPrvSAILUpdatergptReadCb (uint8_t *pBuf, uint32_t ulStartByte, uint32_t ulSize)
{
    SPINOR_STATUS ret = spinorEl1Read ( g_SAILUpdaterCoreCtx.norHandle, ulStartByte, ulSize, pBuf );
    if ( ret == SPINOR_DEVICE_DONE )
    {
        return ulSize;
    }
    else
    {
        return 0;
    }
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

    pEntry  = (gptEntry_t *)g_SAILUpdaterCoreCtx.pGPTWorkBuf;

    for ( i = 0; i < pGptHdr->number_of_partition_entries; i++ )
    {
        if (ulEntrySz != g_SAILUpdaterCoreCtx.gptReadCb(g_SAILUpdaterCoreCtx.pGPTWorkBuf, (ulBase + i * ulEntrySz), ulEntrySz))
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
        if (ulEntrySz != g_SAILUpdaterCoreCtx.gptReadCb(g_SAILUpdaterCoreCtx.pGPTWorkBuf, (ulBase + i * ulEntrySz), ulReadSz))
        {
            return SAIL_UPDATER_FAIL;
        }

        result = sailbsp_memscpy(bufAddr, ulEntrySz, g_SAILUpdaterCoreCtx.pGPTWorkBuf, ulEntrySz);
        if(result == 0)
        {
            return SAIL_UPDATER_FAIL;
        }

        bufAddr += ulEntrySz;
    }

    return SAIL_UPDATER_SUCCESS;
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
static SAILUpdaterCoreStatusType_e ePrvSAILUpdaterGetGPTHdr(uint32_t gpt_id,gptHeader_t *pGPTHdr)
{
    uint32_t startAddr,sz;
    size_t result;

    startAddr = (SAIL_UPD_GPT_ID_PRIMARY == gpt_id) ? NOR_LBA_SZ : (SAIL_UPD_GPT_ID_SECONDARY == gpt_id) ? (g_SAILUpdaterCoreCtx.memInfo.block_count - 1) * NOR_LBA_SZ : 0;

    if (0 == startAddr)
    {
        return SAIL_UPDATER_FAIL;
    }

    sz = (sizeof(gptHeader_t) % SPINOR_BYTES_ALIGNMENT) ? sizeof(gptHeader_t) + SPINOR_BYTES_ALIGNMENT - (sizeof(gptHeader_t) % SPINOR_BYTES_ALIGNMENT) : sizeof(gptHeader_t);

    if (sz != g_SAILUpdaterCoreCtx.gptReadCb(g_SAILUpdaterCoreCtx.pGPTWorkBuf, startAddr, sz))
    {
        return SAIL_UPDATER_FAIL;
    }

    result = sailbsp_memscpy(pGPTHdr, sizeof(gptHeader_t), g_SAILUpdaterCoreCtx.pGPTWorkBuf, sizeof(gptHeader_t));
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
    if (FALSE == gptVerifyPartitionEntryCRC32(pGPTHdr, g_SAILUpdaterCoreCtx.pGPTWorkBuf, g_SAILUpdaterCoreCtx.gptReadCb, NOR_LBA_SZ, GPT_CRC32_SEED_DEFAULT))
    {
        chkGPTparam->EntryCrcStatus = 0;
        chkGPTparam->GptSize = 0;
        return SAIL_UPDATER_SUCCESS;
    }
    else
    {
        chkGPTparam->EntryCrcStatus = 1;
    }

    hdrSz = sizeof(gptHeader_t);
    partEntriesSz = gptGetPartitionEntrySize(pGPTHdr) * gptGetNumOfPartitionEntrys(pGPTHdr);

   // chkGPTparam->GptSize = hdrSz + partEntriesSz;
     chkGPTparam->GptSize = 128 + partEntriesSz;
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
        for (int i = 0; i < ARRAY_LENGTH(cSAILUpdaterFlashImglist); i++)
        {
            if (strlen(imgName) != strlen(cSAILUpdaterFlashImglist[i]) )
            {
                continue;
            }
            if (0 == strncmp(cSAILUpdaterFlashImglist[i], imgName, strlen(cSAILUpdaterFlashImglist[i])))
            {
                return TRUE;
            }
        }
        return FALSE;
    }
    else if (UPDATER_BOOT_OPERATION == oper)
    {
        for (int i = 0; i < ARRAY_LENGTH(cSAILUpdaterBootImglist); i++)
        {
            if (strlen(imgName) != strlen(cSAILUpdaterBootImglist[i]) )
            {
                continue;
            }
            if (0 == strncmp(cSAILUpdaterBootImglist[i], imgName, strlen(cSAILUpdaterBootImglist[i])))
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
 * Read Device tree entry for sail_updater book keeping
 *
 *
 * @return SAILUpdaterCoreStatusType_e [OUT]
 *   Status of the Initalization
 *
 **********************************************************/
static SAILUpdaterCoreStatusType_e  xSAILUpdaterReadDtbUpdateBookkeep (void)
{
    SAILUpdaterCoreStatusType_e eStatus = SAIL_UPDATER_SUCCESS;
    int retval;
    void *pDTB = NULL;
    int32_t root_offset = 0;
    uint32_t bookKeepEnable=0;
    uint32_t maxRetry = 0;
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
         retval |= fdt_getprop_u32(pDTB, root_offset, "eraseBookBeforeWrite", &eraseBookBeforeWrite);

         /* If no errors in the DTB configuration, configure and check for the GPIO value */
         if(0 != retval)
         {
             DEBUG_LOG(SAIL_ERROR,"sailhyp_readdtb_update_bookkeep: fdt read failed\n\r");
             eStatus = SAIL_UPDATER_FAIL;
                 goto readDtbEnd;
             }
             g_SAILUpdaterCoreCtx.bookKeepEnable = (bookKeepEnable==0)?FALSE:TRUE;
             g_SAILUpdaterCoreCtx.eraseBookBeforeWrite = (eraseBookBeforeWrite==0)?FALSE:TRUE;
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
    return g_SAILUpdaterCoreCtx.eraseBookBeforeWrite;
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
   g_SAILUpdaterCoreCtx.norHandle = NULL;
   if(SPINOR_DEVICE_DONE != spinorEl1Open ( &g_SAILUpdaterCoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
   {
       DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreInit: Spinor Open failed \n\r");
       eStatus = SAIL_UPDATER_FAIL;
       goto updaterCoreInitEnd;
   }

   /* Get SPINOR memory Info */
   if (SPINOR_DEVICE_DONE != spinorEl1GetMemInfo(g_SAILUpdaterCoreCtx.norHandle, &g_SAILUpdaterCoreCtx.memInfo))
   {
       DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreInit: Spinor Get Mem Info failed \n\r");
       eStatus = SAIL_UPDATER_FAIL;
       goto updaterCoreInitEnd;
   }

   DEBUG_LOG(SAIL_INFO,"xSAILUpdaterCoreInit: SAILUpdater Core Init done\n\r");

   g_SAILUpdaterCoreCtx.pGPTWorkBuf = gSAILUpdatergptWorkBuf;
   g_SAILUpdaterCoreCtx.gptReadCb = ulPrvSAILUpdatergptReadCb;

   if( SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterGetGPTHdr(SAIL_UPD_GPT_ID_PRIMARY, &g_SAILUpdaterCoreCtx.PrimaryGPTHdr))
   {
       DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreInit: Read Primary GPT header failed \n\r");
       eStatus = SAIL_UPDATER_FAIL;
       goto updaterCoreInitEnd;
   }

   if( SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterGetGPTHdr(SAIL_UPD_GPT_ID_SECONDARY, &g_SAILUpdaterCoreCtx.SecondaryGPTHdr))
   {
       DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreInit: Read GPT Secondary GPT header failed \n\r");
       eStatus = SAIL_UPDATER_FAIL;
       goto updaterCoreInitEnd;
   }

   DEBUG_LOG(SAIL_WARNING, "xSAILUpdaterCoreInit: Primary GPT headerCRC = 0x%x partitionCRC = 0x%x num_partitions=0x%x \n\r", g_SAILUpdaterCoreCtx.PrimaryGPTHdr.header_crc32, g_SAILUpdaterCoreCtx.PrimaryGPTHdr.partition_entries_crc32, g_SAILUpdaterCoreCtx.PrimaryGPTHdr.number_of_partition_entries);
   DEBUG_LOG(SAIL_WARNING, "xSAILUpdaterCoreInit: Secondary GPT headerCRC = 0x%x partitionCRC = 0x%x  num_partitions=0x%x \n\r", g_SAILUpdaterCoreCtx.SecondaryGPTHdr.header_crc32, g_SAILUpdaterCoreCtx.SecondaryGPTHdr.partition_entries_crc32, g_SAILUpdaterCoreCtx.SecondaryGPTHdr.number_of_partition_entries);

updaterCoreInitEnd:
   if (g_SAILUpdaterCoreCtx.norHandle != NULL)
   {
       /* Close SPINOR handle */
       if(SPINOR_DEVICE_DONE != spinorEl1Close ( g_SAILUpdaterCoreCtx.norHandle ))
       {
           DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreInit: Spinor Close failed \n\r");
           eStatus = SAIL_UPDATER_FAIL;
       }
       g_SAILUpdaterCoreCtx.norHandle = NULL;
   }
   return eStatus;
}

/**********************************************************
 * De-Initialize the resources and contexts used by the SAIL Updater
 *
 *
 * @param void [IN]
 *   None
 *
 * @return SAILUpdaterCoreStatusType_e [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SAILUpdaterCoreStatusType_e xSAILUpdaterCoreDeInit(void)
{
    SAILUpdaterCoreStatusType_e eStatus = SAIL_UPDATER_SUCCESS;
    if (g_SAILUpdaterCoreCtx.norHandle != NULL)
    {
        /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl1Close ( g_SAILUpdaterCoreCtx.norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreDeInit: Spinor Open failed \n\r");
            eStatus = SAIL_UPDATER_FAIL;
        }
        g_SAILUpdaterCoreCtx.norHandle = NULL;
    }

    /*memset the core context*/
    memset(&g_SAILUpdaterCoreCtx,0,sizeof(sailUpdaterCoreCtx_t));

    return eStatus;
}
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
uint32_t ulSAILUpdaterCoreCalcCumulativeCRC(uint32_t addr, uint32_t len, bool lastIteration, uint32_t calcCrc)
{
    uint32_t testBufAddr=0;
    uint32_t testBufLen = 0;
    uint32_t sz=1, crc=0;

    testBufAddr = addr;
    testBufLen = len;
    sz = 1;

    crc = ulAutosarCumulativeCrcBufList(AUTOSAR_CRC_32BIT_ETHERNET, &testBufAddr, &testBufLen, sz,lastIteration, calcCrc);
    return crc;
}

/**********************************************************
 * Read Image to work buffer in Loop and calculate Cumulative CRC
 *
 *
 * @param bufLen [IN]
 *   Image Buffer Length
 *
 * @param primbyte_offset [IN]
 *   byte Offset to read
 *
 * @param pointer to cumCrc [IN]
 *   bcalculated cumulative CRC will be passed back to caller
 *
 *
 * @return uint32_t [OUT]
 *   Resulting CRC value.
 *
 **********************************************************/
static SAILUpdaterStatusType_e ulSAILUpdaterCoreImgBufCumCrc(uint32_t bufLen,uint32_t primbyte_offset, uint32_t *cumCrc)
{
     bool lastIter=FALSE;
     uint32_t calcCumCRC=0xFFFFFFFF;
     uint32_t bytesRead=0,numLoop=0,remainderBytes=0;
     SPINOR_STATUS result;
     SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;

     /* Read from the partition again to verify the CRC */
     numLoop = bufLen/SAILUPDATER_GPT_WORK_BUF_SIZE;
     remainderBytes = bufLen%SAILUPDATER_GPT_WORK_BUF_SIZE;

     for(uint32_t loop = 0; loop < numLoop; loop++)
     {
         result = spinorEl1Read ( g_SAILUpdaterCoreCtx.norHandle, primbyte_offset, SAILUPDATER_GPT_WORK_BUF_SIZE, (void *)g_SAILUpdaterCoreCtx.pGPTWorkBuf);
         if( result != SPINOR_DEVICE_DONE )
         {
              DEBUG_LOG(SAIL_ERROR,"ulSAILUpdaterCoreImgBufCumCrc: Read Partition failed \n\r");
              eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
              calcCumCRC =0;
              goto ProcessCoreImgBufCumCrcEnd;
         }
         bytesRead += SAILUPDATER_GPT_WORK_BUF_SIZE;
         primbyte_offset += SAILUPDATER_GPT_WORK_BUF_SIZE;

         /*Last read is done go for Cumulative CRC Calculation*/
         if((bytesRead == numLoop*SAILUPDATER_GPT_WORK_BUF_SIZE) && (remainderBytes == 0))
         {
             lastIter = TRUE;
         }
         /* Calculate cumulative Buffer CRC */
         calcCumCRC = ulSAILUpdaterCoreCalcCumulativeCRC((uint32_t)g_SAILUpdaterCoreCtx.pGPTWorkBuf, SAILUPDATER_GPT_WORK_BUF_SIZE, lastIter, calcCumCRC);
     }
     /*If Remainder bytes are there to be read, set the last Iteration, read and acalculate CRC*/
     if (remainderBytes != 0)
     {
         result = spinorEl1Read ( g_SAILUpdaterCoreCtx.norHandle, primbyte_offset, remainderBytes, (void *)g_SAILUpdaterCoreCtx.pGPTWorkBuf);
         if( result != SPINOR_DEVICE_DONE )
         {
             DEBUG_LOG(SAIL_ERROR,"ulSAILUpdaterCoreImgBufCumCrc: Read Partition failed \n\r");
             eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
             calcCumCRC = 0;
             goto ProcessCoreImgBufCumCrcEnd;
         }
         lastIter = TRUE;
          /* Calculate Buffer CRC */
         calcCumCRC = ulSAILUpdaterCoreCalcCumulativeCRC((uint32_t)g_SAILUpdaterCoreCtx.pGPTWorkBuf, remainderBytes, lastIter, calcCumCRC);
         DEBUG_LOG(SAIL_DEBUG,"ulSAILUpdaterCoreImgBufCumCrc: Remainder Cumulative CRC value in Loop: 0x%x, lastIteration: %d\n\r",calcCumCRC,lastIter);
     }
  ProcessCoreImgBufCumCrcEnd:
     *cumCrc = calcCumCRC;
     return eStatus;
}

/**********************************************************
 * SAIL Updater Check Boot Partition
 *
 *  If Boot partitions are matching, Then update OTA state as DISABLED else write IN_PROGRESS
 *
 **********************************************************/
SAILUpdaterStatusType_e xSAILUpdaterCheckbootPartition(void)
{
    SPINOR_STATUS result;
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;
    uint32_t readPartition, readGptId = 0;
    uint32_t byte_offset,byte_count,blockSize;
    size_t sizeret;
    uint8_t  imgName[SAIL_UPD_IMG_NAME_LEN];      /* including NULL termination */
    char imgGuid[GUID_STRING_SIZE+1] = "";      // dummy GUID
    gptHeader_t xGPTHdr = {0};
    uint32_t primBufCrc=0, bufCrcCompare=0;
    sailUpdaterCoreVerifyGPTtype xPrimaryGPTparam={0}, xSecondaryGPTparam ={0};

    /* Initalize SPINOR handle */
    g_SAILUpdaterCoreCtx.norHandle = NULL;
    if(SPINOR_DEVICE_DONE != spinorEl1Open ( &g_SAILUpdaterCoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCheckbootPartition: Spinor Open failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto UpdaterCheckBootPartititon;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl1GetMemInfo(g_SAILUpdaterCoreCtx.norHandle, &g_SAILUpdaterCoreCtx.memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCheckbootPartition: Spinor Get Mem Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto UpdaterCheckBootPartititon;
    }

    blockSize  = g_SAILUpdaterCoreCtx.memInfo.pages_per_block * g_SAILUpdaterCoreCtx.memInfo.page_size_bytes;

    /* Validate the Image and then compare the CRC for the primary and Backup partitions for each image */
    for(int imageId = 0; imageId < ARRAY_LENGTH(cSAILUpdaterFlashImglist) ; imageId++)
    {
        /*Copy image name*/
        sizeret = sailbsp_memscpy((void *)imgName, SAIL_UPD_IMG_NAME_LEN, (void *) cSAILUpdaterFlashImglist[imageId], SAIL_UPD_IMG_NAME_LEN);
        if(sizeret == 0)
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCheckbootPartition: Failed to copy image name from request to response msg \n\r");
            eStatus = SAIL_UPDATER_STATUS_FAIL;
            goto UpdaterCheckBootPartititon;
        }

        /*Calculate the CRC for the primary and Backup partitions for each image*/
        primBufCrc =0;
        for(readPartition = XBL_PARTITION_A; readPartition <= XBL_PARTITION_B; readPartition++)
        {
            bufCrcCompare = 0;

            /* Get the GUID for the Image */
            if(sailEl1XblGetImgGUID((const char *)imgName, readPartition, SAIL_UPD_GPT_ID_PRIMARY, imgGuid))
            {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCheckbootPartition: Get Image GUID failed \n\r");
            eStatus = SAIL_UPDATER_STATUS_FAIL;
            goto UpdaterCheckBootPartititon;
            }

            /* Get partition Info */
            result = spinorEl1GetGptPartitionInfo(g_SAILUpdaterCoreCtx.norHandle, (const char*)imgGuid, &byte_offset, &byte_count);
            if( result != SPINOR_DEVICE_DONE )
            {
                DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCheckbootPartition: Get Partition Info failed \n\r");
                eStatus = SAIL_UPDATER_STATUS_FAIL;
                goto UpdaterCheckBootPartititon;
            }

            /*Calculate Cumulative Buffer CRC of the Image in Primary partition*/
            result = ulSAILUpdaterCoreImgBufCumCrc(byte_count,byte_offset, &bufCrcCompare);
            if(result != SAIL_UPDATER_STATUS_SUCCESS)
            {
                 DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCheckbootPartition: ulSAILUpdaterCoreImgBufCumCrc failed \n\r");
                 eStatus = SAIL_UPDATER_STATUS_FAIL;
                 goto UpdaterCheckBootPartititon;
            }
            if (readPartition == XBL_PARTITION_A)
            {
                primBufCrc = bufCrcCompare;
            }
        }

        /*compare the CRC for the primary and Backup partitions for each image
          If CRC of doesn't match for atleast one image then SET the OTA state to OTA_IN_PROGRESS*/
        if (primBufCrc != bufCrcCompare)
        {
             DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterCheckbootPartition: Buffer CRC comparison for Prim-Sec partition not matching set OTA_DONE\n\r");

             /*Set OTA state to OTA_DONE */
             if(SAIL_UPDATER_STATUS_SUCCESS != xSAILUpdaterSetOtaStatus(g_SAILUpdaterCoreCtx.norHandle, OTA_DONE))
             {
                  DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCheckbootPartition: ulSAILUpdaterCoreOtaStatusWrite failed \n\r");
                  eStatus = SAIL_UPDATER_STATUS_FAIL;
                  goto UpdaterCheckBootPartititon;
             }
             goto UpdaterCheckBootPartititon;
        }
    }

    /* Get the status of the 2 GPTs */

    /* Check the GPT health of Primary GPT */
    if (SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(SAIL_UPD_GPT_ID_PRIMARY, &g_SAILUpdaterCoreCtx.PrimaryGPTHdr, &xPrimaryGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCheckbootPartition: Getting Primary GPT health failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto UpdaterCheckBootPartititon;
    }

    /* Check the GPT health of Secondary GPT */
    if (SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(SAIL_UPD_GPT_ID_SECONDARY, &g_SAILUpdaterCoreCtx.SecondaryGPTHdr, &xSecondaryGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCheckbootPartition: Getting Secondary GPT health failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto UpdaterCheckBootPartititon;
    }

        /* If both GPTs are valid, and Partition Entry CRCs match, then logicalA -> PhysicalA  else logicalA -> PhysicalB */
    if ((1 == xPrimaryGPTparam.EntryCrcStatus) && (1 == xPrimaryGPTparam.HeaderCrcStatus) &&
        (1 == xSecondaryGPTparam.EntryCrcStatus) && (1 == xSecondaryGPTparam.HeaderCrcStatus) &&
        (g_SAILUpdaterCoreCtx.PrimaryGPTHdr.partition_entries_crc32 == g_SAILUpdaterCoreCtx.SecondaryGPTHdr.partition_entries_crc32)
        )
    {
        /* If the partition entry CRCs match then set state to OTA_DISABLED */
        /*If CRC matches for All images, then SET the OTA state to OTA_DISABLED*/
        DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterCheckbootPartition: Buffer CRC comparison for Prim-Sec partition matching and partition entries match set OTA_DISABLED\n\r");

        /*Set OTA state to OTA_DISABLED*/
        if(SAIL_UPDATER_STATUS_SUCCESS != xSAILUpdaterSetOtaStatus(g_SAILUpdaterCoreCtx.norHandle, OTA_DISABLED))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCheckbootPartition: ulSAILUpdaterCoreOtaStatusWrite failed \n\r");
            eStatus = SAIL_UPDATER_STATUS_FAIL;
            goto UpdaterCheckBootPartititon;
        }
    }
    else
    {
        /*If CRC matches for All images, then SET the OTA state to OTA_DONE*/
        DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterCheckbootPartition: Buffer CRC comparison for Prim-Sec partition matching and partition entries does not match set OTA_DONE\n\r");

        /*Set OTA state to OTA_DISABLED*/
        if(SAIL_UPDATER_STATUS_SUCCESS != xSAILUpdaterSetOtaStatus(g_SAILUpdaterCoreCtx.norHandle, OTA_DONE))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCheckbootPartition: ulSAILUpdaterCoreOtaStatusWrite failed \n\r");
            eStatus = SAIL_UPDATER_STATUS_FAIL;
            goto UpdaterCheckBootPartititon;
        }
    }

UpdaterCheckBootPartititon:
    if (g_SAILUpdaterCoreCtx.norHandle != NULL)
    {
        /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl1Close ( g_SAILUpdaterCoreCtx.norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCheckbootPartition: Spinor Close failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        }
        g_SAILUpdaterCoreCtx.norHandle = NULL;
    }
    return eStatus;
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

    DEBUG_LOG(SAIL_WARNING, "%s: HELLO Request MSG params hello=%s mailboxVersionMajor=0x%x mailboxVersionMinor=0x%x \n\r",__func__, pReqMsg->hello.hello, pReqMsg->hello.mailboxVersionMajor, pReqMsg->hello.mailboxVersionMinor);

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

    DEBUG_LOG(SAIL_WARNING, "%s: HELLO Response MSG params hello=%s mailboxVersionMajor=0x%x mailboxVersionMinor=0x%x \n\r",__func__, pRspMsg->hello.hello, pRspMsg->hello.mailboxVersionMajor, pRspMsg->hello.mailboxVersionMinor);
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
    uint32_t byte_offset,primbyte_offset,byte_count,primbyte_count,block_size;
    uint32_t FlashPartition, FlashGptId;
    uint32_t temp_crc=0;
    uint32_t pulIndex=0;
    size_t sizeret;
    char imgGuid[GUID_STRING_SIZE+1] = "";      // dummy GUID
    guid_t tmpGuid = {0};
    gptHeader_t xGPTHdr = {0};
    sailUpdaterCoreVerifyGPTtype chkGPTparam = {0};
    uint32_t bufAddrToUse = pReqMsg->flashImg.bufAddr - SAIL_MD_DDR_ADDR_OFFSET;
    uint32_t bufCrcCompare=0;
    SAILUpdaterOTAStateValType xOtaStatus = OTA_INVALID ;
    uint8_t guidMap = 0;

    pRspMsg->msgId = SAIL_UPD_MSG_ID_FLASH_IMAGE;

    DEBUG_LOG(SAIL_WARNING, "%s: FLASH_IMAGE Request MSG params imgName=%s FlashPartition=0x%x FlashGptId=0x%x bufAddr=0x%x bufLen=0x%x bufCrc=0x%x\n\r",
              __func__, pReqMsg->flashImg.imgName, pReqMsg->flashImg.FlashPartition, pReqMsg->flashImg.FlashGptId,
              pReqMsg->flashImg.bufAddr, pReqMsg->flashImg.bufLen, pReqMsg->flashImg.bufCrc
              );

    /* Initalize SPINOR handle */
    g_SAILUpdaterCoreCtx.norHandle = NULL;
    if(SPINOR_DEVICE_DONE != spinorEl1Open ( &g_SAILUpdaterCoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: Spinor Open failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessFlashImgEnd;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl1GetMemInfo(g_SAILUpdaterCoreCtx.norHandle, &g_SAILUpdaterCoreCtx.memInfo))
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
        DEBUG_LOG(SAIL_ERROR, "xSAILUpdaterCoreProcessFlashImg: Invalid Partition ID 0x%x \n\r", pReqMsg->flashImg.ext_id.FlashPartition);
        eStatus = SAIL_UPDATER_INVALID_PARTITION_ID;
        goto ProcessFlashImgEnd;
    }

    if ((pReqMsg->flashImg.ext_id.flashtype > 2) || (0 != pReqMsg->flashImg.ext_id.reserved[0]) || (0 != pReqMsg->flashImg.ext_id.reserved[1]))
    {
        DEBUG_LOG(SAIL_ERROR, "xSAILUpdaterCoreProcessFlashImg: Invalid Flash Image extended ID 0x%x\n\r", pReqMsg->flashImg.FlashPartition);
        eStatus = SAIL_UPDATER_INVALID_PARTITION_ID;
        goto ProcessFlashImgEnd;
    }

    /*Get Ota Status*/
    if(SAIL_UPDATER_STATUS_SUCCESS != xSAILUpdaterGetOtaStatus(g_SAILUpdaterCoreCtx.norHandle, &xOtaStatus, &guidMap))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: xSAILUpdaterGetOtaStatus Failed \n\r");
        eStatus =  SAIL_UPDATER_STATUS_FAIL;
        goto ProcessFlashImgEnd;
    }

    if ((OTA_IN_PROGRESS == xOtaStatus) && (SAIL_UPD_PARTITION_ID_SECONDARY != pReqMsg->flashImg.ext_id.FlashPartition))
    {
        DEBUG_LOG(SAIL_ERROR, "xSAILUpdaterCoreProcessFlashImg: Flashing to PARTITION_ID_PRIMARY 0x%x not allowed when OTA state is in OTA_IN_PROGRESS \n\r", pReqMsg->flashImg.ext_id.FlashPartition);
        eStatus = SAIL_UPDATER_INVALID_PARTITION_ID;
        goto ProcessFlashImgEnd;
    }

    /* Invalid GPT ID */
    if (pReqMsg->flashImg.FlashGptId >= SAIL_UPD_GPT_ID_MAX)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: Invalid GPT ID 0x%x \n\r", pReqMsg->flashImg.FlashGptId);
        eStatus = SAIL_UPDATER_INVALID_GPT_ID;
        goto ProcessFlashImgEnd;
    }

    /* UnAligned Buffer size */
    if (pReqMsg->flashImg.bufLen % SPINOR_BYTES_ALIGNMENT)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: Unaligned buffer size 0x%x \n\r", pReqMsg->flashImg.bufLen);
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
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: GPT header read Failed GPT ID=0x%x\n\r", pReqMsg->flashImg.FlashGptId);
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessFlashImgEnd;
    }

    if( (0 == chkGPTparam.HeaderCrcStatus) || (0 == chkGPTparam.EntryCrcStatus) )
    {
        DEBUG_LOG(SAIL_ERROR, "xSAILUpdaterCoreProcessFlashImg: GPT header Invalid HeaderCRC=0x%x EntryCRC=0x%x HeaderCrcStatus=0x%x EntryCrcStatus=0x%x\n\r",
                  xGPTHdr.header_crc32, xGPTHdr.partition_entries_crc32,chkGPTparam.HeaderCrcStatus, chkGPTparam.EntryCrcStatus );
        eStatus = SAIL_UPDATER_GPT_INVALID;
        goto ProcessFlashImgEnd;
    }

    FlashPartition = (pReqMsg->flashImg.ext_id.FlashPartition == SAIL_UPD_PARTITION_ID_PRIMARY) ? XBL_PARTITION_A : XBL_PARTITION_B;
    FlashGptId = (pReqMsg->flashImg.FlashGptId == SAIL_UPD_GPT_ID_PRIMARY)?XBL_GPT_TABLE_PRIMARY:XBL_GPT_TABLE_SECONDARY;

    /* Get the GUID for the Image */
    if(sailEl1XblGetImgGUID((const char *)&pReqMsg->flashImg.imgName, FlashPartition, FlashGptId, imgGuid))
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

    if(FALSE == bPrvSAILUpdaterGPTGetPartitionInfo (&xGPTHdr, &tmpGuid, &byte_offset, &byte_count, &pulIndex ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: Get Partition Info failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessFlashImgEnd;
    }

    /* Invalid Buffer Size if Size of image is more than partition size */
    if (byte_count < pReqMsg->flashImg.bufLen)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: Invalid Buffer Size 0x%x\n\r",pReqMsg->flashImg.bufLen);
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
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: Invalid Buffer CRC \n\r");
        eStatus = SAIL_UPDATER_INVALID_BUF_CRC;
        goto ProcessFlashImgEnd;
    }

    block_size = g_SAILUpdaterCoreCtx.memInfo.pages_per_block * g_SAILUpdaterCoreCtx.memInfo.page_size_bytes;

    /*Read the Devicetree to check if book keep is enabled*/
    if(g_SAILUpdaterCoreCtx.bookKeepEnable)
    {
        /* If the flashtype is 0, change the state to OTA_IN_PROGRESS if the images in A and B does not match */
        if (pReqMsg->flashImg.ext_id.flashtype == 0)
        {
            // read other partition if B then read A partition info read
            if (pReqMsg->flashImg.FlashPartition == SAIL_UPD_PARTITION_ID_SECONDARY)
            {
                FlashPartition = XBL_PARTITION_A;
                DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: call Get Image GUID incase flash partition is secondary \n\r");

                /* Get the GUID for the Image */
                if(sailEl1XblGetImgGUID((const char *)&pReqMsg->flashImg.imgName, FlashPartition, FlashGptId, imgGuid))
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
                if(FALSE == bPrvSAILUpdaterGPTGetPartitionInfo (&xGPTHdr, &tmpGuid, &primbyte_offset, &primbyte_count, &pulIndex ))
                {
                    DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: Get Partition Info failed \n\r");
                    eStatus = SAIL_UPDATER_STATUS_FAIL;
                    goto ProcessFlashImgEnd;
                }

                /* Invalid Buffer Size if Size of image is more than partition size */
                if (primbyte_count < pReqMsg->flashImg.bufLen)
                {
                    DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: Invalid Buffer Size 0x%x\n\r",pReqMsg->flashImg.bufLen);
                    eStatus = SAIL_UPDATER_INVALID_BUF_SIZE;
                    goto ProcessFlashImgEnd;
                }

                /*Calculate Cumulative Buffer CRC of the Image in Primary partition*/
                result = ulSAILUpdaterCoreImgBufCumCrc(pReqMsg->flashImg.bufLen,primbyte_offset, &bufCrcCompare);
                if(result != SAIL_UPDATER_STATUS_SUCCESS)
                {
                     DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: ulSAILUpdaterCoreImgBufCumCrc failed \n\r");
                     eStatus = SAIL_UPDATER_STATUS_FAIL;
                     goto ProcessFlashImgEnd;
                }

                /* Compare CRC of Primary with CRC of Image to be flashed on Secondary, write in progress if not matching crc*/
                if (pReqMsg->flashImg.bufCrc != bufCrcCompare)
                {
#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
                    if (SAIL_OTA_TRIG_ERROR_PRE_INPROGRESS_FLASHIMG == g_SAILUpdaterCoreCtx.testcmdID)
                    {
                        DEBUG_LOG(SAIL_ERROR,"%s: Forced crash due to trigger SAIL_OTA_TRIG_ERROR_PRE_INPROGRESS_FLASHIMG \n\r", __func__);
                        err_fatal(SAIL_UPDATER,ERR_FATAL_FORCED_REBOOT);
                    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

                    DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: Buffer CRC comparison for Prim-Sec partition not matching set OTA_IN_PROGRESS\n\r");

                    if(SAIL_UPDATER_STATUS_SUCCESS != xSAILUpdaterSetOtaStatus(g_SAILUpdaterCoreCtx.norHandle, OTA_IN_PROGRESS))
                    {
                         DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: ulSAILUpdaterCoreOtaStatusWrite failed \n\r");
                         eStatus = SAIL_UPDATER_STATUS_FAIL;
                         goto ProcessFlashImgEnd;
                    }
                }
            }
        }
        else if (pReqMsg->flashImg.ext_id.flashtype == 2)
        {
#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
            if (SAIL_OTA_TRIG_ERROR_PRE_INPROGRESS_FLASHIMG == g_SAILUpdaterCoreCtx.testcmdID)
            {
                DEBUG_LOG(SAIL_ERROR,"%s: Forced crash due to trigger SAIL_OTA_TRIG_ERROR_PRE_INPROGRESS_FLASHIMG \n\r", __func__);
                err_fatal(SAIL_UPDATER,ERR_FATAL_FORCED_REBOOT);
            }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

            /* If the flashtype is 2, change the state to OTA_IN_PROGRESS */
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: Setting state to OTA_IN_PROGRESS\n\r");

            if(SAIL_UPDATER_STATUS_SUCCESS != xSAILUpdaterSetOtaStatus(g_SAILUpdaterCoreCtx.norHandle, OTA_IN_PROGRESS))
            {
                 DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: ulSAILUpdaterCoreOtaStatusWrite failed \n\r");
                 eStatus = SAIL_UPDATER_STATUS_FAIL;
                 goto ProcessFlashImgEnd;
            }
        }
        else
        {
            /* Do nothing */
        }
    }

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if (SAIL_OTA_TRIG_ERROR_ER_FLASHIMG == g_SAILUpdaterCoreCtx.testcmdID)
    {
        /* Set the byte count to 256k */
        byte_count = 256*1024;
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    /*Book keeping status update is done, Do Flashing */
    /* Erase the Partition */
    result = spinorEl1Erase (g_SAILUpdaterCoreCtx.norHandle, byte_offset/block_size, byte_count/block_size);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: Erase Partition failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessFlashImgEnd;
    }

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if (SAIL_OTA_TRIG_ERROR_ER_FLASHIMG == g_SAILUpdaterCoreCtx.testcmdID)
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Forced crash due to trigger SAIL_OTA_TRIG_ERROR_ER_FLASHIMG \n\r", __func__);
        err_fatal(SAIL_UPDATER,ERR_FATAL_FORCED_REBOOT);
    }

    if (SAIL_OTA_TRIG_ERROR_WR_FLASHIMG == g_SAILUpdaterCoreCtx.testcmdID)
    {
        /* Set the write count to 1k */
        pReqMsg->flashImg.bufLen = 1024;
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    /* Write to the partition */
    result = spinorEl1Write ( g_SAILUpdaterCoreCtx.norHandle, byte_offset, pReqMsg->flashImg.bufLen, (void *)bufAddrToUse);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: Write Partition failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessFlashImgEnd;
    }

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if (SAIL_OTA_TRIG_ERROR_WR_FLASHIMG == g_SAILUpdaterCoreCtx.testcmdID)
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Forced crash due to trigger SAIL_OTA_TRIG_ERROR_WR_FLASHIMG \n\r", __func__);
        err_fatal(SAIL_UPDATER,ERR_FATAL_FORCED_REBOOT);
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    /* Copy Buffer Address and Length from the request into the response header */
    pRspMsg->flashImg.bufAddr = pReqMsg->flashImg.bufAddr;
    pRspMsg->flashImg.bufLen = pReqMsg->flashImg.bufLen;

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if (SAIL_OTA_TRIG_ERROR_RD_FLASHIMG == g_SAILUpdaterCoreCtx.testcmdID)
    {
        /* Set the read count to 1k */
        pRspMsg->flashImg.bufLen = 1024;
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    /* Read from the partition again to verify the CRC */
    result = spinorEl1Read ( g_SAILUpdaterCoreCtx.norHandle, byte_offset, pRspMsg->flashImg.bufLen, (void *)bufAddrToUse);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: Read Partition failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessFlashImgEnd;
    }

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if (SAIL_OTA_TRIG_ERROR_RD_FLASHIMG == g_SAILUpdaterCoreCtx.testcmdID)
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Forced crash due to trigger SAIL_OTA_TRIG_ERROR_RD_FLASHIMG \n\r", __func__);
        err_fatal(SAIL_UPDATER,ERR_FATAL_FORCED_REBOOT);
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    /* Calculate Buffer CRC */
    pRspMsg->flashImg.bufCrc = 0;
    pRspMsg->flashImg.bufCrc = ulSAILUpdaterCoreCalcCRC(bufAddrToUse, pRspMsg->flashImg.bufLen);

    if (pRspMsg->flashImg.bufCrc != pReqMsg->flashImg.bufCrc)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: CRC 0x%x after read not matching the Request data CRC 0x%x \n\r", pRspMsg->flashImg.bufCrc, pReqMsg->flashImg.bufCrc);
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessFlashImgEnd;
    }

    pRspMsg->status = SAIL_UPDATER_STATUS_SUCCESS;

ProcessFlashImgEnd:
    DEBUG_LOG(SAIL_WARNING, "%s: FLASH_IMAGE Response MSG params imgName=%s FlashPartition=0x%x FlashGptId=0x%x bufAddr=0x%x bufLen=0x%x bufCrc=0x%x\n\r",
              __func__, pRspMsg->flashImg.imgName, pRspMsg->flashImg.FlashPartition, pRspMsg->flashImg.FlashGptId,
              pRspMsg->flashImg.bufAddr, pRspMsg->flashImg.bufLen, pRspMsg->flashImg.bufCrc
              );

    if (g_SAILUpdaterCoreCtx.norHandle != NULL)
    {
        /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl1Close ( g_SAILUpdaterCoreCtx.norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFlashImg: Spinor Close failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        }
        g_SAILUpdaterCoreCtx.norHandle = NULL;
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
    size_t sizeret;
    uint32_t pulIndex=0;
    char imgGuid[GUID_STRING_SIZE+1] = "";      // dummy GUID
    guid_t tmpGuid = {0};
    gptHeader_t xGPTHdr = {0};
    sailUpdaterCoreVerifyGPTtype chkGPTparam = {0};
    uint32_t bufAddrToUse = pReqMsg->readImg.bufAddr - SAIL_MD_DDR_ADDR_OFFSET;

    pRspMsg->msgId = SAIL_UPD_MSG_ID_READ_IMAGE;

    DEBUG_LOG(SAIL_WARNING, "%s: READ_IMAGE Request MSG params imgName=%s readPartition=0x%x readGptId=0x%x bufAddr=0x%x bufLen=0x%x bufCrc=0x%x\n\r",
              __func__, pReqMsg->readImg.imgName, pReqMsg->readImg.readPartition, pReqMsg->readImg.readGptId,
              pReqMsg->readImg.bufAddr, pReqMsg->readImg.bufLen, pReqMsg->readImg.bufCrc
              );

    /* Initalize SPINOR handle */
    g_SAILUpdaterCoreCtx.norHandle = NULL;
    if(SPINOR_DEVICE_DONE != spinorEl1Open ( &g_SAILUpdaterCoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadImg: Spinor Open failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessReadImgEnd;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl1GetMemInfo(g_SAILUpdaterCoreCtx.norHandle, &g_SAILUpdaterCoreCtx.memInfo))
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
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadImg: Invalid partition ID 0x%x \n\r", pReqMsg->readImg.readPartition);
        eStatus = SAIL_UPDATER_INVALID_PARTITION_ID;
        goto ProcessReadImgEnd;
    }

    /* Invalid GPT ID */
    if (pReqMsg->readImg.readGptId >= SAIL_UPD_GPT_ID_MAX)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadImg: Invalid GPT ID 0x%x \n\r", pReqMsg->readImg.readGptId);
        eStatus = SAIL_UPDATER_INVALID_GPT_ID;
        goto ProcessReadImgEnd;
    }

    /* UnAligned Buffer size */
    if (pReqMsg->readImg.bufLen % SPINOR_BYTES_ALIGNMENT)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadImg: Unaligned buffer length 0x%x \n\r", pReqMsg->readImg.bufLen);
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

    if (SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(pReqMsg->readImg.readGptId, &xGPTHdr, &chkGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadImg: GPT header read Failed GPT ID=0x%x\n\r", pReqMsg->readImg.readGptId);
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessReadImgEnd;
    }

    if( (0 == chkGPTparam.HeaderCrcStatus) || (0 == chkGPTparam.EntryCrcStatus) )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadImg: GPT header Invalid HeaderCRC=0x%x EntryCRC=0x%x HeaderCrcStatus=0x%x EntryCrcStatus=0x%x\n\r",
                  xGPTHdr.header_crc32, xGPTHdr.partition_entries_crc32,chkGPTparam.HeaderCrcStatus, chkGPTparam.EntryCrcStatus);
        eStatus = SAIL_UPDATER_GPT_INVALID;
        goto ProcessReadImgEnd;
    }

    readPartition = (pReqMsg->readImg.readPartition == SAIL_UPD_PARTITION_ID_PRIMARY)?XBL_PARTITION_A:XBL_PARTITION_B;
    readGptId = (pReqMsg->readImg.readGptId == SAIL_UPD_GPT_ID_PRIMARY)?XBL_GPT_TABLE_PRIMARY:XBL_GPT_TABLE_SECONDARY;

    /* Get the GUID for the Image */
    if(XBL_SUCCESS != sailEl1XblGetImgGUID((const char *)&pReqMsg->readImg.imgName, readPartition, readGptId, imgGuid))
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
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadImg: Invalid Buffer Size 0x%x\n\r", pReqMsg->readImg.bufLen);
        eStatus = SAIL_UPDATER_INVALID_BUF_SIZE;
        goto ProcessReadImgEnd;
    }

    /* Read the partition */
    result = spinorEl1Read ( g_SAILUpdaterCoreCtx.norHandle, byte_offset, pReqMsg->readImg.bufLen, (void *)bufAddrToUse);
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

    DEBUG_LOG(SAIL_WARNING, "%s: READ_IMAGE Response MSG params imgName=%s readPartition=0x%x readGptId=0x%x bufAddr=0x%x bufLen=0x%x bufCrc=0x%x\n\r",
              __func__, pRspMsg->readImg.imgName, pRspMsg->readImg.readPartition, pRspMsg->readImg.readGptId,
              pRspMsg->readImg.bufAddr, pRspMsg->readImg.bufLen, pRspMsg->readImg.bufCrc
              );

    if (g_SAILUpdaterCoreCtx.norHandle != NULL)
    {
        /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl1Close ( g_SAILUpdaterCoreCtx.norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadImg: Spinor Close failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        }
        g_SAILUpdaterCoreCtx.norHandle = NULL;
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
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessGetOTAMeta(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg)
{
    SPINOR_STATUS result;
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;
    uint32_t byte_offset,byte_count;

    uint32_t bufAddrToUse = pReqMsg->getMetaData.bufAddr - SAIL_MD_DDR_ADDR_OFFSET;

    pRspMsg->msgId = SAIL_UPD_MSG_ID_GET_OTA_METADATA;

    DEBUG_LOG(SAIL_WARNING, "%s: GET_OTA_METADATA Request MSG params bufAddr=0x%x bufLen=0x%x bufCrc=0x%x\n\r",
              __func__, pReqMsg->getMetaData.bufAddr, pReqMsg->getMetaData.bufLen, pReqMsg->getMetaData.bufCrc
              );

    /* Initalize SPINOR handle */
    g_SAILUpdaterCoreCtx.norHandle = NULL;
    if(SPINOR_DEVICE_DONE != spinorEl1Open ( &g_SAILUpdaterCoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetOTAMeta: Spinor Open failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessGetOTAMetaEnd;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl1GetMemInfo(g_SAILUpdaterCoreCtx.norHandle, &g_SAILUpdaterCoreCtx.memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetOTAMeta: Spinor Get Mem Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessGetOTAMetaEnd;
    }

    /* Get SAIL_OTA_METADATA partition ("e60b7926-9899-45b1-9758-c95af5657199") */
    result = spinorEl1GetGptPartitionInfo(g_SAILUpdaterCoreCtx.norHandle, "e60b7926-9899-45b1-9758-c95af5657199", &byte_offset, &byte_count);
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
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetOTAMeta: Unaligned buffer size 0x%x \n\r", pReqMsg->getMetaData.bufLen);
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
    result = spinorEl1Read ( g_SAILUpdaterCoreCtx.norHandle, byte_offset, pReqMsg->getMetaData.bufLen, (void *)bufAddrToUse);
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
    DEBUG_LOG(SAIL_WARNING, "%s: GET_OTA_METADATA Response MSG params bufAddr=0x%x bufLen=0x%x bufCrc=0x%x\n\r",
              __func__, pRspMsg->getMetaData.bufAddr, pRspMsg->getMetaData.bufLen, pRspMsg->getMetaData.bufCrc
              );

    if (g_SAILUpdaterCoreCtx.norHandle != NULL)
    {
        /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl1Close ( g_SAILUpdaterCoreCtx.norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetOTAMeta: Spinor Close failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        }
        g_SAILUpdaterCoreCtx.norHandle = NULL;
    }
    return eStatus;
}

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
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessSetOTAMeta(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;

    SPINOR_STATUS result;
    uint32_t byte_offset,byte_count,block_size;
    uint32_t temp_crc=0;
    uint32_t bufAddrToUse = pReqMsg->setMetaData.bufAddr - SAIL_MD_DDR_ADDR_OFFSET;

    pRspMsg->msgId = SAIL_UPD_MSG_ID_SET_OTA_METADATA;

    DEBUG_LOG(SAIL_WARNING, "%s: SET_OTA_METADATA Request MSG params bufAddr=0x%x bufLen=0x%x bufCrc=0x%x\n\r",
              __func__, pReqMsg->setMetaData.bufAddr, pReqMsg->setMetaData.bufLen, pReqMsg->setMetaData.bufCrc
              );

    /* Initalize SPINOR handle */
    g_SAILUpdaterCoreCtx.norHandle = NULL;
    if(SPINOR_DEVICE_DONE != spinorEl1Open ( &g_SAILUpdaterCoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessSetOTAMeta: Spinor Open failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessSetOTAMetaEnd;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl1GetMemInfo(g_SAILUpdaterCoreCtx.norHandle, &g_SAILUpdaterCoreCtx.memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessSetOTAMeta: Spinor Get Mem Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessSetOTAMetaEnd;
    }

    /* Get SAIL_OTA_METADATA partition ("e60b7926-9899-45b1-9758-c95af5657199") */
    result = spinorEl1GetGptPartitionInfo(g_SAILUpdaterCoreCtx.norHandle, "e60b7926-9899-45b1-9758-c95af5657199", &byte_offset, &byte_count);
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
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessSetOTAMeta: Unaligned buffer size 0x%x \n\r", pReqMsg->setMetaData.bufLen);
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
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessSetOTAMeta: Invalid buffer calculated CRC 0x%x the Request data CRC 0x%x \n\r", pReqMsg->setMetaData.bufCrc, temp_crc);
        eStatus = SAIL_UPDATER_INVALID_BUF_CRC;
        goto ProcessSetOTAMetaEnd;
    }

    block_size = g_SAILUpdaterCoreCtx.memInfo.pages_per_block * g_SAILUpdaterCoreCtx.memInfo.page_size_bytes;

    /* Erase the Partition */
    result = spinorEl1Erase (g_SAILUpdaterCoreCtx.norHandle, byte_offset/block_size, byte_count/block_size);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessSetOTAMeta: Erase OTA Meta Partition failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessSetOTAMetaEnd;
    }

    /* Write to the partition */
    result = spinorEl1Write ( g_SAILUpdaterCoreCtx.norHandle, byte_offset, pReqMsg->setMetaData.bufLen, (void *)bufAddrToUse);
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
    result = spinorEl1Read ( g_SAILUpdaterCoreCtx.norHandle, byte_offset, pRspMsg->setMetaData.bufLen, (void *)bufAddrToUse);
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
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessSetOTAMeta: CRC 0x%x after read not matching the Request data CRC 0x%x\n\r",pRspMsg->setMetaData.bufCrc, pReqMsg->setMetaData.bufCrc);
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessSetOTAMetaEnd;
    }

    pRspMsg->status = SAIL_UPDATER_STATUS_SUCCESS;

ProcessSetOTAMetaEnd:
    DEBUG_LOG(SAIL_WARNING, "%s: SET_OTA_METADATA Response MSG params bufAddr=0x%x bufLen=0x%x bufCrc=0x%x\n\r",
              __func__, pRspMsg->setMetaData.bufAddr, pRspMsg->setMetaData.bufLen, pRspMsg->setMetaData.bufCrc
              );

    if (g_SAILUpdaterCoreCtx.norHandle != NULL)
    {
        /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl1Close ( g_SAILUpdaterCoreCtx.norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessSetOTAMeta: Spinor Close failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        }
        g_SAILUpdaterCoreCtx.norHandle = NULL;
    }
    return eStatus;
}

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
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessReadOTAMeta(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg)
{
    SPINOR_STATUS result;
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;
    uint32_t byte_offset,byte_count;

    uint32_t bufAddrToUse = pReqMsg->readMetaData.bufAddr - SAIL_MD_DDR_ADDR_OFFSET;

    pRspMsg->msgId = SAIL_UPD_MSG_READ_OTA_METADATA;

    DEBUG_LOG(SAIL_WARNING, "%s: READ_OTA_METADATA Request MSG params bufAddr=0x%x bufLen=0x%x bufCrc=0x%x offset=0x%x size=0x%x \n\r",
              __func__, pReqMsg->readMetaData.bufAddr, pReqMsg->readMetaData.bufLen, pReqMsg->readMetaData.bufCrc,pReqMsg->readMetaData.offset,pReqMsg->readMetaData.size
              );

    /* Initialize SPINOR handle */
    g_SAILUpdaterCoreCtx.norHandle = NULL;
    if(SPINOR_DEVICE_DONE != spinorEl1Open ( &g_SAILUpdaterCoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadOTAMeta: Spinor Open failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessReadOTAMetaEnd;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl1GetMemInfo(g_SAILUpdaterCoreCtx.norHandle, &g_SAILUpdaterCoreCtx.memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadOTAMeta: Spinor Get Mem Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessReadOTAMetaEnd;
    }

    /* Get SAIL_OTA_METADATA partition ("e60b7926-9899-45b1-9758-c95af5657199") */
    result = spinorEl1GetGptPartitionInfo(g_SAILUpdaterCoreCtx.norHandle, "e60b7926-9899-45b1-9758-c95af5657199", &byte_offset, &byte_count);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadOTAMeta: Get Partition Info failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessReadOTAMetaEnd;
    }

    /* Invalid Buffer Size if the size to read is more than partition size */
    if (byte_count < pReqMsg->readMetaData.bufLen)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadOTAMeta: Invalid buffer size 0x%x \n\r", pReqMsg->readMetaData.bufLen);
        eStatus = SAIL_UPDATER_INVALID_BUF_SIZE;
        goto ProcessReadOTAMetaEnd;
    }

    if (0 == pReqMsg->readMetaData.bufLen)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadOTAMeta: Invalid buffer size 0x%x \n\r", pReqMsg->readMetaData.bufLen);
        eStatus = SAIL_UPDATER_INVALID_BUF_SIZE;
        goto ProcessReadOTAMetaEnd;
    }

    /* UnAligned Buffer size */
    if (pReqMsg->readMetaData.bufLen % SPINOR_BYTES_ALIGNMENT)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadOTAMeta: Unaligned buffer size 0x%x \n\r", pReqMsg->readMetaData.bufLen);
        eStatus = SAIL_UPDATER_UNALIGNED_BUF_SIZE;
        goto ProcessReadOTAMetaEnd;
    }

    /* UnAligned Offset */
    if (pReqMsg->readMetaData.offset % SPINOR_BYTES_ALIGNMENT)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadOTAMeta: Unaligned offset 0x%x \n\r", pReqMsg->readMetaData.offset);
        eStatus = SAIL_UPDATER_UNALIGNED_OFFSET;
        goto ProcessReadOTAMetaEnd;
    }

    /* UnAligned Size */
    if (pReqMsg->readMetaData.size % SPINOR_BYTES_ALIGNMENT)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadOTAMeta: Unaligned size 0x%x \n\r", pReqMsg->readMetaData.size);
        eStatus = SAIL_UPDATER_UNALIGNED_SIZE;
        goto ProcessReadOTAMetaEnd;
    }

    /* Invalid Size */
    if (pReqMsg->readMetaData.size > pReqMsg->readMetaData.bufLen)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadOTAMeta: Invalid size 0x%x \n\r", pReqMsg->readMetaData.size);
        eStatus = SAIL_UPDATER_INVALID_SIZE;
        goto ProcessReadOTAMetaEnd;
    }

    /* Invalid Buffer Address */
    if ((0U == pReqMsg->readMetaData.bufAddr) || (0U == bufAddrToUse) ||
        (FALSE == bPrvSAILUpdaterCoreIsAddrInRange(bufAddrToUse, pReqMsg->readMetaData.bufLen))
       )
    {
        eStatus = SAIL_UPDATER_INVALID_BUF_ADDR;
        goto ProcessReadOTAMetaEnd;
    }

    /*If Read Boundary is crossing partition boundary*/
    if((pReqMsg->readMetaData.offset + pReqMsg->readMetaData.size) > byte_count )
    {
        DEBUG_LOG( SAIL_ERROR, "xSAILUpdaterCoreProcessReadOTAMeta: Invalid Size 0x%x Read Boundary crossing Partition Boundary\r\n", pReqMsg->readMetaData.size );
        eStatus = SAIL_UPDATER_INVALID_SIZE;
        goto ProcessReadOTAMetaEnd;
    }

    /* Read the partition */
    result = spinorEl1Read ( g_SAILUpdaterCoreCtx.norHandle, (byte_offset+pReqMsg->readMetaData.offset), pReqMsg->readMetaData.size, (void *)bufAddrToUse);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadOTAMeta: Read from OTA Meta Partition failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessReadOTAMetaEnd;
    }

    /* Calculate Buffer CRC */
    pRspMsg->readMetaData.bufCrc = 0;
    pRspMsg->readMetaData.bufCrc = ulSAILUpdaterCoreCalcCRC(bufAddrToUse, pReqMsg->readMetaData.bufLen);

    /* Copy Buffer Address and Length from the request into the response header */
    pRspMsg->readMetaData.bufAddr = pReqMsg->readMetaData.bufAddr;
    pRspMsg->readMetaData.bufLen = pReqMsg->readMetaData.bufLen;
    pRspMsg->readMetaData.offset = pReqMsg->readMetaData.offset;
    pRspMsg->readMetaData.size = pReqMsg->readMetaData.size;

    pRspMsg->status = SAIL_UPDATER_STATUS_SUCCESS;

ProcessReadOTAMetaEnd:
    DEBUG_LOG(SAIL_WARNING, "%s: READ_OTA_METADATA Response MSG params bufAddr=0x%x bufLen=0x%x bufCrc=0x%x offset=0x%x size=0x%x \n\r",
              __func__, pRspMsg->readMetaData.bufAddr, pRspMsg->readMetaData.bufLen, pRspMsg->readMetaData.bufCrc, pRspMsg->readMetaData.offset, pRspMsg->readMetaData.size
              );

    if (g_SAILUpdaterCoreCtx.norHandle != NULL)
    {
        /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl1Close ( g_SAILUpdaterCoreCtx.norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadOTAMeta: Spinor Close failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        }
        g_SAILUpdaterCoreCtx.norHandle = NULL;
    }
    return eStatus;
}

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
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessWriteOTAMeta(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;

    SPINOR_STATUS result;
    uint32_t byte_offset,byte_count;
    uint32_t temp_crc=0;
    uint32_t bufAddrToUse = pReqMsg->writeMetaData.bufAddr - SAIL_MD_DDR_ADDR_OFFSET;

    pRspMsg->msgId = SAIL_UPD_MSG_WRITE_OTA_METADATA;

    DEBUG_LOG(SAIL_WARNING, "%s: WRITE_OTA_METADATA Request MSG params bufAddr=0x%x bufLen=0x%x bufCrc=0x%x offset=0x%x size=0x%x\n\r",
              __func__, pReqMsg->writeMetaData.bufAddr, pReqMsg->writeMetaData.bufLen, pReqMsg->writeMetaData.bufCrc, pReqMsg->writeMetaData.offset,  pReqMsg->writeMetaData.size
              );

    /* Initalize SPINOR handle */
    g_SAILUpdaterCoreCtx.norHandle = NULL;
    if(SPINOR_DEVICE_DONE != spinorEl1Open ( &g_SAILUpdaterCoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteOTAMeta: Spinor Open failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessWriteOTAMetaEnd;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl1GetMemInfo(g_SAILUpdaterCoreCtx.norHandle, &g_SAILUpdaterCoreCtx.memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteOTAMeta: Spinor Get Mem Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessWriteOTAMetaEnd;
    }

    /* Get SAIL_OTA_METADATA partition ("e60b7926-9899-45b1-9758-c95af5657199") */
    result = spinorEl1GetGptPartitionInfo(g_SAILUpdaterCoreCtx.norHandle, "e60b7926-9899-45b1-9758-c95af5657199", &byte_offset, &byte_count);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteOTAMeta: Get Partition Info failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessWriteOTAMetaEnd;
    }

    /* Invalid Buffer Size if the size to write is more than partition size */
    if (byte_count < pReqMsg->writeMetaData.bufLen)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteOTAMeta: Invalid buffer size 0x%x \n\r", pReqMsg->writeMetaData.bufLen);
        eStatus = SAIL_UPDATER_INVALID_BUF_SIZE;
        goto ProcessWriteOTAMetaEnd;
    }

    if (0 == pReqMsg->writeMetaData.bufLen)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteOTAMeta: Invalid buffer size 0x%x \n\r", pReqMsg->writeMetaData.bufLen);
        eStatus = SAIL_UPDATER_INVALID_BUF_SIZE;
        goto ProcessWriteOTAMetaEnd;
    }

    /* UnAligned Buffer size */
    if (pReqMsg->writeMetaData.bufLen % SPINOR_BYTES_ALIGNMENT)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteOTAMeta: Unaligned buffer size 0x%x \n\r", pReqMsg->writeMetaData.bufLen);
        eStatus = SAIL_UPDATER_UNALIGNED_BUF_SIZE;
        goto ProcessWriteOTAMetaEnd;
    }

    /* UnAligned Offset */
    if (pReqMsg->writeMetaData.offset % SPINOR_BYTES_ALIGNMENT)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteOTAMeta: Unaligned offset 0x%x \n\r", pReqMsg->writeMetaData.offset);
        eStatus = SAIL_UPDATER_UNALIGNED_OFFSET;
        goto ProcessWriteOTAMetaEnd;
    }

    /* UnAligned Size */
    if (pReqMsg->writeMetaData.size % SPINOR_BYTES_ALIGNMENT)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteOTAMeta: Unaligned size 0x%x \n\r", pReqMsg->writeMetaData.size);
        eStatus = SAIL_UPDATER_UNALIGNED_SIZE;
        goto ProcessWriteOTAMetaEnd;
    }

    /* Invalid Size */
    if (pReqMsg->writeMetaData.size > pReqMsg->readMetaData.bufLen)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteOTAMeta: Invalid size 0x%x \n\r", pReqMsg->writeMetaData.size);
        eStatus = SAIL_UPDATER_INVALID_SIZE;
        goto ProcessWriteOTAMetaEnd;
    }

    /* Invalid Buffer Address */
    if ((0U == pReqMsg->writeMetaData.bufAddr) || (0U == bufAddrToUse) ||
        (FALSE == bPrvSAILUpdaterCoreIsAddrInRange(bufAddrToUse, pReqMsg->writeMetaData.bufLen))
       )
    {
        eStatus = SAIL_UPDATER_INVALID_BUF_ADDR;
        goto ProcessWriteOTAMetaEnd;
    }

    /*If Write Boundary is crossing partition boundary*/
    if((pReqMsg->writeMetaData.offset + pReqMsg->writeMetaData.size) > byte_count )
    {
        DEBUG_LOG( SAIL_ERROR, "xSAILUpdaterCoreProcessWriteOTAMeta: Invalid Size 0x%x Read Boundary crossing Partition Boundary\r\n", pReqMsg->writeMetaData.size );
        eStatus = SAIL_UPDATER_INVALID_SIZE;
        goto ProcessWriteOTAMetaEnd;
    }

    /* Copy the current CRC and Calculate Buffer CRC */
    temp_crc = pReqMsg->writeMetaData.bufCrc;
    pReqMsg->writeMetaData.bufCrc = 0;
    pReqMsg->writeMetaData.bufCrc = ulSAILUpdaterCoreCalcCRC(bufAddrToUse, pReqMsg->writeMetaData.bufLen);

    /* Verify Buffer CRC */
    if(TRUE == bPrvSAILUpdaterCoreIsCRCNotMatch(temp_crc, pReqMsg->writeMetaData.bufCrc))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteOTAMeta: Invalid buffer calculated CRC 0x%x the Request data CRC 0x%x \n\r", pReqMsg->writeMetaData.bufCrc, temp_crc);
        eStatus = SAIL_UPDATER_INVALID_BUF_CRC;
        goto ProcessWriteOTAMetaEnd;
    }

    /* Write to the partition */
    result = spinorEl1Write ( g_SAILUpdaterCoreCtx.norHandle, (byte_offset+pReqMsg->writeMetaData.offset), pReqMsg->writeMetaData.size, (void *)bufAddrToUse);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteOTAMeta: Write OTA Meta Partition failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessWriteOTAMetaEnd;
    }

    /* Copy Buffer Address and Length from the request into the response header */
    pRspMsg->writeMetaData.bufAddr = pReqMsg->writeMetaData.bufAddr;
    pRspMsg->writeMetaData.bufLen = pReqMsg->writeMetaData.bufLen;
    pRspMsg->writeMetaData.offset = pReqMsg->writeMetaData.offset;
    pRspMsg->writeMetaData.size = pReqMsg->writeMetaData.size;
    pRspMsg->writeMetaData.bufCrc = pReqMsg->writeMetaData.bufCrc;

    pRspMsg->status = SAIL_UPDATER_STATUS_SUCCESS;

ProcessWriteOTAMetaEnd:
    DEBUG_LOG(SAIL_WARNING, "%s: WRITE_OTA_METADATA Response MSG params bufAddr=0x%x bufLen=0x%x bufCrc=0x%x offset=0x%x size=0x%x\n\r",
              __func__, pRspMsg->writeMetaData.bufAddr, pRspMsg->writeMetaData.bufLen, pRspMsg->writeMetaData.bufCrc, pRspMsg->writeMetaData.offset, pRspMsg->writeMetaData.size
              );

    if (g_SAILUpdaterCoreCtx.norHandle != NULL)
    {
        /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl1Close ( g_SAILUpdaterCoreCtx.norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteOTAMeta: Spinor Close failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        }
        g_SAILUpdaterCoreCtx.norHandle = NULL;
    }
    return eStatus;
}

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
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessEraseOTAMeta(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;

    SPINOR_STATUS result;
    uint32_t byte_offset,byte_count,block_size;
    uint32_t temp_crc=0;

    pRspMsg->msgId = SAIL_UPD_MSG_ERASE_OTA_METADATA;

    DEBUG_LOG(SAIL_WARNING, "%s: ERASE_OTA_METADATA Request MSG params start_block=0x%x block_cnt=0x%x\n\r",
              __func__, pReqMsg->eraseMetaData.start_block, pReqMsg->eraseMetaData.block_cnt
              );

    /* Initalize SPINOR handle */
    g_SAILUpdaterCoreCtx.norHandle = NULL;
    if(SPINOR_DEVICE_DONE != spinorEl1Open ( &g_SAILUpdaterCoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessEraseOTAMeta: Spinor Open failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessEraseOTAMetaEnd;
    }

   /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl1GetMemInfo(g_SAILUpdaterCoreCtx.norHandle, &g_SAILUpdaterCoreCtx.memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessEraseOTAMeta: Spinor Get Mem Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessEraseOTAMetaEnd;
    }

    block_size = g_SAILUpdaterCoreCtx.memInfo.pages_per_block * g_SAILUpdaterCoreCtx.memInfo.page_size_bytes;

    /* Get SAIL_OTA_METADATA partition ("e60b7926-9899-45b1-9758-c95af5657199") */
    result = spinorEl1GetGptPartitionInfo(g_SAILUpdaterCoreCtx.norHandle, "e60b7926-9899-45b1-9758-c95af5657199", &byte_offset, &byte_count);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessEraseOTAMeta: Get Partition Info failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessEraseOTAMetaEnd;
    }

    /*If Erase Boundary is crossing partition boundary*/
    if(pReqMsg->eraseMetaData.block_cnt*4096 > byte_count)
    {
        DEBUG_LOG( SAIL_ERROR, "xSAILUpdaterCoreProcessEraseOTAMeta: Invalid Size 0x%x for erase block_count > byte_count, Erase Boundary crossing Partition Boundary\r\n", pReqMsg->eraseMetaData.block_cnt*4096 );
        eStatus = SAIL_UPDATER_INVALID_SIZE;
        goto ProcessEraseOTAMetaEnd;
    }

    /*If Erase Boundary is crossing partition boundary*/
    if(((pReqMsg->eraseMetaData.start_block*4096) + (pReqMsg->eraseMetaData.block_cnt*4096)-1) > byte_count)
    {
        DEBUG_LOG( SAIL_ERROR, "xSAILUpdaterCoreProcessEraseOTAMeta: Invalid Size 0x%x for erase start_bloc + block count > byte_count , Erase Boundary crossing Partition Boundary\r\n", pReqMsg->eraseMetaData.block_cnt*4096 );
        eStatus = SAIL_UPDATER_INVALID_SIZE;
        goto ProcessEraseOTAMetaEnd;
    }

    /* Erase the Partition */
    result = spinorEl1Erase (g_SAILUpdaterCoreCtx.norHandle, (byte_offset+(pReqMsg->eraseMetaData.start_block*4096))/block_size, pReqMsg->eraseMetaData.block_cnt);
    if( result == SPINOR_ERASE_BLOCK_INVALID )
    {
        DEBUG_LOG(SAIL_WARNING,"xSAILUpdaterCoreProcessEraseOTAMeta: Erase OTA Meta Partition failed ERASE Block Invalid \n\r");
        eStatus = SAIL_UPDATER_INVALID_ERASE_BLOCK;
        goto ProcessEraseOTAMetaEnd;
    }
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessEraseOTAMeta: Erase OTA Meta Partition failed\n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessEraseOTAMetaEnd;
    }

    /* Copy Buffer Address and Length from the request into the response header */
    pRspMsg->eraseMetaData.start_block = pReqMsg->eraseMetaData.start_block;
    pRspMsg->eraseMetaData.block_cnt = pReqMsg->eraseMetaData.block_cnt;

    pRspMsg->status = SAIL_UPDATER_STATUS_SUCCESS;

ProcessEraseOTAMetaEnd:
     DEBUG_LOG(SAIL_WARNING, "%s: ERASE_OTA_METADATA Response MSG params start_block=0x%x block_cnt=0x%x\n\r",
              __func__, pRspMsg->eraseMetaData.start_block, pRspMsg->eraseMetaData.block_cnt
              );

    if (g_SAILUpdaterCoreCtx.norHandle != NULL)
    {
        /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl1Close ( g_SAILUpdaterCoreCtx.norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessEraseOTAMeta: Spinor Close failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        }
        g_SAILUpdaterCoreCtx.norHandle = NULL;
    }
    return eStatus;
}

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
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessGetOTAMetaInfo(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg)
{
    SPINOR_STATUS result;
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;
    uint32_t byte_offset,byte_count,num_blocks,blockStart,idx1,idx2,i;
    spinorSectorMapInfoType el1_sectorMapInfo = {0};

    pRspMsg->msgId = SAIL_UPD_MSG_GET_OTA_METADATAINFO;

    DEBUG_LOG(SAIL_WARNING, "%s: GET_OTA_METADATAInfo Request MSG params partition size=0x%x \n\r",
            __func__, pReqMsg->getMetaDataInfo.partition_size
              );

    /* Initalize SPINOR handle */
    g_SAILUpdaterCoreCtx.norHandle = NULL;
    if(SPINOR_DEVICE_DONE != spinorEl1Open ( &g_SAILUpdaterCoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetOTAMetaInfo: Spinor Open failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessGetOTAMetaInfoEnd;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl1GetMemInfo(g_SAILUpdaterCoreCtx.norHandle, &g_SAILUpdaterCoreCtx.memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetOTAMetaInfo: Spinor Get Mem Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessGetOTAMetaInfoEnd;
    }

    /* Get SAIL_OTA_METADATA partition ("e60b7926-9899-45b1-9758-c95af5657199") */
    result = spinorEl1GetGptPartitionInfo(g_SAILUpdaterCoreCtx.norHandle, "e60b7926-9899-45b1-9758-c95af5657199", &byte_offset, &byte_count);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetOTAMetaInfo: Get Partition Info failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessGetOTAMetaInfoEnd;
    }

    /* Get Sector Map Info*/
    result = spinorEl1GetSectorMapInfo(g_SAILUpdaterCoreCtx.norHandle, &el1_sectorMapInfo);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG( SAIL_ERROR, "xSAILUpdaterCoreProcessGetOTAMetaInfo: spinorEl1GetSectorMapInfo FAILED\r\n" );
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessGetOTAMetaInfoEnd;
    }

    idx1 = sizeof(el1_sectorMapInfo.sectorMapInfo)/sizeof(el1_sectorMapInfo.sectorMapInfo[0]);
    idx2 = sizeof(el1_sectorMapInfo.sectorMapInfo)/sizeof(el1_sectorMapInfo.sectorMapInfo[0]);

    /*Identify the Offset Range*/
    for (int secMapIndx = 0; secMapIndx < sizeof(el1_sectorMapInfo.sectorMapInfo)/sizeof(el1_sectorMapInfo.sectorMapInfo[0]); secMapIndx++)
    {
        /*Find the start index idx1, If byte offset is within this sector map*/
        if ( (byte_offset >= el1_sectorMapInfo.sectorMapInfo[secMapIndx].start_range) && (byte_offset <= el1_sectorMapInfo.sectorMapInfo[secMapIndx].end_range))
        {
            idx1 = secMapIndx;
        }
        /*Find the end index idx2, If byte offset is within this sector map*/
        if ( ((byte_offset + byte_count) >= el1_sectorMapInfo.sectorMapInfo[secMapIndx].start_range) && ((byte_offset + byte_count) <= el1_sectorMapInfo.sectorMapInfo[secMapIndx].end_range))
        {
            idx2 = secMapIndx;
        }
    }

    if((idx1 == sizeof(el1_sectorMapInfo.sectorMapInfo)/sizeof(el1_sectorMapInfo.sectorMapInfo[0])) || (idx2 == sizeof(el1_sectorMapInfo.sectorMapInfo)/sizeof(el1_sectorMapInfo.sectorMapInfo[0])))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetOTAMetaInfo: Offset Range Not Identified in the Sector Map \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessGetOTAMetaInfoEnd;
    }

    if(idx2 > idx1+2)
    {
        DEBUG_LOG(SAIL_WARNING, "%s: GET_OTA_METADATAInfo error more regions available. size of metadata greater than expected. check memory map\n\r",__func__);
    }
    else
    {
        i = 0;
        do
        {
            pRspMsg->getMetaDataInfo.sectorMap[i].offset_start_range = (byte_offset >= el1_sectorMapInfo.sectorMapInfo[idx1+i].start_range)?0:(el1_sectorMapInfo.sectorMapInfo[idx1+i].start_range-byte_offset);
            pRspMsg->getMetaDataInfo.sectorMap[i].offset_end_range = (byte_offset+byte_count-1 >= el1_sectorMapInfo.sectorMapInfo[idx1+i].end_range)?(el1_sectorMapInfo.sectorMapInfo[idx1+i].end_range - byte_offset):(byte_count-1);
            pRspMsg->getMetaDataInfo.sectorMap[i].erase_size_kB = el1_sectorMapInfo.sectorMapInfo[idx1+i].er_size_KB;
            i++;
        }while(idx1+i<idx2);
    }

    /* Copy from the request into the response header */
    pRspMsg->getMetaDataInfo.partition_size = byte_count/1024;

    pRspMsg->status = SAIL_UPDATER_STATUS_SUCCESS;

ProcessGetOTAMetaInfoEnd:
    DEBUG_LOG(SAIL_WARNING, "%s: GET_OTA_METADATAInfo Response MSG params partition size=0x%x\n\r sectormap[0] offset_start_range=0x%x offset_end_range=0x%x erase_size_kB=0x%x\n\r sectormap[1] offset_start_range=0x%x offset_end_range=0x%x erase_size_kB=0x%x\n\r sectormap[2] offset_start_range=0x%x offset_end_range=0x%x erase_size_kB=0x%x\n\r",
            __func__, pRspMsg->getMetaDataInfo.partition_size, pRspMsg->getMetaDataInfo.sectorMap[0].offset_start_range, pRspMsg->getMetaDataInfo.sectorMap[0].offset_end_range, pRspMsg->getMetaDataInfo.sectorMap[0].erase_size_kB, pRspMsg->getMetaDataInfo.sectorMap[1].offset_start_range, pRspMsg->getMetaDataInfo.sectorMap[1].offset_end_range, pRspMsg->getMetaDataInfo.sectorMap[1].erase_size_kB, pRspMsg->getMetaDataInfo.sectorMap[2].offset_start_range, pRspMsg->getMetaDataInfo.sectorMap[2].offset_end_range, pRspMsg->getMetaDataInfo.sectorMap[2].erase_size_kB
              );

    if (g_SAILUpdaterCoreCtx.norHandle != NULL)
    {
        /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl1Close ( g_SAILUpdaterCoreCtx.norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetOTAMetaInfo: Spinor Close failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        }
        g_SAILUpdaterCoreCtx.norHandle = NULL;
    }
    return eStatus;
}

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
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessChkGPT(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;
    sailUpdaterCoreVerifyGPTtype xPrimaryGPTparam={0}, xSecondaryGPTparam ={0};


    pRspMsg->msgId = SAIL_UPD_MSG_ID_CHECK_GPT;


    DEBUG_LOG(SAIL_WARNING, "%s: CHECK_GPT Request MSG params primaryGptHeaderCrcStatus=0x%x primaryGptEntryCrcStatus=0x%x primaryGptSize=0x%x secondaryGptHeaderCrcStatus=0x%x secondaryGptEntryCrcStatus=0x%x secondaryGptSize=0x%x\n\r",
              __func__, pReqMsg->checkGpt.primaryGptHeaderCrcStatus, pReqMsg->checkGpt.primaryGptEntryCrcStatus, pReqMsg->checkGpt.primaryGptSize,
              pReqMsg->checkGpt.secondaryGptHeaderCrcStatus, pReqMsg->checkGpt.secondaryGptEntryCrcStatus, pReqMsg->checkGpt.secondaryGptSize
              );

    /* Initalize SPINOR handle */
    g_SAILUpdaterCoreCtx.norHandle = NULL;
    if(SPINOR_DEVICE_DONE != spinorEl1Open ( &g_SAILUpdaterCoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessChkGPT: Spinor Open failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ChkGPTEnd;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl1GetMemInfo(g_SAILUpdaterCoreCtx.norHandle, &g_SAILUpdaterCoreCtx.memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessChkGPT: Spinor Get Mem Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ChkGPTEnd;
    }

    /* Check the GPT health of Primary GPT */
    if (SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(SAIL_UPD_GPT_ID_PRIMARY, &g_SAILUpdaterCoreCtx.PrimaryGPTHdr, &xPrimaryGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessChkGPT: Getting Primary GPT health failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ChkGPTEnd;
    }

    /* Check the GPT health of Secondary GPT */
    if (SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(SAIL_UPD_GPT_ID_SECONDARY, &g_SAILUpdaterCoreCtx.SecondaryGPTHdr, &xSecondaryGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessChkGPT: Getting Secondary GPT health failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ChkGPTEnd;
    }

    DEBUG_LOG(SAIL_WARNING, "%s: CHECK_GPT primaryGptHeaderCrc=0x%x primaryGptEntryCrc=0x%x primaryGptNumPartitions=0x%x secondaryGptHeaderCrcStatus=0x%x secondaryGptEntryCrcStatus=0x%x secondaryGptNumPartitions=0x%x\n\r",
              __func__, g_SAILUpdaterCoreCtx.PrimaryGPTHdr.header_crc32, g_SAILUpdaterCoreCtx.PrimaryGPTHdr.partition_entries_crc32, g_SAILUpdaterCoreCtx.PrimaryGPTHdr.number_of_partition_entries,
              g_SAILUpdaterCoreCtx.SecondaryGPTHdr.header_crc32, g_SAILUpdaterCoreCtx.SecondaryGPTHdr.partition_entries_crc32, g_SAILUpdaterCoreCtx.SecondaryGPTHdr.number_of_partition_entries
              );

    pRspMsg->checkGpt.primaryGptEntryCrcStatus = xPrimaryGPTparam.EntryCrcStatus;
    pRspMsg->checkGpt.primaryGptHeaderCrcStatus = xPrimaryGPTparam.HeaderCrcStatus;
    pRspMsg->checkGpt.primaryGptSize = xPrimaryGPTparam.GptSize;
    pRspMsg->checkGpt.primaryGptPartitionEntryCrc = g_SAILUpdaterCoreCtx.PrimaryGPTHdr.partition_entries_crc32;

    pRspMsg->checkGpt.secondaryGptEntryCrcStatus = xSecondaryGPTparam.EntryCrcStatus;
    pRspMsg->checkGpt.secondaryGptHeaderCrcStatus = xSecondaryGPTparam.HeaderCrcStatus;
    pRspMsg->checkGpt.secondaryGptSize = xSecondaryGPTparam.GptSize;
    pRspMsg->checkGpt.secondaryGptPartitionEntryCrc = g_SAILUpdaterCoreCtx.SecondaryGPTHdr.partition_entries_crc32;

    pRspMsg->status = SAIL_UPDATER_STATUS_SUCCESS;

ChkGPTEnd:
    DEBUG_LOG(SAIL_WARNING, "%s: CHECK_GPT Response MSG params primaryGptHeaderCrcStatus=0x%x primaryGptEntryCrcStatus=0x%x primaryGptSize=0x%x secondaryGptHeaderCrcStatus=0x%x secondaryGptEntryCrcStatus=0x%x secondaryGptSize=0x%x\n\r",
              __func__, pRspMsg->checkGpt.primaryGptHeaderCrcStatus, pRspMsg->checkGpt.primaryGptEntryCrcStatus, pRspMsg->checkGpt.primaryGptSize,
              pRspMsg->checkGpt.secondaryGptHeaderCrcStatus, pRspMsg->checkGpt.secondaryGptEntryCrcStatus, pRspMsg->checkGpt.secondaryGptSize
              );

    if (g_SAILUpdaterCoreCtx.norHandle != NULL)
    {
        /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl1Close ( g_SAILUpdaterCoreCtx.norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessChkGPT: Spinor Close failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        }
        g_SAILUpdaterCoreCtx.norHandle = NULL;
    }
    return eStatus;
}

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
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessReadGPT(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;
    size_t result;
    gptHeader_t xGPTHdr = {0};
    sailUpdaterCoreVerifyGPTtype chkGPTparam = {0};
    uint32_t bufAddrToUse = pReqMsg->readGpt.bufAddr - SAIL_MD_DDR_ADDR_OFFSET;

    pRspMsg->msgId = SAIL_UPD_MSG_ID_READ_GPT;

    pRspMsg->readGpt.id = pReqMsg->readGpt.id;

    DEBUG_LOG(SAIL_WARNING, "%s: READ_GPT Request MSG params GPT ID=0x%x bufAddr=0x%x bufLen=0x%x bufCrc=0x%x\n\r",
              __func__, pReqMsg->readGpt.id, pReqMsg->readGpt.bufAddr, pReqMsg->readGpt.bufLen, pReqMsg->readGpt.bufCrc
              );

    /* Initalize SPINOR handle */
    g_SAILUpdaterCoreCtx.norHandle = NULL;
    if(SPINOR_DEVICE_DONE != spinorEl1Open ( &g_SAILUpdaterCoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadGPT: Spinor Open failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ReadGPTEnd;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl1GetMemInfo(g_SAILUpdaterCoreCtx.norHandle, &g_SAILUpdaterCoreCtx.memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadGPT: Spinor Get Mem Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ReadGPTEnd;
    }

    /* Validate GPT ID */
    if (pReqMsg->readGpt.id >= SAIL_UPD_GPT_ID_MAX)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadGPT: Invalid GPT ID 0x%x \n\r", pReqMsg->readGpt.id);
        eStatus = SAIL_UPDATER_INVALID_GPT_ID;
        goto ReadGPTEnd;
    }

    if( SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(pReqMsg->readGpt.id, &xGPTHdr, &chkGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadGPT: GPT header read Failed GPT ID 0x%x\n\r", pReqMsg->readGpt.id);
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ReadGPTEnd;
    }

    if( (0 == chkGPTparam.HeaderCrcStatus) || (0 == chkGPTparam.EntryCrcStatus) )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadGPT: GPT header Invalid HeaderCRC=0x%x EntryCRC=0x%x HeaderCrcStatus=0x%x EntryCrcStatus=0x%x\n\r",
                  xGPTHdr.header_crc32, xGPTHdr.partition_entries_crc32,chkGPTparam.HeaderCrcStatus, chkGPTparam.EntryCrcStatus);
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
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadGPT: Unaligned Buffer Size 0x%x \n\r",pReqMsg->readGpt.bufLen);
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
    DEBUG_LOG(SAIL_WARNING, "%s: READ_GPT Response MSG params GPT ID=0x%x bufAddr=0x%x bufLen=0x%x bufCrc=0x%x\n\r",
              __func__, pRspMsg->readGpt.id, pRspMsg->readGpt.bufAddr, pRspMsg->readGpt.bufLen, pRspMsg->readGpt.bufCrc
              );

    if (g_SAILUpdaterCoreCtx.norHandle != NULL)
    {
        /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl1Close ( g_SAILUpdaterCoreCtx.norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessReadGPT: Spinor Close failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        }
        g_SAILUpdaterCoreCtx.norHandle = NULL;
    }
    return eStatus;
}

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

    DEBUG_LOG(SAIL_WARNING, "%s: WRITE_GPT Request MSG params GPT ID=0x%x bufAddr=0x%x bufLen=0x%x bufCrc=0x%x\n\r",
              __func__, pReqMsg->writeGpt.id, pReqMsg->writeGpt.bufAddr, pReqMsg->writeGpt.bufLen, pReqMsg->writeGpt.bufCrc
              );

    pRspMsg->writeGpt.id = pReqMsg->writeGpt.id;

    /* Initalize SPINOR handle */
    g_SAILUpdaterCoreCtx.norHandle = NULL;
    if(SPINOR_DEVICE_DONE != spinorEl1Open ( &g_SAILUpdaterCoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: Spinor Open failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto WriteGPTEnd;
    }
      /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl1GetMemInfo(g_SAILUpdaterCoreCtx.norHandle, &g_SAILUpdaterCoreCtx.memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: Spinor Get Mem Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto WriteGPTEnd;
    }

    /* Validate GPT ID */
    if (pReqMsg->writeGpt.id >= SAIL_UPD_GPT_ID_MAX)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: Invalid GPT ID 0x%x \n\r", pReqMsg->writeGpt.id);
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
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: Alt GPT header read Failed GPT ID=0x%x \n\r", ulAltGptId);
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto WriteGPTEnd;
    }

    if ((0 == chkGPTparam.EntryCrcStatus) || (0 == chkGPTparam.HeaderCrcStatus))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: Alt GPT header Invalid HeaderCRC=0x%x EntryCRC=0x%x HeaderCrcStatus=0x%x EntryCrcStatus=0x%x\n\r",
                  xAltGPTHdr.header_crc32, xAltGPTHdr.partition_entries_crc32,chkGPTparam.HeaderCrcStatus, chkGPTparam.EntryCrcStatus);
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
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: Unaligned Buffer Size 0x%x \n\r", pReqMsg->writeGpt.bufLen);
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
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: Invalid Buffer CRC calculated 0x%x Received CRC 0x%x  \n\r",pReqMsg->writeGpt.bufCrc, temp_crc);
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
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: GPT header CRC invalid HeaderCRC=0x%x \n\r", xGPTHdr.header_crc32);
        eStatus = SAIL_UPDATER_GPT_HEADERCRC_INVALID;
        goto WriteGPTEnd;
    }

    /* Calculate partition entries CRC */
    ulEntrySz  = xGPTHdr.size_of_partition_entry * xGPTHdr.number_of_partition_entries;
    temp_crc = gptCalcCRC32((const uint8_t *)(bufAddrToUse+sizeof(gptHeader_t)), ulEntrySz, GPT_CRC32_SEED_DEFAULT);

    if (temp_crc != xGPTHdr.partition_entries_crc32)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: Partition entries CRC invalid calculated CRC 0x%x Received CRC 0x%x \n\r",temp_crc, xGPTHdr.partition_entries_crc32 );
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
        ulEraseSz = xGPTHdr.my_lba - xGPTHdr.partition_entry_lba +(g_SAILUpdaterCoreCtx.memInfo.block_count - xGPTHdr.my_lba);
    }

    /* Erase the Destination GPT Header and partition entries */
    result = spinorEl1Erase (g_SAILUpdaterCoreCtx.norHandle, ulEraseLBA, ulEraseSz);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: Erase GPT Header and Partition entries failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto WriteGPTEnd;
    }

    ulEntrySz  = xGPTHdr.size_of_partition_entry * xGPTHdr.number_of_partition_entries;

    block_size = g_SAILUpdaterCoreCtx.memInfo.pages_per_block * g_SAILUpdaterCoreCtx.memInfo.page_size_bytes;

    /* copy into max 4k chunks in to local work buffer and then write so that the buffer address is aligned */
    num_bytes = ulEntrySz;

    srcAddr = bufAddrToUse + sizeof(gptHeader_t);
    partitionOffsetAddr = partition_entry_offset * block_size;

    while (num_bytes)
    {
        max_transfersize = (num_bytes <= ARRAY_LENGTH(gSAILUpdatergptWorkBuf))?num_bytes:ARRAY_LENGTH(gSAILUpdatergptWorkBuf);

        /* Copy the entries from workbuffer to local buffers */
        result = sailbsp_memscpy(g_SAILUpdaterCoreCtx.pGPTWorkBuf, max_transfersize, (const void *)srcAddr, max_transfersize);
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
                memset(g_SAILUpdaterCoreCtx.pGPTWorkBuf + num_bytes, 0xFF, (max_transfersize - num_bytes));
            }
            num_bytes -= num_bytes;
        }
        else
        {
            num_bytes -= max_transfersize;
        }

        /* Flush and Invalidate the cache for the local buffer containing the destination content */
        clean_invalidate_cache_by_range((uint32)g_SAILUpdaterCoreCtx.pGPTWorkBuf, (uint32)g_SAILUpdaterCoreCtx.pGPTWorkBuf + max_transfersize);

        /* Write the Destination GPT partition entries */
        result = spinorEl1Write ( g_SAILUpdaterCoreCtx.norHandle, partitionOffsetAddr, max_transfersize, (void *)g_SAILUpdaterCoreCtx.pGPTWorkBuf );
        if( result != SPINOR_DEVICE_DONE )
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: Write partition entries failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
            goto WriteGPTEnd;
        }
        partitionOffsetAddr += max_transfersize;
    }

    /* Copy the GPT header to Destination buffer that can accommodate extra bytes for taking care of padding for alignment */
    result = sailbsp_memscpy(g_SAILUpdaterCoreCtx.pGPTWorkBuf, sizeof(gptHeader_t), (const void *)bufAddrToUse, sizeof(gptHeader_t));
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
        memset(g_SAILUpdaterCoreCtx.pGPTWorkBuf + sizeof(gptHeader_t), 0xFF, (ulWriteSz - sizeof(gptHeader_t)));
    }

    /* Calcuate the buffer offsets for the destination from the GPT header */
    destHdrLba = xGPTHdr.my_lba;

    /* Flush and Invalidate the cache for the address containing the destination content */
    clean_invalidate_cache_by_range((uint32)g_SAILUpdaterCoreCtx.pGPTWorkBuf, (uint32)g_SAILUpdaterCoreCtx.pGPTWorkBuf + ulWriteSz);

    block_size = g_SAILUpdaterCoreCtx.memInfo.pages_per_block * g_SAILUpdaterCoreCtx.memInfo.page_size_bytes;

    /* Write the Destination GPT header */
    result = spinorEl1Write ( g_SAILUpdaterCoreCtx.norHandle, destHdrLba * block_size, ulWriteSz, (void *)g_SAILUpdaterCoreCtx.pGPTWorkBuf);
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
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: Destination GPT header Invalid HeaderCRC=0x%x EntryCRC=0x%x HeaderCrcStatus=0x%x EntryCrcStatus=0x%x\n\r",
                  xGPTHdr.header_crc32, xGPTHdr.partition_entries_crc32,chkDestGPTparam.HeaderCrcStatus, chkDestGPTparam.EntryCrcStatus);
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto WriteGPTEnd;
    }

    pRspMsg->status = SAIL_UPDATER_STATUS_SUCCESS;

WriteGPTEnd:
    DEBUG_LOG(SAIL_WARNING, "%s: WRITE_GPT Response MSG params GPT ID=0x%x bufAddr=0x%x bufLen=0x%x bufCrc=0x%x\n\r",
              __func__, pRspMsg->writeGpt.id, pRspMsg->writeGpt.bufAddr, pRspMsg->writeGpt.bufLen, pRspMsg->writeGpt.bufCrc
              );

    if (g_SAILUpdaterCoreCtx.norHandle != NULL)
    {
        /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl1Close ( g_SAILUpdaterCoreCtx.norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessWriteGPT: Spinor Close failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        }
        g_SAILUpdaterCoreCtx.norHandle = NULL;
    }
    return eStatus;
}

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
    SAILUpdaterOTAStateValType xOtaStatus = { 0 };
    uint32_t bufAddrToUse = pReqMsg->fixGpt.bufAddr - SAIL_MD_DDR_ADDR_OFFSET;
    uint8_t guidMap = 0;

    pRspMsg->msgId = SAIL_UPD_MSG_ID_FIX_GPT;


    DEBUG_LOG(SAIL_WARNING, "%s: FIX_GPT Request MSG params GPT ID=0x%x bufAddr=0x%x bufLen=0x%x \n\r",
              __func__, pReqMsg->fixGpt.id, pReqMsg->fixGpt.bufAddr, pReqMsg->fixGpt.bufLen
              );

    pRspMsg->fixGpt.id = pReqMsg->fixGpt.id;

    /* Initalize SPINOR handle */
    g_SAILUpdaterCoreCtx.norHandle = NULL;
    if(SPINOR_DEVICE_DONE != spinorEl1Open ( &g_SAILUpdaterCoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Spinor Open failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto FixGPTEnd;
    }
    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl1GetMemInfo(g_SAILUpdaterCoreCtx.norHandle, &g_SAILUpdaterCoreCtx.memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Spinor Get Mem Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto FixGPTEnd;
    }

    /* Invalid GPT ID */
    if (pReqMsg->fixGpt.ext_id.id >= SAIL_UPD_GPT_ID_MAX)
    {
        DEBUG_LOG(SAIL_ERROR, "xSAILUpdaterCoreProcessFixGPT: Invalid GPT ID 0x%x\n\r", pReqMsg->fixGpt.ext_id.id);
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

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if (SAIL_OTA_TRIG_ERROR_INVALIDALTGPT_PRE_FIXGPT == g_SAILUpdaterCoreCtx.testcmdID)
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Forced error due to trigger SAIL_OTA_TRIG_ERROR_INVALIDALTGPT_PRE_FIXGPT \n\r", __func__);
        eStatus = SAIL_UPDATER_ALT_GPT_INVALID;
        goto FixGPTEnd;
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    if( SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(ulAltGptId, &xAltGPTHdr, &chkGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Alt GPT header read Failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto FixGPTEnd;
    }

    if ((0 == chkGPTparam.EntryCrcStatus) || (0 == chkGPTparam.HeaderCrcStatus))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Alt GPT header Invalid HeaderCRC=0x%x EntryCRC=0x%x HeaderCrcStatus=0x%x EntryCrcStatus=0x%x\n\r",
                  xAltGPTHdr.header_crc32, xAltGPTHdr.partition_entries_crc32,chkGPTparam.HeaderCrcStatus, chkGPTparam.EntryCrcStatus);
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
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Unaligned Buffer Size 0x%x\n\r", pReqMsg->fixGpt.bufLen);
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
    result = spinorEl1Erase (g_SAILUpdaterCoreCtx.norHandle, destHdrLba, 1);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Erase Destination GPT Header failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto FixGPTEnd;
    }

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if (SAIL_OTA_TRIG_ERROR_ER_GPTHDR_FIXGPT == g_SAILUpdaterCoreCtx.testcmdID)
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Forced crash due to trigger SAIL_OTA_TRIG_ERROR_ER_GPTHDR_FIXGPT \n\r", __func__);
        err_fatal(SAIL_UPDATER,ERR_FATAL_FORCED_REBOOT);
    }
    if (SAIL_OTA_TRIG_ERROR_ER_GPTENTRY_FIXGPT == g_SAILUpdaterCoreCtx.testcmdID)
    {
        /* Erase only 1 4k block */
        partition_entry_size = 1;
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    /* Erase the Destination GPT partition entries */
    result = spinorEl1Erase (g_SAILUpdaterCoreCtx.norHandle, partition_entry_offset, partition_entry_size);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Erase GPT Partition entries failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto FixGPTEnd;
    }

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if (SAIL_OTA_TRIG_ERROR_ER_GPTENTRY_FIXGPT == g_SAILUpdaterCoreCtx.testcmdID)
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Forced crash due to trigger SAIL_OTA_TRIG_ERROR_ER_GPTENTRY_FIXGPT \n\r", __func__);
        err_fatal(SAIL_UPDATER,ERR_FATAL_FORCED_REBOOT);
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    block_size = g_SAILUpdaterCoreCtx.memInfo.pages_per_block * g_SAILUpdaterCoreCtx.memInfo.page_size_bytes;

    /* copy into max 4k chunks in to local work buffer and then write so that the buffer address is aligned */
    num_bytes = ulEntrySz;

    srcAddr = bufAddrToUse + chkGPTparam.GptSize;
    partitionOffsetAddr = partition_entry_offset * block_size;

    while (num_bytes)
    {
        max_transfersize = (num_bytes <= ARRAY_LENGTH(gSAILUpdatergptWorkBuf))?num_bytes:ARRAY_LENGTH(gSAILUpdatergptWorkBuf);

        /* Copy the entries from workbuffer to local buffers */
        result = sailbsp_memscpy(g_SAILUpdaterCoreCtx.pGPTWorkBuf, max_transfersize, (const void *)srcAddr, max_transfersize);
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
                memset(g_SAILUpdaterCoreCtx.pGPTWorkBuf + num_bytes, 0xFF, (max_transfersize - num_bytes));
            }
            num_bytes -= num_bytes;
        }
        else
        {
            num_bytes -= max_transfersize;
        }

        /* Flush and Invalidate the cache for the local buffer containing the destination content */
        clean_invalidate_cache_by_range((uint32)g_SAILUpdaterCoreCtx.pGPTWorkBuf, (uint32)g_SAILUpdaterCoreCtx.pGPTWorkBuf + max_transfersize);

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
        if (SAIL_OTA_TRIG_ERROR_WR_GPTENTRY_FIXGPT == g_SAILUpdaterCoreCtx.testcmdID)
        {
            /* set the write transfer size to SPINOR_BYTES_ALIGNMENT*5 bytes so that it is less than 1 partition entry and aligned*/
            max_transfersize = SPINOR_BYTES_ALIGNMENT*5;
        }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

        /* Write the Destination GPT partition entries */
        result = spinorEl1Write ( g_SAILUpdaterCoreCtx.norHandle, partitionOffsetAddr, max_transfersize, (void *)g_SAILUpdaterCoreCtx.pGPTWorkBuf );
        if( result != SPINOR_DEVICE_DONE )
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Write partition entries failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
            goto FixGPTEnd;
        }
        partitionOffsetAddr += max_transfersize;

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
        if (SAIL_OTA_TRIG_ERROR_WR_GPTENTRY_FIXGPT == g_SAILUpdaterCoreCtx.testcmdID)
        {
            DEBUG_LOG(SAIL_ERROR,"%s: Forced crash due to trigger SAIL_OTA_TRIG_ERROR_WR_GPTENTRY_FIXGPT \n\r", __func__);
            err_fatal(SAIL_UPDATER,ERR_FATAL_FORCED_REBOOT);
        }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED
    }

    /* clear the buffers */
    memset( (void *)bufAddrToUse, 0, pReqMsg->fixGpt.bufLen);

    /* Flush and invalidate the cache */
    clean_invalidate_cache_by_range((uint32)bufAddrToUse, (uint32)bufAddrToUse + pReqMsg->fixGpt.bufLen);

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if (SAIL_OTA_TRIG_ERROR_WR_GPTHDR_FIXGPT == g_SAILUpdaterCoreCtx.testcmdID)
    {
        /* swap bits the CRC*/
        xGptHdr.header_crc32 = ~xGptHdr.header_crc32;
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    /* Copy the GPT header from temp location to Destination buffer */
    result = sailbsp_memscpy( (void *)g_SAILUpdaterCoreCtx.pGPTWorkBuf, sizeof(gptHeader_t), &xGptHdr, sizeof(gptHeader_t));
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
        memset((void *)(g_SAILUpdaterCoreCtx.pGPTWorkBuf + sizeof(gptHeader_t)), 0xFF, (ulWriteSz - sizeof(gptHeader_t)));
    }

    /* Flush and Invalidate the cache for the address containing the destination content */
    clean_invalidate_cache_by_range((uint32) g_SAILUpdaterCoreCtx.pGPTWorkBuf, (uint32)g_SAILUpdaterCoreCtx.pGPTWorkBuf + ulWriteSz);

    block_size = g_SAILUpdaterCoreCtx.memInfo.pages_per_block * g_SAILUpdaterCoreCtx.memInfo.page_size_bytes;

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if (SAIL_OTA_TRIG_ERROR_WR_GPTHDR_FIXGPT == g_SAILUpdaterCoreCtx.testcmdID)
    {
        /* set the write transfer size to SPINOR_BYTES_ALIGNMENT*5 bytes so that it is less than 1 gpt header size and aligned*/
        ulWriteSz = SPINOR_BYTES_ALIGNMENT*5;
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    /* Write the Destination GPT header */
    result = spinorEl1Write ( g_SAILUpdaterCoreCtx.norHandle, destHdrLba * block_size, ulWriteSz, (void *)g_SAILUpdaterCoreCtx.pGPTWorkBuf);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Write partition entries failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto FixGPTEnd;
    }

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if (SAIL_OTA_TRIG_ERROR_WR_GPTHDR_FIXGPT == g_SAILUpdaterCoreCtx.testcmdID)
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Forced crash due to trigger SAIL_OTA_TRIG_ERROR_WR_GPTHDR_FIXGPT \n\r", __func__);
        err_fatal(SAIL_UPDATER,ERR_FATAL_FORCED_REBOOT);
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    /* Verify the new destination GPT */
    if (SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(pReqMsg->fixGpt.ext_id.id, &xGptHdr, &chkDestGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Verify destination header read failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto FixGPTEnd;
    }

    if ((0 == chkDestGPTparam.EntryCrcStatus) || (0 == chkDestGPTparam.HeaderCrcStatus) || (chkDestGPTparam.GptSize != chkGPTparam.GptSize))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Destination GPT header Invalid HeaderCRC=0x%x EntryCRC=0x%x HeaderCrcStatus=0x%x EntryCrcStatus=0x%x\n\r",
                  xGptHdr.header_crc32, xGptHdr.partition_entries_crc32,chkDestGPTparam.HeaderCrcStatus, chkDestGPTparam.EntryCrcStatus);
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto FixGPTEnd;
    }

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if (SAIL_OTA_TRIG_ERROR_INVALIDGPT_POST_FIXGPT == g_SAILUpdaterCoreCtx.testcmdID)
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Forced error due to trigger SAIL_OTA_TRIG_ERROR_INVALIDGPT_POST_FIXGPT \n\r", __func__);
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto FixGPTEnd;
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    /* If the fix type is 0, change state to OTA_DISABLED if current OTA state is not in IN_PROGRESS and not in UPDATE_START */
    if (pReqMsg->fixGpt.ext_id.fixtype == 0)
    {
        /*Read the Devicetree to check if book keep is enabled*/
        if(g_SAILUpdaterCoreCtx.bookKeepEnable)
        {

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
            if (SAIL_OTA_TRIG_ERROR_PRE_OTADDISABLED_FIXGPT == g_SAILUpdaterCoreCtx.testcmdID)
            {
                DEBUG_LOG(SAIL_ERROR,"%s: Forced crash due to trigger SAIL_OTA_TRIG_ERROR_PRE_OTADDISABLED_FIXGPT \n\r", __func__);
                err_fatal(SAIL_UPDATER,ERR_FATAL_FORCED_REBOOT);
            }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

            /*Get Ota Status*/
            if(SAIL_UPDATER_STATUS_SUCCESS != xSAILUpdaterGetOtaStatus(g_SAILUpdaterCoreCtx.norHandle, &xOtaStatus, &guidMap))
            {
                DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: xSAILUpdaterGetOtaStatus Failed \n\r");
                eStatus =  SAIL_UPDATER_STATUS_FAIL;
                goto FixGPTEnd;
            }

            /*- Do not move to OTA_DISABLED, during update GPT or Flashing we want the previous status,
                In all other cases i.e. oem initiated rollback or successfull ota, we can clear book keeping update to OTA disabled */
            if ((xOtaStatus == OTA_UPDATE_START) || (xOtaStatus == OTA_IN_PROGRESS))
            {
                /*Do Nothing*/
            }
            else
            {
                if(SAIL_UPDATER_STATUS_SUCCESS != xSAILUpdaterSetOtaStatus(g_SAILUpdaterCoreCtx.norHandle, OTA_DISABLED))
                {
                    DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: xSAILUpdaterSetOtaStatus failed \n\r");
                    eStatus = SAIL_UPDATER_STATUS_FAIL;
                    goto FixGPTEnd;
                }
            }
        }
    }

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
            if (SAIL_OTA_TRIG_ERROR_POST_FIXGPT == g_SAILUpdaterCoreCtx.testcmdID)
            {
                DEBUG_LOG(SAIL_ERROR,"%s: Forced crash due to trigger SAIL_OTA_TRIG_ERROR_POST_FIXGPT \n\r", __func__);
                err_fatal(SAIL_UPDATER,ERR_FATAL_FORCED_REBOOT);
            }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    pRspMsg->status = SAIL_UPDATER_STATUS_SUCCESS;

FixGPTEnd:

    DEBUG_LOG(SAIL_WARNING, "%s: FIX_GPT Response MSG params GPT ID=0x%x bufAddr=0x%x bufLen=0x%x \n\r",
              __func__, pRspMsg->fixGpt.id, pRspMsg->fixGpt.bufAddr, pRspMsg->fixGpt.bufLen
              );

    if (g_SAILUpdaterCoreCtx.norHandle != NULL)
    {
        /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl1Close ( g_SAILUpdaterCoreCtx.norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessFixGPT: Spinor Close failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        }
        g_SAILUpdaterCoreCtx.norHandle = NULL;
    }
    return eStatus;
}

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

    DEBUG_LOG(SAIL_WARNING, "%s: UPDATE_GPT Request MSG params GPT ID=0x%x num_partitions=0x%x bufAddr=0x%x bufLen=0x%x bufCrc=0x%x \n\r",
              __func__, pReqMsg->updateGpt.id, pReqMsg->updateGpt.num, pReqMsg->updateGpt.bufAddr, pReqMsg->updateGpt.bufLen, pReqMsg->updateGpt.bufCrc
              );

    pRspMsg->updateGpt.id = pReqMsg->updateGpt.id;
    pRspMsg->updateGpt.num = pReqMsg->updateGpt.num;

    /* Initalize SPINOR handle */
    g_SAILUpdaterCoreCtx.norHandle = NULL;
    if(SPINOR_DEVICE_DONE != spinorEl1Open ( &g_SAILUpdaterCoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Spinor Open failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto UpdateGPTEnd;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl1GetMemInfo(g_SAILUpdaterCoreCtx.norHandle, &g_SAILUpdaterCoreCtx.memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Spinor Get Mem Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto UpdateGPTEnd;
    }

    /* Error if the GPT is not primary */
    if (pReqMsg->updateGpt.id != SAIL_UPD_GPT_ID_PRIMARY)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Invalid GPT ID 0x%x\n\r", pReqMsg->updateGpt.id);
        eStatus = SAIL_UPDATER_INVALID_GPT_ID;
        goto UpdateGPTEnd;
    }

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if (SAIL_OTA_TRIG_ERROR_INVALIDALTGPT_PRE_UPDATEGPT == g_SAILUpdaterCoreCtx.testcmdID)
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Forced error due to trigger SAIL_OTA_TRIG_ERROR_INVALIDALTGPT_PRE_UPDATEGPT \n\r", __func__);
        eStatus = SAIL_UPDATER_ALT_GPT_INVALID;
        goto UpdateGPTEnd;
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    /* Verify the alternate GPT */
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

    if (pReqMsg->updateGpt.num > ARRAY_LENGTH(cSAILUpdaterFlashImglist))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Invalid number of Images 0x%x \n\r", pReqMsg->updateGpt.num);
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
    if (pReqMsg->updateGpt.bufLen <  ((pReqMsg->updateGpt.num * sizeof(sailUpdaterMsgUpdateGptEntryType)) + 24*1024))
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
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Invalid Buffer CRC calculated 0x%x Received 0x%x\n\r", pReqMsg->updateGpt.bufCrc, temp_crc);
        eStatus = SAIL_UPDATER_INVALID_BUF_CRC;
        goto UpdateGPTEnd;
    }

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if (SAIL_OTA_TRIG_ERROR_INVALIDGPT_PRE_UPDATEGPT == g_SAILUpdaterCoreCtx.testcmdID)
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Forced error due to trigger SAIL_OTA_TRIG_ERROR_INVALIDGPT_PRE_UPDATEGPT \n\r", __func__);
        eStatus = SAIL_UPDATER_GPT_INVALID;
        goto UpdateGPTEnd;
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    /* Check the GPT health of Primary GPT */
    if (SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(SAIL_UPD_GPT_ID_PRIMARY, &xGPTHdr, &xPrimaryGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Getting Primary GPT health failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto UpdateGPTEnd;
    }

    if( (0 == xPrimaryGPTparam.HeaderCrcStatus) || (0 == xPrimaryGPTparam.EntryCrcStatus) )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Primary GPT Invalid HeaderCRC=0x%x EntryCRC=0x%x HeaderCrcStatus=0x%x EntryCrcStatus=0x%x\n\r",
                  xGPTHdr.header_crc32, xGPTHdr.partition_entries_crc32,xPrimaryGPTparam.HeaderCrcStatus, xPrimaryGPTparam.EntryCrcStatus);
        eStatus = SAIL_UPDATER_GPT_INVALID;
        goto UpdateGPTEnd;
    }

    /*Read the Devicetree to check if book keep is enabled*/
    if(g_SAILUpdaterCoreCtx.bookKeepEnable)
    {
        /* Write to reboot ctrl partition*/
        /*Update the writes with reboot ctrl data -- start*/
        if(SAIL_UPDATER_STATUS_SUCCESS !=  xSAILUpdaterSetOtaStatus(g_SAILUpdaterCoreCtx.norHandle, OTA_UPDATE_START))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: ulSAILUpdaterCoreOtaStatusWrite failed \n\r");
            eStatus = SAIL_UPDATER_STATUS_FAIL;
            goto UpdateGPTEnd;
        }
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

    for (i=0;i < ARRAY_LENGTH(cSAILUpdaterFlashImglist);i++)
    {
        /* Get the GUID A for the Image */
        if (XBL_SUCCESS != sailEl1XblGetImgGUID((const char *)cSAILUpdaterFlashImglist[i], XBL_PARTITION_A, pReqMsg->updateGpt.id, imgGuid_A))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Error Getting Image GUID A \n\r");
            eStatus = SAIL_UPDATER_STATUS_FAIL;
            goto UpdateGPTEnd;
        }

        if (XBL_SUCCESS != sailEl1XblGetImgGUID((const char *)cSAILUpdaterFlashImglist[i], XBL_PARTITION_B, pReqMsg->updateGpt.id, imgGuid_B))
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
    }

    ulEntrySz  = xGPTHdr.size_of_partition_entry * xGPTHdr.number_of_partition_entries;

    /* Flush and Invalidate the cache for the address containing the destination content */
    clean_invalidate_cache_by_range((uint32) workBufAddr, (uint32)workBufAddr + ulEntrySz);

    /* Calcuate the buffer offsets for the destination from the GPT header */
    destHdrLba = xGPTHdr.my_lba;

    /* Erase the Destination GPT header */
    result = spinorEl1Erase (g_SAILUpdaterCoreCtx.norHandle, destHdrLba, 1);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Erase Destination GPT Header failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto UpdateGPTEnd;
    }

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if (SAIL_OTA_TRIG_ERROR_ER_GPTHDR_UPDATEGPT == g_SAILUpdaterCoreCtx.testcmdID)
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Forced crash due to trigger SAIL_OTA_TRIG_ERROR_ER_GPTHDR_UPDATEGPT \n\r", __func__);
        err_fatal(SAIL_UPDATER,ERR_FATAL_FORCED_REBOOT);
    }
    if (SAIL_OTA_TRIG_ERROR_ER_GPTENTRY_UPDATEGPT == g_SAILUpdaterCoreCtx.testcmdID)
    {
        /* Erase only 1 4k block */
        xGPTHdr.partition_entry_lba = xGPTHdr.first_usable_lba - 1;
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    /* Erase the Destination GPT partition entries */
    result = spinorEl1Erase(g_SAILUpdaterCoreCtx.norHandle, xGPTHdr.partition_entry_lba, xGPTHdr.first_usable_lba - xGPTHdr.partition_entry_lba);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Erase GPT Partition entries failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto UpdateGPTEnd;
    }

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if (SAIL_OTA_TRIG_ERROR_ER_GPTENTRY_UPDATEGPT == g_SAILUpdaterCoreCtx.testcmdID)
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Forced crash due to trigger SAIL_OTA_TRIG_ERROR_ER_GPTENTRY_UPDATEGPT \n\r", __func__);
        err_fatal(SAIL_UPDATER,ERR_FATAL_FORCED_REBOOT);
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    block_size = g_SAILUpdaterCoreCtx.memInfo.pages_per_block * g_SAILUpdaterCoreCtx.memInfo.page_size_bytes;

    /* copy into max 4k chunks in to local work buffer and then write so that the buffer address is aligned */
    num_bytes = ulEntrySz;

    srcAddr = workBufAddr;
    partitionOffsetAddr = xGPTHdr.partition_entry_lba * block_size;

    while (num_bytes)
    {
        max_transfersize = (num_bytes <= ARRAY_LENGTH(gSAILUpdatergptWorkBuf))?num_bytes:ARRAY_LENGTH(gSAILUpdatergptWorkBuf);

        /* Copy the entries from workbuffer to local buffers */
        result = sailbsp_memscpy(g_SAILUpdaterCoreCtx.pGPTWorkBuf, max_transfersize, (const void *) srcAddr, max_transfersize);
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
                memset(g_SAILUpdaterCoreCtx.pGPTWorkBuf + num_bytes, 0xFF, (max_transfersize - num_bytes));
            }
            num_bytes -= num_bytes;
        }
        else
        {
            num_bytes -= max_transfersize;
        }

        /* Flush and Invalidate the cache for the local buffer containing the destination content */
        clean_invalidate_cache_by_range((uint32)g_SAILUpdaterCoreCtx.pGPTWorkBuf, (uint32)g_SAILUpdaterCoreCtx.pGPTWorkBuf + max_transfersize);

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
        if (SAIL_OTA_TRIG_ERROR_WR_GPTENTRY_UPDATEGPT == g_SAILUpdaterCoreCtx.testcmdID)
        {
            /* set the write transfer size to SPINOR_BYTES_ALIGNMENT*5 bytes so that it is less than 1 partition entry and aligned*/
            max_transfersize = SPINOR_BYTES_ALIGNMENT*5;
        }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

        /* Write the Destination GPT partition entries */
        result = spinorEl1Write ( g_SAILUpdaterCoreCtx.norHandle, partitionOffsetAddr, max_transfersize, (void *)g_SAILUpdaterCoreCtx.pGPTWorkBuf );
        if( result != SPINOR_DEVICE_DONE )
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Write partition entries failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
            goto UpdateGPTEnd;
        }
        partitionOffsetAddr += max_transfersize;

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
        if (SAIL_OTA_TRIG_ERROR_WR_GPTENTRY_UPDATEGPT == g_SAILUpdaterCoreCtx.testcmdID)
        {
            DEBUG_LOG(SAIL_ERROR,"%s: Forced crash due to trigger SAIL_OTA_TRIG_ERROR_WR_GPTENTRY_UPDATEGPT \n\r", __func__);
            err_fatal(SAIL_UPDATER,ERR_FATAL_FORCED_REBOOT);
        }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED
    }

    /* Calculate partition entries CRC */
    crc = gptCalcCRC32 ((const uint8_t *)workBufAddr, ulEntrySz, GPT_CRC32_SEED_DEFAULT);

    /* Update the partition CRC in the GPT header */
    xGPTHdr.partition_entries_crc32 = crc;

    /* Calculate the new Header CRC */
    xGPTHdr.header_crc32 = 0;

    crc = gptCalcCRC32((const uint8_t *)&xGPTHdr, xGPTHdr.header_size, GPT_CRC32_SEED_DEFAULT);

    xGPTHdr.header_crc32 = crc;

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if (SAIL_OTA_TRIG_ERROR_WR_GPTHDR_UPDATEGPT == g_SAILUpdaterCoreCtx.testcmdID)
    {
        /* swap bits the CRC*/
        xGPTHdr.header_crc32 = ~xGPTHdr.header_crc32;
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    /* Copy the GPT header to Destination buffer that can accommodate extra bytes for taking care of padding for alignment */
    result = sailbsp_memscpy(g_SAILUpdaterCoreCtx.pGPTWorkBuf, sizeof(gptHeader_t), &xGPTHdr, sizeof(gptHeader_t));
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
        memset(g_SAILUpdaterCoreCtx.pGPTWorkBuf + sizeof(gptHeader_t), 0xFF, (ulWriteSz - sizeof(gptHeader_t)));
    }

    /* Flush and Invalidate the cache for the address containing the destination content */
    clean_invalidate_cache_by_range((uint32)g_SAILUpdaterCoreCtx.pGPTWorkBuf, (uint32)g_SAILUpdaterCoreCtx.pGPTWorkBuf + ulWriteSz);

    block_size = g_SAILUpdaterCoreCtx.memInfo.pages_per_block * g_SAILUpdaterCoreCtx.memInfo.page_size_bytes;

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if (SAIL_OTA_TRIG_ERROR_WR_GPTHDR_UPDATEGPT == g_SAILUpdaterCoreCtx.testcmdID)
    {
        /* set the write transfer size to SPINOR_BYTES_ALIGNMENT*5 bytes so that it is less than 1 gpt header size and aligned*/
        ulWriteSz = SPINOR_BYTES_ALIGNMENT*5;
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    /* Write the Destination GPT header */
    result = spinorEl1Write ( g_SAILUpdaterCoreCtx.norHandle, destHdrLba * block_size, ulWriteSz, (void *)g_SAILUpdaterCoreCtx.pGPTWorkBuf);
    if( result != SPINOR_DEVICE_DONE )
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Write partition entries failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto UpdateGPTEnd;
    }

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if (SAIL_OTA_TRIG_ERROR_WR_GPTHDR_UPDATEGPT == g_SAILUpdaterCoreCtx.testcmdID)
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Forced crash due to trigger SAIL_OTA_TRIG_ERROR_WR_GPTHDR_UPDATEGPT \n\r", __func__);
        err_fatal(SAIL_UPDATER,ERR_FATAL_FORCED_REBOOT);
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    /* Verify the new destination GPT */
    if (SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(pReqMsg->updateGpt.id, &xGPTHdr, &chkDestGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Verify destination header read failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto UpdateGPTEnd;
    }

    if ((0 == chkDestGPTparam.EntryCrcStatus) || (0 == chkDestGPTparam.HeaderCrcStatus) || (chkDestGPTparam.GptSize != xPrimaryGPTparam.GptSize))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Destination GPT header Invalid HeaderCRC=0x%x EntryCRC=0x%x HeaderCrcStatus=0x%x EntryCrcStatus=0x%x\n\r",
                  xGPTHdr.header_crc32, xGPTHdr.partition_entries_crc32,chkDestGPTparam.HeaderCrcStatus, chkDestGPTparam.EntryCrcStatus);
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto UpdateGPTEnd;
    }

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if (SAIL_OTA_TRIG_ERROR_POST_UPDATEGPT == g_SAILUpdaterCoreCtx.testcmdID)
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Forced crash due to trigger SAIL_OTA_TRIG_ERROR_POST_UPDATEGPT \n\r", __func__);
        err_fatal(SAIL_UPDATER,ERR_FATAL_FORCED_REBOOT);
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    pRspMsg->status = SAIL_UPDATER_STATUS_SUCCESS;

UpdateGPTEnd:
    DEBUG_LOG(SAIL_WARNING, "%s: UPDATE_GPT Response MSG params GPT ID=0x%x num_partitions=0x%x bufAddr=0x%x bufLen=0x%x bufCrc=0x%x \n\r",
              __func__, pRspMsg->updateGpt.id, pRspMsg->updateGpt.num, pRspMsg->updateGpt.bufAddr, pRspMsg->updateGpt.bufLen, pRspMsg->updateGpt.bufCrc
              );

    if (g_SAILUpdaterCoreCtx.norHandle != NULL)
    {
        /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl1Close ( g_SAILUpdaterCoreCtx.norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateGPT: Spinor Close failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        }
        g_SAILUpdaterCoreCtx.norHandle = NULL;
    }
    return eStatus;
}

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

    DEBUG_LOG(SAIL_WARNING, "%s: QUERY_IMAGES Request MSG params num_images=0x%x bufAddr=0x%x bufLen=0x%x bufCrc=0x%x \n\r",
              __func__, pReqMsg->queryImg.num_images, pReqMsg->queryImg.bufAddr, pReqMsg->queryImg.bufLen, pReqMsg->queryImg.bufCrc
              );

    /* Initalize SPINOR handle */
    g_SAILUpdaterCoreCtx.norHandle = NULL;
    if(SPINOR_DEVICE_DONE != spinorEl1Open ( &g_SAILUpdaterCoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Spinor Open failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessQueryImgEnd;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl1GetMemInfo(g_SAILUpdaterCoreCtx.norHandle, &g_SAILUpdaterCoreCtx.memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Spinor Get Mem Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessQueryImgEnd;
    }

    if (pReqMsg->queryImg.num_images > ARRAY_LENGTH(cSAILUpdaterFlashImglist))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Invalid number of Images 0x%x\n\r", pReqMsg->queryImg.num_images);
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
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Invalid Buffer CRC calculated 0x%x Received 0x%x\n\r", pReqMsg->queryImg.bufCrc, temp_crc);
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
    if (SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(SAIL_UPD_GPT_ID_PRIMARY, &g_SAILUpdaterCoreCtx.PrimaryGPTHdr, &xPrimaryGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Getting Primary GPT health failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessQueryImgEnd;
    }

    /* Check the GPT health of Secondary GPT */
    if (SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(SAIL_UPD_GPT_ID_SECONDARY, &g_SAILUpdaterCoreCtx.SecondaryGPTHdr, &xSecondaryGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Getting Secondary GPT health failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessQueryImgEnd;
    }

    /* Get the boot info from XBL. Need to pass in array size */
    if (sailEl1XblGetBootInfo(xBootInfo, XBL_IMAGE_ID_MAX))
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
                if(sailEl1XblGetImgGUID((const char *)pImgEntry->imgName, XBL_PARTITION_A, bootGPTID, imgGuid_A))
                {
                    DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Get Image GUID_A failed \n\r");
                    eStatus = SAIL_UPDATER_STATUS_FAIL;
                    goto ProcessQueryImgEnd;
                }

                if(sailEl1XblGetImgGUID((const char *)pImgEntry->imgName, XBL_PARTITION_B, bootGPTID, imgGuid_B))
                {
                    DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Get Image GUID_B failed \n\r");
                    eStatus = SAIL_UPDATER_STATUS_FAIL;
                    goto ProcessQueryImgEnd;
                }

                /* Read both the GPT headers */
                /* If the Primary GPT is valid, get the Primary GPT header and read the partition info from it */
                if( (1 == xPrimaryGPTparam.HeaderCrcStatus) && (1 == xPrimaryGPTparam.EntryCrcStatus) )
                {
                    if( SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterGetGPTHdr(SAIL_UPD_GPT_ID_PRIMARY, &g_SAILUpdaterCoreCtx.PrimaryGPTHdr) )
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
                    if(FALSE == bPrvSAILUpdaterGPTGetPartitionInfo (&g_SAILUpdaterCoreCtx.PrimaryGPTHdr, &tmpGuidA, &partitionAddrA_1, &partitionSizeA_1, &pulIndex ))
                    {
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Get Partition Info from Primary GPT for Image GUID_A failed \n\r");
                        eStatus = SAIL_UPDATER_STATUS_FAIL;
                        goto ProcessQueryImgEnd;
                    }

                    if(FALSE == bPrvSAILUpdaterGPTGetPartitionInfo (&g_SAILUpdaterCoreCtx.PrimaryGPTHdr, &tmpGuidB, &partitionAddrB_1, &partitionSizeB_1, &pulIndex ))
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
                    if (SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterGetGPTHdr(SAIL_UPD_GPT_ID_SECONDARY, &g_SAILUpdaterCoreCtx.SecondaryGPTHdr))
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
                    if (FALSE == bPrvSAILUpdaterGPTGetPartitionInfo(&g_SAILUpdaterCoreCtx.SecondaryGPTHdr, &tmpGuidA, &partitionAddrA_2, &partitionSizeA_2, &pulIndex))
                    {
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Get Partition Info from Secondary GPT for Image GUID_A failed \n\r");
                        eStatus = SAIL_UPDATER_STATUS_FAIL;
                        goto ProcessQueryImgEnd;
                    }

                    if(FALSE == bPrvSAILUpdaterGPTGetPartitionInfo (&g_SAILUpdaterCoreCtx.SecondaryGPTHdr, &tmpGuidB, &partitionAddrB_2, &partitionSizeB_2, &pulIndex))
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
    DEBUG_LOG(SAIL_WARNING, "%s: QUERY_IMAGES Response MSG params num_images=0x%x bufAddr=0x%x bufLen=0x%x bufCrc=0x%x \n\r",
              __func__, pRspMsg->queryImg.num_images, pRspMsg->queryImg.bufAddr, pRspMsg->queryImg.bufLen, pRspMsg->queryImg.bufCrc
              );

    if (g_SAILUpdaterCoreCtx.norHandle != NULL)
    {
        /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl1Close ( g_SAILUpdaterCoreCtx.norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessQueryImg: Spinor Close failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        }
        g_SAILUpdaterCoreCtx.norHandle = NULL;
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
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessGetBootInfo(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg)
{
    SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;
    SAILUpdaterStatusType_e result;
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

    SAILUpdaterOTAStateValType xOtaState = { 0 };
    uint8_t guidMap = 0;


    pRspMsg->msgId = SAIL_UPD_MSG_ID_GET_BOOTINFO;

    DEBUG_LOG(SAIL_WARNING, "%s: GET_BOOTINFO Request MSG params primaryGptHeaderCrcStatus=0x%x primaryGptEntryCrcStatus=0x%x primaryGptSize=0x%x secondaryGptHeaderCrcStatus=0x%x secondaryGptEntryCrcStatus=0x%x secondaryGptSize=0x%x \n\r \
              num_images=0x%x bufAddr=0x%x bufLen=0x%x bufCrc=0x%x \n\r",
              __func__, pReqMsg->bootInfo.primaryGptHeaderCrcStatus, pReqMsg->bootInfo.primaryGptEntryCrcStatus, pReqMsg->bootInfo.primaryGptSize,
              pReqMsg->bootInfo.secondaryGptHeaderCrcStatus, pReqMsg->bootInfo.secondaryGptEntryCrcStatus, pReqMsg->bootInfo.secondaryGptSize,
              pReqMsg->bootInfo.imgInfo.num_images, pReqMsg->bootInfo.imgInfo.bufAddr, pReqMsg->bootInfo.imgInfo.bufLen, pReqMsg->bootInfo.imgInfo.bufCrc
              );

    /* Initalize SPINOR handle */
    g_SAILUpdaterCoreCtx.norHandle = NULL;
    if(SPINOR_DEVICE_DONE != spinorEl1Open ( &g_SAILUpdaterCoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Spinor Open failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessBootInfoEnd;
    }

    /* Get SPINOR memory Info */
    if (SPINOR_DEVICE_DONE != spinorEl1GetMemInfo(g_SAILUpdaterCoreCtx.norHandle, &g_SAILUpdaterCoreCtx.memInfo))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Spinor Get Mem Info failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto ProcessBootInfoEnd;
    }

    if (pReqMsg->bootInfo.imgInfo.num_images > ARRAY_LENGTH(cSAILUpdaterFlashImglist))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Invalid number of Images 0x%x \n\r", pReqMsg->bootInfo.imgInfo.num_images);
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
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Invalid Buffer Size 0x%x \n\r", pReqMsg->bootInfo.imgInfo.bufLen );
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
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Invalid Buffer CRC calculated 0x%x Received 0x%x \n\r", pReqMsg->bootInfo.imgInfo.bufCrc , temp_crc);
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
    if (SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(SAIL_UPD_GPT_ID_PRIMARY, &g_SAILUpdaterCoreCtx.PrimaryGPTHdr, &xPrimaryGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Getting Primary GPT health failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessBootInfoEnd;
    }

    /* Check the GPT health of Secondary GPT */
    if (SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterVerifyGPT(SAIL_UPD_GPT_ID_SECONDARY, &g_SAILUpdaterCoreCtx.SecondaryGPTHdr, &xSecondaryGPTparam))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Getting Secondary GPT health failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto ProcessBootInfoEnd;
    }

    /* Get the boot info from XBL. Need to pass in array size */
    if (sailEl1XblGetBootInfo(xBootInfo, XBL_IMAGE_ID_MAX))
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
                if(sailEl1XblGetImgGUID((const char *)pImgEntry->imgName, XBL_PARTITION_A, bootGPTID, imgGuid_A))
                {
                    DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Get Image GUID_A failed \n\r");
                    eStatus = SAIL_UPDATER_STATUS_FAIL;
                    goto ProcessBootInfoEnd;
                }

                if(sailEl1XblGetImgGUID((const char *)pImgEntry->imgName, XBL_PARTITION_B, bootGPTID, imgGuid_B))
                {
                    DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Get Image GUID_B failed \n\r");
                    eStatus = SAIL_UPDATER_STATUS_FAIL;
                    goto ProcessBootInfoEnd;
                }

                /* Read both the GPT headers */

                /* If the Primary GPT is valid, get the Primary GPT header and read the partition info from it */
                if( (1 == xPrimaryGPTparam.HeaderCrcStatus) && (1 == xPrimaryGPTparam.EntryCrcStatus) )
                {
                    if( SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterGetGPTHdr(SAIL_UPD_GPT_ID_PRIMARY, &g_SAILUpdaterCoreCtx.PrimaryGPTHdr) )
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
                    if(FALSE == bPrvSAILUpdaterGPTGetPartitionInfo (&g_SAILUpdaterCoreCtx.PrimaryGPTHdr, &tmpGuidA, &partitionAddrA_1, &partitionSizeA_1, &pulIndex ))
                    {
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Get Partition Info from Primary GPT for Image GUID_A failed \n\r");
                        eStatus = SAIL_UPDATER_STATUS_FAIL;
                        goto ProcessBootInfoEnd;
                    }

                    if(FALSE == bPrvSAILUpdaterGPTGetPartitionInfo (&g_SAILUpdaterCoreCtx.PrimaryGPTHdr, &tmpGuidB, &partitionAddrB_1, &partitionSizeB_1, &pulIndex ))
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
                    if (SAIL_UPDATER_SUCCESS != ePrvSAILUpdaterGetGPTHdr(SAIL_UPD_GPT_ID_SECONDARY, &g_SAILUpdaterCoreCtx.SecondaryGPTHdr))
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
                    if (FALSE == bPrvSAILUpdaterGPTGetPartitionInfo(&g_SAILUpdaterCoreCtx.SecondaryGPTHdr, &tmpGuidA, &partitionAddrA_2, &partitionSizeA_2, &pulIndex))
                    {
                        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Get Partition Info from Secondary GPT for Image GUID_A failed \n\r");
                        eStatus = SAIL_UPDATER_STATUS_FAIL;
                        goto ProcessBootInfoEnd;
                    }

                    if(FALSE == bPrvSAILUpdaterGPTGetPartitionInfo (&g_SAILUpdaterCoreCtx.SecondaryGPTHdr, &tmpGuidB, &partitionAddrB_2, &partitionSizeB_2, &pulIndex ))
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
    pRspMsg->bootInfo.primaryGptPartitionEntryCrc = g_SAILUpdaterCoreCtx.PrimaryGPTHdr.partition_entries_crc32;

    /* Secondary GPT */
    pRspMsg->bootInfo.secondaryGptEntryCrcStatus = xSecondaryGPTparam.EntryCrcStatus;
    pRspMsg->bootInfo.secondaryGptHeaderCrcStatus = xSecondaryGPTparam.HeaderCrcStatus;
    pRspMsg->bootInfo.secondaryGptSize = xSecondaryGPTparam.GptSize;
    pRspMsg->bootInfo.secondaryGptPartitionEntryCrc = g_SAILUpdaterCoreCtx.SecondaryGPTHdr.partition_entries_crc32;

    /* Copy the number of images from Req to Resp Msg */
    pRspMsg->bootInfo.imgInfo.num_images = pReqMsg->bootInfo.imgInfo.num_images;

    /* Copy Buffer Address and Length from the request into the response header */
    pRspMsg->bootInfo.imgInfo.bufAddr = pReqMsg->bootInfo.imgInfo.bufAddr;
    pRspMsg->bootInfo.imgInfo.bufLen = (pRspMsg->bootInfo.imgInfo.num_images * sizeof(sailUpdaterImageEntryType));

    /* Calculate Buffer CRC */
    pRspMsg->bootInfo.imgInfo.bufCrc = 0;
    pRspMsg->bootInfo.imgInfo.bufCrc = ulSAILUpdaterCoreCalcCRC(bufAddrToUse, pRspMsg->bootInfo.imgInfo.bufLen);

    /*Get Ota status and update BootInfo Response*/
    if(SAIL_UPDATER_STATUS_SUCCESS != xSAILUpdaterGetOtaStatus(g_SAILUpdaterCoreCtx.norHandle, &xOtaState, &guidMap))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: xSAILUpdaterGetOtaStatus Failed \n\r");
        eStatus =  SAIL_UPDATER_STATUS_FAIL;
        goto ProcessBootInfoEnd;
    }
    pRspMsg->bootInfo.otaState = (xOtaState)&0x7F;
    pRspMsg->bootInfo.logicGuidASwapped = (guidMap&0x01);

    /* Flush and Invalidate the cache */
    clean_invalidate_cache_by_range((uint32) bufAddrToUse,(uint32)bufAddrToUse +  pRspMsg->bootInfo.imgInfo.bufLen);

    pRspMsg->status = SAIL_UPDATER_STATUS_SUCCESS;

ProcessBootInfoEnd:
    DEBUG_LOG(SAIL_WARNING, "%s: GET_BOOTINFO Response MSG params primaryGptHeaderCrcStatus=0x%x primaryGptEntryCrcStatus=0x%x primaryGptSize=0x%x secondaryGptHeaderCrcStatus=0x%x secondaryGptEntryCrcStatus=0x%x secondaryGptSize=0x%x \n\r \
              num_images=0x%x bufAddr=0x%x bufLen=0x%x bufCrc=0x%x otaState=%d logicGuidASwapped=%d\n\r",
              __func__, pRspMsg->bootInfo.primaryGptHeaderCrcStatus, pRspMsg->bootInfo.primaryGptEntryCrcStatus, pRspMsg->bootInfo.primaryGptSize,
              pRspMsg->bootInfo.secondaryGptHeaderCrcStatus, pRspMsg->bootInfo.secondaryGptEntryCrcStatus, pRspMsg->bootInfo.secondaryGptSize,
              pRspMsg->bootInfo.imgInfo.num_images, pRspMsg->bootInfo.imgInfo.bufAddr, pRspMsg->bootInfo.imgInfo.bufLen, pRspMsg->bootInfo.imgInfo.bufCrc,pRspMsg->bootInfo.otaState,
              pRspMsg->bootInfo.logicGuidASwapped);

    /*Update Invalid OTA state in case of FAIL*/
    if(eStatus != SAIL_UPDATER_STATUS_SUCCESS)
    {
        pRspMsg->bootInfo.otaState = (OTA_INVALID)&0x7F;
        pRspMsg->bootInfo.logicGuidASwapped = 1;

    }
    if (g_SAILUpdaterCoreCtx.norHandle != NULL)
    {
        /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl1Close ( g_SAILUpdaterCoreCtx.norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetBootInfo: Spinor Close failed \n\r");
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        }
        g_SAILUpdaterCoreCtx.norHandle = NULL;
    }
    pImgEntry = NULL;

    return eStatus;
}

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
    return SAIL_UPDATER_STATUS_SUCCESS;
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
    return SAIL_UPDATER_STATUS_SUCCESS;
}

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
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessOTADone(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg)
{

    SAILUpdaterStatusType_e eStatus  = SAIL_UPDATER_STATUS_SUCCESS;

    pRspMsg->msgId = SAIL_UPD_MSG_OTA_DONE;


    DEBUG_LOG(SAIL_WARNING, "%s: OTA_DONE Request MSG  \n\r",__func__);

    /* Open the SPINOR handle handle*/
    if(SPINOR_DEVICE_DONE != spinorEl1Open ( &g_SAILUpdaterCoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessOTADone: Spinor Open failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto OtaDoneEnd;
    }

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if (SAIL_OTA_TRIG_ERROR_PRE_OTADONE == g_SAILUpdaterCoreCtx.testcmdID)
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Forced crash due to trigger SAIL_OTA_TRIG_ERROR_PRE_OTADONE \n\r", __func__);
        err_fatal(SAIL_UPDATER,ERR_FATAL_FORCED_REBOOT);
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    if(SAIL_UPDATER_STATUS_SUCCESS !=  xSAILUpdaterSetOtaStatus(g_SAILUpdaterCoreCtx.norHandle, OTA_DONE))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessOTADone: Set OTA Status failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto OtaDoneEnd;
    }

    pRspMsg->status = SAIL_UPDATER_STATUS_SUCCESS;

OtaDoneEnd:
        DEBUG_LOG(SAIL_WARNING, "%s: OTA_DONE Response MSG \n\r", __func__);

        if (g_SAILUpdaterCoreCtx.norHandle != NULL)
        {
            /* Close SPINOR handle */
            if(SPINOR_DEVICE_DONE != spinorEl1Close ( g_SAILUpdaterCoreCtx.norHandle ))
            {
                DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessOTADone: Spinor Close failed \n\r");
                eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
            }
            g_SAILUpdaterCoreCtx.norHandle = NULL;
        }

        return eStatus;
}

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
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessRedundancy(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg)
{

    SAILUpdaterStatusType_e eStatus  = SAIL_UPDATER_STATUS_SUCCESS;

    pRspMsg->msgId = SAIL_UPD_MSG_REDUNDANCY_ESTABLISHED;


    DEBUG_LOG(SAIL_WARNING, "%s: REDUNDANCY_ESTABLISHED Request MSG  \n\r", __func__);

    /* Open the SPINOR handle handle*/
    if(SPINOR_DEVICE_DONE != spinorEl1Open ( &g_SAILUpdaterCoreCtx.norHandle, SPINOR_USER_TYPE_OTA ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessRedundancy: Spinor Open failed \n\r");
        eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        goto RedundancyEnd;
    }

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED
    if (SAIL_OTA_TRIG_ERROR_PRE_REDUNDANCY == g_SAILUpdaterCoreCtx.testcmdID)
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Forced crash due to trigger SAIL_OTA_TRIG_ERROR_PRE_REDUNDANCY \n\r", __func__);
        err_fatal(SAIL_UPDATER,ERR_FATAL_FORCED_REBOOT);
    }
#endif // SAILUPDATER_INJTEST_SRC_ENABLED

    if(SAIL_UPDATER_STATUS_SUCCESS !=  xSAILUpdaterSetOtaStatus(g_SAILUpdaterCoreCtx.norHandle, OTA_DISABLED))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessRedundancy: Set OTA Status failed \n\r");
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto RedundancyEnd;
    }

    pRspMsg->status = SAIL_UPDATER_STATUS_SUCCESS;

RedundancyEnd:
        DEBUG_LOG(SAIL_WARNING, "%s: REDUNDANCY_ESTABLISHED Response MSG \n\r", __func__);

        if (g_SAILUpdaterCoreCtx.norHandle != NULL)
        {
            /* Close SPINOR handle */
            if(SPINOR_DEVICE_DONE != spinorEl1Close ( g_SAILUpdaterCoreCtx.norHandle ))
            {
                DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessRedundancy: Spinor Close failed \n\r");
                eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
            }
            g_SAILUpdaterCoreCtx.norHandle = NULL;
        }

        return eStatus;
}

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
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessUpdateARB(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg)
{
    uint32_t hvcId     = SAIL_BOOT_ARB_UPDATE_ALL_HVC_ID;
    uint32_t paramId   = SAIL_BOOT_ARB_UPDATE_ALL_PARAM_ID;
    uint32_t arg1      = 0;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;

    pRspMsg->msgId = SAIL_UPD_MSG_ID_UPDATE_ARB;

    if (HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateARB: hvc call SAIL_BOOT_ARB_UPDATE_ALL_HVC_ID Failed \r\n");
        return SAIL_UPDATER_STATUS_FAIL;
    }

    /*Check for return value of HVC call*/
    if(paramId == 0)
    {
        pRspMsg->status = SAIL_UPDATER_STATUS_SUCCESS;
        return SAIL_UPDATER_STATUS_SUCCESS;
    }
    else
    {
        return SAIL_UPDATER_STATUS_FAIL;
    }
}

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
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessUpdateMRC(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg)
{
    uint32_t hvcId     = SAIL_BOOT_MRC_UPDATE_HVC_ID;
    uint32_t paramId   = SAIL_BOOT_MRC_UPDATE_PARAM_ID;
    uint32_t arg1      = 0;
    uint32_t arg2      = 0;
    uint32_t arg3      = 0;
    uint32_t arg4      = 0;

    pRspMsg->msgId = SAIL_UPD_MSG_ID_UPDATE_MRC;

    if (HVC_SUCCESS != hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessUpdateMRC: hvc call SAIL_BOOT_MRC_UPDATE_HVC_ID Failed \r\n");
        return SAIL_UPDATER_STATUS_FAIL;
    }

    /*Check for return value of HVC call*/
    if(paramId == 0)
    {
        pRspMsg->status = SAIL_UPDATER_STATUS_SUCCESS;
        return SAIL_UPDATER_STATUS_SUCCESS;
    }
    else
    {
        return SAIL_UPDATER_STATUS_FAIL;
    }
}

/**********************************************************
 * Process the Get Image Digest double hash
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
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessGetImgDigest(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg)
{
	xbl_digestHashType xbl_digestHash = { 0U };
	SAILUpdaterStatusType_e eStatus = SAIL_UPDATER_STATUS_SUCCESS;
    uint32_t temp_crc = 0U;
	uint32_t bufAddrToUse = pReqMsg->getImgDigest.bufAddr - SAIL_MD_DDR_ADDR_OFFSET;
    pRspMsg->msgId = SAIL_UPD_MSG_GET_IMAGE_DIGEST;

	DEBUG_LOG(SAIL_WARNING, "%s: GET IMAGE DIGEST Request MSG params num_images=0x%x bufAddr=0x%x bufLen=0x%x bufCrc=0x%x \n\r",
				__func__, pReqMsg->getImgDigest.num_images, pReqMsg->getImgDigest.bufAddr, pReqMsg->getImgDigest.bufLen, pReqMsg->getImgDigest.bufCrc
				);
	/* Num images supported */
	if (pReqMsg->getImgDigest.num_images > ARRAY_LENGTH(cSAILUpdaterFlashImglist))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetImgDigest: Invalid number of Images 0x%x \n\r", pReqMsg->getImgDigest.num_images);
        eStatus = SAIL_UPDATER_INVALID_NUM_OF_IMAGES;
        goto ProcessGetImgDigestEnd;
    }
	/* Invalid Buffer Address */
    if ((0U == pReqMsg->getImgDigest.bufAddr) || (0U == bufAddrToUse) ||
        (FALSE == bPrvSAILUpdaterCoreIsAddrInRange(bufAddrToUse, pReqMsg->getImgDigest.bufLen))
		)
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetImgDigest: Invalid Buffer Address \n\r");
        eStatus = SAIL_UPDATER_INVALID_BUF_ADDR;
        goto ProcessGetImgDigestEnd;
    }
    /* Invalid Buffer Size */
    if ((0 == pReqMsg->getImgDigest.bufLen) || (pReqMsg->getImgDigest.bufLen <  (pReqMsg->getImgDigest.num_images * sizeof(sailUpdaterMsgImgDigestEntryType)) ))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetImgDigest: Invalid Buffer Size 0x%x\n\r", pReqMsg->getImgDigest.bufLen);
        eStatus = SAIL_UPDATER_INVALID_BUF_SIZE;
        goto ProcessGetImgDigestEnd;
    }
    /* Copy the current CRC and Calculate Buffer CRC */
    temp_crc = pReqMsg->getImgDigest.bufCrc;
    pReqMsg->getImgDigest.bufCrc = 0;
    pReqMsg->getImgDigest.bufCrc = ulSAILUpdaterCoreCalcCRC(bufAddrToUse, pReqMsg->getImgDigest.bufLen);
    /* Verify Buffer CRC */
    if (TRUE == bPrvSAILUpdaterCoreIsCRCNotMatch(temp_crc, pReqMsg->getImgDigest.bufCrc))
    {
        DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetImgDigest: Invalid Buffer CRC calculated 0x%x Received 0x%x\n\r", pReqMsg->getImgDigest.bufCrc, temp_crc);
        eStatus = SAIL_UPDATER_INVALID_BUF_CRC;
        goto ProcessGetImgDigestEnd;
    }
	/* msg okay */
	sailUpdaterMsgImgDigestEntryType* pDigestEntry = (sailUpdaterMsgImgDigestEntryType*)bufAddrToUse;
	/* get dhsh for each image */
	for(int32_t i= 0; i < pReqMsg->getImgDigest.num_images; i++)
	{
		(void)memset((void *)&pDigestEntry[i].digest[0], 0, SAIL_UPD_IMAGE_DIGEST_MAX_LEN);
		 /* Validate the Image - we will be requetsing either partition image so flash operation */
		if (FALSE == bPrvSAILUpdaterCoreIsValidImg(UPDATER_FLASH_OPERATION, (const char*)&pDigestEntry[i].imgName[0U]))
		{
			DEBUG_LOG(SAIL_ERROR,"xSAILUpdaterCoreProcessGetImgDigest: Invalid Image'%d' name \n\r", i);
			eStatus = SAIL_UPDATER_INVALID_IMG_NAME;
			goto ProcessGetImgDigestEnd;
		}
		/* Invalid Partition ID */
		if (pDigestEntry[i].partitionType >= SAIL_UPD_PARTITION_ID_MAX)
		{
			DEBUG_LOG(SAIL_ERROR, "xSAILUpdaterCoreProcessGetImgDigest: Image'%d', Invalid Partition ID 0x%x  \n\r", i, pDigestEntry[i].partitionType);
			eStatus = SAIL_UPDATER_INVALID_PARTITION_ID;
			goto ProcessGetImgDigestEnd;
		}
		/* Invalid length */
		if (pDigestEntry[i].digestLen != SAIL_UPD_IMAGE_DIGEST_MAX_LEN)
		{
			DEBUG_LOG(SAIL_ERROR, "xSAILUpdaterCoreProcessGetImgDigest: Image'%d', Invalid digest Len 0x%x \n\r", i, pDigestEntry[i].digestLen);
			eStatus = SAIL_UPDATER_INVALID_SIZE;
			goto ProcessGetImgDigestEnd;
		}
		/* fetch dhsh */
		xbl_digestHash.imgName = (void *)&pDigestEntry[i].imgName[0U];
		xbl_digestHash.hashAlgo = (void *)&pDigestEntry[i].digestType;
		xbl_digestHash.containerSize = (void *)&pDigestEntry[i].digestLen;
		xbl_digestHash.hashContainer = (void *)&pDigestEntry[i].digest[0U];
		xbl_digestHash.bIsPrimaryPartition = FALSE;
		if((uint32_t)SAIL_UPD_PARTITION_ID_PRIMARY == pDigestEntry[i].partitionType )
		{
			xbl_digestHash.bIsPrimaryPartition = TRUE;
		}
		DEBUG_LOG(SAIL_WARNING, "%s: GET IMAGE DIGEST XBL Service Request image='%s' hashAlgo=%d containerSize=%d hashContainer=0x%p, bIsPrimaryPartition=0x%x\n\r",
				__func__, xbl_digestHash.imgName, *xbl_digestHash.hashAlgo, *xbl_digestHash.containerSize, xbl_digestHash.hashContainer, xbl_digestHash.bIsPrimaryPartition
				);
		/* xbl service request */
		if(XBL_SUCCESS != sailEl1XblGetDigestHash( &xbl_digestHash ))
		{
			DEBUG_LOG(SAIL_ERROR, "xSAILUpdaterCoreProcessGetImgDigest: Image'%d', service request failed\n\r", i);
			eStatus = SAIL_UPDATER_STATUS_FAIL;
			goto ProcessGetImgDigestEnd;
		}
		/* change XBL size response as interface return free container size */
		if( (uint32_t)SAIL_UPD_IMAGE_DIGEST_MAX_LEN > pDigestEntry[i].digestLen )
		{
			pDigestEntry[i].digestLen = ((uint32_t)SAIL_UPD_IMAGE_DIGEST_MAX_LEN - pDigestEntry[i].digestLen);
		}
		DEBUG_LOG(SAIL_WARNING, "%s: GET IMAGE DIGEST XBL Service Response image='%s' hashAlgo=%d containerSize=%d hashContainer=0x%p, bIsPrimaryPartition=0x%x\n\r",
				__func__, xbl_digestHash.imgName, *xbl_digestHash.hashAlgo, *xbl_digestHash.containerSize, xbl_digestHash.hashContainer, xbl_digestHash.bIsPrimaryPartition
		);
	}
    /* Calculate Buffer CRC */
	pRspMsg->getImgDigest.bufCrc = 0U;
	pRspMsg->getImgDigest.num_images = pReqMsg->getImgDigest.num_images;
	pRspMsg->getImgDigest.bufAddr = pReqMsg->getImgDigest.bufAddr;
	pRspMsg->getImgDigest.bufLen = pReqMsg->getImgDigest.bufLen;
	pRspMsg->getImgDigest.bufCrc = ulSAILUpdaterCoreCalcCRC(bufAddrToUse, pRspMsg->getImgDigest.bufLen);

	ProcessGetImgDigestEnd:
		DEBUG_LOG(SAIL_WARNING, "%s: GET IMAGE DIGEST Response MSG params num_images=0x%x bufAddr=0x%x bufLen=0x%x bufCrc=0x%x eStatus=%d\n\r",
								__func__, pRspMsg->getImgDigest.num_images, pRspMsg->getImgDigest.bufAddr, pRspMsg->getImgDigest.bufLen,
								pRspMsg->getImgDigest.bufCrc, eStatus );
	return eStatus;
}

#ifdef SAILUPDATER_INJTEST_SRC_ENABLED

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
    return g_SAILUpdaterCoreCtx.testcmdID;
}

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
SAILUpdaterStatusType_e xSAILUpdaterCoreProcessTestInjection(sailUpdaterMsgHeaderType* pReqMsg, sailUpdaterMsgHeaderType* pRspMsg)
{
    SAILUpdaterStatusType_e eStatus  = SAIL_UPDATER_STATUS_SUCCESS;
    SAILUpdaterOTAStateValType otaStatus = OTA_INVALID;
    uint8_t guidMap=0;
    spinor_handle_t norHandle = NULL;

    pRspMsg->msgId = SAIL_UPD_MSG_TEST_ERROR_INJECTION;
    DEBUG_LOG(SAIL_WARNING, "%s: TEST_ERROR_INJECTION Request MSG enable=0x%x triggerID=0x%x reserved0=0x%x reserved1=0x%x reserved2=0x%x reserved3=0x%x\n\r", __func__, pReqMsg->testTrigger.enable, pReqMsg->testTrigger.triggerID,
              pReqMsg->testTrigger.reserved[0],pReqMsg->testTrigger.reserved[1], pReqMsg->testTrigger.reserved[2], pReqMsg->testTrigger.reserved[3]);


    pRspMsg->testTrigger.enable = pReqMsg->testTrigger.enable;
    pRspMsg->testTrigger.triggerID  = pReqMsg->testTrigger.triggerID;
    pRspMsg->testTrigger.reserved[0] = pReqMsg->testTrigger.reserved[0];
    pRspMsg->testTrigger.reserved[1] = pReqMsg->testTrigger.reserved[1];
    pRspMsg->testTrigger.reserved[2] = pReqMsg->testTrigger.reserved[2];
    pRspMsg->testTrigger.reserved[3] = pReqMsg->testTrigger.reserved[3];

    if (pReqMsg->testTrigger.reserved[0] || pReqMsg->testTrigger.reserved[1] || pReqMsg->testTrigger.reserved[2] || pReqMsg->testTrigger.reserved[3])
    {
        DEBUG_LOG(SAIL_ERROR,"%s: Invalid Values for reserved fields  \r\n", __func__);
        eStatus = SAIL_UPDATER_STATUS_FAIL;
        goto TestInjectionEnd;
    }

    if (FALSE == pReqMsg->testTrigger.enable)
    {
        if (SAIL_OTA_TRIG_NO_ERROR != pReqMsg->testTrigger.triggerID)
        {
            DEBUG_LOG(SAIL_ERROR,"%s: Invalid Test trigger ID for disabling. Value should be 0  \r\n", __func__);
            eStatus = SAIL_UPDATER_STATUS_FAIL;
            goto TestInjectionEnd;
        }
        DEBUG_LOG(SAIL_WARNING, "%s: Disable Test trigger . No error injection \n\r",  __func__);

        g_SAILUpdaterCoreCtx.testcmdID = pReqMsg->testTrigger.triggerID;
    }
    else
    {
        if (SAIL_OTA_TRIG_ERROR_MAX <=pReqMsg->testTrigger.triggerID)
        {
            DEBUG_LOG(SAIL_ERROR,"%s: Invalid TestID >= Max value %d \r\n", __func__, SAIL_OTA_TRIG_ERROR_MAX);
            eStatus = SAIL_UPDATER_STATUS_FAIL;
            goto TestInjectionEnd;
        }
        else if (pReqMsg->testTrigger.triggerID >= SAIL_OTA_TRIG_ERROR_PRE_FIXGPTCORRUPTION_XBL)
        {
            DEBUG_LOG(SAIL_ERROR, "%s: Invalid TestID. Should be < %d \n\r", __func__, SAIL_OTA_TRIG_ERROR_PRE_FIXGPTCORRUPTION_XBL);
            eStatus = SAIL_UPDATER_STATUS_FAIL;
            goto TestInjectionEnd;
        }
        else if(SAIL_OTA_TRIG_NO_ERROR == pReqMsg->testTrigger.triggerID)
        {
            DEBUG_LOG(SAIL_WARNING, "%s: Valid TestID=%d . No error injection \n\r",  __func__, SAIL_OTA_TRIG_NO_ERROR);
        }
        else
        {
            DEBUG_LOG(SAIL_WARNING, "%s: Valid TestID=%d \n\r",  __func__, pReqMsg->testTrigger.triggerID);
        }

        g_SAILUpdaterCoreCtx.testcmdID = pReqMsg->testTrigger.triggerID;
    }

    switch (g_SAILUpdaterCoreCtx.testcmdID)
    {
        case SAIL_OTA_TRIG_CORRUPT_LAST_BOOKKEEPING_A:
        case SAIL_OTA_TRIG_CORRUPT_MIDENTRY_BOOKKEEPING_A:
        case SAIL_OTA_TRIG_CORRUPT_LAST_BOOKKEEPING_B:
        case SAIL_OTA_TRIG_CORRUPT_MIDENTRY_BOOKKEEPING_B:
        case SAIL_OTA_TRIG_CORRUPT_LAST_BOOKKEEPING_AB:
        case SAIL_OTA_TRIG_CORRUPT_MIDENTRY_BOOKKEEPING_AB:
            if(SPINOR_DEVICE_DONE != spinorEl1Open ( &norHandle, SPINOR_USER_TYPE_OTA ))
            {
                DEBUG_LOG(SAIL_ERROR,"%s: Spinor Open failed \n\r",  __func__);
                eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
                goto TestInjectionEnd;
            }
            eStatus = xSAILUpdaterTestCorruptOtaStatus (norHandle, g_SAILUpdaterCoreCtx.testcmdID);
            if(SAIL_UPDATER_STATUS_SUCCESS != eStatus)
            {
                DEBUG_LOG(SAIL_ERROR,"%s: Corrupting OTA bookkeeping Failed \n\r",  __func__);
                goto TestInjectionEnd;
            }
            break;
        case SAIL_OTA_TRIG_CORRUPT_PRIMARYGPT_NON_UPDATESTART:
            g_SAILUpdaterCoreCtx.norHandle = NULL;
            if(SPINOR_DEVICE_DONE != spinorEl1Open (&norHandle, SPINOR_USER_TYPE_OTA ))
            {
                DEBUG_LOG(SAIL_ERROR,"%s: Spinor Open failed \n\r",  __func__);
                eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
                goto TestInjectionEnd;
            }
            eStatus = xSAILUpdaterGetOtaStatus (norHandle, &otaStatus, &guidMap);
            if(SAIL_UPDATER_STATUS_SUCCESS != eStatus)
            {
                DEBUG_LOG(SAIL_ERROR,"%s: Getting OTA Status failed \n\r",  __func__);
                goto TestInjectionEnd;
            }
            if (OTA_UPDATE_START == otaStatus)
            {
                DEBUG_LOG(SAIL_ERROR,"%s: OTA Status is OTA_UPDATE_START. Retry in another state \n\r",  __func__);
                eStatus = SAIL_UPDATER_STATUS_FAIL;
                goto TestInjectionEnd;
            }
            /* Erase the Destination GPT header */
            if( SPINOR_DEVICE_DONE != spinorEl1Erase (norHandle, 1, 1) )
            {
                DEBUG_LOG(SAIL_ERROR,"%s: Corrupting Primary GPT failed \n\r", __func__);
                eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
                goto TestInjectionEnd;
            }
            DEBUG_LOG(SAIL_WARNING,"%s: Corrupted Primary GPT Successfully \n\r", __func__);
            break;
        default:
            break;
    }

    pRspMsg->status = SAIL_UPDATER_STATUS_SUCCESS;

TestInjectionEnd:

    DEBUG_LOG(SAIL_WARNING, "%s: TEST_ERROR_INJECTION Response MSG enable=0x%x triggerID=0x%x reserved0=0x%x reserved1=0x%x reserved2=0x%x reserved3=0x%x\n\r", __func__, pRspMsg->testTrigger.enable,
              pRspMsg->testTrigger.triggerID, pRspMsg->testTrigger.reserved[0],pRspMsg->testTrigger.reserved[1], pRspMsg->testTrigger.reserved[2], pRspMsg->testTrigger.reserved[3]);

    if (norHandle != NULL)
    {
        /* Close SPINOR handle */
        if(SPINOR_DEVICE_DONE != spinorEl1Close ( norHandle ))
        {
            DEBUG_LOG(SAIL_ERROR,"%s: Spinor Close failed \n\r", __func__);
            eStatus = SAIL_UPDATER_SPINOR_OPERATION_FAIL;
        }
        norHandle = NULL;
    }
    return eStatus;
}
#endif /* SAILUPDATER_INJTEST_SRC_ENABLED */

