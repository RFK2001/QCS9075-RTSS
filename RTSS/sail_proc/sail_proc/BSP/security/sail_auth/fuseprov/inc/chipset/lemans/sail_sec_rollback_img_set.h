/* ============================================================================
 * @file  sail_sec_rollback_img_set.h
 * @brief This file contains definition of the rollback version image set table.
 *
 * Copyright (c) 2023 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 * ============================================================================
 */

#ifndef SAIL_SEC_ROLLBACK_IMG_SET_H
#define SAIL_SEC_ROLLBACK_IMG_SET_H

/* ----------------------------------------------------------------------------
 * Headers
 * ----------------------------------------------------------------------------
 */
#include "sail_sec_rollback_version_fuseprov.h"
#include "sail_sec_hwio.h"
#include "HALhwio.h"
#include "secboot_swid.h"

/* ----------------------------------------------------------------------------
 * PUBLIC DATA DECLARATIONS
 * ----------------------------------------------------------------------------
 */
/* RAW region for write and CORR region for read */
#define ROLLBACK_FUSE_RAW_REGION_MIN  (HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_READ_PERMISSIONS_LSB_ADDR)
#define ROLLBACK_FUSE_RAW_REGION_MAX  (HWIO_SAILSS_SECURITY_CONTROL_QFPROM_BLOW_TIMER_ADDR)
#define ROLLBACK_FUSE_CORR_REGION_MIN (HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_ADDR)
#define ROLLBACK_FUSE_CORR_REGION_MAX (HWIO_SAILSS_SECURITY_CONTROL_SEC_CTRL_HW_VERSION_ADDR)

// Declaration (to fix MISRA)
struct rollback_version_img_set rollback_version_img_set_table[];

// Definition
struct rollback_version_img_set rollback_version_img_set_table[] =
{
  /* image set 0: SAIL HYP Image */
  {
    /* images in this set*/
    {
      SECBOOT_SAIL_HYP_SW_TYPE, 
      SECBOOT_MAX_SW_TYPE 
    },
    
    /* feature_enable_base_addr */
    (uint32 *)HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_ADDR,
    
    /* feature_enable_mask */
    0x1U,
    
    /* version_lsb_base_addr*/
    (uint32 *)HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_ADDR,
    
    /* version_lsb_mask*/
    HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_SAIL_HYP_31_0_BMSK,
    
    /* version_lsb_shift */
    HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_SAIL_HYP_31_0_SHFT,
    
    /* version_msb_base_addr */
    (uint32 *)HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_ADDR,

    /* version_msb_mask */
    HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_SAIL_HYP_59_32_BMSK,
    
    /* version_msb_shift*/
    HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_1_MSB_SAIL_HYP_59_32_SHFT,
    
    /* current_set_version_num*/
    0U
  },

  /* image set 1: SAIL SW1 Image */
  {
    /* images in this set*/
    {
      SECBOOT_SAIL_SW1_SW_TYPE, 
      SECBOOT_MAX_SW_TYPE 
    },
    
    /* feature_enable_base_addr */
    (uint32 *)HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_ADDR,
    
    /* feature_enable_mask */
    0x2U,
    
    /* version_lsb_base_addr*/
    (uint32 *)HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_ADDR,
    
    /* version_lsb_mask*/
    HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_SAIL_SW1_31_0_BMSK,
    
    /* version_lsb_shift */
    HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_SAIL_SW1_31_0_SHFT,
    
    /* version_msb_base_addr */
    (uint32 *)HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_ADDR,

    /* version_msb_mask */
    HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_SAIL_SW1_59_32_BMSK,
    
    /* version_msb_shift*/
    HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_2_MSB_SAIL_SW1_59_32_SHFT,
    
    /* current_set_version_num*/
    0U
  },

