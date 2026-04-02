/*
===========================================================================
*/
/**
    @file  spinor_el1_api.c
    @brief Implementation of spinor EL1 API

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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/src/sailsw1/spinor_el1_api.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "spinor_el1_api.h"
#include "spinor_el1.h"
#include "osal.h"
#include "debug_log.h"

/* this mutex is to protect the threads from the same core from competing for SPINOR resources */
SPINOR_UNPRIV_DATA OsalMutex xSPINORMutex;

/**********************************************************
 *
 *
 * SPINOR service trap systemcall interface primitives
 *
 *
 **********************************************************/

 /**********************************************************
 * (Safertos) Initializes the Safe RTOS mutex
 *
 * @param none
 *
 * @return status of the operation [OUT]
 *
 **********************************************************/
SPINOR_FUNC static boolean el1SafeRTOSMutexInit(void)
{
    if(OSAL_OK != xOsalMutexInit(&xSPINORMutex))
    {
        return FALSE;
    }
    return TRUE;
}

 /**********************************************************
 * (Safertos) Locks access to the OSPI EL1 driver and block the
 * threads within the core to acquire the lock for exercising any SPINOR access.
 *
 * @param none
 *
 * @return void [OUT]
 *
 **********************************************************/
SPINOR_FUNC static void el1SafeRTOSLock(void)
{
    vOsalMutexLock(&xSPINORMutex);
}

/**********************************************************
 * (Safertos) Unlocks access to OSPI EL1 driver
 *
 * @param none
 *
 * @return void [OUT]
 *
 **********************************************************/
SPINOR_FUNC static void el1SafeRTOSUnlock(void)
{
    vOsalMutexUnlock(&xSPINORMutex);
}

