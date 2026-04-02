/*==============================================================================

FILE:      NOC_error_OEM_data.c

DESCRIPTION: This file contains target/platform specific configuration data.

PUBLIC CLASSES:  Not Applicable

INITIALIZATION AND SEQUENCING REQUIREMENTS:  N/A
 
Edit History

When        Who    What, where, why
----------  ---    -----------------------------------------------------------
    Copyright (c) 2023-2024 Qualcomm Technologies, Inc.
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
#include "NOC_error_HWIO_R2.h"
#include "debug_log.h"
#include "chipinfo.h"

/*============================================================================
                           TARGET SPECIFIC DATA
============================================================================*/

/*============================================================================
                        DEVICE CONFIG PROPERTY DATA
============================================================================*/
/* OEM NOC Configuration Data for Lemans Auto */

NOCERR_info_type_oem NOCERR_cfgdata_oem_R2[4] =
{ 
  [0] = {
    .name        = "ASIL_D_NOC",
    .intr_enable = true, 
    .error_fatal = false, /* Intentionally not fatal so that SMMU faults will not crash in TZ. */
    .sbms        = (NOCERR_sbm_info_type_oem []){ 
        [0] = { .faultin_en0_low = 0xFFFFFFFFU , /* Ignore correctable faults. */
        	    .faultin_en0_high = 0x87FU }, /* Stuck to 0 port are set to 0*/
    },
    .obs_mask    = (NOCERR_sbm_info_type_oem []){ 
        [0] = { .faultin_en0_low =  0x0U ,
        	    .faultin_en0_high = 0x0U }, /* obs/Fault[0] are set to 1 */
      },
    .to_reg_vals = (uint32_t []){ 0x1U,   /**< TRCHECK_REFERENCEGENERATOR_0_REFGEN_MAINCTL_LOW  */
                                  0x100U,     /**< TRCHECK_REFERENCEGENERATOR_0_REFGEN_REFCTL1_LOW  */
                                  0x1U,   /**< TRCHECK_REFERENCEGENERATOR_1_REFGEN_MAINCTL_LOW  */
                                  0x100U,     /**< TRCHECK_REFERENCEGENERATOR_1_REFGEN_REFCTL1_LOW  */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL0_LOW    */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL1_LOW    */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL2_LOW    */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL3_LOW    */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL4_LOW    */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL5_LOW    */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL6_LOW    */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL7_LOW    */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL8_LOW    */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL9_LOW    */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL10_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL11_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL12_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL13_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL14_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL15_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL16_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL17_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL18_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL19_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL20_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL21_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL22_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL23_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL24_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL25_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL26_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL27_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL28_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL29_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL30_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL31_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL32_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL33_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL34_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL35_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL36_LOW   */
                                  0x1U,   /**< REFERENCEGENERATOR_REFGEN_MAINCTL_LOW    */
                                 },
    .sfty_ctl    = (NOCERR_sfty_ctl_info_type_oem []){
        [0] = { .outen_low = 0x3U },
    },
  },
  [1] = {
    .name        = "ASIL_B_NOC",
    .intr_enable = true, 
    .error_fatal = false, /* Intentionally not fatal so that SMMU faults will not crash in TZ. */
    .sbms        = (NOCERR_sbm_info_type_oem []){ 
        [0] = { .faultin_en0_low = 0x3FFFFFFU }, /* Ignore correctable faults. */
      },
    .obs_mask    = (NOCERR_sbm_info_type_oem []){ 
        [0] = { .faultin_en0_low = 0x0U },
      },
    .to_reg_vals = (uint32_t []){ 0x100U,     /**< REFERENCEGENERATOR_REFGEN_REFCTL0_LOW    */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL1_LOW    */
                                  0x100U,     /**< REFERENCEGENERATOR_REFGEN_REFCTL2_LOW    */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL3_LOW    */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL0_LOW    */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL1_LOW    */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL2_LOW    */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL3_LOW    */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL4_LOW    */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL5_LOW    */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL6_LOW    */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL7_LOW    */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL8_LOW    */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL9_LOW    */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL10_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL11_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL12_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL13_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL14_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL15_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL16_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL17_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL18_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL19_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL20_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL21_LOW   */
                                  0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL22_LOW   */
                                  0x1U,   /**< REFERENCEGENERATOR_REFGEN_MAINCTL_LOW    */
                                },
    .sfty_ctl    = (NOCERR_sfty_ctl_info_type_oem []){
        [0] = { .outen_low = 0x3U },
    },
  },
  [2] = {
      .name        = "ASIL_D_ISOLATION_NOC",
      .intr_enable = true,
      .error_fatal = false, /* Intentionally not fatal so that SMMU faults will not crash in TZ. */
      .sbms        = (NOCERR_sbm_info_type_oem []){
          [0] = { .faultin_en0_low = 0x3U},
          [1] = { .faultin_en0_low = 0x7U}/* Ignore correctable faults. */
        },
      .obs_mask    = (NOCERR_sbm_info_type_oem []){
          [0] = { .faultin_en0_low = 0x0U },
        },
      .to_reg_vals = (uint32_t []){ 0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL0_LOW    */
        	                        0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL1_LOW    */
                                    0x1U,   /**< REFERENCEGENERATOR_REFGEN_MAINCTL_LOW    */
        },
      .sfty_ctl    = (NOCERR_sfty_ctl_info_type_oem []){
          [0] = { .outen_low = 0x3U },
      },
    },
    [3] = {
        .name        = "ASIL_B_ISOLATION_NOC",
        .intr_enable = true,
        .error_fatal = false, /* Intentionally not fatal so that SMMU faults will not crash in TZ. */
        .sbms        = (NOCERR_sbm_info_type_oem []){
            [0] = { .faultin_en0_low = 0x1FU },
            [1] = { .faultin_en0_low = 0x3U },
        },
        .obs_mask    = (NOCERR_sbm_info_type_oem []){
            [0] = { .faultin_en0_low = 0x0U },
          },
        .to_reg_vals = (uint32_t []){ 0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL0_LOW    */
        	          	              0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL1_LOW    */
        	          	              0x100U,   /**< REFERENCEGENERATOR_REFGEN_REFCTL2_LOW    */
        	                          0x1U,   /**< REFERENCEGENERATOR_REFGEN_MAINCTL_LOW    */
          },
        .sfty_ctl    = (NOCERR_sfty_ctl_info_type_oem []){
            [0] = { .outen_low = 0x3U },
        },
      }
};

