#ifndef QFPROM_TARGET_H
#define QFPROM_TARGET_H

/*===========================================================================

                        QFPROM  Driver Header  File

DESCRIPTION
 Contains target specific defintions and APIs to be used to read and write
 qfprom values for sec ctrl 3.0 .

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


when       who     what, where, why
--------   ---     ----------------------------------------------------------
03/23      sp      Initial version for Makena

============================================================================*/

/*===========================================================================

                           INCLUDE FILES

===========================================================================*/
#include "QFPROMDefs.h"
#include <HALhwio.h>

#define ALIGN(__value) __attribute__((__aligned__(__value)))

/*===========================================================================

                      PUBLIC DATA DECLARATIONS

===========================================================================*/

typedef enum
{
  QFPROM_FEC_NONE = 0,
  QFPROM_FEC_15_10,
  QFPROM_FEC_63_56,
  QFPROM_FEC_62_56,

  /* Add above this */
  QFPROM_MAX_FEC
}QFPROM_FEC_SCHEME;

typedef enum
{
  QFPROM_CONV_FORMAT_RAW_TO_CORR = 0,
  QFPROM_CONV_FORMAT_CORR_TO_RAW = 1,
}QFPROM_CONV_FORMAT;

typedef enum
{
  QFPROM_ROW_LSB = 0,
  QFPROM_ROW_MSB,
}QFPROM_ROW;

/* Blow timer clock frequency in Mhz for 5nm FF technology */
#define QFPROM_BLOW_TIMER_CLK_FREQ_MHZ    4.8
#define SAIL_XO_FREQ_IN_HZ                19200000

/* Amount of time required to hold charge to blow fuse in micro-seconds */
#define QFPROM_FUSE_BLOW_TIME_IN_US       5.0

//This data is from HPG and it is a multiple of QFPROM_BLOW_TIMER_CLK_FREQ_MHZ*QFPROM_FUSE_BLOW_TIME_IN_US
#define QFPROM_BLOW_TIMER_SETTING_VALUE   0x19

/*
* Configure QFPROM_ACCEL[QFPROM_GATELAST] SW field to a default value of 0x1 for 5nm FF SOC technology.
* Configure QFPROM_ACCEL[QFPROM_TRIPPT_SEL] SW field to a value of 0x5 (101) to blow at a high resistance setting
* Configure QFPROM_ACCEL[QFPROM_ACCEL] SW field to a value of 0x10.
*/
#define QFPROM_GATELAST_VAL            0x1
#define QFPROM_TRIPPT_SEL_VAL          0x4
#define QFPROM_ACCEL_VAL               0x10

#define QFPROM_ACCEL_VALUE             HWIO_FVAL(SAILSS_SECURITY_CONTROL_QFPROM_ACCEL,  QFPROM_GATELAST,  QFPROM_GATELAST_VAL) | \
                                       HWIO_FVAL(SAILSS_SECURITY_CONTROL_QFPROM_ACCEL, QFPROM_TRIPPT_SEL, QFPROM_TRIPPT_SEL_VAL) | \
                                       HWIO_FVAL(SAILSS_SECURITY_CONTROL_QFPROM_ACCEL, QFPROM_ACCEL, QFPROM_ACCEL_VAL)

/* QFPROM_ACCEL register default values */

#define QFPROM_GATELAST_RESET_VAL            0x1
#define QFPROM_TRIPPT_SEL_RESET_VAL          0x0
#define QFPROM_ACCEL_RESET_VAL               0x0

#define QFPROM_ACCEL_RESET_VALUE       HWIO_FVAL(SAILSS_SECURITY_CONTROL_QFPROM_ACCEL, QFPROM_GATELAST,  QFPROM_GATELAST_RESET_VAL) | \
                                       HWIO_FVAL(SAILSS_SECURITY_CONTROL_QFPROM_ACCEL, QFPROM_TRIPPT_SEL, QFPROM_TRIPPT_SEL_RESET_VAL) | \
                                       HWIO_FVAL(SAILSS_SECURITY_CONTROL_QFPROM_ACCEL, QFPROM_ACCEL, QFPROM_ACCEL_RESET_VAL)

