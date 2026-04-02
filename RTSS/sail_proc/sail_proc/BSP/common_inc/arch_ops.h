/*
 * Copyright (c) 2008-2014 Travis Geiselbrecht
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

#ifndef ASSEMBLY

#include <stdbool.h>
#include <compiler.h>
#include <arm64.h>
#include "arm_acle.h"

#define USE_GCC_ATOMICS 1
#define ENABLE_CYCLE_COUNTER 1

static inline unsigned int arch_get_cpsr(void)
{
    unsigned int val=0U;
    CF;
    __asm__ volatile (" mrs %0, cpsr" : "=r" (val) :  );
    return val;
}

static inline void arch_set_cpsr(unsigned val)
{
    __asm__ volatile (" msr cpsr, %0":  :"r" (val));
    CF;
}

// override of some routines
static inline void arch_enable_ints(void)
{
    CF;
   __asm__ volatile("cpsie  aif");
}

static inline void arch_disable_ints(void)
{
    __asm__ volatile("cpsid  aif");
    CF;
}

static inline bool arch_ints_disabled(void)
{
    unsigned int state = arch_get_cpsr();
    state &= (1<<7);

    return !!state;
}

static inline void arch_enable_aborts(void)
{
    CF;
    __asm__ volatile("cpsie  a");
}

static inline void arch_disable_aborts(void)
{
    __asm__ volatile("cpsid  a");
    CF;
}

static inline void arch_enable_fiqs(void)
{
    CF;
    __asm__ volatile("cpsie  f");
}

static inline void arch_disable_fiqs(void)
{
    __asm__ volatile("cpsid  f");
    CF;
}

// XXX
static inline bool arch_fiqs_disabled(void)
{
    unsigned int state = arch_get_cpsr();
    
    state &= (1<<6);

    return !!state;
}

static inline uint32 arch_read_mpidr(void)
{
    uint32_t val;
    val = __arm_mrc(15, 0, 0, 0, 5);
    ISB;
    DSB;
    return val;
}

static inline void arch_write_cntvtval(uint32_t val)
{
    /* Counter-timer Virtual Timer TimerValue Register - CNTV_TVAL */
    __arm_mcr(15, 0, val, 14, 3, 0);
    ISB;
    DSB;
}

static inline uint32_t arch_read_cntvtval( void )
{
    /* Counter-timer Virtual Timer TimerValue Register - CNTV_TVAL */
    uint32_t val;
    val = __arm_mrc(15, 0, 14, 3, 0);
    ISB;
    DSB;
    return val;
}

static inline void arch_write_cntvctl(uint32_t val)
{
    /* Counter-timer Virtual Timer Control Register - CNTV_CTL */
    __arm_mcr(15, 0, val, 14, 3, 1);
    ISB;
    DSB;
}

static inline uint64_t arch_read_cntvct(void)
{
    uint64_t val;
    val = __arm_mrrc(15, 1, 14);
    ISB;
    DSB;
    return val;
}

static inline uint64_t arch_read_cntvcval(void)
{
    uint64_t val;
    val = __arm_mrrc(15, 3, 14);
    ISB;
    DSB;
    return val;
}

static inline void arch_write_cntvcval(uint64_t val)
{
    __arm_mcrr(15, 3, val, 14);
    ISB;
    DSB;
}

static inline uint arch_curr_cpu_num(void)
{
// TODO: Move chipset params into platform headers
    uint cpu_num;  
    uint64_t mpidr =  arch_read_mpidr();
    cpu_num = (mpidr & 0xFF);

    if (cpu_num >= 2)
      while (1)
        ;
    return cpu_num;
}

static inline uint arch_curr_cluster_num(void)
{
// TODO: Move chipset params into platform headers
    uint cluster_num;  
    uint64_t mpidr =  arch_read_mpidr();
    cluster_num = (mpidr & 0xFF00) >> 8;

    if (cluster_num >= 2)
      while (1)
        ;
    return cluster_num;
 
}

static inline uint arch_curr_cpu_id(void)
{
// TODO: Move chipset params into platform headers
    uint cpu_num;  
    uint cluster_num; 
    uint64_t mpidr =  __arm_mrc(15, 0, 0, 0, 5);
    cpu_num = (mpidr & 0xFF);
    cluster_num = (mpidr & 0xFF00) >> 7;
    cpu_num |= cluster_num;
    if (cpu_num >= 4)
      while (1)
        ;
    return cpu_num;
}
#define mb()        __asm__ volatile("dsb sy" : : : "memory")
#define rmb()       __asm__ volatile("dsb ld" : : : "memory")
#define wmb()       __asm__ volatile("dsb st" : : : "memory")

