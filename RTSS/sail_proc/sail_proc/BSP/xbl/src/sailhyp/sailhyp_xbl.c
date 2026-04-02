/*
===========================================================================
*/
/**
    @file  sailhyp_xbl.c
    @brief sailhyp xbl implementation
*/
/*
    ===========================================================================

    Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
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



/*===========================================================================
                               INCLUDE FILES
===========================================================================*/
#include <stdlib.h>
#include <stdbool.h>
#include "types.h"
#include "common_functions.h"
#include "target.h"
#include "elfloader.h"
#include "xbl_def.h"
#include "sailhyp_xbl.h"
#include "sailhyp_xbl_api.h"
#include "sailhyp_xbl_guid.h"
#ifdef XBL_USE_WHITELIST
#include "sailhyp_xbl_whitelist.h"
#endif
#include "sailbsp_mutex.h"
#include "xbl_mem.h"
#include "xbl_diag.h"
#include "timetick.h"
#include "gpt_partition1.h"
#include "spinor_cm_defs.h"
#include "pbl_shared_data.h"
#include "debug_log.h"
#include "err_fatal.h"
#include "elfloader_loadlist.h"
#include "elfloader_storage.h"
#include "sail_updater_el2.h"
#include "common_functions.h"

/*===========================================================================
                           MACROS
===========================================================================*/


/*===========================================================================
                               VARIABLES
============================================================================*/
#define XBL_MAX_CORE_ID_NUM    4

#define XBL_GPT_WORK_BUF_SIZE     4096

static uint64_t gXblExitTime[XBL_MAX_CORE_ID_NUM];
static uint64_t gXblEnterTime[XBL_MAX_CORE_ID_NUM];

/*This buffer is not used for any operation in xbl code */
//static uint8_t guXBLgptWorkBuf[XBL_GPT_WORK_BUF_SIZE] __attribute__ ((aligned(EL_SHARED_CACHELINE_SIZE))); /* align to cache line in case doing cache invalidation only */

typedef struct
{
    /*uint8_t* pGPTWorkBuf; */ /*This buffer is not used for any operation in xbl code */
    gptHeader_t PrimaryGPTHdr;
    gptHeader_t SecondaryGPTHdr;
    gptEntryRead gptEntryReadCb;
    uint32_t storageBlockCnt;
    uint32_t gptId;
    eXblStorageType eStorageType;
    uint32_t ulRamBase;
    uint32_t ulRamSize;
    boolean bootType;
} XBLCtxType;

static XBLCtxType gXBLHypCtx = {0};

static void vSetEnterTime(uint32_t coreId)
{
    if (coreId < XBL_MAX_CORE_ID_NUM)
    {
        gXblEnterTime[coreId] = timetick_get64();
    }
}

static void vSetExitTime(uint32_t coreId)
{
    if (coreId < XBL_MAX_CORE_ID_NUM)
    {
        gXblExitTime[coreId] = timetick_get64();
    }
}
static uint64_t uulGetXblDurationUs(uint32_t coreId)
{
    uint64_t durationUs = 0xFFFFFFFF;
    if (coreId < XBL_MAX_CORE_ID_NUM &&  gXblExitTime[coreId] >= gXblEnterTime[coreId])
    {
        /* QTimer runs at 19.2MHz */
        durationUs = (gXblExitTime[coreId] - gXblEnterTime[coreId]) * 10 /192;
    }
    return durationUs;
}

static int nGetHypBootInfoFromPblSharedInfo_lemans(void *pbl_shared_info, xbl_boot_image_info_t *imgInfo)
{
    pbl_sail_tee_shared_data_type_v1 *tee = (pbl_sail_tee_shared_data_type_v1*)pbl_shared_info;
    boot_flash_shared_dev_info_type *pDevInfo = NULL;

    if( imgInfo == NULL || tee == NULL || (tee->sail_tee_sdata_version  != PBL_SAIL_TEE_SHARED_DATA_VERSION_V1))
    {
        XBL_LOG_INFO("%s: Invalid PBL_SHARED_INFO Error\n\r", __func__);
        return XBL_ERROR;
    }
    pDevInfo = (boot_flash_shared_dev_info_type*)tee->pbl_flash_shared_data;
    if( pDevInfo == NULL)
    {
        XBL_LOG_INFO("%s: Invalid PBL_SHARED_INFO Error\n\r", __func__);
        return XBL_ERROR;
    }
    imgInfo->partition_id = (pDevInfo->is_secondary_guid == FALSE) ? XBL_PARTITION_A : XBL_PARTITION_B;
    imgInfo->gpt_id = (pDevInfo->dev_info.spi.is_primary_table == TRUE) ? XBL_GPT_TABLE_PRIMARY : XBL_GPT_TABLE_SECONDARY;

    return XBL_SUCCESS;
}

