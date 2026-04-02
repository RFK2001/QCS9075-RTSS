/*
===========================================================================
*/
/**
    @file  spinor_sfdp_utils.c
    @brief Serial Flash Discoverable Parameters utility functions

*/
/*
    ===========================================================================

    Copyright (c) 2020-2025 Qualcomm Technologies, Inc.
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

    ===========================================================================

    $Header: $
    $DateTime: $
    $Author: $

    ===========================================================================
*/

#include <string.h>
#include "spinor_core.h"
#include "spinor_utils.h"
#include "spinor_init_config.h"
#include "spinor_sfdp.h"
#include "spinor_sfdp_util.h"
#include "spinor_diag.h"
#include "libfdt.h"
#include "fdt_utils.h"


extern spinor_logs *p_sfdp_debug_log;  /* Defined in spinor_sfdp.c */

/* Return the Max Frequency of operation of the param passed */
uint32_t spinor_sfdp_util_get_maxfreq(uint32_t mhz)
{
  uint32_t freq_khz = 0U;

  if (mhz == 0b0000 || mhz == 0b1111 || mhz == 0b1110)
  {
    /* Reserved or not supported */
    freq_khz = 0;
  }
  else if (mhz == 0b0001)
  {
    freq_khz = 33 * 1000;
  }
  else if (mhz == 0b0010)
  {
    freq_khz = 50 * 1000;
  }
  else if (mhz == 0b0011)
  {
    freq_khz = 66 * 1000;
  }
  else if (mhz == 0b0100)
  {
    freq_khz = 80 * 1000;
  }
  else if (mhz == 0b0101)
  {
    freq_khz = 100 * 1000;
  }
  else if (mhz == 0b0110)
  {
    freq_khz = 133 * 1000;
  }
  else if (mhz == 0b0111)
  {
    freq_khz = 166 *1000;
  }
  else if (mhz == 0b1000)
  {
    freq_khz = 200 * 1000;
  }
  else if (mhz == 0b1001)
  {
    freq_khz = 250 * 1000;
  }
  else if (mhz == 0b1010)
  {
    freq_khz = 266 *1000;
  }
  else if (mhz == 0b1011)
  {
    freq_khz = 333 * 1000;
  }
  else if (mhz == 0b1100)
  {
    /* 400MHz */
    freq_khz = 400 * 1000;
  }
  else
  {
    /* return 0 as a failure */
    freq_khz = 0;
  }
  return freq_khz;

}

SPINOR_STATUS spinor_sfdp_util_get_erase_and_write_reg_mask(spinor_config_data *config, uint32_t device_id, spinor_sfdp_t *sfdp_data_read)
{
  SPINOR_STATUS ret_status = SPINOR_DEVICE_DONE;
  uint8_t manufacturer = spinor_sfdp_util_get_manufacturer(device_id);

  /*
   * The error bitmask for erase and program could be retrieved from the
   * device by getting the SCCR table in SFDP. SCCR is defined in JESD216C
   * or later.
   */

  switch (manufacturer)
  {
  case MANUFACTURER_ID_MACRONIX:
    config->erase_err_bmsk       = 0x40;
    config->erase_err_status_reg = 0x2B;
    config->write_err_bmsk       = 0x20;
    config->write_err_status_reg = 0x2B;
    break;
  case MANUFACTURER_ID_MICRON:
  case MANUFACTURER_ID_MICRON_OSPI:
  case MANUFACTURER_ID_ISSI:
  case MANUFACTURER_ID_GD:
    config->erase_err_bmsk       = 0x20;
    config->erase_err_status_reg = 0x70;
    config->write_err_bmsk       = 0x10;
    config->write_err_status_reg = 0x70;
    break;
  case MANUFACTURER_ID_SPANSION:
    config->erase_err_bmsk       = 0x60;
    config->erase_err_status_reg = 0x05;
    config->write_err_bmsk       = 0x60;
    config->write_err_status_reg = 0x05;
    break;
  case MANUFACTURER_ID_WINBOND:
    config->erase_err_bmsk       = 0x20;
    config->erase_err_status_reg = 0x70;
    config->write_err_bmsk       = 0x10;
    config->write_err_status_reg = 0x70;
    break;
  case MANUFACTURER_ID_INFINEON:
    config->erase_err_bmsk       = 0x20;
    config->erase_err_status_reg = 0x05;
    config->write_err_bmsk       = 0x40;
    config->write_err_status_reg = 0x05;
    break;
  default:
    spinor_log (&p_spinor_dev->debug_log, 0x900);
    SPINOR_LOG_ERROR("%s: Error, device_id = 0x%x, manufacturer 0x%x not found\r\n", __func__, device_id, manufacturer);
    ret_status = SPINOR_DEVICE_FAIL;
    goto end;
    break;
  }
end:
  return ret_status;
}

uint32_t spinor_sfdp_util_get_str_bus_freq
(
  spinor_sfdp_t *sfdp_data_read,
  uint32_t freq_khz_at_least,
  boolean dqs,
  boolean is_ospi
)
{
  uint32_t freq_khz = 0U;
  spinor_sfdp_basic_param *basic_params = &sfdp_data_read->bparam_data;

  if (is_ospi == TRUE)
  {
    freq_khz = spinor_sfdp_util_get_maxfreq((dqs == TRUE) ? basic_params->mhz_888s_dt : basic_params->mhz_888s_ndt);
  }
  else
  {
    freq_khz = spinor_sfdp_util_get_maxfreq(basic_params->mhz_444s_ndt);
  }
  if (freq_khz > 0U && freq_khz >= freq_khz_at_least)
  {
    freq_khz = freq_khz_at_least;
  }
  else
  {
    freq_khz = 0;
  }

  return freq_khz;
}
uint32_t spinor_sfdp_util_get_dtr_bus_freq
(
  spinor_sfdp_t *sfdp_data_read,
  uint32_t freq_khz_at_least,
  boolean dqs,
  boolean is_ospi
)
{
  uint32_t freq_khz = 0U;
  spinor_sfdp_basic_param *basic_params = &sfdp_data_read->bparam_data;

  if (is_ospi == TRUE)
  {
    freq_khz = spinor_sfdp_util_get_maxfreq((dqs == TRUE) ? basic_params->mhz_888d_dt : basic_params->mhz_888d_ndt);
  }
  // else
  // {
    // freq_khz = spinor_sfdp_util_get_maxfreq((dqs == TRUE) ? basic_params->mhz_444d_dt : basic_params->mhz_444d_ndt);
  // }

  if (freq_khz > 0U && freq_khz >= freq_khz_at_least)
  {
    freq_khz = freq_khz_at_least;
  }
  else
  {
    freq_khz = 0;
  }
  return freq_khz;
}



boolean spinor_sfdp_util_get_4KB_uniform_sector(spinor_sfdp_t *sfdp_data_read)
{
  boolean tmp = FALSE;

  if (sfdp_data_read && sfdp_data_read->bparam_data.blk_erase_size == 0b01)
  {
    tmp = TRUE;
  }
  return tmp;
}

spinor_sfdp_bus_t spinor_sfdp_util_get_bus_mode(spinor_sfdp_t *sfdp_data_read)
{
  spinor_sfdp_4byte_inst *inst4b = &sfdp_data_read->inst4b_data;
  spinor_sfdp_bus_t bus          = SFDP_BUS_MAX;

  /* 1-1-1 read command 13h needs to be supported. PBL mode runs at 19.2MHz. */
  if ( inst4b->read_111_support == 0U)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x901);
    SPINOR_LOG_ERROR("%s: Error, read_111_support = 0 \r\n", __func__);
    goto end;
  }
  if ( inst4b->read_114_support )
  {
    bus = SFDP_BUS_QSPI;
  }
  else if (inst4b->read_118_support)
  {
    bus = SFDP_BUS_OSPI;
  }
  else
  {
      bus = SFDP_BUS_MAX;
      SPINOR_LOG_ERROR("%s: Error, read_114 or read_118 is not set in inst4b table. Unknown spinor bus mode\r\n", __func__);
  }
end:
  return bus;
}

#ifdef SPINOR_SFDP_UNUSED_FUNCTIONS
boolean spinor_sfdp_util_get_dqs_flag_ospi(spinor_sfdp_t *sfdp_data_read)
{
  boolean dqs = FALSE;
  uint32_t mhz_dtr;
  uint32_t mhz_str;
  spinor_sfdp_basic_param *basic_params = &sfdp_data_read->bparam_data;

  mhz_dtr = basic_params->mhz_888d_dt & 0xF;
  mhz_str = basic_params->mhz_888s_dt & 0xF;

  if (mhz_dtr != 0b1111 && mhz_dtr != 0b1110 && mhz_dtr != 0)
  {
    dqs = TRUE;
  }
  // this check not needed// our controller does not require DQS for SDR mode
  else if (mhz_str != 0b1111 && mhz_str != 0b1110 && mhz_str != 0)
  {
    dqs = TRUE;
  }
  else
  {
    dqs = FALSE;
  }
  return dqs;
}
#endif

