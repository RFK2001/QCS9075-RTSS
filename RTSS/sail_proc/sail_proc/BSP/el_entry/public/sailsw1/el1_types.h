/**
 * @file EL1_types.h
 * @brief Types definitions specfic to EL1
 * Header file for the definition of EL1 register info used in sail
 *
 *        Copyright (c) 2022 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
*/
#ifndef EL1_TYPES_H
#define EL1_TYPES_H

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

/*===========================================================================
                            TYPEDEFS
===========================================================================*/
typedef struct DFAR_EL1 {
  uint32_t bf[1];
} DFAR_EL1_t;

#define DFAR_EL1_default()                                                      \
  (DFAR_EL1_t) {                                                                \
    .bf = { 0 }                                                                \
  }

#define DFAR_EL1_cast(val_0)                                                    \
  (DFAR_EL1_t) {                                                                \
    .bf = { val_0 }                                                            \
  }

static inline uint32_t DFAR_EL1_raw(DFAR_EL1_t bit_field) {
  return bit_field.bf[0];
}

typedef struct IFAR_EL1 {
  uint32_t bf[1];
} IFAR_EL1_t;

#define IFAR_EL1_default()                                                      \
  (IFAR_EL1_t) {                                                                \
    .bf = { 0 }                                                                \
  }

#define IFAR_EL1_cast(val_0)                                                    \
  (IFAR_EL1_t) {                                                                \
    .bf = { val_0 }                                                            \
  }

static inline uint32_t IFAR_EL1_raw(IFAR_EL1_t bit_field) {
  return bit_field.bf[0];
}

typedef struct IFSR_EL1 {
  uint32_t bf[1];
} IFSR_EL1_t;

#define IFSR_EL1_default()                                                      \
  (IFSR_EL1_t) {                                                                \
    .bf = { 0 }                                                                \
  }

#define IFSR_EL1_cast(val_0)                                                    \
  (IFSR_EL1_t) {                                                                \
    .bf = { val_0 }                                                            \
  }

static inline uint32_t IFSR_EL1_raw(IFSR_EL1_t bit_field) {
  return bit_field.bf[0];
}


typedef struct DFSR_EL1 {
  uint32_t bf[1];
} DFSR_EL1_t;

#define DFSR_EL1_default()                                                      \
  (DFSR_EL1_t) {                                                                \
    .bf = { 0 }                                                                \
  }

#define DFSR_EL1_cast(val_0)                                                    \
  (DFSR_EL1_t) {                                                                \
    .bf = { val_0 }                                                            \
  }

static inline uint32_t DFSR_EL1_raw(DFSR_EL1_t bit_field) {
  return bit_field.bf[0];
}

typedef struct SPSR_EL1_A32 {
  uint32_t bf[1];
} SPSR_EL1_A32_t;

#define SPSR_EL1_cast(val_0)                                                   \
  (SPSR_EL1_A32_t) {                                                           \
    .bf = { val_0 }                                                            \
}

static inline uint32_t SPSR_EL1_raw(SPSR_EL1_A32_t bit_field) {
  return bit_field.bf[0];
}
#endif //EL1_TYPES_H
