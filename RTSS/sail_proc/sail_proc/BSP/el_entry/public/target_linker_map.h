/**
 * @file target_linker_map.h
 * @brief For Linker definitions related to memory map.
 *
 *        Copyright (c) 2021 - 2023 Qualcomm Technologies, Inc.
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

#ifndef TARGET_LINKER_MAP_H
#define TARGET_LINKER_MAP_H

/*===========================================================================
                           INCLUDE FILES
===========================================================================*/
#include "types.h"
#include "sail_mem_map.h"

/*===========================================================================
                            MACROS
===========================================================================*/
#ifdef XBL_USE_WHITELIST
#define INVALID_WHITELIST_ADDRESS   0xFFFFFFFF
#define INVALID_WHITELIST_SIZE      0x0

/**
 * @brief Ondemand whitelist start address and size for different softwares
 * 
 *  TODO: Need to take care of multiple regios and starts
 * 
 */
#define ONDEMAND_SW1_LR1_START INVALID_WHITELIST_ADDRESS
#define ONDEMAND_SW1_LR1_SIZE  INVALID_WHITELIST_SIZE

#define ONDEMAND_SW2_LR1_START INVALID_WHITELIST_ADDRESS
#define ONDEMAND_SW2_LR1_SIZE  INVALID_WHITELIST_SIZE

#define ONDEMAND_SW3_LR1_START INVALID_WHITELIST_ADDRESS
#define ONDEMAND_SW3_LR1_SIZE  INVALID_WHITELIST_SIZE

#define ONDEMAND_SW4_LR1_START INVALID_WHITELIST_ADDRESS
#define ONDEMAND_SW4_LR1_SIZE  INVALID_WHITELIST_SIZE
#endif
/**
 * @brief Mandatory whitelist start address and size for different softwares
 * 
 */
#ifdef XBL_USE_WHITELIST
#define MANDATORY_SW1_LR1_START 0x080E1000U
#define MANDATORY_SW1_LR1_SIZE  0x64000U

#define MANDATORY_SW1_LR3_START 0x2000000U
#define MANDATORY_SW1_LR3_SIZE  0x10000U

#define MANDATORY_SW1_LR4_START 0x2100000U
#define MANDATORY_SW1_LR4_SIZE  0x8000U

#define MANDATORY_SW1_LR5_START 0x2200000U
#define MANDATORY_SW1_LR5_SIZE  0x8000U

#define MANDATORY_SW2_LR1_START 0x08145000U
#define MANDATORY_SW2_LR1_SIZE  0xFA000U

#define MANDATORY_SW2_LR3_START 0x2400000U
#define MANDATORY_SW2_LR3_SIZE  0x10000U

#define MANDATORY_SW2_LR4_START 0x2500000U
#define MANDATORY_SW2_LR4_SIZE  0x8000U

#define MANDATORY_SW2_LR5_START 0x2600000U
#define MANDATORY_SW2_LR5_SIZE  0x8000U

#define MANDATORY_SW3_LR1_START 0x0823F000U
#define MANDATORY_SW3_LR1_SIZE  0x8C000U

#define MANDATORY_SW3_LR3_START 0x3000000U
#define MANDATORY_SW3_LR3_SIZE  0x10000U

#define MANDATORY_SW3_LR4_START 0x3100000U
#define MANDATORY_SW3_LR4_SIZE  0x8000U

#define MANDATORY_SW3_LR5_START 0x3200000U
#define MANDATORY_SW3_LR5_SIZE  0x8000U

#define MANDATORY_SW4_LR1_START INVALID_WHITELIST_ADDRESS
#define MANDATORY_SW4_LR1_SIZE  INVALID_WHITELIST_SIZE
#endif

/*===========================================================================
                           TYPEDEFS
===========================================================================*/
/* Thie is the ENUM that is used as identifiers for IMAGES running on SAIL SS */

/*===========================================================================
                            EXTERN
===========================================================================*/

/* Linker Symbols memory map */

