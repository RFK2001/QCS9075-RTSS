#ifndef __SPINOR_EL1_API_H__
#define __SPINOR_EL1_API_H__

/*
===========================================================================
*/
/**
    @file  spinor_el1_api.h
    @brief Public interface declaration for the Spinor EL1 Service.
           This file describes the spinor EL1 external interface.

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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/public/sailsw1/spinor_el1_api.h#1 $
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


#include "spinor_cm_defs.h"
#include "freertos_init.h"

#define SPINOR_FUNC  __attribute__ ( ( section ( "spinor_func" ) ) )
#define SPINOR_UNPRIV_DATA __attribute__ ( ( section ( "bsp_global_data" ) ) )

typedef void (*spinorEl1CallbackType)(SPINOR_STATUS status, uint8 transaction_ID);

typedef struct
{
    uint8 transaction_ID;
}spinorEl1userdata;

/* Bincmd Parameters */
typedef struct
{
    uint32_t addr;                /* Address of the memory/register */
    uint32_t len;                 /* Length of the buffer or data. should be the size of the data */
    uint8 *buffer;                /* Data buffer. The actual allocated buffer size should be atleast 1 byte more than the len passed*/
    uint8_t opcode;               /* Opcode for the SPI command */
    uint8_t dummy_cycle;          /* Number of Dummy cycles (used only for binary commands) */
    uint8_t num_addr_bytes;       /* Number of address bytes (used only for binary commands) */
    boolean is_write_operation;   /* Is the operation write or not. Needed for cache/pre/post operations (used only for binary commands) */
    boolean use_dma;              /* Use the SPINOR DMA or PIO. Needed for cache/pre/post operations(used only for binary commands) */
}spinorBincmdParams_t;

/**********************************************************
 * Spinor EL1 Task Init
 *
 *
 * @param xSchdCore [IN]
 *   CPU number
 *
 * @param xTaskPrior [IN]
 *   Task Priority
 *
 * @return portBaseType [OUT]
 *   Status of the operation
 *
 **********************************************************/
BaseType_t xSpinorEL1TaskInit( CPUIdType_e  xSchdCore, UBaseType_t  xTaskPrior );

/**********************************************************
 * Spinor EL1 task Resouce Initalization
 *
 *
 * @param xSchdCore [IN]
 *   CPU number
 *
 * @return portBaseType [OUT]
 *   Status of the Initalization
 *
 **********************************************************/
BaseType_t xSpinorEl1TaskResourceInit(CPUIdType_e xSchdCore);

/**********************************************************
 * SPINOR EL1 Task
 *
 *
 * @param pvParameters [IN/OUT]
 *   Pointer for Input Params
 *
 * @return void [OUT]
 *   None
 *
 **********************************************************/
void vSpinorEl1Task(void * pvParameters);

/**********************************************************
 * Initialize OSPI EL1 driver
 *
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinorEl1Init(void);

/**********************************************************
 * De-initialize OSPI EL1 driver
 *
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinorEl1DeInit(void);

/**********************************************************
 * Opens handle to a access to the spinor device
 *
 *
 * @param type [IN/OUT]
 *   Pointer to SPINOR service interface handle as an input parameter.
 *   Pointer to internal spinor_clients reference count upon return
 *
 * @param eUserType [IN]
 *	 SPINOR User type
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinorEl1Open( spinor_handle_t *handle, eSpinorUserType eUserType);

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
SPINOR_STATUS spinorEl1Close( spinor_handle_t handle);

/**********************************************************
 * Vote low power to spinor framework.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinorEl1LowPower( spinor_handle_t handle, boolean bLowPower);

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
SPINOR_STATUS spinorEl1GetSectorMapInfo(spinor_handle_t handle, spinorSectorMapInfoType *pSecMapInfo);

/**********************************************************
 * Get memory info from spinor EL1.
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
SPINOR_STATUS spinorEl1GetMemInfo(spinor_handle_t handle, spinorMemInfoType *pmemInfo);

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
SPINOR_STATUS spinorEl1GetGptPartitionInfo( spinor_handle_t handle, const char *guid,  uint32_t *pulStartAddr, uint32_t *pulSize );

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
SPINOR_FUNC SPINOR_STATUS spinorEl1SetPartitionAttrib( spinor_handle_t handle, const char *guid,  eSpinorProtectType eAttrib );

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
SPINOR_FUNC SPINOR_STATUS spinorEl1GetPartitionAttrib( spinor_handle_t handle, const char *guid,  eSpinorProtectType* eAttrib );

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
SPINOR_STATUS spinorEl1Erase( spinor_handle_t handle, uint32 start_block, uint32 block_count);

/**********************************************************
 * Erases given spinor blocks (Async)
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
SPINOR_FUNC SPINOR_STATUS spinorEl1Erase_Async(spinor_handle_t handle, uint32 start_block, uint32 block_count, spinorEl1CallbackType eraseCallback, spinorEl1userdata* userdata);

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
SPINOR_STATUS spinorEl1Write( spinor_handle_t handle, uint32 byte_offset, uint32 byte_count, const void *buffer);

/**********************************************************
 * Writes data to the spinor. (Async)
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
SPINOR_FUNC SPINOR_STATUS spinorEl1Write_Async(spinor_handle_t handle, uint32 byte_offset, uint32 byte_count, const void* buffer, spinorEl1CallbackType writeCallback, spinorEl1userdata* userdata);

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
SPINOR_STATUS spinorEl1Read( spinor_handle_t handle, uint32 byte_offset, uint32 byte_count, void *buffer);

/**********************************************************
 * Allows read data from the spinor (Async)
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
SPINOR_FUNC SPINOR_STATUS spinorEl1Read_Async(spinor_handle_t handle, uint32 byte_offset, uint32 byte_count, void* buffer, spinorEl1CallbackType readCallback, spinorEl1userdata* userdata);

/**********************************************************
 * Reads from DLP partition to check if the SPINOR device is alive
 *
 * @param none
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinorEl1IsDeviceAlive( void );

/**********************************************************
 * Dumps the SFDP table
 *
 * @param none
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinorEl1DumpSFDP(void);

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
SPINOR_FUNC SPINOR_STATUS spinorEl1CoreResetHandler(uint32 resetCoreID);

/**********************************************************
 * Acquire the SPIBUS
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinorEl1AcquireSPIBus(spinor_handle_t handle);

/**********************************************************
 * Release the SPIBUS
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinorEl1ReleaseSPIBus(spinor_handle_t handle);

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
SPINOR_STATUS spinorEl1Bincmd( spinor_handle_t handle, spinorBincmdParams_t *bincmdParams);
#endif /* __SPINOR_EL1_API_H__ */
