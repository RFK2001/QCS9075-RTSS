/**
 * @file busywait.c
 * @brief
 * Source file for wrapper functions of busywait
 *
 *        Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*==========================================================================*/

#include <stdio.h>
#include "common_functions.h"
#include "busywait.h"
#include "sail_qtimer.h"
#include "HALhwio.h"

static BSP_GLOBAL_DATA uint32 cntfreq;
static BSP_GLOBAL_DATA uint32 rtc_cntfreq;

/*!
*
* @brief
*	busy loops for given usec
*	32 bit implementation.
*
* @param
*	@param[in] delay_usec - delay time in microseconds
* @par Dependencies
*   None
* @retval
*   None
* @par Side Effects
*   None
*
*/
void busywait(uint32 delay_usec)
{
	uint32	scount, dcount;

	scount = in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_0_ADDR);
	dcount = (delay_usec * (uint64)cntfreq)/configXO_MICROSEC;

	while ((in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_0_ADDR) - scount) < dcount);
}

/* qtimer resolution is 52ns per one tick/count */
void busywait_ns(uint32 delay_ns)
{
	uint32	scount, dcount;

	scount = in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_0_ADDR);
	dcount = 2U + delay_ns/XO_CLOCK_PERIOD_NANOSEC; /* last clock check may be the end of the clock period */

	while ((in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_0_ADDR) - scount) < dcount);
}

void busywait_init(void)
{
	if (in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_0_ADDR) == 0) {
		out_dword(HWIO_SAILSS_QTMR_QTMR_AC_CNTFRQ_ADDR, configXO_TICKPERSEC);
	}

	cntfreq = in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_0_ADDR);
}

