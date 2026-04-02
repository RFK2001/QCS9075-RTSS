/*===========================================================================
 Copyright (c) 2019-2020, 2022 Qualcomm Technologies, Inc.
 All Rights Reserved.
 Confidential and Proprietary - Qualcomm Technologies, Inc.
===========================================================================*/
#ifndef SAIL_SEC_WHITELIST_H
#define SAIL_SEC_WHITELIST_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief This function checks if address range is part of whitelist
 *
 * @param addr            	  [in] start address of the region 
 * @param size			      [in] size of the region 
 *
 * @return \c TRUE if address range is in whitelist. FALSE otherwise
 *
 */
bool sail_sec_is_ns_range(const uint8_t *start, size_t size);

/**
 * @brief This function checks if region 2 is contained within region 1
 *
 * @param s1            	  [in] start address of the region 1
 * @param e1			      [in] end address of the region 1
 * @param s2            	  [in] start address of the region 2
 * @param e2			      [in] end address of the region 2
 *
 * @return \c TRUE/FALSE
 *
 */
bool region_is_contained(uintptr_t s1, uintptr_t e1, uintptr_t s2, uintptr_t e2);

#endif /* SAIL_SEC_WHITELIST_H */
