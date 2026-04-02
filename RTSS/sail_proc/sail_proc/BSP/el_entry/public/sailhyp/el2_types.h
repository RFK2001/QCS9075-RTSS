/**
 * @file el2_types.h
 * @brief Types definitions specfic to EL2
 * Header file for the definition of hypervisor register info used in sail
 *
 *        Copyright (c) 2022 Qualcomm Technologies, Inc.
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

#ifndef EL2_TYPES_H
#define EL2_TYPES_H

/*===========================================================================
                           INCLUDE FILES
===========================================================================*/
#include "types.h"

/*===========================================================================
                           DEFINES
===========================================================================*/

/*===========================================================================
                            MACROS
===========================================================================*/
#define MAX_CPU_CTX_REG 15U
/*===========================================================================
                            TYPEDEFS
===========================================================================*/
typedef struct asm_ordering_dummy {
	char dummy;
}asm_ordering_dummy_t;

typedef struct SPSR_EL2_A32 {
  uint32_t bf[1];
} SPSR_EL2_A32_t;

#define SPSR_EL2_cast(val_0)                                                    \
  (SPSR_EL2_A32_t) {                                                            \
    .bf = { val_0 }                                                             \
}

static inline uint32_t SPSR_EL2_raw(SPSR_EL2_A32_t bit_field) {
  return bit_field.bf[0];
}



typedef struct ELR_EL2 {
  uint32_t bf[1];
} ELR_EL2_t;

#define ELR_EL2_default()                                                      \
  (ELR_EL2_t) {                                                                \
    .bf = { 0 }                                                                \
  }

#define ELR_EL2_cast(val_0)                                                    \
  (ELR_EL2_t) {                                                                \
    .bf = { val_0 }                                                            \
  }

static inline uint32_t ELR_EL2_raw(ELR_EL2_t bit_field) {
  return bit_field.bf[0];
}

static inline _Atomic uint32_t *ELR_EL2_atomic_ptr_raw(_Atomic ELR_EL2_t *ptr) {
  return (_Atomic uint32_t *)&((ELR_EL2_t *)ptr)->bf[0];
}

static inline void ELR_EL2_init(ELR_EL2_t *bit_field) {
  *bit_field = ELR_EL2_default();
}

static inline bool ELR_EL2_is_equal(ELR_EL2_t b1, ELR_EL2_t b2) {
  return ((b1.bf[0] & 0xffffffffU) == (b2.bf[0] & 0xffffffffU));
}

static inline void ELR_EL2_set_ReturnAddress(ELR_EL2_t *bit_field,
                                             uint32_t val) {
  uint32_t *bf = (uint32_t *)bit_field;
  uint32_t tmp = 0;

  tmp = bf[0];
  tmp &= (uint32_t)0x0U;
  tmp |= ((((uint32_t)val) >> 0) & (uint32_t)0xffffffffU) << 0;
  bf[0] = tmp;
}

static inline uint32_t ELR_EL2_get_ReturnAddress(const ELR_EL2_t *bit_field) {
  uint32_t val = 0;
  uint32_t tmp;
  const uint32_t *bf = (const uint32_t *)&bit_field->bf[0];

  tmp = bf[0];
  val |= ((tmp >> 0) & (uint32_t)0xffffffff) << 0;
  return (uint32_t)val;
}

typedef enum esr_ec {
	ESR_EC_UNKNOWN		= 0,
	ESR_EC_WFIWFE		= 1,
	ESR_EC_MCRMRC15		= 3,
	ESR_EC_MCRRMRCC15	= 4,
	ESR_EC_MCRMRC14		= 5,
	ESR_EC_LDCSTC		= 6,
	ESR_EC_FPEN 		= 7,
	ESR_EC_VMRS_EL2 	= 8,
	ESR_EC_MRRC14 		= 12,
	ESR_EC_ILLEGAL 		= 14,
	ESR_EC_SVC32 		= 17,
	ESR_EC_HVC32_EL2 	= 18,
	ESR_EC_SMC32_EL2 	= 19,
	ESR_EC_INST_ABT_LO 	= 32,
	ESR_EC_INST_ABT 	= 33,
	ESR_EC_PC_ALIGN 	= 34,
	ESR_EC_DATA_ABT_LO 	= 36,
	ESR_EC_DATA_ABT 	= 37,
}esr_ec_t;

