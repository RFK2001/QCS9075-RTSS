/**
 * @file cache.scuceed
 * @brief
 * This file contains the Cache Operations routines.
 *
 *        Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*==========================================================================*/

//ICache Ops
.global enable_icache 
.type enable_icache,%function
enable_icache:
    dsb
    isb    
    mrc     p15, 4, r1, c1, c0, 0   // HSCTLR
    orr     r1, r1, #(0x1 << 12)     // I bit (I cache)
    mcr     p15, 4, r1, c1, c0, 0
    // Ensure all writes to system registers have taken place
    isb
    dsb
    bx      lr
 
    
.global disable_icache 
.type disable_icache,%function
disable_icache:
    dsb
    isb    
    mrc     p15, 4, r1, c1, c0, 0   // HSCTLR
    ands    r1, r1, #0xffffefff     //Clear I bit (I cache)
    mcr     p15, 4, r1, c1, c0, 0
    // Ensure all writes to system registers have taken place
    isb
    dsb
    bx      lr

.global invalidate_icache 
.type invalidate_icache,%function
invalidate_icache:
    dsb
    isb 
    mcr     p15,0,r0,c7,c5,0        // ICIALLU operation, invalidate I$ (ignores the value in r0)
    bx      lr


//DCache Ops
.global enable_dcache 
.type enable_dcache,%function
enable_dcache:
    dsb
    isb
    mrc     p15, 4, r1, c1, c0, 0   // HSCTLR
    orr     r1, r1, #(0x1 << 2)    // C bit (Data cache)
    mcr     p15, 4, r1, c1, c0, 0
    // Ensure all writes to system registers have taken place
    isb
    dsb
    bx      lr
    
.global disable_dcache 
.type disable_dcache,%function
disable_dcache:
    dsb
    isb
    mrc     p15, 4, r1, c1, c0, 0   // HSCTLR
    ands    r1, r1, #0xfffffffb      // clear C bit (Data cache)
    mcr     p15, 4, r1, c1, c0, 0
    // Ensure all writes to system registers have taken place
    isb
    dsb
    bx      lr

.global invalidate_dcache 
.type invalidate_dcache,%function
invalidate_dcache:
    push {r4}
    dsb
    isb
    // Invalidate Dcache
    ldr     r0, =0x00002000         // Initial address (assuming maximum cache size)
    ldr     r1, =0x40000000         // Way 1
    ldr     r2, =0x80000000         // Way 2
    ldr     r3, =0xc0000000         // Way 3
    ldr     r4, =0x0000FFFF         // Address mask

inval_d_set:    
    sub     r0, r0, #0x40           // move the previous cache line
    
    // Invalidate Way 0
    mcr     p15,0,r0,c7,c6,2        // DCISW operation
    
    // Invalidate Way 1
    orrs    r0, r0, r1
    mcr     p15,0,r0,c7,c6,2        // DCISW operation
    
    // Invalidate Way 2
    and     r0, r0, r4
    orrs    r0, r0, r2
    mcr     p15,0,r0,c7,c6,2        // DCISW operation
    
    // Invalidate Way 3
    and     r0, r0, r4
    orrs    r0, r0, r3
    mcr     p15,0,r0,c7,c6,2        // DCISW operation
    
    // check that last set has been invalidated
    and     r0, r0, r4
    cmp     r0, #0
    bne     inval_d_set
    isb
    dsb
    pop {r4}
    bx      lr    

//Place holder for Clean D cache
 
 //I Cache + D Cache
.global enable_caches 
.type enable_caches,%function
enable_caches:
    dsb
    isb
    mrc     p15, 4, r1, c1, c0, 0   // HSCTLR
    orr     r1, r1, #(0x1 << 2)     // C bit (data cache)
    orr     r1, r1, #(0x1 << 12)    // I bit (instruction cache)
    mcr     p15, 4, r1, c1, c0, 0
    isb
    dsb
    bx      lr

.global disable_caches
.type disable_caches,%function
disable_caches:
    dsb
    isb
    mrc     p15, 4, r1, c1, c0, 0   // HSCTLR
    ands    r1, r1, #0xfffffffb     // clear C bit (Data cache)
    ands    r1, r1, #0xffffefff     // clear I bit (Instruction cache)
    mcr     p15, 4, r1, c1, c0, 0
    // Ensure all writes to system registers have taken place
    isb
    dsb
    bx      lr

