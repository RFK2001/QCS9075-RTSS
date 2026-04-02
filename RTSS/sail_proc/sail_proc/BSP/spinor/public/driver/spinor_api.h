#ifndef __SPINOR_API_H__
#define __SPINOR_API_H__

/*
===========================================================================
*/
/**
    @file  spinor_api.h
    @brief Public interface declaration for the Spinor Drivers.
           This file describes the spinor external interface.

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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/public/driver/spinor_api.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

/**  \mainpage spinor Functional Overview
 *
 * The spinor driver provides a high-level interface for clients, such
 * as bootloaders, file systems, and tools to interact with the spinor devices. It
 * handles the spinor device specifics and abstracts with the client from the device-
 * specific algorithms, interfaces, and OS adaptations.
 *
 * \n
 *
 */

/**
* Error codes are 16 bit values, where the first 8 bit(starting from MSB) corresponds to the file name
* and the last 8 bits represent the error code within the file specified by the first byte of the error codes.
*
* Filename				     Error code
* Spinor_api.c			     0x1
* Spinor_core.c			     0x2
* Spinor_utils.c		     0x3
* Spinor_sfdp.c	             0x4
* Spinor_qspial.c            0x5
****/

#include "spinor_cm_defs.h"

//#define SPINOR_PROFILE_ENABLED /* Enable the macro to perform profiling for SPINOR driver */

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
SPINOR_STATUS spinor_init (spinor_init_type_t type, spinor_hardcode_data_mode *hardcoded_data_mode);

/**********************************************************
 * DeInitalizes the spinor controller and device
 *
 *
 * @param void [IN]
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_deinit (void);

/**********************************************************
 * De-initializes the controller
 *
 * @param void [IN]
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_controller_deinit(void);

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
SPINOR_STATUS spinor_open( spinor_handle_t *handle);


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
  struct spinor_info *spinor_info);
  
/**********************************************************
 * Get the Sector map information.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @param secMapInfo [IN/OUT]
 *   Pointer to the address that will store the sector map information.
 *
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_get_sector_map_info(spinor_handle_t handle, spinorSectorMapInfoType *secMapInfo);

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
SPINOR_STATUS spinor_close(spinor_handle_t handle);

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
SPINOR_STATUS spinor_erase(spinor_handle_t handle,
  uint32 start_block, uint32 block_count);

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
                            uint32 start_block, uint32 block_count);

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
SPINOR_STATUS spinor_write(spinor_handle_t handle,
  uint32 byte_offset, uint32 byte_count, const void *buffer);

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
                            uint32 byte_count, const void *buffer);

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
SPINOR_STATUS spinor_read(spinor_handle_t handle,
  uint32 byte_offset, uint32 byte_count, void *buffer);

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
                          uint32 byte_count, void *buffer);

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
SPINOR_STATUS spinor_bincmd_async (spinor_handle_t handle, void *cmdParam);

/**********************************************************
 * Main function loop to run the SPINOR Operation.
 *
 * @param void [IN]
 *
 * @return void [OUT]
 *
 **********************************************************/
void spinor_mainFunction(void);

/**********************************************************
 * Gets the current status of the SPINOR Operation.
 *
 * @param void [IN]
 *
 * @return int [OUT]
 *   Status of the SPINOR Operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_getJobResult(void);

/**********************************************************
 * Enters the deep power down mode
 *
 * @return int [OUT]
 *   Result of the operation.
 **********************************************************/
SPINOR_STATUS spinor_enter_deep_power_down(void);

/**********************************************************
 * Exits the deep power down mode
 *
 * @return int [OUT]
 *   Result of the operation.
 **********************************************************/
SPINOR_STATUS spinor_exit_deep_power_down(void);

/**********************************************************
 * Enables the ECC Checks for operations
 *
 * @return int [OUT]
 *   Result of the operation.
 **********************************************************/
SPINOR_STATUS spinor_enable_ecc_check(void);

/**********************************************************
 * Disables the ECC Checks for operations
 *
 * @return int [OUT]
 *   Result of the operation.
 **********************************************************/
SPINOR_STATUS spinor_disable_ecc_check(void);

/**********************************************************
 * Enables the CRC Checks for operations
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_enable_crc_check(void);

/**********************************************************
 * Disables the CRC Checks for operations
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_disable_crc_check(void);

/**********************************************************
 * Reads the SFDP Signature
 *
 * @signature [OUT]
 *   Signature Value read
 *
 * @return int [OUT]
 *   Result of the operation.
 **********************************************************/
SPINOR_STATUS spinor_read_sfdp_signature(uint32 *signature);

/**********************************************************
 * Clears the ECC registers
 *
 * @return int [OUT]
 *   Result of the operation.
 **********************************************************/
SPINOR_STATUS spinor_clear_ECC_registers(void);

/**********************************************************
 * Checks the ECC status
 *
 * @return int [OUT]
 *   Result of the operation.
 **********************************************************/
SPINOR_STATUS spinor_check_ECC_status(void);

/**********************************************************
 * Performs a software reset
 *
 * @return int [OUT]
 *   Result of the operation.
 **********************************************************/
SPINOR_STATUS spinor_software_reset(void);

/**********************************************************
 * Clears the CRC registers
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_clear_CRC_registers(void);

/**********************************************************
 * Checks the CRC status
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_check_CRC_status(void);

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
SPINOR_STATUS spinor_switch_mux_config (void);

/**********************************************************
 * Reads from DLP partition to check if the SPINOR device is alive
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_is_device_alive(void);

/**********************************************************
 * Dumps the SPINOR SFDP tables
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinor_sfdp_dump(void);

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
SPINOR_STATUS spinor_obtain_profiling_time(uint64 *read_time_tests, uint64 *write_time_tests, uint64 *erase_time_tests);
#endif /* SPINOR_PROFILE_ENABLED */

#endif /* __SPINOR_API_H__ */