static int nGetHypBootInfoFromPblSharedInfo_monaco(void *pbl_shared_info, xbl_boot_image_info_t *imgInfo)
{
    pbl_sail_tee_shared_data_type_v2 *tee = (pbl_sail_tee_shared_data_type_v2*)pbl_shared_info;
    boot_flash_shared_dev_info_type *pDevInfo = NULL;

    if( imgInfo == NULL || tee == NULL || (tee->sail_tee_sdata_version != PBL_SAIL_TEE_SHARED_DATA_VERSION_V2))
    {
        XBL_LOG_INFO("%s: Invalid PBL_SHARED_INFO Error\n\r", __func__);
        return XBL_ERROR;
    }
    pDevInfo = (boot_flash_shared_dev_info_type*)tee->pbl_flash_shared_data;
    if( pDevInfo == NULL)
    {
        XBL_LOG_INFO("%s: Invalid PBL_SHARED_INFO Error\n\r", __func__);
        return XBL_ERROR;
    }
    imgInfo->partition_id = (pDevInfo->is_secondary_guid == FALSE) ? XBL_PARTITION_A : XBL_PARTITION_B;
    imgInfo->gpt_id = (pDevInfo->dev_info.spi.is_primary_table == TRUE) ? XBL_GPT_TABLE_PRIMARY : XBL_GPT_TABLE_SECONDARY;

    return XBL_SUCCESS;
}

static xbl_boot_image_info_t boot_image_info_array[XBL_IMAGE_ID_MAX] =
{
    {
        .img_name = "SAIL_SW1",
        .core_id = CORE_ID_INVALID,
        .image_id = XBL_IMAGE_ID_SW1,
        .status = FALSE,
        .partition_id = XBL_PARTITION_NULL,
        .gpt_id = XBL_GPT_TABLE_NULL,
        .image_entry = 0UL,
        .is_updatable = TRUE,
        .start_time = 0UL,
        .end_time = 0UL,
        .durationUs = 0UL
    },
    {
        .img_name = "SAIL_SW2",
        .core_id = CORE_ID_INVALID,
        .image_id = XBL_IMAGE_ID_SW2,
        .status = FALSE,
        .partition_id = XBL_PARTITION_NULL,
        .gpt_id = XBL_GPT_TABLE_NULL,
        .image_entry = 0UL,
        .is_updatable = TRUE,
        .start_time = 0UL,
        .end_time = 0UL,
        .durationUs = 0UL},
    {
        .img_name = "SAIL_SW3",
        .core_id = CORE_ID_INVALID,
        .image_id = XBL_IMAGE_ID_SW3,
        .status = FALSE,
        .partition_id = XBL_PARTITION_NULL,
        .gpt_id = XBL_GPT_TABLE_NULL,
        .image_entry = 0UL,
        .is_updatable = TRUE,
        .start_time = 0UL,
        .end_time = 0UL,
        .durationUs = 0UL
    },
    {
        .img_name = "SAIL_SW4",
        .core_id = CORE_ID_INVALID,
        .image_id = XBL_IMAGE_ID_SW4,
        .status = FALSE,
        .partition_id = XBL_PARTITION_NULL,
        .gpt_id = XBL_GPT_TABLE_NULL,
        .image_entry = 0UL,
        .is_updatable = TRUE,
        .start_time = 0UL,
        .end_time = 0UL,
        .durationUs = 0UL
    },
    {
        .img_name = "SAIL_SEC_ELF",
        .core_id = CORE_ID_INVALID,
        .image_id = XBL_IMAGE_ID_SEC_ELF,
        .status = FALSE,
        .partition_id = XBL_PARTITION_NULL,
        .gpt_id = XBL_GPT_TABLE_NULL,
        .image_entry = 0UL,
        .is_updatable = FALSE,
        .start_time = 0UL,
        .end_time = 0UL,
        .durationUs = 0UL
    },
    {
        .img_name = "SAIL_DBG_POLICY",
        .core_id = CORE_ID_INVALID,
        .image_id = XBL_IMAGE_ID_DBG_POLICY,
        .status = FALSE,
        .partition_id = XBL_PARTITION_NULL,
        .gpt_id = XBL_GPT_TABLE_NULL,
        .image_entry = 0UL,
        .is_updatable = FALSE,
        .start_time = 0UL,
        .end_time = 0UL,
        .durationUs = 0UL
    },
    {
        .img_name = "SAIL_HYP",
        .core_id = CORE_ID_INVALID,
        .image_id = XBL_IMAGE_ID_HYP,
        .status = FALSE,
        .partition_id = XBL_PARTITION_NULL,
        .gpt_id = XBL_GPT_TABLE_NULL,
        .image_entry = 0UL,
        .is_updatable = TRUE,
        .start_time = 0UL,
        .end_time = 0UL,
        .durationUs = 0UL
    }
};

