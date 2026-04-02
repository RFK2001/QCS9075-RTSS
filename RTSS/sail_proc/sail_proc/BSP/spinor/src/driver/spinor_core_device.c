/*
===========================================================================
*/
/**
    @file  spinor_utils.c
    @brief Implementation of spinor driver support functions

*/
/*
    ===========================================================================

    Copyright (c) 2017,2018,2020-2024 Qualcomm Technologies, Inc.
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
#include "spinor_utils.h"
#include "spinor_core.h"
#include "spinor_job.h"
#include "spinor_init_config.h"
#include "spinor_cm_defs.h"
#include "spinor_osal.h"
#include "spinor_sfdp.h"
#include "spinor_cmd.h"
#include "spinor_access.h"
#include "common_functions.h"
#include "debug_log.h"
#include "spinor_diag.h"
#include "spinor_pvl_api.h"


static SPINOR_STATUS enable_qpi_mode_5 (void);
static SPINOR_STATUS enable_qpi_mode_4 (void);
static SPINOR_STATUS enable_qpi_mode_3 (void);
static SPINOR_STATUS enable_qpi_mode_2 (void);
static SPINOR_STATUS enable_qpi_mode_1 (void);

static SPINOR_STATUS enable_quad_mode_3 (void);
static SPINOR_STATUS enable_quad_mode_1_4_5 (void);
static SPINOR_STATUS enable_quad_mode_2 (void);
static SPINOR_STATUS enable_qer_mode (uint8 qer_mode);
static SPINOR_STATUS enable_quad_mode (void);

static SPINOR_STATUS enable_octal_mode_1 (void);
static SPINOR_STATUS enable_octal_mode_2 (void);
static SPINOR_STATUS enable_octal_mode_4 (void);
static SPINOR_STATUS enable_octal_mode_6 (void);
static SPINOR_STATUS enable_octal_mode_7 (void);
static SPINOR_STATUS enable_octal_mode (void);

/**********************************************************
 * Look up RAM table to find the spinor config info.
 * Save the data in spinor's RAM AON
 *
 * @param spinor_config_tbl [IN]
 *   RAM table containing config data for supported spinor devices
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_device_lookup (boolean is_crash_dbg, void *spinor_config_tbl, spinor_hardcode_data_mode *hardcoded_data_mode)
{
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;
  uint32_t device_id = 0;
  spinor_sfdp_t *sfdp_data_read = NULL;

  /* Read the spinor Device ID */
  status = spinor_util_read_device_id((void *)&device_id, DEVICE_ID_LEN_IN_BYTES);
  if ( status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x501);
    SPINOR_LOG_ERROR("%s: Error, read device ID failed \r\n", __func__);
    goto spinor_device_lookup_end;
  }

  if ( 0 == device_id || 0xFFFFFFFF == device_id )
  {
    spinor_log (&p_spinor_dev->debug_log, 0x502);
    SPINOR_LOG_ERROR("%s: Error, invalid device ID \r\n", __func__);
    status = SPINOR_DEVICE_NOT_FOUND; /* device not found in NOR card */
    goto spinor_device_lookup_end;
  }

  device_id = device_id & 0xFFFFFF;

  status = spinor_sfdp_read_tables(device_id, &sfdp_data_read);
  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x503);
    SPINOR_LOG_ERROR("%s: Error in spinor_sfdp_read_tables, status = %d \r\n", __func__, status);
    goto spinor_device_lookup_end;
  }
  if (NULL == sfdp_data_read)
  {
    /* This is a SW bug */
    SPINOR_LOG_ERROR("%s: Error - sfdp_data_read pointer is NULL \r\n", __func__);
    status = SPINOR_DEVICE_NULL_POINTER;
    goto spinor_device_lookup_end;
  }

  p_spinor_dev->disable_data_dummy_cycle_recfg = (hardcoded_data_mode) ? hardcoded_data_mode->hardcode_no_data_read_dummy_cycle_recfg : 0U;

#if 1
  status = spinor_parse_sfdp2(is_crash_dbg, device_id, hardcoded_data_mode, p_spinor_dev->config_data, sfdp_data_read);
  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x504);
    SPINOR_LOG_ERROR("%s: Error in parse_sfdp2, status = %d \r\n", __func__, status);
    (void)spinor_pvl_sfdp_dump();
  }
    goto spinor_device_lookup_end;
#else
  /* The device has not been found, Try SFDP. */
  manufacturer = device_id & 0xFF;
  status = spinor_parse_sfdp(p_spinor_dev->config_data, device_id, sfdp_data_read);
  if (SPINOR_DEVICE_DONE != status)
  {
    SPINOR_LOG_ERROR("%s: Error, parse_sfdp failed failed \r\n", __func__);
    goto spinor_device_lookup_end;
  }

  p_spinor_dev->config_data->device_id = device_id & 0xFFFFFF;
#endif

