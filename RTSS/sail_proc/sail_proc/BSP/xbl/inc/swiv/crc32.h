/* ===========================================================================

    Copyright (c) 2023 Qualcomm Technologies, Inc.
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

    =========================================================================== */

/*=================================================================================================
    File Name          : crc32.h
    Description        : CRC32 API and data structure.
=================================================================================================*/

#ifndef CRC32_H
#define CRC32_H

#include "ssm_crc.h"

#ifdef CRC32_DEBUG_ENABLED
#include "xbl_diag.h"
#define CRC_DEBUG_LOG XBL_LOG_INFO
#else
#define CRC_DEBUG_LOG(...)
#endif

/**
 * 
 * @brief Scatter buffer structure
 *
*/
struct scatter_buffer
{
    char *buf;          /**< data buffer */
    sl_size_t len;      /**< length of the data buffer */
};

#ifdef __cplusplus
extern "C" {
#endif

/**
 * crc32_generate() -  Calculate CRC value
 * @param[in] buf:    Input data buffer pointer
 * @param[in] len:    length of the data buffer
 * @param[out] crc:   OUTPUT parameter that will contain the value of generated CRC result
 * 
 * Used by message sender to generate a CRC value for specific data and length.
 * 
 * @return:
 * SUCCESS:   successfully generate CRC.
 * INVALID_PARAMETER:  parameter invalid.
 */
error_type crc32_generate(const char *buf, sl_size_t len, sl_u32_t *crc);

/**
 * crc32_verify() -  Verify CRC value
 * @param[in] buf:    Input data buffer pointer
 * @param[in] len:    length of the data buffer
 * @param[in] crc:    The CRC that calculated by message sender
 * 
 * Used by message receiver to verify the CRC value for specific data and length.
 * 
 * @return:
 * SUCCESS:   successfully verify CRC.
 * INVALID_PARAMETER:  parameter invalid.
 * CRC_ERROR:  Recalculated CRC mismatch with received CRC.
 */
error_type crc32_verify(const char *buf, sl_size_t len, sl_u32_t crc);

/**
 * crc32_generate_scatter() -  Calculate CRC value for multiple data payloads
 * @param[in] sbuf:     Scatter buffer array pointer
 * @param[in] num:      Number of the scatter buffer
 * @param[out] crc:     OUTPUT parameter that will contain the value of generated CRC result
 * 
 * Used by message sender to generate a CRC value for separate data payload.
 * 
 * @return:
 * SUCCESS:   generate CRC successfully.
 * INVALID_PARAMETER:  Parameter invalid.
 */
error_type crc32_generate_scatter(const struct scatter_buffer *sbuf, sl_size_t num, sl_u32_t *crc);

/**
 * crc32_verify_scatter() -  Verify CRC value for multiple data payloads
 * @param[in] sbuf:   Scatter buffer array pointer
 * @param[in] num:    Number of the scatter buffer
 * @param[in] crc:    The CRC to be verified
 * 
 * Used by message receiver to verify the CRC value for specific data and length.
 * 
 * @return:
 * SUCCESS:   successfully verify CRC.
 * INVALID_PARAMETER:  Parameter invalid.
 * CRC_ERROR:  Recalculated CRC mismatch with received CRC.
 */
error_type crc32_verify_scatter(const struct scatter_buffer *sbuf, sl_size_t num, sl_u32_t crc);

#ifdef __cplusplus
}
#endif

#endif
