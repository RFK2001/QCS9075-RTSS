/******************************************************************************

    Copyright (c) 2021-2023 Qualcomm Technologies, Inc.
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
    
******************************************************************************/

#ifndef PBL_SAIL_TEE_SHARED_H
#define PBL_SAIL_TEE_SHARED_H

/**===========================================================================
 **
 **                        PRIMARY BOOT LOADER
 **                        -------------------
 ** FILE
 **     pbl_sail_tee_shared.h
 **
 ** GENERAL DESCRIPTION
 **     This header file contains PBL-SAIL_TEE shared data structure
 **     specific details.
 **
 **     Any new shared data that has to be passed to SAIL TEE should be
 **     added in this file. Any dependencies, like enums, defines etc ...
 **     that are supposed to be passed in this structure should be present
 **     in this file.
 **
 **     SAIL TEE code relies heavily on this structure and hence
 **     everytime there is a change in the shared data-structure
 **     (additions/deletions of fields/new values etc) ... structure
 **     version should be incremented appropriately.
 **
 **     Any new shared data field that has to be added has to be
 **     at the end of the structure.
 **
 **     NOTE:
 **     -----
 **
 **     ANY CHANGES INT THIS FILE OR ANY FIELDS RELATED TO THE
 **     SHARED DATA STRUCTURE MUST BE REVIEWED WITH BL IMAGE
 **     OWNERS.
 **
 **==========================================================================*/

/******************************************************************************
                                MODULE INCLUDES
                         ADD NEW ONES UNDER THIS LINE
******************************************************************************/
#include "types.h"

/******************************************************************************
                             PUBLIC MACROS/DEFINES
                         ADD NEW ONES UNDER THIS LINE
******************************************************************************/
/* Shared data structure Version */
/* Version Format: 0xMMMMNNNN
          MMMM : Major Version
          NNNN : Minor Version */
#define PBL_DEBUG_SHARED_DATA_VERSION_V1 0x00010000
#define PBL_SAIL_TEE_SHARED_DATA_VERSION_V1 0x00010000
#define PBL_APPS_CACHE_MPU_SHARE_DATA_VERSION_V1 0x00010000
#define PBL_ELF_IMAGE_SHARED_DATA_VERSION_V1 0x00010000
#define PBL_PRNG_SHARED_DATA_VERSION_V1 0x00010000
#define PBL_TIMESTAMP_SHARED_DATA_VERSION_V1 0x00010000

#define PBL_SAIL_TEE_SHARED_DATA_VERSION_V2 0x00010001
#define SAIL_TEE_RESERVED_LENGTH 32

/******************************************************************************
                         PUBLIC TYPES and TYPE-DEFINES
                         ADD NEW ONES UNDER THIS LINE
******************************************************************************/
#ifndef _ARM_ASM_

/* Define the FLASH types.

   Based on the boot option that is configured, this field
   will indicate the exact boot media that has been used to
   successfully load the BL image.

   If control gets transferred to BL then the field will
   not have NO_FLASH*/
typedef enum {
  NO_FLASH = 0,
  NOR_FLASH = 1,
  NAND_FLASH = 2,
  ONENAND_FLASH = 3,
  SDC_FLASH = 4,
  MMC_FLASH = 5,
  SPI_FLASH = 6,
  PCIE_FLASH = 7,
  UFS_FLASH = 8,
  RESERVED_0_FLASH = 9,
  RESERVED_1_FLASH = 10,
  USB_FLASH = 11,              /* this is not a real flash type, it's used only for sw_type */
  SIZE_FLASH_TYPE = 0x7FFFFFFF /* Force 4 byte alignment */
} boot_flash_type;

