#ifndef __G_SAIL_TO_MD_OCIMEM_HWIO_H__
#define __G_SAIL_TO_MD_OCIMEM_HWIO_H__
/*
===========================================================================
*/
/**
    @file g_SAIL_TO_MD_OCIMEM_HWIO.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        SA8775P (LeMansAU) [lemansau_v1.0_p3q2r72_BTO]
 
    This file contains HWIO register definitions for the following modules:
        SAIL_TO_MD_OCIMEM_CSR


    Generation parameters: 
    { 'filename': 'g_SAIL_TO_MD_OCIMEM_HWIO.h',
      'integer-qualifiers': True,
      'modules': ['SAIL_TO_MD_OCIMEM_CSR'],
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

    $Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/bist/inc/common_inc/g_SAIL_TO_MD_OCIMEM_HWIO.h#1 $
    $DateTime: 2025/02/01 11:39:23 $
    $Author: smarru $

    ===========================================================================
*/

/*----------------------------------------------------------------------------
 * MODULE: SAIL_TO_MD_OCIMEM_CSR
 *--------------------------------------------------------------------------*/

#define SAIL_TO_MD_OCIMEM_CSR_REG_BASE                                                          (SAIL_TO_MD_SAILS_TO_MD_CONFIG_BASE      + 0x00618000ul)
#define SAIL_TO_MD_OCIMEM_CSR_REG_BASE_SIZE                                                     0x800u
#define SAIL_TO_MD_OCIMEM_CSR_REG_BASE_USED                                                     0x90u
#define SAIL_TO_MD_OCIMEM_CSR_REG_BASE_OFFS                                                     0x00618000ul

#define HWIO_SAIL_TO_MD_OCIMEM_HW_VERSION_ADDR                                                  (SAIL_TO_MD_OCIMEM_CSR_REG_BASE      + 0x0u)
#define HWIO_SAIL_TO_MD_OCIMEM_HW_VERSION_OFFS                                                  (SAIL_TO_MD_OCIMEM_CSR_REG_BASE_OFFS + 0x0u)
#define HWIO_SAIL_TO_MD_OCIMEM_HW_VERSION_RMSK                                                  0xfffffffful
#define HWIO_SAIL_TO_MD_OCIMEM_HW_VERSION_IN                    \
                in_dword(HWIO_SAIL_TO_MD_OCIMEM_HW_VERSION_ADDR)
#define HWIO_SAIL_TO_MD_OCIMEM_HW_VERSION_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_OCIMEM_HW_VERSION_ADDR, m)
#define HWIO_SAIL_TO_MD_OCIMEM_HW_VERSION_MAJOR_BMSK                                            0xf0000000ul
#define HWIO_SAIL_TO_MD_OCIMEM_HW_VERSION_MAJOR_SHFT                                                    28u
#define HWIO_SAIL_TO_MD_OCIMEM_HW_VERSION_MINOR_BMSK                                             0xfff0000ul
#define HWIO_SAIL_TO_MD_OCIMEM_HW_VERSION_MINOR_SHFT                                                    16u
#define HWIO_SAIL_TO_MD_OCIMEM_HW_VERSION_STEP_BMSK                                                 0xffffu
#define HWIO_SAIL_TO_MD_OCIMEM_HW_VERSION_STEP_SHFT                                                      0u

#define HWIO_SAIL_TO_MD_OCIMEM_HW_PROFILE_ADDR                                                  (SAIL_TO_MD_OCIMEM_CSR_REG_BASE      + 0x4u)
#define HWIO_SAIL_TO_MD_OCIMEM_HW_PROFILE_OFFS                                                  (SAIL_TO_MD_OCIMEM_CSR_REG_BASE_OFFS + 0x4u)
#define HWIO_SAIL_TO_MD_OCIMEM_HW_PROFILE_RMSK                                                     0x1f1fful
#define HWIO_SAIL_TO_MD_OCIMEM_HW_PROFILE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_OCIMEM_HW_PROFILE_ADDR)
#define HWIO_SAIL_TO_MD_OCIMEM_HW_PROFILE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_OCIMEM_HW_PROFILE_ADDR, m)
#define HWIO_SAIL_TO_MD_OCIMEM_HW_PROFILE_NUM_BANKS_BMSK                                           0x1f000ul
#define HWIO_SAIL_TO_MD_OCIMEM_HW_PROFILE_NUM_BANKS_SHFT                                                12u
#define HWIO_SAIL_TO_MD_OCIMEM_HW_PROFILE_NUM_EXCL_MON_BMSK                                          0x1ffu
#define HWIO_SAIL_TO_MD_OCIMEM_HW_PROFILE_NUM_EXCL_MON_SHFT                                              0u

