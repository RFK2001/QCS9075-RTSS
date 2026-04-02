/*
===========================================================================
*/
/**
    @file  spinor_api.c
    @brief Implementation of spinor driver API

*/
/*
    ===========================================================================

    Copyright (c) 2017-2025 Qualcomm Technologies, Inc.
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

#include "spinor_api.h"
#include "spinor_core.h"
#include "spinor_job.h"
#include "spinor_cmd.h"
#include "spinor_utils.h"
#include "spinor_osal.h"
#include "spinor_init_config.h"
#include "spinor_diag.h"
#include "spinor_pvl_api.h"
#include "common_functions.h"

//#define SPINOR_TEST_SRC_ENABLED

static spinor_drv_info spinor_dev_mm;
static spinor_drv_info spinor_dev_crash_dbg;
spinor_drv_info *p_spinor_dev = NULL;
static boolean crash_dump_flag;
static SPINOR_STATUS spinor_jobstatus = SPINOR_DEVICE_DONE;
/**********************************************************
 * Initalizes the spinor controller and device
 *
 *
 * @param type [IN]
 *   Initialization type to know the environment
 *                  - default initialization type, used in boot time init
 *                  - RAM dump initialization type, used in SDI module to re-init the SPI NOR driver for RAM dump
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_init (spinor_init_type_t type, spinor_hardcode_data_mode *hardcoded_data_mode)
{
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;

  if ( SPINOR_INIT_TYPE_RAM_DUMP == type )
  {
    crash_dump_flag = TRUE;
    p_spinor_dev = &spinor_dev_crash_dbg;
    memset(p_spinor_dev, 0, sizeof(spinor_drv_info));
  }
  else
  {
    p_spinor_dev = &spinor_dev_mm;
  }
  if ( p_spinor_dev->nor_init_done <= SPINOR_INIT_SLEEP_DONE || p_spinor_dev->sw_reset_done == TRUE )
  {
    spinor_init_config_table_type *spinor_config;
    spinor_config = spinor_get_config_table_struct();
    status = spinor_core_init(type, (void *)spinor_config, hardcoded_data_mode);
  }
  return status;
}

/**********************************************************
 * Returns the device specific info.
 * \n
 *
 * @param handle [IN]
 *   SPINOR interface handle
 *
 * @param spinor_info [OUT]
 *   Pointer to the client's spinor device info data.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 ***********************************************************/
SPINOR_STATUS spinor_get_info(spinor_handle_t handle,
                              struct spinor_info *spinor_info)
{
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;

  if (p_spinor_dev->nor_init_done != SPINOR_INIT_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x100);
    SPINOR_LOG_ERROR("%s: Error, Initalization not done \r\n", __func__);
    status = SPINOR_DEVICE_FAIL;
    goto spinor_get_info_end;
  }

  memset(spinor_info, 0, sizeof( struct spinor_info));

  spinor_info->device_id = p_spinor_dev->config_data->device_id;
  spinor_info->block_count = p_spinor_dev->config_data->density_in_blocks;
  spinor_info->pages_per_block = p_spinor_dev->config_data->pages_per_block;
  spinor_info->page_size_bytes = p_spinor_dev->config_data->page_size_in_bytes;

  status = SPINOR_DEVICE_DONE;

