/*
===========================================================================
*/
/**
    @file  sailhyp_xbl_api.h
    @brief sailhyp xbl api function definitions

*/
/*
    ===========================================================================

    Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
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

#ifndef __SAILHYP_XBL_API_H__
#define __SAILHYP_XBL_API_H__

#include "types.h"
#include "xbl_def.h"

/**********************************************************
 * XBL init
 *
 *
 * @param pbl_info [IN]
 *   PBL info pointer
 *
 * @return int [OUT]
 *   XBL_SUCCESS/ERROR.
 *
 **********************************************************/
int sailhyp_xbl_init(void *pbl_info);
/**********************************************************
 * XBL deinit
 *
 *
 * @param NA
 *
 * @return void.
 *
 **********************************************************/
void sailhyp_xbl_deinit(void);
/**********************************************************
 * Load SAIL SW ELFs
 *
 *
 * @param boot_params [IN]
 *   params array
 *
 * @param count [IN]
 *   array size
 *
 * @return int [OUT]
 *   XBL_SUCCESS/ERROR.
 *
 **********************************************************/
int sailhyp_xbl_boot_elfs(xbl_boot_params_t *boot_params, uint32_t count);
/**********************************************************
 * Get image's entry point
 *
 *
 * @param image_id [IN]
 *   image id
 *
 * @return image_entry [OUT]
 *   entry pointer pointer.
 *
 **********************************************************/
int sailhyp_xbl_get_image_entry_point(eXblImageIdType image_id, uint32_t *image_entry);

/**********************************************************
 * Erase image. Both primary and secondary partitions are erased
 *
 *
 * @param image_id [IN]
 *   image id
 *
 * @return int
 *   status code
 *
 **********************************************************/
int sailhyp_xbl_erase_image(eXblImageIdType image_id);
/**********************************************************
 * Check image's ELF header
 *
 *
 * @param image_id [IN]
 *   image id
 *
 * @param primary [OUT]
 *   primary partition ELF header status (TRUE: pass)
 *
 * @param secondary [OUT]
 *   Secondary partition ELF header status (TRUE: pass)
 *
 * @return int
 *   Status code
 *
 **********************************************************/
int sailhyp_xbl_check_ehdr(eXblImageIdType image_id, boolean *primary, boolean *secondary);

/**********************************************************
 * Get image's ID from Image name
 *
 *
 * @param imgName [IN]
 *   Image Name
 *
 * @return image_id [OUT]
 *   Image Id.
 *
 **********************************************************/
int sailhyp_xbl_getImgId(const char* imgName,uint32_t* image_id);

/**********************************************************
 * Get image's ID from Image name
 *
 *
 * @param imgName [IN]
 *   Image Name
 *
 * @param FlashPartition [IN]
 *   Flash Partition
 *
 * @param FlashGptId [IN]
 *   Flash GPT ID
 *
 * @param imgGuid [IN/OUT]
 *   Pointer to populate the GUID
 *
 * @return uint32_t [OUT]
 *   Status code.
 *
 **********************************************************/
uint32_t sailhyp_xbl_getImgGUID(const char* imgName, uint32_t FlashPartition, uint32_t FlashGptId, char *imgGuid);

/**********************************************************
 * Query the bootInfo of all images
 *
 *
 * @param bootInfo [OUT]
 *   Boot Info
 *
 * @param ulArraySize [IN]
 *   Array Size
 *
 * @return uint32_t
 *   XBL_SUCCESS
 *  
 **********************************************************/
uint32_t sailhyp_xbl_queryBootInfo(XBLBootInfoType* bootInfo, uint32_t ulArraySize);

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
int sailhyp_xbl_update_storage( eXblStorageType eType, uint32_t ulRamBase, uint32_t ulRamSize);

/**********************************************************
 * Get the hash digest for the given image name
 *
 *
 * @param xDigestHash [IN]
 *   xbl_digestHashType
 *
 **********************************************************/
int sailhyp_xbl_getHashDigest(xbl_digestHashType * xDigestHash);

#endif