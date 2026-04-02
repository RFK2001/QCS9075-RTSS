/*
===========================================================================
*/
/**
    @file  xbl_mem.c
    @brief mem wrapper

*/
/*
    ===========================================================================

    Copyright (c) 2022 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/mingchen.bsp.sail.1.0.sailtip_08_09/xbl/src/elfloader/elfloader_mem.c#1 $
    $DateTime: 2022/08/09 11:03:10 $
    $Author: mingchen $

    ===========================================================================
*/

#include <stdlib.h>
#include <string.h>
#include "sailbsp_mutex.h"
#include "sailheap.h"
#include "common_functions.h"
#include "cache_ops.h"
#include "xbl_mem.h"
#include "xbl_diag.h"

#define XBL_MAX_CORE_ID    4U

#ifdef XBL_MEM_DBG
static uint32_t g_ulMemCnt[XBL_MAX_CORE_ID];
#endif
void xblMemInit(void)
{
#ifdef XBL_MEM_DBG
    memset ( g_ulMemCnt, 0, sizeof(g_ulMemCnt) );
#endif
}

void *xblMalloc(size_t size)
{
    void *tmp = NULL;
    tmp = sailheap_malloc(size);
#ifdef XBL_MEM_DBG
    g_ulMemCnt[get_curr_phys_cpu_num()] += 1U;
#endif
    return tmp;
}

void xblFree(void *mem)
{
    if ( mem )
    {
        sailheap_free(mem);
#ifdef XBL_MEM_DBG
    g_ulMemCnt[get_curr_phys_cpu_num()] -= 1U;
#endif
    }
}

boolean xblMemCheckLeak(void)
{
    boolean status = TRUE;
#ifdef XBL_MEM_DBG
    status = g_ulMemCnt[get_curr_phys_cpu_num()] == 0U;
#endif
    return status;
}

