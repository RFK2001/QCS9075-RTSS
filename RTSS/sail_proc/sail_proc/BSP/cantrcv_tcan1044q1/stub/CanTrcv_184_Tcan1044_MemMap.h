/*
    ===========================================================================

    Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
    All Rights Reserved.
    Confidential and Proprietary - Qualcomm Technologies, Inc.

    Export of this technology or software is regulated by the U.S. Government.
    Diversion contrary to U.S. law prohibited.

    All ideas, data and information contained in or disclosed by
    this document are confidential and proprietary information of
    Qualcomm Technologies, Inc. and all rights therein are expressly reserved.
    By accepting this material the recipient agrees that this material
    and the information contained therein are held in confidence and in
    trust and will not be used, copied, reproduced in whole or in part,
    nor its contents revealed in any manner to others without the express
    written permission of Qualcomm Technologies, Inc.

    ===========================================================================

    $Header:   $
    $DateTime:  $
    $Author:   $

    ===========================================================================
*/

#ifdef __cplusplus
extern "C"{
#endif
/*=============================================================================
|                       INCLUDE FILES                                         |
=============================================================================*/



/*=============================================================================
|                       EXPORTED CONSTANTS and MACROS                         |
=============================================================================*/
/* [SWS_BSW_00059] Published information elements. */
#ifndef MEMMAP_AR_RELEASE_MAJOR_VERSION
#define MEMMAP_VENDOR_ID  0xB8u
#define MEMMAP_MODULE_ID  0x46u

#define MEMMAP_AR_RELEASE_MAJOR_VERSION     4u
#define MEMMAP_AR_RELEASE_MINOR_VERSION     8u
#define MEMMAP_AR_RELEASE_REVISION_VERSION  0u

#define MEMMAP_SW_MAJOR_VERSION     1u
#define MEMMAP_SW_MINOR_VERSION     2u
#define MEMMAP_SW_PATCH_VERSION     0u
#endif

/* Memory map */
#define MEMMAP_ERROR

/* Sections */
#ifdef CANTRCV_184_TCAN1044_STOP_SEC_CODE
    #undef CANTRCV_184_TCAN1044_STOP_SEC_CODE
    #undef MEMMAP_ERROR
    #ifdef CANTRCV_184_TCAN1044_START_SEC_CODE
        #undef CANTRCV_184_TCAN1044_MEMMAP_SECTION_STARTED
        #undef CANTRCV_184_TCAN1044_START_SEC_CODE
    #else
        //#error "No corresponding memory section STARTed before STOP."
    #endif
    /* No section end keyword. */
#elif defined CANTRCV_184_TCAN1044_START_SEC_CODE
    #undef MEMMAP_ERROR
    #ifndef CANTRCV_184_TCAN1044_MEMMAP_SECTION_STARTED
        #define CANTRCV_184_TCAN1044_MEMMAP_SECTION_STARTED
    #else
      //#error "Previous memory section should be STOPed before STARTing new one."
    #endif
    __attribute__((section(".cantrcv_184_tcan1044_code")))
#elif defined CANTRCV_184_TCAN1044_STOP_SEC_CODE_FAST
    #undef CANTRCV_184_TCAN1044_STOP_SEC_CODE_FAST
    #undef MEMMAP_ERROR
    #ifdef CANTRCV_184_TCAN1044_START_SEC_CODE_FAST
        #undef CANTRCV_184_TCAN1044_MEMMAP_SECTION_STARTED
        #undef CANTRCV_184_TCAN1044_START_SEC_CODE_FAST
    #else
        //#error "No corresponding memory section STARTed before STOP."
    #endif
    /* No section end keyword. */
#elif defined CANTRCV_184_TCAN1044_START_SEC_CODE_FAST
    #undef MEMMAP_ERROR
    #ifndef CANTRCV_184_TCAN1044_MEMMAP_SECTION_STARTED
        #define CANTRCV_184_TCAN1044_MEMMAP_SECTION_STARTED
    #else
      //#error "Previous memory section should be STOPed before STARTing new one."
    #endif
    __attribute__((section(".cantrcv_184_tcan1044_code_fast")))
#elif defined CANTRCV_184_TCAN1044_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    #undef CANTRCV_184_TCAN1044_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR
    #ifdef CANTRCV_184_TCAN1044_START_SEC_VAR_NO_INIT_UNSPECIFIED
        #undef CANTRCV_184_TCAN1044_MEMMAP_SECTION_STARTED
        #undef CANTRCV_184_TCAN1044_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #else
        //#error "No corresponding memory section STARTed before STOP."
    #endif
    /* No section end keyword. */
#elif defined CANTRCV_184_TCAN1044_START_SEC_VAR_NO_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR
    #ifndef CANTRCV_184_TCAN1044_MEMMAP_SECTION_STARTED
        #define CANTRCV_184_TCAN1044_MEMMAP_SECTION_STARTED
    #else
      //#error "Previous memory section should be STOPed before STARTing new one."
    #endif
    __attribute__((section("can_data")))
#elif defined CANTRCV_184_TCAN1044_STOP_SEC_VAR_INIT_8
    #undef CANTRCV_184_TCAN1044_STOP_SEC_VAR_INIT_8
    #undef MEMMAP_ERROR
    #ifdef CANTRCV_184_TCAN1044_START_SEC_VAR_INIT_8
        #undef CANTRCV_184_TCAN1044_MEMMAP_SECTION_STARTED
        #undef CANTRCV_184_TCAN1044_START_SEC_VAR_INIT_8
    #else
        //#error "No corresponding memory section STARTed before STOP."
    #endif
    /* No section end keyword. */
#elif defined CANTRCV_184_TCAN1044_START_SEC_VAR_INIT_8
    #undef MEMMAP_ERROR
    #ifndef CANTRCV_184_TCAN1044_MEMMAP_SECTION_STARTED
        #define CANTRCV_184_TCAN1044_MEMMAP_SECTION_STARTED
    #else
      //#error "Previous memory section should be STOPed before STARTing new one."
    #endif
    __attribute__((section("can_data")))
#elif defined CANTRCV_184_TCAN1044_STOP_SEC_CONST_NO_INIT_UNSPECIFIED
    #undef CANTRCV_184_TCAN1044_STOP_SEC_CONST_NO_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR
    #ifdef CANTRCV_184_TCAN1044_START_SEC_CONST_NO_INIT_UNSPECIFIED
        #undef CANTRCV_184_TCAN1044_MEMMAP_SECTION_STARTED
        #undef CANTRCV_184_TCAN1044_START_SEC_CONST_NO_INIT_UNSPECIFIED
    #else
        //#error "No corresponding memory section STARTed before STOP."
    #endif
    /* No section end keyword. */
#elif defined CANTRCV_184_TCAN1044_START_SEC_CONST_NO_INIT_UNSPECIFIED
    #undef MEMMAP_ERROR
    #ifndef CANTRCV_184_TCAN1044_MEMMAP_SECTION_STARTED
        #define CANTRCV_184_TCAN1044_MEMMAP_SECTION_STARTED
    #else
      //#error "Previous memory section should be STOPed before STARTing new one."
    #endif
    __attribute__((section("can_const_ptr")))
#elif defined CANTRCV_184_TCAN1044_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #undef CANTRCV_184_TCAN1044_STOP_SEC_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR
    #ifdef CANTRCV_184_TCAN1044_START_SEC_CONFIG_DATA_UNSPECIFIED
        #undef CANTRCV_184_TCAN1044_MEMMAP_SECTION_STARTED
        #undef CANTRCV_184_TCAN1044_START_SEC_CONFIG_DATA_UNSPECIFIED
    #else
        //#error "No corresponding memory section STARTed before STOP."
    #endif
    /* No section end keyword. */
#elif defined CANTRCV_184_TCAN1044_START_SEC_CONFIG_DATA_UNSPECIFIED
    #undef MEMMAP_ERROR
    #ifndef CANTRCV_184_TCAN1044_MEMMAP_SECTION_STARTED
        #define CANTRCV_184_TCAN1044_MEMMAP_SECTION_STARTED
    #else
      //#error "Previous memory section should be STOPed before STARTing new one."
    #endif
	__attribute__((section("can_const_data")))
#endif

#ifdef MEMMAP_ERROR
    //#error "Valid memory mapping symbol is not defined."
#endif

#ifdef __cplusplus
}
#endif
