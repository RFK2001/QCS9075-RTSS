#ifndef SAIL_SEC_FUSE_H
#define SAIL_SEC_FUSE_H

/*===========================================================================
  Copyright (c) 2022-2023 Qualcomm Technologies, Inc.  All Rights Reserved.
  Qualcomm Technologies Proprietary and Confidential.
===========================================================================*/

#include <stdint.h>
#include <stdbool.h>
#include "sail_sec_err_fatal.h"
#include "sail_sec_hwio.h"
#include "HALhwio.h"

/**
@file SAIL_SEC_FUSE.h
@brief Provide FUSE related to segment hash algorithm to be used 
*/

#define get_segment_hash_fn_select(x)          ((HWIO_IN( SAILSS_SECURITY_CONTROL_OEM_CONFIG2)) >> (HWIO_SAILSS_SECURITY_CONTROL_OEM_CONFIG2_SEGMENT_HASH_FUNCTION_SELECT_0_SHFT + (x))) & 0x1

#endif
