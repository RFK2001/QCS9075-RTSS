/*
 * @file  syscall_pub.h
 * @brief Sail syscall definitions
 * Header file for the definition of Sail HVC calls
 *
 *        Copyright (c) Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 *
 */

#ifndef _SAILHYP_SYSCALL_PUB_H_
#define _SAILHYP_SYSCALL_PUB_H_

/*===========================================================================
                           INCLUDE FILES
===========================================================================*/
#include<stdio.h>
#include<stdlib.h>
#include "types.h"


/*----------------------------------------------------------------------------
 * Reference
 * -------------------------------------------------------------------------*/

/*   ARMV8 HVC/HVC ID bit layout
 ___________________________________________________
|    |     |        |          |          |         |
| 31 |  30 |29----24|23------16|15-------8|7-------0|
|IRQ |AARCH|  Owner | Reserved |Service ID|  Func # |
|____|_____|________|__________|__________|_________|
                               \_________  _________/
                                         \/
                                     Command ID
*/

/*   Parameter ID bit layout
 ___________________________________________________________________________
|          |     |     |     |     |     |     |     |    |    |    |       |
|31------24|23-22|21-20|19-18|17-16|15-14|13-12|11-10|9--8|7--6|5--4|3-----0|
| Reserved | p10 | p9  | p8  | p7  | p6  | p5  | p4  | p3 | p2 | p1 | nargs |
|          |type |type |type |type |type |type |type |type|type|type|       |
|__________|_____|_____|_____|_____|_____|_____|_____|____|____|____|_______|

*/


/*===========================================================================
                           TYPES and TYPEDEFS
===========================================================================*/

#define SYSCALL_FUNC __attribute__( ( section ( "syscall_func" ) ) )

/** General helper macro to create a bitmask from bits low to high. */
#define SAIL_MASK_BITS(h,l)     ((0xffffffffu >> (32u - ((h - l) + 1u))) << l)

/** Helper macro to extract the IRQ settings from the HVC ID. */
#define SAIL_SYSCALL_IRQ(r0)        ((r0 & SAIL_MASK_BITS(31u,31u)) >> 31u)
/** Helper macro to extract the AArch used from the HVC ID. */
#define SAIL_SYSCALL_AARCH(r0)      ((r0 & SAIL_MASK_BITS(30u,30u)) >> 30u)
/** Helper macro to extract the owning entity from the HVC ID. */
#define SAIL_SYSCALL_OWNER_ID(r0)   ((r0 & SAIL_MASK_BITS(29u,24u)) >> 24u)
/** Helper macro to extract the reserved bits from the HVC ID. */
#define SAIL_SYSCALL_RESERVED(r0)   ((r0 & SAIL_MASK_BITS(23u,16u)) >> 16u)
/** Helper macro to extract the function ID from the HVC ID. */
#define SAIL_SYSCALL_FUNC_ID(r0)    (r0 & SAIL_MASK_BITS(15u,0u))
/** Helper macro to extract the application ID from the HVC ID. */
#define SAIL_SYSCALL_APP_ID(r0)     ((r0 & SAIL_MASK_BITS(15u,8u)) >> 8u)
/** Helper macro to extract the service ID from the function ID in the HVC ID. */
#define SAIL_SYSCALL_SVC_ID(r0)     ((r0 & SAIL_MASK_BITS(15u,8u)) >> 8u)

/** Helper macro to extract the number of arguments from the parameter ID. */
#define SAIL_SYSCALL_NUM_ARGS(r1)   (r1 & SAIL_MASK_BITS(3u,0u))
/** Helper macro to extract an argument type from the parameter ID; maximum 10 arguments. */
#define SAIL_SYSCALL_ARG_TYPE(r1, n) \
  ((n<10u)?((r1 & SAIL_MASK_BITS(((n*2u)+5u),((n*2u)+4u))) >> ((n * 2u) + 4u)):0xFFFFFFFFu)

/**
   Macro used to define a generic SMCC ID based on the owner ID,
   service ID, and function number.
*/
#define SAIL_SYSCALL_CREATE_SMCC_ID(o, s, f) \
  ((uint32)((((((uint32))o & 0x3fu) << 24u ) | ( ((uint32)s) & 0xffu) << 8u) | ( ((uint32)f) & 0xffu)))

/**
   Macro used to define an HVC ID based on the owner ID,
   service ID, and function number.
*/
#define SAIL_SYSCALL_CREATE_HVC_ID( s, f) \
  ((uint32)((((SAIL_OWNER_HVC & 0x3fu) << 24u ) | (((uint32)s) & 0xffu) << 8u) | ( ((uint32)f) & 0xffu)))

/** Parameter ID nargs bitmask. */
#define SAIL_SYSCALL_PARAM_NARGS_MASK  SAIL_MASK_BITS(3u,0u)
/** Parameter ID paramameter type bitmask. */
#define SAIL_SYSCALL_PARAM_TYPE_MASK   SAIL_MASK_BITS(1u,0u)

/** Internal helper macro for __SAIL_SYSCALL_CREATE_PARAM_ID. */
#define _SAIL_SYSCALL_CREATE_PARAM_ID(nargs, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, ...) \
  (((nargs)&SAIL_SYSCALL_PARAM_NARGS_MASK)+ \
  (((p1)&SAIL_SYSCALL_PARAM_TYPE_MASK)<<4u)+ \
  (((p2)&SAIL_SYSCALL_PARAM_TYPE_MASK)<<6u)+ \
  (((p3)&SAIL_SYSCALL_PARAM_TYPE_MASK)<<8u)+ \
  (((p4)&SAIL_SYSCALL_PARAM_TYPE_MASK)<<10u)+ \
  (((p5)&SAIL_SYSCALL_PARAM_TYPE_MASK)<<12u)+ \
  (((p6)&SAIL_SYSCALL_PARAM_TYPE_MASK)<<14u)+ \
  (((p7)&SAIL_SYSCALL_PARAM_TYPE_MASK)<<16u)+ \
  (((p8)&SAIL_SYSCALL_PARAM_TYPE_MASK)<<18u)+ \
  (((p9)&SAIL_SYSCALL_PARAM_TYPE_MASK)<<20u)+ \
  (((p10)&SAIL_SYSCALL_PARAM_TYPE_MASK)<<22u))

/** Internal helper macro for SAIL_SYSCALL_CREATE_PARAM_ID_X */
#define __SAIL_SYSCALL_CREATE_PARAM_ID(...) \
  _SAIL_SYSCALL_CREATE_PARAM_ID(__VA_ARGS__, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u, 0u)

/** Macro used to create a parameter ID with no arguments. */
#define SAIL_SYSCALL_CREATE_PARAM_ID_0 \
  __SAIL_SYSCALL_CREATE_PARAM_ID(0u)
/** Macro used to create a parameter ID with one argument. */
#define SAIL_SYSCALL_CREATE_PARAM_ID_1(p1) \
  __SAIL_SYSCALL_CREATE_PARAM_ID(1u, p1)
/** Macro used to create a parameter ID with two arguments. */
#define SAIL_SYSCALL_CREATE_PARAM_ID_2(p1, p2) \
  __SAIL_SYSCALL_CREATE_PARAM_ID(2u, p1, p2)
/** Macro used to create a parameter ID with three arguments. */
#define SAIL_SYSCALL_CREATE_PARAM_ID_3(p1, p2, p3) \
  __SAIL_SYSCALL_CREATE_PARAM_ID(3u, p1, p2, p3)
/** Macro used to create a parameter ID with four arguments. */
#define SAIL_SYSCALL_CREATE_PARAM_ID_4(p1, p2, p3, p4) \
  __SAIL_SYSCALL_CREATE_PARAM_ID(4u, p1, p2, p3, p4)
/** Macro used to create a parameter ID with five arguments. */
#define SAIL_SYSCALL_CREATE_PARAM_ID_5(p1, p2, p3, p4, p5) \
  __SAIL_SYSCALL_CREATE_PARAM_ID(5u, p1, p2, p3, p4, p5)
/** Macro used to create a parameter ID with six arguments. */
#define SAIL_SYSCALL_CREATE_PARAM_ID_6(p1, p2, p3, p4, p5, p6) \
  __SAIL_SYSCALL_CREATE_PARAM_ID(6u, p1, p2, p3, p4, p5, p6)
/** Macro used to create a parameter ID with seven arguments. */
#define SAIL_SYSCALL_CREATE_PARAM_ID_7(p1, p2, p3, p4, p5, p6, p7) \
  __SAIL_SYSCALL_CREATE_PARAM_ID(7u, p1, p2, p3, p4, p5, p6, p7)
/** Macro used to create a parameter ID with eight arguments. */
#define SAIL_SYSCALL_CREATE_PARAM_ID_8(p1, p2, p3, p4, p5, p6, p7, p8) \
  __SAIL_SYSCALL_CREATE_PARAM_ID(8u, p1, p2, p3, p4, p5, p6, p7, p8)
/** Macro used to create a parameter ID with nine arguments. */
#define SAIL_SYSCALL_CREATE_PARAM_ID_9(p1, p2, p3, p4, p5, p6, p7, p8, p9) \
  __SAIL_SYSCALL_CREATE_PARAM_ID(9u, p1, p2, p3, p4, p5, p6, p7, p8, p9)
/** Macro used to create a parameter ID with ten arguments. */
#define SAIL_SYSCALL_CREATE_PARAM_ID_10(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10) \
  __SAIL_SYSCALL_CREATE_PARAM_ID(10u, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10)


/*----------------------------------------------------------------------------
 * Parameter ID values
 * -------------------------------------------------------------------------*/
/** A parameter of type value. */
#define SAIL_SYSCALL_PARAM_TYPE_VAL              0x0u
/** A parameter of type buffer read only. */
#define SAIL_SYSCALL_PARAM_TYPE_BUF_RO           0x1u
/** A parameter of type buffer read-write. */
#define SAIL_SYSCALL_PARAM_TYPE_BUF_RW           0x2u


/*----------------------------------------------------------------------------
 * Owning Entity IDs (defined by ARM HVC doc)
 * -------------------------------------------------------------------------*/
/** ARM architecture call ID. */
#define SAIL_OWNER_ARM                     0u
/** CPU service call ID. */
#define SAIL_OWNER_CPU                     1u
/** SIP service call ID. */
#define SAIL_OWNER_SIP                     2u
/** OEM service call ID. */
#define SAIL_OWNER_OEM                     3u
/** Standard service call ID. */
#define SAIL_OWNER_STD                     4u
/** Hypervisor service call ID. */
#define SAIL_OWNER_HVC                     5u

/* Values 5-47 are reserved for future use */