#if defined(__ARM_GNU__)

    /* Stack */
    extern uint32_t lnk_stack_top;
    extern uint32_t lnk_stack_bottom;
    #define SAILBSP_STACK_SIZE          (uint32_t)((uint32_t)(&lnk_stack_top) - (uint32_t)(&lnk_stack_bottom))    /* 32KB for all the cores sail hyp stack, per core 8kB */
    #define SAILBSP_STACK_END           (uint32_t)(&lnk_stack_top)                                                /* Stack at the end of the SAILS memory           */
    #define SAILBSP_STACK_BASE          (uint32_t)(&lnk_stack_bottom)

    /* Heap */
    extern uint32_t lnk_sailbsp_heap_start;
    extern uint32_t lnk_sailbsp_heap_end;
    #define SAILBSP_HEAP_SIZE           (uint32_t)((uint32_t)(&lnk_sailbsp_heap_end) - (uint32_t)(&lnk_sailbsp_heap_start)) /* 64KB */
    #define SAILBSP_HEAP_BASE           (uint32_t)(&lnk_sailbsp_heap_start)                                                 /* right above the stack section */
    #define SAILBSP_HEAP_END            (uint32_t)(&lnk_sailbsp_heap_end)

    /* Syscall Table */
    extern uint32_t lnk_syscall_table_start_addr;
    extern uint32_t lnk_syscall_table_end_addr;
    #define SYSCALL_TABLE_START         (uint32_t)(&lnk_syscall_table_start_addr)
    #define SYSCALL_TABLE_END           (uint32_t)(&lnk_syscall_table_end_addr)
    #define SYSCALL_TABLE_LENGTH        (uint32_t)((uint32_t)(&lnk_syscall_table_end_addr) - (uint32_t)(&lnk_syscall_table_start_addr)) 

    /* EL2 Specific Defines */
    #ifdef SAILEL2
    #endif

    /* EL1 Specific Defines */
    #ifdef SAILSW1
    #endif

