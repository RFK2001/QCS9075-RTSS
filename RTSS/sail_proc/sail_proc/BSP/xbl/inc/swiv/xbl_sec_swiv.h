/* ===========================================================================

    Copyright (c) 2023 Qualcomm Technologies, Inc.
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

    =========================================================================== */

/*=================================================================================================
    File Name          : xbl_sec_swiv.h
    Description        : Header for SAIL software image verification API.
=================================================================================================*/

#ifndef XBL_SEC_SWIV_H
#define XBL_SEC_SWIV_H

#include "elfloader_def.h"

#ifndef SWIV_SUCCESS
#define SWIV_SUCCESS 0
#endif

#define SWIV_SEG_BUF_SIZE          16U
#define MAX_SAIL_IMAGE_SEGMENTS    12

/**
 * @brief Gets the SWIV recipe from SAIL image and verify it.
 *
 * @param[in] sec_img_id : Image ID
 * @param[in] elf_type   : Elf class type
 * @param[in] phdr32     : Program header pointer
 * @param[in] phdr_num   : Number of program headers
 * @param[in] ulNorOffSet: Starting address of the image
 *
 * @return SWIV_SUCCESS if Success
 *         Respective error code otherwise
 */
int32_t xbl_sec_swiv ( void *phandle, uint32_t sec_img_id, Elf_Class elf_type, const Elf32_Phdr* phdr32, uint32_t phdr_num, uint32_t ulNorOffSet);

#endif
