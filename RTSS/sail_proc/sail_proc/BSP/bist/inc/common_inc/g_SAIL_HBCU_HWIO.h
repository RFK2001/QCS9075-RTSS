#ifndef __G_SAIL_HBCU_HWIO_H__
#define __G_SAIL_HBCU_HWIO_H__
/*
===========================================================================
*/
/**
    @file g_SAIL_HBCU_HWIO.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        SA8775P (LeMansAU) [lemansau_v1.0_p3q2r72_BTO]
 
    This file contains HWIO register definitions for the following modules:
        SAILSS_HBCU_HBCU


    Generation parameters: 
    { 'filename': 'g_SAIL_HBCU_HWIO.h',
      'integer-qualifiers': True,
      'modules': ['SAILSS_HBCU_HBCU'],
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

    $Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/bist/inc/common_inc/g_SAIL_HBCU_HWIO.h#1 $
    $DateTime: 2025/02/01 11:39:23 $
    $Author: smarru $

    ===========================================================================
*/

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_HBCU_HBCU
 *--------------------------------------------------------------------------*/

#define SAILSS_HBCU_HBCU_REG_BASE                                                                                  (SAILSS_HBCU_HBCU_BASE      + 0x00000000u)
#define SAILSS_HBCU_HBCU_REG_BASE_SIZE                                                                             0x20000ul
#define SAILSS_HBCU_HBCU_REG_BASE_USED                                                                             0x1104u
#define SAILSS_HBCU_HBCU_REG_BASE_OFFS                                                                             0x00000000u

#define HWIO_SAILSS_HBCU_HBCU_VERSION_ADDR                                                                         (SAILSS_HBCU_HBCU_REG_BASE      + 0x0u)
#define HWIO_SAILSS_HBCU_HBCU_VERSION_OFFS                                                                         (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x0u)
#define HWIO_SAILSS_HBCU_HBCU_VERSION_RMSK                                                                           0xfffffful
#define HWIO_SAILSS_HBCU_HBCU_VERSION_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_VERSION_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_VERSION_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_VERSION_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_VERSION_MAJOR_VER_BMSK                                                                 0xff0000ul
#define HWIO_SAILSS_HBCU_HBCU_VERSION_MAJOR_VER_SHFT                                                                       16u
#define HWIO_SAILSS_HBCU_HBCU_VERSION_MINOR_VER_BMSK                                                                   0xff00u
#define HWIO_SAILSS_HBCU_HBCU_VERSION_MINOR_VER_SHFT                                                                        8u
#define HWIO_SAILSS_HBCU_HBCU_VERSION_STEP_VER_BMSK                                                                      0xffu
#define HWIO_SAILSS_HBCU_HBCU_VERSION_STEP_VER_SHFT                                                                         0u

#define HWIO_SAILSS_HBCU_HBCU_SEQ_EN_ADDR                                                                          (SAILSS_HBCU_HBCU_REG_BASE      + 0x4u)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_EN_OFFS                                                                          (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x4u)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_EN_RMSK                                                                                 0x1u
#define HWIO_SAILSS_HBCU_HBCU_SEQ_EN_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SEQ_EN_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SEQ_EN_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_HBCU_HBCU_SEQ_EN_ADDR,v)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_SEQ_EN_ADDR,m,v,HWIO_SAILSS_HBCU_HBCU_SEQ_EN_IN)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_EN_SEQUENCER_ENABLE_BMSK                                                                0x1u
#define HWIO_SAILSS_HBCU_HBCU_SEQ_EN_SEQUENCER_ENABLE_SHFT                                                                  0u
#define HWIO_SAILSS_HBCU_HBCU_SEQ_EN_SEQUENCER_ENABLE_DISABLE_FVAL                                                        0x0u
#define HWIO_SAILSS_HBCU_HBCU_SEQ_EN_SEQUENCER_ENABLE_ENABLE_FVAL                                                         0x1u

#define HWIO_SAILSS_HBCU_HBCU_SHSS_RST_CTL_ADDR                                                                    (SAILSS_HBCU_HBCU_REG_BASE      + 0x8u)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_RST_CTL_OFFS                                                                    (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x8u)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_RST_CTL_RMSK                                                                    0x80000001ul
#define HWIO_SAILSS_HBCU_HBCU_SHSS_RST_CTL_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_RST_CTL_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_RST_CTL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SHSS_RST_CTL_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_RST_CTL_OUT(v)            \
                out_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_RST_CTL_ADDR,v)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_RST_CTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_SHSS_RST_CTL_ADDR,m,v,HWIO_SAILSS_HBCU_HBCU_SHSS_RST_CTL_IN)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_RST_CTL_SHS_SRV_RST_CTRL_OVERRIDE_BMSK                                          0x80000000ul
#define HWIO_SAILSS_HBCU_HBCU_SHSS_RST_CTL_SHS_SRV_RST_CTRL_OVERRIDE_SHFT                                                  31u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_RST_CTL_SHS_SRV_RST_CTRL_OVERRIDE_SHS_SRV_RST_CTRL_OVERRIDE_DISABLE_FVAL               0x0u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_RST_CTL_SHS_SRV_RST_CTRL_OVERRIDE_SHS_SRV_RST_CTRL_OVERRIDE_ENABLE_FVAL                0x1u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_RST_CTL_SHS_SERVER_RESET_N_BMSK                                                        0x1u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_RST_CTL_SHS_SERVER_RESET_N_SHFT                                                          0u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_RST_CTL_SHS_SERVER_RESET_N_SHS_SERVER_IS_IN_RESET_STATE_FVAL                           0x0u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_RST_CTL_SHS_SERVER_RESET_N_SHS_SERVER_IS_IN_OPERATION_MODE_FVAL                        0x1u

#define HWIO_SAILSS_HBCU_HBCU_SHSS_CLK_CTL_ADDR                                                                    (SAILSS_HBCU_HBCU_REG_BASE      + 0xcu)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_CLK_CTL_OFFS                                                                    (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0xcu)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_CLK_CTL_RMSK                                                                    0x8000000ful
#define HWIO_SAILSS_HBCU_HBCU_SHSS_CLK_CTL_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_CLK_CTL_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_CLK_CTL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SHSS_CLK_CTL_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_CLK_CTL_OUT(v)            \
                out_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_CLK_CTL_ADDR,v)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_CLK_CTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_SHSS_CLK_CTL_ADDR,m,v,HWIO_SAILSS_HBCU_HBCU_SHSS_CLK_CTL_IN)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_CLK_CTL_SHS_SRV_CLK_CTRL_OVERRIDE_BMSK                                          0x80000000ul
#define HWIO_SAILSS_HBCU_HBCU_SHSS_CLK_CTL_SHS_SRV_CLK_CTRL_OVERRIDE_SHFT                                                  31u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_CLK_CTL_SHS_SRV_CLK_CTRL_OVERRIDE_SHS_SRV_CLK_CTRL_OVERRIDE_DISABLE_FVAL               0x0u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_CLK_CTL_SHS_SRV_CLK_CTRL_OVERRIDE_SHS_SRV_CLK_CTRL_OVERRIDE_ENABLE_FVAL                0x1u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_CLK_CTL_SHS_SERVER_CLOCK_CONTROL_BMSK                                                  0xfu
#define HWIO_SAILSS_HBCU_HBCU_SHSS_CLK_CTL_SHS_SERVER_CLOCK_CONTROL_SHFT                                                    0u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_CLK_CTL_SHS_SERVER_CLOCK_CONTROL_SHS_SERVER_CLOCK_DISABLED_FVAL                        0x5u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_CLK_CTL_SHS_SERVER_CLOCK_CONTROL_SHS_SERVER_CLOCK_ENABLED_FVAL                         0xau

#define HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_ABORT_ADDR                                                                (SAILSS_HBCU_HBCU_REG_BASE      + 0x10u)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_ABORT_OFFS                                                                (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x10u)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_ABORT_RMSK                                                                       0x1u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_ABORT_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_ABORT_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_ABORT_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_ABORT_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_ABORT_OUT(v)            \
                out_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_ABORT_ADDR,v)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_ABORT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_ABORT_ADDR,m,v,HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_ABORT_IN)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_ABORT_LBIST_ABORT_BMSK                                                           0x1u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_ABORT_LBIST_ABORT_SHFT                                                             0u

