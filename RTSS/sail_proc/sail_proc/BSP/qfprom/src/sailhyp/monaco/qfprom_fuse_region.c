/*===========================================================================

  QFPROM  Driver Source  Code

  DESCRIPTION
  Contains target specific definitions and APIs to be used to read and write
  qfprom values for sec ctrl 3.0.

  INITIALIZATION AND SEQUENCING REQUIREMENTS
  None
  ============================================================================*/

/*=============================================================================
  Copyright (c) 2021 Qualcomm Technologies, Incorporated.
  All rights reserved.
  Qualcomm Technologies, Confidential and Proprietary.
  =============================================================================*/

/*===========================================================================

  EDIT HISTORY FOR FILE

  This section contains comments describing changes made to this file.
  Notice that changes are listed in reverse chronological order.

  $Header: //components/dev/bsp.sail/1.0/pvairave.bsp.sail.1.0.monaco_qfprom/qfprom/src/8650/qfprom_fuse_region.c#1 $

  when       who     what, where, why
  --------   ---     ----------------------------------------------------------
  03/23/20   sp      Initial revision

  ============================================================================*/

/*=============================================================================

  INCLUDE FILES FOR MODULE

  =============================================================================*/
#include "qfprom_target.h"
#include "security_control_hwioreg.h"

/*=============================================================================

  LOCAL DEFINITIONS AND DECLARATIONS FOR MODULE

  This section contains local definitions for constants, macros, types,
  variables and other items needed by this module.

  =============================================================================*/
/*
 **  Array containing QFPROM data items that can be read and associated
 **  registers, mask and shift values for the same.
 */
