#ifndef __SAIL_OSPI_HWIO_H__
#define __SAIL_OSPI_HWIO_H__
/*
===========================================================================
*/
/**
    @file sail_ospi_hwio.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        LeMansAU [lemansau_v1.0_p3q1r37]
 
    This file contains HWIO register definitions for the following modules:
        SAILSS_QSPI


    Generation parameters: 
    { 'explicit-addressing': True,
      'filename': 'sail_ospi_hwio.h',
      'header': '#include "msmhwiobase.h"',
      'ignore-prefixes': True,
      'modules': ['SAILSS_QSPI'],
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

    $Header: //components/dev/bsp.sail/1.0/rmunibyr.bsp.sail.1.0.rmunibyr_safertos1/spinor/inc/driver/8650/sail_ospi_hwio.h#1 $
    $DateTime: 2025/07/09 22:36:30 $
    $Author: rmunibyr $

    ===========================================================================
*/
#include "msmhwiobase.h"

/*----------------------------------------------------------------------------
 * MODULE: QSPI
 *--------------------------------------------------------------------------*/

#define QSPI_REG_BASE                                                                               (SAILSS_QSPI_QSPI_TOP_BASE      + 0x00000000)
#define QSPI_REG_BASE_SIZE                                                                          0x1000
#define QSPI_REG_BASE_USED                                                                          0x334
#define QSPI_REG_BASE_PHYS                                                                          (SAILSS_QSPI_QSPI_TOP_BASE_PHYS + 0x00000000)
#define QSPI_REG_BASE_OFFS                                                                          0x00000000

#define HWIO_QSPI_MSTR_CONFIG_ADDR(x)                                                               ((x) + 0x0)
#define HWIO_QSPI_MSTR_CONFIG_PHYS(x)                                                               ((x) + 0x0)
#define HWIO_QSPI_MSTR_CONFIG_OFFS                                                                  (0x0)
#define HWIO_QSPI_MSTR_CONFIG_RMSK                                                                  0xffffffdc
#define HWIO_QSPI_MSTR_CONFIG_IN(x)            \
                in_dword(HWIO_QSPI_MSTR_CONFIG_ADDR(x))
#define HWIO_QSPI_MSTR_CONFIG_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_MSTR_CONFIG_ADDR(x), m)
#define HWIO_QSPI_MSTR_CONFIG_OUT(x, v)            \
                out_dword(HWIO_QSPI_MSTR_CONFIG_ADDR(x),v)
#define HWIO_QSPI_MSTR_CONFIG_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_QSPI_MSTR_CONFIG_ADDR(x),m,v,HWIO_QSPI_MSTR_CONFIG_IN(x))
#define HWIO_QSPI_MSTR_CONFIG_MISO_DELAYED_BMSK                                                     0x80000000
#define HWIO_QSPI_MSTR_CONFIG_MISO_DELAYED_SHFT                                                             31
#define HWIO_QSPI_MSTR_CONFIG_LPA_BASE_SELECT_BMSK                                                  0x40000000
#define HWIO_QSPI_MSTR_CONFIG_LPA_BASE_SELECT_SHFT                                                          30
#define HWIO_QSPI_MSTR_CONFIG_LPA_BASE_DATA_DESC_BMSK                                               0x3c000000
#define HWIO_QSPI_MSTR_CONFIG_LPA_BASE_DATA_DESC_SHFT                                                       26
#define HWIO_QSPI_MSTR_CONFIG_TX_DATA_OE_DELAY_BMSK                                                  0x3000000
#define HWIO_QSPI_MSTR_CONFIG_TX_DATA_OE_DELAY_SHFT                                                         24
#define HWIO_QSPI_MSTR_CONFIG_TX_CS_N_DELAY_BMSK                                                      0xc00000
#define HWIO_QSPI_MSTR_CONFIG_TX_CS_N_DELAY_SHFT                                                            22
#define HWIO_QSPI_MSTR_CONFIG_TX_CLK_DELAY_BMSK                                                       0x300000
#define HWIO_QSPI_MSTR_CONFIG_TX_CLK_DELAY_SHFT                                                             20
#define HWIO_QSPI_MSTR_CONFIG_TX_DATA_DELAY_BMSK                                                       0xc0000
#define HWIO_QSPI_MSTR_CONFIG_TX_DATA_DELAY_SHFT                                                            18
#define HWIO_QSPI_MSTR_CONFIG_LPA_BASE_BMSK                                                            0x3c000
#define HWIO_QSPI_MSTR_CONFIG_LPA_BASE_SHFT                                                                 14
#define HWIO_QSPI_MSTR_CONFIG_SBL_EN_BMSK                                                               0x2000
#define HWIO_QSPI_MSTR_CONFIG_SBL_EN_SHFT                                                                   13
#define HWIO_QSPI_MSTR_CONFIG_CHIP_SELECT_NUM_BMSK                                                      0x1000
#define HWIO_QSPI_MSTR_CONFIG_CHIP_SELECT_NUM_SHFT                                                          12
#define HWIO_QSPI_MSTR_CONFIG_SPI_MODE_BMSK                                                              0xc00
#define HWIO_QSPI_MSTR_CONFIG_SPI_MODE_SHFT                                                                 10
#define HWIO_QSPI_MSTR_CONFIG_BIG_ENDIAN_MODE_BMSK                                                       0x200
#define HWIO_QSPI_MSTR_CONFIG_BIG_ENDIAN_MODE_SHFT                                                           9
#define HWIO_QSPI_MSTR_CONFIG_DMA_ENABLE_BMSK                                                            0x100
#define HWIO_QSPI_MSTR_CONFIG_DMA_ENABLE_SHFT                                                                8
#define HWIO_QSPI_MSTR_CONFIG_PIN_WPN_BMSK                                                                0x80
#define HWIO_QSPI_MSTR_CONFIG_PIN_WPN_SHFT                                                                   7
#define HWIO_QSPI_MSTR_CONFIG_PIN_HOLDN_BMSK                                                              0x40
#define HWIO_QSPI_MSTR_CONFIG_PIN_HOLDN_SHFT                                                                 6
#define HWIO_QSPI_MSTR_CONFIG_FB_CLK_EN_BMSK                                                              0x10
#define HWIO_QSPI_MSTR_CONFIG_FB_CLK_EN_SHFT                                                                 4
#define HWIO_QSPI_MSTR_CONFIG_FULL_CYCLE_MODE_BMSK                                                         0x8
#define HWIO_QSPI_MSTR_CONFIG_FULL_CYCLE_MODE_SHFT                                                           3
#define HWIO_QSPI_MSTR_CONFIG_CS_ADVANCED_BMSK                                                             0x4
#define HWIO_QSPI_MSTR_CONFIG_CS_ADVANCED_SHFT                                                               2

#define HWIO_QSPI_AHB_MASTER_CFG_ADDR(x)                                                            ((x) + 0x4)
#define HWIO_QSPI_AHB_MASTER_CFG_PHYS(x)                                                            ((x) + 0x4)
#define HWIO_QSPI_AHB_MASTER_CFG_OFFS                                                               (0x4)
#define HWIO_QSPI_AHB_MASTER_CFG_RMSK                                                                   0x3fff
#define HWIO_QSPI_AHB_MASTER_CFG_IN(x)            \
                in_dword(HWIO_QSPI_AHB_MASTER_CFG_ADDR(x))
#define HWIO_QSPI_AHB_MASTER_CFG_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_AHB_MASTER_CFG_ADDR(x), m)
#define HWIO_QSPI_AHB_MASTER_CFG_OUT(x, v)            \
                out_dword(HWIO_QSPI_AHB_MASTER_CFG_ADDR(x),v)
#define HWIO_QSPI_AHB_MASTER_CFG_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_QSPI_AHB_MASTER_CFG_ADDR(x),m,v,HWIO_QSPI_AHB_MASTER_CFG_IN(x))
#define HWIO_QSPI_AHB_MASTER_CFG_DMA_DONE_WAIT4RDY_DISABLE_BMSK                                         0x2000
#define HWIO_QSPI_AHB_MASTER_CFG_DMA_DONE_WAIT4RDY_DISABLE_SHFT                                             13
#define HWIO_QSPI_AHB_MASTER_CFG_HINNERSHARED_BMSK                                                      0x1000
#define HWIO_QSPI_AHB_MASTER_CFG_HINNERSHARED_SHFT                                                          12
#define HWIO_QSPI_AHB_MASTER_CFG_HSHARED_BMSK                                                            0x800
#define HWIO_QSPI_AHB_MASTER_CFG_HSHARED_SHFT                                                               11
#define HWIO_QSPI_AHB_MASTER_CFG_HMEMTYPE_READ_TRANS_BMSK                                                0x700
#define HWIO_QSPI_AHB_MASTER_CFG_HMEMTYPE_READ_TRANS_SHFT                                                    8
#define HWIO_QSPI_AHB_MASTER_CFG_USE_HMEMTYPE_LAST_ON_DESC_OR_CHAIN_BMSK                                  0xc0
#define HWIO_QSPI_AHB_MASTER_CFG_USE_HMEMTYPE_LAST_ON_DESC_OR_CHAIN_SHFT                                     6
#define HWIO_QSPI_AHB_MASTER_CFG_HMEMTYPE_LAST_TRANS_BMSK                                                 0x38
#define HWIO_QSPI_AHB_MASTER_CFG_HMEMTYPE_LAST_TRANS_SHFT                                                    3
#define HWIO_QSPI_AHB_MASTER_CFG_HMEMTYPE_START_MID_TRANS_BMSK                                             0x7
#define HWIO_QSPI_AHB_MASTER_CFG_HMEMTYPE_START_MID_TRANS_SHFT                                               0

#define HWIO_QSPI_REF_CLK_GATE_CFG_ADDR(x)                                                          ((x) + 0x8)
#define HWIO_QSPI_REF_CLK_GATE_CFG_PHYS(x)                                                          ((x) + 0x8)
#define HWIO_QSPI_REF_CLK_GATE_CFG_OFFS                                                             (0x8)
#define HWIO_QSPI_REF_CLK_GATE_CFG_RMSK                                                             0x800000ff
#define HWIO_QSPI_REF_CLK_GATE_CFG_IN(x)            \
                in_dword(HWIO_QSPI_REF_CLK_GATE_CFG_ADDR(x))
#define HWIO_QSPI_REF_CLK_GATE_CFG_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_REF_CLK_GATE_CFG_ADDR(x), m)
#define HWIO_QSPI_REF_CLK_GATE_CFG_OUT(x, v)            \
                out_dword(HWIO_QSPI_REF_CLK_GATE_CFG_ADDR(x),v)
#define HWIO_QSPI_REF_CLK_GATE_CFG_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_QSPI_REF_CLK_GATE_CFG_ADDR(x),m,v,HWIO_QSPI_REF_CLK_GATE_CFG_IN(x))
#define HWIO_QSPI_REF_CLK_GATE_CFG_REF_CLK_GATE_EN_BMSK                                             0x80000000
#define HWIO_QSPI_REF_CLK_GATE_CFG_REF_CLK_GATE_EN_SHFT                                                     31
#define HWIO_QSPI_REF_CLK_GATE_CFG_REF_CLK_GATE_WAIT_CNT_BMSK                                             0xff
#define HWIO_QSPI_REF_CLK_GATE_CFG_REF_CLK_GATE_WAIT_CNT_SHFT                                                0

#define HWIO_QSPI_MSTR_INT_ENABLE_ADDR(x)                                                           ((x) + 0xc)
#define HWIO_QSPI_MSTR_INT_ENABLE_PHYS(x)                                                           ((x) + 0xc)
#define HWIO_QSPI_MSTR_INT_ENABLE_OFFS                                                              (0xc)
#define HWIO_QSPI_MSTR_INT_ENABLE_RMSK                                                              0xf0030e0f
#define HWIO_QSPI_MSTR_INT_ENABLE_IN(x)            \
                in_dword(HWIO_QSPI_MSTR_INT_ENABLE_ADDR(x))
#define HWIO_QSPI_MSTR_INT_ENABLE_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_MSTR_INT_ENABLE_ADDR(x), m)
#define HWIO_QSPI_MSTR_INT_ENABLE_OUT(x, v)            \
                out_dword(HWIO_QSPI_MSTR_INT_ENABLE_ADDR(x),v)
#define HWIO_QSPI_MSTR_INT_ENABLE_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_QSPI_MSTR_INT_ENABLE_ADDR(x),m,v,HWIO_QSPI_MSTR_INT_ENABLE_IN(x))
#define HWIO_QSPI_MSTR_INT_ENABLE_EN_DMA_CHAIN_DONE_BMSK                                            0x80000000
#define HWIO_QSPI_MSTR_INT_ENABLE_EN_DMA_CHAIN_DONE_SHFT                                                    31
#define HWIO_QSPI_MSTR_INT_ENABLE_EN_XIP_ACCESS_DURING_DMA_BMSK                                     0x40000000
#define HWIO_QSPI_MSTR_INT_ENABLE_EN_XIP_ACCESS_DURING_DMA_SHFT                                             30
#define HWIO_QSPI_MSTR_INT_ENABLE_EN_XIP_ACCESS_UNMAPPED_SEGMENT_BMSK                               0x20000000
#define HWIO_QSPI_MSTR_INT_ENABLE_EN_XIP_ACCESS_UNMAPPED_SEGMENT_SHFT                                       29
#define HWIO_QSPI_MSTR_INT_ENABLE_EN_XIP_ACCESS_NOT_ENABLE_BMSK                                     0x10000000
#define HWIO_QSPI_MSTR_INT_ENABLE_EN_XIP_ACCESS_NOT_ENABLE_SHFT                                             28
#define HWIO_QSPI_MSTR_INT_ENABLE_EN_DMA_ACCESS_DURING_XIP_BMSK                                        0x20000
#define HWIO_QSPI_MSTR_INT_ENABLE_EN_DMA_ACCESS_DURING_XIP_SHFT                                             17
#define HWIO_QSPI_MSTR_INT_ENABLE_EN_TRANSACTION_DONE_BMSK                                             0x10000
#define HWIO_QSPI_MSTR_INT_ENABLE_EN_TRANSACTION_DONE_SHFT                                                  16
#define HWIO_QSPI_MSTR_INT_ENABLE_EN_WRITE_FIFO_OVERRUN_BMSK                                             0x800
#define HWIO_QSPI_MSTR_INT_ENABLE_EN_WRITE_FIFO_OVERRUN_SHFT                                                11
#define HWIO_QSPI_MSTR_INT_ENABLE_EN_WRITE_FIFO_FULL_BMSK                                                0x400
#define HWIO_QSPI_MSTR_INT_ENABLE_EN_WRITE_FIFO_FULL_SHFT                                                   10
#define HWIO_QSPI_MSTR_INT_ENABLE_EN_WRITE_FIFO_EMPTY_BMSK                                               0x200
#define HWIO_QSPI_MSTR_INT_ENABLE_EN_WRITE_FIFO_EMPTY_SHFT                                                   9
#define HWIO_QSPI_MSTR_INT_ENABLE_EN_HRESP_FROM_NOC_ERR_BMSK                                               0x8
#define HWIO_QSPI_MSTR_INT_ENABLE_EN_HRESP_FROM_NOC_ERR_SHFT                                                 3
#define HWIO_QSPI_MSTR_INT_ENABLE_EN_RESP_FIFO_RDY_BMSK                                                    0x4
#define HWIO_QSPI_MSTR_INT_ENABLE_EN_RESP_FIFO_RDY_SHFT                                                      2
#define HWIO_QSPI_MSTR_INT_ENABLE_EN_RESP_FIFO_NOT_EMPTY_BMSK                                              0x2
#define HWIO_QSPI_MSTR_INT_ENABLE_EN_RESP_FIFO_NOT_EMPTY_SHFT                                                1
#define HWIO_QSPI_MSTR_INT_ENABLE_EN_RESP_FIFO_UNDERRUN_BMSK                                               0x1
#define HWIO_QSPI_MSTR_INT_ENABLE_EN_RESP_FIFO_UNDERRUN_SHFT                                                 0

