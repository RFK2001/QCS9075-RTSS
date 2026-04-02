#ifndef __SAILDBG_HWIO_H__
#define __SAILDBG_HWIO_H__
/*
===========================================================================
*/
/**
    @file saildbg_hwio.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        SA8775P (LeMansAU) [lemansau_v1.0_p3q3r76_MTO]
 
    This file contains HWIO register definitions for the following modules:
        SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG
        SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_SAIL_SWAOCSR_SAIL_SWAOCSR
        SAILSS_TSCSS_SYS_TSCSS_TSC

    'Include' filters applied: SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE[SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG] SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL[SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG] SAILSS_CLKCTL_SAILSS_CC_FIRST_PASS_TIMEOUT[SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG] SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS[SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG] SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS[SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG] SAILSS_CLKCTL_SAILSS_CC_FIRST_PASS_CURR_TIME[SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG] SAILSS_CLKCTL_SAILSS_CC_MD_RESET_FSM_STATUS[SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG] SAILSS_CLKCTL_SAILSS_CC_MD_RESET_STATUS[SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG] SAILSS_CLKCTL_SAILSS_CC_MD_PS_HOLD_MASK[SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG] SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR[SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG] SAILSS_CLKCTL_SAILSS_CC_RTCU_SCANDUMP_RESET_CTRL[SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG] SAILSS_CLKCTL_SAILSS_CC_WIND_DOWN_TIMER[SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG] SAILSS_CLKCTL_SAILSS_CC_SAVE_CONTENTS_TIMER[SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG] SAILSS_CLKCTL_SAILSS_CC_STOP_CAPTURE_TIMER[SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG] SAILSS_CLKCTL_SAILSS_CC_PREPARE_FOR_RESET_TIMER[SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG] SAILSS_CLKCTL_SAILSS_CC_ABNORM_WKUP_TIMEOUT[SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG] SAILSS_CLKCTL_SAILSS_CC_APB_CBCR[SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG] SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR[SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG] SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR[SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG] SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR[SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG] SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR[SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG] SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR[SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG] SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR[SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG] SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR[SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG] SAILSS_CLKCTL_SAILSS_CC_QSPI_AHB_CBCR[SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG] SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR[SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG] SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWDBGPWRCTRL[SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_SAIL_SWAOCSR_SAIL_SWAOCSR] SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWCSYSPWRCTRL[SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_SAIL_SWAOCSR_SAIL_SWAOCSR] SAILSS_TSCSS_SYS_TSCSS_TSC_CONTROL_CNTCR[SAILSS_TSCSS_SYS_TSCSS_TSC] 

    Generation parameters: 
    { 'filename': 'saildbg_hwio.h',
      'header': '#include "msmhwiobase.h"',
      'module-filter-include': { 'SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG': [ 'SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE',
                                                                                      'SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL',
                                                                                      'SAILSS_CLKCTL_SAILSS_CC_FIRST_PASS_TIMEOUT',
                                                                                      'SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS',
                                                                                      'SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS',
                                                                                      'SAILSS_CLKCTL_SAILSS_CC_FIRST_PASS_CURR_TIME',
                                                                                      'SAILSS_CLKCTL_SAILSS_CC_MD_RESET_FSM_STATUS',
                                                                                      'SAILSS_CLKCTL_SAILSS_CC_MD_RESET_STATUS',
                                                                                      'SAILSS_CLKCTL_SAILSS_CC_MD_PS_HOLD_MASK',
                                                                                      'SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR',
                                                                                      'SAILSS_CLKCTL_SAILSS_CC_RTCU_SCANDUMP_RESET_CTRL',
                                                                                      'SAILSS_CLKCTL_SAILSS_CC_WIND_DOWN_TIMER',
                                                                                      'SAILSS_CLKCTL_SAILSS_CC_SAVE_CONTENTS_TIMER',
                                                                                      'SAILSS_CLKCTL_SAILSS_CC_STOP_CAPTURE_TIMER',
                                                                                      'SAILSS_CLKCTL_SAILSS_CC_PREPARE_FOR_RESET_TIMER',
                                                                                      'SAILSS_CLKCTL_SAILSS_CC_ABNORM_WKUP_TIMEOUT',
                                                                                      'SAILSS_CLKCTL_SAILSS_CC_APB_CBCR',
                                                                                      'SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR',
                                                                                      'SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR',
                                                                                      'SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR',
                                                                                      'SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR',
                                                                                      'SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR',
                                                                                      'SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR',
                                                                                      'SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR',
                                                                                      'SAILSS_CLKCTL_SAILSS_CC_QSPI_AHB_CBCR',
                                                                                      'SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR'],
                                 'SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_SAIL_SWAOCSR_SAIL_SWAOCSR': [ 'SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWDBGPWRCTRL',
                                                                                                                   'SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWCSYSPWRCTRL'],
                                 'SAILSS_TSCSS_SYS_TSCSS_TSC': [ 'SAILSS_TSCSS_SYS_TSCSS_TSC_CONTROL_CNTCR']},
      'modules': [ 'SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG',
                   'SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_SAIL_SWAOCSR_SAIL_SWAOCSR',
                   'SAILSS_TSCSS_SYS_TSCSS_TSC'],
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/crashdbg/inc/8650/saildbg_hwio.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "msmhwiobase.h"

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG
 *--------------------------------------------------------------------------*/

#define SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE                                                 (SAILSS_CLKCTL_SAILSS_CC_BASE      + 0x00010000)
#define SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_SIZE                                            0xf0000
#define SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_USED                                            0x3c000
#define SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_OFFS                                            0x00010000

#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_ADDR                                                     (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE      + 0xc)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_OFFS                                                     (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_OFFS + 0xc)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_RMSK                                                     0x81c0000f
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_IN                    \
                in_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_ADDR)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_ADDR, m)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_OUT(v)            \
                out_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_ADDR,v)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_ADDR,m,v,HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_IN)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_CLK_OFF_BMSK                                             0x80000000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_CLK_OFF_SHFT                                                     31
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_IGNORE_ALL_ARES_BMSK                                      0x1000000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_IGNORE_ALL_ARES_SHFT                                             24
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                    0x800000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                          23
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_CLK_DIS_BMSK                                               0x400000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_CLK_DIS_SHFT                                                     22
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_SW_ONLY_EN_BMSK                                                 0x8
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_SW_ONLY_EN_SHFT                                                   3
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_CLK_ARES_BMSK                                                   0x4
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_CLK_ARES_SHFT                                                     2
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_HW_CTL_BMSK                                                     0x2
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_HW_CTL_SHFT                                                       1
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_CLK_ENABLE_BMSK                                                 0x1
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ASILB_NOC_APB_CBCR_CLK_ENABLE_SHFT                                                   0