spinor_device_lookup_end:
  if (status != SPINOR_DEVICE_DONE)
  {
    DEBUG_LOG(SAIL_ERROR,"%s: Error, device_id = 0x%x, status = %d \r\n", __func__, device_id, status);
  }
  return status;
}

/**********************************************************
 * Enables Quad Mode 4-4-4
 *
 * @reg_value [OUT]
 *   Register Value
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
static SPINOR_STATUS enable_quad_mode (void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint8 temp = 0;

    if (SPI_IO_DEFAULT == p_spinor_dev->config_data->spi_io_mode)
    {
      p_spinor_dev->mode_enabled = SPI_DEFAULT_SDR;
      SPINOR_LOG_INFO("%s: Info, SPI_DEFAULT_SDR mode enabled \r\n", __func__);
      goto enable_quad_mode_end;
    }

    if(p_spinor_dev->config_data->enable_444_seq & 0b00010000)
    {
        status = enable_qpi_mode_5();
        SPINOR_LOG_INFO("%s: Info, QPI mode 5 mode enabled \r\n", __func__);
    }
    else if(p_spinor_dev->config_data->enable_444_seq & 0b00001000)
    {
        status = enable_qpi_mode_4();
        SPINOR_LOG_INFO("%s: Info, QPI Mode 4 mode enabled \r\n", __func__);
    }
    else if(p_spinor_dev->config_data->enable_444_seq & 0b00000100)
    {
        status = enable_qpi_mode_3();
        SPINOR_LOG_INFO("%s: Info, QPI Mode 3 mode enabled \r\n", __func__);
    }
    else if(p_spinor_dev->config_data->enable_444_seq & 0b00000010)
    {
        status = enable_qpi_mode_2();
        SPINOR_LOG_INFO("%s: Info, QPI Mode 2 mode enabled \r\n", __func__);
    }
    else if(p_spinor_dev->config_data->enable_444_seq & 0b00000001)
    {
        status = enable_qpi_mode_1();
        SPINOR_LOG_INFO("%s: Info, QPI Mode 1 mode enabled \r\n", __func__);
    }
    else
    {
        status = SPINOR_DEVICE_FAIL;
    }

    if(status == SPINOR_DEVICE_DONE)
    {
      p_spinor_dev->mode_enabled = (spinor_mode_type)((p_spinor_dev->config_data->device_transfer_rate<< 2) | (p_spinor_dev->config_data->spi_io_mode));
      status = spinor_util_check_operation_status(&temp);
      if (status != SPINOR_DEVICE_DONE)
      {
        p_spinor_dev->debug_log.spinor_status = temp;
        spinor_log (&p_spinor_dev->debug_log, 0x505);
        SPINOR_LOG_ERROR("%s: Error, check operation status fail \r\n", __func__);
        goto enable_quad_mode_end;
      }
    }
    else
    {
      p_spinor_dev->debug_log.spinor_status = status;
      spinor_log (&p_spinor_dev->debug_log, 0x506);
      SPINOR_LOG_ERROR("%s: Error, enable quad mode fail \r\n", __func__);
      goto enable_quad_mode_end;
    }

enable_quad_mode_end:
    return status;
}

/**********************************************************
 * Enables Quad Mode
 *
 * @qer_mode [IN]
 *   Mode is queried from the sfdp's 15th DWORD. Depending on the mode,
 *   different registers are used to enable the Quad Mode.
 *   Refer to the Standard JEDEC 216A Section 6.4.15 for details.
 *
 * @reg_value [OUT]
 *   Register Value
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
static SPINOR_STATUS enable_qer_mode (uint8 qer_mode)
{
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;

  switch (qer_mode)
  {
  case ENABLE_QUAD_MODE_0:
    /* Device does not have QE bit. Device detects 1-1-4 and 1-4-4 modes */
    /* based on instruction */
    break;

  case ENABLE_QUAD_MODE_1:
  case ENABLE_QUAD_MODE_4:
  case ENABLE_QUAD_MODE_5:
    /* Break big funtion into smaller ones */
    status = enable_quad_mode_1_4_5();
    break;

  case ENABLE_QUAD_MODE_2:
    status = enable_quad_mode_2();
    break;

  case ENABLE_QUAD_MODE_3:
    status = enable_quad_mode_3();
    break;

  case ENABLE_QUAD_MODE_6:
  case ENABLE_QUAD_MODE_7:
  default:
    status = SPINOR_DEVICE_FAIL;
    break;
  }

  if(status != SPINOR_DEVICE_DONE)
  {
      spinor_log (&p_spinor_dev->debug_log, 0x507);
      SPINOR_LOG_ERROR("%s: Error, enable QER mode fail \r\n", __func__);
      goto enable_qer_mode_end;
  }
  SPINOR_LOG_INFO("%s: Info, Quad mode %d enabled \r\n", __func__, qer_mode);

