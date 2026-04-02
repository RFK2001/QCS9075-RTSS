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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/src/driver/spinor_utils.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "spinor_utils.h"
#include "spinor_init_config.h"
#include "spinor_cm_defs.h"
#include "spinor_osal.h"
#include "spinor_job.h"
#include "spinor_core.h"
#include "spinor_sfdp.h"
#include "spinor_cmd.h"
#include "spinor_access.h"
#include "common_functions.h"
#include "debug_log.h"
#include "spinor_diag.h"

/**********************************************************
 * Logs error codes. Circular log buffer. The err_index can be used
 * as the index to the most recent error code
 *
 * @param spinor_err_log [IN]
 *   log buffer
 *
 * @param code [IN]
 *   Error code
 *
 **********************************************************/
void spinor_log (spinor_logs *spinor_err_log, uint16 code)
{
  if (spinor_err_log->spinor_err_index >= SPINOR_ERR_LOG_SIZE)
  {
    spinor_err_log->spinor_err_index = 0;
  }
  spinor_err_log->spinor_err_codes[spinor_err_log->spinor_err_index++] = code;
  return;
}

/**********************************************************
 * Validates the passed in client's handle
 *
 * @param parti_handle [IN]
 *   SPINOR interface handle to the partition
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_util_handle_validation(spinor_handle_t handle)
{
  if ((handle == NULL) || (handle != p_spinor_dev))
  {
    spinor_log (&p_spinor_dev->debug_log, 0xB01);
    SPINOR_LOG_ERROR("%s: Error, invalid handle \r\n", __func__);
    return SPINOR_DEVICE_FAIL;
  }
  return SPINOR_DEVICE_DONE;
}

/**********************************************************
 * Validates the input parameters for spinor Erase
 *
 * @param parti_handle [IN]
 *   SPINOR interface handle
 *
 * @param start_block [IN]
 *   Block offset from the start of the partition/image.
 *
 * @param block_count [IN]
 *   Number of blocks to perform the erase operations.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_util_erase_parameters_validation (uint8 *parti_handle,
                                                  uint32 start_block, uint32 block_count)
{
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;
  uint32 total_blocks = 0;

  status = spinor_util_handle_validation(parti_handle);
  if (status != SPINOR_DEVICE_DONE)
  {
    status = SPINOR_DEVICE_INVALID_PARAMETER;
    spinor_log (&p_spinor_dev->debug_log, 0xB02);
    SPINOR_LOG_ERROR("%s: Error, invalid handle \r\n", __func__);
    goto spinor_erase_parameters_validation_end;
  }

  if (block_count == 0)
  {
    status = SPINOR_DEVICE_INVALID_PARAMETER;
    spinor_log (&p_spinor_dev->debug_log, 0xB03);
    SPINOR_LOG_ERROR("%s: Error, block count is 0 \r\n", __func__);
    goto spinor_erase_parameters_validation_end;
  }

  total_blocks = p_spinor_dev->config_data->density_in_blocks;

  /* Boundary Check */
  if (INT_OVERFLOW (start_block, block_count) ||
      (start_block + block_count) > total_blocks)
  {
    status = SPINOR_DEVICE_INVALID_PARAMETER;
    spinor_log (&p_spinor_dev->debug_log, 0xB04);
    SPINOR_LOG_ERROR("%s: Error, invalid block params \r\n", __func__);
    goto spinor_erase_parameters_validation_end;
  }

  status = SPINOR_DEVICE_DONE;

spinor_erase_parameters_validation_end:
  return status;
}

