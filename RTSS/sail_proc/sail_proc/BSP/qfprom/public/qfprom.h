#ifndef QFPROM_H
#define QFPROM_H

/**
 @file qfprom.h 
 @brief
 Contains common definitions and APIs to be used to read and write QFPROM rows.
*/ 

/*===========================================================================
NOTE: The @brief description and any detailed descriptions above do not appear 
      in the PDF. 

      The qfprom_mainpage.dox file contains all file/group descriptions that are 
      in the output PDF generated using Doxygen and LaTeX. To edit or update 
      any of the file/group text in the PDF, edit the qfprom_mainpage.dox file or 
      contact Tech Pubs.

      The above description for this file is part of the "qfprom" group 
      description in the qfprom_mainpage.dox file. 
===========================================================================*/

/*==============================================================================
                  Copyright 2012 - 2016, 2018 Qualcomm Technologies, Inc.
                            All Rights Reserved.
                    Qualcomm Confidential and Proprietary
================================================================================
                              EDIT HISTORY

================================================================================
when       who     what, where, why
--------   ---     -------------------------------------------------------------
07/20/16   lm      Expose qfprom_row_has_fec_bits
05/31/13   jz      Expose qfprom_write_multiple_rows
07/10/12   dh      Change major verion to 02 for badger family
03/08/11   ds      (Tech Pubs) Edited/added Doxygen comments and markup.
11/17/10   dxiang  Doxygen grouping changes for API auto-generation
10/26/10   dxiang  Doxygen markup standards changes 
05/10/10   ddk     Initial version.

==============================================================================*/

#include <stdint.h>
#include "QFPROMDefs.h"

/** @addtogroup qfprom_API
@{ */

/* ============================================================================
**  Function : qfprom_read_row
** ============================================================================
*/
/**
 Reads the row data of the specified QFPROM row address.

 @param[in] row_address     Row address in the QFPROM region from which the row
                            data is read.
 @param[in] addr_type       Raw or corrected address.
 @param[out] row_data       Pointer to the data to be read.

 @return
 Any errors while reading data from the specified QFPROM row address.

 @dependencies
 None.
 */
QFPROM_ERR_CODE qfprom_read_row
(
    uint32_t   row_address,
    QFPROM_ADDR_SPACE addr_type,
    uint32_t*  row_data
);

/* ============================================================================
**  Function : qfprom_write_row
** ============================================================================
*/
/**
 Writes the row data to the specified QFPROM raw row address.

 @param[in] raw_row_address     Row address in the QFPROM region to which the
                                row data is to be written.
 @param[in] row_data            Pointer to the data to write into the QFPROM
                                region.
 @param[in] bus_clk_khz         Frequency in kHz of the bus clock connected to
                                the QFPROM. \n
                                @note1hang
                                When the QFPROM driver runs in AMSS/L4 context,
                                this is ignored. 

 @return
 Any errors while writing data to the specified QFPROM raw row address.

 @dependencies
 None.
 */
QFPROM_ERR_CODE qfprom_write_row
(
    uint32_t   raw_row_address,
    uint32_t   *row_data,
    uint32_t   bus_clk_khz
);

#ifdef SAILEL2
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
QFPROM_ERR_CODE qfprom_write_multiple_rows
(
    void   *row_data_address,
    uint32_t   bus_clk_khz
);

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
);

/** @} */ /* end_addtogroup qfprom_API */
#endif

#endif /* QFPROM_H */