enable_qer_mode_end:
  return status;
}
/**********************************************************
 * Enables Octal Mode 8-8-8
 *
 * @reg_value [OUT]
 *   Register Value
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
static SPINOR_STATUS enable_octal_mode (void)
{

    SPINOR_STATUS status = SPINOR_DEVICE_DONE;

    if (SPI_IO_DEFAULT == p_spinor_dev->config_data->spi_io_mode)
    {
      p_spinor_dev->mode_enabled = SPI_DEFAULT_SDR;
      goto enable_octal_mode_end;
    }

    switch (p_spinor_dev->config_data->octal_enable_r)
    {
    case ENABLE_OCTAL_MODE_0:
      /* Device does not have an Octal Enable bit. */
      p_spinor_dev->mode_enabled = SPI_DEFAULT_SDR;
      break;

    case ENABLE_OCTAL_MODE_1:
      /* Break big funtion into smaller ones */
      status = enable_octal_mode_1();
      p_spinor_dev->mode_enabled = SPI_OCTAL_SDR;
      break;

    case ENABLE_OCTAL_MODE_2:
      status = enable_octal_mode_2();
      p_spinor_dev->mode_enabled = SPI_OCTAL_SDR;
      break;


    case ENABLE_OCTAL_MODE_4:
      status = enable_octal_mode_4();
      p_spinor_dev->mode_enabled = (spinor_mode_type)((p_spinor_dev->config_data->device_transfer_rate<< 2) | (p_spinor_dev->config_data->spi_io_mode));
      break;


    case ENABLE_OCTAL_MODE_7:
      status = enable_octal_mode_7();

      if(p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_mode == SDR_8_8_8_MODE)
          p_spinor_dev->mode_enabled = SPI_OCTAL_SDR;
      else
          p_spinor_dev->mode_enabled = SPI_OCTAL_DDR;
      break;


    case ENABLE_OCTAL_MODE_6:
        status = enable_octal_mode_6();

      if(p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_mode == SDR_8_8_8_MODE)
          p_spinor_dev->mode_enabled = SPI_OCTAL_SDR;
      else
          p_spinor_dev->mode_enabled = SPI_OCTAL_DDR;
      break;

    case ENABLE_OCTAL_MODE_3:
    case ENABLE_OCTAL_MODE_5:
    default:
      status = SPINOR_DEVICE_FAIL;
      p_spinor_dev->mode_enabled = SPI_DEFAULT_SDR;
      break;
    }

    if(status != SPINOR_DEVICE_DONE)
    {
      p_spinor_dev->debug_log.spinor_status = status;
      spinor_log (&p_spinor_dev->debug_log, 0x508);
      SPINOR_LOG_ERROR("%s: Error, enable octal mode fail \r\n", __func__);
      goto enable_octal_mode_end;
    }

    SPINOR_LOG_INFO("%s: Info, Octal mode %d enabled \r\n", __func__, p_spinor_dev->config_data->octal_enable_r);

    p_spinor_dev->octal_mode_enabled = TRUE;

enable_octal_mode_end:
    return status;
}

/**********************************************************
 * Enables Octal Mode. Mode 1
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
static SPINOR_STATUS enable_octal_mode_1 (void)
{
  uint32 status_reg2 = 0;
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;
  SPI_COMMAND_TYPE command_mode = OSPI_REGISTER_READ;

  /* Read/modify/write operation.*/
  status = spinor_util_read_reg_addr (READ_OCTAL_EN_STATUS_2_CMD,0x02, 1,(uint8*)&status_reg2,sizeof(status_reg2));
  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x509);
    SPINOR_LOG_ERROR("%s: Error, register read failed \r\n", __func__);
  }

  if((uint8)status_reg2 & BIT_3)
  {
    /* Octal Mode is already enabled */
    goto enable_octal_mode_1_end;
  }

  /* Set Bit3 of status register2 to enable Octal mode (OER Bit) */
  /* Read/Modify/Write 1 bytes back */
  status_reg2 |= BIT_3;

  status = spinor_util_write_register(WRITE_OCTAL_EN_STATUS_2_CMD, 1, (uint8 *)&status_reg2, sizeof(status_reg2));
  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x50A);
    SPINOR_LOG_ERROR("%s: Error, register write failed \r\n", __func__);
    goto enable_octal_mode_1_end;
  }

enable_octal_mode_1_end:
  return status;
}

/**********************************************************
 * Enables Octal Mode. Mode 2
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
static SPINOR_STATUS enable_octal_mode_2 (void)
{
  uint8 status_reg2 = 0;
  uint32 result=0;
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;

  /* This command has no data phase. Only write the command */
  status = spinor_util_write_register(ENABLE_8S_8S_8S_MODE_SEQ_CMD, 0, (uint8 *)&result, sizeof(result));
  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x50B);
    SPINOR_LOG_ERROR("%s: Error, register write failed \r\n", __func__);
    goto enable_octal_mode_2_end;
  }

enable_octal_mode_2_end:
  return status;
}