#define HWIO_QSPI_MSTR_INT_STATUS_ADDR(x)                                                           ((x) + 0x10)
#define HWIO_QSPI_MSTR_INT_STATUS_PHYS(x)                                                           ((x) + 0x10)
#define HWIO_QSPI_MSTR_INT_STATUS_OFFS                                                              (0x10)
#define HWIO_QSPI_MSTR_INT_STATUS_RMSK                                                              0xf8030e0f
#define HWIO_QSPI_MSTR_INT_STATUS_IN(x)            \
                in_dword(HWIO_QSPI_MSTR_INT_STATUS_ADDR(x))
#define HWIO_QSPI_MSTR_INT_STATUS_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_MSTR_INT_STATUS_ADDR(x), m)
#define HWIO_QSPI_MSTR_INT_STATUS_OUT(x, v)            \
                out_dword(HWIO_QSPI_MSTR_INT_STATUS_ADDR(x),v)
#define HWIO_QSPI_MSTR_INT_STATUS_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_QSPI_MSTR_INT_STATUS_ADDR(x),m,v,HWIO_QSPI_MSTR_INT_STATUS_IN(x))
#define HWIO_QSPI_MSTR_INT_STATUS_DMA_CHAIN_DONE_BMSK                                               0x80000000
#define HWIO_QSPI_MSTR_INT_STATUS_DMA_CHAIN_DONE_SHFT                                                       31
#define HWIO_QSPI_MSTR_INT_STATUS_XIP_ACCESS_DURING_DMA_BMSK                                        0x40000000
#define HWIO_QSPI_MSTR_INT_STATUS_XIP_ACCESS_DURING_DMA_SHFT                                                30
#define HWIO_QSPI_MSTR_INT_STATUS_XIP_ACCESS_UNMAPPED_SEGMENT_BMSK                                  0x20000000
#define HWIO_QSPI_MSTR_INT_STATUS_XIP_ACCESS_UNMAPPED_SEGMENT_SHFT                                          29
#define HWIO_QSPI_MSTR_INT_STATUS_XIP_ACCESS_NOT_ENABLE_BMSK                                        0x10000000
#define HWIO_QSPI_MSTR_INT_STATUS_XIP_ACCESS_NOT_ENABLE_SHFT                                                28
#define HWIO_QSPI_MSTR_INT_STATUS_DMA_STATUS_BMSK                                                    0x8000000
#define HWIO_QSPI_MSTR_INT_STATUS_DMA_STATUS_SHFT                                                           27
#define HWIO_QSPI_MSTR_INT_STATUS_DMA_ACCESS_DURING_XIP_BMSK                                           0x20000
#define HWIO_QSPI_MSTR_INT_STATUS_DMA_ACCESS_DURING_XIP_SHFT                                                17
#define HWIO_QSPI_MSTR_INT_STATUS_TRANSACTION_DONE_BMSK                                                0x10000
#define HWIO_QSPI_MSTR_INT_STATUS_TRANSACTION_DONE_SHFT                                                     16
#define HWIO_QSPI_MSTR_INT_STATUS_WRITE_FIFO_OVERRUN_BMSK                                                0x800
#define HWIO_QSPI_MSTR_INT_STATUS_WRITE_FIFO_OVERRUN_SHFT                                                   11
#define HWIO_QSPI_MSTR_INT_STATUS_WRITE_FIFO_FULL_BMSK                                                   0x400
#define HWIO_QSPI_MSTR_INT_STATUS_WRITE_FIFO_FULL_SHFT                                                      10
#define HWIO_QSPI_MSTR_INT_STATUS_WRITE_FIFO_EMPTY_BMSK                                                  0x200
#define HWIO_QSPI_MSTR_INT_STATUS_WRITE_FIFO_EMPTY_SHFT                                                      9
#define HWIO_QSPI_MSTR_INT_STATUS_HRESP_FROM_NOC_ERR_BMSK                                                  0x8
#define HWIO_QSPI_MSTR_INT_STATUS_HRESP_FROM_NOC_ERR_SHFT                                                    3
#define HWIO_QSPI_MSTR_INT_STATUS_RESP_FIFO_RDY_BMSK                                                       0x4
#define HWIO_QSPI_MSTR_INT_STATUS_RESP_FIFO_RDY_SHFT                                                         2
#define HWIO_QSPI_MSTR_INT_STATUS_RESP_FIFO_NOT_EMPTY_BMSK                                                 0x2
#define HWIO_QSPI_MSTR_INT_STATUS_RESP_FIFO_NOT_EMPTY_SHFT                                                   1
#define HWIO_QSPI_MSTR_INT_STATUS_RESP_FIFO_UNDERRUN_BMSK                                                  0x1
#define HWIO_QSPI_MSTR_INT_STATUS_RESP_FIFO_UNDERRUN_SHFT                                                    0

#define HWIO_QSPI_PIO_TRANSFER_CONTROL_ADDR(x)                                                      ((x) + 0x14)
#define HWIO_QSPI_PIO_TRANSFER_CONTROL_PHYS(x)                                                      ((x) + 0x14)
#define HWIO_QSPI_PIO_TRANSFER_CONTROL_OFFS                                                         (0x14)
#define HWIO_QSPI_PIO_TRANSFER_CONTROL_RMSK                                                             0xffff
#define HWIO_QSPI_PIO_TRANSFER_CONTROL_IN(x)            \
                in_dword(HWIO_QSPI_PIO_TRANSFER_CONTROL_ADDR(x))
#define HWIO_QSPI_PIO_TRANSFER_CONTROL_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_PIO_TRANSFER_CONTROL_ADDR(x), m)
#define HWIO_QSPI_PIO_TRANSFER_CONTROL_OUT(x, v)            \
                out_dword(HWIO_QSPI_PIO_TRANSFER_CONTROL_ADDR(x),v)
#define HWIO_QSPI_PIO_TRANSFER_CONTROL_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_QSPI_PIO_TRANSFER_CONTROL_ADDR(x),m,v,HWIO_QSPI_PIO_TRANSFER_CONTROL_IN(x))
#define HWIO_QSPI_PIO_TRANSFER_CONTROL_REQUEST_COUNT_BMSK                                               0xffff
#define HWIO_QSPI_PIO_TRANSFER_CONTROL_REQUEST_COUNT_SHFT                                                    0

#define HWIO_QSPI_PIO_TRANSFER_CONFIG_ADDR(x)                                                       ((x) + 0x18)
#define HWIO_QSPI_PIO_TRANSFER_CONFIG_PHYS(x)                                                       ((x) + 0x18)
#define HWIO_QSPI_PIO_TRANSFER_CONFIG_OFFS                                                          (0x18)
#define HWIO_QSPI_PIO_TRANSFER_CONFIG_RMSK                                                               0x10f
#define HWIO_QSPI_PIO_TRANSFER_CONFIG_IN(x)            \
                in_dword(HWIO_QSPI_PIO_TRANSFER_CONFIG_ADDR(x))
#define HWIO_QSPI_PIO_TRANSFER_CONFIG_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_PIO_TRANSFER_CONFIG_ADDR(x), m)
#define HWIO_QSPI_PIO_TRANSFER_CONFIG_OUT(x, v)            \
                out_dword(HWIO_QSPI_PIO_TRANSFER_CONFIG_ADDR(x),v)
#define HWIO_QSPI_PIO_TRANSFER_CONFIG_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_QSPI_PIO_TRANSFER_CONFIG_ADDR(x),m,v,HWIO_QSPI_PIO_TRANSFER_CONFIG_IN(x))
#define HWIO_QSPI_PIO_TRANSFER_CONFIG_TRANSFER_FRAGMENT_BMSK                                             0x100
#define HWIO_QSPI_PIO_TRANSFER_CONFIG_TRANSFER_FRAGMENT_SHFT                                                 8
#define HWIO_QSPI_PIO_TRANSFER_CONFIG_MULTI_IO_MODE_BMSK                                                   0xe
#define HWIO_QSPI_PIO_TRANSFER_CONFIG_MULTI_IO_MODE_SHFT                                                     1
#define HWIO_QSPI_PIO_TRANSFER_CONFIG_TRANSFER_DIRECTION_BMSK                                              0x1
#define HWIO_QSPI_PIO_TRANSFER_CONFIG_TRANSFER_DIRECTION_SHFT                                                0

#define HWIO_QSPI_PIO_TRANSFER_STATUS_ADDR(x)                                                       ((x) + 0x1c)
#define HWIO_QSPI_PIO_TRANSFER_STATUS_PHYS(x)                                                       ((x) + 0x1c)
#define HWIO_QSPI_PIO_TRANSFER_STATUS_OFFS                                                          (0x1c)
#define HWIO_QSPI_PIO_TRANSFER_STATUS_RMSK                                                          0xffff0000
#define HWIO_QSPI_PIO_TRANSFER_STATUS_IN(x)            \
                in_dword(HWIO_QSPI_PIO_TRANSFER_STATUS_ADDR(x))
#define HWIO_QSPI_PIO_TRANSFER_STATUS_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_PIO_TRANSFER_STATUS_ADDR(x), m)
#define HWIO_QSPI_PIO_TRANSFER_STATUS_WR_FIFO_BYTES_BMSK                                            0xffff0000
#define HWIO_QSPI_PIO_TRANSFER_STATUS_WR_FIFO_BYTES_SHFT                                                    16

#define HWIO_QSPI_PIO_DATAOUT_1BYTE_ADDR(x)                                                         ((x) + 0x20)
#define HWIO_QSPI_PIO_DATAOUT_1BYTE_PHYS(x)                                                         ((x) + 0x20)
#define HWIO_QSPI_PIO_DATAOUT_1BYTE_OFFS                                                            (0x20)
#define HWIO_QSPI_PIO_DATAOUT_1BYTE_RMSK                                                                  0xff
#define HWIO_QSPI_PIO_DATAOUT_1BYTE_OUT(x, v)            \
                out_dword(HWIO_QSPI_PIO_DATAOUT_1BYTE_ADDR(x),v)
#define HWIO_QSPI_PIO_DATAOUT_1BYTE_DATAIN_BMSK                                                           0xff
#define HWIO_QSPI_PIO_DATAOUT_1BYTE_DATAIN_SHFT                                                              0

#define HWIO_QSPI_PIO_DATAOUT_4BYTE_ADDR(x)                                                         ((x) + 0x24)
#define HWIO_QSPI_PIO_DATAOUT_4BYTE_PHYS(x)                                                         ((x) + 0x24)
#define HWIO_QSPI_PIO_DATAOUT_4BYTE_OFFS                                                            (0x24)
#define HWIO_QSPI_PIO_DATAOUT_4BYTE_RMSK                                                            0xffffffff
#define HWIO_QSPI_PIO_DATAOUT_4BYTE_OUT(x, v)            \
                out_dword(HWIO_QSPI_PIO_DATAOUT_4BYTE_ADDR(x),v)
#define HWIO_QSPI_PIO_DATAOUT_4BYTE_DATAIN_BMSK                                                     0xffffffff
#define HWIO_QSPI_PIO_DATAOUT_4BYTE_DATAIN_SHFT                                                              0

#define HWIO_QSPI_RD_FIFO_CONFIG_ADDR(x)                                                            ((x) + 0x28)
#define HWIO_QSPI_RD_FIFO_CONFIG_PHYS(x)                                                            ((x) + 0x28)
#define HWIO_QSPI_RD_FIFO_CONFIG_OFFS                                                               (0x28)
#define HWIO_QSPI_RD_FIFO_CONFIG_RMSK                                                                      0x1
#define HWIO_QSPI_RD_FIFO_CONFIG_IN(x)            \
                in_dword(HWIO_QSPI_RD_FIFO_CONFIG_ADDR(x))
#define HWIO_QSPI_RD_FIFO_CONFIG_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_RD_FIFO_CONFIG_ADDR(x), m)
#define HWIO_QSPI_RD_FIFO_CONFIG_OUT(x, v)            \
                out_dword(HWIO_QSPI_RD_FIFO_CONFIG_ADDR(x),v)
#define HWIO_QSPI_RD_FIFO_CONFIG_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_QSPI_RD_FIFO_CONFIG_ADDR(x),m,v,HWIO_QSPI_RD_FIFO_CONFIG_IN(x))
#define HWIO_QSPI_RD_FIFO_CONFIG_CONTINUOUS_MODE_BMSK                                                      0x1
#define HWIO_QSPI_RD_FIFO_CONFIG_CONTINUOUS_MODE_SHFT                                                        0

#define HWIO_QSPI_RD_FIFO_STATUS_ADDR(x)                                                            ((x) + 0x2c)
#define HWIO_QSPI_RD_FIFO_STATUS_PHYS(x)                                                            ((x) + 0x2c)
#define HWIO_QSPI_RD_FIFO_STATUS_OFFS                                                               (0x2c)
#define HWIO_QSPI_RD_FIFO_STATUS_RMSK                                                                    0xfff
#define HWIO_QSPI_RD_FIFO_STATUS_IN(x)            \
                in_dword(HWIO_QSPI_RD_FIFO_STATUS_ADDR(x))
#define HWIO_QSPI_RD_FIFO_STATUS_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_RD_FIFO_STATUS_ADDR(x), m)
#define HWIO_QSPI_RD_FIFO_STATUS_FIFO_EMPTY_BMSK                                                         0x800
#define HWIO_QSPI_RD_FIFO_STATUS_FIFO_EMPTY_SHFT                                                            11
#define HWIO_QSPI_RD_FIFO_STATUS_WR_CNTS_BMSK                                                            0x7f0
#define HWIO_QSPI_RD_FIFO_STATUS_WR_CNTS_SHFT                                                                4
#define HWIO_QSPI_RD_FIFO_STATUS_RDY_64BYTE_BMSK                                                           0x8
#define HWIO_QSPI_RD_FIFO_STATUS_RDY_64BYTE_SHFT                                                             3
#define HWIO_QSPI_RD_FIFO_STATUS_RDY_32BYTE_BMSK                                                           0x4
#define HWIO_QSPI_RD_FIFO_STATUS_RDY_32BYTE_SHFT                                                             2
#define HWIO_QSPI_RD_FIFO_STATUS_RDY_16BYTE_BMSK                                                           0x2
#define HWIO_QSPI_RD_FIFO_STATUS_RDY_16BYTE_SHFT                                                             1
#define HWIO_QSPI_RD_FIFO_STATUS_FIFO_RDY_BMSK                                                             0x1
#define HWIO_QSPI_RD_FIFO_STATUS_FIFO_RDY_SHFT                                                               0

#define HWIO_QSPI_RD_FIFO_RESET_ADDR(x)                                                             ((x) + 0x30)
#define HWIO_QSPI_RD_FIFO_RESET_PHYS(x)                                                             ((x) + 0x30)
#define HWIO_QSPI_RD_FIFO_RESET_OFFS                                                                (0x30)
#define HWIO_QSPI_RD_FIFO_RESET_RMSK                                                                       0x1
#define HWIO_QSPI_RD_FIFO_RESET_OUT(x, v)            \
                out_dword(HWIO_QSPI_RD_FIFO_RESET_ADDR(x),v)
