#ifndef __SAIL_PWR_CNTRL_HWIO_H__
#define __SAIL_PWR_CNTRL_HWIO_H__
/*
===========================================================================
*/
/**
    @file sail_pwr_cntrl_hwio.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        LeMansAU [lemansau_v1.0_p3q1r52]
 
    This file contains HWIO register definitions for the following modules:
        SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER


    Generation parameters: 
    { 'explicit-addressing': True,
      'filename': 'sail_pwr_cntrl_hwio.h',
      'header': '#include "msmhwiobase.h"',
      'ignore-prefixes': True,
      'modules': ['SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER'],
      'output-fvals': True,
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/pwr_controller/inc/8650/sail_pwr_cntrl_hwio.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "msmhwiobase.h"

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER
 *--------------------------------------------------------------------------*/

#define SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE                                                      (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_BASE      + 0x00000000)
#define SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_SIZE                                                 0x10000
#define SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_USED                                                 0x53fc
#define SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_PHYS                                                 (SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_BASE_PHYS + 0x00000000)
#define SAILSS_PWR_CTRL_SAILSS_POWER_CONTROLLER_REG_BASE_OFFS                                                 0x00000000

#define HWIO_ISD_CONTROL_ADDR(x)                                                                              ((x) + 0x0)
#define HWIO_ISD_CONTROL_PHYS(x)                                                                              ((x) + 0x0)
#define HWIO_ISD_CONTROL_OFFS                                                                                 (0x0)
#define HWIO_ISD_CONTROL_RMSK                                                                                        0x7
#define HWIO_ISD_CONTROL_IN(x)            \
                in_dword(HWIO_ISD_CONTROL_ADDR(x))
#define HWIO_ISD_CONTROL_INM(x, m)            \
                in_dword_masked(HWIO_ISD_CONTROL_ADDR(x), m)
#define HWIO_ISD_CONTROL_OUT(x, v)            \
                out_dword(HWIO_ISD_CONTROL_ADDR(x),v)
#define HWIO_ISD_CONTROL_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_ISD_CONTROL_ADDR(x),m,v,HWIO_ISD_CONTROL_IN(x))
#define HWIO_ISD_CONTROL_SAIL_FROM_MD_ISO_EN_SW_OVRD_EN_BMSK                                                         0x4
#define HWIO_ISD_CONTROL_SAIL_FROM_MD_ISO_EN_SW_OVRD_EN_SHFT                                                           2
#define HWIO_ISD_CONTROL_ISD_MOVE_TO_ISLAND_STATE_BMSK                                                               0x2
#define HWIO_ISD_CONTROL_ISD_MOVE_TO_ISLAND_STATE_SHFT                                                                 1
#define HWIO_ISD_CONTROL_ISD_MOVE_TO_NORMAL_STATE_BMSK                                                               0x1
#define HWIO_ISD_CONTROL_ISD_MOVE_TO_NORMAL_STATE_SHFT                                                                 0

#define HWIO_ISD_ISO_CTRL_ADDR(x)                                                                             ((x) + 0x4)
#define HWIO_ISD_ISO_CTRL_PHYS(x)                                                                             ((x) + 0x4)
#define HWIO_ISD_ISO_CTRL_OFFS                                                                                (0x4)
#define HWIO_ISD_ISO_CTRL_RMSK                                                                                      0xff
#define HWIO_ISD_ISO_CTRL_IN(x)            \
                in_dword(HWIO_ISD_ISO_CTRL_ADDR(x))
#define HWIO_ISD_ISO_CTRL_INM(x, m)            \
                in_dword_masked(HWIO_ISD_ISO_CTRL_ADDR(x), m)
#define HWIO_ISD_ISO_CTRL_OUT(x, v)            \
                out_dword(HWIO_ISD_ISO_CTRL_ADDR(x),v)
#define HWIO_ISD_ISO_CTRL_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_ISD_ISO_CTRL_ADDR(x),m,v,HWIO_ISD_ISO_CTRL_IN(x))
#define HWIO_ISD_ISO_CTRL_SAIL_FROM_MD_MXA_ISO_EN_DEBUG_BMSK                                                        0x80
#define HWIO_ISD_ISO_CTRL_SAIL_FROM_MD_MXA_ISO_EN_DEBUG_SHFT                                                           7
#define HWIO_ISD_ISO_CTRL_SAIL_FROM_MD_MXA_ISO_EN_DFT_BMSK                                                          0x40
#define HWIO_ISD_ISO_CTRL_SAIL_FROM_MD_MXA_ISO_EN_DFT_SHFT                                                             6
#define HWIO_ISD_ISO_CTRL_SAIL_FROM_MD_MXA_ISO_EN_CLK_BMSK                                                          0x20
#define HWIO_ISD_ISO_CTRL_SAIL_FROM_MD_MXA_ISO_EN_CLK_SHFT                                                             5
#define HWIO_ISD_ISO_CTRL_SAIL_FROM_MD_MXA_ISO_EN_BMSK                                                              0x10
#define HWIO_ISD_ISO_CTRL_SAIL_FROM_MD_MXA_ISO_EN_SHFT                                                                 4
#define HWIO_ISD_ISO_CTRL_SAIL_FROM_MD_CX_ISO_EN_DEBUG_BMSK                                                          0x8
#define HWIO_ISD_ISO_CTRL_SAIL_FROM_MD_CX_ISO_EN_DEBUG_SHFT                                                            3
#define HWIO_ISD_ISO_CTRL_SAIL_FROM_MD_CX_ISO_EN_DFT_BMSK                                                            0x4
#define HWIO_ISD_ISO_CTRL_SAIL_FROM_MD_CX_ISO_EN_DFT_SHFT                                                              2
#define HWIO_ISD_ISO_CTRL_SAIL_FROM_MD_CX_ISO_EN_CLK_BMSK                                                            0x2
#define HWIO_ISD_ISO_CTRL_SAIL_FROM_MD_CX_ISO_EN_CLK_SHFT                                                              1
#define HWIO_ISD_ISO_CTRL_SAIL_FROM_MD_CX_ISO_EN_BMSK                                                                0x1
#define HWIO_ISD_ISO_CTRL_SAIL_FROM_MD_CX_ISO_EN_SHFT                                                                  0

#define HWIO_ISD_STATUS_ADDR(x)                                                                               ((x) + 0x8)
#define HWIO_ISD_STATUS_PHYS(x)                                                                               ((x) + 0x8)
#define HWIO_ISD_STATUS_OFFS                                                                                  (0x8)
#define HWIO_ISD_STATUS_RMSK                                                                                  0x3fffffff
#define HWIO_ISD_STATUS_IN(x)            \
                in_dword(HWIO_ISD_STATUS_ADDR(x))
#define HWIO_ISD_STATUS_INM(x, m)            \
                in_dword_masked(HWIO_ISD_STATUS_ADDR(x), m)
#define HWIO_ISD_STATUS_AGGR_FATAL_ERR_PS_HOLD_BMSK                                                           0x20000000
#define HWIO_ISD_STATUS_AGGR_FATAL_ERR_PS_HOLD_SHFT                                                                   29
#define HWIO_ISD_STATUS_AGGR_FATAL_ERR_ISO_EN_BMSK                                                            0x10000000
#define HWIO_ISD_STATUS_AGGR_FATAL_ERR_ISO_EN_SHFT                                                                    28
#define HWIO_ISD_STATUS_DEGLITCH_MUX_SEL_BMSK                                                                  0xc000000
#define HWIO_ISD_STATUS_DEGLITCH_MUX_SEL_SHFT                                                                         26
#define HWIO_ISD_STATUS_DEGLITCH_COUNTER_RESET_BMSK                                                            0x2000000
#define HWIO_ISD_STATUS_DEGLITCH_COUNTER_RESET_SHFT                                                                   25
#define HWIO_ISD_STATUS_DEGLITCH_COUNTER_HALT_BMSK                                                             0x1000000
#define HWIO_ISD_STATUS_DEGLITCH_COUNTER_HALT_SHFT                                                                    24
#define HWIO_ISD_STATUS_DEGLITCH_COUNT_ZEROS_BMSK                                                               0xffc000
#define HWIO_ISD_STATUS_DEGLITCH_COUNT_ZEROS_SHFT                                                                     14
#define HWIO_ISD_STATUS_DEGLITCH_COUNT_ONES_BMSK                                                                  0x3ff0
#define HWIO_ISD_STATUS_DEGLITCH_COUNT_ONES_SHFT                                                                       4
#define HWIO_ISD_STATUS_ISD_ISLAND_STATE_BMSK                                                                        0x8
#define HWIO_ISD_STATUS_ISD_ISLAND_STATE_SHFT                                                                          3
#define HWIO_ISD_STATUS_ISD_FSM_STATE_BMSK                                                                           0x6
#define HWIO_ISD_STATUS_ISD_FSM_STATE_SHFT                                                                             1
#define HWIO_ISD_STATUS_SAIL_FROM_MD_CX_ISO_EN_SEQ_BMSK                                                              0x1
#define HWIO_ISD_STATUS_SAIL_FROM_MD_CX_ISO_EN_SEQ_SHFT                                                                0

#define HWIO_PS_HOLD_ADDR(x)                                                                                  ((x) + 0xc)
#define HWIO_PS_HOLD_PHYS(x)                                                                                  ((x) + 0xc)
#define HWIO_PS_HOLD_OFFS                                                                                     (0xc)
#define HWIO_PS_HOLD_RMSK                                                                                            0x3
#define HWIO_PS_HOLD_IN(x)            \
                in_dword(HWIO_PS_HOLD_ADDR(x))
#define HWIO_PS_HOLD_INM(x, m)            \
                in_dword_masked(HWIO_PS_HOLD_ADDR(x), m)
#define HWIO_PS_HOLD_OUT(x, v)            \
                out_dword(HWIO_PS_HOLD_ADDR(x),v)
#define HWIO_PS_HOLD_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_PS_HOLD_ADDR(x),m,v,HWIO_PS_HOLD_IN(x))
#define HWIO_PS_HOLD_SAIL_TO_MD_PS_HOLD_BMSK                                                                         0x2
#define HWIO_PS_HOLD_SAIL_TO_MD_PS_HOLD_SHFT                                                                           1
#define HWIO_PS_HOLD_SAIL_PS_HOLD_BMSK                                                                               0x1
#define HWIO_PS_HOLD_SAIL_PS_HOLD_SHFT                                                                                 0

#define HWIO_SAIL_FATAL_ERR_ISO_EN_MASK_ADDR(x)                                                               ((x) + 0x10)
#define HWIO_SAIL_FATAL_ERR_ISO_EN_MASK_PHYS(x)                                                               ((x) + 0x10)
#define HWIO_SAIL_FATAL_ERR_ISO_EN_MASK_OFFS                                                                  (0x10)
#define HWIO_SAIL_FATAL_ERR_ISO_EN_MASK_RMSK                                                                  0xffffffff
#define HWIO_SAIL_FATAL_ERR_ISO_EN_MASK_IN(x)            \
                in_dword(HWIO_SAIL_FATAL_ERR_ISO_EN_MASK_ADDR(x))
#define HWIO_SAIL_FATAL_ERR_ISO_EN_MASK_INM(x, m)            \
                in_dword_masked(HWIO_SAIL_FATAL_ERR_ISO_EN_MASK_ADDR(x), m)
#define HWIO_SAIL_FATAL_ERR_ISO_EN_MASK_OUT(x, v)            \
                out_dword(HWIO_SAIL_FATAL_ERR_ISO_EN_MASK_ADDR(x),v)
#define HWIO_SAIL_FATAL_ERR_ISO_EN_MASK_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_SAIL_FATAL_ERR_ISO_EN_MASK_ADDR(x),m,v,HWIO_SAIL_FATAL_ERR_ISO_EN_MASK_IN(x))
#define HWIO_SAIL_FATAL_ERR_ISO_EN_MASK_SAIL_FATAL_ERR_ISO_EN_MASK_BMSK                                       0xffffffff
#define HWIO_SAIL_FATAL_ERR_ISO_EN_MASK_SAIL_FATAL_ERR_ISO_EN_MASK_SHFT                                                0

#define HWIO_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_ADDR(x)                                                           ((x) + 0x14)
#define HWIO_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_PHYS(x)                                                           ((x) + 0x14)
#define HWIO_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_OFFS                                                              (0x14)
#define HWIO_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_RMSK                                                              0xffffffff
#define HWIO_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_IN(x)            \
                in_dword(HWIO_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_ADDR(x))
#define HWIO_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_INM(x, m)            \
                in_dword_masked(HWIO_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_ADDR(x), m)
#define HWIO_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_OUT(x, v)            \
                out_dword(HWIO_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_ADDR(x),v)
#define HWIO_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_ADDR(x),m,v,HWIO_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_IN(x))
#define HWIO_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_BMSK                               0xffffffff
#define HWIO_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_SAIL_FATAL_ERR_PS_HOLD_EN_MASK_SHFT                                        0

#define HWIO_ISD_DEGLITCH_MAX_COUNT_VAL_ADDR(x)                                                               ((x) + 0x18)
#define HWIO_ISD_DEGLITCH_MAX_COUNT_VAL_PHYS(x)                                                               ((x) + 0x18)
#define HWIO_ISD_DEGLITCH_MAX_COUNT_VAL_OFFS                                                                  (0x18)
#define HWIO_ISD_DEGLITCH_MAX_COUNT_VAL_RMSK                                                                       0x3ff
#define HWIO_ISD_DEGLITCH_MAX_COUNT_VAL_IN(x)            \
                in_dword(HWIO_ISD_DEGLITCH_MAX_COUNT_VAL_ADDR(x))
#define HWIO_ISD_DEGLITCH_MAX_COUNT_VAL_INM(x, m)            \
                in_dword_masked(HWIO_ISD_DEGLITCH_MAX_COUNT_VAL_ADDR(x), m)
#define HWIO_ISD_DEGLITCH_MAX_COUNT_VAL_OUT(x, v)            \
                out_dword(HWIO_ISD_DEGLITCH_MAX_COUNT_VAL_ADDR(x),v)
#define HWIO_ISD_DEGLITCH_MAX_COUNT_VAL_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_ISD_DEGLITCH_MAX_COUNT_VAL_ADDR(x),m,v,HWIO_ISD_DEGLITCH_MAX_COUNT_VAL_IN(x))
#define HWIO_ISD_DEGLITCH_MAX_COUNT_VAL_ISD_DEGLITCH_MAX_COUNT_VAL_BMSK                                            0x3ff
#define HWIO_ISD_DEGLITCH_MAX_COUNT_VAL_ISD_DEGLITCH_MAX_COUNT_VAL_SHFT                                                0

#define HWIO_ISD_DEBUG_BUS_CX_EN_ADDR(x)                                                                      ((x) + 0x1c)
#define HWIO_ISD_DEBUG_BUS_CX_EN_PHYS(x)                                                                      ((x) + 0x1c)
#define HWIO_ISD_DEBUG_BUS_CX_EN_OFFS                                                                         (0x1c)
#define HWIO_ISD_DEBUG_BUS_CX_EN_RMSK                                                                                0xf
#define HWIO_ISD_DEBUG_BUS_CX_EN_IN(x)            \
                in_dword(HWIO_ISD_DEBUG_BUS_CX_EN_ADDR(x))
#define HWIO_ISD_DEBUG_BUS_CX_EN_INM(x, m)            \
                in_dword_masked(HWIO_ISD_DEBUG_BUS_CX_EN_ADDR(x), m)
#define HWIO_ISD_DEBUG_BUS_CX_EN_OUT(x, v)            \
                out_dword(HWIO_ISD_DEBUG_BUS_CX_EN_ADDR(x),v)
#define HWIO_ISD_DEBUG_BUS_CX_EN_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_ISD_DEBUG_BUS_CX_EN_ADDR(x),m,v,HWIO_ISD_DEBUG_BUS_CX_EN_IN(x))
#define HWIO_ISD_DEBUG_BUS_CX_EN_ISD_DEBUG_BUS_CX_EN_4_BMSK                                                          0x8
#define HWIO_ISD_DEBUG_BUS_CX_EN_ISD_DEBUG_BUS_CX_EN_4_SHFT                                                            3
#define HWIO_ISD_DEBUG_BUS_CX_EN_ISD_DEBUG_BUS_CX_EN_3_BMSK                                                          0x4
#define HWIO_ISD_DEBUG_BUS_CX_EN_ISD_DEBUG_BUS_CX_EN_3_SHFT                                                            2
#define HWIO_ISD_DEBUG_BUS_CX_EN_ISD_DEBUG_BUS_CX_EN_2_BMSK                                                          0x2
#define HWIO_ISD_DEBUG_BUS_CX_EN_ISD_DEBUG_BUS_CX_EN_2_SHFT                                                            1
#define HWIO_ISD_DEBUG_BUS_CX_EN_ISD_DEBUG_BUS_CX_EN_1_BMSK                                                          0x1
#define HWIO_ISD_DEBUG_BUS_CX_EN_ISD_DEBUG_BUS_CX_EN_1_SHFT                                                            0

#define HWIO_ISD_DEBUG_BUS_MX_EN_ADDR(x)                                                                      ((x) + 0x20)
#define HWIO_ISD_DEBUG_BUS_MX_EN_PHYS(x)                                                                      ((x) + 0x20)
#define HWIO_ISD_DEBUG_BUS_MX_EN_OFFS                                                                         (0x20)
#define HWIO_ISD_DEBUG_BUS_MX_EN_RMSK                                                                               0x3f
#define HWIO_ISD_DEBUG_BUS_MX_EN_IN(x)            \
                in_dword(HWIO_ISD_DEBUG_BUS_MX_EN_ADDR(x))
#define HWIO_ISD_DEBUG_BUS_MX_EN_INM(x, m)            \
                in_dword_masked(HWIO_ISD_DEBUG_BUS_MX_EN_ADDR(x), m)
#define HWIO_ISD_DEBUG_BUS_MX_EN_OUT(x, v)            \
                out_dword(HWIO_ISD_DEBUG_BUS_MX_EN_ADDR(x),v)
#define HWIO_ISD_DEBUG_BUS_MX_EN_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_ISD_DEBUG_BUS_MX_EN_ADDR(x),m,v,HWIO_ISD_DEBUG_BUS_MX_EN_IN(x))
#define HWIO_ISD_DEBUG_BUS_MX_EN_ISD_DEBUG_BUS_MX_EN_6_BMSK                                                         0x20
#define HWIO_ISD_DEBUG_BUS_MX_EN_ISD_DEBUG_BUS_MX_EN_6_SHFT                                                            5
#define HWIO_ISD_DEBUG_BUS_MX_EN_ISD_DEBUG_BUS_MX_EN_5_BMSK                                                         0x10
#define HWIO_ISD_DEBUG_BUS_MX_EN_ISD_DEBUG_BUS_MX_EN_5_SHFT                                                            4
#define HWIO_ISD_DEBUG_BUS_MX_EN_ISD_DEBUG_BUS_MX_EN_4_BMSK                                                          0x8
#define HWIO_ISD_DEBUG_BUS_MX_EN_ISD_DEBUG_BUS_MX_EN_4_SHFT                                                            3
#define HWIO_ISD_DEBUG_BUS_MX_EN_ISD_DEBUG_BUS_MX_EN_3_BMSK                                                          0x4
#define HWIO_ISD_DEBUG_BUS_MX_EN_ISD_DEBUG_BUS_MX_EN_3_SHFT                                                            2
#define HWIO_ISD_DEBUG_BUS_MX_EN_ISD_DEBUG_BUS_MX_EN_2_BMSK                                                          0x2
#define HWIO_ISD_DEBUG_BUS_MX_EN_ISD_DEBUG_BUS_MX_EN_2_SHFT                                                            1
#define HWIO_ISD_DEBUG_BUS_MX_EN_ISD_DEBUG_BUS_MX_EN_1_BMSK                                                          0x1
#define HWIO_ISD_DEBUG_BUS_MX_EN_ISD_DEBUG_BUS_MX_EN_1_SHFT                                                            0

#define HWIO_ISD_HW_EVENTS_MX_EN_ADDR(x)                                                                      ((x) + 0x24)
#define HWIO_ISD_HW_EVENTS_MX_EN_PHYS(x)                                                                      ((x) + 0x24)
#define HWIO_ISD_HW_EVENTS_MX_EN_OFFS                                                                         (0x24)
#define HWIO_ISD_HW_EVENTS_MX_EN_RMSK                                                                                0x7
#define HWIO_ISD_HW_EVENTS_MX_EN_IN(x)            \
                in_dword(HWIO_ISD_HW_EVENTS_MX_EN_ADDR(x))
#define HWIO_ISD_HW_EVENTS_MX_EN_INM(x, m)            \
                in_dword_masked(HWIO_ISD_HW_EVENTS_MX_EN_ADDR(x), m)
#define HWIO_ISD_HW_EVENTS_MX_EN_OUT(x, v)            \
                out_dword(HWIO_ISD_HW_EVENTS_MX_EN_ADDR(x),v)
#define HWIO_ISD_HW_EVENTS_MX_EN_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_ISD_HW_EVENTS_MX_EN_ADDR(x),m,v,HWIO_ISD_HW_EVENTS_MX_EN_IN(x))
#define HWIO_ISD_HW_EVENTS_MX_EN_ISD_HW_EVENTS_MX_EN_3_BMSK                                                          0x4
#define HWIO_ISD_HW_EVENTS_MX_EN_ISD_HW_EVENTS_MX_EN_3_SHFT                                                            2
#define HWIO_ISD_HW_EVENTS_MX_EN_ISD_HW_EVENTS_MX_EN_2_BMSK                                                          0x2
#define HWIO_ISD_HW_EVENTS_MX_EN_ISD_HW_EVENTS_MX_EN_2_SHFT                                                            1
#define HWIO_ISD_HW_EVENTS_MX_EN_ISD_HW_EVENTS_MX_EN_1_BMSK                                                          0x1
#define HWIO_ISD_HW_EVENTS_MX_EN_ISD_HW_EVENTS_MX_EN_1_SHFT                                                            0

#define HWIO_ISD_ISO_STATUS_ADDR(x)                                                                           ((x) + 0x28)
#define HWIO_ISD_ISO_STATUS_PHYS(x)                                                                           ((x) + 0x28)
#define HWIO_ISD_ISO_STATUS_OFFS                                                                              (0x28)
#define HWIO_ISD_ISO_STATUS_RMSK                                                                                    0xff
#define HWIO_ISD_ISO_STATUS_IN(x)            \
                in_dword(HWIO_ISD_ISO_STATUS_ADDR(x))
#define HWIO_ISD_ISO_STATUS_INM(x, m)            \
                in_dword_masked(HWIO_ISD_ISO_STATUS_ADDR(x), m)
#define HWIO_ISD_ISO_STATUS_SAIL_FROM_MD_MXA_ISO_EN_DEBUG_BMSK                                                      0x80
#define HWIO_ISD_ISO_STATUS_SAIL_FROM_MD_MXA_ISO_EN_DEBUG_SHFT                                                         7
#define HWIO_ISD_ISO_STATUS_SAIL_FROM_MD_MXA_ISO_EN_DFT_BMSK                                                        0x40
#define HWIO_ISD_ISO_STATUS_SAIL_FROM_MD_MXA_ISO_EN_DFT_SHFT                                                           6
#define HWIO_ISD_ISO_STATUS_SAIL_FROM_MD_MXA_ISO_EN_CLK_BMSK                                                        0x20
#define HWIO_ISD_ISO_STATUS_SAIL_FROM_MD_MXA_ISO_EN_CLK_SHFT                                                           5
#define HWIO_ISD_ISO_STATUS_SAIL_FROM_MD_MXA_ISO_EN_BMSK                                                            0x10
#define HWIO_ISD_ISO_STATUS_SAIL_FROM_MD_MXA_ISO_EN_SHFT                                                               4
#define HWIO_ISD_ISO_STATUS_SAIL_FROM_MD_CX_ISO_EN_DEBUG_BMSK                                                        0x8
#define HWIO_ISD_ISO_STATUS_SAIL_FROM_MD_CX_ISO_EN_DEBUG_SHFT                                                          3
#define HWIO_ISD_ISO_STATUS_SAIL_FROM_MD_CX_ISO_EN_DFT_BMSK                                                          0x4
#define HWIO_ISD_ISO_STATUS_SAIL_FROM_MD_CX_ISO_EN_DFT_SHFT                                                            2
#define HWIO_ISD_ISO_STATUS_SAIL_FROM_MD_CX_ISO_EN_CLK_BMSK                                                          0x2
#define HWIO_ISD_ISO_STATUS_SAIL_FROM_MD_CX_ISO_EN_CLK_SHFT                                                            1
#define HWIO_ISD_ISO_STATUS_SAIL_FROM_MD_CX_ISO_EN_BMSK                                                              0x1
#define HWIO_ISD_ISO_STATUS_SAIL_FROM_MD_CX_ISO_EN_SHFT                                                                0

#define HWIO_SAIL_FATAL_ERRS_4_ISO_EN_STATUS_ADDR(x)                                                          ((x) + 0x2c)
#define HWIO_SAIL_FATAL_ERRS_4_ISO_EN_STATUS_PHYS(x)                                                          ((x) + 0x2c)
#define HWIO_SAIL_FATAL_ERRS_4_ISO_EN_STATUS_OFFS                                                             (0x2c)
#define HWIO_SAIL_FATAL_ERRS_4_ISO_EN_STATUS_RMSK                                                             0xffffffff
#define HWIO_SAIL_FATAL_ERRS_4_ISO_EN_STATUS_IN(x)            \
                in_dword(HWIO_SAIL_FATAL_ERRS_4_ISO_EN_STATUS_ADDR(x))
#define HWIO_SAIL_FATAL_ERRS_4_ISO_EN_STATUS_INM(x, m)            \
                in_dword_masked(HWIO_SAIL_FATAL_ERRS_4_ISO_EN_STATUS_ADDR(x), m)
#define HWIO_SAIL_FATAL_ERRS_4_ISO_EN_STATUS_SAIL_FATAL_ERRS_4_ISO_EN_STATUS_BMSK                             0xffffffff
#define HWIO_SAIL_FATAL_ERRS_4_ISO_EN_STATUS_SAIL_FATAL_ERRS_4_ISO_EN_STATUS_SHFT                                      0