#define HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_ADDR                                                          (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE      + 0x3004)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_OFFS                                                          (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_OFFS + 0x3004)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_RMSK                                                          0x81c07ff5
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_IN                    \
                in_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_ADDR)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_ADDR, m)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_OUT(v)            \
                out_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_ADDR,v)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_ADDR,m,v,HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_IN)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_CLK_OFF_BMSK                                                  0x80000000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_CLK_OFF_SHFT                                                          31
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_IGNORE_ALL_ARES_BMSK                                           0x1000000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_IGNORE_ALL_ARES_SHFT                                                  24
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                         0x800000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                               23
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_CLK_DIS_BMSK                                                    0x400000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_CLK_DIS_SHFT                                                          22
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_FORCE_MEM_CORE_ON_BMSK                                            0x4000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_FORCE_MEM_CORE_ON_SHFT                                                14
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_FORCE_MEM_PERIPH_ON_BMSK                                          0x2000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_FORCE_MEM_PERIPH_ON_SHFT                                              13
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_FORCE_MEM_PERIPH_OFF_BMSK                                         0x1000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_FORCE_MEM_PERIPH_OFF_SHFT                                             12
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_WAKEUP_BMSK                                                        0xf00
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_WAKEUP_SHFT                                                            8
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_SLEEP_BMSK                                                          0xf0
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_SLEEP_SHFT                                                             4
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_CLK_ARES_BMSK                                                        0x4
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_CLK_ARES_SHFT                                                          2
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_CLK_ENABLE_BMSK                                                      0x1
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_LPM_PRAM_CBCR_CLK_ENABLE_SHFT                                                        0

#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_ADDR                                                      (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE      + 0x4008)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_OFFS                                                      (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_OFFS + 0x4008)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_RMSK                                                      0x81c0000f
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_IN                    \
                in_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_ADDR)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_ADDR, m)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_OUT(v)            \
                out_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_ADDR,v)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_ADDR,m,v,HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_IN)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_CLK_OFF_BMSK                                              0x80000000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_CLK_OFF_SHFT                                                      31
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_IGNORE_ALL_ARES_BMSK                                       0x1000000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_IGNORE_ALL_ARES_SHFT                                              24
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                     0x800000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                           23
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_CLK_DIS_BMSK                                                0x400000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_CLK_DIS_SHFT                                                      22
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_SW_ONLY_EN_BMSK                                                  0x8
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_SW_ONLY_EN_SHFT                                                    3
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_CLK_ARES_BMSK                                                    0x4
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_CLK_ARES_SHFT                                                      2
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_HW_CTL_BMSK                                                      0x2
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_HW_CTL_SHFT                                                        1
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_CLK_ENABLE_BMSK                                                  0x1
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_CFG_AHB_CBCR_CLK_ENABLE_SHFT                                                    0

#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_ADDR                                                          (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE      + 0x402c)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_OFFS                                                          (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_OFFS + 0x402c)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_RMSK                                                          0x81c0000f
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_IN                    \
                in_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_ADDR)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_ADDR, m)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_OUT(v)            \
                out_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_ADDR,v)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_ADDR,m,v,HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_IN)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_CLK_OFF_BMSK                                                  0x80000000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_CLK_OFF_SHFT                                                          31
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_IGNORE_ALL_ARES_BMSK                                           0x1000000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_IGNORE_ALL_ARES_SHFT                                                  24
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                         0x800000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                               23
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_CLK_DIS_BMSK                                                    0x400000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_CLK_DIS_SHFT                                                          22
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_SW_ONLY_EN_BMSK                                                      0x8
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_SW_ONLY_EN_SHFT                                                        3
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_CLK_ARES_BMSK                                                        0x4
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_CLK_ARES_SHFT                                                          2
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_HW_CTL_BMSK                                                          0x2
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_HW_CTL_SHFT                                                            1
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_CLK_ENABLE_BMSK                                                      0x1
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_DAP_CBCR_CLK_ENABLE_SHFT                                                        0

#define HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_ADDR                                                               (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE      + 0x4030)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_OFFS                                                               (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_OFFS + 0x4030)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_RMSK                                                               0x81c0000f
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_IN                    \
                in_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_ADDR)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_ADDR, m)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_OUT(v)            \
                out_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_ADDR,v)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_ADDR,m,v,HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_IN)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_CLK_OFF_BMSK                                                       0x80000000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_CLK_OFF_SHFT                                                               31
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_IGNORE_ALL_ARES_BMSK                                                0x1000000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_IGNORE_ALL_ARES_SHFT                                                       24
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                              0x800000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                                    23
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_CLK_DIS_BMSK                                                         0x400000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_CLK_DIS_SHFT                                                               22
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_SW_ONLY_EN_BMSK                                                           0x8
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_SW_ONLY_EN_SHFT                                                             3
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_CLK_ARES_BMSK                                                             0x4
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_CLK_ARES_SHFT                                                               2
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_HW_CTL_BMSK                                                               0x2
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_HW_CTL_SHFT                                                                 1
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_CLK_ENABLE_BMSK                                                           0x1
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_APB_CBCR_CLK_ENABLE_SHFT                                                             0

#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_ADDR                                                          (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE      + 0x4034)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_OFFS                                                          (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_OFFS + 0x4034)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_RMSK                                                          0x81c0000f
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_IN                    \
                in_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_ADDR)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_ADDR, m)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_OUT(v)            \
                out_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_ADDR,v)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_ADDR,m,v,HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_IN)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_CLK_OFF_BMSK                                                  0x80000000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_CLK_OFF_SHFT                                                          31
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_IGNORE_ALL_ARES_BMSK                                           0x1000000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_IGNORE_ALL_ARES_SHFT                                                  24
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                         0x800000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                               23
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_CLK_DIS_BMSK                                                    0x400000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_CLK_DIS_SHFT                                                          22
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_SW_ONLY_EN_BMSK                                                      0x8
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_SW_ONLY_EN_SHFT                                                        3
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_CLK_ARES_BMSK                                                        0x4
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_CLK_ARES_SHFT                                                          2
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_HW_CTL_BMSK                                                          0x2
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_HW_CTL_SHFT                                                            1
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_CLK_ENABLE_BMSK                                                      0x1
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SWAO_APB_CBCR_CLK_ENABLE_SHFT                                                        0