#define ESR_EC__MAX (esr_ec_t)(37U)
#define ESR_EC__MIN (esr_ec_t)(0U)

typedef struct ESR_EL2{
	uint32_t bf[1];
} ESR_EL2_t;

#define ESR_EL2_default()                           \
		(ESR_EL2_t) {                               \
	       .bf = {0}                                \
         }                                          \


#define ESR_EL2_cast(val_0)                                                    \
  (ESR_EL2_t) {                                                                \
    .bf = { val_0 }                                                            \
}
  
static inline uint32_t ESR_EL2_raw(ESR_EL2_t bit_field) {
	return bit_field.bf[0];
}

static inline  atomic_uint *ESR_EL2_atomic_ptr_raw(_Atomic ESR_EL2_t *ptr) {
  return ( atomic_uint *)&((ESR_EL2_t *)ptr)->bf[0];
}

static inline void ESR_EL2_init(ESR_EL2_t *bit_field) {
  *bit_field = ESR_EL2_default();
}

static inline bool ESR_EL2_is_equal(ESR_EL2_t b1, ESR_EL2_t b2) {
  return ((b1.bf[0] & 0xffffffffU) == (b2.bf[0] & 0xffffffffU));
}


static inline void ESR_EL2_set_ISS(ESR_EL2_t *bit_field, uint32_t val) {
  uint32_t *bf = (uint32_t *)bit_field;
  uint32_t tmp = 0;

  tmp = bf[0];
  tmp &= (uint32_t)0xfe000000U;
  tmp |= ((((uint32_t)val) >> 0) & (uint32_t)0x1ffffffU) << 0;
  bf[0] = tmp;
}

static inline uint32_t ESR_EL2_get_ISS(const ESR_EL2_t *bit_field) {
  uint32_t val = 0;
  uint32_t tmp;
  const uint32_t *bf = (const uint32_t *)&bit_field->bf[0];

  tmp = bf[0];
  val |= ((tmp >> 0) & (uint32_t)0x1ffffff) << 0;
  return (uint32_t)val;
}

static inline void ESR_EL2_set_IL(ESR_EL2_t *bit_field, bool val) {
  uint32_t *bf = (uint32_t *)bit_field;
  uint32_t tmp = 0;

  tmp = bf[0];
  tmp &= (uint32_t)0xfdffffffU;
  tmp |= ((((uint32_t)val) >> 0) & (uint32_t)0x1U) << 25;
  bf[0] = tmp;
}

static inline bool ESR_EL2_get_IL(const ESR_EL2_t *bit_field) {
  uint32_t val = 0;
  uint32_t tmp;
  const uint32_t *bf = (const uint32_t *)&bit_field->bf[0];

  tmp = bf[0];
  val |= ((tmp >> 25) & (uint32_t)0x1) << 0;
  return (bool)val;
}

static inline void ESR_EL2_set_EC(ESR_EL2_t *bit_field, esr_ec_t val) {
  uint32_t *bf = (uint32_t *)bit_field;
  uint32_t tmp = 0;

  tmp = bf[0];
  tmp &= (uint32_t)0x03ffffffU;
  tmp |= ((((uint32_t)val) >> 0) & (uint32_t)0x3fU) << 26;
  bf[0] = tmp;
}

static inline esr_ec_t ESR_EL2_get_EC(const ESR_EL2_t *bit_field) {
  uint32_t val = 0;
  uint32_t tmp;
  const uint32_t *bf = (const uint32_t *)&bit_field->bf[0];

  tmp = bf[0];
  val |= ((tmp >> 26) & (uint32_t)0x3f) << 0;
  return (esr_ec_t)val;
}

typedef struct ESR_EL2_ISS_MCR_MRC {
  uint32_t bf[1];
} ESR_EL2_ISS_MCR_MRC_t;

#define ESR_EL2_ISS_MCR_MRC_default()                                          \
  (ESR_EL2_ISS_MCR_MRC_t) {                                                    \
    .bf = { 0 }                                                                \
  }

#define ESR_EL2_ISS_MCR_MRC_cast(val_0)                                        \
  (ESR_EL2_ISS_MCR_MRC_t) {                                                    \
    .bf = { val_0 }                                                            \
  }