#define HWIO_QSPI_RD_FIFO_RESET_RESET_FIFO_BMSK                                                            0x1
#define HWIO_QSPI_RD_FIFO_RESET_RESET_FIFO_SHFT                                                              0

#define HWIO_QSPI_MASTER_CONFIG_ADDR(x)                                                             ((x) + 0x34)
#define HWIO_QSPI_MASTER_CONFIG_PHYS(x)                                                             ((x) + 0x34)
#define HWIO_QSPI_MASTER_CONFIG_OFFS                                                                (0x34)
#define HWIO_QSPI_MASTER_CONFIG_RMSK                                                                   0x3ffff
#define HWIO_QSPI_MASTER_CONFIG_IN(x)            \
                in_dword(HWIO_QSPI_MASTER_CONFIG_ADDR(x))
#define HWIO_QSPI_MASTER_CONFIG_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_MASTER_CONFIG_ADDR(x), m)
#define HWIO_QSPI_MASTER_CONFIG_OUT(x, v)            \
                out_dword(HWIO_QSPI_MASTER_CONFIG_ADDR(x),v)
#define HWIO_QSPI_MASTER_CONFIG_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_QSPI_MASTER_CONFIG_ADDR(x),m,v,HWIO_QSPI_MASTER_CONFIG_IN(x))
#define HWIO_QSPI_MASTER_CONFIG_DELAY_LINE_EN_BMSK                                                     0x20000
#define HWIO_QSPI_MASTER_CONFIG_DELAY_LINE_EN_SHFT                                                          17
#define HWIO_QSPI_MASTER_CONFIG_DELAY_LINE_BMSK                                                        0x1e000
#define HWIO_QSPI_MASTER_CONFIG_DELAY_LINE_SHFT                                                             13
#define HWIO_QSPI_MASTER_CONFIG_TCPL_BMSK                                                               0x1e00
#define HWIO_QSPI_MASTER_CONFIG_TCPL_SHFT                                                                    9
#define HWIO_QSPI_MASTER_CONFIG_RESP_FIFO_ALMST_FULL_CNT_BMSK                                            0x1f0
#define HWIO_QSPI_MASTER_CONFIG_RESP_FIFO_ALMST_FULL_CNT_SHFT                                                4
#define HWIO_QSPI_MASTER_CONFIG_TCPH_BMSK                                                                  0xf
#define HWIO_QSPI_MASTER_CONFIG_TCPH_SHFT                                                                    0

#define HWIO_QSPI_NEXT_DMA_DESC_ADDR_ADDR(x)                                                        ((x) + 0x40)
#define HWIO_QSPI_NEXT_DMA_DESC_ADDR_PHYS(x)                                                        ((x) + 0x40)
#define HWIO_QSPI_NEXT_DMA_DESC_ADDR_OFFS                                                           (0x40)
#define HWIO_QSPI_NEXT_DMA_DESC_ADDR_RMSK                                                           0xffffffff
#define HWIO_QSPI_NEXT_DMA_DESC_ADDR_IN(x)            \
                in_dword(HWIO_QSPI_NEXT_DMA_DESC_ADDR_ADDR(x))
#define HWIO_QSPI_NEXT_DMA_DESC_ADDR_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_NEXT_DMA_DESC_ADDR_ADDR(x), m)
#define HWIO_QSPI_NEXT_DMA_DESC_ADDR_OUT(x, v)            \
                out_dword(HWIO_QSPI_NEXT_DMA_DESC_ADDR_ADDR(x),v)
#define HWIO_QSPI_NEXT_DMA_DESC_ADDR_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_QSPI_NEXT_DMA_DESC_ADDR_ADDR(x),m,v,HWIO_QSPI_NEXT_DMA_DESC_ADDR_IN(x))
#define HWIO_QSPI_NEXT_DMA_DESC_ADDR_DMA_NEXT_DESCRIPTOR_BMSK                                       0xffffffff
#define HWIO_QSPI_NEXT_DMA_DESC_ADDR_DMA_NEXT_DESCRIPTOR_SHFT                                                0

#define HWIO_QSPI_CURRENT_DMA_DESC_ADDR_ADDR(x)                                                     ((x) + 0x44)
#define HWIO_QSPI_CURRENT_DMA_DESC_ADDR_PHYS(x)                                                     ((x) + 0x44)
#define HWIO_QSPI_CURRENT_DMA_DESC_ADDR_OFFS                                                        (0x44)
#define HWIO_QSPI_CURRENT_DMA_DESC_ADDR_RMSK                                                        0xffffffff
#define HWIO_QSPI_CURRENT_DMA_DESC_ADDR_IN(x)            \
                in_dword(HWIO_QSPI_CURRENT_DMA_DESC_ADDR_ADDR(x))
#define HWIO_QSPI_CURRENT_DMA_DESC_ADDR_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_CURRENT_DMA_DESC_ADDR_ADDR(x), m)
#define HWIO_QSPI_CURRENT_DMA_DESC_ADDR_DMA_CURRENT_DESCRIPTOR_BMSK                                 0xffffffff
#define HWIO_QSPI_CURRENT_DMA_DESC_ADDR_DMA_CURRENT_DESCRIPTOR_SHFT                                          0

#define HWIO_QSPI_CURRENT_MEM_ADDR_ADDR(x)                                                          ((x) + 0x48)
#define HWIO_QSPI_CURRENT_MEM_ADDR_PHYS(x)                                                          ((x) + 0x48)
#define HWIO_QSPI_CURRENT_MEM_ADDR_OFFS                                                             (0x48)
#define HWIO_QSPI_CURRENT_MEM_ADDR_RMSK                                                             0xffffffff
#define HWIO_QSPI_CURRENT_MEM_ADDR_IN(x)            \
                in_dword(HWIO_QSPI_CURRENT_MEM_ADDR_ADDR(x))
#define HWIO_QSPI_CURRENT_MEM_ADDR_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_CURRENT_MEM_ADDR_ADDR(x), m)
#define HWIO_QSPI_CURRENT_MEM_ADDR_DMA_MEM_PTR_BMSK                                                 0xffffffff
#define HWIO_QSPI_CURRENT_MEM_ADDR_DMA_MEM_PTR_SHFT                                                          0

#define HWIO_QSPI_HW_VERSION_ADDR(x)                                                                ((x) + 0x4c)
#define HWIO_QSPI_HW_VERSION_PHYS(x)                                                                ((x) + 0x4c)
#define HWIO_QSPI_HW_VERSION_OFFS                                                                   (0x4c)
#define HWIO_QSPI_HW_VERSION_RMSK                                                                   0xffffffff
#define HWIO_QSPI_HW_VERSION_IN(x)            \
                in_dword(HWIO_QSPI_HW_VERSION_ADDR(x))
#define HWIO_QSPI_HW_VERSION_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_HW_VERSION_ADDR(x), m)
#define HWIO_QSPI_HW_VERSION_HW_VERSION_MAJOR_BMSK                                                  0xf0000000
#define HWIO_QSPI_HW_VERSION_HW_VERSION_MAJOR_SHFT                                                          28
#define HWIO_QSPI_HW_VERSION_HW_VERSION_MINOR_BMSK                                                   0xfff0000
#define HWIO_QSPI_HW_VERSION_HW_VERSION_MINOR_SHFT                                                          16
#define HWIO_QSPI_HW_VERSION_HW_VERSION_STEP_BMSK                                                       0xffff
#define HWIO_QSPI_HW_VERSION_HW_VERSION_STEP_SHFT                                                            0

#define HWIO_QSPI_RD_FIFOn_ADDR(base,n)                                                             ((base) + 0X50 + (0x4*(n)))
#define HWIO_QSPI_RD_FIFOn_PHYS(base,n)                                                             ((base) + 0X50 + (0x4*(n)))
#define HWIO_QSPI_RD_FIFOn_OFFS(n)                                                                  (0X50 + (0x4*(n)))
#define HWIO_QSPI_RD_FIFOn_RMSK                                                                     0xffffffff
#define HWIO_QSPI_RD_FIFOn_MAXn                                                                             15
#define HWIO_QSPI_RD_FIFOn_INI(base,n)                \
                in_dword_masked(HWIO_QSPI_RD_FIFOn_ADDR(base,n), HWIO_QSPI_RD_FIFOn_RMSK)
#define HWIO_QSPI_RD_FIFOn_INMI(base,n,mask)        \
                in_dword_masked(HWIO_QSPI_RD_FIFOn_ADDR(base,n), mask)
#define HWIO_QSPI_RD_FIFOn_QSPI_RD_FIFO_DATA_BMSK                                                   0xffffffff
#define HWIO_QSPI_RD_FIFOn_QSPI_RD_FIFO_DATA_SHFT                                                            0

#define HWIO_QSPI_SAMPLING_CLK_CONFIG_ADDR(x)                                                       ((x) + 0x90)
#define HWIO_QSPI_SAMPLING_CLK_CONFIG_PHYS(x)                                                       ((x) + 0x90)
#define HWIO_QSPI_SAMPLING_CLK_CONFIG_OFFS                                                          (0x90)
#define HWIO_QSPI_SAMPLING_CLK_CONFIG_RMSK                                                           0x1ffffff
#define HWIO_QSPI_SAMPLING_CLK_CONFIG_IN(x)            \
                in_dword(HWIO_QSPI_SAMPLING_CLK_CONFIG_ADDR(x))
#define HWIO_QSPI_SAMPLING_CLK_CONFIG_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_SAMPLING_CLK_CONFIG_ADDR(x), m)
#define HWIO_QSPI_SAMPLING_CLK_CONFIG_OUT(x, v)            \
                out_dword(HWIO_QSPI_SAMPLING_CLK_CONFIG_ADDR(x),v)
#define HWIO_QSPI_SAMPLING_CLK_CONFIG_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_QSPI_SAMPLING_CLK_CONFIG_ADDR(x),m,v,HWIO_QSPI_SAMPLING_CLK_CONFIG_IN(x))
#define HWIO_QSPI_SAMPLING_CLK_CONFIG_LANE7_CLK_CNTR_INIT_VAL_BMSK                                   0x1c00000
#define HWIO_QSPI_SAMPLING_CLK_CONFIG_LANE7_CLK_CNTR_INIT_VAL_SHFT                                          22
#define HWIO_QSPI_SAMPLING_CLK_CONFIG_LANE6_CLK_CNTR_INIT_VAL_BMSK                                    0x380000
#define HWIO_QSPI_SAMPLING_CLK_CONFIG_LANE6_CLK_CNTR_INIT_VAL_SHFT                                          19
#define HWIO_QSPI_SAMPLING_CLK_CONFIG_LANE5_CLK_CNTR_INIT_VAL_BMSK                                     0x70000
#define HWIO_QSPI_SAMPLING_CLK_CONFIG_LANE5_CLK_CNTR_INIT_VAL_SHFT                                          16
#define HWIO_QSPI_SAMPLING_CLK_CONFIG_LANE4_CLK_CNTR_INIT_VAL_BMSK                                      0xe000
#define HWIO_QSPI_SAMPLING_CLK_CONFIG_LANE4_CLK_CNTR_INIT_VAL_SHFT                                          13
#define HWIO_QSPI_SAMPLING_CLK_CONFIG_EN_LOAD_CLK_CNTR_BMSK                                             0x1000
#define HWIO_QSPI_SAMPLING_CLK_CONFIG_EN_LOAD_CLK_CNTR_SHFT                                                 12
#define HWIO_QSPI_SAMPLING_CLK_CONFIG_LANE3_CLK_CNTR_INIT_VAL_BMSK                                       0xe00
#define HWIO_QSPI_SAMPLING_CLK_CONFIG_LANE3_CLK_CNTR_INIT_VAL_SHFT                                           9
#define HWIO_QSPI_SAMPLING_CLK_CONFIG_LANE2_CLK_CNTR_INIT_VAL_BMSK                                       0x1c0
#define HWIO_QSPI_SAMPLING_CLK_CONFIG_LANE2_CLK_CNTR_INIT_VAL_SHFT                                           6
#define HWIO_QSPI_SAMPLING_CLK_CONFIG_LANE1_CLK_CNTR_INIT_VAL_BMSK                                        0x38
#define HWIO_QSPI_SAMPLING_CLK_CONFIG_LANE1_CLK_CNTR_INIT_VAL_SHFT                                           3
#define HWIO_QSPI_SAMPLING_CLK_CONFIG_LANE0_CLK_CNTR_INIT_VAL_BMSK                                         0x7
#define HWIO_QSPI_SAMPLING_CLK_CONFIG_LANE0_CLK_CNTR_INIT_VAL_SHFT                                           0

#define HWIO_QSPI_SAMPLING_CLK_STATUS_ADDR(x)                                                       ((x) + 0x94)
#define HWIO_QSPI_SAMPLING_CLK_STATUS_PHYS(x)                                                       ((x) + 0x94)
#define HWIO_QSPI_SAMPLING_CLK_STATUS_OFFS                                                          (0x94)
#define HWIO_QSPI_SAMPLING_CLK_STATUS_RMSK                                                                 0x1
#define HWIO_QSPI_SAMPLING_CLK_STATUS_IN(x)            \
                in_dword(HWIO_QSPI_SAMPLING_CLK_STATUS_ADDR(x))
#define HWIO_QSPI_SAMPLING_CLK_STATUS_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_SAMPLING_CLK_STATUS_ADDR(x), m)
#define HWIO_QSPI_SAMPLING_CLK_STATUS_LOAD_CLK_CNTR_ACK_BMSK                                               0x1
#define HWIO_QSPI_SAMPLING_CLK_STATUS_LOAD_CLK_CNTR_ACK_SHFT                                                 0

#define HWIO_QSPI_TEST_BUS_SEL_ADDR(x)                                                              ((x) + 0xc4)
#define HWIO_QSPI_TEST_BUS_SEL_PHYS(x)                                                              ((x) + 0xc4)
#define HWIO_QSPI_TEST_BUS_SEL_OFFS                                                                 (0xc4)
#define HWIO_QSPI_TEST_BUS_SEL_RMSK                                                                       0x1f
#define HWIO_QSPI_TEST_BUS_SEL_IN(x)            \
                in_dword(HWIO_QSPI_TEST_BUS_SEL_ADDR(x))
#define HWIO_QSPI_TEST_BUS_SEL_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_TEST_BUS_SEL_ADDR(x), m)
#define HWIO_QSPI_TEST_BUS_SEL_OUT(x, v)            \
                out_dword(HWIO_QSPI_TEST_BUS_SEL_ADDR(x),v)
#define HWIO_QSPI_TEST_BUS_SEL_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_QSPI_TEST_BUS_SEL_ADDR(x),m,v,HWIO_QSPI_TEST_BUS_SEL_IN(x))
#define HWIO_QSPI_TEST_BUS_SEL_TEST_BUS_SEL_BMSK                                                          0x1f
#define HWIO_QSPI_TEST_BUS_SEL_TEST_BUS_SEL_SHFT                                                             0

#define HWIO_QSPI_TEST_BUS_REG_ADDR(x)                                                              ((x) + 0xc8)
#define HWIO_QSPI_TEST_BUS_REG_PHYS(x)                                                              ((x) + 0xc8)
#define HWIO_QSPI_TEST_BUS_REG_OFFS                                                                 (0xc8)
#define HWIO_QSPI_TEST_BUS_REG_RMSK                                                                 0xffffffff
#define HWIO_QSPI_TEST_BUS_REG_IN(x)            \
                in_dword(HWIO_QSPI_TEST_BUS_REG_ADDR(x))
