/* ============================================================================
 * @file  sail_sec_fuseprov_chipset.h
 * @brief Fuse Provisioning chipset specific definitions/routines.
 *
 * Copyright (c) 2023 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 * ============================================================================
 */

#ifndef SAIL_SEC_FUSEPROV_CHIPSET_H
#define SAIL_SEC_FUSEPROV_CHIPSET_H

#include "types.h"
#include "IxErrno.h"
#include "HALhwio.h"
#include "sail_sec_hwio.h"

/*----------------------------------------------------------------------------
* Macros for sec.dat fuse provision
* -------------------------------------------------------------------------*/

/* This are has been carved out from TZ DDR shared region */
#define SAIL_SEC_SECDAT_BUFFER_BASE                  (0x00000000UL)  // the base of sec.dat ddr memory
#define SAIL_SEC_SECDAT_BUFFER_OFFSET                (0x0000UL)  // the offset of sec.dat ddr memory
#define SAIL_SEC_SECDAT_BUFFER_SIZE                  (4096U)     // the size of the shared region

/* qfprom read fuse through lsb address, so RD_WR_PERM_LSB is used here */
#define SAIL_SEC_FUSEPROV_RD_PERM_HWIO_ADDR                          HWIO_ADDR(SAILSS_SECURITY_CONTROL_QFPROM_RAW_READ_PERMISSIONS_LSB)
#define SAIL_SEC_FUSEPROV_WR_PERM_HWIO_ADDR                          HWIO_ADDR(SAILSS_SECURITY_CONTROL_QFPROM_RAW_WRITE_PERMISSIONS_LSB)
#define SAIL_SEC_FUSEPROV_IS_SECBOOT_WR_PERM_BLOWN(qfprom_fuse_data) ((qfprom_fuse_data[0] & HWIO_FMSK(SAILSS_SECURITY_CONTROL_QFPROM_RAW_WRITE_PERMISSIONS_LSB, OEM_SECURE_BOOT_WRITE_DISABLE)) > 0U)
#define SAIL_SEC_FUSEPROV_IS_IMAGE_ENCR_KEY1_BLOWN(qfprom_fuse_data) ((qfprom_fuse_data[0] & HWIO_FMSK(SAILSS_SECURITY_CONTROL_QFPROM_RAW_WRITE_PERMISSIONS_LSB, IMAGE_ENCRYPTION_KEY_1_WRITE_DISABLE)) > 0U)
#define SAIL_SEC_FUSEPROV_IMAGE_ENCR_KEY1_WR_DISABLE                 (HWIO_FMSK(SAILSS_SECURITY_CONTROL_QFPROM_RAW_WRITE_PERMISSIONS_LSB, IMAGE_ENCRYPTION_KEY_1_WRITE_DISABLE))

/*----------------------------------------------------------------------------
 * Macros for mrc fuse provision
 * -------------------------------------------------------------------------*/
#define SAIL_SEC_FUSEPROV_RAW_MRC_2_0_ACTIVATION_LIST               HWIO_ADDR(SAILSS_SECURITY_CONTROL_QFPROM_RAW_MRC_2_0_ROW0_LSB)
#define SAIL_SEC_FUSEPROV_RAW_MRC_2_0_ACTIVATION_LIST_MASK          HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_MRC_2_0_ROW0_LSB_ROOT_CERT_ACTIVATIOM_LIST_BMSK
#define SAIL_SEC_FUSEPROV_RAW_MRC_2_0_REVOCATION_LIST               HWIO_ADDR(SAILSS_SECURITY_CONTROL_QFPROM_RAW_MRC_2_0_ROW1_LSB)
#define SAIL_SEC_FUSEPROV_RAW_MRC_2_0_REVOCATION_LIST_MASK          HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_MRC_2_0_ROW1_LSB_ROOT_CERT_REVOCATION_LIST_BMSK
#define SAIL_SEC_FUSEPROV_MRC_STICKY_BIT_SYM                        SAILSS_SECURITY_CONTROL_QFPROM_WRITE_DISABLE_STICKY_BIT0
#define SAIL_SEC_FUSEPROV_MRC_STICKY_BIT_VAL                        HWIO_SAILSS_SECURITY_CONTROL_QFPROM_WRITE_DISABLE_STICKY_BIT0_REGION1_STICKY_BIT_BMSK
#define SAIL_SEC_FUSEPROV_MRC_STICKY_BIT_SET(sym, val)              HWIO_OUT(sym, val)
#define SAIL_SEC_FUSEPROV_MRC_STICKY_BIT_READ(sym)                  HWIO_IN(sym)

