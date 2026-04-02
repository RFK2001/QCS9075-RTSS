/*
===========================================================================
*/
/**
    @file  elfloader_def.h
    @brief Header of elf loader common defines

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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/xbl/inc/elfloader/elfloader_def.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

/* Include header file guard */
#ifndef __ELF_LOADER_DEF_H__
#define __ELF_LOADER_DEF_H__

/*=========================================================================================================
**                                     Include files                                                     **
=========================================================================================================*/

#include "types.h"
#include "elf_header.h"
#include "sec_img_auth.h"

/*=========================================================================================================
**                                     Local defines and macros                                          **
=========================================================================================================*/

typedef struct {
    Elf32_Phdr *phdr;        /* allocate phdr pointer */
    uint32     memsize;      /* total bytes of phdr */
    uint16     phnum;        /* number of program headers */
    uint16     phentsize;    /* byte size of each phdr */
} phdrInfoType;

typedef struct {
    uint8  *hash;            /* allocated hash mem */
    uint32 ulHashSize;       /* bytes of hash */
} hashSegmentType;

typedef struct {
    uint32_t ulStartAddr;    /* start addr */
    uint32_t ulSize;         /* size */
} bootPartitionInfoType;

typedef enum
{
    PRE_LOADING = 0,                                   /* Initialization before loading */
    LOAD_ELF_HDR = 1,                                  /* Load Elf Header */
    AUTH_ELF_HDR = 2,                                  /* Authenticate Elf Header */
    PROGRAM_HDR = 3,                                   /* Program Header */
    HASH_SEGMENT = 4,                                  /* Hash segment */
    ALLOCATE_IMG_CTXT = 5,                             /* Allocate Image context */
    VERIFY_META = 6,                                   /* Verify Meta Data */
    LOAD_PHDR_SEG = 7,                                 /* Load Program Header Segment */
    VERIFY_SWIV = 8,                                   /* Software Image Verification */
    SECURE_HASH_VERIFY = 9,                            /* Secure Hash Verification */
    DONE_LOAD,                                         /* Image loading is complete */
}load_elf_states;

#define GUID_SIZE                         37                           /* Hyphenated length is 36 + 1 */
typedef struct {
    Elf32_Ehdr                            g_ehdr;                     /* must be the first field. 4 bytes aligned */
    phdrInfoType                          g_phdr_info;                /* phdr info struct. 4 byte alignment */
    hashSegmentType                       g_hashSegment;              /* hash segment. 4 bytes alignment */
    boolean                               g_bInitDone;                /* elf loader open flag */
    bootPartitionInfoType                 g_partition;                /* boot image partition info struct */
    uint16                                count_loadable_segments;
    uint16                                count_loaded_segments;
    uint16                                g_nImageId;                 /* sec auth lib's image id */
    char                                  g_guidString[GUID_SIZE];    /* guid of this boot partition */
    uint8                                 g_nIdx;                     /* Image index table index */
    void                                  *g_spinor_handle;           /* Move the spinor handle to per Loader */
    load_elf_states                       next_state;                 /* Next state in loading img*/
    sec_img_auth_whitelist_area_param_t   *load_List;                 /* Structure  for passing a list and the count */
    boolean                               bBlackList;                 /* If the load_List is black list or white list
                                                                       * Blacklist logic: skip segments fall into the list
                                                                       * Whitelist logic: only load segments fall into the list */
} BootLoaderInfoType;

/*=========================================================================================================
**                          Global typedefs : Enums, Structures Union and other typedefs                 **
=========================================================================================================*/


#endif /*__BOOT_LOADER_DEF_H__*/

/**********************************************************************************************************
**                                        End of file                                                    **
**********************************************************************************************************/
