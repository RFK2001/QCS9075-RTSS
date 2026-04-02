/**************************************************************************************************
    Copyright (c) Qualcomm Technologies, Inc.
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
**************************************************************************************************/

/*=================================================================================================
    File Name          : common_functions.h
    Component Name     : Common Functions
    Description        : Header file for common functions
    $Header: 
    $DateTime: 
    $Author: 
==================================================================================================*/
/* Include header file guard */
#ifndef ARCH_DEFS_H
#define ARCH_DEFS_H

/**
 * Constants for CPSR mode bits.
 */
#define CPSR_MODE_MASK             0x1FU

#define CPSR_MODE_USR              0x10U
#define CPSR_MODE_FIQ              0x11U
#define CPSR_MODE_IRQ              0x12U
#define CPSR_MODE_SVC              0x13U
#define CPSR_MODE_ABT              0x17U
#define CPSR_MODE_HYP              0x1AU
#define CPSR_MODE_UND              0x1BU
#define CPSR_MODE_SYS              0x1FU

#define SYS_MODE_STACK_SIZE                 2048U
#define IRQ_MODE_STACK_SIZE                 1024U
#define SVC_MODE_STACK_SIZE                 4096U
#define ABT_MODE_STACK_SIZE                 1024U

#define DAIFSET_D_BIT           0x08    /* Debug exception mask bit */
#define DAIFSET_A_BIT           0x04    /* SError mask bit */
#define DAIFSET_I_BIT           0x02    /* IRQ mask bit */
#define DAIFSET_F_BIT           0x01    /* FIQ mask bit */


#define SCTLR_DCACHE_MASK                ( (uint32_t)1U << 2U )
#define SCTLR_ICACHE_MASK                ( (uint32_t)1U << 12U )


#define PSTATE_ABORT_INTR_MASK         ( 1U << 8U )
#define PSTATE_IRQ_INTR_MASK           ( 1U << 7U )
#define PSTATE_FIQ_INTR_MASK           ( 1U << 6U )


#endif