/**********************************************************
 * Validates the Read/Write input parameters
 *
 * @param parti_handle [IN]
 *   SPINOR interface handle
 *
 * @param byte_offset [IN]
 *   Byte offset from the start of the partition/image.
 *
 * @param byte_count [IN]
 *   Number of bytes to perform the read/write operations.
 *
 * @buffer [IN]
 *   Data buffer for the read/write operation.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_util_rw_parameters_validation (uint8 *parti_handle,
               uint32 byte_offset, uint32 byte_count, const void *buffer)
{
  SPINOR_STATUS status = SPINOR_DEVICE_INVALID_PARAMETER;

  status = spinor_util_handle_validation(parti_handle);
  if (status != SPINOR_DEVICE_DONE)
  {
    status = SPINOR_DEVICE_INVALID_PARAMETER;
    spinor_log (&p_spinor_dev->debug_log, 0xB05);
    SPINOR_LOG_ERROR("%s: Error, invalid handle \r\n", __func__);
    goto spinor_rw_parameters_validation_end;
  }

  if ((buffer == NULL) || (byte_count == 0))
  {
    status = SPINOR_DEVICE_INVALID_PARAMETER;
    spinor_log (&p_spinor_dev->debug_log, 0xB06);
    SPINOR_LOG_ERROR("%s: Error, invalid buffer/byte_count \r\n", __func__);
    goto spinor_rw_parameters_validation_end;
  }

  /* Overflow and Boundary Checks */
  if (INT_OVERFLOW (byte_offset, byte_count) ||
      ((byte_offset + byte_count) > (p_spinor_dev->config_data->density_in_blocks * p_spinor_dev->config_data->block_size_in_bytes)))
  {
    status = SPINOR_DEVICE_INVALID_PARAMETER;
    spinor_log (&p_spinor_dev->debug_log, 0xB07);
    SPINOR_LOG_ERROR("%s: Error, boundary check fail \r\n", __func__);
    goto spinor_rw_parameters_validation_end;
  }

  if (p_spinor_dev->config_data->block_size_in_bytes == 0)
  {
    spinor_log (&p_spinor_dev->debug_log, 0xB08);
    SPINOR_LOG_ERROR("%s: Error, block size is 0 \r\n", __func__);
    goto spinor_rw_parameters_validation_end;
  }

  status = SPINOR_DEVICE_DONE;

spinor_rw_parameters_validation_end:
  return status;
}

SPINOR_STATUS spinor_util_check_sfdp_signature(void)
{
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;
  uint32_t signature;
  uint32 timeout = 0;
  uint32 status_polling_us = 0;

  /* Poll here on the SFDP Signature to make sure the flash device is ready and operating */
  status_polling_us = FLASH_INIT_POLLING_USEC;
  timeout = FLASH_INIT_TIMEOUT_USEC;

  while (timeout > 0)
  {
    signature = 0U;
    status = spinor_sfdp_read_signature(&signature);
    if (status == SPINOR_DEVICE_DONE && signature == SFDP_HEADER_SIGNATURE)
    {
      break;
    }

    /* delay between each status query */
    if(p_spinor_dev->disable_timeouts == 0)
    {
        spinor_udelay (status_polling_us);
        timeout -= (status_polling_us);
    }
  }

  if (signature != SFDP_HEADER_SIGNATURE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0xB09);
    SPINOR_LOG_ERROR("%s: Error, invalid SFDP signature read \r\n", __func__);
    status = SPINOR_DEVICE_FAIL;
    goto end;
  }

end:
  return status;
}


