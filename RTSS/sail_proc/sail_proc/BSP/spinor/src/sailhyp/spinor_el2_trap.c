/*
===========================================================================
*/
/**
    @file  spinor_el2_trap.c
    @brief Implementation of spinor EL2 Trap services

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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/src/sailhyp/spinor_el2_trap.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "spinor_el2_trap.h"
#include "spinor_el2.h"
#include "syscall.h"
#include "syscall_pub.h"
#include "common_functions.h"

#include "spinor_trap_defs.h"

static boolean gSpinorEl2TrapInitDone = FALSE;

/**********************************************************
 * Opens a trap handler
 *
 * @param handle [IN/OUT]
 *   Pointer to SPINOR service interface handle as an input parameter.
 *   Pointer to internal spinor_clients refernce count upon return
 *
 * @param eUserType [IN]
 *   Spinor User type
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
uint32 spinorEl2TrapOpen( spinorTrapHandle_t *h, eSpinorUserType eUserType, sailbsp_hvc_rsp_t *rsp )
{
    spinor_handle_t *handle;
    uint32 *pwd;

    if (FALSE == gSpinorEl2TrapInitDone)
    {
        rsp->data[0] = SPINOR_DEVICE_FAIL;
        return HVC_SUCCESS;
    }

    handle = (spinor_handle_t *)h->handle;
    pwd = h->pwd;

    if( (NULL == handle) || (NULL == pwd))
    {
        rsp->data[0] = SPINOR_DEVICE_INVALID_PARAMETER;
        return HVC_SUCCESS;
    }

    if ( (SPINOR_USER_TYPE_EL1 != eUserType) && (SPINOR_USER_TYPE_EL1_SUPER != eUserType) && (SPINOR_USER_TYPE_OTA != eUserType))
    {
        *handle = (void *)0;
        *pwd = 0;
        rsp->data[0] = SPINOR_DEVICE_INVALID_PARAMETER;
        return HVC_SUCCESS;
    }

    rsp->data[0] = ((uint32_t)el2Open( handle, eUserType, pwd));

    return HVC_SUCCESS;
}

/**********************************************************
 * Closes the trap handler.
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
uint32 spinorEl2TrapClose( spinorTrapHandle_t *h, sailbsp_hvc_rsp_t *rsp )
{
    spinor_handle_t handle;
    uint32 *pwd;

    if (FALSE == gSpinorEl2TrapInitDone)
    {
        rsp->data[0] = SPINOR_DEVICE_FAIL;
        return HVC_SUCCESS;
    }

    handle = h->handle;
    pwd = h->pwd;

    if( (NULL == handle) || (NULL == pwd))
    {
        rsp->data[0] = SPINOR_DEVICE_INVALID_PARAMETER;
        return HVC_SUCCESS;
    }
    rsp->data[0] = ((uint32_t) el2Close( handle, pwd ));

    return HVC_SUCCESS;
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
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
uint32 spinorEl2TrapLowPower( spinorTrapHandle_t *h, uint32_t bLowPower, sailbsp_hvc_rsp_t *rsp )
{
    spinor_handle_t handle;
    uint32 *pwd;

    if (FALSE == gSpinorEl2TrapInitDone)
    {
        rsp->data[0] = SPINOR_DEVICE_FAIL;
        return HVC_SUCCESS;
    }

    handle = h->handle;
    pwd = h->pwd;

    if ( (NULL == handle) || (NULL == pwd))
    {
        rsp->data[0] = SPINOR_DEVICE_INVALID_PARAMETER;
        return HVC_SUCCESS;
    }

    rsp->data[0] = ((uint32_t)el2LowPower ( handle, (boolean)bLowPower, pwd) );

    return HVC_SUCCESS;
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
 * @param pRegion [IN/OUT]
 *   GPT partition start address and size
 *
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
uint32 spinorEl2TrapGetGptPartitionInfo( spinorTrapHandle_t *h, const char *guid, spinorTrapRegionInfo_t *pRegion, sailbsp_hvc_rsp_t *rsp )
{
    uint32 *pulStartAddr;
    uint32 *pulSize;
    spinor_handle_t handle;
    uint32 *pwd;

    if (FALSE == gSpinorEl2TrapInitDone)
    {
        rsp->data[0] = SPINOR_DEVICE_FAIL;
        return HVC_SUCCESS;
    }

    handle = h->handle;
    pwd = h->pwd;

    pulStartAddr = &pRegion->base;
    pulSize = &pRegion->size;

    if ( (NULL == handle) || (NULL == guid) || (NULL == pulStartAddr) || (NULL == pulSize) || (NULL == pwd))
    {
        rsp->data[0] = SPINOR_DEVICE_INVALID_PARAMETER;
        return HVC_SUCCESS;
    }
    rsp->data[0] = ((uint32_t)el2GetGptPartitionInfo( handle, guid, pulStartAddr, pulSize, pwd));

    return HVC_SUCCESS;
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
uint32 spinorEl2TrapGetSectorMapInfo( spinorTrapHandle_t *h, spinorSectorMapInfoType *secMapInfo, sailbsp_hvc_rsp_t *rsp )
{
    spinor_handle_t handle;
    uint32 *pwd;

    if (FALSE == gSpinorEl2TrapInitDone)
    {
        rsp->data[0] = SPINOR_DEVICE_FAIL;
        return HVC_SUCCESS;
    }

    handle = h->handle;
    pwd = h->pwd;

    if ( (NULL == handle) || (NULL == secMapInfo) || (NULL == pwd))
    {
        rsp->data[0] = SPINOR_DEVICE_INVALID_PARAMETER;
        return HVC_SUCCESS;
    }
    rsp->data[0] = ((uint32_t)el2GetSectorMapInfo( handle, secMapInfo, pwd));

    return HVC_SUCCESS;
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
uint32 spinorEl2TrapSetPartitionAttrib( spinorTrapHandle_t *h, const char *guid, eSpinorProtectType eAttrib, sailbsp_hvc_rsp_t *rsp )
{
    spinor_handle_t handle;
    uint32 *pwd;

    if (FALSE == gSpinorEl2TrapInitDone)
    {
        rsp->data[0] = SPINOR_DEVICE_FAIL;
        return HVC_SUCCESS;
    }

    handle = h->handle;
    pwd = h->pwd;

    if ( (NULL == handle) || (NULL == guid) || (SPINOR_PROTECT_MAX <= eAttrib) || (NULL == pwd))
    {
        rsp->data[0] = SPINOR_DEVICE_INVALID_PARAMETER;
        return HVC_SUCCESS;
    }
    rsp->data[0] = ((uint32_t)el2SetPartitionAttrib( handle, guid, eAttrib, pwd));

    return HVC_SUCCESS;
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
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
uint32 spinorEl2TrapGetPartitionAttrib( spinorTrapHandle_t *h, const char *guid, eSpinorProtectType* eAttrib, sailbsp_hvc_rsp_t *rsp )
{
    spinor_handle_t handle;
    uint32 *pwd;

    if (FALSE == gSpinorEl2TrapInitDone)
    {
        rsp->data[0] = SPINOR_DEVICE_FAIL;
        return HVC_SUCCESS;
    }

    handle = h->handle;
    pwd = h->pwd;

    if ( (NULL == handle) || (NULL == guid) || (NULL == eAttrib) || (NULL == pwd))
    {
        rsp->data[0] = SPINOR_DEVICE_INVALID_PARAMETER;
        return HVC_SUCCESS;
    }
    rsp->data[0] = ((uint32_t)el2GetPartitionAttrib( handle, guid, eAttrib, pwd));

    return HVC_SUCCESS;
}

/**********************************************************
 * Runs the Main function for the Operation
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
uint32 spinorEl2TrapMainfunction( spinorTrapHandle_t *h, sailbsp_hvc_rsp_t *rsp )
{
    spinor_handle_t handle;
    uint32 *pwd;

    if (FALSE == gSpinorEl2TrapInitDone)
    {
        rsp->data[0] = SPINOR_DEVICE_FAIL;
        return HVC_SUCCESS;
    }

    handle = h->handle;
    pwd = h->pwd;

    if ( (NULL == handle) ||  (NULL == pwd))
    {
        rsp->data[0] = SPINOR_DEVICE_INVALID_PARAMETER;
        return HVC_SUCCESS;
    }

    rsp->data[0] = ((uint32_t)el2Mainfunction( handle, TRUE, pwd));

    return HVC_SUCCESS;
}

/**********************************************************
 * Gets the result for the Operation
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
 uint32 spinorEl2TrapGetJobResult( spinorTrapHandle_t *h, sailbsp_hvc_rsp_t *rsp )
{
    spinor_handle_t handle;
    uint32 *pwd;

    if (FALSE == gSpinorEl2TrapInitDone)
    {
        rsp->data[0] = SPINOR_DEVICE_FAIL;
        return HVC_SUCCESS;
    }

    handle = h->handle;
    pwd = h->pwd;

    if ( (NULL == handle) ||  (NULL == pwd))
    {
        rsp->data[0] = SPINOR_DEVICE_INVALID_PARAMETER;
        return HVC_SUCCESS;
    }

    rsp->data[0] = ((uint32_t)el2GetJobResult( handle, TRUE, pwd));

    return HVC_SUCCESS;
}

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
SPINOR_STATUS spinorEl2TrapBincmd( spinorTrapHandle_t *h, void* bincmdParams, sailbsp_hvc_rsp_t *rsp)
{
    spinor_handle_t handle;
    uint32 *pwd;

    if (FALSE == gSpinorEl2TrapInitDone)
    {
        rsp->data[0] = SPINOR_DEVICE_FAIL;
        return HVC_SUCCESS;
    }

    handle = h->handle;
    pwd = h->pwd;

    if ( (NULL == handle) || (NULL == bincmdParams) ||  (NULL == pwd))
    {
        rsp->data[0] = SPINOR_DEVICE_INVALID_PARAMETER;
        return HVC_SUCCESS;
    }

    rsp->data[0] = ((uint32_t)el2Bincmd( handle, TRUE, bincmdParams, pwd));

    return HVC_SUCCESS;
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
uint32 spinorEl2TrapErase( spinorTrapHandle_t *h, uint32 start_block, uint32 block_count, sailbsp_hvc_rsp_t *rsp )
{
    spinor_handle_t handle;
    uint32 *pwd;

    if (FALSE == gSpinorEl2TrapInitDone)
    {
        rsp->data[0] = SPINOR_DEVICE_FAIL;
        return HVC_SUCCESS;
    }

    handle = h->handle;
    pwd = h->pwd;

    if ( (NULL == handle) || (0 == block_count) ||  (NULL == pwd))
    {
        rsp->data[0] = SPINOR_DEVICE_INVALID_PARAMETER;
        return HVC_SUCCESS;
    }

    rsp->data[0] = ((uint32_t)el2Erase( handle, TRUE, start_block, block_count, pwd));

    return HVC_SUCCESS;
}

/**********************************************************
 * Writes data to the spinor.
 *
 * @param handle [IN]
 *   SPINOR service interface handle
 *
 * @param pRWParams [IN]
 *   Byte offset from the start of the region to write to.
 *   Number of bytes to write data.
 *   Data buffer for spinor write operation.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
uint32 spinorEl2TrapWrite( spinorTrapHandle_t *h, spinorTrapRWRegionParam_t *pRWParams, sailbsp_hvc_rsp_t *rsp )
{
    spinor_handle_t handle;
    uint32 *pwd;
    uint32 byte_count,byte_offset;
    const void *buffer;

    if (FALSE == gSpinorEl2TrapInitDone)
    {
        rsp->data[0] = SPINOR_DEVICE_FAIL;
        return HVC_SUCCESS;
    }

    handle = h->handle;
    pwd = h->pwd;

    byte_count = pRWParams->byte_count;
    byte_offset = pRWParams->byte_offset;
    buffer = pRWParams->buffer;

    if ( (NULL == handle) || (0 == byte_count) || (NULL == buffer) || (NULL == pwd) )
    {
        rsp->data[0] = SPINOR_DEVICE_INVALID_PARAMETER;
        return HVC_SUCCESS;
    }

    if ( ( byte_offset % SPINOR_BYTES_ALIGNMENT ) || ( byte_count % SPINOR_BYTES_ALIGNMENT ) )
    {
        rsp->data[0] = SPINOR_ALIGNMENT;
        return HVC_SUCCESS;
    }
    rsp->data[0] = ((uint32_t)el2Write( handle, TRUE, byte_offset, byte_count, buffer, pwd ));

    return HVC_SUCCESS;
}

/**********************************************************
 * Allows read data from the spinor
 *
 * @param handle [IN]
 *   SPINOR service interface handle
 *
 * @param pRWParams [IN/OUT]
 *   Byte offset from the start of region to read from.
 *   Number of bytes to read data.
 *   Data buffer for a spinor read operation.
 *
 * @return int [OUT]
 *   Result of the operation.
 **********************************************************/