#define HWIO_SAIL_TO_MD_OCIMEM_GEN_CTL_ADDR                                                     (SAIL_TO_MD_OCIMEM_CSR_REG_BASE      + 0x8u)
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_CTL_OFFS                                                     (SAIL_TO_MD_OCIMEM_CSR_REG_BASE_OFFS + 0x8u)
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_CTL_RMSK                                                       0x1f000ful
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_CTL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_OCIMEM_GEN_CTL_ADDR)
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_CTL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_OCIMEM_GEN_CTL_ADDR, m)
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_CTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_OCIMEM_GEN_CTL_ADDR,v)
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_CTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_OCIMEM_GEN_CTL_ADDR,m,v,HWIO_SAIL_TO_MD_OCIMEM_GEN_CTL_IN)
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_CTL_EXMON_GRAN_MASK_BMSK                                       0x1f0000ul
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_CTL_EXMON_GRAN_MASK_SHFT                                             16u
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_CTL_CLREXMONREQ_PULSE_EN_BMSK                                       0x8u
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_CTL_CLREXMONREQ_PULSE_EN_SHFT                                         3u
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_CTL_CLREXMONREQ_PULSE_EN_HANDSHAKE_FVAL                             0x0u
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_CTL_CLREXMONREQ_PULSE_EN_PULSED_FVAL                                0x1u
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_CTL_EXMON_GRAN_128B_EN_BMSK                                         0x4u
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_CTL_EXMON_GRAN_128B_EN_SHFT                                           2u
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_CTL_EXMON_GRAN_128B_EN_LOGIC_0_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_CTL_EXMON_GRAN_128B_EN_LOGIC_1_FVAL                                 0x1u
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_CTL_CSR_AHB_BRIDGE_POSTWR_DIS_BMSK                                  0x2u
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_CTL_CSR_AHB_BRIDGE_POSTWR_DIS_SHFT                                    1u
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_CTL_CSR_AHB_BRIDGE_POSTWR_DIS_POSTWR_OK_FVAL                        0x0u
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_CTL_CSR_AHB_BRIDGE_POSTWR_DIS_POST_WR_DISABLED_FVAL                 0x1u
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_CTL_SW_STM_FLAG_BMSK                                                0x1u
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_CTL_SW_STM_FLAG_SHFT                                                  0u
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_CTL_SW_STM_FLAG_CLREXMON_EN_FVAL                                    0x0u
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_CTL_SW_STM_FLAG_CLREXMON_DIS_FVAL                                   0x1u

#define HWIO_SAIL_TO_MD_OCIMEM_GEN_STAT_ADDR                                                    (SAIL_TO_MD_OCIMEM_CSR_REG_BASE      + 0xcu)
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_STAT_OFFS                                                    (SAIL_TO_MD_OCIMEM_CSR_REG_BASE_OFFS + 0xcu)
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_STAT_RMSK                                                           0x3u
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_STAT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_OCIMEM_GEN_STAT_ADDR)
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_STAT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_OCIMEM_GEN_STAT_ADDR, m)
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_STAT_AXI_ERR_SLEEP_BMSK                                             0x2u
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_STAT_AXI_ERR_SLEEP_SHFT                                               1u
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_STAT_AXI_ERR_SLEEP_NO_SLEEP_ERROR_FVAL                              0x0u
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_STAT_AXI_ERR_SLEEP_MEMORY_SLEEP_ACCESS_ERROR_FVAL                   0x1u
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_STAT_AXI_ERR_DECODE_BMSK                                            0x1u
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_STAT_AXI_ERR_DECODE_SHFT                                              0u
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_STAT_AXI_ERR_DECODE_NO_DECODE_ERROR_FVAL                            0x0u
#define HWIO_SAIL_TO_MD_OCIMEM_GEN_STAT_AXI_ERR_DECODE_ADDRESS_OUT_OF_RANGE_ERROR_FVAL                 0x1u

#define HWIO_SAIL_TO_MD_OCIMEM_INTC_CLR_ADDR                                                    (SAIL_TO_MD_OCIMEM_CSR_REG_BASE      + 0x10u)
#define HWIO_SAIL_TO_MD_OCIMEM_INTC_CLR_OFFS                                                    (SAIL_TO_MD_OCIMEM_CSR_REG_BASE_OFFS + 0x10u)
#define HWIO_SAIL_TO_MD_OCIMEM_INTC_CLR_RMSK                                                           0x1u
#define HWIO_SAIL_TO_MD_OCIMEM_INTC_CLR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_OCIMEM_INTC_CLR_ADDR)
#define HWIO_SAIL_TO_MD_OCIMEM_INTC_CLR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_OCIMEM_INTC_CLR_ADDR, m)
#define HWIO_SAIL_TO_MD_OCIMEM_INTC_CLR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_OCIMEM_INTC_CLR_ADDR,v)
#define HWIO_SAIL_TO_MD_OCIMEM_INTC_CLR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_OCIMEM_INTC_CLR_ADDR,m,v,HWIO_SAIL_TO_MD_OCIMEM_INTC_CLR_IN)
#define HWIO_SAIL_TO_MD_OCIMEM_INTC_CLR_AXI_ERR_INT_CLR_BMSK                                           0x1u
#define HWIO_SAIL_TO_MD_OCIMEM_INTC_CLR_AXI_ERR_INT_CLR_SHFT                                             0u
#define HWIO_SAIL_TO_MD_OCIMEM_INTC_CLR_AXI_ERR_INT_CLR_NO_ACTION_FVAL                                 0x0u
#define HWIO_SAIL_TO_MD_OCIMEM_INTC_CLR_AXI_ERR_INT_CLR_NONSTICK_INTERRUPT_CLEAR_FVAL                  0x1u

#define HWIO_SAIL_TO_MD_OCIMEM_INTC_MASK_ADDR                                                   (SAIL_TO_MD_OCIMEM_CSR_REG_BASE      + 0x14u)
#define HWIO_SAIL_TO_MD_OCIMEM_INTC_MASK_OFFS                                                   (SAIL_TO_MD_OCIMEM_CSR_REG_BASE_OFFS + 0x14u)
#define HWIO_SAIL_TO_MD_OCIMEM_INTC_MASK_RMSK                                                          0x1u
#define HWIO_SAIL_TO_MD_OCIMEM_INTC_MASK_IN                    \
                in_dword(HWIO_SAIL_TO_MD_OCIMEM_INTC_MASK_ADDR)
