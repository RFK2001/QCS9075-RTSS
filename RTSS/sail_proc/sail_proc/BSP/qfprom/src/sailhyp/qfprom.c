/*=============================================================================
            Copyright (c) 2023 Qualcomm Technologies, Incorporated.
                              All rights reserved.
              Qualcomm Technologies, Confidential and Proprietary.
=============================================================================*/

/*===========================================================================

                       QFPROM  Source  Code

DESCRIPTION
 Contains common defintion and APIs to be used to read and write qfprom
 values.

INITIALIZATION AND SEQUENCING REQUIREMENTS
  None
============================================================================*/

/*===========================================================================

                           EDIT HISTORY FOR FILE

This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.

$Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/qfprom/src/sailhyp/qfprom.c#1 $

when         who          what, where, why
--------     --------     ----------------------------------------------------
07/20/16     lm           Added new api qfprom_row_has_fec_bits()
06/21/16     lm           Added the fix to read CORR reg
10/15/15     kpa          Added mutex api calls
05/31/13     jz           Use target include
06/11/12     dh           Initial revision for 8974

 
============================================================================*/

/*=============================================================================

                            INCLUDE FILES FOR MODULE

=============================================================================*/

#include "qfprom.h"
#include "qfprom_target.h"
#include "HALqfprom.h"
#include "fuse_hw_mutex.h"
#include <string.h>

/*=============================================================================

            LOCAL DEFINITIONS AND DECLARATIONS FOR MODULE

This section contains local definitions for constants, macros, types,
variables and other items needed by this module.

=============================================================================*/
/*------------------------------------------------------------------------
  Global variable for multiple write API
------------------------------------------------------------------------*/
static uint32_t row_data_mult_write[2] = {0};

/*=============================================================================
   
                              FUNCTION DEFINITIONS

=============================================================================*/

/*===========================================================================

FUNCTION  qfprom_read_row

DESCRIPTION
This function shall read the row data of the specified QFPROM Row address.

DEPENDENCIES
  None.
 
PARAMETERS
    uint32_t   *row_address  - Pointer to the row address to be read from 
                                      the qfprom region.
    QFPROM_ADDR_SPACE addr_type - Raw or Corrected address.
    uint32_t*  row_data       - Pointer to the data.
 
RETURN VALUE
  QFPROM_ERR_CODE  Any errors while reading the specified item.

SIDE EFFECTS
  None.

===========================================================================*/
QFPROM_ERR_CODE qfprom_read_row
(
    uint32_t   row_address,
    QFPROM_ADDR_SPACE addr_type,
    uint32_t*  row_data
)
{
    QFPROM_ERR_CODE qfprom_err_status = QFPROM_ERR_UNKNOWN;
    QFPROM_REGION_NAME region_type;
    bool is_readable = false;
    bool fec_status = false;
    uint32_t active_row_address;

    fuse_grab_mutex();

    do
    { 
        /* Make sure the pointer to store the data is not NULL */
        if (row_data == NULL)
        {
          qfprom_err_status = QFPROM_DATA_PTR_NULL_ERR;
          break;
        }

		if(addr_type == QFPROM_ADDR_SPACE_CORR)
		{
			row_address |= QFPROM_RAW_TO_CORRECTED_ADDRESS_OFFSET;
		}
        /* Make sure the row address is virtual in case of L4 AMSS context to operate 
        ** since the qfprom diag interface request could be a physical address.
        */

        qfprom_err_status = qfprom_chk_cnvrt_to_active_addr(
                                                row_address,
                                                &active_row_address);

        if (qfprom_err_status != QFPROM_NO_ERR )
        {
            break;
        }


        /* Make sure the row address is fallign in the supproted region row boundary 
        ** address and return if it is not falling in the row address boundary.
        */

        qfprom_err_status = qfprom_chkbound_cond_row_addr(
                                          active_row_address);


        if (qfprom_err_status != QFPROM_NO_ERR )
        {
            break;
        }
      
        /* Check if the row address is part of supported QFPROM Region  */
        qfprom_err_status = qfprom_get_region_name(active_row_address,
                                                   (QFPROM_ADDR_SPACE)addr_type,
                                                   &region_type);

        if (qfprom_err_status != QFPROM_NO_ERR )
        {
            break;
        }


        /*  Check if Read permissions are there or not.
        **  if read permissions are there then read the region
        ** else return error value.
        */
        is_readable = qfprom_is_region_readable(region_type);

        if (is_readable == false)
        {
            qfprom_err_status = QFPROM_REGION_NOT_READABLE_ERR;
            break;
        }

        qfprom_err_status = qfprom_is_fec_enabled(region_type,
                                                  &fec_status);
        if (qfprom_err_status != QFPROM_NO_ERR)
        {
            break;
        }
        
        if (addr_type == QFPROM_ADDR_SPACE_RAW)
        {
            /* Read the Row */
            qfprom_err_status = HAL_qfprom_ReadRawAddressRow(active_row_address,
                                                             row_data );        
        }
        else if (addr_type == QFPROM_ADDR_SPACE_CORR)
        {
            /* Read the Row */
            qfprom_err_status = 
                        HAL_qfprom_ReadCorrectedAddrRow(active_row_address, 
                                                           row_data );
        }
        else
        {
            /* Unsupported addr_type. */
            qfprom_err_status = QFPROM_REGION_NOT_SUPPORTED_ERR ;
        }
        
        if (qfprom_err_status != QFPROM_NO_ERR )
        {
            break;
        }     

        /* Read the FEC_ESR register to ensure there was no FEC error 
           if this region has fec enabled */
        if(fec_status != false && HAL_qfprom_IsFecErrorSeen())
        {
          qfprom_err_status = QFPROM_FEC_ERR;
          break;
        }

    }while(0);
        
    fuse_release_mutex();  
      
    return qfprom_err_status;
} /* qfprom_read_row */


