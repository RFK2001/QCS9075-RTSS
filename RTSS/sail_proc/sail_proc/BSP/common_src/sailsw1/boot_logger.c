/*
===========================================================================
*/
/**
    @file  boot_logegr_el1.c
    @brief This file provides dummy implementation for el1 compilation

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
#ifdef SAILSW3
#include "logcode.h"
#include "busywait.h"
#endif

#define  TIME_FREQ      19200000UL
#define  TIME_NS        1000000UL

uint64 uBootLogger_LogStartTime(char *message, int cpu)
{
    return 0;
}

void uBootLogger_LogAbsTime(char *message, int cpu)
{
   return;
}

void vBootLogger_LogDeltaTime(uint64 startTime, char *message, int cpu)
{
    return;
}