#define HWIO_SAILSS_HBCU_HBCU_SHSS_TIMEOUT_CNT_STRAP_ADDR                                                          (SAILSS_HBCU_HBCU_REG_BASE      + 0x14u)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_TIMEOUT_CNT_STRAP_OFFS                                                          (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x14u)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_TIMEOUT_CNT_STRAP_RMSK                                                                0x1fu
#define HWIO_SAILSS_HBCU_HBCU_SHSS_TIMEOUT_CNT_STRAP_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_TIMEOUT_CNT_STRAP_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_TIMEOUT_CNT_STRAP_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SHSS_TIMEOUT_CNT_STRAP_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_TIMEOUT_CNT_STRAP_OUT(v)            \
                out_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_TIMEOUT_CNT_STRAP_ADDR,v)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_TIMEOUT_CNT_STRAP_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_SHSS_TIMEOUT_CNT_STRAP_ADDR,m,v,HWIO_SAILSS_HBCU_HBCU_SHSS_TIMEOUT_CNT_STRAP_IN)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_TIMEOUT_CNT_STRAP_TIMEOUT_CNT_STRAP_BMSK                                              0x1fu
#define HWIO_SAILSS_HBCU_HBCU_SHSS_TIMEOUT_CNT_STRAP_TIMEOUT_CNT_STRAP_SHFT                                                 0u

#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MODE_ADDR                                                                   (SAILSS_HBCU_HBCU_REG_BASE      + 0x18u)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MODE_OFFS                                                                   (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x18u)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MODE_RMSK                                                                          0x3u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MODE_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MODE_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MODE_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MODE_ADDR,v)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MODE_ADDR,m,v,HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MODE_IN)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MODE_AIT_MODE_BMSK                                                                 0x3u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MODE_AIT_MODE_SHFT                                                                   0u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MODE_AIT_MODE_AIT_MODE_FVAL                                                        0x0u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MODE_AIT_MODE_DEBUG_MODE_FVAL                                                      0x2u

#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_DATA_VALID_ADDR                                                             (SAILSS_HBCU_HBCU_REG_BASE      + 0x1cu)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_DATA_VALID_OFFS                                                             (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x1cu)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_DATA_VALID_RMSK                                                                    0x1u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_DATA_VALID_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_DATA_VALID_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_DATA_VALID_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_DATA_VALID_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_DATA_VALID_OUT(v)            \
                out_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_DATA_VALID_ADDR,v)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_DATA_VALID_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_DATA_VALID_ADDR,m,v,HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_DATA_VALID_IN)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_DATA_VALID_AIT_DATA_VALID_BMSK                                                     0x1u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_DATA_VALID_AIT_DATA_VALID_SHFT                                                       0u

#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_IVI_PATTERN_START_ADDR_b_ADDR(b)                                        (SAILSS_HBCU_HBCU_REG_BASE      + 0X20 + (0x4*(b)))
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_IVI_PATTERN_START_ADDR_b_OFFS(b)                                        (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0X20 + (0x4*(b)))
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_IVI_PATTERN_START_ADDR_b_RMSK                                               0xffffu
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_IVI_PATTERN_START_ADDR_b_MAXb                                                    3u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_IVI_PATTERN_START_ADDR_b_INI(b)                \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_IVI_PATTERN_START_ADDR_b_ADDR(b), HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_IVI_PATTERN_START_ADDR_b_RMSK)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_IVI_PATTERN_START_ADDR_b_INMI(b,mask)        \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_IVI_PATTERN_START_ADDR_b_ADDR(b), mask)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_IVI_PATTERN_START_ADDR_b_OUTI(b,val)        \
                out_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_IVI_PATTERN_START_ADDR_b_ADDR(b),val)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_IVI_PATTERN_START_ADDR_b_OUTMI(b,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_IVI_PATTERN_START_ADDR_b_ADDR(b),mask,val,HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_IVI_PATTERN_START_ADDR_b_INI(b))
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_IVI_PATTERN_START_ADDR_b_AIT_MEM_IVI_PATTERN_START_ADDR_BMSK                0xffffu
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_IVI_PATTERN_START_ADDR_b_AIT_MEM_IVI_PATTERN_START_ADDR_SHFT                     0u

#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_ADAS_PATTERN_START_ADDR_b_ADDR(b)                                       (SAILSS_HBCU_HBCU_REG_BASE      + 0X30 + (0x4*(b)))
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_ADAS_PATTERN_START_ADDR_b_OFFS(b)                                       (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0X30 + (0x4*(b)))
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_ADAS_PATTERN_START_ADDR_b_RMSK                                              0xffffu
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_ADAS_PATTERN_START_ADDR_b_MAXb                                                   3u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_ADAS_PATTERN_START_ADDR_b_INI(b)                \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_ADAS_PATTERN_START_ADDR_b_ADDR(b), HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_ADAS_PATTERN_START_ADDR_b_RMSK)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_ADAS_PATTERN_START_ADDR_b_INMI(b,mask)        \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_ADAS_PATTERN_START_ADDR_b_ADDR(b), mask)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_ADAS_PATTERN_START_ADDR_b_OUTI(b,val)        \
                out_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_ADAS_PATTERN_START_ADDR_b_ADDR(b),val)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_ADAS_PATTERN_START_ADDR_b_OUTMI(b,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_ADAS_PATTERN_START_ADDR_b_ADDR(b),mask,val,HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_ADAS_PATTERN_START_ADDR_b_INI(b))
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_ADAS_PATTERN_START_ADDR_b_AIT_MEM_ADAS_PATTERN_START_ADDR_BMSK              0xffffu
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_ADAS_PATTERN_START_ADDR_b_AIT_MEM_ADAS_PATTERN_START_ADDR_SHFT                   0u

#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_EXIT_PATTERN_START_ADDR_b_ADDR(b)                                       (SAILSS_HBCU_HBCU_REG_BASE      + 0X40 + (0x4*(b)))
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_EXIT_PATTERN_START_ADDR_b_OFFS(b)                                       (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0X40 + (0x4*(b)))
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_EXIT_PATTERN_START_ADDR_b_RMSK                                              0xffffu
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_EXIT_PATTERN_START_ADDR_b_MAXb                                                   3u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_EXIT_PATTERN_START_ADDR_b_INI(b)                \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_EXIT_PATTERN_START_ADDR_b_ADDR(b), HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_EXIT_PATTERN_START_ADDR_b_RMSK)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_EXIT_PATTERN_START_ADDR_b_INMI(b,mask)        \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_EXIT_PATTERN_START_ADDR_b_ADDR(b), mask)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_EXIT_PATTERN_START_ADDR_b_OUTI(b,val)        \
                out_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_EXIT_PATTERN_START_ADDR_b_ADDR(b),val)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_EXIT_PATTERN_START_ADDR_b_OUTMI(b,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_EXIT_PATTERN_START_ADDR_b_ADDR(b),mask,val,HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_EXIT_PATTERN_START_ADDR_b_INI(b))
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_EXIT_PATTERN_START_ADDR_b_AIT_MEM_EXIT_PATTERN_START_ADDR_BMSK              0xffffu
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_MEM_EXIT_PATTERN_START_ADDR_b_AIT_MEM_EXIT_PATTERN_START_ADDR_SHFT                   0u

#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_BYPASS_MODE_ADDR                                                            (SAILSS_HBCU_HBCU_REG_BASE      + 0x50u)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_BYPASS_MODE_OFFS                                                            (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x50u)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_BYPASS_MODE_RMSK                                                                   0x1u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_BYPASS_MODE_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_BYPASS_MODE_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_BYPASS_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_BYPASS_MODE_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_BYPASS_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_BYPASS_MODE_ADDR,v)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_BYPASS_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_BYPASS_MODE_ADDR,m,v,HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_BYPASS_MODE_IN)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_BYPASS_MODE_AIT_BYPASS_MODE_BMSK                                                   0x1u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_AIT_BYPASS_MODE_AIT_BYPASS_MODE_SHFT                                                     0u

#define HWIO_SAILSS_HBCU_HBCU_SHSS_WSO_COMPARE_STATUS_0_ADDR                                                       (SAILSS_HBCU_HBCU_REG_BASE      + 0x54u)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_WSO_COMPARE_STATUS_0_OFFS                                                       (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x54u)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_WSO_COMPARE_STATUS_0_RMSK                                                       0xfffffffful
#define HWIO_SAILSS_HBCU_HBCU_SHSS_WSO_COMPARE_STATUS_0_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_WSO_COMPARE_STATUS_0_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_WSO_COMPARE_STATUS_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SHSS_WSO_COMPARE_STATUS_0_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_WSO_COMPARE_STATUS_0_WSO_COMPARE_STATUS_0_BMSK                                  0xfffffffful
#define HWIO_SAILSS_HBCU_HBCU_SHSS_WSO_COMPARE_STATUS_0_WSO_COMPARE_STATUS_0_SHFT                                           0u