/**********************************************************
 * Erases given spinor blocks in bulk erase blocks size (32KB, 64KB, 512KB ect.
 * Sends SPI command to read register
 *
 * @reg_opcode [IN]
 *   Register Opcode
 *
 * @len [IN]
 *   How many bytes to read
 *
 * @reg_value [OUT]
 *   Register content returned
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_util_read_register (uint8 reg_opcode, uint8 len, uint8 *reg_value,uint8 max_buf_len)
{
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;
  SPI_COMMAND_TYPE command_mode = OSPI_REGISTER_READ;
  spinor_OperationParamType xMemParams = {.addr = 0, .buffer = reg_value, .len = len, .opcode=reg_opcode, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};

  if ((max_buf_len < len)|| (max_buf_len%4!=0))
  {
      spinor_log (&p_spinor_dev->debug_log, 0xB0A);
      SPINOR_LOG_ERROR("%s: Error, invalid max_buf_len %d \r\n", __func__, max_buf_len);
      return SPINOR_DEVICE_FAIL;
  }

  /* Command | data addr | data buffer | length | dma enable */
  status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_READ_REG, &xMemParams);
  if (SPINOR_DEVICE_DONE != status)
  {
      spinor_log (&p_spinor_dev->debug_log, 0xB0B);
      SPINOR_LOG_ERROR("%s: Error, SPINOR command transfer fail, status = 0x%x \r\n", __func__, status);
  }

  return status;
}
/**********************************************************
 * Sends SPI command to write register
 *
 * @reg_addr [IN]
 *   Register Opcode
 *
 * @len [IN]
 *   How many bytes to write
 *
 * @reg_value [OUT]
 *   Register Value
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_util_write_register (uint8 reg_opcode, uint8 len, uint8 *reg_value,uint8 max_buf_len)
{
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;
  uint8 qspi_status = 0;
  SPI_COMMAND_TYPE command_mode = OSPI_REGISTER_WRITE;
  spinor_OperationParamType xMemParams = {.addr = 0, .buffer = reg_value, .len = len, .opcode=reg_opcode, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};

  if ((max_buf_len < len)|| (max_buf_len%4!=0))
  {
    spinor_log (&p_spinor_dev->debug_log, 0xB0C);
    SPINOR_LOG_ERROR("%s: Error, invalid max_buf_len %d \r\n", __func__, max_buf_len);
    return SPINOR_DEVICE_FAIL;
  }

  status = spinor_util_write_enable (&qspi_status);
  if (status != SPINOR_DEVICE_DONE)
  {
    p_spinor_dev->debug_log.spinor_status = qspi_status;
    spinor_log (&p_spinor_dev->debug_log, 0xB0D);
    SPINOR_LOG_ERROR("%s: Error, Write enable fail \r\n", __func__);
    goto write_spi_end;
  }

  /* Command | data addr | data buffer | length | dma enable */
  status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_WRITE_REG, &xMemParams);
  if (SPINOR_DEVICE_DONE != status)
  {
    spinor_log (&p_spinor_dev->debug_log, 0xB0E);
    SPINOR_LOG_ERROR("%s: Error, SPINOR command transfer fail, status = 0x%x \r\n", __func__, status);
  }

write_spi_end:
  return status;
}

