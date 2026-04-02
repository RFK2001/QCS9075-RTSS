/*=============================================================================
            Copyright (c) 2021 Qualcomm Technologies, Incorporated.
                              All rights reserved.
              Qualcomm Technologies, Confidential and Proprietary.
=============================================================================*/

/*===========================================================================

                            EDIT HISTORY FOR FILE

  $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/qfprom/src/sailhyp/fuse_hw_mutex.c#1 $
  $DateTime: 2025/07/09 22:36:30 $
  $Author: rmunibyr $


when       who     what, where, why
--------   ---     ------------------------------------------------------------
12/05/12   rs      Initial version.
=============================================================================*/



/*----------------------------------------------------------------------------
 * Include Files
 * -------------------------------------------------------------------------*/
#include <HALhwio.h>

#include "fuse_hw_mutex.h"
#include "tcsr_mutex_hwio.h"


/** Set reserved HW Mutex ID for Security use **/
#define HW_MUTEX_ID               8U

/** Set Processor ID to 1 to indicate reqest from Apps **/
#define HW_MUTEX_PID              1U

void fuse_grab_mutex(void)
{
  do
  {
    /* Attempt to write Processor ID */
    HWIO_OUTI( SAIL_TO_MD_TCSR_MUTEX_REG_n, HW_MUTEX_ID, HW_MUTEX_PID );

    /* Check if PID was written (i.e. the hardware mutex is locked) */
  } while( HWIO_INI( SAIL_TO_MD_TCSR_MUTEX_REG_n, HW_MUTEX_ID ) != HW_MUTEX_PID );
}

void fuse_release_mutex(void)
{
  /* Unlock hardware mutex by writing 0*/
  HWIO_OUTI( SAIL_TO_MD_TCSR_MUTEX_REG_n, HW_MUTEX_ID, 0 );
}
