#ifndef SECHWIO_H
#define SECHWIO_H

/*****************************************************************************
*
* @file  SecbootHWIO.h (Secboot Hardware internal API)
*
* @brief API to read Security Control Fuses containing authentication
*        information
*
* Copyright (c) 2010-2023 Qualcomm Technologies, Inc.
* All Rights Reserved.
* Confidential and Proprietary - Qualcomm Technologies, Inc.
*****************************************************************************/

#include "HALhwio.h"
#include "sail_sec_hwio.h"
#include <stdint.h>
#include <stddef.h>

#define SECFUSES_DRV(func_name)  func_name ## _secfuses_drv

#ifdef SECHWIO_TEST
#define VIR_HWIO_IN(address) in_dword((uint64)virtual_address(address))
#define VIR_HWIO_INFI(address,bmsk,shft) (address & bmsk) >> shft
#define VIR_HWIO_INF(address,bmsk) address & bmsk
#endif

typedef enum {
    SECCTRL_NO_ERR,
    SECCTRL_DATA_PTR_NULL_ERR,
    SECCTRL_ADDRESS_INVALID_ERR,
    SECCTRL_WRITE_ERR,
  SECCTRL_INVALID_DATA_ERR,
    SECCTRL_ERR_UNKNOWN,
}SECCTRL_ERR_CODE;

/*----------------------------------------------------------------------------
 * Generic Fuse Read/Write Function
 * -------------------------------------------------------------------------*/

static inline uint32 secboot_write_raw_address(uint32 address, uint32 val)
{
#ifdef SECHWIO_TEST
  if (use_test_fuses)
  {
    return 0;
  }
  else
#endif
  {
    uint32 return_value = SECCTRL_ERR_UNKNOWN;
    uint32 test_val = 0x0;

    /* Check for 32bit alignment */
    test_val = (address & 0xFU);

    if((test_val & ~3U) == test_val)
    {
        out_dword((uint64)address, val);
        return_value = SECCTRL_NO_ERR;
    }
    else
    {
        return_value = SECCTRL_ADDRESS_INVALID_ERR;
    }

    return return_value;
  }
}

/*----------------------------------------------------------------------------
 * Read/Write Functions for particular fuses
 * -------------------------------------------------------------------------*/
static inline uint32 secboot_read_SAILSS_SECURITY_CONTROL_FEC_ESR_err_seen(void)
{
#ifdef SECHWIO_TEST
  if (use_test_fuses)
  {
    return VIR_HWIO_INFI(VIR_HWIO_IN(HWIO_SAILSS_SECURITY_CONTROL_FEC_ESR_ADDR), HWIO_SAILSS_SECURITY_CONTROL_FEC_ESR_ERR_SEEN_BMSK, HWIO_SAILSS_SECURITY_CONTROL_FEC_ESR_ERR_SEEN_SHFT);
  }
  else
#endif
  {
    return HWIO_INF(SAILSS_SECURITY_CONTROL_FEC_ESR, ERR_SEEN);
  }
}

static inline void secboot_write_SAILSS_SECURITY_CONTROL_FEC_ESR_err_seen(uint32 val)
{
#ifdef SECHWIO_TEST
  if (use_test_fuses)
  {

    out_dword_masked_ns(VIR_HWIO_IN(HWIO_SAILSS_SECURITY_CONTROL_FEC_ESR_ADDR), HWIO_SAILSS_SECURITY_CONTROL_FEC_ESR_ERR_SEEN_BMSK ,val,in_dword_masked((VIR_HWIO_IN(HWIO_SAILSS_SECURITY_CONTROL_FEC_ESR_ADDR)),HWIO_SAILSS_SECURITY_CONTROL_FEC_ESR_RMSK));
  }
  else
#endif
  {
    HWIO_OUTF(SAILSS_SECURITY_CONTROL_FEC_ESR, ERR_SEEN, val);
  }
}