static mutex_t xMutex;
static void init_boot_image_info(uint8_t coreId, xbl_boot_image_info_t *boot_image_info)
{
    boot_image_info->core_id      = coreId;
    boot_image_info->status       = FALSE;
    boot_image_info->partition_id = XBL_PARTITION_NULL;
    boot_image_info->gpt_id       = XBL_GPT_TABLE_NULL;
    boot_image_info->image_entry  = 0UL;
    boot_image_info->start_time   = timetick_get64();
    boot_image_info->end_time     = 0UL;
    boot_image_info->durationUs   = 0UL;
}
static void finalize_boot_image_info(int ret, xbl_boot_image_info_t *boot_image_info)
{
    boot_image_info->end_time = timetick_get64();

    /* Qtimer runs at 19.2MHz */
    boot_image_info->durationUs = (boot_image_info->end_time - boot_image_info->start_time) * 10;
    boot_image_info->durationUs /= 192;
    XBL_LOG_INFO("%s ret = %d, coreid = %d, imgid = %d, loaded = %d, partition = %d, gpt = %d, entry = 0x%x, 0x%llu, 0x%llu, %d\n\r",
                 __func__, ret, boot_image_info->core_id, boot_image_info->image_id,
                 boot_image_info->status, boot_image_info->partition_id, boot_image_info->gpt_id,
                 boot_image_info->image_entry, boot_image_info->start_time, boot_image_info->end_time,
                 (int32_t)boot_image_info->durationUs);
}

static int sailhyp_xbl_boot_guid(uint8_t coreId,
                                 xbl_boot_image_info_t *boot_image_info,
                                 const char *primary_guid,
                                 const char *secondary_guid,
                                 xbl_mem_loadlist_param_t* load_List,
                                 boolean bBlackList)
{
    int ret;
    BootLoaderInfoType *pxLoaderInfo = NULL;

    ret = nElfloaderLoad_Open(coreId, primary_guid, load_List, bBlackList, &pxLoaderInfo);

    /* Poll loading state until error or successful loading*/
    if (ret == XBL_OK_NOT_DONE)
    {

        while (ret == XBL_OK_NOT_DONE)
        {
           ret = nElfLoaderPollState(coreId, pxLoaderInfo, &boot_image_info->image_entry);
        }

        if (ret == XBL_SUCCESS)
        {
                 boot_image_info->status = TRUE;
                 boot_image_info->partition_id = XBL_PARTITION_A;
                 boot_image_info->gpt_id = gXBLHypCtx.gptId;
                 return ret;
        }
        if(pxLoaderInfo != NULL)
        {
            pxLoaderInfo = NULL;
        }
    }

    /*if the boot mode is regular then only try B*/
    if (gXBLHypCtx.bootType == TRUE)
    {
        /* If primary guid loading failed, execute pre-loading and loading with secondary_guid */
        ret = nElfloaderLoad_Open(coreId, secondary_guid, load_List, bBlackList, &pxLoaderInfo);

        /* Poll loading state until error or successful loading*/
        if (ret == XBL_OK_NOT_DONE)
        {

            while (ret == XBL_OK_NOT_DONE)
            {
               ret = nElfLoaderPollState(coreId, pxLoaderInfo, &boot_image_info->image_entry);
            }

            if (ret == XBL_SUCCESS)
            {
                boot_image_info->status = TRUE;
                boot_image_info->partition_id = XBL_PARTITION_B;
                boot_image_info->gpt_id = gXBLHypCtx.gptId;
                return ret;
            }

        }
    }

    boot_image_info->status = FALSE;
    boot_image_info->partition_id = XBL_PARTITION_NULL;
    ret = XBL_ERROR;

    boot_image_info->gpt_id = gXBLHypCtx.gptId;

#ifndef NORPVL_ENB
    /*If boot Type is OTA Boot then error FATAL*/
    if (TRUE == xSAILUpdaterIsBootTypeOTA())
    {
        XBL_LOG_ERROR("%s Boot Type is OTA Boot Fatal error\n\r", __func__);
        err_fatal(XBL, ERR_FATAL_FORCED_REBOOT);
    }
#endif
    return ret;
}

static xbl_boot_image_info_t* sailhyp_xbl_boot_get_info(uint32_t image_id)
{
    if (image_id < XBL_IMAGE_ID_MAX)
    {
        return &boot_image_info_array[image_id];
    }
    else
    {
        return NULL;
    }
}

