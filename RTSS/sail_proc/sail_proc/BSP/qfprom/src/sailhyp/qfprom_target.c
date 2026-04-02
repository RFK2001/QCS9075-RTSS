/*===========================================================================

                       QFPROM  Driver Source  Code

DESCRIPTION
 Contains target specific defintions and APIs to be used to read and write
 qfprom values.

INITIALIZATION AND SEQUENCING REQUIREMENTS
  None

Copyright  2010-2012,2013,2015,2019-2021 by Qualcomm Technologies Incorporated.  All Rights Reserved.
============================================================================*/

/*===========================================================================

                           EDIT HISTORY FOR FILE

This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.

$Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/qfprom/src/sailhyp/qfprom_target.c#1 $

when       who     what, where, why
--------   ---     ----------------------------------------------------------
02/03/21   aus     Support for mx work-around
07/17/19   ds      Remove the raw/corr lowest and highest address usage
07/02/15   ck      Updated qfprom_is_region_writable/readable to support > 32 regions
07/24/13   lm      Fixed the fec enable region issue for MSM8x10
07/04/13   lm      Added feature for MSM8x10 chipset
06/07/13   jz      Use QFPROM_ACCEL_VALUE per QFPROM technology
05/31/13   jz      Remove hard-coded region ids, fixed write perm mask, cleanup
04/24/13   dh      Correct the fec enable region base address
10/05/12   dh      Change blow timer cycle calculation to round up 
06/11/12   dh      Initial revision for 8974

============================================================================*/

/*=============================================================================

                            INCLUDE FILES FOR MODULE

=============================================================================*/
#include "HALqfprom.h"
#include "qfprom.h"
#include "qfprom_target.h"
#include "security_control_hwioreg.h"

/*=============================================================================

            LOCAL DEFINITIONS AND DECLARATIONS FOR MODULE

This section contains local definitions for constants, macros, types,
variables and other items needed by this module.

=============================================================================*/




#define QFPROM_IS_FEC_ENABLED(x)  ( x > 0U )

#define BIT32_MASK          0xFFFFFFFFUL

/*---------------------------------------------------------------------------
  Used to keep track if clock and PMIC voltage regulators are on.
---------------------------------------------------------------------------*/
static bool qfprom_write_operation_allowed = false;