#define HWIO_SAIL_TO_MD_OCIMEM_INTC_MASK_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_OCIMEM_INTC_MASK_ADDR, m)
#define HWIO_SAIL_TO_MD_OCIMEM_INTC_MASK_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_OCIMEM_INTC_MASK_ADDR,v)
#define HWIO_SAIL_TO_MD_OCIMEM_INTC_MASK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_OCIMEM_INTC_MASK_ADDR,m,v,HWIO_SAIL_TO_MD_OCIMEM_INTC_MASK_IN)
#define HWIO_SAIL_TO_MD_OCIMEM_INTC_MASK_AXI_ERR_INT_MSK_BMSK                                          0x1u
#define HWIO_SAIL_TO_MD_OCIMEM_INTC_MASK_AXI_ERR_INT_MSK_SHFT                                            0u
#define HWIO_SAIL_TO_MD_OCIMEM_INTC_MASK_AXI_ERR_INT_MSK_INTERRUPT_ON_ERROR_FVAL                       0x0u
#define HWIO_SAIL_TO_MD_OCIMEM_INTC_MASK_AXI_ERR_INT_MSK_DISABLE_INTERRUPT_FVAL                        0x1u

#define HWIO_SAIL_TO_MD_OCIMEM_INTC_STAT_ADDR                                                   (SAIL_TO_MD_OCIMEM_CSR_REG_BASE      + 0x18u)
#define HWIO_SAIL_TO_MD_OCIMEM_INTC_STAT_OFFS                                                   (SAIL_TO_MD_OCIMEM_CSR_REG_BASE_OFFS + 0x18u)
#define HWIO_SAIL_TO_MD_OCIMEM_INTC_STAT_RMSK                                                          0x1u
#define HWIO_SAIL_TO_MD_OCIMEM_INTC_STAT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_OCIMEM_INTC_STAT_ADDR)
#define HWIO_SAIL_TO_MD_OCIMEM_INTC_STAT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_OCIMEM_INTC_STAT_ADDR, m)
#define HWIO_SAIL_TO_MD_OCIMEM_INTC_STAT_AXI_ERR_INT_STAT_BMSK                                         0x1u
#define HWIO_SAIL_TO_MD_OCIMEM_INTC_STAT_AXI_ERR_INT_STAT_SHFT                                           0u
#define HWIO_SAIL_TO_MD_OCIMEM_INTC_STAT_AXI_ERR_INT_STAT_NO_AXI_ERROR_FVAL                            0x0u
#define HWIO_SAIL_TO_MD_OCIMEM_INTC_STAT_AXI_ERR_INT_STAT_AXI_ERROR_DETECTED_FVAL                      0x1u

#define HWIO_SAIL_TO_MD_OCIMEM_OSW_STATUS_ADDR                                                  (SAIL_TO_MD_OCIMEM_CSR_REG_BASE      + 0x1cu)
#define HWIO_SAIL_TO_MD_OCIMEM_OSW_STATUS_OFFS                                                  (SAIL_TO_MD_OCIMEM_CSR_REG_BASE_OFFS + 0x1cu)
#define HWIO_SAIL_TO_MD_OCIMEM_OSW_STATUS_RMSK                                                        0x3fu
#define HWIO_SAIL_TO_MD_OCIMEM_OSW_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_OCIMEM_OSW_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_OCIMEM_OSW_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_OCIMEM_OSW_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_OCIMEM_OSW_STATUS_OSW_RRESP_FIFO_FULL_BMSK                                    0x20u
#define HWIO_SAIL_TO_MD_OCIMEM_OSW_STATUS_OSW_RRESP_FIFO_FULL_SHFT                                       5u
#define HWIO_SAIL_TO_MD_OCIMEM_OSW_STATUS_OSW_RRESP_FIFO_FULL_NOT_FULL_FVAL                            0x0u
#define HWIO_SAIL_TO_MD_OCIMEM_OSW_STATUS_OSW_RRESP_FIFO_FULL_FULL_FVAL                                0x1u
#define HWIO_SAIL_TO_MD_OCIMEM_OSW_STATUS_OSW_WRESP_FIFO_FULL_BMSK                                    0x10u
#define HWIO_SAIL_TO_MD_OCIMEM_OSW_STATUS_OSW_WRESP_FIFO_FULL_SHFT                                       4u
#define HWIO_SAIL_TO_MD_OCIMEM_OSW_STATUS_OSW_WRESP_FIFO_FULL_NOT_FULL_FVAL                            0x0u
#define HWIO_SAIL_TO_MD_OCIMEM_OSW_STATUS_OSW_WRESP_FIFO_FULL_FULL_FVAL                                0x1u
#define HWIO_SAIL_TO_MD_OCIMEM_OSW_STATUS_OSW_RDDATA_FIFO_FULL_BMSK                                    0x8u
#define HWIO_SAIL_TO_MD_OCIMEM_OSW_STATUS_OSW_RDDATA_FIFO_FULL_SHFT                                      3u
#define HWIO_SAIL_TO_MD_OCIMEM_OSW_STATUS_OSW_RDDATA_FIFO_FULL_NOT_FULL_FVAL                           0x0u
#define HWIO_SAIL_TO_MD_OCIMEM_OSW_STATUS_OSW_RDDATA_FIFO_FULL_FULL_FVAL                               0x1u
#define HWIO_SAIL_TO_MD_OCIMEM_OSW_STATUS_OSW_WRDATA_FIFO_FULL_BMSK                                    0x4u
#define HWIO_SAIL_TO_MD_OCIMEM_OSW_STATUS_OSW_WRDATA_FIFO_FULL_SHFT                                      2u
#define HWIO_SAIL_TO_MD_OCIMEM_OSW_STATUS_OSW_WRDATA_FIFO_FULL_NOT_FULL_FVAL                           0x0u
#define HWIO_SAIL_TO_MD_OCIMEM_OSW_STATUS_OSW_WRDATA_FIFO_FULL_FULL_FVAL                               0x1u
#define HWIO_SAIL_TO_MD_OCIMEM_OSW_STATUS_OSW_CMDFIFO_FULL_BMSK                                        0x2u
#define HWIO_SAIL_TO_MD_OCIMEM_OSW_STATUS_OSW_CMDFIFO_FULL_SHFT                                          1u
#define HWIO_SAIL_TO_MD_OCIMEM_OSW_STATUS_OSW_CMDFIFO_FULL_NOT_FULL_FVAL                               0x0u
#define HWIO_SAIL_TO_MD_OCIMEM_OSW_STATUS_OSW_CMDFIFO_FULL_FULL_FVAL                                   0x1u
#define HWIO_SAIL_TO_MD_OCIMEM_OSW_STATUS_OSW_STAT_IDLE_BMSK                                           0x1u
#define HWIO_SAIL_TO_MD_OCIMEM_OSW_STATUS_OSW_STAT_IDLE_SHFT                                             0u
#define HWIO_SAIL_TO_MD_OCIMEM_OSW_STATUS_OSW_STAT_IDLE_NOT_IDLE_FVAL                                  0x0u
#define HWIO_SAIL_TO_MD_OCIMEM_OSW_STATUS_OSW_STAT_IDLE_IDLE_FVAL                                      0x1u

