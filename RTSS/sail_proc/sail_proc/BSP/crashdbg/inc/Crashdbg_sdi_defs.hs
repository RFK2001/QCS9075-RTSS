//-----------------------------------------------------------------------------
// The confidential and proprietary information contained in this file may
// only be used by a person authorised under and to the extent permitted
// by a subsisting licensing agreement from ARM Limited or its affiliates.
//
//            (C) COPYRIGHT 2023 ARM Limited or its affiliates.
//                ALL RIGHTS RESERVED
//
// This entire notice must be reproduced on all copies of this file
// and copies of this file may only be made by a person if such person is
// permitted to do so under the terms of a subsisting license agreement
// from ARM Limited or its affiliates.
//
//-----------------------------------------------------------------------------
// Purpose:
//   This file contains definitions that are used by multiple files.  It is
//   loaded by files that require these symbols using the ".include" directive.
//-----------------------------------------------------------------------------

//Cpu inforamtion --
.equ NUM_CPUS,          0x4
.equ NUM_CLUSTERS,      0x2

.equ MPIDR_CLUSTER_MASK, 0xFF00
.equ MPIDR_CLUSTER_SHFT, 8
.equ MPIDR_CPU_MASK,     0xFF
.equ MPIDR_CPU_SHFT,     0
.equ MPIDR_CLUSTER_CPUID_SHFT, 0x7

//TCM config
.equ ATCM_SIZE,          0x10000
.equ BTCM_SIZE,          0x8000
.equ CTCM_SIZE,          0x8000

//cluster 0 core 0
.equ CLUSTER0_CORE0_ATCM_START,   0x2000000
.equ CLUSTER0_CORE0_BTCM_START,   0x2100000
.equ CLUSTER0_CORE0_CTCM_START,   0x2200000

//cluster 0 core 1
.equ CLUSTER0_CORE1_ATCM_START,   0x2400000
.equ CLUSTER0_CORE1_BTCM_START,   0x2500000
.equ CLUSTER0_CORE1_CTCM_START,   0x2600000

//cluster 1 core 0
.equ CLUSTER1_CORE0_ATCM_START,   0x3000000
.equ CLUSTER1_CORE0_BTCM_START,   0x3100000
.equ CLUSTER1_CORE0_CTCM_START,   0x3200000

//cluster 1 core 1
.equ CLUSTER1_CORE1_ATCM_START,   0x3400000
.equ CLUSTER1_CORE1_BTCM_START,   0x3500000
.equ CLUSTER1_CORE1_CTCM_START,   0x3600000