#define HWIO_SAIL_FATAL_ERRS_4_PS_HOLD_STATUS_ADDR(x)                                                         ((x) + 0x30)
#define HWIO_SAIL_FATAL_ERRS_4_PS_HOLD_STATUS_PHYS(x)                                                         ((x) + 0x30)
#define HWIO_SAIL_FATAL_ERRS_4_PS_HOLD_STATUS_OFFS                                                            (0x30)
#define HWIO_SAIL_FATAL_ERRS_4_PS_HOLD_STATUS_RMSK                                                            0xffffffff
#define HWIO_SAIL_FATAL_ERRS_4_PS_HOLD_STATUS_IN(x)            \
                in_dword(HWIO_SAIL_FATAL_ERRS_4_PS_HOLD_STATUS_ADDR(x))
#define HWIO_SAIL_FATAL_ERRS_4_PS_HOLD_STATUS_INM(x, m)            \
                in_dword_masked(HWIO_SAIL_FATAL_ERRS_4_PS_HOLD_STATUS_ADDR(x), m)
#define HWIO_SAIL_FATAL_ERRS_4_PS_HOLD_STATUS_SAIL_FATAL_ERRS_4_PS_HOLD_STATUS_BMSK                           0xffffffff
#define HWIO_SAIL_FATAL_ERRS_4_PS_HOLD_STATUS_SAIL_FATAL_ERRS_4_PS_HOLD_STATUS_SHFT                                    0

#define HWIO_ISD_SPARE_REG_0_ADDR(x)                                                                          ((x) + 0x34)
#define HWIO_ISD_SPARE_REG_0_PHYS(x)                                                                          ((x) + 0x34)
#define HWIO_ISD_SPARE_REG_0_OFFS                                                                             (0x34)
#define HWIO_ISD_SPARE_REG_0_RMSK                                                                             0xffffffff
#define HWIO_ISD_SPARE_REG_0_IN(x)            \
                in_dword(HWIO_ISD_SPARE_REG_0_ADDR(x))
#define HWIO_ISD_SPARE_REG_0_INM(x, m)            \
                in_dword_masked(HWIO_ISD_SPARE_REG_0_ADDR(x), m)
#define HWIO_ISD_SPARE_REG_0_OUT(x, v)            \
                out_dword(HWIO_ISD_SPARE_REG_0_ADDR(x),v)
#define HWIO_ISD_SPARE_REG_0_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_ISD_SPARE_REG_0_ADDR(x),m,v,HWIO_ISD_SPARE_REG_0_IN(x))
#define HWIO_ISD_SPARE_REG_0_ISD_SPARE_REG_0_BMSK                                                             0xffffffff
#define HWIO_ISD_SPARE_REG_0_ISD_SPARE_REG_0_SHFT                                                                      0

#define HWIO_ISD_SPARE_REG_1_ADDR(x)                                                                          ((x) + 0x38)
#define HWIO_ISD_SPARE_REG_1_PHYS(x)                                                                          ((x) + 0x38)
#define HWIO_ISD_SPARE_REG_1_OFFS                                                                             (0x38)
#define HWIO_ISD_SPARE_REG_1_RMSK                                                                             0xffffffff
#define HWIO_ISD_SPARE_REG_1_IN(x)            \
                in_dword(HWIO_ISD_SPARE_REG_1_ADDR(x))
#define HWIO_ISD_SPARE_REG_1_INM(x, m)            \
                in_dword_masked(HWIO_ISD_SPARE_REG_1_ADDR(x), m)
#define HWIO_ISD_SPARE_REG_1_OUT(x, v)            \
                out_dword(HWIO_ISD_SPARE_REG_1_ADDR(x),v)
#define HWIO_ISD_SPARE_REG_1_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_ISD_SPARE_REG_1_ADDR(x),m,v,HWIO_ISD_SPARE_REG_1_IN(x))
#define HWIO_ISD_SPARE_REG_1_ISD_SPARE_REG_1_BMSK                                                             0xffffffff
#define HWIO_ISD_SPARE_REG_1_ISD_SPARE_REG_1_SHFT                                                                      0

#define HWIO_PWR_SEQ_WDOG_CTRL_ADDR(x)                                                                        ((x) + 0x400)
#define HWIO_PWR_SEQ_WDOG_CTRL_PHYS(x)                                                                        ((x) + 0x400)
#define HWIO_PWR_SEQ_WDOG_CTRL_OFFS                                                                           (0x400)
#define HWIO_PWR_SEQ_WDOG_CTRL_RMSK                                                                                  0xf
#define HWIO_PWR_SEQ_WDOG_CTRL_IN(x)            \
                in_dword(HWIO_PWR_SEQ_WDOG_CTRL_ADDR(x))
#define HWIO_PWR_SEQ_WDOG_CTRL_INM(x, m)            \
                in_dword_masked(HWIO_PWR_SEQ_WDOG_CTRL_ADDR(x), m)
#define HWIO_PWR_SEQ_WDOG_CTRL_OUT(x, v)            \
                out_dword(HWIO_PWR_SEQ_WDOG_CTRL_ADDR(x),v)
#define HWIO_PWR_SEQ_WDOG_CTRL_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_PWR_SEQ_WDOG_CTRL_ADDR(x),m,v,HWIO_PWR_SEQ_WDOG_CTRL_IN(x))
#define HWIO_PWR_SEQ_WDOG_CTRL_WDOG_TIMER_CLK_ON_BMSK                                                                0x8
#define HWIO_PWR_SEQ_WDOG_CTRL_WDOG_TIMER_CLK_ON_SHFT                                                                  3
#define HWIO_PWR_SEQ_WDOG_CTRL_WDOG_BARK_RESET_BMSK                                                                  0x4
#define HWIO_PWR_SEQ_WDOG_CTRL_WDOG_BARK_RESET_SHFT                                                                    2
#define HWIO_PWR_SEQ_WDOG_CTRL_WDOG_BITE_RESET_BMSK                                                                  0x2
#define HWIO_PWR_SEQ_WDOG_CTRL_WDOG_BITE_RESET_SHFT                                                                    1
#define HWIO_PWR_SEQ_WDOG_CTRL_FREEZE_THE_WDOG_BMSK                                                                  0x1
#define HWIO_PWR_SEQ_WDOG_CTRL_FREEZE_THE_WDOG_SHFT                                                                    0

#define HWIO_PWR_SEQ_WDOG_CTRL_EN_WDOG_ADDR(x)                                                                ((x) + 0x404)
#define HWIO_PWR_SEQ_WDOG_CTRL_EN_WDOG_PHYS(x)                                                                ((x) + 0x404)
#define HWIO_PWR_SEQ_WDOG_CTRL_EN_WDOG_OFFS                                                                   (0x404)
#define HWIO_PWR_SEQ_WDOG_CTRL_EN_WDOG_RMSK                                                                          0x1
#define HWIO_PWR_SEQ_WDOG_CTRL_EN_WDOG_IN(x)            \
                in_dword(HWIO_PWR_SEQ_WDOG_CTRL_EN_WDOG_ADDR(x))
#define HWIO_PWR_SEQ_WDOG_CTRL_EN_WDOG_INM(x, m)            \
                in_dword_masked(HWIO_PWR_SEQ_WDOG_CTRL_EN_WDOG_ADDR(x), m)
#define HWIO_PWR_SEQ_WDOG_CTRL_EN_WDOG_OUT(x, v)            \
                out_dword(HWIO_PWR_SEQ_WDOG_CTRL_EN_WDOG_ADDR(x),v)
#define HWIO_PWR_SEQ_WDOG_CTRL_EN_WDOG_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_PWR_SEQ_WDOG_CTRL_EN_WDOG_ADDR(x),m,v,HWIO_PWR_SEQ_WDOG_CTRL_EN_WDOG_IN(x))
#define HWIO_PWR_SEQ_WDOG_CTRL_EN_WDOG_ENABLE_THE_WDOG_BMSK                                                          0x1
#define HWIO_PWR_SEQ_WDOG_CTRL_EN_WDOG_ENABLE_THE_WDOG_SHFT                                                            0

#define HWIO_PWR_SEQ_WDOG_STATUS_ADDR(x)                                                                      ((x) + 0x408)
#define HWIO_PWR_SEQ_WDOG_STATUS_PHYS(x)                                                                      ((x) + 0x408)
#define HWIO_PWR_SEQ_WDOG_STATUS_OFFS                                                                         (0x408)
#define HWIO_PWR_SEQ_WDOG_STATUS_RMSK                                                                                0xf
#define HWIO_PWR_SEQ_WDOG_STATUS_IN(x)            \
                in_dword(HWIO_PWR_SEQ_WDOG_STATUS_ADDR(x))
#define HWIO_PWR_SEQ_WDOG_STATUS_INM(x, m)            \
                in_dword_masked(HWIO_PWR_SEQ_WDOG_STATUS_ADDR(x), m)
#define HWIO_PWR_SEQ_WDOG_STATUS_WDOG_CNT_RES_STS_BMSK                                                               0x8
#define HWIO_PWR_SEQ_WDOG_STATUS_WDOG_CNT_RES_STS_SHFT                                                                 3
#define HWIO_PWR_SEQ_WDOG_STATUS_WDOG_RES_SOURCE_BMSK                                                                0x4
#define HWIO_PWR_SEQ_WDOG_STATUS_WDOG_RES_SOURCE_SHFT                                                                  2
#define HWIO_PWR_SEQ_WDOG_STATUS_WDOG_BITE_IRQ_BMSK                                                                  0x2
#define HWIO_PWR_SEQ_WDOG_STATUS_WDOG_BITE_IRQ_SHFT                                                                    1
#define HWIO_PWR_SEQ_WDOG_STATUS_WDOG_BARK_IRQ_BMSK                                                                  0x1
#define HWIO_PWR_SEQ_WDOG_STATUS_WDOG_BARK_IRQ_SHFT                                                                    0

#define HWIO_PWR_SEQ_WDOG_BARK_TIME_ADDR(x)                                                                   ((x) + 0x40c)
#define HWIO_PWR_SEQ_WDOG_BARK_TIME_PHYS(x)                                                                   ((x) + 0x40c)
#define HWIO_PWR_SEQ_WDOG_BARK_TIME_OFFS                                                                      (0x40c)
#define HWIO_PWR_SEQ_WDOG_BARK_TIME_RMSK                                                                         0xfffff
#define HWIO_PWR_SEQ_WDOG_BARK_TIME_IN(x)            \
                in_dword(HWIO_PWR_SEQ_WDOG_BARK_TIME_ADDR(x))
#define HWIO_PWR_SEQ_WDOG_BARK_TIME_INM(x, m)            \
                in_dword_masked(HWIO_PWR_SEQ_WDOG_BARK_TIME_ADDR(x), m)
#define HWIO_PWR_SEQ_WDOG_BARK_TIME_OUT(x, v)            \
                out_dword(HWIO_PWR_SEQ_WDOG_BARK_TIME_ADDR(x),v)
#define HWIO_PWR_SEQ_WDOG_BARK_TIME_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_PWR_SEQ_WDOG_BARK_TIME_ADDR(x),m,v,HWIO_PWR_SEQ_WDOG_BARK_TIME_IN(x))
#define HWIO_PWR_SEQ_WDOG_BARK_TIME_PWR_SEQ_WDOG_BARK_TIME_BMSK                                                  0xfffff
#define HWIO_PWR_SEQ_WDOG_BARK_TIME_PWR_SEQ_WDOG_BARK_TIME_SHFT                                                        0

#define HWIO_PWR_SEQ_WDOG_BITE_TIME_ADDR(x)                                                                   ((x) + 0x410)
#define HWIO_PWR_SEQ_WDOG_BITE_TIME_PHYS(x)                                                                   ((x) + 0x410)
#define HWIO_PWR_SEQ_WDOG_BITE_TIME_OFFS                                                                      (0x410)
#define HWIO_PWR_SEQ_WDOG_BITE_TIME_RMSK                                                                         0xfffff
#define HWIO_PWR_SEQ_WDOG_BITE_TIME_IN(x)            \
                in_dword(HWIO_PWR_SEQ_WDOG_BITE_TIME_ADDR(x))
#define HWIO_PWR_SEQ_WDOG_BITE_TIME_INM(x, m)            \
                in_dword_masked(HWIO_PWR_SEQ_WDOG_BITE_TIME_ADDR(x), m)
#define HWIO_PWR_SEQ_WDOG_BITE_TIME_OUT(x, v)            \
                out_dword(HWIO_PWR_SEQ_WDOG_BITE_TIME_ADDR(x),v)
#define HWIO_PWR_SEQ_WDOG_BITE_TIME_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_PWR_SEQ_WDOG_BITE_TIME_ADDR(x),m,v,HWIO_PWR_SEQ_WDOG_BITE_TIME_IN(x))
#define HWIO_PWR_SEQ_WDOG_BITE_TIME_PWR_SEQ_WDOG_BITE_TIME_BMSK                                                  0xfffff
#define HWIO_PWR_SEQ_WDOG_BITE_TIME_PWR_SEQ_WDOG_BITE_TIME_SHFT                                                        0

#define HWIO_PWR_SEQ_WDOG_TEST_VALUE_ADDR(x)                                                                  ((x) + 0x414)
#define HWIO_PWR_SEQ_WDOG_TEST_VALUE_PHYS(x)                                                                  ((x) + 0x414)
#define HWIO_PWR_SEQ_WDOG_TEST_VALUE_OFFS                                                                     (0x414)
#define HWIO_PWR_SEQ_WDOG_TEST_VALUE_RMSK                                                                        0xfffff
#define HWIO_PWR_SEQ_WDOG_TEST_VALUE_IN(x)            \
                in_dword(HWIO_PWR_SEQ_WDOG_TEST_VALUE_ADDR(x))
#define HWIO_PWR_SEQ_WDOG_TEST_VALUE_INM(x, m)            \
                in_dword_masked(HWIO_PWR_SEQ_WDOG_TEST_VALUE_ADDR(x), m)
#define HWIO_PWR_SEQ_WDOG_TEST_VALUE_OUT(x, v)            \
                out_dword(HWIO_PWR_SEQ_WDOG_TEST_VALUE_ADDR(x),v)
#define HWIO_PWR_SEQ_WDOG_TEST_VALUE_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_PWR_SEQ_WDOG_TEST_VALUE_ADDR(x),m,v,HWIO_PWR_SEQ_WDOG_TEST_VALUE_IN(x))
#define HWIO_PWR_SEQ_WDOG_TEST_VALUE_PWR_SEQ_WDOG_TEST_VALUE_BMSK                                                0xfffff
#define HWIO_PWR_SEQ_WDOG_TEST_VALUE_PWR_SEQ_WDOG_TEST_VALUE_SHFT                                                      0

#define HWIO_PWR_SEQ_WDOG_COUNT_ADDR(x)                                                                       ((x) + 0x418)
#define HWIO_PWR_SEQ_WDOG_COUNT_PHYS(x)                                                                       ((x) + 0x418)
#define HWIO_PWR_SEQ_WDOG_COUNT_OFFS                                                                          (0x418)
#define HWIO_PWR_SEQ_WDOG_COUNT_RMSK                                                                             0xfffff
#define HWIO_PWR_SEQ_WDOG_COUNT_IN(x)            \
                in_dword(HWIO_PWR_SEQ_WDOG_COUNT_ADDR(x))
#define HWIO_PWR_SEQ_WDOG_COUNT_INM(x, m)            \
                in_dword_masked(HWIO_PWR_SEQ_WDOG_COUNT_ADDR(x), m)
#define HWIO_PWR_SEQ_WDOG_COUNT_PWR_SEQ_WDOG_COUNT_BMSK                                                          0xfffff
#define HWIO_PWR_SEQ_WDOG_COUNT_PWR_SEQ_WDOG_COUNT_SHFT                                                                0

#define HWIO_PWR_CTRL_CONTROL_ADDR(x)                                                                         ((x) + 0x420)
#define HWIO_PWR_CTRL_CONTROL_PHYS(x)                                                                         ((x) + 0x420)
#define HWIO_PWR_CTRL_CONTROL_OFFS                                                                            (0x420)
#define HWIO_PWR_CTRL_CONTROL_RMSK                                                                                  0x3f
#define HWIO_PWR_CTRL_CONTROL_IN(x)            \
                in_dword(HWIO_PWR_CTRL_CONTROL_ADDR(x))
#define HWIO_PWR_CTRL_CONTROL_INM(x, m)            \
                in_dword_masked(HWIO_PWR_CTRL_CONTROL_ADDR(x), m)
#define HWIO_PWR_CTRL_CONTROL_OUT(x, v)            \
                out_dword(HWIO_PWR_CTRL_CONTROL_ADDR(x),v)
#define HWIO_PWR_CTRL_CONTROL_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_PWR_CTRL_CONTROL_ADDR(x),m,v,HWIO_PWR_CTRL_CONTROL_IN(x))
#define HWIO_PWR_CTRL_CONTROL_PWR_CTRL_RSVD_BMSK                                                                    0x3e
#define HWIO_PWR_CTRL_CONTROL_PWR_CTRL_RSVD_SHFT                                                                       1
#define HWIO_PWR_CTRL_CONTROL_SAIL_LOW_PWR_ENTRY_BMSK                                                                0x1
#define HWIO_PWR_CTRL_CONTROL_SAIL_LOW_PWR_ENTRY_SHFT                                                                  0

#define HWIO_PWR_CTRL_STATUS_ADDR(x)                                                                          ((x) + 0x424)
#define HWIO_PWR_CTRL_STATUS_PHYS(x)                                                                          ((x) + 0x424)
#define HWIO_PWR_CTRL_STATUS_OFFS                                                                             (0x424)
#define HWIO_PWR_CTRL_STATUS_RMSK                                                                                    0x7
#define HWIO_PWR_CTRL_STATUS_IN(x)            \
                in_dword(HWIO_PWR_CTRL_STATUS_ADDR(x))
#define HWIO_PWR_CTRL_STATUS_INM(x, m)            \
                in_dword_masked(HWIO_PWR_CTRL_STATUS_ADDR(x), m)
#define HWIO_PWR_CTRL_STATUS_SLEEP_EXIT_BMSK                                                                         0x4
#define HWIO_PWR_CTRL_STATUS_SLEEP_EXIT_SHFT                                                                           2
#define HWIO_PWR_CTRL_STATUS_SLEEP_ENTRY_BMSK                                                                        0x2
#define HWIO_PWR_CTRL_STATUS_SLEEP_ENTRY_SHFT                                                                          1
#define HWIO_PWR_CTRL_STATUS_SAIL_IS_IN_SLEEP_BMSK                                                                   0x1
#define HWIO_PWR_CTRL_STATUS_SAIL_IS_IN_SLEEP_SHFT                                                                     0

#define HWIO_ASILB_NOC_QCH_PROTOCOL_ADDR(x)                                                                   ((x) + 0x428)
#define HWIO_ASILB_NOC_QCH_PROTOCOL_PHYS(x)                                                                   ((x) + 0x428)
#define HWIO_ASILB_NOC_QCH_PROTOCOL_OFFS                                                                      (0x428)
#define HWIO_ASILB_NOC_QCH_PROTOCOL_RMSK                                                                             0xf
#define HWIO_ASILB_NOC_QCH_PROTOCOL_IN(x)            \
                in_dword(HWIO_ASILB_NOC_QCH_PROTOCOL_ADDR(x))
#define HWIO_ASILB_NOC_QCH_PROTOCOL_INM(x, m)            \
                in_dword_masked(HWIO_ASILB_NOC_QCH_PROTOCOL_ADDR(x), m)
#define HWIO_ASILB_NOC_QCH_PROTOCOL_QACTIVE_BMSK                                                                     0x8
#define HWIO_ASILB_NOC_QCH_PROTOCOL_QACTIVE_SHFT                                                                       3
#define HWIO_ASILB_NOC_QCH_PROTOCOL_QDENY_BMSK                                                                       0x4
#define HWIO_ASILB_NOC_QCH_PROTOCOL_QDENY_SHFT                                                                         2
#define HWIO_ASILB_NOC_QCH_PROTOCOL_QACCEPTN_BMSK                                                                    0x2
#define HWIO_ASILB_NOC_QCH_PROTOCOL_QACCEPTN_SHFT                                                                      1
#define HWIO_ASILB_NOC_QCH_PROTOCOL_QREQN_BMSK                                                                       0x1
#define HWIO_ASILB_NOC_QCH_PROTOCOL_QREQN_SHFT                                                                         0

#define HWIO_ASILB_NOC_QCH_CTRL_ADDR(x)                                                                       ((x) + 0x42c)
#define HWIO_ASILB_NOC_QCH_CTRL_PHYS(x)                                                                       ((x) + 0x42c)
#define HWIO_ASILB_NOC_QCH_CTRL_OFFS                                                                          (0x42c)
#define HWIO_ASILB_NOC_QCH_CTRL_RMSK                                                                              0x1fff
#define HWIO_ASILB_NOC_QCH_CTRL_IN(x)            \
                in_dword(HWIO_ASILB_NOC_QCH_CTRL_ADDR(x))
#define HWIO_ASILB_NOC_QCH_CTRL_INM(x, m)            \
                in_dword_masked(HWIO_ASILB_NOC_QCH_CTRL_ADDR(x), m)
#define HWIO_ASILB_NOC_QCH_CTRL_OUT(x, v)            \
                out_dword(HWIO_ASILB_NOC_QCH_CTRL_ADDR(x),v)
#define HWIO_ASILB_NOC_QCH_CTRL_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_ASILB_NOC_QCH_CTRL_ADDR(x),m,v,HWIO_ASILB_NOC_QCH_CTRL_IN(x))
#define HWIO_ASILB_NOC_QCH_CTRL_QCH_DENY_TO_REQ_CNT_BMSK                                                          0x1fe0
#define HWIO_ASILB_NOC_QCH_CTRL_QCH_DENY_TO_REQ_CNT_SHFT                                                               5
#define HWIO_ASILB_NOC_QCH_CTRL_QCH_HYST_CNT_BMSK                                                                   0x1f
#define HWIO_ASILB_NOC_QCH_CTRL_QCH_HYST_CNT_SHFT                                                                      0

#define HWIO_ASILB_NOC_QCH_STATUS_ADDR(x)                                                                     ((x) + 0x430)
#define HWIO_ASILB_NOC_QCH_STATUS_PHYS(x)                                                                     ((x) + 0x430)
#define HWIO_ASILB_NOC_QCH_STATUS_OFFS                                                                        (0x430)
#define HWIO_ASILB_NOC_QCH_STATUS_RMSK                                                                              0x7f
#define HWIO_ASILB_NOC_QCH_STATUS_IN(x)            \
                in_dword(HWIO_ASILB_NOC_QCH_STATUS_ADDR(x))
#define HWIO_ASILB_NOC_QCH_STATUS_INM(x, m)            \
                in_dword_masked(HWIO_ASILB_NOC_QCH_STATUS_ADDR(x), m)
#define HWIO_ASILB_NOC_QCH_STATUS_LOW_PWR_RDY_BMSK                                                                  0x40
#define HWIO_ASILB_NOC_QCH_STATUS_LOW_PWR_RDY_SHFT                                                                     6
#define HWIO_ASILB_NOC_QCH_STATUS_QCH_FSM_CUR_STATE_BMSK                                                            0x3c
#define HWIO_ASILB_NOC_QCH_STATUS_QCH_FSM_CUR_STATE_SHFT                                                               2
#define HWIO_ASILB_NOC_QCH_STATUS_QCH_HYST_CNT_EXPIRY_BMSK                                                           0x2
#define HWIO_ASILB_NOC_QCH_STATUS_QCH_HYST_CNT_EXPIRY_SHFT                                                             1
#define HWIO_ASILB_NOC_QCH_STATUS_QCH_DENY_TO_REQ_CNT_EXPIRY_BMSK                                                    0x1
#define HWIO_ASILB_NOC_QCH_STATUS_QCH_DENY_TO_REQ_CNT_EXPIRY_SHFT                                                      0

#define HWIO_ASILD_NOC_QCH_PROTOCOL_ADDR(x)                                                                   ((x) + 0x434)
#define HWIO_ASILD_NOC_QCH_PROTOCOL_PHYS(x)                                                                   ((x) + 0x434)
#define HWIO_ASILD_NOC_QCH_PROTOCOL_OFFS                                                                      (0x434)
#define HWIO_ASILD_NOC_QCH_PROTOCOL_RMSK                                                                             0xf
#define HWIO_ASILD_NOC_QCH_PROTOCOL_IN(x)            \
                in_dword(HWIO_ASILD_NOC_QCH_PROTOCOL_ADDR(x))
#define HWIO_ASILD_NOC_QCH_PROTOCOL_INM(x, m)            \
                in_dword_masked(HWIO_ASILD_NOC_QCH_PROTOCOL_ADDR(x), m)
#define HWIO_ASILD_NOC_QCH_PROTOCOL_QACTIVE_BMSK                                                                     0x8
#define HWIO_ASILD_NOC_QCH_PROTOCOL_QACTIVE_SHFT                                                                       3
#define HWIO_ASILD_NOC_QCH_PROTOCOL_QDENY_BMSK                                                                       0x4
#define HWIO_ASILD_NOC_QCH_PROTOCOL_QDENY_SHFT                                                                         2
#define HWIO_ASILD_NOC_QCH_PROTOCOL_QACCEPTN_BMSK                                                                    0x2
#define HWIO_ASILD_NOC_QCH_PROTOCOL_QACCEPTN_SHFT                                                                      1
#define HWIO_ASILD_NOC_QCH_PROTOCOL_QREQN_BMSK                                                                       0x1
#define HWIO_ASILD_NOC_QCH_PROTOCOL_QREQN_SHFT                                                                         0

#define HWIO_ASILD_NOC_QCH_CTRL_ADDR(x)                                                                       ((x) + 0x438)
#define HWIO_ASILD_NOC_QCH_CTRL_PHYS(x)                                                                       ((x) + 0x438)
#define HWIO_ASILD_NOC_QCH_CTRL_OFFS                                                                          (0x438)
#define HWIO_ASILD_NOC_QCH_CTRL_RMSK                                                                              0x1fff
#define HWIO_ASILD_NOC_QCH_CTRL_IN(x)            \
                in_dword(HWIO_ASILD_NOC_QCH_CTRL_ADDR(x))