#define HWIO_SAIL_TO_MD_OCIMEM_RAM_DYN_CLK_CTL_ADDR                                             (SAIL_TO_MD_OCIMEM_CSR_REG_BASE      + 0x30u)
#define HWIO_SAIL_TO_MD_OCIMEM_RAM_DYN_CLK_CTL_OFFS                                             (SAIL_TO_MD_OCIMEM_CSR_REG_BASE_OFFS + 0x30u)
#define HWIO_SAIL_TO_MD_OCIMEM_RAM_DYN_CLK_CTL_RMSK                                             0x800001f3ul
#define HWIO_SAIL_TO_MD_OCIMEM_RAM_DYN_CLK_CTL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_OCIMEM_RAM_DYN_CLK_CTL_ADDR)
#define HWIO_SAIL_TO_MD_OCIMEM_RAM_DYN_CLK_CTL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_OCIMEM_RAM_DYN_CLK_CTL_ADDR, m)
#define HWIO_SAIL_TO_MD_OCIMEM_RAM_DYN_CLK_CTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_OCIMEM_RAM_DYN_CLK_CTL_ADDR,v)
#define HWIO_SAIL_TO_MD_OCIMEM_RAM_DYN_CLK_CTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_OCIMEM_RAM_DYN_CLK_CTL_ADDR,m,v,HWIO_SAIL_TO_MD_OCIMEM_RAM_DYN_CLK_CTL_IN)
#define HWIO_SAIL_TO_MD_OCIMEM_RAM_DYN_CLK_CTL_RAM_DYN_CLK_EN_BMSK                              0x80000000ul
#define HWIO_SAIL_TO_MD_OCIMEM_RAM_DYN_CLK_CTL_RAM_DYN_CLK_EN_SHFT                                      31u
#define HWIO_SAIL_TO_MD_OCIMEM_RAM_DYN_CLK_CTL_RAM_DYN_CLK_EN_RAM_DYN_CLK_DISABLED_FVAL                0x0u
#define HWIO_SAIL_TO_MD_OCIMEM_RAM_DYN_CLK_CTL_RAM_DYN_CLK_EN_RAM_DYN_CLK_ENABLED_FVAL                 0x1u
#define HWIO_SAIL_TO_MD_OCIMEM_RAM_DYN_CLK_CTL_RAM_DYN_HYST_COUNTER_BMSK                             0x1f0u
#define HWIO_SAIL_TO_MD_OCIMEM_RAM_DYN_CLK_CTL_RAM_DYN_HYST_COUNTER_SHFT                                 4u
#define HWIO_SAIL_TO_MD_OCIMEM_RAM_DYN_CLK_CTL_RAM_DYN_WAIT_COUNTER_BMSK                               0x3u
#define HWIO_SAIL_TO_MD_OCIMEM_RAM_DYN_CLK_CTL_RAM_DYN_WAIT_COUNTER_SHFT                                 0u

#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_TIMERS_ADDR                                                (SAIL_TO_MD_OCIMEM_CSR_REG_BASE      + 0x34u)
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_TIMERS_OFFS                                                (SAIL_TO_MD_OCIMEM_CSR_REG_BASE_OFFS + 0x34u)
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_TIMERS_RMSK                                                     0xf0fu
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_TIMERS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_OCIMEM_PSCGC_TIMERS_ADDR)
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_TIMERS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_OCIMEM_PSCGC_TIMERS_ADDR, m)
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_TIMERS_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_OCIMEM_PSCGC_TIMERS_ADDR,v)
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_TIMERS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_OCIMEM_PSCGC_TIMERS_ADDR,m,v,HWIO_SAIL_TO_MD_OCIMEM_PSCGC_TIMERS_IN)
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_TIMERS_TO_SLEEP_COUNTER_BMSK                                    0xf00u
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_TIMERS_TO_SLEEP_COUNTER_SHFT                                        8u
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_TIMERS_WAKEUP_COUNTER_BMSK                                        0xfu
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_TIMERS_WAKEUP_COUNTER_SHFT                                          0u