/**********************************************************
 * Enables Octal Mode. Mode 4
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
static SPINOR_STATUS enable_octal_mode_4 (void)
{
  uint32 cfg_reg2 = 0, result = 0;
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;

  /* Read/modify/write operation.*/
  /* Read Cfg 2 register */
  (void)spinor_util_read_reg_addr (READ_CFG2_CMD,0, 1, (uint8 *)&cfg_reg2,sizeof(cfg_reg2));
  if(((uint8)cfg_reg2 & (BIT_1|BIT_0)) == (p_spinor_dev->config_data->device_transfer_rate+1))
  {
    /* Octal Mode is already enabled */
    goto enable_octal_mode_4_end;
  }

  cfg_reg2 = ((uint8)cfg_reg2 & (~(BIT_1|BIT_0))) | (p_spinor_dev->config_data->device_transfer_rate+1);

  /* Write 1 byte of the mode to the cfg2 register */
  spinor_util_write_reg_addr (WRITE_CFG2_CMD, 0, 1, (uint8 *)&cfg_reg2, sizeof(cfg_reg2));
  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x50C);
    SPINOR_LOG_ERROR("%s: Error, register write failed \r\n", __func__);
    goto enable_octal_mode_4_end;
  }

enable_octal_mode_4_end:
  return status;
}

/**********************************************************
 * Enables Octal Mode. Mode 6
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
static SPINOR_STATUS enable_octal_mode_6 (void)
{
  uint32 cfg_reg = 0, result = 0;
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;

  status = spinor_util_read_reg_addr (READ_CFG_CMD, 0x00800006, 1, (uint8 *)&cfg_reg, sizeof(cfg_reg));

  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x50D);
    SPINOR_LOG_ERROR("%s: Error, register read failed \r\n", __func__);
    goto enable_octal_mode_6_end;
  }

  cfg_reg |=(p_spinor_dev->config_data->device_transfer_rate+1);

  status = spinor_util_write_reg_addr (WRITE_CFG_CMD, 0x00800006, 1, (uint8 *)&cfg_reg, sizeof(cfg_reg));

  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x50E);
    SPINOR_LOG_ERROR("%s: Error, register write failed \r\n", __func__);
    goto enable_octal_mode_6_end;
  }

enable_octal_mode_6_end:
  return status;
}
/**********************************************************
 * Enables Octal Mode. Mode 7
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
static SPINOR_STATUS enable_octal_mode_7 (void)
{
  uint32 cfg_reg = 0, result = 0;
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;

  /* Write 1 byte of the mode to the Volatile cfg register */
  if(p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_mode == SDR_8_8_8_MODE)
      cfg_reg = 0xB7;
  else
      cfg_reg = 0xE7;
  status = spinor_util_write_reg_addr (WRITE_VOLATILE_CFG_CMD, 0, 1, (uint8 *)&cfg_reg, sizeof(cfg_reg));

  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x50F);
    SPINOR_LOG_ERROR("%s: Error, register write failed \r\n", __func__);
    goto enable_octal_mode_7_end;
  }

enable_octal_mode_7_end:
  return status;
}