#define HWIO_SAILSS_HBCU_HBCU_SHSS_WSO_COMPARE_STATUS_1_ADDR                                                       (SAILSS_HBCU_HBCU_REG_BASE      + 0x58u)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_WSO_COMPARE_STATUS_1_OFFS                                                       (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x58u)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_WSO_COMPARE_STATUS_1_RMSK                                                            0xfffu
#define HWIO_SAILSS_HBCU_HBCU_SHSS_WSO_COMPARE_STATUS_1_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_WSO_COMPARE_STATUS_1_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_WSO_COMPARE_STATUS_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SHSS_WSO_COMPARE_STATUS_1_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_WSO_COMPARE_STATUS_1_WSO_COMPARE_STATUS_1_BMSK                                       0xfffu
#define HWIO_SAILSS_HBCU_HBCU_SHSS_WSO_COMPARE_STATUS_1_WSO_COMPARE_STATUS_1_SHFT                                           0u

#define HWIO_SAILSS_HBCU_HBCU_SHSS_WSO_COMPARE_STATUS_READY_ADDR                                                   (SAILSS_HBCU_HBCU_REG_BASE      + 0x5cu)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_WSO_COMPARE_STATUS_READY_OFFS                                                   (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x5cu)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_WSO_COMPARE_STATUS_READY_RMSK                                                          0x1u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_WSO_COMPARE_STATUS_READY_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_WSO_COMPARE_STATUS_READY_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_WSO_COMPARE_STATUS_READY_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SHSS_WSO_COMPARE_STATUS_READY_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_WSO_COMPARE_STATUS_READY_WSO_COMPARE_STATUS_READY_BMSK                                 0x1u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_WSO_COMPARE_STATUS_READY_WSO_COMPARE_STATUS_READY_SHFT                                   0u

#define HWIO_SAILSS_HBCU_HBCU_SHSS_MAX_COMPARE_WSO_DONE_ADDR                                                       (SAILSS_HBCU_HBCU_REG_BASE      + 0x60u)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_MAX_COMPARE_WSO_DONE_OFFS                                                       (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x60u)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_MAX_COMPARE_WSO_DONE_RMSK                                                              0x1u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_MAX_COMPARE_WSO_DONE_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_MAX_COMPARE_WSO_DONE_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_MAX_COMPARE_WSO_DONE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SHSS_MAX_COMPARE_WSO_DONE_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_MAX_COMPARE_WSO_DONE_MAX_COMPARE_WSO_DONE_BMSK                                         0x1u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_MAX_COMPARE_WSO_DONE_MAX_COMPARE_WSO_DONE_SHFT                                           0u

#define HWIO_SAILSS_HBCU_HBCU_SHSS_CORE_STATUS_VALID_ADDR                                                          (SAILSS_HBCU_HBCU_REG_BASE      + 0x64u)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_CORE_STATUS_VALID_OFFS                                                          (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x64u)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_CORE_STATUS_VALID_RMSK                                                             0xffffful
#define HWIO_SAILSS_HBCU_HBCU_SHSS_CORE_STATUS_VALID_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_CORE_STATUS_VALID_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_CORE_STATUS_VALID_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SHSS_CORE_STATUS_VALID_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_CORE_STATUS_VALID_CORE_STATUS_VALID_BMSK                                           0xffffful
#define HWIO_SAILSS_HBCU_HBCU_SHSS_CORE_STATUS_VALID_CORE_STATUS_VALID_SHFT                                                 0u

#define HWIO_SAILSS_HBCU_HBCU_MBIST_STARTED_ADDR                                                                   (SAILSS_HBCU_HBCU_REG_BASE      + 0x68u)
#define HWIO_SAILSS_HBCU_HBCU_MBIST_STARTED_OFFS                                                                   (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x68u)
#define HWIO_SAILSS_HBCU_HBCU_MBIST_STARTED_RMSK                                                                          0x1u
#define HWIO_SAILSS_HBCU_HBCU_MBIST_STARTED_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_MBIST_STARTED_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_MBIST_STARTED_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_MBIST_STARTED_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_MBIST_STARTED_MBIST_STARTED_BMSK                                                            0x1u
#define HWIO_SAILSS_HBCU_HBCU_MBIST_STARTED_MBIST_STARTED_SHFT                                                              0u
#define HWIO_SAILSS_HBCU_HBCU_MBIST_STARTED_MBIST_STARTED_HBCU_NOT_STARTED_MBIST_FVAL                                     0x0u
#define HWIO_SAILSS_HBCU_HBCU_MBIST_STARTED_MBIST_STARTED_HBCU_STARTED_MBIST_FVAL                                         0x1u

#define HWIO_SAILSS_HBCU_HBCU_MBIST_DONE_ADDR                                                                      (SAILSS_HBCU_HBCU_REG_BASE      + 0x6cu)
#define HWIO_SAILSS_HBCU_HBCU_MBIST_DONE_OFFS                                                                      (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x6cu)
#define HWIO_SAILSS_HBCU_HBCU_MBIST_DONE_RMSK                                                                             0x1u
#define HWIO_SAILSS_HBCU_HBCU_MBIST_DONE_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_MBIST_DONE_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_MBIST_DONE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_MBIST_DONE_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_MBIST_DONE_MBIST_DONE_BMSK                                                                  0x1u
#define HWIO_SAILSS_HBCU_HBCU_MBIST_DONE_MBIST_DONE_SHFT                                                                    0u
#define HWIO_SAILSS_HBCU_HBCU_MBIST_DONE_MBIST_DONE_HBCU_NOT_COMPLETED_MBIST_FVAL                                         0x0u
#define HWIO_SAILSS_HBCU_HBCU_MBIST_DONE_MBIST_DONE_HBCU_COMPLETED_MBIST_FVAL                                             0x1u

#define HWIO_SAILSS_HBCU_HBCU_MBIST_PASS_ADDR                                                                      (SAILSS_HBCU_HBCU_REG_BASE      + 0x70u)
#define HWIO_SAILSS_HBCU_HBCU_MBIST_PASS_OFFS                                                                      (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x70u)
#define HWIO_SAILSS_HBCU_HBCU_MBIST_PASS_RMSK                                                                             0x1u
#define HWIO_SAILSS_HBCU_HBCU_MBIST_PASS_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_MBIST_PASS_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_MBIST_PASS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_MBIST_PASS_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_MBIST_PASS_MBIST_PASS_BMSK                                                                  0x1u
#define HWIO_SAILSS_HBCU_HBCU_MBIST_PASS_MBIST_PASS_SHFT                                                                    0u
#define HWIO_SAILSS_HBCU_HBCU_MBIST_PASS_MBIST_PASS_MBIST_FAIL_FVAL                                                       0x0u
#define HWIO_SAILSS_HBCU_HBCU_MBIST_PASS_MBIST_PASS_MBIST_PASS_FVAL                                                       0x1u

#define HWIO_SAILSS_HBCU_HBCU_LBIST_STARTED_ADDR                                                                   (SAILSS_HBCU_HBCU_REG_BASE      + 0x74u)
#define HWIO_SAILSS_HBCU_HBCU_LBIST_STARTED_OFFS                                                                   (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x74u)
#define HWIO_SAILSS_HBCU_HBCU_LBIST_STARTED_RMSK                                                                          0xfu
#define HWIO_SAILSS_HBCU_HBCU_LBIST_STARTED_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_LBIST_STARTED_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_LBIST_STARTED_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_LBIST_STARTED_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_LBIST_STARTED_LBIST_STARTED_BMSK                                                            0xfu
#define HWIO_SAILSS_HBCU_HBCU_LBIST_STARTED_LBIST_STARTED_SHFT                                                              0u
#define HWIO_SAILSS_HBCU_HBCU_LBIST_STARTED_LBIST_STARTED_HBCU_NOT_STARTED_LBIST_FVAL                                     0x0u
#define HWIO_SAILSS_HBCU_HBCU_LBIST_STARTED_LBIST_STARTED_HBCU_STARTED_LBIST_FVAL                                         0x1u

#define HWIO_SAILSS_HBCU_HBCU_LBIST_DONE_ADDR                                                                      (SAILSS_HBCU_HBCU_REG_BASE      + 0x78u)
#define HWIO_SAILSS_HBCU_HBCU_LBIST_DONE_OFFS                                                                      (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x78u)
#define HWIO_SAILSS_HBCU_HBCU_LBIST_DONE_RMSK                                                                             0xfu
#define HWIO_SAILSS_HBCU_HBCU_LBIST_DONE_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_LBIST_DONE_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_LBIST_DONE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_LBIST_DONE_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_LBIST_DONE_LBIST_DONE_BMSK                                                                  0xfu
#define HWIO_SAILSS_HBCU_HBCU_LBIST_DONE_LBIST_DONE_SHFT                                                                    0u
#define HWIO_SAILSS_HBCU_HBCU_LBIST_DONE_LBIST_DONE_HBCU_NOT_COMPLETED_LBIST_FVAL                                         0x0u
#define HWIO_SAILSS_HBCU_HBCU_LBIST_DONE_LBIST_DONE_HBCU_COMPLETED_LBIST_FVAL                                             0x1u