SPINOR_STATUS spinor_sfdp_util_get_enter_4byte_mode(spinor_sfdp_t *sfdp_data_read, uint32_t device_id, spinor_sfdp_bus_t bus, uint8 *enter_4byte_mode)
{
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;
  spinor_sfdp_basic_param *bparam = NULL;

  if (sfdp_data_read == NULL || enter_4byte_mode == NULL)
  {
    status = SPINOR_DEVICE_FAIL;
    spinor_log (&p_spinor_dev->debug_log, 0x902);
    SPINOR_LOG_ERROR("%s: Error, sfdp_data_read or enter_4byte_mode is NULL \r\n", __func__);
    goto end;
  }
  bparam = &sfdp_data_read->bparam_data;
  *enter_4byte_mode = ADDR_4BYTE_NOT_SUPPORTED;

  if ((bparam->address_bytes_sup == 0b01 || bparam->address_bytes_sup == 0b10) &&
      sfdp_data_read->inst_4byte_size > 0)
  {
    /* Sort this statements to give priority to a different switch mode */
    if (bparam->enter_4b_addr & 0b01000000) /* Always in 4 byte mode */
    {
      *enter_4byte_mode = ADDR_4BYTE_MODE_7;
    }
    else if (bparam->enter_4b_addr & 0b00000001) /* Issue B7 instruction */
    {
      *enter_4byte_mode = ADDR_4BYTE_MODE_1;
    }
    else if (bparam->enter_4b_addr & 0b00100000) /* Dedicated 4Byte ADDR Instructions. */
    {
      *enter_4byte_mode = ADDR_4BYTE_MODE_6;
    }
    else if (bparam->enter_4b_addr & 0b00000010) /* instruction 06 then B7 */
    {
      *enter_4byte_mode = ADDR_4BYTE_MODE_2;
    }
    else if (bparam->enter_4b_addr & 0b00000100) /* */
    {
      *enter_4byte_mode = ADDR_4BYTE_MODE_3;
    }
    else if (bparam->enter_4b_addr & 0b00001000)
    {
      *enter_4byte_mode = ADDR_4BYTE_MODE_4;
    }
    else if (bparam->enter_4b_addr & 0b00010000)
    {
      *enter_4byte_mode = ADDR_4BYTE_MODE_5;
    }
    else
    {
      /* 4byte instruction table shows that no 4byte mode supported */
      status = SPINOR_DEVICE_FAIL;
      spinor_log (&p_spinor_dev->debug_log, 0x903);
      SPINOR_LOG_ERROR("%s: Error, 4byte instruction table shows that no 4byte mode supported \r\n", __func__);
      goto end;
    }
  }
  else
  {
    /* No 4byte instruction table */
    status = SPINOR_DEVICE_FAIL;
    spinor_log (&p_spinor_dev->debug_log, 0x904);
    SPINOR_LOG_ERROR("%s: Error, No 4byte instruction table \r\n", __func__);
    goto end;
  }
end:
  return status;
}
SPINOR_STATUS spinor_sfdp_util_get_octal_dtr_ext(spinor_sfdp_t *sfdp_data_read, uint32_t device_id, spinor_sfdp_bus_t bus, uint8 *octal_dtr_ext)
{
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;

  if (sfdp_data_read == NULL || octal_dtr_ext == NULL)
  {
    status = SPINOR_DEVICE_FAIL;
    spinor_log (&p_spinor_dev->debug_log, 0x905);
    SPINOR_LOG_ERROR("%s: Error, sfdp_data_read or octal_dtr_ext is NULL \r\n", __func__);
    goto end;
  }
  *octal_dtr_ext = sfdp_data_read->bparam_data.octal_dtr_ext;
end:
  return status;
}

SPINOR_STATUS spinor_sfdp_util_get_perf_reg_read_and_reg_read_addr_dummy_cycles(
  spinor_sfdp_t *sfdp_data_read,
  uint32_t device_id,
  spinor_sfdp_bus_t bus,
  spinor_config_data *config,
  uint32 read_mode)
{
  uint8_t manufacturer = spinor_sfdp_util_get_manufacturer(device_id);
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;

  switch (manufacturer)
  {
  case MANUFACTURER_ID_MACRONIX:              // 0xC2
    if(read_mode == SDR_8_8_8_MODE || read_mode == DDR_8_8_8_MODE)
    {
    config->access_param[1].reg_read_dummy_cycles = 4U;
    config->access_param[1].reg_read_addr_dummy_cycles = 4U;
    }
    else
    {
        config->access_param[1].reg_read_dummy_cycles = 0U;
        config->access_param[1].reg_read_addr_dummy_cycles = 0U;
    }
    break;

  case MANUFACTURER_ID_MICRON:                // 0x20
    if(read_mode == DDR_4_4_4_MODE)
    {
        config->access_param[1].reg_read_dummy_cycles = 1U;
        config->access_param[1].reg_read_addr_dummy_cycles = 1U;
    }
    else
    {
    config->access_param[1].reg_read_dummy_cycles = 0U;
    config->access_param[1].reg_read_addr_dummy_cycles = 0U;
    }
    break;

  case MANUFACTURER_ID_SPANSION:              // 0x01
     status = SPINOR_DEVICE_FAIL;
     break;

  case MANUFACTURER_ID_WINBOND:               // 0xEF
    config->access_param[1].reg_read_dummy_cycles = 8U;
    config->access_param[1].reg_read_addr_dummy_cycles = 8U;
    break;

  case MANUFACTURER_ID_MICRON_OSPI:           // 0x2C
    if(read_mode == SDR_1_1_1_MODE)
    {
        config->access_param[1].reg_read_dummy_cycles = 0U;
        config->access_param[1].reg_read_addr_dummy_cycles = 8U;
    }
    else
    {
    config->access_param[1].reg_read_dummy_cycles = 8U;
    config->access_param[1].reg_read_addr_dummy_cycles = 8U;
    }
    break;

  case MANUFACTURER_ID_ISSI:                  // 0x9D
    if(read_mode == DDR_8_8_8_MODE)
    {
    config->access_param[1].reg_read_dummy_cycles = 8U;
    config->access_param[1].reg_read_addr_dummy_cycles = 8U;
    }
    else
    {
        config->access_param[1].reg_read_dummy_cycles = 0U;
        config->access_param[1].reg_read_addr_dummy_cycles = 8U;
    }
    break;
  case MANUFACTURER_ID_GD:                    // 0xC8
    config->access_param[1].reg_read_dummy_cycles = (bus == SFDP_BUS_QSPI) ? 0U : 8U;
    config->access_param[1].reg_read_addr_dummy_cycles = 8U;
    break;

  case MANUFACTURER_ID_INFINEON:              // 0x34
    if(read_mode == SDR_8_8_8_MODE || read_mode == DDR_8_8_8_MODE)
    {
        config->access_param[1].reg_read_dummy_cycles = 5U;
        config->access_param[1].reg_read_addr_dummy_cycles = 5U;
    }
    else
    {
        /* 0 dummy cycles corresponds to low frequencies below 50MHz. To use higher frequencies this should change */
        config->access_param[1].reg_read_dummy_cycles = 0U;
        config->access_param[1].reg_read_addr_dummy_cycles = 0U;
    }
    break;

  default:
    spinor_log (&p_spinor_dev->debug_log, 0x906);
    SPINOR_LOG_ERROR("%s: Error, Invalid manufacturer ID \r\n", __func__);
    status = SPINOR_DEVICE_FAIL;
    break;
  }
  return status;
}

SPINOR_STATUS spinor_sfdp_util_get_default_reg_read_and_reg_read_addr_dummy_cycles(
  spinor_sfdp_t *sfdp_data_read,
  uint32_t device_id,
  spinor_config_data *config)
{
  uint8_t manufacturer = spinor_sfdp_util_get_manufacturer(device_id);
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;
  /* We are making the addr_bytes_reg_addr compatible with the 3 byte addressing mode in case of sailjtagprogrammer as it has not entered 4-byte mode yet.
     In case of mission mode, PBL enters the 4-byte mode prior to the spinor_init and hence we make the value compatible with the 4-byte mode then */

  switch (manufacturer)
  {
  case MANUFACTURER_ID_MACRONIX:              // 0xC2
    config->access_param[0].reg_read_dummy_cycles = 0U;
    config->access_param[0].reg_read_addr_dummy_cycles = 0U;
#ifdef SAILJTAGPROGRAMMER
    config->access_param[0].addr_bytes_reg_addr = 4;
#endif
    break;
  case MANUFACTURER_ID_MICRON:                // 0x20
    config->access_param[0].reg_read_dummy_cycles = 0U;
    config->access_param[0].reg_read_addr_dummy_cycles = 0U;
#ifdef SAILJTAGPROGRAMMER
    config->access_param[0].addr_bytes_reg_addr = 0;
#endif
    break;
  case MANUFACTURER_ID_SPANSION:              // 0x01
     status = SPINOR_DEVICE_FAIL;
     break;
  case MANUFACTURER_ID_WINBOND:               // 0xEF
    config->access_param[0].reg_read_dummy_cycles = 0U;
    config->access_param[0].reg_read_addr_dummy_cycles = 8U;
#ifdef SAILJTAGPROGRAMMER
    config->access_param[0].addr_bytes_reg_addr = 3;
#endif
    break;
  case MANUFACTURER_ID_MICRON_OSPI:           // 0x2C
    config->access_param[0].reg_read_dummy_cycles = 0U;
    config->access_param[0].reg_read_addr_dummy_cycles = 8U;
#ifdef SAILJTAGPROGRAMMER
    config->access_param[0].addr_bytes_reg_addr = 3;
#endif
    break;
  case MANUFACTURER_ID_ISSI:                  // 0x9D
    config->access_param[0].reg_read_dummy_cycles = 8U;
    config->access_param[0].reg_read_addr_dummy_cycles = 8U;
#ifdef SAILJTAGPROGRAMMER
    config->access_param[0].addr_bytes_reg_addr = 3;
#endif
    break;
  case MANUFACTURER_ID_GD:                    // 0xC8
    config->access_param[0].reg_read_dummy_cycles = 0U;
    config->access_param[0].reg_read_addr_dummy_cycles = 8U;
#ifdef SAILJTAGPROGRAMMER
    config->access_param[0].addr_bytes_reg_addr = 3;
#endif
    break;
  case MANUFACTURER_ID_INFINEON:              // 0x34
    config->access_param[0].reg_read_dummy_cycles = 0U;
    config->access_param[0].reg_read_addr_dummy_cycles = 0U;
#ifdef SAILJTAGPROGRAMMER
    config->access_param[0].addr_bytes_reg_addr = 3;
#endif
    break;
  default:
    spinor_log (&p_spinor_dev->debug_log, 0x907);
    SPINOR_LOG_ERROR("%s: Error, Invalid manufacturer ID \r\n", __func__);
    status = SPINOR_DEVICE_FAIL;
    break;
  }

#ifndef SAILJTAGPROGRAMMER
  /* If SW reset is done, then the device is in default addressing mode. set bytes accoridng to manufacturer default  */
  if (TRUE == p_spinor_dev->sw_reset_done)
  {
      if (manufacturer == MANUFACTURER_ID_MICRON)
      {
          config->access_param[0].addr_bytes_reg_addr = 0;
      }
      else if (manufacturer == MANUFACTURER_ID_MACRONIX)
      {
          config->access_param[0].addr_bytes_reg_addr = 4;
      }
      else
      {
          config->access_param[0].addr_bytes_reg_addr = 3;
      }
  }
  else
  {
      /* Entered from PBL, then PBL would have entered 4byte mode. Set to 4 byte default  */
      config->access_param[0].addr_bytes_reg_addr = (manufacturer == MANUFACTURER_ID_MICRON)? 0:4;
  }
#endif
  config->access_param[0].addr_bytes_sfdp = 3;
  config->access_param[0].sfdp_read_dummy_cycles = 8;

  return status;
}


