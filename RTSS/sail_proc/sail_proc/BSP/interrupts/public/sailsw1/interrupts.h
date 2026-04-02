/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * All rights reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

/*
 * Portions Copyright (c) 2008 Travis Geiselbrecht
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#ifndef __PLATFORM_INTERRUPTS_EL1_H
#define __PLATFORM_INTERRUPTS_EL1_H

/*=========================================================================
      Include Files
==========================================================================*/
#include "types.h"

/*=========================================================================
      Type Definitions
==========================================================================*/

//TODO: Once EL1 and El2 seperate images are available, change the interrupt types and APIs naming conventions.
/**
 * Interrupt handlers callback data type.
 */
typedef void (*InterruptHandle_t)(void *arg);

/**
 * Interrupt configuration enum.
 */
enum InterruptConfig_t
{
   EL1_INT_CONFIG_LEVEL_TRIGGER    = 0,
   EL1_INT_CONFIG_EDGE_TRIGGER     = 1,
   EL1_INT_CONFIG_MAX,
};

typedef enum
{
    INT_EL1_SUCCESS = 0,
    INT_EL1_ERR_GENERIC = -1,
    INT_EL1_ERR_OUT_OF_RANGE = -2,
    INT_EL1_ERR_BAD_HANDLE = -3,
    INT_EL1_ERR_ALREADY_EXISTS = -4,
}intEl1Status_t;

/*=========================================================================
      Macros
==========================================================================*/
#define SAVE_FPU_REGISTERS()                        \
    __asm volatile                                  \
    (                                               \
        "   vstmdb  sp!, {d16-d31}  \n"             \
        "   vstmdb  sp!, {d0-d15}   \n"             \
        "   vmrs    r1, fpscr       \n"             \
        "   stmdb   sp!, {r1}       \n"             \
        ::: "r1", "memory"                          \
    )

#define RESTORE_FPU_REGISTERS()                     \
    __asm volatile                                  \
    (                                               \
        "   ldmia   sp!, {r1}       \n"             \
        "   vmsr    fpscr, r1       \n"             \
        "   vldmia  sp!, {d0-d15}   \n"             \
        "   vldmia  sp!, {d16-d31}  \n"             \
        ::: "r1", "memory"                          \
    )

/*=========================================================================
      Interface Declarations
==========================================================================*/

intEl1Status_t xGicInitEl1( void );

intEl1Status_t xGicConfigureInt(uint32_t vector, enum InterruptConfig_t icfg, void* arg);

intEl1Status_t xGicSetIntPriority(uint32_t vector, uint32_t priority);

intEl1Status_t xGicSetIntEnable(uint vector, bool enable);

intEl1Status_t xGicRegisterIntHandler(uint32_t vector, InterruptHandle_t handler, void *arg);

intEl1Status_t xGicUnRegisterIntHandler(uint32_t vector, uint32_t flags);


#endif /* __PLATFORM_INTERRUPTS_EL1_H */