/* Invalid entry */
#define QFPROM_INVALID_ENTRY 0xFFFFFFFFU

/* Raw to Corrected Address region offset  */
#define QFPROM_RAW_TO_CORRECTED_ADDRESS_OFFSET   (0x4000U)

/* Macro for Read/write permission of corrected address */
#define QFPROM_READ_PERM_CORRECTED_ADDR         HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_LSB_ADDR
#define QFPROM_READ_PERM_CORRECTED_MSB_ADDR     HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_READ_PERMISSIONS_MSB_ADDR

#define QFPROM_WRITE_PERM_CORRECTED_ADDR        HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_LSB_ADDR
#define QFPROM_WRITE_PERM_CORRECTED_MSB_ADDR    HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_WRITE_PERMISSIONS_MSB_ADDR

/* Macro for Corrected FEC enable */
#ifndef HWIO_QFPROM_CORR_FEC_EN_LSB_ADDR
#define HWIO_QFPROM_CORR_FEC_EN_LSB_ADDR HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_FEC_ENABLES_LSB_ADDR
#endif
#ifndef HWIO_QFPROM_CORR_FEC_EN_MSB_ADDR
#define HWIO_QFPROM_CORR_FEC_EN_MSB_ADDR HWIO_SAILSS_SECURITY_CONTROL_QFPROM_CORR_FEC_ENABLES_MSB_ADDR
#endif

/*---------------------------------------------------------------------------
  QFPROM REGIONS 
---------------------------------------------------------------------------*/
typedef enum
{
  QFPROM_CRI_CM_PRIVATE_REGION = 0,         /*  0 */ 
  QFPROM_LCM_REGION,                        /*  1 */
  QFPROM_PRI_KEY_DERIVATION_KEY_REGION,     /*  2 */
  QFPROM_CM_FEATURE_CONFIG_REGION,          /*  3 */
  QFPROM_MRC_2_0_REGION,                    /*  4 */ 
  QFPROM_PTE_REGION,                        /*  5 */          
  QFPROM_READ_PERMISSION_REGION,            /*  6 */
  QFPROM_WRITE_PERMISSION_REGION,           /*  7 */
  QFPROM_FEC_ENABLES_REGION,                /*  8 */
  QFPROM_OEM_CONFIG_REGION,                 /*  9 */
  QFPROM_FEATURE_CONFIG_M_REGION,           /* 10 */
  QFPROM_FEATURE_CONFIG_NM_REGION,          /* 11 */
  QFPROM_ANTI_ROLLBACK_1_REGION,            /* 12 */
  QFPROM_ANTI_ROLLBACK_2_REGION,            /* 13 */
  QFPROM_ANTI_ROLLBACK_3_REGION,            /* 14 */
  QFPROM_ANTI_ROLLBACK_4_REGION,            /* 15 */
  QFPROM_ANTI_ROLLBACK_5_REGION,            /* 16 */
  QFPROM_ANTI_ROLLBACK_6_REGION,            /* 17 */
  QFPROM_ANTI_ROLLBACK_7_REGION,            /* 18 */
  QFPROM_ANTI_ROLLBACK_8_REGION,            /* 19 */
  QFPROM_ANTI_ROLLBACK_9_REGION,            /* 20 */
  QFPROM_ANTI_ROLLBACK_10_REGION,           /* 21 */
  QFPROM_ANTI_ROLLBACK_11_REGION,           /* 22 */
  QFPROM_ANTI_ROLLBACK_12_REGION,           /* 23 */
  QFPROM_ANTI_ROLLBACK_13_REGION,           /* 24 */
  QFPROM_PK_HASH_0_REGION,                  /* 25 */
  QFPROM_CALIBRATION_REGION,                /* 26 */
  QFPROM_MEMORY_CONFIGURATION_REGION,       /* 27 */
  QFPROM_QC_SPARE_20_REGION,                /* 28 */
  QFPROM_QC_SPARE_21_REGION,                /* 29 */
  QFPROM_OEM_IMAGE_ENCRYPTION_KEY_REGION,   /* 30 */
  QFPROM_OEM_SECURE_BOOT_REGION,            /* 31 */
  QFPROM_SEC_KEY_DERIVATION_KEY_REGION,     /* 32 */
  QFPROM_BOOT_ROM_PATCH_REGION,             /* 33 */
  QFPROM_IMAGE_ENCRYPTION_KEY_1_REGION,     /* 34 */
  QFPROM_USER_KEY_DERIVATION_KEY_REGION,    /* 35 */
  QFPROM_OEM_SPARE_28_REGION,               /* 36 */
  QFPROM_OEM_SPARE_29_REGION,               /* 37 */
  QFPROM_OEM_SPARE_30_REGION,               /* 38 */
  QFPROM_OEM_SPARE_31_REGION,               /* 39 */
  QFPROM_PDU_REGION,                        /* 40 */
  QFPROM_SAIL_BIST_CONFIG_REGION,           /* 41 */
  
  /* Add above this */
  QFPROM_LAST_REGION_DUMMY,
  QFPROM_MAX_REGION_ENUM                = 0x7FFF /* To ensure it's 16 bits wide */
} QFPROM_REGION_NAME;


