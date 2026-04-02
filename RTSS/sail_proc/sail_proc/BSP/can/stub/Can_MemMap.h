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
#define MEMMAP_VENDOR_ID   39u
#define MEMMAP_MODULE_ID    0u

#define MEMMAP_AR_RELEASE_MAJOR_VERSION     4u
#define MEMMAP_AR_RELEASE_MINOR_VERSION     8u
#define MEMMAP_AR_RELEASE_REVISION_VERSION  0u

#define MEMMAP_SW_MAJOR_VERSION     1u
#define MEMMAP_SW_MINOR_VERSION     0u
#define MEMMAP_SW_PATCH_VERSION     0u
#endif

/* Memory map */
#define MEMMAP_ERROR

/* Sections */
#ifdef CAN_STOP_SEC_CODE_ASIL_B
    #undef CAN_STOP_SEC_CODE_ASIL_B
    #undef MEMMAP_ERROR
    #ifdef CAN_START_SEC_CODE_ASIL_B
        #undef CAN_MEMMAP_SECTION_STARTED
        #undef CAN_START_SEC_CODE_ASIL_B
    #else
        //#error "No corresponding memory section STARTed before STOP."
    #endif
    /* No section end keyword. */
#elif defined CAN_START_SEC_CODE_ASIL_B
    #undef MEMMAP_ERROR
    #ifndef CAN_MEMMAP_SECTION_STARTED
        #define CAN_MEMMAP_SECTION_STARTED
    #else
      //#error "Previous memory section should be STOPed before STARTing new one."
    #endif
    __attribute__((section("can_code")))
#elif defined CAN_STOP_SEC_CALLOUT_CODE_ASIL_B
    #undef CAN_STOP_SEC_CALLOUT_CODE_ASIL_B
    #undef MEMMAP_ERROR
    #ifdef CAN_START_SEC_CALLOUT_CODE_ASIL_B
        #undef CAN_MEMMAP_SECTION_STARTED
        #undef CAN_START_SEC_CALLOUT_CODE_ASIL_B
    #else
        //#error "No corresponding memory section STARTed before STOP."
    #endif
    /* No section end keyword. */
#elif defined CAN_START_SEC_CALLOUT_CODE_ASIL_B
    #undef MEMMAP_ERROR
    #ifndef CAN_MEMMAP_SECTION_STARTED
        #define CAN_MEMMAP_SECTION_STARTED
    #else
      //#error "Previous memory section should be STOPed before STARTing new one."
    #endif
    __attribute__((section(".can_callout_code")))
#elif defined CAN_STOP_SEC_VAR_INIT_ASIL_B_BOOLEAN
    #undef CAN_STOP_SEC_VAR_INIT_ASIL_B_BOOLEAN
    #undef MEMMAP_ERROR
    #ifdef CAN_START_SEC_VAR_INIT_ASIL_B_BOOLEAN
        #undef CAN_MEMMAP_SECTION_STARTED
        #undef CAN_START_SEC_VAR_INIT_ASIL_B_BOOLEAN
    #else
        //#error "No corresponding memory section STARTed before STOP."
    #endif
    /* No section end keyword. */
#elif defined CAN_START_SEC_VAR_INIT_ASIL_B_BOOLEAN
    #undef MEMMAP_ERROR
    #ifndef CAN_MEMMAP_SECTION_STARTED
        #define CAN_MEMMAP_SECTION_STARTED
    #else
      //#error "Previous memory section should be STOPed before STARTing new one."
    #endif
    __attribute__((section("can_data")))
#elif defined CAN_STOP_SEC_VAR_INIT_ASIL_B_8
    #undef CAN_STOP_SEC_VAR_INIT_ASIL_B_8
    #undef MEMMAP_ERROR
    #ifdef CAN_START_SEC_VAR_INIT_ASIL_B_8
        #undef CAN_MEMMAP_SECTION_STARTED
        #undef CAN_START_SEC_VAR_INIT_ASIL_B_8
    #else
        //#error "No corresponding memory section STARTed before STOP."
    #endif
    /* No section end keyword. */
#elif defined CAN_START_SEC_VAR_INIT_ASIL_B_8
    #undef MEMMAP_ERROR
    #ifndef CAN_MEMMAP_SECTION_STARTED
        #define CAN_MEMMAP_SECTION_STARTED
    #else
      //#error "Previous memory section should be STOPed before STARTing new one."
    #endif
    __attribute__((section("can_data")))
