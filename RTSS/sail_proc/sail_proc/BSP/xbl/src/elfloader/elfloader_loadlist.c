/*
===========================================================================
*/
/**
    @file  elfloader_loadlist.c
    @brief loadlist implementation. Supports blacklist and whitelist

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

    $Header: $
    $DateTime: $
    $Author: $

    ===========================================================================
*/

#include "types.h"
#include "xbl_def.h"
#include "elfloader_loadlist.h"
#include "elfloader_def.h"
#include "xbl_mem.h"
#include "elfloader_auth.h"
#include "xbl_diag.h"

/**
 * @brief API to see if the region has to be booted or not
 * 
 * @param sec_img_id 
 * @param ramStartAddr 
 * @param size 
 * @param loadListParam 
 * @return boolean 
 */
boolean bElfloaderCheckLoadList(uint32 ramStartAddr, uint32 size, sec_img_auth_whitelist_area_param_t *loadListParam)
{
    uint32 ramEndAddr = ramStartAddr + size - 1U;
    for (uint32 i = 0; i < loadListParam->count; i++)
    {
        if ( loadListParam->area[i].start <= ramStartAddr && ramEndAddr < loadListParam->area[i].end )
        {
            return TRUE;
        }
        else
        {
            /* do nothing */
        }
    }
    return FALSE;
}

int xElfloaderGetSecImageLoadlist(xbl_mem_loadlist_param_t *in_mem_loadlist,
                                  sec_img_auth_whitelist_area_param_t **out_sec_loadlist)
{
    if (NULL == out_sec_loadlist || NULL == in_mem_loadlist)
    {
        return XBL_ERROR_NULL_POINTER;
    }
    *out_sec_loadlist = (sec_img_auth_whitelist_area_param_t *)xblMalloc(sizeof(sec_img_auth_whitelist_area_param_t));

    if (NULL == (*out_sec_loadlist))
    {
        return XBL_ERROR_NO_MEM;
    }

    (*out_sec_loadlist)->count = in_mem_loadlist->count;
    (*out_sec_loadlist)->area = (sec_img_auth_whitelist_area_t *)xblMalloc(sizeof(sec_img_auth_whitelist_area_t) * (*out_sec_loadlist)->count);
    if (NULL == (*out_sec_loadlist)->area)
    {
        vElfloaderPutSecImageLoadlist(out_sec_loadlist);
        return XBL_ERROR_NO_MEM;
    }
    for (uint i = 0; i < (*out_sec_loadlist)->count; i++)
    {
        (*out_sec_loadlist)->area[i].start = in_mem_loadlist->area[i].start ;
        (*out_sec_loadlist)->area[i].end   = in_mem_loadlist->area[i].end;
    }
    return XBL_SUCCESS;
}

void vElfloaderPutSecImageLoadlist(sec_img_auth_whitelist_area_param_t ** ppLoadlist)
{
    if (ppLoadlist != NULL && *ppLoadlist != NULL)
    {
       sec_img_auth_whitelist_area_param_t *loadlist = *ppLoadlist;
        if (loadlist->area != NULL)
        {
            xblFree(loadlist->area);
        }
        xblFree(loadlist);
        *ppLoadlist = NULL;
    }
}


