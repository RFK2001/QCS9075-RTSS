/**
@file tzbsp_fuseprov.h
@brief Trustzone Init Handler

This file contains the routines for initializing TZBSP.

*/

/*===========================================================================
Copyright (c) 2018-2019, 2021 Qualcomm Technologies, Inc.
All Rights Reserved.
Confidential and Proprietary - Qualcomm Technologies, Inc.
===========================================================================*/

#ifndef SAIL_SEC_FUSEPROV_H
#define SAIL_SEC_FUSEPROV_H

#include "types.h"

/**
 * Blows the fuses listed in the secdat buffer loaded in TZ DDR memory
 * secdat is only consumed if the OEM SEC BOOT write perm disable fuse
 * has not been blown
 *
 * Device will reset if any fuse is blown or on error
 *
 */
void sail_sec_blow_fuses_and_reset(void);

#endif