SPINOR_STATUS spinor_sfdp_util_get_access_param_perf(spinor_sfdp_t *sfdp_data_read, uint32_t device_id, spinor_sfdp_bus_t bus,
                                                           uint32_t bus_clk_khz, uint32 read_mode, uint32 write_mode, boolean dqs, spinor_config_data *config)
{
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;
  spinor_sfdp_basic_param *bparams = NULL;
  spinor_sfdp_4byte_inst  *inst4b  = NULL;
  spinor_sfdp_xspi_profile_1_0 *profile10 = NULL;

  if (bus >= SFDP_BUS_MAX)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x908);
    SPINOR_LOG_ERROR("%s: Error, Bus > SFDP bus max \r\n", __func__);
    goto end;
  }

  if (sfdp_data_read == NULL || config == NULL ||
      sfdp_data_read->basic_param_size == 0U   ||
      sfdp_data_read->inst_4byte_size == 0U    ||
      (bus == SFDP_BUS_OSPI && sfdp_data_read->profile10_size == 0U ) )
  {
    spinor_log (&p_spinor_dev->debug_log, 0x909);
    SPINOR_LOG_ERROR("%s: Error, parameters passed are invalid \r\n", __func__);
    goto end;
  }

  bparams   = &sfdp_data_read->bparam_data;
  inst4b    = &sfdp_data_read->inst4b_data;
  profile10 = &sfdp_data_read->profile10_data;

  uint8_t manufacturer = spinor_sfdp_util_get_manufacturer(device_id);

  memset(&config->access_param[1], 0, sizeof(spinor_access_param_type));

  config->access_param[1].read_mode      = read_mode;       /* Read Mode: Command-Address-Data */

  config->access_param[1].write_mode     = write_mode;      /* Write Mode: Command-Address-Data */

  config->access_param[1].addr_bytes     = 4;               /* Must be 4 Bytes addressing mode for memory access read/write/erase*/

  /* Must be 4 bytes addressing. Number of addr bytes for Register read/write command */
  /* Must be 0 for micron ospi, micron qspi, winbond, issi, gd ospi and gd qspi */
  /* Must be 4 for Macronix in SDR 8-8-8 and DDR 8-8-8 */

  //config->access_param[1].addr_bytes_reg = (manufacturer == MANUFACTURER_ID_MACRONIX)? 4:0;

  if(manufacturer == MANUFACTURER_ID_MACRONIX && (read_mode == SDR_8_8_8_MODE || read_mode == DDR_8_8_8_MODE))
  {
      config->access_param[1].addr_bytes_reg = 4;
  }
  else if(manufacturer == MANUFACTURER_ID_INFINEON && (read_mode == SDR_8_8_8_MODE || read_mode == DDR_8_8_8_MODE))
  {
      config->access_param[1].addr_bytes_reg = 4;
  }
  else
  {
      config->access_param[1].addr_bytes_reg = 0;
  }

  /* Number of addr bytes fo Register read/write with address command */
  if (bus == SFDP_BUS_OSPI)
  {
    config->access_param[1].addr_bytes_reg_addr = 4; //(profile10->num_additional_modifier_bytes_used_for_read_status_reg_cmd == 1U) ? 4 : 0;
                                                     // should be 0 only for micron qspi
  }
  else
  {
    config->access_param[1].addr_bytes_reg_addr = 0U;               //mzhu discuss with dilip
  }

  /* Fill reg read and reg_read_addr dummy cycles
   * 1. config->access_param[1].reg_read_dummy_cycles
   *    Dummy cycles needed for read status/control register for volatile registers
   * 2. config->access_param[1].reg_read_addr_dummy_cycles:
   *    Dummy cycles needed for read status/control register for volatile registers with addr specified
   */
  if (SPINOR_DEVICE_DONE != spinor_sfdp_util_get_perf_reg_read_and_reg_read_addr_dummy_cycles(sfdp_data_read, device_id, bus, config, read_mode))
  {
    spinor_log (&p_spinor_dev->debug_log, 0x90A);
    SPINOR_LOG_ERROR("%s: Error, get perf reg read dummy cycles fail \r\n", __func__);
    goto end;
  }

  if (bus == SFDP_BUS_OSPI)
  {
    /* profile 1.0 1st DWORD. SFDP Command in 8D-8D-8D mode � Address Bytes */
    config->access_param[1].addr_bytes_sfdp = (profile10->sfdp_cmd_in_8d_8d_8d_mode_addr_bytes == 1U) ? 3U : 4U;

    /* profile 1.0 1st DWORD. SFDP Command in 8D-8D-8D mode � Dummy Cycles */
    config->access_param[1].sfdp_read_dummy_cycles = (profile10->sfdp_cmd_in_8d_8d_8d_mode_dummy_cycles == 1U) ? 20U : 8U;
  }
  else
  {
    /* JESD216D-01, basic parameter dword 1 Address Bytes note:
     * All SFDP accesses use 3-byte addressing.
     * A device using 4-byte only addressing may still
     * support 03h read using 3-byte addressing.
     */
    config->access_param[1].addr_bytes_sfdp = 3U;

    /* JESD216D-01 does not have this information for QSPI.
     * Hard coded to 8 for now. Old experience showed that 8 works well.
     */
    config->access_param[1].sfdp_read_dummy_cycles = 8U;
  }

  /* Opcode for the multiple IO read ID operation
   * If there is multiple I/O read ID opcode in the data sheet use that opcode.
   * But, this info is not presented in SFDP. So, here, the default READ_ID_CMD 0x9F
   * is hardcoded. Setting read_id_opcode to 0 here.
   * The driver will use 0x9F  when this field is zero.
   */
  config->access_param[1].read_id_opcode = 0;

  /* Opcode for the read Operation and mode as per data sheet */
  if (bus == SFDP_BUS_OSPI)
  {
      status = spinor_sfdp_util_get_access_param_perf_read_opcode_ospi(sfdp_data_read, bus_clk_khz, read_mode, config, manufacturer);
  }
  else
  {
      status = spinor_sfdp_util_get_access_param_perf_read_opcode_qspi(sfdp_data_read, bus_clk_khz, read_mode, config, manufacturer);
  }

  if(status != SPINOR_DEVICE_DONE)
  {
      spinor_log (&p_spinor_dev->debug_log, 0x90B);
      SPINOR_LOG_ERROR("%s: Error, read opcode setting failed \r\n", __func__);
      goto end;
  }

  /* Total of dummy cycles to wait states for the operation and mode as per data sheet.
   * This field is derived from dummy cycle info structure. No need to fill in
   */
  config->access_param[1].wait_state = 0;

  /* Opcode for the write Operation and mode as per data sheet */
  if (bus == SFDP_BUS_OSPI)
  {
    status = spinor_sfdp_util_get_access_param_perf_write_opcode_ospi(sfdp_data_read, config);
  }
  else
  {
    status = spinor_sfdp_util_get_access_param_perf_write_opcode_qspi(sfdp_data_read, write_mode, config);
  }

  if(status != SPINOR_DEVICE_DONE)
  {
      spinor_log (&p_spinor_dev->debug_log, 0x90C);
      SPINOR_LOG_ERROR("%s: Error, write opcode setting failed \r\n", __func__);
      goto end;
  }

  /* Erase instruction in SFDP basic parameter table:
   * Uniform 4KB sector device must code in 1st DWORD:
   * 1:0 bits:  block/sector erase size to 0b01
   * 15:8 bits: 4KB sector erase instruction
   * Also, the same instruction erase_instr_4k
   * must be in one of those 4 erase types in 8th or 9th DWORD.
   * Additional iformation about 4 erase types (not used in finding erase op code now):
   * There are 4 erase types. Usually, they are defined to be:
   * Erase type 1: it is usually for 4KB sector
   * Erase tupe 2: it is usually for 32KB sector
   * Erase type 3: it is usually for 64KB sector
   * Erase type 4: it is usually for 256KB sector
   * The 4KB size in 8th and 9th DWORD is coded to 0x0C in the basic parameter table
   */
  if (inst4b->erase_1_support == 1U && inst4b->erase_1_inst != 0U)
  {
    config->access_param[1].erase_4kb_opcode = inst4b->erase_1_inst;
  }
  else
  {
    status = SPINOR_DEVICE_FAIL;
    spinor_log (&p_spinor_dev->debug_log, 0x90D);
    SPINOR_LOG_ERROR("%s: Error, cannot obtain erase4K opcode \r\n", __func__);
    goto end;
  }

  if ((0x195A34 == device_id) || (0x195B34 == device_id))
  {
    if (inst4b->erase_4_support == 1U && inst4b->erase_4_inst != 0U)
    {
      config->access_param[1].erase_256kb_opcode = inst4b->erase_4_inst;
    }
    else
    {
      status = SPINOR_DEVICE_FAIL;
      spinor_log (&p_spinor_dev->debug_log, 0x90E);
      SPINOR_LOG_ERROR("%s: Error, cannot obtain erase256K opcode \r\n", __func__);
      goto end;
    }
  }

  /* All done. Set status to DONE */
  status = SPINOR_DEVICE_DONE;

