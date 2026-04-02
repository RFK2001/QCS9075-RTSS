#ifndef __SPINOR_UTILS_H__
#define __SPINOR_UTILS_H__
/*
===========================================================================
*/
/**
    @file  spinor_utils.h
    @brief This file provides definitions for the spinor support functions

*/
/*
    ===========================================================================

    Copyright (c) 2017-2024 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/inc/driver/spinor_utils.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "spinor_api.h"
#include "spinor_core.h"

/* Check for integer overflows */
#define INT_OVERFLOW(x,y) (x + y < x)

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
void spinor_log (spinor_logs *spinor_err_log, uint16 code);

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
SPINOR_STATUS spinor_util_handle_validation(spinor_handle_t handle);

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
                uint32 start_block, uint32 block_count);

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
                uint32 byte_offset, uint32 byte_count, const void *buffer);

SPINOR_STATUS spinor_util_check_sfdp_signature(void);

/**********************************************************
 * Read the Flash device ID
 *
 * @param device_id [IN/OUT]
 *   Flash NOR Device ID
 *
 * @param device_id_len [IN]
 *   Number of bytes to read
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_util_read_device_id (void *device_id, uint8 device_id_len);

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
SPINOR_STATUS spinor_util_read_register (uint8 reg_opcode, uint8 len, uint8 *reg_value,uint8 max_buf_len);

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
 * @max_buf_len [IN]
 *   Maximum length of the buffer
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_util_write_register (uint8 reg_opcode, uint8 len, uint8 *reg_value,uint8 max_buf_len);
/**********************************************************
 * Sends SPI command to read register address
 *
 * @reg_opcode [IN]
 *   Register Opcode
 *
 * @addr [IN]
 *   Address for the register
 *
 * @len [IN]
 *   How many bytes to read
 *
 * @reg_value [OUT]
 *   Register content returned
 *
 * @max_buf_len [IN]
 *   Maximum length of the buffer
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_util_read_reg_addr (uint8 reg_opcode,uint32 addr, uint8 len, uint8 *reg_value, uint8 max_buf_len);
/**********************************************************
 * Sends SPI command to write register address
 *
 * @reg_opcode [IN]
 *   Register Opcode
 *
 * @addr [IN]
 *   Address for the register
 *
 * @len [IN]
 *   How many bytes to write
 *
 * @reg_value [OUT]
 *   Register Value
 *
 * @max_buf_len [IN]
 *   Maximum length of the buffer
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_util_write_reg_addr (uint8 reg_opcode,uint32 addr, uint8 len, uint8 *reg_value, uint8 max_buf_len);
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
SPINOR_STATUS spinor_util_write_enable (uint8 *result);
/**********************************************************
 * Performs a software reset
 *
 * @return int [OUT]
 *   Result of the operation.
 **********************************************************/
SPINOR_STATUS spinor_util_device_software_reset(void);
/**********************************************************
 * Enter deep power down mode.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
**********************************************************/
SPINOR_STATUS spinor_util_enter_deep_power_down(void);
/**********************************************************
 * Exit deep power down mode.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
**********************************************************/
SPINOR_STATUS spinor_util_exit_deep_power_down(void);

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
SPINOR_STATUS spinor_util_check_operation_status (uint8 *result);

/**********************************************************
 * Checks the number of 4k blocks for 1 block of that region
 *
 * @addr [IN]
 *   Address for the erase
 *
 * @block_info [IN/OUT]
 *   Struct for the block info
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_util_getnum4kblock(uint32_t addr, spinor_getnum4kblockType *block_info);

#endif /* __SPINOR_UTILS__H__ */
