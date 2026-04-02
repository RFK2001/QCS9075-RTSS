#ifndef __G_SAIL_TO_MD_VIDEO_CC_HWIO_H__
#define __G_SAIL_TO_MD_VIDEO_CC_HWIO_H__
/*
===========================================================================
*/
/**
    @file g_SAIL_TO_MD_VIDEO_CC_HWIO.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        SA8775P (LeMansAU) [lemansau_v1.0_p3q2r72_BTO]
 
    This file contains HWIO register definitions for the following modules:
        SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG


    Generation parameters: 
    { 'filename': 'g_SAIL_TO_MD_VIDEO_CC_HWIO.h',
      'integer-qualifiers': True,
      'modules': ['SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG'],
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

    $Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/bist/inc/common_inc/g_SAIL_TO_MD_VIDEO_CC_HWIO.h#1 $
    $DateTime: 2025/02/01 11:39:23 $
    $Author: smarru $

    ===========================================================================
*/

/*----------------------------------------------------------------------------
 * MODULE: SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG
 *--------------------------------------------------------------------------*/

#define SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE                                           (SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE      + 0x0abf8000ul)
#define SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_SIZE                                      0x8000u
#define SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_USED                                      0x3000u
#define SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS                                      0x0abf8000ul

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CMD_RCGR_ADDR                                                  (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x0u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CMD_RCGR_OFFS                                                  (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x0u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CMD_RCGR_RMSK                                                  0x80000013ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CMD_RCGR_ROOT_OFF_BMSK                                         0x80000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CMD_RCGR_ROOT_OFF_SHFT                                                 31u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                         0x10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                            4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CMD_RCGR_ROOT_EN_BMSK                                                 0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CMD_RCGR_ROOT_EN_SHFT                                                   1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                          0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CMD_RCGR_UPDATE_BMSK                                                  0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CMD_RCGR_UPDATE_SHFT                                                    0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CMD_RCGR_UPDATE_DISABLE_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CMD_RCGR_UPDATE_ENABLE_FVAL                                           0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_ADDR                                                  (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x4u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_OFFS                                                  (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x4u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_RMSK                                                    0x11071ful
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_HW_CLK_CONTROL_BMSK                                     0x100000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_HW_CLK_CONTROL_SHFT                                           20u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                   0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_RCGLITE_DISABLE_BMSK                                     0x10000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_RCGLITE_DISABLE_SHFT                                          16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                         0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                        0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_SEL_BMSK                                               0x700u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_SEL_SHFT                                                   8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_SEL_SRC0_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_SEL_SRC1_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_SEL_SRC2_FVAL                                            0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_SEL_SRC3_FVAL                                            0x3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_SEL_SRC4_FVAL                                            0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_SEL_SRC5_FVAL                                            0x5u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_SEL_SRC6_FVAL                                            0x6u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_SEL_SRC7_FVAL                                            0x7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_BMSK                                                0x1fu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_SHFT                                                   0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_DIV1_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                          0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_DIV2_FVAL                                            0x3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                          0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_DIV3_FVAL                                            0x5u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                          0x6u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_DIV4_FVAL                                            0x7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                          0x8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_DIV5_FVAL                                            0x9u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                          0xau
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_DIV6_FVAL                                            0xbu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                          0xcu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_DIV7_FVAL                                            0xdu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                          0xeu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_DIV8_FVAL                                            0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                         0x10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_DIV9_FVAL                                           0x11u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                         0x12u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_DIV10_FVAL                                          0x13u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                        0x14u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_DIV11_FVAL                                          0x15u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                        0x16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_DIV12_FVAL                                          0x17u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                        0x18u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_DIV13_FVAL                                          0x19u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                        0x1au
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_DIV14_FVAL                                          0x1bu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                        0x1cu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_DIV15_FVAL                                          0x1du
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                        0x1eu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_RCGR_SRC_DIV_DIV16_FVAL                                          0x1fu

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CMD_RCGR_ADDR                                                  (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x18u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CMD_RCGR_OFFS                                                  (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x18u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CMD_RCGR_RMSK                                                  0x80000013ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CMD_RCGR_ROOT_OFF_BMSK                                         0x80000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CMD_RCGR_ROOT_OFF_SHFT                                                 31u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                         0x10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                            4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CMD_RCGR_ROOT_EN_BMSK                                                 0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CMD_RCGR_ROOT_EN_SHFT                                                   1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                          0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CMD_RCGR_UPDATE_BMSK                                                  0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CMD_RCGR_UPDATE_SHFT                                                    0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CMD_RCGR_UPDATE_DISABLE_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CMD_RCGR_UPDATE_ENABLE_FVAL                                           0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_ADDR                                                  (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x1cu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_OFFS                                                  (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x1cu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_RMSK                                                    0x11071ful
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_HW_CLK_CONTROL_BMSK                                     0x100000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_HW_CLK_CONTROL_SHFT                                           20u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                   0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_RCGLITE_DISABLE_BMSK                                     0x10000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_RCGLITE_DISABLE_SHFT                                          16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                         0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                        0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_SEL_BMSK                                               0x700u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_SEL_SHFT                                                   8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_SEL_SRC0_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_SEL_SRC1_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_SEL_SRC2_FVAL                                            0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_SEL_SRC3_FVAL                                            0x3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_SEL_SRC4_FVAL                                            0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_SEL_SRC5_FVAL                                            0x5u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_SEL_SRC6_FVAL                                            0x6u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_SEL_SRC7_FVAL                                            0x7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_BMSK                                                0x1fu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_SHFT                                                   0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_DIV1_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                          0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_DIV2_FVAL                                            0x3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                          0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_DIV3_FVAL                                            0x5u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                          0x6u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_DIV4_FVAL                                            0x7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                          0x8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_DIV5_FVAL                                            0x9u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                          0xau
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_DIV6_FVAL                                            0xbu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                          0xcu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_DIV7_FVAL                                            0xdu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                          0xeu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_DIV8_FVAL                                            0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                         0x10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_DIV9_FVAL                                           0x11u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                         0x12u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_DIV10_FVAL                                          0x13u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                        0x14u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_DIV11_FVAL                                          0x15u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                        0x16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_DIV12_FVAL                                          0x17u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                        0x18u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_DIV13_FVAL                                          0x19u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                        0x1au
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_DIV14_FVAL                                          0x1bu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                        0x1cu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_DIV15_FVAL                                          0x1du
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                        0x1eu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_RCGR_SRC_DIV_DIV16_FVAL                                          0x1fu

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CMD_RCGR_ADDR                                                   (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x30u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CMD_RCGR_OFFS                                                   (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x30u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CMD_RCGR_RMSK                                                   0x80000013ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CMD_RCGR_ROOT_OFF_BMSK                                          0x80000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CMD_RCGR_ROOT_OFF_SHFT                                                  31u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                          0x10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                             4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CMD_RCGR_ROOT_EN_BMSK                                                  0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CMD_RCGR_ROOT_EN_SHFT                                                    1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CMD_RCGR_UPDATE_BMSK                                                   0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CMD_RCGR_UPDATE_SHFT                                                     0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CMD_RCGR_UPDATE_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CMD_RCGR_UPDATE_ENABLE_FVAL                                            0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_ADDR                                                   (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x34u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_OFFS                                                   (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x34u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_RMSK                                                     0x11071ful
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_HW_CLK_CONTROL_BMSK                                      0x100000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_HW_CLK_CONTROL_SHFT                                            20u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                    0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_RCGLITE_DISABLE_BMSK                                      0x10000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_RCGLITE_DISABLE_SHFT                                           16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                          0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                         0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_SEL_BMSK                                                0x700u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_SEL_SHFT                                                    8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_SEL_SRC0_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_SEL_SRC1_FVAL                                             0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_SEL_SRC2_FVAL                                             0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_SEL_SRC3_FVAL                                             0x3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_SEL_SRC4_FVAL                                             0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_SEL_SRC5_FVAL                                             0x5u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_SEL_SRC6_FVAL                                             0x6u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_SEL_SRC7_FVAL                                             0x7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_BMSK                                                 0x1fu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_SHFT                                                    0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_DIV1_FVAL                                             0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                           0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_DIV2_FVAL                                             0x3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                           0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_DIV3_FVAL                                             0x5u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                           0x6u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_DIV4_FVAL                                             0x7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                           0x8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_DIV5_FVAL                                             0x9u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                           0xau
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_DIV6_FVAL                                             0xbu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                           0xcu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_DIV7_FVAL                                             0xdu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                           0xeu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_DIV8_FVAL                                             0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                          0x10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_DIV9_FVAL                                            0x11u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                          0x12u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_DIV10_FVAL                                           0x13u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                         0x14u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_DIV11_FVAL                                           0x15u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                         0x16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_DIV12_FVAL                                           0x17u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                         0x18u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_DIV13_FVAL                                           0x19u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                         0x1au
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_DIV14_FVAL                                           0x1bu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                         0x1cu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_DIV15_FVAL                                           0x1du
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                         0x1eu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CFG_RCGR_SRC_DIV_DIV16_FVAL                                           0x1fu

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_BCR_ADDR                                                      (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x48u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_BCR_OFFS                                                      (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x48u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_BCR_RMSK                                                             0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_BCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_BCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_BCR_BLK_ARES_BMSK                                                    0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_BCR_BLK_ARES_SHFT                                                      0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_BCR_BLK_ARES_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_BCR_BLK_ARES_ENABLE_FVAL                                             0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_ADDR                                                    (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x4cu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_OFFS                                                    (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x4cu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_RMSK                                                    0xf8fffffful
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_PWR_ON_BMSK                                             0x80000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_PWR_ON_SHFT                                                     31u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_GDSC_STATE_BMSK                                         0x78000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_GDSC_STATE_SHFT                                                 27u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_EN_REST_WAIT_BMSK                                         0xf00000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_EN_REST_WAIT_SHFT                                               20u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_EN_FEW_WAIT_BMSK                                           0xf0000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_EN_FEW_WAIT_SHFT                                                16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_CLK_DIS_WAIT_BMSK                                           0xf000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_CLK_DIS_WAIT_SHFT                                               12u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_RETAIN_FF_ENABLE_BMSK                                        0x800u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_RETAIN_FF_ENABLE_SHFT                                           11u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_RETAIN_FF_ENABLE_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_RETAIN_FF_ENABLE_ENABLE_FVAL                                   0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_RESTORE_BMSK                                                 0x400u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_RESTORE_SHFT                                                    10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_RESTORE_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_RESTORE_ENABLE_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_SAVE_BMSK                                                    0x200u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_SAVE_SHFT                                                        9u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_SAVE_DISABLE_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_SAVE_ENABLE_FVAL                                               0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_RETAIN_BMSK                                                  0x100u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_RETAIN_SHFT                                                      8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_RETAIN_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_RETAIN_ENABLE_FVAL                                             0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_EN_REST_BMSK                                                  0x80u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_EN_REST_SHFT                                                     7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_EN_REST_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_EN_REST_ENABLE_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_EN_FEW_BMSK                                                   0x40u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_EN_FEW_SHFT                                                      6u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_EN_FEW_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_EN_FEW_ENABLE_FVAL                                             0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_CLAMP_IO_BMSK                                                 0x20u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_CLAMP_IO_SHFT                                                    5u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_CLAMP_IO_DISABLE_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_CLAMP_IO_ENABLE_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_CLK_DISABLE_BMSK                                              0x10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_CLK_DISABLE_SHFT                                                 4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_CLK_DISABLE_CLK_NOT_DISABLE_FVAL                               0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_CLK_DISABLE_CLK_IS_DISABLE_FVAL                                0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_PD_ARES_BMSK                                                   0x8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_PD_ARES_SHFT                                                     3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_PD_ARES_NO_RESET_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_PD_ARES_RESET_FVAL                                             0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_SW_OVERRIDE_BMSK                                               0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_SW_OVERRIDE_SHFT                                                 2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_SW_OVERRIDE_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_SW_OVERRIDE_ENABLE_FVAL                                        0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_HW_CONTROL_BMSK                                                0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_HW_CONTROL_SHFT                                                  1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_HW_CONTROL_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_HW_CONTROL_ENABLE_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_SW_COLLAPSE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_SW_COLLAPSE_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_SW_COLLAPSE_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_GDSCR_SW_COLLAPSE_ENABLE_FVAL                                        0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_ADDR                                                (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x50u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_OFFS                                                (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x50u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_RMSK                                                 0x3fffffful
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_GDSC_PWR_DWN_START_BMSK                              0x2000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_GDSC_PWR_DWN_START_SHFT                                     25u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_GDSC_PWR_UP_START_BMSK                               0x1000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_GDSC_PWR_UP_START_SHFT                                      24u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_GDSC_CFG_FSM_STATE_STATUS_BMSK                        0xf00000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_GDSC_CFG_FSM_STATE_STATUS_SHFT                              20u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_GDSC_MEM_PWR_ACK_STATUS_BMSK                           0x80000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_GDSC_MEM_PWR_ACK_STATUS_SHFT                                19u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_GDSC_ENR_ACK_STATUS_BMSK                               0x40000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_GDSC_ENR_ACK_STATUS_SHFT                                    18u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_GDSC_ENF_ACK_STATUS_BMSK                               0x20000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_GDSC_ENF_ACK_STATUS_SHFT                                    17u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_GDSC_POWER_UP_COMPLETE_BMSK                            0x10000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_GDSC_POWER_UP_COMPLETE_SHFT                                 16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_GDSC_POWER_DOWN_COMPLETE_BMSK                           0x8000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_GDSC_POWER_DOWN_COMPLETE_SHFT                               15u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_SOFTWARE_CONTROL_OVERRIDE_BMSK                          0x7800u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_SOFTWARE_CONTROL_OVERRIDE_SHFT                              11u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_GDSC_HANDSHAKE_DIS_BMSK                                  0x400u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_GDSC_HANDSHAKE_DIS_SHFT                                     10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_GDSC_MEM_PERI_FORCE_IN_SW_BMSK                           0x200u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_GDSC_MEM_PERI_FORCE_IN_SW_SHFT                               9u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_GDSC_MEM_CORE_FORCE_IN_SW_BMSK                           0x100u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_GDSC_MEM_CORE_FORCE_IN_SW_SHFT                               8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_GDSC_PHASE_RESET_EN_SW_BMSK                               0x80u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_GDSC_PHASE_RESET_EN_SW_SHFT                                  7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_GDSC_PHASE_RESET_DELAY_COUNT_SW_BMSK                      0x60u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_GDSC_PHASE_RESET_DELAY_COUNT_SW_SHFT                         5u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_GDSC_PSCBC_PWR_DWN_SW_BMSK                                0x10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_GDSC_PSCBC_PWR_DWN_SW_SHFT                                   4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_UNCLAMP_IO_SOFTWARE_OVERRIDE_BMSK                          0x8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_UNCLAMP_IO_SOFTWARE_OVERRIDE_SHFT                            3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_SAVE_RESTORE_SOFTWARE_OVERRIDE_BMSK                        0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_SAVE_RESTORE_SOFTWARE_OVERRIDE_SHFT                          2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_CLAMP_IO_SOFTWARE_OVERRIDE_BMSK                            0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_CLAMP_IO_SOFTWARE_OVERRIDE_SHFT                              1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_DISABLE_CLK_SOFTWARE_OVERRIDE_BMSK                         0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG_GDSCR_DISABLE_CLK_SOFTWARE_OVERRIDE_SHFT                           0u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG2_GDSCR_ADDR                                               (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x54u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG2_GDSCR_OFFS                                               (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x54u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG2_GDSCR_RMSK                                                  0x7fffful
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG2_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG2_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG2_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG2_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG2_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG2_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG2_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG2_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG2_GDSCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG2_GDSCR_GDSC_MEM_PWRUP_ACK_OVERRIDE_BMSK                      0x40000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG2_GDSCR_GDSC_MEM_PWRUP_ACK_OVERRIDE_SHFT                           18u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG2_GDSCR_GDSC_PWRDWN_ENABLE_ACK_OVERRIDE_BMSK                  0x20000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG2_GDSCR_GDSC_PWRDWN_ENABLE_ACK_OVERRIDE_SHFT                       17u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG2_GDSCR_GDSC_CLAMP_MEM_SW_BMSK                                0x10000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG2_GDSCR_GDSC_CLAMP_MEM_SW_SHFT                                     16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG2_GDSCR_DLY_MEM_PWR_UP_BMSK                                    0xf000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG2_GDSCR_DLY_MEM_PWR_UP_SHFT                                        12u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG2_GDSCR_DLY_DEASSERT_CLAMP_MEM_BMSK                             0xf00u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG2_GDSCR_DLY_DEASSERT_CLAMP_MEM_SHFT                                 8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG2_GDSCR_DLY_ASSERT_CLAMP_MEM_BMSK                                0xf0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG2_GDSCR_DLY_ASSERT_CLAMP_MEM_SHFT                                   4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG2_GDSCR_MEM_PWR_DWN_TIMEOUT_BMSK                                  0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG2_GDSCR_MEM_PWR_DWN_TIMEOUT_SHFT                                    0u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_ADDR                                               (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x58u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_OFFS                                               (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x58u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_RMSK                                                0x7fffffful
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_STATUS_BMSK              0x4000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_STATUS_SHFT                     26u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_BMSK                           0x2000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_SHFT                                  25u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_DISABLE_FVAL                         0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_ENABLE_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_DLY_ACCU_RED_SHIFTER_DONE_BMSK                      0x1e00000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_DLY_ACCU_RED_SHIFTER_DONE_SHFT                             21u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_BMSK                       0x100000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_SHFT                             20u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_DISABLE_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_ENABLE_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_BMSK              0x80000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_SHFT                   19u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_DISABLE_FVAL          0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_ENABLE_FVAL           0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_BMSK                  0x40000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_SHFT                       18u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_DISABLE_FVAL              0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_ENABLE_FVAL               0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_BMSK                   0x20000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_SHFT                        17u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_DISABLE_FVAL               0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_ENABLE_FVAL                0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_BMSK                        0x10000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_SHFT                             16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_DISABLE_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_ENABLE_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_GDSC_SPARE_CTRL_IN_BMSK                                0xff00u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_GDSC_SPARE_CTRL_IN_SHFT                                     8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_GDSC_SPARE_CTRL_OUT_BMSK                                 0xffu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG3_GDSCR_GDSC_SPARE_CTRL_OUT_SHFT                                    0u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG4_GDSCR_ADDR                                               (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x5cu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG4_GDSCR_OFFS                                               (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x5cu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG4_GDSCR_RMSK                                                 0xfffffful
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG4_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG4_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG4_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG4_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG4_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG4_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG4_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG4_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG4_GDSCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG4_GDSCR_DLY_UNCLAMPIO_BMSK                                   0xf00000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG4_GDSCR_DLY_UNCLAMPIO_SHFT                                         20u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG4_GDSCR_DLY_RESTOREFF_BMSK                                    0xf0000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG4_GDSCR_DLY_RESTOREFF_SHFT                                         16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG4_GDSCR_DLY_NORETAINFF_BMSK                                    0xf000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG4_GDSCR_DLY_NORETAINFF_SHFT                                        12u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG4_GDSCR_DLY_DEASSERTARES_BMSK                                   0xf00u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG4_GDSCR_DLY_DEASSERTARES_SHFT                                       8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG4_GDSCR_DLY_CLAMPIO_BMSK                                         0xf0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG4_GDSCR_DLY_CLAMPIO_SHFT                                            4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG4_GDSCR_DLY_RETAINFF_BMSK                                         0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CFG4_GDSCR_DLY_RETAINFF_SHFT                                           0u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_DIV_DCDR_ADDR                                                 (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x60u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_DIV_DCDR_OFFS                                                 (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x60u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_DIV_DCDR_RMSK                                                        0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_DIV_DCDR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_DIV_DCDR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_DIV_DCDR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_DIV_DCDR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_DIV_DCDR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_DIV_DCDR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_DIV_DCDR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_DIV_DCDR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_DIV_DCDR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_DIV_DCDR_DCD_ENABLE_BMSK                                             0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_DIV_DCDR_DCD_ENABLE_SHFT                                               0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_DIV_DCDR_DCD_ENABLE_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_DIV_DCDR_DCD_ENABLE_ENABLE_FVAL                                      0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_ADDR                                                     (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x64u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_OFFS                                                     (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x64u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_RMSK                                                     0x81c07ff5ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_CLK_OFF_BMSK                                             0x80000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_CLK_OFF_SHFT                                                     31u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_IGNORE_ALL_ARES_BMSK                                      0x1000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_IGNORE_ALL_ARES_SHFT                                             24u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                    0x800000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                          23u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_CLK_DIS_BMSK                                               0x400000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_CLK_DIS_SHFT                                                     22u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_FORCE_MEM_CORE_ON_BMSK                                       0x4000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_FORCE_MEM_CORE_ON_SHFT                                           14u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_FORCE_MEM_CORE_ON_FORCE_DISABLE_FVAL                            0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_FORCE_MEM_CORE_ON_FORCE_ENABLE_FVAL                             0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_FORCE_MEM_PERIPH_ON_BMSK                                     0x2000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_FORCE_MEM_PERIPH_ON_SHFT                                         13u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_FORCE_MEM_PERIPH_ON_FORCE_DISABLE_FVAL                          0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_FORCE_MEM_PERIPH_ON_FORCE_ENABLE_FVAL                           0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_FORCE_MEM_PERIPH_OFF_BMSK                                    0x1000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_FORCE_MEM_PERIPH_OFF_SHFT                                        12u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_DISABLE_FVAL                         0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_ENABLE_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_WAKEUP_BMSK                                                   0xf00u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_WAKEUP_SHFT                                                       8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_WAKEUP_CLOCK0_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_WAKEUP_CLOCK1_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_WAKEUP_CLOCK2_FVAL                                              0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_WAKEUP_CLOCK3_FVAL                                              0x3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_WAKEUP_CLOCK4_FVAL                                              0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_WAKEUP_CLOCK5_FVAL                                              0x5u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_WAKEUP_CLOCK6_FVAL                                              0x6u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_WAKEUP_CLOCK7_FVAL                                              0x7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_WAKEUP_CLOCK8_FVAL                                              0x8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_WAKEUP_CLOCK9_FVAL                                              0x9u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_WAKEUP_CLOCK10_FVAL                                             0xau
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_WAKEUP_CLOCK11_FVAL                                             0xbu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_WAKEUP_CLOCK12_FVAL                                             0xcu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_WAKEUP_CLOCK13_FVAL                                             0xdu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_WAKEUP_CLOCK14_FVAL                                             0xeu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_WAKEUP_CLOCK15_FVAL                                             0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_SLEEP_BMSK                                                     0xf0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_SLEEP_SHFT                                                        4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_SLEEP_CLOCK0_FVAL                                               0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_SLEEP_CLOCK1_FVAL                                               0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_SLEEP_CLOCK2_FVAL                                               0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_SLEEP_CLOCK3_FVAL                                               0x3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_SLEEP_CLOCK4_FVAL                                               0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_SLEEP_CLOCK5_FVAL                                               0x5u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_SLEEP_CLOCK6_FVAL                                               0x6u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_SLEEP_CLOCK7_FVAL                                               0x7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_SLEEP_CLOCK8_FVAL                                               0x8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_SLEEP_CLOCK9_FVAL                                               0x9u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_SLEEP_CLOCK10_FVAL                                              0xau
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_SLEEP_CLOCK11_FVAL                                              0xbu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_SLEEP_CLOCK12_FVAL                                              0xcu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_SLEEP_CLOCK13_FVAL                                              0xdu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_SLEEP_CLOCK14_FVAL                                              0xeu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_SLEEP_CLOCK15_FVAL                                              0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_CLK_ARES_BMSK                                                   0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_CLK_ARES_SHFT                                                     2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_CLK_ARES_NO_RESET_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_CLK_ARES_RESET_FVAL                                             0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_CLK_ENABLE_BMSK                                                 0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_CLK_ENABLE_SHFT                                                   0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_CLK_ENABLE_DISABLE_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_CBCR_CLK_ENABLE_ENABLE_FVAL                                          0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_ADDR                                                    (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x68u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_OFFS                                                    (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x68u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_RMSK                                                    0xfffffffeul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_BMSK                          0xff000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_SHFT                                  24u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SREG_PSCBC_SPARE_CTRL_IN_BMSK                             0xff0000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SREG_PSCBC_SPARE_CTRL_IN_SHFT                                   16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_IGNORE_GDSC_PWR_DWN_CSR_BMSK                                0x8000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_IGNORE_GDSC_PWR_DWN_CSR_SHFT                                    15u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_IGNORE_GDSC_PWR_DWN_CSR_NO_IGNORE_FVAL                         0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_IGNORE_GDSC_PWR_DWN_CSR_IGNORE_FVAL                            0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_PSCBC_SLP_STG_MODE_CSR_BMSK                                 0x4000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_PSCBC_SLP_STG_MODE_CSR_SHFT                                     14u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_PSCBC_SLP_STG_MODE_CSR_SREG_PSCBC_MODE_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_PSCBC_SLP_STG_MODE_CSR_PSCBC_SLP_STG_MODE_FVAL                 0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_MEM_CPH_RST_SW_OVERRIDE_BMSK                                0x2000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_MEM_CPH_RST_SW_OVERRIDE_SHFT                                    13u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_MEM_CPH_RST_SW_OVERRIDE_NO_OVERRIDE_FVAL                       0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_MEM_CPH_RST_SW_OVERRIDE_OVERRIDE_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_BMSK                            0x1000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_SHFT                                12u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_NO_RESET_FVAL                      0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_RESET_FVAL                         0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_MEM_CORE_ON_ACK_BMSK                                         0x800u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_MEM_CORE_ON_ACK_SHFT                                            11u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_MEM_PERIPH_ON_ACK_BMSK                                       0x400u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_MEM_PERIPH_ON_ACK_SHFT                                          10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SW_DIV_RATIO_SLP_STG_CLK_BMSK                                0x300u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SW_DIV_RATIO_SLP_STG_CLK_SHFT                                    8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_1_FVAL                         0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_2_FVAL                         0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_4_FVAL                         0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_8_FVAL                         0x3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_MEM_CPH_ENABLE_BMSK                                           0x80u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_MEM_CPH_ENABLE_SHFT                                              7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_MEM_CPH_ENABLE_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_MEM_CPH_ENABLE_ENABLE_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_FORCE_CLK_ON_BMSK                                             0x40u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_FORCE_CLK_ON_SHFT                                                6u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_FORCE_CLK_ON_NO_FORCE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_FORCE_CLK_ON_FORCE_ENABLE_FVAL                                 0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SW_RST_SEL_SLP_STG_BMSK                                       0x20u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SW_RST_SEL_SLP_STG_SHFT                                          5u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_HARDWARE_ARES_FVAL               0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_SW_RST_SLP_STG_BIT_FVAL          0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SW_RST_SLP_STG_BMSK                                           0x10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SW_RST_SLP_STG_SHFT                                              4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SW_RST_SLP_STG_DE_ASSERTION_OF_THE_RESET_FVAL                  0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SW_RST_SLP_STG_ASSERTION_OF_THE_RESET_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SW_CTRL_PWR_DOWN_BMSK                                          0x8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SW_CTRL_PWR_DOWN_SHFT                                            3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SW_CTRL_PWR_DOWN_NO_SW_CTRL_FVAL                               0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SW_CTRL_PWR_DOWN_SW_CTRL_FVAL                                  0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SW_CLK_EN_SEL_SLP_STG_BMSK                                     0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SW_CLK_EN_SEL_SLP_STG_SHFT                                       2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_HW_FSM_FVAL        0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_SW_CLK_EN_SLP_STG_BIT_FVAL        0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SW_CLK_EN_SLP_STG_BMSK                                         0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SW_CLK_EN_SLP_STG_SHFT                                           1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_DISABLE_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_ENABLE_FVAL                    0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_DIV2_DIV_CDIVR_ADDR                                           (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x6cu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_DIV2_DIV_CDIVR_OFFS                                           (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x6cu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_DIV2_DIV_CDIVR_RMSK                                                  0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_DIV2_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_DIV2_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_DIV2_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_DIV2_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_DIV2_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_DIV2_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_DIV2_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_DIV2_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_DIV2_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_DIV2_DIV_CDIVR_CLK_DIV_BMSK                                          0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0C_DIV2_DIV_CDIVR_CLK_DIV_SHFT                                            0u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_BCR_ADDR                                                      (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x70u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_BCR_OFFS                                                      (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x70u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_BCR_RMSK                                                             0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_BCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_BCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_BCR_BLK_ARES_BMSK                                                    0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_BCR_BLK_ARES_SHFT                                                      0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_BCR_BLK_ARES_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_BCR_BLK_ARES_ENABLE_FVAL                                             0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_ADDR                                                    (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x74u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_OFFS                                                    (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x74u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_RMSK                                                    0xf8fffffful
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_PWR_ON_BMSK                                             0x80000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_PWR_ON_SHFT                                                     31u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_GDSC_STATE_BMSK                                         0x78000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_GDSC_STATE_SHFT                                                 27u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_EN_REST_WAIT_BMSK                                         0xf00000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_EN_REST_WAIT_SHFT                                               20u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_EN_FEW_WAIT_BMSK                                           0xf0000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_EN_FEW_WAIT_SHFT                                                16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_CLK_DIS_WAIT_BMSK                                           0xf000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_CLK_DIS_WAIT_SHFT                                               12u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_RETAIN_FF_ENABLE_BMSK                                        0x800u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_RETAIN_FF_ENABLE_SHFT                                           11u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_RETAIN_FF_ENABLE_DISABLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_RETAIN_FF_ENABLE_ENABLE_FVAL                                   0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_RESTORE_BMSK                                                 0x400u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_RESTORE_SHFT                                                    10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_RESTORE_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_RESTORE_ENABLE_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_SAVE_BMSK                                                    0x200u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_SAVE_SHFT                                                        9u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_SAVE_DISABLE_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_SAVE_ENABLE_FVAL                                               0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_RETAIN_BMSK                                                  0x100u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_RETAIN_SHFT                                                      8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_RETAIN_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_RETAIN_ENABLE_FVAL                                             0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_EN_REST_BMSK                                                  0x80u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_EN_REST_SHFT                                                     7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_EN_REST_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_EN_REST_ENABLE_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_EN_FEW_BMSK                                                   0x40u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_EN_FEW_SHFT                                                      6u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_EN_FEW_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_EN_FEW_ENABLE_FVAL                                             0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_CLAMP_IO_BMSK                                                 0x20u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_CLAMP_IO_SHFT                                                    5u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_CLAMP_IO_DISABLE_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_CLAMP_IO_ENABLE_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_CLK_DISABLE_BMSK                                              0x10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_CLK_DISABLE_SHFT                                                 4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_CLK_DISABLE_CLK_NOT_DISABLE_FVAL                               0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_CLK_DISABLE_CLK_IS_DISABLE_FVAL                                0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_PD_ARES_BMSK                                                   0x8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_PD_ARES_SHFT                                                     3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_PD_ARES_NO_RESET_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_PD_ARES_RESET_FVAL                                             0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_SW_OVERRIDE_BMSK                                               0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_SW_OVERRIDE_SHFT                                                 2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_SW_OVERRIDE_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_SW_OVERRIDE_ENABLE_FVAL                                        0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_HW_CONTROL_BMSK                                                0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_HW_CONTROL_SHFT                                                  1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_HW_CONTROL_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_HW_CONTROL_ENABLE_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_SW_COLLAPSE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_SW_COLLAPSE_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_SW_COLLAPSE_DISABLE_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_GDSCR_SW_COLLAPSE_ENABLE_FVAL                                        0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_ADDR                                                (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x78u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_OFFS                                                (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x78u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_RMSK                                                 0x3fffffful
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_GDSC_PWR_DWN_START_BMSK                              0x2000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_GDSC_PWR_DWN_START_SHFT                                     25u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_GDSC_PWR_UP_START_BMSK                               0x1000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_GDSC_PWR_UP_START_SHFT                                      24u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_GDSC_CFG_FSM_STATE_STATUS_BMSK                        0xf00000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_GDSC_CFG_FSM_STATE_STATUS_SHFT                              20u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_GDSC_MEM_PWR_ACK_STATUS_BMSK                           0x80000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_GDSC_MEM_PWR_ACK_STATUS_SHFT                                19u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_GDSC_ENR_ACK_STATUS_BMSK                               0x40000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_GDSC_ENR_ACK_STATUS_SHFT                                    18u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_GDSC_ENF_ACK_STATUS_BMSK                               0x20000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_GDSC_ENF_ACK_STATUS_SHFT                                    17u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_GDSC_POWER_UP_COMPLETE_BMSK                            0x10000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_GDSC_POWER_UP_COMPLETE_SHFT                                 16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_GDSC_POWER_DOWN_COMPLETE_BMSK                           0x8000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_GDSC_POWER_DOWN_COMPLETE_SHFT                               15u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_SOFTWARE_CONTROL_OVERRIDE_BMSK                          0x7800u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_SOFTWARE_CONTROL_OVERRIDE_SHFT                              11u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_GDSC_HANDSHAKE_DIS_BMSK                                  0x400u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_GDSC_HANDSHAKE_DIS_SHFT                                     10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_GDSC_MEM_PERI_FORCE_IN_SW_BMSK                           0x200u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_GDSC_MEM_PERI_FORCE_IN_SW_SHFT                               9u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_GDSC_MEM_CORE_FORCE_IN_SW_BMSK                           0x100u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_GDSC_MEM_CORE_FORCE_IN_SW_SHFT                               8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_GDSC_PHASE_RESET_EN_SW_BMSK                               0x80u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_GDSC_PHASE_RESET_EN_SW_SHFT                                  7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_GDSC_PHASE_RESET_DELAY_COUNT_SW_BMSK                      0x60u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_GDSC_PHASE_RESET_DELAY_COUNT_SW_SHFT                         5u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_GDSC_PSCBC_PWR_DWN_SW_BMSK                                0x10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_GDSC_PSCBC_PWR_DWN_SW_SHFT                                   4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_UNCLAMP_IO_SOFTWARE_OVERRIDE_BMSK                          0x8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_UNCLAMP_IO_SOFTWARE_OVERRIDE_SHFT                            3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_SAVE_RESTORE_SOFTWARE_OVERRIDE_BMSK                        0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_SAVE_RESTORE_SOFTWARE_OVERRIDE_SHFT                          2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_CLAMP_IO_SOFTWARE_OVERRIDE_BMSK                            0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_CLAMP_IO_SOFTWARE_OVERRIDE_SHFT                              1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_DISABLE_CLK_SOFTWARE_OVERRIDE_BMSK                         0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG_GDSCR_DISABLE_CLK_SOFTWARE_OVERRIDE_SHFT                           0u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG2_GDSCR_ADDR                                               (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x7cu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG2_GDSCR_OFFS                                               (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x7cu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG2_GDSCR_RMSK                                                  0x7fffful
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG2_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG2_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG2_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG2_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG2_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG2_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG2_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG2_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG2_GDSCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG2_GDSCR_GDSC_MEM_PWRUP_ACK_OVERRIDE_BMSK                      0x40000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG2_GDSCR_GDSC_MEM_PWRUP_ACK_OVERRIDE_SHFT                           18u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG2_GDSCR_GDSC_PWRDWN_ENABLE_ACK_OVERRIDE_BMSK                  0x20000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG2_GDSCR_GDSC_PWRDWN_ENABLE_ACK_OVERRIDE_SHFT                       17u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG2_GDSCR_GDSC_CLAMP_MEM_SW_BMSK                                0x10000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG2_GDSCR_GDSC_CLAMP_MEM_SW_SHFT                                     16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG2_GDSCR_DLY_MEM_PWR_UP_BMSK                                    0xf000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG2_GDSCR_DLY_MEM_PWR_UP_SHFT                                        12u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG2_GDSCR_DLY_DEASSERT_CLAMP_MEM_BMSK                             0xf00u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG2_GDSCR_DLY_DEASSERT_CLAMP_MEM_SHFT                                 8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG2_GDSCR_DLY_ASSERT_CLAMP_MEM_BMSK                                0xf0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG2_GDSCR_DLY_ASSERT_CLAMP_MEM_SHFT                                   4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG2_GDSCR_MEM_PWR_DWN_TIMEOUT_BMSK                                  0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG2_GDSCR_MEM_PWR_DWN_TIMEOUT_SHFT                                    0u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_ADDR                                               (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x80u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_OFFS                                               (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x80u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_RMSK                                                0x7fffffful
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_STATUS_BMSK              0x4000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_STATUS_SHFT                     26u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_BMSK                           0x2000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_SHFT                                  25u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_DISABLE_FVAL                         0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_ENABLE_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_DLY_ACCU_RED_SHIFTER_DONE_BMSK                      0x1e00000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_DLY_ACCU_RED_SHIFTER_DONE_SHFT                             21u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_BMSK                       0x100000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_SHFT                             20u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_DISABLE_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_ENABLE_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_BMSK              0x80000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_SHFT                   19u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_DISABLE_FVAL          0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_ENABLE_FVAL           0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_BMSK                  0x40000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_SHFT                       18u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_DISABLE_FVAL              0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_ENABLE_FVAL               0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_BMSK                   0x20000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_SHFT                        17u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_DISABLE_FVAL               0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_ENABLE_FVAL                0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_BMSK                        0x10000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_SHFT                             16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_DISABLE_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_ENABLE_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_GDSC_SPARE_CTRL_IN_BMSK                                0xff00u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_GDSC_SPARE_CTRL_IN_SHFT                                     8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_GDSC_SPARE_CTRL_OUT_BMSK                                 0xffu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG3_GDSCR_GDSC_SPARE_CTRL_OUT_SHFT                                    0u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG4_GDSCR_ADDR                                               (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x84u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG4_GDSCR_OFFS                                               (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x84u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG4_GDSCR_RMSK                                                 0xfffffful
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG4_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG4_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG4_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG4_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG4_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG4_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG4_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG4_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG4_GDSCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG4_GDSCR_DLY_UNCLAMPIO_BMSK                                   0xf00000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG4_GDSCR_DLY_UNCLAMPIO_SHFT                                         20u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG4_GDSCR_DLY_RESTOREFF_BMSK                                    0xf0000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG4_GDSCR_DLY_RESTOREFF_SHFT                                         16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG4_GDSCR_DLY_NORETAINFF_BMSK                                    0xf000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG4_GDSCR_DLY_NORETAINFF_SHFT                                        12u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG4_GDSCR_DLY_DEASSERTARES_BMSK                                   0xf00u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG4_GDSCR_DLY_DEASSERTARES_SHFT                                       8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG4_GDSCR_DLY_CLAMPIO_BMSK                                         0xf0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG4_GDSCR_DLY_CLAMPIO_SHFT                                            4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG4_GDSCR_DLY_RETAINFF_BMSK                                         0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CFG4_GDSCR_DLY_RETAINFF_SHFT                                           0u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_DIV_DCDR_ADDR                                                 (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x88u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_DIV_DCDR_OFFS                                                 (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x88u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_DIV_DCDR_RMSK                                                        0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_DIV_DCDR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_DIV_DCDR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_DIV_DCDR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_DIV_DCDR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_DIV_DCDR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_DIV_DCDR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_DIV_DCDR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_DIV_DCDR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_DIV_DCDR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_DIV_DCDR_DCD_ENABLE_BMSK                                             0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_DIV_DCDR_DCD_ENABLE_SHFT                                               0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_DIV_DCDR_DCD_ENABLE_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_DIV_DCDR_DCD_ENABLE_ENABLE_FVAL                                      0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_ADDR                                                     (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x8cu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_OFFS                                                     (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x8cu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_RMSK                                                     0x81c07ff5ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_CLK_OFF_BMSK                                             0x80000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_CLK_OFF_SHFT                                                     31u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_IGNORE_ALL_ARES_BMSK                                      0x1000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_IGNORE_ALL_ARES_SHFT                                             24u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                    0x800000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                          23u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_CLK_DIS_BMSK                                               0x400000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_CLK_DIS_SHFT                                                     22u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_FORCE_MEM_CORE_ON_BMSK                                       0x4000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_FORCE_MEM_CORE_ON_SHFT                                           14u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_FORCE_MEM_CORE_ON_FORCE_DISABLE_FVAL                            0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_FORCE_MEM_CORE_ON_FORCE_ENABLE_FVAL                             0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_FORCE_MEM_PERIPH_ON_BMSK                                     0x2000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_FORCE_MEM_PERIPH_ON_SHFT                                         13u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_FORCE_MEM_PERIPH_ON_FORCE_DISABLE_FVAL                          0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_FORCE_MEM_PERIPH_ON_FORCE_ENABLE_FVAL                           0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_FORCE_MEM_PERIPH_OFF_BMSK                                    0x1000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_FORCE_MEM_PERIPH_OFF_SHFT                                        12u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_DISABLE_FVAL                         0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_ENABLE_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_WAKEUP_BMSK                                                   0xf00u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_WAKEUP_SHFT                                                       8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_WAKEUP_CLOCK0_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_WAKEUP_CLOCK1_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_WAKEUP_CLOCK2_FVAL                                              0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_WAKEUP_CLOCK3_FVAL                                              0x3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_WAKEUP_CLOCK4_FVAL                                              0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_WAKEUP_CLOCK5_FVAL                                              0x5u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_WAKEUP_CLOCK6_FVAL                                              0x6u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_WAKEUP_CLOCK7_FVAL                                              0x7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_WAKEUP_CLOCK8_FVAL                                              0x8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_WAKEUP_CLOCK9_FVAL                                              0x9u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_WAKEUP_CLOCK10_FVAL                                             0xau
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_WAKEUP_CLOCK11_FVAL                                             0xbu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_WAKEUP_CLOCK12_FVAL                                             0xcu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_WAKEUP_CLOCK13_FVAL                                             0xdu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_WAKEUP_CLOCK14_FVAL                                             0xeu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_WAKEUP_CLOCK15_FVAL                                             0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_SLEEP_BMSK                                                     0xf0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_SLEEP_SHFT                                                        4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_SLEEP_CLOCK0_FVAL                                               0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_SLEEP_CLOCK1_FVAL                                               0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_SLEEP_CLOCK2_FVAL                                               0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_SLEEP_CLOCK3_FVAL                                               0x3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_SLEEP_CLOCK4_FVAL                                               0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_SLEEP_CLOCK5_FVAL                                               0x5u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_SLEEP_CLOCK6_FVAL                                               0x6u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_SLEEP_CLOCK7_FVAL                                               0x7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_SLEEP_CLOCK8_FVAL                                               0x8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_SLEEP_CLOCK9_FVAL                                               0x9u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_SLEEP_CLOCK10_FVAL                                              0xau
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_SLEEP_CLOCK11_FVAL                                              0xbu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_SLEEP_CLOCK12_FVAL                                              0xcu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_SLEEP_CLOCK13_FVAL                                              0xdu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_SLEEP_CLOCK14_FVAL                                              0xeu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_SLEEP_CLOCK15_FVAL                                              0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_CLK_ARES_BMSK                                                   0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_CLK_ARES_SHFT                                                     2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_CLK_ARES_NO_RESET_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_CLK_ARES_RESET_FVAL                                             0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_CLK_ENABLE_BMSK                                                 0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_CLK_ENABLE_SHFT                                                   0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_CLK_ENABLE_DISABLE_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_CBCR_CLK_ENABLE_ENABLE_FVAL                                          0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_ADDR                                                    (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x90u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_OFFS                                                    (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x90u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_RMSK                                                    0xfffffffeul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_BMSK                          0xff000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_SHFT                                  24u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SREG_PSCBC_SPARE_CTRL_IN_BMSK                             0xff0000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SREG_PSCBC_SPARE_CTRL_IN_SHFT                                   16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_IGNORE_GDSC_PWR_DWN_CSR_BMSK                                0x8000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_IGNORE_GDSC_PWR_DWN_CSR_SHFT                                    15u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_IGNORE_GDSC_PWR_DWN_CSR_NO_IGNORE_FVAL                         0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_IGNORE_GDSC_PWR_DWN_CSR_IGNORE_FVAL                            0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_PSCBC_SLP_STG_MODE_CSR_BMSK                                 0x4000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_PSCBC_SLP_STG_MODE_CSR_SHFT                                     14u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_PSCBC_SLP_STG_MODE_CSR_SREG_PSCBC_MODE_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_PSCBC_SLP_STG_MODE_CSR_PSCBC_SLP_STG_MODE_FVAL                 0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_MEM_CPH_RST_SW_OVERRIDE_BMSK                                0x2000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_MEM_CPH_RST_SW_OVERRIDE_SHFT                                    13u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_MEM_CPH_RST_SW_OVERRIDE_NO_OVERRIDE_FVAL                       0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_MEM_CPH_RST_SW_OVERRIDE_OVERRIDE_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_BMSK                            0x1000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_SHFT                                12u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_NO_RESET_FVAL                      0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_RESET_FVAL                         0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_MEM_CORE_ON_ACK_BMSK                                         0x800u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_MEM_CORE_ON_ACK_SHFT                                            11u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_MEM_PERIPH_ON_ACK_BMSK                                       0x400u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_MEM_PERIPH_ON_ACK_SHFT                                          10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SW_DIV_RATIO_SLP_STG_CLK_BMSK                                0x300u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SW_DIV_RATIO_SLP_STG_CLK_SHFT                                    8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_1_FVAL                         0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_2_FVAL                         0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_4_FVAL                         0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_8_FVAL                         0x3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_MEM_CPH_ENABLE_BMSK                                           0x80u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_MEM_CPH_ENABLE_SHFT                                              7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_MEM_CPH_ENABLE_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_MEM_CPH_ENABLE_ENABLE_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_FORCE_CLK_ON_BMSK                                             0x40u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_FORCE_CLK_ON_SHFT                                                6u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_FORCE_CLK_ON_NO_FORCE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_FORCE_CLK_ON_FORCE_ENABLE_FVAL                                 0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SW_RST_SEL_SLP_STG_BMSK                                       0x20u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SW_RST_SEL_SLP_STG_SHFT                                          5u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_HARDWARE_ARES_FVAL               0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_SW_RST_SLP_STG_BIT_FVAL          0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SW_RST_SLP_STG_BMSK                                           0x10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SW_RST_SLP_STG_SHFT                                              4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SW_RST_SLP_STG_DE_ASSERTION_OF_THE_RESET_FVAL                  0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SW_RST_SLP_STG_ASSERTION_OF_THE_RESET_FVAL                     0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SW_CTRL_PWR_DOWN_BMSK                                          0x8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SW_CTRL_PWR_DOWN_SHFT                                            3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SW_CTRL_PWR_DOWN_NO_SW_CTRL_FVAL                               0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SW_CTRL_PWR_DOWN_SW_CTRL_FVAL                                  0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SW_CLK_EN_SEL_SLP_STG_BMSK                                     0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SW_CLK_EN_SEL_SLP_STG_SHFT                                       2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_HW_FSM_FVAL        0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_SW_CLK_EN_SLP_STG_BIT_FVAL        0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SW_CLK_EN_SLP_STG_BMSK                                         0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SW_CLK_EN_SLP_STG_SHFT                                           1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_DISABLE_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_ENABLE_FVAL                    0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_DIV2_DIV_CDIVR_ADDR                                           (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x94u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_DIV2_DIV_CDIVR_OFFS                                           (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x94u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_DIV2_DIV_CDIVR_RMSK                                                  0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_DIV2_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_DIV2_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_DIV2_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_DIV2_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_DIV2_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_DIV2_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_DIV2_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_DIV2_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_DIV2_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_DIV2_DIV_CDIVR_CLK_DIV_BMSK                                          0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1C_DIV2_DIV_CDIVR_CLK_DIV_SHFT                                            0u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_BCR_ADDR                                                       (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x98u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_BCR_OFFS                                                       (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x98u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_BCR_RMSK                                                              0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_BCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_BCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_BCR_BLK_ARES_BMSK                                                     0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_BCR_BLK_ARES_SHFT                                                       0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_BCR_BLK_ARES_DISABLE_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_BCR_BLK_ARES_ENABLE_FVAL                                              0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_ADDR                                                     (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x9cu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_OFFS                                                     (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x9cu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_RMSK                                                     0xf8fffffful
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_PWR_ON_BMSK                                              0x80000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_PWR_ON_SHFT                                                      31u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_GDSC_STATE_BMSK                                          0x78000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_GDSC_STATE_SHFT                                                  27u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_EN_REST_WAIT_BMSK                                          0xf00000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_EN_REST_WAIT_SHFT                                                20u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_EN_FEW_WAIT_BMSK                                            0xf0000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_EN_FEW_WAIT_SHFT                                                 16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_CLK_DIS_WAIT_BMSK                                            0xf000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_CLK_DIS_WAIT_SHFT                                                12u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_RETAIN_FF_ENABLE_BMSK                                         0x800u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_RETAIN_FF_ENABLE_SHFT                                            11u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_RETAIN_FF_ENABLE_DISABLE_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_RETAIN_FF_ENABLE_ENABLE_FVAL                                    0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_RESTORE_BMSK                                                  0x400u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_RESTORE_SHFT                                                     10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_RESTORE_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_RESTORE_ENABLE_FVAL                                             0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_SAVE_BMSK                                                     0x200u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_SAVE_SHFT                                                         9u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_SAVE_DISABLE_FVAL                                               0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_SAVE_ENABLE_FVAL                                                0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_RETAIN_BMSK                                                   0x100u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_RETAIN_SHFT                                                       8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_RETAIN_DISABLE_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_RETAIN_ENABLE_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_EN_REST_BMSK                                                   0x80u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_EN_REST_SHFT                                                      7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_EN_REST_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_EN_REST_ENABLE_FVAL                                             0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_EN_FEW_BMSK                                                    0x40u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_EN_FEW_SHFT                                                       6u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_EN_FEW_DISABLE_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_EN_FEW_ENABLE_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_CLAMP_IO_BMSK                                                  0x20u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_CLAMP_IO_SHFT                                                     5u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_CLAMP_IO_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_CLAMP_IO_ENABLE_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_CLK_DISABLE_BMSK                                               0x10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_CLK_DISABLE_SHFT                                                  4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_CLK_DISABLE_CLK_NOT_DISABLE_FVAL                                0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_CLK_DISABLE_CLK_IS_DISABLE_FVAL                                 0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_PD_ARES_BMSK                                                    0x8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_PD_ARES_SHFT                                                      3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_PD_ARES_NO_RESET_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_PD_ARES_RESET_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_SW_OVERRIDE_BMSK                                                0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_SW_OVERRIDE_SHFT                                                  2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_SW_OVERRIDE_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_SW_OVERRIDE_ENABLE_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_HW_CONTROL_BMSK                                                 0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_HW_CONTROL_SHFT                                                   1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_HW_CONTROL_DISABLE_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_HW_CONTROL_ENABLE_FVAL                                          0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_SW_COLLAPSE_BMSK                                                0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_SW_COLLAPSE_SHFT                                                  0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_SW_COLLAPSE_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_GDSCR_SW_COLLAPSE_ENABLE_FVAL                                         0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_ADDR                                                 (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0xa0u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_OFFS                                                 (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0xa0u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_RMSK                                                  0x3fffffful
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_GDSC_PWR_DWN_START_BMSK                               0x2000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_GDSC_PWR_DWN_START_SHFT                                      25u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_GDSC_PWR_UP_START_BMSK                                0x1000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_GDSC_PWR_UP_START_SHFT                                       24u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_GDSC_CFG_FSM_STATE_STATUS_BMSK                         0xf00000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_GDSC_CFG_FSM_STATE_STATUS_SHFT                               20u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_GDSC_MEM_PWR_ACK_STATUS_BMSK                            0x80000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_GDSC_MEM_PWR_ACK_STATUS_SHFT                                 19u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_GDSC_ENR_ACK_STATUS_BMSK                                0x40000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_GDSC_ENR_ACK_STATUS_SHFT                                     18u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_GDSC_ENF_ACK_STATUS_BMSK                                0x20000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_GDSC_ENF_ACK_STATUS_SHFT                                     17u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_GDSC_POWER_UP_COMPLETE_BMSK                             0x10000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_GDSC_POWER_UP_COMPLETE_SHFT                                  16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_GDSC_POWER_DOWN_COMPLETE_BMSK                            0x8000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_GDSC_POWER_DOWN_COMPLETE_SHFT                                15u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_SOFTWARE_CONTROL_OVERRIDE_BMSK                           0x7800u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_SOFTWARE_CONTROL_OVERRIDE_SHFT                               11u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_GDSC_HANDSHAKE_DIS_BMSK                                   0x400u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_GDSC_HANDSHAKE_DIS_SHFT                                      10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_GDSC_MEM_PERI_FORCE_IN_SW_BMSK                            0x200u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_GDSC_MEM_PERI_FORCE_IN_SW_SHFT                                9u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_GDSC_MEM_CORE_FORCE_IN_SW_BMSK                            0x100u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_GDSC_MEM_CORE_FORCE_IN_SW_SHFT                                8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_GDSC_PHASE_RESET_EN_SW_BMSK                                0x80u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_GDSC_PHASE_RESET_EN_SW_SHFT                                   7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_GDSC_PHASE_RESET_DELAY_COUNT_SW_BMSK                       0x60u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_GDSC_PHASE_RESET_DELAY_COUNT_SW_SHFT                          5u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_GDSC_PSCBC_PWR_DWN_SW_BMSK                                 0x10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_GDSC_PSCBC_PWR_DWN_SW_SHFT                                    4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_UNCLAMP_IO_SOFTWARE_OVERRIDE_BMSK                           0x8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_UNCLAMP_IO_SOFTWARE_OVERRIDE_SHFT                             3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_SAVE_RESTORE_SOFTWARE_OVERRIDE_BMSK                         0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_SAVE_RESTORE_SOFTWARE_OVERRIDE_SHFT                           2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_CLAMP_IO_SOFTWARE_OVERRIDE_BMSK                             0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_CLAMP_IO_SOFTWARE_OVERRIDE_SHFT                               1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_DISABLE_CLK_SOFTWARE_OVERRIDE_BMSK                          0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG_GDSCR_DISABLE_CLK_SOFTWARE_OVERRIDE_SHFT                            0u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG2_GDSCR_ADDR                                                (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0xa4u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG2_GDSCR_OFFS                                                (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0xa4u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG2_GDSCR_RMSK                                                   0x7fffful
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG2_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG2_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG2_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG2_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG2_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG2_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG2_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG2_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG2_GDSCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG2_GDSCR_GDSC_MEM_PWRUP_ACK_OVERRIDE_BMSK                       0x40000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG2_GDSCR_GDSC_MEM_PWRUP_ACK_OVERRIDE_SHFT                            18u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG2_GDSCR_GDSC_PWRDWN_ENABLE_ACK_OVERRIDE_BMSK                   0x20000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG2_GDSCR_GDSC_PWRDWN_ENABLE_ACK_OVERRIDE_SHFT                        17u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG2_GDSCR_GDSC_CLAMP_MEM_SW_BMSK                                 0x10000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG2_GDSCR_GDSC_CLAMP_MEM_SW_SHFT                                      16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG2_GDSCR_DLY_MEM_PWR_UP_BMSK                                     0xf000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG2_GDSCR_DLY_MEM_PWR_UP_SHFT                                         12u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG2_GDSCR_DLY_DEASSERT_CLAMP_MEM_BMSK                              0xf00u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG2_GDSCR_DLY_DEASSERT_CLAMP_MEM_SHFT                                  8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG2_GDSCR_DLY_ASSERT_CLAMP_MEM_BMSK                                 0xf0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG2_GDSCR_DLY_ASSERT_CLAMP_MEM_SHFT                                    4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG2_GDSCR_MEM_PWR_DWN_TIMEOUT_BMSK                                   0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG2_GDSCR_MEM_PWR_DWN_TIMEOUT_SHFT                                     0u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_ADDR                                                (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0xa8u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_OFFS                                                (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0xa8u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_RMSK                                                 0x7fffffful
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_STATUS_BMSK               0x4000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_STATUS_SHFT                      26u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_BMSK                            0x2000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_SHFT                                   25u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_DISABLE_FVAL                          0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_ENABLE_FVAL                           0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_DLY_ACCU_RED_SHIFTER_DONE_BMSK                       0x1e00000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_DLY_ACCU_RED_SHIFTER_DONE_SHFT                              21u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_BMSK                        0x100000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_SHFT                              20u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_DISABLE_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_ENABLE_FVAL                      0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_BMSK               0x80000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_SHFT                    19u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_DISABLE_FVAL           0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_ENABLE_FVAL            0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_BMSK                   0x40000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_SHFT                        18u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_DISABLE_FVAL               0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_ENABLE_FVAL                0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_BMSK                    0x20000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_SHFT                         17u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_DISABLE_FVAL                0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_ENABLE_FVAL                 0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_BMSK                         0x10000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_SHFT                              16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_DISABLE_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_ENABLE_FVAL                      0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_GDSC_SPARE_CTRL_IN_BMSK                                 0xff00u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_GDSC_SPARE_CTRL_IN_SHFT                                      8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_GDSC_SPARE_CTRL_OUT_BMSK                                  0xffu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG3_GDSCR_GDSC_SPARE_CTRL_OUT_SHFT                                     0u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG4_GDSCR_ADDR                                                (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0xacu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG4_GDSCR_OFFS                                                (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0xacu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG4_GDSCR_RMSK                                                  0xfffffful
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG4_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG4_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG4_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG4_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG4_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG4_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG4_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG4_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG4_GDSCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG4_GDSCR_DLY_UNCLAMPIO_BMSK                                    0xf00000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG4_GDSCR_DLY_UNCLAMPIO_SHFT                                          20u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG4_GDSCR_DLY_RESTOREFF_BMSK                                     0xf0000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG4_GDSCR_DLY_RESTOREFF_SHFT                                          16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG4_GDSCR_DLY_NORETAINFF_BMSK                                     0xf000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG4_GDSCR_DLY_NORETAINFF_SHFT                                         12u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG4_GDSCR_DLY_DEASSERTARES_BMSK                                    0xf00u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG4_GDSCR_DLY_DEASSERTARES_SHFT                                        8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG4_GDSCR_DLY_CLAMPIO_BMSK                                          0xf0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG4_GDSCR_DLY_CLAMPIO_SHFT                                             4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG4_GDSCR_DLY_RETAINFF_BMSK                                          0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CFG4_GDSCR_DLY_RETAINFF_SHFT                                            0u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_ADDR                                                      (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0xb0u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_OFFS                                                      (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0xb0u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_RMSK                                                      0x81c07ffful
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_CLK_OFF_BMSK                                              0x80000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_CLK_OFF_SHFT                                                      31u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_IGNORE_ALL_ARES_BMSK                                       0x1000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_IGNORE_ALL_ARES_SHFT                                              24u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                     0x800000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                           23u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_CLK_DIS_BMSK                                                0x400000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_CLK_DIS_SHFT                                                      22u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_FORCE_MEM_CORE_ON_BMSK                                        0x4000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_FORCE_MEM_CORE_ON_SHFT                                            14u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_FORCE_MEM_CORE_ON_FORCE_DISABLE_FVAL                             0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_FORCE_MEM_CORE_ON_FORCE_ENABLE_FVAL                              0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_FORCE_MEM_PERIPH_ON_BMSK                                      0x2000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_FORCE_MEM_PERIPH_ON_SHFT                                          13u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_FORCE_MEM_PERIPH_ON_FORCE_DISABLE_FVAL                           0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_FORCE_MEM_PERIPH_ON_FORCE_ENABLE_FVAL                            0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_FORCE_MEM_PERIPH_OFF_BMSK                                     0x1000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_FORCE_MEM_PERIPH_OFF_SHFT                                         12u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_DISABLE_FVAL                          0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_ENABLE_FVAL                           0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_WAKEUP_BMSK                                                    0xf00u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_WAKEUP_SHFT                                                        8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_WAKEUP_CLOCK0_FVAL                                               0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_WAKEUP_CLOCK1_FVAL                                               0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_WAKEUP_CLOCK2_FVAL                                               0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_WAKEUP_CLOCK3_FVAL                                               0x3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_WAKEUP_CLOCK4_FVAL                                               0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_WAKEUP_CLOCK5_FVAL                                               0x5u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_WAKEUP_CLOCK6_FVAL                                               0x6u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_WAKEUP_CLOCK7_FVAL                                               0x7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_WAKEUP_CLOCK8_FVAL                                               0x8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_WAKEUP_CLOCK9_FVAL                                               0x9u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_WAKEUP_CLOCK10_FVAL                                              0xau
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_WAKEUP_CLOCK11_FVAL                                              0xbu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_WAKEUP_CLOCK12_FVAL                                              0xcu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_WAKEUP_CLOCK13_FVAL                                              0xdu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_WAKEUP_CLOCK14_FVAL                                              0xeu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_WAKEUP_CLOCK15_FVAL                                              0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_SLEEP_BMSK                                                      0xf0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_SLEEP_SHFT                                                         4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_SLEEP_CLOCK0_FVAL                                                0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_SLEEP_CLOCK1_FVAL                                                0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_SLEEP_CLOCK2_FVAL                                                0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_SLEEP_CLOCK3_FVAL                                                0x3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_SLEEP_CLOCK4_FVAL                                                0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_SLEEP_CLOCK5_FVAL                                                0x5u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_SLEEP_CLOCK6_FVAL                                                0x6u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_SLEEP_CLOCK7_FVAL                                                0x7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_SLEEP_CLOCK8_FVAL                                                0x8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_SLEEP_CLOCK9_FVAL                                                0x9u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_SLEEP_CLOCK10_FVAL                                               0xau
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_SLEEP_CLOCK11_FVAL                                               0xbu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_SLEEP_CLOCK12_FVAL                                               0xcu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_SLEEP_CLOCK13_FVAL                                               0xdu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_SLEEP_CLOCK14_FVAL                                               0xeu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_SLEEP_CLOCK15_FVAL                                               0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_SW_ONLY_EN_BMSK                                                  0x8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_SW_ONLY_EN_SHFT                                                    3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_CLK_ARES_BMSK                                                    0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_CLK_ARES_SHFT                                                      2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_CLK_ARES_NO_RESET_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_CLK_ARES_RESET_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_HW_CTL_BMSK                                                      0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_HW_CTL_SHFT                                                        1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_HW_CTL_DISABLE_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_HW_CTL_ENABLE_FVAL                                               0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_CLK_ENABLE_BMSK                                                  0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_CLK_ENABLE_SHFT                                                    0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_CLK_ENABLE_DISABLE_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_CBCR_CLK_ENABLE_ENABLE_FVAL                                           0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_ADDR                                                     (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0xb4u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_OFFS                                                     (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0xb4u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_RMSK                                                     0xfffffffeul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_BMSK                           0xff000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_SHFT                                   24u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SREG_PSCBC_SPARE_CTRL_IN_BMSK                              0xff0000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SREG_PSCBC_SPARE_CTRL_IN_SHFT                                    16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_IGNORE_GDSC_PWR_DWN_CSR_BMSK                                 0x8000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_IGNORE_GDSC_PWR_DWN_CSR_SHFT                                     15u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_IGNORE_GDSC_PWR_DWN_CSR_NO_IGNORE_FVAL                          0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_IGNORE_GDSC_PWR_DWN_CSR_IGNORE_FVAL                             0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_PSCBC_SLP_STG_MODE_CSR_BMSK                                  0x4000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_PSCBC_SLP_STG_MODE_CSR_SHFT                                      14u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_PSCBC_SLP_STG_MODE_CSR_SREG_PSCBC_MODE_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_PSCBC_SLP_STG_MODE_CSR_PSCBC_SLP_STG_MODE_FVAL                  0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_MEM_CPH_RST_SW_OVERRIDE_BMSK                                 0x2000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_MEM_CPH_RST_SW_OVERRIDE_SHFT                                     13u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_MEM_CPH_RST_SW_OVERRIDE_NO_OVERRIDE_FVAL                        0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_MEM_CPH_RST_SW_OVERRIDE_OVERRIDE_FVAL                           0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_BMSK                             0x1000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_SHFT                                 12u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_NO_RESET_FVAL                       0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_RESET_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_MEM_CORE_ON_ACK_BMSK                                          0x800u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_MEM_CORE_ON_ACK_SHFT                                             11u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_MEM_PERIPH_ON_ACK_BMSK                                        0x400u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_MEM_PERIPH_ON_ACK_SHFT                                           10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SW_DIV_RATIO_SLP_STG_CLK_BMSK                                 0x300u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SW_DIV_RATIO_SLP_STG_CLK_SHFT                                     8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_1_FVAL                          0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_2_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_4_FVAL                          0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_8_FVAL                          0x3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_MEM_CPH_ENABLE_BMSK                                            0x80u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_MEM_CPH_ENABLE_SHFT                                               7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_MEM_CPH_ENABLE_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_MEM_CPH_ENABLE_ENABLE_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_FORCE_CLK_ON_BMSK                                              0x40u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_FORCE_CLK_ON_SHFT                                                 6u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_FORCE_CLK_ON_NO_FORCE_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_FORCE_CLK_ON_FORCE_ENABLE_FVAL                                  0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SW_RST_SEL_SLP_STG_BMSK                                        0x20u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SW_RST_SEL_SLP_STG_SHFT                                           5u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_HARDWARE_ARES_FVAL                0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_SW_RST_SLP_STG_BIT_FVAL           0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SW_RST_SLP_STG_BMSK                                            0x10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SW_RST_SLP_STG_SHFT                                               4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SW_RST_SLP_STG_DE_ASSERTION_OF_THE_RESET_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SW_RST_SLP_STG_ASSERTION_OF_THE_RESET_FVAL                      0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SW_CTRL_PWR_DOWN_BMSK                                           0x8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SW_CTRL_PWR_DOWN_SHFT                                             3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SW_CTRL_PWR_DOWN_NO_SW_CTRL_FVAL                                0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SW_CTRL_PWR_DOWN_SW_CTRL_FVAL                                   0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SW_CLK_EN_SEL_SLP_STG_BMSK                                      0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SW_CLK_EN_SEL_SLP_STG_SHFT                                        2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_HW_FSM_FVAL        0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_SW_CLK_EN_SLP_STG_BIT_FVAL        0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SW_CLK_EN_SLP_STG_BMSK                                          0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SW_CLK_EN_SLP_STG_SHFT                                            1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_DISABLE_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_ENABLE_FVAL                     0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_DIV_CDIVR_ADDR                                                 (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0xb8u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_DIV_CDIVR_OFFS                                                 (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0xb8u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_DIV_CDIVR_RMSK                                                        0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_DIV_CDIVR_CLK_DIV_BMSK                                                0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS0_DIV_CDIVR_CLK_DIV_SHFT                                                  0u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_BCR_ADDR                                                       (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0xbcu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_BCR_OFFS                                                       (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0xbcu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_BCR_RMSK                                                              0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_BCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_BCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_BCR_BLK_ARES_BMSK                                                     0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_BCR_BLK_ARES_SHFT                                                       0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_BCR_BLK_ARES_DISABLE_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_BCR_BLK_ARES_ENABLE_FVAL                                              0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_ADDR                                                     (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0xc0u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_OFFS                                                     (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0xc0u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_RMSK                                                     0xf8fffffful
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_PWR_ON_BMSK                                              0x80000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_PWR_ON_SHFT                                                      31u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_GDSC_STATE_BMSK                                          0x78000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_GDSC_STATE_SHFT                                                  27u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_EN_REST_WAIT_BMSK                                          0xf00000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_EN_REST_WAIT_SHFT                                                20u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_EN_FEW_WAIT_BMSK                                            0xf0000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_EN_FEW_WAIT_SHFT                                                 16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_CLK_DIS_WAIT_BMSK                                            0xf000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_CLK_DIS_WAIT_SHFT                                                12u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_RETAIN_FF_ENABLE_BMSK                                         0x800u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_RETAIN_FF_ENABLE_SHFT                                            11u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_RETAIN_FF_ENABLE_DISABLE_FVAL                                   0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_RETAIN_FF_ENABLE_ENABLE_FVAL                                    0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_RESTORE_BMSK                                                  0x400u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_RESTORE_SHFT                                                     10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_RESTORE_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_RESTORE_ENABLE_FVAL                                             0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_SAVE_BMSK                                                     0x200u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_SAVE_SHFT                                                         9u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_SAVE_DISABLE_FVAL                                               0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_SAVE_ENABLE_FVAL                                                0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_RETAIN_BMSK                                                   0x100u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_RETAIN_SHFT                                                       8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_RETAIN_DISABLE_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_RETAIN_ENABLE_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_EN_REST_BMSK                                                   0x80u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_EN_REST_SHFT                                                      7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_EN_REST_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_EN_REST_ENABLE_FVAL                                             0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_EN_FEW_BMSK                                                    0x40u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_EN_FEW_SHFT                                                       6u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_EN_FEW_DISABLE_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_EN_FEW_ENABLE_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_CLAMP_IO_BMSK                                                  0x20u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_CLAMP_IO_SHFT                                                     5u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_CLAMP_IO_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_CLAMP_IO_ENABLE_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_CLK_DISABLE_BMSK                                               0x10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_CLK_DISABLE_SHFT                                                  4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_CLK_DISABLE_CLK_NOT_DISABLE_FVAL                                0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_CLK_DISABLE_CLK_IS_DISABLE_FVAL                                 0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_PD_ARES_BMSK                                                    0x8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_PD_ARES_SHFT                                                      3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_PD_ARES_NO_RESET_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_PD_ARES_RESET_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_SW_OVERRIDE_BMSK                                                0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_SW_OVERRIDE_SHFT                                                  2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_SW_OVERRIDE_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_SW_OVERRIDE_ENABLE_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_HW_CONTROL_BMSK                                                 0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_HW_CONTROL_SHFT                                                   1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_HW_CONTROL_DISABLE_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_HW_CONTROL_ENABLE_FVAL                                          0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_SW_COLLAPSE_BMSK                                                0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_SW_COLLAPSE_SHFT                                                  0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_SW_COLLAPSE_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_GDSCR_SW_COLLAPSE_ENABLE_FVAL                                         0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_ADDR                                                 (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0xc4u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_OFFS                                                 (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0xc4u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_RMSK                                                  0x3fffffful
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_GDSC_PWR_DWN_START_BMSK                               0x2000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_GDSC_PWR_DWN_START_SHFT                                      25u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_GDSC_PWR_UP_START_BMSK                                0x1000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_GDSC_PWR_UP_START_SHFT                                       24u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_GDSC_CFG_FSM_STATE_STATUS_BMSK                         0xf00000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_GDSC_CFG_FSM_STATE_STATUS_SHFT                               20u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_GDSC_MEM_PWR_ACK_STATUS_BMSK                            0x80000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_GDSC_MEM_PWR_ACK_STATUS_SHFT                                 19u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_GDSC_ENR_ACK_STATUS_BMSK                                0x40000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_GDSC_ENR_ACK_STATUS_SHFT                                     18u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_GDSC_ENF_ACK_STATUS_BMSK                                0x20000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_GDSC_ENF_ACK_STATUS_SHFT                                     17u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_GDSC_POWER_UP_COMPLETE_BMSK                             0x10000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_GDSC_POWER_UP_COMPLETE_SHFT                                  16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_GDSC_POWER_DOWN_COMPLETE_BMSK                            0x8000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_GDSC_POWER_DOWN_COMPLETE_SHFT                                15u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_SOFTWARE_CONTROL_OVERRIDE_BMSK                           0x7800u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_SOFTWARE_CONTROL_OVERRIDE_SHFT                               11u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_GDSC_HANDSHAKE_DIS_BMSK                                   0x400u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_GDSC_HANDSHAKE_DIS_SHFT                                      10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_GDSC_MEM_PERI_FORCE_IN_SW_BMSK                            0x200u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_GDSC_MEM_PERI_FORCE_IN_SW_SHFT                                9u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_GDSC_MEM_CORE_FORCE_IN_SW_BMSK                            0x100u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_GDSC_MEM_CORE_FORCE_IN_SW_SHFT                                8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_GDSC_PHASE_RESET_EN_SW_BMSK                                0x80u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_GDSC_PHASE_RESET_EN_SW_SHFT                                   7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_GDSC_PHASE_RESET_DELAY_COUNT_SW_BMSK                       0x60u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_GDSC_PHASE_RESET_DELAY_COUNT_SW_SHFT                          5u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_GDSC_PSCBC_PWR_DWN_SW_BMSK                                 0x10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_GDSC_PSCBC_PWR_DWN_SW_SHFT                                    4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_UNCLAMP_IO_SOFTWARE_OVERRIDE_BMSK                           0x8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_UNCLAMP_IO_SOFTWARE_OVERRIDE_SHFT                             3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_SAVE_RESTORE_SOFTWARE_OVERRIDE_BMSK                         0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_SAVE_RESTORE_SOFTWARE_OVERRIDE_SHFT                           2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_CLAMP_IO_SOFTWARE_OVERRIDE_BMSK                             0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_CLAMP_IO_SOFTWARE_OVERRIDE_SHFT                               1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_DISABLE_CLK_SOFTWARE_OVERRIDE_BMSK                          0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG_GDSCR_DISABLE_CLK_SOFTWARE_OVERRIDE_SHFT                            0u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG2_GDSCR_ADDR                                                (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0xc8u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG2_GDSCR_OFFS                                                (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0xc8u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG2_GDSCR_RMSK                                                   0x7fffful
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG2_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG2_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG2_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG2_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG2_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG2_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG2_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG2_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG2_GDSCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG2_GDSCR_GDSC_MEM_PWRUP_ACK_OVERRIDE_BMSK                       0x40000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG2_GDSCR_GDSC_MEM_PWRUP_ACK_OVERRIDE_SHFT                            18u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG2_GDSCR_GDSC_PWRDWN_ENABLE_ACK_OVERRIDE_BMSK                   0x20000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG2_GDSCR_GDSC_PWRDWN_ENABLE_ACK_OVERRIDE_SHFT                        17u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG2_GDSCR_GDSC_CLAMP_MEM_SW_BMSK                                 0x10000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG2_GDSCR_GDSC_CLAMP_MEM_SW_SHFT                                      16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG2_GDSCR_DLY_MEM_PWR_UP_BMSK                                     0xf000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG2_GDSCR_DLY_MEM_PWR_UP_SHFT                                         12u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG2_GDSCR_DLY_DEASSERT_CLAMP_MEM_BMSK                              0xf00u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG2_GDSCR_DLY_DEASSERT_CLAMP_MEM_SHFT                                  8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG2_GDSCR_DLY_ASSERT_CLAMP_MEM_BMSK                                 0xf0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG2_GDSCR_DLY_ASSERT_CLAMP_MEM_SHFT                                    4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG2_GDSCR_MEM_PWR_DWN_TIMEOUT_BMSK                                   0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG2_GDSCR_MEM_PWR_DWN_TIMEOUT_SHFT                                     0u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_ADDR                                                (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0xccu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_OFFS                                                (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0xccu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_RMSK                                                 0x7fffffful
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_STATUS_BMSK               0x4000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_STATUS_SHFT                      26u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_BMSK                            0x2000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_SHFT                                   25u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_DISABLE_FVAL                          0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_GDSC_ACCU_RED_ENABLE_ENABLE_FVAL                           0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_DLY_ACCU_RED_SHIFTER_DONE_BMSK                       0x1e00000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_DLY_ACCU_RED_SHIFTER_DONE_SHFT                              21u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_BMSK                        0x100000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_SHFT                              20u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_DISABLE_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_GDSC_ACCU_RED_TIMER_EN_SW_ENABLE_FVAL                      0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_BMSK               0x80000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_SHFT                    19u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_DISABLE_FVAL           0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_DONE_OVERRIDE_ENABLE_FVAL            0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_BMSK                   0x40000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_SHFT                        18u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_DISABLE_FVAL               0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_CLK_EN_SW_ENABLE_FVAL                0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_BMSK                    0x20000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_SHFT                         17u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_DISABLE_FVAL                0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_GDSC_ACCU_RED_SHIFTER_START_SW_ENABLE_FVAL                 0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_BMSK                         0x10000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_SHFT                              16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_DISABLE_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_GDSC_ACCU_RED_SW_OVERRIDE_ENABLE_FVAL                      0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_GDSC_SPARE_CTRL_IN_BMSK                                 0xff00u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_GDSC_SPARE_CTRL_IN_SHFT                                      8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_GDSC_SPARE_CTRL_OUT_BMSK                                  0xffu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG3_GDSCR_GDSC_SPARE_CTRL_OUT_SHFT                                     0u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG4_GDSCR_ADDR                                                (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0xd0u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG4_GDSCR_OFFS                                                (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0xd0u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG4_GDSCR_RMSK                                                  0xfffffful
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG4_GDSCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG4_GDSCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG4_GDSCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG4_GDSCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG4_GDSCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG4_GDSCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG4_GDSCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG4_GDSCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG4_GDSCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG4_GDSCR_DLY_UNCLAMPIO_BMSK                                    0xf00000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG4_GDSCR_DLY_UNCLAMPIO_SHFT                                          20u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG4_GDSCR_DLY_RESTOREFF_BMSK                                     0xf0000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG4_GDSCR_DLY_RESTOREFF_SHFT                                          16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG4_GDSCR_DLY_NORETAINFF_BMSK                                     0xf000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG4_GDSCR_DLY_NORETAINFF_SHFT                                         12u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG4_GDSCR_DLY_DEASSERTARES_BMSK                                    0xf00u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG4_GDSCR_DLY_DEASSERTARES_SHFT                                        8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG4_GDSCR_DLY_CLAMPIO_BMSK                                          0xf0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG4_GDSCR_DLY_CLAMPIO_SHFT                                             4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG4_GDSCR_DLY_RETAINFF_BMSK                                          0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CFG4_GDSCR_DLY_RETAINFF_SHFT                                            0u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_ADDR                                                      (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0xd4u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_OFFS                                                      (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0xd4u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_RMSK                                                      0x81c07ffful
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_CLK_OFF_BMSK                                              0x80000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_CLK_OFF_SHFT                                                      31u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_IGNORE_ALL_ARES_BMSK                                       0x1000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_IGNORE_ALL_ARES_SHFT                                              24u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                     0x800000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                           23u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_CLK_DIS_BMSK                                                0x400000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_CLK_DIS_SHFT                                                      22u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_FORCE_MEM_CORE_ON_BMSK                                        0x4000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_FORCE_MEM_CORE_ON_SHFT                                            14u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_FORCE_MEM_CORE_ON_FORCE_DISABLE_FVAL                             0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_FORCE_MEM_CORE_ON_FORCE_ENABLE_FVAL                              0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_FORCE_MEM_PERIPH_ON_BMSK                                      0x2000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_FORCE_MEM_PERIPH_ON_SHFT                                          13u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_FORCE_MEM_PERIPH_ON_FORCE_DISABLE_FVAL                           0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_FORCE_MEM_PERIPH_ON_FORCE_ENABLE_FVAL                            0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_FORCE_MEM_PERIPH_OFF_BMSK                                     0x1000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_FORCE_MEM_PERIPH_OFF_SHFT                                         12u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_DISABLE_FVAL                          0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_FORCE_MEM_PERIPH_OFF_FORCE_ENABLE_FVAL                           0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_WAKEUP_BMSK                                                    0xf00u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_WAKEUP_SHFT                                                        8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_WAKEUP_CLOCK0_FVAL                                               0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_WAKEUP_CLOCK1_FVAL                                               0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_WAKEUP_CLOCK2_FVAL                                               0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_WAKEUP_CLOCK3_FVAL                                               0x3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_WAKEUP_CLOCK4_FVAL                                               0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_WAKEUP_CLOCK5_FVAL                                               0x5u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_WAKEUP_CLOCK6_FVAL                                               0x6u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_WAKEUP_CLOCK7_FVAL                                               0x7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_WAKEUP_CLOCK8_FVAL                                               0x8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_WAKEUP_CLOCK9_FVAL                                               0x9u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_WAKEUP_CLOCK10_FVAL                                              0xau
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_WAKEUP_CLOCK11_FVAL                                              0xbu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_WAKEUP_CLOCK12_FVAL                                              0xcu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_WAKEUP_CLOCK13_FVAL                                              0xdu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_WAKEUP_CLOCK14_FVAL                                              0xeu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_WAKEUP_CLOCK15_FVAL                                              0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_SLEEP_BMSK                                                      0xf0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_SLEEP_SHFT                                                         4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_SLEEP_CLOCK0_FVAL                                                0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_SLEEP_CLOCK1_FVAL                                                0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_SLEEP_CLOCK2_FVAL                                                0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_SLEEP_CLOCK3_FVAL                                                0x3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_SLEEP_CLOCK4_FVAL                                                0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_SLEEP_CLOCK5_FVAL                                                0x5u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_SLEEP_CLOCK6_FVAL                                                0x6u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_SLEEP_CLOCK7_FVAL                                                0x7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_SLEEP_CLOCK8_FVAL                                                0x8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_SLEEP_CLOCK9_FVAL                                                0x9u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_SLEEP_CLOCK10_FVAL                                               0xau
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_SLEEP_CLOCK11_FVAL                                               0xbu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_SLEEP_CLOCK12_FVAL                                               0xcu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_SLEEP_CLOCK13_FVAL                                               0xdu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_SLEEP_CLOCK14_FVAL                                               0xeu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_SLEEP_CLOCK15_FVAL                                               0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_SW_ONLY_EN_BMSK                                                  0x8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_SW_ONLY_EN_SHFT                                                    3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_CLK_ARES_BMSK                                                    0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_CLK_ARES_SHFT                                                      2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_CLK_ARES_NO_RESET_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_CLK_ARES_RESET_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_HW_CTL_BMSK                                                      0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_HW_CTL_SHFT                                                        1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_HW_CTL_DISABLE_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_HW_CTL_ENABLE_FVAL                                               0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_CLK_ENABLE_BMSK                                                  0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_CLK_ENABLE_SHFT                                                    0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_CLK_ENABLE_DISABLE_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_CBCR_CLK_ENABLE_ENABLE_FVAL                                           0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_ADDR                                                     (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0xd8u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_OFFS                                                     (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0xd8u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_RMSK                                                     0xfffffffeul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_BMSK                           0xff000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SREG_PSCBC_SPARE_CTRL_OUT_SHFT                                   24u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SREG_PSCBC_SPARE_CTRL_IN_BMSK                              0xff0000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SREG_PSCBC_SPARE_CTRL_IN_SHFT                                    16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_IGNORE_GDSC_PWR_DWN_CSR_BMSK                                 0x8000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_IGNORE_GDSC_PWR_DWN_CSR_SHFT                                     15u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_IGNORE_GDSC_PWR_DWN_CSR_NO_IGNORE_FVAL                          0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_IGNORE_GDSC_PWR_DWN_CSR_IGNORE_FVAL                             0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_PSCBC_SLP_STG_MODE_CSR_BMSK                                  0x4000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_PSCBC_SLP_STG_MODE_CSR_SHFT                                      14u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_PSCBC_SLP_STG_MODE_CSR_SREG_PSCBC_MODE_FVAL                     0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_PSCBC_SLP_STG_MODE_CSR_PSCBC_SLP_STG_MODE_FVAL                  0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_MEM_CPH_RST_SW_OVERRIDE_BMSK                                 0x2000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_MEM_CPH_RST_SW_OVERRIDE_SHFT                                     13u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_MEM_CPH_RST_SW_OVERRIDE_NO_OVERRIDE_FVAL                        0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_MEM_CPH_RST_SW_OVERRIDE_OVERRIDE_FVAL                           0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_BMSK                             0x1000u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_SHFT                                 12u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_NO_RESET_FVAL                       0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SW_SM_PSCBC_SEQ_IN_OVERRIDE_RESET_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_MEM_CORE_ON_ACK_BMSK                                          0x800u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_MEM_CORE_ON_ACK_SHFT                                             11u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_MEM_PERIPH_ON_ACK_BMSK                                        0x400u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_MEM_PERIPH_ON_ACK_SHFT                                           10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SW_DIV_RATIO_SLP_STG_CLK_BMSK                                 0x300u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SW_DIV_RATIO_SLP_STG_CLK_SHFT                                     8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_1_FVAL                          0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_2_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_4_FVAL                          0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SW_DIV_RATIO_SLP_STG_CLK_DIV_BY_8_FVAL                          0x3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_MEM_CPH_ENABLE_BMSK                                            0x80u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_MEM_CPH_ENABLE_SHFT                                               7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_MEM_CPH_ENABLE_DISABLE_FVAL                                     0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_MEM_CPH_ENABLE_ENABLE_FVAL                                      0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_FORCE_CLK_ON_BMSK                                              0x40u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_FORCE_CLK_ON_SHFT                                                 6u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_FORCE_CLK_ON_NO_FORCE_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_FORCE_CLK_ON_FORCE_ENABLE_FVAL                                  0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SW_RST_SEL_SLP_STG_BMSK                                        0x20u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SW_RST_SEL_SLP_STG_SHFT                                           5u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_HARDWARE_ARES_FVAL                0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SW_RST_SEL_SLP_STG_SELECT_THE_SW_RST_SLP_STG_BIT_FVAL           0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SW_RST_SLP_STG_BMSK                                            0x10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SW_RST_SLP_STG_SHFT                                               4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SW_RST_SLP_STG_DE_ASSERTION_OF_THE_RESET_FVAL                   0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SW_RST_SLP_STG_ASSERTION_OF_THE_RESET_FVAL                      0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SW_CTRL_PWR_DOWN_BMSK                                           0x8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SW_CTRL_PWR_DOWN_SHFT                                             3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SW_CTRL_PWR_DOWN_NO_SW_CTRL_FVAL                                0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SW_CTRL_PWR_DOWN_SW_CTRL_FVAL                                   0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SW_CLK_EN_SEL_SLP_STG_BMSK                                      0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SW_CLK_EN_SEL_SLP_STG_SHFT                                        2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_HW_FSM_FVAL        0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SW_CLK_EN_SEL_SLP_STG_SLP_STG_CLK_GATE_CONTROLD_BY_SW_CLK_EN_SLP_STG_BIT_FVAL        0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SW_CLK_EN_SLP_STG_BMSK                                          0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SW_CLK_EN_SLP_STG_SHFT                                            1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_DISABLE_FVAL                    0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_SREGR_SW_CLK_EN_SLP_STG_SLP_STG_CLOCK_ENABLE_FVAL                     0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_DIV_CDIVR_ADDR                                                 (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0xdcu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_DIV_CDIVR_OFFS                                                 (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0xdcu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_DIV_CDIVR_RMSK                                                        0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_DIV_CDIVR_CLK_DIV_BMSK                                                0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_MVS1_DIV_CDIVR_CLK_DIV_SHFT                                                  0u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_INTERFACE_BCR_ADDR                                                  (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0xe8u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_INTERFACE_BCR_OFFS                                                  (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0xe8u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_INTERFACE_BCR_RMSK                                                         0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_INTERFACE_BCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_INTERFACE_BCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_INTERFACE_BCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_INTERFACE_BCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_INTERFACE_BCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_INTERFACE_BCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_INTERFACE_BCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_INTERFACE_BCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_INTERFACE_BCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_INTERFACE_BCR_BLK_ARES_BMSK                                                0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_INTERFACE_BCR_BLK_ARES_SHFT                                                  0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_INTERFACE_BCR_BLK_ARES_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_INTERFACE_BCR_BLK_ARES_ENABLE_FVAL                                         0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CBCR_ADDR                                                       (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0xecu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CBCR_OFFS                                                       (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0xecu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CBCR_RMSK                                                       0x81c0000eul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CBCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CBCR_CLK_OFF_BMSK                                               0x80000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CBCR_CLK_OFF_SHFT                                                       31u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CBCR_IGNORE_ALL_ARES_BMSK                                        0x1000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CBCR_IGNORE_ALL_ARES_SHFT                                               24u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                      0x800000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                            23u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CBCR_CLK_DIS_BMSK                                                 0x400000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CBCR_CLK_DIS_SHFT                                                       22u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CBCR_SW_ONLY_EN_BMSK                                                   0x8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CBCR_SW_ONLY_EN_SHFT                                                     3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CBCR_CLK_ARES_BMSK                                                     0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CBCR_CLK_ARES_SHFT                                                       2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CBCR_CLK_ARES_NO_RESET_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CBCR_CLK_ARES_RESET_FVAL                                               0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CBCR_HW_CTL_BMSK                                                       0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CBCR_HW_CTL_SHFT                                                         1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CBCR_HW_CTL_DISABLE_FVAL                                               0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_AHB_CBCR_HW_CTL_ENABLE_FVAL                                                0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_DIV_CDIVR_ADDR                                                (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0xf0u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_DIV_CDIVR_OFFS                                                (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0xf0u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_DIV_CDIVR_RMSK                                                       0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_DIV_CDIVR_CLK_DIV_BMSK                                               0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_DIV_CDIVR_CLK_DIV_SHFT                                                 0u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_CBCR_ADDR                                                     (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0xf4u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_CBCR_OFFS                                                     (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0xf4u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_CBCR_RMSK                                                     0x81c00005ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_CBCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_CBCR_CLK_OFF_BMSK                                             0x80000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_CBCR_CLK_OFF_SHFT                                                     31u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_CBCR_IGNORE_ALL_ARES_BMSK                                      0x1000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_CBCR_IGNORE_ALL_ARES_SHFT                                             24u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                    0x800000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                          23u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_CBCR_CLK_DIS_BMSK                                               0x400000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_CBCR_CLK_DIS_SHFT                                                     22u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_CBCR_CLK_ARES_BMSK                                                   0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_CBCR_CLK_ARES_SHFT                                                     2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_CBCR_CLK_ARES_NO_RESET_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_CBCR_CLK_ARES_RESET_FVAL                                             0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_CBCR_CLK_ENABLE_BMSK                                                 0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_CBCR_CLK_ENABLE_SHFT                                                   0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_CBCR_CLK_ENABLE_DISABLE_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_CBCR_CLK_ENABLE_ENABLE_FVAL                                          0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_DIV_CDIVR_ADDR                                             (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0xfcu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_DIV_CDIVR_OFFS                                             (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0xfcu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_DIV_CDIVR_RMSK                                                    0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_DIV_CDIVR_CLK_DIV_BMSK                                            0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_DIV_CDIVR_CLK_DIV_SHFT                                              0u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_CBCR_ADDR                                                  (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x100u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_CBCR_OFFS                                                  (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x100u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_CBCR_RMSK                                                  0x81c00005ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_CBCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_CBCR_CLK_OFF_BMSK                                          0x80000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_CBCR_CLK_OFF_SHFT                                                  31u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_CBCR_IGNORE_ALL_ARES_BMSK                                   0x1000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_CBCR_IGNORE_ALL_ARES_SHFT                                          24u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                 0x800000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                       23u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_CBCR_CLK_DIS_BMSK                                            0x400000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_CBCR_CLK_DIS_SHFT                                                  22u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_CBCR_CLK_ARES_BMSK                                                0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_CBCR_CLK_ARES_SHFT                                                  2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_CBCR_CLK_ARES_NO_RESET_FVAL                                       0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_CBCR_CLK_ARES_RESET_FVAL                                          0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_CBCR_CLK_ENABLE_BMSK                                              0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_CBCR_CLK_ENABLE_SHFT                                                0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_CBCR_CLK_ENABLE_DISABLE_FVAL                                      0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_CBCR_CLK_ENABLE_ENABLE_FVAL                                       0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_DIV_CDIVR_ADDR                                                   (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x108u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_DIV_CDIVR_OFFS                                                   (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x108u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_DIV_CDIVR_RMSK                                                          0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_DIV_CDIVR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_DIV_CDIVR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_DIV_CDIVR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_DIV_CDIVR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_DIV_CDIVR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_DIV_CDIVR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_DIV_CDIVR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_DIV_CDIVR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_DIV_CDIVR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_DIV_CDIVR_CLK_DIV_BMSK                                                  0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_DIV_CDIVR_CLK_DIV_SHFT                                                    0u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_OBS_CBCR_ADDR                                                    (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x10cu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_OBS_CBCR_OFFS                                                    (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x10cu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_OBS_CBCR_RMSK                                                    0x81c00005ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_OBS_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_OBS_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_OBS_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_OBS_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_OBS_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_OBS_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_OBS_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_OBS_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_OBS_CBCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_OBS_CBCR_CLK_OFF_BMSK                                            0x80000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_OBS_CBCR_CLK_OFF_SHFT                                                    31u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_OBS_CBCR_IGNORE_ALL_ARES_BMSK                                     0x1000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_OBS_CBCR_IGNORE_ALL_ARES_SHFT                                            24u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_OBS_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                   0x800000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_OBS_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                         23u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_OBS_CBCR_CLK_DIS_BMSK                                              0x400000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_OBS_CBCR_CLK_DIS_SHFT                                                    22u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_OBS_CBCR_CLK_ARES_BMSK                                                  0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_OBS_CBCR_CLK_ARES_SHFT                                                    2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_OBS_CBCR_CLK_ARES_NO_RESET_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_OBS_CBCR_CLK_ARES_RESET_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_OBS_CBCR_CLK_ENABLE_BMSK                                                0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_OBS_CBCR_CLK_ENABLE_SHFT                                                  0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_OBS_CBCR_CLK_ENABLE_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SM_OBS_CBCR_CLK_ENABLE_ENABLE_FVAL                                         0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CMD_RCGR_ADDR                                                    (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x110u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CMD_RCGR_OFFS                                                    (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x110u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CMD_RCGR_RMSK                                                    0x80000013ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CMD_RCGR_ROOT_OFF_BMSK                                           0x80000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CMD_RCGR_ROOT_OFF_SHFT                                                   31u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                           0x10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                              4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CMD_RCGR_ROOT_EN_BMSK                                                   0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CMD_RCGR_ROOT_EN_SHFT                                                     1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                            0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CMD_RCGR_UPDATE_BMSK                                                    0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CMD_RCGR_UPDATE_SHFT                                                      0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CMD_RCGR_UPDATE_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CMD_RCGR_UPDATE_ENABLE_FVAL                                             0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_ADDR                                                    (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x114u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_OFFS                                                    (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x114u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_RMSK                                                      0x11071ful
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_HW_CLK_CONTROL_BMSK                                       0x100000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_HW_CLK_CONTROL_SHFT                                             20u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                     0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_RCGLITE_DISABLE_BMSK                                       0x10000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_RCGLITE_DISABLE_SHFT                                            16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                           0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                          0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_SEL_BMSK                                                 0x700u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_SEL_SHFT                                                     8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_SEL_SRC0_FVAL                                              0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_SEL_SRC1_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_SEL_SRC2_FVAL                                              0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_SEL_SRC3_FVAL                                              0x3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_SEL_SRC4_FVAL                                              0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_SEL_SRC5_FVAL                                              0x5u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_SEL_SRC6_FVAL                                              0x6u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_SEL_SRC7_FVAL                                              0x7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_BMSK                                                  0x1fu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_SHFT                                                     0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_DIV1_FVAL                                              0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                            0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_DIV2_FVAL                                              0x3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                            0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_DIV3_FVAL                                              0x5u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                            0x6u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_DIV4_FVAL                                              0x7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                            0x8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_DIV5_FVAL                                              0x9u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                            0xau
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_DIV6_FVAL                                              0xbu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                            0xcu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_DIV7_FVAL                                              0xdu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                            0xeu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_DIV8_FVAL                                              0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                           0x10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_DIV9_FVAL                                             0x11u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                           0x12u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_DIV10_FVAL                                            0x13u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                          0x14u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_DIV11_FVAL                                            0x15u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                          0x16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_DIV12_FVAL                                            0x17u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                          0x18u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_DIV13_FVAL                                            0x19u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                          0x1au
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_DIV14_FVAL                                            0x1bu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                          0x1cu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_DIV15_FVAL                                            0x1du
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                          0x1eu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CFG_RCGR_SRC_DIV_DIV16_FVAL                                            0x1fu

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CBCR_ADDR                                                        (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x128u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CBCR_OFFS                                                        (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x128u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CBCR_RMSK                                                        0x81c00005ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CBCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CBCR_CLK_OFF_BMSK                                                0x80000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CBCR_CLK_OFF_SHFT                                                        31u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CBCR_IGNORE_ALL_ARES_BMSK                                         0x1000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CBCR_IGNORE_ALL_ARES_SHFT                                                24u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                       0x800000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                             23u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CBCR_CLK_DIS_BMSK                                                  0x400000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CBCR_CLK_DIS_SHFT                                                        22u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CBCR_CLK_ARES_BMSK                                                      0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CBCR_CLK_ARES_SHFT                                                        2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CBCR_CLK_ARES_NO_RESET_FVAL                                             0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CBCR_CLK_ARES_RESET_FVAL                                                0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CBCR_CLK_ENABLE_BMSK                                                    0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CBCR_CLK_ENABLE_SHFT                                                      0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CBCR_CLK_ENABLE_DISABLE_FVAL                                            0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_XO_CBCR_CLK_ENABLE_ENABLE_FVAL                                             0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CMD_RCGR_ADDR                                                 (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x12cu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CMD_RCGR_OFFS                                                 (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x12cu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CMD_RCGR_RMSK                                                 0x80000013ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CMD_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CMD_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CMD_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CMD_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CMD_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CMD_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CMD_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CMD_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CMD_RCGR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CMD_RCGR_ROOT_OFF_BMSK                                        0x80000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CMD_RCGR_ROOT_OFF_SHFT                                                31u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CMD_RCGR_DIRTY_CFG_RCGR_BMSK                                        0x10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CMD_RCGR_DIRTY_CFG_RCGR_SHFT                                           4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CMD_RCGR_ROOT_EN_BMSK                                                0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CMD_RCGR_ROOT_EN_SHFT                                                  1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CMD_RCGR_ROOT_EN_DISABLE_FVAL                                        0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CMD_RCGR_ROOT_EN_ENABLE_FVAL                                         0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CMD_RCGR_UPDATE_BMSK                                                 0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CMD_RCGR_UPDATE_SHFT                                                   0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CMD_RCGR_UPDATE_DISABLE_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CMD_RCGR_UPDATE_ENABLE_FVAL                                          0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_ADDR                                                 (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x130u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_OFFS                                                 (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x130u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_RMSK                                                   0x11071ful
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_HW_CLK_CONTROL_BMSK                                    0x100000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_HW_CLK_CONTROL_SHFT                                          20u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_HW_CLK_CONTROL_DISABLE_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_HW_CLK_CONTROL_ENABLE_FVAL                                  0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_RCGLITE_DISABLE_BMSK                                    0x10000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_RCGLITE_DISABLE_SHFT                                         16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_ENABLED_FVAL                        0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_RCGLITE_DISABLE_RCGLITE_DISABLED_FVAL                       0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_SEL_BMSK                                              0x700u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_SEL_SHFT                                                  8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_SEL_SRC0_FVAL                                           0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_SEL_SRC1_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_SEL_SRC2_FVAL                                           0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_SEL_SRC3_FVAL                                           0x3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_SEL_SRC4_FVAL                                           0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_SEL_SRC5_FVAL                                           0x5u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_SEL_SRC6_FVAL                                           0x6u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_SEL_SRC7_FVAL                                           0x7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_BMSK                                               0x1fu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_SHFT                                                  0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_BYPASS_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV1_FVAL                                           0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV1_5_FVAL                                         0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV2_FVAL                                           0x3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV2_5_FVAL                                         0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV3_FVAL                                           0x5u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV3_5_FVAL                                         0x6u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV4_FVAL                                           0x7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV4_5_FVAL                                         0x8u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV5_FVAL                                           0x9u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV5_5_FVAL                                         0xau
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV6_FVAL                                           0xbu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV6_5_FVAL                                         0xcu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV7_FVAL                                           0xdu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV7_5_FVAL                                         0xeu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV8_FVAL                                           0xfu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV8_5_FVAL                                        0x10u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV9_FVAL                                          0x11u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV9_5_FVAL                                        0x12u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV10_FVAL                                         0x13u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV10_5_FVAL                                       0x14u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV11_FVAL                                         0x15u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV11_5_FVAL                                       0x16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV12_FVAL                                         0x17u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV12_5_FVAL                                       0x18u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV13_FVAL                                         0x19u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV13_5_FVAL                                       0x1au
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV14_FVAL                                         0x1bu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV14_5_FVAL                                       0x1cu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV15_FVAL                                         0x1du
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV15_5_FVAL                                       0x1eu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CFG_RCGR_SRC_DIV_DIV16_FVAL                                         0x1fu

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CBCR_ADDR                                                     (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x144u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CBCR_OFFS                                                     (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x144u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CBCR_RMSK                                                     0x81c00005ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CBCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CBCR_CLK_OFF_BMSK                                             0x80000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CBCR_CLK_OFF_SHFT                                                     31u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CBCR_IGNORE_ALL_ARES_BMSK                                      0x1000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CBCR_IGNORE_ALL_ARES_SHFT                                             24u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                    0x800000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                          23u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CBCR_CLK_DIS_BMSK                                               0x400000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CBCR_CLK_DIS_SHFT                                                     22u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CBCR_CLK_ARES_BMSK                                                   0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CBCR_CLK_ARES_SHFT                                                     2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CBCR_CLK_ARES_NO_RESET_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CBCR_CLK_ARES_RESET_FVAL                                             0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CBCR_CLK_ENABLE_BMSK                                                 0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CBCR_CLK_ENABLE_SHFT                                                   0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CBCR_CLK_ENABLE_DISABLE_FVAL                                         0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SLEEP_CBCR_CLK_ENABLE_ENABLE_FVAL                                          0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_LOCK_MONITOR_CBCR_ADDR                                          (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x1000u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_LOCK_MONITOR_CBCR_OFFS                                          (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x1000u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_LOCK_MONITOR_CBCR_RMSK                                          0x81c00005ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_LOCK_MONITOR_CBCR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_LOCK_MONITOR_CBCR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_LOCK_MONITOR_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_LOCK_MONITOR_CBCR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_LOCK_MONITOR_CBCR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_LOCK_MONITOR_CBCR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_LOCK_MONITOR_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_LOCK_MONITOR_CBCR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_LOCK_MONITOR_CBCR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_LOCK_MONITOR_CBCR_CLK_OFF_BMSK                                  0x80000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_LOCK_MONITOR_CBCR_CLK_OFF_SHFT                                          31u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_LOCK_MONITOR_CBCR_IGNORE_ALL_ARES_BMSK                           0x1000000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_LOCK_MONITOR_CBCR_IGNORE_ALL_ARES_SHFT                                  24u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_LOCK_MONITOR_CBCR_IGNORE_ALL_CLK_DIS_BMSK                         0x800000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_LOCK_MONITOR_CBCR_IGNORE_ALL_CLK_DIS_SHFT                               23u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_LOCK_MONITOR_CBCR_CLK_DIS_BMSK                                    0x400000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_LOCK_MONITOR_CBCR_CLK_DIS_SHFT                                          22u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_LOCK_MONITOR_CBCR_CLK_ARES_BMSK                                        0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_LOCK_MONITOR_CBCR_CLK_ARES_SHFT                                          2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_LOCK_MONITOR_CBCR_CLK_ARES_NO_RESET_FVAL                               0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_LOCK_MONITOR_CBCR_CLK_ARES_RESET_FVAL                                  0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_LOCK_MONITOR_CBCR_CLK_ENABLE_BMSK                                      0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_LOCK_MONITOR_CBCR_CLK_ENABLE_SHFT                                        0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_LOCK_MONITOR_CBCR_CLK_ENABLE_DISABLE_FVAL                              0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_LOCK_MONITOR_CBCR_CLK_ENABLE_ENABLE_FVAL                               0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_MUX_MUXR_ADDR                                                 (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x1a4cu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_MUX_MUXR_OFFS                                                 (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x1a4cu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_MUX_MUXR_RMSK                                                       0x3fu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_MUX_MUXR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_MUX_MUXR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_MUX_MUXR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_MUX_MUXR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_MUX_MUXR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_MUX_MUXR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_MUX_MUXR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_MUX_MUXR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_MUX_MUXR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_MUX_MUXR_MUX_SEL_BMSK                                               0x3fu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_MUX_MUXR_MUX_SEL_SHFT                                                  0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_MUX_MUXR_MUX_SEL_VIDEO_CC_MVS0C_CLK_FVAL                             0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_MUX_MUXR_MUX_SEL_VIDEO_CC_MVS0C_SLP_STG_CLK_FVAL                     0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_MUX_MUXR_MUX_SEL_VIDEO_CC_MVS0_CLK_FVAL                              0x3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_MUX_MUXR_MUX_SEL_VIDEO_CC_MVS0_SLP_STG_CLK_FVAL                      0x4u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_MUX_MUXR_MUX_SEL_VIDEO_CC_MVS1_CLK_FVAL                              0x5u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_MUX_MUXR_MUX_SEL_VIDEO_CC_MVS1_SLP_STG_CLK_FVAL                      0x6u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_MUX_MUXR_MUX_SEL_VIDEO_CC_AHB_CLK_FVAL                               0x7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_MUX_MUXR_MUX_SEL_VIDEO_CC_MVS1C_CLK_FVAL                             0x9u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_MUX_MUXR_MUX_SEL_VIDEO_CC_MVS1C_SLP_STG_CLK_FVAL                     0xau
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_MUX_MUXR_MUX_SEL_VIDEO_CC_XO_CLK_FVAL                                0xbu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_MUX_MUXR_MUX_SEL_VIDEO_CC_SLEEP_CLK_FVAL                             0xcu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_DEBUG_MUX_MUXR_MUX_SEL_VIDEO_CC_PLL_LOCK_MONITOR_CLK_FVAL                  0xeu

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE_ADDR                                                          (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x1f04u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE_OFFS                                                          (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x1f04u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE_RMSK                                                          0xfffffffful
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE_RESERVE_BITS31_1_BMSK                                         0xfffffffeul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE_RESERVE_BITS31_1_SHFT                                                  1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE_DEBUG_BUS_DISABLE_BMSK                                               0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE_DEBUG_BUS_DISABLE_SHFT                                                 0u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE1_ADDR                                                         (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x1f24u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE1_OFFS                                                         (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x1f24u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE1_RMSK                                                         0xfffffffful
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE1_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE1_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE1_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE1_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE1_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE1_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE1_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE1_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE1_SPARE1_CTRL_OUT_BMSK                                         0xffff0000ul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE1_SPARE1_CTRL_OUT_SHFT                                                 16u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE1_SPARE1_CTRL_IN_BMSK                                              0xffffu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_SPARE1_SPARE1_CTRL_IN_SHFT                                                   0u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_MUX_MUXR_ADDR                                              (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x1f44u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_MUX_MUXR_OFFS                                              (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x1f44u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_MUX_MUXR_RMSK                                                     0x7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_MUX_MUXR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_MUX_MUXR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_MUX_MUXR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_MUX_MUXR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_MUX_MUXR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_MUX_MUXR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_MUX_MUXR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_MUX_MUXR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_MUX_MUXR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_MUX_MUXR_MUX_SEL_BMSK                                             0x7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_MUX_MUXR_MUX_SEL_SHFT                                               0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_MUX_MUXR_MUX_SEL_VIDEO_PLL0_TEST_FVAL                             0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_TEST_MUX_MUXR_MUX_SEL_VIDEO_PLL1_TEST_FVAL                             0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_RESET_N_MUXR_ADDR                                               (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x1f48u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_RESET_N_MUXR_OFFS                                               (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x1f48u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_RESET_N_MUXR_RMSK                                                      0x7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_RESET_N_MUXR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_RESET_N_MUXR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_RESET_N_MUXR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_RESET_N_MUXR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_RESET_N_MUXR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_RESET_N_MUXR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_RESET_N_MUXR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_RESET_N_MUXR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_RESET_N_MUXR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_RESET_N_MUXR_MUX_SEL_BMSK                                              0x7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_RESET_N_MUXR_MUX_SEL_SHFT                                                0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_RESET_N_MUXR_MUX_SEL_VIDEO_PLL0_RESET_N_FVAL                           0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_RESET_N_MUXR_MUX_SEL_VIDEO_PLL1_RESET_N_FVAL                           0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_STATUS_MUXR_ADDR                                                (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x1f4cu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_STATUS_MUXR_OFFS                                                (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x1f4cu)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_STATUS_MUXR_RMSK                                                       0x7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_STATUS_MUXR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_STATUS_MUXR_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_STATUS_MUXR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_STATUS_MUXR_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_STATUS_MUXR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_STATUS_MUXR_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_STATUS_MUXR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_STATUS_MUXR_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_STATUS_MUXR_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_STATUS_MUXR_MUX_SEL_BMSK                                               0x7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_STATUS_MUXR_MUX_SEL_SHFT                                                 0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_STATUS_MUXR_MUX_SEL_ZERO_FVAL                                          0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_STATUS_MUXR_MUX_SEL_VIDEO_PLL0_STATUS_FVAL                             0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_STATUS_MUXR_MUX_SEL_VIDEO_PLL1_STATUS_FVAL                             0x2u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_STATUS_MUXR_MUX_SEL_RST_CTL_STATUS31_0_FVAL                            0x3u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL_STATUS_MUXR_MUX_SEL_RST_CTL_STATUS63_32_FVAL                           0x4u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL0_PLL_LOCK_MONITOR_CTL_ADDR                                      (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x2004u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL0_PLL_LOCK_MONITOR_CTL_OFFS                                      (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x2004u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL0_PLL_LOCK_MONITOR_CTL_RMSK                                         0x1fffful
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL0_PLL_LOCK_MONITOR_CTL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL0_PLL_LOCK_MONITOR_CTL_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL0_PLL_LOCK_MONITOR_CTL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL0_PLL_LOCK_MONITOR_CTL_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL0_PLL_LOCK_MONITOR_CTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL0_PLL_LOCK_MONITOR_CTL_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL0_PLL_LOCK_MONITOR_CTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL0_PLL_LOCK_MONITOR_CTL_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL0_PLL_LOCK_MONITOR_CTL_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL0_PLL_LOCK_MONITOR_CTL_REF_TIME_OUT_BMSK                            0x1fffeul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL0_PLL_LOCK_MONITOR_CTL_REF_TIME_OUT_SHFT                                  1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL0_PLL_LOCK_MONITOR_CTL_LOSS_OF_PLL_LOCK_FEATURE_EN_BMSK                 0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL0_PLL_LOCK_MONITOR_CTL_LOSS_OF_PLL_LOCK_FEATURE_EN_SHFT                   0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL0_PLL_LOCK_MONITOR_CTL_LOSS_OF_PLL_LOCK_FEATURE_EN_DISABLE_FVAL         0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL0_PLL_LOCK_MONITOR_CTL_LOSS_OF_PLL_LOCK_FEATURE_EN_ENABLE_FVAL          0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL1_PLL_LOCK_MONITOR_CTL_ADDR                                      (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x2008u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL1_PLL_LOCK_MONITOR_CTL_OFFS                                      (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x2008u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL1_PLL_LOCK_MONITOR_CTL_RMSK                                         0x1fffful
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL1_PLL_LOCK_MONITOR_CTL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL1_PLL_LOCK_MONITOR_CTL_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL1_PLL_LOCK_MONITOR_CTL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL1_PLL_LOCK_MONITOR_CTL_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL1_PLL_LOCK_MONITOR_CTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL1_PLL_LOCK_MONITOR_CTL_ADDR,v)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL1_PLL_LOCK_MONITOR_CTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL1_PLL_LOCK_MONITOR_CTL_ADDR,m,v,HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL1_PLL_LOCK_MONITOR_CTL_IN)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL1_PLL_LOCK_MONITOR_CTL_REF_TIME_OUT_BMSK                            0x1fffeul
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL1_PLL_LOCK_MONITOR_CTL_REF_TIME_OUT_SHFT                                  1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL1_PLL_LOCK_MONITOR_CTL_LOSS_OF_PLL_LOCK_FEATURE_EN_BMSK                 0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL1_PLL_LOCK_MONITOR_CTL_LOSS_OF_PLL_LOCK_FEATURE_EN_SHFT                   0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL1_PLL_LOCK_MONITOR_CTL_LOSS_OF_PLL_LOCK_FEATURE_EN_DISABLE_FVAL         0x0u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_PLL1_PLL_LOCK_MONITOR_CTL_LOSS_OF_PLL_LOCK_FEATURE_EN_ENABLE_FVAL          0x1u

#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_FUSA_STATUS_REGISTER_ADDR                                           (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE      + 0x3000u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_FUSA_STATUS_REGISTER_OFFS                                           (SAIL_TO_MD_CVP_VIDEO_CC_VIDEO_CC_VIDEO_CC_REG_REG_BASE_OFFS + 0x3000u)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_FUSA_STATUS_REGISTER_RMSK                                               0x1fffu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_FUSA_STATUS_REGISTER_IN                    \
                in_dword(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_FUSA_STATUS_REGISTER_ADDR)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_FUSA_STATUS_REGISTER_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_CVP_VIDEO_CC_FUSA_STATUS_REGISTER_ADDR, m)
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_FUSA_STATUS_REGISTER_HPCNT_BMSK                                         0x1f80u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_FUSA_STATUS_REGISTER_HPCNT_SHFT                                              7u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_FUSA_STATUS_REGISTER_VPCNT_BMSK                                           0x7eu
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_FUSA_STATUS_REGISTER_VPCNT_SHFT                                              1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_FUSA_STATUS_REGISTER_FLT_BMSK                                              0x1u
#define HWIO_SAIL_TO_MD_CVP_VIDEO_CC_FUSA_STATUS_REGISTER_FLT_SHFT                                                0u


#endif /* __G_SAIL_TO_MD_VIDEO_CC_HWIO_H__ */