spinor_get_info_end:
  return status;
}

 /**********************************************************
 * Get the Sector map information.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @param pSecMapInfo [IN]
 *   Pointer to the address that will store the sector map information.
 *
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_get_sector_map_info(spinor_handle_t handle, spinorSectorMapInfoType *secMapInfo)
{
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;

  if ( handle == NULL  || secMapInfo == NULL)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x101);
    SPINOR_LOG_ERROR("%s: Error, Invalid parameters \r\n", __func__);
    status = SPINOR_DEVICE_INVALID_PARAMETER;
    goto spinor_get_sector_map_info_end;
  }

  if (p_spinor_dev->nor_init_done != SPINOR_INIT_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x102);
    SPINOR_LOG_ERROR("%s: Error, Initalization not done \r\n", __func__);
    status = SPINOR_DEVICE_FAIL;
    goto spinor_get_sector_map_info_end;
  }

  memset(secMapInfo, 0, sizeof(spinorSectorMapInfoType));
  sailbsp_memscpy(secMapInfo, sizeof(spinorSectorMapInfoType), p_spinor_dev->config_data->secmapdata, sizeof(spinorSectorMapInfoType));

  status = SPINOR_DEVICE_DONE;

spinor_get_sector_map_info_end:
  return status;
}

static SPINOR_STATUS spinor_power_on (void)
{
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;

  if (p_spinor_dev->nor_init_done != SPINOR_INIT_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x103);
    SPINOR_LOG_ERROR("%s: Error, Initalization not done \r\n", __func__);
    goto spinor_power_on_end;
  }

  if (p_spinor_dev->ref_count == UINT8_MAX)
  {
    status = SPINOR_DEVICE_FAIL;
    spinor_log (&p_spinor_dev->debug_log, 0x104);
    SPINOR_LOG_ERROR("%s: Error, Reference count has reached maximum \r\n", __func__);
    goto spinor_power_on_end;
  }

  p_spinor_dev->ref_count++;
  status = SPINOR_DEVICE_DONE;

spinor_power_on_end:
  return status;
}


static SPINOR_STATUS spinor_power_off (void)
{
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;

  if (p_spinor_dev->nor_init_done != SPINOR_INIT_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x105);
    SPINOR_LOG_ERROR("%s: Error, Initalization not done \r\n", __func__);
    goto spinor_power_off_end;
  }

  if (p_spinor_dev->ref_count == 0)
  {
    status = SPINOR_DEVICE_FAIL;
    spinor_log (&p_spinor_dev->debug_log, 0x106);
    SPINOR_LOG_ERROR("%s: Error, Reference count is zero \r\n", __func__);
    goto spinor_power_off_end;
  }
  else if (p_spinor_dev->ref_count == 1)
  {
    ;
  }

  p_spinor_dev->ref_count--;
  status = SPINOR_DEVICE_DONE;

spinor_power_off_end:
  return status;
}


/**********************************************************
 * Opens handle to a access to the spinor device
 *
 *
 * @param handle [IN/OUT]
 *   Pointer to SPINOR interface handle as an input parameter.
 *   Pointer to internal spinor_clients refernce count upon return
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_open (spinor_handle_t *handle)
{
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;

  if ( handle == NULL )
  {
    spinor_log (&p_spinor_dev->debug_log, 0x107);
    SPINOR_LOG_ERROR("%s: Error, Handle is NULL \r\n", __func__);
    goto spinor_open_end;
  }
  else if (NULL == p_spinor_dev || p_spinor_dev->nor_init_done != SPINOR_INIT_DONE)
  {
    status = spinor_init( SPINOR_INIT_TYPE_DEFAULT, NULL);
    if (status != SPINOR_DEVICE_DONE)
    {
      spinor_log (&p_spinor_dev->debug_log, 0x108);
      SPINOR_LOG_ERROR("%s: Error, Initalization failure \r\n", __func__);
      goto spinor_open_end;
    }
  }

  status = spinor_power_on();
  if (SPINOR_DEVICE_DONE != status)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x109);
    SPINOR_LOG_ERROR("%s: Error, Power on failure \r\n", __func__);
    goto spinor_open_end;
  }

  *handle = (spinor_handle_t)p_spinor_dev;
  status = SPINOR_DEVICE_DONE;

spinor_open_end:
  return status;
}

/**********************************************************
 * Closes handle to a spinor device.
 * Clients should close the handle when accesses to
 * the device is no longer needed.
 *
 * @param handle [IN]
 *   SPINOR interface handle.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_close (spinor_handle_t handle)
{
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;

  if (p_spinor_dev->nor_init_done != SPINOR_INIT_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x10A);
    SPINOR_LOG_ERROR("%s: Error, Initalization not done \r\n", __func__);
    goto spinor_close_end;
  }

  status = spinor_util_handle_validation (handle);
  if (status != SPINOR_DEVICE_DONE)
  {
    status = SPINOR_DEVICE_INVALID_PARAMETER;
    spinor_log (&p_spinor_dev->debug_log, 0x10B);
    SPINOR_LOG_ERROR("%s: Error, Invalid handle \r\n", __func__);
    goto spinor_close_end;
  }

  status = spinor_power_off();
  if (SPINOR_DEVICE_DONE != status)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x10C);
    SPINOR_LOG_ERROR("%s: Error, Power off failure \r\n", __func__);
    goto spinor_close_end;
  }

  status = SPINOR_DEVICE_DONE;

spinor_close_end:
  return status;
}

/**********************************************************
 * Allows read data from the spinor synchronous operation
 *
 * @param handle [IN]
 *   SPINOR interface handle
 *
 * @param byte_offset [IN]
 *   Byte offset from the start of region to read from.
 *
 * @param byte_count [IN]
 *   Number of bytes to read data.
 *
 * @buffer [OUT]
 *   Data buffer for a spinor read operation.
 *
 * @return int [OUT]
 *   Result of the operation.
 **********************************************************/
