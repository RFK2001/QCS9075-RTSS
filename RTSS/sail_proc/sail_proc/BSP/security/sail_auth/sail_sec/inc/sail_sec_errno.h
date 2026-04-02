/*===========================================================================
 Copyright (c) 2018, 2022 Qualcomm Technologies, Inc.
 All Rights Reserved.
 Confidential and Proprietary - Qualcomm Technologies, Inc.
===========================================================================*/
#ifndef SAIL_SEC_ERRNO_H
#define SAIL_SEC_ERRNO_H

/* Logging modules (16 total) */
#define KERNEL          (0x0) /* Kernel/Platform errors       */
#define IMG_AUTH        (0x2)
#define AC              (0x3) /* Access Control */
#define UNUSED_MODULE_4 (0x4) 
#define CRYPTO_BAM      (0x6)
#define UNUSED_MODULE_9 (0x9)
#define UNUSED_MODULE_A (0xA)
#define UNUSED_MODULE_B (0xB)
#define UNUSED_MODULE_C (0xC)
#define UNUSED_MODULE_D (0xD)
#define UNUSED_MODULE_E (0xE)
#define UNUSED_MODULE_F (0xF)


/* Error code bit layout
 ________________________ __________________ ______
|                        |                  |      |
|31--------------------16|15---------------4|3----0|
|        Reserved        |      Error #     |Module|
|________________________|__________________|______|

*/
#define EC_NUM_BMSK     (0x0FFFFFFF)
#define EC_NUM_SHFT     (4)
#define EC_MODULE_BMSK  (0x0000000F)
#define ERROR_CODE(num, module) \
  (((num & EC_NUM_BMSK) << EC_NUM_SHFT) | (module & EC_MODULE_BMSK))

/* Kernel Error codes */
#define LOG_ERR_MAX_ARGS                                ERROR_CODE(0, KERNEL)
#define PRNG_ERR_INVALID_PARAMETERS                     ERROR_CODE(1, KERNEL)
#define PRNG_ERR_GENERATE_STACK_CANARY_FAILED           ERROR_CODE(2, KERNEL)
#define WLIST_ERR_WLIST_FULL                            ERROR_CODE(3, KERNEL)
#define WLIST_ERR_INT_OVERFLOW                          ERROR_CODE(4, KERNEL)
#define WLIST_ERR_NOT_4K_ALIGNED                        ERROR_CODE(5, KERNEL)
#define WLIST_ERR_UPDATE_FAILED                         ERROR_CODE(6, KERNEL)
#define MMU_ERR_INVALID_PARAM                           ERROR_CODE(7, KERNEL)
#define MMU_ERR_L2_PAGE_TABLE_FULL                      ERROR_CODE(8, KERNEL)
#define MMU_ERR_L3_PAGE_TABLE_FULL                      ERROR_CODE(9, KERNEL)
#define MMU_ERR_ADDRESS_UNMAPPED                        ERROR_CODE(10, KERNEL)
#define SMC_ERR_LOG_SMC_ID                              ERROR_CODE(11, KERNEL)
#define SMC_ERR_LOG_SMC_REQUEST                         ERROR_CODE(12, KERNEL)
#define SMC_ERR_LOG_SMC_RESPONSE                        ERROR_CODE(13, KERNEL)
#define INIT_ERR_INIT_FUNC_FAILED                       ERROR_CODE(14, KERNEL)
#define MILESTONE_ERR_INCORRECT_SIZE                    ERROR_CODE(15, KERNEL)
#define MILESTONE_ERR_INVALID_TZ_ENTRY_ADDR             ERROR_CODE(16, KERNEL)
#define MILESTONE_ERR_MAP_TZ_FAILED                     ERROR_CODE(17, KERNEL)
#define MILESTONE_ERR_INVALID_BOOT_FLOW                 ERROR_CODE(18, KERNEL)
#define MILESTONE_ERR_INVALID_APPS_INDEX                ERROR_CODE(19, KERNEL)

/** xbl_sec eld mode smc call, edl_enable: %d */
#define SMC_ERR_EDL_MODE                                ERROR_CODE(21, KERNEL)   

/** v.v (err_ctx_t*) : %x */
#define SMC_CONTEXT_FATAL_ERROR                         ERROR_CODE(22, KERNEL)
/** Fatal error 0x%x */  
//#define XBL_SEC_FATAL_ERROR                             ERROR_CODE(23, KERNEL)  
#define HYP_WLIST_UPDATE_FAILED                         ERROR_CODE(24, KERNEL) 