/*===========================================================================

FUNCTION  qfprom_write_single_row

DESCRIPTION
This function shall write the row data to the specified QFPROM Raw Row address.

DEPENDENCIES
  None.

PARAMETERS
    uint32_t   raw_row_address  -  address of Row to be
                                               written in  the qfprom raw region.
    uint32_t*  row_data       - Pointer to the data to write into the qfprom region.


RETURN VALUE
  QFPROM_ERR_CODE  Any errors while writing the specified item.

SIDE EFFECTS
  None.

===========================================================================*/
static QFPROM_ERR_CODE qfprom_write_single_row
(
    uint32_t   raw_row_address,
    uint32_t   *row_data
)
{
    QFPROM_ERR_CODE qfprom_err_status = QFPROM_ERR_UNKNOWN;
    QFPROM_REGION_NAME region_type;
    uint32_t corr_data_to_write[2]={0};
    uint32_t raw_data_to_write[2]={0};
    uint32_t active_row_address = 0;
    uint32_t read_row_data[2]={0};

    fuse_grab_mutex();

    do
    {
        /* Make sure the pointer to store the data is not NULL */
        if (row_data == NULL)
        {
          qfprom_err_status = QFPROM_DATA_PTR_NULL_ERR;
          break;
        }

        /* Make sure the row address is virtual in case of L4 AMSS context to operate
        ** since the qfprom diag interface request could be a physical address.
        */
        qfprom_err_status = qfprom_chk_cnvrt_to_active_addr(
                                                raw_row_address,
                                                &active_row_address);


        if (qfprom_err_status != QFPROM_NO_ERR )
        {
            break;
        }

        /* Make sure the row address is falling in the supported region row boundary
        ** address and return if it is not falling in the row address boundary.
        */

        qfprom_err_status = qfprom_chkbound_cond_row_addr(
                                          active_row_address);


        if (qfprom_err_status != QFPROM_NO_ERR )
        {
            break;
        }

        /* First copy the raw row data to the data buffer  */
        (void)memcpy(raw_data_to_write,row_data,sizeof(raw_data_to_write));
        (void)memcpy(corr_data_to_write,row_data,sizeof(corr_data_to_write));


        /* Check if the row address is part of supported QFPROM Region  */
        qfprom_err_status = qfprom_write_chck_row_precond(
                                                        active_row_address,
                                                        row_data,
                                                        &region_type);

        if (qfprom_err_status != QFPROM_NO_ERR )
        {
            break;
        }

         /* Perform the write operation */
         qfprom_err_status = qfprom_write(active_row_address,raw_data_to_write);

        if(qfprom_err_status != QFPROM_NO_ERR)
        {
            break;
        }

        /* Read the QFPROM to ensure that the data was written */
        qfprom_err_status = qfprom_read_row(raw_row_address,
                                            QFPROM_ADDR_SPACE_RAW,
                                            read_row_data);

        if(qfprom_err_status != QFPROM_NO_ERR)
        {
          /* Skip read/write verify test in case the read returns an error.
             Read errors can occur in case read permissions are disabled for
             the region or if there is an FEC error. We can safely skip the
             check in these two scenarios
          */
            qfprom_err_status = QFPROM_NO_ERR;
            break;
        }

        /*If read is allowed for the region, then perform the verification. Some regions
          are treated with special read permission requirements over-riding the read
          permission register in QFPROM block. The Custromer Keys and Customer Private
          Keys regions have this attribute. To read these fuses correctly, we need blow
          certain debug fuses. */

        if(qfprom_region_data[qfprom_find_index(region_type)].read_allowed == true)
        {
          /* Verify if the data was correctly written */
          if (
                ((raw_data_to_write[0]) != (raw_data_to_write[0]
                                           & read_row_data[0])) ||
                ((raw_data_to_write[1]) != (raw_data_to_write[1]
                                            & read_row_data[1]))
            )
            {
              qfprom_err_status = QFPROM_WRITE_ERR;
            }
        }

    }while(0);

    fuse_release_mutex();

    return qfprom_err_status;
} /* qfprom_write_single_row */