SPINOR_STATUS spinor_read(spinor_handle_t handle, uint32 byte_offset,
                          uint32 byte_count, void *buffer)
{
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;

  /* Get the status for the spinor Job */
  status = spinor_read_async( handle, byte_offset, byte_count, buffer);

  while (SPINOR_DEVICE_OK_NOT_DONE == status)
  {
      spinor_mainFunction();
      status = spinor_getJobResult();
  }

  if (SPINOR_DEVICE_DONE != status)
  {
      spinor_log (&p_spinor_dev->debug_log, 0x10D);
      SPINOR_LOG_ERROR("%s: Error, Read transaction failure at address 0x%x and size 0x%x, status = 0x%x \r\n", __func__, byte_offset, byte_count, status);
  }

spinor_read_end:
  return status;
}

/**********************************************************
 * Allows read data from the spinor asynchronous operation
 *
 * @param handle [IN]
 *   SPINOR interface handle
 *
 * @param byte_offset [IN]
 *   Byte offset from the start of region to read from.
 *
 * @param byte_count [IN]
 *   Number of bytes to read data.
 *
 * @buffer [OUT]
 *   Data buffer for a spinor read operation.
 *
 * @return int [OUT]
 *   Result of the operation.
 **********************************************************/
SPINOR_STATUS spinor_read_async(spinor_handle_t handle, uint32 byte_offset,
                          uint32 byte_count, void *buffer)
{
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;
  spinor_OperationParamType xMemParams;

  if (p_spinor_dev->nor_init_done != SPINOR_INIT_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x10E);
    SPINOR_LOG_ERROR("%s: Error, Initalization not done \r\n", __func__);
    goto spinor_read_end;
  }

  /* validate passed in paramerters */
  status = spinor_util_rw_parameters_validation (handle,
                                            byte_offset, byte_count, buffer);
  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x10F);
    SPINOR_LOG_ERROR("%s: Error, Invalid read parameters \r\n", __func__);
    goto spinor_read_end;
  }

#ifdef SPINOR_PROFILE_ENABLED
  p_spinor_dev->profiling_time.spinor_core_read_time = 0;
#endif /* SPINOR_PROFILE_ENABLED */

  xMemParams = (spinor_OperationParamType) {.addr = byte_offset, .buffer = buffer, .len = byte_count, .opcode = 0, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};

  status = spinor_jobDispatcher(SPINOR_JOB_MODE_ASYNC, SPINOR_JOB_OP_READ_MEM, &xMemParams);
  if (SPINOR_DEVICE_OK_NOT_DONE != status)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x110);
    SPINOR_LOG_ERROR("%s: Error, Read transaction failure at address 0x%x and size 0x%x, status = 0x%x \r\n", __func__, byte_offset, byte_count, status);
    return SPINOR_DEVICE_FAIL;
  }

  /* Update the current job status from Mem job Operation status */
  status = spinor_jobstatus = spinor_jobGetOperationStatus();

