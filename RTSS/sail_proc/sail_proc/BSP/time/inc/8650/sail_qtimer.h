#ifndef __SAIL_QTIMER_H__
#define __SAIL_QTIMER_H__
/*
===========================================================================
*/
/**
    @file sail_qtimer.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        LeMansAU [lemansau_v1.0_p2q0r21]
 
    This file contains HWIO register definitions for the following modules:
        SAILSS_QTMR_SAILSS_QTMR
        SAILSS_QTMR_QTMR_F0_0
        SAILSS_QTMR_QTMR_F1_1
        SAILSS_QTMR_QTMR_F2_2
        SAILSS_QTMR_QTMR_F3_3
        SAILSS_QTMR_QTMR_F4_4
        SAILSS_QTMR_QTMR_F5_5
        SAILSS_QTMR_QTMR_F6_6
        SAILSS_QTMR_QTMR_F7_7
        SAILSS_QTMR_QTMR_F8_8
        SAILSS_QTMR_QTMR_F9_9
        SAILSS_QTMR_QTMR_F10_10
        SAILSS_QTMR_QTMR_F11_11
        SAILSS_QTMR_QTMR_AC
        SAILSS_QTMR_QTMR_WDT_CTL
        SAILSS_QTMR_QTMR_WDT_REFRESH


    Generation parameters: 
    { 'filename': 'sail_qtimer.h',
      'header': '#include "msmhwiobase.h"',
      'modules': [ 'SAILSS_QTMR_SAILSS_QTMR',
                   'SAILSS_QTMR_QTMR_F0_0',
                   'SAILSS_QTMR_QTMR_F1_1',
                   'SAILSS_QTMR_QTMR_F2_2',
                   'SAILSS_QTMR_QTMR_F3_3',
                   'SAILSS_QTMR_QTMR_F4_4',
                   'SAILSS_QTMR_QTMR_F5_5',
                   'SAILSS_QTMR_QTMR_F6_6',
                   'SAILSS_QTMR_QTMR_F7_7',
                   'SAILSS_QTMR_QTMR_F8_8',
                   'SAILSS_QTMR_QTMR_F9_9',
                   'SAILSS_QTMR_QTMR_F10_10',
                   'SAILSS_QTMR_QTMR_F11_11',
                   'SAILSS_QTMR_QTMR_AC',
                   'SAILSS_QTMR_QTMR_WDT_CTL',
                   'SAILSS_QTMR_QTMR_WDT_REFRESH'],
      'output-fvals': True,
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

    $Header: //components/dev/bsp.sail/1.0/smarru.bsp.sail.1.0.ref_2_1/time/inc/8650/sail_qtimer.h#1 $
    $DateTime: 2025/02/01 11:39:23 $
    $Author: smarru $

    ===========================================================================
*/

#include "msmhwiobase.h"

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_QTMR_QTMR_F0_0
 *--------------------------------------------------------------------------*/