#define HWIO_ASILD_NOC_QCH_CTRL_INM(x, m)            \
                in_dword_masked(HWIO_ASILD_NOC_QCH_CTRL_ADDR(x), m)
#define HWIO_ASILD_NOC_QCH_CTRL_OUT(x, v)            \
                out_dword(HWIO_ASILD_NOC_QCH_CTRL_ADDR(x),v)
#define HWIO_ASILD_NOC_QCH_CTRL_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_ASILD_NOC_QCH_CTRL_ADDR(x),m,v,HWIO_ASILD_NOC_QCH_CTRL_IN(x))
#define HWIO_ASILD_NOC_QCH_CTRL_QCH_DENY_TO_REQ_CNT_BMSK                                                          0x1fe0
#define HWIO_ASILD_NOC_QCH_CTRL_QCH_DENY_TO_REQ_CNT_SHFT                                                               5
#define HWIO_ASILD_NOC_QCH_CTRL_QCH_HYST_CNT_BMSK                                                                   0x1f
#define HWIO_ASILD_NOC_QCH_CTRL_QCH_HYST_CNT_SHFT                                                                      0

#define HWIO_ASILD_NOC_QCH_STATUS_ADDR(x)                                                                     ((x) + 0x43c)
#define HWIO_ASILD_NOC_QCH_STATUS_PHYS(x)                                                                     ((x) + 0x43c)
#define HWIO_ASILD_NOC_QCH_STATUS_OFFS                                                                        (0x43c)
#define HWIO_ASILD_NOC_QCH_STATUS_RMSK                                                                              0x7f
#define HWIO_ASILD_NOC_QCH_STATUS_IN(x)            \
                in_dword(HWIO_ASILD_NOC_QCH_STATUS_ADDR(x))
#define HWIO_ASILD_NOC_QCH_STATUS_INM(x, m)            \
                in_dword_masked(HWIO_ASILD_NOC_QCH_STATUS_ADDR(x), m)
#define HWIO_ASILD_NOC_QCH_STATUS_LOW_PWR_RDY_BMSK                                                                  0x40
#define HWIO_ASILD_NOC_QCH_STATUS_LOW_PWR_RDY_SHFT                                                                     6
#define HWIO_ASILD_NOC_QCH_STATUS_QCH_FSM_CUR_STATE_BMSK                                                            0x3c
#define HWIO_ASILD_NOC_QCH_STATUS_QCH_FSM_CUR_STATE_SHFT                                                               2
#define HWIO_ASILD_NOC_QCH_STATUS_QCH_HYST_CNT_EXPIRY_BMSK                                                           0x2
#define HWIO_ASILD_NOC_QCH_STATUS_QCH_HYST_CNT_EXPIRY_SHFT                                                             1
#define HWIO_ASILD_NOC_QCH_STATUS_QCH_DENY_TO_REQ_CNT_EXPIRY_BMSK                                                    0x1
#define HWIO_ASILD_NOC_QCH_STATUS_QCH_DENY_TO_REQ_CNT_EXPIRY_SHFT                                                      0

#define HWIO_CLUSTER0_CORE0_PCH_PROTOCOL_ADDR(x)                                                              ((x) + 0x440)
#define HWIO_CLUSTER0_CORE0_PCH_PROTOCOL_PHYS(x)                                                              ((x) + 0x440)
#define HWIO_CLUSTER0_CORE0_PCH_PROTOCOL_OFFS                                                                 (0x440)
#define HWIO_CLUSTER0_CORE0_PCH_PROTOCOL_RMSK                                                                       0x3f
#define HWIO_CLUSTER0_CORE0_PCH_PROTOCOL_IN(x)            \
                in_dword(HWIO_CLUSTER0_CORE0_PCH_PROTOCOL_ADDR(x))
#define HWIO_CLUSTER0_CORE0_PCH_PROTOCOL_INM(x, m)            \
                in_dword_masked(HWIO_CLUSTER0_CORE0_PCH_PROTOCOL_ADDR(x), m)
#define HWIO_CLUSTER0_CORE0_PCH_PROTOCOL_PACTIVE_BMSK                                                               0x30
#define HWIO_CLUSTER0_CORE0_PCH_PROTOCOL_PACTIVE_SHFT                                                                  4
#define HWIO_CLUSTER0_CORE0_PCH_PROTOCOL_PDENY_BMSK                                                                  0x8
#define HWIO_CLUSTER0_CORE0_PCH_PROTOCOL_PDENY_SHFT                                                                    3
#define HWIO_CLUSTER0_CORE0_PCH_PROTOCOL_PACCEPT_BMSK                                                                0x4
#define HWIO_CLUSTER0_CORE0_PCH_PROTOCOL_PACCEPT_SHFT                                                                  2
#define HWIO_CLUSTER0_CORE0_PCH_PROTOCOL_PREQ_BMSK                                                                   0x2
#define HWIO_CLUSTER0_CORE0_PCH_PROTOCOL_PREQ_SHFT                                                                     1
#define HWIO_CLUSTER0_CORE0_PCH_PROTOCOL_PSTATE_BMSK                                                                 0x1
#define HWIO_CLUSTER0_CORE0_PCH_PROTOCOL_PSTATE_SHFT                                                                   0

#define HWIO_CLUSTER0_CORE0_PCH_CTRL_ADDR(x)                                                                  ((x) + 0x444)
#define HWIO_CLUSTER0_CORE0_PCH_CTRL_PHYS(x)                                                                  ((x) + 0x444)
#define HWIO_CLUSTER0_CORE0_PCH_CTRL_OFFS                                                                     (0x444)
#define HWIO_CLUSTER0_CORE0_PCH_CTRL_RMSK                                                                         0xffff
#define HWIO_CLUSTER0_CORE0_PCH_CTRL_IN(x)            \
                in_dword(HWIO_CLUSTER0_CORE0_PCH_CTRL_ADDR(x))
#define HWIO_CLUSTER0_CORE0_PCH_CTRL_INM(x, m)            \
                in_dword_masked(HWIO_CLUSTER0_CORE0_PCH_CTRL_ADDR(x), m)
#define HWIO_CLUSTER0_CORE0_PCH_CTRL_OUT(x, v)            \
                out_dword(HWIO_CLUSTER0_CORE0_PCH_CTRL_ADDR(x),v)
#define HWIO_CLUSTER0_CORE0_PCH_CTRL_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_CLUSTER0_CORE0_PCH_CTRL_ADDR(x),m,v,HWIO_CLUSTER0_CORE0_PCH_CTRL_IN(x))
#define HWIO_CLUSTER0_CORE0_PCH_CTRL_PDENY_TO_PSTABLE_TMR_VAL_BMSK                                                0xff00
#define HWIO_CLUSTER0_CORE0_PCH_CTRL_PDENY_TO_PSTABLE_TMR_VAL_SHFT                                                     8
#define HWIO_CLUSTER0_CORE0_PCH_CTRL_PSTABLE_TIMER_CFG_BMSK                                                         0xff
#define HWIO_CLUSTER0_CORE0_PCH_CTRL_PSTABLE_TIMER_CFG_SHFT                                                            0

#define HWIO_CLUSTER0_CORE0_PCH_STATUS_ADDR(x)                                                                ((x) + 0x448)
#define HWIO_CLUSTER0_CORE0_PCH_STATUS_PHYS(x)                                                                ((x) + 0x448)
#define HWIO_CLUSTER0_CORE0_PCH_STATUS_OFFS                                                                   (0x448)
#define HWIO_CLUSTER0_CORE0_PCH_STATUS_RMSK                                                                          0x7
#define HWIO_CLUSTER0_CORE0_PCH_STATUS_IN(x)            \
                in_dword(HWIO_CLUSTER0_CORE0_PCH_STATUS_ADDR(x))
#define HWIO_CLUSTER0_CORE0_PCH_STATUS_INM(x, m)            \
                in_dword_masked(HWIO_CLUSTER0_CORE0_PCH_STATUS_ADDR(x), m)
#define HWIO_CLUSTER0_CORE0_PCH_STATUS_FSM_CUR_STATE_BMSK                                                            0x7
#define HWIO_CLUSTER0_CORE0_PCH_STATUS_FSM_CUR_STATE_SHFT                                                              0

#define HWIO_CLUSTER0_CORE1_PCH_PROTOCOL_ADDR(x)                                                              ((x) + 0x44c)
#define HWIO_CLUSTER0_CORE1_PCH_PROTOCOL_PHYS(x)                                                              ((x) + 0x44c)
#define HWIO_CLUSTER0_CORE1_PCH_PROTOCOL_OFFS                                                                 (0x44c)
#define HWIO_CLUSTER0_CORE1_PCH_PROTOCOL_RMSK                                                                       0x3f
#define HWIO_CLUSTER0_CORE1_PCH_PROTOCOL_IN(x)            \
                in_dword(HWIO_CLUSTER0_CORE1_PCH_PROTOCOL_ADDR(x))
#define HWIO_CLUSTER0_CORE1_PCH_PROTOCOL_INM(x, m)            \
                in_dword_masked(HWIO_CLUSTER0_CORE1_PCH_PROTOCOL_ADDR(x), m)
#define HWIO_CLUSTER0_CORE1_PCH_PROTOCOL_PACTIVE_BMSK                                                               0x30
#define HWIO_CLUSTER0_CORE1_PCH_PROTOCOL_PACTIVE_SHFT                                                                  4
#define HWIO_CLUSTER0_CORE1_PCH_PROTOCOL_PDENY_BMSK                                                                  0x8
#define HWIO_CLUSTER0_CORE1_PCH_PROTOCOL_PDENY_SHFT                                                                    3
#define HWIO_CLUSTER0_CORE1_PCH_PROTOCOL_PACCEPT_BMSK                                                                0x4
#define HWIO_CLUSTER0_CORE1_PCH_PROTOCOL_PACCEPT_SHFT                                                                  2
#define HWIO_CLUSTER0_CORE1_PCH_PROTOCOL_PREQ_BMSK                                                                   0x2
#define HWIO_CLUSTER0_CORE1_PCH_PROTOCOL_PREQ_SHFT                                                                     1
#define HWIO_CLUSTER0_CORE1_PCH_PROTOCOL_PSTATE_BMSK                                                                 0x1
#define HWIO_CLUSTER0_CORE1_PCH_PROTOCOL_PSTATE_SHFT                                                                   0

#define HWIO_CLUSTER0_CORE1_PCH_CTRL_ADDR(x)                                                                  ((x) + 0x450)
#define HWIO_CLUSTER0_CORE1_PCH_CTRL_PHYS(x)                                                                  ((x) + 0x450)
#define HWIO_CLUSTER0_CORE1_PCH_CTRL_OFFS                                                                     (0x450)
#define HWIO_CLUSTER0_CORE1_PCH_CTRL_RMSK                                                                         0xffff
#define HWIO_CLUSTER0_CORE1_PCH_CTRL_IN(x)            \
                in_dword(HWIO_CLUSTER0_CORE1_PCH_CTRL_ADDR(x))
#define HWIO_CLUSTER0_CORE1_PCH_CTRL_INM(x, m)            \
                in_dword_masked(HWIO_CLUSTER0_CORE1_PCH_CTRL_ADDR(x), m)
#define HWIO_CLUSTER0_CORE1_PCH_CTRL_OUT(x, v)            \
                out_dword(HWIO_CLUSTER0_CORE1_PCH_CTRL_ADDR(x),v)
#define HWIO_CLUSTER0_CORE1_PCH_CTRL_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_CLUSTER0_CORE1_PCH_CTRL_ADDR(x),m,v,HWIO_CLUSTER0_CORE1_PCH_CTRL_IN(x))
#define HWIO_CLUSTER0_CORE1_PCH_CTRL_PDENY_TO_PSTABLE_TMR_VAL_BMSK                                                0xff00
#define HWIO_CLUSTER0_CORE1_PCH_CTRL_PDENY_TO_PSTABLE_TMR_VAL_SHFT                                                     8
#define HWIO_CLUSTER0_CORE1_PCH_CTRL_PSTABLE_TIMER_CFG_BMSK                                                         0xff
#define HWIO_CLUSTER0_CORE1_PCH_CTRL_PSTABLE_TIMER_CFG_SHFT                                                            0

#define HWIO_CLUSTER0_CORE1_PCH_STATUS_ADDR(x)                                                                ((x) + 0x454)
#define HWIO_CLUSTER0_CORE1_PCH_STATUS_PHYS(x)                                                                ((x) + 0x454)
#define HWIO_CLUSTER0_CORE1_PCH_STATUS_OFFS                                                                   (0x454)
#define HWIO_CLUSTER0_CORE1_PCH_STATUS_RMSK                                                                          0x7
#define HWIO_CLUSTER0_CORE1_PCH_STATUS_IN(x)            \
                in_dword(HWIO_CLUSTER0_CORE1_PCH_STATUS_ADDR(x))
#define HWIO_CLUSTER0_CORE1_PCH_STATUS_INM(x, m)            \
                in_dword_masked(HWIO_CLUSTER0_CORE1_PCH_STATUS_ADDR(x), m)
#define HWIO_CLUSTER0_CORE1_PCH_STATUS_FSM_CUR_STATE_BMSK                                                            0x7
#define HWIO_CLUSTER0_CORE1_PCH_STATUS_FSM_CUR_STATE_SHFT                                                              0

#define HWIO_CLUSTER1_CORE0_PCH_PROTOCOL_ADDR(x)                                                              ((x) + 0x458)
#define HWIO_CLUSTER1_CORE0_PCH_PROTOCOL_PHYS(x)                                                              ((x) + 0x458)
#define HWIO_CLUSTER1_CORE0_PCH_PROTOCOL_OFFS                                                                 (0x458)
#define HWIO_CLUSTER1_CORE0_PCH_PROTOCOL_RMSK                                                                       0x3f
#define HWIO_CLUSTER1_CORE0_PCH_PROTOCOL_IN(x)            \
                in_dword(HWIO_CLUSTER1_CORE0_PCH_PROTOCOL_ADDR(x))
#define HWIO_CLUSTER1_CORE0_PCH_PROTOCOL_INM(x, m)            \
                in_dword_masked(HWIO_CLUSTER1_CORE0_PCH_PROTOCOL_ADDR(x), m)
#define HWIO_CLUSTER1_CORE0_PCH_PROTOCOL_PACTIVE_BMSK                                                               0x30
#define HWIO_CLUSTER1_CORE0_PCH_PROTOCOL_PACTIVE_SHFT                                                                  4
#define HWIO_CLUSTER1_CORE0_PCH_PROTOCOL_PDENY_BMSK                                                                  0x8
#define HWIO_CLUSTER1_CORE0_PCH_PROTOCOL_PDENY_SHFT                                                                    3
#define HWIO_CLUSTER1_CORE0_PCH_PROTOCOL_PACCEPT_BMSK                                                                0x4
#define HWIO_CLUSTER1_CORE0_PCH_PROTOCOL_PACCEPT_SHFT                                                                  2
#define HWIO_CLUSTER1_CORE0_PCH_PROTOCOL_PREQ_BMSK                                                                   0x2
#define HWIO_CLUSTER1_CORE0_PCH_PROTOCOL_PREQ_SHFT                                                                     1
#define HWIO_CLUSTER1_CORE0_PCH_PROTOCOL_PSTATE_BMSK                                                                 0x1
#define HWIO_CLUSTER1_CORE0_PCH_PROTOCOL_PSTATE_SHFT                                                                   0

#define HWIO_CLUSTER1_CORE0_PCH_CTRL_ADDR(x)                                                                  ((x) + 0x45c)
#define HWIO_CLUSTER1_CORE0_PCH_CTRL_PHYS(x)                                                                  ((x) + 0x45c)
#define HWIO_CLUSTER1_CORE0_PCH_CTRL_OFFS                                                                     (0x45c)
#define HWIO_CLUSTER1_CORE0_PCH_CTRL_RMSK                                                                         0xffff
#define HWIO_CLUSTER1_CORE0_PCH_CTRL_IN(x)            \
                in_dword(HWIO_CLUSTER1_CORE0_PCH_CTRL_ADDR(x))
#define HWIO_CLUSTER1_CORE0_PCH_CTRL_INM(x, m)            \
                in_dword_masked(HWIO_CLUSTER1_CORE0_PCH_CTRL_ADDR(x), m)
#define HWIO_CLUSTER1_CORE0_PCH_CTRL_OUT(x, v)            \
                out_dword(HWIO_CLUSTER1_CORE0_PCH_CTRL_ADDR(x),v)
#define HWIO_CLUSTER1_CORE0_PCH_CTRL_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_CLUSTER1_CORE0_PCH_CTRL_ADDR(x),m,v,HWIO_CLUSTER1_CORE0_PCH_CTRL_IN(x))
#define HWIO_CLUSTER1_CORE0_PCH_CTRL_PDENY_TO_PSTABLE_TMR_VAL_BMSK                                                0xff00
#define HWIO_CLUSTER1_CORE0_PCH_CTRL_PDENY_TO_PSTABLE_TMR_VAL_SHFT                                                     8
#define HWIO_CLUSTER1_CORE0_PCH_CTRL_PSTABLE_TIMER_CFG_BMSK                                                         0xff
#define HWIO_CLUSTER1_CORE0_PCH_CTRL_PSTABLE_TIMER_CFG_SHFT                                                            0

#define HWIO_CLUSTER1_CORE0_PCH_STATUS_ADDR(x)                                                                ((x) + 0x460)
#define HWIO_CLUSTER1_CORE0_PCH_STATUS_PHYS(x)                                                                ((x) + 0x460)
#define HWIO_CLUSTER1_CORE0_PCH_STATUS_OFFS                                                                   (0x460)
#define HWIO_CLUSTER1_CORE0_PCH_STATUS_RMSK                                                                          0x7
#define HWIO_CLUSTER1_CORE0_PCH_STATUS_IN(x)            \
                in_dword(HWIO_CLUSTER1_CORE0_PCH_STATUS_ADDR(x))
#define HWIO_CLUSTER1_CORE0_PCH_STATUS_INM(x, m)            \
                in_dword_masked(HWIO_CLUSTER1_CORE0_PCH_STATUS_ADDR(x), m)
#define HWIO_CLUSTER1_CORE0_PCH_STATUS_FSM_CUR_STATE_BMSK                                                            0x7
#define HWIO_CLUSTER1_CORE0_PCH_STATUS_FSM_CUR_STATE_SHFT                                                              0

#define HWIO_CLUSTER1_CORE1_PCH_PROTOCOL_ADDR(x)                                                              ((x) + 0x464)
#define HWIO_CLUSTER1_CORE1_PCH_PROTOCOL_PHYS(x)                                                              ((x) + 0x464)
#define HWIO_CLUSTER1_CORE1_PCH_PROTOCOL_OFFS                                                                 (0x464)
#define HWIO_CLUSTER1_CORE1_PCH_PROTOCOL_RMSK                                                                       0x3f
#define HWIO_CLUSTER1_CORE1_PCH_PROTOCOL_IN(x)            \
                in_dword(HWIO_CLUSTER1_CORE1_PCH_PROTOCOL_ADDR(x))
#define HWIO_CLUSTER1_CORE1_PCH_PROTOCOL_INM(x, m)            \
                in_dword_masked(HWIO_CLUSTER1_CORE1_PCH_PROTOCOL_ADDR(x), m)
#define HWIO_CLUSTER1_CORE1_PCH_PROTOCOL_PACTIVE_BMSK                                                               0x30
#define HWIO_CLUSTER1_CORE1_PCH_PROTOCOL_PACTIVE_SHFT                                                                  4
#define HWIO_CLUSTER1_CORE1_PCH_PROTOCOL_PDENY_BMSK                                                                  0x8
#define HWIO_CLUSTER1_CORE1_PCH_PROTOCOL_PDENY_SHFT                                                                    3
#define HWIO_CLUSTER1_CORE1_PCH_PROTOCOL_PACCEPT_BMSK                                                                0x4
#define HWIO_CLUSTER1_CORE1_PCH_PROTOCOL_PACCEPT_SHFT                                                                  2
#define HWIO_CLUSTER1_CORE1_PCH_PROTOCOL_PREQ_BMSK                                                                   0x2
#define HWIO_CLUSTER1_CORE1_PCH_PROTOCOL_PREQ_SHFT                                                                     1
#define HWIO_CLUSTER1_CORE1_PCH_PROTOCOL_PSTATE_BMSK                                                                 0x1
#define HWIO_CLUSTER1_CORE1_PCH_PROTOCOL_PSTATE_SHFT                                                                   0

#define HWIO_CLUSTER1_CORE1_PCH_CTRL_ADDR(x)                                                                  ((x) + 0x468)
#define HWIO_CLUSTER1_CORE1_PCH_CTRL_PHYS(x)                                                                  ((x) + 0x468)
#define HWIO_CLUSTER1_CORE1_PCH_CTRL_OFFS                                                                     (0x468)
#define HWIO_CLUSTER1_CORE1_PCH_CTRL_RMSK                                                                         0xffff
#define HWIO_CLUSTER1_CORE1_PCH_CTRL_IN(x)            \
                in_dword(HWIO_CLUSTER1_CORE1_PCH_CTRL_ADDR(x))
#define HWIO_CLUSTER1_CORE1_PCH_CTRL_INM(x, m)            \
                in_dword_masked(HWIO_CLUSTER1_CORE1_PCH_CTRL_ADDR(x), m)
#define HWIO_CLUSTER1_CORE1_PCH_CTRL_OUT(x, v)            \
                out_dword(HWIO_CLUSTER1_CORE1_PCH_CTRL_ADDR(x),v)
#define HWIO_CLUSTER1_CORE1_PCH_CTRL_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_CLUSTER1_CORE1_PCH_CTRL_ADDR(x),m,v,HWIO_CLUSTER1_CORE1_PCH_CTRL_IN(x))
#define HWIO_CLUSTER1_CORE1_PCH_CTRL_PDENY_TO_PSTABLE_TMR_VAL_BMSK                                                0xff00
#define HWIO_CLUSTER1_CORE1_PCH_CTRL_PDENY_TO_PSTABLE_TMR_VAL_SHFT                                                     8
#define HWIO_CLUSTER1_CORE1_PCH_CTRL_PSTABLE_TIMER_CFG_BMSK                                                         0xff
#define HWIO_CLUSTER1_CORE1_PCH_CTRL_PSTABLE_TIMER_CFG_SHFT                                                            0

#define HWIO_CLUSTER1_CORE1_PCH_STATUS_ADDR(x)                                                                ((x) + 0x46c)
#define HWIO_CLUSTER1_CORE1_PCH_STATUS_PHYS(x)                                                                ((x) + 0x46c)
#define HWIO_CLUSTER1_CORE1_PCH_STATUS_OFFS                                                                   (0x46c)
#define HWIO_CLUSTER1_CORE1_PCH_STATUS_RMSK                                                                          0x7
#define HWIO_CLUSTER1_CORE1_PCH_STATUS_IN(x)            \
                in_dword(HWIO_CLUSTER1_CORE1_PCH_STATUS_ADDR(x))
#define HWIO_CLUSTER1_CORE1_PCH_STATUS_INM(x, m)            \
                in_dword_masked(HWIO_CLUSTER1_CORE1_PCH_STATUS_ADDR(x), m)
#define HWIO_CLUSTER1_CORE1_PCH_STATUS_FSM_CUR_STATE_BMSK                                                            0x7
#define HWIO_CLUSTER1_CORE1_PCH_STATUS_FSM_CUR_STATE_SHFT                                                              0

#define HWIO_WAKE_IRQ_CFG_ENABLE_0_ADDR(x)                                                                    ((x) + 0x470)
#define HWIO_WAKE_IRQ_CFG_ENABLE_0_PHYS(x)                                                                    ((x) + 0x470)
#define HWIO_WAKE_IRQ_CFG_ENABLE_0_OFFS                                                                       (0x470)
#define HWIO_WAKE_IRQ_CFG_ENABLE_0_RMSK                                                                       0xffffffff
#define HWIO_WAKE_IRQ_CFG_ENABLE_0_IN(x)            \
                in_dword(HWIO_WAKE_IRQ_CFG_ENABLE_0_ADDR(x))
#define HWIO_WAKE_IRQ_CFG_ENABLE_0_INM(x, m)            \
                in_dword_masked(HWIO_WAKE_IRQ_CFG_ENABLE_0_ADDR(x), m)
#define HWIO_WAKE_IRQ_CFG_ENABLE_0_OUT(x, v)            \
                out_dword(HWIO_WAKE_IRQ_CFG_ENABLE_0_ADDR(x),v)
#define HWIO_WAKE_IRQ_CFG_ENABLE_0_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_WAKE_IRQ_CFG_ENABLE_0_ADDR(x),m,v,HWIO_WAKE_IRQ_CFG_ENABLE_0_IN(x))
#define HWIO_WAKE_IRQ_CFG_ENABLE_0_WAKE_IRQ_CFG_ENABLE_BMSK                                                   0xffffffff
#define HWIO_WAKE_IRQ_CFG_ENABLE_0_WAKE_IRQ_CFG_ENABLE_SHFT                                                            0

#define HWIO_WAKE_IRQ_CFG_NEGEDGE_0_ADDR(x)                                                                   ((x) + 0x474)
#define HWIO_WAKE_IRQ_CFG_NEGEDGE_0_PHYS(x)                                                                   ((x) + 0x474)
#define HWIO_WAKE_IRQ_CFG_NEGEDGE_0_OFFS                                                                      (0x474)
#define HWIO_WAKE_IRQ_CFG_NEGEDGE_0_RMSK                                                                      0xffffffff
#define HWIO_WAKE_IRQ_CFG_NEGEDGE_0_IN(x)            \
                in_dword(HWIO_WAKE_IRQ_CFG_NEGEDGE_0_ADDR(x))
#define HWIO_WAKE_IRQ_CFG_NEGEDGE_0_INM(x, m)            \
                in_dword_masked(HWIO_WAKE_IRQ_CFG_NEGEDGE_0_ADDR(x), m)
#define HWIO_WAKE_IRQ_CFG_NEGEDGE_0_OUT(x, v)            \
                out_dword(HWIO_WAKE_IRQ_CFG_NEGEDGE_0_ADDR(x),v)
