#ifndef __GPT_H__
#define __GPT_H__
/*
===========================================================================
*/
/**
    @file  gpt.h
    @brief GPT functions for SAIL ELF loader and NOR flash driver.

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

    $Header: $
    $DateTime: $
    $Author: $

    ===========================================================================
*/

#include "types.h"

#define GUID_STRING_SIZE 36

#define GPT_SIGNATURE                       "EFI PART"
#define GPT_SIGNATURE_SIZE                  8
#define GPT_PARTITION_ENTRY_BASE_SIZE_BYTES 128UL
#define GPT_CRC32_SEED_DEFAULT              0UL
#define GPT_PARTITION_NAME_SIZE_BYTES       72   /* Size of partition name in GPT */

// 8701faa8-baa0-43cf-9c90-3b30495c558e
typedef struct  //__attribute__((__packed__))
{
  uint32_t data1;
  uint16_t data2;
  uint16_t data3;
  uint8_t  data4[8];
}__attribute__((packed)) guid_t;

typedef struct // __attribute__((__packed__))
{
  uint8_t  signature[GPT_SIGNATURE_SIZE]; /* Should be "EFI PART" */
  uint32_t revision;                      /* Header revision number, this header is 1.0 */
  uint32_t header_size;                   /* Size of this header in bytes. */
  uint32_t header_crc32;                  /* CRC 32 of this header, set to zero for calculations*/
  uint32_t reserved1;
  uint64_t my_lba;                        /* Logical Block Address of this header. */
  uint64_t alternate_lba;                 /* location of the other header copy */
  uint64_t first_usable_lba;              /* Min LBA for any partition. */
  uint64_t last_usable_lba;               /* Max LBA for any partition. */
  guid_t   disk_guid;                     /* such as 98101B32-BBE2-4BF2-A06E-2BB33D000C20 */
  uint64_t partition_entry_lba;           /* Partiton entry table LBA. */
  uint32_t number_of_partition_entries;   /* Number of entires in partition array*/
  uint32_t size_of_partition_entry;       /* Size of each partition entry. */
  uint32_t partition_entries_crc32;       /* CRC32 of partition entry array. */
  /* The rest of the block is reserved. The header size should be 92 bytes. */
}__attribute__((packed)) gptHeader_t;

typedef struct  //__attribute__((__packed__))
{
  guid_t   partition_type_guid;  /* Partition GUID */
  guid_t   partition_guid;       /* Not used */
  uint64_t starting_lba;         /* partition base */
  uint64_t ending_lba;           /* partition end */
  uint64_t attributes;
  uint8_t  partition_name[GPT_PARTITION_NAME_SIZE_BYTES]; /* Unicode coded name. e.g. ascii 'S' is coded to be 'S''\0' */
}__attribute__((packed)) gptEntry_t;

typedef uint32_t (*gptEntryRead)(uint8_t *pBuf, uint32_t ulStartByte, uint32_t ulSize);

/**********************************************************
 * Calculates CRC32 (Cyclic redundancy check) over the number of bytes specified.
 *
 * @param data [IN/OUT]
 *   Pointer to the buffer to be used to calculate crc32.
 *
 * @param nbytes [IN]
 *   Calculate CRC32 over this number of bytes.
 *
 * @param seed [IN]
 *   CRC32 seed. Used to chain CRC32 calculations.
 *
 * @return crc [OUT]
 *   return CRC32 over the buffer.
 *
 **********************************************************/
uint32_t gptCalcCRC32 (const uint8_t *data, uint32_t nbytes, uint32_t seed);

