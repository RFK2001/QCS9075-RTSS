/*
===========================================================================
*/
/**
    @file  sailhyp_xbl_trap.c
    @brief sailhyp xbl trap call implementation
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/xbl/src/sailhyp/sailhyp_xbl_trap.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/


/*=================================================================================================
**                                        Include files                                          **
=================================================================================================*/

#include "types.h"
#include "common_functions.h"
#include "xbl_def.h"
#include "sailhyp_xbl.h"
#include "sailhyp_xbl_guid.h"
#include "syscall.h"
#include "elfloader_def.h"
#include "elfloader.h"
#include "syscall_pub.h"
#include "sailhyp_xbl_api.h"
#include "gpt_p1.h"
#include "xbl_hvc_event.h"
#include "xbl_mem.h"
#include "xbl_diag.h"
#include "sailbsp_mutex.h"

#define XBL_TRAP_PRI_GUID_IDX    0
#define XBL_TRAP_SEC_GUID_IDX    1
/* Static variables used for El1 XBL Loader */
typedef struct
{
    BootLoaderInfoType * pxLoaderInfo;  
    uint32_t             ulCoreId;
    uint32_t             ulGuidTried;
} xXblTrapCtrlType;
static xXblTrapCtrlType g_xblTrapCtrl;

static int XblTrapTrySecGuid(XblHvcEventType *pEvent);
static int XblTrapLoaderOpen(XblHvcEventType *pEvent);
static int XblTrapLoaderPollState(XblHvcEventType *pEvent);
static int XblGetImgGUIDTrap(const char* imgName, uint32_t FlashPartition, uint32_t FlashGptId, char *imgGuid);
static int XblGetBootInfoTrap(XBLBootInfoType* bootInfo, uint32_t ulArraySize);

//#define XBL_TRAP_HACK /* Uncomment to test EL1 loader open and then poll state in one syscall */
#ifdef XBL_TRAP_HACK 
static int XblTrapTestEl1Loader(XblHvcEventType *pEvent)
{
    int ret = XBL_SUCCESS;

    ret = XblTrapLoaderOpen(pEvent);
    if (ret != XBL_OK_NOT_DONE)
    {
        ret = -100;
        DEBUG_LOG(SAIL_ERROR, "%s: Error in XblTrapLoaderOpen, ret = %d\n\r", __func__, ret);
    }

    while( ret == XBL_OK_NOT_DONE)
    {
        ret = XblTrapLoaderPollState(pEvent);
    }

    if (ret ==  XBL_SUCCESS)
    {
        DEBUG_LOG(SAIL_ERROR, "%s PASSED : entrypoint = 0x%x \n\r", __func__, pEvent->ulEntryPoint);
    }

    else
    {
        ret = -100;
        DEBUG_LOG(SAIL_ERROR, "%s: Error in XblTrapLoaderPollState, ret = %d\n\r", __func__, ret);
    }
    return ret;
}
#endif

static int XblTrapTrySecGuid(XblHvcEventType *pEvent)
{
    const char * guid = NULL;
    boolean bBlackList = FALSE;
    int ret = XBL_ERROR;

    g_xblTrapCtrl.pxLoaderInfo = NULL; /* Rseet primary GUID's loader info pointer */
    g_xblTrapCtrl.ulGuidTried |= (1 << XBL_TRAP_SEC_GUID_IDX);
    guid = sailhyp_xbl_boot_get_guid(pEvent->xBootParams->image_id, FALSE);
    
    /* Preloading for secondary SAIL image. If secondary failed also,
     * loaderInfo is freed in eldloader Open API. Zero out of g_xblTrapCtrl 
     * is done in trap function. */
    ret = nElfloaderLoad_Open((uint8_t)g_xblTrapCtrl.ulCoreId,
                              guid,
                              pEvent->xBootParams->loadlist,
                              bBlackList,
                              &g_xblTrapCtrl.pxLoaderInfo);
    
    return ret;
}
static int XblTrapLoaderOpen(XblHvcEventType *pEvent)
{
    int ret = XBL_ERROR;
    const char * guid = NULL;
    boolean bBlackList = FALSE;

    if (g_xblTrapCtrl.pxLoaderInfo != NULL)
    {
        /* Defensive code, this means sailheap leak. It is a development bug. */
        ret = XBL_ERROR;
        goto end;
    }

    /* Try primary GUID first */
    g_xblTrapCtrl.ulGuidTried = (1 << XBL_TRAP_PRI_GUID_IDX);
    guid = sailhyp_xbl_boot_get_guid(pEvent->xBootParams->image_id, TRUE);
    g_xblTrapCtrl.ulCoreId = get_curr_phys_cpu_num();

    /* ODL uses whitelists, bBlacklist is FALSE */
    /* Preload primary SAIL image */
    ret = nElfloaderLoad_Open((uint8_t)g_xblTrapCtrl.ulCoreId,
                              guid,
                              pEvent->xBootParams->loadlist,
                              bBlackList,
                              &g_xblTrapCtrl.pxLoaderInfo);

    if ( ret != XBL_OK_NOT_DONE)
    {
        /* Load Open only returns XBL_OK_NOT_DONE or error.
         * Primary preloading failed, retrieve secondary guid */
        ret = XblTrapTrySecGuid(pEvent);
    }
end:
    return ret;
}