/*=============================================================================
                                 LOCAL FUNCTION DEFINITIONS
=============================================================================*/


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
QFPROM_ERR_CODE qfprom_find_index(QFPROM_REGION_NAME qfpromRegion)
{
    QFPROM_ERR_CODE return_value = (QFPROM_ERR_CODE)QFPROM_INVALID_ENTRY;
    uint32_t  index = 0;

    /*
    **  Find matching qfprom ID to obtain index in table
    */
    for (index = 0; qfprom_region_data[index].region != QFPROM_LAST_REGION_DUMMY;
           index++)
    {
        if (qfprom_region_data[index].region == qfpromRegion)
        {
            return_value = (QFPROM_ERR_CODE)index;
            break;
        }
    }

    return return_value;
}



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
QFPROM_ERR_CODE
qfprom_write_chck_row_precond
(
    uint32_t   raw_row_address,
    uint32_t   *row_data,
    QFPROM_REGION_NAME* region_type
)
{
    QFPROM_ERR_CODE qfprom_err_status = QFPROM_ERR_UNKNOWN;
    bool is_writeable,is_readable,value = false;

    do
    {
        /* Check if the row address is part of supported QFPROM Region  */
        qfprom_err_status = qfprom_get_region_name(raw_row_address,
                                        QFPROM_ADDR_SPACE_RAW,
                                        region_type);

        if (qfprom_err_status != QFPROM_NO_ERR )
        {
            break;
        }

        /*  Check if write permissions are there or not.
        **  if read permissions are there then read the region
        ** else return error value in success
        */
        is_writeable = qfprom_is_region_writeable(*region_type);

        if (is_writeable == false)
        {
            qfprom_err_status = QFPROM_REGION_NOT_WRITEABLE_ERR;
            break;
        }

        /*  Check if FEC is enabled for the Row.
        **  If FEC is enabled then write is not supported.
        */
        qfprom_err_status = qfprom_is_fec_enabled(*region_type,
                                                   &value);

        if (qfprom_err_status != QFPROM_NO_ERR)
        {
            break;
        }

        if (value)
        {
            qfprom_err_status = QFPROM_REGION_FEC_ENABLED_NOT_WRITEABLE_ERR;
            break;
        }


        /*  Check if Read permissions are there or not.
        **  if read permissions are there then read the region
        ** else return error value in success
        */
        is_readable = qfprom_is_region_readable(*region_type);

        if (is_readable == false)
        {
            qfprom_err_status = QFPROM_REGION_NOT_READABLE_ERR;
            break;
        }
    }while(0);

    return qfprom_err_status;
}


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
QFPROM_ERR_CODE qfprom_write(
    uint32_t raw_row_address,
    uint32_t *raw_data_to_write)
{
    QFPROM_ERR_CODE qfprom_err_status = QFPROM_NO_ERR;
    uint32_t value;

    do
    {

        /* Check if QFPROM hw is busy or not */
        /* value   0: ok to Blow
                   1:  busy blowing fuse
                   2: error occured while blowing
          */
        do
        {
            HAL_qfprom_ReadBlowStatus(&value);
        } while (value == 0x1U);

        if (value != 0x0U)
        {
            /*Fuse blow error occured */
            qfprom_err_status = QFPROM_WRITE_ERR;
            break;
        }

        /* Write QFPROM LSB Row data */
        qfprom_err_status = HAL_qfprom_WriteRawAddress(raw_row_address,
                                                       raw_data_to_write[0]);

        if (qfprom_err_status != QFPROM_NO_ERR)
        {
            break;
        }

        /* Check if QFPROM write can happen or not */
        do
        {
            HAL_qfprom_ReadBlowStatus(&value);
        } while (value == 0x1U);

        if (value != 0x0U)
        {
            /*Fuse blow error occured */
            qfprom_err_status = QFPROM_WRITE_ERR;
            break;
        }
        /*If reach  here, value is 0 ie blow was ok */

        /* Write Qfprom MSB Row data */
        qfprom_err_status = HAL_qfprom_WriteRawAddress((raw_row_address + 4U),
                                                       raw_data_to_write[1]);
        /* Check if QFPROM write can happen or not */
        do
        {
            HAL_qfprom_ReadBlowStatus(&value);
        } while (value == 0x1U);

        if (value != 0x0U)
        {
            /*Fuse blow error occured */
            qfprom_err_status = QFPROM_WRITE_ERR;
            break;
        }

    } while (0);

    return qfprom_err_status;
}

/*=============================================================================
                                 GLOBAL FUNCTION DEFINITIONS
=============================================================================*/


/*===========================================================================

FUNCTION  qfprom_write_set_clock_dependent_settings

DESCRIPTION
    This function shall set the appropriate clock dependent settings for the qfprom block.

PARAMETERS
  None.

DEPENDENCIES
  None.

RETURN VALUE
  uint32_t  Any Errors while setting up the system before blowing the fuses.

SIDE EFFECTS
  None.

===========================================================================*/
static QFPROM_ERR_CODE qfprom_write_set_clock_dependent_settings( void )
{
    QFPROM_ERR_CODE ret_val = QFPROM_NO_ERR;
    
    if (QFPROM_NO_ERR != HAL_qfprom_EnableClock())
    {
      ret_val = QFPROM_CLOCK_SETTINGS_INVALID_ERR;
      return ret_val;
    }

    /*  QFPROM block requires a held charge for (QFPROM_FUSE_BLOW_TIME_IN_US) micro-
    **  seconds time to blow a fuse.
    **  blow_value = Number of clocks that the blow_fuses signal (round up)  ,
    */
    
    /* Round up the blow timer value, if calculated value is in the range of (28 -28.99)cycle,
    round it up to 29 */
    /* blow_value = QFPROM_BLOW_TIMER_CLK_FREQ_MHZ*QFPROM_FUSE_BLOW_TIME_IN_US + 0.5 */
    HAL_qfprom_SetBlowTimer(QFPROM_BLOW_TIMER_SETTING_VALUE);

    /* 
      Configue QFPROM_ACCEL[QFPROM_ACCEL] to 0x90,
      Configure QFPROM_ACCEL[QFPROM_TRIPPT_SEL] to 0x6 for blowing 4k ohms high resistence    
      Configure QFPROM_ACCEL[QFPROM_GATELAST] to 0x1
    */
    HAL_qfprom_SetAccelator(QFPROM_ACCEL_VALUE);
 

    return ret_val;
}