spinor_read_end:
  return status;
}

/**********************************************************
 * Writes data to the spinor synchronous operation.
 *
 * @param handle [IN]
 *   SPINOR interface handle
 *
 * @param byte_offset [IN]
 *   Byte offset from the start of the region to write to.
 *
 * @param byte_count [IN]
 *   Number of bytes to write data.
 *
 * @buffer [IN]
 *   Data buffer for spinor write operation.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_write (spinor_handle_t handle, uint32 byte_offset,
                            uint32 byte_count, const void *buffer)
{
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;

  /* Get the status for the spinor Job */
  status = spinor_write_async (handle, byte_offset, byte_count, buffer);

  while (SPINOR_DEVICE_OK_NOT_DONE == status)
  {
      spinor_mainFunction();
      status = spinor_getJobResult();
  }

  if (SPINOR_DEVICE_DONE != status)
  {
      spinor_log (&p_spinor_dev->debug_log, 0x111);
      SPINOR_LOG_ERROR("%s: Error, Write transaction failure at address 0x%x and size 0x%x, status = 0x%x \r\n", __func__, byte_offset, byte_count, status);
  }

spinor_write_end:
  return status;
}

/**********************************************************
 * Writes data to the spinor asynchronous operation.
 *
 * @param handle [IN]
 *   SPINOR interface handle
 *
 * @param byte_offset [IN]
 *   Byte offset from the start of the region to write to.
 *
 * @param byte_count [IN]
 *   Number of bytes to write data.
 *
 * @buffer [IN]
 *   Data buffer for spinor write operation.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_write_async (spinor_handle_t handle, uint32 byte_offset,
                            uint32 byte_count, const void *buffer)
{
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;
  uint32 transfer_start_addr = 0;
  uint32 parti_start_block = 0;

  spinor_OperationParamType xMemParams;

  if (p_spinor_dev->nor_init_done != SPINOR_INIT_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x112);
    SPINOR_LOG_ERROR("%s: Error, Initalization not done \r\n", __func__);
    goto spinor_write_end;
  }

  /* validate passed in paramerters */
  status = spinor_util_rw_parameters_validation (handle, byte_offset,
                                            byte_count, buffer);
  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x113);
    SPINOR_LOG_ERROR("%s: Error, Invalid write parameters \r\n", __func__);
    goto spinor_write_end;
  }

  transfer_start_addr = parti_start_block + byte_offset;

#ifdef SPINOR_PROFILE_ENABLED
  p_spinor_dev->profiling_time.spinor_core_write_time = 0;
#endif /* SPINOR_PROFILE_ENABLED */

  xMemParams = (spinor_OperationParamType){.addr = transfer_start_addr, .buffer = (void *)buffer, .len = byte_count, .opcode=0, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};

  status = spinor_jobDispatcher(SPINOR_JOB_MODE_ASYNC, SPINOR_JOB_OP_WRITE_MEM, &xMemParams);
  if (SPINOR_DEVICE_OK_NOT_DONE != status)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x115);
    SPINOR_LOG_ERROR("%s: Error, Write transaction failed at address 0x%x and size 0x%x, status = 0x%x \r\n", __func__, byte_offset, byte_count, status);
    return SPINOR_DEVICE_FAIL;
  }

  /* Update the current job status from Mem job Operation status */
  status = spinor_jobstatus = spinor_jobGetOperationStatus();

spinor_write_end:
  return status;
}