#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR_ADDR                                                           (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE      + 0x4038)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR_OFFS                                                           (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_OFFS + 0x4038)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR_RMSK                                                           0x81c0000f
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR_IN                    \
                in_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR_ADDR)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR_ADDR, m)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR_OUT(v)            \
                out_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR_ADDR,v)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR_ADDR,m,v,HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR_IN)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR_CLK_OFF_BMSK                                                   0x80000000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR_CLK_OFF_SHFT                                                           31
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR_IGNORE_ALL_ARES_BMSK                                            0x1000000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR_IGNORE_ALL_ARES_SHFT                                                   24
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                          0x800000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                                23
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR_CLK_DIS_BMSK                                                     0x400000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR_CLK_DIS_SHFT                                                           22
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR_SW_ONLY_EN_BMSK                                                       0x8
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR_SW_ONLY_EN_SHFT                                                         3
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR_CLK_ARES_BMSK                                                         0x4
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR_CLK_ARES_SHFT                                                           2
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR_HW_CTL_BMSK                                                           0x2
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR_HW_CTL_SHFT                                                             1
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR_CLK_ENABLE_BMSK                                                       0x1
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QDSS_XO_CBCR_CLK_ENABLE_SHFT                                                         0

#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR_ADDR                                                             (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE      + 0xd020)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR_OFFS                                                             (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_OFFS + 0xd020)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR_RMSK                                                             0x81c00005
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR_IN                    \
                in_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR_ADDR)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR_ADDR, m)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR_OUT(v)            \
                out_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR_ADDR,v)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR_ADDR,m,v,HWIO_SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR_IN)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR_CLK_OFF_BMSK                                                     0x80000000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR_CLK_OFF_SHFT                                                             31
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR_IGNORE_ALL_ARES_BMSK                                              0x1000000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR_IGNORE_ALL_ARES_SHFT                                                     24
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                            0x800000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                                  23
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR_CLK_DIS_BMSK                                                       0x400000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR_CLK_DIS_SHFT                                                             22
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR_CLK_ARES_BMSK                                                           0x4
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR_CLK_ARES_SHFT                                                             2
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR_CLK_ENABLE_BMSK                                                         0x1
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DEMET_CBCR_CLK_ENABLE_SHFT                                                           0

#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_ADDR                                                           (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE      + 0x1b000)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_OFFS                                                           (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_OFFS + 0x1b000)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_RMSK                                                           0x81c07fff
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_IN                    \
                in_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_ADDR)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_ADDR, m)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_OUT(v)            \
                out_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_ADDR,v)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_ADDR,m,v,HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_IN)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_CLK_OFF_BMSK                                                   0x80000000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_CLK_OFF_SHFT                                                           31
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_IGNORE_ALL_ARES_BMSK                                            0x1000000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_IGNORE_ALL_ARES_SHFT                                                   24
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                          0x800000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                                23
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_CLK_DIS_BMSK                                                     0x400000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_CLK_DIS_SHFT                                                           22
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_FORCE_MEM_CORE_ON_BMSK                                             0x4000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_FORCE_MEM_CORE_ON_SHFT                                                 14
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_FORCE_MEM_PERIPH_ON_BMSK                                           0x2000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_FORCE_MEM_PERIPH_ON_SHFT                                               13
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_FORCE_MEM_PERIPH_OFF_BMSK                                          0x1000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_FORCE_MEM_PERIPH_OFF_SHFT                                              12
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_WAKEUP_BMSK                                                         0xf00
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_WAKEUP_SHFT                                                             8
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_SLEEP_BMSK                                                           0xf0
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_SLEEP_SHFT                                                              4
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_SW_ONLY_EN_BMSK                                                       0x8
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_SW_ONLY_EN_SHFT                                                         3
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_CLK_ARES_BMSK                                                         0x4
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_CLK_ARES_SHFT                                                           2
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_HW_CTL_BMSK                                                           0x2
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_HW_CTL_SHFT                                                             1
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_CLK_ENABLE_BMSK                                                       0x1
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_DCC_AHB_CBCR_CLK_ENABLE_SHFT                                                         0

#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_AHB_CBCR_ADDR                                                          (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE      + 0x1d004)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_AHB_CBCR_OFFS                                                          (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_OFFS + 0x1d004)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_AHB_CBCR_RMSK                                                          0x81c00005
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_AHB_CBCR_IN                    \
                in_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_AHB_CBCR_ADDR)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_AHB_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_AHB_CBCR_ADDR, m)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_AHB_CBCR_OUT(v)            \
                out_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_AHB_CBCR_ADDR,v)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_AHB_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_AHB_CBCR_ADDR,m,v,HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_AHB_CBCR_IN)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_AHB_CBCR_CLK_OFF_BMSK                                                  0x80000000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_AHB_CBCR_CLK_OFF_SHFT                                                          31
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_AHB_CBCR_IGNORE_ALL_ARES_BMSK                                           0x1000000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_AHB_CBCR_IGNORE_ALL_ARES_SHFT                                                  24
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_AHB_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                         0x800000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_AHB_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                               23
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_AHB_CBCR_CLK_DIS_BMSK                                                    0x400000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_AHB_CBCR_CLK_DIS_SHFT                                                          22
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_AHB_CBCR_CLK_ARES_BMSK                                                        0x4
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_AHB_CBCR_CLK_ARES_SHFT                                                          2
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_AHB_CBCR_CLK_ENABLE_BMSK                                                      0x1
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_AHB_CBCR_CLK_ENABLE_SHFT                                                        0

#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR_ADDR                                                         (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE      + 0x1d008)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR_OFFS                                                         (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_OFFS + 0x1d008)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR_RMSK                                                         0x81c00005
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR_IN                    \
                in_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR_ADDR)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR_ADDR, m)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR_OUT(v)            \
                out_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR_ADDR,v)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR_ADDR,m,v,HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR_IN)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR_CLK_OFF_BMSK                                                 0x80000000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR_CLK_OFF_SHFT                                                         31
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR_IGNORE_ALL_ARES_BMSK                                          0x1000000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR_IGNORE_ALL_ARES_SHFT                                                 24
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR_IGNORE_ALL_CLK_DIS_BMSK                                        0x800000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR_IGNORE_ALL_CLK_DIS_SHFT                                              23
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR_CLK_DIS_BMSK                                                   0x400000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR_CLK_DIS_SHFT                                                         22
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR_CLK_ARES_BMSK                                                       0x4
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR_CLK_ARES_SHFT                                                         2
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR_CLK_ENABLE_BMSK                                                     0x1
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_QSPI_CORE_CBCR_CLK_ENABLE_SHFT                                                       0

