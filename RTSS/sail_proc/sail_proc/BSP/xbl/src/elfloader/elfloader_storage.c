/*
===========================================================================
*/
/**
    @file  elfloader_storage.c
    @brief Implementation of elf loader storage read functionality

*/
/*
    ===========================================================================

    Copyright (c) 2022-2023 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/xbl/src/elfloader/elfloader_storage.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "types.h"
#include "elf_header.h"
#include "spinor_el2_api.h"
#include "xbl_def.h"
#include "xbl_mem.h"
#include "xbl_diag.h"
#include "elfloader_storage.h"

typedef struct XblStorageType_s
{
    eXblStorageType StorageType;
    uint32_t ulRamBase;
    uint32_t ulRamSize;
} XblStorageType_t;

//static spinor_handle_t g_spinor_handle;
static XblStorageType_t g_XblStorage;


/*************************************NOR-FLASH APIs*************************************/
static void *nStorageNorOpen(void)
{
    SPINOR_STATUS spinor_status;
    spinor_handle_t phandle = NULL;
    
    do
    {
        spinor_status = spinorEl2Open ( &phandle, SPINOR_USER_TYPE_BOOT_LOADER );
        if ( SPINOR_DEVICE_DONE != spinor_status)
        {
            XBL_LOG_ERROR("%s: error, spinorEl2Open status = %d\n\r", __func__, spinor_status);
            phandle = NULL;
            break;
        }
        spinor_status = spinorEl2SetBootMode ( phandle, TRUE );
        if ( SPINOR_DEVICE_DONE != spinor_status )
        {
            // not expecting this error
            spinor_status = spinorEl2Close( phandle );
            if(spinor_status != SPINOR_DEVICE_DONE)
            {
                XBL_LOG_ERROR("%s: error, spinorEl2Close failed, status = %d\n\r", __func__, spinor_status);
            }
            phandle = NULL;
            XBL_LOG_ERROR("%s: error, spinorEl2SetBootMode status = %d\n\r", __func__, spinor_status);
            break;
        }
    } while (0U);
    return phandle;
}
static void xStorageNorClose(void *pHandle)
{
    SPINOR_STATUS spinor_status;
    if (pHandle != NULL)
    {
        (void)spinorEl2SetBootMode(pHandle, FALSE);
        spinor_status = spinorEl2Close( pHandle );
        if(spinor_status != SPINOR_DEVICE_DONE)
        {
            XBL_LOG_ERROR("%s: error, spinorEl2Close failed, status = %d\n\r", __func__, spinor_status);
        }
    }
}
static int nStorageNorGetPartition ( void *pHandle, const char *guidString, uint32_t *pulStartAddr, uint32_t *pulSize )
{
    if (NULL == guidString || NULL == pulStartAddr || NULL == pulSize)
    {
        XBL_LOG_ERROR("%s: error, guidString = 0x%x, pulStartAddr = 0x%x, pulSize = 0x%x\n\r",
                      __func__, (uint32_t)guidString, (uint32_t)pulStartAddr, (uint32_t)pulSize);
        return XBL_ERROR_INVALID_PARAM;
    }
    SPINOR_STATUS spinor_ret = spinorEl2GetGptPartitionInfo ( pHandle, guidString, pulStartAddr, pulSize );
    if (spinor_ret != SPINOR_DEVICE_DONE || *pulSize == 0U)
    {
        XBL_LOG_ERROR("%s: error, spinorEl2GetGptPartitionInfo ret = %d\n\r", __func__, spinor_ret);
        return XBL_ERROR_NO_PARTITION;
    }
    return XBL_SUCCESS;
}

static int nStorageNorRead ( void *pHandle, uint32_t nStartOffset, uint32_t nSize, uint8_t *buf )
{
    SPINOR_STATUS spinor_ret;
    if (NULL == buf || nSize == 0U)
    {
        XBL_LOG_ERROR("%s: error, buf = 0x%x, size = 0x%x\n\r", __func__, buf, nSize);
        return XBL_ERROR_INVALID_PARAM;
    }
    spinor_ret = spinorEl2Read ( pHandle, nStartOffset, nSize, buf );
    if (spinor_ret != SPINOR_DEVICE_DONE)
    {
        XBL_LOG_ERROR("%s: error, spinorEl2Read status = %d\n\r", __func__, spinor_ret);
        return XBL_ERROR_READ_STORAGE;
    }
    return XBL_SUCCESS;
}

static int nStorageNorErase ( void *pHandle, uint32 start_block, uint32 block_count )
{
    SPINOR_STATUS spinor_ret;
    if ( block_count == 0U)
    {
        XBL_LOG_ERROR("%s: error, block_count = 0x%x\n\r", __func__,block_count);
        return XBL_ERROR_INVALID_PARAM;
    }
    spinor_ret = spinorEl2Erase( pHandle, start_block, block_count);
    if (spinor_ret != SPINOR_DEVICE_DONE)
    {
        XBL_LOG_ERROR("%s: error, spinorEl2Read status = %d\n\r", __func__, spinor_ret);
        return XBL_ERROR_STORAGE_DRIVER;
    }
    return XBL_SUCCESS;
}

