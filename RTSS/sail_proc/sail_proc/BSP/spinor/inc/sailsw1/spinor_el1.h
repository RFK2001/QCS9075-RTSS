#ifndef __SPINOR_EL1_H__
#define __SPINOR_EL1_H__

/*
===========================================================================
*/
/**
    @file  spinor_el1.h
    @brief SPI NOR EL1 framework structure defines.

*/
/*
    ===========================================================================

    Copyright (c) 2022-2024 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/inc/sailsw1/spinor_el1.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "types.h"
#include "spinor_el1_api.h"
#include "spinor_trap_defs.h"

/**********************************************************
 * Initialize OSPI EL1 driver
 *
 * @param type [IN]
 *   None
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el1Init(void);

/**********************************************************
 * De-initialize OSPI EL1 driver
 *
 * @param none
 *
 * @return void [OUT]
 *
 **********************************************************/
SPINOR_STATUS el1DeInit( void );

/**********************************************************
 * Opens handle to a access to the spinor device
 *
 *
 * @param type [IN/OUT]
 *   Pointer to SPINOR service interface handle as an input parameter.
 *   Pointer to internal spinor_clients reference count upon return
 *
 * @param eUserType [IN]
 *   SPINOR User type
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el1Open( spinor_handle_t *handle, eSpinorUserType eUserType);

/**********************************************************
 * Closes handle to a spinor service.
 * Clients should close the handle when accesses to
 * the device is no longer needed.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el1Close( spinor_handle_t handle);

/**********************************************************
 * Query GPT partition information to spinor framework.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @param guid [IN]
 *   NULL terminated GPT partition GUID string.
 *
 * @param pulStartAddr [IN/OUT]
 *   GPT partition start address.
 *
 * @param pulSize [IN/OUT]
 *   GPT partition size.
 *
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
SPINOR_STATUS el1GetGptPartitionInfo( spinor_handle_t handle, const char *guid, uint32_t *pulStartAddr, uint32_t *pulSize);

/**********************************************************
 * Update the Partition Attribute.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @param guid [IN]
 *   NULL terminated GPT partition GUID string.
 *
 * @param eAttrib [IN]
 *   Protection type to update for the region.
 *
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
SPINOR_FUNC SPINOR_STATUS el1SetPartitionAttrib( spinor_handle_t handle, const char *guid,  eSpinorProtectType eAttrib );

/**********************************************************
 * Get the attribute for the Partition.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @param guid [IN]
 *   NULL terminated GPT partition GUID string.
 *
 * @param eAttrib [IN/OUT]
 *   Pointer to address that contains Protection type for the region.
 *
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
SPINOR_FUNC SPINOR_STATUS el1GetPartitionAttrib( spinor_handle_t handle, const char *guid,  eSpinorProtectType* eAttrib );

/**********************************************************
 * Get the Sector map information.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @param pSecMapInfo [IN/OUT]
 *   Pointer to the address that will store the sector map information.
 *
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
SPINOR_FUNC SPINOR_STATUS el1GetSectorMapInfo( spinor_handle_t handle, spinorSectorMapInfoType *pSecMapInfo );

/**********************************************************
 * Erases given spinor blocks
 *
 * @param handle [IN]
 *   SPINOR service interface handle
 *
 * @param start_block [IN]
 *   A starting block for a number of blocks to erase.
 *
 * @param block_count [IN]
 *   Number of blocks to erase
 *
 * @param eraseCallback[IN]
 *   Spinor callback function
 *
 * @param userdata[IN/OUT]
 *   Returs user data via callback function
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el1Erase( spinor_handle_t handle, uint32 start_block, uint32 block_count, spinorEl1CallbackType eraseCallback, spinorEl1userdata *userdata);

/**********************************************************
 * Writes data to the spinor.
 *
 * @param handle [IN]
 *   SPINOR service interface handle
 *
 * @param byte_offset [IN]
 *   Byte offset from the start of the region to write to.
 *
 * @param byte_count [IN]
 *   Number of bytes to write data.
 *
 * @param buffer [IN]
 *   Data buffer for spinor write operation.
 *
 * @param writeCallback[IN]
 *   Spinor callback function
 *
 * @param userdata[IN/OUT]
 *   Returs user data via callback function
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el1Write( spinor_handle_t handle, uint32 byte_offset, uint32 byte_count, const void *buffer, spinorEl1CallbackType writeCallback, spinorEl1userdata *userdata);

/**********************************************************
 * Allows read data from the spinor
 *
 * @param handle [IN]
 *   SPINOR service interface handle
 *
 * @param byte_offset [IN]
 *   Byte offset from the start of region to read from.
 *
 * @param byte_count [IN]
 *   Number of bytes to read data.
 *
 * @param buffer [OUT]
 *   Data buffer for a spinor read operation.
 *
 * @param readCallback[IN]
 *   Spinor callback function
 *
 * @param userdata[IN/OUT]
 *   Returs user data via callback function
 *
 * @return int [OUT]
 *   Result of the operation.
 **********************************************************/
SPINOR_STATUS el1Read ( spinor_handle_t handle, uint32 byte_offset, uint32 byte_count, void *buffer, spinorEl1CallbackType readCallback, spinorEl1userdata *userdata);

/**********************************************************
 * Vote low power to spinor framework.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @param bLowPower [IN]
 *   Vote to allow low power
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el1LowPower ( spinor_handle_t handle, boolean bLowPower);

/**********************************************************
 * Get memory info from spinor EL2.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @param pmemInfo [OUT]
 *   Pointer to the structure that contains the memory info derived.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el1GetMemInfo(spinor_handle_t handle, spinorMemInfoType *pmemInfo);

/**********************************************************
 * Reads from DLP partition to check if the SPINOR device is alive
 *
 * @param none
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el1IsDeviceAlive( void );

/**********************************************************
 * Dumps the SFDP table
 *
 * @param none
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el1DumpSFDP(void);

/**********************************************************
 * Resets the handles upon SW reset
 *
 * @param resetCoreID [IN]
 *   Core ID that got reset.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_FUNC SPINOR_STATUS el1SWResetClose(uint32 resetCoreID);

/**********************************************************
 * Acquire the lock to the SPIBUS
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el1AquireLock(spinor_handle_t handle);

/**********************************************************
 * Release the lock to the SPIBUS
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el1ReleaseLock(spinor_handle_t handle);

/**********************************************************
 * Sends Raw SPI commands to the Flash device synchronously
 *
 * @param handle [IN]
 *   SPINOR service interface handle
 *
 * @param bincmdParams [IN]
 *   Pointer to hold Binary Command Parameters.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 * @dependencies - The SPIBus needs to be acquired before
 *                 sending the command sequences and should be
 *                 released after the sequences are completed.
 *                 The operation is only allowed for EL1 Super users
 **********************************************************/
SPINOR_STATUS el1Bincmd( spinor_handle_t handle, spinorBincmdParams_t *bincmdParams);
#endif /* __SPINOR_EL1_H__ */
