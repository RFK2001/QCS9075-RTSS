#ifndef SECBOOT_METADATA_PARSER_H
#define SECBOOT_METADATA_PARSER_H

/*****************************************************************************
*
* 
* Copyright (c) 2023 Qualcomm Technologies, Inc.
* All rights reserved.
* Qualcomm Technologies, Inc. Confidential and Proprietary.
*
*****************************************************************************/
#include <stdbool.h>
#include <stdint.h>

#define SECBOOT_METADATA_MAJOR_V0  (0UL)
#define SECBOOT_METADATA_MAJOR_V1  (0UL)
#define SECBOOT_METADATA_MINOR     (0UL)



#define MAX_SOC_VERS 12 /**< MAX number for supported soc hardware version */  
#define MAX_SERIAL_NUM 8 /**< MAX number for supported serial number */  

/* Definition for option lengths in the metadata flags */
#define LEN_ROOT_REVOKE_ACTIVATE_ENABLE    2
#define LEN_UIE_KEY_SWITCH_ENABLE          2
#define LEN_DEBUG                          2

/**
 * meta data flag bit shift definition
 */
typedef enum secboot_metadata_flag_t
{
  E_SECBOOT_METADATA_FLAG_MIN                           = -1,
  E_SECBOOT_METADATA_ROT_EN                             = 0,
  E_SECBOOT_METADATA_IN_USE_SOC_HW_VERSION              = 1,
  E_SECBOOT_METADATA_USE_SERIAL_NUMBER_IN_SIGNING       = 2,
  E_SECBOOT_METADATA_OEM_ID_INDEPENDENT                 = 3,
  E_SECBOOT_METADATA_ROOT_REVOKE_ACTIVATE_ENABLE        = 4,
  E_SECBOOT_METADATA_UIE_KEY_SWITCH_ENABLE              = (E_SECBOOT_METADATA_ROOT_REVOKE_ACTIVATE_ENABLE + LEN_ROOT_REVOKE_ACTIVATE_ENABLE),
  E_SECBOOT_METADATA_DEBUG                              = (E_SECBOOT_METADATA_UIE_KEY_SWITCH_ENABLE + LEN_UIE_KEY_SWITCH_ENABLE),
  E_SECBOOT_METADATA_IN_USE_JTAG_ID                     = (E_SECBOOT_METADATA_DEBUG + LEN_DEBUG),
  E_SECBOOT_METADATA_MODEL_ID_INDEPENDENT               = (E_SECBOOT_METADATA_IN_USE_JTAG_ID + 1),
  E_SECBOOT_METADATA_FLAG_MAX                           = (E_SECBOOT_METADATA_MODEL_ID_INDEPENDENT + 1),
} secboot_metadata_flag_type;


/**
 * meta data field enumeration definition used in function secboot_metadata_get_field()
 */

typedef enum secboot_metadata_field_t
{
  E_SECBOOT_METADATA_FIELD_MIN                          = -1,
  E_SECBOOT_METADATA_MAJOR_VERSION                      = 0,
  E_SECBOOT_METADATA_MINOR_VERSION                      = 1,
  E_SECBOOT_METADATA_SW_ID                              = 2,
  E_SECBOOT_METADATA_HW_ID                              = 3,
  E_SECBOOT_METADATA_OEM_ID                             = 4,
  E_SECBOOT_METADATA_MODEL_ID                           = 5,
  E_SECBOOT_METADATA_SECONDARY_SW_ID                    = 6,
  E_SECBOOT_METADATA_FLAGS                              = 7,
  E_SECBOOT_METADATA_SOC_VERS                           = 8,
  E_SECBOOT_METADATA_SERIAL_NUM                         = (E_SECBOOT_METADATA_SOC_VERS + MAX_SOC_VERS),
  E_SECBOOT_METADATA_ROOT_CERT_SEL                      = (E_SECBOOT_METADATA_SERIAL_NUM + MAX_SERIAL_NUM),
  E_SECBOOT_METADATA_ANTI_ROLLBACK                      = (E_SECBOOT_METADATA_ROOT_CERT_SEL + 1),
  E_SECBOOT_METADATA_FIELD_MAX                          = (E_SECBOOT_METADATA_ANTI_ROLLBACK + 1),
} secboot_metadata_field_type;



/*
 *    Function: secboot_metadata_get_flag
 *      -- returns true if the input flag is set to 1 in the input metadata
 *      -- returns false otherwise
 *      -- if any input parameter is invalid, it returns default_ret_val
 */

bool secboot_metadata_get_flag 
(
  const uint8_t* metadata_info_ptr, 
  secboot_metadata_flag_type flag, 
  bool default_ret_val
);



/*
 *    Function: secboot_metadata_get_option
 *      -- returns the option bits for the below inputs from the input metadata flags
 *          -- E_SECBOOT_METADATA_ROOT_REVOKE_ACTIVATE_ENABLE, 
 *          -- E_SECBOOT_METADATA_UIE_KEY_SWITCH_ENABLE, 
 *          -- E_SECBOOT_METADATA_DEBUG 
 *      -- if any input parameter is invalid, it returns default_ret_val
 */

uint32_t secboot_metadata_get_option 
(
  const uint8_t* metadata_info_ptr, 
  secboot_metadata_flag_type flag, 
  uint32_t default_ret_val
);



/*
 *    Function: secboot_metadata_get_field
 *      -- returns the value for the input field for the given input metadata
 *      -- if any input parameter is invalid, it returns default_ret_val
 */

uint32_t secboot_metadata_get_field 
(
  const uint8_t* metadata_info_ptr, 
  secboot_metadata_field_type field, 
  uint32_t default_ret_val
);


#endif /* SECBOOT_METADATA_PARSER_H */
