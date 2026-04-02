//    ===========================================================================
//
//    Copyright (c) 2021-2025 Qualcomm Technologies, Inc.
//    All Rights Reserved.
//    Confidential and Proprietary - Qualcomm Technologies, Inc.
//
//    Export of this technology or software is regulated by the U.S. Government.
//    Diversion contrary to U.S. law prohibited.
//
//    All ideas, data and information contained in or disclosed by
//    this document are confidential and proprietary information of
//    Qualcomm Technologies, Inc. and all rights therein are expressly reserved.
//    By accepting this material the recipient agrees that this material
//    and the information contained therein are held in confidence and in
//    trust and will not be used, copied, reproduced in whole or in part,
//    nor its contents revealed in any manner to others without the express
//    written permission of Qualcomm Technologies, Inc.
//
//    ===========================================================================
//
//    $Header:   $
//    $DateTime:  $
//    $Author:   $
//
//    ===========================================================================

.include "Crashdbg_sdi_defs.hs"

//-------------------------------------------------------------------------------
// Import "sdiinit_sp" symbol that is referenced here
//-------------------------------------------------------------------------------
.global sdiinit_sp
.type sdiinit_sp,%function
.balign 32 // Align SDI address such that LSB 5 bits are 0s and to make it writable in CFGVECTABLE bit[26:0]

.type get_current_cpu_id, %function
.type get_atcm_base, %function
.type get_btcm_base, %function
.type get_ctcm_base, %function

//-------------------------------------------------------------------------------
// SAIL Crash debug SDI Entry Code in PASS1
//-------------------------------------------------------------------------------
sdiinit_sp:

            //------------------------------
            //Start of instructions to support TCM dump
            //------------------------------

            // Disable RAMPROTEN (bit 0) in IMP_MEMPROTCTLR
            mrc p15, 1, r0, c9, c1, 2
            bic r0, r0, #0x1
            mcr p15, 1, r0, c9, c1, 2

            // Enable only EL2 access to TCM
            mrc p15, 0, r0, c11, c0, 0  /* Read IMP_SLAVEPCTLR into R0   */
            mov r0, #0x1                /* Enable only Priv EL2 access   */
            mcr p15, 0, r0, c11, c0, 0  /* Write R0 to IMP_SLAVEPCTLR    */

            // Enable TCMs
            bl     get_current_cpu_id
            bl     get_atcm_base
            mov    r1, r0
            orr    r1, r1, #3
            mcr    p15, 0, r1, c9, c1, 0
            ISB
            DSB
            bl     get_current_cpu_id
            bl     get_btcm_base
            mov    r1, r0
            orr    r1, r1, #3
            mcr    p15, 0, r1, c9, c1, 1
            ISB
            DSB
            bl     get_current_cpu_id
            bl     get_ctcm_base
            mov    r1, r0
            orr    r1, r1, #3
            mcr    p15, 0, r1, c9, c1, 2
            ISB

            // Disable MPU
            DSB
            mrc     p15, 4, r1, c1, c0, 0  // HSCTLR Read
            bic     r1, r1, #0x1           // MPU disabled
            mcr     p15, 4, r1, c1, c0, 0  // HSCTLR Write
            ISB

            // Make core 1 & 2 WFI
            bl get_current_cpu_id
            cmp r0, #0x0
            bne loop_wfi

            //------------------------------
            //End of instructions to support TCM dump
            //------------------------------

            // Initialize stack pointer just before the start of Next region 0x08021400
            // Stack grows downward so start address is just before the end of memory segment (0x08021000 - 0x08021400)
            ldr     sp, =0x0801D3F0


            //----------------------------------------------------------------
            // Enable access to VFP by enabling access to Coprocessors 10 and 11.
            // Enables Full Access i.e. in both privileged and non privileged modes
            //----------------------------------------------------------------

            mrc     p15, 0, r0, c1, c0, 2   // Read Coprocessor Access Control Register (CPACR)
            orr     r0, r0, #(0xF << 20)    // Enable access to CP 10 & 11
            mcr     p15, 0, r0, c1, c0, 2   // Write Coprocessor Access Control Register (CPACR)
            isb

            //----------------------------------------------------------------
            // Switch on the VFP hardware
            //----------------------------------------------------------------

            mov    r0, #0x40000000
            vmsr   FPEXC, r0               // Write FPEXC register, EN bit set


            // branch to SDI function
            bl     Crashdbg_pass1_sdi_entry


get_current_cpu_id:
            mrc    p15, 0, r0, c0, c0, 5       // Read MPIDR
            ands   r1, r0, #MPIDR_CLUSTER_MASK // AFF1 is CluserID 
            ands   r0, r0, #MPIDR_CPU_MASK     // AFF0 is the CPU number.
            orr    r0, r0, r1, LSR #MPIDR_CLUSTER_CPUID_SHFT  // r0 == unique CPU number      
            lsr    r1, r1, #MPIDR_CLUSTER_SHFT
            bx     lr


get_atcm_base:
            cmp   r0,#0
            moveq r0, #CLUSTER0_CORE0_ATCM_START
            beq   exit_get_atcm_base
            cmp   r0,#1
            moveq r0, #CLUSTER0_CORE1_ATCM_START
            beq   exit_get_atcm_base
            cmp   r0,#2
            moveq r0, #CLUSTER1_CORE0_ATCM_START
            beq   exit_get_atcm_base
            cmp   r0,#3
            moveq r0, #CLUSTER1_CORE1_ATCM_START
            beq   exit_get_atcm_base
exit_get_atcm_base:
            bx    lr

get_btcm_base:
            cmp   r0,#0
            moveq r0, #CLUSTER0_CORE0_BTCM_START
            beq   exit_get_btcm_base
            cmp   r0,#1
            moveq r0, #CLUSTER0_CORE1_BTCM_START
            beq   exit_get_btcm_base
            cmp   r0,#2
            moveq r0, #CLUSTER1_CORE0_BTCM_START
            beq   exit_get_btcm_base
            cmp   r0,#3
            moveq r0, #CLUSTER1_CORE1_BTCM_START
            beq   exit_get_btcm_base
exit_get_btcm_base:
            bx    lr

get_ctcm_base:
            cmp   r0,#0
            moveq r0, #CLUSTER0_CORE0_CTCM_START
            beq   exit_get_ctcm_base
            cmp   r0,#1
            moveq r0, #CLUSTER0_CORE1_CTCM_START
            beq   exit_get_ctcm_base
            cmp   r0,#2
            moveq r0, #CLUSTER1_CORE0_CTCM_START
            beq   exit_get_ctcm_base
            cmp   r0,#3
            moveq r0, #CLUSTER1_CORE1_CTCM_START
            beq   exit_get_ctcm_base
exit_get_ctcm_base:
            bx    lr

loop_wfi:      dsb     SY      // Clear all pending data accesses
               wfi         // Go to sleep
               B       loop_wfi