end:
  return status;
}

SPINOR_STATUS spinor_sfdp_util_get_access_param_perf_read_opcode_ospi(spinor_sfdp_t *sfdp_data_read, uint32_t bus_clk_khz, uint32 read_mode, spinor_config_data *config, uint8_t manufacturer)
{
    SPINOR_STATUS status = SPINOR_DEVICE_FAIL;
    spinor_sfdp_basic_param *bparams = &sfdp_data_read->bparam_data;
    spinor_sfdp_4byte_inst  *inst4b  = &sfdp_data_read->inst4b_data;
    spinor_sfdp_xspi_profile_1_0 *profile10 = &sfdp_data_read->profile10_data;

    if (read_mode == SDR_1_1_8_MODE)
    {
      config->access_param[1].read_opcode = READ_SDR_4B_118_INST_F;
    }
    else if (read_mode == SDR_1_8_8_MODE)
    {
      config->access_param[1].read_opcode = READ_SDR_4B_188_INST_F;
    }
    else if(read_mode == SDR_1_1_1_MODE)
    {
      if (inst4b->read_111_support && bus_clk_khz <= SDR_1_1_READ_CODE_13H_MAX_FREQ_KHZ)
      {
        /* Bus freq must be <= SDR_1_1_READ_CODE_13H_MAX_FREQ_KHZ */
        config->access_param[1].read_opcode = READ_SDR_4B_111_INST;
      }
      else if (inst4b->fread_111_support)
      {
        config->access_param[1].read_opcode = READ_SDR_4B_111_INST_F;
      }
      else
      {
        /* This is error. no 0Ch op code but freq is higher than 54MHz */
        spinor_log (&p_spinor_dev->debug_log, 0x90F);
        SPINOR_LOG_ERROR("%s: Error, no 0Ch op code but freq is higher than 54MHz \r\n", __func__);
        goto end;
      }
    }
    else if(read_mode == SDR_8_8_8_MODE)
    {
      /* SDP xSPI profile1.0 does not define 888 SDR read opcode. The code is per vendor.
       * Now, we only added Macronix and Infineon case. It needs to be updated if
       * other vendor also supports 888 SDR */
      if (manufacturer == MANUFACTURER_ID_MACRONIX)
      {
        config->access_param[1].read_opcode = 0xEC;
      }
      else if (manufacturer == MANUFACTURER_ID_INFINEON)
      {
        config->access_param[1].read_opcode = 0xEC;
      }
      else if(manufacturer == MANUFACTURER_ID_GD)
      {
          config->access_param[1].read_opcode = 0x7C;
      }
      else
      {
        spinor_log (&p_spinor_dev->debug_log, 0x910);
        SPINOR_LOG_ERROR("%s: Error, vendors other than Macronix, Gigadevice and Infineon dont support SDR 8-8-8 as of now \r\n", __func__);
        goto end;
      }
    }
    else
    {
      config->access_param[1].read_opcode = profile10->read_fast_cmd; // should be hardcoded?
    }

    /* All done. Set status to DONE */
    status = SPINOR_DEVICE_DONE;

end:
  return status;
}

SPINOR_STATUS spinor_sfdp_util_get_access_param_perf_read_opcode_qspi(spinor_sfdp_t *sfdp_data_read, uint32_t bus_clk_khz, uint32 read_mode, spinor_config_data *config, uint8_t manufacturer)
{
    SPINOR_STATUS status = SPINOR_DEVICE_FAIL;
    spinor_sfdp_basic_param *bparams = &sfdp_data_read->bparam_data;
    spinor_sfdp_4byte_inst  *inst4b  = &sfdp_data_read->inst4b_data;

    if (read_mode == SDR_1_1_1_MODE)
    {
      if (inst4b->read_111_support && bus_clk_khz <= SDR_1_1_READ_CODE_13H_MAX_FREQ_KHZ)
      {
        /* Bus freq must be <= SDR_1_1_READ_CODE_13H_MAX_FREQ_KHZ */
        config->access_param[1].read_opcode = READ_SDR_4B_111_INST;
      }
      else if (inst4b->fread_111_support)
      {
        config->access_param[1].read_opcode = READ_SDR_4B_111_INST_F;
      }
      else
      {
        /* This is error. no 0Ch op code but freq is higher than 54MHz */
        spinor_log (&p_spinor_dev->debug_log, 0x911);
        SPINOR_LOG_ERROR("%s: Error, no 0Ch op code but freq is higher than 54MHz \r\n", __func__);
        goto end;
      }
    }
    else if (read_mode == SDR_1_1_4_MODE)
    {
      config->access_param[1].read_opcode = READ_SDR_4B_114_INST_F;
    }
    else if (read_mode == SDR_1_4_4_MODE)
    {
      config->access_param[1].read_opcode = READ_SDR_4B_144_INST;
    }
    else if (read_mode == SDR_4_4_4_MODE && bparams->read_444_support == 1U &&
             bparams->read_444_instruction != 0U)
    {
      if(manufacturer == MANUFACTURER_ID_MICRON)
      {
          config->access_param[1].read_opcode = 0xEC;
      }
      else
      {
      /* basic parameter table 7th DWORD */
      config->access_param[1].read_opcode = bparams->read_444_instruction;
      }
    }
    else if (read_mode == DDR_4_4_4_MODE && bparams->dtr_support == 1U &&
             bparams->read_444_support == 1U && bparams->read_444_instruction != 0U)
    {
      if(manufacturer == MANUFACTURER_ID_MICRON)
      {
          config->access_param[1].read_opcode = 0xEC;
      }
      else
      {
      /* basic parameter 5th and 7th DWORDs */
      config->access_param[1].read_opcode = bparams->read_444_instruction;  //mzhu discuss with Dilip. We used different op code in lookup table
      }
    }
    else
    {
      /* Error case. Or not implemented/supported */
      spinor_log (&p_spinor_dev->debug_log, 0x912);
      SPINOR_LOG_ERROR("%s: Error case \r\n", __func__);
      goto end;
    }

    /* All done. Set status to DONE */
    status = SPINOR_DEVICE_DONE;

end:
  return status;
}

SPINOR_STATUS spinor_sfdp_util_get_access_param_perf_write_opcode_ospi(spinor_sfdp_t *sfdp_data_read, spinor_config_data *config)
{
    SPINOR_STATUS status = SPINOR_DEVICE_FAIL;
    spinor_sfdp_basic_param *bparams = &sfdp_data_read->bparam_data;
    spinor_sfdp_4byte_inst  *inst4b  = &sfdp_data_read->inst4b_data;

    if (inst4b->prog_111_support == 1 && bparams->page_size == 0x08)
    {
      /* Now, mandate page size to be 256 bytes which is 2^8 bytes.
       * Page programming is not data bus # significent.
       * prog at 1-1-1 STR is the must. 444 or 888 should also use
       * 1-1-1 prog op code in 444 or 888 prog.
       */
      config->access_param[1].write_opcode = PROG_SDR_4B_111_INST;
    }
    else
    {
      /* Error. Have not found the guidance to extract
       * the 444 or 8888 prog op code in SDP table
       */
      spinor_log (&p_spinor_dev->debug_log, 0x913);
      SPINOR_LOG_ERROR("%s: Error, unable to extract the 888 prog opcode \r\n", __func__);
      goto end;
    }

    /* All done. Set status to DONE */
    status = SPINOR_DEVICE_DONE;

end:
  return status;
}

SPINOR_STATUS spinor_sfdp_util_get_access_param_perf_write_opcode_qspi(spinor_sfdp_t *sfdp_data_read, uint32 write_mode, spinor_config_data *config)
{
    SPINOR_STATUS status = SPINOR_DEVICE_FAIL;
    spinor_sfdp_basic_param *bparams = &sfdp_data_read->bparam_data;

    if (write_mode == SDR_1_1_1_MODE)
    {
      config->access_param[1].write_opcode = PROG_SDR_4B_111_INST;
    }
    else if (write_mode == SDR_1_1_4_MODE)
    {
      config->access_param[1].write_opcode = PROG_SDR_4B_114_INST;
    }
    else if (write_mode == SDR_1_4_4_MODE)
    {
      config->access_param[1].write_opcode = PROG_SDR_4B_144_INST;
    }
    else if (write_mode == SDR_4_4_4_MODE)
    {
      /* To follow the same logic defined in JESD251C page 16,
       * 111 PP instruction is assigned to 444S
       */
      config->access_param[1].write_opcode = PROG_SDR_4B_111_INST;
    }
    else if (write_mode == DDR_4_4_4_MODE && bparams->dtr_support == 1U)
    {
      /* To follow the same logic defined in JESD251C page 16,
       * 111 PP instruction is assigned to 444D
       */
      config->access_param[1].write_opcode = PROG_SDR_4B_111_INST;
    }
    else
    {
      /* Error case */
      spinor_log (&p_spinor_dev->debug_log, 0x914);
      SPINOR_LOG_ERROR("%s: Error case \r\n", __func__);
      goto end;
    }

    /* All done. Set status to DONE */
    status = SPINOR_DEVICE_DONE;

end:
  return status;
}

