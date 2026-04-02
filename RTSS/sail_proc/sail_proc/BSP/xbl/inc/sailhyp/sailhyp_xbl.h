/*
===========================================================================
*/
/**
    @file  sailhyp_xbl.h
    @brief sailhyp xbl definitions

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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/xbl/inc/sailhyp/sailhyp_xbl.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#ifndef __SAILHYP_XBL_H__
#define __SAILHYP_XBL_H__

#include "types.h"
#include "xbl_def.h"



typedef struct
{
    const char* img_name;        /* Image name */
    uint32_t core_id;            /* The core used to load this image */
    eXblImageIdType image_id;    /* XBL defined image ID */
    boolean status;              /* load status */
    uint32_t partition_id;       /* loaded primary GUID or secondary GUID */
    uint32_t gpt_id;             /* loaded from primary GPT table or secondary GPT table */
    uint32_t image_entry;        /* image entry point */
    boolean is_updatable;        /* Flag to know if the Image is updatable using Updater */
    uint64_t start_time;         /* start timestamp */
    uint64_t end_time;           /* end timestamp */
    uint64_t durationUs;         /* Boot duration in microseconds */
} xbl_boot_image_info_t;


#endif