/**********************************************************
 * Performs the SPI Binary command asynchronously
 *
 * @param handle [IN]
 *   SPINOR service interface handle
 *
 * @param cmdParam [IN]
 *   Pointer to the Binary Command Params
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_bincmd_async (spinor_handle_t handle, void *cmdParam)
{
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;
  spinor_OperationParamType xMemParams;
  spinor_OperationParamType *bincmdParam = (spinor_OperationParamType *)cmdParam;

  if (p_spinor_dev->nor_init_done != SPINOR_INIT_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x116);
    SPINOR_LOG_ERROR("%s: Error, Initalization not done \r\n", __func__);
    goto spinor_bincmd_end;
  }

  status = spinor_util_handle_validation(handle);
  if (status != SPINOR_DEVICE_DONE)
  {
    status = SPINOR_DEVICE_INVALID_PARAMETER;
    spinor_log (&p_spinor_dev->debug_log, 0x117);
    SPINOR_LOG_ERROR("%s: Error, invalid handle \r\n", __func__);
    goto spinor_bincmd_end;
  }

  xMemParams = (spinor_OperationParamType) {.addr = bincmdParam->addr, .buffer = bincmdParam->buffer, .len = bincmdParam->len,
                                            .opcode = bincmdParam->opcode, .dummy_cycle = bincmdParam->dummy_cycle,
                                            .num_addr_bytes = bincmdParam->num_addr_bytes, .is_write_operation = bincmdParam->is_write_operation,
                                            .use_dma = bincmdParam->use_dma
                                            };

  status = spinor_jobDispatcher(SPINOR_JOB_MODE_ASYNC, SPINOR_JOB_OP_BINARY_CMD, &xMemParams);
  if (SPINOR_DEVICE_OK_NOT_DONE != status)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x118);
    SPINOR_LOG_ERROR("%s: Error, Bin Cmd transaction failed, status = 0x%x \r\n", __func__, status);
    return SPINOR_DEVICE_FAIL;
  }

  /* Update the current job status from Mem job Operation status */
  status = spinor_jobstatus = spinor_jobGetOperationStatus();

spinor_bincmd_end:
  return status;
}

/**********************************************************
 * Erases given spinor blocks synchronous operation
 *
 * @param handle [IN]
 *   SPINOR interface handle
 *
 * @param start_block [IN]
 *   A starting block for a number of blocks to erase.
 *
 * @param block_count [IN]
 *   Number of blocks to erase
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_erase (spinor_handle_t handle,
                            uint32 start_block, uint32 block_count)
{
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;

  /* Get the status for the spinor Job */
  status = spinor_erase_async (handle, start_block, block_count);

  while (SPINOR_DEVICE_OK_NOT_DONE == status)
  {
      spinor_mainFunction();
      status = spinor_getJobResult();
  }

  if (SPINOR_DEVICE_DONE != status)
  {
      spinor_log (&p_spinor_dev->debug_log, 0x119);
      SPINOR_LOG_ERROR("%s: Error, Erase transaction failed at start block 0x%x and 0x%x blocks, status = 0x%x \r\n", __func__, start_block, block_count, status);
  }

spinor_erase_end:
  return status;
}

/**********************************************************
 * Erases given spinor blocks Asynchronous operation
 *
 * @param handle [IN]
 *   SPINOR interface handle
 *
 * @param start_block [IN]
 *   A starting block for a number of blocks to erase.
 *
 * @param block_count [IN]
 *   Number of blocks to erase
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_erase_async (spinor_handle_t handle,
                            uint32 start_block, uint32 block_count)
{
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;
  spinor_OperationParamType xMemParams;

  if (p_spinor_dev->nor_init_done != SPINOR_INIT_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x11A);
    SPINOR_LOG_ERROR("%s: Error, Initalization not done \r\n", __func__);
    goto spinor_erase_end;
  }

  status = spinor_util_erase_parameters_validation(handle,
                                              start_block, block_count);
  if (status != SPINOR_DEVICE_DONE)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x11B);
    SPINOR_LOG_ERROR("%s: Error, Invalid erase parameters \r\n", __func__);
    goto spinor_erase_end;
  }

#ifdef SPINOR_PROFILE_ENABLED
  p_spinor_dev->profiling_time.spinor_core_erase_time = 0;
#endif /* SPINOR_PROFILE_ENABLED */


  xMemParams = (spinor_OperationParamType){.addr = start_block*p_spinor_dev->config_data->block_size_in_bytes, .buffer = 0, .len = block_count, .opcode=0, .dummy_cycle = 0, .num_addr_bytes = 0, .is_write_operation = FALSE, .use_dma = FALSE};
  status = spinor_jobDispatcher(SPINOR_JOB_MODE_ASYNC, SPINOR_JOB_OP_ERASE_MEM, &xMemParams);
  if (SPINOR_DEVICE_OK_NOT_DONE != status)
  {
    spinor_log (&p_spinor_dev->debug_log, 0x11D);
    SPINOR_LOG_ERROR("%s: Error, Erase transaction failed at start block 0x%x and 0x%x blocks, status = 0x%x \r\n", __func__, start_block, block_count, status);
    SPINOR_DEVICE_FAIL;
  }

  /* Update the current job status from Mem job Operation status */
  status = spinor_jobstatus = spinor_jobGetOperationStatus();

