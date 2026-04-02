/* ============================================================================
 * @file  sail_sec_target.h
 *
 * Copyright (c) 2018, 2022-23 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 * ============================================================================
 */

#ifndef _XBL_SEC_TARGET_H
#define _XBL_SEC_TARGET_H

/*===========================================================================

                           EDIT HISTORY FOR FILE

This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.

when       who     what, where, why
--------   ---     ---------------------------------------------------------- 
10/20/16   jp      Added support for enabling CE BAM for xbl_sec
============================================================================*/
#define XBL_SEC_IMG_WHITELIST_LEN       (8)

/* Image base and size */
#define XBL_SEC_IMG_BASE                0x14900000
#define XBL_SEC_IMG_SIZE                0x28000

/* stack base and size */
#define XBL_SEC_STACK_SIZE              0x3000  /* 12KB */
#define XBL_SEC_STACK_BASE              XBL_SEC_IMG_BASE

/* Page table base and size */
#define XBL_SEC_L1_PT_SIZE 			  	0x4000  /* 16KB */
#define XBL_SEC_L2_PT_NUM				6  /*Available or reserved number of L2 pagetables*/
#define XBL_SEC_L2_PT_SIZE 				(1024 * XBL_SEC_L2_PT_NUM)

#define L1_BLOCK_SIZE (ONE_GB)
#define L2_BLOCK_SIZE (TWO_MB)
#define L3_BLOCK_SIZE (FOUR_KB) 

#define BOOT_IMEM_BASE                  0x14800000
#define BOOT_IMEM_SIZE                  0x180000 /*1.5 MB*/

#define DDR_MEM_BASE                    0x80000000
#define DDR_MEM_SIZE                    0x80000000 /* 2 GB */

#define SHRM_IMG_BASE                   0x0
#define SHRM_IMG_SIZE                   0x0
/* Reserved space in IMEM.
   DO NOT modify! Contact XBL SEC dev team for mem size constraints */
#define XBL_SEC_RESERVED_DATA_MEM_SIZE  0x0
#define XBL_SEC_RESERVED_CODE_MEM_SIZE  0x0

/* Size of ring buffer for logging */
#define XBL_SEC_LOG_BUFFER_SIZE         0x400

#define BOOT_ROM_BASE_ADDR              0x300000
#define BOOT_ROM_SIZE                   0x100000
#define BOOT_ROM_USED_SIZE              0x03C000


#define AOP_CODE_BASE                   0x0B000000            // RPM is replaced by AOP
#define AOP_CODE_SIZE                   0x80000 /* 512 KB */

#define AOP_DATA_BASE                   0x0B0E0000             // RPM is replaced by AOP 
#define AOP_DATA_SIZE                   0x20000 /* 128 KB */

#define BOOT_IMEM_BUFFER_BASE           0x14823000
#define BOOT_IMEM_BUFFER_SIZE           0xDD000/* 0x14823000 - 0x148FFFFF */

#define SAIL_SECDBG_POLICY_BASE         0x080C5000
#define SAIL_SECDBG_POLICY_SIZE         0x3000

/* Revision number of debug policy.  */
#define SAIL_SECDBG_REVISION_NUMBER     7

#define TZ_IMEM_BASE                    0x14680000
#define TZ_IMEM_SIZE                    0x19000

#define TZ_DIAG_MEM_BASE                TZBSP_DIAG_BASE
#define TZ_DIAG_MEM_SIZE                TZBSP_DIAG_SIZE

#define TZ_IMG_BASE                     0
#define TZ_IMG_SIZE                     0

#define TZ_DDR_STATIC_RG_BASE           0x86200000
#define TZ_DDR_STATIC_RG_SIZE           0x100000

#define IMEM_BASE                       0x14680000
#define IMEM_SIZE                       0x40000 /* 256KB */

// PIMEM_BASE is already defined in msmhwiobase.h
//#define PIMEM_BASE                    0x1C000000
#define PIMEM_SIZE                      0x4000000 /* 64 MB */

#define PIMEM_BASE_ADDR                 0x1C000000
#define PIMEM_VAULT_BASE_ADDR           0x86300000

/* Copy XBL SEC page tables to pIMEM once pIMEM is init'd */
#define XBL_SEC_PAGE_TABLE_BASE         XBL_SEC_PIMEM_BASE /* 0x1C1F3000 */
#define XBL_SEC_PAGE_TABLE_SIZE         0x6800 /* 26KB */

#define XBL_SEC_ELF_METADATA_SIZE     	0x1000 /* 4KB */
#define XBL_SEC_ELF_METADATA_BASE       (XBL_SEC_IMG_BASE + XBL_SEC_IMG_SIZE - XBL_SEC_ELF_METADATA_SIZE)