/** Information call groups. */
#define SAIL_SVC_INFO_TYPE_COUNT    0u       /**< System call count information.    */
#define SAIL_SVC_INFO_TYPE_UID      1u       /**< System call UID information.      */
#define SAIL_SVC_INFO_TYPE_VER      3u       /**< System call revision information. */
#define SAIL_SVC_INFO_CALL_ID       255u

/* ARM syscall info   */
/** ARM architecture call groups. */
#define SAIL_SVC_ARM_INFO           0u

/* CPU syscall info   */
/** CPU service call groups. */
#define SAIL_SVC_CPU_INFO           SAIL_SVC_INFO_CALL_ID

/* SIP service call groups */
typedef enum
{
    SAIL_SVC_CLOCK                  = 1,     /**< Clock related services.       */
    SAIL_SVC_POWER                  = 2,     /**< Power related services.       */
    SAIL_SVC_SPINOR                 = 3,     /**< SPINOR related services.      */
    SAIL_SVC_CPR                    = 4,     /**< Core Power reduction services */
    SAIL_SVC_VSENS                  = 5,     /**< VSENS related services */
    SAIL_SVC_TSENS                  = 6,     /**< TSENS related services */
    SAIL_SVC_PWR_CNTRL              = 7,     /**< Power Controller related services */
    PSAIL_SVC_CNTRL                 = 8,     /**< PSAIL Related services */
    PMIC_SVC_CNTRL                  = 9,     /**< PMIC Related services */
    SAIL_SVC_XBL                    = 10,    /**< SAIL SVC XBL MAX.*/
    SAIL_SVC_I2C                    = 11,    /**< SAIL SVC I2C.*/
    SAIL_SVC_CHIPINFO               = 12,    /**< CHIPINFO.*/
    SAIL_SVC_TRUSENS                = 13,    /**< TRUSENS.*/
    SAIL_SVC_SST                    = 14,    /**< SST TESTS.*/
    SAIL_SLEEP_SVC                  = 15,
    SAIL_SVC_BOOT                   = 16,    /**< BOOT miltestones services */
    SAIL_SVC_CMN                    = 17,
    SAIL_SVC_BOOTCFG                = 18,     /**< Boot Configuration.*/
    SAIL_SVC_RESCUEIMG              = 19,     /**< Rescue Image.*/
    SAIL_SVC_AC                     = 20,    /**< SAIL Access Control services.*/
    SAIL_SVC_UCLIB                  = 21,	 /**< Uclib related services */
    SAIL_SVC_SHE                    = 22,     /**< SHE SVC.*/
    SAIL_SVC_SECURE_STORAGE         = 23,    /**< Secure Storage related services */
    SAIL_SVC_ICB                    = 24,    /**< ICB related services */
    SAIL_TSC_REG                    = 25,   /**< TSC read/write reg calls.*/
    SAIL_SVC_CDT                    = 26,   /**< TSC read/write reg calls.*/
    SAIL_SVC_SBIST                  = 27,   /**< SAIL ARM Self Test Library related services */
    SAIL_SVC_SECURE_STORAGE_TEST    = 127,   /**< Secure Storage tests related services */    
    SAIL_SVC_SPINOR_TESTS           = 128,   /**< SPINOR tests related services.      */
    SAIL_SVC_QFPROM_TESTS           = 129,    /**< QFPROM tests related services.*/
    SAIL_SVC_FASTBOOT_TESTS         = 130,    /**< Fastboot tests.*/
    SAIL_SVC_TRUSENS_TESTS          = 131,   /**< TRUSENS tests related services.*/
	SAIL_SVC_LOGLEVEL	            = 132,    /**< SAIL UART log level.*/
	SAIL_SVC_ACMU_TEST              = 133,    /**< ACMU Test related services */
    SAIL_SVC_ISD                    = 134,
	SAIL_SVC_DBG                    = 253,   /**< SAIL crash debug.*/
    SAIL_SVC_TEST_0                 = 254,   /**< SAIL test calls.*/
    SAIL_SVC_MAX                    = 255    /**< SAIL SVC ID MAX.*/
}HVCServiceIDType;

/* SIP service call numbers */

typedef enum
{
    SVC_NUM_0 = 0,
    SVC_NUM_1,
    SVC_NUM_2,
    SVC_NUM_3,
    SVC_NUM_4,
    SVC_NUM_5,
    SVC_NUM_6,
    SVC_NUM_7,
    SVC_NUM_8,
    SVC_NUM_9,
    SVC_NUM_10,
    SVC_NUM_11,
    SVC_NUM_12,
    SVC_NUM_13,
    SVC_NUM_14,
    SVC_NUM_15,
    SVC_NUM_16,
    SVC_NUM_17,
    SVC_NUM_18,
    SVC_NUM_19,
    SVC_NUM_20,
    SVC_NUM_21,
    SVC_NUM_22,
    SVC_NUM_23,
    SVC_NUM_24,
    SVC_NUM_25,
    SVC_NUM_26,
    SVC_NUM_27,
    SVC_NUM_28,
    SVC_NUM_29,
    SVC_NUM_30,
    SVC_NUM_31,
    SVC_NUM_32,
    SVC_NUM_33,
    SVC_NUM_34,
    SVC_NUM_35,
    SVC_NUM_36
}HVCServiceNumber;

#define SAIL_SVC_SIP_INFO           SAIL_SVC_INFO_CALL_ID /**< SIP syscall information. */

/* OEM service call groups */
#define SAIL_SVC_OEM_INFO           SAIL_SVC_INFO_CALL_ID /**< OEM service call information. */

/* Standards call groups */
#define SAIL_SVC_PSCI               0u
#define SAIL_SVC_STANDARD_INFO      SAIL_SVC_INFO_CALL_ID /**< Service standard information. */

 /** @name HVC Interface Error Codes Enumeration
 @{ */
typedef enum
{
  HVC_BUSY                          =  1,   /**< BUSY, another service being handled syscall was called.   */
  HVC_SUCCESS                       =  0,   /**< Success, requested syscall was called.   */
  HVC_ERR_UNKNOWN_HVC_ID            = -1L,  /**< ARM-defined error of 0xFFFFFFFF.         */
  HVC_ERR_SYSCALL_FAILED            = -2L,  /**< Syscall function returned failure.       */
  HVC_ERR_SYSCALL_NOT_AVAILABLE     = -3L,  /**< No function associated with the syscall definition. */
  HVC_ERR_RESERVED_FIELD_MBZ        = -4L,  /**< HVC ID error: reserved field must be zero. */
  HVC_ERR_NUM_ARGS_MISMATCH         = -5L,  /**< Number of arguments does not match the
                                                 function definition.                     */
  HVC_ERR_INDIRECT_PARAM_PTR_NOT_NS = -6L,  /**< Indirect parameter pointer does not
                                                 point to NS memory.                      */
  HVC_ERR_BUF_LEN_NOT_FOUND         = -7L,  /**< No buffer length following the buffer pointer. */
  HVC_ERR_BUF_PTR_NOT_NS            = -8L,  /**< Buffer pointer does not point to NS memory. */
  HVC_ERR_NO_MEMORY                 = -9L,  /**< Heap is out of space.                    */
  HVC_ERR_PARAM_ID_MISMATCH         = -10L, /**< Incorrect parameter ID from the NS world. */
  HVC_ERR_BUF_PTR_INVALID           = -11L, /**< Buffer pointer is in the first 4k (invalid) page. */
  HVC_ERR_BUSY                      = -12L, /**< SAIL software is busy waiting for a listener response. */
  HVC_ERR_SESSION_ID_MISMATCH       = -13L, /**< Trusted OS session ID mismatch error.    */
  HVC_ERR_NOT_FOUND_IN_HYP          = -14L, /**< HVC call is not served in HYP.           */
  HVC_ERR_TEE_SERVICE_NOT_FOUND     = -15L, /**< HVC call is from a TEE, but the format is bad. */
  HVC_ERR_STANDARD_CALL_NOT_ALLOWED = -16L, /**< Pre-emptible calls are not allowed.      */
  HVC_ERR_WAITQ_CTX_INVALID         = -18L, /**< The passed HVCCtx for acknowledge or resume is an
                                                 invalid context.                            */
  /* ARMv8 HVC spec: Must return 0xFFFFFFFF for these errors */
  HVC_ERR_SYSCALL_NOT_SUPPORTED     = HVC_ERR_UNKNOWN_HVC_ID, /**< Syscall is not supported. */
  HVC_ERR_AARCH64_NOT_SUPPORTED     = HVC_ERR_UNKNOWN_HVC_ID, /**< HVC64 is not supported.   */

  HVC_ERR_FAILURE                   = -INT32_MAX   /**< Internal failure.                    */
} HVCErrnoType;

/** @name SVC Interface Error Codes Enumeration
@{ */
typedef enum
{
 SVC_BUSY                          =  1,   /**< BUSY, another service being handled syscall was called.   */
 SVC_SUCCESS                       =  0,   /**< Success, requested syscall was called.   */
 SVC_ERR_UNKNOWN_SVC_ID            = -1L,  /**< ARM-defined error of 0xFFFFFFFF.         */
 SVC_ERR_SYSCALL_FAILED            = -2L,  /**< Syscall function returned failure.       */
 SVC_ERR_SYSCALL_NOT_AVAILABLE     = -3L,  /**< No function associated with the syscall definition. */
 SVC_ERR_RESERVED_FIELD_MBZ        = -4L,  /**< HVC ID error: reserved field must be zero. */
 SVC_ERR_NUM_ARGS_MISMATCH         = -5L,  /**< Number of arguments does not match the
                                                function definition.                     */
 SVC_ERR_INDIRECT_PARAM_PTR_NOT_NS = -6L,  /**< Indirect parameter pointer does not
                                                point to NS memory.                      */
 SVC_ERR_BUF_LEN_NOT_FOUND         = -7L,  /**< No buffer length following the buffer pointer. */
 SVC_ERR_BUF_PTR_NOT_NS            = -8L,  /**< Buffer pointer does not point to NS memory. */
 SVC_ERR_NO_MEMORY                 = -9L,  /**< Heap is out of space.                    */
 SVC_ERR_PARAM_ID_MISMATCH         = -10L, /**< Incorrect parameter ID from the NS world. */
 SVC_ERR_BUF_PTR_INVALID           = -11L, /**< Buffer pointer is in the first 4k (invalid) page. */
 SVC_ERR_BUSY                      = -12L, /**< SAIL software is busy waiting for a listener response. */
 SVC_ERR_SESSION_ID_MISMATCH       = -13L, /**< Trusted OS session ID mismatch error.    */
 SVC_ERR_NOT_FOUND_IN_HYP          = -14L, /**< HVC call is not served in HYP.           */
 SVC_ERR_TEE_SERVICE_NOT_FOUND     = -15L, /**< HVC call is from a TEE, but the format is bad. */
 SVC_ERR_STANDARD_CALL_NOT_ALLOWED = -16L, /**< Pre-emptible calls are not allowed.      */
 SVC_ERR_WAITQ_CTX_INVALID         = -18L, /**< The passed HVCCtx for acknowledge or resume is an
                                                invalid context.                            */
 /* ARMv8 HVC spec: Must return 0xFFFFFFFF for these errors */
 SVC_ERR_SYSCALL_NOT_SUPPORTED     = SVC_ERR_UNKNOWN_SVC_ID, /**< Syscall is not supported. */
 SVC_ERR_AARCH64_NOT_SUPPORTED     = SVC_ERR_UNKNOWN_SVC_ID, /**< HVC64 is not supported.   */

 SVC_ERR_FAILURE                   = -INT32_MAX   /**< Internal failure.                    */
} SVCErrnoType;