#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RTCU_SCANDUMP_RESET_CTRL_ADDR                                               (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE      + 0x24600)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RTCU_SCANDUMP_RESET_CTRL_OFFS                                               (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_OFFS + 0x24600)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RTCU_SCANDUMP_RESET_CTRL_RMSK                                                      0x3
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RTCU_SCANDUMP_RESET_CTRL_IN                    \
                in_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_RTCU_SCANDUMP_RESET_CTRL_ADDR)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RTCU_SCANDUMP_RESET_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CLKCTL_SAILSS_CC_RTCU_SCANDUMP_RESET_CTRL_ADDR, m)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RTCU_SCANDUMP_RESET_CTRL_OUT(v)            \
                out_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_RTCU_SCANDUMP_RESET_CTRL_ADDR,v)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RTCU_SCANDUMP_RESET_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CLKCTL_SAILSS_CC_RTCU_SCANDUMP_RESET_CTRL_ADDR,m,v,HWIO_SAILSS_CLKCTL_SAILSS_CC_RTCU_SCANDUMP_RESET_CTRL_IN)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RTCU_SCANDUMP_RESET_CTRL_CLUSTER1_RESET_BMSK                                       0x2
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RTCU_SCANDUMP_RESET_CTRL_CLUSTER1_RESET_SHFT                                         1
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RTCU_SCANDUMP_RESET_CTRL_CLUSTER0_RESET_BMSK                                       0x1
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RTCU_SCANDUMP_RESET_CTRL_CLUSTER0_RESET_SHFT                                         0

#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_ADDR                                                     (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE      + 0x39000)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_OFFS                                                     (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_OFFS + 0x39000)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_RMSK                                                     0xffffffff
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_IN                    \
                in_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_ADDR)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_ADDR, m)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_OUT(v)            \
                out_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_ADDR,v)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_ADDR,m,v,HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_IN)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_RESERVED_BITS31_15_BMSK                                  0xffff8000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_RESERVED_BITS31_15_SHFT                                          15
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_FUNC_CLK_DIS_IN_SP_EN_BMSK                                   0x4000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_FUNC_CLK_DIS_IN_SP_EN_SHFT                                       14
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_SW_BASED_PRE_ARES_BMSK                                       0x2000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_SW_BASED_PRE_ARES_SHFT                                           13
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_PRE_SW_SRST_TMR_EN_BMSK                                      0x1000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_PRE_SW_SRST_TMR_EN_SHFT                                          12
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_DISABLE_APCS_ALT_ARES_BMSK                                    0x800
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_DISABLE_APCS_ALT_ARES_SHFT                                       11
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_ALLOW_OTHER_RST_DBG_EN_BMSK                                   0x400
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_ALLOW_OTHER_RST_DBG_EN_SHFT                                      10
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_MD_PS_HOLD_RST_DEBUG_EN_BMSK                                  0x200
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_MD_PS_HOLD_RST_DEBUG_EN_SHFT                                      9
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_MD_PMIC_FAULT_RST_DEBUG_EN_BMSK                               0x100
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_MD_PMIC_FAULT_RST_DEBUG_EN_SHFT                                   8
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_PWR_SEQ_WDOG_RST_DEBUG_EN_BMSK                                 0x80
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_PWR_SEQ_WDOG_RST_DEBUG_EN_SHFT                                    7
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_R52_WDOG_RESET_DEBUG_EN_BMSK                                   0x40
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_R52_WDOG_RESET_DEBUG_EN_SHFT                                      6
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_SAIL_TSENSE_RESET_DEBUG_EN_BMSK                                0x20
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_SAIL_TSENSE_RESET_DEBUG_EN_SHFT                                   5
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_PMIC_RESIN_RESET_DEBUG_EN_BMSK                                 0x10
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_PMIC_RESIN_RESET_DEBUG_EN_SHFT                                    4
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_PROC_HALT_EN_BMSK                                               0x8
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_PROC_HALT_EN_SHFT                                                 3
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_AUTO_PS_HOLD_SET_EN_BMSK                                        0x4
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_AUTO_PS_HOLD_SET_EN_SHFT                                          2
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_ACCESS_RESET_FIRST_PASS_EN_BMSK                                 0x2
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_ACCESS_RESET_FIRST_PASS_EN_SHFT                                   1
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_DEBUG_RESET_FIRST_PASS_EN_BMSK                                  0x1
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_DEBUG_ENABLE_DEBUG_RESET_FIRST_PASS_EN_SHFT                                    0

#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_ADDR                                                         (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE      + 0x39004)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_OFFS                                                         (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_OFFS + 0x39004)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_RMSK                                                         0xffffffff
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_IN                    \
                in_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_ADDR)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_ADDR, m)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_OUT(v)            \
                out_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_ADDR,v)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_ADDR,m,v,HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_IN)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_RESERVED_BITS31_17_BMSK                                      0xfffe0000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_RESERVED_BITS31_17_SHFT                                              17
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_ALLOW_SRST_PWR_CTRL_BMSK                                        0x10000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_ALLOW_SRST_PWR_CTRL_SHFT                                             16
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_DCC_TO_PREP_HALT_EN_BMSK                                         0x8000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_DCC_TO_PREP_HALT_EN_SHFT                                             15
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_SYS_WKUP_WO_AOP_EN_BMSK                                          0x4000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_SYS_WKUP_WO_AOP_EN_SHFT                                              14
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_NO_OF_ALLOW_RST_IN_SP_BMSK                                       0x3c00
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_NO_OF_ALLOW_RST_IN_SP_SHFT                                           10
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_SECOND_PASS_COMPLETE_BMSK                                         0x200
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_SECOND_PASS_COMPLETE_SHFT                                             9
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_DDR_OUT_OF_SELF_RFRSH_BMSK                                        0x100
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_DDR_OUT_OF_SELF_RFRSH_SHFT                                            8
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_DDR_SELF_RFRSH_TMR_EN_BMSK                                         0x80
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_DDR_SELF_RFRSH_TMR_EN_SHFT                                            7
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_BLOCK_PCIE_ARES_BMSK                                               0x40
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_BLOCK_PCIE_ARES_SHFT                                                  6
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_PCIE_LINK_TMR_EN_BMSK                                              0x20
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_PCIE_LINK_TMR_EN_SHFT                                                 5
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_WKUP_TMR_EN_BMSK                                                   0x10
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_WKUP_TMR_EN_SHFT                                                      4
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_NORMAL_WKUP_EN_BMSK                                                 0x8
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_NORMAL_WKUP_EN_SHFT                                                   3
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_FIRST_PASS_TMR_EN_BMSK                                              0x4
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_FIRST_PASS_TMR_EN_SHFT                                                2
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_FIRST_PASS_COMPLETE_BMSK                                            0x2
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_FIRST_PASS_COMPLETE_SHFT                                              1
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_BLOCK_RESIN_BMSK                                                    0x1
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_CTRL_BLOCK_RESIN_SHFT                                                      0

