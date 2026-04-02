/* ============================================================================
 * @file  miheader.h
 * @brief MULTI-IMAGE HEADER FILE
 * This header file contains declarations and type definitions for the
 * Image Header Information.
 *
 * Copyright (c) 2022-2023 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 * ============================================================================
 */

#ifndef MIHEADER_H
#define MIHEADER_H

/*===========================================================================

                           INCLUDE FILES

===========================================================================*/
#include "mibib.h"

/*===========================================================================

                      PUBLIC DATA DECLARATIONS

===========================================================================*/

/* ----------------------------------------------------- */
/*   Image Header Defintion                              */
/* ----------------------------------------------------- */

/*===========================================================================
 Image address constants used for MMC/SDRAM.
===========================================================================*/

#define MI_SDCC_SBL1_IMG_DEST_ADDR   SCL_SBL1_CODE_BASE

#define MI_SDCC_SBL2_IMG_DEST_ADDR     SCL_SBL2_CODE_BASE

#define MI_SDCC_SBL3_IMG_DEST_ADDR     SCL_SBL3_CODE_BASE

#define MI_SDCC_RPM_IMG_DEST_ADDR      SCL_RPM_CODE_BASE

#define MI_SDCC_TZ_IMG_DEST_ADDR       SCL_TZ_CODE_BASE

#define MI_SDCC_AMSS_IMG_DEST_ADDR     SCL_MODEM_CODE_BASE

#define MI_SDCC_APPSBL_IMG_DEST_ADDR   SCL_APPS_BOOT_BASE

#define MI_SDCC_APPS_IMG_DEST_ADDR     SCL_APPS_CODE_BASE

/*===========================================================================
 Image address constants used for NAND/SDRAM.
===========================================================================*/

#define MI_NAND_AMSS_IMG_DEST_ADDR     SCL_MODEM_CODE_BASE

#define MI_NAND_APPSBL_IMG_DEST_ADDR   SCL_APPS_BOOT_BASE

#define MI_NAND_APPS_IMG_DEST_ADDR     SCL_APPS_CODE_BASE

#define MI_NAND_ADSP_Q5_DEST_ADDR      SCL_ADSP_Q5_CODE_BASE

#define MI_NAND_SBL1_IMG_DEST_ADDR     SCL_SBL1_CODE_BASE

#define MI_NAND_SBL2_IMG_DEST_ADDR     SCL_SBL2_CODE_BASE

#define MI_NAND_SBL3_IMG_DEST_ADDR     SCL_SBL3_CODE_BASE

#define MI_NAND_RPM_IMG_DEST_ADDR      SCL_RPM_CODE_BASE

#define MI_NAND_TZ_IMG_DEST_ADDR       SCL_TZ_CODE_BASE

/* This is used to see the size of each hash value;20 bytes per hash result */
#define SECBOOT_SIGNATURE_SIZE  20   /* SHA-1 digest size  */

/* These are the PFLAG values for R,W,X in the ELF header (bits 0-3) as defined
 * in the latest ELF documentation is at
 * http://www.caldera.com/developers/gabi/latest/ch5.pheader.html
 * Used QCSBL to determine if a segment is writeable or not
 */
#define MI_ELF_PFLAGS_R            0x4
#define MI_ELF_PFLAGS_W            0x2
#define MI_ELF_PFLAGS_X            0x1

#ifndef _ARM_ASM_
/************************************************************/
/*      Image Type Enum definition is moved to mibib.h      */
/************************************************************/

/* Image component in order, code, signature, certificate */
typedef enum
{
  NONE_SEG =0,
  CODE_SEG,      /* Code        */
  SIGNATURE_SEG, /* Signature   */
  CERT_SEG,      /* Certificate */
  MAX_ITEM = 0x7FFFFFFF
}image_component_type;

/* enum for unified boot OS type */
typedef enum
{
  BMP_BOOT_OS= 0x0,
  WM_BOOT_OS = 0x1,
  ANDROID_BOOT_OS = 0x2,
  CHROME_BOOT_OS = 0x3,
  SYMBIAN_BOOT_OS = 0x4,
  LINUX_BOOT_OS = 0x5,
  MAX_OS = 0x7FFFFFFF
} boot_OS_type;

/* updated the mi_boot_image_header_type to support double signing */

typedef struct
{
  uint32 res1;                /* Reserved for compatibility: was image_id */
  uint32 header_vsn_num;      /* Reserved for compatibility: was header_vsn_num */
  uint32 qc_signature_size;   /* Reserved for compatibility: was image_src */
  uint32 qc_cert_chain_size;  /* Reserved for compatibility: was image_dest_ptr */
  uint32 image_size;          /* Size of complete hash segment in bytes */
  uint32 code_size;           /* Size of hash table in bytes */
  uint32 signature_ptr;       /* For compatibility made signature_ptr */
  uint32 oem_signature_size;  /* Size of the attestation signature in bytes */
  uint32 cert_chain_ptr;      /* For compatibility made cert_chain_ptr */
  uint32 oem_cert_chain_size; /* Size of the attestation chain in bytes */
} mi_boot_image_header_type;

/* mbn v6 mi_boot_image_header_type */
typedef struct
{
  uint32 res1;                /* Reserved for compatibility: was image_id */
  uint32 res2;                /* Reserved for compatibility: was header_vsn_num */
  uint32 qc_signature_size;   /* Reserved for compatibility: was image_src */
  uint32 qc_cert_chain_size;  /* Reserved for compatibility: was image_dest_ptr */
  uint32 image_size;          /* Size of complete hash segment in bytes */
  uint32 code_size;           /* Size of hash table in bytes */
  uint32 res5;                /* Reserved for compatibility: was signature_ptr */
  uint32 oem_signature_size;  /* Size of the attestation signature in bytes */
  uint32 res6;                /* Reserved for compatibility: was cert_chain_ptr */
  uint32 oem_cert_chain_size; /* Size of the attestation chain in bytes */
  uint32 qc_metadata_size;    /* QC Metadata size */
  uint32 oem_metadata_size;   /* OEM Metadata size */
} mi_boot_image_header_v6_type;

typedef struct
{
  image_type image_id;       /* Identifies the type of elf image this header
                                 represents (OEM SBL, AMSS, Apps boot loader,
                                 etc.). */
  uint32 image_src;          /* Location of elf image in flash: Address of
                                 image in NOR or page/sector offset to image
                                 from page/sector 0 in NAND/SUPERAND. */
} elf_image_info_type;

typedef struct
{
  uint32         magic_number1;         /* magic number 1 */
  uint32         version;               /* cookie version number */
  boot_OS_type   OS_type;               /* the OS type to boot into */
  uint32         boot_apps_parti_entry; /* start address in storage device of the APPS partition;
                                         NAND build from partition.c; eMMC build from MBR */
  uint32         boot_apps_size_entry;  /* Size in Bytes of APPS Kernel in APPS partition to be loaded */
  uint32         boot_apps_ram_loc;     /* location to copy APPS Kernel into RAM */
  void*          reserved_ptr;          /* reserve pointer */
  uint32         reserved_1;            /* reserve for future use */
  uint32         reserved_2;            /* reserve for future use */
  uint32         reserved_3;            /* reserve for future use */
} mi_boot_cookie_type;

typedef struct
{
    mi_boot_image_header_type image_header;
    mi_boot_cookie_type       boot_cookie;
}mi_boot_header_cookie_type;

/*===========================================================================
                      PUBLIC FUNCTION DECLARATIONS
===========================================================================*/


#endif  /* _ASM_ARM_ */
#endif  /* MIHEADER_H */

