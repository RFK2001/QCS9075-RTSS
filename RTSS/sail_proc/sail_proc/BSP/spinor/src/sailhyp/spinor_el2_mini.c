/*
===========================================================================
*/
/**
    @file  spinor_el2_mini.c
    @brief SPI NOR EL2 mini framework structure implementation for crash debug

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

    $Header: //components/rel/bsp.sail/1.0/spinor/src/sailhyp/spinor_el2_mini.c#6 $
    $DateTime: 2025/07/23 15:33:51 $
    $Author: pwbldsvc $

    ===========================================================================
*/

#include "spinor_el2_api.h"
#include "spinor_el2_mini.h"
#include "spinor_api.h"
#include "blacklist.h"
#include "fd_mgr.h"
#include "gpt_p1.h"
#include "spinor_el2_trap.h"
#include "gpt_partition1.h"
#include "sailbsp_mutex.h"
#include "spinor_diag.h"

#include "debug_log.h"


static spinor_el2_mini_struct_type gxEl2MiniStruct;

/**********************************************************
 * Reads from a GPT partition
 *
 * @param ulStartByte [IN]
 *   GPT partition start address.
 *
 * @param ulSize [OUT]
 *   GPT partition size.
 *
 * @param pBuf [OUT]
 *   Pointer to the buffer containing the data read out.
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
static uint32_t gptReadCbMini (uint8_t *pBuf, uint32_t ulStartByte, uint32_t ulSize)
{
    SPINOR_STATUS ret = spinor_read ( gxEl2MiniStruct.spinorHandle, ulStartByte, ulSize, pBuf );
    if ( ret == SPINOR_DEVICE_DONE )
    {
        return ulSize;
    }
    else
    {
		SPINOR_LOG_ERROR_EL2("%s: Error, read failed \r\n", __func__);
        return 0;
    }
}

/**********************************************************
 * Initialize OSPI EL2 mini driver
 *
 * @param type [IN]
 *   Type of initialization
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
int el2MiniInit( int type, uint8_t *puWorkBuf, uint32_t ulBufLen, spinor_hardcode_data_mode *hardcoded_data_mode)
{
    SPINOR_STATUS ret = SPINOR_DEVICE_FAIL;

    memset(&gxEl2MiniStruct, 0, sizeof(gxEl2MiniStruct));
    gxEl2MiniStruct.puWorkBuf = puWorkBuf;
    gxEl2MiniStruct.ulBufLen = ulBufLen;

    ret = spinor_init(type, hardcoded_data_mode);
    do {
        if (ret != SPINOR_DEVICE_DONE)
        {
			SPINOR_LOG_ERROR_EL2("%s: Error, init failed \r\n", __func__);
            break;
        }
        if ( SPINOR_DEVICE_DONE != spinor_open ( &gxEl2MiniStruct.spinorHandle ) )
        {
            spinor_deinit();
			SPINOR_LOG_ERROR_EL2("%s: Error, open failed \r\n", __func__);
            ret = SPINOR_DEVICE_FAIL;
            break;
        }

        ret = spinor_get_info ( gxEl2MiniStruct.spinorHandle, &gxEl2MiniStruct.spinorInfo );
        if (ret != SPINOR_DEVICE_DONE)
        {
            spinor_close (gxEl2MiniStruct.spinorHandle);
            spinor_deinit();
			SPINOR_LOG_ERROR_EL2("%s: Error, get info failed \r\n", __func__);
            ret = SPINOR_DEVICE_FAIL;
            break;
        }
        if (FALSE == gptPartitionInit(gxEl2MiniStruct.spinorInfo.block_count, gptReadCbMini, gxEl2MiniStruct.puWorkBuf,
                                      gxEl2MiniStruct.ulBufLen, SPINOR_BYTES_ALIGNMENT))
        {
            spinor_close (gxEl2MiniStruct.spinorHandle);
            spinor_deinit();
			SPINOR_LOG_ERROR_EL2("%s: Error, gpt partition init failed \r\n", __func__);
            ret = SPINOR_DEVICE_FAIL;
            break;
        }
    }while (0);

    if (ret != SPINOR_DEVICE_DONE)
    {
        memset(&gxEl2MiniStruct, 0, sizeof(gxEl2MiniStruct));
    }
    return (int)ret;
}

/**********************************************************
 * De-initialize OSPI EL2 driver
 *
 * @param none
 *
 * @return void [OUT]
 *
 **********************************************************/