static int sailhyp_xbl_boot_one_elf(uint8_t coreId, xbl_boot_params_t *boot_param)
{
    int ret;
    xbl_boot_image_info_t *boot_image_info = NULL;
    const char *primary_guid               = NULL;
    const char *secondary_guid             = NULL;

    boot_image_info = sailhyp_xbl_boot_get_info(boot_param->image_id);
    primary_guid = sailhyp_xbl_boot_get_guid(boot_param->image_id, TRUE);
    secondary_guid = sailhyp_xbl_boot_get_guid(boot_param->image_id, FALSE);

    if (NULL == boot_image_info)
    {
        XBL_LOG_ERROR("%s boot_image_info is NULL\n\r", __func__);
        ret = XBL_ERROR_NOT_SUPPORTED;
    }
    else if(NULL == primary_guid || NULL == secondary_guid)
    {
        XBL_LOG_ERROR("%s missing GUID\n\r", __func__);
        boot_image_info->status = FALSE;
        ret = XBL_ERROR_NOT_SUPPORTED;
    }
    else
    {

        init_boot_image_info(coreId, boot_image_info);
        switch (boot_param->boot_option)
        {
            case XBL_BOOT_OPTION_FULL:
            {
                /* load_list is set to NULL, so bBlacklist is donot care */
                ret = sailhyp_xbl_boot_guid(coreId, boot_image_info, primary_guid, secondary_guid, NULL, FALSE);
                if (XBL_SUCCESS != ret)
                {
                    XBL_LOG_ERROR("%s:Error in ELF loading with full whitelist, error = %d, image_id = %d\n\r",
                                  __func__, ret, boot_image_info->image_id);
                }
                break;
            }
            case XBL_BOOT_OPTION_MANDATORY:
            {
                ret = sailhyp_xbl_boot_guid(coreId, boot_image_info, primary_guid, secondary_guid, boot_param->loadlist, TRUE);
                if (XBL_SUCCESS != ret)
                {
                    XBL_LOG_ERROR("%s: Error in ELF loaging with mandatory whitelist. Error = %d, image_id = %d\n\r",
                                  __func__, ret, boot_image_info->image_id);
                }

                break;
            }
            case XBL_BOOT_OPTION_ONDEMAND:
            {
                ret = sailhyp_xbl_boot_guid(coreId, boot_image_info, primary_guid, secondary_guid, boot_param->loadlist, FALSE);
                if (XBL_SUCCESS != ret)
                {
                    XBL_LOG_ERROR("%s: Error in ELF loading with user whitelist. Error = %d, image_id = %d\n\r",
                                  __func__, ret, boot_image_info->image_id);
                }
                break;
            }
            default:
                boot_image_info->status = FALSE;
                ret = XBL_ERROR_INVALID_PARAM;
                XBL_LOG_ERROR("%s invalid BOOT_OPTION error\n\r", __func__);
                break;
        }
        finalize_boot_image_info(ret, boot_image_info);
    }
    return ret;
}
int sailhyp_xbl_boot_elfs(xbl_boot_params_t *boot_params, uint32_t count)
{
    int ret = XBL_SUCCESS;
    xbl_boot_params_t *params = NULL;
    uint8_t coreId = get_curr_phys_cpu_num();

    if (gXBLHypCtx.eStorageType == XBL_STORAGE_DDR && coreId != 0)
    {
        XBL_LOG_INFO("%s: core_id = %d, XBL is in DDR storage boot mode (%d), only core 0 is permitted to boot at this more. Calling err_fatal.\n\r",
                    __func__, coreId, gXBLHypCtx.eStorageType);
        err_fatal(XBL, ERR_FATAL_UNHANDLED_EXCEPTION);
    }

    vSetEnterTime(coreId);

    mutex_lock(&xMutex);

    /* This mutex is used to serialize sec_auth lib before teh multi-core safe faeture implementation done */
    XBL_LOG_ERROR("%s: mutex lock, coreId = %d\n\r", __func__, coreId);

    if (boot_params != NULL)
    {
        if (count == 0 || count > XBL_IMAGE_ID_MAX)
        {
            XBL_LOG_ERROR("%s: Error. Invalid count = %d\n\r", __func__, count);
            ret = XBL_ERROR_INVALID_PARAM;
            goto end;
        }

    }
    else
    {
        count = XBL_IMAGE_ID_SW4+1;   /* default, we load SW1, 2, 3, and 4 */
    }

    params = xblMalloc(sizeof(xbl_boot_params_t) * count);

    if (NULL == params)
    {
        XBL_LOG_ERROR("%s: Error. No mem, coreId = %d\n\r", __func__, coreId);
        ret = XBL_ERROR_NO_MEM;
        goto end;
    }

    /* params is not NULL */
    memset(params, 0, sizeof(sizeof(xbl_boot_params_t) * count));

    if (boot_params != NULL)
    {
        memcpy (params, boot_params, sizeof(xbl_boot_params_t) * count);
    }
    else
    {
        eXblImageIdType id;
        for (id = XBL_IMAGE_ID_SW1; id <= XBL_IMAGE_ID_SW4; id++)
        {
            params[id].boot_option = XBL_BOOT_OPTION_MANDATORY;
            params[id].image_id    = id;
            params[id].loadlist   = NULL;
        }
    }

    for ( int i = 0; i < count; i++)
    {
        switch (params[i].image_id)
        {
        case XBL_IMAGE_ID_SW1:
        case XBL_IMAGE_ID_SW2:
        case XBL_IMAGE_ID_SW3:
        case XBL_IMAGE_ID_SW4:
        case XBL_IMAGE_ID_SEC_ELF:
        case XBL_IMAGE_ID_DBG_POLICY:
            ret = sailhyp_xbl_boot_one_elf (coreId, &params[i]);
            if (ret != XBL_SUCCESS)
            {
                XBL_LOG_ERROR("%s: Error in loading core_id = %d, image_id = %d, error code = %d\n\r",
                              __func__, coreId, params[i].image_id, ret);
            }
            break;
        default:
            XBL_LOG_ERROR("%s: Error. Invalid parameter. core_id = %d, image_id = %d\n\r", __func__, coreId, params[i].image_id);
            ret = XBL_ERROR_INVALID_PARAM;
            break;
        }
        if (XBL_SUCCESS != ret)
        {
            break;
        }
    }
    xblFree(params);

end:
    vSetExitTime(coreId);
    XBL_LOG_INFO("%s: mutex unlock, coreId = %d, ret = %d, duration = 0x%llu\n\r", __func__, coreId, ret, uulGetXblDurationUs(coreId));
#ifdef XBL_MEM_DBG
    if ( FALSE == xblMemCheckLeak() )
    {
        /* Memory leak detected */
        XBL_LOG_ERROR("%s: Error. Memory leak detected. boot status = %d\n\r", __func__);
        ret = XBL_ERROR;
        err_fatal(XBL, ERR_FATAL_UNHANDLED_EXCEPTION);
    }
#endif
    mutex_unlock(&xMutex);

    return ret;
}