uint32_t clock_reg_vals_R2[3] =
{
  [0] = 0x1U,  /* Enable timeout reference clock */
  [1] = 0x3U,  /* Set first divider to DIV4, so that we hit 4.8 MHz.
               * Used by QoS reference and initial step of timeout reference. */
  [2] = 0x1FU, /* Second divider to DIV32, so our timeout reference is 150 KHz.
                 With a timeout counter of 1024 (default with refctl), this
                 means we have a timeout of 6.82 ms base. (1024)/(19.2MHz/4/32)=6.82 ms */
};

/* MonacoAu family identification */

NOCERR_config_info_type_oem NOCERR_propdata_oem_R2 =
{
  .num_configs = 1U,
  .configs = (NOCERR_propdata_type_oem [])
    {
      /* Target info: Lemans v1.0 */
      [0] = 
        {
          .family         = CHIPINFO_FAMILY_LEMANSAU,
          .match          = false,
          .version        = CHIPINFO_VERSION(2U,0U),

          .len            = sizeof(NOCERR_cfgdata_oem_R2)/sizeof(NOCERR_info_type_oem),
          .NOCInfoOEM     = NOCERR_cfgdata_oem_R2,
          .clock_reg_vals = clock_reg_vals_R2,
        },
    },
};

/* MonacoAu family identification */

NOCERR_config_info_type_oem NOCERR_propdata_oem_MONACOAU =
{
  .num_configs = 1U,
  .configs = (NOCERR_propdata_type_oem [])
    {
      /* Target info: Lemans v1.0 */
      [0] =
        {
          .family         = CHIPINFO_FAMILY_MONACOAU,
          .match          = false,
          .version        = CHIPINFO_VERSION(1U,0U),

          .len            = sizeof(NOCERR_cfgdata_oem_R2)/sizeof(NOCERR_info_type_oem),
          .NOCInfoOEM     = NOCERR_cfgdata_oem_R2,
          .clock_reg_vals = clock_reg_vals_R2,
        },
    },
};

/*============================================================================
                                 FUNCTIONS
============================================================================*/
NOCERR_config_info_type_oem*  NOC_ErrPltfrmGetData_OEM(void)
{
	NOCERR_config_info_type_oem *NOCERR_config_info_oem = NULL;

 	ICB_LeManSailVersion_el2 = ChipInfo_GetSailChipVersion();
 	ICB_SailFamily_el2 = ChipInfo_GetChipFamily();

	if (CHIPINFO_FAMILY_MONACOAU == ICB_SailFamily_el2 )
	{

		//DEBUG_LOG(SAIL_INFO,"[ICB] : OEM CHIPINFO_FAMILY_MONACOAU         \n\r" );
		NOCERR_config_info_oem = &NOCERR_propdata_oem_MONACOAU;
	}
	else
	{
	    if(ICB_LeManSailVersion_el2 == ICB_LEMANS_SAIL_R1_VERSION )
	    {
	    	DEBUG_LOG(SAIL_ERROR,"[ICB] : LEMANS_SAIL_R1_VERSION is not supported.\n\r" );
	    }
	    else
	    {
	    	//DEBUG_LOG(SAIL_INFO,"[ICB] : OEM R2 ICB_LeManSailVersion_el2         \n\r" );
	    	NOCERR_config_info_oem = &NOCERR_propdata_oem_R2;
	    }

	}
           return NOCERR_config_info_oem ;
}

/**********************************************************************************************************
**                                  End of file                                                         **
**********************************************************************************************************/