#elif defined CAN_STOP_SEC_VAR_INIT_ASIL_B_16
    #undef CAN_STOP_SEC_VAR_INIT_ASIL_B_16
    #undef MEMMAP_ERROR
    #ifdef CAN_START_SEC_VAR_INIT_ASIL_B_16
        #undef CAN_MEMMAP_SECTION_STARTED
        #undef CAN_START_SEC_VAR_INIT_ASIL_B_16
    #else
        //#error "No corresponding memory section STARTed before STOP."
    #endif
    /* No section end keyword. */
#elif defined CAN_START_SEC_VAR_INIT_ASIL_B_16
    #undef MEMMAP_ERROR
    #ifndef CAN_MEMMAP_SECTION_STARTED
        #define CAN_MEMMAP_SECTION_STARTED
    #else
      //#error "Previous memory section should be STOPed before STARTing new one."
    #endif
    __attribute__((section("can_data")))
#elif defined CAN_STOP_SEC_VAR_INIT_ASIL_B_32
    #undef CAN_STOP_SEC_VAR_INIT_ASIL_B_32
    #undef MEMMAP_ERROR
    #ifdef CAN_START_SEC_VAR_INIT_ASIL_B_32
        #undef CAN_MEMMAP_SECTION_STARTED
        #undef CAN_START_SEC_VAR_INIT_ASIL_B_32
    #else
        //#error "No corresponding memory section STARTed before STOP."
    #endif
    /* No section end keyword. */
#elif defined CAN_START_SEC_VAR_INIT_ASIL_B_32
    #undef MEMMAP_ERROR
    #ifndef CAN_MEMMAP_SECTION_STARTED
        #define CAN_MEMMAP_SECTION_STARTED
    #else
      //#error "Previous memory section should be STOPed before STARTing new one."
    #endif
    __attribute__((section("can_data")))
#elif defined CAN_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
    #undef CAN_STOP_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
    #undef MEMMAP_ERROR
    #ifdef CAN_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
        #undef CAN_MEMMAP_SECTION_STARTED
        #undef CAN_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
    #else
        //#error "No corresponding memory section STARTed before STOP."
    #endif
    /* No section end keyword. */
#elif defined CAN_START_SEC_VAR_INIT_ASIL_B_UNSPECIFIED
    #undef MEMMAP_ERROR
    #ifndef CAN_MEMMAP_SECTION_STARTED
        #define CAN_MEMMAP_SECTION_STARTED
    #else
      //#error "Previous memory section should be STOPed before STARTing new one."
    #endif
    __attribute__((section("can_data")))
#elif defined CAN_STOP_SEC_VAR_CLEARED_ASIL_B_PTR
    #undef CAN_STOP_SEC_VAR_CLEARED_ASIL_B_PTR
    #undef MEMMAP_ERROR
    #ifdef CAN_START_SEC_VAR_CLEARED_ASIL_B_PTR
        #undef CAN_MEMMAP_SECTION_STARTED
        #undef CAN_START_SEC_VAR_CLEARED_ASIL_B_PTR
    #else
        //#error "No corresponding memory section STARTed before STOP."
    #endif
    /* No section end keyword. */
#elif defined CAN_START_SEC_VAR_CLEARED_ASIL_B_PTR
    #undef MEMMAP_ERROR
    #ifndef CAN_MEMMAP_SECTION_STARTED
        #define CAN_MEMMAP_SECTION_STARTED
    #else
      //#error "Previous memory section should be STOPed before STARTing new one."
    #endif
    __attribute__((section("can_const_ptr")))
#elif defined CAN_STOP_SEC_VAR_CLEARED_ASIL_B_8
    #undef CAN_STOP_SEC_VAR_CLEARED_ASIL_B_8
    #undef MEMMAP_ERROR
    #ifdef CAN_START_SEC_VAR_CLEARED_ASIL_B_8
        #undef CAN_MEMMAP_SECTION_STARTED
        #undef CAN_START_SEC_VAR_CLEARED_ASIL_B_8
    #else
        //#error "No corresponding memory section STARTed before STOP."
    #endif
    /* No section end keyword. */
#elif defined CAN_START_SEC_VAR_CLEARED_ASIL_B_8
    #undef MEMMAP_ERROR
    #ifndef CAN_MEMMAP_SECTION_STARTED
        #define CAN_MEMMAP_SECTION_STARTED
    #else
      //#error "Previous memory section should be STOPed before STARTing new one."
    #endif
    __attribute__((section("can_data")))
