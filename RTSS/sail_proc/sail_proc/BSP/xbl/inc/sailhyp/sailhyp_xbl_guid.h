/*
===========================================================================
*/
/**
    @file  sailhyp_xbl_guid.h
    @brief sailhyp xbl guid definitions

*/
/*
    ===========================================================================

    Copyright (c) 2021-2022 Qualcomm Technologies, Inc.
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

#ifndef __SAILHYP_XBL_GUID_H__
#define __SAILHYP_XBL_GUID_H__

#include "types.h"
#include "xbl_def.h"

/**********************************************************
 * Get image's GUID
 *
 *
 * @param image_id [IN]
 *   image_id enum
 * @param primary_guid [IN]
 *   TRUE: primary
 *
 * @return const char * [OUT]
 *   GUID string
 *
 **********************************************************/
const char* sailhyp_xbl_boot_get_guid(eXblImageIdType image_id, boolean primary_guid);


#endif  