#define HWIO_QSPI_TEST_BUS_REG_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_TEST_BUS_REG_ADDR(x), m)
#define HWIO_QSPI_TEST_BUS_REG_TEST_BUS_BMSK                                                        0xffffffff
#define HWIO_QSPI_TEST_BUS_REG_TEST_BUS_SHFT                                                                 0

#define HWIO_QSPI_MSTR_INT1_ENABLE_ADDR(x)                                                          ((x) + 0xd0)
#define HWIO_QSPI_MSTR_INT1_ENABLE_PHYS(x)                                                          ((x) + 0xd0)
#define HWIO_QSPI_MSTR_INT1_ENABLE_OFFS                                                             (0xd0)
#define HWIO_QSPI_MSTR_INT1_ENABLE_RMSK                                                             0xf0030e0f
#define HWIO_QSPI_MSTR_INT1_ENABLE_IN(x)            \
                in_dword(HWIO_QSPI_MSTR_INT1_ENABLE_ADDR(x))
#define HWIO_QSPI_MSTR_INT1_ENABLE_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_MSTR_INT1_ENABLE_ADDR(x), m)
#define HWIO_QSPI_MSTR_INT1_ENABLE_OUT(x, v)            \
                out_dword(HWIO_QSPI_MSTR_INT1_ENABLE_ADDR(x),v)
#define HWIO_QSPI_MSTR_INT1_ENABLE_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_QSPI_MSTR_INT1_ENABLE_ADDR(x),m,v,HWIO_QSPI_MSTR_INT1_ENABLE_IN(x))
#define HWIO_QSPI_MSTR_INT1_ENABLE_EN_DMA_CHAIN_DONE_BMSK                                           0x80000000
#define HWIO_QSPI_MSTR_INT1_ENABLE_EN_DMA_CHAIN_DONE_SHFT                                                   31
#define HWIO_QSPI_MSTR_INT1_ENABLE_EN_XIP_ACCESS_DURING_DMA_BMSK                                    0x40000000
#define HWIO_QSPI_MSTR_INT1_ENABLE_EN_XIP_ACCESS_DURING_DMA_SHFT                                            30
#define HWIO_QSPI_MSTR_INT1_ENABLE_EN_XIP_ACCESS_UNMAPPED_SEGMENT_BMSK                              0x20000000
#define HWIO_QSPI_MSTR_INT1_ENABLE_EN_XIP_ACCESS_UNMAPPED_SEGMENT_SHFT                                      29
#define HWIO_QSPI_MSTR_INT1_ENABLE_EN_XIP_ACCESS_NOT_ENABLE_BMSK                                    0x10000000
#define HWIO_QSPI_MSTR_INT1_ENABLE_EN_XIP_ACCESS_NOT_ENABLE_SHFT                                            28
#define HWIO_QSPI_MSTR_INT1_ENABLE_EN_DMA_ACCESS_DURING_XIP_BMSK                                       0x20000
#define HWIO_QSPI_MSTR_INT1_ENABLE_EN_DMA_ACCESS_DURING_XIP_SHFT                                            17
#define HWIO_QSPI_MSTR_INT1_ENABLE_EN_TRANSACTION_DONE_BMSK                                            0x10000
#define HWIO_QSPI_MSTR_INT1_ENABLE_EN_TRANSACTION_DONE_SHFT                                                 16
#define HWIO_QSPI_MSTR_INT1_ENABLE_EN_WRITE_FIFO_OVERRUN_BMSK                                            0x800
#define HWIO_QSPI_MSTR_INT1_ENABLE_EN_WRITE_FIFO_OVERRUN_SHFT                                               11
#define HWIO_QSPI_MSTR_INT1_ENABLE_EN_WRITE_FIFO_FULL_BMSK                                               0x400
#define HWIO_QSPI_MSTR_INT1_ENABLE_EN_WRITE_FIFO_FULL_SHFT                                                  10
#define HWIO_QSPI_MSTR_INT1_ENABLE_EN_WRITE_FIFO_EMPTY_BMSK                                              0x200
#define HWIO_QSPI_MSTR_INT1_ENABLE_EN_WRITE_FIFO_EMPTY_SHFT                                                  9
#define HWIO_QSPI_MSTR_INT1_ENABLE_EN_HRESP_FROM_NOC_ERR_BMSK                                              0x8
#define HWIO_QSPI_MSTR_INT1_ENABLE_EN_HRESP_FROM_NOC_ERR_SHFT                                                3
#define HWIO_QSPI_MSTR_INT1_ENABLE_EN_RESP_FIFO_RDY_BMSK                                                   0x4
#define HWIO_QSPI_MSTR_INT1_ENABLE_EN_RESP_FIFO_RDY_SHFT                                                     2
#define HWIO_QSPI_MSTR_INT1_ENABLE_EN_RESP_FIFO_NOT_EMPTY_BMSK                                             0x2
#define HWIO_QSPI_MSTR_INT1_ENABLE_EN_RESP_FIFO_NOT_EMPTY_SHFT                                               1
#define HWIO_QSPI_MSTR_INT1_ENABLE_EN_RESP_FIFO_UNDERRUN_BMSK                                              0x1
#define HWIO_QSPI_MSTR_INT1_ENABLE_EN_RESP_FIFO_UNDERRUN_SHFT                                                0

#define HWIO_QSPI_MSTR_INT1_STATUS_ADDR(x)                                                          ((x) + 0xd4)
#define HWIO_QSPI_MSTR_INT1_STATUS_PHYS(x)                                                          ((x) + 0xd4)
#define HWIO_QSPI_MSTR_INT1_STATUS_OFFS                                                             (0xd4)
#define HWIO_QSPI_MSTR_INT1_STATUS_RMSK                                                             0xf0030e0f
#define HWIO_QSPI_MSTR_INT1_STATUS_IN(x)            \
                in_dword(HWIO_QSPI_MSTR_INT1_STATUS_ADDR(x))
#define HWIO_QSPI_MSTR_INT1_STATUS_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_MSTR_INT1_STATUS_ADDR(x), m)
#define HWIO_QSPI_MSTR_INT1_STATUS_OUT(x, v)            \
                out_dword(HWIO_QSPI_MSTR_INT1_STATUS_ADDR(x),v)
#define HWIO_QSPI_MSTR_INT1_STATUS_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_QSPI_MSTR_INT1_STATUS_ADDR(x),m,v,HWIO_QSPI_MSTR_INT1_STATUS_IN(x))
#define HWIO_QSPI_MSTR_INT1_STATUS_DMA_CHAIN_DONE_BMSK                                              0x80000000
#define HWIO_QSPI_MSTR_INT1_STATUS_DMA_CHAIN_DONE_SHFT                                                      31
#define HWIO_QSPI_MSTR_INT1_STATUS_XIP_ACCESS_DURING_DMA_BMSK                                       0x40000000
#define HWIO_QSPI_MSTR_INT1_STATUS_XIP_ACCESS_DURING_DMA_SHFT                                               30
#define HWIO_QSPI_MSTR_INT1_STATUS_XIP_ACCESS_UNMAPPED_SEGMENT_BMSK                                 0x20000000
#define HWIO_QSPI_MSTR_INT1_STATUS_XIP_ACCESS_UNMAPPED_SEGMENT_SHFT                                         29
#define HWIO_QSPI_MSTR_INT1_STATUS_XIP_ACCESS_NOT_ENABLE_BMSK                                       0x10000000
#define HWIO_QSPI_MSTR_INT1_STATUS_XIP_ACCESS_NOT_ENABLE_SHFT                                               28
#define HWIO_QSPI_MSTR_INT1_STATUS_DMA_ACCESS_DURING_XIP_BMSK                                          0x20000
#define HWIO_QSPI_MSTR_INT1_STATUS_DMA_ACCESS_DURING_XIP_SHFT                                               17
#define HWIO_QSPI_MSTR_INT1_STATUS_TRANSACTION_DONE_BMSK                                               0x10000
#define HWIO_QSPI_MSTR_INT1_STATUS_TRANSACTION_DONE_SHFT                                                    16
#define HWIO_QSPI_MSTR_INT1_STATUS_WRITE_FIFO_OVERRUN_BMSK                                               0x800
#define HWIO_QSPI_MSTR_INT1_STATUS_WRITE_FIFO_OVERRUN_SHFT                                                  11
#define HWIO_QSPI_MSTR_INT1_STATUS_WRITE_FIFO_FULL_BMSK                                                  0x400
#define HWIO_QSPI_MSTR_INT1_STATUS_WRITE_FIFO_FULL_SHFT                                                     10
#define HWIO_QSPI_MSTR_INT1_STATUS_WRITE_FIFO_EMPTY_BMSK                                                 0x200
#define HWIO_QSPI_MSTR_INT1_STATUS_WRITE_FIFO_EMPTY_SHFT                                                     9
#define HWIO_QSPI_MSTR_INT1_STATUS_HRESP_FROM_NOC_ERR_BMSK                                                 0x8
#define HWIO_QSPI_MSTR_INT1_STATUS_HRESP_FROM_NOC_ERR_SHFT                                                   3
#define HWIO_QSPI_MSTR_INT1_STATUS_RESP_FIFO_RDY_BMSK                                                      0x4
#define HWIO_QSPI_MSTR_INT1_STATUS_RESP_FIFO_RDY_SHFT                                                        2
#define HWIO_QSPI_MSTR_INT1_STATUS_RESP_FIFO_NOT_EMPTY_BMSK                                                0x2
#define HWIO_QSPI_MSTR_INT1_STATUS_RESP_FIFO_NOT_EMPTY_SHFT                                                  1
#define HWIO_QSPI_MSTR_INT1_STATUS_RESP_FIFO_UNDERRUN_BMSK                                                 0x1
#define HWIO_QSPI_MSTR_INT1_STATUS_RESP_FIFO_UNDERRUN_SHFT                                                   0

#define HWIO_QSPI_CHAR_CFG_ADDR(x)                                                                  ((x) + 0x100)
#define HWIO_QSPI_CHAR_CFG_PHYS(x)                                                                  ((x) + 0x100)
#define HWIO_QSPI_CHAR_CFG_OFFS                                                                     (0x100)
#define HWIO_QSPI_CHAR_CFG_RMSK                                                                          0x1f1
#define HWIO_QSPI_CHAR_CFG_IN(x)            \
                in_dword(HWIO_QSPI_CHAR_CFG_ADDR(x))
#define HWIO_QSPI_CHAR_CFG_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_CHAR_CFG_ADDR(x), m)
#define HWIO_QSPI_CHAR_CFG_OUT(x, v)            \
                out_dword(HWIO_QSPI_CHAR_CFG_ADDR(x),v)
#define HWIO_QSPI_CHAR_CFG_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_QSPI_CHAR_CFG_ADDR(x),m,v,HWIO_QSPI_CHAR_CFG_IN(x))
#define HWIO_QSPI_CHAR_CFG_CHAR_STATUS_BMSK                                                              0x1e0
#define HWIO_QSPI_CHAR_CFG_CHAR_STATUS_SHFT                                                                  5
#define HWIO_QSPI_CHAR_CFG_DIRECTION_BMSK                                                                 0x10
#define HWIO_QSPI_CHAR_CFG_DIRECTION_SHFT                                                                    4
#define HWIO_QSPI_CHAR_CFG_ENABLE_BMSK                                                                     0x1
#define HWIO_QSPI_CHAR_CFG_ENABLE_SHFT                                                                       0

#define HWIO_QSPI_CHAR_DATA_MISOn_ADDR(base,n)                                                      ((base) + 0X104 + (0x4*(n)))
#define HWIO_QSPI_CHAR_DATA_MISOn_PHYS(base,n)                                                      ((base) + 0X104 + (0x4*(n)))
#define HWIO_QSPI_CHAR_DATA_MISOn_OFFS(n)                                                           (0X104 + (0x4*(n)))
#define HWIO_QSPI_CHAR_DATA_MISOn_RMSK                                                                  0xffff
#define HWIO_QSPI_CHAR_DATA_MISOn_MAXn                                                                       7
#define HWIO_QSPI_CHAR_DATA_MISOn_INI(base,n)                \
                in_dword_masked(HWIO_QSPI_CHAR_DATA_MISOn_ADDR(base,n), HWIO_QSPI_CHAR_DATA_MISOn_RMSK)
#define HWIO_QSPI_CHAR_DATA_MISOn_INMI(base,n,mask)        \
                in_dword_masked(HWIO_QSPI_CHAR_DATA_MISOn_ADDR(base,n), mask)
#define HWIO_QSPI_CHAR_DATA_MISOn_OUTI(base,n,val)        \
                out_dword(HWIO_QSPI_CHAR_DATA_MISOn_ADDR(base,n),val)
#define HWIO_QSPI_CHAR_DATA_MISOn_OUTMI(base,n,mask,val) \
                out_dword_masked_ns(HWIO_QSPI_CHAR_DATA_MISOn_ADDR(base,n),mask,val,HWIO_QSPI_CHAR_DATA_MISOn_INI(base,n))
#define HWIO_QSPI_CHAR_DATA_MISOn_DIN_ACTUAL_BMSK                                                       0xff00
#define HWIO_QSPI_CHAR_DATA_MISOn_DIN_ACTUAL_SHFT                                                            8
#define HWIO_QSPI_CHAR_DATA_MISOn_DOUT_DATA_DIN_EXP_BMSK                                                  0xff
#define HWIO_QSPI_CHAR_DATA_MISOn_DOUT_DATA_DIN_EXP_SHFT                                                     0

#define HWIO_QSPI_CHAR_DATA_MOSIn_ADDR(base,n)                                                      ((base) + 0X124 + (0x4*(n)))
#define HWIO_QSPI_CHAR_DATA_MOSIn_PHYS(base,n)                                                      ((base) + 0X124 + (0x4*(n)))
#define HWIO_QSPI_CHAR_DATA_MOSIn_OFFS(n)                                                           (0X124 + (0x4*(n)))
#define HWIO_QSPI_CHAR_DATA_MOSIn_RMSK                                                                 0xfffff
#define HWIO_QSPI_CHAR_DATA_MOSIn_MAXn                                                                       7
#define HWIO_QSPI_CHAR_DATA_MOSIn_INI(base,n)                \
                in_dword_masked(HWIO_QSPI_CHAR_DATA_MOSIn_ADDR(base,n), HWIO_QSPI_CHAR_DATA_MOSIn_RMSK)
#define HWIO_QSPI_CHAR_DATA_MOSIn_INMI(base,n,mask)        \
                in_dword_masked(HWIO_QSPI_CHAR_DATA_MOSIn_ADDR(base,n), mask)
#define HWIO_QSPI_CHAR_DATA_MOSIn_OUTI(base,n,val)        \
                out_dword(HWIO_QSPI_CHAR_DATA_MOSIn_ADDR(base,n),val)
#define HWIO_QSPI_CHAR_DATA_MOSIn_OUTMI(base,n,mask,val) \
                out_dword_masked_ns(HWIO_QSPI_CHAR_DATA_MOSIn_ADDR(base,n),mask,val,HWIO_QSPI_CHAR_DATA_MOSIn_INI(base,n))
