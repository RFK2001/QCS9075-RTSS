/* ============================================================================
 * @file  sail_sec_rollback_fuse.h
 * @brief ARB Fuse Info
 *
 * Copyright (c) 2023 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 * ============================================================================
 */

#ifndef SAIL_SEC_ROLLBACK_FUSE_H
#define SAIL_SEC_ROLLBACK_FUSE_H

#include "sail_sec_img_auth.h"

/** <Image ID>, <FUSE Address>, <MASK>
 * All AR fuses to be read from SENSE register
 */
const sail_sec_arb_list_t arb_fuse_img_list[] = {
  /* SW1 Image */
  { SECBOOT_SAIL_SW1_SW_TYPE, 0, 0 },
  
  /* SW2 Image */
  { SECBOOT_SAIL_SW2_SW_TYPE, 0, 0 },

  /* SW3 Image */
  { SECBOOT_SAIL_SW3_SW_TYPE, 0, 0 },

  /* SW4 Image */
  { SECBOOT_SAIL_SW4_SW_TYPE, 0, 0 },

  /* Dev Config Image */
  // { SECBOOT_SAIL_DEVCFG_SW_TYPE, 0, 0 },

  /* Debug Policy Image */
  { SECBOOT_APDP_SW_TYPE, 0, 0 },

  /* SEC.ELF Image (Fuse Blower Image) */
  { SECBOOT_SEC_ELF_SW_TYPE, 0, 0 },
};

const size_t arb_fuse_img_list_size = ARRAY_SIZE(arb_fuse_img_list);

#endif /* SAIL_SEC_ROLLBACK_FUSE_H */