uint32 spinorEl2TrapRead( spinorTrapHandle_t *h, spinorTrapRWRegionParam_t *pRWParams, sailbsp_hvc_rsp_t *rsp )
{
    spinor_handle_t handle;
    uint32 *pwd;
    uint32 byte_count,byte_offset;
    void *buffer;

    if (FALSE == gSpinorEl2TrapInitDone)
    {
        rsp->data[0] = SPINOR_DEVICE_FAIL;
        return HVC_SUCCESS;
    }

    handle = h->handle;
    pwd = h->pwd;

    byte_count = pRWParams->byte_count;
    byte_offset = pRWParams->byte_offset;
    buffer = (void *)pRWParams->buffer;

    if ( (NULL == handle) || (0 == byte_count) || (NULL == buffer) || (NULL == pwd) )
    {
        rsp->data[0] = SPINOR_DEVICE_INVALID_PARAMETER;
        return HVC_SUCCESS;
    }

    if ( ( byte_offset % SPINOR_BYTES_ALIGNMENT ) || ( byte_count % SPINOR_BYTES_ALIGNMENT ) )
    {
        rsp->data[0] = SPINOR_ALIGNMENT;
        return HVC_SUCCESS;
    }
    rsp->data[0] = ((uint32_t)el2Read( handle, TRUE, byte_offset, byte_count, buffer, pwd));

    return HVC_SUCCESS;
}

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
uint32 spinorEl2TrapIsEl2InitDone(int type, sailbsp_hvc_rsp_t *rsp)
{
    if (FALSE == gSpinorEl2TrapInitDone)
    {
        rsp->data[0] = FALSE;
        return HVC_SUCCESS;
    }
    rsp->data[0] = ((uint32_t)spinorEl2IsInitDone(type));

    return HVC_SUCCESS;
}

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
uint32 spinorEl2TrapInitReadBufRegion(uint32_t ulAddr, uint32_t ulSize, sailbsp_hvc_rsp_t * rsp)
{
    if (FALSE == gSpinorEl2TrapInitDone)
    {
        rsp->data[0] = SPINOR_DEVICE_FAIL;
        return HVC_SUCCESS;
    }

    rsp->data[0] = ((uint32_t)el2InitReadBufRegion(ulAddr,  ulSize));

    return HVC_SUCCESS;
}