#define HWIO_QSPI_CHAR_DATA_MOSIn_DATA_OE_BMSK                                                         0xff000
#define HWIO_QSPI_CHAR_DATA_MOSIn_DATA_OE_SHFT                                                              12
#define HWIO_QSPI_CHAR_DATA_MOSIn_CHAR_MODE_BMSK                                                         0xf00
#define HWIO_QSPI_CHAR_DATA_MOSIn_CHAR_MODE_SHFT                                                             8
#define HWIO_QSPI_CHAR_DATA_MOSIn_DOUT_DATA_DIN_EXP_BMSK                                                  0xff
#define HWIO_QSPI_CHAR_DATA_MOSIn_DOUT_DATA_DIN_EXP_SHFT                                                     0

#define HWIO_QSPI_CHAR_CS_Nn_ADDR(base,n)                                                           ((base) + 0X144 + (0x4*(n)))
#define HWIO_QSPI_CHAR_CS_Nn_PHYS(base,n)                                                           ((base) + 0X144 + (0x4*(n)))
#define HWIO_QSPI_CHAR_CS_Nn_OFFS(n)                                                                (0X144 + (0x4*(n)))
#define HWIO_QSPI_CHAR_CS_Nn_RMSK                                                                      0xfffff
#define HWIO_QSPI_CHAR_CS_Nn_MAXn                                                                            1
#define HWIO_QSPI_CHAR_CS_Nn_INI(base,n)                \
                in_dword_masked(HWIO_QSPI_CHAR_CS_Nn_ADDR(base,n), HWIO_QSPI_CHAR_CS_Nn_RMSK)
#define HWIO_QSPI_CHAR_CS_Nn_INMI(base,n,mask)        \
                in_dword_masked(HWIO_QSPI_CHAR_CS_Nn_ADDR(base,n), mask)
#define HWIO_QSPI_CHAR_CS_Nn_OUTI(base,n,val)        \
                out_dword(HWIO_QSPI_CHAR_CS_Nn_ADDR(base,n),val)
#define HWIO_QSPI_CHAR_CS_Nn_OUTMI(base,n,mask,val) \
                out_dword_masked_ns(HWIO_QSPI_CHAR_CS_Nn_ADDR(base,n),mask,val,HWIO_QSPI_CHAR_CS_Nn_INI(base,n))
#define HWIO_QSPI_CHAR_CS_Nn_DATA_OE_BMSK                                                              0xff000
#define HWIO_QSPI_CHAR_CS_Nn_DATA_OE_SHFT                                                                   12
#define HWIO_QSPI_CHAR_CS_Nn_CHAR_MODE_BMSK                                                              0xf00
#define HWIO_QSPI_CHAR_CS_Nn_CHAR_MODE_SHFT                                                                  8
#define HWIO_QSPI_CHAR_CS_Nn_DOUT_DATA_DIN_EXP_BMSK                                                       0xff
#define HWIO_QSPI_CHAR_CS_Nn_DOUT_DATA_DIN_EXP_SHFT                                                          0

#define HWIO_QSPI_XIP_MASTER_CFG_ADDR(x)                                                            ((x) + 0x200)
#define HWIO_QSPI_XIP_MASTER_CFG_PHYS(x)                                                            ((x) + 0x200)
#define HWIO_QSPI_XIP_MASTER_CFG_OFFS                                                               (0x200)
#define HWIO_QSPI_XIP_MASTER_CFG_RMSK                                                                 0x1eff19
#define HWIO_QSPI_XIP_MASTER_CFG_IN(x)            \
                in_dword(HWIO_QSPI_XIP_MASTER_CFG_ADDR(x))
#define HWIO_QSPI_XIP_MASTER_CFG_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_XIP_MASTER_CFG_ADDR(x), m)
#define HWIO_QSPI_XIP_MASTER_CFG_OUT(x, v)            \
                out_dword(HWIO_QSPI_XIP_MASTER_CFG_ADDR(x),v)
#define HWIO_QSPI_XIP_MASTER_CFG_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_QSPI_XIP_MASTER_CFG_ADDR(x),m,v,HWIO_QSPI_XIP_MASTER_CFG_IN(x))
#define HWIO_QSPI_XIP_MASTER_CFG_ADDRESS_TRANSLATION_EN_REGION_4_BMSK                                 0x100000
#define HWIO_QSPI_XIP_MASTER_CFG_ADDRESS_TRANSLATION_EN_REGION_4_SHFT                                       20
#define HWIO_QSPI_XIP_MASTER_CFG_ADDRESS_TRANSLATION_EN_REGION_3_BMSK                                  0x80000
#define HWIO_QSPI_XIP_MASTER_CFG_ADDRESS_TRANSLATION_EN_REGION_3_SHFT                                       19
#define HWIO_QSPI_XIP_MASTER_CFG_ADDRESS_TRANSLATION_EN_REGION_2_BMSK                                  0x40000
#define HWIO_QSPI_XIP_MASTER_CFG_ADDRESS_TRANSLATION_EN_REGION_2_SHFT                                       18
#define HWIO_QSPI_XIP_MASTER_CFG_ADDRESS_TRANSLATION_EN_REGION_1_BMSK                                  0x20000
#define HWIO_QSPI_XIP_MASTER_CFG_ADDRESS_TRANSLATION_EN_REGION_1_SHFT                                       17
#define HWIO_QSPI_XIP_MASTER_CFG_AHBCLK_FREQ_BMSK                                                       0xff00
#define HWIO_QSPI_XIP_MASTER_CFG_AHBCLK_FREQ_SHFT                                                            8
#define HWIO_QSPI_XIP_MASTER_CFG_DMA_TRANS_BOUNDARY_BMSK                                                  0x10
#define HWIO_QSPI_XIP_MASTER_CFG_DMA_TRANS_BOUNDARY_SHFT                                                     4
#define HWIO_QSPI_XIP_MASTER_CFG_PROGRAM_ERASE_ONGOING_BMSK                                                0x8
#define HWIO_QSPI_XIP_MASTER_CFG_PROGRAM_ERASE_ONGOING_SHFT                                                  3
#define HWIO_QSPI_XIP_MASTER_CFG_XIP_ENABLE_BMSK                                                           0x1
#define HWIO_QSPI_XIP_MASTER_CFG_XIP_ENABLE_SHFT                                                             0

#define HWIO_QSPI_XIP_MASTER_STATUS_ADDR(x)                                                         ((x) + 0x204)
#define HWIO_QSPI_XIP_MASTER_STATUS_PHYS(x)                                                         ((x) + 0x204)
#define HWIO_QSPI_XIP_MASTER_STATUS_OFFS                                                            (0x204)
#define HWIO_QSPI_XIP_MASTER_STATUS_RMSK                                                                   0x3
#define HWIO_QSPI_XIP_MASTER_STATUS_IN(x)            \
                in_dword(HWIO_QSPI_XIP_MASTER_STATUS_ADDR(x))
#define HWIO_QSPI_XIP_MASTER_STATUS_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_XIP_MASTER_STATUS_ADDR(x), m)
#define HWIO_QSPI_XIP_MASTER_STATUS_XIP_AWAITING_ARBITRATION_BMSK                                          0x2
#define HWIO_QSPI_XIP_MASTER_STATUS_XIP_AWAITING_ARBITRATION_SHFT                                            1
#define HWIO_QSPI_XIP_MASTER_STATUS_XIP_ACTIVE_BMSK                                                        0x1
#define HWIO_QSPI_XIP_MASTER_STATUS_XIP_ACTIVE_SHFT                                                          0

#define HWIO_QSPI_XIP_GENERAL_CFG_ADDR(x)                                                           ((x) + 0x208)
#define HWIO_QSPI_XIP_GENERAL_CFG_PHYS(x)                                                           ((x) + 0x208)
#define HWIO_QSPI_XIP_GENERAL_CFG_OFFS                                                              (0x208)
#define HWIO_QSPI_XIP_GENERAL_CFG_RMSK                                                                  0xffff
#define HWIO_QSPI_XIP_GENERAL_CFG_IN(x)            \
                in_dword(HWIO_QSPI_XIP_GENERAL_CFG_ADDR(x))
#define HWIO_QSPI_XIP_GENERAL_CFG_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_XIP_GENERAL_CFG_ADDR(x), m)
#define HWIO_QSPI_XIP_GENERAL_CFG_OUT(x, v)            \
                out_dword(HWIO_QSPI_XIP_GENERAL_CFG_ADDR(x),v)
#define HWIO_QSPI_XIP_GENERAL_CFG_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_QSPI_XIP_GENERAL_CFG_ADDR(x),m,v,HWIO_QSPI_XIP_GENERAL_CFG_IN(x))
#define HWIO_QSPI_XIP_GENERAL_CFG_XIP_FLUSH_OPT_EN_BMSK                                                 0x8000
#define HWIO_QSPI_XIP_GENERAL_CFG_XIP_FLUSH_OPT_EN_SHFT                                                     15
#define HWIO_QSPI_XIP_GENERAL_CFG_XIP_INCR_RD_PERF_BOOST_BMSK                                           0x4000
#define HWIO_QSPI_XIP_GENERAL_CFG_XIP_INCR_RD_PERF_BOOST_SHFT                                               14
#define HWIO_QSPI_XIP_GENERAL_CFG_XIP_SWAP_WR_BYTES_BMSK                                                0x2000
#define HWIO_QSPI_XIP_GENERAL_CFG_XIP_SWAP_WR_BYTES_SHFT                                                    13
#define HWIO_QSPI_XIP_GENERAL_CFG_XIP_AHB_BURST_EN_BMSK                                                 0x1000
#define HWIO_QSPI_XIP_GENERAL_CFG_XIP_AHB_BURST_EN_SHFT                                                     12
#define HWIO_QSPI_XIP_GENERAL_CFG_XIP_AHB_WR_EN_BMSK                                                     0x800
#define HWIO_QSPI_XIP_GENERAL_CFG_XIP_AHB_WR_EN_SHFT                                                        11
#define HWIO_QSPI_XIP_GENERAL_CFG_XIP_PIO_DISABLE_BMSK                                                   0x400
#define HWIO_QSPI_XIP_GENERAL_CFG_XIP_PIO_DISABLE_SHFT                                                      10
#define HWIO_QSPI_XIP_GENERAL_CFG_XIP_CLEAR_ERR_UPON_IDLE_BMSK                                           0x200
#define HWIO_QSPI_XIP_GENERAL_CFG_XIP_CLEAR_ERR_UPON_IDLE_SHFT                                               9
#define HWIO_QSPI_XIP_GENERAL_CFG_MOSI_OE_DELAY_FIX_DIS_BMSK                                             0x100
#define HWIO_QSPI_XIP_GENERAL_CFG_MOSI_OE_DELAY_FIX_DIS_SHFT                                                 8
#define HWIO_QSPI_XIP_GENERAL_CFG_XIP_DMA_ARB_PRIORITY_BMSK                                               0x80
#define HWIO_QSPI_XIP_GENERAL_CFG_XIP_DMA_ARB_PRIORITY_SHFT                                                  7
#define HWIO_QSPI_XIP_GENERAL_CFG_XIP_ACCESS_UNMAPPED_SEGMENT_REGION_MASK_BMSK                            0x40
#define HWIO_QSPI_XIP_GENERAL_CFG_XIP_ACCESS_UNMAPPED_SEGMENT_REGION_MASK_SHFT                               6
#define HWIO_QSPI_XIP_GENERAL_CFG_XIP_ACCESS_UNMAPPED_SEGMENT_OFFSET_MASK_BMSK                            0x20
#define HWIO_QSPI_XIP_GENERAL_CFG_XIP_ACCESS_UNMAPPED_SEGMENT_OFFSET_MASK_SHFT                               5
#define HWIO_QSPI_XIP_GENERAL_CFG_XIP_ACCESS_NOT_ENABLE_MASK_BMSK                                         0x10
#define HWIO_QSPI_XIP_GENERAL_CFG_XIP_ACCESS_NOT_ENABLE_MASK_SHFT                                            4
#define HWIO_QSPI_XIP_GENERAL_CFG_XIP_CGC_EN_BMSK                                                          0x8
#define HWIO_QSPI_XIP_GENERAL_CFG_XIP_CGC_EN_SHFT                                                            3
#define HWIO_QSPI_XIP_GENERAL_CFG_XIP_SWAP_RD_BYTES_BMSK                                                   0x4
#define HWIO_QSPI_XIP_GENERAL_CFG_XIP_SWAP_RD_BYTES_SHFT                                                     2
#define HWIO_QSPI_XIP_GENERAL_CFG_GENERATE_PATTERN_UPON_ACCESS_ERR_BMSK                                    0x2
#define HWIO_QSPI_XIP_GENERAL_CFG_GENERATE_PATTERN_UPON_ACCESS_ERR_SHFT                                      1
#define HWIO_QSPI_XIP_GENERAL_CFG_BYPASS_DISABLE_BMSK                                                      0x1
#define HWIO_QSPI_XIP_GENERAL_CFG_BYPASS_DISABLE_SHFT                                                        0

#define HWIO_QSPI_XIP_INST_PH_CONFIG_ADDR(x)                                                        ((x) + 0x210)
#define HWIO_QSPI_XIP_INST_PH_CONFIG_PHYS(x)                                                        ((x) + 0x210)
#define HWIO_QSPI_XIP_INST_PH_CONFIG_OFFS                                                           (0x210)
#define HWIO_QSPI_XIP_INST_PH_CONFIG_RMSK                                                           0xffffff07
#define HWIO_QSPI_XIP_INST_PH_CONFIG_IN(x)            \
                in_dword(HWIO_QSPI_XIP_INST_PH_CONFIG_ADDR(x))
#define HWIO_QSPI_XIP_INST_PH_CONFIG_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_XIP_INST_PH_CONFIG_ADDR(x), m)
#define HWIO_QSPI_XIP_INST_PH_CONFIG_OUT(x, v)            \
                out_dword(HWIO_QSPI_XIP_INST_PH_CONFIG_ADDR(x),v)
#define HWIO_QSPI_XIP_INST_PH_CONFIG_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_QSPI_XIP_INST_PH_CONFIG_ADDR(x),m,v,HWIO_QSPI_XIP_INST_PH_CONFIG_IN(x))
#define HWIO_QSPI_XIP_INST_PH_CONFIG_LINEAR_BURST_INST_OPCODE_BMSK                                  0xff000000
#define HWIO_QSPI_XIP_INST_PH_CONFIG_LINEAR_BURST_INST_OPCODE_SHFT                                          24
#define HWIO_QSPI_XIP_INST_PH_CONFIG_WRAP_BURST_INST_OPCODE_BMSK                                      0xff0000
#define HWIO_QSPI_XIP_INST_PH_CONFIG_WRAP_BURST_INST_OPCODE_SHFT                                            16
#define HWIO_QSPI_XIP_INST_PH_CONFIG_WRITE_INST_OPCODE_BMSK                                             0xff00
#define HWIO_QSPI_XIP_INST_PH_CONFIG_WRITE_INST_OPCODE_SHFT                                                  8
#define HWIO_QSPI_XIP_INST_PH_CONFIG_DDR_SDR_SELECTOR_BMSK                                                 0x4
#define HWIO_QSPI_XIP_INST_PH_CONFIG_DDR_SDR_SELECTOR_SHFT                                                   2
#define HWIO_QSPI_XIP_INST_PH_CONFIG_BUS_WIDTH_SELECTOR_BMSK                                               0x3
#define HWIO_QSPI_XIP_INST_PH_CONFIG_BUS_WIDTH_SELECTOR_SHFT                                                 0

