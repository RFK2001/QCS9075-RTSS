/*
===========================================================================
*/
/**
    @file  gpt_partition.c
    @brief GPT functions for SAIL ELF loader and NOR falsh driver.

*/
/*
    ===========================================================================

    Copyright (c) 2022-24 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/gpt/src/gpt_partition.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "types.h"
//#include "string.h"
#include "gpt_p1.h"
#include "gpt_partition1.h"
#include "common_functions.h"
#include "debug_log.h"


static gptHeader_t g_gptHdr;
static boolean bgptPartitionInitDone;
static gptEntryRead g_gptEntryReadCb;
static uint32_t g_block_count;
static uint8_t *g_gptWorkBuf;
static uint32_t g_ulGptWorkBufSz;
static uint32_t g_ulReadAlignment;
static uint32_t g_ulGptId;

/**********************************************************
 * Reads and verifies the partition header from the specified address.
 *
 * @param startAddr [IN]
 *   Start address of the region to be read.
 *
 * @param sz [IN]
 *   Size of information to be read.
 *
 * @param pAlternateHdrAddr [IN/OUT]
 *   Pointer to Alternate Header address.
 *
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
int gptPartitiontry(uint32 startAddr, uint32 sz, uint32* pAlternateHdrAddr, boolean* tryval)
{
    size_t result = 0;

    if (sz != g_gptEntryReadCb (g_gptWorkBuf, startAddr, sz))
    {
        *tryval = FALSE;
        return -1;
    }

    result = sailbsp_memscpy(&g_gptHdr, sizeof(g_gptHdr), g_gptWorkBuf, sizeof(g_gptHdr));
    if(result == 0)
    {
        *tryval = FALSE;
        return -1;
    }

    if (pAlternateHdrAddr)
    {
        *pAlternateHdrAddr = g_gptHdr.alternate_lba*NOR_LBA_SZ;
    }

#ifdef TEST_2ND_HDR
    if (startaddr == NOR_LBA_SZ)
    {
        *tryval = FALSE;
        return 0;
    }
#endif

    /* verify GPT header CRC */
    if (FALSE == gptVerifyHeaderCRC32(&g_gptHdr, GPT_CRC32_SEED_DEFAULT))
    {
        *tryval = FALSE;
        return 0;
    }
    if (FALSE == gptVerifyPartitionEntryCRC32(&g_gptHdr, g_gptWorkBuf, g_gptEntryReadCb, NOR_LBA_SZ, GPT_CRC32_SEED_DEFAULT))
    {
        *tryval = FALSE;
        return 0;
    }

    *tryval = TRUE;
    return 0;
}

/**********************************************************
 * Initializes the GPT partition.
 *
 * @param block_count [IN]
 *   Total block count in the device.
 *
 * @param gptEntryReadCb [IN]
 *   GPT entry block containing partition information.
 *
 * @param puWorkBuf [IN/OUT]
 *   Pointer to data buffer for a GPT operation.
 *
 * @param ulBufSz [IN]
 *   Size of work buffer.
 *
 * @param ulAlignment [IN]
 *   GPT partition read address alignment.
 *
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
boolean  gptPartitionInit(uint32 block_count, gptEntryRead gptEntryReadCb, uint8_t *puWorkBuf, uint32_t ulBufSz, uint32_t ulAlignment)
{
    uint32_t gpthdr_sz;
    uint32_t sz;
    uint32 alternateAddr = 0;
    boolean tryval;
    int status = 0;

    if ( NULL == gptEntryReadCb || NULL == puWorkBuf)
    {
        return FALSE;
    }

    gpthdr_sz         = sizeof(gptHeader_t);
    g_gptEntryReadCb  = gptEntryReadCb;
    g_gptWorkBuf      = puWorkBuf;
    g_ulGptWorkBufSz  = ulBufSz;
    g_ulReadAlignment = ulAlignment;
    g_block_count = block_count;

    sz = (gpthdr_sz % g_ulReadAlignment) ? gpthdr_sz + g_ulReadAlignment - (gpthdr_sz % g_ulReadAlignment) : gpthdr_sz;

    if (sz > g_ulGptWorkBufSz || sizeof(gptEntry_t) > g_ulGptWorkBufSz)
    {
        return FALSE;
    }
    
    status = gptPartitiontry(NOR_LBA_SZ, sz, &alternateAddr, &tryval);
    if(status != 0)
    {
        g_ulGptId = GPT_TABLE_NULL;
        memset(&g_gptHdr, 0, sizeof(g_gptHdr));
        return FALSE;
    }
    
    if(tryval == TRUE)
    {
        g_ulGptId = GPT_TABLE_PRIMARY;
        goto found;
    }
#ifdef SINGLE_IMG_COMPILE
    status = gptPartitiontry(alternateAddr, sz, &alternateAddr, &tryval);
    if(status != 0)
    {
        g_ulGptId = GPT_TABLE_NULL;
        memset(&g_gptHdr, 0, sizeof(g_gptHdr));
        return FALSE;
    }
    
    if(tryval == TRUE)
    {
        goto found;
    }
#endif
    status = gptPartitiontry((block_count-1)*NOR_LBA_SZ, sz, NULL, &tryval);
    if(status != 0)
    {
        g_ulGptId = GPT_TABLE_NULL;
        memset(&g_gptHdr, 0, sizeof(g_gptHdr));
        return FALSE;
    }
    
    if(tryval == TRUE)
    {
        g_ulGptId = GPT_TABLE_SECONDARY;
        goto found;
    }
    
    /* When tryval = FALSE */
    g_ulGptId = GPT_TABLE_NULL;
    memset(&g_gptHdr, 0, sizeof(g_gptHdr));
    return FALSE;

