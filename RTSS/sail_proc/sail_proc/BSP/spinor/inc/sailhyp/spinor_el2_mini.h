#ifndef __SPINOR_EL2_MINI_H__
#define __SPINOR_EL2_MINI_H__

/*
===========================================================================
*/
/**
    @file  spinor_el2_mini.h
    @brief SPI NOR EL2 mini framework structure defines for crash debug.

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

    $Header: $
    $DateTime: $
    $Author: $

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

#define SPINOR_EL2_CRASH_DEBUG_HANDLE    0xCADEBADE
typedef struct {
    spinor_handle_t spinorHandle;
    struct spinor_info spinorInfo;
    uint8_t *puWorkBuf;
    uint32_t ulBufLen;
} spinor_el2_mini_struct_type;

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
int el2MiniInit( int type , uint8_t *puWorkBuf, uint32_t ulBufLen, spinor_hardcode_data_mode *hardcoded_data_mode);

/**********************************************************
 * De-initialize OSPI EL2 driver
 *
 * @param none
 *
 * @return void [OUT]
 *
 **********************************************************/
void el2MiniDeinit( void );

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
SPINOR_STATUS el2MiniOpen( spinor_handle_t *handle, eSpinorUserType eUserType, uint32_t *pwd);

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
SPINOR_STATUS el2MiniClose( spinor_handle_t handle, uint32_t *pwd);

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
SPINOR_STATUS el2MiniGetMemInfo(spinor_handle_t handle, spinorMemInfoType *pmemInfo, uint32_t *pwd);

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
SPINOR_STATUS el2MiniGetGptPartitionInfo( spinor_handle_t handle, const char *guid, uint32_t *pulStartAddr, uint32_t *pulSize, uint32_t *pwd);

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
SPINOR_STATUS el2MiniErase( spinor_handle_t handle, boolean bTrap, uint32 start_block, uint32 block_count, uint32_t *pwd);

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
SPINOR_STATUS el2MiniWrite( spinor_handle_t handle, boolean bTrap, uint32 byte_offset, uint32 byte_count, const void *buffer, uint32_t *pwd);

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
SPINOR_STATUS el2MiniRead ( spinor_handle_t handle, boolean bTrap, uint32 byte_offset, uint32 byte_count, void *buffer, uint32_t *pwd);
#endif /* __SPINOR_EL2_MINI_H__ */
