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

#include "HALhwio.h"
#include "sail_sec_img_auth.h"

/** <Image ID>, <FUSE Address>, <MASK>
 * All AR fuses to be read from SENSE register
 */
const sail_sec_arb_list_t arb_fuse_img_list[] = {
  /* SW1 Image */
  { SECBOOT_SAIL_SW1_SW_TYPE, HWIO_ADDR(SAILSS_SECURITY_CONTROL_ANTI_ROLLBACK_2_0), 0xFFFFFFFF /* SAIL_SW1_31_0  */ },
  { SECBOOT_SAIL_SW1_SW_TYPE, HWIO_ADDR(SAILSS_SECURITY_CONTROL_ANTI_ROLLBACK_2_1), 0x0FFFFFFF /* SAIL_SW1_59_32 */ },
  
  /* SW2 Image */
  { SECBOOT_SAIL_SW2_SW_TYPE, HWIO_ADDR(SAILSS_SECURITY_CONTROL_ANTI_ROLLBACK_3_0), 0xFFFFFFFF /* SAIL_SW2_31_0  */ },
  { SECBOOT_SAIL_SW2_SW_TYPE, HWIO_ADDR(SAILSS_SECURITY_CONTROL_ANTI_ROLLBACK_3_1), 0x0FFFFFFF /* SAIL_SW2_59_32 */ },

  /* SW3 Image */
  { SECBOOT_SAIL_SW3_SW_TYPE, HWIO_ADDR(SAILSS_SECURITY_CONTROL_ANTI_ROLLBACK_4_0), 0xFFFFFFFF /* SAIL_SW3_31_0  */ },
  { SECBOOT_SAIL_SW3_SW_TYPE, HWIO_ADDR(SAILSS_SECURITY_CONTROL_ANTI_ROLLBACK_4_1), 0x0FFFFFFF /* SAIL_SW3_59_32 */ },

  /* SW4 Image */
  { SECBOOT_SAIL_SW4_SW_TYPE, HWIO_ADDR(SAILSS_SECURITY_CONTROL_ANTI_ROLLBACK_5_0), 0xFFFFFFFF /* SAIL_SW4_31_0  */ },
  { SECBOOT_SAIL_SW4_SW_TYPE, HWIO_ADDR(SAILSS_SECURITY_CONTROL_ANTI_ROLLBACK_5_1), 0x0FFFFFFF /* SAIL_SW4_59_32 */ },

  /* Dev Config Image */
  // { SECBOOT_SAIL_DEVCFG_SW_TYPE, HWIO_ADDR(SAILSS_SECURITY_CONTROL_ANTI_ROLLBACK_6_0), 0xFFFFFFFF /* SPARE_R34_B0 to SPARE_R34_B31  */ },
  // { SECBOOT_SAIL_DEVCFG_SW_TYPE, HWIO_ADDR(SAILSS_SECURITY_CONTROL_ANTI_ROLLBACK_6_1), 0x0FFFFFFF /* SPARE_R34_B32 to SPARE_R34_B59 */ },

  /* Debug Policy Image */
  { SECBOOT_APDP_SW_TYPE, HWIO_ADDR(SAILSS_SECURITY_CONTROL_ANTI_ROLLBACK_6_1), 0xF0000000 /* DEBUG_POLICY */ },

  /* SEC.ELF Image (Fuse Blower Image) */
  { SECBOOT_SEC_ELF_SW_TYPE, 0, 0 },
};

const size_t arb_fuse_img_list_size = ARRAY_SIZE(arb_fuse_img_list);

#endif /* SAIL_SEC_ROLLBACK_FUSE_H */
