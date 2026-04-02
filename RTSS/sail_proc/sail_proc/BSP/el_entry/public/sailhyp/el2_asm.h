/**
 * @file el2_asm.h
 * @brief EL2 Hypervisor definitions
 * Header file for the definition of hypervisor register info used in sail
 *
 *        Copyright (c) 2021 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
*/


/*===========================================================================

                            EDIT HISTORY FOR FILE

when       who      what, where, why
--------   ---     ------------------------------------------------------------
06.02.21   rrahul       Created
=============================================================================*/

#ifndef EL2_ASM_H
#define EL2_ASM_H

/*===========================================================================
                           INCLUDE FILES
===========================================================================*/
#include "cache_ops.h"
#include "barrier.h"
#include "types.h"
#include "el2_types.h"

/*===========================================================================
                           DEFINITION OF EL2 Control registers AArch32
===========================================================================*/

/*===========================================================================
                            MACROS
===========================================================================*/

static inline HDFAR_EL2_t register_HDFAR_EL2_read( void) {
  register_t val = __arm_mrc(15,4,6,0,0);
  ISB;
  DSB;
  return HDFAR_EL2_cast(val);
}

static inline HIFAR_EL2_t register_HIFAR_EL2_read( void) {
  register_t val = __arm_mrc(15,4,6,0,2);
  ISB;
  DSB;
  return HIFAR_EL2_cast(val);
}

static inline SPSR_EL2_A32_t register_SPSR_HYP_EL2_read( void) {
  register_t val=0U;
  __asm__("mrs %0, spsr_hyp ;" : "=r"(val));
  return SPSR_EL2_cast(val);
}

static inline ESR_EL2_t register_ESR_EL2_read( void) {
	//MRC p15, 4, <Rt>, c5, c2, 0 ; Read HSR into Rt
    //MCR p15, 4, <Rt>, c5, c2, 0 ; Write Rt to HSR

  register_t val = __arm_mrc(15,4,5,2,0);
  ISB;
  DSB;
  return ESR_EL2_cast(val);
}

static inline ELR_EL2_t register_ELR_HYP_read(void) {
  register_t val;
  __asm__("mrs %0, elr_hyp	;" : "=r"(val));
  return ELR_EL2_cast(val);
}

static inline void register_ELR_HYP_write(const ELR_EL2_t val) {
  register_t raw = (register_t)ELR_EL2_raw(val);
  __asm__ volatile (" msr elr_hyp, %0":  :"r" (raw));
}

static inline ELR_EL2_t register_ELR_HYP_read_ordered(struct asm_ordering_dummy *ordering_var) {
  register_t val=0U;
  __asm__("mrs %0, elr_hyp	;" : "=r"(val),"+m"(*ordering_var) );
  return ELR_EL2_cast(val);
}

#endif  