#define HWIO_SAILSS_HBCU_HBCU_LBIST_PASS_ADDR                                                                      (SAILSS_HBCU_HBCU_REG_BASE      + 0x7cu)
#define HWIO_SAILSS_HBCU_HBCU_LBIST_PASS_OFFS                                                                      (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x7cu)
#define HWIO_SAILSS_HBCU_HBCU_LBIST_PASS_RMSK                                                                             0xfu
#define HWIO_SAILSS_HBCU_HBCU_LBIST_PASS_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_LBIST_PASS_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_LBIST_PASS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_LBIST_PASS_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_LBIST_PASS_LBIST_PASS_BMSK                                                                  0xfu
#define HWIO_SAILSS_HBCU_HBCU_LBIST_PASS_LBIST_PASS_SHFT                                                                    0u
#define HWIO_SAILSS_HBCU_HBCU_LBIST_PASS_LBIST_PASS_LBIST_FAIL_FVAL                                                       0x0u
#define HWIO_SAILSS_HBCU_HBCU_LBIST_PASS_LBIST_PASS_LBIST_PASS_FVAL                                                       0x1u

#define HWIO_SAILSS_HBCU_HBCU_SHS_RING_BYPASS_ADDR                                                                 (SAILSS_HBCU_HBCU_REG_BASE      + 0x80u)
#define HWIO_SAILSS_HBCU_HBCU_SHS_RING_BYPASS_OFFS                                                                 (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x80u)
#define HWIO_SAILSS_HBCU_HBCU_SHS_RING_BYPASS_RMSK                                                                 0x800000fful
#define HWIO_SAILSS_HBCU_HBCU_SHS_RING_BYPASS_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SHS_RING_BYPASS_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SHS_RING_BYPASS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SHS_RING_BYPASS_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SHS_RING_BYPASS_OUT(v)            \
                out_dword(HWIO_SAILSS_HBCU_HBCU_SHS_RING_BYPASS_ADDR,v)
#define HWIO_SAILSS_HBCU_HBCU_SHS_RING_BYPASS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_SHS_RING_BYPASS_ADDR,m,v,HWIO_SAILSS_HBCU_HBCU_SHS_RING_BYPASS_IN)
#define HWIO_SAILSS_HBCU_HBCU_SHS_RING_BYPASS_RING_BYPASS_OVERRIDE_BMSK                                            0x80000000ul
#define HWIO_SAILSS_HBCU_HBCU_SHS_RING_BYPASS_RING_BYPASS_OVERRIDE_SHFT                                                    31u
#define HWIO_SAILSS_HBCU_HBCU_SHS_RING_BYPASS_RING_BYPASS_OVERRIDE_SHS_RING_BYPASS_OVERRIDE_DISABLE_FVAL                  0x0u
#define HWIO_SAILSS_HBCU_HBCU_SHS_RING_BYPASS_RING_BYPASS_OVERRIDE_SHS_RING_BYPASS_OVERRIDE_ENABLE_FVAL                   0x1u
#define HWIO_SAILSS_HBCU_HBCU_SHS_RING_BYPASS_RING_BYPASS_BMSK                                                           0xffu
#define HWIO_SAILSS_HBCU_HBCU_SHS_RING_BYPASS_RING_BYPASS_SHFT                                                              0u
#define HWIO_SAILSS_HBCU_HBCU_SHS_RING_BYPASS_RING_BYPASS_ALL_RINGS_ARE_ENABLED_FVAL                                      0x0u
#define HWIO_SAILSS_HBCU_HBCU_SHS_RING_BYPASS_RING_BYPASS_ALL_RINGS_ARE_BYPASSED_FVAL                                    0xffu

#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_ADDR                                                                       (SAILSS_HBCU_HBCU_REG_BASE      + 0x84u)
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_OFFS                                                                       (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x84u)
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_RMSK                                                                         0xfffffful
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING7_BYPASS_BMSK                                                      0x800000ul
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING7_BYPASS_SHFT                                                            23u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING7_BYPASS_RINGS_7_IS_ENABLED_FVAL                                        0x0u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING7_BYPASS_RING_7_IS_DISABLED_FVAL                                        0x1u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING6_BYPASS_BMSK                                                      0x400000ul
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING6_BYPASS_SHFT                                                            22u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING6_BYPASS_RINGS_6_IS_ENABLED_FVAL                                        0x0u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING6_BYPASS_RING_6_IS_DISABLED_FVAL                                        0x1u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING5_BYPASS_BMSK                                                      0x200000ul
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING5_BYPASS_SHFT                                                            21u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING5_BYPASS_RINGS_5_IS_ENABLED_FVAL                                        0x0u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING5_BYPASS_RING_5_IS_DISABLED_FVAL                                        0x1u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING4_BYPASS_BMSK                                                      0x100000ul
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING4_BYPASS_SHFT                                                            20u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING4_BYPASS_RINGS_4_IS_ENABLED_FVAL                                        0x0u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING4_BYPASS_RING_4_IS_DISABLED_FVAL                                        0x1u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING3_BYPASS_BMSK                                                       0x80000ul
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING3_BYPASS_SHFT                                                            19u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING3_BYPASS_RINGS_3_IS_ENABLED_FVAL                                        0x0u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING3_BYPASS_RING_3_IS_DISABLED_FVAL                                        0x1u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING2_BYPASS_BMSK                                                       0x40000ul
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING2_BYPASS_SHFT                                                            18u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING2_BYPASS_RINGS_2_IS_ENABLED_FVAL                                        0x0u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING2_BYPASS_RING_2_IS_DISABLED_FVAL                                        0x1u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING1_BYPASS_BMSK                                                       0x20000ul
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING1_BYPASS_SHFT                                                            17u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING1_BYPASS_RINGS_1_IS_ENABLED_FVAL                                        0x0u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING1_BYPASS_RING_1_IS_DISABLED_FVAL                                        0x1u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING0_BYPASS_BMSK                                                       0x10000ul
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING0_BYPASS_SHFT                                                            16u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING0_BYPASS_RINGS_0_IS_ENABLED_FVAL                                        0x0u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SMART_RING0_BYPASS_RING_0_IS_DISABLED_FVAL                                        0x1u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_MBIST_HW_ALGORITHM_SELECT_BMSK                                                 0xf000u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_MBIST_HW_ALGORITHM_SELECT_SHFT                                                     12u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SPARE_FUSE_BMSK                                                                 0xfc0u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SPARE_FUSE_SHFT                                                                     6u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_DOWNLOAD_FLASH_TO_AIT_RAM_BMSK                                                   0x20u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_DOWNLOAD_FLASH_TO_AIT_RAM_SHFT                                                      5u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_DOWNLOAD_FLASH_TO_AIT_RAM_DOWNLOAD_FROM_EXTERNAL_FLASH_DISABLED_FVAL              0x0u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_DOWNLOAD_FLASH_TO_AIT_RAM_DOWNLOAD_FROM_EXTERNAL_FLASH_ENABLED_FVAL               0x1u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SKIP_RETRY_BMSK                                                                  0x10u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SKIP_RETRY_SHFT                                                                     4u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SKIP_RETRY_RETRY_IS_ENABLED_FVAL                                                  0x0u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SKIP_RETRY_RETRY_IS_DISABLED_FVAL                                                 0x1u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_AIT_ROM_PATCHING_BMSK                                                             0x8u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_AIT_ROM_PATCHING_SHFT                                                               3u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_AIT_ROM_PATCHING_ROM_PATCHING_IS_DISABLED_FVAL                                    0x0u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_AIT_ROM_PATCHING_ROM_PATCHING_IS_ENABLED_FVAL                                     0x1u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SHARED_MEMORY_SW_BIST_CTRL_BMSK                                                   0x4u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SHARED_MEMORY_SW_BIST_CTRL_SHFT                                                     2u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SHARED_MEMORY_SW_BIST_CTRL_DRIVING_SHARED_MEMORY_MBIST_BY_PBL_DISABLED_FVAL        0x0u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_SHARED_MEMORY_SW_BIST_CTRL_DRIVING_SHARED_MEMORY_MBIST_BY_PBL_ENABLED_FVAL        0x1u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_LBIST_COVERAGE_LEVEL_BMSK                                                         0x2u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_LBIST_COVERAGE_LEVEL_SHFT                                                           1u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_LBIST_COVERAGE_LEVEL_LBIST_COVERAGE_LEVEL_80_PERCENT_FVAL                         0x0u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_LBIST_COVERAGE_LEVEL_LBIST_COVERAGE_LEVEL_90_PERCENT_FVAL                         0x1u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_BIST_BYPASS_BMSK                                                                  0x1u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_BIST_BYPASS_SHFT                                                                    0u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_BIST_BYPASS_HBCU_ACTIVE_TO_PERFORM_BIST_FVAL                                      0x0u
#define HWIO_SAILSS_HBCU_HBCU_FUSE_CTRL_BIST_BYPASS_HBCU_IS_BYPASSED_FROM_DOING_BIST_FVAL                                 0x1u