static inline void secboot_write_SAILSS_SECURITY_CONTROL_FEC_ESR(uint32 val)
{
#ifdef SECHWIO_TEST
  if (use_test_fuses)
  {
    out_dword(VIR_HWIO_IN(HWIO_SAILSS_SECURITY_CONTROL_FEC_ESR_ADDR), val);
  }
  else
#endif
  {
    HWIO_OUT(SAILSS_SECURITY_CONTROL_FEC_ESR, val);
  }
}

static inline uint32 secboot_read_SAILSS_SECURITY_CONTROL_FEC_ESR_corr_seen(void)
{
#ifdef SECHWIO_TEST
  if (use_test_fuses)
  {
    return (VIR_HWIO_IN(HWIO_SAILSS_SECURITY_CONTROL_FEC_ESR_ADDR)) & HWIO_FMSK(SAILSS_SECURITY_CONTROL_FEC_ESR, CORR_SEEN);
  }
  else
#endif
  {
    return HWIO_INM(SAILSS_SECURITY_CONTROL_FEC_ESR, HWIO_FMSK(SAILSS_SECURITY_CONTROL_FEC_ESR, CORR_SEEN));
  }
}

static inline uint32 secboot_read_secure_bootn_fuse_src(uint32 code_segment)
{
#ifdef SECHWIO_TEST
  if (use_test_fuses)
  {
    if (code_segment < NUM_TEST_SECURE_BOOTn_SEGMENTS)
    {
      return VIR_HWIO_INFI(VIR_HWIO_IN(HWIO_SAILSS_SECURITY_CONTROL_SECURE_BOOTn_ADDR(code_segment)), HWIO_SAILSS_SECURITY_CONTROL_SECURE_BOOTn_FUSE_SRC_BMSK, HWIO_SECURE_BOOTn_FUSE_SRC_SHFT);
    }
    else
    {
      return 0;
    }
  }
  else
#endif
  {
    return HWIO_INFI(SAILSS_SECURITY_CONTROL_SECURE_BOOTn, code_segment, FUSE_SRC);
  }
}

static inline uint32 secboot_read_oem_id(void)
{
#ifdef SECHWIO_TEST
  if (use_test_fuses)
  {
    return VIR_HWIO_IN(HWIO_OEM_ID_ADDR);
  }
  else
#endif
  {
    return HWIO_IN(SAILSS_SECURITY_CONTROL_OEM_ID);
  }
}

static inline uint32 secboot_read_secure_bootn_pk_hash_in_fuse
(uint32 code_segment)
{
#ifdef SECHWIO_TEST
  if (use_test_fuses)
  {
    if (code_segment < NUM_TEST_SECURE_BOOTn_SEGMENTS)
    {
      return VIR_HWIO_INFI(VIR_HWIO_IN(HWIO_SECURE_BOOTn_ADDR(code_segment)), HWIO_SECURE_BOOTn_PK_HASH_IN_FUSE_BMSK, HWIO_SECURE_BOOTn_PK_HASH_IN_FUSE_SHFT);
    }
    else
    {
      return 0;
    }
  }
  else
#endif
  {
    return HWIO_INFI(SAILSS_SECURITY_CONTROL_SECURE_BOOTn, code_segment, PK_HASH_IN_FUSE);
  }
}

static inline uint32 secboot_read_secure_bootn_rom_pk_hash_index
(uint32 code_segment)
{
#ifdef SECHWIO_TEST
  if (use_test_fuses)
  {
    if (code_segment < NUM_TEST_SECURE_BOOTn_SEGMENTS)
    {
      return VIR_HWIO_INFI(VIR_HWIO_IN(HWIO_SECURE_BOOTn_ADDR(code_segment)), HWIO_SECURE_BOOTn_ROM_PK_HASH_INDEX_BMSK, HWIO_SECURE_BOOTn_ROM_PK_HASH_INDEX_SHFT);
    }
    else
    {
      return 0;
    }
  }
  else
#endif
  {
    return HWIO_INFI(SAILSS_SECURITY_CONTROL_SECURE_BOOTn, code_segment, ROM_PK_HASH_INDEX);
  }
}

