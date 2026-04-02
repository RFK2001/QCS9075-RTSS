/*
 * FreeRTOS Kernel V11.0.1
 * Copyright (C) 2021 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 */
 
/*
 * Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
 * All rights reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

    .text
    .arm

    /* Includes */
    #include "FreeRTOSConfig.h"

    .set SYS_MODE,  0x1f
    .set SVC_MODE,  0x13
    .set IRQ_MODE,  0x12
    
    .set MPIDR_CLUSTER_MASK,        0xFF00
    .set MPIDR_CLUSTER_SHFT,        8
    .set MPIDR_CPU_MASK,            0xFF
    .set MPIDR_CLUSTER_CPUID_SHFT,  0x7

    /* Variables and functions. */
    .extern ulMaxAPIPriorityMask
    .extern _freertos_vector_table

#if ( configNUMBER_OF_CORES > 1 )
    .extern pxCurrentTCBs
    .extern xTaskGetCurrentTaskHandleForCore
#else   
    .extern pxCurrentTCB
#endif /* configNUMBER_OF_CORES > 1 */

    .extern vTaskSwitchContext
    .extern vApplicationIRQHandler
    .extern ulPortInterruptNesting

#if defined( __ARM_FP )
    .extern ulPortTaskHasFPUContext
#endif /* __ARM_FP */

    .global FreeRTOS_IRQ_Handler
    .global FreeRTOS_SVC_Handler
    .global vPortRestoreTaskContext
    .global ulPortGetCurrentCoreID
    .global ulPortGetCurrentClusterID

.macro portSAVE_CONTEXT

    /* Save the LR and SPSR onto the system mode stack before switching to
    system mode to save the remaining system mode registers. */
    SRSDB   sp!, #SYS_MODE
    CPS     #SYS_MODE
    PUSH    {R0-R12, R14}

    /* Push the critical nesting count. */
    LDR     R2, ulCriticalNestingConst
    LDR     R1, [R2]
    PUSH    {R1}

    #if defined( __ARM_FP )
        /* Does the task have a floating point context that needs saving?  If
        ulPortTaskHasFPUContext is 0 then no. */
        LDR     R2, ulPortTaskHasFPUContextConst
        LDR     R3, [R2]
        CMP     R3, #0

        /* Save the floating point context, if any. */
        FMRXNE  R1,  FPSCR
        PUSHNE  {R1}
        VPUSHNE {D0-D15}
        VPUSHNE {D16-D31}

        /* Save ulPortTaskHasFPUContext itself. */
        PUSH    {R3}
    #endif /* __ARM_FP */

    /* Save the stack pointer in the TCB. */
    #if ( configNUMBER_OF_CORES > 1 )
        BLX     ulPortGetCurrentCoreID
        BLX     xTaskGetCurrentTaskHandleForCore
        STR     SP, [R0]
    #else
        LDR     R0, pxCurrentTCBConst
        LDR     R1, [R0]
        STR     SP, [R1]
    #endif /* configNUMBER_OF_CORES > 1 */

    .endm

; /**********************************************************************/

.macro portRESTORE_CONTEXT

    /* Set the SP to point to the stack of the task being restored. */
    #if ( configNUMBER_OF_CORES > 1 )
        BLX     ulPortGetCurrentCoreID
        BLX     xTaskGetCurrentTaskHandleForCore
        LDR     SP, [R0]
    #else
        LDR     R0, pxCurrentTCBConst
        LDR     R1, [R0]    /* R1 contains pointer to top of the stack */
        LDR     SP, [R1]
    #endif /* configNUMBER_OF_CORES > 1 */

    #if defined( __ARM_FP )
        /*
         * Is there a floating point context to restore?  If the restored
         * ulPortTaskHasFPUContext is zero then no.
         */
        LDR     R0, ulPortTaskHasFPUContextConst
        POP     {R1}
        STR     R1, [R0]
        CMP     R1, #0

        /* Restore the floating point context, if any. */
        VPOPNE  {D16-D31}
        VPOPNE  {D0-D15}
        POPNE   {R0}
        VMSRNE  FPSCR, R0
    #endif /* __ARM_FP */

    /* Restore the critical section nesting depth. */
    LDR     R0, ulCriticalNestingConst
    POP     {R1}
    STR     R1, [R0]

    /* Ensure the priority mask is correct for the critical nesting depth. */
    CMP     R1, #0
    MOVEQ   R4, #255
    LDRNE   R4, ulMaxAPIPriorityMaskConst
    LDRNE   R4, [R4]
    /* update ICCPMR Priority */
    MCR     p15, 0, R4, c4, c6, 0
    ISB
    DSB

    /* Restore all system mode registers other than the SP (which is already
    being used). */
    POP     {R0-R12, R14}

    /* Return to the task code, loading CPSR on the way. */
    RFEIA   sp!

    .endm