#define HWIO_SAILSS_CLKCTL_SAILSS_CC_WIND_DOWN_TIMER_ADDR                                                        (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE      + 0x39008)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_WIND_DOWN_TIMER_OFFS                                                        (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_OFFS + 0x39008)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_WIND_DOWN_TIMER_RMSK                                                        0xffffffff
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_WIND_DOWN_TIMER_IN                    \
                in_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_WIND_DOWN_TIMER_ADDR)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_WIND_DOWN_TIMER_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CLKCTL_SAILSS_CC_WIND_DOWN_TIMER_ADDR, m)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_WIND_DOWN_TIMER_OUT(v)            \
                out_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_WIND_DOWN_TIMER_ADDR,v)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_WIND_DOWN_TIMER_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CLKCTL_SAILSS_CC_WIND_DOWN_TIMER_ADDR,m,v,HWIO_SAILSS_CLKCTL_SAILSS_CC_WIND_DOWN_TIMER_IN)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_WIND_DOWN_TIMER_RESERVE_BITS31_16_BMSK                                      0xffff0000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_WIND_DOWN_TIMER_RESERVE_BITS31_16_SHFT                                              16
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_WIND_DOWN_TIMER_TIMER_VAL_BMSK                                                  0xffff
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_WIND_DOWN_TIMER_TIMER_VAL_SHFT                                                       0

#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SAVE_CONTENTS_TIMER_ADDR                                                    (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE      + 0x3900c)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SAVE_CONTENTS_TIMER_OFFS                                                    (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_OFFS + 0x3900c)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SAVE_CONTENTS_TIMER_RMSK                                                    0xffffffff
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SAVE_CONTENTS_TIMER_IN                    \
                in_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_SAVE_CONTENTS_TIMER_ADDR)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SAVE_CONTENTS_TIMER_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CLKCTL_SAILSS_CC_SAVE_CONTENTS_TIMER_ADDR, m)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SAVE_CONTENTS_TIMER_OUT(v)            \
                out_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_SAVE_CONTENTS_TIMER_ADDR,v)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SAVE_CONTENTS_TIMER_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CLKCTL_SAILSS_CC_SAVE_CONTENTS_TIMER_ADDR,m,v,HWIO_SAILSS_CLKCTL_SAILSS_CC_SAVE_CONTENTS_TIMER_IN)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SAVE_CONTENTS_TIMER_RESERVE_BITS31_16_BMSK                                  0xffff0000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SAVE_CONTENTS_TIMER_RESERVE_BITS31_16_SHFT                                          16
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SAVE_CONTENTS_TIMER_TIMER_VAL_BMSK                                              0xffff
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_SAVE_CONTENTS_TIMER_TIMER_VAL_SHFT                                                   0

#define HWIO_SAILSS_CLKCTL_SAILSS_CC_STOP_CAPTURE_TIMER_ADDR                                                     (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE      + 0x39010)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_STOP_CAPTURE_TIMER_OFFS                                                     (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_OFFS + 0x39010)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_STOP_CAPTURE_TIMER_RMSK                                                     0xffffffff
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_STOP_CAPTURE_TIMER_IN                    \
                in_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_STOP_CAPTURE_TIMER_ADDR)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_STOP_CAPTURE_TIMER_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CLKCTL_SAILSS_CC_STOP_CAPTURE_TIMER_ADDR, m)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_STOP_CAPTURE_TIMER_OUT(v)            \
                out_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_STOP_CAPTURE_TIMER_ADDR,v)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_STOP_CAPTURE_TIMER_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CLKCTL_SAILSS_CC_STOP_CAPTURE_TIMER_ADDR,m,v,HWIO_SAILSS_CLKCTL_SAILSS_CC_STOP_CAPTURE_TIMER_IN)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_STOP_CAPTURE_TIMER_RESERVE_BITS31_16_BMSK                                   0xffff0000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_STOP_CAPTURE_TIMER_RESERVE_BITS31_16_SHFT                                           16
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_STOP_CAPTURE_TIMER_TIMER_VAL_BMSK                                               0xffff
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_STOP_CAPTURE_TIMER_TIMER_VAL_SHFT                                                    0

#define HWIO_SAILSS_CLKCTL_SAILSS_CC_PREPARE_FOR_RESET_TIMER_ADDR                                                (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE      + 0x39014)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_PREPARE_FOR_RESET_TIMER_OFFS                                                (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_OFFS + 0x39014)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_PREPARE_FOR_RESET_TIMER_RMSK                                                0xffffffff
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_PREPARE_FOR_RESET_TIMER_IN                    \
                in_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_PREPARE_FOR_RESET_TIMER_ADDR)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_PREPARE_FOR_RESET_TIMER_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CLKCTL_SAILSS_CC_PREPARE_FOR_RESET_TIMER_ADDR, m)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_PREPARE_FOR_RESET_TIMER_OUT(v)            \
                out_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_PREPARE_FOR_RESET_TIMER_ADDR,v)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_PREPARE_FOR_RESET_TIMER_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CLKCTL_SAILSS_CC_PREPARE_FOR_RESET_TIMER_ADDR,m,v,HWIO_SAILSS_CLKCTL_SAILSS_CC_PREPARE_FOR_RESET_TIMER_IN)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_PREPARE_FOR_RESET_TIMER_RESERVE_BITS31_16_BMSK                              0xffff0000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_PREPARE_FOR_RESET_TIMER_RESERVE_BITS31_16_SHFT                                      16
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_PREPARE_FOR_RESET_TIMER_TIMER_VAL_BMSK                                          0xffff
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_PREPARE_FOR_RESET_TIMER_TIMER_VAL_SHFT                                               0