#define HWIO_WAKE_IRQ_CFG_NEGEDGE_0_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_WAKE_IRQ_CFG_NEGEDGE_0_ADDR(x),m,v,HWIO_WAKE_IRQ_CFG_NEGEDGE_0_IN(x))
#define HWIO_WAKE_IRQ_CFG_NEGEDGE_0_WAKE_IRQ_CFG_NEGEDGE_BMSK                                                 0xffffffff
#define HWIO_WAKE_IRQ_CFG_NEGEDGE_0_WAKE_IRQ_CFG_NEGEDGE_SHFT                                                          0

#define HWIO_WAKE_IRQ_CFG_POSEDGE_0_ADDR(x)                                                                   ((x) + 0x478)
#define HWIO_WAKE_IRQ_CFG_POSEDGE_0_PHYS(x)                                                                   ((x) + 0x478)
#define HWIO_WAKE_IRQ_CFG_POSEDGE_0_OFFS                                                                      (0x478)
#define HWIO_WAKE_IRQ_CFG_POSEDGE_0_RMSK                                                                      0xffffffff
#define HWIO_WAKE_IRQ_CFG_POSEDGE_0_IN(x)            \
                in_dword(HWIO_WAKE_IRQ_CFG_POSEDGE_0_ADDR(x))
#define HWIO_WAKE_IRQ_CFG_POSEDGE_0_INM(x, m)            \
                in_dword_masked(HWIO_WAKE_IRQ_CFG_POSEDGE_0_ADDR(x), m)
#define HWIO_WAKE_IRQ_CFG_POSEDGE_0_OUT(x, v)            \
                out_dword(HWIO_WAKE_IRQ_CFG_POSEDGE_0_ADDR(x),v)
#define HWIO_WAKE_IRQ_CFG_POSEDGE_0_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_WAKE_IRQ_CFG_POSEDGE_0_ADDR(x),m,v,HWIO_WAKE_IRQ_CFG_POSEDGE_0_IN(x))
#define HWIO_WAKE_IRQ_CFG_POSEDGE_0_WAKE_IRQ_CFG_POSEDGE_BMSK                                                 0xffffffff
#define HWIO_WAKE_IRQ_CFG_POSEDGE_0_WAKE_IRQ_CFG_POSEDGE_SHFT                                                          0

#define HWIO_WAKE_IRQ_CFG_POLARITY_0_ADDR(x)                                                                  ((x) + 0x47c)
#define HWIO_WAKE_IRQ_CFG_POLARITY_0_PHYS(x)                                                                  ((x) + 0x47c)
#define HWIO_WAKE_IRQ_CFG_POLARITY_0_OFFS                                                                     (0x47c)
#define HWIO_WAKE_IRQ_CFG_POLARITY_0_RMSK                                                                     0xffffffff
#define HWIO_WAKE_IRQ_CFG_POLARITY_0_IN(x)            \
                in_dword(HWIO_WAKE_IRQ_CFG_POLARITY_0_ADDR(x))
#define HWIO_WAKE_IRQ_CFG_POLARITY_0_INM(x, m)            \
                in_dword_masked(HWIO_WAKE_IRQ_CFG_POLARITY_0_ADDR(x), m)
#define HWIO_WAKE_IRQ_CFG_POLARITY_0_OUT(x, v)            \
                out_dword(HWIO_WAKE_IRQ_CFG_POLARITY_0_ADDR(x),v)
#define HWIO_WAKE_IRQ_CFG_POLARITY_0_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_WAKE_IRQ_CFG_POLARITY_0_ADDR(x),m,v,HWIO_WAKE_IRQ_CFG_POLARITY_0_IN(x))
#define HWIO_WAKE_IRQ_CFG_POLARITY_0_WAKE_IRQ_CFG_POLARITY_BMSK                                               0xffffffff
#define HWIO_WAKE_IRQ_CFG_POLARITY_0_WAKE_IRQ_CFG_POLARITY_SHFT                                                        0

#define HWIO_WAKE_IRQ_STATUS_0_ADDR(x)                                                                        ((x) + 0x480)
#define HWIO_WAKE_IRQ_STATUS_0_PHYS(x)                                                                        ((x) + 0x480)
#define HWIO_WAKE_IRQ_STATUS_0_OFFS                                                                           (0x480)
#define HWIO_WAKE_IRQ_STATUS_0_RMSK                                                                           0xffffffff
#define HWIO_WAKE_IRQ_STATUS_0_IN(x)            \
                in_dword(HWIO_WAKE_IRQ_STATUS_0_ADDR(x))
#define HWIO_WAKE_IRQ_STATUS_0_INM(x, m)            \
                in_dword_masked(HWIO_WAKE_IRQ_STATUS_0_ADDR(x), m)
#define HWIO_WAKE_IRQ_STATUS_0_WAKE_IRQ_STATUS_BMSK                                                           0xffffffff
#define HWIO_WAKE_IRQ_STATUS_0_WAKE_IRQ_STATUS_SHFT                                                                    0

#define HWIO_WAKE_HANDLER_CFG_ADDR(x)                                                                         ((x) + 0x484)
#define HWIO_WAKE_HANDLER_CFG_PHYS(x)                                                                         ((x) + 0x484)
#define HWIO_WAKE_HANDLER_CFG_OFFS                                                                            (0x484)
#define HWIO_WAKE_HANDLER_CFG_RMSK                                                                                   0x7
#define HWIO_WAKE_HANDLER_CFG_IN(x)            \
                in_dword(HWIO_WAKE_HANDLER_CFG_ADDR(x))
#define HWIO_WAKE_HANDLER_CFG_INM(x, m)            \
                in_dword_masked(HWIO_WAKE_HANDLER_CFG_ADDR(x), m)
#define HWIO_WAKE_HANDLER_CFG_OUT(x, v)            \
                out_dword(HWIO_WAKE_HANDLER_CFG_ADDR(x),v)
#define HWIO_WAKE_HANDLER_CFG_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_WAKE_HANDLER_CFG_ADDR(x),m,v,HWIO_WAKE_HANDLER_CFG_IN(x))
#define HWIO_WAKE_HANDLER_CFG_WAKE_HANDLER_CLK_ENABLE_BMSK                                                           0x4
#define HWIO_WAKE_HANDLER_CFG_WAKE_HANDLER_CLK_ENABLE_SHFT                                                             2
#define HWIO_WAKE_HANDLER_CFG_STOP_MONITORING_BMSK                                                                   0x2
#define HWIO_WAKE_HANDLER_CFG_STOP_MONITORING_SHFT                                                                     1
#define HWIO_WAKE_HANDLER_CFG_START_MONITORING_BMSK                                                                  0x1
#define HWIO_WAKE_HANDLER_CFG_START_MONITORING_SHFT                                                                    0

#define HWIO_WAKE_HANDLER_STATUS_ADDR(x)                                                                      ((x) + 0x488)
#define HWIO_WAKE_HANDLER_STATUS_PHYS(x)                                                                      ((x) + 0x488)
#define HWIO_WAKE_HANDLER_STATUS_OFFS                                                                         (0x488)
#define HWIO_WAKE_HANDLER_STATUS_RMSK                                                                               0x1f
#define HWIO_WAKE_HANDLER_STATUS_IN(x)            \
                in_dword(HWIO_WAKE_HANDLER_STATUS_ADDR(x))
#define HWIO_WAKE_HANDLER_STATUS_INM(x, m)            \
                in_dword_masked(HWIO_WAKE_HANDLER_STATUS_ADDR(x), m)
#define HWIO_WAKE_HANDLER_STATUS_REPLAY_CURR_STATE_BMSK                                                             0x18
#define HWIO_WAKE_HANDLER_STATUS_REPLAY_CURR_STATE_SHFT                                                                3
#define HWIO_WAKE_HANDLER_STATUS_MAIN_CURR_STATE_BMSK                                                                0x6
#define HWIO_WAKE_HANDLER_STATUS_MAIN_CURR_STATE_SHFT                                                                  1
#define HWIO_WAKE_HANDLER_STATUS_MONITORING_STARTED_BMSK                                                             0x1
#define HWIO_WAKE_HANDLER_STATUS_MONITORING_STARTED_SHFT                                                               0

#define HWIO_SAIL_CX_APM_FUNC_OUT_ADDR(x)                                                                     ((x) + 0x48c)
#define HWIO_SAIL_CX_APM_FUNC_OUT_PHYS(x)                                                                     ((x) + 0x48c)
#define HWIO_SAIL_CX_APM_FUNC_OUT_OFFS                                                                        (0x48c)
#define HWIO_SAIL_CX_APM_FUNC_OUT_RMSK                                                                        0xffffffff
#define HWIO_SAIL_CX_APM_FUNC_OUT_IN(x)            \
                in_dword(HWIO_SAIL_CX_APM_FUNC_OUT_ADDR(x))
#define HWIO_SAIL_CX_APM_FUNC_OUT_INM(x, m)            \
                in_dword_masked(HWIO_SAIL_CX_APM_FUNC_OUT_ADDR(x), m)
#define HWIO_SAIL_CX_APM_FUNC_OUT_OUT(x, v)            \
                out_dword(HWIO_SAIL_CX_APM_FUNC_OUT_ADDR(x),v)
#define HWIO_SAIL_CX_APM_FUNC_OUT_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_SAIL_CX_APM_FUNC_OUT_ADDR(x),m,v,HWIO_SAIL_CX_APM_FUNC_OUT_IN(x))
#define HWIO_SAIL_CX_APM_FUNC_OUT_SAIL_CX_APM_FUNC_OUT_BMSK                                                   0xffffffff
#define HWIO_SAIL_CX_APM_FUNC_OUT_SAIL_CX_APM_FUNC_OUT_SHFT                                                            0

#define HWIO_SAIL_CX_APM_FUNC_IN_ADDR(x)                                                                      ((x) + 0x490)
#define HWIO_SAIL_CX_APM_FUNC_IN_PHYS(x)                                                                      ((x) + 0x490)
#define HWIO_SAIL_CX_APM_FUNC_IN_OFFS                                                                         (0x490)
#define HWIO_SAIL_CX_APM_FUNC_IN_RMSK                                                                         0xffffffff
#define HWIO_SAIL_CX_APM_FUNC_IN_IN(x)            \
                in_dword(HWIO_SAIL_CX_APM_FUNC_IN_ADDR(x))
#define HWIO_SAIL_CX_APM_FUNC_IN_INM(x, m)            \
                in_dword_masked(HWIO_SAIL_CX_APM_FUNC_IN_ADDR(x), m)
#define HWIO_SAIL_CX_APM_FUNC_IN_SAIL_CX_APM_FUNC_IN_BMSK                                                     0xffffffff
#define HWIO_SAIL_CX_APM_FUNC_IN_SAIL_CX_APM_FUNC_IN_SHFT                                                              0

