#ifndef __SPINOR_EL2_H__
#define __SPINOR_EL2_H__

/*
===========================================================================
*/
/**
    @file  spinor_el2.h
    @brief SPI NOR EL2 framework structure defines.

*/
/*
    ===========================================================================

    Copyright (c) 2021-2024 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/inc/sailhyp/spinor_el2.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

/**  \mainpage SGI IPC Functional Overview
 *
 * The SGI IPC module provides the one directional IPC communication from EL2(source) to EL1(destination).
 * It is assumed that the SGI source module is initialized before initializing before the destination
 * module starts its initialization.
 * The SGI IPC destination is assumed to execute in a thread context.
 *
 * \n
 *
 */

#include "types.h"
#include "spinor_el2_api.h"

/**********************************************************
 * Checks if the OSPI EL2 driver is intialized for the initalization requested
 *
 * @param type [IN]
 *   Type of initialization
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean spinorEl2IsInitDone(int type);

/**********************************************************
 * Initialize OSPI EL2 driver
 *
 * @param type [IN]
 *   Type of initialization
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
int el2Init( int type, uint8_t *puWorkBuf, uint32_t ulBufLen, spinor_hardcode_data_mode *hardcoded_data_mode );

/**********************************************************
 * Initialize the ReadBuffer Region for EL1 clients
 *
 * @param ulAddr [IN]
 *   Start address of the Region
 *
 * @param ulSize [IN]
 *   Size of the Region
 *
 * @return int [OUT]
 *   Result of the operation.
 **********************************************************/
SPINOR_STATUS el2InitReadBufRegion(uint32_t ulAddr, uint32_t ulSize);

/**********************************************************
 * De-initialize OSPI EL2 driver
 *
 * @param none
 *
 * @return void [OUT]
 *
 **********************************************************/
void el2DeInit( void );

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
 * @param pwd [IN/OUT]
 *   Pointer to hold the password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2Open( spinor_handle_t *handle, eSpinorUserType eUserType, uint32_t *pwd);

/**********************************************************
 * Closes handle to a spinor service.
 * Clients should close the handle when accesses to
 * the device is no longer needed.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @param pwd [IN/OUT]
 *   Pointer holding the current password for the client as input parameter
 *   Password cleared on success of the operation else returned as it is
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2Close( spinor_handle_t handle, uint32_t *pwd);

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
 * @param pwd [IN/OUT]
 *   Pointer holding the current password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2GetGptPartitionInfo( spinor_handle_t handle, const char *guid, uint32_t *pulStartAddr, uint32_t *pulSize, uint32_t *pwd);

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
 * @param pwd [IN/OUT]
 *   Pointer holding the current password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2SetPartitionAttrib( spinor_handle_t handle, const char *guid, eSpinorProtectType eAttrib, uint32_t *pwd);

/**********************************************************
 * Get the attribute for the Partition.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @param guid [IN]
 *   NULL terminated GPT partition GUID string.
 *
 * @param eAttrib [IN]
 *   Pointer to address that contains Protection type for the region.
 *
 * @param pwd [IN/OUT]
 *   Pointer holding the current password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2GetPartitionAttrib( spinor_handle_t handle, const char *guid, eSpinorProtectType* eAttrib, uint32_t *pwd);

/**********************************************************
 * Main function loop to run EL2 Operations.
 *
 * @param void [IN]
 *
 * @return void [OUT]
 *
 **********************************************************/
SPINOR_STATUS el2Mainfunction(spinor_handle_t handle, boolean bTrap, uint32_t *pwd);

/**********************************************************
 * Gets the current status of the EL2 Operation.
 *
 * @param void [IN]
 *
 * @return int [OUT]
 *   Status of the Operation.
 *
 **********************************************************/
SPINOR_STATUS el2GetJobResult(spinor_handle_t handle, boolean bTrap, uint32_t *pwd);