#define HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_CONFIG_ADDR                                                          (SAILSS_HBCU_HBCU_REG_BASE      + 0x88u)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_CONFIG_OFFS                                                          (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x88u)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_CONFIG_RMSK                                                          0x8000000ful
#define HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_CONFIG_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_CONFIG_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_CONFIG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_CONFIG_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_CONFIG_OUT(v)            \
                out_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_CONFIG_ADDR,v)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_CONFIG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_CONFIG_ADDR,m,v,HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_CONFIG_IN)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_CONFIG_MBIST_ALGO_OVERRIDE_VALID_BMSK                                0x80000000ul
#define HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_CONFIG_MBIST_ALGO_OVERRIDE_VALID_SHFT                                        31u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_CONFIG_MBIST_ALGO_OVERRIDE_VALID_MBIST_ALGO_OVERRIDE_DISABLE_FVAL           0x0u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_CONFIG_MBIST_ALGO_OVERRIDE_VALID_MBIST_ALGO_OVERRIDE_ENABLE_FVAL            0x1u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_CONFIG_MBIST_ALGO_CONFIG_BMSK                                               0xfu
#define HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_CONFIG_MBIST_ALGO_CONFIG_SHFT                                                 0u

#define HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_EN_ADDR                                                              (SAILSS_HBCU_HBCU_REG_BASE      + 0x8cu)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_EN_OFFS                                                              (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x8cu)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_EN_RMSK                                                                     0x1u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_EN_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_EN_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_EN_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_EN_ADDR,v)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_EN_ADDR,m,v,HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_EN_IN)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_EN_MBIST_ALGO_EN_BMSK                                                       0x1u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_EN_MBIST_ALGO_EN_SHFT                                                         0u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_EN_MBIST_ALGO_EN_MBIST_ALGO_DISABLED_FVAL                                   0x0u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_MBIST_ALGO_EN_MBIST_ALGO_EN_MBIST_ALGO_ENABLED_FVAL                                    0x1u

#define HWIO_SAILSS_HBCU_HBCU_SHSS_APB_MODE_ADDR                                                                   (SAILSS_HBCU_HBCU_REG_BASE      + 0x90u)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_APB_MODE_OFFS                                                                   (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x90u)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_APB_MODE_RMSK                                                                          0x1u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_APB_MODE_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_APB_MODE_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_APB_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SHSS_APB_MODE_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_APB_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_APB_MODE_ADDR,v)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_APB_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_SHSS_APB_MODE_ADDR,m,v,HWIO_SAILSS_HBCU_HBCU_SHSS_APB_MODE_IN)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_APB_MODE_APB_MODE_BMSK                                                                 0x1u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_APB_MODE_APB_MODE_SHFT                                                                   0u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_APB_MODE_APB_MODE_HBCU_MODE_FVAL                                                       0x0u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_APB_MODE_APB_MODE_APB_MODE_FVAL                                                        0x1u

#define HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_COVERAGE_LEVEL_ADDR                                                       (SAILSS_HBCU_HBCU_REG_BASE      + 0x94u)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_COVERAGE_LEVEL_OFFS                                                       (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x94u)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_COVERAGE_LEVEL_RMSK                                                       0x80000001ul
#define HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_COVERAGE_LEVEL_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_COVERAGE_LEVEL_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_COVERAGE_LEVEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_COVERAGE_LEVEL_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_COVERAGE_LEVEL_OUT(v)            \
                out_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_COVERAGE_LEVEL_ADDR,v)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_COVERAGE_LEVEL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_COVERAGE_LEVEL_ADDR,m,v,HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_COVERAGE_LEVEL_IN)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_COVERAGE_LEVEL_LBIST_COV_LVL_OVERRIDE_VALID_BMSK                          0x80000000ul
#define HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_COVERAGE_LEVEL_LBIST_COV_LVL_OVERRIDE_VALID_SHFT                                  31u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_COVERAGE_LEVEL_LBIST_COV_LVL_OVERRIDE_VALID_LBIST_COV_LVL_OVERRIDE_DISABLE_FVAL        0x0u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_COVERAGE_LEVEL_LBIST_COV_LVL_OVERRIDE_VALID_LBIST_COV_LVL_OVERRIDE_ENABLE_FVAL        0x1u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_COVERAGE_LEVEL_LBIST_COVERAGE_LEVEL_BMSK                                         0x1u
#define HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_COVERAGE_LEVEL_LBIST_COVERAGE_LEVEL_SHFT                                           0u

#define HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_CBDFT_CORE_BYPASS_ADDR                                                    (SAILSS_HBCU_HBCU_REG_BASE      + 0x98u)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_CBDFT_CORE_BYPASS_OFFS                                                    (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x98u)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_CBDFT_CORE_BYPASS_RMSK                                                           0xfu
#define HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_CBDFT_CORE_BYPASS_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_CBDFT_CORE_BYPASS_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_CBDFT_CORE_BYPASS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_CBDFT_CORE_BYPASS_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_CBDFT_CORE_BYPASS_OUT(v)            \
                out_dword(HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_CBDFT_CORE_BYPASS_ADDR,v)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_CBDFT_CORE_BYPASS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_CBDFT_CORE_BYPASS_ADDR,m,v,HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_CBDFT_CORE_BYPASS_IN)
#define HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_CBDFT_CORE_BYPASS_LBIST_CBDFT_CORE_BYPASS_BMSK                                   0xfu
#define HWIO_SAILSS_HBCU_HBCU_SHSS_LBIST_CBDFT_CORE_BYPASS_LBIST_CBDFT_CORE_BYPASS_SHFT                                     0u

#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_2_ADDR                                                                     (SAILSS_HBCU_HBCU_REG_BASE      + 0x9cu)
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_2_OFFS                                                                     (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x9cu)
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_2_RMSK                                                                     0xfffffffful
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_2_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_2_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_2_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_2_OUT(v)            \
                out_dword(HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_2_ADDR,v)
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_2_ADDR,m,v,HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_2_IN)
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_2_SPARE_BMSK                                                               0xfffffffful
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_2_SPARE_SHFT                                                                        0u

#define HWIO_SAILSS_HBCU_HBCU_PHASE_RECONFIGb_ADDR(b)                                                              (SAILSS_HBCU_HBCU_REG_BASE      + 0XA0 + (0x4*(b)))
#define HWIO_SAILSS_HBCU_HBCU_PHASE_RECONFIGb_OFFS(b)                                                              (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0XA0 + (0x4*(b)))
#define HWIO_SAILSS_HBCU_HBCU_PHASE_RECONFIGb_RMSK                                                                        0x3u
#define HWIO_SAILSS_HBCU_HBCU_PHASE_RECONFIGb_MAXb                                                                          3u
#define HWIO_SAILSS_HBCU_HBCU_PHASE_RECONFIGb_INI(b)                \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_PHASE_RECONFIGb_ADDR(b), HWIO_SAILSS_HBCU_HBCU_PHASE_RECONFIGb_RMSK)
#define HWIO_SAILSS_HBCU_HBCU_PHASE_RECONFIGb_INMI(b,mask)        \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_PHASE_RECONFIGb_ADDR(b), mask)
#define HWIO_SAILSS_HBCU_HBCU_PHASE_RECONFIGb_OUTI(b,val)        \
                out_dword(HWIO_SAILSS_HBCU_HBCU_PHASE_RECONFIGb_ADDR(b),val)
#define HWIO_SAILSS_HBCU_HBCU_PHASE_RECONFIGb_OUTMI(b,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_PHASE_RECONFIGb_ADDR(b),mask,val,HWIO_SAILSS_HBCU_HBCU_PHASE_RECONFIGb_INI(b))
#define HWIO_SAILSS_HBCU_HBCU_PHASE_RECONFIGb_PHASE_RECONFIG_BMSK                                                         0x3u
#define HWIO_SAILSS_HBCU_HBCU_PHASE_RECONFIGb_PHASE_RECONFIG_SHFT                                                           0u