#define HWIO_SAILSS_CLKCTL_SAILSS_CC_FIRST_PASS_TIMEOUT_ADDR                                                     (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE      + 0x39018)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_FIRST_PASS_TIMEOUT_OFFS                                                     (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_OFFS + 0x39018)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_FIRST_PASS_TIMEOUT_RMSK                                                     0xffffffff
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_FIRST_PASS_TIMEOUT_IN                    \
                in_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_FIRST_PASS_TIMEOUT_ADDR)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_FIRST_PASS_TIMEOUT_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CLKCTL_SAILSS_CC_FIRST_PASS_TIMEOUT_ADDR, m)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_FIRST_PASS_TIMEOUT_OUT(v)            \
                out_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_FIRST_PASS_TIMEOUT_ADDR,v)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_FIRST_PASS_TIMEOUT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CLKCTL_SAILSS_CC_FIRST_PASS_TIMEOUT_ADDR,m,v,HWIO_SAILSS_CLKCTL_SAILSS_CC_FIRST_PASS_TIMEOUT_IN)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_FIRST_PASS_TIMEOUT_TIMER_VAL_BMSK                                           0xffffffff
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_FIRST_PASS_TIMEOUT_TIMER_VAL_SHFT                                                    0

#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_ADDR                                                           (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE      + 0x39020)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_OFFS                                                           (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_OFFS + 0x39020)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_RMSK                                                           0xffffffff
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_IN                    \
                in_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_ADDR)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_ADDR, m)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_OUT(v)            \
                out_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_ADDR,v)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_ADDR,m,v,HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_IN)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_RESERVED_BITS31_14_BMSK                                        0xffffc000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_RESERVED_BITS31_14_SHFT                                                14
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_EUD_SRST_RESET_STATUS_BMSK                                         0x2000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_EUD_SRST_RESET_STATUS_SHFT                                             13
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_MD_PS_HOLD_RAW_STATUS_BMSK                                         0x1000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_MD_PS_HOLD_RAW_STATUS_SHFT                                             12
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_SRST_RESET_STATUS_BMSK                                              0x800
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_SRST_RESET_STATUS_SHFT                                                 11
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_QDSS_SW_SRST_RESET_STATUS_BMSK                                      0x400
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_QDSS_SW_SRST_RESET_STATUS_SHFT                                         10
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_SAIL_PS_HOLD_STATUS_BMSK                                            0x200
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_SAIL_PS_HOLD_STATUS_SHFT                                                9
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_MD_PS_HOLD_RESET_STATUS_BMSK                                        0x100
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_MD_PS_HOLD_RESET_STATUS_SHFT                                            8
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_MD_PMIC_FAULT_RESET_STATUS_BMSK                                      0x80
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_MD_PMIC_FAULT_RESET_STATUS_SHFT                                         7
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_PWR_SEQ_WDOG_EXPIRE_RESET_STATUS_BMSK                                0x40
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_PWR_SEQ_WDOG_EXPIRE_RESET_STATUS_SHFT                                   6
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_SAIL_PMIC_ABNORMAL_RESIN_RESET_STATUS_BMSK                           0x20
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_SAIL_PMIC_ABNORMAL_RESIN_RESET_STATUS_SHFT                              5
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_PROC_HALT_CTI_STATUS_BMSK                                            0x10
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_PROC_HALT_CTI_STATUS_SHFT                                               4
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_SAIL_TSENSE1_RESET_STATUS_BMSK                                        0x8
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_SAIL_TSENSE1_RESET_STATUS_SHFT                                          3
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_SAIL_TSENSE0_RESET_STATUS_BMSK                                        0x4
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_SAIL_TSENSE0_RESET_STATUS_SHFT                                          2
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_PMIC_RESIN_RESET_STATUS_BMSK                                          0x2
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_PMIC_RESIN_RESET_STATUS_SHFT                                            1
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_R52_WDOG_EXPIRE_RESET_STATUS_BMSK                                     0x1
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_R52_WDOG_EXPIRE_RESET_STATUS_SHFT                                       0

#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_ADDR                                                       (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE      + 0x39024)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_OFFS                                                       (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_OFFS + 0x39024)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_RMSK                                                       0x1fffffff
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_IN                    \
                in_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_ADDR)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_ADDR, m)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_OUT(v)            \
                out_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_ADDR,v)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_ADDR,m,v,HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_IN)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_RST_CTL_PS_HLD_ASET_BMSK                                   0x10000000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_RST_CTL_PS_HLD_ASET_SHFT                                           28
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_RST_CTL_PS_HLD_ARES_BMSK                                    0x8000000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_RST_CTL_PS_HLD_ARES_SHFT                                           27
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_EXCEED_ALLOWED_RSTS_IN_SP_BMSK                              0x4000000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_EXCEED_ALLOWED_RSTS_IN_SP_SHFT                                     26
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_NO_OF_RSTS_OCCUR_IN_SP_BMSK                                 0x3c00000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_NO_OF_RSTS_OCCUR_IN_SP_SHFT                                        22
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_DDR_SLF_RFRSH_TMR_EXP_BMSK                                   0x200000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_DDR_SLF_RFRSH_TMR_EXP_SHFT                                         21
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_DDR_SLF_RFRSH_TMR_LD_BMSK                                    0x100000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_DDR_SLF_RFRSH_TMR_LD_SHFT                                          20
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_PCIE_LINK_DN_REQ_BMSK                                         0x80000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_PCIE_LINK_DN_REQ_SHFT                                              19
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_PCIE_LINK_DN_ACK_BMSK                                         0x40000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_PCIE_LINK_DN_ACK_SHFT                                              18
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_BLOCK_PCIE_ARES_BMSK                                          0x20000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_BLOCK_PCIE_ARES_SHFT                                               17
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_ALLOW_PCIE_ARES_BMSK                                          0x10000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_ALLOW_PCIE_ARES_SHFT                                               16
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_PCIE_LINK_TMR_LD_BMSK                                          0x8000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_PCIE_LINK_TMR_LD_SHFT                                              15
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_PCIE_LINK_TMR_EXPIRE_BMSK                                      0x4000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_PCIE_LINK_TMR_EXPIRE_SHFT                                          14
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_DBG_PDC_HANG_STATUS_BMSK                                       0x2000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_DBG_PDC_HANG_STATUS_SHFT                                           13
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_DBG_PDC_TRIGGER_BMSK                                           0x1000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_DBG_PDC_TRIGGER_SHFT                                               12
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_NORM_WKUP_HANG_STATUS_BMSK                                      0x800
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_NORM_WKUP_HANG_STATUS_SHFT                                         11
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_FIRST_PASS_EXPIRE_BMSK                                          0x400
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_FIRST_PASS_EXPIRE_SHFT                                             10
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_FIRST_PASS_TIMER_LD_BMSK                                        0x200
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_FIRST_PASS_TIMER_LD_SHFT                                            9
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_BLOCK_RESIN_ASET_BMSK                                           0x100
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_BLOCK_RESIN_ASET_SHFT                                               8
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_BLOCK_RESIN_ARES_BMSK                                            0x80
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_BLOCK_RESIN_ARES_SHFT                                               7
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_DBG_TIMER_TRIGGER_BMSK                                           0x40
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_DBG_TIMER_TRIGGER_SHFT                                              6
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_RESET_DEBUG_READY_BMSK                                           0x20
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_RESET_DEBUG_READY_SHFT                                              5
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_FIRST_PASS_BMSK                                                  0x10
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_FIRST_PASS_SHFT                                                     4
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_FSM_STATE_BMSK                                                    0xf
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_FSM_STATUS_FSM_STATE_SHFT                                                      0