/* Define the types of flash controllers that may be in use */
typedef enum {
  NO_CTRL,                          /* Invalid controller     */
  NOR_CTRL,                         /* NOR controller         */
  NAND_CTRL,                        /* NAND controller        */
  SFLASH_CTRL,                      /* Sync flash controller          */
  SDC_CTRL,                         /* Secure Digital Card controller */
  SPI_CTRL,                         /* SPI controller         */
  UFS_CTRL,                         /* UFS controller         */
  USB_CTRL,                         /* USB controller         */
  SIZE_FLASH_CTRL_TYPE = 0x7FFFFFFF /* Force 4 byte alignment */
} boot_flash_ctrl_type;

typedef struct {
  uint32 phy_parti_size;
} boot_flash_spi_mem_type;

typedef enum { SPI_PORT, SPI_PORT_INVALID, SPI_PORT_SIZE = 0x7FFFFFFF } boot_flash_spi_port_type;

/* This defines the MMC bus width */
typedef enum {
  SPI_BUSWIDTH_1BIT = 0,
  SPI_BUSWIDTH_4BIT = 1,
  SPI_BUSWIDTH_8BIT = 2,
  SPI_BUSWIDTH_COUNT,
  SPI_BUSWIDTH_SIZE = 0x7FFFFFFF
} pbl_spi_buswidth_type;

typedef struct {
  uint32 chip_select;
  uint32 addr_len;
  boot_flash_spi_port_type port; /* BLSP-QUP SPI Port where device was detected */
  pbl_spi_buswidth_type data_width;
  boot_flash_spi_mem_type mem;
  uint32 is_gpt_parti;                  // type changed from boolean to uint32, because SAIL uses unsigned char for boolean but PBL use uint32 for boolean
  uint32 is_primary_table;              // type changed from boolean to uint32
  uint64 starting_lba;
  uint64 ending_lba;
} boot_flash_shared_spi_dev_type;

/* This defines Flash shared data */
typedef struct {
  uint32 shared_data_version;
  boot_flash_type type;           /* Type of flash                      */
  uint32 CS_base;                 /* Base address of chip select device
                                              is connected to.                   */
  uint32 data_width;              /* Bit width of device ie: 8bit/16bit */
  boot_flash_ctrl_type ctrl_type; /* Controller used to interface with
                                              device                             */
  uint32 is_secondary_guid;      /* TRUE if Secondary GUID. type changed from boolean to uint32            */

  union {
    boot_flash_shared_spi_dev_type spi; /* Shared info for SPI device   */
  } dev_info;
} boot_flash_shared_dev_info_type;

typedef struct {
  uint32 shared_data_version;
  void *elf_img_meta_info;           /* sec_img_auth_elf_info_type */
  uint32 num_of_bytes_read_from_elf; /* Total number of bytes ready by PBL from ELF */
} pbl_elf_img_share_info_type;
typedef struct {
  uint32 shared_data_version;
  uint32 pbl_sail_init_timestamp;
  uint32 pbl_sail_pre_bist_timestamp;
  uint32 pbl_sail_post_bist_timestamp;
  uint32 bootable_media_detect_timestamp;
  uint32 sail_tee_elf_metadata_loading_timestamp;
  uint32 sail_tee_hash_seg_auth_timestamp;
  uint32 sail_tee_elf_loadable_segment_loading_timestamp;
  uint32 sail_tee_elf_segs_hash_verify_timestamp;
  uint32 sail_tee_segs_hash_verify_timestamp;
  uint32 pbl_populate_shared_data_and_exit_timestamp;
} pbl_sail_timestamp_type;

//ToDo : Remove after resolving pbl_elf_loader
typedef struct _bl_sec_elf_seg_info_type {
  uint32 shared_data_version;
  uint32 bl_sec_seg_index;
  uint64 bl_sec_seg_base_addr;
  uint64 bl_sec_seg_filesz;
  uint64 bl_elf_entry_pointer;
  uint64 bl_sec_seg_aligned_base_address;
  uint64 bl_sec_seg_aligned_end_address;
} bl_sec_elf_seg_info_type;