/*===========================================================================

FUNCTION  qfprom_write_row

DESCRIPTION
This function shall write the row data to the specified QFPROM Raw Row address.

DEPENDENCIES
  None.

PARAMETERS
    uint32_t   raw_row_address  - Address of Row to be written in  the qfprom raw region.
    uint32_t*  row_data         - Pointer to the data to write into the qfprom region.
    uint32_t   bus_clk_khz      - Frequency in khz of bus connected to the QFPROM .

RETURN VALUE
  QFPROM_ERR_CODE  Any errors while writing the specified item.

SIDE EFFECTS
  None.

===========================================================================*/
QFPROM_ERR_CODE qfprom_write_row
(
    uint32_t   raw_row_address,
    uint32_t   *row_data,
    uint32_t   bus_clk_khz
)
{
  QFPROM_ERR_CODE qfprom_err_status = QFPROM_ERR_UNKNOWN;

  fuse_grab_mutex();

  do
  {
    /* Enable PMIC and clocks to fuse block before writing to the fuse registers */
    qfprom_err_status = qfprom_write_fuse_init();

    if(qfprom_err_status != QFPROM_NO_ERR)
    {
      break;
    }
    qfprom_err_status = qfprom_write_single_row(raw_row_address, row_data);
  }while(0);

  fuse_release_mutex();

  /* Disable PMIC and clocks to fuse block after writing to the fuse registers */
  //qfprom_write_fuse_cleanup();

  return qfprom_err_status;

} /* qfprom_write_row */