#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_STAT_ADDR                                                  (SAIL_TO_MD_OCIMEM_CSR_REG_BASE      + 0x38u)
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_STAT_OFFS                                                  (SAIL_TO_MD_OCIMEM_CSR_REG_BASE_OFFS + 0x38u)
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_STAT_RMSK                                                         0xfu
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_STAT_IN                    \
                in_dword(HWIO_SAIL_TO_MD_OCIMEM_PSCGC_STAT_ADDR)
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_STAT_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_OCIMEM_PSCGC_STAT_ADDR, m)
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_STAT_M3_PSCGC_CLKOFF_BMSK                                         0x8u
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_STAT_M3_PSCGC_CLKOFF_SHFT                                           3u
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_STAT_M3_PSCGC_CLKOFF_CLK_IS_ON_FVAL                               0x0u
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_STAT_M3_PSCGC_CLKOFF_CLK_IS_OFF_FVAL                              0x1u
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_STAT_M2_PSCGC_CLKOFF_BMSK                                         0x4u
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_STAT_M2_PSCGC_CLKOFF_SHFT                                           2u
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_STAT_M2_PSCGC_CLKOFF_CLK_IS_ON_FVAL                               0x0u
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_STAT_M2_PSCGC_CLKOFF_CLK_IS_OFF_FVAL                              0x1u
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_STAT_M1_PSCGC_CLKOFF_BMSK                                         0x2u
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_STAT_M1_PSCGC_CLKOFF_SHFT                                           1u
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_STAT_M1_PSCGC_CLKOFF_CLK_IS_ON_FVAL                               0x0u
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_STAT_M1_PSCGC_CLKOFF_CLK_IS_OFF_FVAL                              0x1u
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_STAT_M0_PSCGC_CLKOFF_BMSK                                         0x1u
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_STAT_M0_PSCGC_CLKOFF_SHFT                                           0u
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_STAT_M0_PSCGC_CLKOFF_CLK_IS_ON_FVAL                               0x0u
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_STAT_M0_PSCGC_CLKOFF_CLK_IS_OFF_FVAL                              0x1u

#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_M0_M7_CTL_ADDR                                             (SAIL_TO_MD_OCIMEM_CSR_REG_BASE      + 0x3cu)
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_M0_M7_CTL_OFFS                                             (SAIL_TO_MD_OCIMEM_CSR_REG_BASE_OFFS + 0x3cu)
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_M0_M7_CTL_RMSK                                                 0x7777u
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_M0_M7_CTL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_OCIMEM_PSCGC_M0_M7_CTL_ADDR)
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_M0_M7_CTL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_OCIMEM_PSCGC_M0_M7_CTL_ADDR, m)
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_M0_M7_CTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_OCIMEM_PSCGC_M0_M7_CTL_ADDR,v)
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_M0_M7_CTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_OCIMEM_PSCGC_M0_M7_CTL_ADDR,m,v,HWIO_SAIL_TO_MD_OCIMEM_PSCGC_M0_M7_CTL_IN)
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_M0_M7_CTL_M3_PSCGC_CTL_BMSK                                    0x7000u
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_M0_M7_CTL_M3_PSCGC_CTL_SHFT                                        12u
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_M0_M7_CTL_M2_PSCGC_CTL_BMSK                                     0x700u
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_M0_M7_CTL_M2_PSCGC_CTL_SHFT                                         8u
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_M0_M7_CTL_M1_PSCGC_CTL_BMSK                                      0x70u
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_M0_M7_CTL_M1_PSCGC_CTL_SHFT                                         4u
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_M0_M7_CTL_M0_PSCGC_CTL_BMSK                                       0x7u
#define HWIO_SAIL_TO_MD_OCIMEM_PSCGC_M0_M7_CTL_M0_PSCGC_CTL_SHFT                                         0u

#define HWIO_SAIL_TO_MD_OCIMEM_ERR_ADDRESS_ADDR                                                 (SAIL_TO_MD_OCIMEM_CSR_REG_BASE      + 0x60u)
#define HWIO_SAIL_TO_MD_OCIMEM_ERR_ADDRESS_OFFS                                                 (SAIL_TO_MD_OCIMEM_CSR_REG_BASE_OFFS + 0x60u)
#define HWIO_SAIL_TO_MD_OCIMEM_ERR_ADDRESS_RMSK                                                 0xfffffffful
#define HWIO_SAIL_TO_MD_OCIMEM_ERR_ADDRESS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_OCIMEM_ERR_ADDRESS_ADDR)
#define HWIO_SAIL_TO_MD_OCIMEM_ERR_ADDRESS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_OCIMEM_ERR_ADDRESS_ADDR, m)
#define HWIO_SAIL_TO_MD_OCIMEM_ERR_ADDRESS_ERROR_ADDRESS_BMSK                                   0xfffffffful
#define HWIO_SAIL_TO_MD_OCIMEM_ERR_ADDRESS_ERROR_ADDRESS_SHFT                                            0u

#define HWIO_SAIL_TO_MD_OCIMEM_AXI_ERR_SYNDROME_ADDR                                            (SAIL_TO_MD_OCIMEM_CSR_REG_BASE      + 0x64u)
#define HWIO_SAIL_TO_MD_OCIMEM_AXI_ERR_SYNDROME_OFFS                                            (SAIL_TO_MD_OCIMEM_CSR_REG_BASE_OFFS + 0x64u)
#define HWIO_SAIL_TO_MD_OCIMEM_AXI_ERR_SYNDROME_RMSK                                            0xffff7f3ful
#define HWIO_SAIL_TO_MD_OCIMEM_AXI_ERR_SYNDROME_IN                    \
                in_dword(HWIO_SAIL_TO_MD_OCIMEM_AXI_ERR_SYNDROME_ADDR)