typedef struct
{
  /* region name; added only for readability */  
  ALIGN(4) QFPROM_REGION_NAME  region;

  /* how many rows the region takes */
  uint32_t                       size;
  
  /*  fec type of region */
  ALIGN(4) QFPROM_FEC_SCHEME   fec_type;
  
  /* raw address  of the region */
  uint32_t                        raw_base_addr;      
  
  /* corrected address of the region */
  uint32_t                        corr_base_addr;
  
  /* can we read this region    */
  uint32_t                        read_perm_mask;      
  
  /* can we write to this region    */
  uint32_t                        write_perm_mask;
  
  /* LSB or MSB  of the qfprom permission region */
  ALIGN(4) QFPROM_ROW           perm_reg_type;
  
  /* Region read-able/non-read-able */
  ALIGN(4) bool              read_allowed;	
  
  /* Region index */
  uint32_t                        qfprom_region_index;	
  
} QFPROM_REGION_INFO;


typedef struct
{
    /* Row address */
    uint32_t   raw_row_address;

    /* MSB row data */
    uint32_t   row_data_msb;
    
    /* LSB row data */
    uint32_t   row_data_lsb;
} write_row_type;


extern const QFPROM_REGION_INFO qfprom_region_data[];


/*===========================================================================

                      PUBLIC FUNCTION DECLARATIONS

===========================================================================*/


/*===========================================================================

**  Function :

** ==========================================================================
*/
/*!
*   qfprom_is_region_readable
* 
* @brief
*   This function shall return if the read permission for the region passed is available or not.
* 
* @par Dependencies
*    None
* 
* @param
*   region - The QFPROM region to be checked.
* 
* @retval bool 
*                         - true - permission is available 
*                         - false - permission is not available 
* 
* @par Side Effects
* 
*/
bool qfprom_is_region_readable
(
    QFPROM_REGION_NAME  region
);

/*===========================================================================

**  Function :    qfprom_is_region_writeable

** ==========================================================================
*/
/*!
*   qfprom_is_region_writeable
* 
* @brief
*   This function shall return if the write permission for the region passed is available or not.
* 
* @par Dependencies
*    None
* 
* @param
*   region - The QFPROM region to be checked.
* 
* @retval bool 
*                         - true - permission is available 
*                         - false - permission is not available 
* 
* @par Side Effects
* 
*/
bool qfprom_is_region_writeable
(
    QFPROM_REGION_NAME  region
);

