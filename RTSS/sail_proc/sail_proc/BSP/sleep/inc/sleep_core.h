#ifndef __SLEEP_CORE_H_
#define __SLEEP_CORE_H_

/*
===========================================================================
*/
/**
    @file  sleep_core.h
    @brief Private interface include file for sleep internal os abstraction layer.

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
    File Name          : sleep_core.h
    Component Name     : pmu
    Description        : contains prototype of internal core function of sleep
    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/sleep/inc/sleep_core.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/


#include "types.h"
#include "sleep_hwio.h"
#include "HALhwio.h"
#include "hw_io.h"
#include "sleep_cmm.h"

/*=========================================================================
      Type Definitions
==========================================================================*/

#define BIT_0    (0x1<<0x0)
#define BIT_1    (0x1<<0x1)
#define BIT_2    (0x1<<0x2)
#define BIT_3    (0x1<<0x3)
#define BIT_4    (0x1<<0x4)
#define BIT_5    (0x1<<0x5)
#define BIT_6    (0x1<<0x6)
#define BIT_7    (0x1<<0x7)
#define BIT_8    (0x1<<0x8)
#define BIT_9    (0x1<<0x9)
#define BIT_10   (0x1<<0xA)
#define BIT_11   (0x1<<0xB)
#define BIT_12   (0x1<<0xC)


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

void low_power(void);
void low_power_El1(void);

#endif