#define HWIO_SAIL_TO_MD_OCIMEM_AXI_ERR_SYNDROME_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_OCIMEM_AXI_ERR_SYNDROME_ADDR, m)
#define HWIO_SAIL_TO_MD_OCIMEM_AXI_ERR_SYNDROME_ERROR_ABID_BMSK                                 0xe0000000ul
#define HWIO_SAIL_TO_MD_OCIMEM_AXI_ERR_SYNDROME_ERROR_ABID_SHFT                                         29u
#define HWIO_SAIL_TO_MD_OCIMEM_AXI_ERR_SYNDROME_ERROR_APID_BMSK                                 0x1f000000ul
#define HWIO_SAIL_TO_MD_OCIMEM_AXI_ERR_SYNDROME_ERROR_APID_SHFT                                         24u
#define HWIO_SAIL_TO_MD_OCIMEM_AXI_ERR_SYNDROME_ERROR_AMID_BMSK                                   0xff0000ul
#define HWIO_SAIL_TO_MD_OCIMEM_AXI_ERR_SYNDROME_ERROR_AMID_SHFT                                         16u
#define HWIO_SAIL_TO_MD_OCIMEM_AXI_ERR_SYNDROME_ERROR_ATID_BMSK                                     0x7f00u
#define HWIO_SAIL_TO_MD_OCIMEM_AXI_ERR_SYNDROME_ERROR_ATID_SHFT                                          8u
#define HWIO_SAIL_TO_MD_OCIMEM_AXI_ERR_SYNDROME_ERROR_ABURST_BMSK                                     0x20u
#define HWIO_SAIL_TO_MD_OCIMEM_AXI_ERR_SYNDROME_ERROR_ABURST_SHFT                                        5u
#define HWIO_SAIL_TO_MD_OCIMEM_AXI_ERR_SYNDROME_ERROR_AWRITE_BMSK                                     0x10u
#define HWIO_SAIL_TO_MD_OCIMEM_AXI_ERR_SYNDROME_ERROR_AWRITE_SHFT                                        4u
#define HWIO_SAIL_TO_MD_OCIMEM_AXI_ERR_SYNDROME_ERROR_ALEN_BMSK                                        0xfu
#define HWIO_SAIL_TO_MD_OCIMEM_AXI_ERR_SYNDROME_ERROR_ALEN_SHFT                                          0u

#define HWIO_SAIL_TO_MD_OCIMEM_DEBUG_CTL_ADDR                                                   (SAIL_TO_MD_OCIMEM_CSR_REG_BASE      + 0x68u)
#define HWIO_SAIL_TO_MD_OCIMEM_DEBUG_CTL_OFFS                                                   (SAIL_TO_MD_OCIMEM_CSR_REG_BASE_OFFS + 0x68u)
#define HWIO_SAIL_TO_MD_OCIMEM_DEBUG_CTL_RMSK                                                        0x10fu
#define HWIO_SAIL_TO_MD_OCIMEM_DEBUG_CTL_IN                    \
                in_dword(HWIO_SAIL_TO_MD_OCIMEM_DEBUG_CTL_ADDR)
#define HWIO_SAIL_TO_MD_OCIMEM_DEBUG_CTL_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_OCIMEM_DEBUG_CTL_ADDR, m)
#define HWIO_SAIL_TO_MD_OCIMEM_DEBUG_CTL_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_OCIMEM_DEBUG_CTL_ADDR,v)
#define HWIO_SAIL_TO_MD_OCIMEM_DEBUG_CTL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_OCIMEM_DEBUG_CTL_ADDR,m,v,HWIO_SAIL_TO_MD_OCIMEM_DEBUG_CTL_IN)
#define HWIO_SAIL_TO_MD_OCIMEM_DEBUG_CTL_DEBUG_BUS_EN_BMSK                                           0x100u
#define HWIO_SAIL_TO_MD_OCIMEM_DEBUG_CTL_DEBUG_BUS_EN_SHFT                                               8u
#define HWIO_SAIL_TO_MD_OCIMEM_DEBUG_CTL_DEBUG_BUS_EN_DEBUG_BUS_DISABLE_FVAL                           0x0u
#define HWIO_SAIL_TO_MD_OCIMEM_DEBUG_CTL_DEBUG_BUS_EN_DEBUG_BUS_ENABLE_FVAL                            0x1u
#define HWIO_SAIL_TO_MD_OCIMEM_DEBUG_CTL_DEBUG_BUS_SEL_BMSK                                            0xfu
#define HWIO_SAIL_TO_MD_OCIMEM_DEBUG_CTL_DEBUG_BUS_SEL_SHFT                                              0u

#define HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_STATUS_ADDR                                             (SAIL_TO_MD_OCIMEM_CSR_REG_BASE      + 0x6cu)
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_STATUS_OFFS                                             (SAIL_TO_MD_OCIMEM_CSR_REG_BASE_OFFS + 0x6cu)
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_STATUS_RMSK                                                0x10001ul
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_STATUS_IN                    \
                in_dword(HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_STATUS_ADDR)
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_STATUS_ADDR, m)
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_STATUS_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_STATUS_ADDR,v)
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_STATUS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_STATUS_ADDR,m,v,HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_STATUS_IN)
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_STATUS_MEM_INIT_DONE_BMSK                                  0x10000ul
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_STATUS_MEM_INIT_DONE_SHFT                                       16u
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_STATUS_MEM_INIT_DONE_INIT_NOT_DONE_FVAL                        0x0u
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_STATUS_MEM_INIT_DONE_INIT_DONE_FVAL                            0x1u
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_STATUS_MEM_SCRUB_INIT_BMSK                                     0x1u
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_STATUS_MEM_SCRUB_INIT_SHFT                                       0u
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_STATUS_MEM_SCRUB_INIT_INIT_DISABLE_FVAL                        0x0u
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_STATUS_MEM_SCRUB_INIT_INIT_ENABLE_FVAL                         0x1u