/*----------------------------------------------------------------------------
                ARM Info calls
 * -------------------------------------------------------------------------*/
/**
   @ingroup arm_info

   Returns the version of SMCCC that is implemented.

   @smc_id
     0x80000000

   @return
     Version information: \n
       Bits [31:16] Major Version \n
       Bits [15:0] Minor Version
*/
 #define SAIL_SMCCC_VERSION_SMCC_ID                  \
  SAIL_SYSCALL_CREATE_SMCCC_ID(SAIL_OWNER_ARM, SAIL_SVC_ARM_INFO , SVC_NUM_0)

 #define SAIL_SMCCC_VERSION_PARAM_ID                  \
  SAIL_SYSCALL_CREATE_PARAM_ID_0


/*----------------------------------------------------------------------------
                HVC calls
 * -------------------------------------------------------------------------*/

/***===== Clock Service HVC IDs =====***/
/**
  @ingroup
    SAIL_SVC_CLOCK

  @hvc_id
    0x05000101

  @param_id
    0x1

  @param[in]
    hClient.

  @return
     <> in response struct.
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define CLOCK_GET_HANDLE_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_CLOCK, SVC_NUM_1)

#define CLOCK_GET_HANDLE_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_1( \
      SAIL_SYSCALL_PARAM_TYPE_VAL )

/**
  @ingroup
    SAIL_SVC_CLOCK

  @hvc_id
    0x05000102

  @param_id
    0x3

  @param[in]
    hClient, *szName, *pId


  @return
     <> in response struct.
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define CLOCK_GETCLOCKID_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_CLOCK, SVC_NUM_2)

#define CLOCK_GETCLOCKID_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_3( \
      SAIL_SYSCALL_PARAM_TYPE_VAL, SAIL_SYSCALL_PARAM_TYPE_VAL, SAIL_SYSCALL_PARAM_TYPE_VAL )

/**
  @ingroup
    SAIL_SVC_CLOCK

  @hvc_id
    0x05000103

  @param_id
    0x3

  @param[in]
    hClient, ClockId, nFlags


  @return
     <> in response struct.
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define CLOCK_ENABLECLOCKEX_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_CLOCK, SVC_NUM_3)

#define CLOCK_ENABLECLOCKEX_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_3( \
      SAIL_SYSCALL_PARAM_TYPE_VAL, SAIL_SYSCALL_PARAM_TYPE_VAL, SAIL_SYSCALL_PARAM_TYPE_VAL )
/**

  @ingroup
    SAIL_SVC_CLOCK

  @hvc_id
    0x05000104

  @param_id
    0x5

  @param[in]
    hClient, ClockId, nFreq, eMatch, *pnResultFreq


  @return
     <> in response struct.
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define CLOCK_SETCLOCKFREQUENCY_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_CLOCK, SVC_NUM_4)

#define CLOCK_SETCLOCKFREQUENCY_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_5(  \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_VAL )

/**
  @ingroup
    SAIL_SVC_CLOCK

  @hvc_id
    0x05000105

  @param_id
    0x3

  @param[in]
    hClient, ClockId, nFlags


  @return
     <> in response struct.
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define CLOCK_DISABLECLOCKEX_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_CLOCK, SVC_NUM_5)

#define CLOCK_DISABLECLOCKEX_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_3( \
      SAIL_SYSCALL_PARAM_TYPE_VAL, SAIL_SYSCALL_PARAM_TYPE_VAL, SAIL_SYSCALL_PARAM_TYPE_VAL )

/**
  @ingroup
    SAIL_SVC_CLOCK

  @hvc_id
    0x05000106

  @param_id
    0x3

  @param[in]
    hClient, ClockId, pnFrequencyHz


  @return
     <> in response struct.
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define CLOCK_GETCLOCKFREQUENCY_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_CLOCK, SVC_NUM_6)

#define CLOCK_GETCLOCKFREQUENCY_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_3( \
      SAIL_SYSCALL_PARAM_TYPE_VAL, SAIL_SYSCALL_PARAM_TYPE_VAL, SAIL_SYSCALL_PARAM_TYPE_VAL )

/**
  @ingroup
    SAIL_SVC_CLOCK

  @hvc_id
    0x05000107

  @param_id
    0x3

  @param[in]
    hClient, ClockId, pbIsEnabled


  @return
     <> in response struct.
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define CLOCK_ISCLOCKENABLED_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_CLOCK, SVC_NUM_7)

#define CLOCK_ISCLOCKENABLED_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_3( \
      SAIL_SYSCALL_PARAM_TYPE_VAL, SAIL_SYSCALL_PARAM_TYPE_VAL, SAIL_SYSCALL_PARAM_TYPE_VAL )

/**
  @ingroup
    SAIL_SVC_CLOCK

  @hvc_id
    0x05000108

  @param_id
    0x3

  @param[in]
    hClient, ClockId, pbIsOn


  @return
     <> in response struct.
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define CLOCK_ISCLOCKON_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_CLOCK, SVC_NUM_8)

#define CLOCK_ISCLOCKON_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_3( \
      SAIL_SYSCALL_PARAM_TYPE_VAL, SAIL_SYSCALL_PARAM_TYPE_VAL, SAIL_SYSCALL_PARAM_TYPE_VAL )
/**
  @ingroup
    SAIL_SVC_CLOCK

  @hvc_id
    0x05000109

  @param_id
    0x3

  @param[in]
    hClient, ClockId, eReset


  @return
     <> in response struct.
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define CLOCK_RESETBLOCK_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_CLOCK, SVC_NUM_9)

#define CLOCK_RESETBLOCK_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_3( \
      SAIL_SYSCALL_PARAM_TYPE_VAL, SAIL_SYSCALL_PARAM_TYPE_VAL, SAIL_SYSCALL_PARAM_TYPE_VAL )

/**
  @ingroup
    SAIL_SVC_CLOCK

  @hvc_id
    0x0500010A

  @param_id
    0x3

  @param[in]
    hClient, ClockId, eReset


  @return
     <> in response struct.
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define CLOCK_RESET_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_CLOCK, SVC_NUM_10)

#define CLOCK_RESET_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_3( \
      SAIL_SYSCALL_PARAM_TYPE_VAL, SAIL_SYSCALL_PARAM_TYPE_VAL, SAIL_SYSCALL_PARAM_TYPE_VAL )

/**
  @ingroup
    SAIL_SVC_CLOCK

  @hvc_id
    0x0500010B

  @param_id
    0x0

  @param[in]
  None


  @return
     <> in response struct.
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define CLOCK_SLEEP_ENTRY_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_CLOCK, SVC_NUM_11)

#define CLOCK_SLEEP_ENTRY_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_0

/**
  @ingroup
    SAIL_SVC_CLOCK

  @hvc_id
    0x0500010C

  @param_id
    0x0

  @param[in]
  None


  @return
     <> in response struct.
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define CLOCK_SLEEP_EXIT_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_CLOCK, SVC_NUM_12)

#define CLOCK_SLEEP_EXIT_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_0

/**
  @ingroup
    SAIL_SVC_CLOCK

  @hvc_id
    0x0500010D

  @param_id
    0x1

  @param[in]
  cpu_num


  @return
     <> in response struct.
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define CLOCK_RESET_CORE_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_CLOCK, SVC_NUM_13)

#define CLOCK_RESET_CORE_PARAM_ID \
   SAIL_SYSCALL_CREATE_PARAM_ID_1( \
      SAIL_SYSCALL_PARAM_TYPE_VAL )

/**
  @ingroup
    SAIL_SVC_CLOCK

  @hvc_id
    0x0500010E

  @param_id
    0x3

  @param[in]
   hClient,szName,eGetCorner


  @return
     <> in response struct.
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define CLOCK_GETVOLTAGERAILCORNER_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_CLOCK, SVC_NUM_14)

#define CLOCK_GETVOLTAGERAILCORNER_PARAM_ID \
        SAIL_SYSCALL_CREATE_PARAM_ID_3( \
                SAIL_SYSCALL_PARAM_TYPE_VAL, SAIL_SYSCALL_PARAM_TYPE_VAL, SAIL_SYSCALL_PARAM_TYPE_VAL )

/**
  @ingroup
    SAIL_SVC_CLOCK

  @hvc_id
    0x0500010F

  @param_id
    0x2

  @param[in]
  eCorner, szName


  @return
     <> in response struct.
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define CLOCK_GETPERFSTRINGNAME_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_CLOCK, SVC_NUM_15)

#define CLOCK_GETPERFSTRINGNAME_PARAM_ID \
        SAIL_SYSCALL_CREATE_PARAM_ID_2( \
                SAIL_SYSCALL_PARAM_TYPE_VAL, SAIL_SYSCALL_PARAM_TYPE_VAL )

/**
  @ingroup
    SAIL_SVC_CLOCK

  @hvc_id
    0x05000110

  @param_id
    0x0

  @param[in]
  None


  @return
     <> in response struct.
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define CLOCK_NODEREFCOUNTDUMP_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_CLOCK, SVC_NUM_16)

#define CLOCK_NODEREFCOUNTDUMP_PARAM_ID \
        SAIL_SYSCALL_CREATE_PARAM_ID_0

/**
  @ingroup

  @brief Rescue Image check

  @smc_id  0x5001301


  @param_id  0x0


  @param bootImgStatus [OUT]
    return status if Boot Image command loaded the rescue image

  @return
    Result of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define SAIL_RESCUEIMG_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_RESCUEIMG, SVC_NUM_1)

#define SAIL_RESCUEIMG_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_0

/***===== Power Service HVC IDs =====***/
/***===== SPINOR Service HVC IDs =====***/
/**
  @ingroup

  @brief Handles the trap call events

  @smc_id  0x5000301


  @param_id  0xA

  @param eventID [IN]
    Spinor Trap Event ID

  @param handle [IN/OUT]
    Pointer to SPINOR service interface handle as an input parameter.
    Pointer to internal spinor_clients refernce count upon return

  @return
    Result of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define SAIL_SPINOR_FUNC_TRAP \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_SPINOR, SVC_NUM_1)

#define SAIL_SPINOR_FUNC_TRAP_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_2( \
      SAIL_SYSCALL_PARAM_TYPE_VAL ,\
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW)

/***===== SPINOR tests Service HVC IDs =====***/
/**
  @ingroup

  @brief HVC Call to call SPINOR EL2 Test Wrapper Function

  @smc_id  0x05008001


  @param_id 0x1


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define SAIL_SPINOR_FUNC_TEST_TRAP \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_SPINOR_TESTS, SVC_NUM_1)

#define SAIL_SPINOR_FUNC_TEST_TRAP_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_1( \
      SAIL_SYSCALL_PARAM_TYPE_VAL)

/***===== Fastboot Controller Service HVC IDs =====***/
/**
  @ingroup

  @brief HVC Call to call Fastboot Hello Test Wrapper Function

  @smc_id  0x5008201


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
	
#define FASTBOOT_HELLO_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_FASTBOOT_TESTS, SVC_NUM_1)

#define FASTBOOT_HELLO_PARAM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_0

/**
  @ingroup

  @brief HVC Call to call Fastboot Flash Image Test Wrapper Function

  @smc_id  0x5008202


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
	
#define FASTBOOT_FLASHIMG_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_FASTBOOT_TESTS, SVC_NUM_2)

#define FASTBOOT_FLASHIMG_PARAM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_0
    
/**
  @ingroup

  @brief HVC Call to call Fastboot Read Image Test Wrapper Function

  @smc_id  0x5008203


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
	
#define FASTBOOT_READIMG_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_FASTBOOT_TESTS, SVC_NUM_3)

#define FASTBOOT_READIMG_PARAM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_0
    
/**
  @ingroup

  @brief HVC Call to call Fastboot Query Image Test Wrapper Function

  @smc_id  0x5008204


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
	
#define FASTBOOT_QUERYIMG_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_FASTBOOT_TESTS, SVC_NUM_4)

#define FASTBOOT_QUERYIMG_PARAM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_0

/**
  @ingroup

  @brief HVC Call to call Fastboot Boot Info Test Wrapper Function

  @smc_id  0x5008205


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
	
#define FASTBOOT_BLINFO_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_FASTBOOT_TESTS, SVC_NUM_5)

#define FASTBOOT_BLINFO_PARAM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_0
    
/**
  @ingroup

  @brief HVC Call to call Fastboot Boot Image Test Wrapper Function

  @smc_id  0x5008206


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
	
#define FASTBOOT_BOOTIMG_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_FASTBOOT_TESTS, SVC_NUM_6)

#define FASTBOOT_BOOTIMG_PARAM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_0    

/**
  @ingroup

  @brief HVC Call to call Fast Boot Continue Test Wrapper Function

  @smc_id  0x5008207


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
	
#define FASTBOOT_BOOTCONTINUE_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_FASTBOOT_TESTS, SVC_NUM_7)

#define FASTBOOT_BOOTCONTINUE_PARAM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_0
    
/**
  @ingroup

  @brief HVC Call to call Init Test Wrapper Function

  @smc_id  0x5008208


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
	
#define FASTBOOT_INIT_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_FASTBOOT_TESTS, SVC_NUM_8)

#define FASTBOOT_INIT_PARAM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_0
/***===== Power Controller Service HVC IDs =====***/
/**
  @ingroup

  @brief Checks if EL2 Driver is initialized and ready for accepting sleep

  @smc_id  0x5000701


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define SAIL_PC_IS_CORE_INITIALIZED \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_PWR_CNTRL, SVC_NUM_1)

#define SAIL_PC_IS_CORE_INITIALIZED_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_0

/**
  @ingroup

  @brief Checks if EL2 Driver is initialized and ready for accepting sleep

  @smc_id  0x5000702


  @param_id  0x11


  @param type [IN]
    Masks containing the IRQs that should be masked in the Power Controller

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define SAIL_PC_CONFIGURE_WAKEIRQ \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_PWR_CNTRL, SVC_NUM_2)

#define SAIL_PC_CONFIGURE_WAKEIRQ_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_1( \
      SAIL_SYSCALL_PARAM_TYPE_BUF_RO )

/**
  @ingroup

  @brief Sleep Entry for Power Controller

  @smc_id  0x5000703


  @param_id  0x1


  @param type [IN]
    Sleep type to be configured in the Power controller Hardware

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define SAIL_PC_SLEEP_ENTER \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_PWR_CNTRL, SVC_NUM_3)

#define SAIL_PC_SLEEP_ENTER_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_1( \
      SAIL_SYSCALL_PARAM_TYPE_VAL )

/**
  @ingroup

  @brief Controls the Power Controller Sequencer Enable

  @smc_id  0x5000704


  @param_id 0x1


  @param type [IN]
    Control for the Power controller Sequencer

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define SAIL_PC_SEQUENCER_EN_CTRL \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_PWR_CNTRL, SVC_NUM_4)

#define SAIL_PC_SEQUENCER_EN_CTRL_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_1( \
      SAIL_SYSCALL_PARAM_TYPE_VAL )

/**
  @ingroup

  @brief Controls the Power Controller Glitch Source and APM Comparator Enable

  @smc_id  0x5000705


  @param_id  0x1


  @param type [IN]
    Control for the Power controller Glitch Source and APM Comparator

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define SAIL_PC_GLITCH_SRC_CTRL \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_PWR_CNTRL, SVC_NUM_5)

#define SAIL_PC_GLITCH_SRC_CTRL_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_1( \
      SAIL_SYSCALL_PARAM_TYPE_VAL )

/**
  @ingroup

  @brief Populates the wake up reason

  @smc_id  0x5000706


  @param_id 0x21


  @param type [IN/OUT]
    Pointer to Reason mask as input parameter
    Mask that provides the reason for the wakeup upon return

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define SAIL_PC_POPULATE_WAKEUP_REASON \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_PWR_CNTRL, SVC_NUM_6)

#define SAIL_PC_POPULATE_WAKEUP_REASON_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_1( \
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW )

/***===== SLEEP Service HVC IDs =====***/
/**
  @ingroup

  @brief Used to do HVC call to EL2 to deInit function register

  @smc_id  0x5000F01


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define SLEEP_NOTIFY_EL2 \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SLEEP_SVC, SVC_NUM_1)

#define SLEEP_NOTIFY_EL2_PARM_ID \
      SAIL_SYSCALL_CREATE_PARAM_ID_1( \
      SAIL_SYSCALL_PARAM_TYPE_VAL )

/**
  @ingroup

  @brief Used to do HVC call to update sleep marker

  @smc_id  0x5000F02


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define SLEEP_DATA \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SLEEP_SVC, SVC_NUM_2)

#define SLEEP_DATA_PARM_ID \
      SAIL_SYSCALL_CREATE_PARAM_ID_1( \
      SAIL_SYSCALL_PARAM_TYPE_VAL)


/**
  @ingroup

  @brief Used to do HVC call to get sleep data

  @smc_id  0x5000F03


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define SLEEP_GET_DATA \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SLEEP_SVC, SVC_NUM_3)

#define SLEEP_GET_DATA_PARM_ID \
      SAIL_SYSCALL_CREATE_PARAM_ID_1( \
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW)


/**
  @ingroup

  @brief Used to do HVC call to do RTCU config

  @smc_id  0x5000F04


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define SLEEP_RTCU_SETTING \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SLEEP_SVC, SVC_NUM_4)

#define SLEEP_RTCU_SETTING_PARM_ID \
      SAIL_SYSCALL_CREATE_PARAM_ID_0

/**
  @ingroup

  @brief Used to do HVC call to disable sailss clock

  @smc_id  0x5000F05


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define SLEEP_CLOCK_DISABLE \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SLEEP_SVC, SVC_NUM_5)

#define SLEEP_CLOCK_DISABLE_PARM_ID \
      SAIL_SYSCALL_CREATE_PARAM_ID_0


/**
  @ingroup

  @brief Used to do HVC call to do sleep config based on STR/DeepSleep

  @smc_id  0x5000F06


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define SLEEP_CONFIG_DATA \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SLEEP_SVC, SVC_NUM_6)

#define SLEEP_CONFIG_DATA_PARM_ID \
      SAIL_SYSCALL_CREATE_PARAM_ID_1( \
      SAIL_SYSCALL_PARAM_TYPE_VAL )


/**
  @ingroup

  @brief Used to do HVC call to do NOC reset for STR - Used in Autosar

  @smc_id  0x5000F07


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define SLEEP_ASILD_NOC_RESET \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SLEEP_SVC, SVC_NUM_7)

#define SLEEP_ASILD_NOC_RESET_PARM_ID \
      SAIL_SYSCALL_CREATE_PARAM_ID_0
      

/***===== PMIC Service HVC IDs =====***/
/**
  @ingroup

  @brief Used to change CX/MX voltage corners.

  @smc_id  0x5000901


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define PMIC_CORNER_CHANGE \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_1)

#define PMIC_CORNER_CHANGE_PARM_ID \
      SAIL_SYSCALL_CREATE_PARAM_ID_2( \
      SAIL_SYSCALL_PARAM_TYPE_VAL ,\
      SAIL_SYSCALL_PARAM_TYPE_VAL)


/**
  @ingroup

  @brief Used to log pending INTR of PMIC to EFS

  @smc_id  0x5000902


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/


#define PMIC_INTR_HANDLING \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_2)

#define PMIC_INTR_HANDLING_PARM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_1( \
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW)

/**
  @ingroup

  @brief Used to Initiate Runtime BIST

  @smc_id  0x5000903


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/


#define PMIC_RUNTIME_BIST \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_3)

#define PMIC_RUNTIME_BIST_PARM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_0

/**
  @ingroup

  @brief Used to Configure Enable_drv pin

  @smc_id  0x5000904


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/


#define PMIC_CONFIGURE_ENABLEDRV_PIN \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_4)

#define PMIC_CONFIGURE_ENABLEDRV_PIN_PARM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_1( \
      SAIL_SYSCALL_PARAM_TYPE_VAL )

/**
  @ingroup

  @brief Used to Read out CX/MX voltage

  @smc_id  0x5000905


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define PMIC_READ_VOLTAGE \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_5)

#define PMIC_READ_VOLTAGE_PARM_ID \
      SAIL_SYSCALL_CREATE_PARAM_ID_2( \
      SAIL_SYSCALL_PARAM_TYPE_VAL ,\
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW)
/**
  @ingroup

  @brief Used to Write CX/MX voltage

  @smc_id  0x5000906


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define PMIC_WRITE_VOLTAGE \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_6)

#define PMIC_WRITE_VOLTAGE_PARM_ID \
      SAIL_SYSCALL_CREATE_PARAM_ID_3( \
      SAIL_SYSCALL_PARAM_TYPE_VAL ,\
      SAIL_SYSCALL_PARAM_TYPE_VAL ,\
      SAIL_SYSCALL_PARAM_TYPE_VAL)

/**
  @ingroup

  @brief Used to Get Read out LDO Voltage

  @smc_id  0x5000907


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define PMIC_READ_LDO_VOLTAGE \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_7)

#define PMIC_READ_LDO_VOLTAGE_PARM_ID \
      SAIL_SYSCALL_CREATE_PARAM_ID_2( \
      SAIL_SYSCALL_PARAM_TYPE_VAL ,\
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW)

/**
  @ingroup

  @brief Used to Get Read out LDO Enable Status

  @smc_id  0x5000908


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define PMIC_READ_LDO_ENABLE \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_8)

#define PMIC_READ_LDO_ENABLE_PARM_ID \
      SAIL_SYSCALL_CREATE_PARAM_ID_2( \
      SAIL_SYSCALL_PARAM_TYPE_VAL ,\
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW)

/**
  @ingroup

  @brief Used to Read out SMPS mode

  @smc_id  0x5000909


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define PMIC_READ_SMPS_MODE \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_9)

#define PMIC_READ_SMPS_MODE_PARM_ID \
      SAIL_SYSCALL_CREATE_PARAM_ID_2( \
      SAIL_SYSCALL_PARAM_TYPE_VAL ,\
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW)

/**
  @ingroup

  @brief Used to Read SMPS Enable Status

  @smc_id  0x500090A


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define PMIC_READ_SMPS_ENABLE \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_10)

#define PMIC_READ_SMPS_ENABLE_PARM_ID \
      SAIL_SYSCALL_CREATE_PARAM_ID_2( \
      SAIL_SYSCALL_PARAM_TYPE_VAL ,\
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW)

/**
  @ingroup

  @brief Used to Read SMPS Voltage

  @smc_id  0x500090B


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define PMIC_READ_SMPS_VOLTAGE \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_11)

#define PMIC_READ_SMPS_VOLTAGE_PARM_ID \
      SAIL_SYSCALL_CREATE_PARAM_ID_2( \
      SAIL_SYSCALL_PARAM_TYPE_VAL ,\
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW)


/**
  @ingroup

  @brief Used to Configure Reset State

  @smc_id  0x500090C


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define PMIC_SET_RESET_STATE \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_12)

#define PMIC_SET_RESET_STATE_PARM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_1( \
      SAIL_SYSCALL_PARAM_TYPE_VAL )

/**
  @ingroup

  @brief Used to Read out PMIC I2C Register

  @smc_id  0x500090D


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define PMIC_COMM_READ \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_13)

#define PMIC_COMM_READ_PARM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_3( \
      SAIL_SYSCALL_PARAM_TYPE_VAL,\
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW )

/**
  @ingroup

  @brief Used to Enable LDO

  @smc_id  0x500090E


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define PMIC_LDO_ENABLE_WRITE \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_14)

#define PMIC_LDO_ENABLE_WRITE_PARM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_2( \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_VAL)

/**
  @ingroup

  @brief Used to Write LDO Voltage

  @smc_id  0x500090F


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define PMIC_LDO_VOLTAGE_WRITE \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_15)

#define PMIC_LDO_VOLTAGE_WRITE_PARM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_3( \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_VAL,\
      SAIL_SYSCALL_PARAM_TYPE_VAL)
/**
  @ingroup

  @brief Used to Enable SMPS

  @smc_id  0x5000910


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define PMIC_SMPS_ENABLE_WRITE \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_16)

#define PMIC_SMPS_ENABLE_WRITE_PARM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_2( \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_VAL)

/**
  @ingroup

  @brief Used to Read out mode of SMPS

  @smc_id  0x5000911


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define PMIC_SMPS_MODE_WRITE \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_17)

#define PMIC_SMPS_MODE_WRITE_PARM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_2( \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_VAL)

/**
  @ingroup

  @brief Used to Write SMPS Voltage

  @smc_id  0x5000912


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define PMIC_SMPS_VOLTAGE_WRITE \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_18)

#define PMIC_SMPS_VOLTAGE_WRITE_PARM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_3( \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_VAL,\
      SAIL_SYSCALL_PARAM_TYPE_VAL)

/**
  @ingroup

  @brief Used to Get NVM Id

  @smc_id  0x5000913


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define PMIC_GET_NVM_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_19)

#define PMIC_GET_NVM_ID_PARM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_1(\
      SAIL_SYSCALL_PARAM_TYPE_VAL)

  /**
  @ingroup

  @brief Used to write to PMIC Register

  @smc_id  0x5000914


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define PMIC_COMM_WRITE \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_20)

#define PMIC_COMM_WRITE_PARM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_3( \
      SAIL_SYSCALL_PARAM_TYPE_VAL,\
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_VAL )

  /**
  @ingroup

  @brief Used to do Pmic Deinit

  @smc_id  0x5000915


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define PMIC_DE_INIT \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_21)

#define PMIC_DE_INIT_PARM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_0


  /**
  @ingroup

  @brief Used to do pmicInit

  @smc_id  0x5000916


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define PMIC_INIT \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_22)

#define PMIC_INIT_PARM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_0

  /**
  @ingroup

  @brief Used to get PMIC reset state

  @smc_id  0x5000917


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define PMIC_GET_RESET_STATE \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_23)

#define PMIC_GET_RESET_STATE_PARM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_1( \
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW)


  /**
  @ingroup

  @brief Used to get if SAIL PMIC is present

  @smc_id  0x5000918


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define PMIC_PRESENT \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_24)

#define PMIC_PRESENT_PARM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_0


/**
  @ingroup

  @brief Used to Configure SAIL PMIC for Sleep Entry/Exit

  @smc_id  0x5000919


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define PMIC_SLEEP_CONFIG \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_25)

#define PMIC_SLEEP_CONFIG_PARM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_1( \
      SAIL_SYSCALL_PARAM_TYPE_VAL)


/**
  @ingroup

  @brief Used to Configure SAIL PMIC External WDG

  @smc_id  0x500091A


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define PMIC_EXTWDG_INIT \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_26)

#define PMIC_EXTWDG_INIT_PARM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_0

/**
  @ingroup

  @brief Used to Configure SAIL PMIC External WDG

  @smc_id  0x500091B


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define PMIC_EXTWDG_ENABLE \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_27)

#define PMIC_EXTWDG_ENABLE_PARM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_0



/**
  @ingroup

  @brief Used to Configure SAIL PMIC External WDG

  @smc_id  0x500091C


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define PMIC_EXTWDG_PET \
SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_28)

#define PMIC_EXTWDG_PET_PARM_ID \
SAIL_SYSCALL_CREATE_PARAM_ID_0

/**
  @ingroup

  @brief Used to Configure SAIL PMIC External WDG

  @smc_id  0x500091D


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define PMIC_EXTWDG_DISABLE \
SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_29)

#define PMIC_EXTWDG_DISABLE_PARM_ID \
SAIL_SYSCALL_CREATE_PARAM_ID_0


/**
  @ingroup

  @brief Used to Get PMIC SM Err Status

  @smc_id  0x500091E


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/


#define PMIC_GET_SM_ERR_STATUS \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_30)

#define PMIC_GET_SM_ERR_STATUS_PARM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_1( \
      SAIL_SYSCALL_PARAM_TYPE_VAL)

/**
  @ingroup

  @brief Check if PMIC FW Version Supports MCU-Less

  @smc_id  0x500091F


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/


#define PMIC_CHECK_FW_MCU_LESS \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_31)

#define PMIC_CHECK_FW_MCU_LESS_PARM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_0



/**
  @ingroup

  @brief Ask PMIC to assert or deassert KPD PWR ON

  @smc_id  0x5000920


  @param_id 0x1


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/


#define PMIC_CHANGE_KPD_PWR \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_32)

#define PMIC_CHANGE_KPD_PWR_PARM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_1( \
      SAIL_SYSCALL_PARAM_TYPE_VAL)

/**
  @ingroup

  @brief Check if PMIC WD has completed First Pet in QA mode.

  @smc_id  0x5000921


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/


#define PMIC_EXTWDG_CHECK_FIRST_PET_COMPLETE \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_33)

#define PMIC_EXTWDG_CHECK_FIRST_PET_COMPLETE_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_0

/**
  @ingroup

  @brief Ask PMIC to perform SM_ERR Handshake

  @smc_id  0x5000922


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/


#define PMIC_SM_ERR_HANDSHAKE \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_34)

#define PMIC_SM_ERR_HANDSHAKE_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_0

/**
  @ingroup

  @brief PMIC to Configure Additional POFF Delay.

  @smc_id  0x5000923


  @param_id 0x1


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/


#define PMIC_CHANGE_POFF_DELAY \
  SAIL_SYSCALL_CREATE_HVC_ID(PMIC_SVC_CNTRL, SVC_NUM_35)

#define PMIC_CHANGE_POFF_DELAY_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_1( \
      SAIL_SYSCALL_PARAM_TYPE_VAL)

/***===== BOOTLOADER service HVC IDs =====***/
/**
  @ingroup

  @brief HVC call of Xbl
  @smc_id 0x5000A01


  @param_id 0x3


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define XBL_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_XBL, SVC_NUM_1)

#define XBL_HVC_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_3( \
      SAIL_SYSCALL_PARAM_TYPE_VAL,\
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW,\
      SAIL_SYSCALL_PARAM_TYPE_VAL)

/***===== BOOT miltestones services HVC IDs =====***/
/**
  @ingroup

  @brief HVC call to BOOT miltestones services
  @smc_id  0x5001001

  @param_id 0x0

  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define SAIL_BOOT_ARB_UPDATE_ALL_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_BOOT, SVC_NUM_1)

#define SAIL_BOOT_ARB_UPDATE_ALL_PARAM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_0

/**
  @ingroup

  @brief HVC call to BOOT miltestones services
  @smc_id  0x5001002

  @param_id 0x0

  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define SAIL_BOOT_MRC_UPDATE_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_BOOT, SVC_NUM_2)

#define SAIL_BOOT_MRC_UPDATE_PARAM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_0

/**
  @ingroup

  @brief HVC call to update EL2 MPU configuration
  @smc_id  0x5001003

  @param_id 0x0

  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define SAIL_BOOT_EL2_MPU_UPDATE_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_BOOT, SVC_NUM_3)

#define SAIL_BOOT_EL2_MPU_UPDATE_PARAM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_0
	
/**
  @ingroup

  @brief HVC call to Get Fuse Bit Status
  @smc_id  0x5001004

  @param_id 0x1

  @param[in]
    UINT32 value, Each Bit representing a fuse blown status to be read as shown below.
    Multiple bits can be read in a single operation with param value with all bits set.
    | 0-DBGEN | 1-NIDEN | 2-HIDEN | 3-HNIDEN | 4-C0_DBGEN | 5-C0_NIDEN | 6-C1_DBGEN
    | 7-C1_NIDEN | 8-C2_DBGEN | 9-C2_NIDEN | 10-C3_DBGEN  | 11-C3_NIDEN | 12-CPU_SCAN_EN
    | 13-DCC_SCAN_EN | 14-WDOG_EN | 15-OEM_SECURE_BOOTN_AUTH_EN | 16-ANTI_ROLLBACK_FEATURE_HYP_EN
    | 17-ANTI_ROLLBACK_FEATURE_SW_EN | 18-OEM_SEC_BOOT_FEC_EN | 19-OEM_SEC_BOOT_WRITE_DIS |
	
  @param[out]
    UINT32 Value, Each bit representing the blown status of fuse as per bit order or
    0x0 if error in reading the fuse bit, see param1 for error details
  @param1[out]
    UINT32 Value, 0x00 - Call Success
                  0x02 - FUSE Status Read Not Allowed
                  0x04 - Fuse Status Read Not Supported / Invalid Fuse

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define SAIL_BOOT_GET_FUSE_BIT_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_BOOT, SVC_NUM_4)

#define SAIL_BOOT_GET_FUSE_BIT_PARAM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_1(SAIL_SYSCALL_PARAM_TYPE_VAL)
	
/**
  @ingroup

  @brief HVC call to Get Fuse Register Value
  @smc_id  0x5001005

  @param_id 0x1

  @param[in]
    UINT32 value, Each value represent a set of bits to be read
    | 0-ROOT_CERT_ACTIVATION_LIST | 1-ROOT_CERT_REVOCATION_LIST | 2-ANTI_ROLLBACK_HYP_LSB
    | 3-ANTI_ROLLBACK_HYP_MSB | 4-ANTI_ROLLBACK_SW1_LSB | 5-ANTI_ROLLBACK_SW1_MSB
    | 6-ANTI_ROLLBACK_SW2_LSB | 7-ANTI_ROLLBACK_SW2_MSB | 8-ANTI_ROLLBACK_SW3_LSB
    | 9-ANTI_ROLLBACK_SW3_MSB | 10-ANTI_ROLLBACK_SW4_LSB | 11-ANTI_ROLLBACK_SW4_MSB
    | 12-ANTI_ROLLBACK_DEBUG | 13-PK_HASH0_0 | 16-PK_HASH0_1 | 17-PK_HASH0_2 | 18-PK_HASH0_3
    | 17-PK_HASH0_4 | 18-PK_HASH0_5 | 19-PK_HASH0_6 | 20-PK_HASH0_7 | 21-PK_HASH0_8
    | 22-PK_HASH0_9 | 23-PK_HASH0_10 | 24-PK_HASH0_11 | 25-PK_HASH0_12 | 26-PK_HASH0_13
    | 27-PK_HASH0_14 | 28-PK_HASH0_15 |
	
  @param[out]
    UINT32 Value represent the fuse value requested from param[in] or
	0x0 if error in reading the fuse bit, see param1 for error details
  @param1[out]
	UINT32 Value, 0x0  - Call Success
	0x02 - FUSE Status Read Not Allowed
	0x04 - Fuse Status Read Not Supported / Invalid Fuse

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define SAIL_BOOT_GET_FUSE_VAL_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_BOOT, SVC_NUM_5)

#define SAIL_BOOT_GET_FUSE_VAL_PARAM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_1(SAIL_SYSCALL_PARAM_TYPE_VAL)

/***===== SST service HVC IDs =====***/
/**
  @ingroup

  @brief HVC Call to call SST Test Wrapper Function

  @smc_id


  @param_id
    0x3

  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define SST_WRAPPER_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_SST, SVC_NUM_1)

#define SST_WRAPPER_PARAM_ID \
      SAIL_SYSCALL_CREATE_PARAM_ID_2( \
      SAIL_SYSCALL_PARAM_TYPE_VAL ,\
      SAIL_SYSCALL_PARAM_TYPE_VAL)

/***===== I2C service HVC IDs =====***/