static inline uint32_t
ESR_EL2_ISS_MCR_MRC_raw(ESR_EL2_ISS_MCR_MRC_t bit_field) {
  return bit_field.bf[0];
}

static inline _Atomic uint32_t *
ESR_EL2_ISS_MCR_MRC_atomic_ptr_raw(_Atomic ESR_EL2_ISS_MCR_MRC_t *ptr) {
  return (_Atomic uint32_t *)&((ESR_EL2_ISS_MCR_MRC_t *)ptr)->bf[0];
}

static inline void ESR_EL2_ISS_MCR_MRC_init(ESR_EL2_ISS_MCR_MRC_t *bit_field) {
  *bit_field = ESR_EL2_ISS_MCR_MRC_default();
}

static inline bool ESR_EL2_ISS_MCR_MRC_is_equal(ESR_EL2_ISS_MCR_MRC_t b1,
                                                ESR_EL2_ISS_MCR_MRC_t b2) {
  return ((b1.bf[0] & 0x1ffffffU) == (b2.bf[0] & 0x1ffffffU));
}


static inline void
ESR_EL2_ISS_MCR_MRC_set_Direction(ESR_EL2_ISS_MCR_MRC_t *bit_field, bool val) {
  uint32_t *bf = (uint32_t *)bit_field;
  uint32_t tmp = 0;

  tmp = bf[0];
  tmp &= (uint32_t)0xfffffffeU;
  tmp |= ((((uint32_t)val) >> 0) & (uint32_t)0x1U) << 0;
  bf[0] = tmp;
}

static inline bool
ESR_EL2_ISS_MCR_MRC_get_Direction(const ESR_EL2_ISS_MCR_MRC_t *bit_field) {
  uint32_t val = 0;
  uint32_t tmp;
  const uint32_t *bf = (const uint32_t *)&bit_field->bf[0];

  tmp = bf[0];
  val |= ((tmp >> 0) & (uint32_t)0x1) << 0;
  return (bool)val;
}

static inline void ESR_EL2_ISS_MCR_MRC_set_CRm(ESR_EL2_ISS_MCR_MRC_t *bit_field,
                                               uint8_t val) {
  uint32_t *bf = (uint32_t *)bit_field;
  uint32_t tmp = 0;

  tmp = bf[0];
  tmp &= (uint32_t)0xffffffe1U;
  tmp |= ((((uint32_t)val) >> 0) & (uint32_t)0xfU) << 1;
  bf[0] = tmp;
}

static inline uint8_t
ESR_EL2_ISS_MCR_MRC_get_CRm(const ESR_EL2_ISS_MCR_MRC_t *bit_field) {
  uint32_t val = 0;
  uint32_t tmp;
  const uint32_t *bf = (const uint32_t *)&bit_field->bf[0];

  tmp = bf[0];
  val |= ((tmp >> 1) & (uint32_t)0xf) << 0;
  return (uint8_t)val;
}

static inline void ESR_EL2_ISS_MCR_MRC_set_Rt(ESR_EL2_ISS_MCR_MRC_t *bit_field,
                                              uint8_t val) {
  uint32_t *bf = (uint32_t *)bit_field;
  uint32_t tmp = 0;

  tmp = bf[0];
  tmp &= (uint32_t)0xfffffc1fU;
  tmp |= ((((uint32_t)val) >> 0) & (uint32_t)0x1fU) << 5;
  bf[0] = tmp;
}

static inline uint8_t
ESR_EL2_ISS_MCR_MRC_get_Rt(const ESR_EL2_ISS_MCR_MRC_t *bit_field) {
  uint32_t val = 0;
  uint32_t tmp;
  const uint32_t *bf = (const uint32_t *)&bit_field->bf[0];

  tmp = bf[0];
  val |= ((tmp >> 5) & (uint32_t)0x1f) << 0;
  return (uint8_t)val;
}

static inline void ESR_EL2_ISS_MCR_MRC_set_CRn(ESR_EL2_ISS_MCR_MRC_t *bit_field,
                                               uint8_t val) {
  uint32_t *bf = (uint32_t *)bit_field;
  uint32_t tmp = 0;

  tmp = bf[0];
  tmp &= (uint32_t)0xffffc3ffU;
  tmp |= ((((uint32_t)val) >> 0) & (uint32_t)0xfU) << 10;
  bf[0] = tmp;
}