#define HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_CLEAR_ADDR                                              (SAIL_TO_MD_OCIMEM_CSR_REG_BASE      + 0x70u)
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_CLEAR_OFFS                                              (SAIL_TO_MD_OCIMEM_CSR_REG_BASE_OFFS + 0x70u)
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_CLEAR_RMSK                                                     0x1u
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_CLEAR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_CLEAR_ADDR)
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_CLEAR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_CLEAR_ADDR, m)
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_CLEAR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_CLEAR_ADDR,v)
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_CLEAR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_CLEAR_ADDR,m,v,HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_CLEAR_IN)
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_CLEAR_MEM_INIT_STATUS_CLEAR_BMSK                               0x1u
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_CLEAR_MEM_INIT_STATUS_CLEAR_SHFT                                 0u
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_CLEAR_MEM_INIT_STATUS_CLEAR_CLEAR_DISABLE_FVAL                 0x0u
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_INIT_CLEAR_MEM_INIT_STATUS_CLEAR_CLEAR_ENABLE_FVAL                  0x1u

#define HWIO_SAIL_TO_MD_OCIMEM_MEM_SCRUB_DATA_M_ADDR                                            (SAIL_TO_MD_OCIMEM_CSR_REG_BASE      + 0x74u)
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_SCRUB_DATA_M_OFFS                                            (SAIL_TO_MD_OCIMEM_CSR_REG_BASE_OFFS + 0x74u)
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_SCRUB_DATA_M_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_SCRUB_DATA_M_IN                    \
                in_dword(HWIO_SAIL_TO_MD_OCIMEM_MEM_SCRUB_DATA_M_ADDR)
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_SCRUB_DATA_M_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_OCIMEM_MEM_SCRUB_DATA_M_ADDR, m)
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_SCRUB_DATA_M_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_OCIMEM_MEM_SCRUB_DATA_M_ADDR,v)
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_SCRUB_DATA_M_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_OCIMEM_MEM_SCRUB_DATA_M_ADDR,m,v,HWIO_SAIL_TO_MD_OCIMEM_MEM_SCRUB_DATA_M_IN)
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_SCRUB_DATA_M_OCIMEM_MEM_SCRUB_DATA_MSB_BMSK                  0xfffffffful
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_SCRUB_DATA_M_OCIMEM_MEM_SCRUB_DATA_MSB_SHFT                           0u

#define HWIO_SAIL_TO_MD_OCIMEM_MEM_SCRUB_DATA_L_ADDR                                            (SAIL_TO_MD_OCIMEM_CSR_REG_BASE      + 0x78u)
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_SCRUB_DATA_L_OFFS                                            (SAIL_TO_MD_OCIMEM_CSR_REG_BASE_OFFS + 0x78u)
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_SCRUB_DATA_L_RMSK                                            0xfffffffful
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_SCRUB_DATA_L_IN                    \
                in_dword(HWIO_SAIL_TO_MD_OCIMEM_MEM_SCRUB_DATA_L_ADDR)
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_SCRUB_DATA_L_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_OCIMEM_MEM_SCRUB_DATA_L_ADDR, m)
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_SCRUB_DATA_L_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_OCIMEM_MEM_SCRUB_DATA_L_ADDR,v)
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_SCRUB_DATA_L_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_OCIMEM_MEM_SCRUB_DATA_L_ADDR,m,v,HWIO_SAIL_TO_MD_OCIMEM_MEM_SCRUB_DATA_L_IN)
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_SCRUB_DATA_L_OCIMEM_MEM_SCRUB_DATA_LSB_BMSK                  0xfffffffful
#define HWIO_SAIL_TO_MD_OCIMEM_MEM_SCRUB_DATA_L_OCIMEM_MEM_SCRUB_DATA_LSB_SHFT                           0u

#define HWIO_SAIL_TO_MD_OCIMEM_ECC_DED_SLVERR_RESP_ENABLE_ADDR                                  (SAIL_TO_MD_OCIMEM_CSR_REG_BASE      + 0x7cu)
#define HWIO_SAIL_TO_MD_OCIMEM_ECC_DED_SLVERR_RESP_ENABLE_OFFS                                  (SAIL_TO_MD_OCIMEM_CSR_REG_BASE_OFFS + 0x7cu)
#define HWIO_SAIL_TO_MD_OCIMEM_ECC_DED_SLVERR_RESP_ENABLE_RMSK                                     0x10001ul
#define HWIO_SAIL_TO_MD_OCIMEM_ECC_DED_SLVERR_RESP_ENABLE_IN                    \
                in_dword(HWIO_SAIL_TO_MD_OCIMEM_ECC_DED_SLVERR_RESP_ENABLE_ADDR)
#define HWIO_SAIL_TO_MD_OCIMEM_ECC_DED_SLVERR_RESP_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_OCIMEM_ECC_DED_SLVERR_RESP_ENABLE_ADDR, m)
#define HWIO_SAIL_TO_MD_OCIMEM_ECC_DED_SLVERR_RESP_ENABLE_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_OCIMEM_ECC_DED_SLVERR_RESP_ENABLE_ADDR,v)
#define HWIO_SAIL_TO_MD_OCIMEM_ECC_DED_SLVERR_RESP_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_OCIMEM_ECC_DED_SLVERR_RESP_ENABLE_ADDR,m,v,HWIO_SAIL_TO_MD_OCIMEM_ECC_DED_SLVERR_RESP_ENABLE_IN)
#define HWIO_SAIL_TO_MD_OCIMEM_ECC_DED_SLVERR_RESP_ENABLE_RRESP_DED_SLVERR_ENABLE_BMSK             0x10000ul
#define HWIO_SAIL_TO_MD_OCIMEM_ECC_DED_SLVERR_RESP_ENABLE_RRESP_DED_SLVERR_ENABLE_SHFT                  16u
#define HWIO_SAIL_TO_MD_OCIMEM_ECC_DED_SLVERR_RESP_ENABLE_RRESP_DED_SLVERR_ENABLE_ENABLE_FVAL          0x0u
#define HWIO_SAIL_TO_MD_OCIMEM_ECC_DED_SLVERR_RESP_ENABLE_RRESP_DED_SLVERR_ENABLE_DISABLE_FVAL         0x1u
#define HWIO_SAIL_TO_MD_OCIMEM_ECC_DED_SLVERR_RESP_ENABLE_BRESP_DED_SLVERR_ENABLE_BMSK                 0x1u
#define HWIO_SAIL_TO_MD_OCIMEM_ECC_DED_SLVERR_RESP_ENABLE_BRESP_DED_SLVERR_ENABLE_SHFT                   0u
#define HWIO_SAIL_TO_MD_OCIMEM_ECC_DED_SLVERR_RESP_ENABLE_BRESP_DED_SLVERR_ENABLE_ENABLE_FVAL          0x0u
#define HWIO_SAIL_TO_MD_OCIMEM_ECC_DED_SLVERR_RESP_ENABLE_BRESP_DED_SLVERR_ENABLE_DISABLE_FVAL         0x1u

