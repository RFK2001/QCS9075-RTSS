/*
===========================================================================
*/
/**
    @file  elfloader_global_whitelist.c
    @brief global whitelist implementation

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

    $Header: $
    $DateTime: $
    $Author: $

    ===========================================================================
*/

#include "types.h"
#include "elf_header.h"
#include "elf_util.h"
#include "elfloader_def.h"
#include "elfloader_image_id.h"
#include "elfloader_auth.h"
#include "secboot_swid.h"


typedef struct {
    const char *guidString;
    uint16      sec_image_id;
} ElfloaderGuidSecImageIdType;

static ElfloaderGuidSecImageIdType g_guid_sec_image_id_table[] =
{
    {.guidString = SAIL_SW1_GUID_PRIMARY,             .sec_image_id = SECBOOT_SAIL_SW1_SW_TYPE},   //0x55
    {.guidString = SAIL_SW2_GUID_PRIMARY,             .sec_image_id = SECBOOT_SAIL_SW2_SW_TYPE},   //0x56
    {.guidString = SAIL_SW3_GUID_PRIMARY,             .sec_image_id = SECBOOT_SAIL_SW3_SW_TYPE},   //0x77
    {.guidString = SAIL_SW4_GUID_PRIMARY,             .sec_image_id = SECBOOT_SAIL_SW4_SW_TYPE},   //0x78
    {.guidString = SAIL_SEC_ELF_GUID_PRIMARY,         .sec_image_id = SECBOOT_SEC_ELF_SW_TYPE},    //0x2B
    {.guidString = SAIL_DBG_POLICY_GUID_PRIMARY,      .sec_image_id = SECBOOT_APDP_SW_TYPE},       //0x200
    {.guidString = SAIL_SW1_GUID_BACKUP,              .sec_image_id = SECBOOT_SAIL_SW1_SW_TYPE},
    {.guidString = SAIL_SW2_GUID_BACKUP,              .sec_image_id = SECBOOT_SAIL_SW2_SW_TYPE},
    {.guidString = SAIL_SW3_GUID_BACKUP,              .sec_image_id = SECBOOT_SAIL_SW3_SW_TYPE},
    {.guidString = SAIL_SW4_GUID_BACKUP,              .sec_image_id = SECBOOT_SAIL_SW4_SW_TYPE},
    {.guidString = SAIL_SEC_ELF_GUID_BACKUP,          .sec_image_id = SECBOOT_SEC_ELF_SW_TYPE},
    {.guidString = SAIL_DBG_POLICY_GUID_BACKUP,       .sec_image_id = SECBOOT_APDP_SW_TYPE}
};

boolean bElfloaderGetImageId(const char *guidString, uint16 *pnImageId, uint8 *pIdx)
{
    uint8 i;

    if ( NULL == guidString || NULL == pnImageId || NULL == pIdx )
    {
        return FALSE;
    }
    *pIdx = 0;
    for ( i = 0; i < sizeof(g_guid_sec_image_id_table) / sizeof(ElfloaderGuidSecImageIdType); i++ )
    {
        if ( NULL != g_guid_sec_image_id_table[i].guidString && 
             strlen(guidString) == strlen(g_guid_sec_image_id_table[i].guidString)  &&
             0 == strcmp(guidString, g_guid_sec_image_id_table[i].guidString))
        {
            *pnImageId = g_guid_sec_image_id_table[i].sec_image_id;
            *pIdx = i;
            return TRUE;
        }
    }
    return FALSE;
}


