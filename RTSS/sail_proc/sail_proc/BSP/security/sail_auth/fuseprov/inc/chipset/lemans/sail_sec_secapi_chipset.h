/* ============================================================================
 * @file  sail_sec_secapi_chipset.h
 * @brief SAIL Security api chipset specific definitions/routines
 *
 * Copyright (c) 2022-2023 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 * ============================================================================
 */

#ifndef SAIL_SEC_SECAPI_CHIPSET_H
#define SAIL_SEC_SECAPI_CHIPSET_H

#include "types.h"
#include "IxErrno.h"
#include "sail_sec_secapi.h"


#define SAIL_SEC_SECAPI_BIST_CTRL_ADDR                                HWIO_SAILSS_SECURITY_CONTROL_QFPROM_BIST_CTRL_ADDR
/* The bit 1 of the ERROR1 register (bit32 in the complete 64 bit ERROR region (ERROR 0&1 combined)),
   is the SHK region bit of QFPROM_BIST_ERROR register.
   This macro is a mask for a 32 bit value read from the register.
 
   Since the SHK bit comes under ERROR1, which is MSB part of the BIST_CTRL_ERROR region,
   add the target in the list where the macro SHK_BIST_CHECK_IN_ERROR1 is defined
   in \securemsm\trustzone\qsee\services\fuseprov\build\SConscript file,
   to validate this mask against the most 32bits read from the BIST ERROR region. */
#define SAIL_SEC_SECAPI_BIST_ERROR_CHECK_SHK_VALU                     (0x00000001U)

/**
 * define the number of fuse row to check by secapi to verify if fuses for the related
 * feature are blown or not.
 */
#define SAIL_SEC_SECAPI_CHECK_FUSE_INFO_ONE_ROW  (0x2U)
#define SAIL_SEC_SECAPI_CHECK_FUSE_INFO_TWO_ROW  (0x3U)

/* address, lsb, msb, lsb_pattern, msb_pattern */
extern secctrl_check_fuse_info_t sail_sec_secapi_debug_disabled[SAIL_SEC_SECAPI_CHECK_FUSE_INFO_ONE_ROW];
extern secctrl_check_fuse_info_t sail_sec_secapi_rd_wr_perm[SAIL_SEC_SECAPI_CHECK_FUSE_INFO_TWO_ROW];
extern secctrl_check_fuse_info_t sail_sec_secapi_fec_en[SAIL_SEC_SECAPI_CHECK_FUSE_INFO_ONE_ROW];
extern secctrl_check_fuse_info_t sail_sec_secapi_fec_en_pk_hash[SAIL_SEC_SECAPI_CHECK_FUSE_INFO_ONE_ROW];
extern secctrl_check_fuse_info_t sail_sec_secapi_anti_rollback[SAIL_SEC_SECAPI_CHECK_FUSE_INFO_ONE_ROW];
extern secctrl_check_fuse_info_t sail_sec_secapi_rpmb_provision[SAIL_SEC_SECAPI_CHECK_FUSE_INFO_ONE_ROW];
#endif // SAIL_SEC_SECAPI_CHIPSET_H
