/*
===========================================================================
*/
/**
    @file  elfloader_storage.h
    @brief Header of elf loader storage read sub-module

*/
/*
    ===========================================================================

    Copyright (c) 2022-2023 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/xbl/inc/elfloader/elfloader_storage.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

/* Include header file guard */
#ifndef __ELF_LOADER_STORAGE_H__
#define __ELF_LOADER_STORAGE_H__

/*=========================================================================================================
**                                     Include files                                                     **
=========================================================================================================*/

#include "types.h"

/*=========================================================================================================
**                                     Local defines and macros                                          **
=========================================================================================================*/


/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
=========================================================================================================*/
/**********************************************************
 * Init Storage Device
 *
 * @param NA [IN]
 *
 * @return void [OUT]
 *
 **********************************************************/
void vStorageInit(void);
/**********************************************************
 * Open storage device
 *
 *
 * @param NA [IN]
 *
 * @return int [OUT]
 *   0: pass.
 *
 **********************************************************/
int nStorageOpen(void **ppHandle);
/**********************************************************
 * Close storage device
 *
 * @param NA [IN]
 *
 * @return void [OUT]
 *
 **********************************************************/
void xStorageClose(void *pHandle);
/**********************************************************
 * Query boot image partition start adsdress and size
 *
 *
 * @param guidString [IN]
 *   GUID
 * @param pulStartAddr [OUT]
 *   partation start address
 *
 * @param pulSize [OUT]
 *   partation size in bytes
 *
 * @return int [OUT]
 *   0: pass.
 *
 **********************************************************/
int nStorageGetPartition ( void *pHandle, const char *guidString, uint32_t *pulStartAddr, uint32_t *pulSize );
/**********************************************************
 * Update the storage type for XBL (NOR-Flash/DDR)
 *
 *
 * @param eType [IN]
 *   eXblStorageType
 *
 * @param ulRamBase [IN]
 *   uint32_t
 *
 * @param ulRamSize [IN]
 *   uint32_t
 *
 **********************************************************/
int nStorageUpdate(eXblStorageType eType, uint32_t ulRamBase, uint32_t ulRamSize);
/**********************************************************
 * Read data from storage device
 *
 *
 * @param nStartOffset [IN]
 *   start address in storage device
 * @param nSize [IN]
 *   partation size to be read out
 *
 * @param buf [OUT]
 *   RAM address to hold teh readout
 *
 * @return int [OUT]
 *   0: pass.
 *
 **********************************************************/
int nStorageRead ( void *pHandle, uint32_t nStartOffset, uint32_t nSize, uint8_t *buf );
/**********************************************************
 * Erase memory
 *
 *
 * @param start_block [IN]
 *   start block number
 * @param block_count [IN]
 *   block count to be erased
 *
 * @return int [OUT]
 *   0: pass.
 *
 **********************************************************/
int nStorageErase ( void *pHandle, uint32 start_block, uint32 block_count );
/**********************************************************
 * Get NOR memory info
 *
 *
 * @param block_count [OUT]
 *   block count pointer
 * @param pages_per_block [OUT]
 *   page count pointer
 * @param page_size_bytes [OUT]
 *   page size pointer
 *
 * @return int [OUT]
 *   0: pass.
 *
 **********************************************************/
int nStorageGetMemInfo ( void *pHandle, uint32 *block_count, uint32 *pages_per_block, uint32 *page_size_bytes );

#endif /*__BOOT_LOADER_STORAGE_H__*/

/**********************************************************************************************************
**                                    End of file                                                        **
**********************************************************************************************************/