  /* image set 2: SAIL SW2 Image */
  {
    /* images in this set*/
    {
      SECBOOT_SAIL_SW2_SW_TYPE, 
      SECBOOT_MAX_SW_TYPE 
    },
    
    /* feature_enable_base_addr */
    (uint32 *)HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_ADDR,
    
    /* feature_enable_mask */
    0x2U,
    
    /* version_lsb_base_addr*/
    (uint32 *)HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_ADDR,
    
    /* version_lsb_mask*/
    HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_SAIL_SW2_31_0_BMSK,
    
    /* version_lsb_shift */
    HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_SAIL_SW2_31_0_SHFT,
    
    /* version_msb_base_addr */
    (uint32 *)HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_ADDR,

    /* version_msb_mask */
    HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_SAIL_SW2_59_32_BMSK,
    
    /* version_msb_shift*/
    HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_3_MSB_SAIL_SW2_59_32_SHFT,
    
    /* current_set_version_num*/
    0U
  },

  /* image set 3: SAIL SW3 Image */
  {
    /* images in this set*/
    {
      SECBOOT_SAIL_SW3_SW_TYPE, 
      SECBOOT_MAX_SW_TYPE 
    },
    
    /* feature_enable_base_addr */
    (uint32 *)HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_ADDR,
    
    /* feature_enable_mask */
    0x2U,
    
    /* version_lsb_base_addr*/
    (uint32 *)HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_ADDR,
    
    /* version_lsb_mask*/
    HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_SAIL_SW3_31_0_BMSK,
    
    /* version_lsb_shift */
    HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_SAIL_SW3_31_0_SHFT,
    
    /* version_msb_base_addr */
    (uint32 *)HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_ADDR,

    /* version_msb_mask */
    HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_SAIL_SW3_59_32_BMSK,
    
    /* version_msb_shift*/
    HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_4_MSB_SAIL_SW3_59_32_SHFT,
    
    /* current_set_version_num*/
    0U
  },

  /* image set 4: SAIL SW4 Image */
  {
    /* images in this set*/
    {
      SECBOOT_SAIL_SW4_SW_TYPE, 
      SECBOOT_MAX_SW_TYPE 
    },
    
    /* feature_enable_base_addr */
    (uint32 *)HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_ADDR,
    
    /* feature_enable_mask */
    0x2U,
    
    /* version_lsb_base_addr*/
    (uint32 *)HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_5_LSB_ADDR,
    
    /* version_lsb_mask*/
    HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_5_LSB_SAIL_SW4_31_0_BMSK,
    
    /* version_lsb_shift */
    HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_5_LSB_SAIL_SW4_31_0_SHFT,
    
    /* version_msb_base_addr */
    (uint32 *)HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_5_MSB_ADDR,

    /* version_msb_mask */
    HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_5_MSB_SAIL_SW4_59_32_BMSK,
    
    /* version_msb_shift*/
    HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_5_MSB_SAIL_SW4_59_32_SHFT,
    
    /* current_set_version_num*/
    0U
  },

  /* image set 6: Debug Policy Image */
  {
    /* images in this set*/
    {
      SECBOOT_APDP_SW_TYPE, 
      SECBOOT_MAX_SW_TYPE 
    },
    
    /* feature_enable_base_addr */
    (uint32 *)HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_OEM_CONFIG_ROW2_MSB_ADDR,
    
    /* feature_enable_mask */
    0x2U,
    
    /* version_lsb_base_addr*/
    NULL,
    
    /* version_lsb_mask*/
    0x0U,
    
    /* version_lsb_shift */
    0x0U,
    
    /* version_msb_base_addr */
    (uint32 *)HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_6_MSB_ADDR,

    /* version_msb_mask */
    HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_6_MSB_DEBUG_POLICY_BMSK,
    
    /* version_msb_shift*/
    HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_6_MSB_DEBUG_POLICY_SHFT,
    
    /* current_set_version_num*/
    0U
  }
};

#endif /* SAIL_SEC_ROLLBACK_IMG_SET_H */