/**
  @ingroup

  @brief HVC Call to call I2C_READ Wrapper Function

  @smc_id  0x5000B02


  @param_id 0x3


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define I2C_READ \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_I2C, SVC_NUM_1)

#define I2C_READ_PARM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_4( \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW)


/**
  @ingroup

  @brief HVC Call to call I2C_WRITE Function

  @smc_id  0x5000B03


  @param_id 0x3


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define I2C_WRITE \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_I2C, SVC_NUM_2)

#define I2C_WRITE_PARM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_4( \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW)

/**
  @ingroup

  @brief HVC Call to call get Ping status from slave connected

  @smc_id  0x5000B04


  @param_id 0x3


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define I2C_PING_STATUS \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_I2C, SVC_NUM_3)

#define I2C_PING_STATUS_PARM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_2( \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_VAL)

/**
  @ingroup

  @brief HVC Call to call to do I2cInit

  @smc_id  0x5000B05


  @param_id 0x3


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define I2C_DEINIT \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_I2C, SVC_NUM_4)

#define I2C_DEINIT_PARM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_1(\
      SAIL_SYSCALL_PARAM_TYPE_VAL)


/**
  @ingroup

  @brief HVC Call to call to do I2cDeInit

  @smc_id  0x5000B06


  @param_id 0x3


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define I2C_INIT \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_I2C, SVC_NUM_5)

#define I2C_INIT_PARM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_1(\
      SAIL_SYSCALL_PARAM_TYPE_VAL)


/***===== CHIPINFO Service HVC IDs =====***/