found:
    bgptPartitionInitDone = TRUE;
    return TRUE;
}

/**********************************************************
 * Get the GPT Id used.
 *
 * @return int [OUT]
 *   GPT Id.
 *
 **********************************************************/
uint32_t gptPartitionGetGptId(void)
{
    return g_ulGptId;
}

/**********************************************************
 * Get the GPT entry callback.
 *
 * @return int [OUT]
 *   GPT entry read callback.
 *
 **********************************************************/
gptEntryRead gptPartitionGetReadCb(void)
{
    return g_gptEntryReadCb;
}

/**********************************************************
 * Get the total block count of the Storage
 *
 * @return int [OUT]
 *   total block count of the storage
 *
 **********************************************************/
uint32_t gptPartitionGetBlockCnt(void)
{
    return g_block_count;
}

/**********************************************************
 * De-Initializes the GPT partition.
 *
 * @param none
 *
 * @return void [OUT]
 *
 *
 **********************************************************/
void  gptPartitionDeInit(void)
{
    memset(&g_gptHdr, 0, sizeof(g_gptHdr));
    g_gptEntryReadCb      = NULL;
    g_gptWorkBuf          = NULL;
    g_ulGptWorkBufSz      = 0;
    g_ulReadAlignment     = 0;
    bgptPartitionInitDone = FALSE;
}

/**********************************************************
 * Decodes the GUID string.
 *
 * @param guidString [IN]
 *   Pointer to the GUID string.
 *
 * @param pGuid [IN/OUT]
 *   Structure storing different parts of the GUID.
 *
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
boolean  gptPartitionDecodeGUIDString(const char* guidString, guid_t* pGuid)
{
    return gptDecodeGUIDString ( guidString, pGuid );
}

/**********************************************************
 * Query GPT partition information to spinor framework.
 *
 * @param guid [IN]
 *   NULL terminated GPT partition GUID string.
 *
 * @param pulStartAddr [IN/OUT]
 *   GPT partition start address.
 *
 * @param pulSize [IN/OUT]
 *   GPT partition size.
 *
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
boolean gptGetPartitionInfo ( guid_t* pGuid, uint32_t *pulStartAddr, uint32_t *pulSize )
{
    uint32_t i;
    uint32_t ulBase;
    uint32_t ulEntrySz;
    uint32_t sz;
    gptEntry_t *pEntry;
    guid_t *tmpGuid;

    if ( !bgptPartitionInitDone  || !pGuid || !pulStartAddr || !pulSize)
    {
        DEBUG_LOG(SAIL_ERROR,"%s: invalid params passed \n\r", __func__);
        return FALSE;
    }

    ulBase     = ((uint32_t)(g_gptHdr.partition_entry_lba & 0xFFFFFFFF)) * NOR_LBA_SZ;
    ulEntrySz  = g_gptHdr.size_of_partition_entry;

    pEntry  = (gptEntry_t *)g_gptWorkBuf;
    tmpGuid = &pEntry->partition_type_guid;

    DEBUG_LOG(SAIL_DEBUG, "%s:Searching for Partition GUID %x-%x-%x-%x%x-%x%x%x%x%x%x \n\r", __func__, pGuid->data1, pGuid->data2, pGuid->data3,
              pGuid->data4[0],pGuid->data4[1],pGuid->data4[2],pGuid->data4[3],pGuid->data4[4],pGuid->data4[5],pGuid->data4[6],pGuid->data4[7]);

    for ( i = 0; i < g_gptHdr.number_of_partition_entries; i++ )
    {
        if (ulEntrySz != g_gptEntryReadCb (g_gptWorkBuf, (ulBase + i * ulEntrySz), ulEntrySz))
        {
            DEBUG_LOG(SAIL_ERROR,"%s: Reading partition entries failed \n\r", __func__);
            return FALSE;
        }
        if ( !gptVerifyPartitionGuid(pEntry, pGuid) )
        {
            continue;
        }
        *pulStartAddr = (uint32_t)gptGetPartitionBase ( pEntry, NOR_LBA_SZ );
        *pulSize      = (uint32_t)gptGetPartitionSize ( pEntry, NOR_LBA_SZ );
        return TRUE;
    }

    
    DEBUG_LOG(SAIL_ERROR, "%s: Partition not found for GUID %x-%x-%x-%x%x-%x%x%x%x%x%x \n\r", __func__, pGuid->data1, pGuid->data2, pGuid->data3,
              pGuid->data4[0],pGuid->data4[1],pGuid->data4[2],pGuid->data4[3],pGuid->data4[4],pGuid->data4[5],pGuid->data4[6],pGuid->data4[7]);
    return FALSE;
}