#define HWIO_SAIL_TO_MD_OCIMEM_FUSA_ERROR_WARNING_CLEAR_ADDR                                    (SAIL_TO_MD_OCIMEM_CSR_REG_BASE      + 0x80u)
#define HWIO_SAIL_TO_MD_OCIMEM_FUSA_ERROR_WARNING_CLEAR_OFFS                                    (SAIL_TO_MD_OCIMEM_CSR_REG_BASE_OFFS + 0x80u)
#define HWIO_SAIL_TO_MD_OCIMEM_FUSA_ERROR_WARNING_CLEAR_RMSK                                    0x80000000ul
#define HWIO_SAIL_TO_MD_OCIMEM_FUSA_ERROR_WARNING_CLEAR_IN                    \
                in_dword(HWIO_SAIL_TO_MD_OCIMEM_FUSA_ERROR_WARNING_CLEAR_ADDR)
#define HWIO_SAIL_TO_MD_OCIMEM_FUSA_ERROR_WARNING_CLEAR_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_OCIMEM_FUSA_ERROR_WARNING_CLEAR_ADDR, m)
#define HWIO_SAIL_TO_MD_OCIMEM_FUSA_ERROR_WARNING_CLEAR_OUT(v)            \
                out_dword(HWIO_SAIL_TO_MD_OCIMEM_FUSA_ERROR_WARNING_CLEAR_ADDR,v)
#define HWIO_SAIL_TO_MD_OCIMEM_FUSA_ERROR_WARNING_CLEAR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAIL_TO_MD_OCIMEM_FUSA_ERROR_WARNING_CLEAR_ADDR,m,v,HWIO_SAIL_TO_MD_OCIMEM_FUSA_ERROR_WARNING_CLEAR_IN)
#define HWIO_SAIL_TO_MD_OCIMEM_FUSA_ERROR_WARNING_CLEAR_OCIMEM_ECC_EN_256KB_BMSK                0x80000000ul
#define HWIO_SAIL_TO_MD_OCIMEM_FUSA_ERROR_WARNING_CLEAR_OCIMEM_ECC_EN_256KB_SHFT                        31u
#define HWIO_SAIL_TO_MD_OCIMEM_FUSA_ERROR_WARNING_CLEAR_OCIMEM_ECC_EN_256KB_ENABLE_FVAL                0x0u
#define HWIO_SAIL_TO_MD_OCIMEM_FUSA_ERROR_WARNING_CLEAR_OCIMEM_ECC_EN_256KB_DISABLE_FVAL               0x1u

#define HWIO_SAIL_TO_MD_FUSA_STATUS_REGISTER_OCIMEM_AXI_CLK_RESET_ADDR                          (SAIL_TO_MD_OCIMEM_CSR_REG_BASE      + 0x90u)
#define HWIO_SAIL_TO_MD_FUSA_STATUS_REGISTER_OCIMEM_AXI_CLK_RESET_OFFS                          (SAIL_TO_MD_OCIMEM_CSR_REG_BASE_OFFS + 0x90u)
#define HWIO_SAIL_TO_MD_FUSA_STATUS_REGISTER_OCIMEM_AXI_CLK_RESET_RMSK                              0x1fffu
#define HWIO_SAIL_TO_MD_FUSA_STATUS_REGISTER_OCIMEM_AXI_CLK_RESET_IN                    \
                in_dword(HWIO_SAIL_TO_MD_FUSA_STATUS_REGISTER_OCIMEM_AXI_CLK_RESET_ADDR)
#define HWIO_SAIL_TO_MD_FUSA_STATUS_REGISTER_OCIMEM_AXI_CLK_RESET_INM(m)            \
                in_dword_masked(HWIO_SAIL_TO_MD_FUSA_STATUS_REGISTER_OCIMEM_AXI_CLK_RESET_ADDR, m)
#define HWIO_SAIL_TO_MD_FUSA_STATUS_REGISTER_OCIMEM_AXI_CLK_RESET_HPCNT_BMSK                        0x1f80u
#define HWIO_SAIL_TO_MD_FUSA_STATUS_REGISTER_OCIMEM_AXI_CLK_RESET_HPCNT_SHFT                             7u
#define HWIO_SAIL_TO_MD_FUSA_STATUS_REGISTER_OCIMEM_AXI_CLK_RESET_VPCNT_BMSK                          0x7eu
#define HWIO_SAIL_TO_MD_FUSA_STATUS_REGISTER_OCIMEM_AXI_CLK_RESET_VPCNT_SHFT                             1u
#define HWIO_SAIL_TO_MD_FUSA_STATUS_REGISTER_OCIMEM_AXI_CLK_RESET_FLT_BMSK                             0x1u
#define HWIO_SAIL_TO_MD_FUSA_STATUS_REGISTER_OCIMEM_AXI_CLK_RESET_FLT_SHFT                               0u


#endif /* __G_SAIL_TO_MD_OCIMEM_HWIO_H__ */
