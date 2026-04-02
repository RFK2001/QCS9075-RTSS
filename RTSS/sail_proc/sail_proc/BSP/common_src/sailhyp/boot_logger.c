/*
===========================================================================
*/
/**
    @file  boot_logegr.c
    @brief This file implements sail boot logger

*/
/*
    ===========================================================================

    Copyright (c) 2021-2022 Qualcomm Technologies, Inc.
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

    $Header:   $
    $DateTime:  $
    $Author:   $

    ===========================================================================
*/

#include "common_functions.h"
#include "types.h"
#include <HALhwio.h>
#include "g_SAIL_QTMR.h"
#include "debug_log.h"
#define  TIME_FREQ      19200000UL
#define  TIME_NS        1000000UL

uint64 uBootLogger_LogStartTime(const char *message, int cpu)
{
    uint64 startTime = (uint64) HWIO_IN(SAILSS_QTMR_QTMR_V1_CNTPCT_LO_0);
    startTime |= ((uint64) HWIO_IN(SAILSS_QTMR_QTMR_V1_CNTPCT_HI_0) & 0xfffULL) << 32U;
    DEBUG_LOG(SAIL_WARNING, "KPI_MARKER: %s %d, Start time: %lldus \r\n", message, cpu, ((startTime * TIME_NS) / TIME_FREQ));

    return startTime;
}

void uBootLogger_LogAbsTime(const char *message, int cpu)
{
    uint64 time = (uint64) HWIO_IN(SAILSS_QTMR_QTMR_V1_CNTPCT_LO_0);
    time |= ((uint64) HWIO_IN(SAILSS_QTMR_QTMR_V1_CNTPCT_HI_0) & 0xfffULL) << 32U;
    DEBUG_LOG(SAIL_INFO, "A -----> %lldus %s %d \r\n", ((time * TIME_NS) / TIME_FREQ), message, cpu);

}

uint64 vBootLogger_LogDeltaTime(uint64 startTime, const char *message, int cpu)
{

    uint64 deltaTime = 0;
    uint64 currTime = (uint64) HWIO_IN(SAILSS_QTMR_QTMR_V1_CNTPCT_LO_0);
    currTime |= ((uint64) HWIO_IN(SAILSS_QTMR_QTMR_V1_CNTPCT_HI_0) & 0xfffULL) << 32U;

    deltaTime = ((currTime - startTime) * TIME_NS) / TIME_FREQ;
    DEBUG_LOG(SAIL_WARNING, "KPI_MARKER: %s %d, Time taken: %lldus \r\n", message, cpu, deltaTime);
    
    return deltaTime;
}
