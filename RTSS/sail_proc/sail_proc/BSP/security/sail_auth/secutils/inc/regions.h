/*===========================================================================
 Copyright (c) 2014-2015  Qualcomm Technologies, Inc.
 All Rights Reserved.
 Confidential and Proprietary - Qualcomm Technologies, Inc.
===========================================================================*/
#ifndef REGIONS_H
#define REGIONS_H

#include <stdint.h>
#include <stdbool.h>

typedef struct
{
  uint64_t start;
	uint64_t end;
} region_t;

typedef enum
{
  REGION_EQUAL,
  REGION_NO_OVERLAP,
  REGION_ADJACENT,
  REGION_OVERLAP_INNER,
  REGION_OVERLAP_INNER_ADJACENT, 
  REGION_OVERLAP_OUTER,
  REGION_OVERLAP_OUTER_ADJACENT,
  REGION_OVERLAP,
} region_overlap_t;

region_overlap_t region_overlap
(
  uint64_t start1, uint64_t end1, uint64_t start2, uint64_t end2
);

// Returns true if region 1 is contained within region 2
bool region_is_contained_in
(
  uint64_t start1, uint64_t end1, uint64_t start2, uint64_t end2
);

#endif

