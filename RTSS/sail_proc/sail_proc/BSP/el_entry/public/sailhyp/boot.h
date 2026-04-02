/**
 * @file boot.h
 * @brief Sail boot API
 * Header file for the definition of Sail Boot API
 *
 *        Copyright (c) 2021-2023 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
*/


/*===========================================================================

                            EDIT HISTORY FOR FILE

when       who      what, where, why
--------   ---     ------------------------------------------------------------
07.08.21   rrahul       Created
=============================================================================*/

#ifndef BOOT_H
#define BOOT_H

/*===========================================================================
                           INCLUDE FILES
===========================================================================*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "types.h"
#include "arm_acle.h"

/*===========================================================================
                           MACROS
===========================================================================*/
#define SAIL_TEE_RESERVED_LENGTH 32

/*===========================================================================
                           TYPES and TYPEDEFS
===========================================================================*/

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

/* Define the boot mode that may be in use */
typedef enum {
    BOOT_MODE_UNKNOWN = 0,      /* Default Init value*/
    BOOT_MODE_REGULAR,          /* Regular boot flow */
    BOOT_MODE_FASTBOOT_ENTER,   /* Enter Fastboot flow */
    BOOT_MODE_FASTBOOT_BOOT,    /* Fastboot Boot mode */
    BOOT_MODE_FASTBOOT_CONT,    /* Continue with regular bootflow */
    BOOT_MODE_TYPE = 0x7FFFFFFF
} boot_mode_type;

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
  boolean is_gpt_parti;
  boolean is_primary_table;
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
  boolean is_secondary_guid;      /* TRUE if Secondary GUID.            */

  union {
    boot_flash_shared_spi_dev_type spi;     /* Shared info for SPI device   */
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

typedef struct _bl_sec_elf_seg_info_type {
  uint32 shared_data_version;
  uint32 bl_sec_seg_index;
  uint64 bl_sec_seg_base_addr;
  uint64 bl_sec_seg_filesz;
  uint64 bl_elf_entry_pointer;
  uint64 bl_sec_seg_aligned_base_address;
  uint64 bl_sec_seg_aligned_end_address;
} bl_sec_elf_seg_info_type;

typedef struct boot_pbl_shared_data_type
{
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

#ifdef monaco
    /* Pre-bist timestamp in ticks */
  uint32 pbl_pre_bist_ts;
#endif

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
} boot_pbl_shared_data_type;

/*===========================================================================
                           EXTERNS
===========================================================================*/

/*
 *===========================================================================
                          FUNCTIONS
 *===========================================================================*/

void  sailbsp_boot_cold_init(int cpu_id, boot_pbl_shared_data_type* pbl_shared_info);

/*===========================================================================
**  Function :  sailbsp_boot_secondary_init
** ==========================================================================
*/
/*!
*
* @brief
*   sailbsp_boot_secondary_init is the cold boot initialization routine called during power on.
*   This will be called for the secondary core.
*
* @param
*   cpu_index
*   cluster_index
* @par Dependencies
*   Boot core should be up.
* @retval
*   None
* @par Side Effects
*   None
*
*/
void  sailbsp_boot_secondary_init(int cpu_id, int cluster_id);

/*===========================================================================
**  Function :  sailbsp_boot_warm_init
** ==========================================================================
*/
/*!
*
* @brief
*   // Warm (second or later) power-on of any CPU.
*
* @param
*   cpu_index
*   cluster_index
* @par Dependencies
*   Cold boot should be done.And it should have gone to Lower power mode.
* @retval
*   None
* @par Side Effects
*   None
*
*/
// Warm (second or later) power-on of any CPU.
void  sailbsp_boot_warm_init(int cpu_id, int cluster_id);

/*===========================================================================
**  Function :  boot_cpu_get_loaded_image_id
** ==========================================================================
*/
/*!
*
* @brief
*    get the  id of the SW image loaded on the current core.
*
* @param
*   poiner to image_id

* @par Dependencies
*   Cold boot should be done.And a image should have been loaded already.
* @retval
*   error status
* @par Side Effects
*   None
*
*/
uint32_t  boot_cpu_get_loaded_image_id(uint32_t *image_id);

/*===========================================================================
**  Function :  sailbsp_get_imageLoadToDDR_config
** ==========================================================================
*/
/*!
*
* @brief
*   Gets the sailbsp_get_imageLoadToDDR_config from device tree
*
* @param
*   None
* @par Dependencies
*   None
* @retval
*   uint32_t Selected config
* @par Side Effects
*   None
*
*/
uint32_t sailbsp_get_imageLoadToDDR_config(void);

#endif
