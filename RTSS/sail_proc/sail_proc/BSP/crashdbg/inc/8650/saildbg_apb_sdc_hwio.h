#ifndef __SAIL_APB_SDC_HWIO_H__
#define __SAIL_APB_SDC_HWIO_H__
/*
===========================================================================
*/
/**
    @file sail_apb_sdc_hwio.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        LeMansAU [lemansau_v1.0_p3q1r45]
 
    This file contains HWIO register definitions for the following modules:
        SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_ALL


    Generation parameters: 
    { 'filename': 'sail_apb_sdc_hwio.h',
      'header': '#include "msmhwiobase.h"',
      'modules': ['SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_ALL'],
      'output-offsets': True}
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/crashdbg/inc/8650/saildbg_apb_sdc_hwio.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/

#include "msmhwiobase.h"

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_ALL
 *--------------------------------------------------------------------------*/

#define SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_ALL_REG_BASE                              (0      + 0xfb010000)//Recheck-LEMANSAU_SAILSS_BASE
#define SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_ALL_REG_BASE_SIZE                         0x1000
#define SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_ALL_REG_BASE_USED                         0x24
#define SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_ALL_REG_BASE_OFFS                         0xfb010000

#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_CONTROL_ADDR                         (SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_ALL_REG_BASE      + 0x0)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_CONTROL_OFFS                         (SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_ALL_REG_BASE_OFFS + 0x0)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_CONTROL_RMSK                                0xf
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_CONTROL_IN                    \
                in_dword(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_CONTROL_ADDR)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_CONTROL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_CONTROL_ADDR, m)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_CONTROL_OUT(v)            \
                out_dword(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_CONTROL_ADDR,v)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_CONTROL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_CONTROL_ADDR,m,v,HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_CONTROL_IN)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_CONTROL_SPARES_BMSK                         0xc
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_CONTROL_SPARES_SHFT                           2
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_CONTROL_CORE_SEL_BMSK                       0x2
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_CONTROL_CORE_SEL_SHFT                         1
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_CONTROL_MANUAL_TRIGGER_BMSK                 0x1
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_CONTROL_MANUAL_TRIGGER_SHFT                   0

#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_DUMP_MODE_ADDR                          (SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_ALL_REG_BASE      + 0x4)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_DUMP_MODE_OFFS                          (SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_ALL_REG_BASE_OFFS + 0x4)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_DUMP_MODE_RMSK                                 0x3
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_DUMP_MODE_IN                    \
                in_dword(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_DUMP_MODE_ADDR)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_DUMP_MODE_INM(m)            \
                in_dword_masked(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_DUMP_MODE_ADDR, m)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_DUMP_MODE_OUT(v)            \
                out_dword(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_DUMP_MODE_ADDR,v)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_DUMP_MODE_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_DUMP_MODE_ADDR,m,v,HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_DUMP_MODE_IN)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_DUMP_MODE_CORE_BMSK                            0x3
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_DUMP_MODE_CORE_SHFT                              0

#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_0_EN_ADDR                               (SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_ALL_REG_BASE      + 0x8)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_0_EN_OFFS                               (SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_ALL_REG_BASE_OFFS + 0x8)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_0_EN_RMSK                                      0x3
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_0_EN_IN                    \
                in_dword(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_0_EN_ADDR)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_0_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_0_EN_ADDR, m)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_0_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_0_EN_ADDR,v)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_0_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_0_EN_ADDR,m,v,HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_0_EN_IN)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_0_EN_CORE_BMSK                                 0x3
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_0_EN_CORE_SHFT                                   0

#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_1_EN_ADDR                               (SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_ALL_REG_BASE      + 0xc)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_1_EN_OFFS                               (SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_ALL_REG_BASE_OFFS + 0xc)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_1_EN_RMSK                                      0x3
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_1_EN_IN                    \
                in_dword(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_1_EN_ADDR)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_1_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_1_EN_ADDR, m)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_1_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_1_EN_ADDR,v)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_1_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_1_EN_ADDR,m,v,HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_1_EN_IN)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_1_EN_CORE_BMSK                                 0x3
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_1_EN_CORE_SHFT                                   0

#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_2_EN_ADDR                               (SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_ALL_REG_BASE      + 0x10)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_2_EN_OFFS                               (SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_ALL_REG_BASE_OFFS + 0x10)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_2_EN_RMSK                                      0x3
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_2_EN_IN                    \
                in_dword(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_2_EN_ADDR)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_2_EN_INM(m)            \
                in_dword_masked(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_2_EN_ADDR, m)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_2_EN_OUT(v)            \
                out_dword(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_2_EN_ADDR,v)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_2_EN_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_2_EN_ADDR,m,v,HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_2_EN_IN)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_2_EN_CORE_BMSK                                 0x3
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_CTRL_2_EN_CORE_SHFT                                   0

#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_DATA_READY_ADDR                         (SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_ALL_REG_BASE      + 0x14)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_DATA_READY_OFFS                         (SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_ALL_REG_BASE_OFFS + 0x14)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_DATA_READY_RMSK                                0x1
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_DATA_READY_IN                    \
                in_dword(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_DATA_READY_ADDR)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_DATA_READY_INM(m)            \
                in_dword_masked(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_DATA_READY_ADDR, m)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_DATA_READY_STATUS_BMSK                         0x1
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_DATA_READY_STATUS_SHFT                           0

#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_CLOCK_CONTROL_ADDR                      (SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_ALL_REG_BASE      + 0x1c)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_CLOCK_CONTROL_OFFS                      (SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_ALL_REG_BASE_OFFS + 0x1c)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_CLOCK_CONTROL_RMSK                            0xff
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_CLOCK_CONTROL_IN                    \
                in_dword(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_CLOCK_CONTROL_ADDR)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_CLOCK_CONTROL_INM(m)            \
                in_dword_masked(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_CLOCK_CONTROL_ADDR, m)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_CLOCK_CONTROL_OUT(v)            \
                out_dword(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_CLOCK_CONTROL_ADDR,v)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_CLOCK_CONTROL_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_CLOCK_CONTROL_ADDR,m,v,HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_CLOCK_CONTROL_IN)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_CLOCK_CONTROL_DELAY_BMSK                      0xff
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_CLOCK_CONTROL_DELAY_SHFT                         0

#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_REG_ADDR                                (SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_ALL_REG_BASE      + 0x20)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_REG_OFFS                                (SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_ALL_REG_BASE_OFFS + 0x20)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_REG_RMSK                                0xffffffff
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_REG_IN                    \
                in_dword(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_REG_ADDR)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_REG_ADDR, m)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_REG_DATA_BMSK                           0xffffffff
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_SCAN_REG_DATA_SHFT                                    0

#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_JDR_REG_ADDR                                 (SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_ALL_REG_BASE      + 0x24)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_JDR_REG_OFFS                                 (SAILSS_DBG_SAILSS_DBG_RTCU_APB_SDC_ALL_REG_BASE_OFFS + 0x24)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_JDR_REG_RMSK                                       0x7f
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_JDR_REG_IN                    \
                in_dword(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_JDR_REG_ADDR)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_JDR_REG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_JDR_REG_ADDR, m)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_JDR_REG_OUT(v)            \
                out_dword(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_JDR_REG_ADDR,v)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_JDR_REG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_JDR_REG_ADDR,m,v,HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_JDR_REG_IN)
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_JDR_REG_VALUE_BMSK                                 0x7f
#define HWIO_SAILSS_DBG_SAILSS_DBG_RTCU_JDR_REG_VALUE_SHFT                                    0


#endif /* __SAIL_APB_SDC_HWIO_H__ */
