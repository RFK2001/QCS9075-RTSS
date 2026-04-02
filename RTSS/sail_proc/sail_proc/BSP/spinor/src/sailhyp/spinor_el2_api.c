/*
===========================================================================
*/
/**
    @file  spinor_el2_api.c
    @brief Implementation of spinor EL2 API

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

    $Header$
    $DateTime$
    $Author$

    ===========================================================================
*/
#include "spinor_el2_api.h"
#include "spinor_el2.h"
#include "spinor_el2_mini.h"
#include "common_functions.h"
#include "sleepEl2.h"
#include "debug_log.h"
#include "spinor_diag.h"
#include "sailbsp_mutex.h"

static void prvSPINORDeInit_Sleep( const sleepModeType_e eState );

static uint32 ulSPINORSleepHandle;

#define SPINOR_CACHE_LINE_SIZE_BYTES      EL_SHARED_CACHELINE_SIZE

#ifdef FD_HANDLE_USE_PWD
#define IS_NULL_PWD() (NULL == (pwd))
#else
#define IS_NULL_PWD() FALSE
#endif /* FD_HANDLE_USE_PWD */

#ifndef FD_HANDLE_USE_PWD
uint32_t glob_pwd=0;
#endif

#define SPINOR_WORK_BUF_SIZE     4096
static uint8_t guWorkBuf[SPINOR_WORK_BUF_SIZE] __attribute__ ((aligned(SPINOR_CACHE_LINE_SIZE_BYTES))); /* align to cache line in case doing cache invalidation only */


/**********************************************************
 * Locks access to the OSPI Bus resouce
 *
 * @param none
 *
 * @return void [OUT]
 *
 **********************************************************/
static void spinorEl2BusLock(void)
{
    uint32_t cpu_num= get_curr_phys_cpu_num();
    while (1)
    {
        if(TRUE == el2MultiCoreSafeResTry(cpu_num,FALSE))
        {
            /* Lock acquired here so break */
            break;
        }
    }
}

/**********************************************************
 * Unlocks access to OSPI Bus resource
 *
 * @param none
 *
 * @return void [OUT]
 *
 **********************************************************/
static void spinorEl2BusUnlock(void)
{
    uint32_t cpu_num= get_curr_phys_cpu_num();
    el2MultiCoreSafeResRemove(cpu_num, FALSE);
}


/**********************************************************
 * Initialize spinor EL2 driver
 *
 * @param eInitType [IN]
 *   init type
 *
 * @return int [OUT]
 *   Result of the operation. 0 for success, non zero for error
 *
 **********************************************************/
int spinorEl2Init(int eInitType, spinor_hardcode_data_mode *hardcoded_data_mode)
{
    uint64 ret;
    if ( 0x0u == ulSPINORSleepHandle )
    {
        if ( SLEEP_ERR_FLAG_SUCCESS != xSleepRegisterCallBack(&prvSPINORDeInit_Sleep,&ulSPINORSleepHandle))
        {
            DEBUG_LOG(SAIL_INFO,"prvSPINORDeInit_Sleep Sleep Reg Failed\n\r");
        }
    }

    if (SPINOR_INIT_TYPE_RAM_DUMP != eInitType)
    {
        el2MultiCoreSafeReservationInit();
    }

    return (SPINOR_INIT_TYPE_RAM_DUMP == eInitType) ? el2MiniInit(eInitType, guWorkBuf, SPINOR_WORK_BUF_SIZE, hardcoded_data_mode) : el2Init(eInitType, guWorkBuf, SPINOR_WORK_BUF_SIZE, hardcoded_data_mode);
}

/**********************************************************
 * DFe-initialize spinor EL2 driver
 *
 * @param eInitType [IN]
 *   init type
 *
 * @return void [OUT]
 *
 *
 **********************************************************/
void spinorEl2DeInit(int eInitType)
{
    if (SPINOR_INIT_TYPE_RAM_DUMP == eInitType)
    {
        el2MiniDeinit();
    }
    else
    {
        el2DeInit();
    }
}

