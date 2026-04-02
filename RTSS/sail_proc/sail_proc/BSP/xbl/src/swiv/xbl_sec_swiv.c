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
    Description        : Implementation of SAIL software image verification(SWIV).
=================================================================================================*/

#include "swiv.h"
#include "xbl_sec_swiv.h"
#include "xbl_def.h"
#include "xbl_diag.h"
#include "xbl_mem.h"
#include "elfloader_storage.h"
#include "secboot_swid.h"

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
int32_t xbl_sec_swiv ( void *phandle, uint32_t sec_img_id, Elf_Class elf_type, const Elf32_Phdr* phdr32, uint32_t phdr_num, uint32_t ulNorOffSet)
{
    int32_t ret = SWIV_SUCCESS;
    uint32_t itr = 0U;
    uint32_t opt = (uint32_t)SEG_UNLOAD; /* Since SWIV segment is unloadable */
    struct swiv_context recipe = {0};
    struct swiv_segment_info sw_seg_list[MAX_SAIL_IMAGE_SEGMENTS] = {0};
    struct swiv_segment *seg_buffer = SL_NULL;

    /* Only checking for 32 bit image as SAIL images are 32bit */
    if((ELF_CLASS_32 == elf_type) && (phdr32 != SL_NULL))
    {
        opt |= (uint32_t)ELF32_TYPE;
        recipe.seg_list = sw_seg_list;
        recipe.seg_list_num = phdr_num;

        /* Get the address of SWIV segment, looping from last segment to avoid storage read of hash segments */
        seg_buffer = xblMalloc(sizeof(struct swiv_segment));
        if (seg_buffer == SL_NULL)
        {
            XBL_LOG_ERROR("%s: Error. No mem, sec_img_id = %d \n\r", __func__, sec_img_id);
            ret = XBL_ERROR_NO_MEM;
        }
        else
        {
            for (itr = phdr_num; itr > 0U; itr--)
            {
                if((phdr32[itr - 1U].p_type == SL_PT_NULL) && (ret == SWIV_SUCCESS))
                {
                    if (0 != nStorageRead( phandle, phdr32[itr - 1U].p_offset + ulNorOffSet, SWIV_SEG_BUF_SIZE, (uint8_t *)seg_buffer))
                    {
                        XBL_LOG_ERROR("%s: Error in segment reading. sec_img_id = 0x%x\n\r", __func__, sec_img_id);
                        ret = XBL_ERROR_READ_STORAGE;
                    }
                    if (seg_buffer->magic_num == SWIV_MAGIC_NUM)
                    {
                        break;
                    }
                }
            }
            if ((ret == SWIV_SUCCESS) && (itr == 0U))
            {
                XBL_LOG_ERROR("%s: SWIV segment not found. sec_img_id = 0x%x\n\r", __func__, sec_img_id);
                ret = SWIV_NOT_FOUND;
            }

            /* Get each segment details and stored CRC value */
            if (ret == SWIV_SUCCESS)
            {
                ret = swiv_parse(phdr32, phdr_num, &recipe, seg_buffer, opt);
            }

            /* Compute CRC and verify with stored value */
            if (ret == SWIV_SUCCESS)
            {
                ret = swiv_verify(&recipe);
            }

            /* Free allocated memory */
            xblFree(seg_buffer);
        }
    }
    else
    {
        XBL_LOG_ERROR("%s: Invalid parameter. sec_img_id = 0x%x\n\r", __func__, sec_img_id);
        ret = XBL_ERROR_INVALID_PARAM;
    }

    return ret;
}