/******************************************************************************
 * Configures the number of dummy cycles for the various octal and quad modes
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 ******************************************************************************/
SPINOR_STATUS configure_dummy_cycles (boolean disable_data_dummy_cycle_recfg)
{
    uint32 cfg_reg2 = 0, dummy_val = 0xFF, shifted_val = 0, dummy_cycle = 0xFF;
    uint8 result = 0, clock_frequency = 0;
    uint32 dummy_cfg_cmd_wr = 0, dummy_cfg_cmd_rd = 0, addr = 0, dummy_cfg_bmsk = 0, dummy_shift = 0;
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    dummy_cfg_cmd_wr = p_spinor_dev->config_data->dummy_cycle_info.dummy_cycle_reg_wr_opcode;
    dummy_cfg_cmd_rd = p_spinor_dev->config_data->dummy_cycle_info.dummy_cycle_reg_rd_opcode;
    dummy_cfg_bmsk = p_spinor_dev->config_data->dummy_cycle_info.dummy_cycle_config_bmsk;
    dummy_shift = p_spinor_dev->config_data->dummy_cycle_info.dummy_config_shift;
    addr = p_spinor_dev->config_data->dummy_cycle_info.dummy_cycle_config_addr;
    uint32_t clk_freq_now = p_spinor_dev->config_data->freq_khz / 1000;

    /* Find the number of dummy cycles from the clock frequency
       {freq, 1-1-1 STR, 1-1-4 STR, 1-4-4 STR, 4-4-4 STR, 4-4-4 DTR, 1-1-8 STR, 1-8-8 STR, 8-8-8 STR, 8-8-8 DTR}
       0xFF DUMMY CYCLES = INVALID
    */
    int i = 0, j = 0;
    while(p_spinor_dev->config_data->dummy_cycle_info.dummy_clocks_freq_vs_number[i][j] != 0xFFFFFFFF)
    {
        if(clk_freq_now <= p_spinor_dev->config_data->dummy_cycle_info.dummy_clocks_freq_vs_number[i][j])
        {
            switch(p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_mode)
            {
                case SDR_1_1_1_MODE:
                    dummy_cycle = p_spinor_dev->config_data->dummy_cycle_info.dummy_clocks_freq_vs_number[i][j+1];
                    break;

                case SDR_1_1_4_MODE:
                    dummy_cycle = p_spinor_dev->config_data->dummy_cycle_info.dummy_clocks_freq_vs_number[i][j+2];
                    break;

                case SDR_1_4_4_MODE:
                    dummy_cycle = p_spinor_dev->config_data->dummy_cycle_info.dummy_clocks_freq_vs_number[i][j+3];
                    break;

                case SDR_4_4_4_MODE:
                    dummy_cycle = p_spinor_dev->config_data->dummy_cycle_info.dummy_clocks_freq_vs_number[i][j+4];
                    break;

                case DDR_4_4_4_MODE:
                    dummy_cycle = p_spinor_dev->config_data->dummy_cycle_info.dummy_clocks_freq_vs_number[i][j+5];
                    break;

                case SDR_1_1_8_MODE:
                    dummy_cycle = p_spinor_dev->config_data->dummy_cycle_info.dummy_clocks_freq_vs_number[i][j+6];
                    break;

                case SDR_1_8_8_MODE:
                    dummy_cycle = p_spinor_dev->config_data->dummy_cycle_info.dummy_clocks_freq_vs_number[i][j+7];
                    break;

                case SDR_8_8_8_MODE:
                    dummy_cycle = p_spinor_dev->config_data->dummy_cycle_info.dummy_clocks_freq_vs_number[i][j+8];
                    break;

                case DDR_8_8_8_MODE:
                    dummy_cycle = p_spinor_dev->config_data->dummy_cycle_info.dummy_clocks_freq_vs_number[i][j+9];
                    break;

                default:
                    dummy_cycle = 0;   /* OSPI Mode which has undefined dummy cycles */
                    break;
            }
            break;
        }
        i++;
    }
    if(dummy_cycle == 0xFF)
    {
        status = SPINOR_DEVICE_FAIL;
        goto configure_dummy_cycles_end;
    }

    /* Find the dummy cycle configuration value to be written from the number of dummy cycles */
    i = 0;
    j = 0;
    if(dummy_cycle == 0)
    {
        goto configure_dummy_cycles_end;
    }

    if(disable_data_dummy_cycle_recfg == FALSE)
    {

       while((p_spinor_dev->config_data->dummy_cycle_info.dummy_clocks_number_vs_regval[i][j] != dummy_cycle) && (p_spinor_dev->config_data->dummy_cycle_info.dummy_clocks_number_vs_regval[i][j] != 0xFF))
       {
           i++;
       }
       dummy_val = (uint8)p_spinor_dev->config_data->dummy_cycle_info.dummy_clocks_number_vs_regval[i][j+1];
       if(dummy_val == 0xFF)
       {
           SPINOR_LOG_ERROR("%s: Error, Invalid dummy val 0xFF \r\n", __func__);
           status = SPINOR_DEVICE_FAIL;
           goto configure_dummy_cycles_end;
       }

       status = spinor_util_read_reg_addr (dummy_cfg_cmd_rd, addr, 1, (uint8 *)&cfg_reg2, sizeof(cfg_reg2));
       if (status != SPINOR_DEVICE_DONE)
       {
           status = SPINOR_DEVICE_FAIL;
           spinor_log (&p_spinor_dev->debug_log, 0x510);
           SPINOR_LOG_ERROR("%s: Error, register read failed \r\n", __func__);
           goto configure_dummy_cycles_end;
       }

       cfg_reg2 &= (uint8)(~(dummy_cfg_bmsk));
       shifted_val = (uint8)(dummy_val << dummy_shift);
       cfg_reg2 |= (uint8)(shifted_val);

       /* Write dummy cycle config value to the required register */
       status = spinor_util_write_reg_addr (dummy_cfg_cmd_wr, addr, 1, (uint8 *)&cfg_reg2, sizeof(cfg_reg2));
       if (status != SPINOR_DEVICE_DONE)
       {
           status = SPINOR_DEVICE_FAIL;
           spinor_log (&p_spinor_dev->debug_log, 0x511);
           SPINOR_LOG_ERROR("%s: Error, register write failed \r\n", __func__);
           goto configure_dummy_cycles_end;
       }
    }
configure_dummy_cycles_end:
    p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].wait_state = dummy_cycle;
    SPINOR_LOG_WARNING("%s: Info, %d dummy cycles configured \r\n", __func__, dummy_cycle);

  return status;
}