spinor_erase_end:
  return status;
}

/**********************************************************
 * Main function loop to run the SPINOR Operation.
 *
 * @param void [IN]
 *
 * @return void [OUT]
 *
 **********************************************************/
void spinor_mainFunction(void)
{
    spinor_jobRunOperation();
    spinor_jobstatus = spinor_jobGetOperationStatus();
}

/**********************************************************
 * Gets the current status of the SPINOR Operation.
 *
 * @param void [IN]
 *
 * @return int [OUT]
 *   Status of the SPINOR Operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_getJobResult(void)
{
    return spinor_jobstatus;
}

/**********************************************************
 * Enters the Deep power down mode
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_enter_deep_power_down()
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    
    if (p_spinor_dev->nor_init_done != SPINOR_INIT_DONE)
    {
        spinor_log (&p_spinor_dev->debug_log, 0x11E);
        SPINOR_LOG_ERROR("%s: Error, Initalization not done \r\n", __func__);
        status = SPINOR_DEVICE_FAIL;
        goto spinor_enter_deep_power_down_end;
    }
    
    status = spinor_util_enter_deep_power_down();
    SPINOR_LOG_VERBOSE("%s: Info, SPINOR deep power down mode entered \r\n", __func__);

spinor_enter_deep_power_down_end:
    return status;
}

/**********************************************************
 * Exits the Deep power down mode
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_exit_deep_power_down()
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    
    if (p_spinor_dev->nor_init_done != SPINOR_INIT_DONE)
    {
        spinor_log (&p_spinor_dev->debug_log, 0x11F);
        SPINOR_LOG_ERROR("%s: Error, Initalization not done \r\n", __func__);
        status = SPINOR_DEVICE_FAIL;
        goto spinor_exit_deep_power_down_end;
    }
    
    status = spinor_util_exit_deep_power_down();
    SPINOR_LOG_VERBOSE("%s: Info, SPINOR deep power down mode exited \r\n", __func__);

spinor_exit_deep_power_down_end:
    return status;
}

/**********************************************************
 * Enables the ECC Checks for operations
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_enable_ecc_check(void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    
    if (p_spinor_dev->nor_init_done != SPINOR_INIT_DONE)
    {
        spinor_log (&p_spinor_dev->debug_log, 0x120);
        SPINOR_LOG_ERROR("%s: Error, Initalization not done \r\n", __func__);
        status = SPINOR_DEVICE_FAIL;
        goto spinor_enable_ecc_check_end;
    }
    
#ifdef SPINOR_ECC_ENABLE
    status = spinor_core_enable_ecc_check();
#endif /* SPINOR_ECC_ENABLE */

spinor_enable_ecc_check_end:
    return status;
}

/**********************************************************
 * Disables the ECC Checks for operations
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_disable_ecc_check(void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    
    if (p_spinor_dev->nor_init_done != SPINOR_INIT_DONE)
    {
        spinor_log (&p_spinor_dev->debug_log, 0x121);
        SPINOR_LOG_ERROR("%s: Error, Initalization not done \r\n", __func__);
        status = SPINOR_DEVICE_FAIL;
        goto spinor_disable_ecc_check_end;
    }
    
#ifdef SPINOR_ECC_ENABLE
    status = spinor_core_disable_ecc_check();
#endif /* SPINOR_ECC_ENABLE */

spinor_disable_ecc_check_end:
    return status;
}

