#ifndef QFPROMDEFS_H
#define QFPROMDEFS_H

/**
@file QFPROMDefs.h
@brief Provide QFPROM definitions
*/

/*=============================================================================
            Copyright (c) 2023 Qualcomm Technologies, Incorporated.
                              All rights reserved.
              Qualcomm Technologies, Confidential and Proprietary.
=============================================================================*/

/*===========================================================================

                            EDIT HISTORY FOR FILE

when       who      what, where, why
--------   ---      ------------------------------------

===========================================================================*/

/*----------------------------------------------------------------------------
 * Include Files
 * -------------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
/*----------------------------------------------------------------------------
 * Type Declarations
 * -------------------------------------------------------------------------*/

 /**
 QFPROM address space. The address space can contain either raw
 (uncorrected) or corrected (FEC-corrected) data.
 */
typedef enum
{
  QFPROM_ADDR_SPACE_RAW = 0,            /**< Raw address space. */
  QFPROM_ADDR_SPACE_CORR,               /**< Corrected address space. */
  QFPROM_ADDR_SPACE_MAX = 0x7FFFFFFF    /**< Last entry in the QFPROM_ADDR_SPACE enumerator.*/
} QFPROM_ADDR_SPACE;

/**
 Identifies the error type returned by the QFPROM API.
 */
typedef enum
{
  QFPROM_NO_ERR = 0U,                            /**< Operation was successful. */
  QFPROM_DATA_PTR_NULL_ERR,                     /**< Null pointer error. */
  QFPROM_ADDRESS_INVALID_ERR,                   /**< Incorrect fuse row address. */
  QFPROM_CLOCK_SETTINGS_INVALID_ERR,            /**< Invalid settings for the
                                                     QFPROM clock. */
  QFPROM_NO_SPECIAL_ITEM_FOUND_ERR,             /**< Deprecated. */
  QFPROM_OPERATION_NOT_ALLOWED_ERR,             /**< Operation is not allowed;
                                                     the hardware is busy. */
  QFPROM_FAILED_TO_CHANGE_VOLTAGE_ERR,          /**< Error when changing the
                                                     PMIC/voltage configuration. */
  QFPROM_WRITE_ERR,                             /**< Write operation failed. */
  QFPROM_REGION_NOT_SUPPORTED_ERR,              /**< Unsupported region for
                                                     reading/blowing fuses. */
  QFPROM_REGION_NOT_READABLE_ERR,               /**< No permission to read from fuses
                                                     in the requested region. */
  QFPROM_REGION_NOT_WRITEABLE_ERR,              /**< No permission to write to fuses
                                                     in the requested region. */
  QFPROM_REGION_FEC_ENABLED_NOT_WRITEABLE_ERR,  /**< Write failed due to an
                                                     FEC-enabled fuse. */
  QFPROM_REGION_RAW_ADDR_READ_BACK_VERIFY_ERR,  /**< Verification error when writing
                                                     to a raw address space. */
  QFPROM_REGION_CORR_ADDR_READ_BACK_VERIFY_ERR, /**< Verification error when writing
                                                     to a corrected address space. */
  QFPROM_ROW_BOUNDARY_CONDITION_VERIFY_ERR,     /**< Row address is not in the
                                                     region's LSB boundary. */
  QFPROM_FEC_ERR,                               /**< FEC read error. */
  
  QFPROM_INVALID_INDEX,                         /**< Fuse region index is invalid>*/

  /* Please add new enum value here and keep the value incremental to the predecessor */

  QFPROM_ERR_UNKNOWN = 0x7FFFFFFFU              /**<  Last entry in the QFPROM_ERR_CODE enumerator. */
} QFPROM_ERR_CODE;

/**
 * HW version details of QFPROM
*/
typedef struct {
    uint16_t Major;
    uint16_t Minor;
    uint16_t Step;
} QFPROMHWVersion;

#endif      /*QFPROMDEFS_H*/
