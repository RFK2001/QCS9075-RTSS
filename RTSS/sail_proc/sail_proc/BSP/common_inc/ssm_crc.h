/**
 * @file crc.h
 *
 * @brief CRC common data structure
 *
 * Copyright (c) 2020-2021 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 *
*/

#ifndef CRC_H
#define CRC_H

#include "safetylibs_types.h"

#ifndef DEBUG_PRINTF
#define DEBUG_PRINTF(...)
#endif

typedef enum {
    SUCCESS = 0x0,
    INVALID_PARAMETER = 0x111,
    CRC_ERROR = 0x222,
    SEQ_ERROR = 0x444,
    BOTH_CRC_SEQ_ERROR = 0x666
} error_type;

#endif
