#ifndef __SPINOR_ACCESS_H__
#define __SPINOR_ACCESS_H__
/*
===========================================================================
*/
/**
    @file  spinor_access.h
    @brief Get the regions that need protection (block IO Access)

*/
/*
    ===========================================================================

    Copyright (c) 2018-2024 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/inc/driver/spinor_access.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "types.h"

//#define SPINOR_USE_ACCESS

#define MAX_PARTITIONS 2

typedef struct
{
   uint32 slot;
   uint32 partition;
   uint64 start_sector;
   uint64 num_sectors;
} spinor_partition_info;

/* Get the list of regions that need to be protected from IO. */
spinor_partition_info *spinor_devcfg_protected_regions(uint32 *count);

#endif /* __SPINOR_ACCESS_H__ */