SPINOR_STATUS spinor_sfdp_util_get_quad_enable_mode(spinor_sfdp_t *sfdp_data_read, uint32_t device_id, spinor_sfdp_bus_t bus, uint8 *quad_enable_mode)
{
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;
  spinor_sfdp_basic_param *bparam = NULL;

  if (sfdp_data_read == NULL || quad_enable_mode == NULL)
  {
    status = SPINOR_DEVICE_FAIL;
    spinor_log (&p_spinor_dev->debug_log, 0x915);
    SPINOR_LOG_ERROR("%s: Error, sfdp_data_read or quad_enable_mode is NULL \r\n", __func__);
    goto end;
  }
  if (bus == SFDP_BUS_OSPI)
  {
    *quad_enable_mode = 0U;
  }
  else
  {
    bparam = &sfdp_data_read->bparam_data;
    if (bparam->quad_en_r == 0b000)
    {
       /* Device does not have a QE bit. Device detects 1-1-4 and 1-4-4 reads based on instruction.
        * IO3/HOLD# functions as hold during instruction phase */
       *quad_enable_mode = ENABLE_QUAD_MODE_0;
    }
    else if (bparam->quad_en_r == 0b001)
    {
      /* QE is bit 1 of status register 2. It is set via Write Status with two data bytes where bit 1 of the
       * second byte is one. It is cleared via Write Status with two data bytes where bit 1 of the second
       * byte is zero. Writing only one byte to the status register has the side-effect of clearing status
       * register 2, including the QE bit. The 100b code is used if writing one byte to the status register
       * does not modify status register 2
       */
      *quad_enable_mode = ENABLE_QUAD_MODE_1;
    }
    else if (bparam->quad_en_r == 0b010)
    {
      /* QE is bit 6 of status register 1. It is set via Write Status with one data byte where bit 6 is one.
       * It is cleared via Write Status with one data byte where bit 6 is zero
       */
      *quad_enable_mode = ENABLE_QUAD_MODE_2;
    }
    else if (bparam->quad_en_r == 0b011)
    {
      /* QE is bit 7 of status register 2. It is set via Write status register 2 instruction 3Eh with one data
       * byte where bit 7 is one. It is cleared via Write status register 2 instruction 3Eh with one data
       * byte where bit 7 is zero. The status register 2 is read using instruction 3Fh.
       */
      *quad_enable_mode = ENABLE_QUAD_MODE_3;
    }
    else if (bparam->quad_en_r == 0b100)
    {
      /* QE is bit 1 of status register 2. It is set via Write Status with two data bytes where bit 1 of the
       * second byte is one. It is cleared via Write Status with two data bytes where bit 1 of the second
       * byte is zero. In contrast to the 001b code, writing one byte to the status register does not
       * modify status register 2
       */
      *quad_enable_mode = ENABLE_QUAD_MODE_4;
    }
    else if (bparam->quad_en_r == 0b101)
    {
      /* QE is bit 1 of status register 2. It is set via Write Status with two data bytes where bit 1 of the
       * second byte is one. It is cleared via Write Status with two data bytes where bit 1 of the second
       * byte is zero. In contrast to the 001b code, writing one byte to the status register does not
       * modify status register 2
       */
      *quad_enable_mode = ENABLE_QUAD_MODE_5;
    }
    else if (bparam->quad_en_r == 0b110)
    {
      /* QE is bit 1 of the status register 2. Status register 1 is read using Read Status instruction 05h.
       * Status register 2 is read using instruction 35h, and status register 3 is read using instruction
       * 15h. QE is set via Write Status Register instruction 31h with one data byte where bit 1 is one.
       * It is cleared via Write Status Register instruction 31h with one data byte where bit 1 is zero
       */
      *quad_enable_mode = ENABLE_QUAD_MODE_6;
    }
    else
    {
      status = SPINOR_DEVICE_FAIL;
      spinor_log (&p_spinor_dev->debug_log, 0x916);
      SPINOR_LOG_ERROR("%s: Error, invalid quad_en_r case \r\n", __func__);
      goto end;
    }
  }
end:
  return status;
}
SPINOR_STATUS spinor_sfdp_util_get_enable_444_seq(spinor_sfdp_t *sfdp_data_read, uint32_t device_id, spinor_sfdp_bus_t bus, uint8 *enable_444_seq)
{
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;

  if (sfdp_data_read == NULL || enable_444_seq == NULL)
  {
    status = SPINOR_DEVICE_FAIL;
    spinor_log (&p_spinor_dev->debug_log, 0x917);
    SPINOR_LOG_ERROR("%s: Error, sfdp_data_read or enable_444_seq is NULL \r\n", __func__);
    goto end;
  }
  if(bus != SFDP_BUS_QSPI)
  {
    /* No enable_444_seq value for OSPI cards */
    *enable_444_seq = 0U;
    goto end;
  }
  if ((sfdp_data_read->bparam_data.enable_444_seq & 0b00010000) ||
      (sfdp_data_read->bparam_data.enable_444_seq & 0b00001000) ||
      (sfdp_data_read->bparam_data.enable_444_seq & 0b00000100) ||
      (sfdp_data_read->bparam_data.enable_444_seq & 0b00000010) ||
      (sfdp_data_read->bparam_data.enable_444_seq & 0b00000001) )
  {
    *enable_444_seq = sfdp_data_read->bparam_data.enable_444_seq;
  }
  else
  {
    status = SPINOR_DEVICE_FAIL;
    spinor_log (&p_spinor_dev->debug_log, 0x918);
    SPINOR_LOG_ERROR("%s: Error, invalid enable_444_seq value \r\n", __func__);
    goto end;
  }
end:
  return status;
}
SPINOR_STATUS spinor_sfdp_util_get_octal_enable_r(spinor_sfdp_t *sfdp_data_read, uint32_t device_id, spinor_sfdp_bus_t bus, uint8 *octal_enable_r, uint8 *octal_sdr_num_bytes)
{
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;
  uint8_t manufacturer = spinor_sfdp_util_get_manufacturer(device_id);

  *octal_sdr_num_bytes = ((manufacturer == MANUFACTURER_ID_MACRONIX) || (manufacturer == MANUFACTURER_ID_INFINEON)) ? 2 : 1;

  if (sfdp_data_read == NULL || octal_enable_r == NULL)
  {
    status = SPINOR_DEVICE_FAIL;
    spinor_log (&p_spinor_dev->debug_log, 0x919);
    SPINOR_LOG_ERROR("%s: Error, sfdp_data_read or octal_enable_r is NULL \r\n", __func__);
    goto end;
  }
  if (bus != SFDP_BUS_OSPI)
  {
    *octal_enable_r = 0U;
    SPINOR_LOG_WARNING("%s: Error, no octal_enable_r for QSPI cards \r\n", __func__);
    goto end;
  }
  if (sfdp_data_read->bparam_data.en_888_seq & 0b00010)
  {
    *octal_enable_r = ENABLE_OCTAL_MODE_2;
  }
  else if (sfdp_data_read->bparam_data.en_888_seq & 0b00100)
  {
    *octal_enable_r = ENABLE_OCTAL_MODE_4;
  }
  else if (manufacturer == MANUFACTURER_ID_MICRON_OSPI || manufacturer == MANUFACTURER_ID_GD
           || manufacturer == MANUFACTURER_ID_ISSI || manufacturer == MANUFACTURER_ID_WINBOND)
  {
    /* This is a hack for ISSI, Micron and Giga OSPI device.
     * Have not got reply back from GD and Micron about how to set to mode 7 */
    *octal_enable_r = ENABLE_OCTAL_MODE_7;
  }
  else if (manufacturer == MANUFACTURER_ID_INFINEON)
  {
    /* This is a hack for Infineon OSPI device. */
    *octal_enable_r = ENABLE_OCTAL_MODE_6;
  }
  else if (sfdp_data_read->bparam_data.octal_en_req == 0b000)
  {
    *octal_enable_r = ENABLE_OCTAL_MODE_0;
  }
  else if (sfdp_data_read->bparam_data.octal_en_req == 0b001)
  {
    *octal_enable_r = ENABLE_OCTAL_MODE_1;
  }
  else
  {
    status = SPINOR_DEVICE_FAIL;
    spinor_log (&p_spinor_dev->debug_log, 0x91B);
    SPINOR_LOG_ERROR("%s: Error, invalid octal_en_req value \r\n", __func__);
    goto end;
  }
end:
  return status;
}
SPINOR_STATUS spinor_sfdp_util_get_spi_io_mode(spinor_sfdp_t *sfdp_data_read, uint32_t device_id, spinor_sfdp_bus_t bus, uint8 *spi_io_mode, uint32_t read_mode)
{
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;
  if (sfdp_data_read == NULL || spi_io_mode == NULL)
  {
    status = SPINOR_DEVICE_FAIL;
    spinor_log (&p_spinor_dev->debug_log, 0x91C);
    SPINOR_LOG_ERROR("%s: Error, sfdp_data_read or spi_io_mode is NULL \r\n", __func__);
    goto end;
  }
  if(read_mode == SDR_1_1_1_MODE || read_mode == SDR_1_1_8_MODE || read_mode == SDR_1_8_8_MODE || read_mode == SDR_1_4_4_MODE || read_mode == SDR_1_1_4_MODE)
  {
      *spi_io_mode = SPI_IO_DEFAULT;
  }
  else if (bus == SFDP_BUS_OSPI)
  {
    *spi_io_mode = SPI_OCTAL_IO;
  }
  else if (bus == SFDP_BUS_QSPI)
  {
    *spi_io_mode = SPI_QUAD_IO;
  }
  else
  {
    status = SPINOR_DEVICE_FAIL;
    spinor_log (&p_spinor_dev->debug_log, 0x91D);
    SPINOR_LOG_ERROR("%s: Error, invalid spi_io_mode case \r\n", __func__);
    goto end;
  }
end:
  return status;
}
SPINOR_STATUS spinor_sfdp_util_get_device_transfer_rate(spinor_sfdp_t *sfdp_data_read, uint32_t device_id, spinor_sfdp_bus_t bus, uint32_t read_mode, uint8 *device_transfer_rate)
{
  /* Transfer rate type to be used for
   * the device based on needs and what is supported by the vendor
   * 0 - SPI_TRANSFER_STR,     --> Single Transfer Rate
   * 1 - SPI_TRANSFER_DTR      --> Dual Transfer Rate */
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;
  if (sfdp_data_read == NULL || device_transfer_rate == NULL)
  {
    status = SPINOR_DEVICE_FAIL;
    spinor_log (&p_spinor_dev->debug_log, 0x91E);
    SPINOR_LOG_ERROR("%s: Error, sfdp_data_read or device_transfer_rate is NULL \r\n", __func__);
    goto end;
  }
  switch (read_mode)
  {
  case SDR_1_1_1_MODE:
  case SDR_1_1_4_MODE:
  case SDR_1_4_4_MODE:
  case SDR_4_4_4_MODE:
  case SDR_1_1_8_MODE:
  case SDR_1_8_8_MODE:
  case SDR_8_8_8_MODE:
    *device_transfer_rate = SPI_TRANSFER_STR;
    break;
  case DDR_1_1_4_MODE:
  case DDR_1_4_4_MODE:
  case DDR_4_4_4_MODE:
  case DDR_1_1_8_MODE:
  case DDR_1_8_8_MODE:
  case DDR_8_8_8_MODE:
    *device_transfer_rate = SPI_TRANSFER_DTR;
    break;
  default:
    status = SPINOR_DEVICE_FAIL;
    spinor_log (&p_spinor_dev->debug_log, 0x91F);
    SPINOR_LOG_ERROR("%s: Error, invalid read_mode \r\n", __func__);
    goto end;
    break;
  }
end:
  return status;
}
SPINOR_STATUS spinor_sfdp_util_get_power_on_delay_in_100us(spinor_sfdp_t *sfdp_data_read, uint32_t device_id, spinor_sfdp_bus_t bus, uint8 *power_on_delay_in_100us)
{
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;

  if (sfdp_data_read == NULL || power_on_delay_in_100us == NULL)
  {
    status = SPINOR_DEVICE_FAIL;
    spinor_log (&p_spinor_dev->debug_log, 0x920);
    SPINOR_LOG_ERROR("%s: Error, sfdp_data_read or power_on_delay is NULL \r\n", __func__);
    goto end;
  }
  /* Hard code to default 800us */
  *power_on_delay_in_100us = SPINOR_INIT_POWER_ON_DELAY_IN_100US;

end:
  return status;
}
SPINOR_STATUS spinor_sfdp_util_get_dqs_sync_qspi_clk(spinor_sfdp_t *sfdp_data_read, uint32_t device_id, spinor_sfdp_bus_t bus, boolean *dqs_sync_qspi_clk)
{
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;

  if (sfdp_data_read == NULL || dqs_sync_qspi_clk == NULL)
  {
    status = SPINOR_DEVICE_FAIL;
    spinor_log (&p_spinor_dev->debug_log, 0x921);
    SPINOR_LOG_ERROR("%s: Error, sfdp_data_read or dqs_sync_qspi_clk is NULL \r\n", __func__);
    goto end;
  }
  /*
   * JESD216D-01 6.4.21 JEDEC Basic Flash Parameter Table: 18th DWORD 25:24b states:
   * Data Strobe Waveforms in STR Mode
   * 11b: First rising edge of DS half a clock cycle before the start of the first data bit, start of first
   * data bit aligned with the first falling edge of DS, first rising edge of DS follows a rising edge of
   * CK, as shown in Error! Reference source not found.
   * 10b: First rising edge of DS in the middle of the first data bit, start of second data bit aligned
   * with the first falling edge of DS, first rising edge of DS follows a Rising edge of CK, as shown
   * in Figure 19
   * 01b: Start of first data bit aligned with the first rising edge of DS, first rising edge of DS
   * follows a falling edge of CK, as shown in Figure 20
   * 00b: Reserved
   */
  *dqs_sync_qspi_clk = sfdp_data_read->bparam_data.dsw_str_mode != 0b01; /* 01b is async case. Micron, ISSI, and Giga device octal spi DDR */
end:
  return status;
}
SPINOR_STATUS spinor_sfdp_util_get_ecc_info(spinor_sfdp_t *sfdp_data_read, uint32_t device_id, spinor_sfdp_bus_t bus, spinor_config_data *config)
{
  SPINOR_STATUS status = SPINOR_DEVICE_DONE; //add device not supported and memset ecc vals to 0

  if (sfdp_data_read == NULL || config == NULL)
  {
    status = SPINOR_DEVICE_FAIL;
    spinor_log (&p_spinor_dev->debug_log, 0x922);
    SPINOR_LOG_ERROR("%s: Error, sfdp_data_read or config is NULL \r\n", __func__);
    goto end;
  }
end:
  return status;
}
SPINOR_STATUS spinor_sfdp_util_get_crc_info(spinor_sfdp_t *sfdp_data_read, uint32_t device_id, spinor_sfdp_bus_t bus, spinor_config_data *config)
{
  SPINOR_STATUS status = SPINOR_DEVICE_DONE; //add device not supported and memset crc vals to 0

  if (sfdp_data_read == NULL || config == NULL)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x923);
    SPINOR_LOG_ERROR("%s: Error, sfdp_data_read or config is NULL \r\n", __func__);
    status = SPINOR_DEVICE_FAIL;
    goto end;
  }
