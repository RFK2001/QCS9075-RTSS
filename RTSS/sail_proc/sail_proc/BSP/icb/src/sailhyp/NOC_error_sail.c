/*==============================================================================

FILE:      NOC_error_sail.c

DESCRIPTION: This file implements SAIL platform specific NOC Error Handler.

PUBLIC CLASSES:  Not Applicable

INITIALIZATION AND SEQUENCING REQUIREMENTS:  N/A

Edit History

When        Who    What, where, why
----------  ---    ----------------------------------------------------------- 
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
==============================================================================*/

#include "NOC_error.h"
#include "Clock.h"
/*#include "interrupts.h" */ /* for EL 2 */
#include "debug_log.h"
/*============================================================================
                          DEFINEs/MACROs
============================================================================*/

/*============================================================================
                                 FUNCTIONS
============================================================================*/

//*============================================================================*/
/**
@brief
      Gets internal platfrom specific property data structure for configuration.

@param[in]  None.

@return
      NOCERR_propdata_type* Pointer to internal property data structure.

@dependencies
      None.

@sideeffects
      None.
*/
/*============================================================================*/
NOCERR_propdata_type *NOC_ErrPltfrmGetPrgmData(void)
{

   NOCERR_propdata_type *noc_propdata = NULL;

   ICB_LeManSailVersion_el2 = ChipInfo_GetSailChipVersion();
   ICB_SailFamily_el2 = ChipInfo_GetChipFamily();


   NOCERR_config_info_type *configs = (NOCERR_config_info_type *)NOC_Error_Platform_Get_Data();
   uint32_t i;

   if(configs == NULL)
   {
     return NULL;
   }

   for( i = 0U; i < configs->num_configs; i++ )
   {
     NOCERR_propdata_type *device_config = &configs->configs[i];
     if( ICB_SailFamily_el2 != device_config->family )
     {
         continue;
     }

     /* We've found a matching version in two different conditions:
       * We have an exact match
       * We don't need an exact match and the version is great than or equal to 
       * what we're looking for. */
     if( ICB_LeManSailVersion_el2 == device_config->version ||
         (false == device_config->match && ICB_LeManSailVersion_el2 >= device_config->version) )
     {
         noc_propdata = device_config;
         break;
     }
   }

   /* Check to see if we found a matching configuration. */
   if( i == configs->num_configs )
   {
     DEBUG_LOG(SAIL_INFO,"[ICB] : NOC_ERR_DEV_CFG_NOT_FOUND\n\r")
   }


   return noc_propdata;
}

//*============================================================================*/
/**
@brief
      Gets OEM platfrom specific property data structure for configuration.

@param[in]  None.

@return
      NOCERR_propdata_type_oem* Pointer to OEM property data structure.

@dependencies
      None.

@sideeffects
      None.
*/
/*============================================================================*/
NOCERR_propdata_type_oem* NOC_ErrPltfrmGetPrgmData_OEM(void)
{

   NOCERR_propdata_type_oem *noc_propdata_oem = NULL;

   ICB_LeManSailVersion_el2 = ChipInfo_GetSailChipVersion();
   ICB_SailFamily_el2 = ChipInfo_GetChipFamily();

   NOCERR_config_info_type_oem *configs = (NOCERR_config_info_type_oem *)NOC_ErrPltfrmGetData_OEM();
   uint32_t i;

   if(configs == NULL)
   {
     return NULL;
   }

      for( i = 0; i < configs->num_configs; i++ )
      {
      NOCERR_propdata_type_oem *device_config = &configs->configs[i];
      if( ICB_SailFamily_el2 != device_config->family )
      {
            continue;
      }

      /* We've found a matching version in two different conditions:
            * We have an exact match
            * We don't need an exact match and the version is great than or equal to 
            * what we're looking for. */
      if( ICB_LeManSailVersion_el2 == device_config->version ||
            (false == device_config->match && ICB_LeManSailVersion_el2 >= device_config->version) )
      {
            noc_propdata_oem = device_config;
            break;
      }
      }

      /* Check to see if we found a matching configuration. */
      if( i == configs->num_configs )
      {
      DEBUG_LOG(SAIL_ERROR, "NOC ERR DEV CFG NOT FOUND\n\r")
      }


   return noc_propdata_oem;
}
