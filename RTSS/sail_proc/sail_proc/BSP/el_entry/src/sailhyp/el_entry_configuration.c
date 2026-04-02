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

    $Header:   $
    $DateTime:  $
    $Author:   $

    ===========================================================================
*/
#include <libfdt.h>
#include "fdt_utils.h"
#include <stdbool.h>
#include "common_functions.h"

extern uint32_t is_initSMP_enabled;
extern uint32_t is_el2_wdt_enabled;
extern uint32_t is_el2_ext_wdg_enabled;
extern uint32_t is_secondarycore_wfi_enabled;
extern uint32_t is_warminit_loadelf_enabled;
extern uint32_t icb_el2_init_core;
extern uint32_t smp_os_image_cfg;
extern uint32_t TimerKConfig;

bool el_entry_read_dts(void)
{
    void *pDTB = NULL;
    int32_t root_offset = 0U;
    pDTB = fdt_get_dtb();

   

    if (NULL != pDTB)
    {
		root_offset = fdt_path_offset(pDTB, "/EL2_boot_configuration");
        if (root_offset != 0) 
        {
            (void)fdt_getprop_u32(pDTB,root_offset, "initSMP_enable", &is_initSMP_enabled);
            (void)fdt_getprop_u32(pDTB,root_offset, "wdt_enable", &is_el2_wdt_enabled);
            (void)fdt_getprop_u32(pDTB,root_offset, "secondarycore_wfi_enable", &is_secondarycore_wfi_enabled);
            (void)fdt_getprop_u32(pDTB,root_offset, "warminit_loadelf_enable", &is_warminit_loadelf_enabled);
            (void)fdt_getprop_u32(pDTB,root_offset, "icb_el2_init_core", &icb_el2_init_core);
            (void)fdt_getprop_u32(pDTB,root_offset, "SMP_os_image_mask", &smp_os_image_cfg);
            (void)fdt_getprop_u32(pDTB,root_offset, "TimerKConfig", &TimerKConfig);
            return TRUE;
        }
    }
    return FALSE;
}