/**********************************************************
 * Enables the CRC Checks for operations
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_enable_crc_check(void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    
    if (p_spinor_dev->nor_init_done != SPINOR_INIT_DONE)
    {
        spinor_log (&p_spinor_dev->debug_log, 0x122);
        SPINOR_LOG_ERROR("%s: Error, Initalization not done \r\n", __func__);
        status = SPINOR_DEVICE_FAIL;
        goto spinor_enable_crc_check_end;
    }
    
#ifdef SPINOR_CRC_ENABLE
    status = spinor_core_enable_crc_check();
#endif /* SPINOR_CRC_ENABLE */

spinor_enable_crc_check_end:
    return status;
}

/**********************************************************
 * Disables the CRC Checks for operations
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_disable_crc_check(void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    
    if (p_spinor_dev->nor_init_done != SPINOR_INIT_DONE)
    {
        spinor_log (&p_spinor_dev->debug_log, 0x123);
        SPINOR_LOG_ERROR("%s: Error, Initalization not done \r\n", __func__);
        status = SPINOR_DEVICE_FAIL;
        goto spinor_disable_crc_check_end;
    }
    
#ifdef SPINOR_CRC_ENABLE
    status = spinor_core_disable_crc_check();
#endif /* SPINOR_CRC_ENABLE */

spinor_disable_crc_check_end:
    return status;
}

#ifdef SPINOR_TEST_SRC_ENABLED
/**********************************************************
 * Reads the SFDP Signature
 *
 * @signature [OUT]
 *   Stores the sfdp signature read.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_read_sfdp_signature(uint32 *signature)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    
    if (p_spinor_dev->nor_init_done != SPINOR_INIT_DONE)
    {
        spinor_log (&p_spinor_dev->debug_log, 0x124);
        SPINOR_LOG_ERROR("%s: Error, Initalization not done \r\n", __func__);
        status = SPINOR_DEVICE_FAIL;
        goto spinor_read_sfdp_signature_end;
    }
    
    status = spinor_core_read_sfdp_signature(signature);

spinor_read_sfdp_signature_end:
    return status;
}

#ifdef SPINOR_ECC_ENABLE
/**********************************************************
 * Clears the ECC registers
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_clear_ECC_registers(void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    
    if (p_spinor_dev->nor_init_done != SPINOR_INIT_DONE)
    {
        spinor_log (&p_spinor_dev->debug_log, 0x125);
        SPINOR_LOG_ERROR("%s: Error, Initalization not done \r\n", __func__);
        status = SPINOR_DEVICE_FAIL;
        goto spinor_clear_ECC_registers_end;
    }
    
    status = spinor_core_clear_ECC_regs();

spinor_clear_ECC_registers_end:
    return status;
}

/**********************************************************
 * Checks the ECC status
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_check_ECC_status(void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    
    if (p_spinor_dev->nor_init_done != SPINOR_INIT_DONE)
    {
        spinor_log (&p_spinor_dev->debug_log, 0x126);
        SPINOR_LOG_ERROR("%s: Error, Initalization not done \r\n", __func__);
        status = SPINOR_DEVICE_FAIL;
        goto spinor_check_ECC_status_end;
    }
    
    status = spinor_core_check_ECC_Status();

spinor_check_ECC_status_end:
    return status;
}
#endif /* SPINOR_ECC_ENABLE */