const QFPROM_REGION_INFO qfprom_region_data[] = {
	{
		QFPROM_MRC_2_0_REGION,                                                                  /* Region Name */
		2,                                                                                      /* Size - how many rows region takes */
		QFPROM_FEC_NONE,                                                                        /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_MRC_2_0_ROW0_LSB_ADDR,                          /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_MRC_2_0_ROW0_LSB_ADDR,                         /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_MRC_READ_DISABLE_BMSK,    /* Read permission */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_MRC_2_0_WRITE_DISABLE_BMSK,                      /* Write permission */
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		0                                                                                       /* QFPROM Region Index */
	},

	{
		QFPROM_PTE_REGION,                                                                      /* Region Name */
		4,                                                                                      /* Size - how many rows region takes */
		QFPROM_FEC_NONE,                                                                        /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_PTE_ROW0_LSB_ADDR,                                                      /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_PTE_ROW0_LSB_ADDR,                                                     /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_PTE_READ_DISABLE_BMSK,                            /* Read permission */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_PTE_WRITE_DISABLE_BMSK,                          /* Write permission */
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		1                                                                                       /* QFPROM Region Index */
	},

	{
		QFPROM_READ_PERMISSION_REGION,                                                          /* Region Name */
		1,                                                                                      /* Size - how many rows region takes */
		QFPROM_FEC_NONE,                                                                        /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_READ_PERMISSIONS_LSB_ADDR,                                              /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_ADDR,                                             /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_READ_PERMISSION_READ_DISABLE_BMSK,                /* Read permission */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_READ_PERMISSIONS_WRITE_DISABLE_BMSK,             /* Write permission */
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		2                                                                                       /* QFPROM Region Index */
	},

	{
		QFPROM_WRITE_PERMISSION_REGION,                                                         /* Region Name */
		1,                                                                                      /* Size - how many rows region takes */
		QFPROM_FEC_NONE,                                                                        /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_WRITE_PERMISSIONS_LSB_ADDR,                                             /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_ADDR,                                            /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_WRITE_PERMISSION_READ_DISABLE_BMSK,               /* Read permission */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_WRITE_PERMISSIONS_WRITE_DISABLE_BMSK,            /* Write permission */
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		3                                                                                       /* QFPROM Region Index */
	},

	{
		QFPROM_FEC_ENABLES_REGION,                                                              /* Region Name */
		1,                                                                                      /* Size - how many rows region takes */
		QFPROM_FEC_NONE,                                                                        /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_FEC_ENABLES_LSB_ADDR,                                                   /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_FEC_ENABLES_LSB_ADDR,                                                  /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_FEC_ENABLES_READ_DISABLE_BMSK,                    /* Read permission */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_FEC_ENABLES_WRITE_DISABLE_BMSK,                  /* Write permission */
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		4                                                                                       /* QFPROM Region Index */
	},

	{
		QFPROM_OEM_CONFIG_REGION,                                                               /* Region Name */
		3,                                                                                      /* Size - how many rows region takes */
		QFPROM_FEC_NONE,                                                                        /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_OEM_CONFIG_ROW0_LSB_ADDR,                                               /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_OEM_CONFIG_ROW0_LSB_ADDR,                                              /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_OEM_CONFIGURATION_READ_DISABLE_BMSK,              /* Read permission */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_OEM_CONFIGURATION_WRITE_DISABLE_BMSK,            /* Write permission */
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		5                                                                                       /* QFPROM Region Index */
	},

	{
		QFPROM_FEATURE_CONFIG_M_REGION,                                                         /* Region Name */
		4,                                                                                      /* Size - how many rows region takes */
		QFPROM_FEC_NONE,                                                                        /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_FEATURE_CONFIG_M_ROW0_LSB_ADDR,                                         /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_FEATURE_CONFIG_M_ROW0_LSB_ADDR,                                        /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_FEATURE_CONFIGURATION_M_READ_DISABLE_BMSK,        /* Read permission */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_FEATURE_CONFIGURATION_M_WRITE_DISABLE_BMSK,      /* Write permission */
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		6                                                                                      /* QFPROM Region Index */
	},

	{
		QFPROM_FEATURE_CONFIG_NM_REGION,                                                        /* Region Name */
		5,                                                                                      /* Size - how many rows region takes */
		QFPROM_FEC_NONE,                                                                        /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_FEATURE_CONFIG_NM_ROW0_LSB_ADDR,                                        /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_FEATURE_CONFIG_NM_ROW0_LSB_ADDR,                                       /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_FEATURE_CONFIGURATION_NM_READ_DISABLE_BMSK,       /* Read permission */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_FEATURE_CONFIGURATION_NM_WRITE_DISABLE_BMSK,     /* Write permission */
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		7                                                                                      /* QFPROM Region Index */
	},

	{
		QFPROM_ANTI_ROLLBACK_1_REGION,                                                          /* Region Name */
		1,                                                                                      /* Size - how many rows region takes */
		QFPROM_FEC_NONE,                                                                        /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_1_LSB_ADDR,                                               /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_ANTI_ROLLBACK_1_LSB_ADDR,                                              /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_ANTI_ROLLBACK_1_READ_DISABLE_BMSK,                /* Read permission */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_ANTI_ROLLBACK_1_WRITE_DISABLE_BMSK,              /* Write permission */
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		8                                                                                       /* QFPROM Region Index */
	},

	{
		QFPROM_ANTI_ROLLBACK_2_REGION,                                                          /* Region Name */
		1,                                                                                      /* Size - how many rows region takes */
		QFPROM_FEC_NONE,                                                                        /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_2_LSB_ADDR,                                               /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_ANTI_ROLLBACK_2_LSB_ADDR,                                              /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_ANTI_ROLLBACK_2_READ_DISABLE_BMSK,                /* Read permission */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_ANTI_ROLLBACK_2_WRITE_DISABLE_BMSK,              /* Write permission */
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		9                                                                                       /* QFPROM Region Index */
	},

	{
		QFPROM_ANTI_ROLLBACK_3_REGION,                                                          /* Region Name */
		1,                                                                                      /* Size - how many rows region takes */
		QFPROM_FEC_NONE,                                                                        /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_3_LSB_ADDR,                                               /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_ANTI_ROLLBACK_3_LSB_ADDR,                                              /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_ANTI_ROLLBACK_3_READ_DISABLE_BMSK,                /* Read permission */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_ANTI_ROLLBACK_3_WRITE_DISABLE_BMSK,              /* Write permission */
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		10                                                                                      /* QFPROM Region Index */
	},

	{
		QFPROM_ANTI_ROLLBACK_4_REGION,                                                          /* Region Name */
		1,                                                                                      /* Size - how many rows region takes */
		QFPROM_FEC_NONE,                                                                        /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_4_LSB_ADDR,                                               /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_ANTI_ROLLBACK_4_LSB_ADDR,                                              /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_ANTI_ROLLBACK_4_READ_DISABLE_BMSK,                /* Read permission */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_ANTI_ROLLBACK_4_WRITE_DISABLE_BMSK,              /* Write permission */
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		11                                                                                      /* QFPROM Region Index */
	},

	{
		QFPROM_ANTI_ROLLBACK_5_REGION,                                                          /* Region Name */
		1,                                                                                      /* Size - how many rows region takes */
		QFPROM_FEC_NONE,                                                                        /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_5_LSB_ADDR,                                               /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_ANTI_ROLLBACK_5_LSB_ADDR,                                              /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_ANTI_ROLLBACK_5_READ_DISABLE_BMSK,                /* Read permission */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_ANTI_ROLLBACK_5_WRITE_DISABLE_BMSK,              /* Write permission */
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		12                                                                                      /* QFPROM Region Index */
	},

	{
		QFPROM_ANTI_ROLLBACK_6_REGION,                                                          /* Region Name */
		1,                                                                                      /* Size - how many rows region takes */
		QFPROM_FEC_NONE,                                                                        /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_6_LSB_ADDR,                                               /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_ANTI_ROLLBACK_6_LSB_ADDR,                                              /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_ANTI_ROLLBACK_6_READ_DISABLE_BMSK,                /* Read permission */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_ANTI_ROLLBACK_6_WRITE_DISABLE_BMSK,              /* Write permission */
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		13                                                                                      /* QFPROM Region Index */
	},

	{
		QFPROM_ANTI_ROLLBACK_7_REGION,                                                          /* Region Name */
		1,                                                                                      /* Size - how many rows region takes */
		QFPROM_FEC_NONE,                                                                        /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_7_LSB_ADDR,                                               /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_ANTI_ROLLBACK_7_LSB_ADDR,                                              /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_ANTI_ROLLBACK_7_READ_DISABLE_BMSK,                /* Read permission */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_ANTI_ROLLBACK_7_WRITE_DISABLE_BMSK,              /* Write permission */
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		14                                                                                      /* QFPROM Region Index */
	},

	{
		QFPROM_ANTI_ROLLBACK_8_REGION,                                                          /* Region Name */
		1,                                                                                      /* Size - how many rows region takes */
		QFPROM_FEC_NONE,                                                                        /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_8_LSB_ADDR,                                               /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_ANTI_ROLLBACK_8_LSB_ADDR,                                              /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_ANTI_ROLLBACK_8_READ_DISABLE_BMSK,                /* Read permission */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_ANTI_ROLLBACK_8_WRITE_DISABLE_BMSK,              /* Write permission */
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		15                                                                                      /* QFPROM Region Index */
	},

	{
		QFPROM_ANTI_ROLLBACK_9_REGION,                                                          /* Region Name */
		1,                                                                                      /* Size - how many rows region takes */
		QFPROM_FEC_NONE,                                                                        /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_9_LSB_ADDR,                                               /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_ANTI_ROLLBACK_9_LSB_ADDR,                                              /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_ANTI_ROLLBACK_9_READ_DISABLE_BMSK,                /* Read permission */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_ANTI_ROLLBACK_9_WRITE_DISABLE_BMSK,              /* Write permission */
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		16                                                                                      /* QFPROM Region Index */
	},

	{
		QFPROM_ANTI_ROLLBACK_10_REGION,                                                          /* Region Name */
		1,                                                                                      /* Size - how many rows region takes */
		QFPROM_FEC_NONE,                                                                        /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_ANTI_ROLLBACK_10_LSB_ADDR,                                               /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_ANTI_ROLLBACK_10_LSB_ADDR,                                              /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_ANTI_ROLLBACK_10_READ_DISABLE_BMSK,                /* Read permission */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_ANTI_ROLLBACK_10_WRITE_DISABLE_BMSK,              /* Write permission */
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		17                                                                                      /* QFPROM Region Index */
	},
	{
		QFPROM_PDU_REGION,                                                          			/* Region Name */
		1,                                                                                      /* Size - how many rows region takes */
		QFPROM_FEC_NONE,                                                                        /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_PDU_LSB_ADDR,                                               /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_PDU_LSB_ADDR,                                              /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_PDU_READ_DISABLE_BMSK,                /* Read permission */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_PDU_WRITE_DISABLE_BMSK,              /* Write permission */
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		18                                                                                      /* QFPROM Region Index */
	},
	{
		QFPROM_PK_HASH_0_REGION,                                                                /* Region Name */
		8,                                                                                      /* Size - how many rows region takes */
		QFPROM_FEC_NONE,                                                                        /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_PK_HASH_0_ROW0_LSB_ADDR,                                                /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_PK_HASH_0_ROW0_LSB_ADDR,                                               /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_PUBLIC_KEY_HASH_0_READ_DISABLE_BMSK,              /* Read permission */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_PUBLIC_KEY_HASH_0_WRITE_DISABLE_BMSK,            /* Write permission */
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		19                                                                                      /* QFPROM Region Index */
	},

	{
		QFPROM_CALIBRATION_REGION,                                                              /* Region Name */
		28,                                                                                     /* Size - how many rows region takes */
		QFPROM_FEC_NONE,                                                                        /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_CALIBRATION_ROW0_LSB_ADDR,                                              /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_CALIBRATION_ROW0_LSB_ADDR,                                             /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_CALIBRATION_READ_DISABLE_BMSK,                    /* Read permission */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_CALIBRATION_WRITE_DISABLE_BMSK,                  /* Write permission */
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		20                                                                                      /* QFPROM Region Index */
	},

	{
		QFPROM_MEMORY_CONFIGURATION_REGION,                                                     /* Region Name */
		22,                                                                                     /* Size - how many rows region takes */
		QFPROM_FEC_NONE,                                                                        /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_MEMORY_CONFIGURATION_ROW0_LSB_ADDR,                                     /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_MEMORY_CONFIGURATION_ROW0_LSB_ADDR,                                    /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_MEMORY_CONFIGURATION_READ_DISABLE_BMSK,           /* Read permission */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_MEMORY_CONFIGURATION_WRITE_DISABLE_BMSK,         /* Write permission */
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		21                                                                                      /* QFPROM Region Index */
	},

	{
		QFPROM_QC_SPARE_20_REGION,                                                              /* Region Name */
		3,                                                                                      /* Size - how many rows region takes */
		QFPROM_FEC_NONE,                                                                        /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_QC_SPARE_20_ROW0_LSB_ADDR,                                                   /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_QC_SPARE_20_ROW0_LSB_ADDR,                                                  /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_QC_SPARE_20_READ_DISABLE_BMSK,                    /* Read permission */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_QC_SPARE_20_WRITE_DISABLE_BMSK,                  /* Write permission */
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		22                                                                                      /* QFPROM Region Index */
	},

	{
		QFPROM_QC_SPARE_21_REGION,                                                              /* Region Name */
		2,                                                                                      /* Size - how many rows region takes */
		QFPROM_FEC_NONE,                                                                        /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_QC_SPARE_21_ROW0_LSB_ADDR,                                                   /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_QC_SPARE_21_ROW0_LSB_ADDR,                                                  /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_QC_SPARE_21_READ_DISABLE_BMSK,                    /* Read permission */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_QC_SPARE_21_WRITE_DISABLE_BMSK,                  /* Write permission */
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		23                                                                                      /* QFPROM Region Index */
	},

	{
		QFPROM_SAIL_BIST_CONFIG_REGION,                                                          /* Region Name */
		202,                                                                                     /* Size - how many rows region takes */
		QFPROM_FEC_63_56,                                                                        /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_SAIL_BIST_CONFIG_ROW0_LSB_ADDR,                                                   /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_SAIL_BIST_CONFIG_ROW0_LSB_ADDR,                                                  /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_SAIL_BIST_CONFIG_READ_DISABLE_BMSK,                    /* Read permission */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_SAIL_BIST_CONFIG_WRITE_DISABLE_BMSK,                  /* Write permission */
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		24                                                                                      /* QFPROM Region Index */
	},

	{
		QFPROM_OEM_IMAGE_ENCRYPTION_KEY_REGION,                                                 /* Region Name */
		3,                                                                                      /* Size - how many rows region takes */
		QFPROM_FEC_63_56,                                                                       /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_OEM_IMAGE_ENCRYPTION_KEY_ROW0_LSB_ADDR,                                 /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_OEM_IMAGE_ENCRYPTION_KEY_ROW0_LSB_ADDR,                                /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_OEM_IMAGE_ENCRYPTION_KEY_READ_DISABLE_BMSK,       /* Read permission */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_OEM_IMAGE_ENCRYPTION_KEY_WRITE_DISABLE_BMSK,     /* Write permission */
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		25                                                                                      /* QFPROM Region Index */
	},

	{
		QFPROM_OEM_SECURE_BOOT_REGION,                                                          /* Region Name */
		2,                                                                                      /* Size - how many rows region takes */
		QFPROM_FEC_63_56,                                                                       /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_OEM_SECURE_BOOT_ROW0_LSB_ADDR,                                          /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_OEM_SECURE_BOOT_ROW0_LSB_ADDR,                                         /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_OEM_SECURE_BOOT_READ_DISABLE_BMSK,                /* Read permission */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_OEM_SECURE_BOOT_WRITE_DISABLE_BMSK,              /* Write permission */
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		26                                                                                      /* QFPROM Region Index */
	},

	{
		QFPROM_BOOT_ROM_PATCH_REGION,                                                   /* Region Name */
		56,                                                                                      /* Size - how many rows region takes */
		QFPROM_FEC_63_56,                                                                       /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_BOOT_ROM_PATCH_ROW0_LSB_ADDR,                                   /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_BOOT_ROM_PATCH_ROW0_LSB_ADDR,                                  /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_BOOT_ROM_PATCH_READ_DISABLE_BMSK,   /* Read permission */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_BOOT_ROM_PATCH_WRITE_DISABLE_BMSK, /* Write permission */
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		27                                                                                      /* QFPROM Region Index */
	},

	{
		QFPROM_IMAGE_ENCRYPTION_KEY_1_REGION,                                                   /* Region Name */
		3,                                                                                      /* Size - how many rows region takes */
		QFPROM_FEC_63_56,                                                                       /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_IMAGE_ENCRYPTION_KEY_1_ROW0_LSB_ADDR,                                   /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_IMAGE_ENCRYPTION_KEY_1_ROW0_LSB_ADDR,                                  /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_IMAGE_ENCRYPTION_KEY_1_READ_DISABLE_BMSK,         /* Read permission */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_IMAGE_ENCRYPTION_KEY_1_WRITE_DISABLE_BMSK,       /* Write permission */
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		28                                                                                      /* QFPROM Region Index */
	},

	{
		QFPROM_USER_KEY_DERIVATION_KEY_REGION,                                                  /* Region Name */
		5,                                                                                      /* Size - how many rows region takes */
		QFPROM_FEC_63_56,                                                                       /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_USER_KEY_DERIVATION_KEY_ROW0_LSB_ADDR,                                  /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_USER_KEY_DERIVATION_KEY_ROW0_LSB_ADDR,                                 /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_USER_KEY_DERIVATION_KEY_READ_DISABLE_BMSK,        /* Read permission */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_USER_KEY_DERIVATIONKEY_WRITE_DISABLE_BMSK,       /* Write permission */
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		29                                                                                      /* QFPROM Region Index */
	},

	{
		QFPROM_OEM_SPARE_30_REGION,                                                             /* Region Name */
		12,                                                                                      /* Size - how many rows region takes */
		QFPROM_FEC_NONE,                                                                        /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_OEM_SPARE_30_ROW0_LSB_ADDR,                                             /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_OEM_SPARE_30_ROW0_LSB_ADDR,                                            /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_OEM_SPARE_30_READ_DISABLE_BMSK,                   /* Read permission */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_OEM_SPARE_30_WRITE_DISABLE_BMSK,                 /* Write permission */       //ToDo rrahul -- check why LSB BMSK is not available.
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		30                                                                                      /* QFPROM Region Index */
	},

	{
		QFPROM_OEM_SPARE_31_REGION,                                                             /* Region Name */
		12,                                                                                      /* Size - how many rows region takes */
		QFPROM_FEC_NONE,                                                                        /* FEC type - bits that contain FEC */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_RAW_OEM_SPARE_31_ROW0_LSB_ADDR,                                             /* Raw address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_OEM_SPARE_31_ROW0_LSB_ADDR,                                            /* Corrected address of the region */
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_OEM_SPARE_31_READ_DISABLE_BMSK,                   /* Read permission */         //ToDo rrahul -- check why LSB BMSK is not available.
		HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_OEM_SPARE_31_WRITE_DISABLE_BMSK,                 /* Write permission */
		QFPROM_ROW_LSB,                                                                         /* LSB or MSB of QFPROM permission region */
		true,                                                                                   /* Read Allow */
		31                                                                                      /* QFPROM Region Index */
	},

	/* Add above this entry */
	{
		QFPROM_LAST_REGION_DUMMY,
		0,
		QFPROM_FEC_NONE,
		0,
		0,
		0,
		0,
		QFPROM_ROW_LSB
	}
};