/**********************************************************
 * Enables Quad Mode. Mode 1,4,5
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
static SPINOR_STATUS enable_quad_mode_1_4_5 (void)
{
  uint32 status_reg1 = 0, status_reg2 = 0;
  uint8 temp[4];
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;

  /* Read/modify/write operation.*/
  (void)spinor_util_read_register(READ_STATUS_CMD, 1, (uint8 *)&status_reg1,sizeof(status_reg1));
  (void)spinor_util_read_register(READ_CFG1_CMD, 1, (uint8 *)&status_reg2,sizeof(status_reg2));

  if ((uint8)status_reg2 & BIT_1)
  {
    /* Quad Mode is already enabled */
    goto enable_quad_mode_1_4_5_end;
  }

  /* Set Bit1 of status register2 to enable Quad mode (QER Bit) */
  /* Read/Modify/Write 2 bytes back */
  status_reg2 |= BIT_1;
  temp[0] = (uint8)status_reg1;
  temp[1] = (uint8)status_reg2;
  temp[2] = 0;
  temp[3] = 0;

  status = spinor_util_write_register(WRITE_STATUS_CMD, 2, (uint8 *)&temp[0], sizeof(temp));
  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x512);
    SPINOR_LOG_ERROR("%s: Error, register write failed \r\n", __func__);
    goto enable_quad_mode_1_4_5_end;
  }

enable_quad_mode_1_4_5_end:
  return status;
}

/**********************************************************
 * Enables Quad Mode. Mode 2
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
static SPINOR_STATUS enable_quad_mode_2 (void)
{
  uint32 status_reg = 0;
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;

  (void)spinor_util_read_register(READ_STATUS_CMD, 1,(uint8 *) &status_reg,sizeof(status_reg));

  /* In Mode 2, Bit6 of status register is used to enable Quad mode */
  if ((uint8)status_reg & BIT_6)
  {
    /* Quad Mode is already enabled */
    goto enable_quad_mode_2_end;
  }

  /* Set Bit6 of status register to enable Quad mode (QER Bit) */
  status_reg |= BIT_6;

  status = spinor_util_write_register(WRITE_STATUS_CMD, 1, (uint8 *)&status_reg,sizeof(status_reg));
  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x513);
    SPINOR_LOG_ERROR("%s: Error, register write failed \r\n", __func__);
    goto enable_quad_mode_2_end;
  }

enable_quad_mode_2_end:
  return status;
}

/**********************************************************
 * Enables Quad Mode for Mode 3
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
static SPINOR_STATUS enable_quad_mode_3 (void)
{
  uint8 temp = 0;
  uint32 status2_reg = 0;
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;

  /* Read 1 byte Status2 register with command 0x3F */
  (void)spinor_util_read_register(READ_STATUS_2_CMD, 1,(uint8 *) &status2_reg,sizeof(status2_reg));

  /* In Mode 3, Bit7 of Status2 register is used to enable Quad mode */
  if ((uint8)status2_reg & BIT_7)
  {
    /* Quad Mode is already enabled */
    goto enable_quad_mode_3_end;
  }

  /* Set Bit7 of Status2 to enable Quad mode (QER Bit) */
  status2_reg |= BIT_7;

  /* Read/Modify/Write Status2 Register */
  status = spinor_util_write_register(WRITE_STATUS_2_CMD, 1, (uint8 *)&status2_reg, sizeof(status2_reg));
  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x514);
    SPINOR_LOG_ERROR("%s: Error, register write failed \r\n", __func__);
    goto enable_quad_mode_3_end;
  }

enable_quad_mode_3_end:
  return status;
}

/**********************************************************
 * Enables QPI Mode for Mode 5
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
static SPINOR_STATUS enable_qpi_mode_5 (void)
{
  uint8 temp = 0;
  uint32 vol_enhan_cfg_reg = 0;
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;

  /* Read Volatile Enhanced Configuration Register using instruction 65h, no address is required */
  (void)spinor_util_read_register(READ_ENHANCED_VOL_CFG_CMD, 1, (uint8 *)&vol_enhan_cfg_reg,sizeof(vol_enhan_cfg_reg));

  /* Bit7 of Volatile Enhanced Configuration Register register is used to enable 4-4-4 mode (reset bit 7 to 0).*/
  if (!((uint8)vol_enhan_cfg_reg & BIT_7))
  {
    /* Quad Mode is already enabled */
    goto enable_qpi_mode_5_end;
  }

  /* reset bit 7 to 0 to enable 4-4-4 mode */
  vol_enhan_cfg_reg &= ~BIT_7;

  /* Enable STR/DTR mode based on the config */
  if (SPI_TRANSFER_DTR == p_spinor_dev->config_data->device_transfer_rate)
  {
      vol_enhan_cfg_reg &= ~BIT_5;
  }
  else
  {
      vol_enhan_cfg_reg |= BIT_5;
  }

  /* Write Volatile Enhanced Configuration Register using instruction 61h, no address is required */
  status = spinor_util_write_register(WRITE_ENHANCED_VOL_CFG_CMD, 1, (uint8 *)&vol_enhan_cfg_reg, sizeof(vol_enhan_cfg_reg));

  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x515);
    SPINOR_LOG_ERROR("%s: Error, register write failed \r\n", __func__);
    goto enable_qpi_mode_5_end;
  }