/**********************************************************
 * Verifies the CRC32 (Cyclic redundancy check) of the partition entry.
 *
 * @param pHdr [IN/OUT]
 *   Pointer to the structure containing header information.
 *
 * @param pBuf [IN/OUT]
 *   Pointer to the buffer to be used to calculate crc32.
 *
 * @param readCb [IN]
 *   GPT entry block containing partition information.
 *
 * @param lba_sz [IN]
 *   Logical base address size.
 *
 * @param ulCRC32Seed [IN]
 *   CRC32 seed. Used to chain CRC32 calculations.
 *
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
boolean gptVerifyPartitionEntryCRC32(gptHeader_t *pHdr, uint8_t *pBuf,
                                     gptEntryRead readCb, uint32_t lba_sz,
                                     uint32_t ulCRC32Seed);

/**********************************************************
 * Verifies the CRC32 (Cyclic redundancy check) of the header.
 *
 * @param pHdr [IN/OUT]
 *   Pointer to the structure containing header information.
 *
 * @param ulCRC32Seed [IN]
 *   CRC32 seed. Used to chain CRC32 calculations.
 *
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
boolean  gptVerifyHeaderCRC32(gptHeader_t *pHdr, uint32_t ulCRC32Seed);

/**********************************************************
 * Checks if the given header is a primary header.
 *
 * @param pHdr [IN/OUT]
 *   Pointer to the structure containing header information.
 *
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
boolean  gptIsPrimaryHeader(gptHeader_t *pHdr);

/**********************************************************
 * Get the partition entry LBA.
 *
 * @param pHdr [IN/OUT]
 *   Pointer to the structure containing header information.
 *
 * @param lba_sz [IN]
 *   Logical base address size.
 *
 * @return int [OUT]
 *   Return the entry LBA of the partition.
 *
 **********************************************************/
uint64_t gptGetPartitionEntryLbaBase(gptHeader_t* pHdr, uint32_t lba_sz);

/**********************************************************
 * Get the number of partition entries.
 *
 * @param pHdr [IN/OUT]
 *   Pointer to the structure containing header information.
 *
 * @return int [OUT]
 *   Return the number of entries.
 *
 **********************************************************/
uint32_t gptGetNumOfPartitionEntrys(gptHeader_t *pHdr);

/**********************************************************
 * Get the sizes of the partition entries.
 *
 * @param pHdr [IN/OUT]
 *   Pointer to the structure containing header information.
 *
 * @return int [OUT]
 *   Return the sizes of entries.
 *
 **********************************************************/
uint32_t gptGetPartitionEntrySize(gptHeader_t *pHdr);

/**********************************************************
 * Get the partition base address.
 *
 * @param pEntry [IN]
 *   Pointer to the structure containing partition information.
 *
 * @param lba_sz [IN]
 *   Logical base address size.
 *
 * @return int [OUT]
 *   Return the base address of the partition.
 *
 **********************************************************/
uint64_t gptGetPartitionBase(gptEntry_t *pEntry, uint32_t lba_sz);

/**********************************************************
 * Get the partition size.
 *
 * @param pEntry [IN]
 *   Pointer to the structure containing partition information.
 *
 * @param lba_sz [IN]
 *   Logical base address size.
 *
 * @return int [OUT]
 *   Return the size of the partition.
 *
 **********************************************************/
uint64_t gptGetPartitionSize(gptEntry_t *pEntry, uint32_t lba_sz);

/**********************************************************
 * Verify the partition GUID.
 *
 * @param pEntry [IN]
 *   Pointer to the structure containing partition information.
 *
 * @param pGuid [IN]
 *   Structure storing different parts of the GUID.
 *
 * @return int [OUT]
 *   Return the result of the operation.
 *
 **********************************************************/
boolean  gptVerifyPartitionGuid(gptEntry_t *pEntry, guid_t *pGuid);

/**********************************************************
 * Decode the GUID string.
 *
 * @param guidString [IN]
 *   Pointer to the GUID string.
 *
 * @param pGuid [IN]
 *   Structure storing different parts of the GUID.
 *
 * @return int [OUT]
 *   Return the result of the operation.
 *
 **********************************************************/
boolean  gptDecodeGUIDString(const char* guidString, guid_t* pGuid);

#endif /* __GPT_H__ */