#define SAILSS_QTMR_QTMR_F0_0_REG_BASE                                     (SAILSS_QTMR_SAILSS_QTMR_BASE            + 0x00000000)
#define SAILSS_QTMR_QTMR_F0_0_REG_BASE_SIZE                                0x1000
#define SAILSS_QTMR_QTMR_F0_0_REG_BASE_USED                                0xfd0
#define SAILSS_QTMR_QTMR_F0_0_REG_BASE_OFFS                                0x00000000

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_0_ADDR                          (SAILSS_QTMR_QTMR_F0_0_REG_BASE            + 0x0)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_0_OFFS                          (SAILSS_QTMR_QTMR_F0_0_REG_BASE_OFFS + 0x0)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_0_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_0_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_0_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_0_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_0_CNTPCT_LO_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_0_CNTPCT_LO_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_0_ADDR                          (SAILSS_QTMR_QTMR_F0_0_REG_BASE            + 0x4)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_0_OFFS                          (SAILSS_QTMR_QTMR_F0_0_REG_BASE_OFFS + 0x4)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_0_RMSK                            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_0_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_0_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_0_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_0_CNTPCT_HI_BMSK                  0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_0_CNTPCT_HI_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_0_ADDR                          (SAILSS_QTMR_QTMR_F0_0_REG_BASE            + 0x8)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_0_OFFS                          (SAILSS_QTMR_QTMR_F0_0_REG_BASE_OFFS + 0x8)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_0_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_0_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_0_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_0_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_0_CNTVCT_LO_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_0_CNTVCT_LO_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_0_ADDR                          (SAILSS_QTMR_QTMR_F0_0_REG_BASE            + 0xc)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_0_OFFS                          (SAILSS_QTMR_QTMR_F0_0_REG_BASE_OFFS + 0xc)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_0_RMSK                            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_0_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_0_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_0_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_0_CNTVCT_HI_BMSK                  0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_0_CNTVCT_HI_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_0_ADDR                             (SAILSS_QTMR_QTMR_F0_0_REG_BASE            + 0x10)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_0_OFFS                             (SAILSS_QTMR_QTMR_F0_0_REG_BASE_OFFS + 0x10)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_0_RMSK                             0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_0_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_0_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_0_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_0_CNTFRQ_BMSK                      0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_0_CNTFRQ_SHFT                               0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_0_ADDR                          (SAILSS_QTMR_QTMR_F0_0_REG_BASE            + 0x14)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_0_OFFS                          (SAILSS_QTMR_QTMR_F0_0_REG_BASE_OFFS + 0x14)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_0_RMSK                               0x303
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_0_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_0_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_0_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_0_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_0_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_0_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_0_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_0_PL0CTEN_BMSK                       0x200
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_0_PL0CTEN_SHFT                           9
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_0_PL0VTEN_BMSK                       0x100
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_0_PL0VTEN_SHFT                           8
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_0_PL0VCTEN_BMSK                        0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_0_PL0VCTEN_SHFT                          1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_0_PL0PCTEN_BMSK                        0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_0_PL0PCTEN_SHFT                          0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_0_ADDR                         (SAILSS_QTMR_QTMR_F0_0_REG_BASE            + 0x18)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_0_OFFS                         (SAILSS_QTMR_QTMR_F0_0_REG_BASE_OFFS + 0x18)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_0_RMSK                         0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_0_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_0_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_0_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_0_CNTVOFF_L0_BMSK              0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_0_CNTVOFF_L0_SHFT                       0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_0_ADDR                         (SAILSS_QTMR_QTMR_F0_0_REG_BASE            + 0x1c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_0_OFFS                         (SAILSS_QTMR_QTMR_F0_0_REG_BASE_OFFS + 0x1c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_0_RMSK                           0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_0_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_0_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_0_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_0_CNTVOFF_HI_BMSK                0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_0_CNTVOFF_HI_SHFT                       0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_0_ADDR                       (SAILSS_QTMR_QTMR_F0_0_REG_BASE            + 0x20)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_0_OFFS                       (SAILSS_QTMR_QTMR_F0_0_REG_BASE_OFFS + 0x20)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_0_RMSK                       0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_0_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_0_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_0_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_0_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_0_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_0_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_0_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_0_CNTP_CVAL_L0_BMSK          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_0_CNTP_CVAL_L0_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_0_ADDR                       (SAILSS_QTMR_QTMR_F0_0_REG_BASE            + 0x24)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_0_OFFS                       (SAILSS_QTMR_QTMR_F0_0_REG_BASE_OFFS + 0x24)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_0_RMSK                         0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_0_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_0_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_0_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_0_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_0_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_0_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_0_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_0_CNTP_CVAL_HI_BMSK            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_0_CNTP_CVAL_HI_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_0_ADDR                          (SAILSS_QTMR_QTMR_F0_0_REG_BASE            + 0x28)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_0_OFFS                          (SAILSS_QTMR_QTMR_F0_0_REG_BASE_OFFS + 0x28)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_0_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_0_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_0_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_0_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_0_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_0_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_0_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_0_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_0_CNTP_TVAL_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_0_CNTP_TVAL_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_0_ADDR                           (SAILSS_QTMR_QTMR_F0_0_REG_BASE            + 0x2c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_0_OFFS                           (SAILSS_QTMR_QTMR_F0_0_REG_BASE_OFFS + 0x2c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_0_RMSK                                  0x7
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_0_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_0_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_0_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_0_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_0_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_0_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_0_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_0_ISTAT_BMSK                            0x4
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_0_ISTAT_SHFT                              2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_0_ISTAT_INTERRUPT_NOT_PENDING_FVAL        0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_0_ISTAT_INTERRUPT_PENDING_FVAL          0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_0_IMSK_BMSK                             0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_0_IMSK_SHFT                               1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_0_IMSK_UNMASK_INTERRUPT_FVAL            0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_0_IMSK_MASK_INTERRUPT_FVAL              0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_0_EN_BMSK                               0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_0_EN_SHFT                                 0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_0_EN_DISABLED_FVAL                      0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_0_EN_ENABLED_FVAL                       0x1

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_0_ADDR                       (SAILSS_QTMR_QTMR_F0_0_REG_BASE            + 0x30)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_0_OFFS                       (SAILSS_QTMR_QTMR_F0_0_REG_BASE_OFFS + 0x30)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_0_RMSK                       0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_0_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_0_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_0_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_0_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_0_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_0_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_0_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_0_CNTV_CVAL_L0_BMSK          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_0_CNTV_CVAL_L0_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_0_ADDR                       (SAILSS_QTMR_QTMR_F0_0_REG_BASE            + 0x34)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_0_OFFS                       (SAILSS_QTMR_QTMR_F0_0_REG_BASE_OFFS + 0x34)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_0_RMSK                         0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_0_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_0_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_0_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_0_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_0_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_0_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_0_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_0_CNTV_CVAL_HI_BMSK            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_0_CNTV_CVAL_HI_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_0_ADDR                          (SAILSS_QTMR_QTMR_F0_0_REG_BASE            + 0x38)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_0_OFFS                          (SAILSS_QTMR_QTMR_F0_0_REG_BASE_OFFS + 0x38)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_0_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_0_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_0_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_0_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_0_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_0_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_0_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_0_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_0_CNTV_TVAL_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_0_CNTV_TVAL_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_0_ADDR                           (SAILSS_QTMR_QTMR_F0_0_REG_BASE            + 0x3c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_0_OFFS                           (SAILSS_QTMR_QTMR_F0_0_REG_BASE_OFFS + 0x3c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_0_RMSK                                  0x7
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_0_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_0_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_0_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_0_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_0_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_0_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_0_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_0_ISTAT_BMSK                            0x4
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_0_ISTAT_SHFT                              2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_0_ISTAT_INTERRUPT_NOT_PENDING_FVAL        0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_0_ISTAT_INTERRUPT_PENDING_FVAL          0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_0_IMSK_BMSK                             0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_0_IMSK_SHFT                               1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_0_IMSK_UNMASK_INTERRUPT_FVAL            0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_0_IMSK_MASK_INTERRUPT_FVAL              0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_0_EN_BMSK                               0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_0_EN_SHFT                                 0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_0_EN_DISABLED_FVAL                      0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_0_EN_ENABLED_FVAL                       0x1

#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_0_ADDR                            (SAILSS_QTMR_QTMR_F0_0_REG_BASE            + 0xfd0)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_0_OFFS                            (SAILSS_QTMR_QTMR_F0_0_REG_BASE_OFFS + 0xfd0)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_0_RMSK                            0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_0_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_VERSION_0_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_VERSION_0_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_0_MAJOR_BMSK                      0xf0000000
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_0_MAJOR_SHFT                              28
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_0_MINOR_BMSK                       0xfff0000
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_0_MINOR_SHFT                              16
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_0_STEP_BMSK                           0xffff
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_0_STEP_SHFT                                0

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_QTMR_QTMR_F1_1
 *--------------------------------------------------------------------------*/

#define SAILSS_QTMR_QTMR_F1_1_REG_BASE                                     (SAILSS_QTMR_SAILSS_QTMR_BASE            + 0x00001000)
#define SAILSS_QTMR_QTMR_F1_1_REG_BASE_SIZE                                0x1000
#define SAILSS_QTMR_QTMR_F1_1_REG_BASE_USED                                0xfd0
#define SAILSS_QTMR_QTMR_F1_1_REG_BASE_OFFS                                0x00001000

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_1_ADDR                          (SAILSS_QTMR_QTMR_F1_1_REG_BASE            + 0x0)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_1_OFFS                          (SAILSS_QTMR_QTMR_F1_1_REG_BASE_OFFS + 0x0)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_1_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_1_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_1_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_1_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_1_CNTPCT_LO_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_1_CNTPCT_LO_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_1_ADDR                          (SAILSS_QTMR_QTMR_F1_1_REG_BASE            + 0x4)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_1_OFFS                          (SAILSS_QTMR_QTMR_F1_1_REG_BASE_OFFS + 0x4)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_1_RMSK                            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_1_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_1_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_1_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_1_CNTPCT_HI_BMSK                  0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_1_CNTPCT_HI_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_1_ADDR                          (SAILSS_QTMR_QTMR_F1_1_REG_BASE            + 0x8)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_1_OFFS                          (SAILSS_QTMR_QTMR_F1_1_REG_BASE_OFFS + 0x8)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_1_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_1_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_1_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_1_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_1_CNTVCT_LO_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_1_CNTVCT_LO_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_1_ADDR                          (SAILSS_QTMR_QTMR_F1_1_REG_BASE            + 0xc)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_1_OFFS                          (SAILSS_QTMR_QTMR_F1_1_REG_BASE_OFFS + 0xc)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_1_RMSK                            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_1_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_1_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_1_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_1_CNTVCT_HI_BMSK                  0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_1_CNTVCT_HI_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_1_ADDR                             (SAILSS_QTMR_QTMR_F1_1_REG_BASE            + 0x10)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_1_OFFS                             (SAILSS_QTMR_QTMR_F1_1_REG_BASE_OFFS + 0x10)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_1_RMSK                             0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_1_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_1_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_1_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_1_CNTFRQ_BMSK                      0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_1_CNTFRQ_SHFT                               0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_1_ADDR                          (SAILSS_QTMR_QTMR_F1_1_REG_BASE            + 0x14)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_1_OFFS                          (SAILSS_QTMR_QTMR_F1_1_REG_BASE_OFFS + 0x14)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_1_RMSK                               0x303
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_1_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_1_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_1_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_1_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_1_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_1_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_1_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_1_PL0CTEN_BMSK                       0x200
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_1_PL0CTEN_SHFT                           9
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_1_PL0VTEN_BMSK                       0x100
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_1_PL0VTEN_SHFT                           8
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_1_PL0VCTEN_BMSK                        0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_1_PL0VCTEN_SHFT                          1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_1_PL0PCTEN_BMSK                        0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_1_PL0PCTEN_SHFT                          0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_1_ADDR                         (SAILSS_QTMR_QTMR_F1_1_REG_BASE            + 0x18)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_1_OFFS                         (SAILSS_QTMR_QTMR_F1_1_REG_BASE_OFFS + 0x18)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_1_RMSK                         0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_1_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_1_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_1_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_1_CNTVOFF_L0_BMSK              0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_1_CNTVOFF_L0_SHFT                       0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_1_ADDR                         (SAILSS_QTMR_QTMR_F1_1_REG_BASE            + 0x1c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_1_OFFS                         (SAILSS_QTMR_QTMR_F1_1_REG_BASE_OFFS + 0x1c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_1_RMSK                           0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_1_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_1_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_1_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_1_CNTVOFF_HI_BMSK                0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_1_CNTVOFF_HI_SHFT                       0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_1_ADDR                       (SAILSS_QTMR_QTMR_F1_1_REG_BASE            + 0x20)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_1_OFFS                       (SAILSS_QTMR_QTMR_F1_1_REG_BASE_OFFS + 0x20)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_1_RMSK                       0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_1_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_1_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_1_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_1_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_1_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_1_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_1_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_1_CNTP_CVAL_L0_BMSK          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_1_CNTP_CVAL_L0_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_1_ADDR                       (SAILSS_QTMR_QTMR_F1_1_REG_BASE            + 0x24)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_1_OFFS                       (SAILSS_QTMR_QTMR_F1_1_REG_BASE_OFFS + 0x24)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_1_RMSK                         0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_1_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_1_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_1_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_1_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_1_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_1_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_1_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_1_CNTP_CVAL_HI_BMSK            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_1_CNTP_CVAL_HI_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_1_ADDR                          (SAILSS_QTMR_QTMR_F1_1_REG_BASE            + 0x28)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_1_OFFS                          (SAILSS_QTMR_QTMR_F1_1_REG_BASE_OFFS + 0x28)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_1_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_1_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_1_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_1_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_1_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_1_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_1_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_1_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_1_CNTP_TVAL_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_1_CNTP_TVAL_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_1_ADDR                           (SAILSS_QTMR_QTMR_F1_1_REG_BASE            + 0x2c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_1_OFFS                           (SAILSS_QTMR_QTMR_F1_1_REG_BASE_OFFS + 0x2c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_1_RMSK                                  0x7
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_1_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_1_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_1_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_1_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_1_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_1_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_1_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_1_ISTAT_BMSK                            0x4
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_1_ISTAT_SHFT                              2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_1_ISTAT_INTERRUPT_NOT_PENDING_FVAL        0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_1_ISTAT_INTERRUPT_PENDING_FVAL          0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_1_IMSK_BMSK                             0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_1_IMSK_SHFT                               1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_1_IMSK_UNMASK_INTERRUPT_FVAL            0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_1_IMSK_MASK_INTERRUPT_FVAL              0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_1_EN_BMSK                               0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_1_EN_SHFT                                 0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_1_EN_DISABLED_FVAL                      0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_1_EN_ENABLED_FVAL                       0x1

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_1_ADDR                       (SAILSS_QTMR_QTMR_F1_1_REG_BASE            + 0x30)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_1_OFFS                       (SAILSS_QTMR_QTMR_F1_1_REG_BASE_OFFS + 0x30)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_1_RMSK                       0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_1_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_1_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_1_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_1_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_1_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_1_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_1_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_1_CNTV_CVAL_L0_BMSK          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_1_CNTV_CVAL_L0_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_1_ADDR                       (SAILSS_QTMR_QTMR_F1_1_REG_BASE            + 0x34)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_1_OFFS                       (SAILSS_QTMR_QTMR_F1_1_REG_BASE_OFFS + 0x34)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_1_RMSK                         0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_1_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_1_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_1_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_1_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_1_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_1_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_1_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_1_CNTV_CVAL_HI_BMSK            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_1_CNTV_CVAL_HI_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_1_ADDR                          (SAILSS_QTMR_QTMR_F1_1_REG_BASE            + 0x38)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_1_OFFS                          (SAILSS_QTMR_QTMR_F1_1_REG_BASE_OFFS + 0x38)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_1_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_1_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_1_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_1_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_1_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_1_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_1_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_1_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_1_CNTV_TVAL_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_1_CNTV_TVAL_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_1_ADDR                           (SAILSS_QTMR_QTMR_F1_1_REG_BASE            + 0x3c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_1_OFFS                           (SAILSS_QTMR_QTMR_F1_1_REG_BASE_OFFS + 0x3c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_1_RMSK                                  0x7
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_1_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_1_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_1_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_1_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_1_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_1_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_1_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_1_ISTAT_BMSK                            0x4
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_1_ISTAT_SHFT                              2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_1_ISTAT_INTERRUPT_NOT_PENDING_FVAL        0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_1_ISTAT_INTERRUPT_PENDING_FVAL          0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_1_IMSK_BMSK                             0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_1_IMSK_SHFT                               1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_1_IMSK_UNMASK_INTERRUPT_FVAL            0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_1_IMSK_MASK_INTERRUPT_FVAL              0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_1_EN_BMSK                               0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_1_EN_SHFT                                 0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_1_EN_DISABLED_FVAL                      0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_1_EN_ENABLED_FVAL                       0x1

#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_1_ADDR                            (SAILSS_QTMR_QTMR_F1_1_REG_BASE            + 0xfd0)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_1_OFFS                            (SAILSS_QTMR_QTMR_F1_1_REG_BASE_OFFS + 0xfd0)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_1_RMSK                            0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_1_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_VERSION_1_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_VERSION_1_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_1_MAJOR_BMSK                      0xf0000000
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_1_MAJOR_SHFT                              28
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_1_MINOR_BMSK                       0xfff0000
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_1_MINOR_SHFT                              16
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_1_STEP_BMSK                           0xffff
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_1_STEP_SHFT                                0

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_QTMR_QTMR_F2_2
 *--------------------------------------------------------------------------*/

#define SAILSS_QTMR_QTMR_F2_2_REG_BASE                                     (SAILSS_QTMR_SAILSS_QTMR_BASE            + 0x00002000)
#define SAILSS_QTMR_QTMR_F2_2_REG_BASE_SIZE                                0x1000
#define SAILSS_QTMR_QTMR_F2_2_REG_BASE_USED                                0xfd0
#define SAILSS_QTMR_QTMR_F2_2_REG_BASE_OFFS                                0x00002000

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_2_ADDR                          (SAILSS_QTMR_QTMR_F2_2_REG_BASE            + 0x0)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_2_OFFS                          (SAILSS_QTMR_QTMR_F2_2_REG_BASE_OFFS + 0x0)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_2_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_2_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_2_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_2_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_2_CNTPCT_LO_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_2_CNTPCT_LO_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_2_ADDR                          (SAILSS_QTMR_QTMR_F2_2_REG_BASE            + 0x4)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_2_OFFS                          (SAILSS_QTMR_QTMR_F2_2_REG_BASE_OFFS + 0x4)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_2_RMSK                            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_2_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_2_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_2_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_2_CNTPCT_HI_BMSK                  0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_2_CNTPCT_HI_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_2_ADDR                          (SAILSS_QTMR_QTMR_F2_2_REG_BASE            + 0x8)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_2_OFFS                          (SAILSS_QTMR_QTMR_F2_2_REG_BASE_OFFS + 0x8)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_2_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_2_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_2_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_2_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_2_CNTVCT_LO_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_2_CNTVCT_LO_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_2_ADDR                          (SAILSS_QTMR_QTMR_F2_2_REG_BASE            + 0xc)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_2_OFFS                          (SAILSS_QTMR_QTMR_F2_2_REG_BASE_OFFS + 0xc)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_2_RMSK                            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_2_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_2_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_2_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_2_CNTVCT_HI_BMSK                  0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_2_CNTVCT_HI_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_2_ADDR                             (SAILSS_QTMR_QTMR_F2_2_REG_BASE            + 0x10)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_2_OFFS                             (SAILSS_QTMR_QTMR_F2_2_REG_BASE_OFFS + 0x10)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_2_RMSK                             0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_2_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_2_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_2_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_2_CNTFRQ_BMSK                      0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_2_CNTFRQ_SHFT                               0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_2_ADDR                          (SAILSS_QTMR_QTMR_F2_2_REG_BASE            + 0x14)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_2_OFFS                          (SAILSS_QTMR_QTMR_F2_2_REG_BASE_OFFS + 0x14)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_2_RMSK                               0x303
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_2_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_2_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_2_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_2_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_2_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_2_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_2_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_2_PL0CTEN_BMSK                       0x200
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_2_PL0CTEN_SHFT                           9
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_2_PL0VTEN_BMSK                       0x100
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_2_PL0VTEN_SHFT                           8
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_2_PL0VCTEN_BMSK                        0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_2_PL0VCTEN_SHFT                          1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_2_PL0PCTEN_BMSK                        0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_2_PL0PCTEN_SHFT                          0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_2_ADDR                         (SAILSS_QTMR_QTMR_F2_2_REG_BASE            + 0x18)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_2_OFFS                         (SAILSS_QTMR_QTMR_F2_2_REG_BASE_OFFS + 0x18)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_2_RMSK                         0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_2_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_2_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_2_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_2_CNTVOFF_L0_BMSK              0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_2_CNTVOFF_L0_SHFT                       0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_2_ADDR                         (SAILSS_QTMR_QTMR_F2_2_REG_BASE            + 0x1c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_2_OFFS                         (SAILSS_QTMR_QTMR_F2_2_REG_BASE_OFFS + 0x1c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_2_RMSK                           0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_2_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_2_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_2_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_2_CNTVOFF_HI_BMSK                0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_2_CNTVOFF_HI_SHFT                       0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_2_ADDR                       (SAILSS_QTMR_QTMR_F2_2_REG_BASE            + 0x20)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_2_OFFS                       (SAILSS_QTMR_QTMR_F2_2_REG_BASE_OFFS + 0x20)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_2_RMSK                       0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_2_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_2_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_2_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_2_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_2_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_2_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_2_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_2_CNTP_CVAL_L0_BMSK          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_2_CNTP_CVAL_L0_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_2_ADDR                       (SAILSS_QTMR_QTMR_F2_2_REG_BASE            + 0x24)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_2_OFFS                       (SAILSS_QTMR_QTMR_F2_2_REG_BASE_OFFS + 0x24)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_2_RMSK                         0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_2_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_2_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_2_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_2_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_2_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_2_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_2_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_2_CNTP_CVAL_HI_BMSK            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_2_CNTP_CVAL_HI_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_2_ADDR                          (SAILSS_QTMR_QTMR_F2_2_REG_BASE            + 0x28)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_2_OFFS                          (SAILSS_QTMR_QTMR_F2_2_REG_BASE_OFFS + 0x28)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_2_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_2_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_2_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_2_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_2_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_2_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_2_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_2_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_2_CNTP_TVAL_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_2_CNTP_TVAL_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_2_ADDR                           (SAILSS_QTMR_QTMR_F2_2_REG_BASE            + 0x2c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_2_OFFS                           (SAILSS_QTMR_QTMR_F2_2_REG_BASE_OFFS + 0x2c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_2_RMSK                                  0x7
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_2_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_2_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_2_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_2_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_2_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_2_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_2_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_2_ISTAT_BMSK                            0x4
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_2_ISTAT_SHFT                              2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_2_ISTAT_INTERRUPT_NOT_PENDING_FVAL        0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_2_ISTAT_INTERRUPT_PENDING_FVAL          0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_2_IMSK_BMSK                             0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_2_IMSK_SHFT                               1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_2_IMSK_UNMASK_INTERRUPT_FVAL            0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_2_IMSK_MASK_INTERRUPT_FVAL              0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_2_EN_BMSK                               0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_2_EN_SHFT                                 0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_2_EN_DISABLED_FVAL                      0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_2_EN_ENABLED_FVAL                       0x1

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_2_ADDR                       (SAILSS_QTMR_QTMR_F2_2_REG_BASE            + 0x30)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_2_OFFS                       (SAILSS_QTMR_QTMR_F2_2_REG_BASE_OFFS + 0x30)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_2_RMSK                       0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_2_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_2_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_2_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_2_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_2_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_2_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_2_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_2_CNTV_CVAL_L0_BMSK          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_2_CNTV_CVAL_L0_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_2_ADDR                       (SAILSS_QTMR_QTMR_F2_2_REG_BASE            + 0x34)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_2_OFFS                       (SAILSS_QTMR_QTMR_F2_2_REG_BASE_OFFS + 0x34)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_2_RMSK                         0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_2_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_2_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_2_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_2_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_2_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_2_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_2_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_2_CNTV_CVAL_HI_BMSK            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_2_CNTV_CVAL_HI_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_2_ADDR                          (SAILSS_QTMR_QTMR_F2_2_REG_BASE            + 0x38)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_2_OFFS                          (SAILSS_QTMR_QTMR_F2_2_REG_BASE_OFFS + 0x38)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_2_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_2_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_2_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_2_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_2_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_2_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_2_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_2_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_2_CNTV_TVAL_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_2_CNTV_TVAL_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_2_ADDR                           (SAILSS_QTMR_QTMR_F2_2_REG_BASE            + 0x3c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_2_OFFS                           (SAILSS_QTMR_QTMR_F2_2_REG_BASE_OFFS + 0x3c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_2_RMSK                                  0x7
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_2_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_2_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_2_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_2_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_2_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_2_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_2_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_2_ISTAT_BMSK                            0x4
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_2_ISTAT_SHFT                              2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_2_ISTAT_INTERRUPT_NOT_PENDING_FVAL        0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_2_ISTAT_INTERRUPT_PENDING_FVAL          0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_2_IMSK_BMSK                             0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_2_IMSK_SHFT                               1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_2_IMSK_UNMASK_INTERRUPT_FVAL            0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_2_IMSK_MASK_INTERRUPT_FVAL              0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_2_EN_BMSK                               0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_2_EN_SHFT                                 0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_2_EN_DISABLED_FVAL                      0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_2_EN_ENABLED_FVAL                       0x1

#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_2_ADDR                            (SAILSS_QTMR_QTMR_F2_2_REG_BASE            + 0xfd0)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_2_OFFS                            (SAILSS_QTMR_QTMR_F2_2_REG_BASE_OFFS + 0xfd0)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_2_RMSK                            0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_2_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_VERSION_2_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_VERSION_2_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_2_MAJOR_BMSK                      0xf0000000
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_2_MAJOR_SHFT                              28
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_2_MINOR_BMSK                       0xfff0000
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_2_MINOR_SHFT                              16
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_2_STEP_BMSK                           0xffff
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_2_STEP_SHFT                                0

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_QTMR_QTMR_F3_3
 *--------------------------------------------------------------------------*/

#define SAILSS_QTMR_QTMR_F3_3_REG_BASE                                     (SAILSS_QTMR_SAILSS_QTMR_BASE            + 0x00003000)
#define SAILSS_QTMR_QTMR_F3_3_REG_BASE_SIZE                                0x1000
#define SAILSS_QTMR_QTMR_F3_3_REG_BASE_USED                                0xfd0
#define SAILSS_QTMR_QTMR_F3_3_REG_BASE_OFFS                                0x00003000

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_3_ADDR                          (SAILSS_QTMR_QTMR_F3_3_REG_BASE            + 0x0)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_3_OFFS                          (SAILSS_QTMR_QTMR_F3_3_REG_BASE_OFFS + 0x0)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_3_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_3_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_3_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_3_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_3_CNTPCT_LO_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_3_CNTPCT_LO_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_3_ADDR                          (SAILSS_QTMR_QTMR_F3_3_REG_BASE            + 0x4)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_3_OFFS                          (SAILSS_QTMR_QTMR_F3_3_REG_BASE_OFFS + 0x4)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_3_RMSK                            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_3_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_3_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_3_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_3_CNTPCT_HI_BMSK                  0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_3_CNTPCT_HI_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_3_ADDR                          (SAILSS_QTMR_QTMR_F3_3_REG_BASE            + 0x8)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_3_OFFS                          (SAILSS_QTMR_QTMR_F3_3_REG_BASE_OFFS + 0x8)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_3_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_3_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_3_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_3_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_3_CNTVCT_LO_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_3_CNTVCT_LO_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_3_ADDR                          (SAILSS_QTMR_QTMR_F3_3_REG_BASE            + 0xc)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_3_OFFS                          (SAILSS_QTMR_QTMR_F3_3_REG_BASE_OFFS + 0xc)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_3_RMSK                            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_3_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_3_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_3_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_3_CNTVCT_HI_BMSK                  0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_3_CNTVCT_HI_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_3_ADDR                             (SAILSS_QTMR_QTMR_F3_3_REG_BASE            + 0x10)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_3_OFFS                             (SAILSS_QTMR_QTMR_F3_3_REG_BASE_OFFS + 0x10)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_3_RMSK                             0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_3_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_3_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_3_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_3_CNTFRQ_BMSK                      0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_3_CNTFRQ_SHFT                               0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_3_ADDR                          (SAILSS_QTMR_QTMR_F3_3_REG_BASE            + 0x14)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_3_OFFS                          (SAILSS_QTMR_QTMR_F3_3_REG_BASE_OFFS + 0x14)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_3_RMSK                               0x303
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_3_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_3_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_3_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_3_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_3_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_3_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_3_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_3_PL0CTEN_BMSK                       0x200
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_3_PL0CTEN_SHFT                           9
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_3_PL0VTEN_BMSK                       0x100
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_3_PL0VTEN_SHFT                           8
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_3_PL0VCTEN_BMSK                        0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_3_PL0VCTEN_SHFT                          1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_3_PL0PCTEN_BMSK                        0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_3_PL0PCTEN_SHFT                          0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_3_ADDR                         (SAILSS_QTMR_QTMR_F3_3_REG_BASE            + 0x18)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_3_OFFS                         (SAILSS_QTMR_QTMR_F3_3_REG_BASE_OFFS + 0x18)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_3_RMSK                         0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_3_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_3_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_3_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_3_CNTVOFF_L0_BMSK              0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_3_CNTVOFF_L0_SHFT                       0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_3_ADDR                         (SAILSS_QTMR_QTMR_F3_3_REG_BASE            + 0x1c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_3_OFFS                         (SAILSS_QTMR_QTMR_F3_3_REG_BASE_OFFS + 0x1c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_3_RMSK                           0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_3_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_3_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_3_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_3_CNTVOFF_HI_BMSK                0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_3_CNTVOFF_HI_SHFT                       0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_3_ADDR                       (SAILSS_QTMR_QTMR_F3_3_REG_BASE            + 0x20)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_3_OFFS                       (SAILSS_QTMR_QTMR_F3_3_REG_BASE_OFFS + 0x20)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_3_RMSK                       0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_3_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_3_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_3_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_3_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_3_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_3_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_3_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_3_CNTP_CVAL_L0_BMSK          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_3_CNTP_CVAL_L0_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_3_ADDR                       (SAILSS_QTMR_QTMR_F3_3_REG_BASE            + 0x24)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_3_OFFS                       (SAILSS_QTMR_QTMR_F3_3_REG_BASE_OFFS + 0x24)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_3_RMSK                         0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_3_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_3_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_3_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_3_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_3_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_3_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_3_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_3_CNTP_CVAL_HI_BMSK            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_3_CNTP_CVAL_HI_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_3_ADDR                          (SAILSS_QTMR_QTMR_F3_3_REG_BASE            + 0x28)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_3_OFFS                          (SAILSS_QTMR_QTMR_F3_3_REG_BASE_OFFS + 0x28)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_3_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_3_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_3_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_3_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_3_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_3_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_3_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_3_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_3_CNTP_TVAL_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_3_CNTP_TVAL_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_3_ADDR                           (SAILSS_QTMR_QTMR_F3_3_REG_BASE            + 0x2c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_3_OFFS                           (SAILSS_QTMR_QTMR_F3_3_REG_BASE_OFFS + 0x2c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_3_RMSK                                  0x7
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_3_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_3_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_3_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_3_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_3_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_3_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_3_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_3_ISTAT_BMSK                            0x4
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_3_ISTAT_SHFT                              2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_3_ISTAT_INTERRUPT_NOT_PENDING_FVAL        0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_3_ISTAT_INTERRUPT_PENDING_FVAL          0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_3_IMSK_BMSK                             0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_3_IMSK_SHFT                               1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_3_IMSK_UNMASK_INTERRUPT_FVAL            0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_3_IMSK_MASK_INTERRUPT_FVAL              0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_3_EN_BMSK                               0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_3_EN_SHFT                                 0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_3_EN_DISABLED_FVAL                      0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_3_EN_ENABLED_FVAL                       0x1

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_3_ADDR                       (SAILSS_QTMR_QTMR_F3_3_REG_BASE            + 0x30)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_3_OFFS                       (SAILSS_QTMR_QTMR_F3_3_REG_BASE_OFFS + 0x30)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_3_RMSK                       0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_3_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_3_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_3_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_3_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_3_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_3_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_3_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_3_CNTV_CVAL_L0_BMSK          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_3_CNTV_CVAL_L0_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_3_ADDR                       (SAILSS_QTMR_QTMR_F3_3_REG_BASE            + 0x34)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_3_OFFS                       (SAILSS_QTMR_QTMR_F3_3_REG_BASE_OFFS + 0x34)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_3_RMSK                         0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_3_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_3_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_3_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_3_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_3_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_3_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_3_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_3_CNTV_CVAL_HI_BMSK            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_3_CNTV_CVAL_HI_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_3_ADDR                          (SAILSS_QTMR_QTMR_F3_3_REG_BASE            + 0x38)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_3_OFFS                          (SAILSS_QTMR_QTMR_F3_3_REG_BASE_OFFS + 0x38)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_3_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_3_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_3_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_3_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_3_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_3_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_3_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_3_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_3_CNTV_TVAL_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_3_CNTV_TVAL_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_3_ADDR                           (SAILSS_QTMR_QTMR_F3_3_REG_BASE            + 0x3c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_3_OFFS                           (SAILSS_QTMR_QTMR_F3_3_REG_BASE_OFFS + 0x3c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_3_RMSK                                  0x7
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_3_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_3_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_3_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_3_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_3_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_3_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_3_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_3_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_3_ISTAT_BMSK                            0x4
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_3_ISTAT_SHFT                              2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_3_ISTAT_INTERRUPT_NOT_PENDING_FVAL        0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_3_ISTAT_INTERRUPT_PENDING_FVAL          0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_3_IMSK_BMSK                             0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_3_IMSK_SHFT                               1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_3_IMSK_UNMASK_INTERRUPT_FVAL            0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_3_IMSK_MASK_INTERRUPT_FVAL              0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_3_EN_BMSK                               0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_3_EN_SHFT                                 0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_3_EN_DISABLED_FVAL                      0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_3_EN_ENABLED_FVAL                       0x1

#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_3_ADDR                            (SAILSS_QTMR_QTMR_F3_3_REG_BASE            + 0xfd0)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_3_OFFS                            (SAILSS_QTMR_QTMR_F3_3_REG_BASE_OFFS + 0xfd0)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_3_RMSK                            0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_3_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_VERSION_3_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_3_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_VERSION_3_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_3_MAJOR_BMSK                      0xf0000000
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_3_MAJOR_SHFT                              28
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_3_MINOR_BMSK                       0xfff0000
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_3_MINOR_SHFT                              16
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_3_STEP_BMSK                           0xffff
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_3_STEP_SHFT                                0

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_QTMR_QTMR_F4_4
 *--------------------------------------------------------------------------*/

#define SAILSS_QTMR_QTMR_F4_4_REG_BASE                                     (SAILSS_QTMR_SAILSS_QTMR_BASE            + 0x00004000)
#define SAILSS_QTMR_QTMR_F4_4_REG_BASE_SIZE                                0x1000
#define SAILSS_QTMR_QTMR_F4_4_REG_BASE_USED                                0xfd0
#define SAILSS_QTMR_QTMR_F4_4_REG_BASE_OFFS                                0x00004000

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_4_ADDR                          (SAILSS_QTMR_QTMR_F4_4_REG_BASE            + 0x0)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_4_OFFS                          (SAILSS_QTMR_QTMR_F4_4_REG_BASE_OFFS + 0x0)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_4_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_4_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_4_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_4_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_4_CNTPCT_LO_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_4_CNTPCT_LO_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_4_ADDR                          (SAILSS_QTMR_QTMR_F4_4_REG_BASE            + 0x4)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_4_OFFS                          (SAILSS_QTMR_QTMR_F4_4_REG_BASE_OFFS + 0x4)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_4_RMSK                            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_4_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_4_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_4_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_4_CNTPCT_HI_BMSK                  0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_4_CNTPCT_HI_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_4_ADDR                          (SAILSS_QTMR_QTMR_F4_4_REG_BASE            + 0x8)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_4_OFFS                          (SAILSS_QTMR_QTMR_F4_4_REG_BASE_OFFS + 0x8)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_4_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_4_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_4_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_4_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_4_CNTVCT_LO_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_4_CNTVCT_LO_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_4_ADDR                          (SAILSS_QTMR_QTMR_F4_4_REG_BASE            + 0xc)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_4_OFFS                          (SAILSS_QTMR_QTMR_F4_4_REG_BASE_OFFS + 0xc)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_4_RMSK                            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_4_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_4_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_4_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_4_CNTVCT_HI_BMSK                  0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_4_CNTVCT_HI_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_4_ADDR                             (SAILSS_QTMR_QTMR_F4_4_REG_BASE            + 0x10)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_4_OFFS                             (SAILSS_QTMR_QTMR_F4_4_REG_BASE_OFFS + 0x10)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_4_RMSK                             0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_4_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_4_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_4_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_4_CNTFRQ_BMSK                      0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_4_CNTFRQ_SHFT                               0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_4_ADDR                          (SAILSS_QTMR_QTMR_F4_4_REG_BASE            + 0x14)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_4_OFFS                          (SAILSS_QTMR_QTMR_F4_4_REG_BASE_OFFS + 0x14)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_4_RMSK                               0x303
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_4_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_4_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_4_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_4_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_4_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_4_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_4_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_4_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_4_PL0CTEN_BMSK                       0x200
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_4_PL0CTEN_SHFT                           9
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_4_PL0VTEN_BMSK                       0x100
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_4_PL0VTEN_SHFT                           8
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_4_PL0VCTEN_BMSK                        0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_4_PL0VCTEN_SHFT                          1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_4_PL0PCTEN_BMSK                        0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_4_PL0PCTEN_SHFT                          0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_4_ADDR                         (SAILSS_QTMR_QTMR_F4_4_REG_BASE            + 0x18)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_4_OFFS                         (SAILSS_QTMR_QTMR_F4_4_REG_BASE_OFFS + 0x18)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_4_RMSK                         0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_4_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_4_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_4_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_4_CNTVOFF_L0_BMSK              0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_4_CNTVOFF_L0_SHFT                       0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_4_ADDR                         (SAILSS_QTMR_QTMR_F4_4_REG_BASE            + 0x1c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_4_OFFS                         (SAILSS_QTMR_QTMR_F4_4_REG_BASE_OFFS + 0x1c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_4_RMSK                           0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_4_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_4_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_4_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_4_CNTVOFF_HI_BMSK                0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_4_CNTVOFF_HI_SHFT                       0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_4_ADDR                       (SAILSS_QTMR_QTMR_F4_4_REG_BASE            + 0x20)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_4_OFFS                       (SAILSS_QTMR_QTMR_F4_4_REG_BASE_OFFS + 0x20)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_4_RMSK                       0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_4_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_4_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_4_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_4_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_4_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_4_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_4_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_4_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_4_CNTP_CVAL_L0_BMSK          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_4_CNTP_CVAL_L0_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_4_ADDR                       (SAILSS_QTMR_QTMR_F4_4_REG_BASE            + 0x24)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_4_OFFS                       (SAILSS_QTMR_QTMR_F4_4_REG_BASE_OFFS + 0x24)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_4_RMSK                         0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_4_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_4_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_4_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_4_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_4_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_4_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_4_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_4_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_4_CNTP_CVAL_HI_BMSK            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_4_CNTP_CVAL_HI_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_4_ADDR                          (SAILSS_QTMR_QTMR_F4_4_REG_BASE            + 0x28)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_4_OFFS                          (SAILSS_QTMR_QTMR_F4_4_REG_BASE_OFFS + 0x28)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_4_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_4_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_4_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_4_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_4_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_4_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_4_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_4_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_4_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_4_CNTP_TVAL_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_4_CNTP_TVAL_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_4_ADDR                           (SAILSS_QTMR_QTMR_F4_4_REG_BASE            + 0x2c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_4_OFFS                           (SAILSS_QTMR_QTMR_F4_4_REG_BASE_OFFS + 0x2c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_4_RMSK                                  0x7
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_4_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_4_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_4_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_4_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_4_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_4_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_4_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_4_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_4_ISTAT_BMSK                            0x4
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_4_ISTAT_SHFT                              2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_4_ISTAT_INTERRUPT_NOT_PENDING_FVAL        0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_4_ISTAT_INTERRUPT_PENDING_FVAL          0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_4_IMSK_BMSK                             0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_4_IMSK_SHFT                               1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_4_IMSK_UNMASK_INTERRUPT_FVAL            0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_4_IMSK_MASK_INTERRUPT_FVAL              0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_4_EN_BMSK                               0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_4_EN_SHFT                                 0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_4_EN_DISABLED_FVAL                      0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_4_EN_ENABLED_FVAL                       0x1

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_4_ADDR                       (SAILSS_QTMR_QTMR_F4_4_REG_BASE            + 0x30)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_4_OFFS                       (SAILSS_QTMR_QTMR_F4_4_REG_BASE_OFFS + 0x30)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_4_RMSK                       0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_4_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_4_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_4_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_4_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_4_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_4_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_4_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_4_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_4_CNTV_CVAL_L0_BMSK          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_4_CNTV_CVAL_L0_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_4_ADDR                       (SAILSS_QTMR_QTMR_F4_4_REG_BASE            + 0x34)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_4_OFFS                       (SAILSS_QTMR_QTMR_F4_4_REG_BASE_OFFS + 0x34)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_4_RMSK                         0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_4_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_4_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_4_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_4_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_4_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_4_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_4_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_4_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_4_CNTV_CVAL_HI_BMSK            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_4_CNTV_CVAL_HI_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_4_ADDR                          (SAILSS_QTMR_QTMR_F4_4_REG_BASE            + 0x38)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_4_OFFS                          (SAILSS_QTMR_QTMR_F4_4_REG_BASE_OFFS + 0x38)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_4_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_4_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_4_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_4_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_4_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_4_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_4_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_4_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_4_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_4_CNTV_TVAL_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_4_CNTV_TVAL_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_4_ADDR                           (SAILSS_QTMR_QTMR_F4_4_REG_BASE            + 0x3c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_4_OFFS                           (SAILSS_QTMR_QTMR_F4_4_REG_BASE_OFFS + 0x3c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_4_RMSK                                  0x7
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_4_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_4_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_4_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_4_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_4_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_4_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_4_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_4_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_4_ISTAT_BMSK                            0x4
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_4_ISTAT_SHFT                              2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_4_ISTAT_INTERRUPT_NOT_PENDING_FVAL        0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_4_ISTAT_INTERRUPT_PENDING_FVAL          0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_4_IMSK_BMSK                             0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_4_IMSK_SHFT                               1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_4_IMSK_UNMASK_INTERRUPT_FVAL            0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_4_IMSK_MASK_INTERRUPT_FVAL              0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_4_EN_BMSK                               0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_4_EN_SHFT                                 0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_4_EN_DISABLED_FVAL                      0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_4_EN_ENABLED_FVAL                       0x1

#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_4_ADDR                            (SAILSS_QTMR_QTMR_F4_4_REG_BASE            + 0xfd0)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_4_OFFS                            (SAILSS_QTMR_QTMR_F4_4_REG_BASE_OFFS + 0xfd0)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_4_RMSK                            0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_4_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_VERSION_4_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_4_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_VERSION_4_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_4_MAJOR_BMSK                      0xf0000000
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_4_MAJOR_SHFT                              28
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_4_MINOR_BMSK                       0xfff0000
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_4_MINOR_SHFT                              16
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_4_STEP_BMSK                           0xffff
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_4_STEP_SHFT                                0

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_QTMR_QTMR_F5_5
 *--------------------------------------------------------------------------*/

#define SAILSS_QTMR_QTMR_F5_5_REG_BASE                                     (SAILSS_QTMR_SAILSS_QTMR_BASE            + 0x00005000)
#define SAILSS_QTMR_QTMR_F5_5_REG_BASE_SIZE                                0x1000
#define SAILSS_QTMR_QTMR_F5_5_REG_BASE_USED                                0xfd0
#define SAILSS_QTMR_QTMR_F5_5_REG_BASE_OFFS                                0x00005000

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_5_ADDR                          (SAILSS_QTMR_QTMR_F5_5_REG_BASE            + 0x0)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_5_OFFS                          (SAILSS_QTMR_QTMR_F5_5_REG_BASE_OFFS + 0x0)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_5_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_5_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_5_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_5_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_5_CNTPCT_LO_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_5_CNTPCT_LO_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_5_ADDR                          (SAILSS_QTMR_QTMR_F5_5_REG_BASE            + 0x4)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_5_OFFS                          (SAILSS_QTMR_QTMR_F5_5_REG_BASE_OFFS + 0x4)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_5_RMSK                            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_5_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_5_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_5_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_5_CNTPCT_HI_BMSK                  0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_5_CNTPCT_HI_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_5_ADDR                          (SAILSS_QTMR_QTMR_F5_5_REG_BASE            + 0x8)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_5_OFFS                          (SAILSS_QTMR_QTMR_F5_5_REG_BASE_OFFS + 0x8)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_5_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_5_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_5_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_5_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_5_CNTVCT_LO_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_5_CNTVCT_LO_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_5_ADDR                          (SAILSS_QTMR_QTMR_F5_5_REG_BASE            + 0xc)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_5_OFFS                          (SAILSS_QTMR_QTMR_F5_5_REG_BASE_OFFS + 0xc)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_5_RMSK                            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_5_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_5_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_5_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_5_CNTVCT_HI_BMSK                  0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_5_CNTVCT_HI_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_5_ADDR                             (SAILSS_QTMR_QTMR_F5_5_REG_BASE            + 0x10)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_5_OFFS                             (SAILSS_QTMR_QTMR_F5_5_REG_BASE_OFFS + 0x10)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_5_RMSK                             0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_5_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_5_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_5_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_5_CNTFRQ_BMSK                      0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_5_CNTFRQ_SHFT                               0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_5_ADDR                          (SAILSS_QTMR_QTMR_F5_5_REG_BASE            + 0x14)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_5_OFFS                          (SAILSS_QTMR_QTMR_F5_5_REG_BASE_OFFS + 0x14)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_5_RMSK                               0x303
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_5_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_5_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_5_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_5_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_5_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_5_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_5_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_5_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_5_PL0CTEN_BMSK                       0x200
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_5_PL0CTEN_SHFT                           9
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_5_PL0VTEN_BMSK                       0x100
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_5_PL0VTEN_SHFT                           8
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_5_PL0VCTEN_BMSK                        0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_5_PL0VCTEN_SHFT                          1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_5_PL0PCTEN_BMSK                        0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_5_PL0PCTEN_SHFT                          0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_5_ADDR                         (SAILSS_QTMR_QTMR_F5_5_REG_BASE            + 0x18)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_5_OFFS                         (SAILSS_QTMR_QTMR_F5_5_REG_BASE_OFFS + 0x18)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_5_RMSK                         0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_5_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_5_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_5_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_5_CNTVOFF_L0_BMSK              0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_5_CNTVOFF_L0_SHFT                       0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_5_ADDR                         (SAILSS_QTMR_QTMR_F5_5_REG_BASE            + 0x1c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_5_OFFS                         (SAILSS_QTMR_QTMR_F5_5_REG_BASE_OFFS + 0x1c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_5_RMSK                           0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_5_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_5_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_5_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_5_CNTVOFF_HI_BMSK                0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_5_CNTVOFF_HI_SHFT                       0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_5_ADDR                       (SAILSS_QTMR_QTMR_F5_5_REG_BASE            + 0x20)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_5_OFFS                       (SAILSS_QTMR_QTMR_F5_5_REG_BASE_OFFS + 0x20)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_5_RMSK                       0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_5_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_5_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_5_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_5_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_5_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_5_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_5_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_5_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_5_CNTP_CVAL_L0_BMSK          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_5_CNTP_CVAL_L0_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_5_ADDR                       (SAILSS_QTMR_QTMR_F5_5_REG_BASE            + 0x24)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_5_OFFS                       (SAILSS_QTMR_QTMR_F5_5_REG_BASE_OFFS + 0x24)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_5_RMSK                         0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_5_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_5_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_5_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_5_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_5_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_5_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_5_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_5_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_5_CNTP_CVAL_HI_BMSK            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_5_CNTP_CVAL_HI_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_5_ADDR                          (SAILSS_QTMR_QTMR_F5_5_REG_BASE            + 0x28)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_5_OFFS                          (SAILSS_QTMR_QTMR_F5_5_REG_BASE_OFFS + 0x28)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_5_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_5_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_5_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_5_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_5_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_5_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_5_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_5_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_5_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_5_CNTP_TVAL_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_5_CNTP_TVAL_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_5_ADDR                           (SAILSS_QTMR_QTMR_F5_5_REG_BASE            + 0x2c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_5_OFFS                           (SAILSS_QTMR_QTMR_F5_5_REG_BASE_OFFS + 0x2c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_5_RMSK                                  0x7
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_5_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_5_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_5_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_5_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_5_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_5_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_5_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_5_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_5_ISTAT_BMSK                            0x4
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_5_ISTAT_SHFT                              2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_5_ISTAT_INTERRUPT_NOT_PENDING_FVAL        0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_5_ISTAT_INTERRUPT_PENDING_FVAL          0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_5_IMSK_BMSK                             0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_5_IMSK_SHFT                               1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_5_IMSK_UNMASK_INTERRUPT_FVAL            0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_5_IMSK_MASK_INTERRUPT_FVAL              0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_5_EN_BMSK                               0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_5_EN_SHFT                                 0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_5_EN_DISABLED_FVAL                      0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_5_EN_ENABLED_FVAL                       0x1

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_5_ADDR                       (SAILSS_QTMR_QTMR_F5_5_REG_BASE            + 0x30)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_5_OFFS                       (SAILSS_QTMR_QTMR_F5_5_REG_BASE_OFFS + 0x30)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_5_RMSK                       0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_5_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_5_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_5_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_5_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_5_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_5_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_5_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_5_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_5_CNTV_CVAL_L0_BMSK          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_5_CNTV_CVAL_L0_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_5_ADDR                       (SAILSS_QTMR_QTMR_F5_5_REG_BASE            + 0x34)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_5_OFFS                       (SAILSS_QTMR_QTMR_F5_5_REG_BASE_OFFS + 0x34)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_5_RMSK                         0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_5_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_5_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_5_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_5_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_5_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_5_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_5_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_5_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_5_CNTV_CVAL_HI_BMSK            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_5_CNTV_CVAL_HI_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_5_ADDR                          (SAILSS_QTMR_QTMR_F5_5_REG_BASE            + 0x38)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_5_OFFS                          (SAILSS_QTMR_QTMR_F5_5_REG_BASE_OFFS + 0x38)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_5_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_5_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_5_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_5_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_5_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_5_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_5_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_5_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_5_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_5_CNTV_TVAL_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_5_CNTV_TVAL_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_5_ADDR                           (SAILSS_QTMR_QTMR_F5_5_REG_BASE            + 0x3c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_5_OFFS                           (SAILSS_QTMR_QTMR_F5_5_REG_BASE_OFFS + 0x3c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_5_RMSK                                  0x7
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_5_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_5_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_5_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_5_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_5_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_5_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_5_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_5_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_5_ISTAT_BMSK                            0x4
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_5_ISTAT_SHFT                              2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_5_ISTAT_INTERRUPT_NOT_PENDING_FVAL        0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_5_ISTAT_INTERRUPT_PENDING_FVAL          0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_5_IMSK_BMSK                             0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_5_IMSK_SHFT                               1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_5_IMSK_UNMASK_INTERRUPT_FVAL            0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_5_IMSK_MASK_INTERRUPT_FVAL              0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_5_EN_BMSK                               0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_5_EN_SHFT                                 0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_5_EN_DISABLED_FVAL                      0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_5_EN_ENABLED_FVAL                       0x1

#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_5_ADDR                            (SAILSS_QTMR_QTMR_F5_5_REG_BASE            + 0xfd0)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_5_OFFS                            (SAILSS_QTMR_QTMR_F5_5_REG_BASE_OFFS + 0xfd0)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_5_RMSK                            0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_5_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_VERSION_5_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_5_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_VERSION_5_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_5_MAJOR_BMSK                      0xf0000000
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_5_MAJOR_SHFT                              28
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_5_MINOR_BMSK                       0xfff0000
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_5_MINOR_SHFT                              16
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_5_STEP_BMSK                           0xffff
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_5_STEP_SHFT                                0

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_QTMR_QTMR_F6_6
 *--------------------------------------------------------------------------*/

#define SAILSS_QTMR_QTMR_F6_6_REG_BASE                                     (SAILSS_QTMR_SAILSS_QTMR_BASE            + 0x00006000)
#define SAILSS_QTMR_QTMR_F6_6_REG_BASE_SIZE                                0x1000
#define SAILSS_QTMR_QTMR_F6_6_REG_BASE_USED                                0xfd0
#define SAILSS_QTMR_QTMR_F6_6_REG_BASE_OFFS                                0x00006000

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_6_ADDR                          (SAILSS_QTMR_QTMR_F6_6_REG_BASE            + 0x0)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_6_OFFS                          (SAILSS_QTMR_QTMR_F6_6_REG_BASE_OFFS + 0x0)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_6_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_6_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_6_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_6_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_6_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_6_CNTPCT_LO_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_6_CNTPCT_LO_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_6_ADDR                          (SAILSS_QTMR_QTMR_F6_6_REG_BASE            + 0x4)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_6_OFFS                          (SAILSS_QTMR_QTMR_F6_6_REG_BASE_OFFS + 0x4)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_6_RMSK                            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_6_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_6_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_6_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_6_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_6_CNTPCT_HI_BMSK                  0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_6_CNTPCT_HI_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_6_ADDR                          (SAILSS_QTMR_QTMR_F6_6_REG_BASE            + 0x8)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_6_OFFS                          (SAILSS_QTMR_QTMR_F6_6_REG_BASE_OFFS + 0x8)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_6_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_6_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_6_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_6_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_6_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_6_CNTVCT_LO_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_6_CNTVCT_LO_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_6_ADDR                          (SAILSS_QTMR_QTMR_F6_6_REG_BASE            + 0xc)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_6_OFFS                          (SAILSS_QTMR_QTMR_F6_6_REG_BASE_OFFS + 0xc)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_6_RMSK                            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_6_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_6_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_6_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_6_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_6_CNTVCT_HI_BMSK                  0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_6_CNTVCT_HI_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_6_ADDR                             (SAILSS_QTMR_QTMR_F6_6_REG_BASE            + 0x10)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_6_OFFS                             (SAILSS_QTMR_QTMR_F6_6_REG_BASE_OFFS + 0x10)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_6_RMSK                             0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_6_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_6_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_6_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_6_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_6_CNTFRQ_BMSK                      0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_6_CNTFRQ_SHFT                               0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_6_ADDR                          (SAILSS_QTMR_QTMR_F6_6_REG_BASE            + 0x14)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_6_OFFS                          (SAILSS_QTMR_QTMR_F6_6_REG_BASE_OFFS + 0x14)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_6_RMSK                               0x303
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_6_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_6_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_6_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_6_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_6_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_6_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_6_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_6_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_6_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_6_PL0CTEN_BMSK                       0x200
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_6_PL0CTEN_SHFT                           9
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_6_PL0VTEN_BMSK                       0x100
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_6_PL0VTEN_SHFT                           8
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_6_PL0VCTEN_BMSK                        0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_6_PL0VCTEN_SHFT                          1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_6_PL0PCTEN_BMSK                        0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_6_PL0PCTEN_SHFT                          0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_6_ADDR                         (SAILSS_QTMR_QTMR_F6_6_REG_BASE            + 0x18)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_6_OFFS                         (SAILSS_QTMR_QTMR_F6_6_REG_BASE_OFFS + 0x18)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_6_RMSK                         0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_6_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_6_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_6_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_6_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_6_CNTVOFF_L0_BMSK              0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_6_CNTVOFF_L0_SHFT                       0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_6_ADDR                         (SAILSS_QTMR_QTMR_F6_6_REG_BASE            + 0x1c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_6_OFFS                         (SAILSS_QTMR_QTMR_F6_6_REG_BASE_OFFS + 0x1c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_6_RMSK                           0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_6_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_6_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_6_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_6_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_6_CNTVOFF_HI_BMSK                0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_6_CNTVOFF_HI_SHFT                       0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_6_ADDR                       (SAILSS_QTMR_QTMR_F6_6_REG_BASE            + 0x20)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_6_OFFS                       (SAILSS_QTMR_QTMR_F6_6_REG_BASE_OFFS + 0x20)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_6_RMSK                       0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_6_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_6_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_6_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_6_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_6_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_6_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_6_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_6_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_6_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_6_CNTP_CVAL_L0_BMSK          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_6_CNTP_CVAL_L0_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_6_ADDR                       (SAILSS_QTMR_QTMR_F6_6_REG_BASE            + 0x24)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_6_OFFS                       (SAILSS_QTMR_QTMR_F6_6_REG_BASE_OFFS + 0x24)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_6_RMSK                         0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_6_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_6_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_6_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_6_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_6_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_6_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_6_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_6_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_6_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_6_CNTP_CVAL_HI_BMSK            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_6_CNTP_CVAL_HI_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_6_ADDR                          (SAILSS_QTMR_QTMR_F6_6_REG_BASE            + 0x28)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_6_OFFS                          (SAILSS_QTMR_QTMR_F6_6_REG_BASE_OFFS + 0x28)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_6_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_6_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_6_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_6_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_6_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_6_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_6_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_6_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_6_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_6_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_6_CNTP_TVAL_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_6_CNTP_TVAL_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_6_ADDR                           (SAILSS_QTMR_QTMR_F6_6_REG_BASE            + 0x2c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_6_OFFS                           (SAILSS_QTMR_QTMR_F6_6_REG_BASE_OFFS + 0x2c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_6_RMSK                                  0x7
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_6_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_6_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_6_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_6_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_6_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_6_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_6_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_6_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_6_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_6_ISTAT_BMSK                            0x4
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_6_ISTAT_SHFT                              2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_6_ISTAT_INTERRUPT_NOT_PENDING_FVAL        0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_6_ISTAT_INTERRUPT_PENDING_FVAL          0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_6_IMSK_BMSK                             0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_6_IMSK_SHFT                               1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_6_IMSK_UNMASK_INTERRUPT_FVAL            0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_6_IMSK_MASK_INTERRUPT_FVAL              0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_6_EN_BMSK                               0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_6_EN_SHFT                                 0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_6_EN_DISABLED_FVAL                      0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_6_EN_ENABLED_FVAL                       0x1

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_6_ADDR                       (SAILSS_QTMR_QTMR_F6_6_REG_BASE            + 0x30)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_6_OFFS                       (SAILSS_QTMR_QTMR_F6_6_REG_BASE_OFFS + 0x30)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_6_RMSK                       0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_6_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_6_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_6_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_6_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_6_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_6_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_6_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_6_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_6_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_6_CNTV_CVAL_L0_BMSK          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_6_CNTV_CVAL_L0_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_6_ADDR                       (SAILSS_QTMR_QTMR_F6_6_REG_BASE            + 0x34)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_6_OFFS                       (SAILSS_QTMR_QTMR_F6_6_REG_BASE_OFFS + 0x34)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_6_RMSK                         0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_6_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_6_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_6_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_6_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_6_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_6_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_6_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_6_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_6_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_6_CNTV_CVAL_HI_BMSK            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_6_CNTV_CVAL_HI_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_6_ADDR                          (SAILSS_QTMR_QTMR_F6_6_REG_BASE            + 0x38)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_6_OFFS                          (SAILSS_QTMR_QTMR_F6_6_REG_BASE_OFFS + 0x38)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_6_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_6_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_6_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_6_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_6_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_6_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_6_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_6_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_6_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_6_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_6_CNTV_TVAL_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_6_CNTV_TVAL_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_6_ADDR                           (SAILSS_QTMR_QTMR_F6_6_REG_BASE            + 0x3c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_6_OFFS                           (SAILSS_QTMR_QTMR_F6_6_REG_BASE_OFFS + 0x3c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_6_RMSK                                  0x7
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_6_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_6_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_6_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_6_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_6_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_6_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_6_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_6_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_6_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_6_ISTAT_BMSK                            0x4
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_6_ISTAT_SHFT                              2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_6_ISTAT_INTERRUPT_NOT_PENDING_FVAL        0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_6_ISTAT_INTERRUPT_PENDING_FVAL          0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_6_IMSK_BMSK                             0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_6_IMSK_SHFT                               1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_6_IMSK_UNMASK_INTERRUPT_FVAL            0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_6_IMSK_MASK_INTERRUPT_FVAL              0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_6_EN_BMSK                               0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_6_EN_SHFT                                 0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_6_EN_DISABLED_FVAL                      0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_6_EN_ENABLED_FVAL                       0x1

#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_6_ADDR                            (SAILSS_QTMR_QTMR_F6_6_REG_BASE            + 0xfd0)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_6_OFFS                            (SAILSS_QTMR_QTMR_F6_6_REG_BASE_OFFS + 0xfd0)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_6_RMSK                            0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_6_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_VERSION_6_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_6_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_VERSION_6_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_6_MAJOR_BMSK                      0xf0000000
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_6_MAJOR_SHFT                              28
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_6_MINOR_BMSK                       0xfff0000
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_6_MINOR_SHFT                              16
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_6_STEP_BMSK                           0xffff
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_6_STEP_SHFT                                0

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_QTMR_QTMR_F7_7
 *--------------------------------------------------------------------------*/

#define SAILSS_QTMR_QTMR_F7_7_REG_BASE                                     (SAILSS_QTMR_SAILSS_QTMR_BASE            + 0x00007000)
#define SAILSS_QTMR_QTMR_F7_7_REG_BASE_SIZE                                0x1000
#define SAILSS_QTMR_QTMR_F7_7_REG_BASE_USED                                0xfd0
#define SAILSS_QTMR_QTMR_F7_7_REG_BASE_OFFS                                0x00007000

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_7_ADDR                          (SAILSS_QTMR_QTMR_F7_7_REG_BASE            + 0x0)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_7_OFFS                          (SAILSS_QTMR_QTMR_F7_7_REG_BASE_OFFS + 0x0)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_7_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_7_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_7_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_7_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_7_CNTPCT_LO_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_7_CNTPCT_LO_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_7_ADDR                          (SAILSS_QTMR_QTMR_F7_7_REG_BASE            + 0x4)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_7_OFFS                          (SAILSS_QTMR_QTMR_F7_7_REG_BASE_OFFS + 0x4)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_7_RMSK                            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_7_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_7_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_7_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_7_CNTPCT_HI_BMSK                  0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_7_CNTPCT_HI_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_7_ADDR                          (SAILSS_QTMR_QTMR_F7_7_REG_BASE            + 0x8)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_7_OFFS                          (SAILSS_QTMR_QTMR_F7_7_REG_BASE_OFFS + 0x8)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_7_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_7_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_7_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_7_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_7_CNTVCT_LO_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_7_CNTVCT_LO_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_7_ADDR                          (SAILSS_QTMR_QTMR_F7_7_REG_BASE            + 0xc)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_7_OFFS                          (SAILSS_QTMR_QTMR_F7_7_REG_BASE_OFFS + 0xc)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_7_RMSK                            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_7_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_7_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_7_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_7_CNTVCT_HI_BMSK                  0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_7_CNTVCT_HI_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_7_ADDR                             (SAILSS_QTMR_QTMR_F7_7_REG_BASE            + 0x10)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_7_OFFS                             (SAILSS_QTMR_QTMR_F7_7_REG_BASE_OFFS + 0x10)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_7_RMSK                             0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_7_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_7_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_7_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_7_CNTFRQ_BMSK                      0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_7_CNTFRQ_SHFT                               0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_7_ADDR                          (SAILSS_QTMR_QTMR_F7_7_REG_BASE            + 0x14)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_7_OFFS                          (SAILSS_QTMR_QTMR_F7_7_REG_BASE_OFFS + 0x14)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_7_RMSK                               0x303
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_7_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_7_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_7_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_7_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_7_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_7_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_7_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_7_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_7_PL0CTEN_BMSK                       0x200
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_7_PL0CTEN_SHFT                           9
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_7_PL0VTEN_BMSK                       0x100
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_7_PL0VTEN_SHFT                           8
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_7_PL0VCTEN_BMSK                        0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_7_PL0VCTEN_SHFT                          1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_7_PL0PCTEN_BMSK                        0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_7_PL0PCTEN_SHFT                          0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_7_ADDR                         (SAILSS_QTMR_QTMR_F7_7_REG_BASE            + 0x18)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_7_OFFS                         (SAILSS_QTMR_QTMR_F7_7_REG_BASE_OFFS + 0x18)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_7_RMSK                         0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_7_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_7_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_7_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_7_CNTVOFF_L0_BMSK              0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_7_CNTVOFF_L0_SHFT                       0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_7_ADDR                         (SAILSS_QTMR_QTMR_F7_7_REG_BASE            + 0x1c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_7_OFFS                         (SAILSS_QTMR_QTMR_F7_7_REG_BASE_OFFS + 0x1c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_7_RMSK                           0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_7_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_7_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_7_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_7_CNTVOFF_HI_BMSK                0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_7_CNTVOFF_HI_SHFT                       0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_7_ADDR                       (SAILSS_QTMR_QTMR_F7_7_REG_BASE            + 0x20)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_7_OFFS                       (SAILSS_QTMR_QTMR_F7_7_REG_BASE_OFFS + 0x20)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_7_RMSK                       0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_7_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_7_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_7_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_7_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_7_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_7_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_7_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_7_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_7_CNTP_CVAL_L0_BMSK          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_7_CNTP_CVAL_L0_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_7_ADDR                       (SAILSS_QTMR_QTMR_F7_7_REG_BASE            + 0x24)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_7_OFFS                       (SAILSS_QTMR_QTMR_F7_7_REG_BASE_OFFS + 0x24)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_7_RMSK                         0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_7_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_7_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_7_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_7_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_7_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_7_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_7_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_7_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_7_CNTP_CVAL_HI_BMSK            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_7_CNTP_CVAL_HI_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_7_ADDR                          (SAILSS_QTMR_QTMR_F7_7_REG_BASE            + 0x28)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_7_OFFS                          (SAILSS_QTMR_QTMR_F7_7_REG_BASE_OFFS + 0x28)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_7_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_7_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_7_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_7_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_7_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_7_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_7_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_7_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_7_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_7_CNTP_TVAL_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_7_CNTP_TVAL_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_7_ADDR                           (SAILSS_QTMR_QTMR_F7_7_REG_BASE            + 0x2c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_7_OFFS                           (SAILSS_QTMR_QTMR_F7_7_REG_BASE_OFFS + 0x2c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_7_RMSK                                  0x7
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_7_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_7_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_7_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_7_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_7_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_7_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_7_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_7_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_7_ISTAT_BMSK                            0x4
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_7_ISTAT_SHFT                              2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_7_ISTAT_INTERRUPT_NOT_PENDING_FVAL        0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_7_ISTAT_INTERRUPT_PENDING_FVAL          0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_7_IMSK_BMSK                             0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_7_IMSK_SHFT                               1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_7_IMSK_UNMASK_INTERRUPT_FVAL            0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_7_IMSK_MASK_INTERRUPT_FVAL              0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_7_EN_BMSK                               0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_7_EN_SHFT                                 0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_7_EN_DISABLED_FVAL                      0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_7_EN_ENABLED_FVAL                       0x1

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_7_ADDR                       (SAILSS_QTMR_QTMR_F7_7_REG_BASE            + 0x30)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_7_OFFS                       (SAILSS_QTMR_QTMR_F7_7_REG_BASE_OFFS + 0x30)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_7_RMSK                       0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_7_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_7_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_7_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_7_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_7_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_7_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_7_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_7_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_7_CNTV_CVAL_L0_BMSK          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_7_CNTV_CVAL_L0_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_7_ADDR                       (SAILSS_QTMR_QTMR_F7_7_REG_BASE            + 0x34)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_7_OFFS                       (SAILSS_QTMR_QTMR_F7_7_REG_BASE_OFFS + 0x34)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_7_RMSK                         0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_7_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_7_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_7_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_7_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_7_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_7_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_7_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_7_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_7_CNTV_CVAL_HI_BMSK            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_7_CNTV_CVAL_HI_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_7_ADDR                          (SAILSS_QTMR_QTMR_F7_7_REG_BASE            + 0x38)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_7_OFFS                          (SAILSS_QTMR_QTMR_F7_7_REG_BASE_OFFS + 0x38)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_7_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_7_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_7_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_7_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_7_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_7_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_7_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_7_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_7_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_7_CNTV_TVAL_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_7_CNTV_TVAL_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_7_ADDR                           (SAILSS_QTMR_QTMR_F7_7_REG_BASE            + 0x3c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_7_OFFS                           (SAILSS_QTMR_QTMR_F7_7_REG_BASE_OFFS + 0x3c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_7_RMSK                                  0x7
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_7_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_7_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_7_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_7_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_7_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_7_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_7_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_7_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_7_ISTAT_BMSK                            0x4
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_7_ISTAT_SHFT                              2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_7_ISTAT_INTERRUPT_NOT_PENDING_FVAL        0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_7_ISTAT_INTERRUPT_PENDING_FVAL          0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_7_IMSK_BMSK                             0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_7_IMSK_SHFT                               1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_7_IMSK_UNMASK_INTERRUPT_FVAL            0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_7_IMSK_MASK_INTERRUPT_FVAL              0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_7_EN_BMSK                               0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_7_EN_SHFT                                 0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_7_EN_DISABLED_FVAL                      0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_7_EN_ENABLED_FVAL                       0x1

#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_7_ADDR                            (SAILSS_QTMR_QTMR_F7_7_REG_BASE            + 0xfd0)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_7_OFFS                            (SAILSS_QTMR_QTMR_F7_7_REG_BASE_OFFS + 0xfd0)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_7_RMSK                            0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_7_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_VERSION_7_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_7_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_VERSION_7_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_7_MAJOR_BMSK                      0xf0000000
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_7_MAJOR_SHFT                              28
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_7_MINOR_BMSK                       0xfff0000
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_7_MINOR_SHFT                              16
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_7_STEP_BMSK                           0xffff
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_7_STEP_SHFT                                0

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_QTMR_QTMR_F8_8
 *--------------------------------------------------------------------------*/

#define SAILSS_QTMR_QTMR_F8_8_REG_BASE                                     (SAILSS_QTMR_SAILSS_QTMR_BASE            + 0x00008000)
#define SAILSS_QTMR_QTMR_F8_8_REG_BASE_SIZE                                0x1000
#define SAILSS_QTMR_QTMR_F8_8_REG_BASE_USED                                0xfd0
#define SAILSS_QTMR_QTMR_F8_8_REG_BASE_OFFS                                0x00008000

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_8_ADDR                          (SAILSS_QTMR_QTMR_F8_8_REG_BASE            + 0x0)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_8_OFFS                          (SAILSS_QTMR_QTMR_F8_8_REG_BASE_OFFS + 0x0)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_8_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_8_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_8_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_8_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_8_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_8_CNTPCT_LO_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_8_CNTPCT_LO_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_8_ADDR                          (SAILSS_QTMR_QTMR_F8_8_REG_BASE            + 0x4)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_8_OFFS                          (SAILSS_QTMR_QTMR_F8_8_REG_BASE_OFFS + 0x4)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_8_RMSK                            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_8_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_8_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_8_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_8_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_8_CNTPCT_HI_BMSK                  0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_8_CNTPCT_HI_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_8_ADDR                          (SAILSS_QTMR_QTMR_F8_8_REG_BASE            + 0x8)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_8_OFFS                          (SAILSS_QTMR_QTMR_F8_8_REG_BASE_OFFS + 0x8)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_8_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_8_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_8_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_8_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_8_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_8_CNTVCT_LO_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_8_CNTVCT_LO_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_8_ADDR                          (SAILSS_QTMR_QTMR_F8_8_REG_BASE            + 0xc)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_8_OFFS                          (SAILSS_QTMR_QTMR_F8_8_REG_BASE_OFFS + 0xc)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_8_RMSK                            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_8_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_8_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_8_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_8_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_8_CNTVCT_HI_BMSK                  0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_8_CNTVCT_HI_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_8_ADDR                             (SAILSS_QTMR_QTMR_F8_8_REG_BASE            + 0x10)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_8_OFFS                             (SAILSS_QTMR_QTMR_F8_8_REG_BASE_OFFS + 0x10)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_8_RMSK                             0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_8_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_8_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_8_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_8_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_8_CNTFRQ_BMSK                      0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_8_CNTFRQ_SHFT                               0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_8_ADDR                          (SAILSS_QTMR_QTMR_F8_8_REG_BASE            + 0x14)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_8_OFFS                          (SAILSS_QTMR_QTMR_F8_8_REG_BASE_OFFS + 0x14)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_8_RMSK                               0x303
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_8_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_8_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_8_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_8_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_8_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_8_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_8_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_8_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_8_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_8_PL0CTEN_BMSK                       0x200
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_8_PL0CTEN_SHFT                           9
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_8_PL0VTEN_BMSK                       0x100
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_8_PL0VTEN_SHFT                           8
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_8_PL0VCTEN_BMSK                        0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_8_PL0VCTEN_SHFT                          1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_8_PL0PCTEN_BMSK                        0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_8_PL0PCTEN_SHFT                          0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_8_ADDR                         (SAILSS_QTMR_QTMR_F8_8_REG_BASE            + 0x18)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_8_OFFS                         (SAILSS_QTMR_QTMR_F8_8_REG_BASE_OFFS + 0x18)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_8_RMSK                         0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_8_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_8_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_8_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_8_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_8_CNTVOFF_L0_BMSK              0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_8_CNTVOFF_L0_SHFT                       0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_8_ADDR                         (SAILSS_QTMR_QTMR_F8_8_REG_BASE            + 0x1c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_8_OFFS                         (SAILSS_QTMR_QTMR_F8_8_REG_BASE_OFFS + 0x1c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_8_RMSK                           0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_8_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_8_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_8_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_8_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_8_CNTVOFF_HI_BMSK                0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_8_CNTVOFF_HI_SHFT                       0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_8_ADDR                       (SAILSS_QTMR_QTMR_F8_8_REG_BASE            + 0x20)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_8_OFFS                       (SAILSS_QTMR_QTMR_F8_8_REG_BASE_OFFS + 0x20)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_8_RMSK                       0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_8_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_8_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_8_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_8_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_8_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_8_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_8_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_8_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_8_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_8_CNTP_CVAL_L0_BMSK          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_8_CNTP_CVAL_L0_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_8_ADDR                       (SAILSS_QTMR_QTMR_F8_8_REG_BASE            + 0x24)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_8_OFFS                       (SAILSS_QTMR_QTMR_F8_8_REG_BASE_OFFS + 0x24)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_8_RMSK                         0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_8_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_8_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_8_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_8_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_8_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_8_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_8_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_8_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_8_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_8_CNTP_CVAL_HI_BMSK            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_8_CNTP_CVAL_HI_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_8_ADDR                          (SAILSS_QTMR_QTMR_F8_8_REG_BASE            + 0x28)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_8_OFFS                          (SAILSS_QTMR_QTMR_F8_8_REG_BASE_OFFS + 0x28)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_8_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_8_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_8_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_8_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_8_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_8_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_8_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_8_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_8_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_8_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_8_CNTP_TVAL_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_8_CNTP_TVAL_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_8_ADDR                           (SAILSS_QTMR_QTMR_F8_8_REG_BASE            + 0x2c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_8_OFFS                           (SAILSS_QTMR_QTMR_F8_8_REG_BASE_OFFS + 0x2c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_8_RMSK                                  0x7
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_8_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_8_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_8_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_8_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_8_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_8_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_8_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_8_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_8_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_8_ISTAT_BMSK                            0x4
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_8_ISTAT_SHFT                              2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_8_ISTAT_INTERRUPT_NOT_PENDING_FVAL        0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_8_ISTAT_INTERRUPT_PENDING_FVAL          0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_8_IMSK_BMSK                             0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_8_IMSK_SHFT                               1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_8_IMSK_UNMASK_INTERRUPT_FVAL            0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_8_IMSK_MASK_INTERRUPT_FVAL              0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_8_EN_BMSK                               0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_8_EN_SHFT                                 0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_8_EN_DISABLED_FVAL                      0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_8_EN_ENABLED_FVAL                       0x1

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_8_ADDR                       (SAILSS_QTMR_QTMR_F8_8_REG_BASE            + 0x30)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_8_OFFS                       (SAILSS_QTMR_QTMR_F8_8_REG_BASE_OFFS + 0x30)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_8_RMSK                       0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_8_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_8_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_8_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_8_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_8_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_8_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_8_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_8_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_8_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_8_CNTV_CVAL_L0_BMSK          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_8_CNTV_CVAL_L0_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_8_ADDR                       (SAILSS_QTMR_QTMR_F8_8_REG_BASE            + 0x34)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_8_OFFS                       (SAILSS_QTMR_QTMR_F8_8_REG_BASE_OFFS + 0x34)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_8_RMSK                         0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_8_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_8_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_8_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_8_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_8_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_8_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_8_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_8_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_8_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_8_CNTV_CVAL_HI_BMSK            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_8_CNTV_CVAL_HI_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_8_ADDR                          (SAILSS_QTMR_QTMR_F8_8_REG_BASE            + 0x38)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_8_OFFS                          (SAILSS_QTMR_QTMR_F8_8_REG_BASE_OFFS + 0x38)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_8_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_8_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_8_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_8_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_8_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_8_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_8_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_8_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_8_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_8_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_8_CNTV_TVAL_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_8_CNTV_TVAL_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_8_ADDR                           (SAILSS_QTMR_QTMR_F8_8_REG_BASE            + 0x3c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_8_OFFS                           (SAILSS_QTMR_QTMR_F8_8_REG_BASE_OFFS + 0x3c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_8_RMSK                                  0x7
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_8_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_8_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_8_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_8_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_8_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_8_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_8_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_8_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_8_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_8_ISTAT_BMSK                            0x4
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_8_ISTAT_SHFT                              2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_8_ISTAT_INTERRUPT_NOT_PENDING_FVAL        0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_8_ISTAT_INTERRUPT_PENDING_FVAL          0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_8_IMSK_BMSK                             0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_8_IMSK_SHFT                               1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_8_IMSK_UNMASK_INTERRUPT_FVAL            0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_8_IMSK_MASK_INTERRUPT_FVAL              0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_8_EN_BMSK                               0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_8_EN_SHFT                                 0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_8_EN_DISABLED_FVAL                      0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_8_EN_ENABLED_FVAL                       0x1

#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_8_ADDR                            (SAILSS_QTMR_QTMR_F8_8_REG_BASE            + 0xfd0)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_8_OFFS                            (SAILSS_QTMR_QTMR_F8_8_REG_BASE_OFFS + 0xfd0)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_8_RMSK                            0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_8_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_VERSION_8_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_8_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_VERSION_8_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_8_MAJOR_BMSK                      0xf0000000
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_8_MAJOR_SHFT                              28
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_8_MINOR_BMSK                       0xfff0000
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_8_MINOR_SHFT                              16
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_8_STEP_BMSK                           0xffff
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_8_STEP_SHFT                                0

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_QTMR_QTMR_F9_9
 *--------------------------------------------------------------------------*/

#define SAILSS_QTMR_QTMR_F9_9_REG_BASE                                     (SAILSS_QTMR_SAILSS_QTMR_BASE            + 0x00009000)
#define SAILSS_QTMR_QTMR_F9_9_REG_BASE_SIZE                                0x1000
#define SAILSS_QTMR_QTMR_F9_9_REG_BASE_USED                                0xfd0
#define SAILSS_QTMR_QTMR_F9_9_REG_BASE_OFFS                                0x00009000

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_9_ADDR                          (SAILSS_QTMR_QTMR_F9_9_REG_BASE            + 0x0)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_9_OFFS                          (SAILSS_QTMR_QTMR_F9_9_REG_BASE_OFFS + 0x0)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_9_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_9_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_9_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_9_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_9_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_9_CNTPCT_LO_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_9_CNTPCT_LO_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_9_ADDR                          (SAILSS_QTMR_QTMR_F9_9_REG_BASE            + 0x4)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_9_OFFS                          (SAILSS_QTMR_QTMR_F9_9_REG_BASE_OFFS + 0x4)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_9_RMSK                            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_9_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_9_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_9_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_9_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_9_CNTPCT_HI_BMSK                  0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_9_CNTPCT_HI_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_9_ADDR                          (SAILSS_QTMR_QTMR_F9_9_REG_BASE            + 0x8)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_9_OFFS                          (SAILSS_QTMR_QTMR_F9_9_REG_BASE_OFFS + 0x8)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_9_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_9_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_9_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_9_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_9_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_9_CNTVCT_LO_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_9_CNTVCT_LO_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_9_ADDR                          (SAILSS_QTMR_QTMR_F9_9_REG_BASE            + 0xc)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_9_OFFS                          (SAILSS_QTMR_QTMR_F9_9_REG_BASE_OFFS + 0xc)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_9_RMSK                            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_9_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_9_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_9_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_9_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_9_CNTVCT_HI_BMSK                  0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_9_CNTVCT_HI_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_9_ADDR                             (SAILSS_QTMR_QTMR_F9_9_REG_BASE            + 0x10)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_9_OFFS                             (SAILSS_QTMR_QTMR_F9_9_REG_BASE_OFFS + 0x10)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_9_RMSK                             0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_9_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_9_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_9_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_9_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_9_CNTFRQ_BMSK                      0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_9_CNTFRQ_SHFT                               0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_9_ADDR                          (SAILSS_QTMR_QTMR_F9_9_REG_BASE            + 0x14)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_9_OFFS                          (SAILSS_QTMR_QTMR_F9_9_REG_BASE_OFFS + 0x14)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_9_RMSK                               0x303
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_9_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_9_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_9_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_9_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_9_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_9_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_9_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_9_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_9_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_9_PL0CTEN_BMSK                       0x200
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_9_PL0CTEN_SHFT                           9
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_9_PL0VTEN_BMSK                       0x100
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_9_PL0VTEN_SHFT                           8
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_9_PL0VCTEN_BMSK                        0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_9_PL0VCTEN_SHFT                          1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_9_PL0PCTEN_BMSK                        0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_9_PL0PCTEN_SHFT                          0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_9_ADDR                         (SAILSS_QTMR_QTMR_F9_9_REG_BASE            + 0x18)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_9_OFFS                         (SAILSS_QTMR_QTMR_F9_9_REG_BASE_OFFS + 0x18)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_9_RMSK                         0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_9_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_9_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_9_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_9_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_9_CNTVOFF_L0_BMSK              0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_9_CNTVOFF_L0_SHFT                       0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_9_ADDR                         (SAILSS_QTMR_QTMR_F9_9_REG_BASE            + 0x1c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_9_OFFS                         (SAILSS_QTMR_QTMR_F9_9_REG_BASE_OFFS + 0x1c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_9_RMSK                           0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_9_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_9_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_9_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_9_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_9_CNTVOFF_HI_BMSK                0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_9_CNTVOFF_HI_SHFT                       0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_9_ADDR                       (SAILSS_QTMR_QTMR_F9_9_REG_BASE            + 0x20)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_9_OFFS                       (SAILSS_QTMR_QTMR_F9_9_REG_BASE_OFFS + 0x20)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_9_RMSK                       0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_9_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_9_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_9_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_9_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_9_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_9_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_9_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_9_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_9_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_9_CNTP_CVAL_L0_BMSK          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_9_CNTP_CVAL_L0_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_9_ADDR                       (SAILSS_QTMR_QTMR_F9_9_REG_BASE            + 0x24)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_9_OFFS                       (SAILSS_QTMR_QTMR_F9_9_REG_BASE_OFFS + 0x24)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_9_RMSK                         0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_9_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_9_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_9_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_9_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_9_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_9_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_9_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_9_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_9_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_9_CNTP_CVAL_HI_BMSK            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_9_CNTP_CVAL_HI_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_9_ADDR                          (SAILSS_QTMR_QTMR_F9_9_REG_BASE            + 0x28)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_9_OFFS                          (SAILSS_QTMR_QTMR_F9_9_REG_BASE_OFFS + 0x28)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_9_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_9_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_9_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_9_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_9_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_9_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_9_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_9_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_9_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_9_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_9_CNTP_TVAL_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_9_CNTP_TVAL_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_9_ADDR                           (SAILSS_QTMR_QTMR_F9_9_REG_BASE            + 0x2c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_9_OFFS                           (SAILSS_QTMR_QTMR_F9_9_REG_BASE_OFFS + 0x2c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_9_RMSK                                  0x7
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_9_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_9_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_9_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_9_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_9_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_9_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_9_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_9_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_9_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_9_ISTAT_BMSK                            0x4
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_9_ISTAT_SHFT                              2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_9_ISTAT_INTERRUPT_NOT_PENDING_FVAL        0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_9_ISTAT_INTERRUPT_PENDING_FVAL          0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_9_IMSK_BMSK                             0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_9_IMSK_SHFT                               1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_9_IMSK_UNMASK_INTERRUPT_FVAL            0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_9_IMSK_MASK_INTERRUPT_FVAL              0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_9_EN_BMSK                               0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_9_EN_SHFT                                 0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_9_EN_DISABLED_FVAL                      0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_9_EN_ENABLED_FVAL                       0x1

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_9_ADDR                       (SAILSS_QTMR_QTMR_F9_9_REG_BASE            + 0x30)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_9_OFFS                       (SAILSS_QTMR_QTMR_F9_9_REG_BASE_OFFS + 0x30)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_9_RMSK                       0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_9_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_9_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_9_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_9_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_9_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_9_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_9_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_9_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_9_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_9_CNTV_CVAL_L0_BMSK          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_9_CNTV_CVAL_L0_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_9_ADDR                       (SAILSS_QTMR_QTMR_F9_9_REG_BASE            + 0x34)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_9_OFFS                       (SAILSS_QTMR_QTMR_F9_9_REG_BASE_OFFS + 0x34)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_9_RMSK                         0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_9_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_9_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_9_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_9_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_9_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_9_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_9_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_9_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_9_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_9_CNTV_CVAL_HI_BMSK            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_9_CNTV_CVAL_HI_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_9_ADDR                          (SAILSS_QTMR_QTMR_F9_9_REG_BASE            + 0x38)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_9_OFFS                          (SAILSS_QTMR_QTMR_F9_9_REG_BASE_OFFS + 0x38)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_9_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_9_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_9_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_9_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_9_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_9_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_9_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_9_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_9_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_9_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_9_CNTV_TVAL_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_9_CNTV_TVAL_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_9_ADDR                           (SAILSS_QTMR_QTMR_F9_9_REG_BASE            + 0x3c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_9_OFFS                           (SAILSS_QTMR_QTMR_F9_9_REG_BASE_OFFS + 0x3c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_9_RMSK                                  0x7
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_9_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_9_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_9_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_9_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_9_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_9_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_9_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_9_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_9_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_9_ISTAT_BMSK                            0x4
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_9_ISTAT_SHFT                              2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_9_ISTAT_INTERRUPT_NOT_PENDING_FVAL        0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_9_ISTAT_INTERRUPT_PENDING_FVAL          0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_9_IMSK_BMSK                             0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_9_IMSK_SHFT                               1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_9_IMSK_UNMASK_INTERRUPT_FVAL            0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_9_IMSK_MASK_INTERRUPT_FVAL              0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_9_EN_BMSK                               0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_9_EN_SHFT                                 0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_9_EN_DISABLED_FVAL                      0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_9_EN_ENABLED_FVAL                       0x1

#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_9_ADDR                            (SAILSS_QTMR_QTMR_F9_9_REG_BASE            + 0xfd0)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_9_OFFS                            (SAILSS_QTMR_QTMR_F9_9_REG_BASE_OFFS + 0xfd0)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_9_RMSK                            0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_9_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_VERSION_9_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_9_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_VERSION_9_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_9_MAJOR_BMSK                      0xf0000000
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_9_MAJOR_SHFT                              28
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_9_MINOR_BMSK                       0xfff0000
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_9_MINOR_SHFT                              16
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_9_STEP_BMSK                           0xffff
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_9_STEP_SHFT                                0

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_QTMR_QTMR_F10_10
 *--------------------------------------------------------------------------*/

#define SAILSS_QTMR_QTMR_F10_10_REG_BASE                                    (SAILSS_QTMR_SAILSS_QTMR_BASE            + 0x0000a000)
#define SAILSS_QTMR_QTMR_F10_10_REG_BASE_SIZE                               0x1000
#define SAILSS_QTMR_QTMR_F10_10_REG_BASE_USED                               0xfd0
#define SAILSS_QTMR_QTMR_F10_10_REG_BASE_OFFS                               0x0000a000

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_10_ADDR                          (SAILSS_QTMR_QTMR_F10_10_REG_BASE            + 0x0)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_10_OFFS                          (SAILSS_QTMR_QTMR_F10_10_REG_BASE_OFFS + 0x0)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_10_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_10_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_10_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_10_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_10_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_10_CNTPCT_LO_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_10_CNTPCT_LO_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_10_ADDR                          (SAILSS_QTMR_QTMR_F10_10_REG_BASE            + 0x4)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_10_OFFS                          (SAILSS_QTMR_QTMR_F10_10_REG_BASE_OFFS + 0x4)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_10_RMSK                            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_10_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_10_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_10_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_10_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_10_CNTPCT_HI_BMSK                  0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_10_CNTPCT_HI_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_10_ADDR                          (SAILSS_QTMR_QTMR_F10_10_REG_BASE            + 0x8)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_10_OFFS                          (SAILSS_QTMR_QTMR_F10_10_REG_BASE_OFFS + 0x8)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_10_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_10_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_10_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_10_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_10_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_10_CNTVCT_LO_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_10_CNTVCT_LO_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_10_ADDR                          (SAILSS_QTMR_QTMR_F10_10_REG_BASE            + 0xc)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_10_OFFS                          (SAILSS_QTMR_QTMR_F10_10_REG_BASE_OFFS + 0xc)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_10_RMSK                            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_10_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_10_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_10_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_10_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_10_CNTVCT_HI_BMSK                  0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_10_CNTVCT_HI_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_10_ADDR                             (SAILSS_QTMR_QTMR_F10_10_REG_BASE            + 0x10)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_10_OFFS                             (SAILSS_QTMR_QTMR_F10_10_REG_BASE_OFFS + 0x10)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_10_RMSK                             0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_10_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_10_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_10_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_10_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_10_CNTFRQ_BMSK                      0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_10_CNTFRQ_SHFT                               0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_10_ADDR                          (SAILSS_QTMR_QTMR_F10_10_REG_BASE            + 0x14)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_10_OFFS                          (SAILSS_QTMR_QTMR_F10_10_REG_BASE_OFFS + 0x14)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_10_RMSK                               0x303
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_10_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_10_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_10_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_10_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_10_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_10_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_10_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_10_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_10_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_10_PL0CTEN_BMSK                       0x200
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_10_PL0CTEN_SHFT                           9
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_10_PL0VTEN_BMSK                       0x100
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_10_PL0VTEN_SHFT                           8
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_10_PL0VCTEN_BMSK                        0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_10_PL0VCTEN_SHFT                          1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_10_PL0PCTEN_BMSK                        0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_10_PL0PCTEN_SHFT                          0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_10_ADDR                         (SAILSS_QTMR_QTMR_F10_10_REG_BASE            + 0x18)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_10_OFFS                         (SAILSS_QTMR_QTMR_F10_10_REG_BASE_OFFS + 0x18)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_10_RMSK                         0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_10_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_10_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_10_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_10_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_10_CNTVOFF_L0_BMSK              0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_10_CNTVOFF_L0_SHFT                       0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_10_ADDR                         (SAILSS_QTMR_QTMR_F10_10_REG_BASE            + 0x1c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_10_OFFS                         (SAILSS_QTMR_QTMR_F10_10_REG_BASE_OFFS + 0x1c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_10_RMSK                           0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_10_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_10_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_10_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_10_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_10_CNTVOFF_HI_BMSK                0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_10_CNTVOFF_HI_SHFT                       0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_10_ADDR                       (SAILSS_QTMR_QTMR_F10_10_REG_BASE            + 0x20)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_10_OFFS                       (SAILSS_QTMR_QTMR_F10_10_REG_BASE_OFFS + 0x20)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_10_RMSK                       0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_10_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_10_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_10_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_10_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_10_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_10_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_10_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_10_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_10_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_10_CNTP_CVAL_L0_BMSK          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_10_CNTP_CVAL_L0_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_10_ADDR                       (SAILSS_QTMR_QTMR_F10_10_REG_BASE            + 0x24)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_10_OFFS                       (SAILSS_QTMR_QTMR_F10_10_REG_BASE_OFFS + 0x24)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_10_RMSK                         0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_10_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_10_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_10_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_10_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_10_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_10_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_10_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_10_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_10_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_10_CNTP_CVAL_HI_BMSK            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_10_CNTP_CVAL_HI_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_10_ADDR                          (SAILSS_QTMR_QTMR_F10_10_REG_BASE            + 0x28)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_10_OFFS                          (SAILSS_QTMR_QTMR_F10_10_REG_BASE_OFFS + 0x28)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_10_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_10_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_10_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_10_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_10_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_10_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_10_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_10_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_10_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_10_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_10_CNTP_TVAL_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_10_CNTP_TVAL_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_10_ADDR                           (SAILSS_QTMR_QTMR_F10_10_REG_BASE            + 0x2c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_10_OFFS                           (SAILSS_QTMR_QTMR_F10_10_REG_BASE_OFFS + 0x2c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_10_RMSK                                  0x7
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_10_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_10_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_10_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_10_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_10_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_10_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_10_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_10_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_10_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_10_ISTAT_BMSK                            0x4
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_10_ISTAT_SHFT                              2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_10_ISTAT_INTERRUPT_NOT_PENDING_FVAL        0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_10_ISTAT_INTERRUPT_PENDING_FVAL          0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_10_IMSK_BMSK                             0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_10_IMSK_SHFT                               1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_10_IMSK_UNMASK_INTERRUPT_FVAL            0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_10_IMSK_MASK_INTERRUPT_FVAL              0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_10_EN_BMSK                               0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_10_EN_SHFT                                 0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_10_EN_DISABLED_FVAL                      0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_10_EN_ENABLED_FVAL                       0x1

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_10_ADDR                       (SAILSS_QTMR_QTMR_F10_10_REG_BASE            + 0x30)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_10_OFFS                       (SAILSS_QTMR_QTMR_F10_10_REG_BASE_OFFS + 0x30)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_10_RMSK                       0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_10_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_10_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_10_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_10_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_10_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_10_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_10_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_10_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_10_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_10_CNTV_CVAL_L0_BMSK          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_10_CNTV_CVAL_L0_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_10_ADDR                       (SAILSS_QTMR_QTMR_F10_10_REG_BASE            + 0x34)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_10_OFFS                       (SAILSS_QTMR_QTMR_F10_10_REG_BASE_OFFS + 0x34)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_10_RMSK                         0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_10_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_10_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_10_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_10_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_10_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_10_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_10_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_10_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_10_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_10_CNTV_CVAL_HI_BMSK            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_10_CNTV_CVAL_HI_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_10_ADDR                          (SAILSS_QTMR_QTMR_F10_10_REG_BASE            + 0x38)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_10_OFFS                          (SAILSS_QTMR_QTMR_F10_10_REG_BASE_OFFS + 0x38)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_10_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_10_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_10_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_10_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_10_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_10_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_10_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_10_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_10_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_10_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_10_CNTV_TVAL_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_10_CNTV_TVAL_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_10_ADDR                           (SAILSS_QTMR_QTMR_F10_10_REG_BASE            + 0x3c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_10_OFFS                           (SAILSS_QTMR_QTMR_F10_10_REG_BASE_OFFS + 0x3c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_10_RMSK                                  0x7
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_10_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_10_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_10_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_10_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_10_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_10_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_10_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_10_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_10_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_10_ISTAT_BMSK                            0x4
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_10_ISTAT_SHFT                              2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_10_ISTAT_INTERRUPT_NOT_PENDING_FVAL        0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_10_ISTAT_INTERRUPT_PENDING_FVAL          0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_10_IMSK_BMSK                             0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_10_IMSK_SHFT                               1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_10_IMSK_UNMASK_INTERRUPT_FVAL            0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_10_IMSK_MASK_INTERRUPT_FVAL              0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_10_EN_BMSK                               0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_10_EN_SHFT                                 0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_10_EN_DISABLED_FVAL                      0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_10_EN_ENABLED_FVAL                       0x1

#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_10_ADDR                            (SAILSS_QTMR_QTMR_F10_10_REG_BASE            + 0xfd0)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_10_OFFS                            (SAILSS_QTMR_QTMR_F10_10_REG_BASE_OFFS + 0xfd0)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_10_RMSK                            0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_10_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_VERSION_10_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_10_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_VERSION_10_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_10_MAJOR_BMSK                      0xf0000000
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_10_MAJOR_SHFT                              28
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_10_MINOR_BMSK                       0xfff0000
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_10_MINOR_SHFT                              16
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_10_STEP_BMSK                           0xffff
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_10_STEP_SHFT                                0

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_QTMR_QTMR_F11_11
 *--------------------------------------------------------------------------*/

#define SAILSS_QTMR_QTMR_F11_11_REG_BASE                                    (SAILSS_QTMR_SAILSS_QTMR_BASE            + 0x0000b000)
#define SAILSS_QTMR_QTMR_F11_11_REG_BASE_SIZE                               0x1000
#define SAILSS_QTMR_QTMR_F11_11_REG_BASE_USED                               0xfd0
#define SAILSS_QTMR_QTMR_F11_11_REG_BASE_OFFS                               0x0000b000

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_11_ADDR                          (SAILSS_QTMR_QTMR_F11_11_REG_BASE            + 0x0)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_11_OFFS                          (SAILSS_QTMR_QTMR_F11_11_REG_BASE_OFFS + 0x0)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_11_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_11_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_11_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_11_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_11_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_11_CNTPCT_LO_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_LO_11_CNTPCT_LO_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_11_ADDR                          (SAILSS_QTMR_QTMR_F11_11_REG_BASE            + 0x4)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_11_OFFS                          (SAILSS_QTMR_QTMR_F11_11_REG_BASE_OFFS + 0x4)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_11_RMSK                            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_11_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_11_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_11_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_11_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_11_CNTPCT_HI_BMSK                  0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPCT_HI_11_CNTPCT_HI_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_11_ADDR                          (SAILSS_QTMR_QTMR_F11_11_REG_BASE            + 0x8)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_11_OFFS                          (SAILSS_QTMR_QTMR_F11_11_REG_BASE_OFFS + 0x8)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_11_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_11_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_11_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_11_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_11_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_11_CNTVCT_LO_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_LO_11_CNTVCT_LO_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_11_ADDR                          (SAILSS_QTMR_QTMR_F11_11_REG_BASE            + 0xc)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_11_OFFS                          (SAILSS_QTMR_QTMR_F11_11_REG_BASE_OFFS + 0xc)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_11_RMSK                            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_11_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_11_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_11_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_11_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_11_CNTVCT_HI_BMSK                  0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVCT_HI_11_CNTVCT_HI_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_11_ADDR                             (SAILSS_QTMR_QTMR_F11_11_REG_BASE            + 0x10)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_11_OFFS                             (SAILSS_QTMR_QTMR_F11_11_REG_BASE_OFFS + 0x10)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_11_RMSK                             0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_11_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_11_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_11_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_11_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_11_CNTFRQ_BMSK                      0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTFRQ_11_CNTFRQ_SHFT                               0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_11_ADDR                          (SAILSS_QTMR_QTMR_F11_11_REG_BASE            + 0x14)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_11_OFFS                          (SAILSS_QTMR_QTMR_F11_11_REG_BASE_OFFS + 0x14)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_11_RMSK                               0x303
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_11_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_11_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_11_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_11_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_11_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_11_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_11_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_11_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_11_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_11_PL0CTEN_BMSK                       0x200
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_11_PL0CTEN_SHFT                           9
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_11_PL0VTEN_BMSK                       0x100
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_11_PL0VTEN_SHFT                           8
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_11_PL0VCTEN_BMSK                        0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_11_PL0VCTEN_SHFT                          1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_11_PL0PCTEN_BMSK                        0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTPL0ACR_11_PL0PCTEN_SHFT                          0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_11_ADDR                         (SAILSS_QTMR_QTMR_F11_11_REG_BASE            + 0x18)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_11_OFFS                         (SAILSS_QTMR_QTMR_F11_11_REG_BASE_OFFS + 0x18)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_11_RMSK                         0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_11_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_11_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_11_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_11_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_11_CNTVOFF_L0_BMSK              0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_LO_11_CNTVOFF_L0_SHFT                       0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_11_ADDR                         (SAILSS_QTMR_QTMR_F11_11_REG_BASE            + 0x1c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_11_OFFS                         (SAILSS_QTMR_QTMR_F11_11_REG_BASE_OFFS + 0x1c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_11_RMSK                           0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_11_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_11_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_11_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_11_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_11_CNTVOFF_HI_BMSK                0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTVOFF_HI_11_CNTVOFF_HI_SHFT                       0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_11_ADDR                       (SAILSS_QTMR_QTMR_F11_11_REG_BASE            + 0x20)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_11_OFFS                       (SAILSS_QTMR_QTMR_F11_11_REG_BASE_OFFS + 0x20)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_11_RMSK                       0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_11_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_11_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_11_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_11_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_11_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_11_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_11_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_11_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_11_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_11_CNTP_CVAL_L0_BMSK          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_LO_11_CNTP_CVAL_L0_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_11_ADDR                       (SAILSS_QTMR_QTMR_F11_11_REG_BASE            + 0x24)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_11_OFFS                       (SAILSS_QTMR_QTMR_F11_11_REG_BASE_OFFS + 0x24)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_11_RMSK                         0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_11_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_11_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_11_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_11_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_11_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_11_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_11_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_11_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_11_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_11_CNTP_CVAL_HI_BMSK            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CVAL_HI_11_CNTP_CVAL_HI_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_11_ADDR                          (SAILSS_QTMR_QTMR_F11_11_REG_BASE            + 0x28)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_11_OFFS                          (SAILSS_QTMR_QTMR_F11_11_REG_BASE_OFFS + 0x28)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_11_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_11_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_11_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_11_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_11_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_11_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_11_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_11_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_11_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_11_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_11_CNTP_TVAL_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_TVAL_11_CNTP_TVAL_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_11_ADDR                           (SAILSS_QTMR_QTMR_F11_11_REG_BASE            + 0x2c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_11_OFFS                           (SAILSS_QTMR_QTMR_F11_11_REG_BASE_OFFS + 0x2c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_11_RMSK                                  0x7
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_11_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_11_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_11_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_11_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_11_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_11_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_11_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_11_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_11_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_11_ISTAT_BMSK                            0x4
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_11_ISTAT_SHFT                              2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_11_ISTAT_INTERRUPT_NOT_PENDING_FVAL        0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_11_ISTAT_INTERRUPT_PENDING_FVAL          0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_11_IMSK_BMSK                             0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_11_IMSK_SHFT                               1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_11_IMSK_UNMASK_INTERRUPT_FVAL            0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_11_IMSK_MASK_INTERRUPT_FVAL              0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_11_EN_BMSK                               0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_11_EN_SHFT                                 0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_11_EN_DISABLED_FVAL                      0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTP_CTL_11_EN_ENABLED_FVAL                       0x1

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_11_ADDR                       (SAILSS_QTMR_QTMR_F11_11_REG_BASE            + 0x30)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_11_OFFS                       (SAILSS_QTMR_QTMR_F11_11_REG_BASE_OFFS + 0x30)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_11_RMSK                       0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_11_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_11_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_11_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_11_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_11_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_11_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_11_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_11_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_11_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_11_CNTV_CVAL_L0_BMSK          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_LO_11_CNTV_CVAL_L0_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_11_ADDR                       (SAILSS_QTMR_QTMR_F11_11_REG_BASE            + 0x34)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_11_OFFS                       (SAILSS_QTMR_QTMR_F11_11_REG_BASE_OFFS + 0x34)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_11_RMSK                         0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_11_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_11_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_11_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_11_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_11_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_11_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_11_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_11_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_11_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_11_CNTV_CVAL_HI_BMSK            0xffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CVAL_HI_11_CNTV_CVAL_HI_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_11_ADDR                          (SAILSS_QTMR_QTMR_F11_11_REG_BASE            + 0x38)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_11_OFFS                          (SAILSS_QTMR_QTMR_F11_11_REG_BASE_OFFS + 0x38)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_11_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_11_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_11_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_11_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_11_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_11_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_11_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_11_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_11_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_11_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_11_CNTV_TVAL_BMSK                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_TVAL_11_CNTV_TVAL_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_11_ADDR                           (SAILSS_QTMR_QTMR_F11_11_REG_BASE            + 0x3c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_11_OFFS                           (SAILSS_QTMR_QTMR_F11_11_REG_BASE_OFFS + 0x3c)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_11_RMSK                                  0x7
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_11_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_11_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_11_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_11_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_11_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_11_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_11_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_11_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_11_IN)
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_11_ISTAT_BMSK                            0x4
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_11_ISTAT_SHFT                              2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_11_ISTAT_INTERRUPT_NOT_PENDING_FVAL        0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_11_ISTAT_INTERRUPT_PENDING_FVAL          0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_11_IMSK_BMSK                             0x2
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_11_IMSK_SHFT                               1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_11_IMSK_UNMASK_INTERRUPT_FVAL            0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_11_IMSK_MASK_INTERRUPT_FVAL              0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_11_EN_BMSK                               0x1
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_11_EN_SHFT                                 0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_11_EN_DISABLED_FVAL                      0x0
#define HWIO_SAILSS_QTMR_QTMR_V1_CNTV_CTL_11_EN_ENABLED_FVAL                       0x1

#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_11_ADDR                            (SAILSS_QTMR_QTMR_F11_11_REG_BASE            + 0xfd0)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_11_OFFS                            (SAILSS_QTMR_QTMR_F11_11_REG_BASE_OFFS + 0xfd0)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_11_RMSK                            0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_11_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_V1_VERSION_11_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_11_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_V1_VERSION_11_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_11_MAJOR_BMSK                      0xf0000000
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_11_MAJOR_SHFT                              28
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_11_MINOR_BMSK                       0xfff0000
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_11_MINOR_SHFT                              16
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_11_STEP_BMSK                           0xffff
#define HWIO_SAILSS_QTMR_QTMR_V1_VERSION_11_STEP_SHFT                                0

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_QTMR_QTMR_AC
 *--------------------------------------------------------------------------*/

#define SAILSS_QTMR_QTMR_AC_REG_BASE                                        (SAILSS_QTMR_SAILSS_QTMR_BASE            + 0x0000c000)
#define SAILSS_QTMR_QTMR_AC_REG_BASE_SIZE                                   0x1000
#define SAILSS_QTMR_QTMR_AC_REG_BASE_USED                                   0xff0
#define SAILSS_QTMR_QTMR_AC_REG_BASE_OFFS                                   0x0000c000

#define HWIO_SAILSS_QTMR_QTMR_AC_CNTFRQ_ADDR                                (SAILSS_QTMR_QTMR_AC_REG_BASE            + 0x0)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTFRQ_OFFS                                (SAILSS_QTMR_QTMR_AC_REG_BASE_OFFS + 0x0)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTFRQ_RMSK                                0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTFRQ_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_AC_CNTFRQ_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTFRQ_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_AC_CNTFRQ_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTFRQ_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_AC_CNTFRQ_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTFRQ_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_AC_CNTFRQ_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_AC_CNTFRQ_IN)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTFRQ_CNTFRQ_BMSK                         0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTFRQ_CNTFRQ_SHFT                                  0

#define HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG0_ADDR                           (SAILSS_QTMR_QTMR_AC_REG_BASE            + 0x4)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG0_OFFS                           (SAILSS_QTMR_QTMR_AC_REG_BASE_OFFS + 0x4)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG0_RMSK                                 0xff
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG0_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG0_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG0_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG0_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG0_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG0_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG0_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG0_IN)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG0_NSN_BMSK                             0xff
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG0_NSN_SHFT                                0
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG0_NSN_SECURE_ONLY_FVAL                  0x0
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG0_NSN_SECURE_OR_NONSECURE_FVAL          0x1

#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG0_ADDR                           (SAILSS_QTMR_QTMR_AC_REG_BASE            + 0x8)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG0_OFFS                           (SAILSS_QTMR_QTMR_AC_REG_BASE_OFFS + 0x8)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG0_RMSK                           0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG0_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG0_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG0_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG0_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG0_F7_CFG_BMSK                    0xf0000000
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG0_F7_CFG_SHFT                            28
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG0_F6_CFG_BMSK                     0xf000000
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG0_F6_CFG_SHFT                            24
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG0_F5_CFG_BMSK                      0xf00000
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG0_F5_CFG_SHFT                            20
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG0_F4_CFG_BMSK                       0xf0000
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG0_F4_CFG_SHFT                            16
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG0_F3_CFG_BMSK                        0xf000
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG0_F3_CFG_SHFT                            12
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG0_F2_CFG_BMSK                         0xf00
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG0_F2_CFG_SHFT                             8
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG0_F1_CFG_BMSK                          0xf0
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG0_F1_CFG_SHFT                             4
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG0_F0_CFG_BMSK                           0xf
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG0_F0_CFG_SHFT                             0
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG0_F0_CFG_FI_FVAL                        0x0
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG0_F0_CFG_FVI_FVAL                       0x1
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG0_F0_CFG_FPLO_FVAL                      0x2
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG0_F0_CFG_RSVD_FVAL                      0x3

#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_ADDR(n)                        (SAILSS_QTMR_QTMR_AC_REG_BASE            + 0X40 + (0x4*(n)))
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_OFFS(n)                        (SAILSS_QTMR_QTMR_AC_REG_BASE_OFFS + 0X40 + (0x4*(n)))
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_RMSK                                 0x3f
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_MAXn                                    7
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_INI(n)                \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_ADDR(n), HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_RMSK)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_ADDR(n), mask)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_ADDR(n),val)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_ADDR(n),mask,val,HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_INI(n))
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_RWPT_BMSK                            0x20
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_RWPT_SHFT                               5
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_RWPT_ACCESS_DENIED_FVAL               0x0
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_RWPT_ACCESS_ALLOWED_FVAL              0x1
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_RWVT_BMSK                            0x10
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_RWVT_SHFT                               4
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_RWVT_ACCESS_DENIED_FVAL               0x0
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_RWVT_ACCESS_ALLOWED_FVAL              0x1
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_RVOFF_BMSK                            0x8
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_RVOFF_SHFT                              3
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_RVOFF_ACCESS_DENIED_FVAL              0x0
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_RVOFF_ACCESS_ALLOWED_FVAL             0x1
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_RFRQ_BMSK                             0x4
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_RFRQ_SHFT                               2
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_RFRQ_ACCESS_DENIED_FVAL               0x0
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_RFRQ_ACCESS_ALLOWED_FVAL              0x1
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_RPVCT_BMSK                            0x2
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_RPVCT_SHFT                              1
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_RPVCT_ACCESS_DENIED_FVAL              0x0
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_RPVCT_ACCESS_ALLOWED_FVAL             0x1
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_RPCT_BMSK                             0x1
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_RPCT_SHFT                               0
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_RPCT_ACCESS_DENIED_FVAL               0x0
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG0_RPCT_ACCESS_ALLOWED_FVAL              0x1

#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_LO_n_ADDR(n)                   (SAILSS_QTMR_QTMR_AC_REG_BASE            + 0X80 + (0x8*(n)))
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_LO_n_OFFS(n)                   (SAILSS_QTMR_QTMR_AC_REG_BASE_OFFS + 0X80 + (0x8*(n)))
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_LO_n_RMSK                      0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_LO_n_MAXn                               7
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_LO_n_INI(n)                \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_LO_n_ADDR(n), HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_LO_n_RMSK)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_LO_n_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_LO_n_ADDR(n), mask)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_LO_n_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_LO_n_ADDR(n),val)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_LO_n_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_LO_n_ADDR(n),mask,val,HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_LO_n_INI(n))
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_LO_n_CNTVOFF_LO_BMSK           0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_LO_n_CNTVOFF_LO_SHFT                    0

#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_HI_n_ADDR(n)                   (SAILSS_QTMR_QTMR_AC_REG_BASE            + 0X84 + (0x8*(n)))
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_HI_n_OFFS(n)                   (SAILSS_QTMR_QTMR_AC_REG_BASE_OFFS + 0X84 + (0x8*(n)))
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_HI_n_RMSK                        0xffffff
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_HI_n_MAXn                               7
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_HI_n_INI(n)                \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_HI_n_ADDR(n), HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_HI_n_RMSK)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_HI_n_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_HI_n_ADDR(n), mask)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_HI_n_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_HI_n_ADDR(n),val)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_HI_n_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_HI_n_ADDR(n),mask,val,HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_HI_n_INI(n))
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_HI_n_CNTVOFF_HI_BMSK             0xffffff
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG0_HI_n_CNTVOFF_HI_SHFT                    0

#define HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG1_ADDR                           (SAILSS_QTMR_QTMR_AC_REG_BASE            + 0x104)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG1_OFFS                           (SAILSS_QTMR_QTMR_AC_REG_BASE_OFFS + 0x104)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG1_RMSK                                  0xf
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG1_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG1_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG1_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG1_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG1_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG1_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG1_IN)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG1_NSN_BMSK                              0xf
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG1_NSN_SHFT                                0
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG1_NSN_SECURE_ONLY_FVAL                  0x0
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTNSAR_FG1_NSN_SECURE_OR_NONSECURE_FVAL          0x1

#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG1_ADDR                           (SAILSS_QTMR_QTMR_AC_REG_BASE            + 0x108)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG1_OFFS                           (SAILSS_QTMR_QTMR_AC_REG_BASE_OFFS + 0x108)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG1_RMSK                           0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG1_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG1_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG1_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG1_F15_CFG_BMSK                   0xf0000000
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG1_F15_CFG_SHFT                           28
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG1_F14_CFG_BMSK                    0xf000000
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG1_F14_CFG_SHFT                           24
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG1_F13_CFG_BMSK                     0xf00000
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG1_F13_CFG_SHFT                           20
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG1_F12_CFG_BMSK                      0xf0000
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG1_F12_CFG_SHFT                           16
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG1_F11_CFG_BMSK                       0xf000
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG1_F11_CFG_SHFT                           12
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG1_F10_CFG_BMSK                        0xf00
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG1_F10_CFG_SHFT                            8
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG1_F9_CFG_BMSK                          0xf0
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG1_F9_CFG_SHFT                             4
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG1_F8_CFG_BMSK                           0xf
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG1_F8_CFG_SHFT                             0
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG1_F8_CFG_FI_FVAL                        0x0
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG1_F8_CFG_FVI_FVAL                       0x1
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG1_F8_CFG_FPLO_FVAL                      0x2
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTTIDR_FG1_F8_CFG_RSVD_FVAL                      0x3

#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_ADDR(n)                        (SAILSS_QTMR_QTMR_AC_REG_BASE            + 0X140 + (0x4*(n)))
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_OFFS(n)                        (SAILSS_QTMR_QTMR_AC_REG_BASE_OFFS + 0X140 + (0x4*(n)))
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_RMSK                                 0x3f
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_MAXn                                    3
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_INI(n)                \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_ADDR(n), HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_RMSK)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_ADDR(n), mask)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_ADDR(n),val)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_ADDR(n),mask,val,HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_INI(n))
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_RWPT_BMSK                            0x20
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_RWPT_SHFT                               5
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_RWPT_ACCESS_DENIED_FVAL               0x0
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_RWPT_ACCESS_ALLOWED_FVAL              0x1
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_RWVT_BMSK                            0x10
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_RWVT_SHFT                               4
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_RWVT_ACCESS_DENIED_FVAL               0x0
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_RWVT_ACCESS_ALLOWED_FVAL              0x1
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_RVOFF_BMSK                            0x8
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_RVOFF_SHFT                              3
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_RVOFF_ACCESS_DENIED_FVAL              0x0
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_RVOFF_ACCESS_ALLOWED_FVAL             0x1
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_RFRQ_BMSK                             0x4
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_RFRQ_SHFT                               2
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_RFRQ_ACCESS_DENIED_FVAL               0x0
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_RFRQ_ACCESS_ALLOWED_FVAL              0x1
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_RPVCT_BMSK                            0x2
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_RPVCT_SHFT                              1
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_RPVCT_ACCESS_DENIED_FVAL              0x0
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_RPVCT_ACCESS_ALLOWED_FVAL             0x1
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_RPCT_BMSK                             0x1
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_RPCT_SHFT                               0
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_RPCT_ACCESS_DENIED_FVAL               0x0
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTACRn_FG1_RPCT_ACCESS_ALLOWED_FVAL              0x1

#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_LO_n_ADDR(n)                   (SAILSS_QTMR_QTMR_AC_REG_BASE            + 0X180 + (0x8*(n)))
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_LO_n_OFFS(n)                   (SAILSS_QTMR_QTMR_AC_REG_BASE_OFFS + 0X180 + (0x8*(n)))
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_LO_n_RMSK                      0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_LO_n_MAXn                               3
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_LO_n_INI(n)                \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_LO_n_ADDR(n), HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_LO_n_RMSK)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_LO_n_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_LO_n_ADDR(n), mask)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_LO_n_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_LO_n_ADDR(n),val)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_LO_n_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_LO_n_ADDR(n),mask,val,HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_LO_n_INI(n))
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_LO_n_CNTVOFF_LO_BMSK           0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_LO_n_CNTVOFF_LO_SHFT                    0

#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_HI_n_ADDR(n)                   (SAILSS_QTMR_QTMR_AC_REG_BASE            + 0X184 + (0x8*(n)))
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_HI_n_OFFS(n)                   (SAILSS_QTMR_QTMR_AC_REG_BASE_OFFS + 0X184 + (0x8*(n)))
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_HI_n_RMSK                        0xffffff
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_HI_n_MAXn                               3
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_HI_n_INI(n)                \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_HI_n_ADDR(n), HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_HI_n_RMSK)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_HI_n_INMI(n,mask)        \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_HI_n_ADDR(n), mask)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_HI_n_OUTI(n,val)        \
                out_dword(HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_HI_n_ADDR(n),val)
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_HI_n_OUTMI(n,mask,val) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_HI_n_ADDR(n),mask,val,HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_HI_n_INI(n))
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_HI_n_CNTVOFF_HI_BMSK             0xffffff
#define HWIO_SAILSS_QTMR_QTMR_AC_CNTVOFF_FG1_HI_n_CNTVOFF_HI_SHFT                    0

#define HWIO_SAILSS_QTMR_QTMR_AC_CFG_ADDR                                   (SAILSS_QTMR_QTMR_AC_REG_BASE            + 0xfc0)
#define HWIO_SAILSS_QTMR_QTMR_AC_CFG_OFFS                                   (SAILSS_QTMR_QTMR_AC_REG_BASE_OFFS + 0xfc0)
#define HWIO_SAILSS_QTMR_QTMR_AC_CFG_RMSK                                          0x3
#define HWIO_SAILSS_QTMR_QTMR_AC_CFG_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_AC_CFG_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_AC_CFG_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_AC_CFG_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_AC_CFG_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_AC_CFG_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_AC_CFG_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_AC_CFG_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_AC_CFG_IN)
#define HWIO_SAILSS_QTMR_QTMR_AC_CFG_DSBL_ATOMIC_BMSK                              0x2
#define HWIO_SAILSS_QTMR_QTMR_AC_CFG_DSBL_ATOMIC_SHFT                                1
#define HWIO_SAILSS_QTMR_QTMR_AC_CFG_TEST_BUS_EN_BMSK                              0x1
#define HWIO_SAILSS_QTMR_QTMR_AC_CFG_TEST_BUS_EN_SHFT                                0

#define HWIO_SAILSS_QTMR_QTMR_AC_VERSION_ADDR                               (SAILSS_QTMR_QTMR_AC_REG_BASE            + 0xfd0)
#define HWIO_SAILSS_QTMR_QTMR_AC_VERSION_OFFS                               (SAILSS_QTMR_QTMR_AC_REG_BASE_OFFS + 0xfd0)
#define HWIO_SAILSS_QTMR_QTMR_AC_VERSION_RMSK                               0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_AC_VERSION_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_AC_VERSION_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_AC_VERSION_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_AC_VERSION_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_AC_VERSION_MAJOR_BMSK                         0xf0000000
#define HWIO_SAILSS_QTMR_QTMR_AC_VERSION_MAJOR_SHFT                                 28
#define HWIO_SAILSS_QTMR_QTMR_AC_VERSION_MINOR_BMSK                          0xfff0000
#define HWIO_SAILSS_QTMR_QTMR_AC_VERSION_MINOR_SHFT                                 16
#define HWIO_SAILSS_QTMR_QTMR_AC_VERSION_STEP_BMSK                              0xffff
#define HWIO_SAILSS_QTMR_QTMR_AC_VERSION_STEP_SHFT                                   0

#define HWIO_SAILSS_QTMR_QTMR_AC_HW_FRAME_SEL_1_ADDR                        (SAILSS_QTMR_QTMR_AC_REG_BASE            + 0xfe0)
#define HWIO_SAILSS_QTMR_QTMR_AC_HW_FRAME_SEL_1_OFFS                        (SAILSS_QTMR_QTMR_AC_REG_BASE_OFFS + 0xfe0)
#define HWIO_SAILSS_QTMR_QTMR_AC_HW_FRAME_SEL_1_RMSK                        0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_AC_HW_FRAME_SEL_1_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_AC_HW_FRAME_SEL_1_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_AC_HW_FRAME_SEL_1_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_AC_HW_FRAME_SEL_1_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_AC_HW_FRAME_SEL_1_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_AC_HW_FRAME_SEL_1_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_AC_HW_FRAME_SEL_1_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_AC_HW_FRAME_SEL_1_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_AC_HW_FRAME_SEL_1_IN)
#define HWIO_SAILSS_QTMR_QTMR_AC_HW_FRAME_SEL_1_HW_FRAME_SEL1_BMSK          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_AC_HW_FRAME_SEL_1_HW_FRAME_SEL1_SHFT                   0

#define HWIO_SAILSS_QTMR_QTMR_AC_HW_FRAME_SEL_2_ADDR                        (SAILSS_QTMR_QTMR_AC_REG_BASE            + 0xff0)
#define HWIO_SAILSS_QTMR_QTMR_AC_HW_FRAME_SEL_2_OFFS                        (SAILSS_QTMR_QTMR_AC_REG_BASE_OFFS + 0xff0)
#define HWIO_SAILSS_QTMR_QTMR_AC_HW_FRAME_SEL_2_RMSK                        0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_AC_HW_FRAME_SEL_2_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_AC_HW_FRAME_SEL_2_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_AC_HW_FRAME_SEL_2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_AC_HW_FRAME_SEL_2_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_AC_HW_FRAME_SEL_2_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_AC_HW_FRAME_SEL_2_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_AC_HW_FRAME_SEL_2_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_AC_HW_FRAME_SEL_2_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_AC_HW_FRAME_SEL_2_IN)
#define HWIO_SAILSS_QTMR_QTMR_AC_HW_FRAME_SEL_2_HW_FRAME_SEL2_BMSK          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_AC_HW_FRAME_SEL_2_HW_FRAME_SEL2_SHFT                   0

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_QTMR_QTMR_WDT_CTL
 *--------------------------------------------------------------------------*/

#define SAILSS_QTMR_QTMR_WDT_CTL_REG_BASE                              (SAILSS_QTMR_SAILSS_QTMR_BASE            + 0x0000e000)
#define SAILSS_QTMR_QTMR_WDT_CTL_REG_BASE_SIZE                         0x1000
#define SAILSS_QTMR_QTMR_WDT_CTL_REG_BASE_USED                         0xfe8
#define SAILSS_QTMR_QTMR_WDT_CTL_REG_BASE_OFFS                         0x0000e000

#define HWIO_SAILSS_QTMR_QTMR_WDT_CSR_ADDR                             (SAILSS_QTMR_QTMR_WDT_CTL_REG_BASE            + 0x0)
#define HWIO_SAILSS_QTMR_QTMR_WDT_CSR_OFFS                             (SAILSS_QTMR_QTMR_WDT_CTL_REG_BASE_OFFS + 0x0)
#define HWIO_SAILSS_QTMR_QTMR_WDT_CSR_RMSK                                    0xf
#define HWIO_SAILSS_QTMR_QTMR_WDT_CSR_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_WDT_CSR_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_WDT_CSR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_WDT_CSR_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_WDT_CSR_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_WDT_CSR_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_WDT_CSR_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_WDT_CSR_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_WDT_CSR_IN)
#define HWIO_SAILSS_QTMR_QTMR_WDT_CSR_WDT_FREEZE_EN_BMSK                      0x8
#define HWIO_SAILSS_QTMR_QTMR_WDT_CSR_WDT_FREEZE_EN_SHFT                        3
#define HWIO_SAILSS_QTMR_QTMR_WDT_CSR_WS1_BMSK                                0x4
#define HWIO_SAILSS_QTMR_QTMR_WDT_CSR_WS1_SHFT                                  2
#define HWIO_SAILSS_QTMR_QTMR_WDT_CSR_WS0_BMSK                                0x2
#define HWIO_SAILSS_QTMR_QTMR_WDT_CSR_WS0_SHFT                                  1
#define HWIO_SAILSS_QTMR_QTMR_WDT_CSR_WDT_EN_BMSK                             0x1
#define HWIO_SAILSS_QTMR_QTMR_WDT_CSR_WDT_EN_SHFT                               0

#define HWIO_SAILSS_QTMR_QTMR_WDT_OFFSET_ADDR                          (SAILSS_QTMR_QTMR_WDT_CTL_REG_BASE            + 0x8)
#define HWIO_SAILSS_QTMR_QTMR_WDT_OFFSET_OFFS                          (SAILSS_QTMR_QTMR_WDT_CTL_REG_BASE_OFFS + 0x8)
#define HWIO_SAILSS_QTMR_QTMR_WDT_OFFSET_RMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_WDT_OFFSET_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_WDT_OFFSET_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_WDT_OFFSET_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_WDT_OFFSET_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_WDT_OFFSET_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_WDT_OFFSET_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_WDT_OFFSET_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_WDT_OFFSET_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_WDT_OFFSET_IN)
#define HWIO_SAILSS_QTMR_QTMR_WDT_OFFSET_WDT_OFFSET_BMSK               0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_WDT_OFFSET_WDT_OFFSET_SHFT                        0

#define HWIO_SAILSS_QTMR_QTMR_WDT_CVAL_LO_ADDR                         (SAILSS_QTMR_QTMR_WDT_CTL_REG_BASE            + 0x10)
#define HWIO_SAILSS_QTMR_QTMR_WDT_CVAL_LO_OFFS                         (SAILSS_QTMR_QTMR_WDT_CTL_REG_BASE_OFFS + 0x10)
#define HWIO_SAILSS_QTMR_QTMR_WDT_CVAL_LO_RMSK                         0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_WDT_CVAL_LO_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_WDT_CVAL_LO_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_WDT_CVAL_LO_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_WDT_CVAL_LO_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_WDT_CVAL_LO_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_WDT_CVAL_LO_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_WDT_CVAL_LO_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_WDT_CVAL_LO_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_WDT_CVAL_LO_IN)
#define HWIO_SAILSS_QTMR_QTMR_WDT_CVAL_LO_CVAL_LO_BMSK                 0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_WDT_CVAL_LO_CVAL_LO_SHFT                          0

#define HWIO_SAILSS_QTMR_QTMR_WDT_CVAL_HI_ADDR                         (SAILSS_QTMR_QTMR_WDT_CTL_REG_BASE            + 0x14)
#define HWIO_SAILSS_QTMR_QTMR_WDT_CVAL_HI_OFFS                         (SAILSS_QTMR_QTMR_WDT_CTL_REG_BASE_OFFS + 0x14)
#define HWIO_SAILSS_QTMR_QTMR_WDT_CVAL_HI_RMSK                           0xffffff
#define HWIO_SAILSS_QTMR_QTMR_WDT_CVAL_HI_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_WDT_CVAL_HI_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_WDT_CVAL_HI_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_WDT_CVAL_HI_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_WDT_CVAL_HI_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_WDT_CVAL_HI_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_WDT_CVAL_HI_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_QTMR_QTMR_WDT_CVAL_HI_ADDR,m,v,HWIO_SAILSS_QTMR_QTMR_WDT_CVAL_HI_IN)
#define HWIO_SAILSS_QTMR_QTMR_WDT_CVAL_HI_CVAL_HI_BMSK                   0xffffff
#define HWIO_SAILSS_QTMR_QTMR_WDT_CVAL_HI_CVAL_HI_SHFT                          0

#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_IIDR_ADDR                        (SAILSS_QTMR_QTMR_WDT_CTL_REG_BASE            + 0xfcc)
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_IIDR_OFFS                        (SAILSS_QTMR_QTMR_WDT_CTL_REG_BASE_OFFS + 0xfcc)
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_IIDR_RMSK                        0xffffff7f
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_IIDR_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_WDT_CTL_IIDR_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_IIDR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_WDT_CTL_IIDR_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_IIDR_PDT_ID_BMSK                 0xfff00000
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_IIDR_PDT_ID_SHFT                         20
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_IIDR_ARCH_VERSION_BMSK              0xf0000
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_IIDR_ARCH_VERSION_SHFT                   16
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_IIDR_IMPL_REV_BMSK                   0xf000
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_IIDR_IMPL_REV_SHFT                       12
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_IIDR_JEP_CONT_CODE_BMSK               0xf00
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_IIDR_JEP_CONT_CODE_SHFT                   8
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_IIDR_JEP_ID_CODE_BMSK                  0x7f
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_IIDR_JEP_ID_CODE_SHFT                     0

#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_VERSION_ADDR                     (SAILSS_QTMR_QTMR_WDT_CTL_REG_BASE            + 0xfd0)
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_VERSION_OFFS                     (SAILSS_QTMR_QTMR_WDT_CTL_REG_BASE_OFFS + 0xfd0)
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_VERSION_RMSK                     0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_VERSION_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_WDT_CTL_VERSION_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_VERSION_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_WDT_CTL_VERSION_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_VERSION_MAJOR_BMSK               0xf0000000
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_VERSION_MAJOR_SHFT                       28
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_VERSION_MINOR_BMSK                0xfff0000
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_VERSION_MINOR_SHFT                       16
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_VERSION_STEP_BMSK                    0xffff
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_VERSION_STEP_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_PIDR2_ADDR                       (SAILSS_QTMR_QTMR_WDT_CTL_REG_BASE            + 0xfe8)
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_PIDR2_OFFS                       (SAILSS_QTMR_QTMR_WDT_CTL_REG_BASE_OFFS + 0xfe8)
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_PIDR2_RMSK                       0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_PIDR2_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_WDT_CTL_PIDR2_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_PIDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_WDT_CTL_PIDR2_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_PIDR2_PIDR_FLD2_BMSK             0xffffff00
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_PIDR2_PIDR_FLD2_SHFT                      8
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_PIDR2_ARCH_REV_BMSK                    0xf0
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_PIDR2_ARCH_REV_SHFT                       4
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_PIDR2_PIDR_FLD1_BMSK                    0xf
#define HWIO_SAILSS_QTMR_QTMR_WDT_CTL_PIDR2_PIDR_FLD1_SHFT                      0

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_QTMR_QTMR_WDT_REFRESH
 *--------------------------------------------------------------------------*/

#define SAILSS_QTMR_QTMR_WDT_REFRESH_REG_BASE                          (SAILSS_QTMR_SAILSS_QTMR_BASE            + 0x0000d000)
#define SAILSS_QTMR_QTMR_WDT_REFRESH_REG_BASE_SIZE                     0x1000
#define SAILSS_QTMR_QTMR_WDT_REFRESH_REG_BASE_USED                     0xfe8
#define SAILSS_QTMR_QTMR_WDT_REFRESH_REG_BASE_OFFS                     0x0000d000

#define HWIO_SAILSS_QTMR_QTMR_WDT_RR_ADDR                              (SAILSS_QTMR_QTMR_WDT_REFRESH_REG_BASE            + 0x0)
#define HWIO_SAILSS_QTMR_QTMR_WDT_RR_OFFS                              (SAILSS_QTMR_QTMR_WDT_REFRESH_REG_BASE_OFFS + 0x0)
#define HWIO_SAILSS_QTMR_QTMR_WDT_RR_RMSK                              0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_WDT_RR_OUT(v)            \
                out_dword(HWIO_SAILSS_QTMR_QTMR_WDT_RR_ADDR,v)
#define HWIO_SAILSS_QTMR_QTMR_WDT_RR_WRR_BMSK                          0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_WDT_RR_WRR_SHFT                                   0

#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_IIDR_ADDR                        (SAILSS_QTMR_QTMR_WDT_REFRESH_REG_BASE            + 0xfcc)
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_IIDR_OFFS                        (SAILSS_QTMR_QTMR_WDT_REFRESH_REG_BASE_OFFS + 0xfcc)
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_IIDR_RMSK                        0xffffff7f
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_IIDR_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_WDT_REF_IIDR_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_IIDR_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_WDT_REF_IIDR_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_IIDR_PDT_ID_BMSK                 0xfff00000
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_IIDR_PDT_ID_SHFT                         20
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_IIDR_ARCH_VERSION_BMSK              0xf0000
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_IIDR_ARCH_VERSION_SHFT                   16
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_IIDR_IMPL_REV_BMSK                   0xf000
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_IIDR_IMPL_REV_SHFT                       12
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_IIDR_JEP_CONT_CODE_BMSK               0xf00
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_IIDR_JEP_CONT_CODE_SHFT                   8
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_IIDR_JEP_ID_CODE_BMSK                  0x7f
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_IIDR_JEP_ID_CODE_SHFT                     0

#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_VERSION_ADDR                     (SAILSS_QTMR_QTMR_WDT_REFRESH_REG_BASE            + 0xfd0)
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_VERSION_OFFS                     (SAILSS_QTMR_QTMR_WDT_REFRESH_REG_BASE_OFFS + 0xfd0)
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_VERSION_RMSK                     0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_VERSION_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_WDT_REF_VERSION_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_VERSION_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_WDT_REF_VERSION_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_VERSION_MAJOR_BMSK               0xf0000000
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_VERSION_MAJOR_SHFT                       28
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_VERSION_MINOR_BMSK                0xfff0000
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_VERSION_MINOR_SHFT                       16
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_VERSION_STEP_BMSK                    0xffff
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_VERSION_STEP_SHFT                         0

#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_PIDR2_ADDR                       (SAILSS_QTMR_QTMR_WDT_REFRESH_REG_BASE            + 0xfe8)
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_PIDR2_OFFS                       (SAILSS_QTMR_QTMR_WDT_REFRESH_REG_BASE_OFFS + 0xfe8)
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_PIDR2_RMSK                       0xffffffff
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_PIDR2_IN                    \
                in_dword(HWIO_SAILSS_QTMR_QTMR_WDT_REF_PIDR2_ADDR)
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_PIDR2_INM(m)            \
                in_dword_masked(HWIO_SAILSS_QTMR_QTMR_WDT_REF_PIDR2_ADDR, m)
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_PIDR2_PIDR_FLD2_BMSK             0xffffff00
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_PIDR2_PIDR_FLD2_SHFT                      8
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_PIDR2_ARCH_VERSION_BMSK                0xf0
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_PIDR2_ARCH_VERSION_SHFT                   4
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_PIDR2_PIDR_FLD1_BMSK                    0xf
#define HWIO_SAILSS_QTMR_QTMR_WDT_REF_PIDR2_PIDR_FLD1_SHFT                      0


#endif /* __SAIL_QTIMER_H__ */