static inline uint32 secboot_read_secure_bootn_auth_en(uint32 code_segment)
{
#ifdef SECHWIO_TEST
  if (use_test_fuses)
  {
    if (code_segment < NUM_TEST_SECURE_BOOTn_SEGMENTS)
    {
      return VIR_HWIO_INFI(VIR_HWIO_IN(HWIO_SECURE_BOOTn_ADDR(code_segment)), HWIO_SECURE_BOOTn_AUTH_EN_BMSK, HWIO_SECURE_BOOTn_AUTH_EN_SHFT);
    }
    else
    {
      return 0;
    }
  }
  else
#endif
  {
    return HWIO_INFI(SAILSS_SECURITY_CONTROL_SECURE_BOOTn, code_segment, AUTH_EN);
  }
}

static inline uint32 secboot_read_pk_hash0_rown_lsb(uintptr_t index)
{
#ifdef SECHWIO_TEST
  if (use_test_fuses)
  {
    if (index < NUM_TEST_PK_HASH_LSB_INDICES)
    {
      return (*((uintptr_t *) (VIR_HWIO_IN(HWIO_QFPROM_CORR_PK_HASH_0_ROW0_LSB_ADDR) + index*8)));
    }
    else
    {
      return 0;
    }
  }
  else
#endif
  {
    return (*((uintptr_t *)(HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_PK_HASH_0_ROW0_LSB_ADDR + index*8)));
  }
}

static inline uint32 secboot_read_pk_hash0_rown_msb(uintptr_t index)
{
#ifdef SECHWIO_TEST
  if (use_test_fuses)
  {
    if (index < NUM_TEST_PK_HASH_MSB_INDICES)
    {
      return (*((uintptr_t *) (VIR_HWIO_IN(HWIO_QFPROM_CORR_PK_HASH_0_ROW0_MSB_ADDR) + index*8)));
    }
    else
    {
      return 0;
    }
  }
  else
#endif
  {
    return (*((uintptr_t *)(HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_PK_HASH_0_ROW0_MSB_ADDR + index*8)));
  }
}

static inline uint32 secboot_read_jtag_id_masked(uint32 mask)
{
#ifdef SECHWIO_TEST
  if (use_test_fuses)
  {
     return (VIR_HWIO_IN(HWIO_JTAG_ID_ADDR)) & mask;
  }
  else
#endif
  {
    return HWIO_INM(SAILSS_SECURITY_CONTROL_JTAG_ID, mask);
  }
}

static inline uint32 secboot_read_secure_bootn_use_serial_num
(uint32 code_segment)
{
#ifdef SECHWIO_TEST
  if (use_test_fuses)
  {
    if (code_segment < NUM_TEST_SECURE_BOOTn_SEGMENTS)
    {
      return VIR_HWIO_INFI(VIR_HWIO_IN(HWIO_SAILSS_SECURITY_CONTROL_SECURE_BOOTn_ADDR(code_segment)), HWIO_SAILSS_SECURITY_CONTROL_SECURE_BOOTn_USE_SERIAL_NUM_BMSK, HWIO_SECURE_BOOTn_USE_SERIAL_NUM_SHFT);
    }
    else
    {
      return 0;
    }
  }
  else
#endif
  {
    return HWIO_INFI( SAILSS_SECURITY_CONTROL_SECURE_BOOTn, code_segment, USE_SERIAL_NUM );
  }
}

static inline uint32 secboot_read_serial_num(void)
{
#ifdef SECHWIO_TEST
  if (use_test_fuses)
  {
    return VIR_HWIO_INFI(VIR_HWIO_IN(HWIO_SERIAL_NUM_ADDR), HWIO_SERIAL_NUM_SERIAL_NUM_BMSK, HWIO_SERIAL_NUM_SERIAL_NUM_SHFT);
  }
  else
#endif
  {
    return HWIO_INF(SAILSS_SECURITY_CONTROL_SERIAL_NUM, SERIAL_NUM);
  }
}

static inline uint32 secboot_read_chip_id(void)
{
#ifdef SECHWIO_TEST
  if (use_test_fuses)
  {
    return VIR_HWIO_INFI(VIR_HWIO_IN(HWIO_CHIP_ID_ADDR), HWIO_CHIP_ID_CHIP_ID_BMSK, HWIO_CHIP_ID_CHIP_ID_SHFT);
  }
  else
#endif
  {
    return HWIO_INF(SAILSS_SECURITY_CONTROL_CHIP_ID, CHIP_ID);
  }
}