#elif defined CAN_STOP_SEC_VAR_CLEARED_ASIL_B_16
    #undef CAN_STOP_SEC_VAR_CLEARED_ASIL_B_16
    #undef MEMMAP_ERROR
    #ifdef CAN_START_SEC_VAR_CLEARED_ASIL_B_16
        #undef CAN_MEMMAP_SECTION_STARTED
        #undef CAN_START_SEC_VAR_CLEARED_ASIL_B_16
    #else
        //#error "No corresponding memory section STARTed before STOP."
    #endif
    /* No section end keyword. */
#elif defined CAN_START_SEC_VAR_CLEARED_ASIL_B_16
    #undef MEMMAP_ERROR
    #ifndef CAN_MEMMAP_SECTION_STARTED
        #define CAN_MEMMAP_SECTION_STARTED
    #else
      //#error "Previous memory section should be STOPed before STARTing new one."
    #endif
    __attribute__((section("can_data")))
#elif defined CAN_STOP_SEC_VAR_CLEARED_ASIL_B_32
    #undef CAN_STOP_SEC_VAR_CLEARED_ASIL_B_32
    #undef MEMMAP_ERROR
    #ifdef CAN_START_SEC_VAR_CLEARED_ASIL_B_32
        #undef CAN_MEMMAP_SECTION_STARTED
        #undef CAN_START_SEC_VAR_CLEARED_ASIL_B_32
    #else
        //#error "No corresponding memory section STARTed before STOP."
    #endif
    /* No section end keyword. */
#elif defined CAN_START_SEC_VAR_CLEARED_ASIL_B_32
    #undef MEMMAP_ERROR
    #ifndef CAN_MEMMAP_SECTION_STARTED
        #define CAN_MEMMAP_SECTION_STARTED
    #else
      //#error "Previous memory section should be STOPed before STARTing new one."
    #endif
    __attribute__((section("can_data")))
#elif defined CAN_STOP_SEC_VAR_CLEARED_ASIL_B_UNSPECIFIED
    #undef CAN_STOP_SEC_VAR_CLEARED_ASIL_B_UNSPECIFIED
    #undef MEMMAP_ERROR
    #ifdef CAN_START_SEC_VAR_CLEARED_ASIL_B_UNSPECIFIED
        #undef CAN_MEMMAP_SECTION_STARTED
        #undef CAN_START_SEC_VAR_CLEARED_ASIL_B_UNSPECIFIED
    #else
        //#error "No corresponding memory section STARTed before STOP."
    #endif
    /* No section end keyword. */
#elif defined CAN_START_SEC_VAR_CLEARED_ASIL_B_UNSPECIFIED
    #undef MEMMAP_ERROR
    #ifndef CAN_MEMMAP_SECTION_STARTED
        #define CAN_MEMMAP_SECTION_STARTED
    #else
      //#error "Previous memory section should be STOPed before STARTing new one."
    #endif
    __attribute__((section("can_data")))
#elif defined CAN_STOP_SEC_CONST_ASIL_B_8
    #undef CAN_STOP_SEC_CONST_ASIL_B_8
    #undef MEMMAP_ERROR
    #ifdef CAN_START_SEC_CONST_ASIL_B_8
        #undef CAN_MEMMAP_SECTION_STARTED
        #undef CAN_START_SEC_CONST_ASIL_B_8
    #else
        //#error "No corresponding memory section STARTed before STOP."
    #endif
    /* No section end keyword. */
#elif defined CAN_START_SEC_CONST_ASIL_B_8
    #undef MEMMAP_ERROR
    #ifndef CAN_MEMMAP_SECTION_STARTED
        #define CAN_MEMMAP_SECTION_STARTED
    #else
      //#error "Previous memory section should be STOPed before STARTing new one."
    #endif
	__attribute__((section("can_const_data")))
#elif defined CAN_STOP_SEC_CONST_ASIL_B_32
    #undef CAN_STOP_SEC_CONST_ASIL_B_32
    #undef MEMMAP_ERROR
    #ifdef CAN_START_SEC_CONST_ASIL_B_32
        #undef CAN_MEMMAP_SECTION_STARTED
        #undef CAN_START_SEC_CONST_ASIL_B_32
    #else
        //#error "No corresponding memory section STARTed before STOP."
    #endif
    /* No section end keyword. */