/**********************************************************
 * Performs the SPI Binary command
 *
 * @param handle [IN]
 *   SPINOR service interface handle
 *
 * @param bTrap [IN]
 *
 * @param bincmdParams [IN]
 *   Pointer to the Binary Command Params
 *
 * @param pwd [IN/OUT]
 *   Pointer holding the current password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2Bincmd( spinor_handle_t handle, boolean bTrap, void* bincmdParams, uint32_t *pwd);

/**********************************************************
 * Erases given spinor blocks
 *
 * @param handle [IN]
 *   SPINOR service interface handle
 *
 * @param bTrap [IN]
 *
 * @param start_block [IN]
 *   A starting block for a number of blocks to erase.
 *
 * @param block_count [IN]
 *   Number of blocks to erase
 *
 * @param pwd [IN/OUT]
 *   Pointer holding the current password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2Erase( spinor_handle_t handle, boolean bTrap, uint32 start_block, uint32 block_count, uint32_t *pwd);

/**********************************************************
 * Writes data to the spinor.
 *
 * @param handle [IN]
 *   SPINOR service interface handle
 *
 * @param bTrap [IN]
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
 * @param pwd [IN/OUT]
 *   Pointer holding the current password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2Write( spinor_handle_t handle, boolean bTrap, uint32 byte_offset, uint32 byte_count, const void *buffer, uint32_t *pwd);

/**********************************************************
 * Allows read data from the spinor
 *
 * @param handle [IN]
 *   SPINOR service interface handle
 *
 * @param bTrap [IN]
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
 * @param pwd [IN/OUT]
 *   Pointer holding the current password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   Result of the operation.
 **********************************************************/
SPINOR_STATUS el2Read ( spinor_handle_t handle, boolean bTrap, uint32 byte_offset, uint32 byte_count, void *buffer, uint32_t *pwd);

/**********************************************************
 * Set boot mode.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @param bEnableBootMode [IN]
 *
 * @param pwd [IN/OUT]
 *   Pointer holding the current password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2SetBootMode(spinor_handle_t handle, boolean bEnableBootMode, uint32_t *pwd);

/**********************************************************
 * Get the Sector map information.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @param pSecMapInfo [IN/OUT]
 *   Pointer to the address that will store the sector map information.
 *
 * @param pwd [IN/OUT]
 *   Pointer holding the current password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2GetSectorMapInfo ( spinor_handle_t handle, spinorSectorMapInfoType *secMapInfo, uint32_t *pwd);

/**********************************************************
 * Vote low power to spinor framework.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @param bLowPower [IN]
 *   Vote to allow low power
 *
 * @param pwd [IN/OUT]
 *   Pointer holding the current password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2LowPower ( spinor_handle_t handle, boolean bLowPower, uint32_t *pwd);

/**********************************************************
 * Get memory info from spinor EL2.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @param pmemInfo [OUT]
 *   Pointer to the structure that contains the memory info derived.
 *
 * @param pwd [IN/OUT]
 *   Pointer holding the current password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2GetMemInfo(spinor_handle_t handle, spinorMemInfoType *pmemInfo, uint32_t *pwd);

/**********************************************************
 * Reads from DLP partition to check if the SPINOR device is alive
 *
 * @param none
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2IsDeviceAlive(void);

/**********************************************************
 * De-initializes the controller
 *
 * @param none
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2ControllerDeInit(void);

/**********************************************************
 * Re-initializes the controller
 *
 * @param none
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2ControllerReInit(void);

/**********************************************************
 * Reconfigures the MUX
 *
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2ReconfigureMUX(void);

/**********************************************************
 * Dumps the SFDP table
 *
 * @param none
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2SFDPDump(void);

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
SPINOR_STATUS el2SWResetClose(uint32_t resetCoreID);

/**********************************************************
 * Get the usertype for the handle.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @param eAttrib [IN/OUT]
 *   Pointer to address that contains User type for the handle.
 *
 * @param pwd [IN/OUT]
 *   Pointer holding the current password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2GetUserType( spinor_handle_t handle, eSpinorUserType* usertype, uint32_t *pwd);

/**********************************************************
 * Initialize the global lock
 *
 * @param none [IN]
 *
 * @return void [OUT]
 *
 **********************************************************/
void el2MultiCoreSafeReservationInit(void);

/**********************************************************
 * Unlock for the global lock
 *
 * @param coreid [IN]
 *   Core Id trying to release the lock.
 *
 * @param bTrap [IN]
 *   Trap call
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean el2MultiCoreSafeResRemove(uint32_t coreid, boolean bTrap);

/**********************************************************
 * Try lock for the global lock
 *
 * @param coreid [IN]
 *   Core Id trying to acquire the lock.
 *
 * @param bTrap [IN]
 *   Trap call
 *
 * @return boolean [OUT]
 *   Result of the operation.
 *
 **********************************************************/
boolean el2MultiCoreSafeResTry(uint32_t coreid, boolean bTrap);

#endif /* __SPINOR_EL2_H__ */