/**********************************************************
 * Performs a SW reset of the Spinor driver
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_software_reset(void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    
    if (p_spinor_dev->nor_init_done != SPINOR_INIT_DONE)
    {
        spinor_log (&p_spinor_dev->debug_log, 0x127);
        SPINOR_LOG_ERROR("%s: Error, Initalization not done \r\n", __func__);
        status = SPINOR_DEVICE_FAIL;
        goto spinor_software_reset_end;
    }
    
    status = spinor_core_shutdown(crash_dump_flag);

spinor_software_reset_end:
    return status;
}

#ifdef SPINOR_CRC_ENABLE
/**********************************************************
 * Clears the CRC registers
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_clear_CRC_registers(void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    
    if (p_spinor_dev->nor_init_done != SPINOR_INIT_DONE)
    {
        spinor_log (&p_spinor_dev->debug_log, 0x128);
        SPINOR_LOG_ERROR("%s: Error, Initalization not done \r\n", __func__);
        status = SPINOR_DEVICE_FAIL;
        goto spinor_clear_CRC_registers_end;
    }
    
    status = spinor_core_clear_CRC_regs();

spinor_clear_CRC_registers_end:
    return status;
}

/**********************************************************
 * Checks the CRC status
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_check_CRC_status(void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    
    if (p_spinor_dev->nor_init_done != SPINOR_INIT_DONE)
    {
        spinor_log (&p_spinor_dev->debug_log, 0x129);
        SPINOR_LOG_ERROR("%s: Error, Initalization not done \r\n", __func__);
        status = SPINOR_DEVICE_FAIL;
        goto spinor_check_CRC_status_end;
    }
    
    status = spinor_core_check_CRC_Status();

spinor_check_CRC_status_end:
    return status;
}
#endif /* SPINOR_CRC_ENABLE */
#endif /* SPINOR_TEST_SRC_ENABLED */

/**********************************************************
 * Switch SPINOR mux configuration to MD.
 *
 * @param handle [IN]
 *   SPINOR interface handle
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_switch_mux_config (void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_FAIL;

    status = spinor_core_reconfig_mux();

    return status;
}

/**********************************************************
 * Reads from DLP partition to check if the SPINOR device is alive
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_is_device_alive(void)
{
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;

  if (p_spinor_dev == NULL || p_spinor_dev->nor_init_done != SPINOR_INIT_DONE)
  {
    status = SPINOR_DEVICE_FAIL;
    spinor_log (&p_spinor_dev->debug_log, 0x12B);
    SPINOR_LOG_ERROR("%s: Error, Initalization not done \r\n", __func__);
    goto spinor_is_device_alive_end;
  }

  status = spinor_core_is_device_alive();

spinor_is_device_alive_end:
  return status;
}

/**********************************************************
 * Dumps the SPINOR SFDP info
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_sfdp_dump(void)
{
  SPINOR_STATUS status = SPINOR_DEVICE_FAIL;

  if (p_spinor_dev == NULL || p_spinor_dev->nor_init_done != SPINOR_INIT_DONE)
  {
    status = SPINOR_DEVICE_FAIL;
    spinor_log (&p_spinor_dev->debug_log, 0x12C);
    SPINOR_LOG_ERROR("%s: Error, Initalization not done \r\n", __func__);
    goto spinor_sfdp_dump;
  }

  status = spinor_pvl_sfdp_dump();

spinor_sfdp_dump:
  return status;
}

#ifdef SPINOR_PROFILE_ENABLED
/**********************************************************
 * Performs the SPINOR profiling
 *
 * @spinor_current_timings [IN]
 *   current timing values.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_obtain_profiling_time(uint64 *read_time_tests, uint64 *write_time_tests, uint64 *erase_time_tests)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;

    if(p_spinor_dev->profiling_time.spinor_core_read_time == NULL ||
       p_spinor_dev->profiling_time.spinor_core_write_time == NULL ||
       p_spinor_dev->profiling_time.spinor_core_erase_time == NULL)
    {
      status = SPINOR_DEVICE_FAIL;
      goto spinor_obtain_profiling_time_end;

    }

    *read_time_tests = p_spinor_dev->profiling_time.spinor_core_read_time;
    *write_time_tests = p_spinor_dev->profiling_time.spinor_core_write_time;
    *erase_time_tests = p_spinor_dev->profiling_time.spinor_core_erase_time;

spinor_obtain_profiling_time_end:
    return status;
}
#endif

#ifdef NORPVL_ENB
SPINOR_STATUS spinor_change_params(uint32 thread_delay_us, uint32_t max_tranfr_pg_size)
{
    SPINOR_STATUS status = SPINOR_DEVICE_FAIL;
    status = spinor_core_change_params(thread_delay_us, max_tranfr_pg_size);
    return status;
}
#endif