#define HWIO_QSPI_XIP_ADDR_PH_CONFIG_ADDR(x)                                                        ((x) + 0x214)
#define HWIO_QSPI_XIP_ADDR_PH_CONFIG_PHYS(x)                                                        ((x) + 0x214)
#define HWIO_QSPI_XIP_ADDR_PH_CONFIG_OFFS                                                           (0x214)
#define HWIO_QSPI_XIP_ADDR_PH_CONFIG_RMSK                                                               0xff07
#define HWIO_QSPI_XIP_ADDR_PH_CONFIG_IN(x)            \
                in_dword(HWIO_QSPI_XIP_ADDR_PH_CONFIG_ADDR(x))
#define HWIO_QSPI_XIP_ADDR_PH_CONFIG_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_XIP_ADDR_PH_CONFIG_ADDR(x), m)
#define HWIO_QSPI_XIP_ADDR_PH_CONFIG_OUT(x, v)            \
                out_dword(HWIO_QSPI_XIP_ADDR_PH_CONFIG_ADDR(x),v)
#define HWIO_QSPI_XIP_ADDR_PH_CONFIG_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_QSPI_XIP_ADDR_PH_CONFIG_ADDR(x),m,v,HWIO_QSPI_XIP_ADDR_PH_CONFIG_IN(x))
#define HWIO_QSPI_XIP_ADDR_PH_CONFIG_ADDRESS_LENGTH_BMSK                                                0xff00
#define HWIO_QSPI_XIP_ADDR_PH_CONFIG_ADDRESS_LENGTH_SHFT                                                     8
#define HWIO_QSPI_XIP_ADDR_PH_CONFIG_DDR_SDR_SELECTOR_BMSK                                                 0x4
#define HWIO_QSPI_XIP_ADDR_PH_CONFIG_DDR_SDR_SELECTOR_SHFT                                                   2
#define HWIO_QSPI_XIP_ADDR_PH_CONFIG_BUS_WIDTH_SELECTOR_BMSK                                               0x3
#define HWIO_QSPI_XIP_ADDR_PH_CONFIG_BUS_WIDTH_SELECTOR_SHFT                                                 0

#define HWIO_QSPI_XIP_MODE_PH_CONFIG_ADDR(x)                                                        ((x) + 0x218)
#define HWIO_QSPI_XIP_MODE_PH_CONFIG_PHYS(x)                                                        ((x) + 0x218)
#define HWIO_QSPI_XIP_MODE_PH_CONFIG_OFFS                                                           (0x218)
#define HWIO_QSPI_XIP_MODE_PH_CONFIG_RMSK                                                           0xff00000f
#define HWIO_QSPI_XIP_MODE_PH_CONFIG_IN(x)            \
                in_dword(HWIO_QSPI_XIP_MODE_PH_CONFIG_ADDR(x))
#define HWIO_QSPI_XIP_MODE_PH_CONFIG_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_XIP_MODE_PH_CONFIG_ADDR(x), m)
#define HWIO_QSPI_XIP_MODE_PH_CONFIG_OUT(x, v)            \
                out_dword(HWIO_QSPI_XIP_MODE_PH_CONFIG_ADDR(x),v)
#define HWIO_QSPI_XIP_MODE_PH_CONFIG_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_QSPI_XIP_MODE_PH_CONFIG_ADDR(x),m,v,HWIO_QSPI_XIP_MODE_PH_CONFIG_IN(x))
#define HWIO_QSPI_XIP_MODE_PH_CONFIG_MODE_BYTE_VALUE_BMSK                                           0xff000000
#define HWIO_QSPI_XIP_MODE_PH_CONFIG_MODE_BYTE_VALUE_SHFT                                                   24
#define HWIO_QSPI_XIP_MODE_PH_CONFIG_MODE_PHASE_ENABLE_BMSK                                                0x8
#define HWIO_QSPI_XIP_MODE_PH_CONFIG_MODE_PHASE_ENABLE_SHFT                                                  3
#define HWIO_QSPI_XIP_MODE_PH_CONFIG_DDR_SDR_SELECTOR_BMSK                                                 0x4
#define HWIO_QSPI_XIP_MODE_PH_CONFIG_DDR_SDR_SELECTOR_SHFT                                                   2
#define HWIO_QSPI_XIP_MODE_PH_CONFIG_BUS_WIDTH_SELECTOR_BMSK                                               0x3
#define HWIO_QSPI_XIP_MODE_PH_CONFIG_BUS_WIDTH_SELECTOR_SHFT                                                 0

#define HWIO_QSPI_XIP_DUMMY_PH_CONFIG_ADDR(x)                                                       ((x) + 0x21c)
#define HWIO_QSPI_XIP_DUMMY_PH_CONFIG_PHYS(x)                                                       ((x) + 0x21c)
#define HWIO_QSPI_XIP_DUMMY_PH_CONFIG_OFFS                                                          (0x21c)
#define HWIO_QSPI_XIP_DUMMY_PH_CONFIG_RMSK                                                          0x1ff0ff07
#define HWIO_QSPI_XIP_DUMMY_PH_CONFIG_IN(x)            \
                in_dword(HWIO_QSPI_XIP_DUMMY_PH_CONFIG_ADDR(x))
#define HWIO_QSPI_XIP_DUMMY_PH_CONFIG_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_XIP_DUMMY_PH_CONFIG_ADDR(x), m)
#define HWIO_QSPI_XIP_DUMMY_PH_CONFIG_OUT(x, v)            \
                out_dword(HWIO_QSPI_XIP_DUMMY_PH_CONFIG_ADDR(x),v)
#define HWIO_QSPI_XIP_DUMMY_PH_CONFIG_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_QSPI_XIP_DUMMY_PH_CONFIG_ADDR(x),m,v,HWIO_QSPI_XIP_DUMMY_PH_CONFIG_IN(x))
#define HWIO_QSPI_XIP_DUMMY_PH_CONFIG_DRIVE_BUS_DUMMY_PH_BMSK                                       0x10000000
#define HWIO_QSPI_XIP_DUMMY_PH_CONFIG_DRIVE_BUS_DUMMY_PH_SHFT                                               28
#define HWIO_QSPI_XIP_DUMMY_PH_CONFIG_BUS_VALUE_DUMMY_PH_BMSK                                        0xff00000
#define HWIO_QSPI_XIP_DUMMY_PH_CONFIG_BUS_VALUE_DUMMY_PH_SHFT                                               20
#define HWIO_QSPI_XIP_DUMMY_PH_CONFIG_DUMMY_LENGTH_BMSK                                                 0xff00
#define HWIO_QSPI_XIP_DUMMY_PH_CONFIG_DUMMY_LENGTH_SHFT                                                      8
#define HWIO_QSPI_XIP_DUMMY_PH_CONFIG_DDR_SDR_SELECTOR_BMSK                                                0x4
#define HWIO_QSPI_XIP_DUMMY_PH_CONFIG_DDR_SDR_SELECTOR_SHFT                                                  2
#define HWIO_QSPI_XIP_DUMMY_PH_CONFIG_BUS_WIDTH_SELECTOR_BMSK                                              0x3
#define HWIO_QSPI_XIP_DUMMY_PH_CONFIG_BUS_WIDTH_SELECTOR_SHFT                                                0

#define HWIO_QSPI_XIP_DATA_PH_CONFIG_ADDR(x)                                                        ((x) + 0x220)
#define HWIO_QSPI_XIP_DATA_PH_CONFIG_PHYS(x)                                                        ((x) + 0x220)
#define HWIO_QSPI_XIP_DATA_PH_CONFIG_OFFS                                                           (0x220)
#define HWIO_QSPI_XIP_DATA_PH_CONFIG_RMSK                                                                  0x7
#define HWIO_QSPI_XIP_DATA_PH_CONFIG_IN(x)            \
                in_dword(HWIO_QSPI_XIP_DATA_PH_CONFIG_ADDR(x))
#define HWIO_QSPI_XIP_DATA_PH_CONFIG_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_XIP_DATA_PH_CONFIG_ADDR(x), m)
#define HWIO_QSPI_XIP_DATA_PH_CONFIG_OUT(x, v)            \
                out_dword(HWIO_QSPI_XIP_DATA_PH_CONFIG_ADDR(x),v)
#define HWIO_QSPI_XIP_DATA_PH_CONFIG_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_QSPI_XIP_DATA_PH_CONFIG_ADDR(x),m,v,HWIO_QSPI_XIP_DATA_PH_CONFIG_IN(x))
#define HWIO_QSPI_XIP_DATA_PH_CONFIG_DDR_SDR_SELECTOR_BMSK                                                 0x4
#define HWIO_QSPI_XIP_DATA_PH_CONFIG_DDR_SDR_SELECTOR_SHFT                                                   2
#define HWIO_QSPI_XIP_DATA_PH_CONFIG_BUS_WIDTH_SELECTOR_BMSK                                               0x3
#define HWIO_QSPI_XIP_DATA_PH_CONFIG_BUS_WIDTH_SELECTOR_SHFT                                                 0

#define HWIO_QSPI_XIP_SUSPEND_PH_CONFIG_ADDR(x)                                                     ((x) + 0x224)
#define HWIO_QSPI_XIP_SUSPEND_PH_CONFIG_PHYS(x)                                                     ((x) + 0x224)
#define HWIO_QSPI_XIP_SUSPEND_PH_CONFIG_OFFS                                                        (0x224)
#define HWIO_QSPI_XIP_SUSPEND_PH_CONFIG_RMSK                                                        0xff03ff0f
#define HWIO_QSPI_XIP_SUSPEND_PH_CONFIG_IN(x)            \
                in_dword(HWIO_QSPI_XIP_SUSPEND_PH_CONFIG_ADDR(x))
#define HWIO_QSPI_XIP_SUSPEND_PH_CONFIG_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_XIP_SUSPEND_PH_CONFIG_ADDR(x), m)
#define HWIO_QSPI_XIP_SUSPEND_PH_CONFIG_OUT(x, v)            \
                out_dword(HWIO_QSPI_XIP_SUSPEND_PH_CONFIG_ADDR(x),v)
#define HWIO_QSPI_XIP_SUSPEND_PH_CONFIG_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_QSPI_XIP_SUSPEND_PH_CONFIG_ADDR(x),m,v,HWIO_QSPI_XIP_SUSPEND_PH_CONFIG_IN(x))
#define HWIO_QSPI_XIP_SUSPEND_PH_CONFIG_SUSPEND_OP_CODE_BMSK                                        0xff000000
#define HWIO_QSPI_XIP_SUSPEND_PH_CONFIG_SUSPEND_OP_CODE_SHFT                                                24
#define HWIO_QSPI_XIP_SUSPEND_PH_CONFIG_T_SUSPEND_PROG_DELAY_BMSK                                      0x3ff00
#define HWIO_QSPI_XIP_SUSPEND_PH_CONFIG_T_SUSPEND_PROG_DELAY_SHFT                                            8
#define HWIO_QSPI_XIP_SUSPEND_PH_CONFIG_SUSPEND_ENABLE_BMSK                                                0x8
#define HWIO_QSPI_XIP_SUSPEND_PH_CONFIG_SUSPEND_ENABLE_SHFT                                                  3
#define HWIO_QSPI_XIP_SUSPEND_PH_CONFIG_DDR_SDR_SELECTOR_BMSK                                              0x4
#define HWIO_QSPI_XIP_SUSPEND_PH_CONFIG_DDR_SDR_SELECTOR_SHFT                                                2
#define HWIO_QSPI_XIP_SUSPEND_PH_CONFIG_BUS_WIDTH_SELECTOR_BMSK                                            0x3
#define HWIO_QSPI_XIP_SUSPEND_PH_CONFIG_BUS_WIDTH_SELECTOR_SHFT                                              0

#define HWIO_QSPI_XIP_RESUME_PH_CONFIG_ADDR(x)                                                      ((x) + 0x228)
#define HWIO_QSPI_XIP_RESUME_PH_CONFIG_PHYS(x)                                                      ((x) + 0x228)
#define HWIO_QSPI_XIP_RESUME_PH_CONFIG_OFFS                                                         (0x228)
#define HWIO_QSPI_XIP_RESUME_PH_CONFIG_RMSK                                                         0xff03ff0f
#define HWIO_QSPI_XIP_RESUME_PH_CONFIG_IN(x)            \
                in_dword(HWIO_QSPI_XIP_RESUME_PH_CONFIG_ADDR(x))
#define HWIO_QSPI_XIP_RESUME_PH_CONFIG_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_XIP_RESUME_PH_CONFIG_ADDR(x), m)
#define HWIO_QSPI_XIP_RESUME_PH_CONFIG_OUT(x, v)            \
                out_dword(HWIO_QSPI_XIP_RESUME_PH_CONFIG_ADDR(x),v)
#define HWIO_QSPI_XIP_RESUME_PH_CONFIG_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_QSPI_XIP_RESUME_PH_CONFIG_ADDR(x),m,v,HWIO_QSPI_XIP_RESUME_PH_CONFIG_IN(x))
#define HWIO_QSPI_XIP_RESUME_PH_CONFIG_RESUME_OP_CODE_BMSK                                          0xff000000
#define HWIO_QSPI_XIP_RESUME_PH_CONFIG_RESUME_OP_CODE_SHFT                                                  24
#define HWIO_QSPI_XIP_RESUME_PH_CONFIG_T_RESUME_PROG_DELAY_BMSK                                        0x3ff00
#define HWIO_QSPI_XIP_RESUME_PH_CONFIG_T_RESUME_PROG_DELAY_SHFT                                              8
#define HWIO_QSPI_XIP_RESUME_PH_CONFIG_RESUME_ENABLE_BMSK                                                  0x8
#define HWIO_QSPI_XIP_RESUME_PH_CONFIG_RESUME_ENABLE_SHFT                                                    3
#define HWIO_QSPI_XIP_RESUME_PH_CONFIG_DDR_SDR_SELECTOR_BMSK                                               0x4
#define HWIO_QSPI_XIP_RESUME_PH_CONFIG_DDR_SDR_SELECTOR_SHFT                                                 2
#define HWIO_QSPI_XIP_RESUME_PH_CONFIG_BUS_WIDTH_SELECTOR_BMSK                                             0x3
#define HWIO_QSPI_XIP_RESUME_PH_CONFIG_BUS_WIDTH_SELECTOR_SHFT                                               0

#define HWIO_QSPI_XIP_REGION_n_SIZE_ADDR(base,n)                                                    ((base) + 0X230 + (0x4*(n)))
#define HWIO_QSPI_XIP_REGION_n_SIZE_PHYS(base,n)                                                    ((base) + 0X230 + (0x4*(n)))
#define HWIO_QSPI_XIP_REGION_n_SIZE_OFFS(n)                                                         (0X230 + (0x4*(n)))
#define HWIO_QSPI_XIP_REGION_n_SIZE_RMSK                                                            0xffffffff
#define HWIO_QSPI_XIP_REGION_n_SIZE_MAXn                                                                     4
#define HWIO_QSPI_XIP_REGION_n_SIZE_INI(base,n)                \
                in_dword_masked(HWIO_QSPI_XIP_REGION_n_SIZE_ADDR(base,n), HWIO_QSPI_XIP_REGION_n_SIZE_RMSK)
#define HWIO_QSPI_XIP_REGION_n_SIZE_INMI(base,n,mask)        \
                in_dword_masked(HWIO_QSPI_XIP_REGION_n_SIZE_ADDR(base,n), mask)
#define HWIO_QSPI_XIP_REGION_n_SIZE_OUTI(base,n,val)        \
                out_dword(HWIO_QSPI_XIP_REGION_n_SIZE_ADDR(base,n),val)
