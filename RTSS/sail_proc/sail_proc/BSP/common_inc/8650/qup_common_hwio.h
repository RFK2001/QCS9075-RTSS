#ifndef __QUP_COMMON_HWIO__
#define __QUP_COMMON_HWIO__
/*
===========================================================================
*/
/**
    @file qup_common_hwio.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        LeMansAU [lemansau_v1.0_p2q0r23_for_dv]
 
    This file contains HWIO register definitions for the following modules:
        SAILSS_QUPV3_1_QUPV3_COMMON
        SAILSS_QUPV3_1_QUPV3_SE_WRAPPER
        SAILSS_QUPV3_1_SE0_.+


    Generation parameters: 
    { 'filename': 'qup_common_hwio.h',
      'ignore-prefixes': True,
      'modules': [ 'SAILSS_QUPV3_1_QUPV3_COMMON',
                   'SAILSS_QUPV3_1_QUPV3_SE_WRAPPER',
                   'SAILSS_QUPV3_1_SE0_.+'],
      'output-offsets': True,
      'output-phys': True}
*/
/*
    ===========================================================================

    Copyright (c) 2021 Qualcomm Technologies, Inc.
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

    $Header: //components/dev/bsp.sail/1.0/txavier.bsp.sail.1.0.dt_qup/uart/inc/8650/qup_common_hwio.h#1 $
    $DateTime: 2023/01/02 02:34:16 $
    $Author: txavier $

    ===========================================================================
*/

#include "msmhwiobase.h"

/*----------------------------------------------------------------------------
 * MODULE: QUPV3_COMMON
 *--------------------------------------------------------------------------*/
#define QUPV3_COMMON_REG_BASE                                                                              (SAILSS_QUPV3_1_QUPV3_ID_1_BASE            + 0x000c0000)
#define QUPV3_COMMON_REG_BASE_SIZE                                                                         0x2000
#define QUPV3_COMMON_REG_BASE_USED                                                                         0x1a2c
#define QUPV3_COMMON_REG_BASE_PHYS                                                                         (SAILSS_QUPV3_1_QUPV3_ID_1_BASE_PHYS + 0x000c0000)
#define QUPV3_COMMON_REG_BASE_OFFS                                                                         0x000c0000

#define HWIO_QUPV3_HW_PARAM_ADDR                                                                           (QUPV3_COMMON_REG_BASE            + 0x0)
#define HWIO_QUPV3_HW_PARAM_PHYS                                                                           (QUPV3_COMMON_REG_BASE_PHYS + 0x0)
#define HWIO_QUPV3_HW_PARAM_OFFS                                                                           (QUPV3_COMMON_REG_BASE_OFFS + 0x0)
#define HWIO_QUPV3_HW_PARAM_RMSK                                                                           0xffffff0f
#define HWIO_QUPV3_HW_PARAM_IN                    \
                in_dword(HWIO_QUPV3_HW_PARAM_ADDR)
#define HWIO_QUPV3_HW_PARAM_INM(m)            \
                in_dword_masked(HWIO_QUPV3_HW_PARAM_ADDR, m)
#define HWIO_QUPV3_HW_PARAM_QUPV3_AHB_M_ADDR_W_BMSK                                                        0xff000000
#define HWIO_QUPV3_HW_PARAM_QUPV3_AHB_M_ADDR_W_SHFT                                                                24
#define HWIO_QUPV3_HW_PARAM_QUPV3_NUM_GPIIS_BMSK                                                             0xff0000
#define HWIO_QUPV3_HW_PARAM_QUPV3_NUM_GPIIS_SHFT                                                                   16
#define HWIO_QUPV3_HW_PARAM_QUPV3_NUM_SES_BMSK                                                                 0xff00
#define HWIO_QUPV3_HW_PARAM_QUPV3_NUM_SES_SHFT                                                                      8
#define HWIO_QUPV3_HW_PARAM_QUPV3_WRAPPER_ID_BMSK                                                                 0xf
#define HWIO_QUPV3_HW_PARAM_QUPV3_WRAPPER_ID_SHFT                                                                   0

#define HWIO_QUPV3_HW_VERSION_ADDR                                                                         (QUPV3_COMMON_REG_BASE            + 0x4)
#define HWIO_QUPV3_HW_VERSION_PHYS                                                                         (QUPV3_COMMON_REG_BASE_PHYS + 0x4)
#define HWIO_QUPV3_HW_VERSION_OFFS                                                                         (QUPV3_COMMON_REG_BASE_OFFS + 0x4)
#define HWIO_QUPV3_HW_VERSION_RMSK                                                                         0xffffffff
#define HWIO_QUPV3_HW_VERSION_IN                    \
                in_dword(HWIO_QUPV3_HW_VERSION_ADDR)
#define HWIO_QUPV3_HW_VERSION_INM(m)            \
                in_dword_masked(HWIO_QUPV3_HW_VERSION_ADDR, m)
#define HWIO_QUPV3_HW_VERSION_MAJOR_BMSK                                                                   0xf0000000
#define HWIO_QUPV3_HW_VERSION_MAJOR_SHFT                                                                           28
#define HWIO_QUPV3_HW_VERSION_MINOR_BMSK                                                                    0xfff0000
#define HWIO_QUPV3_HW_VERSION_MINOR_SHFT                                                                           16
#define HWIO_QUPV3_HW_VERSION_STEP_BMSK                                                                        0xffff
#define HWIO_QUPV3_HW_VERSION_STEP_SHFT                                                                             0

#define HWIO_QUPV3_STATUS_ADDR                                                                             (QUPV3_COMMON_REG_BASE            + 0x8)
#define HWIO_QUPV3_STATUS_PHYS                                                                             (QUPV3_COMMON_REG_BASE_PHYS + 0x8)
#define HWIO_QUPV3_STATUS_OFFS                                                                             (QUPV3_COMMON_REG_BASE_OFFS + 0x8)
#define HWIO_QUPV3_STATUS_RMSK                                                                                    0x1
#define HWIO_QUPV3_STATUS_IN                    \
                in_dword(HWIO_QUPV3_STATUS_ADDR)
#define HWIO_QUPV3_STATUS_INM(m)            \
                in_dword_masked(HWIO_QUPV3_STATUS_ADDR, m)
#define HWIO_QUPV3_STATUS_GSI_BUSY_BMSK                                                                           0x1
#define HWIO_QUPV3_STATUS_GSI_BUSY_SHFT                                                                             0

#define HWIO_QUPV3_EXT_AHB_ARB_CFG_ADDR                                                                    (QUPV3_COMMON_REG_BASE            + 0x100)
#define HWIO_QUPV3_EXT_AHB_ARB_CFG_PHYS                                                                    (QUPV3_COMMON_REG_BASE_PHYS + 0x100)
#define HWIO_QUPV3_EXT_AHB_ARB_CFG_OFFS                                                                    (QUPV3_COMMON_REG_BASE_OFFS + 0x100)
#define HWIO_QUPV3_EXT_AHB_ARB_CFG_RMSK                                                                           0xf
#define HWIO_QUPV3_EXT_AHB_ARB_CFG_IN                    \
                in_dword(HWIO_QUPV3_EXT_AHB_ARB_CFG_ADDR)
#define HWIO_QUPV3_EXT_AHB_ARB_CFG_INM(m)            \
                in_dword_masked(HWIO_QUPV3_EXT_AHB_ARB_CFG_ADDR, m)
#define HWIO_QUPV3_EXT_AHB_ARB_CFG_OUT(v)            \
                out_dword(HWIO_QUPV3_EXT_AHB_ARB_CFG_ADDR,v)
#define HWIO_QUPV3_EXT_AHB_ARB_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_QUPV3_EXT_AHB_ARB_CFG_ADDR,m,v,HWIO_QUPV3_EXT_AHB_ARB_CFG_IN)
#define HWIO_QUPV3_EXT_AHB_ARB_CFG_ARB_TRANSITION_DEPENDS_HREADYIN_IDLE_BMSK                                      0x8
#define HWIO_QUPV3_EXT_AHB_ARB_CFG_ARB_TRANSITION_DEPENDS_HREADYIN_IDLE_SHFT                                        3
#define HWIO_QUPV3_EXT_AHB_ARB_CFG_UNLOCK_DEPENDS_HSEL_BMSK                                                       0x4
#define HWIO_QUPV3_EXT_AHB_ARB_CFG_UNLOCK_DEPENDS_HSEL_SHFT                                                         2
#define HWIO_QUPV3_EXT_AHB_ARB_CFG_USE_DYNAMIC_HSEL_BMSK                                                          0x2
#define HWIO_QUPV3_EXT_AHB_ARB_CFG_USE_DYNAMIC_HSEL_SHFT                                                            1
#define HWIO_QUPV3_EXT_AHB_ARB_CFG_ARBITRATION_TYPE_BMSK                                                          0x1
#define HWIO_QUPV3_EXT_AHB_ARB_CFG_ARBITRATION_TYPE_SHFT                                                            0

#define HWIO_QUPV3_INT_AHB_ARB_CFG_ADDR                                                                    (QUPV3_COMMON_REG_BASE            + 0x104)
#define HWIO_QUPV3_INT_AHB_ARB_CFG_PHYS                                                                    (QUPV3_COMMON_REG_BASE_PHYS + 0x104)
#define HWIO_QUPV3_INT_AHB_ARB_CFG_OFFS                                                                    (QUPV3_COMMON_REG_BASE_OFFS + 0x104)
#define HWIO_QUPV3_INT_AHB_ARB_CFG_RMSK                                                                           0xf
#define HWIO_QUPV3_INT_AHB_ARB_CFG_IN                    \
                in_dword(HWIO_QUPV3_INT_AHB_ARB_CFG_ADDR)
#define HWIO_QUPV3_INT_AHB_ARB_CFG_INM(m)            \
                in_dword_masked(HWIO_QUPV3_INT_AHB_ARB_CFG_ADDR, m)
#define HWIO_QUPV3_INT_AHB_ARB_CFG_OUT(v)            \
                out_dword(HWIO_QUPV3_INT_AHB_ARB_CFG_ADDR,v)
#define HWIO_QUPV3_INT_AHB_ARB_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_QUPV3_INT_AHB_ARB_CFG_ADDR,m,v,HWIO_QUPV3_INT_AHB_ARB_CFG_IN)
#define HWIO_QUPV3_INT_AHB_ARB_CFG_ARB_TRANSITION_DEPENDS_HREADYIN_IDLE_BMSK                                      0x8
#define HWIO_QUPV3_INT_AHB_ARB_CFG_ARB_TRANSITION_DEPENDS_HREADYIN_IDLE_SHFT                                        3
#define HWIO_QUPV3_INT_AHB_ARB_CFG_UNLOCK_DEPENDS_HSEL_BMSK                                                       0x4
#define HWIO_QUPV3_INT_AHB_ARB_CFG_UNLOCK_DEPENDS_HSEL_SHFT                                                         2
#define HWIO_QUPV3_INT_AHB_ARB_CFG_USE_DYNAMIC_HSEL_BMSK                                                          0x2
#define HWIO_QUPV3_INT_AHB_ARB_CFG_USE_DYNAMIC_HSEL_SHFT                                                            1
#define HWIO_QUPV3_INT_AHB_ARB_CFG_ARBITRATION_TYPE_BMSK                                                          0x1
#define HWIO_QUPV3_INT_AHB_ARB_CFG_ARBITRATION_TYPE_SHFT                                                            0

#define HWIO_QUPV3_GSI_SLAVE_AHB_ARB_CFG_ADDR                                                              (QUPV3_COMMON_REG_BASE            + 0x108)
#define HWIO_QUPV3_GSI_SLAVE_AHB_ARB_CFG_PHYS                                                              (QUPV3_COMMON_REG_BASE_PHYS + 0x108)
#define HWIO_QUPV3_GSI_SLAVE_AHB_ARB_CFG_OFFS                                                              (QUPV3_COMMON_REG_BASE_OFFS + 0x108)
#define HWIO_QUPV3_GSI_SLAVE_AHB_ARB_CFG_RMSK                                                                     0xf
#define HWIO_QUPV3_GSI_SLAVE_AHB_ARB_CFG_IN                    \
                in_dword(HWIO_QUPV3_GSI_SLAVE_AHB_ARB_CFG_ADDR)
#define HWIO_QUPV3_GSI_SLAVE_AHB_ARB_CFG_INM(m)            \
                in_dword_masked(HWIO_QUPV3_GSI_SLAVE_AHB_ARB_CFG_ADDR, m)
#define HWIO_QUPV3_GSI_SLAVE_AHB_ARB_CFG_OUT(v)            \
                out_dword(HWIO_QUPV3_GSI_SLAVE_AHB_ARB_CFG_ADDR,v)
#define HWIO_QUPV3_GSI_SLAVE_AHB_ARB_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_QUPV3_GSI_SLAVE_AHB_ARB_CFG_ADDR,m,v,HWIO_QUPV3_GSI_SLAVE_AHB_ARB_CFG_IN)
#define HWIO_QUPV3_GSI_SLAVE_AHB_ARB_CFG_ARB_TRANSITION_DEPENDS_HREADYIN_IDLE_BMSK                                0x8
#define HWIO_QUPV3_GSI_SLAVE_AHB_ARB_CFG_ARB_TRANSITION_DEPENDS_HREADYIN_IDLE_SHFT                                  3
#define HWIO_QUPV3_GSI_SLAVE_AHB_ARB_CFG_UNLOCK_DEPENDS_HSEL_BMSK                                                 0x4
#define HWIO_QUPV3_GSI_SLAVE_AHB_ARB_CFG_UNLOCK_DEPENDS_HSEL_SHFT                                                   2
#define HWIO_QUPV3_GSI_SLAVE_AHB_ARB_CFG_USE_DYNAMIC_HSEL_BMSK                                                    0x2
#define HWIO_QUPV3_GSI_SLAVE_AHB_ARB_CFG_USE_DYNAMIC_HSEL_SHFT                                                      1
#define HWIO_QUPV3_GSI_SLAVE_AHB_ARB_CFG_ARBITRATION_TYPE_BMSK                                                    0x1
#define HWIO_QUPV3_GSI_SLAVE_AHB_ARB_CFG_ARBITRATION_TYPE_SHFT                                                      0

#define HWIO_QUPV3_SE_IF_IRQ_MASKED_ADDR                                                                   (QUPV3_COMMON_REG_BASE            + 0x110)
#define HWIO_QUPV3_SE_IF_IRQ_MASKED_PHYS                                                                   (QUPV3_COMMON_REG_BASE_PHYS + 0x110)
#define HWIO_QUPV3_SE_IF_IRQ_MASKED_OFFS                                                                   (QUPV3_COMMON_REG_BASE_OFFS + 0x110)
#define HWIO_QUPV3_SE_IF_IRQ_MASKED_RMSK                                                                   0xffffffff
#define HWIO_QUPV3_SE_IF_IRQ_MASKED_IN                    \
                in_dword(HWIO_QUPV3_SE_IF_IRQ_MASKED_ADDR)
#define HWIO_QUPV3_SE_IF_IRQ_MASKED_INM(m)            \
                in_dword_masked(HWIO_QUPV3_SE_IF_IRQ_MASKED_ADDR, m)
#define HWIO_QUPV3_SE_IF_IRQ_MASKED_SE_IF_IRQ_MASKED_BMSK                                                  0xffffffff
#define HWIO_QUPV3_SE_IF_IRQ_MASKED_SE_IF_IRQ_MASKED_SHFT                                                           0

#define HWIO_QUPV3_SE_HMEMTYPE_CFG_ADDR                                                                    (QUPV3_COMMON_REG_BASE            + 0x114)
#define HWIO_QUPV3_SE_HMEMTYPE_CFG_PHYS                                                                    (QUPV3_COMMON_REG_BASE_PHYS + 0x114)
#define HWIO_QUPV3_SE_HMEMTYPE_CFG_OFFS                                                                    (QUPV3_COMMON_REG_BASE_OFFS + 0x114)
#define HWIO_QUPV3_SE_HMEMTYPE_CFG_RMSK                                                                         0x1ff
#define HWIO_QUPV3_SE_HMEMTYPE_CFG_IN                    \
                in_dword(HWIO_QUPV3_SE_HMEMTYPE_CFG_ADDR)
#define HWIO_QUPV3_SE_HMEMTYPE_CFG_INM(m)            \
                in_dword_masked(HWIO_QUPV3_SE_HMEMTYPE_CFG_ADDR, m)
#define HWIO_QUPV3_SE_HMEMTYPE_CFG_OUT(v)            \
                out_dword(HWIO_QUPV3_SE_HMEMTYPE_CFG_ADDR,v)
#define HWIO_QUPV3_SE_HMEMTYPE_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_QUPV3_SE_HMEMTYPE_CFG_ADDR,m,v,HWIO_QUPV3_SE_HMEMTYPE_CFG_IN)
#define HWIO_QUPV3_SE_HMEMTYPE_CFG_HMEMTYPE_WRITE_LAST_BMSK                                                     0x1c0
#define HWIO_QUPV3_SE_HMEMTYPE_CFG_HMEMTYPE_WRITE_LAST_SHFT                                                         6
#define HWIO_QUPV3_SE_HMEMTYPE_CFG_HMEMTYPE_WRITE_MID_TRANS_BMSK                                                 0x38
#define HWIO_QUPV3_SE_HMEMTYPE_CFG_HMEMTYPE_WRITE_MID_TRANS_SHFT                                                    3
#define HWIO_QUPV3_SE_HMEMTYPE_CFG_HMEMTYPE_READ_BMSK                                                             0x7
#define HWIO_QUPV3_SE_HMEMTYPE_CFG_HMEMTYPE_READ_SHFT                                                               0

#define HWIO_QUPV3_SE_AHB_M_CFG_ADDR                                                                       (QUPV3_COMMON_REG_BASE            + 0x118)
#define HWIO_QUPV3_SE_AHB_M_CFG_PHYS                                                                       (QUPV3_COMMON_REG_BASE_PHYS + 0x118)
#define HWIO_QUPV3_SE_AHB_M_CFG_OFFS                                                                       (QUPV3_COMMON_REG_BASE_OFFS + 0x118)
#define HWIO_QUPV3_SE_AHB_M_CFG_RMSK                                                                              0x1
#define HWIO_QUPV3_SE_AHB_M_CFG_IN                    \
                in_dword(HWIO_QUPV3_SE_AHB_M_CFG_ADDR)
#define HWIO_QUPV3_SE_AHB_M_CFG_INM(m)            \
                in_dword_masked(HWIO_QUPV3_SE_AHB_M_CFG_ADDR, m)
#define HWIO_QUPV3_SE_AHB_M_CFG_OUT(v)            \
                out_dword(HWIO_QUPV3_SE_AHB_M_CFG_ADDR,v)
#define HWIO_QUPV3_SE_AHB_M_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_QUPV3_SE_AHB_M_CFG_ADDR,m,v,HWIO_QUPV3_SE_AHB_M_CFG_IN)
#define HWIO_QUPV3_SE_AHB_M_CFG_AHB_M_CLK_CGC_ON_BMSK                                                             0x1
#define HWIO_QUPV3_SE_AHB_M_CFG_AHB_M_CLK_CGC_ON_SHFT                                                               0

#define HWIO_QUPV3_COMMON_CFG_ADDR                                                                         (QUPV3_COMMON_REG_BASE            + 0x120)
#define HWIO_QUPV3_COMMON_CFG_PHYS                                                                         (QUPV3_COMMON_REG_BASE_PHYS + 0x120)
#define HWIO_QUPV3_COMMON_CFG_OFFS                                                                         (QUPV3_COMMON_REG_BASE_OFFS + 0x120)
#define HWIO_QUPV3_COMMON_CFG_RMSK                                                                               0x7f
#define HWIO_QUPV3_COMMON_CFG_IN                    \
                in_dword(HWIO_QUPV3_COMMON_CFG_ADDR)
#define HWIO_QUPV3_COMMON_CFG_INM(m)            \
                in_dword_masked(HWIO_QUPV3_COMMON_CFG_ADDR, m)
#define HWIO_QUPV3_COMMON_CFG_OUT(v)            \
                out_dword(HWIO_QUPV3_COMMON_CFG_ADDR,v)
#define HWIO_QUPV3_COMMON_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_QUPV3_COMMON_CFG_ADDR,m,v,HWIO_QUPV3_COMMON_CFG_IN)
#define HWIO_QUPV3_COMMON_CFG_TLV_IN_TIMESTAMP_IRQ_STATUS_DISABLE_BMSK                                           0x40
#define HWIO_QUPV3_COMMON_CFG_TLV_IN_TIMESTAMP_IRQ_STATUS_DISABLE_SHFT                                              6
#define HWIO_QUPV3_COMMON_CFG_TLV_IN_TIMESTAMP_IRQ_DISABLE_BMSK                                                  0x20
#define HWIO_QUPV3_COMMON_CFG_TLV_IN_TIMESTAMP_IRQ_DISABLE_SHFT                                                     5
#define HWIO_QUPV3_COMMON_CFG_TLV_USER_DATA_READ_DIS_BMSK                                                        0x10
#define HWIO_QUPV3_COMMON_CFG_TLV_USER_DATA_READ_DIS_SHFT                                                           4
#define HWIO_QUPV3_COMMON_CFG_TIE_HREADY_IN_LOOPBACK_BMSK                                                         0x8
#define HWIO_QUPV3_COMMON_CFG_TIE_HREADY_IN_LOOPBACK_SHFT                                                           3
#define HWIO_QUPV3_COMMON_CFG_AHB2AHB_POST_EN_MASTER_BMSK                                                         0x4
#define HWIO_QUPV3_COMMON_CFG_AHB2AHB_POST_EN_MASTER_SHFT                                                           2
#define HWIO_QUPV3_COMMON_CFG_AHB2AHB_POST_EN_SLAVE_BMSK                                                          0x2
#define HWIO_QUPV3_COMMON_CFG_AHB2AHB_POST_EN_SLAVE_SHFT                                                            1
#define HWIO_QUPV3_COMMON_CFG_FAST_SWITCH_TO_HIGH_DISABLE_BMSK                                                    0x1
#define HWIO_QUPV3_COMMON_CFG_FAST_SWITCH_TO_HIGH_DISABLE_SHFT                                                      0

#define HWIO_QUPV3_SE_IF_IRQ_MASKED_H_ADDR                                                                 (QUPV3_COMMON_REG_BASE            + 0x124)
#define HWIO_QUPV3_SE_IF_IRQ_MASKED_H_PHYS                                                                 (QUPV3_COMMON_REG_BASE_PHYS + 0x124)
#define HWIO_QUPV3_SE_IF_IRQ_MASKED_H_OFFS                                                                 (QUPV3_COMMON_REG_BASE_OFFS + 0x124)
#define HWIO_QUPV3_SE_IF_IRQ_MASKED_H_RMSK                                                                 0xffffffff
#define HWIO_QUPV3_SE_IF_IRQ_MASKED_H_IN                    \
                in_dword(HWIO_QUPV3_SE_IF_IRQ_MASKED_H_ADDR)
#define HWIO_QUPV3_SE_IF_IRQ_MASKED_H_INM(m)            \
                in_dword_masked(HWIO_QUPV3_SE_IF_IRQ_MASKED_H_ADDR, m)
#define HWIO_QUPV3_SE_IF_IRQ_MASKED_H_SE_IF_IRQ_MASKED_H_BMSK                                              0xffffffff
#define HWIO_QUPV3_SE_IF_IRQ_MASKED_H_SE_IF_IRQ_MASKED_H_SHFT                                                       0

#define HWIO_QUPV3_TEST_BUS_SEL_ADDR                                                                       (QUPV3_COMMON_REG_BASE            + 0x200)
#define HWIO_QUPV3_TEST_BUS_SEL_PHYS                                                                       (QUPV3_COMMON_REG_BASE_PHYS + 0x200)
#define HWIO_QUPV3_TEST_BUS_SEL_OFFS                                                                       (QUPV3_COMMON_REG_BASE_OFFS + 0x200)
#define HWIO_QUPV3_TEST_BUS_SEL_RMSK                                                                          0x77f3f
#define HWIO_QUPV3_TEST_BUS_SEL_IN                    \
                in_dword(HWIO_QUPV3_TEST_BUS_SEL_ADDR)
#define HWIO_QUPV3_TEST_BUS_SEL_INM(m)            \
                in_dword_masked(HWIO_QUPV3_TEST_BUS_SEL_ADDR, m)
#define HWIO_QUPV3_TEST_BUS_SEL_OUT(v)            \
                out_dword(HWIO_QUPV3_TEST_BUS_SEL_ADDR,v)
#define HWIO_QUPV3_TEST_BUS_SEL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_QUPV3_TEST_BUS_SEL_ADDR,m,v,HWIO_QUPV3_TEST_BUS_SEL_IN)
#define HWIO_QUPV3_TEST_BUS_SEL_SE_WRAPPER_TEST_BUS_SEL_BMSK                                                  0x70000
#define HWIO_QUPV3_TEST_BUS_SEL_SE_WRAPPER_TEST_BUS_SEL_SHFT                                                       16
#define HWIO_QUPV3_TEST_BUS_SEL_SE_WRAPPER_MASTER_TEST_BUS_SEL_BMSK                                            0x7000
#define HWIO_QUPV3_TEST_BUS_SEL_SE_WRAPPER_MASTER_TEST_BUS_SEL_SHFT                                                12
#define HWIO_QUPV3_TEST_BUS_SEL_SLAVE_BRIDGE_TEST_BUS_SEL_BMSK                                                  0xc00
#define HWIO_QUPV3_TEST_BUS_SEL_SLAVE_BRIDGE_TEST_BUS_SEL_SHFT                                                     10
#define HWIO_QUPV3_TEST_BUS_SEL_MASTER_BRIDGE_TEST_BUS_SEL_BMSK                                                 0x300
#define HWIO_QUPV3_TEST_BUS_SEL_MASTER_BRIDGE_TEST_BUS_SEL_SHFT                                                     8
#define HWIO_QUPV3_TEST_BUS_SEL_TOP_TEST_BUS_SEL_BMSK                                                            0x3f
#define HWIO_QUPV3_TEST_BUS_SEL_TOP_TEST_BUS_SEL_SHFT                                                               0

#define HWIO_QUPV3_TEST_BUS_EN_ADDR                                                                        (QUPV3_COMMON_REG_BASE            + 0x204)
#define HWIO_QUPV3_TEST_BUS_EN_PHYS                                                                        (QUPV3_COMMON_REG_BASE_PHYS + 0x204)
#define HWIO_QUPV3_TEST_BUS_EN_OFFS                                                                        (QUPV3_COMMON_REG_BASE_OFFS + 0x204)
#define HWIO_QUPV3_TEST_BUS_EN_RMSK                                                                             0x111
#define HWIO_QUPV3_TEST_BUS_EN_IN                    \
                in_dword(HWIO_QUPV3_TEST_BUS_EN_ADDR)
#define HWIO_QUPV3_TEST_BUS_EN_INM(m)            \
                in_dword_masked(HWIO_QUPV3_TEST_BUS_EN_ADDR, m)
#define HWIO_QUPV3_TEST_BUS_EN_OUT(v)            \
                out_dword(HWIO_QUPV3_TEST_BUS_EN_ADDR,v)
#define HWIO_QUPV3_TEST_BUS_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_QUPV3_TEST_BUS_EN_ADDR,m,v,HWIO_QUPV3_TEST_BUS_EN_IN)
#define HWIO_QUPV3_TEST_BUS_EN_SW_TB_TOGGLE_BMSK                                                                0x100
#define HWIO_QUPV3_TEST_BUS_EN_SW_TB_TOGGLE_SHFT                                                                    8
#define HWIO_QUPV3_TEST_BUS_EN_TEST_BUS_EN_BMSK                                                                  0x10
#define HWIO_QUPV3_TEST_BUS_EN_TEST_BUS_EN_SHFT                                                                     4
#define HWIO_QUPV3_TEST_BUS_EN_TEST_BUS_REG_EN_BMSK                                                               0x1
#define HWIO_QUPV3_TEST_BUS_EN_TEST_BUS_REG_EN_SHFT                                                                 0

#define HWIO_QUPV3_TEST_BUS_REG_ADDR                                                                       (QUPV3_COMMON_REG_BASE            + 0x208)
#define HWIO_QUPV3_TEST_BUS_REG_PHYS                                                                       (QUPV3_COMMON_REG_BASE_PHYS + 0x208)
#define HWIO_QUPV3_TEST_BUS_REG_OFFS                                                                       (QUPV3_COMMON_REG_BASE_OFFS + 0x208)
#define HWIO_QUPV3_TEST_BUS_REG_RMSK                                                                       0xffffffff
#define HWIO_QUPV3_TEST_BUS_REG_IN                    \
                in_dword(HWIO_QUPV3_TEST_BUS_REG_ADDR)
#define HWIO_QUPV3_TEST_BUS_REG_INM(m)            \
                in_dword_masked(HWIO_QUPV3_TEST_BUS_REG_ADDR, m)
#define HWIO_QUPV3_TEST_BUS_REG_TEST_BUS_VALUE_BMSK                                                        0xffffffff
#define HWIO_QUPV3_TEST_BUS_REG_TEST_BUS_VALUE_SHFT                                                                 0

#define HWIO_QUPV3_HW_EVENTS_MUX_CFG_ADDR                                                                  (QUPV3_COMMON_REG_BASE            + 0x20c)
#define HWIO_QUPV3_HW_EVENTS_MUX_CFG_PHYS                                                                  (QUPV3_COMMON_REG_BASE_PHYS + 0x20c)
#define HWIO_QUPV3_HW_EVENTS_MUX_CFG_OFFS                                                                  (QUPV3_COMMON_REG_BASE_OFFS + 0x20c)
#define HWIO_QUPV3_HW_EVENTS_MUX_CFG_RMSK                                                                  0x80003f00
#define HWIO_QUPV3_HW_EVENTS_MUX_CFG_IN                    \
                in_dword(HWIO_QUPV3_HW_EVENTS_MUX_CFG_ADDR)
#define HWIO_QUPV3_HW_EVENTS_MUX_CFG_INM(m)            \
                in_dword_masked(HWIO_QUPV3_HW_EVENTS_MUX_CFG_ADDR, m)
#define HWIO_QUPV3_HW_EVENTS_MUX_CFG_OUT(v)            \
                out_dword(HWIO_QUPV3_HW_EVENTS_MUX_CFG_ADDR,v)
#define HWIO_QUPV3_HW_EVENTS_MUX_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_QUPV3_HW_EVENTS_MUX_CFG_ADDR,m,v,HWIO_QUPV3_HW_EVENTS_MUX_CFG_IN)
#define HWIO_QUPV3_HW_EVENTS_MUX_CFG_HW_EVENTS_EN_BMSK                                                     0x80000000
#define HWIO_QUPV3_HW_EVENTS_MUX_CFG_HW_EVENTS_EN_SHFT                                                             31
#define HWIO_QUPV3_HW_EVENTS_MUX_CFG_HW_EVENTS_SEL_BMSK                                                        0x3f00
#define HWIO_QUPV3_HW_EVENTS_MUX_CFG_HW_EVENTS_SEL_SHFT                                                             8

#define HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_NS_ADDR                                                           (QUPV3_COMMON_REG_BASE            + 0x210)
#define HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_NS_PHYS                                                           (QUPV3_COMMON_REG_BASE_PHYS + 0x210)
#define HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_NS_OFFS                                                           (QUPV3_COMMON_REG_BASE_OFFS + 0x210)
#define HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_NS_RMSK                                                                  0x1
#define HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_NS_IN                    \
                in_dword(HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_NS_ADDR)
#define HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_NS_INM(m)            \
                in_dword_masked(HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_NS_ADDR, m)
#define HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_NS_OUT(v)            \
                out_dword(HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_NS_ADDR,v)
#define HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_NS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_NS_ADDR,m,v,HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_NS_IN)
#define HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_NS_FORCE_TLVOUT_LOOPBACK_NS_BMSK                                         0x1
#define HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_NS_FORCE_TLVOUT_LOOPBACK_NS_SHFT                                           0

#define HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_MSA_ADDR                                                          (QUPV3_COMMON_REG_BASE            + 0x214)
#define HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_MSA_PHYS                                                          (QUPV3_COMMON_REG_BASE_PHYS + 0x214)
#define HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_MSA_OFFS                                                          (QUPV3_COMMON_REG_BASE_OFFS + 0x214)
#define HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_MSA_RMSK                                                                 0x1
#define HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_MSA_IN                    \
                in_dword(HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_MSA_ADDR)
#define HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_MSA_INM(m)            \
                in_dword_masked(HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_MSA_ADDR, m)
#define HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_MSA_OUT(v)            \
                out_dword(HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_MSA_ADDR,v)
#define HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_MSA_OUTM(m,v) \
                out_dword_masked_ns(HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_MSA_ADDR,m,v,HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_MSA_IN)
#define HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_MSA_FORCE_TLVOUT_LOOPBACK_MSA_BMSK                                       0x1
#define HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_MSA_FORCE_TLVOUT_LOOPBACK_MSA_SHFT                                         0

#define HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_SP_ADDR                                                           (QUPV3_COMMON_REG_BASE            + 0x218)
#define HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_SP_PHYS                                                           (QUPV3_COMMON_REG_BASE_PHYS + 0x218)
#define HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_SP_OFFS                                                           (QUPV3_COMMON_REG_BASE_OFFS + 0x218)
#define HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_SP_RMSK                                                                  0x1
#define HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_SP_IN                    \
                in_dword(HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_SP_ADDR)
#define HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_SP_INM(m)            \
                in_dword_masked(HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_SP_ADDR, m)
#define HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_SP_OUT(v)            \
                out_dword(HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_SP_ADDR,v)
#define HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_SP_OUTM(m,v) \
                out_dword_masked_ns(HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_SP_ADDR,m,v,HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_SP_IN)
#define HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_SP_FORCE_TLVOUT_LOOPBACK_SP_BMSK                                         0x1
#define HWIO_QUPV3_FORCE_TLVOUT_LOOPBACK_SP_FORCE_TLVOUT_LOOPBACK_SP_SHFT                                           0

#define HWIO_QUPV3_COMMON_CGC_CTRL_ADDR                                                                    (QUPV3_COMMON_REG_BASE            + 0x21c)
#define HWIO_QUPV3_COMMON_CGC_CTRL_PHYS                                                                    (QUPV3_COMMON_REG_BASE_PHYS + 0x21c)
#define HWIO_QUPV3_COMMON_CGC_CTRL_OFFS                                                                    (QUPV3_COMMON_REG_BASE_OFFS + 0x21c)
#define HWIO_QUPV3_COMMON_CGC_CTRL_RMSK                                                                           0x7
#define HWIO_QUPV3_COMMON_CGC_CTRL_IN                    \
                in_dword(HWIO_QUPV3_COMMON_CGC_CTRL_ADDR)
#define HWIO_QUPV3_COMMON_CGC_CTRL_INM(m)            \
                in_dword_masked(HWIO_QUPV3_COMMON_CGC_CTRL_ADDR, m)
#define HWIO_QUPV3_COMMON_CGC_CTRL_OUT(v)            \
                out_dword(HWIO_QUPV3_COMMON_CGC_CTRL_ADDR,v)
#define HWIO_QUPV3_COMMON_CGC_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_QUPV3_COMMON_CGC_CTRL_ADDR,m,v,HWIO_QUPV3_COMMON_CGC_CTRL_IN)
#define HWIO_QUPV3_COMMON_CGC_CTRL_TLV_OUT_CLK_CGC_ON_BMSK                                                        0x4
#define HWIO_QUPV3_COMMON_CGC_CTRL_TLV_OUT_CLK_CGC_ON_SHFT                                                          2
#define HWIO_QUPV3_COMMON_CGC_CTRL_TLV_IN_CLK_CGC_ON_BMSK                                                         0x2
#define HWIO_QUPV3_COMMON_CGC_CTRL_TLV_IN_CLK_CGC_ON_SHFT                                                           1
#define HWIO_QUPV3_COMMON_CGC_CTRL_COMMON_CSR_SLV_CLK_CGC_ON_BMSK                                                 0x1
#define HWIO_QUPV3_COMMON_CGC_CTRL_COMMON_CSR_SLV_CLK_CGC_ON_SHFT                                                   0

#define HWIO_QUPV3_QTIMER_BIN_ADDR                                                                         (QUPV3_COMMON_REG_BASE            + 0x220)
#define HWIO_QUPV3_QTIMER_BIN_PHYS                                                                         (QUPV3_COMMON_REG_BASE_PHYS + 0x220)
#define HWIO_QUPV3_QTIMER_BIN_OFFS                                                                         (QUPV3_COMMON_REG_BASE_OFFS + 0x220)
#define HWIO_QUPV3_QTIMER_BIN_RMSK                                                                         0xffffffff
#define HWIO_QUPV3_QTIMER_BIN_IN                    \
                in_dword(HWIO_QUPV3_QTIMER_BIN_ADDR)
#define HWIO_QUPV3_QTIMER_BIN_INM(m)            \
                in_dword_masked(HWIO_QUPV3_QTIMER_BIN_ADDR, m)
#define HWIO_QUPV3_QTIMER_BIN_QTIMER_BIN_BMSK                                                              0xffffffff
#define HWIO_QUPV3_QTIMER_BIN_QTIMER_BIN_SHFT                                                                       0

#define HWIO_QUPV3_QTIMER_BIN_MSB_ADDR                                                                     (QUPV3_COMMON_REG_BASE            + 0x224)
#define HWIO_QUPV3_QTIMER_BIN_MSB_PHYS                                                                     (QUPV3_COMMON_REG_BASE_PHYS + 0x224)
#define HWIO_QUPV3_QTIMER_BIN_MSB_OFFS                                                                     (QUPV3_COMMON_REG_BASE_OFFS + 0x224)
#define HWIO_QUPV3_QTIMER_BIN_MSB_RMSK                                                                     0xffffffff
#define HWIO_QUPV3_QTIMER_BIN_MSB_IN                    \
                in_dword(HWIO_QUPV3_QTIMER_BIN_MSB_ADDR)
#define HWIO_QUPV3_QTIMER_BIN_MSB_INM(m)            \
                in_dword_masked(HWIO_QUPV3_QTIMER_BIN_MSB_ADDR, m)
#define HWIO_QUPV3_QTIMER_BIN_MSB_QTIMER_BIN_MSB_BMSK                                                      0xffffffff
#define HWIO_QUPV3_QTIMER_BIN_MSB_QTIMER_BIN_MSB_SHFT                                                               0

#define HWIO_QUPV3_USER_DATA_TX_SEn_ADDR(n)                                                                (QUPV3_COMMON_REG_BASE            + 0X1000 + (0x100*(n)))
#define HWIO_QUPV3_USER_DATA_TX_SEn_PHYS(n)                                                                (QUPV3_COMMON_REG_BASE_PHYS + 0X1000 + (0x100*(n)))
#define HWIO_QUPV3_USER_DATA_TX_SEn_OFFS(n)                                                                (QUPV3_COMMON_REG_BASE_OFFS + 0X1000 + (0x100*(n)))
#define HWIO_QUPV3_USER_DATA_TX_SEn_RMSK                                                                   0xffffffff
#define HWIO_QUPV3_USER_DATA_TX_SEn_MAXn                                                                            4
#define HWIO_QUPV3_USER_DATA_TX_SEn_INI(n)                \
                in_dword_masked(HWIO_QUPV3_USER_DATA_TX_SEn_ADDR(n), HWIO_QUPV3_USER_DATA_TX_SEn_RMSK)
#define HWIO_QUPV3_USER_DATA_TX_SEn_INMI(n,mask)        \
                in_dword_masked(HWIO_QUPV3_USER_DATA_TX_SEn_ADDR(n), mask)
#define HWIO_QUPV3_USER_DATA_TX_SEn_USER_DATA_TX_SE_BMSK                                                   0xffffffff
#define HWIO_QUPV3_USER_DATA_TX_SEn_USER_DATA_TX_SE_SHFT                                                            0

#define HWIO_QUPV3_USER_DATA_RX_SEn_ADDR(n)                                                                (QUPV3_COMMON_REG_BASE            + 0X1004 + (0x100*(n)))
#define HWIO_QUPV3_USER_DATA_RX_SEn_PHYS(n)                                                                (QUPV3_COMMON_REG_BASE_PHYS + 0X1004 + (0x100*(n)))
#define HWIO_QUPV3_USER_DATA_RX_SEn_OFFS(n)                                                                (QUPV3_COMMON_REG_BASE_OFFS + 0X1004 + (0x100*(n)))
#define HWIO_QUPV3_USER_DATA_RX_SEn_RMSK                                                                   0xffffffff
#define HWIO_QUPV3_USER_DATA_RX_SEn_MAXn                                                                            4
#define HWIO_QUPV3_USER_DATA_RX_SEn_INI(n)                \
                in_dword_masked(HWIO_QUPV3_USER_DATA_RX_SEn_ADDR(n), HWIO_QUPV3_USER_DATA_RX_SEn_RMSK)
#define HWIO_QUPV3_USER_DATA_RX_SEn_INMI(n,mask)        \
                in_dword_masked(HWIO_QUPV3_USER_DATA_RX_SEn_ADDR(n), mask)
#define HWIO_QUPV3_USER_DATA_RX_SEn_USER_DATA_RX_SE_BMSK                                                   0xffffffff
#define HWIO_QUPV3_USER_DATA_RX_SEn_USER_DATA_RX_SE_SHFT                                                            0

#define HWIO_QUPV3_USER_DATA_GENI_M_SEn_ADDR(n)                                                            (QUPV3_COMMON_REG_BASE            + 0X1008 + (0x100*(n)))
#define HWIO_QUPV3_USER_DATA_GENI_M_SEn_PHYS(n)                                                            (QUPV3_COMMON_REG_BASE_PHYS + 0X1008 + (0x100*(n)))
#define HWIO_QUPV3_USER_DATA_GENI_M_SEn_OFFS(n)                                                            (QUPV3_COMMON_REG_BASE_OFFS + 0X1008 + (0x100*(n)))
#define HWIO_QUPV3_USER_DATA_GENI_M_SEn_RMSK                                                               0xffffffff
#define HWIO_QUPV3_USER_DATA_GENI_M_SEn_MAXn                                                                        4
#define HWIO_QUPV3_USER_DATA_GENI_M_SEn_INI(n)                \
                in_dword_masked(HWIO_QUPV3_USER_DATA_GENI_M_SEn_ADDR(n), HWIO_QUPV3_USER_DATA_GENI_M_SEn_RMSK)
#define HWIO_QUPV3_USER_DATA_GENI_M_SEn_INMI(n,mask)        \
                in_dword_masked(HWIO_QUPV3_USER_DATA_GENI_M_SEn_ADDR(n), mask)
#define HWIO_QUPV3_USER_DATA_GENI_M_SEn_USER_DATA_GENI_M_SE_BMSK                                           0xffffffff
#define HWIO_QUPV3_USER_DATA_GENI_M_SEn_USER_DATA_GENI_M_SE_SHFT                                                    0

#define HWIO_QUPV3_USER_DATA_GENI_S_SEn_ADDR(n)                                                            (QUPV3_COMMON_REG_BASE            + 0X100C + (0x100*(n)))
#define HWIO_QUPV3_USER_DATA_GENI_S_SEn_PHYS(n)                                                            (QUPV3_COMMON_REG_BASE_PHYS + 0X100C + (0x100*(n)))
#define HWIO_QUPV3_USER_DATA_GENI_S_SEn_OFFS(n)                                                            (QUPV3_COMMON_REG_BASE_OFFS + 0X100C + (0x100*(n)))
#define HWIO_QUPV3_USER_DATA_GENI_S_SEn_RMSK                                                               0xffffffff
#define HWIO_QUPV3_USER_DATA_GENI_S_SEn_MAXn                                                                        4
#define HWIO_QUPV3_USER_DATA_GENI_S_SEn_INI(n)                \
                in_dword_masked(HWIO_QUPV3_USER_DATA_GENI_S_SEn_ADDR(n), HWIO_QUPV3_USER_DATA_GENI_S_SEn_RMSK)
#define HWIO_QUPV3_USER_DATA_GENI_S_SEn_INMI(n,mask)        \
                in_dword_masked(HWIO_QUPV3_USER_DATA_GENI_S_SEn_ADDR(n), mask)
#define HWIO_QUPV3_USER_DATA_GENI_S_SEn_USER_DATA_GENI_S_SE_BMSK                                           0xffffffff
#define HWIO_QUPV3_USER_DATA_GENI_S_SEn_USER_DATA_GENI_S_SE_SHFT                                                    0

#define HWIO_QUPV3_GPII_QADn_ADDR(n)                                                                       (QUPV3_COMMON_REG_BASE            + 0X1A00 + (0x4*(n)))
#define HWIO_QUPV3_GPII_QADn_PHYS(n)                                                                       (QUPV3_COMMON_REG_BASE_PHYS + 0X1A00 + (0x4*(n)))
#define HWIO_QUPV3_GPII_QADn_OFFS(n)                                                                       (QUPV3_COMMON_REG_BASE_OFFS + 0X1A00 + (0x4*(n)))
#define HWIO_QUPV3_GPII_QADn_RMSK                                                                                0x1f
#define HWIO_QUPV3_GPII_QADn_MAXn                                                                                  11
#define HWIO_QUPV3_GPII_QADn_INI(n)                \
                in_dword_masked(HWIO_QUPV3_GPII_QADn_ADDR(n), HWIO_QUPV3_GPII_QADn_RMSK)
#define HWIO_QUPV3_GPII_QADn_INMI(n,mask)        \
                in_dword_masked(HWIO_QUPV3_GPII_QADn_ADDR(n), mask)
#define HWIO_QUPV3_GPII_QADn_OUTI(n,val)        \
                out_dword(HWIO_QUPV3_GPII_QADn_ADDR(n),val)
#define HWIO_QUPV3_GPII_QADn_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_QUPV3_GPII_QADn_ADDR(n),mask,val,HWIO_QUPV3_GPII_QADn_INI(n))
#define HWIO_QUPV3_GPII_QADn_GPII_QADID_BMSK                                                                     0x1f
#define HWIO_QUPV3_GPII_QADn_GPII_QADID_SHFT                                                                        0

/*----------------------------------------------------------------------------
 * MODULE: QUPV3_SE_WRAPPER
 *--------------------------------------------------------------------------*/

#define QUPV3_SE_WRAPPER_REG_BASE (SAILSS_QUPV3_1_QUPV3_ID_1_BASE            + 0x00080000)
#define QUPV3_SE_WRAPPER_REG_BASE_SIZE 0x24000
#define QUPV3_SE_WRAPPER_REG_BASE_USED 0x0
#define QUPV3_SE_WRAPPER_REG_BASE_PHYS (SAILSS_QUPV3_1_QUPV3_ID_1_BASE_PHYS + 0x00080000)
#define QUPV3_SE_WRAPPER_REG_BASE_OFFS 0x00080000

/*----------------------------------------------------------------------------
 * MODULE: GENI4_CFG
 *--------------------------------------------------------------------------*/

#define GENI4_CFG_REG_BASE                                                                         (SAILSS_QUPV3_1_QUPV3_ID_1_BASE            + 0x00080000)
#define GENI4_CFG_REG_BASE_SIZE                                                                    0x100
#define GENI4_CFG_REG_BASE_USED                                                                    0x88
#define GENI4_CFG_REG_BASE_PHYS                                                                    (SAILSS_QUPV3_1_QUPV3_ID_1_BASE_PHYS + 0x00080000)
#define GENI4_CFG_REG_BASE_OFFS                                                                    0x00080000

#define HWIO_GENI_INIT_CFG_REVISION_ADDR                                                           (GENI4_CFG_REG_BASE            + 0x0)
#define HWIO_GENI_INIT_CFG_REVISION_PHYS                                                           (GENI4_CFG_REG_BASE_PHYS + 0x0)
#define HWIO_GENI_INIT_CFG_REVISION_OFFS                                                           (GENI4_CFG_REG_BASE_OFFS + 0x0)
#define HWIO_GENI_INIT_CFG_REVISION_RMSK                                                                 0xff
#define HWIO_GENI_INIT_CFG_REVISION_IN                    \
                in_dword(HWIO_GENI_INIT_CFG_REVISION_ADDR)
#define HWIO_GENI_INIT_CFG_REVISION_INM(m)            \
                in_dword_masked(HWIO_GENI_INIT_CFG_REVISION_ADDR, m)
#define HWIO_GENI_INIT_CFG_REVISION_OUT(v)            \
                out_dword(HWIO_GENI_INIT_CFG_REVISION_ADDR,v)
#define HWIO_GENI_INIT_CFG_REVISION_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_INIT_CFG_REVISION_ADDR,m,v,HWIO_GENI_INIT_CFG_REVISION_IN)
#define HWIO_GENI_INIT_CFG_REVISION_VERSION_BMSK                                                         0xff
#define HWIO_GENI_INIT_CFG_REVISION_VERSION_SHFT                                                            0

#define HWIO_GENI_S_INIT_CFG_REVISION_ADDR                                                         (GENI4_CFG_REG_BASE            + 0x4)
#define HWIO_GENI_S_INIT_CFG_REVISION_PHYS                                                         (GENI4_CFG_REG_BASE_PHYS + 0x4)
#define HWIO_GENI_S_INIT_CFG_REVISION_OFFS                                                         (GENI4_CFG_REG_BASE_OFFS + 0x4)
#define HWIO_GENI_S_INIT_CFG_REVISION_RMSK                                                               0xff
#define HWIO_GENI_S_INIT_CFG_REVISION_IN                    \
                in_dword(HWIO_GENI_S_INIT_CFG_REVISION_ADDR)
#define HWIO_GENI_S_INIT_CFG_REVISION_INM(m)            \
                in_dword_masked(HWIO_GENI_S_INIT_CFG_REVISION_ADDR, m)
#define HWIO_GENI_S_INIT_CFG_REVISION_OUT(v)            \
                out_dword(HWIO_GENI_S_INIT_CFG_REVISION_ADDR,v)
#define HWIO_GENI_S_INIT_CFG_REVISION_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_S_INIT_CFG_REVISION_ADDR,m,v,HWIO_GENI_S_INIT_CFG_REVISION_IN)
#define HWIO_GENI_S_INIT_CFG_REVISION_VERSION_BMSK                                                       0xff
#define HWIO_GENI_S_INIT_CFG_REVISION_VERSION_SHFT                                                          0

#define HWIO_GENI_GENERAL_CFG_ADDR                                                                 (GENI4_CFG_REG_BASE            + 0x10)
#define HWIO_GENI_GENERAL_CFG_PHYS                                                                 (GENI4_CFG_REG_BASE_PHYS + 0x10)
#define HWIO_GENI_GENERAL_CFG_OFFS                                                                 (GENI4_CFG_REG_BASE_OFFS + 0x10)
#define HWIO_GENI_GENERAL_CFG_RMSK                                                                     0x7fff
#define HWIO_GENI_GENERAL_CFG_IN                    \
                in_dword(HWIO_GENI_GENERAL_CFG_ADDR)
#define HWIO_GENI_GENERAL_CFG_INM(m)            \
                in_dword_masked(HWIO_GENI_GENERAL_CFG_ADDR, m)
#define HWIO_GENI_GENERAL_CFG_OUT(v)            \
                out_dword(HWIO_GENI_GENERAL_CFG_ADDR,v)
#define HWIO_GENI_GENERAL_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_GENERAL_CFG_ADDR,m,v,HWIO_GENI_GENERAL_CFG_IN)
#define HWIO_GENI_GENERAL_CFG_EP_MGMT_DISABLE_BMSK                                                     0x4000
#define HWIO_GENI_GENERAL_CFG_EP_MGMT_DISABLE_SHFT                                                         14
#define HWIO_GENI_GENERAL_CFG_FW_FLUSH_WITHOUT_RX_FIFO_WE_DISABLE_BMSK                                 0x2000
#define HWIO_GENI_GENERAL_CFG_FW_FLUSH_WITHOUT_RX_FIFO_WE_DISABLE_SHFT                                     13
#define HWIO_GENI_GENERAL_CFG_FW_READ_LAST_ADDRESS_DIS_BMSK                                            0x1000
#define HWIO_GENI_GENERAL_CFG_FW_READ_LAST_ADDRESS_DIS_SHFT                                                12
#define HWIO_GENI_GENERAL_CFG_SW_IRQ_IO3_DATA_BMSK                                                      0x800
#define HWIO_GENI_GENERAL_CFG_SW_IRQ_IO3_DATA_SHFT                                                         11
#define HWIO_GENI_GENERAL_CFG_GENI_RX_FIFO_BLOCK_WAIT_DIS_BMSK                                          0x400
#define HWIO_GENI_GENERAL_CFG_GENI_RX_FIFO_BLOCK_WAIT_DIS_SHFT                                             10
#define HWIO_GENI_GENERAL_CFG_FIFO_LAST_IND_WAIT_DIS_BMSK                                               0x200
#define HWIO_GENI_GENERAL_CFG_FIFO_LAST_IND_WAIT_DIS_SHFT                                                   9
#define HWIO_GENI_GENERAL_CFG_HRESP_ERR_GENI_RAM_WRITE_EN_BMSK                                          0x100
#define HWIO_GENI_GENERAL_CFG_HRESP_ERR_GENI_RAM_WRITE_EN_SHFT                                              8
#define HWIO_GENI_GENERAL_CFG_HW_IRQ_PEND_CMD_SUPPORT_BMSK                                               0x80
#define HWIO_GENI_GENERAL_CFG_HW_IRQ_PEND_CMD_SUPPORT_SHFT                                                  7
#define HWIO_GENI_GENERAL_CFG_HW_IRQ_ACCESS_CLK_SWITCH_EN_BMSK                                           0x40
#define HWIO_GENI_GENERAL_CFG_HW_IRQ_ACCESS_CLK_SWITCH_EN_SHFT                                              6
#define HWIO_GENI_GENERAL_CFG_TX_CRC_MSB_LSB_BMSK                                                        0x20
#define HWIO_GENI_GENERAL_CFG_TX_CRC_MSB_LSB_SHFT                                                           5
#define HWIO_GENI_GENERAL_CFG_CHAR_HUNT_SR_MSB_LSB_BMSK                                                  0x10
#define HWIO_GENI_GENERAL_CFG_CHAR_HUNT_SR_MSB_LSB_SHFT                                                     4
#define HWIO_GENI_GENERAL_CFG_AUTO_CANCEL_RX_STATUS_SET_BMSK                                              0x8
#define HWIO_GENI_GENERAL_CFG_AUTO_CANCEL_RX_STATUS_SET_SHFT                                                3
#define HWIO_GENI_GENERAL_CFG_CLEAR_IRQS_CMD_START_BMSK                                                   0x4
#define HWIO_GENI_GENERAL_CFG_CLEAR_IRQS_CMD_START_SHFT                                                     2
#define HWIO_GENI_GENERAL_CFG_SW_IRQ_IO2_RX_DATA_BMSK                                                     0x2
#define HWIO_GENI_GENERAL_CFG_SW_IRQ_IO2_RX_DATA_SHFT                                                       1
#define HWIO_GENI_GENERAL_CFG_SW_RX_FIFO_FLUSH_NO_FW_BMSK                                                 0x1
#define HWIO_GENI_GENERAL_CFG_SW_RX_FIFO_FLUSH_NO_FW_SHFT                                                   0

#define HWIO_GENI_RX_FIFO_CTRL_ADDR                                                                (GENI4_CFG_REG_BASE            + 0x14)
#define HWIO_GENI_RX_FIFO_CTRL_PHYS                                                                (GENI4_CFG_REG_BASE_PHYS + 0x14)
#define HWIO_GENI_RX_FIFO_CTRL_OFFS                                                                (GENI4_CFG_REG_BASE_OFFS + 0x14)
#define HWIO_GENI_RX_FIFO_CTRL_RMSK                                                                       0x1
#define HWIO_GENI_RX_FIFO_CTRL_OUT(v)            \
                out_dword(HWIO_GENI_RX_FIFO_CTRL_ADDR,v)
#define HWIO_GENI_RX_FIFO_CTRL_SW_RX_FIFO_FLUSH_BMSK                                                      0x1
#define HWIO_GENI_RX_FIFO_CTRL_SW_RX_FIFO_FLUSH_SHFT                                                        0

#define HWIO_GENI_FORCE_DEFAULT_REG_ADDR                                                           (GENI4_CFG_REG_BASE            + 0x20)
#define HWIO_GENI_FORCE_DEFAULT_REG_PHYS                                                           (GENI4_CFG_REG_BASE_PHYS + 0x20)
#define HWIO_GENI_FORCE_DEFAULT_REG_OFFS                                                           (GENI4_CFG_REG_BASE_OFFS + 0x20)
#define HWIO_GENI_FORCE_DEFAULT_REG_RMSK                                                                  0x1
#define HWIO_GENI_FORCE_DEFAULT_REG_OUT(v)            \
                out_dword(HWIO_GENI_FORCE_DEFAULT_REG_ADDR,v)
#define HWIO_GENI_FORCE_DEFAULT_REG_FORCE_DEFAULT_BMSK                                                    0x1
#define HWIO_GENI_FORCE_DEFAULT_REG_FORCE_DEFAULT_SHFT                                                      0

#define HWIO_GENI_OUTPUT_CTRL_ADDR                                                                 (GENI4_CFG_REG_BASE            + 0x24)
#define HWIO_GENI_OUTPUT_CTRL_PHYS                                                                 (GENI4_CFG_REG_BASE_PHYS + 0x24)
#define HWIO_GENI_OUTPUT_CTRL_OFFS                                                                 (GENI4_CFG_REG_BASE_OFFS + 0x24)
#define HWIO_GENI_OUTPUT_CTRL_RMSK                                                                       0x7f
#define HWIO_GENI_OUTPUT_CTRL_IN                    \
                in_dword(HWIO_GENI_OUTPUT_CTRL_ADDR)
#define HWIO_GENI_OUTPUT_CTRL_INM(m)            \
                in_dword_masked(HWIO_GENI_OUTPUT_CTRL_ADDR, m)
#define HWIO_GENI_OUTPUT_CTRL_OUT(v)            \
                out_dword(HWIO_GENI_OUTPUT_CTRL_ADDR,v)
#define HWIO_GENI_OUTPUT_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_OUTPUT_CTRL_ADDR,m,v,HWIO_GENI_OUTPUT_CTRL_IN)
#define HWIO_GENI_OUTPUT_CTRL_IO_OUTPUT_CTRL_BMSK                                                        0x7f
#define HWIO_GENI_OUTPUT_CTRL_IO_OUTPUT_CTRL_SHFT                                                           0

#define HWIO_GENI_CGC_CTRL_ADDR                                                                    (GENI4_CFG_REG_BASE            + 0x28)
#define HWIO_GENI_CGC_CTRL_PHYS                                                                    (GENI4_CFG_REG_BASE_PHYS + 0x28)
#define HWIO_GENI_CGC_CTRL_OFFS                                                                    (GENI4_CFG_REG_BASE_OFFS + 0x28)
#define HWIO_GENI_CGC_CTRL_RMSK                                                                         0x37f
#define HWIO_GENI_CGC_CTRL_IN                    \
                in_dword(HWIO_GENI_CGC_CTRL_ADDR)
#define HWIO_GENI_CGC_CTRL_INM(m)            \
                in_dword_masked(HWIO_GENI_CGC_CTRL_ADDR, m)
#define HWIO_GENI_CGC_CTRL_OUT(v)            \
                out_dword(HWIO_GENI_CGC_CTRL_ADDR,v)
#define HWIO_GENI_CGC_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CGC_CTRL_ADDR,m,v,HWIO_GENI_CGC_CTRL_IN)
#define HWIO_GENI_CGC_CTRL_PROG_RAM_SCLK_OFF_BMSK                                                       0x200
#define HWIO_GENI_CGC_CTRL_PROG_RAM_SCLK_OFF_SHFT                                                           9
#define HWIO_GENI_CGC_CTRL_PROG_RAM_HCLK_OFF_BMSK                                                       0x100
#define HWIO_GENI_CGC_CTRL_PROG_RAM_HCLK_OFF_SHFT                                                           8
#define HWIO_GENI_CGC_CTRL_EXT_CLK_CGC_ON_BMSK                                                           0x40
#define HWIO_GENI_CGC_CTRL_EXT_CLK_CGC_ON_SHFT                                                              6
#define HWIO_GENI_CGC_CTRL_RX_CLK_CGC_ON_BMSK                                                            0x20
#define HWIO_GENI_CGC_CTRL_RX_CLK_CGC_ON_SHFT                                                               5
#define HWIO_GENI_CGC_CTRL_TX_CLK_CGC_ON_BMSK                                                            0x10
#define HWIO_GENI_CGC_CTRL_TX_CLK_CGC_ON_SHFT                                                               4
#define HWIO_GENI_CGC_CTRL_SCLK_CGC_ON_BMSK                                                               0x8
#define HWIO_GENI_CGC_CTRL_SCLK_CGC_ON_SHFT                                                                 3
#define HWIO_GENI_CGC_CTRL_DATA_AHB_CLK_CGC_ON_BMSK                                                       0x4
#define HWIO_GENI_CGC_CTRL_DATA_AHB_CLK_CGC_ON_SHFT                                                         2
#define HWIO_GENI_CGC_CTRL_CFG_AHB_WR_CLK_CGC_ON_BMSK                                                     0x2
#define HWIO_GENI_CGC_CTRL_CFG_AHB_WR_CLK_CGC_ON_SHFT                                                       1
#define HWIO_GENI_CGC_CTRL_CFG_AHB_CLK_CGC_ON_BMSK                                                        0x1
#define HWIO_GENI_CGC_CTRL_CFG_AHB_CLK_CGC_ON_SHFT                                                          0

#define HWIO_GENI_CHAR_CFG_ADDR                                                                    (GENI4_CFG_REG_BASE            + 0x2c)
#define HWIO_GENI_CHAR_CFG_PHYS                                                                    (GENI4_CFG_REG_BASE_PHYS + 0x2c)
#define HWIO_GENI_CHAR_CFG_OFFS                                                                    (GENI4_CFG_REG_BASE_OFFS + 0x2c)
#define HWIO_GENI_CHAR_CFG_RMSK                                                                    0x3f9fff03
#define HWIO_GENI_CHAR_CFG_IN                    \
                in_dword(HWIO_GENI_CHAR_CFG_ADDR)
#define HWIO_GENI_CHAR_CFG_INM(m)            \
                in_dword_masked(HWIO_GENI_CHAR_CFG_ADDR, m)
#define HWIO_GENI_CHAR_CFG_OUT(v)            \
                out_dword(HWIO_GENI_CHAR_CFG_ADDR,v)
#define HWIO_GENI_CHAR_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CHAR_CFG_ADDR,m,v,HWIO_GENI_CHAR_CFG_IN)
#define HWIO_GENI_CHAR_CFG_CHAR_RX_QSPI_MODE_LANE_SEL_BMSK                                         0x30000000
#define HWIO_GENI_CHAR_CFG_CHAR_RX_QSPI_MODE_LANE_SEL_SHFT                                                 28
#define HWIO_GENI_CHAR_CFG_CHAR_RX_MAIN_SIN_NEG_SEL_BMSK                                            0x8000000
#define HWIO_GENI_CHAR_CFG_CHAR_RX_MAIN_SIN_NEG_SEL_SHFT                                                   27
#define HWIO_GENI_CHAR_CFG_CHAR_RX_MAIN_SIN_MUXED_POS_SEL_BMSK                                      0x4000000
#define HWIO_GENI_CHAR_CFG_CHAR_RX_MAIN_SIN_MUXED_POS_SEL_SHFT                                             26
#define HWIO_GENI_CHAR_CFG_CHAR_RX_MAIN_SIN_POS_SEL_BMSK                                            0x2000000
#define HWIO_GENI_CHAR_CFG_CHAR_RX_MAIN_SIN_POS_SEL_SHFT                                                   25
#define HWIO_GENI_CHAR_CFG_CHAR_TX_SOE_SOUT_POS_SEL_BMSK                                            0x1000000
#define HWIO_GENI_CHAR_CFG_CHAR_TX_SOE_SOUT_POS_SEL_SHFT                                                   24
#define HWIO_GENI_CHAR_CFG_CHAR_CLK_GEN_OUTPUT_SEL_BMSK                                              0x800000
#define HWIO_GENI_CHAR_CFG_CHAR_CLK_GEN_OUTPUT_SEL_SHFT                                                    23
#define HWIO_GENI_CHAR_CFG_CHAR_DDR_MODE_BMSK                                                        0x100000
#define HWIO_GENI_CHAR_CFG_CHAR_DDR_MODE_SHFT                                                              20
#define HWIO_GENI_CHAR_CFG_CHAR_MODE_BMSK                                                             0xff000
#define HWIO_GENI_CHAR_CFG_CHAR_MODE_SHFT                                                                  12
#define HWIO_GENI_CHAR_CFG_CHAR_STATUS_BMSK                                                             0xf00
#define HWIO_GENI_CHAR_CFG_CHAR_STATUS_SHFT                                                                 8
#define HWIO_GENI_CHAR_CFG_ENGINE_SEL_BMSK                                                                0x2
#define HWIO_GENI_CHAR_CFG_ENGINE_SEL_SHFT                                                                  1
#define HWIO_GENI_CHAR_CFG_ENABLE_BMSK                                                                    0x1
#define HWIO_GENI_CHAR_CFG_ENABLE_SHFT                                                                      0

#define HWIO_GENI_CHAR_DATA_n_ADDR(n)                                                              (GENI4_CFG_REG_BASE            + 0X30 + (0x4*(n)))
#define HWIO_GENI_CHAR_DATA_n_PHYS(n)                                                              (GENI4_CFG_REG_BASE_PHYS + 0X30 + (0x4*(n)))
#define HWIO_GENI_CHAR_DATA_n_OFFS(n)                                                              (GENI4_CFG_REG_BASE_OFFS + 0X30 + (0x4*(n)))
#define HWIO_GENI_CHAR_DATA_n_RMSK                                                                     0xffff
#define HWIO_GENI_CHAR_DATA_n_MAXn                                                                          1
#define HWIO_GENI_CHAR_DATA_n_INI(n)                \
                in_dword_masked(HWIO_GENI_CHAR_DATA_n_ADDR(n), HWIO_GENI_CHAR_DATA_n_RMSK)
#define HWIO_GENI_CHAR_DATA_n_INMI(n,mask)        \
                in_dword_masked(HWIO_GENI_CHAR_DATA_n_ADDR(n), mask)
#define HWIO_GENI_CHAR_DATA_n_OUTI(n,val)        \
                out_dword(HWIO_GENI_CHAR_DATA_n_ADDR(n),val)
#define HWIO_GENI_CHAR_DATA_n_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_GENI_CHAR_DATA_n_ADDR(n),mask,val,HWIO_GENI_CHAR_DATA_n_INI(n))
#define HWIO_GENI_CHAR_DATA_n_DIN_ACTUAL_BMSK                                                          0xff00
#define HWIO_GENI_CHAR_DATA_n_DIN_ACTUAL_SHFT                                                               8
#define HWIO_GENI_CHAR_DATA_n_DOUT_DATA_DIN_EXP_BMSK                                                     0xff
#define HWIO_GENI_CHAR_DATA_n_DOUT_DATA_DIN_EXP_SHFT                                                        0

#define HWIO_GENI_CHAR_DLY_ADDR                                                                    (GENI4_CFG_REG_BASE            + 0x3c)
#define HWIO_GENI_CHAR_DLY_PHYS                                                                    (GENI4_CFG_REG_BASE_PHYS + 0x3c)
#define HWIO_GENI_CHAR_DLY_OFFS                                                                    (GENI4_CFG_REG_BASE_OFFS + 0x3c)
#define HWIO_GENI_CHAR_DLY_RMSK                                                                       0xfffff
#define HWIO_GENI_CHAR_DLY_IN                    \
                in_dword(HWIO_GENI_CHAR_DLY_ADDR)
#define HWIO_GENI_CHAR_DLY_INM(m)            \
                in_dword_masked(HWIO_GENI_CHAR_DLY_ADDR, m)
#define HWIO_GENI_CHAR_DLY_OUT(v)            \
                out_dword(HWIO_GENI_CHAR_DLY_ADDR,v)
#define HWIO_GENI_CHAR_DLY_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CHAR_DLY_ADDR,m,v,HWIO_GENI_CHAR_DLY_IN)
#define HWIO_GENI_CHAR_DLY_CHAR_DDR_DELAY_BMSK                                                        0xf0000
#define HWIO_GENI_CHAR_DLY_CHAR_DDR_DELAY_SHFT                                                             16
#define HWIO_GENI_CHAR_DLY_CHAR_RX_TX_DELAY_BMSK                                                       0xf000
#define HWIO_GENI_CHAR_DLY_CHAR_RX_TX_DELAY_SHFT                                                           12
#define HWIO_GENI_CHAR_DLY_CHAR_RX_TX_DELAY_START_BMSK                                                  0xf00
#define HWIO_GENI_CHAR_DLY_CHAR_RX_TX_DELAY_START_SHFT                                                      8
#define HWIO_GENI_CHAR_DLY_CHAR_CLK_DIV_BMSK                                                             0xf0
#define HWIO_GENI_CHAR_DLY_CHAR_CLK_DIV_SHFT                                                                4
#define HWIO_GENI_CHAR_DLY_CHAR_CLK_LOW_EXT_BMSK                                                          0xf
#define HWIO_GENI_CHAR_DLY_CHAR_CLK_LOW_EXT_SHFT                                                            0

#define HWIO_GENI_STATUS_ADDR                                                                      (GENI4_CFG_REG_BASE            + 0x40)
#define HWIO_GENI_STATUS_PHYS                                                                      (GENI4_CFG_REG_BASE_PHYS + 0x40)
#define HWIO_GENI_STATUS_OFFS                                                                      (GENI4_CFG_REG_BASE_OFFS + 0x40)
#define HWIO_GENI_STATUS_RMSK                                                                        0x1fffff
#define HWIO_GENI_STATUS_IN                    \
                in_dword(HWIO_GENI_STATUS_ADDR)
#define HWIO_GENI_STATUS_INM(m)            \
                in_dword_masked(HWIO_GENI_STATUS_ADDR, m)
#define HWIO_GENI_STATUS_S_GENI_CMD_FSM_STATE_BMSK                                                   0x1f0000
#define HWIO_GENI_STATUS_S_GENI_CMD_FSM_STATE_SHFT                                                         16
#define HWIO_GENI_STATUS_NOT_USED_BITS_3_BMSK                                                          0xe000
#define HWIO_GENI_STATUS_NOT_USED_BITS_3_SHFT                                                              13
#define HWIO_GENI_STATUS_S_GENI_CMD_ACTIVE_BMSK                                                        0x1000
#define HWIO_GENI_STATUS_S_GENI_CMD_ACTIVE_SHFT                                                            12
#define HWIO_GENI_STATUS_NOT_USED_BITS_2_BMSK                                                           0xe00
#define HWIO_GENI_STATUS_NOT_USED_BITS_2_SHFT                                                               9
#define HWIO_GENI_STATUS_M_GENI_CMD_FSM_STATE_BMSK                                                      0x1f0
#define HWIO_GENI_STATUS_M_GENI_CMD_FSM_STATE_SHFT                                                          4
#define HWIO_GENI_STATUS_NOT_USED_BITS_1_BMSK                                                             0xe
#define HWIO_GENI_STATUS_NOT_USED_BITS_1_SHFT                                                               1
#define HWIO_GENI_STATUS_M_GENI_CMD_ACTIVE_BMSK                                                           0x1
#define HWIO_GENI_STATUS_M_GENI_CMD_ACTIVE_SHFT                                                             0

#define HWIO_GENI_TEST_BUS_CTRL_ADDR                                                               (GENI4_CFG_REG_BASE            + 0x44)
#define HWIO_GENI_TEST_BUS_CTRL_PHYS                                                               (GENI4_CFG_REG_BASE_PHYS + 0x44)
#define HWIO_GENI_TEST_BUS_CTRL_OFFS                                                               (GENI4_CFG_REG_BASE_OFFS + 0x44)
#define HWIO_GENI_TEST_BUS_CTRL_RMSK                                                                     0x3f
#define HWIO_GENI_TEST_BUS_CTRL_IN                    \
                in_dword(HWIO_GENI_TEST_BUS_CTRL_ADDR)
#define HWIO_GENI_TEST_BUS_CTRL_INM(m)            \
                in_dword_masked(HWIO_GENI_TEST_BUS_CTRL_ADDR, m)
#define HWIO_GENI_TEST_BUS_CTRL_OUT(v)            \
                out_dword(HWIO_GENI_TEST_BUS_CTRL_ADDR,v)
#define HWIO_GENI_TEST_BUS_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_TEST_BUS_CTRL_ADDR,m,v,HWIO_GENI_TEST_BUS_CTRL_IN)
#define HWIO_GENI_TEST_BUS_CTRL_TEST_BUS_SEL_BMSK                                                        0x3f
#define HWIO_GENI_TEST_BUS_CTRL_TEST_BUS_SEL_SHFT                                                           0

#define HWIO_GENI_SER_M_CLK_CFG_ADDR                                                               (GENI4_CFG_REG_BASE            + 0x48)
#define HWIO_GENI_SER_M_CLK_CFG_PHYS                                                               (GENI4_CFG_REG_BASE_PHYS + 0x48)
#define HWIO_GENI_SER_M_CLK_CFG_OFFS                                                               (GENI4_CFG_REG_BASE_OFFS + 0x48)
#define HWIO_GENI_SER_M_CLK_CFG_RMSK                                                                 0xfffff1
#define HWIO_GENI_SER_M_CLK_CFG_IN                    \
                in_dword(HWIO_GENI_SER_M_CLK_CFG_ADDR)
#define HWIO_GENI_SER_M_CLK_CFG_INM(m)            \
                in_dword_masked(HWIO_GENI_SER_M_CLK_CFG_ADDR, m)
#define HWIO_GENI_SER_M_CLK_CFG_OUT(v)            \
                out_dword(HWIO_GENI_SER_M_CLK_CFG_ADDR,v)
#define HWIO_GENI_SER_M_CLK_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_SER_M_CLK_CFG_ADDR,m,v,HWIO_GENI_SER_M_CLK_CFG_IN)
#define HWIO_GENI_SER_M_CLK_CFG_CLK_DIV_VALUE_BMSK                                                   0xfffff0
#define HWIO_GENI_SER_M_CLK_CFG_CLK_DIV_VALUE_SHFT                                                          4
#define HWIO_GENI_SER_M_CLK_CFG_SER_CLK_EN_BMSK                                                           0x1
#define HWIO_GENI_SER_M_CLK_CFG_SER_CLK_EN_SHFT                                                             0

#define HWIO_GENI_SER_S_CLK_CFG_ADDR                                                               (GENI4_CFG_REG_BASE            + 0x4c)
#define HWIO_GENI_SER_S_CLK_CFG_PHYS                                                               (GENI4_CFG_REG_BASE_PHYS + 0x4c)
#define HWIO_GENI_SER_S_CLK_CFG_OFFS                                                               (GENI4_CFG_REG_BASE_OFFS + 0x4c)
#define HWIO_GENI_SER_S_CLK_CFG_RMSK                                                                 0xfffff1
#define HWIO_GENI_SER_S_CLK_CFG_IN                    \
                in_dword(HWIO_GENI_SER_S_CLK_CFG_ADDR)
#define HWIO_GENI_SER_S_CLK_CFG_INM(m)            \
                in_dword_masked(HWIO_GENI_SER_S_CLK_CFG_ADDR, m)
#define HWIO_GENI_SER_S_CLK_CFG_OUT(v)            \
                out_dword(HWIO_GENI_SER_S_CLK_CFG_ADDR,v)
#define HWIO_GENI_SER_S_CLK_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_SER_S_CLK_CFG_ADDR,m,v,HWIO_GENI_SER_S_CLK_CFG_IN)
#define HWIO_GENI_SER_S_CLK_CFG_CLK_DIV_VALUE_BMSK                                                   0xfffff0
#define HWIO_GENI_SER_S_CLK_CFG_CLK_DIV_VALUE_SHFT                                                          4
#define HWIO_GENI_SER_S_CLK_CFG_SER_CLK_EN_BMSK                                                           0x1
#define HWIO_GENI_SER_S_CLK_CFG_SER_CLK_EN_SHFT                                                             0

#define HWIO_GENI_HW_PARAM_ADDR                                                                    (GENI4_CFG_REG_BASE            + 0x50)
#define HWIO_GENI_HW_PARAM_PHYS                                                                    (GENI4_CFG_REG_BASE_PHYS + 0x50)
#define HWIO_GENI_HW_PARAM_OFFS                                                                    (GENI4_CFG_REG_BASE_OFFS + 0x50)
#define HWIO_GENI_HW_PARAM_RMSK                                                                           0x1
#define HWIO_GENI_HW_PARAM_IN                    \
                in_dword(HWIO_GENI_HW_PARAM_ADDR)
#define HWIO_GENI_HW_PARAM_INM(m)            \
                in_dword_masked(HWIO_GENI_HW_PARAM_ADDR, m)
#define HWIO_GENI_HW_PARAM_I2C_MASTER_HUB_BMSK                                                            0x1
#define HWIO_GENI_HW_PARAM_I2C_MASTER_HUB_SHFT                                                              0

#define HWIO_GENI_CLK_CTRL_RO_ADDR                                                                 (GENI4_CFG_REG_BASE            + 0x60)
#define HWIO_GENI_CLK_CTRL_RO_PHYS                                                                 (GENI4_CFG_REG_BASE_PHYS + 0x60)
#define HWIO_GENI_CLK_CTRL_RO_OFFS                                                                 (GENI4_CFG_REG_BASE_OFFS + 0x60)
#define HWIO_GENI_CLK_CTRL_RO_RMSK                                                                        0x1
#define HWIO_GENI_CLK_CTRL_RO_IN                    \
                in_dword(HWIO_GENI_CLK_CTRL_RO_ADDR)
#define HWIO_GENI_CLK_CTRL_RO_INM(m)            \
                in_dword_masked(HWIO_GENI_CLK_CTRL_RO_ADDR, m)
#define HWIO_GENI_CLK_CTRL_RO_SER_CLK_SEL_BMSK                                                            0x1
#define HWIO_GENI_CLK_CTRL_RO_SER_CLK_SEL_SHFT                                                              0

#define HWIO_FIFO_IF_DISABLE_RO_ADDR                                                               (GENI4_CFG_REG_BASE            + 0x64)
#define HWIO_FIFO_IF_DISABLE_RO_PHYS                                                               (GENI4_CFG_REG_BASE_PHYS + 0x64)
#define HWIO_FIFO_IF_DISABLE_RO_OFFS                                                               (GENI4_CFG_REG_BASE_OFFS + 0x64)
#define HWIO_FIFO_IF_DISABLE_RO_RMSK                                                                      0x1
#define HWIO_FIFO_IF_DISABLE_RO_IN                    \
                in_dword(HWIO_FIFO_IF_DISABLE_RO_ADDR)
#define HWIO_FIFO_IF_DISABLE_RO_INM(m)            \
                in_dword_masked(HWIO_FIFO_IF_DISABLE_RO_ADDR, m)
#define HWIO_FIFO_IF_DISABLE_RO_FIFO_IF_DISABLE_BMSK                                                      0x1
#define HWIO_FIFO_IF_DISABLE_RO_FIFO_IF_DISABLE_SHFT                                                        0

#define HWIO_GENI_FW_REVISION_RO_ADDR                                                              (GENI4_CFG_REG_BASE            + 0x68)
#define HWIO_GENI_FW_REVISION_RO_PHYS                                                              (GENI4_CFG_REG_BASE_PHYS + 0x68)
#define HWIO_GENI_FW_REVISION_RO_OFFS                                                              (GENI4_CFG_REG_BASE_OFFS + 0x68)
#define HWIO_GENI_FW_REVISION_RO_RMSK                                                                  0xffff
#define HWIO_GENI_FW_REVISION_RO_IN                    \
                in_dword(HWIO_GENI_FW_REVISION_RO_ADDR)
#define HWIO_GENI_FW_REVISION_RO_INM(m)            \
                in_dword_masked(HWIO_GENI_FW_REVISION_RO_ADDR, m)
#define HWIO_GENI_FW_REVISION_RO_PROTOCOL_BMSK                                                         0xff00
#define HWIO_GENI_FW_REVISION_RO_PROTOCOL_SHFT                                                              8
#define HWIO_GENI_FW_REVISION_RO_VERSION_BMSK                                                            0xff
#define HWIO_GENI_FW_REVISION_RO_VERSION_SHFT                                                               0

#define HWIO_GENI_S_FW_REVISION_RO_ADDR                                                            (GENI4_CFG_REG_BASE            + 0x6c)
#define HWIO_GENI_S_FW_REVISION_RO_PHYS                                                            (GENI4_CFG_REG_BASE_PHYS + 0x6c)
#define HWIO_GENI_S_FW_REVISION_RO_OFFS                                                            (GENI4_CFG_REG_BASE_OFFS + 0x6c)
#define HWIO_GENI_S_FW_REVISION_RO_RMSK                                                                0xffff
#define HWIO_GENI_S_FW_REVISION_RO_IN                    \
                in_dword(HWIO_GENI_S_FW_REVISION_RO_ADDR)
#define HWIO_GENI_S_FW_REVISION_RO_INM(m)            \
                in_dword_masked(HWIO_GENI_S_FW_REVISION_RO_ADDR, m)
#define HWIO_GENI_S_FW_REVISION_RO_PROTOCOL_BMSK                                                       0xff00
#define HWIO_GENI_S_FW_REVISION_RO_PROTOCOL_SHFT                                                            8
#define HWIO_GENI_S_FW_REVISION_RO_VERSION_BMSK                                                          0xff
#define HWIO_GENI_S_FW_REVISION_RO_VERSION_SHFT                                                             0

#define HWIO_GENI_FW_MULTILOCK_PROTNS_RO_ADDR                                                      (GENI4_CFG_REG_BASE            + 0x70)
#define HWIO_GENI_FW_MULTILOCK_PROTNS_RO_PHYS                                                      (GENI4_CFG_REG_BASE_PHYS + 0x70)
#define HWIO_GENI_FW_MULTILOCK_PROTNS_RO_OFFS                                                      (GENI4_CFG_REG_BASE_OFFS + 0x70)
#define HWIO_GENI_FW_MULTILOCK_PROTNS_RO_RMSK                                                             0x1
#define HWIO_GENI_FW_MULTILOCK_PROTNS_RO_IN                    \
                in_dword(HWIO_GENI_FW_MULTILOCK_PROTNS_RO_ADDR)
#define HWIO_GENI_FW_MULTILOCK_PROTNS_RO_INM(m)            \
                in_dword_masked(HWIO_GENI_FW_MULTILOCK_PROTNS_RO_ADDR, m)
#define HWIO_GENI_FW_MULTILOCK_PROTNS_RO_GENI_FW_MULTILOCK_PROTNS_BMSK                                    0x1
#define HWIO_GENI_FW_MULTILOCK_PROTNS_RO_GENI_FW_MULTILOCK_PROTNS_SHFT                                      0

#define HWIO_GENI_FW_MULTILOCK_MSA_RO_ADDR                                                         (GENI4_CFG_REG_BASE            + 0x74)
#define HWIO_GENI_FW_MULTILOCK_MSA_RO_PHYS                                                         (GENI4_CFG_REG_BASE_PHYS + 0x74)
#define HWIO_GENI_FW_MULTILOCK_MSA_RO_OFFS                                                         (GENI4_CFG_REG_BASE_OFFS + 0x74)
#define HWIO_GENI_FW_MULTILOCK_MSA_RO_RMSK                                                                0x1
#define HWIO_GENI_FW_MULTILOCK_MSA_RO_IN                    \
                in_dword(HWIO_GENI_FW_MULTILOCK_MSA_RO_ADDR)
#define HWIO_GENI_FW_MULTILOCK_MSA_RO_INM(m)            \
                in_dword_masked(HWIO_GENI_FW_MULTILOCK_MSA_RO_ADDR, m)
#define HWIO_GENI_FW_MULTILOCK_MSA_RO_GENI_FW_MULTILOCK_MSA_BMSK                                          0x1
#define HWIO_GENI_FW_MULTILOCK_MSA_RO_GENI_FW_MULTILOCK_MSA_SHFT                                            0

#define HWIO_GENI_FW_MULTILOCK_SP_RO_ADDR                                                          (GENI4_CFG_REG_BASE            + 0x78)
#define HWIO_GENI_FW_MULTILOCK_SP_RO_PHYS                                                          (GENI4_CFG_REG_BASE_PHYS + 0x78)
#define HWIO_GENI_FW_MULTILOCK_SP_RO_OFFS                                                          (GENI4_CFG_REG_BASE_OFFS + 0x78)
#define HWIO_GENI_FW_MULTILOCK_SP_RO_RMSK                                                                 0x1
#define HWIO_GENI_FW_MULTILOCK_SP_RO_IN                    \
                in_dword(HWIO_GENI_FW_MULTILOCK_SP_RO_ADDR)
#define HWIO_GENI_FW_MULTILOCK_SP_RO_INM(m)            \
                in_dword_masked(HWIO_GENI_FW_MULTILOCK_SP_RO_ADDR, m)
#define HWIO_GENI_FW_MULTILOCK_SP_RO_GENI_FW_MULTILOCK_SP_BMSK                                            0x1
#define HWIO_GENI_FW_MULTILOCK_SP_RO_GENI_FW_MULTILOCK_SP_SHFT                                              0

#define HWIO_GENI_CLK_SEL_ADDR                                                                     (GENI4_CFG_REG_BASE            + 0x7c)
#define HWIO_GENI_CLK_SEL_PHYS                                                                     (GENI4_CFG_REG_BASE_PHYS + 0x7c)
#define HWIO_GENI_CLK_SEL_OFFS                                                                     (GENI4_CFG_REG_BASE_OFFS + 0x7c)
#define HWIO_GENI_CLK_SEL_RMSK                                                                            0x7
#define HWIO_GENI_CLK_SEL_IN                    \
                in_dword(HWIO_GENI_CLK_SEL_ADDR)
#define HWIO_GENI_CLK_SEL_INM(m)            \
                in_dword_masked(HWIO_GENI_CLK_SEL_ADDR, m)
#define HWIO_GENI_CLK_SEL_OUT(v)            \
                out_dword(HWIO_GENI_CLK_SEL_ADDR,v)
#define HWIO_GENI_CLK_SEL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CLK_SEL_ADDR,m,v,HWIO_GENI_CLK_SEL_IN)
#define HWIO_GENI_CLK_SEL_CLK_SEL_BMSK                                                                    0x7
#define HWIO_GENI_CLK_SEL_CLK_SEL_SHFT                                                                      0

#define HWIO_GENI_DFS_IF_CFG_ADDR                                                                  (GENI4_CFG_REG_BASE            + 0x80)
#define HWIO_GENI_DFS_IF_CFG_PHYS                                                                  (GENI4_CFG_REG_BASE_PHYS + 0x80)
#define HWIO_GENI_DFS_IF_CFG_OFFS                                                                  (GENI4_CFG_REG_BASE_OFFS + 0x80)
#define HWIO_GENI_DFS_IF_CFG_RMSK                                                                       0x701
#define HWIO_GENI_DFS_IF_CFG_IN                    \
                in_dword(HWIO_GENI_DFS_IF_CFG_ADDR)
#define HWIO_GENI_DFS_IF_CFG_INM(m)            \
                in_dword_masked(HWIO_GENI_DFS_IF_CFG_ADDR, m)
#define HWIO_GENI_DFS_IF_CFG_OUT(v)            \
                out_dword(HWIO_GENI_DFS_IF_CFG_ADDR,v)
#define HWIO_GENI_DFS_IF_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_DFS_IF_CFG_ADDR,m,v,HWIO_GENI_DFS_IF_CFG_IN)
#define HWIO_GENI_DFS_IF_CFG_NUM_WAIT_STATES_BMSK                                                       0x700
#define HWIO_GENI_DFS_IF_CFG_NUM_WAIT_STATES_SHFT                                                           8
#define HWIO_GENI_DFS_IF_CFG_DFS_IF_EN_BMSK                                                               0x1
#define HWIO_GENI_DFS_IF_CFG_DFS_IF_EN_SHFT                                                                 0

#define HWIO_GENI_CFG_SEQ_START_ADDR                                                               (GENI4_CFG_REG_BASE            + 0x84)
#define HWIO_GENI_CFG_SEQ_START_PHYS                                                               (GENI4_CFG_REG_BASE_PHYS + 0x84)
#define HWIO_GENI_CFG_SEQ_START_OFFS                                                               (GENI4_CFG_REG_BASE_OFFS + 0x84)
#define HWIO_GENI_CFG_SEQ_START_RMSK                                                                      0x1
#define HWIO_GENI_CFG_SEQ_START_OUT(v)            \
                out_dword(HWIO_GENI_CFG_SEQ_START_ADDR,v)
#define HWIO_GENI_CFG_SEQ_START_START_TRIGGER_BMSK                                                        0x1
#define HWIO_GENI_CFG_SEQ_START_START_TRIGGER_SHFT                                                          0

#define HWIO_GENI_CFG_STATUS_ADDR                                                                  (GENI4_CFG_REG_BASE            + 0x88)
#define HWIO_GENI_CFG_STATUS_PHYS                                                                  (GENI4_CFG_REG_BASE_PHYS + 0x88)
#define HWIO_GENI_CFG_STATUS_OFFS                                                                  (GENI4_CFG_REG_BASE_OFFS + 0x88)
#define HWIO_GENI_CFG_STATUS_RMSK                                                                         0x3
#define HWIO_GENI_CFG_STATUS_IN                    \
                in_dword(HWIO_GENI_CFG_STATUS_ADDR)
#define HWIO_GENI_CFG_STATUS_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_STATUS_ADDR, m)
#define HWIO_GENI_CFG_STATUS_CFG_SEQ_DONE_BMSK                                                            0x2
#define HWIO_GENI_CFG_STATUS_CFG_SEQ_DONE_SHFT                                                              1
#define HWIO_GENI_CFG_STATUS_CLK_MODE_CHANGE_IN_PROGRESS_BMSK                                             0x1
#define HWIO_GENI_CFG_STATUS_CLK_MODE_CHANGE_IN_PROGRESS_SHFT                                               0

/*----------------------------------------------------------------------------
 * MODULE: GENI4_IMAGE_REGS
 *--------------------------------------------------------------------------*/

#define GENI4_IMAGE_REGS_REG_BASE                                                                           (SAILSS_QUPV3_1_QUPV3_ID_1_BASE            + 0x00080100)
#define GENI4_IMAGE_REGS_REG_BASE_SIZE                                                                      0x500
#define GENI4_IMAGE_REGS_REG_BASE_USED                                                                      0x1c4
#define GENI4_IMAGE_REGS_REG_BASE_PHYS                                                                      (SAILSS_QUPV3_1_QUPV3_ID_1_BASE_PHYS + 0x00080100)
#define GENI4_IMAGE_REGS_REG_BASE_OFFS                                                                      0x00080100

#define HWIO_GENI_CFG_REG0_ADDR                                                                             (GENI4_IMAGE_REGS_REG_BASE            + 0x0)
#define HWIO_GENI_CFG_REG0_PHYS                                                                             (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x0)
#define HWIO_GENI_CFG_REG0_OFFS                                                                             (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x0)
#define HWIO_GENI_CFG_REG0_RMSK                                                                               0xffffff
#define HWIO_GENI_CFG_REG0_IN                    \
                in_dword(HWIO_GENI_CFG_REG0_ADDR)
#define HWIO_GENI_CFG_REG0_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG0_ADDR, m)
#define HWIO_GENI_CFG_REG0_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG0_ADDR,v)
#define HWIO_GENI_CFG_REG0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG0_ADDR,m,v,HWIO_GENI_CFG_REG0_IN)
#define HWIO_GENI_CFG_REG0_PRIM_11_TX_DURATION_BMSK                                                           0xc00000
#define HWIO_GENI_CFG_REG0_PRIM_11_TX_DURATION_SHFT                                                                 22
#define HWIO_GENI_CFG_REG0_PRIM_10_TX_DURATION_BMSK                                                           0x300000
#define HWIO_GENI_CFG_REG0_PRIM_10_TX_DURATION_SHFT                                                                 20
#define HWIO_GENI_CFG_REG0_PRIM_9_TX_DURATION_BMSK                                                             0xc0000
#define HWIO_GENI_CFG_REG0_PRIM_9_TX_DURATION_SHFT                                                                  18
#define HWIO_GENI_CFG_REG0_PRIM_8_TX_DURATION_BMSK                                                             0x30000
#define HWIO_GENI_CFG_REG0_PRIM_8_TX_DURATION_SHFT                                                                  16
#define HWIO_GENI_CFG_REG0_PRIM_7_TX_DURATION_BMSK                                                              0xc000
#define HWIO_GENI_CFG_REG0_PRIM_7_TX_DURATION_SHFT                                                                  14
#define HWIO_GENI_CFG_REG0_PRIM_6_TX_DURATION_BMSK                                                              0x3000
#define HWIO_GENI_CFG_REG0_PRIM_6_TX_DURATION_SHFT                                                                  12
#define HWIO_GENI_CFG_REG0_PRIM_5_TX_DURATION_BMSK                                                               0xc00
#define HWIO_GENI_CFG_REG0_PRIM_5_TX_DURATION_SHFT                                                                  10
#define HWIO_GENI_CFG_REG0_PRIM_4_TX_DURATION_BMSK                                                               0x300
#define HWIO_GENI_CFG_REG0_PRIM_4_TX_DURATION_SHFT                                                                   8
#define HWIO_GENI_CFG_REG0_PRIM_3_TX_DURATION_BMSK                                                                0xc0
#define HWIO_GENI_CFG_REG0_PRIM_3_TX_DURATION_SHFT                                                                   6
#define HWIO_GENI_CFG_REG0_PRIM_2_TX_DURATION_BMSK                                                                0x30
#define HWIO_GENI_CFG_REG0_PRIM_2_TX_DURATION_SHFT                                                                   4
#define HWIO_GENI_CFG_REG0_PRIM_1_TX_DURATION_BMSK                                                                 0xc
#define HWIO_GENI_CFG_REG0_PRIM_1_TX_DURATION_SHFT                                                                   2
#define HWIO_GENI_CFG_REG0_PRIM_0_TX_DURATION_BMSK                                                                 0x3
#define HWIO_GENI_CFG_REG0_PRIM_0_TX_DURATION_SHFT                                                                   0

#define HWIO_GENI_CFG_REG1_ADDR                                                                             (GENI4_IMAGE_REGS_REG_BASE            + 0x4)
#define HWIO_GENI_CFG_REG1_PHYS                                                                             (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x4)
#define HWIO_GENI_CFG_REG1_OFFS                                                                             (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x4)
#define HWIO_GENI_CFG_REG1_RMSK                                                                               0xffffff
#define HWIO_GENI_CFG_REG1_IN                    \
                in_dword(HWIO_GENI_CFG_REG1_ADDR)
#define HWIO_GENI_CFG_REG1_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG1_ADDR, m)
#define HWIO_GENI_CFG_REG1_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG1_ADDR,v)
#define HWIO_GENI_CFG_REG1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG1_ADDR,m,v,HWIO_GENI_CFG_REG1_IN)
#define HWIO_GENI_CFG_REG1_PRIM_23_TX_DURATION_BMSK                                                           0xc00000
#define HWIO_GENI_CFG_REG1_PRIM_23_TX_DURATION_SHFT                                                                 22
#define HWIO_GENI_CFG_REG1_PRIM_22_TX_DURATION_BMSK                                                           0x300000
#define HWIO_GENI_CFG_REG1_PRIM_22_TX_DURATION_SHFT                                                                 20
#define HWIO_GENI_CFG_REG1_PRIM_21_TX_DURATION_BMSK                                                            0xc0000
#define HWIO_GENI_CFG_REG1_PRIM_21_TX_DURATION_SHFT                                                                 18
#define HWIO_GENI_CFG_REG1_PRIM_20_TX_DURATION_BMSK                                                            0x30000
#define HWIO_GENI_CFG_REG1_PRIM_20_TX_DURATION_SHFT                                                                 16
#define HWIO_GENI_CFG_REG1_PRIM_19_TX_DURATION_BMSK                                                             0xc000
#define HWIO_GENI_CFG_REG1_PRIM_19_TX_DURATION_SHFT                                                                 14
#define HWIO_GENI_CFG_REG1_PRIM_18_TX_DURATION_BMSK                                                             0x3000
#define HWIO_GENI_CFG_REG1_PRIM_18_TX_DURATION_SHFT                                                                 12
#define HWIO_GENI_CFG_REG1_PRIM_17_TX_DURATION_BMSK                                                              0xc00
#define HWIO_GENI_CFG_REG1_PRIM_17_TX_DURATION_SHFT                                                                 10
#define HWIO_GENI_CFG_REG1_PRIM_16_TX_DURATION_BMSK                                                              0x300
#define HWIO_GENI_CFG_REG1_PRIM_16_TX_DURATION_SHFT                                                                  8
#define HWIO_GENI_CFG_REG1_PRIM_15_TX_DURATION_BMSK                                                               0xc0
#define HWIO_GENI_CFG_REG1_PRIM_15_TX_DURATION_SHFT                                                                  6
#define HWIO_GENI_CFG_REG1_PRIM_14_TX_DURATION_BMSK                                                               0x30
#define HWIO_GENI_CFG_REG1_PRIM_14_TX_DURATION_SHFT                                                                  4
#define HWIO_GENI_CFG_REG1_PRIM_13_TX_DURATION_BMSK                                                                0xc
#define HWIO_GENI_CFG_REG1_PRIM_13_TX_DURATION_SHFT                                                                  2
#define HWIO_GENI_CFG_REG1_PRIM_12_TX_DURATION_BMSK                                                                0x3
#define HWIO_GENI_CFG_REG1_PRIM_12_TX_DURATION_SHFT                                                                  0

#define HWIO_GENI_CFG_REG2_ADDR                                                                             (GENI4_IMAGE_REGS_REG_BASE            + 0x8)
#define HWIO_GENI_CFG_REG2_PHYS                                                                             (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x8)
#define HWIO_GENI_CFG_REG2_OFFS                                                                             (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x8)
#define HWIO_GENI_CFG_REG2_RMSK                                                                               0xffffff
#define HWIO_GENI_CFG_REG2_IN                    \
                in_dword(HWIO_GENI_CFG_REG2_ADDR)
#define HWIO_GENI_CFG_REG2_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG2_ADDR, m)
#define HWIO_GENI_CFG_REG2_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG2_ADDR,v)
#define HWIO_GENI_CFG_REG2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG2_ADDR,m,v,HWIO_GENI_CFG_REG2_IN)
#define HWIO_GENI_CFG_REG2_PRIM_11_RX_DURATION_BMSK                                                           0xc00000
#define HWIO_GENI_CFG_REG2_PRIM_11_RX_DURATION_SHFT                                                                 22
#define HWIO_GENI_CFG_REG2_PRIM_10_RX_DURATION_BMSK                                                           0x300000
#define HWIO_GENI_CFG_REG2_PRIM_10_RX_DURATION_SHFT                                                                 20
#define HWIO_GENI_CFG_REG2_PRIM_9_RX_DURATION_BMSK                                                             0xc0000
#define HWIO_GENI_CFG_REG2_PRIM_9_RX_DURATION_SHFT                                                                  18
#define HWIO_GENI_CFG_REG2_PRIM_8_RX_DURATION_BMSK                                                             0x30000
#define HWIO_GENI_CFG_REG2_PRIM_8_RX_DURATION_SHFT                                                                  16
#define HWIO_GENI_CFG_REG2_PRIM_7_RX_DURATION_BMSK                                                              0xc000
#define HWIO_GENI_CFG_REG2_PRIM_7_RX_DURATION_SHFT                                                                  14
#define HWIO_GENI_CFG_REG2_PRIM_6_RX_DURATION_BMSK                                                              0x3000
#define HWIO_GENI_CFG_REG2_PRIM_6_RX_DURATION_SHFT                                                                  12
#define HWIO_GENI_CFG_REG2_PRIM_5_RX_DURATION_BMSK                                                               0xc00
#define HWIO_GENI_CFG_REG2_PRIM_5_RX_DURATION_SHFT                                                                  10
#define HWIO_GENI_CFG_REG2_PRIM_4_RX_DURATION_BMSK                                                               0x300
#define HWIO_GENI_CFG_REG2_PRIM_4_RX_DURATION_SHFT                                                                   8
#define HWIO_GENI_CFG_REG2_PRIM_3_RX_DURATION_BMSK                                                                0xc0
#define HWIO_GENI_CFG_REG2_PRIM_3_RX_DURATION_SHFT                                                                   6
#define HWIO_GENI_CFG_REG2_PRIM_2_RX_DURATION_BMSK                                                                0x30
#define HWIO_GENI_CFG_REG2_PRIM_2_RX_DURATION_SHFT                                                                   4
#define HWIO_GENI_CFG_REG2_PRIM_1_RX_DURATION_BMSK                                                                 0xc
#define HWIO_GENI_CFG_REG2_PRIM_1_RX_DURATION_SHFT                                                                   2
#define HWIO_GENI_CFG_REG2_PRIM_0_RX_DURATION_BMSK                                                                 0x3
#define HWIO_GENI_CFG_REG2_PRIM_0_RX_DURATION_SHFT                                                                   0

#define HWIO_GENI_CFG_REG3_ADDR                                                                             (GENI4_IMAGE_REGS_REG_BASE            + 0xc)
#define HWIO_GENI_CFG_REG3_PHYS                                                                             (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0xc)
#define HWIO_GENI_CFG_REG3_OFFS                                                                             (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0xc)
#define HWIO_GENI_CFG_REG3_RMSK                                                                               0xffffff
#define HWIO_GENI_CFG_REG3_IN                    \
                in_dword(HWIO_GENI_CFG_REG3_ADDR)
#define HWIO_GENI_CFG_REG3_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG3_ADDR, m)
#define HWIO_GENI_CFG_REG3_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG3_ADDR,v)
#define HWIO_GENI_CFG_REG3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG3_ADDR,m,v,HWIO_GENI_CFG_REG3_IN)
#define HWIO_GENI_CFG_REG3_PRIM_23_RX_DURATION_BMSK                                                           0xc00000
#define HWIO_GENI_CFG_REG3_PRIM_23_RX_DURATION_SHFT                                                                 22
#define HWIO_GENI_CFG_REG3_PRIM_22_RX_DURATION_BMSK                                                           0x300000
#define HWIO_GENI_CFG_REG3_PRIM_22_RX_DURATION_SHFT                                                                 20
#define HWIO_GENI_CFG_REG3_PRIM_21_RX_DURATION_BMSK                                                            0xc0000
#define HWIO_GENI_CFG_REG3_PRIM_21_RX_DURATION_SHFT                                                                 18
#define HWIO_GENI_CFG_REG3_PRIM_20_RX_DURATION_BMSK                                                            0x30000
#define HWIO_GENI_CFG_REG3_PRIM_20_RX_DURATION_SHFT                                                                 16
#define HWIO_GENI_CFG_REG3_PRIM_19_RX_DURATION_BMSK                                                             0xc000
#define HWIO_GENI_CFG_REG3_PRIM_19_RX_DURATION_SHFT                                                                 14
#define HWIO_GENI_CFG_REG3_PRIM_18_RX_DURATION_BMSK                                                             0x3000
#define HWIO_GENI_CFG_REG3_PRIM_18_RX_DURATION_SHFT                                                                 12
#define HWIO_GENI_CFG_REG3_PRIM_17_RX_DURATION_BMSK                                                              0xc00
#define HWIO_GENI_CFG_REG3_PRIM_17_RX_DURATION_SHFT                                                                 10
#define HWIO_GENI_CFG_REG3_PRIM_16_RX_DURATION_BMSK                                                              0x300
#define HWIO_GENI_CFG_REG3_PRIM_16_RX_DURATION_SHFT                                                                  8
#define HWIO_GENI_CFG_REG3_PRIM_15_RX_DURATION_BMSK                                                               0xc0
#define HWIO_GENI_CFG_REG3_PRIM_15_RX_DURATION_SHFT                                                                  6
#define HWIO_GENI_CFG_REG3_PRIM_14_RX_DURATION_BMSK                                                               0x30
#define HWIO_GENI_CFG_REG3_PRIM_14_RX_DURATION_SHFT                                                                  4
#define HWIO_GENI_CFG_REG3_PRIM_13_RX_DURATION_BMSK                                                                0xc
#define HWIO_GENI_CFG_REG3_PRIM_13_RX_DURATION_SHFT                                                                  2
#define HWIO_GENI_CFG_REG3_PRIM_12_RX_DURATION_BMSK                                                                0x3
#define HWIO_GENI_CFG_REG3_PRIM_12_RX_DURATION_SHFT                                                                  0

#define HWIO_GENI_CFG_REG4_ADDR                                                                             (GENI4_IMAGE_REGS_REG_BASE            + 0x10)
#define HWIO_GENI_CFG_REG4_PHYS                                                                             (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x10)
#define HWIO_GENI_CFG_REG4_OFFS                                                                             (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x10)
#define HWIO_GENI_CFG_REG4_RMSK                                                                               0xffffff
#define HWIO_GENI_CFG_REG4_IN                    \
                in_dword(HWIO_GENI_CFG_REG4_ADDR)
#define HWIO_GENI_CFG_REG4_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG4_ADDR, m)
#define HWIO_GENI_CFG_REG4_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG4_ADDR,v)
#define HWIO_GENI_CFG_REG4_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG4_ADDR,m,v,HWIO_GENI_CFG_REG4_IN)
#define HWIO_GENI_CFG_REG4_PRIM_7_TX_FUNC_SEL_BMSK                                                            0xe00000
#define HWIO_GENI_CFG_REG4_PRIM_7_TX_FUNC_SEL_SHFT                                                                  21
#define HWIO_GENI_CFG_REG4_PRIM_6_TX_FUNC_SEL_BMSK                                                            0x1c0000
#define HWIO_GENI_CFG_REG4_PRIM_6_TX_FUNC_SEL_SHFT                                                                  18
#define HWIO_GENI_CFG_REG4_PRIM_5_TX_FUNC_SEL_BMSK                                                             0x38000
#define HWIO_GENI_CFG_REG4_PRIM_5_TX_FUNC_SEL_SHFT                                                                  15
#define HWIO_GENI_CFG_REG4_PRIM_4_TX_FUNC_SEL_BMSK                                                              0x7000
#define HWIO_GENI_CFG_REG4_PRIM_4_TX_FUNC_SEL_SHFT                                                                  12
#define HWIO_GENI_CFG_REG4_PRIM_3_TX_FUNC_SEL_BMSK                                                               0xe00
#define HWIO_GENI_CFG_REG4_PRIM_3_TX_FUNC_SEL_SHFT                                                                   9
#define HWIO_GENI_CFG_REG4_PRIM_2_TX_FUNC_SEL_BMSK                                                               0x1c0
#define HWIO_GENI_CFG_REG4_PRIM_2_TX_FUNC_SEL_SHFT                                                                   6
#define HWIO_GENI_CFG_REG4_PRIM_1_TX_FUNC_SEL_BMSK                                                                0x38
#define HWIO_GENI_CFG_REG4_PRIM_1_TX_FUNC_SEL_SHFT                                                                   3
#define HWIO_GENI_CFG_REG4_PRIM_0_TX_FUNC_SEL_BMSK                                                                 0x7
#define HWIO_GENI_CFG_REG4_PRIM_0_TX_FUNC_SEL_SHFT                                                                   0

#define HWIO_GENI_CFG_REG5_ADDR                                                                             (GENI4_IMAGE_REGS_REG_BASE            + 0x14)
#define HWIO_GENI_CFG_REG5_PHYS                                                                             (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x14)
#define HWIO_GENI_CFG_REG5_OFFS                                                                             (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x14)
#define HWIO_GENI_CFG_REG5_RMSK                                                                               0xffffff
#define HWIO_GENI_CFG_REG5_IN                    \
                in_dword(HWIO_GENI_CFG_REG5_ADDR)
#define HWIO_GENI_CFG_REG5_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG5_ADDR, m)
#define HWIO_GENI_CFG_REG5_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG5_ADDR,v)
#define HWIO_GENI_CFG_REG5_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG5_ADDR,m,v,HWIO_GENI_CFG_REG5_IN)
#define HWIO_GENI_CFG_REG5_PRIM_15_TX_FUNC_SEL_BMSK                                                           0xe00000
#define HWIO_GENI_CFG_REG5_PRIM_15_TX_FUNC_SEL_SHFT                                                                 21
#define HWIO_GENI_CFG_REG5_PRIM_14_TX_FUNC_SEL_BMSK                                                           0x1c0000
#define HWIO_GENI_CFG_REG5_PRIM_14_TX_FUNC_SEL_SHFT                                                                 18
#define HWIO_GENI_CFG_REG5_PRIM_13_TX_FUNC_SEL_BMSK                                                            0x38000
#define HWIO_GENI_CFG_REG5_PRIM_13_TX_FUNC_SEL_SHFT                                                                 15
#define HWIO_GENI_CFG_REG5_PRIM_12_TX_FUNC_SEL_BMSK                                                             0x7000
#define HWIO_GENI_CFG_REG5_PRIM_12_TX_FUNC_SEL_SHFT                                                                 12
#define HWIO_GENI_CFG_REG5_PRIM_11_TX_FUNC_SEL_BMSK                                                              0xe00
#define HWIO_GENI_CFG_REG5_PRIM_11_TX_FUNC_SEL_SHFT                                                                  9
#define HWIO_GENI_CFG_REG5_PRIM_10_TX_FUNC_SEL_BMSK                                                              0x1c0
#define HWIO_GENI_CFG_REG5_PRIM_10_TX_FUNC_SEL_SHFT                                                                  6
#define HWIO_GENI_CFG_REG5_PRIM_9_TX_FUNC_SEL_BMSK                                                                0x38
#define HWIO_GENI_CFG_REG5_PRIM_9_TX_FUNC_SEL_SHFT                                                                   3
#define HWIO_GENI_CFG_REG5_PRIM_8_TX_FUNC_SEL_BMSK                                                                 0x7
#define HWIO_GENI_CFG_REG5_PRIM_8_TX_FUNC_SEL_SHFT                                                                   0

#define HWIO_GENI_CFG_REG6_ADDR                                                                             (GENI4_IMAGE_REGS_REG_BASE            + 0x18)
#define HWIO_GENI_CFG_REG6_PHYS                                                                             (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x18)
#define HWIO_GENI_CFG_REG6_OFFS                                                                             (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x18)
#define HWIO_GENI_CFG_REG6_RMSK                                                                               0xffffff
#define HWIO_GENI_CFG_REG6_IN                    \
                in_dword(HWIO_GENI_CFG_REG6_ADDR)
#define HWIO_GENI_CFG_REG6_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG6_ADDR, m)
#define HWIO_GENI_CFG_REG6_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG6_ADDR,v)
#define HWIO_GENI_CFG_REG6_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG6_ADDR,m,v,HWIO_GENI_CFG_REG6_IN)
#define HWIO_GENI_CFG_REG6_PRIM_23_TX_FUNC_SEL_BMSK                                                           0xe00000
#define HWIO_GENI_CFG_REG6_PRIM_23_TX_FUNC_SEL_SHFT                                                                 21
#define HWIO_GENI_CFG_REG6_PRIM_22_TX_FUNC_SEL_BMSK                                                           0x1c0000
#define HWIO_GENI_CFG_REG6_PRIM_22_TX_FUNC_SEL_SHFT                                                                 18
#define HWIO_GENI_CFG_REG6_PRIM_21_TX_FUNC_SEL_BMSK                                                            0x38000
#define HWIO_GENI_CFG_REG6_PRIM_21_TX_FUNC_SEL_SHFT                                                                 15
#define HWIO_GENI_CFG_REG6_PRIM_20_TX_FUNC_SEL_BMSK                                                             0x7000
#define HWIO_GENI_CFG_REG6_PRIM_20_TX_FUNC_SEL_SHFT                                                                 12
#define HWIO_GENI_CFG_REG6_PRIM_19_TX_FUNC_SEL_BMSK                                                              0xe00
#define HWIO_GENI_CFG_REG6_PRIM_19_TX_FUNC_SEL_SHFT                                                                  9
#define HWIO_GENI_CFG_REG6_PRIM_18_TX_FUNC_SEL_BMSK                                                              0x1c0
#define HWIO_GENI_CFG_REG6_PRIM_18_TX_FUNC_SEL_SHFT                                                                  6
#define HWIO_GENI_CFG_REG6_PRIM_17_TX_FUNC_SEL_BMSK                                                               0x38
#define HWIO_GENI_CFG_REG6_PRIM_17_TX_FUNC_SEL_SHFT                                                                  3
#define HWIO_GENI_CFG_REG6_PRIM_16_TX_FUNC_SEL_BMSK                                                                0x7
#define HWIO_GENI_CFG_REG6_PRIM_16_TX_FUNC_SEL_SHFT                                                                  0

#define HWIO_GENI_CFG_REG7_ADDR                                                                             (GENI4_IMAGE_REGS_REG_BASE            + 0x1c)
#define HWIO_GENI_CFG_REG7_PHYS                                                                             (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x1c)
#define HWIO_GENI_CFG_REG7_OFFS                                                                             (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x1c)
#define HWIO_GENI_CFG_REG7_RMSK                                                                               0xffffff
#define HWIO_GENI_CFG_REG7_IN                    \
                in_dword(HWIO_GENI_CFG_REG7_ADDR)
#define HWIO_GENI_CFG_REG7_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG7_ADDR, m)
#define HWIO_GENI_CFG_REG7_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG7_ADDR,v)
#define HWIO_GENI_CFG_REG7_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG7_ADDR,m,v,HWIO_GENI_CFG_REG7_IN)
#define HWIO_GENI_CFG_REG7_PRIM_23_TX_PAR_FIRST_BMSK                                                          0x800000
#define HWIO_GENI_CFG_REG7_PRIM_23_TX_PAR_FIRST_SHFT                                                                23
#define HWIO_GENI_CFG_REG7_PRIM_22_TX_PAR_FIRST_BMSK                                                          0x400000
#define HWIO_GENI_CFG_REG7_PRIM_22_TX_PAR_FIRST_SHFT                                                                22
#define HWIO_GENI_CFG_REG7_PRIM_21_TX_PAR_FIRST_BMSK                                                          0x200000
#define HWIO_GENI_CFG_REG7_PRIM_21_TX_PAR_FIRST_SHFT                                                                21
#define HWIO_GENI_CFG_REG7_PRIM_20_TX_PAR_FIRST_BMSK                                                          0x100000
#define HWIO_GENI_CFG_REG7_PRIM_20_TX_PAR_FIRST_SHFT                                                                20
#define HWIO_GENI_CFG_REG7_PRIM_19_TX_PAR_FIRST_BMSK                                                           0x80000
#define HWIO_GENI_CFG_REG7_PRIM_19_TX_PAR_FIRST_SHFT                                                                19
#define HWIO_GENI_CFG_REG7_PRIM_18_TX_PAR_FIRST_BMSK                                                           0x40000
#define HWIO_GENI_CFG_REG7_PRIM_18_TX_PAR_FIRST_SHFT                                                                18
#define HWIO_GENI_CFG_REG7_PRIM_17_TX_PAR_FIRST_BMSK                                                           0x20000
#define HWIO_GENI_CFG_REG7_PRIM_17_TX_PAR_FIRST_SHFT                                                                17
#define HWIO_GENI_CFG_REG7_PRIM_16_TX_PAR_FIRST_BMSK                                                           0x10000
#define HWIO_GENI_CFG_REG7_PRIM_16_TX_PAR_FIRST_SHFT                                                                16
#define HWIO_GENI_CFG_REG7_PRIM_15_TX_PAR_FIRST_BMSK                                                            0x8000
#define HWIO_GENI_CFG_REG7_PRIM_15_TX_PAR_FIRST_SHFT                                                                15
#define HWIO_GENI_CFG_REG7_PRIM_14_TX_PAR_FIRST_BMSK                                                            0x4000
#define HWIO_GENI_CFG_REG7_PRIM_14_TX_PAR_FIRST_SHFT                                                                14
#define HWIO_GENI_CFG_REG7_PRIM_13_TX_PAR_FIRST_BMSK                                                            0x2000
#define HWIO_GENI_CFG_REG7_PRIM_13_TX_PAR_FIRST_SHFT                                                                13
#define HWIO_GENI_CFG_REG7_PRIM_12_TX_PAR_FIRST_BMSK                                                            0x1000
#define HWIO_GENI_CFG_REG7_PRIM_12_TX_PAR_FIRST_SHFT                                                                12
#define HWIO_GENI_CFG_REG7_PRIM_11_TX_PAR_FIRST_BMSK                                                             0x800
#define HWIO_GENI_CFG_REG7_PRIM_11_TX_PAR_FIRST_SHFT                                                                11
#define HWIO_GENI_CFG_REG7_PRIM_10_TX_PAR_FIRST_BMSK                                                             0x400
#define HWIO_GENI_CFG_REG7_PRIM_10_TX_PAR_FIRST_SHFT                                                                10
#define HWIO_GENI_CFG_REG7_PRIM_9_TX_PAR_FIRST_BMSK                                                              0x200
#define HWIO_GENI_CFG_REG7_PRIM_9_TX_PAR_FIRST_SHFT                                                                  9
#define HWIO_GENI_CFG_REG7_PRIM_8_TX_PAR_FIRST_BMSK                                                              0x100
#define HWIO_GENI_CFG_REG7_PRIM_8_TX_PAR_FIRST_SHFT                                                                  8
#define HWIO_GENI_CFG_REG7_PRIM_7_TX_PAR_FIRST_BMSK                                                               0x80
#define HWIO_GENI_CFG_REG7_PRIM_7_TX_PAR_FIRST_SHFT                                                                  7
#define HWIO_GENI_CFG_REG7_PRIM_6_TX_PAR_FIRST_BMSK                                                               0x40
#define HWIO_GENI_CFG_REG7_PRIM_6_TX_PAR_FIRST_SHFT                                                                  6
#define HWIO_GENI_CFG_REG7_PRIM_5_TX_PAR_FIRST_BMSK                                                               0x20
#define HWIO_GENI_CFG_REG7_PRIM_5_TX_PAR_FIRST_SHFT                                                                  5
#define HWIO_GENI_CFG_REG7_PRIM_4_TX_PAR_FIRST_BMSK                                                               0x10
#define HWIO_GENI_CFG_REG7_PRIM_4_TX_PAR_FIRST_SHFT                                                                  4
#define HWIO_GENI_CFG_REG7_PRIM_3_TX_PAR_FIRST_BMSK                                                                0x8
#define HWIO_GENI_CFG_REG7_PRIM_3_TX_PAR_FIRST_SHFT                                                                  3
#define HWIO_GENI_CFG_REG7_PRIM_2_TX_PAR_FIRST_BMSK                                                                0x4
#define HWIO_GENI_CFG_REG7_PRIM_2_TX_PAR_FIRST_SHFT                                                                  2
#define HWIO_GENI_CFG_REG7_PRIM_1_TX_PAR_FIRST_BMSK                                                                0x2
#define HWIO_GENI_CFG_REG7_PRIM_1_TX_PAR_FIRST_SHFT                                                                  1
#define HWIO_GENI_CFG_REG7_PRIM_0_TX_PAR_FIRST_BMSK                                                                0x1
#define HWIO_GENI_CFG_REG7_PRIM_0_TX_PAR_FIRST_SHFT                                                                  0

#define HWIO_GENI_CFG_REG8_ADDR                                                                             (GENI4_IMAGE_REGS_REG_BASE            + 0x20)
#define HWIO_GENI_CFG_REG8_PHYS                                                                             (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x20)
#define HWIO_GENI_CFG_REG8_OFFS                                                                             (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x20)
#define HWIO_GENI_CFG_REG8_RMSK                                                                               0xffffff
#define HWIO_GENI_CFG_REG8_IN                    \
                in_dword(HWIO_GENI_CFG_REG8_ADDR)
#define HWIO_GENI_CFG_REG8_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG8_ADDR, m)
#define HWIO_GENI_CFG_REG8_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG8_ADDR,v)
#define HWIO_GENI_CFG_REG8_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG8_ADDR,m,v,HWIO_GENI_CFG_REG8_IN)
#define HWIO_GENI_CFG_REG8_PRIM_23_TX_DUMMY_DATA_EN_BMSK                                                      0x800000
#define HWIO_GENI_CFG_REG8_PRIM_23_TX_DUMMY_DATA_EN_SHFT                                                            23
#define HWIO_GENI_CFG_REG8_PRIM_22_TX_DUMMY_DATA_EN_BMSK                                                      0x400000
#define HWIO_GENI_CFG_REG8_PRIM_22_TX_DUMMY_DATA_EN_SHFT                                                            22
#define HWIO_GENI_CFG_REG8_PRIM_21_TX_DUMMY_DATA_EN_BMSK                                                      0x200000
#define HWIO_GENI_CFG_REG8_PRIM_21_TX_DUMMY_DATA_EN_SHFT                                                            21
#define HWIO_GENI_CFG_REG8_PRIM_20_TX_DUMMY_DATA_EN_BMSK                                                      0x100000
#define HWIO_GENI_CFG_REG8_PRIM_20_TX_DUMMY_DATA_EN_SHFT                                                            20
#define HWIO_GENI_CFG_REG8_PRIM_19_TX_DUMMY_DATA_EN_BMSK                                                       0x80000
#define HWIO_GENI_CFG_REG8_PRIM_19_TX_DUMMY_DATA_EN_SHFT                                                            19
#define HWIO_GENI_CFG_REG8_PRIM_18_TX_DUMMY_DATA_EN_BMSK                                                       0x40000
#define HWIO_GENI_CFG_REG8_PRIM_18_TX_DUMMY_DATA_EN_SHFT                                                            18
#define HWIO_GENI_CFG_REG8_PRIM_17_TX_DUMMY_DATA_EN_BMSK                                                       0x20000
#define HWIO_GENI_CFG_REG8_PRIM_17_TX_DUMMY_DATA_EN_SHFT                                                            17
#define HWIO_GENI_CFG_REG8_PRIM_16_TX_DUMMY_DATA_EN_BMSK                                                       0x10000
#define HWIO_GENI_CFG_REG8_PRIM_16_TX_DUMMY_DATA_EN_SHFT                                                            16
#define HWIO_GENI_CFG_REG8_PRIM_15_TX_DUMMY_DATA_EN_BMSK                                                        0x8000
#define HWIO_GENI_CFG_REG8_PRIM_15_TX_DUMMY_DATA_EN_SHFT                                                            15
#define HWIO_GENI_CFG_REG8_PRIM_14_TX_DUMMY_DATA_EN_BMSK                                                        0x4000
#define HWIO_GENI_CFG_REG8_PRIM_14_TX_DUMMY_DATA_EN_SHFT                                                            14
#define HWIO_GENI_CFG_REG8_PRIM_13_TX_DUMMY_DATA_EN_BMSK                                                        0x2000
#define HWIO_GENI_CFG_REG8_PRIM_13_TX_DUMMY_DATA_EN_SHFT                                                            13
#define HWIO_GENI_CFG_REG8_PRIM_12_TX_DUMMY_DATA_EN_BMSK                                                        0x1000
#define HWIO_GENI_CFG_REG8_PRIM_12_TX_DUMMY_DATA_EN_SHFT                                                            12
#define HWIO_GENI_CFG_REG8_PRIM_11_TX_DUMMY_DATA_EN_BMSK                                                         0x800
#define HWIO_GENI_CFG_REG8_PRIM_11_TX_DUMMY_DATA_EN_SHFT                                                            11
#define HWIO_GENI_CFG_REG8_PRIM_10_TX_DUMMY_DATA_EN_BMSK                                                         0x400
#define HWIO_GENI_CFG_REG8_PRIM_10_TX_DUMMY_DATA_EN_SHFT                                                            10
#define HWIO_GENI_CFG_REG8_PRIM_9_TX_DUMMY_DATA_EN_BMSK                                                          0x200
#define HWIO_GENI_CFG_REG8_PRIM_9_TX_DUMMY_DATA_EN_SHFT                                                              9
#define HWIO_GENI_CFG_REG8_PRIM_8_TX_DUMMY_DATA_EN_BMSK                                                          0x100
#define HWIO_GENI_CFG_REG8_PRIM_8_TX_DUMMY_DATA_EN_SHFT                                                              8
#define HWIO_GENI_CFG_REG8_PRIM_7_TX_DUMMY_DATA_EN_BMSK                                                           0x80
#define HWIO_GENI_CFG_REG8_PRIM_7_TX_DUMMY_DATA_EN_SHFT                                                              7
#define HWIO_GENI_CFG_REG8_PRIM_6_TX_DUMMY_DATA_EN_BMSK                                                           0x40
#define HWIO_GENI_CFG_REG8_PRIM_6_TX_DUMMY_DATA_EN_SHFT                                                              6
#define HWIO_GENI_CFG_REG8_PRIM_5_TX_DUMMY_DATA_EN_BMSK                                                           0x20
#define HWIO_GENI_CFG_REG8_PRIM_5_TX_DUMMY_DATA_EN_SHFT                                                              5
#define HWIO_GENI_CFG_REG8_PRIM_4_TX_DUMMY_DATA_EN_BMSK                                                           0x10
#define HWIO_GENI_CFG_REG8_PRIM_4_TX_DUMMY_DATA_EN_SHFT                                                              4
#define HWIO_GENI_CFG_REG8_PRIM_3_TX_DUMMY_DATA_EN_BMSK                                                            0x8
#define HWIO_GENI_CFG_REG8_PRIM_3_TX_DUMMY_DATA_EN_SHFT                                                              3
#define HWIO_GENI_CFG_REG8_PRIM_2_TX_DUMMY_DATA_EN_BMSK                                                            0x4
#define HWIO_GENI_CFG_REG8_PRIM_2_TX_DUMMY_DATA_EN_SHFT                                                              2
#define HWIO_GENI_CFG_REG8_PRIM_1_TX_DUMMY_DATA_EN_BMSK                                                            0x2
#define HWIO_GENI_CFG_REG8_PRIM_1_TX_DUMMY_DATA_EN_SHFT                                                              1
#define HWIO_GENI_CFG_REG8_PRIM_0_TX_DUMMY_DATA_EN_BMSK                                                            0x1
#define HWIO_GENI_CFG_REG8_PRIM_0_TX_DUMMY_DATA_EN_SHFT                                                              0

#define HWIO_GENI_CFG_REG9_ADDR                                                                             (GENI4_IMAGE_REGS_REG_BASE            + 0x24)
#define HWIO_GENI_CFG_REG9_PHYS                                                                             (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x24)
#define HWIO_GENI_CFG_REG9_OFFS                                                                             (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x24)
#define HWIO_GENI_CFG_REG9_RMSK                                                                               0xffffff
#define HWIO_GENI_CFG_REG9_IN                    \
                in_dword(HWIO_GENI_CFG_REG9_ADDR)
#define HWIO_GENI_CFG_REG9_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG9_ADDR, m)
#define HWIO_GENI_CFG_REG9_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG9_ADDR,v)
#define HWIO_GENI_CFG_REG9_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG9_ADDR,m,v,HWIO_GENI_CFG_REG9_IN)
#define HWIO_GENI_CFG_REG9_PRIM_23_TX_DUMMY_PARAM_EN_BMSK                                                     0x800000
#define HWIO_GENI_CFG_REG9_PRIM_23_TX_DUMMY_PARAM_EN_SHFT                                                           23
#define HWIO_GENI_CFG_REG9_PRIM_22_TX_DUMMY_PARAM_EN_BMSK                                                     0x400000
#define HWIO_GENI_CFG_REG9_PRIM_22_TX_DUMMY_PARAM_EN_SHFT                                                           22
#define HWIO_GENI_CFG_REG9_PRIM_21_TX_DUMMY_PARAM_EN_BMSK                                                     0x200000
#define HWIO_GENI_CFG_REG9_PRIM_21_TX_DUMMY_PARAM_EN_SHFT                                                           21
#define HWIO_GENI_CFG_REG9_PRIM_20_TX_DUMMY_PARAM_EN_BMSK                                                     0x100000
#define HWIO_GENI_CFG_REG9_PRIM_20_TX_DUMMY_PARAM_EN_SHFT                                                           20
#define HWIO_GENI_CFG_REG9_PRIM_19_TX_DUMMY_PARAM_EN_BMSK                                                      0x80000
#define HWIO_GENI_CFG_REG9_PRIM_19_TX_DUMMY_PARAM_EN_SHFT                                                           19
#define HWIO_GENI_CFG_REG9_PRIM_18_TX_DUMMY_PARAM_EN_BMSK                                                      0x40000
#define HWIO_GENI_CFG_REG9_PRIM_18_TX_DUMMY_PARAM_EN_SHFT                                                           18
#define HWIO_GENI_CFG_REG9_PRIM_17_TX_DUMMY_PARAM_EN_BMSK                                                      0x20000
#define HWIO_GENI_CFG_REG9_PRIM_17_TX_DUMMY_PARAM_EN_SHFT                                                           17
#define HWIO_GENI_CFG_REG9_PRIM_16_TX_DUMMY_PARAM_EN_BMSK                                                      0x10000
#define HWIO_GENI_CFG_REG9_PRIM_16_TX_DUMMY_PARAM_EN_SHFT                                                           16
#define HWIO_GENI_CFG_REG9_PRIM_15_TX_DUMMY_PARAM_EN_BMSK                                                       0x8000
#define HWIO_GENI_CFG_REG9_PRIM_15_TX_DUMMY_PARAM_EN_SHFT                                                           15
#define HWIO_GENI_CFG_REG9_PRIM_14_TX_DUMMY_PARAM_EN_BMSK                                                       0x4000
#define HWIO_GENI_CFG_REG9_PRIM_14_TX_DUMMY_PARAM_EN_SHFT                                                           14
#define HWIO_GENI_CFG_REG9_PRIM_13_TX_DUMMY_PARAM_EN_BMSK                                                       0x2000
#define HWIO_GENI_CFG_REG9_PRIM_13_TX_DUMMY_PARAM_EN_SHFT                                                           13
#define HWIO_GENI_CFG_REG9_PRIM_12_TX_DUMMY_PARAM_EN_BMSK                                                       0x1000
#define HWIO_GENI_CFG_REG9_PRIM_12_TX_DUMMY_PARAM_EN_SHFT                                                           12
#define HWIO_GENI_CFG_REG9_PRIM_11_TX_DUMMY_PARAM_EN_BMSK                                                        0x800
#define HWIO_GENI_CFG_REG9_PRIM_11_TX_DUMMY_PARAM_EN_SHFT                                                           11
#define HWIO_GENI_CFG_REG9_PRIM_10_TX_DUMMY_PARAM_EN_BMSK                                                        0x400
#define HWIO_GENI_CFG_REG9_PRIM_10_TX_DUMMY_PARAM_EN_SHFT                                                           10
#define HWIO_GENI_CFG_REG9_PRIM_9_TX_DUMMY_PARAM_EN_BMSK                                                         0x200
#define HWIO_GENI_CFG_REG9_PRIM_9_TX_DUMMY_PARAM_EN_SHFT                                                             9
#define HWIO_GENI_CFG_REG9_PRIM_8_TX_DUMMY_PARAM_EN_BMSK                                                         0x100
#define HWIO_GENI_CFG_REG9_PRIM_8_TX_DUMMY_PARAM_EN_SHFT                                                             8
#define HWIO_GENI_CFG_REG9_PRIM_7_TX_DUMMY_PARAM_EN_BMSK                                                          0x80
#define HWIO_GENI_CFG_REG9_PRIM_7_TX_DUMMY_PARAM_EN_SHFT                                                             7
#define HWIO_GENI_CFG_REG9_PRIM_6_TX_DUMMY_PARAM_EN_BMSK                                                          0x40
#define HWIO_GENI_CFG_REG9_PRIM_6_TX_DUMMY_PARAM_EN_SHFT                                                             6
#define HWIO_GENI_CFG_REG9_PRIM_5_TX_DUMMY_PARAM_EN_BMSK                                                          0x20
#define HWIO_GENI_CFG_REG9_PRIM_5_TX_DUMMY_PARAM_EN_SHFT                                                             5
#define HWIO_GENI_CFG_REG9_PRIM_4_TX_DUMMY_PARAM_EN_BMSK                                                          0x10
#define HWIO_GENI_CFG_REG9_PRIM_4_TX_DUMMY_PARAM_EN_SHFT                                                             4
#define HWIO_GENI_CFG_REG9_PRIM_3_TX_DUMMY_PARAM_EN_BMSK                                                           0x8
#define HWIO_GENI_CFG_REG9_PRIM_3_TX_DUMMY_PARAM_EN_SHFT                                                             3
#define HWIO_GENI_CFG_REG9_PRIM_2_TX_DUMMY_PARAM_EN_BMSK                                                           0x4
#define HWIO_GENI_CFG_REG9_PRIM_2_TX_DUMMY_PARAM_EN_SHFT                                                             2
#define HWIO_GENI_CFG_REG9_PRIM_1_TX_DUMMY_PARAM_EN_BMSK                                                           0x2
#define HWIO_GENI_CFG_REG9_PRIM_1_TX_DUMMY_PARAM_EN_SHFT                                                             1
#define HWIO_GENI_CFG_REG9_PRIM_0_TX_DUMMY_PARAM_EN_BMSK                                                           0x1
#define HWIO_GENI_CFG_REG9_PRIM_0_TX_DUMMY_PARAM_EN_SHFT                                                             0

#define HWIO_GENI_CFG_REG10_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x28)
#define HWIO_GENI_CFG_REG10_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x28)
#define HWIO_GENI_CFG_REG10_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x28)
#define HWIO_GENI_CFG_REG10_RMSK                                                                              0xffffff
#define HWIO_GENI_CFG_REG10_IN                    \
                in_dword(HWIO_GENI_CFG_REG10_ADDR)
#define HWIO_GENI_CFG_REG10_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG10_ADDR, m)
#define HWIO_GENI_CFG_REG10_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG10_ADDR,v)
#define HWIO_GENI_CFG_REG10_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG10_ADDR,m,v,HWIO_GENI_CFG_REG10_IN)
#define HWIO_GENI_CFG_REG10_PRIM_23_RX_SI_EN_BMSK                                                             0x800000
#define HWIO_GENI_CFG_REG10_PRIM_23_RX_SI_EN_SHFT                                                                   23
#define HWIO_GENI_CFG_REG10_PRIM_22_RX_SI_EN_BMSK                                                             0x400000
#define HWIO_GENI_CFG_REG10_PRIM_22_RX_SI_EN_SHFT                                                                   22
#define HWIO_GENI_CFG_REG10_PRIM_21_RX_SI_EN_BMSK                                                             0x200000
#define HWIO_GENI_CFG_REG10_PRIM_21_RX_SI_EN_SHFT                                                                   21
#define HWIO_GENI_CFG_REG10_PRIM_20_RX_SI_EN_BMSK                                                             0x100000
#define HWIO_GENI_CFG_REG10_PRIM_20_RX_SI_EN_SHFT                                                                   20
#define HWIO_GENI_CFG_REG10_PRIM_19_RX_SI_EN_BMSK                                                              0x80000
#define HWIO_GENI_CFG_REG10_PRIM_19_RX_SI_EN_SHFT                                                                   19
#define HWIO_GENI_CFG_REG10_PRIM_18_RX_SI_EN_BMSK                                                              0x40000
#define HWIO_GENI_CFG_REG10_PRIM_18_RX_SI_EN_SHFT                                                                   18
#define HWIO_GENI_CFG_REG10_PRIM_17_RX_SI_EN_BMSK                                                              0x20000
#define HWIO_GENI_CFG_REG10_PRIM_17_RX_SI_EN_SHFT                                                                   17
#define HWIO_GENI_CFG_REG10_PRIM_16_RX_SI_EN_BMSK                                                              0x10000
#define HWIO_GENI_CFG_REG10_PRIM_16_RX_SI_EN_SHFT                                                                   16
#define HWIO_GENI_CFG_REG10_PRIM_15_RX_SI_EN_BMSK                                                               0x8000
#define HWIO_GENI_CFG_REG10_PRIM_15_RX_SI_EN_SHFT                                                                   15
#define HWIO_GENI_CFG_REG10_PRIM_14_RX_SI_EN_BMSK                                                               0x4000
#define HWIO_GENI_CFG_REG10_PRIM_14_RX_SI_EN_SHFT                                                                   14
#define HWIO_GENI_CFG_REG10_PRIM_13_RX_SI_EN_BMSK                                                               0x2000
#define HWIO_GENI_CFG_REG10_PRIM_13_RX_SI_EN_SHFT                                                                   13
#define HWIO_GENI_CFG_REG10_PRIM_12_RX_SI_EN_BMSK                                                               0x1000
#define HWIO_GENI_CFG_REG10_PRIM_12_RX_SI_EN_SHFT                                                                   12
#define HWIO_GENI_CFG_REG10_PRIM_11_RX_SI_EN_BMSK                                                                0x800
#define HWIO_GENI_CFG_REG10_PRIM_11_RX_SI_EN_SHFT                                                                   11
#define HWIO_GENI_CFG_REG10_PRIM_10_RX_SI_EN_BMSK                                                                0x400
#define HWIO_GENI_CFG_REG10_PRIM_10_RX_SI_EN_SHFT                                                                   10
#define HWIO_GENI_CFG_REG10_PRIM_9_RX_SI_EN_BMSK                                                                 0x200
#define HWIO_GENI_CFG_REG10_PRIM_9_RX_SI_EN_SHFT                                                                     9
#define HWIO_GENI_CFG_REG10_PRIM_8_RX_SI_EN_BMSK                                                                 0x100
#define HWIO_GENI_CFG_REG10_PRIM_8_RX_SI_EN_SHFT                                                                     8
#define HWIO_GENI_CFG_REG10_PRIM_7_RX_SI_EN_BMSK                                                                  0x80
#define HWIO_GENI_CFG_REG10_PRIM_7_RX_SI_EN_SHFT                                                                     7
#define HWIO_GENI_CFG_REG10_PRIM_6_RX_SI_EN_BMSK                                                                  0x40
#define HWIO_GENI_CFG_REG10_PRIM_6_RX_SI_EN_SHFT                                                                     6
#define HWIO_GENI_CFG_REG10_PRIM_5_RX_SI_EN_BMSK                                                                  0x20
#define HWIO_GENI_CFG_REG10_PRIM_5_RX_SI_EN_SHFT                                                                     5
#define HWIO_GENI_CFG_REG10_PRIM_4_RX_SI_EN_BMSK                                                                  0x10
#define HWIO_GENI_CFG_REG10_PRIM_4_RX_SI_EN_SHFT                                                                     4
#define HWIO_GENI_CFG_REG10_PRIM_3_RX_SI_EN_BMSK                                                                   0x8
#define HWIO_GENI_CFG_REG10_PRIM_3_RX_SI_EN_SHFT                                                                     3
#define HWIO_GENI_CFG_REG10_PRIM_2_RX_SI_EN_BMSK                                                                   0x4
#define HWIO_GENI_CFG_REG10_PRIM_2_RX_SI_EN_SHFT                                                                     2
#define HWIO_GENI_CFG_REG10_PRIM_1_RX_SI_EN_BMSK                                                                   0x2
#define HWIO_GENI_CFG_REG10_PRIM_1_RX_SI_EN_SHFT                                                                     1
#define HWIO_GENI_CFG_REG10_PRIM_0_RX_SI_EN_BMSK                                                                   0x1
#define HWIO_GENI_CFG_REG10_PRIM_0_RX_SI_EN_SHFT                                                                     0

#define HWIO_GENI_CFG_REG11_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x2c)
#define HWIO_GENI_CFG_REG11_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x2c)
#define HWIO_GENI_CFG_REG11_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x2c)
#define HWIO_GENI_CFG_REG11_RMSK                                                                              0xffffff
#define HWIO_GENI_CFG_REG11_IN                    \
                in_dword(HWIO_GENI_CFG_REG11_ADDR)
#define HWIO_GENI_CFG_REG11_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG11_ADDR, m)
#define HWIO_GENI_CFG_REG11_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG11_ADDR,v)
#define HWIO_GENI_CFG_REG11_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG11_ADDR,m,v,HWIO_GENI_CFG_REG11_IN)
#define HWIO_GENI_CFG_REG11_PRIM_23_RX_PAR_EN_BMSK                                                            0x800000
#define HWIO_GENI_CFG_REG11_PRIM_23_RX_PAR_EN_SHFT                                                                  23
#define HWIO_GENI_CFG_REG11_PRIM_22_RX_PAR_EN_BMSK                                                            0x400000
#define HWIO_GENI_CFG_REG11_PRIM_22_RX_PAR_EN_SHFT                                                                  22
#define HWIO_GENI_CFG_REG11_PRIM_21_RX_PAR_EN_BMSK                                                            0x200000
#define HWIO_GENI_CFG_REG11_PRIM_21_RX_PAR_EN_SHFT                                                                  21
#define HWIO_GENI_CFG_REG11_PRIM_20_RX_PAR_EN_BMSK                                                            0x100000
#define HWIO_GENI_CFG_REG11_PRIM_20_RX_PAR_EN_SHFT                                                                  20
#define HWIO_GENI_CFG_REG11_PRIM_19_RX_PAR_EN_BMSK                                                             0x80000
#define HWIO_GENI_CFG_REG11_PRIM_19_RX_PAR_EN_SHFT                                                                  19
#define HWIO_GENI_CFG_REG11_PRIM_18_RX_PAR_EN_BMSK                                                             0x40000
#define HWIO_GENI_CFG_REG11_PRIM_18_RX_PAR_EN_SHFT                                                                  18
#define HWIO_GENI_CFG_REG11_PRIM_17_RX_PAR_EN_BMSK                                                             0x20000
#define HWIO_GENI_CFG_REG11_PRIM_17_RX_PAR_EN_SHFT                                                                  17
#define HWIO_GENI_CFG_REG11_PRIM_16_RX_PAR_EN_BMSK                                                             0x10000
#define HWIO_GENI_CFG_REG11_PRIM_16_RX_PAR_EN_SHFT                                                                  16
#define HWIO_GENI_CFG_REG11_PRIM_15_RX_PAR_EN_BMSK                                                              0x8000
#define HWIO_GENI_CFG_REG11_PRIM_15_RX_PAR_EN_SHFT                                                                  15
#define HWIO_GENI_CFG_REG11_PRIM_14_RX_PAR_EN_BMSK                                                              0x4000
#define HWIO_GENI_CFG_REG11_PRIM_14_RX_PAR_EN_SHFT                                                                  14
#define HWIO_GENI_CFG_REG11_PRIM_13_RX_PAR_EN_BMSK                                                              0x2000
#define HWIO_GENI_CFG_REG11_PRIM_13_RX_PAR_EN_SHFT                                                                  13
#define HWIO_GENI_CFG_REG11_PRIM_12_RX_PAR_EN_BMSK                                                              0x1000
#define HWIO_GENI_CFG_REG11_PRIM_12_RX_PAR_EN_SHFT                                                                  12
#define HWIO_GENI_CFG_REG11_PRIM_11_RX_PAR_EN_BMSK                                                               0x800
#define HWIO_GENI_CFG_REG11_PRIM_11_RX_PAR_EN_SHFT                                                                  11
#define HWIO_GENI_CFG_REG11_PRIM_10_RX_PAR_EN_BMSK                                                               0x400
#define HWIO_GENI_CFG_REG11_PRIM_10_RX_PAR_EN_SHFT                                                                  10
#define HWIO_GENI_CFG_REG11_PRIM_9_RX_PAR_EN_BMSK                                                                0x200
#define HWIO_GENI_CFG_REG11_PRIM_9_RX_PAR_EN_SHFT                                                                    9
#define HWIO_GENI_CFG_REG11_PRIM_8_RX_PAR_EN_BMSK                                                                0x100
#define HWIO_GENI_CFG_REG11_PRIM_8_RX_PAR_EN_SHFT                                                                    8
#define HWIO_GENI_CFG_REG11_PRIM_7_RX_PAR_EN_BMSK                                                                 0x80
#define HWIO_GENI_CFG_REG11_PRIM_7_RX_PAR_EN_SHFT                                                                    7
#define HWIO_GENI_CFG_REG11_PRIM_6_RX_PAR_EN_BMSK                                                                 0x40
#define HWIO_GENI_CFG_REG11_PRIM_6_RX_PAR_EN_SHFT                                                                    6
#define HWIO_GENI_CFG_REG11_PRIM_5_RX_PAR_EN_BMSK                                                                 0x20
#define HWIO_GENI_CFG_REG11_PRIM_5_RX_PAR_EN_SHFT                                                                    5
#define HWIO_GENI_CFG_REG11_PRIM_4_RX_PAR_EN_BMSK                                                                 0x10
#define HWIO_GENI_CFG_REG11_PRIM_4_RX_PAR_EN_SHFT                                                                    4
#define HWIO_GENI_CFG_REG11_PRIM_3_RX_PAR_EN_BMSK                                                                  0x8
#define HWIO_GENI_CFG_REG11_PRIM_3_RX_PAR_EN_SHFT                                                                    3
#define HWIO_GENI_CFG_REG11_PRIM_2_RX_PAR_EN_BMSK                                                                  0x4
#define HWIO_GENI_CFG_REG11_PRIM_2_RX_PAR_EN_SHFT                                                                    2
#define HWIO_GENI_CFG_REG11_PRIM_1_RX_PAR_EN_BMSK                                                                  0x2
#define HWIO_GENI_CFG_REG11_PRIM_1_RX_PAR_EN_SHFT                                                                    1
#define HWIO_GENI_CFG_REG11_PRIM_0_RX_PAR_EN_BMSK                                                                  0x1
#define HWIO_GENI_CFG_REG11_PRIM_0_RX_PAR_EN_SHFT                                                                    0

#define HWIO_GENI_CFG_REG12_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x30)
#define HWIO_GENI_CFG_REG12_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x30)
#define HWIO_GENI_CFG_REG12_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x30)
#define HWIO_GENI_CFG_REG12_RMSK                                                                              0xffffff
#define HWIO_GENI_CFG_REG12_IN                    \
                in_dword(HWIO_GENI_CFG_REG12_ADDR)
#define HWIO_GENI_CFG_REG12_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG12_ADDR, m)
#define HWIO_GENI_CFG_REG12_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG12_ADDR,v)
#define HWIO_GENI_CFG_REG12_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG12_ADDR,m,v,HWIO_GENI_CFG_REG12_IN)
#define HWIO_GENI_CFG_REG12_PRIM_23_RX_PAR_FIRST_BMSK                                                         0x800000
#define HWIO_GENI_CFG_REG12_PRIM_23_RX_PAR_FIRST_SHFT                                                               23
#define HWIO_GENI_CFG_REG12_PRIM_22_RX_PAR_FIRST_BMSK                                                         0x400000
#define HWIO_GENI_CFG_REG12_PRIM_22_RX_PAR_FIRST_SHFT                                                               22
#define HWIO_GENI_CFG_REG12_PRIM_21_RX_PAR_FIRST_BMSK                                                         0x200000
#define HWIO_GENI_CFG_REG12_PRIM_21_RX_PAR_FIRST_SHFT                                                               21
#define HWIO_GENI_CFG_REG12_PRIM_20_RX_PAR_FIRST_BMSK                                                         0x100000
#define HWIO_GENI_CFG_REG12_PRIM_20_RX_PAR_FIRST_SHFT                                                               20
#define HWIO_GENI_CFG_REG12_PRIM_19_RX_PAR_FIRST_BMSK                                                          0x80000
#define HWIO_GENI_CFG_REG12_PRIM_19_RX_PAR_FIRST_SHFT                                                               19
#define HWIO_GENI_CFG_REG12_PRIM_18_RX_PAR_FIRST_BMSK                                                          0x40000
#define HWIO_GENI_CFG_REG12_PRIM_18_RX_PAR_FIRST_SHFT                                                               18
#define HWIO_GENI_CFG_REG12_PRIM_17_RX_PAR_FIRST_BMSK                                                          0x20000
#define HWIO_GENI_CFG_REG12_PRIM_17_RX_PAR_FIRST_SHFT                                                               17
#define HWIO_GENI_CFG_REG12_PRIM_16_RX_PAR_FIRST_BMSK                                                          0x10000
#define HWIO_GENI_CFG_REG12_PRIM_16_RX_PAR_FIRST_SHFT                                                               16
#define HWIO_GENI_CFG_REG12_PRIM_15_RX_PAR_FIRST_BMSK                                                           0x8000
#define HWIO_GENI_CFG_REG12_PRIM_15_RX_PAR_FIRST_SHFT                                                               15
#define HWIO_GENI_CFG_REG12_PRIM_14_RX_PAR_FIRST_BMSK                                                           0x4000
#define HWIO_GENI_CFG_REG12_PRIM_14_RX_PAR_FIRST_SHFT                                                               14
#define HWIO_GENI_CFG_REG12_PRIM_13_RX_PAR_FIRST_BMSK                                                           0x2000
#define HWIO_GENI_CFG_REG12_PRIM_13_RX_PAR_FIRST_SHFT                                                               13
#define HWIO_GENI_CFG_REG12_PRIM_12_RX_PAR_FIRST_BMSK                                                           0x1000
#define HWIO_GENI_CFG_REG12_PRIM_12_RX_PAR_FIRST_SHFT                                                               12
#define HWIO_GENI_CFG_REG12_PRIM_11_RX_PAR_FIRST_BMSK                                                            0x800
#define HWIO_GENI_CFG_REG12_PRIM_11_RX_PAR_FIRST_SHFT                                                               11
#define HWIO_GENI_CFG_REG12_PRIM_10_RX_PAR_FIRST_BMSK                                                            0x400
#define HWIO_GENI_CFG_REG12_PRIM_10_RX_PAR_FIRST_SHFT                                                               10
#define HWIO_GENI_CFG_REG12_PRIM_9_RX_PAR_FIRST_BMSK                                                             0x200
#define HWIO_GENI_CFG_REG12_PRIM_9_RX_PAR_FIRST_SHFT                                                                 9
#define HWIO_GENI_CFG_REG12_PRIM_8_RX_PAR_FIRST_BMSK                                                             0x100
#define HWIO_GENI_CFG_REG12_PRIM_8_RX_PAR_FIRST_SHFT                                                                 8
#define HWIO_GENI_CFG_REG12_PRIM_7_RX_PAR_FIRST_BMSK                                                              0x80
#define HWIO_GENI_CFG_REG12_PRIM_7_RX_PAR_FIRST_SHFT                                                                 7
#define HWIO_GENI_CFG_REG12_PRIM_6_RX_PAR_FIRST_BMSK                                                              0x40
#define HWIO_GENI_CFG_REG12_PRIM_6_RX_PAR_FIRST_SHFT                                                                 6
#define HWIO_GENI_CFG_REG12_PRIM_5_RX_PAR_FIRST_BMSK                                                              0x20
#define HWIO_GENI_CFG_REG12_PRIM_5_RX_PAR_FIRST_SHFT                                                                 5
#define HWIO_GENI_CFG_REG12_PRIM_4_RX_PAR_FIRST_BMSK                                                              0x10
#define HWIO_GENI_CFG_REG12_PRIM_4_RX_PAR_FIRST_SHFT                                                                 4
#define HWIO_GENI_CFG_REG12_PRIM_3_RX_PAR_FIRST_BMSK                                                               0x8
#define HWIO_GENI_CFG_REG12_PRIM_3_RX_PAR_FIRST_SHFT                                                                 3
#define HWIO_GENI_CFG_REG12_PRIM_2_RX_PAR_FIRST_BMSK                                                               0x4
#define HWIO_GENI_CFG_REG12_PRIM_2_RX_PAR_FIRST_SHFT                                                                 2
#define HWIO_GENI_CFG_REG12_PRIM_1_RX_PAR_FIRST_BMSK                                                               0x2
#define HWIO_GENI_CFG_REG12_PRIM_1_RX_PAR_FIRST_SHFT                                                                 1
#define HWIO_GENI_CFG_REG12_PRIM_0_RX_PAR_FIRST_BMSK                                                               0x1
#define HWIO_GENI_CFG_REG12_PRIM_0_RX_PAR_FIRST_SHFT                                                                 0

#define HWIO_GENI_CFG_REG13_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x34)
#define HWIO_GENI_CFG_REG13_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x34)
#define HWIO_GENI_CFG_REG13_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x34)
#define HWIO_GENI_CFG_REG13_RMSK                                                                              0xffffff
#define HWIO_GENI_CFG_REG13_IN                    \
                in_dword(HWIO_GENI_CFG_REG13_ADDR)
#define HWIO_GENI_CFG_REG13_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG13_ADDR, m)
#define HWIO_GENI_CFG_REG13_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG13_ADDR,v)
#define HWIO_GENI_CFG_REG13_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG13_ADDR,m,v,HWIO_GENI_CFG_REG13_IN)
#define HWIO_GENI_CFG_REG13_PRIM_23_ACC_PAR_EN_BMSK                                                           0x800000
#define HWIO_GENI_CFG_REG13_PRIM_23_ACC_PAR_EN_SHFT                                                                 23
#define HWIO_GENI_CFG_REG13_PRIM_22_ACC_PAR_EN_BMSK                                                           0x400000
#define HWIO_GENI_CFG_REG13_PRIM_22_ACC_PAR_EN_SHFT                                                                 22
#define HWIO_GENI_CFG_REG13_PRIM_21_ACC_PAR_EN_BMSK                                                           0x200000
#define HWIO_GENI_CFG_REG13_PRIM_21_ACC_PAR_EN_SHFT                                                                 21
#define HWIO_GENI_CFG_REG13_PRIM_20_ACC_PAR_EN_BMSK                                                           0x100000
#define HWIO_GENI_CFG_REG13_PRIM_20_ACC_PAR_EN_SHFT                                                                 20
#define HWIO_GENI_CFG_REG13_PRIM_19_ACC_PAR_EN_BMSK                                                            0x80000
#define HWIO_GENI_CFG_REG13_PRIM_19_ACC_PAR_EN_SHFT                                                                 19
#define HWIO_GENI_CFG_REG13_PRIM_18_ACC_PAR_EN_BMSK                                                            0x40000
#define HWIO_GENI_CFG_REG13_PRIM_18_ACC_PAR_EN_SHFT                                                                 18
#define HWIO_GENI_CFG_REG13_PRIM_17_ACC_PAR_EN_BMSK                                                            0x20000
#define HWIO_GENI_CFG_REG13_PRIM_17_ACC_PAR_EN_SHFT                                                                 17
#define HWIO_GENI_CFG_REG13_PRIM_16_ACC_PAR_EN_BMSK                                                            0x10000
#define HWIO_GENI_CFG_REG13_PRIM_16_ACC_PAR_EN_SHFT                                                                 16
#define HWIO_GENI_CFG_REG13_PRIM_15_ACC_PAR_EN_BMSK                                                             0x8000
#define HWIO_GENI_CFG_REG13_PRIM_15_ACC_PAR_EN_SHFT                                                                 15
#define HWIO_GENI_CFG_REG13_PRIM_14_ACC_PAR_EN_BMSK                                                             0x4000
#define HWIO_GENI_CFG_REG13_PRIM_14_ACC_PAR_EN_SHFT                                                                 14
#define HWIO_GENI_CFG_REG13_PRIM_13_ACC_PAR_EN_BMSK                                                             0x2000
#define HWIO_GENI_CFG_REG13_PRIM_13_ACC_PAR_EN_SHFT                                                                 13
#define HWIO_GENI_CFG_REG13_PRIM_12_ACC_PAR_EN_BMSK                                                             0x1000
#define HWIO_GENI_CFG_REG13_PRIM_12_ACC_PAR_EN_SHFT                                                                 12
#define HWIO_GENI_CFG_REG13_PRIM_11_ACC_PAR_EN_BMSK                                                              0x800
#define HWIO_GENI_CFG_REG13_PRIM_11_ACC_PAR_EN_SHFT                                                                 11
#define HWIO_GENI_CFG_REG13_PRIM_10_ACC_PAR_EN_BMSK                                                              0x400
#define HWIO_GENI_CFG_REG13_PRIM_10_ACC_PAR_EN_SHFT                                                                 10
#define HWIO_GENI_CFG_REG13_PRIM_9_ACC_PAR_EN_BMSK                                                               0x200
#define HWIO_GENI_CFG_REG13_PRIM_9_ACC_PAR_EN_SHFT                                                                   9
#define HWIO_GENI_CFG_REG13_PRIM_8_ACC_PAR_EN_BMSK                                                               0x100
#define HWIO_GENI_CFG_REG13_PRIM_8_ACC_PAR_EN_SHFT                                                                   8
#define HWIO_GENI_CFG_REG13_PRIM_7_ACC_PAR_EN_BMSK                                                                0x80
#define HWIO_GENI_CFG_REG13_PRIM_7_ACC_PAR_EN_SHFT                                                                   7
#define HWIO_GENI_CFG_REG13_PRIM_6_ACC_PAR_EN_BMSK                                                                0x40
#define HWIO_GENI_CFG_REG13_PRIM_6_ACC_PAR_EN_SHFT                                                                   6
#define HWIO_GENI_CFG_REG13_PRIM_5_ACC_PAR_EN_BMSK                                                                0x20
#define HWIO_GENI_CFG_REG13_PRIM_5_ACC_PAR_EN_SHFT                                                                   5
#define HWIO_GENI_CFG_REG13_PRIM_4_ACC_PAR_EN_BMSK                                                                0x10
#define HWIO_GENI_CFG_REG13_PRIM_4_ACC_PAR_EN_SHFT                                                                   4
#define HWIO_GENI_CFG_REG13_PRIM_3_ACC_PAR_EN_BMSK                                                                 0x8
#define HWIO_GENI_CFG_REG13_PRIM_3_ACC_PAR_EN_SHFT                                                                   3
#define HWIO_GENI_CFG_REG13_PRIM_2_ACC_PAR_EN_BMSK                                                                 0x4
#define HWIO_GENI_CFG_REG13_PRIM_2_ACC_PAR_EN_SHFT                                                                   2
#define HWIO_GENI_CFG_REG13_PRIM_1_ACC_PAR_EN_BMSK                                                                 0x2
#define HWIO_GENI_CFG_REG13_PRIM_1_ACC_PAR_EN_SHFT                                                                   1
#define HWIO_GENI_CFG_REG13_PRIM_0_ACC_PAR_EN_BMSK                                                                 0x1
#define HWIO_GENI_CFG_REG13_PRIM_0_ACC_PAR_EN_SHFT                                                                   0

#define HWIO_GENI_CFG_REG14_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x38)
#define HWIO_GENI_CFG_REG14_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x38)
#define HWIO_GENI_CFG_REG14_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x38)
#define HWIO_GENI_CFG_REG14_RMSK                                                                              0xffffff
#define HWIO_GENI_CFG_REG14_IN                    \
                in_dword(HWIO_GENI_CFG_REG14_ADDR)
#define HWIO_GENI_CFG_REG14_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG14_ADDR, m)
#define HWIO_GENI_CFG_REG14_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG14_ADDR,v)
#define HWIO_GENI_CFG_REG14_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG14_ADDR,m,v,HWIO_GENI_CFG_REG14_IN)
#define HWIO_GENI_CFG_REG14_PRIM_11_IO2_FUNC_SEL_BMSK                                                         0xc00000
#define HWIO_GENI_CFG_REG14_PRIM_11_IO2_FUNC_SEL_SHFT                                                               22
#define HWIO_GENI_CFG_REG14_PRIM_10_IO2_FUNC_SEL_BMSK                                                         0x300000
#define HWIO_GENI_CFG_REG14_PRIM_10_IO2_FUNC_SEL_SHFT                                                               20
#define HWIO_GENI_CFG_REG14_PRIM_9_IO2_FUNC_SEL_BMSK                                                           0xc0000
#define HWIO_GENI_CFG_REG14_PRIM_9_IO2_FUNC_SEL_SHFT                                                                18
#define HWIO_GENI_CFG_REG14_PRIM_8_IO2_FUNC_SEL_BMSK                                                           0x30000
#define HWIO_GENI_CFG_REG14_PRIM_8_IO2_FUNC_SEL_SHFT                                                                16
#define HWIO_GENI_CFG_REG14_PRIM_7_IO2_FUNC_SEL_BMSK                                                            0xc000
#define HWIO_GENI_CFG_REG14_PRIM_7_IO2_FUNC_SEL_SHFT                                                                14
#define HWIO_GENI_CFG_REG14_PRIM_6_IO2_FUNC_SEL_BMSK                                                            0x3000
#define HWIO_GENI_CFG_REG14_PRIM_6_IO2_FUNC_SEL_SHFT                                                                12
#define HWIO_GENI_CFG_REG14_PRIM_5_IO2_FUNC_SEL_BMSK                                                             0xc00
#define HWIO_GENI_CFG_REG14_PRIM_5_IO2_FUNC_SEL_SHFT                                                                10
#define HWIO_GENI_CFG_REG14_PRIM_4_IO2_FUNC_SEL_BMSK                                                             0x300
#define HWIO_GENI_CFG_REG14_PRIM_4_IO2_FUNC_SEL_SHFT                                                                 8
#define HWIO_GENI_CFG_REG14_PRIM_3_IO2_FUNC_SEL_BMSK                                                              0xc0
#define HWIO_GENI_CFG_REG14_PRIM_3_IO2_FUNC_SEL_SHFT                                                                 6
#define HWIO_GENI_CFG_REG14_PRIM_2_IO2_FUNC_SEL_BMSK                                                              0x30
#define HWIO_GENI_CFG_REG14_PRIM_2_IO2_FUNC_SEL_SHFT                                                                 4
#define HWIO_GENI_CFG_REG14_PRIM_1_IO2_FUNC_SEL_BMSK                                                               0xc
#define HWIO_GENI_CFG_REG14_PRIM_1_IO2_FUNC_SEL_SHFT                                                                 2
#define HWIO_GENI_CFG_REG14_PRIM_0_IO2_FUNC_SEL_BMSK                                                               0x3
#define HWIO_GENI_CFG_REG14_PRIM_0_IO2_FUNC_SEL_SHFT                                                                 0

#define HWIO_GENI_CFG_REG15_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x3c)
#define HWIO_GENI_CFG_REG15_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x3c)
#define HWIO_GENI_CFG_REG15_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x3c)
#define HWIO_GENI_CFG_REG15_RMSK                                                                              0xffffff
#define HWIO_GENI_CFG_REG15_IN                    \
                in_dword(HWIO_GENI_CFG_REG15_ADDR)
#define HWIO_GENI_CFG_REG15_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG15_ADDR, m)
#define HWIO_GENI_CFG_REG15_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG15_ADDR,v)
#define HWIO_GENI_CFG_REG15_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG15_ADDR,m,v,HWIO_GENI_CFG_REG15_IN)
#define HWIO_GENI_CFG_REG15_PRIM_23_IO2_FUNC_SEL_BMSK                                                         0xc00000
#define HWIO_GENI_CFG_REG15_PRIM_23_IO2_FUNC_SEL_SHFT                                                               22
#define HWIO_GENI_CFG_REG15_PRIM_22_IO2_FUNC_SEL_BMSK                                                         0x300000
#define HWIO_GENI_CFG_REG15_PRIM_22_IO2_FUNC_SEL_SHFT                                                               20
#define HWIO_GENI_CFG_REG15_PRIM_21_IO2_FUNC_SEL_BMSK                                                          0xc0000
#define HWIO_GENI_CFG_REG15_PRIM_21_IO2_FUNC_SEL_SHFT                                                               18
#define HWIO_GENI_CFG_REG15_PRIM_20_IO2_FUNC_SEL_BMSK                                                          0x30000
#define HWIO_GENI_CFG_REG15_PRIM_20_IO2_FUNC_SEL_SHFT                                                               16
#define HWIO_GENI_CFG_REG15_PRIM_19_IO2_FUNC_SEL_BMSK                                                           0xc000
#define HWIO_GENI_CFG_REG15_PRIM_19_IO2_FUNC_SEL_SHFT                                                               14
#define HWIO_GENI_CFG_REG15_PRIM_18_IO2_FUNC_SEL_BMSK                                                           0x3000
#define HWIO_GENI_CFG_REG15_PRIM_18_IO2_FUNC_SEL_SHFT                                                               12
#define HWIO_GENI_CFG_REG15_PRIM_17_IO2_FUNC_SEL_BMSK                                                            0xc00
#define HWIO_GENI_CFG_REG15_PRIM_17_IO2_FUNC_SEL_SHFT                                                               10
#define HWIO_GENI_CFG_REG15_PRIM_16_IO2_FUNC_SEL_BMSK                                                            0x300
#define HWIO_GENI_CFG_REG15_PRIM_16_IO2_FUNC_SEL_SHFT                                                                8
#define HWIO_GENI_CFG_REG15_PRIM_15_IO2_FUNC_SEL_BMSK                                                             0xc0
#define HWIO_GENI_CFG_REG15_PRIM_15_IO2_FUNC_SEL_SHFT                                                                6
#define HWIO_GENI_CFG_REG15_PRIM_14_IO2_FUNC_SEL_BMSK                                                             0x30
#define HWIO_GENI_CFG_REG15_PRIM_14_IO2_FUNC_SEL_SHFT                                                                4
#define HWIO_GENI_CFG_REG15_PRIM_13_IO2_FUNC_SEL_BMSK                                                              0xc
#define HWIO_GENI_CFG_REG15_PRIM_13_IO2_FUNC_SEL_SHFT                                                                2
#define HWIO_GENI_CFG_REG15_PRIM_12_IO2_FUNC_SEL_BMSK                                                              0x3
#define HWIO_GENI_CFG_REG15_PRIM_12_IO2_FUNC_SEL_SHFT                                                                0

#define HWIO_GENI_CFG_REG16_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x40)
#define HWIO_GENI_CFG_REG16_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x40)
#define HWIO_GENI_CFG_REG16_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x40)
#define HWIO_GENI_CFG_REG16_RMSK                                                                              0xffffff
#define HWIO_GENI_CFG_REG16_IN                    \
                in_dword(HWIO_GENI_CFG_REG16_ADDR)
#define HWIO_GENI_CFG_REG16_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG16_ADDR, m)
#define HWIO_GENI_CFG_REG16_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG16_ADDR,v)
#define HWIO_GENI_CFG_REG16_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG16_ADDR,m,v,HWIO_GENI_CFG_REG16_IN)
#define HWIO_GENI_CFG_REG16_PRIM_11_IO3_FUNC_SEL_BMSK                                                         0xc00000
#define HWIO_GENI_CFG_REG16_PRIM_11_IO3_FUNC_SEL_SHFT                                                               22
#define HWIO_GENI_CFG_REG16_PRIM_10_IO3_FUNC_SEL_BMSK                                                         0x300000
#define HWIO_GENI_CFG_REG16_PRIM_10_IO3_FUNC_SEL_SHFT                                                               20
#define HWIO_GENI_CFG_REG16_PRIM_9_IO3_FUNC_SEL_BMSK                                                           0xc0000
#define HWIO_GENI_CFG_REG16_PRIM_9_IO3_FUNC_SEL_SHFT                                                                18
#define HWIO_GENI_CFG_REG16_PRIM_8_IO3_FUNC_SEL_BMSK                                                           0x30000
#define HWIO_GENI_CFG_REG16_PRIM_8_IO3_FUNC_SEL_SHFT                                                                16
#define HWIO_GENI_CFG_REG16_PRIM_7_IO3_FUNC_SEL_BMSK                                                            0xc000
#define HWIO_GENI_CFG_REG16_PRIM_7_IO3_FUNC_SEL_SHFT                                                                14
#define HWIO_GENI_CFG_REG16_PRIM_6_IO3_FUNC_SEL_BMSK                                                            0x3000
#define HWIO_GENI_CFG_REG16_PRIM_6_IO3_FUNC_SEL_SHFT                                                                12
#define HWIO_GENI_CFG_REG16_PRIM_5_IO3_FUNC_SEL_BMSK                                                             0xc00
#define HWIO_GENI_CFG_REG16_PRIM_5_IO3_FUNC_SEL_SHFT                                                                10
#define HWIO_GENI_CFG_REG16_PRIM_4_IO3_FUNC_SEL_BMSK                                                             0x300
#define HWIO_GENI_CFG_REG16_PRIM_4_IO3_FUNC_SEL_SHFT                                                                 8
#define HWIO_GENI_CFG_REG16_PRIM_3_IO3_FUNC_SEL_BMSK                                                              0xc0
#define HWIO_GENI_CFG_REG16_PRIM_3_IO3_FUNC_SEL_SHFT                                                                 6
#define HWIO_GENI_CFG_REG16_PRIM_2_IO3_FUNC_SEL_BMSK                                                              0x30
#define HWIO_GENI_CFG_REG16_PRIM_2_IO3_FUNC_SEL_SHFT                                                                 4
#define HWIO_GENI_CFG_REG16_PRIM_1_IO3_FUNC_SEL_BMSK                                                               0xc
#define HWIO_GENI_CFG_REG16_PRIM_1_IO3_FUNC_SEL_SHFT                                                                 2
#define HWIO_GENI_CFG_REG16_PRIM_0_IO3_FUNC_SEL_BMSK                                                               0x3
#define HWIO_GENI_CFG_REG16_PRIM_0_IO3_FUNC_SEL_SHFT                                                                 0

#define HWIO_GENI_CFG_REG17_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x44)
#define HWIO_GENI_CFG_REG17_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x44)
#define HWIO_GENI_CFG_REG17_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x44)
#define HWIO_GENI_CFG_REG17_RMSK                                                                              0xffffff
#define HWIO_GENI_CFG_REG17_IN                    \
                in_dword(HWIO_GENI_CFG_REG17_ADDR)
#define HWIO_GENI_CFG_REG17_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG17_ADDR, m)
#define HWIO_GENI_CFG_REG17_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG17_ADDR,v)
#define HWIO_GENI_CFG_REG17_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG17_ADDR,m,v,HWIO_GENI_CFG_REG17_IN)
#define HWIO_GENI_CFG_REG17_PRIM_23_IO3_FUNC_SEL_BMSK                                                         0xc00000
#define HWIO_GENI_CFG_REG17_PRIM_23_IO3_FUNC_SEL_SHFT                                                               22
#define HWIO_GENI_CFG_REG17_PRIM_22_IO3_FUNC_SEL_BMSK                                                         0x300000
#define HWIO_GENI_CFG_REG17_PRIM_22_IO3_FUNC_SEL_SHFT                                                               20
#define HWIO_GENI_CFG_REG17_PRIM_21_IO3_FUNC_SEL_BMSK                                                          0xc0000
#define HWIO_GENI_CFG_REG17_PRIM_21_IO3_FUNC_SEL_SHFT                                                               18
#define HWIO_GENI_CFG_REG17_PRIM_20_IO3_FUNC_SEL_BMSK                                                          0x30000
#define HWIO_GENI_CFG_REG17_PRIM_20_IO3_FUNC_SEL_SHFT                                                               16
#define HWIO_GENI_CFG_REG17_PRIM_19_IO3_FUNC_SEL_BMSK                                                           0xc000
#define HWIO_GENI_CFG_REG17_PRIM_19_IO3_FUNC_SEL_SHFT                                                               14
#define HWIO_GENI_CFG_REG17_PRIM_18_IO3_FUNC_SEL_BMSK                                                           0x3000
#define HWIO_GENI_CFG_REG17_PRIM_18_IO3_FUNC_SEL_SHFT                                                               12
#define HWIO_GENI_CFG_REG17_PRIM_17_IO3_FUNC_SEL_BMSK                                                            0xc00
#define HWIO_GENI_CFG_REG17_PRIM_17_IO3_FUNC_SEL_SHFT                                                               10
#define HWIO_GENI_CFG_REG17_PRIM_16_IO3_FUNC_SEL_BMSK                                                            0x300
#define HWIO_GENI_CFG_REG17_PRIM_16_IO3_FUNC_SEL_SHFT                                                                8
#define HWIO_GENI_CFG_REG17_PRIM_15_IO3_FUNC_SEL_BMSK                                                             0xc0
#define HWIO_GENI_CFG_REG17_PRIM_15_IO3_FUNC_SEL_SHFT                                                                6
#define HWIO_GENI_CFG_REG17_PRIM_14_IO3_FUNC_SEL_BMSK                                                             0x30
#define HWIO_GENI_CFG_REG17_PRIM_14_IO3_FUNC_SEL_SHFT                                                                4
#define HWIO_GENI_CFG_REG17_PRIM_13_IO3_FUNC_SEL_BMSK                                                              0xc
#define HWIO_GENI_CFG_REG17_PRIM_13_IO3_FUNC_SEL_SHFT                                                                2
#define HWIO_GENI_CFG_REG17_PRIM_12_IO3_FUNC_SEL_BMSK                                                              0x3
#define HWIO_GENI_CFG_REG17_PRIM_12_IO3_FUNC_SEL_SHFT                                                                0

#define HWIO_GENI_CFG_REG18_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x48)
#define HWIO_GENI_CFG_REG18_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x48)
#define HWIO_GENI_CFG_REG18_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x48)
#define HWIO_GENI_CFG_REG18_RMSK                                                                              0xffffff
#define HWIO_GENI_CFG_REG18_IN                    \
                in_dword(HWIO_GENI_CFG_REG18_ADDR)
#define HWIO_GENI_CFG_REG18_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG18_ADDR, m)
#define HWIO_GENI_CFG_REG18_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG18_ADDR,v)
#define HWIO_GENI_CFG_REG18_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG18_ADDR,m,v,HWIO_GENI_CFG_REG18_IN)
#define HWIO_GENI_CFG_REG18_PRIM_23_RX_CHAR_HUNT_EN_BMSK                                                      0x800000
#define HWIO_GENI_CFG_REG18_PRIM_23_RX_CHAR_HUNT_EN_SHFT                                                            23
#define HWIO_GENI_CFG_REG18_PRIM_22_RX_CHAR_HUNT_EN_BMSK                                                      0x400000
#define HWIO_GENI_CFG_REG18_PRIM_22_RX_CHAR_HUNT_EN_SHFT                                                            22
#define HWIO_GENI_CFG_REG18_PRIM_21_RX_CHAR_HUNT_EN_BMSK                                                      0x200000
#define HWIO_GENI_CFG_REG18_PRIM_21_RX_CHAR_HUNT_EN_SHFT                                                            21
#define HWIO_GENI_CFG_REG18_PRIM_20_RX_CHAR_HUNT_EN_BMSK                                                      0x100000
#define HWIO_GENI_CFG_REG18_PRIM_20_RX_CHAR_HUNT_EN_SHFT                                                            20
#define HWIO_GENI_CFG_REG18_PRIM_19_RX_CHAR_HUNT_EN_BMSK                                                       0x80000
#define HWIO_GENI_CFG_REG18_PRIM_19_RX_CHAR_HUNT_EN_SHFT                                                            19
#define HWIO_GENI_CFG_REG18_PRIM_18_RX_CHAR_HUNT_EN_BMSK                                                       0x40000
#define HWIO_GENI_CFG_REG18_PRIM_18_RX_CHAR_HUNT_EN_SHFT                                                            18
#define HWIO_GENI_CFG_REG18_PRIM_17_RX_CHAR_HUNT_EN_BMSK                                                       0x20000
#define HWIO_GENI_CFG_REG18_PRIM_17_RX_CHAR_HUNT_EN_SHFT                                                            17
#define HWIO_GENI_CFG_REG18_PRIM_16_RX_CHAR_HUNT_EN_BMSK                                                       0x10000
#define HWIO_GENI_CFG_REG18_PRIM_16_RX_CHAR_HUNT_EN_SHFT                                                            16
#define HWIO_GENI_CFG_REG18_PRIM_15_RX_CHAR_HUNT_EN_BMSK                                                        0x8000
#define HWIO_GENI_CFG_REG18_PRIM_15_RX_CHAR_HUNT_EN_SHFT                                                            15
#define HWIO_GENI_CFG_REG18_PRIM_14_RX_CHAR_HUNT_EN_BMSK                                                        0x4000
#define HWIO_GENI_CFG_REG18_PRIM_14_RX_CHAR_HUNT_EN_SHFT                                                            14
#define HWIO_GENI_CFG_REG18_PRIM_13_RX_CHAR_HUNT_EN_BMSK                                                        0x2000
#define HWIO_GENI_CFG_REG18_PRIM_13_RX_CHAR_HUNT_EN_SHFT                                                            13
#define HWIO_GENI_CFG_REG18_PRIM_12_RX_CHAR_HUNT_EN_BMSK                                                        0x1000
#define HWIO_GENI_CFG_REG18_PRIM_12_RX_CHAR_HUNT_EN_SHFT                                                            12
#define HWIO_GENI_CFG_REG18_PRIM_11_RX_CHAR_HUNT_EN_BMSK                                                         0x800
#define HWIO_GENI_CFG_REG18_PRIM_11_RX_CHAR_HUNT_EN_SHFT                                                            11
#define HWIO_GENI_CFG_REG18_PRIM_10_RX_CHAR_HUNT_EN_BMSK                                                         0x400
#define HWIO_GENI_CFG_REG18_PRIM_10_RX_CHAR_HUNT_EN_SHFT                                                            10
#define HWIO_GENI_CFG_REG18_PRIM_9_RX_CHAR_HUNT_EN_BMSK                                                          0x200
#define HWIO_GENI_CFG_REG18_PRIM_9_RX_CHAR_HUNT_EN_SHFT                                                              9
#define HWIO_GENI_CFG_REG18_PRIM_8_RX_CHAR_HUNT_EN_BMSK                                                          0x100
#define HWIO_GENI_CFG_REG18_PRIM_8_RX_CHAR_HUNT_EN_SHFT                                                              8
#define HWIO_GENI_CFG_REG18_PRIM_7_RX_CHAR_HUNT_EN_BMSK                                                           0x80
#define HWIO_GENI_CFG_REG18_PRIM_7_RX_CHAR_HUNT_EN_SHFT                                                              7
#define HWIO_GENI_CFG_REG18_PRIM_6_RX_CHAR_HUNT_EN_BMSK                                                           0x40
#define HWIO_GENI_CFG_REG18_PRIM_6_RX_CHAR_HUNT_EN_SHFT                                                              6
#define HWIO_GENI_CFG_REG18_PRIM_5_RX_CHAR_HUNT_EN_BMSK                                                           0x20
#define HWIO_GENI_CFG_REG18_PRIM_5_RX_CHAR_HUNT_EN_SHFT                                                              5
#define HWIO_GENI_CFG_REG18_PRIM_4_RX_CHAR_HUNT_EN_BMSK                                                           0x10
#define HWIO_GENI_CFG_REG18_PRIM_4_RX_CHAR_HUNT_EN_SHFT                                                              4
#define HWIO_GENI_CFG_REG18_PRIM_3_RX_CHAR_HUNT_EN_BMSK                                                            0x8
#define HWIO_GENI_CFG_REG18_PRIM_3_RX_CHAR_HUNT_EN_SHFT                                                              3
#define HWIO_GENI_CFG_REG18_PRIM_2_RX_CHAR_HUNT_EN_BMSK                                                            0x4
#define HWIO_GENI_CFG_REG18_PRIM_2_RX_CHAR_HUNT_EN_SHFT                                                              2
#define HWIO_GENI_CFG_REG18_PRIM_1_RX_CHAR_HUNT_EN_BMSK                                                            0x2
#define HWIO_GENI_CFG_REG18_PRIM_1_RX_CHAR_HUNT_EN_SHFT                                                              1
#define HWIO_GENI_CFG_REG18_PRIM_0_RX_CHAR_HUNT_EN_BMSK                                                            0x1
#define HWIO_GENI_CFG_REG18_PRIM_0_RX_CHAR_HUNT_EN_SHFT                                                              0

#define HWIO_GENI_CFG_REG64_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x100)
#define HWIO_GENI_CFG_REG64_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x100)
#define HWIO_GENI_CFG_REG64_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x100)
#define HWIO_GENI_CFG_REG64_RMSK                                                                               0x3023b
#define HWIO_GENI_CFG_REG64_IN                    \
                in_dword(HWIO_GENI_CFG_REG64_ADDR)
#define HWIO_GENI_CFG_REG64_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG64_ADDR, m)
#define HWIO_GENI_CFG_REG64_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG64_ADDR,v)
#define HWIO_GENI_CFG_REG64_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG64_ADDR,m,v,HWIO_GENI_CFG_REG64_IN)
#define HWIO_GENI_CFG_REG64_M_IO_DATA_IRQ_FW_EN_BMSK                                                           0x20000
#define HWIO_GENI_CFG_REG64_M_IO_DATA_IRQ_FW_EN_SHFT                                                                17
#define HWIO_GENI_CFG_REG64_S_IO_DATA_IRQ_FW_EN_BMSK                                                           0x10000
#define HWIO_GENI_CFG_REG64_S_IO_DATA_IRQ_FW_EN_SHFT                                                                16
#define HWIO_GENI_CFG_REG64_DATA_CNT_MODE_BMSK                                                                   0x200
#define HWIO_GENI_CFG_REG64_DATA_CNT_MODE_SHFT                                                                       9
#define HWIO_GENI_CFG_REG64_GENI_MODE_BMSK                                                                        0x30
#define HWIO_GENI_CFG_REG64_GENI_MODE_SHFT                                                                           4
#define HWIO_GENI_CFG_REG64_SLAVE_MODE_EN_BMSK                                                                     0x8
#define HWIO_GENI_CFG_REG64_SLAVE_MODE_EN_SHFT                                                                       3
#define HWIO_GENI_CFG_REG64_EXT_ARB_EN_BMSK                                                                        0x2
#define HWIO_GENI_CFG_REG64_EXT_ARB_EN_SHFT                                                                          1
#define HWIO_GENI_CFG_REG64_M_PROG_RAM_SEC_WORD_EN_BMSK                                                            0x1
#define HWIO_GENI_CFG_REG64_M_PROG_RAM_SEC_WORD_EN_SHFT                                                              0

#define HWIO_GENI_CFG_REG65_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x104)
#define HWIO_GENI_CFG_REG65_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x104)
#define HWIO_GENI_CFG_REG65_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x104)
#define HWIO_GENI_CFG_REG65_RMSK                                                                               0x3ffff
#define HWIO_GENI_CFG_REG65_IN                    \
                in_dword(HWIO_GENI_CFG_REG65_ADDR)
#define HWIO_GENI_CFG_REG65_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG65_ADDR, m)
#define HWIO_GENI_CFG_REG65_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG65_ADDR,v)
#define HWIO_GENI_CFG_REG65_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG65_ADDR,m,v,HWIO_GENI_CFG_REG65_IN)
#define HWIO_GENI_CFG_REG65_TX_PARAM_TABLE_VEC_1_BMSK                                                          0x3fe00
#define HWIO_GENI_CFG_REG65_TX_PARAM_TABLE_VEC_1_SHFT                                                                9
#define HWIO_GENI_CFG_REG65_TX_PARAM_TABLE_VEC_0_BMSK                                                            0x1ff
#define HWIO_GENI_CFG_REG65_TX_PARAM_TABLE_VEC_0_SHFT                                                                0

#define HWIO_GENI_CFG_REG66_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x108)
#define HWIO_GENI_CFG_REG66_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x108)
#define HWIO_GENI_CFG_REG66_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x108)
#define HWIO_GENI_CFG_REG66_RMSK                                                                               0x3ffff
#define HWIO_GENI_CFG_REG66_IN                    \
                in_dword(HWIO_GENI_CFG_REG66_ADDR)
#define HWIO_GENI_CFG_REG66_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG66_ADDR, m)
#define HWIO_GENI_CFG_REG66_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG66_ADDR,v)
#define HWIO_GENI_CFG_REG66_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG66_ADDR,m,v,HWIO_GENI_CFG_REG66_IN)
#define HWIO_GENI_CFG_REG66_TX_PARAM_TABLE_VEC_3_BMSK                                                          0x3fe00
#define HWIO_GENI_CFG_REG66_TX_PARAM_TABLE_VEC_3_SHFT                                                                9
#define HWIO_GENI_CFG_REG66_TX_PARAM_TABLE_VEC_2_BMSK                                                            0x1ff
#define HWIO_GENI_CFG_REG66_TX_PARAM_TABLE_VEC_2_SHFT                                                                0

#define HWIO_GENI_CFG_REG67_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x10c)
#define HWIO_GENI_CFG_REG67_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x10c)
#define HWIO_GENI_CFG_REG67_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x10c)
#define HWIO_GENI_CFG_REG67_RMSK                                                                             0xfdfffff
#define HWIO_GENI_CFG_REG67_IN                    \
                in_dword(HWIO_GENI_CFG_REG67_ADDR)
#define HWIO_GENI_CFG_REG67_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG67_ADDR, m)
#define HWIO_GENI_CFG_REG67_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG67_ADDR,v)
#define HWIO_GENI_CFG_REG67_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG67_ADDR,m,v,HWIO_GENI_CFG_REG67_IN)
#define HWIO_GENI_CFG_REG67_M_AUTO_OPCODE_CANCEL_BMSK                                                        0x8000000
#define HWIO_GENI_CFG_REG67_M_AUTO_OPCODE_CANCEL_SHFT                                                               27
#define HWIO_GENI_CFG_REG67_M_OPCODE_CMD_CANCEL_BMSK                                                         0x7c00000
#define HWIO_GENI_CFG_REG67_M_OPCODE_CMD_CANCEL_SHFT                                                                22
#define HWIO_GENI_CFG_REG67_DRIVE_DEFAULT_ON_START_EN_BMSK                                                    0x100000
#define HWIO_GENI_CFG_REG67_DRIVE_DEFAULT_ON_START_EN_SHFT                                                          20
#define HWIO_GENI_CFG_REG67_TX_BP_MODE_BMSK                                                                    0x80000
#define HWIO_GENI_CFG_REG67_TX_BP_MODE_SHFT                                                                         19
#define HWIO_GENI_CFG_REG67_TX_SOE_EDGE_SEL_BMSK                                                               0x40000
#define HWIO_GENI_CFG_REG67_TX_SOE_EDGE_SEL_SHFT                                                                    18
#define HWIO_GENI_CFG_REG67_TX_SOUT_EDGE_SEL_BMSK                                                              0x20000
#define HWIO_GENI_CFG_REG67_TX_SOUT_EDGE_SEL_SHFT                                                                   17
#define HWIO_GENI_CFG_REG67_TX_DEFAULT_PRIM_SOE_VALUE_BMSK                                                     0x10000
#define HWIO_GENI_CFG_REG67_TX_DEFAULT_PRIM_SOE_VALUE_SHFT                                                          16
#define HWIO_GENI_CFG_REG67_TX_DEFAULT_PRIM_SOUT_VALUE_BMSK                                                     0x8000
#define HWIO_GENI_CFG_REG67_TX_DEFAULT_PRIM_SOUT_VALUE_SHFT                                                         15
#define HWIO_GENI_CFG_REG67_TX_DEFAULT_SOE_VALUE_BMSK                                                           0x4000
#define HWIO_GENI_CFG_REG67_TX_DEFAULT_SOE_VALUE_SHFT                                                               14
#define HWIO_GENI_CFG_REG67_TX_DEFAULT_SOUT_VALUE_BMSK                                                          0x2000
#define HWIO_GENI_CFG_REG67_TX_DEFAULT_SOUT_VALUE_SHFT                                                              13
#define HWIO_GENI_CFG_REG67_TX_CONST1_EFF_SIZE_BMSK                                                             0x1c00
#define HWIO_GENI_CFG_REG67_TX_CONST1_EFF_SIZE_SHFT                                                                 10
#define HWIO_GENI_CFG_REG67_TX_CONST1_REG_BMSK                                                                   0x3fc
#define HWIO_GENI_CFG_REG67_TX_CONST1_REG_SHFT                                                                       2
#define HWIO_GENI_CFG_REG67_TX_CONST1_EFF_SIZE_MSB_BMSK                                                            0x3
#define HWIO_GENI_CFG_REG67_TX_CONST1_EFF_SIZE_MSB_SHFT                                                              0

#define HWIO_GENI_CFG_REG68_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x110)
#define HWIO_GENI_CFG_REG68_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x110)
#define HWIO_GENI_CFG_REG68_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x110)
#define HWIO_GENI_CFG_REG68_RMSK                                                                            0xe0f0ff3f
#define HWIO_GENI_CFG_REG68_IN                    \
                in_dword(HWIO_GENI_CFG_REG68_ADDR)
#define HWIO_GENI_CFG_REG68_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG68_ADDR, m)
#define HWIO_GENI_CFG_REG68_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG68_ADDR,v)
#define HWIO_GENI_CFG_REG68_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG68_ADDR,m,v,HWIO_GENI_CFG_REG68_IN)
#define HWIO_GENI_CFG_REG68_M_TIME_CNT_FR_DIV_BMSK                                                          0xc0000000
#define HWIO_GENI_CFG_REG68_M_TIME_CNT_FR_DIV_SHFT                                                                  30
#define HWIO_GENI_CFG_REG68_M_TIME_CNT_EN_FR_SEL_BMSK                                                       0x20000000
#define HWIO_GENI_CFG_REG68_M_TIME_CNT_EN_FR_SEL_SHFT                                                               29
#define HWIO_GENI_CFG_REG68_IO2_CLK_DIV_INIT_SEL_BMSK                                                         0x800000
#define HWIO_GENI_CFG_REG68_IO2_CLK_DIV_INIT_SEL_SHFT                                                               23
#define HWIO_GENI_CFG_REG68_TX_IO_NEG_SEL_BMSK                                                                0x400000
#define HWIO_GENI_CFG_REG68_TX_IO_NEG_SEL_SHFT                                                                      22
#define HWIO_GENI_CFG_REG68_M_GP_SYNC_CANCEL_CLEAR_BMSK                                                       0x200000
#define HWIO_GENI_CFG_REG68_M_GP_SYNC_CANCEL_CLEAR_SHFT                                                             21
#define HWIO_GENI_CFG_REG68_M_GP_CNT_DIRECTION_BMSK                                                           0x100000
#define HWIO_GENI_CFG_REG68_M_GP_CNT_DIRECTION_SHFT                                                                 20
#define HWIO_GENI_CFG_REG68_TX_CONST1_PAR_EN_BMSK                                                               0x8000
#define HWIO_GENI_CFG_REG68_TX_CONST1_PAR_EN_SHFT                                                                   15
#define HWIO_GENI_CFG_REG68_TX_LOAD_PAR_EN_BMSK                                                                 0x4000
#define HWIO_GENI_CFG_REG68_TX_LOAD_PAR_EN_SHFT                                                                     14
#define HWIO_GENI_CFG_REG68_TX_PARAM_DUMMY_PAR_EN_BMSK                                                          0x2000
#define HWIO_GENI_CFG_REG68_TX_PARAM_DUMMY_PAR_EN_SHFT                                                              13
#define HWIO_GENI_CFG_REG68_TX_PARAM_PAR_EN_BMSK                                                                0x1000
#define HWIO_GENI_CFG_REG68_TX_PARAM_PAR_EN_SHFT                                                                    12
#define HWIO_GENI_CFG_REG68_TX_FIFO_DUMMY_PAR_EN_BMSK                                                            0x800
#define HWIO_GENI_CFG_REG68_TX_FIFO_DUMMY_PAR_EN_SHFT                                                               11
#define HWIO_GENI_CFG_REG68_TX_FIFO_PAR_EN_BMSK                                                                  0x400
#define HWIO_GENI_CFG_REG68_TX_FIFO_PAR_EN_SHFT                                                                     10
#define HWIO_GENI_CFG_REG68_IO2_CLK_PULSE_INIT_SEL_BMSK                                                          0x200
#define HWIO_GENI_CFG_REG68_IO2_CLK_PULSE_INIT_SEL_SHFT                                                              9
#define HWIO_GENI_CFG_REG68_IO2_CONST_EFF_SIZE_BMSK                                                              0x100
#define HWIO_GENI_CFG_REG68_IO2_CONST_EFF_SIZE_SHFT                                                                  8
#define HWIO_GENI_CFG_REG68_IO2_CONST_REG_BMSK                                                                    0x30
#define HWIO_GENI_CFG_REG68_IO2_CONST_REG_SHFT                                                                       4
#define HWIO_GENI_CFG_REG68_IO2_DEFAULT_PRIM_SOE_VALUE_BMSK                                                        0x8
#define HWIO_GENI_CFG_REG68_IO2_DEFAULT_PRIM_SOE_VALUE_SHFT                                                          3
#define HWIO_GENI_CFG_REG68_IO2_DEFAULT_PRIM_SOUT_VALUE_BMSK                                                       0x4
#define HWIO_GENI_CFG_REG68_IO2_DEFAULT_PRIM_SOUT_VALUE_SHFT                                                         2
#define HWIO_GENI_CFG_REG68_IO2_DEFAULT_SOE_VALUE_BMSK                                                             0x2
#define HWIO_GENI_CFG_REG68_IO2_DEFAULT_SOE_VALUE_SHFT                                                               1
#define HWIO_GENI_CFG_REG68_IO2_DEFAULT_SOUT_VALUE_BMSK                                                            0x1
#define HWIO_GENI_CFG_REG68_IO2_DEFAULT_SOUT_VALUE_SHFT                                                              0

#define HWIO_GENI_CFG_REG69_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x114)
#define HWIO_GENI_CFG_REG69_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x114)
#define HWIO_GENI_CFG_REG69_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x114)
#define HWIO_GENI_CFG_REG69_RMSK                                                                            0x4ec03ff1
#define HWIO_GENI_CFG_REG69_IN                    \
                in_dword(HWIO_GENI_CFG_REG69_ADDR)
#define HWIO_GENI_CFG_REG69_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG69_ADDR, m)
#define HWIO_GENI_CFG_REG69_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG69_ADDR,v)
#define HWIO_GENI_CFG_REG69_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG69_ADDR,m,v,HWIO_GENI_CFG_REG69_IN)
#define HWIO_GENI_CFG_REG69_GENI_RX_MODE_BMSK                                                               0x40000000
#define HWIO_GENI_CFG_REG69_GENI_RX_MODE_SHFT                                                                       30
#define HWIO_GENI_CFG_REG69_RX_IO_SIN_SEL_BMSK                                                               0xe000000
#define HWIO_GENI_CFG_REG69_RX_IO_SIN_SEL_SHFT                                                                      25
#define HWIO_GENI_CFG_REG69_RX_SIN_SEL_BMSK                                                                   0xc00000
#define HWIO_GENI_CFG_REG69_RX_SIN_SEL_SHFT                                                                         22
#define HWIO_GENI_CFG_REG69_S_GP_SYNC_CANCEL_CLEAR_BMSK                                                         0x2000
#define HWIO_GENI_CFG_REG69_S_GP_SYNC_CANCEL_CLEAR_SHFT                                                             13
#define HWIO_GENI_CFG_REG69_SW_FLUSH_SYNC_EN_BMSK                                                               0x1000
#define HWIO_GENI_CFG_REG69_SW_FLUSH_SYNC_EN_SHFT                                                                   12
#define HWIO_GENI_CFG_REG69_AUTO_SYNC_FIFO_CLEAR_BMSK                                                            0x800
#define HWIO_GENI_CFG_REG69_AUTO_SYNC_FIFO_CLEAR_SHFT                                                               11
#define HWIO_GENI_CFG_REG69_LAST_IS_DONE_BMSK                                                                    0x400
#define HWIO_GENI_CFG_REG69_LAST_IS_DONE_SHFT                                                                       10
#define HWIO_GENI_CFG_REG69_S_AUTO_OPCODE_CANCEL_BMSK                                                            0x200
#define HWIO_GENI_CFG_REG69_S_AUTO_OPCODE_CANCEL_SHFT                                                                9
#define HWIO_GENI_CFG_REG69_S_OPCODE_CMD_CANCEL_BMSK                                                             0x1f0
#define HWIO_GENI_CFG_REG69_S_OPCODE_CMD_CANCEL_SHFT                                                                 4
#define HWIO_GENI_CFG_REG69_S_DATA_CNT_MODE_BMSK                                                                   0x1
#define HWIO_GENI_CFG_REG69_S_DATA_CNT_MODE_SHFT                                                                     0

#define HWIO_GENI_CFG_REG70_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x118)
#define HWIO_GENI_CFG_REG70_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x118)
#define HWIO_GENI_CFG_REG70_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x118)
#define HWIO_GENI_CFG_REG70_RMSK                                                                                 0x401
#define HWIO_GENI_CFG_REG70_IN                    \
                in_dword(HWIO_GENI_CFG_REG70_ADDR)
#define HWIO_GENI_CFG_REG70_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG70_ADDR, m)
#define HWIO_GENI_CFG_REG70_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG70_ADDR,v)
#define HWIO_GENI_CFG_REG70_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG70_ADDR,m,v,HWIO_GENI_CFG_REG70_IN)
#define HWIO_GENI_CFG_REG70_S_GP_CNT_DIRECTION_BMSK                                                              0x400
#define HWIO_GENI_CFG_REG70_S_GP_CNT_DIRECTION_SHFT                                                                 10
#define HWIO_GENI_CFG_REG70_S_PROG_RAM_SEC_WORD_EN_BMSK                                                            0x1
#define HWIO_GENI_CFG_REG70_S_PROG_RAM_SEC_WORD_EN_SHFT                                                              0

#define HWIO_GENI_CFG_REG71_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x11c)
#define HWIO_GENI_CFG_REG71_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x11c)
#define HWIO_GENI_CFG_REG71_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x11c)
#define HWIO_GENI_CFG_REG71_RMSK                                                                            0x3ffffc00
#define HWIO_GENI_CFG_REG71_IN                    \
                in_dword(HWIO_GENI_CFG_REG71_ADDR)
#define HWIO_GENI_CFG_REG71_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG71_ADDR, m)
#define HWIO_GENI_CFG_REG71_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG71_ADDR,v)
#define HWIO_GENI_CFG_REG71_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG71_ADDR,m,v,HWIO_GENI_CFG_REG71_IN)
#define HWIO_GENI_CFG_REG71_COND_COMP_IN_0_SEL_RST_VAL_EXT_BMSK                                             0x3ff00000
#define HWIO_GENI_CFG_REG71_COND_COMP_IN_0_SEL_RST_VAL_EXT_SHFT                                                     20
#define HWIO_GENI_CFG_REG71_COND_COMP_IN_0_SEL_RST_VAL_BMSK                                                    0xffc00
#define HWIO_GENI_CFG_REG71_COND_COMP_IN_0_SEL_RST_VAL_SHFT                                                         10

#define HWIO_GENI_CFG_REG72_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x120)
#define HWIO_GENI_CFG_REG72_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x120)
#define HWIO_GENI_CFG_REG72_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x120)
#define HWIO_GENI_CFG_REG72_RMSK                                                                            0x3fffffff
#define HWIO_GENI_CFG_REG72_IN                    \
                in_dword(HWIO_GENI_CFG_REG72_ADDR)
#define HWIO_GENI_CFG_REG72_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG72_ADDR, m)
#define HWIO_GENI_CFG_REG72_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG72_ADDR,v)
#define HWIO_GENI_CFG_REG72_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG72_ADDR,m,v,HWIO_GENI_CFG_REG72_IN)
#define HWIO_GENI_CFG_REG72_S_COND_COMP_IN_0_SEL_RST_VAL_EXT_BMSK                                           0x3ff00000
#define HWIO_GENI_CFG_REG72_S_COND_COMP_IN_0_SEL_RST_VAL_EXT_SHFT                                                   20
#define HWIO_GENI_CFG_REG72_S_COND_COMP_IN_0_SEL_RST_VAL_BMSK                                                  0xffc00
#define HWIO_GENI_CFG_REG72_S_COND_COMP_IN_0_SEL_RST_VAL_SHFT                                                       10
#define HWIO_GENI_CFG_REG72_S_COND_COMP_IN_VEC_BMSK                                                              0x3ff
#define HWIO_GENI_CFG_REG72_S_COND_COMP_IN_VEC_SHFT                                                                  0

#define HWIO_GENI_CFG_REG73_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x124)
#define HWIO_GENI_CFG_REG73_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x124)
#define HWIO_GENI_CFG_REG73_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x124)
#define HWIO_GENI_CFG_REG73_RMSK                                                                                   0x1
#define HWIO_GENI_CFG_REG73_IN                    \
                in_dword(HWIO_GENI_CFG_REG73_ADDR)
#define HWIO_GENI_CFG_REG73_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG73_ADDR, m)
#define HWIO_GENI_CFG_REG73_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG73_ADDR,v)
#define HWIO_GENI_CFG_REG73_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG73_ADDR,m,v,HWIO_GENI_CFG_REG73_IN)
#define HWIO_GENI_CFG_REG73_SPI_CPHASE_BMSK                                                                        0x1
#define HWIO_GENI_CFG_REG73_SPI_CPHASE_SHFT                                                                          0

#define HWIO_SPI_CPHA_ADDR                                                                                  (GENI4_IMAGE_REGS_REG_BASE            + 0x124)
#define HWIO_SPI_CPHA_PHYS                                                                                  (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x124)
#define HWIO_SPI_CPHA_OFFS                                                                                  (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x124)
#define HWIO_SPI_CPHA_RMSK                                                                                         0xf
#define HWIO_SPI_CPHA_IN                    \
                in_dword(HWIO_SPI_CPHA_ADDR)
#define HWIO_SPI_CPHA_INM(m)            \
                in_dword_masked(HWIO_SPI_CPHA_ADDR, m)
#define HWIO_SPI_CPHA_OUT(v)            \
                out_dword(HWIO_SPI_CPHA_ADDR,v)
#define HWIO_SPI_CPHA_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SPI_CPHA_ADDR,m,v,HWIO_SPI_CPHA_IN)
#define HWIO_SPI_CPHA_CPHA_BMSK                                                                                    0xf
#define HWIO_SPI_CPHA_CPHA_SHFT                                                                                      0

#define HWIO_GENI_CFG_REG74_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x128)
#define HWIO_GENI_CFG_REG74_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x128)
#define HWIO_GENI_CFG_REG74_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x128)
#define HWIO_GENI_CFG_REG74_RMSK                                                                                   0x1
#define HWIO_GENI_CFG_REG74_IN                    \
                in_dword(HWIO_GENI_CFG_REG74_ADDR)
#define HWIO_GENI_CFG_REG74_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG74_ADDR, m)
#define HWIO_GENI_CFG_REG74_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG74_ADDR,v)
#define HWIO_GENI_CFG_REG74_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG74_ADDR,m,v,HWIO_GENI_CFG_REG74_IN)
#define HWIO_GENI_CFG_REG74_NOT_USED_BMSK                                                                          0x1
#define HWIO_GENI_CFG_REG74_NOT_USED_SHFT                                                                            0

#define HWIO_QSPI_LANE_CONTROL_ADDR                                                                         (GENI4_IMAGE_REGS_REG_BASE            + 0x128)
#define HWIO_QSPI_LANE_CONTROL_PHYS                                                                         (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x128)
#define HWIO_QSPI_LANE_CONTROL_OFFS                                                                         (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x128)
#define HWIO_QSPI_LANE_CONTROL_RMSK                                                                          0xfffff1f
#define HWIO_QSPI_LANE_CONTROL_IN                    \
                in_dword(HWIO_QSPI_LANE_CONTROL_ADDR)
#define HWIO_QSPI_LANE_CONTROL_INM(m)            \
                in_dword_masked(HWIO_QSPI_LANE_CONTROL_ADDR, m)
#define HWIO_QSPI_LANE_CONTROL_OUT(v)            \
                out_dword(HWIO_QSPI_LANE_CONTROL_ADDR,v)
#define HWIO_QSPI_LANE_CONTROL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_QSPI_LANE_CONTROL_ADDR,m,v,HWIO_QSPI_LANE_CONTROL_IN)
#define HWIO_QSPI_LANE_CONTROL_DDR_MODE_NIBBLE_SWAP_BMSK                                                     0x8000000
#define HWIO_QSPI_LANE_CONTROL_DDR_MODE_NIBBLE_SWAP_SHFT                                                            27
#define HWIO_QSPI_LANE_CONTROL_DDR_MODE_EDGE_SEL_EN_BMSK                                                     0x4000000
#define HWIO_QSPI_LANE_CONTROL_DDR_MODE_EDGE_SEL_EN_SHFT                                                            26
#define HWIO_QSPI_LANE_CONTROL_DDR_MODE_EDGE_SEL_BMSK                                                        0x3000000
#define HWIO_QSPI_LANE_CONTROL_DDR_MODE_EDGE_SEL_SHFT                                                               24
#define HWIO_QSPI_LANE_CONTROL_QSPI_SAMPLING_CLK_EN_BMSK                                                      0x800000
#define HWIO_QSPI_LANE_CONTROL_QSPI_SAMPLING_CLK_EN_SHFT                                                            23
#define HWIO_QSPI_LANE_CONTROL_MAIN_PHASE0_CLK_SEL_BMSK                                                       0x400000
#define HWIO_QSPI_LANE_CONTROL_MAIN_PHASE0_CLK_SEL_SHFT                                                             22
#define HWIO_QSPI_LANE_CONTROL_QSPI_REF_CLK_EN_BMSK                                                           0x200000
#define HWIO_QSPI_LANE_CONTROL_QSPI_REF_CLK_EN_SHFT                                                                 21
#define HWIO_QSPI_LANE_CONTROL_FULL_CYCLE_MODE_BMSK                                                           0x100000
#define HWIO_QSPI_LANE_CONTROL_FULL_CYCLE_MODE_SHFT                                                                 20
#define HWIO_QSPI_LANE_CONTROL_CLK_CONFIG_LANE3_BMSK                                                           0xe0000
#define HWIO_QSPI_LANE_CONTROL_CLK_CONFIG_LANE3_SHFT                                                                17
#define HWIO_QSPI_LANE_CONTROL_CLK_CONFIG_LANE2_BMSK                                                           0x1c000
#define HWIO_QSPI_LANE_CONTROL_CLK_CONFIG_LANE2_SHFT                                                                14
#define HWIO_QSPI_LANE_CONTROL_CLK_CONFIG_LANE1_BMSK                                                            0x3800
#define HWIO_QSPI_LANE_CONTROL_CLK_CONFIG_LANE1_SHFT                                                                11
#define HWIO_QSPI_LANE_CONTROL_CLK_CONFIG_LANE0_BMSK                                                             0x700
#define HWIO_QSPI_LANE_CONTROL_CLK_CONFIG_LANE0_SHFT                                                                 8
#define HWIO_QSPI_LANE_CONTROL_RX_MODE_OE_DISABLE_BMSK                                                            0x10
#define HWIO_QSPI_LANE_CONTROL_RX_MODE_OE_DISABLE_SHFT                                                               4
#define HWIO_QSPI_LANE_CONTROL_LANE_CONTROL_FW_EN_BMSK                                                             0x8
#define HWIO_QSPI_LANE_CONTROL_LANE_CONTROL_FW_EN_SHFT                                                               3
#define HWIO_QSPI_LANE_CONTROL_DDR_MODE_BMSK                                                                       0x4
#define HWIO_QSPI_LANE_CONTROL_DDR_MODE_SHFT                                                                         2
#define HWIO_QSPI_LANE_CONTROL_NUMBER_OF_DATA_LINES_BMSK                                                           0x3
#define HWIO_QSPI_LANE_CONTROL_NUMBER_OF_DATA_LINES_SHFT                                                             0

#define HWIO_GENI_CFG_REG75_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x12c)
#define HWIO_GENI_CFG_REG75_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x12c)
#define HWIO_GENI_CFG_REG75_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x12c)
#define HWIO_GENI_CFG_REG75_RMSK                                                                                   0x3
#define HWIO_GENI_CFG_REG75_IN                    \
                in_dword(HWIO_GENI_CFG_REG75_ADDR)
#define HWIO_GENI_CFG_REG75_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG75_ADDR, m)
#define HWIO_GENI_CFG_REG75_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG75_ADDR,v)
#define HWIO_GENI_CFG_REG75_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG75_ADDR,m,v,HWIO_GENI_CFG_REG75_IN)
#define HWIO_GENI_CFG_REG75_LOOPBACK_MODE_BMSK                                                                     0x3
#define HWIO_GENI_CFG_REG75_LOOPBACK_MODE_SHFT                                                                       0

#define HWIO_UART_LOOPBACK_CFG_ADDR                                                                         (GENI4_IMAGE_REGS_REG_BASE            + 0x12c)
#define HWIO_UART_LOOPBACK_CFG_PHYS                                                                         (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x12c)
#define HWIO_UART_LOOPBACK_CFG_OFFS                                                                         (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x12c)
#define HWIO_UART_LOOPBACK_CFG_RMSK                                                                                0x3
#define HWIO_UART_LOOPBACK_CFG_IN                    \
                in_dword(HWIO_UART_LOOPBACK_CFG_ADDR)
#define HWIO_UART_LOOPBACK_CFG_INM(m)            \
                in_dword_masked(HWIO_UART_LOOPBACK_CFG_ADDR, m)
#define HWIO_UART_LOOPBACK_CFG_OUT(v)            \
                out_dword(HWIO_UART_LOOPBACK_CFG_ADDR,v)
#define HWIO_UART_LOOPBACK_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_UART_LOOPBACK_CFG_ADDR,m,v,HWIO_UART_LOOPBACK_CFG_IN)
#define HWIO_UART_LOOPBACK_CFG_LOOPBACK_MODE_BMSK                                                                  0x3
#define HWIO_UART_LOOPBACK_CFG_LOOPBACK_MODE_SHFT                                                                    0

#define HWIO_SPI_LOOPBACK_CFG_ADDR                                                                          (GENI4_IMAGE_REGS_REG_BASE            + 0x12c)
#define HWIO_SPI_LOOPBACK_CFG_PHYS                                                                          (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x12c)
#define HWIO_SPI_LOOPBACK_CFG_OFFS                                                                          (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x12c)
#define HWIO_SPI_LOOPBACK_CFG_RMSK                                                                                 0x3
#define HWIO_SPI_LOOPBACK_CFG_IN                    \
                in_dword(HWIO_SPI_LOOPBACK_CFG_ADDR)
#define HWIO_SPI_LOOPBACK_CFG_INM(m)            \
                in_dword_masked(HWIO_SPI_LOOPBACK_CFG_ADDR, m)
#define HWIO_SPI_LOOPBACK_CFG_OUT(v)            \
                out_dword(HWIO_SPI_LOOPBACK_CFG_ADDR,v)
#define HWIO_SPI_LOOPBACK_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SPI_LOOPBACK_CFG_ADDR,m,v,HWIO_SPI_LOOPBACK_CFG_IN)
#define HWIO_SPI_LOOPBACK_CFG_LOOPBACK_MODE_BMSK                                                                   0x3
#define HWIO_SPI_LOOPBACK_CFG_LOOPBACK_MODE_SHFT                                                                     0

#define HWIO_GENI_CFG_REG76_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x130)
#define HWIO_GENI_CFG_REG76_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x130)
#define HWIO_GENI_CFG_REG76_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x130)
#define HWIO_GENI_CFG_REG76_RMSK                                                                                   0x7
#define HWIO_GENI_CFG_REG76_IN                    \
                in_dword(HWIO_GENI_CFG_REG76_ADDR)
#define HWIO_GENI_CFG_REG76_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG76_ADDR, m)
#define HWIO_GENI_CFG_REG76_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG76_ADDR,v)
#define HWIO_GENI_CFG_REG76_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG76_ADDR,m,v,HWIO_GENI_CFG_REG76_IN)
#define HWIO_GENI_CFG_REG76_IO2_ENGINE_INV_EN_BMSK                                                                 0x4
#define HWIO_GENI_CFG_REG76_IO2_ENGINE_INV_EN_SHFT                                                                   2
#define HWIO_GENI_CFG_REG76_RX_ENGINE_INV_EN_BMSK                                                                  0x2
#define HWIO_GENI_CFG_REG76_RX_ENGINE_INV_EN_SHFT                                                                    1
#define HWIO_GENI_CFG_REG76_TX_ENGINE_INV_EN_BMSK                                                                  0x1
#define HWIO_GENI_CFG_REG76_TX_ENGINE_INV_EN_SHFT                                                                    0

#define HWIO_SPI_CPOL_ADDR                                                                                  (GENI4_IMAGE_REGS_REG_BASE            + 0x130)
#define HWIO_SPI_CPOL_PHYS                                                                                  (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x130)
#define HWIO_SPI_CPOL_OFFS                                                                                  (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x130)
#define HWIO_SPI_CPOL_RMSK                                                                                         0x4
#define HWIO_SPI_CPOL_IN                    \
                in_dword(HWIO_SPI_CPOL_ADDR)
#define HWIO_SPI_CPOL_INM(m)            \
                in_dword_masked(HWIO_SPI_CPOL_ADDR, m)
#define HWIO_SPI_CPOL_OUT(v)            \
                out_dword(HWIO_SPI_CPOL_ADDR,v)
#define HWIO_SPI_CPOL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SPI_CPOL_ADDR,m,v,HWIO_SPI_CPOL_IN)
#define HWIO_SPI_CPOL_CPOL_BMSK                                                                                    0x4
#define HWIO_SPI_CPOL_CPOL_SHFT                                                                                      2

#define HWIO_GENI_CFG_REG77_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x134)
#define HWIO_GENI_CFG_REG77_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x134)
#define HWIO_GENI_CFG_REG77_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x134)
#define HWIO_GENI_CFG_REG77_RMSK                                                                                  0x1f
#define HWIO_GENI_CFG_REG77_IN                    \
                in_dword(HWIO_GENI_CFG_REG77_ADDR)
#define HWIO_GENI_CFG_REG77_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG77_ADDR, m)
#define HWIO_GENI_CFG_REG77_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG77_ADDR,v)
#define HWIO_GENI_CFG_REG77_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG77_ADDR,m,v,HWIO_GENI_CFG_REG77_IN)
#define HWIO_GENI_CFG_REG77_SDA_NOISE_REJECT_BMSK                                                                 0x18
#define HWIO_GENI_CFG_REG77_SDA_NOISE_REJECT_SHFT                                                                    3
#define HWIO_GENI_CFG_REG77_SCL_NOISE_REJECT_BMSK                                                                  0x6
#define HWIO_GENI_CFG_REG77_SCL_NOISE_REJECT_SHFT                                                                    1
#define HWIO_GENI_CFG_REG77_LOW_PERIOD_NOISE_REJECT_EN_BMSK                                                        0x1
#define HWIO_GENI_CFG_REG77_LOW_PERIOD_NOISE_REJECT_EN_SHFT                                                          0

#define HWIO_I2C_NOISE_CANCELATION_CTL_ADDR                                                                 (GENI4_IMAGE_REGS_REG_BASE            + 0x134)
#define HWIO_I2C_NOISE_CANCELATION_CTL_PHYS                                                                 (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x134)
#define HWIO_I2C_NOISE_CANCELATION_CTL_OFFS                                                                 (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x134)
#define HWIO_I2C_NOISE_CANCELATION_CTL_RMSK                                                                       0x1f
#define HWIO_I2C_NOISE_CANCELATION_CTL_IN                    \
                in_dword(HWIO_I2C_NOISE_CANCELATION_CTL_ADDR)
#define HWIO_I2C_NOISE_CANCELATION_CTL_INM(m)            \
                in_dword_masked(HWIO_I2C_NOISE_CANCELATION_CTL_ADDR, m)
#define HWIO_I2C_NOISE_CANCELATION_CTL_OUT(v)            \
                out_dword(HWIO_I2C_NOISE_CANCELATION_CTL_ADDR,v)
#define HWIO_I2C_NOISE_CANCELATION_CTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_I2C_NOISE_CANCELATION_CTL_ADDR,m,v,HWIO_I2C_NOISE_CANCELATION_CTL_IN)
#define HWIO_I2C_NOISE_CANCELATION_CTL_SDA_NOISE_REJECT_BMSK                                                      0x18
#define HWIO_I2C_NOISE_CANCELATION_CTL_SDA_NOISE_REJECT_SHFT                                                         3
#define HWIO_I2C_NOISE_CANCELATION_CTL_SCL_NOISE_REJECT_BMSK                                                       0x6
#define HWIO_I2C_NOISE_CANCELATION_CTL_SCL_NOISE_REJECT_SHFT                                                         1
#define HWIO_I2C_NOISE_CANCELATION_CTL_LOW_PERIOD_NOISE_REJECT_EN_BMSK                                             0x1
#define HWIO_I2C_NOISE_CANCELATION_CTL_LOW_PERIOD_NOISE_REJECT_EN_SHFT                                               0

#define HWIO_GENI_CFG_REG78_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x138)
#define HWIO_GENI_CFG_REG78_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x138)
#define HWIO_GENI_CFG_REG78_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x138)
#define HWIO_GENI_CFG_REG78_RMSK                                                                                   0x3
#define HWIO_GENI_CFG_REG78_IN                    \
                in_dword(HWIO_GENI_CFG_REG78_ADDR)
#define HWIO_GENI_CFG_REG78_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG78_ADDR, m)
#define HWIO_GENI_CFG_REG78_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG78_ADDR,v)
#define HWIO_GENI_CFG_REG78_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG78_ADDR,m,v,HWIO_GENI_CFG_REG78_IN)
#define HWIO_GENI_CFG_REG78_BUSY_INDICATION_SELECT_BMSK                                                            0x2
#define HWIO_GENI_CFG_REG78_BUSY_INDICATION_SELECT_SHFT                                                              1
#define HWIO_GENI_CFG_REG78_SDA_DELAYED_DETECTION_BMSK                                                             0x1
#define HWIO_GENI_CFG_REG78_SDA_DELAYED_DETECTION_SHFT                                                               0

#define HWIO_I2C_MONITOR_CTL_ADDR                                                                           (GENI4_IMAGE_REGS_REG_BASE            + 0x138)
#define HWIO_I2C_MONITOR_CTL_PHYS                                                                           (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x138)
#define HWIO_I2C_MONITOR_CTL_OFFS                                                                           (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x138)
#define HWIO_I2C_MONITOR_CTL_RMSK                                                                                  0x1
#define HWIO_I2C_MONITOR_CTL_IN                    \
                in_dword(HWIO_I2C_MONITOR_CTL_ADDR)
#define HWIO_I2C_MONITOR_CTL_INM(m)            \
                in_dword_masked(HWIO_I2C_MONITOR_CTL_ADDR, m)
#define HWIO_I2C_MONITOR_CTL_OUT(v)            \
                out_dword(HWIO_I2C_MONITOR_CTL_ADDR,v)
#define HWIO_I2C_MONITOR_CTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_I2C_MONITOR_CTL_ADDR,m,v,HWIO_I2C_MONITOR_CTL_IN)
#define HWIO_I2C_MONITOR_CTL_SDA_DELAYED_DETECTION_BMSK                                                            0x1
#define HWIO_I2C_MONITOR_CTL_SDA_DELAYED_DETECTION_SHFT                                                              0

#define HWIO_GENI_CFG_REG79_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x13c)
#define HWIO_GENI_CFG_REG79_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x13c)
#define HWIO_GENI_CFG_REG79_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x13c)
#define HWIO_GENI_CFG_REG79_RMSK                                                                                   0x1
#define HWIO_GENI_CFG_REG79_IN                    \
                in_dword(HWIO_GENI_CFG_REG79_ADDR)
#define HWIO_GENI_CFG_REG79_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG79_ADDR, m)
#define HWIO_GENI_CFG_REG79_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG79_ADDR,v)
#define HWIO_GENI_CFG_REG79_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG79_ADDR,m,v,HWIO_GENI_CFG_REG79_IN)
#define HWIO_GENI_CFG_REG79_IO3_S_FE_FORCE_BMSK                                                                    0x1
#define HWIO_GENI_CFG_REG79_IO3_S_FE_FORCE_SHFT                                                                      0

#define HWIO_GENI_CFG_REG80_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x140)
#define HWIO_GENI_CFG_REG80_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x140)
#define HWIO_GENI_CFG_REG80_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x140)
#define HWIO_GENI_CFG_REG80_RMSK                                                                               0x1ffff
#define HWIO_GENI_CFG_REG80_IN                    \
                in_dword(HWIO_GENI_CFG_REG80_ADDR)
#define HWIO_GENI_CFG_REG80_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG80_ADDR, m)
#define HWIO_GENI_CFG_REG80_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG80_ADDR,v)
#define HWIO_GENI_CFG_REG80_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG80_ADDR,m,v,HWIO_GENI_CFG_REG80_IN)
#define HWIO_GENI_CFG_REG80_IO_MACRO_IO3_DATA_IN_LANE_1_SEL_BMSK                                               0x10000
#define HWIO_GENI_CFG_REG80_IO_MACRO_IO3_DATA_IN_LANE_1_SEL_SHFT                                                    16
#define HWIO_GENI_CFG_REG80_IO_MACRO_IO3_DATA_IN_SEL_BMSK                                                       0xc000
#define HWIO_GENI_CFG_REG80_IO_MACRO_IO3_DATA_IN_SEL_SHFT                                                           14
#define HWIO_GENI_CFG_REG80_IO_MACRO_IO0_PULLH_OE_BMSK                                                          0x2000
#define HWIO_GENI_CFG_REG80_IO_MACRO_IO0_PULLH_OE_SHFT                                                              13
#define HWIO_GENI_CFG_REG80_IO_MACRO_OTHER_IO_OE_BMSK                                                           0x1000
#define HWIO_GENI_CFG_REG80_IO_MACRO_OTHER_IO_OE_SHFT                                                               12
#define HWIO_GENI_CFG_REG80_IO_MACRO_IO2_DATA_IN_SEL_BMSK                                                        0xc00
#define HWIO_GENI_CFG_REG80_IO_MACRO_IO2_DATA_IN_SEL_SHFT                                                           10
#define HWIO_GENI_CFG_REG80_IO_MACRO_RX_DATA_IN_SEL_BMSK                                                         0x300
#define HWIO_GENI_CFG_REG80_IO_MACRO_RX_DATA_IN_SEL_SHFT                                                             8
#define HWIO_GENI_CFG_REG80_IO_MACRO_IO3_SEL_BMSK                                                                 0xc0
#define HWIO_GENI_CFG_REG80_IO_MACRO_IO3_SEL_SHFT                                                                    6
#define HWIO_GENI_CFG_REG80_IO_MACRO_IO2_SEL_BMSK                                                                 0x30
#define HWIO_GENI_CFG_REG80_IO_MACRO_IO2_SEL_SHFT                                                                    4
#define HWIO_GENI_CFG_REG80_IO_MACRO_IO1_SEL_BMSK                                                                  0xc
#define HWIO_GENI_CFG_REG80_IO_MACRO_IO1_SEL_SHFT                                                                    2
#define HWIO_GENI_CFG_REG80_IO_MACRO_IO0_SEL_BMSK                                                                  0x3
#define HWIO_GENI_CFG_REG80_IO_MACRO_IO0_SEL_SHFT                                                                    0

#define HWIO_UART_IO_MACRO_CTRL_ADDR                                                                        (GENI4_IMAGE_REGS_REG_BASE            + 0x140)
#define HWIO_UART_IO_MACRO_CTRL_PHYS                                                                        (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x140)
#define HWIO_UART_IO_MACRO_CTRL_OFFS                                                                        (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x140)
#define HWIO_UART_IO_MACRO_CTRL_RMSK                                                                           0x1ffff
#define HWIO_UART_IO_MACRO_CTRL_IN                    \
                in_dword(HWIO_UART_IO_MACRO_CTRL_ADDR)
#define HWIO_UART_IO_MACRO_CTRL_INM(m)            \
                in_dword_masked(HWIO_UART_IO_MACRO_CTRL_ADDR, m)
#define HWIO_UART_IO_MACRO_CTRL_OUT(v)            \
                out_dword(HWIO_UART_IO_MACRO_CTRL_ADDR,v)
#define HWIO_UART_IO_MACRO_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_UART_IO_MACRO_CTRL_ADDR,m,v,HWIO_UART_IO_MACRO_CTRL_IN)
#define HWIO_UART_IO_MACRO_CTRL_IO_MACRO_IO3_DATA_IN_LANE_1_SEL_BMSK                                           0x10000
#define HWIO_UART_IO_MACRO_CTRL_IO_MACRO_IO3_DATA_IN_LANE_1_SEL_SHFT                                                16
#define HWIO_UART_IO_MACRO_CTRL_IO_MACRO_IO3_DATA_IN_SEL_BMSK                                                   0xc000
#define HWIO_UART_IO_MACRO_CTRL_IO_MACRO_IO3_DATA_IN_SEL_SHFT                                                       14
#define HWIO_UART_IO_MACRO_CTRL_IO_MACRO_IO0_PULLH_OE_BMSK                                                      0x2000
#define HWIO_UART_IO_MACRO_CTRL_IO_MACRO_IO0_PULLH_OE_SHFT                                                          13
#define HWIO_UART_IO_MACRO_CTRL_IO_MACRO_OTHER_IO_OE_BMSK                                                       0x1000
#define HWIO_UART_IO_MACRO_CTRL_IO_MACRO_OTHER_IO_OE_SHFT                                                           12
#define HWIO_UART_IO_MACRO_CTRL_IO_MACRO_IO2_DATA_IN_SEL_BMSK                                                    0xc00
#define HWIO_UART_IO_MACRO_CTRL_IO_MACRO_IO2_DATA_IN_SEL_SHFT                                                       10
#define HWIO_UART_IO_MACRO_CTRL_IO_MACRO_RX_DATA_IN_SEL_BMSK                                                     0x300
#define HWIO_UART_IO_MACRO_CTRL_IO_MACRO_RX_DATA_IN_SEL_SHFT                                                         8
#define HWIO_UART_IO_MACRO_CTRL_IO_MACRO_IO3_SEL_BMSK                                                             0xc0
#define HWIO_UART_IO_MACRO_CTRL_IO_MACRO_IO3_SEL_SHFT                                                                6
#define HWIO_UART_IO_MACRO_CTRL_IO_MACRO_IO2_SEL_BMSK                                                             0x30
#define HWIO_UART_IO_MACRO_CTRL_IO_MACRO_IO2_SEL_SHFT                                                                4
#define HWIO_UART_IO_MACRO_CTRL_IO_MACRO_IO1_SEL_BMSK                                                              0xc
#define HWIO_UART_IO_MACRO_CTRL_IO_MACRO_IO1_SEL_SHFT                                                                2
#define HWIO_UART_IO_MACRO_CTRL_IO_MACRO_IO0_SEL_BMSK                                                              0x3
#define HWIO_UART_IO_MACRO_CTRL_IO_MACRO_IO0_SEL_SHFT                                                                0

#define HWIO_GENI_CFG_REG81_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x144)
#define HWIO_GENI_CFG_REG81_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x144)
#define HWIO_GENI_CFG_REG81_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x144)
#define HWIO_GENI_CFG_REG81_RMSK                                                                                   0xf
#define HWIO_GENI_CFG_REG81_IN                    \
                in_dword(HWIO_GENI_CFG_REG81_ADDR)
#define HWIO_GENI_CFG_REG81_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG81_ADDR, m)
#define HWIO_GENI_CFG_REG81_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG81_ADDR,v)
#define HWIO_GENI_CFG_REG81_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG81_ADDR,m,v,HWIO_GENI_CFG_REG81_IN)
#define HWIO_GENI_CFG_REG81_GENI_IO3_SOUT2_PULL_UP_EN_BMSK                                                         0x8
#define HWIO_GENI_CFG_REG81_GENI_IO3_SOUT2_PULL_UP_EN_SHFT                                                           3
#define HWIO_GENI_CFG_REG81_GENI_IO3_SOUT0_PULL_UP_EN_BMSK                                                         0x4
#define HWIO_GENI_CFG_REG81_GENI_IO3_SOUT0_PULL_UP_EN_SHFT                                                           2
#define HWIO_GENI_CFG_REG81_GENI_SOUT2_PULL_UP_EN_BMSK                                                             0x2
#define HWIO_GENI_CFG_REG81_GENI_SOUT2_PULL_UP_EN_SHFT                                                               1
#define HWIO_GENI_CFG_REG81_GENI_SOUT0_PULL_UP_EN_BMSK                                                             0x1
#define HWIO_GENI_CFG_REG81_GENI_SOUT0_PULL_UP_EN_SHFT                                                               0

#define HWIO_GENI_CFG_REG82_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x148)
#define HWIO_GENI_CFG_REG82_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x148)
#define HWIO_GENI_CFG_REG82_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x148)
#define HWIO_GENI_CFG_REG82_RMSK                                                                                   0xf
#define HWIO_GENI_CFG_REG82_IN                    \
                in_dword(HWIO_GENI_CFG_REG82_ADDR)
#define HWIO_GENI_CFG_REG82_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG82_ADDR, m)
#define HWIO_GENI_CFG_REG82_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG82_ADDR,v)
#define HWIO_GENI_CFG_REG82_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG82_ADDR,m,v,HWIO_GENI_CFG_REG82_IN)
#define HWIO_GENI_CFG_REG82_IO3_DEFAULT_PRIM_SOE_VALUE_BMSK                                                        0x8
#define HWIO_GENI_CFG_REG82_IO3_DEFAULT_PRIM_SOE_VALUE_SHFT                                                          3
#define HWIO_GENI_CFG_REG82_IO3_DEFAULT_PRIM_SOUT_VALUE_BMSK                                                       0x4
#define HWIO_GENI_CFG_REG82_IO3_DEFAULT_PRIM_SOUT_VALUE_SHFT                                                         2
#define HWIO_GENI_CFG_REG82_IO3_DEFAULT_SOE_VALUE_BMSK                                                             0x2
#define HWIO_GENI_CFG_REG82_IO3_DEFAULT_SOE_VALUE_SHFT                                                               1
#define HWIO_GENI_CFG_REG82_IO3_DEFAULT_SOUT_VALUE_BMSK                                                            0x1
#define HWIO_GENI_CFG_REG82_IO3_DEFAULT_SOUT_VALUE_SHFT                                                              0

#define HWIO_UART_IO3_VAL_ADDR                                                                              (GENI4_IMAGE_REGS_REG_BASE            + 0x148)
#define HWIO_UART_IO3_VAL_PHYS                                                                              (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x148)
#define HWIO_UART_IO3_VAL_OFFS                                                                              (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x148)
#define HWIO_UART_IO3_VAL_RMSK                                                                                     0xf
#define HWIO_UART_IO3_VAL_IN                    \
                in_dword(HWIO_UART_IO3_VAL_ADDR)
#define HWIO_UART_IO3_VAL_INM(m)            \
                in_dword_masked(HWIO_UART_IO3_VAL_ADDR, m)
#define HWIO_UART_IO3_VAL_OUT(v)            \
                out_dword(HWIO_UART_IO3_VAL_ADDR,v)
#define HWIO_UART_IO3_VAL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_UART_IO3_VAL_ADDR,m,v,HWIO_UART_IO3_VAL_IN)
#define HWIO_UART_IO3_VAL_IO3_DEFAULT_PRIM_SOE_VALUE_BMSK                                                          0x8
#define HWIO_UART_IO3_VAL_IO3_DEFAULT_PRIM_SOE_VALUE_SHFT                                                            3
#define HWIO_UART_IO3_VAL_IO3_DEFAULT_PRIM_SOUT_VALUE_BMSK                                                         0x4
#define HWIO_UART_IO3_VAL_IO3_DEFAULT_PRIM_SOUT_VALUE_SHFT                                                           2
#define HWIO_UART_IO3_VAL_IO3_DEFAULT_SOE_VALUE_BMSK                                                               0x2
#define HWIO_UART_IO3_VAL_IO3_DEFAULT_SOE_VALUE_SHFT                                                                 1
#define HWIO_UART_IO3_VAL_IO3_DEFAULT_SOUT_VALUE_BMSK                                                              0x1
#define HWIO_UART_IO3_VAL_IO3_DEFAULT_SOUT_VALUE_SHFT                                                                0

#define HWIO_GENI_CFG_REG83_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x14c)
#define HWIO_GENI_CFG_REG83_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x14c)
#define HWIO_GENI_CFG_REG83_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x14c)
#define HWIO_GENI_CFG_REG83_RMSK                                                                                   0xf
#define HWIO_GENI_CFG_REG83_IN                    \
                in_dword(HWIO_GENI_CFG_REG83_ADDR)
#define HWIO_GENI_CFG_REG83_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG83_ADDR, m)
#define HWIO_GENI_CFG_REG83_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG83_ADDR,v)
#define HWIO_GENI_CFG_REG83_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG83_ADDR,m,v,HWIO_GENI_CFG_REG83_IN)
#define HWIO_GENI_CFG_REG83_IO3_DEMUX_OUTPUT_INV_BMSK                                                              0xf
#define HWIO_GENI_CFG_REG83_IO3_DEMUX_OUTPUT_INV_SHFT                                                                0

#define HWIO_SPI_DEMUX_OUTPUT_INV_ADDR                                                                      (GENI4_IMAGE_REGS_REG_BASE            + 0x14c)
#define HWIO_SPI_DEMUX_OUTPUT_INV_PHYS                                                                      (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x14c)
#define HWIO_SPI_DEMUX_OUTPUT_INV_OFFS                                                                      (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x14c)
#define HWIO_SPI_DEMUX_OUTPUT_INV_RMSK                                                                             0xf
#define HWIO_SPI_DEMUX_OUTPUT_INV_IN                    \
                in_dword(HWIO_SPI_DEMUX_OUTPUT_INV_ADDR)
#define HWIO_SPI_DEMUX_OUTPUT_INV_INM(m)            \
                in_dword_masked(HWIO_SPI_DEMUX_OUTPUT_INV_ADDR, m)
#define HWIO_SPI_DEMUX_OUTPUT_INV_OUT(v)            \
                out_dword(HWIO_SPI_DEMUX_OUTPUT_INV_ADDR,v)
#define HWIO_SPI_DEMUX_OUTPUT_INV_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SPI_DEMUX_OUTPUT_INV_ADDR,m,v,HWIO_SPI_DEMUX_OUTPUT_INV_IN)
#define HWIO_SPI_DEMUX_OUTPUT_INV_CS_DEMUX_OUTPUT_INV_BMSK                                                         0xf
#define HWIO_SPI_DEMUX_OUTPUT_INV_CS_DEMUX_OUTPUT_INV_SHFT                                                           0

#define HWIO_GENI_CFG_REG84_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x150)
#define HWIO_GENI_CFG_REG84_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x150)
#define HWIO_GENI_CFG_REG84_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x150)
#define HWIO_GENI_CFG_REG84_RMSK                                                                                  0x1f
#define HWIO_GENI_CFG_REG84_IN                    \
                in_dword(HWIO_GENI_CFG_REG84_ADDR)
#define HWIO_GENI_CFG_REG84_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG84_ADDR, m)
#define HWIO_GENI_CFG_REG84_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG84_ADDR,v)
#define HWIO_GENI_CFG_REG84_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG84_ADDR,m,v,HWIO_GENI_CFG_REG84_IN)
#define HWIO_GENI_CFG_REG84_IO3_DEMUX_FW_EN_BMSK                                                                  0x10
#define HWIO_GENI_CFG_REG84_IO3_DEMUX_FW_EN_SHFT                                                                     4
#define HWIO_GENI_CFG_REG84_IO3_DEMUX_SEL_BMSK                                                                     0xf
#define HWIO_GENI_CFG_REG84_IO3_DEMUX_SEL_SHFT                                                                       0

#define HWIO_SPI_DEMUX_SEL_ADDR                                                                             (GENI4_IMAGE_REGS_REG_BASE            + 0x150)
#define HWIO_SPI_DEMUX_SEL_PHYS                                                                             (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x150)
#define HWIO_SPI_DEMUX_SEL_OFFS                                                                             (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x150)
#define HWIO_SPI_DEMUX_SEL_RMSK                                                                                   0x1f
#define HWIO_SPI_DEMUX_SEL_IN                    \
                in_dword(HWIO_SPI_DEMUX_SEL_ADDR)
#define HWIO_SPI_DEMUX_SEL_INM(m)            \
                in_dword_masked(HWIO_SPI_DEMUX_SEL_ADDR, m)
#define HWIO_SPI_DEMUX_SEL_OUT(v)            \
                out_dword(HWIO_SPI_DEMUX_SEL_ADDR,v)
#define HWIO_SPI_DEMUX_SEL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SPI_DEMUX_SEL_ADDR,m,v,HWIO_SPI_DEMUX_SEL_IN)
#define HWIO_SPI_DEMUX_SEL_CS_DEMUX_FW_EN_BMSK                                                                    0x10
#define HWIO_SPI_DEMUX_SEL_CS_DEMUX_FW_EN_SHFT                                                                       4
#define HWIO_SPI_DEMUX_SEL_CS_DEMUX_SEL_BMSK                                                                       0xf
#define HWIO_SPI_DEMUX_SEL_CS_DEMUX_SEL_SHFT                                                                         0

#define HWIO_GENI_CFG_REG85_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x154)
#define HWIO_GENI_CFG_REG85_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x154)
#define HWIO_GENI_CFG_REG85_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x154)
#define HWIO_GENI_CFG_REG85_RMSK                                                                                   0x3
#define HWIO_GENI_CFG_REG85_IN                    \
                in_dword(HWIO_GENI_CFG_REG85_ADDR)
#define HWIO_GENI_CFG_REG85_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG85_ADDR, m)
#define HWIO_GENI_CFG_REG85_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG85_ADDR,v)
#define HWIO_GENI_CFG_REG85_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG85_ADDR,m,v,HWIO_GENI_CFG_REG85_IN)
#define HWIO_GENI_CFG_REG85_GENI_BYTE_GRANULARITY_BMSK                                                             0x3
#define HWIO_GENI_CFG_REG85_GENI_BYTE_GRANULARITY_SHFT                                                               0

#define HWIO_GENI_BYTE_GRANULARITY_ADDR                                                                     (GENI4_IMAGE_REGS_REG_BASE            + 0x154)
#define HWIO_GENI_BYTE_GRANULARITY_PHYS                                                                     (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x154)
#define HWIO_GENI_BYTE_GRANULARITY_OFFS                                                                     (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x154)
#define HWIO_GENI_BYTE_GRANULARITY_RMSK                                                                            0x3
#define HWIO_GENI_BYTE_GRANULARITY_IN                    \
                in_dword(HWIO_GENI_BYTE_GRANULARITY_ADDR)
#define HWIO_GENI_BYTE_GRANULARITY_INM(m)            \
                in_dword_masked(HWIO_GENI_BYTE_GRANULARITY_ADDR, m)
#define HWIO_GENI_BYTE_GRANULARITY_OUT(v)            \
                out_dword(HWIO_GENI_BYTE_GRANULARITY_ADDR,v)
#define HWIO_GENI_BYTE_GRANULARITY_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_BYTE_GRANULARITY_ADDR,m,v,HWIO_GENI_BYTE_GRANULARITY_IN)
#define HWIO_GENI_BYTE_GRANULARITY_GENI_BYTE_GRANULARITY_BMSK                                                      0x3
#define HWIO_GENI_BYTE_GRANULARITY_GENI_BYTE_GRANULARITY_SHFT                                                        0

#define HWIO_GENI_CFG_REG86_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x158)
#define HWIO_GENI_CFG_REG86_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x158)
#define HWIO_GENI_CFG_REG86_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x158)
#define HWIO_GENI_CFG_REG86_RMSK                                                                                   0x1
#define HWIO_GENI_CFG_REG86_IN                    \
                in_dword(HWIO_GENI_CFG_REG86_ADDR)
#define HWIO_GENI_CFG_REG86_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG86_ADDR, m)
#define HWIO_GENI_CFG_REG86_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG86_ADDR,v)
#define HWIO_GENI_CFG_REG86_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG86_ADDR,m,v,HWIO_GENI_CFG_REG86_IN)
#define HWIO_GENI_CFG_REG86_GENI_DMA_MODE_EN_BMSK                                                                  0x1
#define HWIO_GENI_CFG_REG86_GENI_DMA_MODE_EN_SHFT                                                                    0

#define HWIO_GENI_DMA_MODE_EN_ADDR                                                                          (GENI4_IMAGE_REGS_REG_BASE            + 0x158)
#define HWIO_GENI_DMA_MODE_EN_PHYS                                                                          (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x158)
#define HWIO_GENI_DMA_MODE_EN_OFFS                                                                          (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x158)
#define HWIO_GENI_DMA_MODE_EN_RMSK                                                                                 0x1
#define HWIO_GENI_DMA_MODE_EN_IN                    \
                in_dword(HWIO_GENI_DMA_MODE_EN_ADDR)
#define HWIO_GENI_DMA_MODE_EN_INM(m)            \
                in_dword_masked(HWIO_GENI_DMA_MODE_EN_ADDR, m)
#define HWIO_GENI_DMA_MODE_EN_OUT(v)            \
                out_dword(HWIO_GENI_DMA_MODE_EN_ADDR,v)
#define HWIO_GENI_DMA_MODE_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_DMA_MODE_EN_ADDR,m,v,HWIO_GENI_DMA_MODE_EN_IN)
#define HWIO_GENI_DMA_MODE_EN_GENI_DMA_MODE_EN_BMSK                                                                0x1
#define HWIO_GENI_DMA_MODE_EN_GENI_DMA_MODE_EN_SHFT                                                                  0

#define HWIO_GENI_CFG_REG87_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x15c)
#define HWIO_GENI_CFG_REG87_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x15c)
#define HWIO_GENI_CFG_REG87_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x15c)
#define HWIO_GENI_CFG_REG87_RMSK                                                                                  0x7f
#define HWIO_GENI_CFG_REG87_IN                    \
                in_dword(HWIO_GENI_CFG_REG87_ADDR)
#define HWIO_GENI_CFG_REG87_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG87_ADDR, m)
#define HWIO_GENI_CFG_REG87_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG87_ADDR,v)
#define HWIO_GENI_CFG_REG87_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG87_ADDR,m,v,HWIO_GENI_CFG_REG87_IN)
#define HWIO_GENI_CFG_REG87_I3C_CLK_TOGGLE_FIX_EN_BMSK                                                            0x40
#define HWIO_GENI_CFG_REG87_I3C_CLK_TOGGLE_FIX_EN_SHFT                                                               6
#define HWIO_GENI_CFG_REG87_M_SW_COMP5_BMSK                                                                       0x20
#define HWIO_GENI_CFG_REG87_M_SW_COMP5_SHFT                                                                          5
#define HWIO_GENI_CFG_REG87_M_SW_COMP4_BMSK                                                                       0x10
#define HWIO_GENI_CFG_REG87_M_SW_COMP4_SHFT                                                                          4
#define HWIO_GENI_CFG_REG87_M_SW_COMP3_BMSK                                                                        0x8
#define HWIO_GENI_CFG_REG87_M_SW_COMP3_SHFT                                                                          3
#define HWIO_GENI_CFG_REG87_M_SW_COMP2_BMSK                                                                        0x4
#define HWIO_GENI_CFG_REG87_M_SW_COMP2_SHFT                                                                          2
#define HWIO_GENI_CFG_REG87_M_SW_COMP1_BMSK                                                                        0x2
#define HWIO_GENI_CFG_REG87_M_SW_COMP1_SHFT                                                                          1
#define HWIO_GENI_CFG_REG87_M_SW_COMP0_BMSK                                                                        0x1
#define HWIO_GENI_CFG_REG87_M_SW_COMP0_SHFT                                                                          0

#define HWIO_UART_TX_TRANS_CFG_ADDR                                                                         (GENI4_IMAGE_REGS_REG_BASE            + 0x15c)
#define HWIO_UART_TX_TRANS_CFG_PHYS                                                                         (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x15c)
#define HWIO_UART_TX_TRANS_CFG_OFFS                                                                         (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x15c)
#define HWIO_UART_TX_TRANS_CFG_RMSK                                                                                0x7
#define HWIO_UART_TX_TRANS_CFG_IN                    \
                in_dword(HWIO_UART_TX_TRANS_CFG_ADDR)
#define HWIO_UART_TX_TRANS_CFG_INM(m)            \
                in_dword_masked(HWIO_UART_TX_TRANS_CFG_ADDR, m)
#define HWIO_UART_TX_TRANS_CFG_OUT(v)            \
                out_dword(HWIO_UART_TX_TRANS_CFG_ADDR,v)
#define HWIO_UART_TX_TRANS_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_UART_TX_TRANS_CFG_ADDR,m,v,HWIO_UART_TX_TRANS_CFG_IN)
#define HWIO_UART_TX_TRANS_CFG_LM_UART_EN_BMSK                                                                     0x4
#define HWIO_UART_TX_TRANS_CFG_LM_UART_EN_SHFT                                                                       2
#define HWIO_UART_TX_TRANS_CFG_UART_CTS_MASK_BMSK                                                                  0x2
#define HWIO_UART_TX_TRANS_CFG_UART_CTS_MASK_SHFT                                                                    1
#define HWIO_UART_TX_TRANS_CFG_UART_PARITY_EN_BMSK                                                                 0x1
#define HWIO_UART_TX_TRANS_CFG_UART_PARITY_EN_SHFT                                                                   0

#define HWIO_SPI_TRANS_CFG_ADDR                                                                             (GENI4_IMAGE_REGS_REG_BASE            + 0x15c)
#define HWIO_SPI_TRANS_CFG_PHYS                                                                             (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x15c)
#define HWIO_SPI_TRANS_CFG_OFFS                                                                             (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x15c)
#define HWIO_SPI_TRANS_CFG_RMSK                                                                                    0xe
#define HWIO_SPI_TRANS_CFG_IN                    \
                in_dword(HWIO_SPI_TRANS_CFG_ADDR)
#define HWIO_SPI_TRANS_CFG_INM(m)            \
                in_dword_masked(HWIO_SPI_TRANS_CFG_ADDR, m)
#define HWIO_SPI_TRANS_CFG_OUT(v)            \
                out_dword(HWIO_SPI_TRANS_CFG_ADDR,v)
#define HWIO_SPI_TRANS_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SPI_TRANS_CFG_ADDR,m,v,HWIO_SPI_TRANS_CFG_IN)
#define HWIO_SPI_TRANS_CFG_SPI_NOT_USED_CFG2_BMSK                                                                  0x8
#define HWIO_SPI_TRANS_CFG_SPI_NOT_USED_CFG2_SHFT                                                                    3
#define HWIO_SPI_TRANS_CFG_SPI_NOT_USED_CFG1_BMSK                                                                  0x4
#define HWIO_SPI_TRANS_CFG_SPI_NOT_USED_CFG1_SHFT                                                                    2
#define HWIO_SPI_TRANS_CFG_SPI_CS_TOGGLE_BMSK                                                                      0x2
#define HWIO_SPI_TRANS_CFG_SPI_CS_TOGGLE_SHFT                                                                        1

#define HWIO_I3C_TRANS_CFG_ADDR                                                                             (GENI4_IMAGE_REGS_REG_BASE            + 0x15c)
#define HWIO_I3C_TRANS_CFG_PHYS                                                                             (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x15c)
#define HWIO_I3C_TRANS_CFG_OFFS                                                                             (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x15c)
#define HWIO_I3C_TRANS_CFG_RMSK                                                                                    0x6
#define HWIO_I3C_TRANS_CFG_IN                    \
                in_dword(HWIO_I3C_TRANS_CFG_ADDR)
#define HWIO_I3C_TRANS_CFG_INM(m)            \
                in_dword_masked(HWIO_I3C_TRANS_CFG_ADDR, m)
#define HWIO_I3C_TRANS_CFG_OUT(v)            \
                out_dword(HWIO_I3C_TRANS_CFG_ADDR,v)
#define HWIO_I3C_TRANS_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_I3C_TRANS_CFG_ADDR,m,v,HWIO_I3C_TRANS_CFG_IN)
#define HWIO_I3C_TRANS_CFG_I3C_USE_7E_BMSK                                                                         0x4
#define HWIO_I3C_TRANS_CFG_I3C_USE_7E_SHFT                                                                           2
#define HWIO_I3C_TRANS_CFG_I3C_IBI_NACK_CTRL_BMSK                                                                  0x2
#define HWIO_I3C_TRANS_CFG_I3C_IBI_NACK_CTRL_SHFT                                                                    1

#define HWIO_GENI_CFG_REG88_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x160)
#define HWIO_GENI_CFG_REG88_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x160)
#define HWIO_GENI_CFG_REG88_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x160)
#define HWIO_GENI_CFG_REG88_RMSK                                                                               0xfffff
#define HWIO_GENI_CFG_REG88_IN                    \
                in_dword(HWIO_GENI_CFG_REG88_ADDR)
#define HWIO_GENI_CFG_REG88_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG88_ADDR, m)
#define HWIO_GENI_CFG_REG88_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG88_ADDR,v)
#define HWIO_GENI_CFG_REG88_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG88_ADDR,m,v,HWIO_GENI_CFG_REG88_IN)
#define HWIO_GENI_CFG_REG88_VEC_1_START_INDEX_BMSK                                                             0xf8000
#define HWIO_GENI_CFG_REG88_VEC_1_START_INDEX_SHFT                                                                  15
#define HWIO_GENI_CFG_REG88_VEC_1_DIRECTION_BMSK                                                                0x4000
#define HWIO_GENI_CFG_REG88_VEC_1_DIRECTION_SHFT                                                                    14
#define HWIO_GENI_CFG_REG88_VEC_1_LENGTH_BMSK                                                                   0x3800
#define HWIO_GENI_CFG_REG88_VEC_1_LENGTH_SHFT                                                                       11
#define HWIO_GENI_CFG_REG88_VEC_1_STOP_BMSK                                                                      0x400
#define HWIO_GENI_CFG_REG88_VEC_1_STOP_SHFT                                                                         10
#define HWIO_GENI_CFG_REG88_VEC_0_START_INDEX_BMSK                                                               0x3e0
#define HWIO_GENI_CFG_REG88_VEC_0_START_INDEX_SHFT                                                                   5
#define HWIO_GENI_CFG_REG88_VEC_0_DIRECTION_BMSK                                                                  0x10
#define HWIO_GENI_CFG_REG88_VEC_0_DIRECTION_SHFT                                                                     4
#define HWIO_GENI_CFG_REG88_VEC_0_LENGTH_BMSK                                                                      0xe
#define HWIO_GENI_CFG_REG88_VEC_0_LENGTH_SHFT                                                                        1
#define HWIO_GENI_CFG_REG88_VEC_0_STOP_BMSK                                                                        0x1
#define HWIO_GENI_CFG_REG88_VEC_0_STOP_SHFT                                                                          0

#define HWIO_GENI_TX_PACKING_CFG0_ADDR                                                                      (GENI4_IMAGE_REGS_REG_BASE            + 0x160)
#define HWIO_GENI_TX_PACKING_CFG0_PHYS                                                                      (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x160)
#define HWIO_GENI_TX_PACKING_CFG0_OFFS                                                                      (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x160)
#define HWIO_GENI_TX_PACKING_CFG0_RMSK                                                                         0xfffff
#define HWIO_GENI_TX_PACKING_CFG0_IN                    \
                in_dword(HWIO_GENI_TX_PACKING_CFG0_ADDR)
#define HWIO_GENI_TX_PACKING_CFG0_INM(m)            \
                in_dword_masked(HWIO_GENI_TX_PACKING_CFG0_ADDR, m)
#define HWIO_GENI_TX_PACKING_CFG0_OUT(v)            \
                out_dword(HWIO_GENI_TX_PACKING_CFG0_ADDR,v)
#define HWIO_GENI_TX_PACKING_CFG0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_TX_PACKING_CFG0_ADDR,m,v,HWIO_GENI_TX_PACKING_CFG0_IN)
#define HWIO_GENI_TX_PACKING_CFG0_VEC_1_START_INDEX_BMSK                                                       0xf8000
#define HWIO_GENI_TX_PACKING_CFG0_VEC_1_START_INDEX_SHFT                                                            15
#define HWIO_GENI_TX_PACKING_CFG0_VEC_1_DIRECTION_BMSK                                                          0x4000
#define HWIO_GENI_TX_PACKING_CFG0_VEC_1_DIRECTION_SHFT                                                              14
#define HWIO_GENI_TX_PACKING_CFG0_VEC_1_LENGTH_BMSK                                                             0x3800
#define HWIO_GENI_TX_PACKING_CFG0_VEC_1_LENGTH_SHFT                                                                 11
#define HWIO_GENI_TX_PACKING_CFG0_VEC_1_STOP_BMSK                                                                0x400
#define HWIO_GENI_TX_PACKING_CFG0_VEC_1_STOP_SHFT                                                                   10
#define HWIO_GENI_TX_PACKING_CFG0_VEC_0_START_INDEX_BMSK                                                         0x3e0
#define HWIO_GENI_TX_PACKING_CFG0_VEC_0_START_INDEX_SHFT                                                             5
#define HWIO_GENI_TX_PACKING_CFG0_VEC_0_DIRECTION_BMSK                                                            0x10
#define HWIO_GENI_TX_PACKING_CFG0_VEC_0_DIRECTION_SHFT                                                               4
#define HWIO_GENI_TX_PACKING_CFG0_VEC_0_LENGTH_BMSK                                                                0xe
#define HWIO_GENI_TX_PACKING_CFG0_VEC_0_LENGTH_SHFT                                                                  1
#define HWIO_GENI_TX_PACKING_CFG0_VEC_0_STOP_BMSK                                                                  0x1
#define HWIO_GENI_TX_PACKING_CFG0_VEC_0_STOP_SHFT                                                                    0

#define HWIO_GENI_CFG_REG89_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x164)
#define HWIO_GENI_CFG_REG89_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x164)
#define HWIO_GENI_CFG_REG89_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x164)
#define HWIO_GENI_CFG_REG89_RMSK                                                                               0xfffff
#define HWIO_GENI_CFG_REG89_IN                    \
                in_dword(HWIO_GENI_CFG_REG89_ADDR)
#define HWIO_GENI_CFG_REG89_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG89_ADDR, m)
#define HWIO_GENI_CFG_REG89_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG89_ADDR,v)
#define HWIO_GENI_CFG_REG89_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG89_ADDR,m,v,HWIO_GENI_CFG_REG89_IN)
#define HWIO_GENI_CFG_REG89_VEC_3_START_INDEX_BMSK                                                             0xf8000
#define HWIO_GENI_CFG_REG89_VEC_3_START_INDEX_SHFT                                                                  15
#define HWIO_GENI_CFG_REG89_VEC_3_DIRECTION_BMSK                                                                0x4000
#define HWIO_GENI_CFG_REG89_VEC_3_DIRECTION_SHFT                                                                    14
#define HWIO_GENI_CFG_REG89_VEC_3_LENGTH_BMSK                                                                   0x3800
#define HWIO_GENI_CFG_REG89_VEC_3_LENGTH_SHFT                                                                       11
#define HWIO_GENI_CFG_REG89_VEC_3_STOP_BMSK                                                                      0x400
#define HWIO_GENI_CFG_REG89_VEC_3_STOP_SHFT                                                                         10
#define HWIO_GENI_CFG_REG89_VEC_2_START_INDEX_BMSK                                                               0x3e0
#define HWIO_GENI_CFG_REG89_VEC_2_START_INDEX_SHFT                                                                   5
#define HWIO_GENI_CFG_REG89_VEC_2_DIRECTION_BMSK                                                                  0x10
#define HWIO_GENI_CFG_REG89_VEC_2_DIRECTION_SHFT                                                                     4
#define HWIO_GENI_CFG_REG89_VEC_2_LENGTH_BMSK                                                                      0xe
#define HWIO_GENI_CFG_REG89_VEC_2_LENGTH_SHFT                                                                        1
#define HWIO_GENI_CFG_REG89_VEC_2_STOP_BMSK                                                                        0x1
#define HWIO_GENI_CFG_REG89_VEC_2_STOP_SHFT                                                                          0

#define HWIO_GENI_TX_PACKING_CFG1_ADDR                                                                      (GENI4_IMAGE_REGS_REG_BASE            + 0x164)
#define HWIO_GENI_TX_PACKING_CFG1_PHYS                                                                      (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x164)
#define HWIO_GENI_TX_PACKING_CFG1_OFFS                                                                      (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x164)
#define HWIO_GENI_TX_PACKING_CFG1_RMSK                                                                         0xfffff
#define HWIO_GENI_TX_PACKING_CFG1_IN                    \
                in_dword(HWIO_GENI_TX_PACKING_CFG1_ADDR)
#define HWIO_GENI_TX_PACKING_CFG1_INM(m)            \
                in_dword_masked(HWIO_GENI_TX_PACKING_CFG1_ADDR, m)
#define HWIO_GENI_TX_PACKING_CFG1_OUT(v)            \
                out_dword(HWIO_GENI_TX_PACKING_CFG1_ADDR,v)
#define HWIO_GENI_TX_PACKING_CFG1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_TX_PACKING_CFG1_ADDR,m,v,HWIO_GENI_TX_PACKING_CFG1_IN)
#define HWIO_GENI_TX_PACKING_CFG1_VEC_3_START_INDEX_BMSK                                                       0xf8000
#define HWIO_GENI_TX_PACKING_CFG1_VEC_3_START_INDEX_SHFT                                                            15
#define HWIO_GENI_TX_PACKING_CFG1_VEC_3_DIRECTION_BMSK                                                          0x4000
#define HWIO_GENI_TX_PACKING_CFG1_VEC_3_DIRECTION_SHFT                                                              14
#define HWIO_GENI_TX_PACKING_CFG1_VEC_3_LENGTH_BMSK                                                             0x3800
#define HWIO_GENI_TX_PACKING_CFG1_VEC_3_LENGTH_SHFT                                                                 11
#define HWIO_GENI_TX_PACKING_CFG1_VEC_3_STOP_BMSK                                                                0x400
#define HWIO_GENI_TX_PACKING_CFG1_VEC_3_STOP_SHFT                                                                   10
#define HWIO_GENI_TX_PACKING_CFG1_VEC_2_START_INDEX_BMSK                                                         0x3e0
#define HWIO_GENI_TX_PACKING_CFG1_VEC_2_START_INDEX_SHFT                                                             5
#define HWIO_GENI_TX_PACKING_CFG1_VEC_2_DIRECTION_BMSK                                                            0x10
#define HWIO_GENI_TX_PACKING_CFG1_VEC_2_DIRECTION_SHFT                                                               4
#define HWIO_GENI_TX_PACKING_CFG1_VEC_2_LENGTH_BMSK                                                                0xe
#define HWIO_GENI_TX_PACKING_CFG1_VEC_2_LENGTH_SHFT                                                                  1
#define HWIO_GENI_TX_PACKING_CFG1_VEC_2_STOP_BMSK                                                                  0x1
#define HWIO_GENI_TX_PACKING_CFG1_VEC_2_STOP_SHFT                                                                    0

#define HWIO_GENI_CFG_REG90_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x168)
#define HWIO_GENI_CFG_REG90_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x168)
#define HWIO_GENI_CFG_REG90_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x168)
#define HWIO_GENI_CFG_REG90_RMSK                                                                                 0x3ff
#define HWIO_GENI_CFG_REG90_IN                    \
                in_dword(HWIO_GENI_CFG_REG90_ADDR)
#define HWIO_GENI_CFG_REG90_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG90_ADDR, m)
#define HWIO_GENI_CFG_REG90_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG90_ADDR,v)
#define HWIO_GENI_CFG_REG90_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG90_ADDR,m,v,HWIO_GENI_CFG_REG90_IN)
#define HWIO_GENI_CFG_REG90_M_GP_CNT0_BMSK                                                                       0x3ff
#define HWIO_GENI_CFG_REG90_M_GP_CNT0_SHFT                                                                           0

#define HWIO_UART_TX_WORD_LEN_ADDR                                                                          (GENI4_IMAGE_REGS_REG_BASE            + 0x168)
#define HWIO_UART_TX_WORD_LEN_PHYS                                                                          (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x168)
#define HWIO_UART_TX_WORD_LEN_OFFS                                                                          (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x168)
#define HWIO_UART_TX_WORD_LEN_RMSK                                                                               0x3ff
#define HWIO_UART_TX_WORD_LEN_IN                    \
                in_dword(HWIO_UART_TX_WORD_LEN_ADDR)
#define HWIO_UART_TX_WORD_LEN_INM(m)            \
                in_dword_masked(HWIO_UART_TX_WORD_LEN_ADDR, m)
#define HWIO_UART_TX_WORD_LEN_OUT(v)            \
                out_dword(HWIO_UART_TX_WORD_LEN_ADDR,v)
#define HWIO_UART_TX_WORD_LEN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_UART_TX_WORD_LEN_ADDR,m,v,HWIO_UART_TX_WORD_LEN_IN)
#define HWIO_UART_TX_WORD_LEN_UART_TX_WORD_LEN_BMSK                                                              0x3ff
#define HWIO_UART_TX_WORD_LEN_UART_TX_WORD_LEN_SHFT                                                                  0

#define HWIO_SPI_WORD_LEN_ADDR                                                                              (GENI4_IMAGE_REGS_REG_BASE            + 0x168)
#define HWIO_SPI_WORD_LEN_PHYS                                                                              (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x168)
#define HWIO_SPI_WORD_LEN_OFFS                                                                              (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x168)
#define HWIO_SPI_WORD_LEN_RMSK                                                                                   0x3ff
#define HWIO_SPI_WORD_LEN_IN                    \
                in_dword(HWIO_SPI_WORD_LEN_ADDR)
#define HWIO_SPI_WORD_LEN_INM(m)            \
                in_dword_masked(HWIO_SPI_WORD_LEN_ADDR, m)
#define HWIO_SPI_WORD_LEN_OUT(v)            \
                out_dword(HWIO_SPI_WORD_LEN_ADDR,v)
#define HWIO_SPI_WORD_LEN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SPI_WORD_LEN_ADDR,m,v,HWIO_SPI_WORD_LEN_IN)
#define HWIO_SPI_WORD_LEN_SPI_WORD_LEN_BMSK                                                                      0x3ff
#define HWIO_SPI_WORD_LEN_SPI_WORD_LEN_SHFT                                                                          0

#define HWIO_SPI_SLAVE_WORD_LEN_ADDR                                                                        (GENI4_IMAGE_REGS_REG_BASE            + 0x168)
#define HWIO_SPI_SLAVE_WORD_LEN_PHYS                                                                        (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x168)
#define HWIO_SPI_SLAVE_WORD_LEN_OFFS                                                                        (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x168)
#define HWIO_SPI_SLAVE_WORD_LEN_RMSK                                                                             0x3ff
#define HWIO_SPI_SLAVE_WORD_LEN_IN                    \
                in_dword(HWIO_SPI_SLAVE_WORD_LEN_ADDR)
#define HWIO_SPI_SLAVE_WORD_LEN_INM(m)            \
                in_dword_masked(HWIO_SPI_SLAVE_WORD_LEN_ADDR, m)
#define HWIO_SPI_SLAVE_WORD_LEN_OUT(v)            \
                out_dword(HWIO_SPI_SLAVE_WORD_LEN_ADDR,v)
#define HWIO_SPI_SLAVE_WORD_LEN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SPI_SLAVE_WORD_LEN_ADDR,m,v,HWIO_SPI_SLAVE_WORD_LEN_IN)
#define HWIO_SPI_SLAVE_WORD_LEN_SPI_SLAVE_WORD_LEN_BMSK                                                          0x3ff
#define HWIO_SPI_SLAVE_WORD_LEN_SPI_SLAVE_WORD_LEN_SHFT                                                              0

#define HWIO_I3C_SCL_HIGH_ADDR                                                                              (GENI4_IMAGE_REGS_REG_BASE            + 0x168)
#define HWIO_I3C_SCL_HIGH_PHYS                                                                              (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x168)
#define HWIO_I3C_SCL_HIGH_OFFS                                                                              (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x168)
#define HWIO_I3C_SCL_HIGH_RMSK                                                                                   0x3ff
#define HWIO_I3C_SCL_HIGH_IN                    \
                in_dword(HWIO_I3C_SCL_HIGH_ADDR)
#define HWIO_I3C_SCL_HIGH_INM(m)            \
                in_dword_masked(HWIO_I3C_SCL_HIGH_ADDR, m)
#define HWIO_I3C_SCL_HIGH_OUT(v)            \
                out_dword(HWIO_I3C_SCL_HIGH_ADDR,v)
#define HWIO_I3C_SCL_HIGH_OUTM(m,v) \
                out_dword_masked_ns(HWIO_I3C_SCL_HIGH_ADDR,m,v,HWIO_I3C_SCL_HIGH_IN)
#define HWIO_I3C_SCL_HIGH_I3C_SCL_HIGH_COUNTER_BMSK                                                              0x3ff
#define HWIO_I3C_SCL_HIGH_I3C_SCL_HIGH_COUNTER_SHFT                                                                  0

#define HWIO_GENI_CFG_REG91_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x16c)
#define HWIO_GENI_CFG_REG91_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x16c)
#define HWIO_GENI_CFG_REG91_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x16c)
#define HWIO_GENI_CFG_REG91_RMSK                                                                              0xffffff
#define HWIO_GENI_CFG_REG91_IN                    \
                in_dword(HWIO_GENI_CFG_REG91_ADDR)
#define HWIO_GENI_CFG_REG91_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG91_ADDR, m)
#define HWIO_GENI_CFG_REG91_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG91_ADDR,v)
#define HWIO_GENI_CFG_REG91_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG91_ADDR,m,v,HWIO_GENI_CFG_REG91_IN)
#define HWIO_GENI_CFG_REG91_M_GP_CNT1_BMSK                                                                    0xffffff
#define HWIO_GENI_CFG_REG91_M_GP_CNT1_SHFT                                                                           0

#define HWIO_UART_TX_STOP_BIT_LEN_ADDR                                                                      (GENI4_IMAGE_REGS_REG_BASE            + 0x16c)
#define HWIO_UART_TX_STOP_BIT_LEN_PHYS                                                                      (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x16c)
#define HWIO_UART_TX_STOP_BIT_LEN_OFFS                                                                      (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x16c)
#define HWIO_UART_TX_STOP_BIT_LEN_RMSK                                                                        0xffffff
#define HWIO_UART_TX_STOP_BIT_LEN_IN                    \
                in_dword(HWIO_UART_TX_STOP_BIT_LEN_ADDR)
#define HWIO_UART_TX_STOP_BIT_LEN_INM(m)            \
                in_dword_masked(HWIO_UART_TX_STOP_BIT_LEN_ADDR, m)
#define HWIO_UART_TX_STOP_BIT_LEN_OUT(v)            \
                out_dword(HWIO_UART_TX_STOP_BIT_LEN_ADDR,v)
#define HWIO_UART_TX_STOP_BIT_LEN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_UART_TX_STOP_BIT_LEN_ADDR,m,v,HWIO_UART_TX_STOP_BIT_LEN_IN)
#define HWIO_UART_TX_STOP_BIT_LEN_UART_TX_STOP_BIT_LEN_BMSK                                                   0xffffff
#define HWIO_UART_TX_STOP_BIT_LEN_UART_TX_STOP_BIT_LEN_SHFT                                                          0

#define HWIO_SPI_TX_TRANS_LEN_ADDR                                                                          (GENI4_IMAGE_REGS_REG_BASE            + 0x16c)
#define HWIO_SPI_TX_TRANS_LEN_PHYS                                                                          (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x16c)
#define HWIO_SPI_TX_TRANS_LEN_OFFS                                                                          (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x16c)
#define HWIO_SPI_TX_TRANS_LEN_RMSK                                                                            0xffffff
#define HWIO_SPI_TX_TRANS_LEN_IN                    \
                in_dword(HWIO_SPI_TX_TRANS_LEN_ADDR)
#define HWIO_SPI_TX_TRANS_LEN_INM(m)            \
                in_dword_masked(HWIO_SPI_TX_TRANS_LEN_ADDR, m)
#define HWIO_SPI_TX_TRANS_LEN_OUT(v)            \
                out_dword(HWIO_SPI_TX_TRANS_LEN_ADDR,v)
#define HWIO_SPI_TX_TRANS_LEN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SPI_TX_TRANS_LEN_ADDR,m,v,HWIO_SPI_TX_TRANS_LEN_IN)
#define HWIO_SPI_TX_TRANS_LEN_SPI_TX_TRANS_LEN_BMSK                                                           0xffffff
#define HWIO_SPI_TX_TRANS_LEN_SPI_TX_TRANS_LEN_SHFT                                                                  0

#define HWIO_I2C_TX_TRANS_LEN_ADDR                                                                          (GENI4_IMAGE_REGS_REG_BASE            + 0x16c)
#define HWIO_I2C_TX_TRANS_LEN_PHYS                                                                          (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x16c)
#define HWIO_I2C_TX_TRANS_LEN_OFFS                                                                          (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x16c)
#define HWIO_I2C_TX_TRANS_LEN_RMSK                                                                            0xffffff
#define HWIO_I2C_TX_TRANS_LEN_IN                    \
                in_dword(HWIO_I2C_TX_TRANS_LEN_ADDR)
#define HWIO_I2C_TX_TRANS_LEN_INM(m)            \
                in_dword_masked(HWIO_I2C_TX_TRANS_LEN_ADDR, m)
#define HWIO_I2C_TX_TRANS_LEN_OUT(v)            \
                out_dword(HWIO_I2C_TX_TRANS_LEN_ADDR,v)
#define HWIO_I2C_TX_TRANS_LEN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_I2C_TX_TRANS_LEN_ADDR,m,v,HWIO_I2C_TX_TRANS_LEN_IN)
#define HWIO_I2C_TX_TRANS_LEN_I2C_TX_TRANS_LEN_BMSK                                                           0xffffff
#define HWIO_I2C_TX_TRANS_LEN_I2C_TX_TRANS_LEN_SHFT                                                                  0

#define HWIO_I3C_TX_TRANS_LEN_ADDR                                                                          (GENI4_IMAGE_REGS_REG_BASE            + 0x16c)
#define HWIO_I3C_TX_TRANS_LEN_PHYS                                                                          (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x16c)
#define HWIO_I3C_TX_TRANS_LEN_OFFS                                                                          (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x16c)
#define HWIO_I3C_TX_TRANS_LEN_RMSK                                                                            0xffffff
#define HWIO_I3C_TX_TRANS_LEN_IN                    \
                in_dword(HWIO_I3C_TX_TRANS_LEN_ADDR)
#define HWIO_I3C_TX_TRANS_LEN_INM(m)            \
                in_dword_masked(HWIO_I3C_TX_TRANS_LEN_ADDR, m)
#define HWIO_I3C_TX_TRANS_LEN_OUT(v)            \
                out_dword(HWIO_I3C_TX_TRANS_LEN_ADDR,v)
#define HWIO_I3C_TX_TRANS_LEN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_I3C_TX_TRANS_LEN_ADDR,m,v,HWIO_I3C_TX_TRANS_LEN_IN)
#define HWIO_I3C_TX_TRANS_LEN_TX_TRANS_LEN_BMSK                                                               0xffffff
#define HWIO_I3C_TX_TRANS_LEN_TX_TRANS_LEN_SHFT                                                                      0

#define HWIO_GENI_CFG_REG92_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x170)
#define HWIO_GENI_CFG_REG92_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x170)
#define HWIO_GENI_CFG_REG92_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x170)
#define HWIO_GENI_CFG_REG92_RMSK                                                                              0xffffff
#define HWIO_GENI_CFG_REG92_IN                    \
                in_dword(HWIO_GENI_CFG_REG92_ADDR)
#define HWIO_GENI_CFG_REG92_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG92_ADDR, m)
#define HWIO_GENI_CFG_REG92_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG92_ADDR,v)
#define HWIO_GENI_CFG_REG92_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG92_ADDR,m,v,HWIO_GENI_CFG_REG92_IN)
#define HWIO_GENI_CFG_REG92_M_GP_CNT2_BMSK                                                                    0xffffff
#define HWIO_GENI_CFG_REG92_M_GP_CNT2_SHFT                                                                           0

#define HWIO_UART_TX_TRANS_LEN_ADDR                                                                         (GENI4_IMAGE_REGS_REG_BASE            + 0x170)
#define HWIO_UART_TX_TRANS_LEN_PHYS                                                                         (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x170)
#define HWIO_UART_TX_TRANS_LEN_OFFS                                                                         (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x170)
#define HWIO_UART_TX_TRANS_LEN_RMSK                                                                           0xffffff
#define HWIO_UART_TX_TRANS_LEN_IN                    \
                in_dword(HWIO_UART_TX_TRANS_LEN_ADDR)
#define HWIO_UART_TX_TRANS_LEN_INM(m)            \
                in_dword_masked(HWIO_UART_TX_TRANS_LEN_ADDR, m)
#define HWIO_UART_TX_TRANS_LEN_OUT(v)            \
                out_dword(HWIO_UART_TX_TRANS_LEN_ADDR,v)
#define HWIO_UART_TX_TRANS_LEN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_UART_TX_TRANS_LEN_ADDR,m,v,HWIO_UART_TX_TRANS_LEN_IN)
#define HWIO_UART_TX_TRANS_LEN_UART_TX_TRANS_LEN_BMSK                                                         0xffffff
#define HWIO_UART_TX_TRANS_LEN_UART_TX_TRANS_LEN_SHFT                                                                0

#define HWIO_AFC_PRE_CMD_DLY_ADDR                                                                           (GENI4_IMAGE_REGS_REG_BASE            + 0x170)
#define HWIO_AFC_PRE_CMD_DLY_PHYS                                                                           (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x170)
#define HWIO_AFC_PRE_CMD_DLY_OFFS                                                                           (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x170)
#define HWIO_AFC_PRE_CMD_DLY_RMSK                                                                             0xffffff
#define HWIO_AFC_PRE_CMD_DLY_IN                    \
                in_dword(HWIO_AFC_PRE_CMD_DLY_ADDR)
#define HWIO_AFC_PRE_CMD_DLY_INM(m)            \
                in_dword_masked(HWIO_AFC_PRE_CMD_DLY_ADDR, m)
#define HWIO_AFC_PRE_CMD_DLY_OUT(v)            \
                out_dword(HWIO_AFC_PRE_CMD_DLY_ADDR,v)
#define HWIO_AFC_PRE_CMD_DLY_OUTM(m,v) \
                out_dword_masked_ns(HWIO_AFC_PRE_CMD_DLY_ADDR,m,v,HWIO_AFC_PRE_CMD_DLY_IN)
#define HWIO_AFC_PRE_CMD_DLY_AFC_PRE_CMD_DLY_BMSK                                                             0xffffff
#define HWIO_AFC_PRE_CMD_DLY_AFC_PRE_CMD_DLY_SHFT                                                                    0

#define HWIO_SPI_RX_TRANS_LEN_ADDR                                                                          (GENI4_IMAGE_REGS_REG_BASE            + 0x170)
#define HWIO_SPI_RX_TRANS_LEN_PHYS                                                                          (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x170)
#define HWIO_SPI_RX_TRANS_LEN_OFFS                                                                          (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x170)
#define HWIO_SPI_RX_TRANS_LEN_RMSK                                                                            0xffffff
#define HWIO_SPI_RX_TRANS_LEN_IN                    \
                in_dword(HWIO_SPI_RX_TRANS_LEN_ADDR)
#define HWIO_SPI_RX_TRANS_LEN_INM(m)            \
                in_dword_masked(HWIO_SPI_RX_TRANS_LEN_ADDR, m)
#define HWIO_SPI_RX_TRANS_LEN_OUT(v)            \
                out_dword(HWIO_SPI_RX_TRANS_LEN_ADDR,v)
#define HWIO_SPI_RX_TRANS_LEN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SPI_RX_TRANS_LEN_ADDR,m,v,HWIO_SPI_RX_TRANS_LEN_IN)
#define HWIO_SPI_RX_TRANS_LEN_SPI_RX_TRANS_LEN_BMSK                                                           0xffffff
#define HWIO_SPI_RX_TRANS_LEN_SPI_RX_TRANS_LEN_SHFT                                                                  0

#define HWIO_I2C_RX_TRANS_LEN_ADDR                                                                          (GENI4_IMAGE_REGS_REG_BASE            + 0x170)
#define HWIO_I2C_RX_TRANS_LEN_PHYS                                                                          (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x170)
#define HWIO_I2C_RX_TRANS_LEN_OFFS                                                                          (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x170)
#define HWIO_I2C_RX_TRANS_LEN_RMSK                                                                            0xffffff
#define HWIO_I2C_RX_TRANS_LEN_IN                    \
                in_dword(HWIO_I2C_RX_TRANS_LEN_ADDR)
#define HWIO_I2C_RX_TRANS_LEN_INM(m)            \
                in_dword_masked(HWIO_I2C_RX_TRANS_LEN_ADDR, m)
#define HWIO_I2C_RX_TRANS_LEN_OUT(v)            \
                out_dword(HWIO_I2C_RX_TRANS_LEN_ADDR,v)
#define HWIO_I2C_RX_TRANS_LEN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_I2C_RX_TRANS_LEN_ADDR,m,v,HWIO_I2C_RX_TRANS_LEN_IN)
#define HWIO_I2C_RX_TRANS_LEN_I2C_RX_TRANS_LEN_BMSK                                                           0xffffff
#define HWIO_I2C_RX_TRANS_LEN_I2C_RX_TRANS_LEN_SHFT                                                                  0

#define HWIO_I3C_RX_TRANS_LEN_ADDR                                                                          (GENI4_IMAGE_REGS_REG_BASE            + 0x170)
#define HWIO_I3C_RX_TRANS_LEN_PHYS                                                                          (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x170)
#define HWIO_I3C_RX_TRANS_LEN_OFFS                                                                          (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x170)
#define HWIO_I3C_RX_TRANS_LEN_RMSK                                                                            0xffffff
#define HWIO_I3C_RX_TRANS_LEN_IN                    \
                in_dword(HWIO_I3C_RX_TRANS_LEN_ADDR)
#define HWIO_I3C_RX_TRANS_LEN_INM(m)            \
                in_dword_masked(HWIO_I3C_RX_TRANS_LEN_ADDR, m)
#define HWIO_I3C_RX_TRANS_LEN_OUT(v)            \
                out_dword(HWIO_I3C_RX_TRANS_LEN_ADDR,v)
#define HWIO_I3C_RX_TRANS_LEN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_I3C_RX_TRANS_LEN_ADDR,m,v,HWIO_I3C_RX_TRANS_LEN_IN)
#define HWIO_I3C_RX_TRANS_LEN_RX_TRANS_LEN_BMSK                                                               0xffffff
#define HWIO_I3C_RX_TRANS_LEN_RX_TRANS_LEN_SHFT                                                                      0

#define HWIO_GENI_CFG_REG93_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x174)
#define HWIO_GENI_CFG_REG93_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x174)
#define HWIO_GENI_CFG_REG93_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x174)
#define HWIO_GENI_CFG_REG93_RMSK                                                                              0xffffff
#define HWIO_GENI_CFG_REG93_IN                    \
                in_dword(HWIO_GENI_CFG_REG93_ADDR)
#define HWIO_GENI_CFG_REG93_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG93_ADDR, m)
#define HWIO_GENI_CFG_REG93_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG93_ADDR,v)
#define HWIO_GENI_CFG_REG93_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG93_ADDR,m,v,HWIO_GENI_CFG_REG93_IN)
#define HWIO_GENI_CFG_REG93_M_GP_CNT3_BMSK                                                                    0xffffff
#define HWIO_GENI_CFG_REG93_M_GP_CNT3_SHFT                                                                           0

#define HWIO_LM_UART_CYCLES_TO_CTS_OVERRIDE_ADDR                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x174)
#define HWIO_LM_UART_CYCLES_TO_CTS_OVERRIDE_PHYS                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x174)
#define HWIO_LM_UART_CYCLES_TO_CTS_OVERRIDE_OFFS                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x174)
#define HWIO_LM_UART_CYCLES_TO_CTS_OVERRIDE_RMSK                                                              0xffffff
#define HWIO_LM_UART_CYCLES_TO_CTS_OVERRIDE_IN                    \
                in_dword(HWIO_LM_UART_CYCLES_TO_CTS_OVERRIDE_ADDR)
#define HWIO_LM_UART_CYCLES_TO_CTS_OVERRIDE_INM(m)            \
                in_dword_masked(HWIO_LM_UART_CYCLES_TO_CTS_OVERRIDE_ADDR, m)
#define HWIO_LM_UART_CYCLES_TO_CTS_OVERRIDE_OUT(v)            \
                out_dword(HWIO_LM_UART_CYCLES_TO_CTS_OVERRIDE_ADDR,v)
#define HWIO_LM_UART_CYCLES_TO_CTS_OVERRIDE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_LM_UART_CYCLES_TO_CTS_OVERRIDE_ADDR,m,v,HWIO_LM_UART_CYCLES_TO_CTS_OVERRIDE_IN)
#define HWIO_LM_UART_CYCLES_TO_CTS_OVERRIDE_LM_UART_CYCLES_TO_CTS_OVERRIDE_BMSK                               0xffffff
#define HWIO_LM_UART_CYCLES_TO_CTS_OVERRIDE_LM_UART_CYCLES_TO_CTS_OVERRIDE_SHFT                                      0

#define HWIO_SPI_PRE_POST_CMD_DLY_ADDR                                                                      (GENI4_IMAGE_REGS_REG_BASE            + 0x174)
#define HWIO_SPI_PRE_POST_CMD_DLY_PHYS                                                                      (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x174)
#define HWIO_SPI_PRE_POST_CMD_DLY_OFFS                                                                      (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x174)
#define HWIO_SPI_PRE_POST_CMD_DLY_RMSK                                                                        0xffffff
#define HWIO_SPI_PRE_POST_CMD_DLY_IN                    \
                in_dword(HWIO_SPI_PRE_POST_CMD_DLY_ADDR)
#define HWIO_SPI_PRE_POST_CMD_DLY_INM(m)            \
                in_dword_masked(HWIO_SPI_PRE_POST_CMD_DLY_ADDR, m)
#define HWIO_SPI_PRE_POST_CMD_DLY_OUT(v)            \
                out_dword(HWIO_SPI_PRE_POST_CMD_DLY_ADDR,v)
#define HWIO_SPI_PRE_POST_CMD_DLY_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SPI_PRE_POST_CMD_DLY_ADDR,m,v,HWIO_SPI_PRE_POST_CMD_DLY_IN)
#define HWIO_SPI_PRE_POST_CMD_DLY_SPI_PRE_POST_CMD_DLY_BMSK                                                   0xffffff
#define HWIO_SPI_PRE_POST_CMD_DLY_SPI_PRE_POST_CMD_DLY_SHFT                                                          0

#define HWIO_I2C_DELAY_COUNTER_ADDR                                                                         (GENI4_IMAGE_REGS_REG_BASE            + 0x174)
#define HWIO_I2C_DELAY_COUNTER_PHYS                                                                         (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x174)
#define HWIO_I2C_DELAY_COUNTER_OFFS                                                                         (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x174)
#define HWIO_I2C_DELAY_COUNTER_RMSK                                                                           0xffffff
#define HWIO_I2C_DELAY_COUNTER_IN                    \
                in_dword(HWIO_I2C_DELAY_COUNTER_ADDR)
#define HWIO_I2C_DELAY_COUNTER_INM(m)            \
                in_dword_masked(HWIO_I2C_DELAY_COUNTER_ADDR, m)
#define HWIO_I2C_DELAY_COUNTER_OUT(v)            \
                out_dword(HWIO_I2C_DELAY_COUNTER_ADDR,v)
#define HWIO_I2C_DELAY_COUNTER_OUTM(m,v) \
                out_dword_masked_ns(HWIO_I2C_DELAY_COUNTER_ADDR,m,v,HWIO_I2C_DELAY_COUNTER_IN)
#define HWIO_I2C_DELAY_COUNTER_I2C_DELAY_COUNTER_BMSK                                                         0xffffff
#define HWIO_I2C_DELAY_COUNTER_I2C_DELAY_COUNTER_SHFT                                                                0

#define HWIO_I3C_DELAY_COUNTER_ADDR                                                                         (GENI4_IMAGE_REGS_REG_BASE            + 0x174)
#define HWIO_I3C_DELAY_COUNTER_PHYS                                                                         (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x174)
#define HWIO_I3C_DELAY_COUNTER_OFFS                                                                         (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x174)
#define HWIO_I3C_DELAY_COUNTER_RMSK                                                                           0xffffff
#define HWIO_I3C_DELAY_COUNTER_IN                    \
                in_dword(HWIO_I3C_DELAY_COUNTER_ADDR)
#define HWIO_I3C_DELAY_COUNTER_INM(m)            \
                in_dword_masked(HWIO_I3C_DELAY_COUNTER_ADDR, m)
#define HWIO_I3C_DELAY_COUNTER_OUT(v)            \
                out_dword(HWIO_I3C_DELAY_COUNTER_ADDR,v)
#define HWIO_I3C_DELAY_COUNTER_OUTM(m,v) \
                out_dword_masked_ns(HWIO_I3C_DELAY_COUNTER_ADDR,m,v,HWIO_I3C_DELAY_COUNTER_IN)
#define HWIO_I3C_DELAY_COUNTER_DELAY_COUNTER_BMSK                                                             0xffffff
#define HWIO_I3C_DELAY_COUNTER_DELAY_COUNTER_SHFT                                                                    0

#define HWIO_GENI_CFG_REG94_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x178)
#define HWIO_GENI_CFG_REG94_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x178)
#define HWIO_GENI_CFG_REG94_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x178)
#define HWIO_GENI_CFG_REG94_RMSK                                                                            0x3fffffff
#define HWIO_GENI_CFG_REG94_IN                    \
                in_dword(HWIO_GENI_CFG_REG94_ADDR)
#define HWIO_GENI_CFG_REG94_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG94_ADDR, m)
#define HWIO_GENI_CFG_REG94_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG94_ADDR,v)
#define HWIO_GENI_CFG_REG94_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG94_ADDR,m,v,HWIO_GENI_CFG_REG94_IN)
#define HWIO_GENI_CFG_REG94_M_GP_CNT6_BMSK                                                                  0x3ff00000
#define HWIO_GENI_CFG_REG94_M_GP_CNT6_SHFT                                                                          20
#define HWIO_GENI_CFG_REG94_M_GP_CNT5_BMSK                                                                     0xffc00
#define HWIO_GENI_CFG_REG94_M_GP_CNT5_SHFT                                                                          10
#define HWIO_GENI_CFG_REG94_M_GP_CNT4_BMSK                                                                       0x3ff
#define HWIO_GENI_CFG_REG94_M_GP_CNT4_SHFT                                                                           0

#define HWIO_UART_RX_CHAR_HUNT_ADDR                                                                         (GENI4_IMAGE_REGS_REG_BASE            + 0x178)
#define HWIO_UART_RX_CHAR_HUNT_PHYS                                                                         (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x178)
#define HWIO_UART_RX_CHAR_HUNT_OFFS                                                                         (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x178)
#define HWIO_UART_RX_CHAR_HUNT_RMSK                                                                              0x3ff
#define HWIO_UART_RX_CHAR_HUNT_IN                    \
                in_dword(HWIO_UART_RX_CHAR_HUNT_ADDR)
#define HWIO_UART_RX_CHAR_HUNT_INM(m)            \
                in_dword_masked(HWIO_UART_RX_CHAR_HUNT_ADDR, m)
#define HWIO_UART_RX_CHAR_HUNT_OUT(v)            \
                out_dword(HWIO_UART_RX_CHAR_HUNT_ADDR,v)
#define HWIO_UART_RX_CHAR_HUNT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_UART_RX_CHAR_HUNT_ADDR,m,v,HWIO_UART_RX_CHAR_HUNT_IN)
#define HWIO_UART_RX_CHAR_HUNT_CHAR_HUNT_PATTERN_BMSK                                                            0x3ff
#define HWIO_UART_RX_CHAR_HUNT_CHAR_HUNT_PATTERN_SHFT                                                                0

#define HWIO_SPI_DELAYS_COUNTERS_ADDR                                                                       (GENI4_IMAGE_REGS_REG_BASE            + 0x178)
#define HWIO_SPI_DELAYS_COUNTERS_PHYS                                                                       (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x178)
#define HWIO_SPI_DELAYS_COUNTERS_OFFS                                                                       (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x178)
#define HWIO_SPI_DELAYS_COUNTERS_RMSK                                                                       0x3fffffff
#define HWIO_SPI_DELAYS_COUNTERS_IN                    \
                in_dword(HWIO_SPI_DELAYS_COUNTERS_ADDR)
#define HWIO_SPI_DELAYS_COUNTERS_INM(m)            \
                in_dword_masked(HWIO_SPI_DELAYS_COUNTERS_ADDR, m)
#define HWIO_SPI_DELAYS_COUNTERS_OUT(v)            \
                out_dword(HWIO_SPI_DELAYS_COUNTERS_ADDR,v)
#define HWIO_SPI_DELAYS_COUNTERS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SPI_DELAYS_COUNTERS_ADDR,m,v,HWIO_SPI_DELAYS_COUNTERS_IN)
#define HWIO_SPI_DELAYS_COUNTERS_SPI_PIPE_DLY_TPM_BMSK                                                      0x3ff00000
#define HWIO_SPI_DELAYS_COUNTERS_SPI_PIPE_DLY_TPM_SHFT                                                              20
#define HWIO_SPI_DELAYS_COUNTERS_SPI_CS_CLK_DLY_BMSK                                                           0xffc00
#define HWIO_SPI_DELAYS_COUNTERS_SPI_CS_CLK_DLY_SHFT                                                                10
#define HWIO_SPI_DELAYS_COUNTERS_SPI_INTER_WORDS_DLY_BMSK                                                        0x3ff
#define HWIO_SPI_DELAYS_COUNTERS_SPI_INTER_WORDS_DLY_SHFT                                                            0

#define HWIO_I2C_SCL_COUNTERS_ADDR                                                                          (GENI4_IMAGE_REGS_REG_BASE            + 0x178)
#define HWIO_I2C_SCL_COUNTERS_PHYS                                                                          (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x178)
#define HWIO_I2C_SCL_COUNTERS_OFFS                                                                          (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x178)
#define HWIO_I2C_SCL_COUNTERS_RMSK                                                                          0x3fffffff
#define HWIO_I2C_SCL_COUNTERS_IN                    \
                in_dword(HWIO_I2C_SCL_COUNTERS_ADDR)
#define HWIO_I2C_SCL_COUNTERS_INM(m)            \
                in_dword_masked(HWIO_I2C_SCL_COUNTERS_ADDR, m)
#define HWIO_I2C_SCL_COUNTERS_OUT(v)            \
                out_dword(HWIO_I2C_SCL_COUNTERS_ADDR,v)
#define HWIO_I2C_SCL_COUNTERS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_I2C_SCL_COUNTERS_ADDR,m,v,HWIO_I2C_SCL_COUNTERS_IN)
#define HWIO_I2C_SCL_COUNTERS_I2C_SCL_HIGH_COUNTER_BMSK                                                     0x3ff00000
#define HWIO_I2C_SCL_COUNTERS_I2C_SCL_HIGH_COUNTER_SHFT                                                             20
#define HWIO_I2C_SCL_COUNTERS_I2C_SCL_LOW_COUNTER_BMSK                                                         0xffc00
#define HWIO_I2C_SCL_COUNTERS_I2C_SCL_LOW_COUNTER_SHFT                                                              10
#define HWIO_I2C_SCL_COUNTERS_I2C_SCL_CYCLE_COUNTER_BMSK                                                         0x3ff
#define HWIO_I2C_SCL_COUNTERS_I2C_SCL_CYCLE_COUNTER_SHFT                                                             0

#define HWIO_I3C_SCL_COUNTERS_ADDR                                                                          (GENI4_IMAGE_REGS_REG_BASE            + 0x178)
#define HWIO_I3C_SCL_COUNTERS_PHYS                                                                          (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x178)
#define HWIO_I3C_SCL_COUNTERS_OFFS                                                                          (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x178)
#define HWIO_I3C_SCL_COUNTERS_RMSK                                                                          0x3fffffff
#define HWIO_I3C_SCL_COUNTERS_IN                    \
                in_dword(HWIO_I3C_SCL_COUNTERS_ADDR)
#define HWIO_I3C_SCL_COUNTERS_INM(m)            \
                in_dword_masked(HWIO_I3C_SCL_COUNTERS_ADDR, m)
#define HWIO_I3C_SCL_COUNTERS_OUT(v)            \
                out_dword(HWIO_I3C_SCL_COUNTERS_ADDR,v)
#define HWIO_I3C_SCL_COUNTERS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_I3C_SCL_COUNTERS_ADDR,m,v,HWIO_I3C_SCL_COUNTERS_IN)
#define HWIO_I3C_SCL_COUNTERS_I2C_SCL_HIGH_COUNTER_BMSK                                                     0x3ff00000
#define HWIO_I3C_SCL_COUNTERS_I2C_SCL_HIGH_COUNTER_SHFT                                                             20
#define HWIO_I3C_SCL_COUNTERS_I2C_SCL_LOW_COUNTER_BMSK                                                         0xffc00
#define HWIO_I3C_SCL_COUNTERS_I2C_SCL_LOW_COUNTER_SHFT                                                              10
#define HWIO_I3C_SCL_COUNTERS_I2C_SCL_CYCLE_COUNTER_BMSK                                                         0x3ff
#define HWIO_I3C_SCL_COUNTERS_I2C_SCL_CYCLE_COUNTER_SHFT                                                             0

#define HWIO_GENI_CFG_REG95_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x17c)
#define HWIO_GENI_CFG_REG95_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x17c)
#define HWIO_GENI_CFG_REG95_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x17c)
#define HWIO_GENI_CFG_REG95_RMSK                                                                                 0x3ff
#define HWIO_GENI_CFG_REG95_IN                    \
                in_dword(HWIO_GENI_CFG_REG95_ADDR)
#define HWIO_GENI_CFG_REG95_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG95_ADDR, m)
#define HWIO_GENI_CFG_REG95_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG95_ADDR,v)
#define HWIO_GENI_CFG_REG95_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG95_ADDR,m,v,HWIO_GENI_CFG_REG95_IN)
#define HWIO_GENI_CFG_REG95_M_GP_CNT7_BMSK                                                                       0x3ff
#define HWIO_GENI_CFG_REG95_M_GP_CNT7_SHFT                                                                           0

#define HWIO_SPI_DUMMY_DLY_ADDR                                                                             (GENI4_IMAGE_REGS_REG_BASE            + 0x17c)
#define HWIO_SPI_DUMMY_DLY_PHYS                                                                             (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x17c)
#define HWIO_SPI_DUMMY_DLY_OFFS                                                                             (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x17c)
#define HWIO_SPI_DUMMY_DLY_RMSK                                                                                  0x3ff
#define HWIO_SPI_DUMMY_DLY_IN                    \
                in_dword(HWIO_SPI_DUMMY_DLY_ADDR)
#define HWIO_SPI_DUMMY_DLY_INM(m)            \
                in_dword_masked(HWIO_SPI_DUMMY_DLY_ADDR, m)
#define HWIO_SPI_DUMMY_DLY_OUT(v)            \
                out_dword(HWIO_SPI_DUMMY_DLY_ADDR,v)
#define HWIO_SPI_DUMMY_DLY_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SPI_DUMMY_DLY_ADDR,m,v,HWIO_SPI_DUMMY_DLY_IN)
#define HWIO_SPI_DUMMY_DLY_SPI_DUMMY_DLY_BMSK                                                                    0x3ff
#define HWIO_SPI_DUMMY_DLY_SPI_DUMMY_DLY_SHFT                                                                        0

#define HWIO_I3C_SCL_LOW_ADDR                                                                               (GENI4_IMAGE_REGS_REG_BASE            + 0x17c)
#define HWIO_I3C_SCL_LOW_PHYS                                                                               (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x17c)
#define HWIO_I3C_SCL_LOW_OFFS                                                                               (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x17c)
#define HWIO_I3C_SCL_LOW_RMSK                                                                                    0x3ff
#define HWIO_I3C_SCL_LOW_IN                    \
                in_dword(HWIO_I3C_SCL_LOW_ADDR)
#define HWIO_I3C_SCL_LOW_INM(m)            \
                in_dword_masked(HWIO_I3C_SCL_LOW_ADDR, m)
#define HWIO_I3C_SCL_LOW_OUT(v)            \
                out_dword(HWIO_I3C_SCL_LOW_ADDR,v)
#define HWIO_I3C_SCL_LOW_OUTM(m,v) \
                out_dword_masked_ns(HWIO_I3C_SCL_LOW_ADDR,m,v,HWIO_I3C_SCL_LOW_IN)
#define HWIO_I3C_SCL_LOW_I3C_SCL_LOW_COUNTER_BMSK                                                                0x3ff
#define HWIO_I3C_SCL_LOW_I3C_SCL_LOW_COUNTER_SHFT                                                                    0

#define HWIO_GENI_CFG_REG96_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x180)
#define HWIO_GENI_CFG_REG96_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x180)
#define HWIO_GENI_CFG_REG96_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x180)
#define HWIO_GENI_CFG_REG96_RMSK                                                                                  0x3f
#define HWIO_GENI_CFG_REG96_IN                    \
                in_dword(HWIO_GENI_CFG_REG96_ADDR)
#define HWIO_GENI_CFG_REG96_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG96_ADDR, m)
#define HWIO_GENI_CFG_REG96_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG96_ADDR,v)
#define HWIO_GENI_CFG_REG96_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG96_ADDR,m,v,HWIO_GENI_CFG_REG96_IN)
#define HWIO_GENI_CFG_REG96_S_SW_COMP5_BMSK                                                                       0x20
#define HWIO_GENI_CFG_REG96_S_SW_COMP5_SHFT                                                                          5
#define HWIO_GENI_CFG_REG96_S_SW_COMP4_BMSK                                                                       0x10
#define HWIO_GENI_CFG_REG96_S_SW_COMP4_SHFT                                                                          4
#define HWIO_GENI_CFG_REG96_S_SW_COMP3_BMSK                                                                        0x8
#define HWIO_GENI_CFG_REG96_S_SW_COMP3_SHFT                                                                          3
#define HWIO_GENI_CFG_REG96_S_SW_COMP2_BMSK                                                                        0x4
#define HWIO_GENI_CFG_REG96_S_SW_COMP2_SHFT                                                                          2
#define HWIO_GENI_CFG_REG96_S_SW_COMP1_BMSK                                                                        0x2
#define HWIO_GENI_CFG_REG96_S_SW_COMP1_SHFT                                                                          1
#define HWIO_GENI_CFG_REG96_S_SW_COMP0_BMSK                                                                        0x1
#define HWIO_GENI_CFG_REG96_S_SW_COMP0_SHFT                                                                          0

#define HWIO_UART_RX_TRANS_CFG_ADDR                                                                         (GENI4_IMAGE_REGS_REG_BASE            + 0x180)
#define HWIO_UART_RX_TRANS_CFG_PHYS                                                                         (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x180)
#define HWIO_UART_RX_TRANS_CFG_OFFS                                                                         (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x180)
#define HWIO_UART_RX_TRANS_CFG_RMSK                                                                               0x17
#define HWIO_UART_RX_TRANS_CFG_IN                    \
                in_dword(HWIO_UART_RX_TRANS_CFG_ADDR)
#define HWIO_UART_RX_TRANS_CFG_INM(m)            \
                in_dword_masked(HWIO_UART_RX_TRANS_CFG_ADDR, m)
#define HWIO_UART_RX_TRANS_CFG_OUT(v)            \
                out_dword(HWIO_UART_RX_TRANS_CFG_ADDR,v)
#define HWIO_UART_RX_TRANS_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_UART_RX_TRANS_CFG_ADDR,m,v,HWIO_UART_RX_TRANS_CFG_IN)
#define HWIO_UART_RX_TRANS_CFG_UART_PARITY_EN_BMSK                                                                0x10
#define HWIO_UART_RX_TRANS_CFG_UART_PARITY_EN_SHFT                                                                   4
#define HWIO_UART_RX_TRANS_CFG_UART_RX_INSERT_STATUS_BIT_BMSK                                                      0x4
#define HWIO_UART_RX_TRANS_CFG_UART_RX_INSERT_STATUS_BIT_SHFT                                                        2
#define HWIO_UART_RX_TRANS_CFG_LM_UART_LOOPBACK_BMSK                                                               0x2
#define HWIO_UART_RX_TRANS_CFG_LM_UART_LOOPBACK_SHFT                                                                 1
#define HWIO_UART_RX_TRANS_CFG_LM_UART_EN_BMSK                                                                     0x1
#define HWIO_UART_RX_TRANS_CFG_LM_UART_EN_SHFT                                                                       0

#define HWIO_GENI_CFG_REG97_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x184)
#define HWIO_GENI_CFG_REG97_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x184)
#define HWIO_GENI_CFG_REG97_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x184)
#define HWIO_GENI_CFG_REG97_RMSK                                                                               0xfffff
#define HWIO_GENI_CFG_REG97_IN                    \
                in_dword(HWIO_GENI_CFG_REG97_ADDR)
#define HWIO_GENI_CFG_REG97_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG97_ADDR, m)
#define HWIO_GENI_CFG_REG97_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG97_ADDR,v)
#define HWIO_GENI_CFG_REG97_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG97_ADDR,m,v,HWIO_GENI_CFG_REG97_IN)
#define HWIO_GENI_CFG_REG97_VEC_1_START_INDEX_BMSK                                                             0xf8000
#define HWIO_GENI_CFG_REG97_VEC_1_START_INDEX_SHFT                                                                  15
#define HWIO_GENI_CFG_REG97_VEC_1_DIRECTION_BMSK                                                                0x4000
#define HWIO_GENI_CFG_REG97_VEC_1_DIRECTION_SHFT                                                                    14
#define HWIO_GENI_CFG_REG97_VEC_1_LENGTH_BMSK                                                                   0x3800
#define HWIO_GENI_CFG_REG97_VEC_1_LENGTH_SHFT                                                                       11
#define HWIO_GENI_CFG_REG97_VEC_1_STOP_BMSK                                                                      0x400
#define HWIO_GENI_CFG_REG97_VEC_1_STOP_SHFT                                                                         10
#define HWIO_GENI_CFG_REG97_VEC_0_START_INDEX_BMSK                                                               0x3e0
#define HWIO_GENI_CFG_REG97_VEC_0_START_INDEX_SHFT                                                                   5
#define HWIO_GENI_CFG_REG97_VEC_0_DIRECTION_BMSK                                                                  0x10
#define HWIO_GENI_CFG_REG97_VEC_0_DIRECTION_SHFT                                                                     4
#define HWIO_GENI_CFG_REG97_VEC_0_LENGTH_BMSK                                                                      0xe
#define HWIO_GENI_CFG_REG97_VEC_0_LENGTH_SHFT                                                                        1
#define HWIO_GENI_CFG_REG97_VEC_0_STOP_BMSK                                                                        0x1
#define HWIO_GENI_CFG_REG97_VEC_0_STOP_SHFT                                                                          0

#define HWIO_GENI_RX_PACKING_CFG0_ADDR                                                                      (GENI4_IMAGE_REGS_REG_BASE            + 0x184)
#define HWIO_GENI_RX_PACKING_CFG0_PHYS                                                                      (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x184)
#define HWIO_GENI_RX_PACKING_CFG0_OFFS                                                                      (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x184)
#define HWIO_GENI_RX_PACKING_CFG0_RMSK                                                                         0xfffff
#define HWIO_GENI_RX_PACKING_CFG0_IN                    \
                in_dword(HWIO_GENI_RX_PACKING_CFG0_ADDR)
#define HWIO_GENI_RX_PACKING_CFG0_INM(m)            \
                in_dword_masked(HWIO_GENI_RX_PACKING_CFG0_ADDR, m)
#define HWIO_GENI_RX_PACKING_CFG0_OUT(v)            \
                out_dword(HWIO_GENI_RX_PACKING_CFG0_ADDR,v)
#define HWIO_GENI_RX_PACKING_CFG0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_RX_PACKING_CFG0_ADDR,m,v,HWIO_GENI_RX_PACKING_CFG0_IN)
#define HWIO_GENI_RX_PACKING_CFG0_VEC_1_START_INDEX_BMSK                                                       0xf8000
#define HWIO_GENI_RX_PACKING_CFG0_VEC_1_START_INDEX_SHFT                                                            15
#define HWIO_GENI_RX_PACKING_CFG0_VEC_1_DIRECTION_BMSK                                                          0x4000
#define HWIO_GENI_RX_PACKING_CFG0_VEC_1_DIRECTION_SHFT                                                              14
#define HWIO_GENI_RX_PACKING_CFG0_VEC_1_LENGTH_BMSK                                                             0x3800
#define HWIO_GENI_RX_PACKING_CFG0_VEC_1_LENGTH_SHFT                                                                 11
#define HWIO_GENI_RX_PACKING_CFG0_VEC_1_STOP_BMSK                                                                0x400
#define HWIO_GENI_RX_PACKING_CFG0_VEC_1_STOP_SHFT                                                                   10
#define HWIO_GENI_RX_PACKING_CFG0_VEC_0_START_INDEX_BMSK                                                         0x3e0
#define HWIO_GENI_RX_PACKING_CFG0_VEC_0_START_INDEX_SHFT                                                             5
#define HWIO_GENI_RX_PACKING_CFG0_VEC_0_DIRECTION_BMSK                                                            0x10
#define HWIO_GENI_RX_PACKING_CFG0_VEC_0_DIRECTION_SHFT                                                               4
#define HWIO_GENI_RX_PACKING_CFG0_VEC_0_LENGTH_BMSK                                                                0xe
#define HWIO_GENI_RX_PACKING_CFG0_VEC_0_LENGTH_SHFT                                                                  1
#define HWIO_GENI_RX_PACKING_CFG0_VEC_0_STOP_BMSK                                                                  0x1
#define HWIO_GENI_RX_PACKING_CFG0_VEC_0_STOP_SHFT                                                                    0

#define HWIO_GENI_CFG_REG98_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x188)
#define HWIO_GENI_CFG_REG98_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x188)
#define HWIO_GENI_CFG_REG98_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x188)
#define HWIO_GENI_CFG_REG98_RMSK                                                                               0xfffff
#define HWIO_GENI_CFG_REG98_IN                    \
                in_dword(HWIO_GENI_CFG_REG98_ADDR)
#define HWIO_GENI_CFG_REG98_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG98_ADDR, m)
#define HWIO_GENI_CFG_REG98_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG98_ADDR,v)
#define HWIO_GENI_CFG_REG98_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG98_ADDR,m,v,HWIO_GENI_CFG_REG98_IN)
#define HWIO_GENI_CFG_REG98_VEC_3_START_INDEX_BMSK                                                             0xf8000
#define HWIO_GENI_CFG_REG98_VEC_3_START_INDEX_SHFT                                                                  15
#define HWIO_GENI_CFG_REG98_VEC_3_DIRECTION_BMSK                                                                0x4000
#define HWIO_GENI_CFG_REG98_VEC_3_DIRECTION_SHFT                                                                    14
#define HWIO_GENI_CFG_REG98_VEC_3_LENGTH_BMSK                                                                   0x3800
#define HWIO_GENI_CFG_REG98_VEC_3_LENGTH_SHFT                                                                       11
#define HWIO_GENI_CFG_REG98_VEC_3_STOP_BMSK                                                                      0x400
#define HWIO_GENI_CFG_REG98_VEC_3_STOP_SHFT                                                                         10
#define HWIO_GENI_CFG_REG98_VEC_2_START_INDEX_BMSK                                                               0x3e0
#define HWIO_GENI_CFG_REG98_VEC_2_START_INDEX_SHFT                                                                   5
#define HWIO_GENI_CFG_REG98_VEC_2_DIRECTION_BMSK                                                                  0x10
#define HWIO_GENI_CFG_REG98_VEC_2_DIRECTION_SHFT                                                                     4
#define HWIO_GENI_CFG_REG98_VEC_2_LENGTH_BMSK                                                                      0xe
#define HWIO_GENI_CFG_REG98_VEC_2_LENGTH_SHFT                                                                        1
#define HWIO_GENI_CFG_REG98_VEC_2_STOP_BMSK                                                                        0x1
#define HWIO_GENI_CFG_REG98_VEC_2_STOP_SHFT                                                                          0

#define HWIO_GENI_RX_PACKING_CFG1_ADDR                                                                      (GENI4_IMAGE_REGS_REG_BASE            + 0x188)
#define HWIO_GENI_RX_PACKING_CFG1_PHYS                                                                      (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x188)
#define HWIO_GENI_RX_PACKING_CFG1_OFFS                                                                      (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x188)
#define HWIO_GENI_RX_PACKING_CFG1_RMSK                                                                         0xfffff
#define HWIO_GENI_RX_PACKING_CFG1_IN                    \
                in_dword(HWIO_GENI_RX_PACKING_CFG1_ADDR)
#define HWIO_GENI_RX_PACKING_CFG1_INM(m)            \
                in_dword_masked(HWIO_GENI_RX_PACKING_CFG1_ADDR, m)
#define HWIO_GENI_RX_PACKING_CFG1_OUT(v)            \
                out_dword(HWIO_GENI_RX_PACKING_CFG1_ADDR,v)
#define HWIO_GENI_RX_PACKING_CFG1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_RX_PACKING_CFG1_ADDR,m,v,HWIO_GENI_RX_PACKING_CFG1_IN)
#define HWIO_GENI_RX_PACKING_CFG1_VEC_3_START_INDEX_BMSK                                                       0xf8000
#define HWIO_GENI_RX_PACKING_CFG1_VEC_3_START_INDEX_SHFT                                                            15
#define HWIO_GENI_RX_PACKING_CFG1_VEC_3_DIRECTION_BMSK                                                          0x4000
#define HWIO_GENI_RX_PACKING_CFG1_VEC_3_DIRECTION_SHFT                                                              14
#define HWIO_GENI_RX_PACKING_CFG1_VEC_3_LENGTH_BMSK                                                             0x3800
#define HWIO_GENI_RX_PACKING_CFG1_VEC_3_LENGTH_SHFT                                                                 11
#define HWIO_GENI_RX_PACKING_CFG1_VEC_3_STOP_BMSK                                                                0x400
#define HWIO_GENI_RX_PACKING_CFG1_VEC_3_STOP_SHFT                                                                   10
#define HWIO_GENI_RX_PACKING_CFG1_VEC_2_START_INDEX_BMSK                                                         0x3e0
#define HWIO_GENI_RX_PACKING_CFG1_VEC_2_START_INDEX_SHFT                                                             5
#define HWIO_GENI_RX_PACKING_CFG1_VEC_2_DIRECTION_BMSK                                                            0x10
#define HWIO_GENI_RX_PACKING_CFG1_VEC_2_DIRECTION_SHFT                                                               4
#define HWIO_GENI_RX_PACKING_CFG1_VEC_2_LENGTH_BMSK                                                                0xe
#define HWIO_GENI_RX_PACKING_CFG1_VEC_2_LENGTH_SHFT                                                                  1
#define HWIO_GENI_RX_PACKING_CFG1_VEC_2_STOP_BMSK                                                                  0x1
#define HWIO_GENI_RX_PACKING_CFG1_VEC_2_STOP_SHFT                                                                    0

#define HWIO_GENI_CFG_REG99_ADDR                                                                            (GENI4_IMAGE_REGS_REG_BASE            + 0x18c)
#define HWIO_GENI_CFG_REG99_PHYS                                                                            (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x18c)
#define HWIO_GENI_CFG_REG99_OFFS                                                                            (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x18c)
#define HWIO_GENI_CFG_REG99_RMSK                                                                                 0x3ff
#define HWIO_GENI_CFG_REG99_IN                    \
                in_dword(HWIO_GENI_CFG_REG99_ADDR)
#define HWIO_GENI_CFG_REG99_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG99_ADDR, m)
#define HWIO_GENI_CFG_REG99_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG99_ADDR,v)
#define HWIO_GENI_CFG_REG99_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG99_ADDR,m,v,HWIO_GENI_CFG_REG99_IN)
#define HWIO_GENI_CFG_REG99_S_GP_CNT0_BMSK                                                                       0x3ff
#define HWIO_GENI_CFG_REG99_S_GP_CNT0_SHFT                                                                           0

#define HWIO_UART_RX_WORD_LEN_ADDR                                                                          (GENI4_IMAGE_REGS_REG_BASE            + 0x18c)
#define HWIO_UART_RX_WORD_LEN_PHYS                                                                          (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x18c)
#define HWIO_UART_RX_WORD_LEN_OFFS                                                                          (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x18c)
#define HWIO_UART_RX_WORD_LEN_RMSK                                                                               0x3ff
#define HWIO_UART_RX_WORD_LEN_IN                    \
                in_dword(HWIO_UART_RX_WORD_LEN_ADDR)
#define HWIO_UART_RX_WORD_LEN_INM(m)            \
                in_dword_masked(HWIO_UART_RX_WORD_LEN_ADDR, m)
#define HWIO_UART_RX_WORD_LEN_OUT(v)            \
                out_dword(HWIO_UART_RX_WORD_LEN_ADDR,v)
#define HWIO_UART_RX_WORD_LEN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_UART_RX_WORD_LEN_ADDR,m,v,HWIO_UART_RX_WORD_LEN_IN)
#define HWIO_UART_RX_WORD_LEN_UART_RX_WORD_LEN_BMSK                                                              0x3ff
#define HWIO_UART_RX_WORD_LEN_UART_RX_WORD_LEN_SHFT                                                                  0

#define HWIO_GENI_CFG_REG100_ADDR                                                                           (GENI4_IMAGE_REGS_REG_BASE            + 0x190)
#define HWIO_GENI_CFG_REG100_PHYS                                                                           (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x190)
#define HWIO_GENI_CFG_REG100_OFFS                                                                           (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x190)
#define HWIO_GENI_CFG_REG100_RMSK                                                                             0xffffff
#define HWIO_GENI_CFG_REG100_IN                    \
                in_dword(HWIO_GENI_CFG_REG100_ADDR)
#define HWIO_GENI_CFG_REG100_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG100_ADDR, m)
#define HWIO_GENI_CFG_REG100_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG100_ADDR,v)
#define HWIO_GENI_CFG_REG100_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG100_ADDR,m,v,HWIO_GENI_CFG_REG100_IN)
#define HWIO_GENI_CFG_REG100_S_GP_CNT1_BMSK                                                                   0xffffff
#define HWIO_GENI_CFG_REG100_S_GP_CNT1_SHFT                                                                          0

#define HWIO_LM_UART_S_GP_CNT_ADDR                                                                          (GENI4_IMAGE_REGS_REG_BASE            + 0x190)
#define HWIO_LM_UART_S_GP_CNT_PHYS                                                                          (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x190)
#define HWIO_LM_UART_S_GP_CNT_OFFS                                                                          (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x190)
#define HWIO_LM_UART_S_GP_CNT_RMSK                                                                            0xffffff
#define HWIO_LM_UART_S_GP_CNT_IN                    \
                in_dword(HWIO_LM_UART_S_GP_CNT_ADDR)
#define HWIO_LM_UART_S_GP_CNT_INM(m)            \
                in_dword_masked(HWIO_LM_UART_S_GP_CNT_ADDR, m)
#define HWIO_LM_UART_S_GP_CNT_OUT(v)            \
                out_dword(HWIO_LM_UART_S_GP_CNT_ADDR,v)
#define HWIO_LM_UART_S_GP_CNT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_LM_UART_S_GP_CNT_ADDR,m,v,HWIO_LM_UART_S_GP_CNT_IN)
#define HWIO_LM_UART_S_GP_CNT_S_GP_CNT1_BMSK                                                                  0xffffff
#define HWIO_LM_UART_S_GP_CNT_S_GP_CNT1_SHFT                                                                         0

#define HWIO_GENI_CFG_REG101_ADDR                                                                           (GENI4_IMAGE_REGS_REG_BASE            + 0x194)
#define HWIO_GENI_CFG_REG101_PHYS                                                                           (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x194)
#define HWIO_GENI_CFG_REG101_OFFS                                                                           (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x194)
#define HWIO_GENI_CFG_REG101_RMSK                                                                             0xffffff
#define HWIO_GENI_CFG_REG101_IN                    \
                in_dword(HWIO_GENI_CFG_REG101_ADDR)
#define HWIO_GENI_CFG_REG101_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG101_ADDR, m)
#define HWIO_GENI_CFG_REG101_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG101_ADDR,v)
#define HWIO_GENI_CFG_REG101_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG101_ADDR,m,v,HWIO_GENI_CFG_REG101_IN)
#define HWIO_GENI_CFG_REG101_S_GP_CNT2_BMSK                                                                   0xffffff
#define HWIO_GENI_CFG_REG101_S_GP_CNT2_SHFT                                                                          0

#define HWIO_UART_RX_STALE_CNT_ADDR                                                                         (GENI4_IMAGE_REGS_REG_BASE            + 0x194)
#define HWIO_UART_RX_STALE_CNT_PHYS                                                                         (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x194)
#define HWIO_UART_RX_STALE_CNT_OFFS                                                                         (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x194)
#define HWIO_UART_RX_STALE_CNT_RMSK                                                                           0xffffff
#define HWIO_UART_RX_STALE_CNT_IN                    \
                in_dword(HWIO_UART_RX_STALE_CNT_ADDR)
#define HWIO_UART_RX_STALE_CNT_INM(m)            \
                in_dword_masked(HWIO_UART_RX_STALE_CNT_ADDR, m)
#define HWIO_UART_RX_STALE_CNT_OUT(v)            \
                out_dword(HWIO_UART_RX_STALE_CNT_ADDR,v)
#define HWIO_UART_RX_STALE_CNT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_UART_RX_STALE_CNT_ADDR,m,v,HWIO_UART_RX_STALE_CNT_IN)
#define HWIO_UART_RX_STALE_CNT_UART_RX_STALE_CNT_BMSK                                                         0xffffff
#define HWIO_UART_RX_STALE_CNT_UART_RX_STALE_CNT_SHFT                                                                0

#define HWIO_GENI_CFG_REG102_ADDR                                                                           (GENI4_IMAGE_REGS_REG_BASE            + 0x198)
#define HWIO_GENI_CFG_REG102_PHYS                                                                           (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x198)
#define HWIO_GENI_CFG_REG102_OFFS                                                                           (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x198)
#define HWIO_GENI_CFG_REG102_RMSK                                                                             0xffffff
#define HWIO_GENI_CFG_REG102_IN                    \
                in_dword(HWIO_GENI_CFG_REG102_ADDR)
#define HWIO_GENI_CFG_REG102_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG102_ADDR, m)
#define HWIO_GENI_CFG_REG102_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG102_ADDR,v)
#define HWIO_GENI_CFG_REG102_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG102_ADDR,m,v,HWIO_GENI_CFG_REG102_IN)
#define HWIO_GENI_CFG_REG102_S_GP_CNT3_BMSK                                                                   0xffffff
#define HWIO_GENI_CFG_REG102_S_GP_CNT3_SHFT                                                                          0

#define HWIO_GENI_CFG_REG103_ADDR                                                                           (GENI4_IMAGE_REGS_REG_BASE            + 0x19c)
#define HWIO_GENI_CFG_REG103_PHYS                                                                           (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x19c)
#define HWIO_GENI_CFG_REG103_OFFS                                                                           (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x19c)
#define HWIO_GENI_CFG_REG103_RMSK                                                                           0x3fffffff
#define HWIO_GENI_CFG_REG103_IN                    \
                in_dword(HWIO_GENI_CFG_REG103_ADDR)
#define HWIO_GENI_CFG_REG103_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG103_ADDR, m)
#define HWIO_GENI_CFG_REG103_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG103_ADDR,v)
#define HWIO_GENI_CFG_REG103_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG103_ADDR,m,v,HWIO_GENI_CFG_REG103_IN)
#define HWIO_GENI_CFG_REG103_S_GP_CNT6_BMSK                                                                 0x3ff00000
#define HWIO_GENI_CFG_REG103_S_GP_CNT6_SHFT                                                                         20
#define HWIO_GENI_CFG_REG103_S_GP_CNT5_BMSK                                                                    0xffc00
#define HWIO_GENI_CFG_REG103_S_GP_CNT5_SHFT                                                                         10
#define HWIO_GENI_CFG_REG103_S_GP_CNT4_BMSK                                                                      0x3ff
#define HWIO_GENI_CFG_REG103_S_GP_CNT4_SHFT                                                                          0

#define HWIO_GENI_CFG_REG104_ADDR                                                                           (GENI4_IMAGE_REGS_REG_BASE            + 0x1a0)
#define HWIO_GENI_CFG_REG104_PHYS                                                                           (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x1a0)
#define HWIO_GENI_CFG_REG104_OFFS                                                                           (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x1a0)
#define HWIO_GENI_CFG_REG104_RMSK                                                                                0x3ff
#define HWIO_GENI_CFG_REG104_IN                    \
                in_dword(HWIO_GENI_CFG_REG104_ADDR)
#define HWIO_GENI_CFG_REG104_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG104_ADDR, m)
#define HWIO_GENI_CFG_REG104_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG104_ADDR,v)
#define HWIO_GENI_CFG_REG104_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG104_ADDR,m,v,HWIO_GENI_CFG_REG104_IN)
#define HWIO_GENI_CFG_REG104_S_GP_CNT7_BMSK                                                                      0x3ff
#define HWIO_GENI_CFG_REG104_S_GP_CNT7_SHFT                                                                          0

#define HWIO_GENI_CFG_REG105_ADDR                                                                           (GENI4_IMAGE_REGS_REG_BASE            + 0x1a4)
#define HWIO_GENI_CFG_REG105_PHYS                                                                           (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x1a4)
#define HWIO_GENI_CFG_REG105_OFFS                                                                           (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x1a4)
#define HWIO_GENI_CFG_REG105_RMSK                                                                              0x3ffff
#define HWIO_GENI_CFG_REG105_IN                    \
                in_dword(HWIO_GENI_CFG_REG105_ADDR)
#define HWIO_GENI_CFG_REG105_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG105_ADDR, m)
#define HWIO_GENI_CFG_REG105_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG105_ADDR,v)
#define HWIO_GENI_CFG_REG105_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG105_ADDR,m,v,HWIO_GENI_CFG_REG105_IN)
#define HWIO_GENI_CFG_REG105_TX_CONST1_BIT_STUFF_EN_BMSK                                                       0x20000
#define HWIO_GENI_CFG_REG105_TX_CONST1_BIT_STUFF_EN_SHFT                                                            17
#define HWIO_GENI_CFG_REG105_TX_CRC_BIT_STUFF_EN_BMSK                                                          0x10000
#define HWIO_GENI_CFG_REG105_TX_CRC_BIT_STUFF_EN_SHFT                                                               16
#define HWIO_GENI_CFG_REG105_TX_FIFO_BIT_STUFF_EN_BMSK                                                          0x8000
#define HWIO_GENI_CFG_REG105_TX_FIFO_BIT_STUFF_EN_SHFT                                                              15
#define HWIO_GENI_CFG_REG105_TX_FIFO_DUMMY_BIT_STUFF_EN_BMSK                                                    0x4000
#define HWIO_GENI_CFG_REG105_TX_FIFO_DUMMY_BIT_STUFF_EN_SHFT                                                        14
#define HWIO_GENI_CFG_REG105_TX_PARAM_BIT_STUFF_EN_BMSK                                                         0x2000
#define HWIO_GENI_CFG_REG105_TX_PARAM_BIT_STUFF_EN_SHFT                                                             13
#define HWIO_GENI_CFG_REG105_TX_PARAM_DUMMY_BIT_STUFF_EN_BMSK                                                   0x1000
#define HWIO_GENI_CFG_REG105_TX_PARAM_DUMMY_BIT_STUFF_EN_SHFT                                                       12
#define HWIO_GENI_CFG_REG105_TX_LOAD_BIT_STUFF_EN_BMSK                                                           0x800
#define HWIO_GENI_CFG_REG105_TX_LOAD_BIT_STUFF_EN_SHFT                                                              11
#define HWIO_GENI_CFG_REG105_TX_BIT_STUFF_HIGH_DETECT_EN_BMSK                                                    0x400
#define HWIO_GENI_CFG_REG105_TX_BIT_STUFF_HIGH_DETECT_EN_SHFT                                                       10
#define HWIO_GENI_CFG_REG105_TX_BIT_STUFF_LOW_DETECT_EN_BMSK                                                     0x200
#define HWIO_GENI_CFG_REG105_TX_BIT_STUFF_LOW_DETECT_EN_SHFT                                                         9
#define HWIO_GENI_CFG_REG105_TX_BIT_STUFF_DETECT_NUM_BITS_BMSK                                                   0x1e0
#define HWIO_GENI_CFG_REG105_TX_BIT_STUFF_DETECT_NUM_BITS_SHFT                                                       5
#define HWIO_GENI_CFG_REG105_TX_PARITY_TOGGLE_EN_BMSK                                                             0x10
#define HWIO_GENI_CFG_REG105_TX_PARITY_TOGGLE_EN_SHFT                                                                4
#define HWIO_GENI_CFG_REG105_TX_FW_PAR_SEL_BMSK                                                                    0x8
#define HWIO_GENI_CFG_REG105_TX_FW_PAR_SEL_SHFT                                                                      3
#define HWIO_GENI_CFG_REG105_TX_PAR_MODE_BMSK                                                                      0x6
#define HWIO_GENI_CFG_REG105_TX_PAR_MODE_SHFT                                                                        1
#define HWIO_GENI_CFG_REG105_TX_PAR_CALC_EN_BMSK                                                                   0x1
#define HWIO_GENI_CFG_REG105_TX_PAR_CALC_EN_SHFT                                                                     0

#define HWIO_UART_TX_PARITY_CFG_ADDR                                                                        (GENI4_IMAGE_REGS_REG_BASE            + 0x1a4)
#define HWIO_UART_TX_PARITY_CFG_PHYS                                                                        (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x1a4)
#define HWIO_UART_TX_PARITY_CFG_OFFS                                                                        (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x1a4)
#define HWIO_UART_TX_PARITY_CFG_RMSK                                                                               0x7
#define HWIO_UART_TX_PARITY_CFG_IN                    \
                in_dword(HWIO_UART_TX_PARITY_CFG_ADDR)
#define HWIO_UART_TX_PARITY_CFG_INM(m)            \
                in_dword_masked(HWIO_UART_TX_PARITY_CFG_ADDR, m)
#define HWIO_UART_TX_PARITY_CFG_OUT(v)            \
                out_dword(HWIO_UART_TX_PARITY_CFG_ADDR,v)
#define HWIO_UART_TX_PARITY_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_UART_TX_PARITY_CFG_ADDR,m,v,HWIO_UART_TX_PARITY_CFG_IN)
#define HWIO_UART_TX_PARITY_CFG_TX_PAR_MODE_BMSK                                                                   0x6
#define HWIO_UART_TX_PARITY_CFG_TX_PAR_MODE_SHFT                                                                     1
#define HWIO_UART_TX_PARITY_CFG_TX_PAR_CALC_EN_BMSK                                                                0x1
#define HWIO_UART_TX_PARITY_CFG_TX_PAR_CALC_EN_SHFT                                                                  0

#define HWIO_GENI_CFG_REG106_ADDR                                                                           (GENI4_IMAGE_REGS_REG_BASE            + 0x1a8)
#define HWIO_GENI_CFG_REG106_PHYS                                                                           (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x1a8)
#define HWIO_GENI_CFG_REG106_OFFS                                                                           (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x1a8)
#define HWIO_GENI_CFG_REG106_RMSK                                                                                0x7ff
#define HWIO_GENI_CFG_REG106_IN                    \
                in_dword(HWIO_GENI_CFG_REG106_ADDR)
#define HWIO_GENI_CFG_REG106_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG106_ADDR, m)
#define HWIO_GENI_CFG_REG106_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG106_ADDR,v)
#define HWIO_GENI_CFG_REG106_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG106_ADDR,m,v,HWIO_GENI_CFG_REG106_IN)
#define HWIO_GENI_CFG_REG106_RX_BIT_STUFF_HIGH_DETECT_EN_BMSK                                                    0x400
#define HWIO_GENI_CFG_REG106_RX_BIT_STUFF_HIGH_DETECT_EN_SHFT                                                       10
#define HWIO_GENI_CFG_REG106_RX_BIT_STUFF_LOW_DETECT_EN_BMSK                                                     0x200
#define HWIO_GENI_CFG_REG106_RX_BIT_STUFF_LOW_DETECT_EN_SHFT                                                         9
#define HWIO_GENI_CFG_REG106_RX_BIT_STUFF_DETECT_NUM_BITS_BMSK                                                   0x1e0
#define HWIO_GENI_CFG_REG106_RX_BIT_STUFF_DETECT_NUM_BITS_SHFT                                                       5
#define HWIO_GENI_CFG_REG106_RX_PARITY_TOGGLE_EN_BMSK                                                             0x10
#define HWIO_GENI_CFG_REG106_RX_PARITY_TOGGLE_EN_SHFT                                                                4
#define HWIO_GENI_CFG_REG106_RX_FW_PAR_SEL_BMSK                                                                    0x8
#define HWIO_GENI_CFG_REG106_RX_FW_PAR_SEL_SHFT                                                                      3
#define HWIO_GENI_CFG_REG106_RX_PAR_MODE_BMSK                                                                      0x6
#define HWIO_GENI_CFG_REG106_RX_PAR_MODE_SHFT                                                                        1
#define HWIO_GENI_CFG_REG106_RX_PAR_CALC_EN_BMSK                                                                   0x1
#define HWIO_GENI_CFG_REG106_RX_PAR_CALC_EN_SHFT                                                                     0

#define HWIO_UART_RX_PARITY_CFG_ADDR                                                                        (GENI4_IMAGE_REGS_REG_BASE            + 0x1a8)
#define HWIO_UART_RX_PARITY_CFG_PHYS                                                                        (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x1a8)
#define HWIO_UART_RX_PARITY_CFG_OFFS                                                                        (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x1a8)
#define HWIO_UART_RX_PARITY_CFG_RMSK                                                                               0x7
#define HWIO_UART_RX_PARITY_CFG_IN                    \
                in_dword(HWIO_UART_RX_PARITY_CFG_ADDR)
#define HWIO_UART_RX_PARITY_CFG_INM(m)            \
                in_dword_masked(HWIO_UART_RX_PARITY_CFG_ADDR, m)
#define HWIO_UART_RX_PARITY_CFG_OUT(v)            \
                out_dword(HWIO_UART_RX_PARITY_CFG_ADDR,v)
#define HWIO_UART_RX_PARITY_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_UART_RX_PARITY_CFG_ADDR,m,v,HWIO_UART_RX_PARITY_CFG_IN)
#define HWIO_UART_RX_PARITY_CFG_RX_PAR_MODE_BMSK                                                                   0x6
#define HWIO_UART_RX_PARITY_CFG_RX_PAR_MODE_SHFT                                                                     1
#define HWIO_UART_RX_PARITY_CFG_RX_PAR_CALC_EN_BMSK                                                                0x1
#define HWIO_UART_RX_PARITY_CFG_RX_PAR_CALC_EN_SHFT                                                                  0

#define HWIO_GENI_CFG_REG107_ADDR                                                                           (GENI4_IMAGE_REGS_REG_BASE            + 0x1ac)
#define HWIO_GENI_CFG_REG107_PHYS                                                                           (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x1ac)
#define HWIO_GENI_CFG_REG107_OFFS                                                                           (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x1ac)
#define HWIO_GENI_CFG_REG107_RMSK                                                                           0x80000003
#define HWIO_GENI_CFG_REG107_IN                    \
                in_dword(HWIO_GENI_CFG_REG107_ADDR)
#define HWIO_GENI_CFG_REG107_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG107_ADDR, m)
#define HWIO_GENI_CFG_REG107_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG107_ADDR,v)
#define HWIO_GENI_CFG_REG107_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG107_ADDR,m,v,HWIO_GENI_CFG_REG107_IN)
#define HWIO_GENI_CFG_REG107_IO3_SW_CONTROL_BMSK                                                            0x80000000
#define HWIO_GENI_CFG_REG107_IO3_SW_CONTROL_SHFT                                                                    31
#define HWIO_GENI_CFG_REG107_IO3_FORCE_HIGH_BMSK                                                                   0x2
#define HWIO_GENI_CFG_REG107_IO3_FORCE_HIGH_SHFT                                                                     1
#define HWIO_GENI_CFG_REG107_IO3_FORCE_LOW_BMSK                                                                    0x1
#define HWIO_GENI_CFG_REG107_IO3_FORCE_LOW_SHFT                                                                      0

#define HWIO_UART_MANUAL_RFR_ADDR                                                                           (GENI4_IMAGE_REGS_REG_BASE            + 0x1ac)
#define HWIO_UART_MANUAL_RFR_PHYS                                                                           (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x1ac)
#define HWIO_UART_MANUAL_RFR_OFFS                                                                           (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x1ac)
#define HWIO_UART_MANUAL_RFR_RMSK                                                                           0x80000003
#define HWIO_UART_MANUAL_RFR_IN                    \
                in_dword(HWIO_UART_MANUAL_RFR_ADDR)
#define HWIO_UART_MANUAL_RFR_INM(m)            \
                in_dword_masked(HWIO_UART_MANUAL_RFR_ADDR, m)
#define HWIO_UART_MANUAL_RFR_OUT(v)            \
                out_dword(HWIO_UART_MANUAL_RFR_ADDR,v)
#define HWIO_UART_MANUAL_RFR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_UART_MANUAL_RFR_ADDR,m,v,HWIO_UART_MANUAL_RFR_IN)
#define HWIO_UART_MANUAL_RFR_UART_MANUAL_RFR_EN_BMSK                                                        0x80000000
#define HWIO_UART_MANUAL_RFR_UART_MANUAL_RFR_EN_SHFT                                                                31
#define HWIO_UART_MANUAL_RFR_UART_RFR_NOT_READY_BMSK                                                               0x2
#define HWIO_UART_MANUAL_RFR_UART_RFR_NOT_READY_SHFT                                                                 1
#define HWIO_UART_MANUAL_RFR_UART_RFR_READY_BMSK                                                                   0x1
#define HWIO_UART_MANUAL_RFR_UART_RFR_READY_SHFT                                                                     0

#define HWIO_GENI_CFG_REG108_ADDR                                                                           (GENI4_IMAGE_REGS_REG_BASE            + 0x1b0)
#define HWIO_GENI_CFG_REG108_PHYS                                                                           (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x1b0)
#define HWIO_GENI_CFG_REG108_OFFS                                                                           (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x1b0)
#define HWIO_GENI_CFG_REG108_RMSK                                                                           0x7fff773f
#define HWIO_GENI_CFG_REG108_IN                    \
                in_dword(HWIO_GENI_CFG_REG108_ADDR)
#define HWIO_GENI_CFG_REG108_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG108_ADDR, m)
#define HWIO_GENI_CFG_REG108_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG108_ADDR,v)
#define HWIO_GENI_CFG_REG108_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG108_ADDR,m,v,HWIO_GENI_CFG_REG108_IN)
#define HWIO_GENI_CFG_REG108_RX_MAIN_SIN_NEG_SEL_BMSK                                                       0x40000000
#define HWIO_GENI_CFG_REG108_RX_MAIN_SIN_NEG_SEL_SHFT                                                               30
#define HWIO_GENI_CFG_REG108_RX_MAIN_SIN_MUXED_POS_SEL_BMSK                                                 0x20000000
#define HWIO_GENI_CFG_REG108_RX_MAIN_SIN_MUXED_POS_SEL_SHFT                                                         29
#define HWIO_GENI_CFG_REG108_RX_MAIN_SIN_POS_SEL_BMSK                                                       0x10000000
#define HWIO_GENI_CFG_REG108_RX_MAIN_SIN_POS_SEL_SHFT                                                               28
#define HWIO_GENI_CFG_REG108_TX_SOE_SOUT_POS_SEL_BMSK                                                        0x8000000
#define HWIO_GENI_CFG_REG108_TX_SOE_SOUT_POS_SEL_SHFT                                                               27
#define HWIO_GENI_CFG_REG108_CLK_GEN_OUTPUT_SEL_BMSK                                                         0x4000000
#define HWIO_GENI_CFG_REG108_CLK_GEN_OUTPUT_SEL_SHFT                                                                26
#define HWIO_GENI_CFG_REG108_IO2_SIN_DATA_DLY_BMSK                                                           0x3c00000
#define HWIO_GENI_CFG_REG108_IO2_SIN_DATA_DLY_SHFT                                                                  22
#define HWIO_GENI_CFG_REG108_SB_PIPE_SEL_BMSK                                                                 0x300000
#define HWIO_GENI_CFG_REG108_SB_PIPE_SEL_SHFT                                                                       20
#define HWIO_GENI_CFG_REG108_CLK_GEN_PIPE_SEL_BMSK                                                             0xc0000
#define HWIO_GENI_CFG_REG108_CLK_GEN_PIPE_SEL_SHFT                                                                  18
#define HWIO_GENI_CFG_REG108_TX_PIPE_SEL_BMSK                                                                  0x30000
#define HWIO_GENI_CFG_REG108_TX_PIPE_SEL_SHFT                                                                       16
#define HWIO_GENI_CFG_REG108_RX_SI_EN2IO_DELAY_BMSK                                                             0x7000
#define HWIO_GENI_CFG_REG108_RX_SI_EN2IO_DELAY_SHFT                                                                 12
#define HWIO_GENI_CFG_REG108_RX_IO_EN2CORE_EN_DELAY_BMSK                                                         0x700
#define HWIO_GENI_CFG_REG108_RX_IO_EN2CORE_EN_DELAY_SHFT                                                             8
#define HWIO_GENI_CFG_REG108_RX_POS_FF_EN_SEL_BMSK                                                                0x20
#define HWIO_GENI_CFG_REG108_RX_POS_FF_EN_SEL_SHFT                                                                   5
#define HWIO_GENI_CFG_REG108_RX_IO_POS_FF_EN_SEL_BMSK                                                             0x10
#define HWIO_GENI_CFG_REG108_RX_IO_POS_FF_EN_SEL_SHFT                                                                4
#define HWIO_GENI_CFG_REG108_RX_IO_INT_CLK_SAMP_EN_BMSK                                                            0x8
#define HWIO_GENI_CFG_REG108_RX_IO_INT_CLK_SAMP_EN_SHFT                                                              3
#define HWIO_GENI_CFG_REG108_RX_IO_PIPE_STAGE_SEL_BMSK                                                             0x4
#define HWIO_GENI_CFG_REG108_RX_IO_PIPE_STAGE_SEL_SHFT                                                               2
#define HWIO_GENI_CFG_REG108_CPOL_CTRL_BMSK                                                                        0x2
#define HWIO_GENI_CFG_REG108_CPOL_CTRL_SHFT                                                                          1
#define HWIO_GENI_CFG_REG108_CPHA_CTRL_BMSK                                                                        0x1
#define HWIO_GENI_CFG_REG108_CPHA_CTRL_SHFT                                                                          0

#define HWIO_GENI_CFG_REG108_SHARED_ADDR                                                                    (GENI4_IMAGE_REGS_REG_BASE            + 0x1b0)
#define HWIO_GENI_CFG_REG108_SHARED_PHYS                                                                    (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x1b0)
#define HWIO_GENI_CFG_REG108_SHARED_OFFS                                                                    (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x1b0)
#define HWIO_GENI_CFG_REG108_SHARED_RMSK                                                                     0x3ff773f
#define HWIO_GENI_CFG_REG108_SHARED_IN                    \
                in_dword(HWIO_GENI_CFG_REG108_SHARED_ADDR)
#define HWIO_GENI_CFG_REG108_SHARED_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG108_SHARED_ADDR, m)
#define HWIO_GENI_CFG_REG108_SHARED_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG108_SHARED_ADDR,v)
#define HWIO_GENI_CFG_REG108_SHARED_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG108_SHARED_ADDR,m,v,HWIO_GENI_CFG_REG108_SHARED_IN)
#define HWIO_GENI_CFG_REG108_SHARED_IO2_SIN_DATA_DLY_BMSK                                                    0x3c00000
#define HWIO_GENI_CFG_REG108_SHARED_IO2_SIN_DATA_DLY_SHFT                                                           22
#define HWIO_GENI_CFG_REG108_SHARED_SB_PIPE_SEL_BMSK                                                          0x300000
#define HWIO_GENI_CFG_REG108_SHARED_SB_PIPE_SEL_SHFT                                                                20
#define HWIO_GENI_CFG_REG108_SHARED_CLK_GEN_PIPE_SEL_BMSK                                                      0xc0000
#define HWIO_GENI_CFG_REG108_SHARED_CLK_GEN_PIPE_SEL_SHFT                                                           18
#define HWIO_GENI_CFG_REG108_SHARED_TX_PIPE_SEL_BMSK                                                           0x30000
#define HWIO_GENI_CFG_REG108_SHARED_TX_PIPE_SEL_SHFT                                                                16
#define HWIO_GENI_CFG_REG108_SHARED_RX_SI_EN2IO_DELAY_BMSK                                                      0x7000
#define HWIO_GENI_CFG_REG108_SHARED_RX_SI_EN2IO_DELAY_SHFT                                                          12
#define HWIO_GENI_CFG_REG108_SHARED_RX_IO_EN2CORE_EN_DELAY_BMSK                                                  0x700
#define HWIO_GENI_CFG_REG108_SHARED_RX_IO_EN2CORE_EN_DELAY_SHFT                                                      8
#define HWIO_GENI_CFG_REG108_SHARED_RX_POS_FF_EN_SEL_BMSK                                                         0x20
#define HWIO_GENI_CFG_REG108_SHARED_RX_POS_FF_EN_SEL_SHFT                                                            5
#define HWIO_GENI_CFG_REG108_SHARED_RX_IO_POS_FF_EN_SEL_BMSK                                                      0x10
#define HWIO_GENI_CFG_REG108_SHARED_RX_IO_POS_FF_EN_SEL_SHFT                                                         4
#define HWIO_GENI_CFG_REG108_SHARED_RX_IO_INT_CLK_SAMP_EN_BMSK                                                     0x8
#define HWIO_GENI_CFG_REG108_SHARED_RX_IO_INT_CLK_SAMP_EN_SHFT                                                       3
#define HWIO_GENI_CFG_REG108_SHARED_RX_IO_PIPE_STAGE_SEL_BMSK                                                      0x4
#define HWIO_GENI_CFG_REG108_SHARED_RX_IO_PIPE_STAGE_SEL_SHFT                                                        2
#define HWIO_GENI_CFG_REG108_SHARED_CPOL_CTRL_BMSK                                                                 0x2
#define HWIO_GENI_CFG_REG108_SHARED_CPOL_CTRL_SHFT                                                                   1
#define HWIO_GENI_CFG_REG108_SHARED_CPHA_CTRL_BMSK                                                                 0x1
#define HWIO_GENI_CFG_REG108_SHARED_CPHA_CTRL_SHFT                                                                   0

#define HWIO_GENI_CFG_REG109_ADDR                                                                           (GENI4_IMAGE_REGS_REG_BASE            + 0x1b4)
#define HWIO_GENI_CFG_REG109_PHYS                                                                           (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x1b4)
#define HWIO_GENI_CFG_REG109_OFFS                                                                           (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x1b4)
#define HWIO_GENI_CFG_REG109_RMSK                                                                                  0x1
#define HWIO_GENI_CFG_REG109_IN                    \
                in_dword(HWIO_GENI_CFG_REG109_ADDR)
#define HWIO_GENI_CFG_REG109_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG109_ADDR, m)
#define HWIO_GENI_CFG_REG109_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG109_ADDR,v)
#define HWIO_GENI_CFG_REG109_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG109_ADDR,m,v,HWIO_GENI_CFG_REG109_IN)
#define HWIO_GENI_CFG_REG109_RX_CPOL_BMSK                                                                          0x1
#define HWIO_GENI_CFG_REG109_RX_CPOL_SHFT                                                                            0

#define HWIO_GENI_CFG_REG110_ADDR                                                                           (GENI4_IMAGE_REGS_REG_BASE            + 0x1b8)
#define HWIO_GENI_CFG_REG110_PHYS                                                                           (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x1b8)
#define HWIO_GENI_CFG_REG110_OFFS                                                                           (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x1b8)
#define HWIO_GENI_CFG_REG110_RMSK                                                                               0x7ff7
#define HWIO_GENI_CFG_REG110_IN                    \
                in_dword(HWIO_GENI_CFG_REG110_ADDR)
#define HWIO_GENI_CFG_REG110_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG110_ADDR, m)
#define HWIO_GENI_CFG_REG110_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG110_ADDR,v)
#define HWIO_GENI_CFG_REG110_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG110_ADDR,m,v,HWIO_GENI_CFG_REG110_IN)
#define HWIO_GENI_CFG_REG110_GENI_CRC_NEXT0_MUX_SEL_BMSK                                                        0x7000
#define HWIO_GENI_CFG_REG110_GENI_CRC_NEXT0_MUX_SEL_SHFT                                                            12
#define HWIO_GENI_CFG_REG110_GENI_CRC_POLY_EN_BMSK                                                               0xff0
#define HWIO_GENI_CFG_REG110_GENI_CRC_POLY_EN_SHFT                                                                   4
#define HWIO_GENI_CFG_REG110_GENI_CRC_POLY_MAX_BMSK                                                                0x7
#define HWIO_GENI_CFG_REG110_GENI_CRC_POLY_MAX_SHFT                                                                  0

#define HWIO_GENI_CFG_REG111_ADDR                                                                           (GENI4_IMAGE_REGS_REG_BASE            + 0x1bc)
#define HWIO_GENI_CFG_REG111_PHYS                                                                           (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x1bc)
#define HWIO_GENI_CFG_REG111_OFFS                                                                           (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x1bc)
#define HWIO_GENI_CFG_REG111_RMSK                                                                                  0x1
#define HWIO_GENI_CFG_REG111_IN                    \
                in_dword(HWIO_GENI_CFG_REG111_ADDR)
#define HWIO_GENI_CFG_REG111_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG111_ADDR, m)
#define HWIO_GENI_CFG_REG111_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG111_ADDR,v)
#define HWIO_GENI_CFG_REG111_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG111_ADDR,m,v,HWIO_GENI_CFG_REG111_IN)
#define HWIO_GENI_CFG_REG111_SPI_SLAVE_EN_BMSK                                                                     0x1
#define HWIO_GENI_CFG_REG111_SPI_SLAVE_EN_SHFT                                                                       0

#define HWIO_SPI_SLAVE_EN_ADDR                                                                              (GENI4_IMAGE_REGS_REG_BASE            + 0x1bc)
#define HWIO_SPI_SLAVE_EN_PHYS                                                                              (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x1bc)
#define HWIO_SPI_SLAVE_EN_OFFS                                                                              (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x1bc)
#define HWIO_SPI_SLAVE_EN_RMSK                                                                                     0x1
#define HWIO_SPI_SLAVE_EN_IN                    \
                in_dword(HWIO_SPI_SLAVE_EN_ADDR)
#define HWIO_SPI_SLAVE_EN_INM(m)            \
                in_dword_masked(HWIO_SPI_SLAVE_EN_ADDR, m)
#define HWIO_SPI_SLAVE_EN_OUT(v)            \
                out_dword(HWIO_SPI_SLAVE_EN_ADDR,v)
#define HWIO_SPI_SLAVE_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SPI_SLAVE_EN_ADDR,m,v,HWIO_SPI_SLAVE_EN_IN)
#define HWIO_SPI_SLAVE_EN_SPI_SLAVE_EN_BMSK                                                                        0x1
#define HWIO_SPI_SLAVE_EN_SPI_SLAVE_EN_SHFT                                                                          0

#define HWIO_GENI_CFG_REG112_ADDR                                                                           (GENI4_IMAGE_REGS_REG_BASE            + 0x1c0)
#define HWIO_GENI_CFG_REG112_PHYS                                                                           (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x1c0)
#define HWIO_GENI_CFG_REG112_OFFS                                                                           (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x1c0)
#define HWIO_GENI_CFG_REG112_RMSK                                                                                  0x3
#define HWIO_GENI_CFG_REG112_IN                    \
                in_dword(HWIO_GENI_CFG_REG112_ADDR)
#define HWIO_GENI_CFG_REG112_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG112_ADDR, m)
#define HWIO_GENI_CFG_REG112_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG112_ADDR,v)
#define HWIO_GENI_CFG_REG112_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG112_ADDR,m,v,HWIO_GENI_CFG_REG112_IN)
#define HWIO_GENI_CFG_REG112_RX_GENI_BYTE_GRANULARITY_BMSK                                                         0x3
#define HWIO_GENI_CFG_REG112_RX_GENI_BYTE_GRANULARITY_SHFT                                                           0

#define HWIO_GENI_RX_BYTE_GRANULARITY_ADDR                                                                  (GENI4_IMAGE_REGS_REG_BASE            + 0x1c0)
#define HWIO_GENI_RX_BYTE_GRANULARITY_PHYS                                                                  (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x1c0)
#define HWIO_GENI_RX_BYTE_GRANULARITY_OFFS                                                                  (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x1c0)
#define HWIO_GENI_RX_BYTE_GRANULARITY_RMSK                                                                         0x3
#define HWIO_GENI_RX_BYTE_GRANULARITY_IN                    \
                in_dword(HWIO_GENI_RX_BYTE_GRANULARITY_ADDR)
#define HWIO_GENI_RX_BYTE_GRANULARITY_INM(m)            \
                in_dword_masked(HWIO_GENI_RX_BYTE_GRANULARITY_ADDR, m)
#define HWIO_GENI_RX_BYTE_GRANULARITY_OUT(v)            \
                out_dword(HWIO_GENI_RX_BYTE_GRANULARITY_ADDR,v)
#define HWIO_GENI_RX_BYTE_GRANULARITY_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_RX_BYTE_GRANULARITY_ADDR,m,v,HWIO_GENI_RX_BYTE_GRANULARITY_IN)
#define HWIO_GENI_RX_BYTE_GRANULARITY_GENI_RX_BYTE_GRANULARITY_BMSK                                                0x3
#define HWIO_GENI_RX_BYTE_GRANULARITY_GENI_RX_BYTE_GRANULARITY_SHFT                                                  0

#define HWIO_GENI_CFG_REG113_ADDR                                                                           (GENI4_IMAGE_REGS_REG_BASE            + 0x1c4)
#define HWIO_GENI_CFG_REG113_PHYS                                                                           (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x1c4)
#define HWIO_GENI_CFG_REG113_OFFS                                                                           (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x1c4)
#define HWIO_GENI_CFG_REG113_RMSK                                                                                 0xff
#define HWIO_GENI_CFG_REG113_IN                    \
                in_dword(HWIO_GENI_CFG_REG113_ADDR)
#define HWIO_GENI_CFG_REG113_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG113_ADDR, m)
#define HWIO_GENI_CFG_REG113_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG113_ADDR,v)
#define HWIO_GENI_CFG_REG113_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG113_ADDR,m,v,HWIO_GENI_CFG_REG113_IN)
#define HWIO_GENI_CFG_REG113_TX_PARAM_SEQ_WR_DATA_BMSK                                                            0xff
#define HWIO_GENI_CFG_REG113_TX_PARAM_SEQ_WR_DATA_SHFT                                                               0

#define HWIO_GENI_CFG_REG113_SHARED_ADDR                                                                    (GENI4_IMAGE_REGS_REG_BASE            + 0x1c4)
#define HWIO_GENI_CFG_REG113_SHARED_PHYS                                                                    (GENI4_IMAGE_REGS_REG_BASE_PHYS + 0x1c4)
#define HWIO_GENI_CFG_REG113_SHARED_OFFS                                                                    (GENI4_IMAGE_REGS_REG_BASE_OFFS + 0x1c4)
#define HWIO_GENI_CFG_REG113_SHARED_RMSK                                                                          0xff
#define HWIO_GENI_CFG_REG113_SHARED_IN                    \
                in_dword(HWIO_GENI_CFG_REG113_SHARED_ADDR)
#define HWIO_GENI_CFG_REG113_SHARED_INM(m)            \
                in_dword_masked(HWIO_GENI_CFG_REG113_SHARED_ADDR, m)
#define HWIO_GENI_CFG_REG113_SHARED_OUT(v)            \
                out_dword(HWIO_GENI_CFG_REG113_SHARED_ADDR,v)
#define HWIO_GENI_CFG_REG113_SHARED_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CFG_REG113_SHARED_ADDR,m,v,HWIO_GENI_CFG_REG113_SHARED_IN)
#define HWIO_GENI_CFG_REG113_SHARED_TX_PARAM_SEQ_WR_DATA_BMSK                                                     0xff
#define HWIO_GENI_CFG_REG113_SHARED_TX_PARAM_SEQ_WR_DATA_SHFT                                                        0

/*----------------------------------------------------------------------------
 * MODULE: GENI4_DATA
 *--------------------------------------------------------------------------*/

#define GENI4_DATA_REG_BASE                                                                      (SAILSS_QUPV3_1_QUPV3_ID_1_BASE            + 0x00080600)
#define GENI4_DATA_REG_BASE_SIZE                                                                 0x600
#define GENI4_DATA_REG_BASE_USED                                                                 0x518
#define GENI4_DATA_REG_BASE_PHYS                                                                 (SAILSS_QUPV3_1_QUPV3_ID_1_BASE_PHYS + 0x00080600)
#define GENI4_DATA_REG_BASE_OFFS                                                                 0x00080600

#define HWIO_GENI_M_CMD0_ADDR                                                                    (GENI4_DATA_REG_BASE            + 0x0)
#define HWIO_GENI_M_CMD0_PHYS                                                                    (GENI4_DATA_REG_BASE_PHYS + 0x0)
#define HWIO_GENI_M_CMD0_OFFS                                                                    (GENI4_DATA_REG_BASE_OFFS + 0x0)
#define HWIO_GENI_M_CMD0_RMSK                                                                    0xffffffff
#define HWIO_GENI_M_CMD0_IN                    \
                in_dword(HWIO_GENI_M_CMD0_ADDR)
#define HWIO_GENI_M_CMD0_INM(m)            \
                in_dword_masked(HWIO_GENI_M_CMD0_ADDR, m)
#define HWIO_GENI_M_CMD0_OUT(v)            \
                out_dword(HWIO_GENI_M_CMD0_ADDR,v)
#define HWIO_GENI_M_CMD0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_M_CMD0_ADDR,m,v,HWIO_GENI_M_CMD0_IN)
#define HWIO_GENI_M_CMD0_OPCODE_BMSK                                                             0xf8000000
#define HWIO_GENI_M_CMD0_OPCODE_SHFT                                                                     27
#define HWIO_GENI_M_CMD0_PARAM_BMSK                                                               0x7ffffff
#define HWIO_GENI_M_CMD0_PARAM_SHFT                                                                       0

#define HWIO_GENI_M_CMD_CTRL_REG_ADDR                                                            (GENI4_DATA_REG_BASE            + 0x4)
#define HWIO_GENI_M_CMD_CTRL_REG_PHYS                                                            (GENI4_DATA_REG_BASE_PHYS + 0x4)
#define HWIO_GENI_M_CMD_CTRL_REG_OFFS                                                            (GENI4_DATA_REG_BASE_OFFS + 0x4)
#define HWIO_GENI_M_CMD_CTRL_REG_RMSK                                                                   0x7
#define HWIO_GENI_M_CMD_CTRL_REG_IN                    \
                in_dword(HWIO_GENI_M_CMD_CTRL_REG_ADDR)
#define HWIO_GENI_M_CMD_CTRL_REG_INM(m)            \
                in_dword_masked(HWIO_GENI_M_CMD_CTRL_REG_ADDR, m)
#define HWIO_GENI_M_CMD_CTRL_REG_OUT(v)            \
                out_dword(HWIO_GENI_M_CMD_CTRL_REG_ADDR,v)
#define HWIO_GENI_M_CMD_CTRL_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_M_CMD_CTRL_REG_ADDR,m,v,HWIO_GENI_M_CMD_CTRL_REG_IN)
#define HWIO_GENI_M_CMD_CTRL_REG_M_GENI_CMD_CANCEL_BMSK                                                 0x4
#define HWIO_GENI_M_CMD_CTRL_REG_M_GENI_CMD_CANCEL_SHFT                                                   2
#define HWIO_GENI_M_CMD_CTRL_REG_M_GENI_CMD_ABORT_BMSK                                                  0x2
#define HWIO_GENI_M_CMD_CTRL_REG_M_GENI_CMD_ABORT_SHFT                                                    1
#define HWIO_GENI_M_CMD_CTRL_REG_M_GENI_DISABLE_BMSK                                                    0x1
#define HWIO_GENI_M_CMD_CTRL_REG_M_GENI_DISABLE_SHFT                                                      0

#define HWIO_GENI_M_IRQ_STATUS_ADDR                                                              (GENI4_DATA_REG_BASE            + 0x10)
#define HWIO_GENI_M_IRQ_STATUS_PHYS                                                              (GENI4_DATA_REG_BASE_PHYS + 0x10)
#define HWIO_GENI_M_IRQ_STATUS_OFFS                                                              (GENI4_DATA_REG_BASE_OFFS + 0x10)
#define HWIO_GENI_M_IRQ_STATUS_RMSK                                                              0xfff1ffff
#define HWIO_GENI_M_IRQ_STATUS_IN                    \
                in_dword(HWIO_GENI_M_IRQ_STATUS_ADDR)
#define HWIO_GENI_M_IRQ_STATUS_INM(m)            \
                in_dword_masked(HWIO_GENI_M_IRQ_STATUS_ADDR, m)
#define HWIO_GENI_M_IRQ_STATUS_SEC_IRQ_BMSK                                                      0x80000000
#define HWIO_GENI_M_IRQ_STATUS_SEC_IRQ_SHFT                                                              31
#define HWIO_GENI_M_IRQ_STATUS_TX_FIFO_WATERMARK_BMSK                                            0x40000000
#define HWIO_GENI_M_IRQ_STATUS_TX_FIFO_WATERMARK_SHFT                                                    30
#define HWIO_GENI_M_IRQ_STATUS_TX_FIFO_WR_ERR_BMSK                                               0x20000000
#define HWIO_GENI_M_IRQ_STATUS_TX_FIFO_WR_ERR_SHFT                                                       29
#define HWIO_GENI_M_IRQ_STATUS_TX_FIFO_RD_ERR_BMSK                                               0x10000000
#define HWIO_GENI_M_IRQ_STATUS_TX_FIFO_RD_ERR_SHFT                                                       28
#define HWIO_GENI_M_IRQ_STATUS_RX_FIFO_LAST_BMSK                                                  0x8000000
#define HWIO_GENI_M_IRQ_STATUS_RX_FIFO_LAST_SHFT                                                         27
#define HWIO_GENI_M_IRQ_STATUS_RX_FIFO_WATERMARK_BMSK                                             0x4000000
#define HWIO_GENI_M_IRQ_STATUS_RX_FIFO_WATERMARK_SHFT                                                    26
#define HWIO_GENI_M_IRQ_STATUS_RX_FIFO_WR_ERR_BMSK                                                0x2000000
#define HWIO_GENI_M_IRQ_STATUS_RX_FIFO_WR_ERR_SHFT                                                       25
#define HWIO_GENI_M_IRQ_STATUS_RX_FIFO_RD_ERR_BMSK                                                0x1000000
#define HWIO_GENI_M_IRQ_STATUS_RX_FIFO_RD_ERR_SHFT                                                       24
#define HWIO_GENI_M_IRQ_STATUS_IO_DATA_ASSERT_BMSK                                                 0x800000
#define HWIO_GENI_M_IRQ_STATUS_IO_DATA_ASSERT_SHFT                                                       23
#define HWIO_GENI_M_IRQ_STATUS_IO_DATA_DEASSERT_BMSK                                               0x400000
#define HWIO_GENI_M_IRQ_STATUS_IO_DATA_DEASSERT_SHFT                                                     22
#define HWIO_GENI_M_IRQ_STATUS_TX_FIFO_NOT_EMPTY_BMSK                                              0x200000
#define HWIO_GENI_M_IRQ_STATUS_TX_FIFO_NOT_EMPTY_SHFT                                                    21
#define HWIO_GENI_M_IRQ_STATUS_M_HW_IRQ_BMSK                                                       0x100000
#define HWIO_GENI_M_IRQ_STATUS_M_HW_IRQ_SHFT                                                             20
#define HWIO_GENI_M_IRQ_STATUS_M_GP_IRQ_7_BMSK                                                      0x10000
#define HWIO_GENI_M_IRQ_STATUS_M_GP_IRQ_7_SHFT                                                           16
#define HWIO_GENI_M_IRQ_STATUS_M_GP_IRQ_6_BMSK                                                       0x8000
#define HWIO_GENI_M_IRQ_STATUS_M_GP_IRQ_6_SHFT                                                           15
#define HWIO_GENI_M_IRQ_STATUS_M_GP_IRQ_5_BMSK                                                       0x4000
#define HWIO_GENI_M_IRQ_STATUS_M_GP_IRQ_5_SHFT                                                           14
#define HWIO_GENI_M_IRQ_STATUS_M_GP_IRQ_4_BMSK                                                       0x2000
#define HWIO_GENI_M_IRQ_STATUS_M_GP_IRQ_4_SHFT                                                           13
#define HWIO_GENI_M_IRQ_STATUS_M_GP_IRQ_3_BMSK                                                       0x1000
#define HWIO_GENI_M_IRQ_STATUS_M_GP_IRQ_3_SHFT                                                           12
#define HWIO_GENI_M_IRQ_STATUS_M_GP_IRQ_2_BMSK                                                        0x800
#define HWIO_GENI_M_IRQ_STATUS_M_GP_IRQ_2_SHFT                                                           11
#define HWIO_GENI_M_IRQ_STATUS_M_GP_IRQ_1_BMSK                                                        0x400
#define HWIO_GENI_M_IRQ_STATUS_M_GP_IRQ_1_SHFT                                                           10
#define HWIO_GENI_M_IRQ_STATUS_M_GP_IRQ_0_BMSK                                                        0x200
#define HWIO_GENI_M_IRQ_STATUS_M_GP_IRQ_0_SHFT                                                            9
#define HWIO_GENI_M_IRQ_STATUS_M_GP_SYNC_IRQ_0_BMSK                                                   0x100
#define HWIO_GENI_M_IRQ_STATUS_M_GP_SYNC_IRQ_0_SHFT                                                       8
#define HWIO_GENI_M_IRQ_STATUS_M_RX_IRQ_BMSK                                                           0x80
#define HWIO_GENI_M_IRQ_STATUS_M_RX_IRQ_SHFT                                                              7
#define HWIO_GENI_M_IRQ_STATUS_M_TIMESTAMP_BMSK                                                        0x40
#define HWIO_GENI_M_IRQ_STATUS_M_TIMESTAMP_SHFT                                                           6
#define HWIO_GENI_M_IRQ_STATUS_M_CMD_ABORT_BMSK                                                        0x20
#define HWIO_GENI_M_IRQ_STATUS_M_CMD_ABORT_SHFT                                                           5
#define HWIO_GENI_M_IRQ_STATUS_M_CMD_CANCEL_BMSK                                                       0x10
#define HWIO_GENI_M_IRQ_STATUS_M_CMD_CANCEL_SHFT                                                          4
#define HWIO_GENI_M_IRQ_STATUS_M_CMD_FAILURE_BMSK                                                       0x8
#define HWIO_GENI_M_IRQ_STATUS_M_CMD_FAILURE_SHFT                                                         3
#define HWIO_GENI_M_IRQ_STATUS_M_ILLEGAL_CMD_BMSK                                                       0x4
#define HWIO_GENI_M_IRQ_STATUS_M_ILLEGAL_CMD_SHFT                                                         2
#define HWIO_GENI_M_IRQ_STATUS_M_CMD_OVERRUN_BMSK                                                       0x2
#define HWIO_GENI_M_IRQ_STATUS_M_CMD_OVERRUN_SHFT                                                         1
#define HWIO_GENI_M_IRQ_STATUS_M_CMD_DONE_BMSK                                                          0x1
#define HWIO_GENI_M_IRQ_STATUS_M_CMD_DONE_SHFT                                                            0

#define HWIO_GENI_M_IRQ_ENABLE_ADDR                                                              (GENI4_DATA_REG_BASE            + 0x14)
#define HWIO_GENI_M_IRQ_ENABLE_PHYS                                                              (GENI4_DATA_REG_BASE_PHYS + 0x14)
#define HWIO_GENI_M_IRQ_ENABLE_OFFS                                                              (GENI4_DATA_REG_BASE_OFFS + 0x14)
#define HWIO_GENI_M_IRQ_ENABLE_RMSK                                                              0xfff1ffff
#define HWIO_GENI_M_IRQ_ENABLE_IN                    \
                in_dword(HWIO_GENI_M_IRQ_ENABLE_ADDR)
#define HWIO_GENI_M_IRQ_ENABLE_INM(m)            \
                in_dword_masked(HWIO_GENI_M_IRQ_ENABLE_ADDR, m)
#define HWIO_GENI_M_IRQ_ENABLE_OUT(v)            \
                out_dword(HWIO_GENI_M_IRQ_ENABLE_ADDR,v)
#define HWIO_GENI_M_IRQ_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_M_IRQ_ENABLE_ADDR,m,v,HWIO_GENI_M_IRQ_ENABLE_IN)
#define HWIO_GENI_M_IRQ_ENABLE_SEC_IRQ_EN_BMSK                                                   0x80000000
#define HWIO_GENI_M_IRQ_ENABLE_SEC_IRQ_EN_SHFT                                                           31
#define HWIO_GENI_M_IRQ_ENABLE_TX_FIFO_WATERMARK_EN_BMSK                                         0x40000000
#define HWIO_GENI_M_IRQ_ENABLE_TX_FIFO_WATERMARK_EN_SHFT                                                 30
#define HWIO_GENI_M_IRQ_ENABLE_TX_FIFO_WR_ERR_EN_BMSK                                            0x20000000
#define HWIO_GENI_M_IRQ_ENABLE_TX_FIFO_WR_ERR_EN_SHFT                                                    29
#define HWIO_GENI_M_IRQ_ENABLE_TX_FIFO_RD_ERR_EN_BMSK                                            0x10000000
#define HWIO_GENI_M_IRQ_ENABLE_TX_FIFO_RD_ERR_EN_SHFT                                                    28
#define HWIO_GENI_M_IRQ_ENABLE_RX_FIFO_LAST_EN_BMSK                                               0x8000000
#define HWIO_GENI_M_IRQ_ENABLE_RX_FIFO_LAST_EN_SHFT                                                      27
#define HWIO_GENI_M_IRQ_ENABLE_RX_FIFO_WATERMARK_EN_BMSK                                          0x4000000
#define HWIO_GENI_M_IRQ_ENABLE_RX_FIFO_WATERMARK_EN_SHFT                                                 26
#define HWIO_GENI_M_IRQ_ENABLE_RX_FIFO_WR_ERR_EN_BMSK                                             0x2000000
#define HWIO_GENI_M_IRQ_ENABLE_RX_FIFO_WR_ERR_EN_SHFT                                                    25
#define HWIO_GENI_M_IRQ_ENABLE_RX_FIFO_RD_ERR_EN_BMSK                                             0x1000000
#define HWIO_GENI_M_IRQ_ENABLE_RX_FIFO_RD_ERR_EN_SHFT                                                    24
#define HWIO_GENI_M_IRQ_ENABLE_IO_DATA_ASSERT_EN_BMSK                                              0x800000
#define HWIO_GENI_M_IRQ_ENABLE_IO_DATA_ASSERT_EN_SHFT                                                    23
#define HWIO_GENI_M_IRQ_ENABLE_IO_DATA_DEASSERT_EN_BMSK                                            0x400000
#define HWIO_GENI_M_IRQ_ENABLE_IO_DATA_DEASSERT_EN_SHFT                                                  22
#define HWIO_GENI_M_IRQ_ENABLE_TX_FIFO_NOT_EMPTY_EN_BMSK                                           0x200000
#define HWIO_GENI_M_IRQ_ENABLE_TX_FIFO_NOT_EMPTY_EN_SHFT                                                 21
#define HWIO_GENI_M_IRQ_ENABLE_M_HW_IRQ_EN_BMSK                                                    0x100000
#define HWIO_GENI_M_IRQ_ENABLE_M_HW_IRQ_EN_SHFT                                                          20
#define HWIO_GENI_M_IRQ_ENABLE_M_GP_IRQ_7_EN_BMSK                                                   0x10000
#define HWIO_GENI_M_IRQ_ENABLE_M_GP_IRQ_7_EN_SHFT                                                        16
#define HWIO_GENI_M_IRQ_ENABLE_M_GP_IRQ_6_EN_BMSK                                                    0x8000
#define HWIO_GENI_M_IRQ_ENABLE_M_GP_IRQ_6_EN_SHFT                                                        15
#define HWIO_GENI_M_IRQ_ENABLE_M_GP_IRQ_5_EN_BMSK                                                    0x4000
#define HWIO_GENI_M_IRQ_ENABLE_M_GP_IRQ_5_EN_SHFT                                                        14
#define HWIO_GENI_M_IRQ_ENABLE_M_GP_IRQ_4_EN_BMSK                                                    0x2000
#define HWIO_GENI_M_IRQ_ENABLE_M_GP_IRQ_4_EN_SHFT                                                        13
#define HWIO_GENI_M_IRQ_ENABLE_M_GP_IRQ_3_EN_BMSK                                                    0x1000
#define HWIO_GENI_M_IRQ_ENABLE_M_GP_IRQ_3_EN_SHFT                                                        12
#define HWIO_GENI_M_IRQ_ENABLE_M_GP_IRQ_2_EN_BMSK                                                     0x800
#define HWIO_GENI_M_IRQ_ENABLE_M_GP_IRQ_2_EN_SHFT                                                        11
#define HWIO_GENI_M_IRQ_ENABLE_M_GP_IRQ_1_EN_BMSK                                                     0x400
#define HWIO_GENI_M_IRQ_ENABLE_M_GP_IRQ_1_EN_SHFT                                                        10
#define HWIO_GENI_M_IRQ_ENABLE_M_GP_IRQ_0_EN_BMSK                                                     0x200
#define HWIO_GENI_M_IRQ_ENABLE_M_GP_IRQ_0_EN_SHFT                                                         9
#define HWIO_GENI_M_IRQ_ENABLE_M_GP_SYNC_IRQ_0_EN_BMSK                                                0x100
#define HWIO_GENI_M_IRQ_ENABLE_M_GP_SYNC_IRQ_0_EN_SHFT                                                    8
#define HWIO_GENI_M_IRQ_ENABLE_M_RX_IRQ_EN_BMSK                                                        0x80
#define HWIO_GENI_M_IRQ_ENABLE_M_RX_IRQ_EN_SHFT                                                           7
#define HWIO_GENI_M_IRQ_ENABLE_M_TIMESTAMP_EN_BMSK                                                     0x40
#define HWIO_GENI_M_IRQ_ENABLE_M_TIMESTAMP_EN_SHFT                                                        6
#define HWIO_GENI_M_IRQ_ENABLE_M_CMD_ABORT_EN_BMSK                                                     0x20
#define HWIO_GENI_M_IRQ_ENABLE_M_CMD_ABORT_EN_SHFT                                                        5
#define HWIO_GENI_M_IRQ_ENABLE_M_CMD_CANCEL_EN_BMSK                                                    0x10
#define HWIO_GENI_M_IRQ_ENABLE_M_CMD_CANCEL_EN_SHFT                                                       4
#define HWIO_GENI_M_IRQ_ENABLE_M_CMD_FAILURE_EN_BMSK                                                    0x8
#define HWIO_GENI_M_IRQ_ENABLE_M_CMD_FAILURE_EN_SHFT                                                      3
#define HWIO_GENI_M_IRQ_ENABLE_M_ILLEGAL_CMD_EN_BMSK                                                    0x4
#define HWIO_GENI_M_IRQ_ENABLE_M_ILLEGAL_CMD_EN_SHFT                                                      2
#define HWIO_GENI_M_IRQ_ENABLE_M_CMD_OVERRUN_EN_BMSK                                                    0x2
#define HWIO_GENI_M_IRQ_ENABLE_M_CMD_OVERRUN_EN_SHFT                                                      1
#define HWIO_GENI_M_IRQ_ENABLE_M_CMD_DONE_EN_BMSK                                                       0x1
#define HWIO_GENI_M_IRQ_ENABLE_M_CMD_DONE_EN_SHFT                                                         0

#define HWIO_GENI_M_IRQ_CLEAR_ADDR                                                               (GENI4_DATA_REG_BASE            + 0x18)
#define HWIO_GENI_M_IRQ_CLEAR_PHYS                                                               (GENI4_DATA_REG_BASE_PHYS + 0x18)
#define HWIO_GENI_M_IRQ_CLEAR_OFFS                                                               (GENI4_DATA_REG_BASE_OFFS + 0x18)
#define HWIO_GENI_M_IRQ_CLEAR_RMSK                                                               0xfff1ffff
#define HWIO_GENI_M_IRQ_CLEAR_OUT(v)            \
                out_dword(HWIO_GENI_M_IRQ_CLEAR_ADDR,v)
#define HWIO_GENI_M_IRQ_CLEAR_SEC_IRQ_CLEAR_BMSK                                                 0x80000000
#define HWIO_GENI_M_IRQ_CLEAR_SEC_IRQ_CLEAR_SHFT                                                         31
#define HWIO_GENI_M_IRQ_CLEAR_TX_FIFO_WATERMARK_CLEAR_BMSK                                       0x40000000
#define HWIO_GENI_M_IRQ_CLEAR_TX_FIFO_WATERMARK_CLEAR_SHFT                                               30
#define HWIO_GENI_M_IRQ_CLEAR_TX_FIFO_WR_ERR_CLEAR_BMSK                                          0x20000000
#define HWIO_GENI_M_IRQ_CLEAR_TX_FIFO_WR_ERR_CLEAR_SHFT                                                  29
#define HWIO_GENI_M_IRQ_CLEAR_TX_FIFO_RD_ERR_CLEAR_BMSK                                          0x10000000
#define HWIO_GENI_M_IRQ_CLEAR_TX_FIFO_RD_ERR_CLEAR_SHFT                                                  28
#define HWIO_GENI_M_IRQ_CLEAR_RX_FIFO_LAST_CLEAR_BMSK                                             0x8000000
#define HWIO_GENI_M_IRQ_CLEAR_RX_FIFO_LAST_CLEAR_SHFT                                                    27
#define HWIO_GENI_M_IRQ_CLEAR_RX_FIFO_WATERMARK_CLEAR_BMSK                                        0x4000000
#define HWIO_GENI_M_IRQ_CLEAR_RX_FIFO_WATERMARK_CLEAR_SHFT                                               26
#define HWIO_GENI_M_IRQ_CLEAR_RX_FIFO_WR_ERR_CLEAR_BMSK                                           0x2000000
#define HWIO_GENI_M_IRQ_CLEAR_RX_FIFO_WR_ERR_CLEAR_SHFT                                                  25
#define HWIO_GENI_M_IRQ_CLEAR_RX_FIFO_RD_ERR_CLEAR_BMSK                                           0x1000000
#define HWIO_GENI_M_IRQ_CLEAR_RX_FIFO_RD_ERR_CLEAR_SHFT                                                  24
#define HWIO_GENI_M_IRQ_CLEAR_IO_DATA_ASSERT_CLEAR_BMSK                                            0x800000
#define HWIO_GENI_M_IRQ_CLEAR_IO_DATA_ASSERT_CLEAR_SHFT                                                  23
#define HWIO_GENI_M_IRQ_CLEAR_IO_DATA_DEASSERT_CLEAR_BMSK                                          0x400000
#define HWIO_GENI_M_IRQ_CLEAR_IO_DATA_DEASSERT_CLEAR_SHFT                                                22
#define HWIO_GENI_M_IRQ_CLEAR_TX_FIFO_NOT_EMPTY_CLEAR_BMSK                                         0x200000
#define HWIO_GENI_M_IRQ_CLEAR_TX_FIFO_NOT_EMPTY_CLEAR_SHFT                                               21
#define HWIO_GENI_M_IRQ_CLEAR_M_HW_IRQ_CLEAR_BMSK                                                  0x100000
#define HWIO_GENI_M_IRQ_CLEAR_M_HW_IRQ_CLEAR_SHFT                                                        20
#define HWIO_GENI_M_IRQ_CLEAR_M_GP_IRQ_7_CLEAR_BMSK                                                 0x10000
#define HWIO_GENI_M_IRQ_CLEAR_M_GP_IRQ_7_CLEAR_SHFT                                                      16
#define HWIO_GENI_M_IRQ_CLEAR_M_GP_IRQ_6_CLEAR_BMSK                                                  0x8000
#define HWIO_GENI_M_IRQ_CLEAR_M_GP_IRQ_6_CLEAR_SHFT                                                      15
#define HWIO_GENI_M_IRQ_CLEAR_M_GP_IRQ_5_CLEAR_BMSK                                                  0x4000
#define HWIO_GENI_M_IRQ_CLEAR_M_GP_IRQ_5_CLEAR_SHFT                                                      14
#define HWIO_GENI_M_IRQ_CLEAR_M_GP_IRQ_4_CLEAR_BMSK                                                  0x2000
#define HWIO_GENI_M_IRQ_CLEAR_M_GP_IRQ_4_CLEAR_SHFT                                                      13
#define HWIO_GENI_M_IRQ_CLEAR_M_GP_IRQ_3_CLEAR_BMSK                                                  0x1000
#define HWIO_GENI_M_IRQ_CLEAR_M_GP_IRQ_3_CLEAR_SHFT                                                      12
#define HWIO_GENI_M_IRQ_CLEAR_M_GP_IRQ_2_CLEAR_BMSK                                                   0x800
#define HWIO_GENI_M_IRQ_CLEAR_M_GP_IRQ_2_CLEAR_SHFT                                                      11
#define HWIO_GENI_M_IRQ_CLEAR_M_GP_IRQ_1_CLEAR_BMSK                                                   0x400
#define HWIO_GENI_M_IRQ_CLEAR_M_GP_IRQ_1_CLEAR_SHFT                                                      10
#define HWIO_GENI_M_IRQ_CLEAR_M_GP_IRQ_0_CLEAR_BMSK                                                   0x200
#define HWIO_GENI_M_IRQ_CLEAR_M_GP_IRQ_0_CLEAR_SHFT                                                       9
#define HWIO_GENI_M_IRQ_CLEAR_M_GP_SYNC_IRQ_0_CLEAR_BMSK                                              0x100
#define HWIO_GENI_M_IRQ_CLEAR_M_GP_SYNC_IRQ_0_CLEAR_SHFT                                                  8
#define HWIO_GENI_M_IRQ_CLEAR_M_RX_IRQ_CLEAR_BMSK                                                      0x80
#define HWIO_GENI_M_IRQ_CLEAR_M_RX_IRQ_CLEAR_SHFT                                                         7
#define HWIO_GENI_M_IRQ_CLEAR_M_TIMESTAMP_CLEAR_BMSK                                                   0x40
#define HWIO_GENI_M_IRQ_CLEAR_M_TIMESTAMP_CLEAR_SHFT                                                      6
#define HWIO_GENI_M_IRQ_CLEAR_M_CMD_ABORT_CLEAR_BMSK                                                   0x20
#define HWIO_GENI_M_IRQ_CLEAR_M_CMD_ABORT_CLEAR_SHFT                                                      5
#define HWIO_GENI_M_IRQ_CLEAR_M_CMD_CANCEL_CLEAR_BMSK                                                  0x10
#define HWIO_GENI_M_IRQ_CLEAR_M_CMD_CANCEL_CLEAR_SHFT                                                     4
#define HWIO_GENI_M_IRQ_CLEAR_M_CMD_FAILURE_CLEAR_BMSK                                                  0x8
#define HWIO_GENI_M_IRQ_CLEAR_M_CMD_FAILURE_CLEAR_SHFT                                                    3
#define HWIO_GENI_M_IRQ_CLEAR_M_ILLEGAL_CMD_CLEAR_BMSK                                                  0x4
#define HWIO_GENI_M_IRQ_CLEAR_M_ILLEGAL_CMD_CLEAR_SHFT                                                    2
#define HWIO_GENI_M_IRQ_CLEAR_M_CMD_OVERRUN_CLEAR_BMSK                                                  0x2
#define HWIO_GENI_M_IRQ_CLEAR_M_CMD_OVERRUN_CLEAR_SHFT                                                    1
#define HWIO_GENI_M_IRQ_CLEAR_M_CMD_DONE_CLEAR_BMSK                                                     0x1
#define HWIO_GENI_M_IRQ_CLEAR_M_CMD_DONE_CLEAR_SHFT                                                       0

#define HWIO_GENI_M_IRQ_EN_SET_ADDR                                                              (GENI4_DATA_REG_BASE            + 0x1c)
#define HWIO_GENI_M_IRQ_EN_SET_PHYS                                                              (GENI4_DATA_REG_BASE_PHYS + 0x1c)
#define HWIO_GENI_M_IRQ_EN_SET_OFFS                                                              (GENI4_DATA_REG_BASE_OFFS + 0x1c)
#define HWIO_GENI_M_IRQ_EN_SET_RMSK                                                              0xfff1ffff
#define HWIO_GENI_M_IRQ_EN_SET_OUT(v)            \
                out_dword(HWIO_GENI_M_IRQ_EN_SET_ADDR,v)
#define HWIO_GENI_M_IRQ_EN_SET_SEC_IRQ_EN_SET_BMSK                                               0x80000000
#define HWIO_GENI_M_IRQ_EN_SET_SEC_IRQ_EN_SET_SHFT                                                       31
#define HWIO_GENI_M_IRQ_EN_SET_TX_FIFO_WATERMARK_EN_SET_BMSK                                     0x40000000
#define HWIO_GENI_M_IRQ_EN_SET_TX_FIFO_WATERMARK_EN_SET_SHFT                                             30
#define HWIO_GENI_M_IRQ_EN_SET_TX_FIFO_WR_ERR_EN_SET_BMSK                                        0x20000000
#define HWIO_GENI_M_IRQ_EN_SET_TX_FIFO_WR_ERR_EN_SET_SHFT                                                29
#define HWIO_GENI_M_IRQ_EN_SET_TX_FIFO_RD_ERR_EN_SET_BMSK                                        0x10000000
#define HWIO_GENI_M_IRQ_EN_SET_TX_FIFO_RD_ERR_EN_SET_SHFT                                                28
#define HWIO_GENI_M_IRQ_EN_SET_RX_FIFO_LAST_EN_SET_BMSK                                           0x8000000
#define HWIO_GENI_M_IRQ_EN_SET_RX_FIFO_LAST_EN_SET_SHFT                                                  27
#define HWIO_GENI_M_IRQ_EN_SET_RX_FIFO_WATERMARK_EN_SET_BMSK                                      0x4000000
#define HWIO_GENI_M_IRQ_EN_SET_RX_FIFO_WATERMARK_EN_SET_SHFT                                             26
#define HWIO_GENI_M_IRQ_EN_SET_RX_FIFO_WR_ERR_EN_SET_BMSK                                         0x2000000
#define HWIO_GENI_M_IRQ_EN_SET_RX_FIFO_WR_ERR_EN_SET_SHFT                                                25
#define HWIO_GENI_M_IRQ_EN_SET_RX_FIFO_RD_ERR_EN_SET_BMSK                                         0x1000000
#define HWIO_GENI_M_IRQ_EN_SET_RX_FIFO_RD_ERR_EN_SET_SHFT                                                24
#define HWIO_GENI_M_IRQ_EN_SET_IO_DATA_ASSERT_EN_SET_BMSK                                          0x800000
#define HWIO_GENI_M_IRQ_EN_SET_IO_DATA_ASSERT_EN_SET_SHFT                                                23
#define HWIO_GENI_M_IRQ_EN_SET_IO_DATA_DEASSERT_EN_SET_BMSK                                        0x400000
#define HWIO_GENI_M_IRQ_EN_SET_IO_DATA_DEASSERT_EN_SET_SHFT                                              22
#define HWIO_GENI_M_IRQ_EN_SET_TX_FIFO_NOT_EMPTY_EN_SET_BMSK                                       0x200000
#define HWIO_GENI_M_IRQ_EN_SET_TX_FIFO_NOT_EMPTY_EN_SET_SHFT                                             21
#define HWIO_GENI_M_IRQ_EN_SET_M_HW_IRQ_EN_SET_BMSK                                                0x100000
#define HWIO_GENI_M_IRQ_EN_SET_M_HW_IRQ_EN_SET_SHFT                                                      20
#define HWIO_GENI_M_IRQ_EN_SET_M_GP_IRQ_7_EN_SET_BMSK                                               0x10000
#define HWIO_GENI_M_IRQ_EN_SET_M_GP_IRQ_7_EN_SET_SHFT                                                    16
#define HWIO_GENI_M_IRQ_EN_SET_M_GP_IRQ_6_EN_SET_BMSK                                                0x8000
#define HWIO_GENI_M_IRQ_EN_SET_M_GP_IRQ_6_EN_SET_SHFT                                                    15
#define HWIO_GENI_M_IRQ_EN_SET_M_GP_IRQ_5_EN_SET_BMSK                                                0x4000
#define HWIO_GENI_M_IRQ_EN_SET_M_GP_IRQ_5_EN_SET_SHFT                                                    14
#define HWIO_GENI_M_IRQ_EN_SET_M_GP_IRQ_4_EN_SET_BMSK                                                0x2000
#define HWIO_GENI_M_IRQ_EN_SET_M_GP_IRQ_4_EN_SET_SHFT                                                    13
#define HWIO_GENI_M_IRQ_EN_SET_M_GP_IRQ_3_EN_SET_BMSK                                                0x1000
#define HWIO_GENI_M_IRQ_EN_SET_M_GP_IRQ_3_EN_SET_SHFT                                                    12
#define HWIO_GENI_M_IRQ_EN_SET_M_GP_IRQ_2_EN_SET_BMSK                                                 0x800
#define HWIO_GENI_M_IRQ_EN_SET_M_GP_IRQ_2_EN_SET_SHFT                                                    11
#define HWIO_GENI_M_IRQ_EN_SET_M_GP_IRQ_1_EN_SET_BMSK                                                 0x400
#define HWIO_GENI_M_IRQ_EN_SET_M_GP_IRQ_1_EN_SET_SHFT                                                    10
#define HWIO_GENI_M_IRQ_EN_SET_M_GP_IRQ_0_EN_SET_BMSK                                                 0x200
#define HWIO_GENI_M_IRQ_EN_SET_M_GP_IRQ_0_EN_SET_SHFT                                                     9
#define HWIO_GENI_M_IRQ_EN_SET_M_GP_SYNC_IRQ_0_EN_SET_BMSK                                            0x100
#define HWIO_GENI_M_IRQ_EN_SET_M_GP_SYNC_IRQ_0_EN_SET_SHFT                                                8
#define HWIO_GENI_M_IRQ_EN_SET_M_RX_IRQ_EN_SET_BMSK                                                    0x80
#define HWIO_GENI_M_IRQ_EN_SET_M_RX_IRQ_EN_SET_SHFT                                                       7
#define HWIO_GENI_M_IRQ_EN_SET_M_TIMESTAMP_EN_SET_BMSK                                                 0x40
#define HWIO_GENI_M_IRQ_EN_SET_M_TIMESTAMP_EN_SET_SHFT                                                    6
#define HWIO_GENI_M_IRQ_EN_SET_M_CMD_ABORT_EN_SET_BMSK                                                 0x20
#define HWIO_GENI_M_IRQ_EN_SET_M_CMD_ABORT_EN_SET_SHFT                                                    5
#define HWIO_GENI_M_IRQ_EN_SET_M_CMD_CANCEL_EN_SET_BMSK                                                0x10
#define HWIO_GENI_M_IRQ_EN_SET_M_CMD_CANCEL_EN_SET_SHFT                                                   4
#define HWIO_GENI_M_IRQ_EN_SET_M_CMD_FAILURE_EN_SET_BMSK                                                0x8
#define HWIO_GENI_M_IRQ_EN_SET_M_CMD_FAILURE_EN_SET_SHFT                                                  3
#define HWIO_GENI_M_IRQ_EN_SET_M_ILLEGAL_CMD_EN_SET_BMSK                                                0x4
#define HWIO_GENI_M_IRQ_EN_SET_M_ILLEGAL_CMD_EN_SET_SHFT                                                  2
#define HWIO_GENI_M_IRQ_EN_SET_M_CMD_OVERRUN_EN_SET_BMSK                                                0x2
#define HWIO_GENI_M_IRQ_EN_SET_M_CMD_OVERRUN_EN_SET_SHFT                                                  1
#define HWIO_GENI_M_IRQ_EN_SET_M_CMD_DONE_EN_SET_BMSK                                                   0x1
#define HWIO_GENI_M_IRQ_EN_SET_M_CMD_DONE_EN_SET_SHFT                                                     0

#define HWIO_GENI_M_IRQ_EN_CLEAR_ADDR                                                            (GENI4_DATA_REG_BASE            + 0x20)
#define HWIO_GENI_M_IRQ_EN_CLEAR_PHYS                                                            (GENI4_DATA_REG_BASE_PHYS + 0x20)
#define HWIO_GENI_M_IRQ_EN_CLEAR_OFFS                                                            (GENI4_DATA_REG_BASE_OFFS + 0x20)
#define HWIO_GENI_M_IRQ_EN_CLEAR_RMSK                                                            0xfff1ffff
#define HWIO_GENI_M_IRQ_EN_CLEAR_OUT(v)            \
                out_dword(HWIO_GENI_M_IRQ_EN_CLEAR_ADDR,v)
#define HWIO_GENI_M_IRQ_EN_CLEAR_SEC_IRQ_EN_CLEAR_BMSK                                           0x80000000
#define HWIO_GENI_M_IRQ_EN_CLEAR_SEC_IRQ_EN_CLEAR_SHFT                                                   31
#define HWIO_GENI_M_IRQ_EN_CLEAR_TX_FIFO_WATERMARK_EN_CLEAR_BMSK                                 0x40000000
#define HWIO_GENI_M_IRQ_EN_CLEAR_TX_FIFO_WATERMARK_EN_CLEAR_SHFT                                         30
#define HWIO_GENI_M_IRQ_EN_CLEAR_TX_FIFO_WR_ERR_EN_CLEAR_BMSK                                    0x20000000
#define HWIO_GENI_M_IRQ_EN_CLEAR_TX_FIFO_WR_ERR_EN_CLEAR_SHFT                                            29
#define HWIO_GENI_M_IRQ_EN_CLEAR_TX_FIFO_RD_ERR_EN_CLEAR_BMSK                                    0x10000000
#define HWIO_GENI_M_IRQ_EN_CLEAR_TX_FIFO_RD_ERR_EN_CLEAR_SHFT                                            28
#define HWIO_GENI_M_IRQ_EN_CLEAR_RX_FIFO_LAST_EN_CLEAR_BMSK                                       0x8000000
#define HWIO_GENI_M_IRQ_EN_CLEAR_RX_FIFO_LAST_EN_CLEAR_SHFT                                              27
#define HWIO_GENI_M_IRQ_EN_CLEAR_RX_FIFO_WATERMARK_EN_CLEAR_BMSK                                  0x4000000
#define HWIO_GENI_M_IRQ_EN_CLEAR_RX_FIFO_WATERMARK_EN_CLEAR_SHFT                                         26
#define HWIO_GENI_M_IRQ_EN_CLEAR_RX_FIFO_WR_ERR_EN_CLEAR_BMSK                                     0x2000000
#define HWIO_GENI_M_IRQ_EN_CLEAR_RX_FIFO_WR_ERR_EN_CLEAR_SHFT                                            25
#define HWIO_GENI_M_IRQ_EN_CLEAR_RX_FIFO_RD_ERR_EN_CLEAR_BMSK                                     0x1000000
#define HWIO_GENI_M_IRQ_EN_CLEAR_RX_FIFO_RD_ERR_EN_CLEAR_SHFT                                            24
#define HWIO_GENI_M_IRQ_EN_CLEAR_IO_DATA_ASSERT_EN_CLEAR_BMSK                                      0x800000
#define HWIO_GENI_M_IRQ_EN_CLEAR_IO_DATA_ASSERT_EN_CLEAR_SHFT                                            23
#define HWIO_GENI_M_IRQ_EN_CLEAR_IO_DATA_DEASSERT_EN_CLEAR_BMSK                                    0x400000
#define HWIO_GENI_M_IRQ_EN_CLEAR_IO_DATA_DEASSERT_EN_CLEAR_SHFT                                          22
#define HWIO_GENI_M_IRQ_EN_CLEAR_TX_FIFO_NOT_EMPTY_EN_CLEAR_BMSK                                   0x200000
#define HWIO_GENI_M_IRQ_EN_CLEAR_TX_FIFO_NOT_EMPTY_EN_CLEAR_SHFT                                         21
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_HW_IRQ_EN_CLEAR_BMSK                                            0x100000
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_HW_IRQ_EN_CLEAR_SHFT                                                  20
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_GP_IRQ_7_EN_CLEAR_BMSK                                           0x10000
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_GP_IRQ_7_EN_CLEAR_SHFT                                                16
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_GP_IRQ_6_EN_CLEAR_BMSK                                            0x8000
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_GP_IRQ_6_EN_CLEAR_SHFT                                                15
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_GP_IRQ_5_EN_CLEAR_BMSK                                            0x4000
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_GP_IRQ_5_EN_CLEAR_SHFT                                                14
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_GP_IRQ_4_EN_CLEAR_BMSK                                            0x2000
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_GP_IRQ_4_EN_CLEAR_SHFT                                                13
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_GP_IRQ_3_EN_CLEAR_BMSK                                            0x1000
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_GP_IRQ_3_EN_CLEAR_SHFT                                                12
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_GP_IRQ_2_EN_CLEAR_BMSK                                             0x800
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_GP_IRQ_2_EN_CLEAR_SHFT                                                11
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_GP_IRQ_1_EN_CLEAR_BMSK                                             0x400
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_GP_IRQ_1_EN_CLEAR_SHFT                                                10
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_GP_IRQ_0_EN_CLEAR_BMSK                                             0x200
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_GP_IRQ_0_EN_CLEAR_SHFT                                                 9
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_GP_SYNC_IRQ_0_EN_CLEAR_BMSK                                        0x100
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_GP_SYNC_IRQ_0_EN_CLEAR_SHFT                                            8
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_RX_IRQ_EN_CLEAR_BMSK                                                0x80
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_RX_IRQ_EN_CLEAR_SHFT                                                   7
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_TIMESTAMP_EN_CLEAR_BMSK                                             0x40
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_TIMESTAMP_EN_CLEAR_SHFT                                                6
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_CMD_ABORT_EN_CLEAR_BMSK                                             0x20
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_CMD_ABORT_EN_CLEAR_SHFT                                                5
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_CMD_CANCEL_EN_CLEAR_BMSK                                            0x10
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_CMD_CANCEL_EN_CLEAR_SHFT                                               4
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_CMD_FAILURE_EN_CLEAR_BMSK                                            0x8
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_CMD_FAILURE_EN_CLEAR_SHFT                                              3
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_ILLEGAL_CMD_EN_CLEAR_BMSK                                            0x4
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_ILLEGAL_CMD_EN_CLEAR_SHFT                                              2
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_CMD_OVERRUN_EN_CLEAR_BMSK                                            0x2
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_CMD_OVERRUN_EN_CLEAR_SHFT                                              1
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_CMD_DONE_EN_CLEAR_BMSK                                               0x1
#define HWIO_GENI_M_IRQ_EN_CLEAR_M_CMD_DONE_EN_CLEAR_SHFT                                                 0

#define HWIO_GENI_M_CMD_ERR_STATUS_ADDR                                                          (GENI4_DATA_REG_BASE            + 0x24)
#define HWIO_GENI_M_CMD_ERR_STATUS_PHYS                                                          (GENI4_DATA_REG_BASE_PHYS + 0x24)
#define HWIO_GENI_M_CMD_ERR_STATUS_OFFS                                                          (GENI4_DATA_REG_BASE_OFFS + 0x24)
#define HWIO_GENI_M_CMD_ERR_STATUS_RMSK                                                                 0xf
#define HWIO_GENI_M_CMD_ERR_STATUS_IN                    \
                in_dword(HWIO_GENI_M_CMD_ERR_STATUS_ADDR)
#define HWIO_GENI_M_CMD_ERR_STATUS_INM(m)            \
                in_dword_masked(HWIO_GENI_M_CMD_ERR_STATUS_ADDR, m)
#define HWIO_GENI_M_CMD_ERR_STATUS_GENI_M_CMD_ERR_CODE_BMSK                                             0xf
#define HWIO_GENI_M_CMD_ERR_STATUS_GENI_M_CMD_ERR_CODE_SHFT                                               0

#define HWIO_GENI_M_FW_ERR_STATUS_ADDR                                                           (GENI4_DATA_REG_BASE            + 0x28)
#define HWIO_GENI_M_FW_ERR_STATUS_PHYS                                                           (GENI4_DATA_REG_BASE_PHYS + 0x28)
#define HWIO_GENI_M_FW_ERR_STATUS_OFFS                                                           (GENI4_DATA_REG_BASE_OFFS + 0x28)
#define HWIO_GENI_M_FW_ERR_STATUS_RMSK                                                                  0xf
#define HWIO_GENI_M_FW_ERR_STATUS_IN                    \
                in_dword(HWIO_GENI_M_FW_ERR_STATUS_ADDR)
#define HWIO_GENI_M_FW_ERR_STATUS_INM(m)            \
                in_dword_masked(HWIO_GENI_M_FW_ERR_STATUS_ADDR, m)
#define HWIO_GENI_M_FW_ERR_STATUS_GENI_M_FW_ERR_CODE_BMSK                                               0xf
#define HWIO_GENI_M_FW_ERR_STATUS_GENI_M_FW_ERR_CODE_SHFT                                                 0

#define HWIO_GENI_S_CMD0_ADDR                                                                    (GENI4_DATA_REG_BASE            + 0x30)
#define HWIO_GENI_S_CMD0_PHYS                                                                    (GENI4_DATA_REG_BASE_PHYS + 0x30)
#define HWIO_GENI_S_CMD0_OFFS                                                                    (GENI4_DATA_REG_BASE_OFFS + 0x30)
#define HWIO_GENI_S_CMD0_RMSK                                                                    0xffffffff
#define HWIO_GENI_S_CMD0_IN                    \
                in_dword(HWIO_GENI_S_CMD0_ADDR)
#define HWIO_GENI_S_CMD0_INM(m)            \
                in_dword_masked(HWIO_GENI_S_CMD0_ADDR, m)
#define HWIO_GENI_S_CMD0_OUT(v)            \
                out_dword(HWIO_GENI_S_CMD0_ADDR,v)
#define HWIO_GENI_S_CMD0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_S_CMD0_ADDR,m,v,HWIO_GENI_S_CMD0_IN)
#define HWIO_GENI_S_CMD0_OPCODE_BMSK                                                             0xf8000000
#define HWIO_GENI_S_CMD0_OPCODE_SHFT                                                                     27
#define HWIO_GENI_S_CMD0_PARAM_BMSK                                                               0x7ffffff
#define HWIO_GENI_S_CMD0_PARAM_SHFT                                                                       0

#define HWIO_GENI_S_CMD_CTRL_REG_ADDR                                                            (GENI4_DATA_REG_BASE            + 0x34)
#define HWIO_GENI_S_CMD_CTRL_REG_PHYS                                                            (GENI4_DATA_REG_BASE_PHYS + 0x34)
#define HWIO_GENI_S_CMD_CTRL_REG_OFFS                                                            (GENI4_DATA_REG_BASE_OFFS + 0x34)
#define HWIO_GENI_S_CMD_CTRL_REG_RMSK                                                                   0x7
#define HWIO_GENI_S_CMD_CTRL_REG_IN                    \
                in_dword(HWIO_GENI_S_CMD_CTRL_REG_ADDR)
#define HWIO_GENI_S_CMD_CTRL_REG_INM(m)            \
                in_dword_masked(HWIO_GENI_S_CMD_CTRL_REG_ADDR, m)
#define HWIO_GENI_S_CMD_CTRL_REG_OUT(v)            \
                out_dword(HWIO_GENI_S_CMD_CTRL_REG_ADDR,v)
#define HWIO_GENI_S_CMD_CTRL_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_S_CMD_CTRL_REG_ADDR,m,v,HWIO_GENI_S_CMD_CTRL_REG_IN)
#define HWIO_GENI_S_CMD_CTRL_REG_S_GENI_CMD_CANCEL_BMSK                                                 0x4
#define HWIO_GENI_S_CMD_CTRL_REG_S_GENI_CMD_CANCEL_SHFT                                                   2
#define HWIO_GENI_S_CMD_CTRL_REG_S_GENI_CMD_ABORT_BMSK                                                  0x2
#define HWIO_GENI_S_CMD_CTRL_REG_S_GENI_CMD_ABORT_SHFT                                                    1
#define HWIO_GENI_S_CMD_CTRL_REG_S_GENI_DISABLE_BMSK                                                    0x1
#define HWIO_GENI_S_CMD_CTRL_REG_S_GENI_DISABLE_SHFT                                                      0

#define HWIO_GENI_S_IRQ_STATUS_ADDR                                                              (GENI4_DATA_REG_BASE            + 0x40)
#define HWIO_GENI_S_IRQ_STATUS_PHYS                                                              (GENI4_DATA_REG_BASE_PHYS + 0x40)
#define HWIO_GENI_S_IRQ_STATUS_OFFS                                                              (GENI4_DATA_REG_BASE_OFFS + 0x40)
#define HWIO_GENI_S_IRQ_STATUS_RMSK                                                               0xfc1ff3f
#define HWIO_GENI_S_IRQ_STATUS_IN                    \
                in_dword(HWIO_GENI_S_IRQ_STATUS_ADDR)
#define HWIO_GENI_S_IRQ_STATUS_INM(m)            \
                in_dword_masked(HWIO_GENI_S_IRQ_STATUS_ADDR, m)
#define HWIO_GENI_S_IRQ_STATUS_RX_FIFO_LAST_BMSK                                                  0x8000000
#define HWIO_GENI_S_IRQ_STATUS_RX_FIFO_LAST_SHFT                                                         27
#define HWIO_GENI_S_IRQ_STATUS_RX_FIFO_WATERMARK_BMSK                                             0x4000000
#define HWIO_GENI_S_IRQ_STATUS_RX_FIFO_WATERMARK_SHFT                                                    26
#define HWIO_GENI_S_IRQ_STATUS_RX_FIFO_WR_ERR_BMSK                                                0x2000000
#define HWIO_GENI_S_IRQ_STATUS_RX_FIFO_WR_ERR_SHFT                                                       25
#define HWIO_GENI_S_IRQ_STATUS_RX_FIFO_RD_ERR_BMSK                                                0x1000000
#define HWIO_GENI_S_IRQ_STATUS_RX_FIFO_RD_ERR_SHFT                                                       24
#define HWIO_GENI_S_IRQ_STATUS_IO_DATA_ASSERT_BMSK                                                 0x800000
#define HWIO_GENI_S_IRQ_STATUS_IO_DATA_ASSERT_SHFT                                                       23
#define HWIO_GENI_S_IRQ_STATUS_IO_DATA_DEASSERT_BMSK                                               0x400000
#define HWIO_GENI_S_IRQ_STATUS_IO_DATA_DEASSERT_SHFT                                                     22
#define HWIO_GENI_S_IRQ_STATUS_S_GP_IRQ_7_BMSK                                                      0x10000
#define HWIO_GENI_S_IRQ_STATUS_S_GP_IRQ_7_SHFT                                                           16
#define HWIO_GENI_S_IRQ_STATUS_S_GP_IRQ_6_BMSK                                                       0x8000
#define HWIO_GENI_S_IRQ_STATUS_S_GP_IRQ_6_SHFT                                                           15
#define HWIO_GENI_S_IRQ_STATUS_S_GP_IRQ_5_BMSK                                                       0x4000
#define HWIO_GENI_S_IRQ_STATUS_S_GP_IRQ_5_SHFT                                                           14
#define HWIO_GENI_S_IRQ_STATUS_S_GP_IRQ_4_BMSK                                                       0x2000
#define HWIO_GENI_S_IRQ_STATUS_S_GP_IRQ_4_SHFT                                                           13
#define HWIO_GENI_S_IRQ_STATUS_S_GP_IRQ_3_BMSK                                                       0x1000
#define HWIO_GENI_S_IRQ_STATUS_S_GP_IRQ_3_SHFT                                                           12
#define HWIO_GENI_S_IRQ_STATUS_S_GP_IRQ_2_BMSK                                                        0x800
#define HWIO_GENI_S_IRQ_STATUS_S_GP_IRQ_2_SHFT                                                           11
#define HWIO_GENI_S_IRQ_STATUS_S_GP_IRQ_1_BMSK                                                        0x400
#define HWIO_GENI_S_IRQ_STATUS_S_GP_IRQ_1_SHFT                                                           10
#define HWIO_GENI_S_IRQ_STATUS_S_GP_IRQ_0_BMSK                                                        0x200
#define HWIO_GENI_S_IRQ_STATUS_S_GP_IRQ_0_SHFT                                                            9
#define HWIO_GENI_S_IRQ_STATUS_S_GP_SYNC_IRQ_0_BMSK                                                   0x100
#define HWIO_GENI_S_IRQ_STATUS_S_GP_SYNC_IRQ_0_SHFT                                                       8
#define HWIO_GENI_S_IRQ_STATUS_S_CMD_ABORT_BMSK                                                        0x20
#define HWIO_GENI_S_IRQ_STATUS_S_CMD_ABORT_SHFT                                                           5
#define HWIO_GENI_S_IRQ_STATUS_S_CMD_CANCEL_BMSK                                                       0x10
#define HWIO_GENI_S_IRQ_STATUS_S_CMD_CANCEL_SHFT                                                          4
#define HWIO_GENI_S_IRQ_STATUS_S_CMD_FAILURE_BMSK                                                       0x8
#define HWIO_GENI_S_IRQ_STATUS_S_CMD_FAILURE_SHFT                                                         3
#define HWIO_GENI_S_IRQ_STATUS_S_ILLEGAL_CMD_BMSK                                                       0x4
#define HWIO_GENI_S_IRQ_STATUS_S_ILLEGAL_CMD_SHFT                                                         2
#define HWIO_GENI_S_IRQ_STATUS_S_CMD_OVERRUN_BMSK                                                       0x2
#define HWIO_GENI_S_IRQ_STATUS_S_CMD_OVERRUN_SHFT                                                         1
#define HWIO_GENI_S_IRQ_STATUS_S_CMD_DONE_BMSK                                                          0x1
#define HWIO_GENI_S_IRQ_STATUS_S_CMD_DONE_SHFT                                                            0

#define HWIO_GENI_S_IRQ_ENABLE_ADDR                                                              (GENI4_DATA_REG_BASE            + 0x44)
#define HWIO_GENI_S_IRQ_ENABLE_PHYS                                                              (GENI4_DATA_REG_BASE_PHYS + 0x44)
#define HWIO_GENI_S_IRQ_ENABLE_OFFS                                                              (GENI4_DATA_REG_BASE_OFFS + 0x44)
#define HWIO_GENI_S_IRQ_ENABLE_RMSK                                                               0xfc1ff3f
#define HWIO_GENI_S_IRQ_ENABLE_IN                    \
                in_dword(HWIO_GENI_S_IRQ_ENABLE_ADDR)
#define HWIO_GENI_S_IRQ_ENABLE_INM(m)            \
                in_dword_masked(HWIO_GENI_S_IRQ_ENABLE_ADDR, m)
#define HWIO_GENI_S_IRQ_ENABLE_OUT(v)            \
                out_dword(HWIO_GENI_S_IRQ_ENABLE_ADDR,v)
#define HWIO_GENI_S_IRQ_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_S_IRQ_ENABLE_ADDR,m,v,HWIO_GENI_S_IRQ_ENABLE_IN)
#define HWIO_GENI_S_IRQ_ENABLE_RX_FIFO_LAST_EN_BMSK                                               0x8000000
#define HWIO_GENI_S_IRQ_ENABLE_RX_FIFO_LAST_EN_SHFT                                                      27
#define HWIO_GENI_S_IRQ_ENABLE_RX_FIFO_WATERMARK_EN_BMSK                                          0x4000000
#define HWIO_GENI_S_IRQ_ENABLE_RX_FIFO_WATERMARK_EN_SHFT                                                 26
#define HWIO_GENI_S_IRQ_ENABLE_RX_FIFO_WR_ERR_EN_BMSK                                             0x2000000
#define HWIO_GENI_S_IRQ_ENABLE_RX_FIFO_WR_ERR_EN_SHFT                                                    25
#define HWIO_GENI_S_IRQ_ENABLE_RX_FIFO_RD_ERR_EN_BMSK                                             0x1000000
#define HWIO_GENI_S_IRQ_ENABLE_RX_FIFO_RD_ERR_EN_SHFT                                                    24
#define HWIO_GENI_S_IRQ_ENABLE_IO_DATA_ASSERT_EN_BMSK                                              0x800000
#define HWIO_GENI_S_IRQ_ENABLE_IO_DATA_ASSERT_EN_SHFT                                                    23
#define HWIO_GENI_S_IRQ_ENABLE_IO_DATA_DEASSERT_EN_BMSK                                            0x400000
#define HWIO_GENI_S_IRQ_ENABLE_IO_DATA_DEASSERT_EN_SHFT                                                  22
#define HWIO_GENI_S_IRQ_ENABLE_S_GP_IRQ_7_EN_BMSK                                                   0x10000
#define HWIO_GENI_S_IRQ_ENABLE_S_GP_IRQ_7_EN_SHFT                                                        16
#define HWIO_GENI_S_IRQ_ENABLE_S_GP_IRQ_6_EN_BMSK                                                    0x8000
#define HWIO_GENI_S_IRQ_ENABLE_S_GP_IRQ_6_EN_SHFT                                                        15
#define HWIO_GENI_S_IRQ_ENABLE_S_GP_IRQ_5_EN_BMSK                                                    0x4000
#define HWIO_GENI_S_IRQ_ENABLE_S_GP_IRQ_5_EN_SHFT                                                        14
#define HWIO_GENI_S_IRQ_ENABLE_S_GP_IRQ_4_EN_BMSK                                                    0x2000
#define HWIO_GENI_S_IRQ_ENABLE_S_GP_IRQ_4_EN_SHFT                                                        13
#define HWIO_GENI_S_IRQ_ENABLE_S_GP_IRQ_3_EN_BMSK                                                    0x1000
#define HWIO_GENI_S_IRQ_ENABLE_S_GP_IRQ_3_EN_SHFT                                                        12
#define HWIO_GENI_S_IRQ_ENABLE_S_GP_IRQ_2_EN_BMSK                                                     0x800
#define HWIO_GENI_S_IRQ_ENABLE_S_GP_IRQ_2_EN_SHFT                                                        11
#define HWIO_GENI_S_IRQ_ENABLE_S_GP_IRQ_1_EN_BMSK                                                     0x400
#define HWIO_GENI_S_IRQ_ENABLE_S_GP_IRQ_1_EN_SHFT                                                        10
#define HWIO_GENI_S_IRQ_ENABLE_S_GP_IRQ_0_EN_BMSK                                                     0x200
#define HWIO_GENI_S_IRQ_ENABLE_S_GP_IRQ_0_EN_SHFT                                                         9
#define HWIO_GENI_S_IRQ_ENABLE_S_GP_SYNC_IRQ_0_EN_BMSK                                                0x100
#define HWIO_GENI_S_IRQ_ENABLE_S_GP_SYNC_IRQ_0_EN_SHFT                                                    8
#define HWIO_GENI_S_IRQ_ENABLE_S_CMD_ABORT_EN_BMSK                                                     0x20
#define HWIO_GENI_S_IRQ_ENABLE_S_CMD_ABORT_EN_SHFT                                                        5
#define HWIO_GENI_S_IRQ_ENABLE_S_CMD_CANCEL_EN_BMSK                                                    0x10
#define HWIO_GENI_S_IRQ_ENABLE_S_CMD_CANCEL_EN_SHFT                                                       4
#define HWIO_GENI_S_IRQ_ENABLE_S_CMD_FAILURE_EN_BMSK                                                    0x8
#define HWIO_GENI_S_IRQ_ENABLE_S_CMD_FAILURE_EN_SHFT                                                      3
#define HWIO_GENI_S_IRQ_ENABLE_S_ILLEGAL_CMD_EN_BMSK                                                    0x4
#define HWIO_GENI_S_IRQ_ENABLE_S_ILLEGAL_CMD_EN_SHFT                                                      2
#define HWIO_GENI_S_IRQ_ENABLE_S_CMD_OVERRUN_EN_BMSK                                                    0x2
#define HWIO_GENI_S_IRQ_ENABLE_S_CMD_OVERRUN_EN_SHFT                                                      1
#define HWIO_GENI_S_IRQ_ENABLE_S_CMD_DONE_EN_BMSK                                                       0x1
#define HWIO_GENI_S_IRQ_ENABLE_S_CMD_DONE_EN_SHFT                                                         0

#define HWIO_GENI_S_IRQ_CLEAR_ADDR                                                               (GENI4_DATA_REG_BASE            + 0x48)
#define HWIO_GENI_S_IRQ_CLEAR_PHYS                                                               (GENI4_DATA_REG_BASE_PHYS + 0x48)
#define HWIO_GENI_S_IRQ_CLEAR_OFFS                                                               (GENI4_DATA_REG_BASE_OFFS + 0x48)
#define HWIO_GENI_S_IRQ_CLEAR_RMSK                                                                0xfc1ff3f
#define HWIO_GENI_S_IRQ_CLEAR_OUT(v)            \
                out_dword(HWIO_GENI_S_IRQ_CLEAR_ADDR,v)
#define HWIO_GENI_S_IRQ_CLEAR_RX_FIFO_LAST_CLEAR_BMSK                                             0x8000000
#define HWIO_GENI_S_IRQ_CLEAR_RX_FIFO_LAST_CLEAR_SHFT                                                    27
#define HWIO_GENI_S_IRQ_CLEAR_RX_FIFO_WATERMARK_CLEAR_BMSK                                        0x4000000
#define HWIO_GENI_S_IRQ_CLEAR_RX_FIFO_WATERMARK_CLEAR_SHFT                                               26
#define HWIO_GENI_S_IRQ_CLEAR_RX_FIFO_WR_ERR_CLEAR_BMSK                                           0x2000000
#define HWIO_GENI_S_IRQ_CLEAR_RX_FIFO_WR_ERR_CLEAR_SHFT                                                  25
#define HWIO_GENI_S_IRQ_CLEAR_RX_FIFO_RD_ERR_CLEAR_BMSK                                           0x1000000
#define HWIO_GENI_S_IRQ_CLEAR_RX_FIFO_RD_ERR_CLEAR_SHFT                                                  24
#define HWIO_GENI_S_IRQ_CLEAR_IO_DATA_ASSERT_CLEAR_BMSK                                            0x800000
#define HWIO_GENI_S_IRQ_CLEAR_IO_DATA_ASSERT_CLEAR_SHFT                                                  23
#define HWIO_GENI_S_IRQ_CLEAR_IO_DATA_DEASSERT_CLEAR_BMSK                                          0x400000
#define HWIO_GENI_S_IRQ_CLEAR_IO_DATA_DEASSERT_CLEAR_SHFT                                                22
#define HWIO_GENI_S_IRQ_CLEAR_S_GP_IRQ_7_CLEAR_BMSK                                                 0x10000
#define HWIO_GENI_S_IRQ_CLEAR_S_GP_IRQ_7_CLEAR_SHFT                                                      16
#define HWIO_GENI_S_IRQ_CLEAR_S_GP_IRQ_6_CLEAR_BMSK                                                  0x8000
#define HWIO_GENI_S_IRQ_CLEAR_S_GP_IRQ_6_CLEAR_SHFT                                                      15
#define HWIO_GENI_S_IRQ_CLEAR_S_GP_IRQ_5_CLEAR_BMSK                                                  0x4000
#define HWIO_GENI_S_IRQ_CLEAR_S_GP_IRQ_5_CLEAR_SHFT                                                      14
#define HWIO_GENI_S_IRQ_CLEAR_S_GP_IRQ_4_CLEAR_BMSK                                                  0x2000
#define HWIO_GENI_S_IRQ_CLEAR_S_GP_IRQ_4_CLEAR_SHFT                                                      13
#define HWIO_GENI_S_IRQ_CLEAR_S_GP_IRQ_3_CLEAR_BMSK                                                  0x1000
#define HWIO_GENI_S_IRQ_CLEAR_S_GP_IRQ_3_CLEAR_SHFT                                                      12
#define HWIO_GENI_S_IRQ_CLEAR_S_GP_IRQ_2_CLEAR_BMSK                                                   0x800
#define HWIO_GENI_S_IRQ_CLEAR_S_GP_IRQ_2_CLEAR_SHFT                                                      11
#define HWIO_GENI_S_IRQ_CLEAR_S_GP_IRQ_1_CLEAR_BMSK                                                   0x400
#define HWIO_GENI_S_IRQ_CLEAR_S_GP_IRQ_1_CLEAR_SHFT                                                      10
#define HWIO_GENI_S_IRQ_CLEAR_S_GP_IRQ_0_CLEAR_BMSK                                                   0x200
#define HWIO_GENI_S_IRQ_CLEAR_S_GP_IRQ_0_CLEAR_SHFT                                                       9
#define HWIO_GENI_S_IRQ_CLEAR_S_GP_SYNC_IRQ_0_CLEAR_BMSK                                              0x100
#define HWIO_GENI_S_IRQ_CLEAR_S_GP_SYNC_IRQ_0_CLEAR_SHFT                                                  8
#define HWIO_GENI_S_IRQ_CLEAR_S_CMD_ABORT_CLEAR_BMSK                                                   0x20
#define HWIO_GENI_S_IRQ_CLEAR_S_CMD_ABORT_CLEAR_SHFT                                                      5
#define HWIO_GENI_S_IRQ_CLEAR_S_CMD_CANCEL_CLEAR_BMSK                                                  0x10
#define HWIO_GENI_S_IRQ_CLEAR_S_CMD_CANCEL_CLEAR_SHFT                                                     4
#define HWIO_GENI_S_IRQ_CLEAR_S_CMD_FAILURE_CLEAR_BMSK                                                  0x8
#define HWIO_GENI_S_IRQ_CLEAR_S_CMD_FAILURE_CLEAR_SHFT                                                    3
#define HWIO_GENI_S_IRQ_CLEAR_S_ILLEGAL_CMD_CLEAR_BMSK                                                  0x4
#define HWIO_GENI_S_IRQ_CLEAR_S_ILLEGAL_CMD_CLEAR_SHFT                                                    2
#define HWIO_GENI_S_IRQ_CLEAR_S_CMD_OVERRUN_CLEAR_BMSK                                                  0x2
#define HWIO_GENI_S_IRQ_CLEAR_S_CMD_OVERRUN_CLEAR_SHFT                                                    1
#define HWIO_GENI_S_IRQ_CLEAR_S_CMD_DONE_CLEAR_BMSK                                                     0x1
#define HWIO_GENI_S_IRQ_CLEAR_S_CMD_DONE_CLEAR_SHFT                                                       0

#define HWIO_GENI_S_IRQ_EN_SET_ADDR                                                              (GENI4_DATA_REG_BASE            + 0x4c)
#define HWIO_GENI_S_IRQ_EN_SET_PHYS                                                              (GENI4_DATA_REG_BASE_PHYS + 0x4c)
#define HWIO_GENI_S_IRQ_EN_SET_OFFS                                                              (GENI4_DATA_REG_BASE_OFFS + 0x4c)
#define HWIO_GENI_S_IRQ_EN_SET_RMSK                                                               0xfc1ff3f
#define HWIO_GENI_S_IRQ_EN_SET_OUT(v)            \
                out_dword(HWIO_GENI_S_IRQ_EN_SET_ADDR,v)
#define HWIO_GENI_S_IRQ_EN_SET_RX_FIFO_LAST_EN_SET_BMSK                                           0x8000000
#define HWIO_GENI_S_IRQ_EN_SET_RX_FIFO_LAST_EN_SET_SHFT                                                  27
#define HWIO_GENI_S_IRQ_EN_SET_RX_FIFO_WATERMARK_EN_SET_BMSK                                      0x4000000
#define HWIO_GENI_S_IRQ_EN_SET_RX_FIFO_WATERMARK_EN_SET_SHFT                                             26
#define HWIO_GENI_S_IRQ_EN_SET_RX_FIFO_WR_ERR_EN_SET_BMSK                                         0x2000000
#define HWIO_GENI_S_IRQ_EN_SET_RX_FIFO_WR_ERR_EN_SET_SHFT                                                25
#define HWIO_GENI_S_IRQ_EN_SET_RX_FIFO_RD_ERR_EN_SET_BMSK                                         0x1000000
#define HWIO_GENI_S_IRQ_EN_SET_RX_FIFO_RD_ERR_EN_SET_SHFT                                                24
#define HWIO_GENI_S_IRQ_EN_SET_IO_DATA_ASSERT_EN_SET_BMSK                                          0x800000
#define HWIO_GENI_S_IRQ_EN_SET_IO_DATA_ASSERT_EN_SET_SHFT                                                23
#define HWIO_GENI_S_IRQ_EN_SET_IO_DATA_DEASSERT_EN_SET_BMSK                                        0x400000
#define HWIO_GENI_S_IRQ_EN_SET_IO_DATA_DEASSERT_EN_SET_SHFT                                              22
#define HWIO_GENI_S_IRQ_EN_SET_S_GP_IRQ_7_EN_SET_BMSK                                               0x10000
#define HWIO_GENI_S_IRQ_EN_SET_S_GP_IRQ_7_EN_SET_SHFT                                                    16
#define HWIO_GENI_S_IRQ_EN_SET_S_GP_IRQ_6_EN_SET_BMSK                                                0x8000
#define HWIO_GENI_S_IRQ_EN_SET_S_GP_IRQ_6_EN_SET_SHFT                                                    15
#define HWIO_GENI_S_IRQ_EN_SET_S_GP_IRQ_5_EN_SET_BMSK                                                0x4000
#define HWIO_GENI_S_IRQ_EN_SET_S_GP_IRQ_5_EN_SET_SHFT                                                    14
#define HWIO_GENI_S_IRQ_EN_SET_S_GP_IRQ_4_EN_SET_BMSK                                                0x2000
#define HWIO_GENI_S_IRQ_EN_SET_S_GP_IRQ_4_EN_SET_SHFT                                                    13
#define HWIO_GENI_S_IRQ_EN_SET_S_GP_IRQ_3_EN_SET_BMSK                                                0x1000
#define HWIO_GENI_S_IRQ_EN_SET_S_GP_IRQ_3_EN_SET_SHFT                                                    12
#define HWIO_GENI_S_IRQ_EN_SET_S_GP_IRQ_2_EN_SET_BMSK                                                 0x800
#define HWIO_GENI_S_IRQ_EN_SET_S_GP_IRQ_2_EN_SET_SHFT                                                    11
#define HWIO_GENI_S_IRQ_EN_SET_S_GP_IRQ_1_EN_SET_BMSK                                                 0x400
#define HWIO_GENI_S_IRQ_EN_SET_S_GP_IRQ_1_EN_SET_SHFT                                                    10
#define HWIO_GENI_S_IRQ_EN_SET_S_GP_IRQ_0_EN_SET_BMSK                                                 0x200
#define HWIO_GENI_S_IRQ_EN_SET_S_GP_IRQ_0_EN_SET_SHFT                                                     9
#define HWIO_GENI_S_IRQ_EN_SET_S_GP_SYNC_IRQ_0_EN_SET_BMSK                                            0x100
#define HWIO_GENI_S_IRQ_EN_SET_S_GP_SYNC_IRQ_0_EN_SET_SHFT                                                8
#define HWIO_GENI_S_IRQ_EN_SET_S_CMD_ABORT_EN_SET_BMSK                                                 0x20
#define HWIO_GENI_S_IRQ_EN_SET_S_CMD_ABORT_EN_SET_SHFT                                                    5
#define HWIO_GENI_S_IRQ_EN_SET_S_CMD_CANCEL_EN_SET_BMSK                                                0x10
#define HWIO_GENI_S_IRQ_EN_SET_S_CMD_CANCEL_EN_SET_SHFT                                                   4
#define HWIO_GENI_S_IRQ_EN_SET_S_CMD_FAILURE_EN_SET_BMSK                                                0x8
#define HWIO_GENI_S_IRQ_EN_SET_S_CMD_FAILURE_EN_SET_SHFT                                                  3
#define HWIO_GENI_S_IRQ_EN_SET_S_ILLEGAL_CMD_EN_SET_BMSK                                                0x4
#define HWIO_GENI_S_IRQ_EN_SET_S_ILLEGAL_CMD_EN_SET_SHFT                                                  2
#define HWIO_GENI_S_IRQ_EN_SET_S_CMD_OVERRUN_EN_SET_BMSK                                                0x2
#define HWIO_GENI_S_IRQ_EN_SET_S_CMD_OVERRUN_EN_SET_SHFT                                                  1
#define HWIO_GENI_S_IRQ_EN_SET_S_CMD_DONE_EN_SET_BMSK                                                   0x1
#define HWIO_GENI_S_IRQ_EN_SET_S_CMD_DONE_EN_SET_SHFT                                                     0

#define HWIO_GENI_S_IRQ_EN_CLEAR_ADDR                                                            (GENI4_DATA_REG_BASE            + 0x50)
#define HWIO_GENI_S_IRQ_EN_CLEAR_PHYS                                                            (GENI4_DATA_REG_BASE_PHYS + 0x50)
#define HWIO_GENI_S_IRQ_EN_CLEAR_OFFS                                                            (GENI4_DATA_REG_BASE_OFFS + 0x50)
#define HWIO_GENI_S_IRQ_EN_CLEAR_RMSK                                                             0xfc1ff3f
#define HWIO_GENI_S_IRQ_EN_CLEAR_OUT(v)            \
                out_dword(HWIO_GENI_S_IRQ_EN_CLEAR_ADDR,v)
#define HWIO_GENI_S_IRQ_EN_CLEAR_RX_FIFO_LAST_EN_CLEAR_BMSK                                       0x8000000
#define HWIO_GENI_S_IRQ_EN_CLEAR_RX_FIFO_LAST_EN_CLEAR_SHFT                                              27
#define HWIO_GENI_S_IRQ_EN_CLEAR_RX_FIFO_WATERMARK_EN_CLEAR_BMSK                                  0x4000000
#define HWIO_GENI_S_IRQ_EN_CLEAR_RX_FIFO_WATERMARK_EN_CLEAR_SHFT                                         26
#define HWIO_GENI_S_IRQ_EN_CLEAR_RX_FIFO_WR_ERR_EN_CLEAR_BMSK                                     0x2000000
#define HWIO_GENI_S_IRQ_EN_CLEAR_RX_FIFO_WR_ERR_EN_CLEAR_SHFT                                            25
#define HWIO_GENI_S_IRQ_EN_CLEAR_RX_FIFO_RD_ERR_EN_CLEAR_BMSK                                     0x1000000
#define HWIO_GENI_S_IRQ_EN_CLEAR_RX_FIFO_RD_ERR_EN_CLEAR_SHFT                                            24
#define HWIO_GENI_S_IRQ_EN_CLEAR_IO_DATA_ASSERT_EN_CLEAR_BMSK                                      0x800000
#define HWIO_GENI_S_IRQ_EN_CLEAR_IO_DATA_ASSERT_EN_CLEAR_SHFT                                            23
#define HWIO_GENI_S_IRQ_EN_CLEAR_IO_DATA_DEASSERT_EN_CLEAR_BMSK                                    0x400000
#define HWIO_GENI_S_IRQ_EN_CLEAR_IO_DATA_DEASSERT_EN_CLEAR_SHFT                                          22
#define HWIO_GENI_S_IRQ_EN_CLEAR_S_GP_IRQ_7_EN_CLEAR_BMSK                                           0x10000
#define HWIO_GENI_S_IRQ_EN_CLEAR_S_GP_IRQ_7_EN_CLEAR_SHFT                                                16
#define HWIO_GENI_S_IRQ_EN_CLEAR_S_GP_IRQ_6_EN_CLEAR_BMSK                                            0x8000
#define HWIO_GENI_S_IRQ_EN_CLEAR_S_GP_IRQ_6_EN_CLEAR_SHFT                                                15
#define HWIO_GENI_S_IRQ_EN_CLEAR_S_GP_IRQ_5_EN_CLEAR_BMSK                                            0x4000
#define HWIO_GENI_S_IRQ_EN_CLEAR_S_GP_IRQ_5_EN_CLEAR_SHFT                                                14
#define HWIO_GENI_S_IRQ_EN_CLEAR_S_GP_IRQ_4_EN_CLEAR_BMSK                                            0x2000
#define HWIO_GENI_S_IRQ_EN_CLEAR_S_GP_IRQ_4_EN_CLEAR_SHFT                                                13
#define HWIO_GENI_S_IRQ_EN_CLEAR_S_GP_IRQ_3_EN_CLEAR_BMSK                                            0x1000
#define HWIO_GENI_S_IRQ_EN_CLEAR_S_GP_IRQ_3_EN_CLEAR_SHFT                                                12
#define HWIO_GENI_S_IRQ_EN_CLEAR_S_GP_IRQ_2_EN_CLEAR_BMSK                                             0x800
#define HWIO_GENI_S_IRQ_EN_CLEAR_S_GP_IRQ_2_EN_CLEAR_SHFT                                                11
#define HWIO_GENI_S_IRQ_EN_CLEAR_S_GP_IRQ_1_EN_CLEAR_BMSK                                             0x400
#define HWIO_GENI_S_IRQ_EN_CLEAR_S_GP_IRQ_1_EN_CLEAR_SHFT                                                10
#define HWIO_GENI_S_IRQ_EN_CLEAR_S_GP_IRQ_0_EN_CLEAR_BMSK                                             0x200
#define HWIO_GENI_S_IRQ_EN_CLEAR_S_GP_IRQ_0_EN_CLEAR_SHFT                                                 9
#define HWIO_GENI_S_IRQ_EN_CLEAR_S_GP_SYNC_IRQ_0_EN_CLEAR_BMSK                                        0x100
#define HWIO_GENI_S_IRQ_EN_CLEAR_S_GP_SYNC_IRQ_0_EN_CLEAR_SHFT                                            8
#define HWIO_GENI_S_IRQ_EN_CLEAR_S_CMD_ABORT_EN_CLEAR_BMSK                                             0x20
#define HWIO_GENI_S_IRQ_EN_CLEAR_S_CMD_ABORT_EN_CLEAR_SHFT                                                5
#define HWIO_GENI_S_IRQ_EN_CLEAR_S_CMD_CANCEL_EN_CLEAR_BMSK                                            0x10
#define HWIO_GENI_S_IRQ_EN_CLEAR_S_CMD_CANCEL_EN_CLEAR_SHFT                                               4
#define HWIO_GENI_S_IRQ_EN_CLEAR_S_CMD_FAILURE_EN_CLEAR_BMSK                                            0x8
#define HWIO_GENI_S_IRQ_EN_CLEAR_S_CMD_FAILURE_EN_CLEAR_SHFT                                              3
#define HWIO_GENI_S_IRQ_EN_CLEAR_S_ILLEGAL_CMD_EN_CLEAR_BMSK                                            0x4
#define HWIO_GENI_S_IRQ_EN_CLEAR_S_ILLEGAL_CMD_EN_CLEAR_SHFT                                              2
#define HWIO_GENI_S_IRQ_EN_CLEAR_S_CMD_OVERRUN_EN_CLEAR_BMSK                                            0x2
#define HWIO_GENI_S_IRQ_EN_CLEAR_S_CMD_OVERRUN_EN_CLEAR_SHFT                                              1
#define HWIO_GENI_S_IRQ_EN_CLEAR_S_CMD_DONE_EN_CLEAR_BMSK                                               0x1
#define HWIO_GENI_S_IRQ_EN_CLEAR_S_CMD_DONE_EN_CLEAR_SHFT                                                 0

#define HWIO_GENI_M_HW_IRQ_STATUS_ADDR                                                           (GENI4_DATA_REG_BASE            + 0x60)
#define HWIO_GENI_M_HW_IRQ_STATUS_PHYS                                                           (GENI4_DATA_REG_BASE_PHYS + 0x60)
#define HWIO_GENI_M_HW_IRQ_STATUS_OFFS                                                           (GENI4_DATA_REG_BASE_OFFS + 0x60)
#define HWIO_GENI_M_HW_IRQ_STATUS_RMSK                                                                  0x7
#define HWIO_GENI_M_HW_IRQ_STATUS_IN                    \
                in_dword(HWIO_GENI_M_HW_IRQ_STATUS_ADDR)
#define HWIO_GENI_M_HW_IRQ_STATUS_INM(m)            \
                in_dword_masked(HWIO_GENI_M_HW_IRQ_STATUS_ADDR, m)
#define HWIO_GENI_M_HW_IRQ_STATUS_M_RX_DATA_IRQ_BMSK                                                    0x4
#define HWIO_GENI_M_HW_IRQ_STATUS_M_RX_DATA_IRQ_SHFT                                                      2
#define HWIO_GENI_M_HW_IRQ_STATUS_M_IO3_IRQ_BMSK                                                        0x2
#define HWIO_GENI_M_HW_IRQ_STATUS_M_IO3_IRQ_SHFT                                                          1
#define HWIO_GENI_M_HW_IRQ_STATUS_M_IO2_IRQ_BMSK                                                        0x1
#define HWIO_GENI_M_HW_IRQ_STATUS_M_IO2_IRQ_SHFT                                                          0

#define HWIO_GENI_M_HW_IRQ_ENABLE_ADDR                                                           (GENI4_DATA_REG_BASE            + 0x64)
#define HWIO_GENI_M_HW_IRQ_ENABLE_PHYS                                                           (GENI4_DATA_REG_BASE_PHYS + 0x64)
#define HWIO_GENI_M_HW_IRQ_ENABLE_OFFS                                                           (GENI4_DATA_REG_BASE_OFFS + 0x64)
#define HWIO_GENI_M_HW_IRQ_ENABLE_RMSK                                                                  0x7
#define HWIO_GENI_M_HW_IRQ_ENABLE_IN                    \
                in_dword(HWIO_GENI_M_HW_IRQ_ENABLE_ADDR)
#define HWIO_GENI_M_HW_IRQ_ENABLE_INM(m)            \
                in_dword_masked(HWIO_GENI_M_HW_IRQ_ENABLE_ADDR, m)
#define HWIO_GENI_M_HW_IRQ_ENABLE_OUT(v)            \
                out_dword(HWIO_GENI_M_HW_IRQ_ENABLE_ADDR,v)
#define HWIO_GENI_M_HW_IRQ_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_M_HW_IRQ_ENABLE_ADDR,m,v,HWIO_GENI_M_HW_IRQ_ENABLE_IN)
#define HWIO_GENI_M_HW_IRQ_ENABLE_M_RX_DATA_IRQ_EN_BMSK                                                 0x4
#define HWIO_GENI_M_HW_IRQ_ENABLE_M_RX_DATA_IRQ_EN_SHFT                                                   2
#define HWIO_GENI_M_HW_IRQ_ENABLE_M_IO3_IRQ_EN_BMSK                                                     0x2
#define HWIO_GENI_M_HW_IRQ_ENABLE_M_IO3_IRQ_EN_SHFT                                                       1
#define HWIO_GENI_M_HW_IRQ_ENABLE_M_IO2_IRQ_EN_BMSK                                                     0x1
#define HWIO_GENI_M_HW_IRQ_ENABLE_M_IO2_IRQ_EN_SHFT                                                       0

#define HWIO_GENI_M_HW_IRQ_CLEAR_ADDR                                                            (GENI4_DATA_REG_BASE            + 0x68)
#define HWIO_GENI_M_HW_IRQ_CLEAR_PHYS                                                            (GENI4_DATA_REG_BASE_PHYS + 0x68)
#define HWIO_GENI_M_HW_IRQ_CLEAR_OFFS                                                            (GENI4_DATA_REG_BASE_OFFS + 0x68)
#define HWIO_GENI_M_HW_IRQ_CLEAR_RMSK                                                                   0x7
#define HWIO_GENI_M_HW_IRQ_CLEAR_OUT(v)            \
                out_dword(HWIO_GENI_M_HW_IRQ_CLEAR_ADDR,v)
#define HWIO_GENI_M_HW_IRQ_CLEAR_M_RX_DATA_IRQ_CLEAR_BMSK                                               0x4
#define HWIO_GENI_M_HW_IRQ_CLEAR_M_RX_DATA_IRQ_CLEAR_SHFT                                                 2
#define HWIO_GENI_M_HW_IRQ_CLEAR_M_IO3_IRQ_CLEAR_BMSK                                                   0x2
#define HWIO_GENI_M_HW_IRQ_CLEAR_M_IO3_IRQ_CLEAR_SHFT                                                     1
#define HWIO_GENI_M_HW_IRQ_CLEAR_M_IO2_IRQ_CLEAR_BMSK                                                   0x1
#define HWIO_GENI_M_HW_IRQ_CLEAR_M_IO2_IRQ_CLEAR_SHFT                                                     0

#define HWIO_GENI_SPMI_GPIO_CONTROL_ADDR                                                         (GENI4_DATA_REG_BASE            + 0x70)
#define HWIO_GENI_SPMI_GPIO_CONTROL_PHYS                                                         (GENI4_DATA_REG_BASE_PHYS + 0x70)
#define HWIO_GENI_SPMI_GPIO_CONTROL_OFFS                                                         (GENI4_DATA_REG_BASE_OFFS + 0x70)
#define HWIO_GENI_SPMI_GPIO_CONTROL_RMSK                                                                0x3
#define HWIO_GENI_SPMI_GPIO_CONTROL_IN                    \
                in_dword(HWIO_GENI_SPMI_GPIO_CONTROL_ADDR)
#define HWIO_GENI_SPMI_GPIO_CONTROL_INM(m)            \
                in_dword_masked(HWIO_GENI_SPMI_GPIO_CONTROL_ADDR, m)
#define HWIO_GENI_SPMI_GPIO_CONTROL_OUT(v)            \
                out_dword(HWIO_GENI_SPMI_GPIO_CONTROL_ADDR,v)
#define HWIO_GENI_SPMI_GPIO_CONTROL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_SPMI_GPIO_CONTROL_ADDR,m,v,HWIO_GENI_SPMI_GPIO_CONTROL_IN)
#define HWIO_GENI_SPMI_GPIO_CONTROL_SPMI_GPIO_HIZ_CTRL_BMSK                                             0x2
#define HWIO_GENI_SPMI_GPIO_CONTROL_SPMI_GPIO_HIZ_CTRL_SHFT                                               1
#define HWIO_GENI_SPMI_GPIO_CONTROL_SPMI_GPIO_MODE_EN_BMSK                                              0x1
#define HWIO_GENI_SPMI_GPIO_CONTROL_SPMI_GPIO_MODE_EN_SHFT                                                0

#define HWIO_GENI_TX_FIFOn_ADDR(n)                                                               (GENI4_DATA_REG_BASE            + 0X100 + (0x4*(n)))
#define HWIO_GENI_TX_FIFOn_PHYS(n)                                                               (GENI4_DATA_REG_BASE_PHYS + 0X100 + (0x4*(n)))
#define HWIO_GENI_TX_FIFOn_OFFS(n)                                                               (GENI4_DATA_REG_BASE_OFFS + 0X100 + (0x4*(n)))
#define HWIO_GENI_TX_FIFOn_RMSK                                                                  0xffffffff
#define HWIO_GENI_TX_FIFOn_MAXn                                                                          15
#define HWIO_GENI_TX_FIFOn_OUTI(n,val)        \
                out_dword(HWIO_GENI_TX_FIFOn_ADDR(n),val)
#define HWIO_GENI_TX_FIFOn_TX_DATA_BMSK                                                          0xffffffff
#define HWIO_GENI_TX_FIFOn_TX_DATA_SHFT                                                                   0

#define HWIO_GENI_RX_FIFOn_ADDR(n)                                                               (GENI4_DATA_REG_BASE            + 0X180 + (0x4*(n)))
#define HWIO_GENI_RX_FIFOn_PHYS(n)                                                               (GENI4_DATA_REG_BASE_PHYS + 0X180 + (0x4*(n)))
#define HWIO_GENI_RX_FIFOn_OFFS(n)                                                               (GENI4_DATA_REG_BASE_OFFS + 0X180 + (0x4*(n)))
#define HWIO_GENI_RX_FIFOn_RMSK                                                                  0xffffffff
#define HWIO_GENI_RX_FIFOn_MAXn                                                                          15
#define HWIO_GENI_RX_FIFOn_INI(n)                \
                in_dword_masked(HWIO_GENI_RX_FIFOn_ADDR(n), HWIO_GENI_RX_FIFOn_RMSK)
#define HWIO_GENI_RX_FIFOn_INMI(n,mask)        \
                in_dword_masked(HWIO_GENI_RX_FIFOn_ADDR(n), mask)
#define HWIO_GENI_RX_FIFOn_RX_DATA_BMSK                                                          0xffffffff
#define HWIO_GENI_RX_FIFOn_RX_DATA_SHFT                                                                   0

#define HWIO_GENI_TX_FIFO_STATUS_ADDR                                                            (GENI4_DATA_REG_BASE            + 0x200)
#define HWIO_GENI_TX_FIFO_STATUS_PHYS                                                            (GENI4_DATA_REG_BASE_PHYS + 0x200)
#define HWIO_GENI_TX_FIFO_STATUS_OFFS                                                            (GENI4_DATA_REG_BASE_OFFS + 0x200)
#define HWIO_GENI_TX_FIFO_STATUS_RMSK                                                            0xffffffff
#define HWIO_GENI_TX_FIFO_STATUS_IN                    \
                in_dword(HWIO_GENI_TX_FIFO_STATUS_ADDR)
#define HWIO_GENI_TX_FIFO_STATUS_INM(m)            \
                in_dword_masked(HWIO_GENI_TX_FIFO_STATUS_ADDR, m)
#define HWIO_GENI_TX_FIFO_STATUS_TX_AFIFO_WC_BMSK                                                0xf0000000
#define HWIO_GENI_TX_FIFO_STATUS_TX_AFIFO_WC_SHFT                                                        28
#define HWIO_GENI_TX_FIFO_STATUS_TX_FIFO_WC_BMSK                                                  0xfffffff
#define HWIO_GENI_TX_FIFO_STATUS_TX_FIFO_WC_SHFT                                                          0

#define HWIO_GENI_RX_FIFO_STATUS_ADDR                                                            (GENI4_DATA_REG_BASE            + 0x204)
#define HWIO_GENI_RX_FIFO_STATUS_PHYS                                                            (GENI4_DATA_REG_BASE_PHYS + 0x204)
#define HWIO_GENI_RX_FIFO_STATUS_OFFS                                                            (GENI4_DATA_REG_BASE_OFFS + 0x204)
#define HWIO_GENI_RX_FIFO_STATUS_RMSK                                                            0xffffffff
#define HWIO_GENI_RX_FIFO_STATUS_IN                    \
                in_dword(HWIO_GENI_RX_FIFO_STATUS_ADDR)
#define HWIO_GENI_RX_FIFO_STATUS_INM(m)            \
                in_dword_masked(HWIO_GENI_RX_FIFO_STATUS_ADDR, m)
#define HWIO_GENI_RX_FIFO_STATUS_RX_LAST_BMSK                                                    0x80000000
#define HWIO_GENI_RX_FIFO_STATUS_RX_LAST_SHFT                                                            31
#define HWIO_GENI_RX_FIFO_STATUS_RX_LAST_BYTE_VALID_BMSK                                         0x70000000
#define HWIO_GENI_RX_FIFO_STATUS_RX_LAST_BYTE_VALID_SHFT                                                 28
#define HWIO_GENI_RX_FIFO_STATUS_RX_AFIFO_WC_BMSK                                                 0xe000000
#define HWIO_GENI_RX_FIFO_STATUS_RX_AFIFO_WC_SHFT                                                        25
#define HWIO_GENI_RX_FIFO_STATUS_RX_FIFO_WC_BMSK                                                  0x1ffffff
#define HWIO_GENI_RX_FIFO_STATUS_RX_FIFO_WC_SHFT                                                          0

#define HWIO_GENI_TX_FIFO_THRESHOLD_ADDR                                                         (GENI4_DATA_REG_BASE            + 0x208)
#define HWIO_GENI_TX_FIFO_THRESHOLD_PHYS                                                         (GENI4_DATA_REG_BASE_PHYS + 0x208)
#define HWIO_GENI_TX_FIFO_THRESHOLD_OFFS                                                         (GENI4_DATA_REG_BASE_OFFS + 0x208)
#define HWIO_GENI_TX_FIFO_THRESHOLD_RMSK                                                               0x1f
#define HWIO_GENI_TX_FIFO_THRESHOLD_IN                    \
                in_dword(HWIO_GENI_TX_FIFO_THRESHOLD_ADDR)
#define HWIO_GENI_TX_FIFO_THRESHOLD_INM(m)            \
                in_dword_masked(HWIO_GENI_TX_FIFO_THRESHOLD_ADDR, m)
#define HWIO_GENI_TX_FIFO_THRESHOLD_OUT(v)            \
                out_dword(HWIO_GENI_TX_FIFO_THRESHOLD_ADDR,v)
#define HWIO_GENI_TX_FIFO_THRESHOLD_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_TX_FIFO_THRESHOLD_ADDR,m,v,HWIO_GENI_TX_FIFO_THRESHOLD_IN)
#define HWIO_GENI_TX_FIFO_THRESHOLD_TX_FIFO_THRESHOLD_BMSK                                             0x1f
#define HWIO_GENI_TX_FIFO_THRESHOLD_TX_FIFO_THRESHOLD_SHFT                                                0

#define HWIO_GENI_TX_WATERMARK_REG_ADDR                                                          (GENI4_DATA_REG_BASE            + 0x20c)
#define HWIO_GENI_TX_WATERMARK_REG_PHYS                                                          (GENI4_DATA_REG_BASE_PHYS + 0x20c)
#define HWIO_GENI_TX_WATERMARK_REG_OFFS                                                          (GENI4_DATA_REG_BASE_OFFS + 0x20c)
#define HWIO_GENI_TX_WATERMARK_REG_RMSK                                                                0x3f
#define HWIO_GENI_TX_WATERMARK_REG_IN                    \
                in_dword(HWIO_GENI_TX_WATERMARK_REG_ADDR)
#define HWIO_GENI_TX_WATERMARK_REG_INM(m)            \
                in_dword_masked(HWIO_GENI_TX_WATERMARK_REG_ADDR, m)
#define HWIO_GENI_TX_WATERMARK_REG_OUT(v)            \
                out_dword(HWIO_GENI_TX_WATERMARK_REG_ADDR,v)
#define HWIO_GENI_TX_WATERMARK_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_TX_WATERMARK_REG_ADDR,m,v,HWIO_GENI_TX_WATERMARK_REG_IN)
#define HWIO_GENI_TX_WATERMARK_REG_TX_WATERMARK_BMSK                                                   0x3f
#define HWIO_GENI_TX_WATERMARK_REG_TX_WATERMARK_SHFT                                                      0

#define HWIO_GENI_RX_WATERMARK_REG_ADDR                                                          (GENI4_DATA_REG_BASE            + 0x210)
#define HWIO_GENI_RX_WATERMARK_REG_PHYS                                                          (GENI4_DATA_REG_BASE_PHYS + 0x210)
#define HWIO_GENI_RX_WATERMARK_REG_OFFS                                                          (GENI4_DATA_REG_BASE_OFFS + 0x210)
#define HWIO_GENI_RX_WATERMARK_REG_RMSK                                                                0x3f
#define HWIO_GENI_RX_WATERMARK_REG_IN                    \
                in_dword(HWIO_GENI_RX_WATERMARK_REG_ADDR)
#define HWIO_GENI_RX_WATERMARK_REG_INM(m)            \
                in_dword_masked(HWIO_GENI_RX_WATERMARK_REG_ADDR, m)
#define HWIO_GENI_RX_WATERMARK_REG_OUT(v)            \
                out_dword(HWIO_GENI_RX_WATERMARK_REG_ADDR,v)
#define HWIO_GENI_RX_WATERMARK_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_RX_WATERMARK_REG_ADDR,m,v,HWIO_GENI_RX_WATERMARK_REG_IN)
#define HWIO_GENI_RX_WATERMARK_REG_RX_WATERMARK_BMSK                                                   0x3f
#define HWIO_GENI_RX_WATERMARK_REG_RX_WATERMARK_SHFT                                                      0

#define HWIO_GENI_RX_RFR_WATERMARK_REG_ADDR                                                      (GENI4_DATA_REG_BASE            + 0x214)
#define HWIO_GENI_RX_RFR_WATERMARK_REG_PHYS                                                      (GENI4_DATA_REG_BASE_PHYS + 0x214)
#define HWIO_GENI_RX_RFR_WATERMARK_REG_OFFS                                                      (GENI4_DATA_REG_BASE_OFFS + 0x214)
#define HWIO_GENI_RX_RFR_WATERMARK_REG_RMSK                                                            0x3f
#define HWIO_GENI_RX_RFR_WATERMARK_REG_IN                    \
                in_dword(HWIO_GENI_RX_RFR_WATERMARK_REG_ADDR)
#define HWIO_GENI_RX_RFR_WATERMARK_REG_INM(m)            \
                in_dword_masked(HWIO_GENI_RX_RFR_WATERMARK_REG_ADDR, m)
#define HWIO_GENI_RX_RFR_WATERMARK_REG_OUT(v)            \
                out_dword(HWIO_GENI_RX_RFR_WATERMARK_REG_ADDR,v)
#define HWIO_GENI_RX_RFR_WATERMARK_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_RX_RFR_WATERMARK_REG_ADDR,m,v,HWIO_GENI_RX_RFR_WATERMARK_REG_IN)
#define HWIO_GENI_RX_RFR_WATERMARK_REG_RX_RFR_WATERMARK_BMSK                                           0x3f
#define HWIO_GENI_RX_RFR_WATERMARK_REG_RX_RFR_WATERMARK_SHFT                                              0

#define HWIO_GENI_GP_OUTPUT_REG_ADDR                                                             (GENI4_DATA_REG_BASE            + 0x300)
#define HWIO_GENI_GP_OUTPUT_REG_PHYS                                                             (GENI4_DATA_REG_BASE_PHYS + 0x300)
#define HWIO_GENI_GP_OUTPUT_REG_OFFS                                                             (GENI4_DATA_REG_BASE_OFFS + 0x300)
#define HWIO_GENI_GP_OUTPUT_REG_RMSK                                                                   0x3f
#define HWIO_GENI_GP_OUTPUT_REG_IN                    \
                in_dword(HWIO_GENI_GP_OUTPUT_REG_ADDR)
#define HWIO_GENI_GP_OUTPUT_REG_INM(m)            \
                in_dword_masked(HWIO_GENI_GP_OUTPUT_REG_ADDR, m)
#define HWIO_GENI_GP_OUTPUT_REG_OUT(v)            \
                out_dword(HWIO_GENI_GP_OUTPUT_REG_ADDR,v)
#define HWIO_GENI_GP_OUTPUT_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_GP_OUTPUT_REG_ADDR,m,v,HWIO_GENI_GP_OUTPUT_REG_IN)
#define HWIO_GENI_GP_OUTPUT_REG_GP_OUTPUT_BMSK                                                         0x3f
#define HWIO_GENI_GP_OUTPUT_REG_GP_OUTPUT_SHFT                                                            0

#define HWIO_GENI_IOS_ADDR                                                                       (GENI4_DATA_REG_BASE            + 0x308)
#define HWIO_GENI_IOS_PHYS                                                                       (GENI4_DATA_REG_BASE_PHYS + 0x308)
#define HWIO_GENI_IOS_OFFS                                                                       (GENI4_DATA_REG_BASE_OFFS + 0x308)
#define HWIO_GENI_IOS_RMSK                                                                              0x7
#define HWIO_GENI_IOS_IN                    \
                in_dword(HWIO_GENI_IOS_ADDR)
#define HWIO_GENI_IOS_INM(m)            \
                in_dword_masked(HWIO_GENI_IOS_ADDR, m)
#define HWIO_GENI_IOS_IO3_DATA_IN_BMSK                                                                  0x4
#define HWIO_GENI_IOS_IO3_DATA_IN_SHFT                                                                    2
#define HWIO_GENI_IOS_IO2_DATA_IN_BMSK                                                                  0x2
#define HWIO_GENI_IOS_IO2_DATA_IN_SHFT                                                                    1
#define HWIO_GENI_IOS_RX_DATA_IN_BMSK                                                                   0x1
#define HWIO_GENI_IOS_RX_DATA_IN_SHFT                                                                     0

#define HWIO_GENI_M_GP_LENGTH_ADDR                                                               (GENI4_DATA_REG_BASE            + 0x310)
#define HWIO_GENI_M_GP_LENGTH_PHYS                                                               (GENI4_DATA_REG_BASE_PHYS + 0x310)
#define HWIO_GENI_M_GP_LENGTH_OFFS                                                               (GENI4_DATA_REG_BASE_OFFS + 0x310)
#define HWIO_GENI_M_GP_LENGTH_RMSK                                                               0xffffffff
#define HWIO_GENI_M_GP_LENGTH_IN                    \
                in_dword(HWIO_GENI_M_GP_LENGTH_ADDR)
#define HWIO_GENI_M_GP_LENGTH_INM(m)            \
                in_dword_masked(HWIO_GENI_M_GP_LENGTH_ADDR, m)
#define HWIO_GENI_M_GP_LENGTH_M_GP_LENGTH_BMSK                                                   0xffffffff
#define HWIO_GENI_M_GP_LENGTH_M_GP_LENGTH_SHFT                                                            0

#define HWIO_GENI_S_GP_LENGTH_ADDR                                                               (GENI4_DATA_REG_BASE            + 0x314)
#define HWIO_GENI_S_GP_LENGTH_PHYS                                                               (GENI4_DATA_REG_BASE_PHYS + 0x314)
#define HWIO_GENI_S_GP_LENGTH_OFFS                                                               (GENI4_DATA_REG_BASE_OFFS + 0x314)
#define HWIO_GENI_S_GP_LENGTH_RMSK                                                               0xffffffff
#define HWIO_GENI_S_GP_LENGTH_IN                    \
                in_dword(HWIO_GENI_S_GP_LENGTH_ADDR)
#define HWIO_GENI_S_GP_LENGTH_INM(m)            \
                in_dword_masked(HWIO_GENI_S_GP_LENGTH_ADDR, m)
#define HWIO_GENI_S_GP_LENGTH_S_GP_LENGTH_BMSK                                                   0xffffffff
#define HWIO_GENI_S_GP_LENGTH_S_GP_LENGTH_SHFT                                                            0

#define HWIO_GENI_HW_IRQ_EN_ADDR                                                                 (GENI4_DATA_REG_BASE            + 0x320)
#define HWIO_GENI_HW_IRQ_EN_PHYS                                                                 (GENI4_DATA_REG_BASE_PHYS + 0x320)
#define HWIO_GENI_HW_IRQ_EN_OFFS                                                                 (GENI4_DATA_REG_BASE_OFFS + 0x320)
#define HWIO_GENI_HW_IRQ_EN_RMSK                                                                        0xf
#define HWIO_GENI_HW_IRQ_EN_IN                    \
                in_dword(HWIO_GENI_HW_IRQ_EN_ADDR)
#define HWIO_GENI_HW_IRQ_EN_INM(m)            \
                in_dword_masked(HWIO_GENI_HW_IRQ_EN_ADDR, m)
#define HWIO_GENI_HW_IRQ_EN_OUT(v)            \
                out_dword(HWIO_GENI_HW_IRQ_EN_ADDR,v)
#define HWIO_GENI_HW_IRQ_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_HW_IRQ_EN_ADDR,m,v,HWIO_GENI_HW_IRQ_EN_IN)
#define HWIO_GENI_HW_IRQ_EN_M_RX_DATA_IRQ_EN_BMSK                                                       0x8
#define HWIO_GENI_HW_IRQ_EN_M_RX_DATA_IRQ_EN_SHFT                                                         3
#define HWIO_GENI_HW_IRQ_EN_M_IO3_IRQ_EN_BMSK                                                           0x4
#define HWIO_GENI_HW_IRQ_EN_M_IO3_IRQ_EN_SHFT                                                             2
#define HWIO_GENI_HW_IRQ_EN_M_IO2_IRQ_EN_BMSK                                                           0x2
#define HWIO_GENI_HW_IRQ_EN_M_IO2_IRQ_EN_SHFT                                                             1
#define HWIO_GENI_HW_IRQ_EN_M_IBI_IRQ_EN_BMSK                                                           0x1
#define HWIO_GENI_HW_IRQ_EN_M_IBI_IRQ_EN_SHFT                                                             0

#define HWIO_GENI_HW_IRQ_IGNORE_ON_ACTIVE_ADDR                                                   (GENI4_DATA_REG_BASE            + 0x324)
#define HWIO_GENI_HW_IRQ_IGNORE_ON_ACTIVE_PHYS                                                   (GENI4_DATA_REG_BASE_PHYS + 0x324)
#define HWIO_GENI_HW_IRQ_IGNORE_ON_ACTIVE_OFFS                                                   (GENI4_DATA_REG_BASE_OFFS + 0x324)
#define HWIO_GENI_HW_IRQ_IGNORE_ON_ACTIVE_RMSK                                                          0xf
#define HWIO_GENI_HW_IRQ_IGNORE_ON_ACTIVE_IN                    \
                in_dword(HWIO_GENI_HW_IRQ_IGNORE_ON_ACTIVE_ADDR)
#define HWIO_GENI_HW_IRQ_IGNORE_ON_ACTIVE_INM(m)            \
                in_dword_masked(HWIO_GENI_HW_IRQ_IGNORE_ON_ACTIVE_ADDR, m)
#define HWIO_GENI_HW_IRQ_IGNORE_ON_ACTIVE_OUT(v)            \
                out_dword(HWIO_GENI_HW_IRQ_IGNORE_ON_ACTIVE_ADDR,v)
#define HWIO_GENI_HW_IRQ_IGNORE_ON_ACTIVE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_HW_IRQ_IGNORE_ON_ACTIVE_ADDR,m,v,HWIO_GENI_HW_IRQ_IGNORE_ON_ACTIVE_IN)
#define HWIO_GENI_HW_IRQ_IGNORE_ON_ACTIVE_M_RX_DATA_IRQ_IGNORE_BMSK                                     0x8
#define HWIO_GENI_HW_IRQ_IGNORE_ON_ACTIVE_M_RX_DATA_IRQ_IGNORE_SHFT                                       3
#define HWIO_GENI_HW_IRQ_IGNORE_ON_ACTIVE_M_IO3_IRQ_IGNORE_BMSK                                         0x4
#define HWIO_GENI_HW_IRQ_IGNORE_ON_ACTIVE_M_IO3_IRQ_IGNORE_SHFT                                           2
#define HWIO_GENI_HW_IRQ_IGNORE_ON_ACTIVE_M_IO2_IRQ_IGNORE_BMSK                                         0x2
#define HWIO_GENI_HW_IRQ_IGNORE_ON_ACTIVE_M_IO2_IRQ_IGNORE_SHFT                                           1
#define HWIO_GENI_HW_IRQ_IGNORE_ON_ACTIVE_M_IBI_IRQ_IGNORE_BMSK                                         0x1
#define HWIO_GENI_HW_IRQ_IGNORE_ON_ACTIVE_M_IBI_IRQ_IGNORE_SHFT                                           0

#define HWIO_GENI_HW_IRQ_CMD_PARAM_0_ADDR                                                        (GENI4_DATA_REG_BASE            + 0x330)
#define HWIO_GENI_HW_IRQ_CMD_PARAM_0_PHYS                                                        (GENI4_DATA_REG_BASE_PHYS + 0x330)
#define HWIO_GENI_HW_IRQ_CMD_PARAM_0_OFFS                                                        (GENI4_DATA_REG_BASE_OFFS + 0x330)
#define HWIO_GENI_HW_IRQ_CMD_PARAM_0_RMSK                                                               0x3
#define HWIO_GENI_HW_IRQ_CMD_PARAM_0_IN                    \
                in_dword(HWIO_GENI_HW_IRQ_CMD_PARAM_0_ADDR)
#define HWIO_GENI_HW_IRQ_CMD_PARAM_0_INM(m)            \
                in_dword_masked(HWIO_GENI_HW_IRQ_CMD_PARAM_0_ADDR, m)
#define HWIO_GENI_HW_IRQ_CMD_PARAM_0_OUT(v)            \
                out_dword(HWIO_GENI_HW_IRQ_CMD_PARAM_0_ADDR,v)
#define HWIO_GENI_HW_IRQ_CMD_PARAM_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_HW_IRQ_CMD_PARAM_0_ADDR,m,v,HWIO_GENI_HW_IRQ_CMD_PARAM_0_IN)
#define HWIO_GENI_HW_IRQ_CMD_PARAM_0_M_IBI_IRQ_PARAM_STOP_STALL_BMSK                                    0x2
#define HWIO_GENI_HW_IRQ_CMD_PARAM_0_M_IBI_IRQ_PARAM_STOP_STALL_SHFT                                      1
#define HWIO_GENI_HW_IRQ_CMD_PARAM_0_M_IBI_IRQ_PARAM_7E_BMSK                                            0x1
#define HWIO_GENI_HW_IRQ_CMD_PARAM_0_M_IBI_IRQ_PARAM_7E_SHFT                                              0

#define HWIO_GENI_TIMESTAMP_ADDR                                                                 (GENI4_DATA_REG_BASE            + 0x340)
#define HWIO_GENI_TIMESTAMP_PHYS                                                                 (GENI4_DATA_REG_BASE_PHYS + 0x340)
#define HWIO_GENI_TIMESTAMP_OFFS                                                                 (GENI4_DATA_REG_BASE_OFFS + 0x340)
#define HWIO_GENI_TIMESTAMP_RMSK                                                                 0xffffffff
#define HWIO_GENI_TIMESTAMP_IN                    \
                in_dword(HWIO_GENI_TIMESTAMP_ADDR)
#define HWIO_GENI_TIMESTAMP_INM(m)            \
                in_dword_masked(HWIO_GENI_TIMESTAMP_ADDR, m)
#define HWIO_GENI_TIMESTAMP_TIMESTAMP_BMSK                                                       0xffffffff
#define HWIO_GENI_TIMESTAMP_TIMESTAMP_SHFT                                                                0

#define HWIO_GENI_TIMESTAMP_MSB_ADDR                                                             (GENI4_DATA_REG_BASE            + 0x344)
#define HWIO_GENI_TIMESTAMP_MSB_PHYS                                                             (GENI4_DATA_REG_BASE_PHYS + 0x344)
#define HWIO_GENI_TIMESTAMP_MSB_OFFS                                                             (GENI4_DATA_REG_BASE_OFFS + 0x344)
#define HWIO_GENI_TIMESTAMP_MSB_RMSK                                                             0xffffffff
#define HWIO_GENI_TIMESTAMP_MSB_IN                    \
                in_dword(HWIO_GENI_TIMESTAMP_MSB_ADDR)
#define HWIO_GENI_TIMESTAMP_MSB_INM(m)            \
                in_dword_masked(HWIO_GENI_TIMESTAMP_MSB_ADDR, m)
#define HWIO_GENI_TIMESTAMP_MSB_TIMESTAMP_BMSK                                                   0xffffffff
#define HWIO_GENI_TIMESTAMP_MSB_TIMESTAMP_SHFT                                                            0

#define HWIO_GENI_TIMESTAMP_SAMP_ENABLE_ADDR                                                     (GENI4_DATA_REG_BASE            + 0x348)
#define HWIO_GENI_TIMESTAMP_SAMP_ENABLE_PHYS                                                     (GENI4_DATA_REG_BASE_PHYS + 0x348)
#define HWIO_GENI_TIMESTAMP_SAMP_ENABLE_OFFS                                                     (GENI4_DATA_REG_BASE_OFFS + 0x348)
#define HWIO_GENI_TIMESTAMP_SAMP_ENABLE_RMSK                                                            0x1
#define HWIO_GENI_TIMESTAMP_SAMP_ENABLE_IN                    \
                in_dword(HWIO_GENI_TIMESTAMP_SAMP_ENABLE_ADDR)
#define HWIO_GENI_TIMESTAMP_SAMP_ENABLE_INM(m)            \
                in_dword_masked(HWIO_GENI_TIMESTAMP_SAMP_ENABLE_ADDR, m)
#define HWIO_GENI_TIMESTAMP_SAMP_ENABLE_OUT(v)            \
                out_dword(HWIO_GENI_TIMESTAMP_SAMP_ENABLE_ADDR,v)
#define HWIO_GENI_TIMESTAMP_SAMP_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_TIMESTAMP_SAMP_ENABLE_ADDR,m,v,HWIO_GENI_TIMESTAMP_SAMP_ENABLE_IN)
#define HWIO_GENI_TIMESTAMP_SAMP_ENABLE_HW_IRQ_SAMP_EN_BMSK                                             0x1
#define HWIO_GENI_TIMESTAMP_SAMP_ENABLE_HW_IRQ_SAMP_EN_SHFT                                               0

#define HWIO_GENI_HW_IRQ_CMD_PARAM_IO2_ADDR                                                      (GENI4_DATA_REG_BASE            + 0x350)
#define HWIO_GENI_HW_IRQ_CMD_PARAM_IO2_PHYS                                                      (GENI4_DATA_REG_BASE_PHYS + 0x350)
#define HWIO_GENI_HW_IRQ_CMD_PARAM_IO2_OFFS                                                      (GENI4_DATA_REG_BASE_OFFS + 0x350)
#define HWIO_GENI_HW_IRQ_CMD_PARAM_IO2_RMSK                                                      0xffffffff
#define HWIO_GENI_HW_IRQ_CMD_PARAM_IO2_IN                    \
                in_dword(HWIO_GENI_HW_IRQ_CMD_PARAM_IO2_ADDR)
#define HWIO_GENI_HW_IRQ_CMD_PARAM_IO2_INM(m)            \
                in_dword_masked(HWIO_GENI_HW_IRQ_CMD_PARAM_IO2_ADDR, m)
#define HWIO_GENI_HW_IRQ_CMD_PARAM_IO2_OUT(v)            \
                out_dword(HWIO_GENI_HW_IRQ_CMD_PARAM_IO2_ADDR,v)
#define HWIO_GENI_HW_IRQ_CMD_PARAM_IO2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_HW_IRQ_CMD_PARAM_IO2_ADDR,m,v,HWIO_GENI_HW_IRQ_CMD_PARAM_IO2_IN)
#define HWIO_GENI_HW_IRQ_CMD_PARAM_IO2_M_IO2_IRQ_OPCODE_BMSK                                     0xf8000000
#define HWIO_GENI_HW_IRQ_CMD_PARAM_IO2_M_IO2_IRQ_OPCODE_SHFT                                             27
#define HWIO_GENI_HW_IRQ_CMD_PARAM_IO2_M_IO2_IRQ_PARAM_BMSK                                       0x7ffffff
#define HWIO_GENI_HW_IRQ_CMD_PARAM_IO2_M_IO2_IRQ_PARAM_SHFT                                               0

#define HWIO_GENI_HW_IRQ_CMD_PARAM_IO3_ADDR                                                      (GENI4_DATA_REG_BASE            + 0x354)
#define HWIO_GENI_HW_IRQ_CMD_PARAM_IO3_PHYS                                                      (GENI4_DATA_REG_BASE_PHYS + 0x354)
#define HWIO_GENI_HW_IRQ_CMD_PARAM_IO3_OFFS                                                      (GENI4_DATA_REG_BASE_OFFS + 0x354)
#define HWIO_GENI_HW_IRQ_CMD_PARAM_IO3_RMSK                                                      0xffffffff
#define HWIO_GENI_HW_IRQ_CMD_PARAM_IO3_IN                    \
                in_dword(HWIO_GENI_HW_IRQ_CMD_PARAM_IO3_ADDR)
#define HWIO_GENI_HW_IRQ_CMD_PARAM_IO3_INM(m)            \
                in_dword_masked(HWIO_GENI_HW_IRQ_CMD_PARAM_IO3_ADDR, m)
#define HWIO_GENI_HW_IRQ_CMD_PARAM_IO3_OUT(v)            \
                out_dword(HWIO_GENI_HW_IRQ_CMD_PARAM_IO3_ADDR,v)
#define HWIO_GENI_HW_IRQ_CMD_PARAM_IO3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_HW_IRQ_CMD_PARAM_IO3_ADDR,m,v,HWIO_GENI_HW_IRQ_CMD_PARAM_IO3_IN)
#define HWIO_GENI_HW_IRQ_CMD_PARAM_IO3_M_IO3_IRQ_OPCODE_BMSK                                     0xf8000000
#define HWIO_GENI_HW_IRQ_CMD_PARAM_IO3_M_IO3_IRQ_OPCODE_SHFT                                             27
#define HWIO_GENI_HW_IRQ_CMD_PARAM_IO3_M_IO3_IRQ_PARAM_BMSK                                       0x7ffffff
#define HWIO_GENI_HW_IRQ_CMD_PARAM_IO3_M_IO3_IRQ_PARAM_SHFT                                               0

#define HWIO_GENI_HW_IRQ_CMD_PARAM_RX_DATA_ADDR                                                  (GENI4_DATA_REG_BASE            + 0x358)
#define HWIO_GENI_HW_IRQ_CMD_PARAM_RX_DATA_PHYS                                                  (GENI4_DATA_REG_BASE_PHYS + 0x358)
#define HWIO_GENI_HW_IRQ_CMD_PARAM_RX_DATA_OFFS                                                  (GENI4_DATA_REG_BASE_OFFS + 0x358)
#define HWIO_GENI_HW_IRQ_CMD_PARAM_RX_DATA_RMSK                                                  0xffffffff
#define HWIO_GENI_HW_IRQ_CMD_PARAM_RX_DATA_IN                    \
                in_dword(HWIO_GENI_HW_IRQ_CMD_PARAM_RX_DATA_ADDR)
#define HWIO_GENI_HW_IRQ_CMD_PARAM_RX_DATA_INM(m)            \
                in_dword_masked(HWIO_GENI_HW_IRQ_CMD_PARAM_RX_DATA_ADDR, m)
#define HWIO_GENI_HW_IRQ_CMD_PARAM_RX_DATA_OUT(v)            \
                out_dword(HWIO_GENI_HW_IRQ_CMD_PARAM_RX_DATA_ADDR,v)
#define HWIO_GENI_HW_IRQ_CMD_PARAM_RX_DATA_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_HW_IRQ_CMD_PARAM_RX_DATA_ADDR,m,v,HWIO_GENI_HW_IRQ_CMD_PARAM_RX_DATA_IN)
#define HWIO_GENI_HW_IRQ_CMD_PARAM_RX_DATA_M_RX_DATA_IRQ_OPCODE_BMSK                             0xf8000000
#define HWIO_GENI_HW_IRQ_CMD_PARAM_RX_DATA_M_RX_DATA_IRQ_OPCODE_SHFT                                     27
#define HWIO_GENI_HW_IRQ_CMD_PARAM_RX_DATA_M_RX_DATA_IRQ_PARAM_BMSK                               0x7ffffff
#define HWIO_GENI_HW_IRQ_CMD_PARAM_RX_DATA_M_RX_DATA_IRQ_PARAM_SHFT                                       0

#define HWIO_GENI_SW_IRQ_EN_ADDR                                                                 (GENI4_DATA_REG_BASE            + 0x360)
#define HWIO_GENI_SW_IRQ_EN_PHYS                                                                 (GENI4_DATA_REG_BASE_PHYS + 0x360)
#define HWIO_GENI_SW_IRQ_EN_OFFS                                                                 (GENI4_DATA_REG_BASE_OFFS + 0x360)
#define HWIO_GENI_SW_IRQ_EN_RMSK                                                                 0x13131300
#define HWIO_GENI_SW_IRQ_EN_IN                    \
                in_dword(HWIO_GENI_SW_IRQ_EN_ADDR)
#define HWIO_GENI_SW_IRQ_EN_INM(m)            \
                in_dword_masked(HWIO_GENI_SW_IRQ_EN_ADDR, m)
#define HWIO_GENI_SW_IRQ_EN_OUT(v)            \
                out_dword(HWIO_GENI_SW_IRQ_EN_ADDR,v)
#define HWIO_GENI_SW_IRQ_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_SW_IRQ_EN_ADDR,m,v,HWIO_GENI_SW_IRQ_EN_IN)
#define HWIO_GENI_SW_IRQ_EN_RX_DATA_IRQ_EN_STATUS_BMSK                                           0x10000000
#define HWIO_GENI_SW_IRQ_EN_RX_DATA_IRQ_EN_STATUS_SHFT                                                   28
#define HWIO_GENI_SW_IRQ_EN_RX_DATA_IN_DETECTION_VAL_BMSK                                         0x2000000
#define HWIO_GENI_SW_IRQ_EN_RX_DATA_IN_DETECTION_VAL_SHFT                                                25
#define HWIO_GENI_SW_IRQ_EN_RX_DATA_IRQ_EN_BMSK                                                   0x1000000
#define HWIO_GENI_SW_IRQ_EN_RX_DATA_IRQ_EN_SHFT                                                          24
#define HWIO_GENI_SW_IRQ_EN_IO3_IRQ_EN_STATUS_BMSK                                                 0x100000
#define HWIO_GENI_SW_IRQ_EN_IO3_IRQ_EN_STATUS_SHFT                                                       20
#define HWIO_GENI_SW_IRQ_EN_IO3_IN_DETECTION_VAL_BMSK                                               0x20000
#define HWIO_GENI_SW_IRQ_EN_IO3_IN_DETECTION_VAL_SHFT                                                    17
#define HWIO_GENI_SW_IRQ_EN_IO3_IRQ_EN_BMSK                                                         0x10000
#define HWIO_GENI_SW_IRQ_EN_IO3_IRQ_EN_SHFT                                                              16
#define HWIO_GENI_SW_IRQ_EN_IO2_IRQ_EN_STATUS_BMSK                                                   0x1000
#define HWIO_GENI_SW_IRQ_EN_IO2_IRQ_EN_STATUS_SHFT                                                       12
#define HWIO_GENI_SW_IRQ_EN_IO2_IN_DETECTION_VAL_BMSK                                                 0x200
#define HWIO_GENI_SW_IRQ_EN_IO2_IN_DETECTION_VAL_SHFT                                                     9
#define HWIO_GENI_SW_IRQ_EN_IO2_IRQ_EN_BMSK                                                           0x100
#define HWIO_GENI_SW_IRQ_EN_IO2_IRQ_EN_SHFT                                                               8

#define HWIO_GENI_SW_IRQ_EN_RECOVER_ADDR                                                         (GENI4_DATA_REG_BASE            + 0x364)
#define HWIO_GENI_SW_IRQ_EN_RECOVER_PHYS                                                         (GENI4_DATA_REG_BASE_PHYS + 0x364)
#define HWIO_GENI_SW_IRQ_EN_RECOVER_OFFS                                                         (GENI4_DATA_REG_BASE_OFFS + 0x364)
#define HWIO_GENI_SW_IRQ_EN_RECOVER_RMSK                                                              0x111
#define HWIO_GENI_SW_IRQ_EN_RECOVER_IN                    \
                in_dword(HWIO_GENI_SW_IRQ_EN_RECOVER_ADDR)
#define HWIO_GENI_SW_IRQ_EN_RECOVER_INM(m)            \
                in_dword_masked(HWIO_GENI_SW_IRQ_EN_RECOVER_ADDR, m)
#define HWIO_GENI_SW_IRQ_EN_RECOVER_OUT(v)            \
                out_dword(HWIO_GENI_SW_IRQ_EN_RECOVER_ADDR,v)
#define HWIO_GENI_SW_IRQ_EN_RECOVER_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_SW_IRQ_EN_RECOVER_ADDR,m,v,HWIO_GENI_SW_IRQ_EN_RECOVER_IN)
#define HWIO_GENI_SW_IRQ_EN_RECOVER_RX_DATA_IRQ_EN_RECOVER_SET_BMSK                                   0x100
#define HWIO_GENI_SW_IRQ_EN_RECOVER_RX_DATA_IRQ_EN_RECOVER_SET_SHFT                                       8
#define HWIO_GENI_SW_IRQ_EN_RECOVER_IO3_IRQ_EN_RECOVER_SET_BMSK                                        0x10
#define HWIO_GENI_SW_IRQ_EN_RECOVER_IO3_IRQ_EN_RECOVER_SET_SHFT                                           4
#define HWIO_GENI_SW_IRQ_EN_RECOVER_IO2_IRQ_EN_RECOVER_SET_BMSK                                         0x1
#define HWIO_GENI_SW_IRQ_EN_RECOVER_IO2_IRQ_EN_RECOVER_SET_SHFT                                           0

#define HWIO_GENI_I3C_IBI_CFG_TABLEn_ADDR(n)                                                     (GENI4_DATA_REG_BASE            + 0X400 + (0x4*(n)))
#define HWIO_GENI_I3C_IBI_CFG_TABLEn_PHYS(n)                                                     (GENI4_DATA_REG_BASE_PHYS + 0X400 + (0x4*(n)))
#define HWIO_GENI_I3C_IBI_CFG_TABLEn_OFFS(n)                                                     (GENI4_DATA_REG_BASE_OFFS + 0X400 + (0x4*(n)))
#define HWIO_GENI_I3C_IBI_CFG_TABLEn_RMSK                                                         0x1ffffff
#define HWIO_GENI_I3C_IBI_CFG_TABLEn_MAXn                                                                15
#define HWIO_GENI_I3C_IBI_CFG_TABLEn_INI(n)                \
                in_dword_masked(HWIO_GENI_I3C_IBI_CFG_TABLEn_ADDR(n), HWIO_GENI_I3C_IBI_CFG_TABLEn_RMSK)
#define HWIO_GENI_I3C_IBI_CFG_TABLEn_INMI(n,mask)        \
                in_dword_masked(HWIO_GENI_I3C_IBI_CFG_TABLEn_ADDR(n), mask)
#define HWIO_GENI_I3C_IBI_CFG_TABLEn_SCL_LOW_CNT_BMSK                                             0x1fe0000
#define HWIO_GENI_I3C_IBI_CFG_TABLEn_SCL_LOW_CNT_SHFT                                                    17
#define HWIO_GENI_I3C_IBI_CFG_TABLEn_OWNER_BMSK                                                     0x1e000
#define HWIO_GENI_I3C_IBI_CFG_TABLEn_OWNER_SHFT                                                          13
#define HWIO_GENI_I3C_IBI_CFG_TABLEn_NUM_BYTES_BMSK                                                  0x1c00
#define HWIO_GENI_I3C_IBI_CFG_TABLEn_NUM_BYTES_SHFT                                                      10
#define HWIO_GENI_I3C_IBI_CFG_TABLEn_ACK_NACK_BMSK                                                    0x200
#define HWIO_GENI_I3C_IBI_CFG_TABLEn_ACK_NACK_SHFT                                                        9
#define HWIO_GENI_I3C_IBI_CFG_TABLEn_RD_WR_BMSK                                                       0x100
#define HWIO_GENI_I3C_IBI_CFG_TABLEn_RD_WR_SHFT                                                           8
#define HWIO_GENI_I3C_IBI_CFG_TABLEn_DEVICE_ADDR_BMSK                                                  0xfe
#define HWIO_GENI_I3C_IBI_CFG_TABLEn_DEVICE_ADDR_SHFT                                                     1
#define HWIO_GENI_I3C_IBI_CFG_TABLEn_VALID_BMSK                                                         0x1
#define HWIO_GENI_I3C_IBI_CFG_TABLEn_VALID_SHFT                                                           0

#define HWIO_GENI_I3C_IBI_STATUS_ADDR                                                            (GENI4_DATA_REG_BASE            + 0x480)
#define HWIO_GENI_I3C_IBI_STATUS_PHYS                                                            (GENI4_DATA_REG_BASE_PHYS + 0x480)
#define HWIO_GENI_I3C_IBI_STATUS_OFFS                                                            (GENI4_DATA_REG_BASE_OFFS + 0x480)
#define HWIO_GENI_I3C_IBI_STATUS_RMSK                                                            0x81ef71ff
#define HWIO_GENI_I3C_IBI_STATUS_IN                    \
                in_dword(HWIO_GENI_I3C_IBI_STATUS_ADDR)
#define HWIO_GENI_I3C_IBI_STATUS_INM(m)            \
                in_dword_masked(HWIO_GENI_I3C_IBI_STATUS_ADDR, m)
#define HWIO_GENI_I3C_IBI_STATUS_FOUND_BMSK                                                      0x80000000
#define HWIO_GENI_I3C_IBI_STATUS_FOUND_SHFT                                                              31
#define HWIO_GENI_I3C_IBI_STATUS_INDEX_BMSK                                                       0x1e00000
#define HWIO_GENI_I3C_IBI_STATUS_INDEX_SHFT                                                              21
#define HWIO_GENI_I3C_IBI_STATUS_OWNER_BMSK                                                         0xf0000
#define HWIO_GENI_I3C_IBI_STATUS_OWNER_SHFT                                                              16
#define HWIO_GENI_I3C_IBI_STATUS_NUM_BYTES_BMSK                                                      0x7000
#define HWIO_GENI_I3C_IBI_STATUS_NUM_BYTES_SHFT                                                          12
#define HWIO_GENI_I3C_IBI_STATUS_ACK_NACK_BMSK                                                        0x100
#define HWIO_GENI_I3C_IBI_STATUS_ACK_NACK_SHFT                                                            8
#define HWIO_GENI_I3C_IBI_STATUS_DEVICE_ADDR_BMSK                                                      0xfe
#define HWIO_GENI_I3C_IBI_STATUS_DEVICE_ADDR_SHFT                                                         1
#define HWIO_GENI_I3C_IBI_STATUS_RD_WR_BMSK                                                             0x1
#define HWIO_GENI_I3C_IBI_STATUS_RD_WR_SHFT                                                               0

#define HWIO_GENI_I3C_IBI_RD_DATA_ADDR                                                           (GENI4_DATA_REG_BASE            + 0x484)
#define HWIO_GENI_I3C_IBI_RD_DATA_PHYS                                                           (GENI4_DATA_REG_BASE_PHYS + 0x484)
#define HWIO_GENI_I3C_IBI_RD_DATA_OFFS                                                           (GENI4_DATA_REG_BASE_OFFS + 0x484)
#define HWIO_GENI_I3C_IBI_RD_DATA_RMSK                                                           0xffffffff
#define HWIO_GENI_I3C_IBI_RD_DATA_IN                    \
                in_dword(HWIO_GENI_I3C_IBI_RD_DATA_ADDR)
#define HWIO_GENI_I3C_IBI_RD_DATA_INM(m)            \
                in_dword_masked(HWIO_GENI_I3C_IBI_RD_DATA_ADDR, m)
#define HWIO_GENI_I3C_IBI_RD_DATA_DATA_BMSK                                                      0xffffffff
#define HWIO_GENI_I3C_IBI_RD_DATA_DATA_SHFT                                                               0

#define HWIO_GENI_I3C_IBI_SEARCH_PATTERN_ADDR                                                    (GENI4_DATA_REG_BASE            + 0x488)
#define HWIO_GENI_I3C_IBI_SEARCH_PATTERN_PHYS                                                    (GENI4_DATA_REG_BASE_PHYS + 0x488)
#define HWIO_GENI_I3C_IBI_SEARCH_PATTERN_OFFS                                                    (GENI4_DATA_REG_BASE_OFFS + 0x488)
#define HWIO_GENI_I3C_IBI_SEARCH_PATTERN_RMSK                                                          0xff
#define HWIO_GENI_I3C_IBI_SEARCH_PATTERN_IN                    \
                in_dword(HWIO_GENI_I3C_IBI_SEARCH_PATTERN_ADDR)
#define HWIO_GENI_I3C_IBI_SEARCH_PATTERN_INM(m)            \
                in_dword_masked(HWIO_GENI_I3C_IBI_SEARCH_PATTERN_ADDR, m)
#define HWIO_GENI_I3C_IBI_SEARCH_PATTERN_DEVICE_ADDR_BMSK                                              0xfe
#define HWIO_GENI_I3C_IBI_SEARCH_PATTERN_DEVICE_ADDR_SHFT                                                 1
#define HWIO_GENI_I3C_IBI_SEARCH_PATTERN_RD_WR_BMSK                                                     0x1
#define HWIO_GENI_I3C_IBI_SEARCH_PATTERN_RD_WR_SHFT                                                       0

#define HWIO_GENI_I3C_IBI_SEARCH_DATA_ADDR                                                       (GENI4_DATA_REG_BASE            + 0x48c)
#define HWIO_GENI_I3C_IBI_SEARCH_DATA_PHYS                                                       (GENI4_DATA_REG_BASE_PHYS + 0x48c)
#define HWIO_GENI_I3C_IBI_SEARCH_DATA_OFFS                                                       (GENI4_DATA_REG_BASE_OFFS + 0x48c)
#define HWIO_GENI_I3C_IBI_SEARCH_DATA_RMSK                                                       0x8000000f
#define HWIO_GENI_I3C_IBI_SEARCH_DATA_IN                    \
                in_dword(HWIO_GENI_I3C_IBI_SEARCH_DATA_ADDR)
#define HWIO_GENI_I3C_IBI_SEARCH_DATA_INM(m)            \
                in_dword_masked(HWIO_GENI_I3C_IBI_SEARCH_DATA_ADDR, m)
#define HWIO_GENI_I3C_IBI_SEARCH_DATA_FOUND_BMSK                                                 0x80000000
#define HWIO_GENI_I3C_IBI_SEARCH_DATA_FOUND_SHFT                                                         31
#define HWIO_GENI_I3C_IBI_SEARCH_DATA_INDEX_BMSK                                                        0xf
#define HWIO_GENI_I3C_IBI_SEARCH_DATA_INDEX_SHFT                                                          0

#define HWIO_GENI_I3C_SW_IBI_EN_ADDR                                                             (GENI4_DATA_REG_BASE            + 0x490)
#define HWIO_GENI_I3C_SW_IBI_EN_PHYS                                                             (GENI4_DATA_REG_BASE_PHYS + 0x490)
#define HWIO_GENI_I3C_SW_IBI_EN_OFFS                                                             (GENI4_DATA_REG_BASE_OFFS + 0x490)
#define HWIO_GENI_I3C_SW_IBI_EN_RMSK                                                                   0x11
#define HWIO_GENI_I3C_SW_IBI_EN_IN                    \
                in_dword(HWIO_GENI_I3C_SW_IBI_EN_ADDR)
#define HWIO_GENI_I3C_SW_IBI_EN_INM(m)            \
                in_dword_masked(HWIO_GENI_I3C_SW_IBI_EN_ADDR, m)
#define HWIO_GENI_I3C_SW_IBI_EN_IBI_EN_STATUS_BMSK                                                     0x10
#define HWIO_GENI_I3C_SW_IBI_EN_IBI_EN_STATUS_SHFT                                                        4
#define HWIO_GENI_I3C_SW_IBI_EN_IBI_EN_BMSK                                                             0x1
#define HWIO_GENI_I3C_SW_IBI_EN_IBI_EN_SHFT                                                               0

#define HWIO_GENI_I3C_SW_IBI_EN_RECOVER_ADDR                                                     (GENI4_DATA_REG_BASE            + 0x494)
#define HWIO_GENI_I3C_SW_IBI_EN_RECOVER_PHYS                                                     (GENI4_DATA_REG_BASE_PHYS + 0x494)
#define HWIO_GENI_I3C_SW_IBI_EN_RECOVER_OFFS                                                     (GENI4_DATA_REG_BASE_OFFS + 0x494)
#define HWIO_GENI_I3C_SW_IBI_EN_RECOVER_RMSK                                                            0x1
#define HWIO_GENI_I3C_SW_IBI_EN_RECOVER_OUT(v)            \
                out_dword(HWIO_GENI_I3C_SW_IBI_EN_RECOVER_ADDR,v)
#define HWIO_GENI_I3C_SW_IBI_EN_RECOVER_IBI_EN_RECOVER_SET_BMSK                                         0x1
#define HWIO_GENI_I3C_SW_IBI_EN_RECOVER_IBI_EN_RECOVER_SET_SHFT                                           0

#define HWIO_GENI_I3C_IBI_CTRL_EN_ADDR                                                           (GENI4_DATA_REG_BASE            + 0x498)
#define HWIO_GENI_I3C_IBI_CTRL_EN_PHYS                                                           (GENI4_DATA_REG_BASE_PHYS + 0x498)
#define HWIO_GENI_I3C_IBI_CTRL_EN_OFFS                                                           (GENI4_DATA_REG_BASE_OFFS + 0x498)
#define HWIO_GENI_I3C_IBI_CTRL_EN_RMSK                                                                  0x1
#define HWIO_GENI_I3C_IBI_CTRL_EN_IN                    \
                in_dword(HWIO_GENI_I3C_IBI_CTRL_EN_ADDR)
#define HWIO_GENI_I3C_IBI_CTRL_EN_INM(m)            \
                in_dword_masked(HWIO_GENI_I3C_IBI_CTRL_EN_ADDR, m)
#define HWIO_GENI_I3C_IBI_CTRL_EN_OUT(v)            \
                out_dword(HWIO_GENI_I3C_IBI_CTRL_EN_ADDR,v)
#define HWIO_GENI_I3C_IBI_CTRL_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_I3C_IBI_CTRL_EN_ADDR,m,v,HWIO_GENI_I3C_IBI_CTRL_EN_IN)
#define HWIO_GENI_I3C_IBI_CTRL_EN_IBI_CTRL_EN_BMSK                                                      0x1
#define HWIO_GENI_I3C_IBI_CTRL_EN_IBI_CTRL_EN_SHFT                                                        0

#define HWIO_GENI_I3C_IBI_LEGACY_ADDR                                                            (GENI4_DATA_REG_BASE            + 0x49c)
#define HWIO_GENI_I3C_IBI_LEGACY_PHYS                                                            (GENI4_DATA_REG_BASE_PHYS + 0x49c)
#define HWIO_GENI_I3C_IBI_LEGACY_OFFS                                                            (GENI4_DATA_REG_BASE_OFFS + 0x49c)
#define HWIO_GENI_I3C_IBI_LEGACY_RMSK                                                                   0x7
#define HWIO_GENI_I3C_IBI_LEGACY_IN                    \
                in_dword(HWIO_GENI_I3C_IBI_LEGACY_ADDR)
#define HWIO_GENI_I3C_IBI_LEGACY_INM(m)            \
                in_dword_masked(HWIO_GENI_I3C_IBI_LEGACY_ADDR, m)
#define HWIO_GENI_I3C_IBI_LEGACY_OUT(v)            \
                out_dword(HWIO_GENI_I3C_IBI_LEGACY_ADDR,v)
#define HWIO_GENI_I3C_IBI_LEGACY_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_I3C_IBI_LEGACY_ADDR,m,v,HWIO_GENI_I3C_IBI_LEGACY_IN)
#define HWIO_GENI_I3C_IBI_LEGACY_I3C_IBI_SSC_IBI_SEL_BMSK                                               0x4
#define HWIO_GENI_I3C_IBI_LEGACY_I3C_IBI_SSC_IBI_SEL_SHFT                                                 2
#define HWIO_GENI_I3C_IBI_LEGACY_I3C_IBI_LEGACY_PORTS_EN_BMSK                                           0x2
#define HWIO_GENI_I3C_IBI_LEGACY_I3C_IBI_LEGACY_PORTS_EN_SHFT                                             1
#define HWIO_GENI_I3C_IBI_LEGACY_I3C_IBI_LEGACY_EN_BMSK                                                 0x1
#define HWIO_GENI_I3C_IBI_LEGACY_I3C_IBI_LEGACY_EN_SHFT                                                   0

#define HWIO_GENI_TIMESTAMP_OFFSET0_1_ADDR                                                       (GENI4_DATA_REG_BASE            + 0x4a0)
#define HWIO_GENI_TIMESTAMP_OFFSET0_1_PHYS                                                       (GENI4_DATA_REG_BASE_PHYS + 0x4a0)
#define HWIO_GENI_TIMESTAMP_OFFSET0_1_OFFS                                                       (GENI4_DATA_REG_BASE_OFFS + 0x4a0)
#define HWIO_GENI_TIMESTAMP_OFFSET0_1_RMSK                                                       0xffffffff
#define HWIO_GENI_TIMESTAMP_OFFSET0_1_IN                    \
                in_dword(HWIO_GENI_TIMESTAMP_OFFSET0_1_ADDR)
#define HWIO_GENI_TIMESTAMP_OFFSET0_1_INM(m)            \
                in_dword_masked(HWIO_GENI_TIMESTAMP_OFFSET0_1_ADDR, m)
#define HWIO_GENI_TIMESTAMP_OFFSET0_1_TIMESTAMP_OFFSET1_BMSK                                     0xffff0000
#define HWIO_GENI_TIMESTAMP_OFFSET0_1_TIMESTAMP_OFFSET1_SHFT                                             16
#define HWIO_GENI_TIMESTAMP_OFFSET0_1_TIMESTAMP_OFFSET0_BMSK                                         0xffff
#define HWIO_GENI_TIMESTAMP_OFFSET0_1_TIMESTAMP_OFFSET0_SHFT                                              0

#define HWIO_GENI_TIMESTAMP_OFFSET2_3_ADDR                                                       (GENI4_DATA_REG_BASE            + 0x4a4)
#define HWIO_GENI_TIMESTAMP_OFFSET2_3_PHYS                                                       (GENI4_DATA_REG_BASE_PHYS + 0x4a4)
#define HWIO_GENI_TIMESTAMP_OFFSET2_3_OFFS                                                       (GENI4_DATA_REG_BASE_OFFS + 0x4a4)
#define HWIO_GENI_TIMESTAMP_OFFSET2_3_RMSK                                                       0xffffffff
#define HWIO_GENI_TIMESTAMP_OFFSET2_3_IN                    \
                in_dword(HWIO_GENI_TIMESTAMP_OFFSET2_3_ADDR)
#define HWIO_GENI_TIMESTAMP_OFFSET2_3_INM(m)            \
                in_dword_masked(HWIO_GENI_TIMESTAMP_OFFSET2_3_ADDR, m)
#define HWIO_GENI_TIMESTAMP_OFFSET2_3_TIMESTAMP_OFFSET3_BMSK                                     0xffff0000
#define HWIO_GENI_TIMESTAMP_OFFSET2_3_TIMESTAMP_OFFSET3_SHFT                                             16
#define HWIO_GENI_TIMESTAMP_OFFSET2_3_TIMESTAMP_OFFSET2_BMSK                                         0xffff
#define HWIO_GENI_TIMESTAMP_OFFSET2_3_TIMESTAMP_OFFSET2_SHFT                                              0

#define HWIO_GENI_TIMESTAMP_OFFSET4_5_ADDR                                                       (GENI4_DATA_REG_BASE            + 0x4a8)
#define HWIO_GENI_TIMESTAMP_OFFSET4_5_PHYS                                                       (GENI4_DATA_REG_BASE_PHYS + 0x4a8)
#define HWIO_GENI_TIMESTAMP_OFFSET4_5_OFFS                                                       (GENI4_DATA_REG_BASE_OFFS + 0x4a8)
#define HWIO_GENI_TIMESTAMP_OFFSET4_5_RMSK                                                       0xffffffff
#define HWIO_GENI_TIMESTAMP_OFFSET4_5_IN                    \
                in_dword(HWIO_GENI_TIMESTAMP_OFFSET4_5_ADDR)
#define HWIO_GENI_TIMESTAMP_OFFSET4_5_INM(m)            \
                in_dword_masked(HWIO_GENI_TIMESTAMP_OFFSET4_5_ADDR, m)
#define HWIO_GENI_TIMESTAMP_OFFSET4_5_TIMESTAMP_OFFSET5_BMSK                                     0xffff0000
#define HWIO_GENI_TIMESTAMP_OFFSET4_5_TIMESTAMP_OFFSET5_SHFT                                             16
#define HWIO_GENI_TIMESTAMP_OFFSET4_5_TIMESTAMP_OFFSET4_BMSK                                         0xffff
#define HWIO_GENI_TIMESTAMP_OFFSET4_5_TIMESTAMP_OFFSET4_SHFT                                              0

#define HWIO_GENI_TIMESTAMP_OFFSET6_7_ADDR                                                       (GENI4_DATA_REG_BASE            + 0x4ac)
#define HWIO_GENI_TIMESTAMP_OFFSET6_7_PHYS                                                       (GENI4_DATA_REG_BASE_PHYS + 0x4ac)
#define HWIO_GENI_TIMESTAMP_OFFSET6_7_OFFS                                                       (GENI4_DATA_REG_BASE_OFFS + 0x4ac)
#define HWIO_GENI_TIMESTAMP_OFFSET6_7_RMSK                                                       0xffffffff
#define HWIO_GENI_TIMESTAMP_OFFSET6_7_IN                    \
                in_dword(HWIO_GENI_TIMESTAMP_OFFSET6_7_ADDR)
#define HWIO_GENI_TIMESTAMP_OFFSET6_7_INM(m)            \
                in_dword_masked(HWIO_GENI_TIMESTAMP_OFFSET6_7_ADDR, m)
#define HWIO_GENI_TIMESTAMP_OFFSET6_7_TIMESTAMP_OFFSET7_BMSK                                     0xffff0000
#define HWIO_GENI_TIMESTAMP_OFFSET6_7_TIMESTAMP_OFFSET7_SHFT                                             16
#define HWIO_GENI_TIMESTAMP_OFFSET6_7_TIMESTAMP_OFFSET6_BMSK                                         0xffff
#define HWIO_GENI_TIMESTAMP_OFFSET6_7_TIMESTAMP_OFFSET6_SHFT                                              0

#define HWIO_GENI_ARM_I2CONSET_ADDR                                                              (GENI4_DATA_REG_BASE            + 0x500)
#define HWIO_GENI_ARM_I2CONSET_PHYS                                                              (GENI4_DATA_REG_BASE_PHYS + 0x500)
#define HWIO_GENI_ARM_I2CONSET_OFFS                                                              (GENI4_DATA_REG_BASE_OFFS + 0x500)
#define HWIO_GENI_ARM_I2CONSET_RMSK                                                                    0x7c
#define HWIO_GENI_ARM_I2CONSET_IN                    \
                in_dword(HWIO_GENI_ARM_I2CONSET_ADDR)
#define HWIO_GENI_ARM_I2CONSET_INM(m)            \
                in_dword_masked(HWIO_GENI_ARM_I2CONSET_ADDR, m)
#define HWIO_GENI_ARM_I2CONSET_OUT(v)            \
                out_dword(HWIO_GENI_ARM_I2CONSET_ADDR,v)
#define HWIO_GENI_ARM_I2CONSET_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_ARM_I2CONSET_ADDR,m,v,HWIO_GENI_ARM_I2CONSET_IN)
#define HWIO_GENI_ARM_I2CONSET_I2EN_BMSK                                                               0x40
#define HWIO_GENI_ARM_I2CONSET_I2EN_SHFT                                                                  6
#define HWIO_GENI_ARM_I2CONSET_STA_BMSK                                                                0x20
#define HWIO_GENI_ARM_I2CONSET_STA_SHFT                                                                   5
#define HWIO_GENI_ARM_I2CONSET_STO_BMSK                                                                0x10
#define HWIO_GENI_ARM_I2CONSET_STO_SHFT                                                                   4
#define HWIO_GENI_ARM_I2CONSET_SI_BMSK                                                                  0x8
#define HWIO_GENI_ARM_I2CONSET_SI_SHFT                                                                    3
#define HWIO_GENI_ARM_I2CONSET_AA_BMSK                                                                  0x4
#define HWIO_GENI_ARM_I2CONSET_AA_SHFT                                                                    2

#define HWIO_GENI_ARM_I2STAT_ADDR                                                                (GENI4_DATA_REG_BASE            + 0x504)
#define HWIO_GENI_ARM_I2STAT_PHYS                                                                (GENI4_DATA_REG_BASE_PHYS + 0x504)
#define HWIO_GENI_ARM_I2STAT_OFFS                                                                (GENI4_DATA_REG_BASE_OFFS + 0x504)
#define HWIO_GENI_ARM_I2STAT_RMSK                                                                      0xff
#define HWIO_GENI_ARM_I2STAT_IN                    \
                in_dword(HWIO_GENI_ARM_I2STAT_ADDR)
#define HWIO_GENI_ARM_I2STAT_INM(m)            \
                in_dword_masked(HWIO_GENI_ARM_I2STAT_ADDR, m)
#define HWIO_GENI_ARM_I2STAT_STATUS_BMSK                                                               0xf8
#define HWIO_GENI_ARM_I2STAT_STATUS_SHFT                                                                  3
#define HWIO_GENI_ARM_I2STAT_STATUS0_BMSK                                                               0x7
#define HWIO_GENI_ARM_I2STAT_STATUS0_SHFT                                                                 0

#define HWIO_GENI_ARM_I2CDATA_ADDR                                                               (GENI4_DATA_REG_BASE            + 0x508)
#define HWIO_GENI_ARM_I2CDATA_PHYS                                                               (GENI4_DATA_REG_BASE_PHYS + 0x508)
#define HWIO_GENI_ARM_I2CDATA_OFFS                                                               (GENI4_DATA_REG_BASE_OFFS + 0x508)
#define HWIO_GENI_ARM_I2CDATA_RMSK                                                                     0xff
#define HWIO_GENI_ARM_I2CDATA_IN                    \
                in_dword(HWIO_GENI_ARM_I2CDATA_ADDR)
#define HWIO_GENI_ARM_I2CDATA_INM(m)            \
                in_dword_masked(HWIO_GENI_ARM_I2CDATA_ADDR, m)
#define HWIO_GENI_ARM_I2CDATA_OUT(v)            \
                out_dword(HWIO_GENI_ARM_I2CDATA_ADDR,v)
#define HWIO_GENI_ARM_I2CDATA_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_ARM_I2CDATA_ADDR,m,v,HWIO_GENI_ARM_I2CDATA_IN)
#define HWIO_GENI_ARM_I2CDATA_DATA_BMSK                                                                0xff
#define HWIO_GENI_ARM_I2CDATA_DATA_SHFT                                                                   0

#define HWIO_GENI_ARM_I2ADR_ADDR                                                                 (GENI4_DATA_REG_BASE            + 0x50c)
#define HWIO_GENI_ARM_I2ADR_PHYS                                                                 (GENI4_DATA_REG_BASE_PHYS + 0x50c)
#define HWIO_GENI_ARM_I2ADR_OFFS                                                                 (GENI4_DATA_REG_BASE_OFFS + 0x50c)
#define HWIO_GENI_ARM_I2ADR_RMSK                                                                       0xff
#define HWIO_GENI_ARM_I2ADR_IN                    \
                in_dword(HWIO_GENI_ARM_I2ADR_ADDR)
#define HWIO_GENI_ARM_I2ADR_INM(m)            \
                in_dword_masked(HWIO_GENI_ARM_I2ADR_ADDR, m)
#define HWIO_GENI_ARM_I2ADR_OUT(v)            \
                out_dword(HWIO_GENI_ARM_I2ADR_ADDR,v)
#define HWIO_GENI_ARM_I2ADR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_ARM_I2ADR_ADDR,m,v,HWIO_GENI_ARM_I2ADR_IN)
#define HWIO_GENI_ARM_I2ADR_ADDRESS_BMSK                                                               0xfe
#define HWIO_GENI_ARM_I2ADR_ADDRESS_SHFT                                                                  1
#define HWIO_GENI_ARM_I2ADR_GC_BMSK                                                                     0x1
#define HWIO_GENI_ARM_I2ADR_GC_SHFT                                                                       0

#define HWIO_GENI_ARM_I2SCLH_ADDR                                                                (GENI4_DATA_REG_BASE            + 0x510)
#define HWIO_GENI_ARM_I2SCLH_PHYS                                                                (GENI4_DATA_REG_BASE_PHYS + 0x510)
#define HWIO_GENI_ARM_I2SCLH_OFFS                                                                (GENI4_DATA_REG_BASE_OFFS + 0x510)
#define HWIO_GENI_ARM_I2SCLH_RMSK                                                                    0xffff
#define HWIO_GENI_ARM_I2SCLH_IN                    \
                in_dword(HWIO_GENI_ARM_I2SCLH_ADDR)
#define HWIO_GENI_ARM_I2SCLH_INM(m)            \
                in_dword_masked(HWIO_GENI_ARM_I2SCLH_ADDR, m)
#define HWIO_GENI_ARM_I2SCLH_OUT(v)            \
                out_dword(HWIO_GENI_ARM_I2SCLH_ADDR,v)
#define HWIO_GENI_ARM_I2SCLH_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_ARM_I2SCLH_ADDR,m,v,HWIO_GENI_ARM_I2SCLH_IN)
#define HWIO_GENI_ARM_I2SCLH_T_HIGH_BMSK                                                             0xffff
#define HWIO_GENI_ARM_I2SCLH_T_HIGH_SHFT                                                                  0

#define HWIO_GENI_ARM_I2SCLL_ADDR                                                                (GENI4_DATA_REG_BASE            + 0x514)
#define HWIO_GENI_ARM_I2SCLL_PHYS                                                                (GENI4_DATA_REG_BASE_PHYS + 0x514)
#define HWIO_GENI_ARM_I2SCLL_OFFS                                                                (GENI4_DATA_REG_BASE_OFFS + 0x514)
#define HWIO_GENI_ARM_I2SCLL_RMSK                                                                    0xffff
#define HWIO_GENI_ARM_I2SCLL_IN                    \
                in_dword(HWIO_GENI_ARM_I2SCLL_ADDR)
#define HWIO_GENI_ARM_I2SCLL_INM(m)            \
                in_dword_masked(HWIO_GENI_ARM_I2SCLL_ADDR, m)
#define HWIO_GENI_ARM_I2SCLL_OUT(v)            \
                out_dword(HWIO_GENI_ARM_I2SCLL_ADDR,v)
#define HWIO_GENI_ARM_I2SCLL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_ARM_I2SCLL_ADDR,m,v,HWIO_GENI_ARM_I2SCLL_IN)
#define HWIO_GENI_ARM_I2SCLL_T_LOW_BMSK                                                              0xffff
#define HWIO_GENI_ARM_I2SCLL_T_LOW_SHFT                                                                   0

#define HWIO_GENI_ARM_I2CONCLR_ADDR                                                              (GENI4_DATA_REG_BASE            + 0x518)
#define HWIO_GENI_ARM_I2CONCLR_PHYS                                                              (GENI4_DATA_REG_BASE_PHYS + 0x518)
#define HWIO_GENI_ARM_I2CONCLR_OFFS                                                              (GENI4_DATA_REG_BASE_OFFS + 0x518)
#define HWIO_GENI_ARM_I2CONCLR_RMSK                                                                    0x6c
#define HWIO_GENI_ARM_I2CONCLR_OUT(v)            \
                out_dword(HWIO_GENI_ARM_I2CONCLR_ADDR,v)
#define HWIO_GENI_ARM_I2CONCLR_I2ENC_BMSK                                                              0x40
#define HWIO_GENI_ARM_I2CONCLR_I2ENC_SHFT                                                                 6
#define HWIO_GENI_ARM_I2CONCLR_STAC_BMSK                                                               0x20
#define HWIO_GENI_ARM_I2CONCLR_STAC_SHFT                                                                  5
#define HWIO_GENI_ARM_I2CONCLR_SIC_BMSK                                                                 0x8
#define HWIO_GENI_ARM_I2CONCLR_SIC_SHFT                                                                   3
#define HWIO_GENI_ARM_I2CONCLR_AAC_BMSK                                                                 0x4
#define HWIO_GENI_ARM_I2CONCLR_AAC_SHFT                                                                   2

/*----------------------------------------------------------------------------
 * MODULE: QUPV3_SE_DMA
 *--------------------------------------------------------------------------*/

#define QUPV3_SE_DMA_REG_BASE                                                               (SAILSS_QUPV3_1_QUPV3_ID_1_BASE            + 0x00080c00)
#define QUPV3_SE_DMA_REG_BASE_SIZE                                                          0x400
#define QUPV3_SE_DMA_REG_BASE_USED                                                          0x248
#define QUPV3_SE_DMA_REG_BASE_PHYS                                                          (SAILSS_QUPV3_1_QUPV3_ID_1_BASE_PHYS + 0x00080c00)
#define QUPV3_SE_DMA_REG_BASE_OFFS                                                          0x00080c00

#define HWIO_DMA_TX_PTR_L_ADDR                                                              (QUPV3_SE_DMA_REG_BASE            + 0x30)
#define HWIO_DMA_TX_PTR_L_PHYS                                                              (QUPV3_SE_DMA_REG_BASE_PHYS + 0x30)
#define HWIO_DMA_TX_PTR_L_OFFS                                                              (QUPV3_SE_DMA_REG_BASE_OFFS + 0x30)
#define HWIO_DMA_TX_PTR_L_RMSK                                                              0xffffffff
#define HWIO_DMA_TX_PTR_L_IN                    \
                in_dword(HWIO_DMA_TX_PTR_L_ADDR)
#define HWIO_DMA_TX_PTR_L_INM(m)            \
                in_dword_masked(HWIO_DMA_TX_PTR_L_ADDR, m)
#define HWIO_DMA_TX_PTR_L_OUT(v)            \
                out_dword(HWIO_DMA_TX_PTR_L_ADDR,v)
#define HWIO_DMA_TX_PTR_L_OUTM(m,v) \
                out_dword_masked_ns(HWIO_DMA_TX_PTR_L_ADDR,m,v,HWIO_DMA_TX_PTR_L_IN)
#define HWIO_DMA_TX_PTR_L_TX_PTR_L_BMSK                                                     0xffffffff
#define HWIO_DMA_TX_PTR_L_TX_PTR_L_SHFT                                                              0

#define HWIO_DMA_TX_PTR_H_ADDR                                                              (QUPV3_SE_DMA_REG_BASE            + 0x34)
#define HWIO_DMA_TX_PTR_H_PHYS                                                              (QUPV3_SE_DMA_REG_BASE_PHYS + 0x34)
#define HWIO_DMA_TX_PTR_H_OFFS                                                              (QUPV3_SE_DMA_REG_BASE_OFFS + 0x34)
#define HWIO_DMA_TX_PTR_H_RMSK                                                              0xffffffff
#define HWIO_DMA_TX_PTR_H_IN                    \
                in_dword(HWIO_DMA_TX_PTR_H_ADDR)
#define HWIO_DMA_TX_PTR_H_INM(m)            \
                in_dword_masked(HWIO_DMA_TX_PTR_H_ADDR, m)
#define HWIO_DMA_TX_PTR_H_OUT(v)            \
                out_dword(HWIO_DMA_TX_PTR_H_ADDR,v)
#define HWIO_DMA_TX_PTR_H_OUTM(m,v) \
                out_dword_masked_ns(HWIO_DMA_TX_PTR_H_ADDR,m,v,HWIO_DMA_TX_PTR_H_IN)
#define HWIO_DMA_TX_PTR_H_TX_PTR_H_BMSK                                                     0xffffffff
#define HWIO_DMA_TX_PTR_H_TX_PTR_H_SHFT                                                              0

#define HWIO_DMA_TX_ATTR_ADDR                                                               (QUPV3_SE_DMA_REG_BASE            + 0x38)
#define HWIO_DMA_TX_ATTR_PHYS                                                               (QUPV3_SE_DMA_REG_BASE_PHYS + 0x38)
#define HWIO_DMA_TX_ATTR_OFFS                                                               (QUPV3_SE_DMA_REG_BASE_OFFS + 0x38)
#define HWIO_DMA_TX_ATTR_RMSK                                                                    0xf0f
#define HWIO_DMA_TX_ATTR_IN                    \
                in_dword(HWIO_DMA_TX_ATTR_ADDR)
#define HWIO_DMA_TX_ATTR_INM(m)            \
                in_dword_masked(HWIO_DMA_TX_ATTR_ADDR, m)
#define HWIO_DMA_TX_ATTR_OUT(v)            \
                out_dword(HWIO_DMA_TX_ATTR_ADDR,v)
#define HWIO_DMA_TX_ATTR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_DMA_TX_ATTR_ADDR,m,v,HWIO_DMA_TX_ATTR_IN)
#define HWIO_DMA_TX_ATTR_GPII_INDEX_BMSK                                                         0xf00
#define HWIO_DMA_TX_ATTR_GPII_INDEX_SHFT                                                             8
#define HWIO_DMA_TX_ATTR_REQ_PRIORITY_BMSK                                                         0x8
#define HWIO_DMA_TX_ATTR_REQ_PRIORITY_SHFT                                                           3
#define HWIO_DMA_TX_ATTR_DMA_OPERATION_BMSK                                                        0x6
#define HWIO_DMA_TX_ATTR_DMA_OPERATION_SHFT                                                          1
#define HWIO_DMA_TX_ATTR_EOT_BMSK                                                                  0x1
#define HWIO_DMA_TX_ATTR_EOT_SHFT                                                                    0

#define HWIO_DMA_TX_LENGTH_ADDR                                                             (QUPV3_SE_DMA_REG_BASE            + 0x3c)
#define HWIO_DMA_TX_LENGTH_PHYS                                                             (QUPV3_SE_DMA_REG_BASE_PHYS + 0x3c)
#define HWIO_DMA_TX_LENGTH_OFFS                                                             (QUPV3_SE_DMA_REG_BASE_OFFS + 0x3c)
#define HWIO_DMA_TX_LENGTH_RMSK                                                               0xffffff
#define HWIO_DMA_TX_LENGTH_IN                    \
                in_dword(HWIO_DMA_TX_LENGTH_ADDR)
#define HWIO_DMA_TX_LENGTH_INM(m)            \
                in_dword_masked(HWIO_DMA_TX_LENGTH_ADDR, m)
#define HWIO_DMA_TX_LENGTH_OUT(v)            \
                out_dword(HWIO_DMA_TX_LENGTH_ADDR,v)
#define HWIO_DMA_TX_LENGTH_OUTM(m,v) \
                out_dword_masked_ns(HWIO_DMA_TX_LENGTH_ADDR,m,v,HWIO_DMA_TX_LENGTH_IN)
#define HWIO_DMA_TX_LENGTH_TX_LENGTH_BMSK                                                     0xffffff
#define HWIO_DMA_TX_LENGTH_TX_LENGTH_SHFT                                                            0

#define HWIO_DMA_TX_IRQ_STAT_ADDR                                                           (QUPV3_SE_DMA_REG_BASE            + 0x40)
#define HWIO_DMA_TX_IRQ_STAT_PHYS                                                           (QUPV3_SE_DMA_REG_BASE_PHYS + 0x40)
#define HWIO_DMA_TX_IRQ_STAT_OFFS                                                           (QUPV3_SE_DMA_REG_BASE_OFFS + 0x40)
#define HWIO_DMA_TX_IRQ_STAT_RMSK                                                              0x7dfef
#define HWIO_DMA_TX_IRQ_STAT_IN                    \
                in_dword(HWIO_DMA_TX_IRQ_STAT_ADDR)
#define HWIO_DMA_TX_IRQ_STAT_INM(m)            \
                in_dword_masked(HWIO_DMA_TX_IRQ_STAT_ADDR, m)
#define HWIO_DMA_TX_IRQ_STAT_TX_DMA_TIMEOUT_BMSK                                               0x40000
#define HWIO_DMA_TX_IRQ_STAT_TX_DMA_TIMEOUT_SHFT                                                    18
#define HWIO_DMA_TX_IRQ_STAT_EOT_2_BMSK                                                        0x20000
#define HWIO_DMA_TX_IRQ_STAT_EOT_2_SHFT                                                             17
#define HWIO_DMA_TX_IRQ_STAT_DMA_2_DONE_BMSK                                                   0x10000
#define HWIO_DMA_TX_IRQ_STAT_DMA_2_DONE_SHFT                                                        16
#define HWIO_DMA_TX_IRQ_STAT_GENI_CMD_FAILURE_BMSK                                              0x8000
#define HWIO_DMA_TX_IRQ_STAT_GENI_CMD_FAILURE_SHFT                                                  15
#define HWIO_DMA_TX_IRQ_STAT_GENI_CANCEL_IRQ_BMSK                                               0x4000
#define HWIO_DMA_TX_IRQ_STAT_GENI_CANCEL_IRQ_SHFT                                                   14
#define HWIO_DMA_TX_IRQ_STAT_GENI_GP_IRQ_BMSK                                                   0x1fe0
#define HWIO_DMA_TX_IRQ_STAT_GENI_GP_IRQ_SHFT                                                        5
#define HWIO_DMA_TX_IRQ_STAT_RESET_DONE_BMSK                                                       0x8
#define HWIO_DMA_TX_IRQ_STAT_RESET_DONE_SHFT                                                         3
#define HWIO_DMA_TX_IRQ_STAT_SBE_BMSK                                                              0x4
#define HWIO_DMA_TX_IRQ_STAT_SBE_SHFT                                                                2
#define HWIO_DMA_TX_IRQ_STAT_EOT_BMSK                                                              0x2
#define HWIO_DMA_TX_IRQ_STAT_EOT_SHFT                                                                1
#define HWIO_DMA_TX_IRQ_STAT_DMA_DONE_BMSK                                                         0x1
#define HWIO_DMA_TX_IRQ_STAT_DMA_DONE_SHFT                                                           0

#define HWIO_DMA_TX_IRQ_CLR_ADDR                                                            (QUPV3_SE_DMA_REG_BASE            + 0x44)
#define HWIO_DMA_TX_IRQ_CLR_PHYS                                                            (QUPV3_SE_DMA_REG_BASE_PHYS + 0x44)
#define HWIO_DMA_TX_IRQ_CLR_OFFS                                                            (QUPV3_SE_DMA_REG_BASE_OFFS + 0x44)
#define HWIO_DMA_TX_IRQ_CLR_RMSK                                                               0x7dfef
#define HWIO_DMA_TX_IRQ_CLR_OUT(v)            \
                out_dword(HWIO_DMA_TX_IRQ_CLR_ADDR,v)
#define HWIO_DMA_TX_IRQ_CLR_TX_DMA_TIMEOUT_CLR_BMSK                                            0x40000
#define HWIO_DMA_TX_IRQ_CLR_TX_DMA_TIMEOUT_CLR_SHFT                                                 18
#define HWIO_DMA_TX_IRQ_CLR_EOT_2_CLR_BMSK                                                     0x20000
#define HWIO_DMA_TX_IRQ_CLR_EOT_2_CLR_SHFT                                                          17
#define HWIO_DMA_TX_IRQ_CLR_DMA_2_DONE_CLR_BMSK                                                0x10000
#define HWIO_DMA_TX_IRQ_CLR_DMA_2_DONE_CLR_SHFT                                                     16
#define HWIO_DMA_TX_IRQ_CLR_GENI_CMD_FAILURE_CLR_BMSK                                           0x8000
#define HWIO_DMA_TX_IRQ_CLR_GENI_CMD_FAILURE_CLR_SHFT                                               15
#define HWIO_DMA_TX_IRQ_CLR_GENI_CANCEL_IRQ_CLR_BMSK                                            0x4000
#define HWIO_DMA_TX_IRQ_CLR_GENI_CANCEL_IRQ_CLR_SHFT                                                14
#define HWIO_DMA_TX_IRQ_CLR_GENI_GP_IRQ_CLR_BMSK                                                0x1fe0
#define HWIO_DMA_TX_IRQ_CLR_GENI_GP_IRQ_CLR_SHFT                                                     5
#define HWIO_DMA_TX_IRQ_CLR_RESET_DONE_CLR_BMSK                                                    0x8
#define HWIO_DMA_TX_IRQ_CLR_RESET_DONE_CLR_SHFT                                                      3
#define HWIO_DMA_TX_IRQ_CLR_SBE_CLR_BMSK                                                           0x4
#define HWIO_DMA_TX_IRQ_CLR_SBE_CLR_SHFT                                                             2
#define HWIO_DMA_TX_IRQ_CLR_EOT_CLR_BMSK                                                           0x2
#define HWIO_DMA_TX_IRQ_CLR_EOT_CLR_SHFT                                                             1
#define HWIO_DMA_TX_IRQ_CLR_DMA_DONE_CLR_BMSK                                                      0x1
#define HWIO_DMA_TX_IRQ_CLR_DMA_DONE_CLR_SHFT                                                        0

#define HWIO_DMA_TX_IRQ_EN_ADDR                                                             (QUPV3_SE_DMA_REG_BASE            + 0x48)
#define HWIO_DMA_TX_IRQ_EN_PHYS                                                             (QUPV3_SE_DMA_REG_BASE_PHYS + 0x48)
#define HWIO_DMA_TX_IRQ_EN_OFFS                                                             (QUPV3_SE_DMA_REG_BASE_OFFS + 0x48)
#define HWIO_DMA_TX_IRQ_EN_RMSK                                                                0x7dfef
#define HWIO_DMA_TX_IRQ_EN_IN                    \
                in_dword(HWIO_DMA_TX_IRQ_EN_ADDR)
#define HWIO_DMA_TX_IRQ_EN_INM(m)            \
                in_dword_masked(HWIO_DMA_TX_IRQ_EN_ADDR, m)
#define HWIO_DMA_TX_IRQ_EN_TX_DMA_TIMEOUT_EN_BMSK                                              0x40000
#define HWIO_DMA_TX_IRQ_EN_TX_DMA_TIMEOUT_EN_SHFT                                                   18
#define HWIO_DMA_TX_IRQ_EN_EOT_2_EN_BMSK                                                       0x20000
#define HWIO_DMA_TX_IRQ_EN_EOT_2_EN_SHFT                                                            17
#define HWIO_DMA_TX_IRQ_EN_DMA_2_DONE_EN_BMSK                                                  0x10000
#define HWIO_DMA_TX_IRQ_EN_DMA_2_DONE_EN_SHFT                                                       16
#define HWIO_DMA_TX_IRQ_EN_GENI_CMD_FAILURE_EN_BMSK                                             0x8000
#define HWIO_DMA_TX_IRQ_EN_GENI_CMD_FAILURE_EN_SHFT                                                 15
#define HWIO_DMA_TX_IRQ_EN_GENI_CANCEL_IRQ_EN_BMSK                                              0x4000
#define HWIO_DMA_TX_IRQ_EN_GENI_CANCEL_IRQ_EN_SHFT                                                  14
#define HWIO_DMA_TX_IRQ_EN_GENI_GP_IRQ_EN_BMSK                                                  0x1fe0
#define HWIO_DMA_TX_IRQ_EN_GENI_GP_IRQ_EN_SHFT                                                       5
#define HWIO_DMA_TX_IRQ_EN_RESET_DONE_EN_BMSK                                                      0x8
#define HWIO_DMA_TX_IRQ_EN_RESET_DONE_EN_SHFT                                                        3
#define HWIO_DMA_TX_IRQ_EN_SBE_EN_BMSK                                                             0x4
#define HWIO_DMA_TX_IRQ_EN_SBE_EN_SHFT                                                               2
#define HWIO_DMA_TX_IRQ_EN_EOT_EN_BMSK                                                             0x2
#define HWIO_DMA_TX_IRQ_EN_EOT_EN_SHFT                                                               1
#define HWIO_DMA_TX_IRQ_EN_DMA_DONE_EN_BMSK                                                        0x1
#define HWIO_DMA_TX_IRQ_EN_DMA_DONE_EN_SHFT                                                          0

#define HWIO_DMA_TX_IRQ_EN_SET_ADDR                                                         (QUPV3_SE_DMA_REG_BASE            + 0x4c)
#define HWIO_DMA_TX_IRQ_EN_SET_PHYS                                                         (QUPV3_SE_DMA_REG_BASE_PHYS + 0x4c)
#define HWIO_DMA_TX_IRQ_EN_SET_OFFS                                                         (QUPV3_SE_DMA_REG_BASE_OFFS + 0x4c)
#define HWIO_DMA_TX_IRQ_EN_SET_RMSK                                                            0x7dfef
#define HWIO_DMA_TX_IRQ_EN_SET_OUT(v)            \
                out_dword(HWIO_DMA_TX_IRQ_EN_SET_ADDR,v)
#define HWIO_DMA_TX_IRQ_EN_SET_TX_DMA_TIMEOUT_EN_SET_BMSK                                      0x40000
#define HWIO_DMA_TX_IRQ_EN_SET_TX_DMA_TIMEOUT_EN_SET_SHFT                                           18
#define HWIO_DMA_TX_IRQ_EN_SET_EOT_2_EN_SET_BMSK                                               0x20000
#define HWIO_DMA_TX_IRQ_EN_SET_EOT_2_EN_SET_SHFT                                                    17
#define HWIO_DMA_TX_IRQ_EN_SET_DMA_2_DONE_EN_SET_BMSK                                          0x10000
#define HWIO_DMA_TX_IRQ_EN_SET_DMA_2_DONE_EN_SET_SHFT                                               16
#define HWIO_DMA_TX_IRQ_EN_SET_GENI_CMD_FAILURE_EN_SET_BMSK                                     0x8000
#define HWIO_DMA_TX_IRQ_EN_SET_GENI_CMD_FAILURE_EN_SET_SHFT                                         15
#define HWIO_DMA_TX_IRQ_EN_SET_GENI_CANCEL_IRQ_EN_SET_BMSK                                      0x4000
#define HWIO_DMA_TX_IRQ_EN_SET_GENI_CANCEL_IRQ_EN_SET_SHFT                                          14
#define HWIO_DMA_TX_IRQ_EN_SET_GENI_GP_IRQ_EN_SET_BMSK                                          0x1fe0
#define HWIO_DMA_TX_IRQ_EN_SET_GENI_GP_IRQ_EN_SET_SHFT                                               5
#define HWIO_DMA_TX_IRQ_EN_SET_RESET_DONE_EN_SET_BMSK                                              0x8
#define HWIO_DMA_TX_IRQ_EN_SET_RESET_DONE_EN_SET_SHFT                                                3
#define HWIO_DMA_TX_IRQ_EN_SET_SBE_EN_SET_BMSK                                                     0x4
#define HWIO_DMA_TX_IRQ_EN_SET_SBE_EN_SET_SHFT                                                       2
#define HWIO_DMA_TX_IRQ_EN_SET_EOT_EN_SET_BMSK                                                     0x2
#define HWIO_DMA_TX_IRQ_EN_SET_EOT_EN_SET_SHFT                                                       1
#define HWIO_DMA_TX_IRQ_EN_SET_DMA_DONE_EN_SET_BMSK                                                0x1
#define HWIO_DMA_TX_IRQ_EN_SET_DMA_DONE_EN_SET_SHFT                                                  0

#define HWIO_DMA_TX_IRQ_EN_CLR_ADDR                                                         (QUPV3_SE_DMA_REG_BASE            + 0x50)
#define HWIO_DMA_TX_IRQ_EN_CLR_PHYS                                                         (QUPV3_SE_DMA_REG_BASE_PHYS + 0x50)
#define HWIO_DMA_TX_IRQ_EN_CLR_OFFS                                                         (QUPV3_SE_DMA_REG_BASE_OFFS + 0x50)
#define HWIO_DMA_TX_IRQ_EN_CLR_RMSK                                                            0x7dfef
#define HWIO_DMA_TX_IRQ_EN_CLR_OUT(v)            \
                out_dword(HWIO_DMA_TX_IRQ_EN_CLR_ADDR,v)
#define HWIO_DMA_TX_IRQ_EN_CLR_TX_DMA_TIMEOUT_EN_CLR_BMSK                                      0x40000
#define HWIO_DMA_TX_IRQ_EN_CLR_TX_DMA_TIMEOUT_EN_CLR_SHFT                                           18
#define HWIO_DMA_TX_IRQ_EN_CLR_EOT_2_EN_CLR_BMSK                                               0x20000
#define HWIO_DMA_TX_IRQ_EN_CLR_EOT_2_EN_CLR_SHFT                                                    17
#define HWIO_DMA_TX_IRQ_EN_CLR_DMA_2_DONE_EN_CLR_BMSK                                          0x10000
#define HWIO_DMA_TX_IRQ_EN_CLR_DMA_2_DONE_EN_CLR_SHFT                                               16
#define HWIO_DMA_TX_IRQ_EN_CLR_GENI_CMD_FAILURE_EN_CLR_BMSK                                     0x8000
#define HWIO_DMA_TX_IRQ_EN_CLR_GENI_CMD_FAILURE_EN_CLR_SHFT                                         15
#define HWIO_DMA_TX_IRQ_EN_CLR_GENI_CANCEL_IRQ_EN_CLR_BMSK                                      0x4000
#define HWIO_DMA_TX_IRQ_EN_CLR_GENI_CANCEL_IRQ_EN_CLR_SHFT                                          14
#define HWIO_DMA_TX_IRQ_EN_CLR_GENI_GP_IRQ_EN_CLR_BMSK                                          0x1fe0
#define HWIO_DMA_TX_IRQ_EN_CLR_GENI_GP_IRQ_EN_CLR_SHFT                                               5
#define HWIO_DMA_TX_IRQ_EN_CLR_RESET_DONE_EN_CLR_BMSK                                              0x8
#define HWIO_DMA_TX_IRQ_EN_CLR_RESET_DONE_EN_CLR_SHFT                                                3
#define HWIO_DMA_TX_IRQ_EN_CLR_SBE_EN_CLR_BMSK                                                     0x4
#define HWIO_DMA_TX_IRQ_EN_CLR_SBE_EN_CLR_SHFT                                                       2
#define HWIO_DMA_TX_IRQ_EN_CLR_EOT_EN_CLR_BMSK                                                     0x2
#define HWIO_DMA_TX_IRQ_EN_CLR_EOT_EN_CLR_SHFT                                                       1
#define HWIO_DMA_TX_IRQ_EN_CLR_DMA_DONE_EN_CLR_BMSK                                                0x1
#define HWIO_DMA_TX_IRQ_EN_CLR_DMA_DONE_EN_CLR_SHFT                                                  0

#define HWIO_DMA_TX_LENGTH_IN_ADDR                                                          (QUPV3_SE_DMA_REG_BASE            + 0x54)
#define HWIO_DMA_TX_LENGTH_IN_PHYS                                                          (QUPV3_SE_DMA_REG_BASE_PHYS + 0x54)
#define HWIO_DMA_TX_LENGTH_IN_OFFS                                                          (QUPV3_SE_DMA_REG_BASE_OFFS + 0x54)
#define HWIO_DMA_TX_LENGTH_IN_RMSK                                                            0xffffff
#define HWIO_DMA_TX_LENGTH_IN_IN                    \
                in_dword(HWIO_DMA_TX_LENGTH_IN_ADDR)
#define HWIO_DMA_TX_LENGTH_IN_INM(m)            \
                in_dword_masked(HWIO_DMA_TX_LENGTH_IN_ADDR, m)
#define HWIO_DMA_TX_LENGTH_IN_TX_LENGTH_IN_BMSK                                               0xffffff
#define HWIO_DMA_TX_LENGTH_IN_TX_LENGTH_IN_SHFT                                                      0

#define HWIO_DMA_TX_FSM_RST_ADDR                                                            (QUPV3_SE_DMA_REG_BASE            + 0x58)
#define HWIO_DMA_TX_FSM_RST_PHYS                                                            (QUPV3_SE_DMA_REG_BASE_PHYS + 0x58)
#define HWIO_DMA_TX_FSM_RST_OFFS                                                            (QUPV3_SE_DMA_REG_BASE_OFFS + 0x58)
#define HWIO_DMA_TX_FSM_RST_RMSK                                                                   0x1
#define HWIO_DMA_TX_FSM_RST_IN                    \
                in_dword(HWIO_DMA_TX_FSM_RST_ADDR)
#define HWIO_DMA_TX_FSM_RST_INM(m)            \
                in_dword_masked(HWIO_DMA_TX_FSM_RST_ADDR, m)
#define HWIO_DMA_TX_FSM_RST_OUT(v)            \
                out_dword(HWIO_DMA_TX_FSM_RST_ADDR,v)
#define HWIO_DMA_TX_FSM_RST_OUTM(m,v) \
                out_dword_masked_ns(HWIO_DMA_TX_FSM_RST_ADDR,m,v,HWIO_DMA_TX_FSM_RST_IN)
#define HWIO_DMA_TX_FSM_RST_TX_FSM_RST_BMSK                                                        0x1
#define HWIO_DMA_TX_FSM_RST_TX_FSM_RST_SHFT                                                          0

#define HWIO_DMA_TX_MAX_BURST_SIZE_ADDR                                                     (QUPV3_SE_DMA_REG_BASE            + 0x5c)
#define HWIO_DMA_TX_MAX_BURST_SIZE_PHYS                                                     (QUPV3_SE_DMA_REG_BASE_PHYS + 0x5c)
#define HWIO_DMA_TX_MAX_BURST_SIZE_OFFS                                                     (QUPV3_SE_DMA_REG_BASE_OFFS + 0x5c)
#define HWIO_DMA_TX_MAX_BURST_SIZE_RMSK                                                            0x3
#define HWIO_DMA_TX_MAX_BURST_SIZE_IN                    \
                in_dword(HWIO_DMA_TX_MAX_BURST_SIZE_ADDR)
#define HWIO_DMA_TX_MAX_BURST_SIZE_INM(m)            \
                in_dword_masked(HWIO_DMA_TX_MAX_BURST_SIZE_ADDR, m)
#define HWIO_DMA_TX_MAX_BURST_SIZE_OUT(v)            \
                out_dword(HWIO_DMA_TX_MAX_BURST_SIZE_ADDR,v)
#define HWIO_DMA_TX_MAX_BURST_SIZE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_DMA_TX_MAX_BURST_SIZE_ADDR,m,v,HWIO_DMA_TX_MAX_BURST_SIZE_IN)
#define HWIO_DMA_TX_MAX_BURST_SIZE_TX_MAX_BURST_SIZE_BMSK                                          0x3
#define HWIO_DMA_TX_MAX_BURST_SIZE_TX_MAX_BURST_SIZE_SHFT                                            0

#define HWIO_DMA_2_TX_PTR_L_ADDR                                                            (QUPV3_SE_DMA_REG_BASE            + 0x60)
#define HWIO_DMA_2_TX_PTR_L_PHYS                                                            (QUPV3_SE_DMA_REG_BASE_PHYS + 0x60)
#define HWIO_DMA_2_TX_PTR_L_OFFS                                                            (QUPV3_SE_DMA_REG_BASE_OFFS + 0x60)
#define HWIO_DMA_2_TX_PTR_L_RMSK                                                            0xffffffff
#define HWIO_DMA_2_TX_PTR_L_IN                    \
                in_dword(HWIO_DMA_2_TX_PTR_L_ADDR)
#define HWIO_DMA_2_TX_PTR_L_INM(m)            \
                in_dword_masked(HWIO_DMA_2_TX_PTR_L_ADDR, m)
#define HWIO_DMA_2_TX_PTR_L_OUT(v)            \
                out_dword(HWIO_DMA_2_TX_PTR_L_ADDR,v)
#define HWIO_DMA_2_TX_PTR_L_OUTM(m,v) \
                out_dword_masked_ns(HWIO_DMA_2_TX_PTR_L_ADDR,m,v,HWIO_DMA_2_TX_PTR_L_IN)
#define HWIO_DMA_2_TX_PTR_L_TX_PTR_L_BMSK                                                   0xffffffff
#define HWIO_DMA_2_TX_PTR_L_TX_PTR_L_SHFT                                                            0

#define HWIO_DMA_2_TX_PTR_H_ADDR                                                            (QUPV3_SE_DMA_REG_BASE            + 0x64)
#define HWIO_DMA_2_TX_PTR_H_PHYS                                                            (QUPV3_SE_DMA_REG_BASE_PHYS + 0x64)
#define HWIO_DMA_2_TX_PTR_H_OFFS                                                            (QUPV3_SE_DMA_REG_BASE_OFFS + 0x64)
#define HWIO_DMA_2_TX_PTR_H_RMSK                                                            0xffffffff
#define HWIO_DMA_2_TX_PTR_H_IN                    \
                in_dword(HWIO_DMA_2_TX_PTR_H_ADDR)
#define HWIO_DMA_2_TX_PTR_H_INM(m)            \
                in_dword_masked(HWIO_DMA_2_TX_PTR_H_ADDR, m)
#define HWIO_DMA_2_TX_PTR_H_OUT(v)            \
                out_dword(HWIO_DMA_2_TX_PTR_H_ADDR,v)
#define HWIO_DMA_2_TX_PTR_H_OUTM(m,v) \
                out_dword_masked_ns(HWIO_DMA_2_TX_PTR_H_ADDR,m,v,HWIO_DMA_2_TX_PTR_H_IN)
#define HWIO_DMA_2_TX_PTR_H_TX_PTR_H_BMSK                                                   0xffffffff
#define HWIO_DMA_2_TX_PTR_H_TX_PTR_H_SHFT                                                            0

#define HWIO_DMA_2_TX_ATTR_ADDR                                                             (QUPV3_SE_DMA_REG_BASE            + 0x68)
#define HWIO_DMA_2_TX_ATTR_PHYS                                                             (QUPV3_SE_DMA_REG_BASE_PHYS + 0x68)
#define HWIO_DMA_2_TX_ATTR_OFFS                                                             (QUPV3_SE_DMA_REG_BASE_OFFS + 0x68)
#define HWIO_DMA_2_TX_ATTR_RMSK                                                                  0xf0f
#define HWIO_DMA_2_TX_ATTR_IN                    \
                in_dword(HWIO_DMA_2_TX_ATTR_ADDR)
#define HWIO_DMA_2_TX_ATTR_INM(m)            \
                in_dword_masked(HWIO_DMA_2_TX_ATTR_ADDR, m)
#define HWIO_DMA_2_TX_ATTR_OUT(v)            \
                out_dword(HWIO_DMA_2_TX_ATTR_ADDR,v)
#define HWIO_DMA_2_TX_ATTR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_DMA_2_TX_ATTR_ADDR,m,v,HWIO_DMA_2_TX_ATTR_IN)
#define HWIO_DMA_2_TX_ATTR_GPII_INDEX_BMSK                                                       0xf00
#define HWIO_DMA_2_TX_ATTR_GPII_INDEX_SHFT                                                           8
#define HWIO_DMA_2_TX_ATTR_REQ_PRIORITY_BMSK                                                       0x8
#define HWIO_DMA_2_TX_ATTR_REQ_PRIORITY_SHFT                                                         3
#define HWIO_DMA_2_TX_ATTR_DMA_OPERATION_BMSK                                                      0x6
#define HWIO_DMA_2_TX_ATTR_DMA_OPERATION_SHFT                                                        1
#define HWIO_DMA_2_TX_ATTR_EOT_BMSK                                                                0x1
#define HWIO_DMA_2_TX_ATTR_EOT_SHFT                                                                  0

#define HWIO_DMA_2_TX_LENGTH_ADDR                                                           (QUPV3_SE_DMA_REG_BASE            + 0x6c)
#define HWIO_DMA_2_TX_LENGTH_PHYS                                                           (QUPV3_SE_DMA_REG_BASE_PHYS + 0x6c)
#define HWIO_DMA_2_TX_LENGTH_OFFS                                                           (QUPV3_SE_DMA_REG_BASE_OFFS + 0x6c)
#define HWIO_DMA_2_TX_LENGTH_RMSK                                                             0xffffff
#define HWIO_DMA_2_TX_LENGTH_IN                    \
                in_dword(HWIO_DMA_2_TX_LENGTH_ADDR)
#define HWIO_DMA_2_TX_LENGTH_INM(m)            \
                in_dword_masked(HWIO_DMA_2_TX_LENGTH_ADDR, m)
#define HWIO_DMA_2_TX_LENGTH_OUT(v)            \
                out_dword(HWIO_DMA_2_TX_LENGTH_ADDR,v)
#define HWIO_DMA_2_TX_LENGTH_OUTM(m,v) \
                out_dword_masked_ns(HWIO_DMA_2_TX_LENGTH_ADDR,m,v,HWIO_DMA_2_TX_LENGTH_IN)
#define HWIO_DMA_2_TX_LENGTH_TX_LENGTH_BMSK                                                   0xffffff
#define HWIO_DMA_2_TX_LENGTH_TX_LENGTH_SHFT                                                          0

#define HWIO_DMA_2_TX_LENGTH_IN_ADDR                                                        (QUPV3_SE_DMA_REG_BASE            + 0x70)
#define HWIO_DMA_2_TX_LENGTH_IN_PHYS                                                        (QUPV3_SE_DMA_REG_BASE_PHYS + 0x70)
#define HWIO_DMA_2_TX_LENGTH_IN_OFFS                                                        (QUPV3_SE_DMA_REG_BASE_OFFS + 0x70)
#define HWIO_DMA_2_TX_LENGTH_IN_RMSK                                                          0xffffff
#define HWIO_DMA_2_TX_LENGTH_IN_OUT(v)            \
                out_dword(HWIO_DMA_2_TX_LENGTH_IN_ADDR,v)
#define HWIO_DMA_2_TX_LENGTH_IN_TX_LENGTH_IN_BMSK                                             0xffffff
#define HWIO_DMA_2_TX_LENGTH_IN_TX_LENGTH_IN_SHFT                                                    0

#define HWIO_DMA_RX_PTR_L_ADDR                                                              (QUPV3_SE_DMA_REG_BASE            + 0x130)
#define HWIO_DMA_RX_PTR_L_PHYS                                                              (QUPV3_SE_DMA_REG_BASE_PHYS + 0x130)
#define HWIO_DMA_RX_PTR_L_OFFS                                                              (QUPV3_SE_DMA_REG_BASE_OFFS + 0x130)
#define HWIO_DMA_RX_PTR_L_RMSK                                                              0xffffffff
#define HWIO_DMA_RX_PTR_L_IN                    \
                in_dword(HWIO_DMA_RX_PTR_L_ADDR)
#define HWIO_DMA_RX_PTR_L_INM(m)            \
                in_dword_masked(HWIO_DMA_RX_PTR_L_ADDR, m)
#define HWIO_DMA_RX_PTR_L_OUT(v)            \
                out_dword(HWIO_DMA_RX_PTR_L_ADDR,v)
#define HWIO_DMA_RX_PTR_L_OUTM(m,v) \
                out_dword_masked_ns(HWIO_DMA_RX_PTR_L_ADDR,m,v,HWIO_DMA_RX_PTR_L_IN)
#define HWIO_DMA_RX_PTR_L_RX_PTR_L_BMSK                                                     0xffffffff
#define HWIO_DMA_RX_PTR_L_RX_PTR_L_SHFT                                                              0

#define HWIO_DMA_RX_PTR_H_ADDR                                                              (QUPV3_SE_DMA_REG_BASE            + 0x134)
#define HWIO_DMA_RX_PTR_H_PHYS                                                              (QUPV3_SE_DMA_REG_BASE_PHYS + 0x134)
#define HWIO_DMA_RX_PTR_H_OFFS                                                              (QUPV3_SE_DMA_REG_BASE_OFFS + 0x134)
#define HWIO_DMA_RX_PTR_H_RMSK                                                              0xffffffff
#define HWIO_DMA_RX_PTR_H_IN                    \
                in_dword(HWIO_DMA_RX_PTR_H_ADDR)
#define HWIO_DMA_RX_PTR_H_INM(m)            \
                in_dword_masked(HWIO_DMA_RX_PTR_H_ADDR, m)
#define HWIO_DMA_RX_PTR_H_OUT(v)            \
                out_dword(HWIO_DMA_RX_PTR_H_ADDR,v)
#define HWIO_DMA_RX_PTR_H_OUTM(m,v) \
                out_dword_masked_ns(HWIO_DMA_RX_PTR_H_ADDR,m,v,HWIO_DMA_RX_PTR_H_IN)
#define HWIO_DMA_RX_PTR_H_RX_PTR_H_BMSK                                                     0xffffffff
#define HWIO_DMA_RX_PTR_H_RX_PTR_H_SHFT                                                              0

#define HWIO_DMA_RX_ATTR_ADDR                                                               (QUPV3_SE_DMA_REG_BASE            + 0x138)
#define HWIO_DMA_RX_ATTR_PHYS                                                               (QUPV3_SE_DMA_REG_BASE_PHYS + 0x138)
#define HWIO_DMA_RX_ATTR_OFFS                                                               (QUPV3_SE_DMA_REG_BASE_OFFS + 0x138)
#define HWIO_DMA_RX_ATTR_RMSK                                                                    0xf0e
#define HWIO_DMA_RX_ATTR_IN                    \
                in_dword(HWIO_DMA_RX_ATTR_ADDR)
#define HWIO_DMA_RX_ATTR_INM(m)            \
                in_dword_masked(HWIO_DMA_RX_ATTR_ADDR, m)
#define HWIO_DMA_RX_ATTR_OUT(v)            \
                out_dword(HWIO_DMA_RX_ATTR_ADDR,v)
#define HWIO_DMA_RX_ATTR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_DMA_RX_ATTR_ADDR,m,v,HWIO_DMA_RX_ATTR_IN)
#define HWIO_DMA_RX_ATTR_GPII_INDEX_BMSK                                                         0xf00
#define HWIO_DMA_RX_ATTR_GPII_INDEX_SHFT                                                             8
#define HWIO_DMA_RX_ATTR_REQ_PRIORITY_BMSK                                                         0x8
#define HWIO_DMA_RX_ATTR_REQ_PRIORITY_SHFT                                                           3
#define HWIO_DMA_RX_ATTR_DMA_OPERATION_BMSK                                                        0x6
#define HWIO_DMA_RX_ATTR_DMA_OPERATION_SHFT                                                          1

#define HWIO_DMA_RX_LENGTH_ADDR                                                             (QUPV3_SE_DMA_REG_BASE            + 0x13c)
#define HWIO_DMA_RX_LENGTH_PHYS                                                             (QUPV3_SE_DMA_REG_BASE_PHYS + 0x13c)
#define HWIO_DMA_RX_LENGTH_OFFS                                                             (QUPV3_SE_DMA_REG_BASE_OFFS + 0x13c)
#define HWIO_DMA_RX_LENGTH_RMSK                                                               0xffffff
#define HWIO_DMA_RX_LENGTH_IN                    \
                in_dword(HWIO_DMA_RX_LENGTH_ADDR)
#define HWIO_DMA_RX_LENGTH_INM(m)            \
                in_dword_masked(HWIO_DMA_RX_LENGTH_ADDR, m)
#define HWIO_DMA_RX_LENGTH_OUT(v)            \
                out_dword(HWIO_DMA_RX_LENGTH_ADDR,v)
#define HWIO_DMA_RX_LENGTH_OUTM(m,v) \
                out_dword_masked_ns(HWIO_DMA_RX_LENGTH_ADDR,m,v,HWIO_DMA_RX_LENGTH_IN)
#define HWIO_DMA_RX_LENGTH_RX_LENGTH_BMSK                                                     0xffffff
#define HWIO_DMA_RX_LENGTH_RX_LENGTH_SHFT                                                            0

#define HWIO_DMA_RX_IRQ_STAT_ADDR                                                           (QUPV3_SE_DMA_REG_BASE            + 0x140)
#define HWIO_DMA_RX_IRQ_STAT_PHYS                                                           (QUPV3_SE_DMA_REG_BASE_PHYS + 0x140)
#define HWIO_DMA_RX_IRQ_STAT_OFFS                                                           (QUPV3_SE_DMA_REG_BASE_OFFS + 0x140)
#define HWIO_DMA_RX_IRQ_STAT_RMSK                                                              0x7dfff
#define HWIO_DMA_RX_IRQ_STAT_IN                    \
                in_dword(HWIO_DMA_RX_IRQ_STAT_ADDR)
#define HWIO_DMA_RX_IRQ_STAT_INM(m)            \
                in_dword_masked(HWIO_DMA_RX_IRQ_STAT_ADDR, m)
#define HWIO_DMA_RX_IRQ_STAT_RX_DMA_TIMEOUT_BMSK                                               0x40000
#define HWIO_DMA_RX_IRQ_STAT_RX_DMA_TIMEOUT_SHFT                                                    18
#define HWIO_DMA_RX_IRQ_STAT_EOT_2_BMSK                                                        0x20000
#define HWIO_DMA_RX_IRQ_STAT_EOT_2_SHFT                                                             17
#define HWIO_DMA_RX_IRQ_STAT_DMA_2_DONE_BMSK                                                   0x10000
#define HWIO_DMA_RX_IRQ_STAT_DMA_2_DONE_SHFT                                                        16
#define HWIO_DMA_RX_IRQ_STAT_GENI_CMD_FAILURE_BMSK                                              0x8000
#define HWIO_DMA_RX_IRQ_STAT_GENI_CMD_FAILURE_SHFT                                                  15
#define HWIO_DMA_RX_IRQ_STAT_GENI_CANCEL_IRQ_BMSK                                               0x4000
#define HWIO_DMA_RX_IRQ_STAT_GENI_CANCEL_IRQ_SHFT                                                   14
#define HWIO_DMA_RX_IRQ_STAT_GENI_GP_IRQ_BMSK                                                   0x1fe0
#define HWIO_DMA_RX_IRQ_STAT_GENI_GP_IRQ_SHFT                                                        5
#define HWIO_DMA_RX_IRQ_STAT_FLUSH_DONE_BMSK                                                      0x10
#define HWIO_DMA_RX_IRQ_STAT_FLUSH_DONE_SHFT                                                         4
#define HWIO_DMA_RX_IRQ_STAT_RESET_DONE_BMSK                                                       0x8
#define HWIO_DMA_RX_IRQ_STAT_RESET_DONE_SHFT                                                         3
#define HWIO_DMA_RX_IRQ_STAT_SBE_BMSK                                                              0x4
#define HWIO_DMA_RX_IRQ_STAT_SBE_SHFT                                                                2
#define HWIO_DMA_RX_IRQ_STAT_EOT_BMSK                                                              0x2
#define HWIO_DMA_RX_IRQ_STAT_EOT_SHFT                                                                1
#define HWIO_DMA_RX_IRQ_STAT_DMA_DONE_BMSK                                                         0x1
#define HWIO_DMA_RX_IRQ_STAT_DMA_DONE_SHFT                                                           0

#define HWIO_DMA_RX_IRQ_CLR_ADDR                                                            (QUPV3_SE_DMA_REG_BASE            + 0x144)
#define HWIO_DMA_RX_IRQ_CLR_PHYS                                                            (QUPV3_SE_DMA_REG_BASE_PHYS + 0x144)
#define HWIO_DMA_RX_IRQ_CLR_OFFS                                                            (QUPV3_SE_DMA_REG_BASE_OFFS + 0x144)
#define HWIO_DMA_RX_IRQ_CLR_RMSK                                                               0x7dfff
#define HWIO_DMA_RX_IRQ_CLR_OUT(v)            \
                out_dword(HWIO_DMA_RX_IRQ_CLR_ADDR,v)
#define HWIO_DMA_RX_IRQ_CLR_RX_DMA_TIMEOUT_CLR_BMSK                                            0x40000
#define HWIO_DMA_RX_IRQ_CLR_RX_DMA_TIMEOUT_CLR_SHFT                                                 18
#define HWIO_DMA_RX_IRQ_CLR_EOT_2_CLR_BMSK                                                     0x20000
#define HWIO_DMA_RX_IRQ_CLR_EOT_2_CLR_SHFT                                                          17
#define HWIO_DMA_RX_IRQ_CLR_DMA_2_DONE_CLR_BMSK                                                0x10000
#define HWIO_DMA_RX_IRQ_CLR_DMA_2_DONE_CLR_SHFT                                                     16
#define HWIO_DMA_RX_IRQ_CLR_GENI_CMD_FAILURE_CLR_BMSK                                           0x8000
#define HWIO_DMA_RX_IRQ_CLR_GENI_CMD_FAILURE_CLR_SHFT                                               15
#define HWIO_DMA_RX_IRQ_CLR_GENI_CANCEL_IRQ_CLR_BMSK                                            0x4000
#define HWIO_DMA_RX_IRQ_CLR_GENI_CANCEL_IRQ_CLR_SHFT                                                14
#define HWIO_DMA_RX_IRQ_CLR_GENI_GP_IRQ_CLR_BMSK                                                0x1fe0
#define HWIO_DMA_RX_IRQ_CLR_GENI_GP_IRQ_CLR_SHFT                                                     5
#define HWIO_DMA_RX_IRQ_CLR_FLUSH_DONE_CLR_BMSK                                                   0x10
#define HWIO_DMA_RX_IRQ_CLR_FLUSH_DONE_CLR_SHFT                                                      4
#define HWIO_DMA_RX_IRQ_CLR_RESET_DONE_CLR_BMSK                                                    0x8
#define HWIO_DMA_RX_IRQ_CLR_RESET_DONE_CLR_SHFT                                                      3
#define HWIO_DMA_RX_IRQ_CLR_SBE_CLR_BMSK                                                           0x4
#define HWIO_DMA_RX_IRQ_CLR_SBE_CLR_SHFT                                                             2
#define HWIO_DMA_RX_IRQ_CLR_EOT_CLR_BMSK                                                           0x2
#define HWIO_DMA_RX_IRQ_CLR_EOT_CLR_SHFT                                                             1
#define HWIO_DMA_RX_IRQ_CLR_DMA_DONE_CLR_BMSK                                                      0x1
#define HWIO_DMA_RX_IRQ_CLR_DMA_DONE_CLR_SHFT                                                        0

#define HWIO_DMA_RX_IRQ_EN_ADDR                                                             (QUPV3_SE_DMA_REG_BASE            + 0x148)
#define HWIO_DMA_RX_IRQ_EN_PHYS                                                             (QUPV3_SE_DMA_REG_BASE_PHYS + 0x148)
#define HWIO_DMA_RX_IRQ_EN_OFFS                                                             (QUPV3_SE_DMA_REG_BASE_OFFS + 0x148)
#define HWIO_DMA_RX_IRQ_EN_RMSK                                                                0x7dfff
#define HWIO_DMA_RX_IRQ_EN_IN                    \
                in_dword(HWIO_DMA_RX_IRQ_EN_ADDR)
#define HWIO_DMA_RX_IRQ_EN_INM(m)            \
                in_dword_masked(HWIO_DMA_RX_IRQ_EN_ADDR, m)
#define HWIO_DMA_RX_IRQ_EN_RX_DMA_TIMEOUT_EN_BMSK                                              0x40000
#define HWIO_DMA_RX_IRQ_EN_RX_DMA_TIMEOUT_EN_SHFT                                                   18
#define HWIO_DMA_RX_IRQ_EN_EOT_2_EN_BMSK                                                       0x20000
#define HWIO_DMA_RX_IRQ_EN_EOT_2_EN_SHFT                                                            17
#define HWIO_DMA_RX_IRQ_EN_DMA_2_DONE_EN_BMSK                                                  0x10000
#define HWIO_DMA_RX_IRQ_EN_DMA_2_DONE_EN_SHFT                                                       16
#define HWIO_DMA_RX_IRQ_EN_GENI_CMD_FAILURE_EN_BMSK                                             0x8000
#define HWIO_DMA_RX_IRQ_EN_GENI_CMD_FAILURE_EN_SHFT                                                 15
#define HWIO_DMA_RX_IRQ_EN_GENI_CANCEL_IRQ_EN_BMSK                                              0x4000
#define HWIO_DMA_RX_IRQ_EN_GENI_CANCEL_IRQ_EN_SHFT                                                  14
#define HWIO_DMA_RX_IRQ_EN_GENI_GP_IRQ_EN_BMSK                                                  0x1fe0
#define HWIO_DMA_RX_IRQ_EN_GENI_GP_IRQ_EN_SHFT                                                       5
#define HWIO_DMA_RX_IRQ_EN_FLUSH_DONE_EN_BMSK                                                     0x10
#define HWIO_DMA_RX_IRQ_EN_FLUSH_DONE_EN_SHFT                                                        4
#define HWIO_DMA_RX_IRQ_EN_RESET_DONE_EN_BMSK                                                      0x8
#define HWIO_DMA_RX_IRQ_EN_RESET_DONE_EN_SHFT                                                        3
#define HWIO_DMA_RX_IRQ_EN_SBE_EN_BMSK                                                             0x4
#define HWIO_DMA_RX_IRQ_EN_SBE_EN_SHFT                                                               2
#define HWIO_DMA_RX_IRQ_EN_EOT_EN_BMSK                                                             0x2
#define HWIO_DMA_RX_IRQ_EN_EOT_EN_SHFT                                                               1
#define HWIO_DMA_RX_IRQ_EN_DMA_DONE_EN_BMSK                                                        0x1
#define HWIO_DMA_RX_IRQ_EN_DMA_DONE_EN_SHFT                                                          0

#define HWIO_DMA_RX_IRQ_EN_SET_ADDR                                                         (QUPV3_SE_DMA_REG_BASE            + 0x14c)
#define HWIO_DMA_RX_IRQ_EN_SET_PHYS                                                         (QUPV3_SE_DMA_REG_BASE_PHYS + 0x14c)
#define HWIO_DMA_RX_IRQ_EN_SET_OFFS                                                         (QUPV3_SE_DMA_REG_BASE_OFFS + 0x14c)
#define HWIO_DMA_RX_IRQ_EN_SET_RMSK                                                            0x7dfff
#define HWIO_DMA_RX_IRQ_EN_SET_OUT(v)            \
                out_dword(HWIO_DMA_RX_IRQ_EN_SET_ADDR,v)
#define HWIO_DMA_RX_IRQ_EN_SET_RX_DMA_TIMEOUT_EN_SET_BMSK                                      0x40000
#define HWIO_DMA_RX_IRQ_EN_SET_RX_DMA_TIMEOUT_EN_SET_SHFT                                           18
#define HWIO_DMA_RX_IRQ_EN_SET_EOT_2_EN_SET_BMSK                                               0x20000
#define HWIO_DMA_RX_IRQ_EN_SET_EOT_2_EN_SET_SHFT                                                    17
#define HWIO_DMA_RX_IRQ_EN_SET_DMA_2_DONE_EN_SET_BMSK                                          0x10000
#define HWIO_DMA_RX_IRQ_EN_SET_DMA_2_DONE_EN_SET_SHFT                                               16
#define HWIO_DMA_RX_IRQ_EN_SET_GENI_CMD_FAILURE_EN_SET_BMSK                                     0x8000
#define HWIO_DMA_RX_IRQ_EN_SET_GENI_CMD_FAILURE_EN_SET_SHFT                                         15
#define HWIO_DMA_RX_IRQ_EN_SET_GENI_CANCEL_IRQ_EN_SET_BMSK                                      0x4000
#define HWIO_DMA_RX_IRQ_EN_SET_GENI_CANCEL_IRQ_EN_SET_SHFT                                          14
#define HWIO_DMA_RX_IRQ_EN_SET_GENI_GP_IRQ_EN_SET_BMSK                                          0x1fe0
#define HWIO_DMA_RX_IRQ_EN_SET_GENI_GP_IRQ_EN_SET_SHFT                                               5
#define HWIO_DMA_RX_IRQ_EN_SET_FLUSH_DONE_EN_SET_BMSK                                             0x10
#define HWIO_DMA_RX_IRQ_EN_SET_FLUSH_DONE_EN_SET_SHFT                                                4
#define HWIO_DMA_RX_IRQ_EN_SET_RESET_DONE_EN_SET_BMSK                                              0x8
#define HWIO_DMA_RX_IRQ_EN_SET_RESET_DONE_EN_SET_SHFT                                                3
#define HWIO_DMA_RX_IRQ_EN_SET_SBE_EN_SET_BMSK                                                     0x4
#define HWIO_DMA_RX_IRQ_EN_SET_SBE_EN_SET_SHFT                                                       2
#define HWIO_DMA_RX_IRQ_EN_SET_EOT_EN_SET_BMSK                                                     0x2
#define HWIO_DMA_RX_IRQ_EN_SET_EOT_EN_SET_SHFT                                                       1
#define HWIO_DMA_RX_IRQ_EN_SET_DMA_DONE_EN_SET_BMSK                                                0x1
#define HWIO_DMA_RX_IRQ_EN_SET_DMA_DONE_EN_SET_SHFT                                                  0

#define HWIO_DMA_RX_IRQ_EN_CLR_ADDR                                                         (QUPV3_SE_DMA_REG_BASE            + 0x150)
#define HWIO_DMA_RX_IRQ_EN_CLR_PHYS                                                         (QUPV3_SE_DMA_REG_BASE_PHYS + 0x150)
#define HWIO_DMA_RX_IRQ_EN_CLR_OFFS                                                         (QUPV3_SE_DMA_REG_BASE_OFFS + 0x150)
#define HWIO_DMA_RX_IRQ_EN_CLR_RMSK                                                            0x7dfff
#define HWIO_DMA_RX_IRQ_EN_CLR_OUT(v)            \
                out_dword(HWIO_DMA_RX_IRQ_EN_CLR_ADDR,v)
#define HWIO_DMA_RX_IRQ_EN_CLR_RX_DMA_TIMEOUT_EN_CLR_BMSK                                      0x40000
#define HWIO_DMA_RX_IRQ_EN_CLR_RX_DMA_TIMEOUT_EN_CLR_SHFT                                           18
#define HWIO_DMA_RX_IRQ_EN_CLR_EOT_2_EN_CLR_BMSK                                               0x20000
#define HWIO_DMA_RX_IRQ_EN_CLR_EOT_2_EN_CLR_SHFT                                                    17
#define HWIO_DMA_RX_IRQ_EN_CLR_DMA_2_DONE_EN_CLR_BMSK                                          0x10000
#define HWIO_DMA_RX_IRQ_EN_CLR_DMA_2_DONE_EN_CLR_SHFT                                               16
#define HWIO_DMA_RX_IRQ_EN_CLR_GENI_CMD_FAILURE_EN_CLR_BMSK                                     0x8000
#define HWIO_DMA_RX_IRQ_EN_CLR_GENI_CMD_FAILURE_EN_CLR_SHFT                                         15
#define HWIO_DMA_RX_IRQ_EN_CLR_GENI_CANCEL_IRQ_EN_CLR_BMSK                                      0x4000
#define HWIO_DMA_RX_IRQ_EN_CLR_GENI_CANCEL_IRQ_EN_CLR_SHFT                                          14
#define HWIO_DMA_RX_IRQ_EN_CLR_GENI_GP_IRQ_EN_CLR_BMSK                                          0x1fe0
#define HWIO_DMA_RX_IRQ_EN_CLR_GENI_GP_IRQ_EN_CLR_SHFT                                               5
#define HWIO_DMA_RX_IRQ_EN_CLR_FLUSH_DONE_EN_CLR_BMSK                                             0x10
#define HWIO_DMA_RX_IRQ_EN_CLR_FLUSH_DONE_EN_CLR_SHFT                                                4
#define HWIO_DMA_RX_IRQ_EN_CLR_RESET_DONE_EN_CLR_BMSK                                              0x8
#define HWIO_DMA_RX_IRQ_EN_CLR_RESET_DONE_EN_CLR_SHFT                                                3
#define HWIO_DMA_RX_IRQ_EN_CLR_SBE_EN_CLR_BMSK                                                     0x4
#define HWIO_DMA_RX_IRQ_EN_CLR_SBE_EN_CLR_SHFT                                                       2
#define HWIO_DMA_RX_IRQ_EN_CLR_EOT_EN_CLR_BMSK                                                     0x2
#define HWIO_DMA_RX_IRQ_EN_CLR_EOT_EN_CLR_SHFT                                                       1
#define HWIO_DMA_RX_IRQ_EN_CLR_DMA_DONE_EN_CLR_BMSK                                                0x1
#define HWIO_DMA_RX_IRQ_EN_CLR_DMA_DONE_EN_CLR_SHFT                                                  0

#define HWIO_DMA_RX_LENGTH_IN_ADDR                                                          (QUPV3_SE_DMA_REG_BASE            + 0x154)
#define HWIO_DMA_RX_LENGTH_IN_PHYS                                                          (QUPV3_SE_DMA_REG_BASE_PHYS + 0x154)
#define HWIO_DMA_RX_LENGTH_IN_OFFS                                                          (QUPV3_SE_DMA_REG_BASE_OFFS + 0x154)
#define HWIO_DMA_RX_LENGTH_IN_RMSK                                                            0xffffff
#define HWIO_DMA_RX_LENGTH_IN_IN                    \
                in_dword(HWIO_DMA_RX_LENGTH_IN_ADDR)
#define HWIO_DMA_RX_LENGTH_IN_INM(m)            \
                in_dword_masked(HWIO_DMA_RX_LENGTH_IN_ADDR, m)
#define HWIO_DMA_RX_LENGTH_IN_RX_LENGTH_IN_BMSK                                               0xffffff
#define HWIO_DMA_RX_LENGTH_IN_RX_LENGTH_IN_SHFT                                                      0

#define HWIO_DMA_RX_FSM_RST_ADDR                                                            (QUPV3_SE_DMA_REG_BASE            + 0x158)
#define HWIO_DMA_RX_FSM_RST_PHYS                                                            (QUPV3_SE_DMA_REG_BASE_PHYS + 0x158)
#define HWIO_DMA_RX_FSM_RST_OFFS                                                            (QUPV3_SE_DMA_REG_BASE_OFFS + 0x158)
#define HWIO_DMA_RX_FSM_RST_RMSK                                                                   0x1
#define HWIO_DMA_RX_FSM_RST_IN                    \
                in_dword(HWIO_DMA_RX_FSM_RST_ADDR)
#define HWIO_DMA_RX_FSM_RST_INM(m)            \
                in_dword_masked(HWIO_DMA_RX_FSM_RST_ADDR, m)
#define HWIO_DMA_RX_FSM_RST_OUT(v)            \
                out_dword(HWIO_DMA_RX_FSM_RST_ADDR,v)
#define HWIO_DMA_RX_FSM_RST_OUTM(m,v) \
                out_dword_masked_ns(HWIO_DMA_RX_FSM_RST_ADDR,m,v,HWIO_DMA_RX_FSM_RST_IN)
#define HWIO_DMA_RX_FSM_RST_RX_FSM_RST_BMSK                                                        0x1
#define HWIO_DMA_RX_FSM_RST_RX_FSM_RST_SHFT                                                          0

#define HWIO_DMA_RX_MAX_BURST_SIZE_ADDR                                                     (QUPV3_SE_DMA_REG_BASE            + 0x15c)
#define HWIO_DMA_RX_MAX_BURST_SIZE_PHYS                                                     (QUPV3_SE_DMA_REG_BASE_PHYS + 0x15c)
#define HWIO_DMA_RX_MAX_BURST_SIZE_OFFS                                                     (QUPV3_SE_DMA_REG_BASE_OFFS + 0x15c)
#define HWIO_DMA_RX_MAX_BURST_SIZE_RMSK                                                            0x3
#define HWIO_DMA_RX_MAX_BURST_SIZE_IN                    \
                in_dword(HWIO_DMA_RX_MAX_BURST_SIZE_ADDR)
#define HWIO_DMA_RX_MAX_BURST_SIZE_INM(m)            \
                in_dword_masked(HWIO_DMA_RX_MAX_BURST_SIZE_ADDR, m)
#define HWIO_DMA_RX_MAX_BURST_SIZE_OUT(v)            \
                out_dword(HWIO_DMA_RX_MAX_BURST_SIZE_ADDR,v)
#define HWIO_DMA_RX_MAX_BURST_SIZE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_DMA_RX_MAX_BURST_SIZE_ADDR,m,v,HWIO_DMA_RX_MAX_BURST_SIZE_IN)
#define HWIO_DMA_RX_MAX_BURST_SIZE_RX_MAX_BURST_SIZE_BMSK                                          0x3
#define HWIO_DMA_RX_MAX_BURST_SIZE_RX_MAX_BURST_SIZE_SHFT                                            0

#define HWIO_DMA_RX_FLUSH_ADDR                                                              (QUPV3_SE_DMA_REG_BASE            + 0x160)
#define HWIO_DMA_RX_FLUSH_PHYS                                                              (QUPV3_SE_DMA_REG_BASE_PHYS + 0x160)
#define HWIO_DMA_RX_FLUSH_OFFS                                                              (QUPV3_SE_DMA_REG_BASE_OFFS + 0x160)
#define HWIO_DMA_RX_FLUSH_RMSK                                                                     0x1
#define HWIO_DMA_RX_FLUSH_IN                    \
                in_dword(HWIO_DMA_RX_FLUSH_ADDR)
#define HWIO_DMA_RX_FLUSH_INM(m)            \
                in_dword_masked(HWIO_DMA_RX_FLUSH_ADDR, m)
#define HWIO_DMA_RX_FLUSH_OUT(v)            \
                out_dword(HWIO_DMA_RX_FLUSH_ADDR,v)
#define HWIO_DMA_RX_FLUSH_OUTM(m,v) \
                out_dword_masked_ns(HWIO_DMA_RX_FLUSH_ADDR,m,v,HWIO_DMA_RX_FLUSH_IN)
#define HWIO_DMA_RX_FLUSH_RX_FLUSH_BMSK                                                            0x1
#define HWIO_DMA_RX_FLUSH_RX_FLUSH_SHFT                                                              0

#define HWIO_DMA_2_RX_PTR_L_ADDR                                                            (QUPV3_SE_DMA_REG_BASE            + 0x164)
#define HWIO_DMA_2_RX_PTR_L_PHYS                                                            (QUPV3_SE_DMA_REG_BASE_PHYS + 0x164)
#define HWIO_DMA_2_RX_PTR_L_OFFS                                                            (QUPV3_SE_DMA_REG_BASE_OFFS + 0x164)
#define HWIO_DMA_2_RX_PTR_L_RMSK                                                            0xffffffff
#define HWIO_DMA_2_RX_PTR_L_IN                    \
                in_dword(HWIO_DMA_2_RX_PTR_L_ADDR)
#define HWIO_DMA_2_RX_PTR_L_INM(m)            \
                in_dword_masked(HWIO_DMA_2_RX_PTR_L_ADDR, m)
#define HWIO_DMA_2_RX_PTR_L_OUT(v)            \
                out_dword(HWIO_DMA_2_RX_PTR_L_ADDR,v)
#define HWIO_DMA_2_RX_PTR_L_OUTM(m,v) \
                out_dword_masked_ns(HWIO_DMA_2_RX_PTR_L_ADDR,m,v,HWIO_DMA_2_RX_PTR_L_IN)
#define HWIO_DMA_2_RX_PTR_L_RX_PTR_L_BMSK                                                   0xffffffff
#define HWIO_DMA_2_RX_PTR_L_RX_PTR_L_SHFT                                                            0

#define HWIO_DMA_2_RX_PTR_H_ADDR                                                            (QUPV3_SE_DMA_REG_BASE            + 0x168)
#define HWIO_DMA_2_RX_PTR_H_PHYS                                                            (QUPV3_SE_DMA_REG_BASE_PHYS + 0x168)
#define HWIO_DMA_2_RX_PTR_H_OFFS                                                            (QUPV3_SE_DMA_REG_BASE_OFFS + 0x168)
#define HWIO_DMA_2_RX_PTR_H_RMSK                                                            0xffffffff
#define HWIO_DMA_2_RX_PTR_H_IN                    \
                in_dword(HWIO_DMA_2_RX_PTR_H_ADDR)
#define HWIO_DMA_2_RX_PTR_H_INM(m)            \
                in_dword_masked(HWIO_DMA_2_RX_PTR_H_ADDR, m)
#define HWIO_DMA_2_RX_PTR_H_OUT(v)            \
                out_dword(HWIO_DMA_2_RX_PTR_H_ADDR,v)
#define HWIO_DMA_2_RX_PTR_H_OUTM(m,v) \
                out_dword_masked_ns(HWIO_DMA_2_RX_PTR_H_ADDR,m,v,HWIO_DMA_2_RX_PTR_H_IN)
#define HWIO_DMA_2_RX_PTR_H_RX_PTR_H_BMSK                                                   0xffffffff
#define HWIO_DMA_2_RX_PTR_H_RX_PTR_H_SHFT                                                            0

#define HWIO_DMA_2_RX_ATTR_ADDR                                                             (QUPV3_SE_DMA_REG_BASE            + 0x16c)
#define HWIO_DMA_2_RX_ATTR_PHYS                                                             (QUPV3_SE_DMA_REG_BASE_PHYS + 0x16c)
#define HWIO_DMA_2_RX_ATTR_OFFS                                                             (QUPV3_SE_DMA_REG_BASE_OFFS + 0x16c)
#define HWIO_DMA_2_RX_ATTR_RMSK                                                                  0xf0e
#define HWIO_DMA_2_RX_ATTR_IN                    \
                in_dword(HWIO_DMA_2_RX_ATTR_ADDR)
#define HWIO_DMA_2_RX_ATTR_INM(m)            \
                in_dword_masked(HWIO_DMA_2_RX_ATTR_ADDR, m)
#define HWIO_DMA_2_RX_ATTR_OUT(v)            \
                out_dword(HWIO_DMA_2_RX_ATTR_ADDR,v)
#define HWIO_DMA_2_RX_ATTR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_DMA_2_RX_ATTR_ADDR,m,v,HWIO_DMA_2_RX_ATTR_IN)
#define HWIO_DMA_2_RX_ATTR_GPII_INDEX_BMSK                                                       0xf00
#define HWIO_DMA_2_RX_ATTR_GPII_INDEX_SHFT                                                           8
#define HWIO_DMA_2_RX_ATTR_REQ_PRIORITY_BMSK                                                       0x8
#define HWIO_DMA_2_RX_ATTR_REQ_PRIORITY_SHFT                                                         3
#define HWIO_DMA_2_RX_ATTR_DMA_OPERATION_BMSK                                                      0x6
#define HWIO_DMA_2_RX_ATTR_DMA_OPERATION_SHFT                                                        1

#define HWIO_DMA_2_RX_LENGTH_ADDR                                                           (QUPV3_SE_DMA_REG_BASE            + 0x170)
#define HWIO_DMA_2_RX_LENGTH_PHYS                                                           (QUPV3_SE_DMA_REG_BASE_PHYS + 0x170)
#define HWIO_DMA_2_RX_LENGTH_OFFS                                                           (QUPV3_SE_DMA_REG_BASE_OFFS + 0x170)
#define HWIO_DMA_2_RX_LENGTH_RMSK                                                             0xffffff
#define HWIO_DMA_2_RX_LENGTH_IN                    \
                in_dword(HWIO_DMA_2_RX_LENGTH_ADDR)
#define HWIO_DMA_2_RX_LENGTH_INM(m)            \
                in_dword_masked(HWIO_DMA_2_RX_LENGTH_ADDR, m)
#define HWIO_DMA_2_RX_LENGTH_OUT(v)            \
                out_dword(HWIO_DMA_2_RX_LENGTH_ADDR,v)
#define HWIO_DMA_2_RX_LENGTH_OUTM(m,v) \
                out_dword_masked_ns(HWIO_DMA_2_RX_LENGTH_ADDR,m,v,HWIO_DMA_2_RX_LENGTH_IN)
#define HWIO_DMA_2_RX_LENGTH_RX_LENGTH_BMSK                                                   0xffffff
#define HWIO_DMA_2_RX_LENGTH_RX_LENGTH_SHFT                                                          0

#define HWIO_DMA_2_RX_LENGTH_IN_ADDR                                                        (QUPV3_SE_DMA_REG_BASE            + 0x174)
#define HWIO_DMA_2_RX_LENGTH_IN_PHYS                                                        (QUPV3_SE_DMA_REG_BASE_PHYS + 0x174)
#define HWIO_DMA_2_RX_LENGTH_IN_OFFS                                                        (QUPV3_SE_DMA_REG_BASE_OFFS + 0x174)
#define HWIO_DMA_2_RX_LENGTH_IN_RMSK                                                          0xffffff
#define HWIO_DMA_2_RX_LENGTH_IN_OUT(v)            \
                out_dword(HWIO_DMA_2_RX_LENGTH_IN_ADDR,v)
#define HWIO_DMA_2_RX_LENGTH_IN_RX_LENGTH_IN_BMSK                                             0xffffff
#define HWIO_DMA_2_RX_LENGTH_IN_RX_LENGTH_IN_SHFT                                                    0

#define HWIO_SE_IRQ_HIGH_PRIORITY_ADDR                                                      (QUPV3_SE_DMA_REG_BASE            + 0x214)
#define HWIO_SE_IRQ_HIGH_PRIORITY_PHYS                                                      (QUPV3_SE_DMA_REG_BASE_PHYS + 0x214)
#define HWIO_SE_IRQ_HIGH_PRIORITY_OFFS                                                      (QUPV3_SE_DMA_REG_BASE_OFFS + 0x214)
#define HWIO_SE_IRQ_HIGH_PRIORITY_RMSK                                                             0xf
#define HWIO_SE_IRQ_HIGH_PRIORITY_IN                    \
                in_dword(HWIO_SE_IRQ_HIGH_PRIORITY_ADDR)
#define HWIO_SE_IRQ_HIGH_PRIORITY_INM(m)            \
                in_dword_masked(HWIO_SE_IRQ_HIGH_PRIORITY_ADDR, m)
#define HWIO_SE_IRQ_HIGH_PRIORITY_OUT(v)            \
                out_dword(HWIO_SE_IRQ_HIGH_PRIORITY_ADDR,v)
#define HWIO_SE_IRQ_HIGH_PRIORITY_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SE_IRQ_HIGH_PRIORITY_ADDR,m,v,HWIO_SE_IRQ_HIGH_PRIORITY_IN)
#define HWIO_SE_IRQ_HIGH_PRIORITY_GENI_S_IRQ_HIGH_PRIORITY_BMSK                                    0x8
#define HWIO_SE_IRQ_HIGH_PRIORITY_GENI_S_IRQ_HIGH_PRIORITY_SHFT                                      3
#define HWIO_SE_IRQ_HIGH_PRIORITY_GENI_M_IRQ_HIGH_PRIORITY_BMSK                                    0x4
#define HWIO_SE_IRQ_HIGH_PRIORITY_GENI_M_IRQ_HIGH_PRIORITY_SHFT                                      2
#define HWIO_SE_IRQ_HIGH_PRIORITY_RX_IRQ_HIGH_PRIORITY_BMSK                                        0x2
#define HWIO_SE_IRQ_HIGH_PRIORITY_RX_IRQ_HIGH_PRIORITY_SHFT                                          1
#define HWIO_SE_IRQ_HIGH_PRIORITY_TX_IRQ_HIGH_PRIORITY_BMSK                                        0x1
#define HWIO_SE_IRQ_HIGH_PRIORITY_TX_IRQ_HIGH_PRIORITY_SHFT                                          0

#define HWIO_SE_GSI_EVENT_EN_ADDR                                                           (QUPV3_SE_DMA_REG_BASE            + 0x218)
#define HWIO_SE_GSI_EVENT_EN_PHYS                                                           (QUPV3_SE_DMA_REG_BASE_PHYS + 0x218)
#define HWIO_SE_GSI_EVENT_EN_OFFS                                                           (QUPV3_SE_DMA_REG_BASE_OFFS + 0x218)
#define HWIO_SE_GSI_EVENT_EN_RMSK                                                                  0xf
#define HWIO_SE_GSI_EVENT_EN_IN                    \
                in_dword(HWIO_SE_GSI_EVENT_EN_ADDR)
#define HWIO_SE_GSI_EVENT_EN_INM(m)            \
                in_dword_masked(HWIO_SE_GSI_EVENT_EN_ADDR, m)
#define HWIO_SE_GSI_EVENT_EN_OUT(v)            \
                out_dword(HWIO_SE_GSI_EVENT_EN_ADDR,v)
#define HWIO_SE_GSI_EVENT_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SE_GSI_EVENT_EN_ADDR,m,v,HWIO_SE_GSI_EVENT_EN_IN)
#define HWIO_SE_GSI_EVENT_EN_GENI_S_EVENT_EN_BMSK                                                  0x8
#define HWIO_SE_GSI_EVENT_EN_GENI_S_EVENT_EN_SHFT                                                    3
#define HWIO_SE_GSI_EVENT_EN_GENI_M_EVENT_EN_BMSK                                                  0x4
#define HWIO_SE_GSI_EVENT_EN_GENI_M_EVENT_EN_SHFT                                                    2
#define HWIO_SE_GSI_EVENT_EN_DMA_TX_EVENT_EN_BMSK                                                  0x2
#define HWIO_SE_GSI_EVENT_EN_DMA_TX_EVENT_EN_SHFT                                                    1
#define HWIO_SE_GSI_EVENT_EN_DMA_RX_EVENT_EN_BMSK                                                  0x1
#define HWIO_SE_GSI_EVENT_EN_DMA_RX_EVENT_EN_SHFT                                                    0

#define HWIO_SE_IRQ_EN_ADDR                                                                 (QUPV3_SE_DMA_REG_BASE            + 0x21c)
#define HWIO_SE_IRQ_EN_PHYS                                                                 (QUPV3_SE_DMA_REG_BASE_PHYS + 0x21c)
#define HWIO_SE_IRQ_EN_OFFS                                                                 (QUPV3_SE_DMA_REG_BASE_OFFS + 0x21c)
#define HWIO_SE_IRQ_EN_RMSK                                                                        0xf
#define HWIO_SE_IRQ_EN_IN                    \
                in_dword(HWIO_SE_IRQ_EN_ADDR)
#define HWIO_SE_IRQ_EN_INM(m)            \
                in_dword_masked(HWIO_SE_IRQ_EN_ADDR, m)
#define HWIO_SE_IRQ_EN_OUT(v)            \
                out_dword(HWIO_SE_IRQ_EN_ADDR,v)
#define HWIO_SE_IRQ_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SE_IRQ_EN_ADDR,m,v,HWIO_SE_IRQ_EN_IN)
#define HWIO_SE_IRQ_EN_GENI_S_IRQ_EN_BMSK                                                          0x8
#define HWIO_SE_IRQ_EN_GENI_S_IRQ_EN_SHFT                                                            3
#define HWIO_SE_IRQ_EN_GENI_M_IRQ_EN_BMSK                                                          0x4
#define HWIO_SE_IRQ_EN_GENI_M_IRQ_EN_SHFT                                                            2
#define HWIO_SE_IRQ_EN_DMA_TX_IRQ_EN_BMSK                                                          0x2
#define HWIO_SE_IRQ_EN_DMA_TX_IRQ_EN_SHFT                                                            1
#define HWIO_SE_IRQ_EN_DMA_RX_IRQ_EN_BMSK                                                          0x1
#define HWIO_SE_IRQ_EN_DMA_RX_IRQ_EN_SHFT                                                            0

#define HWIO_DMA_IF_EN_RO_ADDR                                                              (QUPV3_SE_DMA_REG_BASE            + 0x220)
#define HWIO_DMA_IF_EN_RO_PHYS                                                              (QUPV3_SE_DMA_REG_BASE_PHYS + 0x220)
#define HWIO_DMA_IF_EN_RO_OFFS                                                              (QUPV3_SE_DMA_REG_BASE_OFFS + 0x220)
#define HWIO_DMA_IF_EN_RO_RMSK                                                                     0x1
#define HWIO_DMA_IF_EN_RO_IN                    \
                in_dword(HWIO_DMA_IF_EN_RO_ADDR)
#define HWIO_DMA_IF_EN_RO_INM(m)            \
                in_dword_masked(HWIO_DMA_IF_EN_RO_ADDR, m)
#define HWIO_DMA_IF_EN_RO_DMA_IF_EN_BMSK                                                           0x1
#define HWIO_DMA_IF_EN_RO_DMA_IF_EN_SHFT                                                             0

#define HWIO_SE_HW_PARAM_0_ADDR                                                             (QUPV3_SE_DMA_REG_BASE            + 0x224)
#define HWIO_SE_HW_PARAM_0_PHYS                                                             (QUPV3_SE_DMA_REG_BASE_PHYS + 0x224)
#define HWIO_SE_HW_PARAM_0_OFFS                                                             (QUPV3_SE_DMA_REG_BASE_OFFS + 0x224)
#define HWIO_SE_HW_PARAM_0_RMSK                                                             0x3f3f7bff
#define HWIO_SE_HW_PARAM_0_IN                    \
                in_dword(HWIO_SE_HW_PARAM_0_ADDR)
#define HWIO_SE_HW_PARAM_0_INM(m)            \
                in_dword_masked(HWIO_SE_HW_PARAM_0_ADDR, m)
#define HWIO_SE_HW_PARAM_0_TX_FIFO_WIDTH_BMSK                                               0x3f000000
#define HWIO_SE_HW_PARAM_0_TX_FIFO_WIDTH_SHFT                                                       24
#define HWIO_SE_HW_PARAM_0_TX_FIFO_DEPTH_BMSK                                                 0x3f0000
#define HWIO_SE_HW_PARAM_0_TX_FIFO_DEPTH_SHFT                                                       16
#define HWIO_SE_HW_PARAM_0_TX_ASYNC_FIFO_DEPTH_BMSK                                             0x7000
#define HWIO_SE_HW_PARAM_0_TX_ASYNC_FIFO_DEPTH_SHFT                                                 12
#define HWIO_SE_HW_PARAM_0_TX_FIFO_EN_BMSK                                                       0x800
#define HWIO_SE_HW_PARAM_0_TX_FIFO_EN_SHFT                                                          11
#define HWIO_SE_HW_PARAM_0_GEN_SPI_SLAVE_EN_BMSK                                                 0x200
#define HWIO_SE_HW_PARAM_0_GEN_SPI_SLAVE_EN_SHFT                                                     9
#define HWIO_SE_HW_PARAM_0_GEN_I3C_BMSK                                                          0x100
#define HWIO_SE_HW_PARAM_0_GEN_I3C_SHFT                                                              8
#define HWIO_SE_HW_PARAM_0_GEN_I3C_IBI_CTRL_BMSK                                                  0x80
#define HWIO_SE_HW_PARAM_0_GEN_I3C_IBI_CTRL_SHFT                                                     7
#define HWIO_SE_HW_PARAM_0_GEN_SCND_SEQUENCER_BMSK                                                0x40
#define HWIO_SE_HW_PARAM_0_GEN_SCND_SEQUENCER_SHFT                                                   6
#define HWIO_SE_HW_PARAM_0_AHB_M_ADDR_W_BMSK                                                      0x3f
#define HWIO_SE_HW_PARAM_0_AHB_M_ADDR_W_SHFT                                                         0

#define HWIO_SE_HW_PARAM_1_ADDR                                                             (QUPV3_SE_DMA_REG_BASE            + 0x228)
#define HWIO_SE_HW_PARAM_1_PHYS                                                             (QUPV3_SE_DMA_REG_BASE_PHYS + 0x228)
#define HWIO_SE_HW_PARAM_1_OFFS                                                             (QUPV3_SE_DMA_REG_BASE_OFFS + 0x228)
#define HWIO_SE_HW_PARAM_1_RMSK                                                             0x3f3f7800
#define HWIO_SE_HW_PARAM_1_IN                    \
                in_dword(HWIO_SE_HW_PARAM_1_ADDR)
#define HWIO_SE_HW_PARAM_1_INM(m)            \
                in_dword_masked(HWIO_SE_HW_PARAM_1_ADDR, m)
#define HWIO_SE_HW_PARAM_1_RX_FIFO_WIDTH_BMSK                                               0x3f000000
#define HWIO_SE_HW_PARAM_1_RX_FIFO_WIDTH_SHFT                                                       24
#define HWIO_SE_HW_PARAM_1_RX_FIFO_DEPTH_BMSK                                                 0x3f0000
#define HWIO_SE_HW_PARAM_1_RX_FIFO_DEPTH_SHFT                                                       16
#define HWIO_SE_HW_PARAM_1_RX_ASYNC_FIFO_DEPTH_BMSK                                             0x7000
#define HWIO_SE_HW_PARAM_1_RX_ASYNC_FIFO_DEPTH_SHFT                                                 12
#define HWIO_SE_HW_PARAM_1_RX_FIFO_EN_BMSK                                                       0x800
#define HWIO_SE_HW_PARAM_1_RX_FIFO_EN_SHFT                                                          11

#define HWIO_SE_HW_PARAM_2_ADDR                                                             (QUPV3_SE_DMA_REG_BASE            + 0x22c)
#define HWIO_SE_HW_PARAM_2_PHYS                                                             (QUPV3_SE_DMA_REG_BASE_PHYS + 0x22c)
#define HWIO_SE_HW_PARAM_2_OFFS                                                             (QUPV3_SE_DMA_REG_BASE_OFFS + 0x22c)
#define HWIO_SE_HW_PARAM_2_RMSK                                                                0x3f7ff
#define HWIO_SE_HW_PARAM_2_IN                    \
                in_dword(HWIO_SE_HW_PARAM_2_ADDR)
#define HWIO_SE_HW_PARAM_2_INM(m)            \
                in_dword_masked(HWIO_SE_HW_PARAM_2_ADDR, m)
#define HWIO_SE_HW_PARAM_2_GEN_HW_FSM_SPI_S_BMSK                                               0x20000
#define HWIO_SE_HW_PARAM_2_GEN_HW_FSM_SPI_S_SHFT                                                    17
#define HWIO_SE_HW_PARAM_2_GEN_HW_FSM_I3C_BMSK                                                 0x10000
#define HWIO_SE_HW_PARAM_2_GEN_HW_FSM_I3C_SHFT                                                      16
#define HWIO_SE_HW_PARAM_2_GEN_HW_FSM_I2C_BMSK                                                  0x8000
#define HWIO_SE_HW_PARAM_2_GEN_HW_FSM_I2C_SHFT                                                      15
#define HWIO_SE_HW_PARAM_2_GEN_HW_FSM_UART_BMSK                                                 0x4000
#define HWIO_SE_HW_PARAM_2_GEN_HW_FSM_UART_SHFT                                                     14
#define HWIO_SE_HW_PARAM_2_GEN_HW_FSM_SPI_BMSK                                                  0x2000
#define HWIO_SE_HW_PARAM_2_GEN_HW_FSM_SPI_SHFT                                                      13
#define HWIO_SE_HW_PARAM_2_GEN_USE_MINICORES_BMSK                                               0x1000
#define HWIO_SE_HW_PARAM_2_GEN_USE_MINICORES_SHFT                                                   12
#define HWIO_SE_HW_PARAM_2_PROG_RAM_DEPTH_BMSK                                                   0x7ff
#define HWIO_SE_HW_PARAM_2_PROG_RAM_DEPTH_SHFT                                                       0

#define HWIO_DMA_GENERAL_CFG_ADDR                                                           (QUPV3_SE_DMA_REG_BASE            + 0x230)
#define HWIO_DMA_GENERAL_CFG_PHYS                                                           (QUPV3_SE_DMA_REG_BASE_PHYS + 0x230)
#define HWIO_DMA_GENERAL_CFG_OFFS                                                           (QUPV3_SE_DMA_REG_BASE_OFFS + 0x230)
#define HWIO_DMA_GENERAL_CFG_RMSK                                                                0xfff
#define HWIO_DMA_GENERAL_CFG_IN                    \
                in_dword(HWIO_DMA_GENERAL_CFG_ADDR)
#define HWIO_DMA_GENERAL_CFG_INM(m)            \
                in_dword_masked(HWIO_DMA_GENERAL_CFG_ADDR, m)
#define HWIO_DMA_GENERAL_CFG_OUT(v)            \
                out_dword(HWIO_DMA_GENERAL_CFG_ADDR,v)
#define HWIO_DMA_GENERAL_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_DMA_GENERAL_CFG_ADDR,m,v,HWIO_DMA_GENERAL_CFG_IN)
#define HWIO_DMA_GENERAL_CFG_DMA_TX_IDLE_ABORT_EN_BMSK                                           0x800
#define HWIO_DMA_GENERAL_CFG_DMA_TX_IDLE_ABORT_EN_SHFT                                              11
#define HWIO_DMA_GENERAL_CFG_DMA_RX_DOUBLE_BUFF_DIS_BMSK                                         0x400
#define HWIO_DMA_GENERAL_CFG_DMA_RX_DOUBLE_BUFF_DIS_SHFT                                            10
#define HWIO_DMA_GENERAL_CFG_DMA_TX_DOUBLE_BUFF_DIS_BMSK                                         0x200
#define HWIO_DMA_GENERAL_CFG_DMA_TX_DOUBLE_BUFF_DIS_SHFT                                             9
#define HWIO_DMA_GENERAL_CFG_RX_DMA_IRQ_DELAY_BMSK                                               0x1c0
#define HWIO_DMA_GENERAL_CFG_RX_DMA_IRQ_DELAY_SHFT                                                   6
#define HWIO_DMA_GENERAL_CFG_TX_DMA_ZERO_PADDING_EN_BMSK                                          0x20
#define HWIO_DMA_GENERAL_CFG_TX_DMA_ZERO_PADDING_EN_SHFT                                             5
#define HWIO_DMA_GENERAL_CFG_DUMMY_RX_NON_BUFFERABLE_BMSK                                         0x10
#define HWIO_DMA_GENERAL_CFG_DUMMY_RX_NON_BUFFERABLE_SHFT                                            4
#define HWIO_DMA_GENERAL_CFG_AHB_SEC_SLV_CLK_CGC_ON_BMSK                                           0x8
#define HWIO_DMA_GENERAL_CFG_AHB_SEC_SLV_CLK_CGC_ON_SHFT                                             3
#define HWIO_DMA_GENERAL_CFG_DMA_AHB_SLV_CLK_CGC_ON_BMSK                                           0x4
#define HWIO_DMA_GENERAL_CFG_DMA_AHB_SLV_CLK_CGC_ON_SHFT                                             2
#define HWIO_DMA_GENERAL_CFG_DMA_TX_CLK_CGC_ON_BMSK                                                0x2
#define HWIO_DMA_GENERAL_CFG_DMA_TX_CLK_CGC_ON_SHFT                                                  1
#define HWIO_DMA_GENERAL_CFG_DMA_RX_CLK_CGC_ON_BMSK                                                0x1
#define HWIO_DMA_GENERAL_CFG_DMA_RX_CLK_CGC_ON_SHFT                                                  0

#define HWIO_DMA_WD_TIMER_CFG_ADDR                                                          (QUPV3_SE_DMA_REG_BASE            + 0x234)
#define HWIO_DMA_WD_TIMER_CFG_PHYS                                                          (QUPV3_SE_DMA_REG_BASE_PHYS + 0x234)
#define HWIO_DMA_WD_TIMER_CFG_OFFS                                                          (QUPV3_SE_DMA_REG_BASE_OFFS + 0x234)
#define HWIO_DMA_WD_TIMER_CFG_RMSK                                                          0xffffffff
#define HWIO_DMA_WD_TIMER_CFG_IN                    \
                in_dword(HWIO_DMA_WD_TIMER_CFG_ADDR)
#define HWIO_DMA_WD_TIMER_CFG_INM(m)            \
                in_dword_masked(HWIO_DMA_WD_TIMER_CFG_ADDR, m)
#define HWIO_DMA_WD_TIMER_CFG_OUT(v)            \
                out_dword(HWIO_DMA_WD_TIMER_CFG_ADDR,v)
#define HWIO_DMA_WD_TIMER_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_DMA_WD_TIMER_CFG_ADDR,m,v,HWIO_DMA_WD_TIMER_CFG_IN)
#define HWIO_DMA_WD_TIMER_CFG_DMA_RX_WD_TIMER_EN_BMSK                                       0x80000000
#define HWIO_DMA_WD_TIMER_CFG_DMA_RX_WD_TIMER_EN_SHFT                                               31
#define HWIO_DMA_WD_TIMER_CFG_DMA_RX_WD_TIMER_MAX_BMSK                                      0x7fff0000
#define HWIO_DMA_WD_TIMER_CFG_DMA_RX_WD_TIMER_MAX_SHFT                                              16
#define HWIO_DMA_WD_TIMER_CFG_DMA_TX_WD_TIMER_EN_BMSK                                           0x8000
#define HWIO_DMA_WD_TIMER_CFG_DMA_TX_WD_TIMER_EN_SHFT                                               15
#define HWIO_DMA_WD_TIMER_CFG_DMA_TX_WD_TIMER_MAX_BMSK                                          0x7fff
#define HWIO_DMA_WD_TIMER_CFG_DMA_TX_WD_TIMER_MAX_SHFT                                               0

#define HWIO_DMA_DEBUG_REG0_ADDR                                                            (QUPV3_SE_DMA_REG_BASE            + 0x240)
#define HWIO_DMA_DEBUG_REG0_PHYS                                                            (QUPV3_SE_DMA_REG_BASE_PHYS + 0x240)
#define HWIO_DMA_DEBUG_REG0_OFFS                                                            (QUPV3_SE_DMA_REG_BASE_OFFS + 0x240)
#define HWIO_DMA_DEBUG_REG0_RMSK                                                                 0xff3
#define HWIO_DMA_DEBUG_REG0_IN                    \
                in_dword(HWIO_DMA_DEBUG_REG0_ADDR)
#define HWIO_DMA_DEBUG_REG0_INM(m)            \
                in_dword_masked(HWIO_DMA_DEBUG_REG0_ADDR, m)
#define HWIO_DMA_DEBUG_REG0_DMA_RX_STATE_BMSK                                                    0xf00
#define HWIO_DMA_DEBUG_REG0_DMA_RX_STATE_SHFT                                                        8
#define HWIO_DMA_DEBUG_REG0_DMA_TX_STATE_BMSK                                                     0xf0
#define HWIO_DMA_DEBUG_REG0_DMA_TX_STATE_SHFT                                                        4
#define HWIO_DMA_DEBUG_REG0_DMA_RX_ACTIVE_BMSK                                                     0x2
#define HWIO_DMA_DEBUG_REG0_DMA_RX_ACTIVE_SHFT                                                       1
#define HWIO_DMA_DEBUG_REG0_DMA_TX_ACTIVE_BMSK                                                     0x1
#define HWIO_DMA_DEBUG_REG0_DMA_TX_ACTIVE_SHFT                                                       0

#define HWIO_DMA_TEST_BUS_CTRL_ADDR                                                         (QUPV3_SE_DMA_REG_BASE            + 0x244)
#define HWIO_DMA_TEST_BUS_CTRL_PHYS                                                         (QUPV3_SE_DMA_REG_BASE_PHYS + 0x244)
#define HWIO_DMA_TEST_BUS_CTRL_OFFS                                                         (QUPV3_SE_DMA_REG_BASE_OFFS + 0x244)
#define HWIO_DMA_TEST_BUS_CTRL_RMSK                                                                0x7
#define HWIO_DMA_TEST_BUS_CTRL_IN                    \
                in_dword(HWIO_DMA_TEST_BUS_CTRL_ADDR)
#define HWIO_DMA_TEST_BUS_CTRL_INM(m)            \
                in_dword_masked(HWIO_DMA_TEST_BUS_CTRL_ADDR, m)
#define HWIO_DMA_TEST_BUS_CTRL_OUT(v)            \
                out_dword(HWIO_DMA_TEST_BUS_CTRL_ADDR,v)
#define HWIO_DMA_TEST_BUS_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_DMA_TEST_BUS_CTRL_ADDR,m,v,HWIO_DMA_TEST_BUS_CTRL_IN)
#define HWIO_DMA_TEST_BUS_CTRL_DMA_TEST_BUS_SEL_BMSK                                               0x7
#define HWIO_DMA_TEST_BUS_CTRL_DMA_TEST_BUS_SEL_SHFT                                                 0

#define HWIO_SE_TOP_TEST_BUS_CTRL_ADDR                                                      (QUPV3_SE_DMA_REG_BASE            + 0x248)
#define HWIO_SE_TOP_TEST_BUS_CTRL_PHYS                                                      (QUPV3_SE_DMA_REG_BASE_PHYS + 0x248)
#define HWIO_SE_TOP_TEST_BUS_CTRL_OFFS                                                      (QUPV3_SE_DMA_REG_BASE_OFFS + 0x248)
#define HWIO_SE_TOP_TEST_BUS_CTRL_RMSK                                                             0x3
#define HWIO_SE_TOP_TEST_BUS_CTRL_IN                    \
                in_dword(HWIO_SE_TOP_TEST_BUS_CTRL_ADDR)
#define HWIO_SE_TOP_TEST_BUS_CTRL_INM(m)            \
                in_dword_masked(HWIO_SE_TOP_TEST_BUS_CTRL_ADDR, m)
#define HWIO_SE_TOP_TEST_BUS_CTRL_OUT(v)            \
                out_dword(HWIO_SE_TOP_TEST_BUS_CTRL_ADDR,v)
#define HWIO_SE_TOP_TEST_BUS_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SE_TOP_TEST_BUS_CTRL_ADDR,m,v,HWIO_SE_TOP_TEST_BUS_CTRL_IN)
#define HWIO_SE_TOP_TEST_BUS_CTRL_SE_TOP_TEST_BUS_SEL_BMSK                                         0x3
#define HWIO_SE_TOP_TEST_BUS_CTRL_SE_TOP_TEST_BUS_SEL_SHFT                                           0

/*----------------------------------------------------------------------------
 * MODULE: GENI4_IMAGE
 *--------------------------------------------------------------------------*/

#define GENI4_IMAGE_REG_BASE                                              (SAILSS_QUPV3_1_QUPV3_ID_1_BASE            + 0x00081000)
#define GENI4_IMAGE_REG_BASE_SIZE                                         0x1000
#define GENI4_IMAGE_REG_BASE_USED                                         0xffc
#define GENI4_IMAGE_REG_BASE_PHYS                                         (SAILSS_QUPV3_1_QUPV3_ID_1_BASE_PHYS + 0x00081000)
#define GENI4_IMAGE_REG_BASE_OFFS                                         0x00081000

#define HWIO_GENI_FW_REVISION_ADDR                                        (GENI4_IMAGE_REG_BASE            + 0x0)
#define HWIO_GENI_FW_REVISION_PHYS                                        (GENI4_IMAGE_REG_BASE_PHYS + 0x0)
#define HWIO_GENI_FW_REVISION_OFFS                                        (GENI4_IMAGE_REG_BASE_OFFS + 0x0)
#define HWIO_GENI_FW_REVISION_RMSK                                            0xffff
#define HWIO_GENI_FW_REVISION_IN                    \
                in_dword(HWIO_GENI_FW_REVISION_ADDR)
#define HWIO_GENI_FW_REVISION_INM(m)            \
                in_dword_masked(HWIO_GENI_FW_REVISION_ADDR, m)
#define HWIO_GENI_FW_REVISION_OUT(v)            \
                out_dword(HWIO_GENI_FW_REVISION_ADDR,v)
#define HWIO_GENI_FW_REVISION_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_FW_REVISION_ADDR,m,v,HWIO_GENI_FW_REVISION_IN)
#define HWIO_GENI_FW_REVISION_PROTOCOL_BMSK                                   0xff00
#define HWIO_GENI_FW_REVISION_PROTOCOL_SHFT                                        8
#define HWIO_GENI_FW_REVISION_VERSION_BMSK                                      0xff
#define HWIO_GENI_FW_REVISION_VERSION_SHFT                                         0

#define HWIO_GENI_S_FW_REVISION_ADDR                                      (GENI4_IMAGE_REG_BASE            + 0x4)
#define HWIO_GENI_S_FW_REVISION_PHYS                                      (GENI4_IMAGE_REG_BASE_PHYS + 0x4)
#define HWIO_GENI_S_FW_REVISION_OFFS                                      (GENI4_IMAGE_REG_BASE_OFFS + 0x4)
#define HWIO_GENI_S_FW_REVISION_RMSK                                          0xffff
#define HWIO_GENI_S_FW_REVISION_IN                    \
                in_dword(HWIO_GENI_S_FW_REVISION_ADDR)
#define HWIO_GENI_S_FW_REVISION_INM(m)            \
                in_dword_masked(HWIO_GENI_S_FW_REVISION_ADDR, m)
#define HWIO_GENI_S_FW_REVISION_OUT(v)            \
                out_dword(HWIO_GENI_S_FW_REVISION_ADDR,v)
#define HWIO_GENI_S_FW_REVISION_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_S_FW_REVISION_ADDR,m,v,HWIO_GENI_S_FW_REVISION_IN)
#define HWIO_GENI_S_FW_REVISION_PROTOCOL_BMSK                                 0xff00
#define HWIO_GENI_S_FW_REVISION_PROTOCOL_SHFT                                      8
#define HWIO_GENI_S_FW_REVISION_VERSION_BMSK                                    0xff
#define HWIO_GENI_S_FW_REVISION_VERSION_SHFT                                       0

#define HWIO_GENI_CFG_RAMn_ADDR(n)                                        (GENI4_IMAGE_REG_BASE            + 0X10 + (0x4*(n)))
#define HWIO_GENI_CFG_RAMn_PHYS(n)                                        (GENI4_IMAGE_REG_BASE_PHYS + 0X10 + (0x4*(n)))
#define HWIO_GENI_CFG_RAMn_OFFS(n)                                        (GENI4_IMAGE_REG_BASE_OFFS + 0X10 + (0x4*(n)))
#define HWIO_GENI_CFG_RAMn_RMSK                                             0x7fffff
#define HWIO_GENI_CFG_RAMn_MAXn                                                 1019
#define HWIO_GENI_CFG_RAMn_INI(n)                \
                in_dword_masked(HWIO_GENI_CFG_RAMn_ADDR(n), HWIO_GENI_CFG_RAMn_RMSK)
#define HWIO_GENI_CFG_RAMn_INMI(n,mask)        \
                in_dword_masked(HWIO_GENI_CFG_RAMn_ADDR(n), mask)
#define HWIO_GENI_CFG_RAMn_OUTI(n,val)        \
                out_dword(HWIO_GENI_CFG_RAMn_ADDR(n),val)
#define HWIO_GENI_CFG_RAMn_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_GENI_CFG_RAMn_ADDR(n),mask,val,HWIO_GENI_CFG_RAMn_INI(n))
#define HWIO_GENI_CFG_RAMn_TBD_BMSK                                         0x7fffff
#define HWIO_GENI_CFG_RAMn_TBD_SHFT                                                0

/*----------------------------------------------------------------------------
 * MODULE: QUPV3_SEC
 *--------------------------------------------------------------------------*/

#define QUPV3_SEC_REG_BASE                                                                      (SAILSS_QUPV3_1_QUPV3_ID_1_BASE            + 0x00082000)
#define QUPV3_SEC_REG_BASE_SIZE                                                                 0x1000
#define QUPV3_SEC_REG_BASE_USED                                                                 0x14
#define QUPV3_SEC_REG_BASE_PHYS                                                                 (SAILSS_QUPV3_1_QUPV3_ID_1_BASE_PHYS + 0x00082000)
#define QUPV3_SEC_REG_BASE_OFFS                                                                 0x00082000

#define HWIO_GENI_CLK_CTRL_ADDR                                                                 (QUPV3_SEC_REG_BASE            + 0x0)
#define HWIO_GENI_CLK_CTRL_PHYS                                                                 (QUPV3_SEC_REG_BASE_PHYS + 0x0)
#define HWIO_GENI_CLK_CTRL_OFFS                                                                 (QUPV3_SEC_REG_BASE_OFFS + 0x0)
#define HWIO_GENI_CLK_CTRL_RMSK                                                                        0x1
#define HWIO_GENI_CLK_CTRL_IN                    \
                in_dword(HWIO_GENI_CLK_CTRL_ADDR)
#define HWIO_GENI_CLK_CTRL_INM(m)            \
                in_dword_masked(HWIO_GENI_CLK_CTRL_ADDR, m)
#define HWIO_GENI_CLK_CTRL_OUT(v)            \
                out_dword(HWIO_GENI_CLK_CTRL_ADDR,v)
#define HWIO_GENI_CLK_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_CLK_CTRL_ADDR,m,v,HWIO_GENI_CLK_CTRL_IN)
#define HWIO_GENI_CLK_CTRL_SER_CLK_SEL_BMSK                                                            0x1
#define HWIO_GENI_CLK_CTRL_SER_CLK_SEL_SHFT                                                              0

#define HWIO_DMA_IF_EN_ADDR                                                                     (QUPV3_SEC_REG_BASE            + 0x4)
#define HWIO_DMA_IF_EN_PHYS                                                                     (QUPV3_SEC_REG_BASE_PHYS + 0x4)
#define HWIO_DMA_IF_EN_OFFS                                                                     (QUPV3_SEC_REG_BASE_OFFS + 0x4)
#define HWIO_DMA_IF_EN_RMSK                                                                            0x1
#define HWIO_DMA_IF_EN_IN                    \
                in_dword(HWIO_DMA_IF_EN_ADDR)
#define HWIO_DMA_IF_EN_INM(m)            \
                in_dword_masked(HWIO_DMA_IF_EN_ADDR, m)
#define HWIO_DMA_IF_EN_OUT(v)            \
                out_dword(HWIO_DMA_IF_EN_ADDR,v)
#define HWIO_DMA_IF_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_DMA_IF_EN_ADDR,m,v,HWIO_DMA_IF_EN_IN)
#define HWIO_DMA_IF_EN_DMA_IF_EN_BMSK                                                                  0x1
#define HWIO_DMA_IF_EN_DMA_IF_EN_SHFT                                                                    0

#define HWIO_FIFO_IF_DISABLE_ADDR                                                               (QUPV3_SEC_REG_BASE            + 0x8)
#define HWIO_FIFO_IF_DISABLE_PHYS                                                               (QUPV3_SEC_REG_BASE_PHYS + 0x8)
#define HWIO_FIFO_IF_DISABLE_OFFS                                                               (QUPV3_SEC_REG_BASE_OFFS + 0x8)
#define HWIO_FIFO_IF_DISABLE_RMSK                                                                      0x1
#define HWIO_FIFO_IF_DISABLE_IN                    \
                in_dword(HWIO_FIFO_IF_DISABLE_ADDR)
#define HWIO_FIFO_IF_DISABLE_INM(m)            \
                in_dword_masked(HWIO_FIFO_IF_DISABLE_ADDR, m)
#define HWIO_FIFO_IF_DISABLE_OUT(v)            \
                out_dword(HWIO_FIFO_IF_DISABLE_ADDR,v)
#define HWIO_FIFO_IF_DISABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_FIFO_IF_DISABLE_ADDR,m,v,HWIO_FIFO_IF_DISABLE_IN)
#define HWIO_FIFO_IF_DISABLE_FIFO_IF_DISABLE_BMSK                                                      0x1
#define HWIO_FIFO_IF_DISABLE_FIFO_IF_DISABLE_SHFT                                                        0

#define HWIO_GENI_FW_MULTILOCK_PROTNS_ADDR                                                      (QUPV3_SEC_REG_BASE            + 0xc)
#define HWIO_GENI_FW_MULTILOCK_PROTNS_PHYS                                                      (QUPV3_SEC_REG_BASE_PHYS + 0xc)
#define HWIO_GENI_FW_MULTILOCK_PROTNS_OFFS                                                      (QUPV3_SEC_REG_BASE_OFFS + 0xc)
#define HWIO_GENI_FW_MULTILOCK_PROTNS_RMSK                                                             0x1
#define HWIO_GENI_FW_MULTILOCK_PROTNS_IN                    \
                in_dword(HWIO_GENI_FW_MULTILOCK_PROTNS_ADDR)
#define HWIO_GENI_FW_MULTILOCK_PROTNS_INM(m)            \
                in_dword_masked(HWIO_GENI_FW_MULTILOCK_PROTNS_ADDR, m)
#define HWIO_GENI_FW_MULTILOCK_PROTNS_OUT(v)            \
                out_dword(HWIO_GENI_FW_MULTILOCK_PROTNS_ADDR,v)
#define HWIO_GENI_FW_MULTILOCK_PROTNS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_FW_MULTILOCK_PROTNS_ADDR,m,v,HWIO_GENI_FW_MULTILOCK_PROTNS_IN)
#define HWIO_GENI_FW_MULTILOCK_PROTNS_GENI_FW_MULTILOCK_PROTNS_BMSK                                    0x1
#define HWIO_GENI_FW_MULTILOCK_PROTNS_GENI_FW_MULTILOCK_PROTNS_SHFT                                      0

#define HWIO_GENI_FW_MULTILOCK_MSA_ADDR                                                         (QUPV3_SEC_REG_BASE            + 0x10)
#define HWIO_GENI_FW_MULTILOCK_MSA_PHYS                                                         (QUPV3_SEC_REG_BASE_PHYS + 0x10)
#define HWIO_GENI_FW_MULTILOCK_MSA_OFFS                                                         (QUPV3_SEC_REG_BASE_OFFS + 0x10)
#define HWIO_GENI_FW_MULTILOCK_MSA_RMSK                                                                0x1
#define HWIO_GENI_FW_MULTILOCK_MSA_IN                    \
                in_dword(HWIO_GENI_FW_MULTILOCK_MSA_ADDR)
#define HWIO_GENI_FW_MULTILOCK_MSA_INM(m)            \
                in_dword_masked(HWIO_GENI_FW_MULTILOCK_MSA_ADDR, m)
#define HWIO_GENI_FW_MULTILOCK_MSA_OUT(v)            \
                out_dword(HWIO_GENI_FW_MULTILOCK_MSA_ADDR,v)
#define HWIO_GENI_FW_MULTILOCK_MSA_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_FW_MULTILOCK_MSA_ADDR,m,v,HWIO_GENI_FW_MULTILOCK_MSA_IN)
#define HWIO_GENI_FW_MULTILOCK_MSA_GENI_FW_MULTILOCK_MSA_BMSK                                          0x1
#define HWIO_GENI_FW_MULTILOCK_MSA_GENI_FW_MULTILOCK_MSA_SHFT                                            0

#define HWIO_GENI_FW_MULTILOCK_SP_ADDR                                                          (QUPV3_SEC_REG_BASE            + 0x14)
#define HWIO_GENI_FW_MULTILOCK_SP_PHYS                                                          (QUPV3_SEC_REG_BASE_PHYS + 0x14)
#define HWIO_GENI_FW_MULTILOCK_SP_OFFS                                                          (QUPV3_SEC_REG_BASE_OFFS + 0x14)
#define HWIO_GENI_FW_MULTILOCK_SP_RMSK                                                                 0x1
#define HWIO_GENI_FW_MULTILOCK_SP_IN                    \
                in_dword(HWIO_GENI_FW_MULTILOCK_SP_ADDR)
#define HWIO_GENI_FW_MULTILOCK_SP_INM(m)            \
                in_dword_masked(HWIO_GENI_FW_MULTILOCK_SP_ADDR, m)
#define HWIO_GENI_FW_MULTILOCK_SP_OUT(v)            \
                out_dword(HWIO_GENI_FW_MULTILOCK_SP_ADDR,v)
#define HWIO_GENI_FW_MULTILOCK_SP_OUTM(m,v) \
                out_dword_masked_ns(HWIO_GENI_FW_MULTILOCK_SP_ADDR,m,v,HWIO_GENI_FW_MULTILOCK_SP_IN)
#define HWIO_GENI_FW_MULTILOCK_SP_GENI_FW_MULTILOCK_SP_BMSK                                            0x1
#define HWIO_GENI_FW_MULTILOCK_SP_GENI_FW_MULTILOCK_SP_SHFT                                              0


#endif /* __HWIO_H__ */
