#ifndef __GPT_PARTITION_H__
#define __GPT_PARTITION_H__
/*
===========================================================================
*/
/**
    @file  gpt_partition.h
    @brief GPT functions for SAIL ELF loader and NOR falsh driver.

*/
/*
    ===========================================================================

    Copyright (c) 2022 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/gpt/public/gpt_partition.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "types.h"
#include "gpt_p1.h"

#define NOR_LBA_SZ        4096
#define GPT_TABLE_NULL            0
#define GPT_TABLE_PRIMARY         1
#define GPT_TABLE_SECONDARY       2

/**********************************************************
 * Initializes the GPT partition.
 *
 * @param block_count [IN]
 *   Total block count in the device.
 *
 * @param gptEntryReadCb [IN]
 *   GPT entry block containing block information.
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
boolean  gptPartitionInit(uint32 block_count, gptEntryRead gptEntryReadCb, uint8_t *puWorkBuf, uint32_t ulBufSz, uint32_t ulAlignment);

/**********************************************************
 * Get the GPT Id used.
 *
 * @return int [OUT]
 *   GPT Id.
 *
 **********************************************************/
uint32_t gptPartitionGetGptId(void);

/**********************************************************
 * Get the GPT entry callback.
 *
 * @return int [OUT]
 *   GPT entry read callback.
 *
 **********************************************************/
gptEntryRead gptPartitionGetReadCb(void);

/**********************************************************
 * Get the total block count of the Storage
 *
 * @return int [OUT]
 *   total block count of the storage
 *
 **********************************************************/
uint32_t gptPartitionGetBlockCnt(void);

/**********************************************************
 * De-Initializes the GPT partition.
 *
 * @param none
 *
 * @return void [OUT]
 *
 *
 **********************************************************/
void  gptPartitionDeInit(void);

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
boolean  gptPartitionDecodeGUIDString(const char* guidString, guid_t* pGuid);

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
boolean gptGetPartitionInfo ( guid_t* pGuid, uint32_t *pulStartAddr, uint32_t *pulSize );

#endif /* __GPT_PARTITION_H__ */