/**********************************************************
 * De-initialize OSPI EL1 data from EL2 driver
 *
 * @param void[IN]
 *   None
 *
 * @return int [OUT]
 *   Result of the operation
 *
 **********************************************************/
uint32 spinorEl2TrapEl1DeInit(sailbsp_hvc_rsp_t *rsp)
{
    if (FALSE == gSpinorEl2TrapInitDone)
    {
        rsp->data[0] = (uint32_t)0;
        return HVC_SUCCESS;
    }
    rsp->data[0] = 0;

    return HVC_SUCCESS;
}

/**********************************************************
 * Get memory info from spinor EL2.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @param pmemInfo [IN/OUT]
 *   Pointer to the structure that contains the memory info derived.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
uint32 spinorEl2TrapGetMemInfo(spinorTrapHandle_t *h, spinorMemInfoType *pMemInfo, sailbsp_hvc_rsp_t *rsp )
{
    spinor_handle_t handle;
    uint32 *pwd;

    if (FALSE == gSpinorEl2TrapInitDone)
    {
        rsp->data[0] = (uint32_t)FALSE;
        return HVC_SUCCESS;
    }

    handle = h->handle;
    pwd = h->pwd;

    if ( (NULL == handle) || (NULL == pwd))
    {
        rsp->data[0] = SPINOR_DEVICE_INVALID_PARAMETER;
        return HVC_SUCCESS;
    }

    rsp->data[0] = ((uint32_t)el2GetMemInfo( handle,pMemInfo, pwd));

    return HVC_SUCCESS;
}

/**********************************************************
 * Opens handle to a access to the spinor device
 *
 *
 * @param type [IN]
 *   SPINOR initialization type
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS spinorEl2TrapInit(void)
{
    gSpinorEl2TrapInitDone = TRUE;

    return SPINOR_DEVICE_DONE;
}

/**********************************************************
 * De-initialize OSPI EL2 Trap layer
 *
 * @param void[IN]
 *   None
 *
 * @return int [OUT]
 *   Result of the operation
 *
 **********************************************************/