int sailhyp_xbl_get_image_entry_point(eXblImageIdType image_id, uint32_t *image_entry)
{
    int ret = XBL_SUCCESS;
    uint8_t coreId = get_curr_phys_cpu_num();

    if (NULL != image_entry && image_id < XBL_IMAGE_ID_MAX && boot_image_info_array[image_id].status == TRUE)
    {
        *image_entry = boot_image_info_array[image_id].image_entry;
        if (0UL == *image_entry)
        {
            XBL_LOG_ERROR("%s: Error, image_entry is zero. core_id = %d, image_id = %d, image_entry = 0x%x\n\r",
                          __func__, coreId, image_id, *image_entry);
        }
        else
        {
            XBL_LOG_ERROR("%s: core_id = %d, image_id = %d, image_entry = 0x%x\n\r",
                          __func__, coreId, image_id, *image_entry);
        }
    }
    else
    {
        XBL_LOG_ERROR("%s: Error\n\r", __func__);
        ret = XBL_ERROR;
    }
    return ret;
}

int sailhyp_xbl_getImgId(const char* imgName, uint32_t* image_id)
{
    if ((NULL == imgName) || (NULL == image_id))
    {
        return XBL_ERROR;
    }

    for ( int i = 0; i < sizeof(boot_image_info_array) / sizeof(boot_image_info_array[0]); i++ )
    {
        if ( NULL != boot_image_info_array[i].img_name &&
            strlen(imgName) == strlen(boot_image_info_array[i].img_name)  &&
             0 == strncmp(imgName, boot_image_info_array[i].img_name,strlen(boot_image_info_array[i].img_name)))
        {
            *image_id = boot_image_info_array[i].image_id;
            return XBL_SUCCESS;
        }
    }

    return XBL_ERROR;
}

uint32_t sailhyp_xbl_getImgGUID(const char* imgName, uint32_t FlashPartition, uint32_t FlashGptId, char *imgGuid)
{
    char *pGuid;
    size_t result;
    uint32_t image_id=0xFFFFFFFF;
    if(sailhyp_xbl_getImgId(imgName,&image_id))
    {
        *imgGuid = (char) 0;
        return XBL_ERROR;
    }

    if (XBL_PARTITION_A == FlashPartition)
    {
        pGuid = (char *) sailhyp_xbl_boot_get_guid((eXblImageIdType)image_id, TRUE);
    }
    else if(XBL_PARTITION_B == FlashPartition)
    {
        pGuid = (char *) sailhyp_xbl_boot_get_guid((eXblImageIdType)image_id, FALSE);
    }
    else
    {
        pGuid = NULL;
    }

    if (NULL != pGuid)
    {
        result = sailbsp_strlcpy(imgGuid, (const char *)pGuid, GUID_STRING_SIZE+1);
        if(result == 0)
        {
            return XBL_ERROR;
        }

        return XBL_SUCCESS;
    }
    else
    {
        return XBL_ERROR;
    }
}

