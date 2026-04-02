#ifndef __G_SAIL_TO_MD_GPU_RBBM_HWIO_H__
#define __G_SAIL_TO_MD_GPU_RBBM_HWIO_H__
/*
===========================================================================
*/
/**
    @file g_SAIL_TO_MD_GPU_RBBM_HWIO.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        SA8775P (LeMansAU) [lemansau_v1.0_p3q2r72_BTO]
 
    This file contains HWIO register definitions for the following modules:
        SAIL_TO_MD_GPU_RBBM_BLK_DEC0


    Generation parameters: 
    { 'filename': 'g_SAIL_TO_MD_GPU_RBBM_HWIO.h',
      'integer-qualifiers': True,
      'modules': ['SAIL_TO_MD_GPU_RBBM_BLK_DEC0'],
      'output-fvals': True,
      'output-offsets': True}
*/
/*
    ===========================================================================

    Copyright (c) 2022 Qualcomm Technologies, Inc.
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

    $Header: $
    $DateTime: $
    $Author: $

    ===========================================================================
*/

/*----------------------------------------------------------------------------
 * MODULE: SAIL_TO_MD_GPU_RBBM_BLK_DEC0
 *--------------------------------------------------------------------------*/

#define SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE                                               (SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE      + 0x03d00000ul)
#define SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_SIZE                                          0x17c0u
#define SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_USED                                          0x1554u
#define SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS                                          0x03d00000ul