/*===========================================================================

FUNCTION  qfprom_write_reset_clock_dependent_settings

DESCRIPTION
    This function shall reset the appropriate clock dependent settings for the qfprom block.

PARAMETERS
  None.

DEPENDENCIES
  None.

RETURN VALUE
  uint32_t  Any Errors while setting up the system before blowing the fuses.

SIDE EFFECTS
  None.

===========================================================================*/
static QFPROM_ERR_CODE qfprom_write_reset_clock_dependent_settings( void )
{
    if (QFPROM_NO_ERR != HAL_qfprom_DisableClock())
	{
		return QFPROM_CLOCK_SETTINGS_INVALID_ERR;
	}
    
    /* Set blow timer to 0 to block accidental blows to QFPROM. */
    HAL_qfprom_SetBlowTimer(0);
    
    /* Restore Accelator setting for normal fuse read */
    HAL_qfprom_SetAccelator(QFPROM_ACCEL_RESET_VALUE);
    
    return QFPROM_NO_ERR;
}

// Enable it after PMIC APIs available
#ifdef QFPROM_PMIC_SUPPORT_ENABLED
/*===========================================================================

FUNCTION  qfprom_write_set_voltage_dependent_settings

DESCRIPTION
    This function shall set the appropriate voltage dependent settings for the qfprom block.

PARAMETERS
  None.

DEPENDENCIES
  None.

RETURN VALUE
  uint32_t  Any Errors while setting up the system before blowing the fuses.

SIDE EFFECTS
  Turns on qfprom clock and enables VREG_GP5.

===========================================================================*/

static QFPROM_ERR_CODE qfprom_write_set_voltage_dependent_settings(void)
{
    QFPROM_ERR_CODE ret_val = QFPROM_NO_ERR;

    pm_err_flag_type errFlag = PM_ERR_FLAG__SUCCESS;

    /* Voltage is applied enable the logic to write.
      Set QFPROM_BLOW_VDD to 1.9v by turning on switch
      LOW_VOLTAGE_SWITCH_LVS_1_CONTROL.
      When pmic lib is available [when porting it to other images/modules],
      its generic api's should be used to substitute below api.
      */
    errFlag = pm_enable_qfuse_power_rail();
    if (errFlag != PM_ERR_FLAG__SUCCESS)
    {
        return QFPROM_FAILED_TO_CHANGE_VOLTAGE_ERR;
    }

#ifdef ENABLE_MX_RAIL_REQ
    ret_val = qfprom_enable_mx_rail();
#endif

    return ret_val;
}
/*===========================================================================

FUNCTION  qfprom_write_reset_voltage_dependent_settings

DESCRIPTION
    This function shall reset the appropriate voltage dependent settings for the qfprom block.

PARAMETERS
  None.

DEPENDENCIES
  None.

RETURN VALUE
  uint32_t  Any Errors while setting up the system before blowing the fuses.

SIDE EFFECTS
  Disables the vreg being used.

===========================================================================*/
static QFPROM_ERR_CODE qfprom_write_reset_voltage_dependent_settings(void)
{
    QFPROM_ERR_CODE ret_val = QFPROM_NO_ERR;
    pm_err_flag_type errFlag = PM_ERR_FLAG__SUCCESS;

    /*Disable power to the qfprom block  by turning off switch
           LOW_VOLTAGE_SWITCH_LVS_1_CONTROL*/
    errFlag = pm_disable_qfuse_power_rail();

    if (errFlag != PM_ERR_FLAG__SUCCESS)
    {
        return QFPROM_FAILED_TO_CHANGE_VOLTAGE_ERR;
    }

#ifdef ENABLE_MX_RAIL_REQ
    ret_val = qfprom_disable_mx_rail();
#endif

    /* Apply enough wait time here to stabilise the voltage */
    clk_busy_wait(1000);

    return ret_val;
}
#endif

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
  uint32_t  Any Errors while setting up the system before blowing the fuses.

SIDE EFFECTS
  Turns on qfprom clock and enables VREG_GP5.

===========================================================================*/
QFPROM_ERR_CODE qfprom_write_fuse_init( void )
{
    QFPROM_ERR_CODE ret_val = QFPROM_NO_ERR;

    do
    {
       /*Ensure pmic and clock settings are reset to default before
         enabling them */
        ret_val = qfprom_write_fuse_cleanup();

        if (ret_val != QFPROM_NO_ERR)
        {
            break;
        }

        ret_val = qfprom_write_set_clock_dependent_settings();

        if (ret_val != QFPROM_NO_ERR)
        {
            break;
        }
#ifdef QFPROM_PMIC_SUPPORT_ENABLED
        ret_val = qfprom_write_set_voltage_dependent_settings();
#endif

    }while(0);

    if (ret_val != QFPROM_NO_ERR)
    {
       (void)qfprom_write_fuse_cleanup();
    }
    else
    {
        /* Set the write operation active flag */
        qfprom_write_operation_allowed = true;
    }

    return ret_val;
}

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
  uint32_t   Any Errors while doing the cleanup.