/******************************************************************************
 * SVC handler is used to start the scheduler.
 *****************************************************************************/
.align 4
.type FreeRTOS_SVC_Handler, %function
FreeRTOS_SVC_Handler:
    /* Save the context of the current task and select a new task to run. */
    portSAVE_CONTEXT

    /* Ensure bit 2 of the stack pointer is clear. */
    MOV     r2, sp
    AND     r2, r2, #4
    SUB     sp, sp, r2

    #if ( configNUMBER_OF_CORES > 1 )
        BLX     ulPortGetCurrentCoreID       /* R0 = Core number */  
    #endif /* configNUMBER_OF_CORES > 1 */

    LDR R3, vTaskSwitchContextConst
    BLX R3

    portRESTORE_CONTEXT


/******************************************************************************
 * vPortRestoreTaskContext is used to start the scheduler.
 *****************************************************************************/
.type vPortRestoreTaskContext, %function
vPortRestoreTaskContext:
    /* Switch to system mode. */
    CPS     #SYS_MODE
    portRESTORE_CONTEXT

.align 4
.type FreeRTOS_IRQ_Handler, %function
FreeRTOS_IRQ_Handler:

    /* Return to the interrupted instruction. */
    SUB     lr, lr, #4

    /* Push the return address and SPSR. */
    PUSH    {lr}
    MRS     lr, SPSR
    PUSH    {lr}

    /* Change to supervisor mode to allow reentry. */
    CPS     #SVC_MODE

    /* Push used registers. */
    PUSH    {r0-r4, r12}

    /* Increment nesting count.  r3 holds the address of ulPortInterruptNesting
    for future use.  r1 holds the original ulPortInterruptNesting value for
    future use. */
    #if ( configNUMBER_OF_CORES > 1 )
        BLX     ulPortGetCurrentCoreID
        MOV     r1, #4
        MUL     r0, r0, r1
        LDR     r3, ulPortInterruptNestingConst
        ADD     r3, r3, r0
        LDR     r1, [r3]
        ADD     r4, r1, #1
        STR     r4, [r3]
    #else
        LDR     r3, ulPortInterruptNestingConst
        LDR     r1, [r3]
        ADD     r4, r1, #1
        STR     r4, [r3]
    #endif /* configNUMBER_OF_CORES > 1 */

    /* Read value from the interrupt acknowledge register (ICC_IAR), which is stored in r0
    for future parameter and interrupt clearing use. */
    MRC     p15, 0, r0, c12, c12, 0
    DSB
    ISB

    /* Ensure bit 2 of the stack pointer is clear.  r2 holds the bit 2 value for
    future use.  _RB_ Is this ever needed provided the start of the stack is
    alligned on an 8-byte boundary? */
    MOV     r2, sp
    AND     r2, r2, #4
    SUB     sp, sp, r2

    /* Call the interrupt handler. */
    PUSH    {r0-r4, lr}
    LDR     r1, vApplicationIRQHandlerConst
    BLX     r1
    POP     {r0-r4, lr}
    ADD     sp, sp, r2

    CPSID   i
    DSB
    ISB

    /* Write the value read from ICCIAR to ICCEOIR. */
    MCR     p15, 0, r0, c12, c12, 1
    ISB
    DSB

    /* Restore the old nesting count. */
    STR     r1, [r3]

    /* A context switch is never performed if the nesting count is not 0. */
    CMP     r1, #0
    BNE     exit_without_switch

    /* Did the interrupt request a context switch?  r1 holds the address of
    ulPortYieldRequired and r0 the value of ulPortYieldRequired for future
    use. */
    #if ( configNUMBER_OF_CORES > 1 )
        BLX     ulPortGetCurrentCoreID
        MOV     r1, #4
        MUL     r0, r0, r1
        LDR     r1, =ulPortYieldRequired
        ADD     r1, r1, r0
    #else
        LDR     r1, =ulPortYieldRequired
    #endif /* configNUMBER_OF_CORES > 1 */
    LDR     r0, [r1]

    /* Switch Context if ulPortYieldRequired is set TRUE from ISR */
    CMP     r0, #0
    BNE     switch_before_exit

exit_without_switch:
    /* No context switch.  Restore used registers, LR_irq and SPSR before
    returning. */
    POP     {r0-r4, r12}
    CPS     #IRQ_MODE
    POP     {LR}
    MSR     SPSR_cxsf, LR
    POP     {LR}
    MOVS    PC, LR

