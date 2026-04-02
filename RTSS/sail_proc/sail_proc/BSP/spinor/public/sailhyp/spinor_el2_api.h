#ifndef __SPINOR_EL2_API_H__
#define __SPINOR_EL2_API_H__

/*
===========================================================================
*/
/**
    @file  spinor_el2_api.h
    @brief Public interface declaration for the Spinor EL2 Service.
           This file describes the spinor service external interface.

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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/public/sailhyp/spinor_el2_api.h#1 $
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
* Filename                       Error code
* spinor_el2_api.c               0x1
* spinor_el2_client.c            0x2
* spinor_el2_trans.c             0x3
* spinor_el2_sgi.c               0x4
* spinor_el2_ac.c                0x5
* spinor_el2_trap.c              0x6
****/

#include "spinor_cm_defs.h"

/**********************************************************
 *
 *
 * SPINOR service EL2 function interafce primitives
 *
 *
 **********************************************************/

/**********************************************************
 * Initialize spinor EL2 driver
 *
 *
 * @param eInitType
 *   Initialization type
 *
 * @return int [OUT]
 *   Result of the operation. 0 for sucdess, non zero for error
 *
 **********************************************************/
int spinorEl2Init(int eInitType, spinor_hardcode_data_mode *hardcoded_data_mode);

/**********************************************************
 * De-initialize spinor EL2 driver
 *
 *
 * @param eInitType
 *   Initialization type
 *
 * @return void [OUT]
 *
 *
 **********************************************************/
void spinorEl2DeInit(int eInitType);

/**********************************************************
 * Re-initializes the controller
 *
 * @param void [IN]
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinorEl2ControllerReInit(void);

/**********************************************************
 * Reconfigure MUX
 *
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinorEl2ReconfigureMUX(void);

/**********************************************************
 * Dump the SPINOR SFDP Table.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinorEl2SFDPDump(void);

#ifdef FD_HANDLE_USE_PWD
/**********************************************************
 * Opens handle to a access to the spinor service
 *
 *
 * @param handle [IN/OUT]
 *   Pointer to SPINOR service interface handle as an input parameter.
 *   Pointer to internal spinor_clients refernce count upon return
 *
 * @param eUserType [IN]
 *   Parameter that defines the type of user
 *
 * @param pwd [IN/OUT]
 *   Pointer to hold the password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinorEl2Open( spinor_handle_t *handle, eSpinorUserType eUserType,uint32_t *pwd);

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
SPINOR_STATUS spinorEl2Close( spinor_handle_t handle, uint32_t *pwd);

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
SPINOR_STATUS spinorEl2GetMemInfo(spinor_handle_t handle, spinorMemInfoType *pmemInfo, uint32_t *pwd);

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
SPINOR_STATUS spinorEl2LowPower( spinor_handle_t handle, boolean bLowPower, uint32_t *pwd);

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
SPINOR_STATUS spinorEl2GetGptPartitionInfo( spinor_handle_t handle, const char *guid, uint32_t *pulStartAddr, uint32_t *pulSize, uint32_t *pwd);

/**********************************************************
 * Query GPT partition information to spinor framework.
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
SPINOR_STATUS spinorEl2SetPartitionAttrib( spinor_handle_t handle, const char *guid,  eSpinorProtectType eAttrib, uint32_t *pwd);

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
SPINOR_STATUS spinorEl2GetPartitionAttrib( spinor_handle_t handle, const char *guid,  eSpinorProtectType* eAttrib, uint32_t *pwd);

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
SPINOR_STATUS spinorEl2GetSectorMapInfo(spinor_handle_t handle, spinorSectorMapInfoType *pSecMapInfo, uint32_t *pwd);

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
 * @param pwd [IN/OUT]
 *   Pointer holding the current password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinorEl2Erase( spinor_handle_t handle, uint32 start_block, uint32 block_count, uint32_t *pwd);

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
SPINOR_STATUS spinorEl2Write( spinor_handle_t handle, uint32 byte_offset, uint32 byte_count, const void *buffer, uint32_t *pwd);

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
SPINOR_STATUS spinorEl2Read( spinor_handle_t handle, uint32 byte_offset, uint32 byte_count, void *buffer, uint32_t *pwd);

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
SPINOR_STATUS spinorEl2SetBootMode(spinor_handle_t handle, boolean bEnableBootMode, uint32_t *pwd);

#else /* FD_HANDLE_USE_PWD */

/**********************************************************
 * Opens handle to a access to the spinor service
 *
 *
 * @param handle [IN/OUT]
 *   Pointer to SPINOR service interface handle as an input parameter.
 *   Pointer to internal spinor_clients refernce count upon return
 *
 * @param eUserType [IN]
 *   Parameter that defines the type of user
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinorEl2Open( spinor_handle_t *handle, eSpinorUserType eUserType);

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
SPINOR_STATUS spinorEl2Close( spinor_handle_t handle);

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
SPINOR_STATUS spinorEl2GetMemInfo(spinor_handle_t handle, spinorMemInfoType *pmemInfo);

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
SPINOR_STATUS spinorEl2LowPower( spinor_handle_t handle, boolean bLowPower);

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
SPINOR_STATUS spinorEl2GetGptPartitionInfo( spinor_handle_t handle, const char *guid, uint32_t *pulStartAddr, uint32_t *pulSize);

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
SPINOR_STATUS spinorEl2SetPartitionAttrib( spinor_handle_t handle, const char *guid,  eSpinorProtectType eAttrib);

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
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinorEl2GetPartitionAttrib( spinor_handle_t handle, const char *guid,  eSpinorProtectType* eAttrib);

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
SPINOR_STATUS spinorEl2GetSectorMapInfo(spinor_handle_t handle, spinorSectorMapInfoType *pSecMapInfo);

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
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinorEl2Erase( spinor_handle_t handle, uint32 start_block, uint32 block_count);

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
 * @buffer [IN]
 *   Data buffer for spinor write operation.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinorEl2Write( spinor_handle_t handle, uint32 byte_offset, uint32 byte_count, const void *buffer);

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
 * @buffer [OUT]
 *   Data buffer for a spinor read operation.
 *
 * @return int [OUT]
 *   Result of the operation.
 **********************************************************/
SPINOR_STATUS spinorEl2Read( spinor_handle_t handle, uint32 byte_offset, uint32 byte_count, void *buffer);

/**********************************************************
 * Set boot mode.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @param bEnableBootMode [IN]
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinorEl2SetBootMode(spinor_handle_t handle, boolean bEnableBootMode);

#endif /* FD_HANDLE_USE_PWD */

#endif /* __SPINOR_EL2_API_H__ */