/**
  @ingroup
    SAIL_SVC_CHIPINFO

  @hvc_id
    0x05000C01

  @param_id
    0x0

  @param[in]
  None

  @return
     <> in response struct.
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define CHIPINFO_GET_CHIP_VERSION_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_CHIPINFO, SVC_NUM_1)

#define CHIPINFO_GET_CHIP_VERSION_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_0


/**
  @ingroup
    SAIL_SVC_CHIPINFO

  @hvc_id
    0x05000C02

  @param_id
    0x0

  @param[in]
  None

  @return
     <> in response struct.
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define CHIPINFO_GET_SAIL_CHIP_VERSION_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_CHIPINFO, SVC_NUM_2)

#define CHIPINFO_GET_SAIL_CHIP_VERSION_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_0


/**
  @ingroup
    SAIL_SVC_CHIPINFO

  @hvc_id
    0x05000C03

  @param_id
    0x0

  @param[in]
  None

  @return
     <> in response struct.
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define CHIPINFO_GET_CHIP_ID_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_CHIPINFO, SVC_NUM_3)

#define CHIPINFO_GET_CHIP_ID_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_0


/**
  @ingroup
    SAIL_SVC_CHIPINFO

  @hvc_id
    0x05000C04

  @param_id
    0x0

  @param[in]
  None

  @return
     <> in response struct.
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define CHIPINFO_GET_CHIP_FAMILY_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_CHIPINFO, SVC_NUM_4)

#define CHIPINFO_GET_CHIP_FAMILY_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_0


/**
  @ingroup
    SAIL_SVC_PLATFORMTYPE

  @hvc_id
    0x05000C05

  @param_id
    0x0

  @param[in]
  None

  @return
     <> in response struct.
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define CHIPINFO_GET_PLATFORM_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_CHIPINFO, SVC_NUM_5)

#define CHIPINFO_GET_PLATFORM_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_0

/***===== DBG Service HVC IDs =====***/

