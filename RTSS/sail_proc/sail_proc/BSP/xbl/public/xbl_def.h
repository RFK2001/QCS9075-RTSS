/*
===========================================================================
*/
/**
    @file  xbl_def.h
    @brief common defines of xbl

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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/xbl/public/xbl_def.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#ifndef __XBL_DEF_H__
#define __XBL_DEF_H__

#include "types.h"

#define XBL_OK_NOT_DONE                      1
#define XBL_SUCCESS                          0
#define XBL_ERROR                          (-1)
#define XBL_ERROR_NOT_SUPPORTED            (-2)
#define XBL_ERROR_INVALID_PARAM            (-3)
#define XBL_ERROR_NULL_POINTER             (-4)
#define XBL_ERROR_AUTH                     (-5)
#define XBL_ERROR_DATA_INTEGRITY           (-6)
#define XBL_ERROR_NO_PARTITION             (-7)
#define XBL_ERROR_READ_STORAGE             (-8)
#define XBL_ERROR_SYSCALL_FAILURE          (-9)
#define XBL_ERROR_TIMEOUT                  (-10)
#define XBL_ERROR_NO_MEM                   (-11)
#define XBL_ERROR_INVALID_WHITE_LIST       (-12)
#define XBL_ERROR_INVALID_ELF              (-13)
#define XBL_ERROR_INVALID_PHDR             (-14)
#define XBL_ERROR_HASH                     (-15)
#define XBL_ERROR_STORAGE_DRIVER           (-16)
#define XBL_ERROR_CMP_MANDATORY_ONDEMAND_WHITELIST    (-17)
#define XBL_ERROR_QUERY_MANDATORY_WHITELIST           (-18)
#define XBL_ERROR_CMP_USER_ONDEMAND_WHITELIST         (-19)
#define XBL_ERROR_CREATE_FULL_WHITELIST               (-20)
#define XBL_ERROR_STORAGE_OPEN                        (-21)
#define XBL_ERROR_DIGEST_HASH                         (-22)

#define SAIL_SW1_GUID_PRIMARY                         "48f990b1-4e61-4b16-9f76-2244ee819eb3"
#define SAIL_SW2_GUID_PRIMARY                         "e96d074b-6921-49f2-bd7c-c6a0a4bb72e1"
#define SAIL_SW3_GUID_PRIMARY                         "dbba35e0-bc57-453f-9b0c-e8c0193a3e9d"
#define SAIL_SW4_GUID_PRIMARY                         "77458ffe-3bc4-41cc-999e-8a4f4bcb56f8"
#define SAIL_SEC_ELF_GUID_PRIMARY                     "8498942c-6f0e-41e5-957e-206e4df63c1e"
#define SAIL_DBG_POLICY_GUID_PRIMARY                  "19a02f73-e542-4ce9-af87-be5209f4cbaa"
#define SAIL_SW1_GUID_BACKUP                          "025416ff-75ca-475a-9c62-e4c90e4acc2d"
#define SAIL_SW2_GUID_BACKUP                          "a866cb7e-3e25-4c2e-95cd-2dfae9290fba"
#define SAIL_SW3_GUID_BACKUP                          "58af8cc0-33e0-4216-a59a-0356488db42e"
#define SAIL_SW4_GUID_BACKUP                          "4a2f5eb6-d0ca-4525-a0f8-04d5dd55b846"
#define SAIL_SEC_ELF_GUID_BACKUP                      "a9eb764c-8a63-4ec0-aa9f-9ee2a53e5a88"
#define SAIL_DBG_POLICY_GUID_BACKUP                   "04bc082a-6e31-438c-889c-fbeb791ecaec"
#define SAIL_HYP_GUID_PRIMARY                         "8701faa8-baa0-43cf-9c90-3b30495c558e"
#define SAIL_HYP_GUID_BACKUP                          "ccd55b90-28b7-4d96-993f-ac93a512f1eb"

//#define XBL_IMAGE_INFO_MAX_NUM      (XBL_IMAGE_ID_SW3 + 1)
#define XBL_PARTITION_NULL            0
#define XBL_PARTITION_A               1
#define XBL_PARTITION_B               2
#define XBL_GPT_TABLE_NULL            0
#define XBL_GPT_TABLE_PRIMARY         1
#define XBL_GPT_TABLE_SECONDARY       2

#define XBL_IMG_NAME_SIZE_MAX          32
#define XBL_DIGEST_HASH_SIZE_IN_BYTES  48U

typedef struct xbl_mem_whitelist_area_s
{
  uintnt start; /**< Start address of the memory area. Start is inclusive. */
  uintnt end;   /**< End address of the memory area. End is exclusive.*/
} xbl_mem_Loadlist_area_t;

typedef struct xbl_mem_whitelist_param_s
{
  uint32 count;  /**< count of whitelist area. */
  xbl_mem_Loadlist_area_t *area;  /**< Pointer to whitelist area data. */
}xbl_mem_loadlist_param_t;

typedef enum
{
    XBL_BOOT_OPTION_NOT_USED,   /* Not used */
    XBL_BOOT_OPTION_FULL,       /* Load full ELF */
    XBL_BOOT_OPTION_MANDATORY,  /* Load must have segments (skip black listed segments) */
    XBL_BOOT_OPTION_ONDEMAND    /* Load ELF segments matching the given RAM memory whitelist */
}eXblBootOptionType;

typedef enum
{
    XBL_IMAGE_ID_SW1,             /* sailsw1. SW1 must be at 0 index */
    XBL_IMAGE_ID_SW2,             /* sailsw2 */
    XBL_IMAGE_ID_SW3,             /* sailsw3 */
    XBL_IMAGE_ID_SW4,             /* sailsw4 */
    XBL_IMAGE_ID_SEC_ELF,         /* sec elf image must be after SW4 */
    XBL_IMAGE_ID_DBG_POLICY,      /* DBG policy image */
    XBL_IMAGE_ID_HYP,             /* SAIL HYP Image */
    XBL_IMAGE_ID_MAX              /* max number */
} eXblImageIdType;

typedef struct xbl_boot_image_info_s
{
  eXblImageIdType image_id;                   /* [IN] param: XBL_IMAGE_ID_SW1, etc. */
  eXblBootOptionType boot_option;             /* [IN] param: boot option */
  xbl_mem_loadlist_param_t *loadlist;         /* [IN] param: mem loadlist */
}xbl_boot_params_t;

typedef struct
{
    char img_name[XBL_IMG_NAME_SIZE_MAX];    /* Image name */
    uint32_t partition_id;                   /* loaded primary GUID or secondary GUID */
    uint32_t gpt_id;                         /* loaded from primary GPT table or secondary GPT table */
} XBLBootInfoType;

typedef struct
{
    uint32_t HeaderCrcStatus;    /* 0 - error, 1 - pass */
    uint32_t EntryCrcStatus;     /* 0 - error, 1 - pass */
    uint32_t GptSize;            /* in bytes            */
} xbl_verifyGPTtype;

typedef enum
{
    XBL_STORAGE_NOR_FLASH,
    XBL_STORAGE_DDR,
    XBL_STORAGE_MAX
} eXblStorageType;

typedef struct
{
    const char* imgName;             /* Image name */ 
    uint8_t* hashContainer;          /* Hash digest container */
    uint32_t* containerSize;         /* Total Size of container */
    boolean bIsPrimaryPartition;     /* Image Partition True: if primary, False otherwise */
    uint32_t* hashAlgo;              /* Placeholder to indicate hash algo 256/384/512 */
} xbl_digestHashType;

#endif