.global invalidate_caches 
.type invalidate_caches,%function
invalidate_caches:
    push {r4}
    dsb
    isb
    // Invalidate Icache
    mcr     p15,0,r0,c7,c5,0        // ICIALLU operation, invalidate I$ (ignores the value in r0)
    // Invalidate Dcache
    ldr     r0, =0x00002000         // Initial address (assuming maximum cache size)
    ldr     r1, =0x40000000         // Way 1
    ldr     r2, =0x80000000         // Way 2
    ldr     r3, =0xc0000000         // Way 3
    ldr     r4, =0x0000FFFF         // Address mask

inval_d_set1:    
    sub     r0, r0, #0x40           // move the previous cache line
    
    // Invalidate Way 0
    mcr     p15,0,r0,c7,c6,2        // DCISW operation
    
    // Invalidate Way 1
    orrs    r0, r0, r1
    mcr     p15,0,r0,c7,c6,2        // DCISW operation
    
    // Invalidate Way 2
    and     r0, r0, r4
    orrs    r0, r0, r2
    mcr     p15,0,r0,c7,c6,2        // DCISW operation
    
    // Invalidate Way 3
    and     r0, r0, r4
    orrs    r0, r0, r3
    mcr     p15,0,r0,c7,c6,2        // DCISW operation
    
    // check that last set has been invalidated
    and     r0, r0, r4
    cmp     r0, #0
    bne     inval_d_set1
    isb
    dsb
    pop {r4}
    bx      lr    
    
    
/* ICIMVAU, Invalidate Instruction Cache Line by MVA to PoU */
.global invalidate_icache_by_addr 
.type invalidate_icache_by_addr,%function
invalidate_icache_by_addr: 
    isb
    mcr     p15,0,r0,c7,c5,1
    isb
    dsb
    bx      lr    


/* DCIMVAC, Invalidate data cache line by MVA to PoC */
.global invalidate_dcache_by_addr 
.type invalidate_dcache_by_addr,%function
invalidate_dcache_by_addr: 
    dsb
    isb
    mcr     p15,0,r0,c7,c6,1
    isb
    dsb
    bx      lr 

/* DCCMVAC, Clean data cache line by MVA to PoC */
.global clean_dcache_by_addr 
.type clean_dcache_by_addr,%function
clean_dcache_by_addr: 
    dsb
    isb
    mcr     p15,0,r0,c7,c10,1
    isb
    dsb
    bx      lr 

/* DCCIMVAC, Clean and invalidate data cache line by MVA to PoC */
.global clean_invalidate_cache_by_addr 
.type clean_invalidate_cache_by_addr,%function
clean_invalidate_cache_by_addr: 
    dsb
    isb
    mcr     p15,0,r0,c7,c14,1
    isb
    dsb
    bx      lr 
    
.global invalidate_icache_by_range 
.type invalidate_icache_by_range,%function    
invalidate_icache_by_range:
    dsb
    isb
 
    mov r2, #32   // hardcode the cache line size to 32
 
    /* r2 <- minimal cache line size in cache system */
    sub     r3, r2, #1
    bic     r0, r0, r3
 1: mcr     p15,0,r0,c7,c5,1         
    add     r0, r0, r2
    cmp     r0, r1
    blt    1b
 
    isb
    dsb
    bx      lr 

.global invalidate_dcache_by_range 
.type invalidate_dcache_by_range,%function
invalidate_dcache_by_range:
    dsb
    isb

    mov r2, #32   // hardcode the cache line size to 32
 
    /* r2 <- minimal cache line size in cache system */
    sub     r3, r2, #1
    bic     r0, r0, r3
 1: mcr     p15,0,r0,c7,c6,1        
    add     r0, r0, r2
    cmp     r0, r1
    blt     1b

    isb
    dsb
    bx      lr 

.global clean_dcache_by_range 
.type clean_dcache_by_range,%function
clean_dcache_by_range:
    dsb
    isb

    mov r2, #32   // hardcode the cache line size to 32
 
    /* r2 <- minimal cache line size in cache system */
    sub     r3, r2, #1
    bic     r0, r0, r3
 1: mcr     p15,0,r0,c7,c10,1
    add     r0, r0, r2
    cmp     r0, r1
    blt    1b

    isb
    dsb
    bx      lr 

.global clean_invalidate_cache_by_range 
.type clean_invalidate_cache_by_range,%function
clean_invalidate_cache_by_range:
    dsb
    isb

    mov r2, #32   // hardcode the cache line size to 32
 
    /* r2 <- minimal cache line size in cache system */
    sub     r3, r2, #1
    bic     r0, r0, r3
 1: mcr     p15,0,r0,c7,c14,1
    add     r0, r0, r2
    cmp     r0, r1
    blt    1b

    isb
    dsb
    bx      lr 