/**
  @ingroup
    SAIL_SVC_DBG

  @hvc_id
    0x0500FD01

  @param_id
    0x0

  @param[in]
  None

  @return
     <> in response struct.
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define CRASHDBG_DISDBG_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_DBG, SVC_NUM_1)

#define CRASHDBG_DISDBG_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_1( \
      SAIL_SYSCALL_PARAM_TYPE_VAL )

/***===== Trusens service HVC IDs =====***/
/**
  @ingroup

  @brief HVC call of TruSens
  @smc_id  0x05000D01


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define TRUSENS_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_TRUSENS, SVC_NUM_1)

#define TRUSENS_HVC_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_3( \
      SAIL_SYSCALL_PARAM_TYPE_VAL,\
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW,\
      SAIL_SYSCALL_PARAM_TYPE_VAL)

/***===== UART LOG LEVEL tests Service HVC IDs =====***/
/**
  @ingroup

  @brief HVC Call to call UART LOG LEVEL TEST Wrapper Function

  @smc_id  0x05008401


  @param_id 0x1


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define SAIL_LOGLEVEL_FUNC_TEST_TRAP \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_LOGLEVEL, SVC_NUM_1)

#define SAIL_LOGLEVEL_FUNC_TEST_TRAP_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_1( \
      SAIL_SYSCALL_PARAM_TYPE_VAL)
	  
/***===== Trusens eL2 TEST WRAPPER service HVC IDs =====***/
/**
  @ingroup

  @brief HVC call of EL2 test wrapper TruSens
  @smc_id  0x05008301


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define TRUSENS_EL2_TEST_WRAPPER_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_TRUSENS_TESTS, SVC_NUM_1)

#define TRUSENS_EL2_TEST_WRAPPER_HVC_PARAM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_0

/***===== Common service HVC IDs =====***/
/**
  @ingroup
  SAIL_SVC_CMN

  @brief HVC call of Common Syscall
  @smc_id  0x05001101


  @param_id 0x1


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define CACHE_INV_DATA_ADD_HVC_ID \
SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_CMN, SVC_NUM_1)

#define CACHE_INV_DATA_ADD_PARAM_ID \
        SAIL_SYSCALL_CREATE_PARAM_ID_1( \
             SAIL_SYSCALL_PARAM_TYPE_VAL )

/**
  @ingroup
  SAIL_SVC_CMN

  @brief HVC call of Common Syscall
  @smc_id  0x05001102


  @param_id 0x2


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define CACHE_CLEAN_DATA_RANGE_HVC_ID \
SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_CMN, SVC_NUM_2)

#define CACHE_CLEAN_DATA_RANGE_PARAM_ID \
        SAIL_SYSCALL_CREATE_PARAM_ID_2( \
             SAIL_SYSCALL_PARAM_TYPE_VAL, \
             SAIL_SYSCALL_PARAM_TYPE_VAL )

/**
  @ingroup
  SAIL_SVC_CMN

  @brief HVC call of Common Syscall
  @smc_id  0x05001103


  @param_id 0x2


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define CACHE_INV_DATA_RANGE_HVC_ID \
SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_CMN, SVC_NUM_3)

#define CACHE_INV_DATA_RANGE_PARAM_ID \
        SAIL_SYSCALL_CREATE_PARAM_ID_2( \
             SAIL_SYSCALL_PARAM_TYPE_VAL, \
             SAIL_SYSCALL_PARAM_TYPE_VAL )
/**
  @ingroup
  SAIL_SVC_CMN

  @brief HVC call of Common Syscall
  @smc_id  0x05001104


  @param_id 0x2


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define CACHE_CLEAN_INV_DATA_RANGE_HVC_ID \
SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_CMN, SVC_NUM_4)

#define CACHE_CLEAN_INV_DATA_RANGE_PARAM_ID \
        SAIL_SYSCALL_CREATE_PARAM_ID_2( \
             SAIL_SYSCALL_PARAM_TYPE_VAL, \
             SAIL_SYSCALL_PARAM_TYPE_VAL )

/***===== Boot Configuration HVC IDs =====***/
/**
  @ingroup

  @brief HVC call to Get Boot Configuration Info

  @smc_id  0x05001201

  @param_id 0x1

  @param[in]
    None.

  @return
     <> in response struct.
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define BOOTCFG_GET_MDBIST_CORE_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_BOOTCFG, SVC_NUM_1)
#define BOOTCFG_GET_MDBIST_CORE_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_0

/**
  @ingroup

  @brief HVC call to Get Cluster Config info

  @smc_id  0x05001202

  @param_id 0x1

  @param[in]
    None.

  @return
     <> in response struct.
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define GET_CLUSTER_CONFIG \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_BOOTCFG, SVC_NUM_2)
#define GET_CLUSTER_CONFIG_PARM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_1( \
      SAIL_SYSCALL_PARAM_TYPE_VAL )


/**
  @ingroup

  @brief Handles the trap call events

  @smc_id  0x05001901


  @param_id  0x0

  @param eventID [IN]
    SAIL bootcfg Trap Event ID

  @param handle [IN/OUT]
    Pointer to SAIL boot cfg utils service interface handle as an input parameter.
    Pointer to internal SAIL boot cfg refernce count upon return

  @return
    Result of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define SAIL_GET_CAPT_SEC_GPIO \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_BOOTCFG, SVC_NUM_3)

#define SAIL_GET_CAPT_SEC_GPIO_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_0

/**
  @ingroup

  @brief Handles the trap call events

  @smc_id  0x05001902


  @param_id  0x0

  @param [IN]
    None.

  @return
    <> in response struct.
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define SAIL_READ_MPIDR \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_BOOTCFG, SVC_NUM_4)

#define SAIL_READ_MPIDR_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_0
/***===== ICB HVC IDs =====***/
/**
  @ingroup
 
  @brief HVC to access SAIL NOC registers
 
  @return
    NOC error inforamtion
*/