static inline uint32 secboot_read_image_enc_enable(void)
{
#ifdef SECHWIO_TEST
  if (use_test_fuses)
  {
    return VIR_HWIO_INFI(VIR_HWIO_IN(HWIO_OEM_CONFIG0_ADDR), HWIO_OEM_CONFIG0_IMAGE_ENCRYPTION_ENABLE_BMSK, HWIO_OEM_CONFIG0_IMAGE_ENCRYPTION_ENABLE_SHFT);
  }
  else
#endif
  {
    return HWIO_INF(SAILSS_SECURITY_CONTROL_OEM_CONFIG0, IMAGE_ENCRYPTION_ENABLE);
  }
}

static inline uint32 secboot_read_oem_image_encr_keyn(uint32 index)
{
#ifdef SECHWIO_TEST
  if (use_test_fuses)
  {
    if (index < NUM_OEM_IMAGE_ENCR_KEYn_INDICES)
    {
      return VIR_HWIO_IN(HWIO_OEM_IMAGE_ENCR_KEYn_ADDR(index));
    }
    else
    {
      return 0;
    }
  }
  else
#endif
  {
    return HWIO_INI (SAILSS_SECURITY_CONTROL_OEM_IMAGE_ENCR_KEYn, index);
  }
}

static inline uint32 secboot_read_image_encr_key1_0(void)
{
#ifdef SECHWIO_TEST
  if (use_test_fuses)
  {
    return VIR_HWIO_INFI(VIR_HWIO_IN(HWIO_IMAGE_ENCR_KEY1_0_ADDR), HWIO_IMAGE_ENCR_KEY1_0_KEY_DATA0_BMSK, HWIO_IMAGE_ENCR_KEY1_0_KEY_DATA0_SHFT);
  }
  else
#endif
  {
    return HWIO_INF(SAILSS_SECURITY_CONTROL_IMAGE_ENCR_KEY1_0, KEY_DATA0);
  }
}

static inline uint32 secboot_read_image_encr_key1_1(void)
{
#ifdef SECHWIO_TEST
  if (use_test_fuses)
  {
    return VIR_HWIO_INFI(VIR_HWIO_IN(HWIO_IMAGE_ENCR_KEY1_1_ADDR), HWIO_IMAGE_ENCR_KEY1_1_KEY_DATA0_BMSK, HWIO_IMAGE_ENCR_KEY1_1_KEY_DATA0_SHFT);
  }
  else
#endif
  {
    return HWIO_INF(SAILSS_SECURITY_CONTROL_IMAGE_ENCR_KEY1_1, KEY_DATA0);
  }
}

static inline uint32 secboot_read_image_encr_key1_2(void)
{
#ifdef SECHWIO_TEST
  if (use_test_fuses)
  {
    return VIR_HWIO_INFI(VIR_HWIO_IN(HWIO_IMAGE_ENCR_KEY1_2_ADDR), HWIO_IMAGE_ENCR_KEY1_2_KEY_DATA0_BMSK, HWIO_IMAGE_ENCR_KEY1_2_KEY_DATA0_SHFT);
  }
  else
#endif
  {
    return HWIO_INF(SAILSS_SECURITY_CONTROL_IMAGE_ENCR_KEY1_2, KEY_DATA0);
  }
}

static inline uint32 secboot_read_image_encr_key1_3(void)
{
#ifdef SECHWIO_TEST
  if (use_test_fuses)
  {
    return VIR_HWIO_INFI(VIR_HWIO_IN(HWIO_IMAGE_ENCR_KEY1_3_ADDR), HWIO_IMAGE_ENCR_KEY1_3_KEY_DATA0_BMSK, HWIO_IMAGE_ENCR_KEY1_3_KEY_DATA0_SHFT);
  }
  else
#endif
  {
    return HWIO_INF(SAILSS_SECURITY_CONTROL_IMAGE_ENCR_KEY1_3, KEY_DATA0);
  }
}