#define HWIO_QSPI_XIP_REGION_n_SIZE_OUTMI(base,n,mask,val) \
                out_dword_masked_ns(HWIO_QSPI_XIP_REGION_n_SIZE_ADDR(base,n),mask,val,HWIO_QSPI_XIP_REGION_n_SIZE_INI(base,n))
#define HWIO_QSPI_XIP_REGION_n_SIZE_REGION_SIZE_BMSK                                                0xffffffff
#define HWIO_QSPI_XIP_REGION_n_SIZE_REGION_SIZE_SHFT                                                         0

#define HWIO_QSPI_XIP_REGION_n_SPI_BASE_ADDR(base,n)                                                ((base) + 0X270 + (0x4*(n)))
#define HWIO_QSPI_XIP_REGION_n_SPI_BASE_PHYS(base,n)                                                ((base) + 0X270 + (0x4*(n)))
#define HWIO_QSPI_XIP_REGION_n_SPI_BASE_OFFS(n)                                                     (0X270 + (0x4*(n)))
#define HWIO_QSPI_XIP_REGION_n_SPI_BASE_RMSK                                                        0xffffffff
#define HWIO_QSPI_XIP_REGION_n_SPI_BASE_MAXn                                                                 4
#define HWIO_QSPI_XIP_REGION_n_SPI_BASE_INI(base,n)                \
                in_dword_masked(HWIO_QSPI_XIP_REGION_n_SPI_BASE_ADDR(base,n), HWIO_QSPI_XIP_REGION_n_SPI_BASE_RMSK)
#define HWIO_QSPI_XIP_REGION_n_SPI_BASE_INMI(base,n,mask)        \
                in_dword_masked(HWIO_QSPI_XIP_REGION_n_SPI_BASE_ADDR(base,n), mask)
#define HWIO_QSPI_XIP_REGION_n_SPI_BASE_OUTI(base,n,val)        \
                out_dword(HWIO_QSPI_XIP_REGION_n_SPI_BASE_ADDR(base,n),val)
#define HWIO_QSPI_XIP_REGION_n_SPI_BASE_OUTMI(base,n,mask,val) \
                out_dword_masked_ns(HWIO_QSPI_XIP_REGION_n_SPI_BASE_ADDR(base,n),mask,val,HWIO_QSPI_XIP_REGION_n_SPI_BASE_INI(base,n))
#define HWIO_QSPI_XIP_REGION_n_SPI_BASE_REGION_SPI_BASE_BMSK                                        0xffffffff
#define HWIO_QSPI_XIP_REGION_n_SPI_BASE_REGION_SPI_BASE_SHFT                                                 0

#define HWIO_QSPI_XIP_ERR_PATTERN_ADDR(x)                                                           ((x) + 0x310)
#define HWIO_QSPI_XIP_ERR_PATTERN_PHYS(x)                                                           ((x) + 0x310)
#define HWIO_QSPI_XIP_ERR_PATTERN_OFFS                                                              (0x310)
#define HWIO_QSPI_XIP_ERR_PATTERN_RMSK                                                              0xffffffff
#define HWIO_QSPI_XIP_ERR_PATTERN_IN(x)            \
                in_dword(HWIO_QSPI_XIP_ERR_PATTERN_ADDR(x))
#define HWIO_QSPI_XIP_ERR_PATTERN_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_XIP_ERR_PATTERN_ADDR(x), m)
#define HWIO_QSPI_XIP_ERR_PATTERN_OUT(x, v)            \
                out_dword(HWIO_QSPI_XIP_ERR_PATTERN_ADDR(x),v)
#define HWIO_QSPI_XIP_ERR_PATTERN_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_QSPI_XIP_ERR_PATTERN_ADDR(x),m,v,HWIO_QSPI_XIP_ERR_PATTERN_IN(x))
#define HWIO_QSPI_XIP_ERR_PATTERN_ERR_PATTERN_BMSK                                                  0xffffffff
#define HWIO_QSPI_XIP_ERR_PATTERN_ERR_PATTERN_SHFT                                                           0

#define HWIO_QSPI_XIP_WR_DUMMY_PH_CONFIG_ADDR(x)                                                    ((x) + 0x314)
#define HWIO_QSPI_XIP_WR_DUMMY_PH_CONFIG_PHYS(x)                                                    ((x) + 0x314)
#define HWIO_QSPI_XIP_WR_DUMMY_PH_CONFIG_OFFS                                                       (0x314)
#define HWIO_QSPI_XIP_WR_DUMMY_PH_CONFIG_RMSK                                                       0x1ff0ff07
#define HWIO_QSPI_XIP_WR_DUMMY_PH_CONFIG_IN(x)            \
                in_dword(HWIO_QSPI_XIP_WR_DUMMY_PH_CONFIG_ADDR(x))
#define HWIO_QSPI_XIP_WR_DUMMY_PH_CONFIG_INM(x, m)            \
                in_dword_masked(HWIO_QSPI_XIP_WR_DUMMY_PH_CONFIG_ADDR(x), m)
#define HWIO_QSPI_XIP_WR_DUMMY_PH_CONFIG_OUT(x, v)            \
                out_dword(HWIO_QSPI_XIP_WR_DUMMY_PH_CONFIG_ADDR(x),v)
#define HWIO_QSPI_XIP_WR_DUMMY_PH_CONFIG_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_QSPI_XIP_WR_DUMMY_PH_CONFIG_ADDR(x),m,v,HWIO_QSPI_XIP_WR_DUMMY_PH_CONFIG_IN(x))
#define HWIO_QSPI_XIP_WR_DUMMY_PH_CONFIG_DRIVE_BUS_DUMMY_PH_BMSK                                    0x10000000
#define HWIO_QSPI_XIP_WR_DUMMY_PH_CONFIG_DRIVE_BUS_DUMMY_PH_SHFT                                            28
#define HWIO_QSPI_XIP_WR_DUMMY_PH_CONFIG_BUS_VALUE_DUMMY_PH_BMSK                                     0xff00000
#define HWIO_QSPI_XIP_WR_DUMMY_PH_CONFIG_BUS_VALUE_DUMMY_PH_SHFT                                            20
#define HWIO_QSPI_XIP_WR_DUMMY_PH_CONFIG_DUMMY_LENGTH_BMSK                                              0xff00
#define HWIO_QSPI_XIP_WR_DUMMY_PH_CONFIG_DUMMY_LENGTH_SHFT                                                   8
#define HWIO_QSPI_XIP_WR_DUMMY_PH_CONFIG_DDR_SDR_SELECTOR_BMSK                                             0x4
#define HWIO_QSPI_XIP_WR_DUMMY_PH_CONFIG_DDR_SDR_SELECTOR_SHFT                                               2
#define HWIO_QSPI_XIP_WR_DUMMY_PH_CONFIG_BUS_WIDTH_SELECTOR_BMSK                                           0x3
#define HWIO_QSPI_XIP_WR_DUMMY_PH_CONFIG_BUS_WIDTH_SELECTOR_SHFT                                             0

#define HWIO_HC_REG_DLL_CONFIG_ADDR(x)                                                              ((x) + 0x318)
#define HWIO_HC_REG_DLL_CONFIG_PHYS(x)                                                              ((x) + 0x318)
#define HWIO_HC_REG_DLL_CONFIG_OFFS                                                                 (0x318)
#define HWIO_HC_REG_DLL_CONFIG_RMSK                                                                 0xffffffff
#define HWIO_HC_REG_DLL_CONFIG_IN(x)            \
                in_dword(HWIO_HC_REG_DLL_CONFIG_ADDR(x))
#define HWIO_HC_REG_DLL_CONFIG_INM(x, m)            \
                in_dword_masked(HWIO_HC_REG_DLL_CONFIG_ADDR(x), m)
#define HWIO_HC_REG_DLL_CONFIG_OUT(x, v)            \
                out_dword(HWIO_HC_REG_DLL_CONFIG_ADDR(x),v)
#define HWIO_HC_REG_DLL_CONFIG_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_HC_REG_DLL_CONFIG_ADDR(x),m,v,HWIO_HC_REG_DLL_CONFIG_IN(x))
#define HWIO_HC_REG_DLL_CONFIG_QSPI_DIS_DOUT_BMSK                                                   0x80000000
#define HWIO_HC_REG_DLL_CONFIG_QSPI_DIS_DOUT_SHFT                                                           31
#define HWIO_HC_REG_DLL_CONFIG_DLL_RST_BMSK                                                         0x40000000
#define HWIO_HC_REG_DLL_CONFIG_DLL_RST_SHFT                                                                 30
#define HWIO_HC_REG_DLL_CONFIG_PDN_BMSK                                                             0x20000000
#define HWIO_HC_REG_DLL_CONFIG_PDN_SHFT                                                                     29
#define HWIO_HC_REG_DLL_CONFIG_CK_INTP_SEL_BMSK                                                     0x10000000
#define HWIO_HC_REG_DLL_CONFIG_CK_INTP_SEL_SHFT                                                             28
#define HWIO_HC_REG_DLL_CONFIG_CK_INTP_EN_BMSK                                                       0x8000000
#define HWIO_HC_REG_DLL_CONFIG_CK_INTP_EN_SHFT                                                              27
#define HWIO_HC_REG_DLL_CONFIG_MCLK_FREQ_BMSK                                                        0x7000000
#define HWIO_HC_REG_DLL_CONFIG_MCLK_FREQ_SHFT                                                               24
#define HWIO_HC_REG_DLL_CONFIG_CDR_SELEXT_BMSK                                                        0xf00000
#define HWIO_HC_REG_DLL_CONFIG_CDR_SELEXT_SHFT                                                              20
#define HWIO_HC_REG_DLL_CONFIG_CDR_EXT_EN_BMSK                                                         0x80000
#define HWIO_HC_REG_DLL_CONFIG_CDR_EXT_EN_SHFT                                                              19
#define HWIO_HC_REG_DLL_CONFIG_CK_OUT_EN_BMSK                                                          0x40000
#define HWIO_HC_REG_DLL_CONFIG_CK_OUT_EN_SHFT                                                               18
#define HWIO_HC_REG_DLL_CONFIG_CDR_EN_BMSK                                                             0x20000
#define HWIO_HC_REG_DLL_CONFIG_CDR_EN_SHFT                                                                  17
#define HWIO_HC_REG_DLL_CONFIG_DLL_EN_BMSK                                                             0x10000
#define HWIO_HC_REG_DLL_CONFIG_DLL_EN_SHFT                                                                  16
#define HWIO_HC_REG_DLL_CONFIG_CDR_UPD_RATE_BMSK                                                        0xc000
#define HWIO_HC_REG_DLL_CONFIG_CDR_UPD_RATE_SHFT                                                            14
#define HWIO_HC_REG_DLL_CONFIG_DLL_UPD_RATE_BMSK                                                        0x3000
#define HWIO_HC_REG_DLL_CONFIG_DLL_UPD_RATE_SHFT                                                            12
#define HWIO_HC_REG_DLL_CONFIG_DLL_PHASE_DET_BMSK                                                        0xc00
#define HWIO_HC_REG_DLL_CONFIG_DLL_PHASE_DET_SHFT                                                           10
#define HWIO_HC_REG_DLL_CONFIG_CDR_ALGORITHM_SEL_BMSK                                                    0x200
#define HWIO_HC_REG_DLL_CONFIG_CDR_ALGORITHM_SEL_SHFT                                                        9
#define HWIO_HC_REG_DLL_CONFIG_DLY_LINE_SWITCH_CLK_BMSK                                                  0x100
#define HWIO_HC_REG_DLL_CONFIG_DLY_LINE_SWITCH_CLK_SHFT                                                      8
#define HWIO_HC_REG_DLL_CONFIG_CDR_PHASE_SEL_MODE_BMSK                                                    0xc0
#define HWIO_HC_REG_DLL_CONFIG_CDR_PHASE_SEL_MODE_SHFT                                                       6
#define HWIO_HC_REG_DLL_CONFIG_MCLK_GATING_ENABLE_BMSK                                                    0x20
#define HWIO_HC_REG_DLL_CONFIG_MCLK_GATING_ENABLE_SHFT                                                       5
#define HWIO_HC_REG_DLL_CONFIG_FINE_PHASE_ENABLE_BMSK                                                     0x10
#define HWIO_HC_REG_DLL_CONFIG_FINE_PHASE_ENABLE_SHFT                                                        4
#define HWIO_HC_REG_DLL_CONFIG_CDR_FINE_PHASE_BMSK                                                         0xc
#define HWIO_HC_REG_DLL_CONFIG_CDR_FINE_PHASE_SHFT                                                           2
#define HWIO_HC_REG_DLL_CONFIG_RCLK_IN_TEST_EN_BMSK                                                        0x2
#define HWIO_HC_REG_DLL_CONFIG_RCLK_IN_TEST_EN_SHFT                                                          1
#define HWIO_HC_REG_DLL_CONFIG_CMD_DAT_TRACK_SEL_BMSK                                                      0x1
#define HWIO_HC_REG_DLL_CONFIG_CMD_DAT_TRACK_SEL_SHFT                                                        0

#define HWIO_HC_REG_DLL_STATUS_ADDR(x)                                                              ((x) + 0x31c)
#define HWIO_HC_REG_DLL_STATUS_PHYS(x)                                                              ((x) + 0x31c)
#define HWIO_HC_REG_DLL_STATUS_OFFS                                                                 (0x31c)
#define HWIO_HC_REG_DLL_STATUS_RMSK                                                                     0x1ffd
#define HWIO_HC_REG_DLL_STATUS_IN(x)            \
                in_dword(HWIO_HC_REG_DLL_STATUS_ADDR(x))
#define HWIO_HC_REG_DLL_STATUS_INM(x, m)            \
                in_dword_masked(HWIO_HC_REG_DLL_STATUS_ADDR(x), m)
#define HWIO_HC_REG_DLL_STATUS_QSPI_DTEST_MUXSEL_BMSK                                                   0x1000
#define HWIO_HC_REG_DLL_STATUS_QSPI_DTEST_MUXSEL_SHFT                                                       12
#define HWIO_HC_REG_DLL_STATUS_DDR_DLL_LOCK_JDR_BMSK                                                     0x800
#define HWIO_HC_REG_DLL_STATUS_DDR_DLL_LOCK_JDR_SHFT                                                        11
#define HWIO_HC_REG_DLL_STATUS_QSPI_DLL_DTEST_OUT_ATPG_BMSK                                              0x600
#define HWIO_HC_REG_DLL_STATUS_QSPI_DLL_DTEST_OUT_ATPG_SHFT                                                  9
#define HWIO_HC_REG_DLL_STATUS_QSPI_DLL_LOCK_ATPG_BMSK                                                   0x100
#define HWIO_HC_REG_DLL_STATUS_QSPI_DLL_LOCK_ATPG_SHFT                                                       8
#define HWIO_HC_REG_DLL_STATUS_DLL_LOCK_BMSK                                                              0x80
#define HWIO_HC_REG_DLL_STATUS_DLL_LOCK_SHFT                                                                 7
#define HWIO_HC_REG_DLL_STATUS_CDR_PHASE_BMSK                                                             0x78
#define HWIO_HC_REG_DLL_STATUS_CDR_PHASE_SHFT                                                                3
#define HWIO_HC_REG_DLL_STATUS_DDLL_COARSE_CAL_BMSK                                                        0x4
#define HWIO_HC_REG_DLL_STATUS_DDLL_COARSE_CAL_SHFT                                                          2
#define HWIO_HC_REG_DLL_STATUS_DDR_DLL_LOCK_BMSK                                                           0x1
#define HWIO_HC_REG_DLL_STATUS_DDR_DLL_LOCK_SHFT                                                             0