/*----------------------------------------------------------------------------
 * Macros for rot fuse configuration (these macros are not valid for 8996)
 * -------------------------------------------------------------------------*/ 
#define SAIL_SEC_FUSEPROV_CORR_OEM_CONFIG_ROW0_ADDR                   HWIO_ADDR(SAILSS_SECURITY_CONTROL_QFPROM_CORR_OEM_CONFIG_ROW0_LSB)
#define SAIL_SEC_FUSEPROV_CORR_IS_ENCRYPTION_ENABLED(qfprom_fuse_data)  \
   ((qfprom_fuse_data[0] & HWIO_FMSK(SAILSS_SECURITY_CONTROL_QFPROM_CORR_OEM_CONFIG_ROW0_LSB, IMAGE_ENCRYPTION_ENABLE)) > 0U)

/* fuse address for writing the rot sw config */
#define SAIL_SEC_FUSEPROV_RAW_PK_HASH1_ROW4_LSB_ADDR                 HWIO_ADDR(QFPROM_RAW_PK_HASH1_ROW4_LSB)
#define SAIL_SEC_FUSEPROV_SW_ROT_CONFIG_CURRENT_SW_ROT_APPS          HWIO_QFPROM_CORR_PK_HASH1_ROW4_MSB_CURRENT_SW_ROT_APPS_BMSK
#define SAIL_SEC_FUSEPROV_SW_ROT_CONFIG_CURRENT_SW_ROT_MODEM         HWIO_QFPROM_CORR_PK_HASH1_ROW4_MSB_CURRENT_SW_ROT_MODEM_BMSK

/* fuse address for checking/reading the rot sw config */
#define SAIL_SEC_FUSEPROV_CORR_PK_HASH1_ROW4_LSB_ADDR                HWIO_ADDR(QFPROM_CORR_PK_HASH1_ROW4_LSB)

/* fuse address for writing wr permission for rot fuses */
#define SAIL_SEC_FUSEPROV_WR_PERM_ADDR                               HWIO_ADDR(SAILSS_SECURITY_CONTROL_QFPROM_RAW_WRITE_PERMISSIONS_LSB)
#define SAIL_SEC_FUSEPROV_WR_DISABLE_PK_HASH1                        QFPROM_RAW_WRITE_PERMISSIONS_LSB_PK_HASH1_BMSK
#define SAIL_SEC_FUSEPROV_WR_DISABLE_ENC_KEY1                        QFPROM_RAW_WRITE_PERMISSIONS_MSB_IMAGE_ENCRYPTION_KEY1_BMSK
#define SAIL_SEC_FUSEPROV_WR_DISABLE_FEC_EN                          QFPROM_RAW_WRITE_PERMISSIONS_LSB_FEC_ENABLE_BMSK
#define SAIL_SEC_FUSEPROV_WR_DISABLE_WR_PERM                         QFPROM_RAW_WRITE_PERMISSIONS_LSB_WRITE_PERMISSIONS_BMSK

/* fuse address for writing fec en fuses for rot fuses */
#define SAIL_SEC_FUSEPROV_FEC_EN_ADDR                                HWIO_ADDR(SAILSS_SECURITY_CONTROL_QFPROM_RAW_FEC_ENABLES_LSB)
#define SAIL_SEC_FUSEPROV_FEC_EN_PK_HASH1                            HWIO_QFPROM_RAW_FEC_EN_LSB_REGION30_FEC_ENABLE_BMSK // for PK HASH1
#define SAIL_SEC_FUSEPROV_FEC_EN_ENC_KEY1                            HWIO_QFPROM_RAW_FEC_EN_LSB_REGION29_FEC_ENABLE_BMSK // for IMAGE ENC KEY1

#define SAIL_SEC_FUSEPROV_RAW_PK_HASH1_ADDR(n)                       HWIO_QFPROM_RAW_PK_HASH1_ROWn_LSB_ADDR(n)
#define SAIL_SEC_ROT_BYTES_IN_PK_HASH_FUSE_ROW                       (0x7U)

#define SAIL_SEC_FUSEPROV_RAW_ENC_KEY1_ADDR(n)                       HWIO_QFPROM_RAW_IMAGE_ENCR_KEY1_ROWn_LSB_ADDR(n)
#define SAIL_SEC_ROT_BYTES_IN_ENC_KEY_FUSE_ROW                       (0x7U)

/* Cold reset is used to reset after fuseblow by default */
#define SAIL_SEC_FUSEPROV_REQUIRES_WARM_RESET                       (false)

#endif