uint32_t sailhyp_xbl_queryBootInfo(XBLBootInfoType* bootInfo, uint32_t ulArraySize)
{

    uint32_t boot_image_info_size = sizeof(boot_image_info_array) / sizeof(boot_image_info_array[0]);
    uint32_t num_elements;

    num_elements = ulArraySize;

    if (ulArraySize > boot_image_info_size)
    {
        num_elements = boot_image_info_size;
    }

    for (int i=0;i<num_elements;i++)
    {
        sailbsp_strlcpy(bootInfo[i].img_name, boot_image_info_array[i].img_name, XBL_IMG_NAME_SIZE_MAX);
        bootInfo[i].partition_id = boot_image_info_array[i].partition_id;
        bootInfo[i].gpt_id = boot_image_info_array[i].gpt_id;
    }
    return XBL_SUCCESS;
}

int sailhyp_xbl_erase_image(eXblImageIdType image_id)
{
    int ret;
    const char *primary_guid;
    const char *secondary_guid;
    uint8_t coreId;

    coreId = get_curr_phys_cpu_num();
    primary_guid = sailhyp_xbl_boot_get_guid(image_id, TRUE);
    secondary_guid = sailhyp_xbl_boot_get_guid(image_id, FALSE);
    ret = nBootLoaderErase(coreId, primary_guid);
    if (0 != ret)
    {
        goto end;
    }
    ret = nBootLoaderErase(coreId, secondary_guid);
end:
    return ret;
}

int sailhyp_xbl_check_ehdr(eXblImageIdType image_id, boolean *primary, boolean *secondary)
{
    int ret = XBL_SUCCESS;
    const char *primary_guid;
    const char *secondary_guid;
    uint8_t coreId;

    if (NULL == primary || NULL == secondary)
    {
        ret = XBL_ERROR_INVALID_PARAM;
        goto end;
    }
    coreId = get_curr_phys_cpu_num();
    primary_guid = sailhyp_xbl_boot_get_guid(image_id, TRUE);
    secondary_guid = sailhyp_xbl_boot_get_guid(image_id, FALSE);
    *primary   = bBootLoaderCheckElfHeader ( coreId, primary_guid);
    *secondary = bBootLoaderCheckElfHeader ( coreId, secondary_guid);
end:
    return ret;
}

int sailhyp_xbl_update_storage( eXblStorageType eType, uint32_t ulRamBase, uint32_t ulRamSize)
{
    int ret = XBL_SUCCESS;
    if(eType >= XBL_STORAGE_MAX)
    {
        ret = XBL_ERROR_INVALID_PARAM;
        return ret;
    }
    gXBLHypCtx.eStorageType = eType;
    gXBLHypCtx.ulRamBase = ulRamBase;
    gXBLHypCtx.ulRamSize = ulRamSize;
    ret = nElfLoaderUpdate(gXBLHypCtx.eStorageType, gXBLHypCtx.ulRamBase, gXBLHypCtx.ulRamSize);
    return ret;
}