#elif defined CAN_START_SEC_CONST_ASIL_B_32
    #undef MEMMAP_ERROR
    #ifndef CAN_MEMMAP_SECTION_STARTED
        #define CAN_MEMMAP_SECTION_STARTED
    #else
      //#error "Previous memory section should be STOPed before STARTing new one."
    #endif
	__attribute__((section("can_const_data")))
#elif defined CAN_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_B_UNSPECIFIED
    #undef CAN_STOP_SEC_CONFIG_DATA_PREBUILD_ASIL_B_UNSPECIFIED
    #undef MEMMAP_ERROR
    #ifdef CAN_START_SEC_CONFIG_DATA_PREBUILD_ASIL_B_UNSPECIFIED
        #undef CAN_MEMMAP_SECTION_STARTED
        #undef CAN_START_SEC_CONFIG_DATA_PREBUILD_ASIL_B_UNSPECIFIED
    #else
        //#error "No corresponding memory section STARTed before STOP."
    #endif
    /* No section end keyword. */
#elif defined CAN_START_SEC_CONFIG_DATA_PREBUILD_ASIL_B_UNSPECIFIED
    #undef MEMMAP_ERROR
    #ifndef CAN_MEMMAP_SECTION_STARTED
        #define CAN_MEMMAP_SECTION_STARTED
    #else
      //#error "Previous memory section should be STOPed before STARTing new one."
    #endif
    __attribute__((section("can_data")))
#elif defined CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
    #undef CAN_STOP_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
    #undef MEMMAP_ERROR
    #ifdef CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
        #undef CAN_MEMMAP_SECTION_STARTED
        #undef CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
    #else
        //#error "No corresponding memory section STARTed before STOP."
    #endif
    /* No section end keyword. */
#elif defined CAN_START_SEC_CONFIG_DATA_POSTBUILD_ASIL_B_UNSPECIFIED
    #undef MEMMAP_ERROR
    #ifndef CAN_MEMMAP_SECTION_STARTED
        #define CAN_MEMMAP_SECTION_STARTED
    #else
      //#error "Previous memory section should be STOPed before STARTing new one."
    #endif
    __attribute__((section("can_data")))
#elif defined CAN_STOP_SEC_DMA_DATA_ASIL_B_UNSPECIFIED
    #undef CAN_STOP_SEC_DMA_DATA_ASIL_B_UNSPECIFIED
    #undef MEMMAP_ERROR
    #ifdef CAN_START_SEC_DMA_DATA_ASIL_B_UNSPECIFIED
        #undef CAN_MEMMAP_SECTION_STARTED
        #undef CAN_START_SEC_DMA_DATA_ASIL_B_UNSPECIFIED
    #else
        //#error "No corresponding memory section STARTed before STOP."
    #endif
    /* No section end keyword. */
#elif defined CAN_START_SEC_DMA_DATA_ASIL_B_UNSPECIFIED
    #undef MEMMAP_ERROR
    #ifndef CAN_MEMMAP_SECTION_STARTED
        #define CAN_MEMMAP_SECTION_STARTED
    #else
      //#error "Previous memory section should be STOPed before STARTing new one."
    #endif
    __attribute__((section("can_dma_sram_data")))
#elif defined CAN_STOP_SEC_DMA_DDR_DATA_ASIL_B_UNSPECIFIED
    #undef CAN_STOP_SEC_DMA_DDR_DATA_ASIL_B_UNSPECIFIED
    #undef MEMMAP_ERROR
    #ifdef CAN_START_SEC_DMA_DDR_DATA_ASIL_B_UNSPECIFIED
        #undef CAN_MEMMAP_SECTION_STARTED
        #undef CAN_START_SEC_DMA_DDR_DATA_ASIL_B_UNSPECIFIED
    #else
        //#error "No corresponding memory section STARTed before STOP."
    #endif
    /* No section end keyword. */
#elif defined CAN_START_SEC_DMA_DDR_DATA_ASIL_B_UNSPECIFIED
    #undef MEMMAP_ERROR
    #ifndef CAN_MEMMAP_SECTION_STARTED
        #define CAN_MEMMAP_SECTION_STARTED
    #else
      //#error "Previous memory section should be STOPed before STARTing new one."
    #endif
    __attribute__((section("can_dma_ddr_data")))
#endif    

#ifdef MEMMAP_ERROR
    //#error "Valid memory mapping symbol is not defined."
#endif




#ifdef __cplusplus
}
#endif
