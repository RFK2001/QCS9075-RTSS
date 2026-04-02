/**************************************************************************************************
** Copyright (c) 2022-2025 Qualcomm Technologies, Inc.                                                **
** All Rights Reserved.                                                                          **
** Confidential and Proprietary - Qualcomm Technologies, Inc.                                    **
**************************************************************************************************/

/*=================================================================================================
    File Name          : lib_mutex.c
    Component Name     : common_src
    Description        : Implemented the _mutex_* to make the thread-safe heap API, as mentioned by
                         ARM C library user guide.
    $Header: $
    $DateTime: $
    $Author: $
=================================================================================================*/

/*=================================================================================================
**                                        Include files                                          **
=================================================================================================*/
#include"sailbsp_mutex.h"

/*
 * This function accepts a pointer to a pointer-sized word and initializes it as a valid mutex.
 */
__attribute__((used)) int _mutex_initialize(mutex_t *mutex)
{
    mutex_init(mutex);
    return 1;
}

/*
 * This function causes the calling thread to obtain a lock on the supplied mutex.
 */
__attribute__((used)) void _mutex_acquire(mutex_t *mutex)
{
    mutex_lock(mutex);
}

/*
 * This function causes the calling thread to release the lock on a mutex acquired by
 * _mutex_acquire().
 */
__attribute__((used)) void _mutex_release(mutex_t *mutex)
{
    mutex_unlock(mutex);
}

/*
 * This function is optional. If you do not supply this function, the C library does not attempt to
 * call it.
 */
#if 0
__attribute__((used)) void _mutex_free(mutex_t *mutex)
{
    return;
}
#endif