switch_before_exit:
    /* A context switch is to be performed.  Clear the context switch pending
    flag. */
    MOV     r0, #0
    STR     r0, [r1]

    /* Restore used registers, LR-irq and SPSR before saving the context
    to the task stack. */
    POP     {r0-r4, r12}
    CPS     #IRQ_MODE
    POP     {LR}
    MSR     SPSR_cxsf, LR
    POP     {LR}
    portSAVE_CONTEXT

    /* Ensure bit 2 of the stack pointer is clear. */
    MOV     r2, sp
    AND     r2, r2, #4
    SUB     sp, sp, r2

    /* Call the function that selects the new task to execute.
    vTaskSwitchContext() if vTaskSwitchContext() uses LDRD or STRD
    instructions, or 8 byte aligned stack allocated data.  LR does not need
    saving as a new LR will be loaded by portRESTORE_CONTEXT anyway. */
    
    #if ( configNUMBER_OF_CORES > 1 )
        BLX     ulPortGetCurrentCoreID       /* R0 = Core number */  
    #endif /* configNUMBER_OF_CORES > 1 */

    LDR     R3, vTaskSwitchContextConst
    BLX     R3

    /* Restore the context of, and branch to, the task selected to execute
    next. */
    portRESTORE_CONTEXT

/******************************************************************************
 * If the application provides an implementation of vApplicationIRQHandler(),
 * then it will get called directly without saving the FPU registers on
 * interrupt entry, and this weak implementation of
 * vApplicationIRQHandler() will not get called.
 *
 * If the application provides its own implementation of
 * vApplicationFPUSafeIRQHandler() then this implementation of
 * vApplicationIRQHandler() will be called, save the FPU registers, and then
 * call vApplicationFPUSafeIRQHandler().
 *
 * Therefore, if the application writer wants FPU registers to be saved on
 * interrupt entry their IRQ handler must be called
 * vApplicationFPUSafeIRQHandler(), and if the application writer does not want
 * FPU registers to be saved on interrupt entry their IRQ handler must be
 * called vApplicationIRQHandler().
 *****************************************************************************/
.align 4
.weak vApplicationIRQHandler
.type vApplicationIRQHandler, %function
vApplicationIRQHandler:

    PUSH    {LR}

    #if defined( __ARM_FP )
        FMRX    R1,  FPSCR
        VPUSH   {D16-D31}
        VPUSH   {D0-D15}
        PUSH    {R1}

        LDR     r1, vApplicationFPUSafeIRQHandlerConst
        BLX     r1

        POP     {R0}
        VPOP    {D0-D15}
        VPOP    {D16-D31}
        VMSR    FPSCR, R0
    #endif /* __ARM_FP */

    POP {PC}

/******************************************************************************
 * ulPortGetCurrentCoreID is used to get current CPU ID.
 *****************************************************************************/
.align 4
.type ulPortGetCurrentCoreID, %function
ulPortGetCurrentCoreID:

    mrc    p15, 0, r0, c0, c0, 5       // Read MPIDR
    ands   r1, r0, #MPIDR_CLUSTER_MASK // AFF1 is CluserID 
    ands   r0, r0, #MPIDR_CPU_MASK     // AFF0 is the CPU number.
    orr    r0, r0, r1, LSR #MPIDR_CLUSTER_CPUID_SHFT  // r0 == unique CPU number      
    lsr    r1, r1, #MPIDR_CLUSTER_SHFT
    bx     lr

/******************************************************************************
 * ulPortGetCurrentClusterID is used to get Currect Cluster ID.
 *****************************************************************************/
.align 4
.type ulPortGetCurrentClusterID, %function
ulPortGetCurrentClusterID:

    mrc    p15, 0, r0, c0, c0, 5       // Read MPIDR
    ands   r0, r0, #MPIDR_CLUSTER_MASK   // AFF1 is CluserID                
    lsr    r0, r0, #MPIDR_CLUSTER_SHFT // r0 == Cluster Number
    bx     lr 


#if ( configNUMBER_OF_CORES > 1 )
    pxCurrentTCBsConst: .word pxCurrentTCBs
#else
    pxCurrentTCBConst: .word pxCurrentTCB
#endif /* configNUMBER_OF_CORES > 1 */

ulCriticalNestingConst: .word ulCriticalNesting

#if defined( __ARM_FP )
    ulPortTaskHasFPUContextConst: .word ulPortTaskHasFPUContext
    vApplicationFPUSafeIRQHandlerConst: .word vApplicationFPUSafeIRQHandler
#endif /* __ARM_FP */

ulMaxAPIPriorityMaskConst: .word ulMaxAPIPriorityMask
vTaskSwitchContextConst: .word vTaskSwitchContext
vApplicationIRQHandlerConst: .word vApplicationIRQHandler
ulPortInterruptNestingConst: .word ulPortInterruptNesting

.end