int sailhyp_xbl_getHashDigest(xbl_digestHashType * xDigestHash)
{
    int retVal;
    char* imgGuid = NULL;
    uint32_t image_id   = 0xFFFFFFFF;
    uint8_t coreId      = get_curr_phys_cpu_num();
    BootLoaderInfoType *pxLoaderInfo = NULL;
    uint32_t dummyImageEntry = 0UL;

    *xDigestHash->hashAlgo = 384U;

    if(NULL == xDigestHash->imgName || NULL == xDigestHash->hashContainer || NULL == xDigestHash->containerSize)
    {
        return XBL_ERROR_INVALID_PARAM;
    }

    if(*xDigestHash->containerSize < XBL_DIGEST_HASH_SIZE_IN_BYTES)
    {
        XBL_LOG_ERROR("%s: Error, invalid hash container size\n\r", __func__);
        return XBL_ERROR_INVALID_PARAM;
    }

    retVal = sailhyp_xbl_getImgId(xDigestHash->imgName,&image_id);
    if(XBL_SUCCESS != retVal)
    {
        XBL_LOG_ERROR("%s: Error, getImgId failed\n\r", __func__);
        goto end;
    }
    imgGuid = (char *) sailhyp_xbl_boot_get_guid((eXblImageIdType)image_id, xDigestHash->bIsPrimaryPartition);
    if(imgGuid == NULL)
    {
        XBL_LOG_ERROR("%s: Error, getImgGUID failed\n\r", __func__);
        retVal = XBL_ERROR;
        goto end;
    }

    if(!bBootLoaderCheckElfHeader(coreId, imgGuid))
    {
        XBL_LOG_ERROR("%s: Error, Requested partition empty\n\r", __func__);
        return retVal;
    }

    do
    {
        pxLoaderInfo = xblMalloc(sizeof(BootLoaderInfoType));
        if (NULL == pxLoaderInfo)
        {
            XBL_LOG_ERROR("%s: Error, core_id = %d, no mem\n\r", __func__, coreId);
            retVal = XBL_ERROR_NO_MEM;
            break;
        }

        (void)memset(pxLoaderInfo, 0, sizeof(BootLoaderInfoType));
        (void)sailbsp_strlcpy(pxLoaderInfo->g_guidString, imgGuid, GUID_SIZE);
        if (0 != nStorageOpen(&pxLoaderInfo->g_spinor_handle))
        {
            XBL_LOG_ERROR("%s: Error. Cannot open storage driver\n\r", __func__);
            xblFree(pxLoaderInfo);
            pxLoaderInfo = NULL;
            retVal = XBL_ERROR_STORAGE_OPEN;
            break;
        }
        if (0 != nStorageGetPartition( pxLoaderInfo->g_spinor_handle, imgGuid, &pxLoaderInfo->g_partition.ulStartAddr, &pxLoaderInfo->g_partition.ulSize) )
        {
            xStorageClose(pxLoaderInfo->g_spinor_handle);
            XBL_LOG_ERROR("%s: Error, core_id = %d, sec_img_id = 0x%x, guid = '%s', cannot get partition\n\r",
                        __func__, coreId, pxLoaderInfo->g_nImageId, imgGuid);
            xblFree(pxLoaderInfo);
            retVal = XBL_ERROR_NO_PARTITION;
            pxLoaderInfo = NULL;
            break;
        }
        pxLoaderInfo->bBlackList = FALSE;
        pxLoaderInfo->next_state = LOAD_ELF_HDR;
        retVal = XBL_OK_NOT_DONE;
    }while(0);

    while (retVal == XBL_OK_NOT_DONE)
    {
        retVal = nElfLoaderLoad_State(coreId, pxLoaderInfo, &dummyImageEntry, pxLoaderInfo->load_List);

        if(pxLoaderInfo->next_state == AUTH_ELF_HDR && retVal == XBL_OK_NOT_DONE)
        {
            pxLoaderInfo->next_state = PROGRAM_HDR;
        }
        else if(pxLoaderInfo->next_state == ALLOCATE_IMG_CTXT && retVal == XBL_OK_NOT_DONE)
        {
            pxLoaderInfo->next_state = DONE_LOAD;
            retVal = XBL_SUCCESS;
        }
        else
        {
            //Do nothing
        }
    }

    if (XBL_SUCCESS != retVal)
    {
            XBL_LOG_ERROR("%s: Error in Hash loading, status = %d\n\r", __func__, retVal);
            goto end;
    }

    retVal = nElfLoaderGetDigestHash(pxLoaderInfo, xDigestHash->hashContainer, XBL_DIGEST_HASH_SIZE_IN_BYTES);

    if(XBL_SUCCESS != retVal)
    {
            XBL_LOG_ERROR("%s: Error in Digest Hash calculation, status = %d\n\r", __func__, retVal);
            goto end;
    }

    *xDigestHash->containerSize = *xDigestHash->containerSize - XBL_DIGEST_HASH_SIZE_IN_BYTES;
    end:
        if (pxLoaderInfo != NULL)
        {
            if (pxLoaderInfo->g_spinor_handle != NULL)
            {
                xStorageClose(pxLoaderInfo->g_spinor_handle);
            }
            xblFree(pxLoaderInfo->g_hashSegment.hash);
            xblFree(pxLoaderInfo);
        }
        return retVal;
}