static int XblTrapLoaderPollState(XblHvcEventType *pEvent)
{
    const char * guid = NULL;
    int ret = XBL_SUCCESS;
    
    ret = nElfLoaderPollState((uint8_t)g_xblTrapCtrl.ulCoreId,
                              g_xblTrapCtrl.pxLoaderInfo,
                              &pEvent->ulEntryPoint);
    if ( ret != XBL_OK_NOT_DONE &&  ret != XBL_SUCCESS)
    {
        /* Poll state failed. If secondary GUID not tried, try it */
        if ( !(g_xblTrapCtrl.ulGuidTried & (1 << XBL_TRAP_SEC_GUID_IDX)) )
        {
            ret = XblTrapTrySecGuid(pEvent);
            return ret;
        }
    }

    return ret;

}

static int XblGetImgGUIDTrap(const char* imgName, uint32_t FlashPartition, uint32_t FlashGptId, char *imgGuid)
{
    int retval;
    retval = sailhyp_xbl_getImgGUID(imgName, FlashPartition, FlashGptId, imgGuid);
    return retval;
}

static int XblGetBootInfoTrap(XBLBootInfoType* bootInfo, uint32_t ulArraySize)
{
    int retval;
    
    if(NULL == bootInfo)
    {
        return XBL_ERROR;
    }

    retval = sailhyp_xbl_queryBootInfo(bootInfo, ulArraySize);

    return retval;
    
}

static int XblGetHashDigestTrap(xbl_digestHashType * xDigestHash)
{
    int retVal;
    
    if(NULL == xDigestHash)
    {
        return XBL_ERROR;
    }
    
    retVal = sailhyp_xbl_getHashDigest(xDigestHash);
    
    return retVal;
}

uint32_t  XblHvcTrap(uint32_t ulEventId, XblHvcEventType * pEvent, uint32_t ulEventSize , sailbsp_hvc_rsp_t *rsp)
{

    const char *guid = NULL;
    int ret = XBL_SUCCESS;
    
    if (pEvent == NULL)
    {
        ret = XBL_ERROR_NULL_POINTER;
    }
    else if (ulEventSize != sizeof(XblHvcEventType))
    {
        ret = XBL_ERROR_INVALID_PARAM;
    }
    else if (ulEventId < 0 || ulEventId >= XBL_EL1_EVENT_MAX_NUM)
    {
        ret =  XBL_ERROR_INVALID_PARAM;
    }

    if (ret != XBL_SUCCESS)
    {
        goto end;
    }

    switch (ulEventId)
    {
    case (uint32_t)XBL_EL1_EVENT_LOADER_OPEN:
#ifdef XBL_TRAP_HACK
        ret = XblTrapTestEl1Loader(pEvent);
#else
        ret = XblTrapLoaderOpen(pEvent);
#endif
        break;
        
    case (uint32_t)XBL_EL1_EVENT_LOADER_POLL:
        ret = XblTrapLoaderPollState(pEvent);
        break;

    case (uint32_t)XBL_EL1_EVENT_GET_BOOT_INFO:
        
        ret = XblGetBootInfoTrap(pEvent->xGetBootInfo.xBootInfo,
                                 pEvent->xGetBootInfo.ulArraySize);
        break;

    case (uint32_t)XBL_EL1_EVENT_GET_GUID:
        ret = XblGetImgGUIDTrap(pEvent->xGetImageGuid.imgName,
                                pEvent->xGetImageGuid.FlashPartition,
                                pEvent->xGetImageGuid.FlashGptId,
                                pEvent->xGetImageGuid.imgGuid);
        break;
        
    case (uint32_t)XBL_EL1_EVENT_GET_HASH_DGST:
        ret = XblGetHashDigestTrap(pEvent->xGetHashDigest);
         break;

    default:
        // Non-supported case
        ret = XBL_ERROR_NOT_SUPPORTED;
        break;
    }
    
    end: 
        if (XBL_OK_NOT_DONE != ret)
        {
            memset(&g_xblTrapCtrl, 0, sizeof(g_xblTrapCtrl));
        }

        rsp->data[0] = ret;
        return XBL_SUCCESS;
}

SAIL_DEFINE_SYSCALL(XBL_HVC_ID,
                    XBL_HVC_PARAM_ID,
                    0,
                    XblHvcTrap);
