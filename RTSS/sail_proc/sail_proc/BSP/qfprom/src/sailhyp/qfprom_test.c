/*=============================================================================
            Copyright (c) 2021 Qualcomm Technologies, Incorporated.
                              All rights reserved.
              Qualcomm Technologies, Confidential and Proprietary.
=============================================================================*/
/*=============================================================================

                                qfprom_test.c

GENERAL DESCRIPTION
  This file contains the function definition for invoking Qfprom Test Framework.
=============================================================================*/


/*==============================================================================

                            EDIT HISTORY FOR MODULE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.


when       who        what, where, why
--------   ---        ----------------------------------------------------------
07/02/15   aus        Make the variables global as they are used by JTAG scripts
03/20/14   ck         Initial version for Bear family
==============================================================================*/


/*==============================================================================

                            INCLUDE FILES FOR MODULE

==============================================================================*/
#include "qfprom_test.h"
#include "qfprom.h"
#include "qfprom_target.h"

/* STATIC FUNCTIONS*/
#ifdef QFPROM_BOOT_SINGLE_TEST
static void boot_qfprom_single_test(void);
/*==============================================================================

                              FUNCTION DEFINITIONS

==============================================================================*/

  /* These variables are modified by Trace32 */
  
volatile static bool test_single_fuse_blow   = false;
volatile static bool test_multiple_fuse_blow = false;
volatile static bool test_read_fuse          = false;
volatile static bool qfprom_test_run_always  = false;

volatile static struct boot_qfprom_test_data_type boot_qfprom_test_data; 

volatile static uint32_t qfprom_test_array_length = 
  (sizeof(boot_qfprom_test_data.qfprom_test_fuse_array)/sizeof(write_row_type));
            
            
/* =============================================================================
**  Function : boot_qfprom_single_test
** =============================================================================
*/
/*!
*   @brief
*   This function invokes Qfprom Test Api's one time.
*
*
*   @return
*   None
*
*   @par Dependencies
*   Needs to be involded before TZ_SBL_END_MILESTONE service request
*   (that locks out qfprom driver in TZ).
*
*   @par Side Effects
*   None
*
*   @sa
*   None
*/
static void boot_qfprom_single_test(void)
{
  boot_qfprom_test_data.qfprom_service_api_status = (uint32_t)QFPROM_NO_ERR;
  
  /* Blow single  Qfprom fuse */
  if(test_single_fuse_blow) 
  {
    boot_qfprom_test_data.qfprom_service_api_status =
      (uint32_t)qfprom_write_row(boot_qfprom_test_data.qfprom_fuse_addr, 
                       (uint32_t *)boot_qfprom_test_data.qfprom_fuse_data,
                       0);
  }
  
  /* Blow array of  Qfprom fuse */
  if((test_multiple_fuse_blow == true) && (qfprom_test_array_length == QFPROM_BLOW_ARRAY_MAX_LEN)) 
  {
    boot_qfprom_test_data.qfprom_service_api_status =
      (uint32_t)qfprom_write_multiple_rows((void *)&boot_qfprom_test_data.qfprom_test_fuse_array,
                                 0);
  }
  
  /* Read  Qfprom fuse */
  if(test_read_fuse) 
  {
    boot_qfprom_test_data.qfprom_service_api_status =
      (uint32_t)qfprom_read_row(boot_qfprom_test_data.qfprom_fuse_addr, 
                      boot_qfprom_test_data.addr_type, 
                      (uint32_t *)boot_qfprom_test_data.qfprom_fuse_data);
  }
} /* boot_qfprom_single_test */
#endif

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
*   Needs to be involded before TZ_SBL_END_MILESTONE service request
*   (that locks out qfprom driver in TZ).
*
*   @par Side Effects
*   None
*
*   @sa
*   None
*/
void boot_qfprom_test(void)
{

#ifdef QFPROM_BOOT_SINGLE_TEST
  do
  {
    /* loop as long as the test script sets the run always flag to do so */
    boot_qfprom_single_test();
  }while(qfprom_test_run_always == true);
#endif

}  /* qfprom_test */

