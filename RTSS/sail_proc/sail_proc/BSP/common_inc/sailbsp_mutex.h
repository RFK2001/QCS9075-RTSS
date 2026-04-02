/**
 * @file mutex.h
 * @brief
 * This file contains the definition of hypervisor mutex interface
 *
 *        Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*==========================================================================*/

#ifndef MUTEX_H_
#define MUTEX_H_

#include"types.h"

typedef struct __attribute__((aligned(128)))
{
  volatile uint32 lock;
} mutex_t;

/**
 * Initialize the mutex structure. The mutex functions are aliased so that the
 * standard C libary will use the below implementation.
 *
 * @returns non-zero to tell the ARM C libraries that we are running
 *          multithreaded code.
 */
uint64 mutex_init(mutex_t *mutex);

/**
 * Perform a spinlock on the mutex
 */
void mutex_lock(mutex_t *mutex);

/* Try to acquire lock and return */
uint32_t mutex_try_lock(mutex_t *mutex); /* returns 1 on success and 0 on failure*/
/**
 * Unlock the mutex
 */
void mutex_unlock(mutex_t *mutex);

#endif /* MUTEX_H_ */