#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ABNORM_WKUP_TIMEOUT_ADDR                                                    (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE      + 0x39034)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ABNORM_WKUP_TIMEOUT_OFFS                                                    (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_OFFS + 0x39034)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ABNORM_WKUP_TIMEOUT_RMSK                                                    0xffffffff
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ABNORM_WKUP_TIMEOUT_IN                    \
                in_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_ABNORM_WKUP_TIMEOUT_ADDR)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ABNORM_WKUP_TIMEOUT_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CLKCTL_SAILSS_CC_ABNORM_WKUP_TIMEOUT_ADDR, m)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ABNORM_WKUP_TIMEOUT_OUT(v)            \
                out_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_ABNORM_WKUP_TIMEOUT_ADDR,v)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ABNORM_WKUP_TIMEOUT_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CLKCTL_SAILSS_CC_ABNORM_WKUP_TIMEOUT_ADDR,m,v,HWIO_SAILSS_CLKCTL_SAILSS_CC_ABNORM_WKUP_TIMEOUT_IN)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ABNORM_WKUP_TIMEOUT_TIMER_VAL_BMSK                                          0xffffffff
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_ABNORM_WKUP_TIMEOUT_TIMER_VAL_SHFT                                                   0

#define HWIO_SAILSS_CLKCTL_SAILSS_CC_FIRST_PASS_CURR_TIME_ADDR                                                   (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE      + 0x39100)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_FIRST_PASS_CURR_TIME_OFFS                                                   (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_OFFS + 0x39100)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_FIRST_PASS_CURR_TIME_RMSK                                                   0xffffffff
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_FIRST_PASS_CURR_TIME_IN                    \
                in_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_FIRST_PASS_CURR_TIME_ADDR)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_FIRST_PASS_CURR_TIME_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CLKCTL_SAILSS_CC_FIRST_PASS_CURR_TIME_ADDR, m)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_FIRST_PASS_CURR_TIME_TIMER_VAL_BMSK                                         0xffffffff
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_FIRST_PASS_CURR_TIME_TIMER_VAL_SHFT                                                  0

#define HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_RESET_FSM_STATUS_ADDR                                                    (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE      + 0x39400)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_RESET_FSM_STATUS_OFFS                                                    (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_OFFS + 0x39400)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_RESET_FSM_STATUS_RMSK                                                           0xf
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_RESET_FSM_STATUS_IN                    \
                in_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_RESET_FSM_STATUS_ADDR)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_RESET_FSM_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_RESET_FSM_STATUS_ADDR, m)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_RESET_FSM_STATUS_FSM_STATE_BMSK                                                 0xf
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_RESET_FSM_STATUS_FSM_STATE_SHFT                                                   0

#define HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_RESET_STATUS_ADDR                                                        (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE      + 0x39410)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_RESET_STATUS_OFFS                                                        (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_OFFS + 0x39410)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_RESET_STATUS_RMSK                                                           0x1ffff
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_RESET_STATUS_IN                    \
                in_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_RESET_STATUS_ADDR)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_RESET_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_RESET_STATUS_ADDR, m)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_RESET_STATUS_STATUS_REG_16_0_BMSK                                           0x1ffff
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_RESET_STATUS_STATUS_REG_16_0_SHFT                                                 0

#define HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_PS_HOLD_MASK_ADDR                                                        (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE      + 0x39420)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_PS_HOLD_MASK_OFFS                                                        (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_OFFS + 0x39420)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_PS_HOLD_MASK_RMSK                                                        0xffffffff
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_PS_HOLD_MASK_IN                    \
                in_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_PS_HOLD_MASK_ADDR)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_PS_HOLD_MASK_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_PS_HOLD_MASK_ADDR, m)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_PS_HOLD_MASK_OUT(v)            \
                out_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_PS_HOLD_MASK_ADDR,v)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_PS_HOLD_MASK_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_PS_HOLD_MASK_ADDR,m,v,HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_PS_HOLD_MASK_IN)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_PS_HOLD_MASK_RESERVED_BITS31_17_BMSK                                     0xffff0000
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_PS_HOLD_MASK_RESERVED_BITS31_17_SHFT                                             16
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_PS_HOLD_MASK_FSM_STATE_MASK_BMSK                                             0xffff
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_MD_PS_HOLD_MASK_FSM_STATE_MASK_SHFT                                                  0

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_SAIL_SWAOCSR_SAIL_SWAOCSR
 *--------------------------------------------------------------------------*/

#define SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_SAIL_SWAOCSR_SAIL_SWAOCSR_REG_BASE                                           (SAILSS_DBG_SAILSS_SOC_DBG_BASE      + 0x007fb000)
#define SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_SAIL_SWAOCSR_SAIL_SWAOCSR_REG_BASE_SIZE                                      0x1000
#define SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_SAIL_SWAOCSR_SAIL_SWAOCSR_REG_BASE_USED                                      0xffc
#define SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_SAIL_SWAOCSR_SAIL_SWAOCSR_REG_BASE_OFFS                                      0x007fb000

#define HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWDBGPWRCTRL_ADDR                                            (SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_SAIL_SWAOCSR_SAIL_SWAOCSR_REG_BASE      + 0x0)
#define HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWDBGPWRCTRL_OFFS                                            (SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_SAIL_SWAOCSR_SAIL_SWAOCSR_REG_BASE_OFFS + 0x0)
#define HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWDBGPWRCTRL_RMSK                                            0xffffffff
#define HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWDBGPWRCTRL_IN                    \
                in_dword(HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWDBGPWRCTRL_ADDR)
#define HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWDBGPWRCTRL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWDBGPWRCTRL_ADDR, m)
#define HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWDBGPWRCTRL_OUT(v)            \
                out_dword(HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWDBGPWRCTRL_ADDR,v)
