/**
 * @file mutex.c
 * @brief
 * This file contains the Mutex Assembly codes
 *
 *        Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

/*==========================================================================*/

.global mutex_init
.type mutex_init,%function
mutex_init:
    DMB

    MOV     r1, #0
    STR     r1, [r0]

    // Return non-zero to tell the ARM C libraries that we are running
    // multithreaded code.
    MOV     r0, #0

    DMB
    bx      lr

.global mutex_lock
.type mutex_lock,%function
mutex_lock:
    MOV     r1, #1
    //PRFM    PSTL1KEEP, [r0] //@TODO: find prefetch memory instruction
Lock:
    // We need to issue a cache invalidate by addr with the mutex variables address.
    // This is needed as there is no way for [no unified cache in R52/no CHI interconnect 
    // to notify the other cores about the update on their cached entry on this address].
    // We need uncached access for mutex acquiring across cores/clusters.
    // As we in shortage of MPU regions to program uncached memory we are trying to mimic 
    // an uncacned access by invalidating before loading it everytime. As the cache is write 
    // through by default[hw enforced] we dont have to worry update not going into the PoU/PoC.
#ifndef SAILEL2
    push { R14, R1, R0 }
    blx invalidate_dcache_by_addr_syscall
    pop  { R0, R1, R14 }
#else
    mcr p15,0,r0,c7,c6,1        // Invalidate the cache line with address r0.
#endif


    
    LDREX   r2, [r0]            // read lock with acquire
    //CBNZ    r2, Lock          // check if 0
    cmp     r2, #0
    bne     Lock
    STREX   r2, r1, [r0]        // attemp to store new value
    //CBNZ    r2, Lock          
    cmp     r2, #0
    bne     Lock                // test if store succeeded, if fail,
                                // retry until it scuceed
    DMB                         // Ensure other observers see lock claim.
    bx      lr

.global mutex_try_lock
.type mutex_try_lock,%function
mutex_try_lock:
    MOV     r1, r0 // Store RO to R1
    MOV     r0, #0 // Store 0 in R0
    MOV     r2, #1 // Store 1 in R2
    // We need to issue a cache invalidate by addr with the mutex variables address.
    // This is needed as there is no way for [no unified cache in R52/no CHI interconnect
    // to notify the other cores about the update on their cached entry on this address].
    // We need uncached access for mutex acquiring across cores/clusters.
    // As we in shortage of MPU regions to program uncached memory we are trying to mimic
    // an uncached access by invalidating before loading it everytime. As the cache is write
    // through by default[hw enforced] we dont have to worry update not going into the PoU/PoC.
    #ifndef SAILEL2
    push { R0, R1, R2, R14}
    mov R0, R1
    blx invalidate_dcache_by_addr_syscall
	pop  { R14, R2, R1, R0 }       
    #else
    mcr p15,0,r1,c7,c6,1        // Invalidate the cache line with address r0.
    #endif
    LDREX   r3, [r1]            // read lock with acquire
    cmp     r3, #0
    bne     exit
    STREX   r3, r2, [r1]        // Lock is open, attempt to lock , store new value
    cmp     r3, #0
    bne     exit                // Test if store succeeded, if it fails exit
    MOV     r0, #1 				// Store 1 in R0 to Signal Success
exit:
    DMB                         // Ensure other observers see lock claim.
    bx      lr



.global mutex_unlock
.type mutex_unlock,%function
mutex_unlock:
    DMB                         // Ensure other observers see lock claim.
    //STLR    WZR, [r0]           // clear the lock with release semantics
    MOV      r1, #0
    stl      r1, [r0]
    DMB                         // Ensure other observers see lock claim.
    bx      lr