static int nStorageNorGetMemInfo ( void *pHandle, uint32 *block_count, uint32 *pages_per_block, uint32 *page_size_bytes )
{
    SPINOR_STATUS spinor_ret;
    spinorMemInfoType memInfo;

    if ( block_count == NULL || pages_per_block == NULL || page_size_bytes == NULL )
    {
        XBL_LOG_ERROR("%s: error, invalid parameters\n\r", __func__);
        return XBL_ERROR_INVALID_PARAM;
    }

    spinor_ret = spinorEl2GetMemInfo( pHandle, &memInfo);
    if ( spinor_ret != SPINOR_DEVICE_DONE )
    {
        XBL_LOG_ERROR("%s: error, spinorEl2GetMemInfo status = %d\n\r", __func__, spinor_ret);
        return XBL_ERROR_STORAGE_DRIVER;
    }

    *block_count = memInfo.block_count;
    *pages_per_block = memInfo.pages_per_block;
    *page_size_bytes = memInfo.page_size_bytes;

    return XBL_SUCCESS;
}
/****************************************************************************************/

void vStorageInit(void)
{
    g_XblStorage.StorageType = XBL_STORAGE_NOR_FLASH;
    g_XblStorage.ulRamBase = 0UL;
    g_XblStorage.ulRamSize = 0UL;
}

int nStorageOpen(void **ppHandle)
{
    int ret = XBL_SUCCESS;
    if (g_XblStorage.StorageType == XBL_STORAGE_NOR_FLASH)
    {
        *ppHandle = nStorageNorOpen();
        if (NULL == *ppHandle)
        {
            ret = XBL_ERROR_STORAGE_OPEN;
            XBL_LOG_ERROR("%s: error\n\r", __func__);
        }
        else
        {
            XBL_LOG_INFO("%s: handle = 0x%x\n\r", __func__, *ppHandle);
        }
    }
    return ret;
}

void xStorageClose(void *pHandle)
{
    if (g_XblStorage.StorageType == XBL_STORAGE_NOR_FLASH && pHandle != NULL)
    {
        xStorageNorClose(pHandle);
        XBL_LOG_INFO("%s: handle = 0x%x\n\r", __func__,pHandle);
    }
}

int nStorageUpdate(eXblStorageType eType, uint32_t ulRamBase, uint32_t ulRamSize)
{
    g_XblStorage.StorageType = eType;
    g_XblStorage.ulRamBase = ulRamBase;
    g_XblStorage.ulRamSize = ulRamSize;
    return XBL_SUCCESS;
}

int nStorageRead( void *pHandle, uint32_t nStartOffset, uint32_t nSize, uint8_t *buf)
{
    int ret = XBL_SUCCESS;
    if (g_XblStorage.StorageType == XBL_STORAGE_NOR_FLASH)
    {
        ret = nStorageNorRead( pHandle, nStartOffset, nSize, buf);
    }
    else
    {
        (void)memcpy(buf, (uint8_t*)nStartOffset, nSize);
    }
    return ret;
}

int nStorageErase( void *pHandle, uint32 start_block, uint32 block_count)
{
    int ret = XBL_SUCCESS;
    if (g_XblStorage.StorageType == XBL_STORAGE_NOR_FLASH)
    {
        ret = nStorageNorErase( pHandle, start_block, block_count);
    }
    else
    {
        return XBL_ERROR_STORAGE_DRIVER;
    }
    return ret;
}

int nStorageGetMemInfo( void *pHandle, uint32 *block_count, uint32 *pages_per_block, uint32 *page_size_bytes)
{
    int ret = XBL_SUCCESS;
    if (g_XblStorage.StorageType == XBL_STORAGE_NOR_FLASH)
    {
        ret = nStorageNorGetMemInfo( pHandle, block_count, pages_per_block, page_size_bytes);
    }
    else
    {
        /**** StorageType = DDR **** Memory Size Hard set 2MB ****/
        *block_count = g_XblStorage.ulRamSize/4096U;
        *pages_per_block = 4096U/256U;
        *page_size_bytes = 256U;
    }
    return ret;
}

int nStorageGetPartition( void *pHandle, const char *guidString, uint32_t *pulStartAddr, uint32_t *pulSize)
{
    int ret = XBL_SUCCESS;
    if (g_XblStorage.StorageType == XBL_STORAGE_NOR_FLASH)
    {
        if (NULL == pHandle)
        {
            XBL_LOG_ERROR("%s: Error, null handle\n\r", __func__);
        }
        else
        {
            ret = nStorageNorGetPartition( pHandle, guidString, pulStartAddr, pulSize);
        }
    }
    else
    {
        *pulStartAddr = g_XblStorage.ulRamBase;
        *pulSize = g_XblStorage.ulRamSize;
    }
    return ret;
}