#elif defined(__ARM_FUSA__)

    /* Common define for EL1 and EL2 */
    /* Stack */
    extern unsigned int Image$$ARM_LIB_STACK$$ZI$$Length;
    extern unsigned int Image$$ARM_LIB_STACK$$ZI$$Limit;
    extern unsigned int Image$$ARM_LIB_STACK$$ZI$$Base;
    #define SAILBSP_STACK_SIZE         (uint32_t)&Image$$ARM_LIB_STACK$$ZI$$Length    /* 32KB for all the cores sail hyp stack, per core 8kB */
    #define SAILBSP_STACK_END          (uint32_t)&Image$$ARM_LIB_STACK$$ZI$$Limit     /* Stack at the end of the SAILS memory           */
    #define SAILBSP_STACK_BASE         (uint32_t)&Image$$ARM_LIB_STACK$$ZI$$Base

    /* Heap */
    /*extern unsigned int Image$$SAILHYP_HEAP$$ZI$$Length;
    extern unsigned int Image$$SAILHYP_HEAP$$ZI$$Base;
    extern unsigned int Image$$SAILHYP_HEAP$$ZI$$Limit;*/
    #define SAILBSP_HEAP_SIZE          (uint32_t)&Image$$SAILHYP_HEAP$$ZI$$Length /* 64KB */
    #define SAILBSP_HEAP_BASE          (uint32_t)&Image$$SAILHYP_HEAP$$ZI$$Base   /* right above the stack section */
    #define SAILBSP_HEAP_END           (uint32_t)&Image$$SAILHYP_HEAP$$ZI$$Limit

    /* Syscall Table */
    extern uint32_t Image$$syscall_table$$Base;
    extern uint32_t Image$$syscall_table$$Limit;
    extern uint32_t Image$$syscall_table$$Length;
    #define SYSCALL_TABLE_START        (uint32_t)&Image$$syscall_table$$Base
    #define SYSCALL_TABLE_END          (uint32_t)&Image$$syscall_table$$Limit
    #define SYSCALL_TABLE_LENGTH       (uint32_t)&Image$$syscall_table$$Length

    /* Reclaim Region */    
    extern unsigned int Image$$lnkRECLAIMDATAStartAddr$$ZI$$Base;
    extern unsigned int Image$$lnkRECLAIMDATAEndAddr$$ZI$$Base;

    /* EL2 Specific Defines */
    #ifdef SAILEL2
    
    extern unsigned int Image$$lnkEL2ROEndAddr$$ZI$$Base;
    extern unsigned int Image$$lnkSDIDATAStartAddr$$ZI$$Base;
    
    #endif /* SAILEL2 */

    /* EL1 Specific Defines */
    #ifdef SAILSW1
    
    extern unsigned int Image$$lnkSMAPPDATAStartAddr$$ZI$$Base;
    extern unsigned int Image$$lnkSMAPPDATAEndAddr$$ZI$$Base;
    #define SAILBSP_SM_APP_DATA_ADDR_BASE        (UBaseType_t)&Image$$lnkSMAPPDATAStartAddr$$ZI$$Base
    #define SAILBSP_SM_APP_DATA_ADDR_SIZE        (UBaseType_t)( (uint32_t)&Image$$lnkSMAPPDATAEndAddr$$ZI$$Base -\
                                                                (uint32_t)&Image$$lnkSMAPPDATAStartAddr$$ZI$$Base )

    extern unsigned int Image$$lnkMBOSHStartAddr$$RO$$Base;
    extern unsigned int Image$$lnkMBOSHEndAddr$$RO$$Base;
    #define SAILBSP_MBOSH_ADDR_BASE              (UBaseType_t)&Image$$lnkMBOSHStartAddr$$RO$$Base
    #define SAILBSP_MBOSH_ADDR_SIZE              (UBaseType_t)( (uint32_t)&Image$$lnkMBOSHEndAddr$$RO$$Base -\
                                                                (uint32_t)&Image$$lnkMBOSHStartAddr$$RO$$Base )

    extern unsigned int Image$$lnkUSERUNPRIVCODEStartAddr$$RO$$Base;
    extern unsigned int Image$$lnkUSERUNPRIVCODEEndAddr$$RO$$Base;
    #define SAILBSP_UNPRIV_CODE_ADDR_BASE              (UBaseType_t)&Image$$lnkUSERUNPRIVCODEStartAddr$$RO$$Base
    #define SAILBSP_UNPRIV_CODE_ADDR_SIZE              (UBaseType_t)( (uint32_t)&Image$$lnkUSERUNPRIVCODEEndAddr$$RO$$Base -\
                                                                (uint32_t)&Image$$lnkUSERUNPRIVCODEStartAddr$$RO$$Base )

    extern unsigned int Image$$lnkATCM_UNPRIVStartAddr$$RO$$Base;
    extern unsigned int Image$$lnkATCM_UNPRIVEndAddr$$RO$$Base;
    #define SAILBSP_ATCM_CODE_ADDR_BASE              (UBaseType_t)&Image$$lnkATCM_UNPRIVStartAddr$$RO$$Base
    #define SAILBSP_ATCM_CODE_ADDR_SIZE              (UBaseType_t)( (uint32_t)&Image$$lnkATCM_UNPRIVEndAddr$$RO$$Base -\
                                                                (uint32_t)&Image$$lnkATCM_UNPRIVStartAddr$$RO$$Base )

    extern unsigned int Image$$lnkCTCM_UNPRIVStartAddr$$RO$$Base;
    extern unsigned int Image$$lnkCTCM_UNPRIVEndAddr$$RO$$Base;
    #define SAILBSP_CTCM_CODE_ADDR_BASE              (UBaseType_t)&Image$$lnkCTCM_UNPRIVStartAddr$$RO$$Base
    #define SAILBSP_CTCM_CODE_ADDR_SIZE              (UBaseType_t)( (uint32_t)&Image$$lnkCTCM_UNPRIVEndAddr$$RO$$Base -\
                                                                (uint32_t)&Image$$lnkCTCM_UNPRIVStartAddr$$RO$$Base )
    #endif /* SAILSW1 */

#else
    #error "Unknown Linker Symbols Format"
#endif

#endif