static inline uint8_t
ESR_EL2_ISS_MCR_MRC_get_CRn(const ESR_EL2_ISS_MCR_MRC_t *bit_field) {
  uint32_t val = 0;
  uint32_t tmp;
  const uint32_t *bf = (const uint32_t *)&bit_field->bf[0];

  tmp = bf[0];
  val |= ((tmp >> 10) & (uint32_t)0xf) << 0;
  return (uint8_t)val;
}

static inline void
ESR_EL2_ISS_MCR_MRC_set_Opc1(ESR_EL2_ISS_MCR_MRC_t *bit_field, uint8_t val) {
  uint32_t *bf = (uint32_t *)bit_field;
  uint32_t tmp = 0;

  tmp = bf[0];
  tmp &= (uint32_t)0xfffe3fffU;
  tmp |= ((((uint32_t)val) >> 0) & (uint32_t)0x7U) << 14;
  bf[0] = tmp;
}

static inline uint8_t
ESR_EL2_ISS_MCR_MRC_get_Opc1(const ESR_EL2_ISS_MCR_MRC_t *bit_field) {
  uint32_t val = 0;
  uint32_t tmp;
  const uint32_t *bf = (const uint32_t *)&bit_field->bf[0];

  tmp = bf[0];
  val |= ((tmp >> 14) & (uint32_t)0x7) << 0;
  return (uint8_t)val;
}

static inline void
ESR_EL2_ISS_MCR_MRC_set_Opc2(ESR_EL2_ISS_MCR_MRC_t *bit_field, uint8_t val) {
  uint32_t *bf = (uint32_t *)bit_field;
  uint32_t tmp = 0;

  tmp = bf[0];
  tmp &= (uint32_t)0xfff1ffffU;
  tmp |= ((((uint32_t)val) >> 0) & (uint32_t)0x7U) << 17;
  bf[0] = tmp;
}

static inline uint8_t
ESR_EL2_ISS_MCR_MRC_get_Opc2(const ESR_EL2_ISS_MCR_MRC_t *bit_field) {
  uint32_t val = 0;
  uint32_t tmp;
  const uint32_t *bf = (const uint32_t *)&bit_field->bf[0];

  tmp = bf[0];
  val |= ((tmp >> 17) & (uint32_t)0x7) << 0;
  return (uint8_t)val;
}

static inline void
ESR_EL2_ISS_MCR_MRC_set_COND(ESR_EL2_ISS_MCR_MRC_t *bit_field, uint8_t val) {
  uint32_t *bf = (uint32_t *)bit_field;
  uint32_t tmp = 0;

  tmp = bf[0];
  tmp &= (uint32_t)0xff0fffffU;
  tmp |= ((((uint32_t)val) >> 0) & (uint32_t)0xfU) << 20;
  bf[0] = tmp;
}

static inline uint8_t
ESR_EL2_ISS_MCR_MRC_get_COND(const ESR_EL2_ISS_MCR_MRC_t *bit_field) {
  uint32_t val = 0;
  uint32_t tmp;
  const uint32_t *bf = (const uint32_t *)&bit_field->bf[0];

  tmp = bf[0];
  val |= ((tmp >> 20) & (uint32_t)0xf) << 0;
  return (uint8_t)val;
}

static inline void ESR_EL2_ISS_MCR_MRC_set_CV(ESR_EL2_ISS_MCR_MRC_t *bit_field,
                                              bool val) {
  uint32_t *bf = (uint32_t *)bit_field;
  uint32_t tmp = 0;

  tmp = bf[0];
  tmp &= (uint32_t)0xfeffffffU;
  tmp |= ((((uint32_t)val) >> 0) & (uint32_t)0x1U) << 24;
  bf[0] = tmp;
}

static inline bool
ESR_EL2_ISS_MCR_MRC_get_CV(const ESR_EL2_ISS_MCR_MRC_t *bit_field) {
  uint32_t val = 0;
  uint32_t tmp;
  const uint32_t *bf = (const uint32_t *)&bit_field->bf[0];

  tmp = bf[0];
  val |= ((tmp >> 24) & (uint32_t)0x1) << 0;
  return (bool)val;
}

