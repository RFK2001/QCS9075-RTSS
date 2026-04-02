#ifndef QFPROM_TEST_H
#define QFPROM_TEST_H


/*=============================================================================

                                qfprom_test.h

GENERAL DESCRIPTION
  This file contains the function header for invoking Qfprom Test Framework.

Copyright 2023 by Qualcomm Technologies, Inc.  All Rights Reserved.
=============================================================================*/


/*==============================================================================

                            EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.


when       who        what, where, why
--------   ---        ----------------------------------------------------------
03/20/14   ck         Initial version for Bear family
==============================================================================*/


/*==============================================================================

                            INCLUDE FILES FOR MODULE

==============================================================================*/
#include <stdint.h>
#include <QFPROMDefs.h>
#include "qfprom_target.h"

#define QFPROM_BLOW_ARRAY_MAX_LEN  11U

struct boot_qfprom_test_data_type
{
  uint32_t qfprom_service_api_status;
  QFPROM_ADDR_SPACE addr_type ;
  uint32_t qfprom_fuse_addr;
  uint32_t qfprom_fuse_data[2];
  write_row_type qfprom_test_fuse_array[QFPROM_BLOW_ARRAY_MAX_LEN];
};


/*==============================================================================

                          PUBLIC FUNCTION DECLARATIONS

==============================================================================*/

/* =============================================================================
**  Function : boot_qfprom_test
** =============================================================================
*/
/*!
*   @brief
*   This function invokes Qfprom Test Framework.
*
*
*   @return
*   None
*
*   @par Dependencies
*   None
*
*   @par Side Effects
*   None
*
*   @sa
*   None
*/
void boot_qfprom_test(void);

#endif /* QFPROM_TEST_H */