/**********************************************************
 * Read the spinor device ID
 *
 * @param device_id [IN/OUT]
 *   spinor Device ID
 *
 * @param device_id_len [IN]
 *   Number of bytes to read
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_util_read_device_id (void *device_id, uint8 device_id_len)
{
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;
  uint8 opcode;

  device_id_len = ((device_id_len%4) != 0)?((device_id_len/4)+1)*4:device_id_len;
  memset(device_id, 0, device_id_len);
  opcode = (p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_id_opcode == 0)?READ_ID_CMD:p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_id_opcode;
  status = spinor_util_read_register(opcode, device_id_len, (uint8 *)device_id,sizeof(uint32));
  return status;
}
/**********************************************************
 * Sends SPI command to read register address
 *
 * @reg_opcode [IN]
 *   Register Opcode
 *
 * @addr [IN]
 *   Address for the register
 *
 * @addr_bytes [IN]
 *
 *   How many bytes for the address
 * @len [IN]
 *   How many bytes to read
 *
 * @reg_value [OUT]
 *   Register content returned
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_util_read_reg_addr (uint8 reg_opcode,uint32 addr, uint8 len, uint8 *reg_value,uint8 max_buf_len)
{
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;
  SPI_COMMAND_TYPE command_mode = OSPI_REGISTER_READ_ADDR;
  spinor_OperationParamType xMemParams = {.addr = addr, .buffer = reg_value, .len = len, .opcode=reg_opcode, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};

  if ((max_buf_len<len) || (max_buf_len%4!=0))
  {
      spinor_log (&p_spinor_dev->debug_log, 0xB0F);
      SPINOR_LOG_ERROR("%s: Error, invalid max_buf_len %d \r\n", __func__, max_buf_len);
      return SPINOR_DEVICE_FAIL;
  }

  status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_READ_REG_ADDR, &xMemParams);
  if (SPINOR_DEVICE_DONE != status)
  {
      spinor_log (&p_spinor_dev->debug_log, 0xB10);
      SPINOR_LOG_ERROR("%s: Error, SPINOR command transfer fail, status = 0x%x \r\n", __func__, status);
  }

  return status;
}
/**********************************************************
 * Sends SPI command to write register address
 *
 * @reg_opcode [IN]
 *   Register Opcode
 *
 * @addr [IN]
 *   Address for the register
 *
 * @addr_bytes [IN]
 *   How many bytes for the address
 *
 * @len [IN]
 *   How many bytes to write
 *
 * @reg_value [OUT]
 *   Register Value
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_util_write_reg_addr (uint8 reg_opcode,uint32 addr, uint8 len, uint8 *reg_value, uint8 max_buf_len)
{
  SPINOR_STATUS status = SPINOR_DEVICE_DONE;
  uint8 qspi_status = 0;
  SPI_COMMAND_TYPE command_mode = OSPI_REGISTER_WRITE_ADDR;

  spinor_OperationParamType xMemParams = {.addr = addr, .buffer = reg_value, .len = len, .opcode=reg_opcode, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};

  if ((max_buf_len < len)|| (max_buf_len%4!=0))
  {
      spinor_log (&p_spinor_dev->debug_log, 0xB11);
      SPINOR_LOG_ERROR("%s: Error, invalid max_buf_len %d \r\n", __func__, max_buf_len);
      return SPINOR_DEVICE_FAIL;
  }

  status = spinor_util_write_enable (&qspi_status);
  if (status != SPINOR_DEVICE_DONE)
  {
      p_spinor_dev->debug_log.spinor_status = qspi_status;
      spinor_log (&p_spinor_dev->debug_log, 0xB12);
      SPINOR_LOG_ERROR("%s: Error, Write enable fail \r\n", __func__);
      goto write_spi_reg_addr_end;
  }

  /* Command | data addr | data buffer | length | dma enable */
  status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_WRITE_REG_ADDR, &xMemParams);
  if (SPINOR_DEVICE_DONE != status)
  {
      spinor_log (&p_spinor_dev->debug_log, 0xB13);
      SPINOR_LOG_ERROR("%s: Error, SPINOR command transfer fail, status = 0x%x \r\n", __func__, status);
  }

write_spi_reg_addr_end:
  return status;
}
/**********************************************************
 * Issues WRITE_ENABLE command to SPI NOR device
 *
 * @result [OUT]
 *   returns the Read Status Register content after WRITE_ENABLE
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_util_write_enable (uint8 *result)
{
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;
  uint32 timeout = 0;
  uint32 retval=0;
  SPI_COMMAND_TYPE command_mode = OSPI_DEVICE_OP_MODE;
  int len;
  uint8 temp = 0;
  spinor_OperationParamType xMemParams = {.addr = 0, .buffer =  &temp, .len = 0, .opcode=WRITE_ENABLE_CMD, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};

  if(p_spinor_dev->perfmode_enabled == FALSE)
      len = (p_spinor_dev->config_data->access_param[DEFAULT_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;
  else
      len = (p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;

  status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_DEV_OP, &xMemParams);
  if (SPINOR_DEVICE_DONE != status)
  {
    spinor_log (&p_spinor_dev->debug_log, 0xB14);
    SPINOR_LOG_ERROR("%s: Error, SPINOR command transfer fail, status = 0x%x \r\n", __func__, status);
    goto spinor_write_enable_end;
  }

  status = SPINOR_DEVICE_FAIL;

  timeout = p_spinor_dev->read_status_timeout;
  while (timeout > 0)
  {
    /* Read 1 byte Status register. command 0x5 */
    status = spinor_util_read_register(READ_STATUS_CMD, len, (uint8 *)&retval,sizeof(retval));
    if ((status == SPINOR_DEVICE_DONE) && ((uint8)retval & STATUS_WR_EN_MASK))
    {
      break;
    }
    
    if(p_spinor_dev->disable_timeouts == 0)
    {
        spinor_udelay(p_spinor_dev->status_polling_usec);
        timeout -= p_spinor_dev->status_polling_usec;
    }
  }

  if ((status != SPINOR_DEVICE_DONE) || (STATUS_WR_EN_MASK !=((uint8)retval & STATUS_WR_EN_MASK)) )
  {
     *result = (uint8)retval;
     status = SPINOR_DEVICE_FAIL;
     spinor_log (&p_spinor_dev->debug_log, 0xB15);
  }