/**********************************************************
 * De-initializes the controller
 *
 * @param none
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinorEl2ControllerDeInit(void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_FAIL;

    status = el2ControllerDeInit();
    if (status != SPINOR_DEVICE_DONE)
    {
        SPINOR_LOG_ERROR_EL2("%s: Error, controller deinit failed \r\n", __func__);
        status = SPINOR_DEVICE_FAIL;
        return status;
    }
    
    SPINOR_LOG_INFO("%s: SPINOR controller de-init SUCCESSFUL \r\n", __func__);

    return status;
}

/**********************************************************
 * Re-initializes the controller
 *
 * @param none
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinorEl2ControllerReInit(void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_FAIL;

    status = el2ControllerReInit();
    if (status != SPINOR_DEVICE_DONE)
    {
        SPINOR_LOG_ERROR_EL2("%s: Error, controller reinit failed \r\n", __func__);
        status = SPINOR_DEVICE_FAIL;
        return status;
    }
    
    SPINOR_LOG_INFO("%s: SPINOR controller re-init SUCCESSFUL \r\n", __func__);

    return status;
}

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
#ifdef FD_HANDLE_USE_PWD
SPINOR_STATUS spinorEl2Open( spinor_handle_t *handle, eSpinorUserType eUserType,uint32_t *pwd)
{
#else
SPINOR_STATUS spinorEl2Open( spinor_handle_t *handle, eSpinorUserType eUserType)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint32_t *pwd = &glob_pwd;
#endif /* FD_HANDLE_USE_PWD */

    if( (NULL == handle) || IS_NULL_PWD())
    {
        SPINOR_LOG_ERROR_EL2("%s: Error, invalid parameter \r\n", __func__);
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }
    if ( eUserType != SPINOR_USER_TYPE_EL2 && eUserType != SPINOR_USER_TYPE_BOOT_LOADER && eUserType != SPINOR_USER_TYPE_CRASH_DBG && eUserType != SPINOR_USER_TYPE_OTA)
    {
        *handle = (void *)0;
        SPINOR_LOG_ERROR_EL2("%s: Error, invalid user type \r\n", __func__);
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    if(eUserType == SPINOR_USER_TYPE_CRASH_DBG)
    {
        status = el2MiniOpen( handle, eUserType, pwd);
    }
    else
    {
        spinorEl2BusLock();
        status = el2Open( handle, eUserType, pwd);
        spinorEl2BusUnlock();
    }
    return status;
}

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
#ifdef FD_HANDLE_USE_PWD
SPINOR_STATUS spinorEl2Close( spinor_handle_t handle, uint32_t *pwd)
{
#else
SPINOR_STATUS spinorEl2Close( spinor_handle_t handle)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint32_t *pwd = &glob_pwd;
#endif /* FD_HANDLE_USE_PWD */

    if( (NULL == handle) || IS_NULL_PWD() )
    {
        SPINOR_LOG_ERROR_EL2("%s: Error, invalid parameters \r\n", __func__);
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    if((uint32_t)handle == SPINOR_EL2_CRASH_DEBUG_HANDLE)
    {
        status = el2MiniClose(handle, pwd);
    }
    else
    {
        spinorEl2BusLock();
        status = el2Close(handle, pwd);
        spinorEl2BusUnlock();
    }
    return status;
}

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
#ifdef FD_HANDLE_USE_PWD
SPINOR_STATUS spinorEl2GetMemInfo(spinor_handle_t handle, spinorMemInfoType *pmemInfo, uint32_t *pwd)
{
#else
SPINOR_STATUS spinorEl2GetMemInfo(spinor_handle_t handle, spinorMemInfoType *pmemInfo)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint32_t *pwd = &glob_pwd;
#endif /* FD_HANDLE_USE_PWD */

    if ( (NULL == handle) || (NULL == pmemInfo) || IS_NULL_PWD() )
    {
        SPINOR_LOG_ERROR_EL2("%s: Error, invalid parameters \r\n", __func__);
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    if ((uint32_t)handle == SPINOR_EL2_CRASH_DEBUG_HANDLE)
    {
        status = el2MiniGetMemInfo ( handle, pmemInfo, pwd);
    }
    else
    {
        spinorEl2BusLock();
        status = el2GetMemInfo ( handle, pmemInfo, pwd);
        spinorEl2BusUnlock();
    }
    return status;
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
 * @param pwd [IN/OUT]
 *   Pointer holding the current password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
#ifdef FD_HANDLE_USE_PWD
SPINOR_STATUS spinorEl2GetGptPartitionInfo( spinor_handle_t handle, const char *guid,  uint32_t *pulStartAddr, uint32_t *pulSize, uint32_t *pwd)
{
#else
SPINOR_STATUS spinorEl2GetGptPartitionInfo( spinor_handle_t handle, const char *guid,  uint32_t *pulStartAddr, uint32_t *pulSize)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint32_t *pwd = &glob_pwd;
#endif /* FD_HANDLE_USE_PWD */

    if ( (NULL == handle) || (NULL == guid) || (NULL == pulStartAddr) || (NULL == pulSize) || IS_NULL_PWD() )
    {
        SPINOR_LOG_ERROR_EL2("%s: Error, invalid parameters \r\n", __func__);
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    if((uint32_t)handle == SPINOR_EL2_CRASH_DEBUG_HANDLE)
    {
        status = el2MiniGetGptPartitionInfo( handle, guid, pulStartAddr, pulSize, pwd);
    }
    else
    {
        spinorEl2BusLock();
        status = el2GetGptPartitionInfo( handle, guid, pulStartAddr, pulSize, pwd);
        spinorEl2BusUnlock();
    }
    return status;
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
 * @param pwd [IN/OUT]
 *   Pointer holding the current password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
#ifdef FD_HANDLE_USE_PWD
SPINOR_STATUS spinorEl2SetPartitionAttrib( spinor_handle_t handle, const char *guid,  eSpinorProtectType eAttrib, uint32_t *pwd)
{
#else
SPINOR_STATUS spinorEl2SetPartitionAttrib( spinor_handle_t handle, const char *guid,  eSpinorProtectType eAttrib)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint32_t *pwd = &glob_pwd;
#endif /* FD_HANDLE_USE_PWD */

    if ( (NULL == handle) || (NULL == guid) || (SPINOR_PROTECT_MAX <= eAttrib) || IS_NULL_PWD() )
    {
        SPINOR_LOG_ERROR_EL2("%s: Error, invalid parameters \r\n", __func__);
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    if ((uint32_t)handle == SPINOR_EL2_CRASH_DEBUG_HANDLE)
    {
        return SPINOR_DEVICE_NOT_SUPPORTED;
    }

    spinorEl2BusLock();
    status = el2SetPartitionAttrib(handle, guid, eAttrib, pwd);
    spinorEl2BusUnlock();

    return status;
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
#ifdef FD_HANDLE_USE_PWD
SPINOR_STATUS spinorEl2GetPartitionAttrib( spinor_handle_t handle, const char *guid,  eSpinorProtectType* eAttrib, uint32_t *pwd)
{
#else
SPINOR_STATUS spinorEl2GetPartitionAttrib( spinor_handle_t handle, const char *guid,  eSpinorProtectType* eAttrib)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint32_t *pwd = &glob_pwd;
#endif /* FD_HANDLE_USE_PWD */

    if ( (NULL == handle) || (NULL == guid) || (NULL == eAttrib) || IS_NULL_PWD() )
    {
        SPINOR_LOG_ERROR_EL2("%s: Error, invalid parameters \r\n", __func__);
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    if ((uint32_t)handle == SPINOR_EL2_CRASH_DEBUG_HANDLE)
    {
        return SPINOR_DEVICE_NOT_SUPPORTED;
    }

    spinorEl2BusLock();
    status = el2GetPartitionAttrib(handle, guid, eAttrib, pwd);
    spinorEl2BusUnlock();

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
 * @param pwd [IN/OUT]
 *   Pointer holding the current password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
#ifdef FD_HANDLE_USE_PWD
SPINOR_STATUS spinorEl2GetSectorMapInfo(spinor_handle_t handle, spinorSectorMapInfoType *pSecMapInfo, uint32_t *pwd)
{
#else
SPINOR_STATUS spinorEl2GetSectorMapInfo(spinor_handle_t handle, spinorSectorMapInfoType *pSecMapInfo)
{
    SPINOR_STATUS status;
    uint32_t *pwd = &glob_pwd;
#endif /* FD_HANDLE_USE_PWD */

    if ( (NULL == handle) || (NULL == pSecMapInfo) || IS_NULL_PWD() )
    {
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }
    
    spinorEl2BusLock();

    status = el2GetSectorMapInfo( handle, pSecMapInfo, pwd);
    if(status != SPINOR_DEVICE_DONE)
    {
        SPINOR_LOG_ERROR_EL2("%s: Error, Get Sector Map info failed \r\n", __func__);
        spinorEl2BusUnlock();
        return status;
    }
    
    spinorEl2BusUnlock();

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
 * @param pwd [IN/OUT]
 *   Pointer holding the current password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
#ifdef FD_HANDLE_USE_PWD
SPINOR_STATUS spinorEl2Erase( spinor_handle_t handle,
  uint32 start_block, uint32 block_count, uint32_t *pwd)
{
#else
SPINOR_STATUS spinorEl2Erase( spinor_handle_t handle,
  uint32 start_block, uint32 block_count)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint32_t *pwd = &glob_pwd;
#endif /* FD_HANDLE_USE_PWD */

    if ( (NULL == handle) || (0 == block_count) || IS_NULL_PWD())
    {
        SPINOR_LOG_ERROR_EL2("%s: Error, invalid parameters \r\n", __func__);
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    if ((uint32_t)handle == SPINOR_EL2_CRASH_DEBUG_HANDLE)
    {
        status = el2MiniErase( handle, FALSE, start_block, block_count, pwd);
    }
    else
    {
        spinorEl2BusLock();
        status = el2Erase( handle, FALSE, start_block, block_count, pwd);
        spinorEl2BusUnlock();
    }
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
#ifdef FD_HANDLE_USE_PWD
SPINOR_STATUS spinorEl2Write( spinor_handle_t handle, uint32 byte_offset, uint32 byte_count, const void *buffer, uint32_t *pwd)
{
#else
SPINOR_STATUS spinorEl2Write( spinor_handle_t handle, uint32 byte_offset, uint32 byte_count, const void *buffer)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint32_t *pwd = &glob_pwd;
#endif /* FD_HANDLE_USE_PWD */

    if ( (NULL == handle) || (0 == byte_count) || (NULL == buffer) || IS_NULL_PWD() )
    {
        SPINOR_LOG_ERROR_EL2("%s: Error, invalid parameters \r\n", __func__);
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    if ((uint32_t)handle == SPINOR_EL2_CRASH_DEBUG_HANDLE)
    {
        status = el2MiniWrite( handle, FALSE, byte_offset, byte_count, buffer, pwd);
    }
    else
    {
        spinorEl2BusLock();
        status = el2Write( handle, FALSE, byte_offset, byte_count, buffer, pwd);
        spinorEl2BusUnlock();
    }
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
#ifdef FD_HANDLE_USE_PWD
SPINOR_STATUS spinorEl2Read( spinor_handle_t handle, uint32 byte_offset, uint32 byte_count, void *buffer, uint32_t *pwd)
{
#else
SPINOR_STATUS spinorEl2Read( spinor_handle_t handle, uint32 byte_offset, uint32 byte_count, void *buffer)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint32_t *pwd = &glob_pwd;
#endif /* FD_HANDLE_USE_PWD */

    if ( (NULL == handle) || (0 == byte_count) || (NULL == buffer) || IS_NULL_PWD() )
    {
        SPINOR_LOG_ERROR_EL2("%s: Error, invalid parameters \r\n", __func__);
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    if ((uint32_t)handle == SPINOR_EL2_CRASH_DEBUG_HANDLE)
    {
        status = el2MiniRead( handle, FALSE, byte_offset, byte_count, buffer, pwd);
    }
    else
    {
        spinorEl2BusLock();
        status = el2Read( handle, FALSE, byte_offset, byte_count, buffer, pwd);
        spinorEl2BusUnlock();
    }

    return status;
}

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
#ifdef FD_HANDLE_USE_PWD
SPINOR_STATUS spinorEl2SetBootMode ( spinor_handle_t handle, boolean bEnableBootMode, uint32_t *pwd)
{
#else
SPINOR_STATUS spinorEl2SetBootMode ( spinor_handle_t handle, boolean bEnableBootMode)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint32_t *pwd = &glob_pwd;
#endif /* FD_HANDLE_USE_PWD */

    if ( (NULL == handle) || IS_NULL_PWD() )
    {
        SPINOR_LOG_ERROR_EL2("%s: Error, invalid parameters \r\n", __func__);
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }
    if ((uint32_t)handle == SPINOR_EL2_CRASH_DEBUG_HANDLE)
    {
        return SPINOR_DEVICE_NOT_SUPPORTED;
    }
    else
    {
        spinorEl2BusLock();
        status = el2SetBootMode( handle, bEnableBootMode, pwd);
        spinorEl2BusUnlock();
    }
    return status;
}

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
#ifdef FD_HANDLE_USE_PWD
SPINOR_STATUS spinorEl2LowPower( spinor_handle_t handle, boolean bLowPower, uint32_t *pwd)
{
#else
SPINOR_STATUS spinorEl2LowPower( spinor_handle_t handle, boolean bLowPower)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    uint32_t *pwd = &glob_pwd;
#endif /* FD_HANDLE_USE_PWD */

    if ( (NULL == handle) || IS_NULL_PWD() )
    {
        SPINOR_LOG_ERROR_EL2("%s: Error, invalid parameters \r\n", __func__);
        return SPINOR_DEVICE_INVALID_PARAMETER;
    }

    if ((uint32_t)handle == SPINOR_EL2_CRASH_DEBUG_HANDLE)
    {
        return SPINOR_DEVICE_NOT_SUPPORTED;
    }
    else
    {
        spinorEl2BusLock();
        status = el2LowPower ( handle, bLowPower, pwd);
        spinorEl2BusUnlock();
    }
    return status;
}

/**********************************************************
 * Dump the SPINOR SFDP Table.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinorEl2SFDPDump(void)
{
    return ((uint32_t)el2SFDPDump());
}

void prvSPINORDeInit_Sleep(const sleepModeType_e eState)
{
   uint32_t phys_core_id = get_curr_phys_cpu_num();
   if ((( STR_SLEEP_MODE == eState ) || (DEEP_SLEEP_MODE == eState))&& (0x0 == phys_core_id) )
   {
       if ( SPINOR_DEVICE_DONE ==  spinorEl2ControllerDeInit() )
       {
            if (SLEEP_ERR_FLAG_SUCCESS == xSleepDriverAck(ulSPINORSleepHandle, DRIVER_SLEEP))
            {
                DEBUG_LOG(SAIL_INFO, "prvSPINORDeInit_Sleep xSleepDriverAck Success\n\r");
            }else
            {
                DEBUG_LOG(SAIL_ERROR, "prvSPINORDeInit_Sleep xSleepDriverAck Failed\n\r");
            }
       }else
       {
            DEBUG_LOG(SAIL_ERROR, "spinorEl2ControllerDeInit Failed\n\r");
       }
   }

}

/**********************************************************
 * Reconfigure MUX
 *
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinorEl2ReconfigureMUX(void)
{
    SPINOR_STATUS status = SPINOR_DEVICE_DONE;
    
    status = (uint32_t)el2ReconfigureMUX();
    
#ifdef SAIL_CC_SPINOR
    prvSPINORDeInit_Sleep(SLEEP_ENTRY);
#endif /* SAIL_CC_SPINOR */
    
    return status;
}