static inline uint32 secboot_read_mrc_current_uie_key_sel(void)
{
#ifdef SECHWIO_TEST
  if (use_test_fuses)
  {
    return VIR_HWIO_INFI(VIR_HWIO_IN(HWIO_MRC_2_0_1_ADDR), HWIO_MRC_2_0_1_CURRENT_UIE_KEY_SEL_BMSK, HWIO_MRC_2_0_1_CURRENT_UIE_KEY_SEL_SHFT);
  }
  else
#endif
  {
    return HWIO_INF(SAILSS_SECURITY_CONTROL_MRC_2_0_1, CURRENT_UIE_KEY_SEL);
  }
}

static inline uint32 secboot_read_blow_status(void)
{
#ifdef SECHWIO_TEST
  if (use_test_fuses)
  {
    return 0;
  }
  else
#endif
  {
    return HWIO_IN(SAILSS_SECURITY_CONTROL_QFPROM_BLOW_STATUS );
  }
}

#define SECFUSES_PK_HASH_BYTE_SIZE 48U

static inline uint32 SECFUSES_DRV(secboot_read_pk_hash_data)
(
  uint8* root_of_trust,
  uint32 rot_size
)
{
  uint32 *arry_ptr = (uint32*)root_of_trust;

  if (arry_ptr == NULL)
  {
    return SECCTRL_DATA_PTR_NULL_ERR;
  }
  if (rot_size != SECFUSES_PK_HASH_BYTE_SIZE)
  {
    return SECCTRL_INVALID_DATA_ERR;
  }

#ifdef SECHWIO_TEST
  if (use_test_fuses)
  {
    arry_ptr[0] = secboot_read_pk_hash0_rown_lsb(0);
    arry_ptr[1] = secboot_read_pk_hash0_rown_msb(0);
    arry_ptr[2] = secboot_read_pk_hash0_rown_lsb(1);
    arry_ptr[3] = secboot_read_pk_hash0_rown_msb(1);
    arry_ptr[4] = secboot_read_pk_hash0_rown_lsb(2);
    arry_ptr[5] = secboot_read_pk_hash0_rown_msb(2);
    arry_ptr[6] = secboot_read_pk_hash0_rown_lsb(3);
    arry_ptr[7] = secboot_read_pk_hash0_rown_msb(3);
    arry_ptr[8] = secboot_read_pk_hash0_rown_lsb(4);
    arry_ptr[9] = secboot_read_pk_hash0_rown_msb(4);
    arry_ptr[10] = secboot_read_pk_hash0_rown_lsb(5);
    arry_ptr[11] = secboot_read_pk_hash0_rown_msb(5);
  }
  else
#endif
  {
    arry_ptr[0] = HWIO_INF(SAILSS_SECURITY_CONTROL_PK_HASH0_0, HASH_DATA0);
    arry_ptr[1] = HWIO_INF(SAILSS_SECURITY_CONTROL_PK_HASH0_1, HASH_DATA0);
    arry_ptr[2] = HWIO_INF(SAILSS_SECURITY_CONTROL_PK_HASH0_2, HASH_DATA0);
    arry_ptr[3] = HWIO_INF(SAILSS_SECURITY_CONTROL_PK_HASH0_3, HASH_DATA0);
    arry_ptr[4] = HWIO_INF(SAILSS_SECURITY_CONTROL_PK_HASH0_4, HASH_DATA0);
    arry_ptr[5] = HWIO_INF(SAILSS_SECURITY_CONTROL_PK_HASH0_5, HASH_DATA0);
    arry_ptr[6] = HWIO_INF(SAILSS_SECURITY_CONTROL_PK_HASH0_6, HASH_DATA0);
    arry_ptr[7] = HWIO_INF(SAILSS_SECURITY_CONTROL_PK_HASH0_7, HASH_DATA0);
    arry_ptr[8] = HWIO_INF(SAILSS_SECURITY_CONTROL_PK_HASH0_8, HASH_DATA0);
    arry_ptr[9] = HWIO_INF(SAILSS_SECURITY_CONTROL_PK_HASH0_9, HASH_DATA0);
    arry_ptr[10] = HWIO_INF(SAILSS_SECURITY_CONTROL_PK_HASH0_10, HASH_DATA0);
    arry_ptr[11] = HWIO_INF(SAILSS_SECURITY_CONTROL_PK_HASH0_11, HASH_DATA0);
  }
  return SECCTRL_NO_ERR;
}

