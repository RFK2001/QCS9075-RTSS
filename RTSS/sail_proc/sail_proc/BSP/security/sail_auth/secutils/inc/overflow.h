/* ============================================================================
 * @file  overflow.h
 * @brief Overflow macro
 *
 * Copyright (c) 2022-2023 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 * ============================================================================
 */

#ifndef OVERFLOW_H
#define OVERFLOW_H

#define UNSIGNED_ADD_OVERFLOW(type, a, b) (((b) > (((type)(-1)) - (a))) ? (1U) : (0U))
#define UNSIGNED_MUL_OVERFLOW(type, a, b) (((b) > (((type)(-1)) / (a))) ? (1U) : (0U))

#endif