spinor_write_enable_end:
  return status;
}
/**********************************************************
 * Performs a software reset
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_util_device_software_reset(void)
{
    uint8 temp = 0;
    SPI_COMMAND_TYPE command_mode = OSPI_DEVICE_OP_MODE;
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    spinor_OperationParamType xMemParams = {.addr = 0, .buffer = &temp, .len = 0, .opcode=RESET_ENABLE_CMD, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};

    if(p_spinor_dev->nor_init_done == SPINOR_INIT_NOT_DONE)
    {
        status = SPINOR_DEVICE_DONE;
        SPINOR_LOG_INFO("%s: Info, SPINOR init not done, hence no sw reset is needed for the device \r\n", __func__);
        goto software_reset_end;
    }

    if(p_spinor_dev->nor_init_done == SPINOR_INIT_FAIL)
    {
        status = SPINOR_DEVICE_FAIL;
        spinor_log (&p_spinor_dev->debug_log, 0xB16);
        SPINOR_LOG_ERROR("%s: Error, SPINOR init failed \r\n", __func__);
        goto software_reset_end;
    }

    status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_DEV_OP, &xMemParams);
    if (SPINOR_DEVICE_DONE != status)
    {
        spinor_log (&p_spinor_dev->debug_log, 0xB17);
        SPINOR_LOG_ERROR("%s: Error, SPINOR command transfer 1 fail, status = 0x%x \r\n", __func__, status);
        goto software_reset_end;
    }

    spinor_ndelay(40); /* Delay of tSHSL:
                        From Read to next Read = 10 nanoseconds
                        From Write/Erase/Program to Read Status Register = 40 nanoseconds */

    xMemParams = (spinor_OperationParamType){.addr = 0, .buffer = &temp, .len = 0, .opcode=RESET_CMD, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
    status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_DEV_OP, &xMemParams);
    if (SPINOR_DEVICE_DONE != status)
    {
        spinor_log (&p_spinor_dev->debug_log, 0xB18);
        SPINOR_LOG_ERROR("%s: Error, SPINOR command transfer 2 fail, status = 0x%x \r\n", __func__, status);
        goto software_reset_end;
    }

    spinor_udelay(90); /* Reset recovery time on standby = 90 microseconds (to accommodate different card's reset recovery time) */

    p_spinor_dev->sw_reset_done = TRUE;

software_reset_end:
return status;
}

/**********************************************************
 * Enters the Deep power down mode
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_util_enter_deep_power_down(void)
{
    uint8 temp = 0;
    SPI_COMMAND_TYPE command_mode = OSPI_DEVICE_OP_MODE;
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;

    if ((0x195A34 == p_spinor_dev->config_data->device_id) || (0x195B34 == p_spinor_dev->config_data->device_id))
    {
        goto enter_deep_power_down_end;
    }

    spinor_OperationParamType xMemParams = {.addr = 0, .buffer = &temp, .len = 0, .opcode=ENTER_DPD, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};

    status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_DEV_OP, &xMemParams);
    if (SPINOR_DEVICE_DONE != status)
    {
        spinor_log (&p_spinor_dev->debug_log, 0xB19);
        SPINOR_LOG_ERROR("%s: Error, SPINOR command transfer fail, status = 0x%x \r\n", __func__, status);
        goto enter_deep_power_down_end;
    }

    spinor_udelay(10); /* Delay of tDP = 10 microseconds */

enter_deep_power_down_end:
return status;
}