#define TZ_SDI_MEM_BASE                 0x146A5000
#define TZ_SDI_MEM_SIZE                 0x9000

/* Xbl sec L2 TCM area is from 0x14100000 - 40kb up to 0x14100000. */
#define XBL_SEC_L2_TCM_SIZE             0xA000
#define XBL_SEC_L2_TCM_BASE             0x140F6000
#define XBL_SEC_L2_TCM_LIMIT            (XBL_SEC_L2_TCM_BASE + XBL_SEC_L2_TCM_SIZE)


#define PBL_PAGE_TABLE_BASE             (0x14800000)
#define PBL_PAGE_TABLE_SIZE             (0x7000)

/* PBL L2/L3 PT offsets from L1 */
#define PBL_PAGE_TABLE_L2_OFFSET	    (-0x6000)
#define PBL_PAGE_TABLE_L3_OFFSET        (-0x5000)

/* Define the # of extra L2/L3 PTs to allocate when copying PTs to pIMEM */
#define XBL_SEC_NUM_EXTRA_L2_PAGE_TABLE 1
#define XBL_SEC_NUM_EXTRA_L3_PAGE_TABLE 1  

#define XBL_SEC_NUM_L2_TTS              2
#define XBL_SEC_NUM_L3_TTS              4  

/* PBL page table sizes */
#define PBL_NUM_L1_PT                   8   /* max number of PBL L1 pagetables */
#define MMU_L2_PT_SIZE                  512 /* L2 resolves bits [29:21], 2^9=512 entries. And 1GB/2MB = 512 */
#define PBL_NUM_L2_PT                   1   /* max number of PBL L2 pagetables, 1 set of 512 per GB */
#define MMU_L3_PT_SIZE                  512 /* L3 resolves bits [20:12], 2^9=512 entries. And 2MB/4KB = 512 */
#define PBL_NUM_L3_PT                   4   /* max number of PBL L3 pagetables allocated */

 /* 0x5800 = 22 KB */

/* Copy PBL page tables to XBL Loader region.
   Location should be signed off by BOOT team. */
#define XBL_PAGE_TABLE_BASE             0x14833000 /* 24KB */
#define XBL_PAGE_TABLE_SIZE             0x7000 /* 28KB */

/* L2/L3 table offsets relative to L1 */
#define XBL_PAGE_TABLE_L1_BASE          (XBL_PAGE_TABLE_BASE + 0x6000)
#define XBL_PAGE_TABLE_L2_BASE          (XBL_PAGE_TABLE_BASE)
#define XBL_PAGE_TABLE_L3_BASE          (XBL_PAGE_TABLE_BASE + 0x1000)

#define XBL_LOADER_BASE                 0x14800000
#define XBL_LOADER_SIZE                 0x180000 /* 1.5MB */

#define XBL_LOADER_SDI_IMEM_BASE        0x146AE000
#define XBL_LOADER_SDI_IMEM_SIZE        0xD000 /* 52KB */

#define DDR_REMAP_REG_LOCK_MSK          0x3FFFFFFF
#define DDR_REMAP_REG_MODEM_LOCK_MSK    DDR_REMAP_REG_LOCK_MSK
#define DDR_REMAP_REG_PROTNS_LOCK_MSK   DDR_REMAP_REG_LOCK_MSK
#define DDR_REMAP_REG_SP_LOCK_MSK       DDR_REMAP_REG_LOCK_MSK

#define XBL_SEC_CRYPTO_BAM_SIZE         0x0
#define CRYPTO_HASH_IMEM_DATA_BYTE_SIZE (0x400)

#define XBL_SEC_OEM_MISC_SIZE           0
#define XBL_SEC_QTI_MISC_SIZE           0
#define XBL_SEC_OEM_MISC_ADDR           0
#define XBL_SEC_QTI_MISC_ADDR           0

#define XBL_SEC_CODE_DATA_END           XBL_SEC_QTI_MISC_ADDR

#define TTBR_IRGN_WB_WA                 ((0 << 0) | (1 << 6))
#define TTBR_ORGN_WB_WA                 ((0 << 4) | (1 << 3))
#define TTBR_INNR_SHARED                ((1 << 5) | (1 << 1))

#define PRRR 							0xFE0BAAA4
#define NMRR							0x76807680
#define TZ_REGION_IMEM_BASE				IMEM_BASE
#define TZ_REGION_IMEM_SIZE				IMEM_SIZE
#define TZ_REGION_DDR_BASE              PIMEM_BASE_ADDR     
#define TZ_REGION_DDR_SIZE              PIMEM_SIZE 

#endif /* _XBL_SEC_TARGET_H */
