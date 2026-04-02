/*
===========================================================================
*/
/**
    @file  sailel1_xbl.h
    @brief sailel1 xbl api function definitions

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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/xbl/public/sailsw1/sailel1_xbl_api.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#ifndef   SAIL_EL1_XBL_API_H
#define   SAIL_EL1_XBL_API_H

#include "types.h"
#include "xbl_def.h"

int sailEl1XblInit(void);
int sailEl1XblGetImgGUID( const char* imgName, uint32_t FlashPartition, uint32_t FlashGptId, char *imgGuid);
int sailEl1XblGetBootInfo(XBLBootInfoType* bootInfo, uint32_t ulArraySize);
int sailEl1XblLoaderOpen(xbl_boot_params_t * boot_param);
int sailEl1XblLoaderPollState(uint32_t * ulEntryPoint);
int sailEl1XblGetDigestHash(xbl_digestHashType * xDigestHash);

#endif /* SAIL_EL1_XBL_API_H */