SIDE EFFECTS
  None.

===========================================================================*/
QFPROM_ERR_CODE qfprom_write_fuse_cleanup( void )
{
    QFPROM_ERR_CODE ret_val = QFPROM_NO_ERR;

    do
    {
#ifdef QFPROM_PMIC_SUPPORT_ENABLED
        /* At any cost the LDO should be switched OFF for MDM 9k as power down
        ** has issues and could cause MSM to be in bad state if it is ON.
        ** For MSM 8660 too its necessary to switch off voltage to the qfprom
        ** Power rail, to prevent any later accidental writes to qfprom region.
        */
        ret_val = qfprom_write_reset_voltage_dependent_settings();
#endif

        ret_val = qfprom_write_reset_clock_dependent_settings();


    }while(0);

    /* Reset the write operation active flag */
    qfprom_write_operation_allowed = false;

    return ret_val;
}

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
bool qfprom_is_write_opr_allowed ( void )
{
  return qfprom_write_operation_allowed;
}


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

QFPROM_ERR_CODE
qfprom_chk_cnvrt_to_active_addr
(
    uint32_t row_address,
    uint32_t*active_row_address
)
{
  QFPROM_ERR_CODE qfprom_err_status = QFPROM_ADDRESS_INVALID_ERR;

  if (SAILSS_SECURITY_CONTROL_SAIL_SECURITY_CONTROL_BASE == SAILSS_SECURITY_CONTROL_SAIL_SECURITY_CONTROL_BASE_PHYS)
  {
    *active_row_address =  row_address;
    qfprom_err_status = QFPROM_NO_ERR;
  }
  else
  {
    *active_row_address = SAILSS_SECURITY_CONTROL_SAIL_SECURITY_CONTROL_BASE + row_address - SAILSS_SECURITY_CONTROL_SAIL_SECURITY_CONTROL_BASE_PHYS;
    qfprom_err_status = QFPROM_NO_ERR;
  }    
  return qfprom_err_status;
}


/*===========================================================================

FUNCTION  qfprom_chkbound_cond_row_addr

DESCRIPTION
    This function shall check the boundary condition for the row address to be operated.

PARAMETERS
    uint32_t   row_address  - Row address to be checked

DEPENDENCIES
  None.

RETURN VALUE
  uint32_t  Any Errors while setting up the system before blowing the fuses.

SIDE EFFECTS
  Disables the vreg being used.

===========================================================================*/

QFPROM_ERR_CODE
qfprom_chkbound_cond_row_addr
(
    uint32_t row_address
)
{
    QFPROM_ERR_CODE return_value = QFPROM_ROW_BOUNDARY_CONDITION_VERIFY_ERR;
    uint32_t  index,row_index = 0;
    uint32_t local_raw_row_address = 0x0;
    uint32_t local_corr_row_address = 0x0;

    /*
    **  Ensure the row address is falling in the row boundary.
    */
    for (index = 0; qfprom_region_data[index].region != QFPROM_LAST_REGION_DUMMY;
           index++)
    {
        row_index = qfprom_region_data[index].size;

        do
        {
            local_raw_row_address =  ( qfprom_region_data[index].raw_base_addr  + (row_index -1U)*8U );
            local_corr_row_address =  ( qfprom_region_data[index].corr_base_addr + (row_index -1U)*8U );


            if ( (row_address == local_raw_row_address) ||
                  (row_address == local_corr_row_address) )
            {
                return_value = QFPROM_NO_ERR;
                break;
            }
            row_index--;
        }while(row_index > 0U);
    }

    return return_value;
}


