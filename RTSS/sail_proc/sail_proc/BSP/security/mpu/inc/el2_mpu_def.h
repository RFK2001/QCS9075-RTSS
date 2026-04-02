/*
 * el2_mpu_def.h
 *
 * Copyright (c) Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 *  Created on: Jan 26, 2022
 *  Author: shaygold
  
                      EDIT HISTORY FOR FILE

  This section contains comments describing changes made to the module.
  Notice that changes are listed in reverse chronological order.

   when        who         what, where, why
   --------    -----       -----------------------------------------------------
   26/10/21    shaygold    Initial version
 */

#ifndef EL2_MPU_DEF_H_
#define EL2_MPU_DEF_H_

//#define TEST_MPU_ENABLED //comment out before submitting

#define EL2_MPU_MINALIGN        64U

#define isb(option) __asm__ __volatile__ ("isb " #option : : : "memory")
#define dsb(option) __asm__ __volatile__ ("dsb " #option : : : "memory")

#define xstr(s...) xxstr(s)
#define xxstr(s...) #s

#define MPU_ACCESS_CP15(CRn, Op1, CRm, Op2)			\
	"mrc", "mcr", xstr(p15, Op1, %0, CRn, CRm, Op2), u32

#define MPU_read_sysreg(r, w, c, t) ({				\
			t mpu__val;				\
			__asm__ volatile(r " " c : "=r" (mpu__val));	\
			mpu__val;					\
		})
#define read_sysreg(...)                 MPU_read_sysreg(__VA_ARGS__)

#define MPU_write_sysreg(v, r, w, c, t)   __asm__ volatile(w " " c : : "r" ((t)(v)))
#define write_sysreg(v, ...)            MPU_write_sysreg(v, __VA_ARGS__)

#define HCR       MPU_ACCESS_CP15(c1, 4, c1, 0)
#define HMPUIR    MPU_ACCESS_CP15(c0, 4, c0, 4)
#define HPRENR    MPU_ACCESS_CP15(c6, 4, c1, 1)
#define HPRSEL    MPU_ACCESS_CP15(c6, 4, c2, 1)
#define HPRBAR    MPU_ACCESS_CP15(c6, 4, c3, 0)
#define HPRLAR    MPU_ACCESS_CP15(c6, 4, c3, 1)
#define HSCTLR    MPU_ACCESS_CP15(c1, 4, c0, 0)
#define HMAIR0    MPU_ACCESS_CP15(c10, 4, c2, 0)
#define HMAIR1    MPU_ACCESS_CP15(c10, 4, c2, 1)
#define MPIDR     MPU_ACCESS_CP15(c0, 0, c0, 5)
#define IMP_CBAR  MPU_ACCESS_CP15(c15, 1, c3, 0)

#define HMAIR0_VAL                   (MPU_HMAIR_ATTR0 | MPU_HMAIR_ATTR1 | \
                                      MPU_HMAIR_ATTR2 | MPU_HMAIR_ATTR3 )
#define HMAIR1_VAL                   (MPU_HMAIR_ATTR4 | MPU_HMAIR_ATTR5 | \
                                      MPU_HMAIR_ATTR6 | MPU_HMAIR_ATTR7 )

#define HPRBAR_NX_OFFSET 0
#define HPRBAR_AP_OFFSET 1
#define HPRBAR_SH_OFFSET 3
#define HPLAR_ATT_OFFSET 1

#define HSCTLR_M_BIT      0x1U
#define HSCTLR_BR_BIT     0x20000U 
#define HSCTLR_WNX_BIT    0x80000U

#endif /* EL2_MPU_DEF_H_ */
