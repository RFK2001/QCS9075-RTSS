#ifndef __EXTERNAL_BUILD_FLAG_H__
#define __EXTERNAL_BUILD_FLAG_H__

/*
===========================================================================
*/
/**
    @file  external_build_flag.h
    @brief File to disable external build code

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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/tests/public/external_build_flag.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#define VIP_FIRMWARE_CHECK_FOR_INTERNAL_BUILD //flag for only internal build

//  hshar - Disabling SAIL FS Driver
// #define SAILFS_INTERNAL_DRIVER_FLAG     //  to disable SAIL FS driver

#endif /* __EXTERNAL_BUILD_FLAG_H__ */
