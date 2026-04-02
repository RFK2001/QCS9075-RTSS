/**
 * @file EL1_asm.h
 * @brief EL1 Hypervisor definitions
 * Header file for the definition of EL1 register info used in sail
 *
 *        Copyright (c) 2021 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
*/
#ifndef EL1_ASM_H
#define EL1_ASM_H

/*===========================================================================
                           INCLUDE FILES
===========================================================================*/
#include "cache_ops.h"
#include "barrier.h"
#include "types.h"
#include "el1_types.h"

/*===========================================================================
                           DEFINITION OF EL1 Control registers AArch32
===========================================================================*/

/*===========================================================================
                            MACROS
===========================================================================*/

static inline DFAR_EL1_t register_DFAR_EL1_read( void) {
    // Data Fault Address Register
    register_t val = __arm_mrc(15,0,6,0,0);
    ISB;
    DSB;
    return DFAR_EL1_cast(val);
}

static inline IFAR_EL1_t register_IFAR_EL1_read(void) {
    // Instruction Fault Address Register
    register_t val = __arm_mrc(15,0,6,0,2);
    ISB;
    DSB;
    return IFAR_EL1_cast(val);
}


static inline IFSR_EL1_t register_IFSR_EL1_read( void) {
    // Instruction Fault Status Register
    register_t val = __arm_mrc(15,0,5,0,1);
    ISB;
    DSB;
    return IFSR_EL1_cast(val);
}

static inline DFSR_EL1_t register_DFSR_EL1_read( void) {
    // Data Fault Status Register
    register_t val = __arm_mrc(15,0,5,0,0);
    ISB;
    DSB;
    return DFSR_EL1_cast(val);
}

static inline SPSR_EL1_A32_t register_SPSR_SVC_EL1_read( void) {
    register_t val;
    __asm__("mrs %0, SPSR_SVC ;" : "=r"(val));
    return SPSR_EL1_cast(val);
}
#endif  