/*===========================================================================

**  Function :qfprom_is_region_readable

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
bool  qfprom_is_region_readable
(
    QFPROM_REGION_NAME  region
)
{
    bool status = false;
    uint32_t  index;
    uint32_t read_perm = 0;
    QFPROM_ERR_CODE return_value = QFPROM_ERR_UNKNOWN;


    for (index = 0; qfprom_region_data[index].region != QFPROM_LAST_REGION_DUMMY;
           index++)
    {
        if (qfprom_region_data[index].region == region)
        {
            if (qfprom_region_data[index].perm_reg_type == QFPROM_ROW_LSB)
            {
                /* Read the read permission register values */
                return_value = HAL_qfprom_ReadCorrectedAddress(
                               QFPROM_READ_PERM_CORRECTED_ADDR,
                               &read_perm);
            }
            else
            {
                #ifdef QFPROM_READ_PERM_CORRECTED_MSB_ADDR
                return_value = HAL_qfprom_ReadCorrectedAddress(
                               QFPROM_READ_PERM_CORRECTED_MSB_ADDR,
                               &read_perm);
                #endif
            }

            if (return_value != QFPROM_NO_ERR )
            {
                break;
            }

            /* Mask the values with the reg type so that LSB ,MSB masks are appropriately
            ** applied.
            **
            **  0 - Allow    Read
            **  1 - Disable  Read
            */
            if ((read_perm & qfprom_region_data[index].read_perm_mask) == 0x0U)
            {
                status = true;
            }
            
            break;
        }
    }

   return status;
}



/*===========================================================================

**  Function :

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
bool     qfprom_is_region_writeable
(
    QFPROM_REGION_NAME  region
)
{
    bool status = false;
    uint32_t  index;
    uint32_t write_perm = 0;
    QFPROM_ERR_CODE return_value = QFPROM_ERR_UNKNOWN;


    for (index = 0; qfprom_region_data[index].region != QFPROM_LAST_REGION_DUMMY;
           index++)
    {
        if (qfprom_region_data[index].region == region)
        {

            if (qfprom_region_data[index].perm_reg_type == QFPROM_ROW_LSB)
            {
                /* Read the write permission register values */
                return_value = HAL_qfprom_ReadCorrectedAddress(
                               QFPROM_WRITE_PERM_CORRECTED_ADDR,
                               &write_perm);
            }
            else
            {
                #ifdef QFPROM_WRITE_PERM_CORRECTED_MSB_ADDR
                return_value = HAL_qfprom_ReadCorrectedAddress(
                               QFPROM_WRITE_PERM_CORRECTED_MSB_ADDR,
                               &write_perm);
                #endif
            }


            if (return_value != QFPROM_NO_ERR )
            {
                break;
            }

            /* Mask the values with the reg type so that LSB ,MSB masks are appropriately
            ** applied.
            **
            **  0 - Allow    write
            **  1 - Disable  write
            */
            if ((write_perm & qfprom_region_data[index].write_perm_mask) == 0x0U)
            {
                status = true;
            }
            
            break;
        }
    }

   return status;
}

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
*   uint32_t address - Address of the Row.
*   HAL_QFPROM_ADDR_SPACE_TYPE_ENUM addr_type - Raw or Corrected address,
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
 )
{
    QFPROM_ERR_CODE return_value = QFPROM_REGION_NOT_SUPPORTED_ERR;
    uint32_t  index = 0;
    uint32_t region_start_row_addr = 0;
    uint32_t region_end_row_addr = 0;

    /*
    **  Find matching qfprom ID to obtain index in table
    */
    for (index = 0; qfprom_region_data[index].region != QFPROM_LAST_REGION_DUMMY; index++)
    {

        if (addr_type == QFPROM_ADDR_SPACE_RAW)
        {
            region_start_row_addr = qfprom_region_data[index].raw_base_addr;
        }
        else if (addr_type == QFPROM_ADDR_SPACE_CORR)
        {
            region_start_row_addr = qfprom_region_data[index].corr_base_addr;
        }
        else // Unsupported addr_type
        {
            return_value = QFPROM_REGION_NOT_SUPPORTED_ERR ;
            break ;
        }

        region_end_row_addr = ((region_start_row_addr) +
                                            ((qfprom_region_data[index].size) *8U) );

        if (( address >=  region_start_row_addr) &&
            (address < region_end_row_addr ))
        {
            *region_type = qfprom_region_data[index].region;
            return_value = QFPROM_NO_ERR;
            break;
        }
    }

    return return_value;
}

