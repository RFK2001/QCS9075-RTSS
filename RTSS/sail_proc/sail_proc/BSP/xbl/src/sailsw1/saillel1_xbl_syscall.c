/*
===========================================================================
*/
/**
    @file  sailsw1_xbl_syscall.c
    @brief sailsw1 xbl syscall implementation
*/
/*
    ===========================================================================

    Copyright (c) 2021-2023 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/xbl/src/sailsw1/saillel1_xbl_syscall.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "types.h"
#include "xbl_def.h"
#include "syscall.h"
#include "syscall_pub.h"
#include "syscall_hvc.h"
#include "xbl_diag.h"
#include "xbl_hvc_event.h"
#include "debug_log.h"

int sailEl1XblSysCall(uint32_t eventId, XblHvcEventType * event)
{
    int ret;
    uint32_t hvcId     = XBL_HVC_ID;
    uint32_t paramId   = XBL_HVC_PARAM_ID;

    uint32_t arg1      = (uint32_t)eventId;
    uint32_t arg2      = (uint32_t)event;
    uint32_t arg3      = (uint32_t)sizeof(XblHvcEventType);
    uint32_t arg4      = 0UL;

    ret = hvc_call( &hvcId, &paramId, &arg1, &arg2, &arg3, &arg4);
    if (XBL_SUCCESS != ret)
    {
        XBL_LOG_ERROR("%s: error, hvc call failure, ret = %d\n\r", __func__, ret);    
        return XBL_ERROR;    
    }

    ret = (int)paramId;

    if (XBL_OK_NOT_DONE != ret && XBL_SUCCESS != ret)
    {
        XBL_LOG_ERROR("%s: error, xbl EL2 trap , ret = %d\n\r", __func__, ret);
    }
    return ret;
}


