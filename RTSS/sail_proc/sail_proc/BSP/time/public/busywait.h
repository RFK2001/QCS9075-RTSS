
#ifndef __BUSYWAIT_H__
#define __BUSYWAIT_H__
/**
 * @file busywait.h
 * @brief
 * Header file for busywait function
 *
 *        Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */
/*==========================================================================*/

#include <stdio.h>
#include "types.h"

#define configXO_MICROSEC           ( 1000000UL )
#define configXO_MILLISEC           ( 1000UL )
#define configXO_SEC                ( 1UL )

#define configXO_TICKPERSEC         ( 19200000UL )
#define XO_CLOCK_PERIOD_NANOSEC     52

//busywait loop
void busywait(uint32 delay_usec);
void busywait_ns(uint32 ns);
void busywait_init(void);

#endif //__BUSYWAIT_H__