/*===========================================================================

**  Function : qfprom_is_fec_enabled

** ==========================================================================
*/
/*!
*
* @brief
*   This function shall check the FEC status of the given region.
*
* @par Dependencies
*   None.
*
* @param:
*   QFPROM_REGION_NAME region_type - name of the region.
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

QFPROM_ERR_CODE
qfprom_is_fec_enabled
(
    QFPROM_REGION_NAME  region_type,
    bool *fec_status
)
{
    QFPROM_ERR_CODE return_value = QFPROM_NO_ERR;
    uint32_t index = 0;
    uint32_t fec_en_lsb,fec_en_msb = 0;

    do
    {
        /*
        **  Find matching qfprom ID to obtain index in table
        */
        for (index = 0; qfprom_region_data[index].region != QFPROM_LAST_REGION_DUMMY; index++)
        {
            if (qfprom_region_data[index].region == region_type)
            {
                if (qfprom_region_data[index].fec_type == QFPROM_FEC_63_56)
                {
					/* Finding whether the qfprom region is sitting in LSB or MSB */
					if(qfprom_region_data[index].qfprom_region_index < 32U)
					{
						/*  Read the LSB address to get the FEC_EN region data */
						return_value = HAL_qfprom_ReadCorrectedAddress(
										HWIO_QFPROM_CORR_FEC_EN_LSB_ADDR,
										&fec_en_lsb);

						if (return_value != QFPROM_NO_ERR )
						{
							break;
						}             

						/* Extract the FEC bits and check if the FEC enabled or not */
						fec_en_lsb &= (uint32_t)((1UL << qfprom_region_data[index].qfprom_region_index)&(BIT32_MASK));

						*fec_status = QFPROM_IS_FEC_ENABLED(fec_en_lsb);
						return_value = QFPROM_NO_ERR;
					}
					else if(qfprom_region_data[index].qfprom_region_index < 64U)
					{
						/*  Read the MSB address to get the FEC_EN region data */
						return_value = HAL_qfprom_ReadCorrectedAddress(
										HWIO_QFPROM_CORR_FEC_EN_MSB_ADDR,
										&fec_en_msb);

						if (return_value != QFPROM_NO_ERR )
						{
							break;
						}             

						/* Extract the FEC bits and check if the FEC enabled or not */
						fec_en_msb &= (uint32_t)((1UL << (qfprom_region_data[index].qfprom_region_index - 32UL))&(BIT32_MASK));
						*fec_status = QFPROM_IS_FEC_ENABLED(fec_en_msb);
						return_value = QFPROM_NO_ERR;
					}
					else
					{
						return_value = QFPROM_INVALID_INDEX;
						break;	
					}
                }
                /*For regions that do no support FEC , no need for FEC action */
                else if (qfprom_region_data[index].fec_type == QFPROM_FEC_NONE)
                {
                    *fec_status = false;
                    return_value = QFPROM_NO_ERR;
                }
                /* Unsupported FEC type , report error */
                else 
                {
                    *fec_status = false;
                    return_value = QFPROM_ERR_UNKNOWN;
                }
                
              /*Once the matching region break out of the loop*/  
              break;
            }
        } /* end for */
    }while(0);
    
    return return_value;
}


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
 )
{
  QFPROM_ERR_CODE return_value = QFPROM_REGION_NOT_SUPPORTED_ERR;
  uint32_t  index = 0;
  uint32_t region_start_row_addr = 0;
  uint32_t region_end_row_addr = 0;    
  uint32_t active_address;
  
  do
  {
    if(region_index == NULL)
    {
      return_value = QFPROM_DATA_PTR_NULL_ERR;
      break;
    }
    
   /* The requested address could be physical. Convert the address in
    * to a virtual address */
    return_value = qfprom_chk_cnvrt_to_active_addr(
                                            address,
                                            &active_address);
    if (return_value != QFPROM_NO_ERR)
    {
        break;
    }
    
    /* 
    **  Find matching qfprom ID to obtain index in table
    */
    for (index = 0; qfprom_region_data[index].region != QFPROM_LAST_REGION_DUMMY;
         index++)
    {
      if (addr_type == QFPROM_ADDR_SPACE_RAW)
      {
        region_start_row_addr = qfprom_region_data[index].raw_base_addr;
      }
      else if (addr_type == QFPROM_ADDR_SPACE_CORR)
      {
        region_start_row_addr = qfprom_region_data[index].corr_base_addr;
      }
      else // Unsupported addr_type
      {
        return_value = QFPROM_REGION_NOT_SUPPORTED_ERR ;
        break ;
      }

      region_end_row_addr = ((region_start_row_addr) + 
                                       ((qfprom_region_data[index].size) *8U) );
        
      if (( active_address >=  region_start_row_addr) && 
          (active_address < region_end_row_addr ))
      {
         *region_index = qfprom_region_data[index].qfprom_region_index;
         return_value = QFPROM_NO_ERR;
         break;
      }
    }

  }while(0);

  return return_value;
} 