/*===========================================================================

**  Function : qfprom_get_region_name

** ==========================================================================
*/
/*!
* 
* @brief
*   This function gets the region of the given row address which need to be a RAW
*   address.
*  
* @par Dependencies
*   None.
*     
* @param:
*   uint32_t  address - Address of the Row.
*   QFPROM_ADDR_SPACE addr_type - Raw or Corrected address,
*   QFPROM_REGION_NAME* region_type - QFPROM Region of the Row address 
*                                                              passed.
* 
* @retval
* @retval: return - QFPROM_NO_ERR - if the operation is success.
*                           error_type           - if the operation is failure.                      
* @par Side Effects
*   None.
* 
*   
*/
QFPROM_ERR_CODE qfprom_get_region_name
 (
    uint32_t address,
    QFPROM_ADDR_SPACE addr_type,
    QFPROM_REGION_NAME* region_type    
 );

/*===========================================================================

**  Function : qfprom_is_fec_enabled

** ==========================================================================
*/
/*!
* 
* @brief
*   This function shall check the FEC status of the given Raw region row address.
*  
* @par Dependencies
*   None.
*     
* @param:
*   uint32_t row_address - Address of the Row.
*   bool *fec_status - true , FEC is enabled. 
*                                   false , FEC is disabled..
* 
* @retval
* @retval: return - QFPROM_NO_ERR - if the operation is success.
*                           error_type           - if the operation is failure.                      
* @par Side Effects
*   None.
* 
*/

QFPROM_ERR_CODE qfprom_is_fec_enabled
(
    QFPROM_REGION_NAME    region_type,
    bool *fec_status
);


/*===========================================================================

FUNCTION  qfprom_chk_cnvrt_to_active_addr

DESCRIPTION
    This function shall check the address the appropriate voltage dependent settings for the qfprom block.

PARAMETERS
    uint32_t   row_address  - Pointer to the row address to be checked 
    uint32_t   *active_row_address  - Pointer to the active row address after conversion 

DEPENDENCIES
  None.
 
RETURN VALUE
  uint32_t  Any Errors while setting up the system before blowing the fuses.

SIDE EFFECTS
  Disables the vreg being used.

===========================================================================*/

QFPROM_ERR_CODE qfprom_chk_cnvrt_to_active_addr
(
    uint32_t row_address,
    uint32_t*active_row_address
);


/*===========================================================================

FUNCTION  qfprom_chkbound_cond_row_addr

DESCRIPTION
    This function shall check the boundary condition for the row address to be operated.

PARAMETERS
    uint32_t   row_address  - Row address to be checked 

DEPENDENCIES
  None.
 
RETURN VALUE
  QFPROM_ERR_CODE  Any Errors while setting up the system before blowing the fuses.

SIDE EFFECTS
  Disables the vreg being used.

===========================================================================*/

QFPROM_ERR_CODE qfprom_chkbound_cond_row_addr
(
    uint32_t row_address
);


/*===========================================================================

FUNCTION  QFPROM_WRITE_FUSE_INIT

DESCRIPTION
  Here we might need to enable appropriate volatge regulator for each target.
  Currently MDM9x00 have volatge regulators ON by default.  
PARAMETERS
  None.

DEPENDENCIES
  None.
 
RETURN VALUE
  QFPROM_ERR_CODE  Any Errors while setting up the system before blowing the fuses.

SIDE EFFECTS
  Turns on qfprom clock and enables VREG_GP5.

===========================================================================*/
QFPROM_ERR_CODE qfprom_write_fuse_init( void );

