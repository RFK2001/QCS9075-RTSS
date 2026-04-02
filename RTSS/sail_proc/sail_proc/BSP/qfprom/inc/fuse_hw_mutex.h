#ifndef FUSE_HW_MUTEX_H
#define FUSE_HW_MUTEX_H

/*=============================================================================
            Copyright (c) 2021 Qualcomm Technologies, Incorporated.
                              All rights reserved.
              Qualcomm Technologies, Confidential and Proprietary.
=============================================================================*/

/*===========================================================================

                           EDIT HISTORY FOR FILE

This section contains comments describing changes made to this file.
Notice that changes are listed in reverse chronological order.

$Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/qfprom/inc/fuse_hw_mutex.h#1 $
$DateTime: 2025/07/09 22:36:30 $
$Author: rmunibyr $

when       who     what, where, why
--------   ---     ----------------------------------------------------------
12/05/12   rs      First version.
============================================================================*/

/**
 * Grab Hardware Mutex for QFPROM Driver
 *
 */
void fuse_grab_mutex(void) __attribute__((weak));

/**
 * Release Hardware Mutex for QFPROM Driver
 *
 */
void fuse_release_mutex(void) __attribute__((weak));


#endif /* FUSE_HW_MUTEX_H */