#define HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWDBGPWRCTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWDBGPWRCTRL_ADDR,m,v,HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWDBGPWRCTRL_IN)
#define HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWDBGPWRCTRL_RFU_BMSK                                        0xfffffffe
#define HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWDBGPWRCTRL_RFU_SHFT                                                 1
#define HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWDBGPWRCTRL_SWDBGPWRUPREQ_BMSK                                     0x1
#define HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWDBGPWRCTRL_SWDBGPWRUPREQ_SHFT                                       0

#define HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWCSYSPWRCTRL_ADDR                                           (SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_SAIL_SWAOCSR_SAIL_SWAOCSR_REG_BASE      + 0xe0)
#define HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWCSYSPWRCTRL_OFFS                                           (SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_SAIL_SWAOCSR_SAIL_SWAOCSR_REG_BASE_OFFS + 0xe0)
#define HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWCSYSPWRCTRL_RMSK                                           0xffffffff
#define HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWCSYSPWRCTRL_IN                    \
                in_dword(HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWCSYSPWRCTRL_ADDR)
#define HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWCSYSPWRCTRL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWCSYSPWRCTRL_ADDR, m)
#define HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWCSYSPWRCTRL_OUT(v)            \
                out_dword(HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWCSYSPWRCTRL_ADDR,v)
#define HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWCSYSPWRCTRL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWCSYSPWRCTRL_ADDR,m,v,HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWCSYSPWRCTRL_IN)
#define HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWCSYSPWRCTRL_RFU_BMSK                                       0xfffffffe
#define HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWCSYSPWRCTRL_RFU_SHFT                                                1
#define HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWCSYSPWRCTRL_SWCSYSPWRUPREQ_BMSK                                   0x1
#define HWIO_SAILSS_DBG_SAILSS_DBG_SAIL_SWAO_DEBUG_SAIL_SWAOCSR_CS_SWAOCSR_SWCSYSPWRCTRL_SWCSYSPWRUPREQ_SHFT                                     0

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_TSCSS_SYS_TSCSS_TSC
 *--------------------------------------------------------------------------*/

#define SAILSS_TSCSS_SYS_TSCSS_TSC_REG_BASE                                                      (SAILSS_TSCSS_SYS_TSCSS_BASE      + 0x00000000)
#define SAILSS_TSCSS_SYS_TSCSS_TSC_REG_BASE_SIZE                                                 0x2000
#define SAILSS_TSCSS_SYS_TSCSS_TSC_REG_BASE_USED                                                 0x1004
#define SAILSS_TSCSS_SYS_TSCSS_TSC_REG_BASE_OFFS                                                 0x00000000

#define HWIO_SAILSS_TSCSS_SYS_TSCSS_TSC_CONTROL_CNTCR_ADDR                                       (SAILSS_TSCSS_SYS_TSCSS_TSC_REG_BASE      + 0x0)
#define HWIO_SAILSS_TSCSS_SYS_TSCSS_TSC_CONTROL_CNTCR_OFFS                                       (SAILSS_TSCSS_SYS_TSCSS_TSC_REG_BASE_OFFS + 0x0)
#define HWIO_SAILSS_TSCSS_SYS_TSCSS_TSC_CONTROL_CNTCR_RMSK                                           0x3fff
#define HWIO_SAILSS_TSCSS_SYS_TSCSS_TSC_CONTROL_CNTCR_IN                    \
                in_dword(HWIO_SAILSS_TSCSS_SYS_TSCSS_TSC_CONTROL_CNTCR_ADDR)
#define HWIO_SAILSS_TSCSS_SYS_TSCSS_TSC_CONTROL_CNTCR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_TSCSS_SYS_TSCSS_TSC_CONTROL_CNTCR_ADDR, m)
#define HWIO_SAILSS_TSCSS_SYS_TSCSS_TSC_CONTROL_CNTCR_OUT(v)            \
                out_dword(HWIO_SAILSS_TSCSS_SYS_TSCSS_TSC_CONTROL_CNTCR_ADDR,v)
#define HWIO_SAILSS_TSCSS_SYS_TSCSS_TSC_CONTROL_CNTCR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_TSCSS_SYS_TSCSS_TSC_CONTROL_CNTCR_ADDR,m,v,HWIO_SAILSS_TSCSS_SYS_TSCSS_TSC_CONTROL_CNTCR_IN)
#define HWIO_SAILSS_TSCSS_SYS_TSCSS_TSC_CONTROL_CNTCR_SLEEP_MODE_INCR_SEL_BMSK                       0x2000
#define HWIO_SAILSS_TSCSS_SYS_TSCSS_TSC_CONTROL_CNTCR_SLEEP_MODE_INCR_SEL_SHFT                           13
#define HWIO_SAILSS_TSCSS_SYS_TSCSS_TSC_CONTROL_CNTCR_STEP_INCR_BMSK                                 0x1000
#define HWIO_SAILSS_TSCSS_SYS_TSCSS_TSC_CONTROL_CNTCR_STEP_INCR_SHFT                                     12
#define HWIO_SAILSS_TSCSS_SYS_TSCSS_TSC_CONTROL_CNTCR_INCR_BMSK                                       0xf00
#define HWIO_SAILSS_TSCSS_SYS_TSCSS_TSC_CONTROL_CNTCR_INCR_SHFT                                           8
#define HWIO_SAILSS_TSCSS_SYS_TSCSS_TSC_CONTROL_CNTCR_VALID_PULSE_WIDTH_BMSK                           0xc0
#define HWIO_SAILSS_TSCSS_SYS_TSCSS_TSC_CONTROL_CNTCR_VALID_PULSE_WIDTH_SHFT                              6
#define HWIO_SAILSS_TSCSS_SYS_TSCSS_TSC_CONTROL_CNTCR_SPARE_BMSK                                       0x3c
#define HWIO_SAILSS_TSCSS_SYS_TSCSS_TSC_CONTROL_CNTCR_SPARE_SHFT                                          2
#define HWIO_SAILSS_TSCSS_SYS_TSCSS_TSC_CONTROL_CNTCR_HALT_DBG_BMSK                                     0x2
#define HWIO_SAILSS_TSCSS_SYS_TSCSS_TSC_CONTROL_CNTCR_HALT_DBG_SHFT                                       1
#define HWIO_SAILSS_TSCSS_SYS_TSCSS_TSC_CONTROL_CNTCR_EN_BMSK                                           0x1
#define HWIO_SAILSS_TSCSS_SYS_TSCSS_TSC_CONTROL_CNTCR_EN_SHFT                                             0


#endif /* __SAILDBG_HWIO_H__ */