/*===========================================================================

FUNCTION  QFPROM_WRITE_FUSE_CLEANUP

DESCRIPTION
  This function is going to use PMIC library API to trun OFF the LDO.
  Currently though for MDM9x00 we do not need to do anything.
 
DEPENDENCIES
  None.

PARAMETERS
  None.
 
RETURN VALUE
  QFPROM_ERR_CODE   Any Errors while doing the cleanup.

SIDE EFFECTS
  Turns off qfprom clock and disables VREG_GP5.

===========================================================================*/
QFPROM_ERR_CODE qfprom_write_fuse_cleanup( void );

/*===========================================================================

FUNCTION  qfprom_is_write_opr_allowed

DESCRIPTION
  This function returns whether the clocks and voltage regulators have been
  setup correctly for writing fuses. 

DEPENDENCIES
  None.

PARAMETERS
  None.
 
RETURN VALUE
  bool  Whether writing of fuses has been enabled.

SIDE EFFECTS
  None.

===========================================================================*/
bool qfprom_is_write_opr_allowed ( void );


/*===========================================================================

**  Function : qfprom_get_region_index

** ==========================================================================
*/
/*!
* 
* @brief
*  This function gets the index of the region to which the given row address
*  belongs
*  
* @par Dependencies
*  None.
*     
* @param:
*  uint32_t address - Address of the Row.
*  QFPROM_ADDR_SPACE addr_type - Raw or Corrected address,
*  uint32_t *region_index - pointer to address location which will
*                          be filled in with index value by api.
* 
* @retval
* @retval: return - QFPROM_NO_ERR - if the operation is success.
*                   error_type    - if the operation is failure.                      
* @par Side Effects
*  None.
* 
*   
*/
QFPROM_ERR_CODE qfprom_get_region_index
(
    uint32_t address,
    QFPROM_ADDR_SPACE addr_type,
    uint32_t *region_index
);


/*===========================================================================
**  Function :    : qfprom_write

** ==========================================================================
*/
/*!
*
* @brief :  This function writes the actual raw data to the row
*
*
* @param  :
*                 uint32_t   raw_row_address,
*                 uint32_t   *raw_data_to_write     - Pointer to data.
* @par Dependencies:
*
* @retval: return - QFPROM_NO_ERR - if the operation is success.
*                    error_type           - if the operation is failure.
*
* @par Side Effects:
* algo: Write the lower 32 bits and wait for the fuse write status to be ok.
*       Then write the upper 32 bits
*       If the write operation goes ok return QFPROM_NO_ERR else the error value.
*/
QFPROM_ERR_CODE qfprom_write
(
    uint32_t   raw_row_address,
    uint32_t   *raw_data_to_write
);


/*===========================================================================
**  Function :    : qfprom_write_chck_row_precond

** ==========================================================================
*/
/*!
*
* @brief :  This function shall check if the row address is part of supported QFPROM Region
*            returns the status.
*
* @param  :
*                 uint32_t   raw_row_address,
*                 uint32_t   *row_data,           - Pointer to data.
*                 QFPROM_REGION_NAME* region_type
* @par Dependencies:
*
* @retval: return - QFPROM_NO_ERR - if the operation is success.
*                   error_type           - if the operation is failure.
*
*/
QFPROM_ERR_CODE qfprom_write_chck_row_precond
(
    uint32_t   raw_row_address,
    uint32_t   *row_data,
    QFPROM_REGION_NAME* region_type
);


/*===========================================================================

**  Function : qfprom_find_index

** ==========================================================================
*/
/*!
*
* @brief
*   This function finds the index of the fuse in the chain.
*
* @par Dependencies
*   None.
*
* @param:
*   QFPROM_REGION_NAME  This tells the region ID for which we want to find index.
*
* @retval
*   uint32_t  Index in qfprom table that matches qfpromId;
*           return QFPROM_INVALID_ENTRY in no match found.
*
* @par Side Effects
*   None.
*
*
*/
QFPROM_ERR_CODE qfprom_find_index(QFPROM_REGION_NAME qfpromRegion);


#endif /* QFPROM_TARGET_H */

