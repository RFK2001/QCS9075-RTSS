/*
 * Copyright (c) 2019 Qualcomm Technologies, Inc. All rights reserved.
 * Portions Copyright (c) 2014 Travis Geiselbrecht
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
#pragma once

#include <stdbool.h>
#include <types.h>
#include <compiler.h>
#include "arm_acle.h"

__BEGIN_CDECLS

#define ISB         __asm__("isb                          ");
#define DSB         __asm__("dsb                          ");

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

void arm64_context_switch(vaddr_t *old_sp, vaddr_t new_sp);

/* exception handling */
struct arm64_iframe_long {
    uint64_t r[30];
    uint64_t lr;
    uint64_t usp;
    uint64_t elr;
    uint64_t spsr;
    uint64_t esr;
    uint64_t far;
};

struct arm64_iframe_short {
    uint64_t r[18];
    uint64_t lr;
    uint64_t usp;
    uint64_t elr;
    uint64_t spsr;
};

struct thread;
extern void arm64_exception_base(void);
void arm64_el3_to_el1(void);
void arm64_fpu_exception(struct arm64_iframe_long *iframe);
void arm64_fpu_save_state(struct thread *thread);
void arm64_fpu_load_state(struct thread *thread);
/*
static inline void arm64_fpu_pre_context_switch_restore(struct thread *thread)
{
    uint32_t cpacr = ARM64_READ_SYSREG(cpacr_el1);
    if ((cpacr >> 20) & 3) {
        arm64_fpu_load_state (thread);
    }
}

static inline void arm64_fpu_pre_context_switch(struct thread *thread)
{
    uint32_t cpacr = ARM64_READ_SYSREG(cpacr_el1);
    if ((cpacr >> 20) & 3) {
        arm64_fpu_save_state(thread);
		//  Do not disable FPU register access
        // cpacr &= ~(3 << 20);
        // ARM64_WRITE_SYSREG(cpacr_el1, cpacr);
    }
}*/

/* overridable syscall handler */
void arm64_syscall(struct arm64_iframe_long *iframe, bool is_64bit);

static inline uint64_t get_timer_cnt (void)
{
    uint64_t val;
    val = __arm_mrrc(15, 1, 14);
    ISB;
    DSB;
    return val;
}

#define DEFAULT_ARCH_CPU_TIMER_FREQ    19200000
//#define TIMER_CNT_TO_US(x)             (((x)*1000000)/DEFAULT_ARCH_CPU_TIMER_FREQ)
// This following alternate option optimizes better
#define TIMER_CNT_TO_US(x)             (((x)*(1000000/100000))/(DEFAULT_ARCH_CPU_TIMER_FREQ/100000))

static inline uint64_t get_timer_cnt_us (void)
{
  return TIMER_CNT_TO_US(get_timer_cnt());
}

__END_CDECLS