#define HWIO_SAILSS_HBCU_HBCU_SEQ_MEM_FUSA_STATUS_ADDR                                                             (SAILSS_HBCU_HBCU_REG_BASE      + 0xf40u)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_MEM_FUSA_STATUS_OFFS                                                             (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0xf40u)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_MEM_FUSA_STATUS_RMSK                                                                 0x1fffu
#define HWIO_SAILSS_HBCU_HBCU_SEQ_MEM_FUSA_STATUS_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SEQ_MEM_FUSA_STATUS_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_MEM_FUSA_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SEQ_MEM_FUSA_STATUS_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_MEM_FUSA_STATUS_HPCNT_BMSK                                                           0x1f80u
#define HWIO_SAILSS_HBCU_HBCU_SEQ_MEM_FUSA_STATUS_HPCNT_SHFT                                                                7u
#define HWIO_SAILSS_HBCU_HBCU_SEQ_MEM_FUSA_STATUS_VPCNT_BMSK                                                             0x7eu
#define HWIO_SAILSS_HBCU_HBCU_SEQ_MEM_FUSA_STATUS_VPCNT_SHFT                                                                1u
#define HWIO_SAILSS_HBCU_HBCU_SEQ_MEM_FUSA_STATUS_FLT_BMSK                                                                0x1u
#define HWIO_SAILSS_HBCU_HBCU_SEQ_MEM_FUSA_STATUS_FLT_SHFT                                                                  0u

#define HWIO_SAILSS_HBCU_FUSA_STATUS_REGISTER_ADDR                                                                 (SAILSS_HBCU_HBCU_REG_BASE      + 0xf50u)
#define HWIO_SAILSS_HBCU_FUSA_STATUS_REGISTER_OFFS                                                                 (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0xf50u)
#define HWIO_SAILSS_HBCU_FUSA_STATUS_REGISTER_RMSK                                                                     0x1fffu
#define HWIO_SAILSS_HBCU_FUSA_STATUS_REGISTER_IN                    \
                in_dword(HWIO_SAILSS_HBCU_FUSA_STATUS_REGISTER_ADDR)
#define HWIO_SAILSS_HBCU_FUSA_STATUS_REGISTER_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_FUSA_STATUS_REGISTER_ADDR, m)
#define HWIO_SAILSS_HBCU_FUSA_STATUS_REGISTER_HPCNT_BMSK                                                               0x1f80u
#define HWIO_SAILSS_HBCU_FUSA_STATUS_REGISTER_HPCNT_SHFT                                                                    7u
#define HWIO_SAILSS_HBCU_FUSA_STATUS_REGISTER_VPCNT_BMSK                                                                 0x7eu
#define HWIO_SAILSS_HBCU_FUSA_STATUS_REGISTER_VPCNT_SHFT                                                                    1u
#define HWIO_SAILSS_HBCU_FUSA_STATUS_REGISTER_FLT_BMSK                                                                    0x1u
#define HWIO_SAILSS_HBCU_FUSA_STATUS_REGISTER_FLT_SHFT                                                                      0u

#define HWIO_SAILSS_HBCU_HBCU_PARAM_SEQ_CONFIG_ADDR                                                                (SAILSS_HBCU_HBCU_REG_BASE      + 0x1000u)
#define HWIO_SAILSS_HBCU_HBCU_PARAM_SEQ_CONFIG_OFFS                                                                (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x1000u)
#define HWIO_SAILSS_HBCU_HBCU_PARAM_SEQ_CONFIG_RMSK                                                                      0xffu
#define HWIO_SAILSS_HBCU_HBCU_PARAM_SEQ_CONFIG_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_PARAM_SEQ_CONFIG_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_PARAM_SEQ_CONFIG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_PARAM_SEQ_CONFIG_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_PARAM_SEQ_CONFIG_NUM_SEQ_MEM_WORDS_BMSK                                                    0xffu
#define HWIO_SAILSS_HBCU_HBCU_PARAM_SEQ_CONFIG_NUM_SEQ_MEM_WORDS_SHFT                                                       0u

#define HWIO_SAILSS_HBCU_HBCU_SEQ_BUSY_ADDR                                                                        (SAILSS_HBCU_HBCU_REG_BASE      + 0x1004u)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_BUSY_OFFS                                                                        (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x1004u)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_BUSY_RMSK                                                                               0x1u
#define HWIO_SAILSS_HBCU_HBCU_SEQ_BUSY_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SEQ_BUSY_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_BUSY_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SEQ_BUSY_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_BUSY_BUSY_STAT_BMSK                                                                     0x1u
#define HWIO_SAILSS_HBCU_HBCU_SEQ_BUSY_BUSY_STAT_SHFT                                                                       0u
#define HWIO_SAILSS_HBCU_HBCU_SEQ_BUSY_BUSY_STAT_SEQUENCER_IDLE_FVAL                                                      0x0u
#define HWIO_SAILSS_HBCU_HBCU_SEQ_BUSY_BUSY_STAT_SEQUENCER_BUSY_FVAL                                                      0x1u

#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_PROGRAM_COUNTER_ADDR                                                         (SAILSS_HBCU_HBCU_REG_BASE      + 0x1008u)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_PROGRAM_COUNTER_OFFS                                                         (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x1008u)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_PROGRAM_COUNTER_RMSK                                                              0x1ffu
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_PROGRAM_COUNTER_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_PROGRAM_COUNTER_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_PROGRAM_COUNTER_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_PROGRAM_COUNTER_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_PROGRAM_COUNTER_CURRENT_INSTR_ADDR_BMSK                                           0x1ffu
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_PROGRAM_COUNTER_CURRENT_INSTR_ADDR_SHFT                                               0u

#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_STAT_ADDR                                                                    (SAILSS_HBCU_HBCU_REG_BASE      + 0x100cu)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_STAT_OFFS                                                                    (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x100cu)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_STAT_RMSK                                                                           0x1u
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_STAT_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_STAT_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_STAT_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_STAT_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_STAT_DBG_STEPPING_STATUS_BMSK                                                       0x1u
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_STAT_DBG_STEPPING_STATUS_SHFT                                                         0u

#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_WAIT_EVNT_ADDR                                                               (SAILSS_HBCU_HBCU_REG_BASE      + 0x1010u)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_WAIT_EVNT_OFFS                                                               (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x1010u)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_WAIT_EVNT_RMSK                                                               0xfffffffful
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_WAIT_EVNT_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_WAIT_EVNT_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_WAIT_EVNT_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_WAIT_EVNT_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_WAIT_EVNT_SEQ_DBG_WAIT_EVNT_BMSK                                             0xfffffffful
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_WAIT_EVNT_SEQ_DBG_WAIT_EVNT_SHFT                                                      0u

#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_ADDR                                                                     (SAILSS_HBCU_HBCU_REG_BASE      + 0x1014u)
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_OFFS                                                                     (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x1014u)
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_RMSK                                                                     0xfffffffful
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_OUT(v)            \
                out_dword(HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_ADDR,v)
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_ADDR,m,v,HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_IN)
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_SPARE_BMSK                                                               0xffffffe0ul
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_SPARE_SHFT                                                                        5u
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_SKIP_PHASE_3_BMSK                                                              0x10u
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_SKIP_PHASE_3_SHFT                                                                 4u
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_SKIP_PHASE_3_DONT_SKIP_PHASE_3_FVAL                                             0x0u
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_SKIP_PHASE_3_SKIP_PHASE_3_FVAL                                                  0x1u
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_SKIP_PHASE_2_BMSK                                                               0x8u
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_SKIP_PHASE_2_SHFT                                                                 3u
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_SKIP_PHASE_2_DONT_SKIP_PHASE_2_FVAL                                             0x0u
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_SKIP_PHASE_2_SKIP_PHASE_2_FVAL                                                  0x1u
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_SKIP_PHASE_1_BMSK                                                               0x4u
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_SKIP_PHASE_1_SHFT                                                                 2u
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_SKIP_PHASE_1_DONT_SKIP_PHASE_1_FVAL                                             0x0u
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_SKIP_PHASE_1_SKIP_PHASE_1_FVAL                                                  0x1u
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_FORCE_CLK_EN_BMSK                                                               0x2u
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_FORCE_CLK_EN_SHFT                                                                 1u
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_FORCE_CLK_EN_ENABLE_CLOCK_GATING_FVAL                                           0x0u
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_FORCE_CLK_EN_DIABLE_CLOCK_GATING_FVAL                                           0x1u
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_DEBUG_DSB_SEL_BMSK                                                              0x1u
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_DEBUG_DSB_SEL_SHFT                                                                0u
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_DEBUG_DSB_SEL_HBCU_DEBUG_DSB_SELECTED_FVAL                                      0x0u
#define HWIO_SAILSS_HBCU_HBCU_SPARE_CSR_1_DEBUG_DSB_SEL_SHS_DEBUG_DSB_SELECTED_FVAL                                       0x1u

