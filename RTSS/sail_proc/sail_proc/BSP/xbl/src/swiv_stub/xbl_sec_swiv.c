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
    File Name          : xbl_sec_swiv.c
    Description        : Implementation of SAIL software image verification - Stub.
=================================================================================================*/

#include "xbl_sec_swiv.h"

/**
 * @brief Stub implementation used when SWIV is disabled.
 *
 * @param[in] sec_img_id : Image ID
 * @param[in] elf_type   : Elf class type
 * @param[in] phdr32     : Program header pointer
 * @param[in] phdr_num   : Number of program headers
 * @param[in] ulNorOffSet: Starting address of the image
 *
 * @return SWIV_SUCCESS 
 */
int32_t xbl_sec_swiv ( void *phandle, uint32_t sec_img_id, Elf_Class elf_type, const Elf32_Phdr* phdr32, uint32_t phdr_num, uint32_t ulNorOffSet)
{
    return SWIV_SUCCESS;
}
