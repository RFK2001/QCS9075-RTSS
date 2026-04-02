/*
===========================================================================
*/
/**
    @file  sailsw1_xbl.c
    @brief sailsw1 xbl implementation
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/xbl/src/sailsw1/sailel1_xbl.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/



/*===========================================================================
                               INCLUDE FILES
===========================================================================*/
#include <stdbool.h>
#include "types.h"
#include "xbl_def.h"
#include "sailel1_xbl_api.h"
#include "sailel1_xbl_syscall.h"
#include "xbl_diag.h"
#include "debug_log.h"
#include "xbl_mem.h"
#include "common_functions.h"

/*===========================================================================
                           MACROS
===========================================================================*/


/*===========================================================================
                               VARIABLES
============================================================================*/
typedef struct
{
    boolean init;
    //add mutex
} sailel1_xbl_ctxt_type;

sailel1_xbl_ctxt_type el1XblCtxt;

int sailEl1XblInit(void)
{
    memset(&el1XblCtxt, 0, sizeof(el1XblCtxt));
    //TBD: Init mutex
    el1XblCtxt.init = TRUE;
    return XBL_SUCCESS;
}

int sailEl1XblGetImgGUID( const char* imgName, uint32_t FlashPartition, uint32_t FlashGptId, char *imgGuid)
{
    int ret = XBL_SUCCESS;
    XblHvcEventType   event;
    XblEl1EventIdType eventId = XBL_EL1_EVENT_GET_GUID;
    if (el1XblCtxt.init != TRUE)
    {
        DEBUG_LOG(SAIL_ERROR, "El1 Xbl context variable not initialized %u\n\r");
        return XBL_ERROR;
    }

    if ((NULL == imgName) || (NULL == imgGuid))
    {
        DEBUG_LOG(SAIL_ERROR, "Xbl imgName and imgGuid is NULL %u\n\r");
        return XBL_ERROR_NULL_POINTER;
    }

    memset(&event, 0, sizeof(XblEl1EventIdType));
    event.xGetImageGuid.imgName = imgName;
    event.xGetImageGuid.FlashPartition = FlashPartition;
    event.xGetImageGuid.FlashGptId = FlashGptId;
    event.xGetImageGuid.imgGuid = imgGuid;

    ret = sailEl1XblSysCall(eventId,&event);
    if (ret != XBL_SUCCESS)
    {
        XBL_LOG_ERROR("%s: error, get GUID hvc , ret = %d\n\r", __func__, ret);
        return ret;
    }
    return XBL_SUCCESS;
}

int sailEl1XblGetBootInfo(XBLBootInfoType* bootInfo, uint32_t ulArraySize)
{
    int ret = XBL_SUCCESS;
    XblHvcEventType   event;
    XblEl1EventIdType eventId = XBL_EL1_EVENT_GET_BOOT_INFO;

    if (el1XblCtxt.init != TRUE)
    {
        DEBUG_LOG(SAIL_ERROR, "Sail El1 context variable not initialized %u\n\r");
        return XBL_ERROR;
    }

    if (NULL == bootInfo)
    {
        DEBUG_LOG(SAIL_ERROR, "Xbl boot info parameter is null %u\n\r");
        return XBL_ERROR_NULL_POINTER;
    }

    memset(&event, 0, sizeof(XblHvcEventType));
    event.xGetBootInfo.xBootInfo = bootInfo;
    event.xGetBootInfo.ulArraySize = ulArraySize;

    ret = sailEl1XblSysCall(eventId,&event);
    if (ret != XBL_SUCCESS)
    {
        XBL_LOG_ERROR("%s: error, boot info hvc , ret = %d\n\r", __func__, ret);
        return ret;
    }

    return XBL_SUCCESS;
}

int sailEl1XblLoaderOpen(xbl_boot_params_t * boot_param)
{
    int ret = XBL_SUCCESS;
    XblHvcEventType event;
    XblEl1EventIdType eventId = XBL_EL1_EVENT_LOADER_OPEN;

    if (boot_param == NULL)
    {
        DEBUG_LOG(SAIL_ERROR, "Xbl boot param is null %u\n\r");
        return XBL_ERROR_NULL_POINTER;
    }

    memset(&event, 0, sizeof(XblHvcEventType));
    event.xBootParams = boot_param;
    ret = sailEl1XblSysCall(eventId, &event);

    if (XBL_OK_NOT_DONE != ret)
    {
        XBL_LOG_ERROR("%s: error, loader open , ret = %d\n\r", __func__, ret);
    }

    return ret;

}



int sailEl1XblLoaderPollState(uint32_t * ulEntryPoint)
{
    int ret = XBL_SUCCESS;
    /* make sure event info carries from preloading */
    XblHvcEventType event;
    XblEl1EventIdType eventId = XBL_EL1_EVENT_LOADER_POLL;

    if (ulEntryPoint == NULL)
    {
        DEBUG_LOG(SAIL_ERROR, "Xbl Image entry point is null %u\n\r");
        return XBL_ERROR_NULL_POINTER;
    }

    memset(&event,0,sizeof(XblHvcEventType));
    ret = sailEl1XblSysCall(eventId,&event);

    if (XBL_SUCCESS != ret && XBL_OK_NOT_DONE != ret)
    {
        XBL_LOG_ERROR("%s: error, loader poll state hvc , ret = %d\n\r", __func__, ret);
        return XBL_ERROR;
    }

    if (XBL_SUCCESS == ret)
    {
        *ulEntryPoint = event.ulEntryPoint;
    }

    return ret;

}

int sailEl1XblGetDigestHash(xbl_digestHashType * xDigestHash)
{
    int ret = XBL_SUCCESS;
    /* make sure event info carries from preloading */
    XblHvcEventType event;
    XblEl1EventIdType eventId = XBL_EL1_EVENT_GET_HASH_DGST;
    xbl_digestHashType tmpDigestHashInfo = { 0U };

    if (NULL == xDigestHash)
    {
        DEBUG_LOG(SAIL_ERROR, "DigestHash info is NULL %u\n\r");
        return XBL_ERROR_NULL_POINTER;
    }
    
    tmpDigestHashInfo = *xDigestHash;
    
    event.xGetHashDigest = &tmpDigestHashInfo; 
    ret = sailEl1XblSysCall(eventId,&event);
    
    sailbsp_memscpy(xDigestHash, sizeof(xDigestHash), &tmpDigestHashInfo, sizeof(tmpDigestHashInfo));

    if (XBL_SUCCESS != ret && XBL_OK_NOT_DONE != ret)
    {
        XBL_LOG_ERROR("%s: error, get hash digest hvc , ret = %d\n\r", __func__, ret);
        return XBL_ERROR;
    }
    
    return ret;
}