#define HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_START_ADDR_ADDR                                                         (SAILSS_HBCU_HBCU_REG_BASE      + 0x1018u)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_START_ADDR_OFFS                                                         (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x1018u)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_START_ADDR_RMSK                                                         0x800001fful
#define HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_START_ADDR_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_START_ADDR_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_START_ADDR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_START_ADDR_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_START_ADDR_OUT(v)            \
                out_dword(HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_START_ADDR_ADDR,v)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_START_ADDR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_START_ADDR_ADDR,m,v,HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_START_ADDR_IN)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_START_ADDR_SEQ_OVERRIDE_VALID_BMSK                                      0x80000000ul
#define HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_START_ADDR_SEQ_OVERRIDE_VALID_SHFT                                              31u
#define HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_START_ADDR_SEQ_OVERRIDE_VALID_SEQ_OVERRIDE_DISABLE_FVAL                        0x0u
#define HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_START_ADDR_SEQ_OVERRIDE_VALID_SEQ_OVERRIDE_ENABLE_FVAL                         0x1u
#define HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_START_ADDR_SEQ_OVERRIDE_START_ADDR_BMSK                                      0x1ffu
#define HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_START_ADDR_SEQ_OVERRIDE_START_ADDR_SHFT                                          0u

#define HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_TRIGGER_ADDR                                                            (SAILSS_HBCU_HBCU_REG_BASE      + 0x101cu)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_TRIGGER_OFFS                                                            (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x101cu)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_TRIGGER_RMSK                                                                   0x1u
#define HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_TRIGGER_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_TRIGGER_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_TRIGGER_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_TRIGGER_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_TRIGGER_OUT(v)            \
                out_dword(HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_TRIGGER_ADDR,v)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_TRIGGER_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_TRIGGER_ADDR,m,v,HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_TRIGGER_IN)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_TRIGGER_SEQ_OVERRIDE_TRIGGER_BMSK                                              0x1u
#define HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_TRIGGER_SEQ_OVERRIDE_TRIGGER_SHFT                                                0u
#define HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_TRIGGER_SEQ_OVERRIDE_TRIGGER_SEQ_SW_OVERRIDE_NO_TRIGGER_FVAL                   0x0u
#define HWIO_SAILSS_HBCU_HBCU_SEQ_OVERRIDE_TRIGGER_SEQ_OVERRIDE_TRIGGER_SEQ_SW_OVERRIDE_TRIGGER_FVAL                      0x1u

#define HWIO_SAILSS_HBCU_HBCU_SEQ_TRIGGER_CTRL_OVERRIDE_MASK_ADDR                                                  (SAILSS_HBCU_HBCU_REG_BASE      + 0x1020u)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_TRIGGER_CTRL_OVERRIDE_MASK_OFFS                                                  (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x1020u)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_TRIGGER_CTRL_OVERRIDE_MASK_RMSK                                                  0xfffffffful
#define HWIO_SAILSS_HBCU_HBCU_SEQ_TRIGGER_CTRL_OVERRIDE_MASK_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SEQ_TRIGGER_CTRL_OVERRIDE_MASK_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_TRIGGER_CTRL_OVERRIDE_MASK_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SEQ_TRIGGER_CTRL_OVERRIDE_MASK_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_TRIGGER_CTRL_OVERRIDE_MASK_OUT(v)            \
                out_dword(HWIO_SAILSS_HBCU_HBCU_SEQ_TRIGGER_CTRL_OVERRIDE_MASK_ADDR,v)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_TRIGGER_CTRL_OVERRIDE_MASK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_SEQ_TRIGGER_CTRL_OVERRIDE_MASK_ADDR,m,v,HWIO_SAILSS_HBCU_HBCU_SEQ_TRIGGER_CTRL_OVERRIDE_MASK_IN)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_TRIGGER_CTRL_OVERRIDE_MASK_TRIGGER_CTRL_OVERRIDE_MASK_BMSK                       0xfffffffful
#define HWIO_SAILSS_HBCU_HBCU_SEQ_TRIGGER_CTRL_OVERRIDE_MASK_TRIGGER_CTRL_OVERRIDE_MASK_SHFT                                0u

#define HWIO_SAILSS_HBCU_HBCU_SEQ_TRIGGER_CTRL_OVERRIDE_VAL_ADDR                                                   (SAILSS_HBCU_HBCU_REG_BASE      + 0x1024u)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_TRIGGER_CTRL_OVERRIDE_VAL_OFFS                                                   (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x1024u)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_TRIGGER_CTRL_OVERRIDE_VAL_RMSK                                                   0xfffffffful
#define HWIO_SAILSS_HBCU_HBCU_SEQ_TRIGGER_CTRL_OVERRIDE_VAL_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SEQ_TRIGGER_CTRL_OVERRIDE_VAL_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_TRIGGER_CTRL_OVERRIDE_VAL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SEQ_TRIGGER_CTRL_OVERRIDE_VAL_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_TRIGGER_CTRL_OVERRIDE_VAL_OUT(v)            \
                out_dword(HWIO_SAILSS_HBCU_HBCU_SEQ_TRIGGER_CTRL_OVERRIDE_VAL_ADDR,v)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_TRIGGER_CTRL_OVERRIDE_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_SEQ_TRIGGER_CTRL_OVERRIDE_VAL_ADDR,m,v,HWIO_SAILSS_HBCU_HBCU_SEQ_TRIGGER_CTRL_OVERRIDE_VAL_IN)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_TRIGGER_CTRL_OVERRIDE_VAL_TRIGGER_CTRL_OVERRIDE_VAL_BMSK                         0xfffffffful
#define HWIO_SAILSS_HBCU_HBCU_SEQ_TRIGGER_CTRL_OVERRIDE_VAL_TRIGGER_CTRL_OVERRIDE_VAL_SHFT                                  0u

#define HWIO_SAILSS_HBCU_HBCU_SEQ_WAIT_EVENT_OVERRIDE_MASK_ADDR                                                    (SAILSS_HBCU_HBCU_REG_BASE      + 0x1028u)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_WAIT_EVENT_OVERRIDE_MASK_OFFS                                                    (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x1028u)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_WAIT_EVENT_OVERRIDE_MASK_RMSK                                                    0xfffffffful
#define HWIO_SAILSS_HBCU_HBCU_SEQ_WAIT_EVENT_OVERRIDE_MASK_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SEQ_WAIT_EVENT_OVERRIDE_MASK_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_WAIT_EVENT_OVERRIDE_MASK_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SEQ_WAIT_EVENT_OVERRIDE_MASK_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_WAIT_EVENT_OVERRIDE_MASK_OUT(v)            \
                out_dword(HWIO_SAILSS_HBCU_HBCU_SEQ_WAIT_EVENT_OVERRIDE_MASK_ADDR,v)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_WAIT_EVENT_OVERRIDE_MASK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_SEQ_WAIT_EVENT_OVERRIDE_MASK_ADDR,m,v,HWIO_SAILSS_HBCU_HBCU_SEQ_WAIT_EVENT_OVERRIDE_MASK_IN)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_WAIT_EVENT_OVERRIDE_MASK_WAIT_EVENT_OVERRIDE_MASK_BMSK                           0xfffffffful
#define HWIO_SAILSS_HBCU_HBCU_SEQ_WAIT_EVENT_OVERRIDE_MASK_WAIT_EVENT_OVERRIDE_MASK_SHFT                                    0u

#define HWIO_SAILSS_HBCU_HBCU_SEQ_WAIT_EVENT_OVERRIDE_VAL_ADDR                                                     (SAILSS_HBCU_HBCU_REG_BASE      + 0x102cu)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_WAIT_EVENT_OVERRIDE_VAL_OFFS                                                     (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x102cu)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_WAIT_EVENT_OVERRIDE_VAL_RMSK                                                     0xfffffffful
#define HWIO_SAILSS_HBCU_HBCU_SEQ_WAIT_EVENT_OVERRIDE_VAL_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SEQ_WAIT_EVENT_OVERRIDE_VAL_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_WAIT_EVENT_OVERRIDE_VAL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SEQ_WAIT_EVENT_OVERRIDE_VAL_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_WAIT_EVENT_OVERRIDE_VAL_OUT(v)            \
                out_dword(HWIO_SAILSS_HBCU_HBCU_SEQ_WAIT_EVENT_OVERRIDE_VAL_ADDR,v)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_WAIT_EVENT_OVERRIDE_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_SEQ_WAIT_EVENT_OVERRIDE_VAL_ADDR,m,v,HWIO_SAILSS_HBCU_HBCU_SEQ_WAIT_EVENT_OVERRIDE_VAL_IN)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_WAIT_EVENT_OVERRIDE_VAL_WAIT_EVENT_OVERRIDE_VAL_BMSK                             0xfffffffful