/*---------------------------------------------------------------------------
  Defines the data structure that is filled with data that is shared with
  the BL image. It may be necessary for the BL to make a deep copy of
  this structure for its own use if it wipes out PBL memory. Below structure for Lemans
---------------------------------------------------------------------------*/
typedef struct _pbl_sail_tee_shared_data_type_v1 {
  /* Shared data structure version */
  uint32 sail_tee_sdata_version;

  /* PBL version */
  uint32 pbl_version;

  /* PBL Patch version */
  uint32 pbl_patch_version;

  /* PBL Boot option configured in the fuse */
  uint32 boot_option_fuse_val;

  /* BL loader authentication state */
  uint32 sail_tee_auth_enabled;

  //TS buffer to be shared with TEE image
  void *pbl_ts_buffer;

  /* PBL shared data structure, maps to: pbl_sdata_type */
  void *pbl_debug_shared_data;

  /* Pointer to elf image shared data structure, maps to: pbl_elf_img_share_info_type */
  void *pbl_elf_shared_data;

  /* Pointer to Secboot shared data structure, maps to: secboot_pbl_shared_info_type */
  void *pbl_secboot_shared_data;

  /* Pointer to flash shared data structure, maps to: boot_flash_shared_dev_info_type */
  void *pbl_flash_shared_data;

  /* Pointer to ECC shared data structure,maps to: crypto_ecc_shared_info_type */
  void *pbl_ecc_shared_data;

  /* Pointer to cipher Hash shared data structure,maps to: crypto_hash_cipher_shared_info_type */
  void *pbl_crypto_hash_cipher_shared_data;

  /*Reserved fields*/
  uint32 reserved_fields[SAIL_TEE_RESERVED_LENGTH];
} pbl_sail_tee_shared_data_type_v1;

/*---------------------------------------------------------------------------
  Defines the data structure that is filled with data that is shared with
  the BL image. It may be necessary for the BL to make a deep copy of
  this structure for its own use if it wipes out PBL memory. Below structure for Monaco
---------------------------------------------------------------------------*/
typedef struct _pbl_sail_tee_shared_data_type_v2 {
  /* Shared data structure version */
  uint32 sail_tee_sdata_version;

  /* PBL version */
  uint32 pbl_version;

  /* PBL Patch version */
  uint32 pbl_patch_version;

  /* PBL Boot option configured in the fuse */
  uint32 boot_option_fuse_val;

  /* BL loader authentication state */
  uint32 sail_tee_auth_enabled;

  /* Pre-bist timestamp in ticks */
  uint32 pbl_pre_bist_ts;
  
  //TS buffer to be shared with TEE image
  void *pbl_ts_buffer;

  /* PBL shared data structure, maps to: pbl_sdata_type */
  void *pbl_debug_shared_data;

  /* Pointer to elf image shared data structure, maps to: pbl_elf_img_share_info_type */
  void *pbl_elf_shared_data;

  /* Pointer to Secboot shared data structure, maps to: secboot_pbl_shared_info_type */
  void *pbl_secboot_shared_data;

  /* Pointer to flash shared data structure, maps to: boot_flash_shared_dev_info_type */
  void *pbl_flash_shared_data;

  /* Pointer to ECC shared data structure,maps to: crypto_ecc_shared_info_type */
  void *pbl_ecc_shared_data;

  /* Pointer to cipher Hash shared data structure,maps to: crypto_hash_cipher_shared_info_type */
  void *pbl_crypto_hash_cipher_shared_data;

  /*Reserved fields*/
  uint32 reserved_fields[SAIL_TEE_RESERVED_LENGTH];
} pbl_sail_tee_shared_data_type_v2;


/******************************************************************************
                            PUBLIC DATA DECLARATION
                         ADD NEW ONES UNDER THIS LINE
******************************************************************************/

/******************************************************************************
                         PUBLIC FUNCTION DECLARATIONS
                         ADD NEW ONES UNDER THIS LINE
******************************************************************************/

#endif /* _ARM_ASM_ */

#endif /* PBL_SAIL_TEE_SHARED_H */
/*=============================================================================
                                  END OF FILE
=============================================================================*/