/*===========================================================================

FUNCTION  qfprom_write_multiple_rows

DESCRIPTION
This function shall write multiple rows of data to the specified QFPROM Raw Row
addresses.

DEPENDENCIES
  None.

PARAMETERS
    uint32_t*  row_data_address  - Pointer to the first entry in the array to be
                                 written in  the qfprom raw region.
    uint32_t   bus_clk_khz       - Frequency in khz of bus connected to the QFPROM .

RETURN VALUE
  QFPROM_ERR_CODE  Any errors while writing the specified item.

SIDE EFFECTS
  None.

===========================================================================*/
QFPROM_ERR_CODE  qfprom_write_multiple_rows
(
    void   *row_data_address,
    uint32_t   bus_clk_khz
)
{
  QFPROM_ERR_CODE qfprom_err_status = QFPROM_ERR_UNKNOWN;
  uint32_t index = 0;
  write_row_type *write_rows = (write_row_type *)row_data_address;

  fuse_grab_mutex();

  do
  {

    /* Enable PMIC and clocks to fuse block before writing to the fuse registers */
    qfprom_err_status = qfprom_write_fuse_init();
    if(qfprom_err_status != QFPROM_NO_ERR)
    {
      break;
    }
    /* Send write commands for every entry in the array */
    while(write_rows[index].raw_row_address != 0x0U)
    {
      row_data_mult_write[0] = write_rows[index].row_data_lsb;
      row_data_mult_write[1] = write_rows[index].row_data_msb;

      qfprom_err_status = qfprom_write_single_row(
                    write_rows[index].raw_row_address,&row_data_mult_write[0]);

      /* If there is an error, do not proceed further */
      if(qfprom_err_status != QFPROM_NO_ERR)
      {
        break;
      }
      index++;
    }

  }while(0);

  fuse_release_mutex();
  
  /* Disable PMIC and clocks to fuse block after writing to the fuse registers */
  //qfprom_write_fuse_cleanup();

  return qfprom_err_status;

} /* qfprom_write_multiple_rows */

/*===========================================================================

FUNCTION  qfprom_row_has_fec_bits

DESCRIPTION
This function shall check whether the FEC bits are present or not in the specified QFPROM Row address.

DEPENDENCIES
  None.
 
PARAMETERS
    uint32_t   *row_address  - Pointer to the row address to check the 
                             FEC bits in the qfprom region.
    QFPROM_ADDR_SPACE addr_type - Raw or Corrected address.
    uint8_t*  fec_bits       - Pointer to the data.
 
RETURN VALUE
  QFPROM_ERR_CODE  Any errors while checking the specified item.

SIDE EFFECTS
  None.

===========================================================================*/
QFPROM_ERR_CODE qfprom_row_has_fec_bits
(
    uint32_t   row_address,
    QFPROM_ADDR_SPACE addr_type,
    uint8_t*  fec_bits
)
{
	QFPROM_ERR_CODE qfprom_err_status = QFPROM_ERR_UNKNOWN;
	QFPROM_REGION_NAME region_type;
	uint32_t active_row_address = 0;
	
	fuse_grab_mutex();
	
	do
	{
		
		if(addr_type == QFPROM_ADDR_SPACE_CORR)
		{
			row_address |= QFPROM_RAW_TO_CORRECTED_ADDRESS_OFFSET;
		}
		/* Make sure the row address is virtual in case of L4 AMSS context to operate 
		** since the qfprom diag interface request could be a physical address.
		*/

		qfprom_err_status = qfprom_chk_cnvrt_to_active_addr(
													row_address,
													&active_row_address);

		if (qfprom_err_status != QFPROM_NO_ERR )
		{
			break;
		}


		/* Make sure the row address is fallign in the supproted region row boundary 
		** address and return if it is not falling in the row address boundary.
		*/

		qfprom_err_status = qfprom_chkbound_cond_row_addr(
															active_row_address);

		if (qfprom_err_status != QFPROM_NO_ERR )
		{
			break;
		}
		  
		/* Check if the row address is part of supported QFPROM Region  */
		qfprom_err_status = qfprom_get_region_name(active_row_address,
										 (QFPROM_ADDR_SPACE)addr_type,
															&region_type);
		if (qfprom_err_status != QFPROM_NO_ERR )
		{
			break;
		}
			
		if(qfprom_region_data[qfprom_find_index(region_type)].read_allowed == true)
		{
			if(qfprom_region_data[qfprom_find_index(region_type)].fec_type != QFPROM_FEC_NONE)
			{
				*fec_bits =  1;
					
			}
			else
			{
				*fec_bits = 0;
			}
		}
	}while(0);
	
	fuse_release_mutex();
	
	return qfprom_err_status;
}