#define HWIO_SAILSS_HBCU_HBCU_SEQ_WAIT_EVENT_OVERRIDE_VAL_WAIT_EVENT_OVERRIDE_VAL_SHFT                                      0u

#define HWIO_SAILSS_HBCU_HBCU_SEQ_BR_EVENT_OVERRIDE_MASK_ADDR                                                      (SAILSS_HBCU_HBCU_REG_BASE      + 0x1030u)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_BR_EVENT_OVERRIDE_MASK_OFFS                                                      (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x1030u)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_BR_EVENT_OVERRIDE_MASK_RMSK                                                          0xffffu
#define HWIO_SAILSS_HBCU_HBCU_SEQ_BR_EVENT_OVERRIDE_MASK_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SEQ_BR_EVENT_OVERRIDE_MASK_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_BR_EVENT_OVERRIDE_MASK_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SEQ_BR_EVENT_OVERRIDE_MASK_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_BR_EVENT_OVERRIDE_MASK_OUT(v)            \
                out_dword(HWIO_SAILSS_HBCU_HBCU_SEQ_BR_EVENT_OVERRIDE_MASK_ADDR,v)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_BR_EVENT_OVERRIDE_MASK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_SEQ_BR_EVENT_OVERRIDE_MASK_ADDR,m,v,HWIO_SAILSS_HBCU_HBCU_SEQ_BR_EVENT_OVERRIDE_MASK_IN)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_BR_EVENT_OVERRIDE_MASK_BR_EVENT_OVERRIDE_MASK_BMSK                                   0xffffu
#define HWIO_SAILSS_HBCU_HBCU_SEQ_BR_EVENT_OVERRIDE_MASK_BR_EVENT_OVERRIDE_MASK_SHFT                                        0u

#define HWIO_SAILSS_HBCU_HBCU_SEQ_BR_EVENT_OVERRIDE_VAL_ADDR                                                       (SAILSS_HBCU_HBCU_REG_BASE      + 0x1034u)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_BR_EVENT_OVERRIDE_VAL_OFFS                                                       (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x1034u)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_BR_EVENT_OVERRIDE_VAL_RMSK                                                           0xffffu
#define HWIO_SAILSS_HBCU_HBCU_SEQ_BR_EVENT_OVERRIDE_VAL_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SEQ_BR_EVENT_OVERRIDE_VAL_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_BR_EVENT_OVERRIDE_VAL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SEQ_BR_EVENT_OVERRIDE_VAL_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_BR_EVENT_OVERRIDE_VAL_OUT(v)            \
                out_dword(HWIO_SAILSS_HBCU_HBCU_SEQ_BR_EVENT_OVERRIDE_VAL_ADDR,v)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_BR_EVENT_OVERRIDE_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_SEQ_BR_EVENT_OVERRIDE_VAL_ADDR,m,v,HWIO_SAILSS_HBCU_HBCU_SEQ_BR_EVENT_OVERRIDE_VAL_IN)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_BR_EVENT_OVERRIDE_VAL_BR_EVENT_OVERRIDE_VAL_BMSK                                     0xffffu
#define HWIO_SAILSS_HBCU_HBCU_SEQ_BR_EVENT_OVERRIDE_VAL_BR_EVENT_OVERRIDE_VAL_SHFT                                          0u

#define HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_BR_ADDR_b_ADDR(b)                                                            (SAILSS_HBCU_HBCU_REG_BASE      + 0X1040 + (0x4*(b)))
#define HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_BR_ADDR_b_OFFS(b)                                                            (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0X1040 + (0x4*(b)))
#define HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_BR_ADDR_b_RMSK                                                                    0x1ffu
#define HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_BR_ADDR_b_MAXb                                                                       15u
#define HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_BR_ADDR_b_INI(b)                \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_BR_ADDR_b_ADDR(b), HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_BR_ADDR_b_RMSK)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_BR_ADDR_b_INMI(b,mask)        \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_BR_ADDR_b_ADDR(b), mask)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_BR_ADDR_b_OUTI(b,val)        \
                out_dword(HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_BR_ADDR_b_ADDR(b),val)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_BR_ADDR_b_OUTMI(b,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_BR_ADDR_b_ADDR(b),mask,val,HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_BR_ADDR_b_INI(b))
#define HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_BR_ADDR_b_BR_ADDR_BMSK                                                            0x1ffu
#define HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_BR_ADDR_b_BR_ADDR_SHFT                                                                0u

#define HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_DELAY_VAL_v_ADDR(v)                                                          (SAILSS_HBCU_HBCU_REG_BASE      + 0X10C0 + (0x4*(v)))
#define HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_DELAY_VAL_v_OFFS(v)                                                          (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0X10C0 + (0x4*(v)))
#define HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_DELAY_VAL_v_RMSK                                                                0xffffful
#define HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_DELAY_VAL_v_MAXv                                                                     15u
#define HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_DELAY_VAL_v_INI(v)                \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_DELAY_VAL_v_ADDR(v), HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_DELAY_VAL_v_RMSK)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_DELAY_VAL_v_INMI(v,mask)        \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_DELAY_VAL_v_ADDR(v), mask)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_DELAY_VAL_v_OUTI(v,val)        \
                out_dword(HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_DELAY_VAL_v_ADDR(v),val)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_DELAY_VAL_v_OUTMI(v,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_DELAY_VAL_v_ADDR(v),mask,val,HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_DELAY_VAL_v_INI(v))
#define HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_DELAY_VAL_v_DELAY_VAL_BMSK                                                      0xffffful
#define HWIO_SAILSS_HBCU_HBCU_SEQ_CFG_DELAY_VAL_v_DELAY_VAL_SHFT                                                            0u

#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_BREAKPOINT_ADDR_ADDR                                                         (SAILSS_HBCU_HBCU_REG_BASE      + 0x1100u)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_BREAKPOINT_ADDR_OFFS                                                         (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x1100u)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_BREAKPOINT_ADDR_RMSK                                                         0x800001fful
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_BREAKPOINT_ADDR_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_BREAKPOINT_ADDR_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_BREAKPOINT_ADDR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_BREAKPOINT_ADDR_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_BREAKPOINT_ADDR_OUT(v)            \
                out_dword(HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_BREAKPOINT_ADDR_ADDR,v)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_BREAKPOINT_ADDR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_BREAKPOINT_ADDR_ADDR,m,v,HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_BREAKPOINT_ADDR_IN)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_BREAKPOINT_ADDR_DBG_BREAKPOINT_VALID_BMSK                                    0x80000000ul
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_BREAKPOINT_ADDR_DBG_BREAKPOINT_VALID_SHFT                                            31u
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_BREAKPOINT_ADDR_DBG_BREAKPOINT_ADDR_BMSK                                          0x1ffu
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_BREAKPOINT_ADDR_DBG_BREAKPOINT_ADDR_SHFT                                              0u

#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_STEP_ADDR                                                                    (SAILSS_HBCU_HBCU_REG_BASE      + 0x1104u)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_STEP_OFFS                                                                    (SAILSS_HBCU_HBCU_REG_BASE_OFFS + 0x1104u)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_STEP_RMSK                                                                       0x10001ul
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_STEP_IN                    \
                in_dword(HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_STEP_ADDR)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_STEP_INM(m)            \
                in_dword_masked(HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_STEP_ADDR, m)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_STEP_OUT(v)            \
                out_dword(HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_STEP_ADDR,v)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_STEP_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_STEP_ADDR,m,v,HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_STEP_IN)
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_STEP_SEQ_DBG_STEP_TRIGGER_BMSK                                                  0x10000ul
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_STEP_SEQ_DBG_STEP_TRIGGER_SHFT                                                       16u
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_STEP_SEQ_DBG_STEP_CONTINUE_BMSK                                                     0x1u
#define HWIO_SAILSS_HBCU_HBCU_SEQ_DBG_STEP_SEQ_DBG_STEP_CONTINUE_SHFT                                                       0u


#endif /* __G_SAIL_HBCU_HWIO_H__ */
