/*
===========================================================================
*/
/**
    @file  sleep_core.c
    @brief Defination of core function of sleep driver

*/
/*
    ===========================================================================

    Copyright (c) 2023 Qualcomm Technologies, Inc.
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
    File Name          : sleep_core.c
    Component Name     : sleep
    Description        : Defination of core function of sleep driver
    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/sleep/src/sailsw1/sleep_core.c#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/



/*=========================================================================================================
**                                        Include files                                                  **
=========================================================================================================*/

#include "types.h"
#include "sleep_core.h"
#include "sleep_cmm.h"
#include "sleepEl1.h"
#include "common_functions.h"
#include "Clock.h"
#include "ClockDefs.h"
#include "target.h"
#include "debug_log.h"
/*=========================================================================================================
**                                        Global functions definition                                    **
=========================================================================================================*/


/*=========================================================================================================
 @Service name        low_power
 @Description         low_power function will put current CPU in WFI
 @param[in]           void
 @param[out]          NA
 @param[in, out]      NA
 @return              void
 @Pre                 NA
 @Post                NA
 @Requirements IDs    NA
 @Design IDs          NA
 @service ID          NA
 @Sync/Async          <Aync>          
 @Reentrancy          <NO>          
 @Note                <None>
=========================================================================================================*/

void  __attribute__((__aligned__(32))) low_power_El1(void)
{
    uint32_t grpen = 0;
    uint32 ulcpu_ID;

    ulcpu_ID = get_curr_phys_cpu_num();

    if(ulcpu_ID==0)
    {
	DEBUG_LOG(SAIL_ERROR,"INSIDE CORE 1\n\r");
        __asm__("MCR p15,0,%0,c12,c12,6"::"r"(grpen));
        __asm__("MCR p15,0,%0,c12,c12,7"::"r"(grpen));
        HWIO_OUTF(SAILSS_GIC0_ALIAS0_GICR_WAKER, PROCESSORSLEEP, 0x1);
        while(!HWIO_INF(SAILSS_GIC0_ALIAS0_GICR_WAKER, CHILDRENASLEEP));
        __asm__("ISB");
        __asm__("wfi");

    }
    else if(ulcpu_ID==0x1)
    {
	DEBUG_LOG(SAIL_ERROR,"INSIDE CORE 1\n\r");
        __asm__("MCR p15,0,%0,c12,c12,6"::"r"(grpen));
        __asm__("MCR p15,0,%0,c12,c12,7"::"r"(grpen));
        HWIO_OUTF(SAILSS_GIC0_ALIAS1_GICR_WAKER, PROCESSORSLEEP, 0x1);
        while(!HWIO_INF(SAILSS_GIC0_ALIAS1_GICR_WAKER, CHILDRENASLEEP));
        __asm__("ISB");
        __asm__("wfi");
    }
    else if(ulcpu_ID==0x2)
    {
	DEBUG_LOG(SAIL_ERROR,"INSIDE CORE 2\n\r");
        __asm__("MCR p15,0,%0,c12,c12,6"::"r"(grpen));
        __asm__("MCR p15,0,%0,c12,c12,7"::"r"(grpen));
        HWIO_OUTF(SAILSS_GIC1_ALIAS0_GICR_WAKER, PROCESSORSLEEP, 0x1);
        while(!HWIO_INF(SAILSS_GIC1_ALIAS0_GICR_WAKER, CHILDRENASLEEP));
        __asm__("ISB");
        __asm__("wfi");
    }
    else if(ulcpu_ID==0x3)
    {
        __asm__("MCR p15,0,%0,c12,c12,6"::"r"(grpen));
        __asm__("MCR p15,0,%0,c12,c12,7"::"r"(grpen));
        HWIO_OUTF(SAILSS_GIC1_ALIAS1_GICR_WAKER, PROCESSORSLEEP, 0x1);
        while(!HWIO_INF(SAILSS_GIC1_ALIAS1_GICR_WAKER, CHILDRENASLEEP));
        __asm__("ISB");
        __asm__("wfi");
    }
}
 
/**********************************************************************************************************
**                                  End of file sleep_core.c                                               **
**********************************************************************************************************/
