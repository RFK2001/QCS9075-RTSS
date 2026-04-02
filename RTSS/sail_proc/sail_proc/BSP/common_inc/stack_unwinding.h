/*
@file stack_unwinding.h

*/
 /*        Copyright (c) 2023-2025 Qualcomm Technologies, Inc.
 *             All Rights Reserved.
 *        Qualcomm Technologies Inc. Proprietary and Confidential.
 */
 
 
/*===========================================================================
                              Include files
=============================================================================*/

#include <stdint.h>

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

//This unwinds the call stack and prints the function address
void stack_unwind(void);
