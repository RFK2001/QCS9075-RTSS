/*
===========================================================================
*/
/**
    @file  spinor_access.c
    @brief Get the regions that need protection (block IO Access)

*/
/*
    ===========================================================================

    Copyright (c) 2018,2021-2024 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/src/driver/spinor_access.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/
#include "spinor_access.h"

#ifdef SPINOR_USE_ACCESS

static char *partition_accesslist[MAX_PARTITIONS] = {
  "spinor/region1",
  "spinor/region2",
};

typedef struct
{
   uint32 num_partitions;
   spinor_partition_info partition_entries[MAX_PARTITIONS];
} spinor_partition_record;

static spinor_partition_record partition_list = {0};

spinor_partition_info *devcfg_get_partition_info(uint32 *count)
{
  partition_list.partition_entries[0].slot = 0;
  partition_list.partition_entries[0].partition = 0;
  partition_list.partition_entries[0].start_sector = 0x6;
  partition_list.partition_entries[0].num_sectors = 0x84;
  partition_list.num_partitions++;


  partition_list.partition_entries[1].slot = 0;
  partition_list.partition_entries[1].partition = 0;
  partition_list.partition_entries[1].start_sector = 0x8A;
  partition_list.partition_entries[1].num_sectors = 0xA3;


  *count = partition_list.num_partitions;
  if (*count == 0)
    return NULL;
  return &partition_list.partition_entries[0];
}

spinor_partition_info *spinor_devcfg_protected_regions(uint32 *count)
{
  *count =0;
  return NULL;
}
#endif /* SPINOR_USE_ACCESS */