/* Image authentication Error codes */
#define IMG_AUTH_ERR_OVERLAPS_BLACKLIST                 ERROR_CODE(0, IMG_AUTH)
#define IMG_AUTH_ERR_OVERFLOW                           ERROR_CODE(1, IMG_AUTH)
#define IMG_AUTH_ERR_MAPPING_FAILED                     ERROR_CODE(2, IMG_AUTH)
#define IMG_AUTH_ERR_ELF_FORMAT                         ERROR_CODE(3, IMG_AUTH)
#define IMG_AUTH_ERR_INVALID_HASH_ARGS                  ERROR_CODE(4, IMG_AUTH)
#define IMG_AUTH_ERR_HASH_CALC                          ERROR_CODE(5, IMG_AUTH)
#define IMG_AUTH_ERR_UNMAP_FAILED                       ERROR_CODE(6, IMG_AUTH)
#define IMG_AUTH_ERR_NO_METADATA_SPACE                  ERROR_CODE(7, IMG_AUTH)
#define IMG_AUTH_ERR_NO_HASH_SEGMENT                    ERROR_CODE(8, IMG_AUTH)
#define IMG_AUTH_ERR_SHARED_INFO_NO_SPACE               ERROR_CODE(9, IMG_AUTH)
#define IMG_AUTH_ERR_PARTIAL_HASH_INVALID_ARG           ERROR_CODE(10, IMG_AUTH)
#define IMG_AUTH_ERR_PARTIAL_HASH_CRYPTO_INIT_FAIL      ERROR_CODE(11, IMG_AUTH)
#define IMG_AUTH_ERR_PARTIAL_HASH_CRYPTO_UPDATE_FAIL    ERROR_CODE(12, IMG_AUTH)
#define IMG_AUTH_ERR_PARTIAL_HASH_CRYPTO_FINAL_FAIL     ERROR_CODE(13, IMG_AUTH)
#define IMG_AUTH_ERR_PARTIAL_HASH_CRYPTO_COMPARE_FAIL   ERROR_CODE(14, IMG_AUTH)
#define IMG_AUTH_ERR_PARTIAL_HASH_CRYPTO_DEINIT_FAIL    ERROR_CODE(15, IMG_AUTH)
#define IMG_AUTH_ERR_PARALLEL_HASH_INVALID_ARG          ERROR_CODE(16, IMG_AUTH)
#define IMG_AUTH_ERR_PARALLEL_HASH_CRYPTO_INIT_FAIL     ERROR_CODE(17, IMG_AUTH)
#define IMG_AUTH_ERR_PARALLEL_HASH_CRYPTO_SETPARAM_FAIL ERROR_CODE(18, IMG_AUTH)
#define IMG_AUTH_ERR_PARALLEL_HASH_CRYPTO_UPDATE_FAIL   ERROR_CODE(19, IMG_AUTH)
#define IMG_AUTH_ERR_PARALLEL_HASH_CRYPTO_FINAL_FAIL    ERROR_CODE(20, IMG_AUTH)
#define IMG_AUTH_ERR_PARALLEL_HASH_CRYPTO_DEINIT_FAIL   ERROR_CODE(21, IMG_AUTH)
#define IMG_AUTH_ERR_PARALLEL_HASH_CRYPTO_COMPARE_FAIL  ERROR_CODE(22, IMG_AUTH)
#define IMG_AUTH_ERR_PARTIAL_HASH_INVALID_NUM_SEGMENTS  ERROR_CODE(23, IMG_AUTH)
#define IMG_AUTH_ERR_IMAGE_POST_VERIFICATION_FAIL       ERROR_CODE(24, IMG_AUTH)
#define IMG_AUTH_ERR_INVALID_NUM_SEGMENTS               ERROR_CODE(25, IMG_AUTH)
#define IMG_AUTH_ERR_INVALID_BUF_ADDRESS                ERROR_CODE(26, IMG_AUTH)
#define IMG_AUTH_ERR_INVALID_ELF                        ERROR_CODE(27, IMG_AUTH)
#define IMG_AUTH_ERR_INVALID_HASH_TABLE_HEADER_LEN      ERROR_CODE(28, IMG_AUTH)

/* Call TZ Error codes*/
#define TZ_ENTRY_ADDR_ALIGNMENT_CHECK_FAIL              ERROR_CODE(0, TZ_ENTRY)

/* Crypto Bam error codes */
#define BAMCORE_CRYPTO_INIT_FAILED                      ERROR_CODE(0, CRYPTO_BAM)

#endif /* SAIL_SEC_ERRNO_H */