/**********************************************************
 * Exits the Deep power down mode
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_util_exit_deep_power_down(void)
{
    uint8 temp = 0;
    SPI_COMMAND_TYPE command_mode = OSPI_DEVICE_OP_MODE;
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;

    if ((0x195A34 == p_spinor_dev->config_data->device_id) || (0x195B34 == p_spinor_dev->config_data->device_id))
    {
        goto exit_deep_power_down_end;
    }

    spinor_OperationParamType xMemParams = {.addr = 0, .buffer = &temp, .len = 0, .opcode=EXIT_DPD, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};

    status = spinor_jobDispatcherSyncWrapper(SPINOR_JOB_OP_DEV_OP, &xMemParams);
    if (SPINOR_DEVICE_DONE != status)
    {
        spinor_log (&p_spinor_dev->debug_log, 0xB1A);
        SPINOR_LOG_ERROR("%s: Error, SPINOR command transfer fail, status = 0x%x \r\n", __func__, status);
        goto exit_deep_power_down_end;
    }

    spinor_udelay(30); /*Delay of tRES1 = 30 microseconds */

exit_deep_power_down_end:
return status;
}
/**********************************************************
 * Checks Status of the operation by reading the Status register
 *
 * @result [OUT]
 *   Status Register Value
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_util_check_operation_status (uint8 *result)
{
  int32 timeout = 0;
  uint32 retval=0;
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;
  int len;

  if(p_spinor_dev->perfmode_enabled == FALSE)
      len = (p_spinor_dev->config_data->access_param[DEFAULT_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;
  else
      len = (p_spinor_dev->config_data->access_param[PERF_MODE_ACCESS_PARAM].read_mode == DDR_8_8_8_MODE)? 2:1;

  timeout = p_spinor_dev->read_status_timeout;
  while (timeout > 0)
  {
    /* Read 1 byte Status register */
    (void)spinor_util_read_register(READ_STATUS_CMD, len, (uint8 *)&retval,sizeof(retval));
    if (!((uint8)retval & READ_STATUS_BUSY_MASK))
    {
      *result = (uint8)retval;
      status = SPINOR_DEVICE_DONE;
      goto spinor_util_check_operation_status_end;
    }
    
    if(p_spinor_dev->disable_timeouts == 0)
    {
        timeout -= p_spinor_dev->status_polling_usec;
        spinor_udelay(p_spinor_dev->status_polling_usec);
    }
  }

  *result = (uint8)retval;

  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0xB1B);
    SPINOR_LOG_ERROR("%s: Error, spinor_util_check_operation_status fail \r\n", __func__);
  }

spinor_util_check_operation_status_end:
  return status;
}

/**********************************************************
 * Checks the number of 4k blocks for 1 block of that region
 *
 * @param addr [IN]
 *   Address for the SPINOR erase
 *
 * @result spinor_getnum4kblockType [OUT]
 *   The number of 4k blocks and the block's sector index
 *
 **********************************************************/
SPINOR_STATUS spinor_util_getnum4kblock(uint32_t addr, spinor_getnum4kblockType *block_info)
{
    SPINOR_STATUS status = SPINOR_DEVICE_FAIL;

    if(block_info == NULL)
    {
        status = SPINOR_DEVICE_INVALID_PARAMETER;
        goto spinor_util_getnum4kblock_end;
    }

    for (int idx = 0; idx < sizeof(p_spinor_dev->config_data->secmapdata) / sizeof(p_spinor_dev->config_data->secmapdata[0]); idx++)
    {
        if ( (addr >= p_spinor_dev->config_data->secmapdata[idx].start_range) && (addr <= p_spinor_dev->config_data->secmapdata[idx].end_range))
        {
          block_info->block_num = p_spinor_dev->config_data->secmapdata[idx].er_size_KB/4;
          block_info->idx = idx;
          status = SPINOR_DEVICE_DONE;
          goto spinor_util_getnum4kblock_end;
        }
    }

spinor_util_getnum4kblock_end:
    return status;
}
