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
    File Name          : swiv.c
    Description        : Software Image Integrity Validation is used for validating software images
                         with FuSa critical contents.
=================================================================================================*/

#include "stdint.h"
#include "swiv.h"
#include "crc32.h"

static sl_s32_t verify_swiv_magic(const struct swiv_segment *seg)
{
    sl_s32_t ret = 0;

    if (seg->magic_num != SWIV_MAGIC_NUM) {
        ret = -1;
    }

    return ret;
}

sl_s32_t swiv_parse(const void *phdr, sl_u32_t phdr_num, struct swiv_context *recipe, const struct swiv_segment *seg, sl_u32_t opt)
{
    const sl_Elf32_Phdr *p32 = (const sl_Elf32_Phdr *)phdr;
    const sl_Elf64_Phdr *p64 = (const sl_Elf64_Phdr *)phdr;
    sl_size_t i = 0;
    sl_u32_t loadable_seg_num = 0U;
    sl_elf_type elf_type = ELF32_TYPE;
    sl_load_type load_type = SEG_UNLOAD;
    sl_s32_t ret = SWIV_SUCCESS;
    sl_s32_t result = 0;

    /* Validate parameter */
    if ((phdr == SL_NULL) || (recipe == SL_NULL) || (seg == SL_NULL) || (phdr_num == 0U) || (phdr_num > SEG_MAX_NR)) {
        ret = PARAMETER_INVALID;
    }

    if (ret == SWIV_SUCCESS) {
        if ((recipe->seg_list == SL_NULL) || (recipe->seg_list_num == 0U)) {
            ret = PARAMETER_INVALID;
        }
    }

    if ((opt & ELF_TYPE_MASK) == (sl_u32_t)ELF32_TYPE) {
        elf_type = ELF32_TYPE;
    } else if ((opt & ELF_TYPE_MASK) == (sl_u32_t)ELF64_TYPE) {
        elf_type = ELF64_TYPE;
    } else {
        /* ELF type value is not supported */
        ret = PARAMETER_INVALID;
    }

    if ((opt & LOAD_TYPE_MASK) == (sl_u32_t)SEG_UNLOAD) {
        load_type = SEG_UNLOAD;
    } else if ((opt & LOAD_TYPE_MASK) == (sl_u32_t)SEG_LOAD) {
        load_type = SEG_LOAD;
    } else {
        /* Load type value is not supported */
        ret = PARAMETER_INVALID;
    }

    if (ret == SWIV_SUCCESS) {
        result = verify_swiv_magic(seg);
        if (result != 0) {
            ret = SWIV_NOT_FOUND;
        }
    }

    if (ret == SWIV_SUCCESS) {
        /* Go through each loadable segment and record its address and size in the recipe */
        if (elf_type == ELF32_TYPE)
        {
            while (i < phdr_num) {
                if (p32->p_type == SL_PT_LOAD) {
                    loadable_seg_num++;
                    if (loadable_seg_num <= recipe->seg_list_num) {
                        recipe->seg_list[loadable_seg_num - 1U].vaddr = (sl_u64_t)p32->p_vaddr;
                        recipe->seg_list[loadable_seg_num - 1U].paddr = (sl_u64_t)p32->p_paddr;
                        recipe->seg_list[loadable_seg_num - 1U].memsz = (sl_u64_t)p32->p_memsz;
                        SWIV_DEBUG_LOG("Parsed segment: VA - %x, PA - %x, MEMSZ - %x\n", p32->p_vaddr, p32->p_paddr, p32->p_memsz);
                    } else {
                        ret = PARAMETER_INVALID;
                        break;
                    }
                }
                i++;
                p32++;
            }
        } else {
            while (i < phdr_num) {
                if (p64->p_type == SL_PT_LOAD) {
                    loadable_seg_num++;
                    if (loadable_seg_num <= recipe->seg_list_num) {
                        recipe->seg_list[loadable_seg_num - 1U].vaddr = p64->p_vaddr;
                        recipe->seg_list[loadable_seg_num - 1U].paddr = p64->p_paddr;
                        recipe->seg_list[loadable_seg_num - 1U].memsz = p64->p_memsz;
                        SWIV_DEBUG_LOG("Parsed segment: VA - %llx, PA - %llx, MEMSZ - %llx\n", p64->p_vaddr, p64->p_paddr, p64->p_memsz);
                    } else {
                        ret = PARAMETER_INVALID;
                        break;
                    }
                }
                i++;
                p64++;
            }
        }

        recipe->seg_num = loadable_seg_num;
        recipe->crc = seg->crc;
        recipe->loadable = load_type;
        SWIV_DEBUG_LOG("SWIV context recipe: seg_num - %u, crc - %x, loadable - %u\n", recipe->seg_num, recipe->crc, recipe->loadable);
    }

    return ret;
}

sl_s32_t swiv_verify(const struct swiv_context *recipe)
{
    sl_s32_t ret = SWIV_SUCCESS;
    sl_u32_t i = 0U;
    sl_u32_t crc = 0U;
    sl_u32_t temp_crc = 0U;
    struct scatter_buffer buf_list[SEG_MAX_NR];
    const struct swiv_segment_info *seg = SL_NULL;
    struct swiv_segment *swiv_seg = SL_NULL;
    sl_u32_t num = 0U;
    error_type crc_ret = SUCCESS;
    
    if (recipe == SL_NULL) {
        ret = PARAMETER_INVALID;
    } else {
        seg = recipe->seg_list;
        num = recipe->seg_num;
        SWIV_DEBUG_LOG("SWIV context recipe info: crc - %x, loadable - %u, seg_num - %u, seg - %x \n", recipe->crc, recipe->loadable, num, seg);

        if ((num == 0U) || (num > SEG_MAX_NR)) {
            ret = PARAMETER_INVALID;
        } else {
            for (i = 0U; i < num; i++) {
                buf_list[i].buf = ((char *)(uintptr_t)seg->paddr);
                buf_list[i].len = (sl_size_t)seg->memsz;
                seg++;
            }

            if (recipe->loadable == SEG_LOAD) {
                /* Point to SWIV segment */
                seg--;
                swiv_seg = ((struct swiv_segment *)(uintptr_t)(seg->paddr));
                temp_crc = swiv_seg->crc;
                swiv_seg->crc = 0U;

                crc_ret = crc32_generate_scatter(buf_list, num, &crc);
                SWIV_DEBUG_LOG("Calculated CRC32: %x\n", crc);
                if (crc_ret == INVALID_PARAMETER) {
                    ret = PARAMETER_INVALID;
                } else if (crc != recipe->crc) {
                    ret = CRC_MISMATCH;
                } else {
                    ret = SWIV_SUCCESS;
                }

                /* Restore original CRC checksum */
                swiv_seg->crc = temp_crc;
            } else {
                crc_ret = crc32_generate_scatter(buf_list, num, &crc);
                SWIV_DEBUG_LOG("Calculated CRC32: %x\n", crc);
                if (crc_ret == INVALID_PARAMETER) {
                    ret = PARAMETER_INVALID;
                } else if (crc != recipe->crc) {
                    ret = CRC_MISMATCH;
                } else {
                    ret = SWIV_SUCCESS;
                }
            }
        }
    }
    SWIV_DEBUG_LOG("%s: Calculated crc = 0x%x, stored crc = 0x%x, ret value = %d \n\r", __func__, crc, recipe->crc, ret);

    return ret;
}