static inline uint32 SECFUSES_DRV(secboot_read_oem_config_eku_enforcement)(void)
{
#ifdef SECHWIO_TEST
  if (use_test_fuses)
  {
    return VIR_HWIO_INFI(VIR_HWIO_IN(HWIO_OEM_CONFIG2_ADDR), HWIO_OEM_CONFIG2_EKU_ENFORCEMENT_EN_BMSK, HWIO_OEM_CONFIG2_EKU_ENFORCEMENT_EN_SHFT);
  }
  else
#endif
  {
    return HWIO_INF( SAILSS_SECURITY_CONTROL_OEM_CONFIG2, EKU_ENFORCEMENT_EN );
  }
}

static inline uint32 SECFUSES_DRV(secboot_read_oem_config_disable_rsa)(void)
{
#ifdef SECHWIO_TEST
  if (use_test_fuses)
  {
    return VIR_HWIO_INFI(VIR_HWIO_IN(HWIO_OEM_CONFIG2_ADDR), HWIO_OEM_CONFIG2_DISABLE_RSA_BMSK, HWIO_OEM_CONFIG2_DISABLE_RSA_SHFT);
  }
  else
#endif
  {
    return HWIO_INF( SAILSS_SECURITY_CONTROL_OEM_CONFIG2, DISABLE_RSA );
  }
}

static inline uint32 SECFUSES_DRV(secboot_read_use_legacy_sig)(void)
{
#ifdef SECHWIO_TEST
  if (use_test_fuses)
  {
    return VIR_HWIO_INFI(VIR_HWIO_IN(HWIO_FEATURE_CONFIG_NM1_ADDR), HWIO_FEATURE_CONFIG_NM1_LEGACY_MBNV6_OEM_AUTH_CTRL_SECBOOT_BMSK, HWIO_FEATURE_CONFIG_NM1_LEGACY_MBNV6_OEM_AUTH_CTRL_SECBOOT_SHFT);
  }
  else
#endif
  {
    return HWIO_INF(SAILSS_SECURITY_CONTROL_FEATURE_CONFIG_NM1, LEGACY_MBNV6_OEM_AUTH_CTRL_SECBOOT);
  }
}


static inline uint32 SECFUSES_DRV(secboot_read_qti_root_sig_format_sel)(void)
{
#ifdef SECHWIO_TEST
  if (use_test_fuses)
  {
    return VIR_HWIO_INFI(VIR_HWIO_IN(HWIO_FEATURE_CONFIG_NM1_ADDR), HWIO_FEATURE_CONFIG_NM1_QTI_ROOT_SIG_FORMAT_SEL_BMSK, HWIO_FEATURE_CONFIG_NM1_QTI_ROOT_SIG_FORMAT_SEL_SHFT);
  }
  else
#endif
  {
    return HWIO_INF(SAILSS_SECURITY_CONTROL_FEATURE_CONFIG_NM1, QTI_ROOT_SIG_FORMAT_SEL);
  }
}

/* TODO: This function is moved from debug_status file to here, if needed, need to implement in this file.
   This function maps the address of security control block to virtual security control block */
/*uint32 virtual_address(uint32 address)
{
    address = address - SECURITY_CONTROL_CORE_REG_BASE + VIRTUAL_SECURITY_CONTROL_CORE_ADDR;
    return address;
}*/

/**
 * @brief Check if secure boot authentication is enabled
 * @return TRUE if enabled else FALSE
 */
static inline bool secboot_is_auth_enabled(void)
{
  return (bool)HWIO_INFI(SAILSS_SECURITY_CONTROL_SECURE_BOOTn, 0x1, AUTH_EN);
}

#endif // SECHWIO_H