end:
  return status;
}
static SPINOR_STATUS get_111_read_opcode_0C_dummy_cycle(uint32_t device_id, spinor_sfdp_bus_t bus, uint32_t *dummy_cycle)
{
  uint8_t manufacturer = spinor_sfdp_util_get_manufacturer(device_id);
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;

  switch (manufacturer)
  {
  case MANUFACTURER_ID_MACRONIX:              // 0xC2
    /* Assume that QSPI also use 8. Need to revisit */
    *dummy_cycle = 8U;
    break;
  case MANUFACTURER_ID_MICRON:                // 0x20
    *dummy_cycle = 8U;
    break;
  case MANUFACTURER_ID_SPANSION:              // 0x01
     status = SPINOR_DEVICE_FAIL;
     break;
  case MANUFACTURER_ID_WINBOND:               // 0xEF
    *dummy_cycle = 20U;
    break;
  case MANUFACTURER_ID_MICRON_OSPI:           // 0x2C
    *dummy_cycle = 8U;
    break;
  case MANUFACTURER_ID_ISSI:                  // 0x9D
    *dummy_cycle = 8U;
    break;
  case MANUFACTURER_ID_GD:                    // 0xC8
    *dummy_cycle = 8U;
    break;
  default:
    status = SPINOR_DEVICE_FAIL;
    spinor_log (&p_spinor_dev->debug_log, 0x924);
    SPINOR_LOG_ERROR("%s: Error, invalid manufacturer ID \r\n", __func__);
    break;
  }
  return status;
}

