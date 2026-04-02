/**
 * @file r52_diagnostics.h
 * @brief Sail R52 diagnostics 
 * Header file for the definition of R52 diagnostics API
 *
 *        Copyright (c) 2021 -2022 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
*/


/*===========================================================================

                            EDIT HISTORY FOR FILE

when       who      what, where, why
--------   ---     ------------------------------------------------------------
08.04.22   pmdonthi       Created
=============================================================================*/

#ifndef R52_DIAGNOSTICS_H
#define R52_DIAGNOSTICS_H

/*===========================================================================
                           INCLUDE FILES
===========================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "types.h"
#include "arm_acle.h"
#include "target.h"
/*===========================================================================
                           MACROS
===========================================================================*/
/*
  1: Enable Enable memory-ECC on reset
*/
#define ECC_ENABLE_CHECK_BIT 0x1U

/*
  0 : Core to TOP comparator enable
  1:  Core to Governor comparator enable
  2:  Core to RAM comparator enable
  3:  Core-Governor to TOP comparator enable
  4:  Core-Governor to CORE comparator enable
  5:  Activity check on core signals comparator enable
  6:  Activity check on debug signals comparator enable
  28: Global-Governor to TOP comparator enable
  30: Global-Governor to CORE comparator enable
*/
#define COMPARATOR_ENABLE_BITS 0x5000007F

/*
  6: Enable memory-error profilers
*/
#define MEM_PROFILER_ENABLE_BIT 0x00000040

/* 
   4: core_0 memory-error aggregator fault-injection
   5: core_1 memory-error aggregator fault-injection
   6: core_2 memory-error aggregator fault-injection
   7: core_3 memory-error aggregator fault-injection
*/
#define MEM_PROFILER_FAULT_INJ_BITS 0xF0

/* 
   19: core_0 memory ECC warning
   20: core_1 memory ECC warning
   21: core_2 memory ECC warning
   22: core_3 memory ECC warning
*/
#define MEM_PROFILER_FAULT_DETECTION_BITS 0x00780000U

/*
  0 : Core to TOP comparator fault-injection
  1:  Core to Governor comparator fault-injection
  2:  Core to RAM comparator fault-injection
  3:  Core-Governor to TOP comparator fault-injection
  4:  Core-Governor to CORE comparator fault-injection
  28: Global-Governor to TOP comparator fault-injection
  30: Global-Governor to CORE comparator fault-injection
*/
#define COMPARATOR_FAULT_INJ_BITS 0x5000001F

/*
  0 : Core to TOP comparator. Primary clock comparator o/p
  1 : Core to TOP comparator. Secondary clock comparator o/p
  2:  Core to Governor comparator. Primary clock comparator o/p
  3:  Core to Governor comparator. Secondary clock comparator o/p
  4:  Core to RAM comparator. Primary clock comparator o/p
  5:  Core to RAM comparator. Secondary clock comparator o/p
  6:  Core-Governor to TOP comparator. Primary clock comparator o/p
  7:  Core-Governor to TOP comparator. Secondary clock comparator o/p
  8:  Core-Governor to CORE comparator. Primary clock comparator o/p
  9:  Core-Governor to CORE comparator. Secondary clock comparator o/p
  28: Global-Governor to TOP comparator. Primary clock comparator o/p
  29: Global-Governor to TOP comparator. Secondary clock comparator o/p
  30: Global-Governor to CORE comparator. Primary clock comparator o/p
  31: Global-Governor to CORE comparator. Secondary clock comparator o/p
*/
#define COMPARATOR_FAULT_DETECTION_BITS 0xF00003FFU

/*
   28: Bus protection bit
   29: Bus protection bit
*/
#define BUS_PROTECTION_CHECK 0x30000000U

/*
   2: Bus protection enabled value
*/
#define BUS_PROTECTION_ENABLED 0x10000000U

/*
   8: Self hosted debugger disable bit
*/
#define TDE_BIT_CHECK 0x100U

/*
  31: Cluster-0 comparators FUSA error clear (SAILSS_CSR_FUSA_ERROR_STATUS_2)
*/
#define COMPARATOR_CLUSTER_0_FUSA_CLEAR_BITS 0x80000000U

/*
  0: Cluster-1 comparators FUSA error clear (SAILSS_CSR_FUSA_ERROR_STATUS_3)
*/
#define COMPARATOR_CLUSTER_1_FUSA_CLEAR_BITS 0x1U

/*===========================================================================
                           TYPES and TYPEDEFS
===========================================================================*/
typedef enum
{
    COMP_ERRINJ_PASS = 0,
    COMP_ERRINJ_FAIL =1
}ComparatorTestStats_e;

typedef enum
{
    MEM_ERRAGGR_PASS= 0,
    MEM_ERRAGGR_FAIL =2
}MemErrAggrTestStats_e;
/*===========================================================================
                           EXTERNS
===========================================================================*/

/*
 *===========================================================================
                          FUNCTIONS
 *===========================================================================*/

/*===========================================================================
**  Function :  r52_diagnostics
** ==========================================================================
*/
/*!
*
* @brief
*   Performs R52 diagnostics
*
* @param
*   None
* 
* @par Dependencies
*   None
* 
* @retval
*   Status of the operation
* 
* @par Side Effects
*   None
*
*/
int r52_diagnostics(void);


/*===========================================================================
**  Function :  ecc_enable_check
** ==========================================================================
*/
/*!
*
* @brief
*   Checks if the ECC is enabled for the TCM memories
*
* @param
*   None
* 
* @par Dependencies
*   None
* 
* @retval
*   Status of the operation
* 
* @par Side Effects
*   None
*
*/
int ecc_enable_check(void);


/*===========================================================================
**  Function :  bus_protection_check
** ==========================================================================
*/
/*!
*
* @brief
*   Checks if the Bus interface is protected from R52 to its slaves
*
* @param
*   None
* 
* @par Dependencies
*   None
* 
* @retval
*   Status of the operation
* 
* @par Side Effects
*   None
*
*/
int bus_protection_check(void);

/*===========================================================================
**  Function :  self_hosted_debugger_disablement
** ==========================================================================
*/
/*!
*
* @brief
*   Writes to the TDE bit in the HDCR register to disable the self hosted debugger
*
* @param
*   None
*
* @par Dependencies
*   None
*
* @retval
*   Status of the operation
*
* @par Side Effects
*   None
*
*/
int selfhosted_dbgr_disablement(void);

#endif  