#define HWIO_HC_REG_DLL_CONFIG_2_ADDR(x)                                                            ((x) + 0x320)
#define HWIO_HC_REG_DLL_CONFIG_2_PHYS(x)                                                            ((x) + 0x320)
#define HWIO_HC_REG_DLL_CONFIG_2_OFFS                                                               (0x320)
#define HWIO_HC_REG_DLL_CONFIG_2_RMSK                                                                 0x6ffc0f
#define HWIO_HC_REG_DLL_CONFIG_2_IN(x)            \
                in_dword(HWIO_HC_REG_DLL_CONFIG_2_ADDR(x))
#define HWIO_HC_REG_DLL_CONFIG_2_INM(x, m)            \
                in_dword_masked(HWIO_HC_REG_DLL_CONFIG_2_ADDR(x), m)
#define HWIO_HC_REG_DLL_CONFIG_2_OUT(x, v)            \
                out_dword(HWIO_HC_REG_DLL_CONFIG_2_ADDR(x),v)
#define HWIO_HC_REG_DLL_CONFIG_2_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_HC_REG_DLL_CONFIG_2_ADDR(x),m,v,HWIO_HC_REG_DLL_CONFIG_2_IN(x))
#define HWIO_HC_REG_DLL_CONFIG_2_DLL_OUTPUT_TO_PAD_BMSK                                               0x400000
#define HWIO_HC_REG_DLL_CONFIG_2_DLL_OUTPUT_TO_PAD_SHFT                                                     22
#define HWIO_HC_REG_DLL_CONFIG_2_DLL_CLOCK_DISABLE_BMSK                                               0x200000
#define HWIO_HC_REG_DLL_CONFIG_2_DLL_CLOCK_DISABLE_SHFT                                                     21
#define HWIO_HC_REG_DLL_CONFIG_2_LOW_FREQ_MODE_BMSK                                                    0x80000
#define HWIO_HC_REG_DLL_CONFIG_2_LOW_FREQ_MODE_SHFT                                                         19
#define HWIO_HC_REG_DLL_CONFIG_2_FLL_CYCLE_CNT_BMSK                                                    0x40000
#define HWIO_HC_REG_DLL_CONFIG_2_FLL_CYCLE_CNT_SHFT                                                         18
#define HWIO_HC_REG_DLL_CONFIG_2_MCLK_FREQ_CALC_BMSK                                                   0x3fc00
#define HWIO_HC_REG_DLL_CONFIG_2_MCLK_FREQ_CALC_SHFT                                                        10
#define HWIO_HC_REG_DLL_CONFIG_2_DDR_TRAFFIC_INIT_SEL_BMSK                                                 0xc
#define HWIO_HC_REG_DLL_CONFIG_2_DDR_TRAFFIC_INIT_SEL_SHFT                                                   2
#define HWIO_HC_REG_DLL_CONFIG_2_DDR_TRAFFIC_INIT_SW_BMSK                                                  0x2
#define HWIO_HC_REG_DLL_CONFIG_2_DDR_TRAFFIC_INIT_SW_SHFT                                                    1
#define HWIO_HC_REG_DLL_CONFIG_2_DDR_CAL_EN_BMSK                                                           0x1
#define HWIO_HC_REG_DLL_CONFIG_2_DDR_CAL_EN_SHFT                                                             0

#define HWIO_HC_REG_DDR_CONFIG_ADDR(x)                                                              ((x) + 0x324)
#define HWIO_HC_REG_DDR_CONFIG_PHYS(x)                                                              ((x) + 0x324)
#define HWIO_HC_REG_DDR_CONFIG_OFFS                                                                 (0x324)
#define HWIO_HC_REG_DDR_CONFIG_RMSK                                                                 0xffffffff
#define HWIO_HC_REG_DDR_CONFIG_IN(x)            \
                in_dword(HWIO_HC_REG_DDR_CONFIG_ADDR(x))
#define HWIO_HC_REG_DDR_CONFIG_INM(x, m)            \
                in_dword_masked(HWIO_HC_REG_DDR_CONFIG_ADDR(x), m)
#define HWIO_HC_REG_DDR_CONFIG_OUT(x, v)            \
                out_dword(HWIO_HC_REG_DDR_CONFIG_ADDR(x),v)
#define HWIO_HC_REG_DDR_CONFIG_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_HC_REG_DDR_CONFIG_ADDR(x),m,v,HWIO_HC_REG_DDR_CONFIG_IN(x))
#define HWIO_HC_REG_DDR_CONFIG_PRG_DLY_EN_BMSK                                                      0x80000000
#define HWIO_HC_REG_DDR_CONFIG_PRG_DLY_EN_SHFT                                                              31
#define HWIO_HC_REG_DDR_CONFIG_EXT_PRG_RCLK_DLY_EN_BMSK                                             0x40000000
#define HWIO_HC_REG_DDR_CONFIG_EXT_PRG_RCLK_DLY_EN_SHFT                                                     30
#define HWIO_HC_REG_DDR_CONFIG_EXT_PRG_RCLK_DLY_CODE_BMSK                                           0x38000000
#define HWIO_HC_REG_DDR_CONFIG_EXT_PRG_RCLK_DLY_CODE_SHFT                                                   27
#define HWIO_HC_REG_DDR_CONFIG_EXT_PRG_RCLK_DLY_BMSK                                                 0x7e00000
#define HWIO_HC_REG_DDR_CONFIG_EXT_PRG_RCLK_DLY_SHFT                                                        21
#define HWIO_HC_REG_DDR_CONFIG_TCXO_CYCLES_DLY_LINE_BMSK                                              0x1ff000
#define HWIO_HC_REG_DDR_CONFIG_TCXO_CYCLES_DLY_LINE_SHFT                                                    12
#define HWIO_HC_REG_DDR_CONFIG_TCXO_CYCLES_CNT_BMSK                                                      0xe00
#define HWIO_HC_REG_DDR_CONFIG_TCXO_CYCLES_CNT_SHFT                                                          9
#define HWIO_HC_REG_DDR_CONFIG_PRG_RCLK_DLY_BMSK                                                         0x1ff
#define HWIO_HC_REG_DDR_CONFIG_PRG_RCLK_DLY_SHFT                                                             0

#define HWIO_HC_REG_DLL_TEST_CTL_ADDR(x)                                                            ((x) + 0x328)
#define HWIO_HC_REG_DLL_TEST_CTL_PHYS(x)                                                            ((x) + 0x328)
#define HWIO_HC_REG_DLL_TEST_CTL_OFFS                                                               (0x328)
#define HWIO_HC_REG_DLL_TEST_CTL_RMSK                                                               0xffffffff
#define HWIO_HC_REG_DLL_TEST_CTL_IN(x)            \
                in_dword(HWIO_HC_REG_DLL_TEST_CTL_ADDR(x))
#define HWIO_HC_REG_DLL_TEST_CTL_INM(x, m)            \
                in_dword_masked(HWIO_HC_REG_DLL_TEST_CTL_ADDR(x), m)
#define HWIO_HC_REG_DLL_TEST_CTL_OUT(x, v)            \
                out_dword(HWIO_HC_REG_DLL_TEST_CTL_ADDR(x),v)
#define HWIO_HC_REG_DLL_TEST_CTL_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_HC_REG_DLL_TEST_CTL_ADDR(x),m,v,HWIO_HC_REG_DLL_TEST_CTL_IN(x))
#define HWIO_HC_REG_DLL_TEST_CTL_QSPI_DLL_TEST_CTL_BMSK                                             0xffffffff
#define HWIO_HC_REG_DLL_TEST_CTL_QSPI_DLL_TEST_CTL_SHFT                                                      0

#define HWIO_HC_REG_DLL_CONFIG_3_ADDR(x)                                                            ((x) + 0x32c)
#define HWIO_HC_REG_DLL_CONFIG_3_PHYS(x)                                                            ((x) + 0x32c)
#define HWIO_HC_REG_DLL_CONFIG_3_OFFS                                                               (0x32c)
#define HWIO_HC_REG_DLL_CONFIG_3_RMSK                                                                     0xff
#define HWIO_HC_REG_DLL_CONFIG_3_IN(x)            \
                in_dword(HWIO_HC_REG_DLL_CONFIG_3_ADDR(x))
#define HWIO_HC_REG_DLL_CONFIG_3_INM(x, m)            \
                in_dword_masked(HWIO_HC_REG_DLL_CONFIG_3_ADDR(x), m)
#define HWIO_HC_REG_DLL_CONFIG_3_OUT(x, v)            \
                out_dword(HWIO_HC_REG_DLL_CONFIG_3_ADDR(x),v)
#define HWIO_HC_REG_DLL_CONFIG_3_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_HC_REG_DLL_CONFIG_3_ADDR(x),m,v,HWIO_HC_REG_DLL_CONFIG_3_IN(x))
#define HWIO_HC_REG_DLL_CONFIG_3_QSPI_CONFIG_MSB_BMSK                                                     0xff
#define HWIO_HC_REG_DLL_CONFIG_3_QSPI_CONFIG_MSB_SHFT                                                        0

#define HWIO_HC_REG_DLL_STATUS_EXT_ADDR(x)                                                          ((x) + 0x330)
#define HWIO_HC_REG_DLL_STATUS_EXT_PHYS(x)                                                          ((x) + 0x330)
#define HWIO_HC_REG_DLL_STATUS_EXT_OFFS                                                             (0x330)
#define HWIO_HC_REG_DLL_STATUS_EXT_RMSK                                                              0x1ffffff
#define HWIO_HC_REG_DLL_STATUS_EXT_IN(x)            \
                in_dword(HWIO_HC_REG_DLL_STATUS_EXT_ADDR(x))
#define HWIO_HC_REG_DLL_STATUS_EXT_INM(x, m)            \
                in_dword_masked(HWIO_HC_REG_DLL_STATUS_EXT_ADDR(x), m)
#define HWIO_HC_REG_DLL_STATUS_EXT_QSPI_DLL_LOCK_BMSK                                                0x1000000
#define HWIO_HC_REG_DLL_STATUS_EXT_QSPI_DLL_LOCK_SHFT                                                       24
#define HWIO_HC_REG_DLL_STATUS_EXT_QSPI_DLL_STATUS_EXT_BMSK                                           0xffffff
#define HWIO_HC_REG_DLL_STATUS_EXT_QSPI_DLL_STATUS_EXT_SHFT                                                  0

#define HWIO_HC_REG_DLL_USER_CTL_ADDR(x)                                                            ((x) + 0x334)
#define HWIO_HC_REG_DLL_USER_CTL_PHYS(x)                                                            ((x) + 0x334)
#define HWIO_HC_REG_DLL_USER_CTL_OFFS                                                               (0x334)
#define HWIO_HC_REG_DLL_USER_CTL_RMSK                                                               0xffffffff
#define HWIO_HC_REG_DLL_USER_CTL_IN(x)            \
                in_dword(HWIO_HC_REG_DLL_USER_CTL_ADDR(x))
#define HWIO_HC_REG_DLL_USER_CTL_INM(x, m)            \
                in_dword_masked(HWIO_HC_REG_DLL_USER_CTL_ADDR(x), m)
#define HWIO_HC_REG_DLL_USER_CTL_OUT(x, v)            \
                out_dword(HWIO_HC_REG_DLL_USER_CTL_ADDR(x),v)
#define HWIO_HC_REG_DLL_USER_CTL_OUTM(x,m,v) \
                out_dword_masked_ns(HWIO_HC_REG_DLL_USER_CTL_ADDR(x),m,v,HWIO_HC_REG_DLL_USER_CTL_IN(x))
#define HWIO_HC_REG_DLL_USER_CTL_COARSE_TUNING_CTRL_BMSK                                            0x80000000
#define HWIO_HC_REG_DLL_USER_CTL_COARSE_TUNING_CTRL_SHFT                                                    31
#define HWIO_HC_REG_DLL_USER_CTL_DRR_BYPASS_EN_BMSK                                                 0x40000000
#define HWIO_HC_REG_DLL_USER_CTL_DRR_BYPASS_EN_SHFT                                                         30
#define HWIO_HC_REG_DLL_USER_CTL_BIAS_OK_SIGNAL_BMSK                                                0x20000000
#define HWIO_HC_REG_DLL_USER_CTL_BIAS_OK_SIGNAL_SHFT                                                        29
#define HWIO_HC_REG_DLL_USER_CTL_FLL_MODE_EN_BMSK                                                   0x10000000
#define HWIO_HC_REG_DLL_USER_CTL_FLL_MODE_EN_SHFT                                                           28
#define HWIO_HC_REG_DLL_USER_CTL_FINE_TUNE_MODE_EN_BMSK                                              0x8000000
#define HWIO_HC_REG_DLL_USER_CTL_FINE_TUNE_MODE_EN_SHFT                                                     27
#define HWIO_HC_REG_DLL_USER_CTL_TEST_CONFIG_BMSK                                                    0x7000000
#define HWIO_HC_REG_DLL_USER_CTL_TEST_CONFIG_SHFT                                                           24
#define HWIO_HC_REG_DLL_USER_CTL_RDAC_CONFIG_BMSK                                                     0xc00000
#define HWIO_HC_REG_DLL_USER_CTL_RDAC_CONFIG_SHFT                                                           22
#define HWIO_HC_REG_DLL_USER_CTL_REF_VOLT_CONFIG_BMSK                                                 0x300000
#define HWIO_HC_REG_DLL_USER_CTL_REF_VOLT_CONFIG_SHFT                                                       20
#define HWIO_HC_REG_DLL_USER_CTL_FREEZE_CDAC_OP_BMSK                                                   0x80000
#define HWIO_HC_REG_DLL_USER_CTL_FREEZE_CDAC_OP_SHFT                                                        19
#define HWIO_HC_REG_DLL_USER_CTL_FREEZE_RDAC_OP_BMSK                                                   0x40000
#define HWIO_HC_REG_DLL_USER_CTL_FREEZE_RDAC_OP_SHFT                                                        18
#define HWIO_HC_REG_DLL_USER_CTL_RESET_SDR_DAT_OUT_BMSK                                                0x20000
#define HWIO_HC_REG_DLL_USER_CTL_RESET_SDR_DAT_OUT_SHFT                                                     17
#define HWIO_HC_REG_DLL_USER_CTL_DELAY_LINE_OSC_MODE_BMSK                                              0x10000
#define HWIO_HC_REG_DLL_USER_CTL_DELAY_LINE_OSC_MODE_SHFT                                                   16
#define HWIO_HC_REG_DLL_USER_CTL_EDGE_LEVEL_BMSK                                                        0xc000
#define HWIO_HC_REG_DLL_USER_CTL_EDGE_LEVEL_SHFT                                                            14
#define HWIO_HC_REG_DLL_USER_CTL_PROG_DLY_DLL_UP_DN_BMSK                                                0x3000
#define HWIO_HC_REG_DLL_USER_CTL_PROG_DLY_DLL_UP_DN_SHFT                                                    12
#define HWIO_HC_REG_DLL_USER_CTL_RDAC_INIT_CODE_BMSK                                                     0xff0
#define HWIO_HC_REG_DLL_USER_CTL_RDAC_INIT_CODE_SHFT                                                         4
#define HWIO_HC_REG_DLL_USER_CTL_BIST_ERR_INJECT_BMSK                                                      0xf
#define HWIO_HC_REG_DLL_USER_CTL_BIST_ERR_INJECT_SHFT                                                        0


#endif /* __SAIL_OSPI_HWIO_H__ */