#ifdef WITH_SMP
#define smp_mb()    __asm__ volatile("dmb ish" : : : "memory")
#define smp_rmb()   __asm__ volatile("dmb ishld" : : : "memory")
#define smp_wmb()   __asm__ volatile("dmb ishst" : : : "memory")
#else
#define smp_mb()    CF
#define smp_wmb()   CF
#define smp_rmb()   CF
#endif

static inline int atomic_add(volatile int *ptr, int val)
{
#if USE_GCC_ATOMICS
    return __atomic_fetch_add(ptr, val, __ATOMIC_RELAXED);
#else
    int old;
    int temp;
    int test;

    do {
        __asm__ volatile(
            "ldrex  %[old], [%[ptr]]\n"
            "adds   %[temp], %[old], %[val]\n"
            "strex  %[test], %[temp], [%[ptr]]\n"
            : [old]"=&r" (old), [temp]"=&r" (temp), [test]"=&r" (test)
            : [ptr]"r" (ptr), [val]"r" (val)
            : "memory", "cc");

    } while (test != 0);

    return old;
#endif
}

static inline int atomic_or(volatile int *ptr, int val)
{
#if USE_GCC_ATOMICS
    return __atomic_fetch_or(ptr, val, __ATOMIC_RELAXED);
#else
    int old;
    int temp;
    int test;

    do {
        __asm__ volatile(
            "ldrex  %[old], [%[ptr]]\n"
            "orrs   %[temp], %[old], %[val]\n"
            "strex  %[test], %[temp], [%[ptr]]\n"
            : [old]"=&r" (old), [temp]"=&r" (temp), [test]"=&r" (test)
            : [ptr]"r" (ptr), [val]"r" (val)
            : "memory", "cc");

    } while (test != 0);

    return old;
#endif
}

static inline int atomic_and(volatile int *ptr, int val)
{
#if USE_GCC_ATOMICS
    return __atomic_fetch_and(ptr, val, __ATOMIC_RELAXED);
#else
    int old;
    int temp;
    int test;

    do {
        __asm__ volatile(
            "ldrex  %[old], [%[ptr]]\n"
            "ands   %[temp], %[old], %[val]\n"
            "strex  %[test], %[temp], [%[ptr]]\n"
            : [old]"=&r" (old), [temp]"=&r" (temp), [test]"=&r" (test)
            : [ptr]"r" (ptr), [val]"r" (val)
            : "memory", "cc");

    } while (test != 0);

    return old;
#endif
}

static inline int atomic_swap(volatile int *ptr, int val)
{
#if USE_GCC_ATOMICS
    return __atomic_exchange_n(ptr, val, __ATOMIC_RELAXED);
#else
    int old;
    int test;

    do {
        __asm__ volatile(
            "ldrex  %[old], [%[ptr]]\n"
            "strex  %[test], %[val], [%[ptr]]\n"
            : [old]"=&r" (old), [test]"=&r" (test)
            : [ptr]"r" (ptr), [val]"r" (val)
            : "memory");

    } while (test != 0);

    return old;
#endif
}

static inline int atomic_cmpxchg(volatile int *ptr, int oldval, int newval)
{
#if USE_GCC_ATOMICS
    __atomic_compare_exchange_n(ptr, &oldval, newval, false,
                                __ATOMIC_RELAXED, __ATOMIC_RELAXED);
    return oldval;
#else
    int old;
    int test;

    do {
        __asm__ volatile(
            "ldrex  %[old], [%[ptr]]\n"
            "mov    %[test], #0\n"
            "teq    %[old], %[oldval]\n"
            "bne    0f\n"
            "strex  %[test], %[newval], [%[ptr]]\n"
            "0:\n" 
            : [old]"=&r" (old), [test]"=&r" (test)
            : [ptr]"r" (ptr), [oldval]"Ir" (oldval), [newval]"r" (newval)
            : "cc");

    } while (test != 0);

    return old;
#endif
}

static inline uint32_t arch_cycle_count(void)
{ 
    uint32_t count;
    __asm__ volatile("mrc       p15, 0, %0, c9, c13, 0"
                     : "=r" (count)
                    );
    return count; 
}


#endif // ASSEMBLY