void el2MiniDeinit( void )
{
    if (gxEl2MiniStruct.spinorHandle)
    {
        gptPartitionDeInit();
        spinor_close ( gxEl2MiniStruct.spinorHandle );
        spinor_deinit();
        memset(&gxEl2MiniStruct, 0, sizeof(gxEl2MiniStruct));
    }
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
 * @param pwd [IN/OUT]
 *   Pointer to hold the password for the client as input parameter
 *   Updated password to be used for further transactions upon return on success of the operation
 *
 * @return int [OUT]
 *   Result of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2MiniOpen( spinor_handle_t *handle, eSpinorUserType eUserType, uint32_t *pwd)
{
    if (gxEl2MiniStruct.spinorHandle)
    {
        *handle = (spinor_handle_t *)SPINOR_EL2_CRASH_DEBUG_HANDLE;
         return SPINOR_DEVICE_DONE;
    }
    else
    {
        /* It is in mission mode, mini EL2 is not supported */
		SPINOR_LOG_ERROR_EL2("%s: Error, invalid handle \r\n", __func__);
        return SPINOR_DEVICE_NOT_SUPPORTED;
    }
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
SPINOR_STATUS el2MiniClose( spinor_handle_t handle, uint32_t *pwd)
{
    *pwd = 0;
    return SPINOR_DEVICE_DONE;
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
SPINOR_STATUS el2MiniGetMemInfo(spinor_handle_t handle, spinorMemInfoType *pmemInfo, uint32_t *pwd)
{
    SPINOR_STATUS ret = SPINOR_DEVICE_DONE;
    if (NULL == pmemInfo || sizeof(spinorMemInfoType) != sizeof(gxEl2MiniStruct.spinorInfo))
    {
		SPINOR_LOG_ERROR_EL2("%s: Error, invalid parameters \r\n", __func__);
        ret =  SPINOR_DEVICE_FAIL;
    }
    else
    {
        *pmemInfo = gxEl2MiniStruct.spinorInfo;
    }
    return ret;
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
 *   status of the operation.
 *
 **********************************************************/
SPINOR_STATUS el2MiniGetGptPartitionInfo( spinor_handle_t handle, const char *guid, uint32_t *pulStartAddr, uint32_t *pulSize, uint32_t *pwd)
{
    boolean status;
    guid_t tmpGuid;
    SPINOR_STATUS ret = SPINOR_DEVICE_DONE;

    if (FALSE == gptPartitionDecodeGUIDString((const char*)guid, &tmpGuid))
    {
		SPINOR_LOG_ERROR_EL2("%s: Error, gpt partition string decode fail \r\n", __func__);
        ret = SPINOR_DEVICE_FAIL;
    }
    else
    {
        status = gptGetPartitionInfo(&tmpGuid, pulStartAddr, pulSize);
        if (FALSE == status)
        {
            *pulStartAddr = 0;
            *pulSize = 0;
			SPINOR_LOG_ERROR_EL2("%s: Error, get gptpartition info failed \r\n", __func__);
            ret = SPINOR_DEVICE_FAIL;
        }
    }
    return ret;
}

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
SPINOR_STATUS el2MiniErase( spinor_handle_t handle, boolean bTrap, uint32 start_block, uint32 block_count, uint32_t *pwd)
{
    SPINOR_STATUS ret;

    ret = spinor_erase( gxEl2MiniStruct.spinorHandle, start_block, block_count );
    return ret;
}

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
SPINOR_STATUS el2MiniWrite( spinor_handle_t handle, boolean bTrap, uint32 byte_offset, uint32 byte_count, const void *buffer, uint32_t *pwd)
{
    SPINOR_STATUS ret = SPINOR_DEVICE_DONE;

    ret = spinor_write ( gxEl2MiniStruct.spinorHandle, byte_offset, byte_count, buffer );
    return ret;
}

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
SPINOR_STATUS el2MiniRead ( spinor_handle_t handle, boolean bTrap, uint32 byte_offset, uint32 byte_count, void *buffer, uint32_t *pwd)
{
    SPINOR_STATUS ret = SPINOR_DEVICE_DONE;

    ret = spinor_read ( gxEl2MiniStruct.spinorHandle, byte_offset, byte_count, buffer );
    return ret;
}
