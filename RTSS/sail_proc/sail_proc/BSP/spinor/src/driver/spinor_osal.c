/*
===========================================================================
*/
/**
    @file  spinor_osal.c
    @brief This file provides definitions for the spinor OS abstratcion Layer

*/
/*
    ===========================================================================

    Copyright (c) 2017-2018,2020-2022 Qualcomm Technologies, Inc.
    All Rights Reserved.
    Confidential and Proprietary - Qualcomm Technologies, Inc.

    Export of this technology or software is regulated by the U.S. Government.
    Diversion contrary to U.S. law prohibited.

    All ideas, data and information contained in or disclosed by
    this document are confidential and proprietary information of
    Qualcomm Technologies, Inc. and all rights therein are expressly reserved.
    By accepting this material the recipient agrees that this material
    and the information contained therein are held in confidence and in
    trust and will not be used, copied, reproduced in whole or in part,
    nor its contents revealed in any manner to others without the express
    written permission of Qualcomm Technologies, Inc.

    ===========================================================================

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/src/driver/spinor_osal.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "spinor_osal.h"
#include "busywait.h"

/* Cache management wrapper */

void spinor_cache_flush (void *addr, uint32_t len)
{
  clean_dcache_by_range((uint32) addr,(uint32)addr + len);
}

void spinor_cache_inval (void *addr, uint32_t len)
{
  invalidate_dcache_by_range((uint32) addr,(uint32)addr + len);
}

void spinor_cache_flush_inval(uint8_t *addr, uint8_t len)
{
  clean_invalidate_cache_by_range((uint32) addr,(uint32)addr + len);
}

/**********************************************************
 * Flash delay in uint of micro seconds
 *
 * @param usec_delay [IN]
 *   Number of micro seconds delay.
 *
 **********************************************************/
void spinor_udelay (uint32 usec_delay)
{
  busywait(usec_delay);
}

/**********************************************************
 * Flash delay in uint of nano seconds
 *
 * @param nsec_delay [IN]
 *   Number of nano seconds delay.
 *
 **********************************************************/
void spinor_ndelay (uint32 nsec_delay)
{
  busywait_ns(nsec_delay);
}