#define ICB_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_ICB, SVC_NUM_1)

#define ICB_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_2( \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW )

/***===== Vsens service HVC IDs =====***/
/**
  @ingroup

  @brief HVC call of Vsens
  @smc_id  0x05000501


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define VSENS_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_VSENS, SVC_NUM_1)

#define VSENS_HVC_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_2( \
      SAIL_SYSCALL_PARAM_TYPE_VAL,\
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW )

/**
  @ingroup

  @brief HVC call of Vsens
  @smc_id  0x05000502


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define VSENS_TEST_AUTOCAL_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_VSENS, SVC_NUM_2)

#define VSENS_TEST_AUTOCAL_HVC_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_2( \
      SAIL_SYSCALL_PARAM_TYPE_VAL,\
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW )

/**
  @ingroup

  @brief HVC call of Vsens
  @smc_id  0x05000503


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define VSENS_TEST_GET_OL_VOLT_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_VSENS, SVC_NUM_3)

#define VSENS_TEST_GET_OL_VOLT_HVC_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_3( \
      SAIL_SYSCALL_PARAM_TYPE_VAL,\
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW, \
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW )

/**
  @ingroup

  @brief HVC call of Vsens
  @smc_id  0x05000504


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define VSENS_TEST_FUSE_GET_CODES_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_VSENS, SVC_NUM_4)

#define VSENS_TEST_FUSE_GET_CODES_HVC_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_4( \
      SAIL_SYSCALL_PARAM_TYPE_VAL,\
      SAIL_SYSCALL_PARAM_TYPE_VAL,\
      SAIL_SYSCALL_PARAM_TYPE_VAL,\
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW )

/**
  @ingroup

  @brief HVC call of Vsens
  @smc_id  0x05000505


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define VSENS_TEST_EXTRAPOLATE_TO_MV_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_VSENS, SVC_NUM_5)

#define VSENS_TEST_EXTRAPOLATE_TO_MV_HVC_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_1( \
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW )

/**
  @ingroup

  @brief HVC call of Vsens
  @smc_id  0x05000506

  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define VSENS_TEST_GET_THRESHOLD_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_VSENS, SVC_NUM_6)


#define VSENS_TEST_GET_THRESHOLD_HVC_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_3( \
      SAIL_SYSCALL_PARAM_TYPE_VAL,\
      SAIL_SYSCALL_PARAM_TYPE_VAL,\
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW)

/**
  @ingroup

  @brief HVC call of Vsens
  @smc_id  0x05000507

  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define VSENS_TEST_GET_THRESHOLD_ISR_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_VSENS, SVC_NUM_7)


#define VSENS_TEST_GET_THRESHOLD_ISR_HVC_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_3( \
      SAIL_SYSCALL_PARAM_TYPE_VAL,\
      SAIL_SYSCALL_PARAM_TYPE_VAL,\
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW)

/**
  @ingroup

  @brief HVC call of Vsens
  @smc_id  0x05000508

  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define VSENS_TEST_GET_SENSOR_RESET_STATE_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_VSENS, SVC_NUM_8)


#define VSENS_TEST_GET_SENSOR_RESET_STATE_HVC_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_1( \
      SAIL_SYSCALL_PARAM_TYPE_VAL)

/**
  @ingroup

  @brief HVC call of Vsens
  @smc_id  0x05000509

  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define VSENS_TEST_SET_THRESH_EN_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_VSENS, SVC_NUM_9)


#define VSENS_TEST_SET_THRESH_EN_HVC_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_1( \
      SAIL_SYSCALL_PARAM_TYPE_VAL)
/**
  @ingroup

  @brief HVC call of Vsens
  @smc_id  0x0500050A

  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define VSENS_TEST_IRQ_FORCE_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_VSENS, SVC_NUM_10)


#define VSENS_TEST_IRQ_FORCE_HVC_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_4( \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_VAL)

/**
  @ingroup

  @brief HVC call of Vsens
  @smc_id  0x0500050B

  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define VSENS_TEST_SET_SENSOR_THRESH_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_VSENS, SVC_NUM_11)


#define VSENS_TEST_SET_SENSOR_THRESH_HVC_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_4( \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_VAL)

/**
  @ingroup

  @brief HVC call of Vsens
  @smc_id  0x0500050C

  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define VSENS_TEST_GET_SENSOR_THRESH_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_VSENS, SVC_NUM_12)


#define VSENS_TEST_GET_SENSOR_THRESH_HVC_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_4( \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW)

/**
  @ingroup

  @brief HVC call of Vsens
  @smc_id  0x0500050D

  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define VSENS_TEST_SET_ALARM_EN_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_VSENS, SVC_NUM_13)


#define VSENS_TEST_SET_ALARM_EN_HVC_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_3( \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_VAL)

/**
  @ingroup

  @brief HVC call of Vsens
  @smc_id  0x0500050E

  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define VSENS_TEST_DIS_EN_VCOFILTER_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_VSENS, SVC_NUM_14)


#define VSENS_TEST_DIS_EN_VCOFILTER_HVC_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_2( \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_VAL)

/***===== Acmu eL2 TEST WRAPPER service HVC IDs =====***/
/**
  @ingroup

  @brief HVC call of EL2 test wrapper Acmu
  @smc_id  0x05008501


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define ACMU_EL2_TEST_SAIL_PLL_LOCK_WRAPPER_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_ACMU_TEST, SVC_NUM_1)

#define ACMU_EL2_TEST_SAIL_PLL_LOCK_WRAPPER_HVC_PARAM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_0
	
/**
  @ingroup

  @brief HVC call of EL2 test wrapper Acmu
  @smc_id  0x05008502


  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define ACMU_EL2_TEST_SAIL_PLL_UNLOCK_WRAPPER_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_ACMU_TEST, SVC_NUM_2)

#define ACMU_EL2_TEST_SAIL_PLL_UNLOCK_WRAPPER_HVC_PARAM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_0	
	
/**
  @ingroup

  @brief HVC call of EL2 test wrapper Acmu
  @smc_id  0x05008503


  @param_id 0x2


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define ACMU_EL2_TEST_SAIL_BCR_CONTROL_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_ACMU_TEST, SVC_NUM_3)

#define ACMU_EL2_TEST_SAIL_BCR_CONTROL_HVC_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_2( \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_VAL)	
  
/***===== ISD service HVC IDs =====***/