SPINOR_STATUS spinorEl2TrapDeInit(void)
{
    gSpinorEl2TrapInitDone = FALSE;
    /* Register call back to trap system call module */
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
uint32 spinorEl2IsDeviceAlive(sailbsp_hvc_rsp_t *rsp)
{
  if (FALSE == gSpinorEl2TrapInitDone)
  {
      rsp->data[0] = SPINOR_DEVICE_FAIL;
      return HVC_SUCCESS;
  }

  rsp->data[0] = ((uint32_t)el2IsDeviceAlive());

  return HVC_SUCCESS;
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
uint32 spinorEl2DumpSFDP(sailbsp_hvc_rsp_t* rsp)
{
    if (FALSE == gSpinorEl2TrapInitDone)
    {
        rsp->data[0] = SPINOR_DEVICE_FAIL;
        return HVC_SUCCESS;
    }

    rsp->data[0] = ((uint32_t)el2SFDPDump());

    return HVC_SUCCESS;
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
uint32 spinorEl2TrapSWResetClose(uint32_t resetCoreID, sailbsp_hvc_rsp_t* rsp)
{
    if (FALSE == gSpinorEl2TrapInitDone)
    {
        rsp->data[0] = SPINOR_DEVICE_FAIL;
        return HVC_SUCCESS;
    }

    rsp->data[0] = ((uint32_t)el2SWResetClose(resetCoreID));

    return HVC_SUCCESS;
}

/**********************************************************
 * Get the usertype for the handle.
 *
 * @param handle [IN]
 *   SPINOR service interface handle.
 *
 * @param usertype [IN/OUT]
 *   Pointer to address that contains User type for the handle.
 *
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
uint32 spinorEl2TrapGetUserType( spinorTrapHandle_t *h, eSpinorUserType* usertype, sailbsp_hvc_rsp_t *rsp )
{
    spinor_handle_t handle;
    uint32 *pwd;

    if (FALSE == gSpinorEl2TrapInitDone)
    {
        rsp->data[0] = SPINOR_DEVICE_FAIL;
        return HVC_SUCCESS;
    }

    handle = h->handle;
    pwd = h->pwd;

    if ( (NULL == handle) ||  (NULL == usertype) || (NULL == pwd))
    {
        rsp->data[0] = SPINOR_DEVICE_INVALID_PARAMETER;
        return HVC_SUCCESS;
    }

    rsp->data[0] = ((uint32_t)el2GetUserType(  handle, usertype, pwd));

    return HVC_SUCCESS;
}

/**********************************************************
 * Try lock for the resource.
 *
 * @param coreid [IN]
 *   core id acquiring the lock.
 *
 *
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
uint32 spinorEl2TrapResLock( uint32_t coreid, sailbsp_hvc_rsp_t *rsp )
{
    spinor_handle_t handle;
    uint32 *pwd;

    if (FALSE == gSpinorEl2TrapInitDone)
    {
        rsp->data[0] = FALSE;
        return HVC_SUCCESS;
    }

    rsp->data[0] = ((uint32_t)el2MultiCoreSafeResTry(coreid, TRUE));

    return HVC_SUCCESS;
}

/**********************************************************
 * Unlock for the resource.
 *
 * @param coreid [IN]
 *   core id releasing the lock.
 *
 *
 * @return int [OUT]
 *   status of the operation.
 *
 **********************************************************/
uint32 spinorEl2TrapResUnlock( uint32_t coreid, sailbsp_hvc_rsp_t *rsp )
{
    spinor_handle_t handle;
    uint32 *pwd;

    if (FALSE == gSpinorEl2TrapInitDone)
    {
        rsp->data[0] = FALSE;
        return HVC_SUCCESS;
    }

    rsp->data[0] = ((uint32_t)el2MultiCoreSafeResRemove(coreid, TRUE));

    return HVC_SUCCESS;
}

/**********************************************************
 * Trap Interface for the HVC calls
 *
 * @param eventID [IN]
 *   SPINOR Event ID.
 *
 * @param trapParam [IN/OUT]
 *   SPINOR parameters.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
uint32 spinorEl2TrapInterface(spinorTrapEventID_t eventID, spinorTrapParams_t* trapParam,sailbsp_hvc_rsp_t *rsp)
{
    switch (eventID)
    {
        case SAIL_SPINOR_FUNC_INIT:
            return spinorEl2TrapIsEl2InitDone(trapParam->initParam.type, rsp);
        case SAIL_SPINOR_FUNC_INIT_READBUF_REG:
            return spinorEl2TrapInitReadBufRegion(trapParam->readBufRegParam.addr, trapParam->readBufRegParam.size, rsp);
        case SAIL_SPINOR_FUNC_DEINIT:
            return spinorEl2TrapEl1DeInit(rsp);
        case SAIL_SPINOR_FUNC_OPEN:
            return spinorEl2TrapOpen(trapParam->openParam.h, trapParam->openParam.eUserType, rsp);
        case SAIL_SPINOR_FUNC_CLOSE:
            return spinorEl2TrapClose(trapParam->closeParam.h, rsp);
        case SAIL_SPINOR_FUNC_GET_PARTITION_INFO:
            return spinorEl2TrapGetGptPartitionInfo(trapParam->gptPartInfoParam.h, (const char *)trapParam->gptPartInfoParam.guid, trapParam->gptPartInfoParam.pRegion, rsp);
        case SAIL_SPINOR_FUNC_ERASE:
            return spinorEl2TrapErase(trapParam->eraseParam.h, trapParam->eraseParam.start_block, trapParam->eraseParam.block_count, rsp);
        case SAIL_SPINOR_FUNC_BINCMD:
            return spinorEl2TrapBincmd(trapParam->bincmdParam.h, (void*)trapParam->bincmdParam.cmdparams, rsp);
        case SAIL_SPINOR_FUNC_WRITE:
            return spinorEl2TrapWrite(trapParam->writeParam.h, trapParam->writeParam.pRWParams, rsp);
        case SAIL_SPINOR_FUNC_READ:
            return spinorEl2TrapRead(trapParam->readParam.h, trapParam->readParam.pRWParams, rsp);
        case SAIL_SPINOR_FUNC_LOWPOWER:
            return spinorEl2TrapLowPower(trapParam->lowPowerParam.h, trapParam->lowPowerParam.bLowPower, rsp);
        case SAIL_SPINOR_FUNC_GET_MEMINFO:
            return spinorEl2TrapGetMemInfo(trapParam->getMemInfoParam.h, trapParam->getMemInfoParam.pMemInfo, rsp);
        case SAIL_SPINOR_FUNC_IS_DEVICE_ALIVE:
            return spinorEl2IsDeviceAlive(rsp);
        case SAIL_SPINOR_FUNC_SFDP_DUMP:
            return spinorEl2DumpSFDP(rsp);
        case SAIL_SPINOR_FUNC_SET_PARTITION_ATTRIB:
            return spinorEl2TrapSetPartitionAttrib(trapParam->setPartAttribParam.h, (const char *)trapParam->setPartAttribParam.guid, trapParam->setPartAttribParam.eAttrib, rsp);
        case SAIL_SPINOR_FUNC_GET_PARTITION_ATTRIB:
            return spinorEl2TrapGetPartitionAttrib(trapParam->getPartAttribParam.h, (const char *)trapParam->getPartAttribParam.guid, trapParam->getPartAttribParam.eAttrib, rsp);
        case SAIL_SPINOR_FUNC_MAINFUNC:
            return spinorEl2TrapMainfunction(trapParam->mainFuncParam.h, rsp);
        case SAIL_SPINOR_FUNC_GETJOBRESULT:
            return spinorEl2TrapGetJobResult(trapParam->getJobResParam.h, rsp);
        case SAIL_SPINOR_FUNC_SWRESETCLOSE:
            return spinorEl2TrapSWResetClose(trapParam->resetCloseParam.resetCoreID, rsp);
        case SAIL_SPINOR_FUNC_GETUSERTYPE:
            return spinorEl2TrapGetUserType(trapParam->getUserTypeParam.h, trapParam->getUserTypeParam.userType, rsp);
        case SAIL_SPINOR_FUNC_RESLOCK:
            return spinorEl2TrapResLock(trapParam->resLockParam.coreid, rsp);
        case SAIL_SPINOR_FUNC_RESUNLOCK:
            return spinorEl2TrapResUnlock(trapParam->resLockParam.coreid, rsp);
        case SAIL_SPINOR_FUNC_GET_SECTOR_MAP_INFO:
            return spinorEl2TrapGetSectorMapInfo(trapParam->secMapInfoParam.h, (spinorSectorMapInfoType*)trapParam->secMapInfoParam.secMapInfo, rsp);
        default:
            rsp->data[0] = SPINOR_DEVICE_FAIL;
            break;
    }

    return HVC_SUCCESS;
}

/**********************************************************
 *
 *
 * SPINOR service trap systemcall interface primitives
 *
 *
 **********************************************************/

/* SYS CALL DECLARATIONS */

SAIL_DEFINE_SYSCALL(  SAIL_SPINOR_FUNC_TRAP,
                      SAIL_SPINOR_FUNC_TRAP_PARAM_ID,
                      0,
                      spinorEl2TrapInterface
                    );

