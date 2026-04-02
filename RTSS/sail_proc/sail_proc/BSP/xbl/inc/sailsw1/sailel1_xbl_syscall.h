/*
===========================================================================
*/
/**
    @file  sailel1_xbl_syscall.h
    @brief sailel1 xbl syscall function definitions

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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/xbl/inc/sailsw1/sailel1_xbl_syscall.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#ifndef __SAIL_EL1_XBL_SYSCALL_H__
#define __SAIL_EL1_XBL_SYSCALL_H__

#include "types.h"
#include "xbl_def.h"
#include "xbl_hvc_event.h"


/**********************************************************
 * Get GUID from Img Name
 *
 *
 * @param imgName [IN]
 *   image name
 *
 * @param FlashPartition [IN]
 *   Flash partition ID
 *
 * @param FlashGptId [IN]
 *   GPT partition ID
 *
 * @param imgGuid [OUT]
 *   GUID string
 *
 * @return int [OUT]
 *   XBL_SUCCESS/ERROR.
 *
 **********************************************************/
int sailEl1XblGetImgGUIDSysCall( const char* imgName, uint32_t FlashPartition, uint32_t FlashGptId, char *imgGuid);

/**********************************************************
 * Query the bootInfo of all images
 *
 *
 * @param bootInfo [OUT]
 *   Boot Info
 *
 * @return int [OUT]
 *   XBL_SUCCESS/ERROR.
 *
 **********************************************************/
int sailEl1XblGetBootInfoSysCall(XBLBootInfoType* bootInfo);

///**********************************************************
// * Verify the GPT validity
// *
// *
// * @param gpt_id [IN]
// *   GPT ID
// *
// * @param verifyGPTparam [OUT]
// *   Verify GPT parameters
// *
/**********************************************************
 * XBL HVC syscall
 *
 *
 * @param eventId [IN]
 *   eventId
 * 
 * @param event [IN]
 *   eventType
 * 
 * @return int [OUT]
 *   XBL_SUCCESS/ERROR.
 *
 **********************************************************/
int sailEl1XblSysCall(uint32_t eventId, XblHvcEventType * event);

#endif