int sailhyp_xbl_init(void *pbl_shared_info)
{

    int ret = XBL_SUCCESS;
    uint8_t coreId = get_curr_phys_cpu_num();
#ifndef NORPVL_ENB
    SAILUpdaterOTAStateValType otaState;
#endif

    memset(&gXBLHypCtx, 0, sizeof(gXBLHypCtx));

    if (NULL == pbl_shared_info)
    {
        return XBL_ERROR_INVALID_PARAM;
    }

#ifndef NORPVL_ENB
    /*get the loader Flow*/
    if(SAIL_UPDATER_STATUS_SUCCESS != xSAILUpdaterGetLoaderFlow(&gXBLHypCtx.bootType))
    {
        XBL_LOG_ERROR("%s: Error in getting Loader Flow\n\r");
        return XBL_ERROR;
    }
#endif

    /*get the chip Id if its Monaco we need to handle updated PBL Shared Info Structure with BIS Time stamp*/
    #ifdef monaco
         ret = nGetHypBootInfoFromPblSharedInfo_monaco(pbl_shared_info, &boot_image_info_array[XBL_IMAGE_ID_HYP]);
    #else
         ret = nGetHypBootInfoFromPblSharedInfo_lemans(pbl_shared_info, &boot_image_info_array[XBL_IMAGE_ID_HYP]);
    #endif
    if (ret != XBL_SUCCESS)
    {
        XBL_LOG_ERROR("%s: Error in getting PBL Shared Info. core_id = %d\n\r", __func__, coreId);
        return XBL_ERROR;
    }
#ifndef NORPVL_ENB
    /*Check Current OTA State*/
    otaState = xSAILUpdaterGetCurrentOTAState();
    XBL_LOG_WARNING("%s: SAIL HYP XBL Info. currentOTAState = %d, GPT_ID = %d, Partition_ID = %d\n\r", __func__, otaState, boot_image_info_array[XBL_IMAGE_ID_HYP].gpt_id, boot_image_info_array[XBL_IMAGE_ID_HYP].partition_id);

    /* If the boot is using Secondary GPT, then allow only if the state is disabled. Cause a forced reboot.
       Primary GPT should have been fixed for the next boot */
    if (boot_image_info_array[XBL_IMAGE_ID_HYP].gpt_id == XBL_GPT_TABLE_SECONDARY)
    {
        if (otaState != OTA_DISABLED)
        {
            XBL_LOG_ERROR("%s: Error in OTA state Info. currentOTAState = %d, GPT_ID = %d, Partition_ID = %d\n\r", __func__, otaState, boot_image_info_array[XBL_IMAGE_ID_HYP].gpt_id, boot_image_info_array[XBL_IMAGE_ID_HYP].partition_id);
            XBL_LOG_ERROR("%s: Booting from Secondary GPT is only allowed in OTA_DISABLED state. Forcing a reboot \n\r", __func__);
            err_fatal(XBL, ERR_FATAL_FORCED_REBOOT);
        }
        else
        {
            /* OTA State is disabled. Do nothing */
        }
    }
    else
    {
        if ( (otaState == OTA_IN_PROGRESS)  || (otaState == OTA_UPDATE_START) || (otaState == OTA_BOOTING) ||(otaState == OTA_ROLLBACK) || (otaState == OTA_DONE) || (otaState == OTA_REBOOT_CORRUPTED)
            )
        {
            /*Booting from partition B is not allowed in these state. */
            if ( (!gXBLHypCtx.bootType) && (boot_image_info_array[XBL_IMAGE_ID_HYP].partition_id == XBL_PARTITION_B))
            {
                XBL_LOG_ERROR("%s: Error in OTA state Info. currentOTAState = %d, GPT_ID = %d, Partition_ID = %d\n\r", __func__, otaState, boot_image_info_array[XBL_IMAGE_ID_HYP].gpt_id, boot_image_info_array[XBL_IMAGE_ID_HYP].partition_id);
                XBL_LOG_ERROR("%s: Booting from partition B is not allowed in this state\n\r", __func__);
                return XBL_ERROR;
            }
            else if (gXBLHypCtx.bootType)
            {
                XBL_LOG_ERROR("%s: Error in OTA state Info. currentOTAState = %d, GPT_ID = %d, Partition_ID = %d\n\r", __func__, otaState, boot_image_info_array[XBL_IMAGE_ID_HYP].gpt_id, boot_image_info_array[XBL_IMAGE_ID_HYP].partition_id);
                XBL_LOG_ERROR("%s: Boot type is True in this state is an error \n\r", __func__);
                return XBL_ERROR;
            }
            else
            {
                /* Booting with Partition A. Do nothing */
            }
        }
        else if (otaState == OTA_DISABLED)
        {
            /* OTA State is disabled. Do nothing. Allow boot with any partition */
        }
        else
        {
            /* Control should not be here */
            XBL_LOG_ERROR("%s: Error in OTA state Info. currentOTAState = %d, GPT_ID = %d, Partition_ID = %d\n\r", __func__, otaState, boot_image_info_array[XBL_IMAGE_ID_HYP].gpt_id, boot_image_info_array[XBL_IMAGE_ID_HYP].partition_id);
            XBL_LOG_ERROR("%s: OTA state undefined is an error \n\r", __func__);
            return XBL_ERROR;
        }
    }
#endif

    mutex_init(&xMutex);
    xblMemInit();
    if (0 != nElfloaderInit(pbl_shared_info))
    {
        XBL_LOG_ERROR("%s: Error in ELF loader init. core_id = %d\n\r", __func__, coreId);
        return XBL_ERROR;
    }

    /* Storage open is already successful at this point. Get the callback for the GPT read from storage layer */
    /*gXBLHypCtx.pGPTWorkBuf = guXBLgptWorkBuf; Not used */
    gXBLHypCtx.gptEntryReadCb = gptPartitionGetReadCb();
    gXBLHypCtx.storageBlockCnt = gptPartitionGetBlockCnt();
    gXBLHypCtx.gptId = gptPartitionGetGptId();

    /* TBD: In OTA reboot, OTA status will be checked to decide if we need to rollback to -1 sailhyp version.
     * OTA design limitation: sailhyp must boot to pass ospi init and reach here.
     */
    XBL_LOG_INFO("%s: done, core_id = %d\n\r", __func__, coreId);


    return XBL_SUCCESS;
}

void sailhyp_xbl_deinit(void)
{
    vElfloaderDeinit();
}

