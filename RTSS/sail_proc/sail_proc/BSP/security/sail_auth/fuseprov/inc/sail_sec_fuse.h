#ifndef SAIL_SEC_FUSE_H
#define SAIL_SEC_FUSE_H

/**
@file sail_sec_fuse.h
@brief Provide HW Fuse functionality
*/

/*===========================================================================
  Copyright (c) 2011-2017,2020 Qualcomm Technologies, Inc.
  All Rights Reserved.
  Confidential and Proprietary - Qualcomm Technologies, Inc.
===========================================================================*/

/*----------------------------------------------------------------------------
 * Include Files
 * -------------------------------------------------------------------------*/
//#include <comdef.h>
//#include <stdint.h>
//#include <stddef.h>
//#include "qfprom.h"
#include "types.h"

/*----------------------------------------------------------------------------
 * Preprocessor Definitions and Constants
 * -------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 * Type Declarations
 * -------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 * External API Declarations
 * -------------------------------------------------------------------------*/
/**
 * @brief     Fuse write row
 * @param[in]  raw_row_address
 * @param[in]  row_data is array of two uin32 values (LSB/MSB) 
 * @param[in]  bus_clk_khz 
 * @param[out] qfprom_api_status
 * @return    0 on success, negative on failure
 */
int sail_sec_fuse_write
(
  uint32_t    raw_row_address,
  uint32_t*   row_data,
  uint32_t    bus_clk_khz,
  uint32_t*   qfprom_api_status
);

/**
 * @brief     Fuse read row
 * @param[in]  row_address
 * @param[in]  addr_type
 * @param[out] row_data is array of two uin32 values (LSB/MSB)
 * @param[out] qfprom_api_status
 * @return    0 on success, negative on failure
 */
int sail_sec_fuse_read
(
  uint32_t   row_address,
  int32_t    addr_type,
  uint32_t*  row_data,
  uint32_t*  qfprom_api_status
);

#endif /* SAIL_SEC_FUSE_H */