enable_qpi_mode_5_end:
  return status;
}

/**********************************************************
 * Enables QPI Mode for Mode 4
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
static SPINOR_STATUS enable_qpi_mode_4 (void)
{
    uint8 temp = 0;
    uint32 cfg_reg = 0;
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;

    spinor_util_read_reg_addr (READ_CFG_CMD,0x800003, 1, (uint8 *)&cfg_reg,sizeof(cfg_reg));

    /* Bit6 of Configuration Register is used to enable 4-4-4 mode (Set bit 6 to 1). */

    if ((uint8)cfg_reg & BIT_6)
    {
      /* 444 is already enabled */
      goto enable_qpi_mode_4_end;
    }

    /* Set bit 6 to 1 to enable 4-4-4 mode */
    cfg_reg |= BIT_6;

    /* write configuration using instruction 71h followed by address 800003h */
    status = spinor_util_write_reg_addr (WRITE_CFG_CMD,0x800003, 1, (uint8 *)&cfg_reg, sizeof(cfg_reg));
    if (status != SPINOR_DEVICE_DONE)
    {
      spinor_log (&p_spinor_dev->debug_log, 0x516);
      SPINOR_LOG_ERROR("%s: Error, register write failed \r\n", __func__);
      goto enable_qpi_mode_4_end;
    }

enable_qpi_mode_4_end:
    return status;
}

/**********************************************************
 * Enables QPI Mode for Mode 3
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
static SPINOR_STATUS enable_qpi_mode_3 (void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint8 temp = 0;
    spinor_OperationParamType xMemParams = (spinor_OperationParamType){.addr = 0, .buffer = &temp, .len = 0, .opcode=ISSUE_INSTR_35_CMD, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};

    /* This command has no data phase. Only write the command */
    status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_DEV_OP, &xMemParams);
    if (SPINOR_DEVICE_DONE != status)
    {
      spinor_log (&p_spinor_dev->debug_log, 0x517);
      SPINOR_LOG_ERROR("%s: Error, command transfer failed \r\n", __func__);
      goto enable_qpi_mode_3_end;
    }

enable_qpi_mode_3_end:
  return status;
}

/**********************************************************
 * Enables QPI Mode for Mode 2
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
static SPINOR_STATUS enable_qpi_mode_2 (void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint8 temp = 0;
    spinor_OperationParamType xMemParams = (spinor_OperationParamType){.addr = 0, .buffer = &temp, .len = 0, .opcode=ISSUE_INSTR_38_CMD, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};

    /* This command has no data phase. Only write the command */
    status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_DEV_OP, &xMemParams);
    if (SPINOR_DEVICE_DONE != status)
    {
      spinor_log (&p_spinor_dev->debug_log, 0x518);
      SPINOR_LOG_ERROR("%s: Error, command transfer failed \r\n", __func__);
      goto enable_qpi_mode_2_end;
    }

enable_qpi_mode_2_end:
  return status;

}

/**********************************************************
 * Enables QPI Mode for Mode 1
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
static SPINOR_STATUS enable_qpi_mode_1 (void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint8 temp = 0;
    SPI_COMMAND_TYPE command_mode = OSPI_DEVICE_OP_MODE;
    spinor_OperationParamType xMemParams = {.addr = 0, .buffer = &temp, .len = 0, .opcode=ISSUE_INSTR_38_CMD, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};

    /* set QE per QER bit */
    status = enable_qer_mode(p_spinor_dev->config_data->quad_enable_mode);
    if (status != SPINOR_DEVICE_DONE)
    {
      spinor_log (&p_spinor_dev->debug_log, 0x519);
      SPINOR_LOG_ERROR("%s: Error, enable QER mode failed \r\n", __func__);
      goto enable_qpi_mode_1_end;
    }

    /* Issue instruction 38h */
    /* This command has no data phase. Only write the command */
    status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_DEV_OP, &xMemParams);
    if (SPINOR_DEVICE_DONE != status)
    {
      spinor_log (&p_spinor_dev->debug_log, 0x51A);
      SPINOR_LOG_ERROR("%s: Error, command transfer failed \r\n", __func__);
      goto enable_qpi_mode_1_end;
    }

enable_qpi_mode_1_end:
  return status;

}