typedef struct HIFAR_EL2 {
  uint32_t bf[1];
} HIFAR_EL2_t;

#define HIFAR_EL2_default()                                                      \
  (HIFAR_EL2_t) {                                                                \
    .bf = { 0 }                                                                \
  }

#define HIFAR_EL2_cast(val_0)                                                    \
  (HIFAR_EL2_t) {                                                                \
    .bf = { val_0 }                                                            \
  }

static inline uint32_t HIFAR_EL2_raw(HIFAR_EL2_t bit_field) {
  return bit_field.bf[0];
}

static inline _Atomic uint32_t *HIFAR_EL2_atomic_ptr_raw(_Atomic HIFAR_EL2_t *ptr) {
  return (_Atomic uint32_t *)&((HIFAR_EL2_t *)ptr)->bf[0];
}

static inline void HIFAR_EL2_init(HIFAR_EL2_t *bit_field) {
  *bit_field = HIFAR_EL2_default();
}

static inline bool HIFAR_EL2_is_equal(HIFAR_EL2_t b1, HIFAR_EL2_t b2) {
  return ((b1.bf[0] & 0xffffffffU) == (b2.bf[0] & 0xffffffffU));
}

typedef struct HDFAR_EL2 {
  uint32_t bf[1];
} HDFAR_EL2_t;

#define HDFAR_EL2_default()                                                      \
  (HDFAR_EL2_t) {                                                                \
    .bf = { 0 }                                                                \
  }

#define HDFAR_EL2_cast(val_0)                                                    \
  (HDFAR_EL2_t) {                                                                \
    .bf = { val_0 }                                                            \
  }

static inline uint32_t HDFAR_EL2_raw(HDFAR_EL2_t bit_field) {
  return bit_field.bf[0];
}

static inline _Atomic uint32_t *HDFAR_EL2_atomic_ptr_raw(_Atomic HDFAR_EL2_t *ptr) {
  return (_Atomic uint32_t *)&((HDFAR_EL2_t *)ptr)->bf[0];
}

static inline void HDFAR_EL2_init(HDFAR_EL2_t *bit_field) {
  *bit_field = HDFAR_EL2_default();
}

static inline bool HDFAR_EL2_is_equal(HDFAR_EL2_t b1, HDFAR_EL2_t b2) {
  return ((b1.bf[0] & 0xffffffffU) == (b2.bf[0] & 0xffffffffU));
}


typedef struct FPCR {
  uint32_t bf[1];
} FPCR_t;


typedef struct HPFAR_EL2 {
  uint32_t bf[1];
} HPFAR_EL2_t;

#define HPFAR_EL2_default()                                                    \
  (HPFAR_EL2_t) {                                                              \
    .bf = { 0 }                                                                \
  }

#define HPFAR_EL2_cast(val_0)                                                  \
  (HPFAR_EL2_t) {                                                              \
    .bf = { val_0 }                                                            \
  }
static inline void HPFAR_EL2_set_FIPA(HPFAR_EL2_t *bit_field, uint32_t val) {
  uint32_t *bf = (uint32_t *)bit_field;
  uint32_t tmp = 0;

  tmp = bf[0];
  tmp &= (uint32_t)0xfffff0000000000fU;
  tmp |= ((((uint32_t)val) >> 12) & (uint32_t)0xffffffffffU) << 4;
  bf[0] = tmp;
}

static inline uint32_t HPFAR_EL2_get_FIPA(const HPFAR_EL2_t *bit_field) {
  uint32_t val = 0;
  uint32_t tmp;
  const uint32_t *bf = (const uint32_t *)&bit_field->bf[0];

  tmp = bf[0];
  val |= ((tmp >> 4) & (uint32_t)0xffffffffff) << 12;
  return (uint32_t)val;
}

typedef enum trap_result {
  TRAP_RESULT_UNHANDLED = 0,
  TRAP_RESULT_EMULATED = 1,
  TRAP_RESULT_RETRY = 2,
  TRAP_RESULT_FAULT = 3
} trap_result_t;


typedef struct vcpu_general_registers {
  register_t x[MAX_CPU_CTX_REG];
  ELR_EL2_t pc;
  SPSR_EL2_A32_t spsr_el2;
} vcpu_general_registers_t;

#endif //EL2_TYPES_H
