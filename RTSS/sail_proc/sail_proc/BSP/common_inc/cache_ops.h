/**
 * @cache_ops.h
 * @brief Types definitions
 * Header file for the cache operations.
 *
 *        Copyright (c) 2025 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */
#ifndef CACHE_OPS_H_
#define CACHE_OPS_H_

#ifndef ASSEMBLY

/*===========================================================================
                           INCLUDE FILES
===========================================================================*/
#include <stdbool.h> 
#include "arm_acle.h"
#include "types.h"

/*===========================================================================
                            DEFINES
===========================================================================*/
#define DCACHE_LINE_SIZE_MASK       0x000F0000
#define DCACHE_LINE_SIZE_SHIFT      16
#define DCACHE_LINE_SIZE_LOG_BASE   2
#define ICACHE_LINE_SIZE_MASK       0x0000000F
#define ICACHE_LINE_SIZE_SHIFT      0
#define ICACHE_LINE_SIZE_LOG_BASE   2
/*===========================================================================
                            MACROS
===========================================================================*/
//Memory barriers
#define mb()        __asm__ volatile("dsb sy" : : : "memory");
#define rmb()       __asm__ volatile("dsb ld" : : : "memory");
#define wmb()       __asm__ volatile("dsb st" : : : "memory");
#define smp_mb()    __asm__ volatile("dmb ish" : : : "memory");
#define smp_rmb()   __asm__ volatile("dmb ishld" : : : "memory");
#define smp_wmb()   __asm__ volatile("dmb ishst" : : : "memory");
#define ISB         __asm__("isb                          ");
#define DSB         __asm__("dsb                          ");

/*===========================================================================
                            Functions 
===========================================================================*/
//Enable Cache OPs
void enable_icache(void);
void enable_dcache(void);
void enable_caches(void);

//Disable Cache OPs
void disable_icache(void);
void disable_dcache(void);
void disable_caches(void);

//Invalidate Cache OPs
void invalidate_icache(void);
void invalidate_dcache(void);
void invalidate_caches(void);
 
//Clean Cache OPs

//*_by_addr operations
void invalidate_icache_by_addr(uint32 addr);
void invalidate_dcache_by_addr(uint32 addr);
void clean_dcache_by_addr(uint32 addr);
void clean_invalidate_cache_by_addr(uint32 addr);

//*_by_range operations
void invalidate_icache_by_range(uint32 start_addr,uint32 end_addr);
void invalidate_dcache_by_range(uint32 start_addr,uint32 end_addr);
void clean_dcache_by_range(uint32 start_addr,uint32 end_addr);
void clean_invalidate_cache_by_range(uint32 start_addr,uint32 end_addr);


/*===========================================================================
                            Inline Functions 
===========================================================================*/
static inline uint32 arch_get_dcache_line_size( void ) {
    uint32 val = 0;
    
    val = __arm_mrc(15, 0, 0, 0, 1);    
    val &= DCACHE_LINE_SIZE_MASK;
    val >>= DCACHE_LINE_SIZE_SHIFT;
    val <<= DCACHE_LINE_SIZE_LOG_BASE;
    
    return val;
}

static inline uint32 arch_get_icache_line_size( void ) {
    uint32 val = 0;
    
    val = __arm_mrc(15, 0, 0, 0, 1);    
    val &= ICACHE_LINE_SIZE_MASK;
    val >>= ICACHE_LINE_SIZE_SHIFT;
    val <<= ICACHE_LINE_SIZE_LOG_BASE;
    
    return val;
}

#endif // ASSEMBLY
#endif //CACHE_OPS