/**********************************************************
 * Initialize OSPI EL1 driver
 *
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_FUNC SPINOR_STATUS spinorEl1Init(void)
{
    SPINOR_STATUS status;
    boolean ret;

    //Initializes the mutex
    ret = el1SafeRTOSMutexInit();
    if(ret != TRUE)
    {
        DEBUG_LOG( SAIL_ERROR, "%s: failed to acquire mutex\r\n", __func__ );
        status = SPINOR_DEVICE_FAIL;
        return status;
    }

    status = el1Init();
    if(status != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "%s: el1Init failed\r\n", __func__ );
        return status;
    }

    return SPINOR_DEVICE_DONE;
}

/**********************************************************
 * De-initialize OSPI EL1 driver
 *
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_FUNC SPINOR_STATUS spinorEl1DeInit(void)
{
    SPINOR_STATUS status;
    boolean ret;

    status = el1DeInit();
    if (status != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG(SAIL_ERROR, "%s: el1DeInit failed\r\n", __func__);
        return status;
    }

    return SPINOR_DEVICE_DONE;
}

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
SPINOR_FUNC SPINOR_STATUS spinorEl1Open( spinor_handle_t *handle, eSpinorUserType eUserType)
{
    SPINOR_STATUS status;

    if( (NULL == handle))
    {
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }
    if ((SPINOR_USER_TYPE_EL1  != eUserType) && (SPINOR_USER_TYPE_EL1_SUPER != eUserType) && ( SPINOR_USER_TYPE_OTA != eUserType))
    {
        *handle = (void *)0;
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    //lock the mutex
    el1SafeRTOSLock();

    status = el1Open( handle, eUserType);
    if(status != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "%s: el1 open failed\r\n", __func__ );
        el1SafeRTOSUnlock();
        return status;
    }

    //unlock the mutex
    el1SafeRTOSUnlock();

    return SPINOR_DEVICE_DONE;
}

/**********************************************************
 * Closes handle to a spinor service.
 * Clients should close the handle when accesses to
 * the device is no longer needed.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @param eUserType [IN]
 *   SPINOR User type
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_FUNC SPINOR_STATUS spinorEl1Close( spinor_handle_t handle)
{
    SPINOR_STATUS status;

    if( (NULL == handle))
    {
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    //lock the mutex
    el1SafeRTOSLock();

    status = el1Close(handle);
    if(status != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "%s: el1 close failed\r\n", __func__ );
        el1SafeRTOSUnlock();
        return status;
    }

    //unlock the mutex
    el1SafeRTOSUnlock();

    return SPINOR_DEVICE_DONE;
}

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
SPINOR_FUNC SPINOR_STATUS spinorEl1GetMemInfo(spinor_handle_t handle, spinorMemInfoType *pmemInfo)
{
    SPINOR_STATUS status;

    if ( (NULL == handle) || (NULL == pmemInfo) )
    {
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    //lock the mutex
    el1SafeRTOSLock();

    status = el1GetMemInfo ( handle, pmemInfo);
    if(status != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "%s: el1 get mem info failed\r\n", __func__ );
        el1SafeRTOSUnlock();
        return status;
    }

    //unlock the mutex
    el1SafeRTOSUnlock();

    return SPINOR_DEVICE_DONE;
}

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
SPINOR_FUNC SPINOR_STATUS spinorEl1GetGptPartitionInfo( spinor_handle_t handle, const char *guid,  uint32_t *pulStartAddr, uint32_t *pulSize )
{
    SPINOR_STATUS status;

    if ( (NULL == handle) || (NULL == guid) || (NULL == pulStartAddr) || (NULL == pulSize) )
    {
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    //lock the mutex
    el1SafeRTOSLock();

    status = el1GetGptPartitionInfo( handle, (const char *)guid, pulStartAddr, pulSize);
    if(status != SPINOR_DEVICE_DONE)
    {
        //DEBUG_LOG( SAIL_ERROR, "%s: el1 get partition info failed", __func__ );
        el1SafeRTOSUnlock();
        return status;
    }

    //unlock the mutex
    el1SafeRTOSUnlock();

    return SPINOR_DEVICE_DONE;
}

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
SPINOR_FUNC SPINOR_STATUS spinorEl1SetPartitionAttrib( spinor_handle_t handle, const char *guid,  eSpinorProtectType eAttrib )
{
    SPINOR_STATUS status;

    if ( (NULL == handle) || (NULL == guid) || (SPINOR_PROTECT_MAX <= eAttrib) )
    {
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    //lock the mutex
    el1SafeRTOSLock();

    status = el1SetPartitionAttrib( handle, (const char *)guid, eAttrib);
    if(status != SPINOR_DEVICE_DONE)
    {
        //DEBUG_LOG( SAIL_ERROR, "%s: el1 Set Partition Attribute failed", __func__ );
        el1SafeRTOSUnlock();
        return status;
    }

    //unlock the mutex
    el1SafeRTOSUnlock();

    return SPINOR_DEVICE_DONE;
}

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
SPINOR_FUNC SPINOR_STATUS spinorEl1GetPartitionAttrib( spinor_handle_t handle, const char *guid,  eSpinorProtectType* eAttrib )
{
    SPINOR_STATUS status;

    if ( (NULL == handle) || (NULL == guid) || (NULL == eAttrib) )
    {
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    //lock the mutex
    el1SafeRTOSLock();

    status = el1GetPartitionAttrib( handle, (const char *)guid, eAttrib);
    if(status != SPINOR_DEVICE_DONE)
    {
        //DEBUG_LOG( SAIL_ERROR, "%s: el1 Set Partition Attribute failed", __func__ );
        el1SafeRTOSUnlock();
        return status;
    }

    //unlock the mutex
    el1SafeRTOSUnlock();

    return SPINOR_DEVICE_DONE;
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
SPINOR_STATUS spinorEl1GetSectorMapInfo(spinor_handle_t handle, spinorSectorMapInfoType *pSecMapInfo)
{
    SPINOR_STATUS status;

    if ( (NULL == handle) || (NULL == pSecMapInfo) )
    {
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    //lock the mutex
    el1SafeRTOSLock();

    status = el1GetSectorMapInfo( handle, pSecMapInfo);
    if(status != SPINOR_DEVICE_DONE)
    {
        el1SafeRTOSUnlock();
        return status;
    }

    //unlock the mutex
    el1SafeRTOSUnlock();

    return SPINOR_DEVICE_DONE;
}

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
SPINOR_FUNC SPINOR_STATUS spinorEl1Erase( spinor_handle_t handle, uint32 start_block, uint32 block_count)
{
    SPINOR_STATUS status;

    if ( (NULL == handle) || (0 == block_count))
    {
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    //lock the mutex
    el1SafeRTOSLock();

    status = el1Erase( handle,start_block, block_count, NULL, NULL);
    if(status != SPINOR_DEVICE_DONE)
    {
        //DEBUG_LOG( SAIL_ERROR, "%s: el1 erase failed", __func__ );
        el1SafeRTOSUnlock();
        return status;
    }

    //unlock the mutex
    el1SafeRTOSUnlock();

    return SPINOR_DEVICE_DONE;
}

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
SPINOR_FUNC SPINOR_STATUS spinorEl1Erase_Async(spinor_handle_t handle, uint32 start_block, uint32 block_count, spinorEl1CallbackType eraseCallback, spinorEl1userdata* userdata)
{
    SPINOR_STATUS status;

    if ((NULL == handle) || (0 == block_count) || (NULL == eraseCallback) || (NULL == userdata))
    {
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    //lock the mutex
    el1SafeRTOSLock();

    status = el1Erase(handle, start_block, block_count, eraseCallback, userdata);
    if (status != SPINOR_DEVICE_OK_NOT_DONE)
    {
        //DEBUG_LOG( SAIL_ERROR, "%s: el1 erase failed", __func__ );
        el1SafeRTOSUnlock();
        return status;
    }

    //unlock the mutex
    el1SafeRTOSUnlock();

    return status;
}

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
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_FUNC SPINOR_STATUS spinorEl1Write( spinor_handle_t handle, uint32 byte_offset, uint32 byte_count, const void *buffer)
{
    SPINOR_STATUS status;

    if ( (NULL == handle) || (0 == byte_count) || (NULL == buffer))
    {
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    //lock the mutex
    el1SafeRTOSLock();

    status = el1Write( handle,byte_offset, byte_count, buffer, NULL, NULL);
    if(status != SPINOR_DEVICE_DONE)
    {
        //DEBUG_LOG( SAIL_ERROR, "%s: el1 write failed", __func__ );
        el1SafeRTOSUnlock();
        return status;
    }

    //unlock the mutex
    el1SafeRTOSUnlock();

    return SPINOR_DEVICE_DONE;
}

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
SPINOR_FUNC SPINOR_STATUS spinorEl1Write_Async(spinor_handle_t handle, uint32 byte_offset, uint32 byte_count, const void* buffer, spinorEl1CallbackType writeCallback, spinorEl1userdata* userdata)
{
    SPINOR_STATUS status;

    if ((NULL == handle) || (0 == byte_count) || (NULL == buffer) || (NULL == writeCallback) || (NULL == userdata))
    {
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    //lock the mutex
    el1SafeRTOSLock();

    status = el1Write(handle, byte_offset, byte_count, buffer, writeCallback, userdata);
    if (status != SPINOR_DEVICE_OK_NOT_DONE)
    {
        //DEBUG_LOG( SAIL_ERROR, "%s: el1 write failed", __func__ );
        el1SafeRTOSUnlock();
        return status;
    }

    //unlock the mutex
    el1SafeRTOSUnlock();

    return status;
}

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
 * @return int [OUT]
 *   Result of the operation.
 **********************************************************/
