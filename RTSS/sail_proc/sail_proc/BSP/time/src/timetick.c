/**
 * @file timetick.c
 * @brief
 * Source file for timetick function
 *
 *        Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*==========================================================================*/
#include "timetick.h"

#include <stdio.h>

#include "types.h"
#include "HALhwio.h"
#include "sail_qtimer.h"
#include "busywait.h"

timetick_type_64 timetick_get64()
{
    uint32_t ulLow = 0U;
    uint32_t ulHigh = 0U;

    do {
        ulHigh = HWIO_IN(SAILSS_QTMR_QTMR_V1_CNTPCT_HI_0);
        ulLow = HWIO_IN(SAILSS_QTMR_QTMR_V1_CNTPCT_LO_0);
    } while (ulHigh != HWIO_IN(SAILSS_QTMR_QTMR_V1_CNTPCT_HI_0));

    return (((timetick_type_64)(ulHigh)) << 32U) + (timetick_type_64)ulLow;
}

/* Converts 64 bit ticks to the given unit */
uint64 timetick_CvtTimetick64ToTime( timetick_type_64 tick, TimetickUnitType_e xTimeUnit )
{
    uint64 timeVal = 0;

    switch( xTimeUnit )
    {
        case T_USEC:
        timeVal = ( (uint64)configXO_MICROSEC * tick ) / configXO_TICKPERSEC ;
        break;
            
        case T_MSEC:
        timeVal = ( (uint64)configXO_MILLISEC * tick ) / configXO_TICKPERSEC;
        break;

        case T_SEC:
        timeVal = ( (uint64)configXO_SEC * tick ) / configXO_TICKPERSEC;
        break;

        default:
        break;
    }

    return timeVal;
}


uint64 elapsedtime_us(timetick_type_64 t2, timetick_type_64 t1)
{
	return ((uint64)(t2-t1)*XO_CLOCK_PERIOD_NANOSEC)/1000UL;
}

void sail_timetick_init(void)
{
}