/**
  @ingroup

  @brief HVC Call to call ISD EL2  Wrapper Function

  @smc_id  0x5008103


  @param_id 0x3


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define ISD_WRAPPER_POLL_MDPSHOLD_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_ISD, SVC_NUM_1)

#define ISD_WRAPPER_POLL_MDPSHOLD_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_0



/***===== CPR service HVC IDs =====***/
/**
  @ingroup

  @brief HVC call of CPR
  @smc_id  0x05000D01

  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define CPR_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_CPR, SVC_NUM_1)

#define CPR_HVC_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_3( \
      SAIL_SYSCALL_PARAM_TYPE_VAL,\
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW,\
      SAIL_SYSCALL_PARAM_TYPE_VAL)
	  
/***===== Access Control Service HVC IDs =====***/
/**
  @ingroup
  SAIL_SVC_AC
  
  brief HVC Call to call SAIL AC Monitoring from SM


  @hvc_id  

  @param_id 0x0

  @return
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define SAIL_AC_SM_TRIGGER_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_AC, SVC_NUM_1)

#define SAIL_AC_SM_TRIGGER_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_0
  
/**
  @ingroup
  SAIL_SVC_AC
  
  brief HVC Call to call SAIL AC MSA GV calculation after TZ BOOT Success in ISD


  @hvc_id  

  @param_id 0x0

  @return
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define SAIL_AC_GV_TRIGGER_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_AC, SVC_NUM_2)

#define SAIL_AC_GV_TRIGGER_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_0

/***===== UCLIB service HVC IDs =====***/
/**
  @ingroup

  @brief HVC Call to call UCLIB API Functions

  @smc_id  
    

  @param_id 
    0x3

  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define PRNG_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_UCLIB, SVC_NUM_1)

#define PRNG_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_2( \
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW, SAIL_SYSCALL_PARAM_TYPE_VAL )


/***===== SHE service HVC IDs =====***/
/**
  @ingroup

  @brief HVC call of SHE_open
  @smc_id  


  @param_id 
   0x0

  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define SHE_OPEN_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_SHE, SVC_NUM_1)

#define SHE_OPEN_PARAM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_3( \
      SAIL_SYSCALL_PARAM_TYPE_VAL ,\
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW,\
      SAIL_SYSCALL_PARAM_TYPE_VAL )

/**
  @ingroup

  @brief HVC call of SHE_verify_key_table
  @smc_id  


  @param_id 
   0x0

  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define SHE_VERIFY_KEY_TABLE_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_SHE, SVC_NUM_2)

#define SHE_VERIFY_KEY_TABLE_PARAM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_3( \
      SAIL_SYSCALL_PARAM_TYPE_VAL ,\
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW,\
      SAIL_SYSCALL_PARAM_TYPE_VAL )

/**
  @ingroup

  @brief HVC call of SHE _verify_key_table
  @smc_id  


  @param_id 
   0x0

  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define SHE_SET_SS_HW_FAULT_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_SHE, SVC_NUM_3)

#define SHE_SET_SS_HW_FAULT_PARAM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_0

/**
  @ingroup

  @brief HVC call of SHE_commit
  @smc_id  


  @param_id 
   0x0

  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define SHE_COMMIT_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_SHE, SVC_NUM_4)

#define SHE_COMMIT_PARAM_ID \
    SAIL_SYSCALL_CREATE_PARAM_ID_3( \
      SAIL_SYSCALL_PARAM_TYPE_VAL ,\
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW ,\
      SAIL_SYSCALL_PARAM_TYPE_VAL)

/**
  @ingroup

  @brief HVC call of SHE_setRAM_Key
  @smc_id  


  @param_id 
   0x3

  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define SHE_SET_RAMKEY_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_SHE, SVC_NUM_5)

#define SHE_SET_RAMKEY_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_3( \
    SAIL_SYSCALL_PARAM_TYPE_BUF_RW,\
    SAIL_SYSCALL_PARAM_TYPE_VAL,\
    SAIL_SYSCALL_PARAM_TYPE_VAL)

/**
  @ingroup

  @brief HVC call of SHE_crypto_operation
  @smc_id  


  @param_id 
   0x4

  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define SHE_CRYPTO_OP_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_SHE, SVC_NUM_6)

#define SHE_CRYPTO_OP_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_4( \
    SAIL_SYSCALL_PARAM_TYPE_VAL,\
    SAIL_SYSCALL_PARAM_TYPE_VAL,\
    SAIL_SYSCALL_PARAM_TYPE_VAL,\
    SAIL_SYSCALL_PARAM_TYPE_BUF_RW)

/**
  @ingroup

  @brief HVC call of SHE_provision_key
  @smc_id  


  @param_id 
   0x1

  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define SHE_PROVISION_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_SHE, SVC_NUM_7)

#define SHE_PROVISION_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_1( \
    SAIL_SYSCALL_PARAM_TYPE_BUF_RW)

/**
  @ingroup

  @brief HVC call of SHE_export_ram_key
  @smc_id  


  @param_id 
   0x1

  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define SHE_EXPORT_RAMKEY_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_SHE, SVC_NUM_8)

#define SHE_EXPORT_RAMKEY_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_1( \
    SAIL_SYSCALL_PARAM_TYPE_BUF_RW)
    
/**
  @ingroup

  @brief HVC call of CSHE_set_key_valid_parameter
  @smc_id  


  @param_id 
   0x3

  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define SHE_SET_KEY_VALID_PARAMETER_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_SHE, SVC_NUM_9)

#define SHE_SET_KEY_VALID_PARAMETER_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_2( \
    SAIL_SYSCALL_PARAM_TYPE_VAL,\
    SAIL_SYSCALL_PARAM_TYPE_BUF_RW)

/***===== Secure Storage HVC IDs =====***/
/**
  @ingroup

  @brief HVC to set main partition header
    
  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define SECURE_STORAGE_SET_MPH_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_SECURE_STORAGE, SVC_NUM_1)

#define SECURE_STORAGE_SET_MPH_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_3( \
      SAIL_SYSCALL_PARAM_TYPE_BUF_RO, \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW)

/**
  @ingroup

  @brief HVC to initialize main paritition header

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define SECURE_STORAGE_INIT_MPH_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_SECURE_STORAGE, SVC_NUM_2)

#define SECURE_STORAGE_INIT_MPH_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_3( \
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW, \
      SAIL_SYSCALL_PARAM_TYPE_VAL,  \
      SAIL_SYSCALL_PARAM_TYPE_VAL)

/**
  @ingroup

  @brief HVC to create a new client partition

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define SECURE_STORAGE_CREATE_PARTITION_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_SECURE_STORAGE, SVC_NUM_3)

#define SECURE_STORAGE_CREATE_PARTITION_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_6( \
       SAIL_SYSCALL_PARAM_TYPE_VAL, \
       SAIL_SYSCALL_PARAM_TYPE_BUF_RO, \
       SAIL_SYSCALL_PARAM_TYPE_VAL, \
       SAIL_SYSCALL_PARAM_TYPE_VAL, \
       SAIL_SYSCALL_PARAM_TYPE_BUF_RW, \
       SAIL_SYSCALL_PARAM_TYPE_VAL)

/**
  @ingroup

  @brief HVC for opening client partition

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define SECURE_STORAGE_OPEN_PARTITION_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_SECURE_STORAGE, SVC_NUM_4)

#define SECURE_STORAGE_OPEN_PARTITION_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_4( \
       SAIL_SYSCALL_PARAM_TYPE_VAL, \
       SAIL_SYSCALL_PARAM_TYPE_BUF_RW, \
       SAIL_SYSCALL_PARAM_TYPE_VAL, \
       SAIL_SYSCALL_PARAM_TYPE_BUF_RW )

/**
  @ingroup

  @brief HVC for closing client partition

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define SECURE_STORAGE_CLOSE_PARTITION_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_SECURE_STORAGE, SVC_NUM_5)

#define SECURE_STORAGE_CLOSE_PARTITION_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_1( \
      SAIL_SYSCALL_PARAM_TYPE_VAL)

/**
  @ingroup

  @brief HVC to get client partition offset

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define SECURE_STORAGE_GET_CLIENT_PARTITION_OFFSET_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_SECURE_STORAGE, SVC_NUM_6)

#define SECURE_STORAGE_GET_CLIENT_PARTITION_OFFSET_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_4( \
       SAIL_SYSCALL_PARAM_TYPE_VAL, \
       SAIL_SYSCALL_PARAM_TYPE_VAL, \
       SAIL_SYSCALL_PARAM_TYPE_VAL, \
       SAIL_SYSCALL_PARAM_TYPE_BUF_RW )

/**
  @ingroup

  @brief HVC to increment client partition version

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define SECURE_STORAGE_INCREMENT_CLIENT_PARTITION_VER_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_SECURE_STORAGE, SVC_NUM_7)

#define SECURE_STORAGE_INCREMENT_CLIENT_PARTITION_VER_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_3( \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW, \
      SAIL_SYSCALL_PARAM_TYPE_VAL)

/**
  @ingroup

  @brief HVC to blow client ARB fuse

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define SECURE_STORAGE_BLOW_CLIENT_ARB_FUSE_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_SECURE_STORAGE, SVC_NUM_8)

#define SECURE_STORAGE_BLOW_CLIENT_ARB_FUSE_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_1( \
      SAIL_SYSCALL_PARAM_TYPE_VAL)

/**
  @ingroup

  @brief HVC for secure storage tests

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define SECURE_STORAGE_TEST_WRAPPER_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_SECURE_STORAGE_TEST, SVC_NUM_1)

#define SECURE_STORAGE_TEST_WRAPPER_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_3( \
      SAIL_SYSCALL_PARAM_TYPE_VAL, \
      SAIL_SYSCALL_PARAM_TYPE_BUF_RW, \
      SAIL_SYSCALL_PARAM_TYPE_VAL)

/***===== Syscall Test service HVC IDs =====***/
/**
  @ingroup

  @brief HVC call of Syscall Test
  @smc_id  0x0500FE01

  @param_id 0x0


  @param[in]
    None.

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/
#define SYSCALL_TEST_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_TEST_0, SVC_NUM_1)

#define SYSCALL_TEST_HVC_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_1( \
      SAIL_SYSCALL_PARAM_TYPE_VAL)

/***===== CDT HVC IDs =====***/
/**
  @ingroup

  @brief used for getting CDT info from Hyp

  @return
    status of the operation
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define CDT_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_CDT, SVC_NUM_1)

#define CDT_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_1( \
      SAIL_SYSCALL_PARAM_TYPE_VAL )


/***===== TSC Service HVC IDs =====***/
/**
  @ingroup
    SAIL_SVC_CHIPINFO

  @hvc_id
    
  @param_id
    
  @param[in]
  None

  @return
     <> in response struct.
    SUCCESS if the call succeeded; an error code otherwise.
*/

#define TSC_GET_REG_AHB_CBCR_HVC_ID                                                                   \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_TSC_REG, SVC_NUM_1)

#define TSC_SET_REG_AHB_CBCR_HVC_ID                                                                   \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_TSC_REG, SVC_NUM_2)

#define TSC_GET_REG_CNTR_CBCR_HVC_ID                                                                  \
    SAIL_SYSCALL_CREATE_HVC_ID(SAIL_TSC_REG, SVC_NUM_3)

#define TSC_SET_REG_CNTR_CBCR_HVC_ID                                                                  \
    SAIL_SYSCALL_CREATE_HVC_ID(SAIL_TSC_REG, SVC_NUM_4)

#define SYSCALL_TSC_GET_REG_PARAM_ID                                                                  \
    SAIL_SYSCALL_CREATE_PARAM_ID_1(SAIL_SYSCALL_PARAM_TYPE_VAL)

#define SYSCALL_TSC_SET_REG_PARAM_ID                                                                  \
    SAIL_SYSCALL_CREATE_PARAM_ID_2(SAIL_SYSCALL_PARAM_TYPE_VAL, SAIL_SYSCALL_PARAM_TYPE_VAL)

/***===== SBIST HVC IDs =====***/
/**
  @ingroup
 
  @brief HVC to access ARM RTL SBIST
 
  @return
    NSBIST resultO
*/

#define SBIST_HVC_ID \
  SAIL_SYSCALL_CREATE_HVC_ID(SAIL_SVC_SBIST, SVC_NUM_1)

#define SBIST_PARAM_ID \
  SAIL_SYSCALL_CREATE_PARAM_ID_1( \
      SAIL_SYSCALL_PARAM_TYPE_VAL)

#endif /* _SAILHYP_SYSCALL_PUB_H_ */
