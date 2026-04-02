#ifndef SAIL_CLKCTL_RSTSTS_HWIO_H
#define SAIL_CLKCTL_RSTSTS_HWIO_H
/*
===========================================================================
*/
/**
    @file sail_clkctl_RstSts_hwio.h
    @brief Auto-generated HWIO interface include file.

    Reference chip release:
        SA8775P (LeMansAU) r2 [lemansau_2.0_p3q3r43_MTO]
 
    This file contains HWIO register definitions for the following modules:
        SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG

    'Include' filters applied: SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS[SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG] 

    Generation parameters: 
    { 'filename': 'sail_clkctl_RstSts_hwio.h',
      'integer-qualifiers': True,
      'module-filter-include': { 'SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG': [ 'SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS']},
      'modules': ['SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG'],
      'output-attrs': True,
      'output-fvals': True,
      'output-offsets': True}

    Attribute definitions for the HWIO_*_ATTR macros are as follows:
        0x0: Command register
        0x1: Read-Only
        0x2: Write-Only
        0x3: Read/Write
*/
/*
    ===========================================================================
    
    Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
    All rights reserved.
    Confidential and Proprietary - Qualcomm Technologies, Inc.
    
    ===========================================================================
*/

/*----------------------------------------------------------------------------
 * MODULE: SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG
 *--------------------------------------------------------------------------*/

#define SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE                                                 (SAILSS_CLKCTL_SAILSS_CC_BASE      + 0x00010000UL)
#define SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_SIZE                                            0xf0000UL
#define SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_USED                                            0x3c000UL
#define SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_OFFS                                            0x00010000UL

#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_ADDR                                                           (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE      + 0x39020UL)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_OFFS                                                           (SAILSS_CLKCTL_SAILSS_CC_SAILSS_CC_SAILSS_CC_REG_REG_BASE_OFFS + 0x39020UL)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_RMSK                                                               0x3fffU
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_ATTR                                                                        0x3
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_IN                    \
                in_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_ADDR)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_INM(m)            \
                in_dword_masked(HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_ADDR, m)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_OUT(v)            \
                out_dword(HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_ADDR,v)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_OUTM(m,v) \
                out_dword_masked_ns(HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_ADDR,m,v,HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_IN)
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_EUD_SRST_RESET_STATUS_BMSK                                         0x2000U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_EUD_SRST_RESET_STATUS_SHFT                                             13U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_MD_PS_HOLD_RAW_STATUS_BMSK                                         0x1000U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_MD_PS_HOLD_RAW_STATUS_SHFT                                             12U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_SRST_RESET_STATUS_BMSK                                              0x800U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_SRST_RESET_STATUS_SHFT                                                 11U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_QDSS_SW_SRST_RESET_STATUS_BMSK                                      0x400U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_QDSS_SW_SRST_RESET_STATUS_SHFT                                         10U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_SAIL_PS_HOLD_STATUS_BMSK                                            0x200U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_SAIL_PS_HOLD_STATUS_SHFT                                                9U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_MD_PS_HOLD_RESET_STATUS_BMSK                                        0x100U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_MD_PS_HOLD_RESET_STATUS_SHFT                                            8U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_MD_PMIC_FAULT_RESET_STATUS_BMSK                                      0x80U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_MD_PMIC_FAULT_RESET_STATUS_SHFT                                         7U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_PWR_SEQ_WDOG_EXPIRE_RESET_STATUS_BMSK                                0x40U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_PWR_SEQ_WDOG_EXPIRE_RESET_STATUS_SHFT                                   6U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_SAIL_PMIC_ABNORMAL_RESIN_RESET_STATUS_BMSK                           0x20U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_SAIL_PMIC_ABNORMAL_RESIN_RESET_STATUS_SHFT                              5U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_PROC_HALT_CTI_STATUS_BMSK                                            0x10U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_PROC_HALT_CTI_STATUS_SHFT                                               4U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_PROC_HALT_CTI_STATUS_NO_HALT_FVAL                                     0x0U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_PROC_HALT_CTI_STATUS_HALT_FVAL                                        0x1U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_SAIL_TSENSE1_RESET_STATUS_BMSK                                        0x8U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_SAIL_TSENSE1_RESET_STATUS_SHFT                                          3U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_SAIL_TSENSE0_RESET_STATUS_BMSK                                        0x4U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_SAIL_TSENSE0_RESET_STATUS_SHFT                                          2U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_PMIC_RESIN_RESET_STATUS_BMSK                                          0x2U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_PMIC_RESIN_RESET_STATUS_SHFT                                            1U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_R52_WDOG_EXPIRE_RESET_STATUS_BMSK                                     0x1U
#define HWIO_SAILSS_CLKCTL_SAILSS_CC_RESET_STATUS_R52_WDOG_EXPIRE_RESET_STATUS_SHFT                                       0U


#endif /* SAIL_CLKCTL_RSTSTS_HWIO_H */