SPINOR_FUNC SPINOR_STATUS spinorEl1Read( spinor_handle_t handle, uint32 byte_offset, uint32 byte_count, void *buffer)
{
    SPINOR_STATUS status;

    if ( (NULL == handle) || (0 == byte_count) || (NULL == buffer) )
    {
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    //lock the mutex
    el1SafeRTOSLock();

    status = el1Read( handle, byte_offset, byte_count, buffer, NULL, NULL);
    if(status != SPINOR_DEVICE_DONE)
    {
        //DEBUG_LOG( SAIL_ERROR, "%s: el1 read failed", __func__ );
        el1SafeRTOSUnlock();
        return status;
    }

    //unlock the mutex
    el1SafeRTOSUnlock();

    return SPINOR_DEVICE_DONE;
}

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
SPINOR_FUNC SPINOR_STATUS spinorEl1Read_Async(spinor_handle_t handle, uint32 byte_offset, uint32 byte_count, void* buffer, spinorEl1CallbackType readCallback, spinorEl1userdata* userdata)
{
    SPINOR_STATUS status;

    if ((NULL == handle) || (0 == byte_count) || (NULL == buffer) || (NULL == readCallback) || (NULL == userdata))
    {
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    //lock the mutex
    el1SafeRTOSLock();

    status = el1Read(handle, byte_offset, byte_count, buffer, readCallback, userdata);
    if (status != SPINOR_DEVICE_OK_NOT_DONE)
    {
        //DEBUG_LOG( SAIL_ERROR, "%s: el1 read failed", __func__ );
        el1SafeRTOSUnlock();
        return status;
    }

    //unlock the mutex
    el1SafeRTOSUnlock();

    return status;
}

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
SPINOR_FUNC SPINOR_STATUS spinorEl1LowPower( spinor_handle_t handle, boolean bLowPower)
{
    SPINOR_STATUS status;

    if ( (NULL == handle))
    {
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    //lock the mutex
    el1SafeRTOSLock();

    status = el1LowPower ( handle, bLowPower);
    if(status != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "%s: el1 low power failed\r\n", __func__ );
        el1SafeRTOSUnlock();
        return status;
    }

    //unlock the mutex
    el1SafeRTOSUnlock();

    return SPINOR_DEVICE_DONE;
}

/**********************************************************
 * Reads from DLP partition to check if the SPINOR device is alive
 *
 * @param none
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_FUNC SPINOR_STATUS spinorEl1IsDeviceAlive( void )
{
    SPINOR_STATUS status;
    spinor_handle_t el1Handle = NULL;

    //lock the mutex
    el1SafeRTOSLock();

    status = spinorEl1Open ( &el1Handle, SPINOR_USER_TYPE_EL1 );
    if(status != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "%s: el1 open failed\r\n", __func__ );
        el1SafeRTOSUnlock();
        return status;
    }

    status = el1IsDeviceAlive();
    if(status != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "%s: el1 is device alive failed\r\n", __func__ );
        el1SafeRTOSUnlock();
        return status;
    }

    if(el1Handle != NULL)
    {
      status = spinorEl1Close( el1Handle );
      if(status != SPINOR_DEVICE_DONE)
      {
          DEBUG_LOG( SAIL_ERROR, "%s: el1 close failed\r\n", __func__ );
          el1SafeRTOSUnlock();
          return status;
      }
    }

    //unlock the mutex
    el1SafeRTOSUnlock();

    return SPINOR_DEVICE_DONE;
}

/**********************************************************
 * Dumps the SFDP table
 *
 * @param none
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_FUNC SPINOR_STATUS spinorEl1DumpSFDP(void)
{
    SPINOR_STATUS status;

    //lock the mutex
    el1SafeRTOSLock();

    status = el1DumpSFDP();
    if (status != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG(SAIL_ERROR, "%s: el1 dump SFDP failed\r\n", __func__);
        el1SafeRTOSUnlock();
        return status;
    }

    //unlock the mutex
    el1SafeRTOSUnlock();

    return SPINOR_DEVICE_DONE;
}

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
SPINOR_FUNC SPINOR_STATUS spinorEl1CoreResetHandler(uint32 resetCoreID)
{
    SPINOR_STATUS status;

    status = el1SWResetClose(resetCoreID);
    if (status != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG(SAIL_ERROR, "%s: SW Reset close handles failed\r\n", __func__);
        return status;
    }

    return SPINOR_DEVICE_DONE;
}

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
SPINOR_FUNC SPINOR_STATUS spinorEl1AcquireSPIBus(spinor_handle_t handle)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;

    if( (NULL == handle))
    {
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    //lock the mutex
    el1SafeRTOSLock();

    status = el1AquireLock(handle);
    if (status != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG(SAIL_ERROR, "%s: Acquire lock failed\r\n", __func__);
        el1SafeRTOSUnlock();
        return status;
    }

    //unlock the mutex
    el1SafeRTOSUnlock();

    return SPINOR_DEVICE_DONE;
}

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
SPINOR_FUNC SPINOR_STATUS spinorEl1ReleaseSPIBus(spinor_handle_t handle)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    if( (NULL == handle))
    {
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    //lock the mutex
    el1SafeRTOSLock();

    status = el1ReleaseLock(handle);
    if (status != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG(SAIL_ERROR, "%s: Release lock failed\r\n", __func__);
        el1SafeRTOSUnlock();
        return status;
    }

    //unlock the mutex
    el1SafeRTOSUnlock();

    return SPINOR_DEVICE_DONE;
}

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
SPINOR_FUNC SPINOR_STATUS spinorEl1Bincmd( spinor_handle_t handle, spinorBincmdParams_t *bincmdParams)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;

    if( (NULL == handle) || (NULL == bincmdParams))
    {
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    //lock the mutex
    el1SafeRTOSLock();

    status = el1Bincmd( handle, bincmdParams);
    if(status != SPINOR_DEVICE_DONE)
    {
        DEBUG_LOG( SAIL_ERROR, "%s: el1 SPI Binary Command failed\r\n", __func__ );
        el1SafeRTOSUnlock();
        return status;
    }

    //unlock the mutex
    el1SafeRTOSUnlock();

    return SPINOR_DEVICE_DONE;
}

