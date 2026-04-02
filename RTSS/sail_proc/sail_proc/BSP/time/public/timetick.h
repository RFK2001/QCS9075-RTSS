#ifndef SAIL_TIMETICK_H_
#define SAIL_TIMETICK_H_

/**
 * @file timetick.h
 * @brief
 * Header file for timetick declarations
 *
 *        Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*==========================================================================*/
#include "types.h"

typedef uint64  timetick_type_64;

typedef enum
{
   T_USEC = 1,
   T_MSEC,
   T_SEC
}TimetickUnitType_e;

timetick_type_64 timetick_get64(void);
uint64 elapsedtime_us(timetick_type_64 t2, timetick_type_64 t1);
uint64 timetick_CvtTimetick64ToTime( timetick_type_64 tick, TimetickUnitType_e xTimeUnit );
void sail_timetick_init(void);

#endif /* SAIL_TIMETICK_H_ */