#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_VERSION_ADDR                                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_VERSION_OFFS                                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_VERSION_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_VERSION_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_HW_VERSION_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_VERSION_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_HW_VERSION_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_VERSION_STEP_BMSK                                       0xffff0000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_VERSION_STEP_SHFT                                               16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_VERSION_MINOR_BMSK                                          0xfff0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_VERSION_MINOR_SHFT                                               4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_VERSION_MAJOR_BMSK                                             0xfu
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_VERSION_MAJOR_SHFT                                               0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_RELEASE_ADDR                                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_RELEASE_OFFS                                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_RELEASE_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_RELEASE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_HW_RELEASE_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_RELEASE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_HW_RELEASE_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_RELEASE_YEAR_BMSK                                       0xe0000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_RELEASE_YEAR_SHFT                                               29u
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_RELEASE_MONTH_BMSK                                      0x1e000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_RELEASE_MONTH_SHFT                                              25u
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_RELEASE_DAY_BMSK                                         0x1f00000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_RELEASE_DAY_SHFT                                                20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_RELEASE_RELEASENUM_BMSK                                    0xf0000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_RELEASE_RELEASENUM_SHFT                                         16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_RELEASE_HMID_BMSK                                           0xffffu
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_RELEASE_HMID_SHFT                                                0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_CONFIGURATION_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_CONFIGURATION_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_CONFIGURATION_RMSK                                       0xffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_CONFIGURATION_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_HW_CONFIGURATION_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_CONFIGURATION_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_HW_CONFIGURATION_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_CONFIGURATION_NUMRB_BMSK                                 0xf000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_CONFIGURATION_NUMRB_SHFT                                        24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_CONFIGURATION_CONFIGID_BMSK                               0xff0000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_CONFIGURATION_CONFIGID_SHFT                                     16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_CONFIGURATION_NUMAXIPORTS_BMSK                              0xf000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_CONFIGURATION_NUMAXIPORTS_SHFT                                  12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_CONFIGURATION_NUMUCHEBANKS_BMSK                              0xf00u
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_CONFIGURATION_NUMUCHEBANKS_SHFT                                  8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_CONFIGURATION_VPCMEMDEPTHL2_BMSK                              0xf0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_CONFIGURATION_VPCMEMDEPTHL2_SHFT                                 4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_CONFIGURATION_NUMSP_BMSK                                       0xfu
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_CONFIGURATION_NUMSP_SHFT                                         0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_CLIENT_QOS_CNTL_ADDR                                  (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x44u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_CLIENT_QOS_CNTL_OFFS                                  (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x44u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_CLIENT_QOS_CNTL_RMSK                                   0x7770777ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_CLIENT_QOS_CNTL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_CLIENT_QOS_CNTL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_CLIENT_QOS_CNTL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_CLIENT_QOS_CNTL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_CLIENT_QOS_CNTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_CLIENT_QOS_CNTL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_CLIENT_QOS_CNTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_CLIENT_QOS_CNTL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_CLIENT_QOS_CNTL_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_CLIENT_QOS_CNTL_PRIORLV1CLIENT_FLAG_BMSK               0x7000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_CLIENT_QOS_CNTL_PRIORLV1CLIENT_FLAG_SHFT                      24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_CLIENT_QOS_CNTL_PRIORLV1CLIENT_UCHE_CCU_BMSK            0x700000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_CLIENT_QOS_CNTL_PRIORLV1CLIENT_UCHE_CCU_SHFT                  20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_CLIENT_QOS_CNTL_PRIORLV1CLIENT_CP_BMSK                   0x70000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_CLIENT_QOS_CNTL_PRIORLV1CLIENT_CP_SHFT                        16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_CLIENT_QOS_CNTL_REQPRIORCLIENT_FLAG_BMSK                   0x700u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_CLIENT_QOS_CNTL_REQPRIORCLIENT_FLAG_SHFT                       8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_CLIENT_QOS_CNTL_REQPRIORCLIENT_UCHE_CCU_BMSK                0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_CLIENT_QOS_CNTL_REQPRIORCLIENT_UCHE_CCU_SHFT                   4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_CLIENT_QOS_CNTL_REQPRIORCLIENT_CP_BMSK                       0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_CLIENT_QOS_CNTL_REQPRIORCLIENT_CP_SHFT                         0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_RAM_ACC_63_32_ADDR                                         (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x48u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_RAM_ACC_63_32_OFFS                                         (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x48u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_RAM_ACC_63_32_RMSK                                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_RAM_ACC_63_32_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_RAM_ACC_63_32_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_RAM_ACC_63_32_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_RAM_ACC_63_32_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_RAM_ACC_63_32_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_RAM_ACC_63_32_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_RAM_ACC_63_32_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_RAM_ACC_63_32_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_RAM_ACC_63_32_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_RAM_ACC_63_32_ACC63TO32_BMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_RAM_ACC_63_32_ACC63TO32_SHFT                                        0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_HALT_ADDR                                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x58u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_HALT_OFFS                                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x58u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_HALT_RMSK                                                    0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_HALT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_HALT_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_HALT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_HALT_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_HALT_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_HALT_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_HALT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_HALT_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_HALT_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_HALT_HALT_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_HALT_HALT_SHFT                                                 0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_HALT_ACK_ADDR                                         (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x5cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_HALT_ACK_OFFS                                         (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x5cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_HALT_ACK_RMSK                                                0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_HALT_ACK_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_HALT_ACK_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_HALT_ACK_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_HALT_ACK_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_HALT_ACK_HALT_ACK_BMSK                                       0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GBIF_HALT_ACK_HALT_ACK_SHFT                                         0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_GPR0_CNTL_ADDR                                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x60u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GPR0_CNTL_OFFS                                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x60u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GPR0_CNTL_RMSK                                                   0x1fu
#define HWIO_SAIL_TO_MD_GPU_RBBM_GPR0_CNTL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_GPR0_CNTL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GPR0_CNTL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_GPR0_CNTL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GPR0_CNTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_GPR0_CNTL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GPR0_CNTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_GPR0_CNTL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_GPR0_CNTL_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GPR0_CNTL_REQAFTERDATADIS_BMSK                                   0x10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GPR0_CNTL_REQAFTERDATADIS_SHFT                                      4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GPR0_CNTL_PRIORLVLFLAG_BMSK                                       0xcu
#define HWIO_SAIL_TO_MD_GPU_RBBM_GPR0_CNTL_PRIORLVLFLAG_SHFT                                         2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GPR0_CNTL_REQPRIORCFLAG_BMSK                                      0x3u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GPR0_CNTL_REQPRIORCFLAG_SHFT                                        0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_GPR1_CNTL_ADDR                                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x64u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GPR1_CNTL_OFFS                                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x64u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GPR1_CNTL_RMSK                                             0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_GPR1_CNTL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_GPR1_CNTL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GPR1_CNTL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_GPR1_CNTL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GPR1_CNTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_GPR1_CNTL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GPR1_CNTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_GPR1_CNTL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_GPR1_CNTL_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GPR1_CNTL_ISDBDEBUGBINARYPOINTER_BMSK                      0xfffff000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_GPR1_CNTL_ISDBDEBUGBINARYPOINTER_SHFT                              12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GPR1_CNTL_NA_BMSK                                               0xfffu
#define HWIO_SAIL_TO_MD_GPU_RBBM_GPR1_CNTL_NA_SHFT                                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_WAIT_IDLE_CLOCKS_CNTL_ADDR                                 (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x68u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_WAIT_IDLE_CLOCKS_CNTL_OFFS                                 (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x68u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_WAIT_IDLE_CLOCKS_CNTL_RMSK                                     0xffffu
#define HWIO_SAIL_TO_MD_GPU_RBBM_WAIT_IDLE_CLOCKS_CNTL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_WAIT_IDLE_CLOCKS_CNTL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_WAIT_IDLE_CLOCKS_CNTL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_WAIT_IDLE_CLOCKS_CNTL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_WAIT_IDLE_CLOCKS_CNTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_WAIT_IDLE_CLOCKS_CNTL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_WAIT_IDLE_CLOCKS_CNTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_WAIT_IDLE_CLOCKS_CNTL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_WAIT_IDLE_CLOCKS_CNTL_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_WAIT_IDLE_CLOCKS_CNTL_WAITIDLECLOCKS_BMSK                      0xffffu
#define HWIO_SAIL_TO_MD_GPU_RBBM_WAIT_IDLE_CLOCKS_CNTL_WAITIDLECLOCKS_SHFT                           0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_WAIT_IDLE_CLOCKS_CNTL2_ADDR                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x6cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_WAIT_IDLE_CLOCKS_CNTL2_OFFS                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x6cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_WAIT_IDLE_CLOCKS_CNTL2_RMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_WAIT_IDLE_CLOCKS_CNTL2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_WAIT_IDLE_CLOCKS_CNTL2_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_WAIT_IDLE_CLOCKS_CNTL2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_WAIT_IDLE_CLOCKS_CNTL2_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_WAIT_IDLE_CLOCKS_CNTL2_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_WAIT_IDLE_CLOCKS_CNTL2_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_WAIT_IDLE_CLOCKS_CNTL2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_WAIT_IDLE_CLOCKS_CNTL2_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_WAIT_IDLE_CLOCKS_CNTL2_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_WAIT_IDLE_CLOCKS_CNTL2_GPUIDLEHYST_BMSK                    0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_WAIT_IDLE_CLOCKS_CNTL2_GPUIDLEHYST_SHFT                             0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_INT_CNTL_ADDR                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x7cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_INT_CNTL_OFFS                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x7cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_INT_CNTL_RMSK                               0x4ffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_INT_CNTL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_INT_CNTL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_INT_CNTL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_INT_CNTL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_INT_CNTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_INT_CNTL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_INT_CNTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_INT_CNTL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_INT_CNTL_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_INT_CNTL_HANGINTEN_BMSK                     0x40000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_INT_CNTL_HANGINTEN_SHFT                             30u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_INT_CNTL_HANGCOUNT_BMSK                      0xffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_INT_CNTL_HANGCOUNT_SHFT                              0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL0_ADDR                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x80u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL0_OFFS                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x80u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL0_RMSK                             0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL0_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL0_INTERFACEHANGMASK_BMSK           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL0_INTERFACEHANGMASK_SHFT                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL1_ADDR                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x84u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL1_OFFS                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x84u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL1_RMSK                             0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL1_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL1_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL1_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL1_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL1_INTERFACEHANGMASK_BMSK           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL1_INTERFACEHANGMASK_SHFT                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL2_ADDR                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x88u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL2_OFFS                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x88u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL2_RMSK                             0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL2_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL2_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL2_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL2_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL2_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL2_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL2_INTERFACEHANGMASK_BMSK           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL2_INTERFACEHANGMASK_SHFT                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL3_ADDR                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x8cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL3_OFFS                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x8cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL3_RMSK                             0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL3_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL3_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL3_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL3_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL3_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL3_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL3_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL3_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL3_INTERFACEHANGMASK_BMSK           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL3_INTERFACEHANGMASK_SHFT                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL4_ADDR                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x90u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL4_OFFS                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x90u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL4_RMSK                             0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL4_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL4_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL4_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL4_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL4_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL4_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL4_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL4_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL4_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL4_INTERFACEHANGMASK_BMSK           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL4_INTERFACEHANGMASK_SHFT                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL5_ADDR                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x94u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL5_OFFS                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x94u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL5_RMSK                             0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL5_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL5_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL5_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL5_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL5_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL5_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL5_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL5_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL5_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL5_INTERFACEHANGMASK_BMSK           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL5_INTERFACEHANGMASK_SHFT                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL6_ADDR                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x98u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL6_OFFS                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x98u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL6_RMSK                             0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL6_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL6_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL6_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL6_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL6_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL6_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL6_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL6_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL6_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL6_INTERFACEHANGMASK_BMSK           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL6_INTERFACEHANGMASK_SHFT                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL7_ADDR                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x9cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL7_OFFS                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x9cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL7_RMSK                             0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL7_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL7_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL7_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL7_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL7_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL7_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL7_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL7_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL7_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL7_INTERFACEHANGMASK_BMSK           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL7_INTERFACEHANGMASK_SHFT                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL8_ADDR                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0xa0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL8_OFFS                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0xa0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL8_RMSK                             0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL8_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL8_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL8_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL8_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL8_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL8_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL8_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL8_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL8_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL8_INTERFACEHANGMASK_BMSK           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL8_INTERFACEHANGMASK_SHFT                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL9_ADDR                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0xa4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL9_OFFS                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0xa4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL9_RMSK                             0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL9_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL9_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL9_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL9_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL9_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL9_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL9_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL9_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL9_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL9_INTERFACEHANGMASK_BMSK           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL9_INTERFACEHANGMASK_SHFT                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL10_ADDR                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0xa8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL10_OFFS                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0xa8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL10_RMSK                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL10_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL10_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL10_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL10_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL10_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL10_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL10_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL10_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL10_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL10_INTERFACEHANGMASK_BMSK          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL10_INTERFACEHANGMASK_SHFT                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL11_ADDR                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0xacu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL11_OFFS                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0xacu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL11_RMSK                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL11_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL11_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL11_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL11_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL11_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL11_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL11_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL11_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL11_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL11_INTERFACEHANGMASK_BMSK          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL11_INTERFACEHANGMASK_SHFT                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL12_ADDR                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0xb0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL12_OFFS                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0xb0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL12_RMSK                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL12_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL12_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL12_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL12_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL12_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL12_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL12_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL12_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL12_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL12_INTERFACEHANGMASK_BMSK          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL12_INTERFACEHANGMASK_SHFT                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL13_ADDR                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0xb4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL13_OFFS                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0xb4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL13_RMSK                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL13_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL13_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL13_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL13_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL13_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL13_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL13_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL13_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL13_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL13_INTERFACEHANGMASK_BMSK          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL13_INTERFACEHANGMASK_SHFT                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL14_ADDR                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0xb8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL14_OFFS                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0xb8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL14_RMSK                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL14_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL14_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL14_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL14_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL14_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL14_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL14_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL14_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL14_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL14_INTERFACEHANGMASK_BMSK          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL14_INTERFACEHANGMASK_SHFT                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL15_ADDR                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0xbcu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL15_OFFS                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0xbcu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL15_RMSK                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL15_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL15_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL15_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL15_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL15_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL15_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL15_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL15_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL15_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL15_INTERFACEHANGMASK_BMSK          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL15_INTERFACEHANGMASK_SHFT                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL16_ADDR                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0xc0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL16_OFFS                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0xc0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL16_RMSK                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL16_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL16_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL16_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL16_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL16_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL16_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL16_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL16_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL16_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL16_INTERFACEHANGMASK_BMSK          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL16_INTERFACEHANGMASK_SHFT                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL17_ADDR                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0xc4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL17_OFFS                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0xc4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL17_RMSK                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL17_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL17_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL17_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL17_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL17_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL17_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL17_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL17_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL17_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL17_INTERFACEHANGMASK_BMSK          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL17_INTERFACEHANGMASK_SHFT                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL18_ADDR                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0xc8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL18_OFFS                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0xc8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL18_RMSK                            0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL18_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL18_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL18_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL18_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL18_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL18_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL18_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL18_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL18_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL18_INTERFACEHANGMASK_BMSK          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_HANG_MASK_CNTL18_INTERFACEHANGMASK_SHFT                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_ADDR                                           (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0xd8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_OFFS                                           (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0xd8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_RMSK                                           0xdff7fffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_ISDBUNDERDEBUG_BMSK                            0x80000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_ISDBUNDERDEBUG_SHFT                                    31u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_ISDBCPUIRQ_BMSK                                0x40000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_ISDBCPUIRQ_SHFT                                        30u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_TSBWRITEERROR_BMSK                             0x10000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_TSBWRITEERROR_SHFT                                     28u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_DEBUGBUSINTERRUPT1_BMSK                         0x8000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_DEBUGBUSINTERRUPT1_SHFT                                27u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_DEBUGBUSINTERRUPT0_BMSK                         0x4000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_DEBUGBUSINTERRUPT0_SHFT                                26u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_UCHETRAPINTERRUPT_BMSK                          0x2000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_UCHETRAPINTERRUPT_SHFT                                 25u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_OUTOFBOUNDACCESS_BMSK                           0x1000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_OUTOFBOUNDACCESS_SHFT                                  24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_HANGDETECTINTERRUPT_BMSK                         0x800000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_HANGDETECTINTERRUPT_SHFT                               23u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_ATBBUSOVERFLOW_BMSK                              0x400000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_ATBBUSOVERFLOW_SHFT                                    22u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_CACHE_FLUSH_TS_LPAC_BMSK                         0x200000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_CACHE_FLUSH_TS_LPAC_SHFT                               21u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_CACHE_FLUSH_TS_BMSK                              0x100000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_CACHE_FLUSH_TS_SHFT                                    20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_WT_DONE_TS_BMSK                                   0x40000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_WT_DONE_TS_SHFT                                        18u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_RB_DONE_TS_BMSK                                   0x20000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_RB_DONE_TS_SHFT                                        17u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_RBINTERRUPTLPAC_BMSK                              0x10000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_RBINTERRUPTLPAC_SHFT                                   16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_RBINTERRUPT_BMSK                                   0x8000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_RBINTERRUPT_SHFT                                       15u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_IB1INTERRUPT_BMSK                                  0x4000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_IB1INTERRUPT_SHFT                                      14u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_IB2INTERRUPT_BMSK                                  0x2000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_IB2INTERRUPT_SHFT                                      13u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_CCU_RESOLVE_TS_BMSK                                0x1000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_CCU_RESOLVE_TS_SHFT                                    12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_CCU_FLUSH_COLOR_TS_BMSK                             0x800u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_CCU_FLUSH_COLOR_TS_SHFT                                11u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_CCU_FLUSH_DEPTH_TS_BMSK                             0x400u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_CCU_FLUSH_DEPTH_TS_SHFT                                10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_HWERROR_BMSK                                        0x200u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_HWERROR_SHFT                                            9u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_SWINTERRUPT_BMSK                                    0x100u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_SWINTERRUPT_SHFT                                        8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_GPCERROR_BMSK                                        0x80u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_GPCERROR_SHFT                                           7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_ATBASYNCFIFOOVERFLOW_BMSK                            0x40u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_ATBASYNCFIFOOVERFLOW_SHFT                               6u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_CPIPCINT1_BMSK                                       0x20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_CPIPCINT1_SHFT                                          5u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_CPIPCINT0_BMSK                                       0x10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_CPIPCINT0_SHFT                                          4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_IB1INTERRUPTLPAC_BMSK                                 0x8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_IB1INTERRUPTLPAC_SHFT                                   3u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_IB2INTERRUPTLPAC_BMSK                                 0x4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_IB2INTERRUPTLPAC_SHFT                                   2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_AHBERROR_BMSK                                         0x2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_AHBERROR_SHFT                                           1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_GPUIDLE_BMSK                                          0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_SET_CMD_GPUIDLE_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_ADDR                                         (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0xdcu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_OFFS                                         (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0xdcu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_RMSK                                         0xdff7fffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_ISDBUNDERDEBUG_BMSK                          0x80000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_ISDBUNDERDEBUG_SHFT                                  31u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_ISDBCPUIRQ_BMSK                              0x40000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_ISDBCPUIRQ_SHFT                                      30u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_TSBWRITEERROR_BMSK                           0x10000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_TSBWRITEERROR_SHFT                                   28u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_DEBUGBUSINTERRUPT1_BMSK                       0x8000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_DEBUGBUSINTERRUPT1_SHFT                              27u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_DEBUGBUSINTERRUPT0_BMSK                       0x4000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_DEBUGBUSINTERRUPT0_SHFT                              26u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_UCHETRAPINTERRUPT_BMSK                        0x2000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_UCHETRAPINTERRUPT_SHFT                               25u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_OUTOFBOUNDACCESS_BMSK                         0x1000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_OUTOFBOUNDACCESS_SHFT                                24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_HANGDETECTINTERRUPT_BMSK                       0x800000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_HANGDETECTINTERRUPT_SHFT                             23u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_ATBBUSOVERFLOW_BMSK                            0x400000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_ATBBUSOVERFLOW_SHFT                                  22u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_CACHE_FLUSH_TS_LPAC_BMSK                       0x200000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_CACHE_FLUSH_TS_LPAC_SHFT                             21u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_CACHE_FLUSH_TS_BMSK                            0x100000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_CACHE_FLUSH_TS_SHFT                                  20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_WT_DONE_TS_BMSK                                 0x40000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_WT_DONE_TS_SHFT                                      18u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_RB_DONE_TS_BMSK                                 0x20000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_RB_DONE_TS_SHFT                                      17u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_RBINTERRUPTLPAC_BMSK                            0x10000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_RBINTERRUPTLPAC_SHFT                                 16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_RBINTERRUPT_BMSK                                 0x8000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_RBINTERRUPT_SHFT                                     15u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_IB1INTERRUPT_BMSK                                0x4000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_IB1INTERRUPT_SHFT                                    14u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_IB2INTERRUPT_BMSK                                0x2000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_IB2INTERRUPT_SHFT                                    13u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_CCU_RESOLVE_TS_BMSK                              0x1000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_CCU_RESOLVE_TS_SHFT                                  12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_CCU_FLUSH_COLOR_TS_BMSK                           0x800u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_CCU_FLUSH_COLOR_TS_SHFT                              11u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_CCU_FLUSH_DEPTH_TS_BMSK                           0x400u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_CCU_FLUSH_DEPTH_TS_SHFT                              10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_HWERROR_BMSK                                      0x200u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_HWERROR_SHFT                                          9u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_SWINTERRUPT_BMSK                                  0x100u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_SWINTERRUPT_SHFT                                      8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_GPCERROR_BMSK                                      0x80u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_GPCERROR_SHFT                                         7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_ATBASYNCFIFOOVERFLOW_BMSK                          0x40u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_ATBASYNCFIFOOVERFLOW_SHFT                             6u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_CPIPCINT1_BMSK                                     0x20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_CPIPCINT1_SHFT                                        5u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_CPIPCINT0_BMSK                                     0x10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_CPIPCINT0_SHFT                                        4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_IB1INTERRUPTLPAC_BMSK                               0x8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_IB1INTERRUPTLPAC_SHFT                                 3u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_IB2INTERRUPTLPAC_BMSK                               0x4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_IB2INTERRUPTLPAC_SHFT                                 2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_AHBERROR_BMSK                                       0x2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_AHBERROR_SHFT                                         1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_GPUIDLE_BMSK                                        0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_CLEAR_CMD_GPUIDLE_SHFT                                          0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_ADDR                                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0xe0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_OFFS                                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0xe0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_RMSK                                            0xdff7fffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_ISDBUNDERDEBUG_BMSK                             0x80000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_ISDBUNDERDEBUG_SHFT                                     31u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_ISDBCPUIRQ_BMSK                                 0x40000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_ISDBCPUIRQ_SHFT                                         30u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_TSBWRITEERROR_BMSK                              0x10000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_TSBWRITEERROR_SHFT                                      28u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_DEBUGBUSINTERRUPT1_BMSK                          0x8000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_DEBUGBUSINTERRUPT1_SHFT                                 27u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_DEBUGBUSINTERRUPT0_BMSK                          0x4000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_DEBUGBUSINTERRUPT0_SHFT                                 26u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_UCHETRAPINTERRUPT_BMSK                           0x2000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_UCHETRAPINTERRUPT_SHFT                                  25u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_OUTOFBOUNDACCESS_BMSK                            0x1000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_OUTOFBOUNDACCESS_SHFT                                   24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_HANGDETECTINTERRUPT_BMSK                          0x800000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_HANGDETECTINTERRUPT_SHFT                                23u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_ATBBUSOVERFLOW_BMSK                               0x400000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_ATBBUSOVERFLOW_SHFT                                     22u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_CACHE_FLUSH_TS_LPAC_BMSK                          0x200000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_CACHE_FLUSH_TS_LPAC_SHFT                                21u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_CACHE_FLUSH_TS_BMSK                               0x100000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_CACHE_FLUSH_TS_SHFT                                     20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_WT_DONE_TS_BMSK                                    0x40000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_WT_DONE_TS_SHFT                                         18u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_RB_DONE_TS_BMSK                                    0x20000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_RB_DONE_TS_SHFT                                         17u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_RBINTERRUPTLPAC_BMSK                               0x10000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_RBINTERRUPTLPAC_SHFT                                    16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_RBINTERRUPT_BMSK                                    0x8000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_RBINTERRUPT_SHFT                                        15u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_IB1INTERRUPT_BMSK                                   0x4000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_IB1INTERRUPT_SHFT                                       14u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_IB2INTERRUPT_BMSK                                   0x2000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_IB2INTERRUPT_SHFT                                       13u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_CCU_RESOLVE_TS_BMSK                                 0x1000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_CCU_RESOLVE_TS_SHFT                                     12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_CCU_FLUSH_COLOR_TS_BMSK                              0x800u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_CCU_FLUSH_COLOR_TS_SHFT                                 11u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_CCU_FLUSH_DEPTH_TS_BMSK                              0x400u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_CCU_FLUSH_DEPTH_TS_SHFT                                 10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_HWERROR_BMSK                                         0x200u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_HWERROR_SHFT                                             9u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_SWINTERRUPT_BMSK                                     0x100u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_SWINTERRUPT_SHFT                                         8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_GPCERROR_BMSK                                         0x80u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_GPCERROR_SHFT                                            7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_ATBASYNCFIFOOVERFLOW_BMSK                             0x40u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_ATBASYNCFIFOOVERFLOW_SHFT                                6u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_CPIPCINT1_BMSK                                        0x20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_CPIPCINT1_SHFT                                           5u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_CPIPCINT0_BMSK                                        0x10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_CPIPCINT0_SHFT                                           4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_IB1INTERRUPTLPAC_BMSK                                  0x8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_IB1INTERRUPTLPAC_SHFT                                    3u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_IB2INTERRUPTLPAC_BMSK                                  0x4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_IB2INTERRUPTLPAC_SHFT                                    2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_AHBERROR_BMSK                                          0x2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_AHBERROR_SHFT                                            1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_GPUIDLE_BMSK                                           0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_MASK_GPUIDLE_SHFT                                             0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_ADDR                                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0xe4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_OFFS                                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0xe4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_RMSK                                            0xdff7fffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_ISDBUNDERDEBUG_BMSK                             0x80000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_ISDBUNDERDEBUG_SHFT                                     31u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_ISDBCPUIRQ_BMSK                                 0x40000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_ISDBCPUIRQ_SHFT                                         30u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_TSBWRITEERROR_BMSK                              0x10000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_TSBWRITEERROR_SHFT                                      28u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_DEBUGBUSINTERRUPT1_BMSK                          0x8000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_DEBUGBUSINTERRUPT1_SHFT                                 27u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_DEBUGBUSINTERRUPT0_BMSK                          0x4000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_DEBUGBUSINTERRUPT0_SHFT                                 26u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_UCHETRAPINTERRUPT_BMSK                           0x2000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_UCHETRAPINTERRUPT_SHFT                                  25u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_OUTOFBOUNDACCESS_BMSK                            0x1000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_OUTOFBOUNDACCESS_SHFT                                   24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_HANGDETECTINTERRUPT_BMSK                          0x800000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_HANGDETECTINTERRUPT_SHFT                                23u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_ATBBUSOVERFLOW_BMSK                               0x400000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_ATBBUSOVERFLOW_SHFT                                     22u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_CACHE_FLUSH_TS_LPAC_BMSK                          0x200000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_CACHE_FLUSH_TS_LPAC_SHFT                                21u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_CACHE_FLUSH_TS_BMSK                               0x100000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_CACHE_FLUSH_TS_SHFT                                     20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_WT_DONE_TS_BMSK                                    0x40000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_WT_DONE_TS_SHFT                                         18u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_RB_DONE_TS_BMSK                                    0x20000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_RB_DONE_TS_SHFT                                         17u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_RBINTERRUPTLPAC_BMSK                               0x10000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_RBINTERRUPTLPAC_SHFT                                    16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_RBINTERRUPT_BMSK                                    0x8000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_RBINTERRUPT_SHFT                                        15u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_IB1INTERRUPT_BMSK                                   0x4000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_IB1INTERRUPT_SHFT                                       14u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_IB2INTERRUPT_BMSK                                   0x2000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_IB2INTERRUPT_SHFT                                       13u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_CCU_RESOLVE_TS_BMSK                                 0x1000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_CCU_RESOLVE_TS_SHFT                                     12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_CCU_FLUSH_COLOR_TS_BMSK                              0x800u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_CCU_FLUSH_COLOR_TS_SHFT                                 11u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_CCU_FLUSH_DEPTH_TS_BMSK                              0x400u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_CCU_FLUSH_DEPTH_TS_SHFT                                 10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_HWERROR_BMSK                                         0x200u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_HWERROR_SHFT                                             9u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_SWINTERRUPT_BMSK                                     0x100u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_SWINTERRUPT_SHFT                                         8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_GPCERROR_BMSK                                         0x80u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_GPCERROR_SHFT                                            7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_ATBASYNCFIFOOVERFLOW_BMSK                             0x40u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_ATBASYNCFIFOOVERFLOW_SHFT                                6u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_CPIPCINT1_BMSK                                        0x20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_CPIPCINT1_SHFT                                           5u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_CPIPCINT0_BMSK                                        0x10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_CPIPCINT0_SHFT                                           4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_IB1INTERRUPTLPAC_BMSK                                  0x8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_IB1INTERRUPTLPAC_SHFT                                    3u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_IB2INTERRUPTLPAC_BMSK                                  0x4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_IB2INTERRUPTLPAC_SHFT                                    2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_AHBERROR_BMSK                                          0x2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_AHBERROR_SHFT                                            1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_GPUIDLE_BMSK                                           0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_MASK_GPUIDLE_SHFT                                             0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_ADDR                                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0xe8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_OFFS                                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0xe8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_RMSK                                            0xdff7fffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_ISDBUNDERDEBUG_BMSK                             0x80000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_ISDBUNDERDEBUG_SHFT                                     31u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_ISDBCPUIRQ_BMSK                                 0x40000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_ISDBCPUIRQ_SHFT                                         30u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_TSBWRITEERROR_BMSK                              0x10000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_TSBWRITEERROR_SHFT                                      28u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_DEBUGBUSINTERRUPT1_BMSK                          0x8000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_DEBUGBUSINTERRUPT1_SHFT                                 27u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_DEBUGBUSINTERRUPT0_BMSK                          0x4000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_DEBUGBUSINTERRUPT0_SHFT                                 26u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_UCHETRAPINTERRUPT_BMSK                           0x2000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_UCHETRAPINTERRUPT_SHFT                                  25u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_OUTOFBOUNDACCESS_BMSK                            0x1000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_OUTOFBOUNDACCESS_SHFT                                   24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_HANGDETECTINTERRUPT_BMSK                          0x800000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_HANGDETECTINTERRUPT_SHFT                                23u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_ATBBUSOVERFLOW_BMSK                               0x400000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_ATBBUSOVERFLOW_SHFT                                     22u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_CACHE_FLUSH_TS_LPAC_BMSK                          0x200000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_CACHE_FLUSH_TS_LPAC_SHFT                                21u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_CACHE_FLUSH_TS_BMSK                               0x100000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_CACHE_FLUSH_TS_SHFT                                     20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_WT_DONE_TS_BMSK                                    0x40000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_WT_DONE_TS_SHFT                                         18u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_RB_DONE_TS_BMSK                                    0x20000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_RB_DONE_TS_SHFT                                         17u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_RBINTERRUPTLPAC_BMSK                               0x10000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_RBINTERRUPTLPAC_SHFT                                    16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_RBINTERRUPT_BMSK                                    0x8000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_RBINTERRUPT_SHFT                                        15u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_IB1INTERRUPT_BMSK                                   0x4000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_IB1INTERRUPT_SHFT                                       14u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_IB2INTERRUPT_BMSK                                   0x2000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_IB2INTERRUPT_SHFT                                       13u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_CCU_RESOLVE_TS_BMSK                                 0x1000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_CCU_RESOLVE_TS_SHFT                                     12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_CCU_FLUSH_COLOR_TS_BMSK                              0x800u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_CCU_FLUSH_COLOR_TS_SHFT                                 11u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_CCU_FLUSH_DEPTH_TS_BMSK                              0x400u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_CCU_FLUSH_DEPTH_TS_SHFT                                 10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_HWERROR_BMSK                                         0x200u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_HWERROR_SHFT                                             9u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_SWINTERRUPT_BMSK                                     0x100u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_SWINTERRUPT_SHFT                                         8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_GPCERROR_BMSK                                         0x80u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_GPCERROR_SHFT                                            7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_ATBASYNCFIFOOVERFLOW_BMSK                             0x40u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_ATBASYNCFIFOOVERFLOW_SHFT                                6u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_CPIPCINT1_BMSK                                        0x20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_CPIPCINT1_SHFT                                           5u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_CPIPCINT0_BMSK                                        0x10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_CPIPCINT0_SHFT                                           4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_IB1INTERRUPTLPAC_BMSK                                  0x8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_IB1INTERRUPTLPAC_SHFT                                    3u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_IB2INTERRUPTLPAC_BMSK                                  0x4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_IB2INTERRUPTLPAC_SHFT                                    2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_AHBERROR_BMSK                                          0x2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_AHBERROR_SHFT                                            1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_GPUIDLE_BMSK                                           0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_MASK_GPUIDLE_SHFT                                             0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_ADDR                                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0xecu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_OFFS                                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0xecu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_RMSK                                            0xdff7fffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_ISDBUNDERDEBUG_BMSK                             0x80000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_ISDBUNDERDEBUG_SHFT                                     31u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_ISDBCPUIRQ_BMSK                                 0x40000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_ISDBCPUIRQ_SHFT                                         30u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_TSBWRITEERROR_BMSK                              0x10000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_TSBWRITEERROR_SHFT                                      28u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_DEBUGBUSINTERRUPT1_BMSK                          0x8000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_DEBUGBUSINTERRUPT1_SHFT                                 27u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_DEBUGBUSINTERRUPT0_BMSK                          0x4000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_DEBUGBUSINTERRUPT0_SHFT                                 26u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_UCHETRAPINTERRUPT_BMSK                           0x2000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_UCHETRAPINTERRUPT_SHFT                                  25u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_OUTOFBOUNDACCESS_BMSK                            0x1000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_OUTOFBOUNDACCESS_SHFT                                   24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_HANGDETECTINTERRUPT_BMSK                          0x800000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_HANGDETECTINTERRUPT_SHFT                                23u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_ATBBUSOVERFLOW_BMSK                               0x400000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_ATBBUSOVERFLOW_SHFT                                     22u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_CACHE_FLUSH_TS_LPAC_BMSK                          0x200000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_CACHE_FLUSH_TS_LPAC_SHFT                                21u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_CACHE_FLUSH_TS_BMSK                               0x100000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_CACHE_FLUSH_TS_SHFT                                     20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_WT_DONE_TS_BMSK                                    0x40000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_WT_DONE_TS_SHFT                                         18u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_RB_DONE_TS_BMSK                                    0x20000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_RB_DONE_TS_SHFT                                         17u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_RBINTERRUPTLPAC_BMSK                               0x10000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_RBINTERRUPTLPAC_SHFT                                    16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_RBINTERRUPT_BMSK                                    0x8000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_RBINTERRUPT_SHFT                                        15u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_IB1INTERRUPT_BMSK                                   0x4000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_IB1INTERRUPT_SHFT                                       14u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_IB2INTERRUPT_BMSK                                   0x2000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_IB2INTERRUPT_SHFT                                       13u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_CCU_RESOLVE_TS_BMSK                                 0x1000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_CCU_RESOLVE_TS_SHFT                                     12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_CCU_FLUSH_COLOR_TS_BMSK                              0x800u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_CCU_FLUSH_COLOR_TS_SHFT                                 11u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_CCU_FLUSH_DEPTH_TS_BMSK                              0x400u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_CCU_FLUSH_DEPTH_TS_SHFT                                 10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_HWERROR_BMSK                                         0x200u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_HWERROR_SHFT                                             9u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_SWINTERRUPT_BMSK                                     0x100u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_SWINTERRUPT_SHFT                                         8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_GPCERROR_BMSK                                         0x80u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_GPCERROR_SHFT                                            7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_ATBASYNCFIFOOVERFLOW_BMSK                             0x40u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_ATBASYNCFIFOOVERFLOW_SHFT                                6u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_CPIPCINT1_BMSK                                        0x20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_CPIPCINT1_SHFT                                           5u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_CPIPCINT0_BMSK                                        0x10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_CPIPCINT0_SHFT                                           4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_IB1INTERRUPTLPAC_BMSK                                  0x8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_IB1INTERRUPTLPAC_SHFT                                    3u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_IB2INTERRUPTLPAC_BMSK                                  0x4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_IB2INTERRUPTLPAC_SHFT                                    2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_AHBERROR_BMSK                                          0x2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_AHBERROR_SHFT                                            1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_GPUIDLE_BMSK                                           0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_MASK_GPUIDLE_SHFT                                             0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_ADDR                                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0xf0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_OFFS                                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0xf0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_RMSK                                            0xdff7fffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_ISDBUNDERDEBUG_BMSK                             0x80000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_ISDBUNDERDEBUG_SHFT                                     31u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_ISDBCPUIRQ_BMSK                                 0x40000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_ISDBCPUIRQ_SHFT                                         30u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_TSBWRITEERROR_BMSK                              0x10000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_TSBWRITEERROR_SHFT                                      28u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_DEBUGBUSINTERRUPT1_BMSK                          0x8000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_DEBUGBUSINTERRUPT1_SHFT                                 27u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_DEBUGBUSINTERRUPT0_BMSK                          0x4000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_DEBUGBUSINTERRUPT0_SHFT                                 26u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_UCHETRAPINTERRUPT_BMSK                           0x2000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_UCHETRAPINTERRUPT_SHFT                                  25u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_OUTOFBOUNDACCESS_BMSK                            0x1000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_OUTOFBOUNDACCESS_SHFT                                   24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_HANGDETECTINTERRUPT_BMSK                          0x800000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_HANGDETECTINTERRUPT_SHFT                                23u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_ATBBUSOVERFLOW_BMSK                               0x400000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_ATBBUSOVERFLOW_SHFT                                     22u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_CACHE_FLUSH_TS_LPAC_BMSK                          0x200000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_CACHE_FLUSH_TS_LPAC_SHFT                                21u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_CACHE_FLUSH_TS_BMSK                               0x100000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_CACHE_FLUSH_TS_SHFT                                     20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_WT_DONE_TS_BMSK                                    0x40000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_WT_DONE_TS_SHFT                                         18u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_RB_DONE_TS_BMSK                                    0x20000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_RB_DONE_TS_SHFT                                         17u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_RBINTERRUPTLPAC_BMSK                               0x10000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_RBINTERRUPTLPAC_SHFT                                    16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_RBINTERRUPT_BMSK                                    0x8000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_RBINTERRUPT_SHFT                                        15u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_IB1INTERRUPT_BMSK                                   0x4000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_IB1INTERRUPT_SHFT                                       14u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_IB2INTERRUPT_BMSK                                   0x2000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_IB2INTERRUPT_SHFT                                       13u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_CCU_RESOLVE_TS_BMSK                                 0x1000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_CCU_RESOLVE_TS_SHFT                                     12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_CCU_FLUSH_COLOR_TS_BMSK                              0x800u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_CCU_FLUSH_COLOR_TS_SHFT                                 11u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_CCU_FLUSH_DEPTH_TS_BMSK                              0x400u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_CCU_FLUSH_DEPTH_TS_SHFT                                 10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_HWERROR_BMSK                                         0x200u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_HWERROR_SHFT                                             9u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_SWINTERRUPT_BMSK                                     0x100u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_SWINTERRUPT_SHFT                                         8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_GPCERROR_BMSK                                         0x80u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_GPCERROR_SHFT                                            7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_ATBASYNCFIFOOVERFLOW_BMSK                             0x40u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_ATBASYNCFIFOOVERFLOW_SHFT                                6u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_CPIPCINT1_BMSK                                        0x20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_CPIPCINT1_SHFT                                           5u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_CPIPCINT0_BMSK                                        0x10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_CPIPCINT0_SHFT                                           4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_IB1INTERRUPTLPAC_BMSK                                  0x8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_IB1INTERRUPTLPAC_SHFT                                    3u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_IB2INTERRUPTLPAC_BMSK                                  0x4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_IB2INTERRUPTLPAC_SHFT                                    2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_AHBERROR_BMSK                                          0x2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_AHBERROR_SHFT                                            1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_GPUIDLE_BMSK                                           0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_MASK_GPUIDLE_SHFT                                             0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_SP_HYST_CNT_ADDR                                           (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x108u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_SP_HYST_CNT_OFFS                                           (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x108u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_SP_HYST_CNT_RMSK                                                0xfffu
#define HWIO_SAIL_TO_MD_GPU_RBBM_SP_HYST_CNT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_SP_HYST_CNT_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_SP_HYST_CNT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_SP_HYST_CNT_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_SP_HYST_CNT_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_SP_HYST_CNT_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_SP_HYST_CNT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_SP_HYST_CNT_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_SP_HYST_CNT_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_SP_HYST_CNT_SPLPCNT_BMSK                                        0xfffu
#define HWIO_SAIL_TO_MD_GPU_RBBM_SP_HYST_CNT_SPLPCNT_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_SW_RESET_CMD_ADDR                                          (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x10cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_SW_RESET_CMD_OFFS                                          (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x10cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_SW_RESET_CMD_RMSK                                                 0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_SW_RESET_CMD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_SW_RESET_CMD_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_SW_RESET_CMD_GLSWRESET_BMSK                                       0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_SW_RESET_CMD_GLSWRESET_SHFT                                         0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_RAC_THRESHOLD_CNT_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x110u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_RAC_THRESHOLD_CNT_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x110u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_RAC_THRESHOLD_CNT_RMSK                                           0xffu
#define HWIO_SAIL_TO_MD_GPU_RBBM_RAC_THRESHOLD_CNT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_RAC_THRESHOLD_CNT_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_RAC_THRESHOLD_CNT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_RAC_THRESHOLD_CNT_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_RAC_THRESHOLD_CNT_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_RAC_THRESHOLD_CNT_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_RAC_THRESHOLD_CNT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_RAC_THRESHOLD_CNT_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_RAC_THRESHOLD_CNT_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_RAC_THRESHOLD_CNT_CGCTHRESHOLDRAC_BMSK                           0xffu
#define HWIO_SAIL_TO_MD_GPU_RBBM_RAC_THRESHOLD_CNT_CGCTHRESHOLDRAC_SHFT                              0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_ADDR                                    (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x114u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_OFFS                                    (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x114u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_RMSK                                     0xfffffc0ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_HLSQ_SPTPSWRESET_BMSK                    0x8000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_HLSQ_SPTPSWRESET_SHFT                           27u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_GPCSWRESET_BMSK                          0x4000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_GPCSWRESET_SHFT                                 26u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_VFDSWRESET_BMSK                          0x3c00000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_VFDSWRESET_SHFT                                 22u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_VBIFSWRESET_BMSK                          0x3c0000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_VBIFSWRESET_SHFT                                18u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_RBBMSWRESET_BMSK                           0x20000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_RBBMSWRESET_SHFT                                17u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_GPMUSWRESET_BMSK                           0x10000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_GPMUSWRESET_SHFT                                16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_UCHESWRESET_BMSK                            0x8000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_UCHESWRESET_SHFT                                15u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_VSCSWRESET_BMSK                             0x4000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_VSCSWRESET_SHFT                                 14u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_RASSWRESET_BMSK                             0x2000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_RASSWRESET_SHFT                                 13u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_TSESWRESET_BMSK                             0x1000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_TSESWRESET_SHFT                                 12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_HLSQSWRESET_BMSK                             0x800u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_HLSQSWRESET_SHFT                                11u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_VPCSWRESET_BMSK                              0x400u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_VPCSWRESET_SHFT                                 10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_VFDPSWRESET_BMSK                             0x200u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_VFDPSWRESET_SHFT                                 9u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_TESSSWRESET_BMSK                             0x100u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_TESSSWRESET_SHFT                                 8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_PCSWRESET_BMSK                                0x80u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_PCSWRESET_SHFT                                   7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_CPSWRESET_BMSK                                0x40u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD_CPSWRESET_SHFT                                   6u

#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_ADDR                                   (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x118u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_OFFS                                   (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x118u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_RMSK                                   0x23fffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_TEXFCHESWRESET_BMSK                    0x20000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_TEXFCHESWRESET_SHFT                            29u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_CRESWRESET_BMSK                         0x2000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_CRESWRESET_SHFT                                25u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_RACSWRESET_BMSK                         0x1000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_RACSWRESET_SHFT                                24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_LARCSWRESET_BMSK                         0x800000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_LARCSWRESET_SHFT                               23u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_HMSWRESET_BMSK                           0x400000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_HMSWRESET_SHFT                                 22u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_RBPSWRESET_BMSK                          0x200000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_RBPSWRESET_SHFT                                21u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_DCOMSWRESET_BMSK                         0x100000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_DCOMSWRESET_SHFT                               20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_COMSWRESET_BMSK                           0x80000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_COMSWRESET_SHFT                                19u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_LRZSWRESET_BMSK                           0x40000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_LRZSWRESET_SHFT                                18u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_CCUFCHESWRESET_BMSK                       0x20000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_CCUFCHESWRESET_SHFT                            17u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_A2DSWRESET_BMSK                           0x10000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_A2DSWRESET_SHFT                                16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_CCUSWRESET_BMSK                            0xf000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_CCUSWRESET_SHFT                                12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_RBSWRESET_BMSK                              0xf00u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_RBSWRESET_SHFT                                  8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_TPSWRESET_BMSK                               0xf0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_TPSWRESET_SHFT                                  4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_SPSWRESET_BMSK                                0xfu
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_CMD2_SPSWRESET_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_RESET_CYCLES_ADDR                                          (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x11cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_RESET_CYCLES_OFFS                                          (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x11cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_RESET_CYCLES_RMSK                                              0xffffu
#define HWIO_SAIL_TO_MD_GPU_RBBM_RESET_CYCLES_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_RESET_CYCLES_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_RESET_CYCLES_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_RESET_CYCLES_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_RESET_CYCLES_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_RESET_CYCLES_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_RESET_CYCLES_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_RESET_CYCLES_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_RESET_CYCLES_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_RESET_CYCLES_CYCLES_BMSK                                       0xffffu
#define HWIO_SAIL_TO_MD_GPU_RBBM_RESET_CYCLES_CYCLES_SHFT                                            0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_ASSERT_CMD_ADDR                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x120u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_ASSERT_CMD_OFFS                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x120u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_ASSERT_CMD_RMSK                                    0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_ASSERT_CMD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_ASSERT_CMD_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_ASSERT_CMD_BLOCKSWRESET_BMSK                       0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_ASSERT_CMD_BLOCKSWRESET_SHFT                         0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_ADDR                                   (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x124u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_OFFS                                   (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x124u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_RMSK                                    0xfffffc0ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_HLSQ_SPTPSWRESET_BMSK                   0x8000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_HLSQ_SPTPSWRESET_SHFT                          27u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_GPCSWRESET_BMSK                         0x4000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_GPCSWRESET_SHFT                                26u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_VFDSWRESET_BMSK                         0x3c00000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_VFDSWRESET_SHFT                                22u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_VBIFSWRESET_BMSK                         0x3c0000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_VBIFSWRESET_SHFT                               18u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_RBBMSWRESET_BMSK                          0x20000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_RBBMSWRESET_SHFT                               17u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_GPMUSWRESET_BMSK                          0x10000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_GPMUSWRESET_SHFT                               16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_UCHESWRESET_BMSK                           0x8000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_UCHESWRESET_SHFT                               15u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_VSCSWRESET_BMSK                            0x4000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_VSCSWRESET_SHFT                                14u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_RASSWRESET_BMSK                            0x2000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_RASSWRESET_SHFT                                13u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_TSESWRESET_BMSK                            0x1000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_TSESWRESET_SHFT                                12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_HLSQSWRESET_BMSK                            0x800u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_HLSQSWRESET_SHFT                               11u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_VPCSWRESET_BMSK                             0x400u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_VPCSWRESET_SHFT                                10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_VFDPSWRESET_BMSK                            0x200u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_VFDPSWRESET_SHFT                                9u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_TESSSWRESET_BMSK                            0x100u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_TESSSWRESET_SHFT                                8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_PCSWRESET_BMSK                               0x80u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_PCSWRESET_SHFT                                  7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_CPSWRESET_BMSK                               0x40u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL1_CPSWRESET_SHFT                                  6u

#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_ADDR                                   (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x128u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_OFFS                                   (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x128u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_RMSK                                   0x23fffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_TEXFCHESWRESET_BMSK                    0x20000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_TEXFCHESWRESET_SHFT                            29u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_CRESWRESET_BMSK                         0x2000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_CRESWRESET_SHFT                                25u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_RACSWRESET_BMSK                         0x1000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_RACSWRESET_SHFT                                24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_LARCSWRESET_BMSK                         0x800000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_LARCSWRESET_SHFT                               23u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_HMSWRESET_BMSK                           0x400000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_HMSWRESET_SHFT                                 22u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_RBPSWRESET_BMSK                          0x200000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_RBPSWRESET_SHFT                                21u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_DCOMSWRESET_BMSK                         0x100000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_DCOMSWRESET_SHFT                               20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_COMSWRESET_BMSK                           0x80000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_COMSWRESET_SHFT                                19u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_LRZSWRESET_BMSK                           0x40000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_LRZSWRESET_SHFT                                18u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_CCUFCHESWRESET_BMSK                       0x20000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_CCUFCHESWRESET_SHFT                            17u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_A2DSWRESET_BMSK                           0x10000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_A2DSWRESET_SHFT                                16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_CCUSWRESET_BMSK                            0xf000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_CCUSWRESET_SHFT                                12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_RBSWRESET_BMSK                              0xf00u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_RBSWRESET_SHFT                                  8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_TPSWRESET_BMSK                               0xf0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_TPSWRESET_SHFT                                  4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_SPSWRESET_BMSK                                0xfu
#define HWIO_SAIL_TO_MD_GPU_RBBM_BLOCK_SW_RESET_SEL2_SPSWRESET_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x140u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x140u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_RMSK                                        0x7fffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP18_BMSK                                0x40000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP18_SHFT                                     18u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP17_BMSK                                0x20000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP17_SHFT                                     17u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP16_BMSK                                0x10000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP16_SHFT                                     16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP15_BMSK                                 0x8000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP15_SHFT                                     15u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP14_BMSK                                 0x4000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP14_SHFT                                     14u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP13_BMSK                                 0x2000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP13_SHFT                                     13u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP12_BMSK                                 0x1000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP12_SHFT                                     12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP11_BMSK                                  0x800u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP11_SHFT                                     11u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP10_BMSK                                  0x400u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP10_SHFT                                     10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP9_BMSK                                   0x200u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP9_SHFT                                       9u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP8_BMSK                                   0x100u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP8_SHFT                                       8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP7_BMSK                                    0x80u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP7_SHFT                                       7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP6_BMSK                                    0x40u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP6_SHFT                                       6u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP5_BMSK                                    0x20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP5_SHFT                                       5u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP4_BMSK                                    0x10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP4_SHFT                                       4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP3_BMSK                                     0x8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP3_SHFT                                       3u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP2_BMSK                                     0x4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP2_SHFT                                       2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP1_BMSK                                     0x2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP1_SHFT                                       1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP0_BMSK                                     0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GX_RETENTION_CNTL_GROUP0_SHFT                                       0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_EVENT_MUX_CNTL_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x158u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_EVENT_MUX_CNTL_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x158u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_EVENT_MUX_CNTL_RMSK                                            0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_EVENT_MUX_CNTL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_HW_EVENT_MUX_CNTL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_EVENT_MUX_CNTL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_HW_EVENT_MUX_CNTL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_EVENT_MUX_CNTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_HW_EVENT_MUX_CNTL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_EVENT_MUX_CNTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_HW_EVENT_MUX_CNTL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_HW_EVENT_MUX_CNTL_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_EVENT_MUX_CNTL_INSTANCESEL_BMSK                                0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_HW_EVENT_MUX_CNTL_INSTANCESEL_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GLOBAL_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x2b4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GLOBAL_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x2b4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GLOBAL_RMSK                                            0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GLOBAL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GLOBAL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GLOBAL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GLOBAL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GLOBAL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GLOBAL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GLOBAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GLOBAL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GLOBAL_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GLOBAL_GLOBALFORCEON_BMSK                              0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GLOBAL_GLOBALFORCEON_SHFT                                0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_ADDR                                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x2b8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_OFFS                                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x2b8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RMSK                                            0xfffcfffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CGCCNTLHM_BMSK                                  0xc0000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CGCCNTLHM_SHFT                                          30u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CGCCNTLVBIF_BMSK                                0x30000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CGCCNTLVBIF_SHFT                                        28u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CGCCNTLUCHE_BMSK                                 0xc000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CGCCNTLUCHE_SHFT                                        26u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CGCCNTLVSC_BMSK                                  0x3000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CGCCNTLVSC_SHFT                                         24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CGCCNTLRAS_BMSK                                   0xc00000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CGCCNTLRAS_SHFT                                         22u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CGCCNTLTSE_BMSK                                   0x300000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CGCCNTLTSE_SHFT                                         20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CGCCNTLHLSQ_BMSK                                   0xc0000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CGCCNTLHLSQ_SHFT                                        18u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CGCCNTLCCU_BMSK                                     0xc000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CGCCNTLCCU_SHFT                                         14u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CGCCNTLGPC_BMSK                                     0x3000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CGCCNTLGPC_SHFT                                         12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CGCCNTLCP_BMSK                                       0xc00u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CGCCNTLCP_SHFT                                          10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CGCCNTLLRZ_BMSK                                      0x300u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CGCCNTLLRZ_SHFT                                          8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CGCCNTLACR_BMSK                                       0xc0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CGCCNTLACR_SHFT                                          6u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CGCCNTLRBBM_BMSK                                      0x30u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CGCCNTLRBBM_SHFT                                         4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CGCCNTLDBGC_BMSK                                       0xcu
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CGCCNTLDBGC_SHFT                                         2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CGCCNTLSPTP_BMSK                                       0x3u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CGCCNTLSPTP_SHFT                                         0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_SP0_ADDR                                        (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x2c0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_SP0_OFFS                                        (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x2c0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_SP0_RMSK                                        0x77777777ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_SP0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_SP0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_SP0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_SP0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_SP0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_SP0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_SP0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_SP0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_SP0_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_SP0_CGCCNTLSPMODE7_BMSK                         0x70000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_SP0_CGCCNTLSPMODE7_SHFT                                 28u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_SP0_CGCCNTLSPMODE6_BMSK                          0x7000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_SP0_CGCCNTLSPMODE6_SHFT                                 24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_SP0_CGCCNTLSPMODE5_BMSK                           0x700000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_SP0_CGCCNTLSPMODE5_SHFT                                 20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_SP0_CGCCNTLSPMODE4_BMSK                            0x70000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_SP0_CGCCNTLSPMODE4_SHFT                                 16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_SP0_CGCCNTLSPMODE3_BMSK                             0x7000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_SP0_CGCCNTLSPMODE3_SHFT                                 12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_SP0_CGCCNTLSPMODE2_BMSK                              0x700u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_SP0_CGCCNTLSPMODE2_SHFT                                  8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_SP0_CGCCNTLSPMODE1_BMSK                               0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_SP0_CGCCNTLSPMODE1_SHFT                                  4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_SP0_CGCCNTLSPMODE0_BMSK                                0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_SP0_CGCCNTLSPMODE0_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_SP0_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x2d0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_SP0_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x2d0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_SP0_RMSK                                        0x7777777ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_SP0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_SP0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_SP0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_SP0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_SP0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_SP0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_SP0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_SP0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_SP0_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_SP0_CGCCNTLSPMODE14_BMSK                        0x7000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_SP0_CGCCNTLSPMODE14_SHFT                               24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_SP0_CGCCNTLSPMODE13_BMSK                         0x700000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_SP0_CGCCNTLSPMODE13_SHFT                               20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_SP0_CGCCNTLSPMODE12_BMSK                          0x70000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_SP0_CGCCNTLSPMODE12_SHFT                               16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_SP0_CGCCNTLSPMODE11_BMSK                           0x7000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_SP0_CGCCNTLSPMODE11_SHFT                               12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_SP0_CGCCNTLSPMODE10_BMSK                            0x700u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_SP0_CGCCNTLSPMODE10_SHFT                                8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_SP0_CGCCNTLSPMODE9_BMSK                              0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_SP0_CGCCNTLSPMODE9_SHFT                                 4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_SP0_CGCCNTLSPMODE8_BMSK                               0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_SP0_CGCCNTLSPMODE8_SHFT                                 0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_SP0_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x2e0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_SP0_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x2e0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_SP0_RMSK                                         0x1c71c7ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_SP0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_SP0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_SP0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_SP0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_SP0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_SP0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_SP0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_SP0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_SP0_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_SP0_CGCDELAYSP3_BMSK                             0x1c0000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_SP0_CGCDELAYSP3_SHFT                                   18u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_SP0_CGCDELAYSP2_BMSK                               0x7000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_SP0_CGCDELAYSP2_SHFT                                   12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_SP0_CGCDELAYSP1_BMSK                                0x1c0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_SP0_CGCDELAYSP1_SHFT                                    6u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_SP0_CGCDELAYSP0_BMSK                                  0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_SP0_CGCDELAYSP0_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_SP0_ADDR                                        (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x2f0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_SP0_OFFS                                        (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x2f0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_SP0_RMSK                                          0x3cf3cful
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_SP0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_SP0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_SP0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_SP0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_SP0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_SP0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_SP0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_SP0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_SP0_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_SP0_CGCHYSTSP3_BMSK                               0x3c0000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_SP0_CGCHYSTSP3_SHFT                                     18u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_SP0_CGCHYSTSP2_BMSK                                 0xf000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_SP0_CGCHYSTSP2_SHFT                                     12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_SP0_CGCHYSTSP1_BMSK                                  0x3c0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_SP0_CGCHYSTSP1_SHFT                                      6u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_SP0_CGCHYSTSP0_BMSK                                    0xfu
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_SP0_CGCHYSTSP0_SHFT                                      0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TP0_ADDR                                        (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x300u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TP0_OFFS                                        (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x300u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TP0_RMSK                                        0x77777777ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TP0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TP0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TP0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TP0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TP0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TP0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TP0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TP0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TP0_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TP0_CGCCNTLTPMODE7_BMSK                         0x70000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TP0_CGCCNTLTPMODE7_SHFT                                 28u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TP0_CGCCNTLTPMODE6_BMSK                          0x7000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TP0_CGCCNTLTPMODE6_SHFT                                 24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TP0_CGCCNTLTPMODE5_BMSK                           0x700000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TP0_CGCCNTLTPMODE5_SHFT                                 20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TP0_CGCCNTLTPMODE4_BMSK                            0x70000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TP0_CGCCNTLTPMODE4_SHFT                                 16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TP0_CGCCNTLTPMODE3_BMSK                             0x7000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TP0_CGCCNTLTPMODE3_SHFT                                 12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TP0_CGCCNTLTPMODE2_BMSK                              0x700u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TP0_CGCCNTLTPMODE2_SHFT                                  8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TP0_CGCCNTLTPMODE1_BMSK                               0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TP0_CGCCNTLTPMODE1_SHFT                                  4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TP0_CGCCNTLTPMODE0_BMSK                                0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TP0_CGCCNTLTPMODE0_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_TP0_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x310u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_TP0_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x310u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_TP0_RMSK                                       0x77777777ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_TP0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_TP0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_TP0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_TP0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_TP0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_TP0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_TP0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_TP0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_TP0_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_TP0_CGCCNTLTPMODE15_BMSK                       0x70000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_TP0_CGCCNTLTPMODE15_SHFT                               28u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_TP0_CGCCNTLTPMODE14_BMSK                        0x7000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_TP0_CGCCNTLTPMODE14_SHFT                               24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_TP0_CGCCNTLTPMODE13_BMSK                         0x700000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_TP0_CGCCNTLTPMODE13_SHFT                               20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_TP0_CGCCNTLTPMODE12_BMSK                          0x70000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_TP0_CGCCNTLTPMODE12_SHFT                               16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_TP0_CGCCNTLTPMODE11_BMSK                           0x7000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_TP0_CGCCNTLTPMODE11_SHFT                               12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_TP0_CGCCNTLTPMODE10_BMSK                            0x700u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_TP0_CGCCNTLTPMODE10_SHFT                                8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_TP0_CGCCNTLTPMODE9_BMSK                              0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_TP0_CGCCNTLTPMODE9_SHFT                                 4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_TP0_CGCCNTLTPMODE8_BMSK                               0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_TP0_CGCCNTLTPMODE8_SHFT                                 0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL3_TP0_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x320u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL3_TP0_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x320u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL3_TP0_RMSK                                       0x77777777ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL3_TP0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL3_TP0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL3_TP0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL3_TP0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL3_TP0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL3_TP0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL3_TP0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL3_TP0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL3_TP0_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL3_TP0_CGCCNTLTPMODE23_BMSK                       0x70000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL3_TP0_CGCCNTLTPMODE23_SHFT                               28u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL3_TP0_CGCCNTLTPMODE22_BMSK                        0x7000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL3_TP0_CGCCNTLTPMODE22_SHFT                               24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL3_TP0_CGCCNTLTPMODE21_BMSK                         0x700000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL3_TP0_CGCCNTLTPMODE21_SHFT                               20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL3_TP0_CGCCNTLTPMODE20_BMSK                          0x70000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL3_TP0_CGCCNTLTPMODE20_SHFT                               16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL3_TP0_CGCCNTLTPMODE19_BMSK                           0x7000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL3_TP0_CGCCNTLTPMODE19_SHFT                               12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL3_TP0_CGCCNTLTPMODE18_BMSK                            0x700u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL3_TP0_CGCCNTLTPMODE18_SHFT                                8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL3_TP0_CGCCNTLTPMODE17_BMSK                             0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL3_TP0_CGCCNTLTPMODE17_SHFT                                4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL3_TP0_CGCCNTLTPMODE16_BMSK                              0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL3_TP0_CGCCNTLTPMODE16_SHFT                                0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL4_TP0_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x330u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL4_TP0_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x330u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL4_TP0_RMSK                                          0x77777ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL4_TP0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL4_TP0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL4_TP0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL4_TP0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL4_TP0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL4_TP0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL4_TP0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL4_TP0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL4_TP0_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL4_TP0_CGCCNTLTPMODE28_BMSK                          0x70000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL4_TP0_CGCCNTLTPMODE28_SHFT                               16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL4_TP0_CGCCNTLTPMODE27_BMSK                           0x7000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL4_TP0_CGCCNTLTPMODE27_SHFT                               12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL4_TP0_CGCCNTLTPMODE26_BMSK                            0x700u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL4_TP0_CGCCNTLTPMODE26_SHFT                                8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL4_TP0_CGCCNTLTPMODE25_BMSK                             0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL4_TP0_CGCCNTLTPMODE25_SHFT                                4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL4_TP0_CGCCNTLTPMODE24_BMSK                              0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL4_TP0_CGCCNTLTPMODE24_SHFT                                0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TP0_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x340u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TP0_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x340u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TP0_RMSK                                       0x77777777ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TP0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TP0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TP0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TP0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TP0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TP0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TP0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TP0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TP0_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TP0_CGCCNTLTPDELAY7_BMSK                       0x70000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TP0_CGCCNTLTPDELAY7_SHFT                               28u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TP0_CGCCNTLTPDELAY6_BMSK                        0x7000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TP0_CGCCNTLTPDELAY6_SHFT                               24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TP0_CGCCNTLTPDELAY5_BMSK                         0x700000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TP0_CGCCNTLTPDELAY5_SHFT                               20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TP0_CGCCNTLTPDELAY4_BMSK                          0x70000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TP0_CGCCNTLTPDELAY4_SHFT                               16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TP0_CGCCNTLTPDELAY3_BMSK                           0x7000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TP0_CGCCNTLTPDELAY3_SHFT                               12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TP0_CGCCNTLTPDELAY2_BMSK                            0x700u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TP0_CGCCNTLTPDELAY2_SHFT                                8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TP0_CGCCNTLTPDELAY1_BMSK                             0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TP0_CGCCNTLTPDELAY1_SHFT                                4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TP0_CGCCNTLTPDELAY0_BMSK                              0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TP0_CGCCNTLTPDELAY0_SHFT                                0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY2_TP0_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x350u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY2_TP0_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x350u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY2_TP0_RMSK                                      0x77777777ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY2_TP0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY2_TP0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY2_TP0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY2_TP0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY2_TP0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY2_TP0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY2_TP0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY2_TP0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY2_TP0_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY2_TP0_CGCCNTLTPDELAY15_BMSK                     0x70000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY2_TP0_CGCCNTLTPDELAY15_SHFT                             28u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY2_TP0_CGCCNTLTPDELAY14_BMSK                      0x7000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY2_TP0_CGCCNTLTPDELAY14_SHFT                             24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY2_TP0_CGCCNTLTPDELAY13_BMSK                       0x700000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY2_TP0_CGCCNTLTPDELAY13_SHFT                             20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY2_TP0_CGCCNTLTPDELAY12_BMSK                        0x70000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY2_TP0_CGCCNTLTPDELAY12_SHFT                             16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY2_TP0_CGCCNTLTPDELAY11_BMSK                         0x7000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY2_TP0_CGCCNTLTPDELAY11_SHFT                             12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY2_TP0_CGCCNTLTPDELAY10_BMSK                          0x700u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY2_TP0_CGCCNTLTPDELAY10_SHFT                              8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY2_TP0_CGCCNTLTPDELAY9_BMSK                            0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY2_TP0_CGCCNTLTPDELAY9_SHFT                               4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY2_TP0_CGCCNTLTPDELAY8_BMSK                             0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY2_TP0_CGCCNTLTPDELAY8_SHFT                               0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY3_TP0_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x360u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY3_TP0_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x360u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY3_TP0_RMSK                                      0x77777777ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY3_TP0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY3_TP0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY3_TP0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY3_TP0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY3_TP0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY3_TP0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY3_TP0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY3_TP0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY3_TP0_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY3_TP0_CGCCNTLTPDELAY23_BMSK                     0x70000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY3_TP0_CGCCNTLTPDELAY23_SHFT                             28u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY3_TP0_CGCCNTLTPDELAY22_BMSK                      0x7000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY3_TP0_CGCCNTLTPDELAY22_SHFT                             24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY3_TP0_CGCCNTLTPDELAY21_BMSK                       0x700000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY3_TP0_CGCCNTLTPDELAY21_SHFT                             20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY3_TP0_CGCCNTLTPDELAY20_BMSK                        0x70000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY3_TP0_CGCCNTLTPDELAY20_SHFT                             16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY3_TP0_CGCCNTLTPDELAY19_BMSK                         0x7000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY3_TP0_CGCCNTLTPDELAY19_SHFT                             12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY3_TP0_CGCCNTLTPDELAY18_BMSK                          0x700u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY3_TP0_CGCCNTLTPDELAY18_SHFT                              8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY3_TP0_CGCCNTLTPDELAY17_BMSK                           0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY3_TP0_CGCCNTLTPDELAY17_SHFT                              4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY3_TP0_CGCCNTLTPDELAY16_BMSK                            0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY3_TP0_CGCCNTLTPDELAY16_SHFT                              0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY4_TP0_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x370u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY4_TP0_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x370u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY4_TP0_RMSK                                         0x77777ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY4_TP0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY4_TP0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY4_TP0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY4_TP0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY4_TP0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY4_TP0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY4_TP0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY4_TP0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY4_TP0_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY4_TP0_CGCCNTLTPDELAY28_BMSK                        0x70000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY4_TP0_CGCCNTLTPDELAY28_SHFT                             16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY4_TP0_CGCCNTLTPDELAY27_BMSK                         0x7000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY4_TP0_CGCCNTLTPDELAY27_SHFT                             12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY4_TP0_CGCCNTLTPDELAY26_BMSK                          0x700u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY4_TP0_CGCCNTLTPDELAY26_SHFT                              8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY4_TP0_CGCCNTLTPDELAY25_BMSK                           0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY4_TP0_CGCCNTLTPDELAY25_SHFT                              4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY4_TP0_CGCCNTLTPDELAY24_BMSK                            0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY4_TP0_CGCCNTLTPDELAY24_SHFT                              0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TP0_ADDR                                        (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x380u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TP0_OFFS                                        (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x380u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TP0_RMSK                                        0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TP0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TP0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TP0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TP0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TP0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TP0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TP0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TP0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TP0_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TP0_CGCHYSTTP7_BMSK                             0xf0000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TP0_CGCHYSTTP7_SHFT                                     28u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TP0_CGCHYSTTP6_BMSK                              0xf000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TP0_CGCHYSTTP6_SHFT                                     24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TP0_CGCHYSTTP5_BMSK                               0xf00000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TP0_CGCHYSTTP5_SHFT                                     20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TP0_CGCHYSTTP4_BMSK                                0xf0000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TP0_CGCHYSTTP4_SHFT                                     16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TP0_CGCHYSTTP3_BMSK                                 0xf000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TP0_CGCHYSTTP3_SHFT                                     12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TP0_CGCHYSTTP2_BMSK                                  0xf00u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TP0_CGCHYSTTP2_SHFT                                      8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TP0_CGCHYSTTP1_BMSK                                   0xf0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TP0_CGCHYSTTP1_SHFT                                      4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TP0_CGCHYSTTP0_BMSK                                    0xfu
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TP0_CGCHYSTTP0_SHFT                                      0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST2_TP0_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x390u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST2_TP0_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x390u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST2_TP0_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST2_TP0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST2_TP0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST2_TP0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST2_TP0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST2_TP0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST2_TP0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST2_TP0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST2_TP0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST2_TP0_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST2_TP0_CGCHYSTTP15_BMSK                           0xf0000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST2_TP0_CGCHYSTTP15_SHFT                                   28u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST2_TP0_CGCHYSTTP14_BMSK                            0xf000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST2_TP0_CGCHYSTTP14_SHFT                                   24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST2_TP0_CGCHYSTTP13_BMSK                             0xf00000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST2_TP0_CGCHYSTTP13_SHFT                                   20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST2_TP0_CGCHYSTTP12_BMSK                              0xf0000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST2_TP0_CGCHYSTTP12_SHFT                                   16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST2_TP0_CGCHYSTTP11_BMSK                               0xf000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST2_TP0_CGCHYSTTP11_SHFT                                   12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST2_TP0_CGCHYSTTP10_BMSK                                0xf00u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST2_TP0_CGCHYSTTP10_SHFT                                    8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST2_TP0_CGCHYSTTP9_BMSK                                  0xf0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST2_TP0_CGCHYSTTP9_SHFT                                     4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST2_TP0_CGCHYSTTP8_BMSK                                   0xfu
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST2_TP0_CGCHYSTTP8_SHFT                                     0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST3_TP0_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x3a0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST3_TP0_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x3a0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST3_TP0_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST3_TP0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST3_TP0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST3_TP0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST3_TP0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST3_TP0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST3_TP0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST3_TP0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST3_TP0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST3_TP0_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST3_TP0_CGCHYSTTP23_BMSK                           0xf0000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST3_TP0_CGCHYSTTP23_SHFT                                   28u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST3_TP0_CGCHYSTTP22_BMSK                            0xf000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST3_TP0_CGCHYSTTP22_SHFT                                   24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST3_TP0_CGCHYSTTP21_BMSK                             0xf00000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST3_TP0_CGCHYSTTP21_SHFT                                   20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST3_TP0_CGCHYSTTP20_BMSK                              0xf0000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST3_TP0_CGCHYSTTP20_SHFT                                   16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST3_TP0_CGCHYSTTP19_BMSK                               0xf000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST3_TP0_CGCHYSTTP19_SHFT                                   12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST3_TP0_CGCHYSTTP18_BMSK                                0xf00u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST3_TP0_CGCHYSTTP18_SHFT                                    8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST3_TP0_CGCHYSTTP17_BMSK                                 0xf0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST3_TP0_CGCHYSTTP17_SHFT                                    4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST3_TP0_CGCHYSTTP16_BMSK                                  0xfu
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST3_TP0_CGCHYSTTP16_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST4_TP0_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x3b0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST4_TP0_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x3b0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST4_TP0_RMSK                                          0xffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST4_TP0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST4_TP0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST4_TP0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST4_TP0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST4_TP0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST4_TP0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST4_TP0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST4_TP0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST4_TP0_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST4_TP0_CGCHYSTTP28_BMSK                              0xf0000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST4_TP0_CGCHYSTTP28_SHFT                                   16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST4_TP0_CGCHYSTTP27_BMSK                               0xf000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST4_TP0_CGCHYSTTP27_SHFT                                   12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST4_TP0_CGCHYSTTP26_BMSK                                0xf00u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST4_TP0_CGCHYSTTP26_SHFT                                    8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST4_TP0_CGCHYSTTP25_BMSK                                 0xf0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST4_TP0_CGCHYSTTP25_SHFT                                    4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST4_TP0_CGCHYSTTP24_BMSK                                  0xfu
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST4_TP0_CGCHYSTTP24_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RB0_ADDR                                        (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x3c0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RB0_OFFS                                        (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x3c0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RB0_RMSK                                        0x77777777ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RB0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RB0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RB0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RB0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RB0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RB0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RB0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RB0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RB0_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RB0_CGCCNTLRBMODE7_BMSK                         0x70000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RB0_CGCCNTLRBMODE7_SHFT                                 28u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RB0_CGCCNTLRBMODE6_BMSK                          0x7000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RB0_CGCCNTLRBMODE6_SHFT                                 24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RB0_CGCCNTLRBMODE5_BMSK                           0x700000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RB0_CGCCNTLRBMODE5_SHFT                                 20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RB0_CGCCNTLRBMODE4_BMSK                            0x70000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RB0_CGCCNTLRBMODE4_SHFT                                 16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RB0_CGCCNTLRBMODE3_BMSK                             0x7000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RB0_CGCCNTLRBMODE3_SHFT                                 12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RB0_CGCCNTLRBMODE2_BMSK                              0x700u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RB0_CGCCNTLRBMODE2_SHFT                                  8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RB0_CGCCNTLRBMODE1_BMSK                               0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RB0_CGCCNTLRBMODE1_SHFT                                  4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RB0_CGCCNTLRBMODE0_BMSK                                0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RB0_CGCCNTLRBMODE0_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RB0_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x3d0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RB0_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x3d0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RB0_RMSK                                        0x3f07777ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RB0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RB0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RB0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RB0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RB0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RB0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RB0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RB0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RB0_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RB0_CGCCNTLRACBATCHMODE0_BMSK                   0x3800000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RB0_CGCCNTLRACBATCHMODE0_SHFT                          23u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RB0_CGCCNTLRACMODE0_BMSK                         0x700000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RB0_CGCCNTLRACMODE0_SHFT                               20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RB0_CGCCNTLRBMODE11_BMSK                           0x7000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RB0_CGCCNTLRBMODE11_SHFT                               12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RB0_CGCCNTLRBMODE10_BMSK                            0x700u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RB0_CGCCNTLRBMODE10_SHFT                                8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RB0_CGCCNTLRBMODE9_BMSK                              0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RB0_CGCCNTLRBMODE9_SHFT                                 4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RB0_CGCCNTLRBMODE8_BMSK                               0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RB0_CGCCNTLRBMODE8_SHFT                                 0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CCU0_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x3e0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CCU0_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x3e0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CCU0_RMSK                                           0x7770u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CCU0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CCU0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CCU0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CCU0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CCU0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CCU0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CCU0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CCU0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CCU0_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CCU0_CGCCNTLCCUZCMODE_BMSK                          0x7000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CCU0_CGCCNTLCCUZCMODE_SHFT                              12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CCU0_CGCCNTLCCUCMODE_BMSK                            0x700u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CCU0_CGCCNTLCCUCMODE_SHFT                                8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CCU0_CGCCNTLCCUZMODE_BMSK                             0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_CCU0_CGCCNTLCCUZMODE_SHFT                                4u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RB_CCU0_ADDR                                    (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x400u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RB_CCU0_OFFS                                    (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x400u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RB_CCU0_RMSK                                    0xff000f0ful
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RB_CCU0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RB_CCU0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RB_CCU0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RB_CCU0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RB_CCU0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RB_CCU0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RB_CCU0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RB_CCU0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RB_CCU0_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RB_CCU0_CGCHYSTRAC_BATCH_BMSK                   0xf0000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RB_CCU0_CGCHYSTRAC_BATCH_SHFT                           28u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RB_CCU0_CGCHYSTRAC_BMSK                          0xf000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RB_CCU0_CGCHYSTRAC_SHFT                                 24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RB_CCU0_CGCHYSTCCU_BMSK                              0xf00u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RB_CCU0_CGCHYSTCCU_SHFT                                  8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RB_CCU0_CGCHYSTRB_BMSK                                 0xfu
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RB_CCU0_CGCHYSTRB_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RAC_ADDR                                        (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x410u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RAC_OFFS                                        (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x410u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RAC_RMSK                                        0x77777777ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RAC_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RAC_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RAC_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RAC_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RAC_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RAC_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RAC_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RAC_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RAC_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RAC_CGCCNTLCREMODE_BMSK                         0x70000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RAC_CGCCNTLCREMODE_SHFT                                 28u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RAC_CGCCNTLLRZ2MODE_BMSK                         0x7000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RAC_CGCCNTLLRZ2MODE_SHFT                                24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RAC_CGCCNTLLRZ1MODE_BMSK                          0x700000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RAC_CGCCNTLLRZ1MODE_SHFT                                20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RAC_CGCCNTLRBPMODE_BMSK                            0x70000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RAC_CGCCNTLRBPMODE_SHFT                                 16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RAC_CGCCNTLCCUFCHEMODE_BMSK                         0x7000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RAC_CGCCNTLCCUFCHEMODE_SHFT                             12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RAC_CGCCNTLA2DMODE_BMSK                              0x700u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RAC_CGCCNTLA2DMODE_SHFT                                  8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RAC_CGCCNTLDCOMMODE_BMSK                              0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RAC_CGCCNTLDCOMMODE_SHFT                                 4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RAC_CGCCNTLCOMMODE_BMSK                                0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_RAC_CGCCNTLCOMMODE_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RAC_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x414u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RAC_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x414u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RAC_RMSK                                         0x777777ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RAC_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RAC_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RAC_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RAC_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RAC_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RAC_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RAC_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RAC_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RAC_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RAC_CGCCNTLLRZ8MODE_BMSK                         0x700000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RAC_CGCCNTLLRZ8MODE_SHFT                               20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RAC_CGCCNTLLRZ7MODE_BMSK                          0x70000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RAC_CGCCNTLLRZ7MODE_SHFT                               16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RAC_CGCCNTLLRZ6MODE_BMSK                           0x7000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RAC_CGCCNTLLRZ6MODE_SHFT                               12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RAC_CGCCNTLLRZ5MODE_BMSK                            0x700u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RAC_CGCCNTLLRZ5MODE_SHFT                                8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RAC_CGCCNTLLRZ4MODE_BMSK                             0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RAC_CGCCNTLLRZ4MODE_SHFT                                4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RAC_CGCCNTLLRZ3MODE_BMSK                              0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL2_RAC_CGCCNTLLRZ3MODE_SHFT                                0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_RAC_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x418u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_RAC_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x418u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_RAC_RMSK                                        0x7777777ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_RAC_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_RAC_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_RAC_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_RAC_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_RAC_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_RAC_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_RAC_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_RAC_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_RAC_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_RAC_CGCDELAYCRE_BMSK                            0x7000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_RAC_CGCDELAYCRE_SHFT                                   24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_RAC_CGCDELAYRBP_BMSK                             0x700000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_RAC_CGCDELAYRBP_SHFT                                   20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_RAC_CGCDELAYLRZ_BMSK                              0x70000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_RAC_CGCDELAYLRZ_SHFT                                   16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_RAC_CGCDELAYCCUFCHE_BMSK                           0x7000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_RAC_CGCDELAYCCUFCHE_SHFT                               12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_RAC_CGCDELAYA2D_BMSK                                0x700u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_RAC_CGCDELAYA2D_SHFT                                    8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_RAC_CGCDELAYDCOM_BMSK                                0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_RAC_CGCDELAYDCOM_SHFT                                   4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_RAC_CGCDELAYCOM_BMSK                                  0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_RAC_CGCDELAYCOM_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RAC_ADDR                                        (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x41cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RAC_OFFS                                        (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x41cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RAC_RMSK                                         0xffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RAC_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RAC_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RAC_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RAC_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RAC_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RAC_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RAC_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RAC_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RAC_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RAC_CGCHYSTCRE_BMSK                              0xf000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RAC_CGCHYSTCRE_SHFT                                     24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RAC_CGCHYSTRBP_BMSK                               0xf00000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RAC_CGCHYSTRBP_SHFT                                     20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RAC_CGCHYSTLRZ_BMSK                                0xf0000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RAC_CGCHYSTLRZ_SHFT                                     16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RAC_CGCHYSTCCUFCHE_BMSK                             0xf000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RAC_CGCHYSTCCUFCHE_SHFT                                 12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RAC_CGCHYSTA2D_BMSK                                  0xf00u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RAC_CGCHYSTA2D_SHFT                                      8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RAC_CGCHYSTDCOM_BMSK                                  0xf0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RAC_CGCHYSTDCOM_SHFT                                     4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RAC_CGCHYSTCOM_BMSK                                    0xfu
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_RAC_CGCHYSTCOM_SHFT                                      0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TSE_RAS_RBBM_ADDR                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x420u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TSE_RAS_RBBM_OFFS                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x420u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TSE_RAS_RBBM_RMSK                                0x7777777ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TSE_RAS_RBBM_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TSE_RAS_RBBM_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TSE_RAS_RBBM_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TSE_RAS_RBBM_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TSE_RAS_RBBM_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TSE_RAS_RBBM_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TSE_RAS_RBBM_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TSE_RAS_RBBM_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TSE_RAS_RBBM_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TSE_RAS_RBBM_CGCCNTLRBBMMODE_BMSK                0x7000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TSE_RAS_RBBM_CGCCNTLRBBMMODE_SHFT                       24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TSE_RAS_RBBM_CGCCNTLRASMODE_BMSK                  0x700000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TSE_RAS_RBBM_CGCCNTLRASMODE_SHFT                        20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TSE_RAS_RBBM_CGCCNTLTSEMODE4_BMSK                  0x70000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TSE_RAS_RBBM_CGCCNTLTSEMODE4_SHFT                       16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TSE_RAS_RBBM_CGCCNTLTSEMODE3_BMSK                   0x7000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TSE_RAS_RBBM_CGCCNTLTSEMODE3_SHFT                       12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TSE_RAS_RBBM_CGCCNTLTSEMODE2_BMSK                    0x700u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TSE_RAS_RBBM_CGCCNTLTSEMODE2_SHFT                        8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TSE_RAS_RBBM_CGCCNTLTSEMODE1_BMSK                     0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TSE_RAS_RBBM_CGCCNTLTSEMODE1_SHFT                        4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TSE_RAS_RBBM_CGCCNTLTSEMODE0_BMSK                      0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TSE_RAS_RBBM_CGCCNTLTSEMODE0_SHFT                        0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TSE_RAS_RBBM_ADDR                              (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x424u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TSE_RAS_RBBM_OFFS                              (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x424u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TSE_RAS_RBBM_RMSK                                  0x7777u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TSE_RAS_RBBM_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TSE_RAS_RBBM_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TSE_RAS_RBBM_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TSE_RAS_RBBM_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TSE_RAS_RBBM_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TSE_RAS_RBBM_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TSE_RAS_RBBM_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TSE_RAS_RBBM_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TSE_RAS_RBBM_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TSE_RAS_RBBM_CGCDELAYRBBM_BMSK                     0x7000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TSE_RAS_RBBM_CGCDELAYRBBM_SHFT                         12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TSE_RAS_RBBM_CGCDELAYRAS_BMSK                       0x700u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TSE_RAS_RBBM_CGCDELAYRAS_SHFT                           8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TSE_RAS_RBBM_CGCDELAYTSE1_BMSK                       0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TSE_RAS_RBBM_CGCDELAYTSE1_SHFT                          4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TSE_RAS_RBBM_CGCDELAYTSE0_BMSK                        0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TSE_RAS_RBBM_CGCDELAYTSE0_SHFT                          0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TSE_RAS_RBBM_ADDR                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x428u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TSE_RAS_RBBM_OFFS                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x428u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TSE_RAS_RBBM_RMSK                                 0x3cf3cful
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TSE_RAS_RBBM_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TSE_RAS_RBBM_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TSE_RAS_RBBM_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TSE_RAS_RBBM_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TSE_RAS_RBBM_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TSE_RAS_RBBM_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TSE_RAS_RBBM_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TSE_RAS_RBBM_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TSE_RAS_RBBM_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TSE_RAS_RBBM_CGCHYSTRBBM_BMSK                     0x3c0000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TSE_RAS_RBBM_CGCHYSTRBBM_SHFT                           18u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TSE_RAS_RBBM_CGCHYSTRAS_BMSK                        0xf000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TSE_RAS_RBBM_CGCHYSTRAS_SHFT                            12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TSE_RAS_RBBM_CGCHYSTTSE1_BMSK                        0x3c0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TSE_RAS_RBBM_CGCHYSTTSE1_SHFT                            6u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TSE_RAS_RBBM_CGCHYSTTSE0_BMSK                          0xfu
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TSE_RAS_RBBM_CGCHYSTTSE0_SHFT                            0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_UCHE_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x42cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_UCHE_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x42cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_UCHE_RMSK                                       0x77777777ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_UCHE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_UCHE_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_UCHE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_UCHE_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_UCHE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_UCHE_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_UCHE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_UCHE_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_UCHE_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_UCHE_CGCCNTLUCHEMODE7_BMSK                      0x70000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_UCHE_CGCCNTLUCHEMODE7_SHFT                              28u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_UCHE_CGCCNTLUCHEMODE6_BMSK                       0x7000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_UCHE_CGCCNTLUCHEMODE6_SHFT                              24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_UCHE_CGCCNTLUCHEMODE5_BMSK                        0x700000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_UCHE_CGCCNTLUCHEMODE5_SHFT                              20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_UCHE_CGCCNTLUCHEMODE4_BMSK                         0x70000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_UCHE_CGCCNTLUCHEMODE4_SHFT                              16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_UCHE_CGCCNTLUCHEMODE3_BMSK                          0x7000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_UCHE_CGCCNTLUCHEMODE3_SHFT                              12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_UCHE_CGCCNTLUCHEMODE2_BMSK                           0x700u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_UCHE_CGCCNTLUCHEMODE2_SHFT                               8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_UCHE_CGCCNTLUCHEMODE1_BMSK                            0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_UCHE_CGCCNTLUCHEMODE1_SHFT                               4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_UCHE_CGCCNTLUCHEMODE0_BMSK                             0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_UCHE_CGCCNTLUCHEMODE0_SHFT                               0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_UCHE_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x43cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_UCHE_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x43cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_UCHE_RMSK                                       0x7777777ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_UCHE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_UCHE_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_UCHE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_UCHE_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_UCHE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_UCHE_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_UCHE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_UCHE_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_UCHE_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_UCHE_CGCDELAYUCHE6_BMSK                         0x7000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_UCHE_CGCDELAYUCHE6_SHFT                                24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_UCHE_CGCDELAYUCHE5_BMSK                          0x700000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_UCHE_CGCDELAYUCHE5_SHFT                                20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_UCHE_CGCDELAYUCHE4_BMSK                           0x70000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_UCHE_CGCDELAYUCHE4_SHFT                                16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_UCHE_CGCDELAYUCHE3_BMSK                            0x7000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_UCHE_CGCDELAYUCHE3_SHFT                                12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_UCHE_CGCDELAYUCHE2_BMSK                             0x700u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_UCHE_CGCDELAYUCHE2_SHFT                                 8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_UCHE_CGCDELAYUCHE1_BMSK                              0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_UCHE_CGCDELAYUCHE1_SHFT                                 4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_UCHE_CGCDELAYUCHE0_BMSK                               0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_UCHE_CGCDELAYUCHE0_SHFT                                 0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_UCHE_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x440u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_UCHE_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x440u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_UCHE_RMSK                                        0xffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_UCHE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_UCHE_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_UCHE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_UCHE_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_UCHE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_UCHE_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_UCHE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_UCHE_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_UCHE_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_UCHE_CGCHYSTUCHE6_BMSK                           0xf000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_UCHE_CGCHYSTUCHE6_SHFT                                  24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_UCHE_CGCHYSTUCHE5_BMSK                            0xf00000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_UCHE_CGCHYSTUCHE5_SHFT                                  20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_UCHE_CGCHYSTUCHE4_BMSK                             0xf0000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_UCHE_CGCHYSTUCHE4_SHFT                                  16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_UCHE_CGCHYSTUCHE3_BMSK                              0xf000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_UCHE_CGCHYSTUCHE3_SHFT                                  12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_UCHE_CGCHYSTUCHE2_BMSK                               0xf00u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_UCHE_CGCHYSTUCHE2_SHFT                                   8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_UCHE_CGCHYSTUCHE1_BMSK                                0xf0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_UCHE_CGCHYSTUCHE1_SHFT                                   4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_UCHE_CGCHYSTUCHE0_BMSK                                 0xfu
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_UCHE_CGCHYSTUCHE0_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_VFD_ADDR                                        (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x444u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_VFD_OFFS                                        (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x444u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_VFD_RMSK                                            0x7777u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_VFD_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_VFD_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_VFD_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_VFD_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_VFD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_VFD_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_VFD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_VFD_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_VFD_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_VFD_CGCMODEVFD3_BMSK                                0x7000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_VFD_CGCMODEVFD3_SHFT                                    12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_VFD_CGCMODEVFD2_BMSK                                 0x700u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_VFD_CGCMODEVFD2_SHFT                                     8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_VFD_CGCMODEVFD1_BMSK                                  0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_VFD_CGCMODEVFD1_SHFT                                     4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_VFD_CGCMODEVFD0_BMSK                                   0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_VFD_CGCMODEVFD0_SHFT                                     0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_VFD_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x448u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_VFD_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x448u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_VFD_RMSK                                           0x7777u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_VFD_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_VFD_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_VFD_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_VFD_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_VFD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_VFD_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_VFD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_VFD_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_VFD_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_VFD_CGCDELAYVFD3_BMSK                              0x7000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_VFD_CGCDELAYVFD3_SHFT                                  12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_VFD_CGCDELAYVFD2_BMSK                               0x700u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_VFD_CGCDELAYVFD2_SHFT                                   8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_VFD_CGCDELAYVFD1_BMSK                                0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_VFD_CGCDELAYVFD1_SHFT                                   4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_VFD_CGCDELAYVFD0_BMSK                                 0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_VFD_CGCDELAYVFD0_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_VFD_ADDR                                        (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x44cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_VFD_OFFS                                        (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x44cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_VFD_RMSK                                          0x3cf3cful
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_VFD_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_VFD_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_VFD_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_VFD_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_VFD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_VFD_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_VFD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_VFD_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_VFD_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_VFD_CGCHYSTVFD3_BMSK                              0x3c0000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_VFD_CGCHYSTVFD3_SHFT                                    18u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_VFD_CGCHYSTVFD2_BMSK                                0xf000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_VFD_CGCHYSTVFD2_SHFT                                    12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_VFD_CGCHYSTVFD1_BMSK                                 0x3c0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_VFD_CGCHYSTVFD1_SHFT                                     6u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_VFD_CGCHYSTVFD0_BMSK                                   0xfu
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_VFD_CGCHYSTVFD0_SHFT                                     0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_GPC_ADDR                                        (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x450u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_GPC_OFFS                                        (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x450u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_GPC_RMSK                                         0x7777777ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_GPC_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_GPC_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_GPC_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_GPC_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_GPC_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_GPC_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_GPC_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_GPC_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_GPC_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_GPC_CGCMODEVSC_BMSK                              0x7000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_GPC_CGCMODEVSC_SHFT                                     24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_GPC_CGCMODETESS_BMSK                              0x700000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_GPC_CGCMODETESS_SHFT                                    20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_GPC_CGCMODEVFDP_BMSK                               0x70000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_GPC_CGCMODEVFDP_SHFT                                    16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_GPC_CGCMODEVPCGL_BMSK                               0x7000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_GPC_CGCMODEVPCGL_SHFT                                   12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_GPC_CGCMODEVPCLM_BMSK                                0x700u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_GPC_CGCMODEVPCLM_SHFT                                    8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_GPC_CGCMODEVPCSO_BMSK                                 0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_GPC_CGCMODEVPCSO_SHFT                                    4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_GPC_CGCMODEPC_BMSK                                     0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_GPC_CGCMODEPC_SHFT                                       0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GPC_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x454u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GPC_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x454u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GPC_RMSK                                          0x77777ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GPC_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GPC_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GPC_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GPC_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GPC_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GPC_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GPC_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GPC_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GPC_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GPC_CGCDELAYVSC_BMSK                              0x70000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GPC_CGCDELAYVSC_SHFT                                   16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GPC_CGCDELAYTESS_BMSK                              0x7000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GPC_CGCDELAYTESS_SHFT                                  12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GPC_CGCDELAYVFDP_BMSK                               0x700u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GPC_CGCDELAYVFDP_SHFT                                   8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GPC_CGCDELAYVPC_BMSK                                 0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GPC_CGCDELAYVPC_SHFT                                    4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GPC_CGCDELAYPC_BMSK                                   0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GPC_CGCDELAYPC_SHFT                                     0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GPC_ADDR                                        (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x458u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GPC_OFFS                                        (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x458u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GPC_RMSK                                         0xf3cf3cful
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GPC_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GPC_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GPC_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GPC_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GPC_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GPC_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GPC_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GPC_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GPC_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GPC_CGCHYSTVSC_BMSK                              0xf000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GPC_CGCHYSTVSC_SHFT                                     24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GPC_CGCHYSTTESS_BMSK                              0x3c0000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GPC_CGCHYSTTESS_SHFT                                    18u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GPC_CGCHYSTVFDP_BMSK                                0xf000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GPC_CGCHYSTVFDP_SHFT                                    12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GPC_CGCHYSTVPC_BMSK                                  0x3c0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GPC_CGCHYSTVPC_SHFT                                      6u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GPC_CGCHYSTPC_BMSK                                     0xfu
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GPC_CGCHYSTPC_SHFT                                       0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_2_ADDR                                    (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x45cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_2_OFFS                                    (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x45cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_2_RMSK                                          0x77u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_2_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_2_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_2_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_2_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_2_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_2_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_2_CGCHLSQTPEARLYCYC_BMSK                        0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_2_CGCHLSQTPEARLYCYC_SHFT                           4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_2_CGCHLSQSPEARLYCYC_BMSK                         0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_2_CGCHLSQSPEARLYCYC_SHFT                           0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GMU_GX_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x460u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GMU_GX_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x460u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GMU_GX_RMSK                                          0x777u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GMU_GX_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GMU_GX_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GMU_GX_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GMU_GX_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GMU_GX_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GMU_GX_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GMU_GX_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GMU_GX_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GMU_GX_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GMU_GX_CGCMODECSR_BMSK                               0x700u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GMU_GX_CGCMODECSR_SHFT                                   8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GMU_GX_CGCMODECOUNTER_BMSK                            0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GMU_GX_CGCMODECOUNTER_SHFT                               4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GMU_GX_CGCMODEGDPM_BMSK                                0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_GMU_GX_CGCMODEGDPM_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GMU_GX_ADDR                                    (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x464u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GMU_GX_OFFS                                    (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x464u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GMU_GX_RMSK                                         0x777u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GMU_GX_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GMU_GX_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GMU_GX_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GMU_GX_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GMU_GX_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GMU_GX_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GMU_GX_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GMU_GX_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GMU_GX_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GMU_GX_CGCDELAYCSR_BMSK                             0x700u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GMU_GX_CGCDELAYCSR_SHFT                                 8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GMU_GX_CGCDELAYCOUNTER_BMSK                          0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GMU_GX_CGCDELAYCOUNTER_SHFT                             4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GMU_GX_CGCDELAYGDPM_BMSK                              0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_GMU_GX_CGCDELAYGDPM_SHFT                                0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GMU_GX_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x468u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GMU_GX_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x468u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GMU_GX_RMSK                                          0xfffu
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GMU_GX_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GMU_GX_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GMU_GX_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GMU_GX_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GMU_GX_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GMU_GX_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GMU_GX_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GMU_GX_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GMU_GX_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GMU_GX_CGCHYSTCSR_BMSK                               0xf00u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GMU_GX_CGCHYSTCSR_SHFT                                   8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GMU_GX_CGCHYSTCOUNTER_BMSK                            0xf0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GMU_GX_CGCHYSTCOUNTER_SHFT                               4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GMU_GX_CGCHYSTGDPM_BMSK                                0xfu
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_GMU_GX_CGCHYSTGDPM_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_HLSQ_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x46cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_HLSQ_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x46cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_HLSQ_RMSK                                           0x7777u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_HLSQ_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_HLSQ_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_HLSQ_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_HLSQ_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_HLSQ_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_HLSQ_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_HLSQ_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_HLSQ_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_HLSQ_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_HLSQ_CGCMODEHLSQ3_BMSK                              0x7000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_HLSQ_CGCMODEHLSQ3_SHFT                                  12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_HLSQ_CGCMODEHLSQ2_BMSK                               0x700u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_HLSQ_CGCMODEHLSQ2_SHFT                                   8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_HLSQ_CGCMODEHLSQ1_BMSK                                0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_HLSQ_CGCMODEHLSQ1_SHFT                                   4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_HLSQ_CGCMODEHLSQ0_BMSK                                 0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_MODE_HLSQ_CGCMODEHLSQ0_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x470u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x470u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_RMSK                                          0x7777u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_CGCDELAYHLSQ3_BMSK                            0x7000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_CGCDELAYHLSQ3_SHFT                                12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_CGCDELAYHLSQ2_BMSK                             0x700u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_CGCDELAYHLSQ2_SHFT                                 8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_CGCDELAYHLSQ1_BMSK                              0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_CGCDELAYHLSQ1_SHFT                                 4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_CGCDELAYHLSQ0_BMSK                               0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_HLSQ_CGCDELAYHLSQ0_SHFT                                 0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_HLSQ_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x474u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_HLSQ_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x474u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_HLSQ_RMSK                                           0xffffu
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_HLSQ_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_HLSQ_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_HLSQ_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_HLSQ_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_HLSQ_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_HLSQ_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_HLSQ_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_HLSQ_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_HLSQ_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_HLSQ_CGCHYSTHLSQ3_BMSK                              0xf000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_HLSQ_CGCHYSTHLSQ3_SHFT                                  12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_HLSQ_CGCHYSTHLSQ2_BMSK                               0xf00u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_HLSQ_CGCHYSTHLSQ2_SHFT                                   8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_HLSQ_CGCHYSTHLSQ1_BMSK                                0xf0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_HLSQ_CGCHYSTHLSQ1_SHFT                                   4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_HLSQ_CGCHYSTHLSQ0_BMSK                                 0xfu
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_HLSQ_CGCHYSTHLSQ0_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TEX_FCHE_ADDR                                   (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x480u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TEX_FCHE_OFFS                                   (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x480u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TEX_FCHE_RMSK                                        0x777u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TEX_FCHE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TEX_FCHE_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TEX_FCHE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TEX_FCHE_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TEX_FCHE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TEX_FCHE_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TEX_FCHE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TEX_FCHE_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TEX_FCHE_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TEX_FCHE_CGCCNTLTEXFCHEMODE2_BMSK                    0x700u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TEX_FCHE_CGCCNTLTEXFCHEMODE2_SHFT                        8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TEX_FCHE_CGCCNTLTEXFCHEMODE1_BMSK                     0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TEX_FCHE_CGCCNTLTEXFCHEMODE1_SHFT                        4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TEX_FCHE_CGCCNTLTEXFCHEMODE0_BMSK                      0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_CNTL_TEX_FCHE_CGCCNTLTEXFCHEMODE0_SHFT                        0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TEX_FCHE_ADDR                                  (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x484u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TEX_FCHE_OFFS                                  (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x484u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TEX_FCHE_RMSK                                       0x777u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TEX_FCHE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TEX_FCHE_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TEX_FCHE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TEX_FCHE_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TEX_FCHE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TEX_FCHE_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TEX_FCHE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TEX_FCHE_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TEX_FCHE_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TEX_FCHE_CGCCNTLTEXFCHEDELAY2_BMSK                  0x700u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TEX_FCHE_CGCCNTLTEXFCHEDELAY2_SHFT                      8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TEX_FCHE_CGCCNTLTEXFCHEDELAY1_BMSK                   0x70u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TEX_FCHE_CGCCNTLTEXFCHEDELAY1_SHFT                      4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TEX_FCHE_CGCCNTLTEXFCHEDELAY0_BMSK                    0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_DELAY_TEX_FCHE_CGCCNTLTEXFCHEDELAY0_SHFT                      0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TEX_FCHE_ADDR                                   (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x488u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TEX_FCHE_OFFS                                   (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x488u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TEX_FCHE_RMSK                                        0xfffu
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TEX_FCHE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TEX_FCHE_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TEX_FCHE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TEX_FCHE_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TEX_FCHE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TEX_FCHE_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TEX_FCHE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TEX_FCHE_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TEX_FCHE_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TEX_FCHE_CGC_HYST_TEX_FCHE_2_BMSK                    0xf00u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TEX_FCHE_CGC_HYST_TEX_FCHE_2_SHFT                        8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TEX_FCHE_CGC_HYST_TEX_FCHE_1_BMSK                     0xf0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TEX_FCHE_CGC_HYST_TEX_FCHE_1_SHFT                        4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TEX_FCHE_CGC_HYST_TEX_FCHE_0_BMSK                      0xfu
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_HYST_TEX_FCHE_CGC_HYST_TEX_FCHE_0_SHFT                        0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_ADDR                                   (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x800u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_OFFS                                   (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x800u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_RMSK                                   0xdff7fffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_ISDBUNDERDEBUG_BMSK                    0x80000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_ISDBUNDERDEBUG_SHFT                            31u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_ISDBCPUIRQ_BMSK                        0x40000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_ISDBCPUIRQ_SHFT                                30u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_TSBWRITEERROR_BMSK                     0x10000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_TSBWRITEERROR_SHFT                             28u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_DEBUGBUSINTERRUPT1_BMSK                 0x8000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_DEBUGBUSINTERRUPT1_SHFT                        27u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_DEBUGBUSINTERRUPT0_BMSK                 0x4000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_DEBUGBUSINTERRUPT0_SHFT                        26u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_UCHETRAPINTERRUPT_BMSK                  0x2000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_UCHETRAPINTERRUPT_SHFT                         25u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_OUTOFBOUNDACCESS_BMSK                   0x1000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_OUTOFBOUNDACCESS_SHFT                          24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_HANGDETECTINTERRUPT_BMSK                 0x800000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_HANGDETECTINTERRUPT_SHFT                       23u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_ATBBUSOVERFLOW_BMSK                      0x400000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_ATBBUSOVERFLOW_SHFT                            22u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_CACHE_FLUSH_TS_LPAC_BMSK                 0x200000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_CACHE_FLUSH_TS_LPAC_SHFT                       21u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_CACHE_FLUSH_TS_BMSK                      0x100000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_CACHE_FLUSH_TS_SHFT                            20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_WT_DONE_TS_BMSK                           0x40000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_WT_DONE_TS_SHFT                                18u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_RB_DONE_TS_BMSK                           0x20000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_RB_DONE_TS_SHFT                                17u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_RBINTERRUPTLPAC_BMSK                      0x10000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_RBINTERRUPTLPAC_SHFT                           16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_RBINTERRUPT_BMSK                           0x8000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_RBINTERRUPT_SHFT                               15u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_IB1INTERRUPT_BMSK                          0x4000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_IB1INTERRUPT_SHFT                              14u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_IB2INTERRUPT_BMSK                          0x2000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_IB2INTERRUPT_SHFT                              13u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_CCU_RESOLVE_TS_BMSK                        0x1000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_CCU_RESOLVE_TS_SHFT                            12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_CCU_FLUSH_COLOR_TS_BMSK                     0x800u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_CCU_FLUSH_COLOR_TS_SHFT                        11u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_CCU_FLUSH_DEPTH_TS_BMSK                     0x400u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_CCU_FLUSH_DEPTH_TS_SHFT                        10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_HWERROR_BMSK                                0x200u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_HWERROR_SHFT                                    9u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_SWINTERRUPT_BMSK                            0x100u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_SWINTERRUPT_SHFT                                8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_GPCERROR_BMSK                                0x80u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_GPCERROR_SHFT                                   7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_ATBASYNCFIFOOVERFLOW_BMSK                    0x40u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_ATBASYNCFIFOOVERFLOW_SHFT                       6u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_CPIPCINT1_BMSK                               0x20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_CPIPCINT1_SHFT                                  5u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_CPIPCINT0_BMSK                               0x10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_CPIPCINT0_SHFT                                  4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_IB1INTERRUPTLPAC_BMSK                         0x8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_IB1INTERRUPTLPAC_SHFT                           3u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_IB2INTERRUPTLPAC_BMSK                         0x4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_IB2INTERRUPTLPAC_SHFT                           2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_AHBERROR_BMSK                                 0x2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_AHBERROR_SHFT                                   1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_GPUIDLE_BMSK                                  0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_UNMASKED_STATUS_GPUIDLE_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_ADDR                                          (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x804u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_OFFS                                          (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x804u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_RMSK                                          0xdff7fffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_ISDBUNDERDEBUG_BMSK                           0x80000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_ISDBUNDERDEBUG_SHFT                                   31u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_ISDBCPUIRQ_BMSK                               0x40000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_ISDBCPUIRQ_SHFT                                       30u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_TSBWRITEERROR_BMSK                            0x10000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_TSBWRITEERROR_SHFT                                    28u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_DEBUGBUSINTERRUPT1_BMSK                        0x8000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_DEBUGBUSINTERRUPT1_SHFT                               27u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_DEBUGBUSINTERRUPT0_BMSK                        0x4000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_DEBUGBUSINTERRUPT0_SHFT                               26u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_UCHETRAPINTERRUPT_BMSK                         0x2000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_UCHETRAPINTERRUPT_SHFT                                25u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_OUTOFBOUNDACCESS_BMSK                          0x1000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_OUTOFBOUNDACCESS_SHFT                                 24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_HANGDETECTINTERRUPT_BMSK                        0x800000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_HANGDETECTINTERRUPT_SHFT                              23u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_ATBBUSOVERFLOW_BMSK                             0x400000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_ATBBUSOVERFLOW_SHFT                                   22u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_CACHE_FLUSH_TS_LPAC_BMSK                        0x200000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_CACHE_FLUSH_TS_LPAC_SHFT                              21u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_CACHE_FLUSH_TS_BMSK                             0x100000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_CACHE_FLUSH_TS_SHFT                                   20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_WT_DONE_TS_BMSK                                  0x40000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_WT_DONE_TS_SHFT                                       18u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_RB_DONE_TS_BMSK                                  0x20000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_RB_DONE_TS_SHFT                                       17u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_RBINTERRUPTLPAC_BMSK                             0x10000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_RBINTERRUPTLPAC_SHFT                                  16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_RBINTERRUPT_BMSK                                  0x8000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_RBINTERRUPT_SHFT                                      15u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_IB1INTERRUPT_BMSK                                 0x4000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_IB1INTERRUPT_SHFT                                     14u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_IB2INTERRUPT_BMSK                                 0x2000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_IB2INTERRUPT_SHFT                                     13u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_CCU_RESOLVE_TS_BMSK                               0x1000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_CCU_RESOLVE_TS_SHFT                                   12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_CCU_FLUSH_COLOR_TS_BMSK                            0x800u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_CCU_FLUSH_COLOR_TS_SHFT                               11u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_CCU_FLUSH_DEPTH_TS_BMSK                            0x400u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_CCU_FLUSH_DEPTH_TS_SHFT                               10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_HWERROR_BMSK                                       0x200u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_HWERROR_SHFT                                           9u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_SWINTERRUPT_BMSK                                   0x100u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_SWINTERRUPT_SHFT                                       8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_GPCERROR_BMSK                                       0x80u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_GPCERROR_SHFT                                          7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_ATBASYNCFIFOOVERFLOW_BMSK                           0x40u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_ATBASYNCFIFOOVERFLOW_SHFT                              6u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_CPIPCINT1_BMSK                                      0x20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_CPIPCINT1_SHFT                                         5u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_CPIPCINT0_BMSK                                      0x10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_CPIPCINT0_SHFT                                         4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_IB1INTERRUPTLPAC_BMSK                                0x8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_IB1INTERRUPTLPAC_SHFT                                  3u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_IB2INTERRUPTLPAC_BMSK                                0x4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_IB2INTERRUPTLPAC_SHFT                                  2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_AHBERROR_BMSK                                        0x2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_AHBERROR_SHFT                                          1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_GPUIDLE_BMSK                                         0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_0_STATUS_GPUIDLE_SHFT                                           0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_ADDR                                          (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x808u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_OFFS                                          (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x808u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_RMSK                                          0xdff7fffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_ISDBUNDERDEBUG_BMSK                           0x80000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_ISDBUNDERDEBUG_SHFT                                   31u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_ISDBCPUIRQ_BMSK                               0x40000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_ISDBCPUIRQ_SHFT                                       30u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_TSBWRITEERROR_BMSK                            0x10000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_TSBWRITEERROR_SHFT                                    28u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_DEBUGBUSINTERRUPT1_BMSK                        0x8000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_DEBUGBUSINTERRUPT1_SHFT                               27u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_DEBUGBUSINTERRUPT0_BMSK                        0x4000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_DEBUGBUSINTERRUPT0_SHFT                               26u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_UCHETRAPINTERRUPT_BMSK                         0x2000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_UCHETRAPINTERRUPT_SHFT                                25u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_OUTOFBOUNDACCESS_BMSK                          0x1000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_OUTOFBOUNDACCESS_SHFT                                 24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_HANGDETECTINTERRUPT_BMSK                        0x800000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_HANGDETECTINTERRUPT_SHFT                              23u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_ATBBUSOVERFLOW_BMSK                             0x400000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_ATBBUSOVERFLOW_SHFT                                   22u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_CACHE_FLUSH_TS_LPAC_BMSK                        0x200000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_CACHE_FLUSH_TS_LPAC_SHFT                              21u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_CACHE_FLUSH_TS_BMSK                             0x100000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_CACHE_FLUSH_TS_SHFT                                   20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_WT_DONE_TS_BMSK                                  0x40000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_WT_DONE_TS_SHFT                                       18u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_RB_DONE_TS_BMSK                                  0x20000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_RB_DONE_TS_SHFT                                       17u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_RBINTERRUPTLPAC_BMSK                             0x10000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_RBINTERRUPTLPAC_SHFT                                  16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_RBINTERRUPT_BMSK                                  0x8000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_RBINTERRUPT_SHFT                                      15u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_IB1INTERRUPT_BMSK                                 0x4000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_IB1INTERRUPT_SHFT                                     14u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_IB2INTERRUPT_BMSK                                 0x2000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_IB2INTERRUPT_SHFT                                     13u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_CCU_RESOLVE_TS_BMSK                               0x1000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_CCU_RESOLVE_TS_SHFT                                   12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_CCU_FLUSH_COLOR_TS_BMSK                            0x800u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_CCU_FLUSH_COLOR_TS_SHFT                               11u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_CCU_FLUSH_DEPTH_TS_BMSK                            0x400u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_CCU_FLUSH_DEPTH_TS_SHFT                               10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_HWERROR_BMSK                                       0x200u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_HWERROR_SHFT                                           9u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_SWINTERRUPT_BMSK                                   0x100u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_SWINTERRUPT_SHFT                                       8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_GPCERROR_BMSK                                       0x80u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_GPCERROR_SHFT                                          7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_ATBASYNCFIFOOVERFLOW_BMSK                           0x40u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_ATBASYNCFIFOOVERFLOW_SHFT                              6u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_CPIPCINT1_BMSK                                      0x20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_CPIPCINT1_SHFT                                         5u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_CPIPCINT0_BMSK                                      0x10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_CPIPCINT0_SHFT                                         4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_IB1INTERRUPTLPAC_BMSK                                0x8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_IB1INTERRUPTLPAC_SHFT                                  3u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_IB2INTERRUPTLPAC_BMSK                                0x4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_IB2INTERRUPTLPAC_SHFT                                  2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_AHBERROR_BMSK                                        0x2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_AHBERROR_SHFT                                          1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_GPUIDLE_BMSK                                         0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_1_STATUS_GPUIDLE_SHFT                                           0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_ADDR                                          (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x80cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_OFFS                                          (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x80cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_RMSK                                          0xdff7fffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_ISDBUNDERDEBUG_BMSK                           0x80000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_ISDBUNDERDEBUG_SHFT                                   31u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_ISDBCPUIRQ_BMSK                               0x40000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_ISDBCPUIRQ_SHFT                                       30u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_TSBWRITEERROR_BMSK                            0x10000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_TSBWRITEERROR_SHFT                                    28u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_DEBUGBUSINTERRUPT1_BMSK                        0x8000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_DEBUGBUSINTERRUPT1_SHFT                               27u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_DEBUGBUSINTERRUPT0_BMSK                        0x4000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_DEBUGBUSINTERRUPT0_SHFT                               26u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_UCHETRAPINTERRUPT_BMSK                         0x2000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_UCHETRAPINTERRUPT_SHFT                                25u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_OUTOFBOUNDACCESS_BMSK                          0x1000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_OUTOFBOUNDACCESS_SHFT                                 24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_HANGDETECTINTERRUPT_BMSK                        0x800000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_HANGDETECTINTERRUPT_SHFT                              23u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_ATBBUSOVERFLOW_BMSK                             0x400000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_ATBBUSOVERFLOW_SHFT                                   22u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_CACHE_FLUSH_TS_LPAC_BMSK                        0x200000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_CACHE_FLUSH_TS_LPAC_SHFT                              21u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_CACHE_FLUSH_TS_BMSK                             0x100000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_CACHE_FLUSH_TS_SHFT                                   20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_WT_DONE_TS_BMSK                                  0x40000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_WT_DONE_TS_SHFT                                       18u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_RB_DONE_TS_BMSK                                  0x20000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_RB_DONE_TS_SHFT                                       17u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_RBINTERRUPTLPAC_BMSK                             0x10000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_RBINTERRUPTLPAC_SHFT                                  16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_RBINTERRUPT_BMSK                                  0x8000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_RBINTERRUPT_SHFT                                      15u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_IB1INTERRUPT_BMSK                                 0x4000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_IB1INTERRUPT_SHFT                                     14u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_IB2INTERRUPT_BMSK                                 0x2000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_IB2INTERRUPT_SHFT                                     13u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_CCU_RESOLVE_TS_BMSK                               0x1000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_CCU_RESOLVE_TS_SHFT                                   12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_CCU_FLUSH_COLOR_TS_BMSK                            0x800u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_CCU_FLUSH_COLOR_TS_SHFT                               11u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_CCU_FLUSH_DEPTH_TS_BMSK                            0x400u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_CCU_FLUSH_DEPTH_TS_SHFT                               10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_HWERROR_BMSK                                       0x200u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_HWERROR_SHFT                                           9u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_SWINTERRUPT_BMSK                                   0x100u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_SWINTERRUPT_SHFT                                       8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_GPCERROR_BMSK                                       0x80u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_GPCERROR_SHFT                                          7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_ATBASYNCFIFOOVERFLOW_BMSK                           0x40u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_ATBASYNCFIFOOVERFLOW_SHFT                              6u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_CPIPCINT1_BMSK                                      0x20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_CPIPCINT1_SHFT                                         5u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_CPIPCINT0_BMSK                                      0x10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_CPIPCINT0_SHFT                                         4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_IB1INTERRUPTLPAC_BMSK                                0x8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_IB1INTERRUPTLPAC_SHFT                                  3u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_IB2INTERRUPTLPAC_BMSK                                0x4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_IB2INTERRUPTLPAC_SHFT                                  2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_AHBERROR_BMSK                                        0x2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_AHBERROR_SHFT                                          1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_GPUIDLE_BMSK                                         0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_2_STATUS_GPUIDLE_SHFT                                           0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_ADDR                                          (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x810u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_OFFS                                          (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x810u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_RMSK                                          0xdff7fffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_ISDBUNDERDEBUG_BMSK                           0x80000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_ISDBUNDERDEBUG_SHFT                                   31u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_ISDBCPUIRQ_BMSK                               0x40000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_ISDBCPUIRQ_SHFT                                       30u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_TSBWRITEERROR_BMSK                            0x10000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_TSBWRITEERROR_SHFT                                    28u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_DEBUGBUSINTERRUPT1_BMSK                        0x8000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_DEBUGBUSINTERRUPT1_SHFT                               27u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_DEBUGBUSINTERRUPT0_BMSK                        0x4000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_DEBUGBUSINTERRUPT0_SHFT                               26u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_UCHETRAPINTERRUPT_BMSK                         0x2000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_UCHETRAPINTERRUPT_SHFT                                25u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_OUTOFBOUNDACCESS_BMSK                          0x1000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_OUTOFBOUNDACCESS_SHFT                                 24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_HANGDETECTINTERRUPT_BMSK                        0x800000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_HANGDETECTINTERRUPT_SHFT                              23u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_ATBBUSOVERFLOW_BMSK                             0x400000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_ATBBUSOVERFLOW_SHFT                                   22u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_CACHE_FLUSH_TS_LPAC_BMSK                        0x200000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_CACHE_FLUSH_TS_LPAC_SHFT                              21u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_CACHE_FLUSH_TS_BMSK                             0x100000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_CACHE_FLUSH_TS_SHFT                                   20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_WT_DONE_TS_BMSK                                  0x40000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_WT_DONE_TS_SHFT                                       18u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_RB_DONE_TS_BMSK                                  0x20000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_RB_DONE_TS_SHFT                                       17u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_RBINTERRUPTLPAC_BMSK                             0x10000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_RBINTERRUPTLPAC_SHFT                                  16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_RBINTERRUPT_BMSK                                  0x8000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_RBINTERRUPT_SHFT                                      15u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_IB1INTERRUPT_BMSK                                 0x4000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_IB1INTERRUPT_SHFT                                     14u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_IB2INTERRUPT_BMSK                                 0x2000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_IB2INTERRUPT_SHFT                                     13u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_CCU_RESOLVE_TS_BMSK                               0x1000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_CCU_RESOLVE_TS_SHFT                                   12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_CCU_FLUSH_COLOR_TS_BMSK                            0x800u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_CCU_FLUSH_COLOR_TS_SHFT                               11u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_CCU_FLUSH_DEPTH_TS_BMSK                            0x400u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_CCU_FLUSH_DEPTH_TS_SHFT                               10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_HWERROR_BMSK                                       0x200u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_HWERROR_SHFT                                           9u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_SWINTERRUPT_BMSK                                   0x100u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_SWINTERRUPT_SHFT                                       8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_GPCERROR_BMSK                                       0x80u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_GPCERROR_SHFT                                          7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_ATBASYNCFIFOOVERFLOW_BMSK                           0x40u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_ATBASYNCFIFOOVERFLOW_SHFT                              6u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_CPIPCINT1_BMSK                                      0x20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_CPIPCINT1_SHFT                                         5u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_CPIPCINT0_BMSK                                      0x10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_CPIPCINT0_SHFT                                         4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_IB1INTERRUPTLPAC_BMSK                                0x8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_IB1INTERRUPTLPAC_SHFT                                  3u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_IB2INTERRUPTLPAC_BMSK                                0x4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_IB2INTERRUPTLPAC_SHFT                                  2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_AHBERROR_BMSK                                        0x2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_AHBERROR_SHFT                                          1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_GPUIDLE_BMSK                                         0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_3_STATUS_GPUIDLE_SHFT                                           0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_ADDR                                          (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x814u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_OFFS                                          (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x814u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_RMSK                                          0xdff7fffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_ISDBUNDERDEBUG_BMSK                           0x80000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_ISDBUNDERDEBUG_SHFT                                   31u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_ISDBCPUIRQ_BMSK                               0x40000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_ISDBCPUIRQ_SHFT                                       30u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_TSBWRITEERROR_BMSK                            0x10000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_TSBWRITEERROR_SHFT                                    28u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_DEBUGBUSINTERRUPT1_BMSK                        0x8000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_DEBUGBUSINTERRUPT1_SHFT                               27u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_DEBUGBUSINTERRUPT0_BMSK                        0x4000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_DEBUGBUSINTERRUPT0_SHFT                               26u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_UCHETRAPINTERRUPT_BMSK                         0x2000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_UCHETRAPINTERRUPT_SHFT                                25u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_OUTOFBOUNDACCESS_BMSK                          0x1000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_OUTOFBOUNDACCESS_SHFT                                 24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_HANGDETECTINTERRUPT_BMSK                        0x800000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_HANGDETECTINTERRUPT_SHFT                              23u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_ATBBUSOVERFLOW_BMSK                             0x400000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_ATBBUSOVERFLOW_SHFT                                   22u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_CACHE_FLUSH_TS_LPAC_BMSK                        0x200000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_CACHE_FLUSH_TS_LPAC_SHFT                              21u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_CACHE_FLUSH_TS_BMSK                             0x100000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_CACHE_FLUSH_TS_SHFT                                   20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_WT_DONE_TS_BMSK                                  0x40000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_WT_DONE_TS_SHFT                                       18u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_RB_DONE_TS_BMSK                                  0x20000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_RB_DONE_TS_SHFT                                       17u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_RBINTERRUPTLPAC_BMSK                             0x10000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_RBINTERRUPTLPAC_SHFT                                  16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_RBINTERRUPT_BMSK                                  0x8000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_RBINTERRUPT_SHFT                                      15u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_IB1INTERRUPT_BMSK                                 0x4000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_IB1INTERRUPT_SHFT                                     14u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_IB2INTERRUPT_BMSK                                 0x2000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_IB2INTERRUPT_SHFT                                     13u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_CCU_RESOLVE_TS_BMSK                               0x1000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_CCU_RESOLVE_TS_SHFT                                   12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_CCU_FLUSH_COLOR_TS_BMSK                            0x800u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_CCU_FLUSH_COLOR_TS_SHFT                               11u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_CCU_FLUSH_DEPTH_TS_BMSK                            0x400u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_CCU_FLUSH_DEPTH_TS_SHFT                               10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_HWERROR_BMSK                                       0x200u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_HWERROR_SHFT                                           9u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_SWINTERRUPT_BMSK                                   0x100u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_SWINTERRUPT_SHFT                                       8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_GPCERROR_BMSK                                       0x80u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_GPCERROR_SHFT                                          7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_ATBASYNCFIFOOVERFLOW_BMSK                           0x40u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_ATBASYNCFIFOOVERFLOW_SHFT                              6u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_CPIPCINT1_BMSK                                      0x20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_CPIPCINT1_SHFT                                         5u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_CPIPCINT0_BMSK                                      0x10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_CPIPCINT0_SHFT                                         4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_IB1INTERRUPTLPAC_BMSK                                0x8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_IB1INTERRUPTLPAC_SHFT                                  3u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_IB2INTERRUPTLPAC_BMSK                                0x4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_IB2INTERRUPTLPAC_SHFT                                  2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_AHBERROR_BMSK                                        0x2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_AHBERROR_SHFT                                          1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_GPUIDLE_BMSK                                         0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_INT_4_STATUS_GPUIDLE_SHFT                                           0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_ADDR                                          (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x818u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_OFFS                                          (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x818u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_RMSK                                          0xff3ff0fful
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_CGCCNTLRBBM_BMSK                              0x80000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_CGCCNTLRBBM_SHFT                                      31u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_CGCCNTLHM_BMSK                                0x40000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_CGCCNTLHM_SHFT                                        30u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_CGCCNTLVBIF_BMSK                              0x20000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_CGCCNTLVBIF_SHFT                                      29u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_CGCCNTLUCHE_BMSK                              0x10000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_CGCCNTLUCHE_SHFT                                      28u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_CGCCNTLVSC_BMSK                                0x8000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_CGCCNTLVSC_SHFT                                       27u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_CGCCNTLRAS_BMSK                                0x4000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_CGCCNTLRAS_SHFT                                       26u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_CGCCNTLTSE_BMSK                                0x2000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_CGCCNTLTSE_SHFT                                       25u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_CGCCNTLHLSQ_BMSK                               0x1000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_CGCCNTLHLSQ_SHFT                                      24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_CGCCNTLGPC_BMSK                                 0x200000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_CGCCNTLGPC_SHFT                                       21u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_CGCCNTLCP_BMSK                                  0x100000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_CGCCNTLCP_SHFT                                        20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_CGCCNTLRAC_BMSK                                  0xf0000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_CGCCNTLRAC_SHFT                                       16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_CGCCNTLTEXFCHE2_BMSK                              0xf000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_CGCCNTLTEXFCHE2_SHFT                                  12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_CGCCNTLSPTP_BMSK                                    0xffu
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_CGCCNTLSPTP_SHFT                                       0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP0_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x81cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP0_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x81cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP0_RMSK                                      0x1ffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP0_CGCSTATUSTP0_BMSK                         0x1ffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP0_CGCSTATUSTP0_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP1_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x820u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP1_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x820u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP1_RMSK                                      0x1ffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP1_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP1_CGCSTATUSTP0_BMSK                         0x1ffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP1_CGCSTATUSTP0_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP2_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x824u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP2_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x824u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP2_RMSK                                      0x1ffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP2_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP2_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP2_CGCSTATUSTP0_BMSK                         0x1ffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP2_CGCSTATUSTP0_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP3_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x828u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP3_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x828u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP3_RMSK                                      0x1ffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP3_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP3_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP3_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP3_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP3_CGCSTATUSTP0_BMSK                         0x1ffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_TP3_CGCSTATUSTP0_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_RB_CCU_ADDR                                   (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x82cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_RB_CCU_OFFS                                   (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x82cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_RB_CCU_RMSK                                         0x1fu
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_RB_CCU_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_RB_CCU_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_RB_CCU_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_RB_CCU_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_RB_CCU_CGCSTATUSCCUCRE_BMSK                         0x10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_RB_CCU_CGCSTATUSCCUCRE_SHFT                            4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_RB_CCU_CGCSTATUSRBCCU3_BMSK                          0x8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_RB_CCU_CGCSTATUSRBCCU3_SHFT                            3u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_RB_CCU_CGCSTATUSRBCCU2_BMSK                          0x4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_RB_CCU_CGCSTATUSRBCCU2_SHFT                            2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_RB_CCU_CGCSTATUSRBCCU1_BMSK                          0x2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_RB_CCU_CGCSTATUSRBCCU1_SHFT                            1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_RB_CCU_CGCSTATUSRBCCU0_BMSK                          0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_RB_CCU_CGCSTATUSRBCCU0_SHFT                            0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_UCHE_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x830u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_UCHE_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x830u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_UCHE_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_UCHE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_UCHE_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_UCHE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_UCHE_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_UCHE_CGCSTATUSUCHE_BMSK                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_UCHE_CGCSTATUSUCHE_SHFT                                0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_GMU_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x834u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_GMU_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x834u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_GMU_RMSK                                             0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_GMU_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_GMU_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_GMU_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_GMU_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_GMU_CGCSTATUSCSR_BMSK                                0x4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_GMU_CGCSTATUSCSR_SHFT                                  2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_GMU_CGCSTATUSCOUNTER_BMSK                            0x2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_GMU_CGCSTATUSCOUNTER_SHFT                              1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_GMU_CGCSTATUSGDPM_BMSK                               0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_GMU_CGCSTATUSGDPM_SHFT                                 0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_ADDR                                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x840u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_OFFS                                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x840u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_RMSK                                                  0xfffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_GPUBUSYIGNAHB_BMSK                                    0x800000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_GPUBUSYIGNAHB_SHFT                                          23u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_GPUBUSYIGNAHBCP_BMSK                                  0x400000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_GPUBUSYIGNAHBCP_SHFT                                        22u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_HLSQBUSY_BMSK                                         0x200000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_HLSQBUSY_SHFT                                               21u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_VSCBUSY_BMSK                                          0x100000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_VSCBUSY_SHFT                                                20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_TPL1BUSY_BMSK                                          0x80000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_TPL1BUSY_SHFT                                               19u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_SPBUSY_BMSK                                            0x40000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_SPBUSY_SHFT                                                 18u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_UCHEBUSY_BMSK                                          0x20000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_UCHEBUSY_SHFT                                               17u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_VPCBUSY_BMSK                                           0x10000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_VPCBUSY_SHFT                                                16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_VFDBUSY_BMSK                                            0x8000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_VFDBUSY_SHFT                                                15u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_TESSBUSY_BMSK                                           0x4000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_TESSBUSY_SHFT                                               14u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_PCVSDBUSY_BMSK                                          0x2000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_PCVSDBUSY_SHFT                                              13u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_PCDCALLBUSY_BMSK                                        0x1000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_PCDCALLBUSY_SHFT                                            12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_COMDCOMBUSY_BMSK                                         0x800u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_COMDCOMBUSY_SHFT                                            11u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_LRZBUSY_BMSK                                             0x400u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_LRZBUSY_SHFT                                                10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_A2DBUSY_BMSK                                             0x200u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_A2DBUSY_SHFT                                                 9u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_CCUBUSY_BMSK                                             0x100u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_CCUBUSY_SHFT                                                 8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_RBBUSY_BMSK                                               0x80u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_RBBUSY_SHFT                                                  7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_RASBUSY_BMSK                                              0x40u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_RASBUSY_SHFT                                                 6u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_TSEBUSY_BMSK                                              0x20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_TSEBUSY_SHFT                                                 5u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_VBIFGXFPARTBUSY_BMSK                                      0x10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_VBIFGXFPARTBUSY_SHFT                                         4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_GFXDBGCBUSY_BMSK                                           0x8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_GFXDBGCBUSY_SHFT                                             3u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_CPBUSY_BMSK                                                0x4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_CPBUSY_SHFT                                                  2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_CPAHBBUSYCPMASTER_BMSK                                     0x2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_CPAHBBUSYCPMASTER_SHFT                                       1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_CPAHBBUSYCXMASTER_BMSK                                     0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS_CPAHBBUSYCXMASTER_SHFT                                       0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_ADDR                                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x844u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_OFFS                                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x844u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_RMSK                                               0x1f0f0f0ful
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_VFDPBUSY_BMSK                                      0x10000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_VFDPBUSY_SHFT                                              28u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_VFD3BUSY_BMSK                                       0x8000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_VFD3BUSY_SHFT                                              27u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_VFD2BUSY_BMSK                                       0x4000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_VFD2BUSY_SHFT                                              26u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_VFD1BUSY_BMSK                                       0x2000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_VFD1BUSY_SHFT                                              25u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_VFD0BUSY_BMSK                                       0x1000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_VFD0BUSY_SHFT                                              24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_RAC3BUSY_BMSK                                         0x80000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_RAC3BUSY_SHFT                                              19u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_RAC2BUSY_BMSK                                         0x40000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_RAC2BUSY_SHFT                                              18u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_RAC1BUSY_BMSK                                         0x20000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_RAC1BUSY_SHFT                                              17u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_RAC0BUSY_BMSK                                         0x10000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_RAC0BUSY_SHFT                                              16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_TPL13BUSY_BMSK                                          0x800u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_TPL13BUSY_SHFT                                             11u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_TPL12BUSY_BMSK                                          0x400u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_TPL12BUSY_SHFT                                             10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_TPL11BUSY_BMSK                                          0x200u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_TPL11BUSY_SHFT                                              9u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_TPL10BUSY_BMSK                                          0x100u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_TPL10BUSY_SHFT                                              8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_SP3BUSY_BMSK                                              0x8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_SP3BUSY_SHFT                                                3u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_SP2BUSY_BMSK                                              0x4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_SP2BUSY_SHFT                                                2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_SP1BUSY_BMSK                                              0x2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_SP1BUSY_SHFT                                                1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_SP0BUSY_BMSK                                              0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS1_SP0BUSY_SHFT                                                0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS2_ADDR                                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x848u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS2_OFFS                                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x848u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS2_RMSK                                                  0xf0f0ful
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_STATUS2_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_STATUS2_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS2_CCU3BUSY_BMSK                                         0x80000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS2_CCU3BUSY_SHFT                                              19u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS2_CCU2BUSY_BMSK                                         0x40000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS2_CCU2BUSY_SHFT                                              18u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS2_CCU1BUSY_BMSK                                         0x20000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS2_CCU1BUSY_SHFT                                              17u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS2_CCU0BUSY_BMSK                                         0x10000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS2_CCU0BUSY_SHFT                                              16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS2_SP3FSBUSY_BMSK                                          0x800u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS2_SP3FSBUSY_SHFT                                             11u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS2_SP2FSBUSY_BMSK                                          0x400u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS2_SP2FSBUSY_SHFT                                             10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS2_SP1FSBUSY_BMSK                                          0x200u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS2_SP1FSBUSY_SHFT                                              9u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS2_SP0FSBUSY_BMSK                                          0x100u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS2_SP0FSBUSY_SHFT                                              8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS2_SP3VSBUSY_BMSK                                            0x8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS2_SP3VSBUSY_SHFT                                              3u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS2_SP2VSBUSY_BMSK                                            0x4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS2_SP2VSBUSY_SHFT                                              2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS2_SP1VSBUSY_BMSK                                            0x2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS2_SP1VSBUSY_SHFT                                              1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS2_SP0VSBUSY_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS2_SP0VSBUSY_SHFT                                              0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_ADDR                                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x84cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_OFFS                                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x84cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_RMSK                                                0xff70f0ful
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_DCOMBUSY_BMSK                                       0x8000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_DCOMBUSY_SHFT                                              27u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_COMBUSY_BMSK                                        0x4000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_COMBUSY_SHFT                                               26u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_MCRCCBUSY_BMSK                                      0x2000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_MCRCCBUSY_SHFT                                             25u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_SMMUSTALLEDONFAULT_BMSK                             0x1000000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_SMMUSTALLEDONFAULT_SHFT                                    24u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_UCHEWRAPPERBUSY_BMSK                                 0x800000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_UCHEWRAPPERBUSY_SHFT                                       23u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_GPCBUSY_BMSK                                         0x400000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_GPCBUSY_SHFT                                               22u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_LARCBUSY_BMSK                                        0x200000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_LARCBUSY_SHFT                                              21u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_HLSQSPTPBUSY_BMSK                                    0x100000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_HLSQSPTPBUSY_SHFT                                          20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_LAZYBUSY_BMSK                                         0x40000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_LAZYBUSY_SHFT                                              18u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_CCUDIRTY_BMSK                                         0x20000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_CCUDIRTY_SHFT                                              17u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_RBPBUSY_BMSK                                          0x10000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_RBPBUSY_SHFT                                               16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_BYPASS3BUSY_BMSK                                        0x800u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_BYPASS3BUSY_SHFT                                           11u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_BYPASS2BUSY_BMSK                                        0x400u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_BYPASS2BUSY_SHFT                                           10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_BYPASS1BUSY_BMSK                                        0x200u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_BYPASS1BUSY_SHFT                                            9u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_BYPASS0BUSY_BMSK                                        0x100u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_BYPASS0BUSY_SHFT                                            8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_RB3BUSY_BMSK                                              0x8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_RB3BUSY_SHFT                                                3u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_RB2BUSY_BMSK                                              0x4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_RB2BUSY_SHFT                                                2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_RB1BUSY_BMSK                                              0x2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_RB1BUSY_SHFT                                                1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_RB0BUSY_BMSK                                              0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_STATUS3_RB0BUSY_SHFT                                                0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_VBIF_GX_RESET_STATUS_ADDR                                  (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x854u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_VBIF_GX_RESET_STATUS_OFFS                                  (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x854u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_VBIF_GX_RESET_STATUS_RMSK                                    0xfffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_VBIF_GX_RESET_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_VBIF_GX_RESET_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_VBIF_GX_RESET_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_VBIF_GX_RESET_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_VBIF_GX_RESET_STATUS_VBIFRESETCOMPLETIONTIME_BMSK            0xffff00ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_VBIF_GX_RESET_STATUS_VBIFRESETCOMPLETIONTIME_SHFT                   8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_VBIF_GX_RESET_STATUS_VBIFRESETACKCOMPLETE_BMSK                   0xf0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_VBIF_GX_RESET_STATUS_VBIFRESETACKCOMPLETE_SHFT                      4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_VBIF_GX_RESET_STATUS_VBIFRESETREQCURR_BMSK                        0xfu
#define HWIO_SAIL_TO_MD_GPU_RBBM_VBIF_GX_RESET_STATUS_VBIFRESETREQCURR_SHFT                          0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_ADDR                                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x858u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_OFFS                                            (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x858u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_RMSK                                              0xfffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_GPUBUSYIGNAHB_BMSK                                0x800000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_GPUBUSYIGNAHB_SHFT                                      23u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_GPUBUSYIGNAHBCP_BMSK                              0x400000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_GPUBUSYIGNAHBCP_SHFT                                    22u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_HLSQBUSY_BMSK                                     0x200000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_HLSQBUSY_SHFT                                           21u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_VSCBUSY_BMSK                                      0x100000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_VSCBUSY_SHFT                                            20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_TPL1BUSY_BMSK                                      0x80000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_TPL1BUSY_SHFT                                           19u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_SPBUSY_BMSK                                        0x40000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_SPBUSY_SHFT                                             18u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_UCHEBUSY_BMSK                                      0x20000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_UCHEBUSY_SHFT                                           17u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_VPCBUSY_BMSK                                       0x10000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_VPCBUSY_SHFT                                            16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_VFDBUSY_BMSK                                        0x8000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_VFDBUSY_SHFT                                            15u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_TESSBUSY_BMSK                                       0x4000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_TESSBUSY_SHFT                                           14u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_PCVSDBUSY_BMSK                                      0x2000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_PCVSDBUSY_SHFT                                          13u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_PCDCALLBUSY_BMSK                                    0x1000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_PCDCALLBUSY_SHFT                                        12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_COMDCOMBUSY_BMSK                                     0x800u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_COMDCOMBUSY_SHFT                                        11u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_LRZBUSY_BMSK                                         0x400u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_LRZBUSY_SHFT                                            10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_A2DBUSY_BMSK                                         0x200u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_A2DBUSY_SHFT                                             9u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_CCUBUSY_BMSK                                         0x100u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_CCUBUSY_SHFT                                             8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_RBBUSY_BMSK                                           0x80u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_RBBUSY_SHFT                                              7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_RASBUSY_BMSK                                          0x40u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_RASBUSY_SHFT                                             6u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_TSEBUSY_BMSK                                          0x20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_TSEBUSY_SHFT                                             5u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_VBIFGXFPARTBUSY_BMSK                                  0x10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_VBIFGXFPARTBUSY_SHFT                                     4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_GFXDBGCBUSY_BMSK                                       0x8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_GFXDBGCBUSY_SHFT                                         3u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_CPBUSY_BMSK                                            0x4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_CPBUSY_SHFT                                              2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_CPAHBBUSYCPMASTER_BMSK                                 0x2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_CPAHBBUSYCPMASTER_SHFT                                   1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_CPAHBBUSYCXMASTER_BMSK                                 0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_GFX_STATUS_CPAHBBUSYCXMASTER_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_UCHE1_ADDR                                    (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x85cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_UCHE1_OFFS                                    (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x85cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_UCHE1_RMSK                                    0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_UCHE1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_UCHE1_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_UCHE1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_UCHE1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_UCHE1_CGCSTATUSUCHE_BMSK                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_CLOCK_STATUS_UCHE1_CGCSTATUSUCHE_SHFT                               0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS0_ADDR                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x860u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS0_OFFS                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x860u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS0_RMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS0_INTERFACESRDY_BMSK                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS0_INTERFACESRDY_SHFT                           0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS0_ADDR                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x864u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS0_OFFS                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x864u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS0_RMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS0_INTERFACERRDY_BMSK                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS0_INTERFACERRDY_SHFT                           0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS1_ADDR                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x868u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS1_OFFS                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x868u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS1_RMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS1_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS1_INTERFACESRDY_BMSK                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS1_INTERFACESRDY_SHFT                           0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS1_ADDR                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x86cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS1_OFFS                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x86cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS1_RMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS1_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS1_INTERFACERRDY_BMSK                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS1_INTERFACERRDY_SHFT                           0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS2_ADDR                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x870u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS2_OFFS                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x870u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS2_RMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS2_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS2_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS2_INTERFACESRDY_BMSK                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS2_INTERFACESRDY_SHFT                           0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS2_ADDR                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x874u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS2_OFFS                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x874u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS2_RMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS2_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS2_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS2_INTERFACERRDY_BMSK                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS2_INTERFACERRDY_SHFT                           0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS3_ADDR                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x878u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS3_OFFS                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x878u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS3_RMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS3_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS3_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS3_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS3_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS3_INTERFACESRDY_BMSK                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS3_INTERFACESRDY_SHFT                           0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS3_ADDR                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x87cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS3_OFFS                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x87cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS3_RMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS3_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS3_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS3_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS3_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS3_INTERFACERRDY_BMSK                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS3_INTERFACERRDY_SHFT                           0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS4_ADDR                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x880u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS4_OFFS                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x880u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS4_RMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS4_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS4_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS4_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS4_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS4_INTERFACESRDY_BMSK                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS4_INTERFACESRDY_SHFT                           0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS4_ADDR                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x884u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS4_OFFS                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x884u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS4_RMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS4_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS4_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS4_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS4_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS4_INTERFACERRDY_BMSK                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS4_INTERFACERRDY_SHFT                           0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS5_ADDR                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x888u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS5_OFFS                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x888u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS5_RMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS5_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS5_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS5_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS5_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS5_INTERFACESRDY_BMSK                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS5_INTERFACESRDY_SHFT                           0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS5_ADDR                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x88cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS5_OFFS                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x88cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS5_RMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS5_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS5_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS5_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS5_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS5_INTERFACERRDY_BMSK                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS5_INTERFACERRDY_SHFT                           0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS6_ADDR                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x890u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS6_OFFS                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x890u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS6_RMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS6_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS6_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS6_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS6_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS6_INTERFACESRDY_BMSK                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS6_INTERFACESRDY_SHFT                           0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS6_ADDR                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x894u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS6_OFFS                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x894u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS6_RMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS6_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS6_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS6_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS6_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS6_INTERFACERRDY_BMSK                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS6_INTERFACERRDY_SHFT                           0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS7_ADDR                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x898u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS7_OFFS                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x898u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS7_RMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS7_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS7_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS7_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS7_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS7_INTERFACESRDY_BMSK                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS7_INTERFACESRDY_SHFT                           0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS7_ADDR                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x89cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS7_OFFS                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x89cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS7_RMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS7_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS7_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS7_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS7_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS7_INTERFACERRDY_BMSK                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS7_INTERFACERRDY_SHFT                           0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS8_ADDR                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x8a0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS8_OFFS                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x8a0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS8_RMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS8_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS8_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS8_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS8_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS8_INTERFACESRDY_BMSK                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS8_INTERFACESRDY_SHFT                           0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS8_ADDR                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x8a4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS8_OFFS                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x8a4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS8_RMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS8_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS8_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS8_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS8_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS8_INTERFACERRDY_BMSK                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS8_INTERFACERRDY_SHFT                           0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS9_ADDR                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x8a8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS9_OFFS                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x8a8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS9_RMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS9_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS9_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS9_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS9_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS9_INTERFACESRDY_BMSK                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS9_INTERFACESRDY_SHFT                           0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS9_ADDR                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x8acu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS9_OFFS                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x8acu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS9_RMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS9_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS9_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS9_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS9_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS9_INTERFACERRDY_BMSK                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS9_INTERFACERRDY_SHFT                           0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS10_ADDR                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x8b0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS10_OFFS                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x8b0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS10_RMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS10_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS10_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS10_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS10_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS10_INTERFACESRDY_BMSK                 0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS10_INTERFACESRDY_SHFT                          0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS10_ADDR                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x8b4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS10_OFFS                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x8b4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS10_RMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS10_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS10_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS10_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS10_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS10_INTERFACERRDY_BMSK                 0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS10_INTERFACERRDY_SHFT                          0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS11_ADDR                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x8b8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS11_OFFS                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x8b8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS11_RMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS11_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS11_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS11_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS11_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS11_INTERFACESRDY_BMSK                 0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS11_INTERFACESRDY_SHFT                          0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS11_ADDR                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x8bcu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS11_OFFS                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x8bcu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS11_RMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS11_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS11_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS11_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS11_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS11_INTERFACERRDY_BMSK                 0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS11_INTERFACERRDY_SHFT                          0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS12_ADDR                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x8c0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS12_OFFS                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x8c0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS12_RMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS12_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS12_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS12_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS12_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS12_INTERFACESRDY_BMSK                 0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS12_INTERFACESRDY_SHFT                          0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS12_ADDR                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x8c4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS12_OFFS                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x8c4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS12_RMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS12_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS12_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS12_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS12_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS12_INTERFACERRDY_BMSK                 0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS12_INTERFACERRDY_SHFT                          0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS13_ADDR                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x8c8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS13_OFFS                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x8c8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS13_RMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS13_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS13_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS13_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS13_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS13_INTERFACESRDY_BMSK                 0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS13_INTERFACESRDY_SHFT                          0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS13_ADDR                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x8ccu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS13_OFFS                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x8ccu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS13_RMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS13_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS13_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS13_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS13_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS13_INTERFACERRDY_BMSK                 0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS13_INTERFACERRDY_SHFT                          0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS14_ADDR                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x8d0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS14_OFFS                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x8d0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS14_RMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS14_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS14_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS14_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS14_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS14_INTERFACESRDY_BMSK                 0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS14_INTERFACESRDY_SHFT                          0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS14_ADDR                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x8d4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS14_OFFS                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x8d4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS14_RMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS14_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS14_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS14_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS14_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS14_INTERFACERRDY_BMSK                 0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS14_INTERFACERRDY_SHFT                          0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS15_ADDR                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x8d8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS15_OFFS                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x8d8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS15_RMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS15_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS15_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS15_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS15_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS15_INTERFACESRDY_BMSK                 0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS15_INTERFACESRDY_SHFT                          0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS15_ADDR                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x8dcu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS15_OFFS                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x8dcu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS15_RMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS15_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS15_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS15_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS15_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS15_INTERFACERRDY_BMSK                 0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS15_INTERFACERRDY_SHFT                          0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS16_ADDR                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x8e0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS16_OFFS                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x8e0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS16_RMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS16_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS16_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS16_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS16_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS16_INTERFACESRDY_BMSK                 0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS16_INTERFACESRDY_SHFT                          0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS16_ADDR                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x8e4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS16_OFFS                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x8e4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS16_RMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS16_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS16_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS16_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS16_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS16_INTERFACERRDY_BMSK                 0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS16_INTERFACERRDY_SHFT                          0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS17_ADDR                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x8e8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS17_OFFS                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x8e8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS17_RMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS17_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS17_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS17_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS17_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS17_INTERFACESRDY_BMSK                 0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS17_INTERFACESRDY_SHFT                          0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS17_ADDR                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x8ecu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS17_OFFS                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x8ecu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS17_RMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS17_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS17_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS17_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS17_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS17_INTERFACERRDY_BMSK                 0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS17_INTERFACERRDY_SHFT                          0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS18_ADDR                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x8f0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS18_OFFS                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x8f0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS18_RMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS18_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS18_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS18_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS18_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS18_INTERFACESRDY_BMSK                 0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_SRDY_STATUS18_INTERFACESRDY_SHFT                          0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS18_ADDR                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x8f4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS18_OFFS                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x8f4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS18_RMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS18_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS18_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS18_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS18_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS18_INTERFACERRDY_BMSK                 0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_INTERFACE_RRDY_STATUS18_INTERFACERRDY_SHFT                          0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_0_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1000u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_0_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1000u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_0_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_0_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_0_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_0_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_0_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_0_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_0_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_0_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_0_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_0_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_0_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_0_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_0_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1004u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_0_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1004u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_0_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_0_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_0_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_0_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_0_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_0_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_0_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_0_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_0_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_0_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_0_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_0_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_1_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1008u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_1_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1008u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_1_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_1_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_1_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_1_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_1_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_1_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_1_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_1_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_1_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_1_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_1_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_1_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_1_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x100cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_1_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x100cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_1_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_1_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_1_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_1_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_1_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_1_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_1_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_1_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_1_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_1_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_1_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_1_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_2_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1010u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_2_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1010u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_2_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_2_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_2_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_2_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_2_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_2_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_2_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_2_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_2_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_2_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_2_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_2_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_2_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1014u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_2_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1014u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_2_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_2_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_2_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_2_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_2_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_2_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_2_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_2_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_2_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_2_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_2_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_2_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_3_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1018u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_3_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1018u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_3_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_3_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_3_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_3_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_3_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_3_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_3_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_3_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_3_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_3_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_3_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_3_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_3_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x101cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_3_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x101cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_3_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_3_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_3_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_3_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_3_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_3_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_3_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_3_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_3_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_3_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_3_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_3_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_4_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1020u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_4_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1020u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_4_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_4_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_4_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_4_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_4_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_4_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_4_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_4_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_4_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_4_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_4_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_4_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_4_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1024u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_4_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1024u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_4_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_4_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_4_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_4_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_4_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_4_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_4_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_4_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_4_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_4_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_4_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_4_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_5_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1028u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_5_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1028u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_5_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_5_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_5_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_5_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_5_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_5_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_5_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_5_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_5_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_5_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_5_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_5_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_5_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x102cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_5_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x102cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_5_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_5_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_5_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_5_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_5_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_5_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_5_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_5_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_5_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_5_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_5_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_5_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_6_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1030u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_6_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1030u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_6_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_6_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_6_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_6_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_6_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_6_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_6_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_6_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_6_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_6_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_6_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_6_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_6_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1034u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_6_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1034u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_6_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_6_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_6_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_6_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_6_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_6_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_6_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_6_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_6_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_6_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_6_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_6_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_7_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1038u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_7_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1038u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_7_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_7_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_7_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_7_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_7_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_7_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_7_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_7_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_7_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_7_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_7_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_7_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_7_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x103cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_7_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x103cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_7_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_7_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_7_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_7_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_7_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_7_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_7_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_7_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_7_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_7_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_7_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_7_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_8_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1040u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_8_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1040u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_8_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_8_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_8_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_8_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_8_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_8_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_8_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_8_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_8_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_8_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_8_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_8_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_8_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1044u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_8_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1044u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_8_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_8_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_8_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_8_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_8_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_8_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_8_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_8_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_8_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_8_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_8_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_8_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_9_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1048u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_9_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1048u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_9_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_9_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_9_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_9_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_9_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_9_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_9_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_9_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_9_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_9_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_9_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_9_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_9_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x104cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_9_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x104cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_9_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_9_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_9_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_9_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_9_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_9_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_9_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_9_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_9_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_9_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_9_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_9_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_10_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1050u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_10_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1050u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_10_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_10_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_10_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_10_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_10_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_10_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_10_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_10_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_10_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_10_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_10_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_10_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_10_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1054u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_10_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1054u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_10_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_10_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_10_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_10_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_10_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_10_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_10_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_10_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_10_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_10_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_10_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_10_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_11_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1058u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_11_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1058u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_11_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_11_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_11_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_11_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_11_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_11_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_11_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_11_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_11_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_11_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_11_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_11_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_11_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x105cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_11_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x105cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_11_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_11_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_11_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_11_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_11_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_11_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_11_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_11_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_11_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_11_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_11_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_11_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_12_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1060u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_12_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1060u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_12_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_12_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_12_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_12_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_12_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_12_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_12_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_12_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_12_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_12_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_12_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_12_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_12_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1064u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_12_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1064u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_12_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_12_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_12_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_12_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_12_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_12_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_12_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_12_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_12_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_12_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_12_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_12_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_13_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1068u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_13_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1068u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_13_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_13_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_13_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_13_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_13_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_13_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_13_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_13_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_13_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_13_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_13_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_13_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_13_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x106cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_13_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x106cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_13_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_13_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_13_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_13_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_13_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_13_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_13_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_13_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_13_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_13_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_13_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CP_13_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_0_LO_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1070u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_0_LO_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1070u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_0_LO_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_0_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_0_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_0_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_0_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_0_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_0_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_0_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_0_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_0_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_0_LO_PERFCOUNTLO_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_0_LO_PERFCOUNTLO_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_0_HI_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1074u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_0_HI_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1074u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_0_HI_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_0_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_0_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_0_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_0_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_0_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_0_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_0_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_0_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_0_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_0_HI_PERFCOUNTHI_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_0_HI_PERFCOUNTHI_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_1_LO_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1078u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_1_LO_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1078u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_1_LO_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_1_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_1_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_1_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_1_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_1_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_1_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_1_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_1_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_1_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_1_LO_PERFCOUNTLO_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_1_LO_PERFCOUNTLO_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_1_HI_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x107cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_1_HI_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x107cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_1_HI_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_1_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_1_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_1_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_1_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_1_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_1_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_1_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_1_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_1_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_1_HI_PERFCOUNTHI_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_1_HI_PERFCOUNTHI_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_2_LO_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1080u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_2_LO_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1080u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_2_LO_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_2_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_2_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_2_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_2_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_2_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_2_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_2_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_2_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_2_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_2_LO_PERFCOUNTLO_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_2_LO_PERFCOUNTLO_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_2_HI_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1084u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_2_HI_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1084u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_2_HI_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_2_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_2_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_2_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_2_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_2_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_2_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_2_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_2_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_2_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_2_HI_PERFCOUNTHI_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_2_HI_PERFCOUNTHI_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_3_LO_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1088u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_3_LO_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1088u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_3_LO_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_3_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_3_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_3_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_3_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_3_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_3_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_3_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_3_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_3_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_3_LO_PERFCOUNTLO_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_3_LO_PERFCOUNTLO_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_3_HI_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x108cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_3_HI_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x108cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_3_HI_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_3_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_3_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_3_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_3_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_3_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_3_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_3_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_3_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_3_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_3_HI_PERFCOUNTHI_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_3_HI_PERFCOUNTHI_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_0_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1090u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_0_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1090u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_0_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_0_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_0_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_0_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_0_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_0_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_0_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_0_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_0_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_0_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_0_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_0_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_0_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1094u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_0_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1094u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_0_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_0_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_0_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_0_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_0_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_0_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_0_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_0_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_0_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_0_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_0_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_0_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_1_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1098u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_1_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1098u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_1_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_1_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_1_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_1_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_1_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_1_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_1_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_1_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_1_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_1_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_1_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_1_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_1_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x109cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_1_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x109cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_1_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_1_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_1_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_1_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_1_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_1_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_1_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_1_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_1_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_1_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_1_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_1_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_2_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x10a0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_2_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x10a0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_2_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_2_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_2_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_2_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_2_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_2_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_2_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_2_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_2_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_2_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_2_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_2_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_2_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x10a4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_2_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x10a4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_2_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_2_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_2_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_2_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_2_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_2_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_2_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_2_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_2_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_2_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_2_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_2_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_3_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x10a8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_3_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x10a8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_3_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_3_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_3_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_3_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_3_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_3_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_3_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_3_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_3_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_3_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_3_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_3_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_3_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x10acu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_3_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x10acu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_3_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_3_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_3_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_3_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_3_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_3_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_3_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_3_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_3_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_3_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_3_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_3_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_4_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x10b0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_4_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x10b0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_4_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_4_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_4_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_4_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_4_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_4_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_4_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_4_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_4_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_4_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_4_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_4_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_4_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x10b4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_4_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x10b4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_4_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_4_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_4_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_4_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_4_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_4_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_4_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_4_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_4_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_4_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_4_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_4_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_5_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x10b8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_5_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x10b8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_5_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_5_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_5_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_5_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_5_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_5_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_5_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_5_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_5_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_5_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_5_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_5_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_5_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x10bcu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_5_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x10bcu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_5_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_5_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_5_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_5_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_5_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_5_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_5_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_5_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_5_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_5_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_5_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_5_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_6_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x10c0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_6_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x10c0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_6_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_6_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_6_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_6_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_6_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_6_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_6_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_6_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_6_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_6_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_6_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_6_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_6_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x10c4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_6_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x10c4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_6_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_6_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_6_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_6_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_6_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_6_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_6_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_6_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_6_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_6_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_6_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_6_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_7_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x10c8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_7_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x10c8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_7_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_7_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_7_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_7_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_7_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_7_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_7_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_7_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_7_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_7_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_7_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_7_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_7_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x10ccu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_7_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x10ccu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_7_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_7_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_7_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_7_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_7_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_7_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_7_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_7_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_7_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_7_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_7_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_PC_7_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_0_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x10d0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_0_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x10d0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_0_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_0_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_0_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_0_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_0_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_0_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_0_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_0_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_0_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_0_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_0_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_0_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_0_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x10d4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_0_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x10d4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_0_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_0_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_0_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_0_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_0_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_0_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_0_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_0_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_0_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_0_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_0_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_0_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_1_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x10d8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_1_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x10d8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_1_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_1_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_1_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_1_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_1_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_1_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_1_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_1_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_1_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_1_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_1_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_1_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_1_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x10dcu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_1_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x10dcu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_1_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_1_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_1_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_1_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_1_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_1_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_1_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_1_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_1_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_1_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_1_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_1_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_2_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x10e0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_2_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x10e0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_2_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_2_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_2_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_2_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_2_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_2_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_2_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_2_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_2_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_2_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_2_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_2_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_2_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x10e4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_2_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x10e4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_2_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_2_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_2_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_2_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_2_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_2_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_2_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_2_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_2_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_2_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_2_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_2_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_3_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x10e8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_3_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x10e8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_3_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_3_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_3_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_3_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_3_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_3_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_3_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_3_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_3_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_3_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_3_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_3_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_3_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x10ecu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_3_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x10ecu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_3_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_3_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_3_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_3_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_3_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_3_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_3_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_3_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_3_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_3_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_3_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_3_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_4_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x10f0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_4_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x10f0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_4_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_4_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_4_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_4_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_4_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_4_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_4_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_4_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_4_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_4_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_4_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_4_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_4_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x10f4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_4_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x10f4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_4_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_4_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_4_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_4_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_4_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_4_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_4_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_4_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_4_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_4_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_4_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_4_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_5_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x10f8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_5_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x10f8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_5_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_5_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_5_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_5_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_5_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_5_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_5_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_5_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_5_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_5_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_5_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_5_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_5_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x10fcu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_5_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x10fcu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_5_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_5_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_5_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_5_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_5_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_5_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_5_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_5_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_5_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_5_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_5_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_5_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_6_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1100u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_6_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1100u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_6_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_6_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_6_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_6_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_6_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_6_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_6_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_6_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_6_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_6_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_6_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_6_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_6_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1104u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_6_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1104u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_6_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_6_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_6_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_6_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_6_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_6_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_6_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_6_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_6_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_6_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_6_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_6_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_7_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1108u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_7_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1108u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_7_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_7_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_7_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_7_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_7_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_7_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_7_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_7_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_7_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_7_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_7_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_7_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_7_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x110cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_7_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x110cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_7_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_7_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_7_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_7_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_7_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_7_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_7_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_7_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_7_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_7_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_7_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VFD_7_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_0_LO_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1110u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_0_LO_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1110u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_0_LO_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_0_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_0_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_0_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_0_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_0_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_0_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_0_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_0_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_0_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_0_LO_PERFCOUNTLO_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_0_LO_PERFCOUNTLO_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_0_HI_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1114u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_0_HI_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1114u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_0_HI_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_0_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_0_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_0_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_0_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_0_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_0_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_0_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_0_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_0_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_0_HI_PERFCOUNTHI_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_0_HI_PERFCOUNTHI_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_1_LO_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1118u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_1_LO_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1118u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_1_LO_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_1_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_1_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_1_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_1_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_1_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_1_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_1_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_1_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_1_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_1_LO_PERFCOUNTLO_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_1_LO_PERFCOUNTLO_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_1_HI_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x111cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_1_HI_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x111cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_1_HI_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_1_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_1_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_1_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_1_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_1_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_1_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_1_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_1_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_1_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_1_HI_PERFCOUNTHI_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_1_HI_PERFCOUNTHI_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_2_LO_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1120u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_2_LO_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1120u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_2_LO_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_2_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_2_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_2_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_2_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_2_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_2_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_2_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_2_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_2_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_2_LO_PERFCOUNTLO_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_2_LO_PERFCOUNTLO_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_2_HI_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1124u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_2_HI_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1124u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_2_HI_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_2_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_2_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_2_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_2_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_2_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_2_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_2_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_2_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_2_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_2_HI_PERFCOUNTHI_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_2_HI_PERFCOUNTHI_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_3_LO_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1128u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_3_LO_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1128u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_3_LO_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_3_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_3_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_3_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_3_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_3_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_3_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_3_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_3_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_3_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_3_LO_PERFCOUNTLO_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_3_LO_PERFCOUNTLO_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_3_HI_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x112cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_3_HI_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x112cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_3_HI_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_3_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_3_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_3_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_3_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_3_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_3_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_3_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_3_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_3_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_3_HI_PERFCOUNTHI_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_3_HI_PERFCOUNTHI_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_4_LO_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1130u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_4_LO_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1130u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_4_LO_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_4_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_4_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_4_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_4_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_4_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_4_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_4_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_4_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_4_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_4_LO_PERFCOUNTLO_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_4_LO_PERFCOUNTLO_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_4_HI_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1134u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_4_HI_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1134u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_4_HI_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_4_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_4_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_4_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_4_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_4_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_4_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_4_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_4_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_4_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_4_HI_PERFCOUNTHI_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_4_HI_PERFCOUNTHI_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_5_LO_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1138u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_5_LO_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1138u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_5_LO_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_5_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_5_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_5_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_5_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_5_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_5_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_5_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_5_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_5_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_5_LO_PERFCOUNTLO_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_5_LO_PERFCOUNTLO_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_5_HI_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x113cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_5_HI_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x113cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_5_HI_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_5_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_5_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_5_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_5_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_5_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_5_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_5_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_5_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_5_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_5_HI_PERFCOUNTHI_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_HLSQ_5_HI_PERFCOUNTHI_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_0_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1140u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_0_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1140u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_0_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_0_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_0_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_0_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_0_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_0_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_0_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_0_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_0_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_0_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_0_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_0_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_0_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1144u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_0_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1144u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_0_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_0_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_0_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_0_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_0_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_0_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_0_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_0_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_0_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_0_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_0_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_0_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_1_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1148u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_1_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1148u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_1_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_1_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_1_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_1_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_1_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_1_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_1_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_1_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_1_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_1_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_1_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_1_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_1_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x114cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_1_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x114cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_1_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_1_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_1_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_1_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_1_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_1_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_1_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_1_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_1_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_1_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_1_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_1_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_2_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1150u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_2_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1150u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_2_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_2_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_2_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_2_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_2_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_2_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_2_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_2_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_2_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_2_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_2_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_2_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_2_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1154u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_2_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1154u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_2_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_2_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_2_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_2_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_2_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_2_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_2_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_2_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_2_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_2_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_2_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_2_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_3_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1158u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_3_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1158u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_3_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_3_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_3_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_3_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_3_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_3_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_3_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_3_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_3_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_3_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_3_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_3_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_3_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x115cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_3_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x115cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_3_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_3_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_3_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_3_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_3_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_3_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_3_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_3_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_3_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_3_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_3_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_3_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_4_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1160u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_4_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1160u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_4_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_4_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_4_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_4_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_4_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_4_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_4_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_4_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_4_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_4_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_4_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_4_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_4_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1164u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_4_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1164u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_4_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_4_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_4_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_4_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_4_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_4_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_4_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_4_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_4_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_4_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_4_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_4_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_5_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1168u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_5_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1168u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_5_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_5_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_5_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_5_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_5_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_5_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_5_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_5_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_5_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_5_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_5_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_5_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_5_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x116cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_5_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x116cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_5_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_5_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_5_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_5_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_5_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_5_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_5_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_5_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_5_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_5_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_5_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VPC_5_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_0_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1170u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_0_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1170u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_0_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_0_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_0_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_0_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_0_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_0_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_0_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_0_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_0_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_0_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_0_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_0_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_0_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1174u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_0_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1174u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_0_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_0_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_0_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_0_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_0_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_0_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_0_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_0_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_0_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_0_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_0_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_0_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_1_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1178u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_1_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1178u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_1_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_1_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_1_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_1_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_1_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_1_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_1_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_1_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_1_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_1_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_1_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_1_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_1_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x117cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_1_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x117cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_1_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_1_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_1_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_1_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_1_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_1_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_1_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_1_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_1_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_1_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_1_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_1_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_2_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1180u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_2_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1180u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_2_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_2_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_2_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_2_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_2_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_2_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_2_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_2_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_2_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_2_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_2_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_2_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_2_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1184u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_2_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1184u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_2_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_2_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_2_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_2_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_2_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_2_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_2_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_2_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_2_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_2_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_2_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_2_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_3_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1188u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_3_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1188u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_3_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_3_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_3_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_3_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_3_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_3_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_3_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_3_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_3_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_3_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_3_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_3_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_3_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x118cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_3_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x118cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_3_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_3_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_3_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_3_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_3_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_3_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_3_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_3_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_3_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_3_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_3_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_3_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_4_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1190u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_4_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1190u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_4_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_4_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_4_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_4_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_4_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_4_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_4_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_4_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_4_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_4_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_4_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_4_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_4_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1194u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_4_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1194u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_4_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_4_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_4_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_4_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_4_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_4_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_4_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_4_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_4_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_4_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_4_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CCU_4_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_0_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1198u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_0_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1198u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_0_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_0_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_0_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_0_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_0_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_0_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_0_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_0_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_0_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_0_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_0_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_0_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_0_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x119cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_0_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x119cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_0_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_0_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_0_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_0_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_0_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_0_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_0_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_0_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_0_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_0_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_0_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_0_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_1_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x11a0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_1_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x11a0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_1_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_1_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_1_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_1_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_1_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_1_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_1_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_1_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_1_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_1_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_1_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_1_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_1_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x11a4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_1_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x11a4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_1_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_1_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_1_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_1_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_1_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_1_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_1_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_1_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_1_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_1_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_1_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_1_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_2_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x11a8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_2_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x11a8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_2_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_2_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_2_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_2_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_2_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_2_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_2_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_2_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_2_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_2_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_2_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_2_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_2_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x11acu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_2_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x11acu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_2_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_2_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_2_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_2_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_2_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_2_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_2_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_2_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_2_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_2_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_2_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_2_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_3_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x11b0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_3_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x11b0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_3_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_3_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_3_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_3_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_3_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_3_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_3_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_3_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_3_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_3_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_3_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_3_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_3_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x11b4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_3_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x11b4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_3_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_3_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_3_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_3_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_3_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_3_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_3_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_3_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_3_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_3_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_3_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TSE_3_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_0_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x11b8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_0_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x11b8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_0_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_0_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_0_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_0_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_0_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_0_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_0_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_0_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_0_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_0_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_0_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_0_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_0_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x11bcu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_0_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x11bcu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_0_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_0_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_0_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_0_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_0_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_0_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_0_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_0_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_0_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_0_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_0_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_0_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_1_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x11c0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_1_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x11c0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_1_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_1_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_1_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_1_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_1_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_1_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_1_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_1_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_1_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_1_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_1_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_1_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_1_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x11c4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_1_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x11c4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_1_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_1_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_1_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_1_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_1_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_1_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_1_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_1_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_1_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_1_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_1_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_1_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_2_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x11c8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_2_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x11c8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_2_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_2_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_2_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_2_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_2_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_2_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_2_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_2_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_2_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_2_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_2_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_2_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_2_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x11ccu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_2_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x11ccu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_2_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_2_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_2_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_2_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_2_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_2_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_2_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_2_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_2_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_2_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_2_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_2_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_3_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x11d0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_3_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x11d0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_3_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_3_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_3_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_3_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_3_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_3_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_3_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_3_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_3_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_3_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_3_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_3_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_3_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x11d4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_3_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x11d4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_3_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_3_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_3_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_3_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_3_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_3_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_3_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_3_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_3_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_3_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_3_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RAS_3_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_0_LO_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x11d8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_0_LO_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x11d8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_0_LO_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_0_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_0_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_0_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_0_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_0_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_0_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_0_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_0_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_0_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_0_LO_PERFCOUNTLO_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_0_LO_PERFCOUNTLO_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_0_HI_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x11dcu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_0_HI_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x11dcu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_0_HI_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_0_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_0_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_0_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_0_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_0_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_0_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_0_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_0_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_0_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_0_HI_PERFCOUNTHI_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_0_HI_PERFCOUNTHI_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_1_LO_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x11e0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_1_LO_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x11e0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_1_LO_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_1_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_1_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_1_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_1_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_1_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_1_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_1_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_1_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_1_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_1_LO_PERFCOUNTLO_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_1_LO_PERFCOUNTLO_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_1_HI_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x11e4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_1_HI_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x11e4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_1_HI_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_1_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_1_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_1_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_1_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_1_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_1_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_1_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_1_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_1_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_1_HI_PERFCOUNTHI_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_1_HI_PERFCOUNTHI_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_2_LO_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x11e8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_2_LO_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x11e8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_2_LO_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_2_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_2_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_2_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_2_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_2_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_2_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_2_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_2_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_2_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_2_LO_PERFCOUNTLO_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_2_LO_PERFCOUNTLO_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_2_HI_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x11ecu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_2_HI_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x11ecu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_2_HI_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_2_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_2_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_2_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_2_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_2_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_2_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_2_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_2_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_2_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_2_HI_PERFCOUNTHI_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_2_HI_PERFCOUNTHI_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_3_LO_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x11f0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_3_LO_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x11f0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_3_LO_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_3_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_3_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_3_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_3_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_3_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_3_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_3_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_3_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_3_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_3_LO_PERFCOUNTLO_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_3_LO_PERFCOUNTLO_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_3_HI_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x11f4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_3_HI_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x11f4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_3_HI_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_3_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_3_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_3_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_3_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_3_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_3_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_3_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_3_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_3_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_3_HI_PERFCOUNTHI_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_3_HI_PERFCOUNTHI_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_4_LO_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x11f8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_4_LO_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x11f8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_4_LO_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_4_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_4_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_4_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_4_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_4_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_4_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_4_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_4_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_4_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_4_LO_PERFCOUNTLO_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_4_LO_PERFCOUNTLO_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_4_HI_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x11fcu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_4_HI_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x11fcu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_4_HI_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_4_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_4_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_4_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_4_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_4_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_4_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_4_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_4_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_4_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_4_HI_PERFCOUNTHI_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_4_HI_PERFCOUNTHI_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_5_LO_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1200u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_5_LO_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1200u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_5_LO_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_5_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_5_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_5_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_5_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_5_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_5_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_5_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_5_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_5_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_5_LO_PERFCOUNTLO_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_5_LO_PERFCOUNTLO_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_5_HI_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1204u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_5_HI_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1204u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_5_HI_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_5_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_5_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_5_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_5_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_5_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_5_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_5_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_5_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_5_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_5_HI_PERFCOUNTHI_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_5_HI_PERFCOUNTHI_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_6_LO_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1208u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_6_LO_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1208u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_6_LO_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_6_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_6_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_6_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_6_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_6_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_6_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_6_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_6_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_6_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_6_LO_PERFCOUNTLO_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_6_LO_PERFCOUNTLO_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_6_HI_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x120cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_6_HI_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x120cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_6_HI_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_6_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_6_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_6_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_6_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_6_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_6_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_6_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_6_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_6_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_6_HI_PERFCOUNTHI_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_6_HI_PERFCOUNTHI_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_7_LO_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1210u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_7_LO_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1210u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_7_LO_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_7_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_7_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_7_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_7_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_7_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_7_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_7_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_7_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_7_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_7_LO_PERFCOUNTLO_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_7_LO_PERFCOUNTLO_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_7_HI_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1214u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_7_HI_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1214u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_7_HI_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_7_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_7_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_7_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_7_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_7_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_7_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_7_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_7_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_7_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_7_HI_PERFCOUNTHI_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_7_HI_PERFCOUNTHI_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_8_LO_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1218u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_8_LO_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1218u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_8_LO_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_8_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_8_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_8_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_8_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_8_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_8_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_8_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_8_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_8_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_8_LO_PERFCOUNTLO_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_8_LO_PERFCOUNTLO_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_8_HI_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x121cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_8_HI_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x121cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_8_HI_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_8_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_8_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_8_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_8_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_8_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_8_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_8_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_8_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_8_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_8_HI_PERFCOUNTHI_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_8_HI_PERFCOUNTHI_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_9_LO_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1220u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_9_LO_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1220u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_9_LO_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_9_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_9_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_9_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_9_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_9_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_9_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_9_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_9_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_9_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_9_LO_PERFCOUNTLO_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_9_LO_PERFCOUNTLO_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_9_HI_ADDR                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1224u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_9_HI_OFFS                                     (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1224u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_9_HI_RMSK                                     0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_9_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_9_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_9_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_9_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_9_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_9_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_9_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_9_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_9_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_9_HI_PERFCOUNTHI_BMSK                         0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_9_HI_PERFCOUNTHI_SHFT                                  0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_10_LO_ADDR                                    (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1228u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_10_LO_OFFS                                    (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1228u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_10_LO_RMSK                                    0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_10_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_10_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_10_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_10_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_10_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_10_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_10_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_10_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_10_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_10_LO_PERFCOUNTLO_BMSK                        0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_10_LO_PERFCOUNTLO_SHFT                                 0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_10_HI_ADDR                                    (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x122cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_10_HI_OFFS                                    (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x122cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_10_HI_RMSK                                    0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_10_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_10_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_10_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_10_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_10_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_10_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_10_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_10_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_10_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_10_HI_PERFCOUNTHI_BMSK                        0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_10_HI_PERFCOUNTHI_SHFT                                 0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_11_LO_ADDR                                    (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1230u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_11_LO_OFFS                                    (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1230u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_11_LO_RMSK                                    0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_11_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_11_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_11_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_11_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_11_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_11_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_11_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_11_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_11_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_11_LO_PERFCOUNTLO_BMSK                        0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_11_LO_PERFCOUNTLO_SHFT                                 0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_11_HI_ADDR                                    (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1234u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_11_HI_OFFS                                    (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1234u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_11_HI_RMSK                                    0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_11_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_11_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_11_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_11_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_11_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_11_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_11_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_11_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_11_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_11_HI_PERFCOUNTHI_BMSK                        0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_UCHE_11_HI_PERFCOUNTHI_SHFT                                 0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_0_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1238u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_0_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1238u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_0_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_0_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_0_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_0_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_0_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_0_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_0_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_0_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_0_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_0_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_0_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_0_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_0_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x123cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_0_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x123cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_0_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_0_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_0_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_0_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_0_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_0_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_0_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_0_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_0_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_0_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_0_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_0_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_1_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1240u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_1_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1240u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_1_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_1_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_1_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_1_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_1_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_1_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_1_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_1_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_1_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_1_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_1_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_1_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_1_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1244u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_1_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1244u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_1_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_1_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_1_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_1_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_1_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_1_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_1_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_1_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_1_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_1_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_1_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_1_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_2_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1248u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_2_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1248u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_2_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_2_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_2_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_2_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_2_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_2_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_2_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_2_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_2_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_2_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_2_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_2_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_2_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x124cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_2_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x124cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_2_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_2_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_2_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_2_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_2_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_2_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_2_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_2_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_2_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_2_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_2_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_2_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_3_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1250u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_3_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1250u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_3_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_3_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_3_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_3_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_3_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_3_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_3_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_3_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_3_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_3_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_3_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_3_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_3_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1254u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_3_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1254u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_3_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_3_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_3_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_3_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_3_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_3_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_3_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_3_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_3_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_3_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_3_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_3_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_4_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1258u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_4_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1258u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_4_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_4_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_4_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_4_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_4_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_4_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_4_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_4_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_4_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_4_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_4_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_4_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_4_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x125cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_4_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x125cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_4_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_4_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_4_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_4_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_4_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_4_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_4_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_4_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_4_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_4_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_4_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_4_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_5_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1260u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_5_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1260u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_5_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_5_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_5_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_5_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_5_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_5_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_5_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_5_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_5_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_5_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_5_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_5_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_5_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1264u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_5_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1264u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_5_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_5_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_5_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_5_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_5_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_5_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_5_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_5_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_5_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_5_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_5_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_5_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_6_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1268u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_6_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1268u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_6_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_6_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_6_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_6_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_6_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_6_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_6_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_6_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_6_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_6_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_6_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_6_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_6_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x126cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_6_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x126cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_6_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_6_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_6_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_6_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_6_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_6_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_6_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_6_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_6_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_6_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_6_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_6_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_7_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1270u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_7_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1270u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_7_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_7_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_7_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_7_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_7_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_7_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_7_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_7_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_7_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_7_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_7_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_7_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_7_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1274u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_7_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1274u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_7_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_7_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_7_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_7_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_7_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_7_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_7_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_7_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_7_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_7_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_7_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_7_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_8_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1278u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_8_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1278u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_8_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_8_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_8_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_8_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_8_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_8_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_8_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_8_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_8_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_8_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_8_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_8_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_8_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x127cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_8_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x127cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_8_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_8_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_8_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_8_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_8_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_8_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_8_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_8_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_8_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_8_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_8_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_8_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_9_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1280u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_9_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1280u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_9_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_9_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_9_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_9_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_9_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_9_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_9_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_9_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_9_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_9_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_9_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_9_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_9_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1284u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_9_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1284u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_9_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_9_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_9_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_9_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_9_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_9_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_9_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_9_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_9_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_9_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_9_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_9_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_10_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1288u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_10_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1288u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_10_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_10_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_10_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_10_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_10_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_10_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_10_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_10_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_10_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_10_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_10_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_10_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_10_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x128cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_10_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x128cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_10_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_10_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_10_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_10_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_10_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_10_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_10_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_10_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_10_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_10_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_10_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_10_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_11_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1290u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_11_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1290u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_11_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_11_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_11_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_11_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_11_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_11_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_11_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_11_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_11_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_11_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_11_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_11_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_11_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1294u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_11_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1294u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_11_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_11_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_11_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_11_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_11_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_11_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_11_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_11_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_11_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_11_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_11_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_TP_11_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_0_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1298u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_0_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1298u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_0_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_0_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_0_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_0_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_0_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_0_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_0_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_0_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_0_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_0_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_0_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_0_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_0_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x129cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_0_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x129cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_0_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_0_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_0_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_0_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_0_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_0_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_0_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_0_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_0_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_0_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_0_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_0_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_1_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x12a0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_1_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x12a0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_1_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_1_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_1_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_1_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_1_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_1_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_1_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_1_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_1_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_1_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_1_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_1_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_1_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x12a4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_1_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x12a4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_1_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_1_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_1_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_1_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_1_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_1_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_1_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_1_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_1_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_1_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_1_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_1_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_2_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x12a8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_2_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x12a8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_2_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_2_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_2_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_2_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_2_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_2_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_2_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_2_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_2_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_2_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_2_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_2_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_2_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x12acu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_2_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x12acu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_2_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_2_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_2_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_2_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_2_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_2_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_2_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_2_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_2_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_2_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_2_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_2_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_3_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x12b0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_3_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x12b0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_3_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_3_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_3_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_3_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_3_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_3_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_3_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_3_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_3_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_3_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_3_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_3_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_3_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x12b4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_3_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x12b4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_3_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_3_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_3_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_3_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_3_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_3_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_3_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_3_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_3_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_3_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_3_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_3_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_4_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x12b8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_4_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x12b8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_4_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_4_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_4_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_4_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_4_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_4_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_4_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_4_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_4_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_4_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_4_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_4_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_4_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x12bcu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_4_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x12bcu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_4_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_4_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_4_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_4_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_4_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_4_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_4_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_4_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_4_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_4_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_4_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_4_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_5_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x12c0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_5_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x12c0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_5_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_5_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_5_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_5_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_5_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_5_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_5_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_5_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_5_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_5_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_5_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_5_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_5_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x12c4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_5_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x12c4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_5_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_5_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_5_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_5_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_5_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_5_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_5_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_5_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_5_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_5_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_5_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_5_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_6_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x12c8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_6_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x12c8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_6_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_6_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_6_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_6_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_6_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_6_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_6_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_6_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_6_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_6_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_6_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_6_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_6_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x12ccu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_6_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x12ccu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_6_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_6_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_6_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_6_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_6_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_6_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_6_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_6_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_6_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_6_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_6_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_6_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_7_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x12d0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_7_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x12d0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_7_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_7_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_7_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_7_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_7_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_7_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_7_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_7_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_7_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_7_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_7_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_7_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_7_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x12d4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_7_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x12d4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_7_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_7_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_7_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_7_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_7_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_7_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_7_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_7_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_7_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_7_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_7_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_7_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_8_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x12d8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_8_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x12d8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_8_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_8_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_8_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_8_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_8_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_8_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_8_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_8_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_8_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_8_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_8_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_8_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_8_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x12dcu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_8_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x12dcu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_8_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_8_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_8_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_8_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_8_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_8_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_8_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_8_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_8_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_8_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_8_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_8_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_9_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x12e0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_9_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x12e0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_9_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_9_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_9_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_9_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_9_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_9_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_9_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_9_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_9_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_9_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_9_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_9_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_9_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x12e4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_9_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x12e4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_9_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_9_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_9_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_9_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_9_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_9_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_9_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_9_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_9_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_9_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_9_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_9_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_10_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x12e8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_10_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x12e8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_10_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_10_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_10_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_10_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_10_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_10_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_10_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_10_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_10_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_10_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_10_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_10_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_10_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x12ecu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_10_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x12ecu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_10_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_10_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_10_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_10_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_10_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_10_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_10_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_10_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_10_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_10_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_10_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_10_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_11_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x12f0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_11_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x12f0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_11_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_11_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_11_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_11_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_11_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_11_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_11_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_11_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_11_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_11_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_11_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_11_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_11_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x12f4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_11_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x12f4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_11_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_11_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_11_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_11_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_11_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_11_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_11_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_11_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_11_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_11_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_11_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_11_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_12_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x12f8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_12_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x12f8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_12_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_12_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_12_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_12_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_12_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_12_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_12_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_12_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_12_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_12_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_12_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_12_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_12_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x12fcu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_12_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x12fcu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_12_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_12_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_12_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_12_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_12_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_12_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_12_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_12_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_12_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_12_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_12_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_12_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_13_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1300u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_13_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1300u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_13_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_13_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_13_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_13_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_13_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_13_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_13_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_13_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_13_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_13_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_13_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_13_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_13_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1304u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_13_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1304u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_13_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_13_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_13_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_13_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_13_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_13_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_13_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_13_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_13_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_13_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_13_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_13_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_14_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1308u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_14_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1308u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_14_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_14_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_14_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_14_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_14_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_14_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_14_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_14_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_14_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_14_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_14_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_14_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_14_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x130cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_14_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x130cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_14_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_14_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_14_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_14_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_14_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_14_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_14_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_14_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_14_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_14_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_14_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_14_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_15_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1310u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_15_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1310u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_15_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_15_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_15_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_15_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_15_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_15_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_15_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_15_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_15_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_15_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_15_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_15_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_15_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1314u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_15_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1314u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_15_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_15_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_15_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_15_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_15_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_15_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_15_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_15_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_15_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_15_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_15_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_15_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_16_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1318u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_16_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1318u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_16_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_16_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_16_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_16_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_16_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_16_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_16_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_16_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_16_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_16_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_16_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_16_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_16_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x131cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_16_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x131cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_16_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_16_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_16_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_16_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_16_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_16_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_16_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_16_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_16_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_16_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_16_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_16_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_17_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1320u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_17_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1320u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_17_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_17_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_17_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_17_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_17_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_17_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_17_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_17_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_17_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_17_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_17_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_17_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_17_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1324u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_17_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1324u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_17_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_17_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_17_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_17_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_17_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_17_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_17_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_17_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_17_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_17_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_17_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_17_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_18_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1328u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_18_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1328u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_18_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_18_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_18_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_18_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_18_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_18_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_18_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_18_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_18_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_18_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_18_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_18_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_18_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x132cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_18_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x132cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_18_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_18_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_18_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_18_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_18_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_18_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_18_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_18_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_18_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_18_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_18_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_18_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_19_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1330u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_19_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1330u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_19_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_19_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_19_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_19_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_19_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_19_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_19_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_19_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_19_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_19_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_19_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_19_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_19_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1334u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_19_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1334u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_19_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_19_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_19_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_19_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_19_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_19_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_19_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_19_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_19_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_19_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_19_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_19_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_20_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1338u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_20_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1338u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_20_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_20_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_20_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_20_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_20_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_20_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_20_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_20_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_20_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_20_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_20_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_20_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_20_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x133cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_20_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x133cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_20_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_20_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_20_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_20_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_20_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_20_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_20_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_20_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_20_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_20_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_20_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_20_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_21_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1340u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_21_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1340u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_21_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_21_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_21_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_21_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_21_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_21_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_21_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_21_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_21_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_21_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_21_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_21_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_21_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1344u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_21_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1344u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_21_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_21_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_21_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_21_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_21_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_21_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_21_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_21_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_21_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_21_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_21_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_21_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_22_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1348u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_22_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1348u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_22_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_22_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_22_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_22_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_22_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_22_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_22_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_22_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_22_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_22_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_22_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_22_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_22_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x134cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_22_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x134cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_22_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_22_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_22_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_22_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_22_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_22_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_22_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_22_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_22_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_22_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_22_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_22_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_23_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1350u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_23_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1350u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_23_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_23_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_23_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_23_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_23_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_23_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_23_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_23_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_23_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_23_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_23_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_23_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_23_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1354u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_23_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1354u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_23_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_23_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_23_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_23_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_23_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_23_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_23_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_23_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_23_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_23_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_23_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SP_23_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_0_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1358u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_0_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1358u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_0_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_0_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_0_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_0_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_0_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_0_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_0_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_0_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_0_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_0_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_0_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_0_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_0_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x135cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_0_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x135cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_0_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_0_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_0_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_0_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_0_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_0_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_0_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_0_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_0_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_0_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_0_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_0_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_1_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1360u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_1_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1360u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_1_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_1_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_1_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_1_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_1_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_1_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_1_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_1_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_1_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_1_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_1_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_1_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_1_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1364u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_1_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1364u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_1_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_1_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_1_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_1_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_1_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_1_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_1_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_1_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_1_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_1_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_1_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_1_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_2_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1368u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_2_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1368u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_2_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_2_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_2_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_2_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_2_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_2_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_2_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_2_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_2_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_2_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_2_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_2_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_2_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x136cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_2_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x136cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_2_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_2_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_2_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_2_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_2_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_2_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_2_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_2_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_2_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_2_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_2_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_2_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_3_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1370u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_3_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1370u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_3_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_3_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_3_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_3_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_3_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_3_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_3_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_3_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_3_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_3_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_3_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_3_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_3_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1374u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_3_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1374u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_3_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_3_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_3_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_3_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_3_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_3_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_3_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_3_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_3_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_3_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_3_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_3_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_4_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1378u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_4_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1378u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_4_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_4_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_4_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_4_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_4_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_4_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_4_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_4_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_4_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_4_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_4_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_4_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_4_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x137cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_4_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x137cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_4_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_4_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_4_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_4_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_4_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_4_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_4_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_4_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_4_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_4_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_4_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_4_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_5_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1380u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_5_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1380u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_5_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_5_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_5_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_5_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_5_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_5_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_5_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_5_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_5_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_5_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_5_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_5_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_5_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1384u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_5_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1384u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_5_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_5_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_5_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_5_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_5_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_5_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_5_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_5_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_5_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_5_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_5_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_5_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_6_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1388u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_6_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1388u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_6_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_6_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_6_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_6_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_6_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_6_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_6_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_6_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_6_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_6_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_6_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_6_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_6_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x138cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_6_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x138cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_6_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_6_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_6_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_6_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_6_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_6_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_6_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_6_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_6_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_6_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_6_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_6_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_7_LO_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1390u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_7_LO_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1390u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_7_LO_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_7_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_7_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_7_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_7_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_7_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_7_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_7_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_7_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_7_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_7_LO_PERFCOUNTLO_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_7_LO_PERFCOUNTLO_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_7_HI_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1394u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_7_HI_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1394u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_7_HI_RMSK                                       0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_7_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_7_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_7_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_7_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_7_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_7_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_7_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_7_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_7_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_7_HI_PERFCOUNTHI_BMSK                           0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RB_7_HI_PERFCOUNTHI_SHFT                                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_0_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1398u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_0_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1398u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_0_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_0_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_0_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_0_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_0_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_0_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_0_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_0_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_0_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_0_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_0_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_0_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_0_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x139cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_0_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x139cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_0_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_0_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_0_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_0_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_0_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_0_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_0_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_0_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_0_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_0_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_0_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_0_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_1_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x13a0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_1_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x13a0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_1_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_1_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_1_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_1_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_1_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_1_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_1_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_1_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_1_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_1_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_1_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_1_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_1_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x13a4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_1_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x13a4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_1_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_1_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_1_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_1_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_1_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_1_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_1_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_1_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_1_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_1_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_1_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_VSC_1_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_0_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x13a8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_0_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x13a8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_0_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_0_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_0_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_0_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_0_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_0_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_0_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_0_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_0_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_0_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_0_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_0_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_0_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x13acu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_0_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x13acu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_0_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_0_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_0_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_0_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_0_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_0_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_0_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_0_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_0_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_0_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_0_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_0_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_1_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x13b0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_1_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x13b0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_1_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_1_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_1_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_1_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_1_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_1_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_1_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_1_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_1_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_1_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_1_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_1_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_1_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x13b4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_1_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x13b4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_1_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_1_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_1_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_1_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_1_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_1_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_1_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_1_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_1_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_1_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_1_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_1_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_2_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x13b8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_2_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x13b8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_2_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_2_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_2_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_2_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_2_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_2_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_2_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_2_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_2_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_2_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_2_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_2_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_2_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x13bcu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_2_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x13bcu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_2_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_2_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_2_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_2_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_2_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_2_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_2_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_2_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_2_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_2_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_2_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_2_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_3_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x13c0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_3_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x13c0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_3_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_3_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_3_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_3_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_3_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_3_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_3_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_3_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_3_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_3_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_3_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_3_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_3_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x13c4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_3_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x13c4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_3_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_3_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_3_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_3_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_3_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_3_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_3_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_3_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_3_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_3_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_3_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_LRZ_3_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_0_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x13c8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_0_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x13c8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_0_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_0_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_0_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_0_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_0_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_0_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_0_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_0_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_0_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_0_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_0_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_0_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_0_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x13ccu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_0_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x13ccu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_0_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_0_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_0_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_0_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_0_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_0_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_0_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_0_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_0_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_0_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_0_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_0_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_1_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x13d0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_1_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x13d0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_1_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_1_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_1_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_1_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_1_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_1_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_1_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_1_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_1_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_1_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_1_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_1_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_1_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x13d4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_1_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x13d4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_1_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_1_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_1_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_1_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_1_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_1_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_1_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_1_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_1_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_1_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_1_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_1_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_2_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x13d8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_2_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x13d8u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_2_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_2_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_2_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_2_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_2_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_2_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_2_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_2_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_2_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_2_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_2_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_2_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_2_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x13dcu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_2_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x13dcu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_2_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_2_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_2_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_2_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_2_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_2_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_2_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_2_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_2_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_2_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_2_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_2_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_3_LO_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x13e0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_3_LO_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x13e0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_3_LO_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_3_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_3_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_3_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_3_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_3_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_3_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_3_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_3_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_3_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_3_LO_PERFCOUNTLO_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_3_LO_PERFCOUNTLO_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_3_HI_ADDR                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x13e4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_3_HI_OFFS                                      (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x13e4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_3_HI_RMSK                                      0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_3_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_3_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_3_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_3_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_3_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_3_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_3_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_3_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_3_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_3_HI_PERFCOUNTHI_BMSK                          0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CMP_3_HI_PERFCOUNTHI_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CNTL_ADDR                                          (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1400u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CNTL_OFFS                                          (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1400u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CNTL_RMSK                                                 0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CNTL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CNTL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CNTL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CNTL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CNTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CNTL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CNTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CNTL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CNTL_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CNTL_PERFCTRSEN_BMSK                                      0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_CNTL_PERFCTRSEN_SHFT                                        0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_0_ADDR                                    (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x141cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_0_OFFS                                    (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x141cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_0_RMSK                                          0xffu
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_0_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_0_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_0_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_0_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_0_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_0_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_0_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_0_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_0_PERFSEL_BMSK                                  0xffu
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_0_PERFSEL_SHFT                                     0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_0_PERFSEL_RBBM_0_PERF_RBBM_ALWAYS_COUNT_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_0_PERFSEL_RBBM_0_PERF_RBBM_ALWAYS_ON_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_0_PERFSEL_RBBM_0_PERF_RBBM_TSE_BUSY_FVAL         0x2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_0_PERFSEL_RBBM_0_PERF_RBBM_RAS_BUSY_FVAL         0x3u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_0_PERFSEL_RBBM_0_PERF_RBBM_PC_DCALL_BUSY_FVAL        0x4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_0_PERFSEL_RBBM_0_PERF_RBBM_PC_VSD_BUSY_FVAL        0x5u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_0_PERFSEL_RBBM_0_PERF_RBBM_STATUS_MASKED_FVAL        0x6u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_0_PERFSEL_RBBM_0_PERF_RBBM_COM_BUSY_FVAL         0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_0_PERFSEL_RBBM_0_PERF_RBBM_DCOM_BUSY_FVAL        0x8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_0_PERFSEL_RBBM_0_PERF_RBBM_VBIF_BUSY_FVAL        0x9u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_0_PERFSEL_RBBM_0_PERF_RBBM_VSC_BUSY_FVAL         0xau
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_0_PERFSEL_RBBM_0_PERF_RBBM_TESS_BUSY_FVAL        0xbu
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_0_PERFSEL_RBBM_0_PERF_RBBM_UCHE_BUSY_FVAL        0xcu
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_0_PERFSEL_RBBM_0_PERF_RBBM_HLSQ_BUSY_FVAL        0xdu

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_1_ADDR                                    (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1420u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_1_OFFS                                    (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1420u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_1_RMSK                                          0xffu
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_1_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_1_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_1_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_1_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_1_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_1_PERFSEL_BMSK                                  0xffu
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_1_PERFSEL_SHFT                                     0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_1_PERFSEL_RBBM_0_PERF_RBBM_ALWAYS_COUNT_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_1_PERFSEL_RBBM_0_PERF_RBBM_ALWAYS_ON_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_1_PERFSEL_RBBM_0_PERF_RBBM_TSE_BUSY_FVAL         0x2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_1_PERFSEL_RBBM_0_PERF_RBBM_RAS_BUSY_FVAL         0x3u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_1_PERFSEL_RBBM_0_PERF_RBBM_PC_DCALL_BUSY_FVAL        0x4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_1_PERFSEL_RBBM_0_PERF_RBBM_PC_VSD_BUSY_FVAL        0x5u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_1_PERFSEL_RBBM_0_PERF_RBBM_STATUS_MASKED_FVAL        0x6u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_1_PERFSEL_RBBM_0_PERF_RBBM_COM_BUSY_FVAL         0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_1_PERFSEL_RBBM_0_PERF_RBBM_DCOM_BUSY_FVAL        0x8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_1_PERFSEL_RBBM_0_PERF_RBBM_VBIF_BUSY_FVAL        0x9u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_1_PERFSEL_RBBM_0_PERF_RBBM_VSC_BUSY_FVAL         0xau
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_1_PERFSEL_RBBM_0_PERF_RBBM_TESS_BUSY_FVAL        0xbu
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_1_PERFSEL_RBBM_0_PERF_RBBM_UCHE_BUSY_FVAL        0xcu
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_1_PERFSEL_RBBM_0_PERF_RBBM_HLSQ_BUSY_FVAL        0xdu

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_2_ADDR                                    (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1424u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_2_OFFS                                    (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1424u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_2_RMSK                                          0xffu
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_2_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_2_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_2_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_2_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_2_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_2_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_2_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_2_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_2_PERFSEL_BMSK                                  0xffu
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_2_PERFSEL_SHFT                                     0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_2_PERFSEL_RBBM_0_PERF_RBBM_ALWAYS_COUNT_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_2_PERFSEL_RBBM_0_PERF_RBBM_ALWAYS_ON_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_2_PERFSEL_RBBM_0_PERF_RBBM_TSE_BUSY_FVAL         0x2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_2_PERFSEL_RBBM_0_PERF_RBBM_RAS_BUSY_FVAL         0x3u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_2_PERFSEL_RBBM_0_PERF_RBBM_PC_DCALL_BUSY_FVAL        0x4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_2_PERFSEL_RBBM_0_PERF_RBBM_PC_VSD_BUSY_FVAL        0x5u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_2_PERFSEL_RBBM_0_PERF_RBBM_STATUS_MASKED_FVAL        0x6u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_2_PERFSEL_RBBM_0_PERF_RBBM_COM_BUSY_FVAL         0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_2_PERFSEL_RBBM_0_PERF_RBBM_DCOM_BUSY_FVAL        0x8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_2_PERFSEL_RBBM_0_PERF_RBBM_VBIF_BUSY_FVAL        0x9u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_2_PERFSEL_RBBM_0_PERF_RBBM_VSC_BUSY_FVAL         0xau
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_2_PERFSEL_RBBM_0_PERF_RBBM_TESS_BUSY_FVAL        0xbu
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_2_PERFSEL_RBBM_0_PERF_RBBM_UCHE_BUSY_FVAL        0xcu
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_2_PERFSEL_RBBM_0_PERF_RBBM_HLSQ_BUSY_FVAL        0xdu

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_3_ADDR                                    (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1428u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_3_OFFS                                    (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1428u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_3_RMSK                                          0xffu
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_3_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_3_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_3_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_3_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_3_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_3_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_3_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_3_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_3_PERFSEL_BMSK                                  0xffu
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_3_PERFSEL_SHFT                                     0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_3_PERFSEL_RBBM_0_PERF_RBBM_ALWAYS_COUNT_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_3_PERFSEL_RBBM_0_PERF_RBBM_ALWAYS_ON_FVAL        0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_3_PERFSEL_RBBM_0_PERF_RBBM_TSE_BUSY_FVAL         0x2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_3_PERFSEL_RBBM_0_PERF_RBBM_RAS_BUSY_FVAL         0x3u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_3_PERFSEL_RBBM_0_PERF_RBBM_PC_DCALL_BUSY_FVAL        0x4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_3_PERFSEL_RBBM_0_PERF_RBBM_PC_VSD_BUSY_FVAL        0x5u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_3_PERFSEL_RBBM_0_PERF_RBBM_STATUS_MASKED_FVAL        0x6u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_3_PERFSEL_RBBM_0_PERF_RBBM_COM_BUSY_FVAL         0x7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_3_PERFSEL_RBBM_0_PERF_RBBM_DCOM_BUSY_FVAL        0x8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_3_PERFSEL_RBBM_0_PERF_RBBM_VBIF_BUSY_FVAL        0x9u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_3_PERFSEL_RBBM_0_PERF_RBBM_VSC_BUSY_FVAL         0xau
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_3_PERFSEL_RBBM_0_PERF_RBBM_TESS_BUSY_FVAL        0xbu
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_3_PERFSEL_RBBM_0_PERF_RBBM_UCHE_BUSY_FVAL        0xcu
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_RBBM_SEL_3_PERFSEL_RBBM_0_PERF_RBBM_HLSQ_BUSY_FVAL        0xdu

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_ADDR                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x142cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_OFFS                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x142cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_RMSK                                 0x2f7ffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_A2DBUSY_BMSK                         0x200000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_A2DBUSY_SHFT                               21u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_CCUFCHEBUSY_BMSK                      0x80000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_CCUFCHEBUSY_SHFT                           19u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_DCOMBUSY_BMSK                         0x40000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_DCOMBUSY_SHFT                              18u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_COMBUSY_BMSK                          0x20000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_COMBUSY_SHFT                               17u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_HLSQBUSY_BMSK                         0x10000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_HLSQBUSY_SHFT                              16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_VSCBUSY_BMSK                           0x4000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_VSCBUSY_SHFT                               14u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_LRZBUSY_BMSK                           0x2000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_LRZBUSY_SHFT                               13u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_TPL1BUSY_BMSK                          0x1000u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_TPL1BUSY_SHFT                              12u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_SPBUSY_BMSK                             0x800u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_SPBUSY_SHFT                                11u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_UCHEBUSY_BMSK                           0x400u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_UCHEBUSY_SHFT                              10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_VPCBUSY_BMSK                            0x200u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_VPCBUSY_SHFT                                9u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_VFDVFDPBUSY_BMSK                        0x100u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_VFDVFDPBUSY_SHFT                            8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_TESSBUSY_BMSK                            0x80u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_TESSBUSY_SHFT                               7u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_PCVSDBUSY_BMSK                           0x40u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_PCVSDBUSY_SHFT                              6u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_PCDCALLBUSY_BMSK                         0x20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_PCDCALLBUSY_SHFT                            5u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_RBBUSY_BMSK                              0x10u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_RBBUSY_SHFT                                 4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_RASBUSY_BMSK                              0x8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_RASBUSY_SHFT                                3u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_TSEBUSY_BMSK                              0x4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_TSEBUSY_SHFT                                2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_VBIFBUSY_BMSK                             0x2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_VBIFBUSY_SHFT                               1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_CPNRTBUSY_BMSK                            0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_GPU_BUSY_MASKED_CPNRTBUSY_SHFT                              0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SRAM_INIT_CMD_ADDR                                 (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1438u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SRAM_INIT_CMD_OFFS                                 (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1438u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SRAM_INIT_CMD_RMSK                                        0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SRAM_INIT_CMD_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SRAM_INIT_CMD_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SRAM_INIT_CMD_INITIALPERFCOUNTERSRAM_BMSK                 0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SRAM_INIT_CMD_INITIALPERFCOUNTERSRAM_SHFT                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SRAM_INIT_STATUS_ADDR                              (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x143cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SRAM_INIT_STATUS_OFFS                              (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x143cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SRAM_INIT_STATUS_RMSK                                   0xff3u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SRAM_INIT_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SRAM_INIT_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SRAM_INIT_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SRAM_INIT_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SRAM_INIT_STATUS_SRAMADDRESS_BMSK                       0xff0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SRAM_INIT_STATUS_SRAMADDRESS_SHFT                           4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SRAM_INIT_STATUS_CMDRECEIVED_BMSK                         0x2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SRAM_INIT_STATUS_CMDRECEIVED_SHFT                           1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SRAM_INIT_STATUS_STATUS_BMSK                              0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_PERFCTR_SRAM_INIT_STATUS_STATUS_SHFT                                0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_POWER_COLLAPSE_CNTL_ADDR                                   (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1440u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_POWER_COLLAPSE_CNTL_OFFS                                   (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1440u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_POWER_COLLAPSE_CNTL_RMSK                                          0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_POWER_COLLAPSE_CNTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_POWER_COLLAPSE_CNTL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_POWER_COLLAPSE_CNTL_INITIALPERFCOUNTERSTORE_BMSK                  0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_POWER_COLLAPSE_CNTL_INITIALPERFCOUNTERSTORE_SHFT                    0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_POWER_COLLAPSE_STATUS_ADDR                                 (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1444u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_POWER_COLLAPSE_STATUS_OFFS                                 (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1444u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_POWER_COLLAPSE_STATUS_RMSK                                 0xfffffff3ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_POWER_COLLAPSE_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_POWER_COLLAPSE_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_POWER_COLLAPSE_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_POWER_COLLAPSE_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_POWER_COLLAPSE_STATUS_FORHW_BMSK                           0xffff0000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_POWER_COLLAPSE_STATUS_FORHW_SHFT                                   16u
#define HWIO_SAIL_TO_MD_GPU_RBBM_POWER_COLLAPSE_STATUS_COUNTERADDRESS_BMSK                      0xff00u
#define HWIO_SAIL_TO_MD_GPU_RBBM_POWER_COLLAPSE_STATUS_COUNTERADDRESS_SHFT                           8u
#define HWIO_SAIL_TO_MD_GPU_RBBM_POWER_COLLAPSE_STATUS_STATUS_BMSK                                0xf0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_POWER_COLLAPSE_STATUS_STATUS_SHFT                                   4u
#define HWIO_SAIL_TO_MD_GPU_RBBM_POWER_COLLAPSE_STATUS_GMUREQRECEIVED_BMSK                         0x2u
#define HWIO_SAIL_TO_MD_GPU_RBBM_POWER_COLLAPSE_STATUS_GMUREQRECEIVED_SHFT                           1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_POWER_COLLAPSE_STATUS_ACK_BMSK                                    0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_POWER_COLLAPSE_STATUS_ACK_SHFT                                      0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_ISDB_CNT_ADDR                                              (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x14ccu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_ISDB_CNT_OFFS                                              (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x14ccu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_ISDB_CNT_RMSK                                                0x110000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_ISDB_CNT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_ISDB_CNT_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_ISDB_CNT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_ISDB_CNT_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_ISDB_CNT_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_ISDB_CNT_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_ISDB_CNT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_ISDB_CNT_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_ISDB_CNT_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_ISDB_CNT_HANGCNTRSTBYSMMUDIS_BMSK                            0x100000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_ISDB_CNT_HANGCNTRSTBYSMMUDIS_SHFT                                  20u
#define HWIO_SAIL_TO_MD_GPU_RBBM_ISDB_CNT_HANGCNTRSTBYISDBDIS_BMSK                             0x10000ul
#define HWIO_SAIL_TO_MD_GPU_RBBM_ISDB_CNT_HANGCNTRSTBYISDBDIS_SHFT                                  16u

#define HWIO_SAIL_TO_MD_GPU_RBBM_NC_MODE_CNTL_ADDR                                          (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x14d0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_NC_MODE_CNTL_OFFS                                          (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x14d0u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_NC_MODE_CNTL_RMSK                                                 0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_NC_MODE_CNTL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_NC_MODE_CNTL_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_NC_MODE_CNTL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_NC_MODE_CNTL_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_NC_MODE_CNTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_NC_MODE_CNTL_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_NC_MODE_CNTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_NC_MODE_CNTL_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_NC_MODE_CNTL_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_NC_MODE_CNTL_MACROTILINGMODE_BMSK                                 0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_NC_MODE_CNTL_MACROTILINGMODE_SHFT                                   0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_NC_MODE_CNTL_MACROTILINGMODE_RBBM_0_MACROTILINGMODE4CHANNELS_FVAL        0x0u
#define HWIO_SAIL_TO_MD_GPU_RBBM_NC_MODE_CNTL_MACROTILINGMODE_RBBM_0_MACROTILINGMODE8CHANNELS_FVAL        0x1u

#define HWIO_SAIL_TO_MD_GPU_RBBM_SNAPSHOT_STATUS_ADDR                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x14d4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_SNAPSHOT_STATUS_OFFS                                       (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x14d4u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_SNAPSHOT_STATUS_RMSK                                              0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_SNAPSHOT_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_SNAPSHOT_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_SNAPSHOT_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_SNAPSHOT_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_SNAPSHOT_STATUS_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_SNAPSHOT_STATUS_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_SNAPSHOT_STATUS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_SNAPSHOT_STATUS_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_SNAPSHOT_STATUS_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_SNAPSHOT_STATUS_STATICSTATUS_BMSK                                 0x1u
#define HWIO_SAIL_TO_MD_GPU_RBBM_SNAPSHOT_STATUS_STATICSTATUS_SHFT                                   0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAVERTICES_LO_ADDR                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1500u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAVERTICES_LO_OFFS                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1500u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAVERTICES_LO_RMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAVERTICES_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAVERTICES_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAVERTICES_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAVERTICES_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAVERTICES_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAVERTICES_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAVERTICES_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAVERTICES_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAVERTICES_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAVERTICES_LO_PIPESTATCOUNT_BMSK                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAVERTICES_LO_PIPESTATCOUNT_SHFT                           0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAVERTICES_HI_ADDR                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1504u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAVERTICES_HI_OFFS                                (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1504u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAVERTICES_HI_RMSK                                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAVERTICES_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAVERTICES_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAVERTICES_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAVERTICES_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAVERTICES_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAVERTICES_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAVERTICES_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAVERTICES_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAVERTICES_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAVERTICES_HI_PIPESTATCOUNT_BMSK                  0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAVERTICES_HI_PIPESTATCOUNT_SHFT                           0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAPRIMITIVES_LO_ADDR                              (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1508u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAPRIMITIVES_LO_OFFS                              (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1508u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAPRIMITIVES_LO_RMSK                              0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAPRIMITIVES_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAPRIMITIVES_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAPRIMITIVES_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAPRIMITIVES_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAPRIMITIVES_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAPRIMITIVES_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAPRIMITIVES_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAPRIMITIVES_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAPRIMITIVES_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAPRIMITIVES_LO_PIPESTATCOUNT_BMSK                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAPRIMITIVES_LO_PIPESTATCOUNT_SHFT                         0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAPRIMITIVES_HI_ADDR                              (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x150cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAPRIMITIVES_HI_OFFS                              (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x150cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAPRIMITIVES_HI_RMSK                              0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAPRIMITIVES_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAPRIMITIVES_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAPRIMITIVES_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAPRIMITIVES_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAPRIMITIVES_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAPRIMITIVES_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAPRIMITIVES_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAPRIMITIVES_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAPRIMITIVES_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAPRIMITIVES_HI_PIPESTATCOUNT_BMSK                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_IAPRIMITIVES_HI_PIPESTATCOUNT_SHFT                         0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_VSINVOCATIONS_LO_ADDR                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1510u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_VSINVOCATIONS_LO_OFFS                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1510u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_VSINVOCATIONS_LO_RMSK                             0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_VSINVOCATIONS_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_VSINVOCATIONS_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_VSINVOCATIONS_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_VSINVOCATIONS_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_VSINVOCATIONS_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_VSINVOCATIONS_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_VSINVOCATIONS_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_VSINVOCATIONS_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_VSINVOCATIONS_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_VSINVOCATIONS_LO_PIPESTATCOUNT_BMSK               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_VSINVOCATIONS_LO_PIPESTATCOUNT_SHFT                        0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_VSINVOCATIONS_HI_ADDR                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1514u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_VSINVOCATIONS_HI_OFFS                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1514u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_VSINVOCATIONS_HI_RMSK                             0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_VSINVOCATIONS_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_VSINVOCATIONS_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_VSINVOCATIONS_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_VSINVOCATIONS_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_VSINVOCATIONS_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_VSINVOCATIONS_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_VSINVOCATIONS_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_VSINVOCATIONS_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_VSINVOCATIONS_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_VSINVOCATIONS_HI_PIPESTATCOUNT_BMSK               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_VSINVOCATIONS_HI_PIPESTATCOUNT_SHFT                        0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_HSINVOCATIONS_LO_ADDR                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1518u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_HSINVOCATIONS_LO_OFFS                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1518u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_HSINVOCATIONS_LO_RMSK                             0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_HSINVOCATIONS_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_HSINVOCATIONS_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_HSINVOCATIONS_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_HSINVOCATIONS_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_HSINVOCATIONS_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_HSINVOCATIONS_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_HSINVOCATIONS_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_HSINVOCATIONS_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_HSINVOCATIONS_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_HSINVOCATIONS_LO_PIPESTATCOUNT_BMSK               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_HSINVOCATIONS_LO_PIPESTATCOUNT_SHFT                        0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_HSINVOCATIONS_HI_ADDR                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x151cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_HSINVOCATIONS_HI_OFFS                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x151cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_HSINVOCATIONS_HI_RMSK                             0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_HSINVOCATIONS_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_HSINVOCATIONS_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_HSINVOCATIONS_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_HSINVOCATIONS_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_HSINVOCATIONS_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_HSINVOCATIONS_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_HSINVOCATIONS_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_HSINVOCATIONS_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_HSINVOCATIONS_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_HSINVOCATIONS_HI_PIPESTATCOUNT_BMSK               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_HSINVOCATIONS_HI_PIPESTATCOUNT_SHFT                        0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_DSINVOCATIONS_LO_ADDR                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1520u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_DSINVOCATIONS_LO_OFFS                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1520u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_DSINVOCATIONS_LO_RMSK                             0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_DSINVOCATIONS_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_DSINVOCATIONS_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_DSINVOCATIONS_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_DSINVOCATIONS_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_DSINVOCATIONS_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_DSINVOCATIONS_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_DSINVOCATIONS_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_DSINVOCATIONS_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_DSINVOCATIONS_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_DSINVOCATIONS_LO_PIPESTATCOUNT_BMSK               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_DSINVOCATIONS_LO_PIPESTATCOUNT_SHFT                        0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_DSINVOCATIONS_HI_ADDR                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1524u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_DSINVOCATIONS_HI_OFFS                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1524u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_DSINVOCATIONS_HI_RMSK                             0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_DSINVOCATIONS_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_DSINVOCATIONS_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_DSINVOCATIONS_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_DSINVOCATIONS_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_DSINVOCATIONS_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_DSINVOCATIONS_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_DSINVOCATIONS_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_DSINVOCATIONS_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_DSINVOCATIONS_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_DSINVOCATIONS_HI_PIPESTATCOUNT_BMSK               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_DSINVOCATIONS_HI_PIPESTATCOUNT_SHFT                        0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSINVOCATIONS_LO_ADDR                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1528u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSINVOCATIONS_LO_OFFS                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1528u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSINVOCATIONS_LO_RMSK                             0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSINVOCATIONS_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSINVOCATIONS_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSINVOCATIONS_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSINVOCATIONS_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSINVOCATIONS_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSINVOCATIONS_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSINVOCATIONS_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSINVOCATIONS_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSINVOCATIONS_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSINVOCATIONS_LO_PIPESTATCOUNT_BMSK               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSINVOCATIONS_LO_PIPESTATCOUNT_SHFT                        0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSINVOCATIONS_HI_ADDR                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x152cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSINVOCATIONS_HI_OFFS                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x152cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSINVOCATIONS_HI_RMSK                             0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSINVOCATIONS_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSINVOCATIONS_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSINVOCATIONS_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSINVOCATIONS_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSINVOCATIONS_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSINVOCATIONS_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSINVOCATIONS_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSINVOCATIONS_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSINVOCATIONS_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSINVOCATIONS_HI_PIPESTATCOUNT_BMSK               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSINVOCATIONS_HI_PIPESTATCOUNT_SHFT                        0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSPRIMITIVES_LO_ADDR                              (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1530u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSPRIMITIVES_LO_OFFS                              (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1530u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSPRIMITIVES_LO_RMSK                              0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSPRIMITIVES_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSPRIMITIVES_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSPRIMITIVES_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSPRIMITIVES_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSPRIMITIVES_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSPRIMITIVES_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSPRIMITIVES_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSPRIMITIVES_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSPRIMITIVES_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSPRIMITIVES_LO_PIPESTATCOUNT_BMSK                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSPRIMITIVES_LO_PIPESTATCOUNT_SHFT                         0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSPRIMITIVES_HI_ADDR                              (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1534u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSPRIMITIVES_HI_OFFS                              (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1534u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSPRIMITIVES_HI_RMSK                              0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSPRIMITIVES_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSPRIMITIVES_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSPRIMITIVES_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSPRIMITIVES_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSPRIMITIVES_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSPRIMITIVES_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSPRIMITIVES_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSPRIMITIVES_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSPRIMITIVES_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSPRIMITIVES_HI_PIPESTATCOUNT_BMSK                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_GSPRIMITIVES_HI_PIPESTATCOUNT_SHFT                         0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CINVOCATIONS_LO_ADDR                              (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1538u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CINVOCATIONS_LO_OFFS                              (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1538u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CINVOCATIONS_LO_RMSK                              0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CINVOCATIONS_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CINVOCATIONS_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CINVOCATIONS_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CINVOCATIONS_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CINVOCATIONS_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CINVOCATIONS_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CINVOCATIONS_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CINVOCATIONS_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CINVOCATIONS_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CINVOCATIONS_LO_PIPESTATCOUNT_BMSK                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CINVOCATIONS_LO_PIPESTATCOUNT_SHFT                         0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CINVOCATIONS_HI_ADDR                              (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x153cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CINVOCATIONS_HI_OFFS                              (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x153cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CINVOCATIONS_HI_RMSK                              0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CINVOCATIONS_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CINVOCATIONS_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CINVOCATIONS_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CINVOCATIONS_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CINVOCATIONS_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CINVOCATIONS_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CINVOCATIONS_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CINVOCATIONS_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CINVOCATIONS_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CINVOCATIONS_HI_PIPESTATCOUNT_BMSK                0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CINVOCATIONS_HI_PIPESTATCOUNT_SHFT                         0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CPRIMITIVES_LO_ADDR                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1540u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CPRIMITIVES_LO_OFFS                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1540u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CPRIMITIVES_LO_RMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CPRIMITIVES_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CPRIMITIVES_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CPRIMITIVES_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CPRIMITIVES_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CPRIMITIVES_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CPRIMITIVES_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CPRIMITIVES_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CPRIMITIVES_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CPRIMITIVES_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CPRIMITIVES_LO_PIPESTATCOUNT_BMSK                 0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CPRIMITIVES_LO_PIPESTATCOUNT_SHFT                          0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CPRIMITIVES_HI_ADDR                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1544u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CPRIMITIVES_HI_OFFS                               (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1544u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CPRIMITIVES_HI_RMSK                               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CPRIMITIVES_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CPRIMITIVES_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CPRIMITIVES_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CPRIMITIVES_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CPRIMITIVES_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CPRIMITIVES_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CPRIMITIVES_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CPRIMITIVES_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CPRIMITIVES_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CPRIMITIVES_HI_PIPESTATCOUNT_BMSK                 0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CPRIMITIVES_HI_PIPESTATCOUNT_SHFT                          0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_PSINVOCATIONS_LO_ADDR                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1548u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_PSINVOCATIONS_LO_OFFS                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1548u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_PSINVOCATIONS_LO_RMSK                             0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_PSINVOCATIONS_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_PSINVOCATIONS_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_PSINVOCATIONS_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_PSINVOCATIONS_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_PSINVOCATIONS_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_PSINVOCATIONS_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_PSINVOCATIONS_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_PSINVOCATIONS_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_PSINVOCATIONS_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_PSINVOCATIONS_LO_PIPESTATCOUNT_BMSK               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_PSINVOCATIONS_LO_PIPESTATCOUNT_SHFT                        0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_PSINVOCATIONS_HI_ADDR                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x154cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_PSINVOCATIONS_HI_OFFS                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x154cu)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_PSINVOCATIONS_HI_RMSK                             0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_PSINVOCATIONS_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_PSINVOCATIONS_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_PSINVOCATIONS_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_PSINVOCATIONS_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_PSINVOCATIONS_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_PSINVOCATIONS_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_PSINVOCATIONS_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_PSINVOCATIONS_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_PSINVOCATIONS_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_PSINVOCATIONS_HI_PIPESTATCOUNT_BMSK               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_PSINVOCATIONS_HI_PIPESTATCOUNT_SHFT                        0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CSINVOCATIONS_LO_ADDR                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1550u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CSINVOCATIONS_LO_OFFS                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1550u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CSINVOCATIONS_LO_RMSK                             0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CSINVOCATIONS_LO_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CSINVOCATIONS_LO_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CSINVOCATIONS_LO_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CSINVOCATIONS_LO_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CSINVOCATIONS_LO_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CSINVOCATIONS_LO_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CSINVOCATIONS_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CSINVOCATIONS_LO_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CSINVOCATIONS_LO_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CSINVOCATIONS_LO_PIPESTATCOUNT_BMSK               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CSINVOCATIONS_LO_PIPESTATCOUNT_SHFT                        0u

#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CSINVOCATIONS_HI_ADDR                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE      + 0x1554u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CSINVOCATIONS_HI_OFFS                             (SAIL_TO_MD_GPU_RBBM_BLK_DEC0_REG_BASE_OFFS + 0x1554u)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CSINVOCATIONS_HI_RMSK                             0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CSINVOCATIONS_HI_IN                    \
                in_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CSINVOCATIONS_HI_ADDR)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CSINVOCATIONS_HI_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CSINVOCATIONS_HI_ADDR, m)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CSINVOCATIONS_HI_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CSINVOCATIONS_HI_ADDR,v)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CSINVOCATIONS_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CSINVOCATIONS_HI_ADDR,m,v,HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CSINVOCATIONS_HI_IN)
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CSINVOCATIONS_HI_PIPESTATCOUNT_BMSK               0xfffffffful
#define HWIO_SAIL_TO_MD_GPU_RBBM_PIPESTAT_CSINVOCATIONS_HI_PIPESTATCOUNT_SHFT                        0u


#endif /* __G_SAIL_TO_MD_GPU_RBBM_HWIO_H__ */
