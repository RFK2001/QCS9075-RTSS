/**
 * @barrier.h
 * @brief Barrier  definitions
 * Header file for the Barrier operations.
 *
 *        Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */
#ifndef _BARRIER_H_
#define _BARRIER_H_


/*===========================================================================
                           INCLUDE FILES
===========================================================================*/

#include "types.h"

/*===========================================================================
                            DEFINES
===========================================================================*/
/* compiler fence */
#define CF do { __asm__ volatile("" ::: "memory"); } while(0)
// Ensure that writes to CPU configuration registers and other similar events
// are visible to code executing on the CPU. For example, use this between
// enabling access to floating point registers and actually using those
// registers.
#define asm_context_sync_fence()	__asm__ volatile("isb" ::: "memory")
#define asm_context_sync_ordered(order) __asm__ volatile("isb" : "+m"(*order))

// The asm_ordering variable is used as an artificial dependency to order
// different individual asm statements with respect to each other in a way that
// is lighter weight than a full "memory" clobber.
extern struct asm_ordering_dummy asm_ordering;
/*===========================================================================
                            MACROS
===========================================================================*/

/*===========================================================================
                            Functions 
===========================================================================*/

#endif //BARRIER_H