SPINOR_STATUS spinor_sfdp_util_get_read_dummy_cycle(spinor_sfdp_t *sfdp_data_read, uint32_t device_id, spinor_sfdp_bus_t bus, uint32_t bus_clk_khz,
                                                               uint32_t read_mode, spinor_config_data *config)
{
  int retval=0;
  uint32_t spinor_prop_val=0;
  void *pDTB = NULL;
  int32_t root_offset = 0;
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;
  uint32_t dummy_cycle = 0;
  uint32_t bus_clk_mhz = bus_clk_khz / 1000;
  uint32_t bus_clk_mhz_now = bus_clk_mhz;
  uint32_t idx = 0;
  uint8_t manufacturer = spinor_sfdp_util_get_manufacturer(device_id);
  /* Clear old data */
  memset(config->dummy_cycle_info.dummy_clocks_freq_vs_number, 0, sizeof(config->dummy_cycle_info.dummy_clocks_freq_vs_number));
  if (bus == SFDP_BUS_OSPI && sfdp_data_read->profile10_size > 0 && sfdp_data_read->inst_4byte_size > 0)
  {
    if (sfdp_data_read->profile10_data.num_dummy_cycles_required_200mhz_operation > 0U  && bus_clk_mhz <= 200)
    {
      /* the pattern must not be zero
      if (sfdp_data_read->profile10_data.cfg_bit_pattern_to_set_this_num_of_dummy_cycles_200mhz_operation == 0U)
      {
        status = SPINOR_DEVICE_FAIL;
        goto end;
      }*/

      if (manufacturer == MANUFACTURER_ID_MICRON_OSPI && bus_clk_mhz_now < 166)
      {
        dummy_cycle = 0x10;
        bus_clk_mhz = 166; // right now the controller only supports upto 166Mhz
      }
      else
      {
        dummy_cycle = sfdp_data_read->profile10_data.num_dummy_cycles_required_200mhz_operation;
        bus_clk_mhz = 166; // right now the controller only supports upto 166Mhz
      }
    }
    else if (sfdp_data_read->profile10_data.num_dummy_cycles_required_166mhz_operation > 0U  && bus_clk_mhz <= 166)
    {
      /* the pattern must not be zero
      if (sfdp_data_read->profile10_data.cfg_bit_pattern_to_set_this_num_of_dummy_cycles_166mhz_operation == 0U)
      {
        status = SPINOR_DEVICE_FAIL;
        goto end;
      }*/
      dummy_cycle = sfdp_data_read->profile10_data.num_dummy_cycles_required_166mhz_operation;
      bus_clk_mhz = 166;
    }
    else if (sfdp_data_read->profile10_data.num_dummy_cycles_required_133mhz_operation > 0U && bus_clk_mhz <= 133)
    {
      /*if (sfdp_data_read->profile10_data.cfg_bit_pattern_to_set_this_num_of_dummy_cycles_100mhz_operation == 0U)
      {
        status = SPINOR_DEVICE_FAIL;
        goto end;
      }*/
      dummy_cycle = sfdp_data_read->profile10_data.num_dummy_cycles_required_133mhz_operation;
      bus_clk_mhz = 133;
    }
    else if (sfdp_data_read->profile10_data.num_dummy_cycles_required_100mhz_operation > 0U && bus_clk_mhz <= 100)
    {
        /*if (sfdp_data_read->profile10_data.cfg_bit_pattern_to_set_this_num_of_dummy_cycles_100mhz_operation == 0U)
        {
          status = SPINOR_DEVICE_FAIL;
          goto end;
        }*/
      dummy_cycle = sfdp_data_read->profile10_data.num_dummy_cycles_required_100mhz_operation;
      bus_clk_mhz = 100;
    }
    else
    {
      status = SPINOR_DEVICE_FAIL;
      spinor_log (&p_spinor_dev->debug_log, 0x925);
      SPINOR_LOG_ERROR("%s: Error, invalid dummy_cycle set case \r\n", __func__);
      goto end;
    }

    if (read_mode == DDR_8_8_8_MODE || read_mode == SDR_8_8_8_MODE)
    {
      idx = (read_mode == SDR_8_8_8_MODE) ? 8 : 9;
    }
    else if (read_mode == SDR_1_1_8_MODE || read_mode == SDR_1_8_8_MODE)
    {
      if (read_mode == SDR_1_1_8_MODE)
      {
        dummy_cycle = sfdp_data_read->bparam_data.read_118_dummy_cycles + sfdp_data_read->bparam_data.read_118_mode_clocks;
        idx = 6;
      }
      else
      {
        dummy_cycle = sfdp_data_read->bparam_data.read_188_dummy_cycles + sfdp_data_read->bparam_data.read_188_mode_clocks;
        idx = 7;
      }
      if (dummy_cycle != sfdp_data_read->profile10_data.num_dummy_cycles_required_166mhz_operation &&
          sfdp_data_read->profile10_data.num_dummy_cycles_required_166mhz_operation > 0 &&
          bus_clk_mhz_now > SPINOR_DEFAULT_BUS_FREQ_MHZ_OSPI)
      {
        /* This means that the default 1-1-8 or 1-8-8 freq is not the max.
         * The default freq requirement should be satisfied */
        status = SPINOR_DEVICE_FAIL;
        spinor_log (&p_spinor_dev->debug_log, 0x926);
        SPINOR_LOG_ERROR("%s: Error, the default 1-1-8 or 1-8-8 freq is not the max \r\n", __func__);
        goto end;
      }
    }
    else if(read_mode == SDR_1_1_1_MODE)
    {
        if(config->access_param[1].read_opcode == READ_SDR_4B_111_INST)
        {
            dummy_cycle = 0;
            idx = 1;
        }
        else if(config->access_param[1].read_opcode == READ_SDR_4B_111_INST_F)
        {
            dummy_cycle = 8;
            idx = 1;
        }
        else
        {
        status = SPINOR_DEVICE_FAIL;
        spinor_log (&p_spinor_dev->debug_log, 0x927);
        SPINOR_LOG_ERROR("%s: Error, invalid read opcode \r\n", __func__);
        goto end;
      }
    }
    config->dummy_cycle_info.dummy_clocks_freq_vs_number[0][0] = bus_clk_mhz;
    config->dummy_cycle_info.dummy_clocks_freq_vs_number[0][idx] = dummy_cycle;
    config->dummy_cycle_info.dummy_clocks_freq_vs_number[1][0] = 0xFFFFFFFF;
    config->dummy_cycle_info.dummy_clocks_freq_vs_number[1][idx] = 0xFF;
  }
  else if (bus == SFDP_BUS_QSPI && sfdp_data_read->inst_4byte_size > 0)
  {
      /* QSPI */
    switch (read_mode)
    {
    case SDR_1_1_1_MODE:
      if (sfdp_data_read->inst4b_data.fread_111_support == 0U && sfdp_data_read->inst4b_data.read_111_support == 0)
      {
        /* no 1-1-1 support */
        goto end;
      }
      if (bus_clk_khz <= SDR_1_1_READ_CODE_13H_MAX_FREQ_KHZ && sfdp_data_read->inst4b_data.read_111_support == 1U)
      {
        dummy_cycle = 0U;
      }
      else if (sfdp_data_read->inst4b_data.fread_111_support == 1U)
      {
        status = get_111_read_opcode_0C_dummy_cycle(device_id, bus, &dummy_cycle);
        if (status != SPINOR_DEVICE_DONE)
        {
          spinor_log (&p_spinor_dev->debug_log, 0x928);
          SPINOR_LOG_ERROR("%s: Error, get_111_read_opcode_0C_dummy fail \r\n", __func__);
          goto end;
        }
      }
      else
      {
        status = SPINOR_DEVICE_FAIL;
        goto end;
      }
      idx = 1;
      break;
    case SDR_1_1_4_MODE:
    case SDR_1_4_4_MODE:
    {
      uint32_t dummy444 = sfdp_data_read->bparam_data.read_444_dummy_cycles + sfdp_data_read->bparam_data.read_444_mode_clocks;

      if (read_mode == SDR_1_1_4_MODE)
      {
        dummy_cycle = sfdp_data_read->bparam_data.read_114_dummy_cycles + sfdp_data_read->bparam_data.read_114_mode_clocks;
        idx = 2;
      }
      else
      {
        dummy_cycle = sfdp_data_read->bparam_data.read_144_dummy_cycles + sfdp_data_read->bparam_data.read_144_mode_clocks;
        idx = 3;
      }
      if (dummy_cycle != dummy444 && bus_clk_khz > SPI_BUS_MAX_SUPPORTED_FREQ_KHZ_QSPI)
      {
        /* This means that the default 1-1-4 or 1-4-4 freq is not the max.
         * The default freq requirement should be satisfied */
        status = SPINOR_DEVICE_FAIL;
        spinor_log (&p_spinor_dev->debug_log, 0x929);
        SPINOR_LOG_ERROR("%s: Error, the default 1-1-4 or 1-4-4 freq is not the max \r\n", __func__);
        goto end;
      }
      break;
    }
    case SDR_4_4_4_MODE:
    case DDR_4_4_4_MODE:
      if(manufacturer == MANUFACTURER_ID_MICRON && (bus_clk_mhz_now == 9 || bus_clk_mhz_now == 80) && read_mode == SDR_4_4_4_MODE)
      {
          dummy_cycle = 10;
          idx = 4; //(read_mode == SDR_4_4_4_MODE) ? 4 : 5;
      }
      else if(manufacturer == MANUFACTURER_ID_MICRON && (bus_clk_mhz_now == 9 || bus_clk_mhz_now == 80) && read_mode == DDR_4_4_4_MODE)
      {
          dummy_cycle = 8;
          idx =  5; //(read_mode == SDR_4_4_4_MODE) ? 4 : 5;
      }
      else
      {
      dummy_cycle = sfdp_data_read->bparam_data.read_444_dummy_cycles + sfdp_data_read->bparam_data.read_444_mode_clocks;
    idx = (read_mode == SDR_4_4_4_MODE) ? 4 : 5;
      }
      break;
    default:
      status = SPINOR_DEVICE_FAIL;
      spinor_log (&p_spinor_dev->debug_log, 0x92A);
      SPINOR_LOG_ERROR("%s: Error, invalid read_mode \r\n", __func__);
      goto end;
      break;
    }
    /* bus_clk_mhz has been verified against basic parameter table's QSPI frequency parameter */
    config->dummy_cycle_info.dummy_clocks_freq_vs_number[0][0] = bus_clk_mhz;
    config->dummy_cycle_info.dummy_clocks_freq_vs_number[0][idx] = dummy_cycle;
    config->dummy_cycle_info.dummy_clocks_freq_vs_number[1][0] = 0xFFFFFFFF;
    config->dummy_cycle_info.dummy_clocks_freq_vs_number[1][idx] = 0xFF;
  }
  else
  {
    status = SPINOR_DEVICE_FAIL;
    spinor_log (&p_spinor_dev->debug_log, 0x92B);
    SPINOR_LOG_ERROR("%s: Error, invalid case \r\n", __func__);
    goto end;
  }
end:
  return status;
}
SPINOR_STATUS spinor_sfdp_util_get_dummy_cycle_info(spinor_sfdp_t *sfdp_data_read, uint32_t device_id, spinor_sfdp_bus_t bus,
                                                               uint32_t bus_clk_khz, uint32_t read_mode, spinor_config_data *config)
{
  uint8_t manufacturer = spinor_sfdp_util_get_manufacturer(device_id);
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;

  status = spinor_sfdp_util_get_read_dummy_cycle(sfdp_data_read, device_id, bus, bus_clk_khz, read_mode, config);
  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x92C);
    SPINOR_LOG_ERROR("%s: Error, get_read_dummy_cycle fail \r\n", __func__);
    goto end;
  }
  if (manufacturer == MANUFACTURER_ID_MACRONIX) /* Maconix OSPI such as device_id 0x003C84C2 */
  {
    config->dummy_cycle_info.dummy_cycle_config_addr = 0x300;
    config->dummy_cycle_info.dummy_cycle_reg_rd_opcode = READ_CFG2_CMD;
    config->dummy_cycle_info.dummy_cycle_reg_wr_opcode = WRITE_CFG2_CMD;
    config->dummy_cycle_info.dummy_cycle_config_bmsk = 0x07;
    config->dummy_cycle_info.dummy_config_shift = 0;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[0][0] = 6;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[0][1] = 0x7;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[1][0] = 8;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[1][1] = 0x6;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[2][0] = 10;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[2][1] = 0x5;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[3][0] = 12;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[3][1] = 0x4;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[4][0] = 14;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[4][1] = 0x3;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[5][0] = 16;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[5][1] = 0x2;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[6][0] = 18;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[6][1] = 0x1;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[7][0] = 20;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[7][1] = 0x0;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[8][0] = 0xFF;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[8][1] = 0xFF;
  }
  else if (manufacturer == MANUFACTURER_ID_MICRON) /* Micron QSPI such as device_id 0x0019BB20 */
  {
    config->dummy_cycle_info.dummy_cycle_config_addr = 0x00;
    config->dummy_cycle_info.dummy_cycle_reg_rd_opcode = READ_VOLATILE_CFG_CMD;
    config->dummy_cycle_info.dummy_cycle_reg_wr_opcode = WRITE_VOLATILE_CFG_CMD;
    config->dummy_cycle_info.dummy_cycle_config_bmsk = 0xF0;
    config->dummy_cycle_info.dummy_config_shift = 4;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[0][0] = 1;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[0][1] = 0x01;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[1][0] = 3;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[1][1] = 0x03;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[2][0] = 4;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[2][1] = 0x04;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[3][0] = 5;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[3][1] = 0x05;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[4][0] = 6;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[4][1] = 0x06;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[5][0] = 7;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[5][1] = 0x07;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[6][0] = 8;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[6][1] = 0x08;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[7][0] = 10;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[7][1] = 0x0A;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[8][0] = 14;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[8][1] = 0x0E;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[9][0] = 0xFF;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[9][1] = 0xFF;
  }
  else if (manufacturer == MANUFACTURER_ID_MICRON_OSPI) /* Micron OSPI such as device_id 0x001C5B2C */
  {
    config->dummy_cycle_info.dummy_cycle_config_addr = 0x01;
    config->dummy_cycle_info.dummy_cycle_reg_rd_opcode = READ_VOLATILE_CFG_CMD;
    config->dummy_cycle_info.dummy_cycle_reg_wr_opcode = WRITE_VOLATILE_CFG_CMD;
    config->dummy_cycle_info.dummy_cycle_config_bmsk = 0xFF;
    config->dummy_cycle_info.dummy_config_shift = 0;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[0][0] = 1;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[0][1] = 0x01;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[1][0] = 3;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[1][1] = 0x03;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[2][0] = 5;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[2][1] = 0x05;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[3][0] = 6;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[3][1] = 0x06;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[4][0] = 7;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[4][1] = 0x07;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[5][0] = 8;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[5][1] = 0x08;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[6][0] = 16;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[6][1] = 0x10;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[7][0] = 17;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[7][1] = 0x11;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[8][0] = 20;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[8][1] = 0x14;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[9][0] = 0xFF;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[9][1] = 0xFF;
  }
  else if (manufacturer == MANUFACTURER_ID_SPANSION)
  {
    /* Not support yet */
    status = SPINOR_DEVICE_FAIL;
  }
  else if (manufacturer == MANUFACTURER_ID_WINBOND)
  {
    config->dummy_cycle_info.dummy_cycle_config_addr = 0x01;
    config->dummy_cycle_info.dummy_cycle_reg_rd_opcode = READ_VOLATILE_CFG_CMD;
    config->dummy_cycle_info.dummy_cycle_reg_wr_opcode = WRITE_VOLATILE_CFG_CMD;
    config->dummy_cycle_info.dummy_cycle_config_bmsk = 0xFF;
    config->dummy_cycle_info.dummy_config_shift = 0;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[0][0] = 4;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[0][1] = 0x04;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[1][0] = 5;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[1][1] = 0x05;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[2][0] = 6;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[2][1] = 0x06;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[3][0] = 7;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[3][1] = 0x07;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[4][0] = 8;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[4][1] = 0x08;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[5][0] = 16;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[5][1] = 0x10;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[6][0] = 17;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[6][1] = 0x11;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[7][0] = 19;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[7][1] = 0x13;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[8][0] = 22;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[8][1] = 0x16;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[9][0] = 0xFF;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[9][1] = 0xFF;
  }
  else if (manufacturer == MANUFACTURER_ID_ISSI)
  {
    config->dummy_cycle_info.dummy_cycle_config_addr = 0x01;
    config->dummy_cycle_info.dummy_cycle_reg_rd_opcode = READ_VOLATILE_CFG_CMD;
    config->dummy_cycle_info.dummy_cycle_reg_wr_opcode = WRITE_VOLATILE_CFG_CMD;
    config->dummy_cycle_info.dummy_cycle_config_bmsk = 0xFF;
    config->dummy_cycle_info.dummy_config_shift = 0;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[0][0] = 1;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[0][1] = 0x01;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[1][0] = 3;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[1][1] = 0x03;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[2][0] = 5;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[2][1] = 0x05;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[3][0] = 6;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[3][1] = 0x06;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[4][0] = 8;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[4][1] = 0x08;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[5][0] = 16;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[5][1] = 0x10;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[6][0] = 17;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[6][1] = 0x11;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[7][0] = 20;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[7][1] = 0x14;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[8][0] = 31;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[8][1] = 0x1F;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[9][0] = 0xFF;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[9][1] = 0xFF;
  }
  else if (manufacturer == MANUFACTURER_ID_GD)
  {
    config->dummy_cycle_info.dummy_cycle_config_addr = 0x01;
    config->dummy_cycle_info.dummy_cycle_reg_rd_opcode = READ_VOLATILE_CFG_CMD;
    config->dummy_cycle_info.dummy_cycle_reg_wr_opcode = WRITE_VOLATILE_CFG_CMD;
    config->dummy_cycle_info.dummy_cycle_config_bmsk = 0xFF;
    config->dummy_cycle_info.dummy_config_shift = 0;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[0][0] = 5;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[0][1] = 0x05;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[1][0] = 6;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[1][1] = 0x06;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[2][0] = 7;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[2][1] = 0x07;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[3][0] = 8;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[3][1] = 0x08;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[4][0] = 10;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[4][1] = 0x0A;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[5][0] = 14;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[5][1] = 0x0E;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[6][0] = 16;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[6][1] = 0x10;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[7][0] = 17;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[7][1] = 0x11;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[8][0] = 20;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[8][1] = 0x14;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[9][0] = 0xFF;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[9][1] = 0xFF;
  }
  else if (manufacturer == MANUFACTURER_ID_INFINEON) /* Infineon OSPI such as device_id 0x195B34 or 0x195A34 */
  {
    config->dummy_cycle_info.dummy_cycle_config_addr = 0x00800003;
    config->dummy_cycle_info.dummy_cycle_reg_rd_opcode = READ_CFG_CMD;
    config->dummy_cycle_info.dummy_cycle_reg_wr_opcode = WRITE_CFG_CMD;
    config->dummy_cycle_info.dummy_cycle_config_bmsk = 0x0F;
    config->dummy_cycle_info.dummy_config_shift = 0;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[0][0] = 20;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[0][1] = 0x8;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[1][0] = 23;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[1][1] = 0xA;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[2][0] = 10;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[2][1] = 0x5;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[3][0] = 12;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[3][1] = 0x4;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[4][0] = 14;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[4][1] = 0x3;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[5][0] = 16;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[5][1] = 0x2;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[6][0] = 18;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[6][1] = 0x1;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[7][0] = 20;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[7][1] = 0x0;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[8][0] = 0xFF;
    config->dummy_cycle_info.dummy_clocks_number_vs_regval[8][1] = 0xFF;
  }
  else
  {
    spinor_log (&p_spinor_dev->debug_log, 0x92D);
    SPINOR_LOG_ERROR("%s: Error, invalid manufacturer ID \r\n", __func__);
    status = SPINOR_DEVICE_FAIL;
  }
end:
  return status;
}

uint8_t spinor_sfdp_util_get_manufacturer(uint32_t device_id)
{
  uint8_t manufacturer = device_id & 0xFF;
  return manufacturer;
}
/* EOF */