SPINOR_STATUS spinor_core_device_perf_config(void)
{
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;

  status = configure_dummy_cycles(p_spinor_dev->disable_data_dummy_cycle_recfg);
  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x51B);
    SPINOR_LOG_ERROR("%s: Error, configure dummy cycles failed \r\n", __func__);
    goto done;
  }

  if ((p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_mode != SDR_1_1_1_MODE) ||
      (p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].write_mode != SDR_1_1_1_MODE))
  {
    if ((p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_mode >= SDR_1_1_8_MODE) ||
        (p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].write_mode >= SDR_1_1_8_MODE))
    {
      status = enable_octal_mode();
      if (status != SPINOR_DEVICE_DONE)
      {
        spinor_log (&p_spinor_dev->debug_log, 0x51C);
        SPINOR_LOG_ERROR("%s: Error, enable octal mode failed \r\n", __func__);
        goto done;
      }
    }
    else
    {
      status = enable_quad_mode();
      if (status != SPINOR_DEVICE_DONE)
      {
        spinor_log (&p_spinor_dev->debug_log, 0x51D);
        SPINOR_LOG_ERROR("%s: Error, enable quad mode failed \r\n", __func__);
        goto done;
      }
    }
  }

  switch(p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_mode)
  {
    case SDR_1_1_1_MODE:
    DEBUG_LOG(SAIL_WARNING,"[SPINOR] Mode of Operation: SDR 1-1-1 \n\r");
    break;

    case SDR_1_1_4_MODE:
    DEBUG_LOG(SAIL_WARNING,"[SPINOR] Mode of Operation: SDR 1-1-4 \n\r");
    break;

    case SDR_1_4_4_MODE:
    DEBUG_LOG(SAIL_WARNING,"[SPINOR] Mode of Operation: SDR 1-4-4 \n\r");
    break;

    case SDR_4_4_4_MODE:
    DEBUG_LOG(SAIL_WARNING,"[SPINOR] Mode of Operation: SDR 4-4-4 \n\r");
    break;

    case DDR_1_1_4_MODE:
    DEBUG_LOG(SAIL_WARNING,"[SPINOR] Mode of Operation: DDR_1_1_4 \n\r");
    break;

    case DDR_1_4_4_MODE:
    DEBUG_LOG(SAIL_WARNING,"[SPINOR] Mode of Operation: DDR_1_4_4 \n\r");
    break;

    case DDR_4_4_4_MODE:
    DEBUG_LOG(SAIL_WARNING,"[SPINOR] Mode of Operation: DDR_4_4_4 \n\r");
    break;

    case SDR_1_1_8_MODE:
    DEBUG_LOG(SAIL_WARNING,"[SPINOR] Mode of Operation: SDR_1_1_8 \n\r");
    break;

    case SDR_1_8_8_MODE:
    DEBUG_LOG(SAIL_WARNING,"[SPINOR] Mode of Operation: SDR_1_8_8 \n\r");
    break;

    case SDR_8_8_8_MODE:
    DEBUG_LOG(SAIL_WARNING,"[SPINOR] Mode of Operation: SDR_8_8_8 \n\r");
    break;

    case DDR_1_1_8_MODE:
    DEBUG_LOG(SAIL_WARNING,"[SPINOR] Mode of Operation: DDR_1_1_8 \n\r");
    break;

    case DDR_1_8_8_MODE:
    DEBUG_LOG(SAIL_WARNING,"[SPINOR] Mode of Operation: DDR_1_8_8 \n\r");
    break;

    case DDR_8_8_8_MODE:
    DEBUG_LOG(SAIL_WARNING,"[SPINOR] Mode of Operation: DDR_8_8_8 \n\r");
    break;

    default:
      DEBUG_LOG(SAIL_WARNING,"[SPINOR] Mode of Operation: Unidentified mode \n\r");
      break;
    }

    DEBUG_LOG(SAIL_WARNING,"[SPINOR] Frequency of operation = %d MHz\n\r", p_spinor_dev->config_data->freq_khz/1000);
done:
  return status;
}
/**********************************************************
 * Sets 4-byte address mode
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_core_device_set_4byte_address_mode(void)
{
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;
  uint32 temp = 0;

  switch (p_spinor_dev->config_data->enter_4byte_mode)
  {
  case ADDR_4BYTE_MODE_6:
    /* SPI-NOR part supports dedicated 4-Byte address instruction set. */
  case ADDR_4BYTE_MODE_7:
    /* SPI-NOR part supports 4 byte address by default. */
    break;

  case ADDR_4BYTE_MODE_1:
    /* This command has no data phase. Only write the command */
    status = spinor_util_write_register(ENTER_4B_ADDR_CMD, 0, (uint8 *)&temp,sizeof(temp));
    if (status != SPINOR_DEVICE_DONE)
    {
      spinor_log (&p_spinor_dev->debug_log, 0x51E);
      SPINOR_LOG_ERROR("%s: Error, register write failed \r\n", __func__);
      goto set_4byte_address_mode_end;
    }
    break;

  //Extend this table to support other options to enter 4-byte mode

  default: /* More implementation & testing needed to support other modes. */
    status = SPINOR_DEVICE_FAIL;
    break;
  }

  if(status == SPINOR_DEVICE_DONE)
  {
      SPINOR_LOG_INFO("%s: Info, 4 byte address mode %d set \r\n", __func__, p_spinor_dev->config_data->enter_4byte_mode);
  }

set_4byte_address_mode_end:
  return status;
}
