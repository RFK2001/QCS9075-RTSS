#ifndef __G_SAILSS_VSENSE_CTRL_CONTROLLER_H__
#define __G_SAILSS_VSENSE_CTRL_CONTROLLER_H__
/*
===========================================================================
*/
/**
    @file g_SAILSS_VSENSE_CTRL_CONTROLLER.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        SA8775P (LeMansAU) [lemansau_v1.0_p3q2r72_BTO]
 
    This file contains HWIO register definitions for the following modules:
        SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER
        SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER


    Generation parameters: 
    { 'filename': 'g_SAILSS_VSENSE_CTRL_CONTROLLER.h',
      'integer-qualifiers': True,
      'modules': [ 'SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER',
                   'SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER'],
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
 * MODULE: SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER
 *--------------------------------------------------------------------------*/

#define SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE                                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_BASE      + 0x00000000u)
#define SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_SIZE                                                                       0x1000u
#define SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_USED                                                                       0xd70u
#define SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS                                                                       0x00000000u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_HW_ID_ADDR                                                                          (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_HW_ID_OFFS                                                                          (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_HW_ID_RMSK                                                                          0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_HW_ID_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_HW_ID_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_HW_ID_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_HW_ID_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_HW_ID_MAJOR_BMSK                                                                    0xf0000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_HW_ID_MAJOR_SHFT                                                                            28u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_HW_ID_MINOR_BMSK                                                                     0xfff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_HW_ID_MINOR_SHFT                                                                            16u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_HW_ID_STEP_BMSK                                                                         0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_HW_ID_STEP_SHFT                                                                              0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_ADDR(n)                                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0X4 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_OFFS(n)                                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0X4 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_RMSK                                                                     0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_MAXn                                                                             18u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_ADDR(n),val)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_ADDR(n),mask,val,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_INI(n))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_THRESHOLD_OUTER_MIN_BMSK                                                 0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_THRESHOLD_OUTER_MIN_SHFT                                                         24u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_THRESHOLD_INNER_MAX_BMSK                                                   0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_THRESHOLD_INNER_MAX_SHFT                                                         16u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_THRESHOLD_INNER_MIN_BMSK                                                     0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_THRESHOLD_INNER_MIN_SHFT                                                          8u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_AU_MODE_SEL_BMSK                                                               0x80u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_AU_MODE_SEL_SHFT                                                                  7u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_AU_MODE_SEL_LEGACY_MODE_FVAL                                                    0x0u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_AU_MODE_SEL_NEW_AU_MODE_FVAL                                                    0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_CAPTURE_DELAY_BMSK                                                             0x70u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_CAPTURE_DELAY_SHFT                                                                4u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_TRIG_POS_BMSK                                                                   0xcu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_TRIG_POS_SHFT                                                                     2u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_TRIG_POS_PRE_TRIG_FVAL                                                          0x0u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_TRIG_POS_MID_TRIG_FVAL                                                          0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_TRIG_POS_POST_TRIG_FVAL                                                         0x2u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_WATERMARK_EN_BMSK                                                               0x2u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_WATERMARK_EN_SHFT                                                                 1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_AUTO_CAL_EN_BMSK                                                                0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_0_AUTO_CAL_EN_SHFT                                                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_ADDR(n)                                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0X54 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_OFFS(n)                                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0X54 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_RMSK                                                                      0xffffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_MAXn                                                                             18u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_ADDR(n),val)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_ADDR(n),mask,val,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_INI(n))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_PARITY_CHK_EN_BMSK                                                        0x8000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_PARITY_CHK_EN_SHFT                                                               27u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_TDF_COND_WATERMARK_BMSK                                                   0x4000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_TDF_COND_WATERMARK_SHFT                                                          26u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_FIFO_DATA_HS_RATE_BMSK                                                    0x3000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_FIFO_DATA_HS_RATE_SHFT                                                           24u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_RESERVD2_BMSK                                                              0x800000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_RESERVD2_SHFT                                                                    23u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_VS_CLK_DEBUG_EN_BMSK                                                       0x400000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_VS_CLK_DEBUG_EN_SHFT                                                             22u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_VCO_PWR_SEL_MODE_BMSK                                                      0x200000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_VCO_PWR_SEL_MODE_SHFT                                                            21u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_DC_MEAS_CYC_BMSK                                                           0x180000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_DC_MEAS_CYC_SHFT                                                                 19u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_DC_MEAS_CYC_NUM_DC_MEAS_CYC256_FVAL                                             0x0u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_DC_MEAS_CYC_NUM_DC_MEAS_CYC128_FVAL                                             0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_DC_MEAS_CYC_NUM_DC_MEAS_CYC64_FVAL                                              0x2u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_DC_MEAS_CYC_NUM_DC_MEAS_CYC32_FVAL                                              0x3u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_AC_MODE_BMSK                                                                0x40000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_AC_MODE_SHFT                                                                     18u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_RESERVD_BMSK                                                                0x20000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_RESERVD_SHFT                                                                     17u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_MODE_SEL_BMSK                                                               0x10000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_MODE_SEL_SHFT                                                                    16u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_MODE_SEL_INTERRUPT_MODE_FVAL                                                    0x0u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_MODE_SEL_WATERMARK_MODE_FVAL                                                    0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_VCO_FILTER_EN_BMSK                                                           0x8000u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_VCO_FILTER_EN_SHFT                                                               15u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_VCO_POWER_SEL_BMSK                                                           0x4000u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_VCO_POWER_SEL_SHFT                                                               14u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_POWER_EN_BMSK                                                                0x2000u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_POWER_EN_SHFT                                                                    13u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_FUNC_EN_BMSK                                                                 0x1000u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_FUNC_EN_SHFT                                                                     12u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_TRIG_SEL_BMSK                                                                 0xc00u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_TRIG_SEL_SHFT                                                                    10u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_TRIG_SEL_TRIG_SEL0_FVAL                                                         0x0u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_TRIG_SEL_TRIG_SEL1_FVAL                                                         0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_TRIG_SEL_TRIG_SEL2_FVAL                                                         0x2u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_TRIG_SEL_TRIG_SEL3_FVAL                                                         0x3u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_HW_CAPTURE_EN_BMSK                                                            0x200u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_HW_CAPTURE_EN_SHFT                                                                9u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_SW_CAPTURE_BMSK                                                               0x100u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_SW_CAPTURE_SHFT                                                                   8u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_THRESHOLD_OUTER_MAX_BMSK                                                       0xffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_CONFIG_1_THRESHOLD_OUTER_MAX_SHFT                                                          0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_ADDR(n)                                                                   (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0XA4 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_OFFS(n)                                                                   (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0XA4 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_RMSK                                                                      0xffff7ffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_MAXn                                                                              18u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_VDD_MAX_CAL_DATA_BMSK                                                     0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_VDD_MAX_CAL_DATA_SHFT                                                             24u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_VDD_MIN_CAL_DATA_BMSK                                                       0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_VDD_MIN_CAL_DATA_SHFT                                                             16u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_PARITY_BIT_STATUS_BMSK                                                        0x4000u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_PARITY_BIT_STATUS_SHFT                                                            14u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_VS_CLK_FREQ_BMSK                                                              0x3000u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_VS_CLK_FREQ_SHFT                                                                  12u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_VS_CLK_FREQ_CNT_BTWN_0_10_FVAL                                                   0x0u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_VS_CLK_FREQ_CNT_BTWN_10_20_FVAL                                                  0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_VS_CLK_FREQ_CNT_BTWN_20_30_FVAL                                                  0x2u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_VS_CLK_FREQ_CNT_BTWN_30_40_FVAL                                                  0x3u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_VS_CLK_STATUS_BMSK                                                             0x800u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_VS_CLK_STATUS_SHFT                                                                11u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_VS_CLK_STATUS_OFF_FVAL                                                           0x0u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_VS_CLK_STATUS_ON_FVAL                                                            0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_CALIB_DONE_BMSK                                                                0x400u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_CALIB_DONE_SHFT                                                                   10u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_FSM_STATE_BMSK                                                                 0x3c0u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_FSM_STATE_SHFT                                                                     6u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_FIFO_COMPLETE_BMSK                                                              0x20u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_FIFO_COMPLETE_SHFT                                                                 5u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_FIFO_ACTIVE_BMSK                                                                0x10u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_FIFO_ACTIVE_SHFT                                                                   4u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_ALARM_OUTER_MAX_BMSK                                                             0x8u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_ALARM_OUTER_MAX_SHFT                                                               3u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_ALARM_INNER_MAX_BMSK                                                             0x4u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_ALARM_INNER_MAX_SHFT                                                               2u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_ALARM_INNER_MIN_BMSK                                                             0x2u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_ALARM_INNER_MIN_SHFT                                                               1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_ALARM_OUTER_MIN_BMSK                                                             0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_SUMMARY_ALARM_OUTER_MIN_SHFT                                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_ALARM_CNT_ADDR(n)                                                                 (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0XF4 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_ALARM_CNT_OFFS(n)                                                                 (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0XF4 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_ALARM_CNT_RMSK                                                                          0x3fu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_ALARM_CNT_MAXn                                                                            18u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_ALARM_CNT_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_ALARM_CNT_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_ALARM_CNT_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_ALARM_CNT_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_ALARM_CNT_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_ALARM_CNT_ALARM_COUNT_BMSK                                                              0x3fu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_ALARM_CNT_ALARM_COUNT_SHFT                                                                 0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_WR_EN_ADDR                                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x144u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_WR_EN_OFFS                                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x144u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_WR_EN_RMSK                                                                     0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_WR_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_WR_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_WR_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_WR_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_WR_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_WR_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_WR_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_WR_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_WR_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_WR_EN_VSENSE_SENSOR_CONFIG_WR_EN_BMSK                                          0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_WR_EN_VSENSE_SENSOR_CONFIG_WR_EN_SHFT                                                0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_WR_STATUS_ADDR                                                              (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x148u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_WR_STATUS_OFFS                                                              (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x148u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_WR_STATUS_RMSK                                                                 0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_WR_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_WR_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_WR_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_WR_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_WR_STATUS_VSENSE_SENSOR_CONFIG_WR_STATUS_BMSK                                  0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_WR_STATUS_VSENSE_SENSOR_CONFIG_WR_STATUS_SHFT                                        0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FC_MASK_EN_ADDR                                                                    (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x14cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FC_MASK_EN_OFFS                                                                    (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x14cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FC_MASK_EN_RMSK                                                                       0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FC_MASK_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FC_MASK_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FC_MASK_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FC_MASK_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FC_MASK_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FC_MASK_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FC_MASK_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FC_MASK_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FC_MASK_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FC_MASK_EN_VSENSE_SENSOR_FC_MASK_EN_BMSK                                              0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FC_MASK_EN_VSENSE_SENSOR_FC_MASK_EN_SHFT                                                    0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_ADDR                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x150u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_OFFS                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x150u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_RMSK                                                               0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_BMSK                              0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_SHFT                                    0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APPS_ALARM_MASK_EN_ADDR                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x154u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APPS_ALARM_MASK_EN_OFFS                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x154u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APPS_ALARM_MASK_EN_RMSK                                                               0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APPS_ALARM_MASK_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APPS_ALARM_MASK_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APPS_ALARM_MASK_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APPS_ALARM_MASK_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APPS_ALARM_MASK_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APPS_ALARM_MASK_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APPS_ALARM_MASK_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APPS_ALARM_MASK_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APPS_ALARM_MASK_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APPS_ALARM_MASK_EN_VSENSE_SENSOR_APPS_ALARM_MASK_EN_BMSK                              0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APPS_ALARM_MASK_EN_VSENSE_SENSOR_APPS_ALARM_MASK_EN_SHFT                                    0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_ADDR                                                          (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x158u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_OFFS                                                          (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x158u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_RMSK                                                             0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_BMSK                          0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_SHFT                                0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_ADDR                                                          (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x15cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_OFFS                                                          (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x15cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_RMSK                                                             0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_BMSK                          0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_SHFT                                0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_ALARM_STATUS_ADDR                                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x160u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_ALARM_STATUS_OFFS                                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x160u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_ALARM_STATUS_RMSK                                                                     0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_ALARM_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_ALARM_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_ALARM_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_ALARM_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_ALARM_STATUS_VSENSE_SENSOR_ALARM_STATUS_BMSK                                          0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_ALARM_STATUS_VSENSE_SENSOR_ALARM_STATUS_SHFT                                                0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FC_STATUS_ADDR                                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x164u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FC_STATUS_OFFS                                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x164u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FC_STATUS_RMSK                                                                        0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FC_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FC_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FC_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FC_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FC_STATUS_VSENSE_SENSOR_FC_STATUS_BMSK                                                0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FC_STATUS_VSENSE_SENSOR_FC_STATUS_SHFT                                                      0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_ADDR                                                              (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x168u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_OFFS                                                              (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x168u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_RMSK                                                                     0x3u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_MUX_SEL_BMSK                                                             0x3u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_MUX_SEL_SHFT                                                               0u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_MUX_SEL_FIRST_64BITS_FVAL                                                0x0u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_MUX_SEL_SECOND_64BITS_FVAL                                               0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_MUX_SEL_THIRD_64BITS_FVAL                                                0x2u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_MUX_SEL_FOURTH_64BITS_FVAL                                               0x3u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_3_TO_0_ADDR                                                              (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x16cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_3_TO_0_OFFS                                                              (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x16cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_3_TO_0_RMSK                                                              0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_3_TO_0_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_3_TO_0_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_3_TO_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_3_TO_0_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_3_TO_0_FIFO_DATA3_BMSK                                                   0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_3_TO_0_FIFO_DATA3_SHFT                                                           24u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_3_TO_0_FIFO_DATA2_BMSK                                                     0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_3_TO_0_FIFO_DATA2_SHFT                                                           16u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_3_TO_0_FIFO_DATA1_BMSK                                                       0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_3_TO_0_FIFO_DATA1_SHFT                                                            8u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_3_TO_0_FIFO_DATA0_BMSK                                                         0xffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_3_TO_0_FIFO_DATA0_SHFT                                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_7_TO_4_ADDR                                                              (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x170u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_7_TO_4_OFFS                                                              (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x170u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_7_TO_4_RMSK                                                              0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_7_TO_4_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_7_TO_4_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_7_TO_4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_7_TO_4_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_7_TO_4_FIFO_DATA7_BMSK                                                   0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_7_TO_4_FIFO_DATA7_SHFT                                                           24u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_7_TO_4_FIFO_DATA6_BMSK                                                     0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_7_TO_4_FIFO_DATA6_SHFT                                                           16u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_7_TO_4_FIFO_DATA5_BMSK                                                       0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_7_TO_4_FIFO_DATA5_SHFT                                                            8u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_7_TO_4_FIFO_DATA4_BMSK                                                         0xffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_7_TO_4_FIFO_DATA4_SHFT                                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_CLEAR_SUMMARY_ADDR                                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x174u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_CLEAR_SUMMARY_OFFS                                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x174u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_CLEAR_SUMMARY_RMSK                                                                     0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_CLEAR_SUMMARY_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_CLEAR_SUMMARY_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_CLEAR_SUMMARY_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_CLEAR_SUMMARY_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_CLEAR_SUMMARY_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_CLEAR_SUMMARY_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_CLEAR_SUMMARY_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_CLEAR_SUMMARY_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_CLEAR_SUMMARY_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_CLEAR_SUMMARY_VSENSE_SENSOR_CLEAR_SUMMARY_BMSK                                         0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_CLEAR_SUMMARY_VSENSE_SENSOR_CLEAR_SUMMARY_SHFT                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_COMMON_CONFIG_ADDR                                                                 (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x178u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_COMMON_CONFIG_OFFS                                                                 (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x178u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_COMMON_CONFIG_RMSK                                                                       0x1fu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_COMMON_CONFIG_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_COMMON_CONFIG_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_COMMON_CONFIG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_COMMON_CONFIG_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_COMMON_CONFIG_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_COMMON_CONFIG_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_COMMON_CONFIG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_COMMON_CONFIG_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_COMMON_CONFIG_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_COMMON_CONFIG_VSENSE_CLR_RCDRW_BMSK                                                      0x10u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_COMMON_CONFIG_VSENSE_CLR_RCDRW_SHFT                                                         4u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_COMMON_CONFIG_VSENSE_SW_DATA_RD_MODE_BMSK                                                 0x8u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_COMMON_CONFIG_VSENSE_SW_DATA_RD_MODE_SHFT                                                   3u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_COMMON_CONFIG_VSENSE_CNTRL_CLR_INT_FIFO_BMSK                                              0x4u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_COMMON_CONFIG_VSENSE_CNTRL_CLR_INT_FIFO_SHFT                                                2u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_COMMON_CONFIG_VSENSE_SENSOR_INT_MODE_BMSK                                                 0x2u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_COMMON_CONFIG_VSENSE_SENSOR_INT_MODE_SHFT                                                   1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_COMMON_CONFIG_VSENSE_SENSOR_INT_MODE_CONTINUOUS_MODE_FVAL                                 0x0u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_COMMON_CONFIG_VSENSE_SENSOR_INT_MODE_BREAK_MODE_FVAL                                      0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_COMMON_CONFIG_VSENSE_SENSOR_BROADCAST_EN_BMSK                                             0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_COMMON_CONFIG_VSENSE_SENSOR_BROADCAST_EN_SHFT                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HW_BYPASS_STATUS_ADDR                                                              (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x17cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HW_BYPASS_STATUS_OFFS                                                              (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x17cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HW_BYPASS_STATUS_RMSK                                                                 0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HW_BYPASS_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HW_BYPASS_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HW_BYPASS_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HW_BYPASS_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HW_BYPASS_STATUS_VSENSE_SENSOR_HW_BYPASS_STATUS_BMSK                                  0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HW_BYPASS_STATUS_VSENSE_SENSOR_HW_BYPASS_STATUS_SHFT                                        0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_TX_MISC_STATUS_CHAINn_ADDR(n)                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0X180 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_TX_MISC_STATUS_CHAINn_OFFS(n)                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0X180 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_TX_MISC_STATUS_CHAINn_RMSK                                                          0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_TX_MISC_STATUS_CHAINn_MAXn                                                                  13u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_TX_MISC_STATUS_CHAINn_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_TX_MISC_STATUS_CHAINn_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_TX_MISC_STATUS_CHAINn_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_TX_MISC_STATUS_CHAINn_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_TX_MISC_STATUS_CHAINn_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_TX_MISC_STATUS_CHAINn_DEBUG_BUS_TX_CHAIN_BMSK                                       0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_TX_MISC_STATUS_CHAINn_DEBUG_BUS_TX_CHAIN_SHFT                                                0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RX_MISC_STATUS_ADDR                                                                 (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x1c0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RX_MISC_STATUS_OFFS                                                                 (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x1c0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RX_MISC_STATUS_RMSK                                                                       0x7fu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RX_MISC_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RX_MISC_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RX_MISC_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RX_MISC_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RX_MISC_STATUS_CMB_DATA_SENT_BMSK                                                         0x40u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RX_MISC_STATUS_CMB_DATA_SENT_SHFT                                                            6u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RX_MISC_STATUS_RX_FSM_ERR_CNT_BMSK                                                        0x38u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RX_MISC_STATUS_RX_FSM_ERR_CNT_SHFT                                                           3u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RX_MISC_STATUS_RX_FSM_STATE_BMSK                                                           0x7u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RX_MISC_STATUS_RX_FSM_STATE_SHFT                                                             0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_ADDR                                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x1c4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_OFFS                                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x1c4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_RMSK                                                                       0x8000003ful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_EN_BMSK                                                          0x80000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_EN_SHFT                                                                  31u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_BMSK                                                               0x3fu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_SHFT                                                                  0u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_TX_DBG_BUS0_FVAL                                                    0x0u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_TX_DBG_BUS1_FVAL                                                    0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_TX_DBG_BUS2_FVAL                                                    0x2u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_TX_DBG_BUS3_FVAL                                                    0x3u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_TX_DBG_BUS4_FVAL                                                    0x4u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_TX_DBG_BUS5_FVAL                                                    0x5u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_TX_DBG_BUS6_FVAL                                                    0x6u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_TX_DBG_BUS7_FVAL                                                    0x7u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_TX_DBG_BUS8_FVAL                                                    0x8u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_TX_DBG_BUS9_FVAL                                                    0x9u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_TX_DBG_BUS10_FVAL                                                   0xau
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_TX_DBG_BUS11_FVAL                                                   0xbu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_TX_DBG_BUS12_FVAL                                                   0xcu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_TX_DBG_BUS13_FVAL                                                   0xdu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_RX_DBG_BUS_FVAL                                                    0x10u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_ALARM_BUS_FVAL                                                     0x11u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CMB_DATA_FVAL                                                      0x12u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_FC_BUS_FVAL                                                        0x13u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLAMP_EN_BUS_FVAL                                                  0x14u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_DISABLE_SENSOR_BUS_FVAL                                            0x15u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_POWER_DOWN_BUS_FVAL                                                0x16u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_RESET_STATE_BUS_FVAL                                               0x17u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_EN_BUS_FVAL                                                    0x18u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM0_DBG_BUS_FVAL                                              0x19u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM1_DBG_BUS_FVAL                                              0x1au
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM2_DBG_BUS_FVAL                                              0x1bu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM3_DBG_BUS_FVAL                                              0x1cu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM4_DBG_BUS_FVAL                                              0x1du
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM5_DBG_BUS_FVAL                                              0x1eu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM6_DBG_BUS_FVAL                                              0x1fu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM7_DBG_BUS_FVAL                                              0x20u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM8_DBG_BUS_FVAL                                              0x21u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM9_DBG_BUS_FVAL                                              0x22u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM10_DBG_BUS_FVAL                                             0x23u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM11_DBG_BUS_FVAL                                             0x24u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM12_DBG_BUS_FVAL                                             0x25u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM13_DBG_BUS_FVAL                                             0x26u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM14_DBG_BUS_FVAL                                             0x27u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM15_DBG_BUS_FVAL                                             0x28u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM16_DBG_BUS_FVAL                                             0x29u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM17_DBG_BUS_FVAL                                             0x2au
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM18_DBG_BUS_FVAL                                             0x2bu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CPRF0_DBG_BUS_FVAL                                                 0x2eu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CPRF1_DBG_BUS_FVAL                                                 0x2fu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CPRF2_DBG_BUS_FVAL                                                 0x30u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CPRF3_DBG_BUS_FVAL                                                 0x31u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CPRF4_DBG_BUS_FVAL                                                 0x32u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CPRF5_DBG_BUS_FVAL                                                 0x33u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CPRF6_DBG_BUS_FVAL                                                 0x34u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CPRF7_DBG_BUS_FVAL                                                 0x35u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CPRF8_DBG_BUS_FVAL                                                 0x36u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CPRF9_DBG_BUS_FVAL                                                 0x37u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CPRH0_DBG_BUS_FVAL                                                 0x3au
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CPRH1_DBG_BUS_FVAL                                                 0x3bu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_VACC_DBG_BUS_FVAL                                                  0x3cu

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_MODE_ADDR                                                                (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x1c8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_MODE_OFFS                                                                (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x1c8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_MODE_RMSK                                                                      0xffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DELAY_BMSK                                        0xc0u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DELAY_SHFT                                           6u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DELAY_DLY_10_CYCLES_FVAL                           0x0u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DELAY_DLY_20_CYCLES_FVAL                           0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DELAY_DLY_30_CYCLES_FVAL                           0x2u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DELAY_DLY_50_CYCLES_FVAL                           0x3u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DRIVE_SDATA1_BMSK                                 0x20u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DRIVE_SDATA1_SHFT                                    5u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DRIVE_SDATA0_BMSK                                 0x10u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DRIVE_SDATA0_SHFT                                    4u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DRIVE_SENA_BMSK                                    0x8u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DRIVE_SENA_SHFT                                      3u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DRIVE_SMODE1_BMSK                                  0x4u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DRIVE_SMODE1_SHFT                                    2u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DRIVE_SMODE0_BMSK                                  0x2u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DRIVE_SMODE0_SHFT                                    1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_MODE_EN_BMSK                                       0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_MODE_EN_SHFT                                         0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_ADDR(n)                                                    (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0X1CC + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_OFFS(n)                                                    (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0X1CC + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_RMSK                                                             0x1fu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_MAXn                                                               13u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_SELF_TEST_SDATA1_STATUS_CHAIN_BMSK                               0x10u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_SELF_TEST_SDATA1_STATUS_CHAIN_SHFT                                  4u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_SELF_TEST_SDATA0_STATUS_CHAIN_BMSK                                0x8u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_SELF_TEST_SDATA0_STATUS_CHAIN_SHFT                                  3u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_SELF_TEST_SENA_STATUS_CHAIN_BMSK                                  0x4u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_SELF_TEST_SENA_STATUS_CHAIN_SHFT                                    2u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_SELF_TEST_SMODE1_STATUS_CHAIN_BMSK                                0x2u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_SELF_TEST_SMODE1_STATUS_CHAIN_SHFT                                  1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_SELF_TEST_SMODE0_STATUS_CHAIN_BMSK                                0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_SELF_TEST_SMODE0_STATUS_CHAIN_SHFT                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_DISABLE_SENSOR_STATUS_ADDR                                                         (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x210u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_DISABLE_SENSOR_STATUS_OFFS                                                         (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x210u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_DISABLE_SENSOR_STATUS_RMSK                                                            0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_DISABLE_SENSOR_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_DISABLE_SENSOR_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_DISABLE_SENSOR_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_DISABLE_SENSOR_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_DISABLE_SENSOR_STATUS_VSENSE_SENSOR_DISABLE_SENSOR_STATUS_BMSK                        0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_DISABLE_SENSOR_STATUS_VSENSE_SENSOR_DISABLE_SENSOR_STATUS_SHFT                              0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_POWER_DOWN_STATUS_ADDR                                                             (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x214u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_POWER_DOWN_STATUS_OFFS                                                             (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x214u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_POWER_DOWN_STATUS_RMSK                                                                0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_POWER_DOWN_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_POWER_DOWN_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_POWER_DOWN_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_POWER_DOWN_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_POWER_DOWN_STATUS_VSENSE_SENSOR_POWER_DOWN_STATUS_BMSK                                0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_POWER_DOWN_STATUS_VSENSE_SENSOR_POWER_DOWN_STATUS_SHFT                                      0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_CPRF_ENABLE_ADDR                                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x220u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_CPRF_ENABLE_OFFS                                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x220u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_CPRF_ENABLE_RMSK                                                                              0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_CPRF_ENABLE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_CPRF_ENABLE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_CPRF_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_CPRF_ENABLE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_CPRF_ENABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_CPRF_ENABLE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_CPRF_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_CPRF_ENABLE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_CPRF_ENABLE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_CPRF_ENABLE_CX_ENABLE_BMSK                                                                    0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_CPRF_ENABLE_CX_ENABLE_SHFT                                                                      0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_MIN_SUPPORTED_MODE_ADDR                                                                (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x224u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_MIN_SUPPORTED_MODE_OFFS                                                                (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x224u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_MIN_SUPPORTED_MODE_RMSK                                                                       0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_MIN_SUPPORTED_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_MIN_SUPPORTED_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_MIN_SUPPORTED_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_MIN_SUPPORTED_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_MIN_SUPPORTED_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_MIN_SUPPORTED_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_MIN_SUPPORTED_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_MIN_SUPPORTED_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_MIN_SUPPORTED_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_MIN_SUPPORTED_MODE_CX_MODE_BMSK                                                               0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_MIN_SUPPORTED_MODE_CX_MODE_SHFT                                                                 0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_CURR_MODE_SEL_ADDR                                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x228u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_CURR_MODE_SEL_OFFS                                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x228u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_CURR_MODE_SEL_RMSK                                                                            0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_CURR_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_CURR_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_CURR_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_CURR_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_CURR_MODE_SEL_CX_CURR_MODE_BMSK                                                               0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_CURR_MODE_SEL_CX_CURR_MODE_SHFT                                                                 0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PREV_MODE_SEL_ADDR                                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x22cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PREV_MODE_SEL_OFFS                                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x22cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PREV_MODE_SEL_RMSK                                                                            0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PREV_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PREV_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PREV_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PREV_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PREV_MODE_SEL_CX_PREV_MODE_BMSK                                                               0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PREV_MODE_SEL_CX_PREV_MODE_SHFT                                                                 0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_RAIL_STATUS_ADDR                                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x230u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_RAIL_STATUS_OFFS                                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x230u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_RAIL_STATUS_RMSK                                                                              0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_RAIL_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_RAIL_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_RAIL_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_RAIL_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_RAIL_STATUS_CX_RAIL_IS_UP_BMSK                                                                0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_RAIL_STATUS_CX_RAIL_IS_UP_SHFT                                                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PC_MODE_ADDR                                                                           (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x234u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PC_MODE_OFFS                                                                           (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x234u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PC_MODE_RMSK                                                                                  0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PC_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PC_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PC_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PC_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PC_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PC_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PC_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PC_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PC_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PC_MODE_CX_PC_MODE_BMSK                                                                       0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PC_MODE_CX_PC_MODE_SHFT                                                                         0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_CX_ADDR                                                      (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x238u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_CX_OFFS                                                      (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x238u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_CX_RMSK                                                          0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_CX_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_CX_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_CX_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_CX_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_CX_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_CX_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_CX_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_CX_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_CX_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_CX_POST_COLLAPSE_CNTR_VAL_CX_BMSK                                0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_CX_POST_COLLAPSE_CNTR_VAL_CX_SHFT                                     0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PU_INIT_MODE_ADDR                                                                      (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x23cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PU_INIT_MODE_OFFS                                                                      (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x23cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PU_INIT_MODE_RMSK                                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PU_INIT_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PU_INIT_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PU_INIT_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PU_INIT_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PU_INIT_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PU_INIT_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PU_INIT_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PU_INIT_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PU_INIT_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PU_INIT_MODE_CX_PU_INIT_MODE_BMSK                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CX_PU_INIT_MODE_CX_PU_INIT_MODE_SHFT                                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_CPRF_ENABLE_ADDR                                                                      (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x240u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_CPRF_ENABLE_OFFS                                                                      (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x240u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_CPRF_ENABLE_RMSK                                                                             0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_CPRF_ENABLE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_CPRF_ENABLE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_CPRF_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_CPRF_ENABLE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_CPRF_ENABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_CPRF_ENABLE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_CPRF_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_CPRF_ENABLE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_CPRF_ENABLE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_CPRF_ENABLE_MXA_ENABLE_BMSK                                                                  0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_CPRF_ENABLE_MXA_ENABLE_SHFT                                                                    0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_MIN_SUPPORTED_MODE_ADDR                                                               (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x244u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_MIN_SUPPORTED_MODE_OFFS                                                               (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x244u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_MIN_SUPPORTED_MODE_RMSK                                                                      0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_MIN_SUPPORTED_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_MIN_SUPPORTED_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_MIN_SUPPORTED_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_MIN_SUPPORTED_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_MIN_SUPPORTED_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_MIN_SUPPORTED_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_MIN_SUPPORTED_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_MIN_SUPPORTED_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_MIN_SUPPORTED_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_MIN_SUPPORTED_MODE_MXA_MODE_BMSK                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_MIN_SUPPORTED_MODE_MXA_MODE_SHFT                                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_CURR_MODE_SEL_ADDR                                                                    (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x248u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_CURR_MODE_SEL_OFFS                                                                    (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x248u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_CURR_MODE_SEL_RMSK                                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_CURR_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_CURR_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_CURR_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_CURR_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_CURR_MODE_SEL_MXA_CURR_MODE_BMSK                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_CURR_MODE_SEL_MXA_CURR_MODE_SHFT                                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PREV_MODE_SEL_ADDR                                                                    (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x24cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PREV_MODE_SEL_OFFS                                                                    (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x24cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PREV_MODE_SEL_RMSK                                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PREV_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PREV_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PREV_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PREV_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PREV_MODE_SEL_MXA_PREV_MODE_BMSK                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PREV_MODE_SEL_MXA_PREV_MODE_SHFT                                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_RAIL_STATUS_ADDR                                                                      (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x250u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_RAIL_STATUS_OFFS                                                                      (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x250u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_RAIL_STATUS_RMSK                                                                             0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_RAIL_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_RAIL_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_RAIL_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_RAIL_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_RAIL_STATUS_MXA_RAIL_IS_UP_BMSK                                                              0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_RAIL_STATUS_MXA_RAIL_IS_UP_SHFT                                                                0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PC_MODE_ADDR                                                                          (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x254u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PC_MODE_OFFS                                                                          (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x254u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PC_MODE_RMSK                                                                                 0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PC_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PC_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PC_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PC_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PC_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PC_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PC_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PC_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PC_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PC_MODE_MXA_PC_MODE_BMSK                                                                     0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PC_MODE_MXA_PC_MODE_SHFT                                                                       0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXA_ADDR                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x258u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXA_OFFS                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x258u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXA_RMSK                                                         0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXA_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXA_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXA_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXA_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXA_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXA_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXA_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXA_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXA_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXA_POST_COLLAPSE_CNTR_VAL_MXA_BMSK                              0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXA_POST_COLLAPSE_CNTR_VAL_MXA_SHFT                                   0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PU_INIT_MODE_ADDR                                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x25cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PU_INIT_MODE_OFFS                                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x25cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PU_INIT_MODE_RMSK                                                                            0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PU_INIT_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PU_INIT_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PU_INIT_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PU_INIT_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PU_INIT_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PU_INIT_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PU_INIT_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PU_INIT_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PU_INIT_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PU_INIT_MODE_MXA_PU_INIT_MODE_BMSK                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXA_PU_INIT_MODE_MXA_PU_INIT_MODE_SHFT                                                             0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_CPRF_ENABLE_ADDR                                                                      (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x260u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_CPRF_ENABLE_OFFS                                                                      (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x260u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_CPRF_ENABLE_RMSK                                                                             0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_CPRF_ENABLE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_CPRF_ENABLE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_CPRF_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_CPRF_ENABLE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_CPRF_ENABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_CPRF_ENABLE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_CPRF_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_CPRF_ENABLE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_CPRF_ENABLE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_CPRF_ENABLE_DDR_ENABLE_BMSK                                                                  0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_CPRF_ENABLE_DDR_ENABLE_SHFT                                                                    0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_MIN_SUPPORTED_MODE_ADDR                                                               (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x264u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_MIN_SUPPORTED_MODE_OFFS                                                               (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x264u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_MIN_SUPPORTED_MODE_RMSK                                                                      0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_MIN_SUPPORTED_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_MIN_SUPPORTED_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_MIN_SUPPORTED_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_MIN_SUPPORTED_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_MIN_SUPPORTED_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_MIN_SUPPORTED_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_MIN_SUPPORTED_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_MIN_SUPPORTED_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_MIN_SUPPORTED_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_MIN_SUPPORTED_MODE_DDR_MODE_BMSK                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_MIN_SUPPORTED_MODE_DDR_MODE_SHFT                                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_CURR_MODE_SEL_ADDR                                                                    (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x268u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_CURR_MODE_SEL_OFFS                                                                    (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x268u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_CURR_MODE_SEL_RMSK                                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_CURR_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_CURR_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_CURR_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_CURR_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_CURR_MODE_SEL_DDR_CURR_MODE_BMSK                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_CURR_MODE_SEL_DDR_CURR_MODE_SHFT                                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PREV_MODE_SEL_ADDR                                                                    (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x26cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PREV_MODE_SEL_OFFS                                                                    (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x26cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PREV_MODE_SEL_RMSK                                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PREV_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PREV_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PREV_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PREV_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PREV_MODE_SEL_DDR_PREV_MODE_BMSK                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PREV_MODE_SEL_DDR_PREV_MODE_SHFT                                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_RAIL_STATUS_ADDR                                                                      (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x270u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_RAIL_STATUS_OFFS                                                                      (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x270u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_RAIL_STATUS_RMSK                                                                             0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_RAIL_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_RAIL_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_RAIL_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_RAIL_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_RAIL_STATUS_DDR_RAIL_IS_UP_BMSK                                                              0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_RAIL_STATUS_DDR_RAIL_IS_UP_SHFT                                                                0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PC_MODE_ADDR                                                                          (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x274u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PC_MODE_OFFS                                                                          (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x274u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PC_MODE_RMSK                                                                                 0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PC_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PC_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PC_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PC_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PC_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PC_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PC_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PC_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PC_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PC_MODE_DDR_PC_MODE_BMSK                                                                     0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PC_MODE_DDR_PC_MODE_SHFT                                                                       0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_DDR_ADDR                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x278u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_DDR_OFFS                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x278u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_DDR_RMSK                                                         0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_DDR_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_DDR_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_DDR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_DDR_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_DDR_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_DDR_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_DDR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_DDR_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_DDR_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_DDR_POST_COLLAPSE_CNTR_VAL_DDR_BMSK                              0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_DDR_POST_COLLAPSE_CNTR_VAL_DDR_SHFT                                   0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PU_INIT_MODE_ADDR                                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x27cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PU_INIT_MODE_OFFS                                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x27cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PU_INIT_MODE_RMSK                                                                            0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PU_INIT_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PU_INIT_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PU_INIT_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PU_INIT_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PU_INIT_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PU_INIT_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PU_INIT_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PU_INIT_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PU_INIT_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PU_INIT_MODE_DDR_PU_INIT_MODE_BMSK                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_DDR_PU_INIT_MODE_DDR_PU_INIT_MODE_SHFT                                                             0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_CPRF_ENABLE_ADDR                                                                   (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x280u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_CPRF_ENABLE_OFFS                                                                   (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x280u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_CPRF_ENABLE_RMSK                                                                          0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_CPRF_ENABLE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_CPRF_ENABLE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_CPRF_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_CPRF_ENABLE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_CPRF_ENABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_CPRF_ENABLE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_CPRF_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_CPRF_ENABLE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_CPRF_ENABLE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_CPRF_ENABLE_SSC_CX_ENABLE_BMSK                                                            0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_CPRF_ENABLE_SSC_CX_ENABLE_SHFT                                                              0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_MIN_SUPPORTED_MODE_ADDR                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x284u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_MIN_SUPPORTED_MODE_OFFS                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x284u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_MIN_SUPPORTED_MODE_RMSK                                                                   0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_MIN_SUPPORTED_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_MIN_SUPPORTED_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_MIN_SUPPORTED_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_MIN_SUPPORTED_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_MIN_SUPPORTED_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_MIN_SUPPORTED_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_MIN_SUPPORTED_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_MIN_SUPPORTED_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_MIN_SUPPORTED_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_MIN_SUPPORTED_MODE_SSC_CX_MODE_BMSK                                                       0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_MIN_SUPPORTED_MODE_SSC_CX_MODE_SHFT                                                         0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_CURR_MODE_SEL_ADDR                                                                 (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x288u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_CURR_MODE_SEL_OFFS                                                                 (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x288u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_CURR_MODE_SEL_RMSK                                                                        0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_CURR_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_CURR_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_CURR_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_CURR_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_CURR_MODE_SEL_SSC_CX_CURR_MODE_BMSK                                                       0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_CURR_MODE_SEL_SSC_CX_CURR_MODE_SHFT                                                         0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PREV_MODE_SEL_ADDR                                                                 (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x28cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PREV_MODE_SEL_OFFS                                                                 (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x28cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PREV_MODE_SEL_RMSK                                                                        0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PREV_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PREV_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PREV_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PREV_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PREV_MODE_SEL_SSC_CX_PREV_MODE_BMSK                                                       0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PREV_MODE_SEL_SSC_CX_PREV_MODE_SHFT                                                         0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_RAIL_STATUS_ADDR                                                                   (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x290u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_RAIL_STATUS_OFFS                                                                   (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x290u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_RAIL_STATUS_RMSK                                                                          0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_RAIL_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_RAIL_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_RAIL_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_RAIL_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_RAIL_STATUS_SSC_CX_RAIL_IS_UP_BMSK                                                        0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_RAIL_STATUS_SSC_CX_RAIL_IS_UP_SHFT                                                          0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PC_MODE_ADDR                                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x294u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PC_MODE_OFFS                                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x294u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PC_MODE_RMSK                                                                              0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PC_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PC_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PC_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PC_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PC_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PC_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PC_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PC_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PC_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PC_MODE_SSC_CX_PC_MODE_BMSK                                                               0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PC_MODE_SSC_CX_PC_MODE_SHFT                                                                 0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_CX_ADDR                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x298u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_CX_OFFS                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x298u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_CX_RMSK                                                      0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_CX_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_CX_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_CX_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_CX_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_CX_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_CX_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_CX_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_CX_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_CX_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_CX_POST_COLLAPSE_CNTR_VAL_SSC_CX_BMSK                        0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_CX_POST_COLLAPSE_CNTR_VAL_SSC_CX_SHFT                             0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PU_INIT_MODE_ADDR                                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x29cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PU_INIT_MODE_OFFS                                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x29cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PU_INIT_MODE_RMSK                                                                         0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PU_INIT_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PU_INIT_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PU_INIT_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PU_INIT_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PU_INIT_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PU_INIT_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PU_INIT_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PU_INIT_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PU_INIT_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PU_INIT_MODE_SSC_CX_PU_INIT_MODE_BMSK                                                     0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_CX_PU_INIT_MODE_SSC_CX_PU_INIT_MODE_SHFT                                                       0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_CPRF_ENABLE_ADDR                                                                   (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x2a0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_CPRF_ENABLE_OFFS                                                                   (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2a0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_CPRF_ENABLE_RMSK                                                                          0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_CPRF_ENABLE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_CPRF_ENABLE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_CPRF_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_CPRF_ENABLE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_CPRF_ENABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_CPRF_ENABLE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_CPRF_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_CPRF_ENABLE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_CPRF_ENABLE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_CPRF_ENABLE_SSC_MX_ENABLE_BMSK                                                            0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_CPRF_ENABLE_SSC_MX_ENABLE_SHFT                                                              0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_MIN_SUPPORTED_MODE_ADDR                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x2a4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_MIN_SUPPORTED_MODE_OFFS                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2a4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_MIN_SUPPORTED_MODE_RMSK                                                                   0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_MIN_SUPPORTED_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_MIN_SUPPORTED_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_MIN_SUPPORTED_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_MIN_SUPPORTED_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_MIN_SUPPORTED_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_MIN_SUPPORTED_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_MIN_SUPPORTED_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_MIN_SUPPORTED_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_MIN_SUPPORTED_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_MIN_SUPPORTED_MODE_SSC_MX_MODE_BMSK                                                       0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_MIN_SUPPORTED_MODE_SSC_MX_MODE_SHFT                                                         0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_CURR_MODE_SEL_ADDR                                                                 (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x2a8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_CURR_MODE_SEL_OFFS                                                                 (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2a8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_CURR_MODE_SEL_RMSK                                                                        0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_CURR_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_CURR_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_CURR_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_CURR_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_CURR_MODE_SEL_SSC_MX_CURR_MODE_BMSK                                                       0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_CURR_MODE_SEL_SSC_MX_CURR_MODE_SHFT                                                         0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PREV_MODE_SEL_ADDR                                                                 (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x2acu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PREV_MODE_SEL_OFFS                                                                 (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2acu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PREV_MODE_SEL_RMSK                                                                        0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PREV_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PREV_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PREV_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PREV_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PREV_MODE_SEL_SSC_MX_PREV_MODE_BMSK                                                       0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PREV_MODE_SEL_SSC_MX_PREV_MODE_SHFT                                                         0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_RAIL_STATUS_ADDR                                                                   (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x2b0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_RAIL_STATUS_OFFS                                                                   (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2b0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_RAIL_STATUS_RMSK                                                                          0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_RAIL_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_RAIL_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_RAIL_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_RAIL_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_RAIL_STATUS_SSC_MX_RAIL_IS_UP_BMSK                                                        0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_RAIL_STATUS_SSC_MX_RAIL_IS_UP_SHFT                                                          0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PC_MODE_ADDR                                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x2b4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PC_MODE_OFFS                                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2b4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PC_MODE_RMSK                                                                              0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PC_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PC_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PC_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PC_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PC_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PC_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PC_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PC_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PC_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PC_MODE_SSC_MX_PC_MODE_BMSK                                                               0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PC_MODE_SSC_MX_PC_MODE_SHFT                                                                 0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_MX_ADDR                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x2b8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_MX_OFFS                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2b8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_MX_RMSK                                                      0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_MX_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_MX_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_MX_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_MX_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_MX_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_MX_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_MX_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_MX_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_MX_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_MX_POST_COLLAPSE_CNTR_VAL_SSC_MX_BMSK                        0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_MX_POST_COLLAPSE_CNTR_VAL_SSC_MX_SHFT                             0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PU_INIT_MODE_ADDR                                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x2bcu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PU_INIT_MODE_OFFS                                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2bcu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PU_INIT_MODE_RMSK                                                                         0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PU_INIT_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PU_INIT_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PU_INIT_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PU_INIT_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PU_INIT_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PU_INIT_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PU_INIT_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PU_INIT_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PU_INIT_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PU_INIT_MODE_SSC_MX_PU_INIT_MODE_BMSK                                                     0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SSC_MX_PU_INIT_MODE_SSC_MX_PU_INIT_MODE_SHFT                                                       0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_CPRF_ENABLE_ADDR                                                                      (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x2c0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_CPRF_ENABLE_OFFS                                                                      (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2c0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_CPRF_ENABLE_RMSK                                                                             0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_CPRF_ENABLE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_CPRF_ENABLE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_CPRF_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_CPRF_ENABLE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_CPRF_ENABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_CPRF_ENABLE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_CPRF_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_CPRF_ENABLE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_CPRF_ENABLE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_CPRF_ENABLE_GFX_ENABLE_BMSK                                                                  0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_CPRF_ENABLE_GFX_ENABLE_SHFT                                                                    0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_MIN_SUPPORTED_MODE_ADDR                                                               (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x2c4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_MIN_SUPPORTED_MODE_OFFS                                                               (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2c4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_MIN_SUPPORTED_MODE_RMSK                                                                      0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_MIN_SUPPORTED_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_MIN_SUPPORTED_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_MIN_SUPPORTED_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_MIN_SUPPORTED_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_MIN_SUPPORTED_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_MIN_SUPPORTED_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_MIN_SUPPORTED_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_MIN_SUPPORTED_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_MIN_SUPPORTED_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_MIN_SUPPORTED_MODE_GFX_MODE_BMSK                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_MIN_SUPPORTED_MODE_GFX_MODE_SHFT                                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_CURR_MODE_SEL_ADDR                                                                    (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x2c8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_CURR_MODE_SEL_OFFS                                                                    (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2c8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_CURR_MODE_SEL_RMSK                                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_CURR_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_CURR_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_CURR_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_CURR_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_CURR_MODE_SEL_GFX_CURR_MODE_BMSK                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_CURR_MODE_SEL_GFX_CURR_MODE_SHFT                                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PREV_MODE_SEL_ADDR                                                                    (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x2ccu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PREV_MODE_SEL_OFFS                                                                    (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2ccu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PREV_MODE_SEL_RMSK                                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PREV_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PREV_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PREV_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PREV_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PREV_MODE_SEL_GFX_PREV_MODE_BMSK                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PREV_MODE_SEL_GFX_PREV_MODE_SHFT                                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_RAIL_STATUS_ADDR                                                                      (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x2d0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_RAIL_STATUS_OFFS                                                                      (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2d0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_RAIL_STATUS_RMSK                                                                             0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_RAIL_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_RAIL_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_RAIL_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_RAIL_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_RAIL_STATUS_GFX_RAIL_IS_UP_BMSK                                                              0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_RAIL_STATUS_GFX_RAIL_IS_UP_SHFT                                                                0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PC_MODE_ADDR                                                                          (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x2d4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PC_MODE_OFFS                                                                          (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2d4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PC_MODE_RMSK                                                                                 0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PC_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PC_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PC_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PC_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PC_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PC_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PC_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PC_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PC_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PC_MODE_GFX_PC_MODE_BMSK                                                                     0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PC_MODE_GFX_PC_MODE_SHFT                                                                       0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_GFX_ADDR                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x2d8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_GFX_OFFS                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2d8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_GFX_RMSK                                                         0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_GFX_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_GFX_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_GFX_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_GFX_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_GFX_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_GFX_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_GFX_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_GFX_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_GFX_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_GFX_POST_COLLAPSE_CNTR_VAL_GFX_BMSK                              0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_GFX_POST_COLLAPSE_CNTR_VAL_GFX_SHFT                                   0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PU_INIT_MODE_ADDR                                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x2dcu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PU_INIT_MODE_OFFS                                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2dcu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PU_INIT_MODE_RMSK                                                                            0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PU_INIT_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PU_INIT_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PU_INIT_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PU_INIT_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PU_INIT_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PU_INIT_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PU_INIT_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PU_INIT_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PU_INIT_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PU_INIT_MODE_GFX_PU_INIT_MODE_BMSK                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_GFX_PU_INIT_MODE_GFX_PU_INIT_MODE_SHFT                                                             0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_CPRF_ENABLE_ADDR                                                                   (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x2e0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_CPRF_ENABLE_OFFS                                                                   (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2e0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_CPRF_ENABLE_RMSK                                                                          0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_CPRF_ENABLE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_CPRF_ENABLE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_CPRF_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_CPRF_ENABLE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_CPRF_ENABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_CPRF_ENABLE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_CPRF_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_CPRF_ENABLE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_CPRF_ENABLE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_CPRF_ENABLE_NSP_CX_ENABLE_BMSK                                                            0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_CPRF_ENABLE_NSP_CX_ENABLE_SHFT                                                              0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_MIN_SUPPORTED_MODE_ADDR                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x2e4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_MIN_SUPPORTED_MODE_OFFS                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2e4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_MIN_SUPPORTED_MODE_RMSK                                                                   0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_MIN_SUPPORTED_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_MIN_SUPPORTED_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_MIN_SUPPORTED_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_MIN_SUPPORTED_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_MIN_SUPPORTED_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_MIN_SUPPORTED_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_MIN_SUPPORTED_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_MIN_SUPPORTED_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_MIN_SUPPORTED_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_MIN_SUPPORTED_MODE_NSP_CX_MODE_BMSK                                                       0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_MIN_SUPPORTED_MODE_NSP_CX_MODE_SHFT                                                         0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_CURR_MODE_SEL_ADDR                                                                 (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x2e8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_CURR_MODE_SEL_OFFS                                                                 (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2e8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_CURR_MODE_SEL_RMSK                                                                        0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_CURR_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_CURR_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_CURR_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_CURR_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_CURR_MODE_SEL_NSP_CX_CURR_MODE_BMSK                                                       0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_CURR_MODE_SEL_NSP_CX_CURR_MODE_SHFT                                                         0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PREV_MODE_SEL_ADDR                                                                 (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x2ecu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PREV_MODE_SEL_OFFS                                                                 (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2ecu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PREV_MODE_SEL_RMSK                                                                        0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PREV_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PREV_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PREV_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PREV_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PREV_MODE_SEL_NSP_CX_PREV_MODE_BMSK                                                       0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PREV_MODE_SEL_NSP_CX_PREV_MODE_SHFT                                                         0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_RAIL_STATUS_ADDR                                                                   (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x2f0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_RAIL_STATUS_OFFS                                                                   (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2f0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_RAIL_STATUS_RMSK                                                                          0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_RAIL_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_RAIL_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_RAIL_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_RAIL_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_RAIL_STATUS_NSP_CX_RAIL_IS_UP_BMSK                                                        0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_RAIL_STATUS_NSP_CX_RAIL_IS_UP_SHFT                                                          0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PC_MODE_ADDR                                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x2f4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PC_MODE_OFFS                                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2f4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PC_MODE_RMSK                                                                              0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PC_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PC_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PC_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PC_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PC_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PC_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PC_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PC_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PC_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PC_MODE_NSP_CX_PC_MODE_BMSK                                                               0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PC_MODE_NSP_CX_PC_MODE_SHFT                                                                 0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP_CX_ADDR                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x2f8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP_CX_OFFS                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2f8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP_CX_RMSK                                                      0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP_CX_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP_CX_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP_CX_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP_CX_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP_CX_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP_CX_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP_CX_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP_CX_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP_CX_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP_CX_POST_COLLAPSE_CNTR_VAL_NSP_CX_BMSK                        0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP_CX_POST_COLLAPSE_CNTR_VAL_NSP_CX_SHFT                             0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PU_INIT_MODE_ADDR                                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x2fcu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PU_INIT_MODE_OFFS                                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2fcu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PU_INIT_MODE_RMSK                                                                         0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PU_INIT_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PU_INIT_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PU_INIT_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PU_INIT_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PU_INIT_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PU_INIT_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PU_INIT_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PU_INIT_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PU_INIT_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PU_INIT_MODE_NSP_CX_PU_INIT_MODE_BMSK                                                     0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP_CX_PU_INIT_MODE_NSP_CX_PU_INIT_MODE_SHFT                                                       0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_CPRF_ENABLE_ADDR                                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x300u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_CPRF_ENABLE_OFFS                                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x300u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_CPRF_ENABLE_RMSK                                                                         0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_CPRF_ENABLE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_CPRF_ENABLE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_CPRF_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_CPRF_ENABLE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_CPRF_ENABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_CPRF_ENABLE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_CPRF_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_CPRF_ENABLE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_CPRF_ENABLE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_CPRF_ENABLE_NSP2_CX_ENABLE_BMSK                                                          0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_CPRF_ENABLE_NSP2_CX_ENABLE_SHFT                                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_MIN_SUPPORTED_MODE_ADDR                                                           (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x304u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_MIN_SUPPORTED_MODE_OFFS                                                           (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x304u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_MIN_SUPPORTED_MODE_RMSK                                                                  0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_MIN_SUPPORTED_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_MIN_SUPPORTED_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_MIN_SUPPORTED_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_MIN_SUPPORTED_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_MIN_SUPPORTED_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_MIN_SUPPORTED_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_MIN_SUPPORTED_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_MIN_SUPPORTED_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_MIN_SUPPORTED_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_MIN_SUPPORTED_MODE_NSP2_CX_MODE_BMSK                                                     0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_MIN_SUPPORTED_MODE_NSP2_CX_MODE_SHFT                                                       0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_CURR_MODE_SEL_ADDR                                                                (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x308u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_CURR_MODE_SEL_OFFS                                                                (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x308u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_CURR_MODE_SEL_RMSK                                                                       0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_CURR_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_CURR_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_CURR_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_CURR_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_CURR_MODE_SEL_NSP2_CX_CURR_MODE_BMSK                                                     0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_CURR_MODE_SEL_NSP2_CX_CURR_MODE_SHFT                                                       0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PREV_MODE_SEL_ADDR                                                                (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x30cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PREV_MODE_SEL_OFFS                                                                (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x30cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PREV_MODE_SEL_RMSK                                                                       0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PREV_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PREV_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PREV_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PREV_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PREV_MODE_SEL_NSP2_CX_PREV_MODE_BMSK                                                     0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PREV_MODE_SEL_NSP2_CX_PREV_MODE_SHFT                                                       0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_RAIL_STATUS_ADDR                                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x310u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_RAIL_STATUS_OFFS                                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x310u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_RAIL_STATUS_RMSK                                                                         0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_RAIL_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_RAIL_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_RAIL_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_RAIL_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_RAIL_STATUS_NSP2_CX_RAIL_IS_UP_BMSK                                                      0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_RAIL_STATUS_NSP2_CX_RAIL_IS_UP_SHFT                                                        0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PC_MODE_ADDR                                                                      (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x314u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PC_MODE_OFFS                                                                      (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x314u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PC_MODE_RMSK                                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PC_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PC_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PC_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PC_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PC_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PC_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PC_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PC_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PC_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PC_MODE_NSP2_CX_PC_MODE_BMSK                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PC_MODE_NSP2_CX_PC_MODE_SHFT                                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP2_CX_ADDR                                                 (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x318u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP2_CX_OFFS                                                 (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x318u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP2_CX_RMSK                                                     0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP2_CX_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP2_CX_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP2_CX_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP2_CX_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP2_CX_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP2_CX_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP2_CX_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP2_CX_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP2_CX_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP2_CX_POST_COLLAPSE_CNTR_VAL_NSP2_CX_BMSK                      0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP2_CX_POST_COLLAPSE_CNTR_VAL_NSP2_CX_SHFT                           0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PU_INIT_MODE_ADDR                                                                 (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x31cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PU_INIT_MODE_OFFS                                                                 (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x31cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PU_INIT_MODE_RMSK                                                                        0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PU_INIT_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PU_INIT_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PU_INIT_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PU_INIT_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PU_INIT_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PU_INIT_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PU_INIT_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PU_INIT_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PU_INIT_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PU_INIT_MODE_NSP2_CX_PU_INIT_MODE_BMSK                                                   0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_NSP2_CX_PU_INIT_MODE_NSP2_CX_PU_INIT_MODE_SHFT                                                     0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_CPRF_ENABLE_ADDR                                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x320u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_CPRF_ENABLE_OFFS                                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x320u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_CPRF_ENABLE_RMSK                                                                            0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_CPRF_ENABLE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_CPRF_ENABLE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_CPRF_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_CPRF_ENABLE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_CPRF_ENABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_CPRF_ENABLE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_CPRF_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_CPRF_ENABLE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_CPRF_ENABLE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_CPRF_ENABLE_MMCX_ENABLE_BMSK                                                                0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_CPRF_ENABLE_MMCX_ENABLE_SHFT                                                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_MIN_SUPPORTED_MODE_ADDR                                                              (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x324u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_MIN_SUPPORTED_MODE_OFFS                                                              (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x324u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_MIN_SUPPORTED_MODE_RMSK                                                                     0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_MIN_SUPPORTED_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_MIN_SUPPORTED_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_MIN_SUPPORTED_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_MIN_SUPPORTED_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_MIN_SUPPORTED_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_MIN_SUPPORTED_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_MIN_SUPPORTED_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_MIN_SUPPORTED_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_MIN_SUPPORTED_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_MIN_SUPPORTED_MODE_MMCX_MODE_BMSK                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_MIN_SUPPORTED_MODE_MMCX_MODE_SHFT                                                             0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_CURR_MODE_SEL_ADDR                                                                   (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x328u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_CURR_MODE_SEL_OFFS                                                                   (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x328u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_CURR_MODE_SEL_RMSK                                                                          0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_CURR_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_CURR_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_CURR_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_CURR_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_CURR_MODE_SEL_MMCX_CURR_MODE_BMSK                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_CURR_MODE_SEL_MMCX_CURR_MODE_SHFT                                                             0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PREV_MODE_SEL_ADDR                                                                   (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x32cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PREV_MODE_SEL_OFFS                                                                   (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x32cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PREV_MODE_SEL_RMSK                                                                          0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PREV_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PREV_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PREV_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PREV_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PREV_MODE_SEL_MMCX_PREV_MODE_BMSK                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PREV_MODE_SEL_MMCX_PREV_MODE_SHFT                                                             0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_RAIL_STATUS_ADDR                                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x330u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_RAIL_STATUS_OFFS                                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x330u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_RAIL_STATUS_RMSK                                                                            0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_RAIL_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_RAIL_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_RAIL_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_RAIL_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_RAIL_STATUS_MMCX_RAIL_IS_UP_BMSK                                                            0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_RAIL_STATUS_MMCX_RAIL_IS_UP_SHFT                                                              0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PC_MODE_ADDR                                                                         (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x334u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PC_MODE_OFFS                                                                         (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x334u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PC_MODE_RMSK                                                                                0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PC_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PC_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PC_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PC_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PC_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PC_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PC_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PC_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PC_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PC_MODE_MMCX_PC_MODE_BMSK                                                                   0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PC_MODE_MMCX_PC_MODE_SHFT                                                                     0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MMCX_ADDR                                                    (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x338u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MMCX_OFFS                                                    (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x338u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MMCX_RMSK                                                        0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MMCX_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MMCX_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MMCX_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MMCX_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MMCX_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MMCX_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MMCX_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MMCX_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MMCX_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MMCX_POST_COLLAPSE_CNTR_VAL_MMCX_BMSK                            0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MMCX_POST_COLLAPSE_CNTR_VAL_MMCX_SHFT                                 0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PU_INIT_MODE_ADDR                                                                    (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x33cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PU_INIT_MODE_OFFS                                                                    (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x33cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PU_INIT_MODE_RMSK                                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PU_INIT_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PU_INIT_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PU_INIT_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PU_INIT_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PU_INIT_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PU_INIT_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PU_INIT_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PU_INIT_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PU_INIT_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PU_INIT_MODE_MMCX_PU_INIT_MODE_BMSK                                                         0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MMCX_PU_INIT_MODE_MMCX_PU_INIT_MODE_SHFT                                                           0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_CPRF_ENABLE_ADDR                                                                      (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x340u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_CPRF_ENABLE_OFFS                                                                      (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x340u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_CPRF_ENABLE_RMSK                                                                             0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_CPRF_ENABLE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_CPRF_ENABLE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_CPRF_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_CPRF_ENABLE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_CPRF_ENABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_CPRF_ENABLE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_CPRF_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_CPRF_ENABLE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_CPRF_ENABLE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_CPRF_ENABLE_MXC_ENABLE_BMSK                                                                  0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_CPRF_ENABLE_MXC_ENABLE_SHFT                                                                    0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_MIN_SUPPORTED_MODE_ADDR                                                               (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x344u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_MIN_SUPPORTED_MODE_OFFS                                                               (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x344u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_MIN_SUPPORTED_MODE_RMSK                                                                      0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_MIN_SUPPORTED_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_MIN_SUPPORTED_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_MIN_SUPPORTED_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_MIN_SUPPORTED_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_MIN_SUPPORTED_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_MIN_SUPPORTED_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_MIN_SUPPORTED_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_MIN_SUPPORTED_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_MIN_SUPPORTED_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_MIN_SUPPORTED_MODE_MXC_MODE_BMSK                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_MIN_SUPPORTED_MODE_MXC_MODE_SHFT                                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_CURR_MODE_SEL_ADDR                                                                    (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x348u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_CURR_MODE_SEL_OFFS                                                                    (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x348u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_CURR_MODE_SEL_RMSK                                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_CURR_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_CURR_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_CURR_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_CURR_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_CURR_MODE_SEL_MXC_CURR_MODE_BMSK                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_CURR_MODE_SEL_MXC_CURR_MODE_SHFT                                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PREV_MODE_SEL_ADDR                                                                    (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x34cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PREV_MODE_SEL_OFFS                                                                    (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x34cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PREV_MODE_SEL_RMSK                                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PREV_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PREV_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PREV_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PREV_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PREV_MODE_SEL_MXC_PREV_MODE_BMSK                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PREV_MODE_SEL_MXC_PREV_MODE_SHFT                                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_RAIL_STATUS_ADDR                                                                      (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x350u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_RAIL_STATUS_OFFS                                                                      (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x350u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_RAIL_STATUS_RMSK                                                                             0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_RAIL_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_RAIL_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_RAIL_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_RAIL_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_RAIL_STATUS_MXC_RAIL_IS_UP_BMSK                                                              0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_RAIL_STATUS_MXC_RAIL_IS_UP_SHFT                                                                0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PC_MODE_ADDR                                                                          (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x354u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PC_MODE_OFFS                                                                          (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x354u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PC_MODE_RMSK                                                                                 0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PC_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PC_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PC_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PC_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PC_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PC_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PC_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PC_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PC_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PC_MODE_MXC_PC_MODE_BMSK                                                                     0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PC_MODE_MXC_PC_MODE_SHFT                                                                       0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXC_ADDR                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x358u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXC_OFFS                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x358u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXC_RMSK                                                         0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXC_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXC_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXC_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXC_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXC_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXC_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXC_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXC_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXC_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXC_POST_COLLAPSE_CNTR_VAL_MXC_BMSK                              0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXC_POST_COLLAPSE_CNTR_VAL_MXC_SHFT                                   0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PU_INIT_MODE_ADDR                                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x35cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PU_INIT_MODE_OFFS                                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x35cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PU_INIT_MODE_RMSK                                                                            0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PU_INIT_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PU_INIT_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PU_INIT_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PU_INIT_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PU_INIT_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PU_INIT_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PU_INIT_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PU_INIT_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PU_INIT_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PU_INIT_MODE_MXC_PU_INIT_MODE_BMSK                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_MXC_PU_INIT_MODE_MXC_PU_INIT_MODE_SHFT                                                             0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_CPRH_ENABLE_ADDR                                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x360u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_CPRH_ENABLE_OFFS                                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x360u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_CPRH_ENABLE_RMSK                                                                            0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_CPRH_ENABLE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_CPRH_ENABLE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_CPRH_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_CPRH_ENABLE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_CPRH_ENABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_CPRH_ENABLE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_CPRH_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_CPRH_ENABLE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_CPRH_ENABLE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_CPRH_ENABLE_APC0_ENABLE_BMSK                                                                0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_CPRH_ENABLE_APC0_ENABLE_SHFT                                                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_MIN_SUPPORTED_MODE_ADDR                                                              (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x364u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_MIN_SUPPORTED_MODE_OFFS                                                              (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x364u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_MIN_SUPPORTED_MODE_RMSK                                                                   0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_MIN_SUPPORTED_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_MIN_SUPPORTED_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_MIN_SUPPORTED_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_MIN_SUPPORTED_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_MIN_SUPPORTED_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_MIN_SUPPORTED_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_MIN_SUPPORTED_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_MIN_SUPPORTED_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_MIN_SUPPORTED_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_MIN_SUPPORTED_MODE_APC0_MODE_BMSK                                                         0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_MIN_SUPPORTED_MODE_APC0_MODE_SHFT                                                             0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_CURR_MODE_SEL_ADDR                                                                   (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x368u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_CURR_MODE_SEL_OFFS                                                                   (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x368u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_CURR_MODE_SEL_RMSK                                                                        0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_CURR_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_CURR_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_CURR_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_CURR_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_CURR_MODE_SEL_APC0_CURR_MODE_BMSK                                                         0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_CURR_MODE_SEL_APC0_CURR_MODE_SHFT                                                             0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PREV_MODE_SEL_ADDR                                                                   (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x36cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PREV_MODE_SEL_OFFS                                                                   (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x36cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PREV_MODE_SEL_RMSK                                                                        0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PREV_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PREV_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PREV_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PREV_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PREV_MODE_SEL_APC0_PREV_MODE_BMSK                                                         0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PREV_MODE_SEL_APC0_PREV_MODE_SHFT                                                             0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_RAIL_STATUS_ADDR                                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x370u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_RAIL_STATUS_OFFS                                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x370u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_RAIL_STATUS_RMSK                                                                            0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_RAIL_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_RAIL_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_RAIL_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_RAIL_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_RAIL_STATUS_APC0_RAIL_IS_UP_BMSK                                                            0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_RAIL_STATUS_APC0_RAIL_IS_UP_SHFT                                                              0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PC_MODE_ADDR                                                                         (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x374u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PC_MODE_OFFS                                                                         (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x374u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PC_MODE_RMSK                                                                              0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PC_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PC_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PC_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PC_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PC_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PC_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PC_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PC_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PC_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PC_MODE_APC0_PC_MODE_BMSK                                                                 0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PC_MODE_APC0_PC_MODE_SHFT                                                                     0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PU_INIT_MODE_ADDR                                                                    (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x378u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PU_INIT_MODE_OFFS                                                                    (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x378u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PU_INIT_MODE_RMSK                                                                         0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PU_INIT_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PU_INIT_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PU_INIT_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PU_INIT_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PU_INIT_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PU_INIT_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PU_INIT_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PU_INIT_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PU_INIT_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PU_INIT_MODE_APC0_PU_INIT_MODE_BMSK                                                       0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_PU_INIT_MODE_APC0_PU_INIT_MODE_SHFT                                                           0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_CPRH_ENABLE_ADDR                                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x390u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_CPRH_ENABLE_OFFS                                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x390u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_CPRH_ENABLE_RMSK                                                                            0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_CPRH_ENABLE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_CPRH_ENABLE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_CPRH_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_CPRH_ENABLE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_CPRH_ENABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_CPRH_ENABLE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_CPRH_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_CPRH_ENABLE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_CPRH_ENABLE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_CPRH_ENABLE_APC1_ENABLE_BMSK                                                                0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_CPRH_ENABLE_APC1_ENABLE_SHFT                                                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_MIN_SUPPORTED_MODE_ADDR                                                              (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x394u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_MIN_SUPPORTED_MODE_OFFS                                                              (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x394u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_MIN_SUPPORTED_MODE_RMSK                                                                   0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_MIN_SUPPORTED_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_MIN_SUPPORTED_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_MIN_SUPPORTED_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_MIN_SUPPORTED_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_MIN_SUPPORTED_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_MIN_SUPPORTED_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_MIN_SUPPORTED_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_MIN_SUPPORTED_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_MIN_SUPPORTED_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_MIN_SUPPORTED_MODE_APC1_MODE_BMSK                                                         0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_MIN_SUPPORTED_MODE_APC1_MODE_SHFT                                                             0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_CURR_MODE_SEL_ADDR                                                                   (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x39cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_CURR_MODE_SEL_OFFS                                                                   (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x39cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_CURR_MODE_SEL_RMSK                                                                        0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_CURR_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_CURR_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_CURR_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_CURR_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_CURR_MODE_SEL_APC1_CURR_MODE_BMSK                                                         0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_CURR_MODE_SEL_APC1_CURR_MODE_SHFT                                                             0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PREV_MODE_SEL_ADDR                                                                   (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x3a0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PREV_MODE_SEL_OFFS                                                                   (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x3a0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PREV_MODE_SEL_RMSK                                                                        0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PREV_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PREV_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PREV_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PREV_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PREV_MODE_SEL_APC1_PREV_MODE_BMSK                                                         0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PREV_MODE_SEL_APC1_PREV_MODE_SHFT                                                             0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_RAIL_STATUS_ADDR                                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x3a4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_RAIL_STATUS_OFFS                                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x3a4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_RAIL_STATUS_RMSK                                                                            0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_RAIL_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_RAIL_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_RAIL_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_RAIL_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_RAIL_STATUS_APC1_RAIL_IS_UP_BMSK                                                            0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_RAIL_STATUS_APC1_RAIL_IS_UP_SHFT                                                              0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PC_MODE_ADDR                                                                         (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x3a8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PC_MODE_OFFS                                                                         (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x3a8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PC_MODE_RMSK                                                                              0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PC_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PC_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PC_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PC_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PC_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PC_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PC_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PC_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PC_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PC_MODE_APC1_PC_MODE_BMSK                                                                 0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PC_MODE_APC1_PC_MODE_SHFT                                                                     0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PU_INIT_MODE_ADDR                                                                    (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x3acu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PU_INIT_MODE_OFFS                                                                    (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x3acu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PU_INIT_MODE_RMSK                                                                         0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PU_INIT_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PU_INIT_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PU_INIT_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PU_INIT_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PU_INIT_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PU_INIT_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PU_INIT_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PU_INIT_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PU_INIT_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PU_INIT_MODE_APC1_PU_INIT_MODE_BMSK                                                       0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_PU_INIT_MODE_APC1_PU_INIT_MODE_SHFT                                                           0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SB_WM_EN_ADDR                                                                      (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x3c0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SB_WM_EN_OFFS                                                                      (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x3c0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SB_WM_EN_RMSK                                                                         0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SB_WM_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SB_WM_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SB_WM_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SB_WM_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SB_WM_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SB_WM_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SB_WM_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SB_WM_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SB_WM_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SB_WM_EN_VSENSE_SENSOR_SB_WM_EN_BMSK                                                  0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SB_WM_EN_VSENSE_SENSOR_SB_WM_EN_SHFT                                                        0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_ALARM_EN_ADDR                                                                      (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x3c4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_ALARM_EN_OFFS                                                                      (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x3c4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_ALARM_EN_RMSK                                                                         0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_ALARM_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_ALARM_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_ALARM_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_ALARM_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_ALARM_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_ALARM_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_ALARM_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_ALARM_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_ALARM_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_ALARM_EN_VSENSE_SENSOR_ALARM_EN_BMSK                                                  0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_ALARM_EN_VSENSE_SENSOR_ALARM_EN_SHFT                                                        0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_ADDR(n)                                                        (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0X3D0 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_OFFS(n)                                                        (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0X3D0 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_RMSK                                                               0x3fffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_MAXn                                                                   18u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_ADDR(n),val)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_ADDR(n),mask,val,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_INI(n))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_CLK_EN_VAL_BMSK                                       0x2000u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_CLK_EN_VAL_SHFT                                           13u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_POWER_DOWN_VAL_BMSK                                   0x1000u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_POWER_DOWN_VAL_SHFT                                       12u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_VS_ARES_VAL_BMSK                                       0x800u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_VS_ARES_VAL_SHFT                                          11u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_CLAMP_EN_OUT_VAL_BMSK                                  0x400u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_CLAMP_EN_OUT_VAL_SHFT                                     10u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_PLL_LOCK_DET_VAL_BMSK                                  0x200u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_PLL_LOCK_DET_VAL_SHFT                                      9u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_SUPPORTED_MODE_VAL_BMSK                                0x100u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_SUPPORTED_MODE_VAL_SHFT                                    8u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_RAIL_IS_UP_VAL_BMSK                                     0x80u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_RAIL_IS_UP_VAL_SHFT                                        7u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_CLK_EN_BMSK                                             0x40u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_CLK_EN_SHFT                                                6u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_POWER_DOWN_BMSK                                         0x20u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_POWER_DOWN_SHFT                                            5u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_VS_ARES_BMSK                                            0x10u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_VS_ARES_SHFT                                               4u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_CLAMP_EN_OUT_BMSK                                        0x8u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_CLAMP_EN_OUT_SHFT                                          3u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_PLL_LOCK_DET_BMSK                                        0x4u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_PLL_LOCK_DET_SHFT                                          2u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_SUPPORTED_MODE_BMSK                                      0x2u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_SUPPORTED_MODE_SHFT                                        1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_RAIL_IS_UP_BMSK                                          0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_RAIL_IS_UP_SHFT                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA0_ADDR(n)                                                             (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0X424 + (0x8*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA0_OFFS(n)                                                             (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0X424 + (0x8*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA0_RMSK                                                                0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA0_MAXn                                                                        16u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA0_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA0_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA0_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA0_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA0_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA0_SENSOR_MAX_DATA_RD1_BMSK                                            0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA0_SENSOR_MAX_DATA_RD1_SHFT                                                    24u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA0_SENSOR_MIN_DATA_RD1_BMSK                                              0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA0_SENSOR_MIN_DATA_RD1_SHFT                                                    16u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA0_SENSOR_MAX_DATA_RD0_BMSK                                                0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA0_SENSOR_MAX_DATA_RD0_SHFT                                                     8u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA0_SENSOR_MIN_DATA_RD0_BMSK                                                  0xffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA0_SENSOR_MIN_DATA_RD0_SHFT                                                     0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA1_ADDR(n)                                                             (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0X428 + (0x8*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA1_OFFS(n)                                                             (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0X428 + (0x8*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA1_RMSK                                                                0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA1_MAXn                                                                        16u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA1_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA1_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA1_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA1_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA1_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA1_SENSOR_MAX_DATA_RD3_BMSK                                            0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA1_SENSOR_MAX_DATA_RD3_SHFT                                                    24u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA1_SENSOR_MIN_DATA_RD3_BMSK                                              0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA1_SENSOR_MIN_DATA_RD3_SHFT                                                    16u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA1_SENSOR_MAX_DATA_RD2_BMSK                                                0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA1_SENSOR_MAX_DATA_RD2_SHFT                                                     8u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA1_SENSOR_MIN_DATA_RD2_BMSK                                                  0xffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_DATA1_SENSOR_MIN_DATA_RD2_SHFT                                                     0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA0_ADDR                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x4d0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA0_OFFS                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x4d0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA0_RMSK                                                            0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA0_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA0_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA0_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA0_SENSOR_APC0_MAX_DATA_RD1_BMSK                                   0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA0_SENSOR_APC0_MAX_DATA_RD1_SHFT                                           24u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA0_SENSOR_APC0_MIN_DATA_RD1_BMSK                                     0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA0_SENSOR_APC0_MIN_DATA_RD1_SHFT                                           16u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA0_SENSOR_APC0_MAX_DATA_RD0_BMSK                                       0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA0_SENSOR_APC0_MAX_DATA_RD0_SHFT                                            8u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA0_SENSOR_APC0_MIN_DATA_RD0_BMSK                                         0xffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA0_SENSOR_APC0_MIN_DATA_RD0_SHFT                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA1_ADDR                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x4d4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA1_OFFS                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x4d4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA1_RMSK                                                            0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA1_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA1_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA1_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA1_SENSOR_APC0_MAX_DATA_RD3_BMSK                                   0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA1_SENSOR_APC0_MAX_DATA_RD3_SHFT                                           24u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA1_SENSOR_APC0_MIN_DATA_RD3_BMSK                                     0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA1_SENSOR_APC0_MIN_DATA_RD3_SHFT                                           16u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA1_SENSOR_APC0_MAX_DATA_RD2_BMSK                                       0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA1_SENSOR_APC0_MAX_DATA_RD2_SHFT                                            8u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA1_SENSOR_APC0_MIN_DATA_RD2_BMSK                                         0xffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA1_SENSOR_APC0_MIN_DATA_RD2_SHFT                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA2_ADDR                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x4d8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA2_OFFS                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x4d8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA2_RMSK                                                            0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA2_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA2_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA2_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA2_SENSOR_APC0_MAX_DATA_RD5_BMSK                                   0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA2_SENSOR_APC0_MAX_DATA_RD5_SHFT                                           24u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA2_SENSOR_APC0_MIN_DATA_RD5_BMSK                                     0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA2_SENSOR_APC0_MIN_DATA_RD5_SHFT                                           16u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA2_SENSOR_APC0_MAX_DATA_RD4_BMSK                                       0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA2_SENSOR_APC0_MAX_DATA_RD4_SHFT                                            8u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA2_SENSOR_APC0_MIN_DATA_RD4_BMSK                                         0xffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA2_SENSOR_APC0_MIN_DATA_RD4_SHFT                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA3_ADDR                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x4dcu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA3_OFFS                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x4dcu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA3_RMSK                                                            0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA3_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA3_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA3_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA3_SENSOR_APC0_MAX_DATA_RD7_BMSK                                   0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA3_SENSOR_APC0_MAX_DATA_RD7_SHFT                                           24u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA3_SENSOR_APC0_MIN_DATA_RD7_BMSK                                     0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA3_SENSOR_APC0_MIN_DATA_RD7_SHFT                                           16u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA3_SENSOR_APC0_MAX_DATA_RD6_BMSK                                       0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA3_SENSOR_APC0_MAX_DATA_RD6_SHFT                                            8u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA3_SENSOR_APC0_MIN_DATA_RD6_BMSK                                         0xffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA3_SENSOR_APC0_MIN_DATA_RD6_SHFT                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA4_ADDR                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x4e0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA4_OFFS                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x4e0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA4_RMSK                                                            0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA4_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA4_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA4_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA4_SENSOR_APC0_MAX_DATA_RD9_BMSK                                   0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA4_SENSOR_APC0_MAX_DATA_RD9_SHFT                                           24u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA4_SENSOR_APC0_MIN_DATA_RD9_BMSK                                     0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA4_SENSOR_APC0_MIN_DATA_RD9_SHFT                                           16u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA4_SENSOR_APC0_MAX_DATA_RD8_BMSK                                       0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA4_SENSOR_APC0_MAX_DATA_RD8_SHFT                                            8u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA4_SENSOR_APC0_MIN_DATA_RD8_BMSK                                         0xffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_DATA4_SENSOR_APC0_MIN_DATA_RD8_SHFT                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA0_ADDR                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x4e4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA0_OFFS                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x4e4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA0_RMSK                                                            0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA0_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA0_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA0_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA0_SENSOR_APC1_MAX_DATA_RD1_BMSK                                   0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA0_SENSOR_APC1_MAX_DATA_RD1_SHFT                                           24u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA0_SENSOR_APC1_MIN_DATA_RD1_BMSK                                     0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA0_SENSOR_APC1_MIN_DATA_RD1_SHFT                                           16u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA0_SENSOR_APC1_MAX_DATA_RD0_BMSK                                       0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA0_SENSOR_APC1_MAX_DATA_RD0_SHFT                                            8u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA0_SENSOR_APC1_MIN_DATA_RD0_BMSK                                         0xffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA0_SENSOR_APC1_MIN_DATA_RD0_SHFT                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA1_ADDR                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x4e8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA1_OFFS                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x4e8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA1_RMSK                                                            0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA1_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA1_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA1_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA1_SENSOR_APC1_MAX_DATA_RD3_BMSK                                   0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA1_SENSOR_APC1_MAX_DATA_RD3_SHFT                                           24u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA1_SENSOR_APC1_MIN_DATA_RD3_BMSK                                     0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA1_SENSOR_APC1_MIN_DATA_RD3_SHFT                                           16u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA1_SENSOR_APC1_MAX_DATA_RD2_BMSK                                       0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA1_SENSOR_APC1_MAX_DATA_RD2_SHFT                                            8u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA1_SENSOR_APC1_MIN_DATA_RD2_BMSK                                         0xffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA1_SENSOR_APC1_MIN_DATA_RD2_SHFT                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA2_ADDR                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x4ecu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA2_OFFS                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x4ecu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA2_RMSK                                                            0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA2_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA2_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA2_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA2_SENSOR_APC1_MAX_DATA_RD5_BMSK                                   0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA2_SENSOR_APC1_MAX_DATA_RD5_SHFT                                           24u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA2_SENSOR_APC1_MIN_DATA_RD5_BMSK                                     0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA2_SENSOR_APC1_MIN_DATA_RD5_SHFT                                           16u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA2_SENSOR_APC1_MAX_DATA_RD4_BMSK                                       0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA2_SENSOR_APC1_MAX_DATA_RD4_SHFT                                            8u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA2_SENSOR_APC1_MIN_DATA_RD4_BMSK                                         0xffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA2_SENSOR_APC1_MIN_DATA_RD4_SHFT                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA3_ADDR                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x4f0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA3_OFFS                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x4f0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA3_RMSK                                                            0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA3_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA3_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA3_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA3_SENSOR_APC1_MAX_DATA_RD7_BMSK                                   0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA3_SENSOR_APC1_MAX_DATA_RD7_SHFT                                           24u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA3_SENSOR_APC1_MIN_DATA_RD7_BMSK                                     0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA3_SENSOR_APC1_MIN_DATA_RD7_SHFT                                           16u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA3_SENSOR_APC1_MAX_DATA_RD6_BMSK                                       0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA3_SENSOR_APC1_MAX_DATA_RD6_SHFT                                            8u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA3_SENSOR_APC1_MIN_DATA_RD6_BMSK                                         0xffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA3_SENSOR_APC1_MIN_DATA_RD6_SHFT                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA4_ADDR                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x4f4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA4_OFFS                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x4f4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA4_RMSK                                                            0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA4_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA4_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA4_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA4_SENSOR_APC1_MAX_DATA_RD9_BMSK                                   0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA4_SENSOR_APC1_MAX_DATA_RD9_SHFT                                           24u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA4_SENSOR_APC1_MIN_DATA_RD9_BMSK                                     0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA4_SENSOR_APC1_MIN_DATA_RD9_SHFT                                           16u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA4_SENSOR_APC1_MAX_DATA_RD8_BMSK                                       0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA4_SENSOR_APC1_MAX_DATA_RD8_SHFT                                            8u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA4_SENSOR_APC1_MIN_DATA_RD8_BMSK                                         0xffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_DATA4_SENSOR_APC1_MIN_DATA_RD8_SHFT                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_MODE_CHANGE_TMR_CNT_ADDR                                                             (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x4f8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_MODE_CHANGE_TMR_CNT_OFFS                                                             (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x4f8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_MODE_CHANGE_TMR_CNT_RMSK                                                                   0x3fu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_MODE_CHANGE_TMR_CNT_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_MODE_CHANGE_TMR_CNT_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_MODE_CHANGE_TMR_CNT_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_MODE_CHANGE_TMR_CNT_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_MODE_CHANGE_TMR_CNT_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_MODE_CHANGE_TMR_CNT_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_MODE_CHANGE_TMR_CNT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_MODE_CHANGE_TMR_CNT_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_MODE_CHANGE_TMR_CNT_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_MODE_CHANGE_TMR_CNT_APC0_NUM_CYCLES4MODE_CHANGE_BMSK                                       0x3fu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC0_MODE_CHANGE_TMR_CNT_APC0_NUM_CYCLES4MODE_CHANGE_SHFT                                          0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_MODE_CHANGE_TMR_CNT_ADDR                                                             (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x4fcu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_MODE_CHANGE_TMR_CNT_OFFS                                                             (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x4fcu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_MODE_CHANGE_TMR_CNT_RMSK                                                                   0x3fu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_MODE_CHANGE_TMR_CNT_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_MODE_CHANGE_TMR_CNT_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_MODE_CHANGE_TMR_CNT_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_MODE_CHANGE_TMR_CNT_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_MODE_CHANGE_TMR_CNT_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_MODE_CHANGE_TMR_CNT_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_MODE_CHANGE_TMR_CNT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_MODE_CHANGE_TMR_CNT_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_MODE_CHANGE_TMR_CNT_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_MODE_CHANGE_TMR_CNT_APC1_NUM_CYCLES4MODE_CHANGE_BMSK                                       0x3fu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_APC1_MODE_CHANGE_TMR_CNT_APC1_NUM_CYCLES4MODE_CHANGE_SHFT                                          0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CLR_MINMAX_DATA_ADDR                                                               (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x504u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CLR_MINMAX_DATA_OFFS                                                               (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x504u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CLR_MINMAX_DATA_RMSK                                                                  0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CLR_MINMAX_DATA_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CLR_MINMAX_DATA_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CLR_MINMAX_DATA_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CLR_MINMAX_DATA_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CLR_MINMAX_DATA_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CLR_MINMAX_DATA_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CLR_MINMAX_DATA_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CLR_MINMAX_DATA_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CLR_MINMAX_DATA_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CLR_MINMAX_DATA_VSENSE_SENSOR_CLR_MINMAX_DATA_BMSK                                    0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CLR_MINMAX_DATA_VSENSE_SENSOR_CLR_MINMAX_DATA_SHFT                                          0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_RD_EN_ADDR                                                               (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x508u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_RD_EN_OFFS                                                               (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x508u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_RD_EN_RMSK                                                                  0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_RD_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_RD_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_RD_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_RD_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_RD_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_RD_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_RD_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_RD_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_RD_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_RD_EN_VSENSE_SENSOR_FIFO_DATA_RD_EN_BMSK                                    0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_FIFO_DATA_RD_EN_VSENSE_SENSOR_FIFO_DATA_RD_EN_SHFT                                          0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_RESET_STATE_STATUS_ADDR                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x50cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_RESET_STATE_STATUS_OFFS                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x50cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_RESET_STATE_STATUS_RMSK                                                               0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_RESET_STATE_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_RESET_STATE_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_RESET_STATE_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_RESET_STATE_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_RESET_STATE_STATUS_VSENSE_SENSOR_RESET_STATE_STATUS_BMSK                              0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_RESET_STATE_STATUS_VSENSE_SENSOR_RESET_STATE_STATUS_SHFT                                    0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CLK_EN_STATUS_ADDR                                                                 (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x510u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CLK_EN_STATUS_OFFS                                                                 (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x510u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CLK_EN_STATUS_RMSK                                                                   0x37fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CLK_EN_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CLK_EN_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CLK_EN_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CLK_EN_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CLK_EN_STATUS_VSENSE_CNTRL_AHB_CLK_EN_STATUS_BMSK                                    0x200000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CLK_EN_STATUS_VSENSE_CNTRL_AHB_CLK_EN_STATUS_SHFT                                          21u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CLK_EN_STATUS_VSENSE_CNTRL_CLK_EN_STATUS_BMSK                                        0x100000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CLK_EN_STATUS_VSENSE_CNTRL_CLK_EN_STATUS_SHFT                                              20u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CLK_EN_STATUS_VSENSE_SENSOR_CLK_EN_STATUS_BMSK                                        0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CLK_EN_STATUS_VSENSE_SENSOR_CLK_EN_STATUS_SHFT                                              0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_RCDRW_STATUS_ADDR                                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x514u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_RCDRW_STATUS_OFFS                                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x514u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_RCDRW_STATUS_RMSK                                                                      0x3fffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_RCDRW_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_RCDRW_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_RCDRW_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_RCDRW_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_RCDRW_STATUS_VSENSE_CHAIN_RCDRW_STATUS_BMSK                                            0x3fffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_RCDRW_STATUS_VSENSE_CHAIN_RCDRW_STATUS_SHFT                                                 0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_EN_HW_DCVS_ADDR                                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x518u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_EN_HW_DCVS_OFFS                                                                     (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x518u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_EN_HW_DCVS_RMSK                                                                        0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_EN_HW_DCVS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_EN_HW_DCVS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_EN_HW_DCVS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_EN_HW_DCVS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_EN_HW_DCVS_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_EN_HW_DCVS_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_EN_HW_DCVS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_EN_HW_DCVS_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_EN_HW_DCVS_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_EN_HW_DCVS_EN_HW_DCVS_BMSK                                                             0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_EN_HW_DCVS_EN_HW_DCVS_SHFT                                                                   0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_MODE_DATA_ADDR(n)                                                         (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0X51C + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_MODE_DATA_OFFS(n)                                                         (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0X51C + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_MODE_DATA_RMSK                                                                0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_MODE_DATA_MAXn                                                                    16u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_MODE_DATA_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_MODE_DATA_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_MODE_DATA_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_MODE_DATA_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_MODE_DATA_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_MODE_DATA_SENSOR_MODE_DATA_RD3_BMSK                                           0xf000u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_MODE_DATA_SENSOR_MODE_DATA_RD3_SHFT                                               12u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_MODE_DATA_SENSOR_MODE_DATA_RD2_BMSK                                            0xf00u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_MODE_DATA_SENSOR_MODE_DATA_RD2_SHFT                                                8u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_MODE_DATA_SENSOR_MODE_DATA_RD1_BMSK                                             0xf0u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_MODE_DATA_SENSOR_MODE_DATA_RD1_SHFT                                                4u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_MODE_DATA_SENSOR_MODE_DATA_RD0_BMSK                                              0xfu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MAX_MIN_MODE_DATA_SENSOR_MODE_DATA_RD0_SHFT                                                0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA0_ADDR                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x570u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA0_OFFS                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x570u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA0_RMSK                                                         0xfffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA0_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA0_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA0_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA0_SENSOR_APC0_MODE_DATA_RD1_BMSK                               0xfff000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA0_SENSOR_APC0_MODE_DATA_RD1_SHFT                                     12u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA0_SENSOR_APC0_MODE_DATA_RD0_BMSK                                  0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA0_SENSOR_APC0_MODE_DATA_RD0_SHFT                                      0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA1_ADDR                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x574u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA1_OFFS                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x574u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA1_RMSK                                                         0xfffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA1_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA1_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA1_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA1_SENSOR_APC0_MODE_DATA_RD3_BMSK                               0xfff000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA1_SENSOR_APC0_MODE_DATA_RD3_SHFT                                     12u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA1_SENSOR_APC0_MODE_DATA_RD2_BMSK                                  0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA1_SENSOR_APC0_MODE_DATA_RD2_SHFT                                      0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA2_ADDR                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x578u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA2_OFFS                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x578u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA2_RMSK                                                         0xfffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA2_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA2_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA2_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA2_SENSOR_APC0_MODE_DATA_RD5_BMSK                               0xfff000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA2_SENSOR_APC0_MODE_DATA_RD5_SHFT                                     12u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA2_SENSOR_APC0_MODE_DATA_RD4_BMSK                                  0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA2_SENSOR_APC0_MODE_DATA_RD4_SHFT                                      0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA3_ADDR                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x57cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA3_OFFS                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x57cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA3_RMSK                                                         0xfffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA3_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA3_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA3_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA3_SENSOR_APC0_MODE_DATA_RD7_BMSK                               0xfff000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA3_SENSOR_APC0_MODE_DATA_RD7_SHFT                                     12u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA3_SENSOR_APC0_MODE_DATA_RD6_BMSK                                  0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA3_SENSOR_APC0_MODE_DATA_RD6_SHFT                                      0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA4_ADDR                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x580u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA4_OFFS                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x580u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA4_RMSK                                                         0xfffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA4_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA4_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA4_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA4_SENSOR_APC0_MODE_DATA_RD9_BMSK                               0xfff000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA4_SENSOR_APC0_MODE_DATA_RD9_SHFT                                     12u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA4_SENSOR_APC0_MODE_DATA_RD8_BMSK                                  0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA4_SENSOR_APC0_MODE_DATA_RD8_SHFT                                      0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA0_ADDR                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x584u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA0_OFFS                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x584u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA0_RMSK                                                         0xfffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA0_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA0_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA0_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA0_SENSOR_APC1_MODE_DATA_RD1_BMSK                               0xfff000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA0_SENSOR_APC1_MODE_DATA_RD1_SHFT                                     12u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA0_SENSOR_APC1_MODE_DATA_RD0_BMSK                                  0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA0_SENSOR_APC1_MODE_DATA_RD0_SHFT                                      0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA1_ADDR                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x588u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA1_OFFS                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x588u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA1_RMSK                                                         0xfffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA1_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA1_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA1_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA1_SENSOR_APC1_MODE_DATA_RD3_BMSK                               0xfff000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA1_SENSOR_APC1_MODE_DATA_RD3_SHFT                                     12u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA1_SENSOR_APC1_MODE_DATA_RD2_BMSK                                  0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA1_SENSOR_APC1_MODE_DATA_RD2_SHFT                                      0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA2_ADDR                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x58cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA2_OFFS                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x58cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA2_RMSK                                                         0xfffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA2_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA2_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA2_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA2_SENSOR_APC1_MODE_DATA_RD5_BMSK                               0xfff000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA2_SENSOR_APC1_MODE_DATA_RD5_SHFT                                     12u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA2_SENSOR_APC1_MODE_DATA_RD4_BMSK                                  0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA2_SENSOR_APC1_MODE_DATA_RD4_SHFT                                      0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA3_ADDR                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x590u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA3_OFFS                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x590u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA3_RMSK                                                         0xfffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA3_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA3_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA3_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA3_SENSOR_APC1_MODE_DATA_RD7_BMSK                               0xfff000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA3_SENSOR_APC1_MODE_DATA_RD7_SHFT                                     12u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA3_SENSOR_APC1_MODE_DATA_RD6_BMSK                                  0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA3_SENSOR_APC1_MODE_DATA_RD6_SHFT                                      0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA4_ADDR                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x594u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA4_OFFS                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x594u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA4_RMSK                                                         0xfffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA4_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA4_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA4_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA4_SENSOR_APC1_MODE_DATA_RD9_BMSK                               0xfff000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA4_SENSOR_APC1_MODE_DATA_RD9_SHFT                                     12u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA4_SENSOR_APC1_MODE_DATA_RD8_BMSK                                  0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA4_SENSOR_APC1_MODE_DATA_RD8_SHFT                                      0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PLL_LOCK_WAIT_CNTR_ADDR                                                             (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x598u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PLL_LOCK_WAIT_CNTR_OFFS                                                             (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x598u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PLL_LOCK_WAIT_CNTR_RMSK                                                                 0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PLL_LOCK_WAIT_CNTR_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PLL_LOCK_WAIT_CNTR_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PLL_LOCK_WAIT_CNTR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PLL_LOCK_WAIT_CNTR_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PLL_LOCK_WAIT_CNTR_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PLL_LOCK_WAIT_CNTR_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PLL_LOCK_WAIT_CNTR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PLL_LOCK_WAIT_CNTR_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PLL_LOCK_WAIT_CNTR_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PLL_LOCK_WAIT_CNTR_WAIT_CNT_VAL_BMSK                                                    0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PLL_LOCK_WAIT_CNTR_WAIT_CNT_VAL_SHFT                                                         0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_LIVE_STREAM_SEL_ADDR                                                               (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x59cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_LIVE_STREAM_SEL_OFFS                                                               (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x59cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_LIVE_STREAM_SEL_RMSK                                                                  0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_LIVE_STREAM_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_LIVE_STREAM_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_LIVE_STREAM_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_LIVE_STREAM_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_LIVE_STREAM_SEL_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_LIVE_STREAM_SEL_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_LIVE_STREAM_SEL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_LIVE_STREAM_SEL_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_LIVE_STREAM_SEL_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_LIVE_STREAM_SEL_VSENSE_SENSOR_LIVE_STREAM_SEL_BMSK                                    0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_LIVE_STREAM_SEL_VSENSE_SENSOR_LIVE_STREAM_SEL_SHFT                                          0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_LIVE_STREAM_EN_ADDR                                                                (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x5a0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_LIVE_STREAM_EN_OFFS                                                                (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5a0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_LIVE_STREAM_EN_RMSK                                                                       0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_LIVE_STREAM_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_LIVE_STREAM_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_LIVE_STREAM_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_LIVE_STREAM_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_LIVE_STREAM_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_LIVE_STREAM_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_LIVE_STREAM_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_LIVE_STREAM_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_LIVE_STREAM_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_LIVE_STREAM_EN_VSENSE_SENSOR_ALL_LIVE_STREAM_EN_BMSK                                      0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_LIVE_STREAM_EN_VSENSE_SENSOR_ALL_LIVE_STREAM_EN_SHFT                                        0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_FUSA_CFG_ADDR                                                                             (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x5a4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_FUSA_CFG_OFFS                                                                             (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5a4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_FUSA_CFG_RMSK                                                                             0x800000fful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_FUSA_CFG_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_FUSA_CFG_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_FUSA_CFG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_FUSA_CFG_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_FUSA_CFG_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_FUSA_CFG_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_FUSA_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_FUSA_CFG_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_FUSA_CFG_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_FUSA_CFG_DISABLE_SUMMARY_READ_BMSK                                                        0x80000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_FUSA_CFG_DISABLE_SUMMARY_READ_SHFT                                                                31u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_FUSA_CFG_FUSA_EN_BMSK                                                                           0xffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_FUSA_CFG_FUSA_EN_SHFT                                                                              0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_ADDR                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x5a8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_OFFS                                                            (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5a8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_RMSK                                                                  0x1fu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_VSENSE_CNTRL_PARITY_IRQ_TYPE_BMSK                                     0x18u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_VSENSE_CNTRL_PARITY_IRQ_TYPE_SHFT                                        3u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_VSENSE_CNTRL_PARITY_IRQ_EN_BMSK                                        0x4u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_VSENSE_CNTRL_PARITY_IRQ_EN_SHFT                                          2u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_VSENSE_CNTRL_PARITY_IRQ_FORCE_BMSK                                     0x2u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_VSENSE_CNTRL_PARITY_IRQ_FORCE_SHFT                                       1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_VSENSE_CNTRL_PARITY_IRQ_CLEAR_BMSK                                     0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_VSENSE_CNTRL_PARITY_IRQ_CLEAR_SHFT                                       0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_ADDR                                                              (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x5acu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_OFFS                                                              (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5acu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_RMSK                                                              0xc007fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_VSENSE_SENSOR_HEARTBEAT_IRQ_TYPE_BMSK                             0xc0000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_VSENSE_SENSOR_HEARTBEAT_IRQ_TYPE_SHFT                                     30u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_BMSK                                  0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_SHFT                                        0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_ADDR                                                           (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x5b0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_OFFS                                                           (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5b0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_RMSK                                                              0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_BMSK                            0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_SHFT                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_ADDR                                                           (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x5b4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_OFFS                                                           (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5b4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_RMSK                                                              0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_BMSK                            0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_SHFT                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_PARITY_IRQ_STATUS_ADDR                                                   (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x5b8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_PARITY_IRQ_STATUS_OFFS                                                   (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5b8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_PARITY_IRQ_STATUS_RMSK                                                   0x8007fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_PARITY_IRQ_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_PARITY_IRQ_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_PARITY_IRQ_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_PARITY_IRQ_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_PARITY_IRQ_STATUS_VSENSE_CNTRL_PARITY_IRQ_STATUS_BMSK                    0x80000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_PARITY_IRQ_STATUS_VSENSE_CNTRL_PARITY_IRQ_STATUS_SHFT                            31u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_PARITY_IRQ_STATUS_VSENSE_SENSOR_HEARTBEAT_IRQ_STATUS_BMSK                   0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_HEARTBEAT_PARITY_IRQ_STATUS_VSENSE_SENSOR_HEARTBEAT_IRQ_STATUS_SHFT                         0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_ADDR                                                              (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x5bcu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_OFFS                                                              (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5bcu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_RMSK                                                              0xc007fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_VSENSE_SENSOR_OUTER_MAX_IRQ_TYPE_BMSK                             0xc0000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_VSENSE_SENSOR_OUTER_MAX_IRQ_TYPE_SHFT                                     30u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_BMSK                                  0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_SHFT                                        0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_ADDR                                                           (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x5c0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_OFFS                                                           (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5c0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_RMSK                                                              0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_BMSK                            0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_SHFT                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_ADDR                                                           (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x5c4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_OFFS                                                           (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5c4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_RMSK                                                              0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_BMSK                            0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_SHFT                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_STATUS_ADDR                                                          (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x5c8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_STATUS_OFFS                                                          (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5c8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_STATUS_RMSK                                                             0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_STATUS_VSENSE_SENSOR_OUTER_MAX_IRQ_STATUS_BMSK                          0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MAX_IRQ_STATUS_VSENSE_SENSOR_OUTER_MAX_IRQ_STATUS_SHFT                                0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_EN_ADDR                                                              (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x5ccu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_EN_OFFS                                                              (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5ccu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_EN_RMSK                                                              0xc007fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_EN_VSENSE_SENSOR_INNER_MAX_IRQ_TYPE_BMSK                             0xc0000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_EN_VSENSE_SENSOR_INNER_MAX_IRQ_TYPE_SHFT                                     30u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_EN_VSENSE_SENSOR_INNER_MAX_IRQ_EN_BMSK                                  0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_EN_VSENSE_SENSOR_INNER_MAX_IRQ_EN_SHFT                                        0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_ADDR                                                           (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x5d0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_OFFS                                                           (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5d0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_RMSK                                                              0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_BMSK                            0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_SHFT                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_ADDR                                                           (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x5d4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_OFFS                                                           (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5d4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_RMSK                                                              0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_BMSK                            0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_SHFT                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_STATUS_ADDR                                                          (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x5d8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_STATUS_OFFS                                                          (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5d8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_STATUS_RMSK                                                             0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_STATUS_VSENSE_SENSOR_INNER_MAX_IRQ_STATUS_BMSK                          0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MAX_IRQ_STATUS_VSENSE_SENSOR_INNER_MAX_IRQ_STATUS_SHFT                                0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_EN_ADDR                                                              (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x5dcu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_EN_OFFS                                                              (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5dcu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_EN_RMSK                                                              0xc007fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_EN_VSENSE_SENSOR_INNER_MIN_IRQ_TYPE_BMSK                             0xc0000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_EN_VSENSE_SENSOR_INNER_MIN_IRQ_TYPE_SHFT                                     30u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_EN_VSENSE_SENSOR_INNER_MIN_IRQ_EN_BMSK                                  0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_EN_VSENSE_SENSOR_INNER_MIN_IRQ_EN_SHFT                                        0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_ADDR                                                           (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x5e0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_OFFS                                                           (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5e0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_RMSK                                                              0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_BMSK                            0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_SHFT                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_ADDR                                                           (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x5e4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_OFFS                                                           (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5e4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_RMSK                                                              0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_BMSK                            0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_SHFT                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_STATUS_ADDR                                                          (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x5e8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_STATUS_OFFS                                                          (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5e8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_STATUS_RMSK                                                             0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_STATUS_VSENSE_SENSOR_INNER_MIN_IRQ_STATUS_BMSK                          0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_INNER_MIN_IRQ_STATUS_VSENSE_SENSOR_INNER_MIN_IRQ_STATUS_SHFT                                0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_ADDR                                                              (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x5ecu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_OFFS                                                              (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5ecu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_RMSK                                                              0xc007fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_VSENSE_SENSOR_OUTER_MIN_IRQ_TYPE_BMSK                             0xc0000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_VSENSE_SENSOR_OUTER_MIN_IRQ_TYPE_SHFT                                     30u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_BMSK                                  0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_SHFT                                        0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_ADDR                                                           (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x5f0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_OFFS                                                           (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5f0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_RMSK                                                              0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_BMSK                            0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_SHFT                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_ADDR                                                           (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x5f4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_OFFS                                                           (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5f4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_RMSK                                                              0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_BMSK                            0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_SHFT                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_STATUS_ADDR                                                          (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x5f8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_STATUS_OFFS                                                          (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5f8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_STATUS_RMSK                                                             0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_STATUS_VSENSE_SENSOR_OUTER_MIN_IRQ_STATUS_BMSK                          0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_OUTER_MIN_IRQ_STATUS_VSENSE_SENSOR_OUTER_MIN_IRQ_STATUS_SHFT                                0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_IRQ_DETECT_CTL_ADDR                                                                (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x5fcu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_IRQ_DETECT_CTL_OFFS                                                                (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5fcu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_IRQ_DETECT_CTL_RMSK                                                                      0x3fu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_IRQ_DETECT_CTL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_IRQ_DETECT_CTL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_IRQ_DETECT_CTL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_IRQ_DETECT_CTL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_IRQ_DETECT_CTL_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_IRQ_DETECT_CTL_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_IRQ_DETECT_CTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_IRQ_DETECT_CTL_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_IRQ_DETECT_CTL_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_IRQ_DETECT_CTL_VSENSE_SENSOR_PARITY_IRQ_DETECT_CTL_BMSK                                  0x20u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_IRQ_DETECT_CTL_VSENSE_SENSOR_PARITY_IRQ_DETECT_CTL_SHFT                                     5u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_IRQ_DETECT_CTL_VSENSE_SENSOR_HEARTBEAT_IRQ_DETECT_CTL_BMSK                               0x10u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_IRQ_DETECT_CTL_VSENSE_SENSOR_HEARTBEAT_IRQ_DETECT_CTL_SHFT                                  4u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_IRQ_DETECT_CTL_VSENSE_SENSOR_OUTER_MAX_IRQ_DETECT_CTL_BMSK                                0x8u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_IRQ_DETECT_CTL_VSENSE_SENSOR_OUTER_MAX_IRQ_DETECT_CTL_SHFT                                  3u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_IRQ_DETECT_CTL_VSENSE_SENSOR_INNER_MAX_IRQ_DETECT_CTL_BMSK                                0x4u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_IRQ_DETECT_CTL_VSENSE_SENSOR_INNER_MAX_IRQ_DETECT_CTL_SHFT                                  2u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_IRQ_DETECT_CTL_VSENSE_SENSOR_INNER_MIN_IRQ_DETECT_CTL_BMSK                                0x2u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_IRQ_DETECT_CTL_VSENSE_SENSOR_INNER_MIN_IRQ_DETECT_CTL_SHFT                                  1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_IRQ_DETECT_CTL_VSENSE_SENSOR_OUTER_MIN_IRQ_DETECT_CTL_BMSK                                0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_IRQ_DETECT_CTL_VSENSE_SENSOR_OUTER_MIN_IRQ_DETECT_CTL_SHFT                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_ERROR_STATUS_ADDR                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x600u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_ERROR_STATUS_OFFS                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x600u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_ERROR_STATUS_RMSK                                                       0x8007fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_ERROR_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_ERROR_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_ERROR_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_ERROR_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_ERROR_STATUS_VSENSE_SENSOR_GLOBAL_PARITY_IRQ_ERROR_STATUS_BMSK          0x80000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_ERROR_STATUS_VSENSE_SENSOR_GLOBAL_PARITY_IRQ_ERROR_STATUS_SHFT                  31u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_ERROR_STATUS_VSENSE_SENSOR_GLOBAL_IRQ_ERROR_STATUS_BMSK                    0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_ERROR_STATUS_VSENSE_SENSOR_GLOBAL_IRQ_ERROR_STATUS_SHFT                          0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_WARN_STATUS_ADDR                                                        (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x604u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_WARN_STATUS_OFFS                                                        (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x604u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_WARN_STATUS_RMSK                                                        0x8007fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_WARN_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_WARN_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_WARN_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_WARN_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_WARN_STATUS_VSENSE_SENSOR_GLOBAL_PARITY_IRQ_WARN_STATUS_BMSK            0x80000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_WARN_STATUS_VSENSE_SENSOR_GLOBAL_PARITY_IRQ_WARN_STATUS_SHFT                    31u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_WARN_STATUS_VSENSE_SENSOR_GLOBAL_IRQ_WARN_STATUS_BMSK                      0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_WARN_STATUS_VSENSE_SENSOR_GLOBAL_IRQ_WARN_STATUS_SHFT                            0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_ADDR                                                              (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x608u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_OFFS                                                              (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x608u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_RMSK                                                                 0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_BMSK                                  0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_SHFT                                        0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_DISABLE_ADDR                                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0x60cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_DISABLE_OFFS                                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x60cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_DISABLE_RMSK                                                                  0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_DISABLE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_DISABLE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_DISABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_DISABLE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_DISABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_DISABLE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_DISABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_DISABLE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_DISABLE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_DISABLE_VSENSE_CNTRL_DEBUG_DISABLE_BMSK                                       0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_DEBUG_DISABLE_VSENSE_CNTRL_DEBUG_DISABLE_SHFT                                                0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MODEm_THRESHOLD_ADDR(m,n)                                                         (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0X610 + (0x4*(m)) + (0x50*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MODEm_THRESHOLD_OFFS(m,n)                                                         (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0X610 + (0x4*(m)) + (0x50*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MODEm_THRESHOLD_RMSK                                                              0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MODEm_THRESHOLD_MAXm                                                                      18u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MODEm_THRESHOLD_MAXn                                                                      15u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MODEm_THRESHOLD_INI2(m,n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MODEm_THRESHOLD_ADDR(m,n), HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MODEm_THRESHOLD_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MODEm_THRESHOLD_INMI2(m,n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MODEm_THRESHOLD_ADDR(m,n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MODEm_THRESHOLD_OUTI2(m,n,val)        \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MODEm_THRESHOLD_ADDR(m,n),val)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MODEm_THRESHOLD_OUTMI2(m,n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MODEm_THRESHOLD_ADDR(m,n),mask,val,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MODEm_THRESHOLD_INI2(m,n))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MODEm_THRESHOLD_OUTER_MAX_THRESHOLD_BMSK                                          0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MODEm_THRESHOLD_OUTER_MAX_THRESHOLD_SHFT                                                  24u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MODEm_THRESHOLD_INNER_MAX_THRESHOLD_BMSK                                            0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MODEm_THRESHOLD_INNER_MAX_THRESHOLD_SHFT                                                  16u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MODEm_THRESHOLD_INNER_MIN_THRESHOLD_BMSK                                              0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MODEm_THRESHOLD_INNER_MIN_THRESHOLD_SHFT                                                   8u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MODEm_THRESHOLD_OUTER_MIN_THRESHOLD_BMSK                                                0xffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_MODEm_THRESHOLD_OUTER_MIN_THRESHOLD_SHFT                                                   0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MODEn_RANGE_ADDR(n)                                                           (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0XB80 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MODEn_RANGE_OFFS(n)                                                           (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0XB80 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MODEn_RANGE_RMSK                                                               0xfff0ffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MODEn_RANGE_MAXn                                                                      15u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MODEn_RANGE_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MODEn_RANGE_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MODEn_RANGE_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MODEn_RANGE_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MODEn_RANGE_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MODEn_RANGE_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MODEn_RANGE_ADDR(n),val)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MODEn_RANGE_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MODEn_RANGE_ADDR(n),mask,val,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MODEn_RANGE_INI(n))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MODEn_RANGE_APC0_MODE_MAX_RANGE_BMSK                                           0xfff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MODEn_RANGE_APC0_MODE_MAX_RANGE_SHFT                                                  16u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MODEn_RANGE_APC0_MODE_MIN_RANGE_BMSK                                               0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC0_MODEn_RANGE_APC0_MODE_MIN_RANGE_SHFT                                                   0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MODEn_RANGE_ADDR(n)                                                           (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0XBC0 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MODEn_RANGE_OFFS(n)                                                           (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0XBC0 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MODEn_RANGE_RMSK                                                               0xfff0ffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MODEn_RANGE_MAXn                                                                      15u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MODEn_RANGE_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MODEn_RANGE_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MODEn_RANGE_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MODEn_RANGE_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MODEn_RANGE_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MODEn_RANGE_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MODEn_RANGE_ADDR(n),val)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MODEn_RANGE_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MODEn_RANGE_ADDR(n),mask,val,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MODEn_RANGE_INI(n))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MODEn_RANGE_APC1_MODE_MAX_RANGE_BMSK                                           0xfff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MODEn_RANGE_APC1_MODE_MAX_RANGE_SHFT                                                  16u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MODEn_RANGE_APC1_MODE_MIN_RANGE_BMSK                                               0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_APC1_MODEn_RANGE_APC1_MODE_MIN_RANGE_SHFT                                                   0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_HEARTBEAT_RANGE_ADDR(n)                                                           (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0XC10 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_HEARTBEAT_RANGE_OFFS(n)                                                           (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0XC10 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_HEARTBEAT_RANGE_RMSK                                                              0x800ffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_HEARTBEAT_RANGE_MAXn                                                                      18u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_HEARTBEAT_RANGE_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_HEARTBEAT_RANGE_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_HEARTBEAT_RANGE_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_HEARTBEAT_RANGE_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_HEARTBEAT_RANGE_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_HEARTBEAT_RANGE_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_HEARTBEAT_RANGE_ADDR(n),val)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_HEARTBEAT_RANGE_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_HEARTBEAT_RANGE_ADDR(n),mask,val,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_HEARTBEAT_RANGE_INI(n))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_HEARTBEAT_RANGE_VSENSE_SENSOR_HEARTBEAT_EN_BMSK                                   0x80000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_HEARTBEAT_RANGE_VSENSE_SENSOR_HEARTBEAT_EN_SHFT                                           31u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_HEARTBEAT_RANGE_VSENSE_SENSOR_HEARTBEAT_MAX_BMSK                                     0xffc00ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_HEARTBEAT_RANGE_VSENSE_SENSOR_HEARTBEAT_MAX_SHFT                                          10u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_HEARTBEAT_RANGE_VSENSE_SENSOR_HEARTBEAT_MIN_BMSK                                       0x3ffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_HEARTBEAT_RANGE_VSENSE_SENSOR_HEARTBEAT_MIN_SHFT                                           0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_HEARTBEAT_CNT_ADDR(n)                                                             (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0XC60 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_HEARTBEAT_CNT_OFFS(n)                                                             (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0XC60 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_HEARTBEAT_CNT_RMSK                                                                     0x3ffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_HEARTBEAT_CNT_MAXn                                                                        18u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_HEARTBEAT_CNT_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_HEARTBEAT_CNT_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_HEARTBEAT_CNT_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_HEARTBEAT_CNT_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_HEARTBEAT_CNT_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_HEARTBEAT_CNT_VSENSE_SENSOR_HEARTBEAT_CNT_BMSK                                         0x3ffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSORn_HEARTBEAT_CNT_VSENSE_SENSOR_HEARTBEAT_CNT_SHFT                                             0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_READ_EN_ADDR                                                                (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0xcb0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_READ_EN_OFFS                                                                (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0xcb0u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_READ_EN_RMSK                                                                   0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_READ_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_READ_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_READ_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_READ_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_READ_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_READ_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_READ_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_READ_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_READ_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_READ_EN_VSENSE_SENSOR_CONFIG_READ_EN_BMSK                                      0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_READ_EN_VSENSE_SENSOR_CONFIG_READ_EN_SHFT                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SUMMARY_READ_EN_ADDR                                                               (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0xcb4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SUMMARY_READ_EN_OFFS                                                               (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0xcb4u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SUMMARY_READ_EN_RMSK                                                                  0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SUMMARY_READ_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SUMMARY_READ_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SUMMARY_READ_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SUMMARY_READ_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SUMMARY_READ_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SUMMARY_READ_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SUMMARY_READ_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SUMMARY_READ_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SUMMARY_READ_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SUMMARY_READ_EN_VSENSE_SENSOR_SUMMARY_READ_EN_BMSK                                    0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_SUMMARY_READ_EN_VSENSE_SENSOR_SUMMARY_READ_EN_SHFT                                          0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_SUMMARY_RD_STATUS_ADDR                                                      (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0xcb8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_SUMMARY_RD_STATUS_OFFS                                                      (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0xcb8u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_SUMMARY_RD_STATUS_RMSK                                                         0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_SUMMARY_RD_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_SUMMARY_RD_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_SUMMARY_RD_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_SUMMARY_RD_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_SUMMARY_RD_STATUS_VSENSE_SENSOR_CONFIG_SUMMARY_RD_STATUS_BMSK                  0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_CONFIG_SUMMARY_RD_STATUS_VSENSE_SENSOR_CONFIG_SUMMARY_RD_STATUS_SHFT                        0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_ADDR(n)                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0XCC0 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_OFFS(n)                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0XCC0 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_RMSK                                                          0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_MAXn                                                                  18u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_ADDR(n),val)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_ADDR(n),mask,val,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_INI(n))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_THRESHOLD_OUTER_MIN_BMSK                                      0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_THRESHOLD_OUTER_MIN_SHFT                                              24u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_THRESHOLD_INNER_MAX_BMSK                                        0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_THRESHOLD_INNER_MAX_SHFT                                              16u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_THRESHOLD_INNER_MIN_BMSK                                          0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_THRESHOLD_INNER_MIN_SHFT                                               8u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_AU_MODE_SEL_BMSK                                                    0x80u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_AU_MODE_SEL_SHFT                                                       7u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_AU_MODE_SEL_LEGACY_MODE_FVAL                                         0x0u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_AU_MODE_SEL_NEW_AU_MODE_FVAL                                         0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_CAPTURE_DELAY_BMSK                                                  0x70u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_CAPTURE_DELAY_SHFT                                                     4u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_TRIG_POS_BMSK                                                        0xcu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_TRIG_POS_SHFT                                                          2u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_TRIG_POS_PRE_TRIG_FVAL                                               0x0u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_TRIG_POS_MID_TRIG_FVAL                                               0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_TRIG_POS_POST_TRIG_FVAL                                              0x2u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_WATERMARK_EN_BMSK                                                    0x2u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_WATERMARK_EN_SHFT                                                      1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_AUTO_CAL_EN_BMSK                                                     0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_AUTO_CAL_EN_SHFT                                                       0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_ADDR(n)                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0XD10 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_OFFS(n)                                                       (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0XD10 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_RMSK                                                           0xffffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_MAXn                                                                  18u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_PARITY_CHK_EN_BMSK                                             0x8000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_PARITY_CHK_EN_SHFT                                                    27u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_TDF_COND_WATERMARK_BMSK                                        0x4000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_TDF_COND_WATERMARK_SHFT                                               26u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_FIFO_DATA_HS_RATE_BMSK                                         0x3000000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_FIFO_DATA_HS_RATE_SHFT                                                24u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_RESERVD2_BMSK                                                   0x800000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_RESERVD2_SHFT                                                         23u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_VS_CLK_DEBUG_EN_BMSK                                            0x400000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_VS_CLK_DEBUG_EN_SHFT                                                  22u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_VCO_PWR_SEL_MODE_BMSK                                           0x200000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_VCO_PWR_SEL_MODE_SHFT                                                 21u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_DC_MEAS_CYC_BMSK                                                0x180000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_DC_MEAS_CYC_SHFT                                                      19u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_DC_MEAS_CYC_NUM_DC_MEAS_CYC256_FVAL                                  0x0u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_DC_MEAS_CYC_NUM_DC_MEAS_CYC128_FVAL                                  0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_DC_MEAS_CYC_NUM_DC_MEAS_CYC64_FVAL                                   0x2u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_DC_MEAS_CYC_NUM_DC_MEAS_CYC32_FVAL                                   0x3u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_AC_MODE_BMSK                                                     0x40000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_AC_MODE_SHFT                                                          18u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_RESERVD_BMSK                                                     0x20000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_RESERVD_SHFT                                                          17u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_MODE_SEL_BMSK                                                    0x10000ul
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_MODE_SEL_SHFT                                                         16u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_MODE_SEL_INTERRUPT_MODE_FVAL                                         0x0u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_MODE_SEL_WATERMARK_MODE_FVAL                                         0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_VCO_FILTER_EN_BMSK                                                0x8000u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_VCO_FILTER_EN_SHFT                                                    15u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_VCO_POWER_SEL_BMSK                                                0x4000u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_VCO_POWER_SEL_SHFT                                                    14u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_POWER_EN_BMSK                                                     0x2000u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_POWER_EN_SHFT                                                         13u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_FUNC_EN_BMSK                                                      0x1000u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_FUNC_EN_SHFT                                                          12u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_TRIG_SEL_BMSK                                                      0xc00u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_TRIG_SEL_SHFT                                                         10u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_TRIG_SEL_TRIG_SEL0_FVAL                                              0x0u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_TRIG_SEL_TRIG_SEL1_FVAL                                              0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_TRIG_SEL_TRIG_SEL2_FVAL                                              0x2u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_TRIG_SEL_TRIG_SEL3_FVAL                                              0x3u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_HW_CAPTURE_EN_BMSK                                                 0x200u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_HW_CAPTURE_EN_SHFT                                                     9u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_SW_CAPTURE_BMSK                                                    0x100u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_SW_CAPTURE_SHFT                                                        8u
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_THRESHOLD_OUTER_MAX_BMSK                                            0xffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_THRESHOLD_OUTER_MAX_SHFT                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RAIL_LOCATION_ADDR                                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0xd60u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RAIL_LOCATION_OFFS                                                                  (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0xd60u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RAIL_LOCATION_RMSK                                                                      0x3fffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RAIL_LOCATION_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RAIL_LOCATION_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RAIL_LOCATION_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RAIL_LOCATION_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RAIL_LOCATION_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RAIL_LOCATION_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RAIL_LOCATION_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RAIL_LOCATION_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RAIL_LOCATION_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RAIL_LOCATION_VSENSE_CNTRL_RAIL_LOCATION_BMSK                                           0x3fffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RAIL_LOCATION_VSENSE_CNTRL_RAIL_LOCATION_SHFT                                                0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RAIL0_DEPENDENCY_ADDR                                                               (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0xd64u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RAIL0_DEPENDENCY_OFFS                                                               (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0xd64u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RAIL0_DEPENDENCY_RMSK                                                                   0x3fffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RAIL0_DEPENDENCY_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RAIL0_DEPENDENCY_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RAIL0_DEPENDENCY_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RAIL0_DEPENDENCY_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RAIL0_DEPENDENCY_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RAIL0_DEPENDENCY_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RAIL0_DEPENDENCY_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RAIL0_DEPENDENCY_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RAIL0_DEPENDENCY_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RAIL0_DEPENDENCY_VSENSE_CNTRL_RAIL0_DEPENDENCY_BMSK                                     0x3fffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_RAIL0_DEPENDENCY_VSENSE_CNTRL_RAIL0_DEPENDENCY_SHFT                                          0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_VACC_STATUS_ADDR                                                                    (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0xd68u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_VACC_STATUS_OFFS                                                                    (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0xd68u)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_VACC_STATUS_RMSK                                                                        0x3fffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_VACC_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_VACC_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_VACC_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_VACC_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_VACC_STATUS_VSENSE_CNTRL_VACC_STATUS_BMSK                                               0x3fffu
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_VACC_STATUS_VSENSE_CNTRL_VACC_STATUS_SHFT                                                    0u

#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_EN_ADDR                                                                             (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0xd6cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_EN_OFFS                                                                             (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0xd6cu)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_EN_RMSK                                                                             0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_EN_VSENSE_EN_BMSK                                                                   0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_0_VSENSE_CNTRL_EN_VSENSE_EN_SHFT                                                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_0_FUSA_STATUS_REGISTER_VSENSE_CNTRL_CLK_RESET_ADDR                                                 (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE      + 0xd70u)
#define HWIO_SAILSS_VSENSE_CTRL_0_FUSA_STATUS_REGISTER_VSENSE_CNTRL_CLK_RESET_OFFS                                                 (SAILSS_VSENSE_CTRL_0_VSENSE_CONTROLLER_REG_BASE_OFFS + 0xd70u)
#define HWIO_SAILSS_VSENSE_CTRL_0_FUSA_STATUS_REGISTER_VSENSE_CNTRL_CLK_RESET_RMSK                                                     0x1fffu
#define HWIO_SAILSS_VSENSE_CTRL_0_FUSA_STATUS_REGISTER_VSENSE_CNTRL_CLK_RESET_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_0_FUSA_STATUS_REGISTER_VSENSE_CNTRL_CLK_RESET_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_0_FUSA_STATUS_REGISTER_VSENSE_CNTRL_CLK_RESET_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_0_FUSA_STATUS_REGISTER_VSENSE_CNTRL_CLK_RESET_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_0_FUSA_STATUS_REGISTER_VSENSE_CNTRL_CLK_RESET_HPCNT_BMSK                                               0x1f80u
#define HWIO_SAILSS_VSENSE_CTRL_0_FUSA_STATUS_REGISTER_VSENSE_CNTRL_CLK_RESET_HPCNT_SHFT                                                    7u
#define HWIO_SAILSS_VSENSE_CTRL_0_FUSA_STATUS_REGISTER_VSENSE_CNTRL_CLK_RESET_VPCNT_BMSK                                                 0x7eu
#define HWIO_SAILSS_VSENSE_CTRL_0_FUSA_STATUS_REGISTER_VSENSE_CNTRL_CLK_RESET_VPCNT_SHFT                                                    1u
#define HWIO_SAILSS_VSENSE_CTRL_0_FUSA_STATUS_REGISTER_VSENSE_CNTRL_CLK_RESET_FLT_BMSK                                                    0x1u
#define HWIO_SAILSS_VSENSE_CTRL_0_FUSA_STATUS_REGISTER_VSENSE_CNTRL_CLK_RESET_FLT_SHFT                                                      0u

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER
 *--------------------------------------------------------------------------*/

#define SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE                                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_BASE      + 0x00000000u)
#define SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_SIZE                                                                       0x1000u
#define SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_USED                                                                       0xd70u
#define SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS                                                                       0x00000000u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_HW_ID_ADDR                                                                          (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_HW_ID_OFFS                                                                          (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_HW_ID_RMSK                                                                          0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_HW_ID_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_HW_ID_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_HW_ID_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_HW_ID_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_HW_ID_MAJOR_BMSK                                                                    0xf0000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_HW_ID_MAJOR_SHFT                                                                            28u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_HW_ID_MINOR_BMSK                                                                     0xfff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_HW_ID_MINOR_SHFT                                                                            16u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_HW_ID_STEP_BMSK                                                                         0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_HW_ID_STEP_SHFT                                                                              0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_ADDR(n)                                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0X4 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_OFFS(n)                                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0X4 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_RMSK                                                                     0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_MAXn                                                                             18u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_ADDR(n),val)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_ADDR(n),mask,val,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_INI(n))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_THRESHOLD_OUTER_MIN_BMSK                                                 0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_THRESHOLD_OUTER_MIN_SHFT                                                         24u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_THRESHOLD_INNER_MAX_BMSK                                                   0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_THRESHOLD_INNER_MAX_SHFT                                                         16u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_THRESHOLD_INNER_MIN_BMSK                                                     0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_THRESHOLD_INNER_MIN_SHFT                                                          8u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_AU_MODE_SEL_BMSK                                                               0x80u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_AU_MODE_SEL_SHFT                                                                  7u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_AU_MODE_SEL_LEGACY_MODE_FVAL                                                    0x0u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_AU_MODE_SEL_NEW_AU_MODE_FVAL                                                    0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_CAPTURE_DELAY_BMSK                                                             0x70u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_CAPTURE_DELAY_SHFT                                                                4u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_TRIG_POS_BMSK                                                                   0xcu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_TRIG_POS_SHFT                                                                     2u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_TRIG_POS_PRE_TRIG_FVAL                                                          0x0u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_TRIG_POS_MID_TRIG_FVAL                                                          0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_TRIG_POS_POST_TRIG_FVAL                                                         0x2u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_WATERMARK_EN_BMSK                                                               0x2u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_WATERMARK_EN_SHFT                                                                 1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_AUTO_CAL_EN_BMSK                                                                0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_0_AUTO_CAL_EN_SHFT                                                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_ADDR(n)                                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0X54 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_OFFS(n)                                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0X54 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_RMSK                                                                      0xffffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_MAXn                                                                             18u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_ADDR(n),val)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_ADDR(n),mask,val,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_INI(n))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_PARITY_CHK_EN_BMSK                                                        0x8000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_PARITY_CHK_EN_SHFT                                                               27u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_TDF_COND_WATERMARK_BMSK                                                   0x4000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_TDF_COND_WATERMARK_SHFT                                                          26u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_FIFO_DATA_HS_RATE_BMSK                                                    0x3000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_FIFO_DATA_HS_RATE_SHFT                                                           24u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_RESERVD2_BMSK                                                              0x800000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_RESERVD2_SHFT                                                                    23u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_VS_CLK_DEBUG_EN_BMSK                                                       0x400000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_VS_CLK_DEBUG_EN_SHFT                                                             22u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_VCO_PWR_SEL_MODE_BMSK                                                      0x200000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_VCO_PWR_SEL_MODE_SHFT                                                            21u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_DC_MEAS_CYC_BMSK                                                           0x180000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_DC_MEAS_CYC_SHFT                                                                 19u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_DC_MEAS_CYC_NUM_DC_MEAS_CYC256_FVAL                                             0x0u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_DC_MEAS_CYC_NUM_DC_MEAS_CYC128_FVAL                                             0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_DC_MEAS_CYC_NUM_DC_MEAS_CYC64_FVAL                                              0x2u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_DC_MEAS_CYC_NUM_DC_MEAS_CYC32_FVAL                                              0x3u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_AC_MODE_BMSK                                                                0x40000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_AC_MODE_SHFT                                                                     18u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_RESERVD_BMSK                                                                0x20000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_RESERVD_SHFT                                                                     17u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_MODE_SEL_BMSK                                                               0x10000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_MODE_SEL_SHFT                                                                    16u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_MODE_SEL_INTERRUPT_MODE_FVAL                                                    0x0u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_MODE_SEL_WATERMARK_MODE_FVAL                                                    0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_VCO_FILTER_EN_BMSK                                                           0x8000u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_VCO_FILTER_EN_SHFT                                                               15u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_VCO_POWER_SEL_BMSK                                                           0x4000u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_VCO_POWER_SEL_SHFT                                                               14u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_POWER_EN_BMSK                                                                0x2000u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_POWER_EN_SHFT                                                                    13u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_FUNC_EN_BMSK                                                                 0x1000u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_FUNC_EN_SHFT                                                                     12u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_TRIG_SEL_BMSK                                                                 0xc00u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_TRIG_SEL_SHFT                                                                    10u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_TRIG_SEL_TRIG_SEL0_FVAL                                                         0x0u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_TRIG_SEL_TRIG_SEL1_FVAL                                                         0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_TRIG_SEL_TRIG_SEL2_FVAL                                                         0x2u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_TRIG_SEL_TRIG_SEL3_FVAL                                                         0x3u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_HW_CAPTURE_EN_BMSK                                                            0x200u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_HW_CAPTURE_EN_SHFT                                                                9u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_SW_CAPTURE_BMSK                                                               0x100u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_SW_CAPTURE_SHFT                                                                   8u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_THRESHOLD_OUTER_MAX_BMSK                                                       0xffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_CONFIG_1_THRESHOLD_OUTER_MAX_SHFT                                                          0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_ADDR(n)                                                                   (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0XA4 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_OFFS(n)                                                                   (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0XA4 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_RMSK                                                                      0xffff7ffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_MAXn                                                                              18u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_VDD_MAX_CAL_DATA_BMSK                                                     0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_VDD_MAX_CAL_DATA_SHFT                                                             24u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_VDD_MIN_CAL_DATA_BMSK                                                       0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_VDD_MIN_CAL_DATA_SHFT                                                             16u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_PARITY_BIT_STATUS_BMSK                                                        0x4000u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_PARITY_BIT_STATUS_SHFT                                                            14u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_VS_CLK_FREQ_BMSK                                                              0x3000u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_VS_CLK_FREQ_SHFT                                                                  12u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_VS_CLK_FREQ_CNT_BTWN_0_10_FVAL                                                   0x0u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_VS_CLK_FREQ_CNT_BTWN_10_20_FVAL                                                  0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_VS_CLK_FREQ_CNT_BTWN_20_30_FVAL                                                  0x2u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_VS_CLK_FREQ_CNT_BTWN_30_40_FVAL                                                  0x3u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_VS_CLK_STATUS_BMSK                                                             0x800u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_VS_CLK_STATUS_SHFT                                                                11u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_VS_CLK_STATUS_OFF_FVAL                                                           0x0u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_VS_CLK_STATUS_ON_FVAL                                                            0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_CALIB_DONE_BMSK                                                                0x400u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_CALIB_DONE_SHFT                                                                   10u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_FSM_STATE_BMSK                                                                 0x3c0u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_FSM_STATE_SHFT                                                                     6u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_FIFO_COMPLETE_BMSK                                                              0x20u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_FIFO_COMPLETE_SHFT                                                                 5u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_FIFO_ACTIVE_BMSK                                                                0x10u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_FIFO_ACTIVE_SHFT                                                                   4u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_ALARM_OUTER_MAX_BMSK                                                             0x8u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_ALARM_OUTER_MAX_SHFT                                                               3u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_ALARM_INNER_MAX_BMSK                                                             0x4u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_ALARM_INNER_MAX_SHFT                                                               2u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_ALARM_INNER_MIN_BMSK                                                             0x2u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_ALARM_INNER_MIN_SHFT                                                               1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_ALARM_OUTER_MIN_BMSK                                                             0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_SUMMARY_ALARM_OUTER_MIN_SHFT                                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_ALARM_CNT_ADDR(n)                                                                 (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0XF4 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_ALARM_CNT_OFFS(n)                                                                 (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0XF4 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_ALARM_CNT_RMSK                                                                          0x3fu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_ALARM_CNT_MAXn                                                                            18u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_ALARM_CNT_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_ALARM_CNT_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_ALARM_CNT_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_ALARM_CNT_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_ALARM_CNT_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_ALARM_CNT_ALARM_COUNT_BMSK                                                              0x3fu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_ALARM_CNT_ALARM_COUNT_SHFT                                                                 0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_WR_EN_ADDR                                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x144u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_WR_EN_OFFS                                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x144u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_WR_EN_RMSK                                                                     0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_WR_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_WR_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_WR_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_WR_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_WR_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_WR_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_WR_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_WR_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_WR_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_WR_EN_VSENSE_SENSOR_CONFIG_WR_EN_BMSK                                          0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_WR_EN_VSENSE_SENSOR_CONFIG_WR_EN_SHFT                                                0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_WR_STATUS_ADDR                                                              (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x148u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_WR_STATUS_OFFS                                                              (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x148u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_WR_STATUS_RMSK                                                                 0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_WR_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_WR_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_WR_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_WR_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_WR_STATUS_VSENSE_SENSOR_CONFIG_WR_STATUS_BMSK                                  0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_WR_STATUS_VSENSE_SENSOR_CONFIG_WR_STATUS_SHFT                                        0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FC_MASK_EN_ADDR                                                                    (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x14cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FC_MASK_EN_OFFS                                                                    (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x14cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FC_MASK_EN_RMSK                                                                       0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FC_MASK_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FC_MASK_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FC_MASK_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FC_MASK_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FC_MASK_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FC_MASK_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FC_MASK_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FC_MASK_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FC_MASK_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FC_MASK_EN_VSENSE_SENSOR_FC_MASK_EN_BMSK                                              0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FC_MASK_EN_VSENSE_SENSOR_FC_MASK_EN_SHFT                                                    0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_ADDR                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x150u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_OFFS                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x150u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_RMSK                                                               0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_BMSK                              0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_VSENSE_SENSOR_AOSS_ALARM_MASK_EN_SHFT                                    0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APPS_ALARM_MASK_EN_ADDR                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x154u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APPS_ALARM_MASK_EN_OFFS                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x154u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APPS_ALARM_MASK_EN_RMSK                                                               0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APPS_ALARM_MASK_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APPS_ALARM_MASK_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APPS_ALARM_MASK_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APPS_ALARM_MASK_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APPS_ALARM_MASK_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APPS_ALARM_MASK_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APPS_ALARM_MASK_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APPS_ALARM_MASK_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APPS_ALARM_MASK_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APPS_ALARM_MASK_EN_VSENSE_SENSOR_APPS_ALARM_MASK_EN_BMSK                              0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APPS_ALARM_MASK_EN_VSENSE_SENSOR_APPS_ALARM_MASK_EN_SHFT                                    0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_ADDR                                                          (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x158u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_OFFS                                                          (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x158u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_RMSK                                                             0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_BMSK                          0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_VSENSE_SENSOR_MSS_Q6_ALARM_MASK_EN_SHFT                                0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_ADDR                                                          (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x15cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_OFFS                                                          (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x15cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_RMSK                                                             0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_BMSK                          0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_VSENSE_SENSOR_SSC_Q6_ALARM_MASK_EN_SHFT                                0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_ALARM_STATUS_ADDR                                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x160u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_ALARM_STATUS_OFFS                                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x160u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_ALARM_STATUS_RMSK                                                                     0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_ALARM_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_ALARM_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_ALARM_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_ALARM_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_ALARM_STATUS_VSENSE_SENSOR_ALARM_STATUS_BMSK                                          0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_ALARM_STATUS_VSENSE_SENSOR_ALARM_STATUS_SHFT                                                0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FC_STATUS_ADDR                                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x164u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FC_STATUS_OFFS                                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x164u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FC_STATUS_RMSK                                                                        0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FC_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FC_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FC_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FC_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FC_STATUS_VSENSE_SENSOR_FC_STATUS_BMSK                                                0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FC_STATUS_VSENSE_SENSOR_FC_STATUS_SHFT                                                      0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_ADDR                                                              (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x168u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_OFFS                                                              (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x168u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_RMSK                                                                     0x3u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_MUX_SEL_BMSK                                                             0x3u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_MUX_SEL_SHFT                                                               0u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_MUX_SEL_FIRST_64BITS_FVAL                                                0x0u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_MUX_SEL_SECOND_64BITS_FVAL                                               0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_MUX_SEL_THIRD_64BITS_FVAL                                                0x2u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_FIFO_DATA_MUX_SEL_MUX_SEL_FOURTH_64BITS_FVAL                                               0x3u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_3_TO_0_ADDR                                                              (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x16cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_3_TO_0_OFFS                                                              (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x16cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_3_TO_0_RMSK                                                              0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_3_TO_0_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_3_TO_0_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_3_TO_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_3_TO_0_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_3_TO_0_FIFO_DATA3_BMSK                                                   0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_3_TO_0_FIFO_DATA3_SHFT                                                           24u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_3_TO_0_FIFO_DATA2_BMSK                                                     0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_3_TO_0_FIFO_DATA2_SHFT                                                           16u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_3_TO_0_FIFO_DATA1_BMSK                                                       0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_3_TO_0_FIFO_DATA1_SHFT                                                            8u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_3_TO_0_FIFO_DATA0_BMSK                                                         0xffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_3_TO_0_FIFO_DATA0_SHFT                                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_7_TO_4_ADDR                                                              (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x170u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_7_TO_4_OFFS                                                              (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x170u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_7_TO_4_RMSK                                                              0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_7_TO_4_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_7_TO_4_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_7_TO_4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_7_TO_4_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_7_TO_4_FIFO_DATA7_BMSK                                                   0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_7_TO_4_FIFO_DATA7_SHFT                                                           24u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_7_TO_4_FIFO_DATA6_BMSK                                                     0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_7_TO_4_FIFO_DATA6_SHFT                                                           16u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_7_TO_4_FIFO_DATA5_BMSK                                                       0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_7_TO_4_FIFO_DATA5_SHFT                                                            8u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_7_TO_4_FIFO_DATA4_BMSK                                                         0xffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_7_TO_4_FIFO_DATA4_SHFT                                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_CLEAR_SUMMARY_ADDR                                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x174u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_CLEAR_SUMMARY_OFFS                                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x174u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_CLEAR_SUMMARY_RMSK                                                                     0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_CLEAR_SUMMARY_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_CLEAR_SUMMARY_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_CLEAR_SUMMARY_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_CLEAR_SUMMARY_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_CLEAR_SUMMARY_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_CLEAR_SUMMARY_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_CLEAR_SUMMARY_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_CLEAR_SUMMARY_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_CLEAR_SUMMARY_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_CLEAR_SUMMARY_VSENSE_SENSOR_CLEAR_SUMMARY_BMSK                                         0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_CLEAR_SUMMARY_VSENSE_SENSOR_CLEAR_SUMMARY_SHFT                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_COMMON_CONFIG_ADDR                                                                 (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x178u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_COMMON_CONFIG_OFFS                                                                 (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x178u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_COMMON_CONFIG_RMSK                                                                       0x1fu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_COMMON_CONFIG_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_COMMON_CONFIG_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_COMMON_CONFIG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_COMMON_CONFIG_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_COMMON_CONFIG_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_COMMON_CONFIG_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_COMMON_CONFIG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_COMMON_CONFIG_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_COMMON_CONFIG_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_COMMON_CONFIG_VSENSE_CLR_RCDRW_BMSK                                                      0x10u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_COMMON_CONFIG_VSENSE_CLR_RCDRW_SHFT                                                         4u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_COMMON_CONFIG_VSENSE_SW_DATA_RD_MODE_BMSK                                                 0x8u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_COMMON_CONFIG_VSENSE_SW_DATA_RD_MODE_SHFT                                                   3u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_COMMON_CONFIG_VSENSE_CNTRL_CLR_INT_FIFO_BMSK                                              0x4u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_COMMON_CONFIG_VSENSE_CNTRL_CLR_INT_FIFO_SHFT                                                2u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_COMMON_CONFIG_VSENSE_SENSOR_INT_MODE_BMSK                                                 0x2u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_COMMON_CONFIG_VSENSE_SENSOR_INT_MODE_SHFT                                                   1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_COMMON_CONFIG_VSENSE_SENSOR_INT_MODE_CONTINUOUS_MODE_FVAL                                 0x0u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_COMMON_CONFIG_VSENSE_SENSOR_INT_MODE_BREAK_MODE_FVAL                                      0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_COMMON_CONFIG_VSENSE_SENSOR_BROADCAST_EN_BMSK                                             0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_COMMON_CONFIG_VSENSE_SENSOR_BROADCAST_EN_SHFT                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HW_BYPASS_STATUS_ADDR                                                              (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x17cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HW_BYPASS_STATUS_OFFS                                                              (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x17cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HW_BYPASS_STATUS_RMSK                                                                 0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HW_BYPASS_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HW_BYPASS_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HW_BYPASS_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HW_BYPASS_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HW_BYPASS_STATUS_VSENSE_SENSOR_HW_BYPASS_STATUS_BMSK                                  0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HW_BYPASS_STATUS_VSENSE_SENSOR_HW_BYPASS_STATUS_SHFT                                        0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_TX_MISC_STATUS_CHAINn_ADDR(n)                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0X180 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_TX_MISC_STATUS_CHAINn_OFFS(n)                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0X180 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_TX_MISC_STATUS_CHAINn_RMSK                                                          0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_TX_MISC_STATUS_CHAINn_MAXn                                                                  13u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_TX_MISC_STATUS_CHAINn_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_TX_MISC_STATUS_CHAINn_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_TX_MISC_STATUS_CHAINn_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_TX_MISC_STATUS_CHAINn_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_TX_MISC_STATUS_CHAINn_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_TX_MISC_STATUS_CHAINn_DEBUG_BUS_TX_CHAIN_BMSK                                       0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_TX_MISC_STATUS_CHAINn_DEBUG_BUS_TX_CHAIN_SHFT                                                0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RX_MISC_STATUS_ADDR                                                                 (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x1c0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RX_MISC_STATUS_OFFS                                                                 (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x1c0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RX_MISC_STATUS_RMSK                                                                       0x7fu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RX_MISC_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RX_MISC_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RX_MISC_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RX_MISC_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RX_MISC_STATUS_CMB_DATA_SENT_BMSK                                                         0x40u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RX_MISC_STATUS_CMB_DATA_SENT_SHFT                                                            6u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RX_MISC_STATUS_RX_FSM_ERR_CNT_BMSK                                                        0x38u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RX_MISC_STATUS_RX_FSM_ERR_CNT_SHFT                                                           3u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RX_MISC_STATUS_RX_FSM_STATE_BMSK                                                           0x7u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RX_MISC_STATUS_RX_FSM_STATE_SHFT                                                             0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_ADDR                                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x1c4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_OFFS                                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x1c4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_RMSK                                                                       0x8000003ful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_EN_BMSK                                                          0x80000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_EN_SHFT                                                                  31u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_BMSK                                                               0x3fu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_SHFT                                                                  0u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_TX_DBG_BUS0_FVAL                                                    0x0u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_TX_DBG_BUS1_FVAL                                                    0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_TX_DBG_BUS2_FVAL                                                    0x2u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_TX_DBG_BUS3_FVAL                                                    0x3u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_TX_DBG_BUS4_FVAL                                                    0x4u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_TX_DBG_BUS5_FVAL                                                    0x5u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_TX_DBG_BUS6_FVAL                                                    0x6u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_TX_DBG_BUS7_FVAL                                                    0x7u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_TX_DBG_BUS8_FVAL                                                    0x8u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_TX_DBG_BUS9_FVAL                                                    0x9u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_TX_DBG_BUS10_FVAL                                                   0xau
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_TX_DBG_BUS11_FVAL                                                   0xbu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_TX_DBG_BUS12_FVAL                                                   0xcu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_TX_DBG_BUS13_FVAL                                                   0xdu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_RX_DBG_BUS_FVAL                                                    0x10u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_ALARM_BUS_FVAL                                                     0x11u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CMB_DATA_FVAL                                                      0x12u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_FC_BUS_FVAL                                                        0x13u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLAMP_EN_BUS_FVAL                                                  0x14u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_DISABLE_SENSOR_BUS_FVAL                                            0x15u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_POWER_DOWN_BUS_FVAL                                                0x16u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_RESET_STATE_BUS_FVAL                                               0x17u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_EN_BUS_FVAL                                                    0x18u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM0_DBG_BUS_FVAL                                              0x19u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM1_DBG_BUS_FVAL                                              0x1au
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM2_DBG_BUS_FVAL                                              0x1bu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM3_DBG_BUS_FVAL                                              0x1cu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM4_DBG_BUS_FVAL                                              0x1du
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM5_DBG_BUS_FVAL                                              0x1eu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM6_DBG_BUS_FVAL                                              0x1fu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM7_DBG_BUS_FVAL                                              0x20u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM8_DBG_BUS_FVAL                                              0x21u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM9_DBG_BUS_FVAL                                              0x22u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM10_DBG_BUS_FVAL                                             0x23u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM11_DBG_BUS_FVAL                                             0x24u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM12_DBG_BUS_FVAL                                             0x25u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM13_DBG_BUS_FVAL                                             0x26u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM14_DBG_BUS_FVAL                                             0x27u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM15_DBG_BUS_FVAL                                             0x28u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM16_DBG_BUS_FVAL                                             0x29u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM17_DBG_BUS_FVAL                                             0x2au
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CLK_FSM18_DBG_BUS_FVAL                                             0x2bu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CPRF0_DBG_BUS_FVAL                                                 0x2eu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CPRF1_DBG_BUS_FVAL                                                 0x2fu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CPRF2_DBG_BUS_FVAL                                                 0x30u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CPRF3_DBG_BUS_FVAL                                                 0x31u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CPRF4_DBG_BUS_FVAL                                                 0x32u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CPRF5_DBG_BUS_FVAL                                                 0x33u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CPRF6_DBG_BUS_FVAL                                                 0x34u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CPRF7_DBG_BUS_FVAL                                                 0x35u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CPRF8_DBG_BUS_FVAL                                                 0x36u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CPRF9_DBG_BUS_FVAL                                                 0x37u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CPRH0_DBG_BUS_FVAL                                                 0x3au
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_CPRH1_DBG_BUS_FVAL                                                 0x3bu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_EN_DEBUG_BUS_SEL_VACC_DBG_BUS_FVAL                                                  0x3cu

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_MODE_ADDR                                                                (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x1c8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_MODE_OFFS                                                                (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x1c8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_MODE_RMSK                                                                      0xffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DELAY_BMSK                                        0xc0u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DELAY_SHFT                                           6u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DELAY_DLY_10_CYCLES_FVAL                           0x0u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DELAY_DLY_20_CYCLES_FVAL                           0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DELAY_DLY_30_CYCLES_FVAL                           0x2u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DELAY_DLY_50_CYCLES_FVAL                           0x3u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DRIVE_SDATA1_BMSK                                 0x20u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DRIVE_SDATA1_SHFT                                    5u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DRIVE_SDATA0_BMSK                                 0x10u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DRIVE_SDATA0_SHFT                                    4u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DRIVE_SENA_BMSK                                    0x8u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DRIVE_SENA_SHFT                                      3u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DRIVE_SMODE1_BMSK                                  0x4u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DRIVE_SMODE1_SHFT                                    2u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DRIVE_SMODE0_BMSK                                  0x2u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_DRIVE_SMODE0_SHFT                                    1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_MODE_EN_BMSK                                       0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_MODE_VSENSE_SENSOR_SELF_TEST_MODE_EN_SHFT                                         0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_ADDR(n)                                                    (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0X1CC + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_OFFS(n)                                                    (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0X1CC + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_RMSK                                                             0x1fu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_MAXn                                                               13u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_SELF_TEST_SDATA1_STATUS_CHAIN_BMSK                               0x10u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_SELF_TEST_SDATA1_STATUS_CHAIN_SHFT                                  4u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_SELF_TEST_SDATA0_STATUS_CHAIN_BMSK                                0x8u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_SELF_TEST_SDATA0_STATUS_CHAIN_SHFT                                  3u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_SELF_TEST_SENA_STATUS_CHAIN_BMSK                                  0x4u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_SELF_TEST_SENA_STATUS_CHAIN_SHFT                                    2u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_SELF_TEST_SMODE1_STATUS_CHAIN_BMSK                                0x2u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_SELF_TEST_SMODE1_STATUS_CHAIN_SHFT                                  1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_SELF_TEST_SMODE0_STATUS_CHAIN_BMSK                                0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SELF_TEST_STATUS_CHAINn_SELF_TEST_SMODE0_STATUS_CHAIN_SHFT                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_DISABLE_SENSOR_STATUS_ADDR                                                         (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x210u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_DISABLE_SENSOR_STATUS_OFFS                                                         (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x210u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_DISABLE_SENSOR_STATUS_RMSK                                                            0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_DISABLE_SENSOR_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_DISABLE_SENSOR_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_DISABLE_SENSOR_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_DISABLE_SENSOR_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_DISABLE_SENSOR_STATUS_VSENSE_SENSOR_DISABLE_SENSOR_STATUS_BMSK                        0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_DISABLE_SENSOR_STATUS_VSENSE_SENSOR_DISABLE_SENSOR_STATUS_SHFT                              0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_POWER_DOWN_STATUS_ADDR                                                             (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x214u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_POWER_DOWN_STATUS_OFFS                                                             (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x214u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_POWER_DOWN_STATUS_RMSK                                                                0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_POWER_DOWN_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_POWER_DOWN_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_POWER_DOWN_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_POWER_DOWN_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_POWER_DOWN_STATUS_VSENSE_SENSOR_POWER_DOWN_STATUS_BMSK                                0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_POWER_DOWN_STATUS_VSENSE_SENSOR_POWER_DOWN_STATUS_SHFT                                      0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_CPRF_ENABLE_ADDR                                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x220u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_CPRF_ENABLE_OFFS                                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x220u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_CPRF_ENABLE_RMSK                                                                              0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_CPRF_ENABLE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_CPRF_ENABLE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_CPRF_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_CPRF_ENABLE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_CPRF_ENABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_CPRF_ENABLE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_CPRF_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_CPRF_ENABLE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_CPRF_ENABLE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_CPRF_ENABLE_CX_ENABLE_BMSK                                                                    0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_CPRF_ENABLE_CX_ENABLE_SHFT                                                                      0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_MIN_SUPPORTED_MODE_ADDR                                                                (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x224u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_MIN_SUPPORTED_MODE_OFFS                                                                (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x224u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_MIN_SUPPORTED_MODE_RMSK                                                                       0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_MIN_SUPPORTED_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_MIN_SUPPORTED_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_MIN_SUPPORTED_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_MIN_SUPPORTED_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_MIN_SUPPORTED_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_MIN_SUPPORTED_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_MIN_SUPPORTED_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_MIN_SUPPORTED_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_MIN_SUPPORTED_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_MIN_SUPPORTED_MODE_CX_MODE_BMSK                                                               0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_MIN_SUPPORTED_MODE_CX_MODE_SHFT                                                                 0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_CURR_MODE_SEL_ADDR                                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x228u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_CURR_MODE_SEL_OFFS                                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x228u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_CURR_MODE_SEL_RMSK                                                                            0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_CURR_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_CURR_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_CURR_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_CURR_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_CURR_MODE_SEL_CX_CURR_MODE_BMSK                                                               0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_CURR_MODE_SEL_CX_CURR_MODE_SHFT                                                                 0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PREV_MODE_SEL_ADDR                                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x22cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PREV_MODE_SEL_OFFS                                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x22cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PREV_MODE_SEL_RMSK                                                                            0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PREV_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PREV_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PREV_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PREV_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PREV_MODE_SEL_CX_PREV_MODE_BMSK                                                               0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PREV_MODE_SEL_CX_PREV_MODE_SHFT                                                                 0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_RAIL_STATUS_ADDR                                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x230u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_RAIL_STATUS_OFFS                                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x230u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_RAIL_STATUS_RMSK                                                                              0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_RAIL_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_RAIL_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_RAIL_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_RAIL_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_RAIL_STATUS_CX_RAIL_IS_UP_BMSK                                                                0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_RAIL_STATUS_CX_RAIL_IS_UP_SHFT                                                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PC_MODE_ADDR                                                                           (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x234u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PC_MODE_OFFS                                                                           (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x234u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PC_MODE_RMSK                                                                                  0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PC_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PC_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PC_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PC_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PC_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PC_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PC_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PC_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PC_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PC_MODE_CX_PC_MODE_BMSK                                                                       0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PC_MODE_CX_PC_MODE_SHFT                                                                         0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_CX_ADDR                                                      (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x238u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_CX_OFFS                                                      (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x238u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_CX_RMSK                                                          0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_CX_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_CX_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_CX_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_CX_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_CX_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_CX_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_CX_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_CX_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_CX_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_CX_POST_COLLAPSE_CNTR_VAL_CX_BMSK                                0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_CX_POST_COLLAPSE_CNTR_VAL_CX_SHFT                                     0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PU_INIT_MODE_ADDR                                                                      (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x23cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PU_INIT_MODE_OFFS                                                                      (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x23cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PU_INIT_MODE_RMSK                                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PU_INIT_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PU_INIT_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PU_INIT_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PU_INIT_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PU_INIT_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PU_INIT_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PU_INIT_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PU_INIT_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PU_INIT_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PU_INIT_MODE_CX_PU_INIT_MODE_BMSK                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CX_PU_INIT_MODE_CX_PU_INIT_MODE_SHFT                                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_CPRF_ENABLE_ADDR                                                                      (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x240u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_CPRF_ENABLE_OFFS                                                                      (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x240u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_CPRF_ENABLE_RMSK                                                                             0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_CPRF_ENABLE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_CPRF_ENABLE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_CPRF_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_CPRF_ENABLE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_CPRF_ENABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_CPRF_ENABLE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_CPRF_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_CPRF_ENABLE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_CPRF_ENABLE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_CPRF_ENABLE_MXA_ENABLE_BMSK                                                                  0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_CPRF_ENABLE_MXA_ENABLE_SHFT                                                                    0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_MIN_SUPPORTED_MODE_ADDR                                                               (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x244u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_MIN_SUPPORTED_MODE_OFFS                                                               (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x244u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_MIN_SUPPORTED_MODE_RMSK                                                                      0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_MIN_SUPPORTED_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_MIN_SUPPORTED_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_MIN_SUPPORTED_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_MIN_SUPPORTED_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_MIN_SUPPORTED_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_MIN_SUPPORTED_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_MIN_SUPPORTED_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_MIN_SUPPORTED_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_MIN_SUPPORTED_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_MIN_SUPPORTED_MODE_MXA_MODE_BMSK                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_MIN_SUPPORTED_MODE_MXA_MODE_SHFT                                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_CURR_MODE_SEL_ADDR                                                                    (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x248u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_CURR_MODE_SEL_OFFS                                                                    (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x248u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_CURR_MODE_SEL_RMSK                                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_CURR_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_CURR_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_CURR_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_CURR_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_CURR_MODE_SEL_MXA_CURR_MODE_BMSK                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_CURR_MODE_SEL_MXA_CURR_MODE_SHFT                                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PREV_MODE_SEL_ADDR                                                                    (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x24cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PREV_MODE_SEL_OFFS                                                                    (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x24cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PREV_MODE_SEL_RMSK                                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PREV_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PREV_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PREV_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PREV_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PREV_MODE_SEL_MXA_PREV_MODE_BMSK                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PREV_MODE_SEL_MXA_PREV_MODE_SHFT                                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_RAIL_STATUS_ADDR                                                                      (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x250u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_RAIL_STATUS_OFFS                                                                      (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x250u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_RAIL_STATUS_RMSK                                                                             0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_RAIL_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_RAIL_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_RAIL_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_RAIL_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_RAIL_STATUS_MXA_RAIL_IS_UP_BMSK                                                              0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_RAIL_STATUS_MXA_RAIL_IS_UP_SHFT                                                                0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PC_MODE_ADDR                                                                          (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x254u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PC_MODE_OFFS                                                                          (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x254u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PC_MODE_RMSK                                                                                 0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PC_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PC_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PC_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PC_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PC_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PC_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PC_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PC_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PC_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PC_MODE_MXA_PC_MODE_BMSK                                                                     0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PC_MODE_MXA_PC_MODE_SHFT                                                                       0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXA_ADDR                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x258u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXA_OFFS                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x258u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXA_RMSK                                                         0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXA_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXA_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXA_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXA_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXA_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXA_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXA_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXA_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXA_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXA_POST_COLLAPSE_CNTR_VAL_MXA_BMSK                              0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXA_POST_COLLAPSE_CNTR_VAL_MXA_SHFT                                   0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PU_INIT_MODE_ADDR                                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x25cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PU_INIT_MODE_OFFS                                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x25cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PU_INIT_MODE_RMSK                                                                            0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PU_INIT_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PU_INIT_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PU_INIT_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PU_INIT_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PU_INIT_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PU_INIT_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PU_INIT_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PU_INIT_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PU_INIT_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PU_INIT_MODE_MXA_PU_INIT_MODE_BMSK                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXA_PU_INIT_MODE_MXA_PU_INIT_MODE_SHFT                                                             0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_CPRF_ENABLE_ADDR                                                                      (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x260u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_CPRF_ENABLE_OFFS                                                                      (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x260u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_CPRF_ENABLE_RMSK                                                                             0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_CPRF_ENABLE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_CPRF_ENABLE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_CPRF_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_CPRF_ENABLE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_CPRF_ENABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_CPRF_ENABLE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_CPRF_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_CPRF_ENABLE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_CPRF_ENABLE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_CPRF_ENABLE_DDR_ENABLE_BMSK                                                                  0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_CPRF_ENABLE_DDR_ENABLE_SHFT                                                                    0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_MIN_SUPPORTED_MODE_ADDR                                                               (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x264u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_MIN_SUPPORTED_MODE_OFFS                                                               (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x264u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_MIN_SUPPORTED_MODE_RMSK                                                                      0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_MIN_SUPPORTED_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_MIN_SUPPORTED_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_MIN_SUPPORTED_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_MIN_SUPPORTED_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_MIN_SUPPORTED_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_MIN_SUPPORTED_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_MIN_SUPPORTED_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_MIN_SUPPORTED_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_MIN_SUPPORTED_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_MIN_SUPPORTED_MODE_DDR_MODE_BMSK                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_MIN_SUPPORTED_MODE_DDR_MODE_SHFT                                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_CURR_MODE_SEL_ADDR                                                                    (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x268u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_CURR_MODE_SEL_OFFS                                                                    (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x268u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_CURR_MODE_SEL_RMSK                                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_CURR_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_CURR_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_CURR_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_CURR_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_CURR_MODE_SEL_DDR_CURR_MODE_BMSK                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_CURR_MODE_SEL_DDR_CURR_MODE_SHFT                                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PREV_MODE_SEL_ADDR                                                                    (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x26cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PREV_MODE_SEL_OFFS                                                                    (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x26cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PREV_MODE_SEL_RMSK                                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PREV_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PREV_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PREV_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PREV_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PREV_MODE_SEL_DDR_PREV_MODE_BMSK                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PREV_MODE_SEL_DDR_PREV_MODE_SHFT                                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_RAIL_STATUS_ADDR                                                                      (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x270u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_RAIL_STATUS_OFFS                                                                      (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x270u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_RAIL_STATUS_RMSK                                                                             0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_RAIL_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_RAIL_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_RAIL_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_RAIL_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_RAIL_STATUS_DDR_RAIL_IS_UP_BMSK                                                              0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_RAIL_STATUS_DDR_RAIL_IS_UP_SHFT                                                                0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PC_MODE_ADDR                                                                          (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x274u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PC_MODE_OFFS                                                                          (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x274u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PC_MODE_RMSK                                                                                 0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PC_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PC_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PC_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PC_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PC_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PC_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PC_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PC_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PC_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PC_MODE_DDR_PC_MODE_BMSK                                                                     0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PC_MODE_DDR_PC_MODE_SHFT                                                                       0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_DDR_ADDR                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x278u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_DDR_OFFS                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x278u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_DDR_RMSK                                                         0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_DDR_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_DDR_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_DDR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_DDR_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_DDR_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_DDR_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_DDR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_DDR_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_DDR_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_DDR_POST_COLLAPSE_CNTR_VAL_DDR_BMSK                              0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_DDR_POST_COLLAPSE_CNTR_VAL_DDR_SHFT                                   0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PU_INIT_MODE_ADDR                                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x27cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PU_INIT_MODE_OFFS                                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x27cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PU_INIT_MODE_RMSK                                                                            0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PU_INIT_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PU_INIT_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PU_INIT_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PU_INIT_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PU_INIT_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PU_INIT_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PU_INIT_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PU_INIT_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PU_INIT_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PU_INIT_MODE_DDR_PU_INIT_MODE_BMSK                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_DDR_PU_INIT_MODE_DDR_PU_INIT_MODE_SHFT                                                             0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_CPRF_ENABLE_ADDR                                                                   (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x280u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_CPRF_ENABLE_OFFS                                                                   (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x280u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_CPRF_ENABLE_RMSK                                                                          0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_CPRF_ENABLE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_CPRF_ENABLE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_CPRF_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_CPRF_ENABLE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_CPRF_ENABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_CPRF_ENABLE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_CPRF_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_CPRF_ENABLE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_CPRF_ENABLE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_CPRF_ENABLE_SSC_CX_ENABLE_BMSK                                                            0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_CPRF_ENABLE_SSC_CX_ENABLE_SHFT                                                              0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_MIN_SUPPORTED_MODE_ADDR                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x284u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_MIN_SUPPORTED_MODE_OFFS                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x284u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_MIN_SUPPORTED_MODE_RMSK                                                                   0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_MIN_SUPPORTED_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_MIN_SUPPORTED_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_MIN_SUPPORTED_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_MIN_SUPPORTED_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_MIN_SUPPORTED_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_MIN_SUPPORTED_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_MIN_SUPPORTED_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_MIN_SUPPORTED_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_MIN_SUPPORTED_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_MIN_SUPPORTED_MODE_SSC_CX_MODE_BMSK                                                       0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_MIN_SUPPORTED_MODE_SSC_CX_MODE_SHFT                                                         0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_CURR_MODE_SEL_ADDR                                                                 (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x288u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_CURR_MODE_SEL_OFFS                                                                 (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x288u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_CURR_MODE_SEL_RMSK                                                                        0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_CURR_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_CURR_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_CURR_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_CURR_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_CURR_MODE_SEL_SSC_CX_CURR_MODE_BMSK                                                       0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_CURR_MODE_SEL_SSC_CX_CURR_MODE_SHFT                                                         0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PREV_MODE_SEL_ADDR                                                                 (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x28cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PREV_MODE_SEL_OFFS                                                                 (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x28cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PREV_MODE_SEL_RMSK                                                                        0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PREV_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PREV_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PREV_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PREV_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PREV_MODE_SEL_SSC_CX_PREV_MODE_BMSK                                                       0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PREV_MODE_SEL_SSC_CX_PREV_MODE_SHFT                                                         0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_RAIL_STATUS_ADDR                                                                   (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x290u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_RAIL_STATUS_OFFS                                                                   (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x290u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_RAIL_STATUS_RMSK                                                                          0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_RAIL_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_RAIL_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_RAIL_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_RAIL_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_RAIL_STATUS_SSC_CX_RAIL_IS_UP_BMSK                                                        0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_RAIL_STATUS_SSC_CX_RAIL_IS_UP_SHFT                                                          0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PC_MODE_ADDR                                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x294u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PC_MODE_OFFS                                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x294u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PC_MODE_RMSK                                                                              0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PC_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PC_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PC_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PC_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PC_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PC_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PC_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PC_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PC_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PC_MODE_SSC_CX_PC_MODE_BMSK                                                               0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PC_MODE_SSC_CX_PC_MODE_SHFT                                                                 0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_CX_ADDR                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x298u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_CX_OFFS                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x298u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_CX_RMSK                                                      0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_CX_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_CX_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_CX_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_CX_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_CX_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_CX_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_CX_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_CX_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_CX_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_CX_POST_COLLAPSE_CNTR_VAL_SSC_CX_BMSK                        0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_CX_POST_COLLAPSE_CNTR_VAL_SSC_CX_SHFT                             0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PU_INIT_MODE_ADDR                                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x29cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PU_INIT_MODE_OFFS                                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x29cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PU_INIT_MODE_RMSK                                                                         0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PU_INIT_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PU_INIT_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PU_INIT_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PU_INIT_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PU_INIT_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PU_INIT_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PU_INIT_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PU_INIT_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PU_INIT_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PU_INIT_MODE_SSC_CX_PU_INIT_MODE_BMSK                                                     0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_CX_PU_INIT_MODE_SSC_CX_PU_INIT_MODE_SHFT                                                       0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_CPRF_ENABLE_ADDR                                                                   (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x2a0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_CPRF_ENABLE_OFFS                                                                   (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2a0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_CPRF_ENABLE_RMSK                                                                          0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_CPRF_ENABLE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_CPRF_ENABLE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_CPRF_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_CPRF_ENABLE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_CPRF_ENABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_CPRF_ENABLE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_CPRF_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_CPRF_ENABLE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_CPRF_ENABLE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_CPRF_ENABLE_SSC_MX_ENABLE_BMSK                                                            0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_CPRF_ENABLE_SSC_MX_ENABLE_SHFT                                                              0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_MIN_SUPPORTED_MODE_ADDR                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x2a4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_MIN_SUPPORTED_MODE_OFFS                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2a4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_MIN_SUPPORTED_MODE_RMSK                                                                   0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_MIN_SUPPORTED_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_MIN_SUPPORTED_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_MIN_SUPPORTED_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_MIN_SUPPORTED_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_MIN_SUPPORTED_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_MIN_SUPPORTED_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_MIN_SUPPORTED_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_MIN_SUPPORTED_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_MIN_SUPPORTED_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_MIN_SUPPORTED_MODE_SSC_MX_MODE_BMSK                                                       0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_MIN_SUPPORTED_MODE_SSC_MX_MODE_SHFT                                                         0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_CURR_MODE_SEL_ADDR                                                                 (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x2a8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_CURR_MODE_SEL_OFFS                                                                 (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2a8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_CURR_MODE_SEL_RMSK                                                                        0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_CURR_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_CURR_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_CURR_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_CURR_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_CURR_MODE_SEL_SSC_MX_CURR_MODE_BMSK                                                       0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_CURR_MODE_SEL_SSC_MX_CURR_MODE_SHFT                                                         0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PREV_MODE_SEL_ADDR                                                                 (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x2acu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PREV_MODE_SEL_OFFS                                                                 (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2acu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PREV_MODE_SEL_RMSK                                                                        0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PREV_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PREV_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PREV_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PREV_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PREV_MODE_SEL_SSC_MX_PREV_MODE_BMSK                                                       0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PREV_MODE_SEL_SSC_MX_PREV_MODE_SHFT                                                         0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_RAIL_STATUS_ADDR                                                                   (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x2b0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_RAIL_STATUS_OFFS                                                                   (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2b0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_RAIL_STATUS_RMSK                                                                          0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_RAIL_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_RAIL_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_RAIL_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_RAIL_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_RAIL_STATUS_SSC_MX_RAIL_IS_UP_BMSK                                                        0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_RAIL_STATUS_SSC_MX_RAIL_IS_UP_SHFT                                                          0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PC_MODE_ADDR                                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x2b4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PC_MODE_OFFS                                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2b4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PC_MODE_RMSK                                                                              0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PC_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PC_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PC_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PC_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PC_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PC_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PC_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PC_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PC_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PC_MODE_SSC_MX_PC_MODE_BMSK                                                               0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PC_MODE_SSC_MX_PC_MODE_SHFT                                                                 0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_MX_ADDR                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x2b8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_MX_OFFS                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2b8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_MX_RMSK                                                      0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_MX_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_MX_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_MX_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_MX_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_MX_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_MX_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_MX_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_MX_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_MX_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_MX_POST_COLLAPSE_CNTR_VAL_SSC_MX_BMSK                        0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_SSC_MX_POST_COLLAPSE_CNTR_VAL_SSC_MX_SHFT                             0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PU_INIT_MODE_ADDR                                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x2bcu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PU_INIT_MODE_OFFS                                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2bcu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PU_INIT_MODE_RMSK                                                                         0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PU_INIT_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PU_INIT_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PU_INIT_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PU_INIT_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PU_INIT_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PU_INIT_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PU_INIT_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PU_INIT_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PU_INIT_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PU_INIT_MODE_SSC_MX_PU_INIT_MODE_BMSK                                                     0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SSC_MX_PU_INIT_MODE_SSC_MX_PU_INIT_MODE_SHFT                                                       0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_CPRF_ENABLE_ADDR                                                                      (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x2c0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_CPRF_ENABLE_OFFS                                                                      (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2c0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_CPRF_ENABLE_RMSK                                                                             0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_CPRF_ENABLE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_CPRF_ENABLE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_CPRF_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_CPRF_ENABLE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_CPRF_ENABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_CPRF_ENABLE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_CPRF_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_CPRF_ENABLE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_CPRF_ENABLE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_CPRF_ENABLE_GFX_ENABLE_BMSK                                                                  0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_CPRF_ENABLE_GFX_ENABLE_SHFT                                                                    0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_MIN_SUPPORTED_MODE_ADDR                                                               (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x2c4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_MIN_SUPPORTED_MODE_OFFS                                                               (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2c4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_MIN_SUPPORTED_MODE_RMSK                                                                      0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_MIN_SUPPORTED_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_MIN_SUPPORTED_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_MIN_SUPPORTED_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_MIN_SUPPORTED_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_MIN_SUPPORTED_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_MIN_SUPPORTED_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_MIN_SUPPORTED_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_MIN_SUPPORTED_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_MIN_SUPPORTED_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_MIN_SUPPORTED_MODE_GFX_MODE_BMSK                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_MIN_SUPPORTED_MODE_GFX_MODE_SHFT                                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_CURR_MODE_SEL_ADDR                                                                    (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x2c8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_CURR_MODE_SEL_OFFS                                                                    (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2c8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_CURR_MODE_SEL_RMSK                                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_CURR_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_CURR_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_CURR_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_CURR_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_CURR_MODE_SEL_GFX_CURR_MODE_BMSK                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_CURR_MODE_SEL_GFX_CURR_MODE_SHFT                                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PREV_MODE_SEL_ADDR                                                                    (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x2ccu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PREV_MODE_SEL_OFFS                                                                    (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2ccu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PREV_MODE_SEL_RMSK                                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PREV_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PREV_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PREV_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PREV_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PREV_MODE_SEL_GFX_PREV_MODE_BMSK                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PREV_MODE_SEL_GFX_PREV_MODE_SHFT                                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_RAIL_STATUS_ADDR                                                                      (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x2d0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_RAIL_STATUS_OFFS                                                                      (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2d0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_RAIL_STATUS_RMSK                                                                             0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_RAIL_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_RAIL_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_RAIL_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_RAIL_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_RAIL_STATUS_GFX_RAIL_IS_UP_BMSK                                                              0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_RAIL_STATUS_GFX_RAIL_IS_UP_SHFT                                                                0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PC_MODE_ADDR                                                                          (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x2d4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PC_MODE_OFFS                                                                          (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2d4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PC_MODE_RMSK                                                                                 0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PC_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PC_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PC_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PC_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PC_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PC_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PC_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PC_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PC_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PC_MODE_GFX_PC_MODE_BMSK                                                                     0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PC_MODE_GFX_PC_MODE_SHFT                                                                       0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_GFX_ADDR                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x2d8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_GFX_OFFS                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2d8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_GFX_RMSK                                                         0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_GFX_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_GFX_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_GFX_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_GFX_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_GFX_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_GFX_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_GFX_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_GFX_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_GFX_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_GFX_POST_COLLAPSE_CNTR_VAL_GFX_BMSK                              0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_GFX_POST_COLLAPSE_CNTR_VAL_GFX_SHFT                                   0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PU_INIT_MODE_ADDR                                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x2dcu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PU_INIT_MODE_OFFS                                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2dcu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PU_INIT_MODE_RMSK                                                                            0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PU_INIT_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PU_INIT_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PU_INIT_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PU_INIT_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PU_INIT_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PU_INIT_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PU_INIT_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PU_INIT_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PU_INIT_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PU_INIT_MODE_GFX_PU_INIT_MODE_BMSK                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_GFX_PU_INIT_MODE_GFX_PU_INIT_MODE_SHFT                                                             0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_CPRF_ENABLE_ADDR                                                                   (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x2e0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_CPRF_ENABLE_OFFS                                                                   (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2e0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_CPRF_ENABLE_RMSK                                                                          0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_CPRF_ENABLE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_CPRF_ENABLE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_CPRF_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_CPRF_ENABLE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_CPRF_ENABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_CPRF_ENABLE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_CPRF_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_CPRF_ENABLE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_CPRF_ENABLE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_CPRF_ENABLE_NSP_CX_ENABLE_BMSK                                                            0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_CPRF_ENABLE_NSP_CX_ENABLE_SHFT                                                              0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_MIN_SUPPORTED_MODE_ADDR                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x2e4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_MIN_SUPPORTED_MODE_OFFS                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2e4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_MIN_SUPPORTED_MODE_RMSK                                                                   0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_MIN_SUPPORTED_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_MIN_SUPPORTED_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_MIN_SUPPORTED_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_MIN_SUPPORTED_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_MIN_SUPPORTED_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_MIN_SUPPORTED_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_MIN_SUPPORTED_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_MIN_SUPPORTED_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_MIN_SUPPORTED_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_MIN_SUPPORTED_MODE_NSP_CX_MODE_BMSK                                                       0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_MIN_SUPPORTED_MODE_NSP_CX_MODE_SHFT                                                         0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_CURR_MODE_SEL_ADDR                                                                 (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x2e8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_CURR_MODE_SEL_OFFS                                                                 (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2e8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_CURR_MODE_SEL_RMSK                                                                        0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_CURR_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_CURR_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_CURR_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_CURR_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_CURR_MODE_SEL_NSP_CX_CURR_MODE_BMSK                                                       0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_CURR_MODE_SEL_NSP_CX_CURR_MODE_SHFT                                                         0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PREV_MODE_SEL_ADDR                                                                 (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x2ecu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PREV_MODE_SEL_OFFS                                                                 (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2ecu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PREV_MODE_SEL_RMSK                                                                        0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PREV_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PREV_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PREV_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PREV_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PREV_MODE_SEL_NSP_CX_PREV_MODE_BMSK                                                       0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PREV_MODE_SEL_NSP_CX_PREV_MODE_SHFT                                                         0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_RAIL_STATUS_ADDR                                                                   (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x2f0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_RAIL_STATUS_OFFS                                                                   (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2f0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_RAIL_STATUS_RMSK                                                                          0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_RAIL_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_RAIL_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_RAIL_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_RAIL_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_RAIL_STATUS_NSP_CX_RAIL_IS_UP_BMSK                                                        0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_RAIL_STATUS_NSP_CX_RAIL_IS_UP_SHFT                                                          0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PC_MODE_ADDR                                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x2f4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PC_MODE_OFFS                                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2f4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PC_MODE_RMSK                                                                              0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PC_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PC_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PC_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PC_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PC_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PC_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PC_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PC_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PC_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PC_MODE_NSP_CX_PC_MODE_BMSK                                                               0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PC_MODE_NSP_CX_PC_MODE_SHFT                                                                 0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP_CX_ADDR                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x2f8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP_CX_OFFS                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2f8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP_CX_RMSK                                                      0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP_CX_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP_CX_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP_CX_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP_CX_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP_CX_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP_CX_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP_CX_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP_CX_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP_CX_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP_CX_POST_COLLAPSE_CNTR_VAL_NSP_CX_BMSK                        0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP_CX_POST_COLLAPSE_CNTR_VAL_NSP_CX_SHFT                             0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PU_INIT_MODE_ADDR                                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x2fcu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PU_INIT_MODE_OFFS                                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x2fcu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PU_INIT_MODE_RMSK                                                                         0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PU_INIT_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PU_INIT_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PU_INIT_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PU_INIT_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PU_INIT_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PU_INIT_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PU_INIT_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PU_INIT_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PU_INIT_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PU_INIT_MODE_NSP_CX_PU_INIT_MODE_BMSK                                                     0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP_CX_PU_INIT_MODE_NSP_CX_PU_INIT_MODE_SHFT                                                       0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_CPRF_ENABLE_ADDR                                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x300u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_CPRF_ENABLE_OFFS                                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x300u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_CPRF_ENABLE_RMSK                                                                         0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_CPRF_ENABLE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_CPRF_ENABLE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_CPRF_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_CPRF_ENABLE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_CPRF_ENABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_CPRF_ENABLE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_CPRF_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_CPRF_ENABLE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_CPRF_ENABLE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_CPRF_ENABLE_NSP2_CX_ENABLE_BMSK                                                          0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_CPRF_ENABLE_NSP2_CX_ENABLE_SHFT                                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_MIN_SUPPORTED_MODE_ADDR                                                           (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x304u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_MIN_SUPPORTED_MODE_OFFS                                                           (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x304u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_MIN_SUPPORTED_MODE_RMSK                                                                  0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_MIN_SUPPORTED_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_MIN_SUPPORTED_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_MIN_SUPPORTED_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_MIN_SUPPORTED_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_MIN_SUPPORTED_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_MIN_SUPPORTED_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_MIN_SUPPORTED_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_MIN_SUPPORTED_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_MIN_SUPPORTED_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_MIN_SUPPORTED_MODE_NSP2_CX_MODE_BMSK                                                     0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_MIN_SUPPORTED_MODE_NSP2_CX_MODE_SHFT                                                       0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_CURR_MODE_SEL_ADDR                                                                (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x308u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_CURR_MODE_SEL_OFFS                                                                (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x308u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_CURR_MODE_SEL_RMSK                                                                       0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_CURR_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_CURR_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_CURR_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_CURR_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_CURR_MODE_SEL_NSP2_CX_CURR_MODE_BMSK                                                     0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_CURR_MODE_SEL_NSP2_CX_CURR_MODE_SHFT                                                       0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PREV_MODE_SEL_ADDR                                                                (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x30cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PREV_MODE_SEL_OFFS                                                                (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x30cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PREV_MODE_SEL_RMSK                                                                       0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PREV_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PREV_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PREV_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PREV_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PREV_MODE_SEL_NSP2_CX_PREV_MODE_BMSK                                                     0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PREV_MODE_SEL_NSP2_CX_PREV_MODE_SHFT                                                       0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_RAIL_STATUS_ADDR                                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x310u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_RAIL_STATUS_OFFS                                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x310u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_RAIL_STATUS_RMSK                                                                         0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_RAIL_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_RAIL_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_RAIL_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_RAIL_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_RAIL_STATUS_NSP2_CX_RAIL_IS_UP_BMSK                                                      0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_RAIL_STATUS_NSP2_CX_RAIL_IS_UP_SHFT                                                        0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PC_MODE_ADDR                                                                      (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x314u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PC_MODE_OFFS                                                                      (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x314u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PC_MODE_RMSK                                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PC_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PC_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PC_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PC_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PC_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PC_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PC_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PC_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PC_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PC_MODE_NSP2_CX_PC_MODE_BMSK                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PC_MODE_NSP2_CX_PC_MODE_SHFT                                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP2_CX_ADDR                                                 (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x318u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP2_CX_OFFS                                                 (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x318u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP2_CX_RMSK                                                     0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP2_CX_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP2_CX_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP2_CX_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP2_CX_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP2_CX_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP2_CX_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP2_CX_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP2_CX_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP2_CX_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP2_CX_POST_COLLAPSE_CNTR_VAL_NSP2_CX_BMSK                      0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_NSP2_CX_POST_COLLAPSE_CNTR_VAL_NSP2_CX_SHFT                           0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PU_INIT_MODE_ADDR                                                                 (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x31cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PU_INIT_MODE_OFFS                                                                 (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x31cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PU_INIT_MODE_RMSK                                                                        0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PU_INIT_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PU_INIT_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PU_INIT_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PU_INIT_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PU_INIT_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PU_INIT_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PU_INIT_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PU_INIT_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PU_INIT_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PU_INIT_MODE_NSP2_CX_PU_INIT_MODE_BMSK                                                   0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_NSP2_CX_PU_INIT_MODE_NSP2_CX_PU_INIT_MODE_SHFT                                                     0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_CPRF_ENABLE_ADDR                                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x320u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_CPRF_ENABLE_OFFS                                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x320u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_CPRF_ENABLE_RMSK                                                                            0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_CPRF_ENABLE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_CPRF_ENABLE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_CPRF_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_CPRF_ENABLE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_CPRF_ENABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_CPRF_ENABLE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_CPRF_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_CPRF_ENABLE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_CPRF_ENABLE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_CPRF_ENABLE_MMCX_ENABLE_BMSK                                                                0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_CPRF_ENABLE_MMCX_ENABLE_SHFT                                                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_MIN_SUPPORTED_MODE_ADDR                                                              (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x324u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_MIN_SUPPORTED_MODE_OFFS                                                              (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x324u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_MIN_SUPPORTED_MODE_RMSK                                                                     0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_MIN_SUPPORTED_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_MIN_SUPPORTED_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_MIN_SUPPORTED_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_MIN_SUPPORTED_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_MIN_SUPPORTED_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_MIN_SUPPORTED_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_MIN_SUPPORTED_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_MIN_SUPPORTED_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_MIN_SUPPORTED_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_MIN_SUPPORTED_MODE_MMCX_MODE_BMSK                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_MIN_SUPPORTED_MODE_MMCX_MODE_SHFT                                                             0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_CURR_MODE_SEL_ADDR                                                                   (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x328u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_CURR_MODE_SEL_OFFS                                                                   (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x328u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_CURR_MODE_SEL_RMSK                                                                          0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_CURR_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_CURR_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_CURR_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_CURR_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_CURR_MODE_SEL_MMCX_CURR_MODE_BMSK                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_CURR_MODE_SEL_MMCX_CURR_MODE_SHFT                                                             0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PREV_MODE_SEL_ADDR                                                                   (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x32cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PREV_MODE_SEL_OFFS                                                                   (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x32cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PREV_MODE_SEL_RMSK                                                                          0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PREV_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PREV_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PREV_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PREV_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PREV_MODE_SEL_MMCX_PREV_MODE_BMSK                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PREV_MODE_SEL_MMCX_PREV_MODE_SHFT                                                             0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_RAIL_STATUS_ADDR                                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x330u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_RAIL_STATUS_OFFS                                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x330u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_RAIL_STATUS_RMSK                                                                            0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_RAIL_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_RAIL_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_RAIL_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_RAIL_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_RAIL_STATUS_MMCX_RAIL_IS_UP_BMSK                                                            0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_RAIL_STATUS_MMCX_RAIL_IS_UP_SHFT                                                              0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PC_MODE_ADDR                                                                         (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x334u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PC_MODE_OFFS                                                                         (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x334u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PC_MODE_RMSK                                                                                0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PC_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PC_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PC_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PC_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PC_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PC_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PC_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PC_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PC_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PC_MODE_MMCX_PC_MODE_BMSK                                                                   0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PC_MODE_MMCX_PC_MODE_SHFT                                                                     0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MMCX_ADDR                                                    (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x338u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MMCX_OFFS                                                    (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x338u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MMCX_RMSK                                                        0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MMCX_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MMCX_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MMCX_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MMCX_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MMCX_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MMCX_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MMCX_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MMCX_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MMCX_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MMCX_POST_COLLAPSE_CNTR_VAL_MMCX_BMSK                            0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MMCX_POST_COLLAPSE_CNTR_VAL_MMCX_SHFT                                 0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PU_INIT_MODE_ADDR                                                                    (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x33cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PU_INIT_MODE_OFFS                                                                    (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x33cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PU_INIT_MODE_RMSK                                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PU_INIT_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PU_INIT_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PU_INIT_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PU_INIT_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PU_INIT_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PU_INIT_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PU_INIT_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PU_INIT_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PU_INIT_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PU_INIT_MODE_MMCX_PU_INIT_MODE_BMSK                                                         0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MMCX_PU_INIT_MODE_MMCX_PU_INIT_MODE_SHFT                                                           0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_CPRF_ENABLE_ADDR                                                                      (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x340u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_CPRF_ENABLE_OFFS                                                                      (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x340u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_CPRF_ENABLE_RMSK                                                                             0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_CPRF_ENABLE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_CPRF_ENABLE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_CPRF_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_CPRF_ENABLE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_CPRF_ENABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_CPRF_ENABLE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_CPRF_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_CPRF_ENABLE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_CPRF_ENABLE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_CPRF_ENABLE_MXC_ENABLE_BMSK                                                                  0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_CPRF_ENABLE_MXC_ENABLE_SHFT                                                                    0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_MIN_SUPPORTED_MODE_ADDR                                                               (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x344u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_MIN_SUPPORTED_MODE_OFFS                                                               (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x344u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_MIN_SUPPORTED_MODE_RMSK                                                                      0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_MIN_SUPPORTED_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_MIN_SUPPORTED_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_MIN_SUPPORTED_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_MIN_SUPPORTED_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_MIN_SUPPORTED_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_MIN_SUPPORTED_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_MIN_SUPPORTED_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_MIN_SUPPORTED_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_MIN_SUPPORTED_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_MIN_SUPPORTED_MODE_MXC_MODE_BMSK                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_MIN_SUPPORTED_MODE_MXC_MODE_SHFT                                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_CURR_MODE_SEL_ADDR                                                                    (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x348u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_CURR_MODE_SEL_OFFS                                                                    (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x348u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_CURR_MODE_SEL_RMSK                                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_CURR_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_CURR_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_CURR_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_CURR_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_CURR_MODE_SEL_MXC_CURR_MODE_BMSK                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_CURR_MODE_SEL_MXC_CURR_MODE_SHFT                                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PREV_MODE_SEL_ADDR                                                                    (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x34cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PREV_MODE_SEL_OFFS                                                                    (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x34cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PREV_MODE_SEL_RMSK                                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PREV_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PREV_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PREV_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PREV_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PREV_MODE_SEL_MXC_PREV_MODE_BMSK                                                             0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PREV_MODE_SEL_MXC_PREV_MODE_SHFT                                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_RAIL_STATUS_ADDR                                                                      (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x350u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_RAIL_STATUS_OFFS                                                                      (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x350u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_RAIL_STATUS_RMSK                                                                             0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_RAIL_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_RAIL_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_RAIL_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_RAIL_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_RAIL_STATUS_MXC_RAIL_IS_UP_BMSK                                                              0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_RAIL_STATUS_MXC_RAIL_IS_UP_SHFT                                                                0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PC_MODE_ADDR                                                                          (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x354u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PC_MODE_OFFS                                                                          (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x354u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PC_MODE_RMSK                                                                                 0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PC_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PC_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PC_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PC_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PC_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PC_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PC_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PC_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PC_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PC_MODE_MXC_PC_MODE_BMSK                                                                     0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PC_MODE_MXC_PC_MODE_SHFT                                                                       0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXC_ADDR                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x358u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXC_OFFS                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x358u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXC_RMSK                                                         0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXC_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXC_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXC_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXC_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXC_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXC_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXC_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXC_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXC_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXC_POST_COLLAPSE_CNTR_VAL_MXC_BMSK                              0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_POST_COLLAPSE_CNTR_VAL_MXC_POST_COLLAPSE_CNTR_VAL_MXC_SHFT                                   0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PU_INIT_MODE_ADDR                                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x35cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PU_INIT_MODE_OFFS                                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x35cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PU_INIT_MODE_RMSK                                                                            0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PU_INIT_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PU_INIT_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PU_INIT_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PU_INIT_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PU_INIT_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PU_INIT_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PU_INIT_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PU_INIT_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PU_INIT_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PU_INIT_MODE_MXC_PU_INIT_MODE_BMSK                                                           0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_MXC_PU_INIT_MODE_MXC_PU_INIT_MODE_SHFT                                                             0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_CPRH_ENABLE_ADDR                                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x360u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_CPRH_ENABLE_OFFS                                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x360u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_CPRH_ENABLE_RMSK                                                                            0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_CPRH_ENABLE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_CPRH_ENABLE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_CPRH_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_CPRH_ENABLE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_CPRH_ENABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_CPRH_ENABLE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_CPRH_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_CPRH_ENABLE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_CPRH_ENABLE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_CPRH_ENABLE_APC0_ENABLE_BMSK                                                                0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_CPRH_ENABLE_APC0_ENABLE_SHFT                                                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_MIN_SUPPORTED_MODE_ADDR                                                              (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x364u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_MIN_SUPPORTED_MODE_OFFS                                                              (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x364u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_MIN_SUPPORTED_MODE_RMSK                                                                   0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_MIN_SUPPORTED_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_MIN_SUPPORTED_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_MIN_SUPPORTED_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_MIN_SUPPORTED_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_MIN_SUPPORTED_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_MIN_SUPPORTED_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_MIN_SUPPORTED_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_MIN_SUPPORTED_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_MIN_SUPPORTED_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_MIN_SUPPORTED_MODE_APC0_MODE_BMSK                                                         0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_MIN_SUPPORTED_MODE_APC0_MODE_SHFT                                                             0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_CURR_MODE_SEL_ADDR                                                                   (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x368u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_CURR_MODE_SEL_OFFS                                                                   (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x368u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_CURR_MODE_SEL_RMSK                                                                        0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_CURR_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_CURR_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_CURR_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_CURR_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_CURR_MODE_SEL_APC0_CURR_MODE_BMSK                                                         0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_CURR_MODE_SEL_APC0_CURR_MODE_SHFT                                                             0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PREV_MODE_SEL_ADDR                                                                   (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x36cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PREV_MODE_SEL_OFFS                                                                   (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x36cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PREV_MODE_SEL_RMSK                                                                        0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PREV_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PREV_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PREV_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PREV_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PREV_MODE_SEL_APC0_PREV_MODE_BMSK                                                         0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PREV_MODE_SEL_APC0_PREV_MODE_SHFT                                                             0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_RAIL_STATUS_ADDR                                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x370u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_RAIL_STATUS_OFFS                                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x370u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_RAIL_STATUS_RMSK                                                                            0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_RAIL_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_RAIL_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_RAIL_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_RAIL_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_RAIL_STATUS_APC0_RAIL_IS_UP_BMSK                                                            0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_RAIL_STATUS_APC0_RAIL_IS_UP_SHFT                                                              0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PC_MODE_ADDR                                                                         (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x374u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PC_MODE_OFFS                                                                         (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x374u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PC_MODE_RMSK                                                                              0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PC_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PC_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PC_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PC_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PC_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PC_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PC_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PC_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PC_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PC_MODE_APC0_PC_MODE_BMSK                                                                 0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PC_MODE_APC0_PC_MODE_SHFT                                                                     0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PU_INIT_MODE_ADDR                                                                    (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x378u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PU_INIT_MODE_OFFS                                                                    (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x378u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PU_INIT_MODE_RMSK                                                                         0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PU_INIT_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PU_INIT_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PU_INIT_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PU_INIT_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PU_INIT_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PU_INIT_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PU_INIT_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PU_INIT_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PU_INIT_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PU_INIT_MODE_APC0_PU_INIT_MODE_BMSK                                                       0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_PU_INIT_MODE_APC0_PU_INIT_MODE_SHFT                                                           0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_CPRH_ENABLE_ADDR                                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x390u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_CPRH_ENABLE_OFFS                                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x390u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_CPRH_ENABLE_RMSK                                                                            0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_CPRH_ENABLE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_CPRH_ENABLE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_CPRH_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_CPRH_ENABLE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_CPRH_ENABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_CPRH_ENABLE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_CPRH_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_CPRH_ENABLE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_CPRH_ENABLE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_CPRH_ENABLE_APC1_ENABLE_BMSK                                                                0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_CPRH_ENABLE_APC1_ENABLE_SHFT                                                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_MIN_SUPPORTED_MODE_ADDR                                                              (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x394u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_MIN_SUPPORTED_MODE_OFFS                                                              (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x394u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_MIN_SUPPORTED_MODE_RMSK                                                                   0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_MIN_SUPPORTED_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_MIN_SUPPORTED_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_MIN_SUPPORTED_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_MIN_SUPPORTED_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_MIN_SUPPORTED_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_MIN_SUPPORTED_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_MIN_SUPPORTED_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_MIN_SUPPORTED_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_MIN_SUPPORTED_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_MIN_SUPPORTED_MODE_APC1_MODE_BMSK                                                         0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_MIN_SUPPORTED_MODE_APC1_MODE_SHFT                                                             0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_CURR_MODE_SEL_ADDR                                                                   (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x39cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_CURR_MODE_SEL_OFFS                                                                   (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x39cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_CURR_MODE_SEL_RMSK                                                                        0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_CURR_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_CURR_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_CURR_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_CURR_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_CURR_MODE_SEL_APC1_CURR_MODE_BMSK                                                         0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_CURR_MODE_SEL_APC1_CURR_MODE_SHFT                                                             0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PREV_MODE_SEL_ADDR                                                                   (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x3a0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PREV_MODE_SEL_OFFS                                                                   (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x3a0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PREV_MODE_SEL_RMSK                                                                        0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PREV_MODE_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PREV_MODE_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PREV_MODE_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PREV_MODE_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PREV_MODE_SEL_APC1_PREV_MODE_BMSK                                                         0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PREV_MODE_SEL_APC1_PREV_MODE_SHFT                                                             0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_RAIL_STATUS_ADDR                                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x3a4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_RAIL_STATUS_OFFS                                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x3a4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_RAIL_STATUS_RMSK                                                                            0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_RAIL_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_RAIL_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_RAIL_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_RAIL_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_RAIL_STATUS_APC1_RAIL_IS_UP_BMSK                                                            0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_RAIL_STATUS_APC1_RAIL_IS_UP_SHFT                                                              0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PC_MODE_ADDR                                                                         (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x3a8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PC_MODE_OFFS                                                                         (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x3a8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PC_MODE_RMSK                                                                              0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PC_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PC_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PC_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PC_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PC_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PC_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PC_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PC_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PC_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PC_MODE_APC1_PC_MODE_BMSK                                                                 0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PC_MODE_APC1_PC_MODE_SHFT                                                                     0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PU_INIT_MODE_ADDR                                                                    (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x3acu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PU_INIT_MODE_OFFS                                                                    (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x3acu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PU_INIT_MODE_RMSK                                                                         0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PU_INIT_MODE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PU_INIT_MODE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PU_INIT_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PU_INIT_MODE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PU_INIT_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PU_INIT_MODE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PU_INIT_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PU_INIT_MODE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PU_INIT_MODE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PU_INIT_MODE_APC1_PU_INIT_MODE_BMSK                                                       0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_PU_INIT_MODE_APC1_PU_INIT_MODE_SHFT                                                           0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SB_WM_EN_ADDR                                                                      (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x3c0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SB_WM_EN_OFFS                                                                      (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x3c0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SB_WM_EN_RMSK                                                                         0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SB_WM_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SB_WM_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SB_WM_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SB_WM_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SB_WM_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SB_WM_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SB_WM_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SB_WM_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SB_WM_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SB_WM_EN_VSENSE_SENSOR_SB_WM_EN_BMSK                                                  0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SB_WM_EN_VSENSE_SENSOR_SB_WM_EN_SHFT                                                        0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_ALARM_EN_ADDR                                                                      (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x3c4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_ALARM_EN_OFFS                                                                      (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x3c4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_ALARM_EN_RMSK                                                                         0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_ALARM_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_ALARM_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_ALARM_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_ALARM_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_ALARM_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_ALARM_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_ALARM_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_ALARM_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_ALARM_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_ALARM_EN_VSENSE_SENSOR_ALARM_EN_BMSK                                                  0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_ALARM_EN_VSENSE_SENSOR_ALARM_EN_SHFT                                                        0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_ADDR(n)                                                        (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0X3D0 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_OFFS(n)                                                        (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0X3D0 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_RMSK                                                               0x3fffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_MAXn                                                                   18u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_ADDR(n),val)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_ADDR(n),mask,val,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_INI(n))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_CLK_EN_VAL_BMSK                                       0x2000u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_CLK_EN_VAL_SHFT                                           13u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_POWER_DOWN_VAL_BMSK                                   0x1000u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_POWER_DOWN_VAL_SHFT                                       12u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_VS_ARES_VAL_BMSK                                       0x800u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_VS_ARES_VAL_SHFT                                          11u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_CLAMP_EN_OUT_VAL_BMSK                                  0x400u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_CLAMP_EN_OUT_VAL_SHFT                                     10u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_PLL_LOCK_DET_VAL_BMSK                                  0x200u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_PLL_LOCK_DET_VAL_SHFT                                      9u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_SUPPORTED_MODE_VAL_BMSK                                0x100u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_SUPPORTED_MODE_VAL_SHFT                                    8u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_RAIL_IS_UP_VAL_BMSK                                     0x80u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_RAIL_IS_UP_VAL_SHFT                                        7u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_CLK_EN_BMSK                                             0x40u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_CLK_EN_SHFT                                                6u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_POWER_DOWN_BMSK                                         0x20u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_POWER_DOWN_SHFT                                            5u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_VS_ARES_BMSK                                            0x10u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_VS_ARES_SHFT                                               4u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_CLAMP_EN_OUT_BMSK                                        0x8u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_CLAMP_EN_OUT_SHFT                                          3u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_PLL_LOCK_DET_BMSK                                        0x4u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_PLL_LOCK_DET_SHFT                                          2u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_SUPPORTED_MODE_BMSK                                      0x2u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_SUPPORTED_MODE_SHFT                                        1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_RAIL_IS_UP_BMSK                                          0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_SW_FORCE_FSM_SENSORn_SENSOR_FORCE_RAIL_IS_UP_SHFT                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA0_ADDR(n)                                                             (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0X424 + (0x8*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA0_OFFS(n)                                                             (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0X424 + (0x8*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA0_RMSK                                                                0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA0_MAXn                                                                        16u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA0_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA0_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA0_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA0_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA0_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA0_SENSOR_MAX_DATA_RD1_BMSK                                            0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA0_SENSOR_MAX_DATA_RD1_SHFT                                                    24u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA0_SENSOR_MIN_DATA_RD1_BMSK                                              0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA0_SENSOR_MIN_DATA_RD1_SHFT                                                    16u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA0_SENSOR_MAX_DATA_RD0_BMSK                                                0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA0_SENSOR_MAX_DATA_RD0_SHFT                                                     8u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA0_SENSOR_MIN_DATA_RD0_BMSK                                                  0xffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA0_SENSOR_MIN_DATA_RD0_SHFT                                                     0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA1_ADDR(n)                                                             (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0X428 + (0x8*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA1_OFFS(n)                                                             (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0X428 + (0x8*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA1_RMSK                                                                0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA1_MAXn                                                                        16u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA1_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA1_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA1_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA1_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA1_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA1_SENSOR_MAX_DATA_RD3_BMSK                                            0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA1_SENSOR_MAX_DATA_RD3_SHFT                                                    24u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA1_SENSOR_MIN_DATA_RD3_BMSK                                              0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA1_SENSOR_MIN_DATA_RD3_SHFT                                                    16u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA1_SENSOR_MAX_DATA_RD2_BMSK                                                0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA1_SENSOR_MAX_DATA_RD2_SHFT                                                     8u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA1_SENSOR_MIN_DATA_RD2_BMSK                                                  0xffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_DATA1_SENSOR_MIN_DATA_RD2_SHFT                                                     0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA0_ADDR                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x4d0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA0_OFFS                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x4d0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA0_RMSK                                                            0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA0_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA0_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA0_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA0_SENSOR_APC0_MAX_DATA_RD1_BMSK                                   0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA0_SENSOR_APC0_MAX_DATA_RD1_SHFT                                           24u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA0_SENSOR_APC0_MIN_DATA_RD1_BMSK                                     0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA0_SENSOR_APC0_MIN_DATA_RD1_SHFT                                           16u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA0_SENSOR_APC0_MAX_DATA_RD0_BMSK                                       0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA0_SENSOR_APC0_MAX_DATA_RD0_SHFT                                            8u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA0_SENSOR_APC0_MIN_DATA_RD0_BMSK                                         0xffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA0_SENSOR_APC0_MIN_DATA_RD0_SHFT                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA1_ADDR                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x4d4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA1_OFFS                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x4d4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA1_RMSK                                                            0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA1_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA1_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA1_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA1_SENSOR_APC0_MAX_DATA_RD3_BMSK                                   0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA1_SENSOR_APC0_MAX_DATA_RD3_SHFT                                           24u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA1_SENSOR_APC0_MIN_DATA_RD3_BMSK                                     0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA1_SENSOR_APC0_MIN_DATA_RD3_SHFT                                           16u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA1_SENSOR_APC0_MAX_DATA_RD2_BMSK                                       0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA1_SENSOR_APC0_MAX_DATA_RD2_SHFT                                            8u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA1_SENSOR_APC0_MIN_DATA_RD2_BMSK                                         0xffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA1_SENSOR_APC0_MIN_DATA_RD2_SHFT                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA2_ADDR                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x4d8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA2_OFFS                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x4d8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA2_RMSK                                                            0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA2_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA2_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA2_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA2_SENSOR_APC0_MAX_DATA_RD5_BMSK                                   0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA2_SENSOR_APC0_MAX_DATA_RD5_SHFT                                           24u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA2_SENSOR_APC0_MIN_DATA_RD5_BMSK                                     0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA2_SENSOR_APC0_MIN_DATA_RD5_SHFT                                           16u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA2_SENSOR_APC0_MAX_DATA_RD4_BMSK                                       0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA2_SENSOR_APC0_MAX_DATA_RD4_SHFT                                            8u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA2_SENSOR_APC0_MIN_DATA_RD4_BMSK                                         0xffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA2_SENSOR_APC0_MIN_DATA_RD4_SHFT                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA3_ADDR                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x4dcu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA3_OFFS                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x4dcu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA3_RMSK                                                            0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA3_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA3_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA3_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA3_SENSOR_APC0_MAX_DATA_RD7_BMSK                                   0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA3_SENSOR_APC0_MAX_DATA_RD7_SHFT                                           24u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA3_SENSOR_APC0_MIN_DATA_RD7_BMSK                                     0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA3_SENSOR_APC0_MIN_DATA_RD7_SHFT                                           16u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA3_SENSOR_APC0_MAX_DATA_RD6_BMSK                                       0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA3_SENSOR_APC0_MAX_DATA_RD6_SHFT                                            8u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA3_SENSOR_APC0_MIN_DATA_RD6_BMSK                                         0xffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA3_SENSOR_APC0_MIN_DATA_RD6_SHFT                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA4_ADDR                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x4e0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA4_OFFS                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x4e0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA4_RMSK                                                            0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA4_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA4_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA4_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA4_SENSOR_APC0_MAX_DATA_RD9_BMSK                                   0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA4_SENSOR_APC0_MAX_DATA_RD9_SHFT                                           24u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA4_SENSOR_APC0_MIN_DATA_RD9_BMSK                                     0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA4_SENSOR_APC0_MIN_DATA_RD9_SHFT                                           16u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA4_SENSOR_APC0_MAX_DATA_RD8_BMSK                                       0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA4_SENSOR_APC0_MAX_DATA_RD8_SHFT                                            8u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA4_SENSOR_APC0_MIN_DATA_RD8_BMSK                                         0xffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_DATA4_SENSOR_APC0_MIN_DATA_RD8_SHFT                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA0_ADDR                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x4e4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA0_OFFS                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x4e4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA0_RMSK                                                            0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA0_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA0_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA0_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA0_SENSOR_APC1_MAX_DATA_RD1_BMSK                                   0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA0_SENSOR_APC1_MAX_DATA_RD1_SHFT                                           24u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA0_SENSOR_APC1_MIN_DATA_RD1_BMSK                                     0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA0_SENSOR_APC1_MIN_DATA_RD1_SHFT                                           16u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA0_SENSOR_APC1_MAX_DATA_RD0_BMSK                                       0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA0_SENSOR_APC1_MAX_DATA_RD0_SHFT                                            8u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA0_SENSOR_APC1_MIN_DATA_RD0_BMSK                                         0xffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA0_SENSOR_APC1_MIN_DATA_RD0_SHFT                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA1_ADDR                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x4e8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA1_OFFS                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x4e8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA1_RMSK                                                            0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA1_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA1_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA1_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA1_SENSOR_APC1_MAX_DATA_RD3_BMSK                                   0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA1_SENSOR_APC1_MAX_DATA_RD3_SHFT                                           24u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA1_SENSOR_APC1_MIN_DATA_RD3_BMSK                                     0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA1_SENSOR_APC1_MIN_DATA_RD3_SHFT                                           16u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA1_SENSOR_APC1_MAX_DATA_RD2_BMSK                                       0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA1_SENSOR_APC1_MAX_DATA_RD2_SHFT                                            8u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA1_SENSOR_APC1_MIN_DATA_RD2_BMSK                                         0xffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA1_SENSOR_APC1_MIN_DATA_RD2_SHFT                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA2_ADDR                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x4ecu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA2_OFFS                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x4ecu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA2_RMSK                                                            0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA2_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA2_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA2_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA2_SENSOR_APC1_MAX_DATA_RD5_BMSK                                   0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA2_SENSOR_APC1_MAX_DATA_RD5_SHFT                                           24u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA2_SENSOR_APC1_MIN_DATA_RD5_BMSK                                     0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA2_SENSOR_APC1_MIN_DATA_RD5_SHFT                                           16u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA2_SENSOR_APC1_MAX_DATA_RD4_BMSK                                       0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA2_SENSOR_APC1_MAX_DATA_RD4_SHFT                                            8u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA2_SENSOR_APC1_MIN_DATA_RD4_BMSK                                         0xffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA2_SENSOR_APC1_MIN_DATA_RD4_SHFT                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA3_ADDR                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x4f0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA3_OFFS                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x4f0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA3_RMSK                                                            0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA3_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA3_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA3_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA3_SENSOR_APC1_MAX_DATA_RD7_BMSK                                   0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA3_SENSOR_APC1_MAX_DATA_RD7_SHFT                                           24u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA3_SENSOR_APC1_MIN_DATA_RD7_BMSK                                     0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA3_SENSOR_APC1_MIN_DATA_RD7_SHFT                                           16u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA3_SENSOR_APC1_MAX_DATA_RD6_BMSK                                       0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA3_SENSOR_APC1_MAX_DATA_RD6_SHFT                                            8u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA3_SENSOR_APC1_MIN_DATA_RD6_BMSK                                         0xffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA3_SENSOR_APC1_MIN_DATA_RD6_SHFT                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA4_ADDR                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x4f4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA4_OFFS                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x4f4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA4_RMSK                                                            0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA4_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA4_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA4_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA4_SENSOR_APC1_MAX_DATA_RD9_BMSK                                   0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA4_SENSOR_APC1_MAX_DATA_RD9_SHFT                                           24u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA4_SENSOR_APC1_MIN_DATA_RD9_BMSK                                     0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA4_SENSOR_APC1_MIN_DATA_RD9_SHFT                                           16u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA4_SENSOR_APC1_MAX_DATA_RD8_BMSK                                       0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA4_SENSOR_APC1_MAX_DATA_RD8_SHFT                                            8u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA4_SENSOR_APC1_MIN_DATA_RD8_BMSK                                         0xffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_DATA4_SENSOR_APC1_MIN_DATA_RD8_SHFT                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_MODE_CHANGE_TMR_CNT_ADDR                                                             (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x4f8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_MODE_CHANGE_TMR_CNT_OFFS                                                             (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x4f8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_MODE_CHANGE_TMR_CNT_RMSK                                                                   0x3fu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_MODE_CHANGE_TMR_CNT_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_MODE_CHANGE_TMR_CNT_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_MODE_CHANGE_TMR_CNT_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_MODE_CHANGE_TMR_CNT_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_MODE_CHANGE_TMR_CNT_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_MODE_CHANGE_TMR_CNT_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_MODE_CHANGE_TMR_CNT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_MODE_CHANGE_TMR_CNT_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_MODE_CHANGE_TMR_CNT_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_MODE_CHANGE_TMR_CNT_APC0_NUM_CYCLES4MODE_CHANGE_BMSK                                       0x3fu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC0_MODE_CHANGE_TMR_CNT_APC0_NUM_CYCLES4MODE_CHANGE_SHFT                                          0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_MODE_CHANGE_TMR_CNT_ADDR                                                             (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x4fcu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_MODE_CHANGE_TMR_CNT_OFFS                                                             (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x4fcu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_MODE_CHANGE_TMR_CNT_RMSK                                                                   0x3fu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_MODE_CHANGE_TMR_CNT_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_MODE_CHANGE_TMR_CNT_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_MODE_CHANGE_TMR_CNT_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_MODE_CHANGE_TMR_CNT_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_MODE_CHANGE_TMR_CNT_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_MODE_CHANGE_TMR_CNT_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_MODE_CHANGE_TMR_CNT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_MODE_CHANGE_TMR_CNT_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_MODE_CHANGE_TMR_CNT_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_MODE_CHANGE_TMR_CNT_APC1_NUM_CYCLES4MODE_CHANGE_BMSK                                       0x3fu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_APC1_MODE_CHANGE_TMR_CNT_APC1_NUM_CYCLES4MODE_CHANGE_SHFT                                          0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CLR_MINMAX_DATA_ADDR                                                               (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x504u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CLR_MINMAX_DATA_OFFS                                                               (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x504u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CLR_MINMAX_DATA_RMSK                                                                  0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CLR_MINMAX_DATA_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CLR_MINMAX_DATA_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CLR_MINMAX_DATA_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CLR_MINMAX_DATA_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CLR_MINMAX_DATA_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CLR_MINMAX_DATA_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CLR_MINMAX_DATA_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CLR_MINMAX_DATA_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CLR_MINMAX_DATA_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CLR_MINMAX_DATA_VSENSE_SENSOR_CLR_MINMAX_DATA_BMSK                                    0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CLR_MINMAX_DATA_VSENSE_SENSOR_CLR_MINMAX_DATA_SHFT                                          0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_RD_EN_ADDR                                                               (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x508u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_RD_EN_OFFS                                                               (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x508u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_RD_EN_RMSK                                                                  0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_RD_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_RD_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_RD_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_RD_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_RD_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_RD_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_RD_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_RD_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_RD_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_RD_EN_VSENSE_SENSOR_FIFO_DATA_RD_EN_BMSK                                    0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_FIFO_DATA_RD_EN_VSENSE_SENSOR_FIFO_DATA_RD_EN_SHFT                                          0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_RESET_STATE_STATUS_ADDR                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x50cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_RESET_STATE_STATUS_OFFS                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x50cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_RESET_STATE_STATUS_RMSK                                                               0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_RESET_STATE_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_RESET_STATE_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_RESET_STATE_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_RESET_STATE_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_RESET_STATE_STATUS_VSENSE_SENSOR_RESET_STATE_STATUS_BMSK                              0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_RESET_STATE_STATUS_VSENSE_SENSOR_RESET_STATE_STATUS_SHFT                                    0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CLK_EN_STATUS_ADDR                                                                 (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x510u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CLK_EN_STATUS_OFFS                                                                 (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x510u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CLK_EN_STATUS_RMSK                                                                   0x37fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CLK_EN_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CLK_EN_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CLK_EN_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CLK_EN_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CLK_EN_STATUS_VSENSE_CNTRL_AHB_CLK_EN_STATUS_BMSK                                    0x200000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CLK_EN_STATUS_VSENSE_CNTRL_AHB_CLK_EN_STATUS_SHFT                                          21u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CLK_EN_STATUS_VSENSE_CNTRL_CLK_EN_STATUS_BMSK                                        0x100000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CLK_EN_STATUS_VSENSE_CNTRL_CLK_EN_STATUS_SHFT                                              20u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CLK_EN_STATUS_VSENSE_SENSOR_CLK_EN_STATUS_BMSK                                        0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CLK_EN_STATUS_VSENSE_SENSOR_CLK_EN_STATUS_SHFT                                              0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_RCDRW_STATUS_ADDR                                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x514u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_RCDRW_STATUS_OFFS                                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x514u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_RCDRW_STATUS_RMSK                                                                      0x3fffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_RCDRW_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_RCDRW_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_RCDRW_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_RCDRW_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_RCDRW_STATUS_VSENSE_CHAIN_RCDRW_STATUS_BMSK                                            0x3fffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_RCDRW_STATUS_VSENSE_CHAIN_RCDRW_STATUS_SHFT                                                 0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_EN_HW_DCVS_ADDR                                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x518u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_EN_HW_DCVS_OFFS                                                                     (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x518u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_EN_HW_DCVS_RMSK                                                                        0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_EN_HW_DCVS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_EN_HW_DCVS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_EN_HW_DCVS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_EN_HW_DCVS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_EN_HW_DCVS_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_EN_HW_DCVS_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_EN_HW_DCVS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_EN_HW_DCVS_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_EN_HW_DCVS_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_EN_HW_DCVS_EN_HW_DCVS_BMSK                                                             0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_EN_HW_DCVS_EN_HW_DCVS_SHFT                                                                   0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_MODE_DATA_ADDR(n)                                                         (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0X51C + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_MODE_DATA_OFFS(n)                                                         (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0X51C + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_MODE_DATA_RMSK                                                                0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_MODE_DATA_MAXn                                                                    16u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_MODE_DATA_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_MODE_DATA_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_MODE_DATA_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_MODE_DATA_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_MODE_DATA_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_MODE_DATA_SENSOR_MODE_DATA_RD3_BMSK                                           0xf000u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_MODE_DATA_SENSOR_MODE_DATA_RD3_SHFT                                               12u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_MODE_DATA_SENSOR_MODE_DATA_RD2_BMSK                                            0xf00u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_MODE_DATA_SENSOR_MODE_DATA_RD2_SHFT                                                8u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_MODE_DATA_SENSOR_MODE_DATA_RD1_BMSK                                             0xf0u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_MODE_DATA_SENSOR_MODE_DATA_RD1_SHFT                                                4u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_MODE_DATA_SENSOR_MODE_DATA_RD0_BMSK                                              0xfu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MAX_MIN_MODE_DATA_SENSOR_MODE_DATA_RD0_SHFT                                                0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA0_ADDR                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x570u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA0_OFFS                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x570u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA0_RMSK                                                         0xfffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA0_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA0_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA0_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA0_SENSOR_APC0_MODE_DATA_RD1_BMSK                               0xfff000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA0_SENSOR_APC0_MODE_DATA_RD1_SHFT                                     12u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA0_SENSOR_APC0_MODE_DATA_RD0_BMSK                                  0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA0_SENSOR_APC0_MODE_DATA_RD0_SHFT                                      0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA1_ADDR                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x574u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA1_OFFS                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x574u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA1_RMSK                                                         0xfffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA1_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA1_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA1_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA1_SENSOR_APC0_MODE_DATA_RD3_BMSK                               0xfff000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA1_SENSOR_APC0_MODE_DATA_RD3_SHFT                                     12u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA1_SENSOR_APC0_MODE_DATA_RD2_BMSK                                  0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA1_SENSOR_APC0_MODE_DATA_RD2_SHFT                                      0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA2_ADDR                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x578u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA2_OFFS                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x578u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA2_RMSK                                                         0xfffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA2_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA2_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA2_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA2_SENSOR_APC0_MODE_DATA_RD5_BMSK                               0xfff000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA2_SENSOR_APC0_MODE_DATA_RD5_SHFT                                     12u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA2_SENSOR_APC0_MODE_DATA_RD4_BMSK                                  0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA2_SENSOR_APC0_MODE_DATA_RD4_SHFT                                      0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA3_ADDR                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x57cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA3_OFFS                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x57cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA3_RMSK                                                         0xfffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA3_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA3_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA3_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA3_SENSOR_APC0_MODE_DATA_RD7_BMSK                               0xfff000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA3_SENSOR_APC0_MODE_DATA_RD7_SHFT                                     12u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA3_SENSOR_APC0_MODE_DATA_RD6_BMSK                                  0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA3_SENSOR_APC0_MODE_DATA_RD6_SHFT                                      0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA4_ADDR                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x580u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA4_OFFS                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x580u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA4_RMSK                                                         0xfffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA4_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA4_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA4_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA4_SENSOR_APC0_MODE_DATA_RD9_BMSK                               0xfff000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA4_SENSOR_APC0_MODE_DATA_RD9_SHFT                                     12u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA4_SENSOR_APC0_MODE_DATA_RD8_BMSK                                  0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MAX_MIN_MODE_DATA4_SENSOR_APC0_MODE_DATA_RD8_SHFT                                      0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA0_ADDR                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x584u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA0_OFFS                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x584u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA0_RMSK                                                         0xfffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA0_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA0_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA0_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA0_SENSOR_APC1_MODE_DATA_RD1_BMSK                               0xfff000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA0_SENSOR_APC1_MODE_DATA_RD1_SHFT                                     12u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA0_SENSOR_APC1_MODE_DATA_RD0_BMSK                                  0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA0_SENSOR_APC1_MODE_DATA_RD0_SHFT                                      0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA1_ADDR                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x588u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA1_OFFS                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x588u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA1_RMSK                                                         0xfffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA1_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA1_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA1_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA1_SENSOR_APC1_MODE_DATA_RD3_BMSK                               0xfff000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA1_SENSOR_APC1_MODE_DATA_RD3_SHFT                                     12u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA1_SENSOR_APC1_MODE_DATA_RD2_BMSK                                  0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA1_SENSOR_APC1_MODE_DATA_RD2_SHFT                                      0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA2_ADDR                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x58cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA2_OFFS                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x58cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA2_RMSK                                                         0xfffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA2_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA2_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA2_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA2_SENSOR_APC1_MODE_DATA_RD5_BMSK                               0xfff000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA2_SENSOR_APC1_MODE_DATA_RD5_SHFT                                     12u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA2_SENSOR_APC1_MODE_DATA_RD4_BMSK                                  0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA2_SENSOR_APC1_MODE_DATA_RD4_SHFT                                      0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA3_ADDR                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x590u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA3_OFFS                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x590u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA3_RMSK                                                         0xfffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA3_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA3_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA3_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA3_SENSOR_APC1_MODE_DATA_RD7_BMSK                               0xfff000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA3_SENSOR_APC1_MODE_DATA_RD7_SHFT                                     12u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA3_SENSOR_APC1_MODE_DATA_RD6_BMSK                                  0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA3_SENSOR_APC1_MODE_DATA_RD6_SHFT                                      0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA4_ADDR                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x594u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA4_OFFS                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x594u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA4_RMSK                                                         0xfffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA4_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA4_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA4_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA4_SENSOR_APC1_MODE_DATA_RD9_BMSK                               0xfff000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA4_SENSOR_APC1_MODE_DATA_RD9_SHFT                                     12u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA4_SENSOR_APC1_MODE_DATA_RD8_BMSK                                  0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MAX_MIN_MODE_DATA4_SENSOR_APC1_MODE_DATA_RD8_SHFT                                      0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PLL_LOCK_WAIT_CNTR_ADDR                                                             (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x598u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PLL_LOCK_WAIT_CNTR_OFFS                                                             (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x598u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PLL_LOCK_WAIT_CNTR_RMSK                                                                 0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PLL_LOCK_WAIT_CNTR_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PLL_LOCK_WAIT_CNTR_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PLL_LOCK_WAIT_CNTR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PLL_LOCK_WAIT_CNTR_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PLL_LOCK_WAIT_CNTR_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PLL_LOCK_WAIT_CNTR_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PLL_LOCK_WAIT_CNTR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PLL_LOCK_WAIT_CNTR_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PLL_LOCK_WAIT_CNTR_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PLL_LOCK_WAIT_CNTR_WAIT_CNT_VAL_BMSK                                                    0xffffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PLL_LOCK_WAIT_CNTR_WAIT_CNT_VAL_SHFT                                                         0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_LIVE_STREAM_SEL_ADDR                                                               (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x59cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_LIVE_STREAM_SEL_OFFS                                                               (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x59cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_LIVE_STREAM_SEL_RMSK                                                                  0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_LIVE_STREAM_SEL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_LIVE_STREAM_SEL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_LIVE_STREAM_SEL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_LIVE_STREAM_SEL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_LIVE_STREAM_SEL_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_LIVE_STREAM_SEL_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_LIVE_STREAM_SEL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_LIVE_STREAM_SEL_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_LIVE_STREAM_SEL_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_LIVE_STREAM_SEL_VSENSE_SENSOR_LIVE_STREAM_SEL_BMSK                                    0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_LIVE_STREAM_SEL_VSENSE_SENSOR_LIVE_STREAM_SEL_SHFT                                          0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_LIVE_STREAM_EN_ADDR                                                                (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x5a0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_LIVE_STREAM_EN_OFFS                                                                (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5a0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_LIVE_STREAM_EN_RMSK                                                                       0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_LIVE_STREAM_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_LIVE_STREAM_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_LIVE_STREAM_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_LIVE_STREAM_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_LIVE_STREAM_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_LIVE_STREAM_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_LIVE_STREAM_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_LIVE_STREAM_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_LIVE_STREAM_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_LIVE_STREAM_EN_VSENSE_SENSOR_ALL_LIVE_STREAM_EN_BMSK                                      0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_LIVE_STREAM_EN_VSENSE_SENSOR_ALL_LIVE_STREAM_EN_SHFT                                        0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_FUSA_CFG_ADDR                                                                             (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x5a4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_FUSA_CFG_OFFS                                                                             (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5a4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_FUSA_CFG_RMSK                                                                             0x800000fful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_FUSA_CFG_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_FUSA_CFG_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_FUSA_CFG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_FUSA_CFG_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_FUSA_CFG_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_FUSA_CFG_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_FUSA_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_FUSA_CFG_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_FUSA_CFG_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_FUSA_CFG_DISABLE_SUMMARY_READ_BMSK                                                        0x80000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_FUSA_CFG_DISABLE_SUMMARY_READ_SHFT                                                                31u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_FUSA_CFG_FUSA_EN_BMSK                                                                           0xffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_FUSA_CFG_FUSA_EN_SHFT                                                                              0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_ADDR                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x5a8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_OFFS                                                            (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5a8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_RMSK                                                                  0x1fu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_VSENSE_CNTRL_PARITY_IRQ_TYPE_BMSK                                     0x18u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_VSENSE_CNTRL_PARITY_IRQ_TYPE_SHFT                                        3u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_VSENSE_CNTRL_PARITY_IRQ_EN_BMSK                                        0x4u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_VSENSE_CNTRL_PARITY_IRQ_EN_SHFT                                          2u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_VSENSE_CNTRL_PARITY_IRQ_FORCE_BMSK                                     0x2u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_VSENSE_CNTRL_PARITY_IRQ_FORCE_SHFT                                       1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_VSENSE_CNTRL_PARITY_IRQ_CLEAR_BMSK                                     0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_PARITY_IRQ_EN_CLEAR_VSENSE_CNTRL_PARITY_IRQ_CLEAR_SHFT                                       0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_ADDR                                                              (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x5acu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_OFFS                                                              (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5acu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_RMSK                                                              0xc007fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_VSENSE_SENSOR_HEARTBEAT_IRQ_TYPE_BMSK                             0xc0000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_VSENSE_SENSOR_HEARTBEAT_IRQ_TYPE_SHFT                                     30u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_BMSK                                  0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_VSENSE_SENSOR_HEARTBEAT_IRQ_EN_SHFT                                        0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_ADDR                                                           (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x5b0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_OFFS                                                           (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5b0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_RMSK                                                              0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_BMSK                            0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_VSENSE_SENSOR_HEARTBEAT_IRQ_FORCE_SHFT                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_ADDR                                                           (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x5b4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_OFFS                                                           (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5b4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_RMSK                                                              0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_BMSK                            0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_VSENSE_SENSOR_HEARTBEAT_IRQ_CLEAR_SHFT                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_PARITY_IRQ_STATUS_ADDR                                                   (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x5b8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_PARITY_IRQ_STATUS_OFFS                                                   (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5b8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_PARITY_IRQ_STATUS_RMSK                                                   0x8007fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_PARITY_IRQ_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_PARITY_IRQ_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_PARITY_IRQ_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_PARITY_IRQ_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_PARITY_IRQ_STATUS_VSENSE_CNTRL_PARITY_IRQ_STATUS_BMSK                    0x80000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_PARITY_IRQ_STATUS_VSENSE_CNTRL_PARITY_IRQ_STATUS_SHFT                            31u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_PARITY_IRQ_STATUS_VSENSE_SENSOR_HEARTBEAT_IRQ_STATUS_BMSK                   0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_HEARTBEAT_PARITY_IRQ_STATUS_VSENSE_SENSOR_HEARTBEAT_IRQ_STATUS_SHFT                         0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_ADDR                                                              (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x5bcu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_OFFS                                                              (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5bcu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_RMSK                                                              0xc007fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_VSENSE_SENSOR_OUTER_MAX_IRQ_TYPE_BMSK                             0xc0000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_VSENSE_SENSOR_OUTER_MAX_IRQ_TYPE_SHFT                                     30u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_BMSK                                  0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_VSENSE_SENSOR_OUTER_MAX_IRQ_EN_SHFT                                        0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_ADDR                                                           (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x5c0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_OFFS                                                           (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5c0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_RMSK                                                              0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_BMSK                            0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_VSENSE_SENSOR_OUTER_MAX_IRQ_FORCE_SHFT                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_ADDR                                                           (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x5c4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_OFFS                                                           (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5c4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_RMSK                                                              0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_BMSK                            0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_VSENSE_SENSOR_OUTER_MAX_IRQ_CLEAR_SHFT                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_STATUS_ADDR                                                          (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x5c8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_STATUS_OFFS                                                          (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5c8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_STATUS_RMSK                                                             0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_STATUS_VSENSE_SENSOR_OUTER_MAX_IRQ_STATUS_BMSK                          0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MAX_IRQ_STATUS_VSENSE_SENSOR_OUTER_MAX_IRQ_STATUS_SHFT                                0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_EN_ADDR                                                              (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x5ccu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_EN_OFFS                                                              (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5ccu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_EN_RMSK                                                              0xc007fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_EN_VSENSE_SENSOR_INNER_MAX_IRQ_TYPE_BMSK                             0xc0000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_EN_VSENSE_SENSOR_INNER_MAX_IRQ_TYPE_SHFT                                     30u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_EN_VSENSE_SENSOR_INNER_MAX_IRQ_EN_BMSK                                  0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_EN_VSENSE_SENSOR_INNER_MAX_IRQ_EN_SHFT                                        0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_ADDR                                                           (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x5d0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_OFFS                                                           (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5d0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_RMSK                                                              0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_BMSK                            0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_VSENSE_SENSOR_INNER_MAX_IRQ_FORCE_SHFT                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_ADDR                                                           (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x5d4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_OFFS                                                           (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5d4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_RMSK                                                              0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_BMSK                            0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_VSENSE_SENSOR_INNER_MAX_IRQ_CLEAR_SHFT                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_STATUS_ADDR                                                          (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x5d8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_STATUS_OFFS                                                          (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5d8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_STATUS_RMSK                                                             0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_STATUS_VSENSE_SENSOR_INNER_MAX_IRQ_STATUS_BMSK                          0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MAX_IRQ_STATUS_VSENSE_SENSOR_INNER_MAX_IRQ_STATUS_SHFT                                0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_EN_ADDR                                                              (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x5dcu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_EN_OFFS                                                              (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5dcu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_EN_RMSK                                                              0xc007fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_EN_VSENSE_SENSOR_INNER_MIN_IRQ_TYPE_BMSK                             0xc0000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_EN_VSENSE_SENSOR_INNER_MIN_IRQ_TYPE_SHFT                                     30u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_EN_VSENSE_SENSOR_INNER_MIN_IRQ_EN_BMSK                                  0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_EN_VSENSE_SENSOR_INNER_MIN_IRQ_EN_SHFT                                        0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_ADDR                                                           (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x5e0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_OFFS                                                           (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5e0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_RMSK                                                              0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_BMSK                            0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_VSENSE_SENSOR_INNER_MIN_IRQ_FORCE_SHFT                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_ADDR                                                           (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x5e4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_OFFS                                                           (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5e4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_RMSK                                                              0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_BMSK                            0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_VSENSE_SENSOR_INNER_MIN_IRQ_CLEAR_SHFT                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_STATUS_ADDR                                                          (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x5e8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_STATUS_OFFS                                                          (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5e8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_STATUS_RMSK                                                             0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_STATUS_VSENSE_SENSOR_INNER_MIN_IRQ_STATUS_BMSK                          0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_INNER_MIN_IRQ_STATUS_VSENSE_SENSOR_INNER_MIN_IRQ_STATUS_SHFT                                0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_ADDR                                                              (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x5ecu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_OFFS                                                              (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5ecu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_RMSK                                                              0xc007fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_VSENSE_SENSOR_OUTER_MIN_IRQ_TYPE_BMSK                             0xc0000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_VSENSE_SENSOR_OUTER_MIN_IRQ_TYPE_SHFT                                     30u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_BMSK                                  0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_VSENSE_SENSOR_OUTER_MIN_IRQ_EN_SHFT                                        0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_ADDR                                                           (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x5f0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_OFFS                                                           (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5f0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_RMSK                                                              0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_BMSK                            0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_VSENSE_SENSOR_OUTER_MIN_IRQ_FORCE_SHFT                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_ADDR                                                           (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x5f4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_OFFS                                                           (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5f4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_RMSK                                                              0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_BMSK                            0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_VSENSE_SENSOR_OUTER_MIN_IRQ_CLEAR_SHFT                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_STATUS_ADDR                                                          (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x5f8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_STATUS_OFFS                                                          (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5f8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_STATUS_RMSK                                                             0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_STATUS_VSENSE_SENSOR_OUTER_MIN_IRQ_STATUS_BMSK                          0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_OUTER_MIN_IRQ_STATUS_VSENSE_SENSOR_OUTER_MIN_IRQ_STATUS_SHFT                                0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_IRQ_DETECT_CTL_ADDR                                                                (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x5fcu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_IRQ_DETECT_CTL_OFFS                                                                (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x5fcu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_IRQ_DETECT_CTL_RMSK                                                                      0x3fu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_IRQ_DETECT_CTL_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_IRQ_DETECT_CTL_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_IRQ_DETECT_CTL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_IRQ_DETECT_CTL_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_IRQ_DETECT_CTL_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_IRQ_DETECT_CTL_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_IRQ_DETECT_CTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_IRQ_DETECT_CTL_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_IRQ_DETECT_CTL_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_IRQ_DETECT_CTL_VSENSE_SENSOR_PARITY_IRQ_DETECT_CTL_BMSK                                  0x20u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_IRQ_DETECT_CTL_VSENSE_SENSOR_PARITY_IRQ_DETECT_CTL_SHFT                                     5u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_IRQ_DETECT_CTL_VSENSE_SENSOR_HEARTBEAT_IRQ_DETECT_CTL_BMSK                               0x10u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_IRQ_DETECT_CTL_VSENSE_SENSOR_HEARTBEAT_IRQ_DETECT_CTL_SHFT                                  4u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_IRQ_DETECT_CTL_VSENSE_SENSOR_OUTER_MAX_IRQ_DETECT_CTL_BMSK                                0x8u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_IRQ_DETECT_CTL_VSENSE_SENSOR_OUTER_MAX_IRQ_DETECT_CTL_SHFT                                  3u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_IRQ_DETECT_CTL_VSENSE_SENSOR_INNER_MAX_IRQ_DETECT_CTL_BMSK                                0x4u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_IRQ_DETECT_CTL_VSENSE_SENSOR_INNER_MAX_IRQ_DETECT_CTL_SHFT                                  2u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_IRQ_DETECT_CTL_VSENSE_SENSOR_INNER_MIN_IRQ_DETECT_CTL_BMSK                                0x2u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_IRQ_DETECT_CTL_VSENSE_SENSOR_INNER_MIN_IRQ_DETECT_CTL_SHFT                                  1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_IRQ_DETECT_CTL_VSENSE_SENSOR_OUTER_MIN_IRQ_DETECT_CTL_BMSK                                0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_IRQ_DETECT_CTL_VSENSE_SENSOR_OUTER_MIN_IRQ_DETECT_CTL_SHFT                                  0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_ERROR_STATUS_ADDR                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x600u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_ERROR_STATUS_OFFS                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x600u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_ERROR_STATUS_RMSK                                                       0x8007fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_ERROR_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_ERROR_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_ERROR_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_ERROR_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_ERROR_STATUS_VSENSE_SENSOR_GLOBAL_PARITY_IRQ_ERROR_STATUS_BMSK          0x80000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_ERROR_STATUS_VSENSE_SENSOR_GLOBAL_PARITY_IRQ_ERROR_STATUS_SHFT                  31u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_ERROR_STATUS_VSENSE_SENSOR_GLOBAL_IRQ_ERROR_STATUS_BMSK                    0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_ERROR_STATUS_VSENSE_SENSOR_GLOBAL_IRQ_ERROR_STATUS_SHFT                          0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_WARN_STATUS_ADDR                                                        (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x604u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_WARN_STATUS_OFFS                                                        (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x604u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_WARN_STATUS_RMSK                                                        0x8007fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_WARN_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_WARN_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_WARN_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_WARN_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_WARN_STATUS_VSENSE_SENSOR_GLOBAL_PARITY_IRQ_WARN_STATUS_BMSK            0x80000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_WARN_STATUS_VSENSE_SENSOR_GLOBAL_PARITY_IRQ_WARN_STATUS_SHFT                    31u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_WARN_STATUS_VSENSE_SENSOR_GLOBAL_IRQ_WARN_STATUS_BMSK                      0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_WARN_STATUS_VSENSE_SENSOR_GLOBAL_IRQ_WARN_STATUS_SHFT                            0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_ADDR                                                              (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x608u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_OFFS                                                              (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x608u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_RMSK                                                                 0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_BMSK                                  0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_VSENSE_SENSOR_GLOBAL_IRQ_CLEAR_SHFT                                        0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_DISABLE_ADDR                                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0x60cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_DISABLE_OFFS                                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0x60cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_DISABLE_RMSK                                                                  0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_DISABLE_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_DISABLE_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_DISABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_DISABLE_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_DISABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_DISABLE_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_DISABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_DISABLE_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_DISABLE_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_DISABLE_VSENSE_CNTRL_DEBUG_DISABLE_BMSK                                       0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_DEBUG_DISABLE_VSENSE_CNTRL_DEBUG_DISABLE_SHFT                                                0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MODEm_THRESHOLD_ADDR(m,n)                                                         (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0X610 + (0x4*(m)) + (0x50*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MODEm_THRESHOLD_OFFS(m,n)                                                         (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0X610 + (0x4*(m)) + (0x50*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MODEm_THRESHOLD_RMSK                                                              0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MODEm_THRESHOLD_MAXm                                                                      18u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MODEm_THRESHOLD_MAXn                                                                      15u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MODEm_THRESHOLD_INI2(m,n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MODEm_THRESHOLD_ADDR(m,n), HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MODEm_THRESHOLD_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MODEm_THRESHOLD_INMI2(m,n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MODEm_THRESHOLD_ADDR(m,n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MODEm_THRESHOLD_OUTI2(m,n,val)        \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MODEm_THRESHOLD_ADDR(m,n),val)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MODEm_THRESHOLD_OUTMI2(m,n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MODEm_THRESHOLD_ADDR(m,n),mask,val,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MODEm_THRESHOLD_INI2(m,n))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MODEm_THRESHOLD_OUTER_MAX_THRESHOLD_BMSK                                          0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MODEm_THRESHOLD_OUTER_MAX_THRESHOLD_SHFT                                                  24u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MODEm_THRESHOLD_INNER_MAX_THRESHOLD_BMSK                                            0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MODEm_THRESHOLD_INNER_MAX_THRESHOLD_SHFT                                                  16u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MODEm_THRESHOLD_INNER_MIN_THRESHOLD_BMSK                                              0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MODEm_THRESHOLD_INNER_MIN_THRESHOLD_SHFT                                                   8u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MODEm_THRESHOLD_OUTER_MIN_THRESHOLD_BMSK                                                0xffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_MODEm_THRESHOLD_OUTER_MIN_THRESHOLD_SHFT                                                   0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MODEn_RANGE_ADDR(n)                                                           (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0XB80 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MODEn_RANGE_OFFS(n)                                                           (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0XB80 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MODEn_RANGE_RMSK                                                               0xfff0ffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MODEn_RANGE_MAXn                                                                      15u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MODEn_RANGE_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MODEn_RANGE_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MODEn_RANGE_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MODEn_RANGE_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MODEn_RANGE_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MODEn_RANGE_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MODEn_RANGE_ADDR(n),val)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MODEn_RANGE_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MODEn_RANGE_ADDR(n),mask,val,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MODEn_RANGE_INI(n))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MODEn_RANGE_APC0_MODE_MAX_RANGE_BMSK                                           0xfff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MODEn_RANGE_APC0_MODE_MAX_RANGE_SHFT                                                  16u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MODEn_RANGE_APC0_MODE_MIN_RANGE_BMSK                                               0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC0_MODEn_RANGE_APC0_MODE_MIN_RANGE_SHFT                                                   0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MODEn_RANGE_ADDR(n)                                                           (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0XBC0 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MODEn_RANGE_OFFS(n)                                                           (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0XBC0 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MODEn_RANGE_RMSK                                                               0xfff0ffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MODEn_RANGE_MAXn                                                                      15u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MODEn_RANGE_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MODEn_RANGE_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MODEn_RANGE_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MODEn_RANGE_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MODEn_RANGE_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MODEn_RANGE_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MODEn_RANGE_ADDR(n),val)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MODEn_RANGE_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MODEn_RANGE_ADDR(n),mask,val,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MODEn_RANGE_INI(n))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MODEn_RANGE_APC1_MODE_MAX_RANGE_BMSK                                           0xfff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MODEn_RANGE_APC1_MODE_MAX_RANGE_SHFT                                                  16u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MODEn_RANGE_APC1_MODE_MIN_RANGE_BMSK                                               0xfffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_APC1_MODEn_RANGE_APC1_MODE_MIN_RANGE_SHFT                                                   0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_HEARTBEAT_RANGE_ADDR(n)                                                           (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0XC10 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_HEARTBEAT_RANGE_OFFS(n)                                                           (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0XC10 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_HEARTBEAT_RANGE_RMSK                                                              0x800ffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_HEARTBEAT_RANGE_MAXn                                                                      18u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_HEARTBEAT_RANGE_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_HEARTBEAT_RANGE_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_HEARTBEAT_RANGE_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_HEARTBEAT_RANGE_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_HEARTBEAT_RANGE_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_HEARTBEAT_RANGE_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_HEARTBEAT_RANGE_ADDR(n),val)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_HEARTBEAT_RANGE_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_HEARTBEAT_RANGE_ADDR(n),mask,val,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_HEARTBEAT_RANGE_INI(n))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_HEARTBEAT_RANGE_VSENSE_SENSOR_HEARTBEAT_EN_BMSK                                   0x80000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_HEARTBEAT_RANGE_VSENSE_SENSOR_HEARTBEAT_EN_SHFT                                           31u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_HEARTBEAT_RANGE_VSENSE_SENSOR_HEARTBEAT_MAX_BMSK                                     0xffc00ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_HEARTBEAT_RANGE_VSENSE_SENSOR_HEARTBEAT_MAX_SHFT                                          10u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_HEARTBEAT_RANGE_VSENSE_SENSOR_HEARTBEAT_MIN_BMSK                                       0x3ffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_HEARTBEAT_RANGE_VSENSE_SENSOR_HEARTBEAT_MIN_SHFT                                           0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_HEARTBEAT_CNT_ADDR(n)                                                             (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0XC60 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_HEARTBEAT_CNT_OFFS(n)                                                             (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0XC60 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_HEARTBEAT_CNT_RMSK                                                                     0x3ffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_HEARTBEAT_CNT_MAXn                                                                        18u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_HEARTBEAT_CNT_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_HEARTBEAT_CNT_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_HEARTBEAT_CNT_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_HEARTBEAT_CNT_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_HEARTBEAT_CNT_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_HEARTBEAT_CNT_VSENSE_SENSOR_HEARTBEAT_CNT_BMSK                                         0x3ffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSORn_HEARTBEAT_CNT_VSENSE_SENSOR_HEARTBEAT_CNT_SHFT                                             0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_READ_EN_ADDR                                                                (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0xcb0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_READ_EN_OFFS                                                                (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0xcb0u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_READ_EN_RMSK                                                                   0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_READ_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_READ_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_READ_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_READ_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_READ_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_READ_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_READ_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_READ_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_READ_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_READ_EN_VSENSE_SENSOR_CONFIG_READ_EN_BMSK                                      0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_READ_EN_VSENSE_SENSOR_CONFIG_READ_EN_SHFT                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SUMMARY_READ_EN_ADDR                                                               (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0xcb4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SUMMARY_READ_EN_OFFS                                                               (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0xcb4u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SUMMARY_READ_EN_RMSK                                                                  0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SUMMARY_READ_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SUMMARY_READ_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SUMMARY_READ_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SUMMARY_READ_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SUMMARY_READ_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SUMMARY_READ_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SUMMARY_READ_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SUMMARY_READ_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SUMMARY_READ_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SUMMARY_READ_EN_VSENSE_SENSOR_SUMMARY_READ_EN_BMSK                                    0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_SUMMARY_READ_EN_VSENSE_SENSOR_SUMMARY_READ_EN_SHFT                                          0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_SUMMARY_RD_STATUS_ADDR                                                      (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0xcb8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_SUMMARY_RD_STATUS_OFFS                                                      (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0xcb8u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_SUMMARY_RD_STATUS_RMSK                                                         0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_SUMMARY_RD_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_SUMMARY_RD_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_SUMMARY_RD_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_SUMMARY_RD_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_SUMMARY_RD_STATUS_VSENSE_SENSOR_CONFIG_SUMMARY_RD_STATUS_BMSK                  0x7fffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_CONFIG_SUMMARY_RD_STATUS_VSENSE_SENSOR_CONFIG_SUMMARY_RD_STATUS_SHFT                        0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_ADDR(n)                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0XCC0 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_OFFS(n)                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0XCC0 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_RMSK                                                          0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_MAXn                                                                  18u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_ADDR(n),val)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_ADDR(n),mask,val,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_INI(n))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_THRESHOLD_OUTER_MIN_BMSK                                      0xff000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_THRESHOLD_OUTER_MIN_SHFT                                              24u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_THRESHOLD_INNER_MAX_BMSK                                        0xff0000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_THRESHOLD_INNER_MAX_SHFT                                              16u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_THRESHOLD_INNER_MIN_BMSK                                          0xff00u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_THRESHOLD_INNER_MIN_SHFT                                               8u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_AU_MODE_SEL_BMSK                                                    0x80u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_AU_MODE_SEL_SHFT                                                       7u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_AU_MODE_SEL_LEGACY_MODE_FVAL                                         0x0u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_AU_MODE_SEL_NEW_AU_MODE_FVAL                                         0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_CAPTURE_DELAY_BMSK                                                  0x70u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_CAPTURE_DELAY_SHFT                                                     4u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_TRIG_POS_BMSK                                                        0xcu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_TRIG_POS_SHFT                                                          2u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_TRIG_POS_PRE_TRIG_FVAL                                               0x0u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_TRIG_POS_MID_TRIG_FVAL                                               0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_TRIG_POS_POST_TRIG_FVAL                                              0x2u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_WATERMARK_EN_BMSK                                                    0x2u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_WATERMARK_EN_SHFT                                                      1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_AUTO_CAL_EN_BMSK                                                     0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG0_READ_VALUE_AUTO_CAL_EN_SHFT                                                       0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_ADDR(n)                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0XD10 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_OFFS(n)                                                       (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0XD10 + (0x4*(n)))
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_RMSK                                                           0xffffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_MAXn                                                                  18u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_INI(n)                \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_ADDR(n), HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_RMSK)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_ADDR(n), mask)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_PARITY_CHK_EN_BMSK                                             0x8000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_PARITY_CHK_EN_SHFT                                                    27u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_TDF_COND_WATERMARK_BMSK                                        0x4000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_TDF_COND_WATERMARK_SHFT                                               26u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_FIFO_DATA_HS_RATE_BMSK                                         0x3000000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_FIFO_DATA_HS_RATE_SHFT                                                24u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_RESERVD2_BMSK                                                   0x800000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_RESERVD2_SHFT                                                         23u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_VS_CLK_DEBUG_EN_BMSK                                            0x400000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_VS_CLK_DEBUG_EN_SHFT                                                  22u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_VCO_PWR_SEL_MODE_BMSK                                           0x200000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_VCO_PWR_SEL_MODE_SHFT                                                 21u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_DC_MEAS_CYC_BMSK                                                0x180000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_DC_MEAS_CYC_SHFT                                                      19u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_DC_MEAS_CYC_NUM_DC_MEAS_CYC256_FVAL                                  0x0u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_DC_MEAS_CYC_NUM_DC_MEAS_CYC128_FVAL                                  0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_DC_MEAS_CYC_NUM_DC_MEAS_CYC64_FVAL                                   0x2u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_DC_MEAS_CYC_NUM_DC_MEAS_CYC32_FVAL                                   0x3u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_AC_MODE_BMSK                                                     0x40000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_AC_MODE_SHFT                                                          18u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_RESERVD_BMSK                                                     0x20000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_RESERVD_SHFT                                                          17u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_MODE_SEL_BMSK                                                    0x10000ul
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_MODE_SEL_SHFT                                                         16u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_MODE_SEL_INTERRUPT_MODE_FVAL                                         0x0u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_MODE_SEL_WATERMARK_MODE_FVAL                                         0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_VCO_FILTER_EN_BMSK                                                0x8000u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_VCO_FILTER_EN_SHFT                                                    15u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_VCO_POWER_SEL_BMSK                                                0x4000u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_VCO_POWER_SEL_SHFT                                                    14u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_POWER_EN_BMSK                                                     0x2000u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_POWER_EN_SHFT                                                         13u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_FUNC_EN_BMSK                                                      0x1000u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_FUNC_EN_SHFT                                                          12u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_TRIG_SEL_BMSK                                                      0xc00u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_TRIG_SEL_SHFT                                                         10u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_TRIG_SEL_TRIG_SEL0_FVAL                                              0x0u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_TRIG_SEL_TRIG_SEL1_FVAL                                              0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_TRIG_SEL_TRIG_SEL2_FVAL                                              0x2u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_TRIG_SEL_TRIG_SEL3_FVAL                                              0x3u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_HW_CAPTURE_EN_BMSK                                                 0x200u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_HW_CAPTURE_EN_SHFT                                                     9u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_SW_CAPTURE_BMSK                                                    0x100u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_SW_CAPTURE_SHFT                                                        8u
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_THRESHOLD_OUTER_MAX_BMSK                                            0xffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_SENSOR_n_CONFIG1_READ_VALUE_THRESHOLD_OUTER_MAX_SHFT                                               0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RAIL_LOCATION_ADDR                                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0xd60u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RAIL_LOCATION_OFFS                                                                  (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0xd60u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RAIL_LOCATION_RMSK                                                                      0x3fffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RAIL_LOCATION_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RAIL_LOCATION_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RAIL_LOCATION_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RAIL_LOCATION_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RAIL_LOCATION_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RAIL_LOCATION_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RAIL_LOCATION_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RAIL_LOCATION_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RAIL_LOCATION_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RAIL_LOCATION_VSENSE_CNTRL_RAIL_LOCATION_BMSK                                           0x3fffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RAIL_LOCATION_VSENSE_CNTRL_RAIL_LOCATION_SHFT                                                0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RAIL0_DEPENDENCY_ADDR                                                               (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0xd64u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RAIL0_DEPENDENCY_OFFS                                                               (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0xd64u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RAIL0_DEPENDENCY_RMSK                                                                   0x3fffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RAIL0_DEPENDENCY_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RAIL0_DEPENDENCY_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RAIL0_DEPENDENCY_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RAIL0_DEPENDENCY_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RAIL0_DEPENDENCY_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RAIL0_DEPENDENCY_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RAIL0_DEPENDENCY_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RAIL0_DEPENDENCY_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RAIL0_DEPENDENCY_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RAIL0_DEPENDENCY_VSENSE_CNTRL_RAIL0_DEPENDENCY_BMSK                                     0x3fffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_RAIL0_DEPENDENCY_VSENSE_CNTRL_RAIL0_DEPENDENCY_SHFT                                          0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_VACC_STATUS_ADDR                                                                    (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0xd68u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_VACC_STATUS_OFFS                                                                    (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0xd68u)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_VACC_STATUS_RMSK                                                                        0x3fffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_VACC_STATUS_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_VACC_STATUS_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_VACC_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_VACC_STATUS_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_VACC_STATUS_VSENSE_CNTRL_VACC_STATUS_BMSK                                               0x3fffu
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_VACC_STATUS_VSENSE_CNTRL_VACC_STATUS_SHFT                                                    0u

#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_EN_ADDR                                                                             (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0xd6cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_EN_OFFS                                                                             (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0xd6cu)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_EN_RMSK                                                                             0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_EN_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_EN_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_EN_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_EN_ADDR,v)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_EN_ADDR,m,v,HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_EN_IN)
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_EN_VSENSE_EN_BMSK                                                                   0xfffffffful
#define HWIO_SAILSS_VSENSE_CTRL_1_VSENSE_CNTRL_EN_VSENSE_EN_SHFT                                                                            0u

#define HWIO_SAILSS_VSENSE_CTRL_1_FUSA_STATUS_REGISTER_VSENSE_CNTRL_CLK_RESET_ADDR                                                 (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE      + 0xd70u)
#define HWIO_SAILSS_VSENSE_CTRL_1_FUSA_STATUS_REGISTER_VSENSE_CNTRL_CLK_RESET_OFFS                                                 (SAILSS_VSENSE_CTRL_1_VSENSE_CONTROLLER_REG_BASE_OFFS + 0xd70u)
#define HWIO_SAILSS_VSENSE_CTRL_1_FUSA_STATUS_REGISTER_VSENSE_CNTRL_CLK_RESET_RMSK                                                     0x1fffu
#define HWIO_SAILSS_VSENSE_CTRL_1_FUSA_STATUS_REGISTER_VSENSE_CNTRL_CLK_RESET_IN                    \
                in_dword(HWIO_SAILSS_VSENSE_CTRL_1_FUSA_STATUS_REGISTER_VSENSE_CNTRL_CLK_RESET_ADDR)
#define HWIO_SAILSS_VSENSE_CTRL_1_FUSA_STATUS_REGISTER_VSENSE_CNTRL_CLK_RESET_INM(m)            \
                in_dword_masked(HWIO_SAILSS_VSENSE_CTRL_1_FUSA_STATUS_REGISTER_VSENSE_CNTRL_CLK_RESET_ADDR, m)
#define HWIO_SAILSS_VSENSE_CTRL_1_FUSA_STATUS_REGISTER_VSENSE_CNTRL_CLK_RESET_HPCNT_BMSK                                               0x1f80u
#define HWIO_SAILSS_VSENSE_CTRL_1_FUSA_STATUS_REGISTER_VSENSE_CNTRL_CLK_RESET_HPCNT_SHFT                                                    7u
#define HWIO_SAILSS_VSENSE_CTRL_1_FUSA_STATUS_REGISTER_VSENSE_CNTRL_CLK_RESET_VPCNT_BMSK                                                 0x7eu
#define HWIO_SAILSS_VSENSE_CTRL_1_FUSA_STATUS_REGISTER_VSENSE_CNTRL_CLK_RESET_VPCNT_SHFT                                                    1u
#define HWIO_SAILSS_VSENSE_CTRL_1_FUSA_STATUS_REGISTER_VSENSE_CNTRL_CLK_RESET_FLT_BMSK                                                    0x1u
#define HWIO_SAILSS_VSENSE_CTRL_1_FUSA_STATUS_REGISTER_VSENSE_CNTRL_CLK_RESET_FLT_SHFT                                                      0u


#endif /* __G_SAILSS_VSENSE_CTRL_CONTROLLER_H__ */