#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_0_ADDR(x)                                                          ((x) + 0x494)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_0_PHYS(x)                                                          ((x) + 0x494)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_0_OFFS                                                             (0x494)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_0_RMSK                                                             0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_0_IN(x)            \
                in_dword(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_0_ADDR(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_0_INM(x, m)            \
                in_dword_masked(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_0_ADDR(x), m)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_0_OUT(x, v)            \
                out_dword(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_0_ADDR(x),v)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_0_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_0_ADDR(x),m,v,HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_0_IN(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_0_SAIL_CX_APM_CONTROLLER_CONFIG_0_BMSK                             0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_0_SAIL_CX_APM_CONTROLLER_CONFIG_0_SHFT                                      0

#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_1_ADDR(x)                                                          ((x) + 0x498)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_1_PHYS(x)                                                          ((x) + 0x498)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_1_OFFS                                                             (0x498)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_1_RMSK                                                             0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_1_IN(x)            \
                in_dword(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_1_ADDR(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_1_INM(x, m)            \
                in_dword_masked(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_1_ADDR(x), m)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_1_OUT(x, v)            \
                out_dword(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_1_ADDR(x),v)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_1_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_1_ADDR(x),m,v,HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_1_IN(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_1_SAIL_CX_APM_CONTROLLER_CONFIG_1_BMSK                             0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_1_SAIL_CX_APM_CONTROLLER_CONFIG_1_SHFT                                      0

#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_2_ADDR(x)                                                          ((x) + 0x49c)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_2_PHYS(x)                                                          ((x) + 0x49c)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_2_OFFS                                                             (0x49c)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_2_RMSK                                                             0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_2_IN(x)            \
                in_dword(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_2_ADDR(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_2_INM(x, m)            \
                in_dword_masked(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_2_ADDR(x), m)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_2_OUT(x, v)            \
                out_dword(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_2_ADDR(x),v)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_2_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_2_ADDR(x),m,v,HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_2_IN(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_2_SAIL_CX_APM_CONTROLLER_CONFIG_2_BMSK                             0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_2_SAIL_CX_APM_CONTROLLER_CONFIG_2_SHFT                                      0

#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_3_ADDR(x)                                                          ((x) + 0x4a0)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_3_PHYS(x)                                                          ((x) + 0x4a0)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_3_OFFS                                                             (0x4a0)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_3_RMSK                                                             0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_3_IN(x)            \
                in_dword(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_3_ADDR(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_3_INM(x, m)            \
                in_dword_masked(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_3_ADDR(x), m)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_3_OUT(x, v)            \
                out_dword(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_3_ADDR(x),v)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_3_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_3_ADDR(x),m,v,HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_3_IN(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_3_SAIL_CX_APM_CONTROLLER_CONFIG_3_BMSK                             0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_3_SAIL_CX_APM_CONTROLLER_CONFIG_3_SHFT                                      0

#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_4_ADDR(x)                                                          ((x) + 0x4a4)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_4_PHYS(x)                                                          ((x) + 0x4a4)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_4_OFFS                                                             (0x4a4)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_4_RMSK                                                             0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_4_IN(x)            \
                in_dword(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_4_ADDR(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_4_INM(x, m)            \
                in_dword_masked(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_4_ADDR(x), m)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_4_OUT(x, v)            \
                out_dword(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_4_ADDR(x),v)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_4_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_4_ADDR(x),m,v,HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_4_IN(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_4_SAIL_CX_APM_CONTROLLER_CONFIG_4_BMSK                             0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_4_SAIL_CX_APM_CONTROLLER_CONFIG_4_SHFT                                      0

#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_5_ADDR(x)                                                          ((x) + 0x4a8)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_5_PHYS(x)                                                          ((x) + 0x4a8)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_5_OFFS                                                             (0x4a8)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_5_RMSK                                                             0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_5_IN(x)            \
                in_dword(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_5_ADDR(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_5_INM(x, m)            \
                in_dword_masked(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_5_ADDR(x), m)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_5_OUT(x, v)            \
                out_dword(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_5_ADDR(x),v)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_5_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_5_ADDR(x),m,v,HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_5_IN(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_5_APM2TILE_DOM2AUX_FDBK_CONFIG_SEL_BMSK                            0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_5_APM2TILE_DOM2AUX_FDBK_CONFIG_SEL_SHFT                                     0

#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_6_ADDR(x)                                                          ((x) + 0x4ac)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_6_PHYS(x)                                                          ((x) + 0x4ac)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_6_OFFS                                                             (0x4ac)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_6_RMSK                                                             0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_6_IN(x)            \
                in_dword(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_6_ADDR(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_6_INM(x, m)            \
                in_dword_masked(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_6_ADDR(x), m)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_6_OUT(x, v)            \
                out_dword(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_6_ADDR(x),v)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_6_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_6_ADDR(x),m,v,HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_6_IN(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_6_APM2TILE_DOM2AUX_FDBK_CONFIG_SEL_BMSK                            0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_6_APM2TILE_DOM2AUX_FDBK_CONFIG_SEL_SHFT                                     0

#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_7_ADDR(x)                                                          ((x) + 0x4b0)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_7_PHYS(x)                                                          ((x) + 0x4b0)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_7_OFFS                                                             (0x4b0)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_7_RMSK                                                             0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_7_IN(x)            \
                in_dword(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_7_ADDR(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_7_INM(x, m)            \
                in_dword_masked(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_7_ADDR(x), m)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_7_OUT(x, v)            \
                out_dword(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_7_ADDR(x),v)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_7_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_7_ADDR(x),m,v,HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_7_IN(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_7_SAIL_CX_APM_CONTROLLER_CONFIG_7_BMSK                             0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_7_SAIL_CX_APM_CONTROLLER_CONFIG_7_SHFT                                      0

#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_8_ADDR(x)                                                          ((x) + 0x4b4)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_8_PHYS(x)                                                          ((x) + 0x4b4)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_8_OFFS                                                             (0x4b4)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_8_RMSK                                                             0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_8_IN(x)            \
                in_dword(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_8_ADDR(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_8_INM(x, m)            \
                in_dword_masked(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_8_ADDR(x), m)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_8_OUT(x, v)            \
                out_dword(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_8_ADDR(x),v)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_8_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_8_ADDR(x),m,v,HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_8_IN(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_8_APM2TILE_AUX2DOM_FDBK_CONFIG_SEL_BMSK                            0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_8_APM2TILE_AUX2DOM_FDBK_CONFIG_SEL_SHFT                                     0

#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_9_ADDR(x)                                                          ((x) + 0x4b8)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_9_PHYS(x)                                                          ((x) + 0x4b8)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_9_OFFS                                                             (0x4b8)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_9_RMSK                                                             0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_9_IN(x)            \
                in_dword(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_9_ADDR(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_9_INM(x, m)            \
                in_dword_masked(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_9_ADDR(x), m)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_9_OUT(x, v)            \
                out_dword(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_9_ADDR(x),v)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_9_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_9_ADDR(x),m,v,HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_9_IN(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_9_APM2TILE_AUX2DOM_FDBK_CONFIG_SEL_BMSK                            0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_9_APM2TILE_AUX2DOM_FDBK_CONFIG_SEL_SHFT                                     0

#define HWIO_SAIL_CX_APM_CONTROLLER_RSVD_OUT_ADDR(x)                                                          ((x) + 0x4bc)
#define HWIO_SAIL_CX_APM_CONTROLLER_RSVD_OUT_PHYS(x)                                                          ((x) + 0x4bc)
#define HWIO_SAIL_CX_APM_CONTROLLER_RSVD_OUT_OFFS                                                             (0x4bc)
#define HWIO_SAIL_CX_APM_CONTROLLER_RSVD_OUT_RMSK                                                             0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_RSVD_OUT_IN(x)            \
                in_dword(HWIO_SAIL_CX_APM_CONTROLLER_RSVD_OUT_ADDR(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_RSVD_OUT_INM(x, m)            \
                in_dword_masked(HWIO_SAIL_CX_APM_CONTROLLER_RSVD_OUT_ADDR(x), m)
#define HWIO_SAIL_CX_APM_CONTROLLER_RSVD_OUT_OUT(x, v)            \
                out_dword(HWIO_SAIL_CX_APM_CONTROLLER_RSVD_OUT_ADDR(x),v)
#define HWIO_SAIL_CX_APM_CONTROLLER_RSVD_OUT_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_SAIL_CX_APM_CONTROLLER_RSVD_OUT_ADDR(x),m,v,HWIO_SAIL_CX_APM_CONTROLLER_RSVD_OUT_IN(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_RSVD_OUT_RSVD_OUT_BMSK                                                    0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_RSVD_OUT_RSVD_OUT_SHFT                                                             0

#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_0_ADDR(x)                                                          ((x) + 0x4c0)
#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_0_PHYS(x)                                                          ((x) + 0x4c0)
#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_0_OFFS                                                             (0x4c0)
#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_0_RMSK                                                             0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_0_IN(x)            \
                in_dword(HWIO_SAIL_CX_APM_CONTROLLER_STATUS_0_ADDR(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_0_INM(x, m)            \
                in_dword_masked(HWIO_SAIL_CX_APM_CONTROLLER_STATUS_0_ADDR(x), m)
#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_0_SAIL_CX_APM_CONTROLLER_STATUS_0_BMSK                             0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_0_SAIL_CX_APM_CONTROLLER_STATUS_0_SHFT                                      0

#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_1_ADDR(x)                                                          ((x) + 0x4c4)
#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_1_PHYS(x)                                                          ((x) + 0x4c4)
#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_1_OFFS                                                             (0x4c4)
#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_1_RMSK                                                             0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_1_IN(x)            \
                in_dword(HWIO_SAIL_CX_APM_CONTROLLER_STATUS_1_ADDR(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_1_INM(x, m)            \
                in_dword_masked(HWIO_SAIL_CX_APM_CONTROLLER_STATUS_1_ADDR(x), m)
#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_1_SAIL_CX_APM_CONTROLLER_STATUS_1_BMSK                             0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_1_SAIL_CX_APM_CONTROLLER_STATUS_1_SHFT                                      0

#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_2_ADDR(x)                                                          ((x) + 0x4c8)
#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_2_PHYS(x)                                                          ((x) + 0x4c8)
#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_2_OFFS                                                             (0x4c8)
#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_2_RMSK                                                             0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_2_IN(x)            \
                in_dword(HWIO_SAIL_CX_APM_CONTROLLER_STATUS_2_ADDR(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_2_INM(x, m)            \
                in_dword_masked(HWIO_SAIL_CX_APM_CONTROLLER_STATUS_2_ADDR(x), m)
#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_2_SAIL_CX_APM_CONTROLLER_STATUS_2_BMSK                             0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_2_SAIL_CX_APM_CONTROLLER_STATUS_2_SHFT                                      0

#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_3_ADDR(x)                                                          ((x) + 0x4cc)
#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_3_PHYS(x)                                                          ((x) + 0x4cc)
#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_3_OFFS                                                             (0x4cc)
#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_3_RMSK                                                             0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_3_IN(x)            \
                in_dword(HWIO_SAIL_CX_APM_CONTROLLER_STATUS_3_ADDR(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_3_INM(x, m)            \
                in_dword_masked(HWIO_SAIL_CX_APM_CONTROLLER_STATUS_3_ADDR(x), m)
#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_3_SAIL_CX_APM_CONTROLLER_STATUS_3_BMSK                             0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_STATUS_3_SAIL_CX_APM_CONTROLLER_STATUS_3_SHFT                                      0

#define HWIO_SAIL_CX_APM_CONTROLLER_RSVD_IN_ADDR(x)                                                           ((x) + 0x4d0)
#define HWIO_SAIL_CX_APM_CONTROLLER_RSVD_IN_PHYS(x)                                                           ((x) + 0x4d0)
#define HWIO_SAIL_CX_APM_CONTROLLER_RSVD_IN_OFFS                                                              (0x4d0)
#define HWIO_SAIL_CX_APM_CONTROLLER_RSVD_IN_RMSK                                                              0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_RSVD_IN_IN(x)            \
                in_dword(HWIO_SAIL_CX_APM_CONTROLLER_RSVD_IN_ADDR(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_RSVD_IN_INM(x, m)            \
                in_dword_masked(HWIO_SAIL_CX_APM_CONTROLLER_RSVD_IN_ADDR(x), m)
#define HWIO_SAIL_CX_APM_CONTROLLER_RSVD_IN_RSVD_IN_BMSK                                                      0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_RSVD_IN_RSVD_IN_SHFT                                                               0

#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_8_1_ADDR(x)                                                        ((x) + 0x4d4)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_8_1_PHYS(x)                                                        ((x) + 0x4d4)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_8_1_OFFS                                                           (0x4d4)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_8_1_RMSK                                                           0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_8_1_IN(x)            \
                in_dword(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_8_1_ADDR(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_8_1_INM(x, m)            \
                in_dword_masked(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_8_1_ADDR(x), m)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_8_1_OUT(x, v)            \
                out_dword(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_8_1_ADDR(x),v)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_8_1_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_8_1_ADDR(x),m,v,HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_8_1_IN(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_8_1_APM2TILE_AUX2DOM_FDBK_CONFIG_SEL_BMSK                          0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_8_1_APM2TILE_AUX2DOM_FDBK_CONFIG_SEL_SHFT                                   0

#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_9_1_ADDR(x)                                                        ((x) + 0x4d8)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_9_1_PHYS(x)                                                        ((x) + 0x4d8)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_9_1_OFFS                                                           (0x4d8)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_9_1_RMSK                                                           0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_9_1_IN(x)            \
                in_dword(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_9_1_ADDR(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_9_1_INM(x, m)            \
                in_dword_masked(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_9_1_ADDR(x), m)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_9_1_OUT(x, v)            \
                out_dword(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_9_1_ADDR(x),v)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_9_1_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_9_1_ADDR(x),m,v,HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_9_1_IN(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_9_1_APM2TILE_AUX2DOM_FDBK_CONFIG_SEL_BMSK                          0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_9_1_APM2TILE_AUX2DOM_FDBK_CONFIG_SEL_SHFT                                   0

#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_5_1_ADDR(x)                                                        ((x) + 0x4dc)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_5_1_PHYS(x)                                                        ((x) + 0x4dc)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_5_1_OFFS                                                           (0x4dc)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_5_1_RMSK                                                           0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_5_1_IN(x)            \
                in_dword(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_5_1_ADDR(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_5_1_INM(x, m)            \
                in_dword_masked(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_5_1_ADDR(x), m)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_5_1_OUT(x, v)            \
                out_dword(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_5_1_ADDR(x),v)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_5_1_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_5_1_ADDR(x),m,v,HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_5_1_IN(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_5_1_APM2TILE_DOM2AUX_FDBK_CONFIG_SEL_BMSK                          0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_5_1_APM2TILE_DOM2AUX_FDBK_CONFIG_SEL_SHFT                                   0

#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_6_1_ADDR(x)                                                        ((x) + 0x4e0)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_6_1_PHYS(x)                                                        ((x) + 0x4e0)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_6_1_OFFS                                                           (0x4e0)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_6_1_RMSK                                                           0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_6_1_IN(x)            \
                in_dword(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_6_1_ADDR(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_6_1_INM(x, m)            \
                in_dword_masked(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_6_1_ADDR(x), m)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_6_1_OUT(x, v)            \
                out_dword(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_6_1_ADDR(x),v)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_6_1_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_6_1_ADDR(x),m,v,HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_6_1_IN(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_6_1_APM2TILE_DOM2AUX_FDBK_CONFIG_SEL_BMSK                          0xffffffff
#define HWIO_SAIL_CX_APM_CONTROLLER_CONFIG_6_1_APM2TILE_DOM2AUX_FDBK_CONFIG_SEL_SHFT                                   0

#define HWIO_SAIL_CX_APM_CONTROLLER_CONTROL_ADDR(x)                                                           ((x) + 0x4e4)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONTROL_PHYS(x)                                                           ((x) + 0x4e4)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONTROL_OFFS                                                              (0x4e4)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONTROL_RMSK                                                                     0x1
#define HWIO_SAIL_CX_APM_CONTROLLER_CONTROL_IN(x)            \
                in_dword(HWIO_SAIL_CX_APM_CONTROLLER_CONTROL_ADDR(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_CONTROL_INM(x, m)            \
                in_dword_masked(HWIO_SAIL_CX_APM_CONTROLLER_CONTROL_ADDR(x), m)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONTROL_OUT(x, v)            \
                out_dword(HWIO_SAIL_CX_APM_CONTROLLER_CONTROL_ADDR(x),v)
#define HWIO_SAIL_CX_APM_CONTROLLER_CONTROL_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_SAIL_CX_APM_CONTROLLER_CONTROL_ADDR(x),m,v,HWIO_SAIL_CX_APM_CONTROLLER_CONTROL_IN(x))
#define HWIO_SAIL_CX_APM_CONTROLLER_CONTROL_CSR_SAIL_CX_APM_CTRL_SEL_BMSK                                            0x1
#define HWIO_SAIL_CX_APM_CONTROLLER_CONTROL_CSR_SAIL_CX_APM_CTRL_SEL_SHFT                                              0

#define HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_ADDR(x)                                                             ((x) + 0x500)
#define HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_PHYS(x)                                                             ((x) + 0x500)
#define HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_OFFS                                                                (0x500)
#define HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_RMSK                                                                0xffffffff
#define HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_IN(x)            \
                in_dword(HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_ADDR(x))
#define HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_INM(x, m)            \
                in_dword_masked(HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_ADDR(x), m)
#define HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_OUT(x, v)            \
                out_dword(HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_ADDR(x),v)
#define HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_ADDR(x),m,v,HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_IN(x))
#define HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_BMSK                                   0xffffffff
#define HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_PWR_CTRL_SLEEP_TMR_CMP_VAL_0_SHFT                                            0

#define HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_ADDR(x)                                                             ((x) + 0x504)
#define HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_PHYS(x)                                                             ((x) + 0x504)
#define HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_OFFS                                                                (0x504)
#define HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_RMSK                                                                0xffffffff
#define HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_IN(x)            \
                in_dword(HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_ADDR(x))
#define HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_INM(x, m)            \
                in_dword_masked(HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_ADDR(x), m)
#define HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_OUT(x, v)            \
                out_dword(HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_ADDR(x),v)
#define HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_ADDR(x),m,v,HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_IN(x))
#define HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_PWR_CTRL_SLEEP_TMR_CMP_EN_BMSK                                      0x80000000
#define HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_PWR_CTRL_SLEEP_TMR_CMP_EN_SHFT                                              31
#define HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_RSVD_BMSK                              0x7f000000
#define HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_RSVD_SHFT                                      24
#define HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_BMSK                                     0xffffff
#define HWIO_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_PWR_CTRL_SLEEP_TMR_CMP_VAL_1_SHFT                                            0

#define HWIO_PC_DEBUG_BUS_CX_EN_ADDR(x)                                                                       ((x) + 0x508)
#define HWIO_PC_DEBUG_BUS_CX_EN_PHYS(x)                                                                       ((x) + 0x508)
#define HWIO_PC_DEBUG_BUS_CX_EN_OFFS                                                                          (0x508)
#define HWIO_PC_DEBUG_BUS_CX_EN_RMSK                                                                               0x1ff
#define HWIO_PC_DEBUG_BUS_CX_EN_IN(x)            \
                in_dword(HWIO_PC_DEBUG_BUS_CX_EN_ADDR(x))
#define HWIO_PC_DEBUG_BUS_CX_EN_INM(x, m)            \
                in_dword_masked(HWIO_PC_DEBUG_BUS_CX_EN_ADDR(x), m)
#define HWIO_PC_DEBUG_BUS_CX_EN_OUT(x, v)            \
                out_dword(HWIO_PC_DEBUG_BUS_CX_EN_ADDR(x),v)
#define HWIO_PC_DEBUG_BUS_CX_EN_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_PC_DEBUG_BUS_CX_EN_ADDR(x),m,v,HWIO_PC_DEBUG_BUS_CX_EN_IN(x))
#define HWIO_PC_DEBUG_BUS_CX_EN_PC_DEBUG_BUS_CX_EN_BMSK                                                            0x1ff
#define HWIO_PC_DEBUG_BUS_CX_EN_PC_DEBUG_BUS_CX_EN_SHFT                                                                0

#define HWIO_PC_DEBUG_BUS_MX_EN_ADDR(x)                                                                       ((x) + 0x50c)
#define HWIO_PC_DEBUG_BUS_MX_EN_PHYS(x)                                                                       ((x) + 0x50c)
#define HWIO_PC_DEBUG_BUS_MX_EN_OFFS                                                                          (0x50c)
#define HWIO_PC_DEBUG_BUS_MX_EN_RMSK                                                                          0xffffffff
#define HWIO_PC_DEBUG_BUS_MX_EN_IN(x)            \
                in_dword(HWIO_PC_DEBUG_BUS_MX_EN_ADDR(x))
#define HWIO_PC_DEBUG_BUS_MX_EN_INM(x, m)            \
                in_dword_masked(HWIO_PC_DEBUG_BUS_MX_EN_ADDR(x), m)
#define HWIO_PC_DEBUG_BUS_MX_EN_OUT(x, v)            \
                out_dword(HWIO_PC_DEBUG_BUS_MX_EN_ADDR(x),v)
#define HWIO_PC_DEBUG_BUS_MX_EN_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_PC_DEBUG_BUS_MX_EN_ADDR(x),m,v,HWIO_PC_DEBUG_BUS_MX_EN_IN(x))
#define HWIO_PC_DEBUG_BUS_MX_EN_PC_DEBUG_BUS_MX_EN_BMSK                                                       0xffffffff
#define HWIO_PC_DEBUG_BUS_MX_EN_PC_DEBUG_BUS_MX_EN_SHFT                                                                0

#define HWIO_PC_HW_EVENTS_MX_EN_ADDR(x)                                                                       ((x) + 0x510)
#define HWIO_PC_HW_EVENTS_MX_EN_PHYS(x)                                                                       ((x) + 0x510)
#define HWIO_PC_HW_EVENTS_MX_EN_OFFS                                                                          (0x510)
#define HWIO_PC_HW_EVENTS_MX_EN_RMSK                                                                             0x3ffff
#define HWIO_PC_HW_EVENTS_MX_EN_IN(x)            \
                in_dword(HWIO_PC_HW_EVENTS_MX_EN_ADDR(x))
#define HWIO_PC_HW_EVENTS_MX_EN_INM(x, m)            \
                in_dword_masked(HWIO_PC_HW_EVENTS_MX_EN_ADDR(x), m)
#define HWIO_PC_HW_EVENTS_MX_EN_OUT(x, v)            \
                out_dword(HWIO_PC_HW_EVENTS_MX_EN_ADDR(x),v)
#define HWIO_PC_HW_EVENTS_MX_EN_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_PC_HW_EVENTS_MX_EN_ADDR(x),m,v,HWIO_PC_HW_EVENTS_MX_EN_IN(x))
#define HWIO_PC_HW_EVENTS_MX_EN_PC_HW_EVENTS_MX_EN_BMSK                                                          0x3ffff
#define HWIO_PC_HW_EVENTS_MX_EN_PC_HW_EVENTS_MX_EN_SHFT                                                                0

#define HWIO_DEBUG_BUS_MX_MASTER_EN_ADDR(x)                                                                   ((x) + 0x514)
#define HWIO_DEBUG_BUS_MX_MASTER_EN_PHYS(x)                                                                   ((x) + 0x514)
#define HWIO_DEBUG_BUS_MX_MASTER_EN_OFFS                                                                      (0x514)
#define HWIO_DEBUG_BUS_MX_MASTER_EN_RMSK                                                                             0x3
#define HWIO_DEBUG_BUS_MX_MASTER_EN_IN(x)            \
                in_dword(HWIO_DEBUG_BUS_MX_MASTER_EN_ADDR(x))
#define HWIO_DEBUG_BUS_MX_MASTER_EN_INM(x, m)            \
                in_dword_masked(HWIO_DEBUG_BUS_MX_MASTER_EN_ADDR(x), m)
#define HWIO_DEBUG_BUS_MX_MASTER_EN_OUT(x, v)            \
                out_dword(HWIO_DEBUG_BUS_MX_MASTER_EN_ADDR(x),v)
#define HWIO_DEBUG_BUS_MX_MASTER_EN_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_DEBUG_BUS_MX_MASTER_EN_ADDR(x),m,v,HWIO_DEBUG_BUS_MX_MASTER_EN_IN(x))
#define HWIO_DEBUG_BUS_MX_MASTER_EN_PC_DEBUG_BUS_MX_MASTER_EN_BMSK                                                   0x2
#define HWIO_DEBUG_BUS_MX_MASTER_EN_PC_DEBUG_BUS_MX_MASTER_EN_SHFT                                                     1
#define HWIO_DEBUG_BUS_MX_MASTER_EN_ISD_DEBUG_BUS_MX_MASTER_EN_BMSK                                                  0x1
#define HWIO_DEBUG_BUS_MX_MASTER_EN_ISD_DEBUG_BUS_MX_MASTER_EN_SHFT                                                    0

#define HWIO_CXO_PAD_EN_ADDR(x)                                                                               ((x) + 0x518)
#define HWIO_CXO_PAD_EN_PHYS(x)                                                                               ((x) + 0x518)
#define HWIO_CXO_PAD_EN_OFFS                                                                                  (0x518)
#define HWIO_CXO_PAD_EN_RMSK                                                                                         0x1
#define HWIO_CXO_PAD_EN_IN(x)            \
                in_dword(HWIO_CXO_PAD_EN_ADDR(x))
#define HWIO_CXO_PAD_EN_INM(x, m)            \
                in_dword_masked(HWIO_CXO_PAD_EN_ADDR(x), m)
#define HWIO_CXO_PAD_EN_OUT(x, v)            \
                out_dword(HWIO_CXO_PAD_EN_ADDR(x),v)
#define HWIO_CXO_PAD_EN_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_CXO_PAD_EN_ADDR(x),m,v,HWIO_CXO_PAD_EN_IN(x))
#define HWIO_CXO_PAD_EN_HVM_CXO_PAD_EN_BMSK                                                                          0x1
#define HWIO_CXO_PAD_EN_HVM_CXO_PAD_EN_SHFT                                                                            0

#define HWIO_CXO_PAD_EN_STATUS_ADDR(x)                                                                        ((x) + 0x51c)
#define HWIO_CXO_PAD_EN_STATUS_PHYS(x)                                                                        ((x) + 0x51c)
#define HWIO_CXO_PAD_EN_STATUS_OFFS                                                                           (0x51c)
#define HWIO_CXO_PAD_EN_STATUS_RMSK                                                                                  0x1
#define HWIO_CXO_PAD_EN_STATUS_IN(x)            \
                in_dword(HWIO_CXO_PAD_EN_STATUS_ADDR(x))
#define HWIO_CXO_PAD_EN_STATUS_INM(x, m)            \
                in_dword_masked(HWIO_CXO_PAD_EN_STATUS_ADDR(x), m)
#define HWIO_CXO_PAD_EN_STATUS_HVM_CXO_PAD_EN_BMSK                                                                   0x1
#define HWIO_CXO_PAD_EN_STATUS_HVM_CXO_PAD_EN_SHFT                                                                     0

#define HWIO_MD_PS_HOLD_PAD_CONTROL_ADDR(x)                                                                   ((x) + 0x520)
#define HWIO_MD_PS_HOLD_PAD_CONTROL_PHYS(x)                                                                   ((x) + 0x520)
#define HWIO_MD_PS_HOLD_PAD_CONTROL_OFFS                                                                      (0x520)
#define HWIO_MD_PS_HOLD_PAD_CONTROL_RMSK                                                                            0x7f
#define HWIO_MD_PS_HOLD_PAD_CONTROL_IN(x)            \
                in_dword(HWIO_MD_PS_HOLD_PAD_CONTROL_ADDR(x))
#define HWIO_MD_PS_HOLD_PAD_CONTROL_INM(x, m)            \
                in_dword_masked(HWIO_MD_PS_HOLD_PAD_CONTROL_ADDR(x), m)
#define HWIO_MD_PS_HOLD_PAD_CONTROL_OUT(x, v)            \
                out_dword(HWIO_MD_PS_HOLD_PAD_CONTROL_ADDR(x),v)
#define HWIO_MD_PS_HOLD_PAD_CONTROL_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_MD_PS_HOLD_PAD_CONTROL_ADDR(x),m,v,HWIO_MD_PS_HOLD_PAD_CONTROL_IN(x))
#define HWIO_MD_PS_HOLD_PAD_CONTROL_MD_PS_HOLD_PULL_BMSK                                                            0x60
#define HWIO_MD_PS_HOLD_PAD_CONTROL_MD_PS_HOLD_PULL_SHFT                                                               5
#define HWIO_MD_PS_HOLD_PAD_CONTROL_MD_PS_HOLD_HDRIVE_BMSK                                                          0x1c
#define HWIO_MD_PS_HOLD_PAD_CONTROL_MD_PS_HOLD_HDRIVE_SHFT                                                             2
#define HWIO_MD_PS_HOLD_PAD_CONTROL_MD_PS_HOLD_OE_BMSK                                                               0x2
#define HWIO_MD_PS_HOLD_PAD_CONTROL_MD_PS_HOLD_OE_SHFT                                                                 1
#define HWIO_MD_PS_HOLD_PAD_CONTROL_MD_PS_HOLD_IE_BMSK                                                               0x1
#define HWIO_MD_PS_HOLD_PAD_CONTROL_MD_PS_HOLD_IE_SHFT                                                                 0

#define HWIO_SAIL_PS_HOLD_PAD_CONTROL_ADDR(x)                                                                 ((x) + 0x524)
#define HWIO_SAIL_PS_HOLD_PAD_CONTROL_PHYS(x)                                                                 ((x) + 0x524)
#define HWIO_SAIL_PS_HOLD_PAD_CONTROL_OFFS                                                                    (0x524)
#define HWIO_SAIL_PS_HOLD_PAD_CONTROL_RMSK                                                                          0x7f
#define HWIO_SAIL_PS_HOLD_PAD_CONTROL_IN(x)            \
                in_dword(HWIO_SAIL_PS_HOLD_PAD_CONTROL_ADDR(x))
#define HWIO_SAIL_PS_HOLD_PAD_CONTROL_INM(x, m)            \
                in_dword_masked(HWIO_SAIL_PS_HOLD_PAD_CONTROL_ADDR(x), m)
#define HWIO_SAIL_PS_HOLD_PAD_CONTROL_OUT(x, v)            \
                out_dword(HWIO_SAIL_PS_HOLD_PAD_CONTROL_ADDR(x),v)
#define HWIO_SAIL_PS_HOLD_PAD_CONTROL_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_SAIL_PS_HOLD_PAD_CONTROL_ADDR(x),m,v,HWIO_SAIL_PS_HOLD_PAD_CONTROL_IN(x))
#define HWIO_SAIL_PS_HOLD_PAD_CONTROL_SAIL_PS_HOLD_PULL_BMSK                                                        0x60
#define HWIO_SAIL_PS_HOLD_PAD_CONTROL_SAIL_PS_HOLD_PULL_SHFT                                                           5
#define HWIO_SAIL_PS_HOLD_PAD_CONTROL_SAIL_PS_HOLD_HDRIVE_BMSK                                                      0x1c
#define HWIO_SAIL_PS_HOLD_PAD_CONTROL_SAIL_PS_HOLD_HDRIVE_SHFT                                                         2
#define HWIO_SAIL_PS_HOLD_PAD_CONTROL_SAIL_PS_HOLD_OE_BMSK                                                           0x2
#define HWIO_SAIL_PS_HOLD_PAD_CONTROL_SAIL_PS_HOLD_OE_SHFT                                                             1
#define HWIO_SAIL_PS_HOLD_PAD_CONTROL_SAIL_PS_HOLD_IE_BMSK                                                           0x1
#define HWIO_SAIL_PS_HOLD_PAD_CONTROL_SAIL_PS_HOLD_IE_SHFT                                                             0

#define HWIO_SAIL_SLEEP_EN_PAD_CONTROL_ADDR(x)                                                                ((x) + 0x528)
#define HWIO_SAIL_SLEEP_EN_PAD_CONTROL_PHYS(x)                                                                ((x) + 0x528)
#define HWIO_SAIL_SLEEP_EN_PAD_CONTROL_OFFS                                                                   (0x528)
#define HWIO_SAIL_SLEEP_EN_PAD_CONTROL_RMSK                                                                         0x7f
#define HWIO_SAIL_SLEEP_EN_PAD_CONTROL_IN(x)            \
                in_dword(HWIO_SAIL_SLEEP_EN_PAD_CONTROL_ADDR(x))
#define HWIO_SAIL_SLEEP_EN_PAD_CONTROL_INM(x, m)            \
                in_dword_masked(HWIO_SAIL_SLEEP_EN_PAD_CONTROL_ADDR(x), m)
#define HWIO_SAIL_SLEEP_EN_PAD_CONTROL_OUT(x, v)            \
                out_dword(HWIO_SAIL_SLEEP_EN_PAD_CONTROL_ADDR(x),v)
#define HWIO_SAIL_SLEEP_EN_PAD_CONTROL_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_SAIL_SLEEP_EN_PAD_CONTROL_ADDR(x),m,v,HWIO_SAIL_SLEEP_EN_PAD_CONTROL_IN(x))
#define HWIO_SAIL_SLEEP_EN_PAD_CONTROL_SAIL_SLEEP_EN_PULL_BMSK                                                      0x60
#define HWIO_SAIL_SLEEP_EN_PAD_CONTROL_SAIL_SLEEP_EN_PULL_SHFT                                                         5
#define HWIO_SAIL_SLEEP_EN_PAD_CONTROL_SAIL_SLEEP_EN_HDRIVE_BMSK                                                    0x1c
#define HWIO_SAIL_SLEEP_EN_PAD_CONTROL_SAIL_SLEEP_EN_HDRIVE_SHFT                                                       2
#define HWIO_SAIL_SLEEP_EN_PAD_CONTROL_SAIL_SLEEP_EN_OE_BMSK                                                         0x2
#define HWIO_SAIL_SLEEP_EN_PAD_CONTROL_SAIL_SLEEP_EN_OE_SHFT                                                           1
#define HWIO_SAIL_SLEEP_EN_PAD_CONTROL_SAIL_SLEEP_EN_IE_BMSK                                                         0x1
#define HWIO_SAIL_SLEEP_EN_PAD_CONTROL_SAIL_SLEEP_EN_IE_SHFT                                                           0

#define HWIO_PWR_CTRL_SPARE_REG_0_ADDR(x)                                                                     ((x) + 0x600)
#define HWIO_PWR_CTRL_SPARE_REG_0_PHYS(x)                                                                     ((x) + 0x600)
#define HWIO_PWR_CTRL_SPARE_REG_0_OFFS                                                                        (0x600)
#define HWIO_PWR_CTRL_SPARE_REG_0_RMSK                                                                        0xffffffff
#define HWIO_PWR_CTRL_SPARE_REG_0_IN(x)            \
                in_dword(HWIO_PWR_CTRL_SPARE_REG_0_ADDR(x))
#define HWIO_PWR_CTRL_SPARE_REG_0_INM(x, m)            \
                in_dword_masked(HWIO_PWR_CTRL_SPARE_REG_0_ADDR(x), m)
#define HWIO_PWR_CTRL_SPARE_REG_0_OUT(x, v)            \
                out_dword(HWIO_PWR_CTRL_SPARE_REG_0_ADDR(x),v)
#define HWIO_PWR_CTRL_SPARE_REG_0_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_PWR_CTRL_SPARE_REG_0_ADDR(x),m,v,HWIO_PWR_CTRL_SPARE_REG_0_IN(x))
#define HWIO_PWR_CTRL_SPARE_REG_0_PWR_CTRL_SPARE_REG_BMSK                                                     0xffffffff
#define HWIO_PWR_CTRL_SPARE_REG_0_PWR_CTRL_SPARE_REG_SHFT                                                              0

#define HWIO_PWR_CTRL_SPARE_REG_1_ADDR(x)                                                                     ((x) + 0x604)
#define HWIO_PWR_CTRL_SPARE_REG_1_PHYS(x)                                                                     ((x) + 0x604)
#define HWIO_PWR_CTRL_SPARE_REG_1_OFFS                                                                        (0x604)
#define HWIO_PWR_CTRL_SPARE_REG_1_RMSK                                                                        0xffffffff
#define HWIO_PWR_CTRL_SPARE_REG_1_IN(x)            \
                in_dword(HWIO_PWR_CTRL_SPARE_REG_1_ADDR(x))
#define HWIO_PWR_CTRL_SPARE_REG_1_INM(x, m)            \
                in_dword_masked(HWIO_PWR_CTRL_SPARE_REG_1_ADDR(x), m)
#define HWIO_PWR_CTRL_SPARE_REG_1_OUT(x, v)            \
                out_dword(HWIO_PWR_CTRL_SPARE_REG_1_ADDR(x),v)
#define HWIO_PWR_CTRL_SPARE_REG_1_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_PWR_CTRL_SPARE_REG_1_ADDR(x),m,v,HWIO_PWR_CTRL_SPARE_REG_1_IN(x))
#define HWIO_PWR_CTRL_SPARE_REG_1_PWR_CTRL_SPARE_REG_BMSK                                                     0xffffffff
#define HWIO_PWR_CTRL_SPARE_REG_1_PWR_CTRL_SPARE_REG_SHFT                                                              0

#define HWIO_FUSA_STATUS_REGISTER_ADDR(x)                                                                     ((x) + 0xf50)
#define HWIO_FUSA_STATUS_REGISTER_PHYS(x)                                                                     ((x) + 0xf50)
#define HWIO_FUSA_STATUS_REGISTER_OFFS                                                                        (0xf50)
#define HWIO_FUSA_STATUS_REGISTER_RMSK                                                                            0x1fff
#define HWIO_FUSA_STATUS_REGISTER_IN(x)            \
                in_dword(HWIO_FUSA_STATUS_REGISTER_ADDR(x))
#define HWIO_FUSA_STATUS_REGISTER_INM(x, m)            \
                in_dword_masked(HWIO_FUSA_STATUS_REGISTER_ADDR(x), m)
#define HWIO_FUSA_STATUS_REGISTER_HPCNT_BMSK                                                                      0x1f80
#define HWIO_FUSA_STATUS_REGISTER_HPCNT_SHFT                                                                           7
#define HWIO_FUSA_STATUS_REGISTER_VPCNT_BMSK                                                                        0x7e
#define HWIO_FUSA_STATUS_REGISTER_VPCNT_SHFT                                                                           1
#define HWIO_FUSA_STATUS_REGISTER_FLT_BMSK                                                                           0x1
#define HWIO_FUSA_STATUS_REGISTER_FLT_SHFT                                                                             0

#define HWIO_PWR_SEQ_CONFIG_0_ADDR(x)                                                                         ((x) + 0x1000)
#define HWIO_PWR_SEQ_CONFIG_0_PHYS(x)                                                                         ((x) + 0x1000)
#define HWIO_PWR_SEQ_CONFIG_0_OFFS                                                                            (0x1000)
#define HWIO_PWR_SEQ_CONFIG_0_RMSK                                                                                   0x3
#define HWIO_PWR_SEQ_CONFIG_0_IN(x)            \
                in_dword(HWIO_PWR_SEQ_CONFIG_0_ADDR(x))
#define HWIO_PWR_SEQ_CONFIG_0_INM(x, m)            \
                in_dword_masked(HWIO_PWR_SEQ_CONFIG_0_ADDR(x), m)
#define HWIO_PWR_SEQ_CONFIG_0_OUT(x, v)            \
                out_dword(HWIO_PWR_SEQ_CONFIG_0_ADDR(x),v)
#define HWIO_PWR_SEQ_CONFIG_0_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_PWR_SEQ_CONFIG_0_ADDR(x),m,v,HWIO_PWR_SEQ_CONFIG_0_IN(x))
#define HWIO_PWR_SEQ_CONFIG_0_DISABLE_DEBUG_CSR_UPDATE_BMSK                                                          0x2
#define HWIO_PWR_SEQ_CONFIG_0_DISABLE_DEBUG_CSR_UPDATE_SHFT                                                            1
#define HWIO_PWR_SEQ_CONFIG_0_FORCE_CLK_EN_BMSK                                                                      0x1
#define HWIO_PWR_SEQ_CONFIG_0_FORCE_CLK_EN_SHFT                                                                        0

#define HWIO_PWR_SEQ_PARAM_SEQ_CONFIG_ADDR(x)                                                                 ((x) + 0x1004)
#define HWIO_PWR_SEQ_PARAM_SEQ_CONFIG_PHYS(x)                                                                 ((x) + 0x1004)
#define HWIO_PWR_SEQ_PARAM_SEQ_CONFIG_OFFS                                                                    (0x1004)
#define HWIO_PWR_SEQ_PARAM_SEQ_CONFIG_RMSK                                                                         0x3ff
#define HWIO_PWR_SEQ_PARAM_SEQ_CONFIG_IN(x)            \
                in_dword(HWIO_PWR_SEQ_PARAM_SEQ_CONFIG_ADDR(x))
#define HWIO_PWR_SEQ_PARAM_SEQ_CONFIG_INM(x, m)            \
                in_dword_masked(HWIO_PWR_SEQ_PARAM_SEQ_CONFIG_ADDR(x), m)
#define HWIO_PWR_SEQ_PARAM_SEQ_CONFIG_NUM_SEQ_CMD_WORDS_BMSK                                                       0x3ff
#define HWIO_PWR_SEQ_PARAM_SEQ_CONFIG_NUM_SEQ_CMD_WORDS_SHFT                                                           0

#define HWIO_PWR_SEQ_BUSY_ADDR(x)                                                                             ((x) + 0x1008)
#define HWIO_PWR_SEQ_BUSY_PHYS(x)                                                                             ((x) + 0x1008)
#define HWIO_PWR_SEQ_BUSY_OFFS                                                                                (0x1008)
#define HWIO_PWR_SEQ_BUSY_RMSK                                                                                       0x1
#define HWIO_PWR_SEQ_BUSY_IN(x)            \
                in_dword(HWIO_PWR_SEQ_BUSY_ADDR(x))
#define HWIO_PWR_SEQ_BUSY_INM(x, m)            \
                in_dword_masked(HWIO_PWR_SEQ_BUSY_ADDR(x), m)
#define HWIO_PWR_SEQ_BUSY_BUSY_STAT_BMSK                                                                             0x1
#define HWIO_PWR_SEQ_BUSY_BUSY_STAT_SHFT                                                                               0

#define HWIO_PWR_SEQ_DBG_PROGRAM_COUNTER_ADDR(x)                                                              ((x) + 0x100c)
#define HWIO_PWR_SEQ_DBG_PROGRAM_COUNTER_PHYS(x)                                                              ((x) + 0x100c)
#define HWIO_PWR_SEQ_DBG_PROGRAM_COUNTER_OFFS                                                                 (0x100c)
#define HWIO_PWR_SEQ_DBG_PROGRAM_COUNTER_RMSK                                                                      0x3ff
#define HWIO_PWR_SEQ_DBG_PROGRAM_COUNTER_IN(x)            \
                in_dword(HWIO_PWR_SEQ_DBG_PROGRAM_COUNTER_ADDR(x))
#define HWIO_PWR_SEQ_DBG_PROGRAM_COUNTER_INM(x, m)            \
                in_dword_masked(HWIO_PWR_SEQ_DBG_PROGRAM_COUNTER_ADDR(x), m)
#define HWIO_PWR_SEQ_DBG_PROGRAM_COUNTER_CURRENT_INSTR_ADDR_BMSK                                                   0x3ff
#define HWIO_PWR_SEQ_DBG_PROGRAM_COUNTER_CURRENT_INSTR_ADDR_SHFT                                                       0

#define HWIO_PWR_SEQ_DBG_STAT_ADDR(x)                                                                         ((x) + 0x1010)
#define HWIO_PWR_SEQ_DBG_STAT_PHYS(x)                                                                         ((x) + 0x1010)
#define HWIO_PWR_SEQ_DBG_STAT_OFFS                                                                            (0x1010)
#define HWIO_PWR_SEQ_DBG_STAT_RMSK                                                                                   0x1
#define HWIO_PWR_SEQ_DBG_STAT_IN(x)            \
                in_dword(HWIO_PWR_SEQ_DBG_STAT_ADDR(x))
#define HWIO_PWR_SEQ_DBG_STAT_INM(x, m)            \
                in_dword_masked(HWIO_PWR_SEQ_DBG_STAT_ADDR(x), m)
#define HWIO_PWR_SEQ_DBG_STAT_DBG_STEPPING_STATUS_BMSK                                                               0x1
#define HWIO_PWR_SEQ_DBG_STAT_DBG_STEPPING_STATUS_SHFT                                                                 0

#define HWIO_PWR_SEQ_START_ADDR_ADDR(x)                                                                       ((x) + 0x1014)
#define HWIO_PWR_SEQ_START_ADDR_PHYS(x)                                                                       ((x) + 0x1014)
#define HWIO_PWR_SEQ_START_ADDR_OFFS                                                                          (0x1014)
#define HWIO_PWR_SEQ_START_ADDR_RMSK                                                                               0x3ff
#define HWIO_PWR_SEQ_START_ADDR_IN(x)            \
                in_dword(HWIO_PWR_SEQ_START_ADDR_ADDR(x))
#define HWIO_PWR_SEQ_START_ADDR_INM(x, m)            \
                in_dword_masked(HWIO_PWR_SEQ_START_ADDR_ADDR(x), m)
#define HWIO_PWR_SEQ_START_ADDR_OUT(x, v)            \
                out_dword(HWIO_PWR_SEQ_START_ADDR_ADDR(x),v)
#define HWIO_PWR_SEQ_START_ADDR_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_PWR_SEQ_START_ADDR_ADDR(x),m,v,HWIO_PWR_SEQ_START_ADDR_IN(x))
#define HWIO_PWR_SEQ_START_ADDR_SEQ_START_ADDR_BMSK                                                                0x3ff
#define HWIO_PWR_SEQ_START_ADDR_SEQ_START_ADDR_SHFT                                                                    0

#define HWIO_PWR_SEQ_OVERRIDE_START_ADDR_ADDR(x)                                                              ((x) + 0x1018)
#define HWIO_PWR_SEQ_OVERRIDE_START_ADDR_PHYS(x)                                                              ((x) + 0x1018)
#define HWIO_PWR_SEQ_OVERRIDE_START_ADDR_OFFS                                                                 (0x1018)
#define HWIO_PWR_SEQ_OVERRIDE_START_ADDR_RMSK                                                                 0x800003ff
#define HWIO_PWR_SEQ_OVERRIDE_START_ADDR_IN(x)            \
                in_dword(HWIO_PWR_SEQ_OVERRIDE_START_ADDR_ADDR(x))
#define HWIO_PWR_SEQ_OVERRIDE_START_ADDR_INM(x, m)            \
                in_dword_masked(HWIO_PWR_SEQ_OVERRIDE_START_ADDR_ADDR(x), m)
#define HWIO_PWR_SEQ_OVERRIDE_START_ADDR_OUT(x, v)            \
                out_dword(HWIO_PWR_SEQ_OVERRIDE_START_ADDR_ADDR(x),v)
#define HWIO_PWR_SEQ_OVERRIDE_START_ADDR_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_PWR_SEQ_OVERRIDE_START_ADDR_ADDR(x),m,v,HWIO_PWR_SEQ_OVERRIDE_START_ADDR_IN(x))
#define HWIO_PWR_SEQ_OVERRIDE_START_ADDR_SEQ_OVERRIDE_VALID_BMSK                                              0x80000000
#define HWIO_PWR_SEQ_OVERRIDE_START_ADDR_SEQ_OVERRIDE_VALID_SHFT                                                      31
#define HWIO_PWR_SEQ_OVERRIDE_START_ADDR_SEQ_OVERRIDE_START_ADDR_BMSK                                              0x3ff
#define HWIO_PWR_SEQ_OVERRIDE_START_ADDR_SEQ_OVERRIDE_START_ADDR_SHFT                                                  0

#define HWIO_PWR_SEQ_OVERRIDE_TRIGGER_ADDR(x)                                                                 ((x) + 0x101c)
#define HWIO_PWR_SEQ_OVERRIDE_TRIGGER_PHYS(x)                                                                 ((x) + 0x101c)
#define HWIO_PWR_SEQ_OVERRIDE_TRIGGER_OFFS                                                                    (0x101c)
#define HWIO_PWR_SEQ_OVERRIDE_TRIGGER_RMSK                                                                           0x3
#define HWIO_PWR_SEQ_OVERRIDE_TRIGGER_IN(x)            \
                in_dword(HWIO_PWR_SEQ_OVERRIDE_TRIGGER_ADDR(x))
#define HWIO_PWR_SEQ_OVERRIDE_TRIGGER_INM(x, m)            \
                in_dword_masked(HWIO_PWR_SEQ_OVERRIDE_TRIGGER_ADDR(x), m)
#define HWIO_PWR_SEQ_OVERRIDE_TRIGGER_OUT(x, v)            \
                out_dword(HWIO_PWR_SEQ_OVERRIDE_TRIGGER_ADDR(x),v)
#define HWIO_PWR_SEQ_OVERRIDE_TRIGGER_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_PWR_SEQ_OVERRIDE_TRIGGER_ADDR(x),m,v,HWIO_PWR_SEQ_OVERRIDE_TRIGGER_IN(x))
#define HWIO_PWR_SEQ_OVERRIDE_TRIGGER_CRASH_SEQ_OVERRIDE_TRIGGER_BMSK                                                0x2
#define HWIO_PWR_SEQ_OVERRIDE_TRIGGER_CRASH_SEQ_OVERRIDE_TRIGGER_SHFT                                                  1
#define HWIO_PWR_SEQ_OVERRIDE_TRIGGER_CRASH_SEQ_OVERRIDE_TRIGGER_CRASH_SEQ_SW_OVERRIDE_NO_TRIGGER_FVAL               0x0
#define HWIO_PWR_SEQ_OVERRIDE_TRIGGER_CRASH_SEQ_OVERRIDE_TRIGGER_CRASH_SEQ_SW_OVERRIDE_TRIGGER_FVAL                  0x1
#define HWIO_PWR_SEQ_OVERRIDE_TRIGGER_SEQ_OVERRIDE_TRIGGER_BMSK                                                      0x1
#define HWIO_PWR_SEQ_OVERRIDE_TRIGGER_SEQ_OVERRIDE_TRIGGER_SHFT                                                        0
#define HWIO_PWR_SEQ_OVERRIDE_TRIGGER_SEQ_OVERRIDE_TRIGGER_SEQ_SW_OVERRIDE_NO_TRIGGER_FVAL                           0x0
#define HWIO_PWR_SEQ_OVERRIDE_TRIGGER_SEQ_OVERRIDE_TRIGGER_SEQ_SW_OVERRIDE_TRIGGER_FVAL                              0x1

#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0_ADDR(x)                                                         ((x) + 0x1020)
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0_PHYS(x)                                                         ((x) + 0x1020)
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0_OFFS                                                            (0x1020)
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0_RMSK                                                            0xffffffff
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0_IN(x)            \
                in_dword(HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0_ADDR(x))
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0_INM(x, m)            \
                in_dword_masked(HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0_ADDR(x), m)
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0_OUT(x, v)            \
                out_dword(HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0_ADDR(x),v)
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0_ADDR(x),m,v,HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0_IN(x))
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0_PWR_CTRL_OVERRIDE_MASK_BMSK                                     0xffffffff
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_0_PWR_CTRL_OVERRIDE_MASK_SHFT                                              0

#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0_ADDR(x)                                                          ((x) + 0x1024)
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0_PHYS(x)                                                          ((x) + 0x1024)
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0_OFFS                                                             (0x1024)
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0_RMSK                                                             0xffffffff
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0_IN(x)            \
                in_dword(HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0_ADDR(x))
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0_INM(x, m)            \
                in_dword_masked(HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0_ADDR(x), m)
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0_OUT(x, v)            \
                out_dword(HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0_ADDR(x),v)
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0_ADDR(x),m,v,HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0_IN(x))
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0_PWR_CTRL_OVERRIDE_VAL_BMSK                                       0xffffffff
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_0_PWR_CTRL_OVERRIDE_VAL_SHFT                                                0

#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_1_ADDR(x)                                                         ((x) + 0x1028)
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_1_PHYS(x)                                                         ((x) + 0x1028)
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_1_OFFS                                                            (0x1028)
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_1_RMSK                                                            0xffffffff
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_1_IN(x)            \
                in_dword(HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_1_ADDR(x))
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_1_INM(x, m)            \
                in_dword_masked(HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_1_ADDR(x), m)
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_1_OUT(x, v)            \
                out_dword(HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_1_ADDR(x),v)
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_1_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_1_ADDR(x),m,v,HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_1_IN(x))
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_1_PWR_CTRL_OVERRIDE_MASK_BMSK                                     0xffffffff
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_MASK_1_PWR_CTRL_OVERRIDE_MASK_SHFT                                              0

#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_1_ADDR(x)                                                          ((x) + 0x102c)
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_1_PHYS(x)                                                          ((x) + 0x102c)
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_1_OFFS                                                             (0x102c)
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_1_RMSK                                                             0xffffffff
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_1_IN(x)            \
                in_dword(HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_1_ADDR(x))
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_1_INM(x, m)            \
                in_dword_masked(HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_1_ADDR(x), m)
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_1_OUT(x, v)            \
                out_dword(HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_1_ADDR(x),v)
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_1_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_1_ADDR(x),m,v,HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_1_IN(x))
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_1_PWR_CTRL_OVERRIDE_VAL_BMSK                                       0xffffffff
#define HWIO_PWR_SEQ_PWR_CTRL_OVERRIDE_VAL_1_PWR_CTRL_OVERRIDE_VAL_SHFT                                                0

#define HWIO_PWR_SEQ_WAIT_EVENT_OVERRIDE_MASK_ADDR(x)                                                         ((x) + 0x1030)
#define HWIO_PWR_SEQ_WAIT_EVENT_OVERRIDE_MASK_PHYS(x)                                                         ((x) + 0x1030)
#define HWIO_PWR_SEQ_WAIT_EVENT_OVERRIDE_MASK_OFFS                                                            (0x1030)
#define HWIO_PWR_SEQ_WAIT_EVENT_OVERRIDE_MASK_RMSK                                                            0xffffffff
#define HWIO_PWR_SEQ_WAIT_EVENT_OVERRIDE_MASK_IN(x)            \
                in_dword(HWIO_PWR_SEQ_WAIT_EVENT_OVERRIDE_MASK_ADDR(x))
#define HWIO_PWR_SEQ_WAIT_EVENT_OVERRIDE_MASK_INM(x, m)            \
                in_dword_masked(HWIO_PWR_SEQ_WAIT_EVENT_OVERRIDE_MASK_ADDR(x), m)
#define HWIO_PWR_SEQ_WAIT_EVENT_OVERRIDE_MASK_OUT(x, v)            \
                out_dword(HWIO_PWR_SEQ_WAIT_EVENT_OVERRIDE_MASK_ADDR(x),v)
#define HWIO_PWR_SEQ_WAIT_EVENT_OVERRIDE_MASK_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_PWR_SEQ_WAIT_EVENT_OVERRIDE_MASK_ADDR(x),m,v,HWIO_PWR_SEQ_WAIT_EVENT_OVERRIDE_MASK_IN(x))
#define HWIO_PWR_SEQ_WAIT_EVENT_OVERRIDE_MASK_WAIT_EVENT_OVERRIDE_MASK_BMSK                                   0xffffffff
#define HWIO_PWR_SEQ_WAIT_EVENT_OVERRIDE_MASK_WAIT_EVENT_OVERRIDE_MASK_SHFT                                            0

#define HWIO_PWR_SEQ_WAIT_EVENT_OVERRIDE_VAL_ADDR(x)                                                          ((x) + 0x1034)
#define HWIO_PWR_SEQ_WAIT_EVENT_OVERRIDE_VAL_PHYS(x)                                                          ((x) + 0x1034)
#define HWIO_PWR_SEQ_WAIT_EVENT_OVERRIDE_VAL_OFFS                                                             (0x1034)
#define HWIO_PWR_SEQ_WAIT_EVENT_OVERRIDE_VAL_RMSK                                                             0xffffffff
#define HWIO_PWR_SEQ_WAIT_EVENT_OVERRIDE_VAL_IN(x)            \
                in_dword(HWIO_PWR_SEQ_WAIT_EVENT_OVERRIDE_VAL_ADDR(x))
#define HWIO_PWR_SEQ_WAIT_EVENT_OVERRIDE_VAL_INM(x, m)            \
                in_dword_masked(HWIO_PWR_SEQ_WAIT_EVENT_OVERRIDE_VAL_ADDR(x), m)
#define HWIO_PWR_SEQ_WAIT_EVENT_OVERRIDE_VAL_OUT(x, v)            \
                out_dword(HWIO_PWR_SEQ_WAIT_EVENT_OVERRIDE_VAL_ADDR(x),v)
#define HWIO_PWR_SEQ_WAIT_EVENT_OVERRIDE_VAL_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_PWR_SEQ_WAIT_EVENT_OVERRIDE_VAL_ADDR(x),m,v,HWIO_PWR_SEQ_WAIT_EVENT_OVERRIDE_VAL_IN(x))
#define HWIO_PWR_SEQ_WAIT_EVENT_OVERRIDE_VAL_WAIT_EVENT_OVERRIDE_VAL_BMSK                                     0xffffffff
#define HWIO_PWR_SEQ_WAIT_EVENT_OVERRIDE_VAL_WAIT_EVENT_OVERRIDE_VAL_SHFT                                              0

#define HWIO_PWR_SEQ_BR_EVENT_CONTROL_ADDR(x)                                                                 ((x) + 0x1038)
#define HWIO_PWR_SEQ_BR_EVENT_CONTROL_PHYS(x)                                                                 ((x) + 0x1038)
#define HWIO_PWR_SEQ_BR_EVENT_CONTROL_OFFS                                                                    (0x1038)
#define HWIO_PWR_SEQ_BR_EVENT_CONTROL_RMSK                                                                           0xf
#define HWIO_PWR_SEQ_BR_EVENT_CONTROL_IN(x)            \
                in_dword(HWIO_PWR_SEQ_BR_EVENT_CONTROL_ADDR(x))
#define HWIO_PWR_SEQ_BR_EVENT_CONTROL_INM(x, m)            \
                in_dword_masked(HWIO_PWR_SEQ_BR_EVENT_CONTROL_ADDR(x), m)
#define HWIO_PWR_SEQ_BR_EVENT_CONTROL_OUT(x, v)            \
                out_dword(HWIO_PWR_SEQ_BR_EVENT_CONTROL_ADDR(x),v)
#define HWIO_PWR_SEQ_BR_EVENT_CONTROL_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_PWR_SEQ_BR_EVENT_CONTROL_ADDR(x),m,v,HWIO_PWR_SEQ_BR_EVENT_CONTROL_IN(x))
#define HWIO_PWR_SEQ_BR_EVENT_CONTROL_MD_WAKE_UP_BMSK                                                                0x8
#define HWIO_PWR_SEQ_BR_EVENT_CONTROL_MD_WAKE_UP_SHFT                                                                  3
#define HWIO_PWR_SEQ_BR_EVENT_CONTROL_SAIL_WAKE_UP_BMSK                                                              0x4
#define HWIO_PWR_SEQ_BR_EVENT_CONTROL_SAIL_WAKE_UP_SHFT                                                                2
#define HWIO_PWR_SEQ_BR_EVENT_CONTROL_SAIL_PMIC_WAKEUP_BMSK                                                          0x2
#define HWIO_PWR_SEQ_BR_EVENT_CONTROL_SAIL_PMIC_WAKEUP_SHFT                                                            1
#define HWIO_PWR_SEQ_BR_EVENT_CONTROL_LOW_POWER_MODE_BMSK                                                            0x1
#define HWIO_PWR_SEQ_BR_EVENT_CONTROL_LOW_POWER_MODE_SHFT                                                              0

#define HWIO_PWR_SEQ_BR_EVENT_OVERRIDE_MASK_ADDR(x)                                                           ((x) + 0x103c)
#define HWIO_PWR_SEQ_BR_EVENT_OVERRIDE_MASK_PHYS(x)                                                           ((x) + 0x103c)
#define HWIO_PWR_SEQ_BR_EVENT_OVERRIDE_MASK_OFFS                                                              (0x103c)
#define HWIO_PWR_SEQ_BR_EVENT_OVERRIDE_MASK_RMSK                                                              0xffffffff
#define HWIO_PWR_SEQ_BR_EVENT_OVERRIDE_MASK_IN(x)            \
                in_dword(HWIO_PWR_SEQ_BR_EVENT_OVERRIDE_MASK_ADDR(x))
#define HWIO_PWR_SEQ_BR_EVENT_OVERRIDE_MASK_INM(x, m)            \
                in_dword_masked(HWIO_PWR_SEQ_BR_EVENT_OVERRIDE_MASK_ADDR(x), m)
#define HWIO_PWR_SEQ_BR_EVENT_OVERRIDE_MASK_OUT(x, v)            \
                out_dword(HWIO_PWR_SEQ_BR_EVENT_OVERRIDE_MASK_ADDR(x),v)
#define HWIO_PWR_SEQ_BR_EVENT_OVERRIDE_MASK_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_PWR_SEQ_BR_EVENT_OVERRIDE_MASK_ADDR(x),m,v,HWIO_PWR_SEQ_BR_EVENT_OVERRIDE_MASK_IN(x))
#define HWIO_PWR_SEQ_BR_EVENT_OVERRIDE_MASK_BR_EVENT_OVERRIDE_MASK_BMSK                                       0xffffffff
#define HWIO_PWR_SEQ_BR_EVENT_OVERRIDE_MASK_BR_EVENT_OVERRIDE_MASK_SHFT                                                0

#define HWIO_PWR_SEQ_BR_EVENT_OVERRIDE_VAL_ADDR(x)                                                            ((x) + 0x1040)
#define HWIO_PWR_SEQ_BR_EVENT_OVERRIDE_VAL_PHYS(x)                                                            ((x) + 0x1040)
#define HWIO_PWR_SEQ_BR_EVENT_OVERRIDE_VAL_OFFS                                                               (0x1040)
#define HWIO_PWR_SEQ_BR_EVENT_OVERRIDE_VAL_RMSK                                                               0xffffffff
#define HWIO_PWR_SEQ_BR_EVENT_OVERRIDE_VAL_IN(x)            \
                in_dword(HWIO_PWR_SEQ_BR_EVENT_OVERRIDE_VAL_ADDR(x))
#define HWIO_PWR_SEQ_BR_EVENT_OVERRIDE_VAL_INM(x, m)            \
                in_dword_masked(HWIO_PWR_SEQ_BR_EVENT_OVERRIDE_VAL_ADDR(x), m)
#define HWIO_PWR_SEQ_BR_EVENT_OVERRIDE_VAL_OUT(x, v)            \
                out_dword(HWIO_PWR_SEQ_BR_EVENT_OVERRIDE_VAL_ADDR(x),v)
#define HWIO_PWR_SEQ_BR_EVENT_OVERRIDE_VAL_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_PWR_SEQ_BR_EVENT_OVERRIDE_VAL_ADDR(x),m,v,HWIO_PWR_SEQ_BR_EVENT_OVERRIDE_VAL_IN(x))
#define HWIO_PWR_SEQ_BR_EVENT_OVERRIDE_VAL_BR_EVENT_OVERRIDE_VAL_BMSK                                         0xffffffff
#define HWIO_PWR_SEQ_BR_EVENT_OVERRIDE_VAL_BR_EVENT_OVERRIDE_VAL_SHFT                                                  0

#define HWIO_PWR_SEQ_CONFIG_BR_ADDR_b_ADDR(base,b)                                                            ((base) + 0X1050 + (0x4*(b)))
#define HWIO_PWR_SEQ_CONFIG_BR_ADDR_b_PHYS(base,b)                                                            ((base) + 0X1050 + (0x4*(b)))
#define HWIO_PWR_SEQ_CONFIG_BR_ADDR_b_OFFS(b)                                                                 (0X1050 + (0x4*(b)))
#define HWIO_PWR_SEQ_CONFIG_BR_ADDR_b_RMSK                                                                         0x3ff
#define HWIO_PWR_SEQ_CONFIG_BR_ADDR_b_MAXb                                                                            31
#define HWIO_PWR_SEQ_CONFIG_BR_ADDR_b_INI(base,b)                \
                in_dword_masked(HWIO_PWR_SEQ_CONFIG_BR_ADDR_b_ADDR(base,b), HWIO_PWR_SEQ_CONFIG_BR_ADDR_b_RMSK)
#define HWIO_PWR_SEQ_CONFIG_BR_ADDR_b_INMI(base,b,mask)        \
                in_dword_masked(HWIO_PWR_SEQ_CONFIG_BR_ADDR_b_ADDR(base,b), mask)
#define HWIO_PWR_SEQ_CONFIG_BR_ADDR_b_OUTI(base,b,val)        \
                out_dword(HWIO_PWR_SEQ_CONFIG_BR_ADDR_b_ADDR(base,b),val)
#define HWIO_PWR_SEQ_CONFIG_BR_ADDR_b_OUTMI(base,b,mask,val) \
                out_dword_masked_ns(HWIO_PWR_SEQ_CONFIG_BR_ADDR_b_ADDR(base,b),mask,val,HWIO_PWR_SEQ_CONFIG_BR_ADDR_b_INI(base,b))
#define HWIO_PWR_SEQ_CONFIG_BR_ADDR_b_CFG_BR_ADDR_BMSK                                                             0x3ff
#define HWIO_PWR_SEQ_CONFIG_BR_ADDR_b_CFG_BR_ADDR_SHFT                                                                 0

#define HWIO_PWR_SEQ_CONFIG_DELAY_VAL_v_ADDR(base,v)                                                          ((base) + 0X1150 + (0x4*(v)))
#define HWIO_PWR_SEQ_CONFIG_DELAY_VAL_v_PHYS(base,v)                                                          ((base) + 0X1150 + (0x4*(v)))
#define HWIO_PWR_SEQ_CONFIG_DELAY_VAL_v_OFFS(v)                                                               (0X1150 + (0x4*(v)))
#define HWIO_PWR_SEQ_CONFIG_DELAY_VAL_v_RMSK                                                                     0xfffff
#define HWIO_PWR_SEQ_CONFIG_DELAY_VAL_v_MAXv                                                                          15
#define HWIO_PWR_SEQ_CONFIG_DELAY_VAL_v_INI(base,v)                \
                in_dword_masked(HWIO_PWR_SEQ_CONFIG_DELAY_VAL_v_ADDR(base,v), HWIO_PWR_SEQ_CONFIG_DELAY_VAL_v_RMSK)
#define HWIO_PWR_SEQ_CONFIG_DELAY_VAL_v_INMI(base,v,mask)        \
                in_dword_masked(HWIO_PWR_SEQ_CONFIG_DELAY_VAL_v_ADDR(base,v), mask)
#define HWIO_PWR_SEQ_CONFIG_DELAY_VAL_v_OUTI(base,v,val)        \
                out_dword(HWIO_PWR_SEQ_CONFIG_DELAY_VAL_v_ADDR(base,v),val)
#define HWIO_PWR_SEQ_CONFIG_DELAY_VAL_v_OUTMI(base,v,mask,val) \
                out_dword_masked_ns(HWIO_PWR_SEQ_CONFIG_DELAY_VAL_v_ADDR(base,v),mask,val,HWIO_PWR_SEQ_CONFIG_DELAY_VAL_v_INI(base,v))
#define HWIO_PWR_SEQ_CONFIG_DELAY_VAL_v_CFG_DELAY_VAL_BMSK                                                       0xfffff
#define HWIO_PWR_SEQ_CONFIG_DELAY_VAL_v_CFG_DELAY_VAL_SHFT                                                             0

#define HWIO_PWR_SEQ_DBG_BREAKPOINT_ADDR_ADDR(x)                                                              ((x) + 0x1200)
#define HWIO_PWR_SEQ_DBG_BREAKPOINT_ADDR_PHYS(x)                                                              ((x) + 0x1200)
#define HWIO_PWR_SEQ_DBG_BREAKPOINT_ADDR_OFFS                                                                 (0x1200)
#define HWIO_PWR_SEQ_DBG_BREAKPOINT_ADDR_RMSK                                                                 0x800003ff
#define HWIO_PWR_SEQ_DBG_BREAKPOINT_ADDR_IN(x)            \
                in_dword(HWIO_PWR_SEQ_DBG_BREAKPOINT_ADDR_ADDR(x))
#define HWIO_PWR_SEQ_DBG_BREAKPOINT_ADDR_INM(x, m)            \
                in_dword_masked(HWIO_PWR_SEQ_DBG_BREAKPOINT_ADDR_ADDR(x), m)
#define HWIO_PWR_SEQ_DBG_BREAKPOINT_ADDR_OUT(x, v)            \
                out_dword(HWIO_PWR_SEQ_DBG_BREAKPOINT_ADDR_ADDR(x),v)
#define HWIO_PWR_SEQ_DBG_BREAKPOINT_ADDR_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_PWR_SEQ_DBG_BREAKPOINT_ADDR_ADDR(x),m,v,HWIO_PWR_SEQ_DBG_BREAKPOINT_ADDR_IN(x))
#define HWIO_PWR_SEQ_DBG_BREAKPOINT_ADDR_DBG_BREAKPOINT_VALID_BMSK                                            0x80000000
#define HWIO_PWR_SEQ_DBG_BREAKPOINT_ADDR_DBG_BREAKPOINT_VALID_SHFT                                                    31
#define HWIO_PWR_SEQ_DBG_BREAKPOINT_ADDR_DBG_BREAKPOINT_ADDR_BMSK                                                  0x3ff
#define HWIO_PWR_SEQ_DBG_BREAKPOINT_ADDR_DBG_BREAKPOINT_ADDR_SHFT                                                      0

#define HWIO_PWR_SEQ_DBG_STEP_ADDR(x)                                                                         ((x) + 0x1204)
#define HWIO_PWR_SEQ_DBG_STEP_PHYS(x)                                                                         ((x) + 0x1204)
#define HWIO_PWR_SEQ_DBG_STEP_OFFS                                                                            (0x1204)
#define HWIO_PWR_SEQ_DBG_STEP_RMSK                                                                               0x10001
#define HWIO_PWR_SEQ_DBG_STEP_IN(x)            \
                in_dword(HWIO_PWR_SEQ_DBG_STEP_ADDR(x))
#define HWIO_PWR_SEQ_DBG_STEP_INM(x, m)            \
                in_dword_masked(HWIO_PWR_SEQ_DBG_STEP_ADDR(x), m)
#define HWIO_PWR_SEQ_DBG_STEP_OUT(x, v)            \
                out_dword(HWIO_PWR_SEQ_DBG_STEP_ADDR(x),v)
#define HWIO_PWR_SEQ_DBG_STEP_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_PWR_SEQ_DBG_STEP_ADDR(x),m,v,HWIO_PWR_SEQ_DBG_STEP_IN(x))
#define HWIO_PWR_SEQ_DBG_STEP_SEQ_DBG_STEP_TRIGGER_BMSK                                                          0x10000
#define HWIO_PWR_SEQ_DBG_STEP_SEQ_DBG_STEP_TRIGGER_SHFT                                                               16
#define HWIO_PWR_SEQ_DBG_STEP_SEQ_DBG_STEP_CONTINUE_BMSK                                                             0x1
#define HWIO_PWR_SEQ_DBG_STEP_SEQ_DBG_STEP_CONTINUE_SHFT                                                               0

#define HWIO_PWR_SEQ_PWR_CONTROL_0_ADDR(x)                                                                    ((x) + 0x1208)
#define HWIO_PWR_SEQ_PWR_CONTROL_0_PHYS(x)                                                                    ((x) + 0x1208)
#define HWIO_PWR_SEQ_PWR_CONTROL_0_OFFS                                                                       (0x1208)
#define HWIO_PWR_SEQ_PWR_CONTROL_0_RMSK                                                                       0xffffffff
#define HWIO_PWR_SEQ_PWR_CONTROL_0_IN(x)            \
                in_dword(HWIO_PWR_SEQ_PWR_CONTROL_0_ADDR(x))
#define HWIO_PWR_SEQ_PWR_CONTROL_0_INM(x, m)            \
                in_dword_masked(HWIO_PWR_SEQ_PWR_CONTROL_0_ADDR(x), m)
#define HWIO_PWR_SEQ_PWR_CONTROL_0_PWR_SEQ_PWR_CONTROL_0_BMSK                                                 0xffffffff
#define HWIO_PWR_SEQ_PWR_CONTROL_0_PWR_SEQ_PWR_CONTROL_0_SHFT                                                          0

#define HWIO_PWR_SEQ_PWR_CONTROL_1_ADDR(x)                                                                    ((x) + 0x120c)
#define HWIO_PWR_SEQ_PWR_CONTROL_1_PHYS(x)                                                                    ((x) + 0x120c)
#define HWIO_PWR_SEQ_PWR_CONTROL_1_OFFS                                                                       (0x120c)
#define HWIO_PWR_SEQ_PWR_CONTROL_1_RMSK                                                                       0xffffffff
#define HWIO_PWR_SEQ_PWR_CONTROL_1_IN(x)            \
                in_dword(HWIO_PWR_SEQ_PWR_CONTROL_1_ADDR(x))
#define HWIO_PWR_SEQ_PWR_CONTROL_1_INM(x, m)            \
                in_dword_masked(HWIO_PWR_SEQ_PWR_CONTROL_1_ADDR(x), m)
#define HWIO_PWR_SEQ_PWR_CONTROL_1_PWR_SEQ_PWR_CONTROL_1_BMSK                                                 0xffffffff
#define HWIO_PWR_SEQ_PWR_CONTROL_1_PWR_SEQ_PWR_CONTROL_1_SHFT                                                          0

#define HWIO_PWR_SEQ_WAIT_EVENTS_ADDR(x)                                                                      ((x) + 0x1210)
#define HWIO_PWR_SEQ_WAIT_EVENTS_PHYS(x)                                                                      ((x) + 0x1210)
#define HWIO_PWR_SEQ_WAIT_EVENTS_OFFS                                                                         (0x1210)
#define HWIO_PWR_SEQ_WAIT_EVENTS_RMSK                                                                         0xffffffff
#define HWIO_PWR_SEQ_WAIT_EVENTS_IN(x)            \
                in_dword(HWIO_PWR_SEQ_WAIT_EVENTS_ADDR(x))
#define HWIO_PWR_SEQ_WAIT_EVENTS_INM(x, m)            \
                in_dword_masked(HWIO_PWR_SEQ_WAIT_EVENTS_ADDR(x), m)
#define HWIO_PWR_SEQ_WAIT_EVENTS_PWR_SEQ_WAIT_EVENTS_BMSK                                                     0xffffffff
#define HWIO_PWR_SEQ_WAIT_EVENTS_PWR_SEQ_WAIT_EVENTS_SHFT                                                              0

#define HWIO_CRASH_WAKEUP_CONFIG_0_ADDR(x)                                                                    ((x) + 0x1300)
#define HWIO_CRASH_WAKEUP_CONFIG_0_PHYS(x)                                                                    ((x) + 0x1300)
#define HWIO_CRASH_WAKEUP_CONFIG_0_OFFS                                                                       (0x1300)
#define HWIO_CRASH_WAKEUP_CONFIG_0_RMSK                                                                              0x3
#define HWIO_CRASH_WAKEUP_CONFIG_0_IN(x)            \
                in_dword(HWIO_CRASH_WAKEUP_CONFIG_0_ADDR(x))
#define HWIO_CRASH_WAKEUP_CONFIG_0_INM(x, m)            \
                in_dword_masked(HWIO_CRASH_WAKEUP_CONFIG_0_ADDR(x), m)
#define HWIO_CRASH_WAKEUP_CONFIG_0_OUT(x, v)            \
                out_dword(HWIO_CRASH_WAKEUP_CONFIG_0_ADDR(x),v)
#define HWIO_CRASH_WAKEUP_CONFIG_0_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_CRASH_WAKEUP_CONFIG_0_ADDR(x),m,v,HWIO_CRASH_WAKEUP_CONFIG_0_IN(x))
#define HWIO_CRASH_WAKEUP_CONFIG_0_DISABLE_DEBUG_CSR_UPDATE_BMSK                                                     0x2
#define HWIO_CRASH_WAKEUP_CONFIG_0_DISABLE_DEBUG_CSR_UPDATE_SHFT                                                       1
#define HWIO_CRASH_WAKEUP_CONFIG_0_FORCE_CLK_EN_BMSK                                                                 0x1
#define HWIO_CRASH_WAKEUP_CONFIG_0_FORCE_CLK_EN_SHFT                                                                   0

#define HWIO_CRASH_WAKEUP_PARAM_SEQ_CONFIG_ADDR(x)                                                            ((x) + 0x1304)
#define HWIO_CRASH_WAKEUP_PARAM_SEQ_CONFIG_PHYS(x)                                                            ((x) + 0x1304)
#define HWIO_CRASH_WAKEUP_PARAM_SEQ_CONFIG_OFFS                                                               (0x1304)
#define HWIO_CRASH_WAKEUP_PARAM_SEQ_CONFIG_RMSK                                                                    0x3ff
#define HWIO_CRASH_WAKEUP_PARAM_SEQ_CONFIG_IN(x)            \
                in_dword(HWIO_CRASH_WAKEUP_PARAM_SEQ_CONFIG_ADDR(x))
#define HWIO_CRASH_WAKEUP_PARAM_SEQ_CONFIG_INM(x, m)            \
                in_dword_masked(HWIO_CRASH_WAKEUP_PARAM_SEQ_CONFIG_ADDR(x), m)
#define HWIO_CRASH_WAKEUP_PARAM_SEQ_CONFIG_NUM_SEQ_CMD_WORDS_BMSK                                                  0x3ff
#define HWIO_CRASH_WAKEUP_PARAM_SEQ_CONFIG_NUM_SEQ_CMD_WORDS_SHFT                                                      0

#define HWIO_CRASH_WAKEUP_BUSY_ADDR(x)                                                                        ((x) + 0x1308)
#define HWIO_CRASH_WAKEUP_BUSY_PHYS(x)                                                                        ((x) + 0x1308)
#define HWIO_CRASH_WAKEUP_BUSY_OFFS                                                                           (0x1308)
#define HWIO_CRASH_WAKEUP_BUSY_RMSK                                                                                  0x1
#define HWIO_CRASH_WAKEUP_BUSY_IN(x)            \
                in_dword(HWIO_CRASH_WAKEUP_BUSY_ADDR(x))
#define HWIO_CRASH_WAKEUP_BUSY_INM(x, m)            \
                in_dword_masked(HWIO_CRASH_WAKEUP_BUSY_ADDR(x), m)
#define HWIO_CRASH_WAKEUP_BUSY_BUSY_STAT_BMSK                                                                        0x1
#define HWIO_CRASH_WAKEUP_BUSY_BUSY_STAT_SHFT                                                                          0

#define HWIO_CRASH_WAKEUP_DBG_PROGRAM_COUNTER_ADDR(x)                                                         ((x) + 0x130c)
#define HWIO_CRASH_WAKEUP_DBG_PROGRAM_COUNTER_PHYS(x)                                                         ((x) + 0x130c)
#define HWIO_CRASH_WAKEUP_DBG_PROGRAM_COUNTER_OFFS                                                            (0x130c)
#define HWIO_CRASH_WAKEUP_DBG_PROGRAM_COUNTER_RMSK                                                                 0x3ff
#define HWIO_CRASH_WAKEUP_DBG_PROGRAM_COUNTER_IN(x)            \
                in_dword(HWIO_CRASH_WAKEUP_DBG_PROGRAM_COUNTER_ADDR(x))
#define HWIO_CRASH_WAKEUP_DBG_PROGRAM_COUNTER_INM(x, m)            \
                in_dword_masked(HWIO_CRASH_WAKEUP_DBG_PROGRAM_COUNTER_ADDR(x), m)
#define HWIO_CRASH_WAKEUP_DBG_PROGRAM_COUNTER_CURRENT_INSTR_ADDR_BMSK                                              0x3ff
#define HWIO_CRASH_WAKEUP_DBG_PROGRAM_COUNTER_CURRENT_INSTR_ADDR_SHFT                                                  0

#define HWIO_CRASH_WAKEUP_DBG_STAT_ADDR(x)                                                                    ((x) + 0x1310)
#define HWIO_CRASH_WAKEUP_DBG_STAT_PHYS(x)                                                                    ((x) + 0x1310)
#define HWIO_CRASH_WAKEUP_DBG_STAT_OFFS                                                                       (0x1310)
#define HWIO_CRASH_WAKEUP_DBG_STAT_RMSK                                                                              0x1
#define HWIO_CRASH_WAKEUP_DBG_STAT_IN(x)            \
                in_dword(HWIO_CRASH_WAKEUP_DBG_STAT_ADDR(x))
#define HWIO_CRASH_WAKEUP_DBG_STAT_INM(x, m)            \
                in_dword_masked(HWIO_CRASH_WAKEUP_DBG_STAT_ADDR(x), m)
#define HWIO_CRASH_WAKEUP_DBG_STAT_DBG_STEPPING_STATUS_BMSK                                                          0x1
#define HWIO_CRASH_WAKEUP_DBG_STAT_DBG_STEPPING_STATUS_SHFT                                                            0

#define HWIO_CRASH_WAKEUP_START_ADDR_ADDR(x)                                                                  ((x) + 0x1314)
#define HWIO_CRASH_WAKEUP_START_ADDR_PHYS(x)                                                                  ((x) + 0x1314)
#define HWIO_CRASH_WAKEUP_START_ADDR_OFFS                                                                     (0x1314)
#define HWIO_CRASH_WAKEUP_START_ADDR_RMSK                                                                          0x3ff
#define HWIO_CRASH_WAKEUP_START_ADDR_IN(x)            \
                in_dword(HWIO_CRASH_WAKEUP_START_ADDR_ADDR(x))
#define HWIO_CRASH_WAKEUP_START_ADDR_INM(x, m)            \
                in_dword_masked(HWIO_CRASH_WAKEUP_START_ADDR_ADDR(x), m)
#define HWIO_CRASH_WAKEUP_START_ADDR_OUT(x, v)            \
                out_dword(HWIO_CRASH_WAKEUP_START_ADDR_ADDR(x),v)
#define HWIO_CRASH_WAKEUP_START_ADDR_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_CRASH_WAKEUP_START_ADDR_ADDR(x),m,v,HWIO_CRASH_WAKEUP_START_ADDR_IN(x))
#define HWIO_CRASH_WAKEUP_START_ADDR_SEQ_START_ADDR_BMSK                                                           0x3ff
#define HWIO_CRASH_WAKEUP_START_ADDR_SEQ_START_ADDR_SHFT                                                               0

#define HWIO_CRASH_WAKEUP_OVERRIDE_START_ADDR_ADDR(x)                                                         ((x) + 0x1318)
#define HWIO_CRASH_WAKEUP_OVERRIDE_START_ADDR_PHYS(x)                                                         ((x) + 0x1318)
#define HWIO_CRASH_WAKEUP_OVERRIDE_START_ADDR_OFFS                                                            (0x1318)
#define HWIO_CRASH_WAKEUP_OVERRIDE_START_ADDR_RMSK                                                            0x800003ff
#define HWIO_CRASH_WAKEUP_OVERRIDE_START_ADDR_IN(x)            \
                in_dword(HWIO_CRASH_WAKEUP_OVERRIDE_START_ADDR_ADDR(x))
#define HWIO_CRASH_WAKEUP_OVERRIDE_START_ADDR_INM(x, m)            \
                in_dword_masked(HWIO_CRASH_WAKEUP_OVERRIDE_START_ADDR_ADDR(x), m)
#define HWIO_CRASH_WAKEUP_OVERRIDE_START_ADDR_OUT(x, v)            \
                out_dword(HWIO_CRASH_WAKEUP_OVERRIDE_START_ADDR_ADDR(x),v)
#define HWIO_CRASH_WAKEUP_OVERRIDE_START_ADDR_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_CRASH_WAKEUP_OVERRIDE_START_ADDR_ADDR(x),m,v,HWIO_CRASH_WAKEUP_OVERRIDE_START_ADDR_IN(x))
#define HWIO_CRASH_WAKEUP_OVERRIDE_START_ADDR_SEQ_OVERRIDE_VALID_BMSK                                         0x80000000
#define HWIO_CRASH_WAKEUP_OVERRIDE_START_ADDR_SEQ_OVERRIDE_VALID_SHFT                                                 31
#define HWIO_CRASH_WAKEUP_OVERRIDE_START_ADDR_SEQ_OVERRIDE_START_ADDR_BMSK                                         0x3ff
#define HWIO_CRASH_WAKEUP_OVERRIDE_START_ADDR_SEQ_OVERRIDE_START_ADDR_SHFT                                             0

#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_0_ADDR(x)                                                    ((x) + 0x131c)
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_0_PHYS(x)                                                    ((x) + 0x131c)
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_0_OFFS                                                       (0x131c)
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_0_RMSK                                                       0xffffffff
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_0_IN(x)            \
                in_dword(HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_0_ADDR(x))
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_0_INM(x, m)            \
                in_dword_masked(HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_0_ADDR(x), m)
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_0_OUT(x, v)            \
                out_dword(HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_0_ADDR(x),v)
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_0_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_0_ADDR(x),m,v,HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_0_IN(x))
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_0_PWR_CTRL_OVERRIDE_MASK_0_BMSK                              0xffffffff
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_0_PWR_CTRL_OVERRIDE_MASK_0_SHFT                                       0

#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_0_ADDR(x)                                                     ((x) + 0x1320)
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_0_PHYS(x)                                                     ((x) + 0x1320)
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_0_OFFS                                                        (0x1320)
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_0_RMSK                                                        0xffffffff
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_0_IN(x)            \
                in_dword(HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_0_ADDR(x))
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_0_INM(x, m)            \
                in_dword_masked(HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_0_ADDR(x), m)
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_0_OUT(x, v)            \
                out_dword(HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_0_ADDR(x),v)
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_0_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_0_ADDR(x),m,v,HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_0_IN(x))
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_0_PWR_CTRL_OVERRIDE_VAL_0_BMSK                                0xffffffff
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_0_PWR_CTRL_OVERRIDE_VAL_0_SHFT                                         0

#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_1_ADDR(x)                                                    ((x) + 0x1324)
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_1_PHYS(x)                                                    ((x) + 0x1324)
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_1_OFFS                                                       (0x1324)
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_1_RMSK                                                       0xffffffff
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_1_IN(x)            \
                in_dword(HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_1_ADDR(x))
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_1_INM(x, m)            \
                in_dword_masked(HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_1_ADDR(x), m)
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_1_OUT(x, v)            \
                out_dword(HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_1_ADDR(x),v)
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_1_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_1_ADDR(x),m,v,HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_1_IN(x))
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_1_PWR_CTRL_OVERRIDE_MASK_1_BMSK                              0xffffffff
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_MASK_1_PWR_CTRL_OVERRIDE_MASK_1_SHFT                                       0

#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_1_ADDR(x)                                                     ((x) + 0x1328)
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_1_PHYS(x)                                                     ((x) + 0x1328)
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_1_OFFS                                                        (0x1328)
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_1_RMSK                                                        0xffffffff
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_1_IN(x)            \
                in_dword(HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_1_ADDR(x))
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_1_INM(x, m)            \
                in_dword_masked(HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_1_ADDR(x), m)
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_1_OUT(x, v)            \
                out_dword(HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_1_ADDR(x),v)
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_1_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_1_ADDR(x),m,v,HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_1_IN(x))
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_1_PWR_CTRL_OVERRIDE_VAL_1_BMSK                                0xffffffff
#define HWIO_CRASH_WAKEUP_PWR_CTRL_OVERRIDE_VAL_1_PWR_CTRL_OVERRIDE_VAL_1_SHFT                                         0

#define HWIO_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_MASK_ADDR(x)                                                    ((x) + 0x132c)
#define HWIO_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_MASK_PHYS(x)                                                    ((x) + 0x132c)
#define HWIO_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_MASK_OFFS                                                       (0x132c)
#define HWIO_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_MASK_RMSK                                                       0xffffffff
#define HWIO_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_MASK_IN(x)            \
                in_dword(HWIO_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_MASK_ADDR(x))
#define HWIO_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_MASK_INM(x, m)            \
                in_dword_masked(HWIO_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_MASK_ADDR(x), m)
#define HWIO_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_MASK_OUT(x, v)            \
                out_dword(HWIO_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_MASK_ADDR(x),v)
#define HWIO_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_MASK_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_MASK_ADDR(x),m,v,HWIO_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_MASK_IN(x))
#define HWIO_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_MASK_WAIT_EVENT_OVERRIDE_MASK_BMSK                              0xffffffff
#define HWIO_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_MASK_WAIT_EVENT_OVERRIDE_MASK_SHFT                                       0

#define HWIO_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_VAL_ADDR(x)                                                     ((x) + 0x1330)
#define HWIO_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_VAL_PHYS(x)                                                     ((x) + 0x1330)
#define HWIO_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_VAL_OFFS                                                        (0x1330)
#define HWIO_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_VAL_RMSK                                                        0xffffffff
#define HWIO_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_VAL_IN(x)            \
                in_dword(HWIO_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_VAL_ADDR(x))
#define HWIO_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_VAL_INM(x, m)            \
                in_dword_masked(HWIO_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_VAL_ADDR(x), m)
#define HWIO_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_VAL_OUT(x, v)            \
                out_dword(HWIO_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_VAL_ADDR(x),v)
#define HWIO_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_VAL_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_VAL_ADDR(x),m,v,HWIO_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_VAL_IN(x))
#define HWIO_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_VAL_WAIT_EVENT_OVERRIDE_VAL_BMSK                                0xffffffff
#define HWIO_CRASH_WAKEUP_WAIT_EVENT_OVERRIDE_VAL_WAIT_EVENT_OVERRIDE_VAL_SHFT                                         0

#define HWIO_CRASH_WAKEUP_BR_EVENT_OVERRIDE_MASK_ADDR(x)                                                      ((x) + 0x1334)
#define HWIO_CRASH_WAKEUP_BR_EVENT_OVERRIDE_MASK_PHYS(x)                                                      ((x) + 0x1334)
#define HWIO_CRASH_WAKEUP_BR_EVENT_OVERRIDE_MASK_OFFS                                                         (0x1334)
#define HWIO_CRASH_WAKEUP_BR_EVENT_OVERRIDE_MASK_RMSK                                                         0xffffffff
#define HWIO_CRASH_WAKEUP_BR_EVENT_OVERRIDE_MASK_IN(x)            \
                in_dword(HWIO_CRASH_WAKEUP_BR_EVENT_OVERRIDE_MASK_ADDR(x))
#define HWIO_CRASH_WAKEUP_BR_EVENT_OVERRIDE_MASK_INM(x, m)            \
                in_dword_masked(HWIO_CRASH_WAKEUP_BR_EVENT_OVERRIDE_MASK_ADDR(x), m)
#define HWIO_CRASH_WAKEUP_BR_EVENT_OVERRIDE_MASK_OUT(x, v)            \
                out_dword(HWIO_CRASH_WAKEUP_BR_EVENT_OVERRIDE_MASK_ADDR(x),v)
#define HWIO_CRASH_WAKEUP_BR_EVENT_OVERRIDE_MASK_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_CRASH_WAKEUP_BR_EVENT_OVERRIDE_MASK_ADDR(x),m,v,HWIO_CRASH_WAKEUP_BR_EVENT_OVERRIDE_MASK_IN(x))
#define HWIO_CRASH_WAKEUP_BR_EVENT_OVERRIDE_MASK_BR_EVENT_OVERRIDE_MASK_BMSK                                  0xffffffff
#define HWIO_CRASH_WAKEUP_BR_EVENT_OVERRIDE_MASK_BR_EVENT_OVERRIDE_MASK_SHFT                                           0

#define HWIO_CRASH_WAKEUP_BR_EVENT_OVERRIDE_VAL_ADDR(x)                                                       ((x) + 0x1338)
#define HWIO_CRASH_WAKEUP_BR_EVENT_OVERRIDE_VAL_PHYS(x)                                                       ((x) + 0x1338)
#define HWIO_CRASH_WAKEUP_BR_EVENT_OVERRIDE_VAL_OFFS                                                          (0x1338)
#define HWIO_CRASH_WAKEUP_BR_EVENT_OVERRIDE_VAL_RMSK                                                          0xffffffff
#define HWIO_CRASH_WAKEUP_BR_EVENT_OVERRIDE_VAL_IN(x)            \
                in_dword(HWIO_CRASH_WAKEUP_BR_EVENT_OVERRIDE_VAL_ADDR(x))
#define HWIO_CRASH_WAKEUP_BR_EVENT_OVERRIDE_VAL_INM(x, m)            \
                in_dword_masked(HWIO_CRASH_WAKEUP_BR_EVENT_OVERRIDE_VAL_ADDR(x), m)
#define HWIO_CRASH_WAKEUP_BR_EVENT_OVERRIDE_VAL_OUT(x, v)            \
                out_dword(HWIO_CRASH_WAKEUP_BR_EVENT_OVERRIDE_VAL_ADDR(x),v)
#define HWIO_CRASH_WAKEUP_BR_EVENT_OVERRIDE_VAL_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_CRASH_WAKEUP_BR_EVENT_OVERRIDE_VAL_ADDR(x),m,v,HWIO_CRASH_WAKEUP_BR_EVENT_OVERRIDE_VAL_IN(x))
#define HWIO_CRASH_WAKEUP_BR_EVENT_OVERRIDE_VAL_BR_EVENT_OVERRIDE_VAL_BMSK                                    0xffffffff
#define HWIO_CRASH_WAKEUP_BR_EVENT_OVERRIDE_VAL_BR_EVENT_OVERRIDE_VAL_SHFT                                             0

#define HWIO_CRASH_WAKEUP_CONFIG_BR_ADDR_b_ADDR(base,b)                                                       ((base) + 0X133C + (0x4*(b)))
#define HWIO_CRASH_WAKEUP_CONFIG_BR_ADDR_b_PHYS(base,b)                                                       ((base) + 0X133C + (0x4*(b)))
#define HWIO_CRASH_WAKEUP_CONFIG_BR_ADDR_b_OFFS(b)                                                            (0X133C + (0x4*(b)))
#define HWIO_CRASH_WAKEUP_CONFIG_BR_ADDR_b_RMSK                                                                    0x3ff
#define HWIO_CRASH_WAKEUP_CONFIG_BR_ADDR_b_MAXb                                                                       31
#define HWIO_CRASH_WAKEUP_CONFIG_BR_ADDR_b_INI(base,b)                \
                in_dword_masked(HWIO_CRASH_WAKEUP_CONFIG_BR_ADDR_b_ADDR(base,b), HWIO_CRASH_WAKEUP_CONFIG_BR_ADDR_b_RMSK)
#define HWIO_CRASH_WAKEUP_CONFIG_BR_ADDR_b_INMI(base,b,mask)        \
                in_dword_masked(HWIO_CRASH_WAKEUP_CONFIG_BR_ADDR_b_ADDR(base,b), mask)
#define HWIO_CRASH_WAKEUP_CONFIG_BR_ADDR_b_OUTI(base,b,val)        \
                out_dword(HWIO_CRASH_WAKEUP_CONFIG_BR_ADDR_b_ADDR(base,b),val)
#define HWIO_CRASH_WAKEUP_CONFIG_BR_ADDR_b_OUTMI(base,b,mask,val) \
                out_dword_masked_ns(HWIO_CRASH_WAKEUP_CONFIG_BR_ADDR_b_ADDR(base,b),mask,val,HWIO_CRASH_WAKEUP_CONFIG_BR_ADDR_b_INI(base,b))
#define HWIO_CRASH_WAKEUP_CONFIG_BR_ADDR_b_CFG_BR_ADDR_BMSK                                                        0x3ff
#define HWIO_CRASH_WAKEUP_CONFIG_BR_ADDR_b_CFG_BR_ADDR_SHFT                                                            0

#define HWIO_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_ADDR(base,v)                                                     ((base) + 0X1400 + (0x4*(v)))
#define HWIO_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_PHYS(base,v)                                                     ((base) + 0X1400 + (0x4*(v)))
#define HWIO_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_OFFS(v)                                                          (0X1400 + (0x4*(v)))
#define HWIO_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_RMSK                                                                0xfffff
#define HWIO_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_MAXv                                                                     15
#define HWIO_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_INI(base,v)                \
                in_dword_masked(HWIO_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_ADDR(base,v), HWIO_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_RMSK)
#define HWIO_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_INMI(base,v,mask)        \
                in_dword_masked(HWIO_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_ADDR(base,v), mask)
#define HWIO_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_OUTI(base,v,val)        \
                out_dword(HWIO_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_ADDR(base,v),val)
#define HWIO_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_OUTMI(base,v,mask,val) \
                out_dword_masked_ns(HWIO_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_ADDR(base,v),mask,val,HWIO_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_INI(base,v))
#define HWIO_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_CFG_DELAY_VAL_BMSK                                                  0xfffff
#define HWIO_CRASH_WAKEUP_CONFIG_DELAY_VAL_v_CFG_DELAY_VAL_SHFT                                                        0

#define HWIO_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_ADDR(x)                                                         ((x) + 0x1500)
#define HWIO_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_PHYS(x)                                                         ((x) + 0x1500)
#define HWIO_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_OFFS                                                            (0x1500)
#define HWIO_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_RMSK                                                            0x800003ff
#define HWIO_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_IN(x)            \
                in_dword(HWIO_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_ADDR(x))
#define HWIO_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_INM(x, m)            \
                in_dword_masked(HWIO_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_ADDR(x), m)
#define HWIO_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_OUT(x, v)            \
                out_dword(HWIO_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_ADDR(x),v)
#define HWIO_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_ADDR(x),m,v,HWIO_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_IN(x))
#define HWIO_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_DBG_BREAKPOINT_VALID_BMSK                                       0x80000000
#define HWIO_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_DBG_BREAKPOINT_VALID_SHFT                                               31
#define HWIO_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_DBG_BREAKPOINT_ADDR_BMSK                                             0x3ff
#define HWIO_CRASH_WAKEUP_DBG_BREAKPOINT_ADDR_DBG_BREAKPOINT_ADDR_SHFT                                                 0

#define HWIO_CRASH_WAKEUP_DBG_STEP_ADDR(x)                                                                    ((x) + 0x1504)
#define HWIO_CRASH_WAKEUP_DBG_STEP_PHYS(x)                                                                    ((x) + 0x1504)
#define HWIO_CRASH_WAKEUP_DBG_STEP_OFFS                                                                       (0x1504)
#define HWIO_CRASH_WAKEUP_DBG_STEP_RMSK                                                                          0x10001
#define HWIO_CRASH_WAKEUP_DBG_STEP_IN(x)            \
                in_dword(HWIO_CRASH_WAKEUP_DBG_STEP_ADDR(x))
#define HWIO_CRASH_WAKEUP_DBG_STEP_INM(x, m)            \
                in_dword_masked(HWIO_CRASH_WAKEUP_DBG_STEP_ADDR(x), m)
#define HWIO_CRASH_WAKEUP_DBG_STEP_OUT(x, v)            \
                out_dword(HWIO_CRASH_WAKEUP_DBG_STEP_ADDR(x),v)
#define HWIO_CRASH_WAKEUP_DBG_STEP_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_CRASH_WAKEUP_DBG_STEP_ADDR(x),m,v,HWIO_CRASH_WAKEUP_DBG_STEP_IN(x))
#define HWIO_CRASH_WAKEUP_DBG_STEP_SEQ_DBG_STEP_TRIGGER_BMSK                                                     0x10000
#define HWIO_CRASH_WAKEUP_DBG_STEP_SEQ_DBG_STEP_TRIGGER_SHFT                                                          16
#define HWIO_CRASH_WAKEUP_DBG_STEP_SEQ_DBG_STEP_CONTINUE_BMSK                                                        0x1
#define HWIO_CRASH_WAKEUP_DBG_STEP_SEQ_DBG_STEP_CONTINUE_SHFT                                                          0

#define HWIO_CRASH_WAKEUP_PWR_CONTROL_0_ADDR(x)                                                               ((x) + 0x1508)
#define HWIO_CRASH_WAKEUP_PWR_CONTROL_0_PHYS(x)                                                               ((x) + 0x1508)
#define HWIO_CRASH_WAKEUP_PWR_CONTROL_0_OFFS                                                                  (0x1508)
#define HWIO_CRASH_WAKEUP_PWR_CONTROL_0_RMSK                                                                  0xffffffff
#define HWIO_CRASH_WAKEUP_PWR_CONTROL_0_IN(x)            \
                in_dword(HWIO_CRASH_WAKEUP_PWR_CONTROL_0_ADDR(x))
#define HWIO_CRASH_WAKEUP_PWR_CONTROL_0_INM(x, m)            \
                in_dword_masked(HWIO_CRASH_WAKEUP_PWR_CONTROL_0_ADDR(x), m)
#define HWIO_CRASH_WAKEUP_PWR_CONTROL_0_CRASH_WAKEUP_PWR_CONTROL_0_BMSK                                       0xffffffff
#define HWIO_CRASH_WAKEUP_PWR_CONTROL_0_CRASH_WAKEUP_PWR_CONTROL_0_SHFT                                                0

#define HWIO_CRASH_WAKEUP_PWR_CONTROL_1_ADDR(x)                                                               ((x) + 0x150c)
#define HWIO_CRASH_WAKEUP_PWR_CONTROL_1_PHYS(x)                                                               ((x) + 0x150c)
#define HWIO_CRASH_WAKEUP_PWR_CONTROL_1_OFFS                                                                  (0x150c)
#define HWIO_CRASH_WAKEUP_PWR_CONTROL_1_RMSK                                                                  0xffffffff
#define HWIO_CRASH_WAKEUP_PWR_CONTROL_1_IN(x)            \
                in_dword(HWIO_CRASH_WAKEUP_PWR_CONTROL_1_ADDR(x))
#define HWIO_CRASH_WAKEUP_PWR_CONTROL_1_INM(x, m)            \
                in_dword_masked(HWIO_CRASH_WAKEUP_PWR_CONTROL_1_ADDR(x), m)
#define HWIO_CRASH_WAKEUP_PWR_CONTROL_1_CRASH_WAKEUP_PWR_CONTROL_1_BMSK                                       0xffffffff
#define HWIO_CRASH_WAKEUP_PWR_CONTROL_1_CRASH_WAKEUP_PWR_CONTROL_1_SHFT                                                0

#define HWIO_CRASH_WAKEUP_WAIT_EVENTS_ADDR(x)                                                                 ((x) + 0x1510)
#define HWIO_CRASH_WAKEUP_WAIT_EVENTS_PHYS(x)                                                                 ((x) + 0x1510)
#define HWIO_CRASH_WAKEUP_WAIT_EVENTS_OFFS                                                                    (0x1510)
#define HWIO_CRASH_WAKEUP_WAIT_EVENTS_RMSK                                                                    0xffffffff
#define HWIO_CRASH_WAKEUP_WAIT_EVENTS_IN(x)            \
                in_dword(HWIO_CRASH_WAKEUP_WAIT_EVENTS_ADDR(x))
#define HWIO_CRASH_WAKEUP_WAIT_EVENTS_INM(x, m)            \
                in_dword_masked(HWIO_CRASH_WAKEUP_WAIT_EVENTS_ADDR(x), m)
#define HWIO_CRASH_WAKEUP_WAIT_EVENTS_CRASH_WAKEUP_WAIT_EVENTS_BMSK                                           0xffffffff
#define HWIO_CRASH_WAKEUP_WAIT_EVENTS_CRASH_WAKEUP_WAIT_EVENTS_SHFT                                                    0

#define HWIO_WAKE_IRQ_CFG_ENABLE_1_ADDR(x)                                                                    ((x) + 0x1600)
#define HWIO_WAKE_IRQ_CFG_ENABLE_1_PHYS(x)                                                                    ((x) + 0x1600)
#define HWIO_WAKE_IRQ_CFG_ENABLE_1_OFFS                                                                       (0x1600)
#define HWIO_WAKE_IRQ_CFG_ENABLE_1_RMSK                                                                       0xffffffff
#define HWIO_WAKE_IRQ_CFG_ENABLE_1_IN(x)            \
                in_dword(HWIO_WAKE_IRQ_CFG_ENABLE_1_ADDR(x))
#define HWIO_WAKE_IRQ_CFG_ENABLE_1_INM(x, m)            \
                in_dword_masked(HWIO_WAKE_IRQ_CFG_ENABLE_1_ADDR(x), m)
#define HWIO_WAKE_IRQ_CFG_ENABLE_1_OUT(x, v)            \
                out_dword(HWIO_WAKE_IRQ_CFG_ENABLE_1_ADDR(x),v)
#define HWIO_WAKE_IRQ_CFG_ENABLE_1_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_WAKE_IRQ_CFG_ENABLE_1_ADDR(x),m,v,HWIO_WAKE_IRQ_CFG_ENABLE_1_IN(x))
#define HWIO_WAKE_IRQ_CFG_ENABLE_1_WAKE_IRQ_CFG_ENABLE_BMSK                                                   0xffffffff
#define HWIO_WAKE_IRQ_CFG_ENABLE_1_WAKE_IRQ_CFG_ENABLE_SHFT                                                            0

#define HWIO_WAKE_IRQ_CFG_NEGEDGE_1_ADDR(x)                                                                   ((x) + 0x1604)
#define HWIO_WAKE_IRQ_CFG_NEGEDGE_1_PHYS(x)                                                                   ((x) + 0x1604)
#define HWIO_WAKE_IRQ_CFG_NEGEDGE_1_OFFS                                                                      (0x1604)
#define HWIO_WAKE_IRQ_CFG_NEGEDGE_1_RMSK                                                                      0xffffffff
#define HWIO_WAKE_IRQ_CFG_NEGEDGE_1_IN(x)            \
                in_dword(HWIO_WAKE_IRQ_CFG_NEGEDGE_1_ADDR(x))
#define HWIO_WAKE_IRQ_CFG_NEGEDGE_1_INM(x, m)            \
                in_dword_masked(HWIO_WAKE_IRQ_CFG_NEGEDGE_1_ADDR(x), m)
#define HWIO_WAKE_IRQ_CFG_NEGEDGE_1_OUT(x, v)            \
                out_dword(HWIO_WAKE_IRQ_CFG_NEGEDGE_1_ADDR(x),v)
#define HWIO_WAKE_IRQ_CFG_NEGEDGE_1_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_WAKE_IRQ_CFG_NEGEDGE_1_ADDR(x),m,v,HWIO_WAKE_IRQ_CFG_NEGEDGE_1_IN(x))
#define HWIO_WAKE_IRQ_CFG_NEGEDGE_1_WAKE_IRQ_CFG_NEGEDGE_BMSK                                                 0xffffffff
#define HWIO_WAKE_IRQ_CFG_NEGEDGE_1_WAKE_IRQ_CFG_NEGEDGE_SHFT                                                          0

#define HWIO_WAKE_IRQ_CFG_POSEDGE_1_ADDR(x)                                                                   ((x) + 0x1608)
#define HWIO_WAKE_IRQ_CFG_POSEDGE_1_PHYS(x)                                                                   ((x) + 0x1608)
#define HWIO_WAKE_IRQ_CFG_POSEDGE_1_OFFS                                                                      (0x1608)
#define HWIO_WAKE_IRQ_CFG_POSEDGE_1_RMSK                                                                      0xffffffff
#define HWIO_WAKE_IRQ_CFG_POSEDGE_1_IN(x)            \
                in_dword(HWIO_WAKE_IRQ_CFG_POSEDGE_1_ADDR(x))
#define HWIO_WAKE_IRQ_CFG_POSEDGE_1_INM(x, m)            \
                in_dword_masked(HWIO_WAKE_IRQ_CFG_POSEDGE_1_ADDR(x), m)
#define HWIO_WAKE_IRQ_CFG_POSEDGE_1_OUT(x, v)            \
                out_dword(HWIO_WAKE_IRQ_CFG_POSEDGE_1_ADDR(x),v)
#define HWIO_WAKE_IRQ_CFG_POSEDGE_1_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_WAKE_IRQ_CFG_POSEDGE_1_ADDR(x),m,v,HWIO_WAKE_IRQ_CFG_POSEDGE_1_IN(x))
#define HWIO_WAKE_IRQ_CFG_POSEDGE_1_WAKE_IRQ_CFG_POSEDGE_BMSK                                                 0xffffffff
#define HWIO_WAKE_IRQ_CFG_POSEDGE_1_WAKE_IRQ_CFG_POSEDGE_SHFT                                                          0

#define HWIO_WAKE_IRQ_CFG_POLARITY_1_ADDR(x)                                                                  ((x) + 0x160c)
#define HWIO_WAKE_IRQ_CFG_POLARITY_1_PHYS(x)                                                                  ((x) + 0x160c)
#define HWIO_WAKE_IRQ_CFG_POLARITY_1_OFFS                                                                     (0x160c)
#define HWIO_WAKE_IRQ_CFG_POLARITY_1_RMSK                                                                     0xffffffff
#define HWIO_WAKE_IRQ_CFG_POLARITY_1_IN(x)            \
                in_dword(HWIO_WAKE_IRQ_CFG_POLARITY_1_ADDR(x))
#define HWIO_WAKE_IRQ_CFG_POLARITY_1_INM(x, m)            \
                in_dword_masked(HWIO_WAKE_IRQ_CFG_POLARITY_1_ADDR(x), m)
#define HWIO_WAKE_IRQ_CFG_POLARITY_1_OUT(x, v)            \
                out_dword(HWIO_WAKE_IRQ_CFG_POLARITY_1_ADDR(x),v)
#define HWIO_WAKE_IRQ_CFG_POLARITY_1_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_WAKE_IRQ_CFG_POLARITY_1_ADDR(x),m,v,HWIO_WAKE_IRQ_CFG_POLARITY_1_IN(x))
#define HWIO_WAKE_IRQ_CFG_POLARITY_1_WAKE_IRQ_CFG_POLARITY_BMSK                                               0xffffffff
#define HWIO_WAKE_IRQ_CFG_POLARITY_1_WAKE_IRQ_CFG_POLARITY_SHFT                                                        0

#define HWIO_WAKE_IRQ_STATUS_1_ADDR(x)                                                                        ((x) + 0x1610)
#define HWIO_WAKE_IRQ_STATUS_1_PHYS(x)                                                                        ((x) + 0x1610)
#define HWIO_WAKE_IRQ_STATUS_1_OFFS                                                                           (0x1610)
#define HWIO_WAKE_IRQ_STATUS_1_RMSK                                                                           0xffffffff
#define HWIO_WAKE_IRQ_STATUS_1_IN(x)            \
                in_dword(HWIO_WAKE_IRQ_STATUS_1_ADDR(x))
#define HWIO_WAKE_IRQ_STATUS_1_INM(x, m)            \
                in_dword_masked(HWIO_WAKE_IRQ_STATUS_1_ADDR(x), m)
#define HWIO_WAKE_IRQ_STATUS_1_WAKE_IRQ_STATUS_BMSK                                                           0xffffffff
#define HWIO_WAKE_IRQ_STATUS_1_WAKE_IRQ_STATUS_SHFT                                                                    0

#define HWIO_SAILSS_PC_SEQ_MEM_m_ADDR(base,m)                                                                 ((base) + 0X4000 + (0x4*(m)))
#define HWIO_SAILSS_PC_SEQ_MEM_m_PHYS(base,m)                                                                 ((base) + 0X4000 + (0x4*(m)))
#define HWIO_SAILSS_PC_SEQ_MEM_m_OFFS(m)                                                                      (0X4000 + (0x4*(m)))
#define HWIO_SAILSS_PC_SEQ_MEM_m_RMSK                                                                         0xffffffff
#define HWIO_SAILSS_PC_SEQ_MEM_m_MAXm                                                                                255
#define HWIO_SAILSS_PC_SEQ_MEM_m_INI(base,m)                \
                in_dword_masked(HWIO_SAILSS_PC_SEQ_MEM_m_ADDR(base,m), HWIO_SAILSS_PC_SEQ_MEM_m_RMSK)
#define HWIO_SAILSS_PC_SEQ_MEM_m_INMI(base,m,mask)        \
                in_dword_masked(HWIO_SAILSS_PC_SEQ_MEM_m_ADDR(base,m), mask)
#define HWIO_SAILSS_PC_SEQ_MEM_m_OUTI(base,m,val)        \
                out_dword(HWIO_SAILSS_PC_SEQ_MEM_m_ADDR(base,m),val)
#define HWIO_SAILSS_PC_SEQ_MEM_m_OUTMI(base,m,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_PC_SEQ_MEM_m_ADDR(base,m),mask,val,HWIO_SAILSS_PC_SEQ_MEM_m_INI(base,m))
#define HWIO_SAILSS_PC_SEQ_MEM_m_CMD_1_INSTR_FIELD_BMSK                                                       0xff000000
#define HWIO_SAILSS_PC_SEQ_MEM_m_CMD_1_INSTR_FIELD_SHFT                                                               24
#define HWIO_SAILSS_PC_SEQ_MEM_m_CMD_1_INSTR_FIELD_DELAY_FVAL                                                        0x0
#define HWIO_SAILSS_PC_SEQ_MEM_m_CMD_1_INSTR_FIELD_RETURN_FVAL                                                       0x1
#define HWIO_SAILSS_PC_SEQ_MEM_m_CMD_1_INSTR_FIELD_BRANCH_EQUAL_NO_RETURN_FVAL                                       0x2
#define HWIO_SAILSS_PC_SEQ_MEM_m_CMD_1_INSTR_FIELD_BRANCH_EQUAL_WITH_RETURN_FVAL                                     0x3
#define HWIO_SAILSS_PC_SEQ_MEM_m_CMD_1_INSTR_FIELD_SET_OUTPUT_LEVEL_0_FVAL                                           0x4
#define HWIO_SAILSS_PC_SEQ_MEM_m_CMD_1_INSTR_FIELD_SET_OUTPUT_LEVEL_1_FVAL                                           0x5
#define HWIO_SAILSS_PC_SEQ_MEM_m_CMD_1_INSTR_FIELD_WAIT_FOR_INPUT_LEVEL_0_FVAL                                       0x6
#define HWIO_SAILSS_PC_SEQ_MEM_m_CMD_1_INSTR_FIELD_WAIT_FOR_INPUT_LEVEL_1_FVAL                                       0x7
#define HWIO_SAILSS_PC_SEQ_MEM_m_CMD_1_DATA_FIELD_BMSK                                                          0xff0000
#define HWIO_SAILSS_PC_SEQ_MEM_m_CMD_1_DATA_FIELD_SHFT                                                                16
#define HWIO_SAILSS_PC_SEQ_MEM_m_CMD_0_INSTR_FIELD_BMSK                                                           0xff00
#define HWIO_SAILSS_PC_SEQ_MEM_m_CMD_0_INSTR_FIELD_SHFT                                                                8
#define HWIO_SAILSS_PC_SEQ_MEM_m_CMD_0_INSTR_FIELD_DELAY_FVAL                                                        0x0
#define HWIO_SAILSS_PC_SEQ_MEM_m_CMD_0_INSTR_FIELD_RETURN_FVAL                                                       0x1
#define HWIO_SAILSS_PC_SEQ_MEM_m_CMD_0_INSTR_FIELD_BRANCH_EQUAL_NO_RETURN_FVAL                                       0x2
#define HWIO_SAILSS_PC_SEQ_MEM_m_CMD_0_INSTR_FIELD_BRANCH_EQUAL_WITH_RETURN_FVAL                                     0x3
#define HWIO_SAILSS_PC_SEQ_MEM_m_CMD_0_INSTR_FIELD_SET_OUTPUT_LEVEL_0_FVAL                                           0x4
#define HWIO_SAILSS_PC_SEQ_MEM_m_CMD_0_INSTR_FIELD_SET_OUTPUT_LEVEL_1_FVAL                                           0x5
#define HWIO_SAILSS_PC_SEQ_MEM_m_CMD_0_INSTR_FIELD_WAIT_FOR_INPUT_LEVEL_0_FVAL                                       0x6
#define HWIO_SAILSS_PC_SEQ_MEM_m_CMD_0_INSTR_FIELD_WAIT_FOR_INPUT_LEVEL_1_FVAL                                       0x7
#define HWIO_SAILSS_PC_SEQ_MEM_m_CMD_0_DATA_FIELD_BMSK                                                              0xff
#define HWIO_SAILSS_PC_SEQ_MEM_m_CMD_0_DATA_FIELD_SHFT                                                                 0

#define HWIO_SAILSS_CRASH_SEQ_MEM_m_ADDR(base,m)                                                              ((base) + 0X5000 + (0x4*(m)))
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_PHYS(base,m)                                                              ((base) + 0X5000 + (0x4*(m)))
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_OFFS(m)                                                                   (0X5000 + (0x4*(m)))
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_RMSK                                                                      0xffffffff
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_MAXm                                                                             255
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_INI(base,m)                \
                in_dword_masked(HWIO_SAILSS_CRASH_SEQ_MEM_m_ADDR(base,m), HWIO_SAILSS_CRASH_SEQ_MEM_m_RMSK)
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_INMI(base,m,mask)        \
                in_dword_masked(HWIO_SAILSS_CRASH_SEQ_MEM_m_ADDR(base,m), mask)
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_OUTI(base,m,val)        \
                out_dword(HWIO_SAILSS_CRASH_SEQ_MEM_m_ADDR(base,m),val)
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_OUTMI(base,m,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_CRASH_SEQ_MEM_m_ADDR(base,m),mask,val,HWIO_SAILSS_CRASH_SEQ_MEM_m_INI(base,m))
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_1_INSTR_FIELD_BMSK                                          0xff000000
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_1_INSTR_FIELD_SHFT                                                  24
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_1_INSTR_FIELD_DELAY_FVAL                                           0x0
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_1_INSTR_FIELD_RETURN_FVAL                                          0x1
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_1_INSTR_FIELD_BRANCH_EQUAL_NO_RETURN_FVAL                          0x2
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_1_INSTR_FIELD_BRANCH_EQUAL_WITH_RETURN_FVAL                        0x3
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_1_INSTR_FIELD_SET_OUTPUT_LEVEL_0_FVAL                              0x4
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_1_INSTR_FIELD_SET_OUTPUT_LEVEL_1_FVAL                              0x5
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_1_INSTR_FIELD_WAIT_FOR_INPUT_LEVEL_0_FVAL                          0x6
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_1_INSTR_FIELD_WAIT_FOR_INPUT_LEVEL_1_FVAL                          0x7
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_1_DATA_FIELD_BMSK                                             0xff0000
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_1_DATA_FIELD_SHFT                                                   16
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_0_INSTR_FIELD_BMSK                                              0xff00
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_0_INSTR_FIELD_SHFT                                                   8
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_0_INSTR_FIELD_DELAY_FVAL                                           0x0
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_0_INSTR_FIELD_RETURN_FVAL                                          0x1
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_0_INSTR_FIELD_BRANCH_EQUAL_NO_RETURN_FVAL                          0x2
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_0_INSTR_FIELD_BRANCH_EQUAL_WITH_RETURN_FVAL                        0x3
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_0_INSTR_FIELD_SET_OUTPUT_LEVEL_0_FVAL                              0x4
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_0_INSTR_FIELD_SET_OUTPUT_LEVEL_1_FVAL                              0x5
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_0_INSTR_FIELD_WAIT_FOR_INPUT_LEVEL_0_FVAL                          0x6
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_0_INSTR_FIELD_WAIT_FOR_INPUT_LEVEL_1_FVAL                          0x7
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_0_DATA_FIELD_BMSK                                                 0xff
#define HWIO_SAILSS_CRASH_SEQ_MEM_m_CRASH_SEQ_CMD_0_DATA_FIELD_SHFT                                                    0


#endif /* __SAIL_PWR_CNTRL_HWIO_H__ */